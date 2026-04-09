
/*
 * Portable Object Compiler (c) 2025.  All Rights Reserved.
 * $Id: mvartest.m,v 1.1 2025/06/16 16:19:51 stes Exp $
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
#include "mvartest.h"
#if OBJC_BLOCKS
#include "Block.h"
#endif
#include <objpak.h>
#include <cakit.h>

@implementation MultivariateExpansionTest

- run
{
   int i,n;
   id power;
   id x,y,polynomial,dpol,symbols,term,one;
   printf("Object Unit Test: Multivariate Expansion test\n");
   x = [Symbol str:"x"];
   y = [Symbol str:"y"];
   one = [BigInt int:1];
   polynomial = [Polynomial scalar:one]; 
   term = [Term scalar:[BigInt int:1] symbol:x exponent:1];
   [polynomial insertTerm:term];
   term = [Term scalar:[BigInt int:1] symbol:y exponent:1];
   [polynomial insertTerm:term];
   [polynomial printLine];
   printf("isDegreeDense: %i\n",[polynomial isDegreeDense]);
   printf("isVariableDense: %i\n",[polynomial isVariableDense]);
   printf("isRecursive: %i\n",[polynomial isRecursive]);
   dpol = [polynomial makeVariableDense];
   [dpol printLine];
   printf("isDegreeDense: %i\n",[dpol isDegreeDense]);
   printf("isVariableDense: %i\n",[dpol isVariableDense]);
   printf("isRecursive: %i\n",[dpol isRecursive]);
   dpol = [dpol power:3];
   [dpol printLine];
   printf("degree: %i\n",[dpol degree]);
   return self;
}

@end

