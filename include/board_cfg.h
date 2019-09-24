#ifndef __BOARD_CFG_H
#define __BOARD_CFG_H
#define CONFIG_CONSOLE_APP y
#define CONFIG_POWERON_MESSAGE "\r\nWelcome to CatOS v0.0.1\r\n"
#define CONFIG_CONSOLE_PROMPT_STR "root:#/>"
#define CONFIG_CONSOLE_ECHO_ON y
#define CONFIG_CONSOLE_DATE_ON y
#define CONFIG_CONSOLE_UART_PATH "/dev/ttyUSB0"
#define CONFIG_RTC_PATH "/dev/rtc0"
#define CONFIG_SPI_0_MISO_PIN (0)
#define CONFIG_SPI_0_MISO_PORT (0)
#define CONFIG_SPI_0_MOSI_PIN (1)
#define CONFIG_SPI_0_MOSI_PORT (0)
#define CONFIG_SPI_0_SCK_PIN (2)
#define CONFIG_SPI_0_SCK_PORT (0)
#define CONFIG_SPI_0_CS_PIN (3)
#define CONFIG_SPI_0_CS_PORT (0)
#define CONFIG_SPI_BUFFER_LEN (12)
#endif /* __BOARD_CFG_H */
