
/*
 * Computer Algebra Kit (c) 1993,00 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: monomial.m,v 1.7 2014/03/04 09:09:35 stes Exp $
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

@implementation Monomial
- check
{
  assert (termOne != nil && scalar != nil && terms != nil);
  [termOne check];
  [scalar check];
  [terms check];
  return [super check];
}


+ new
{
  return [self error:"+new: Cannot create monomial without scalar"];
}

- _setUpScalar:aScalar terms:aCarrier
{
  scalar = aScalar;
  termOne = [aCarrier termOne];
  terms = aCarrier;

  assert ([self check]);
  return self;
}

+ scalar:aScalar terms:aCarrier
{
  return [[super new] _setUpScalar:aScalar terms:aCarrier];
}

+ scalar:aScalar
{
  id aCarrier = [varsps_monomial scalarOne:[aScalar one]];
  return [self scalar:aScalar terms:aCarrier];
}

- scalar:aScalar symbols:aCltn
{
  return [self notImplemented:_cmd];
}

+ scalar:aScalar symbols:aCltn
{
  if ([aCltn isEmpty])
    {
      return [self error:"Monomial: Cltn must not be empty"];
    }
  else
    {
      id aCarrier = [vardns_monomial scalarOne:[aScalar one] symbols:aCltn];
      return [self scalar:aScalar terms:aCarrier];
    }
}

- doclone
{
  scalar = nil;
  terms = nil;
  _leadingTerm = nil;
  _symbols = nil;
  return self;
}

- clone
{
  return [[super clone] doclone];
}

- setscalar:aScalar terms:theTerms
{
  scalar = aScalar;
  terms = theTerms;
  assert ([self check]);
  return self;
}

- scalar:aScalar terms:theTerms
{
  return [[self clone] setscalar:aScalar terms:theTerms];
}

- empty
{
  return [self scalar:[scalar one] terms:[terms empty]];
}

- copy
{
  return [self scalar:scalar terms:[terms copy]];
}

- deepCopy
{
  return [self scalar:[scalar deepCopy] terms:[terms deepCopy]];
}

- invalidate
{
  if (_leadingTerm)
    _leadingTerm = nil;
  if (_symbols)
    _symbols = nil;
  return [super invalidate];
}


- asNumerical
{
  id s = [scalar asNumerical];
  return [self scalar:s terms:[terms copy]];
}

- asModp:(unsigned short)p
{
  id s = [scalar asModp:p];
  return [self scalar:s terms:[terms copy]];
}

- (int) intValue
{
  if ([self numTerms])
    {
      [self error:"-intValue: monomial not intValue"];
      return 0;
    }
  else
    {
      return [scalar intValue];
    }
}

- intValue:(int)aValue
{
  id c = [scalar intValue:aValue];
  return (c) ? [self scalar : c terms:[terms empty]]:nil;
}

- (float) floatValue
{
  if ([self numTerms])
    {
      [self error:"-floatValue: monomial not floatValue"];
      return 0;
    }
  else
    {
      return [scalar floatValue];
    }
}

- floatValue:(float)aValue
{
  id c = [scalar floatValue:aValue];
  return (c) ? [self scalar : c terms:[terms empty]]:nil;
}

- (BOOL) isScalar
{
  return ([self numTerms] == 0);
}

- asScalar
{
  return ([self numTerms] == 0) ? scalar : nil;
}

- scalar:aScalar
{
  assert ([scalar sameClass:aScalar]);
  return [self scalar:aScalar terms:[terms empty]];
}

- termsAsSymbol
{
  if ([self numTerms] == 1)
    {
      id lt = [self leadingTerm];
      return (lt) ? [lt asSymbol] : nil;
    }
  else
    {
      return nil;
    }
}

- termsSymbol:aSymbol
{
  if ([self isVariableDense] && [[terms symbols] offsetOf:aSymbol] == -1)
    {
      return nil;
    }
  else
    {
      id term = [termOne symbol:aSymbol];
      assert ([termOne symbol] == nil && term);		/* never fails */
      return [[terms empty] insertTerm:term];
    }
}

- asSymbol
{
  return ([scalar isOne]) ? [self termsAsSymbol] : nil;
}

- symbol:aSymbol
{
  id t = [self termsSymbol:aSymbol];
  return (t) ? [self scalar : [scalar one] terms:t]:nil;
}

- (BOOL)sameClass:b
{
  return isa == [b class] && [scalar sameClass:[b scalar]] && [terms sameClass:[b terms]];
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
  return [scalar characteristic];
}


- scalar
{
  return scalar;
}

- termOne
{
  return termOne;
}

- terms
{
  return terms;
}

- (BOOL) isMonic
{
  return [scalar isOne];
}

+ classTerms
{
  return [self doesNotRecognize:_cmd];
}

- (BOOL) isVariableSparse
{
  return [terms isVariableSparse];
}

- (BOOL) isVariableDense
{
  return [terms isVariableDense];
}

- (int) degree
{
  return [terms degree];
}

- (int) numTerms
{
  return [terms numTerms];
}

- (BOOL) isTerm
{
  return [terms numTerms] == 1;
}

- (BOOL) isEqual:aMonomial
{
  if (self == aMonomial)
    {
      return YES;
    }
  else
    {
      BOOL cmp;
      id aScalar = [aMonomial scalar];
      id aTerms = [aMonomial terms];
      cmp = [terms isEqual:aTerms];
      assert (cmp == NO || [terms compare:aTerms] == 0);
      return [scalar isEqual:aScalar] && cmp;
    }
}

- (unsigned) hash
{
  return ([scalar hash] << 24) + [terms hash];
}


- addSymbolsTo:aCltn
{
  id term, seq = [self eachTerm];
  while ((term = [seq next]))
    [term addSymbolsTo:aCltn];
  return aCltn;
}

- symbols
{
  if ([self isVariableDense])
    {
      return [terms symbols];
    }
  else
    {
      if (_symbols == nil)
	{
	  _symbols = [self addSymbolsTo:[CACollection new]];
	  [[_symbols sort] reverse];
	}
      return _symbols;
    }
}

- (BOOL) isOrderDegreeCompatible
{
  return [self isVariableDense] && [[self symbols] size] == 1;
}

- (BOOL) isOrderReverseDegreeCompatible
{
  return NO;
}

- (int) compareTerms:aMonomial
{
  return [terms compare:[aMonomial terms]];
}


- removeTerm
{
  id lt;
  assert ([self check]);
  lt = [terms removeTerm];
  [self invalidate];
  assert ([self check]);
  return lt;
}
- insertTerm:aTerm
{
  assert ([self check]);
  if ([aTerm isZero])
    {
      scalar = [scalar zero];
      terms = [terms empty];
    }
  else
    {
      id c = [aTerm coefficient];
      if ([c isOne])
	{
	  terms = [terms insertTerm:aTerm];
	}
      else
	{
	  id new = [aTerm coefficient:[c one] exponent:[aTerm exponent]];
	  scalar = [scalar multiply:c];
	  terms = [terms insertTerm:new];
	}
    }
  assert ([self check]);
  return [self invalidate];
}


- eachTerm
{
  return [terms eachTerm];
}

- leadingTerm
{
  if (_leadingTerm == nil && [self numTerms])
    {
      id aTerm, aSequence = [self eachTerm];
      while ((aTerm = [aSequence next]))
	{
	  if ([aTerm exponent])
	    {
	      _leadingTerm = aTerm;
	      break;
	    }
	}
    }
  return _leadingTerm;
}


- zero
{
  return [self scalar:[scalar zero] terms:[terms empty]];
}

- (BOOL) isZero
{
  return [scalar isZero];
}

- negate
{
  id s = [scalar negate];
  id t = [terms copy];
  return [self scalar:s terms:t];
}

- double
{
  id s = [scalar double];
  id t = [terms copy];
  return [self scalar:s terms:t];
}

- add:b
{
  if ([self compareTerms:b])
    {
      return nil;
    }
  else
    {
      id s = [scalar add:[b scalar]];
      id t = [terms copy];
      return [self scalar:s terms:t];
    }
}

- subtract:b
{
  if ([self compareTerms:b])
    {
      return nil;
    }
  else
    {
      id s = [scalar subtract:[b scalar]];
      id t = [terms copy];
      return [self scalar:s terms:t];
    }
}


- one
{
  return [self scalar:[scalar one] terms:[terms empty]];
}

- (BOOL) isOne
{
  return [scalar isOne] && [terms isEmpty];
}

- (BOOL) isMinusOne
{
  return [scalar isMinusOne] && [terms isEmpty];
}

- square
{
  return [self scalar:[scalar square] terms:[terms square]];
}

- multiply:b
{
  id s, t;
  [self checkSameClass:b];
  s = [scalar multiply:[b scalar]];
  t = [terms multiply:[b terms]];
  return [self scalar:s terms:t];
}

- multiplyScalar:s
{
  return [self scalar:[scalar multiply:s] terms:[terms copy]];
}

- divideScalar:s
{
  id c = [scalar divide:s];
  return (c) ? [self scalar : c terms:[terms copy]]:nil;
}

- divide:aMonomial
{
  id t;
  [self checkSameClass:aMonomial];
  if ((t = [terms divide:[aMonomial terms]]))
    {
      id s = [scalar divide:[aMonomial scalar]];
      return (s) ? [self scalar : s terms:t]:nil;
    }
  else
    {
      return nil;
    }
}

- divideTerms:aMonomial
{
  id t;
  [self checkSameClass:aMonomial];
  assert ([self check] && [aMonomial check]);
  t = [terms divide:[aMonomial terms]];
  return (t) ? [self scalar : scalar terms:t]:nil;
}


- gcd:aMonomial
{
  id gcd = [terms gcd:[aMonomial terms]];
  return [self scalar:[scalar one] terms:gcd];
}

- lcm:aMonomial
{
  id lcm = [terms lcm:[aMonomial terms]];
  return [self scalar:[scalar one] terms:lcm];
}


- frobenius
{
  id aTerm, aSequence;
  id m = [terms empty];
  id s = [scalar frobenius];

  aSequence = [self eachTerm];
  while ((aTerm = [aSequence next]))
    [m insertTerm:[aTerm frobenius]];

  return [self scalar:s terms:m];
}

- frobeniusInverse
{
  id s = [scalar frobeniusInverse];

  if (s)
    {
      id m = [terms empty];
      id aTerm, aSequence = [self eachTerm];
      while ((aTerm = [aSequence next]))
	{
	  aTerm = [aTerm frobeniusInverse];
	  if (aTerm)
	    [m insertTerm:aTerm];
	  else
	    {
	      return nil;
	    }
	}

      return [self scalar:s terms:m];
    }
  else
    {
      return nil;
    }
}

- changeRepresentationTo:aPrototype
{
  id new, seq, term;
  assert ([aPrototype isExpanded]);

  new = [aPrototype scalar:scalar];
  seq = [self eachTerm];
  while ((term = [seq next]))
    {
      id x = [term changeRepresentationTo:aPrototype];
      new = [new multiply:x];
    }

  return new;
}


- (BOOL) printsLeadingSign
{
  /* the structure of this method must match printing ! */

  if ([scalar isZero])
    return NO;
  if ([scalar isOne])
    return NO;
  if ([scalar isMinusOne])
    return YES;

  if ([terms isEmpty])
    {
      return [scalar printsLeadingSign];
    }
  else
    {
      return ([scalar printsSum]) ? NO : [scalar printsLeadingSign];
    }
}

- (BOOL) printsSum
{
  /* the structure of this method must match printing ! */

  if ([scalar isZero])
    return NO;
  if ([scalar isOne])
    return NO;
  if ([scalar isMinusOne])
    return NO;

  if ([terms isEmpty])
    {
      return [scalar printsSum];
    }
  else
    {
      return NO;
    }
}

- (BOOL) printsProduct
{
  /* the structure of this method must match printing ! */

  if ([scalar isZero])
    return NO;
  if ([scalar isOne])
    return [terms numTerms] > 0;
  if ([scalar isMinusOne])
    return [terms numTerms] > 0;

  if ([terms isEmpty])
    {
      return [scalar printsProduct];
    }
  else
    {
      return YES;
    }
}

- printTermsToFile:(FILE *)aFile
{
  assert ([self check]);

  if ([terms isEmpty])
    {
      fprintf (aFile, "1");
    }
  else
    {
      id term, seq;
      seq = [self eachTerm];
      do
	{
	  term = [seq next];
	}
      while ([term exponent] == 0);
      [term printOn:aFile];
      while ((term = [seq next]))
	{
	  if ([term exponent])
	    {
	      fprintf (aFile, " ");
	      [term printOn:aFile];
	    }
	}
    }

  return self;
}

- printOn:(IOD)aFile
{
  assert ([self check]);

  if ([scalar isZero])
    {
      fprintf (aFile, "0");
      return self;
    }
  if ([scalar isOne])
    {
      return [self printTermsToFile:aFile];
    }
  if ([scalar isMinusOne])
    {
      fprintf (aFile, "-");
      return [self printTermsToFile:aFile];
    }

  [scalar printOn:aFile];

  if ([terms isEmpty])
    {
      return self;
    }
  else
    {
      fprintf (aFile, " ");

      if ([scalar printsSum])
	{
	  fprintf (aFile, "(");
	  [self printTermsToFile:aFile];
	  fprintf (aFile, ")");
	}
      else
	{
	  [self printTermsToFile:aFile];
	}

      return self;
    }
}

@end
 
