
/*
 * Computer Algebra Kit (c) 1993,2000,14 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: term.m,v 1.10 2014/03/04 09:59:25 stes Exp $
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

@implementation Term
- check
{
  assert (scalarZero);
  [scalarZero check];
  if (symbol)
    [symbol check];
  assert ((exponent == 0 && symbol == nil) || (exponent && symbol));
  assert (coefficient);
  [coefficient check];
  if ([coefficient differentClass:scalarZero])
    {
      assert ([[coefficient scalarZero] sameClass:scalarZero]);
      if ([coefficient isVariableSparse])
	{
	  if (symbol)
	    {
	      id z = [coefficient asScalar];
	      assert (z == nil || [z differentClass:scalarZero]);
	      assert ([coefficient compareSymbols:self] < 0);
	    }
	  else
	    {
	      /* symbol nil might occur after derive, divide etc
	       * when the exponent drops to zero
	       * it's a polynomial lifted to a term
	       * but this case does *NOT* occur inside a varsps polynomial
	       */
	    }
	}
      else
	{
	  /* don't compare wrt to alphabetic in vardns case */
	  assert (symbol == nil || symbol != nil);
	}
    }
  return self;
}


- _setUpScalarZero:aZero coefficient:aCoefficient symbol:aSymbol exponent:(int)anExponent
{
  scalarZero = aZero;
  if ([aZero notZero])
    [self error:"Scalar must be zero"];
  coefficient = aCoefficient;
  exponent = anExponent;
  symbol = (exponent == 0) ? nil : aSymbol;
  assert ([self check]);
  return self;
}

- scalarZero:aScalar coefficient:aCoefficient symbol:aSymbol exponent:(int)anExponent
{
  return [self notImplemented:_cmd];
}

+ scalarZero:aZero coefficient:aCoefficient symbol:aSymbol exponent:(int)anExponent
{
  return [[super new] _setUpScalarZero:aZero coefficient:aCoefficient symbol:aSymbol exponent:anExponent];
}

- scalar:aScalar symbol:aSymbol exponent:(int)anExponent
{
  return [self notImplemented:_cmd];
}

+ scalar:aScalar symbol:aSymbol exponent:(int)anExponent
{
  return [self scalarZero:[aScalar zero] coefficient:aScalar symbol:aSymbol exponent:anExponent];
}

+ coefficient:aCoefficient symbol:aSymbol exponent:(int)anExponent
{
  id aZero = [aCoefficient scalarZero];
  return [self scalarZero:aZero coefficient:aCoefficient symbol:aSymbol exponent:anExponent];
}

- copycoefficient
{
  if (![coefficient sameClass:scalarZero])
    {
      coefficient = [coefficient copy];
    }
  return self;
}

- copy
{
  return [[super copy] copycoefficient];
}
- deepcopycoefficient
{
  scalarZero = [scalarZero deepCopy];
  coefficient = [coefficient deepCopy];
  if (symbol)
    symbol = [symbol deepCopy];
  return self;
}

- deepCopy
{
  return [[super deepCopy] deepcopycoefficient];
}
- clonecoefficient
{
  coefficient = nil;
  symbol = nil;
  return self;
}

- clone
{
  return [[super clone] clonecoefficient];
}

- setcoefficient:aCoefficient symbol:aSymbol exponent:(int)anExponent
{
  coefficient = aCoefficient;
  symbol = aSymbol;
  exponent = anExponent;
  assert ([self check]);
  return self;
}

- coefficient:aCoefficient symbol:aSymbol exponent:(int)anExponent
{
  return [[self clone] setcoefficient:aCoefficient symbol:aSymbol exponent:anExponent];
}

- coefficient:aCoefficient exponent:(int)anExponent
{
  if (exponent)
    {
      assert ([symbol check]);
      return [self coefficient:aCoefficient symbol:symbol exponent:anExponent];
    }
  else
    {
      assert (symbol == nil);
      if (anExponent)
	{
	  return [self error:""];
	}
      else
	{
	  return [self coefficient:aCoefficient symbol:nil exponent:0];
	}
    }
}

- coefficient:aCoefficient
{
  return [self notImplemented:_cmd];
}

- symbol:aSymbol exponent:(int)anExponent
{
  return [self notImplemented:_cmd];
}

- (BOOL)sameClass:b
{
  return isa == [b class];
}

- (BOOL)inAdditiveSemiGroup		
{
  return YES;
}
- (BOOL)inAdditiveMonoid		
{
  return YES;
}
- (BOOL)inAdditiveGroup			
{
  return YES;
}

- (BOOL)inSemiGroup			
{
  return YES;
}
- (BOOL)inMonoid			
{
  return YES;
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


- addSymbolsTo:aCltn
{
  if ([coefficient sameClass:scalarZero])
    {
      if (symbol)
	[aCltn addIfAbsent:symbol];
    }
  else
    {
      [coefficient addSymbolsTo:aCltn];
      if (symbol)
	[aCltn addIfAbsent:symbol];
    }

  return aCltn;
}

- scalarZero
{
  return scalarZero;
}

- coefficient
{
  return coefficient;
}

- (BOOL) isCoefficient
{
  return exponent == 0;
}

- symbol
{
  return symbol;
}

- (int) exponent
{
  return exponent;
}

- (int) degree
{
  return exponent;
}

- (unsigned) hash
{
  if (exponent)
    {
      return ([coefficient hash] & 255) + (((unsigned) exponent) << 8) + ([symbol hash] << 16);
    }
  else
    {
      return ([coefficient hash] & 255);
    }
}

- (BOOL) isEqual:b
{
  assert ([self check]);
  assert ([b check]);

  if (self == b)
    {
      return YES;
    }
  else
    {
      if ([coefficient differentClass:[b coefficient]])
	return NO;

      if (exponent)
	{
	  return [coefficient isEqual:[b coefficient]] && exponent == [b exponent] && [symbol isEqual:[b symbol]];
	}
      else
	{
	  return 0 == [b exponent] && [coefficient isEqual:[b coefficient]];
	}
    }
}

- (int) compareSymbols:aTerm
{
  /* don't check because check invokes compareSymbols
   * assert([self check]);assert([aTerm check]);
   */

  if (self == aTerm)
    {
      return 0;
    }
  else
    {
      if (symbol)
	{
	  id aSymbol = [aTerm symbol];
	  return (aSymbol) ? [symbol compare : aSymbol]:+1;
	}
      else
	{
	  return ([aTerm symbol]) ? -1 : 0;
	}
    }
}

- (int) compareExponents:b
{
  /* don't check because check invokes compareSymbols
   * assert([self check]);assert([b check]);
   */

  if (self == b)
    {
      return 0;
    }
  else
    {
      int cmp = [self compareSymbols:b];
      if (cmp == 0)
	{
	  cmp = exponent - [b exponent];
	  return (cmp == 0) ? 0 : ((cmp < 0) ? -1 : +1);
	}
      else
	{
	  return cmp;
	}
    }
}


- (int) intValue
{
  if (exponent)
    {
      [self error:"-intValue: term not intValue"];
      return 0;
    }
  else
    {
      return [coefficient intValue];
    }
}

- intValue:(int)aValue
{
  id c = [coefficient intValue:aValue];
  return [self coefficient:c symbol:nil exponent:0];
}

- (float) floatValue
{
  if (exponent)
    {
      [self error:"-floatValue: term not floatValue"];
      return 0;
    }
  else
    {
      return [coefficient floatValue];
    }
}

- floatValue:(float)aValue
{
  id c = [coefficient floatValue:aValue];
  return [self coefficient:c symbol:nil exponent:0];
}

- asScalar
{
  if (exponent)
    {
      return nil;
    }
  else
    {
      if ([coefficient sameClass:scalarZero])
	{
	  return coefficient;
	}
      else
	{
	  return [coefficient asScalar];
	}
    }
}

- scalar:aScalar
{
  if ([coefficient sameClass:scalarZero])
    {
      assert ([scalarZero sameClass:aScalar]);
      return [self coefficient:aScalar symbol:nil exponent:0];
    }
  else
    {
      return [self coefficient:[coefficient scalar:aScalar] symbol:nil exponent:0];
    }
}

- asSymbol
{
  if (exponent == 0)
    {
      if ([coefficient sameClass:scalarZero])
	{
	  return nil;
	}
      else
	{
	  return [coefficient asSymbol];
	}
    }

  if (exponent == 1)
    {
      return ([coefficient isOne]) ? symbol : nil;
    }

  return nil;
}

- symbol:aSymbol
{
  /* this method must be used with termOne or termZero */
  assert ([self isZero] || [self isOne]);
  assert ([aSymbol check]);

  if (symbol)
    {
      if ([symbol isEqual:aSymbol])
	{
	  id c = [coefficient one];
	  return [self coefficient:c symbol:aSymbol exponent:1];
	}
      else
	{
	  id c = [coefficient symbol:aSymbol];
	  return (c) ? [self coefficient : c symbol:nil exponent:0]:nil;
	}
    }
  else
    {
      id c = [coefficient one];
      return [self coefficient:c symbol:aSymbol exponent:1];
    }
}

- asNumerical
{
  id s = [scalarZero asNumerical];
  id c = [coefficient asNumerical];
  return [isa scalarZero:s coefficient:c symbol:symbol exponent:exponent];
}

- asModp:(unsigned short)p
{
  id s = [scalarZero asModp:p];
  id c = [coefficient asModp:p];
  return [isa scalarZero:s coefficient:c symbol:symbol exponent:exponent];
}


- zero
{
  return [self coefficient:[coefficient zero] symbol:nil exponent:0];
}

- (BOOL) isZero
{
  return [coefficient isZero];
}

- (BOOL) isOpposite:b
{
  assert ([self check]);
  assert ([b check]);

  if (exponent)
    {
      if ([coefficient differentClass:[b coefficient]])
	return NO;

      return exponent == [b exponent] && [symbol isEqual:[b symbol]] && [coefficient isOpposite:[b coefficient]];
    }
  else
    {
      return 0 == [b exponent] && nil == [b symbol] && [coefficient isOpposite:[b coefficient]];
    }
}

- negate
{
  return [self coefficient:[coefficient negate] exponent:exponent];
}

- double
{
  return [self coefficient:[coefficient double] exponent:exponent];
}

- add:b
{
  assert ([self check]);
  assert ([b check]);

  if (self == b)
    {
      return [self double];
    }
  else
    {
      int e;
      id c, s, z;

      [self checkSameClass:b];
      if ([self isZero])
	return b;
      if ([b isZero])
	return self;

      if (exponent)
	{
	  assert (exponent == [b exponent] && [symbol isEqual:[b symbol]]);
	  s = symbol;
	  e = exponent;
	}
      else
	{
	  assert (exponent == [b exponent]);
	  s = nil;
	  e = 0;
	}

      if ([coefficient sameClass:scalarZero])
	{
	  if ([[b coefficient] sameClass:scalarZero])
	    {
	      c = [coefficient add:[b coefficient]];
	    }
	  else
	    {
	      c = [[b coefficient] addScalar:coefficient];
	    }
	}
      else
	{
	  if ([[b coefficient] sameClass:scalarZero])
	    {
	      c = [coefficient addScalar:[b coefficient]];
	    }
	  else
	    {
	      c = [coefficient add:[b coefficient]];
	      if ([c isVariableSparse] && (z = [c asScalar]))
		c = z;
	    }
	}

      return [self coefficient:c symbol:s exponent:e];
    }
}

- subtract:b
{
  assert ([self check]);
  assert ([b check]);

  if (self == b)
    {
      return [self zero];
    }
  else
    {
      int e;
      id c, s, z;

      [self checkSameClass:b];
      if ([self isZero])
	return [b negate];
      if ([b isZero])
	return self;

      if (exponent)
	{
	  assert (exponent == [b exponent] && [symbol isEqual:[b symbol]]);
	  s = symbol;
	  e = exponent;
	}
      else
	{
	  assert (exponent == [b exponent]);
	  s = nil;
	  e = 0;
	}

      if ([coefficient sameClass:scalarZero])
	{
	  if ([[b coefficient] sameClass:scalarZero])
	    {
	      c = [coefficient subtract:[b coefficient]];
	    }
	  else
	    {
	      c = [[[b coefficient] subtractScalar:coefficient] negate];
	    }
	}
      else
	{
	  if ([[b coefficient] sameClass:scalarZero])
	    {
	      c = [coefficient subtractScalar:[b coefficient]];
	    }
	  else
	    {
	      c = [coefficient subtract:[b coefficient]];
	      if ([c isVariableSparse] && (z = [c asScalar]))
		c = z;
	    }
	}

      return [self coefficient:c symbol:s exponent:e];
    }
}


- one
{
  assert ([self check]);
  return [self coefficient:[coefficient one] symbol:nil exponent:0];
}

- (BOOL) isOne
{
  assert ([self check]);
  return [coefficient isOne] && exponent == 0;
}

- (BOOL) isMinusOne
{
  assert ([self check]);
  return [coefficient isMinusOne] && exponent == 0;
}

- square
{
  return [self coefficient:[coefficient square] exponent:exponent + exponent];
}

- inverse
{
  id c = [coefficient inverse];
  return (c) ? [self coefficient : c exponent:-exponent]:nil;
}

- multiplyScalar:b
{
  id c;
  assert ([self check]);
  assert ([b check]);

  if ([b isZero])
    return [self zero];
  if ([b isOne])
    return self;
  if ([b isMinusOne])
    return [self negate];

  if ([coefficient sameClass:scalarZero])
    {
      c = [coefficient multiply:b];
    }
  else
    {
      c = [coefficient multiplyScalar:b];
    }

  return [self coefficient:c exponent:exponent];
}

- multiplyCoefficient:b
{
  assert ([self check] && [b check]);

  if ([b isZero])
    return [self zero];
  if ([b isOne])
    return self;
  if ([b isMinusOne])
    return [self negate];

  return [self coefficient:[coefficient multiply:b] exponent:exponent];
}

- varspsMultiplyCoefficient:b
{
  assert ([self check] && [b check] && [b isVariableSparse]);

  if ([b isZero])
    return [self zero];
  if ([b isOne])
    return self;
  if ([b isMinusOne])
    return [self negate];

  if ([coefficient sameClass:scalarZero])
    {
      id z, c = [b multiplyScalar:coefficient];
      if ((z = [c asScalar]))
	c = z;
      return [self coefficient:c exponent:exponent];
    }
  else
    {
      id z, c = [coefficient multiply:b];
      if ((z = [c asScalar]))
	c = z;
      return [self coefficient:c exponent:exponent];
    }
}

- multiply:b
{
  assert ([self check]);
  assert ([b check]);

  if (self == b)
    {
      return [self square];
    }
  else
    {
      int e;
      id c, s;

      [self checkSameClass:b];
      if ([self isZero] || [b isZero])
	return [self zero];
      if ([self isOne])
	return b;
      if ([b isOne])
	return self;

      if ((e = exponent + [b exponent]))
	{
	  if (exponent)
	    {
	      if ([b exponent])
		assert ([symbol isEqual:[b symbol]]);
	      s = symbol;
	    }
	  else
	    {
	      s = ([b exponent]) ? [b symbol] : nil;
	    }
	}
      else
	{
	  s = nil;
	}

      if ([coefficient sameClass:scalarZero])
	{
	  id z;
	  if ([[b coefficient] sameClass:scalarZero])
	    {
	      c = [coefficient multiply:[b coefficient]];
	    }
	  else
	    {
	      c = [[b coefficient] multiplyScalar:coefficient];
	      if ([c isVariableSparse] && (z = [c asScalar]))
		c = z;
	    }
	}
      else
	{
	  id z;
	  if ([[b coefficient] sameClass:scalarZero])
	    {
	      c = [coefficient multiplyScalar:[b coefficient]];
	      if ([c isVariableSparse] && (z = [c asScalar]))
		c = z;
	    }
	  else
	    {
	      c = [coefficient multiply:[b coefficient]];
	      if ([c isVariableSparse] && (z = [c asScalar]))
		c = z;
	    }
	}

      return (c) ? [self coefficient : c symbol:s exponent:e]:nil;
    }
}

- divideScalar:b
{
  id c;
  assert ([self check]);
  assert ([b check]);

  if ([b isZero])
    return nil;
  if ([b isOne])
    return self;
  if ([b isMinusOne])
    return [self negate];

  if ([coefficient sameClass:scalarZero])
    {
      c = [coefficient divide:b];
    }
  else
    {
      c = [coefficient divideScalar:b];
    }

  return (c) ? [self coefficient : c exponent:exponent]:nil;
}

- divideCoefficient:b
{
  id c;
  assert ([self check] && [b check]);

  if ([b isZero])
    return nil;
  if ([b isOne])
    return self;
  if ([b isMinusOne])
    return [self negate];

  c = [coefficient divide:b];
#ifndef NDEBUG
  if (c)
    {
      id d = [c multiply:b];
      assert ([d isEqual:coefficient]);
    }
#endif
  return (c) ? [self coefficient : c exponent:exponent]:nil;
}

- varspsDivideCoefficient:b
{
  assert ([self check] && [b check] && [b isVariableSparse]);

  if ([b isZero])
    return nil;
  if ([b isOne])
    return self;
  if ([b isMinusOne])
    return [self negate];

  if ([coefficient sameClass:scalarZero])
    {
      return nil;
    }
  else
    {
      id z, c = [coefficient divide:b];
      if ((z = [c asScalar]))
	c = z;
      return [self coefficient:c exponent:exponent];
    }
}

- subtractExponents:b
{
  int e, bexponent;

  bexponent = [b exponent];
  e = exponent - bexponent;

  if (e)
    {
      if (e > 0)
	{
	  id c, s;
	  if (exponent)
	    {
	      if (bexponent)
		assert ([symbol isEqual:[b symbol]]);
	      s = symbol;
	    }
	  else
	    {
	      s = (bexponent) ? [b symbol] : nil;
	    }
	  c = coefficient;
	  return [self coefficient:c symbol:s exponent:e];
	}
      else
	{
	  return nil;
	}
    }
  else
    {
      id c = coefficient;
      return [self coefficient:c symbol:nil exponent:0];
    }
}

- divide:b
{
  assert ([self check]);
  assert ([b check]);

  if ([b isZero])
    return nil;

  if (self == b)
    {
      return [self one];
    }
  else
    {
      int e;
      id c, s;

      [self checkSameClass:b];
      if ([self isZero])
	return [self zero];
      if ([self isOne])
	return self;
      if ([b isOne])
	return self;

      e = exponent - [b exponent];

      if ([coefficient sameClass:scalarZero])
	{
	  if ([[b coefficient] sameClass:scalarZero])
	    {
	      c = [coefficient divide:[b coefficient]];
	    }
	  else
	    {
	      return nil;
	    }
	}
      else
	{
	  if ([[b coefficient] sameClass:scalarZero])
	    {
	      id z;
	      c = [coefficient divideScalar:[b coefficient]];
	      if ([c isVariableSparse] && (z = [c asScalar]))
		c = z;
	    }
	  else
	    {
	      id z;
	      c = [coefficient divide:[b coefficient]];
	      if ([c isVariableSparse] && (z = [c asScalar]))
		c = z;
	    }
	}

      if (c)
	{
	  if (e)
	    {
	      if (exponent)
		{
		  if ([b exponent])
		    assert ([symbol isEqual:[b symbol]]);
		  s = symbol;
		}
	      else
		{
		  s = ([b exponent]) ? [b symbol] : nil;
		}
	    }
	  else
	    {
	      s = nil;
	    }
	  return [self coefficient:c symbol:s exponent:e];
	}
      else
	{
	  return nil;
	}
    }
}


- power:(int)n
{
  id c = [coefficient power:n];
  return [self coefficient:c exponent:exponent * n];
}

- root:(int)n
{
  id r = [coefficient root:n];
  if (r && exponent % n == 0)
    {
      return [self coefficient:r exponent:exponent / n];
    }
  else
    {
      return nil;
    }
}

- squareRoot
{
  id r = [coefficient squareRoot];
  if (r && exponent % 2 == 0)
    {
      return [self coefficient:r exponent:exponent / 2];
    }
  else
    {
      return nil;
    }
}


- frobenius
{
  id r = [coefficient frobenius];
  int n = [coefficient characteristic];
  return [self coefficient:r exponent:exponent * n];
}

- frobeniusInverse
{
  int n = [coefficient characteristic];
  id r = [coefficient frobeniusInverse];
  if (r && exponent % n == 0)
    {
      return [self coefficient:r exponent:exponent / n];
    }
  else
    {
      return nil;
    }
}


- derive
{
  if (exponent == 1)
    {
      id c = coefficient;
      return [self coefficient:c symbol:nil exponent:0];
    }

  if (exponent > 1)
    {
      id c = [coefficient multiplyIntValue:exponent];
      id s = symbol;
      return [self coefficient:c symbol:s exponent:exponent - 1];
    }

  return [self zero];
}

- integrate
{
  if (exponent)
    {
      id c = [coefficient divideIntValue:exponent];
      return (c) ? [self coefficient : c exponent:exponent + 1]:nil;
    }
  else
    {
      return [self zero];
    }
}

- substitute:(STR)aSymbol by:aPolynomial
{
  if ([coefficient sameClass:scalarZero])
    {
      return self;
    }
  else
    {
      id c = [coefficient substitute:aSymbol by:aPolynomial];
      return [self coefficient:c exponent:exponent];
    }
}

- makeDegreeDense
{
  if ([coefficient sameClass:scalarZero])
    {
      return self;
    }
  else
    {
      id c = [coefficient makeDegreeDense];
      id s = (symbol) ? symbol : nil;
      return [self coefficient:c symbol:s exponent:exponent];
    }
}

- makeDegreeSparse
{
  if ([coefficient sameClass:scalarZero])
    {
      return self;
    }
  else
    {
      id c = [coefficient makeDegreeSparse];
      id s = (symbol) ? symbol : nil;
      return [self coefficient:c symbol:s exponent:exponent];
    }
}

- changeRepresentationTo:aPrototype
{
  id new;
  assert ([aPrototype isExpanded] || [aPrototype isRecursive]);

  if ([coefficient sameClass:scalarZero])
    {
      new = [aPrototype scalar:coefficient];
      if (exponent)
	{
	  id x = [aPrototype symbol:symbol];
	  x = [x power:exponent];
	  new = [new multiply:x];
	}
    }
  else
    {
      new = [coefficient changeRepresentationTo:aPrototype];
      if (exponent)
	{
	  id x = [aPrototype symbol:symbol];
	  x = [x power:exponent];
	  new = [new multiply:x];
	}
    }

  return new;
}

- makeVariableSparse
{
  if ([coefficient sameClass:scalarZero])
    {
      return self;
    }
  else
    {
      id z;
      id c = [coefficient makeVariableSparse];
      id s = (symbol) ? symbol : nil;

      if ((z = [c asScalar]))
	c = z;
      return [self coefficient:c symbol:s exponent:exponent];
    }
}


- (BOOL) printsLeadingSign
{
  /* the structure of this method must match printing ! */

  if ([self isZero])
    {
      return NO;
    }
  else
    {
      if ([coefficient isOne])
	return NO;
      if ([coefficient isMinusOne])
	return YES;
      if (exponent)
	{
	  return ([coefficient printsSum]) ? NO : [coefficient printsLeadingSign];
	}
      else
	{
	  return [coefficient printsLeadingSign];
	}
    }
}

- (BOOL) printsSum
{
  /* the structure of this method must match printing ! */

  if ([self isZero])
    {
      return NO;
    }
  else
    {
      if ([coefficient isOne])
	return NO;
      if ([coefficient isMinusOne])
	return NO;
      if (exponent)
	{
	  return NO;
	}
      else
	{
	  return [coefficient printsSum];
	}
    }
}

- (BOOL) printsProduct
{
  /* the structure of this method must match printing ! */

  if ([self isZero])
    {
      return NO;
    }
  else
    {
      if ([coefficient isOne])
	return YES;
      if ([coefficient isMinusOne])
	return YES;
      if (exponent)
	{
	  return ([coefficient printsSum]) ? YES : [coefficient printsProduct];
	}
      else
	{
	  return [coefficient printsProduct];
	}
    }
}

- printOn:(IOD)aFile
{
  if ([coefficient isZero])
    {
      fprintf (aFile, "0");
      return self;
    }
  if ([coefficient isOne])
    {
      if (exponent)
	{
	  if (exponent != 1)
	    {
	      if ([symbol printsProduct] || [symbol printsSum] || [symbol printsLeadingSign])
		{
		  fprintf (aFile, "(");
		  [symbol printOn:aFile];
		  fprintf (aFile, ")");
		}
	      else
		{
		  [symbol printOn:aFile];
		}
	      fprintf (aFile, "^%i", exponent);
	    }
	  else
	    {
	      [symbol printOn:aFile];
	    }
	  return self;
	}
      else
	{
	  fprintf (aFile, "1");
	  return self;
	}
    }

  if ([coefficient isMinusOne])
    {
      if (exponent)
	{
	  fprintf (aFile, "-");
	  if (exponent != 1)
	    {
	      if ([symbol printsProduct] || [symbol printsSum] || [symbol printsLeadingSign])
		{
		  fprintf (aFile, "(");
		  [symbol printOn:aFile];
		  fprintf (aFile, ")");
		}
	      else
		{
		  [symbol printOn:aFile];
		}
	      fprintf (aFile, "^%i", exponent);
	    }
	  else
	    {
	      [symbol printOn:aFile];
	    }
	  return self;
	}
      else
	{
	  fprintf (aFile, "-1");
	  return self;
	}
    }

  if (exponent)
    {
      if ([coefficient printsSum])
	{
	  fprintf (aFile, "(");
	  [coefficient printOn:aFile];
	  fprintf (aFile, ")");
	}
      else
	{
	  [coefficient printOn:aFile];
	}

      fprintf (aFile, " ");

      if (exponent != 1)
	{
	  if ([symbol printsProduct] || [symbol printsSum] || [symbol printsLeadingSign])
	    {
	      fprintf (aFile, "(");
	      [symbol printOn:aFile];
	      fprintf (aFile, ")");
	    }
	  else
	    {
	      [symbol printOn:aFile];
	    }
	  fprintf (aFile, "^%i", exponent);
	}
      else
	{
	  [symbol printOn:aFile];
	}

      return self;
    }
  else
    {
      [coefficient printOn:aFile];
      return self;
    }
}


- fileOutOn:aFiler
{
  [super fileOutOn:aFiler];
  [aFiler fileOut:&exponent type:'i'];
  return self;
}

- fileInFrom:aFiler
{
  [super fileInFrom:aFiler];
  [aFiler fileIn:&exponent type:'i'];
  return self;
}

@end
 
