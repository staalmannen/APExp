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
 * $Id: mvectorc.m,v 1.6 2000/10/12 14:40:26 stes Exp $
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

static modpvec_args 
modpvec_getargs (id self)
{
  modpvec_args args;
  args.sargs = modp_getargs ([self scalarZero]);
  return args;
}

static int 
modpvec_check (modpvec_t self, modpvec_args args)
{
  assert (0 <= self->n && self->n <= self->c);
  modpseq_check (self->ptr, self->n, args.sargs);
  return 1;
}

static modpvec_t 
modpvec_id2t (id object)
{
  return [object modpvec_value];
}

static modpvec_c *
modpvec_id2c (id object)
{
  return [object modpvec_reference];
}

static id 
modpvec_t2id (id proto, modpvec_t f)
{
  return [proto modpvec_value:f];
}

static id 
modpvec_c2id (id proto, modpvec_c * r)
{
  return [proto modpvec_reference:r];
}

static void 
modpvec_init (modpvec_t self, int n, modpvec_args args)
{
  self->n = n;
  self->c = n;
  self->ptr = modpseq_alloc (n, args.sargs);
}

static void 
modpvec_initcount (modpvec_t c, int n, modpvec_args args)
{
  modpvec_init (c, n, args);
  modpseq_oozero (c->ptr, n, args.sargs);
}

static void 
modpvec_initcapacity (modpvec_t self, int n, modpvec_args args)
{
  self->n = 0;
  self->c = n;
  self->ptr = modpseq_alloc (n, args.sargs);
}

static void 
modpvec_copy (modpvec_t c, modpvec_t a, modpvec_args args)
{
  modpvec_init (c, a->n, args);
  modpseq_copy (c->ptr, a->ptr, a->n, args.sargs);
}

static void 
modpvec_deepcopy (modpvec_t c, modpvec_t a, modpvec_args args)
{
  modpvec_init (c, a->n, args);
  modpseq_deepcopy (c->ptr, a->ptr, a->n, args.sargs);
}

static void 
modpvec_move (modpvec_t c, modpvec_t a, modpvec_args args)
{
  c->n = a->n;
  c->c = a->c;
  c->ptr = a->ptr;
  a->ptr = NULL;
}

static void 
modpvec_destroy (modpvec_t self, modpvec_args args)
{
  /*
   * clearing memory allocated by modpvec_init after a failed operation
   * can't do a modpseq_clear in that case as the handler doesnt know
   * what elements have been allocated
   */

  self->ptr = modpseq_free (self->ptr, args.sargs);
}

static void 
modpvec_clear (modpvec_t self, modpvec_args args)
{
  modpseq_clear (self->ptr, self->n, args.sargs);
  modpvec_destroy (self, args);
}

static int 
modpvec_count (modpvec_t self)
{
  return self->n;
}

static unsigned 
modpvec_hash (modpvec_t a, modpvec_args args)
{
  return modpseq_hash (a->ptr, a->n, args.sargs);
}

static int 
modpvec_iseq (modpvec_t a, modpvec_t b, modpvec_args args)
{
  assert (a != b);
  return (a->n == b->n && modpseq_iseq (a->ptr, b->ptr, a->n, args.sargs));
}

static void 
modpvec_expand (modpvec_t self, modpvec_args args)
{
  int oldc = self->c;
  assert (self->n == self->c);
  self->c = self->n + self->c + 1;
  self->ptr = modpseq_realloc (self->ptr, oldc, self->c, args.sargs);
  assert (self->n < self->c);
}

static void 
modpvec_insertfirst (modpvec_t self, modp_t a, modpvec_args args)
{
  assert (self->n <= self->c);
  if (self->n == self->c)
    modpvec_expand (self, args);
  self->n = modpseq_insertlast (self->ptr, a, self->n, args.sargs);
}

static void 
modpvec_insertat (modpvec_t self, modp_t a, int i, modpvec_args args)
{
  assert (0 < i && i <= self->n && self->n <= self->c);
  if (self->n == self->c)
    modpvec_expand (self, args);

  if (i == self->n)
    {
      self->n = modpseq_insertfirst (self->ptr, a, self->n, args.sargs);
    }
  else
    {
      self->n = modpseq_insertat (self->ptr, a, self->n - i - 1, self->n, args.sargs);
    }
}

static void 
modpvec_place (modpvec_t self, modp_t a, int i, modpvec_args args)
{
  assert (0 <= i && i < self->n);
  modpseq_place (self->ptr, a, self->n - i - 1, args.sargs);
}

static void 
modpvec_freefirst (modpvec_t self, modpvec_args args)
{
  assert (self->n > 0);
  self->n = modpseq_freelast (self->ptr, self->n, args.sargs);
}

static void 
modpvec_freeat (modpvec_t self, int i, modpvec_args args)
{
  assert (0 < i && i < self->n);
  self->n = modpseq_freeat (self->ptr, self->n - i - 1, self->n, args.sargs);
}


static modp_t 
modpvec_at (modpvec_t self, int ix, modpvec_args args)
{
  assert (0 <= ix && ix < self->n);
  return modpseq_at (self->ptr, self->n - ix - 1, args.sargs);
}

static modp_t 
modpvec_first (modpvec_t self, modpvec_args args)
{
  assert (self->n > 0);
  return modpseq_last (self->ptr, self->n, args.sargs);
}

static modp_t 
modpvec_elt (modpvec_t self, modpvec_ixt ix, modpvec_args args)
{
  assert (ix->n == self->n);
  return modpvec_at (self, ix->i, args);
}

static int 
modpvec_iszero (modpvec_t self, modpvec_args args)
{
  return modpseq_iszero (self->ptr, self->n, args.sargs);
}

static int 
modpvec_isop (modpvec_t a, modpvec_t b, modpvec_args args)
{
  assert (a != b);
  return (a->n == b->n && modpseq_isop (a->ptr, b->ptr, a->n, args.sargs));
}

static void 
modpvec_ooneg (modpvec_t c, modpvec_t a, modpvec_args args)
{
  modpvec_init (c, a->n, args);
  modpseq_ooneg (c->ptr, a->ptr, a->n, args.sargs);
}

static void 
modpvec_inneg (modpvec_t a, modpvec_args args)
{
  modpseq_inneg (a->ptr, a->n, args.sargs);
}

static void 
modpvec_oodbl (modpvec_t c, modpvec_t a, int v, modpvec_args args)
{
  modpvec_init (c, a->n, args);
  modpseq_oodbl (c->ptr, a->ptr, v, a->n, args.sargs);
}

static void 
modpvec_indbl (modpvec_t a, int v, modpvec_args args)
{
  modpseq_indbl (a->ptr, v, a->n, args.sargs);
}

static void 
modpvec_checkcount (int a, int b)
{
  if (a != b)
    {
      fprintf (stderr, "Vector : Dimensions Not Equal\n");
      abort ();
    }
}

static void 
modpvec_ooadd (modpvec_t c, modpvec_t a, int v, modpvec_t b, int w, modpvec_args args)
{
  assert (a != b);
  modpvec_checkcount (a->n, b->n);
  modpvec_init (c, a->n, args);
  modpseq_ooadd (c->ptr, a->ptr, v, b->ptr, w, a->n, args.sargs);
}

static void 
modpvec_inadd (modpvec_t a, int v, modpvec_t b, int w, modpvec_args args)
{
  assert (a != b);
  modpvec_checkcount (a->n, b->n);
  modpseq_inadd (a->ptr, v, b->ptr, w, a->n, args.sargs);
}

static void 
modpvec_oomulsc (modpvec_t c, modpvec_t a, modp_t s, modpvec_args args)
{
  modpvec_init (c, a->n, args);
  modpseq_oomulsc (c->ptr, a->ptr, s, a->n, args.sargs);
}

static void 
modpvec_inmulsc (modpvec_t a, modp_t s, modpvec_args args)
{
  modpseq_inmulsc (a->ptr, s, a->n, args.sargs);
}

static void 
modpvec_ooaddmulsc (modpvec_t c, modpvec_t a, int v, modpvec_t b, modp_t s, int w, modpvec_args args)
{
  assert (a != b);
  modpvec_checkcount (a->n, b->n);
  modpvec_init (c, a->n, args);
  modpseq_ooaddmulsc (c->ptr, a->ptr, v, b->ptr, s, w, a->n, args.sargs);
}

static void 
modpvec_inaddmulsc (modpvec_t a, int v, modpvec_t b, modp_t s, int w, modpvec_args args)
{
  assert (a != b);
  modpvec_checkcount (a->n, b->n);
  modpseq_inaddmulsc (a->ptr, v, b->ptr, s, w, a->n, args.sargs);
}

static void 
modpvec_oomulscadd (modpvec_t c, modpvec_t a, modp_t s, int v, modpvec_t b, int w, modpvec_args args)
{
  assert (a != b);
  modpvec_checkcount (a->n, b->n);
  modpvec_init (c, a->n, args);
  modpseq_oomulscadd (c->ptr, a->ptr, s, v, b->ptr, w, a->n, args.sargs);
}

static void 
modpvec_inmulscadd (modpvec_t a, modp_t s, int v, modpvec_t b, int w, modpvec_args args)
{
  assert (a != b);
  modpvec_checkcount (a->n, b->n);
  modpseq_inmulscadd (a->ptr, s, v, b->ptr, w, a->n, args.sargs);
}

static void 
modpvec_oomulscaddmulsc (modpvec_t c, modpvec_t a, modp_t s, int v, modpvec_t b, modp_t t, int w, modpvec_args args)
{
  assert (a != b);
  modpvec_checkcount (a->n, b->n);
  modpvec_init (c, a->n, args);
  modpseq_oomulscaddmulsc (c->ptr, a->ptr, s, v, b->ptr, t, w, a->n, args.sargs);
}

static void 
modpvec_inmulscaddmulsc (modpvec_t a, modp_t s, int v, modpvec_t b, modp_t t, int w, modpvec_args args)
{
  assert (a != b);
  modpvec_checkcount (a->n, b->n);
  modpseq_inmulscaddmulsc (a->ptr, s, v, b->ptr, t, w, a->n, args.sargs);
}

static BOOL 
modpvec_oodivsc (modpvec_t c, modpvec_t a, modp_t s, modpvec_args args)
{
  BOOL failed;

  modpvec_init (c, a->n, args);
  failed = modpseq_oodivsc (c->ptr, a->ptr, s, a->n, args.sargs);
  if (failed)
    modpvec_destroy (c, args);

  return failed;
}

static void 
modpvec_indivsc (modpvec_t a, modp_t s, modpvec_args args)
{
  modpseq_indivsc (a->ptr, s, a->n, args.sargs);
}

static void 
modpvec_oodotmul (modp_c * c, modpvec_t a, modpvec_t b, modpvec_args args)
{
  assert (a != b);
  modpvec_checkcount (a->n, b->n);
  modpseq_oodotmul (c, a->ptr, b->ptr, a->n, args.sargs);
}

static void 
modpvec_oodotsqr (modp_c * c, modpvec_t a, modpvec_args args)
{
  modpseq_oodotsqr (c, a->ptr, a->n, args.sargs);
}

static void 
modpvec_args_fileOut (id aFiler, modpvec_args * args)
{
  modpseq_args_fileOut (aFiler, &args->sargs);
}
static void 
modpvec_args_fileIn (id aFiler, modpvec_args * args)
{
  modpseq_args_fileIn (aFiler, &args->sargs);
}

static void 
modpvec_fileOut (id aFiler, modpvec_t self, modpvec_args args)
{
  [aFiler fileOut:&self->n type:'i'];
  modpseq_fileOut (aFiler, self->ptr, self->n, args.sargs);
}

static void 
modpvec_fileIn (id aFiler, modpvec_t self, modpvec_args args)
{
  int n;
  [aFiler fileIn:&n type:'i'];
  modpvec_init (self, n, args);
  modpseq_fileIn (aFiler, self->ptr, self->n, args.sargs);
}

static void 
modpvec_ix_init (modpvec_ixt ix, id self)
{
  modpvec_t v = [self modpvec_value];
  ix->n = v->n;
}

static void 
modpvec_ix_copy (modpvec_ixt c, modpvec_ixt a)
{
  c->i = a->i;
  c->n = a->n;
}

static void 
modpvec_ix_clear (modpvec_ixt ix)
{
  /* nothing to clear */
}

static int 
modpvec_ix_count (modpvec_ixt ix)
{
  return ix->n;
}

static int 
modpvec_ix_isempty (modpvec_ixt ix)
{
  return ix->n == 0;
}

static int 
modpvec_ix_ismatch (modpvec_ixt ix)
{
  assert (-1 <= ix->i && ix->i <= ix->n);
  return 0 <= ix->i && ix->i < ix->n;
}

static void 
modpvec_ix_tofirst (modpvec_ixt ix)
{
  ix->i = -1;			/* next -> first */
}

static void 
modpvec_ix_tolast (modpvec_ixt ix)
{
  ix->i = ix->n;		/* prev -> last */
}

static void 
modpvec_ix_to (modpvec_ixt ix, int i)
{
  /* the actual position is n-i-1; conversion done in elting routine... */
  if (i < 0)
    ix->i = -1;
  else if (i > ix->n)
    ix->i = ix->n;
  else
    ix->i = i - 1;		/* next -> at i */
}

static void 
modpvec_ix_next (modpvec_ixt ix)
{
  ix->i = (ix->i < ix->n) ? ix->i + 1 : ix->n;
}

static void 
modpvec_ix_prev (modpvec_ixt ix)
{
  ix->i = (0 <= ix->i) ? ix->i - 1 : -1;
}
@implementation modp_vector : vectorc

- check
{
  [super check];
  [scalarZero check];
  modpvec_check (&value, modpvec_getargs (self));
  return self;
}


- _setUpScalarZero:aScalarZero numScalars:(int)numScalars
{
  scalarZero = aScalarZero;
  modpvec_initcount (&value, numScalars, modpvec_getargs (self));
  assert ([self check]);
  return self;
}

+ scalarZero:aScalarZero numScalars:(int)numScalars
{
  return [[super new] _setUpScalarZero:aScalarZero numScalars:numScalars];
}

- copy
{
  modpvec_c c;
  assert ([self check]);
  modpvec_copy (&c, &value, modpvec_getargs (self));
  return modpvec_c2id (self, &c);
}

- deepCopy
{
  modpvec_c c;
  assert ([self check]);
  modpvec_deepcopy (&c, &value, modpvec_getargs (self));
  return modpvec_c2id (self, &c);
}

- release
{
  modpvec_clear (&value, modpvec_getargs (self));
  return [super release];
}

- (modpvec_t)modpvec_value
{
  return &value;
}

- domodpvec_value:(modpvec_t)aValue
{
  modpvec_copy (&value, aValue, modpvec_getargs (self));
  assert ([self check]);
  return self;
}

- modpvec_value:(modpvec_t)aValue
{
  return [[self clone] domodpvec_value:aValue];
}

- (modpvec_t)modpvec_reference
{
  return &value;
}

- domodpvec_reference:(modpvec_c *)aReference
{
  modpvec_move (&value, aReference, modpvec_getargs (self));
  assert ([self check]);
  return self;
}

- modpvec_reference:(modpvec_c *)aReference
{
  return [[self clone] domodpvec_reference:aReference];
}

- capacity:(int)aCapacity
{
  modpvec_c c;
  assert ([self check]);
  modpvec_initcapacity (&c, aCapacity, modpvec_getargs (self));
  return modpvec_c2id (self, &c);
}

- numScalars:(int)numScalars
{
  modpvec_c c;
  assert ([self check]);
  modpvec_initcount (&c, numScalars, modpvec_getargs (self));
  return modpvec_c2id (self, &c);
}


- scalarZero
{
  return scalarZero;
}

- (int) numScalars
{
  assert ([self check]);
  return modpvec_count (&value);
}


- insertScalar:aScalar
{
  modp_c c;
  assert ([aScalar check]);
  assert ([self check]);
  modpvec_insertfirst (&value, modp_id2ref (aScalar, &c), modpvec_getargs (self));
  assert ([aScalar check]);
  assert ([self check]);
  [self invalidate];
  return self;
}

- insertScalar:aScalar at:(int)i
{
  modp_c c;
  assert (aScalar);
  assert ([self check]);
  modpvec_insertat (&value, modp_id2ref (aScalar, &c), i, modpvec_getargs (self));
  assert ([aScalar check]);
  assert ([self check]);
  [self invalidate];
  return self;
}


- removeScalar
{
  if ([self numScalars])
    {
      id res;
      modp_t t = modpvec_first (&value, modpvec_getargs (self));
      assert ([self check]);
      res = modp_t2id (scalarZero, t);
      modpvec_freefirst (&value, modpvec_getargs (self));
      assert ([self check]);
      assert ([res check]);
      [self invalidate];
      return res;
    }
  else
    {
      return nil;
    }
}

- removeScalarAt:(int)i
{
  id res;
  assert ([self check]);
  res = modp_t2id (scalarZero, modpvec_at (&value, i, modpvec_getargs (self)));
  modpvec_freeat (&value, i, modpvec_getargs (self));
  assert ([self check]);
  assert ([res check]);
  [self invalidate];
  return res;
}


- placeScalar:aScalar at:(int)i
{
  modp_c c;
  assert ([aScalar check]);
  assert ([self check]);
  modpvec_place (&value, modp_id2ref (aScalar, &c), i, modpvec_getargs (self));
  assert ([aScalar check]);
  assert ([self check]);
  [self invalidate];
  return self;
}

- replaceScalarAt:(int)i with:aScalar
{
  id res;
  modp_c c;
  modp_t t = modpvec_at (&value, i, modpvec_getargs (self));
  assert ([self check]);
  res = modp_t2id (scalarZero, t);
  modpvec_place (&value, modp_id2ref (aScalar, &c), i, modpvec_getargs (self));
  assert ([aScalar check]);
  assert ([self check]);
  assert ([res check]);
  [self invalidate];
  return res;
}


- eachScalar
{
  id aSequence = [modpvec_sequence content:self];
  return [CASequence over:aSequence];
}

- elt_modpvec_ix:(modpvec_ixt)ix
{
  if (modpvec_ix_ismatch (ix))
    {
      modp_t t = modpvec_elt (&value, ix, modpvec_getargs (self));
      return modp_t2id (scalarZero, t);
    }
  else
    {
      return nil;
    }
}


- dotMultiply:b
{
  modp_c c;			/* carrier for scalar */
  modpvec_oodotmul (&c, &value, [b modpvec_value], modpvec_getargs (self));
  /* now promote the carrier to object */
  /* all of this used to be very difficult in 0.6 */
  return modp_c2id (scalarZero, &c);
}

- dotSquare
{
  modp_c c;			/* carrier for scalar */
  modpvec_oodotsqr (&c, &value, modpvec_getargs (self));
  /* now promote the carrier to object */
  /* all of this used to be very difficult in 0.6 */
  return modp_c2id (scalarZero, &c);
}


- fileOutOn:aFiler
{
  modpvec_args args;
  assert ([self check]);
  [super fileOutOn:aFiler];
  args = modpvec_getargs (self);
  modpvec_args_fileOut (aFiler, &args);
  modpvec_fileOut (aFiler, &value, args);
  return self;
}

- fileInFrom:aFiler
{
  modpvec_args args;
  [super fileInFrom:aFiler];
  modpvec_args_fileIn (aFiler, &args);
  modpvec_fileIn (aFiler, &value, args);
  return self;
}

- (unsigned) hash
{
  return modpvec_hash (modpvec_id2t (self), modpvec_getargs (self));
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
      return modpvec_iseq (modpvec_id2t (self), modpvec_id2t (b), modpvec_getargs (self));
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
      return !modpvec_iseq (modpvec_id2t (self), modpvec_id2t (b), modpvec_getargs (self));
    }
}

- (BOOL) isZero
{
  assert ([self check]);
  return modpvec_iszero (modpvec_id2t (self), modpvec_getargs (self));
}

- (BOOL) notZero
{
  assert ([self check]);
  return !modpvec_iszero (modpvec_id2t (self), modpvec_getargs (self));
}

- (BOOL) isOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return modpvec_isop (modpvec_id2t (self), modpvec_id2t (b), modpvec_getargs (self));
}

- (BOOL) notOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return !modpvec_isop (modpvec_id2t (self), modpvec_id2t (b), modpvec_getargs (self));
}

- negate
{
  modpvec_c c;
  assert ([self check]);
  modpvec_ooneg (&c, modpvec_id2t (self), modpvec_getargs (self));
  return modpvec_c2id (self, &c);
}

- _double:(int)v
{
  modpvec_c c;
  assert ([self check]);
  modpvec_oodbl (&c, modpvec_id2t (self), v, modpvec_getargs (self));
  return modpvec_c2id (self, &c);
}

- double
{
  modpvec_c c;
  assert ([self check]);
  modpvec_oodbl (&c, modpvec_id2t (self), +1, modpvec_getargs (self));
  return modpvec_c2id (self, &c);
}

- _add:(int)v:b:(int)w
{
  modpvec_c c;
  assert ([self sameClass:b] && v * v == 1 && w * w == 1 && self != b);
  modpvec_ooadd (&c, modpvec_id2t (self), v, modpvec_id2t (b), w, modpvec_getargs (self));
  return modpvec_c2id (self, &c);
}

- add:b
{
  modpvec_c c;
  assert ([self checkSameClass:b] && self != b);
  modpvec_ooadd (&c, modpvec_id2t (self), +1, modpvec_id2t (b), +1, modpvec_getargs (self));
  return modpvec_c2id (self, &c);
}

- subtract:b
{
  modpvec_c c;
  assert ([self checkSameClass:b] && self != b);
  modpvec_ooadd (&c, modpvec_id2t (self), +1, modpvec_id2t (b), -1, modpvec_getargs (self));
  return modpvec_c2id (self, &c);
}

- multiplyScalar:s
{
  modpvec_c c;
  modp_c sc;
  modpvec_oomulsc (&c, modpvec_id2t (self), modp_id2ref (s, &sc), modpvec_getargs (self));
  return modpvec_c2id (self, &c);
}

- divideScalar:s
{
  modpvec_c c;
  modp_c sc;
  BOOL failed = modpvec_oodivsc (&c, modpvec_id2t (self), modp_id2ref (s, &sc), modpvec_getargs (self));
  return (failed) ? nil : modpvec_c2id (self, &c);
}

- _add:(int)v:B multiplyScalar:b:(int)w
{
  modpvec_c c;
  modp_c bc;
  assert ([self sameClass:B] && [scalarZero sameClass:b] && v * v == 1 && w * w == 1);
  modpvec_ooaddmulsc (&c, modpvec_id2t (self), v, modpvec_id2t (B), modp_id2ref (b, &bc), w, modpvec_getargs (self));
  return modpvec_c2id (self, &c);
}

- _multiplyScalar:a:(int)v add:B:(int)w
{
  modpvec_c c;
  modp_c ac;
  assert ([scalarZero sameClass:a] && [self sameClass:B] && v * v == 1 && w * w == 1);
  modpvec_oomulscadd (&c, modpvec_id2t (self), modp_id2ref (a, &ac), v, modpvec_id2t (B), w, modpvec_getargs (self));
  return modpvec_c2id (self, &c);
}

- _multiplyScalar:a:(int)v add:B multiplyScalar:b:(int)w
{
  modpvec_c c;
  modp_c ac, bc;
  assert ([scalarZero sameClass:a] && [self sameClass:B] && [scalarZero sameClass:b] && v * v == 1 && w * w == 1);
  modpvec_oomulscaddmulsc (&c, modpvec_id2t (self), modp_id2ref (a, &ac), v, modpvec_id2t (B), modp_id2ref (b, &bc), w, modpvec_getargs (self));
  return modpvec_c2id (self, &c);
}

@end
 
