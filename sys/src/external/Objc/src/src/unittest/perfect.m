
/*
 * Portable Object Compiler (c) 2025.  All Rights Reserved.
 * $Id: perfect.m,v 1.2 2025/10/19 19:14:59 stes Exp $
 */

/*
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

#include "config.h"
#include <assert.h>
#include "perfect.h"
#if OBJC_BLOCKS
#include "Block.h"
#endif
#include <objpak.h>
#include <cakit.h>

#define NUMPRIMES 4

@implementation PerfectNumberTest

/*
 * Smalltalk code small perfect numbers
 * 
 * |d c|
 * d := Integer primesUpTo:7.
 * c := OrderedCollection new.
 * d do:[ :p | c add:((2 raisedToInteger:(p-1)) * ((2 raisedToInteger:p) - 1)). ].
 */

static int smallprimes[] = {2,3,5,7};

id perfect(void) 
{
  id c;
  int i;
  id two,one;

  c = [OrdCltn new];
  one = [BigInt int:1];
  two = [BigInt int:2];

  for(i=0;i<NUMPRIMES;i++) {
     int p = smallprimes[i];
     [c add:[[two power:(p-1)] multiply:[[two power:p] subtract:one]]];
  } 

  return c;
}

- run
{
  id m;
  m  = perfect();
  printf("Object Unit Test: Perfect Number test\n");
  [m printLine];
}

@end

