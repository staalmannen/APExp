
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

#include "quofield.h"
#include "legendre.h"
#include "shanks.h"
#include "bezout.h"

#include <ocstring.h>

@implementation QuotientField

- (BOOL)inField
{
  return YES;
}

- (BOOL)inMonoid
{
  return YES;
}

- (BOOL)inAdditiveMonoid
{
  return YES;
}

- value:v modulus:p
{
  value = v;modulus = p;return self;
}

+ value:v modulus:p
{
  return [[super new] value:v modulus:p];
}

- nonsquare
{
  return nonsquare;
}

- value
{
  return value;
}

- value:v
{
  value = v;return self;
}

- intValue:(int)x
{
  id v = [value intValue:x];
  return [[super copy] value:[v modulo:modulus]];
}

- one
{
  return [[super copy] value:[value one]];
}

- zero
{
  return [[super copy] value:[value zero]];
}

- (BOOL)isOne
{
  return [value isOne];
}

- (BOOL)isMinusOne
{
  return [[self negate] isOne];
}

- (BOOL)isZero
{
  return [value isZero];
}

- negate
{
  id v = [[value negate] modulo:modulus];
  return [[super copy] value:v];
}

- increment
{
  id v = [[value increment] modulo:modulus];
  return [[super copy] value:v];
}
  
- decrement
{
  id v = [[value decrement] modulo:modulus];
  return [[super copy] value:v];
}

- double
{
  id v = [[value double] modulo:modulus];
  return [[super copy] value:v];
}

- quadruple
{
  return [[self double] double];
}

- (unsigned)hash
{
  return [value hash];
}

- (BOOL)isEqual:x
{
  return [value isEqual:[x value]];
}

- (BOOL)isOpposite:x
{
  return [[self add:x] isZero];
}

- add:x
{
  if ([self isEqual:x]) {
    return [self double];
  } else {
    id v = [[value add:[x value]] modulo:modulus];
    return [[super copy] value:v];
  }
}

- subtract:x
{
  if ([self isEqual:x]) {
    return [self zero];
  } else {
    id v = [[value subtract:[x value]] modulo:modulus];
    return [[super copy] value:v];
  }
}
 
- square
{
  id v = [value squareModulo:modulus];
  return [[super copy] value:v];
}

- multiply:x
{
  if ([self isEqual:x]) {
    return [self square];
  } else {
    id v = [value multiply:[x value] modulo:modulus];
    return [[super copy] value:v];
  }
}

- multiplyIntValue:(int)x
{
  id v = [[value multiplyIntValue:x] modulo:modulus];
  return [[super copy] value:v];
}

- inverse
{
   if ([self isZero]) [self error:"division by zero"];
   return [[super copy] value:bezout(value,modulus)];
}

- divide:x
{
   if ([x isZero]) [self error:"division by zero"];

   if ([self isZero]) return self;

   if ([self isEqual:x]) {
     return [self one];
   } else {
     return [self multiply:[x inverse]];
   }
}

- printOn:(IOD)d
{
  [value printOn:d];
  return self;
}

- printmodulusOn:(IOD)d
{
  [modulus printOn:d];
  return self;
}


@end

