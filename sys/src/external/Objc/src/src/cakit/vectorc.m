
/*
 * Computer Algebra Kit (c) 1993,00 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: vectorc.m,v 1.6 2000/10/12 14:40:26 stes Exp $
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

@implementation vectorc
- (int)numScalars			
{
  [self subclassResponsibility:_cmd];
  return 0;
}
- numScalars:(int)n			
{
  [self subclassResponsibility:_cmd];
  return self;
}
- capacity:(int)n			
{
  [self subclassResponsibility:_cmd];
  return self;
}
- insertScalar:aScalar			
{
  [self subclassResponsibility:_cmd];
  return self;
}
- insertScalar:aScalar at:(int)i	
{
  [self subclassResponsibility:_cmd];
  return self;
}
- removeScalar				
{
  [self subclassResponsibility:_cmd];
  return self;
}
- removeScalarAt:(int)i			
{
  [self subclassResponsibility:_cmd];
  return self;
}
- placeScalar:aScalar at:(int)i		
{
  [self subclassResponsibility:_cmd];
  return self;
}
- replaceScalarAt:(int)i with:aScalar	
{
  [self subclassResponsibility:_cmd];
  return self;
}
- eachScalar				
{
  [self subclassResponsibility:_cmd];
  return self;
}

- (BOOL)sameClass:b
{
  return isa == [b class] && [[self scalarZero] isEqual:[b scalarZero]];
}


- (float) floatValueAt:(int)i
{
  float res;
  id seq = [self eachScalar];
  res = [[seq at:i] floatValue];
  return res;
}

- (int) intValueAt:(int)i
{
  int res;
  id seq = [self eachScalar];
  res = [[seq at:i] intValue];
  return res;
}


- (BOOL) isZero
{
  id seq;
  int i, n = [self numScalars];

  seq = [self eachScalar];
  for (i = 0; i < n; i++)
    if ([[seq at:i] notZero])
      {
	return NO;
      }
  return YES;
}

- negate
{
  id c, seq;
  int i, n = [self numScalars];

  c = [self numScalars:n];
  seq = [self eachScalar];
  for (i = 0; i < n; i++)
    [c placeScalar:[[seq at:i] negate] at:i];

  return c;
}

- double
{
  id c, seq;
  int i, n = [self numScalars];

  c = [self numScalars:n];
  seq = [self eachScalar];
  for (i = 0; i < n; i++)
    [c placeScalar:[[seq at:i] double] at:i];

  return c;
}

- add:b
{
  id c, A, B;
  int i, n = [self numScalars];
  assert (self != b && [b numScalars] == n);
  c = [self numScalars:n];
  A = [self eachScalar];
  B = [b eachScalar];
  for (i = 0; i < n; i++)
    [c placeScalar:[[A at:i] add:[B at:i]] at:i];

  return c;
}

- subtract:b
{
  id c, A, B;
  int i, n = [self numScalars];
  assert (self != b && [b numScalars] == n);
  c = [self numScalars:n];
  A = [self eachScalar];
  B = [b eachScalar];
  for (i = 0; i < n; i++)
    [c placeScalar:[[A at:i] subtract:[B at:i]] at:i];

  return c;
}


- multiplyScalar:t
{
  id c, seq;
  int i, n = [self numScalars];
  c = [self numScalars:n];

  seq = [self eachScalar];
  for (i = 0; i < n; i++)
    [c placeScalar:[[seq at:i] multiply:t] at:i];

  return c;
}

- divideScalar:t
{
  id c, seq;
  int i, n = [self numScalars];
  c = [self numScalars:n];

  seq = [self eachScalar];
  for (i = 0; i < n; i++)
    {
      id q = [[seq at:i] divide:t];
      if (q)
	[c placeScalar:q at:i];
      else
	{
	  return nil;
	}
    }

  return c;
}


- dotSquare
{
  id seq, sum = [[self scalarZero] zero];
  int i, n = [self numScalars];
  seq = [self eachScalar];
  for (i = 0; i < n; i++)
    {
      id t = [[seq at:i] square];
      sum = [sum add:t];	/* add:square: ?? */
    }
  return sum;
}

- dotMultiply:aVector
{
  id A, B, sum = [[self scalarZero] zero];
  int i, n = [self numScalars];
  assert ([aVector numScalars] == n);
  A = [self eachScalar];
  B = [aVector eachScalar];
  for (i = 0; i < n; i++)
    {
      id t = [[A at:i] multiply:[B at:i]];
      sum = [sum add:t];	/* add:multiply: ?? */
    }
  return sum;
}

@end
 
