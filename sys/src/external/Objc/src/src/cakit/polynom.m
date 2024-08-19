
/*
 * Computer Algebra Kit (c) 1993,2000,14 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: polynom.m,v 1.12 2014/03/04 14:39:43 stes Exp $
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

@implementation Polynomial
- check
{
  [super check];
  [scalarZero check];
  assert ([scalarZero isZero]);
  assert (carrier);
  [carrier check];
  assert ([[carrier scalarZero] isEqual:scalarZero]);
  assert ([[carrier termZero] isEqual:termZero]);
  assert ([[carrier monomialZero] isEqual:monomialZero]);

  if ([carrier isRecursive])
    {
      assert ([termZero isZero]);
      if ([carrier isVariableSparse])
	{
	  assert ([termZero exponent] == 0 && [termZero symbol] == nil);
	}
      else
	{
	  assert ([termZero exponent] == 1 && [termZero symbol] != nil);
	}
    }

  return self;
}


+ new
{
  return [self error:"+new: Cannot create polynomial without scalarZero"];
}

- _setUpCarrier:aCarrier
{
  scalarZero = [aCarrier scalarZero];
  termZero = [aCarrier termZero];
  monomialZero = [aCarrier monomialZero];
  carrier = aCarrier;
  assert ([self check]);
  return self;
}

+ over:aCarrier
{
  return [[super new] _setUpCarrier:aCarrier];
}

+ scalar:aScalar
{
  id classCarrier = [aScalar class_varspsrecdegsps_polynomial];
  return [Polynomial over:[classCarrier scalar:aScalar]];
}

- copy
{
  assert ([self check]);
  return [self over:[carrier copy]];
}

- deepCopy
{
  assert ([self check]);
  return [self over:[carrier deepCopy]];
}

- invalidate
{
  if (_leadingTerm)
    _leadingTerm = nil;
  if (_leadingMonomial)
    _leadingMonomial = nil;
  return [super invalidate];
}

- clearpoly
{
  carrier = nil;
  _leadingMonomial = nil;
  _leadingTerm = nil;
  _symbols = nil;
  _variables = nil;
  return self;
}

- clone
{
  return [[super clone] clearpoly];
}

- carrier
{
  return carrier;
}

- setcarrier:c
{
  carrier = c;
  assert ([self check]);
  return self;
}

- over:c
{
  return [[self clone] setcarrier:c];
}

- empty
{
  return [self over:[carrier empty]];
}

- dodifferentcarrier:c
{
  scalarZero = [c scalarZero];
  termZero = [c termZero];
  monomialZero = [c monomialZero];

  _zero = nil;
  _one = nil;
  _leadingMonomial = nil;
  _leadingTerm = nil;

  assert (c);
  carrier = c;

  assert ([self check]);
  return self;
}

- differentCarrier:c
{
  return [[super clone] dodifferentcarrier:c];
}

- emptyScalarZero:aZero
{
  id res = [self differentCarrier:[carrier emptyScalarZero:aZero]];
  assert ([res isVariableDense] == [self isVariableDense]);
  assert ([res isRecursive] == [self isRecursive]);
  assert ([res isDegreeDense] == [self isDegreeDense]);
  return res;
}

- emptyVariableDense:symbols
{
  id res = [self differentCarrier:[carrier emptyVariableDense:symbols]];
  assert ([res isVariableDense]);
  assert ([res isRecursive] == [self isRecursive]);
  assert ([res isDegreeDense] == [self isDegreeDense]);
  return res;
}

- emptyVariableSparse
{
  id res;
  if ([self isVariableSparse])
    {
      res = [self empty];
    }
  else
    {
      res = [self differentCarrier:[carrier emptyVariableSparse]];
    }
  assert ([res isVariableSparse]);
  assert ([res isRecursive] == [self isRecursive]);
  assert ([res isDegreeDense] == [self isDegreeDense]);
  return res;
}

- emptyExpanded
{
  id res;
  if ([self isExpanded])
    {
      res = [self empty];
    }
  else
    {
      res = [self differentCarrier:[carrier emptyExpanded]];
    }
  assert ([res isExpanded]);
  assert ([res isDegreeDense] == [self isDegreeDense]);
  assert ([res isVariableDense] == [self isVariableDense]);
  return res;
}

- emptyRecursive
{
  id res;
  if ([self isRecursive])
    {
      res = [self empty];
    }
  else
    {
      res = [self differentCarrier:[carrier emptyRecursive]];
    }
  assert ([res isRecursive]);
  assert ([res isDegreeDense] == [self isDegreeDense]);
  assert ([res isVariableDense] == [self isVariableDense]);
  return res;
}

- emptyDegreeSparse
{
  id res;
  if ([self isDegreeSparse])
    {
      res = [self empty];
    }
  else
    {
      res = [self differentCarrier:[carrier emptyDegreeSparse]];
    }
  assert ([res isDegreeSparse]);
  assert ([res isRecursive] == [self isRecursive]);
  assert ([res isVariableSparse] == [self isVariableSparse]);
  return res;
}

- emptyDegreeDense
{
  id res;
  if ([self isDegreeDense])
    {
      res = [self empty];
    }
  else
    {
      res = [self differentCarrier:[carrier emptyDegreeDense]];
    }
  assert ([res isDegreeDense]);
  assert ([res isRecursive] == [self isRecursive]);
  assert ([res isVariableSparse] == [self isVariableSparse]);
  return res;
}


+ wilkinsonDegree:(int)n
{
  return [self notImplemented:_cmd];
}

+ randomDegree:(int)n
{
  return [self notImplemented:_cmd];
}

+ bernouilliDegree:(int)n
{
  return [self notImplemented:_cmd];
}

+ binomialDegree:(int)n
{
  return [self notImplemented:_cmd];
}

+ chebyshevTDegree:(int)n
{
  return [self notImplemented:_cmd];
}

+ chebyshevUDegree:(int)n
{
  return [self notImplemented:_cmd];
}

+ cyclotomicDegree:(int)n
{
  return [self notImplemented:_cmd];
}

+ eulerDegree:(int)n
{
  return [self notImplemented:_cmd];
}

+ hermiteDegree:(int)n
{
  return [self notImplemented:_cmd];
}

+ laguerreDegree:(int)n
{
  return [self notImplemented:_cmd];
}

+ legendreDegree:(int)n
{
  return [self notImplemented:_cmd];
}
- (BOOL)sameClass:b
{
  return isa == [b class] && [carrier sameClass:[b carrier]];
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
  return [scalarZero inField] && [self inUnivariateDomain];
}
- (BOOL)inIntegralDomain		
{
  return [scalarZero inIntegralDomain];
}				/* Gauss' lemma */
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

- termZero
{
  if ([self isRecursive])
    {
      assert ([self isVariableSparse] || [termZero symbol] != nil);
      return termZero;
    }
  else
    {
      return [self error:"-termZero: polynomial must be recursive"];
    }
}

- monomialZero
{
  if ([self isExpanded])
    {
      return monomialZero;
    }
  else
    {
      return [self error:"-monomialZero: polynomial must be expanded"];
    }
}

+ classTerms
{
  return [self doesNotRecognize:_cmd];
}

+ classMonomials
{
  return [self doesNotRecognize:_cmd];
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

- (BOOL) isRecursive
{
  assert ([self check]);
  return [carrier isRecursive];
}

- (BOOL) isExpanded
{
  assert ([self check]);
  return [carrier isExpanded];
}

- (BOOL) isVariableSparse
{
  assert ([self check]);
  return [carrier isVariableSparse];
}

- (BOOL) isVariableDense
{
  assert ([self check]);
  return [carrier isVariableDense];
}

- (BOOL) isDegreeDense
{
  assert ([self check]);
  return [carrier isDegreeDense];
}

- (BOOL) isDegreeSparse
{
  assert ([self check]);
  return [carrier isDegreeSparse];
}

- (BOOL) isUnivariate
{
  return [[self symbols] size] == 1;
}

- (BOOL) inUnivariateDomain
{
  return [self isVariableDense] && [[self symbols] size] == 1;
}

- (BOOL) isMultivariate
{
  [self notImplemented:_cmd];
  return NO;
}


- (int) intValue
{
  if ([self isZero])
    {
      return 0;
    }
  else
    {
      id member = [self asMember];
      if (member)
	{
	  int res = [member intValue];
	  return res;
	}
      else
	{
	  [self error:"intValue: Polynomial must have integer value"];
	}
    }

  return 0;
}

- intValue:(int)aValue
{
  return [[self empty] insertMember:[[self memberZero] intValue:aValue]];
}

- (float) floatValue
{
  if ([self isZero])
    {
      return 0;
    }
  else
    {
      id member = [self asMember];
      if (member)
	{
	  float res = [member floatValue];
	  return res;
	}
      else
	{
	  [self error:"intValue: Polynomial must have integer value"];
	}
    }

  return 0;
}

- floatValue:(float)aValue
{
  return [[self empty] insertMember:[[self memberZero] floatValue:aValue]];
}

- asScalar
{
  id c = [carrier asScalar];
  assert (c == nil || [c sameClass:scalarZero]);
  return c;
}

- scalar:aScalar
{
  id member;
  assert ([self check]);
  [scalarZero checkSameClass:aScalar];
  member = [[self memberZero] scalar:aScalar];
  return (member) ? [[self empty] insertMember : member]:nil;
}

- asSymbol
{
  return [carrier asSymbol];
}

- symbol:aSymbol
{
  id member;
  assert ([self check]);
  member = [[self memberZero] symbol:aSymbol];
  return (member) ? [[self empty] insertMember : member]:nil;
}

- asTerm
{
  assert ([self check]);
  if ([self isExpanded])
    [self error:"asTerm: Polynomial must be recursive"];

  if ([self numTerms] == 1)
    {
      id seq, term;
      seq = [self eachTerm];
      term = [seq firstElement];
      return term;
    }
  else
    {
      return nil;
    }
}

- asMonomial
{
  assert ([self check]);
  if ([self isRecursive])
    [self error:"asMonomial: Polynomial must be expanded"];

  if ([self numMonomials] == 1)
    {
      id seq, monomial;
      seq = [self eachMonomial];
      monomial = [seq firstElement];
      return monomial;
    }
  else
    {
      return nil;
    }
}

- asMember
{
  return ([self isRecursive]) ? [self asTerm] : [self asMonomial];
}

- asCoefficient
{
  id term = [self asTerm];
  if (term)
    {
      id coef = [term coefficient];
      return coef;
    }
  else
    {
      return nil;
    }
}

- asNumerical
{
  id member, members, new;
  new = [self emptyScalarZero:[scalarZero asNumerical]];
  members = [self eachElement];
  while ((member = [members next]))
    {
      [new insertMember:[member asNumerical]];
    }
  return new;
}

- asModp:(unsigned short)p
{
  id member, members, new;
  new = [self emptyScalarZero:[scalarZero asModp:p]];
  members = [self eachElement];
  while ((member = [members next]))
    {
      [new insertMember:[member asModp:p]];
    }
  return new;
}

- commonDenominator
{
  id d, s = [self eachScalar];
  d = [s commonDenominator];
  return d;
}

- onCommonDenominator
{
  return [self notImplemented:_cmd];
}


- (int) compareSymbols:aTerm
{
  if ([self isRecursive])
    {
      id lt = [self leadingTerm];
      return (lt) ? [lt compareSymbols : aTerm]:-1;
    }
  else
    {
      [self notImplemented:_cmd];
      return 0;
    }
}

- addSymbolsTo:aCltn
{
  id member, seq = [self eachElement];
  while ((member = [seq next]))
    [member addSymbolsTo:aCltn];
  return aCltn;
}

- symbols
{
  if ([self isVariableDense])
    {
      return [carrier symbols];
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

- variables
{
  [self notImplemented:_cmd];
  return nil;
}


- (int) degree
{
  if ([self isRecursive])
    {
      return [carrier leadingDegree];
    }
  else
    {
      if ([monomialZero isOrderDegreeCompatible])
	return [carrier leadingDegree];
      if ([monomialZero isOrderReverseDegreeCompatible])
	return [carrier lastDegree];
      return [carrier maxDegree];
    }
}

- (int) order
{
  if ([self isRecursive])
    {
      return [carrier lastDegree];
    }
  else
    {
      if ([monomialZero isOrderDegreeCompatible])
	return [carrier lastDegree];
      if ([monomialZero isOrderReverseDegreeCompatible])
	return [carrier leadingDegree];
      return [carrier minDegree];
    }
}

- (int) numTerms
{
  if ([self isExpanded])
    {
      [self error:"-numTerms: Polynomial must be recursive"];
      return 0;
    }
  else
    {
      return [carrier numTerms];
    }
}

- (int) numMonomials
{
  if ([self isRecursive])
    {
      [self error:"-numMonomials: Polynomial must be expanded"];
      return 0;
    }
  else
    {
      return [carrier numMonomials];
    }
}

- (unsigned) size
{
  return ([self isRecursive]) ? [self numTerms] : [self numMonomials];
}


- removeTerm
{
  assert ([self check]);
  if ([self isExpanded])
    [self error:"-removeTerm: Polynomial must be Recursive"];

  if ([self notZero])
    {
      id lt = [carrier removeTerm];
      [self invalidate];
      assert ([self check] && lt != nil && [lt notZero]);
      return lt;
    }
  else
    {
      return nil;
    }
}

- insertTerm:aTerm
{
  id coef = [aTerm coefficient];
  if ([self isExpanded])
    [self error:"-insertTerm: Polynomial must be Recursive"];

  /* test the following here because how do i do [coef differentClass:self] at carrier level ? */

  if ([self isVariableSparse])
    {
      if ([coef differentClass:scalarZero] && [coef differentClass:self])
	{
	  return [self error:"insertTerm: polynomial and term incompatible"];
	}
    }
  else
    {
      if ([coef differentClass:[termZero coefficient]] || ([aTerm symbol] && [[aTerm symbol] notEqual:[[self symbols] lastElement]]))
	{
	  return [self error:"insertTerm: polynomial and term incompatible"];
	}
    }

  assert ([self check]);
  carrier = [carrier insertTerm:aTerm];
  [self invalidate];
  assert ([self check]);
  return self;
}

- removeMonomial
{
  assert ([self check]);
  if ([self isRecursive])
    {
      [self error:"-removeMonomial: Polynomial must be Expanded"];
    }

  if ([self notZero])
    {
      id lm = [carrier removeMonomial];
      [self invalidate];
      assert ([self check] && lm != nil && [lm notZero]);
      return lm;
    }
  else
    {
      return nil;
    }
}

- insertMonomial:aMonomial
{
  [aMonomial checkSameClass:monomialZero];

  if ([self isRecursive])
    [self error:"Polynomial must be Expanded"];
  if ([aMonomial isZero])
    {
      return self;
    }
  carrier = [carrier insertMonomial:aMonomial];
  return [self invalidate];
}

- removeLast
{
  return ([self isRecursive]) ? [self removeTerm] : [self removeMonomial];
}

- insertMember:aMember
{
  return ([self isRecursive]) ? [self insertTerm : aMember]:[self insertMonomial:aMember];
}


- eachTerm
{
  if ([self isRecursive])
    {
      return [carrier eachTerm];
    }
  else
    {
      return [self error:"-eachTerm: polynomial must be recursive"];
    }
}
- eachMonomial
{
  if ([self isExpanded])
    {
      return [carrier eachMonomial];
    }
  else
    {
      return [self error:"-eachMonomial: polynomial must be expanded"];
    }
}
- eachSequence
{
  return [carrier eachSequence];
}

- memberZero
{
  return ([self isRecursive]) ? termZero : monomialZero;
}

- eachElement
{
  return ([self isRecursive]) ? [self eachTerm] : [self eachMonomial];
}

- eachScalar
{
  id seq;

  if ([self isRecursive])
    {
      seq = [recpolscalar_sequence content:self];
    }
  else
    {
      seq = [exppolscalar_sequence content:self];
    }

  return [CASequence over:seq];
}

- eachCoefficient
{
  id seq;

  if ([self isExpanded])
    {
      [self error:"-termContent: polynomial must be recursive"];
    }
  if ([self isVariableSparse])
    {
      [self error:"-termContent: polynomial must be variable dense"];
    }

  seq = [recpolcoef_sequence content:self];
  return [CASequence over:seq];
}


- changeRepresentationTo:aPrototype
{
  id new, member, seq;
  new = [aPrototype empty];
  seq = [self eachElement];
  while ((member = [seq next]))
    {
      id add = [member changeRepresentationTo:aPrototype];
      new = [new add:add];
    }
  return new;
}

- makeDegreeDense
{
  if ([self isDegreeDense])
    {
      return self;
    }
  else
    {
      id new = [self emptyDegreeDense];

      if ([self isRecursive])
	{
	  id aTerm, aSequence = [self eachTerm];
	  while ((aTerm = [aSequence next]))
	    {
	      [new insertTerm:[aTerm makeDegreeDense]];
	    }
	}
      else
	{
	  id aMonomial, aSequence = [self eachMonomial];
	  while ((aMonomial = [aSequence next]))
	    {
	      [new insertMonomial:aMonomial];
	    }
	}

      return new;
    }
}

- makeDegreeSparse
{
  if ([self isDegreeSparse])
    {
      return self;
    }
  else
    {
      id new = [self emptyDegreeSparse];

      if ([self isRecursive])
	{
	  id aTerm, aSequence = [self eachTerm];
	  while ((aTerm = [aSequence next]))
	    {
	      [new insertTerm:[aTerm makeDegreeSparse]];
	    }
	}
      else
	{
	  id aMonomial, aSequence = [self eachMonomial];
	  while ((aMonomial = [aSequence next]))
	    {
	      [new insertMonomial:aMonomial];
	    }
	}

      return new;
    }
}

- makeRecursive
{
  if ([self isRecursive])
    {
      return self;
    }
  else
    {
      id res = [self emptyRecursive];
      return [self changeRepresentationTo:res];
    }
}

- makeExpanded
{
  if ([self isExpanded])
    {
      return self;
    }
  else
    {
      id res = [self emptyExpanded];
      return [self changeRepresentationTo:res];
    }
}

- makeVariableSparse
{
  if ([self isVariableSparse])
    {
      return self;
    }
  else
    {
      id new, member, seq;

      new = [self emptyVariableSparse];
      seq = [self eachElement];
      while ((member = [seq next]))
	{
	  [new insertMember:[member makeVariableSparse]];
	}
      return new;
    }
}

- makeVariableDense
{
  return ([self isVariableDense]) ? self : [self collect:[self symbols]];

}
- collect:symbols
{
  id mySymbols;

  if (symbols == nil || [symbols size] == 0)
    {
      [self error:"-collect: Collection must not be empty"];
    }

  mySymbols = [self symbols];

  if ([mySymbols size] <= [symbols size])
    {
      id res = [self emptyVariableDense:symbols];
      res = [self changeRepresentationTo:res];
      assert ([res isVariableDense] && [[res symbols] isEqual:symbols]);
      return res;
    }
  else
    {
      return [self error:"-collect: invoked with too few symbols.  Not yet implemented."];
    }
}


- leadingTerm
{
  if ([self isExpanded])
    [self error:"Polynomial must be Recursive"];

  if (_leadingTerm == nil && [self numTerms])
    {
      id sequence = [self eachTerm];
      _leadingTerm = [sequence firstElement];
    }

  return _leadingTerm;
}

- leadingCoefficient
{
  id lt = [self leadingTerm];
  return (lt) ? [lt coefficient] : nil;
}

- (int) leadingSign
{
  if ([self isRecursive])
    {
      id lc = [self leadingCoefficient];
      return (lc) ? [lc sign] : 0;
    }
  else
    {
      id ls = [self leadingScalar];
      return (ls) ? [ls sign] : 0;
    }
}

- leadingMonomial
{
  if ([self isRecursive])
    [self error:"Polynomial must be Expanded"];

  if ([self isExpanded])
    {
      if (_leadingMonomial == nil && [self numMonomials])
	{
	  id sequence = [self eachMonomial];
	  _leadingMonomial = [sequence firstElement];
	}
    }
  else
    {
      if (_leadingMonomial == nil && [self numTerms])
	{
	  id member, sequence = [self eachSequence];
	  member = [sequence firstElement];
	  while ([member isKindOfSequence])
	    member = [member firstElement];
	  _leadingMonomial = member;
	}
    }
  return _leadingMonomial;
}

- leadingScalar
{
  id lm = [self leadingMonomial];
  return (lm) ? [lm scalar] : nil;
}


- (BOOL) isMonic
{
  if ([self isZero])
    return NO;
  return ([self isRecursive]) ? [[self leadingCoefficient] isOne] : [[self leadingScalar] isOne];
}

- (BOOL) notMonic
{
  return [self isMonic] == NO;
}

- makeMonic
{
  if ([self isMonic])
    {
      return self;
    }
  else
    {
      if ([self isRecursive])
	{
	  return [self divideCoefficient:[self leadingCoefficient]];
	}
      else
	{
	  return [self divideScalar:[self leadingScalar]];
	}
    }
}


- zero
{
  if (_zero == nil)
    _zero = [self empty];
  return _zero;
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

- addScalar:s
{
  id res, tmp = [self scalar:s];
  res = [self add:tmp];
  return res;
}

- subtractScalar:s
{
  id res, tmp = [self scalar:s];
  res = [self subtract:tmp];
  return res;
}


- one
{
  if (_one == nil)
    {
      _one = [self empty];
      [_one insertMember:[[self memberZero] one]];
    }
  return _one;
}

- (BOOL) isOne
{
  return [carrier isOne];
}

- (BOOL) isMinusOne
{
  return [carrier isMinusOne];
}

- multiply:b
{
  id a;
  [self checkSameClass:b];

  if (self == b || [self isEqual:b])
    return [self square];
  if ([self isZero] || [b isZero])
    return [self zero];
  if ([b isOne])
    return self;
  if ([self isOne])
    return b;
  if ([b isMinusOne])
    return [self negate];
  if ([self isMinusOne])
    return [b negate];

  if ([self isRecursive])
    {
      id term;

      /* outer loop of mul iterates over polynomial with smallest num terms */
      if ([self numTerms] > [b numTerms])
	{
	  a = b;
	  b = self;
	}
      else
	{
	  a = self;
	}

      if ((term = [a asTerm]))
	{
	  id p = [b multiplyTerm:term];
	  return p;
	}
      else
	{
	  id p, seq;
	  assert ([b asTerm] == nil);
	  p = [a empty];
	  seq = [a eachTerm];
	  while ((term = [seq next]))
	    {
	      p = [p add:b multiplyTerm:term];
	    }
	  return p;
	}
    }
  else
    {
      id monomial;

      /* outer loop of mul iterates over polynomial with smallest num terms */
      if ([self numMonomials] > [b numMonomials])
	{
	  a = b;
	  b = self;
	}
      else
	{
	  a = self;
	}

      if ((monomial = [a asMonomial]))
	{
	  id p = [b multiplyMonomial:monomial];
	  return p;
	}
      else
	{
	  id p, seq;
	  assert ([b asMonomial] == nil);
	  p = [a empty];
	  seq = [a eachMonomial];
	  while ((monomial = [seq next]))
	    {
	      p = [p add:b multiplyMonomial:monomial];
	    }
	  return p;
	}
    }
}

- square
{
  if ([self isMinusOne])
    return [self one];
  if ([self isZero] || [self isOne])
    return self;

  if ([self isRecursive])
    {
      id t, t2, tsqr, c, d, a = [self copy];

      t = [a removeTerm];
      tsqr = [t square];
      c = [[self empty] insertTerm:tsqr];
      d = [[self empty] insertTerm:t];

      while ((t = [a removeTerm]))
	{
	  tsqr = [t square];
	  t2 = [t double];
	  c = [c add:d multiplyTerm:t2];
	  [c insertTerm:tsqr];
	  [d insertTerm:t];
	}

      return c;
    }
  else
    {
      id t, t2, tsqr, c, d, a = [self copy];

      t = [a removeMonomial];
      tsqr = [t square];
      c = [[self empty] insertMonomial:tsqr];
      d = [[self empty] insertMonomial:t];

      while ((t = [a removeMonomial]))
	{
	  tsqr = [t square];
	  t2 = [t double];
	  c = [c add:d multiplyMonomial:t2];
	  [c insertMonomial:tsqr];
	  [d insertMonomial:t];
	}

      return c;
    }
}

- inverse
{
  if ([self isZero])
    return nil;
  if ([self isOne] || [self isMinusOne])
    return self;
  if ([self isRecursive])
    {
      id term;
      if ((term = [self asTerm]))
	{
	  id inv = [term inverse];
	  if (inv && [inv exponent] >= 0)
	    {
	      return [[self empty] insertTerm:inv];
	    }
	  else
	    {
	      return nil;
	    }
	}
      else
	{
	  return nil;
	}
    }
  else
    {
      return [self notImplemented:_cmd];
    }
}

- power:(int)n
{
  id member;

  if ([self isZero] && n == 0)
    [self error:"-power: 0 power 0"];

  switch (n)
    {
      case 0:
      {
	return [self one];
      }
    case 1:
      {
	return self;
      }
    case 2:
      {
	return [self square];
      }
    }

  if ([self isOne])
    return self;
  if ([self isZero])
    {
      return self;
    }
  if ([self isMinusOne])
    {
      return ODD (n) ? self : [self one];
    }

  if ((member = [self asMember]))
    {
      id res = [[self empty] insertMember:[member power:n]];
      return res;
    }

  /* the problem currently is that makeVariableSparse invokes power:
   * so be sure to end the recursion, e.g. by handling asMember above
   */

  if ([self isVariableSparse])
    {
      id tmp = [self makeVariableDense];
      tmp = [tmp power:n];
      return [tmp makeVariableSparse];
    }
  else
    {
      return [super power:n];
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

- multiplyCoefficient:aCoefficient
{
  if ([self isExpanded])
    [self error:"-multiplyCoefficient: polynomial must be recursive"];
  if ([self isVariableSparse])
    [self error:"-multiplyCoefficient: polynomial must be variable dense"];

  if ([aCoefficient isZero])
    return [self zero];
  if ([aCoefficient isOne])
    return self;
  if ([aCoefficient isMinusOne])
    return [self negate];
  return [self over:[carrier multiplyCoefficient:aCoefficient]];
}

- divideCoefficient:aCoefficient
{
  id tmp;
  if ([self isExpanded])
    [self error:"-divideCoefficient: polynomial must be recursive"];
  if ([self isVariableSparse])
    [self error:"-divideCoefficient: polynomial must be variable dense"];

  if ([aCoefficient isZero])
    return nil;
  if ([aCoefficient isOne])
    return self;
  if ([aCoefficient isMinusOne])
    return [self negate];
  tmp = [carrier divideCoefficient:aCoefficient];
  return [self over:tmp];
}

- _add:(int)v:B multiplyCoefficient:b:(int)w
{
  assert ([self isVariableDense] && [self sameClass:B] && v * v == 1 && w * w == 1);

  if ([b isZero])
    return [self _negate:v];
  if ([b isOne])
    return [self _add:v:B:+w];
  if ([b isMinusOne])
    return [self _add:v:B:-w];

  return [self over:[carrier _add:v:[B carrier] multiplyCoefficient:b:w]];
}

- _multiplyCoefficient:a:(int)v add:B:(int)w
{
  assert ([self isVariableDense] && [self sameClass:B] && v * v == 1 && w * w == 1);

  if ([a isZero])
    return [B _negate:+w];
  if ([a isOne])
    return [self _add:+v:B:+w];
  if ([a isMinusOne])
    return [self _add:-v:B:+w];

  return [self over:[carrier _multiplyCoefficient:a:v add:[B carrier]:w]];
}

- _multiplyCoefficient:a:(int)v add:B multiplyCoefficient:b:(int)w
{
  assert ([self isVariableDense] && [self sameClass:B] && v * v == 1 && w * w == 1);

  if ([a isZero])
    return [B _multiplyCoefficient:b:+w];
  if ([b isZero])
    return [self _multiplyCoefficient:a:+v];
  if ([a isOne])
    return [self _add:+v:B multiplyCoefficient:b:+w];
  if ([b isOne])
    return [self _multiplyCoefficient:a:+v add:B:+w];
  if ([a isMinusOne])
    return [self _add:-v:B multiplyCoefficient:b:+w];
  if ([b isMinusOne])
    return [self _multiplyCoefficient:a:+v add:B:-w];

  return [self over:[carrier _multiplyCoefficient:a:v add:[B carrier] multiplyCoefficient:b:w]];
}

- multiplyTerm:aTerm
{
  if ([self isExpanded])
    [self error:"-multiplyTerm: polynomial must be recursive"];

  if ([self isVariableDense])
    {
      if ([aTerm isCoefficient])
	return [self multiplyCoefficient:[aTerm coefficient]];
    }
  else
    {
      if ([aTerm isCoefficient])
	return [self multiplyScalar:[aTerm coefficient]];
    }

  return [self over:[carrier multiplyTerm:aTerm]];
}

- divideTerm:aTerm
{
  id tmp;
  if ([self isExpanded])
    [self error:"-divideTerm: polynomial must be recursive"];

  if ([self isVariableDense])
    {
      if ([aTerm isCoefficient])
	return [self divideCoefficient:[aTerm coefficient]];
    }
  else
    {
      if ([aTerm isCoefficient])
	return [self divideScalar:[aTerm coefficient]];
    }

  return (tmp = [carrier divideTerm:aTerm]) ? [self over : tmp]:nil;
}

- _add:(int)v:B multiplyTerm:b:(int)w
{
  assert ([self sameClass:B] && v * v == 1 && w * w == 1);

  if ([B isZero])
    return [self _negate:v];

  if ([self isVariableDense])
    {
      if ([b isCoefficient])
	return [self _add:v:B multiplyCoefficient:[b coefficient]:w];
    }
  else
    {
      if ([b isCoefficient])
	return [self _add:v:B multiplyScalar:[b coefficient]:w];
    }

  return [self over:[carrier _add:v:[B carrier] multiplyTerm:b:w]];
}

- _multiplyCoefficient:a:(int)v add:B multiplyTerm:b:(int)w
{
  assert ([self isVariableDense] && [self sameClass:B] && v * v == 1 && w * w == 1);

  if ([B isZero])
    return [self _multiplyCoefficient:a:v];
  if ([a isZero])
    return [B _multiplyTerm:b:+w];
  if ([a isOne])
    return [self _add:+v:B multiplyTerm:b:w];
  if ([a isMinusOne])
    return [self _add:-v:B multiplyTerm:b:w];
  if ([b isCoefficient])
    return [self _multiplyCoefficient:a:v add:B multiplyCoefficient:[b coefficient]:w];

  return [self over:[carrier _multiplyCoefficient:a:v add:[B carrier] multiplyTerm:b:w]];
}

- multiplyMonomial:s
{
  if ([s isScalar])
    return [self multiplyScalar:[s scalar]];

  return [self over:[carrier multiplyMonomial:s]];
}

- divideMonomial:s
{
  id tmp;
  if ([s isScalar])
    return [self divideScalar:[s scalar]];

  if ((tmp = [carrier divideMonomial:s]))
    {
      return [self over:tmp];
    }
  else
    {
      return nil;
    }
}

- _add:(int)v:B multiplyMonomial:b:(int)w
{
  assert ([self sameClass:B] && v * v == 1 && w * w == 1);
  if ([b isScalar])
    return [self _add:v:B multiplyScalar:[b scalar]:w];
  return [self over:[carrier _add:v:[B carrier] multiplyMonomial:b:w]];
}

- _multiplyScalar:a:(int)v add:B multiplyMonomial:b:(int)w
{
  assert ([self sameClass:B] && v * v == 1 && w * w == 1);

  if ([a isZero])
    return [B _multiplyMonomial:b:+w];
  if ([a isOne])
    return [self _add:+v:B multiplyMonomial:b:w];
  if ([a isMinusOne])
    return [self _add:-v:B multiplyMonomial:b:w];
  if ([b isScalar])
    return [self _multiplyScalar:a:v add:B multiplyScalar:[b coefficient]:w];

  return [self over:[carrier _multiplyScalar:a:v add:[B carrier] multiplyMonomial:b:w]];
}


- remainder:b quotient:(id *)q
{
  id A, B;

  if ([b isZero])
    {
      if (q)
	*q = nil;
      return nil;
    }

  if (self == b)
    {
      if (q)
	*q = [self one];
      return [self zero];
    }
  if ([self isZero])
    {
      if (q)
	*q = self;
      return self;
    }
  if ([b isOne])
    {
      if (q)
	*q = self;
      return [self zero];
    }
  if ([b isMinusOne])
    {
      if (q)
	*q = [self negate];
      return [self zero];
    }

  if ((A = [self asScalar]))
    {
      if ((B = [b asScalar]))
	{
	  /* stes 9/97 for modular case */
	  if ([A inField])
	    {
	      id r = [self scalar:[A zero]];
	      if (q)
		*q = [self scalar:[A divide:B]];
	      return r;
	    }
	  else
	    {
	      id r = [A remainder:B quotient:q];
	      if (r)
		{
		  if (q)
		    *q = [self scalar:*q];
		  return [self scalar:r];
		}
	    }
	}
    }

  if ([self isRecursive])
    {
      if ([self isVariableSparse])
	{
	  id r, c, d, symbols = [[self symbols] union:[b symbols]];
	  assert ([symbols size]);
	  c = [self collect:symbols];
	  d = [b collect:symbols];
	  assert ([[c scalarZero] isEqual:[self scalarZero]]);
	  r = [c remainder:d quotient:q];
	  if (r)
	    {
	      r = [r makeVariableSparse];
	      if (q)
		*q = [*q makeVariableSparse];
	    }
	  return r;
	}
      else
	{
	  id r, t, c;
	  assert ([self isRecursive] && [self isVariableDense]);

	  if ([self degree] < [b degree])
	    {
	      if (q)
		*q = [self zero];
	      return self;
	    }

	  c = [b copy];
	  t = [c removeTerm];

	  /* note c might be zero, which is ok.
	   * handling the special case r == 0 apart gives a lot of garbage
	   * routines and divideScalar/divideTerm etc. should be implemented
	   * separately anyway quotientScalar/quotientTerm don't occur often
	   * and may be handled here
	   */

	  r = [self remainderReductum:c term:t quotient:q];
	  return r;
	}
    }
  else
    {
      id r, m, c;
      c = [b copy];
      m = [c removeMonomial];	/* c might be zero, that's ok */
      r = [self remainderReductum:c monomial:m quotient:q];
      return r;
    }
}

- divide:b
{
  id r, q;
  [self checkSameClass:b];

  if ([b isZero])
    return nil;
  if ([self isZero])
    return [self zero];
  if (self == b)
    return [self one];
  if ([b isOne])
    return self;
  if ([b isMinusOne])
    return [self negate];

  if ([self isEqual:b])
    return [self one];
  if ([self isOpposite:b])
    return [self minusOne];

  if ([self isRecursive] && (r = [b asTerm]))
    {
      q = [self divideTerm:r];
      return q;
    }

  if ([self isExpanded] && (r = [b asMonomial]))
    {
      q = [self divideMonomial:r];
      return q;
    }

  r = [self remainder:b quotient:&q];
  if (r)
    {
      if ([r isZero])
	{
	  return q;
	}
      else
	{
	  return nil;
	}
    }
  else
    {
      assert (q == nil);
      return nil;
    }
}

- remainderReductum:r term:t quotient:(id *)q
{
  id c, s, inv;

  assert ([self isRecursive] && [r sameClass:self] && [t sameClass:termZero]);

  s = [t coefficient];
  if ([s isOne])
    return [self remainderReductum:r monicTerm:t quotient:q];

  if ((inv = [s inverse]))
    {
      c = [self remainderReductum:r term:t inverse:inv quotient:q];
    }
  else
    {
      c = [self remainderReductum:r term:t coefficient:s quotient:q];
    }

  return c;
}

- remainderReductum:r monicTerm:t quotient:(id *)q
{
  id a, lt;
  assert ([[t coefficient] isOne]);
  a = [self copy];
  if (q)
    *q = [self empty];

  while ((lt = [a removeTerm]))
    {
      id ltq = [lt subtractExponents:t];
      if (ltq)
	{
	  a = [a subtract:r multiplyTerm:ltq];
	  a = [a copy];
	  if (q)
	    [*q insertTerm:ltq];
	}
      else
	{
	  [a insertTerm:lt];
	  break;
	}
    }

  return a;
}

- remainderReductum:r term:t inverse:s quotient:(id *)q
{
  id a, lt;
  a = [self copy];
  if (q)
    *q = [self empty];

  while ((lt = [a removeTerm]))
    {
      id ltq = [lt subtractExponents:t];
      if (ltq)
	{
	  ltq = [ltq multiplyCoefficient:s];
	  a = [a subtract:r multiplyTerm:ltq];
	  a = [a copy];
	  if (q)
	    [*q insertTerm:ltq];
	}
      else
	{
	  [a insertTerm:lt];
	  break;
	}
    }

  return a;
}

- remainderReductum:r term:t coefficient:s quotient:(id *)q
{
  id a, lt;
  a = [self copy];
  if (q)
    *q = [self empty];

  while ((lt = [a removeTerm]))
    {
      id ltq = [lt subtractExponents:t];
      if (ltq)
	{
	  id ltqc = [ltq divideCoefficient:s];
	  if (ltqc)
	    {
	      a = [a subtract:r multiplyTerm:ltqc];
	      a = [a copy];
	      if (q)
		[*q insertTerm:ltqc];
	    }
	  else
	    {
	      /* return nil and set *q to nil */
	      if (q)
		*q = nil;
	      return nil;
	    }
	}
      else
	{
	  [a insertTerm:lt];
	  break;
	}
    }

  return a;
}

- remainderReductum:r monomial:t quotient:(id *)q
{
  id c, s, inv;

  assert ([self isExpanded] && [r sameClass:self] && [t sameClass:monomialZero]);

  s = [t scalar];
  if ([s isOne])
    return [self remainderReductum:r monicMonomial:t quotient:q];

  if ((inv = [s inverse]))
    {
      c = [self remainderReductum:r monomial:t inverse:inv quotient:q];
    }
  else
    {
      c = [self remainderReductum:r monomial:t scalar:s quotient:q];
    }

  return c;
}

- remainderReductum:r monicMonomial:t quotient:(id *)q
{
  id a, lt;
  assert ([[t scalar] isOne]);
  a = [self copy];
  if (q)
    *q = [self empty];

  while ((lt = [a removeMonomial]))
    {
      id ltq = [lt divideTerms:t];
      if (ltq)
	{
	  a = [a subtract:r multiplyMonomial:ltq];
	  a = [a copy];
	  if (q)
	    [*q insertMonomial:ltq];
	}
      else
	{
	  [a insertMonomial:lt];
	  break;
	}
    }

  return a;
}

- remainderReductum:r monomial:t inverse:s quotient:(id *)q
{
  id a, lt;
  a = [self copy];
  if (q)
    *q = [self empty];

  while ((lt = [a removeMonomial]))
    {
      id ltq = [lt divideTerms:t];
      if (ltq)
	{
	  ltq = [ltq multiplyScalar:s];
	  a = [a subtract:r multiplyMonomial:ltq];
	  a = [a copy];
	  if (q)
	    [*q insertMonomial:ltq];
	}
      else
	{
	  [a insertMonomial:lt];
	  break;
	}
    }

  return a;
}

- remainderReductum:r monomial:t scalar:s quotient:(id *)q
{
  id a, lt;
  a = [self copy];
  if (q)
    *q = [self empty];

  while ((lt = [a removeMonomial]))
    {
      id ltq = [lt divideTerms:t];
      if (ltq)
	{
	  id ltqs = [ltq divideScalar:s];
	  if (ltqs)
	    {
	      a = [a subtract:r multiplyMonomial:ltqs];
	      a = [a copy];
	      if (q)
		[*q insertMonomial:ltqs];
	    }
	  else
	    {
	      /* return nil and set *q to nil */
	      if (q)
		*q = nil;
	      return nil;
	    }
	}
      else
	{
	  [a insertMonomial:lt];
	  break;
	}
    }

  return a;
}


- pseudoRemainder:b quotient:(id *)q
{
  if ([b isZero])
    return nil;

  if (self == b)
    {
      if (q)
	*q = [self one];
      return [self zero];
    }
  if ([self isZero])
    {
      if (q)
	*q = self;
      return self;
    }
  if ([b isOne])
    {
      if (q)
	*q = self;
      return [self zero];
    }

  if ([self isExpanded])
    {
      id r, c, d;
      c = [self makeRecursive];
      d = [b makeRecursive];
      r = [c pseudoRemainder:d quotient:q];
      if (r)
	{
	  r = [r makeExpanded];
	  if (q)
	    *q = [*q makeExpanded];
	}
      return r;
    }
  else if ([self isVariableSparse])
    {
      id r, c, d, symbols = [[self symbols] union:[b symbols]];
      c = [self collect:symbols];
      d = [b collect:symbols];
      r = [c pseudoRemainder:d quotient:q];
      if (r)
	{
	  r = [r makeVariableSparse];
	  if (q)
	    *q = [*q makeVariableSparse];
	}
      return r;
    }
  else
    {
      id r, t, c;
      assert ([self isRecursive] && [self isVariableDense]);
      if ([self degree] < [b degree])
	{
	  if (q)
	    *q = [self zero];
	  return self;
	}

      r = [b copy];
      t = [r removeTerm];	/* note r might be zero, which is ok. don't handle that case separately */
      c = [self pseudoRemainderReductum:r term:t quotient:q];

      return c;
    }
}

- pseudoRemainder:b
{
  return [self pseudoRemainder:b quotient:NULL];
}

- pseudoRemainderReductum:r term:t quotient:(id *)q
{
  id c, s;
  int spcount, d;

  assert ([r sameClass:self] && [t sameClass:termZero]);
  s = [t coefficient];
  if ([s isOne])
    return [self remainderReductum:r monicTerm:t quotient:q];

  d = [self degree] - [t degree] + 1;
  c = [self pseudoRemainderReductum:r term:t coefficient:s quotient:q sparsityCount:&spcount];

  switch (d = d - spcount)
    {
      case 0:
      {
	break;
      }
    case 1:
      {
	if (q)
	  *q = [*q multiplyCoefficient:c];
	c = [c multiplyCoefficient:s];
	break;
      }
    default:
      {
	id e = [s power:d];
	if (q)
	  *q = [*q multiplyCoefficient:e];
	c = [c multiplyCoefficient:e];
	break;
      }
    }

  return c;
}

- pseudoRemainderReductum:r term:t coefficient:s quotient:(id *)q sparsityCount:(int *)cref
{
  id lt, a;
  int count = 0;
  a = [self copy];
  if (q)
    *q = [self empty];

  while ((lt = [a removeTerm]))
    {
      id ltq = [lt subtractExponents:t];
      if (ltq)
	{
	  lt = ltq;
	}
      else
	{
	  [a insertTerm:lt];
	  break;
	}
      a = [a multiplyCoefficient:s subtract:r multiplyTerm:lt];
      count++;
      if (q)
	{
	  *q = [*q multiplyCoefficient:s];
	  [*q insertTerm:lt];
	}
    }

  *cref = count;
  return a;
}


- content
{
  id content, aSequence = [self eachScalar];
  content = [aSequence content];
  assert (content == nil || [content sameClass:scalarZero]);
  return content;
}

- divideContent
{
  if ([self isZero])
    {
      return [self zero];
    }
  else
    {
      id content = [self content];
      return [self divideScalar:content];
    }
}

- coefficientContent
{
  id content, aSequence;

  if ([self isExpanded])
    {
      [self error:"-coefficientContent: polynomial must be recursive"];
    }
  if ([self isVariableSparse])
    {
      [self error:"-coefficientContent: polynomial must be variable dense"];
    }

  assert ([self check]);
  aSequence = [self eachCoefficient];
  content = [aSequence content];
  assert (content == nil || [content sameClass:[termZero coefficient]]);
  return content;
}

- divideCoefficientContent
{
  if ([self isZero])
    {
      return [self zero];
    }
  else
    {
      id content = [self coefficientContent];
      return [self divideCoefficient:content];
    }
}

- termContent
{
  id c, s;
  int e;

  if ([self isExpanded])
    {
      [self error:"-termContent: polynomial must be recursive"];
    }
  if ([self isVariableSparse])
    {
      [self error:"-termContent: polynomial must be variable dense"];
    }

  e = [self order];
  c = [[termZero coefficient] one];
  s = (e) ? [termZero symbol] : nil;
  return [termZero coefficient:c symbol:nil exponent:0];
}
- monomialContent
{
  id content, aSequence;

  if ([self isRecursive])
    {
      [self error:"-monomialContent: polynomial must be expanded"];
    }

  assert ([self check]);
  aSequence = [self eachMonomial];
  content = [aSequence content];
  assert (content == nil || [content sameClass:[termZero coefficient]]);
  return content;
}


- doImprovedSubresultant:(id *)pref:(id *)qref
{
  int delta;
  id p = *pref;
  id q = *qref;
  id r, rd, c, cd, f, t;

  assert ([p sameClass:q] && [p isVariableDense] && [p isRecursive]);

  delta = [p degree] - [q degree];
  if (delta < 0)
    {
      delta = -delta;
      t = p;
      p = q;
      q = t;
    }
  r = [[termZero coefficient] one];
  rd = r;
  c = r;

  do
    {
      f = [c multiply:rd];
      if (EVEN (delta))
	f = [f negate];
      p = [[p pseudoRemainder:q] divideCoefficient:f];

      t = p;
      p = q;
      q = t;
      if ([q degree] <= 0)
	break;
      c = [p leadingCoefficient];
      cd = [c power:delta];
      r = [[r multiply:cd] divide:rd];
      delta = [p degree] - [q degree];
      rd = [r power:delta];
    }
  while (1);

  *pref = p;
  *qref = q;
  return self;
}

/******************************************************************************
 *
 * Gcd
 *
 *****************************************************************************/

- fieldGcd:b
{
  id a = self;
  if ([a isZero])
    return b;
  if ([b isZero])
    return a;
  if (a == b)
    return [a makeMonic];

  while ([b notZero])
    {
      id c;
      a = [a remainder:b];
      c = a;
      a = b;
      b = c;
    }
  return [a makeMonic];
}

- idomGcd:b
{
  id ac, bc, gc, g, a = self;
  if ([a isZero])
    return b;
  if ([b isZero])
    return a;
  if (a == b || [a isEqual:b])
    return [a divideCoefficientContent];

  ac = [a coefficientContent];
  bc = [b coefficientContent];
  gc = [ac gcd:bc];
  a = [a divideCoefficient:ac];
  b = [b divideCoefficient:bc];

  [self doImprovedSubresultant:&a:&b];

  g = ([b isZero]) ? [a divideCoefficientContent] : [a one];
  g = [g multiplyCoefficient:gc];

  return g;
}

- gcd:b
{
  id A, B;

  if ([scalarZero isFloatingPoint])
    [self error:"No Gcd over Floating Points"];

  if ([self isZero])
    return b;
  if ([b isZero])
    return self;
  if ((A = [self asScalar]))
    {
      if ((B = [b asScalar]))
	{
	  id r = ([scalarZero inField]) ? [scalarZero one] : [A gcd:B];
	  return [self scalar:r];
	}
    }

  if ([self isExpanded])
    {
      id g, c, d;
      c = [self makeRecursive];
      d = [b makeRecursive];
      g = [c gcd:d];
      return (g) ? [g makeExpanded] : nil;
    }
  else if ([self isVariableSparse])
    {
      id g, c, d, symbols = [[self symbols] union:[b symbols]];
      c = [self collect:symbols];
      d = [b collect:symbols];
      assert ([[c scalarZero] isEqual:[self scalarZero]]);
      g = [c gcd:d];
      return (g) ? [g makeVariableSparse] : nil;
    }
  else
    {
      id coefficientZero = [termZero coefficient];
      if ([coefficientZero inField])
	return [self fieldGcd:b];
      if ([coefficientZero inIntegralDomain])
	return [self idomGcd:b];
      return [self notImplemented:_cmd];
    }
}

/******************************************************************************
 *
 * Resultant
 *
 *****************************************************************************/

- resultant:b
{
  id resultant, p, q;

  if ([self isExpanded] || [self isVariableSparse])
    {
      [self error:"-resultant: polynomials must be variable dense and recursive"];
    }

  p = self;
  q = b;
  [self doImprovedSubresultant:&p:&q];
  if ([q isZero])
    {
      resultant = [[termZero coefficient] zero];
    }
  else
    {
      resultant = [q asCoefficient];
    }
  return resultant;
}

- resultant:b wrt:(STR)aSymbol
{
  return [self error:"sorry, use resultant !"];
}

- discriminant
{
  id disc, dself;
  dself = [self derive];
  disc = [self resultant:dself];
  return disc;
}

- signedPseudoRemainder:B
{
  id C;
  int d;

  d = [self degree] - [B degree] + 1;
  C = [self pseudoRemainder:B];
  return (ODD (d) && [B leadingSign] == -1) ? [C negate] : C;
}

static int 
sgn_delta (int i)
{
  return ODD ((i * (i - 1)) / 2);
}

static int *
sgnlist_alloc (int count)
{
  return (int *) OC_Malloc (count * sizeof (int));
}

static void 
sgnlist_free (int *self)
{
  OC_Free (self);
}

static int 
sgnlist_var (int *self, int count)
{
  int i;
  int si = 0;
  int sj = 0;
  int var = 0;

  for (i = 0; i < count; i++)
    {
      si = self [i];
      assert (si == 0 || si == -1 || si == +1);
      if (si)
	break;
    }
  if (i == count)
    return var;

  while (1)
    {
      for (i++; i < count; i++)
	{
	  sj = self [i];
	  assert (sj == 0 || sj == -1 || sj == +1);
	  if (sj)
	    break;
	}
      if (i == count)
	return var;
      if (si != sj)
	{
	  si = sj;
	  var++;
	}
    }
}

static void 
sgnlist_add (int *plus, int *minus, id polynomial, int count)
{
  int sign = [polynomial leadingSign];
  assert (sign == +1 || sign == 0 || sign == -1);
  plus [count] = sign;
  minus [count] = ODD ([polynomial degree]) ? -sign : sign;
}

- (int) signedPseudoRemainderList:g plus:(int*)plus minus:(int*)minus
{
  int delta, count;
  id r, rd, c, cd, f, t;
  id p = [self copy];
  id q = [g copy];

  assert (plus && minus && [q degree] <= [p degree]);
  assert ([p sameClass:q] && [p isVariableDense] && [p isRecursive]);

  delta = [p degree] - [q degree];
  count = 0;
  r = [[termZero coefficient] one];
  rd = r;
  c = r;
  sgnlist_add (plus, minus, p, count++);
  sgnlist_add (plus, minus, q, count++);

  do
    {
      f = [[c multiply:rd] absValue];
      p = [[p signedPseudoRemainder:q] divideCoefficient:f];
      sgnlist_add (plus, minus, p, count++);

      t = p;
      p = q;
      q = t;
      if ([q degree] <= 0)
	break;
      c = [p leadingCoefficient];
      cd = [c power:delta];
      r = [[r multiply:cd] divide:rd];
      delta = [p degree] - [q degree];
      rd = [r power:delta];
    }
  while (1);

  return count;
}

- (int) vRealRoots:g
{
  int i, v, count, *plus, *minus;

  count = [self degree] + 2;
  plus = sgnlist_alloc (count);
  minus = sgnlist_alloc (count);
  count = [self signedPseudoRemainderList:g plus:plus minus:minus];
  assert (count <= [self degree] + 2);

  for (i = 0; i < count; i++)
    if (sgn_delta (i))
      {
	plus [i] *= -1;
	minus [i] *= -1;
      }

  v = sgnlist_var (minus, count) - sgnlist_var (plus, count);
  sgnlist_free (plus);
  sgnlist_free (minus);
  return v;
}

- (int) numRealRoots
{
  int v;

  if ([scalarZero isFloatingPoint])
    [self error:"-numRealRoots: scalars may not be floating-point"];

  if ([self isVariableSparse])
    {
      id t = [self makeVariableDense];
      v = [t numRealRoots];
      return v;
    }
  else
    {
      id dself = [self derive];
      v = [self vRealRoots:dself];
      return v;
    }
}

- (int) varRealRoots:g
{
  int v;
  /* i'm not sure about the signedPseudoRemainder here ! compensate sign ?
   * use pseudoRemainder ?
   */
  id q = [g signedPseudoRemainder:self];

  if ([scalarZero isFloatingPoint])
    [self error:"-varRealRoots: scalars may not be floating-point"];

  v = [self vRealRoots:q];
  return v;
}



- factor
{
  return [self notImplemented:_cmd];
}

- (BOOL) isSquareFree
{
  BOOL sqrfree;
  id dself = [self derive];
  sqrfree = [self isCoprime:dself];
  return sqrfree;
}

- factorSymbol:aSymbol exponent:(int)anExponent
{
  return [Term scalar:[scalarZero one] symbol:aSymbol exponent:anExponent];
}

- factorSquareFreeDerivative:dself gcd:gcd
{
  int i;
  id factors;
  id A, B, dB, C;

  factors = [CACollection new];
  if ([dself isZero])
    return factors;

  B = [self divide:gcd];
  assert (B);
  C = [dself divide:gcd];
  assert (C);

  for (i = 1; 1; i++)
    {
      dB = [B derive];
      C = [C subtract:dB];
      if ([C isZero])
	break;
      A = [B gcd:C];
      if ([A notOne])
	{
	  B = [B divide:A];
	  assert (B);
	  C = [C divide:A];
	  assert (C);
	  [factors add:[self factorSymbol:A exponent:i]];
	}
    }

  assert ([C isZero] && [B notOne]);
  [factors add:[self factorSymbol:B exponent:i]];
  return factors;
}

- factorSquareFreeDerivative:dself gcd:gcd characteristic:(unsigned)p
{
  int j, k;
  id ourGcd, factor, factors;

  factors = [self factorSquareFreeDerivative:dself gcd:gcd];

  /* check whether the decomposition is complete */
  j = [factors size];
  ourGcd = [gcd copy];
  while (j--)
    {
      id fj = [[factors at:j] symbol];
      int ej = [[factors at:j] exponent];
      while (--ej)
	ourGcd = [ourGcd divide:fj];
    }

  if ([ourGcd isUnit])
    {
      return factors;
    }
  else
    {
      id U, V;

      ourGcd = [ourGcd frobeniusInverse];
      V = [ourGcd factorSquareFree];
      U = factors;
      factors = [CACollection new];

      k = [V size];
      while (k--)
	{
	  id Vk = [[V at:k] symbol];
	  int ek = [[V at:k] exponent];

	  j = [U size];
	  while (j--)
	    {
	      int ej;
	      id gcdjk, Uj;

	      Uj = [[U at:j] symbol];
	      ej = [[U at:j] exponent];

	      if ([Uj isOne])
		continue;

	      gcdjk = [Uj gcd:Vk];
	      if ([gcdjk notOne])
		{
		  Vk = [Vk divide:gcdjk];
		  [factors add:[self factorSymbol:gcdjk exponent:ej + p * ek]];

		  /* it would be better to construct a new list */
		  factor = [self factorSymbol:[Uj divide:gcdjk] exponent:ej];
		  [U at:j put:factor];
		}

	      if ([Vk isOne])
		break;
	    }

	  if ([Vk notOne])
	    {
	      [factors add:[self factorSymbol:Vk exponent:p * ek]];
	    }

	  factor = [self factorSymbol:Vk exponent:ek];
	  [V at:k put:factor];
	}

      j = [U size];
      while (j--)
	{
	  id Uj = [[U at:j] symbol];
	  int ej = [[U at:j] exponent];
	  if ([Uj notOne])
	    {
	      [factors add:[self factorSymbol:Uj exponent:ej]];
	    }
	}

    }
  return factors;
}

- factorSquareFree
{
  if ([scalarZero isFloatingPoint])
    [self error:"No Factorization over Floats"];

  if ([self isExpanded])
    {
      id c, factors;
      c = [self makeRecursive];
      factors = [c factorSquareFree];
      return factors;
    }
  else if ([self isVariableSparse])
    {
      id c, factors;
      c = [self makeVariableDense];
      factors = [c factorSquareFree];
      return factors;
    }
  else
    {
      unsigned p;
      id dself, gcd, factors;
      assert ([self isRecursive] && [self isVariableDense]);

      dself = [self derive];
      gcd = [self gcd:dself];
      p = [scalarZero characteristic];

      if (p)
	{
	  factors = [self factorSquareFreeDerivative:dself gcd:gcd characteristic:p];
	}
      else
	{
	  factors = [self factorSquareFreeDerivative:dself gcd:gcd];
	}

      return factors;
    }
}

- truncateAtDegree:(int)d
{
  id result, aMember, aSequence;

  result = [self empty];
  aSequence = [self eachElement];

  while ((aMember = [aSequence next]))
    {
      if ([aMember degree] <= d)
	[result insertMember:aMember];
    }

  return result;
}


- frobenius
{
  id result, aMember, aSequence;

  result = [self empty];
  aSequence = [self eachElement];

  while ((aMember = [aSequence next]))
    {
      if ((aMember = [aMember frobenius]))
	{
	  [result insertMember:aMember];
	}
      else
	{
	  return nil;
	}
    }

  return result;
}

- frobeniusInverse
{
  id result, aMember, aSequence;

  result = [self empty];
  aSequence = [self eachElement];

  while ((aMember = [aSequence next]))
    {
      if ((aMember = [aMember frobeniusInverse]))
	{
	  [result insertMember:aMember];
	}
      else
	{
	  return nil;
	}
    }

  return result;
}


- evaluate:aScalar
{
  return [self notImplemented:_cmd];
}

- evaluate:(STR)aSymbol at:aScalar
{
  return [self notImplemented:_cmd];
}

- evaluateAll:cltnOfScalars
{
  if ([self isZero])
    return scalarZero;

  if ([self isExpanded])
    {
      id c, d;
      c = [self makeRecursive];
      d = [c evaluateAll:cltnOfScalars];
      assert ([d sameClass:scalarZero]);
      return d;
    }
  else if ([self isVariableSparse])
    {
      id c, d;
      c = [self makeVariableDense];
      d = [c evaluateAll:cltnOfScalars];
      assert ([d sameClass:scalarZero]);
      return d;
    }
  else
    {
      id x, xn, px, term, terms;
      int f, e, n = [[self symbols] size];
      assert ([self isRecursive] && [self isVariableDense]);

      if ([cltnOfScalars size] < n)
	{
	  [self error:"-evaluateAll: not enough scalars in collection"];
	}

      x = [cltnOfScalars at:n - 1];
      if ([x differentClass:scalarZero])
	[self error:"-evaluateAll: objects in collection must be scalars"];

      terms = [self eachTerm];
      term = [terms firstElement];
      f = [term degree];
      px = (n == 1) ? [term coefficient] : [[term coefficient] evaluateAll:cltnOfScalars];
      while ((term = [terms next]))
	{
	  e = [term degree];
	  xn = [x power:f - e];
	  if (n == 1)
	    {
	      px = [px _multiply:xn:+1 add:[term coefficient]:+1];
	    }
	  else
	    {
	      id c = [[term coefficient] evaluateAll:cltnOfScalars];
	      px = [px _multiply:xn:+1 add:c:+1];
	    }
	  f = e;
	}

      xn = [x power:f];
      px = [px multiply:xn];

      assert ([px sameClass:scalarZero]);
      return px;
    }
}

- (float) floatEvaluate:(float)floatValue
{
  id x, y;
  if ([scalarZero isFloatingPoint] == NO)
    [self error:"-floatEvaluateAll: scalars must be floating-point"];

  x = [scalarZero floatValue:floatValue];
  y = [self evaluate:x];
  floatValue = [y floatValue];
  return floatValue;
}

- (float) floatEvaluateAll:(float *)floatValues
{
  float res;
  id scalar, scalars = [CACollection new];
  int i, n = [[self symbols] size];
  if ([scalarZero isFloatingPoint] == NO)
    [self error:"-floatEvaluateAll: scalars must be floating-point"];

  for (i = 0; i < n; i++)
    [scalars add:[scalarZero floatValue:floatValues [i]]];
  scalar = [self evaluateAll:scalars];
  res = [scalar floatValue];

  return res;
}

- substitute:aPolynomial
{
  int e, f;
  id xn, px;
  id terms, term;

  if ([self isZero])
    return [self zero];

  terms = [self eachTerm];
  term = [terms firstElement];
  f = [term exponent];
  px = [term coefficient];
  while ((term = [terms next]))
    {
      e = [term exponent];
      xn = [aPolynomial power:f - e];
      px = [px _multiply:xn:+1 add:[term coefficient]:+1];
      f = e;
    }

  xn = [aPolynomial power:f];
  px = [px multiply:xn];

  return px;
}

- substitute:(STR)aSymbol by:aPolynomial
{
  assert ([aPolynomial sameClass:self]);

  if ([self isVariableSparse])
    {
      id res, term, terms, variableAsTerm;

      res = [self empty];
      terms = [self eachTerm];
      variableAsTerm = [termZero str:aSymbol];
      if (!variableAsTerm)
	{
	  [self error:"-substitute:by: argument must be a variable"];
	}

      while ((term = [terms next]))
	{
	  int cmp = [term compareSymbols:variableAsTerm];
	  if (cmp == 0)
	    {
	      id power = [aPolynomial power:[term exponent]];
	      res = [res _add:+1:power multiplyCoefficient:[term coefficient]:+1];
	    }
	  else
	    {
	      if (cmp > 0)
		{
		  [res insertTerm:[term substitute:aSymbol by:aPolynomial]];
		}
	      else
		{
		  [res insertTerm:term];
		}
	    }
	}

      return res;
    }
  else
    {
      return [self notImplemented:_cmd];
    }
}

- substituteAll:cltnOfPolynomials
{
  return [self notImplemented:_cmd];
}


- derive
{
  if ([self isVariableSparse])
    {
      return [self error:"-derive: polynomial must be variable dense"];
      /* return [self derive:[[self variables] lastElement]]; */
    }
  else
    {
      id result, aMember, aSequence;

      if ([self degree] < 1)
	return [self zero];

      result = [self empty];
      aSequence = [self eachElement];

      while ((aMember = [aSequence next]))
	{
	  if ((aMember = [aMember derive]))
	    {
	      [result insertMember:aMember];
	    }
	  else
	    {
	      return nil;
	    }
	}

      return result;
    }
}

- deriveWrt:(STR)aSymbol
{
  return [self notImplemented:_cmd];
}

- integrate
{
  if ([self isVariableSparse])
    {
      return [self error:"-integrate: polynomial must be variable dense"];
      /* return [self integrate:[[self variables] lastElement]]; */
    }
  else
    {
      return [self notImplemented:_cmd];
    }
}

- integrateWrt:(STR)aSymbol
{
  return [self notImplemented:_cmd];
}


- (BOOL) printsLeadingSign
{
  assert ([self check]);

  if ([self isZero])
    {
      return NO;
    }
  else
    {
      if ([self isExpanded])
	{
	  return [[self leadingMonomial] printsLeadingSign];
	}
      else
	{
	  return [[self leadingTerm] printsLeadingSign];
	}
    }
}

- (BOOL) printsSum
{
  assert ([self check]);

  if ([self isZero])
    {
      return NO;
    }
  else
    {
      if ([self isExpanded])
	{
	  return [self numMonomials] > 1;
	}
      else
	{
	  if ([self numTerms] > 1)
	    return YES;
	  return [self numTerms] == 1 && [[self leadingTerm] printsSum];
	}
    }
}

- (BOOL) printsProduct
{
  assert ([self check]);

  if ([self isZero])
    {
      return NO;
    }
  else
    {
      if ([self isExpanded])
	{
	  return [self numMonomials] == 1;
	}
      else
	{
	  return [self numTerms] == 1 && [[self leadingTerm] printsProduct];
	}
    }
}

- printOn:(IOD)aFile
{
  assert ([self check]);

  if ([self isZero])
    {
      fprintf (aFile, "0");
    }
  else
    {
      id aMember, aSequence = [self eachElement];
      aMember = [aSequence firstElement];
      assert ([aMember notZero]);
      [aMember printOn:aFile];
      while ((aMember = [aSequence next]))
	{
	  if ([aMember isZero])
	    continue;
	  if ([aMember printsLeadingSign])
	    {
	      id opposite = [aMember negate];
	      assert ([opposite printsLeadingSign] == NO);
	      fprintf (aFile, " - ");
	      if ([opposite printsSum])
		{
		  fprintf (aFile, "(");
		  [opposite printOn:aFile];
		  fprintf (aFile, ")");
		}
	      else
		{
		  [opposite printOn:aFile];
		}
	    }
	  else
	    {
	      fprintf (aFile, " + ");
	      [aMember printOn:aFile];
	    }
	}
    }

  return self;
}

@end
 
