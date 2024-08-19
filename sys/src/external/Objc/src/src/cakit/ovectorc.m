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
 * $Id: ovectorc.m,v 1.6 2000/10/12 14:40:26 stes Exp $
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

static objvec_args 
objvec_getargs (id self)
{
  objvec_args args;
  args.sargs = obj_getargs ([self scalarZero]);
  return args;
}

static int 
objvec_check (objvec_t self, objvec_args args)
{
  assert (0 <= self->n && self->n <= self->c);
  objseq_check (self->ptr, self->n, args.sargs);
  return 1;
}

static objvec_t 
objvec_id2t (id object)
{
  return [object objvec_value];
}

static objvec_c *
objvec_id2c (id object)
{
  return [object objvec_reference];
}

static id 
objvec_t2id (id proto, objvec_t f)
{
  return [proto objvec_value:f];
}

static id 
objvec_c2id (id proto, objvec_c * r)
{
  return [proto objvec_reference:r];
}

static void 
objvec_init (objvec_t self, int n, objvec_args args)
{
  self->n = n;
  self->c = n;
  self->ptr = objseq_alloc (n, args.sargs);
}

static void 
objvec_initcount (objvec_t c, int n, objvec_args args)
{
  objvec_init (c, n, args);
  objseq_oozero (c->ptr, n, args.sargs);
}

static void 
objvec_initcapacity (objvec_t self, int n, objvec_args args)
{
  self->n = 0;
  self->c = n;
  self->ptr = objseq_alloc (n, args.sargs);
}

static void 
objvec_copy (objvec_t c, objvec_t a, objvec_args args)
{
  objvec_init (c, a->n, args);
  objseq_copy (c->ptr, a->ptr, a->n, args.sargs);
}

static void 
objvec_deepcopy (objvec_t c, objvec_t a, objvec_args args)
{
  objvec_init (c, a->n, args);
  objseq_deepcopy (c->ptr, a->ptr, a->n, args.sargs);
}

static void 
objvec_move (objvec_t c, objvec_t a, objvec_args args)
{
  c->n = a->n;
  c->c = a->c;
  c->ptr = a->ptr;
  a->ptr = NULL;
}

static void 
objvec_destroy (objvec_t self, objvec_args args)
{
  /*
   * clearing memory allocated by objvec_init after a failed operation
   * can't do a objseq_clear in that case as the handler doesnt know
   * what elements have been allocated
   */

  self->ptr = objseq_free (self->ptr, args.sargs);
}

static void 
objvec_clear (objvec_t self, objvec_args args)
{
  objseq_clear (self->ptr, self->n, args.sargs);
  objvec_destroy (self, args);
}

static int 
objvec_count (objvec_t self)
{
  return self->n;
}

static unsigned 
objvec_hash (objvec_t a, objvec_args args)
{
  return objseq_hash (a->ptr, a->n, args.sargs);
}

static int 
objvec_iseq (objvec_t a, objvec_t b, objvec_args args)
{
  assert (a != b);
  return (a->n == b->n && objseq_iseq (a->ptr, b->ptr, a->n, args.sargs));
}

static void 
objvec_expand (objvec_t self, objvec_args args)
{
  int oldc = self->c;
  assert (self->n == self->c);
  self->c = self->n + self->c + 1;
  self->ptr = objseq_realloc (self->ptr, oldc, self->c, args.sargs);
  assert (self->n < self->c);
}

static void 
objvec_insertfirst (objvec_t self, obj_t a, objvec_args args)
{
  assert (self->n <= self->c);
  if (self->n == self->c)
    objvec_expand (self, args);
  self->n = objseq_insertlast (self->ptr, a, self->n, args.sargs);
}

static void 
objvec_insertat (objvec_t self, obj_t a, int i, objvec_args args)
{
  assert (0 < i && i <= self->n && self->n <= self->c);
  if (self->n == self->c)
    objvec_expand (self, args);

  if (i == self->n)
    {
      self->n = objseq_insertfirst (self->ptr, a, self->n, args.sargs);
    }
  else
    {
      self->n = objseq_insertat (self->ptr, a, self->n - i - 1, self->n, args.sargs);
    }
}

static void 
objvec_place (objvec_t self, obj_t a, int i, objvec_args args)
{
  assert (0 <= i && i < self->n);
  objseq_place (self->ptr, a, self->n - i - 1, args.sargs);
}

static void 
objvec_freefirst (objvec_t self, objvec_args args)
{
  assert (self->n > 0);
  self->n = objseq_freelast (self->ptr, self->n, args.sargs);
}

static void 
objvec_freeat (objvec_t self, int i, objvec_args args)
{
  assert (0 < i && i < self->n);
  self->n = objseq_freeat (self->ptr, self->n - i - 1, self->n, args.sargs);
}


static obj_t 
objvec_at (objvec_t self, int ix, objvec_args args)
{
  assert (0 <= ix && ix < self->n);
  return objseq_at (self->ptr, self->n - ix - 1, args.sargs);
}

static obj_t 
objvec_first (objvec_t self, objvec_args args)
{
  assert (self->n > 0);
  return objseq_last (self->ptr, self->n, args.sargs);
}

static obj_t 
objvec_elt (objvec_t self, objvec_ixt ix, objvec_args args)
{
  assert (ix->n == self->n);
  return objvec_at (self, ix->i, args);
}

static int 
objvec_iszero (objvec_t self, objvec_args args)
{
  return objseq_iszero (self->ptr, self->n, args.sargs);
}

static int 
objvec_isop (objvec_t a, objvec_t b, objvec_args args)
{
  assert (a != b);
  return (a->n == b->n && objseq_isop (a->ptr, b->ptr, a->n, args.sargs));
}

static void 
objvec_ooneg (objvec_t c, objvec_t a, objvec_args args)
{
  objvec_init (c, a->n, args);
  objseq_ooneg (c->ptr, a->ptr, a->n, args.sargs);
}

static void 
objvec_inneg (objvec_t a, objvec_args args)
{
  objseq_inneg (a->ptr, a->n, args.sargs);
}

static void 
objvec_oodbl (objvec_t c, objvec_t a, int v, objvec_args args)
{
  objvec_init (c, a->n, args);
  objseq_oodbl (c->ptr, a->ptr, v, a->n, args.sargs);
}

static void 
objvec_indbl (objvec_t a, int v, objvec_args args)
{
  objseq_indbl (a->ptr, v, a->n, args.sargs);
}

static void 
objvec_checkcount (int a, int b)
{
  if (a != b)
    {
      fprintf (stderr, "Vector : Dimensions Not Equal\n");
      abort ();
    }
}

static void 
objvec_ooadd (objvec_t c, objvec_t a, int v, objvec_t b, int w, objvec_args args)
{
  assert (a != b);
  objvec_checkcount (a->n, b->n);
  objvec_init (c, a->n, args);
  objseq_ooadd (c->ptr, a->ptr, v, b->ptr, w, a->n, args.sargs);
}

static void 
objvec_inadd (objvec_t a, int v, objvec_t b, int w, objvec_args args)
{
  assert (a != b);
  objvec_checkcount (a->n, b->n);
  objseq_inadd (a->ptr, v, b->ptr, w, a->n, args.sargs);
}

static void 
objvec_oomulsc (objvec_t c, objvec_t a, obj_t s, objvec_args args)
{
  objvec_init (c, a->n, args);
  objseq_oomulsc (c->ptr, a->ptr, s, a->n, args.sargs);
}

static void 
objvec_inmulsc (objvec_t a, obj_t s, objvec_args args)
{
  objseq_inmulsc (a->ptr, s, a->n, args.sargs);
}

static void 
objvec_ooaddmulsc (objvec_t c, objvec_t a, int v, objvec_t b, obj_t s, int w, objvec_args args)
{
  assert (a != b);
  objvec_checkcount (a->n, b->n);
  objvec_init (c, a->n, args);
  objseq_ooaddmulsc (c->ptr, a->ptr, v, b->ptr, s, w, a->n, args.sargs);
}

static void 
objvec_inaddmulsc (objvec_t a, int v, objvec_t b, obj_t s, int w, objvec_args args)
{
  assert (a != b);
  objvec_checkcount (a->n, b->n);
  objseq_inaddmulsc (a->ptr, v, b->ptr, s, w, a->n, args.sargs);
}

static void 
objvec_oomulscadd (objvec_t c, objvec_t a, obj_t s, int v, objvec_t b, int w, objvec_args args)
{
  assert (a != b);
  objvec_checkcount (a->n, b->n);
  objvec_init (c, a->n, args);
  objseq_oomulscadd (c->ptr, a->ptr, s, v, b->ptr, w, a->n, args.sargs);
}

static void 
objvec_inmulscadd (objvec_t a, obj_t s, int v, objvec_t b, int w, objvec_args args)
{
  assert (a != b);
  objvec_checkcount (a->n, b->n);
  objseq_inmulscadd (a->ptr, s, v, b->ptr, w, a->n, args.sargs);
}

static void 
objvec_oomulscaddmulsc (objvec_t c, objvec_t a, obj_t s, int v, objvec_t b, obj_t t, int w, objvec_args args)
{
  assert (a != b);
  objvec_checkcount (a->n, b->n);
  objvec_init (c, a->n, args);
  objseq_oomulscaddmulsc (c->ptr, a->ptr, s, v, b->ptr, t, w, a->n, args.sargs);
}

static void 
objvec_inmulscaddmulsc (objvec_t a, obj_t s, int v, objvec_t b, obj_t t, int w, objvec_args args)
{
  assert (a != b);
  objvec_checkcount (a->n, b->n);
  objseq_inmulscaddmulsc (a->ptr, s, v, b->ptr, t, w, a->n, args.sargs);
}

static BOOL 
objvec_oodivsc (objvec_t c, objvec_t a, obj_t s, objvec_args args)
{
  BOOL failed;

  objvec_init (c, a->n, args);
  failed = objseq_oodivsc (c->ptr, a->ptr, s, a->n, args.sargs);
  if (failed)
    objvec_destroy (c, args);

  return failed;
}

static void 
objvec_indivsc (objvec_t a, obj_t s, objvec_args args)
{
  objseq_indivsc (a->ptr, s, a->n, args.sargs);
}

static void 
objvec_oodotmul (obj_c * c, objvec_t a, objvec_t b, objvec_args args)
{
  assert (a != b);
  objvec_checkcount (a->n, b->n);
  objseq_oodotmul (c, a->ptr, b->ptr, a->n, args.sargs);
}

static void 
objvec_oodotsqr (obj_c * c, objvec_t a, objvec_args args)
{
  objseq_oodotsqr (c, a->ptr, a->n, args.sargs);
}

static void 
objvec_args_fileOut (id aFiler, objvec_args * args)
{
  objseq_args_fileOut (aFiler, &args->sargs);
}
static void 
objvec_args_fileIn (id aFiler, objvec_args * args)
{
  objseq_args_fileIn (aFiler, &args->sargs);
}

static void 
objvec_fileOut (id aFiler, objvec_t self, objvec_args args)
{
  [aFiler fileOut:&self->n type:'i'];
  objseq_fileOut (aFiler, self->ptr, self->n, args.sargs);
}

static void 
objvec_fileIn (id aFiler, objvec_t self, objvec_args args)
{
  int n;
  [aFiler fileIn:&n type:'i'];
  objvec_init (self, n, args);
  objseq_fileIn (aFiler, self->ptr, self->n, args.sargs);
}

static void 
objvec_ix_init (objvec_ixt ix, id self)
{
  objvec_t v = [self objvec_value];
  ix->n = v->n;
}

static void 
objvec_ix_copy (objvec_ixt c, objvec_ixt a)
{
  c->i = a->i;
  c->n = a->n;
}

static void 
objvec_ix_clear (objvec_ixt ix)
{
  /* nothing to clear */
}

static int 
objvec_ix_count (objvec_ixt ix)
{
  return ix->n;
}

static int 
objvec_ix_isempty (objvec_ixt ix)
{
  return ix->n == 0;
}

static int 
objvec_ix_ismatch (objvec_ixt ix)
{
  assert (-1 <= ix->i && ix->i <= ix->n);
  return 0 <= ix->i && ix->i < ix->n;
}

static void 
objvec_ix_tofirst (objvec_ixt ix)
{
  ix->i = -1;			/* next -> first */
}

static void 
objvec_ix_tolast (objvec_ixt ix)
{
  ix->i = ix->n;		/* prev -> last */
}

static void 
objvec_ix_to (objvec_ixt ix, int i)
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
objvec_ix_next (objvec_ixt ix)
{
  ix->i = (ix->i < ix->n) ? ix->i + 1 : ix->n;
}

static void 
objvec_ix_prev (objvec_ixt ix)
{
  ix->i = (0 <= ix->i) ? ix->i - 1 : -1;
}
@implementation obj_vector : vectorc

- check
{
  [super check];
  [scalarZero check];
  objvec_check (&value, objvec_getargs (self));
  return self;
}


- _setUpScalarZero:aScalarZero numScalars:(int)numScalars
{
  scalarZero = aScalarZero;
  objvec_initcount (&value, numScalars, objvec_getargs (self));
  assert ([self check]);
  return self;
}

+ scalarZero:aScalarZero numScalars:(int)numScalars
{
  return [[super new] _setUpScalarZero:aScalarZero numScalars:numScalars];
}

- copy
{
  objvec_c c;
  assert ([self check]);
  objvec_copy (&c, &value, objvec_getargs (self));
  return objvec_c2id (self, &c);
}

- deepCopy
{
  objvec_c c;
  assert ([self check]);
  objvec_deepcopy (&c, &value, objvec_getargs (self));
  return objvec_c2id (self, &c);
}

- release
{
  objvec_clear (&value, objvec_getargs (self));
  return [super release];
}

- (objvec_t)objvec_value
{
  return &value;
}

- doobjvec_value:(objvec_t)aValue
{
  objvec_copy (&value, aValue, objvec_getargs (self));
  assert ([self check]);
  return self;
}

- objvec_value:(objvec_t)aValue
{
  return [[self clone] doobjvec_value:aValue];
}

- (objvec_t)objvec_reference
{
  return &value;
}

- doobjvec_reference:(objvec_c *)aReference
{
  objvec_move (&value, aReference, objvec_getargs (self));
  assert ([self check]);
  return self;
}

- objvec_reference:(objvec_c *)aReference
{
  return [[self clone] doobjvec_reference:aReference];
}

- capacity:(int)aCapacity
{
  objvec_c c;
  assert ([self check]);
  objvec_initcapacity (&c, aCapacity, objvec_getargs (self));
  return objvec_c2id (self, &c);
}

- numScalars:(int)numScalars
{
  objvec_c c;
  assert ([self check]);
  objvec_initcount (&c, numScalars, objvec_getargs (self));
  return objvec_c2id (self, &c);
}


- scalarZero
{
  return scalarZero;
}

- (int) numScalars
{
  assert ([self check]);
  return objvec_count (&value);
}


- insertScalar:aScalar
{
  obj_c c;
  assert ([aScalar check]);
  assert ([self check]);
  objvec_insertfirst (&value, obj_id2ref (aScalar, &c), objvec_getargs (self));
  assert ([aScalar check]);
  assert ([self check]);
  [self invalidate];
  return self;
}

- insertScalar:aScalar at:(int)i
{
  obj_c c;
  assert (aScalar);
  assert ([self check]);
  objvec_insertat (&value, obj_id2ref (aScalar, &c), i, objvec_getargs (self));
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
      obj_t t = objvec_first (&value, objvec_getargs (self));
      assert ([self check]);
      res = obj_t2id (scalarZero, t);
      objvec_freefirst (&value, objvec_getargs (self));
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
  res = obj_t2id (scalarZero, objvec_at (&value, i, objvec_getargs (self)));
  objvec_freeat (&value, i, objvec_getargs (self));
  assert ([self check]);
  assert ([res check]);
  [self invalidate];
  return res;
}


- placeScalar:aScalar at:(int)i
{
  obj_c c;
  assert ([aScalar check]);
  assert ([self check]);
  objvec_place (&value, obj_id2ref (aScalar, &c), i, objvec_getargs (self));
  assert ([aScalar check]);
  assert ([self check]);
  [self invalidate];
  return self;
}

- replaceScalarAt:(int)i with:aScalar
{
  id res;
  obj_c c;
  obj_t t = objvec_at (&value, i, objvec_getargs (self));
  assert ([self check]);
  res = obj_t2id (scalarZero, t);
  objvec_place (&value, obj_id2ref (aScalar, &c), i, objvec_getargs (self));
  assert ([aScalar check]);
  assert ([self check]);
  assert ([res check]);
  [self invalidate];
  return res;
}


- eachScalar
{
  id aSequence = [objvec_sequence content:self];
  return [CASequence over:aSequence];
}

- elt_objvec_ix:(objvec_ixt)ix
{
  if (objvec_ix_ismatch (ix))
    {
      obj_t t = objvec_elt (&value, ix, objvec_getargs (self));
      return obj_t2id (scalarZero, t);
    }
  else
    {
      return nil;
    }
}


- dotMultiply:b
{
  obj_c c;			/* carrier for scalar */
  objvec_oodotmul (&c, &value, [b objvec_value], objvec_getargs (self));
  /* now promote the carrier to object */
  /* all of this used to be very difficult in 0.6 */
  return obj_c2id (scalarZero, &c);
}

- dotSquare
{
  obj_c c;			/* carrier for scalar */
  objvec_oodotsqr (&c, &value, objvec_getargs (self));
  /* now promote the carrier to object */
  /* all of this used to be very difficult in 0.6 */
  return obj_c2id (scalarZero, &c);
}


- fileOutOn:aFiler
{
  objvec_args args;
  assert ([self check]);
  [super fileOutOn:aFiler];
  args = objvec_getargs (self);
  objvec_args_fileOut (aFiler, &args);
  objvec_fileOut (aFiler, &value, args);
  return self;
}

- fileInFrom:aFiler
{
  objvec_args args;
  [super fileInFrom:aFiler];
  objvec_args_fileIn (aFiler, &args);
  objvec_fileIn (aFiler, &value, args);
  return self;
}

- (unsigned) hash
{
  return objvec_hash (objvec_id2t (self), objvec_getargs (self));
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
      return objvec_iseq (objvec_id2t (self), objvec_id2t (b), objvec_getargs (self));
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
      return !objvec_iseq (objvec_id2t (self), objvec_id2t (b), objvec_getargs (self));
    }
}

- (BOOL) isZero
{
  assert ([self check]);
  return objvec_iszero (objvec_id2t (self), objvec_getargs (self));
}

- (BOOL) notZero
{
  assert ([self check]);
  return !objvec_iszero (objvec_id2t (self), objvec_getargs (self));
}

- (BOOL) isOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return objvec_isop (objvec_id2t (self), objvec_id2t (b), objvec_getargs (self));
}

- (BOOL) notOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return !objvec_isop (objvec_id2t (self), objvec_id2t (b), objvec_getargs (self));
}

- negate
{
  objvec_c c;
  assert ([self check]);
  objvec_ooneg (&c, objvec_id2t (self), objvec_getargs (self));
  return objvec_c2id (self, &c);
}

- _double:(int)v
{
  objvec_c c;
  assert ([self check]);
  objvec_oodbl (&c, objvec_id2t (self), v, objvec_getargs (self));
  return objvec_c2id (self, &c);
}

- double
{
  objvec_c c;
  assert ([self check]);
  objvec_oodbl (&c, objvec_id2t (self), +1, objvec_getargs (self));
  return objvec_c2id (self, &c);
}

- _add:(int)v:b:(int)w
{
  objvec_c c;
  assert ([self sameClass:b] && v * v == 1 && w * w == 1 && self != b);
  objvec_ooadd (&c, objvec_id2t (self), v, objvec_id2t (b), w, objvec_getargs (self));
  return objvec_c2id (self, &c);
}

- add:b
{
  objvec_c c;
  assert ([self checkSameClass:b] && self != b);
  objvec_ooadd (&c, objvec_id2t (self), +1, objvec_id2t (b), +1, objvec_getargs (self));
  return objvec_c2id (self, &c);
}

- subtract:b
{
  objvec_c c;
  assert ([self checkSameClass:b] && self != b);
  objvec_ooadd (&c, objvec_id2t (self), +1, objvec_id2t (b), -1, objvec_getargs (self));
  return objvec_c2id (self, &c);
}

- multiplyScalar:s
{
  objvec_c c;
  obj_c sc;
  objvec_oomulsc (&c, objvec_id2t (self), obj_id2ref (s, &sc), objvec_getargs (self));
  return objvec_c2id (self, &c);
}

- divideScalar:s
{
  objvec_c c;
  obj_c sc;
  BOOL failed = objvec_oodivsc (&c, objvec_id2t (self), obj_id2ref (s, &sc), objvec_getargs (self));
  return (failed) ? nil : objvec_c2id (self, &c);
}

- _add:(int)v:B multiplyScalar:b:(int)w
{
  objvec_c c;
  obj_c bc;
  assert ([self sameClass:B] && [scalarZero sameClass:b] && v * v == 1 && w * w == 1);
  objvec_ooaddmulsc (&c, objvec_id2t (self), v, objvec_id2t (B), obj_id2ref (b, &bc), w, objvec_getargs (self));
  return objvec_c2id (self, &c);
}

- _multiplyScalar:a:(int)v add:B:(int)w
{
  objvec_c c;
  obj_c ac;
  assert ([scalarZero sameClass:a] && [self sameClass:B] && v * v == 1 && w * w == 1);
  objvec_oomulscadd (&c, objvec_id2t (self), obj_id2ref (a, &ac), v, objvec_id2t (B), w, objvec_getargs (self));
  return objvec_c2id (self, &c);
}

- _multiplyScalar:a:(int)v add:B multiplyScalar:b:(int)w
{
  objvec_c c;
  obj_c ac, bc;
  assert ([scalarZero sameClass:a] && [self sameClass:B] && [scalarZero sameClass:b] && v * v == 1 && w * w == 1);
  objvec_oomulscaddmulsc (&c, objvec_id2t (self), obj_id2ref (a, &ac), v, objvec_id2t (B), obj_id2ref (b, &bc), w, objvec_getargs (self));
  return objvec_c2id (self, &c);
}

@end
 
