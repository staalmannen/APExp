#include "cakit.h"

#define VAL_MIN -32500
#define VAL_MAX +32500

static int 
bigintobj_check (bigintobj_t self, bigintobj_args args)
{
  assert (args.proto);
  [args.proto check];

  assert (VAL_MIN == -VAL_MAX);	/* for opposite tests */
  assert (VAL_MAX * VAL_MAX + VAL_MAX * VAL_MAX < INT_MAX);
  assert (VAL_MIN * VAL_MAX - VAL_MIN * VAL_MAX > INT_MIN);

  if (self->hit)
    {
      assert (VAL_MIN <= self->val && self->val <= VAL_MAX);
      if (self->obj)
	{
	  id obj = [args.proto intValue:self->val];
	  assert ([obj isEqual:self->obj]);
	}
    }
  else
    {
      int val;
      id obj = self->obj;
      assert ([obj check]);
      val = [obj intValue];
      assert (val < VAL_MIN || VAL_MAX < val);
    }

  return 1;
}

/*
 * return new reference to object or create it if necessary
 */

static id 
bigintobj_obj (bigintobj_t self, bigintobj_args args)
{
  assert (bigintobj_check (self, args));

  if (self->obj)
    {
      return self->obj;
    }
  else
    {
      id obj;
      assert (self->hit);
      obj = [args.proto intValue:self->val];
      assert ([obj intValue] == self->val);
      return obj;
    }
}

/*
 * works inplace on "self"; creates object if it doesn't exists; returns it.
 */

static id 
bigintobj_makeobj (bigintobj_c * self, bigintobj_args args)
{
  assert (bigintobj_check (self, args));

  if (self->obj)
    {
      return self->obj;
    }
  else
    {
      assert (self->hit);
      return self->obj = [args.proto intValue:self->val];
    }
}

/*
 * initializing "c" by object
 */

static void 
bigintobj_ooobj (bigintobj_c * c, id obj, bigintobj_args args)
{
  int val = [obj intValue];
  if (VAL_MIN <= val && val <= VAL_MAX)
    {
      c->hit = 1;
      c->val = val;
      c->obj = obj;
    }
  else
    {
      c->hit = 0;
      c->obj = obj;
    }
  assert (bigintobj_check (c, args));
}

/*
 * replacing "c" by object result of inplace operation
 * used like :
 *
 *              bigintobj_makeobj(c,args);
 *              bigintobj_inobj(c,[c->obj negate],args)
 */

static void 
bigintobj_inobj (bigintobj_c * c, id obj, bigintobj_args args)
{
  int val = [obj intValue];
  /* c->obj is invalid reference now... replace it by result inplace op
   * we cannot check "c" here (as the object is invalid...)
   */
  assert (c->obj != nil);
  if (VAL_MIN <= val && val <= VAL_MAX)
    {
      c->hit = 1;
      c->val = val;
      c->obj = obj;
    }
  else
    {
      c->hit = 0;
      c->obj = obj;
    }
  assert (bigintobj_check (c, args));
}

/*
 * initializing "c" by int value
 */

static void 
bigintobj_ooval (bigintobj_c * c, int val, bigintobj_args args)
{
  if (VAL_MIN <= val && val <= VAL_MAX)
    {
      c->hit = 1;
      c->val = val;
      c->obj = nil;
    }
  else
    {
      c->hit = 0;
      c->obj = [args.proto intValue:val];
    }
  assert (bigintobj_check (c, args));
}

/*
 * replacing "c" by int value
 */

static void 
bigintobj_inval (bigintobj_c * c, int val, bigintobj_args args)
{
  assert (bigintobj_check (c, args));
  if (VAL_MIN <= val && val <= VAL_MAX)
    {
      c->hit = 1;
      c->val = val;
      if (c->obj)
	c->obj = nil;
    }
  else
    {
      c->hit = 0;
      if (c->obj)
	c->obj = nil;
      c->obj = [args.proto intValue:val];
    }
  assert (bigintobj_check (c, args));
}

static void 
bigintobj_oozero (bigintobj_c * c, bigintobj_args args)
{
  c->hit = 1;
  c->val = 0;
  c->obj = nil;
  assert (bigintobj_check (c, args));
}

static void 
bigintobj_copy (bigintobj_c * c, bigintobj_t a, bigintobj_args args)
{
  c->hit = a->hit;
  c->val = a->val;
  c->obj = (a->obj) ? a->obj : nil;
  assert (bigintobj_check (c, args) && bigintobj_check (a, args));
}

static void 
bigintobj_deepcopy (bigintobj_c * c, bigintobj_t a, bigintobj_args args)
{
  c->hit = a->hit;
  c->val = a->val;
  c->obj = (a->obj) ? [a->obj copy] : nil;
  assert (bigintobj_check (c, args) && bigintobj_check (a, args));
}

static void 
bigintobj_move (bigintobj_c * c, bigintobj_c * a, bigintobj_args args)
{
  assert (bigintobj_check (c, args));
  c->hit = a->hit;
  c->val = a->val;
  a->val = SHRT_MAX;
  c->obj = a->obj;
  a->obj = nil;
  assert (bigintobj_check (c, args));
}

static void 
bigintobj_clear (bigintobj_c * c, bigintobj_args args)
{
  c->val = SHRT_MAX;
  if (c->obj)
    c->obj = nil;
}

static bigintobj_args 
bigintobj_getargs (id self)
{
  bigintobj_args args;
  args.proto = self;
  return args;
}

static int 
bigintobj_size (bigintobj_args args)
{
  return 1;			/* pointer increment */
}

static int 
bigintobj_bsize (bigintobj_args args)
{
  return sizeof (bigintobj_c);	/* byte size carrier */
}

#if 0
static bigintobj_t 
bigintobj_id2t (id object)
{				/* not needed */
}
static bigintobj_c *
bigintobj_id2t (id object)
{				/* not needed */
}
#endif

/*
 * initialize scratch space "ref" with a read-only value 
 */

static bigintobj_t 
bigintobj_id2ref (id object, bigintobj_c * ref)
{
  bigintobj_args args = bigintobj_getargs (object);	/* use object as proto */

  bigintobj_ooobj (ref, object, args);
  return ref;
}

/*
 * return a new object, containing a copy of "t"
 */

static id 
bigintobj_t2id (id proto, bigintobj_t t)
{
  bigintobj_args args = bigintobj_getargs (proto);
  return bigintobj_obj (t, args);
}

/*
 * return a new object, containing "t" itself (moved into object)
 */

static id 
bigintobj_c2id (id proto, bigintobj_c * c)
{
  id res;
  bigintobj_args args = bigintobj_getargs (proto);

  res = bigintobj_obj (c, args);
  bigintobj_clear (c, args);

  return res;
}

static unsigned 
bigintobj_hash (bigintobj_t a, bigintobj_args args)
{
  return (a->hit) ? a->val : [a->obj hash];
}

static int 
bigintobj_iseq (bigintobj_t a, bigintobj_t b, bigintobj_args args)
{
  if (a == b)
    {
      return YES;
    }
  else
    {
      if (a->hit)
	{
	  return (b->hit) ? a->val == b->val : NO;
	}
      else
	{
	  return (b->hit) ? NO : [a->obj isEqual:b->obj];
	}
    }
}

static int 
bigintobj_sgn (bigintobj_t a, bigintobj_args args)
{
  if (a->hit)
    {
      short int sgn = a->val;
      return (sgn == 0) ? 0 : ((sgn < 0) ? -1 : +1);
    }
  else
    {
      return [a->obj sign];
    }
}

static int 
bigintobj_cmp (bigintobj_t a, bigintobj_t b, bigintobj_args args)
{
  int cmp;

  if (a == b)
    {
      cmp = 0;
    }
  else
    {
      if (a->hit && b->hit)
	{
	  cmp = a->val - b->val;
	  cmp = (cmp == 0) ? 0 : ((cmp < 0) ? -1 : +1);
	}
      else
	{
	  id A = bigintobj_obj (a, args);
	  id B = bigintobj_obj (b, args);
	  cmp = [A compare:B];
	}
    }

  return cmp;
}

static int 
bigintobj_iszero (bigintobj_t a, bigintobj_args args)
{
  int iszero = (a->hit && a->val == 0);
  assert (iszero || (a->hit && a->val != 0) || (a->hit == 0 && [a->obj notZero]));
  return iszero;
}

static int 
bigintobj_isop (bigintobj_t a, bigintobj_t b, bigintobj_args args)
{
  if (a == b)
    {
      return NO;
    }
  else
    {
      if (a->hit)
	{
	  assert (VAL_MAX + VAL_MIN == 0);
	  assert (VAL_MIN <= a->val && a->val <= VAL_MAX);
	  assert (VAL_MIN <= b->val && b->val <= VAL_MAX);
	  return (b->hit) ? a->val + b->val == 0 : NO;
	}
      else
	{
	  return (b->hit) ? NO : [a->obj isOpposite:b->obj];
	}
    }
}

static void 
bigintobj_ooneg (bigintobj_c * c, bigintobj_t a, bigintobj_args args)
{
  if (a->hit)
    {
      int C = -a->val;
      bigintobj_ooval (c, C, args);
    }
  else
    {
      bigintobj_ooobj (c, [a->obj negate], args);
    }

  assert (bigintobj_isop (c, a, args));
}

static void 
bigintobj_inneg (bigintobj_c * c, bigintobj_args args)
{
  if (c->hit)
    {
      int C = -c->val;
      bigintobj_inval (c, C, args);
    }
  else
    {
      bigintobj_inobj (c, [c->obj negate], args);
    }
}

static void 
bigintobj_oodbl (bigintobj_c * c, bigintobj_t a, int v, bigintobj_args args)
{
  if (a->hit)
    {
      int C = 2 * a->val;
      C = (v == +1) ? +C : -C;
      bigintobj_ooval (c, C, args);
    }
  else
    {
      bigintobj_ooobj (c, [a->obj _double:v], args);
    }
}

static void 
bigintobj_indbl (bigintobj_c * c, int v, bigintobj_args args)
{
  if (c->hit)
    {
      int C = 2 * c->val;
      C = (v == +1) ? +C : -C;
      bigintobj_inval (c, C, args);
    }
  else
    {
      bigintobj_inobj (c, [c->obj _double:v], args);
    }
}

static void 
bigintobj_ooadd (bigintobj_c * c, bigintobj_t a, int v, bigintobj_t b, int w, bigintobj_args args)
{
  if (a->hit && b->hit)
    {
      int C = a->val * v + b->val * w;
      bigintobj_ooval (c, C, args);
    }
  else
    {
      id A, B, C;
      A = bigintobj_obj (a, args);
      B = bigintobj_obj (b, args);
      C = [A _add:v:B:w];
      bigintobj_ooobj (c, C, args);
    }
}

static void 
bigintobj_inadd (bigintobj_c * c, int v, bigintobj_t b, int w, bigintobj_args args)
{
  if (c->hit && b->hit)
    {
      int C = c->val * v + b->val * w;
      bigintobj_inval (c, C, args);
    }
  else
    {
      id B = bigintobj_obj (b, args);
      bigintobj_makeobj (c, args);
      bigintobj_inobj (c, [c->obj _add:v:B:w], args);
    }
}

static int 
bigintobj_isone (bigintobj_t a, bigintobj_args args)
{
  return (a->hit && a->val == +1);
}

static int 
bigintobj_isminusone (bigintobj_t a, bigintobj_args args)
{
  return (a->hit && a->val == -1);
}

static void 
bigintobj_oosqr (bigintobj_c * c, bigintobj_t a, bigintobj_args args)
{
  if (a->hit)
    {
      int C = a->val * a->val;
      bigintobj_ooval (c, C, args);
    }
  else
    {
      bigintobj_ooobj (c, [a->obj square], args);
    }
}

static void 
bigintobj_insqr (bigintobj_c * c, bigintobj_args args)
{
  if (c->hit)
    {
      int C = c->val * c->val;
      bigintobj_inval (c, C, args);
    }
  else
    {
      bigintobj_inobj (c, [c->obj square], args);
    }
}

static void 
bigintobj_oomul (bigintobj_c * c, bigintobj_t a, bigintobj_t b, bigintobj_args args)
{
  if (a->hit && b->hit)
    {
      int C = a->val * b->val;
      bigintobj_ooval (c, C, args);
    }
  else
    {
      id A, B, C;
      A = bigintobj_obj (a, args);
      B = bigintobj_obj (b, args);
      C = [A multiply:B];
      bigintobj_ooobj (c, C, args);
    }
}

static void 
bigintobj_inmul (bigintobj_c * c, bigintobj_t b, bigintobj_args args)
{
  if (c->hit && b->hit)
    {
      int C = c->val * b->val;
      bigintobj_inval (c, C, args);
    }
  else
    {
      id B = bigintobj_obj (b, args);
      bigintobj_makeobj (c, args);
      bigintobj_inobj (c, [c->obj multiply:B], args);
    }
}

static void 
bigintobj_oomulv (bigintobj_c * c, bigintobj_t a, bigintobj_t b, int v, bigintobj_args args)
{
  if (a->hit && b->hit)
    {
      int C = a->val * b->val * v;
      bigintobj_ooval (c, C, args);
    }
  else
    {
      id A, B, C;
      A = bigintobj_obj (a, args);
      B = bigintobj_obj (b, args);
      C = [A _multiply:B:v];
      bigintobj_ooobj (c, C, args);
    }
}

static void 
bigintobj_inmulv (bigintobj_c * c, bigintobj_t b, int v, bigintobj_args args)
{
  if (c->hit && b->hit)
    {
      int C = c->val * b->val * v;
      bigintobj_inval (c, C, args);
    }
  else
    {
      id B = bigintobj_obj (b, args);
      bigintobj_makeobj (c, args);
      bigintobj_inobj (c, [c->obj _multiply:B:v], args);
    }
}

static void 
bigintobj_ooaddmul (bigintobj_c * c, bigintobj_t a, int v, bigintobj_t b, bigintobj_t t, int w, bigintobj_args args)
{
  if (a->hit && b->hit && t->hit)
    {
      int C = a->val * v + b->val * t->val * w;
      bigintobj_ooval (c, C, args);
    }
  else
    {
      id A, B, T, C;
      A = bigintobj_obj (a, args);
      B = bigintobj_obj (b, args);
      T = bigintobj_obj (t, args);
      C = [A _add:v:B multiply:T:w];
      bigintobj_ooobj (c, C, args);
    }
}

static void 
bigintobj_inaddmul (bigintobj_c * c, int v, bigintobj_t b, bigintobj_t t, int w, bigintobj_args args)
{
  if (c->hit && b->hit && t->hit)
    {
      int C = c->val * v + b->val * t->val * w;
      bigintobj_inval (c, C, args);
    }
  else
    {
      id B = bigintobj_obj (b, args);
      id T = bigintobj_obj (t, args);
      bigintobj_makeobj (c, args);
      bigintobj_inobj (c, [c->obj _add:v:B multiply:T:w], args);
    }
}

static void 
bigintobj_oomuladd (bigintobj_c * c, bigintobj_t a, bigintobj_t s, int v, bigintobj_t b, int w, bigintobj_args args)
{
  if (a->hit && s->hit && b->hit)
    {
      int C = a->val * s->val * v + b->val * w;
      bigintobj_ooval (c, C, args);
    }
  else
    {
      id A, B, S, C;
      A = bigintobj_obj (a, args);
      B = bigintobj_obj (b, args);
      S = bigintobj_obj (s, args);
      C = [A _multiply:S:v add:B:w];
      bigintobj_ooobj (c, C, args);
    }
}

static void 
bigintobj_inmuladd (bigintobj_c * c, bigintobj_t s, int v, bigintobj_t b, int w, bigintobj_args args)
{
  if (c->hit && s->hit && b->hit)
    {
      int C = c->val * s->val * v + b->val * w;
      bigintobj_inval (c, C, args);
    }
  else
    {
      id B = bigintobj_obj (b, args);
      id S = bigintobj_obj (s, args);
      bigintobj_makeobj (c, args);
      bigintobj_inobj (c, [c->obj _multiply:S:v add:B:w], args);
    }
}

static void 
bigintobj_oomuladdmul (bigintobj_c * c, bigintobj_t a, bigintobj_t s, int v, bigintobj_t b, bigintobj_t t, int w, bigintobj_args args)
{
  if (a->hit && s->hit && b->hit && t->hit)
    {
      int C = a->val * s->val * v + b->val * t->val * w;
      bigintobj_ooval (c, C, args);
    }
  else
    {
      id A, B, S, T, C;
      A = bigintobj_obj (a, args);
      B = bigintobj_obj (b, args);
      S = bigintobj_obj (s, args);
      T = bigintobj_obj (t, args);
      C = [A _multiply:S:v add:B multiply:T:w];
      bigintobj_ooobj (c, C, args);
    }
}

static void 
bigintobj_inmuladdmul (bigintobj_c * c, bigintobj_t s, int v, bigintobj_t b, bigintobj_t t, int w, bigintobj_args args)
{
  if (c->hit && s->hit && b->hit && t->hit)
    {
      int C = c->val * s->val * v + b->val * t->val * w;
      bigintobj_inval (c, C, args);
    }
  else
    {
      id B = bigintobj_obj (b, args);
      id S = bigintobj_obj (s, args);
      id T = bigintobj_obj (t, args);
      bigintobj_makeobj (c, args);
      bigintobj_inobj (c, [c->obj _multiply:S:v add:B multiply:T:w], args);
    }
}

static void 
bigintobj_ooaddsqr (bigintobj_c * c, bigintobj_t a, int v, bigintobj_t b, int w, bigintobj_args args)
{
  if (a->hit && b->hit)
    {
      int C = a->val * v + b->val * b->val * w;
      bigintobj_ooval (c, C, args);
    }
  else
    {
      id A, B, C;
      A = bigintobj_obj (a, args);
      B = bigintobj_obj (b, args);
      C = [A _addSquare:v:B:w];
      bigintobj_ooobj (c, C, args);
    }
}

static void 
bigintobj_inaddsqr (bigintobj_c * c, int v, bigintobj_t b, int w, bigintobj_args args)
{
  if (c->hit && b->hit)
    {
      int C = c->val * v + b->val * b->val * w;
      bigintobj_inval (c, C, args);
    }
  else
    {
      id B = bigintobj_obj (b, args);
      bigintobj_makeobj (c, args);
      bigintobj_inobj (c, [c->obj _addSquare:v:B:w], args);
    }
}

static BOOL 
bigintobj_oodiv (bigintobj_c * c, bigintobj_t a, bigintobj_t b, bigintobj_args args)
{
  if (a->hit && b->hit)
    {
      int C;
      if (b->val == 0 || a->val % b->val != 0)
	{
	  return FAILURE;
	}
      else
	{
	  C = a->val / b->val;
	}
      bigintobj_ooval (c, C, args);
    }
  else
    {
      id A, B, C;
      A = bigintobj_obj (a, args);
      B = bigintobj_obj (b, args);
      C = [A divide:B];
      if (C == nil)
	return FAILURE;
      bigintobj_ooobj (c, C, args);
    }

  return SUCCESS;
}

static void 
bigintobj_indiv (bigintobj_c * c, bigintobj_t b, bigintobj_args args)
{
  if (c->hit && b->hit)
    {
      int C;
      if (b->val == 0 || c->val % b->val != 0)
	{
	  fprintf (stderr, "-exact division failed\n");
	  abort ();
	}
      else
	{
	  C = c->val / b->val;
	}
      bigintobj_inval (c, C, args);
    }
  else
    {
      id C, B = bigintobj_obj (b, args);
      bigintobj_makeobj (c, args);
      C = [c->obj divide:B];
      if (C == nil)
	{
	  fprintf (stderr, "-exact division failed\n");
	  abort ();
	}
      bigintobj_inobj (c, C, args);
    }
}

static void 
bigintobj_args_fileOut (id aFile, bigintobj_args * args)
{
}
static void 
bigintobj_args_fileIn (id aFile, bigintobj_args * args)
{
}

static void 
bigintobj_fileOut (id aFiler, bigintobj_c * a, bigintobj_args args)
{
  assert (bigintobj_check (a, args));
  [aFiler fileOut:&a->hit type:'S'];
  if (a->hit)
    {
      [aFiler fileOut:&a->val type:'s'];	/* signed ! */
    }
  else
    {
      [aFiler fileOut:&a->obj type:'@'];
    }
}

static void 
bigintobj_fileIn (id aFiler, bigintobj_c * c, bigintobj_args args)
{
  [aFiler fileIn:&c->hit type:'S'];
  if (c->hit)
    {
      [aFiler fileIn:&c->val type:'s'];
      c->obj = nil;
    }
  else
    {
      [aFiler fileIn:&c->obj type:'@'];
    }
}


/*
 * Computer Algebra Kit (c) 1993,00 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: ivectorc.m,v 1.6 2000/10/12 14:40:26 stes Exp $
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

#if bigintobj_pervalue
static bigintobj_t 
bigintobjseq_tval (bigintobjseq_t self)
{
  return *self;
}
static bigintobj_c *
bigintobjseq_cval (bigintobjseq_t self)
{
  return self;
}
#else
static bigintobj_t 
bigintobjseq_tval (bigintobjseq_t self)
{
  return self;
}
static bigintobj_c *
bigintobjseq_cval (bigintobjseq_t self)
{
  return self;
}
#endif

static int 
bigintobjseq_check (bigintobjseq_t self, int n, bigintobj_args args)
{
  while (n--)
    {
      bigintobj_check (bigintobjseq_tval (self), args);
      self += bigintobj_size (args);
    }
  return 1;
}

static bigintobjseq_t 
bigintobjseq_alloc (int n, bigintobj_args args)
{
  bigintobjseq_t p;
  int m = n * bigintobj_bsize (args);
#if OBJC_REFCNT
  p = (bigintobjseq_t) OC_Calloc (m);
#else
  p = (bigintobjseq_t) OC_Malloc (m);
#endif
  return p;
}

static bigintobjseq_t 
bigintobjseq_realloc (bigintobjseq_t self, int oldc, int n, bigintobj_args args)
{
  bigintobjseq_t p;
  int m = n * bigintobj_bsize (args);
  p = (bigintobjseq_t) OC_Realloc (self, m);
#if OBJC_REFCNT
  assert (oldc <= n);
  memset (p + oldc, 0, (n - oldc) * bigintobj_bsize (args));
#endif
  return p;
}

static bigintobjseq_t 
bigintobjseq_free (bigintobjseq_t self, bigintobj_args args)
{
  OC_Free (self);
  return NULL;
}

static void 
bigintobjseq_oozero (bigintobjseq_t c, int n, bigintobj_args args)
{
  while (n--)
    {
      bigintobj_oozero (bigintobjseq_cval (c), args);
      c += bigintobj_size (args);
    }
}

static void 
bigintobjseq_copy (bigintobjseq_t c, bigintobjseq_t a, int n, bigintobj_args args)
{
  assert (n >= 0);
  while (n--)
    {
      bigintobj_copy (bigintobjseq_cval (c), bigintobjseq_tval (a), args);
      c += bigintobj_size (args);
      a += bigintobj_size (args);
    }
}

static void 
bigintobjseq_deepcopy (bigintobjseq_t c, bigintobjseq_t a, int n, bigintobj_args args)
{
  assert (n >= 0);
  while (n--)
    {
      bigintobj_deepcopy (bigintobjseq_cval (c), bigintobjseq_tval (a), args);
      c += bigintobj_size (args);
      a += bigintobj_size (args);
    }
}

#if bigintobj_isvalue
static void 
bigintobjseq_clear (bigintobjseq_t self, int n, bigintobj_args args)
{
  /* nothing to clear */
}
#else
static void 
bigintobjseq_clear (bigintobjseq_t self, int n, bigintobj_args args)
{
  while (n--)
    {
      bigintobj_clear (self, args);
      self += bigintobj_size (args);
    }
}
#endif /* bigintobj_isvalue */

static int 
bigintobjseq_iseq (bigintobjseq_t a, bigintobjseq_t b, int n, bigintobj_args args)
{
  assert (n >= 0 && a != b);
  while (n--)
    {
      if (!bigintobj_iseq (bigintobjseq_tval (a), bigintobjseq_tval (b), args))
	{
	  return 0;
	}
      else
	{
	  a += bigintobj_size (args);
	  b += bigintobj_size (args);
	}
    }
  return 1;
}

static unsigned 
bigintobjseq_hash (bigintobjseq_t a, int n, bigintobj_args args)
{
  assert (n >= 0);
  return (n) ? bigintobj_hash (bigintobjseq_tval (a), args) : 0;
}

static void 
bigintobjseq_place (bigintobjseq_t self, bigintobj_t a, int i, bigintobj_args args)
{
  bigintobj_c *c = bigintobjseq_cval (self + i * bigintobj_size (args));
  bigintobj_clear (c, args);
  bigintobj_copy (c, a, args);
}

static int 
bigintobjseq_insertlast (bigintobjseq_t self, bigintobj_t a, int n, bigintobj_args args)
{
  bigintobj_c *c;
  assert (n >= 0);
  c = bigintobjseq_cval (self + n * bigintobj_size (args));
  bigintobj_copy (c, a, args);
  return ++n;
}

static int 
bigintobjseq_insertfirst (bigintobjseq_t self, bigintobj_t a, int n, bigintobj_args args)
{
  int j;
  assert (n > 0);
  self += n * bigintobj_size (args);
  j = n;
  while (j--)
    {
      bigintobjseq_t t;
      t = self - bigintobj_size (args);
      bigintobj_move (bigintobjseq_cval (self), bigintobjseq_cval (t), args);
      self = t;
    }
  bigintobj_copy (bigintobjseq_cval (self), a, args);
  return ++n;
}

static int 
bigintobjseq_insertat (bigintobjseq_t self, bigintobj_t a, int i, int n, bigintobj_args args)
{
  assert (0 <= i && i < n);
  self += i * bigintobj_size (args);
  return i + bigintobjseq_insertfirst (self, a, n - i, args);
}

static int 
bigintobjseq_freelast (bigintobjseq_t self, int n, bigintobj_args args)
{
  bigintobj_c *c;
  assert (0 < n);
  --n;
  c = bigintobjseq_cval (self + n * bigintobj_size (args));
  bigintobj_clear (c, args);
  return n;
}

static int 
bigintobjseq_freefirst (bigintobjseq_t self, int n, bigintobj_args args)
{
  int j;
  assert (0 < n);
  bigintobj_clear (bigintobjseq_cval (self), args);
  --n;
  j = n;
  while (j--)
    {
      bigintobjseq_t t;
      t = self + bigintobj_size (args);
      bigintobj_move (bigintobjseq_cval (self), bigintobjseq_cval (t), args);
      self = t;
    }
  return n;
}

static int 
bigintobjseq_freeat (bigintobjseq_t self, int i, int n, bigintobj_args args)
{
  assert (0 <= i && i < n);
  self += i * bigintobj_size (args);
  return i + bigintobjseq_freefirst (self, n - i, args);
}

static bigintobj_t 
bigintobjseq_at (bigintobjseq_t self, int i, bigintobj_args args)
{
  bigintobj_t res;
  assert (0 <= i);
  res = bigintobjseq_tval (self + i * bigintobj_size (args));
  assert (bigintobj_check (res, args));
  return res;
}

static bigintobj_t 
bigintobjseq_last (bigintobjseq_t self, int n, bigintobj_args args)
{
  return bigintobjseq_at (self, n - 1, args);
}

static bigintobj_c *
bigintobjseq_cvalat (bigintobjseq_t self, int i, bigintobj_args args)
{
  assert (0 <= i);
  return bigintobjseq_cval (self + i * bigintobj_size (args));
}

static int 
bigintobjseq_iszero (bigintobjseq_t a, int n, bigintobj_args args)
{
  assert (n >= 0);
  while (n--)
    {
      if (bigintobj_iszero (bigintobjseq_tval (a), args))
	{
	  a += bigintobj_size (args);
	}
      else
	{
	  return 0;
	}
    }
  return 1;
}

static int 
bigintobjseq_isop (bigintobjseq_t a, bigintobjseq_t b, int n, bigintobj_args args)
{
  assert (n >= 0 && a != b);
  while (n--)
    {
      if (!bigintobj_isop (bigintobjseq_tval (a), bigintobjseq_tval (b), args))
	{
	  return 0;
	}
      else
	{
	  a += bigintobj_size (args);
	  b += bigintobj_size (args);
	}
    }
  return 1;
}

static void 
bigintobjseq_ooneg (bigintobjseq_t c, bigintobjseq_t a, int n, bigintobj_args args)
{
  assert (n >= 0);
  while (n--)
    {
      bigintobj_ooneg (bigintobjseq_cval (c), bigintobjseq_tval (a), args);
      c += bigintobj_size (args);
      a += bigintobj_size (args);
    }
}

static void 
bigintobjseq_inneg (bigintobjseq_t a, int n, bigintobj_args args)
{
  assert (n >= 0);
  while (n--)
    {
      bigintobj_inneg (bigintobjseq_cval (a), args);
      a += bigintobj_size (args);
    }
}

static void 
bigintobjseq_oonegv (bigintobjseq_t c, bigintobjseq_t a, int v, int n, bigintobj_args args)
{
  assert (v * v == 1);
  if (v == -1)
    bigintobjseq_ooneg (c, a, n, args);
  else
    bigintobjseq_copy (c, a, n, args);
}

static void 
bigintobjseq_innegv (bigintobjseq_t a, int v, int n, bigintobj_args args)
{
  assert (v * v == 1);
  if (v == -1)
    bigintobjseq_inneg (a, n, args);
}

static void 
bigintobjseq_oodbl (bigintobjseq_t c, bigintobjseq_t a, int v, int n, bigintobj_args args)
{
  assert (n >= 0 && v * v == 1);
  while (n--)
    {
      bigintobj_oodbl (bigintobjseq_cval (c), bigintobjseq_tval (a), v, args);
      c += bigintobj_size (args);
      a += bigintobj_size (args);
    }
}

static void 
bigintobjseq_indbl (bigintobjseq_t a, int v, int n, bigintobj_args args)
{
  assert (n >= 0 && v * v == 1);
  while (n--)
    {
      bigintobj_indbl (bigintobjseq_cval (a), v, args);
      a += bigintobj_size (args);
    }
}

static void 
bigintobjseq_ooadd (bigintobjseq_t c, bigintobjseq_t a, int v, bigintobjseq_t b, int w, int n, bigintobj_args args)
{
  assert (n >= 0 && a != b && v * v == 1 && w * w == 1);
  while (n--)
    {
      bigintobj_ooadd (bigintobjseq_cval (c), bigintobjseq_tval (a), v, bigintobjseq_tval (b), w, args);
      c += bigintobj_size (args);
      a += bigintobj_size (args);
      b += bigintobj_size (args);
    }
}

static void 
bigintobjseq_inadd (bigintobjseq_t a, int v, bigintobjseq_t b, int w, int n, bigintobj_args args)
{
  assert (n >= 0 && a != b && v * v == 1 && w * w == 1);
  while (n--)
    {
      bigintobj_inadd (bigintobjseq_cval (a), v, bigintobjseq_tval (b), w, args);
      a += bigintobj_size (args);
      b += bigintobj_size (args);
    }
}

static void 
bigintobjseq_oomulsc (bigintobjseq_t c, bigintobjseq_t a, bigintobj_t s, int n, bigintobj_args args)
{
  assert (n >= 0);
  while (n--)
    {
      bigintobj_oomul (bigintobjseq_cval (c), bigintobjseq_tval (a), s, args);
      c += bigintobj_size (args);
      a += bigintobj_size (args);
    }
}

static void 
bigintobjseq_inmulsc (bigintobjseq_t a, bigintobj_t s, int n, bigintobj_args args)
{
  assert (n >= 0);
  while (n--)
    {
      bigintobj_inmul (bigintobjseq_cval (a), s, args);
      a += bigintobj_size (args);
    }
}

static void 
bigintobjseq_oomulscv (bigintobjseq_t c, bigintobjseq_t a, bigintobj_t s, int v, int n, bigintobj_args args)
{
  assert (n >= 0 && v * v == 1);
  while (n--)
    {
      bigintobj_oomulv (bigintobjseq_cval (c), bigintobjseq_tval (a), s, v, args);
      c += bigintobj_size (args);
      a += bigintobj_size (args);
    }
}

static void 
bigintobjseq_inmulscv (bigintobjseq_t a, bigintobj_t s, int v, int n, bigintobj_args args)
{
  assert (n >= 0 && v * v == 1);
  while (n--)
    {
      bigintobj_inmulv (bigintobjseq_cval (a), s, v, args);
      a += bigintobj_size (args);
    }
}

static void 
bigintobjseq_ooaddmulsc (bigintobjseq_t c, bigintobjseq_t a, int v, bigintobjseq_t b, bigintobj_t t, int w, int n, bigintobj_args args)
{
  assert (n >= 0 && v * v == 1 && w * w == 1);
  while (n--)
    {
      bigintobj_ooaddmul (bigintobjseq_cval (c), bigintobjseq_tval (a), v, bigintobjseq_tval (b), t, w, args);
      a += bigintobj_size (args);
      b += bigintobj_size (args);
      c += bigintobj_size (args);
    }
}

static void 
bigintobjseq_oomulscadd (bigintobjseq_t c, bigintobjseq_t a, bigintobj_t s, int v, bigintobjseq_t b, int w, int n, bigintobj_args args)
{
  assert (n >= 0 && v * v == 1 && w * w == 1);
  while (n--)
    {
      bigintobj_oomuladd (bigintobjseq_cval (c), bigintobjseq_tval (a), s, v, bigintobjseq_tval (b), w, args);
      a += bigintobj_size (args);
      b += bigintobj_size (args);
      c += bigintobj_size (args);
    }
}

static void 
bigintobjseq_oomulscaddmulsc (bigintobjseq_t c, bigintobjseq_t a, bigintobj_t s, int v, bigintobjseq_t b, bigintobj_t t, int w, int n, bigintobj_args args)
{
  assert (n >= 0 && v * v == 1 && w * w == 1);
  while (n--)
    {
      bigintobj_oomuladdmul (bigintobjseq_cval (c), bigintobjseq_tval (a), s, v, bigintobjseq_tval (b), t, w, args);
      a += bigintobj_size (args);
      b += bigintobj_size (args);
      c += bigintobj_size (args);
    }
}

static void 
bigintobjseq_inaddmulsc (bigintobjseq_t a, int v, bigintobjseq_t b, bigintobj_t t, int w, int n, bigintobj_args args)
{
  assert (n >= 0 && v * v == 1 && w * w == 1);
  while (n--)
    {
      bigintobj_inaddmul (bigintobjseq_cval (a), v, bigintobjseq_tval (b), t, w, args);
      a += bigintobj_size (args);
      b += bigintobj_size (args);
    }
}

static void 
bigintobjseq_inmulscadd (bigintobjseq_t a, bigintobj_t s, int v, bigintobjseq_t b, int w, int n, bigintobj_args args)
{
  assert (n >= 0 && v * v == 1 && w * w == 1);
  while (n--)
    {
      bigintobj_inmuladd (bigintobjseq_cval (a), s, v, bigintobjseq_tval (b), w, args);
      a += bigintobj_size (args);
      b += bigintobj_size (args);
    }
}

static void 
bigintobjseq_inmulscaddmulsc (bigintobjseq_t a, bigintobj_t s, int v, bigintobjseq_t b, bigintobj_t t, int w, int n, bigintobj_args args)
{
  assert (n >= 0 && v * v == 1 && w * w == 1);
  while (n--)
    {
      bigintobj_inmuladdmul (bigintobjseq_cval (a), s, v, bigintobjseq_tval (b), t, w, args);
      a += bigintobj_size (args);
      b += bigintobj_size (args);
    }
}

static BOOL 
bigintobjseq_oodivsc (bigintobjseq_t c, bigintobjseq_t a, bigintobj_t s, int n, bigintobj_args args)
{
  int i;
  BOOL failed;
  bigintobjseq_t orgc = c;
  assert (n >= 0);

  for (i = 0; i < n; i++)
    {

      failed = bigintobj_oodiv (bigintobjseq_cval (c), bigintobjseq_tval (a), s, args);

      if (failed)
	{
	  bigintobjseq_clear (orgc, i - 1, args);
	  return FAILURE;
	}
      else
	{
	  c += bigintobj_size (args);
	  a += bigintobj_size (args);
	}
    }

  return SUCCESS;
}

static void 
bigintobjseq_indivsc (bigintobjseq_t a, bigintobj_t s, int n, bigintobj_args args)
{
  assert (n >= 0);
  while (n--)
    {
      bigintobj_indiv (bigintobjseq_cval (a), s, args);
      a += bigintobj_size (args);
    }
}

static void 
bigintobjseq_oodotsqr (bigintobj_c * c, bigintobjseq_t a, int n, bigintobj_args args)
{
  assert (n >= 0);
  bigintobj_oozero (c, args);
  while (n--)
    {
      bigintobj_inaddsqr (c, +1, bigintobjseq_tval (a), +1, args);
      a += bigintobj_size (args);
    }
}

static void 
bigintobjseq_oodotmul (bigintobj_c * c, bigintobjseq_t a, bigintobjseq_t b, int n, bigintobj_args args)
{
  assert (n >= 0);
  bigintobj_oozero (c, args);
  while (n--)
    {
      bigintobj_inaddmul (c, +1, bigintobjseq_tval (a), bigintobjseq_tval (b), +1, args);
      a += bigintobj_size (args);
      b += bigintobj_size (args);
    }
}

static void 
bigintobjseq_args_fileOut (id aFiler, bigintobj_args * args)
{
  bigintobj_args_fileOut (aFiler, args);
}
static void 
bigintobjseq_args_fileIn (id aFiler, bigintobj_args * args)
{
  bigintobj_args_fileIn (aFiler, args);
}

static void 
bigintobjseq_fileOut (id aFiler, bigintobjseq_t self, int n, bigintobj_args args)
{
  assert (n >= 0);
  while (n--)
    {
      bigintobj_fileOut (aFiler, bigintobjseq_cval (self), args);
      self += bigintobj_size (args);
    }
}

static void 
bigintobjseq_fileIn (id aFiler, bigintobjseq_t self, int n, bigintobj_args args)
{
  assert (n >= 0);
  while (n--)
    {
      bigintobj_fileIn (aFiler, bigintobjseq_cval (self), args);
      self += bigintobj_size (args);
    }
}

static bigintobjvec_args 
bigintobjvec_getargs (id self)
{
  bigintobjvec_args args;
  args.sargs = bigintobj_getargs ([self scalarZero]);
  return args;
}

static int 
bigintobjvec_check (bigintobjvec_t self, bigintobjvec_args args)
{
  assert (0 <= self->n && self->n <= self->c);
  bigintobjseq_check (self->ptr, self->n, args.sargs);
  return 1;
}

static bigintobjvec_t 
bigintobjvec_id2t (id object)
{
  return [object bigintobjvec_value];
}

static bigintobjvec_c *
bigintobjvec_id2c (id object)
{
  return [object bigintobjvec_reference];
}

static id 
bigintobjvec_t2id (id proto, bigintobjvec_t f)
{
  return [proto bigintobjvec_value:f];
}

static id 
bigintobjvec_c2id (id proto, bigintobjvec_c * r)
{
  return [proto bigintobjvec_reference:r];
}

static void 
bigintobjvec_init (bigintobjvec_t self, int n, bigintobjvec_args args)
{
  self->n = n;
  self->c = n;
  self->ptr = bigintobjseq_alloc (n, args.sargs);
}

static void 
bigintobjvec_initcount (bigintobjvec_t c, int n, bigintobjvec_args args)
{
  bigintobjvec_init (c, n, args);
  bigintobjseq_oozero (c->ptr, n, args.sargs);
}

static void 
bigintobjvec_initcapacity (bigintobjvec_t self, int n, bigintobjvec_args args)
{
  self->n = 0;
  self->c = n;
  self->ptr = bigintobjseq_alloc (n, args.sargs);
}

static void 
bigintobjvec_copy (bigintobjvec_t c, bigintobjvec_t a, bigintobjvec_args args)
{
  bigintobjvec_init (c, a->n, args);
  bigintobjseq_copy (c->ptr, a->ptr, a->n, args.sargs);
}

static void 
bigintobjvec_deepcopy (bigintobjvec_t c, bigintobjvec_t a, bigintobjvec_args args)
{
  bigintobjvec_init (c, a->n, args);
  bigintobjseq_deepcopy (c->ptr, a->ptr, a->n, args.sargs);
}

static void 
bigintobjvec_move (bigintobjvec_t c, bigintobjvec_t a, bigintobjvec_args args)
{
  c->n = a->n;
  c->c = a->c;
  c->ptr = a->ptr;
  a->ptr = NULL;
}

static void 
bigintobjvec_destroy (bigintobjvec_t self, bigintobjvec_args args)
{
  /*
   * clearing memory allocated by bigintobjvec_init after a failed operation
   * can't do a bigintobjseq_clear in that case as the handler doesnt know
   * what elements have been allocated
   */

  self->ptr = bigintobjseq_free (self->ptr, args.sargs);
}

static void 
bigintobjvec_clear (bigintobjvec_t self, bigintobjvec_args args)
{
  bigintobjseq_clear (self->ptr, self->n, args.sargs);
  bigintobjvec_destroy (self, args);
}

static int 
bigintobjvec_count (bigintobjvec_t self)
{
  return self->n;
}

static unsigned 
bigintobjvec_hash (bigintobjvec_t a, bigintobjvec_args args)
{
  return bigintobjseq_hash (a->ptr, a->n, args.sargs);
}

static int 
bigintobjvec_iseq (bigintobjvec_t a, bigintobjvec_t b, bigintobjvec_args args)
{
  assert (a != b);
  return (a->n == b->n && bigintobjseq_iseq (a->ptr, b->ptr, a->n, args.sargs));
}

static void 
bigintobjvec_expand (bigintobjvec_t self, bigintobjvec_args args)
{
  int oldc = self->c;
  assert (self->n == self->c);
  self->c = self->n + self->c + 1;
  self->ptr = bigintobjseq_realloc (self->ptr, oldc, self->c, args.sargs);
  assert (self->n < self->c);
}

static void 
bigintobjvec_insertfirst (bigintobjvec_t self, bigintobj_t a, bigintobjvec_args args)
{
  assert (self->n <= self->c);
  if (self->n == self->c)
    bigintobjvec_expand (self, args);
  self->n = bigintobjseq_insertlast (self->ptr, a, self->n, args.sargs);
}

static void 
bigintobjvec_insertat (bigintobjvec_t self, bigintobj_t a, int i, bigintobjvec_args args)
{
  assert (0 < i && i <= self->n && self->n <= self->c);
  if (self->n == self->c)
    bigintobjvec_expand (self, args);

  if (i == self->n)
    {
      self->n = bigintobjseq_insertfirst (self->ptr, a, self->n, args.sargs);
    }
  else
    {
      self->n = bigintobjseq_insertat (self->ptr, a, self->n - i - 1, self->n, args.sargs);
    }
}

static void 
bigintobjvec_place (bigintobjvec_t self, bigintobj_t a, int i, bigintobjvec_args args)
{
  assert (0 <= i && i < self->n);
  bigintobjseq_place (self->ptr, a, self->n - i - 1, args.sargs);
}

static void 
bigintobjvec_freefirst (bigintobjvec_t self, bigintobjvec_args args)
{
  assert (self->n > 0);
  self->n = bigintobjseq_freelast (self->ptr, self->n, args.sargs);
}

static void 
bigintobjvec_freeat (bigintobjvec_t self, int i, bigintobjvec_args args)
{
  assert (0 < i && i < self->n);
  self->n = bigintobjseq_freeat (self->ptr, self->n - i - 1, self->n, args.sargs);
}


static bigintobj_t 
bigintobjvec_at (bigintobjvec_t self, int ix, bigintobjvec_args args)
{
  assert (0 <= ix && ix < self->n);
  return bigintobjseq_at (self->ptr, self->n - ix - 1, args.sargs);
}

static bigintobj_t 
bigintobjvec_first (bigintobjvec_t self, bigintobjvec_args args)
{
  assert (self->n > 0);
  return bigintobjseq_last (self->ptr, self->n, args.sargs);
}

static bigintobj_t 
bigintobjvec_elt (bigintobjvec_t self, bigintobjvec_ixt ix, bigintobjvec_args args)
{
  assert (ix->n == self->n);
  return bigintobjvec_at (self, ix->i, args);
}

static int 
bigintobjvec_iszero (bigintobjvec_t self, bigintobjvec_args args)
{
  return bigintobjseq_iszero (self->ptr, self->n, args.sargs);
}

static int 
bigintobjvec_isop (bigintobjvec_t a, bigintobjvec_t b, bigintobjvec_args args)
{
  assert (a != b);
  return (a->n == b->n && bigintobjseq_isop (a->ptr, b->ptr, a->n, args.sargs));
}

static void 
bigintobjvec_ooneg (bigintobjvec_t c, bigintobjvec_t a, bigintobjvec_args args)
{
  bigintobjvec_init (c, a->n, args);
  bigintobjseq_ooneg (c->ptr, a->ptr, a->n, args.sargs);
}

static void 
bigintobjvec_inneg (bigintobjvec_t a, bigintobjvec_args args)
{
  bigintobjseq_inneg (a->ptr, a->n, args.sargs);
}

static void 
bigintobjvec_oodbl (bigintobjvec_t c, bigintobjvec_t a, int v, bigintobjvec_args args)
{
  bigintobjvec_init (c, a->n, args);
  bigintobjseq_oodbl (c->ptr, a->ptr, v, a->n, args.sargs);
}

static void 
bigintobjvec_indbl (bigintobjvec_t a, int v, bigintobjvec_args args)
{
  bigintobjseq_indbl (a->ptr, v, a->n, args.sargs);
}

static void 
bigintobjvec_checkcount (int a, int b)
{
  if (a != b)
    {
      fprintf (stderr, "Vector : Dimensions Not Equal\n");
      abort ();
    }
}

static void 
bigintobjvec_ooadd (bigintobjvec_t c, bigintobjvec_t a, int v, bigintobjvec_t b, int w, bigintobjvec_args args)
{
  assert (a != b);
  bigintobjvec_checkcount (a->n, b->n);
  bigintobjvec_init (c, a->n, args);
  bigintobjseq_ooadd (c->ptr, a->ptr, v, b->ptr, w, a->n, args.sargs);
}

static void 
bigintobjvec_inadd (bigintobjvec_t a, int v, bigintobjvec_t b, int w, bigintobjvec_args args)
{
  assert (a != b);
  bigintobjvec_checkcount (a->n, b->n);
  bigintobjseq_inadd (a->ptr, v, b->ptr, w, a->n, args.sargs);
}

static void 
bigintobjvec_oomulsc (bigintobjvec_t c, bigintobjvec_t a, bigintobj_t s, bigintobjvec_args args)
{
  bigintobjvec_init (c, a->n, args);
  bigintobjseq_oomulsc (c->ptr, a->ptr, s, a->n, args.sargs);
}

static void 
bigintobjvec_inmulsc (bigintobjvec_t a, bigintobj_t s, bigintobjvec_args args)
{
  bigintobjseq_inmulsc (a->ptr, s, a->n, args.sargs);
}

static void 
bigintobjvec_ooaddmulsc (bigintobjvec_t c, bigintobjvec_t a, int v, bigintobjvec_t b, bigintobj_t s, int w, bigintobjvec_args args)
{
  assert (a != b);
  bigintobjvec_checkcount (a->n, b->n);
  bigintobjvec_init (c, a->n, args);
  bigintobjseq_ooaddmulsc (c->ptr, a->ptr, v, b->ptr, s, w, a->n, args.sargs);
}

static void 
bigintobjvec_inaddmulsc (bigintobjvec_t a, int v, bigintobjvec_t b, bigintobj_t s, int w, bigintobjvec_args args)
{
  assert (a != b);
  bigintobjvec_checkcount (a->n, b->n);
  bigintobjseq_inaddmulsc (a->ptr, v, b->ptr, s, w, a->n, args.sargs);
}

static void 
bigintobjvec_oomulscadd (bigintobjvec_t c, bigintobjvec_t a, bigintobj_t s, int v, bigintobjvec_t b, int w, bigintobjvec_args args)
{
  assert (a != b);
  bigintobjvec_checkcount (a->n, b->n);
  bigintobjvec_init (c, a->n, args);
  bigintobjseq_oomulscadd (c->ptr, a->ptr, s, v, b->ptr, w, a->n, args.sargs);
}

static void 
bigintobjvec_inmulscadd (bigintobjvec_t a, bigintobj_t s, int v, bigintobjvec_t b, int w, bigintobjvec_args args)
{
  assert (a != b);
  bigintobjvec_checkcount (a->n, b->n);
  bigintobjseq_inmulscadd (a->ptr, s, v, b->ptr, w, a->n, args.sargs);
}

static void 
bigintobjvec_oomulscaddmulsc (bigintobjvec_t c, bigintobjvec_t a, bigintobj_t s, int v, bigintobjvec_t b, bigintobj_t t, int w, bigintobjvec_args args)
{
  assert (a != b);
  bigintobjvec_checkcount (a->n, b->n);
  bigintobjvec_init (c, a->n, args);
  bigintobjseq_oomulscaddmulsc (c->ptr, a->ptr, s, v, b->ptr, t, w, a->n, args.sargs);
}

static void 
bigintobjvec_inmulscaddmulsc (bigintobjvec_t a, bigintobj_t s, int v, bigintobjvec_t b, bigintobj_t t, int w, bigintobjvec_args args)
{
  assert (a != b);
  bigintobjvec_checkcount (a->n, b->n);
  bigintobjseq_inmulscaddmulsc (a->ptr, s, v, b->ptr, t, w, a->n, args.sargs);
}

static BOOL 
bigintobjvec_oodivsc (bigintobjvec_t c, bigintobjvec_t a, bigintobj_t s, bigintobjvec_args args)
{
  BOOL failed;

  bigintobjvec_init (c, a->n, args);
  failed = bigintobjseq_oodivsc (c->ptr, a->ptr, s, a->n, args.sargs);
  if (failed)
    bigintobjvec_destroy (c, args);

  return failed;
}

static void 
bigintobjvec_indivsc (bigintobjvec_t a, bigintobj_t s, bigintobjvec_args args)
{
  bigintobjseq_indivsc (a->ptr, s, a->n, args.sargs);
}

static void 
bigintobjvec_oodotmul (bigintobj_c * c, bigintobjvec_t a, bigintobjvec_t b, bigintobjvec_args args)
{
  assert (a != b);
  bigintobjvec_checkcount (a->n, b->n);
  bigintobjseq_oodotmul (c, a->ptr, b->ptr, a->n, args.sargs);
}

static void 
bigintobjvec_oodotsqr (bigintobj_c * c, bigintobjvec_t a, bigintobjvec_args args)
{
  bigintobjseq_oodotsqr (c, a->ptr, a->n, args.sargs);
}

static void 
bigintobjvec_args_fileOut (id aFiler, bigintobjvec_args * args)
{
  bigintobjseq_args_fileOut (aFiler, &args->sargs);
}
static void 
bigintobjvec_args_fileIn (id aFiler, bigintobjvec_args * args)
{
  bigintobjseq_args_fileIn (aFiler, &args->sargs);
}

static void 
bigintobjvec_fileOut (id aFiler, bigintobjvec_t self, bigintobjvec_args args)
{
  [aFiler fileOut:&self->n type:'i'];
  bigintobjseq_fileOut (aFiler, self->ptr, self->n, args.sargs);
}

static void 
bigintobjvec_fileIn (id aFiler, bigintobjvec_t self, bigintobjvec_args args)
{
  int n;
  [aFiler fileIn:&n type:'i'];
  bigintobjvec_init (self, n, args);
  bigintobjseq_fileIn (aFiler, self->ptr, self->n, args.sargs);
}

static void 
bigintobjvec_ix_init (bigintobjvec_ixt ix, id self)
{
  bigintobjvec_t v = [self bigintobjvec_value];
  ix->n = v->n;
}

static void 
bigintobjvec_ix_copy (bigintobjvec_ixt c, bigintobjvec_ixt a)
{
  c->i = a->i;
  c->n = a->n;
}

static void 
bigintobjvec_ix_clear (bigintobjvec_ixt ix)
{
  /* nothing to clear */
}

static int 
bigintobjvec_ix_count (bigintobjvec_ixt ix)
{
  return ix->n;
}

static int 
bigintobjvec_ix_isempty (bigintobjvec_ixt ix)
{
  return ix->n == 0;
}

static int 
bigintobjvec_ix_ismatch (bigintobjvec_ixt ix)
{
  assert (-1 <= ix->i && ix->i <= ix->n);
  return 0 <= ix->i && ix->i < ix->n;
}

static void 
bigintobjvec_ix_tofirst (bigintobjvec_ixt ix)
{
  ix->i = -1;			/* next -> first */
}

static void 
bigintobjvec_ix_tolast (bigintobjvec_ixt ix)
{
  ix->i = ix->n;		/* prev -> last */
}

static void 
bigintobjvec_ix_to (bigintobjvec_ixt ix, int i)
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
bigintobjvec_ix_next (bigintobjvec_ixt ix)
{
  ix->i = (ix->i < ix->n) ? ix->i + 1 : ix->n;
}

static void 
bigintobjvec_ix_prev (bigintobjvec_ixt ix)
{
  ix->i = (0 <= ix->i) ? ix->i - 1 : -1;
}
@implementation bigintobj_vector : vectorc

- check
{
  [super check];
  [scalarZero check];
  bigintobjvec_check (&value, bigintobjvec_getargs (self));
  return self;
}


- _setUpScalarZero:aScalarZero numScalars:(int)numScalars
{
  scalarZero = aScalarZero;
  bigintobjvec_initcount (&value, numScalars, bigintobjvec_getargs (self));
  assert ([self check]);
  return self;
}

+ scalarZero:aScalarZero numScalars:(int)numScalars
{
  return [[super new] _setUpScalarZero:aScalarZero numScalars:numScalars];
}

- copy
{
  bigintobjvec_c c;
  assert ([self check]);
  bigintobjvec_copy (&c, &value, bigintobjvec_getargs (self));
  return bigintobjvec_c2id (self, &c);
}

- deepCopy
{
  bigintobjvec_c c;
  assert ([self check]);
  bigintobjvec_deepcopy (&c, &value, bigintobjvec_getargs (self));
  return bigintobjvec_c2id (self, &c);
}

- release
{
  bigintobjvec_clear (&value, bigintobjvec_getargs (self));
  return [super release];
}

- (bigintobjvec_t)bigintobjvec_value
{
  return &value;
}

- dobigintobjvec_value:(bigintobjvec_t)aValue
{
  bigintobjvec_copy (&value, aValue, bigintobjvec_getargs (self));
  assert ([self check]);
  return self;
}

- bigintobjvec_value:(bigintobjvec_t)aValue
{
  return [[self clone] dobigintobjvec_value:aValue];
}

- (bigintobjvec_t)bigintobjvec_reference
{
  return &value;
}

- dobigintobjvec_reference:(bigintobjvec_c *)aReference
{
  bigintobjvec_move (&value, aReference, bigintobjvec_getargs (self));
  assert ([self check]);
  return self;
}

- bigintobjvec_reference:(bigintobjvec_c *)aReference
{
  return [[self clone] dobigintobjvec_reference:aReference];
}

- capacity:(int)aCapacity
{
  bigintobjvec_c c;
  assert ([self check]);
  bigintobjvec_initcapacity (&c, aCapacity, bigintobjvec_getargs (self));
  return bigintobjvec_c2id (self, &c);
}

- numScalars:(int)numScalars
{
  bigintobjvec_c c;
  assert ([self check]);
  bigintobjvec_initcount (&c, numScalars, bigintobjvec_getargs (self));
  return bigintobjvec_c2id (self, &c);
}


- scalarZero
{
  return scalarZero;
}

- (int) numScalars
{
  assert ([self check]);
  return bigintobjvec_count (&value);
}


- insertScalar:aScalar
{
  bigintobj_c c;
  assert ([aScalar check]);
  assert ([self check]);
  bigintobjvec_insertfirst (&value, bigintobj_id2ref (aScalar, &c), bigintobjvec_getargs (self));
  assert ([aScalar check]);
  assert ([self check]);
  [self invalidate];
  return self;
}

- insertScalar:aScalar at:(int)i
{
  bigintobj_c c;
  assert (aScalar);
  assert ([self check]);
  bigintobjvec_insertat (&value, bigintobj_id2ref (aScalar, &c), i, bigintobjvec_getargs (self));
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
      bigintobj_t t = bigintobjvec_first (&value, bigintobjvec_getargs (self));
      assert ([self check]);
      res = bigintobj_t2id (scalarZero, t);
      bigintobjvec_freefirst (&value, bigintobjvec_getargs (self));
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
  res = bigintobj_t2id (scalarZero, bigintobjvec_at (&value, i, bigintobjvec_getargs (self)));
  bigintobjvec_freeat (&value, i, bigintobjvec_getargs (self));
  assert ([self check]);
  assert ([res check]);
  [self invalidate];
  return res;
}


- placeScalar:aScalar at:(int)i
{
  bigintobj_c c;
  assert ([aScalar check]);
  assert ([self check]);
  bigintobjvec_place (&value, bigintobj_id2ref (aScalar, &c), i, bigintobjvec_getargs (self));
  assert ([aScalar check]);
  assert ([self check]);
  [self invalidate];
  return self;
}

- replaceScalarAt:(int)i with:aScalar
{
  id res;
  bigintobj_c c;
  bigintobj_t t = bigintobjvec_at (&value, i, bigintobjvec_getargs (self));
  assert ([self check]);
  res = bigintobj_t2id (scalarZero, t);
  bigintobjvec_place (&value, bigintobj_id2ref (aScalar, &c), i, bigintobjvec_getargs (self));
  assert ([aScalar check]);
  assert ([self check]);
  assert ([res check]);
  [self invalidate];
  return res;
}


- eachScalar
{
  id aSequence = [bigintobjvec_sequence content:self];
  return [CASequence over:aSequence];
}

- elt_bigintobjvec_ix:(bigintobjvec_ixt)ix
{
  if (bigintobjvec_ix_ismatch (ix))
    {
      bigintobj_t t = bigintobjvec_elt (&value, ix, bigintobjvec_getargs (self));
      return bigintobj_t2id (scalarZero, t);
    }
  else
    {
      return nil;
    }
}


- dotMultiply:b
{
  bigintobj_c c;		/* carrier for scalar */
  bigintobjvec_oodotmul (&c, &value, [b bigintobjvec_value], bigintobjvec_getargs (self));
  /* now promote the carrier to object */
  /* all of this used to be very difficult in 0.6 */
  return bigintobj_c2id (scalarZero, &c);
}

- dotSquare
{
  bigintobj_c c;		/* carrier for scalar */
  bigintobjvec_oodotsqr (&c, &value, bigintobjvec_getargs (self));
  /* now promote the carrier to object */
  /* all of this used to be very difficult in 0.6 */
  return bigintobj_c2id (scalarZero, &c);
}


- fileOutOn:aFiler
{
  bigintobjvec_args args;
  assert ([self check]);
  [super fileOutOn:aFiler];
  args = bigintobjvec_getargs (self);
  bigintobjvec_args_fileOut (aFiler, &args);
  bigintobjvec_fileOut (aFiler, &value, args);
  return self;
}

- fileInFrom:aFiler
{
  bigintobjvec_args args;
  [super fileInFrom:aFiler];
  bigintobjvec_args_fileIn (aFiler, &args);
  bigintobjvec_fileIn (aFiler, &value, args);
  return self;
}

- (unsigned) hash
{
  return bigintobjvec_hash (bigintobjvec_id2t (self), bigintobjvec_getargs (self));
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
      return bigintobjvec_iseq (bigintobjvec_id2t (self), bigintobjvec_id2t (b), bigintobjvec_getargs (self));
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
      return !bigintobjvec_iseq (bigintobjvec_id2t (self), bigintobjvec_id2t (b), bigintobjvec_getargs (self));
    }
}

- (BOOL) isZero
{
  assert ([self check]);
  return bigintobjvec_iszero (bigintobjvec_id2t (self), bigintobjvec_getargs (self));
}

- (BOOL) notZero
{
  assert ([self check]);
  return !bigintobjvec_iszero (bigintobjvec_id2t (self), bigintobjvec_getargs (self));
}

- (BOOL) isOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return bigintobjvec_isop (bigintobjvec_id2t (self), bigintobjvec_id2t (b), bigintobjvec_getargs (self));
}

- (BOOL) notOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return !bigintobjvec_isop (bigintobjvec_id2t (self), bigintobjvec_id2t (b), bigintobjvec_getargs (self));
}

- negate
{
  bigintobjvec_c c;
  assert ([self check]);
  bigintobjvec_ooneg (&c, bigintobjvec_id2t (self), bigintobjvec_getargs (self));
  return bigintobjvec_c2id (self, &c);
}

- _double:(int)v
{
  bigintobjvec_c c;
  assert ([self check]);
  bigintobjvec_oodbl (&c, bigintobjvec_id2t (self), v, bigintobjvec_getargs (self));
  return bigintobjvec_c2id (self, &c);
}

- double
{
  bigintobjvec_c c;
  assert ([self check]);
  bigintobjvec_oodbl (&c, bigintobjvec_id2t (self), +1, bigintobjvec_getargs (self));
  return bigintobjvec_c2id (self, &c);
}

- _add:(int)v:b:(int)w
{
  bigintobjvec_c c;
  assert ([self sameClass:b] && v * v == 1 && w * w == 1 && self != b);
  bigintobjvec_ooadd (&c, bigintobjvec_id2t (self), v, bigintobjvec_id2t (b), w, bigintobjvec_getargs (self));
  return bigintobjvec_c2id (self, &c);
}

- add:b
{
  bigintobjvec_c c;
  assert ([self checkSameClass:b] && self != b);
  bigintobjvec_ooadd (&c, bigintobjvec_id2t (self), +1, bigintobjvec_id2t (b), +1, bigintobjvec_getargs (self));
  return bigintobjvec_c2id (self, &c);
}

- subtract:b
{
  bigintobjvec_c c;
  assert ([self checkSameClass:b] && self != b);
  bigintobjvec_ooadd (&c, bigintobjvec_id2t (self), +1, bigintobjvec_id2t (b), -1, bigintobjvec_getargs (self));
  return bigintobjvec_c2id (self, &c);
}

- multiplyScalar:s
{
  bigintobjvec_c c;
  bigintobj_c sc;
  bigintobjvec_oomulsc (&c, bigintobjvec_id2t (self), bigintobj_id2ref (s, &sc), bigintobjvec_getargs (self));
  return bigintobjvec_c2id (self, &c);
}

- divideScalar:s
{
  bigintobjvec_c c;
  bigintobj_c sc;
  BOOL failed = bigintobjvec_oodivsc (&c, bigintobjvec_id2t (self), bigintobj_id2ref (s, &sc), bigintobjvec_getargs (self));
  return (failed) ? nil : bigintobjvec_c2id (self, &c);
}

- _add:(int)v:B multiplyScalar:b:(int)w
{
  bigintobjvec_c c;
  bigintobj_c bc;
  assert ([self sameClass:B] && [scalarZero sameClass:b] && v * v == 1 && w * w == 1);
  bigintobjvec_ooaddmulsc (&c, bigintobjvec_id2t (self), v, bigintobjvec_id2t (B), bigintobj_id2ref (b, &bc), w, bigintobjvec_getargs (self));
  return bigintobjvec_c2id (self, &c);
}

- _multiplyScalar:a:(int)v add:B:(int)w
{
  bigintobjvec_c c;
  bigintobj_c ac;
  assert ([scalarZero sameClass:a] && [self sameClass:B] && v * v == 1 && w * w == 1);
  bigintobjvec_oomulscadd (&c, bigintobjvec_id2t (self), bigintobj_id2ref (a, &ac), v, bigintobjvec_id2t (B), w, bigintobjvec_getargs (self));
  return bigintobjvec_c2id (self, &c);
}

- _multiplyScalar:a:(int)v add:B multiplyScalar:b:(int)w
{
  bigintobjvec_c c;
  bigintobj_c ac, bc;
  assert ([scalarZero sameClass:a] && [self sameClass:B] && [scalarZero sameClass:b] && v * v == 1 && w * w == 1);
  bigintobjvec_oomulscaddmulsc (&c, bigintobjvec_id2t (self), bigintobj_id2ref (a, &ac), v, bigintobjvec_id2t (B), bigintobj_id2ref (b, &bc), w, bigintobjvec_getargs (self));
  return bigintobjvec_c2id (self, &c);
}

@end
 
