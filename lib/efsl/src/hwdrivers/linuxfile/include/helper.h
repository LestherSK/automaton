/*****************************************************************************\
*                     EFSL - Embedded Filesystems Library                     *
*                     -----------------------------------                     *
*                                                                             *
* Filename : helper.c                                                         *
* Release  : 0.3 - devel                                                      *
* Description : These functions may NOT BE USED ANYWHERE ! They are helper    *
*               functions for the Linux based developement. They use the GNU  *
*               C library and headers.                                        *
*                                                                             *
* This program is free software; you can redistribute it and/or               *
* modify it under the terms of the GNU General Public License                 *
* as published by the Free Software Foundation; version 2                     *
* of the License.                                                             *
*                                                                             *
* This program is distributed in the hope that it will be useful,             *
* but WITHOUT ANY WARRANTY; without even the implied warranty of              *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
* GNU General Public License for more details.                                *
*                                                                             *
* As a special exception, if other files instantiate templates or             *
* use macros or inline functions from this file, or you compile this          *
* file and link it with other works to produce a work based on this file,     *
* this file does not by itself cause the resulting work to be covered         *
* by the GNU General Public License. However the source code for this         *
* file must still be made available in accordance with section (3) of         *
* the GNU General Public License.                                             *
*                                                                             *
* This exception does not invalidate any other reasons why a work based       *
* on this file might be covered by the GNU General Public License.            *
*                                                                             *
*                                                    (c)2006 Lennart Yseboodt *
*                                                    (c)2006 Michael De Nil   *
\*****************************************************************************/

#ifndef __HELPER_H__
#define __HELPER_H__

/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "debug.h"
#include "types.h"
#include "config.h"
/*****************************************************************************/

void* Malloc(eint32 size);
void Fopen(FILE **f,eint8* filename);
void MMap(eint8* filename,void**x,eint32* size);
int getFileSize(FILE* file);

#endif
