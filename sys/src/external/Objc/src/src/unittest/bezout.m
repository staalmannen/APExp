
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
#include "bezout.h"

id bezout(id a,id b)
{
   id u,v,w,r,q;
   if ([a isZero]) [a error:"division by zero"];
  
   u = [a one];v = [a zero];
   while ([b notZero]) {
     r = [a remainder:b quotient:&q];
     a = b;b = r;
     w = [u subtract:[q multiply:v]];
     u = v;v = w;
   }
   
   return [u divide:a];
}

