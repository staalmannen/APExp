
/*
 * Computer Algebra Kit (c) 1998,99 by David Stes.  All Rights Reserved.
 * $Id: drdpolc.m,v 1.6 2000/10/12 14:40:25 stes Exp $
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

#include "cakit.h"

@implementation vardnsrecdegdns_polynomial
+ scalarZero:aScalar
{
  return [self error:"Can't create variable dense polynomial without cltn of symbols"];
}

+ scalarZero:aScalar coefficientZero:aCoef symbols:aCltn
{
  return [self subclassResponsibility:_cmd];
}

+ scalarZero:aScalar symbols:aCltn
{
  id aCoef, aClass;
  int n = [aCltn size];

  assert ([aScalar isZero] && n >= 1);

  if (n == 1)
    {
      aCoef = aScalar;
    }
  else
    {
      id cltn = [aCltn copy];
      [cltn removeLast];
      aCoef = [self scalarZero:aScalar symbols:cltn];
      aCoef = [Polynomial over:aCoef];
    }

  aClass = [aCoef class_vardnsrecdegdns_polynomial];
  return [aClass scalarZero:aScalar coefficientZero:aCoef symbols:aCltn];
}

- scalarZero
{
  return [self subclassResponsibility:_cmd];
}

- symbols
{
  return [self subclassResponsibility:_cmd];
}

- (BOOL) sameClass:b
{
  id aScalar = [self scalarZero];
  id aSymbols = [self symbols];
  id bScalar = [b scalarZero];
  id bSymbols = [b symbols];

  if ([super sameClass:b] == NO)
    return NO;
  if (aScalar != bScalar && [aScalar notEqual:bScalar])
    return NO;
  if (aSymbols != bSymbols && [aSymbols notEqual:bSymbols])
    return NO;

  return YES;
}

- (BOOL)isVariableDense		
{
  return YES;
}
- (BOOL)isVariableSparse	
{
  return NO;
}
- (BOOL)isRecursive		
{
  return YES;
}
- (BOOL)isExpanded		
{
  return NO;
}
- (BOOL)isDegreeDense		
{
  return YES;
}
- (BOOL)isDegreeSparse		
{
  return NO;
}

- emptyScalarZero:aZero
{
  id classCarrier;
  id symbols = [self symbols];

  classCarrier = [aZero class_vardnsrecdegdns_polynomial];
  return [classCarrier scalarZero:aZero symbols:symbols];
}

- emptyVariableDense:aCltn
{
  id classCarrier;
  id scalarZero = [self scalarZero];

  classCarrier = [scalarZero class_vardnsrecdegdns_polynomial];
  assert (classCarrier == isa || classCarrier != isa);
  assert ([aCltn size] == [[self symbols] size]);
  return [classCarrier scalarZero:scalarZero symbols:aCltn];
}

- emptyVariableSparse
{
  id classCarrier;
  id scalarZero = [self scalarZero];

  classCarrier = [scalarZero class_varspsrecdegdns_polynomial];
  return [classCarrier scalarZero:scalarZero];
}

- emptyExpanded
{
  id classCarrier;
  id scalarZero = [self scalarZero];
  id symbols = [self symbols];

  classCarrier = [scalarZero class_vardnsexpdegdns_polynomial];
  return [classCarrier scalarZero:scalarZero symbols:symbols];
}

- emptyRecursive
{
  return [self empty];
}

- emptyDegreeSparse
{
  id classCarrier;
  id scalarZero = [self scalarZero];
  id symbols = [self symbols];

  classCarrier = [scalarZero class_vardnsrecdegsps_polynomial];
  return [classCarrier scalarZero:scalarZero symbols:symbols];
}

- emptyDegreeDense
{
  return [self empty];
}

@end
 
