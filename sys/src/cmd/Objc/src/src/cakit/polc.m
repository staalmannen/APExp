
/*
 * Computer Algebra Kit (c) 1993,2000,14 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: polc.m,v 1.8 2014/03/04 09:38:34 stes Exp $
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

@implementation polynomialc
- empty
{
  [self subclassResponsibility:_cmd];
  return self;
}

- (BOOL) isEmpty
{
  [self subclassResponsibility:_cmd];
  return NO;
}

- (BOOL)isVariableDense 
{
  [self subclassResponsibility:_cmd];
  return NO;
}
- (BOOL)isVariableSparse 
{
  [self subclassResponsibility:_cmd];
  return NO;
}
- (BOOL)isRecursive 
{
  [self subclassResponsibility:_cmd];
  return NO;
}
- (BOOL)isExpanded 
{
  [self subclassResponsibility:_cmd];
  return NO;
}
- (BOOL)isDegreeDense 
{
  [self subclassResponsibility:_cmd];
  return NO;
}
- (BOOL)isDegreeSparse 
{
  [self subclassResponsibility:_cmd];
  return NO;
}

- (int)numTerms
{
  if ([self isRecursive])
    {
      [self subclassResponsibility:_cmd];
      return 0;
    }
  else
    {
      [self doesNotRecognize:_cmd];
      return 0;
    }
}

- eachTerm
{
  if ([self isRecursive])
    {
      [self subclassResponsibility:_cmd];
      return self;
    }
  else
    {
      [self doesNotRecognize:_cmd];
      return self;
    }
}

- removeTerm
{
  if ([self isRecursive])
    {
      [self subclassResponsibility:_cmd];
      return self;
    }
  else
    {
      [self doesNotRecognize:_cmd];
      return self;
    }
}

- insertTerm:aTerm
{
  if ([self isRecursive])
    {
      [self subclassResponsibility:_cmd];
      return self;
    }
  else
    {
      [self doesNotRecognize:_cmd];
      return self;
    }
}

- (int)numMonomials
{
  if ([self isExpanded])
    {
      [self subclassResponsibility:_cmd];
      return 0;
    }
  else
    {
      [self doesNotRecognize:_cmd];
      return 0;
    }
}

- eachMonomial
{
  if ([self isExpanded])
    {
      [self subclassResponsibility:_cmd];
      return self;
    }
  else
    {
      [self doesNotRecognize:_cmd];
      return self;
    }
}

- removeMonomial
{
  if ([self isExpanded])
    {
      [self subclassResponsibility:_cmd];
      return self;
    }
  else
    {
      [self doesNotRecognize:_cmd];
      return self;
    }
}

- insertMonomial:aMonomial
{
  if ([self isExpanded])
    {
      [self subclassResponsibility:_cmd];
      return self;
    }
  else
    {
      [self doesNotRecognize:_cmd];
      return self;
    }
}

- (int) leadingDegree
{
  if ([self isEmpty])
    {
      return -1;
    }
  else
    {
      int deg;
      id seq = [self eachElement];
      deg = [[seq firstElement] degree];
      return deg;
    }
}

- (int) lastDegree
{
  if ([self isEmpty])
    {
      return -1;
    }
  else
    {
      int deg;
      id seq = [self eachElement];
      deg = [[seq lastElement] degree];
      return deg;
    }
}

- (int) maxDegree
{
  if ([self isEmpty])
    {
      return -1;
    }
  else
    {
      int deg, max;
      id member, seq = [self eachElement];
      max = [[seq firstElement] degree];
      while ((member = [seq next]))
	{
	  deg = [member degree];
	  if (deg > max)
	    max = deg;
	}
      return max;
    }
}

- (int) minDegree
{
  if ([self isEmpty])
    {
      return -1;
    }
  else
    {
      int deg, min;
      id member, seq = [self eachElement];
      min = [[seq firstElement] degree];
      while ((member = [seq next]))
	{
	  deg = [member degree];
	  if (deg < min)
	    min = deg;
	}
      return min;
    }
}

- eachElement
{
  return ([self isRecursive]) ? [self eachTerm] : [self eachMonomial];
}

- (unsigned) size
{
  return ([self isRecursive]) ? [self numTerms] : [self numMonomials];
}

- insertMember:aMember
{
  return ([self isRecursive]) ? [self insertTerm : aMember]:[self insertMonomial:aMember];
}

- (BOOL) isOpposite:b
{
  id tmp;
  BOOL res;
  tmp = [self add:b];
  res = [tmp isZero];
  return res;
}

- negate
{
  id seq, member, res;
  res = [self empty];
  seq = [self eachElement];
  while ((member = [seq next]))
    [res insertMember:[member negate]];
  return res;
}

- double
{
  id seq, member, res;
  res = [self empty];
  seq = [self eachElement];
  while ((member = [seq next]))
    [res insertMember:[member double]];
  return res;
}

- add:b
{
  id res, seq, member;
  res = [self empty];

  seq = [self eachElement];
  while ((member = [seq next]))
    [res insertMember:member];

  seq = [b eachElement];
  while ((member = [seq next]))
    [res insertMember:member];

  return res;
}

- subtract:b
{
  id res, seq, member;
  res = [self empty];

  seq = [self eachElement];
  while ((member = [seq next]))
    [res insertMember:member];

  seq = [b eachElement];
  while ((member = [seq next]))
    [res insertMember:[member negate]];

  return res;
}

- multiplyScalar:aScalar
{
  id seq, member, res;
  if ([self isRecursive] && [self isVariableDense])
    {
      [self notImplemented:_cmd];
    }

  assert ([self check] && [aScalar check]);
  res = [self empty];
  seq = [self eachElement];
  while ((member = [seq next]))
    {
      [res insertMember:[member multiplyScalar:aScalar]];
    }
  return res;
}

- multiplyCoefficient:aCoefficient
{
  id seq, term, res;
  assert ([self isRecursive] && [self isVariableDense]);
  assert ([self check] && [aCoefficient check]);
  res = [self empty];
  seq = [self eachTerm];
  while ((term = [seq next]))
    {
      [res insertMember:[term multiplyCoefficient:aCoefficient]];
    }
  return res;
}

- multiplyMonomial:aMonomial
{
  id seq, monomial, res;
  assert ([self check] && [aMonomial check]);
  assert ([aMonomial isScalar] == NO);
  res = [self empty];
  seq = [self eachMonomial];
  while ((monomial = [seq next]))
    {
      [res insertMonomial:[monomial multiply:aMonomial]];
    }
  return res;
}

- vardnsMultiplyTerm:aTerm
{
  id seq, term, res;
  assert ([self isVariableDense] && [self check] && [aTerm check]);
  assert ([aTerm isCoefficient] == NO);
  res = [self empty];
  seq = [self eachTerm];
  while ((term = [seq next]))
    {
      [res insertTerm:[term multiply:aTerm]];
    }
  return res;
}

- multiplyTerm:aTerm
{
  assert ([self isRecursive]);
  return ([self isVariableDense]) ? [self vardnsMultiplyTerm : aTerm]:[self varspsMultiplyTerm:aTerm];
}

- divideScalar:aScalar
{
  id seq, member, res;
  if ([self isVariableDense])
    [self notImplemented:_cmd];

  assert ([self check] && [aScalar check] && [aScalar notZero]);
  res = [self empty];
  seq = [self eachElement];
  while ((member = [seq next]))
    {
      member = [member divideScalar:aScalar];
      if (member)
	{
	  [res insertMember:member];
	}
      else
	{
	  return nil;
	}
    }
  return res;
}

- divideCoefficient:aCoefficient
{
  id seq, term, res;
  assert ([self isRecursive] && [self isVariableDense]);
  assert ([aCoefficient notZero] && [self check] && [aCoefficient check]);
  res = [self empty];
  seq = [self eachTerm];
  while ((term = [seq next]))
    {
      term = [term divideCoefficient:aCoefficient];
      if (term)
	{
	  [res insertMember:term];
	}
      else
	{
	  return nil;
	}
    }
  return res;
}

- divideMonomial:aMonomial
{
  id seq, monomial, res;
  assert ([self check] && [aMonomial check]);
  assert ([aMonomial isScalar] == NO && [aMonomial notZero]);
  res = [self empty];
  seq = [self eachMonomial];
  while ((monomial = [seq next]))
    {
      monomial = [monomial divide:aMonomial];
      if (monomial)
	{
	  [res insertMonomial:monomial];
	}
      else
	{
	  return nil;
	}
    }
  return res;
}

- vardnsDivideTerm:aTerm
{
  id seq, term, res;
  assert ([self isVariableDense] && [self check]);
  assert ([aTerm isCoefficient] == NO && [aTerm check] && [aTerm notZero]);
  res = [self empty];
  seq = [self eachTerm];
  while ((term = [seq next]))
    {
      term = [term divide:aTerm];
      if (term)
	{
	  [res insertTerm:term];
	}
      else
	{
	  return nil;
	}
    }
  return res;
}

- divideTerm:aTerm
{
  assert ([self isRecursive]);
  return ([self isVariableDense]) ? [self vardnsDivideTerm : aTerm]:[self varspsDivideTerm:aTerm];
}

- over:aCarrier
{
  return [self notImplemented:_cmd];
}

- liftTerm:aTerm
{
  id aCarrier = [[self empty] insertTerm:aTerm];
  return [Polynomial over:aCarrier];
}

- varspsMultiplyTerm:aTerm
{
  id seq, term, res, aScalar;
  assert ([self check] && [aTerm check]);
  assert ([self isRecursive] && [self isVariableSparse] && [aTerm isCoefficient] == NO);
  res = [self empty];
  seq = [self eachTerm];
  while ((term = [seq next]))
    {
      id product;
      int cmp = [term compareSymbols:aTerm];
      if (cmp == 0)
	{
	  product = [term multiply:aTerm];
	  [res insertTerm:product];
	}
      else
	{
	  if (cmp < 0)
	    {
	      id poly = [self liftTerm:term];
	      product = [aTerm varspsMultiplyCoefficient:poly];
	      [res insertTerm:product];
	    }
	  else
	    {
	      id poly = [self liftTerm:aTerm];
	      product = [term varspsMultiplyCoefficient:poly];
	      [res insertTerm:product];
	    }
	}
    }
  return res;
}

- varspsDivideTerm:aTerm
{
  id seq, term, res, aScalar;
  assert ([self check] && [aTerm check]);
  assert ([self isRecursive] && [self isVariableSparse] && [aTerm isCoefficient] == NO);
  res = [self empty];
  seq = [self eachTerm];
  while ((term = [seq next]))
    {
      id product;
      int cmp = [term compareSymbols:aTerm];
      if (cmp == 0)
	{
	  if ((product = [term divide:aTerm]))
	    {
	      [res insertTerm:product];
	    }
	  else
	    {
	      return nil;
	    }
	}
      else
	{
	  if (cmp < 0)
	    {
	      return nil;
	    }
	  else
	    {
	      id poly = [self liftTerm:aTerm];
	      product = [term varspsDivideCoefficient:poly];
	      if (product)
		{
		  [res insertTerm:product];
		}
	      else
		{
		  return nil;
		}
	    }
	}
    }
  return res;
}

@end
 
