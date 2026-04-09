
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

#include "shanks.h"
#include <assert.h>

/* Shanks' algorithm for solving x^2 = a mod p */
/* a is a square residue (jacobi or legendre a|p == +1) */
/* z is a given non-square residue (ie. jacobi or legendre z|p == -1) */

id shanks(id a,id p,id po,id z) 
{
  int s,i,j;
  id b,c,n,x,y;
  id p1,q,k1;

  p1 = [po decrement];
  s = 0;
  while (q = [p1 divideDigit:2]) {
    p1 = q;
    s++;
  }

  c  = [z genpower:p1 modulo:p];
  k1 = [[p1 increment] quotientDigit:2];
  x  = [a genpower:k1 modulo:p];
  n  = [a genpower:p1 modulo:p];
  
  while ([n notOne]) {
    y = n;
    j = s;
    for(i=0;i<j;i++) {
      if ([y notOne]) {
       y = [y squareModulo:p];
      } else { 
       y = c;
       s = i;
      }
    }
    b = y;
    c = [b squareModulo:p];
    x = [b multiply:x modulo:p];
    n = [c multiply:n modulo:p]; 
  }
  
  return x;
}

