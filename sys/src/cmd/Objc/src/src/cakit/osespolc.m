
/*
 * Computer Algebra Kit (c) 1993,98 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: osespolc.m,v 1.6 2000/10/12 14:40:26 stes Exp $
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

@implementation obj_varspsexpdegsps_polynomial
- check
{
  int n;
  id last;

  [super check];
  [scalarZero check];
  [termZero check];
  [monomialZero check];
  [monomials check];

  last = nil;
  n = [monomials size];
  while (n--)
    {
      id monomial = [monomials at:n];
      assert ([monomial notZero]);
      if (last)
	assert ([last compareTerms:monomial] > 0);
      last = monomial;
    }

  return self;
}

+ new
{
  return [self notImplemented:_cmd];
}

- _setUpScalarZero:aScalar
{
  assert ([aScalar isZero]);
  assert ([aScalar class_varspsexpdegsps_polynomial] == [self class]);

  termZero = [Term scalar:aScalar symbol:nil exponent:0];
  monomialZero = [Monomial scalar:aScalar];

  scalarZero = aScalar;
  monomials = [CACollection new];

  assert ([self check]);
  return self;
}

+ scalarZero:aScalar
{
  return [[super new] _setUpScalarZero:aScalar];
}

- copy
{
  int i, n;
  id new;

  new = [monomials empty];
  for (n = [monomials size], i = 0; i < n; i++)
    {
      id monomial = [monomials at:i];
      [new add:[monomial copy]];
    }

  return [self _monomials:new];
}

- deepCopy
{
  int i, n;
  id new;

  /* don't use [monomials deepCopy] -> sends copy */
  new = [monomials empty];
  for (n = [monomials size], i = 0; i < n; i++)
    {
      id monomial = [monomials at:i];
      [new add:[monomial deepCopy]];
    }

  return [self _monomials:new];
}

- _monomials 
{
  return monomials;
}				/* super temporal of course */

- scalarZero 
{
  return scalarZero;
}
- termZero 
{
  return termZero;
}
- monomialZero 
{
  return monomialZero;
}

- set_monomials:cltn
{
  monomials = cltn;
  assert ([self check]);
  return self;
}

- _monomials:cltn
{
  return [[self clone] set_monomials:cltn];
}

- empty
{
  return [self _monomials:[CACollection new]];
}

- emptyScalarZero:aZero
{
  id classCarrier = [aZero class_varspsexpdegsps_polynomial];
  return [classCarrier scalarZero:aZero];
}

- emptyVariableDense:aCltn
{
  id classCarrier = [scalarZero class_vardnsexpdegsps_polynomial];
  return [classCarrier scalarZero:scalarZero symbols:aCltn];
}

- emptyVariableSparse
{
  return [self empty];
}

- emptyExpanded
{
  return [self empty];
}

- emptyRecursive
{
  id classCarrier = [scalarZero class_varspsrecdegsps_polynomial];
  return [classCarrier scalarZero:scalarZero];
}

- emptyDegreeSparse
{
  return [self empty];
}

- emptyDegreeDense
{
  id classCarrier = [scalarZero class_varspsexpdegdns_polynomial];
  return [classCarrier scalarZero:scalarZero];
}

- (BOOL) isEmpty
{
  return [monomials size] == 0;
}

- (BOOL) isZero
{
  return [monomials size] == 0;
}

- (BOOL) isOne
{
  return [monomials size] == 1 && [[monomials lastElement] isOne];
}

- (BOOL) isMinusOne
{
  return [monomials size] == 1 && [[monomials lastElement] isMinusOne];
}

- (BOOL) sameClass:b
{
  return [super sameClass:b] && [scalarZero isEqual:[b scalarZero]];
}

- (BOOL) isEqual:b
{
  assert ([self sameClass:b]);
  return [monomials isEqual:[b _monomials]];
}

- asScalar
{
  return ([monomials size] == 1) ? [[monomials lastElement] asScalar] : nil;
}

- asSymbol
{
  return ([monomials size] == 1) ? [[monomials lastElement] asSymbol] : nil;
}

- (int) numMonomials
{
  return [monomials size];
}

- eachMonomial
{
  return [monomials eachElementReversed];
}

- removeMonomial
{
  id lt;
  assert ([self check] == self);
  lt = [monomials removeLast];
  [self invalidate];
  return lt;
}

- insertMonomial:aMonomial
{
  assert ([self check] == self);

  if ([aMonomial isZero])
    {
      return self;
    }
  else
    {
      int n = [monomials size];
      while (n--)
	{
	  int cmp;
	  id monomial = [monomials at:n];
	  cmp = [monomial compareTerms:aMonomial];
	  if (cmp == 0)
	    {
	      id sum = [monomial add:aMonomial];
	      if ([sum isZero])
		{
		  [monomials removeAt:n];
		  assert ([self check]);
		  return [self invalidate];
		}
	      else
		{
		  [monomials at:n put:sum];
		  assert ([self check]);
		  return [self invalidate];
		}
	    }
	  else
	    {
	      if (cmp > 0)
		{
		  continue;
		}
	      else
		{
		  [monomials at:n + 1 insert:aMonomial];
		  assert ([self check]);
		  return [self invalidate];
		}
	    }
	}
      [monomials at:0 insert:aMonomial];
      assert ([self check]);
      return [self invalidate];
    }
}

@end
 
