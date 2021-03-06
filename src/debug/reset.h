/* automaton
 * (c) 2013 Justin Gottula
 * The source code of this project is distributed under the terms of the
 * simplified BSD license. See the LICENSE file for details.
 */


#ifndef AUTOMATON_DEBUG_RESET_H
#define AUTOMATON_DEBUG_RESET_H


#include "std.h"


extern uint8_t mcusr;


noreturn void reset(void);

void reset_defuse(void);


#endif
