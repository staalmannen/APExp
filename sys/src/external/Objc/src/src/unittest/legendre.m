
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

#include <assert.h>
#include "legendre.h"

int legendre(id n,id p)
{
  id e;
  id two,four;
  two = [BigInt int:2];
  four = [two square];

  if ([p isEqual:two]) {
    return ([n isOdd])?+1:0;
  }

  n = [n modulo:p];
  if ([n isOne]) return +1;
  if ([n isZero]) return 0;
  if ([[n increment] isEqual:p]) {
    return ([[p modulo:four] isOne])?+1:-1;
  }

  assert([p notEqual:two]);
  e = [[p decrement] divide:two];
  return ([[n genpower:e modulo:p] isOne])?+1:-1; 
}

