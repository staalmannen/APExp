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
 * $Id: mdrdpolc.m,v 1.6 2000/10/12 14:40:26 stes Exp $
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

#if modp_pervalue
static modp_t 
modpseq_tval (modpseq_t self)
{
  return *self;
}
static modp_c *
modpseq_cval (modpseq_t self)
{
  return self;
}
#else
static modp_t 
modpseq_tval (modpseq_t self)
{
  return self;
}
static modp_c *
modpseq_cval (modpseq_t self)
{
  return self;
}
#endif

static int 
modpseq_check (modpseq_t self, int n, modp_args args)
{
  while (n--)
    {
      modp_check (modpseq_tval (self), args);
      self += modp_size (args);
    }
  return 1;
}

static modpseq_t 
modpseq_alloc (int n, modp_args args)
{
  modpseq_t p;
  int m = n * modp_bsize (args);
#if OBJC_REFCNT
  p = (modpseq_t) OC_Calloc (m);
#else
  p = (modpseq_t) OC_Malloc (m);
#endif
  return p;
}

static modpseq_t 
modpseq_realloc (modpseq_t self, int oldc, int n, modp_args args)
{
  modpseq_t p;
  int m = n * modp_bsize (args);
  p = (modpseq_t) OC_Realloc (self, m);
#if OBJC_REFCNT
  assert (oldc <= n);
  memset (p + oldc, 0, (n - oldc) * modp_bsize (args));
#endif
  return p;
}

static modpseq_t 
modpseq_free (modpseq_t self, modp_args args)
{
  OC_Free (self);
  return NULL;
}

static void 
modpseq_oozero (modpseq_t c, int n, modp_args args)
{
  while (n--)
    {
      modp_oozero (modpseq_cval (c), args);
      c += modp_size (args);
    }
}

static void 
modpseq_copy (modpseq_t c, modpseq_t a, int n, modp_args args)
{
  assert (n >= 0);
  while (n--)
    {
      modp_copy (modpseq_cval (c), modpseq_tval (a), args);
      c += modp_size (args);
      a += modp_size (args);
    }
}

static void 
modpseq_deepcopy (modpseq_t c, modpseq_t a, int n, modp_args args)
{
  assert (n >= 0);
  while (n--)
    {
      modp_deepcopy (modpseq_cval (c), modpseq_tval (a), args);
      c += modp_size (args);
      a += modp_size (args);
    }
}

#if modp_isvalue
static void 
modpseq_clear (modpseq_t self, int n, modp_args args)
{
  /* nothing to clear */
}
#else
static void 
modpseq_clear (modpseq_t self, int n, modp_args args)
{
  while (n--)
    {
      modp_clear (self, args);
      self += modp_size (args);
    }
}
#endif /* modp_isvalue */

static int 
modpseq_iseq (modpseq_t a, modpseq_t b, int n, modp_args args)
{
  assert (n >= 0 && a != b);
  while (n--)
    {
      if (!modp_iseq (modpseq_tval (a), modpseq_tval (b), args))
	{
	  return 0;
	}
      else
	{
	  a += modp_size (args);
	  b += modp_size (args);
	}
    }
  return 1;
}

static unsigned 
modpseq_hash (modpseq_t a, int n, modp_args args)
{
  assert (n >= 0);
  return (n) ? modp_hash (modpseq_tval (a), args) : 0;
}

static void 
modpseq_place (modpseq_t self, modp_t a, int i, modp_args args)
{
  modp_c *c = modpseq_cval (self + i * modp_size (args));
  modp_clear (c, args);
  modp_copy (c, a, args);
}

static int 
modpseq_insertlast (modpseq_t self, modp_t a, int n, modp_args args)
{
  modp_c *c;
  assert (n >= 0);
  c = modpseq_cval (self + n * modp_size (args));
  modp_copy (c, a, args);
  return ++n;
}

static int 
modpseq_insertfirst (modpseq_t self, modp_t a, int n, modp_args args)
{
  int j;
  assert (n > 0);
  self += n * modp_size (args);
  j = n;
  while (j--)
    {
      modpseq_t t;
      t = self - modp_size (args);
      modp_move (modpseq_cval (self), modpseq_cval (t), args);
      self = t;
    }
  modp_copy (modpseq_cval (self), a, args);
  return ++n;
}

static int 
modpseq_insertat (modpseq_t self, modp_t a, int i, int n, modp_args args)
{
  assert (0 <= i && i < n);
  self += i * modp_size (args);
  return i + modpseq_insertfirst (self, a, n - i, args);
}

static int 
modpseq_freelast (modpseq_t self, int n, modp_args args)
{
  modp_c *c;
  assert (0 < n);
  --n;
  c = modpseq_cval (self + n * modp_size (args));
  modp_clear (c, args);
  return n;
}

static int 
modpseq_freefirst (modpseq_t self, int n, modp_args args)
{
  int j;
  assert (0 < n);
  modp_clear (modpseq_cval (self), args);
  --n;
  j = n;
  while (j--)
    {
      modpseq_t t;
      t = self + modp_size (args);
      modp_move (modpseq_cval (self), modpseq_cval (t), args);
      self = t;
    }
  return n;
}

static int 
modpseq_freeat (modpseq_t self, int i, int n, modp_args args)
{
  assert (0 <= i && i < n);
  self += i * modp_size (args);
  return i + modpseq_freefirst (self, n - i, args);
}

static modp_t 
modpseq_at (modpseq_t self, int i, modp_args args)
{
  modp_t res;
  assert (0 <= i);
  res = modpseq_tval (self + i * modp_size (args));
  assert (modp_check (res, args));
  return res;
}

static modp_t 
modpseq_last (modpseq_t self, int n, modp_args args)
{
  return modpseq_at (self, n - 1, args);
}

static modp_c *
modpseq_cvalat (modpseq_t self, int i, modp_args args)
{
  assert (0 <= i);
  return modpseq_cval (self + i * modp_size (args));
}

static int 
modpseq_iszero (modpseq_t a, int n, modp_args args)
{
  assert (n >= 0);
  while (n--)
    {
      if (modp_iszero (modpseq_tval (a), args))
	{
	  a += modp_size (args);
	}
      else
	{
	  return 0;
	}
    }
  return 1;
}

static int 
modpseq_isop (modpseq_t a, modpseq_t b, int n, modp_args args)
{
  assert (n >= 0 && a != b);
  while (n--)
    {
      if (!modp_isop (modpseq_tval (a), modpseq_tval (b), args))
	{
	  return 0;
	}
      else
	{
	  a += modp_size (args);
	  b += modp_size (args);
	}
    }
  return 1;
}

static void 
modpseq_ooneg (modpseq_t c, modpseq_t a, int n, modp_args args)
{
  assert (n >= 0);
  while (n--)
    {
      modp_ooneg (modpseq_cval (c), modpseq_tval (a), args);
      c += modp_size (args);
      a += modp_size (args);
    }
}

static void 
modpseq_inneg (modpseq_t a, int n, modp_args args)
{
  assert (n >= 0);
  while (n--)
    {
      modp_inneg (modpseq_cval (a), args);
      a += modp_size (args);
    }
}

static void 
modpseq_oonegv (modpseq_t c, modpseq_t a, int v, int n, modp_args args)
{
  assert (v * v == 1);
  if (v == -1)
    modpseq_ooneg (c, a, n, args);
  else
    modpseq_copy (c, a, n, args);
}

static void 
modpseq_innegv (modpseq_t a, int v, int n, modp_args args)
{
  assert (v * v == 1);
  if (v == -1)
    modpseq_inneg (a, n, args);
}

static void 
modpseq_oodbl (modpseq_t c, modpseq_t a, int v, int n, modp_args args)
{
  assert (n >= 0 && v * v == 1);
  while (n--)
    {
      modp_oodbl (modpseq_cval (c), modpseq_tval (a), v, args);
      c += modp_size (args);
      a += modp_size (args);
    }
}

static void 
modpseq_indbl (modpseq_t a, int v, int n, modp_args args)
{
  assert (n >= 0 && v * v == 1);
  while (n--)
    {
      modp_indbl (modpseq_cval (a), v, args);
      a += modp_size (args);
    }
}

static void 
modpseq_ooadd (modpseq_t c, modpseq_t a, int v, modpseq_t b, int w, int n, modp_args args)
{
  assert (n >= 0 && a != b && v * v == 1 && w * w == 1);
  while (n--)
    {
      modp_ooadd (modpseq_cval (c), modpseq_tval (a), v, modpseq_tval (b), w, args);
      c += modp_size (args);
      a += modp_size (args);
      b += modp_size (args);
    }
}

static void 
modpseq_inadd (modpseq_t a, int v, modpseq_t b, int w, int n, modp_args args)
{
  assert (n >= 0 && a != b && v * v == 1 && w * w == 1);
  while (n--)
    {
      modp_inadd (modpseq_cval (a), v, modpseq_tval (b), w, args);
      a += modp_size (args);
      b += modp_size (args);
    }
}

static void 
modpseq_oomulsc (modpseq_t c, modpseq_t a, modp_t s, int n, modp_args args)
{
  assert (n >= 0);
  while (n--)
    {
      modp_oomul (modpseq_cval (c), modpseq_tval (a), s, args);
      c += modp_size (args);
      a += modp_size (args);
    }
}

static void 
modpseq_inmulsc (modpseq_t a, modp_t s, int n, modp_args args)
{
  assert (n >= 0);
  while (n--)
    {
      modp_inmul (modpseq_cval (a), s, args);
      a += modp_size (args);
    }
}

static void 
modpseq_oomulscv (modpseq_t c, modpseq_t a, modp_t s, int v, int n, modp_args args)
{
  assert (n >= 0 && v * v == 1);
  while (n--)
    {
      modp_oomulv (modpseq_cval (c), modpseq_tval (a), s, v, args);
      c += modp_size (args);
      a += modp_size (args);
    }
}

static void 
modpseq_inmulscv (modpseq_t a, modp_t s, int v, int n, modp_args args)
{
  assert (n >= 0 && v * v == 1);
  while (n--)
    {
      modp_inmulv (modpseq_cval (a), s, v, args);
      a += modp_size (args);
    }
}

static void 
modpseq_ooaddmulsc (modpseq_t c, modpseq_t a, int v, modpseq_t b, modp_t t, int w, int n, modp_args args)
{
  assert (n >= 0 && v * v == 1 && w * w == 1);
  while (n--)
    {
      modp_ooaddmul (modpseq_cval (c), modpseq_tval (a), v, modpseq_tval (b), t, w, args);
      a += modp_size (args);
      b += modp_size (args);
      c += modp_size (args);
    }
}

static void 
modpseq_oomulscadd (modpseq_t c, modpseq_t a, modp_t s, int v, modpseq_t b, int w, int n, modp_args args)
{
  assert (n >= 0 && v * v == 1 && w * w == 1);
  while (n--)
    {
      modp_oomuladd (modpseq_cval (c), modpseq_tval (a), s, v, modpseq_tval (b), w, args);
      a += modp_size (args);
      b += modp_size (args);
      c += modp_size (args);
    }
}

static void 
modpseq_oomulscaddmulsc (modpseq_t c, modpseq_t a, modp_t s, int v, modpseq_t b, modp_t t, int w, int n, modp_args args)
{
  assert (n >= 0 && v * v == 1 && w * w == 1);
  while (n--)
    {
      modp_oomuladdmul (modpseq_cval (c), modpseq_tval (a), s, v, modpseq_tval (b), t, w, args);
      a += modp_size (args);
      b += modp_size (args);
      c += modp_size (args);
    }
}

static void 
modpseq_inaddmulsc (modpseq_t a, int v, modpseq_t b, modp_t t, int w, int n, modp_args args)
{
  assert (n >= 0 && v * v == 1 && w * w == 1);
  while (n--)
    {
      modp_inaddmul (modpseq_cval (a), v, modpseq_tval (b), t, w, args);
      a += modp_size (args);
      b += modp_size (args);
    }
}

static void 
modpseq_inmulscadd (modpseq_t a, modp_t s, int v, modpseq_t b, int w, int n, modp_args args)
{
  assert (n >= 0 && v * v == 1 && w * w == 1);
  while (n--)
    {
      modp_inmuladd (modpseq_cval (a), s, v, modpseq_tval (b), w, args);
      a += modp_size (args);
      b += modp_size (args);
    }
}

static void 
modpseq_inmulscaddmulsc (modpseq_t a, modp_t s, int v, modpseq_t b, modp_t t, int w, int n, modp_args args)
{
  assert (n >= 0 && v * v == 1 && w * w == 1);
  while (n--)
    {
      modp_inmuladdmul (modpseq_cval (a), s, v, modpseq_tval (b), t, w, args);
      a += modp_size (args);
      b += modp_size (args);
    }
}

static BOOL 
modpseq_oodivsc (modpseq_t c, modpseq_t a, modp_t s, int n, modp_args args)
{
  int i;
  BOOL failed;
  modpseq_t orgc = c;
  assert (n >= 0);

  for (i = 0; i < n; i++)
    {

      failed = modp_oodiv (modpseq_cval (c), modpseq_tval (a), s, args);

      if (failed)
	{
	  modpseq_clear (orgc, i - 1, args);
	  return FAILURE;
	}
      else
	{
	  c += modp_size (args);
	  a += modp_size (args);
	}
    }

  return SUCCESS;
}

static void 
modpseq_indivsc (modpseq_t a, modp_t s, int n, modp_args args)
{
  assert (n >= 0);
  while (n--)
    {
      modp_indiv (modpseq_cval (a), s, args);
      a += modp_size (args);
    }
}

static void 
modpseq_oodotsqr (modp_c * c, modpseq_t a, int n, modp_args args)
{
  assert (n >= 0);
  modp_oozero (c, args);
  while (n--)
    {
      modp_inaddsqr (c, +1, modpseq_tval (a), +1, args);
      a += modp_size (args);
    }
}

static void 
modpseq_oodotmul (modp_c * c, modpseq_t a, modpseq_t b, int n, modp_args args)
{
  assert (n >= 0);
  modp_oozero (c, args);
  while (n--)
    {
      modp_inaddmul (c, +1, modpseq_tval (a), modpseq_tval (b), +1, args);
      a += modp_size (args);
      b += modp_size (args);
    }
}

static void 
modpseq_args_fileOut (id aFiler, modp_args * args)
{
  modp_args_fileOut (aFiler, args);
}
static void 
modpseq_args_fileIn (id aFiler, modp_args * args)
{
  modp_args_fileIn (aFiler, args);
}

static void 
modpseq_fileOut (id aFiler, modpseq_t self, int n, modp_args args)
{
  assert (n >= 0);
  while (n--)
    {
      modp_fileOut (aFiler, modpseq_cval (self), args);
      self += modp_size (args);
    }
}

static void 
modpseq_fileIn (id aFiler, modpseq_t self, int n, modp_args args)
{
  assert (n >= 0);
  while (n--)
    {
      modp_fileIn (aFiler, modpseq_cval (self), args);
      self += modp_size (args);
    }
}

static int 
modp_vardnsrecdegdnspolseq_check (modp_vardnsrecdegdnspolseq_t self, int n, modp_vardnsrecdegdnspol_args args)
{
  if (n)
    {
      modp_t lcf = modpseq_last (self, n, args.sargs);
      assert (!modp_iszero (lcf, args.sargs));
    }

  return modpseq_check (self, n, args.sargs);
}

static int 
modp_vardnsrecdegdnspolseq_copy (modp_vardnsrecdegdnspolseq_t c, modp_vardnsrecdegdnspolseq_t a, int n, modp_vardnsrecdegdnspol_args args)
{
  modpseq_copy (c, a, n, args.sargs);
  return n;
}

static int 
modp_vardnsrecdegdnspolseq_deepcopy (modp_vardnsrecdegdnspolseq_t c, modp_vardnsrecdegdnspolseq_t a, int n, modp_vardnsrecdegdnspol_args args)
{
  modpseq_deepcopy (c, a, n, args.sargs);
  return n;
}

static int 
modp_vardnsrecdegdnspolseq_count (modp_vardnsrecdegdnspolseq_t self, int n, modp_vardnsrecdegdnspol_args args)
{
  int count = 0;
  while (n--)
    {
      if (!modp_iszero (modpseq_tval (self), args.sargs))
	count++;
      self += modp_size (args.sargs);
    }
  return count;
}

static int 
modp_vardnsrecdegdnspolseq_ord (modp_vardnsrecdegdnspolseq_t self, int n, modp_vardnsrecdegdnspol_args args)
{
  int ord = -1;
  while (n--)
    {
      if (modp_iszero (modpseq_tval (self), args.sargs))
	{
	  ord++;
	  self += modp_size (args.sargs);
	}
      else
	{
	  break;
	}
    }
  return ord;
}

static int 
modp_vardnsrecdegdnspolseq_iseq (modp_vardnsrecdegdnspolseq_t a, int an, modp_vardnsrecdegdnspolseq_t b, int bn, modp_vardnsrecdegdnspol_args args)
{
  return (an == bn) ? modpseq_iseq (a, b, an, args.sargs) : 0;
}

static int 
modp_vardnsrecdegdnspolseq_isop (modp_vardnsrecdegdnspolseq_t a, int an, modp_vardnsrecdegdnspolseq_t b, int bn, modp_vardnsrecdegdnspol_args args)
{
  return (an == bn) ? modpseq_isop (a, b, an, args.sargs) : 0;
}

static int 
modp_vardnsrecdegdnspolseq_hash (modp_vardnsrecdegdnspolseq_t a, int an, modp_vardnsrecdegdnspol_args args)
{
  return modpseq_hash (a, an, args.sargs);
}

static int 
modp_vardnsrecdegdnspolseq_isone (modp_vardnsrecdegdnspolseq_t a, int an, modp_vardnsrecdegdnspol_args args)
{
  return an == 1 && modp_isone (modpseq_tval (a), args.sargs);
}

static int 
modp_vardnsrecdegdnspolseq_isminusone (modp_vardnsrecdegdnspolseq_t a, int an, modp_vardnsrecdegdnspol_args args)
{
  return an == 1 && modp_isminusone (modpseq_tval (a), args.sargs);
}

static int 
modp_vardnsrecdegdnspolseq_removezeroes (modp_vardnsrecdegdnspolseq_t a, int n, modp_vardnsrecdegdnspol_args args)
{
  a += n * modp_size (args.sargs);
  while (n--)
    {
      a -= modp_size (args.sargs);
      if (modp_iszero (modpseq_tval (a), args.sargs))
	{
	  modp_clear (modpseq_cval (a), args.sargs);
	}
      else
	{
	  break;
	}
    }
  return n + 1;
}

static int 
modp_vardnsrecdegdnspolseq_delete (modp_vardnsrecdegdnspolseq_t self, int n, modp_vardnsrecdegdnspol_args args)
{
  n = n - 1;
  assert (n >= 0);
  modp_clear (modpseq_cvalat (self, n, args.sargs), args.sargs);
  return modp_vardnsrecdegdnspolseq_removezeroes (self, n, args);
}

static int 
modp_vardnsrecdegdnspolseq_insert (modp_vardnsrecdegdnspolseq_t self, int n, int e, modp_t s, modp_vardnsrecdegdnspol_args args)
{
  assert (modp_iszero (s, args.sargs) == 0);
  if (e < n)
    {
      modp_inadd (modpseq_cvalat (self, e, args.sargs), +1, s, +1, args.sargs);
      return modp_vardnsrecdegdnspolseq_removezeroes (self, n, args);
    }
  else
    {
      modpseq_oozero (self + n * modp_size (args.sargs), e + 1 - n, args.sargs);
      modp_inadd (modpseq_cvalat (self, e, args.sargs), +1, s, +1, args.sargs);
      return e + 1;
    }
}

static int 
modp_vardnsrecdegdnspolseq_ooneg (modp_vardnsrecdegdnspolseq_t c, modp_vardnsrecdegdnspolseq_t a, int n, modp_vardnsrecdegdnspol_args args)
{
  modpseq_ooneg (c, a, n, args.sargs);
  return n;
}

static int 
modp_vardnsrecdegdnspolseq_inneg (modp_vardnsrecdegdnspolseq_t a, int n, modp_vardnsrecdegdnspol_args args)
{
  modpseq_inneg (a, n, args.sargs);
  return n;
}

static int 
modp_vardnsrecdegdnspolseq_oodbl (modp_vardnsrecdegdnspolseq_t c, modp_vardnsrecdegdnspolseq_t a, int n, int v, modp_vardnsrecdegdnspol_args args)
{
  modpseq_oodbl (c, a, v, n, args.sargs);
  return modp_vardnsrecdegdnspolseq_removezeroes (c, n, args);
}

static int 
modp_vardnsrecdegdnspolseq_indbl (modp_vardnsrecdegdnspolseq_t a, int n, int v, modp_vardnsrecdegdnspol_args args)
{
  modpseq_indbl (a, v, n, args.sargs);
  return modp_vardnsrecdegdnspolseq_removezeroes (a, n, args);
}

static int 
modp_vardnsrecdegdnspolseq_ooadd (modp_vardnsrecdegdnspolseq_t c, modp_vardnsrecdegdnspolseq_t a, int an, int v, modp_vardnsrecdegdnspolseq_t b, int bn, int w, modp_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      modpseq_ooadd (c, a, v, b, w, an, args.sargs);
      return modp_vardnsrecdegdnspolseq_removezeroes (c, an, args);
    }
  else
    {
      if (an < bn)
	{
	  modpseq_ooadd (c, a, v, b, w, an, args.sargs);
	  c += an * modp_size (args.sargs);
	  b += an * modp_size (args.sargs);
	  modpseq_oonegv (c, b, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  modpseq_ooadd (c, a, v, b, w, bn, args.sargs);
	  c += bn * modp_size (args.sargs);
	  a += bn * modp_size (args.sargs);
	  modpseq_oonegv (c, a, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static int 
modp_vardnsrecdegdnspolseq_inadd (modp_vardnsrecdegdnspolseq_t a, int an, int v, modp_vardnsrecdegdnspolseq_t b, int bn, int w, modp_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      modpseq_inadd (a, v, b, w, an, args.sargs);
      return modp_vardnsrecdegdnspolseq_removezeroes (a, an, args);
    }
  else
    {
      if (an < bn)
	{
	  modpseq_inadd (a, v, b, w, an, args.sargs);
	  a += an * modp_size (args.sargs);
	  b += an * modp_size (args.sargs);
	  modpseq_oonegv (a, b, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  modpseq_inadd (a, v, b, w, bn, args.sargs);
	  a += bn * modp_size (args.sargs);
	  modpseq_innegv (a, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static int 
modp_vardnsrecdegdnspolseq_oomulsc (modp_vardnsrecdegdnspolseq_t c, modp_vardnsrecdegdnspolseq_t a, int n, modp_t s, modp_vardnsrecdegdnspol_args args)
{
  modpseq_oomulsc (c, a, s, n, args.sargs);
  return modp_vardnsrecdegdnspolseq_removezeroes (c, n, args);
}

static int 
modp_vardnsrecdegdnspolseq_inmulsc (modp_vardnsrecdegdnspolseq_t a, int n, modp_t s, modp_vardnsrecdegdnspol_args args)
{
  modpseq_inmulsc (a, s, n, args.sargs);
  return modp_vardnsrecdegdnspolseq_removezeroes (a, n, args);
}

static int 
modp_vardnsrecdegdnspolseq_ooaddmulsc (modp_vardnsrecdegdnspolseq_t c, modp_vardnsrecdegdnspolseq_t a, int an, int v, modp_vardnsrecdegdnspolseq_t b, int bn, modp_t t, int w, modp_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      modpseq_ooaddmulsc (c, a, v, b, t, w, an, args.sargs);
      return modp_vardnsrecdegdnspolseq_removezeroes (c, an, args);
    }
  else
    {
      if (an < bn)
	{
	  modpseq_ooaddmulsc (c, a, v, b, t, w, an, args.sargs);
	  c += an * modp_size (args.sargs);
	  b += an * modp_size (args.sargs);
	  modpseq_oomulscv (c, b, t, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  modpseq_ooaddmulsc (c, a, v, b, t, w, bn, args.sargs);
	  c += bn * modp_size (args.sargs);
	  a += bn * modp_size (args.sargs);
	  modpseq_oonegv (c, a, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static int 
modp_vardnsrecdegdnspolseq_inaddmulsc (modp_vardnsrecdegdnspolseq_t a, int an, int v, modp_vardnsrecdegdnspolseq_t b, int bn, modp_t t, int w, modp_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      modpseq_inaddmulsc (a, v, b, t, w, an, args.sargs);
      return modp_vardnsrecdegdnspolseq_removezeroes (a, an, args);
    }
  else
    {
      if (an < bn)
	{
	  modpseq_inaddmulsc (a, v, b, t, w, an, args.sargs);
	  a += an * modp_size (args.sargs);
	  b += an * modp_size (args.sargs);
	  modpseq_oomulscv (a, b, t, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  modpseq_inaddmulsc (a, v, b, t, w, bn, args.sargs);
	  a += bn * modp_size (args.sargs);
	  modpseq_innegv (a, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static int 
modp_vardnsrecdegdnspolseq_oomulscadd (modp_vardnsrecdegdnspolseq_t c, modp_vardnsrecdegdnspolseq_t a, int an, modp_t s, int v, modp_vardnsrecdegdnspolseq_t b, int bn, int w, modp_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      modpseq_oomulscadd (c, a, s, v, b, w, an, args.sargs);
      return modp_vardnsrecdegdnspolseq_removezeroes (c, an, args);
    }
  else
    {
      if (an < bn)
	{
	  modpseq_oomulscadd (c, a, s, v, b, w, an, args.sargs);
	  c += an * modp_size (args.sargs);
	  b += an * modp_size (args.sargs);
	  modpseq_oonegv (c, b, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  modpseq_oomulscadd (c, a, s, v, b, w, bn, args.sargs);
	  c += bn * modp_size (args.sargs);
	  a += bn * modp_size (args.sargs);
	  modpseq_oomulscv (c, a, s, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static int 
modp_vardnsrecdegdnspolseq_inmulscadd (modp_vardnsrecdegdnspolseq_t a, int an, modp_t s, int v, modp_vardnsrecdegdnspolseq_t b, int bn, int w, modp_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      modpseq_inmulscadd (a, s, v, b, w, an, args.sargs);
      return modp_vardnsrecdegdnspolseq_removezeroes (a, an, args);
    }
  else
    {
      if (an < bn)
	{
	  modpseq_inmulscadd (a, s, v, b, w, an, args.sargs);
	  a += an * modp_size (args.sargs);
	  b += an * modp_size (args.sargs);
	  modpseq_oonegv (a, b, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  modpseq_inmulscadd (a, s, v, b, w, bn, args.sargs);
	  a += bn * modp_size (args.sargs);
	  modpseq_inmulscv (a, s, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static int 
modp_vardnsrecdegdnspolseq_oomulscaddmulsc (modp_vardnsrecdegdnspolseq_t c, modp_vardnsrecdegdnspolseq_t a, int an, modp_t s, int v, modp_vardnsrecdegdnspolseq_t b, int bn, modp_t t, int w, modp_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      modpseq_oomulscaddmulsc (c, a, s, v, b, t, w, an, args.sargs);
      return modp_vardnsrecdegdnspolseq_removezeroes (c, an, args);
    }
  else
    {
      if (an < bn)
	{
	  modpseq_oomulscaddmulsc (c, a, s, v, b, t, w, an, args.sargs);
	  c += an * modp_size (args.sargs);
	  b += an * modp_size (args.sargs);
	  modpseq_oomulscv (c, b, t, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  modpseq_oomulscaddmulsc (c, a, s, v, b, t, w, bn, args.sargs);
	  c += bn * modp_size (args.sargs);
	  a += bn * modp_size (args.sargs);
	  modpseq_oomulscv (c, a, s, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static int 
modp_vardnsrecdegdnspolseq_inmulscaddmulsc (modp_vardnsrecdegdnspolseq_t a, int an, modp_t s, int v, modp_vardnsrecdegdnspolseq_t b, int bn, modp_t t, int w, modp_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      modpseq_inmulscaddmulsc (a, s, v, b, t, w, an, args.sargs);
      return modp_vardnsrecdegdnspolseq_removezeroes (a, an, args);
    }
  else
    {
      if (an < bn)
	{
	  modpseq_inmulscaddmulsc (a, s, v, b, t, w, an, args.sargs);
	  a += an * modp_size (args.sargs);
	  b += an * modp_size (args.sargs);
	  modpseq_oomulscv (a, b, t, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  modpseq_inmulscaddmulsc (a, s, v, b, t, w, bn, args.sargs);
	  a += bn * modp_size (args.sargs);
	  modpseq_inmulscv (a, s, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static BOOL 
modp_vardnsrecdegdnspolseq_oodivsc (modp_vardnsrecdegdnspolseq_t c, modp_vardnsrecdegdnspolseq_t a, int n, modp_t s, modp_vardnsrecdegdnspol_args args)
{
  return modpseq_oodivsc (c, a, s, n, args.sargs);
}

static int 
modp_vardnsrecdegdnspolseq_indivsc (modp_vardnsrecdegdnspolseq_t a, int n, modp_t s, modp_vardnsrecdegdnspol_args args)
{
  modpseq_indivsc (a, s, n, args.sargs);
  return n;
}

static int 
modp_vardnsrecdegdnspolseq_oomulmonomsc (modp_vardnsrecdegdnspolseq_t c, modp_vardnsrecdegdnspolseq_t a, int n, int m, modp_t s, int v, modp_vardnsrecdegdnspol_args args)
{
  modpseq_oozero (c, m, args.sargs);
  c += m * modp_size (args.sargs);
  modpseq_oomulscv (c, a, s, v, n, args.sargs);
  return n + m;
}

static BOOL 
modp_vardnsrecdegdnspolseq_oodivmonomsc (modp_vardnsrecdegdnspolseq_t c, modp_vardnsrecdegdnspolseq_t a, int n, int m, modp_t s, modp_vardnsrecdegdnspol_args args)
{
  assert (n >= m);
  a += m * modp_size (args.sargs);
  return modpseq_oodivsc (c, a, s, n - m, args.sargs);
}

static int 
modp_vardnsrecdegdnspolseq_ooaddmulmonomsc (modp_vardnsrecdegdnspolseq_t c, modp_vardnsrecdegdnspolseq_t a, int an, int v, modp_vardnsrecdegdnspolseq_t b, int bn, int m, modp_t t, int w, modp_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn + m)
    {
      assert (an >= m);
      modpseq_oonegv (c, a, v, m, args.sargs);
      c += m * modp_size (args.sargs);
      a += m * modp_size (args.sargs);
      assert (an >= bn);
      modpseq_ooaddmulsc (c, a, v, b, t, w, bn, args.sargs);
      c -= m * modp_size (args.sargs);
      return modp_vardnsrecdegdnspolseq_removezeroes (c, an, args);
    }
  else
    {
      if (an < bn + m)
	{
	  if (an < m)
	    {
	      modpseq_oonegv (c, a, v, an, args.sargs);
	      c += an * modp_size (args.sargs);
	      a += an * modp_size (args.sargs);
	      modpseq_oozero (c, m - an, args.sargs);
	      c += (m - an) * modp_size (args.sargs);
	      modpseq_oomulscv (c, b, t, w, bn, args.sargs);
	    }
	  else
	    {
	      assert (an >= m);
	      modpseq_oonegv (c, a, v, m, args.sargs);
	      c += m * modp_size (args.sargs);
	      a += m * modp_size (args.sargs);
	      assert (bn > an - m);
	      modpseq_ooaddmulsc (c, a, v, b, t, w, an - m, args.sargs);
	      c += (an - m) * modp_size (args.sargs);
	      b += (an - m) * modp_size (args.sargs);
	      modpseq_oomulscv (c, b, t, w, bn - (an - m), args.sargs);
	    }
	  return bn + m;
	}
      else
	{
	  assert (an >= m);
	  modpseq_oonegv (c, a, v, m, args.sargs);
	  c += m * modp_size (args.sargs);
	  a += m * modp_size (args.sargs);
	  assert (an >= bn);
	  modpseq_ooaddmulsc (c, a, v, b, t, w, bn, args.sargs);
	  c += bn * modp_size (args.sargs);
	  a += bn * modp_size (args.sargs);
	  assert (an > bn + m);
	  modpseq_oonegv (c, a, v, an - bn - m, args.sargs);
	  return an;
	}
    }
}

static int 
modp_vardnsrecdegdnspolseq_inaddmulmonomsc (modp_vardnsrecdegdnspolseq_t a, int an, int v, modp_vardnsrecdegdnspolseq_t b, int bn, int m, modp_t t, int w, modp_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn + m)
    {
      assert (an >= m);
      modpseq_innegv (a, v, m, args.sargs);
      a += m * modp_size (args.sargs);
      assert (an >= bn);
      modpseq_inaddmulsc (a, v, b, t, w, bn, args.sargs);
      a -= m * modp_size (args.sargs);
      return modp_vardnsrecdegdnspolseq_removezeroes (a, an, args);
    }
  else
    {
      if (an < bn + m)
	{
	  if (an < m)
	    {
	      modpseq_innegv (a, v, an, args.sargs);
	      a += an * modp_size (args.sargs);
	      modpseq_oozero (a, m - an, args.sargs);
	      a += (m - an) * modp_size (args.sargs);
	      modpseq_oomulscv (a, b, t, w, bn, args.sargs);
	    }
	  else
	    {
	      assert (an >= m);
	      modpseq_innegv (a, v, m, args.sargs);
	      a += m * modp_size (args.sargs);
	      assert (bn > an - m);
	      modpseq_inaddmulsc (a, v, b, t, w, an - m, args.sargs);
	      a += (an - m) * modp_size (args.sargs);
	      modpseq_oomulscv (a, b, t, w, bn - (an - m), args.sargs);
	    }
	  return bn + m;
	}
      else
	{
	  assert (an >= m);
	  modpseq_innegv (a, v, m, args.sargs);
	  a += m * modp_size (args.sargs);
	  assert (an >= bn);
	  modpseq_inaddmulsc (a, v, b, t, w, bn, args.sargs);
	  a += bn * modp_size (args.sargs);
	  assert (an > bn + m);
	  modpseq_innegv (a, v, an - bn - m, args.sargs);
	  return an;
	}
    }
}

static int 
modp_vardnsrecdegdnspolseq_oomulscaddmulmonomsc (modp_vardnsrecdegdnspolseq_t c, modp_vardnsrecdegdnspolseq_t a, int an, modp_t s, int v, modp_vardnsrecdegdnspolseq_t b, int bn, int m, modp_t t, int w, modp_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn + m)
    {
      assert (an >= m);
      modpseq_oomulscv (c, a, s, v, m, args.sargs);
      c += m * modp_size (args.sargs);
      a += m * modp_size (args.sargs);
      assert (an >= bn);
      modpseq_oomulscaddmulsc (c, a, s, v, b, t, w, bn, args.sargs);
      c -= m * modp_size (args.sargs);
      return modp_vardnsrecdegdnspolseq_removezeroes (c, an, args);
    }
  else
    {
      if (an < bn + m)
	{
	  if (an < m)
	    {
	      modpseq_oomulscv (c, a, s, v, an, args.sargs);
	      c += an * modp_size (args.sargs);
	      a += an * modp_size (args.sargs);
	      modpseq_oozero (c, m - an, args.sargs);
	      c += (m - an) * modp_size (args.sargs);
	      modpseq_oomulscv (c, b, t, w, bn, args.sargs);
	    }
	  else
	    {
	      assert (an >= m);
	      modpseq_oomulscv (c, a, s, v, m, args.sargs);
	      c += m * modp_size (args.sargs);
	      a += m * modp_size (args.sargs);
	      assert (bn > an - m);
	      modpseq_oomulscaddmulsc (c, a, s, v, b, t, w, an - m, args.sargs);
	      c += (an - m) * modp_size (args.sargs);
	      a += (an - m) * modp_size (args.sargs);
	      b += (an - m) * modp_size (args.sargs);
	      modpseq_oomulscv (c, b, t, w, bn - (an - m), args.sargs);
	    }
	  return bn + m;
	}
      else
	{
	  assert (an >= m);
	  modpseq_oomulscv (c, a, s, v, m, args.sargs);
	  c += m * modp_size (args.sargs);
	  a += m * modp_size (args.sargs);
	  assert (an >= bn);
	  modpseq_oomulscaddmulsc (c, a, s, v, b, t, w, bn, args.sargs);
	  c += bn * modp_size (args.sargs);
	  a += bn * modp_size (args.sargs);
	  assert (an > bn + m);
	  modpseq_oomulscv (c, a, s, v, an - bn - m, args.sargs);
	  return an;
	}
    }
}

static int 
modp_vardnsrecdegdnspolseq_inmulscaddmulmonomsc (modp_vardnsrecdegdnspolseq_t a, int an, modp_t s, int v, modp_vardnsrecdegdnspolseq_t b, int bn, int m, modp_t t, int w, modp_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn + m)
    {
      assert (an >= m);
      modpseq_inmulscv (a, s, v, m, args.sargs);
      a += m * modp_size (args.sargs);
      assert (an >= bn);
      modpseq_inmulscaddmulsc (a, s, v, b, t, w, bn, args.sargs);
      a -= m * modp_size (args.sargs);
      return modp_vardnsrecdegdnspolseq_removezeroes (a, an, args);
    }
  else
    {
      if (an < bn + m)
	{
	  if (an < m)
	    {
	      modpseq_inmulscv (a, s, v, an, args.sargs);
	      a += an * modp_size (args.sargs);
	      modpseq_oozero (a, m - an, args.sargs);
	      a += m * modp_size (args.sargs);
	      modpseq_oomulscv (a, b, t, w, bn, args.sargs);
	    }
	  else
	    {
	      assert (an >= m);
	      modpseq_inmulscv (a, s, v, m, args.sargs);
	      a += m * modp_size (args.sargs);
	      assert (bn > an - m);
	      modpseq_inmulscaddmulsc (a, s, v, b, t, w, an - m, args.sargs);
	      a += (an - m) * modp_size (args.sargs);
	      modpseq_oomulscv (a, b, t, w, bn - (an - m), args.sargs);
	    }
	  return bn + m;
	}
      else
	{
	  assert (an >= m);
	  modpseq_inmulscv (a, s, v, m, args.sargs);
	  a += m * modp_size (args.sargs);
	  assert (an >= bn);
	  modpseq_inmulscaddmulsc (a, s, v, b, t, w, bn, args.sargs);
	  a += bn * modp_size (args.sargs);
	  assert (an > bn + m);
	  modpseq_inmulscv (a, s, v, an - bn - m, args.sargs);
	  return an;
	}
    }
}

static void 
modp_vardnsrecdegdnspol_ix_init (modp_vardnsrecdegdnspol_ixt ix, id self)
{
  modp_vardnsrecdegdnspol_t v = [self modp_vardnsrecdegdnspol_value];
  ix->i = -1;
  ix->n = v->n;
}

static void 
modp_vardnsrecdegdnspol_ix_clear (modp_vardnsrecdegdnspol_ixt ix)
{
  /* nothing to clear */
}

static int 
modp_vardnsrecdegdnspol_ix_count (modp_vardnsrecdegdnspol_ixt ix)
{
  return ix->n;			/* total number, zero or nonzero */
}

static int 
modp_vardnsrecdegdnspol_ix_isempty (modp_vardnsrecdegdnspol_ixt ix)
{
  return ix->n == 0;
}

static int 
modp_vardnsrecdegdnspol_ix_ismatch (modp_vardnsrecdegdnspol_ixt ix)
{
  assert (-1 <= ix->i && ix->i <= ix->n);
  return (ix->i != -1 && ix->i != ix->n);
}

static void 
modp_vardnsrecdegdnspol_ix_tofirst (modp_vardnsrecdegdnspol_ixt ix)
{
  ix->i = -1;			/* next = first */
}

static void 
modp_vardnsrecdegdnspol_ix_tolast (modp_vardnsrecdegdnspol_ixt ix)
{
  ix->i = ix->n;		/* prev = last */
}

static void 
modp_vardnsrecdegdnspol_ix_to (modp_vardnsrecdegdnspol_ixt ix, int i)
{
  /* conversion to "n-i-1" done in elting routine... */
  if (i < 0)
    ix->i = -1;
  else if (i > ix->n)
    ix->i = ix->n;
  else
    ix->i = i - 1;		/* next -> at i */
}

static void 
modp_vardnsrecdegdnspol_ix_next (modp_vardnsrecdegdnspol_ixt ix)
{
  if (ix->i == ix->n)
    {
      /* remain on position just after last term */
    }
  else
    {
      ++(ix->i);
    }
}

static void 
modp_vardnsrecdegdnspol_ix_prev (modp_vardnsrecdegdnspol_ixt ix)
{
  if (ix->i == -1)
    {
      /* remain on position just before first term */
    }
  else
    {
      --(ix->i);
    }
}
static int 
modp_vardnsrecdegdnspol_check (modp_vardnsrecdegdnspol_t self, modp_vardnsrecdegdnspol_args args)
{
  assert (self->n <= self->c);
  return modp_vardnsrecdegdnspolseq_check (self->ptr, self->n, args);
}

static modp_vardnsrecdegdnspol_args 
modp_vardnsrecdegdnspol_getargs (id self)
{
  modp_vardnsrecdegdnspol_args res;
  res.sargs = modp_getargs ([[self termZero] coefficient]);
  return res;
}

static modp_vardnsrecdegdnspol_t 
modp_vardnsrecdegdnspol_id2t (id object)
{
  return [object modp_vardnsrecdegdnspol_value];
}

static modp_vardnsrecdegdnspol_c *
modp_vardnsrecdegdnspol_id2c (id object)
{
  return [object modp_vardnsrecdegdnspol_reference];
}

static id 
modp_vardnsrecdegdnspol_t2id (id proto, modp_vardnsrecdegdnspol_t f)
{
  return [proto modp_vardnsrecdegdnspol_value:f];
}

static id 
modp_vardnsrecdegdnspol_c2id (id proto, modp_vardnsrecdegdnspol_c * r)
{
  return [proto modp_vardnsrecdegdnspol_reference:r];
}

static int 
modp_vardnsrecdegdnspol_isempty (modp_vardnsrecdegdnspol_t self)
{
  return self->n == 0;
}

static void 
modp_vardnsrecdegdnspol_init (modp_vardnsrecdegdnspol_t self, int c, modp_vardnsrecdegdnspol_args args)
{
  self->n = 0;
  self->c = c;
  self->ptr = modpseq_alloc (c, args.sargs);
  assert (modp_vardnsrecdegdnspol_check (self, args));
}

static void 
modp_vardnsrecdegdnspol_copy (modp_vardnsrecdegdnspol_t c, modp_vardnsrecdegdnspol_t a, modp_vardnsrecdegdnspol_args args)
{
  assert (modp_vardnsrecdegdnspol_check (a, args));
  modp_vardnsrecdegdnspol_init (c, a->n, args);
  c->n = modp_vardnsrecdegdnspolseq_copy (c->ptr, a->ptr, a->n, args);
  assert (modp_vardnsrecdegdnspol_check (c, args));
}

static void 
modp_vardnsrecdegdnspol_deepcopy (modp_vardnsrecdegdnspol_t c, modp_vardnsrecdegdnspol_t a, modp_vardnsrecdegdnspol_args args)
{
  assert (modp_vardnsrecdegdnspol_check (a, args));
  modp_vardnsrecdegdnspol_init (c, a->n, args);
  c->n = modp_vardnsrecdegdnspolseq_deepcopy (c->ptr, a->ptr, a->n, args);
  assert (modp_vardnsrecdegdnspol_check (c, args));
}

static void 
modp_vardnsrecdegdnspol_move (modp_vardnsrecdegdnspol_t c, modp_vardnsrecdegdnspol_t a, modp_vardnsrecdegdnspol_args args)
{
  c->ptr = a->ptr;
  c->n = a->n;
  c->c = a->c;
  a->ptr = NULL;
  assert (modp_vardnsrecdegdnspol_check (c, args));
}

static void 
modp_vardnsrecdegdnspol_destroy (modp_vardnsrecdegdnspol_t self, modp_vardnsrecdegdnspol_args args)
{
  /* needed e.g. after a failed oodiv operation */
  self->ptr = modpseq_free (self->ptr, args.sargs);
}

static void 
modp_vardnsrecdegdnspol_clear (modp_vardnsrecdegdnspol_t self, modp_vardnsrecdegdnspol_args args)
{
  modpseq_clear (self->ptr, self->n, args.sargs);
  modp_vardnsrecdegdnspol_destroy (self, args);
}

static int 
modp_vardnsrecdegdnspol_count (modp_vardnsrecdegdnspol_t self, modp_vardnsrecdegdnspol_args args)
{
  return modp_vardnsrecdegdnspolseq_count (self->ptr, self->n, args);	/* num non-zero coefs */
}

static unsigned 
modp_vardnsrecdegdnspol_hash (modp_vardnsrecdegdnspol_t a, modp_vardnsrecdegdnspol_args args)
{
  return modp_vardnsrecdegdnspolseq_hash (a->ptr, a->n, args);
}

static int 
modp_vardnsrecdegdnspol_iseq (modp_vardnsrecdegdnspol_t a, modp_vardnsrecdegdnspol_t b, modp_vardnsrecdegdnspol_args args)
{
  return (a == b) ? YES : modp_vardnsrecdegdnspolseq_iseq (a->ptr, a->n, b->ptr, b->n, args);
}

static int 
modp_vardnsrecdegdnspol_isone (modp_vardnsrecdegdnspol_t self, modp_vardnsrecdegdnspol_args args)
{
  return modp_vardnsrecdegdnspolseq_isone (self->ptr, self->n, args);
}

static int 
modp_vardnsrecdegdnspol_isminusone (modp_vardnsrecdegdnspol_t self, modp_vardnsrecdegdnspol_args args)
{
  return modp_vardnsrecdegdnspolseq_isminusone (self->ptr, self->n, args);
}

static int 
modp_vardnsrecdegdnspol_deg (modp_vardnsrecdegdnspol_t self, modp_vardnsrecdegdnspol_args args)
{
  return self->n - 1;
}

static int 
modp_vardnsrecdegdnspol_ord (modp_vardnsrecdegdnspol_t self, modp_vardnsrecdegdnspol_args args)
{
  return modp_vardnsrecdegdnspolseq_ord (self->ptr, self->n, args);
}

static int 
modp_vardnsrecdegdnspol_maxdeg (modp_vardnsrecdegdnspol_t self, modp_vardnsrecdegdnspol_args args)
{
  return self->n - 1;
}

static int 
modp_vardnsrecdegdnspol_mindeg (modp_vardnsrecdegdnspol_t self, modp_vardnsrecdegdnspol_args args)
{
  return modp_vardnsrecdegdnspolseq_ord (self->ptr, self->n, args);
}

static modp_t 
modp_vardnsrecdegdnspol_scalat (modp_vardnsrecdegdnspol_t self, modp_vardnsrecdegdnspol_ixt ix, modp_vardnsrecdegdnspol_args args)
{
  assert (modp_vardnsrecdegdnspol_ix_ismatch (ix) && ix->n == self->n);
  return modpseq_at (self->ptr, ix->n - ix->i - 1, args.sargs);
}

static int 
modp_vardnsrecdegdnspol_expat (modp_vardnsrecdegdnspol_t self, modp_vardnsrecdegdnspol_ixt ix, modp_vardnsrecdegdnspol_args args)
{
  assert (modp_vardnsrecdegdnspol_ix_ismatch (ix) && ix->n == self->n);
  return ix->n - ix->i - 1;
}

static modp_t 
modp_vardnsrecdegdnspol_scalfirst (modp_vardnsrecdegdnspol_t self, modp_vardnsrecdegdnspol_args args)
{
  assert (modp_vardnsrecdegdnspol_isempty (self) == NO);
  return modpseq_last (self->ptr, self->n, args.sargs);
}

static int 
modp_vardnsrecdegdnspol_expfirst (modp_vardnsrecdegdnspol_t self, modp_vardnsrecdegdnspol_args args)
{
  assert (modp_vardnsrecdegdnspol_isempty (self) == NO);
  return self->n - 1;
}

static void 
modp_vardnsrecdegdnspol_expand (modp_vardnsrecdegdnspol_t self, modp_vardnsrecdegdnspol_args args)
{
  int oldc = self->c;
  self->c = self->n + self->c + 1;
  self->ptr = modpseq_realloc (self->ptr, oldc, self->c, args.sargs);
  assert (self->n < self->c);
}

static void 
modp_vardnsrecdegdnspol_remove (modp_vardnsrecdegdnspol_t self, modp_vardnsrecdegdnspol_args args)
{
  assert (modp_vardnsrecdegdnspol_check (self, args) && modp_vardnsrecdegdnspol_isempty (self) == NO);
  self->n = modp_vardnsrecdegdnspolseq_delete (self->ptr, self->n, args);
  assert (modp_vardnsrecdegdnspol_check (self, args));
}

static void 
modp_vardnsrecdegdnspol_insert (modp_vardnsrecdegdnspol_t self, int e, modp_t s, modp_vardnsrecdegdnspol_args args)
{
  assert (modp_vardnsrecdegdnspol_check (self, args));
  while (self->c < e + 1)
    modp_vardnsrecdegdnspol_expand (self, args);
  self->n = modp_vardnsrecdegdnspolseq_insert (self->ptr, self->n, e, s, args);
  assert (modp_vardnsrecdegdnspol_check (self, args));
}

static int 
modp_vardnsrecdegdnspol_iszero (modp_vardnsrecdegdnspol_t self, modp_vardnsrecdegdnspol_args args)
{
  return modp_vardnsrecdegdnspol_isempty (self);
}

static int 
modp_vardnsrecdegdnspol_isop (modp_vardnsrecdegdnspol_t a, modp_vardnsrecdegdnspol_t b, modp_vardnsrecdegdnspol_args args)
{
  assert (a != b);
  return modp_vardnsrecdegdnspolseq_isop (a->ptr, a->n, b->ptr, b->n, args);
}

static void 
modp_vardnsrecdegdnspol_ooneg (modp_vardnsrecdegdnspol_t c, modp_vardnsrecdegdnspol_t a, modp_vardnsrecdegdnspol_args args)
{
  modp_vardnsrecdegdnspol_init (c, a->n, args);
  c->n = modp_vardnsrecdegdnspolseq_ooneg (c->ptr, a->ptr, a->n, args);
  assert (modp_vardnsrecdegdnspol_check (c, args));
}

static void 
modp_vardnsrecdegdnspol_inneg (modp_vardnsrecdegdnspol_t a, modp_vardnsrecdegdnspol_args args)
{
  a->n = modp_vardnsrecdegdnspolseq_inneg (a->ptr, a->n, args);
  assert (modp_vardnsrecdegdnspol_check (a, args));
}

static void 
modp_vardnsrecdegdnspol_oodbl (modp_vardnsrecdegdnspol_t c, modp_vardnsrecdegdnspol_t a, int v, modp_vardnsrecdegdnspol_args args)
{
  modp_vardnsrecdegdnspol_init (c, a->n, args);
  c->n = modp_vardnsrecdegdnspolseq_oodbl (c->ptr, a->ptr, a->n, v, args);
  assert (modp_vardnsrecdegdnspol_check (c, args));
}

static void 
modp_vardnsrecdegdnspol_indbl (modp_vardnsrecdegdnspol_t a, int v, modp_vardnsrecdegdnspol_args args)
{
  modp_vardnsrecdegdnspolseq_indbl (a->ptr, a->n, v, args);
  assert (modp_vardnsrecdegdnspol_check (a, args));
}

static void 
modp_vardnsrecdegdnspol_ooadd (modp_vardnsrecdegdnspol_t c, modp_vardnsrecdegdnspol_t a, int v, modp_vardnsrecdegdnspol_t b, int w, modp_vardnsrecdegdnspol_args args)
{
  assert (a != b);
  modp_vardnsrecdegdnspol_init (c, MAX (a->n, b->n), args);
  c->n = modp_vardnsrecdegdnspolseq_ooadd (c->ptr, a->ptr, a->n, v, b->ptr, b->n, w, args);
  assert (modp_vardnsrecdegdnspol_check (c, args));
}

static void 
modp_vardnsrecdegdnspol_inadd (modp_vardnsrecdegdnspol_t a, int v, modp_vardnsrecdegdnspol_t b, int w, modp_vardnsrecdegdnspol_args args)
{
  assert (a != b);
  while (a->c < b->n)
    modp_vardnsrecdegdnspol_expand (a, args);
  a->n = modp_vardnsrecdegdnspolseq_inadd (a->ptr, a->n, v, b->ptr, b->n, w, args);
  assert (modp_vardnsrecdegdnspol_check (a, args));
}

static void 
modp_vardnsrecdegdnspol_oomulsc (modp_vardnsrecdegdnspol_t c, modp_vardnsrecdegdnspol_t a, modp_t s, modp_vardnsrecdegdnspol_args args)
{
  modp_vardnsrecdegdnspol_init (c, a->n, args);
  c->n = modp_vardnsrecdegdnspolseq_oomulsc (c->ptr, a->ptr, a->n, s, args);
  assert (modp_vardnsrecdegdnspol_check (c, args));
}

static void 
modp_vardnsrecdegdnspol_inmulsc (modp_vardnsrecdegdnspol_t a, modp_t s, modp_vardnsrecdegdnspol_args args)
{
  a->n = modp_vardnsrecdegdnspolseq_inmulsc (a->ptr, a->n, s, args);
  assert (modp_vardnsrecdegdnspol_check (a, args));
}

static void 
modp_vardnsrecdegdnspol_ooaddmulsc (modp_vardnsrecdegdnspol_t c, modp_vardnsrecdegdnspol_t a, int v, modp_vardnsrecdegdnspol_t b, modp_t t, int w, modp_vardnsrecdegdnspol_args args)
{
  modp_vardnsrecdegdnspol_init (c, MAX (a->n, b->n), args);
  c->n = modp_vardnsrecdegdnspolseq_ooaddmulsc (c->ptr, a->ptr, a->n, v, b->ptr, b->n, t, w, args);
  assert (modp_vardnsrecdegdnspol_check (c, args));
}

static void 
modp_vardnsrecdegdnspol_inaddmulsc (modp_vardnsrecdegdnspol_t a, int v, modp_vardnsrecdegdnspol_t b, modp_t t, int w, modp_vardnsrecdegdnspol_args args)
{
  while (a->c < b->n)
    modp_vardnsrecdegdnspol_expand (a, args);
  a->n = modp_vardnsrecdegdnspolseq_inaddmulsc (a->ptr, a->n, v, b->ptr, b->n, t, w, args);
  assert (modp_vardnsrecdegdnspol_check (a, args));
}

static void 
modp_vardnsrecdegdnspol_oomulscadd (modp_vardnsrecdegdnspol_t c, modp_vardnsrecdegdnspol_t a, modp_t s, int v, modp_vardnsrecdegdnspol_t b, int w, modp_vardnsrecdegdnspol_args args)
{
  modp_vardnsrecdegdnspol_init (c, MAX (a->n, b->n), args);
  c->n = modp_vardnsrecdegdnspolseq_oomulscadd (c->ptr, a->ptr, a->n, s, v, b->ptr, b->n, w, args);
  assert (modp_vardnsrecdegdnspol_check (c, args));
}

static void 
modp_vardnsrecdegdnspol_inmulscadd (modp_vardnsrecdegdnspol_t a, modp_t s, int v, modp_vardnsrecdegdnspol_t b, int w, modp_vardnsrecdegdnspol_args args)
{
  while (a->c < b->n)
    modp_vardnsrecdegdnspol_expand (a, args);
  a->n = modp_vardnsrecdegdnspolseq_inmulscadd (a->ptr, a->n, s, v, b->ptr, b->n, w, args);
  assert (modp_vardnsrecdegdnspol_check (a, args));
}

static void 
modp_vardnsrecdegdnspol_oomulscaddmulsc (modp_vardnsrecdegdnspol_t c, modp_vardnsrecdegdnspol_t a, modp_t s, int v, modp_vardnsrecdegdnspol_t b, modp_t t, int w, modp_vardnsrecdegdnspol_args args)
{
  modp_vardnsrecdegdnspol_init (c, MAX (a->n, b->n), args);
  c->n = modp_vardnsrecdegdnspolseq_oomulscaddmulsc (c->ptr, a->ptr, a->n, s, v, b->ptr, b->n, t, w, args);
  assert (modp_vardnsrecdegdnspol_check (c, args));
}

static void 
modp_vardnsrecdegdnspol_inmulscaddmulsc (modp_vardnsrecdegdnspol_t a, modp_t s, int v, modp_vardnsrecdegdnspol_t b, modp_t t, int w, modp_vardnsrecdegdnspol_args args)
{
  while (a->c < b->n)
    modp_vardnsrecdegdnspol_expand (a, args);
  a->n = modp_vardnsrecdegdnspolseq_inmulscaddmulsc (a->ptr, a->n, s, v, b->ptr, b->n, t, w, args);
  assert (modp_vardnsrecdegdnspol_check (a, args));
}

static BOOL 
modp_vardnsrecdegdnspol_oodivsc (modp_vardnsrecdegdnspol_t c, modp_vardnsrecdegdnspol_t a, modp_t s, modp_vardnsrecdegdnspol_args args)
{
  BOOL failed;
  modp_vardnsrecdegdnspol_init (c, a->n, args);
  failed = modp_vardnsrecdegdnspolseq_oodivsc (c->ptr, a->ptr, a->n, s, args);
  if (failed)
    {
      /* the actual scalars are already freed */
      modp_vardnsrecdegdnspol_destroy (c, args);
    }
  else
    {
      c->n = a->n;
      assert (modp_vardnsrecdegdnspol_check (c, args));
    }
  return failed;
}

static void 
modp_vardnsrecdegdnspol_indivsc (modp_vardnsrecdegdnspol_t a, modp_t s, modp_vardnsrecdegdnspol_args args)
{
  a->n = modp_vardnsrecdegdnspolseq_indivsc (a->ptr, a->n, s, args);
  assert (modp_vardnsrecdegdnspol_check (a, args));
}

static void 
modp_vardnsrecdegdnspol_oomulmonomsc (modp_vardnsrecdegdnspol_t c, modp_vardnsrecdegdnspol_t b, unimonom_t m, modp_t t, int w, modp_vardnsrecdegdnspol_args args)
{
  modp_vardnsrecdegdnspol_init (c, b->n + m, args);
  c->n = modp_vardnsrecdegdnspolseq_oomulmonomsc (c->ptr, b->ptr, b->n, m, t, w, args);
  assert (modp_vardnsrecdegdnspol_check (c, args));
}

static void 
modp_vardnsrecdegdnspol_inmulmonomsc (modp_vardnsrecdegdnspol_t b, unimonom_t m, modp_t t, int w, modp_vardnsrecdegdnspol_args args)
{
  modp_vardnsrecdegdnspol_c tmp;
  modp_vardnsrecdegdnspol_oomulmonomsc (&tmp, b, m, t, w, args);
  modp_vardnsrecdegdnspol_clear (b, args);
  modp_vardnsrecdegdnspol_move (b, &tmp, args);
}

static void 
modp_vardnsrecdegdnspol_ooaddmulmonomsc (modp_vardnsrecdegdnspol_t c, modp_vardnsrecdegdnspol_t a, int v, modp_vardnsrecdegdnspol_t b, unimonom_t m, modp_t t, int w, modp_vardnsrecdegdnspol_args args)
{
  modp_vardnsrecdegdnspol_init (c, MAX (a->n, b->n + m), args);
  c->n = modp_vardnsrecdegdnspolseq_ooaddmulmonomsc (c->ptr, a->ptr, a->n, v, b->ptr, b->n, m, t, w, args);
  assert (modp_vardnsrecdegdnspol_check (c, args));
}

static void 
modp_vardnsrecdegdnspol_inaddmulmonomsc (modp_vardnsrecdegdnspol_t a, int v, modp_vardnsrecdegdnspol_t b, unimonom_t m, modp_t t, int w, modp_vardnsrecdegdnspol_args args)
{
  while (a->c < b->n + m)
    modp_vardnsrecdegdnspol_expand (a, args);
  a->n = modp_vardnsrecdegdnspolseq_inaddmulmonomsc (a->ptr, a->n, v, b->ptr, b->n, m, t, w, args);
  assert (modp_vardnsrecdegdnspol_check (a, args));
}

static void 
modp_vardnsrecdegdnspol_oomulscaddmulmonomsc (modp_vardnsrecdegdnspol_t c, modp_vardnsrecdegdnspol_t a, modp_t s, int v, modp_vardnsrecdegdnspol_t b, unimonom_t m, modp_t t, int w, modp_vardnsrecdegdnspol_args args)
{
  modp_vardnsrecdegdnspol_init (c, MAX (a->n, b->n + m), args);
  c->n = modp_vardnsrecdegdnspolseq_oomulscaddmulmonomsc (c->ptr, a->ptr, a->n, s, v, b->ptr, b->n, m, t, w, args);
  assert (modp_vardnsrecdegdnspol_check (c, args));
}

static void 
modp_vardnsrecdegdnspol_inmulscaddmulmonomsc (modp_vardnsrecdegdnspol_t a, modp_t s, int v, modp_vardnsrecdegdnspol_t b, unimonom_t m, modp_t t, int w, modp_vardnsrecdegdnspol_args args)
{
  a->n = modp_vardnsrecdegdnspolseq_inmulscaddmulmonomsc (a->ptr, a->n, s, v, b->ptr, b->n, m, t, w, args);
  assert (modp_vardnsrecdegdnspol_check (a, args));
}

static BOOL 
modp_vardnsrecdegdnspol_oodivmonomsc (modp_vardnsrecdegdnspol_t c, modp_vardnsrecdegdnspol_t b, unimonom_t m, modp_t t, modp_vardnsrecdegdnspol_args args)
{
  if (modp_vardnsrecdegdnspol_ord (b, args) < m)
    {
      return FAILURE;
    }
  else
    {
      BOOL failed;
      modp_vardnsrecdegdnspol_init (c, b->n - m, args);
      failed = modp_vardnsrecdegdnspolseq_oodivmonomsc (c->ptr, b->ptr, b->n, m, t, args);
      if (failed)
	{
	  /* the actual scalars are already freed */
	  modp_vardnsrecdegdnspol_destroy (c, args);
	}
      else
	{
	  c->n = b->n - m;
	  assert (modp_vardnsrecdegdnspol_check (c, args));
	}
      return failed;
    }
}

static void 
modp_vardnsrecdegdnspol_indivmonomsc (modp_vardnsrecdegdnspol_t b, unimonom_t m, modp_t t, modp_vardnsrecdegdnspol_args args)
{
  modp_vardnsrecdegdnspol_c tmp;
  BOOL failed = modp_vardnsrecdegdnspol_oodivmonomsc (&tmp, b, m, t, args);
  if (failed)
    {
      fprintf (stderr, "Exact Division Failed");
      abort ();
    }
  modp_vardnsrecdegdnspol_clear (b, args);
  modp_vardnsrecdegdnspol_move (b, &tmp, args);
}

static void 
modp_vardnsrecdegdnspol_args_fileOut (id aFiler, modp_vardnsrecdegdnspol_args * args)
{
  modpseq_args_fileOut (aFiler, &args->sargs);
}
static void 
modp_vardnsrecdegdnspol_args_fileIn (id aFiler, modp_vardnsrecdegdnspol_args * args)
{
  modpseq_args_fileIn (aFiler, &args->sargs);
}

static void 
modp_vardnsrecdegdnspol_fileOut (id aFiler, modp_vardnsrecdegdnspol_t self, modp_vardnsrecdegdnspol_args args)
{
  int n = self->n;
  [aFiler fileOut:&n type:'i'];
  assert (modp_vardnsrecdegdnspol_check (self, args));
  modpseq_fileOut (aFiler, self->ptr, n, args.sargs);
}

static void 
modp_vardnsrecdegdnspol_fileIn (id aFiler, modp_vardnsrecdegdnspol_t self, modp_vardnsrecdegdnspol_args args)
{
  int n;
  [aFiler fileIn:&n type:'i'];
  modp_vardnsrecdegdnspol_init (self, n, args);
  modpseq_fileIn (aFiler, self->ptr, n, args.sargs);
  self->n = n;
  assert (self->n == n && modp_vardnsrecdegdnspol_check (self, args));
}

@implementation modp_vardnsrecdegdns_polynomial : vardnsrecdegdns_polynomial

- _setUpScalarZero:aScalar coefficientZero:aCoef symbols:aCltn
{
  id aSymbol;

  assert ([aCoef isZero] && [aScalar isZero]);
  assert ([aCoef class_vardnsrecdegdns_polynomial] == [self class]);

  aSymbol = [aCltn lastElement];
  termZero = [Term scalarZero:aScalar coefficient:aCoef symbol:aSymbol exponent:1];
  monomialZero = [Monomial scalar:aScalar symbols:aCltn];
  scalarZero = aScalar;
  symbols = aCltn;

  modp_vardnsrecdegdnspol_init (&value, 2 /* capacity */ , modp_vardnsrecdegdnspol_getargs (self));
  assert ([self check]);
  return self;
}

+ scalarZero:aScalar coefficientZero:aCoef symbols:aCltn
{
  return [[super new] _setUpScalarZero:aScalar coefficientZero:aCoef symbols:aCltn];
}

- empty
{
  modp_vardnsrecdegdnspol_c c;
  assert ([self check]);
  modp_vardnsrecdegdnspol_init (&c, 2 /* capacity */ , modp_vardnsrecdegdnspol_getargs (self));
  return modp_vardnsrecdegdnspol_c2id (self, &c);
}

- (int) numTerms
{
  /* doesn't take getargs in degsps case */
  assert ([self check]);
  return modp_vardnsrecdegdnspol_count (&value, modp_vardnsrecdegdnspol_getargs (self));
}

- (modp_vardnsrecdegdnspol_t)modp_vardnsrecdegdnspol_value
{
  return &value;
}

- domodp_vardnsrecdegdnspol_value:(modp_vardnsrecdegdnspol_t)aValue
{
  modp_vardnsrecdegdnspol_copy (&value, aValue, modp_vardnsrecdegdnspol_getargs (self));
  assert ([self check]);
  return self;
}

- modp_vardnsrecdegdnspol_value:(modp_vardnsrecdegdnspol_t)aValue
{
  return [[self clone] domodp_vardnsrecdegdnspol_value:aValue];
}

- (modp_vardnsrecdegdnspol_t)modp_vardnsrecdegdnspol_reference
{
  return &value;
}

- domodp_vardnsrecdegdnspol_reference:(modp_vardnsrecdegdnspol_c *)aReference
{
  modp_vardnsrecdegdnspol_move (&value, aReference, modp_vardnsrecdegdnspol_getargs (self));
  assert ([self check]);
  return self;
}

- modp_vardnsrecdegdnspol_reference:(modp_vardnsrecdegdnspol_c *)aReference
{
  return [[self clone] domodp_vardnsrecdegdnspol_reference:aReference];
}

- copy
{
  modp_vardnsrecdegdnspol_c c;
  assert ([self check]);
  modp_vardnsrecdegdnspol_copy (&c, &value, modp_vardnsrecdegdnspol_getargs (self));
  return modp_vardnsrecdegdnspol_c2id (self, &c);
}

- deepCopy
{
  modp_vardnsrecdegdnspol_c c;
  assert ([self check]);
  modp_vardnsrecdegdnspol_deepcopy (&c, &value, modp_vardnsrecdegdnspol_getargs (self));
  return modp_vardnsrecdegdnspol_c2id (self, &c);
}

- (BOOL) isEmpty
{
  return modp_vardnsrecdegdnspol_isempty (&value);
}

- (BOOL) isOne
{
  return modp_vardnsrecdegdnspol_isone (&value, modp_vardnsrecdegdnspol_getargs (self));
}

- (BOOL) isMinusOne
{
  return modp_vardnsrecdegdnspol_isminusone (&value, modp_vardnsrecdegdnspol_getargs (self));
}

- (unsigned) hash
{
  return modp_vardnsrecdegdnspol_hash (modp_vardnsrecdegdnspol_id2t (self), modp_vardnsrecdegdnspol_getargs (self));
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
      return modp_vardnsrecdegdnspol_iseq (modp_vardnsrecdegdnspol_id2t (self), modp_vardnsrecdegdnspol_id2t (b), modp_vardnsrecdegdnspol_getargs (self));
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
      return !modp_vardnsrecdegdnspol_iseq (modp_vardnsrecdegdnspol_id2t (self), modp_vardnsrecdegdnspol_id2t (b), modp_vardnsrecdegdnspol_getargs (self));
    }
}

- (BOOL) isZero
{
  assert ([self check]);
  return modp_vardnsrecdegdnspol_iszero (modp_vardnsrecdegdnspol_id2t (self), modp_vardnsrecdegdnspol_getargs (self));
}

- (BOOL) notZero
{
  assert ([self check]);
  return !modp_vardnsrecdegdnspol_iszero (modp_vardnsrecdegdnspol_id2t (self), modp_vardnsrecdegdnspol_getargs (self));
}

- (BOOL) isOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return modp_vardnsrecdegdnspol_isop (modp_vardnsrecdegdnspol_id2t (self), modp_vardnsrecdegdnspol_id2t (b), modp_vardnsrecdegdnspol_getargs (self));
}

- (BOOL) notOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return !modp_vardnsrecdegdnspol_isop (modp_vardnsrecdegdnspol_id2t (self), modp_vardnsrecdegdnspol_id2t (b), modp_vardnsrecdegdnspol_getargs (self));
}

- negate
{
  modp_vardnsrecdegdnspol_c c;
  assert ([self check]);
  modp_vardnsrecdegdnspol_ooneg (&c, modp_vardnsrecdegdnspol_id2t (self), modp_vardnsrecdegdnspol_getargs (self));
  return modp_vardnsrecdegdnspol_c2id (self, &c);
}

- _double:(int)v
{
  modp_vardnsrecdegdnspol_c c;
  assert ([self check]);
  modp_vardnsrecdegdnspol_oodbl (&c, modp_vardnsrecdegdnspol_id2t (self), v, modp_vardnsrecdegdnspol_getargs (self));
  return modp_vardnsrecdegdnspol_c2id (self, &c);
}

- double
{
  modp_vardnsrecdegdnspol_c c;
  assert ([self check]);
  modp_vardnsrecdegdnspol_oodbl (&c, modp_vardnsrecdegdnspol_id2t (self), +1, modp_vardnsrecdegdnspol_getargs (self));
  return modp_vardnsrecdegdnspol_c2id (self, &c);
}

- _add:(int)v:b:(int)w
{
  modp_vardnsrecdegdnspol_c c;
  assert ([self sameClass:b] && v * v == 1 && w * w == 1 && self != b);
  modp_vardnsrecdegdnspol_ooadd (&c, modp_vardnsrecdegdnspol_id2t (self), v, modp_vardnsrecdegdnspol_id2t (b), w, modp_vardnsrecdegdnspol_getargs (self));
  return modp_vardnsrecdegdnspol_c2id (self, &c);
}

- add:b
{
  modp_vardnsrecdegdnspol_c c;
  assert ([self checkSameClass:b] && self != b);
  modp_vardnsrecdegdnspol_ooadd (&c, modp_vardnsrecdegdnspol_id2t (self), +1, modp_vardnsrecdegdnspol_id2t (b), +1, modp_vardnsrecdegdnspol_getargs (self));
  return modp_vardnsrecdegdnspol_c2id (self, &c);
}

- subtract:b
{
  modp_vardnsrecdegdnspol_c c;
  assert ([self checkSameClass:b] && self != b);
  modp_vardnsrecdegdnspol_ooadd (&c, modp_vardnsrecdegdnspol_id2t (self), +1, modp_vardnsrecdegdnspol_id2t (b), -1, modp_vardnsrecdegdnspol_getargs (self));
  return modp_vardnsrecdegdnspol_c2id (self, &c);
}

- (int) leadingDegree
{
  return modp_vardnsrecdegdnspol_deg (&value, modp_vardnsrecdegdnspol_getargs (self));
}

- (int) lastDegree
{
  return modp_vardnsrecdegdnspol_ord (&value, modp_vardnsrecdegdnspol_getargs (self));
}

- (int) maxDegree
{
  return modp_vardnsrecdegdnspol_maxdeg (&value, modp_vardnsrecdegdnspol_getargs (self));
}

- (int) minDegree
{
  return modp_vardnsrecdegdnspol_mindeg (&value, modp_vardnsrecdegdnspol_getargs (self));
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

  modp_vardnsrecdegdnspol_check (&value, modp_vardnsrecdegdnspol_getargs (self));
  return self;
}

- release
{
  modp_vardnsrecdegdnspol_clear (&value, modp_vardnsrecdegdnspol_getargs (self));
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
  id aSequence = [modp_vardnsrecdegdnspol_sequence content:self];
  return [CASequence over:aSequence];
}

- elt_modp_vardnsrecdegdnspol_ix:(modp_vardnsrecdegdnspol_ixt)ix
{
  if (modp_vardnsrecdegdnspol_ix_ismatch (ix))
    {
      id c, s;
      int e;
      modp_t t;
      t = modp_vardnsrecdegdnspol_scalat (&value, ix, modp_vardnsrecdegdnspol_getargs (self));
      e = modp_vardnsrecdegdnspol_expat (&value, ix, modp_vardnsrecdegdnspol_getargs (self));
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

      t = modp_vardnsrecdegdnspol_scalfirst (&value, modp_vardnsrecdegdnspol_getargs (self));
      e = modp_vardnsrecdegdnspol_expfirst (&value, modp_vardnsrecdegdnspol_getargs (self));
      c = modp_t2id ([termZero coefficient], t);
      s = (e) ? [termZero symbol] : nil;
      lt = [termZero coefficient:c symbol:s exponent:e];

      modp_vardnsrecdegdnspol_remove (&value, modp_vardnsrecdegdnspol_getargs (self));
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
      modp_vardnsrecdegdnspol_insert (&value, e, r, modp_vardnsrecdegdnspol_getargs (self));
      assert ([aTerm check]);
      [self invalidate];
      assert ([self check]);
      return self;
    }
}

- multiplyCoefficient:s
{
  modp_vardnsrecdegdnspol_c c;
  modp_c sc;
  modp_vardnsrecdegdnspol_oomulsc (&c, modp_vardnsrecdegdnspol_id2t (self), modp_id2ref (s, &sc), modp_vardnsrecdegdnspol_getargs (self));
  return modp_vardnsrecdegdnspol_c2id (self, &c);
}

- divideCoefficient:s
{
  modp_vardnsrecdegdnspol_c c;
  modp_c sc;
  BOOL failed = modp_vardnsrecdegdnspol_oodivsc (&c, modp_vardnsrecdegdnspol_id2t (self), modp_id2ref (s, &sc), modp_vardnsrecdegdnspol_getargs (self));
  return (failed) ? nil : modp_vardnsrecdegdnspol_c2id (self, &c);
}

- _add:(int)v:B multiplyCoefficient:b:(int)w
{
  modp_vardnsrecdegdnspol_c c;
  modp_c bc;
  modp_vardnsrecdegdnspol_ooaddmulsc (&c, modp_vardnsrecdegdnspol_id2t (self), v, modp_vardnsrecdegdnspol_id2t (B), modp_id2ref (b, &bc), w, modp_vardnsrecdegdnspol_getargs (self));
  return modp_vardnsrecdegdnspol_c2id (self, &c);
}

- _multiplyCoefficient:a:(int)v add:B:(int)w
{
  modp_vardnsrecdegdnspol_c c;
  modp_c ac;
  modp_vardnsrecdegdnspol_oomulscadd (&c, modp_vardnsrecdegdnspol_id2t (self), modp_id2ref (a, &ac), v, modp_vardnsrecdegdnspol_id2t (B), w, modp_vardnsrecdegdnspol_getargs (self));
  return modp_vardnsrecdegdnspol_c2id (self, &c);
}

- _multiplyCoefficient:a:(int)v add:B multiplyCoefficient:b:(int)w
{
  modp_vardnsrecdegdnspol_c c;
  modp_c ac, bc;
  modp_vardnsrecdegdnspol_oomulscaddmulsc (&c, modp_vardnsrecdegdnspol_id2t (self), modp_id2ref (a, &ac), v, modp_vardnsrecdegdnspol_id2t (B), modp_id2ref (b, &bc), w, modp_vardnsrecdegdnspol_getargs (self));
  return modp_vardnsrecdegdnspol_c2id (self, &c);
}

- multiplyTerm:aTerm
{
  modp_vardnsrecdegdnspol_c c;
  modp_t s;
  modp_c sc;
  s = modp_id2ref ([aTerm coefficient], &sc);
  modp_vardnsrecdegdnspol_oomulmonomsc (&c, modp_vardnsrecdegdnspol_id2t (self), [aTerm exponent], s, +1, modp_vardnsrecdegdnspol_getargs (self));
  return modp_vardnsrecdegdnspol_c2id (self, &c);
}

- _multiplyTerm:aTerm:(int)v
{
  modp_vardnsrecdegdnspol_c c;
  modp_t s;
  modp_c sc;
  s = modp_id2ref ([aTerm coefficient], &sc);
  modp_vardnsrecdegdnspol_oomulmonomsc (&c, modp_vardnsrecdegdnspol_id2t (self), [aTerm exponent], s, v, modp_vardnsrecdegdnspol_getargs (self));
  return modp_vardnsrecdegdnspol_c2id (self, &c);
}

- divideTerm:aTerm
{
  int e;
  modp_vardnsrecdegdnspol_c c;
  BOOL failed;
  modp_t s;
  modp_c sc;

  e = [aTerm exponent];
  s = modp_id2ref ([aTerm coefficient], &sc);
  failed = modp_vardnsrecdegdnspol_oodivmonomsc (&c, modp_vardnsrecdegdnspol_id2t (self), e, s, modp_vardnsrecdegdnspol_getargs (self));
  return (failed) ? nil : modp_vardnsrecdegdnspol_c2id (self, &c);
}

- _add:(int)v:B multiplyTerm:b:(int)w
{
  modp_vardnsrecdegdnspol_c c;
  modp_c bc;
  modp_t bs;
  bs = modp_id2ref ([b coefficient], &bc);
  modp_vardnsrecdegdnspol_ooaddmulmonomsc (&c, modp_vardnsrecdegdnspol_id2c (self), v, modp_vardnsrecdegdnspol_id2t (B), [b exponent], bs, w, modp_vardnsrecdegdnspol_getargs (self));
  return modp_vardnsrecdegdnspol_c2id (self, &c);
}

- _multiplyCoefficient:a:(int)v add:B multiplyTerm:b:(int)w
{
  modp_vardnsrecdegdnspol_c c;
  modp_c ac, bc;
  modp_t as, bs;
  as = modp_id2ref (a, &ac);
  bs = modp_id2ref ([b coefficient], &bc);
  modp_vardnsrecdegdnspol_oomulscaddmulmonomsc (&c, modp_vardnsrecdegdnspol_id2c (self), as, v, modp_vardnsrecdegdnspol_id2t (B), [b exponent], bs, w, modp_vardnsrecdegdnspol_getargs (self));
  return modp_vardnsrecdegdnspol_c2id (self, &c);
}


- fileOutOn:aFiler
{
  modp_vardnsrecdegdnspol_args args;
  [super fileOutOn:aFiler];
  args = modp_vardnsrecdegdnspol_getargs (self);	/* can't do this in fileIn case */
  modp_vardnsrecdegdnspol_args_fileOut (aFiler, &args);
  modp_vardnsrecdegdnspol_fileOut (aFiler, &value, args);
  return self;
}

- fileInFrom:aFiler
{
  modp_vardnsrecdegdnspol_args args;
  [super fileInFrom:aFiler];
  modp_vardnsrecdegdnspol_args_fileIn (aFiler, &args);
  modp_vardnsrecdegdnspol_fileIn (aFiler, &value, args);
  return self;
}

@end
 
