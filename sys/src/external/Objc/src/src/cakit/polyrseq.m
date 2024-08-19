
/*
 * Computer Algebra Kit (c) 1993,2000,14 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: polyrseq.m,v 1.8 2014/03/04 14:39:43 stes Exp $
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

@implementation recpolscalar_sequence
- _setUpContent:aPolynomial
{
  assert ([aPolynomial isRecursive]);
  content = aPolynomial;
  eachTerm = [aPolynomial eachTerm];
  eachScalar = nil;
  return self;
}

+ content:aPolynomial
{
  return [[super new] _setUpContent:aPolynomial];
}

- toFirst
{
  if (eachScalar)
    eachScalar = nil;
  [eachTerm toFirst];
  return self;
}

- toLast
{
  if (eachScalar)
    eachScalar = nil;
  [eachTerm toLast];
  return self;
}

- (BOOL) isEmpty
{
  return [eachTerm isEmpty];
}

- (unsigned) size
{
  [self notImplemented:_cmd];
  return 0;
}

- toElementAt:(int)i
{
  [self notImplemented:_cmd];
  return self;
}

- next
{
  id next;

  if (eachScalar)
    {
      if ((next = [eachScalar next]))
	return next;
    }

  if ((next = [eachTerm next]))
    {
      id c = [next coefficient];
      if ([c sameClass:[content scalarZero]])
	{
	  return c;
	}
      else
	{
	  eachScalar = [[c eachScalar] toFirst];
	  return [self next];
	}
    }
  else
    {
      return nil;
    }
}

- previous
{
  id prevMember;

  if (eachScalar)
    {
      if ((prevMember = [eachScalar previous]))
	return prevMember;
    }

  if ((prevMember = [eachTerm previous]))
    {
      id c = [prevMember coefficient];
      if ([c sameClass:[content scalarZero]])
	{
	  return c;
	}
      else
	{
	  eachScalar = [[c eachScalar] toLast];
	  return [self previous];
	}
    }
  else
    {
      return nil;
    }
}

@end
 
