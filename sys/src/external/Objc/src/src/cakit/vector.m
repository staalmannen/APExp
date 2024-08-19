
/*
 * Computer Algebra Kit (c) 1993,00 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: vector.m,v 1.8 2014/03/04 09:38:34 stes Exp $
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

@implementation Vector
- check
{
  assert (carrier && scalarZero);
  [carrier check];
  [scalarZero check];
  assert ([scalarZero isZero]);
  assert ([[carrier scalarZero] isEqual:scalarZero]);
  return [super check];
}


+ collection:aCltn
{
  if ([aCltn isEmpty])
    {
      return [self error:"-collection: cltn must not be empty"];
    }
  else
    {
      id res;
      int n = [aCltn size];
      res = [self scalarZero:[[aCltn lastElement] zero] numScalars:n];
      while (n--)
	[res insertScalar:[aCltn at:n]];
      return res;
    }
}

- scalarZero:aScalarZero numScalars:(int)numScalars
{
  return [self notImplemented:_cmd];
}

- _setUpScalarZero:aScalarZero numScalars:(int)numScalars
{
  id classCarrier;
  classCarrier = [aScalarZero class_vector];
  carrier = [classCarrier scalarZero:aScalarZero numScalars:numScalars];

  assert ([self check]);
  return self;
}

+ scalarZero:aScalarZero numScalars:(int)numScalars
{
  return [[super new] _setUpScalarZero:aScalarZero numScalars:numScalars];
}

- copycarrier
{
  carrier = [carrier copy];
  return self;
}

- copy
{
  return [[super copy] copycarrier];
}

- deepcopycarrier
{
  carrier = [carrier deepCopy];
  scalarZero = [scalarZero deepCopy];
  return self;
}

- deepCopy
{
  return [[super deepCopy] deepcopycarrier];
}

- numScalars:(int)numScalars
{
  return [self over:[carrier numScalars:numScalars]];
}

- capacity:(int)aCapacity
{
  return [self over:[carrier capacity:aCapacity]];
}

- collection:aCltn
{
  id c;
  int n = [aCltn size];

  /* the order of members in a vector/collection is opposite */

  c = [self capacity:n];
  while (n--)
    [c insertScalar:[aCltn at:n]];

  return c;
}

- setcarrier:c
{
  carrier = c;
  return self;
}

- clone
{
  return [[super clone] setcarrier:nil];
}

- over:aCarrier
{
  return [[super clone] setcarrier:aCarrier];
}

- (BOOL)sameClass:b
{
  return isa == [b class] && [scalarZero isEqual:[b scalarZero]];
}

- (BOOL)inAdditiveSemiGroup		
{
  return YES;
}
- (BOOL)inAdditiveMonoid		
{
  return NO;
}
- (BOOL)inAdditiveGroup			
{
  return NO;
}

- (BOOL)inSemiGroup			
{
  return YES;
}
- (BOOL)inMonoid			
{
  return NO;
}
- (BOOL)inGroup				
{
  return NO;
}

- (BOOL)inEuclideanDomain		
{
  return NO;
}
- (BOOL)inIntegralDomain		
{
  return NO;
}
- (BOOL)inField				
{
  return NO;
}

- (BOOL)inOrderedSet			
{
  return NO;
}
- (int)characteristic			
{
  return [scalarZero characteristic];
}


- scalarZero
{
  return scalarZero;
}

- (int) numScalars
{
  return [carrier numScalars];
}

- carrier
{
  return carrier;
}

- (unsigned) hash
{
  return [carrier hash];
}

- (BOOL) isEqual:b
{
  return (self == b) ? YES : [carrier isEqual:[b carrier]];
}

- (BOOL) notEqual:b
{
  return (self == b) ? NO : [carrier notEqual:[b carrier]];
}


- insertScalar:aScalar
{
  if (aScalar)
    {
      [carrier insertScalar:aScalar];
      return [self invalidate];
    }
  else
    {
      return nil;
    }
}

- insertScalar:aScalar at:(int)i
{
  if (aScalar)
    {
      [carrier insertScalar:aScalar at:i];
      return [self invalidate];
    }
  else
    {
      return self;
    }
}


- removeScalar
{
  id s = [carrier removeScalar];
  [self invalidate];
  return s;
}

- removeScalarAt:(int)i
{
  id s = [carrier removeScalarAt:i];
  [self invalidate];
  return s;
}


- placeScalar:aScalar at:(int)i
{
  [carrier placeScalar:aScalar at:i];
  return [self invalidate];
}

- replaceScalarAt:(int)i with:aScalar
{
  id s = [carrier replaceScalarAt:i with:aScalar];
  [self invalidate];
  return s;
}

- asCollection
{
  id c, seq, scalar;
  c = [CACollection new];

  seq = [self eachScalar];
  while ((scalar = [seq next]))
    [c add:scalar];

  assert ([c size] == [self numScalars]);
  return c;
}

- asNumerical
{
  int n;
  id v, seq;

  n = [self numScalars];
  v = [Vector scalarZero:[scalarZero asNumerical] numScalars:n];

  seq = [self eachScalar];
  while (n--)
    [v placeScalar:[[seq at:n] asNumerical] at:n];

  return v;
}

- asModp:(unsigned short)p
{
  int n;
  id v, seq;

  n = [self numScalars];
  v = [Vector scalarZero:[scalarZero asModp:p] numScalars:n];

  seq = [self eachScalar];
  while (n--)
    {
      id s = [[seq at:n] asModp:p];
      if (s == nil)
	[self error:"asModp: modulo failed"];
      [v placeScalar:s at:n];
    }

  return v;
}

- commonDenominator
{
  id d, s = [self eachScalar];
  d = [s commonDenominator];
  return d;
}

- onCommonDenominator:(id *)denominator
{
  id n, d, e;
  d = [self commonDenominator];
  e = [scalarZero numerator:d denominator:[d one]];
  n = [self multiplyScalar:e];
  *denominator = d;
  return [n asIntegral];
}

- asIntegral
{
  int n;
  id v, seq;

  n = [self numScalars];
  v = [Vector scalarZero:[scalarZero asIntegral] numScalars:n];

  seq = [self eachScalar];
  while (n--)
    [v placeScalar:[[seq at:n] asIntegral] at:n];

  return v;
}

- asFractional
{
  int n;
  id v, seq;

  n = [self numScalars];
  v = [Vector scalarZero:[scalarZero asTotalFraction] numScalars:n];

  seq = [self eachScalar];
  while (n--)
    [v placeScalar:[[seq at:n] asTotalFraction] at:n];

  return v;
}


- eachScalar
{
  return [carrier eachScalar];
}

- (float) floatValueAt:(int)i
{
  return [carrier floatValueAt:i];
}

- (int) intValueAt:(int)i
{
  return [carrier intValueAt:i];
}


- zero
{
  return [self numScalars:[self numScalars]];
}

- (BOOL) isZero
{
  return [carrier isZero];
}

- (BOOL) notZero
{
  return [carrier notZero];
}

- (BOOL) isOpposite:b
{
  [self checkSameClass:b];

  if (self == b)
    {
      return [self isZero] || [self isCharacteristicTwo];
    }
  else
    {
      return [carrier isOpposite:[b carrier]];
    }
}

- (BOOL) notOpposite:b
{
  if (self == b)
    {
      return [self notZero] && [self notCharacteristicTwo];
    }
  else
    {
      return [carrier notOpposite:[b carrier]];
    }
}

- negate
{
  if ([self isZero] || [self isCharacteristicTwo])
    {
      return self;
    }
  else
    {
      return [self over:[carrier negate]];
    }
}

- _double:(int)v
{
  if ([self isZero] || [self isCharacteristicTwo])
    {
      return [self zero];
    }
  else
    {
      return [self over:[carrier _double:v]];
    }
}

- double
{
  if ([self isZero] || [self isCharacteristicTwo])
    {
      return [self zero];
    }
  else
    {
      return [self over:[carrier double]];
    }
}

- _add:(int)v:b:(int)w
{
  assert ([self sameClass:b] && v * v == 1 && w * w == 1);

  if (self == b)
    {
      return (v == w) ? [self _double : v]:[self zero];
    }
  else
    {
      if ([self inAdditiveMonoid])
	{
	  if ([self isZero])
	    return [b _negate:w];
	  if ([b isZero])
	    return [self _negate:v];
	}
      return [self over:[carrier _add:v:[b carrier]:w]];
    }
}

- add:b
{
  [self checkSameClass:b];

  if (self == b)
    {
      return [self double];
    }
  else
    {
      if ([self inAdditiveMonoid])
	{
	  if ([self isZero])
	    return b;
	  if ([b isZero])
	    return self;
	}
      return [self over:[carrier add:[b carrier]]];
    }
}

- subtract:b
{
  [self checkSameClass:b];

  if (self == b)
    {
      return [self zero];
    }
  else
    {
      if ([self inAdditiveMonoid])
	{
	  if ([self isZero])
	    return [b negate];
	  if ([b isZero])
	    return self;
	}
      return [self over:[carrier subtract:[b carrier]]];
    }
}

- addScalar:s at:(int)i
{
  if (0 <= i && i < [self numScalars])
    {
      id c, sum, aSequence = [self eachScalar];
      sum = [[aSequence at:i] add:s];

      c = [self copy];
      [c placeScalar:sum at:i];
      return c;
    }
  else
    {
      return [self error:"-addScalar:at: index out of bounds"];
    }
}
- subtractScalar:s at:(int)i
{
  if (0 <= i && i < [self numScalars])
    {
      id c, sum, aSequence = [self eachScalar];
      sum = [[aSequence at:i] subtract:s];

      c = [self copy];
      [c placeScalar:sum at:i];
      return c;
    }
  else
    {
      return [self error:"-addScalar:at: index out of bounds"];
    }
}


- multiplyScalar:s
{
  assert ([scalarZero sameClass:s]);

  if ([s isZero])
    return [self zero];
  if ([s isOne])
    return self;
  if ([s isMinusOne])
    return [self negate];

  return [self over:[carrier multiplyScalar:s]];
}

- divideScalar:s
{
  id tmp;
  assert ([scalarZero sameClass:s]);

  if ([s isZero])
    return nil;
  if ([s isOne])
    return self;
  if ([s isMinusOne])
    return [self negate];

  if ((tmp = [carrier divideScalar:s]))
    {
      return [self over:tmp];
    }
  else
    {
      return nil;
    }
}

- _add:(int)v:B multiplyScalar:b:(int)w
{
  assert ([self sameClass:B] && [scalarZero sameClass:b] && v * v == 1 && w * w == 1);

  if ([b isZero])
    return [self _negate:v];
  if ([b isOne])
    return [self _add:v:B:+w];
  if ([b isMinusOne])
    return [self _add:v:B:-w];

  return [self over:[carrier _add:v:[B carrier] multiplyScalar:b:w]];
}

- _multiplyScalar:a:(int)v add:B:(int)w
{
  assert ([scalarZero sameClass:a] && [self sameClass:B] && v * v == 1 && w * w == 1);

  if ([a isZero])
    return [B _negate:+w];
  if ([a isOne])
    return [self _add:+v:B:+w];
  if ([a isMinusOne])
    return [self _add:-v:B:+w];

  return [self over:[carrier _multiplyScalar:a:v add:[B carrier]:w]];
}

- _multiplyScalar:a:(int)v add:B multiplyScalar:b:(int)w
{
  assert ([scalarZero sameClass:a] && [self sameClass:B] && [scalarZero sameClass:b] && v * v == 1 && w * w == 1);

  if ([a isZero])
    return [B _multiplyScalar:b:+w];
  if ([b isZero])
    return [self _multiplyScalar:a:+v];
  if ([a isOne])
    return [self _add:+v:B multiplyScalar:b:+w];
  if ([b isOne])
    return [self _multiplyScalar:a:+v add:B:+w];
  if ([a isMinusOne])
    return [self _add:-v:B multiplyScalar:b:+w];
  if ([b isMinusOne])
    return [self _multiplyScalar:a:+v add:B:-w];

  return [self over:[carrier _multiplyScalar:a:v add:[B carrier] multiplyScalar:b:w]];
}


- dotSquare
{
  return [carrier dotSquare];
}

- dotMultiply:aVector
{
  return [carrier dotMultiply:[aVector carrier]];
}

- multiplyLeftMatrix:aMatrix
{
  id v;
  int n;

  n = [aMatrix numRows];
  v = [self capacity:n];
  while (n--)
    [v insertScalar:[[aMatrix rowAt:n] dotMultiply:self]];
  return v;
}

- divideLeftMatrix:aMatrix
{
  return [aMatrix solveVector:self];
}

- printOn:(IOD)aFile
{
  if ([self numScalars])
    {
      id scalar, sequence = [self eachScalar];
      fprintf (aFile, "{");
      [[sequence firstElement] printOn:aFile];
      while ((scalar = [sequence next]))
	{
	  fprintf (aFile, ",");
	  [scalar printOn:aFile];
	}
      fprintf (aFile, "}");
    }
  else
    {
      fprintf (aFile, "{}");
    }

  return self;
}

@end
 
