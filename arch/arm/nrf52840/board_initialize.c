#include <board.h>
#include <uart.h>
#include <gpio.h>

unsigned int LED = 13;
unsigned int BUTTON_1 = 11;

/*
 * board_init - initialize the board resources
 *
 * Initialize the board specific device drivers and prepare the board.
 */
void board_init(void)
{
  /* Driver initialization logic */

  uart_init();
  gpio_init();

  gpio_configure(LED, 0, GPIO_DIRECTION_OUT);
  gpio_configure(BUTTON_1, 0, GPIO_DIRECTION_IN);
}