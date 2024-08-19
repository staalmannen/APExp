
/*
 * Computer Algebra Kit (c) 1993,00 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: cobject.m,v 1.9 2000/10/12 14:40:25 stes Exp $
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

@implementation CAObject

+ (STR) cakitRevision
{
  return __cakit_revision__;
}

- new
{
  return [self notImplemented:_cmd];
}

+ str:(STR)aString
{
  return [self notImplemented:_cmd];
}

+ int:(int)intValue
{
  return [self notImplemented:_cmd];
}

+ stringValue:(const char *)aString
{
  return [self str:(STR) aString];
}

- set_str:(STR)x
{
  _str = x;
  return self;
}

- clone
{
  return [[super copy] set_str:NULL];
}

- copy
{
  return [[super copy] set_str:NULL];
}
- deepCopy
{
  return [[super copy] set_str:NULL];
}
- check
{
  return self;
}

- invalidate
{
  if (_str)
    {
      OC_Free (_str);
      _str = NULL;
    }
  assert ([self check]);	/* now we must be ok again */
  return self;
}

- release
{
  if (_str)
    {
      OC_Free (_str);
      _str = NULL;
    }
  return [super release];
}


- set
{
  return nil;
}

- (BOOL) sameClass:a
{
#if defined(__STPSTN__) || defined(__PORTABLE_OBJC__)
  return isa == [a class];
#else
  return isa == ((CAObject *) a)->isa;
#endif
}

- (BOOL) differentClass:a
{
  return [self sameClass:a] == NO;
}

- errorSetEqual
{
  return [self error:"Objects different class"];
}

- checkSetEqual:a
{
  if (self == nil || a == nil)
    {
      fprintf (stderr, "Object is *nil*.\n");
      abort ();
    }
  if ([self differentClass:a])
    {
      fprintf (stderr, "Objects different class : %s (%s) and %s (%s).\n", [self str], [self name], [a str], [a name]);
      abort ();
    }

  return self;
}

- checkSameClass:a
{
  if (self == nil || a == nil)
    {
      fprintf (stderr, "Object is *nil*.\n");
      abort ();
    }
  if ([self differentClass:a])
    {
      fprintf (stderr, "Objects different class : %s (%s) and %s (%s).\n", [self str], [self name], [a str], [a name]);
      abort ();
    }
  return self;
}

- (BOOL) isKindOfSequence
{
  return NO;
}

- class_vector
{
  return (id) [obj_vector class];
}

- class_varspsrecdegsps_polynomial
{
  return (id) [obj_varspsrecdegsps_polynomial class];
}

- class_varspsrecdegdns_polynomial
{
  return [self error:"No Variable Sparse, Recursive and Degree Dense Polynomials Yet"];
  /* return [obj_varspsrecdegdns_polynomial class]; */
}

- class_varspsexpdegsps_polynomial
{
  return (id) [obj_varspsexpdegsps_polynomial class];
}

- class_varspsexpdegdns_polynomial
{
  return [self error:"No Variable Sparse, Expanded and Degree Dense Polynomials Yet"];
  /* return [obj_varspsexpdegdns_polynomial class]; */
}

- class_vardnsrecdegsps_polynomial
{
  return (id) [obj_vardnsrecdegsps_polynomial class];
}

- class_vardnsrecdegdns_polynomial
{
  return (id) [obj_vardnsrecdegdns_polynomial class];
}

- class_vardnsexpdegsps_polynomial
{
  return (id) [obj_vardnsexpdegsps_polynomial class];
}

- class_vardnsexpdegdns_polynomial
{
  return [self error:"No Variable Dense, Expanded and Degree Dense Polynomials Yet"];
  /* return [obj_vardnsexpdegdns_polynomial class]; */
}


static int 
fileLen (FILE * aFile)
{
  int c = 0;
  rewind (aFile);
  while (fgetc (aFile) != EOF)
    {
      c++;
    }
  return c;
}

static void 
fileCpy (STR s, FILE * aFile)
{
  int c;
  rewind (aFile);
  while ((c = fgetc (aFile)) != EOF)
    {
      *s++ = c;
    }
  *s++ = 0;
}

- (STR) str
{
  if (_str)
    {
      return _str;
    }
  else
    {
      FILE *aFile = tmpfile ();
      [self printOn:aFile];
      _str = (STR) OC_Malloc (fileLen (aFile) + 1);
      fileCpy (_str, aFile);
      fclose (aFile);
      return _str;
    }
}

- (const char *) stringValue
{
  return (const char *) [self str];
}

- str:(STR)aString
{
  return [self subclassResponsibility:_cmd];
}

- (int) intValue
{
  [self subclassResponsibility:_cmd];
  return 0;
}

- intValue:(int)i
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- asModp:(unsigned short)p
{
  return [self subclassResponsibility:_cmd];
}

- (BOOL) isFloatingPoint
{
  return NO;
}

- asNumerical
{
  return [self subclassResponsibility:_cmd];
}

- (float) floatValue
{
  [self subclassResponsibility:_cmd];
  return 0;
}

- floatValue:(float)f
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- asTotalFraction
{
  return [Fraction totalFraction:self];
}

- asScalar
{
  return [self notImplemented:_cmd];
}

- scalar:aScalar
{
  return [self notImplemented:_cmd];
}

- asSymbol
{
  return [self notImplemented:_cmd];
}

- symbol:aSymbol
{
  return nil;
}


- (BOOL) isEqual:a
{
  return self == a;
}

- (BOOL) notEqual:a
{
  return [self isEqual:a] == NO;
}


- (BOOL) inOrderedSet
{
  [self subclassResponsibility:_cmd];
  return NO;
}

- (int) compare:b
{
  [self subclassResponsibility:_cmd];
  return NO;
}

- (int) sign
{
  [self subclassResponsibility:_cmd];
  return 0;
}

- (BOOL) isLess:a
{
  return (self == a) ? NO : [self compare:a] < 0;
}

- (BOOL) isGreater:a
{
  return (self == a) ? NO : [self compare:a] > 0;
}

- (BOOL) isLessEqual:a
{
  return (self == a) ? YES : [self compare:a] <= 0;
}

- (BOOL) isGreaterEqual:a
{
  return (self == a) ? YES : [self compare:a] >= 0;
}

- absValue
{
  return ([self sign] < 0) ? [self negate] : self;
}


- (BOOL) inAdditiveSemiGroup
{
  [self subclassResponsibility:_cmd];
  return NO;
}

- (BOOL) inAdditiveMonoid
{
  [self subclassResponsibility:_cmd];
  return NO;
}

- (BOOL) inAdditiveGroup
{
  [self subclassResponsibility:_cmd];
  return NO;
}

- (BOOL) isZero
{
  [self subclassResponsibility:_cmd];
  return NO;
}

- (BOOL) notZero
{
  return [self isZero] == NO;
}

- (BOOL) isOpposite:b
{
  [self subclassResponsibility:_cmd];
  return NO;
}

- (BOOL) notOpposite:b
{
  return [self isOpposite:b] == NO;
}

- zero
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- negate
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- _negate:(int)v
{
  assert (v == +1 || v == -1);
  return (v == +1) ? self : [self negate];
}

- add:b
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- _add:(int)v:b:(int)w
{
  switch (v)
    {
      case +1:return (w == +1) ? [self add : b]:[self subtract:b];
      case -1:return (w == +1) ? [b subtract : self]:[[self add:b] negate];
    }
  return nil;
}

- subtract:b
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- increment
{
  id one = [self one];
  return [self add:one];
}

- decrement
{
  id one = [self one];
  return [self subtract:one];
}

- multiplyIntValue:(int)b
{
  id res = [self intValue:b];
  return [self multiply:res];
}
- double
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- _double:(int)v
{
  return (v == +1) ? [self double] : [[self double] negate];
}

- quadruple
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- divideIntValue:(int)b
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- half
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- quarter
{
  [self subclassResponsibility:_cmd];
  return nil;
}


- (BOOL) commutes
{
  [self subclassResponsibility:_cmd];
  return NO;
}

- (BOOL) commutesWith:b
{
  [self subclassResponsibility:_cmd];
  return NO;
}

- (BOOL) inSemiGroup
{
  [self subclassResponsibility:_cmd];
  return NO;
}

- (BOOL) inMonoid
{
  [self subclassResponsibility:_cmd];
  return NO;
}

- (BOOL) inGroup
{
  [self subclassResponsibility:_cmd];
  return NO;
}

- one
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- minusOne
{
  return [[self one] negate];
}

- (BOOL) isOne
{
  [self subclassResponsibility:_cmd];
  return NO;
}

- (BOOL) notOne
{
  return [self isOne] == NO;
}

- (BOOL) isMinusOne
{
  [self subclassResponsibility:_cmd];
  return NO;
}

- (BOOL) notMinusOne
{
  return [self isMinusOne] == NO;
}

- square
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- _square:(int)w
{
  return (w == +1) ? [self square] : [[self square] negate];
}

- multiply:b
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- _multiply:b:(int)w
{
  id res = [self multiply:b];
  return (w == +1) ? res : [res negate];
}

- power:(int)n
{
  id o, e;
  if (n < 0)
    {
      id i = [self inverse];
      return (i) ? [i power : -n]:nil;
    }

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
  if ([self inMonoid] && [self isOne])
    return self;
  if ([self inAdditiveMonoid])
    {
      if ([self isZero])
	{
	  return self;
	}
      if ([self isMinusOne])
	{
	  return ODD (n) ? self : [self one];
	}
    }
  o = [self one];
  e = [self copy];
  while (n > 1)
    {
      if (n & 1)
	o = [o multiply:e];
      e = [e square];
      n >>= 1;
    }

  e = [e multiply:o];
  return e;
}

- inverse
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- (BOOL) isUnit
{
  id inv = [self inverse];
  return (inv) ? YES : NO;
}

- (BOOL) notUnit
{
  return NO == [self isUnit];
}

- divide:b
{
  [self subclassResponsibility:_cmd];
  return nil;
}


- remainder:b quotient:(id *)q
{
  [self subclassResponsibility:_cmd];
  return nil;
}
- remainder:b
{
  return [self remainder:b quotient:NULL];
}
- quotient:b
{
  id q, r;

  if ((r = [self remainder:b quotient:&q]))
    {
      return q;
    }
  else
    {
      return nil;
    }
}

- (BOOL) inEuclideanDomain
{
  [self subclassResponsibility:_cmd];
  return NO;
}

- (BOOL) isCoprime:b
{
  id g;
  BOOL res;
  g = [self gcd:b];
  res = [g isUnit];
  return res;
}

- (BOOL) notCoprime:b
{
  return [self isCoprime:b] == NO;
}

- (BOOL) isGcd:a:b
{
  id g;
  BOOL res;
  g = [a gcd:b];
  res = [g isEqual:self];
  return res;
}

- (BOOL) isLcm:a:b
{
  id g;
  BOOL res;
  g = [a lcm:b];
  res = [g isEqual:self];
  return res;
}

- gcd:b
{
  return [self subclassResponsibility:_cmd];
}

- bezout:b gcd:(id *)gcd
{
  return [self subclassResponsibility:_cmd];
}

- lcm:b
{
  id lcm, gcd;
  if ([self inAdditiveSemiGroup])
    {
      if ([self isZero])
	return b;
      if ([b isZero])
	return self;
    }
  gcd = [self gcd:b];
  lcm = [self multiply:b];
  lcm = [lcm divide:gcd];
  return lcm;
}


- modulo:m
{
  id r = [self remainder:m];
  if ([self inOrderedSet] && [r sign] < 0)
    r = [r add:m];
  return r;
}

- multiply:b modulo:m
{
  return [[self multiply:b] modulo:m];
}

- squareModulo:m
{
  return [[self square] modulo:m];
}

- power:(int)n modulo:m
{
  id o, e;
  if (n < 0)
    return [self error:"Negative Exponent"];

  switch (n)
    {
      case 0:
      {
	return ([self isZero]) ? nil : [self one];
      }
    case 1:
      {
	return [self modulo:m];
      }
    case 2:
      {
	return [self squareModulo:m];
      }
    }

  if ([self isOne])
    {
      return self;
    }
  if ([self isZero])
    {
      return self;
    }
  if ([self isMinusOne])
    {
      return ODD (n) ? self : [self one];
    }

  o = [self one];
  e = self;
  while (n > 1)
    {
      if (n & 1)
	o = [o multiply:e modulo:m];
      e = [e squareModulo:m];
      n >>= 1;
    }

  e = [e multiply:o modulo:m];
  return e;
}
- genpower:n modulo:m
{
  id o, e;
  DIGIT rem;

  if ([n sign] < 0)
    return [self error:"Negative Exponent"];
  if ([n isDigit])
    return [self power:[n digitValue] modulo:m];

  o = [self one];
  e = self;
  n = [n copy];
  while ([n notOne])
    {
      n = [n quotientDigit:2 remainder:&rem];
      if (rem)
	o = [o multiply:e modulo:m];
      e = [e squareModulo:m];
    }

  return [e multiply:o modulo:m];
}

- inverseModulo:m
{
  return [self subclassResponsibility:_cmd];
}


- random
{
  return [self subclassResponsibility:_cmd];
}


- (int) characteristic
{
  [self subclassResponsibility:_cmd];
  return 0;
}

- (BOOL) isCharacteristicZero
{
  return [self characteristic] == 0;
}

- (BOOL) notCharacteristicZero
{
  return [self characteristic] != 0;
}

- (BOOL) isCharacteristicTwo
{
  return [self characteristic] == 2;
}

- (BOOL) notCharacteristicTwo
{
  return [self characteristic] != 2;
}

- frobenius
{
  return [self subclassResponsibility:_cmd];
}

- frobeniusInverse
{
  return [self subclassResponsibility:_cmd];
}

- (int) dimensionOverPrimeField
{
  [self subclassResponsibility:_cmd];
  return 0;
}


- (BOOL) inRing
{
  return [self inAdditiveGroup] && [self inMonoid];
}

- (BOOL) inIntegralDomain
{
  [self subclassResponsibility:_cmd];
  return NO;
}

- (BOOL) inField
{
  return [self inAdditiveGroup] && [self inGroup];
}

- (BOOL) inFieldOfFractions
{
  return NO;
}

- _addSquare:(int)v:b:(int)w
{
  id t = [b square];
  return [self _add:v:t:w];
}

- _add:(int)v:B multiply:b:(int)w
{
  id t = [B multiply:b];
  return [self _add:v:t:w];
}

- _multiply:a:(int)v add:B:(int)w
{
  return [[self multiply:a] _add:v:B:w];
}

- _multiply:a:(int)v add:B multiply:b:(int)w
{
  return [[self multiply:a] _add:v:B multiply:b:w];
}

- _multiply:a:(int)v divide:d
{
  return [[self _multiply:a:v] divide:d];
}

- _multiply:a:(int)v add:B multiply:b:(int)w divide:d
{
  return [[self _multiply:a:v add:B multiply:b:w] divide:d];
}


- scalarZero
{
  [self subclassResponsibility:_cmd];
  return nil;
}
- scalarContent
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- divideScalarContent
{
  id new, c;
  c = [self scalarContent];
  new = ([c isZero]) ? self : [self divideScalar:c];
  return new;
}

- multiplyScalar:s
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- _multiplyScalar:s:(int)v
{
  id res = [self multiplyScalar:s];
  return (v == +1) ? res : [res negate];
}

- divideScalar:s
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- addScalar:s
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- subtractScalar:s
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- _add:(int)v:B multiplyScalar:b:(int)w
{
  id t = [B multiplyScalar:b];
  return [self _add:v:t:w];
}

- _multiplyScalar:a:(int)v add:B:(int)w
{
  return [[self multiplyScalar:a] _add:v:B:w];
}

- _multiplyScalar:a:(int)v add:B multiplyScalar:b:(int)w
{
  return [[self multiplyScalar:a] _add:v:B multiplyScalar:b:w];
}

- _multiplyScalar:a:(int)v divideScalar:d
{
  return [[self _multiplyScalar:a:v] divideScalar:d];
}

- _multiplyScalar:a:(int)v add:B multiplyScalar:b:(int)w divideScalar:d
{
  return [[self _multiplyScalar:a:v add:B multiplyScalar:b:w] divideScalar:d];
}

- subtract:r multiplyScalar:q
{
  return [self _add:+1:r multiplyScalar:q:-1];
}

- multiplyScalar:p subtract:r multiplyScalar:q divideScalar:d
{
  return [self _multiplyScalar:p:+1 add:r multiplyScalar:q:-1 divideScalar:d];
}

- multiplyScalar:p divideScalar:d
{
  return [self _multiplyScalar:p:+1 divideScalar:d];
}

- multiplyCoefficient:s
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- _multiplyCoefficient:s:(int)v
{
  id res = [self multiplyCoefficient:s];
  return (v == +1) ? res : [res negate];
}

- divideCoefficient:s
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- _add:(int)v:B multiplyCoefficient:b:(int)w
{
  id t = [B multiplyCoefficient:b];
  return [self _add:v:t:w];
}

- _multiplyCoefficient:a:(int)v add:B:(int)w
{
  return [[self multiplyCoefficient:a] _add:v:B:w];
}

- _multiplyCoefficient:a:(int)v add:B multiplyCoefficient:b:(int)w
{
  return [[self multiplyCoefficient:a] _add:v:B multiplyCoefficient:b:w];
}

- _multiplyCoefficient:a:(int)v divideCoefficient:d
{
  return [[self _multiplyCoefficient:a:v] divideCoefficient:d];
}

- _multiplyCoefficient:a:(int)v add:B multiplyCoefficient:b:(int)w divideCoefficient:d
{
  return [[self _multiplyCoefficient:a:v add:B multiplyCoefficient:b:w] divideCoefficient:d];
}

- multiplyTerm:s
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- _multiplyTerm:s:(int)v
{
  id res = [self multiplyTerm:s];
  return (v == +1) ? res : [res negate];
}

- divideTerm:s
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- _add:(int)v:B multiplyTerm:b:(int)w
{
  id t = [B multiplyTerm:b];
  return [self _add:v:t:w];
}

- _multiplyCoefficient:a:(int)v add:B multiplyTerm:b:(int)w
{
  return [[self multiplyCoefficient:a] _add:v:B multiplyTerm:b:w];
}

- add:r multiplyTerm:q
{
  return [self _add:+1:r multiplyTerm:q:+1];
}

- subtract:r multiplyTerm:q
{
  return [self _add:+1:r multiplyTerm:q:-1];
}

- multiplyCoefficient:p subtract:r multiplyTerm:q
{
  return [self _multiplyCoefficient:p:+1 add:r multiplyTerm:q:-1];
}

- multiplyMonomial:s
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- _multiplyMonomial:s:(int)v
{
  id res = [self multiplyMonomial:s];
  return (v == +1) ? res : [res negate];
}

- divideMonomial:s
{
  [self subclassResponsibility:_cmd];
  return nil;
}

- _add:(int)v:B multiplyMonomial:b:(int)w
{
  id t = [B multiplyMonomial:b];
  return [self _add:v:t:w];
}

- _multiplyScalar:a:(int)v add:B multiplyMonomial:b:(int)w
{
  return [[self multiplyScalar:a] _add:v:B multiplyMonomial:b:w];
}

- add:r multiplyMonomial:q
{
  return [self _add:+1:r multiplyMonomial:q:+1];
}

- subtract:r multiplyMonomial:q
{
  return [self _add:+1:r multiplyMonomial:q:-1];
}

- multiplyScalar:p subtract:r multiplyMonomial:q
{
  return [self _multiplyScalar:p:+1 add:r multiplyMonomial:q:-1];
}


- (BOOL) printsLeadingSign
{
  return NO;
}

- (BOOL) printsSum
{
  return NO;
}

- (BOOL) printsProduct
{
  return NO;
}

- printOn:(IOD)aFile
{
  [self subclassResponsibility:_cmd];
  return self;
}

@end
 
