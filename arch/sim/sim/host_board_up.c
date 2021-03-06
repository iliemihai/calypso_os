/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#ifdef __APPLE__
  #include <sys/semaphore.h>
#else
  #include <semaphore.h>
#endif

#include <pthread.h>
#include <signal.h>
#include <stdarg.h>
#include <stdint.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/uio.h>
#include <termios.h>
#include <unistd.h>

#include "../../../include/chip/simulator.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Error macro that prints to standard error */

#define _err(fmt, ...)            fprintf(stderr, "[ERROR] "fmt, __VA_ARGS__)

/* The timer interval that generates sys tick events */

#define SCHEDULING_TIME_SLICE_MS  (1)

/* Simulated flash file path */

#define CONFIG_SIM_FLASH_FILENAME "config/sim/sim_flash.dat"

/* The block size in bytes */

#define CONFIG_SIM_FLASH_BLOCK_SIZE   (512)

/****************************************************************************
 * Public Data
 ****************************************************************************/

/* The simulated interrupt vector table */

extern void (*g_ram_vectors[NUM_IRQS])(void);

extern uint8_t g_lpuart_fifo[CONFIG_SIM_LPUART_FIFO_SIZE];

/****************************************************************************
 * Private Data
 ****************************************************************************/

/* Simulated interrupts thread */

static pthread_t g_simulated_int;

/* The PID of the host process */

static pid_t g_host_pid;

/* The console settings */

static struct termios current;

/* The simulated flash file descriptor */

static int g_sim_flash_fd = -1;

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/* This function is the entry point for the Calypso OS */

void _start(void);

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: host_signal_handler
 *
 * Description:
 *   Signal handler for the host process that invokes the context switching
 *   mechanism.
 *
 * Input Parameters:
 *   sig    - signal handler number
 *   si     - the signal info
 *   old_ucontext - the old processor state
 *
 ****************************************************************************/

static void host_signal_handler(int sig, siginfo_t *si, void *old_ucontext)
{
  if (sig == SIGALRM) {
    sched_context_switch();
  } else if (sig == SIGUSR2) {

    /* Send the UART simulated event */

    if (g_ram_vectors[UART_0_IRQ] != NULL)
      g_ram_vectors[UART_0_IRQ]();
  }

  /* Unsupported sig */
}

/****************************************************************************
 * Name: host_simulated_intterupts
 *
 * Description:
 *   Simulated interrupts from peripherals and send signals to the OS thread.
 *
 * Input Parameters:
 *   ignored
 *
 ****************************************************************************/

static void host_simulated_intterupts(void *arg)
{
  int ret;
  char c;

  while (1) {
    ret = read(0, &g_lpuart_fifo[0], sizeof(c));
    if (ret < 0) {
      _err("%d read from stdin\n", ret);
    } else {
      kill(g_host_pid, SIGUSR2);
    }
  }
}

/****************************************************************************
 * Name: host_create_interrupt_thread
 *
 * Description:
 *   Creates a new pthread to simulate external events.
 *
 ****************************************************************************/

static void host_create_interrupt_thread(void)
{
  int ret;
  struct sigaction act;

  g_host_pid = getpid();

  act.sa_sigaction = host_signal_handler;
  sigemptyset(&act.sa_mask);
  act.sa_flags = SA_SIGINFO;

  if ((ret = sigaction(SIGUSR2, &act, NULL)) != 0) {
      _err("%d signal handler", ret);
  }

  ret = pthread_create(&g_simulated_int, NULL, host_simulated_intterupts, NULL);
  if (ret < 0) {
    _err("%d start sim interrupts thread\n", ret);
  }
}

/****************************************************************************
 * Name: host_init_termios
 *
 * Description:
 *   Set up the console so that it does not buffer characters.
 *
 ****************************************************************************/

static void host_init_termios(int echo)
{
  tcgetattr(0, &current);
  current.c_lflag &= ~ICANON;
  current.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP
                        | INLCR | IGNCR | ICRNL | IXON);
  if (echo) {
      current.c_lflag |= ECHO;
  } else {
      current.c_lflag &= ~ECHO;
  }

  tcsetattr(0, TCSANOW, &current);
}

/****************************************************************************
 * Name: host_sim_flash_opens
 *
 * Description:
 *   Open the simulated flash file.
 *
 ****************************************************************************/

static void host_sim_flash_open(void)
{
  int ret = open(CONFIG_SIM_FLASH_FILENAME, O_RDWR);
  if (ret < 0)
    return;

  g_sim_flash_fd = ret; 
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: host_console_putc
 *
 * Description:
 *   This function prints out one character to the console. It is invoked from
 *   the lower layer UART to show a character to the console. In a hardware
 *   build this function should be responsible for storing the character in
 *   the UART peripheral register taht will later be transfered on the wire.
 *
 * Input Parameters:
 *   c    - the character that will be printed to the console
 *
 * Assumptions/Limitations:
 *   Anything else that one might need to know to use this function.
 *
 ****************************************************************************/

void host_console_putc(int c)
{
  char buffer[12];
  memset(buffer, 0, sizeof(buffer));

  int ret = snprintf(buffer, sizeof(buffer), "%c", c);
  if (ret > 0) {
    write(1, buffer, ret);
  }
}

/****************************************************************************
 * Name: host_simulated_systick
 *
 * Description:
 *   Simulate a tick event using a host timer. This function sets up the
 *   signal mask for the host process in which we run Caypso OS, it sets
 *   up a timer and it fires it with SCHEDULING_TIME_SLICE_MS interval.
 *   It is called from the board control logic during initialization.
 *
 * Assumptions/Limitations:
 *   Anything else that one might need to know to use this function.
 *
 ****************************************************************************/

void host_simulated_systick(void)
{
  int ret;
  struct itimerval it;

  struct sigaction act;
  sigset_t set;

  /* Enable all the signals */

  __enable_irq();

  act.sa_sigaction = host_signal_handler;
  sigemptyset(&act.sa_mask);
  act.sa_flags = SA_SIGINFO;

  sigemptyset(&set);
  sigaddset(&set, SIGALRM);
  sigaddset(&set, SIGSEGV);
  if ((ret = sigaction(SIGALRM, &act, NULL)) != 0) {
      _err("%d signal handler", ret);
  }

  it.it_interval.tv_sec  = 0;
  it.it_interval.tv_usec = SCHEDULING_TIME_SLICE_MS * 1000;
  it.it_value            = it.it_interval;

  ret = setitimer(ITIMER_REAL, &it, NULL);
  if (ret < 0) {
    _err("%d settimer\n", ret);
    return;
  }

  return;
}

/****************************************************************************
 * Name: __enable_irq
 *
 * Description:
 *   This function enables the SysTick simulated interrupts by changing
 *   the process signal mask.
 *
 ****************************************************************************/

void __enable_irq(void)
{
  sigset_t newset;

  sigfillset(&newset);
  pthread_sigmask(SIG_UNBLOCK, &newset, NULL);
}

/****************************************************************************
 * Name: __disable_irq
 *
 * Description:
 *   This function disablesthe SysTick simulated interrupts by changing
 *   the process signal mask.
 *
 ****************************************************************************/

void __disable_irq(void)
{
  sigset_t newset;

  /* Disable signals */

  sigfillset(&newset);
  pthread_sigmask(SIG_BLOCK, &newset, NULL);
}

/****************************************************************************
 * Name: host_sim_flash_read_mtd
 *
 * Description:
 *   Read data from the simulated flash file and fill the provided buffer.
 *
 * Input Arguments:
 *   buffer - the place where we store the data
 *   sector - the sector number
 *   count  - the number of bytes that we would like to read
 *
 * Returned Value:
 *   The number of bytes read otherwise a negative error code.
 *
 ****************************************************************************/

int host_sim_flash_read_mtd(uint8_t *buffer, uint32_t sector, size_t count)
{
  int ret = 0;
  size_t n_read_bytes = 0;
  off_t n_seek_offset, n_seeked_offset;

  if (g_sim_flash_fd < 0) {
    _err("[SimFlash] no SIM flash file found fd=%d\n", g_sim_flash_fd);
    return -ENOSYS;
  }

  /* Seek to the specified sector */

  n_seek_offset = sector * CONFIG_SIM_FLASH_BLOCK_SIZE; 
  n_seeked_offset = lseek(g_sim_flash_fd, n_seek_offset, SEEK_SET); 
  if (n_seek_offset != n_seeked_offset) {
    _err("[SimFlash] seek to n_seek_offset=%d failed, current:%d\n",
         (int)n_seek_offset,
         (int)n_seeked_offset); 
    return -EINVAL;
  }

  /* Read the data in the buffer */

  do {
    ret = read(g_sim_flash_fd, buffer, count);
    if (ret < 0) {
      return n_read_bytes;
    }

    count  -= ret;
    buffer += ret;
    n_read_bytes += ret;
  } while (count > 0);

  return n_read_bytes;
} 

/****************************************************************************
 * Name: host_sim_flash_write_mtd
 *
 * Description:
 *   Write data from to the simulated flash file from the received buffer.
 *
 * Input Arguments:
 *   buffer - the buffer to write
 *   sector - the sector number
 *   count  - the number of bytes that we would like to write
 *
 * Returned Value:
 *   The number of bytes written otherwise a negative error code.
 *
 ****************************************************************************/

int host_sim_flash_write_mtd(uint8_t *buffer, uint32_t sector, size_t count)
{
  int ret = 0;
  size_t n_written_bytes = 0;
  off_t n_seek_offset, n_seeked_offset;

  if (g_sim_flash_fd < 0) {
    _err("[SimFlash] no SIM flash file found fd=%d\n", g_sim_flash_fd);
    return -ENOSYS;
  }

  /* Seek to the specified sector */

  n_seek_offset = sector * CONFIG_SIM_FLASH_BLOCK_SIZE; 
  n_seeked_offset = lseek(g_sim_flash_fd, n_seek_offset, SEEK_SET); 
  if (n_seek_offset != n_seeked_offset) {
    _err("[SimFlash] seek to n_seek_offset=%d failed, current:%d\n",
         (int)n_seek_offset,
         (int)n_seeked_offset); 
    return -EINVAL;
  }

  /* Read the data in the buffer */

  do {
    ret = write(g_sim_flash_fd, buffer, count);
    if (ret < 0) {
      return n_written_bytes;
    }

    count  -= ret;
    buffer += ret;
    n_written_bytes += ret;
  } while (count > 0);

  return n_written_bytes;
}

/****************************************************************************
 * Name: main
 *
 * Description:
 *   Main entry point for the simulation. This function calls the entry point
 *   for the Calypso OS.
 *
 * Input Arguments:
 *   argc - the number of arguments
 *   argv - the arguments buffer
 *
 ****************************************************************************/

int main(int argc, char **argv)
{
  /* Disable all the signals to prevent new pthreads from executing our signal
   * handler.
   */

  __disable_irq();

  /* Set up the console so that we don't buffer characters and we disable echo
   */

  host_init_termios(0);

  /* Open the simulated flash file */

  host_sim_flash_open();

  /* Create interrupts thread for this simulation */

  host_create_interrupt_thread();

  /* Start the Calypso OS simulation */

  _start();

  return 0;
}
