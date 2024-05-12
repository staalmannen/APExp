
/*
 * Computer Algebra Kit (c) 1993,98 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: osrspolc.m,v 1.6 2000/10/12 14:40:26 stes Exp $
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

@implementation obj_varspsrecdegsps_polynomial
- check
{
  int n;
  id last;

  [super check];
  [scalarZero check];
  [termZero check];
  [monomialZero check];
  assert ([scalarZero isEqual:[termZero coefficient]]);
  assert ([scalarZero isEqual:[monomialZero scalar]]);
  assert ([monomialZero isVariableSparse]);

  last = nil;
  n = [terms size];
  while (n--)
    {
      id term = [terms at:n];
      assert ([term notZero]);
      if ([term isCoefficient])
	{
	  assert ([[term coefficient] sameClass:scalarZero]);
	}
      if (last)
	assert ([term compareExponents:last] < 0);
      [term check];
      last = term;
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
  assert ([aScalar class_varspsrecdegsps_polynomial] == [self class]);

  termZero = [Term scalar:aScalar symbol:nil exponent:0];
  monomialZero = [Monomial scalar:aScalar];
  scalarZero = aScalar;
  terms = [CACollection new];

  assert ([self check]);
  return self;
}

+ scalarZero:aScalar
{
  return [[super new] _setUpScalarZero:aScalar];
}

- setterms:t
{
  terms = t;
  return self;
}

- copy
{
  int i, n;
  id new;

  new = [terms empty];
  for (n = [terms size], i = 0; i < n; i++)
    {
      id term = [terms at:i];
      [new add:[term copy]];
    }

  return [[self clone] setterms:new];
}

- deepCopy
{
  int i, n;
  id new;

  /* don't use [terms deepCopy] -> sends copy */
  new = [terms empty];
  for (n = [terms size], i = 0; i < n; i++)
    {
      id term = [terms at:i];
      [new add:[term deepCopy]];
    }

  return [[self clone] setterms:new];
}

- _terms 
{
  return terms;
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

- clone
{
  return [[super clone] setterms:nil];
}

- _terms:cltn
{
  return [[self clone] setterms:cltn];
}

- empty
{
  return [self _terms:[CACollection new]];
}

- scalarZero:aScalar
{
  return [self notImplemented:_cmd];
}

- scalarZero:aScalar symbols:aCltn
{
  return [self notImplemented:_cmd];
}

- emptyScalarZero:aZero
{
  id classCarrier = [aZero class_varspsrecdegsps_polynomial];
  return [classCarrier scalarZero:aZero];
}

- emptyVariableDense:aCltn
{
  id classCarrier = [scalarZero class_vardnsrecdegsps_polynomial];
  return [classCarrier scalarZero:scalarZero symbols:aCltn];
}

- emptyVariableSparse
{
  return [self empty];
}

- emptyExpanded
{
  id classCarrier = [scalarZero class_varspsexpdegsps_polynomial];
  return [classCarrier scalarZero:scalarZero];
}

- emptyRecursive
{
  return [self empty];
}

- emptyDegreeSparse
{
  return [self empty];
}

- emptyDegreeDense
{
  id classCarrier = [scalarZero class_varspsrecdegdns_polynomial];
  return [classCarrier scalarZero:scalarZero];
}

- (BOOL) isEmpty
{
  return [terms size] == 0;
}

- (BOOL) isZero
{
  return [terms size] == 0;
}

- (BOOL) isOne
{
  return [terms size] == 1 && [[terms lastElement] isOne];
}

- (BOOL) isMinusOne
{
  return [terms size] == 1 && [[terms lastElement] isMinusOne];
}

- (BOOL) sameClass:b
{
  return [super sameClass:b] && [scalarZero isEqual:[b scalarZero]];
}

- (BOOL) isEqual:b
{
  assert ([self sameClass:b]);
  return [terms isEqual:[b _terms]];
}

- asScalar
{
  return ([terms size] == 1) ? [[terms lastElement] asScalar] : nil;
}

- asSymbol
{
  return ([terms size] == 1) ? [[terms lastElement] asSymbol] : nil;
}

- (int) numTerms
{
  return [terms size];
}

- eachTerm
{
  return [terms eachElementReversed];
}

- removeTerm
{
  id lt;
  assert ([self check] == self);
  lt = [terms removeLast];
  [self invalidate];
  return lt;
}

- insertTerm:aTerm
{
  id c;
  assert ([self check] && [aTerm check]);

  if ([aTerm isZero])
    {
      return self;
    }
  if ([aTerm symbol] || [[aTerm coefficient] sameClass:scalarZero])
    {
      int n = [terms size];
      while (n--)
	{
	  int cmp;
	  id term = [terms at:n];
	  cmp = [term compareExponents:aTerm];
	  if (cmp == 0)
	    {
	      id sum = [term add:aTerm];
	      if ([sum isZero])
		{
		  [terms removeAt:n];
		  assert ([self check]);
		  return [self invalidate];
		}
	      else
		{
		  [terms at:n put:sum];
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
		  [terms at:n + 1 insert:aTerm];
		  assert ([self check]);
		  return [self invalidate];
		}
	    }
	}
      [terms at:0 insert:aTerm];
      assert ([self check]);
      return [self invalidate];
    }
  else
    {
      /* "insert" of a lifted term */
      assert ([aTerm isCoefficient] && [[aTerm coefficient] isVariableSparse]);
      return [self add:[aTerm coefficient]];
    }
}

@end
 
