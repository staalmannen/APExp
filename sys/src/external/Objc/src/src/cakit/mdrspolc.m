#include "cakit.h"

static modp_args 
modp_getargs (id self)
{
  modp_args args;
  args.p = [self modulus];
  return args;
}

static int 
modp_size (modp_args args)
{
  return 1;			/* pointer increment */
}

static int 
modp_bsize (modp_args args)
{
  return sizeof (modp_c);	/* bytes */
}

static modp_t 
modp_id2t (id object)
{
  return [object modp_value];	/* read-only */
}

static modp_t 
modp_id2ref (id object, modp_c * ref)
{
  return [object modp_value];	/* read-only, scratch space "ref" */
}

static modp_c *
modp_id2c (id object)
{
  return [object modp_reference];	/* write for inplace arithmetic */
}

static id 
modp_t2id (id proto, modp_t f)
{
  return [proto modp_value:f];	/* new object containing copy of "f" */
}

static id 
modp_c2id (id proto, modp_c * c)
{
  return [proto modp_reference:c];	/* new object containing "c" */
}

static modp_t 
modp_fromintvalue (int i, modp_args args)
{
  modp_t red;

  if (i == 0)
    return 0;
  if (i < 0)
    {
      red = -i;
      red %= args.p;		/* it's dangerous to % int & unsigned */
      red = (red) ? args.p - red : 0;
    }
  else
    {
      red = i;
      red %= args.p;		/* dito */
    }

  return red;
}

static int 
modp_check (modp_t self, modp_args args)
{
  assert (self < args.p);
  return 1;
}

static modp_t 
modp_zero (modp_args args)
{
  return 0;
}

static modp_t 
modp_one (modp_args args)
{
  return 1;
}

static unsigned 
modp_hash (modp_t a, modp_args args)
{
  return a;
}

static int 
modp_iseq (modp_t a, modp_t b, modp_args args)
{
  assert (modp_check (a, args) && modp_check (b, args));
  return (a == b);
}

static int 
modp_isop (modp_t a, modp_t b, modp_args args)
{
  assert (modp_check (a, args) && modp_check (b, args));
  return (a == 0) ? (b == 0) : (a + b == args.p);
}

static int 
modp_iszero (modp_t a, modp_args args)
{
  return a == 0;
}

static int 
modp_isone (modp_t a, modp_args args)
{
  return a == 1;
}

static int 
modp_isminusone (modp_t a, modp_args args)
{
  return (a + 1) == args.p;
}

static modp_t 
modp_neg (modp_t a, modp_args args)
{
  assert (modp_check (a, args));
  return (a) ? args.p - a : 0;
}

static modp_t 
modp_dbl (modp_t a, modp_args args)
{
  modp_t c = a + a;
  assert (args.p != 2 && modp_check (a, args));
  if (c)
    return (c < args.p) ? c : c - args.p;
  else
    return 0;
}

static modp_t 
modp_add (modp_t a, modp_t b, modp_args args)
{
  modp_t c = a + b;
  assert (modp_check (a, args) && modp_check (b, args));
  return ((c >= args.p) ? c - args.p : c);	/* compiles better than c<p?c:c-p */
}

static modp_t 
modp_sub (modp_t a, modp_t b, modp_args args)
{
  assert (modp_check (a, args) && modp_check (b, args));
  return (a >= b) ? (a - b) : (args.p - (b - a));
}

static modp_t 
modp_mul (modp_t a, modp_t b, modp_args args)
{
  unsigned c = a * b;		/* limitation to 16bits to be able to do this
				 * russian peasant 50% slower
				 */
  assert (sizeof (unsigned) == 2 * sizeof (modp_t));
  return c % args.p;
}

static modp_t 
modp_sqr (modp_t a, modp_args args)
{
  unsigned c = a * a;
  assert (sizeof (unsigned) == 2 * sizeof (modp_t));
  return c % args.p;
}

static modp_t 
modp_inv (modp_t x, modp_args args)
{
  unsigned q, s;
  int u1, u2, us;		/* intermediate values can be negative */
  modp_t a, b, inv;

  assert (x != 0 && x != 1 && x + 1 != args.p);

  a = x;
  b = args.p;
  u1 = 1;
  u2 = 0;
  while (b)
    {
      s = a % b;
      q = a / b;
      a = b;
      b = s;
      u1 -= q * u2;
      us = u1;
      u1 = u2;
      u2 = us;
    }

  inv = ((u1 < 0) ? u1 + args.p : u1);	/* keep result positive */

  assert (modp_check (inv, args));
  assert (modp_isone (modp_mul (x, inv, args), args));
  return inv;
}

static modp_t 
modp_div (modp_t a, modp_t b, modp_args args)
{
  assert (b != 0);
  return modp_mul (a, modp_inv (b, args), args);
}

static modp_t 
modp_pow (modp_t a, int n, modp_args args)
{
  modp_t o;

  if (n == 0)
    return modp_one (args);
  if (n == 1)
    return a;
  if (n == 2)
    return modp_sqr (a, args);

  o = modp_one (args);
  while (n > 1)
    {
      if (n & 1)
	o = modp_mul (o, a, args);
      a = modp_sqr (a, args);
      n >>= 1;
    }

  return modp_mul (o, a, args);
}

#if !modp_isvalue
#error "modp_copy_val.fab should not be included"
#endif

static void 
modp_clear (modp_c * c, modp_args args)
{
  /* nothing to clear, but the following might help... */
#ifndef DEBUG
  *c = (modp_t) 0xcafebabe;
#endif
}

static void 
modp_copy (modp_c * c, modp_t a, modp_args args)
{
  *c = a;
}

static void 
modp_deepcopy (modp_c * c, modp_t a, modp_args args)
{
  *c = a;
}

static void 
modp_move (modp_c * c, modp_c * a, modp_args args)
{
  *c = *a;
#ifndef DEBUG
  *a = (modp_t) 0xcafebabe;
#endif
}

#if !modp_isvalue
#error "modp_add_val.fab should not be included"
#endif

static void 
modp_oozero (modp_c * c, modp_args args)
{
  *c = modp_zero (args);
}

static void 
modp_inzero (modp_c * a, modp_args args)
{
  *a = modp_zero (args);
}

static void 
modp_inneg (modp_c * a, modp_args args)
{
  *a = modp_neg (*a, args);
}

static void 
modp_ooneg (modp_c * c, modp_t a, modp_args args)
{
  *c = modp_neg (a, args);
}

static modp_t 
modp_dblv (modp_t a, int v, modp_args args)
{
  modp_t c = modp_dbl (a, args);
  return (v == +1) ? c : modp_neg (c, args);
}

static void 
modp_indbl (modp_c * a, int v, modp_args args)
{
  *a = modp_dblv (*a, v, args);
}

static void 
modp_oodbl (modp_c * c, modp_t a, int v, modp_args args)
{
  *c = modp_dblv (a, v, args);
}

static modp_t 
modp_addvw (modp_t a, int v, modp_t b, int w, modp_args args)
{
  modp_t c;
  assert (v * v == +1 && w * w == 1);

  if (v == +1)
    {
      if (w == +1)
	{
	  c = modp_add (a, b, args);
	}
      else
	{
	  c = modp_sub (a, b, args);
	}
    }
  else
    {
      if (w == +1)
	{
	  c = modp_sub (b, a, args);
	}
      else
	{
	  c = modp_neg (modp_add (a, b, args), args);
	}
    }

  return c;
}

static void 
modp_inadd (modp_c * a, int v, modp_t b, int w, modp_args args)
{
  *a = modp_addvw (*a, v, b, w, args);
}

static void 
modp_ooadd (modp_c * c, modp_t a, int v, modp_t b, int w, modp_args args)
{
  *c = modp_addvw (a, v, b, w, args);
}
#if !modp_isvalue
#error "modp_mul_val.fab should not be included"
#endif

static void 
modp_insqr (modp_c * a, modp_args args)
{
  *a = modp_sqr (*a, args);
}

static void 
modp_oosqr (modp_c * c, modp_t a, modp_args args)
{
  *c = modp_sqr (a, args);
}

static void 
modp_inmul (modp_c * a, modp_t b, modp_args args)
{
  *a = modp_mul (*a, b, args);
}

static void 
modp_oomul (modp_c * c, modp_t a, modp_t b, modp_args args)
{
  *c = modp_mul (a, b, args);
}
#if !modp_isvalue
#error "modp_inv_val.fab should not be included"
#endif

static void 
modp_ininv (modp_c * a, modp_args args)
{
  *a = modp_inv (*a, args);
}

static void 
modp_ooinv (modp_c * c, modp_t a, modp_args args)
{
  *c = modp_inv (a, args);
}

#if !modp_isvalue
#error "modp_div_val.fab should not be included"
#endif

static void 
modp_indiv (modp_c * a, modp_t b, modp_args args)
{
  *a = modp_div (*a, b, args);
}

static BOOL 
modp_oodiv (modp_c * c, modp_t a, modp_t b, modp_args args)
{
  *c = modp_div (a, b, args);
  return SUCCESS;
}
#if !modp_isvalue
#error "modp_add_val.fab should not be included"
#endif

static modp_t 
modp_mulv (modp_t a, modp_t b, int v, modp_args args)
{
  modp_t c = modp_mul (a, b, args);
  return (v == +1) ? c : modp_neg (c, args);
}

static void 
modp_inmulv (modp_c * a, modp_t b, int v, modp_args args)
{
  *a = modp_mulv (*a, b, v, args);
}

static void 
modp_oomulv (modp_c * c, modp_t a, modp_t b, int v, modp_args args)
{
  *c = modp_mulv (a, b, v, args);
}

static modp_t 
modp_addmul (modp_t a, int v, modp_t b, modp_t s, int w, modp_args args)
{
  return modp_addvw (a, v, modp_mul (b, s, args), w, args);
}

static modp_t 
modp_addsqr (modp_t a, int v, modp_t b, int w, modp_args args)
{
  return modp_addvw (a, v, modp_sqr (b, args), w, args);
}

static modp_t 
modp_muladd (modp_t a, modp_t s, int v, modp_t b, int w, modp_args args)
{
  return modp_addvw (modp_mul (a, s, args), v, b, w, args);
}

static modp_t 
modp_muladdmul (modp_t a, modp_t s, int v, modp_t b, modp_t t, int w, modp_args args)
{
  return modp_addvw (modp_mul (a, s, args), v, modp_mul (b, t, args), w, args);
}

static void 
modp_inaddmul (modp_c * a, int v, modp_t b, modp_t t, int w, modp_args args)
{
  *a = modp_addmul (*a, v, b, t, w, args);
}

static void 
modp_ooaddmul (modp_c * c, modp_t a, int v, modp_t b, modp_t t, int w, modp_args args)
{
  *c = modp_addmul (a, v, b, t, w, args);
}

static void 
modp_inaddsqr (modp_c * a, int v, modp_t b, int w, modp_args args)
{
  *a = modp_addsqr (*a, v, b, w, args);
}

static void 
modp_ooaddsqr (modp_c * c, modp_t a, int v, modp_t b, int w, modp_args args)
{
  *c = modp_addsqr (a, v, b, w, args);
}

static void 
modp_inmuladd (modp_c * a, modp_t s, int v, modp_t b, int w, modp_args args)
{
  *a = modp_muladd (*a, s, v, b, w, args);
}

static void 
modp_oomuladd (modp_c * c, modp_t a, modp_t s, int v, modp_t b, int w, modp_args args)
{
  *c = modp_muladd (a, s, v, b, w, args);
}

static void 
modp_inmuladdmul (modp_c * a, modp_t s, int v, modp_t b, modp_t t, int w, modp_args args)
{
  *a = modp_muladdmul (*a, s, v, b, t, w, args);
}

static void 
modp_oomuladdmul (modp_c * c, modp_t a, modp_t s, int v, modp_t b, modp_t t, int w, modp_args args)
{
  *c = modp_muladdmul (a, s, v, b, t, w, args);
}
static void 
modp_args_fileOut (id aFiler, modp_args * args)
{
}
static void 
modp_args_fileIn (id aFiler, modp_args * args)
{
}

static void 
modp_fileOut (id aFiler, modp_c * c, modp_args args)
{
  [aFiler fileOut:c type:'S'];
}

static void 
modp_fileIn (id aFiler, modp_c * c, modp_args args)
{
  [aFiler fileIn:c type:'S'];
}


/*
 * Computer Algebra Kit (c) 1993,00 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: mdrspolc.m,v 1.6 2000/10/12 14:40:26 stes Exp $
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

static int 
unimonom_size (unimonom_args args)
{
  return 1;
}

static int 
unimonom_bsize (unimonom_args args)
{
  return sizeof (unimonom_t);
}

static int 
unimonom_check (unimonom_t self, unimonom_args args)
{
  assert (self >= 0);
  return 1;
}

static void 
unimonom_clear (unimonom_c * c, unimonom_args args)
{
  /* nothing to clear, but the following might help... */
#ifndef DEBUG
  *c = (unimonom_t) 0xcafebabe;
#endif
}

static void 
unimonom_copy (unimonom_c * c, unimonom_t a, unimonom_args args)
{
  *c = a;
}

static void 
unimonom_move (unimonom_c * c, unimonom_c * a, unimonom_args args)
{
  *c = *a;
#ifndef DEBUG
  *a = (unimonom_t) 0xcafebabe;
#endif
}

static void 
unimonom_args_fileOut (id aFiler, unimonom_args * args)
{
}
static void 
unimonom_args_fileIn (id aFiler, unimonom_args * args)
{
}

static void 
unimonom_fileOut (id aFiler, unimonom_c * c, unimonom_args args)
{
  [aFiler fileOut:c type:'i'];
}

static void 
unimonom_fileIn (id aFiler, unimonom_c * c, unimonom_args args)
{
  [aFiler fileIn:c type:'i'];
}

static unsigned 
unimonom_hash (unimonom_t self, unimonom_args args)
{
  return self;
}

static int 
unimonom_deg (unimonom_t self, unimonom_args args)
{
  return self;
}

static int 
unimonom_isone (unimonom_t self, unimonom_args args)
{
  return self == 0;
}

static int 
unimonom_iseq (unimonom_t a, unimonom_t b, unimonom_args args)
{
  return a == b;
}

static int 
unimonom_iseqmul (unimonom_t a, unimonom_t x, unimonom_t b, unimonom_args args)
{
  return a == x + b;
}

static int 
unimonom_cmp (unimonom_t a, unimonom_t b, unimonom_args args)
{
  return a - b;
}

static int 
unimonom_cmpmul (unimonom_t a, unimonom_t x, unimonom_t b, unimonom_args args)
{
  return a - x - b;
}

static void 
unimonom_oomul (unimonom_c * c, unimonom_t a, unimonom_t b, unimonom_args args)
{
  *c = a + b;
}

static void 
unimonom_inmul (unimonom_c * c, unimonom_t b, unimonom_args args)
{
  *c += b;
}

static BOOL 
unimonom_oodiv (unimonom_c * c, unimonom_t a, unimonom_t b, unimonom_args args)
{
  if (a < b)
    {
      return FAILURE;
    }
  else
    {
      *c = a - b;
      return SUCCESS;
    }
}

static void 
unimonom_indiv (unimonom_c * c, unimonom_t b, unimonom_args args)
{
  if (*c < b)
    {
      fprintf (stderr, "Division not Exact\n");
      abort ();
    }				/* should stay */
  *c -= b;
}

/*
 * scalar is accessed by the C "->" operator since having variable sized
 * scalars _and_ monomials gets difficult on machines like the DEC alpha
 * (where we'd have to manually pad to get pointer aligned structures).
 * 
 * the monomial (exponent) is however not accessed by the C "->" operator
 * but rather by functions that can take offsets as arguments
 * this is important the monomials in variable dense representation
 * (fixarray of exp)
 *
 * stes - mar31, 1997 - CHANGES: for DEC alpha coefficient needs to be aligned
 * properly, put it before the monomial and drop the idea of variable sized
 * coefficients.
 */

static unimonom_c *
modp_vardnsrecdegspsterm_monom_cval (modp_vardnsrecdegspsterm_t self)
{
  return &self->data;
}

static unimonom_t 
modp_vardnsrecdegspsterm_monom (modp_vardnsrecdegspsterm_t self)
{
#if unimonom_pervalue
  return self->data;
#else
  return modp_vardnsrecdegspsterm_monom_cval (self);
#endif
}

/* stes - mar31,1997
 * change for DEC alpha to exclude varsized scalars
 */

static modp_c *
modp_vardnsrecdegspsterm_scal_cval (modp_vardnsrecdegspsterm_t self, modp_vardnsrecdegspsterm_args args)
{
  return &self->scal;
}

static modp_t 
modp_vardnsrecdegspsterm_scal (modp_vardnsrecdegspsterm_t self, modp_vardnsrecdegspsterm_args args)
{
#if modp_pervalue
  return self->scal;
#else
  return modp_vardnsrecdegspsterm_scal_cval (self, args);
#endif
}

static int 
modp_vardnsrecdegspsterm_check (modp_vardnsrecdegspsterm_t self, modp_vardnsrecdegspsterm_args args)
{
  assert (modp_check (modp_vardnsrecdegspsterm_scal (self, args), args.sargs));
  assert (!modp_iszero (modp_vardnsrecdegspsterm_scal (self, args), args.sargs));
  assert (unimonom_check (modp_vardnsrecdegspsterm_monom (self), args.margs));
  return 1;
}

static int 
modp_vardnsrecdegspsterm_bsize (modp_vardnsrecdegspsterm_args args)
{
  /* this is sizeof(unimonom_c) too much but why bother ? */
  return sizeof (struct modp_vardnsrecdegspsterm) + unimonom_bsize (args.margs);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_alloc (modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_t p;
  int n = modp_vardnsrecdegspsterm_bsize (args);
  p = (modp_vardnsrecdegspsterm_t) OC_Malloc (n);
#if OBJC_REFCNT
  memset (p, 0, n);
#endif
  return p;
}

static void 
modp_vardnsrecdegspsterm_clear (modp_vardnsrecdegspsterm_t self, modp_vardnsrecdegspsterm_args args)
{
  unimonom_clear (modp_vardnsrecdegspsterm_monom_cval (self), args.margs);
  modp_clear (modp_vardnsrecdegspsterm_scal_cval (self, args), args.sargs);
}

static void 
modp_vardnsrecdegspsterm_free (modp_vardnsrecdegspsterm_t self, modp_vardnsrecdegspsterm_args args)
{
  /* invalidating links not always helps : buggy code might work because
   * links were cleared...        self->nlink = NULL;self->plink = NULL;
   */
  OC_Free (self);
}

static int 
modp_vardnsrecdegspsterm_cmp (modp_vardnsrecdegspsterm_t a, modp_vardnsrecdegspsterm_t b, modp_vardnsrecdegspsterm_args args)
{
  assert (modp_vardnsrecdegspsterm_check (a, args) && modp_vardnsrecdegspsterm_check (b, args));
  return unimonom_cmp (modp_vardnsrecdegspsterm_monom (a), modp_vardnsrecdegspsterm_monom (b), args.margs);
}

static int 
modp_vardnsrecdegspsterm_cmpmonom (modp_vardnsrecdegspsterm_t a, unimonom_t b, modp_vardnsrecdegspsterm_args args)
{
  assert (modp_vardnsrecdegspsterm_check (a, args) && unimonom_check (b, args.margs));
  return unimonom_cmp (modp_vardnsrecdegspsterm_monom (a), b, args.margs);
}

static int 
modp_vardnsrecdegspsterm_cmpmul (modp_vardnsrecdegspsterm_t a, modp_vardnsrecdegspsterm_t b, unimonom_t m, modp_vardnsrecdegspsterm_args args)
{
  assert (modp_vardnsrecdegspsterm_check (a, args) && modp_vardnsrecdegspsterm_check (b, args));
  assert (unimonom_check (m, args.margs));
  return unimonom_cmpmul (modp_vardnsrecdegspsterm_monom (a), modp_vardnsrecdegspsterm_monom (b), m, args.margs);
}

static int 
modp_vardnsrecdegspsterm_deg (modp_vardnsrecdegspsterm_t a, modp_vardnsrecdegspsterm_args args)
{
  return unimonom_deg (modp_vardnsrecdegspsterm_monom (a), args.margs);
}

static int 
modp_vardnsrecdegspsterm_iszero (modp_vardnsrecdegspsterm_t self, modp_vardnsrecdegspsterm_args args)
{
  return modp_iszero (modp_vardnsrecdegspsterm_scal (self, args), args.sargs);
}

static int 
modp_vardnsrecdegspsterm_isone (modp_vardnsrecdegspsterm_t self, modp_vardnsrecdegspsterm_args args)
{
  return modp_isone (modp_vardnsrecdegspsterm_scal (self, args), args.sargs) && unimonom_isone (modp_vardnsrecdegspsterm_monom (self), args.margs);
}

static int 
modp_vardnsrecdegspsterm_isminusone (modp_vardnsrecdegspsterm_t self, modp_vardnsrecdegspsterm_args args)
{
  return modp_isminusone (modp_vardnsrecdegspsterm_scal (self, args), args.sargs) && unimonom_isone (modp_vardnsrecdegspsterm_monom (self), args.margs);
}

static int 
modp_vardnsrecdegspsterm_iseq (modp_vardnsrecdegspsterm_t a, modp_vardnsrecdegspsterm_t b, modp_vardnsrecdegspsterm_args args)
{
  assert (modp_vardnsrecdegspsterm_check (a, args) && modp_vardnsrecdegspsterm_check (b, args));
  return unimonom_iseq (modp_vardnsrecdegspsterm_monom (a), modp_vardnsrecdegspsterm_monom (b), args.margs) && modp_iseq (modp_vardnsrecdegspsterm_scal (a, args), modp_vardnsrecdegspsterm_scal (b, args), args.sargs);
}

static int 
modp_vardnsrecdegspsterm_isop (modp_vardnsrecdegspsterm_t a, modp_vardnsrecdegspsterm_t b, modp_vardnsrecdegspsterm_args args)
{
  assert (modp_vardnsrecdegspsterm_check (a, args) && modp_vardnsrecdegspsterm_check (b, args));
  return unimonom_iseq (modp_vardnsrecdegspsterm_monom (a), modp_vardnsrecdegspsterm_monom (b), args.margs) && modp_isop (modp_vardnsrecdegspsterm_scal (a, args), modp_vardnsrecdegspsterm_scal (b, args), args.sargs);
}

static void 
modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A)
{
  C->nlink = A;
  A->plink = C;
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A)
{
  modp_vardnsrecdegspsterm_glue (C, A);
  return A;
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_delete (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_t C = A->nlink;
  modp_vardnsrecdegspsterm_glue (A->plink, C);
  modp_vardnsrecdegspsterm_clear (A, args);
  modp_vardnsrecdegspsterm_free (A, args);
  return C;
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_condcns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t new, modp_vardnsrecdegspsterm_args args)
{
  if (modp_vardnsrecdegspsterm_iszero (new, args))
    {
      modp_vardnsrecdegspsterm_clear (new, args);
      modp_vardnsrecdegspsterm_free (new, args);
      return C;
    }
  else
    {
      assert (modp_vardnsrecdegspsterm_check (new, args));
      return modp_vardnsrecdegspsterm_cns (C, new);
    }
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_conddelete (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_args args)
{
  if (modp_vardnsrecdegspsterm_iszero (A, args))
    {
      return modp_vardnsrecdegspsterm_delete (A, args);
    }
  else
    {
      return A->nlink;
    }
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_copymonomsc_cns (modp_vardnsrecdegspsterm_t C, unimonom_t m, modp_t s, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_t new = modp_vardnsrecdegspsterm_alloc (args);

  modp_copy (modp_vardnsrecdegspsterm_scal_cval (new, args), s, args.sargs);
  unimonom_copy (modp_vardnsrecdegspsterm_monom_cval (new), m, args.margs);

  assert (modp_vardnsrecdegspsterm_check (new, args));
  return modp_vardnsrecdegspsterm_cns (C, new);
}

static void 
modp_vardnsrecdegspsterm_copymonomsc (modp_vardnsrecdegspsterm_t C, unimonom_t m, modp_t s, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspsterm_copymonomsc_cns (C, m, s, args), CT);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_deepcopymonomsc_cns (modp_vardnsrecdegspsterm_t C, unimonom_t m, modp_t s, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_t new = modp_vardnsrecdegspsterm_alloc (args);

  modp_deepcopy (modp_vardnsrecdegspsterm_scal_cval (new, args), s, args.sargs);
  unimonom_copy (modp_vardnsrecdegspsterm_monom_cval (new), m, args.margs);

  assert (modp_vardnsrecdegspsterm_check (new, args));
  return modp_vardnsrecdegspsterm_cns (C, new);
}

static void 
modp_vardnsrecdegspsterm_deepcopymonomsc (modp_vardnsrecdegspsterm_t C, unimonom_t m, modp_t s, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspsterm_deepcopymonomsc_cns (C, m, s, args), CT);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_copy_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_args args)
{
  return modp_vardnsrecdegspsterm_copymonomsc_cns (C, modp_vardnsrecdegspsterm_monom (A), modp_vardnsrecdegspsterm_scal (A, args), args);
}

static void 
modp_vardnsrecdegspsterm_copy (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspsterm_copy_cns (C, A, args), CT);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_deepcopy_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_args args)
{
  return modp_vardnsrecdegspsterm_deepcopymonomsc_cns (C, modp_vardnsrecdegspsterm_monom (A), modp_vardnsrecdegspsterm_scal (A, args), args);
}

static void 
modp_vardnsrecdegspsterm_deepcopy (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspsterm_deepcopy_cns (C, A, args), CT);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_ooneg_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_t new = modp_vardnsrecdegspsterm_alloc (args);
  assert (modp_vardnsrecdegspsterm_iszero (A, args) == NO);

  modp_ooneg (modp_vardnsrecdegspsterm_scal_cval (new, args), modp_vardnsrecdegspsterm_scal (A, args), args.sargs);
  unimonom_copy (modp_vardnsrecdegspsterm_monom_cval (new), modp_vardnsrecdegspsterm_monom (A), args.margs);

  return modp_vardnsrecdegspsterm_cns (C, new);
}

static void 
modp_vardnsrecdegspsterm_ooneg (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspsterm_ooneg_cns (C, A, args), CT);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_inneg (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_args args)
{
  assert (modp_vardnsrecdegspsterm_iszero (A, args) == NO);
  modp_inneg (modp_vardnsrecdegspsterm_scal_cval (A, args), args.sargs);
  assert (modp_vardnsrecdegspsterm_iszero (A, args) == NO);
  return A->nlink;
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_oonegv_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, int v, modp_vardnsrecdegspsterm_args args)
{
  return (v == -1) ? modp_vardnsrecdegspsterm_ooneg_cns (C, A, args) : modp_vardnsrecdegspsterm_copy_cns (C, A, args);
}

static void 
modp_vardnsrecdegspsterm_oonegv (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, int v, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspsterm_oonegv_cns (C, A, v, args), CT);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_innegv (modp_vardnsrecdegspsterm_t A, int v, modp_vardnsrecdegspsterm_args args)
{
  return (v == -1) ? modp_vardnsrecdegspsterm_inneg (A, args) : A->nlink;
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_oodbl_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, int v, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_t new = modp_vardnsrecdegspsterm_alloc (args);
  assert (modp_vardnsrecdegspsterm_iszero (A, args) == NO);

  modp_oodbl (modp_vardnsrecdegspsterm_scal_cval (new, args), modp_vardnsrecdegspsterm_scal (A, args), v, args.sargs);
  unimonom_copy (modp_vardnsrecdegspsterm_monom_cval (new), modp_vardnsrecdegspsterm_monom (A), args.margs);

  return modp_vardnsrecdegspsterm_condcns (C, new, args);
}

static void 
modp_vardnsrecdegspsterm_oodbl (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, int v, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspsterm_oodbl_cns (C, A, v, args), CT);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_indbl (modp_vardnsrecdegspsterm_t A, int v, modp_vardnsrecdegspsterm_args args)
{
  assert (modp_vardnsrecdegspsterm_iszero (A, args) == NO);
  modp_indbl (modp_vardnsrecdegspsterm_scal_cval (A, args), v, args.sargs);
  return modp_vardnsrecdegspsterm_conddelete (A, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_ooaddsc_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, int v, modp_t B, int w, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_t new = modp_vardnsrecdegspsterm_alloc (args);
  modp_ooadd (modp_vardnsrecdegspsterm_scal_cval (new, args), modp_vardnsrecdegspsterm_scal (A, args), v, B, w, args.sargs);
  unimonom_copy (modp_vardnsrecdegspsterm_monom_cval (new), modp_vardnsrecdegspsterm_monom (A), args.margs);
  return modp_vardnsrecdegspsterm_condcns (C, new, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_inaddsc (modp_vardnsrecdegspsterm_t A, int v, modp_t B, int w, modp_vardnsrecdegspsterm_args args)
{
  modp_inadd (modp_vardnsrecdegspsterm_scal_cval (A, args), v, B, w, args.sargs);
  return modp_vardnsrecdegspsterm_conddelete (A, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_ooadd_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, int v, modp_vardnsrecdegspsterm_t B, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (0 == modp_vardnsrecdegspsterm_cmp (A, B, args));
  assert (modp_vardnsrecdegspsterm_iszero (A, args) == NO && modp_vardnsrecdegspsterm_iszero (B, args) == NO);
  return modp_vardnsrecdegspsterm_ooaddsc_cns (C, A, v, modp_vardnsrecdegspsterm_scal (B, args), w, args);
}

static void 
modp_vardnsrecdegspsterm_ooadd (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, int v, modp_vardnsrecdegspsterm_t B, int w, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspsterm_ooadd_cns (C, A, v, B, w, args), CT);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_inadd (modp_vardnsrecdegspsterm_t A, int v, modp_vardnsrecdegspsterm_t B, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (0 == modp_vardnsrecdegspsterm_cmp (A, B, args));
  assert (modp_vardnsrecdegspsterm_iszero (A, args) == NO && modp_vardnsrecdegspsterm_iszero (B, args) == NO);
  return modp_vardnsrecdegspsterm_inaddsc (A, v, modp_vardnsrecdegspsterm_scal (B, args), w, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_oomulsc_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_t s, int v, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_t new = modp_vardnsrecdegspsterm_alloc (args);

  modp_oomulv (modp_vardnsrecdegspsterm_scal_cval (new, args), modp_vardnsrecdegspsterm_scal (A, args), s, v, args.sargs);
  unimonom_copy (modp_vardnsrecdegspsterm_monom_cval (new), modp_vardnsrecdegspsterm_monom (A), args.margs);

  return modp_vardnsrecdegspsterm_condcns (C, new, args);
}

static void 
modp_vardnsrecdegspsterm_oomulsc (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_t s, int v, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspsterm_oomulsc_cns (C, A, s, v, args), CT);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_inmulsc (modp_vardnsrecdegspsterm_t A, modp_t s, int v, modp_vardnsrecdegspsterm_args args)
{
  modp_inmulv (modp_vardnsrecdegspsterm_scal_cval (A, args), s, v, args.sargs);
  return modp_vardnsrecdegspsterm_conddelete (A, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_oomulmonomsc_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, unimonom_t m, modp_t s, int v, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_t new = modp_vardnsrecdegspsterm_alloc (args);

  modp_oomulv (modp_vardnsrecdegspsterm_scal_cval (new, args), modp_vardnsrecdegspsterm_scal (A, args), s, v, args.sargs);
  unimonom_oomul (modp_vardnsrecdegspsterm_monom_cval (new), modp_vardnsrecdegspsterm_monom (A), m, args.margs);

  return modp_vardnsrecdegspsterm_condcns (C, new, args);
}

static void 
modp_vardnsrecdegspsterm_oomulmonomsc (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, unimonom_t m, modp_t s, int v, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspsterm_oomulmonomsc_cns (C, A, m, s, v, args), CT);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_inmulmonomsc (modp_vardnsrecdegspsterm_t A, unimonom_t m, modp_t s, int v, modp_vardnsrecdegspsterm_args args)
{
  modp_inmulv (modp_vardnsrecdegspsterm_scal_cval (A, args), s, v, args.sargs);
  unimonom_inmul (modp_vardnsrecdegspsterm_monom_cval (A), m, args.margs);

  return modp_vardnsrecdegspsterm_conddelete (A, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_ooaddscmulsc_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, int v, modp_t B, modp_t t, int w, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_t new = modp_vardnsrecdegspsterm_alloc (args);

  modp_ooaddmul (modp_vardnsrecdegspsterm_scal_cval (new, args), modp_vardnsrecdegspsterm_scal (A, args), v, B, t, w, args.sargs);
  unimonom_copy (modp_vardnsrecdegspsterm_monom_cval (new), modp_vardnsrecdegspsterm_monom (A), args.margs);

  return modp_vardnsrecdegspsterm_condcns (C, new, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_inaddscmulsc (modp_vardnsrecdegspsterm_t A, int v, modp_t B, modp_t t, int w, modp_vardnsrecdegspsterm_args args)
{
  modp_inaddmul (modp_vardnsrecdegspsterm_scal_cval (A, args), v, B, t, w, args.sargs);
  return modp_vardnsrecdegspsterm_conddelete (A, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_ooaddmulsc_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, int v, modp_vardnsrecdegspsterm_t B, modp_t t, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (0 == (modp_vardnsrecdegspsterm_cmp (A, B, args)));
  return modp_vardnsrecdegspsterm_ooaddscmulsc_cns (C, A, v, modp_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_ooaddmulmonomsc_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, int v, modp_vardnsrecdegspsterm_t B, unimonom_t m, modp_t t, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (0 == (modp_vardnsrecdegspsterm_cmpmul (A, B, m, args)));
  return modp_vardnsrecdegspsterm_ooaddscmulsc_cns (C, A, v, modp_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static void 
modp_vardnsrecdegspsterm_ooaddmulsc (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, int v, modp_vardnsrecdegspsterm_t B, modp_t t, int w, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspsterm_ooaddmulsc_cns (C, A, v, B, t, w, args), CT);
}

static void 
modp_vardnsrecdegspsterm_ooaddmulmonomsc (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, int v, modp_vardnsrecdegspsterm_t B, unimonom_t m, modp_t t, int w, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspsterm_ooaddmulmonomsc_cns (C, A, v, B, m, t, w, args), CT);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_inaddmulsc (modp_vardnsrecdegspsterm_t A, int v, modp_vardnsrecdegspsterm_t B, modp_t t, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (0 == (modp_vardnsrecdegspsterm_cmp (A, B, args)));
  return modp_vardnsrecdegspsterm_inaddscmulsc (A, v, modp_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_inaddmulmonomsc (modp_vardnsrecdegspsterm_t A, int v, modp_vardnsrecdegspsterm_t B, unimonom_t m, modp_t t, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (0 == (modp_vardnsrecdegspsterm_cmpmul (A, B, m, args)));
  return modp_vardnsrecdegspsterm_inaddscmulsc (A, v, modp_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_oomulscaddsc_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_t s, int v, modp_t B, int w, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_t new = modp_vardnsrecdegspsterm_alloc (args);

  modp_oomuladd (modp_vardnsrecdegspsterm_scal_cval (new, args), modp_vardnsrecdegspsterm_scal (A, args), s, v, B, w, args.sargs);
  unimonom_copy (modp_vardnsrecdegspsterm_monom_cval (new), modp_vardnsrecdegspsterm_monom (A), args.margs);

  return modp_vardnsrecdegspsterm_condcns (C, new, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_inmulscaddsc (modp_vardnsrecdegspsterm_t A, modp_t s, int v, modp_t B, int w, modp_vardnsrecdegspsterm_args args)
{
  modp_inmuladd (modp_vardnsrecdegspsterm_scal_cval (A, args), s, v, B, w, args.sargs);
  return modp_vardnsrecdegspsterm_conddelete (A, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_oomulscadd_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_t s, int v, modp_vardnsrecdegspsterm_t B, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (0 == (modp_vardnsrecdegspsterm_cmp (A, B, args)));
  return modp_vardnsrecdegspsterm_oomulscaddsc_cns (C, A, s, v, modp_vardnsrecdegspsterm_scal (B, args), w, args);
}

static void 
modp_vardnsrecdegspsterm_oomulscadd (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_t s, int v, modp_vardnsrecdegspsterm_t B, int w, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspsterm_oomulscadd_cns (C, A, s, v, B, w, args), CT);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_inmulscadd (modp_vardnsrecdegspsterm_t A, modp_t s, int v, modp_vardnsrecdegspsterm_t B, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (0 == (modp_vardnsrecdegspsterm_cmp (A, B, args)));
  return modp_vardnsrecdegspsterm_inmulscaddsc (A, s, v, modp_vardnsrecdegspsterm_scal (B, args), w, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_oomulscaddscmulsc_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_t s, int v, modp_t B, modp_t t, int w, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_t new = modp_vardnsrecdegspsterm_alloc (args);
  modp_oomuladdmul (modp_vardnsrecdegspsterm_scal_cval (new, args), modp_vardnsrecdegspsterm_scal (A, args), s, v, B, t, w, args.sargs);
  unimonom_copy (modp_vardnsrecdegspsterm_monom_cval (new), modp_vardnsrecdegspsterm_monom (A), args.margs);

  return modp_vardnsrecdegspsterm_condcns (C, new, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_inmulscaddscmulsc (modp_vardnsrecdegspsterm_t A, modp_t s, int v, modp_t B, modp_t t, int w, modp_vardnsrecdegspsterm_args args)
{
  modp_inmuladdmul (modp_vardnsrecdegspsterm_scal_cval (A, args), s, v, B, t, w, args.sargs);
  return modp_vardnsrecdegspsterm_conddelete (A, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_oomulscaddmulsc_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_t s, int v, modp_vardnsrecdegspsterm_t B, modp_t t, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (0 == (modp_vardnsrecdegspsterm_cmp (A, B, args)));
  return modp_vardnsrecdegspsterm_oomulscaddscmulsc_cns (C, A, s, v, modp_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_oomulscaddmulmonomsc_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_t s, int v, modp_vardnsrecdegspsterm_t B, unimonom_t m, modp_t t, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (0 == (modp_vardnsrecdegspsterm_cmpmul (A, B, m, args)));
  return modp_vardnsrecdegspsterm_oomulscaddscmulsc_cns (C, A, s, v, modp_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static void 
modp_vardnsrecdegspsterm_oomulscaddmulsc (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_t s, int v, modp_vardnsrecdegspsterm_t B, modp_t t, int w, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspsterm_oomulscaddmulsc_cns (C, A, s, v, B, t, w, args), CT);
}

static void 
modp_vardnsrecdegspsterm_oomulscaddmulmonomsc (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_t s, int v, modp_vardnsrecdegspsterm_t B, unimonom_t m, modp_t t, int w, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspsterm_oomulscaddmulmonomsc_cns (C, A, s, v, B, m, t, w, args), CT);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_inmulscaddmulsc (modp_vardnsrecdegspsterm_t A, modp_t s, int v, modp_vardnsrecdegspsterm_t B, modp_t t, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (0 == (modp_vardnsrecdegspsterm_cmp (A, B, args)));
  return modp_vardnsrecdegspsterm_inmulscaddscmulsc (A, s, v, modp_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_inmulscaddmulmonomsc (modp_vardnsrecdegspsterm_t A, modp_t s, int v, modp_vardnsrecdegspsterm_t B, unimonom_t m, modp_t t, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (0 == (modp_vardnsrecdegspsterm_cmpmul (A, B, m, args)));
  return modp_vardnsrecdegspsterm_inmulscaddscmulsc (A, s, v, modp_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_oodivsc_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_t s, modp_vardnsrecdegspsterm_args args)
{
  BOOL failed;
  modp_vardnsrecdegspsterm_t new = modp_vardnsrecdegspsterm_alloc (args);

  failed = modp_oodiv (modp_vardnsrecdegspsterm_scal_cval (new, args), modp_vardnsrecdegspsterm_scal (A, args), s, args.sargs);
  if (failed)
    {
      modp_vardnsrecdegspsterm_free (new, args);
      return NULL;
    }

  unimonom_copy (modp_vardnsrecdegspsterm_monom_cval (new), modp_vardnsrecdegspsterm_monom (A), args.margs);

  return modp_vardnsrecdegspsterm_condcns (C, new, args);
}

#if 0				/* unused ! why did I write this ? */
static BOOL 
modp_vardnsrecdegspsterm_oodivsc (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_t s, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  if ((C = modp_vardnsrecdegspsterm_oodivsc_cns (C, A, s, args)))
    {
      modp_vardnsrecdegspsterm_glue (C, CT);
      return SUCCESS;
    }
  else
    {
      return FAILURE;
    }
}
#endif

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_indivsc (modp_vardnsrecdegspsterm_t A, modp_t s, modp_vardnsrecdegspsterm_args args)
{
  modp_indiv (modp_vardnsrecdegspsterm_scal_cval (A, args), s, args.sargs);
  return modp_vardnsrecdegspsterm_conddelete (A, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_oodivmonomsc_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, unimonom_t m, modp_t s, modp_vardnsrecdegspsterm_args args)
{
  BOOL sfailed, mfailed;
  modp_vardnsrecdegspsterm_t new = modp_vardnsrecdegspsterm_alloc (args);

  sfailed = modp_oodiv (modp_vardnsrecdegspsterm_scal_cval (new, args), modp_vardnsrecdegspsterm_scal (A, args), s, args.sargs);
  mfailed = unimonom_oodiv (modp_vardnsrecdegspsterm_monom_cval (new), modp_vardnsrecdegspsterm_monom (A), m, args.margs);

  if (sfailed || mfailed)
    {
      /* both failures are possible in the multivariate case */
      modp_vardnsrecdegspsterm_free (new, args);
      return NULL;
    }

  return modp_vardnsrecdegspsterm_condcns (C, new, args);
}

#if 0				/* unused ! why did I write this ? */
static BOOL 
modp_vardnsrecdegspsterm_oodivmonomsc (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, unimonom_t m, modp_t s, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  if ((C = modp_vardnsrecdegspsterm_oodivmonomsc_cns (C, A, m, s, args)))
    {
      modp_vardnsrecdegspsterm_glue (C, CT);
      return SUCCESS;
    }
  else
    {
      return FAILURE;
    }
}
#endif

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_indivmonomsc (modp_vardnsrecdegspsterm_t A, unimonom_t m, modp_t s, modp_vardnsrecdegspsterm_args args)
{
  modp_indiv (modp_vardnsrecdegspsterm_scal_cval (A, args), s, args.sargs);
  unimonom_indiv (modp_vardnsrecdegspsterm_monom_cval (A), m, args.margs);

  return modp_vardnsrecdegspsterm_conddelete (A, args);
}

static void 
modp_vardnsrecdegspsterm_args_fileOut (id aFiler, modp_vardnsrecdegspsterm_args * args)
{
  modp_args_fileOut (aFiler, &args->sargs);
  unimonom_args_fileOut (aFiler, &args->margs);
}
static void 
modp_vardnsrecdegspsterm_args_fileIn (id aFiler, modp_vardnsrecdegspsterm_args * args)
{
  modp_args_fileIn (aFiler, &args->sargs);
  unimonom_args_fileIn (aFiler, &args->margs);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_fileOut (id aFiler, modp_vardnsrecdegspsterm_t self, modp_vardnsrecdegspsterm_args args)
{
  assert (modp_vardnsrecdegspsterm_check (self, args));

  modp_fileOut (aFiler, modp_vardnsrecdegspsterm_scal_cval (self, args), args.sargs);
  unimonom_fileOut (aFiler, modp_vardnsrecdegspsterm_monom_cval (self), args.margs);

  return self->nlink;
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspsterm_fileIn_cns (id aFiler, modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_t self = modp_vardnsrecdegspsterm_alloc (args);

  modp_fileIn (aFiler, modp_vardnsrecdegspsterm_scal_cval (self, args), args.sargs);
  unimonom_fileIn (aFiler, modp_vardnsrecdegspsterm_monom_cval (self), args.margs);

  return modp_vardnsrecdegspsterm_cns (C, self);
}

static int 
modp_vardnsrecdegspslist_check (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_t prev;

  for (prev = NULL; A != AT; prev = A, A = A->nlink)
    {
      if (modp_vardnsrecdegspsterm_check (A, args) == 0)
	return 0;
      if (prev && modp_vardnsrecdegspsterm_cmp (prev, A, args) <= 0)
	return 0;
    }

  return 1;
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspslist_copy_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    {
      C = modp_vardnsrecdegspsterm_copy_cns (C, A, args);
      A = A->nlink;
    }
  return C;
}

static void 
modp_vardnsrecdegspslist_copy (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspslist_copy_cns (C, A, AT, args), CT);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspslist_deepcopy_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    {
      C = modp_vardnsrecdegspsterm_deepcopy_cns (C, A, args);
      A = A->nlink;
    }
  return C;
}

static void 
modp_vardnsrecdegspslist_deepcopy (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspslist_deepcopy_cns (C, A, AT, args), CT);
}

static void 
modp_vardnsrecdegspslist_clear (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    {
      modp_vardnsrecdegspsterm_clear (A, args);
      A = A->nlink;
    }
}

static void 
modp_vardnsrecdegspslist_free (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_t t;
  for (; A != AT; A = t)
    {
      t = A->nlink;
      modp_vardnsrecdegspsterm_free (A, args);
    }
}

static int 
modp_vardnsrecdegspslist_count (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT)
{
  int c = 0;
  for (; A != AT; A = A->nlink)
    c++;
  return c;
}

static unsigned 
modp_vardnsrecdegspslist_hash (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_vardnsrecdegspsterm_args args)
{
  return modp_vardnsrecdegspslist_count (A, AT);
}

static int 
modp_vardnsrecdegspslist_iseq (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_vardnsrecdegspsterm_t B, modp_vardnsrecdegspsterm_t BT, modp_vardnsrecdegspsterm_args args)
{
  for (; A != AT && B != BT; A = A->nlink, B = B->nlink)
    {
      if (!modp_vardnsrecdegspsterm_iseq (A, B, args))
	return 0;
    }
  return (A == AT && B == BT);
}

static int 
modp_vardnsrecdegspslist_isop (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_vardnsrecdegspsterm_t B, modp_vardnsrecdegspsterm_t BT, modp_vardnsrecdegspsterm_args args)
{
  for (; A != AT && B != BT; A = A->nlink, B = B->nlink)
    {
      if (!modp_vardnsrecdegspsterm_isop (A, B, args))
	return 0;
    }
  return (A == AT && B == BT);
}

static int 
modp_vardnsrecdegspslist_deg (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_vardnsrecdegspsterm_args args)
{
  return (A == AT) ? -1 : modp_vardnsrecdegspsterm_deg (A, args);
}

static int 
modp_vardnsrecdegspslist_maxdeg (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_vardnsrecdegspsterm_args args)
{
  int max = (A == AT) ? -1 : modp_vardnsrecdegspsterm_deg (A, args);
  for (A = A->nlink; A != AT; A = A->nlink)
    {
      int d = modp_vardnsrecdegspsterm_deg (A, args);
      if (max < d)
	max = d;
    }
  return max;
}

static int 
modp_vardnsrecdegspslist_ord (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_vardnsrecdegspsterm_args args)
{
  return (A == AT) ? -1 : modp_vardnsrecdegspsterm_deg (AT->plink, args);
}

static int 
modp_vardnsrecdegspslist_mindeg (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_vardnsrecdegspsterm_args args)
{
  int min = (A == AT) ? -1 : modp_vardnsrecdegspsterm_deg (A, args);
  for (A = A->nlink; A != AT; A = A->nlink)
    {
      int d = modp_vardnsrecdegspsterm_deg (A, args);
      if (min > d)
	min = d;
    }
  return min;
}

static void 
modp_vardnsrecdegspslist_insert (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, unimonom_t m, modp_t s, modp_vardnsrecdegspsterm_args args)
{
  assert (modp_iszero (s, args.sargs) == NO);

  /* adding to zero */
  if (A == AT)
    {
      modp_vardnsrecdegspsterm_copymonomsc (A, m, s, A, args);
      return;
    }

  /* tail append */
  if (modp_vardnsrecdegspsterm_cmpmonom (AT->plink, m, args) > 0)
    {
      modp_vardnsrecdegspsterm_copymonomsc (AT->plink, m, s, AT, args);
      return;
    }

  /* insertion */
  while (A != AT)
    {
      int cmp = modp_vardnsrecdegspsterm_cmpmonom (A, m, args);
      if (cmp == 0)
	{
	  modp_vardnsrecdegspsterm_inaddsc (A, +1, s, +1, args);
	  return;
	}
      if (cmp < 0)
	{
	  modp_vardnsrecdegspsterm_copymonomsc (A->plink, m, s, A, args);
	  return;
	}
      A = A->nlink;
    }

  fprintf (stderr, "Shouldn't happen\n");
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspslist_ooneg_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    {
      C = modp_vardnsrecdegspsterm_ooneg_cns (C, A, args);
      A = A->nlink;
    }
  return C;
}

static void 
modp_vardnsrecdegspslist_ooneg (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspslist_ooneg_cns (C, A, AT, args), CT);
}

static void 
modp_vardnsrecdegspslist_inneg (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    A = modp_vardnsrecdegspsterm_inneg (A, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspslist_oonegv_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, int v, modp_vardnsrecdegspsterm_args args)
{
  if (v == -1)
    {
      return modp_vardnsrecdegspslist_ooneg_cns (C, A, AT, args);
    }
  else
    {
      return modp_vardnsrecdegspslist_copy_cns (C, A, AT, args);
    }
}

static void 
modp_vardnsrecdegspslist_oonegv (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, int v, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspslist_oonegv_cns (C, A, AT, v, args), CT);
}

static void 
modp_vardnsrecdegspslist_innegv (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, int v, modp_vardnsrecdegspsterm_args args)
{
  if (v == -1)
    modp_vardnsrecdegspslist_inneg (A, AT, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspslist_oodbl_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, int v, modp_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    {
      C = modp_vardnsrecdegspsterm_oodbl_cns (C, A, v, args);
      A = A->nlink;
    }
  return C;
}

static void 
modp_vardnsrecdegspslist_oodbl (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, int v, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspslist_oodbl_cns (C, A, AT, v, args), CT);
}

static void 
modp_vardnsrecdegspslist_indbl (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, int v, modp_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    A = modp_vardnsrecdegspsterm_indbl (A, v, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspslist_ooadd_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, int v, modp_vardnsrecdegspsterm_t B, modp_vardnsrecdegspsterm_t BT, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = modp_vardnsrecdegspsterm_ooadd_cns (C, A, v, B, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = modp_vardnsrecdegspsterm_oonegv_cns (C, B, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = modp_vardnsrecdegspsterm_oonegv_cns (C, A, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return modp_vardnsrecdegspslist_oonegv_cns (C, A, AT, v, args);
  if (B != BT)
    return modp_vardnsrecdegspslist_oonegv_cns (C, B, BT, w, args);
  return C;
}

static void 
modp_vardnsrecdegspslist_ooadd (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, int v, modp_vardnsrecdegspsterm_t B, modp_vardnsrecdegspsterm_t BT, int w, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspslist_ooadd_cns (C, A, AT, v, B, BT, w, args), CT);
}

static void 
modp_vardnsrecdegspslist_inadd (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, int v, modp_vardnsrecdegspsterm_t B, modp_vardnsrecdegspsterm_t BT, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = modp_vardnsrecdegspsterm_inadd (A, v, B, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  modp_vardnsrecdegspsterm_oonegv (A->plink, B, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = modp_vardnsrecdegspsterm_innegv (A, v, args);
	}
    }

  if (A != AT)
    modp_vardnsrecdegspslist_innegv (A, AT, v, args);
  if (B != BT)
    modp_vardnsrecdegspslist_oonegv (A->plink, B, BT, w, A, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspslist_oomulsc_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_t s, int v, modp_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    {
      C = modp_vardnsrecdegspsterm_oomulsc_cns (C, A, s, v, args);
      A = A->nlink;
    }
  return C;
}

static void 
modp_vardnsrecdegspslist_oomulsc (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_t s, int v, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspslist_oomulsc_cns (C, A, AT, s, v, args), CT);
}

static void 
modp_vardnsrecdegspslist_inmulsc (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_t s, int v, modp_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    A = modp_vardnsrecdegspsterm_inmulsc (A, s, v, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspslist_oomulmonomsc_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, unimonom_t m, modp_t s, int v, modp_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    {
      C = modp_vardnsrecdegspsterm_oomulmonomsc_cns (C, A, m, s, v, args);
      A = A->nlink;
    }
  return C;
}

static void 
modp_vardnsrecdegspslist_oomulmonomsc (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, unimonom_t m, modp_t s, int v, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspslist_oomulmonomsc_cns (C, A, AT, m, s, v, args), CT);
}

static void 
modp_vardnsrecdegspslist_inmulmonomsc (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, unimonom_t m, modp_t s, int v, modp_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    A = modp_vardnsrecdegspsterm_inmulmonomsc (A, m, s, v, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspslist_ooaddmulsc_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, int v, modp_vardnsrecdegspsterm_t B, modp_vardnsrecdegspsterm_t BT, modp_t t, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = modp_vardnsrecdegspsterm_ooaddmulsc_cns (C, A, v, B, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = modp_vardnsrecdegspsterm_oomulsc_cns (C, B, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = modp_vardnsrecdegspsterm_oonegv_cns (C, A, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return modp_vardnsrecdegspslist_oonegv_cns (C, A, AT, v, args);
  if (B != BT)
    return modp_vardnsrecdegspslist_oomulsc_cns (C, B, BT, t, w, args);
  return C;
}

static void 
modp_vardnsrecdegspslist_ooaddmulsc (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, int v, modp_vardnsrecdegspsterm_t B, modp_vardnsrecdegspsterm_t BT, modp_t t, int w, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspslist_ooaddmulsc_cns (C, A, AT, v, B, BT, t, w, args), CT);
}

static void 
modp_vardnsrecdegspslist_inaddmulsc (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, int v, modp_vardnsrecdegspsterm_t B, modp_vardnsrecdegspsterm_t BT, modp_t t, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = modp_vardnsrecdegspsterm_inaddmulsc (A, v, B, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  modp_vardnsrecdegspsterm_oomulsc (A->plink, B, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = modp_vardnsrecdegspsterm_innegv (A, v, args);
	}
    }

  if (A != AT)
    modp_vardnsrecdegspslist_innegv (A, AT, v, args);
  if (B != BT)
    modp_vardnsrecdegspslist_oomulsc (A->plink, B, BT, t, w, A, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspslist_ooaddmulmonomsc_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, int v, modp_vardnsrecdegspsterm_t B, modp_vardnsrecdegspsterm_t BT, unimonom_t m, modp_t t, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsrecdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  C = modp_vardnsrecdegspsterm_ooaddmulmonomsc_cns (C, A, v, B, m, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = modp_vardnsrecdegspsterm_oomulmonomsc_cns (C, B, m, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = modp_vardnsrecdegspsterm_oonegv_cns (C, A, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return modp_vardnsrecdegspslist_oonegv_cns (C, A, AT, v, args);
  if (B != BT)
    return modp_vardnsrecdegspslist_oomulmonomsc_cns (C, B, BT, m, t, w, args);
  return C;
}

static void 
modp_vardnsrecdegspslist_ooaddmulmonomsc (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, int v, modp_vardnsrecdegspsterm_t B, modp_vardnsrecdegspsterm_t BT, unimonom_t m, modp_t t, int w, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspslist_ooaddmulmonomsc_cns (C, A, AT, v, B, BT, m, t, w, args), CT);
}

static void 
modp_vardnsrecdegspslist_inaddmulmonomsc (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, int v, modp_vardnsrecdegspsterm_t B, modp_vardnsrecdegspsterm_t BT, unimonom_t m, modp_t t, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsrecdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  A = modp_vardnsrecdegspsterm_inaddmulmonomsc (A, v, B, m, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  modp_vardnsrecdegspsterm_oomulmonomsc (A->plink, B, m, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = modp_vardnsrecdegspsterm_innegv (A, v, args);
	}
    }

  if (A != AT)
    modp_vardnsrecdegspslist_innegv (A, AT, v, args);
  if (B != BT)
    modp_vardnsrecdegspslist_oomulmonomsc (A->plink, B, BT, m, t, w, A, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspslist_oomulscadd_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_t s, int v, modp_vardnsrecdegspsterm_t B, modp_vardnsrecdegspsterm_t BT, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = modp_vardnsrecdegspsterm_oomulscadd_cns (C, A, s, v, B, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = modp_vardnsrecdegspsterm_oonegv_cns (C, B, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = modp_vardnsrecdegspsterm_oomulsc_cns (C, A, s, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return modp_vardnsrecdegspslist_oomulsc_cns (C, A, AT, s, v, args);
  if (B != BT)
    return modp_vardnsrecdegspslist_oonegv_cns (C, B, BT, w, args);
  return C;
}

static void 
modp_vardnsrecdegspslist_oomulscadd (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_t s, int v, modp_vardnsrecdegspsterm_t B, modp_vardnsrecdegspsterm_t BT, int w, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspslist_oomulscadd_cns (C, A, AT, s, v, B, BT, w, args), CT);
}

static void 
modp_vardnsrecdegspslist_inmulscadd (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_t s, int v, modp_vardnsrecdegspsterm_t B, modp_vardnsrecdegspsterm_t BT, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = modp_vardnsrecdegspsterm_inmulscadd (A, s, v, B, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  modp_vardnsrecdegspsterm_oonegv (A->plink, B, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = modp_vardnsrecdegspsterm_inmulsc (A, s, v, args);
	}
    }

  if (A != AT)
    modp_vardnsrecdegspslist_inmulsc (A, AT, s, v, args);
  if (B != BT)
    modp_vardnsrecdegspslist_oonegv (A->plink, B, BT, w, A, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspslist_oomulscaddmulsc_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_t s, int v, modp_vardnsrecdegspsterm_t B, modp_vardnsrecdegspsterm_t BT, modp_t t, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = modp_vardnsrecdegspsterm_oomulscaddmulsc_cns (C, A, s, v, B, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = modp_vardnsrecdegspsterm_oomulsc_cns (C, B, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = modp_vardnsrecdegspsterm_oomulsc_cns (C, A, s, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return modp_vardnsrecdegspslist_oomulsc_cns (C, A, AT, s, v, args);
  if (B != BT)
    return modp_vardnsrecdegspslist_oomulsc_cns (C, B, BT, t, w, args);
  return C;
}

static void 
modp_vardnsrecdegspslist_oomulscaddmulsc (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_t s, int v, modp_vardnsrecdegspsterm_t B, modp_vardnsrecdegspsterm_t BT, modp_t t, int w, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspslist_oomulscaddmulsc_cns (C, A, AT, s, v, B, BT, t, w, args), CT);
}

static void 
modp_vardnsrecdegspslist_inmulscaddmulsc (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_t s, int v, modp_vardnsrecdegspsterm_t B, modp_vardnsrecdegspsterm_t BT, modp_t t, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = modp_vardnsrecdegspsterm_inmulscaddmulsc (A, s, v, B, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  modp_vardnsrecdegspsterm_oomulsc (A->plink, B, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = modp_vardnsrecdegspsterm_inmulsc (A, s, v, args);
	}
    }

  if (A != AT)
    modp_vardnsrecdegspslist_inmulsc (A, AT, s, v, args);
  if (B != BT)
    modp_vardnsrecdegspslist_oomulsc (A->plink, B, BT, t, w, A, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspslist_oomulscaddmulmonomsc_cns (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_t s, int v, modp_vardnsrecdegspsterm_t B, modp_vardnsrecdegspsterm_t BT, unimonom_t m, modp_t t, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsrecdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  C = modp_vardnsrecdegspsterm_oomulscaddmulmonomsc_cns (C, A, s, v, B, m, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = modp_vardnsrecdegspsterm_oomulmonomsc_cns (C, B, m, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = modp_vardnsrecdegspsterm_oomulsc_cns (C, A, s, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return modp_vardnsrecdegspslist_oomulsc_cns (C, A, AT, s, v, args);
  if (B != BT)
    return modp_vardnsrecdegspslist_oomulmonomsc_cns (C, B, BT, m, t, w, args);
  return C;
}

static void 
modp_vardnsrecdegspslist_oomulscaddmulmonomsc (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_t s, int v, modp_vardnsrecdegspsterm_t B, modp_vardnsrecdegspsterm_t BT, unimonom_t m, modp_t t, int w, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspslist_oomulscaddmulmonomsc_cns (C, A, AT, s, v, B, BT, m, t, w, args), CT);
}

static void 
modp_vardnsrecdegspslist_inmulscaddmulmonomsc (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_t s, int v, modp_vardnsrecdegspsterm_t B, modp_vardnsrecdegspsterm_t BT, unimonom_t m, modp_t t, int w, modp_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsrecdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  A = modp_vardnsrecdegspsterm_inmulscaddmulmonomsc (A, s, v, B, m, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  modp_vardnsrecdegspsterm_oomulmonomsc (A->plink, B, m, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = modp_vardnsrecdegspsterm_inmulsc (A, s, v, args);
	}
    }

  if (A != AT)
    modp_vardnsrecdegspslist_inmulsc (A, AT, s, v, args);
  if (B != BT)
    modp_vardnsrecdegspslist_oomulmonomsc (A->plink, B, BT, m, t, w, A, args);
}

static BOOL 
modp_vardnsrecdegspslist_oodivsc (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_t s, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  BOOL failed = NO;

  while (A != AT)
    {
      modp_vardnsrecdegspsterm_t nextC = modp_vardnsrecdegspsterm_oodivsc_cns (C, A, s, args);
      if (nextC)
	{
	  C = nextC;
	  A = A->nlink;
	}
      else
	{
	  failed = YES;
	  break;
	}
    }

  /* in any case, success or failure, have to keep list circular */
  modp_vardnsrecdegspsterm_glue (C, CT);
  return failed;
}

static void 
modp_vardnsrecdegspslist_indivsc (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_t s, modp_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    A = modp_vardnsrecdegspsterm_indivsc (A, s, args);
}

static BOOL 
modp_vardnsrecdegspslist_oodivmonomsc (modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, unimonom_t m, modp_t s, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  BOOL failed = NO;

  while (A != AT)
    {
      modp_vardnsrecdegspsterm_t nextC = modp_vardnsrecdegspsterm_oodivmonomsc_cns (C, A, m, s, args);
      if (nextC)
	{
	  C = nextC;
	  A = A->nlink;
	}
      else
	{
	  failed = YES;
	  break;
	}
    }

  /* in any case, success or failure, have to keep list circular */
  modp_vardnsrecdegspsterm_glue (C, CT);
  return failed;
}

static void 
modp_vardnsrecdegspslist_indivmonomsc (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, unimonom_t m, modp_t s, modp_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    A = modp_vardnsrecdegspsterm_indivmonomsc (A, m, s, args);
}

static void 
modp_vardnsrecdegspslist_fileOut (id aFiler, modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT, modp_vardnsrecdegspsterm_args args)
{
  int n;
  n = modp_vardnsrecdegspslist_count (A, AT);
  [aFiler fileOut:&n type:'i'];
  while (A != AT)
    A = modp_vardnsrecdegspsterm_fileOut (aFiler, A, args);
}

static modp_vardnsrecdegspsterm_t 
modp_vardnsrecdegspslist_fileIn_cns (id aFiler, modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_args args)
{
  int n;
  [aFiler fileIn:&n type:'i'];
  while (n--)
    C = modp_vardnsrecdegspsterm_fileIn_cns (aFiler, C, args);
  return C;
}

static void 
modp_vardnsrecdegspslist_fileIn (id aFiler, modp_vardnsrecdegspsterm_t C, modp_vardnsrecdegspsterm_t CT, modp_vardnsrecdegspsterm_args args)
{
  modp_vardnsrecdegspsterm_glue (modp_vardnsrecdegspslist_fileIn_cns (aFiler, C, args), CT);
}

static void 
modp_vardnsrecdegspspol_ix_init (modp_vardnsrecdegspspol_ixt ix, id self)
{
  modp_vardnsrecdegspspol_t v = [self modp_vardnsrecdegspspol_value];
  ix->head = v;
  ix->ix = v;
}

static void 
modp_vardnsrecdegspspol_ix_clear (modp_vardnsrecdegspspol_ixt ix)
{
  /* nothing to clear */
}

static int 
modp_vardnsrecdegspspol_ix_count_aux_aux (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT)
{
  int c = 0;
  for (; A != AT; A = A->nlink)
    c++;
  return c;
}

static int 
modp_vardnsrecdegspspol_ix_count_aux (modp_vardnsrecdegspspol_t self)
{
  return modp_vardnsrecdegspspol_ix_count_aux_aux (self->nlink, self);
}

static int 
modp_vardnsrecdegspspol_ix_count (modp_vardnsrecdegspspol_ixt ix)
{
  /* merde ! can't include entire modp_vardnsrecdegspslist for modp_vardnsrecdegspslist_count */
  return modp_vardnsrecdegspspol_ix_count_aux (ix->head);
}

static int 
modp_vardnsrecdegspspol_ix_isempty_aux (modp_vardnsrecdegspspol_t self)
{
  if (self->nlink == self)
    {
      assert (self->plink == self);
      return YES;
    }
  else
    {
      assert (self->plink != self);
      return NO;
    }
}

static int 
modp_vardnsrecdegspspol_ix_isempty (modp_vardnsrecdegspspol_ixt ix)
{
  /* can't include entire modp_vardnsrecdegspspol for modp_vardnsrecdegspspol_isempty */
  return modp_vardnsrecdegspspol_ix_isempty_aux (ix->head);
}

static int 
modp_vardnsrecdegspspol_ix_ismatch (modp_vardnsrecdegspspol_ixt ix)
{
  return (ix->ix != NULL && ix->ix != ix->head);
}

static void 
modp_vardnsrecdegspspol_ix_tofirst (modp_vardnsrecdegspspol_ixt ix)
{
  ix->ix = ix->head;
}

static void 
modp_vardnsrecdegspspol_ix_tolast (modp_vardnsrecdegspspol_ixt ix)
{
  ix->ix = NULL;
}

static void 
modp_vardnsrecdegspspol_ix_to (modp_vardnsrecdegspspol_ixt ix, int i)
{
  fprintf (stderr, "at: notImplemented\n");
}

static void 
modp_vardnsrecdegspspol_ix_next (modp_vardnsrecdegspspol_ixt ix)
{
  if (ix->ix == NULL)
    {
      /* remain on position just after last term */
    }
  else
    {
      ix->ix = ix->ix->nlink;	/* next term or head = position after last */
      if (ix->ix == ix->head)
	ix->ix = NULL;
    }
}

static void 
modp_vardnsrecdegspspol_ix_prev (modp_vardnsrecdegspspol_ixt ix)
{
  if (ix->ix == ix->head)
    {
      /* remain on position just before first term */
    }
  else
    {
      if (ix->ix == NULL)
	{
	  ix->ix = ix->head->plink;	/* last term or head = position before first */
	}
      else
	{
	  ix->ix = ix->ix->plink;	/* previous term or head = position before first */
	}
    }
}
static int 
modp_vardnsrecdegspspol_check (modp_vardnsrecdegspspol_t self, modp_vardnsrecdegspspol_args args)
{
  assert (self->data == 0xcafebabe);
  return modp_vardnsrecdegspslist_check (self->nlink, self, args);
}

static modp_vardnsrecdegspspol_t 
modp_vardnsrecdegspspol_id2t (id object)
{
  return [object modp_vardnsrecdegspspol_value];
}

static modp_vardnsrecdegspspol_c *
modp_vardnsrecdegspspol_id2c (id object)
{
  return [object modp_vardnsrecdegspspol_reference];
}

static id 
modp_vardnsrecdegspspol_t2id (id proto, modp_vardnsrecdegspspol_t f)
{
  return [proto modp_vardnsrecdegspspol_value:f];
}

static id 
modp_vardnsrecdegspspol_c2id (id proto, modp_vardnsrecdegspspol_c * r)
{
  return [proto modp_vardnsrecdegspspol_reference:r];
}

static int 
modp_vardnsrecdegspspol_isempty (modp_vardnsrecdegspspol_t self)
{
  if (self->nlink == self)
    {
      assert (self->plink == self);
      return YES;
    }
  else
    {
      assert (self->plink != self);
      return NO;
    }
}

static void 
modp_vardnsrecdegspspol_init (modp_vardnsrecdegspspol_t self, modp_vardnsrecdegspspol_args args)
{
  self->data = 0xcafebabe;
  self->nlink = self;
  self->plink = self;
  assert (modp_vardnsrecdegspspol_check (self, args));
}

static void 
modp_vardnsrecdegspspol_copy (modp_vardnsrecdegspspol_t c, modp_vardnsrecdegspspol_t a, modp_vardnsrecdegspspol_args args)
{
  assert (modp_vardnsrecdegspspol_check (a, args));
  modp_vardnsrecdegspspol_init (c, args);
  modp_vardnsrecdegspslist_copy (c, a->nlink, a, c, args);
}

static void 
modp_vardnsrecdegspspol_deepcopy (modp_vardnsrecdegspspol_t c, modp_vardnsrecdegspspol_t a, modp_vardnsrecdegspspol_args args)
{
  assert (modp_vardnsrecdegspspol_check (a, args));
  modp_vardnsrecdegspspol_init (c, args);
  modp_vardnsrecdegspslist_deepcopy (c, a->nlink, a, c, args);
}

static void 
modp_vardnsrecdegspspol_move (modp_vardnsrecdegspspol_t c, modp_vardnsrecdegspspol_t a, modp_vardnsrecdegspspol_args args)
{
  if (modp_vardnsrecdegspspol_isempty (a))
    {
      modp_vardnsrecdegspspol_init (c, args);
    }
  else
    {
      modp_vardnsrecdegspspol_init (c, args);
      modp_vardnsrecdegspsterm_glue (c, a->nlink);
      modp_vardnsrecdegspsterm_glue (a->plink, c);
    }

  a->data = 0;
  assert (modp_vardnsrecdegspspol_check (c, args));
}

static void 
modp_vardnsrecdegspspol_clear (modp_vardnsrecdegspspol_t self, modp_vardnsrecdegspspol_args args)
{
  modp_vardnsrecdegspslist_clear (self->nlink, self, args);
  self->data = 0;
  modp_vardnsrecdegspslist_free (self->nlink, self, args);
}

static int 
modp_vardnsrecdegspspol_count (modp_vardnsrecdegspspol_t self)
{
  return modp_vardnsrecdegspslist_count (self->nlink, self);
}

static unsigned 
modp_vardnsrecdegspspol_hash (modp_vardnsrecdegspspol_t a, modp_vardnsrecdegspspol_args args)
{
  return modp_vardnsrecdegspslist_hash (a->nlink, a, args);
}

static int 
modp_vardnsrecdegspspol_iseq (modp_vardnsrecdegspspol_t a, modp_vardnsrecdegspspol_t b, modp_vardnsrecdegspspol_args args)
{
  return (a == b) ? YES : modp_vardnsrecdegspslist_iseq (a->nlink, a, b->nlink, b, args);
}

static int 
modp_vardnsrecdegspspol_isone (modp_vardnsrecdegspspol_t a, modp_vardnsrecdegspspol_args args)
{
  /* if the leading term is one, then it is one */
  return (modp_vardnsrecdegspspol_isempty (a)) ? 0 : modp_vardnsrecdegspsterm_isone (a->nlink, args);
}

static int 
modp_vardnsrecdegspspol_isminusone (modp_vardnsrecdegspspol_t a, modp_vardnsrecdegspspol_args args)
{
  /* if the leading term is minus one, then it is minus one */
  return (modp_vardnsrecdegspspol_isempty (a)) ? 0 : modp_vardnsrecdegspsterm_isminusone (a->nlink, args);
}

static int 
modp_vardnsrecdegspspol_deg (modp_vardnsrecdegspspol_t self, modp_vardnsrecdegspspol_args args)
{
  return modp_vardnsrecdegspslist_deg (self->nlink, self, args);
}

static int 
modp_vardnsrecdegspspol_ord (modp_vardnsrecdegspspol_t self, modp_vardnsrecdegspspol_args args)
{
  return modp_vardnsrecdegspslist_ord (self->nlink, self, args);
}

static int 
modp_vardnsrecdegspspol_maxdeg (modp_vardnsrecdegspspol_t self, modp_vardnsrecdegspspol_args args)
{
  return modp_vardnsrecdegspslist_maxdeg (self->nlink, self, args);
}

static int 
modp_vardnsrecdegspspol_mindeg (modp_vardnsrecdegspspol_t self, modp_vardnsrecdegspspol_args args)
{
  return modp_vardnsrecdegspslist_mindeg (self->nlink, self, args);
}

static modp_t 
modp_vardnsrecdegspspol_scalat (modp_vardnsrecdegspspol_t self, modp_vardnsrecdegspspol_ixt ix, modp_vardnsrecdegspspol_args args)
{
  assert (modp_vardnsrecdegspspol_ix_ismatch (ix) && ix->head == self);
  return modp_vardnsrecdegspsterm_scal (ix->ix, args);
}

static unimonom_t 
modp_vardnsrecdegspspol_monomat (modp_vardnsrecdegspspol_t self, modp_vardnsrecdegspspol_ixt ix, modp_vardnsrecdegspspol_args args)
{
  assert (modp_vardnsrecdegspspol_ix_ismatch (ix) && ix->head == self);
  return modp_vardnsrecdegspsterm_monom (ix->ix);
}

static modp_t 
modp_vardnsrecdegspspol_scalfirst (modp_vardnsrecdegspspol_t self, modp_vardnsrecdegspspol_args args)
{
  assert (modp_vardnsrecdegspspol_isempty (self) == NO);
  return modp_vardnsrecdegspsterm_scal (self->nlink, args);
}

static unimonom_t 
modp_vardnsrecdegspspol_monomfirst (modp_vardnsrecdegspspol_t self, modp_vardnsrecdegspspol_args args)
{
  assert (modp_vardnsrecdegspspol_isempty (self) == NO);
  return modp_vardnsrecdegspsterm_monom (self->nlink);
}

static void 
modp_vardnsrecdegspspol_remove (modp_vardnsrecdegspspol_t self, modp_vardnsrecdegspspol_args args)
{
  assert (modp_vardnsrecdegspspol_check (self, args) && modp_vardnsrecdegspspol_isempty (self) == NO);
  modp_vardnsrecdegspsterm_delete (self->nlink, args);
  assert (modp_vardnsrecdegspspol_check (self, args));
}

static void 
modp_vardnsrecdegspspol_insert (modp_vardnsrecdegspspol_t self, unimonom_t m, modp_t s, modp_vardnsrecdegspspol_args args)
{
  assert (modp_vardnsrecdegspspol_check (self, args));
  modp_vardnsrecdegspslist_insert (self->nlink, self, m, s, args);
  assert (modp_vardnsrecdegspspol_check (self, args));
}

static int 
modp_vardnsrecdegspspol_iszero (modp_vardnsrecdegspspol_t self, modp_vardnsrecdegspspol_args args)
{
  return modp_vardnsrecdegspspol_isempty (self);
}

static int 
modp_vardnsrecdegspspol_isop (modp_vardnsrecdegspspol_t a, modp_vardnsrecdegspspol_t b, modp_vardnsrecdegspspol_args args)
{
  assert (a != b);
  return modp_vardnsrecdegspslist_isop (a->nlink, a, b->nlink, b, args);
}

static void 
modp_vardnsrecdegspspol_ooneg (modp_vardnsrecdegspspol_t c, modp_vardnsrecdegspspol_t a, modp_vardnsrecdegspspol_args args)
{
  modp_vardnsrecdegspspol_init (c, args);
  modp_vardnsrecdegspslist_ooneg (c, a->nlink, a, c, args);
  assert (modp_vardnsrecdegspspol_check (c, args));
}

static void 
modp_vardnsrecdegspspol_inneg (modp_vardnsrecdegspspol_t a, modp_vardnsrecdegspspol_args args)
{
  modp_vardnsrecdegspslist_inneg (a->nlink, a, args);
  assert (modp_vardnsrecdegspspol_check (a, args));
}

static void 
modp_vardnsrecdegspspol_oodbl (modp_vardnsrecdegspspol_t c, modp_vardnsrecdegspspol_t a, int v, modp_vardnsrecdegspspol_args args)
{
  modp_vardnsrecdegspspol_init (c, args);
  modp_vardnsrecdegspslist_oodbl (c, a->nlink, a, v, c, args);
  assert (modp_vardnsrecdegspspol_check (c, args));
}

static void 
modp_vardnsrecdegspspol_indbl (modp_vardnsrecdegspspol_t a, int v, modp_vardnsrecdegspspol_args args)
{
  modp_vardnsrecdegspslist_indbl (a->nlink, a, v, args);
  assert (modp_vardnsrecdegspspol_check (a, args));
}

static void 
modp_vardnsrecdegspspol_ooadd (modp_vardnsrecdegspspol_t c, modp_vardnsrecdegspspol_t a, int v, modp_vardnsrecdegspspol_t b, int w, modp_vardnsrecdegspspol_args args)
{
  assert (a != b);
  modp_vardnsrecdegspspol_init (c, args);
  modp_vardnsrecdegspslist_ooadd (c, a->nlink, a, v, b->nlink, b, w, c, args);
  assert (modp_vardnsrecdegspspol_check (c, args));
}

static void 
modp_vardnsrecdegspspol_inadd (modp_vardnsrecdegspspol_t a, int v, modp_vardnsrecdegspspol_t b, int w, modp_vardnsrecdegspspol_args args)
{
  assert (a != b);
  modp_vardnsrecdegspslist_inadd (a->nlink, a, v, b->nlink, b, w, args);
  assert (modp_vardnsrecdegspspol_check (a, args));
}

static void 
modp_vardnsrecdegspspol_oomulsc (modp_vardnsrecdegspspol_t c, modp_vardnsrecdegspspol_t a, modp_t s, modp_vardnsrecdegspspol_args args)
{
  modp_vardnsrecdegspspol_init (c, args);
  modp_vardnsrecdegspslist_oomulsc (c, a->nlink, a, s, +1, c, args);
  assert (modp_vardnsrecdegspspol_check (c, args));
}

static void 
modp_vardnsrecdegspspol_inmulsc (modp_vardnsrecdegspspol_t a, modp_t s, modp_vardnsrecdegspspol_args args)
{
  modp_vardnsrecdegspslist_inmulsc (a->nlink, a, s, +1, args);
  assert (modp_vardnsrecdegspspol_check (a, args));
}

static void 
modp_vardnsrecdegspspol_ooaddmulsc (modp_vardnsrecdegspspol_t c, modp_vardnsrecdegspspol_t a, int v, modp_vardnsrecdegspspol_t b, modp_t t, int w, modp_vardnsrecdegspspol_args args)
{
  modp_vardnsrecdegspspol_init (c, args);
  modp_vardnsrecdegspslist_ooaddmulsc (c, a->nlink, a, v, b->nlink, b, t, w, c, args);
  assert (modp_vardnsrecdegspspol_check (c, args));
}

static void 
modp_vardnsrecdegspspol_inaddmulsc (modp_vardnsrecdegspspol_t a, int v, modp_vardnsrecdegspspol_t b, modp_t t, int w, modp_vardnsrecdegspspol_args args)
{
  modp_vardnsrecdegspslist_inaddmulsc (a->nlink, a, v, b->nlink, b, t, w, args);
  assert (modp_vardnsrecdegspspol_check (a, args));
}

static void 
modp_vardnsrecdegspspol_oomulscadd (modp_vardnsrecdegspspol_t c, modp_vardnsrecdegspspol_t a, modp_t s, int v, modp_vardnsrecdegspspol_t b, int w, modp_vardnsrecdegspspol_args args)
{
  modp_vardnsrecdegspspol_init (c, args);
  modp_vardnsrecdegspslist_oomulscadd (c, a->nlink, a, s, v, b->nlink, b, w, c, args);
  assert (modp_vardnsrecdegspspol_check (c, args));
}

static void 
modp_vardnsrecdegspspol_inmulscadd (modp_vardnsrecdegspspol_t a, modp_t s, int v, modp_vardnsrecdegspspol_t b, int w, modp_vardnsrecdegspspol_args args)
{
  modp_vardnsrecdegspslist_inmulscadd (a->nlink, a, s, v, b->nlink, b, w, args);
  assert (modp_vardnsrecdegspspol_check (a, args));
}

static void 
modp_vardnsrecdegspspol_oomulscaddmulsc (modp_vardnsrecdegspspol_t c, modp_vardnsrecdegspspol_t a, modp_t s, int v, modp_vardnsrecdegspspol_t b, modp_t t, int w, modp_vardnsrecdegspspol_args args)
{
  modp_vardnsrecdegspspol_init (c, args);
  modp_vardnsrecdegspslist_oomulscaddmulsc (c, a->nlink, a, s, v, b->nlink, b, t, w, c, args);
  assert (modp_vardnsrecdegspspol_check (c, args));
}

static void 
modp_vardnsrecdegspspol_inmulscaddmulsc (modp_vardnsrecdegspspol_t a, modp_t s, int v, modp_vardnsrecdegspspol_t b, modp_t t, int w, modp_vardnsrecdegspspol_args args)
{
  modp_vardnsrecdegspslist_inmulscaddmulsc (a->nlink, a, s, v, b->nlink, b, t, w, args);
  assert (modp_vardnsrecdegspspol_check (a, args));
}

static BOOL 
modp_vardnsrecdegspspol_oodivsc (modp_vardnsrecdegspspol_t c, modp_vardnsrecdegspspol_t a, modp_t s, modp_vardnsrecdegspspol_args args)
{
  BOOL failed;
  modp_vardnsrecdegspspol_init (c, args);
  failed = modp_vardnsrecdegspslist_oodivsc (c, a->nlink, a, s, c, args);
  assert (modp_vardnsrecdegspspol_check (c, args));
  if (failed)
    modp_vardnsrecdegspspol_clear (c, args);
  return failed;
}

static void 
modp_vardnsrecdegspspol_indivsc (modp_vardnsrecdegspspol_t a, modp_t s, modp_vardnsrecdegspspol_args args)
{
  modp_vardnsrecdegspslist_indivsc (a->nlink, a, s, args);
  assert (modp_vardnsrecdegspspol_check (a, args));
}

static void 
modp_vardnsrecdegspspol_oomulmonomsc (modp_vardnsrecdegspspol_t c, modp_vardnsrecdegspspol_t b, unimonom_t m, modp_t t, int w, modp_vardnsrecdegspspol_args args)
{
  modp_vardnsrecdegspspol_init (c, args);
  modp_vardnsrecdegspslist_oomulmonomsc (c, b->nlink, b, m, t, w, c, args);
  assert (modp_vardnsrecdegspspol_check (c, args));
}

static void 
modp_vardnsrecdegspspol_inmulmonomsc (modp_vardnsrecdegspspol_t b, unimonom_t m, modp_t t, int w, modp_vardnsrecdegspspol_args args)
{
  modp_vardnsrecdegspslist_inmulmonomsc (b->nlink, b, m, t, w, args);
  assert (modp_vardnsrecdegspspol_check (b, args));
}

static void 
modp_vardnsrecdegspspol_ooaddmulmonomsc (modp_vardnsrecdegspspol_t c, modp_vardnsrecdegspspol_t a, int v, modp_vardnsrecdegspspol_t b, unimonom_t m, modp_t t, int w, modp_vardnsrecdegspspol_args args)
{
  modp_vardnsrecdegspspol_init (c, args);
  modp_vardnsrecdegspslist_ooaddmulmonomsc (c, a->nlink, a, v, b->nlink, b, m, t, w, c, args);
  assert (modp_vardnsrecdegspspol_check (c, args));
}

static void 
modp_vardnsrecdegspspol_inaddmulmonomsc (modp_vardnsrecdegspspol_t a, int v, modp_vardnsrecdegspspol_t b, unimonom_t m, modp_t t, int w, modp_vardnsrecdegspspol_args args)
{
  modp_vardnsrecdegspslist_inaddmulmonomsc (a->nlink, a, v, b->nlink, b, m, t, w, args);
  assert (modp_vardnsrecdegspspol_check (a, args));
}

static void 
modp_vardnsrecdegspspol_oomulscaddmulmonomsc (modp_vardnsrecdegspspol_t c, modp_vardnsrecdegspspol_t a, modp_t s, int v, modp_vardnsrecdegspspol_t b, unimonom_t m, modp_t t, int w, modp_vardnsrecdegspspol_args args)
{
  modp_vardnsrecdegspspol_init (c, args);
  modp_vardnsrecdegspslist_oomulscaddmulmonomsc (c, a->nlink, a, s, v, b->nlink, b, m, t, w, c, args);
  assert (modp_vardnsrecdegspspol_check (c, args));
}

static void 
modp_vardnsrecdegspspol_inmulscaddmulmonomsc (modp_vardnsrecdegspspol_t a, modp_t s, int v, modp_vardnsrecdegspspol_t b, unimonom_t m, modp_t t, int w, modp_vardnsrecdegspspol_args args)
{
  modp_vardnsrecdegspslist_inmulscaddmulmonomsc (a->nlink, a, s, v, b->nlink, b, m, t, w, args);
  assert (modp_vardnsrecdegspspol_check (a, args));
}

static BOOL 
modp_vardnsrecdegspspol_oodivmonomsc (modp_vardnsrecdegspspol_t c, modp_vardnsrecdegspspol_t b, unimonom_t m, modp_t t, modp_vardnsrecdegspspol_args args)
{
  BOOL failed;
  modp_vardnsrecdegspspol_init (c, args);
  failed = modp_vardnsrecdegspslist_oodivmonomsc (c, b->nlink, b, m, t, c, args);
  assert (modp_vardnsrecdegspspol_check (c, args));
  if (failed)
    modp_vardnsrecdegspspol_clear (c, args);
  return failed;
}

static void 
modp_vardnsrecdegspspol_indivmonomsc (modp_vardnsrecdegspspol_t b, unimonom_t m, modp_t t, modp_vardnsrecdegspspol_args args)
{
  modp_vardnsrecdegspslist_indivmonomsc (b->nlink, b, m, t, args);
  assert (modp_vardnsrecdegspspol_check (b, args));
}

static void 
modp_vardnsrecdegspspol_args_fileOut (id aFiler, modp_vardnsrecdegspspol_args * args)
{
  modp_vardnsrecdegspsterm_args_fileOut (aFiler, args);
}
static void 
modp_vardnsrecdegspspol_args_fileIn (id aFiler, modp_vardnsrecdegspspol_args * args)
{
  modp_vardnsrecdegspsterm_args_fileIn (aFiler, args);
}

static void 
modp_vardnsrecdegspspol_fileOut (id aFiler, modp_vardnsrecdegspspol_t self, modp_vardnsrecdegspspol_args args)
{
  assert (modp_vardnsrecdegspspol_check (self, args));
  modp_vardnsrecdegspslist_fileOut (aFiler, self->nlink, self, args);
}

static void 
modp_vardnsrecdegspspol_fileIn (id aFiler, modp_vardnsrecdegspspol_t self, modp_vardnsrecdegspspol_args args)
{
  modp_vardnsrecdegspspol_init (self, args);
  modp_vardnsrecdegspslist_fileIn (aFiler, self, self, args);
  assert (modp_vardnsrecdegspspol_check (self, args));
}

static modp_vardnsrecdegspspol_args 
modp_vardnsrecdegspspol_getargs (id self)
{
  modp_vardnsrecdegspspol_args res;
  res.sargs = modp_getargs ([[self termZero] coefficient]);
  res.margs = 0;		/* unused */
  return res;
}

static int 
modp_vardnsrecdegspspol_expat (modp_vardnsrecdegspspol_t self, modp_vardnsrecdegspspol_ixt ix, modp_vardnsrecdegspspol_args args)
{
  return modp_vardnsrecdegspspol_monomat (self, ix, args);
}

static int 
modp_vardnsrecdegspspol_expfirst (modp_vardnsrecdegspspol_t self, modp_vardnsrecdegspspol_args args)
{
  return modp_vardnsrecdegspspol_monomfirst (self, args);
}
@implementation modp_vardnsrecdegsps_polynomial : vardnsrecdegsps_polynomial

- _setUpScalarZero:aScalar coefficientZero:aCoef symbols:aCltn
{
  id aSymbol;
  assert ([aCoef isZero] && [aScalar isZero]);
  assert ([aCoef class_vardnsrecdegsps_polynomial] == [self class]);
  aSymbol = [aCltn lastElement];
  termZero = [Term scalarZero:aScalar coefficient:aCoef symbol:aSymbol exponent:1];
  monomialZero = [Monomial scalar:aScalar symbols:aCltn];
  scalarZero = aScalar;
  symbols = aCltn;

  /* in vardns case, init takes a capacity */
  modp_vardnsrecdegspspol_init (&value, modp_vardnsrecdegspspol_getargs (self));
  assert ([self check]);
  return self;
}

+ scalarZero:aScalar coefficientZero:aCoef symbols:aCltn
{
  return [[super new] _setUpScalarZero:aScalar coefficientZero:aCoef symbols:aCltn];
}

- empty
{
  modp_vardnsrecdegspspol_c c;
  assert ([self check]);
  /* in vardns case, init takes a capacity */
  modp_vardnsrecdegspspol_init (&c, modp_vardnsrecdegspspol_getargs (self));
  return modp_vardnsrecdegspspol_c2id (self, &c);
}

- (int) numTerms
{
  /* seems to take getargs in degdns case */
  assert ([self check]);
  return modp_vardnsrecdegspspol_count (&value);
}

- (modp_vardnsrecdegspspol_t)modp_vardnsrecdegspspol_value
{
  return &value;
}

- domodp_vardnsrecdegspspol_value:(modp_vardnsrecdegspspol_t)aValue
{
  modp_vardnsrecdegspspol_copy (&value, aValue, modp_vardnsrecdegspspol_getargs (self));
  assert ([self check]);
  return self;
}

- modp_vardnsrecdegspspol_value:(modp_vardnsrecdegspspol_t)aValue
{
  return [[self clone] domodp_vardnsrecdegspspol_value:aValue];
}

- (modp_vardnsrecdegspspol_t)modp_vardnsrecdegspspol_reference
{
  return &value;
}

- domodp_vardnsrecdegspspol_reference:(modp_vardnsrecdegspspol_c *)aReference
{
  modp_vardnsrecdegspspol_move (&value, aReference, modp_vardnsrecdegspspol_getargs (self));
  assert ([self check]);
  return self;
}

- modp_vardnsrecdegspspol_reference:(modp_vardnsrecdegspspol_c *)aReference
{
  return [[self clone] domodp_vardnsrecdegspspol_reference:aReference];
}

- copy
{
  modp_vardnsrecdegspspol_c c;
  assert ([self check]);
  modp_vardnsrecdegspspol_copy (&c, &value, modp_vardnsrecdegspspol_getargs (self));
  return modp_vardnsrecdegspspol_c2id (self, &c);
}

- deepCopy
{
  modp_vardnsrecdegspspol_c c;
  assert ([self check]);
  modp_vardnsrecdegspspol_deepcopy (&c, &value, modp_vardnsrecdegspspol_getargs (self));
  return modp_vardnsrecdegspspol_c2id (self, &c);
}

- (BOOL) isEmpty
{
  return modp_vardnsrecdegspspol_isempty (&value);
}

- (BOOL) isOne
{
  return modp_vardnsrecdegspspol_isone (&value, modp_vardnsrecdegspspol_getargs (self));
}

- (BOOL) isMinusOne
{
  return modp_vardnsrecdegspspol_isminusone (&value, modp_vardnsrecdegspspol_getargs (self));
}

- (unsigned) hash
{
  return modp_vardnsrecdegspspol_hash (modp_vardnsrecdegspspol_id2t (self), modp_vardnsrecdegspspol_getargs (self));
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
      return modp_vardnsrecdegspspol_iseq (modp_vardnsrecdegspspol_id2t (self), modp_vardnsrecdegspspol_id2t (b), modp_vardnsrecdegspspol_getargs (self));
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
      return !modp_vardnsrecdegspspol_iseq (modp_vardnsrecdegspspol_id2t (self), modp_vardnsrecdegspspol_id2t (b), modp_vardnsrecdegspspol_getargs (self));
    }
}

- (BOOL) isZero
{
  assert ([self check]);
  return modp_vardnsrecdegspspol_iszero (modp_vardnsrecdegspspol_id2t (self), modp_vardnsrecdegspspol_getargs (self));
}

- (BOOL) notZero
{
  assert ([self check]);
  return !modp_vardnsrecdegspspol_iszero (modp_vardnsrecdegspspol_id2t (self), modp_vardnsrecdegspspol_getargs (self));
}

- (BOOL) isOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return modp_vardnsrecdegspspol_isop (modp_vardnsrecdegspspol_id2t (self), modp_vardnsrecdegspspol_id2t (b), modp_vardnsrecdegspspol_getargs (self));
}

- (BOOL) notOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return !modp_vardnsrecdegspspol_isop (modp_vardnsrecdegspspol_id2t (self), modp_vardnsrecdegspspol_id2t (b), modp_vardnsrecdegspspol_getargs (self));
}

- negate
{
  modp_vardnsrecdegspspol_c c;
  assert ([self check]);
  modp_vardnsrecdegspspol_ooneg (&c, modp_vardnsrecdegspspol_id2t (self), modp_vardnsrecdegspspol_getargs (self));
  return modp_vardnsrecdegspspol_c2id (self, &c);
}

- _double:(int)v
{
  modp_vardnsrecdegspspol_c c;
  assert ([self check]);
  modp_vardnsrecdegspspol_oodbl (&c, modp_vardnsrecdegspspol_id2t (self), v, modp_vardnsrecdegspspol_getargs (self));
  return modp_vardnsrecdegspspol_c2id (self, &c);
}

- double
{
  modp_vardnsrecdegspspol_c c;
  assert ([self check]);
  modp_vardnsrecdegspspol_oodbl (&c, modp_vardnsrecdegspspol_id2t (self), +1, modp_vardnsrecdegspspol_getargs (self));
  return modp_vardnsrecdegspspol_c2id (self, &c);
}

- _add:(int)v:b:(int)w
{
  modp_vardnsrecdegspspol_c c;
  assert ([self sameClass:b] && v * v == 1 && w * w == 1 && self != b);
  modp_vardnsrecdegspspol_ooadd (&c, modp_vardnsrecdegspspol_id2t (self), v, modp_vardnsrecdegspspol_id2t (b), w, modp_vardnsrecdegspspol_getargs (self));
  return modp_vardnsrecdegspspol_c2id (self, &c);
}

- add:b
{
  modp_vardnsrecdegspspol_c c;
  assert ([self checkSameClass:b] && self != b);
  modp_vardnsrecdegspspol_ooadd (&c, modp_vardnsrecdegspspol_id2t (self), +1, modp_vardnsrecdegspspol_id2t (b), +1, modp_vardnsrecdegspspol_getargs (self));
  return modp_vardnsrecdegspspol_c2id (self, &c);
}

- subtract:b
{
  modp_vardnsrecdegspspol_c c;
  assert ([self checkSameClass:b] && self != b);
  modp_vardnsrecdegspspol_ooadd (&c, modp_vardnsrecdegspspol_id2t (self), +1, modp_vardnsrecdegspspol_id2t (b), -1, modp_vardnsrecdegspspol_getargs (self));
  return modp_vardnsrecdegspspol_c2id (self, &c);
}

- (int) leadingDegree
{
  return modp_vardnsrecdegspspol_deg (&value, modp_vardnsrecdegspspol_getargs (self));
}

- (int) lastDegree
{
  return modp_vardnsrecdegspspol_ord (&value, modp_vardnsrecdegspspol_getargs (self));
}

- (int) maxDegree
{
  return modp_vardnsrecdegspspol_maxdeg (&value, modp_vardnsrecdegspspol_getargs (self));
}

- (int) minDegree
{
  return modp_vardnsrecdegspspol_mindeg (&value, modp_vardnsrecdegspspol_getargs (self));
}

- asScalar
{
  if ([self size] == 1)
    {
      id asScalar, lastTerm, aSequence = [self eachElement];
      asScalar = (lastTerm = [aSequence lastElement]) ? [lastTerm asScalar] : nil;
      return asScalar;
    }
  else
    {
      return nil;
    }
}

- asSymbol
{
  if ([self size] == 1)
    {
      id asSymbol, lastTerm, aSequence = [self eachElement];
      asSymbol = (lastTerm = [aSequence lastElement]) ? [lastTerm asSymbol] : nil;
      return asSymbol;
    }
  else
    {
      return nil;
    }
}

- check
{
  [super check];
  [scalarZero check];
  [termZero check];
  [monomialZero check];
  [symbols check];
  assert ([symbols size] >= 1);
  assert ([scalarZero isEqual:[monomialZero scalar]]);
  assert ([symbols isEqual:[monomialZero symbols]]);
  assert ([termZero isZero] && [termZero exponent] == 1 && [termZero symbol] != nil);
  assert ([[symbols lastElement] isEqual:[termZero symbol]]);

  modp_vardnsrecdegspspol_check (&value, modp_vardnsrecdegspspol_getargs (self));
  return self;
}

- release
{
  modp_vardnsrecdegspspol_clear (&value, modp_vardnsrecdegspspol_getargs (self));
  return [super release];
}

- scalarZero   
{
  return scalarZero;
}
- termZero     
{
  return termZero;
}
- monomialZero 
{
  return monomialZero;
}
- symbols      
{
  return symbols;
}

- eachTerm
{
  id aSequence = [modp_vardnsrecdegspspol_sequence content:self];
  return [CASequence over:aSequence];
}

- elt_modp_vardnsrecdegspspol_ix:(modp_vardnsrecdegspspol_ixt)ix
{
  if (modp_vardnsrecdegspspol_ix_ismatch (ix))
    {
      id c, s;
      int e;
      modp_t t;
      t = modp_vardnsrecdegspspol_scalat (&value, ix, modp_vardnsrecdegspspol_getargs (self));
      e = modp_vardnsrecdegspspol_expat (&value, ix, modp_vardnsrecdegspspol_getargs (self));
      c = modp_t2id ([termZero coefficient], t);
      s = (e) ? [termZero symbol] : nil;
      return [termZero coefficient:c symbol:s exponent:e];
    }
  else
    {
      return nil;
    }
}
- removeTerm
{
  if ([self isEmpty])
    {
      return nil;
    }
  else
    {
      id lt;
      id c, s;
      int e;
      modp_t t;
      assert ([self check]);

      t = modp_vardnsrecdegspspol_scalfirst (&value, modp_vardnsrecdegspspol_getargs (self));
      e = modp_vardnsrecdegspspol_expfirst (&value, modp_vardnsrecdegspspol_getargs (self));
      c = modp_t2id ([termZero coefficient], t);
      s = (e) ? [termZero symbol] : nil;
      lt = [termZero coefficient:c symbol:s exponent:e];

      modp_vardnsrecdegspspol_remove (&value, modp_vardnsrecdegspspol_getargs (self));
      [self invalidate];
      assert ([self check]);
      return lt;
    }
}

- insertTerm:aTerm
{
  if ([aTerm isZero])
    {
      return self;
    }
  else
    {
      modp_c c;
      modp_t r;
      int e;
      assert ([aTerm check]);
      assert ([self check]);
      r = modp_id2ref ([aTerm coefficient], &c);
      e = [aTerm exponent];
      modp_vardnsrecdegspspol_insert (&value, e, r, modp_vardnsrecdegspspol_getargs (self));
      assert ([aTerm check]);
      [self invalidate];
      assert ([self check]);
      return self;
    }
}

- multiplyCoefficient:s
{
  modp_vardnsrecdegspspol_c c;
  modp_c sc;
  modp_vardnsrecdegspspol_oomulsc (&c, modp_vardnsrecdegspspol_id2t (self), modp_id2ref (s, &sc), modp_vardnsrecdegspspol_getargs (self));
  return modp_vardnsrecdegspspol_c2id (self, &c);
}

- divideCoefficient:s
{
  modp_vardnsrecdegspspol_c c;
  modp_c sc;
  BOOL failed = modp_vardnsrecdegspspol_oodivsc (&c, modp_vardnsrecdegspspol_id2t (self), modp_id2ref (s, &sc), modp_vardnsrecdegspspol_getargs (self));
  return (failed) ? nil : modp_vardnsrecdegspspol_c2id (self, &c);
}

- _add:(int)v:B multiplyCoefficient:b:(int)w
{
  modp_vardnsrecdegspspol_c c;
  modp_c bc;
  modp_vardnsrecdegspspol_ooaddmulsc (&c, modp_vardnsrecdegspspol_id2t (self), v, modp_vardnsrecdegspspol_id2t (B), modp_id2ref (b, &bc), w, modp_vardnsrecdegspspol_getargs (self));
  return modp_vardnsrecdegspspol_c2id (self, &c);
}

- _multiplyCoefficient:a:(int)v add:B:(int)w
{
  modp_vardnsrecdegspspol_c c;
  modp_c ac;
  modp_vardnsrecdegspspol_oomulscadd (&c, modp_vardnsrecdegspspol_id2t (self), modp_id2ref (a, &ac), v, modp_vardnsrecdegspspol_id2t (B), w, modp_vardnsrecdegspspol_getargs (self));
  return modp_vardnsrecdegspspol_c2id (self, &c);
}

- _multiplyCoefficient:a:(int)v add:B multiplyCoefficient:b:(int)w
{
  modp_vardnsrecdegspspol_c c;
  modp_c ac, bc;
  modp_vardnsrecdegspspol_oomulscaddmulsc (&c, modp_vardnsrecdegspspol_id2t (self), modp_id2ref (a, &ac), v, modp_vardnsrecdegspspol_id2t (B), modp_id2ref (b, &bc), w, modp_vardnsrecdegspspol_getargs (self));
  return modp_vardnsrecdegspspol_c2id (self, &c);
}

- multiplyTerm:aTerm
{
  modp_vardnsrecdegspspol_c c;
  modp_t s;
  modp_c sc;
  s = modp_id2ref ([aTerm coefficient], &sc);
  modp_vardnsrecdegspspol_oomulmonomsc (&c, modp_vardnsrecdegspspol_id2t (self), [aTerm exponent], s, +1, modp_vardnsrecdegspspol_getargs (self));
  return modp_vardnsrecdegspspol_c2id (self, &c);
}

- _multiplyTerm:aTerm:(int)v
{
  modp_vardnsrecdegspspol_c c;
  modp_t s;
  modp_c sc;
  s = modp_id2ref ([aTerm coefficient], &sc);
  modp_vardnsrecdegspspol_oomulmonomsc (&c, modp_vardnsrecdegspspol_id2t (self), [aTerm exponent], s, v, modp_vardnsrecdegspspol_getargs (self));
  return modp_vardnsrecdegspspol_c2id (self, &c);
}

- divideTerm:aTerm
{
  int e;
  modp_vardnsrecdegspspol_c c;
  BOOL failed;
  modp_t s;
  modp_c sc;

  e = [aTerm exponent];
  s = modp_id2ref ([aTerm coefficient], &sc);
  failed = modp_vardnsrecdegspspol_oodivmonomsc (&c, modp_vardnsrecdegspspol_id2t (self), e, s, modp_vardnsrecdegspspol_getargs (self));
  return (failed) ? nil : modp_vardnsrecdegspspol_c2id (self, &c);
}

- _add:(int)v:B multiplyTerm:b:(int)w
{
  modp_vardnsrecdegspspol_c c;
  modp_c bc;
  modp_t bs;
  bs = modp_id2ref ([b coefficient], &bc);
  modp_vardnsrecdegspspol_ooaddmulmonomsc (&c, modp_vardnsrecdegspspol_id2c (self), v, modp_vardnsrecdegspspol_id2t (B), [b exponent], bs, w, modp_vardnsrecdegspspol_getargs (self));
  return modp_vardnsrecdegspspol_c2id (self, &c);
}

- _multiplyCoefficient:a:(int)v add:B multiplyTerm:b:(int)w
{
  modp_vardnsrecdegspspol_c c;
  modp_c ac, bc;
  modp_t as, bs;
  as = modp_id2ref (a, &ac);
  bs = modp_id2ref ([b coefficient], &bc);
  modp_vardnsrecdegspspol_oomulscaddmulmonomsc (&c, modp_vardnsrecdegspspol_id2c (self), as, v, modp_vardnsrecdegspspol_id2t (B), [b exponent], bs, w, modp_vardnsrecdegspspol_getargs (self));
  return modp_vardnsrecdegspspol_c2id (self, &c);
}


- fileOutOn:aFiler
{
  modp_vardnsrecdegspspol_args args;
  [super fileOutOn:aFiler];
  args = modp_vardnsrecdegspspol_getargs (self);	/* can't do this in fileIn case */
  modp_vardnsrecdegspspol_args_fileOut (aFiler, &args);
  modp_vardnsrecdegspspol_fileOut (aFiler, &value, args);
  return self;
}

- fileInFrom:aFiler
{
  modp_vardnsrecdegspspol_args args;
  [super fileInFrom:aFiler];
  modp_vardnsrecdegspspol_args_fileIn (aFiler, &args);
  modp_vardnsrecdegspspol_fileIn (aFiler, &value, args);
  return self;
}

@end
 
