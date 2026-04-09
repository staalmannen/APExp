
/*
 * Copyright (c) 2000 David Stes.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Library General Public License as published 
 * by the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef BIGRANDOM_H

#include <cakit.h>

void biginthex(id c);
void seedrandomgen(char *randomdevice);
id bigintrandom(int numDigits);
id bigint2string(id value);
id string2bigint(id aString);
id randompolynomial(id p);
id bigintu16(int dim,unsigned *p);

#define BIGRANDOM_H
#endif

