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
 * $Id: mdespolc.m,v 1.6 2000/10/12 14:40:26 stes Exp $
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
vardnsmonom_size (vardnsmonom_args args)
{
  return args.nvars;		/* size to add to int pointer */
}

static int 
vardnsmonom_bsize (vardnsmonom_args args)
{
  return args.nvars * sizeof (int);	/* byte size exponent array */
}

static int 
vardnsmonom_check (vardnsmonom_t self, vardnsmonom_args args)
{
  int nvars = args.nvars;
  while (nvars--)
    assert (*self++ >= 0);
  return 1;
}

static vardnsmonom_t 
vardnsmonom_id2t (id object)
{
  return [object vardnsmonom_value];
}

static id 
vardnsmonom_t2id (id proto, vardnsmonom_t f)
{
  return [proto vardnsmonom_value:f];
}

static vardnsmonom_args 
vardnsmonom_getargs (id self)
{
  vardnsmonom_args res;
  res.nvars = [[self symbols] size];
  return res;
}

static vardnsmonom_t 
vardnsmonom_alloc (vardnsmonom_args args)
{
  return (vardnsmonom_t) OC_Malloc (vardnsmonom_bsize (args));
}

static void 
vardnsmonom_init (vardnsmonom_c * c, vardnsmonom_args args)
{
  int nvars = args.nvars;
  while (nvars--)
    *c++ = 0;
}

static void 
vardnsmonom_copy (vardnsmonom_c * c, vardnsmonom_t a, vardnsmonom_args args)
{
  int nvars = args.nvars;
  while (nvars--)
    *c++ = *a++;
}

static void 
vardnsmonom_clear (vardnsmonom_c * c, vardnsmonom_args args)
{
  /* nothing to clear... */
}

static void 
vardnsmonom_free (vardnsmonom_c * c, vardnsmonom_args args)
{
  OC_Free (c);
}

static void 
vardnsmonom_args_fileOut (id aFiler, vardnsmonom_args * args)
{
  [aFiler fileOut:&args->nvars type:'i'];
}

static void 
vardnsmonom_args_fileIn (id aFiler, vardnsmonom_args * args)
{
  [aFiler fileIn:&args->nvars type:'i'];
}

static void 
vardnsmonom_fileOut (id aFiler, vardnsmonom_c * c, vardnsmonom_args args)
{
  int n = args.nvars;
  while (n--)
    [aFiler fileOut:c++ type:'i'];
}

static void 
vardnsmonom_fileIn (id aFiler, vardnsmonom_c * c, vardnsmonom_args args)
{
  int n = args.nvars;
  while (n--)
    [aFiler fileIn:c++ type:'i'];
}

static unsigned 
vardnsmonom_hash (vardnsmonom_t self, vardnsmonom_args args)
{
  assert (args.nvars > 0);
  return self [0];
}

static int 
vardnsmonom_deg (vardnsmonom_t self, vardnsmonom_args args)
{
  int sum = 0;
  int nvars = args.nvars;
  while (nvars--)
    sum += *self++;
  return sum;
}

static int 
vardnsmonom_numterms (vardnsmonom_t self, vardnsmonom_args args)
{
  int numterms = 0;
  int nvars = args.nvars;
  while (nvars--)
    if (*self++)
      numterms++;
  return numterms;
}

static int 
vardnsmonom_isone (vardnsmonom_t self, vardnsmonom_args args)
{
  int nvars = args.nvars;
  while (nvars--)
    {
      if (*self)
	return 0;
      self++;
    }
  return 1;
}

static int 
vardnsmonom_iseq (vardnsmonom_t a, vardnsmonom_t b, vardnsmonom_args args)
{
  int nvars = args.nvars;
  while (nvars--)
    {
      if ((*a) != (*b))
	return 0;
      a++;
      b++;
    }
  return 1;
}

static int 
vardnsmonom_iseqmul (vardnsmonom_t a, vardnsmonom_t x, vardnsmonom_t b, vardnsmonom_args args)
{
  int nvars = args.nvars;
  while (nvars--)
    {
      if ((*a) != (*x) + (*b))
	return 0;
      a++;
      x++;
      b++;
    }
  return 1;
}

static int 
vardnsmonom_cmp (vardnsmonom_t a, vardnsmonom_t b, vardnsmonom_args args)
{
  int nvars = args.nvars;

  /* lexicographic cmp *MUST* work from right to left
   * because last symbol is largest for vardns order
   */

  while (nvars--)
    {
      if ((*a) < (*b))
	return -1;
      if ((*a) > (*b))
	return +1;
      a++;
      b++;
    }

  return 0;
}

static int 
vardnsmonom_cmpmul (vardnsmonom_t a, vardnsmonom_t x, vardnsmonom_t b, vardnsmonom_args args)
{
  int nvars = args.nvars;

  /* lexicographic cmp *MUST* work from right to left
   * because last symbol is largest for vardns order
   */

  while (nvars--)
    {
      int sum = *x + *b;
      if ((*a) < sum)
	return -1;
      if ((*a) > sum)
	return +1;
      a++;
      x++;
      b++;
    }

  return 0;
}

static void 
vardnsmonom_oomul (vardnsmonom_c * c, vardnsmonom_t a, vardnsmonom_t b, vardnsmonom_args args)
{
  int nvars = args.nvars;
  while (nvars--)
    {
      (*c) = (*a) + (*b);
      c++;
      a++;
      b++;
    }
}

static void 
vardnsmonom_inmul (vardnsmonom_c * c, vardnsmonom_t b, vardnsmonom_args args)
{
  int nvars = args.nvars;
  while (nvars--)
    {
      (*c) += (*b);
      c++;
      b++;
    }
}

static BOOL 
vardnsmonom_oodiv (vardnsmonom_c * c, vardnsmonom_t a, vardnsmonom_t b, vardnsmonom_args args)
{
  int nvars = args.nvars;
  while (nvars--)
    {
      int q = *a - *b;
      if (q < 0)
	return FAILURE;
      *c = q;
      c++;
      a++;
      b++;
    }

  return SUCCESS;
}

static void 
vardnsmonom_indiv (vardnsmonom_c * c, vardnsmonom_t b, vardnsmonom_args args)
{
  int nvars = args.nvars;
  while (nvars--)
    {
      int q = *c - *b;
      if (q < 0)
	{
	  fprintf (stderr, "Division not Exact\n");
	  abort ();
	}			/* should stay */
      *c = q;
      c++;
      b++;
    }
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

static vardnsmonom_c *
modp_vardnsexpdegspsterm_monom_cval (modp_vardnsexpdegspsterm_t self)
{
  return &self->data;
}

static vardnsmonom_t 
modp_vardnsexpdegspsterm_monom (modp_vardnsexpdegspsterm_t self)
{
#if vardnsmonom_pervalue
  return self->data;
#else
  return modp_vardnsexpdegspsterm_monom_cval (self);
#endif
}

/* stes - mar31,1997
 * change for DEC alpha to exclude varsized scalars
 */

static modp_c *
modp_vardnsexpdegspsterm_scal_cval (modp_vardnsexpdegspsterm_t self, modp_vardnsexpdegspsterm_args args)
{
  return &self->scal;
}

static modp_t 
modp_vardnsexpdegspsterm_scal (modp_vardnsexpdegspsterm_t self, modp_vardnsexpdegspsterm_args args)
{
#if modp_pervalue
  return self->scal;
#else
  return modp_vardnsexpdegspsterm_scal_cval (self, args);
#endif
}

static int 
modp_vardnsexpdegspsterm_check (modp_vardnsexpdegspsterm_t self, modp_vardnsexpdegspsterm_args args)
{
  assert (modp_check (modp_vardnsexpdegspsterm_scal (self, args), args.sargs));
  assert (!modp_iszero (modp_vardnsexpdegspsterm_scal (self, args), args.sargs));
  assert (vardnsmonom_check (modp_vardnsexpdegspsterm_monom (self), args.margs));
  return 1;
}

static int 
modp_vardnsexpdegspsterm_bsize (modp_vardnsexpdegspsterm_args args)
{
  /* this is sizeof(vardnsmonom_c) too much but why bother ? */
  return sizeof (struct modp_vardnsexpdegspsterm) + vardnsmonom_bsize (args.margs);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_alloc (modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_t p;
  int n = modp_vardnsexpdegspsterm_bsize (args);
  p = (modp_vardnsexpdegspsterm_t) OC_Malloc (n);
#if OBJC_REFCNT
  memset (p, 0, n);
#endif
  return p;
}

static void 
modp_vardnsexpdegspsterm_clear (modp_vardnsexpdegspsterm_t self, modp_vardnsexpdegspsterm_args args)
{
  vardnsmonom_clear (modp_vardnsexpdegspsterm_monom_cval (self), args.margs);
  modp_clear (modp_vardnsexpdegspsterm_scal_cval (self, args), args.sargs);
}

static void 
modp_vardnsexpdegspsterm_free (modp_vardnsexpdegspsterm_t self, modp_vardnsexpdegspsterm_args args)
{
  /* invalidating links not always helps : buggy code might work because
   * links were cleared...        self->nlink = NULL;self->plink = NULL;
   */
  OC_Free (self);
}

static int 
modp_vardnsexpdegspsterm_cmp (modp_vardnsexpdegspsterm_t a, modp_vardnsexpdegspsterm_t b, modp_vardnsexpdegspsterm_args args)
{
  assert (modp_vardnsexpdegspsterm_check (a, args) && modp_vardnsexpdegspsterm_check (b, args));
  return vardnsmonom_cmp (modp_vardnsexpdegspsterm_monom (a), modp_vardnsexpdegspsterm_monom (b), args.margs);
}

static int 
modp_vardnsexpdegspsterm_cmpmonom (modp_vardnsexpdegspsterm_t a, vardnsmonom_t b, modp_vardnsexpdegspsterm_args args)
{
  assert (modp_vardnsexpdegspsterm_check (a, args) && vardnsmonom_check (b, args.margs));
  return vardnsmonom_cmp (modp_vardnsexpdegspsterm_monom (a), b, args.margs);
}

static int 
modp_vardnsexpdegspsterm_cmpmul (modp_vardnsexpdegspsterm_t a, modp_vardnsexpdegspsterm_t b, vardnsmonom_t m, modp_vardnsexpdegspsterm_args args)
{
  assert (modp_vardnsexpdegspsterm_check (a, args) && modp_vardnsexpdegspsterm_check (b, args));
  assert (vardnsmonom_check (m, args.margs));
  return vardnsmonom_cmpmul (modp_vardnsexpdegspsterm_monom (a), modp_vardnsexpdegspsterm_monom (b), m, args.margs);
}

static int 
modp_vardnsexpdegspsterm_deg (modp_vardnsexpdegspsterm_t a, modp_vardnsexpdegspsterm_args args)
{
  return vardnsmonom_deg (modp_vardnsexpdegspsterm_monom (a), args.margs);
}

static int 
modp_vardnsexpdegspsterm_iszero (modp_vardnsexpdegspsterm_t self, modp_vardnsexpdegspsterm_args args)
{
  return modp_iszero (modp_vardnsexpdegspsterm_scal (self, args), args.sargs);
}

static int 
modp_vardnsexpdegspsterm_isone (modp_vardnsexpdegspsterm_t self, modp_vardnsexpdegspsterm_args args)
{
  return modp_isone (modp_vardnsexpdegspsterm_scal (self, args), args.sargs) && vardnsmonom_isone (modp_vardnsexpdegspsterm_monom (self), args.margs);
}

static int 
modp_vardnsexpdegspsterm_isminusone (modp_vardnsexpdegspsterm_t self, modp_vardnsexpdegspsterm_args args)
{
  return modp_isminusone (modp_vardnsexpdegspsterm_scal (self, args), args.sargs) && vardnsmonom_isone (modp_vardnsexpdegspsterm_monom (self), args.margs);
}

static int 
modp_vardnsexpdegspsterm_iseq (modp_vardnsexpdegspsterm_t a, modp_vardnsexpdegspsterm_t b, modp_vardnsexpdegspsterm_args args)
{
  assert (modp_vardnsexpdegspsterm_check (a, args) && modp_vardnsexpdegspsterm_check (b, args));
  return vardnsmonom_iseq (modp_vardnsexpdegspsterm_monom (a), modp_vardnsexpdegspsterm_monom (b), args.margs) && modp_iseq (modp_vardnsexpdegspsterm_scal (a, args), modp_vardnsexpdegspsterm_scal (b, args), args.sargs);
}

static int 
modp_vardnsexpdegspsterm_isop (modp_vardnsexpdegspsterm_t a, modp_vardnsexpdegspsterm_t b, modp_vardnsexpdegspsterm_args args)
{
  assert (modp_vardnsexpdegspsterm_check (a, args) && modp_vardnsexpdegspsterm_check (b, args));
  return vardnsmonom_iseq (modp_vardnsexpdegspsterm_monom (a), modp_vardnsexpdegspsterm_monom (b), args.margs) && modp_isop (modp_vardnsexpdegspsterm_scal (a, args), modp_vardnsexpdegspsterm_scal (b, args), args.sargs);
}

static void 
modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A)
{
  C->nlink = A;
  A->plink = C;
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A)
{
  modp_vardnsexpdegspsterm_glue (C, A);
  return A;
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_delete (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_t C = A->nlink;
  modp_vardnsexpdegspsterm_glue (A->plink, C);
  modp_vardnsexpdegspsterm_clear (A, args);
  modp_vardnsexpdegspsterm_free (A, args);
  return C;
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_condcns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t new, modp_vardnsexpdegspsterm_args args)
{
  if (modp_vardnsexpdegspsterm_iszero (new, args))
    {
      modp_vardnsexpdegspsterm_clear (new, args);
      modp_vardnsexpdegspsterm_free (new, args);
      return C;
    }
  else
    {
      assert (modp_vardnsexpdegspsterm_check (new, args));
      return modp_vardnsexpdegspsterm_cns (C, new);
    }
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_conddelete (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_args args)
{
  if (modp_vardnsexpdegspsterm_iszero (A, args))
    {
      return modp_vardnsexpdegspsterm_delete (A, args);
    }
  else
    {
      return A->nlink;
    }
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_copymonomsc_cns (modp_vardnsexpdegspsterm_t C, vardnsmonom_t m, modp_t s, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_t new = modp_vardnsexpdegspsterm_alloc (args);

  modp_copy (modp_vardnsexpdegspsterm_scal_cval (new, args), s, args.sargs);
  vardnsmonom_copy (modp_vardnsexpdegspsterm_monom_cval (new), m, args.margs);

  assert (modp_vardnsexpdegspsterm_check (new, args));
  return modp_vardnsexpdegspsterm_cns (C, new);
}

static void 
modp_vardnsexpdegspsterm_copymonomsc (modp_vardnsexpdegspsterm_t C, vardnsmonom_t m, modp_t s, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspsterm_copymonomsc_cns (C, m, s, args), CT);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_deepcopymonomsc_cns (modp_vardnsexpdegspsterm_t C, vardnsmonom_t m, modp_t s, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_t new = modp_vardnsexpdegspsterm_alloc (args);

  modp_deepcopy (modp_vardnsexpdegspsterm_scal_cval (new, args), s, args.sargs);
  vardnsmonom_copy (modp_vardnsexpdegspsterm_monom_cval (new), m, args.margs);

  assert (modp_vardnsexpdegspsterm_check (new, args));
  return modp_vardnsexpdegspsterm_cns (C, new);
}

static void 
modp_vardnsexpdegspsterm_deepcopymonomsc (modp_vardnsexpdegspsterm_t C, vardnsmonom_t m, modp_t s, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspsterm_deepcopymonomsc_cns (C, m, s, args), CT);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_copy_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_args args)
{
  return modp_vardnsexpdegspsterm_copymonomsc_cns (C, modp_vardnsexpdegspsterm_monom (A), modp_vardnsexpdegspsterm_scal (A, args), args);
}

static void 
modp_vardnsexpdegspsterm_copy (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspsterm_copy_cns (C, A, args), CT);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_deepcopy_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_args args)
{
  return modp_vardnsexpdegspsterm_deepcopymonomsc_cns (C, modp_vardnsexpdegspsterm_monom (A), modp_vardnsexpdegspsterm_scal (A, args), args);
}

static void 
modp_vardnsexpdegspsterm_deepcopy (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspsterm_deepcopy_cns (C, A, args), CT);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_ooneg_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_t new = modp_vardnsexpdegspsterm_alloc (args);
  assert (modp_vardnsexpdegspsterm_iszero (A, args) == NO);

  modp_ooneg (modp_vardnsexpdegspsterm_scal_cval (new, args), modp_vardnsexpdegspsterm_scal (A, args), args.sargs);
  vardnsmonom_copy (modp_vardnsexpdegspsterm_monom_cval (new), modp_vardnsexpdegspsterm_monom (A), args.margs);

  return modp_vardnsexpdegspsterm_cns (C, new);
}

static void 
modp_vardnsexpdegspsterm_ooneg (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspsterm_ooneg_cns (C, A, args), CT);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_inneg (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_args args)
{
  assert (modp_vardnsexpdegspsterm_iszero (A, args) == NO);
  modp_inneg (modp_vardnsexpdegspsterm_scal_cval (A, args), args.sargs);
  assert (modp_vardnsexpdegspsterm_iszero (A, args) == NO);
  return A->nlink;
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_oonegv_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, int v, modp_vardnsexpdegspsterm_args args)
{
  return (v == -1) ? modp_vardnsexpdegspsterm_ooneg_cns (C, A, args) : modp_vardnsexpdegspsterm_copy_cns (C, A, args);
}

static void 
modp_vardnsexpdegspsterm_oonegv (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, int v, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspsterm_oonegv_cns (C, A, v, args), CT);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_innegv (modp_vardnsexpdegspsterm_t A, int v, modp_vardnsexpdegspsterm_args args)
{
  return (v == -1) ? modp_vardnsexpdegspsterm_inneg (A, args) : A->nlink;
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_oodbl_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, int v, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_t new = modp_vardnsexpdegspsterm_alloc (args);
  assert (modp_vardnsexpdegspsterm_iszero (A, args) == NO);

  modp_oodbl (modp_vardnsexpdegspsterm_scal_cval (new, args), modp_vardnsexpdegspsterm_scal (A, args), v, args.sargs);
  vardnsmonom_copy (modp_vardnsexpdegspsterm_monom_cval (new), modp_vardnsexpdegspsterm_monom (A), args.margs);

  return modp_vardnsexpdegspsterm_condcns (C, new, args);
}

static void 
modp_vardnsexpdegspsterm_oodbl (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, int v, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspsterm_oodbl_cns (C, A, v, args), CT);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_indbl (modp_vardnsexpdegspsterm_t A, int v, modp_vardnsexpdegspsterm_args args)
{
  assert (modp_vardnsexpdegspsterm_iszero (A, args) == NO);
  modp_indbl (modp_vardnsexpdegspsterm_scal_cval (A, args), v, args.sargs);
  return modp_vardnsexpdegspsterm_conddelete (A, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_ooaddsc_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, int v, modp_t B, int w, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_t new = modp_vardnsexpdegspsterm_alloc (args);
  modp_ooadd (modp_vardnsexpdegspsterm_scal_cval (new, args), modp_vardnsexpdegspsterm_scal (A, args), v, B, w, args.sargs);
  vardnsmonom_copy (modp_vardnsexpdegspsterm_monom_cval (new), modp_vardnsexpdegspsterm_monom (A), args.margs);
  return modp_vardnsexpdegspsterm_condcns (C, new, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_inaddsc (modp_vardnsexpdegspsterm_t A, int v, modp_t B, int w, modp_vardnsexpdegspsterm_args args)
{
  modp_inadd (modp_vardnsexpdegspsterm_scal_cval (A, args), v, B, w, args.sargs);
  return modp_vardnsexpdegspsterm_conddelete (A, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_ooadd_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, int v, modp_vardnsexpdegspsterm_t B, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (0 == modp_vardnsexpdegspsterm_cmp (A, B, args));
  assert (modp_vardnsexpdegspsterm_iszero (A, args) == NO && modp_vardnsexpdegspsterm_iszero (B, args) == NO);
  return modp_vardnsexpdegspsterm_ooaddsc_cns (C, A, v, modp_vardnsexpdegspsterm_scal (B, args), w, args);
}

static void 
modp_vardnsexpdegspsterm_ooadd (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, int v, modp_vardnsexpdegspsterm_t B, int w, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspsterm_ooadd_cns (C, A, v, B, w, args), CT);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_inadd (modp_vardnsexpdegspsterm_t A, int v, modp_vardnsexpdegspsterm_t B, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (0 == modp_vardnsexpdegspsterm_cmp (A, B, args));
  assert (modp_vardnsexpdegspsterm_iszero (A, args) == NO && modp_vardnsexpdegspsterm_iszero (B, args) == NO);
  return modp_vardnsexpdegspsterm_inaddsc (A, v, modp_vardnsexpdegspsterm_scal (B, args), w, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_oomulsc_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_t s, int v, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_t new = modp_vardnsexpdegspsterm_alloc (args);

  modp_oomulv (modp_vardnsexpdegspsterm_scal_cval (new, args), modp_vardnsexpdegspsterm_scal (A, args), s, v, args.sargs);
  vardnsmonom_copy (modp_vardnsexpdegspsterm_monom_cval (new), modp_vardnsexpdegspsterm_monom (A), args.margs);

  return modp_vardnsexpdegspsterm_condcns (C, new, args);
}

static void 
modp_vardnsexpdegspsterm_oomulsc (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_t s, int v, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspsterm_oomulsc_cns (C, A, s, v, args), CT);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_inmulsc (modp_vardnsexpdegspsterm_t A, modp_t s, int v, modp_vardnsexpdegspsterm_args args)
{
  modp_inmulv (modp_vardnsexpdegspsterm_scal_cval (A, args), s, v, args.sargs);
  return modp_vardnsexpdegspsterm_conddelete (A, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_oomulmonomsc_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, vardnsmonom_t m, modp_t s, int v, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_t new = modp_vardnsexpdegspsterm_alloc (args);

  modp_oomulv (modp_vardnsexpdegspsterm_scal_cval (new, args), modp_vardnsexpdegspsterm_scal (A, args), s, v, args.sargs);
  vardnsmonom_oomul (modp_vardnsexpdegspsterm_monom_cval (new), modp_vardnsexpdegspsterm_monom (A), m, args.margs);

  return modp_vardnsexpdegspsterm_condcns (C, new, args);
}

static void 
modp_vardnsexpdegspsterm_oomulmonomsc (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, vardnsmonom_t m, modp_t s, int v, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspsterm_oomulmonomsc_cns (C, A, m, s, v, args), CT);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_inmulmonomsc (modp_vardnsexpdegspsterm_t A, vardnsmonom_t m, modp_t s, int v, modp_vardnsexpdegspsterm_args args)
{
  modp_inmulv (modp_vardnsexpdegspsterm_scal_cval (A, args), s, v, args.sargs);
  vardnsmonom_inmul (modp_vardnsexpdegspsterm_monom_cval (A), m, args.margs);

  return modp_vardnsexpdegspsterm_conddelete (A, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_ooaddscmulsc_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, int v, modp_t B, modp_t t, int w, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_t new = modp_vardnsexpdegspsterm_alloc (args);

  modp_ooaddmul (modp_vardnsexpdegspsterm_scal_cval (new, args), modp_vardnsexpdegspsterm_scal (A, args), v, B, t, w, args.sargs);
  vardnsmonom_copy (modp_vardnsexpdegspsterm_monom_cval (new), modp_vardnsexpdegspsterm_monom (A), args.margs);

  return modp_vardnsexpdegspsterm_condcns (C, new, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_inaddscmulsc (modp_vardnsexpdegspsterm_t A, int v, modp_t B, modp_t t, int w, modp_vardnsexpdegspsterm_args args)
{
  modp_inaddmul (modp_vardnsexpdegspsterm_scal_cval (A, args), v, B, t, w, args.sargs);
  return modp_vardnsexpdegspsterm_conddelete (A, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_ooaddmulsc_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, int v, modp_vardnsexpdegspsterm_t B, modp_t t, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (0 == (modp_vardnsexpdegspsterm_cmp (A, B, args)));
  return modp_vardnsexpdegspsterm_ooaddscmulsc_cns (C, A, v, modp_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_ooaddmulmonomsc_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, int v, modp_vardnsexpdegspsterm_t B, vardnsmonom_t m, modp_t t, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (0 == (modp_vardnsexpdegspsterm_cmpmul (A, B, m, args)));
  return modp_vardnsexpdegspsterm_ooaddscmulsc_cns (C, A, v, modp_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static void 
modp_vardnsexpdegspsterm_ooaddmulsc (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, int v, modp_vardnsexpdegspsterm_t B, modp_t t, int w, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspsterm_ooaddmulsc_cns (C, A, v, B, t, w, args), CT);
}

static void 
modp_vardnsexpdegspsterm_ooaddmulmonomsc (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, int v, modp_vardnsexpdegspsterm_t B, vardnsmonom_t m, modp_t t, int w, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspsterm_ooaddmulmonomsc_cns (C, A, v, B, m, t, w, args), CT);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_inaddmulsc (modp_vardnsexpdegspsterm_t A, int v, modp_vardnsexpdegspsterm_t B, modp_t t, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (0 == (modp_vardnsexpdegspsterm_cmp (A, B, args)));
  return modp_vardnsexpdegspsterm_inaddscmulsc (A, v, modp_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_inaddmulmonomsc (modp_vardnsexpdegspsterm_t A, int v, modp_vardnsexpdegspsterm_t B, vardnsmonom_t m, modp_t t, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (0 == (modp_vardnsexpdegspsterm_cmpmul (A, B, m, args)));
  return modp_vardnsexpdegspsterm_inaddscmulsc (A, v, modp_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_oomulscaddsc_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_t s, int v, modp_t B, int w, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_t new = modp_vardnsexpdegspsterm_alloc (args);

  modp_oomuladd (modp_vardnsexpdegspsterm_scal_cval (new, args), modp_vardnsexpdegspsterm_scal (A, args), s, v, B, w, args.sargs);
  vardnsmonom_copy (modp_vardnsexpdegspsterm_monom_cval (new), modp_vardnsexpdegspsterm_monom (A), args.margs);

  return modp_vardnsexpdegspsterm_condcns (C, new, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_inmulscaddsc (modp_vardnsexpdegspsterm_t A, modp_t s, int v, modp_t B, int w, modp_vardnsexpdegspsterm_args args)
{
  modp_inmuladd (modp_vardnsexpdegspsterm_scal_cval (A, args), s, v, B, w, args.sargs);
  return modp_vardnsexpdegspsterm_conddelete (A, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_oomulscadd_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_t s, int v, modp_vardnsexpdegspsterm_t B, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (0 == (modp_vardnsexpdegspsterm_cmp (A, B, args)));
  return modp_vardnsexpdegspsterm_oomulscaddsc_cns (C, A, s, v, modp_vardnsexpdegspsterm_scal (B, args), w, args);
}

static void 
modp_vardnsexpdegspsterm_oomulscadd (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_t s, int v, modp_vardnsexpdegspsterm_t B, int w, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspsterm_oomulscadd_cns (C, A, s, v, B, w, args), CT);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_inmulscadd (modp_vardnsexpdegspsterm_t A, modp_t s, int v, modp_vardnsexpdegspsterm_t B, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (0 == (modp_vardnsexpdegspsterm_cmp (A, B, args)));
  return modp_vardnsexpdegspsterm_inmulscaddsc (A, s, v, modp_vardnsexpdegspsterm_scal (B, args), w, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_oomulscaddscmulsc_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_t s, int v, modp_t B, modp_t t, int w, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_t new = modp_vardnsexpdegspsterm_alloc (args);
  modp_oomuladdmul (modp_vardnsexpdegspsterm_scal_cval (new, args), modp_vardnsexpdegspsterm_scal (A, args), s, v, B, t, w, args.sargs);
  vardnsmonom_copy (modp_vardnsexpdegspsterm_monom_cval (new), modp_vardnsexpdegspsterm_monom (A), args.margs);

  return modp_vardnsexpdegspsterm_condcns (C, new, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_inmulscaddscmulsc (modp_vardnsexpdegspsterm_t A, modp_t s, int v, modp_t B, modp_t t, int w, modp_vardnsexpdegspsterm_args args)
{
  modp_inmuladdmul (modp_vardnsexpdegspsterm_scal_cval (A, args), s, v, B, t, w, args.sargs);
  return modp_vardnsexpdegspsterm_conddelete (A, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_oomulscaddmulsc_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_t s, int v, modp_vardnsexpdegspsterm_t B, modp_t t, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (0 == (modp_vardnsexpdegspsterm_cmp (A, B, args)));
  return modp_vardnsexpdegspsterm_oomulscaddscmulsc_cns (C, A, s, v, modp_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_oomulscaddmulmonomsc_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_t s, int v, modp_vardnsexpdegspsterm_t B, vardnsmonom_t m, modp_t t, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (0 == (modp_vardnsexpdegspsterm_cmpmul (A, B, m, args)));
  return modp_vardnsexpdegspsterm_oomulscaddscmulsc_cns (C, A, s, v, modp_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static void 
modp_vardnsexpdegspsterm_oomulscaddmulsc (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_t s, int v, modp_vardnsexpdegspsterm_t B, modp_t t, int w, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspsterm_oomulscaddmulsc_cns (C, A, s, v, B, t, w, args), CT);
}

static void 
modp_vardnsexpdegspsterm_oomulscaddmulmonomsc (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_t s, int v, modp_vardnsexpdegspsterm_t B, vardnsmonom_t m, modp_t t, int w, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspsterm_oomulscaddmulmonomsc_cns (C, A, s, v, B, m, t, w, args), CT);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_inmulscaddmulsc (modp_vardnsexpdegspsterm_t A, modp_t s, int v, modp_vardnsexpdegspsterm_t B, modp_t t, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (0 == (modp_vardnsexpdegspsterm_cmp (A, B, args)));
  return modp_vardnsexpdegspsterm_inmulscaddscmulsc (A, s, v, modp_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_inmulscaddmulmonomsc (modp_vardnsexpdegspsterm_t A, modp_t s, int v, modp_vardnsexpdegspsterm_t B, vardnsmonom_t m, modp_t t, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (0 == (modp_vardnsexpdegspsterm_cmpmul (A, B, m, args)));
  return modp_vardnsexpdegspsterm_inmulscaddscmulsc (A, s, v, modp_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_oodivsc_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_t s, modp_vardnsexpdegspsterm_args args)
{
  BOOL failed;
  modp_vardnsexpdegspsterm_t new = modp_vardnsexpdegspsterm_alloc (args);

  failed = modp_oodiv (modp_vardnsexpdegspsterm_scal_cval (new, args), modp_vardnsexpdegspsterm_scal (A, args), s, args.sargs);
  if (failed)
    {
      modp_vardnsexpdegspsterm_free (new, args);
      return NULL;
    }

  vardnsmonom_copy (modp_vardnsexpdegspsterm_monom_cval (new), modp_vardnsexpdegspsterm_monom (A), args.margs);

  return modp_vardnsexpdegspsterm_condcns (C, new, args);
}

#if 0				/* unused ! why did I write this ? */
static BOOL 
modp_vardnsexpdegspsterm_oodivsc (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_t s, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  if ((C = modp_vardnsexpdegspsterm_oodivsc_cns (C, A, s, args)))
    {
      modp_vardnsexpdegspsterm_glue (C, CT);
      return SUCCESS;
    }
  else
    {
      return FAILURE;
    }
}
#endif

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_indivsc (modp_vardnsexpdegspsterm_t A, modp_t s, modp_vardnsexpdegspsterm_args args)
{
  modp_indiv (modp_vardnsexpdegspsterm_scal_cval (A, args), s, args.sargs);
  return modp_vardnsexpdegspsterm_conddelete (A, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_oodivmonomsc_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, vardnsmonom_t m, modp_t s, modp_vardnsexpdegspsterm_args args)
{
  BOOL sfailed, mfailed;
  modp_vardnsexpdegspsterm_t new = modp_vardnsexpdegspsterm_alloc (args);

  sfailed = modp_oodiv (modp_vardnsexpdegspsterm_scal_cval (new, args), modp_vardnsexpdegspsterm_scal (A, args), s, args.sargs);
  mfailed = vardnsmonom_oodiv (modp_vardnsexpdegspsterm_monom_cval (new), modp_vardnsexpdegspsterm_monom (A), m, args.margs);

  if (sfailed || mfailed)
    {
      /* both failures are possible in the multivariate case */
      modp_vardnsexpdegspsterm_free (new, args);
      return NULL;
    }

  return modp_vardnsexpdegspsterm_condcns (C, new, args);
}

#if 0				/* unused ! why did I write this ? */
static BOOL 
modp_vardnsexpdegspsterm_oodivmonomsc (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, vardnsmonom_t m, modp_t s, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  if ((C = modp_vardnsexpdegspsterm_oodivmonomsc_cns (C, A, m, s, args)))
    {
      modp_vardnsexpdegspsterm_glue (C, CT);
      return SUCCESS;
    }
  else
    {
      return FAILURE;
    }
}
#endif

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_indivmonomsc (modp_vardnsexpdegspsterm_t A, vardnsmonom_t m, modp_t s, modp_vardnsexpdegspsterm_args args)
{
  modp_indiv (modp_vardnsexpdegspsterm_scal_cval (A, args), s, args.sargs);
  vardnsmonom_indiv (modp_vardnsexpdegspsterm_monom_cval (A), m, args.margs);

  return modp_vardnsexpdegspsterm_conddelete (A, args);
}

static void 
modp_vardnsexpdegspsterm_args_fileOut (id aFiler, modp_vardnsexpdegspsterm_args * args)
{
  modp_args_fileOut (aFiler, &args->sargs);
  vardnsmonom_args_fileOut (aFiler, &args->margs);
}
static void 
modp_vardnsexpdegspsterm_args_fileIn (id aFiler, modp_vardnsexpdegspsterm_args * args)
{
  modp_args_fileIn (aFiler, &args->sargs);
  vardnsmonom_args_fileIn (aFiler, &args->margs);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_fileOut (id aFiler, modp_vardnsexpdegspsterm_t self, modp_vardnsexpdegspsterm_args args)
{
  assert (modp_vardnsexpdegspsterm_check (self, args));

  modp_fileOut (aFiler, modp_vardnsexpdegspsterm_scal_cval (self, args), args.sargs);
  vardnsmonom_fileOut (aFiler, modp_vardnsexpdegspsterm_monom_cval (self), args.margs);

  return self->nlink;
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspsterm_fileIn_cns (id aFiler, modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_t self = modp_vardnsexpdegspsterm_alloc (args);

  modp_fileIn (aFiler, modp_vardnsexpdegspsterm_scal_cval (self, args), args.sargs);
  vardnsmonom_fileIn (aFiler, modp_vardnsexpdegspsterm_monom_cval (self), args.margs);

  return modp_vardnsexpdegspsterm_cns (C, self);
}

static int 
modp_vardnsexpdegspslist_check (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_t prev;

  for (prev = NULL; A != AT; prev = A, A = A->nlink)
    {
      if (modp_vardnsexpdegspsterm_check (A, args) == 0)
	return 0;
      if (prev && modp_vardnsexpdegspsterm_cmp (prev, A, args) <= 0)
	return 0;
    }

  return 1;
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspslist_copy_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    {
      C = modp_vardnsexpdegspsterm_copy_cns (C, A, args);
      A = A->nlink;
    }
  return C;
}

static void 
modp_vardnsexpdegspslist_copy (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspslist_copy_cns (C, A, AT, args), CT);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspslist_deepcopy_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    {
      C = modp_vardnsexpdegspsterm_deepcopy_cns (C, A, args);
      A = A->nlink;
    }
  return C;
}

static void 
modp_vardnsexpdegspslist_deepcopy (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspslist_deepcopy_cns (C, A, AT, args), CT);
}

static void 
modp_vardnsexpdegspslist_clear (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    {
      modp_vardnsexpdegspsterm_clear (A, args);
      A = A->nlink;
    }
}

static void 
modp_vardnsexpdegspslist_free (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_t t;
  for (; A != AT; A = t)
    {
      t = A->nlink;
      modp_vardnsexpdegspsterm_free (A, args);
    }
}

static int 
modp_vardnsexpdegspslist_count (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT)
{
  int c = 0;
  for (; A != AT; A = A->nlink)
    c++;
  return c;
}

static unsigned 
modp_vardnsexpdegspslist_hash (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_vardnsexpdegspsterm_args args)
{
  return modp_vardnsexpdegspslist_count (A, AT);
}

static int 
modp_vardnsexpdegspslist_iseq (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_vardnsexpdegspsterm_t B, modp_vardnsexpdegspsterm_t BT, modp_vardnsexpdegspsterm_args args)
{
  for (; A != AT && B != BT; A = A->nlink, B = B->nlink)
    {
      if (!modp_vardnsexpdegspsterm_iseq (A, B, args))
	return 0;
    }
  return (A == AT && B == BT);
}

static int 
modp_vardnsexpdegspslist_isop (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_vardnsexpdegspsterm_t B, modp_vardnsexpdegspsterm_t BT, modp_vardnsexpdegspsterm_args args)
{
  for (; A != AT && B != BT; A = A->nlink, B = B->nlink)
    {
      if (!modp_vardnsexpdegspsterm_isop (A, B, args))
	return 0;
    }
  return (A == AT && B == BT);
}

static int 
modp_vardnsexpdegspslist_deg (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_vardnsexpdegspsterm_args args)
{
  return (A == AT) ? -1 : modp_vardnsexpdegspsterm_deg (A, args);
}

static int 
modp_vardnsexpdegspslist_maxdeg (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_vardnsexpdegspsterm_args args)
{
  int max = (A == AT) ? -1 : modp_vardnsexpdegspsterm_deg (A, args);
  for (A = A->nlink; A != AT; A = A->nlink)
    {
      int d = modp_vardnsexpdegspsterm_deg (A, args);
      if (max < d)
	max = d;
    }
  return max;
}

static int 
modp_vardnsexpdegspslist_ord (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_vardnsexpdegspsterm_args args)
{
  return (A == AT) ? -1 : modp_vardnsexpdegspsterm_deg (AT->plink, args);
}

static int 
modp_vardnsexpdegspslist_mindeg (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_vardnsexpdegspsterm_args args)
{
  int min = (A == AT) ? -1 : modp_vardnsexpdegspsterm_deg (A, args);
  for (A = A->nlink; A != AT; A = A->nlink)
    {
      int d = modp_vardnsexpdegspsterm_deg (A, args);
      if (min > d)
	min = d;
    }
  return min;
}

static void 
modp_vardnsexpdegspslist_insert (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, vardnsmonom_t m, modp_t s, modp_vardnsexpdegspsterm_args args)
{
  assert (modp_iszero (s, args.sargs) == NO);

  /* adding to zero */
  if (A == AT)
    {
      modp_vardnsexpdegspsterm_copymonomsc (A, m, s, A, args);
      return;
    }

  /* tail append */
  if (modp_vardnsexpdegspsterm_cmpmonom (AT->plink, m, args) > 0)
    {
      modp_vardnsexpdegspsterm_copymonomsc (AT->plink, m, s, AT, args);
      return;
    }

  /* insertion */
  while (A != AT)
    {
      int cmp = modp_vardnsexpdegspsterm_cmpmonom (A, m, args);
      if (cmp == 0)
	{
	  modp_vardnsexpdegspsterm_inaddsc (A, +1, s, +1, args);
	  return;
	}
      if (cmp < 0)
	{
	  modp_vardnsexpdegspsterm_copymonomsc (A->plink, m, s, A, args);
	  return;
	}
      A = A->nlink;
    }

  fprintf (stderr, "Shouldn't happen\n");
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspslist_ooneg_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    {
      C = modp_vardnsexpdegspsterm_ooneg_cns (C, A, args);
      A = A->nlink;
    }
  return C;
}

static void 
modp_vardnsexpdegspslist_ooneg (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspslist_ooneg_cns (C, A, AT, args), CT);
}

static void 
modp_vardnsexpdegspslist_inneg (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    A = modp_vardnsexpdegspsterm_inneg (A, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspslist_oonegv_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, int v, modp_vardnsexpdegspsterm_args args)
{
  if (v == -1)
    {
      return modp_vardnsexpdegspslist_ooneg_cns (C, A, AT, args);
    }
  else
    {
      return modp_vardnsexpdegspslist_copy_cns (C, A, AT, args);
    }
}

static void 
modp_vardnsexpdegspslist_oonegv (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, int v, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspslist_oonegv_cns (C, A, AT, v, args), CT);
}

static void 
modp_vardnsexpdegspslist_innegv (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, int v, modp_vardnsexpdegspsterm_args args)
{
  if (v == -1)
    modp_vardnsexpdegspslist_inneg (A, AT, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspslist_oodbl_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, int v, modp_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    {
      C = modp_vardnsexpdegspsterm_oodbl_cns (C, A, v, args);
      A = A->nlink;
    }
  return C;
}

static void 
modp_vardnsexpdegspslist_oodbl (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, int v, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspslist_oodbl_cns (C, A, AT, v, args), CT);
}

static void 
modp_vardnsexpdegspslist_indbl (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, int v, modp_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    A = modp_vardnsexpdegspsterm_indbl (A, v, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspslist_ooadd_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, int v, modp_vardnsexpdegspsterm_t B, modp_vardnsexpdegspsterm_t BT, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = modp_vardnsexpdegspsterm_ooadd_cns (C, A, v, B, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = modp_vardnsexpdegspsterm_oonegv_cns (C, B, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = modp_vardnsexpdegspsterm_oonegv_cns (C, A, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return modp_vardnsexpdegspslist_oonegv_cns (C, A, AT, v, args);
  if (B != BT)
    return modp_vardnsexpdegspslist_oonegv_cns (C, B, BT, w, args);
  return C;
}

static void 
modp_vardnsexpdegspslist_ooadd (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, int v, modp_vardnsexpdegspsterm_t B, modp_vardnsexpdegspsterm_t BT, int w, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspslist_ooadd_cns (C, A, AT, v, B, BT, w, args), CT);
}

static void 
modp_vardnsexpdegspslist_inadd (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, int v, modp_vardnsexpdegspsterm_t B, modp_vardnsexpdegspsterm_t BT, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = modp_vardnsexpdegspsterm_inadd (A, v, B, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  modp_vardnsexpdegspsterm_oonegv (A->plink, B, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = modp_vardnsexpdegspsterm_innegv (A, v, args);
	}
    }

  if (A != AT)
    modp_vardnsexpdegspslist_innegv (A, AT, v, args);
  if (B != BT)
    modp_vardnsexpdegspslist_oonegv (A->plink, B, BT, w, A, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspslist_oomulsc_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_t s, int v, modp_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    {
      C = modp_vardnsexpdegspsterm_oomulsc_cns (C, A, s, v, args);
      A = A->nlink;
    }
  return C;
}

static void 
modp_vardnsexpdegspslist_oomulsc (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_t s, int v, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspslist_oomulsc_cns (C, A, AT, s, v, args), CT);
}

static void 
modp_vardnsexpdegspslist_inmulsc (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_t s, int v, modp_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    A = modp_vardnsexpdegspsterm_inmulsc (A, s, v, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspslist_oomulmonomsc_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, vardnsmonom_t m, modp_t s, int v, modp_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    {
      C = modp_vardnsexpdegspsterm_oomulmonomsc_cns (C, A, m, s, v, args);
      A = A->nlink;
    }
  return C;
}

static void 
modp_vardnsexpdegspslist_oomulmonomsc (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, vardnsmonom_t m, modp_t s, int v, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspslist_oomulmonomsc_cns (C, A, AT, m, s, v, args), CT);
}

static void 
modp_vardnsexpdegspslist_inmulmonomsc (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, vardnsmonom_t m, modp_t s, int v, modp_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    A = modp_vardnsexpdegspsterm_inmulmonomsc (A, m, s, v, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspslist_ooaddmulsc_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, int v, modp_vardnsexpdegspsterm_t B, modp_vardnsexpdegspsterm_t BT, modp_t t, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = modp_vardnsexpdegspsterm_ooaddmulsc_cns (C, A, v, B, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = modp_vardnsexpdegspsterm_oomulsc_cns (C, B, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = modp_vardnsexpdegspsterm_oonegv_cns (C, A, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return modp_vardnsexpdegspslist_oonegv_cns (C, A, AT, v, args);
  if (B != BT)
    return modp_vardnsexpdegspslist_oomulsc_cns (C, B, BT, t, w, args);
  return C;
}

static void 
modp_vardnsexpdegspslist_ooaddmulsc (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, int v, modp_vardnsexpdegspsterm_t B, modp_vardnsexpdegspsterm_t BT, modp_t t, int w, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspslist_ooaddmulsc_cns (C, A, AT, v, B, BT, t, w, args), CT);
}

static void 
modp_vardnsexpdegspslist_inaddmulsc (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, int v, modp_vardnsexpdegspsterm_t B, modp_vardnsexpdegspsterm_t BT, modp_t t, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = modp_vardnsexpdegspsterm_inaddmulsc (A, v, B, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  modp_vardnsexpdegspsterm_oomulsc (A->plink, B, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = modp_vardnsexpdegspsterm_innegv (A, v, args);
	}
    }

  if (A != AT)
    modp_vardnsexpdegspslist_innegv (A, AT, v, args);
  if (B != BT)
    modp_vardnsexpdegspslist_oomulsc (A->plink, B, BT, t, w, A, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspslist_ooaddmulmonomsc_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, int v, modp_vardnsexpdegspsterm_t B, modp_vardnsexpdegspsterm_t BT, vardnsmonom_t m, modp_t t, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsexpdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  C = modp_vardnsexpdegspsterm_ooaddmulmonomsc_cns (C, A, v, B, m, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = modp_vardnsexpdegspsterm_oomulmonomsc_cns (C, B, m, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = modp_vardnsexpdegspsterm_oonegv_cns (C, A, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return modp_vardnsexpdegspslist_oonegv_cns (C, A, AT, v, args);
  if (B != BT)
    return modp_vardnsexpdegspslist_oomulmonomsc_cns (C, B, BT, m, t, w, args);
  return C;
}

static void 
modp_vardnsexpdegspslist_ooaddmulmonomsc (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, int v, modp_vardnsexpdegspsterm_t B, modp_vardnsexpdegspsterm_t BT, vardnsmonom_t m, modp_t t, int w, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspslist_ooaddmulmonomsc_cns (C, A, AT, v, B, BT, m, t, w, args), CT);
}

static void 
modp_vardnsexpdegspslist_inaddmulmonomsc (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, int v, modp_vardnsexpdegspsterm_t B, modp_vardnsexpdegspsterm_t BT, vardnsmonom_t m, modp_t t, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsexpdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  A = modp_vardnsexpdegspsterm_inaddmulmonomsc (A, v, B, m, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  modp_vardnsexpdegspsterm_oomulmonomsc (A->plink, B, m, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = modp_vardnsexpdegspsterm_innegv (A, v, args);
	}
    }

  if (A != AT)
    modp_vardnsexpdegspslist_innegv (A, AT, v, args);
  if (B != BT)
    modp_vardnsexpdegspslist_oomulmonomsc (A->plink, B, BT, m, t, w, A, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspslist_oomulscadd_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_t s, int v, modp_vardnsexpdegspsterm_t B, modp_vardnsexpdegspsterm_t BT, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = modp_vardnsexpdegspsterm_oomulscadd_cns (C, A, s, v, B, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = modp_vardnsexpdegspsterm_oonegv_cns (C, B, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = modp_vardnsexpdegspsterm_oomulsc_cns (C, A, s, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return modp_vardnsexpdegspslist_oomulsc_cns (C, A, AT, s, v, args);
  if (B != BT)
    return modp_vardnsexpdegspslist_oonegv_cns (C, B, BT, w, args);
  return C;
}

static void 
modp_vardnsexpdegspslist_oomulscadd (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_t s, int v, modp_vardnsexpdegspsterm_t B, modp_vardnsexpdegspsterm_t BT, int w, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspslist_oomulscadd_cns (C, A, AT, s, v, B, BT, w, args), CT);
}

static void 
modp_vardnsexpdegspslist_inmulscadd (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_t s, int v, modp_vardnsexpdegspsterm_t B, modp_vardnsexpdegspsterm_t BT, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = modp_vardnsexpdegspsterm_inmulscadd (A, s, v, B, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  modp_vardnsexpdegspsterm_oonegv (A->plink, B, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = modp_vardnsexpdegspsterm_inmulsc (A, s, v, args);
	}
    }

  if (A != AT)
    modp_vardnsexpdegspslist_inmulsc (A, AT, s, v, args);
  if (B != BT)
    modp_vardnsexpdegspslist_oonegv (A->plink, B, BT, w, A, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspslist_oomulscaddmulsc_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_t s, int v, modp_vardnsexpdegspsterm_t B, modp_vardnsexpdegspsterm_t BT, modp_t t, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = modp_vardnsexpdegspsterm_oomulscaddmulsc_cns (C, A, s, v, B, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = modp_vardnsexpdegspsterm_oomulsc_cns (C, B, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = modp_vardnsexpdegspsterm_oomulsc_cns (C, A, s, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return modp_vardnsexpdegspslist_oomulsc_cns (C, A, AT, s, v, args);
  if (B != BT)
    return modp_vardnsexpdegspslist_oomulsc_cns (C, B, BT, t, w, args);
  return C;
}

static void 
modp_vardnsexpdegspslist_oomulscaddmulsc (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_t s, int v, modp_vardnsexpdegspsterm_t B, modp_vardnsexpdegspsterm_t BT, modp_t t, int w, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspslist_oomulscaddmulsc_cns (C, A, AT, s, v, B, BT, t, w, args), CT);
}

static void 
modp_vardnsexpdegspslist_inmulscaddmulsc (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_t s, int v, modp_vardnsexpdegspsterm_t B, modp_vardnsexpdegspsterm_t BT, modp_t t, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = modp_vardnsexpdegspsterm_inmulscaddmulsc (A, s, v, B, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  modp_vardnsexpdegspsterm_oomulsc (A->plink, B, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = modp_vardnsexpdegspsterm_inmulsc (A, s, v, args);
	}
    }

  if (A != AT)
    modp_vardnsexpdegspslist_inmulsc (A, AT, s, v, args);
  if (B != BT)
    modp_vardnsexpdegspslist_oomulsc (A->plink, B, BT, t, w, A, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspslist_oomulscaddmulmonomsc_cns (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_t s, int v, modp_vardnsexpdegspsterm_t B, modp_vardnsexpdegspsterm_t BT, vardnsmonom_t m, modp_t t, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsexpdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  C = modp_vardnsexpdegspsterm_oomulscaddmulmonomsc_cns (C, A, s, v, B, m, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = modp_vardnsexpdegspsterm_oomulmonomsc_cns (C, B, m, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = modp_vardnsexpdegspsterm_oomulsc_cns (C, A, s, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return modp_vardnsexpdegspslist_oomulsc_cns (C, A, AT, s, v, args);
  if (B != BT)
    return modp_vardnsexpdegspslist_oomulmonomsc_cns (C, B, BT, m, t, w, args);
  return C;
}

static void 
modp_vardnsexpdegspslist_oomulscaddmulmonomsc (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_t s, int v, modp_vardnsexpdegspsterm_t B, modp_vardnsexpdegspsterm_t BT, vardnsmonom_t m, modp_t t, int w, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspslist_oomulscaddmulmonomsc_cns (C, A, AT, s, v, B, BT, m, t, w, args), CT);
}

static void 
modp_vardnsexpdegspslist_inmulscaddmulmonomsc (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_t s, int v, modp_vardnsexpdegspsterm_t B, modp_vardnsexpdegspsterm_t BT, vardnsmonom_t m, modp_t t, int w, modp_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = modp_vardnsexpdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  A = modp_vardnsexpdegspsterm_inmulscaddmulmonomsc (A, s, v, B, m, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  modp_vardnsexpdegspsterm_oomulmonomsc (A->plink, B, m, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = modp_vardnsexpdegspsterm_inmulsc (A, s, v, args);
	}
    }

  if (A != AT)
    modp_vardnsexpdegspslist_inmulsc (A, AT, s, v, args);
  if (B != BT)
    modp_vardnsexpdegspslist_oomulmonomsc (A->plink, B, BT, m, t, w, A, args);
}

static BOOL 
modp_vardnsexpdegspslist_oodivsc (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_t s, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  BOOL failed = NO;

  while (A != AT)
    {
      modp_vardnsexpdegspsterm_t nextC = modp_vardnsexpdegspsterm_oodivsc_cns (C, A, s, args);
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
  modp_vardnsexpdegspsterm_glue (C, CT);
  return failed;
}

static void 
modp_vardnsexpdegspslist_indivsc (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_t s, modp_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    A = modp_vardnsexpdegspsterm_indivsc (A, s, args);
}

static BOOL 
modp_vardnsexpdegspslist_oodivmonomsc (modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, vardnsmonom_t m, modp_t s, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  BOOL failed = NO;

  while (A != AT)
    {
      modp_vardnsexpdegspsterm_t nextC = modp_vardnsexpdegspsterm_oodivmonomsc_cns (C, A, m, s, args);
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
  modp_vardnsexpdegspsterm_glue (C, CT);
  return failed;
}

static void 
modp_vardnsexpdegspslist_indivmonomsc (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, vardnsmonom_t m, modp_t s, modp_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    A = modp_vardnsexpdegspsterm_indivmonomsc (A, m, s, args);
}

static void 
modp_vardnsexpdegspslist_fileOut (id aFiler, modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT, modp_vardnsexpdegspsterm_args args)
{
  int n;
  n = modp_vardnsexpdegspslist_count (A, AT);
  [aFiler fileOut:&n type:'i'];
  while (A != AT)
    A = modp_vardnsexpdegspsterm_fileOut (aFiler, A, args);
}

static modp_vardnsexpdegspsterm_t 
modp_vardnsexpdegspslist_fileIn_cns (id aFiler, modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_args args)
{
  int n;
  [aFiler fileIn:&n type:'i'];
  while (n--)
    C = modp_vardnsexpdegspsterm_fileIn_cns (aFiler, C, args);
  return C;
}

static void 
modp_vardnsexpdegspslist_fileIn (id aFiler, modp_vardnsexpdegspsterm_t C, modp_vardnsexpdegspsterm_t CT, modp_vardnsexpdegspsterm_args args)
{
  modp_vardnsexpdegspsterm_glue (modp_vardnsexpdegspslist_fileIn_cns (aFiler, C, args), CT);
}

static void 
modp_vardnsexpdegspspol_ix_init (modp_vardnsexpdegspspol_ixt ix, id self)
{
  modp_vardnsexpdegspspol_t v = [self modp_vardnsexpdegspspol_value];
  ix->head = v;
  ix->ix = v;
}

static void 
modp_vardnsexpdegspspol_ix_clear (modp_vardnsexpdegspspol_ixt ix)
{
  /* nothing to clear */
}

static int 
modp_vardnsexpdegspspol_ix_count_aux_aux (modp_vardnsexpdegspsterm_t A, modp_vardnsexpdegspsterm_t AT)
{
  int c = 0;
  for (; A != AT; A = A->nlink)
    c++;
  return c;
}

static int 
modp_vardnsexpdegspspol_ix_count_aux (modp_vardnsexpdegspspol_t self)
{
  return modp_vardnsexpdegspspol_ix_count_aux_aux (self->nlink, self);
}

static int 
modp_vardnsexpdegspspol_ix_count (modp_vardnsexpdegspspol_ixt ix)
{
  /* merde ! can't include entire modp_vardnsexpdegspslist for modp_vardnsexpdegspslist_count */
  return modp_vardnsexpdegspspol_ix_count_aux (ix->head);
}

static int 
modp_vardnsexpdegspspol_ix_isempty_aux (modp_vardnsexpdegspspol_t self)
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
modp_vardnsexpdegspspol_ix_isempty (modp_vardnsexpdegspspol_ixt ix)
{
  /* can't include entire modp_vardnsexpdegspspol for modp_vardnsexpdegspspol_isempty */
  return modp_vardnsexpdegspspol_ix_isempty_aux (ix->head);
}

static int 
modp_vardnsexpdegspspol_ix_ismatch (modp_vardnsexpdegspspol_ixt ix)
{
  return (ix->ix != NULL && ix->ix != ix->head);
}

static void 
modp_vardnsexpdegspspol_ix_tofirst (modp_vardnsexpdegspspol_ixt ix)
{
  ix->ix = ix->head;
}

static void 
modp_vardnsexpdegspspol_ix_tolast (modp_vardnsexpdegspspol_ixt ix)
{
  ix->ix = NULL;
}

static void 
modp_vardnsexpdegspspol_ix_to (modp_vardnsexpdegspspol_ixt ix, int i)
{
  fprintf (stderr, "at: notImplemented\n");
}

static void 
modp_vardnsexpdegspspol_ix_next (modp_vardnsexpdegspspol_ixt ix)
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
modp_vardnsexpdegspspol_ix_prev (modp_vardnsexpdegspspol_ixt ix)
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
modp_vardnsexpdegspspol_check (modp_vardnsexpdegspspol_t self, modp_vardnsexpdegspspol_args args)
{
  assert (self->data == 0xcafebabe);
  return modp_vardnsexpdegspslist_check (self->nlink, self, args);
}

static modp_vardnsexpdegspspol_t 
modp_vardnsexpdegspspol_id2t (id object)
{
  return [object modp_vardnsexpdegspspol_value];
}

static modp_vardnsexpdegspspol_c *
modp_vardnsexpdegspspol_id2c (id object)
{
  return [object modp_vardnsexpdegspspol_reference];
}

static id 
modp_vardnsexpdegspspol_t2id (id proto, modp_vardnsexpdegspspol_t f)
{
  return [proto modp_vardnsexpdegspspol_value:f];
}

static id 
modp_vardnsexpdegspspol_c2id (id proto, modp_vardnsexpdegspspol_c * r)
{
  return [proto modp_vardnsexpdegspspol_reference:r];
}

static int 
modp_vardnsexpdegspspol_isempty (modp_vardnsexpdegspspol_t self)
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
modp_vardnsexpdegspspol_init (modp_vardnsexpdegspspol_t self, modp_vardnsexpdegspspol_args args)
{
  self->data = 0xcafebabe;
  self->nlink = self;
  self->plink = self;
  assert (modp_vardnsexpdegspspol_check (self, args));
}

static void 
modp_vardnsexpdegspspol_copy (modp_vardnsexpdegspspol_t c, modp_vardnsexpdegspspol_t a, modp_vardnsexpdegspspol_args args)
{
  assert (modp_vardnsexpdegspspol_check (a, args));
  modp_vardnsexpdegspspol_init (c, args);
  modp_vardnsexpdegspslist_copy (c, a->nlink, a, c, args);
}

static void 
modp_vardnsexpdegspspol_deepcopy (modp_vardnsexpdegspspol_t c, modp_vardnsexpdegspspol_t a, modp_vardnsexpdegspspol_args args)
{
  assert (modp_vardnsexpdegspspol_check (a, args));
  modp_vardnsexpdegspspol_init (c, args);
  modp_vardnsexpdegspslist_deepcopy (c, a->nlink, a, c, args);
}

static void 
modp_vardnsexpdegspspol_move (modp_vardnsexpdegspspol_t c, modp_vardnsexpdegspspol_t a, modp_vardnsexpdegspspol_args args)
{
  if (modp_vardnsexpdegspspol_isempty (a))
    {
      modp_vardnsexpdegspspol_init (c, args);
    }
  else
    {
      modp_vardnsexpdegspspol_init (c, args);
      modp_vardnsexpdegspsterm_glue (c, a->nlink);
      modp_vardnsexpdegspsterm_glue (a->plink, c);
    }

  a->data = 0;
  assert (modp_vardnsexpdegspspol_check (c, args));
}

static void 
modp_vardnsexpdegspspol_clear (modp_vardnsexpdegspspol_t self, modp_vardnsexpdegspspol_args args)
{
  modp_vardnsexpdegspslist_clear (self->nlink, self, args);
  self->data = 0;
  modp_vardnsexpdegspslist_free (self->nlink, self, args);
}

static int 
modp_vardnsexpdegspspol_count (modp_vardnsexpdegspspol_t self)
{
  return modp_vardnsexpdegspslist_count (self->nlink, self);
}

static unsigned 
modp_vardnsexpdegspspol_hash (modp_vardnsexpdegspspol_t a, modp_vardnsexpdegspspol_args args)
{
  return modp_vardnsexpdegspslist_hash (a->nlink, a, args);
}

static int 
modp_vardnsexpdegspspol_iseq (modp_vardnsexpdegspspol_t a, modp_vardnsexpdegspspol_t b, modp_vardnsexpdegspspol_args args)
{
  return (a == b) ? YES : modp_vardnsexpdegspslist_iseq (a->nlink, a, b->nlink, b, args);
}

static int 
modp_vardnsexpdegspspol_isone (modp_vardnsexpdegspspol_t a, modp_vardnsexpdegspspol_args args)
{
  /* if the leading term is one, then it is one */
  return (modp_vardnsexpdegspspol_isempty (a)) ? 0 : modp_vardnsexpdegspsterm_isone (a->nlink, args);
}

static int 
modp_vardnsexpdegspspol_isminusone (modp_vardnsexpdegspspol_t a, modp_vardnsexpdegspspol_args args)
{
  /* if the leading term is minus one, then it is minus one */
  return (modp_vardnsexpdegspspol_isempty (a)) ? 0 : modp_vardnsexpdegspsterm_isminusone (a->nlink, args);
}

static int 
modp_vardnsexpdegspspol_deg (modp_vardnsexpdegspspol_t self, modp_vardnsexpdegspspol_args args)
{
  return modp_vardnsexpdegspslist_deg (self->nlink, self, args);
}

static int 
modp_vardnsexpdegspspol_ord (modp_vardnsexpdegspspol_t self, modp_vardnsexpdegspspol_args args)
{
  return modp_vardnsexpdegspslist_ord (self->nlink, self, args);
}

static int 
modp_vardnsexpdegspspol_maxdeg (modp_vardnsexpdegspspol_t self, modp_vardnsexpdegspspol_args args)
{
  return modp_vardnsexpdegspslist_maxdeg (self->nlink, self, args);
}

static int 
modp_vardnsexpdegspspol_mindeg (modp_vardnsexpdegspspol_t self, modp_vardnsexpdegspspol_args args)
{
  return modp_vardnsexpdegspslist_mindeg (self->nlink, self, args);
}

static modp_t 
modp_vardnsexpdegspspol_scalat (modp_vardnsexpdegspspol_t self, modp_vardnsexpdegspspol_ixt ix, modp_vardnsexpdegspspol_args args)
{
  assert (modp_vardnsexpdegspspol_ix_ismatch (ix) && ix->head == self);
  return modp_vardnsexpdegspsterm_scal (ix->ix, args);
}

static vardnsmonom_t 
modp_vardnsexpdegspspol_monomat (modp_vardnsexpdegspspol_t self, modp_vardnsexpdegspspol_ixt ix, modp_vardnsexpdegspspol_args args)
{
  assert (modp_vardnsexpdegspspol_ix_ismatch (ix) && ix->head == self);
  return modp_vardnsexpdegspsterm_monom (ix->ix);
}

static modp_t 
modp_vardnsexpdegspspol_scalfirst (modp_vardnsexpdegspspol_t self, modp_vardnsexpdegspspol_args args)
{
  assert (modp_vardnsexpdegspspol_isempty (self) == NO);
  return modp_vardnsexpdegspsterm_scal (self->nlink, args);
}

static vardnsmonom_t 
modp_vardnsexpdegspspol_monomfirst (modp_vardnsexpdegspspol_t self, modp_vardnsexpdegspspol_args args)
{
  assert (modp_vardnsexpdegspspol_isempty (self) == NO);
  return modp_vardnsexpdegspsterm_monom (self->nlink);
}

static void 
modp_vardnsexpdegspspol_remove (modp_vardnsexpdegspspol_t self, modp_vardnsexpdegspspol_args args)
{
  assert (modp_vardnsexpdegspspol_check (self, args) && modp_vardnsexpdegspspol_isempty (self) == NO);
  modp_vardnsexpdegspsterm_delete (self->nlink, args);
  assert (modp_vardnsexpdegspspol_check (self, args));
}

static void 
modp_vardnsexpdegspspol_insert (modp_vardnsexpdegspspol_t self, vardnsmonom_t m, modp_t s, modp_vardnsexpdegspspol_args args)
{
  assert (modp_vardnsexpdegspspol_check (self, args));
  modp_vardnsexpdegspslist_insert (self->nlink, self, m, s, args);
  assert (modp_vardnsexpdegspspol_check (self, args));
}

static int 
modp_vardnsexpdegspspol_iszero (modp_vardnsexpdegspspol_t self, modp_vardnsexpdegspspol_args args)
{
  return modp_vardnsexpdegspspol_isempty (self);
}

static int 
modp_vardnsexpdegspspol_isop (modp_vardnsexpdegspspol_t a, modp_vardnsexpdegspspol_t b, modp_vardnsexpdegspspol_args args)
{
  assert (a != b);
  return modp_vardnsexpdegspslist_isop (a->nlink, a, b->nlink, b, args);
}

static void 
modp_vardnsexpdegspspol_ooneg (modp_vardnsexpdegspspol_t c, modp_vardnsexpdegspspol_t a, modp_vardnsexpdegspspol_args args)
{
  modp_vardnsexpdegspspol_init (c, args);
  modp_vardnsexpdegspslist_ooneg (c, a->nlink, a, c, args);
  assert (modp_vardnsexpdegspspol_check (c, args));
}

static void 
modp_vardnsexpdegspspol_inneg (modp_vardnsexpdegspspol_t a, modp_vardnsexpdegspspol_args args)
{
  modp_vardnsexpdegspslist_inneg (a->nlink, a, args);
  assert (modp_vardnsexpdegspspol_check (a, args));
}

static void 
modp_vardnsexpdegspspol_oodbl (modp_vardnsexpdegspspol_t c, modp_vardnsexpdegspspol_t a, int v, modp_vardnsexpdegspspol_args args)
{
  modp_vardnsexpdegspspol_init (c, args);
  modp_vardnsexpdegspslist_oodbl (c, a->nlink, a, v, c, args);
  assert (modp_vardnsexpdegspspol_check (c, args));
}

static void 
modp_vardnsexpdegspspol_indbl (modp_vardnsexpdegspspol_t a, int v, modp_vardnsexpdegspspol_args args)
{
  modp_vardnsexpdegspslist_indbl (a->nlink, a, v, args);
  assert (modp_vardnsexpdegspspol_check (a, args));
}

static void 
modp_vardnsexpdegspspol_ooadd (modp_vardnsexpdegspspol_t c, modp_vardnsexpdegspspol_t a, int v, modp_vardnsexpdegspspol_t b, int w, modp_vardnsexpdegspspol_args args)
{
  assert (a != b);
  modp_vardnsexpdegspspol_init (c, args);
  modp_vardnsexpdegspslist_ooadd (c, a->nlink, a, v, b->nlink, b, w, c, args);
  assert (modp_vardnsexpdegspspol_check (c, args));
}

static void 
modp_vardnsexpdegspspol_inadd (modp_vardnsexpdegspspol_t a, int v, modp_vardnsexpdegspspol_t b, int w, modp_vardnsexpdegspspol_args args)
{
  assert (a != b);
  modp_vardnsexpdegspslist_inadd (a->nlink, a, v, b->nlink, b, w, args);
  assert (modp_vardnsexpdegspspol_check (a, args));
}

static void 
modp_vardnsexpdegspspol_oomulsc (modp_vardnsexpdegspspol_t c, modp_vardnsexpdegspspol_t a, modp_t s, modp_vardnsexpdegspspol_args args)
{
  modp_vardnsexpdegspspol_init (c, args);
  modp_vardnsexpdegspslist_oomulsc (c, a->nlink, a, s, +1, c, args);
  assert (modp_vardnsexpdegspspol_check (c, args));
}

static void 
modp_vardnsexpdegspspol_inmulsc (modp_vardnsexpdegspspol_t a, modp_t s, modp_vardnsexpdegspspol_args args)
{
  modp_vardnsexpdegspslist_inmulsc (a->nlink, a, s, +1, args);
  assert (modp_vardnsexpdegspspol_check (a, args));
}

static void 
modp_vardnsexpdegspspol_ooaddmulsc (modp_vardnsexpdegspspol_t c, modp_vardnsexpdegspspol_t a, int v, modp_vardnsexpdegspspol_t b, modp_t t, int w, modp_vardnsexpdegspspol_args args)
{
  modp_vardnsexpdegspspol_init (c, args);
  modp_vardnsexpdegspslist_ooaddmulsc (c, a->nlink, a, v, b->nlink, b, t, w, c, args);
  assert (modp_vardnsexpdegspspol_check (c, args));
}

static void 
modp_vardnsexpdegspspol_inaddmulsc (modp_vardnsexpdegspspol_t a, int v, modp_vardnsexpdegspspol_t b, modp_t t, int w, modp_vardnsexpdegspspol_args args)
{
  modp_vardnsexpdegspslist_inaddmulsc (a->nlink, a, v, b->nlink, b, t, w, args);
  assert (modp_vardnsexpdegspspol_check (a, args));
}

static void 
modp_vardnsexpdegspspol_oomulscadd (modp_vardnsexpdegspspol_t c, modp_vardnsexpdegspspol_t a, modp_t s, int v, modp_vardnsexpdegspspol_t b, int w, modp_vardnsexpdegspspol_args args)
{
  modp_vardnsexpdegspspol_init (c, args);
  modp_vardnsexpdegspslist_oomulscadd (c, a->nlink, a, s, v, b->nlink, b, w, c, args);
  assert (modp_vardnsexpdegspspol_check (c, args));
}

static void 
modp_vardnsexpdegspspol_inmulscadd (modp_vardnsexpdegspspol_t a, modp_t s, int v, modp_vardnsexpdegspspol_t b, int w, modp_vardnsexpdegspspol_args args)
{
  modp_vardnsexpdegspslist_inmulscadd (a->nlink, a, s, v, b->nlink, b, w, args);
  assert (modp_vardnsexpdegspspol_check (a, args));
}

static void 
modp_vardnsexpdegspspol_oomulscaddmulsc (modp_vardnsexpdegspspol_t c, modp_vardnsexpdegspspol_t a, modp_t s, int v, modp_vardnsexpdegspspol_t b, modp_t t, int w, modp_vardnsexpdegspspol_args args)
{
  modp_vardnsexpdegspspol_init (c, args);
  modp_vardnsexpdegspslist_oomulscaddmulsc (c, a->nlink, a, s, v, b->nlink, b, t, w, c, args);
  assert (modp_vardnsexpdegspspol_check (c, args));
}

static void 
modp_vardnsexpdegspspol_inmulscaddmulsc (modp_vardnsexpdegspspol_t a, modp_t s, int v, modp_vardnsexpdegspspol_t b, modp_t t, int w, modp_vardnsexpdegspspol_args args)
{
  modp_vardnsexpdegspslist_inmulscaddmulsc (a->nlink, a, s, v, b->nlink, b, t, w, args);
  assert (modp_vardnsexpdegspspol_check (a, args));
}

static BOOL 
modp_vardnsexpdegspspol_oodivsc (modp_vardnsexpdegspspol_t c, modp_vardnsexpdegspspol_t a, modp_t s, modp_vardnsexpdegspspol_args args)
{
  BOOL failed;
  modp_vardnsexpdegspspol_init (c, args);
  failed = modp_vardnsexpdegspslist_oodivsc (c, a->nlink, a, s, c, args);
  assert (modp_vardnsexpdegspspol_check (c, args));
  if (failed)
    modp_vardnsexpdegspspol_clear (c, args);
  return failed;
}

static void 
modp_vardnsexpdegspspol_indivsc (modp_vardnsexpdegspspol_t a, modp_t s, modp_vardnsexpdegspspol_args args)
{
  modp_vardnsexpdegspslist_indivsc (a->nlink, a, s, args);
  assert (modp_vardnsexpdegspspol_check (a, args));
}

static void 
modp_vardnsexpdegspspol_oomulmonomsc (modp_vardnsexpdegspspol_t c, modp_vardnsexpdegspspol_t b, vardnsmonom_t m, modp_t t, int w, modp_vardnsexpdegspspol_args args)
{
  modp_vardnsexpdegspspol_init (c, args);
  modp_vardnsexpdegspslist_oomulmonomsc (c, b->nlink, b, m, t, w, c, args);
  assert (modp_vardnsexpdegspspol_check (c, args));
}

static void 
modp_vardnsexpdegspspol_inmulmonomsc (modp_vardnsexpdegspspol_t b, vardnsmonom_t m, modp_t t, int w, modp_vardnsexpdegspspol_args args)
{
  modp_vardnsexpdegspslist_inmulmonomsc (b->nlink, b, m, t, w, args);
  assert (modp_vardnsexpdegspspol_check (b, args));
}

static void 
modp_vardnsexpdegspspol_ooaddmulmonomsc (modp_vardnsexpdegspspol_t c, modp_vardnsexpdegspspol_t a, int v, modp_vardnsexpdegspspol_t b, vardnsmonom_t m, modp_t t, int w, modp_vardnsexpdegspspol_args args)
{
  modp_vardnsexpdegspspol_init (c, args);
  modp_vardnsexpdegspslist_ooaddmulmonomsc (c, a->nlink, a, v, b->nlink, b, m, t, w, c, args);
  assert (modp_vardnsexpdegspspol_check (c, args));
}

static void 
modp_vardnsexpdegspspol_inaddmulmonomsc (modp_vardnsexpdegspspol_t a, int v, modp_vardnsexpdegspspol_t b, vardnsmonom_t m, modp_t t, int w, modp_vardnsexpdegspspol_args args)
{
  modp_vardnsexpdegspslist_inaddmulmonomsc (a->nlink, a, v, b->nlink, b, m, t, w, args);
  assert (modp_vardnsexpdegspspol_check (a, args));
}

static void 
modp_vardnsexpdegspspol_oomulscaddmulmonomsc (modp_vardnsexpdegspspol_t c, modp_vardnsexpdegspspol_t a, modp_t s, int v, modp_vardnsexpdegspspol_t b, vardnsmonom_t m, modp_t t, int w, modp_vardnsexpdegspspol_args args)
{
  modp_vardnsexpdegspspol_init (c, args);
  modp_vardnsexpdegspslist_oomulscaddmulmonomsc (c, a->nlink, a, s, v, b->nlink, b, m, t, w, c, args);
  assert (modp_vardnsexpdegspspol_check (c, args));
}

static void 
modp_vardnsexpdegspspol_inmulscaddmulmonomsc (modp_vardnsexpdegspspol_t a, modp_t s, int v, modp_vardnsexpdegspspol_t b, vardnsmonom_t m, modp_t t, int w, modp_vardnsexpdegspspol_args args)
{
  modp_vardnsexpdegspslist_inmulscaddmulmonomsc (a->nlink, a, s, v, b->nlink, b, m, t, w, args);
  assert (modp_vardnsexpdegspspol_check (a, args));
}

static BOOL 
modp_vardnsexpdegspspol_oodivmonomsc (modp_vardnsexpdegspspol_t c, modp_vardnsexpdegspspol_t b, vardnsmonom_t m, modp_t t, modp_vardnsexpdegspspol_args args)
{
  BOOL failed;
  modp_vardnsexpdegspspol_init (c, args);
  failed = modp_vardnsexpdegspslist_oodivmonomsc (c, b->nlink, b, m, t, c, args);
  assert (modp_vardnsexpdegspspol_check (c, args));
  if (failed)
    modp_vardnsexpdegspspol_clear (c, args);
  return failed;
}

static void 
modp_vardnsexpdegspspol_indivmonomsc (modp_vardnsexpdegspspol_t b, vardnsmonom_t m, modp_t t, modp_vardnsexpdegspspol_args args)
{
  modp_vardnsexpdegspslist_indivmonomsc (b->nlink, b, m, t, args);
  assert (modp_vardnsexpdegspspol_check (b, args));
}

static void 
modp_vardnsexpdegspspol_args_fileOut (id aFiler, modp_vardnsexpdegspspol_args * args)
{
  modp_vardnsexpdegspsterm_args_fileOut (aFiler, args);
}
static void 
modp_vardnsexpdegspspol_args_fileIn (id aFiler, modp_vardnsexpdegspspol_args * args)
{
  modp_vardnsexpdegspsterm_args_fileIn (aFiler, args);
}

static void 
modp_vardnsexpdegspspol_fileOut (id aFiler, modp_vardnsexpdegspspol_t self, modp_vardnsexpdegspspol_args args)
{
  assert (modp_vardnsexpdegspspol_check (self, args));
  modp_vardnsexpdegspslist_fileOut (aFiler, self->nlink, self, args);
}

static void 
modp_vardnsexpdegspspol_fileIn (id aFiler, modp_vardnsexpdegspspol_t self, modp_vardnsexpdegspspol_args args)
{
  modp_vardnsexpdegspspol_init (self, args);
  modp_vardnsexpdegspslist_fileIn (aFiler, self, self, args);
  assert (modp_vardnsexpdegspspol_check (self, args));
}

static modp_vardnsexpdegspspol_args 
modp_vardnsexpdegspspol_getargs (id self)
{
  modp_vardnsexpdegspspol_args res;
  id monomialZero = [self monomialZero];
  res.sargs = modp_getargs ([monomialZero scalar]);
  res.margs = vardnsmonom_getargs ([monomialZero terms]);
  return res;
}
@implementation modp_vardnsexpdegsps_polynomial : vardnsexpdegsps_polynomial

- (modp_vardnsexpdegspspol_t)modp_vardnsexpdegspspol_value
{
  return &value;
}

- domodp_vardnsexpdegspspol_value:(modp_vardnsexpdegspspol_t)aValue
{
  modp_vardnsexpdegspspol_copy (&value, aValue, modp_vardnsexpdegspspol_getargs (self));
  assert ([self check]);
  return self;
}

- modp_vardnsexpdegspspol_value:(modp_vardnsexpdegspspol_t)aValue
{
  return [[self clone] domodp_vardnsexpdegspspol_value:aValue];
}

- (modp_vardnsexpdegspspol_t)modp_vardnsexpdegspspol_reference
{
  return &value;
}

- domodp_vardnsexpdegspspol_reference:(modp_vardnsexpdegspspol_c *)aReference
{
  modp_vardnsexpdegspspol_move (&value, aReference, modp_vardnsexpdegspspol_getargs (self));
  assert ([self check]);
  return self;
}

- modp_vardnsexpdegspspol_reference:(modp_vardnsexpdegspspol_c *)aReference
{
  return [[self clone] domodp_vardnsexpdegspspol_reference:aReference];
}

- copy
{
  modp_vardnsexpdegspspol_c c;
  assert ([self check]);
  modp_vardnsexpdegspspol_copy (&c, &value, modp_vardnsexpdegspspol_getargs (self));
  return modp_vardnsexpdegspspol_c2id (self, &c);
}

- deepCopy
{
  modp_vardnsexpdegspspol_c c;
  assert ([self check]);
  modp_vardnsexpdegspspol_deepcopy (&c, &value, modp_vardnsexpdegspspol_getargs (self));
  return modp_vardnsexpdegspspol_c2id (self, &c);
}

- (BOOL) isEmpty
{
  return modp_vardnsexpdegspspol_isempty (&value);
}

- (BOOL) isOne
{
  return modp_vardnsexpdegspspol_isone (&value, modp_vardnsexpdegspspol_getargs (self));
}

- (BOOL) isMinusOne
{
  return modp_vardnsexpdegspspol_isminusone (&value, modp_vardnsexpdegspspol_getargs (self));
}

- (unsigned) hash
{
  return modp_vardnsexpdegspspol_hash (modp_vardnsexpdegspspol_id2t (self), modp_vardnsexpdegspspol_getargs (self));
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
      return modp_vardnsexpdegspspol_iseq (modp_vardnsexpdegspspol_id2t (self), modp_vardnsexpdegspspol_id2t (b), modp_vardnsexpdegspspol_getargs (self));
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
      return !modp_vardnsexpdegspspol_iseq (modp_vardnsexpdegspspol_id2t (self), modp_vardnsexpdegspspol_id2t (b), modp_vardnsexpdegspspol_getargs (self));
    }
}

- (BOOL) isZero
{
  assert ([self check]);
  return modp_vardnsexpdegspspol_iszero (modp_vardnsexpdegspspol_id2t (self), modp_vardnsexpdegspspol_getargs (self));
}

- (BOOL) notZero
{
  assert ([self check]);
  return !modp_vardnsexpdegspspol_iszero (modp_vardnsexpdegspspol_id2t (self), modp_vardnsexpdegspspol_getargs (self));
}

- (BOOL) isOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return modp_vardnsexpdegspspol_isop (modp_vardnsexpdegspspol_id2t (self), modp_vardnsexpdegspspol_id2t (b), modp_vardnsexpdegspspol_getargs (self));
}

- (BOOL) notOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return !modp_vardnsexpdegspspol_isop (modp_vardnsexpdegspspol_id2t (self), modp_vardnsexpdegspspol_id2t (b), modp_vardnsexpdegspspol_getargs (self));
}

- negate
{
  modp_vardnsexpdegspspol_c c;
  assert ([self check]);
  modp_vardnsexpdegspspol_ooneg (&c, modp_vardnsexpdegspspol_id2t (self), modp_vardnsexpdegspspol_getargs (self));
  return modp_vardnsexpdegspspol_c2id (self, &c);
}

- _double:(int)v
{
  modp_vardnsexpdegspspol_c c;
  assert ([self check]);
  modp_vardnsexpdegspspol_oodbl (&c, modp_vardnsexpdegspspol_id2t (self), v, modp_vardnsexpdegspspol_getargs (self));
  return modp_vardnsexpdegspspol_c2id (self, &c);
}

- double
{
  modp_vardnsexpdegspspol_c c;
  assert ([self check]);
  modp_vardnsexpdegspspol_oodbl (&c, modp_vardnsexpdegspspol_id2t (self), +1, modp_vardnsexpdegspspol_getargs (self));
  return modp_vardnsexpdegspspol_c2id (self, &c);
}

- _add:(int)v:b:(int)w
{
  modp_vardnsexpdegspspol_c c;
  assert ([self sameClass:b] && v * v == 1 && w * w == 1 && self != b);
  modp_vardnsexpdegspspol_ooadd (&c, modp_vardnsexpdegspspol_id2t (self), v, modp_vardnsexpdegspspol_id2t (b), w, modp_vardnsexpdegspspol_getargs (self));
  return modp_vardnsexpdegspspol_c2id (self, &c);
}

- add:b
{
  modp_vardnsexpdegspspol_c c;
  assert ([self checkSameClass:b] && self != b);
  modp_vardnsexpdegspspol_ooadd (&c, modp_vardnsexpdegspspol_id2t (self), +1, modp_vardnsexpdegspspol_id2t (b), +1, modp_vardnsexpdegspspol_getargs (self));
  return modp_vardnsexpdegspspol_c2id (self, &c);
}

- subtract:b
{
  modp_vardnsexpdegspspol_c c;
  assert ([self checkSameClass:b] && self != b);
  modp_vardnsexpdegspspol_ooadd (&c, modp_vardnsexpdegspspol_id2t (self), +1, modp_vardnsexpdegspspol_id2t (b), -1, modp_vardnsexpdegspspol_getargs (self));
  return modp_vardnsexpdegspspol_c2id (self, &c);
}

- (int) leadingDegree
{
  return modp_vardnsexpdegspspol_deg (&value, modp_vardnsexpdegspspol_getargs (self));
}

- (int) lastDegree
{
  return modp_vardnsexpdegspspol_ord (&value, modp_vardnsexpdegspspol_getargs (self));
}

- (int) maxDegree
{
  return modp_vardnsexpdegspspol_maxdeg (&value, modp_vardnsexpdegspspol_getargs (self));
}

- (int) minDegree
{
  return modp_vardnsexpdegspspol_mindeg (&value, modp_vardnsexpdegspspol_getargs (self));
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
  assert (scalarZero && termZero && monomialZero && symbols);
  [scalarZero check];
  [termZero check];
  [monomialZero check];
  [symbols check];
  assert ([symbols size] >= 1);
  assert ([scalarZero isEqual:[monomialZero scalar]]);
  assert ([symbols isEqual:[monomialZero symbols]]);

  modp_vardnsexpdegspspol_check (&value, modp_vardnsexpdegspspol_getargs (self));
  return self;
}

- _setUpScalarZero:aScalar symbols:aCltn
{
  assert ([aScalar isZero] && [aCltn notEmpty]);
  assert ([aScalar class_vardnsexpdegsps_polynomial] == [self class]);

  termZero = [Term scalar:aScalar symbol:nil exponent:0];
  monomialZero = [Monomial scalar:aScalar symbols:aCltn];

  scalarZero = aScalar;
  symbols = aCltn;

  modp_vardnsexpdegspspol_init (&value, modp_vardnsexpdegspspol_getargs (self));
  assert ([self check]);
  return self;
}

+ scalarZero:aScalar symbols:aCltn
{
  return [[super new] _setUpScalarZero:aScalar symbols:aCltn];
}

- release
{
  modp_vardnsexpdegspspol_clear (&value, modp_vardnsexpdegspspol_getargs (self));
  return [super release];
}

- empty
{
  modp_vardnsexpdegspspol_c c;
  assert ([self check]);
  modp_vardnsexpdegspspol_init (&c, modp_vardnsexpdegspspol_getargs (self));
  return modp_vardnsexpdegspspol_c2id (self, &c);
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

- (int) numMonomials
{
  assert ([self check]);
  return modp_vardnsexpdegspspol_count (&value);
}

- eachMonomial
{
  id aSequence = [modp_vardnsexpdegspspol_sequence content:self];
  return [CASequence over:aSequence];
}

- elt_modp_vardnsexpdegspspol_ix:(modp_vardnsexpdegspspol_ixt)ix
{
  if (modp_vardnsexpdegspspol_ix_ismatch (ix))
    {
      id s, m;
      modp_t sc;
      vardnsmonom_t mc;
      sc = modp_vardnsexpdegspspol_scalat (&value, ix, modp_vardnsexpdegspspol_getargs (self));
      mc = modp_vardnsexpdegspspol_monomat (&value, ix, modp_vardnsexpdegspspol_getargs (self));
      s = modp_t2id ([monomialZero scalar], sc);
      m = vardnsmonom_t2id ([monomialZero terms], mc);
      return [monomialZero scalar:s terms:m];
    }
  else
    {
      return nil;
    }
}

- removeMonomial
{
  if ([self isEmpty])
    {
      return nil;
    }
  else
    {
      id lt;
      id m, s;
      modp_t sc;
      vardnsmonom_t mc;
      assert ([self check]);

      sc = modp_vardnsexpdegspspol_scalfirst (&value, modp_vardnsexpdegspspol_getargs (self));
      mc = modp_vardnsexpdegspspol_monomfirst (&value, modp_vardnsexpdegspspol_getargs (self));
      s = modp_t2id ([monomialZero scalar], sc);
      m = vardnsmonom_t2id ([monomialZero terms], mc);
      lt = [monomialZero scalar:s terms:m];

      modp_vardnsexpdegspspol_remove (&value, modp_vardnsexpdegspspol_getargs (self));
      [self invalidate];
      assert ([self check]);
      return lt;
    }
}

- insertMonomial:aMonomial
{
  if ([aMonomial isZero])
    {
      return self;
    }
  else
    {
      modp_c c;
      modp_t r;
      vardnsmonom_t m;
      assert ([aMonomial check]);
      assert ([self check]);
      r = modp_id2ref ([aMonomial scalar], &c);
      m = vardnsmonom_id2t ([aMonomial terms]);
      modp_vardnsexpdegspspol_insert (&value, m, r, modp_vardnsexpdegspspol_getargs (self));
      assert ([aMonomial check]);
      [self invalidate];
      assert ([self check]);
      return self;
    }
}

- multiplyScalar:s
{
  modp_vardnsexpdegspspol_c c;
  modp_c sc;
  modp_vardnsexpdegspspol_oomulsc (&c, modp_vardnsexpdegspspol_id2t (self), modp_id2ref (s, &sc), modp_vardnsexpdegspspol_getargs (self));
  return modp_vardnsexpdegspspol_c2id (self, &c);
}

- divideScalar:s
{
  modp_vardnsexpdegspspol_c c;
  modp_c sc;
  BOOL failed = modp_vardnsexpdegspspol_oodivsc (&c, modp_vardnsexpdegspspol_id2t (self), modp_id2ref (s, &sc), modp_vardnsexpdegspspol_getargs (self));
  return (failed) ? nil : modp_vardnsexpdegspspol_c2id (self, &c);
}

- _add:(int)v:B multiplyScalar:b:(int)w
{
  modp_vardnsexpdegspspol_c c;
  modp_c bc;
  assert ([self sameClass:B] && [scalarZero sameClass:b] && v * v == 1 && w * w == 1);
  modp_vardnsexpdegspspol_ooaddmulsc (&c, modp_vardnsexpdegspspol_id2t (self), v, modp_vardnsexpdegspspol_id2t (B), modp_id2ref (b, &bc), w, modp_vardnsexpdegspspol_getargs (self));
  return modp_vardnsexpdegspspol_c2id (self, &c);
}

- _multiplyScalar:a:(int)v add:B:(int)w
{
  modp_vardnsexpdegspspol_c c;
  modp_c ac;
  assert ([scalarZero sameClass:a] && [self sameClass:B] && v * v == 1 && w * w == 1);
  modp_vardnsexpdegspspol_oomulscadd (&c, modp_vardnsexpdegspspol_id2t (self), modp_id2ref (a, &ac), v, modp_vardnsexpdegspspol_id2t (B), w, modp_vardnsexpdegspspol_getargs (self));
  return modp_vardnsexpdegspspol_c2id (self, &c);
}

- _multiplyScalar:a:(int)v add:B multiplyScalar:b:(int)w
{
  modp_vardnsexpdegspspol_c c;
  modp_c ac, bc;
  assert ([scalarZero sameClass:a] && [self sameClass:B] && [scalarZero sameClass:b] && v * v == 1 && w * w == 1);
  modp_vardnsexpdegspspol_oomulscaddmulsc (&c, modp_vardnsexpdegspspol_id2t (self), modp_id2ref (a, &ac), v, modp_vardnsexpdegspspol_id2t (B), modp_id2ref (b, &bc), w, modp_vardnsexpdegspspol_getargs (self));
  return modp_vardnsexpdegspspol_c2id (self, &c);
}

- multiplyMonomial:aMonomial
{
  modp_vardnsexpdegspspol_c c;
  modp_t s;
  modp_c sc;
  vardnsmonom_t m;

  m = vardnsmonom_id2t ([aMonomial terms]);
  s = modp_id2ref ([aMonomial scalar], &sc);
  modp_vardnsexpdegspspol_oomulmonomsc (&c, modp_vardnsexpdegspspol_id2t (self), m, s, +1, modp_vardnsexpdegspspol_getargs (self));
  return modp_vardnsexpdegspspol_c2id (self, &c);
}

- _multiplyMonomial:aMonomial:(int)v
{
  modp_vardnsexpdegspspol_c c;
  modp_t s;
  modp_c sc;
  vardnsmonom_t m;

  m = vardnsmonom_id2t ([aMonomial terms]);
  s = modp_id2ref ([aMonomial scalar], &sc);
  modp_vardnsexpdegspspol_oomulmonomsc (&c, modp_vardnsexpdegspspol_id2t (self), m, s, v, modp_vardnsexpdegspspol_getargs (self));
  return modp_vardnsexpdegspspol_c2id (self, &c);
}

- divideMonomial:aMonomial
{
  BOOL failed;
  modp_vardnsexpdegspspol_c c;
  modp_t s;
  modp_c sc;
  vardnsmonom_t m;

  m = vardnsmonom_id2t ([aMonomial terms]);
  s = modp_id2ref ([aMonomial scalar], &sc);
  failed = modp_vardnsexpdegspspol_oodivmonomsc (&c, modp_vardnsexpdegspspol_id2t (self), m, s, modp_vardnsexpdegspspol_getargs (self));
  return (failed) ? nil : modp_vardnsexpdegspspol_c2id (self, &c);
}

- _add:(int)v:B multiplyMonomial:b:(int)w
{
  modp_vardnsexpdegspspol_c c;
  modp_c bc;
  modp_t bs;
  vardnsmonom_t bm;

  bm = vardnsmonom_id2t ([b terms]);
  bs = modp_id2ref ([b scalar], &bc);
  modp_vardnsexpdegspspol_ooaddmulmonomsc (&c, modp_vardnsexpdegspspol_id2c (self), v, modp_vardnsexpdegspspol_id2t (B), bm, bs, w, modp_vardnsexpdegspspol_getargs (self));
  return modp_vardnsexpdegspspol_c2id (self, &c);
}

- _multiplyScalar:a:(int)v add:B multiplyMonomial:b:(int)w
{
  modp_vardnsexpdegspspol_c c;
  modp_c ac, bc;
  modp_t as, bs;
  vardnsmonom_t bm;

  as = modp_id2ref (a, &ac);
  bm = vardnsmonom_id2t ([b terms]);
  bs = modp_id2ref ([b scalar], &bc);
  modp_vardnsexpdegspspol_oomulscaddmulmonomsc (&c, modp_vardnsexpdegspspol_id2c (self), as, v, modp_vardnsexpdegspspol_id2t (B), bm, bs, w, modp_vardnsexpdegspspol_getargs (self));
  return modp_vardnsexpdegspspol_c2id (self, &c);
}


- fileOutOn:aFiler
{
  modp_vardnsexpdegspspol_args args;
  assert ([self check]);
  [super fileOutOn:aFiler];
  args = modp_vardnsexpdegspspol_getargs (self);
  modp_vardnsexpdegspspol_args_fileOut (aFiler, &args);
  modp_vardnsexpdegspspol_fileOut (aFiler, &value, args);
  return self;
}

- fileInFrom:aFiler
{
  modp_vardnsexpdegspspol_args args;
  [super fileInFrom:aFiler];
  modp_vardnsexpdegspspol_args_fileIn (aFiler, &args);
  modp_vardnsexpdegspspol_fileIn (aFiler, &value, args);
  return self;
}

@end
 
