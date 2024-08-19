
/*
 * Computer Algebra Kit (c) 1993,99 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: smonomc.m,v 1.6 2000/10/12 14:40:26 stes Exp $
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

@implementation varsps_monomial
- check
{
  int n;
  id last;

  [super check];
  assert (termOne != nil && terms != nil);
  [termOne check];
  [terms check];

  last = nil;
  n = [terms size];
  while (n--)
    {
      id term = [terms at:n];
      assert ([[term coefficient] isOne] && [term exponent] > 0);
      if (last)
	assert ([last compareSymbols:term] < 0);
      last = term;
    }

  return self;
}

- _setUpScalarOne:aOne
{
  assert ([aOne isOne]);
  termOne = [Term scalar:aOne symbol:nil exponent:0];
  terms = [CACollection new];
  assert ([self check]);
  return self;
}

+ scalarOne:aOne
{
  return [[super new] _setUpScalarOne:aOne];
}

- copy
{
  return [self _terms:[terms copy]];
}

- deepCopy
{
  return [self _terms:[terms deepCopy]];
}

- doclone
{
  terms = nil;
  return self;
}

- clone
{
  return [[super clone] doclone];
}

- _terms
{
  return terms;
}

- _setterms:cltn
{
  terms = cltn;
  assert ([self check]);
  return self;
}

- _terms:cltn
{
  return [[self clone] _setterms:cltn];
}

- empty
{
  return [self _terms:[CACollection new]];
}

- termOne 
{
  return termOne;
}
- (BOOL)isVariableSparse 
{
  return YES;
}
- (BOOL)isVariableDense  
{
  return NO;
}

- (BOOL) isEmpty
{
  return [terms size] == 0;
}

- (BOOL) isOne
{
  return [terms size] == 0;
}

- (int) compare:b
{
  int cmp, n, m;
  id bterms = [b _terms];

  n = [terms size];
  m = [bterms size];

  while (n && m)
    {
      id term = [terms at:--n];
      id bterm = [bterms at:--m];
      if ((cmp = [term compareExponents:bterm]))
	return cmp;
    }

  if (n)
    return +1;
  if (m)
    return -1;
  return 0;
}

- (BOOL) isEqual:b
{
  id bTerms = [b _terms];
  return (terms == bTerms) ? YES : [terms isEqual:bTerms];
}

- (unsigned) hash
{
  return [terms hash];
}

- asSymbol
{
  return ([terms size] == 1) ? [[terms lastElement] asSymbol] : nil;
}

- symbol:aSymbol
{
  id term = [termOne symbol:aSymbol];
  assert ([termOne symbol] == nil && term);	/* never fails since symbol is nil */
  return [[self empty] insertTerm:term];
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
  int n;

  assert ([self check] && [[aTerm coefficient] isOne]);
  if ([aTerm exponent] == 0)
    {
      return self;
    }

  n = [terms size];
  while (n--)
    {
      int cmp;
      id term = [terms at:n];
      cmp = [term compareSymbols:aTerm];
      if (cmp == 0)
	{
	  id product = [term multiply:aTerm];
	  if ([product exponent] < 0)
	    {
	      return nil;
	    }
	  if ([product exponent] == 0)
	    {
	      [terms removeAt:n];
	      assert ([self check]);
	      return [self invalidate];
	    }
	  else
	    {
	      [terms at:n put:product];
	      assert ([self check]);
	      return [self invalidate];
	    }
	}
      else
	{
	  if (cmp < 0)
	    {
	      continue;
	    }
	  else
	    {
	      if ([aTerm exponent] < 0)
		{
		  return nil;
		}
	      else
		{
		  [terms at:n + 1 insert:aTerm];
		  assert ([self check]);
		  return [self invalidate];
		}
	    }
	}
    }

  if ([aTerm exponent] < 0)
    {
      return nil;
    }
  else
    {
      [terms at:0 insert:aTerm];
      assert ([self check]);
      return [self invalidate];
    }
}

@end
 
