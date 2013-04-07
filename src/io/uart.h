/* automaton
 * (c) 2013 Justin Gottula
 * The source code of this project is distributed under the terms of the
 * simplified BSD license. See the LICENSE file for details.
 */


#ifndef AUTOMATON_IO_UART_H
#define AUTOMATON_IO_UART_H


#include "std.h"


#define UART_LF_TO_CRLF 1


enum uart_num {
	UART_DEBUG   = 0,
	UART_STN1110 = 1,
};

/* bit 12 is the double-speed bit */
enum uart_divisor {
	UART_DIV_2400   = 520,
	UART_DIV_4800   = 259,
	UART_DIV_9600   = 129,
	UART_DIV_14400  = 86,
	UART_DIV_19200  = 64,
	UART_DIV_28800  = 42,
	UART_DIV_38400  = 32,
	UART_DIV_57600  = 21,
	UART_DIV_76800  = 15,
	UART_DIV_115200 = 10,
	UART_DIV_250K   = 4,
	UART_DIV_1_25M  = 0,
	
	UART_DIV_230400 = 21 | _BV(12),
	UART_DIV_500K   = 4  | _BV(12),
	UART_DIV_2_50M  = 0  | _BV(12),
};
_Static_assert(F_CPU == 20000000UL, "UART baud rate divisors are wrong");


void uart_init(uint8_t dev, uint16_t divisor, uint16_t timeout_tx_ms,
	uint16_t timeout_rx_ms);
void uart_stop(uint8_t dev);

bool uart_flush(uint8_t dev, uint16_t timeout_ms);

size_t uart_write_chr(uint8_t dev, char chr);
size_t uart_write_str(uint8_t dev, const char *str);
size_t uart_write_pstr_(uint8_t dev, const __flash char *str);

size_t uart_read_chr(uint8_t dev, char *chr);
size_t uart_read_str(uint8_t dev, char *str, size_t max_len);


#define uart_write_pstr(_dev, _str) \
	uart_write_pstr_(_dev, PSTR(_str))


#endif