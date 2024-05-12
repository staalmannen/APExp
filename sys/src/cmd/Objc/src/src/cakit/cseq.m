
/*
 * Computer Algebra Kit (c) 1993,00 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: cseq.m,v 1.7 2014/03/04 15:24:41 stes Exp $
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

@implementation CASequence

- _setUpCarrier:aSequence
{
  carrier = aSequence;
  return self;
}

+ over:aSequence
{
  return [[[super new] _setUpCarrier:aSequence] toFirst];
}


- next
{
  id m;
  if ((m = [carrier next]))
    {
      return m;
    }
  else
    {
      assert ([carrier isEmpty] || [carrier previous] != nil);
      assert ([carrier isEmpty] || m == [carrier next]);
      return m;
    }
}

- previous
{
  id m;
  if ((m = [carrier previous]))
    {
      return m;
    }
  else
    {
      assert ([carrier isEmpty] || [carrier next] != nil);
      assert ([carrier isEmpty] || m == [carrier previous]);
      return m;
    }
}


- (unsigned) size
{
  return [carrier size];
}

- (BOOL) isEmpty
{
  return [carrier isEmpty];
}

- (BOOL) isKindOfSequence
{
  return YES;
}


- toFirst
{
  [carrier toFirst];
  return self;
}

- toLast
{
  [carrier toLast];
  return self;
}

- toElementAt:(int)i
{
  [carrier toElementAt:i];
  return self;
}


- lastElement
{
  id res = [[self toLast] previous];
  assert ([self isEmpty] || [res check] != nil);
  return res;
}

- firstElement
{
  id res = [[self toFirst] next];
  assert ([self isEmpty] || [res check] != nil);
  return res;
}

- at:(unsigned)i
{
  id res = [[self toElementAt:i] next];
#ifndef NDEBUG
  if (0 <= i && i < [self size])
    {
      assert ([res check]);
    }
  else
    {
      assert (res == nil);
    }
#endif
  return res;
}

- commonDenominator
{
  id d, m = [self firstElement];
  if (m)
    {
      d = [[m denominator] copy];
      while ((m = [self next]))
	d = [d lcm:[m denominator]];
      return d;
    }
  else
    {
      return nil;
    }
}

- content
{
  id d, m = [self firstElement];
  if (m)
    {
      d = [m copy];
      while ([d notZero] && [d notOne] && (m = [self next]))
	{
	  d = [d gcd:m];
	}
      return d;
    }
  else
    {
      return nil;
    }
}


- printOn:(IOD)aFile
{
  id aMember;

  fprintf (aFile, "{");
  if ((aMember = [self next]))
    [aMember printOn:aFile];
  while ((aMember = [self next]))
    {
      fprintf (aFile, ",");
      [aMember printOn:aFile];
    }
  fprintf (aFile, "}");

  return self;
}

@end
 
