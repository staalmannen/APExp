
/*
 * Computer Algebra Kit (c) 1993,00 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: despolc.m,v 1.6 2000/10/12 14:40:25 stes Exp $
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

@implementation vardnsexpdegsps_polynomial
+ scalarZero:aScalar
{
  return [self error:"Can't create variable dense polynomial without cltn of symbols"];
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
  return NO;
}
- (BOOL)isExpanded		
{
  return YES;
}
- (BOOL)isDegreeDense		
{
  return NO;
}
- (BOOL)isDegreeSparse		
{
  return YES;
}

- emptyScalarZero:aZero
{
  id symbols = [self symbols];
  id classCarrier = [aZero class_vardnsexpdegsps_polynomial];
  return [classCarrier scalarZero:aZero symbols:symbols];
}

- emptyVariableDense:aCltn
{
  id scalarZero = [self scalarZero];
  assert (isa == [scalarZero class_vardnsexpdegsps_polynomial]);
  assert ([aCltn size] == [[self symbols] size]);
  return [isa scalarZero:scalarZero symbols:aCltn];
}

- emptyVariableSparse
{
  id classCarrier;
  id scalarZero = [self scalarZero];
  classCarrier = [scalarZero class_varspsexpdegsps_polynomial];
  return [classCarrier scalarZero:scalarZero];
}

- emptyExpanded
{
  return [self empty];
}

- emptyRecursive
{
  id classCarrier;
  id scalarZero = [self scalarZero];
  id symbols = [self symbols];
  classCarrier = [scalarZero class_vardnsrecdegsps_polynomial];
  return [classCarrier scalarZero:scalarZero symbols:symbols];
}

- emptyDegreeSparse
{
  return [self empty];
}

- emptyDegreeDense
{
  id classCarrier;
  id scalarZero = [self scalarZero];
  id symbols = [self symbols];
  classCarrier = [scalarZero class_vardnsexpdegdns_polynomial];
  return [classCarrier scalarZero:scalarZero symbols:symbols];
}

@end
 
