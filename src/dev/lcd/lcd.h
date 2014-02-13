/* automaton
 * (c) 2014 Justin Gottula
 * The source code of this project is distributed under the terms of the
 * simplified BSD license. See the LICENSE file for details.
 */


#ifndef AUTOMATON_DEV_LCD_LCD_H
#define AUTOMATON_DEV_LCD_LCD_H


#include "std.h"


void lcd_init(void);

void lcd_onoff(bool on);
void lcd_contrast(uint8_t value);


#endif
