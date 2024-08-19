
/*
 * Computer Algebra Kit (c) 1993,00 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: cfloat.m,v 1.6 2000/10/12 14:40:25 stes Exp $
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

static float_args 
float_getargs (id self)
{
  float_args args;
  args.unused = 0;
  return args;
}

static int 
float_size (float_args args)
{
  return 1;			/* pointer increment */
}

static int 
float_bsize (float_args args)
{
  return sizeof (float_c);	/* bytes */
}

static float_t 
float_id2t (id object)
{
  return [object float_value];	/* read-only */
}

static float_t 
float_id2ref (id object, float_c * ref)
{
  return [object float_value];	/* read-only, scratch space "ref" */
}

static float_c *
float_id2c (id object)
{
  return [object float_reference];	/* write for inplace arithmetic */
}

static id 
float_t2id (id proto, float_t f)
{
  return [proto float_value:f];	/* new object containing copy of "f" */
}

static id 
float_c2id (id proto, float_c * f)
{
  return [proto float_reference:f];	/* new object containing "f" */
}

static int 
float_check (float_t self, float_args args)
{
  return 1;
}

static float_t 
float_zero (float_args args)
{
  return 0.0;
}

static float_t 
float_one (float_args args)
{
  return 1.0;
}

static unsigned 
float_hash (float_t a, float_args args)
{
  return (unsigned) a;
}

static int 
float_iszero (float_t a, float_args args)
{
  return a == 0.0;
}

static int 
float_isone (float_t a, float_args args)
{
  return a == +1.0;
}

static int 
float_isminusone (float_t a, float_args args)
{
  return a == -1.0;
}

static int 
float_sgn (float_t a, float_args args)
{
  return (a == 0.0) ? 0 : ((a < 0.0) ? -1 : +1);
}

static int 
float_cmp (float_t a, float_t b, float_args args)
{
  return (a == b) ? 0 : ((a < b) ? -1 : +1);
}

static int 
float_iseq (float_t a, float_t b, float_args args)
{
  return a == b;
}

static int 
float_isop (float_t a, float_t b, float_args args)
{
  return a + b == 0.0;
}

static float_t 
float_neg (float_t a, float_args args)
{
  return -a;
}

static float_t 
float_dbl (float_t a, float_args args)
{
  return a + a;
}

static float_t 
float_add (float_t a, float_t b, float_args args)
{
  return a + b;
}

static float_t 
float_sub (float_t a, float_t b, float_args args)
{
  return a - b;
}

static float_t 
float_sqr (float_t a, float_args args)
{
  return a * a;
}

static float_t 
float_mul (float_t a, float_t b, float_args args)
{
  return a * b;
}

static float_t 
float_inv (float_t a, float_args args)
{
  return 1.0 / a;
}

static float_t 
float_div (float_t a, float_t b, float_args args)
{
  return a / b;
}

static float_t 
float_pow (float_t a, int n, float_args args)
{
  /* on some systems, pow() needs libm.a
   * return pow(a,n);
   */

  float_t o;

  if (n == 0)
    return 1.0;
  if (n == 1)
    return a;
  if (n == 2)
    return a * a;

  o = 1.0;
  while (n > 1)
    {
      if (n & 1)
	o = o * a;
      a = a * a;
      n >>= 1;
    }

  return o * a;
}

#if !float_isvalue
#error "float_copy_val.fab should not be included"
#endif

static void 
float_clear (float_c * c, float_args args)
{
  /* nothing to clear, but the following might help... */
#ifndef DEBUG
  *c = (float_t) 0xcafebabe;
#endif
}

static void 
float_copy (float_c * c, float_t a, float_args args)
{
  *c = a;
}

static void 
float_deepcopy (float_c * c, float_t a, float_args args)
{
  *c = a;
}

static void 
float_move (float_c * c, float_c * a, float_args args)
{
  *c = *a;
#ifndef DEBUG
  *a = (float_t) 0xcafebabe;
#endif
}

#if !float_isvalue
#error "float_add_val.fab should not be included"
#endif

static void 
float_oozero (float_c * c, float_args args)
{
  *c = float_zero (args);
}

static void 
float_inzero (float_c * a, float_args args)
{
  *a = float_zero (args);
}

static void 
float_inneg (float_c * a, float_args args)
{
  *a = float_neg (*a, args);
}

static void 
float_ooneg (float_c * c, float_t a, float_args args)
{
  *c = float_neg (a, args);
}

static float_t 
float_dblv (float_t a, int v, float_args args)
{
  float_t c = float_dbl (a, args);
  return (v == +1) ? c : float_neg (c, args);
}

static void 
float_indbl (float_c * a, int v, float_args args)
{
  *a = float_dblv (*a, v, args);
}

static void 
float_oodbl (float_c * c, float_t a, int v, float_args args)
{
  *c = float_dblv (a, v, args);
}

static float_t 
float_addvw (float_t a, int v, float_t b, int w, float_args args)
{
  float_t c;
  assert (v * v == +1 && w * w == 1);

  if (v == +1)
    {
      if (w == +1)
	{
	  c = float_add (a, b, args);
	}
      else
	{
	  c = float_sub (a, b, args);
	}
    }
  else
    {
      if (w == +1)
	{
	  c = float_sub (b, a, args);
	}
      else
	{
	  c = float_neg (float_add (a, b, args), args);
	}
    }

  return c;
}

static void 
float_inadd (float_c * a, int v, float_t b, int w, float_args args)
{
  *a = float_addvw (*a, v, b, w, args);
}

static void 
float_ooadd (float_c * c, float_t a, int v, float_t b, int w, float_args args)
{
  *c = float_addvw (a, v, b, w, args);
}
#if !float_isvalue
#error "float_mul_val.fab should not be included"
#endif

static void 
float_insqr (float_c * a, float_args args)
{
  *a = float_sqr (*a, args);
}

static void 
float_oosqr (float_c * c, float_t a, float_args args)
{
  *c = float_sqr (a, args);
}

static void 
float_inmul (float_c * a, float_t b, float_args args)
{
  *a = float_mul (*a, b, args);
}

static void 
float_oomul (float_c * c, float_t a, float_t b, float_args args)
{
  *c = float_mul (a, b, args);
}
#if !float_isvalue
#error "float_inv_val.fab should not be included"
#endif

static void 
float_ininv (float_c * a, float_args args)
{
  *a = float_inv (*a, args);
}

static void 
float_ooinv (float_c * c, float_t a, float_args args)
{
  *c = float_inv (a, args);
}

#if !float_isvalue
#error "float_div_val.fab should not be included"
#endif

static void 
float_indiv (float_c * a, float_t b, float_args args)
{
  *a = float_div (*a, b, args);
}

static BOOL 
float_oodiv (float_c * c, float_t a, float_t b, float_args args)
{
  *c = float_div (a, b, args);
  return SUCCESS;
}
#if !float_isvalue
#error "float_add_val.fab should not be included"
#endif

static float_t 
float_mulv (float_t a, float_t b, int v, float_args args)
{
  float_t c = float_mul (a, b, args);
  return (v == +1) ? c : float_neg (c, args);
}

static void 
float_inmulv (float_c * a, float_t b, int v, float_args args)
{
  *a = float_mulv (*a, b, v, args);
}

static void 
float_oomulv (float_c * c, float_t a, float_t b, int v, float_args args)
{
  *c = float_mulv (a, b, v, args);
}

static float_t 
float_addmul (float_t a, int v, float_t b, float_t s, int w, float_args args)
{
  return float_addvw (a, v, float_mul (b, s, args), w, args);
}

static float_t 
float_addsqr (float_t a, int v, float_t b, int w, float_args args)
{
  return float_addvw (a, v, float_sqr (b, args), w, args);
}

static float_t 
float_muladd (float_t a, float_t s, int v, float_t b, int w, float_args args)
{
  return float_addvw (float_mul (a, s, args), v, b, w, args);
}

static float_t 
float_muladdmul (float_t a, float_t s, int v, float_t b, float_t t, int w, float_args args)
{
  return float_addvw (float_mul (a, s, args), v, float_mul (b, t, args), w, args);
}

static void 
float_inaddmul (float_c * a, int v, float_t b, float_t t, int w, float_args args)
{
  *a = float_addmul (*a, v, b, t, w, args);
}

static void 
float_ooaddmul (float_c * c, float_t a, int v, float_t b, float_t t, int w, float_args args)
{
  *c = float_addmul (a, v, b, t, w, args);
}

static void 
float_inaddsqr (float_c * a, int v, float_t b, int w, float_args args)
{
  *a = float_addsqr (*a, v, b, w, args);
}

static void 
float_ooaddsqr (float_c * c, float_t a, int v, float_t b, int w, float_args args)
{
  *c = float_addsqr (a, v, b, w, args);
}

static void 
float_inmuladd (float_c * a, float_t s, int v, float_t b, int w, float_args args)
{
  *a = float_muladd (*a, s, v, b, w, args);
}

static void 
float_oomuladd (float_c * c, float_t a, float_t s, int v, float_t b, int w, float_args args)
{
  *c = float_muladd (a, s, v, b, w, args);
}

static void 
float_inmuladdmul (float_c * a, float_t s, int v, float_t b, float_t t, int w, float_args args)
{
  *a = float_muladdmul (*a, s, v, b, t, w, args);
}

static void 
float_oomuladdmul (float_c * c, float_t a, float_t s, int v, float_t b, float_t t, int w, float_args args)
{
  *c = float_muladdmul (a, s, v, b, t, w, args);
}
@implementation Float

+ new
{
  return [self floatValue:0];
}

- _setUpFloatValue:(float)floatValue
{
  value = floatValue;
  return self;
}

+ floatValue:(float)floatValue
{
  return [[super new] _setUpFloatValue:floatValue];
}

+ str:(STR)aString
{
  static id dummy = nil;
  if (!dummy)
    dummy = [self new];
  return [dummy str:aString];
}

- empty
{
  return [self float_value:0];
}

- (float_t) float_value
{
  return value;
}

- setfloat_value:(float_t)f
{
  value = f;
  return self;
}

- float_value:(float_t)f
{
  return [[self clone] setfloat_value:f];
}

- (float_t *) float_reference
{
  return &value;
}

- float_reference:(float_t *)f
{
  return [self float_value:*f];
}


- (BOOL) isFloatingPoint
{
  return YES;
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
  return YES;
}
- (int)characteristic			
{
  return 0;
}


- (unsigned) hash
{
  return float_hash (float_id2t (self), float_getargs (self));
}

- (BOOL) isEqual:b
{
  [self checkSameClass:b];
  if (self == b)
    {
      return YES;
    }
  else
    {
      return float_iseq (float_id2t (self), float_id2t (b), float_getargs (self));
    }
}

- (BOOL) notEqual:b
{
  [self checkSameClass:b];
  if (self == b)
    {
      return NO;
    }
  else
    {
      return !float_iseq (float_id2t (self), float_id2t (b), float_getargs (self));
    }
}

- (float) floatValue
{
  return value;
}

- floatValue:(float)f
{
  return [self float_value:f];
}


- (int) sign
{
  return float_sgn (float_id2t (self), float_getargs (self));
}

- (int) compare:b
{
  [self checkSameClass:b];

  if (self == b)
    {
      return 0;
    }
  else
    {
      return float_cmp (float_id2t (self), float_id2t (b), float_getargs (self));
    }
}

- zero
{
  static id zero = nil;
  return (zero) ? zero : (zero = [self floatValue:0]);
}

- (BOOL) isZero
{
  assert ([self check]);
  return float_iszero (float_id2t (self), float_getargs (self));
}

- (BOOL) notZero
{
  assert ([self check]);
  return NO == float_iszero (float_id2t (self), float_getargs (self));
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
      return float_isop (float_id2t (self), float_id2t (b), float_getargs (self));
    }
}

- (BOOL) notOpposite:b
{
  [self checkSameClass:b];

  if (self == b)
    {
      return [self notZero] && [self notCharacteristicTwo];
    }
  else
    {
      return NO == float_isop (float_id2t (self), float_id2t (b), float_getargs (self));
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
      float_c c;
      assert ([self check]);
      float_ooneg (&c, float_id2t (self), float_getargs (self));
      return float_c2id (self, &c);
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
      float_c c;
      assert ([self check]);
      float_oodbl (&c, float_id2t (self), v, float_getargs (self));
      return float_c2id (self, &c);
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
      float_c c;
      assert ([self check]);
      float_oodbl (&c, float_id2t (self), +1, float_getargs (self));
      return float_c2id (self, &c);
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
      if (1)
	{
	  float_c c;
	  float_ooadd (&c, float_id2t (self), v, float_id2t (b), w, float_getargs (self));
	  return float_c2id (self, &c);
	}
    }

  return nil;			/* to quiet some compilers, e.g. WATCOM */
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
      if (1)
	{
	  float_c c;
	  float_ooadd (&c, float_id2t (self), +1, float_id2t (b), +1, float_getargs (self));
	  return float_c2id (self, &c);
	}
    }

  return nil;
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
      if (1)
	{
	  float_c c;
	  float_ooadd (&c, float_id2t (self), +1, float_id2t (b), -1, float_getargs (self));
	  return float_c2id (self, &c);
	}
    }

  return nil;
}


- one
{
  static id one = nil;
  return (one) ? one : (one = [self floatValue:1]);
}

- minusOne
{
  static id minusOne = nil;
  return (minusOne) ? minusOne : (minusOne = [self floatValue:-1]);
}

- (BOOL) isOne
{
  assert ([self check]);
  return float_isone (float_id2t (self), float_getargs (self));
}

- (BOOL) notOne
{
  assert ([self check]);
  return NO == float_isone (float_id2t (self), float_getargs (self));
}

- (BOOL) isMinusOne
{
  assert ([self check]);
  return float_isminusone (float_id2t (self), float_getargs (self));
}

- (BOOL) notMinusOne
{
  assert ([self check]);
  return NO == float_isminusone (float_id2t (self), float_getargs (self));
}

- square
{
  float_c c;

  if ([self inMonoid] && [self isOne])
    return self;
  if ([self inAdditiveMonoid])
    {
      if ([self isMinusOne])
	return [self one];
      if ([self isZero])
	return self;
    }

  assert ([self check]);
  float_oosqr (&c, float_id2t (self), float_getargs (self));
  return float_c2id (self, &c);
}

- multiply:b
{
  [self checkSameClass:b];

  if (self == b)
    {
      return [self square];
    }
  else
    {
      float_c c;
      if ([self inMonoid])
	{
	  if ([self isOne])
	    return b;
	  if ([b isOne])
	    return self;
	}
      if ([self inAdditiveMonoid])
	{
	  if ([self isZero] || [b isZero])
	    return [self zero];
	  if ([self isMinusOne])
	    return [b negate];
	  if ([b isMinusOne])
	    return [self negate];
	}
      float_oomul (&c, float_id2t (self), float_id2t (b), float_getargs (self));
      return float_c2id (self, &c);
    }
}

- inverse
{
  if ([self inMonoid] && [self isOne])
    return self;
  if ([self inAdditiveMonoid])
    {
      if ([self isMinusOne])
	return self;
      if ([self isZero])
	return nil;
    }
  if (1)
    {
      float_c c;
      assert ([self check]);
      float_ooinv (&c, float_id2t (self), float_getargs (self));
      return float_c2id (self, &c);
    }

  return nil;
}

- divide:b
{
  [self checkSameClass:b];

  if ([self inAdditiveMonoid])
    {
      if ([b isZero])
	return nil;
      if ([self isZero])
	return self;
    }

  if (self == b)
    {
      return [self one];
    }
  else
    {
      if ([self inMonoid])
	{
	  if ([b isOne])
	    return self;
	  if ([self inAdditiveMonoid] && [b isMinusOne])
	    return [self negate];
	}
      if (1)
	{
	  float_c c;
	  BOOL failed = float_oodiv (&c, float_id2t (self), float_id2t (b), float_getargs (self));
	  return (failed) ? nil : float_c2id (self, &c);
	}
    }

  return nil;
}

- _add:(int)v:B multiply:b:(int)w
{
  assert ([self sameClass:B] && [self sameClass:b] && v * v == 1 && w * w == 1);

  if ([self isZero])
    return [B _multiply:b:+w];
  if ([B isZero])
    return [self _negate:v];
  if ([b isZero])
    return [self _negate:v];

  if ([b isOne])
    return [self _add:v:B:+w];
  if ([B isOne])
    return [self _add:v:b:+w];
  if ([b isMinusOne])
    return [self _add:v:B:-w];
  if ([B isMinusOne])
    return [self _add:v:b:-w];

  if (1)
    {
      float_c c;
      float_ooaddmul (&c, float_id2t (self), v, float_id2t (B), float_id2t (b), w, float_getargs (self));
      return float_c2id (self, &c);
    }

  return nil;
}

- _multiply:a:(int)v add:B:(int)w
{
  assert ([self sameClass:a] && [self sameClass:B] && v * v == 1 && w * w == 1);

  if ([self isZero])
    return [B _negate:+w];
  if ([a isZero])
    return [B _negate:+w];
  if ([B isZero])
    return [self _multiply:a:+v];

  if ([self isOne])
    return [a _add:+v:B:+w];
  if ([a isOne])
    return [self _add:+v:B:+w];
  if ([self isMinusOne])
    return [a _add:-v:B:+w];
  if ([a isMinusOne])
    return [self _add:-v:B:+w];

  if (1)
    {
      float_c c;
      float_oomuladd (&c, float_id2t (self), float_id2t (a), v, float_id2t (B), w, float_getargs (self));
      return float_c2id (self, &c);
    }

  return nil;
}

- _multiply:a:(int)v add:B multiply:b:(int)w
{
  assert ([self sameClass:a] && [self sameClass:B] && [self sameClass:b] && v * v == 1 && w * w == 1);

  if ([self isZero])
    return [B _multiply:b:+w];
  if ([a isZero])
    return [B _multiply:b:+w];
  if ([B isZero])
    return [self _multiply:a:+v];
  if ([b isZero])
    return [self _multiply:a:+v];

  if ([self isOne])
    return [a _add:+v:B multiply:b:+w];
  if ([a isOne])
    return [self _add:+v:B multiply:b:+w];
  if ([b isOne])
    return [self _multiply:a:+v add:B:+w];
  if ([B isOne])
    return [self _multiply:a:+v add:b:+w];

  if ([self isMinusOne])
    return [a _add:-v:B multiply:b:+w];
  if ([a isMinusOne])
    return [self _add:-v:B multiply:b:+w];
  if ([b isMinusOne])
    return [self _multiply:a:+v add:B:-w];
  if ([B isMinusOne])
    return [self _multiply:a:+v add:b:-w];

  if (1)
    {
      float_c c;
      float_oomuladdmul (&c, float_id2t (self), float_id2t (a), v, float_id2t (B), float_id2t (b), w, float_getargs (self));
      return float_c2id (self, &c);
    }

  return nil;
}

- str:(STR)aString
{
  return [self floatValue:atof (aString)];
}


- (BOOL) printsLeadingSign
{
  return [self sign] < 0;
}

- printOn:(IOD)aFile
{
  fprintf (aFile, "%g", [self floatValue]);
  return self;
}

@end
 
