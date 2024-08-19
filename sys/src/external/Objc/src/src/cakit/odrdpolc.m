#include "cakit.h"

static obj_args 
obj_getargs (id object)
{
  obj_args args;
#if OBJC_REFCNT
  memset (&args, 0, sizeof (obj_args));
#endif
  args.proto = object;
  return args;
}

static int 
obj_size (obj_args args)
{
  return 1;			/* pointer increment */
}

static int 
obj_bsize (obj_args args)
{
  return sizeof (obj_c);	/* byte size carrier */
}

#if 0
static obj_t 
obj_id2t (id object)
{				/* not needed */
}
static obj_c *
obj_id2t (id object)
{				/* not needed */
}
#endif

static obj_t 
obj_id2ref (id object, obj_c * ref)
{
  return object;		/* read-only, scratch space "ref" */
}

static id 
obj_t2id (id proto, obj_t t)
{
  return t;			/* new object, contains copy of "t" */
}

static id 
obj_c2id (id proto, obj_c * c)
{
  return *c;			/* new object, contains "c" */
}

static int 
obj_check (obj_t self, obj_args args)
{
  assert (args.proto && self);
  [args.proto check];
  [self check];
  return 1;
}

static void 
obj_oozero (obj_c * c, obj_args args)
{
  *c = [args.proto zero];
}

static void 
obj_copy (obj_c * c, obj_t a, obj_args args)
{
  *c = a;
}

static void 
obj_deepcopy (obj_c * c, obj_t a, obj_args args)
{
  *c = [a deepCopy];
}

static void 
obj_move (obj_c * c, obj_c * a, obj_args args)
{
  *c = *a;
  *a = nil;
}

static void 
obj_clear (obj_c * c, obj_args args)
{
  *c = nil;
}

static unsigned 
obj_hash (obj_t a, obj_args args)
{
  return [a hash];
}

static int 
obj_iseq (obj_t a, obj_t b, obj_args args)
{
  return (a == b) ? YES : [a isEqual:b];
}

static int 
obj_sgn (obj_t a, obj_args args)
{
  return [a sign];
}

static int 
obj_cmp (obj_t a, obj_t b, obj_args args)
{
  return (a == b) ? 0 : [a compare:b];
}

static int 
obj_iszero (obj_t a, obj_args args)
{
  return [a isZero];
}

static int 
obj_isop (obj_t a, obj_t b, obj_args args)
{
  return [a isOpposite:b];
}

static void 
obj_ooneg (obj_c * c, obj_t a, obj_args args)
{
  *c = [a negate];
}

static void 
obj_inneg (obj_c * c, obj_args args)
{
  *c = [*c negate];
}

static void 
obj_oodbl (obj_c * c, obj_t a, int v, obj_args args)
{
  *c = [a _double:v];
}

static void 
obj_indbl (obj_c * c, int v, obj_args args)
{
  *c = [*c _double:v];
}

static void 
obj_ooadd (obj_c * c, obj_t a, int v, obj_t b, int w, obj_args args)
{
  *c = [a _add:v:b:w];
}

static void 
obj_inadd (obj_c * c, int v, obj_t b, int w, obj_args args)
{
  *c = [*c _add:v:b:w];
}

static int 
obj_isone (obj_t a, obj_args args)
{
  return [a isOne];
}

static int 
obj_isminusone (obj_t a, obj_args args)
{
  return [a isMinusOne];
}

static void 
obj_oosqr (obj_c * c, obj_t a, obj_args args)
{
  *c = [a square];
}

static void 
obj_insqr (obj_c * c, obj_args args)
{
  *c = [*c square];
}

static void 
obj_oomul (obj_c * c, obj_t a, obj_t b, obj_args args)
{
  *c = [a multiply:b];
}

static void 
obj_inmul (obj_c * c, obj_t b, obj_args args)
{
  *c = [*c multiply:b];
}

static void 
obj_oomulv (obj_c * c, obj_t a, obj_t b, int v, obj_args args)
{
  *c = [a _multiply:b:v];
}

static void 
obj_inmulv (obj_c * c, obj_t b, int v, obj_args args)
{
  *c = [*c _multiply:b:v];
}

static void 
obj_ooaddmul (obj_c * c, obj_t a, int v, obj_t b, obj_t t, int w, obj_args args)
{
  *c = [a _add:v:b multiply:t:w];
}

static void 
obj_inaddmul (obj_c * c, int v, obj_t b, obj_t t, int w, obj_args args)
{
  *c = [*c _add:v:b multiply:t:w];
}

static void 
obj_oomuladd (obj_c * c, obj_t a, obj_t s, int v, obj_t b, int w, obj_args args)
{
  *c = [a _multiply:s:v add:b:w];
}

static void 
obj_inmuladd (obj_c * c, obj_t s, int v, obj_t b, int w, obj_args args)
{
  *c = [*c _multiply:s:v add:b:w];
}

static void 
obj_oomuladdmul (obj_c * c, obj_t a, obj_t s, int v, obj_t b, obj_t t, int w, obj_args args)
{
  *c = [a _multiply:s:v add:b multiply:t:w];
}

static void 
obj_inmuladdmul (obj_c * c, obj_t s, int v, obj_t b, obj_t t, int w, obj_args args)
{
  *c = [*c _multiply:s:v add:b multiply:t:w];
}

static void 
obj_ooaddsqr (obj_c * c, obj_t a, int v, obj_t b, int w, obj_args args)
{
  *c = [a _addSquare:v:b:w];
}

static void 
obj_inaddsqr (obj_c * c, int v, obj_t b, int w, obj_args args)
{
  *c = [*c _addSquare:v:b:w];
}

static void 
obj_ooinv (obj_c * c, obj_t a, obj_args args)
{
  *c = [a inverse];
}

static void 
obj_ininv (obj_c * c, obj_args args)
{
  *c = [*c inverse];
}

static BOOL 
obj_oodiv (obj_c * c, obj_t a, obj_t b, obj_args args)
{
  id Q = [a divide:b];
  if (Q)
    {
      *c = Q;
      return SUCCESS;
    }
  else
    {
      return FAILURE;
    }
}

static void 
obj_indiv (obj_c * c, obj_t b, obj_args args)
{
  id Q = [*c divide:b];
  if (Q)
    {
      *c = Q;
    }
  else
    {
      fprintf (stderr, "-exact division failed\n");
      abort ();
    }
}

static void 
obj_args_fileOut (id aFiler, obj_args * args)
{
}
static void 
obj_args_fileIn (id aFiler, obj_args * args)
{
}

static void 
obj_fileOut (id aFiler, obj_c * a, obj_args args)
{
  [aFiler fileOut:a type:'@'];
}

static void 
obj_fileIn (id aFiler, obj_c * c, obj_args args)
{
  [aFiler fileIn:c type:'@'];
}


/*
 * Computer Algebra Kit (c) 1993,00 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: odrdpolc.m,v 1.6 2000/10/12 14:40:26 stes Exp $
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

#if obj_pervalue
static obj_t 
objseq_tval (objseq_t self)
{
  return *self;
}
static obj_c *
objseq_cval (objseq_t self)
{
  return self;
}
#else
static obj_t 
objseq_tval (objseq_t self)
{
  return self;
}
static obj_c *
objseq_cval (objseq_t self)
{
  return self;
}
#endif

static int 
objseq_check (objseq_t self, int n, obj_args args)
{
  while (n--)
    {
      obj_check (objseq_tval (self), args);
      self += obj_size (args);
    }
  return 1;
}

static objseq_t 
objseq_alloc (int n, obj_args args)
{
  objseq_t p;
  int m = n * obj_bsize (args);
#if OBJC_REFCNT
  p = (objseq_t) OC_Calloc (m);
#else
  p = (objseq_t) OC_Malloc (m);
#endif
  return p;
}

static objseq_t 
objseq_realloc (objseq_t self, int oldc, int n, obj_args args)
{
  objseq_t p;
  int m = n * obj_bsize (args);
  p = (objseq_t) OC_Realloc (self, m);
#if OBJC_REFCNT
  assert (oldc <= n);
  memset (p + oldc, 0, (n - oldc) * obj_bsize (args));
#endif
  return p;
}

static objseq_t 
objseq_free (objseq_t self, obj_args args)
{
  OC_Free (self);
  return NULL;
}

static void 
objseq_oozero (objseq_t c, int n, obj_args args)
{
  while (n--)
    {
      obj_oozero (objseq_cval (c), args);
      c += obj_size (args);
    }
}

static void 
objseq_copy (objseq_t c, objseq_t a, int n, obj_args args)
{
  assert (n >= 0);
  while (n--)
    {
      obj_copy (objseq_cval (c), objseq_tval (a), args);
      c += obj_size (args);
      a += obj_size (args);
    }
}

static void 
objseq_deepcopy (objseq_t c, objseq_t a, int n, obj_args args)
{
  assert (n >= 0);
  while (n--)
    {
      obj_deepcopy (objseq_cval (c), objseq_tval (a), args);
      c += obj_size (args);
      a += obj_size (args);
    }
}

#if obj_isvalue
static void 
objseq_clear (objseq_t self, int n, obj_args args)
{
  /* nothing to clear */
}
#else
static void 
objseq_clear (objseq_t self, int n, obj_args args)
{
  while (n--)
    {
      obj_clear (self, args);
      self += obj_size (args);
    }
}
#endif /* obj_isvalue */

static int 
objseq_iseq (objseq_t a, objseq_t b, int n, obj_args args)
{
  assert (n >= 0 && a != b);
  while (n--)
    {
      if (!obj_iseq (objseq_tval (a), objseq_tval (b), args))
	{
	  return 0;
	}
      else
	{
	  a += obj_size (args);
	  b += obj_size (args);
	}
    }
  return 1;
}

static unsigned 
objseq_hash (objseq_t a, int n, obj_args args)
{
  assert (n >= 0);
  return (n) ? obj_hash (objseq_tval (a), args) : 0;
}

static void 
objseq_place (objseq_t self, obj_t a, int i, obj_args args)
{
  obj_c *c = objseq_cval (self + i * obj_size (args));
  obj_clear (c, args);
  obj_copy (c, a, args);
}

static int 
objseq_insertlast (objseq_t self, obj_t a, int n, obj_args args)
{
  obj_c *c;
  assert (n >= 0);
  c = objseq_cval (self + n * obj_size (args));
  obj_copy (c, a, args);
  return ++n;
}

static int 
objseq_insertfirst (objseq_t self, obj_t a, int n, obj_args args)
{
  int j;
  assert (n > 0);
  self += n * obj_size (args);
  j = n;
  while (j--)
    {
      objseq_t t;
      t = self - obj_size (args);
      obj_move (objseq_cval (self), objseq_cval (t), args);
      self = t;
    }
  obj_copy (objseq_cval (self), a, args);
  return ++n;
}

static int 
objseq_insertat (objseq_t self, obj_t a, int i, int n, obj_args args)
{
  assert (0 <= i && i < n);
  self += i * obj_size (args);
  return i + objseq_insertfirst (self, a, n - i, args);
}

static int 
objseq_freelast (objseq_t self, int n, obj_args args)
{
  obj_c *c;
  assert (0 < n);
  --n;
  c = objseq_cval (self + n * obj_size (args));
  obj_clear (c, args);
  return n;
}

static int 
objseq_freefirst (objseq_t self, int n, obj_args args)
{
  int j;
  assert (0 < n);
  obj_clear (objseq_cval (self), args);
  --n;
  j = n;
  while (j--)
    {
      objseq_t t;
      t = self + obj_size (args);
      obj_move (objseq_cval (self), objseq_cval (t), args);
      self = t;
    }
  return n;
}

static int 
objseq_freeat (objseq_t self, int i, int n, obj_args args)
{
  assert (0 <= i && i < n);
  self += i * obj_size (args);
  return i + objseq_freefirst (self, n - i, args);
}

static obj_t 
objseq_at (objseq_t self, int i, obj_args args)
{
  obj_t res;
  assert (0 <= i);
  res = objseq_tval (self + i * obj_size (args));
  assert (obj_check (res, args));
  return res;
}

static obj_t 
objseq_last (objseq_t self, int n, obj_args args)
{
  return objseq_at (self, n - 1, args);
}

static obj_c *
objseq_cvalat (objseq_t self, int i, obj_args args)
{
  assert (0 <= i);
  return objseq_cval (self + i * obj_size (args));
}

static int 
objseq_iszero (objseq_t a, int n, obj_args args)
{
  assert (n >= 0);
  while (n--)
    {
      if (obj_iszero (objseq_tval (a), args))
	{
	  a += obj_size (args);
	}
      else
	{
	  return 0;
	}
    }
  return 1;
}

static int 
objseq_isop (objseq_t a, objseq_t b, int n, obj_args args)
{
  assert (n >= 0 && a != b);
  while (n--)
    {
      if (!obj_isop (objseq_tval (a), objseq_tval (b), args))
	{
	  return 0;
	}
      else
	{
	  a += obj_size (args);
	  b += obj_size (args);
	}
    }
  return 1;
}

static void 
objseq_ooneg (objseq_t c, objseq_t a, int n, obj_args args)
{
  assert (n >= 0);
  while (n--)
    {
      obj_ooneg (objseq_cval (c), objseq_tval (a), args);
      c += obj_size (args);
      a += obj_size (args);
    }
}

static void 
objseq_inneg (objseq_t a, int n, obj_args args)
{
  assert (n >= 0);
  while (n--)
    {
      obj_inneg (objseq_cval (a), args);
      a += obj_size (args);
    }
}

static void 
objseq_oonegv (objseq_t c, objseq_t a, int v, int n, obj_args args)
{
  assert (v * v == 1);
  if (v == -1)
    objseq_ooneg (c, a, n, args);
  else
    objseq_copy (c, a, n, args);
}

static void 
objseq_innegv (objseq_t a, int v, int n, obj_args args)
{
  assert (v * v == 1);
  if (v == -1)
    objseq_inneg (a, n, args);
}

static void 
objseq_oodbl (objseq_t c, objseq_t a, int v, int n, obj_args args)
{
  assert (n >= 0 && v * v == 1);
  while (n--)
    {
      obj_oodbl (objseq_cval (c), objseq_tval (a), v, args);
      c += obj_size (args);
      a += obj_size (args);
    }
}

static void 
objseq_indbl (objseq_t a, int v, int n, obj_args args)
{
  assert (n >= 0 && v * v == 1);
  while (n--)
    {
      obj_indbl (objseq_cval (a), v, args);
      a += obj_size (args);
    }
}

static void 
objseq_ooadd (objseq_t c, objseq_t a, int v, objseq_t b, int w, int n, obj_args args)
{
  assert (n >= 0 && a != b && v * v == 1 && w * w == 1);
  while (n--)
    {
      obj_ooadd (objseq_cval (c), objseq_tval (a), v, objseq_tval (b), w, args);
      c += obj_size (args);
      a += obj_size (args);
      b += obj_size (args);
    }
}

static void 
objseq_inadd (objseq_t a, int v, objseq_t b, int w, int n, obj_args args)
{
  assert (n >= 0 && a != b && v * v == 1 && w * w == 1);
  while (n--)
    {
      obj_inadd (objseq_cval (a), v, objseq_tval (b), w, args);
      a += obj_size (args);
      b += obj_size (args);
    }
}

static void 
objseq_oomulsc (objseq_t c, objseq_t a, obj_t s, int n, obj_args args)
{
  assert (n >= 0);
  while (n--)
    {
      obj_oomul (objseq_cval (c), objseq_tval (a), s, args);
      c += obj_size (args);
      a += obj_size (args);
    }
}

static void 
objseq_inmulsc (objseq_t a, obj_t s, int n, obj_args args)
{
  assert (n >= 0);
  while (n--)
    {
      obj_inmul (objseq_cval (a), s, args);
      a += obj_size (args);
    }
}

static void 
objseq_oomulscv (objseq_t c, objseq_t a, obj_t s, int v, int n, obj_args args)
{
  assert (n >= 0 && v * v == 1);
  while (n--)
    {
      obj_oomulv (objseq_cval (c), objseq_tval (a), s, v, args);
      c += obj_size (args);
      a += obj_size (args);
    }
}

static void 
objseq_inmulscv (objseq_t a, obj_t s, int v, int n, obj_args args)
{
  assert (n >= 0 && v * v == 1);
  while (n--)
    {
      obj_inmulv (objseq_cval (a), s, v, args);
      a += obj_size (args);
    }
}

static void 
objseq_ooaddmulsc (objseq_t c, objseq_t a, int v, objseq_t b, obj_t t, int w, int n, obj_args args)
{
  assert (n >= 0 && v * v == 1 && w * w == 1);
  while (n--)
    {
      obj_ooaddmul (objseq_cval (c), objseq_tval (a), v, objseq_tval (b), t, w, args);
      a += obj_size (args);
      b += obj_size (args);
      c += obj_size (args);
    }
}

static void 
objseq_oomulscadd (objseq_t c, objseq_t a, obj_t s, int v, objseq_t b, int w, int n, obj_args args)
{
  assert (n >= 0 && v * v == 1 && w * w == 1);
  while (n--)
    {
      obj_oomuladd (objseq_cval (c), objseq_tval (a), s, v, objseq_tval (b), w, args);
      a += obj_size (args);
      b += obj_size (args);
      c += obj_size (args);
    }
}

static void 
objseq_oomulscaddmulsc (objseq_t c, objseq_t a, obj_t s, int v, objseq_t b, obj_t t, int w, int n, obj_args args)
{
  assert (n >= 0 && v * v == 1 && w * w == 1);
  while (n--)
    {
      obj_oomuladdmul (objseq_cval (c), objseq_tval (a), s, v, objseq_tval (b), t, w, args);
      a += obj_size (args);
      b += obj_size (args);
      c += obj_size (args);
    }
}

static void 
objseq_inaddmulsc (objseq_t a, int v, objseq_t b, obj_t t, int w, int n, obj_args args)
{
  assert (n >= 0 && v * v == 1 && w * w == 1);
  while (n--)
    {
      obj_inaddmul (objseq_cval (a), v, objseq_tval (b), t, w, args);
      a += obj_size (args);
      b += obj_size (args);
    }
}

static void 
objseq_inmulscadd (objseq_t a, obj_t s, int v, objseq_t b, int w, int n, obj_args args)
{
  assert (n >= 0 && v * v == 1 && w * w == 1);
  while (n--)
    {
      obj_inmuladd (objseq_cval (a), s, v, objseq_tval (b), w, args);
      a += obj_size (args);
      b += obj_size (args);
    }
}

static void 
objseq_inmulscaddmulsc (objseq_t a, obj_t s, int v, objseq_t b, obj_t t, int w, int n, obj_args args)
{
  assert (n >= 0 && v * v == 1 && w * w == 1);
  while (n--)
    {
      obj_inmuladdmul (objseq_cval (a), s, v, objseq_tval (b), t, w, args);
      a += obj_size (args);
      b += obj_size (args);
    }
}

static BOOL 
objseq_oodivsc (objseq_t c, objseq_t a, obj_t s, int n, obj_args args)
{
  int i;
  BOOL failed;
  objseq_t orgc = c;
  assert (n >= 0);

  for (i = 0; i < n; i++)
    {

      failed = obj_oodiv (objseq_cval (c), objseq_tval (a), s, args);

      if (failed)
	{
	  objseq_clear (orgc, i - 1, args);
	  return FAILURE;
	}
      else
	{
	  c += obj_size (args);
	  a += obj_size (args);
	}
    }

  return SUCCESS;
}

static void 
objseq_indivsc (objseq_t a, obj_t s, int n, obj_args args)
{
  assert (n >= 0);
  while (n--)
    {
      obj_indiv (objseq_cval (a), s, args);
      a += obj_size (args);
    }
}

static void 
objseq_oodotsqr (obj_c * c, objseq_t a, int n, obj_args args)
{
  assert (n >= 0);
  obj_oozero (c, args);
  while (n--)
    {
      obj_inaddsqr (c, +1, objseq_tval (a), +1, args);
      a += obj_size (args);
    }
}

static void 
objseq_oodotmul (obj_c * c, objseq_t a, objseq_t b, int n, obj_args args)
{
  assert (n >= 0);
  obj_oozero (c, args);
  while (n--)
    {
      obj_inaddmul (c, +1, objseq_tval (a), objseq_tval (b), +1, args);
      a += obj_size (args);
      b += obj_size (args);
    }
}

static void 
objseq_args_fileOut (id aFiler, obj_args * args)
{
  obj_args_fileOut (aFiler, args);
}
static void 
objseq_args_fileIn (id aFiler, obj_args * args)
{
  obj_args_fileIn (aFiler, args);
}

static void 
objseq_fileOut (id aFiler, objseq_t self, int n, obj_args args)
{
  assert (n >= 0);
  while (n--)
    {
      obj_fileOut (aFiler, objseq_cval (self), args);
      self += obj_size (args);
    }
}

static void 
objseq_fileIn (id aFiler, objseq_t self, int n, obj_args args)
{
  assert (n >= 0);
  while (n--)
    {
      obj_fileIn (aFiler, objseq_cval (self), args);
      self += obj_size (args);
    }
}

static int 
obj_vardnsrecdegdnspolseq_check (obj_vardnsrecdegdnspolseq_t self, int n, obj_vardnsrecdegdnspol_args args)
{
  if (n)
    {
      obj_t lcf = objseq_last (self, n, args.sargs);
      assert (!obj_iszero (lcf, args.sargs));
    }

  return objseq_check (self, n, args.sargs);
}

static int 
obj_vardnsrecdegdnspolseq_copy (obj_vardnsrecdegdnspolseq_t c, obj_vardnsrecdegdnspolseq_t a, int n, obj_vardnsrecdegdnspol_args args)
{
  objseq_copy (c, a, n, args.sargs);
  return n;
}

static int 
obj_vardnsrecdegdnspolseq_deepcopy (obj_vardnsrecdegdnspolseq_t c, obj_vardnsrecdegdnspolseq_t a, int n, obj_vardnsrecdegdnspol_args args)
{
  objseq_deepcopy (c, a, n, args.sargs);
  return n;
}

static int 
obj_vardnsrecdegdnspolseq_count (obj_vardnsrecdegdnspolseq_t self, int n, obj_vardnsrecdegdnspol_args args)
{
  int count = 0;
  while (n--)
    {
      if (!obj_iszero (objseq_tval (self), args.sargs))
	count++;
      self += obj_size (args.sargs);
    }
  return count;
}

static int 
obj_vardnsrecdegdnspolseq_ord (obj_vardnsrecdegdnspolseq_t self, int n, obj_vardnsrecdegdnspol_args args)
{
  int ord = -1;
  while (n--)
    {
      if (obj_iszero (objseq_tval (self), args.sargs))
	{
	  ord++;
	  self += obj_size (args.sargs);
	}
      else
	{
	  break;
	}
    }
  return ord;
}

static int 
obj_vardnsrecdegdnspolseq_iseq (obj_vardnsrecdegdnspolseq_t a, int an, obj_vardnsrecdegdnspolseq_t b, int bn, obj_vardnsrecdegdnspol_args args)
{
  return (an == bn) ? objseq_iseq (a, b, an, args.sargs) : 0;
}

static int 
obj_vardnsrecdegdnspolseq_isop (obj_vardnsrecdegdnspolseq_t a, int an, obj_vardnsrecdegdnspolseq_t b, int bn, obj_vardnsrecdegdnspol_args args)
{
  return (an == bn) ? objseq_isop (a, b, an, args.sargs) : 0;
}

static int 
obj_vardnsrecdegdnspolseq_hash (obj_vardnsrecdegdnspolseq_t a, int an, obj_vardnsrecdegdnspol_args args)
{
  return objseq_hash (a, an, args.sargs);
}

static int 
obj_vardnsrecdegdnspolseq_isone (obj_vardnsrecdegdnspolseq_t a, int an, obj_vardnsrecdegdnspol_args args)
{
  return an == 1 && obj_isone (objseq_tval (a), args.sargs);
}

static int 
obj_vardnsrecdegdnspolseq_isminusone (obj_vardnsrecdegdnspolseq_t a, int an, obj_vardnsrecdegdnspol_args args)
{
  return an == 1 && obj_isminusone (objseq_tval (a), args.sargs);
}

static int 
obj_vardnsrecdegdnspolseq_removezeroes (obj_vardnsrecdegdnspolseq_t a, int n, obj_vardnsrecdegdnspol_args args)
{
  a += n * obj_size (args.sargs);
  while (n--)
    {
      a -= obj_size (args.sargs);
      if (obj_iszero (objseq_tval (a), args.sargs))
	{
	  obj_clear (objseq_cval (a), args.sargs);
	}
      else
	{
	  break;
	}
    }
  return n + 1;
}

static int 
obj_vardnsrecdegdnspolseq_delete (obj_vardnsrecdegdnspolseq_t self, int n, obj_vardnsrecdegdnspol_args args)
{
  n = n - 1;
  assert (n >= 0);
  obj_clear (objseq_cvalat (self, n, args.sargs), args.sargs);
  return obj_vardnsrecdegdnspolseq_removezeroes (self, n, args);
}

static int 
obj_vardnsrecdegdnspolseq_insert (obj_vardnsrecdegdnspolseq_t self, int n, int e, obj_t s, obj_vardnsrecdegdnspol_args args)
{
  assert (obj_iszero (s, args.sargs) == 0);
  if (e < n)
    {
      obj_inadd (objseq_cvalat (self, e, args.sargs), +1, s, +1, args.sargs);
      return obj_vardnsrecdegdnspolseq_removezeroes (self, n, args);
    }
  else
    {
      objseq_oozero (self + n * obj_size (args.sargs), e + 1 - n, args.sargs);
      obj_inadd (objseq_cvalat (self, e, args.sargs), +1, s, +1, args.sargs);
      return e + 1;
    }
}

static int 
obj_vardnsrecdegdnspolseq_ooneg (obj_vardnsrecdegdnspolseq_t c, obj_vardnsrecdegdnspolseq_t a, int n, obj_vardnsrecdegdnspol_args args)
{
  objseq_ooneg (c, a, n, args.sargs);
  return n;
}

static int 
obj_vardnsrecdegdnspolseq_inneg (obj_vardnsrecdegdnspolseq_t a, int n, obj_vardnsrecdegdnspol_args args)
{
  objseq_inneg (a, n, args.sargs);
  return n;
}

static int 
obj_vardnsrecdegdnspolseq_oodbl (obj_vardnsrecdegdnspolseq_t c, obj_vardnsrecdegdnspolseq_t a, int n, int v, obj_vardnsrecdegdnspol_args args)
{
  objseq_oodbl (c, a, v, n, args.sargs);
  return obj_vardnsrecdegdnspolseq_removezeroes (c, n, args);
}

static int 
obj_vardnsrecdegdnspolseq_indbl (obj_vardnsrecdegdnspolseq_t a, int n, int v, obj_vardnsrecdegdnspol_args args)
{
  objseq_indbl (a, v, n, args.sargs);
  return obj_vardnsrecdegdnspolseq_removezeroes (a, n, args);
}

static int 
obj_vardnsrecdegdnspolseq_ooadd (obj_vardnsrecdegdnspolseq_t c, obj_vardnsrecdegdnspolseq_t a, int an, int v, obj_vardnsrecdegdnspolseq_t b, int bn, int w, obj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      objseq_ooadd (c, a, v, b, w, an, args.sargs);
      return obj_vardnsrecdegdnspolseq_removezeroes (c, an, args);
    }
  else
    {
      if (an < bn)
	{
	  objseq_ooadd (c, a, v, b, w, an, args.sargs);
	  c += an * obj_size (args.sargs);
	  b += an * obj_size (args.sargs);
	  objseq_oonegv (c, b, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  objseq_ooadd (c, a, v, b, w, bn, args.sargs);
	  c += bn * obj_size (args.sargs);
	  a += bn * obj_size (args.sargs);
	  objseq_oonegv (c, a, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static int 
obj_vardnsrecdegdnspolseq_inadd (obj_vardnsrecdegdnspolseq_t a, int an, int v, obj_vardnsrecdegdnspolseq_t b, int bn, int w, obj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      objseq_inadd (a, v, b, w, an, args.sargs);
      return obj_vardnsrecdegdnspolseq_removezeroes (a, an, args);
    }
  else
    {
      if (an < bn)
	{
	  objseq_inadd (a, v, b, w, an, args.sargs);
	  a += an * obj_size (args.sargs);
	  b += an * obj_size (args.sargs);
	  objseq_oonegv (a, b, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  objseq_inadd (a, v, b, w, bn, args.sargs);
	  a += bn * obj_size (args.sargs);
	  objseq_innegv (a, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static int 
obj_vardnsrecdegdnspolseq_oomulsc (obj_vardnsrecdegdnspolseq_t c, obj_vardnsrecdegdnspolseq_t a, int n, obj_t s, obj_vardnsrecdegdnspol_args args)
{
  objseq_oomulsc (c, a, s, n, args.sargs);
  return obj_vardnsrecdegdnspolseq_removezeroes (c, n, args);
}

static int 
obj_vardnsrecdegdnspolseq_inmulsc (obj_vardnsrecdegdnspolseq_t a, int n, obj_t s, obj_vardnsrecdegdnspol_args args)
{
  objseq_inmulsc (a, s, n, args.sargs);
  return obj_vardnsrecdegdnspolseq_removezeroes (a, n, args);
}

static int 
obj_vardnsrecdegdnspolseq_ooaddmulsc (obj_vardnsrecdegdnspolseq_t c, obj_vardnsrecdegdnspolseq_t a, int an, int v, obj_vardnsrecdegdnspolseq_t b, int bn, obj_t t, int w, obj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      objseq_ooaddmulsc (c, a, v, b, t, w, an, args.sargs);
      return obj_vardnsrecdegdnspolseq_removezeroes (c, an, args);
    }
  else
    {
      if (an < bn)
	{
	  objseq_ooaddmulsc (c, a, v, b, t, w, an, args.sargs);
	  c += an * obj_size (args.sargs);
	  b += an * obj_size (args.sargs);
	  objseq_oomulscv (c, b, t, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  objseq_ooaddmulsc (c, a, v, b, t, w, bn, args.sargs);
	  c += bn * obj_size (args.sargs);
	  a += bn * obj_size (args.sargs);
	  objseq_oonegv (c, a, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static int 
obj_vardnsrecdegdnspolseq_inaddmulsc (obj_vardnsrecdegdnspolseq_t a, int an, int v, obj_vardnsrecdegdnspolseq_t b, int bn, obj_t t, int w, obj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      objseq_inaddmulsc (a, v, b, t, w, an, args.sargs);
      return obj_vardnsrecdegdnspolseq_removezeroes (a, an, args);
    }
  else
    {
      if (an < bn)
	{
	  objseq_inaddmulsc (a, v, b, t, w, an, args.sargs);
	  a += an * obj_size (args.sargs);
	  b += an * obj_size (args.sargs);
	  objseq_oomulscv (a, b, t, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  objseq_inaddmulsc (a, v, b, t, w, bn, args.sargs);
	  a += bn * obj_size (args.sargs);
	  objseq_innegv (a, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static int 
obj_vardnsrecdegdnspolseq_oomulscadd (obj_vardnsrecdegdnspolseq_t c, obj_vardnsrecdegdnspolseq_t a, int an, obj_t s, int v, obj_vardnsrecdegdnspolseq_t b, int bn, int w, obj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      objseq_oomulscadd (c, a, s, v, b, w, an, args.sargs);
      return obj_vardnsrecdegdnspolseq_removezeroes (c, an, args);
    }
  else
    {
      if (an < bn)
	{
	  objseq_oomulscadd (c, a, s, v, b, w, an, args.sargs);
	  c += an * obj_size (args.sargs);
	  b += an * obj_size (args.sargs);
	  objseq_oonegv (c, b, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  objseq_oomulscadd (c, a, s, v, b, w, bn, args.sargs);
	  c += bn * obj_size (args.sargs);
	  a += bn * obj_size (args.sargs);
	  objseq_oomulscv (c, a, s, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static int 
obj_vardnsrecdegdnspolseq_inmulscadd (obj_vardnsrecdegdnspolseq_t a, int an, obj_t s, int v, obj_vardnsrecdegdnspolseq_t b, int bn, int w, obj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      objseq_inmulscadd (a, s, v, b, w, an, args.sargs);
      return obj_vardnsrecdegdnspolseq_removezeroes (a, an, args);
    }
  else
    {
      if (an < bn)
	{
	  objseq_inmulscadd (a, s, v, b, w, an, args.sargs);
	  a += an * obj_size (args.sargs);
	  b += an * obj_size (args.sargs);
	  objseq_oonegv (a, b, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  objseq_inmulscadd (a, s, v, b, w, bn, args.sargs);
	  a += bn * obj_size (args.sargs);
	  objseq_inmulscv (a, s, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static int 
obj_vardnsrecdegdnspolseq_oomulscaddmulsc (obj_vardnsrecdegdnspolseq_t c, obj_vardnsrecdegdnspolseq_t a, int an, obj_t s, int v, obj_vardnsrecdegdnspolseq_t b, int bn, obj_t t, int w, obj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      objseq_oomulscaddmulsc (c, a, s, v, b, t, w, an, args.sargs);
      return obj_vardnsrecdegdnspolseq_removezeroes (c, an, args);
    }
  else
    {
      if (an < bn)
	{
	  objseq_oomulscaddmulsc (c, a, s, v, b, t, w, an, args.sargs);
	  c += an * obj_size (args.sargs);
	  b += an * obj_size (args.sargs);
	  objseq_oomulscv (c, b, t, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  objseq_oomulscaddmulsc (c, a, s, v, b, t, w, bn, args.sargs);
	  c += bn * obj_size (args.sargs);
	  a += bn * obj_size (args.sargs);
	  objseq_oomulscv (c, a, s, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static int 
obj_vardnsrecdegdnspolseq_inmulscaddmulsc (obj_vardnsrecdegdnspolseq_t a, int an, obj_t s, int v, obj_vardnsrecdegdnspolseq_t b, int bn, obj_t t, int w, obj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      objseq_inmulscaddmulsc (a, s, v, b, t, w, an, args.sargs);
      return obj_vardnsrecdegdnspolseq_removezeroes (a, an, args);
    }
  else
    {
      if (an < bn)
	{
	  objseq_inmulscaddmulsc (a, s, v, b, t, w, an, args.sargs);
	  a += an * obj_size (args.sargs);
	  b += an * obj_size (args.sargs);
	  objseq_oomulscv (a, b, t, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  objseq_inmulscaddmulsc (a, s, v, b, t, w, bn, args.sargs);
	  a += bn * obj_size (args.sargs);
	  objseq_inmulscv (a, s, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static BOOL 
obj_vardnsrecdegdnspolseq_oodivsc (obj_vardnsrecdegdnspolseq_t c, obj_vardnsrecdegdnspolseq_t a, int n, obj_t s, obj_vardnsrecdegdnspol_args args)
{
  return objseq_oodivsc (c, a, s, n, args.sargs);
}

static int 
obj_vardnsrecdegdnspolseq_indivsc (obj_vardnsrecdegdnspolseq_t a, int n, obj_t s, obj_vardnsrecdegdnspol_args args)
{
  objseq_indivsc (a, s, n, args.sargs);
  return n;
}

static int 
obj_vardnsrecdegdnspolseq_oomulmonomsc (obj_vardnsrecdegdnspolseq_t c, obj_vardnsrecdegdnspolseq_t a, int n, int m, obj_t s, int v, obj_vardnsrecdegdnspol_args args)
{
  objseq_oozero (c, m, args.sargs);
  c += m * obj_size (args.sargs);
  objseq_oomulscv (c, a, s, v, n, args.sargs);
  return n + m;
}

static BOOL 
obj_vardnsrecdegdnspolseq_oodivmonomsc (obj_vardnsrecdegdnspolseq_t c, obj_vardnsrecdegdnspolseq_t a, int n, int m, obj_t s, obj_vardnsrecdegdnspol_args args)
{
  assert (n >= m);
  a += m * obj_size (args.sargs);
  return objseq_oodivsc (c, a, s, n - m, args.sargs);
}

static int 
obj_vardnsrecdegdnspolseq_ooaddmulmonomsc (obj_vardnsrecdegdnspolseq_t c, obj_vardnsrecdegdnspolseq_t a, int an, int v, obj_vardnsrecdegdnspolseq_t b, int bn, int m, obj_t t, int w, obj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn + m)
    {
      assert (an >= m);
      objseq_oonegv (c, a, v, m, args.sargs);
      c += m * obj_size (args.sargs);
      a += m * obj_size (args.sargs);
      assert (an >= bn);
      objseq_ooaddmulsc (c, a, v, b, t, w, bn, args.sargs);
      c -= m * obj_size (args.sargs);
      return obj_vardnsrecdegdnspolseq_removezeroes (c, an, args);
    }
  else
    {
      if (an < bn + m)
	{
	  if (an < m)
	    {
	      objseq_oonegv (c, a, v, an, args.sargs);
	      c += an * obj_size (args.sargs);
	      a += an * obj_size (args.sargs);
	      objseq_oozero (c, m - an, args.sargs);
	      c += (m - an) * obj_size (args.sargs);
	      objseq_oomulscv (c, b, t, w, bn, args.sargs);
	    }
	  else
	    {
	      assert (an >= m);
	      objseq_oonegv (c, a, v, m, args.sargs);
	      c += m * obj_size (args.sargs);
	      a += m * obj_size (args.sargs);
	      assert (bn > an - m);
	      objseq_ooaddmulsc (c, a, v, b, t, w, an - m, args.sargs);
	      c += (an - m) * obj_size (args.sargs);
	      b += (an - m) * obj_size (args.sargs);
	      objseq_oomulscv (c, b, t, w, bn - (an - m), args.sargs);
	    }
	  return bn + m;
	}
      else
	{
	  assert (an >= m);
	  objseq_oonegv (c, a, v, m, args.sargs);
	  c += m * obj_size (args.sargs);
	  a += m * obj_size (args.sargs);
	  assert (an >= bn);
	  objseq_ooaddmulsc (c, a, v, b, t, w, bn, args.sargs);
	  c += bn * obj_size (args.sargs);
	  a += bn * obj_size (args.sargs);
	  assert (an > bn + m);
	  objseq_oonegv (c, a, v, an - bn - m, args.sargs);
	  return an;
	}
    }
}

static int 
obj_vardnsrecdegdnspolseq_inaddmulmonomsc (obj_vardnsrecdegdnspolseq_t a, int an, int v, obj_vardnsrecdegdnspolseq_t b, int bn, int m, obj_t t, int w, obj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn + m)
    {
      assert (an >= m);
      objseq_innegv (a, v, m, args.sargs);
      a += m * obj_size (args.sargs);
      assert (an >= bn);
      objseq_inaddmulsc (a, v, b, t, w, bn, args.sargs);
      a -= m * obj_size (args.sargs);
      return obj_vardnsrecdegdnspolseq_removezeroes (a, an, args);
    }
  else
    {
      if (an < bn + m)
	{
	  if (an < m)
	    {
	      objseq_innegv (a, v, an, args.sargs);
	      a += an * obj_size (args.sargs);
	      objseq_oozero (a, m - an, args.sargs);
	      a += (m - an) * obj_size (args.sargs);
	      objseq_oomulscv (a, b, t, w, bn, args.sargs);
	    }
	  else
	    {
	      assert (an >= m);
	      objseq_innegv (a, v, m, args.sargs);
	      a += m * obj_size (args.sargs);
	      assert (bn > an - m);
	      objseq_inaddmulsc (a, v, b, t, w, an - m, args.sargs);
	      a += (an - m) * obj_size (args.sargs);
	      objseq_oomulscv (a, b, t, w, bn - (an - m), args.sargs);
	    }
	  return bn + m;
	}
      else
	{
	  assert (an >= m);
	  objseq_innegv (a, v, m, args.sargs);
	  a += m * obj_size (args.sargs);
	  assert (an >= bn);
	  objseq_inaddmulsc (a, v, b, t, w, bn, args.sargs);
	  a += bn * obj_size (args.sargs);
	  assert (an > bn + m);
	  objseq_innegv (a, v, an - bn - m, args.sargs);
	  return an;
	}
    }
}

static int 
obj_vardnsrecdegdnspolseq_oomulscaddmulmonomsc (obj_vardnsrecdegdnspolseq_t c, obj_vardnsrecdegdnspolseq_t a, int an, obj_t s, int v, obj_vardnsrecdegdnspolseq_t b, int bn, int m, obj_t t, int w, obj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn + m)
    {
      assert (an >= m);
      objseq_oomulscv (c, a, s, v, m, args.sargs);
      c += m * obj_size (args.sargs);
      a += m * obj_size (args.sargs);
      assert (an >= bn);
      objseq_oomulscaddmulsc (c, a, s, v, b, t, w, bn, args.sargs);
      c -= m * obj_size (args.sargs);
      return obj_vardnsrecdegdnspolseq_removezeroes (c, an, args);
    }
  else
    {
      if (an < bn + m)
	{
	  if (an < m)
	    {
	      objseq_oomulscv (c, a, s, v, an, args.sargs);
	      c += an * obj_size (args.sargs);
	      a += an * obj_size (args.sargs);
	      objseq_oozero (c, m - an, args.sargs);
	      c += (m - an) * obj_size (args.sargs);
	      objseq_oomulscv (c, b, t, w, bn, args.sargs);
	    }
	  else
	    {
	      assert (an >= m);
	      objseq_oomulscv (c, a, s, v, m, args.sargs);
	      c += m * obj_size (args.sargs);
	      a += m * obj_size (args.sargs);
	      assert (bn > an - m);
	      objseq_oomulscaddmulsc (c, a, s, v, b, t, w, an - m, args.sargs);
	      c += (an - m) * obj_size (args.sargs);
	      a += (an - m) * obj_size (args.sargs);
	      b += (an - m) * obj_size (args.sargs);
	      objseq_oomulscv (c, b, t, w, bn - (an - m), args.sargs);
	    }
	  return bn + m;
	}
      else
	{
	  assert (an >= m);
	  objseq_oomulscv (c, a, s, v, m, args.sargs);
	  c += m * obj_size (args.sargs);
	  a += m * obj_size (args.sargs);
	  assert (an >= bn);
	  objseq_oomulscaddmulsc (c, a, s, v, b, t, w, bn, args.sargs);
	  c += bn * obj_size (args.sargs);
	  a += bn * obj_size (args.sargs);
	  assert (an > bn + m);
	  objseq_oomulscv (c, a, s, v, an - bn - m, args.sargs);
	  return an;
	}
    }
}

static int 
obj_vardnsrecdegdnspolseq_inmulscaddmulmonomsc (obj_vardnsrecdegdnspolseq_t a, int an, obj_t s, int v, obj_vardnsrecdegdnspolseq_t b, int bn, int m, obj_t t, int w, obj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn + m)
    {
      assert (an >= m);
      objseq_inmulscv (a, s, v, m, args.sargs);
      a += m * obj_size (args.sargs);
      assert (an >= bn);
      objseq_inmulscaddmulsc (a, s, v, b, t, w, bn, args.sargs);
      a -= m * obj_size (args.sargs);
      return obj_vardnsrecdegdnspolseq_removezeroes (a, an, args);
    }
  else
    {
      if (an < bn + m)
	{
	  if (an < m)
	    {
	      objseq_inmulscv (a, s, v, an, args.sargs);
	      a += an * obj_size (args.sargs);
	      objseq_oozero (a, m - an, args.sargs);
	      a += m * obj_size (args.sargs);
	      objseq_oomulscv (a, b, t, w, bn, args.sargs);
	    }
	  else
	    {
	      assert (an >= m);
	      objseq_inmulscv (a, s, v, m, args.sargs);
	      a += m * obj_size (args.sargs);
	      assert (bn > an - m);
	      objseq_inmulscaddmulsc (a, s, v, b, t, w, an - m, args.sargs);
	      a += (an - m) * obj_size (args.sargs);
	      objseq_oomulscv (a, b, t, w, bn - (an - m), args.sargs);
	    }
	  return bn + m;
	}
      else
	{
	  assert (an >= m);
	  objseq_inmulscv (a, s, v, m, args.sargs);
	  a += m * obj_size (args.sargs);
	  assert (an >= bn);
	  objseq_inmulscaddmulsc (a, s, v, b, t, w, bn, args.sargs);
	  a += bn * obj_size (args.sargs);
	  assert (an > bn + m);
	  objseq_inmulscv (a, s, v, an - bn - m, args.sargs);
	  return an;
	}
    }
}

static void 
obj_vardnsrecdegdnspol_ix_init (obj_vardnsrecdegdnspol_ixt ix, id self)
{
  obj_vardnsrecdegdnspol_t v = [self obj_vardnsrecdegdnspol_value];
  ix->i = -1;
  ix->n = v->n;
}

static void 
obj_vardnsrecdegdnspol_ix_clear (obj_vardnsrecdegdnspol_ixt ix)
{
  /* nothing to clear */
}

static int 
obj_vardnsrecdegdnspol_ix_count (obj_vardnsrecdegdnspol_ixt ix)
{
  return ix->n;			/* total number, zero or nonzero */
}

static int 
obj_vardnsrecdegdnspol_ix_isempty (obj_vardnsrecdegdnspol_ixt ix)
{
  return ix->n == 0;
}

static int 
obj_vardnsrecdegdnspol_ix_ismatch (obj_vardnsrecdegdnspol_ixt ix)
{
  assert (-1 <= ix->i && ix->i <= ix->n);
  return (ix->i != -1 && ix->i != ix->n);
}

static void 
obj_vardnsrecdegdnspol_ix_tofirst (obj_vardnsrecdegdnspol_ixt ix)
{
  ix->i = -1;			/* next = first */
}

static void 
obj_vardnsrecdegdnspol_ix_tolast (obj_vardnsrecdegdnspol_ixt ix)
{
  ix->i = ix->n;		/* prev = last */
}

static void 
obj_vardnsrecdegdnspol_ix_to (obj_vardnsrecdegdnspol_ixt ix, int i)
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
obj_vardnsrecdegdnspol_ix_next (obj_vardnsrecdegdnspol_ixt ix)
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
obj_vardnsrecdegdnspol_ix_prev (obj_vardnsrecdegdnspol_ixt ix)
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
obj_vardnsrecdegdnspol_check (obj_vardnsrecdegdnspol_t self, obj_vardnsrecdegdnspol_args args)
{
  assert (self->n <= self->c);
  return obj_vardnsrecdegdnspolseq_check (self->ptr, self->n, args);
}

static obj_vardnsrecdegdnspol_args 
obj_vardnsrecdegdnspol_getargs (id self)
{
  obj_vardnsrecdegdnspol_args res;
  res.sargs = obj_getargs ([[self termZero] coefficient]);
  return res;
}

static obj_vardnsrecdegdnspol_t 
obj_vardnsrecdegdnspol_id2t (id object)
{
  return [object obj_vardnsrecdegdnspol_value];
}

static obj_vardnsrecdegdnspol_c *
obj_vardnsrecdegdnspol_id2c (id object)
{
  return [object obj_vardnsrecdegdnspol_reference];
}

static id 
obj_vardnsrecdegdnspol_t2id (id proto, obj_vardnsrecdegdnspol_t f)
{
  return [proto obj_vardnsrecdegdnspol_value:f];
}

static id 
obj_vardnsrecdegdnspol_c2id (id proto, obj_vardnsrecdegdnspol_c * r)
{
  return [proto obj_vardnsrecdegdnspol_reference:r];
}

static int 
obj_vardnsrecdegdnspol_isempty (obj_vardnsrecdegdnspol_t self)
{
  return self->n == 0;
}

static void 
obj_vardnsrecdegdnspol_init (obj_vardnsrecdegdnspol_t self, int c, obj_vardnsrecdegdnspol_args args)
{
  self->n = 0;
  self->c = c;
  self->ptr = objseq_alloc (c, args.sargs);
  assert (obj_vardnsrecdegdnspol_check (self, args));
}

static void 
obj_vardnsrecdegdnspol_copy (obj_vardnsrecdegdnspol_t c, obj_vardnsrecdegdnspol_t a, obj_vardnsrecdegdnspol_args args)
{
  assert (obj_vardnsrecdegdnspol_check (a, args));
  obj_vardnsrecdegdnspol_init (c, a->n, args);
  c->n = obj_vardnsrecdegdnspolseq_copy (c->ptr, a->ptr, a->n, args);
  assert (obj_vardnsrecdegdnspol_check (c, args));
}

static void 
obj_vardnsrecdegdnspol_deepcopy (obj_vardnsrecdegdnspol_t c, obj_vardnsrecdegdnspol_t a, obj_vardnsrecdegdnspol_args args)
{
  assert (obj_vardnsrecdegdnspol_check (a, args));
  obj_vardnsrecdegdnspol_init (c, a->n, args);
  c->n = obj_vardnsrecdegdnspolseq_deepcopy (c->ptr, a->ptr, a->n, args);
  assert (obj_vardnsrecdegdnspol_check (c, args));
}

static void 
obj_vardnsrecdegdnspol_move (obj_vardnsrecdegdnspol_t c, obj_vardnsrecdegdnspol_t a, obj_vardnsrecdegdnspol_args args)
{
  c->ptr = a->ptr;
  c->n = a->n;
  c->c = a->c;
  a->ptr = NULL;
  assert (obj_vardnsrecdegdnspol_check (c, args));
}

static void 
obj_vardnsrecdegdnspol_destroy (obj_vardnsrecdegdnspol_t self, obj_vardnsrecdegdnspol_args args)
{
  /* needed e.g. after a failed oodiv operation */
  self->ptr = objseq_free (self->ptr, args.sargs);
}

static void 
obj_vardnsrecdegdnspol_clear (obj_vardnsrecdegdnspol_t self, obj_vardnsrecdegdnspol_args args)
{
  objseq_clear (self->ptr, self->n, args.sargs);
  obj_vardnsrecdegdnspol_destroy (self, args);
}

static int 
obj_vardnsrecdegdnspol_count (obj_vardnsrecdegdnspol_t self, obj_vardnsrecdegdnspol_args args)
{
  return obj_vardnsrecdegdnspolseq_count (self->ptr, self->n, args);	/* num non-zero coefs */
}

static unsigned 
obj_vardnsrecdegdnspol_hash (obj_vardnsrecdegdnspol_t a, obj_vardnsrecdegdnspol_args args)
{
  return obj_vardnsrecdegdnspolseq_hash (a->ptr, a->n, args);
}

static int 
obj_vardnsrecdegdnspol_iseq (obj_vardnsrecdegdnspol_t a, obj_vardnsrecdegdnspol_t b, obj_vardnsrecdegdnspol_args args)
{
  return (a == b) ? YES : obj_vardnsrecdegdnspolseq_iseq (a->ptr, a->n, b->ptr, b->n, args);
}

static int 
obj_vardnsrecdegdnspol_isone (obj_vardnsrecdegdnspol_t self, obj_vardnsrecdegdnspol_args args)
{
  return obj_vardnsrecdegdnspolseq_isone (self->ptr, self->n, args);
}

static int 
obj_vardnsrecdegdnspol_isminusone (obj_vardnsrecdegdnspol_t self, obj_vardnsrecdegdnspol_args args)
{
  return obj_vardnsrecdegdnspolseq_isminusone (self->ptr, self->n, args);
}

static int 
obj_vardnsrecdegdnspol_deg (obj_vardnsrecdegdnspol_t self, obj_vardnsrecdegdnspol_args args)
{
  return self->n - 1;
}

static int 
obj_vardnsrecdegdnspol_ord (obj_vardnsrecdegdnspol_t self, obj_vardnsrecdegdnspol_args args)
{
  return obj_vardnsrecdegdnspolseq_ord (self->ptr, self->n, args);
}

static int 
obj_vardnsrecdegdnspol_maxdeg (obj_vardnsrecdegdnspol_t self, obj_vardnsrecdegdnspol_args args)
{
  return self->n - 1;
}

static int 
obj_vardnsrecdegdnspol_mindeg (obj_vardnsrecdegdnspol_t self, obj_vardnsrecdegdnspol_args args)
{
  return obj_vardnsrecdegdnspolseq_ord (self->ptr, self->n, args);
}

static obj_t 
obj_vardnsrecdegdnspol_scalat (obj_vardnsrecdegdnspol_t self, obj_vardnsrecdegdnspol_ixt ix, obj_vardnsrecdegdnspol_args args)
{
  assert (obj_vardnsrecdegdnspol_ix_ismatch (ix) && ix->n == self->n);
  return objseq_at (self->ptr, ix->n - ix->i - 1, args.sargs);
}

static int 
obj_vardnsrecdegdnspol_expat (obj_vardnsrecdegdnspol_t self, obj_vardnsrecdegdnspol_ixt ix, obj_vardnsrecdegdnspol_args args)
{
  assert (obj_vardnsrecdegdnspol_ix_ismatch (ix) && ix->n == self->n);
  return ix->n - ix->i - 1;
}

static obj_t 
obj_vardnsrecdegdnspol_scalfirst (obj_vardnsrecdegdnspol_t self, obj_vardnsrecdegdnspol_args args)
{
  assert (obj_vardnsrecdegdnspol_isempty (self) == NO);
  return objseq_last (self->ptr, self->n, args.sargs);
}

static int 
obj_vardnsrecdegdnspol_expfirst (obj_vardnsrecdegdnspol_t self, obj_vardnsrecdegdnspol_args args)
{
  assert (obj_vardnsrecdegdnspol_isempty (self) == NO);
  return self->n - 1;
}

static void 
obj_vardnsrecdegdnspol_expand (obj_vardnsrecdegdnspol_t self, obj_vardnsrecdegdnspol_args args)
{
  int oldc = self->c;
  self->c = self->n + self->c + 1;
  self->ptr = objseq_realloc (self->ptr, oldc, self->c, args.sargs);
  assert (self->n < self->c);
}

static void 
obj_vardnsrecdegdnspol_remove (obj_vardnsrecdegdnspol_t self, obj_vardnsrecdegdnspol_args args)
{
  assert (obj_vardnsrecdegdnspol_check (self, args) && obj_vardnsrecdegdnspol_isempty (self) == NO);
  self->n = obj_vardnsrecdegdnspolseq_delete (self->ptr, self->n, args);
  assert (obj_vardnsrecdegdnspol_check (self, args));
}

static void 
obj_vardnsrecdegdnspol_insert (obj_vardnsrecdegdnspol_t self, int e, obj_t s, obj_vardnsrecdegdnspol_args args)
{
  assert (obj_vardnsrecdegdnspol_check (self, args));
  while (self->c < e + 1)
    obj_vardnsrecdegdnspol_expand (self, args);
  self->n = obj_vardnsrecdegdnspolseq_insert (self->ptr, self->n, e, s, args);
  assert (obj_vardnsrecdegdnspol_check (self, args));
}

static int 
obj_vardnsrecdegdnspol_iszero (obj_vardnsrecdegdnspol_t self, obj_vardnsrecdegdnspol_args args)
{
  return obj_vardnsrecdegdnspol_isempty (self);
}

static int 
obj_vardnsrecdegdnspol_isop (obj_vardnsrecdegdnspol_t a, obj_vardnsrecdegdnspol_t b, obj_vardnsrecdegdnspol_args args)
{
  assert (a != b);
  return obj_vardnsrecdegdnspolseq_isop (a->ptr, a->n, b->ptr, b->n, args);
}

static void 
obj_vardnsrecdegdnspol_ooneg (obj_vardnsrecdegdnspol_t c, obj_vardnsrecdegdnspol_t a, obj_vardnsrecdegdnspol_args args)
{
  obj_vardnsrecdegdnspol_init (c, a->n, args);
  c->n = obj_vardnsrecdegdnspolseq_ooneg (c->ptr, a->ptr, a->n, args);
  assert (obj_vardnsrecdegdnspol_check (c, args));
}

static void 
obj_vardnsrecdegdnspol_inneg (obj_vardnsrecdegdnspol_t a, obj_vardnsrecdegdnspol_args args)
{
  a->n = obj_vardnsrecdegdnspolseq_inneg (a->ptr, a->n, args);
  assert (obj_vardnsrecdegdnspol_check (a, args));
}

static void 
obj_vardnsrecdegdnspol_oodbl (obj_vardnsrecdegdnspol_t c, obj_vardnsrecdegdnspol_t a, int v, obj_vardnsrecdegdnspol_args args)
{
  obj_vardnsrecdegdnspol_init (c, a->n, args);
  c->n = obj_vardnsrecdegdnspolseq_oodbl (c->ptr, a->ptr, a->n, v, args);
  assert (obj_vardnsrecdegdnspol_check (c, args));
}

static void 
obj_vardnsrecdegdnspol_indbl (obj_vardnsrecdegdnspol_t a, int v, obj_vardnsrecdegdnspol_args args)
{
  obj_vardnsrecdegdnspolseq_indbl (a->ptr, a->n, v, args);
  assert (obj_vardnsrecdegdnspol_check (a, args));
}

static void 
obj_vardnsrecdegdnspol_ooadd (obj_vardnsrecdegdnspol_t c, obj_vardnsrecdegdnspol_t a, int v, obj_vardnsrecdegdnspol_t b, int w, obj_vardnsrecdegdnspol_args args)
{
  assert (a != b);
  obj_vardnsrecdegdnspol_init (c, MAX (a->n, b->n), args);
  c->n = obj_vardnsrecdegdnspolseq_ooadd (c->ptr, a->ptr, a->n, v, b->ptr, b->n, w, args);
  assert (obj_vardnsrecdegdnspol_check (c, args));
}

static void 
obj_vardnsrecdegdnspol_inadd (obj_vardnsrecdegdnspol_t a, int v, obj_vardnsrecdegdnspol_t b, int w, obj_vardnsrecdegdnspol_args args)
{
  assert (a != b);
  while (a->c < b->n)
    obj_vardnsrecdegdnspol_expand (a, args);
  a->n = obj_vardnsrecdegdnspolseq_inadd (a->ptr, a->n, v, b->ptr, b->n, w, args);
  assert (obj_vardnsrecdegdnspol_check (a, args));
}

static void 
obj_vardnsrecdegdnspol_oomulsc (obj_vardnsrecdegdnspol_t c, obj_vardnsrecdegdnspol_t a, obj_t s, obj_vardnsrecdegdnspol_args args)
{
  obj_vardnsrecdegdnspol_init (c, a->n, args);
  c->n = obj_vardnsrecdegdnspolseq_oomulsc (c->ptr, a->ptr, a->n, s, args);
  assert (obj_vardnsrecdegdnspol_check (c, args));
}

static void 
obj_vardnsrecdegdnspol_inmulsc (obj_vardnsrecdegdnspol_t a, obj_t s, obj_vardnsrecdegdnspol_args args)
{
  a->n = obj_vardnsrecdegdnspolseq_inmulsc (a->ptr, a->n, s, args);
  assert (obj_vardnsrecdegdnspol_check (a, args));
}

static void 
obj_vardnsrecdegdnspol_ooaddmulsc (obj_vardnsrecdegdnspol_t c, obj_vardnsrecdegdnspol_t a, int v, obj_vardnsrecdegdnspol_t b, obj_t t, int w, obj_vardnsrecdegdnspol_args args)
{
  obj_vardnsrecdegdnspol_init (c, MAX (a->n, b->n), args);
  c->n = obj_vardnsrecdegdnspolseq_ooaddmulsc (c->ptr, a->ptr, a->n, v, b->ptr, b->n, t, w, args);
  assert (obj_vardnsrecdegdnspol_check (c, args));
}

static void 
obj_vardnsrecdegdnspol_inaddmulsc (obj_vardnsrecdegdnspol_t a, int v, obj_vardnsrecdegdnspol_t b, obj_t t, int w, obj_vardnsrecdegdnspol_args args)
{
  while (a->c < b->n)
    obj_vardnsrecdegdnspol_expand (a, args);
  a->n = obj_vardnsrecdegdnspolseq_inaddmulsc (a->ptr, a->n, v, b->ptr, b->n, t, w, args);
  assert (obj_vardnsrecdegdnspol_check (a, args));
}

static void 
obj_vardnsrecdegdnspol_oomulscadd (obj_vardnsrecdegdnspol_t c, obj_vardnsrecdegdnspol_t a, obj_t s, int v, obj_vardnsrecdegdnspol_t b, int w, obj_vardnsrecdegdnspol_args args)
{
  obj_vardnsrecdegdnspol_init (c, MAX (a->n, b->n), args);
  c->n = obj_vardnsrecdegdnspolseq_oomulscadd (c->ptr, a->ptr, a->n, s, v, b->ptr, b->n, w, args);
  assert (obj_vardnsrecdegdnspol_check (c, args));
}

static void 
obj_vardnsrecdegdnspol_inmulscadd (obj_vardnsrecdegdnspol_t a, obj_t s, int v, obj_vardnsrecdegdnspol_t b, int w, obj_vardnsrecdegdnspol_args args)
{
  while (a->c < b->n)
    obj_vardnsrecdegdnspol_expand (a, args);
  a->n = obj_vardnsrecdegdnspolseq_inmulscadd (a->ptr, a->n, s, v, b->ptr, b->n, w, args);
  assert (obj_vardnsrecdegdnspol_check (a, args));
}

static void 
obj_vardnsrecdegdnspol_oomulscaddmulsc (obj_vardnsrecdegdnspol_t c, obj_vardnsrecdegdnspol_t a, obj_t s, int v, obj_vardnsrecdegdnspol_t b, obj_t t, int w, obj_vardnsrecdegdnspol_args args)
{
  obj_vardnsrecdegdnspol_init (c, MAX (a->n, b->n), args);
  c->n = obj_vardnsrecdegdnspolseq_oomulscaddmulsc (c->ptr, a->ptr, a->n, s, v, b->ptr, b->n, t, w, args);
  assert (obj_vardnsrecdegdnspol_check (c, args));
}

static void 
obj_vardnsrecdegdnspol_inmulscaddmulsc (obj_vardnsrecdegdnspol_t a, obj_t s, int v, obj_vardnsrecdegdnspol_t b, obj_t t, int w, obj_vardnsrecdegdnspol_args args)
{
  while (a->c < b->n)
    obj_vardnsrecdegdnspol_expand (a, args);
  a->n = obj_vardnsrecdegdnspolseq_inmulscaddmulsc (a->ptr, a->n, s, v, b->ptr, b->n, t, w, args);
  assert (obj_vardnsrecdegdnspol_check (a, args));
}

static BOOL 
obj_vardnsrecdegdnspol_oodivsc (obj_vardnsrecdegdnspol_t c, obj_vardnsrecdegdnspol_t a, obj_t s, obj_vardnsrecdegdnspol_args args)
{
  BOOL failed;
  obj_vardnsrecdegdnspol_init (c, a->n, args);
  failed = obj_vardnsrecdegdnspolseq_oodivsc (c->ptr, a->ptr, a->n, s, args);
  if (failed)
    {
      /* the actual scalars are already freed */
      obj_vardnsrecdegdnspol_destroy (c, args);
    }
  else
    {
      c->n = a->n;
      assert (obj_vardnsrecdegdnspol_check (c, args));
    }
  return failed;
}

static void 
obj_vardnsrecdegdnspol_indivsc (obj_vardnsrecdegdnspol_t a, obj_t s, obj_vardnsrecdegdnspol_args args)
{
  a->n = obj_vardnsrecdegdnspolseq_indivsc (a->ptr, a->n, s, args);
  assert (obj_vardnsrecdegdnspol_check (a, args));
}

static void 
obj_vardnsrecdegdnspol_oomulmonomsc (obj_vardnsrecdegdnspol_t c, obj_vardnsrecdegdnspol_t b, unimonom_t m, obj_t t, int w, obj_vardnsrecdegdnspol_args args)
{
  obj_vardnsrecdegdnspol_init (c, b->n + m, args);
  c->n = obj_vardnsrecdegdnspolseq_oomulmonomsc (c->ptr, b->ptr, b->n, m, t, w, args);
  assert (obj_vardnsrecdegdnspol_check (c, args));
}

static void 
obj_vardnsrecdegdnspol_inmulmonomsc (obj_vardnsrecdegdnspol_t b, unimonom_t m, obj_t t, int w, obj_vardnsrecdegdnspol_args args)
{
  obj_vardnsrecdegdnspol_c tmp;
  obj_vardnsrecdegdnspol_oomulmonomsc (&tmp, b, m, t, w, args);
  obj_vardnsrecdegdnspol_clear (b, args);
  obj_vardnsrecdegdnspol_move (b, &tmp, args);
}

static void 
obj_vardnsrecdegdnspol_ooaddmulmonomsc (obj_vardnsrecdegdnspol_t c, obj_vardnsrecdegdnspol_t a, int v, obj_vardnsrecdegdnspol_t b, unimonom_t m, obj_t t, int w, obj_vardnsrecdegdnspol_args args)
{
  obj_vardnsrecdegdnspol_init (c, MAX (a->n, b->n + m), args);
  c->n = obj_vardnsrecdegdnspolseq_ooaddmulmonomsc (c->ptr, a->ptr, a->n, v, b->ptr, b->n, m, t, w, args);
  assert (obj_vardnsrecdegdnspol_check (c, args));
}

static void 
obj_vardnsrecdegdnspol_inaddmulmonomsc (obj_vardnsrecdegdnspol_t a, int v, obj_vardnsrecdegdnspol_t b, unimonom_t m, obj_t t, int w, obj_vardnsrecdegdnspol_args args)
{
  while (a->c < b->n + m)
    obj_vardnsrecdegdnspol_expand (a, args);
  a->n = obj_vardnsrecdegdnspolseq_inaddmulmonomsc (a->ptr, a->n, v, b->ptr, b->n, m, t, w, args);
  assert (obj_vardnsrecdegdnspol_check (a, args));
}

static void 
obj_vardnsrecdegdnspol_oomulscaddmulmonomsc (obj_vardnsrecdegdnspol_t c, obj_vardnsrecdegdnspol_t a, obj_t s, int v, obj_vardnsrecdegdnspol_t b, unimonom_t m, obj_t t, int w, obj_vardnsrecdegdnspol_args args)
{
  obj_vardnsrecdegdnspol_init (c, MAX (a->n, b->n + m), args);
  c->n = obj_vardnsrecdegdnspolseq_oomulscaddmulmonomsc (c->ptr, a->ptr, a->n, s, v, b->ptr, b->n, m, t, w, args);
  assert (obj_vardnsrecdegdnspol_check (c, args));
}

static void 
obj_vardnsrecdegdnspol_inmulscaddmulmonomsc (obj_vardnsrecdegdnspol_t a, obj_t s, int v, obj_vardnsrecdegdnspol_t b, unimonom_t m, obj_t t, int w, obj_vardnsrecdegdnspol_args args)
{
  a->n = obj_vardnsrecdegdnspolseq_inmulscaddmulmonomsc (a->ptr, a->n, s, v, b->ptr, b->n, m, t, w, args);
  assert (obj_vardnsrecdegdnspol_check (a, args));
}

static BOOL 
obj_vardnsrecdegdnspol_oodivmonomsc (obj_vardnsrecdegdnspol_t c, obj_vardnsrecdegdnspol_t b, unimonom_t m, obj_t t, obj_vardnsrecdegdnspol_args args)
{
  if (obj_vardnsrecdegdnspol_ord (b, args) < m)
    {
      return FAILURE;
    }
  else
    {
      BOOL failed;
      obj_vardnsrecdegdnspol_init (c, b->n - m, args);
      failed = obj_vardnsrecdegdnspolseq_oodivmonomsc (c->ptr, b->ptr, b->n, m, t, args);
      if (failed)
	{
	  /* the actual scalars are already freed */
	  obj_vardnsrecdegdnspol_destroy (c, args);
	}
      else
	{
	  c->n = b->n - m;
	  assert (obj_vardnsrecdegdnspol_check (c, args));
	}
      return failed;
    }
}

static void 
obj_vardnsrecdegdnspol_indivmonomsc (obj_vardnsrecdegdnspol_t b, unimonom_t m, obj_t t, obj_vardnsrecdegdnspol_args args)
{
  obj_vardnsrecdegdnspol_c tmp;
  BOOL failed = obj_vardnsrecdegdnspol_oodivmonomsc (&tmp, b, m, t, args);
  if (failed)
    {
      fprintf (stderr, "Exact Division Failed");
      abort ();
    }
  obj_vardnsrecdegdnspol_clear (b, args);
  obj_vardnsrecdegdnspol_move (b, &tmp, args);
}

static void 
obj_vardnsrecdegdnspol_args_fileOut (id aFiler, obj_vardnsrecdegdnspol_args * args)
{
  objseq_args_fileOut (aFiler, &args->sargs);
}
static void 
obj_vardnsrecdegdnspol_args_fileIn (id aFiler, obj_vardnsrecdegdnspol_args * args)
{
  objseq_args_fileIn (aFiler, &args->sargs);
}

static void 
obj_vardnsrecdegdnspol_fileOut (id aFiler, obj_vardnsrecdegdnspol_t self, obj_vardnsrecdegdnspol_args args)
{
  int n = self->n;
  [aFiler fileOut:&n type:'i'];
  assert (obj_vardnsrecdegdnspol_check (self, args));
  objseq_fileOut (aFiler, self->ptr, n, args.sargs);
}

static void 
obj_vardnsrecdegdnspol_fileIn (id aFiler, obj_vardnsrecdegdnspol_t self, obj_vardnsrecdegdnspol_args args)
{
  int n;
  [aFiler fileIn:&n type:'i'];
  obj_vardnsrecdegdnspol_init (self, n, args);
  objseq_fileIn (aFiler, self->ptr, n, args.sargs);
  self->n = n;
  assert (self->n == n && obj_vardnsrecdegdnspol_check (self, args));
}

@implementation obj_vardnsrecdegdns_polynomial : vardnsrecdegdns_polynomial

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

  obj_vardnsrecdegdnspol_init (&value, 2 /* capacity */ , obj_vardnsrecdegdnspol_getargs (self));
  assert ([self check]);
  return self;
}

+ scalarZero:aScalar coefficientZero:aCoef symbols:aCltn
{
  return [[super new] _setUpScalarZero:aScalar coefficientZero:aCoef symbols:aCltn];
}

- empty
{
  obj_vardnsrecdegdnspol_c c;
  assert ([self check]);
  obj_vardnsrecdegdnspol_init (&c, 2 /* capacity */ , obj_vardnsrecdegdnspol_getargs (self));
  return obj_vardnsrecdegdnspol_c2id (self, &c);
}

- (int) numTerms
{
  /* doesn't take getargs in degsps case */
  assert ([self check]);
  return obj_vardnsrecdegdnspol_count (&value, obj_vardnsrecdegdnspol_getargs (self));
}

- (obj_vardnsrecdegdnspol_t)obj_vardnsrecdegdnspol_value
{
  return &value;
}

- doobj_vardnsrecdegdnspol_value:(obj_vardnsrecdegdnspol_t)aValue
{
  obj_vardnsrecdegdnspol_copy (&value, aValue, obj_vardnsrecdegdnspol_getargs (self));
  assert ([self check]);
  return self;
}

- obj_vardnsrecdegdnspol_value:(obj_vardnsrecdegdnspol_t)aValue
{
  return [[self clone] doobj_vardnsrecdegdnspol_value:aValue];
}

- (obj_vardnsrecdegdnspol_t)obj_vardnsrecdegdnspol_reference
{
  return &value;
}

- doobj_vardnsrecdegdnspol_reference:(obj_vardnsrecdegdnspol_c *)aReference
{
  obj_vardnsrecdegdnspol_move (&value, aReference, obj_vardnsrecdegdnspol_getargs (self));
  assert ([self check]);
  return self;
}

- obj_vardnsrecdegdnspol_reference:(obj_vardnsrecdegdnspol_c *)aReference
{
  return [[self clone] doobj_vardnsrecdegdnspol_reference:aReference];
}

- copy
{
  obj_vardnsrecdegdnspol_c c;
  assert ([self check]);
  obj_vardnsrecdegdnspol_copy (&c, &value, obj_vardnsrecdegdnspol_getargs (self));
  return obj_vardnsrecdegdnspol_c2id (self, &c);
}

- deepCopy
{
  obj_vardnsrecdegdnspol_c c;
  assert ([self check]);
  obj_vardnsrecdegdnspol_deepcopy (&c, &value, obj_vardnsrecdegdnspol_getargs (self));
  return obj_vardnsrecdegdnspol_c2id (self, &c);
}

- (BOOL) isEmpty
{
  return obj_vardnsrecdegdnspol_isempty (&value);
}

- (BOOL) isOne
{
  return obj_vardnsrecdegdnspol_isone (&value, obj_vardnsrecdegdnspol_getargs (self));
}

- (BOOL) isMinusOne
{
  return obj_vardnsrecdegdnspol_isminusone (&value, obj_vardnsrecdegdnspol_getargs (self));
}

- (unsigned) hash
{
  return obj_vardnsrecdegdnspol_hash (obj_vardnsrecdegdnspol_id2t (self), obj_vardnsrecdegdnspol_getargs (self));
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
      return obj_vardnsrecdegdnspol_iseq (obj_vardnsrecdegdnspol_id2t (self), obj_vardnsrecdegdnspol_id2t (b), obj_vardnsrecdegdnspol_getargs (self));
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
      return !obj_vardnsrecdegdnspol_iseq (obj_vardnsrecdegdnspol_id2t (self), obj_vardnsrecdegdnspol_id2t (b), obj_vardnsrecdegdnspol_getargs (self));
    }
}

- (BOOL) isZero
{
  assert ([self check]);
  return obj_vardnsrecdegdnspol_iszero (obj_vardnsrecdegdnspol_id2t (self), obj_vardnsrecdegdnspol_getargs (self));
}

- (BOOL) notZero
{
  assert ([self check]);
  return !obj_vardnsrecdegdnspol_iszero (obj_vardnsrecdegdnspol_id2t (self), obj_vardnsrecdegdnspol_getargs (self));
}

- (BOOL) isOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return obj_vardnsrecdegdnspol_isop (obj_vardnsrecdegdnspol_id2t (self), obj_vardnsrecdegdnspol_id2t (b), obj_vardnsrecdegdnspol_getargs (self));
}

- (BOOL) notOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return !obj_vardnsrecdegdnspol_isop (obj_vardnsrecdegdnspol_id2t (self), obj_vardnsrecdegdnspol_id2t (b), obj_vardnsrecdegdnspol_getargs (self));
}

- negate
{
  obj_vardnsrecdegdnspol_c c;
  assert ([self check]);
  obj_vardnsrecdegdnspol_ooneg (&c, obj_vardnsrecdegdnspol_id2t (self), obj_vardnsrecdegdnspol_getargs (self));
  return obj_vardnsrecdegdnspol_c2id (self, &c);
}

- _double:(int)v
{
  obj_vardnsrecdegdnspol_c c;
  assert ([self check]);
  obj_vardnsrecdegdnspol_oodbl (&c, obj_vardnsrecdegdnspol_id2t (self), v, obj_vardnsrecdegdnspol_getargs (self));
  return obj_vardnsrecdegdnspol_c2id (self, &c);
}

- double
{
  obj_vardnsrecdegdnspol_c c;
  assert ([self check]);
  obj_vardnsrecdegdnspol_oodbl (&c, obj_vardnsrecdegdnspol_id2t (self), +1, obj_vardnsrecdegdnspol_getargs (self));
  return obj_vardnsrecdegdnspol_c2id (self, &c);
}

- _add:(int)v:b:(int)w
{
  obj_vardnsrecdegdnspol_c c;
  assert ([self sameClass:b] && v * v == 1 && w * w == 1 && self != b);
  obj_vardnsrecdegdnspol_ooadd (&c, obj_vardnsrecdegdnspol_id2t (self), v, obj_vardnsrecdegdnspol_id2t (b), w, obj_vardnsrecdegdnspol_getargs (self));
  return obj_vardnsrecdegdnspol_c2id (self, &c);
}

- add:b
{
  obj_vardnsrecdegdnspol_c c;
  assert ([self checkSameClass:b] && self != b);
  obj_vardnsrecdegdnspol_ooadd (&c, obj_vardnsrecdegdnspol_id2t (self), +1, obj_vardnsrecdegdnspol_id2t (b), +1, obj_vardnsrecdegdnspol_getargs (self));
  return obj_vardnsrecdegdnspol_c2id (self, &c);
}

- subtract:b
{
  obj_vardnsrecdegdnspol_c c;
  assert ([self checkSameClass:b] && self != b);
  obj_vardnsrecdegdnspol_ooadd (&c, obj_vardnsrecdegdnspol_id2t (self), +1, obj_vardnsrecdegdnspol_id2t (b), -1, obj_vardnsrecdegdnspol_getargs (self));
  return obj_vardnsrecdegdnspol_c2id (self, &c);
}

- (int) leadingDegree
{
  return obj_vardnsrecdegdnspol_deg (&value, obj_vardnsrecdegdnspol_getargs (self));
}

- (int) lastDegree
{
  return obj_vardnsrecdegdnspol_ord (&value, obj_vardnsrecdegdnspol_getargs (self));
}

- (int) maxDegree
{
  return obj_vardnsrecdegdnspol_maxdeg (&value, obj_vardnsrecdegdnspol_getargs (self));
}

- (int) minDegree
{
  return obj_vardnsrecdegdnspol_mindeg (&value, obj_vardnsrecdegdnspol_getargs (self));
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

  obj_vardnsrecdegdnspol_check (&value, obj_vardnsrecdegdnspol_getargs (self));
  return self;
}

- release
{
  obj_vardnsrecdegdnspol_clear (&value, obj_vardnsrecdegdnspol_getargs (self));
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
  id aSequence = [obj_vardnsrecdegdnspol_sequence content:self];
  return [CASequence over:aSequence];
}

- elt_obj_vardnsrecdegdnspol_ix:(obj_vardnsrecdegdnspol_ixt)ix
{
  if (obj_vardnsrecdegdnspol_ix_ismatch (ix))
    {
      id c, s;
      int e;
      obj_t t;
      t = obj_vardnsrecdegdnspol_scalat (&value, ix, obj_vardnsrecdegdnspol_getargs (self));
      e = obj_vardnsrecdegdnspol_expat (&value, ix, obj_vardnsrecdegdnspol_getargs (self));
      c = obj_t2id ([termZero coefficient], t);
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
      obj_t t;
      assert ([self check]);

      t = obj_vardnsrecdegdnspol_scalfirst (&value, obj_vardnsrecdegdnspol_getargs (self));
      e = obj_vardnsrecdegdnspol_expfirst (&value, obj_vardnsrecdegdnspol_getargs (self));
      c = obj_t2id ([termZero coefficient], t);
      s = (e) ? [termZero symbol] : nil;
      lt = [termZero coefficient:c symbol:s exponent:e];

      obj_vardnsrecdegdnspol_remove (&value, obj_vardnsrecdegdnspol_getargs (self));
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
      obj_c c;
      obj_t r;
      int e;
      assert ([aTerm check]);
      assert ([self check]);
      r = obj_id2ref ([aTerm coefficient], &c);
      e = [aTerm exponent];
      obj_vardnsrecdegdnspol_insert (&value, e, r, obj_vardnsrecdegdnspol_getargs (self));
      assert ([aTerm check]);
      [self invalidate];
      assert ([self check]);
      return self;
    }
}

- multiplyCoefficient:s
{
  obj_vardnsrecdegdnspol_c c;
  obj_c sc;
  obj_vardnsrecdegdnspol_oomulsc (&c, obj_vardnsrecdegdnspol_id2t (self), obj_id2ref (s, &sc), obj_vardnsrecdegdnspol_getargs (self));
  return obj_vardnsrecdegdnspol_c2id (self, &c);
}

- divideCoefficient:s
{
  obj_vardnsrecdegdnspol_c c;
  obj_c sc;
  BOOL failed = obj_vardnsrecdegdnspol_oodivsc (&c, obj_vardnsrecdegdnspol_id2t (self), obj_id2ref (s, &sc), obj_vardnsrecdegdnspol_getargs (self));
  return (failed) ? nil : obj_vardnsrecdegdnspol_c2id (self, &c);
}

- _add:(int)v:B multiplyCoefficient:b:(int)w
{
  obj_vardnsrecdegdnspol_c c;
  obj_c bc;
  obj_vardnsrecdegdnspol_ooaddmulsc (&c, obj_vardnsrecdegdnspol_id2t (self), v, obj_vardnsrecdegdnspol_id2t (B), obj_id2ref (b, &bc), w, obj_vardnsrecdegdnspol_getargs (self));
  return obj_vardnsrecdegdnspol_c2id (self, &c);
}

- _multiplyCoefficient:a:(int)v add:B:(int)w
{
  obj_vardnsrecdegdnspol_c c;
  obj_c ac;
  obj_vardnsrecdegdnspol_oomulscadd (&c, obj_vardnsrecdegdnspol_id2t (self), obj_id2ref (a, &ac), v, obj_vardnsrecdegdnspol_id2t (B), w, obj_vardnsrecdegdnspol_getargs (self));
  return obj_vardnsrecdegdnspol_c2id (self, &c);
}

- _multiplyCoefficient:a:(int)v add:B multiplyCoefficient:b:(int)w
{
  obj_vardnsrecdegdnspol_c c;
  obj_c ac, bc;
  obj_vardnsrecdegdnspol_oomulscaddmulsc (&c, obj_vardnsrecdegdnspol_id2t (self), obj_id2ref (a, &ac), v, obj_vardnsrecdegdnspol_id2t (B), obj_id2ref (b, &bc), w, obj_vardnsrecdegdnspol_getargs (self));
  return obj_vardnsrecdegdnspol_c2id (self, &c);
}

- multiplyTerm:aTerm
{
  obj_vardnsrecdegdnspol_c c;
  obj_t s;
  obj_c sc;
  s = obj_id2ref ([aTerm coefficient], &sc);
  obj_vardnsrecdegdnspol_oomulmonomsc (&c, obj_vardnsrecdegdnspol_id2t (self), [aTerm exponent], s, +1, obj_vardnsrecdegdnspol_getargs (self));
  return obj_vardnsrecdegdnspol_c2id (self, &c);
}

- _multiplyTerm:aTerm:(int)v
{
  obj_vardnsrecdegdnspol_c c;
  obj_t s;
  obj_c sc;
  s = obj_id2ref ([aTerm coefficient], &sc);
  obj_vardnsrecdegdnspol_oomulmonomsc (&c, obj_vardnsrecdegdnspol_id2t (self), [aTerm exponent], s, v, obj_vardnsrecdegdnspol_getargs (self));
  return obj_vardnsrecdegdnspol_c2id (self, &c);
}

- divideTerm:aTerm
{
  int e;
  obj_vardnsrecdegdnspol_c c;
  BOOL failed;
  obj_t s;
  obj_c sc;

  e = [aTerm exponent];
  s = obj_id2ref ([aTerm coefficient], &sc);
  failed = obj_vardnsrecdegdnspol_oodivmonomsc (&c, obj_vardnsrecdegdnspol_id2t (self), e, s, obj_vardnsrecdegdnspol_getargs (self));
  return (failed) ? nil : obj_vardnsrecdegdnspol_c2id (self, &c);
}

- _add:(int)v:B multiplyTerm:b:(int)w
{
  obj_vardnsrecdegdnspol_c c;
  obj_c bc;
  obj_t bs;
  bs = obj_id2ref ([b coefficient], &bc);
  obj_vardnsrecdegdnspol_ooaddmulmonomsc (&c, obj_vardnsrecdegdnspol_id2c (self), v, obj_vardnsrecdegdnspol_id2t (B), [b exponent], bs, w, obj_vardnsrecdegdnspol_getargs (self));
  return obj_vardnsrecdegdnspol_c2id (self, &c);
}

- _multiplyCoefficient:a:(int)v add:B multiplyTerm:b:(int)w
{
  obj_vardnsrecdegdnspol_c c;
  obj_c ac, bc;
  obj_t as, bs;
  as = obj_id2ref (a, &ac);
  bs = obj_id2ref ([b coefficient], &bc);
  obj_vardnsrecdegdnspol_oomulscaddmulmonomsc (&c, obj_vardnsrecdegdnspol_id2c (self), as, v, obj_vardnsrecdegdnspol_id2t (B), [b exponent], bs, w, obj_vardnsrecdegdnspol_getargs (self));
  return obj_vardnsrecdegdnspol_c2id (self, &c);
}


- fileOutOn:aFiler
{
  obj_vardnsrecdegdnspol_args args;
  [super fileOutOn:aFiler];
  args = obj_vardnsrecdegdnspol_getargs (self);		/* can't do this in fileIn case */
  obj_vardnsrecdegdnspol_args_fileOut (aFiler, &args);
  obj_vardnsrecdegdnspol_fileOut (aFiler, &value, args);
  return self;
}

- fileInFrom:aFiler
{
  obj_vardnsrecdegdnspol_args args;
  [super fileInFrom:aFiler];
  obj_vardnsrecdegdnspol_args_fileIn (aFiler, &args);
  obj_vardnsrecdegdnspol_fileIn (aFiler, &value, args);
  return self;
}

@end
 
