
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

#ifndef GALOISFIELD_H

#include "quofield.h"

id gfu16(id zero,int dim,unsigned *p);

@interface GaloisField : QuotientField
{
  id scalarzero;
  id frobtab; /* precomputed frobenius images */
  int characteristic;
  int degree;
  id cardinality;
}

+ characteristic:(int)p degree:(int)n;
- characteristic:(int)p degree:(int)n;
- (int)characteristic;
- (int)degree;

- cardinality;
- calcfrobtab;
- findnonsquare;

- asBigInt;
- embed:aBigInt;

- frobenius;
- norm;
- trace;

- (BOOL)isSquare;
- squareRoot;

@end

#define GALOISFIELD_H
#endif

