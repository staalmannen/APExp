
/*
 * Computer Algebra Kit (c) 1993,00 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: ccomplex.m,v 1.7 2001/07/09 19:30:49 stes Exp $
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

@implementation Gaussian

+ real:aReal
{
  return [self real:aReal imaginary:[aReal zero]];
}

- _setUpReal:aReal imaginary:anotherReal
{
  real = aReal;
  imaginary = anotherReal;
  return self;
}

+ real:aReal imaginary:anotherReal
{
  return [[super new] _setUpReal:aReal imaginary:anotherReal];
}

- copy
{
  return [super copy];
}

- dodeepCopy
{
  real = [real deepCopy];
  imaginary = [imaginary deepCopy];
  return self;
}

- deepCopy
{
  return [[super deepCopy] dodeepCopy];
}

- doreal:aReal imaginary:anotherReal
{
  assert (aReal && anotherReal);
  real = aReal;
  imaginary = anotherReal;
  return self;
}

- real:aReal imaginary:anotherReal
{
  return [[self clone] doreal:aReal imaginary:anotherReal];
}

- real:aReal
{
  return [self real:aReal imaginary:[imaginary zero]];
}

- imaginary:aReal
{
  return [self real:[real zero] imaginary:aReal];
}

- symbol:aSymbol
{
  if (strcmp ([aSymbol str], "I") == 0)
    {
      return [self I];
    }
  else
    {
      return [self real:[real symbol:aSymbol]];
    }
}


- real
{
  return real;
}

- imaginary
{
  return imaginary;
}

- (BOOL) isReal
{
  return [imaginary isZero];
}

- (BOOL) notReal
{
  return [imaginary notZero];
}

- (unsigned) hash
{
  return ([real hash] << 16) + ([imaginary hash] & 0x0000ffff);
}

- (BOOL) isEqual:b
{
  if (self == b)
    {
      return YES;
    }
  else
    {
      return [real isEqual:[b real]] && [imaginary isEqual:[b imaginary]];
    }
}


- conjugate
{
  if ([self isReal])
    {
      return self;
    }
  else
    {
      return [self imaginary:[imaginary negate]];
    }
}

- norm
{
  id norm;

  if ([self isReal])
    {
      norm = [real square];
    }
  else
    {
      id t = [imaginary square];
      norm = [[real square] add:t];
    }

  return norm;
}

- asReal
{
  assert ([self isReal]);
  return real;
}


- zero
{
  return [self real:[real zero] imaginary:[imaginary zero]];
}

- (BOOL) isZero
{
  return [real isZero] && [imaginary isZero];
}

- (BOOL) isOpposite:b
{
  return [real isOpposite:[b real]] && [imaginary isOpposite:[b imaginary]];
}

- negate
{
  if ([self isReal])
    {
      return [self real:[real negate]];
    }
  else
    {
      return [self real:[real negate] imaginary:[imaginary negate]];
    }
}

- double
{
  if ([self isReal])
    {
      return [self real:[real double]];
    }
  else
    {
      return [self real:[real double] imaginary:[imaginary double]];
    }
}

- add:b
{
  if (self == b)
    {
      return [self double];
    }
  else
    {
      id r = [real add:[b real]];
      id i = [imaginary add:[b imaginary]];
      return [self real:r imaginary:i];
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
      id r = [real subtract:[b real]];
      id i = [imaginary subtract:[b imaginary]];
      return [self real:r imaginary:i];
    }
}


- I
{
  return [self imaginary:[imaginary one]];
}

- one
{
  return [self real:[real one]];
}

- (BOOL) isOne
{
  if ([real isZero])
    return [imaginary isUnit];
  if ([imaginary isZero])
    return [real isUnit];
  return NO;
}

- (BOOL) isMinusOne
{
  if ([real isZero])
    return [imaginary isUnit];
  if ([imaginary isZero])
    return [real isUnit];
  return NO;
}

- (BOOL) isUnit
{
  if ([real isZero])
    return [imaginary isUnit];
  if ([imaginary isZero])
    return [real isUnit];
  return NO;
}

- square
{
  if ([self isZero])
    return [self zero];
  if ([self isOne] || [self isMinusOne])
    return [self one];

  if ([self isReal])
    {
      return [self real:[real square]];
    }
  else
    {
      id r, i;
      r = [real square];
      i = [imaginary square];
      r = [r subtract:i];
      i = [[real multiply:imaginary] double];
      return [self real:r imaginary:i];
    }
}

- multiplyReal:b
{
  if ([b isZero])
    return [self zero];
  if ([b isOne])
    return self;
  if ([b isMinusOne])
    return [self negate];

  return [self real:[real multiply:b] imaginary:[imaginary multiply:b]];
}

- multiply:b
{
  if (self == b)
    {
      return [self square];
    }
  else
    {
      id ac, bd, bc, ad;
      if ([self isReal])
	return [b multiplyReal:real];
      if ([b isReal])
	return [self multiplyReal:[b real]];

      ac = [real multiply:[b real]];
      bd = [imaginary multiply:[b imaginary]];
      ad = [real multiply:[b imaginary]];
      bc = [imaginary multiply:[b real]];

      ac = [ac subtract:bd];
      ad = [ad add:bc];
      return [self real:ac imaginary:ad];
    }
}

- power:(int)n
{
  if ([self isReal])
    {
      return [self real:[real power:n]];
    }
  else
    {
      id o, e;

      if (n == 0)
	{
	  return [self one];
	}
      if (n == 1)
	{
	  return self;
	}
      if (n == 2)
	{
	  return [self square];
	}

      o = [[self one] copy];
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
}


- divideReal:b
{
  id r, i;

  if ([b isZero])
    return nil;
  if ([b isOne])
    return self;
  if ([b isMinusOne])
    return [self negate];

  r = [real divide:b];
  if (!r)
    return nil;
  i = [imaginary divide:b];
  if (!i)
    return nil;

  return [self real:r imaginary:i];
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
      if ([b isReal])
	{
	  return [self divideReal:[b real]];
	}
      else
	{
	  id bbar, norm, res;
	  bbar = [b conjugate];
	  norm = [b norm];
	  /* this is not the same as multiplying by the inverse of b ! */
	  res = [[self multiply:bbar] divideReal:norm];
	  return res;
	}
    }
}

- inverse
{
  id inv, norm;
  if ([self isZero])
    return nil;
  if ([self isOne] || [self isMinusOne])
    return self;

  norm = [self norm];
  inv = [[self conjugate] divideReal:norm];
  return inv;
}

- quotientReal:b
{
  id r, i;

  if ([b isZero])
    return nil;
  if ([b isOne])
    return self;
  if ([b isMinusOne])
    return [self negate];

  r = [real quotient:b];
  if (!r)
    return nil;
  i = [imaginary quotient:b];
  if (!i)
    return nil;

  return [self real:r imaginary:i];
}

- quotient:b
{
  if ([b isZero])
    return nil;
  if (self == b)
    {
      return [self one];
    }
  else
    {
      if ([b isReal])
	{
	  return [self quotientReal:[b real]];
	}
      else
	{
	  id bbar, norm, res;
	  bbar = [b conjugate];
	  norm = [b norm];
	  res = [[self multiply:bbar] quotientReal:norm];
	  return res;
	}
    }
}

- remainder:b quotient:(id *)q
{
  id rem, tmp, quo = [self quotient:b];
  tmp = [quo multiply:b];
  rem = [self subtract:tmp];
  if (q)
    *q = quo;
  return rem;
}


- gcd:b
{
  if ([self isZero])
    return b;
  if ([b isZero])
    return self;

  if ([self isReal] && [b isReal])
    {
      id ra, rb, rc;
      ra = [self asReal];
      rb = [b asReal];
      rc = [ra gcd:rb];
      return [self real:rc];
    }
  else
    {
      id a = [self copy];
      b = [b copy];
      while ([b notZero])
	{
	  id c = [a remainder:b];
	  a = b;
	  b = c;
	}
      return a;
    }
}


- printOn:(IOD)aFile
{
  if ([imaginary isZero])
    {
      if ([real isZero])
	{
	  fprintf (aFile, "0");
	}
      else
	{
	  [real printOn:aFile];
	}
    }
  else
    {
      if ([real notZero])
	{
	  [real printOn:aFile];
	  fprintf (aFile, " + ");
	}
      fprintf (aFile, "I ");
      [imaginary printOn:aFile];
    }

  return self;
}

@end
 
