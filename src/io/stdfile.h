/* automaton
 * (c) 2014 Justin Gottula
 * The source code of this project is distributed under the terms of the
 * simplified BSD license. See the LICENSE file for details.
 */


#ifndef AUTOMATON_IO_STDFILE_H
#define AUTOMATON_IO_STDFILE_H


#include "std.h"


extern FILE *lcd;


void stdfile_open(void);
void stdfile_close(void);


#endif