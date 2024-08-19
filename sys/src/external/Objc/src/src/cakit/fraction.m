
/*
 * Computer Algebra Kit (c) 1993,2000,14 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: fraction.m,v 1.9 2014/03/04 09:09:34 stes Exp $
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

@implementation Fraction
- check
{
  assert (numerator && denominator);
  [numerator check];
  [denominator check];
  if ([numerator sameClass:denominator])
    {
      if ([numerator inIntegralDomain])
	{
	  assert ([numerator isCoprime:denominator]);
	}
      if ([numerator inOrderedSet])
	assert ([denominator sign] >= 0);
    }
  return [super check];
}


- totalFraction:aNumerator
{
  return [self notImplemented:_cmd];
}

+ totalFraction:aNumerator
{
  return [self numerator:aNumerator denominator:[aNumerator one]];
}

- _setUpNumerator:aNumerator denominator:aDenominator
{
  numerator = aNumerator;
  denominator = aDenominator;
  assert ([self check]);
  return self;
}

+ numerator:aNumerator denominator:aDenominator
{
  return [[super new] _setUpNumerator:aNumerator denominator:aDenominator];
}

- copy
{
  return [super copy];
}

- setnumerator:n denominator:d
{
  numerator = n;
  denominator = d;
  return self;
}

- deepCopy
{
  return [[super deepCopy] setnumerator:[numerator deepCopy] denominator:[denominator deepCopy]];
}

static id 
mulMap (id numerator, id denominator)
{
  return [numerator multiply:denominator];	/* A x S -> A currently only total fractions */
}

- numerator:n denominator:d
{
  assert (n && d);

  if ([numerator sameClass:denominator])
    {
      if ([numerator inIntegralDomain])
	{
	  id gcd = [n gcd:d];
	  if ([gcd notOne])
	    {
	      n = [n divide:gcd];
	      d = [d divide:gcd];
	    }
	}
      if ([numerator inOrderedSet] && [d sign] < 0)
	{
	  n = [n negate];
	  d = [d negate];
	}
    }

  return [[self clone] setnumerator:n denominator:d];
}

- numerator:aNumerator
{
  return [self numerator:aNumerator denominator:denominator];
}

- denominator:aDenominator
{
  return [self numerator:numerator denominator:aDenominator];
}

- denominator:aNumerator numerator:aDenominator
{
  return [self numerator:aNumerator denominator:aDenominator];
}

- numerator:aNumerator numerator:aDenominator
{
  return [self numerator:aNumerator denominator:aDenominator];
}

- (BOOL)sameClass:b
{
  return isa == [b class] && [numerator sameClass:[b numerator]] && [denominator sameClass:[b denominator]];
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
  return YES;
}

- (BOOL)inEuclideanDomain		
{
  return YES;
}
- (BOOL)inIntegralDomain		
{
  return YES;
}
- (BOOL)inField				
{
  return YES;
}
- (BOOL)inFieldOfFractions		
{
  return YES;
}

- (BOOL)inOrderedSet			
{
  return [numerator inOrderedSet];
}
- (int)characteristic			
{
  return [numerator characteristic];
}


- numerator
{
  return numerator;
}

- denominator
{
  return denominator;
}

- (unsigned) hash
{
  return ([numerator hash] << 16) + ([denominator hash] & 0x0000ffff);
}

- (BOOL) isEqual:b
{
  if (self == b)
    {
      return YES;
    }
  else
    {
      id bn = [b numerator];
      id bd = [b denominator];
      if ([numerator isEqual:bn] && [denominator isEqual:bd])
	return YES;
      if ([numerator inIntegralDomain])
	{
	  if ([numerator inOrderedSet])
	    {
	      return NO;
	    }
	  else
	    {
	      if ([numerator isOpposite:bn] && [denominator isOpposite:bd])
		return YES;
	      return NO;
	    }
	}
      else
	{
	  BOOL eq;
	  id t = [self subtract:b];
	  eq = [t isZero];
	  return eq;
	}
    }
}

- (int) compare:b
{
  if (self == b)
    {
      return 0;
    }
  else
    {
      int cmp;
      id ad = mulMap (numerator, [b denominator]);
      id cb = mulMap ([b numerator], denominator);
      cmp = [ad compare:cb];
      return cmp;
    }
}


- asNumerical
{
  id r;
  id n = [numerator asNumerical];
  id d = [denominator asNumerical];

  r = [n divide:d];
  return r;
}

- asModp:(unsigned short)p
{
  id r;
  id n = [numerator asModp:p];
  id d = [denominator asModp:p];

  if ((r = [n divide:d]))
    {
      return r;
    }
  else
    {
      return [self error:"asModp: division failed"];
    }
}

- asIntegral
{
  if ([denominator isOne])
    {
      return numerator;
    }
  else
    {
      return [self error:"-asIntegral: denominator not one"];
    }
}


- zero
{
  return [self numerator:[numerator zero] denominator:[denominator one]];
}

- (BOOL) isZero
{
  return [numerator isZero];
}

- (BOOL) isOpposite:b
{
  if (self == b)
    {
      return [self isZero];
    }
  else
    {
      id bn = [b numerator];
      id bd = [b denominator];
      if ([numerator isOpposite:bn] && [denominator isEqual:bd])
	return YES;
      if ([numerator inIntegralDomain])
	{
	  if ([numerator inOrderedSet])
	    {
	      return NO;
	    }
	  else
	    {
	      if ([numerator isEqual:bn] && [denominator isOpposite:bd])
		return YES;
	      return NO;
	    }
	}
      else
	{
	  BOOL eq;
	  id t = [self add:b];
	  eq = [t isZero];
	  return eq;
	}
    }
}

- negate
{
  if ([self isZero])
    return self;
  return [self numerator:[numerator negate]];
}

- double
{
  if ([self isZero])
    return self;
  return [self numerator:[numerator double]];
}

- add:b
{
  if (self == b)
    {
      return [self double];
    }
  else
    {
      if ([self isZero])
	return b;
      if ([b isZero])
	return self;
      if ([denominator isEqual:[b denominator]])
	{
	  return [self numerator:[numerator add:[b numerator]]];
	}
      else
	{
	  id ad = mulMap (numerator, [b denominator]);
	  id cb = mulMap ([b numerator], denominator);
	  ad = [ad add:cb];
	  return [self numerator:ad denominator:[denominator multiply:[b denominator]]];
	}
    }
}

- subtract:b
{
  if (self == b)
    {
      return [self zero];
    }
  else
    {
      if ([self isZero])
	return [b negate];
      if ([b isZero])
	return self;
      if ([denominator isEqual:[b denominator]])
	{
	  return [self numerator:[numerator subtract:[b numerator]]];
	}
      else
	{
	  id ad = mulMap (numerator, [b denominator]);
	  id cb = mulMap ([b numerator], denominator);
	  ad = [ad subtract:cb];
	  return [self numerator:ad denominator:[denominator multiply:[b denominator]]];
	}
    }
}


- one
{
  return [self numerator:[numerator one] denominator:[denominator one]];
}

- (BOOL) isOne
{
  return [numerator isEqual:denominator];
}

- (BOOL) isMinusOne
{
  return [numerator isOpposite:denominator];
}

- square
{
  if ([self isZero])
    return [self zero];
  if ([self isOne] || [self isMinusOne])
    return [self one];
  return [self numerator:[numerator square] denominator:[denominator square]];
}

- inverse
{
  if ([self isZero])
    return nil;
  if ([self isOne] || [self isMinusOne])
    return self;
  return [self denominator:denominator numerator:numerator];
}

- multiply:b
{
  if (self == b)
    {
      return [self square];
    }
  else
    {
      id n, d;
      if ([self isZero] || [b isZero])
	return [self zero];
      if ([self isOne])
	return b;
      if ([b isOne])
	return self;
      if ([self isMinusOne])
	return [b negate];
      if ([b isMinusOne])
	return [self negate];
      n = [numerator multiply:[b numerator]];
      d = [denominator multiply:[b denominator]];
      return [self numerator:n denominator:d];
    }
}

- divide:b
{
  if ([b isZero])
    return nil;
  if (self == b)
    {
      return [self one];
    }
  else
    {
      id n, d;
      if ([self isZero])
	return [self zero];
      if ([b isOne])
	return self;
      if ([b isMinusOne])
	return [self negate];
      n = mulMap (numerator, [b denominator]);
      d = mulMap ([b numerator], denominator);
      return [self numerator:n numerator:d];
    }
}

- power:(int)n
{
  if ([self isZero])
    return [self zero];
  if ([self isOne])
    return [self one];
  if ([self isMinusOne])
    return (ODD (n)) ? self : [self one];
  return [self numerator:[numerator power:n] denominator:[denominator power:n]];
}


- intValue:(int)intValue
{
  return [self numerator:[numerator intValue:intValue] denominator:[denominator one]];
}

- (int) intValue
{
  return [numerator intValue] / [denominator intValue];
}

- multiplyIntValue:(int)intValue
{
  switch (intValue)
    {
      case 0:return [self zero];
      case +1:return self;
      case -1:return [self negate];
    default:
      {
	id n = [numerator multiplyIntValue:intValue];
	id d = denominator;
	return [self numerator:n denominator:d];
      }
    }
}

- divideIntValue:(int)intValue
{
  switch (intValue)
    {
      case 0:return nil;
      case +1:return self;
      case -1:return [self negate];
    default:
      {
	id n = numerator;
	id d = [denominator multiplyIntValue:intValue];
	return [self numerator:n denominator:d];
      }
    }
}


- (BOOL) printsLeadingSign
{
  if ([denominator notOne])
    {
      if ([numerator printsSum])
	return NO;
      return [numerator printsLeadingSign];
    }
  else
    {
      return [numerator printsLeadingSign];
    }
}

- (BOOL) printsSum
{
  if ([denominator notOne])
    {
      return NO;
    }
  else
    {
      return [numerator printsSum];
    }
}

- (BOOL) printsProduct
{
  if ([denominator notOne])
    {
      return NO;
    }
  else
    {
      return [numerator printsProduct];
    }
}

- printOn:(IOD)aFile
{
  if ([denominator notOne])
    {
      if ([numerator printsSum])
	{
	  fprintf (aFile, "(");
	  [numerator printOn:aFile];
	  fprintf (aFile, ")");
	}
      else
	{
	  [numerator printOn:aFile];
	}

      fprintf (aFile, "/");

      if ([denominator printsProduct] || [denominator printsSum])
	{
	  fprintf (aFile, "(");
	  [denominator printOn:aFile];
	  fprintf (aFile, ")");
	}
      else
	{
	  [denominator printOn:aFile];
	}
    }
  else
    {
      [numerator printOn:aFile];
    }

  return self;
}

@end
 
