/* automaton
 * (c) 2014 Justin Gottula
 * The source code of this project is distributed under the terms of the
 * simplified BSD license. See the LICENSE file for details.
 */


#include "std.h"
#include "dev/lcd/backlight.h"
#include "dev/lcd/font.h"
#include "dev/lcd/lcd.h"
#include "mcu/clock.h"


#if 0
static void _main_init(const char *pstr) {
	printf_P(PSTR("main: init %S\n"), pstr);
}


static void _DEBUG_passthru_uart(void) {
	for ( ; ; ) {
		/*char c;
		
		while ((c = fgetc(stdin)) != EOF) {
			fputc(c, stn1110);
		}
		
		while ((c = fgetc(stn1110)) != EOF) {
			fputc(c, stdout);
		}*/
		
		while (uart_avail(UART_PC) != 0) {
			char c;
			
			if (uart_read(UART_PC, &c)) {
				uart_write(UART_STN1110, c);
			}
		}
		
		while (uart_avail(UART_STN1110) != 0) {
			char c;
			
			if (uart_read(UART_STN1110, &c)) {
				uart_write(UART_PC, c);
			}
		}
	}
}


#warning remove me
extern uint8_t mcusr;
#endif


int main(void) {
	mcu_setup_xtal();
	mcu_setup_pll();
	mcu_use_pll();
	
	lcd_bl_init();
	//button_init();
	
	lcd_init();
	lcd_onoff(true);
	
	uint8_t sprite[] = {
		0b00111100,
		0b01000010,
		0b10000001,
		0b10000001,
		0b10000001,
		0b10000001,
		0b01000010,
		0b00111100,
	};
	uint8_t mask[] = {
		0b00111100,
		0b01111110,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b01111110,
		0b00111100,
	};
	
	lcd_bl_rgb(255, 255, 255);
	
	lcd_draw_str("quick: brown, fox. jump!");
	lcd_update(false);
	
	/*for (char c = ' '; c <= '~'; ++c) {
		_delay_ms(50);
		lcd_draw_chr(c);
		lcd_update(false);
	}*/
	
	/*extern uint8_t font_04b_03_glyphs[];
	uint8_t fmask[] = { 0xff, 0xff, 0xff, 0xff, 0xff };
	for (uint8_t i = 0; i < 16; ++i) {
		_delay_ms(50);
		lcd_draw_sprite(1, 1 + (i * 6), 5, font_04b_03_glyphs + (i * 5), fmask);
		lcd_update(false);
	} for (;;);*/
	
	/*for (;;) {
		_delay_ms(50);
		lcd_draw_sprite(rand() % 64, rand() % 128, 8, sprite, mask);
		lcd_update(false);
	}*/
	/*
	_delay_ms(1000);
	lcd_draw_sprite(0, 0, 8, sprite, mask);
	lcd_update(false);
	_delay_ms(1000);
	lcd_draw_sprite(0, 4, 8, sprite, mask);
	lcd_update(false);
	_delay_ms(1000);
	lcd_draw_sprite(1, 16, 8, sprite, mask);
	lcd_update(false);
	_delay_ms(1000);
	lcd_draw_sprite(2, 24, 8, sprite, mask);
	lcd_update(false);
	_delay_ms(1000);
	lcd_draw_sprite(3, 32, 8, sprite, mask);
	lcd_update(false);
	_delay_ms(1000);*/
	
	lcd_bl_rgb(255, 0, 0);
	for (;;) {
		for (uint8_t i = 0; i < 255; ++i) {
			lcd_bl_rgb(255, i + 1, 0);
			_delay_ms(2);
		}
		for (uint8_t i = 0; i < 255; ++i) {
			lcd_bl_rgb(255 - (i + 1), 255, 0);
			_delay_ms(2);
		}
		for (uint8_t i = 0; i < 255; ++i) {
			lcd_bl_rgb(0, 255, i + 1);
			_delay_ms(2);
		}
		for (uint8_t i = 0; i < 255; ++i) {
			lcd_bl_rgb(0, 255 - (i + 1), 255);
			_delay_ms(2);
		}
		for (uint8_t i = 0; i < 255; ++i) {
			lcd_bl_rgb(i + 1, 0, 255);
			_delay_ms(2);
		}
		for (uint8_t i = 0; i < 255; ++i) {
			lcd_bl_rgb(255, 0, 255 - (i + 1));
			_delay_ms(2);
		}
	}
	
	
	/*uint8_t colors[] = {
		0b000, // white
		0b011, // red
		0b001, // yellow
		0b101, // green
		0b100, // cyan
		0b110, // blue
		0b010, // purple
	};
	for (;;) {
		for (uint8_t i = 0; i < sizeof(colors); ++i) {
			_delay_ms(500);
			PORTE.OUT = colors[i];
		}
	}*/
	
	
	
	/*uart_direct_write_pstr(UART_PC, UART_DIV_PC,
		PSTR("\n[[automaton][pc uart]]\n"));
	
	
	timer1_start();
	
	uart_init(UART_PC, UART_DIV_PC, 0, 0);
	stdfile_open();
	
	sei();
	fputs_P(PSTR("main: uart ok\n"), stdout);
	
	
	_main_init(PSTR("lcd"));
	lcd_init();
	
	fputs_P(PSTR("init..."), lcd);
	
	_main_init(PSTR("clock"));
	clock_init();
	
	_main_init(PSTR("button"));
	button_init();
	
	_main_init(PSTR("spi"));
	spi_init();
	
	_main_init(PSTR("sd"));
	sd_init();
	
	fputs_P(PSTR("\rinit stn1110..."), lcd);
	
	_main_init(PSTR("stn1110"));
	stn1110_init();
	
	lcd_clear();
	fputs_P(PSTR("main: init ok\n"), stdout);
	
	
	_DEBUG_passthru_uart();
	
	
	ui_loop();*/
}
