
/*
 * Computer Algebra Kit (c) 1993,00 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: matrix.m,v 1.7 2014/03/04 09:38:34 stes Exp $
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

@implementation Matrix
- check
{
  int i, m, n;

  assert (rows && scalarZero && emptyVector);
  [rows check];
  [scalarZero check];
  [emptyVector check];

  assert ([scalarZero isEqual:[emptyVector scalarZero]]);
  assert ([emptyVector numScalars] == 0);

  m = [self numRows];
  n = [self numColumns];
  for (i = 0; i < m; i++)
    {
      assert ([[[rows at:i] scalarZero] isEqual:scalarZero]);
      assert ([[rows at:i] numScalars] == n);
    }

  return [super check];
}


+ diagonal:cltnOfScalars
{
  id c;
  int i, n = [cltnOfScalars size];
  if (n == 0)
    [self error:"Collection Must Not Be Empty"];

  c = [self scalarZero:[[cltnOfScalars lastElement] zero] numRows:n numColumns:n];
  for (i = 0; i < n; i++)
    [c placeScalar:[cltnOfScalars at:i] at:i:i];

  assert ([c isDiagonal]);
  return c;
}

+ circulant:cltnOfScalars
{
  id c;
  int i, j, n = [cltnOfScalars size];
  if (n == 0)
    [self error:"Collection Must Not Be Empty"];

  c = [self scalarZero:[[cltnOfScalars lastElement] zero] numRows:n numColumns:n];
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
	{
	  [c placeScalar:[cltnOfScalars at:(n - i + j) % n] at:i:j];
	}
    }
  return c;
}

+ companion:cltnOfScalars
{
  id c;
  id aZero;
  int i, n = [cltnOfScalars size];
  if (n == 0)
    [self error:"Collection Must Not Be Empty"];

  aZero = [[cltnOfScalars lastElement] zero];
  c = [self scalarZero:aZero numRows:n numColumns:n];
  for (i = 0; i < n - 1; i++)
    [c placeScalar:[aZero one] at:i + 1:i];
  for (i = 0; i < n; i++)
    [c placeScalar:[[cltnOfScalars at:i] negate] at:i:n - 1];
  return c;
}

+ hankel:rowScalars:colScalars
{
  id c;
  id obj;
  int i, j, k, n, m;

  n = [colScalars size] + 1;
  m = [rowScalars size];
  c = [self scalarZero:[[rowScalars lastElement] zero] numRows:n numColumns:m];

  for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
	{
	  k = i + j;
	  obj = (k < m) ? [rowScalars at : k]:[colScalars at:k - m];
	  [c placeScalar:obj at:i:j];
	}
    }

  return c;
}

+ toeplitz:rowScalars:colScalars
{
  id c;
  id obj;
  int i, j, k, n, m;

  n = [colScalars size];
  m = [rowScalars size] + 1;
  c = [self scalarZero:[[rowScalars lastElement] zero] numRows:n numColumns:m];

  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      {
	k = j - i + n - 1;
	obj = (k < n) ? [colScalars at : k]:[rowScalars at:k - n];
	[c placeScalar:obj at:i:j];
      }

  return c;
}

+ hilbert:(int)n scalarZero:aZero
{
  id c;
  id obj;
  int i, j, k;
  c = [self scalarZero:aZero numRows:n numColumns:n];

  for (k = 1; k < (n + n); k++)
    {
      obj = [aZero intValue:k];
      obj = [obj inverse];
      for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
	  {
	    if (i + j + 1 == k)
	      [c placeScalar:obj at:i:j];
	  }
    }

  return c;
}

+ hilbert:(int)n
{
  id aZero;

  aZero = [Integer new];
  aZero = [Fraction numerator:aZero denominator:[aZero one]];

  return [self hilbert:n scalarZero:aZero];
}


- _setUpScalarZero:aScalarZero numRows:(int)numRows numColumns:(int)numColumns
{
  if ([aScalarZero notZero])
    [self error:"ScalarZero Not Zero !"];

  scalarZero = aScalarZero;
  emptyVector = [Vector scalarZero:scalarZero numScalars:0];

  rows = [CACollection new:numRows];
  while (numRows--)
    [rows add:[emptyVector numScalars:numColumns]];
  return self;
}

- scalarZero:aScalarZero numRows:(int)numRows numColumns:(int)numColumns
{
  return [self notImplemented:_cmd];
}

+ scalarZero:aScalarZero numRows:(int)numRows numColumns:(int)numColumns
{
  return [[super new] _setUpScalarZero:aScalarZero numRows:numRows numColumns:numColumns];
}
- scalar:aScalar numRows:(int)numRows numColumns:(int)numColumns
{
  return [self notImplemented:_cmd];
}

+ scalar:aScalar numRows:(int)numRows numColumns:(int)numColumns
{
  id c;
  int i = (numRows < numColumns) ? numRows : numColumns;
  c = [self scalarZero:[aScalar zero] numRows:numRows numColumns:numColumns];
  while (i--)
    [c placeScalar:aScalar at:i:i];
  return c;
}
- setrows:r
{
  rows = r;
  return self;
}

- copy
{
  return [[super copy] setrows:[rows deepCopy]];
}

- dodeepCopy
{
  scalarZero = [scalarZero deepCopy];
  emptyVector = [emptyVector deepCopy];
  rows = [rows deepCopy];
  assert ([self check]);
  return self;
}

- deepCopy
{
  return [[super deepCopy] dodeepCopy];
}

- clone
{
  return [[super clone] setrows:nil];
}

- rows:c
{
  return [[super clone] setrows:c];
}

- doscalarZero:aZero emptyVector:aVector rows:c
{
  scalarZero = aZero;
  emptyVector = aVector;
  rows = c;
  assert ([self check]);
  return self;
}

- scalarZero:aZero emptyVector:aVector rows:c
{
  return [[super clone] doscalarZero:aZero emptyVector:aVector rows:c];
}

- numRows:(int)numRows numColumns:(int)numColumns
{
  id c = [rows capacity:numRows];
  while (numRows--)
    [c add:[emptyVector numScalars:numColumns]];
  return [self rows:c];
}

- emptyVector
{
  return emptyVector;
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

- rows
{
  return rows;
}

+ classVectors
{
  return [self doesNotRecognize:_cmd];
}

- (int) numRows
{
  /* don't invoke check here as we call numRows from check */
  return [rows size];
}

- (int) numColumns
{
  /* don't invoke check here as we call numRows from check */
  id row = [rows lastElement];
  return (row) ? [row numScalars] : 0;
}

- checkDimensionEqual:b
{
  if ([self numRows] != [b numRows])
    [self error:"numRows not equal"];
  if ([self numColumns] != [b numColumns])
    [self error:"numColumns not equal"];
  return self;
}

- checkSquare
{
  if ([self numRows] != [self numColumns])
    [self error:"Matrix not Square"];
  return self;
}

- (BOOL) isEqual:aMatrix
{
  if (self == aMatrix)
    {
      return YES;
    }
  else
    {
      int m = [self numRows];
      if (m == [aMatrix numRows])
	{
	  while (m--)
	    if ([[self rowAt:m] notEqual:[aMatrix rowAt:m]])
	      return NO;
	  return YES;
	}
      else
	{
	  return NO;
	}
    }
}

- (unsigned) hash
{
  return ([rows lastElement]) ? [[rows lastElement] hash] : 0;
}

- (BOOL) isDiagonal
{
  id ix;
  BOOL res;
  int i, j, m, n;

  m = [self numRows];
  n = [self numColumns];
  ix = [self eachSequence];
  res = YES;

  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      if (i != j)
	if ([[[ix at:i] at:j] notZero])
	  {
	    res = NO;
	    break;
	  }

  return res;
}

- (BOOL) isSymmetric
{
  id ix, jx;
  BOOL res;
  int i, j, m, n;

  m = [self numRows];
  n = [self numColumns];
  ix = [self eachSequence];
  jx = [self eachSequence];
  res = YES;

  for (i = 0; i < m; i++)
    for (j = 0; j < i; j++)
      if ([[[ix at:i] at:j] notEqual:[[jx at:j] at:i]])
	{
	  res = NO;
	  break;
	}

  return res;
}

- (BOOL) isAntiSymmetric
{
  id ix, jx;
  BOOL res;
  int i, j, m, n;

  m = [self numRows];
  n = [self numColumns];
  ix = [self eachSequence];
  jx = [self eachSequence];
  res = YES;

  for (i = 0; i < m; i++)
    for (j = 0; j < i; j++)
      if ([[[ix at:i] at:j] notOpposite:[[jx at:j] at:i]])
	{
	  res = NO;
	  break;
	}

  return res;
}


- insertRow:aVector
{
  id last;

  last = [rows lastElement];
  if (last != nil && [last numScalars] != [aVector numScalars])
    {
      [self error:"Rows Must Have Same Number of Scalars"];
    }

  [rows add:aVector];
  return [self invalidate];
}

- insertRow:aVector at:(int)i
{
  id last;

  last = [rows lastElement];
  if (last != nil && [last numScalars] != [aVector numScalars])
    {
      [self error:"Rows Must Have Same Number of Scalars"];
    }

  [rows at:i insert:aVector];
  return [self invalidate];
}

- insertColumn:aCollection
{
  int m, n;

  m = [rows size];
  n = [aCollection size];

  if (m)
    {
      if (m != n)
	[self error:"Columns Must Have Same Number of Scalars"];
    }
  else
    {
      /* load enough empty vectors in the matrix */
      while (n--)
	[rows add:[self emptyVector]];
    }

  while (m--)
    [[rows at:m] insertScalar:[aCollection at:m]];
  return [self invalidate];
}

- insertColumn:aCollection at:(int)i
{
  int m, n;

  m = [rows size];
  n = [aCollection size];

  if (m)
    {
      if (m != n)
	[self error:"Columns Must Have Same Number of Scalars"];
    }
  else
    {
      /* load enough empty vectors in the matrix */
      while (n--)
	[rows add:[self emptyVector]];
    }

  while (m--)
    [[rows at:m] insertScalar:[aCollection at:m] at:i];
  return [self invalidate];
}


- removeRow
{
  id r = [rows removeLast];
  [self invalidate];
  return r;
}

- removeRowAt:(int)i
{
  id r = [rows removeAt:i];
  [self invalidate];
  return r;
}

- removeColumn
{
  int j, m = [self numRows];
  if ([self numColumns])
    {
      id column = [rows capacity:m];
      for (j = 0; j < m; j++)
	[column add:[[rows at:j] removeScalar]];
      [self invalidate];
      return column;
    }
  else
    {
      return nil;
    }
}

- removeColumnAt:(int)i
{
  int j, m = [self numRows];
  if ([self numColumns])
    {
      id column = [rows capacity:m];
      for (j = 0; j < m; j++)
	[column add:[[rows at:j] removeScalarAt:i]];
      [self invalidate];
      return column;
    }
  else
    {
      return nil;
    }
}


- placeScalar:aScalar at:(int)i:(int)j
{
  [[rows at:i] placeScalar:aScalar at:j];
  return [self invalidate];
}

- replaceScalarAt:(int)i:(int)j with:aScalar
{
  [[rows at:i] replaceScalarAt:j with:aScalar];
  return [self invalidate];
}


- asNumerical
{
  id new;
  int i, m;
  id aZero, aVector;

  m = [self numRows];
  new = [rows capacity:m];
  for (i = 0; i < m; i++)
    [new add:[[rows at:i] asNumerical]];

  aZero = [scalarZero asNumerical];
  aVector = [emptyVector asNumerical];
  return [self scalarZero:aZero emptyVector:aVector rows:new];
}

- asModp:(unsigned short)p
{
  id new;
  int i, m;
  id aZero, aVector;

  m = [self numRows];
  new = [rows capacity:m];
  for (i = 0; i < m; i++)
    [new add:[[rows at:i] asModp:p]];

  aZero = [scalarZero asModp:p];
  aVector = [emptyVector asModp:p];
  return [self scalarZero:aZero emptyVector:aVector rows:new];
}

- commonDenominator
{
  id d, s = [self eachScalar];
  d = [s commonDenominator];
  return d;
}

- asIntegral
{
  int i, m;
  id aZero, aVector, new;

  m = [self numRows];
  new = [rows capacity:m];
  for (i = 0; i < m; i++)
    [new add:[[rows at:i] asIntegral]];

  aZero = [scalarZero asIntegral];
  aVector = [emptyVector asIntegral];
  return [self scalarZero:aZero emptyVector:aVector rows:new];
}

- asFractional
{
  int i, m;
  id aZero, aVector, new;

  m = [self numRows];
  new = [rows capacity:m];
  for (i = 0; i < m; i++)
    [new add:[[rows at:i] asFractional]];

  aZero = [scalarZero asTotalFraction];
  aVector = [emptyVector asFractional];
  return [self scalarZero:aZero emptyVector:aVector rows:new];
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


- rowAt:(int)i
{
  return [rows at:i];
}

- eachRow
{
  return [rows eachElement];
}

- eachScalar
{
  return [CASequence over:[CAMatrixSequenceScalars content:self]];
}

- eachSequence
{
  return [CASequence over:[CAMatrixSequenceSequences content:self]];
}

- (float) floatValueAt:(int)i:(int)j
{
  return [[rows at:i] floatValueAt:j];
}


- zero
{
  id c;
  int i, m;
  c = [rows capacity:m = [self numRows]];
  for (i = 0; i < m; i++)
    [c add:[[self rowAt:i] zero]];
  return [self rows:c];
}

- negate
{
  id c;
  int i, m;
  c = [rows capacity:m = [self numRows]];
  for (i = 0; i < m; i++)
    [c add:[[self rowAt:i] negate]];
  return [self rows:c];
}

- double
{
  id c;
  int i, m;
  c = [rows capacity:m = [self numRows]];
  for (i = 0; i < m; i++)
    [c add:[[self rowAt:i] double]];
  return [self rows:c];
}

- add:b
{
  if (self == b)
    {
      return [self double];
    }
  else
    {
      id c;
      int i, m;
      [self checkDimensionEqual:b];
      c = [rows capacity:m = [self numRows]];
      for (i = 0; i < m; i++)
	[c add:[[self rowAt:i] add:[b rowAt:i]]];
      return [self rows:c];
    }
}

- subtract:b
{
  if (self == b)
    {
      return [self double];
    }
  else
    {
      id c;
      int i, m;
      [self checkDimensionEqual:b];
      c = [rows capacity:m = [self numRows]];
      for (i = 0; i < m; i++)
	[c add:[[self rowAt:i] subtract:[b rowAt:i]]];
      return [self rows:c];
    }
}

- addScalar:s
{
  if ([s isZero])
    {
      return self;
    }
  else
    {
      int i, m;
      id c;
      c = [rows capacity:m = [self numRows]];
      for (i = 0; i < m; i++)
	[c add:[[self rowAt:i] addScalar:s at:i]];
      return [self rows:c];
    }
}

- subtractScalar:s
{
  if ([s isZero])
    {
      return self;
    }
  else
    {
      int i, m;
      id c;
      c = [rows capacity:m = [self numRows]];
      for (i = 0; i < m; i++)
	[c add:[[self rowAt:i] subtractScalar:s at:i]];
      return [self rows:c];
    }
}


- one
{
  id c;
  int m = [self numRows];
  int n = [self numColumns];
  c = [self zero];
  n = (n < m) ? n : m;
  while (n--)
    [c placeScalar:[scalarZero one] at:n:n];
  return self;
}

- square
{
  return [self multiply:self];
}

- multiply:b
{
  id c, bt;
  int i, j, m, n;

  assert ([b check] && [self check]);

  m = [self numRows];
  n = [b numColumns];
  if ([self numColumns] != [b numRows])
    {
      [self error:"-matrix multiply: numColumns!=numRows"];
    }

  bt = [b transpose];
  c = [self numRows:m numColumns:n];

  for (i = 0; i < m; i++)
    {
      id ri = [self rowAt:i];
      for (j = 0; j < n; j++)
	{
	  [c placeScalar:[ri dotMultiply:[bt rowAt:j]] at:i:j];
	}
    }

  return c;
}

- multiplyVector:aColumn
{
  return [aColumn multiplyLeftMatrix:self];
}


- multiplyScalar:b
{
  id c;
  int i, m;
  c = [rows capacity:m = [self numRows]];
  for (i = 0; i < m; i++)
    [c add:[[self rowAt:i] multiplyScalar:b]];
  return [self rows:c];
}


- divideScalar:b
{
  id c;
  int i, m;
  c = [rows capacity:m = [self numRows]];
  for (i = 0; i < m; i++)
    {
      id r = [[self rowAt:i] divideScalar:b];
      if (r)
	[c add:r];
      else
	return nil;
    }
  return [self rows:c];
}


- transpose
{
  id c, seq;
  int i, m = [self numRows];
  int j, n = [self numColumns];

  seq = [self eachSequence];
  c = [self numRows:n numColumns:m];

  for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
	{
	  [c placeScalar:[[seq at:i] at:j] at:j:i];
	}
    }

  return c;
}

- determinant
{
  id det;
  [self checkSquare];

  if ([scalarZero isFloatingPoint])
    {
      det = [self error:"No Determinant Over Floating Points Yet !"];
    }
  else if ([scalarZero inFieldOfFractions])
    {
      id n, d, m;
      m = [self onCommonDenominator:&d];
      d = [d power:[self numRows]];
      n = [m determinant];
      return [scalarZero numerator:n denominator:d];
    }
  else if ([scalarZero inField])
    {
      det = [self determinantGauss];
    }
  else if ([scalarZero inIntegralDomain])
    {
      det = [self determinantBareiss];
    }
  else
    {
      det = [self notImplemented:_cmd];
    }

  return det;
}

- determinantGauss
{
  int i, j, n, sign;
  id ri, rj, rn, p, q, det;

  /* create a scalar that will evolve into the determinant */

  det = [scalarZero one];
  rn = [rows deepCopy];
  n = [rn size];

  /* iterate over the rows */

  for (sign = +1, ri = nil, p = nil, i = 0; i < n; i++)
    {

      /* for the first row, search pivot in first column
       * for second row, search in second column etc
       */

      for (j = i; j < n; j++)
	{
	  ri = [rn at:j];
	  p = [ri removeScalar];
	  if (![p isZero])
	    break;
	}

      /* quit if no pivot or swap pivot onto diagonal */

      if (j == n)
	{
	  return [scalarZero zero];
	}
      if (j != i)
	{
	  sign = -sign;
	  [rn swapElementsAt:i:j];
	}

      det = [det multiply:p];
      p = [p inverse];
      assert (p);

      /* reduction step - modify behind back of "rn" member at "j"
       * so don't forget to update the reference at position "j"
       */

      for (j++; j < n; j++)
	{
	  rj = [rn at:j];
	  q = [rj removeScalar];
	  q = [q multiply:p];
	  rj = [rj subtract:ri multiplyScalar:q];
	  [rn at:j put:rj];
	}

      assert ([rn check]);
    }

  det = (sign > 0) ? det : [det negate];
  return det;
}

- determinantBareiss
{
  int i, j, n, sign;
  id ri, rj, rn, p, q, det;

  /* create a scalar that will evolve into the determinant */

  det = [scalarZero one];
  rn = [rows deepCopy];
  n = [rn size];

  /* iterate over the rows */

  for (sign = +1, ri = nil, p = nil, i = 0; i < n; i++)
    {

      /* for the first row, search pivot in first column
       * for second row, search in second column etc
       */

      for (j = i; j < n; j++)
	{
	  ri = [rn at:j];
	  p = [ri removeScalar];
	  if (![p isZero])
	    break;
	}

      /* quit if no pivot or swap pivot onto diagonal
       * unlike Gauss, have to modify rows with leading zero
       */

      if (j == n)
	{
	  return [scalarZero zero];
	}
      if (j != i)
	{
	  int k;
	  sign = -sign;
	  for (k = i; k < j; k++)
	    {
	      id rk = [rn at:k];
	      rk = [rk multiplyScalar:p divideScalar:det];
	      [rn at:k put:rk];
	    }
	  [rn swapElementsAt:i:j];
	}

      /* reduction step - modify behind back of "rn" member at "j"
       * so don't forget to update the reference at position "j"
       * multiply by current pivot - divide by previous pivot
       */

      for (j++; j < n; j++)
	{
	  rj = [rn at:j];
	  q = [rj removeScalar];
	  rj = [rj multiplyScalar:p subtract:ri multiplyScalar:q divideScalar:det];
	  [rn at:j put:rj];
	}

      assert ([rn check]);
      det = p;
    }

  det = (sign > 0) ? det : [det negate];
  return det;
}

- solveVector:y
{
  [emptyVector checkSameClass:y];
  [self checkSquare];

  if ([y numScalars] != [self numRows])
    {
      [self error:"Dimensions Not Compatible"];
    }
  else
    {
      id matrix;

      /* append column vector to matrix */

      matrix = [self copy];
      [matrix insertColumn:[y asCollection] at:[matrix numColumns]];

      if ([scalarZero inFieldOfFractions])
	{
	  id x = [matrix solveGaussDeterminant:NULL];
	  return x;
	}
      else if ([scalarZero inField])
	{
	  id x = [matrix solveGaussDeterminant:NULL];
	  return x;
	}
      else if ([scalarZero inIntegralDomain])
	{
	  id det, x;
	  x = [matrix solveBareissDeterminant:&det];
	  x = [x divideScalar:det];
	  return x;
	}
    }

  return [self notImplemented:_cmd];
}

- solveGaussDeterminant:(id *)detReference
{
  int i, j, n, sign;
  id ri, rj, p, q, rn, det, x;

  n = [self numRows];
  assert (n + 1 == [self numColumns]);
  rn = [rows deepCopy];

  det = (detReference) ? [scalarZero one] : nil;
  for (sign = (+1), ri = nil, p = nil, i = 0; i < n; i++)
    {

      for (j = i; j < n; j++)
	{
	  ri = [rn at:j];
	  p = [ri removeScalar];
	  if (![p isZero])
	    break;
	}

      if (j == n)
	{
	  [self error:"Matrix Singular"];
	}
      if (j != i)
	{
	  sign = -sign;
	  [rn swapElementsAt:i:j];
	}

      if (detReference)
	det = [det multiply:p];
      p = [p inverse];
      assert (p);
      ri = [ri multiplyScalar:p];
      [rn at:i put:ri];

      for (j++; j < n; j++)
	{
	  rj = [rn at:j];
	  q = [rj removeScalar];
	  rj = [rj subtract:ri multiplyScalar:q];
	  [rn at:j put:rj];
	}

      assert ([rn check]);
    }
  if (detReference)
    det = (sign > 0) ? det : [det negate];

  x = [emptyVector capacity:n + 1];
  x = [x insertScalar:[scalarZero minusOne]];
  i = n;
  while (i--)
    {
      q = [x dotMultiply:[rn at:i]];
      [x insertScalar:[q negate]];
    }

  if (detReference)
    *detReference = det;
  [x removeScalarAt:n];
  return x;
}

- solveBareissDeterminant:(id *)detReference
{
  int i, j, n, sign;
  id ri, rj, rk, p, q, piv, rn, det, x;

  n = [self numRows];
  assert (n + 1 == [self numColumns]);
  rn = [rows deepCopy];

  det = [scalarZero one];
  piv = [rows capacity:n];

  for (sign = (+1), ri = nil, p = nil, i = 0; i < n; i++)
    {

      for (j = i; j < n; j++)
	{
	  ri = [rn at:j];
	  p = [ri removeScalar];
	  if (![p isZero])
	    break;
	}

      if (j == n)
	{
	  [self error:"Matrix Singular"];
	}
      if (j != i)
	{
	  int k;
	  for (k = i; k < j; k++)
	    {
	      rk = [[rn at:k] multiplyScalar:p divideScalar:det];
	      [rn at:k put:rk];
	    }
	  sign = -sign;
	  [rn swapElementsAt:i:j];
	}

      for (j++; j < n; j++)
	{
	  rj = [rn at:j];
	  q = [rj removeScalar];
	  rj = [rj multiplyScalar:p subtract:ri multiplyScalar:q divideScalar:det];
	  [rn at:j put:rj];
	}

      [piv add:p];
      assert ([rn check]);
      det = p;
    }

  det = (sign > 0) ? det : [det negate];

  x = [emptyVector capacity:n + 1];
  p = [piv removeLast];
  if (sign > 0)
    {
      assert ([p isEqual:det]);
      x = [x insertScalar:[p negate]];
      x = [x insertScalar:[[rn at:n - 1] removeScalar]];
    }
  else
    {
      assert ([p isOpposite:det]);
      x = [x insertScalar:p];
      x = [x insertScalar:[[[rn at:n - 1] removeScalar] negate]];
    }
  i = n - 1;
  while (i--)
    {
      q = [x dotMultiply:[rn at:i]];
      p = [piv removeLast];
      q = [[q divide:p] negate];
      [x insertScalar:q];
    }

  if (detReference)
    *detReference = det;
  [x removeScalarAt:n];
  return x;
}

- inverse
{
  [self checkSquare];
  return [[self one] divide:self];
}

- divide:b
{
  if ([scalarZero inField])
    return [self divideGauss:b];
  return [self notImplemented:_cmd];
}

- divideGauss:b
{
  int i, j, n;
  id p, ri, rj, iri, irj, q, t, rn, irn, triangle;

  n = [self numRows];
  assert (n == [self numColumns] && n == [b numRows] && n == [b numColumns]);
  rn = [[b rows] deepCopy];
  irn = [rows deepCopy];
  triangle = [rows capacity:n];

  /*          - - -                 1 | |
   *     rn   - - -   ->  triangle    1 | 
   *          - - -                     1
   */

  for (ri = nil, p = nil, i = 0; i < n; i++)
    {

      t = [rn capacity:n];
      for (j = 0; j < i; j++)
	{
	  rj = [rn at:j];
	  [t add:[rj removeScalar]];
	  assert ([rn at:j]);
	}

      for (j = i; j < n; j++)
	{
	  ri = [rn at:j];
	  p = [ri removeScalar];
	  if (![p isZero])
	    break;
	}

      if (j == n)
	{
	  return nil;
	}
      if (j != i)
	{
	  [rn swapElementsAt:i:j];
	  [irn swapElementsAt:i:j];
	}

      p = [p inverse];
      assert (p);
      iri = [irn at:i];
      ri = [ri multiplyScalar:p];
      iri = [iri multiplyScalar:p];
      [rn at:i put:ri];
      [irn at:i put:iri];

      for (j++; j < n; j++)
	{
	  rj = [rn at:j];
	  q = [rj removeScalar];
	  rj = [rj subtract:ri multiplyScalar:q];
	  [rn at:j put:rj];
	  irj = [irn at:j];
	  irj = [irj subtract:iri multiplyScalar:q];
	  [irn at:j put:irj];
	}

      [triangle add:t];
      assert ([rn check]);
      assert ([irn check]);
    }

  while (i--)
    {
      t = [triangle at:i];
      iri = [irn at:i];
      for (j = i - 1; j >= 0; j--)
	{
	  q = [t removeLast];
	  irj = [irn at:j];
	  irj = [irj subtract:iri multiplyScalar:q];
	  [irn at:j put:irj];
	}
    }

  return [self rows:irn];
}

- (int) rank
{
  BOOL *rowmark;
  id q, qj, ri, rk, rm;
  int i, j, k, m, n, rank;

  m = [self numRows];
  n = [self numColumns];
  rm = [rows deepCopy];
  qj = [rows capacity:m];

  rowmark = (BOOL *) OC_Malloc (m * sizeof (BOOL));
  for (i = 0; i < m; i++)
    rowmark [i] = NO;

  for (q = nil, ri = nil, rank = n, j = 0; j < n; j++)
    {

      for (i = 0; i < m; i++)
	{
	  ri = [rm at:i];
	  q = [ri removeScalar];
	  if (rowmark [i] == NO && [q notZero])
	    break;
	  else
	    [qj add:q];
	}

      if (i == m)
	{
	  rank--;
	}
      else
	{
	  rowmark [i] = YES;

	  q = [q inverse];
	  assert (q);
	  ri = [ri multiplyScalar:q];
	  [rm at:i put:ri];

	  for (k = i - 1; k >= 0; k--)
	    {
	      q = [qj removeLast];
	      rk = [rm at:k];
	      [rm at:k put:[rk subtract:ri multiplyScalar:q]];
	    }

	  for (k = i + 1; k < m; k++)
	    {
	      rk = [rm at:k];
	      q = [rk removeScalar];
	      [rm at:k put:[rk subtract:ri multiplyScalar:q]];
	    }
	}

    }

  OC_Free (rowmark);
  return rank;
}

- (int) nullity
{
  return [self numColumns] - [self rank];
}

- rowReducedFormRank:(int *)rankReference indexRank:(int**)indexRankReference
{
  BOOL *rowmark;
  id q, qj, ri, rk, rm, rrf;
  int i, j, k, m, n, rank, *indexrank;

  m = [self numRows];
  n = [self numColumns];
  rm = [rows deepCopy];

  rrf = [rows capacity:n];
  rowmark = (BOOL *) OC_Malloc (sizeof (BOOL) * m);
  for (i = 0; i < m; i++)
    rowmark [i] = NO;
  indexrank = (int *) OC_Malloc (sizeof (int) * n);

  for (q = nil, ri = nil, rank = n, j = 0; j < n; j++)
    {

      qj = [rows capacity:m];

      for (i = 0; i < m; i++)
	{
	  ri = [rm at:i];
	  q = [ri removeScalar];
	  if (rowmark [i] == NO && [q notZero])
	    {
	      break;
	    }
	  else
	    {
	      [qj add:q];
	    }
	}

      if (i == m)
	{
	  indexrank [j] = -1;
	  rank--;
	}
      else
	{
	  indexrank [j] = i;
	  rowmark [i] = YES;

	  q = [q inverse];
	  assert (q);
	  ri = [ri multiplyScalar:q];
	  [rm at:i put:ri];
	  [qj add:[scalarZero one]];

	  for (k = 0; k < i; k++)
	    {
	      q = [qj at:k put:[scalarZero zero]];
	      rk = [[rm at:k] subtract:ri multiplyScalar:q];
	      [rm at:k put:rk];
	    }

	  for (k = i + 1; k < m; k++)
	    {
	      rk = [rm at:k];
	      q = [rk removeScalar];
	      rk = [rk subtract:ri multiplyScalar:q];
	      [rm at:k put:rk];
	      [qj add:[scalarZero zero]];
	    }
	}

      [rrf add:qj];
    }

  OC_Free (rowmark);
  *rankReference = rank;
  *indexRankReference = indexrank;
  return rrf;
}

- kernel
{
  id q, c, ker, rrf;
  int i, ix, j, k, n, rank, nullity, *indexrank;

  rrf = [self rowReducedFormRank:&rank indexRank:&indexrank];
  n = [self numColumns];
  nullity = n - rank;

  ker = [rows capacity:nullity];

  for (j = k = 1; j < nullity; j++, k++)
    {
      c = [emptyVector numScalars:n];
      while (indexrank [k] >= 0)
	k++;
      for (i = 0; i < k; i++)
	{
	  ix = indexrank [i];
	  if (ix < 0)
	    {
	      q = [scalarZero zero];
	    }
	  else
	    {
	      q = [[[rrf at:i] at:ix] negate];
	    }
	  [c placeScalar:q at:i];
	}
      [ker add:c];
    }

  OC_Free (indexrank);
  return ker;
}

- image
{
  id qk, c, image, rrf;
  int i, j, k, m, rank, *indexrank;

  rrf = [self rowReducedFormRank:&rank indexRank:&indexrank];
  m = [self numRows];

  image = [rows capacity:rank];

  for (j = k = 1; j < rank; j++, k++)
    {
      while (indexrank [k] < 0)
	k++;
      qk = [rrf at:k];
      c = [emptyVector numScalars:m];
      i = m;
      while (i--)
	[c placeScalar:[qk at:i] at:i];
      [image add:c];
    }

  OC_Free (indexrank);
  return image;
}


- trace
{
  int n;
  id seq, trace;
  [self checkSquare];

  trace = [scalarZero zero];
  n = [self numRows];

  seq = [self eachSequence];
  while (n--)
    trace = [trace add:[[seq at:n] at:n]];

  return trace;
}

- adjoint
{
  int k, n;
  id adj, c;

  n = [self numRows];
  k = [scalarZero characteristic];
  if (0 < k && k < n)
    [self error:"-adjoint: Characteristic to Small For This Implementation"];

  c = [self trace];
  c = [c negate];
  adj = [self addScalar:c];

  for (k = 2; k < n; k++)
    {
      assert ([adj check]);
      adj = [self multiply:adj];
      c = [adj trace];
      c = [c divideIntValue:-k];
      adj = [adj addScalar:c];
    }

  return adj;
}


- printOn:(IOD)aFile
{
  [rows printOn:aFile];
  return self;
}

@end
 
