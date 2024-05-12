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
 * $Id: idespolc.m,v 1.6 2000/10/12 14:40:25 stes Exp $
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
bigintobj_vardnsexpdegspsterm_monom_cval (bigintobj_vardnsexpdegspsterm_t self)
{
  return &self->data;
}

static vardnsmonom_t 
bigintobj_vardnsexpdegspsterm_monom (bigintobj_vardnsexpdegspsterm_t self)
{
#if vardnsmonom_pervalue
  return self->data;
#else
  return bigintobj_vardnsexpdegspsterm_monom_cval (self);
#endif
}

/* stes - mar31,1997
 * change for DEC alpha to exclude varsized scalars
 */

static bigintobj_c *
bigintobj_vardnsexpdegspsterm_scal_cval (bigintobj_vardnsexpdegspsterm_t self, bigintobj_vardnsexpdegspsterm_args args)
{
  return &self->scal;
}

static bigintobj_t 
bigintobj_vardnsexpdegspsterm_scal (bigintobj_vardnsexpdegspsterm_t self, bigintobj_vardnsexpdegspsterm_args args)
{
#if bigintobj_pervalue
  return self->scal;
#else
  return bigintobj_vardnsexpdegspsterm_scal_cval (self, args);
#endif
}

static int 
bigintobj_vardnsexpdegspsterm_check (bigintobj_vardnsexpdegspsterm_t self, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (bigintobj_check (bigintobj_vardnsexpdegspsterm_scal (self, args), args.sargs));
  assert (!bigintobj_iszero (bigintobj_vardnsexpdegspsterm_scal (self, args), args.sargs));
  assert (vardnsmonom_check (bigintobj_vardnsexpdegspsterm_monom (self), args.margs));
  return 1;
}

static int 
bigintobj_vardnsexpdegspsterm_bsize (bigintobj_vardnsexpdegspsterm_args args)
{
  /* this is sizeof(vardnsmonom_c) too much but why bother ? */
  return sizeof (struct bigintobj_vardnsexpdegspsterm) + vardnsmonom_bsize (args.margs);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_alloc (bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_t p;
  int n = bigintobj_vardnsexpdegspsterm_bsize (args);
  p = (bigintobj_vardnsexpdegspsterm_t) OC_Malloc (n);
#if OBJC_REFCNT
  memset (p, 0, n);
#endif
  return p;
}

static void 
bigintobj_vardnsexpdegspsterm_clear (bigintobj_vardnsexpdegspsterm_t self, bigintobj_vardnsexpdegspsterm_args args)
{
  vardnsmonom_clear (bigintobj_vardnsexpdegspsterm_monom_cval (self), args.margs);
  bigintobj_clear (bigintobj_vardnsexpdegspsterm_scal_cval (self, args), args.sargs);
}

static void 
bigintobj_vardnsexpdegspsterm_free (bigintobj_vardnsexpdegspsterm_t self, bigintobj_vardnsexpdegspsterm_args args)
{
  /* invalidating links not always helps : buggy code might work because
   * links were cleared...        self->nlink = NULL;self->plink = NULL;
   */
  OC_Free (self);
}

static int 
bigintobj_vardnsexpdegspsterm_cmp (bigintobj_vardnsexpdegspsterm_t a, bigintobj_vardnsexpdegspsterm_t b, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (bigintobj_vardnsexpdegspsterm_check (a, args) && bigintobj_vardnsexpdegspsterm_check (b, args));
  return vardnsmonom_cmp (bigintobj_vardnsexpdegspsterm_monom (a), bigintobj_vardnsexpdegspsterm_monom (b), args.margs);
}

static int 
bigintobj_vardnsexpdegspsterm_cmpmonom (bigintobj_vardnsexpdegspsterm_t a, vardnsmonom_t b, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (bigintobj_vardnsexpdegspsterm_check (a, args) && vardnsmonom_check (b, args.margs));
  return vardnsmonom_cmp (bigintobj_vardnsexpdegspsterm_monom (a), b, args.margs);
}

static int 
bigintobj_vardnsexpdegspsterm_cmpmul (bigintobj_vardnsexpdegspsterm_t a, bigintobj_vardnsexpdegspsterm_t b, vardnsmonom_t m, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (bigintobj_vardnsexpdegspsterm_check (a, args) && bigintobj_vardnsexpdegspsterm_check (b, args));
  assert (vardnsmonom_check (m, args.margs));
  return vardnsmonom_cmpmul (bigintobj_vardnsexpdegspsterm_monom (a), bigintobj_vardnsexpdegspsterm_monom (b), m, args.margs);
}

static int 
bigintobj_vardnsexpdegspsterm_deg (bigintobj_vardnsexpdegspsterm_t a, bigintobj_vardnsexpdegspsterm_args args)
{
  return vardnsmonom_deg (bigintobj_vardnsexpdegspsterm_monom (a), args.margs);
}

static int 
bigintobj_vardnsexpdegspsterm_iszero (bigintobj_vardnsexpdegspsterm_t self, bigintobj_vardnsexpdegspsterm_args args)
{
  return bigintobj_iszero (bigintobj_vardnsexpdegspsterm_scal (self, args), args.sargs);
}

static int 
bigintobj_vardnsexpdegspsterm_isone (bigintobj_vardnsexpdegspsterm_t self, bigintobj_vardnsexpdegspsterm_args args)
{
  return bigintobj_isone (bigintobj_vardnsexpdegspsterm_scal (self, args), args.sargs) && vardnsmonom_isone (bigintobj_vardnsexpdegspsterm_monom (self), args.margs);
}

static int 
bigintobj_vardnsexpdegspsterm_isminusone (bigintobj_vardnsexpdegspsterm_t self, bigintobj_vardnsexpdegspsterm_args args)
{
  return bigintobj_isminusone (bigintobj_vardnsexpdegspsterm_scal (self, args), args.sargs) && vardnsmonom_isone (bigintobj_vardnsexpdegspsterm_monom (self), args.margs);
}

static int 
bigintobj_vardnsexpdegspsterm_iseq (bigintobj_vardnsexpdegspsterm_t a, bigintobj_vardnsexpdegspsterm_t b, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (bigintobj_vardnsexpdegspsterm_check (a, args) && bigintobj_vardnsexpdegspsterm_check (b, args));
  return vardnsmonom_iseq (bigintobj_vardnsexpdegspsterm_monom (a), bigintobj_vardnsexpdegspsterm_monom (b), args.margs) && bigintobj_iseq (bigintobj_vardnsexpdegspsterm_scal (a, args), bigintobj_vardnsexpdegspsterm_scal (b, args), args.sargs);
}

static int 
bigintobj_vardnsexpdegspsterm_isop (bigintobj_vardnsexpdegspsterm_t a, bigintobj_vardnsexpdegspsterm_t b, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (bigintobj_vardnsexpdegspsterm_check (a, args) && bigintobj_vardnsexpdegspsterm_check (b, args));
  return vardnsmonom_iseq (bigintobj_vardnsexpdegspsterm_monom (a), bigintobj_vardnsexpdegspsterm_monom (b), args.margs) && bigintobj_isop (bigintobj_vardnsexpdegspsterm_scal (a, args), bigintobj_vardnsexpdegspsterm_scal (b, args), args.sargs);
}

static void 
bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A)
{
  C->nlink = A;
  A->plink = C;
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A)
{
  bigintobj_vardnsexpdegspsterm_glue (C, A);
  return A;
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_delete (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_t C = A->nlink;
  bigintobj_vardnsexpdegspsterm_glue (A->plink, C);
  bigintobj_vardnsexpdegspsterm_clear (A, args);
  bigintobj_vardnsexpdegspsterm_free (A, args);
  return C;
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_condcns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t new, bigintobj_vardnsexpdegspsterm_args args)
{
  if (bigintobj_vardnsexpdegspsterm_iszero (new, args))
    {
      bigintobj_vardnsexpdegspsterm_clear (new, args);
      bigintobj_vardnsexpdegspsterm_free (new, args);
      return C;
    }
  else
    {
      assert (bigintobj_vardnsexpdegspsterm_check (new, args));
      return bigintobj_vardnsexpdegspsterm_cns (C, new);
    }
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_conddelete (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_args args)
{
  if (bigintobj_vardnsexpdegspsterm_iszero (A, args))
    {
      return bigintobj_vardnsexpdegspsterm_delete (A, args);
    }
  else
    {
      return A->nlink;
    }
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_copymonomsc_cns (bigintobj_vardnsexpdegspsterm_t C, vardnsmonom_t m, bigintobj_t s, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_t new = bigintobj_vardnsexpdegspsterm_alloc (args);

  bigintobj_copy (bigintobj_vardnsexpdegspsterm_scal_cval (new, args), s, args.sargs);
  vardnsmonom_copy (bigintobj_vardnsexpdegspsterm_monom_cval (new), m, args.margs);

  assert (bigintobj_vardnsexpdegspsterm_check (new, args));
  return bigintobj_vardnsexpdegspsterm_cns (C, new);
}

static void 
bigintobj_vardnsexpdegspsterm_copymonomsc (bigintobj_vardnsexpdegspsterm_t C, vardnsmonom_t m, bigintobj_t s, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspsterm_copymonomsc_cns (C, m, s, args), CT);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_deepcopymonomsc_cns (bigintobj_vardnsexpdegspsterm_t C, vardnsmonom_t m, bigintobj_t s, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_t new = bigintobj_vardnsexpdegspsterm_alloc (args);

  bigintobj_deepcopy (bigintobj_vardnsexpdegspsterm_scal_cval (new, args), s, args.sargs);
  vardnsmonom_copy (bigintobj_vardnsexpdegspsterm_monom_cval (new), m, args.margs);

  assert (bigintobj_vardnsexpdegspsterm_check (new, args));
  return bigintobj_vardnsexpdegspsterm_cns (C, new);
}

static void 
bigintobj_vardnsexpdegspsterm_deepcopymonomsc (bigintobj_vardnsexpdegspsterm_t C, vardnsmonom_t m, bigintobj_t s, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspsterm_deepcopymonomsc_cns (C, m, s, args), CT);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_copy_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_args args)
{
  return bigintobj_vardnsexpdegspsterm_copymonomsc_cns (C, bigintobj_vardnsexpdegspsterm_monom (A), bigintobj_vardnsexpdegspsterm_scal (A, args), args);
}

static void 
bigintobj_vardnsexpdegspsterm_copy (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspsterm_copy_cns (C, A, args), CT);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_deepcopy_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_args args)
{
  return bigintobj_vardnsexpdegspsterm_deepcopymonomsc_cns (C, bigintobj_vardnsexpdegspsterm_monom (A), bigintobj_vardnsexpdegspsterm_scal (A, args), args);
}

static void 
bigintobj_vardnsexpdegspsterm_deepcopy (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspsterm_deepcopy_cns (C, A, args), CT);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_ooneg_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_t new = bigintobj_vardnsexpdegspsterm_alloc (args);
  assert (bigintobj_vardnsexpdegspsterm_iszero (A, args) == NO);

  bigintobj_ooneg (bigintobj_vardnsexpdegspsterm_scal_cval (new, args), bigintobj_vardnsexpdegspsterm_scal (A, args), args.sargs);
  vardnsmonom_copy (bigintobj_vardnsexpdegspsterm_monom_cval (new), bigintobj_vardnsexpdegspsterm_monom (A), args.margs);

  return bigintobj_vardnsexpdegspsterm_cns (C, new);
}

static void 
bigintobj_vardnsexpdegspsterm_ooneg (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspsterm_ooneg_cns (C, A, args), CT);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_inneg (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (bigintobj_vardnsexpdegspsterm_iszero (A, args) == NO);
  bigintobj_inneg (bigintobj_vardnsexpdegspsterm_scal_cval (A, args), args.sargs);
  assert (bigintobj_vardnsexpdegspsterm_iszero (A, args) == NO);
  return A->nlink;
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_oonegv_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, int v, bigintobj_vardnsexpdegspsterm_args args)
{
  return (v == -1) ? bigintobj_vardnsexpdegspsterm_ooneg_cns (C, A, args) : bigintobj_vardnsexpdegspsterm_copy_cns (C, A, args);
}

static void 
bigintobj_vardnsexpdegspsterm_oonegv (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, int v, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspsterm_oonegv_cns (C, A, v, args), CT);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_innegv (bigintobj_vardnsexpdegspsterm_t A, int v, bigintobj_vardnsexpdegspsterm_args args)
{
  return (v == -1) ? bigintobj_vardnsexpdegspsterm_inneg (A, args) : A->nlink;
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_oodbl_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, int v, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_t new = bigintobj_vardnsexpdegspsterm_alloc (args);
  assert (bigintobj_vardnsexpdegspsterm_iszero (A, args) == NO);

  bigintobj_oodbl (bigintobj_vardnsexpdegspsterm_scal_cval (new, args), bigintobj_vardnsexpdegspsterm_scal (A, args), v, args.sargs);
  vardnsmonom_copy (bigintobj_vardnsexpdegspsterm_monom_cval (new), bigintobj_vardnsexpdegspsterm_monom (A), args.margs);

  return bigintobj_vardnsexpdegspsterm_condcns (C, new, args);
}

static void 
bigintobj_vardnsexpdegspsterm_oodbl (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, int v, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspsterm_oodbl_cns (C, A, v, args), CT);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_indbl (bigintobj_vardnsexpdegspsterm_t A, int v, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (bigintobj_vardnsexpdegspsterm_iszero (A, args) == NO);
  bigintobj_indbl (bigintobj_vardnsexpdegspsterm_scal_cval (A, args), v, args.sargs);
  return bigintobj_vardnsexpdegspsterm_conddelete (A, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_ooaddsc_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, int v, bigintobj_t B, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_t new = bigintobj_vardnsexpdegspsterm_alloc (args);
  bigintobj_ooadd (bigintobj_vardnsexpdegspsterm_scal_cval (new, args), bigintobj_vardnsexpdegspsterm_scal (A, args), v, B, w, args.sargs);
  vardnsmonom_copy (bigintobj_vardnsexpdegspsterm_monom_cval (new), bigintobj_vardnsexpdegspsterm_monom (A), args.margs);
  return bigintobj_vardnsexpdegspsterm_condcns (C, new, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_inaddsc (bigintobj_vardnsexpdegspsterm_t A, int v, bigintobj_t B, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_inadd (bigintobj_vardnsexpdegspsterm_scal_cval (A, args), v, B, w, args.sargs);
  return bigintobj_vardnsexpdegspsterm_conddelete (A, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_ooadd_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, int v, bigintobj_vardnsexpdegspsterm_t B, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (0 == bigintobj_vardnsexpdegspsterm_cmp (A, B, args));
  assert (bigintobj_vardnsexpdegspsterm_iszero (A, args) == NO && bigintobj_vardnsexpdegspsterm_iszero (B, args) == NO);
  return bigintobj_vardnsexpdegspsterm_ooaddsc_cns (C, A, v, bigintobj_vardnsexpdegspsterm_scal (B, args), w, args);
}

static void 
bigintobj_vardnsexpdegspsterm_ooadd (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, int v, bigintobj_vardnsexpdegspsterm_t B, int w, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspsterm_ooadd_cns (C, A, v, B, w, args), CT);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_inadd (bigintobj_vardnsexpdegspsterm_t A, int v, bigintobj_vardnsexpdegspsterm_t B, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (0 == bigintobj_vardnsexpdegspsterm_cmp (A, B, args));
  assert (bigintobj_vardnsexpdegspsterm_iszero (A, args) == NO && bigintobj_vardnsexpdegspsterm_iszero (B, args) == NO);
  return bigintobj_vardnsexpdegspsterm_inaddsc (A, v, bigintobj_vardnsexpdegspsterm_scal (B, args), w, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_oomulsc_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_t new = bigintobj_vardnsexpdegspsterm_alloc (args);

  bigintobj_oomulv (bigintobj_vardnsexpdegspsterm_scal_cval (new, args), bigintobj_vardnsexpdegspsterm_scal (A, args), s, v, args.sargs);
  vardnsmonom_copy (bigintobj_vardnsexpdegspsterm_monom_cval (new), bigintobj_vardnsexpdegspsterm_monom (A), args.margs);

  return bigintobj_vardnsexpdegspsterm_condcns (C, new, args);
}

static void 
bigintobj_vardnsexpdegspsterm_oomulsc (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspsterm_oomulsc_cns (C, A, s, v, args), CT);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_inmulsc (bigintobj_vardnsexpdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_inmulv (bigintobj_vardnsexpdegspsterm_scal_cval (A, args), s, v, args.sargs);
  return bigintobj_vardnsexpdegspsterm_conddelete (A, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_oomulmonomsc_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, vardnsmonom_t m, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_t new = bigintobj_vardnsexpdegspsterm_alloc (args);

  bigintobj_oomulv (bigintobj_vardnsexpdegspsterm_scal_cval (new, args), bigintobj_vardnsexpdegspsterm_scal (A, args), s, v, args.sargs);
  vardnsmonom_oomul (bigintobj_vardnsexpdegspsterm_monom_cval (new), bigintobj_vardnsexpdegspsterm_monom (A), m, args.margs);

  return bigintobj_vardnsexpdegspsterm_condcns (C, new, args);
}

static void 
bigintobj_vardnsexpdegspsterm_oomulmonomsc (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, vardnsmonom_t m, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspsterm_oomulmonomsc_cns (C, A, m, s, v, args), CT);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_inmulmonomsc (bigintobj_vardnsexpdegspsterm_t A, vardnsmonom_t m, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_inmulv (bigintobj_vardnsexpdegspsterm_scal_cval (A, args), s, v, args.sargs);
  vardnsmonom_inmul (bigintobj_vardnsexpdegspsterm_monom_cval (A), m, args.margs);

  return bigintobj_vardnsexpdegspsterm_conddelete (A, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_ooaddscmulsc_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, int v, bigintobj_t B, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_t new = bigintobj_vardnsexpdegspsterm_alloc (args);

  bigintobj_ooaddmul (bigintobj_vardnsexpdegspsterm_scal_cval (new, args), bigintobj_vardnsexpdegspsterm_scal (A, args), v, B, t, w, args.sargs);
  vardnsmonom_copy (bigintobj_vardnsexpdegspsterm_monom_cval (new), bigintobj_vardnsexpdegspsterm_monom (A), args.margs);

  return bigintobj_vardnsexpdegspsterm_condcns (C, new, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_inaddscmulsc (bigintobj_vardnsexpdegspsterm_t A, int v, bigintobj_t B, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_inaddmul (bigintobj_vardnsexpdegspsterm_scal_cval (A, args), v, B, t, w, args.sargs);
  return bigintobj_vardnsexpdegspsterm_conddelete (A, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_ooaddmulsc_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (0 == (bigintobj_vardnsexpdegspsterm_cmp (A, B, args)));
  return bigintobj_vardnsexpdegspsterm_ooaddscmulsc_cns (C, A, v, bigintobj_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_ooaddmulmonomsc_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, int v, bigintobj_vardnsexpdegspsterm_t B, vardnsmonom_t m, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (0 == (bigintobj_vardnsexpdegspsterm_cmpmul (A, B, m, args)));
  return bigintobj_vardnsexpdegspsterm_ooaddscmulsc_cns (C, A, v, bigintobj_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static void 
bigintobj_vardnsexpdegspsterm_ooaddmulsc (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspsterm_ooaddmulsc_cns (C, A, v, B, t, w, args), CT);
}

static void 
bigintobj_vardnsexpdegspsterm_ooaddmulmonomsc (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, int v, bigintobj_vardnsexpdegspsterm_t B, vardnsmonom_t m, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspsterm_ooaddmulmonomsc_cns (C, A, v, B, m, t, w, args), CT);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_inaddmulsc (bigintobj_vardnsexpdegspsterm_t A, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (0 == (bigintobj_vardnsexpdegspsterm_cmp (A, B, args)));
  return bigintobj_vardnsexpdegspsterm_inaddscmulsc (A, v, bigintobj_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_inaddmulmonomsc (bigintobj_vardnsexpdegspsterm_t A, int v, bigintobj_vardnsexpdegspsterm_t B, vardnsmonom_t m, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (0 == (bigintobj_vardnsexpdegspsterm_cmpmul (A, B, m, args)));
  return bigintobj_vardnsexpdegspsterm_inaddscmulsc (A, v, bigintobj_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_oomulscaddsc_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_t s, int v, bigintobj_t B, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_t new = bigintobj_vardnsexpdegspsterm_alloc (args);

  bigintobj_oomuladd (bigintobj_vardnsexpdegspsterm_scal_cval (new, args), bigintobj_vardnsexpdegspsterm_scal (A, args), s, v, B, w, args.sargs);
  vardnsmonom_copy (bigintobj_vardnsexpdegspsterm_monom_cval (new), bigintobj_vardnsexpdegspsterm_monom (A), args.margs);

  return bigintobj_vardnsexpdegspsterm_condcns (C, new, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_inmulscaddsc (bigintobj_vardnsexpdegspsterm_t A, bigintobj_t s, int v, bigintobj_t B, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_inmuladd (bigintobj_vardnsexpdegspsterm_scal_cval (A, args), s, v, B, w, args.sargs);
  return bigintobj_vardnsexpdegspsterm_conddelete (A, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_oomulscadd_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_t B, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (0 == (bigintobj_vardnsexpdegspsterm_cmp (A, B, args)));
  return bigintobj_vardnsexpdegspsterm_oomulscaddsc_cns (C, A, s, v, bigintobj_vardnsexpdegspsterm_scal (B, args), w, args);
}

static void 
bigintobj_vardnsexpdegspsterm_oomulscadd (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_t B, int w, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspsterm_oomulscadd_cns (C, A, s, v, B, w, args), CT);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_inmulscadd (bigintobj_vardnsexpdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_t B, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (0 == (bigintobj_vardnsexpdegspsterm_cmp (A, B, args)));
  return bigintobj_vardnsexpdegspsterm_inmulscaddsc (A, s, v, bigintobj_vardnsexpdegspsterm_scal (B, args), w, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_oomulscaddscmulsc_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_t s, int v, bigintobj_t B, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_t new = bigintobj_vardnsexpdegspsterm_alloc (args);
  bigintobj_oomuladdmul (bigintobj_vardnsexpdegspsterm_scal_cval (new, args), bigintobj_vardnsexpdegspsterm_scal (A, args), s, v, B, t, w, args.sargs);
  vardnsmonom_copy (bigintobj_vardnsexpdegspsterm_monom_cval (new), bigintobj_vardnsexpdegspsterm_monom (A), args.margs);

  return bigintobj_vardnsexpdegspsterm_condcns (C, new, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_inmulscaddscmulsc (bigintobj_vardnsexpdegspsterm_t A, bigintobj_t s, int v, bigintobj_t B, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_inmuladdmul (bigintobj_vardnsexpdegspsterm_scal_cval (A, args), s, v, B, t, w, args.sargs);
  return bigintobj_vardnsexpdegspsterm_conddelete (A, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_oomulscaddmulsc_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (0 == (bigintobj_vardnsexpdegspsterm_cmp (A, B, args)));
  return bigintobj_vardnsexpdegspsterm_oomulscaddscmulsc_cns (C, A, s, v, bigintobj_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_oomulscaddmulmonomsc_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_t B, vardnsmonom_t m, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (0 == (bigintobj_vardnsexpdegspsterm_cmpmul (A, B, m, args)));
  return bigintobj_vardnsexpdegspsterm_oomulscaddscmulsc_cns (C, A, s, v, bigintobj_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static void 
bigintobj_vardnsexpdegspsterm_oomulscaddmulsc (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspsterm_oomulscaddmulsc_cns (C, A, s, v, B, t, w, args), CT);
}

static void 
bigintobj_vardnsexpdegspsterm_oomulscaddmulmonomsc (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_t B, vardnsmonom_t m, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspsterm_oomulscaddmulmonomsc_cns (C, A, s, v, B, m, t, w, args), CT);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_inmulscaddmulsc (bigintobj_vardnsexpdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (0 == (bigintobj_vardnsexpdegspsterm_cmp (A, B, args)));
  return bigintobj_vardnsexpdegspsterm_inmulscaddscmulsc (A, s, v, bigintobj_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_inmulscaddmulmonomsc (bigintobj_vardnsexpdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_t B, vardnsmonom_t m, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (0 == (bigintobj_vardnsexpdegspsterm_cmpmul (A, B, m, args)));
  return bigintobj_vardnsexpdegspsterm_inmulscaddscmulsc (A, s, v, bigintobj_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_oodivsc_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_t s, bigintobj_vardnsexpdegspsterm_args args)
{
  BOOL failed;
  bigintobj_vardnsexpdegspsterm_t new = bigintobj_vardnsexpdegspsterm_alloc (args);

  failed = bigintobj_oodiv (bigintobj_vardnsexpdegspsterm_scal_cval (new, args), bigintobj_vardnsexpdegspsterm_scal (A, args), s, args.sargs);
  if (failed)
    {
      bigintobj_vardnsexpdegspsterm_free (new, args);
      return NULL;
    }

  vardnsmonom_copy (bigintobj_vardnsexpdegspsterm_monom_cval (new), bigintobj_vardnsexpdegspsterm_monom (A), args.margs);

  return bigintobj_vardnsexpdegspsterm_condcns (C, new, args);
}

#if 0				/* unused ! why did I write this ? */
static BOOL 
bigintobj_vardnsexpdegspsterm_oodivsc (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_t s, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  if ((C = bigintobj_vardnsexpdegspsterm_oodivsc_cns (C, A, s, args)))
    {
      bigintobj_vardnsexpdegspsterm_glue (C, CT);
      return SUCCESS;
    }
  else
    {
      return FAILURE;
    }
}
#endif

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_indivsc (bigintobj_vardnsexpdegspsterm_t A, bigintobj_t s, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_indiv (bigintobj_vardnsexpdegspsterm_scal_cval (A, args), s, args.sargs);
  return bigintobj_vardnsexpdegspsterm_conddelete (A, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_oodivmonomsc_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, vardnsmonom_t m, bigintobj_t s, bigintobj_vardnsexpdegspsterm_args args)
{
  BOOL sfailed, mfailed;
  bigintobj_vardnsexpdegspsterm_t new = bigintobj_vardnsexpdegspsterm_alloc (args);

  sfailed = bigintobj_oodiv (bigintobj_vardnsexpdegspsterm_scal_cval (new, args), bigintobj_vardnsexpdegspsterm_scal (A, args), s, args.sargs);
  mfailed = vardnsmonom_oodiv (bigintobj_vardnsexpdegspsterm_monom_cval (new), bigintobj_vardnsexpdegspsterm_monom (A), m, args.margs);

  if (sfailed || mfailed)
    {
      /* both failures are possible in the multivariate case */
      bigintobj_vardnsexpdegspsterm_free (new, args);
      return NULL;
    }

  return bigintobj_vardnsexpdegspsterm_condcns (C, new, args);
}

#if 0				/* unused ! why did I write this ? */
static BOOL 
bigintobj_vardnsexpdegspsterm_oodivmonomsc (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, vardnsmonom_t m, bigintobj_t s, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  if ((C = bigintobj_vardnsexpdegspsterm_oodivmonomsc_cns (C, A, m, s, args)))
    {
      bigintobj_vardnsexpdegspsterm_glue (C, CT);
      return SUCCESS;
    }
  else
    {
      return FAILURE;
    }
}
#endif

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_indivmonomsc (bigintobj_vardnsexpdegspsterm_t A, vardnsmonom_t m, bigintobj_t s, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_indiv (bigintobj_vardnsexpdegspsterm_scal_cval (A, args), s, args.sargs);
  vardnsmonom_indiv (bigintobj_vardnsexpdegspsterm_monom_cval (A), m, args.margs);

  return bigintobj_vardnsexpdegspsterm_conddelete (A, args);
}

static void 
bigintobj_vardnsexpdegspsterm_args_fileOut (id aFiler, bigintobj_vardnsexpdegspsterm_args * args)
{
  bigintobj_args_fileOut (aFiler, &args->sargs);
  vardnsmonom_args_fileOut (aFiler, &args->margs);
}
static void 
bigintobj_vardnsexpdegspsterm_args_fileIn (id aFiler, bigintobj_vardnsexpdegspsterm_args * args)
{
  bigintobj_args_fileIn (aFiler, &args->sargs);
  vardnsmonom_args_fileIn (aFiler, &args->margs);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_fileOut (id aFiler, bigintobj_vardnsexpdegspsterm_t self, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (bigintobj_vardnsexpdegspsterm_check (self, args));

  bigintobj_fileOut (aFiler, bigintobj_vardnsexpdegspsterm_scal_cval (self, args), args.sargs);
  vardnsmonom_fileOut (aFiler, bigintobj_vardnsexpdegspsterm_monom_cval (self), args.margs);

  return self->nlink;
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspsterm_fileIn_cns (id aFiler, bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_t self = bigintobj_vardnsexpdegspsterm_alloc (args);

  bigintobj_fileIn (aFiler, bigintobj_vardnsexpdegspsterm_scal_cval (self, args), args.sargs);
  vardnsmonom_fileIn (aFiler, bigintobj_vardnsexpdegspsterm_monom_cval (self), args.margs);

  return bigintobj_vardnsexpdegspsterm_cns (C, self);
}

static int 
bigintobj_vardnsexpdegspslist_check (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_t prev;

  for (prev = NULL; A != AT; prev = A, A = A->nlink)
    {
      if (bigintobj_vardnsexpdegspsterm_check (A, args) == 0)
	return 0;
      if (prev && bigintobj_vardnsexpdegspsterm_cmp (prev, A, args) <= 0)
	return 0;
    }

  return 1;
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspslist_copy_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    {
      C = bigintobj_vardnsexpdegspsterm_copy_cns (C, A, args);
      A = A->nlink;
    }
  return C;
}

static void 
bigintobj_vardnsexpdegspslist_copy (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspslist_copy_cns (C, A, AT, args), CT);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspslist_deepcopy_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    {
      C = bigintobj_vardnsexpdegspsterm_deepcopy_cns (C, A, args);
      A = A->nlink;
    }
  return C;
}

static void 
bigintobj_vardnsexpdegspslist_deepcopy (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspslist_deepcopy_cns (C, A, AT, args), CT);
}

static void 
bigintobj_vardnsexpdegspslist_clear (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    {
      bigintobj_vardnsexpdegspsterm_clear (A, args);
      A = A->nlink;
    }
}

static void 
bigintobj_vardnsexpdegspslist_free (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_t t;
  for (; A != AT; A = t)
    {
      t = A->nlink;
      bigintobj_vardnsexpdegspsterm_free (A, args);
    }
}

static int 
bigintobj_vardnsexpdegspslist_count (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT)
{
  int c = 0;
  for (; A != AT; A = A->nlink)
    c++;
  return c;
}

static unsigned 
bigintobj_vardnsexpdegspslist_hash (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_vardnsexpdegspsterm_args args)
{
  return bigintobj_vardnsexpdegspslist_count (A, AT);
}

static int 
bigintobj_vardnsexpdegspslist_iseq (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_vardnsexpdegspsterm_t B, bigintobj_vardnsexpdegspsterm_t BT, bigintobj_vardnsexpdegspsterm_args args)
{
  for (; A != AT && B != BT; A = A->nlink, B = B->nlink)
    {
      if (!bigintobj_vardnsexpdegspsterm_iseq (A, B, args))
	return 0;
    }
  return (A == AT && B == BT);
}

static int 
bigintobj_vardnsexpdegspslist_isop (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_vardnsexpdegspsterm_t B, bigintobj_vardnsexpdegspsterm_t BT, bigintobj_vardnsexpdegspsterm_args args)
{
  for (; A != AT && B != BT; A = A->nlink, B = B->nlink)
    {
      if (!bigintobj_vardnsexpdegspsterm_isop (A, B, args))
	return 0;
    }
  return (A == AT && B == BT);
}

static int 
bigintobj_vardnsexpdegspslist_deg (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_vardnsexpdegspsterm_args args)
{
  return (A == AT) ? -1 : bigintobj_vardnsexpdegspsterm_deg (A, args);
}

static int 
bigintobj_vardnsexpdegspslist_maxdeg (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_vardnsexpdegspsterm_args args)
{
  int max = (A == AT) ? -1 : bigintobj_vardnsexpdegspsterm_deg (A, args);
  for (A = A->nlink; A != AT; A = A->nlink)
    {
      int d = bigintobj_vardnsexpdegspsterm_deg (A, args);
      if (max < d)
	max = d;
    }
  return max;
}

static int 
bigintobj_vardnsexpdegspslist_ord (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_vardnsexpdegspsterm_args args)
{
  return (A == AT) ? -1 : bigintobj_vardnsexpdegspsterm_deg (AT->plink, args);
}

static int 
bigintobj_vardnsexpdegspslist_mindeg (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_vardnsexpdegspsterm_args args)
{
  int min = (A == AT) ? -1 : bigintobj_vardnsexpdegspsterm_deg (A, args);
  for (A = A->nlink; A != AT; A = A->nlink)
    {
      int d = bigintobj_vardnsexpdegspsterm_deg (A, args);
      if (min > d)
	min = d;
    }
  return min;
}

static void 
bigintobj_vardnsexpdegspslist_insert (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, vardnsmonom_t m, bigintobj_t s, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (bigintobj_iszero (s, args.sargs) == NO);

  /* adding to zero */
  if (A == AT)
    {
      bigintobj_vardnsexpdegspsterm_copymonomsc (A, m, s, A, args);
      return;
    }

  /* tail append */
  if (bigintobj_vardnsexpdegspsterm_cmpmonom (AT->plink, m, args) > 0)
    {
      bigintobj_vardnsexpdegspsterm_copymonomsc (AT->plink, m, s, AT, args);
      return;
    }

  /* insertion */
  while (A != AT)
    {
      int cmp = bigintobj_vardnsexpdegspsterm_cmpmonom (A, m, args);
      if (cmp == 0)
	{
	  bigintobj_vardnsexpdegspsterm_inaddsc (A, +1, s, +1, args);
	  return;
	}
      if (cmp < 0)
	{
	  bigintobj_vardnsexpdegspsterm_copymonomsc (A->plink, m, s, A, args);
	  return;
	}
      A = A->nlink;
    }

  fprintf (stderr, "Shouldn't happen\n");
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspslist_ooneg_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    {
      C = bigintobj_vardnsexpdegspsterm_ooneg_cns (C, A, args);
      A = A->nlink;
    }
  return C;
}

static void 
bigintobj_vardnsexpdegspslist_ooneg (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspslist_ooneg_cns (C, A, AT, args), CT);
}

static void 
bigintobj_vardnsexpdegspslist_inneg (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    A = bigintobj_vardnsexpdegspsterm_inneg (A, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspslist_oonegv_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, int v, bigintobj_vardnsexpdegspsterm_args args)
{
  if (v == -1)
    {
      return bigintobj_vardnsexpdegspslist_ooneg_cns (C, A, AT, args);
    }
  else
    {
      return bigintobj_vardnsexpdegspslist_copy_cns (C, A, AT, args);
    }
}

static void 
bigintobj_vardnsexpdegspslist_oonegv (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, int v, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspslist_oonegv_cns (C, A, AT, v, args), CT);
}

static void 
bigintobj_vardnsexpdegspslist_innegv (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, int v, bigintobj_vardnsexpdegspsterm_args args)
{
  if (v == -1)
    bigintobj_vardnsexpdegspslist_inneg (A, AT, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspslist_oodbl_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, int v, bigintobj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    {
      C = bigintobj_vardnsexpdegspsterm_oodbl_cns (C, A, v, args);
      A = A->nlink;
    }
  return C;
}

static void 
bigintobj_vardnsexpdegspslist_oodbl (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, int v, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspslist_oodbl_cns (C, A, AT, v, args), CT);
}

static void 
bigintobj_vardnsexpdegspslist_indbl (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, int v, bigintobj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    A = bigintobj_vardnsexpdegspsterm_indbl (A, v, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspslist_ooadd_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_vardnsexpdegspsterm_t BT, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = bigintobj_vardnsexpdegspsterm_ooadd_cns (C, A, v, B, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = bigintobj_vardnsexpdegspsterm_oonegv_cns (C, B, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = bigintobj_vardnsexpdegspsterm_oonegv_cns (C, A, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return bigintobj_vardnsexpdegspslist_oonegv_cns (C, A, AT, v, args);
  if (B != BT)
    return bigintobj_vardnsexpdegspslist_oonegv_cns (C, B, BT, w, args);
  return C;
}

static void 
bigintobj_vardnsexpdegspslist_ooadd (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_vardnsexpdegspsterm_t BT, int w, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspslist_ooadd_cns (C, A, AT, v, B, BT, w, args), CT);
}

static void 
bigintobj_vardnsexpdegspslist_inadd (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_vardnsexpdegspsterm_t BT, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = bigintobj_vardnsexpdegspsterm_inadd (A, v, B, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  bigintobj_vardnsexpdegspsterm_oonegv (A->plink, B, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = bigintobj_vardnsexpdegspsterm_innegv (A, v, args);
	}
    }

  if (A != AT)
    bigintobj_vardnsexpdegspslist_innegv (A, AT, v, args);
  if (B != BT)
    bigintobj_vardnsexpdegspslist_oonegv (A->plink, B, BT, w, A, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspslist_oomulsc_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    {
      C = bigintobj_vardnsexpdegspsterm_oomulsc_cns (C, A, s, v, args);
      A = A->nlink;
    }
  return C;
}

static void 
bigintobj_vardnsexpdegspslist_oomulsc (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspslist_oomulsc_cns (C, A, AT, s, v, args), CT);
}

static void 
bigintobj_vardnsexpdegspslist_inmulsc (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    A = bigintobj_vardnsexpdegspsterm_inmulsc (A, s, v, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspslist_oomulmonomsc_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, vardnsmonom_t m, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    {
      C = bigintobj_vardnsexpdegspsterm_oomulmonomsc_cns (C, A, m, s, v, args);
      A = A->nlink;
    }
  return C;
}

static void 
bigintobj_vardnsexpdegspslist_oomulmonomsc (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, vardnsmonom_t m, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspslist_oomulmonomsc_cns (C, A, AT, m, s, v, args), CT);
}

static void 
bigintobj_vardnsexpdegspslist_inmulmonomsc (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, vardnsmonom_t m, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    A = bigintobj_vardnsexpdegspsterm_inmulmonomsc (A, m, s, v, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspslist_ooaddmulsc_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_vardnsexpdegspsterm_t BT, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = bigintobj_vardnsexpdegspsterm_ooaddmulsc_cns (C, A, v, B, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = bigintobj_vardnsexpdegspsterm_oomulsc_cns (C, B, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = bigintobj_vardnsexpdegspsterm_oonegv_cns (C, A, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return bigintobj_vardnsexpdegspslist_oonegv_cns (C, A, AT, v, args);
  if (B != BT)
    return bigintobj_vardnsexpdegspslist_oomulsc_cns (C, B, BT, t, w, args);
  return C;
}

static void 
bigintobj_vardnsexpdegspslist_ooaddmulsc (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_vardnsexpdegspsterm_t BT, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspslist_ooaddmulsc_cns (C, A, AT, v, B, BT, t, w, args), CT);
}

static void 
bigintobj_vardnsexpdegspslist_inaddmulsc (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_vardnsexpdegspsterm_t BT, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = bigintobj_vardnsexpdegspsterm_inaddmulsc (A, v, B, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  bigintobj_vardnsexpdegspsterm_oomulsc (A->plink, B, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = bigintobj_vardnsexpdegspsterm_innegv (A, v, args);
	}
    }

  if (A != AT)
    bigintobj_vardnsexpdegspslist_innegv (A, AT, v, args);
  if (B != BT)
    bigintobj_vardnsexpdegspslist_oomulsc (A->plink, B, BT, t, w, A, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspslist_ooaddmulmonomsc_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_vardnsexpdegspsterm_t BT, vardnsmonom_t m, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsexpdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  C = bigintobj_vardnsexpdegspsterm_ooaddmulmonomsc_cns (C, A, v, B, m, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = bigintobj_vardnsexpdegspsterm_oomulmonomsc_cns (C, B, m, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = bigintobj_vardnsexpdegspsterm_oonegv_cns (C, A, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return bigintobj_vardnsexpdegspslist_oonegv_cns (C, A, AT, v, args);
  if (B != BT)
    return bigintobj_vardnsexpdegspslist_oomulmonomsc_cns (C, B, BT, m, t, w, args);
  return C;
}

static void 
bigintobj_vardnsexpdegspslist_ooaddmulmonomsc (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_vardnsexpdegspsterm_t BT, vardnsmonom_t m, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspslist_ooaddmulmonomsc_cns (C, A, AT, v, B, BT, m, t, w, args), CT);
}

static void 
bigintobj_vardnsexpdegspslist_inaddmulmonomsc (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_vardnsexpdegspsterm_t BT, vardnsmonom_t m, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsexpdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  A = bigintobj_vardnsexpdegspsterm_inaddmulmonomsc (A, v, B, m, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  bigintobj_vardnsexpdegspsterm_oomulmonomsc (A->plink, B, m, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = bigintobj_vardnsexpdegspsterm_innegv (A, v, args);
	}
    }

  if (A != AT)
    bigintobj_vardnsexpdegspslist_innegv (A, AT, v, args);
  if (B != BT)
    bigintobj_vardnsexpdegspslist_oomulmonomsc (A->plink, B, BT, m, t, w, A, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspslist_oomulscadd_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_vardnsexpdegspsterm_t BT, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = bigintobj_vardnsexpdegspsterm_oomulscadd_cns (C, A, s, v, B, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = bigintobj_vardnsexpdegspsterm_oonegv_cns (C, B, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = bigintobj_vardnsexpdegspsterm_oomulsc_cns (C, A, s, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return bigintobj_vardnsexpdegspslist_oomulsc_cns (C, A, AT, s, v, args);
  if (B != BT)
    return bigintobj_vardnsexpdegspslist_oonegv_cns (C, B, BT, w, args);
  return C;
}

static void 
bigintobj_vardnsexpdegspslist_oomulscadd (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_vardnsexpdegspsterm_t BT, int w, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspslist_oomulscadd_cns (C, A, AT, s, v, B, BT, w, args), CT);
}

static void 
bigintobj_vardnsexpdegspslist_inmulscadd (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_vardnsexpdegspsterm_t BT, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = bigintobj_vardnsexpdegspsterm_inmulscadd (A, s, v, B, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  bigintobj_vardnsexpdegspsterm_oonegv (A->plink, B, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = bigintobj_vardnsexpdegspsterm_inmulsc (A, s, v, args);
	}
    }

  if (A != AT)
    bigintobj_vardnsexpdegspslist_inmulsc (A, AT, s, v, args);
  if (B != BT)
    bigintobj_vardnsexpdegspslist_oonegv (A->plink, B, BT, w, A, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspslist_oomulscaddmulsc_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_vardnsexpdegspsterm_t BT, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = bigintobj_vardnsexpdegspsterm_oomulscaddmulsc_cns (C, A, s, v, B, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = bigintobj_vardnsexpdegspsterm_oomulsc_cns (C, B, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = bigintobj_vardnsexpdegspsterm_oomulsc_cns (C, A, s, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return bigintobj_vardnsexpdegspslist_oomulsc_cns (C, A, AT, s, v, args);
  if (B != BT)
    return bigintobj_vardnsexpdegspslist_oomulsc_cns (C, B, BT, t, w, args);
  return C;
}

static void 
bigintobj_vardnsexpdegspslist_oomulscaddmulsc (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_vardnsexpdegspsterm_t BT, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspslist_oomulscaddmulsc_cns (C, A, AT, s, v, B, BT, t, w, args), CT);
}

static void 
bigintobj_vardnsexpdegspslist_inmulscaddmulsc (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_vardnsexpdegspsterm_t BT, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = bigintobj_vardnsexpdegspsterm_inmulscaddmulsc (A, s, v, B, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  bigintobj_vardnsexpdegspsterm_oomulsc (A->plink, B, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = bigintobj_vardnsexpdegspsterm_inmulsc (A, s, v, args);
	}
    }

  if (A != AT)
    bigintobj_vardnsexpdegspslist_inmulsc (A, AT, s, v, args);
  if (B != BT)
    bigintobj_vardnsexpdegspslist_oomulsc (A->plink, B, BT, t, w, A, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspslist_oomulscaddmulmonomsc_cns (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_vardnsexpdegspsterm_t BT, vardnsmonom_t m, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsexpdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  C = bigintobj_vardnsexpdegspsterm_oomulscaddmulmonomsc_cns (C, A, s, v, B, m, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = bigintobj_vardnsexpdegspsterm_oomulmonomsc_cns (C, B, m, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = bigintobj_vardnsexpdegspsterm_oomulsc_cns (C, A, s, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return bigintobj_vardnsexpdegspslist_oomulsc_cns (C, A, AT, s, v, args);
  if (B != BT)
    return bigintobj_vardnsexpdegspslist_oomulmonomsc_cns (C, B, BT, m, t, w, args);
  return C;
}

static void 
bigintobj_vardnsexpdegspslist_oomulscaddmulmonomsc (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_vardnsexpdegspsterm_t BT, vardnsmonom_t m, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspslist_oomulscaddmulmonomsc_cns (C, A, AT, s, v, B, BT, m, t, w, args), CT);
}

static void 
bigintobj_vardnsexpdegspslist_inmulscaddmulmonomsc (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsexpdegspsterm_t B, bigintobj_vardnsexpdegspsterm_t BT, vardnsmonom_t m, bigintobj_t t, int w, bigintobj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsexpdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  A = bigintobj_vardnsexpdegspsterm_inmulscaddmulmonomsc (A, s, v, B, m, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  bigintobj_vardnsexpdegspsterm_oomulmonomsc (A->plink, B, m, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = bigintobj_vardnsexpdegspsterm_inmulsc (A, s, v, args);
	}
    }

  if (A != AT)
    bigintobj_vardnsexpdegspslist_inmulsc (A, AT, s, v, args);
  if (B != BT)
    bigintobj_vardnsexpdegspslist_oomulmonomsc (A->plink, B, BT, m, t, w, A, args);
}

static BOOL 
bigintobj_vardnsexpdegspslist_oodivsc (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_t s, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  BOOL failed = NO;

  while (A != AT)
    {
      bigintobj_vardnsexpdegspsterm_t nextC = bigintobj_vardnsexpdegspsterm_oodivsc_cns (C, A, s, args);
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
  bigintobj_vardnsexpdegspsterm_glue (C, CT);
  return failed;
}

static void 
bigintobj_vardnsexpdegspslist_indivsc (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_t s, bigintobj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    A = bigintobj_vardnsexpdegspsterm_indivsc (A, s, args);
}

static BOOL 
bigintobj_vardnsexpdegspslist_oodivmonomsc (bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, vardnsmonom_t m, bigintobj_t s, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  BOOL failed = NO;

  while (A != AT)
    {
      bigintobj_vardnsexpdegspsterm_t nextC = bigintobj_vardnsexpdegspsterm_oodivmonomsc_cns (C, A, m, s, args);
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
  bigintobj_vardnsexpdegspsterm_glue (C, CT);
  return failed;
}

static void 
bigintobj_vardnsexpdegspslist_indivmonomsc (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, vardnsmonom_t m, bigintobj_t s, bigintobj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    A = bigintobj_vardnsexpdegspsterm_indivmonomsc (A, m, s, args);
}

static void 
bigintobj_vardnsexpdegspslist_fileOut (id aFiler, bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT, bigintobj_vardnsexpdegspsterm_args args)
{
  int n;
  n = bigintobj_vardnsexpdegspslist_count (A, AT);
  [aFiler fileOut:&n type:'i'];
  while (A != AT)
    A = bigintobj_vardnsexpdegspsterm_fileOut (aFiler, A, args);
}

static bigintobj_vardnsexpdegspsterm_t 
bigintobj_vardnsexpdegspslist_fileIn_cns (id aFiler, bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_args args)
{
  int n;
  [aFiler fileIn:&n type:'i'];
  while (n--)
    C = bigintobj_vardnsexpdegspsterm_fileIn_cns (aFiler, C, args);
  return C;
}

static void 
bigintobj_vardnsexpdegspslist_fileIn (id aFiler, bigintobj_vardnsexpdegspsterm_t C, bigintobj_vardnsexpdegspsterm_t CT, bigintobj_vardnsexpdegspsterm_args args)
{
  bigintobj_vardnsexpdegspsterm_glue (bigintobj_vardnsexpdegspslist_fileIn_cns (aFiler, C, args), CT);
}

static void 
bigintobj_vardnsexpdegspspol_ix_init (bigintobj_vardnsexpdegspspol_ixt ix, id self)
{
  bigintobj_vardnsexpdegspspol_t v = [self bigintobj_vardnsexpdegspspol_value];
  ix->head = v;
  ix->ix = v;
}

static void 
bigintobj_vardnsexpdegspspol_ix_clear (bigintobj_vardnsexpdegspspol_ixt ix)
{
  /* nothing to clear */
}

static int 
bigintobj_vardnsexpdegspspol_ix_count_aux_aux (bigintobj_vardnsexpdegspsterm_t A, bigintobj_vardnsexpdegspsterm_t AT)
{
  int c = 0;
  for (; A != AT; A = A->nlink)
    c++;
  return c;
}

static int 
bigintobj_vardnsexpdegspspol_ix_count_aux (bigintobj_vardnsexpdegspspol_t self)
{
  return bigintobj_vardnsexpdegspspol_ix_count_aux_aux (self->nlink, self);
}

static int 
bigintobj_vardnsexpdegspspol_ix_count (bigintobj_vardnsexpdegspspol_ixt ix)
{
  /* merde ! can't include entire bigintobj_vardnsexpdegspslist for bigintobj_vardnsexpdegspslist_count */
  return bigintobj_vardnsexpdegspspol_ix_count_aux (ix->head);
}

static int 
bigintobj_vardnsexpdegspspol_ix_isempty_aux (bigintobj_vardnsexpdegspspol_t self)
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
bigintobj_vardnsexpdegspspol_ix_isempty (bigintobj_vardnsexpdegspspol_ixt ix)
{
  /* can't include entire bigintobj_vardnsexpdegspspol for bigintobj_vardnsexpdegspspol_isempty */
  return bigintobj_vardnsexpdegspspol_ix_isempty_aux (ix->head);
}

static int 
bigintobj_vardnsexpdegspspol_ix_ismatch (bigintobj_vardnsexpdegspspol_ixt ix)
{
  return (ix->ix != NULL && ix->ix != ix->head);
}

static void 
bigintobj_vardnsexpdegspspol_ix_tofirst (bigintobj_vardnsexpdegspspol_ixt ix)
{
  ix->ix = ix->head;
}

static void 
bigintobj_vardnsexpdegspspol_ix_tolast (bigintobj_vardnsexpdegspspol_ixt ix)
{
  ix->ix = NULL;
}

static void 
bigintobj_vardnsexpdegspspol_ix_to (bigintobj_vardnsexpdegspspol_ixt ix, int i)
{
  fprintf (stderr, "at: notImplemented\n");
}

static void 
bigintobj_vardnsexpdegspspol_ix_next (bigintobj_vardnsexpdegspspol_ixt ix)
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
bigintobj_vardnsexpdegspspol_ix_prev (bigintobj_vardnsexpdegspspol_ixt ix)
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
bigintobj_vardnsexpdegspspol_check (bigintobj_vardnsexpdegspspol_t self, bigintobj_vardnsexpdegspspol_args args)
{
  assert (self->data == 0xcafebabe);
  return bigintobj_vardnsexpdegspslist_check (self->nlink, self, args);
}

static bigintobj_vardnsexpdegspspol_t 
bigintobj_vardnsexpdegspspol_id2t (id object)
{
  return [object bigintobj_vardnsexpdegspspol_value];
}

static bigintobj_vardnsexpdegspspol_c *
bigintobj_vardnsexpdegspspol_id2c (id object)
{
  return [object bigintobj_vardnsexpdegspspol_reference];
}

static id 
bigintobj_vardnsexpdegspspol_t2id (id proto, bigintobj_vardnsexpdegspspol_t f)
{
  return [proto bigintobj_vardnsexpdegspspol_value:f];
}

static id 
bigintobj_vardnsexpdegspspol_c2id (id proto, bigintobj_vardnsexpdegspspol_c * r)
{
  return [proto bigintobj_vardnsexpdegspspol_reference:r];
}

static int 
bigintobj_vardnsexpdegspspol_isempty (bigintobj_vardnsexpdegspspol_t self)
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
bigintobj_vardnsexpdegspspol_init (bigintobj_vardnsexpdegspspol_t self, bigintobj_vardnsexpdegspspol_args args)
{
  self->data = 0xcafebabe;
  self->nlink = self;
  self->plink = self;
  assert (bigintobj_vardnsexpdegspspol_check (self, args));
}

static void 
bigintobj_vardnsexpdegspspol_copy (bigintobj_vardnsexpdegspspol_t c, bigintobj_vardnsexpdegspspol_t a, bigintobj_vardnsexpdegspspol_args args)
{
  assert (bigintobj_vardnsexpdegspspol_check (a, args));
  bigintobj_vardnsexpdegspspol_init (c, args);
  bigintobj_vardnsexpdegspslist_copy (c, a->nlink, a, c, args);
}

static void 
bigintobj_vardnsexpdegspspol_deepcopy (bigintobj_vardnsexpdegspspol_t c, bigintobj_vardnsexpdegspspol_t a, bigintobj_vardnsexpdegspspol_args args)
{
  assert (bigintobj_vardnsexpdegspspol_check (a, args));
  bigintobj_vardnsexpdegspspol_init (c, args);
  bigintobj_vardnsexpdegspslist_deepcopy (c, a->nlink, a, c, args);
}

static void 
bigintobj_vardnsexpdegspspol_move (bigintobj_vardnsexpdegspspol_t c, bigintobj_vardnsexpdegspspol_t a, bigintobj_vardnsexpdegspspol_args args)
{
  if (bigintobj_vardnsexpdegspspol_isempty (a))
    {
      bigintobj_vardnsexpdegspspol_init (c, args);
    }
  else
    {
      bigintobj_vardnsexpdegspspol_init (c, args);
      bigintobj_vardnsexpdegspsterm_glue (c, a->nlink);
      bigintobj_vardnsexpdegspsterm_glue (a->plink, c);
    }

  a->data = 0;
  assert (bigintobj_vardnsexpdegspspol_check (c, args));
}

static void 
bigintobj_vardnsexpdegspspol_clear (bigintobj_vardnsexpdegspspol_t self, bigintobj_vardnsexpdegspspol_args args)
{
  bigintobj_vardnsexpdegspslist_clear (self->nlink, self, args);
  self->data = 0;
  bigintobj_vardnsexpdegspslist_free (self->nlink, self, args);
}

static int 
bigintobj_vardnsexpdegspspol_count (bigintobj_vardnsexpdegspspol_t self)
{
  return bigintobj_vardnsexpdegspslist_count (self->nlink, self);
}

static unsigned 
bigintobj_vardnsexpdegspspol_hash (bigintobj_vardnsexpdegspspol_t a, bigintobj_vardnsexpdegspspol_args args)
{
  return bigintobj_vardnsexpdegspslist_hash (a->nlink, a, args);
}

static int 
bigintobj_vardnsexpdegspspol_iseq (bigintobj_vardnsexpdegspspol_t a, bigintobj_vardnsexpdegspspol_t b, bigintobj_vardnsexpdegspspol_args args)
{
  return (a == b) ? YES : bigintobj_vardnsexpdegspslist_iseq (a->nlink, a, b->nlink, b, args);
}

static int 
bigintobj_vardnsexpdegspspol_isone (bigintobj_vardnsexpdegspspol_t a, bigintobj_vardnsexpdegspspol_args args)
{
  /* if the leading term is one, then it is one */
  return (bigintobj_vardnsexpdegspspol_isempty (a)) ? 0 : bigintobj_vardnsexpdegspsterm_isone (a->nlink, args);
}

static int 
bigintobj_vardnsexpdegspspol_isminusone (bigintobj_vardnsexpdegspspol_t a, bigintobj_vardnsexpdegspspol_args args)
{
  /* if the leading term is minus one, then it is minus one */
  return (bigintobj_vardnsexpdegspspol_isempty (a)) ? 0 : bigintobj_vardnsexpdegspsterm_isminusone (a->nlink, args);
}

static int 
bigintobj_vardnsexpdegspspol_deg (bigintobj_vardnsexpdegspspol_t self, bigintobj_vardnsexpdegspspol_args args)
{
  return bigintobj_vardnsexpdegspslist_deg (self->nlink, self, args);
}

static int 
bigintobj_vardnsexpdegspspol_ord (bigintobj_vardnsexpdegspspol_t self, bigintobj_vardnsexpdegspspol_args args)
{
  return bigintobj_vardnsexpdegspslist_ord (self->nlink, self, args);
}

static int 
bigintobj_vardnsexpdegspspol_maxdeg (bigintobj_vardnsexpdegspspol_t self, bigintobj_vardnsexpdegspspol_args args)
{
  return bigintobj_vardnsexpdegspslist_maxdeg (self->nlink, self, args);
}

static int 
bigintobj_vardnsexpdegspspol_mindeg (bigintobj_vardnsexpdegspspol_t self, bigintobj_vardnsexpdegspspol_args args)
{
  return bigintobj_vardnsexpdegspslist_mindeg (self->nlink, self, args);
}

static bigintobj_t 
bigintobj_vardnsexpdegspspol_scalat (bigintobj_vardnsexpdegspspol_t self, bigintobj_vardnsexpdegspspol_ixt ix, bigintobj_vardnsexpdegspspol_args args)
{
  assert (bigintobj_vardnsexpdegspspol_ix_ismatch (ix) && ix->head == self);
  return bigintobj_vardnsexpdegspsterm_scal (ix->ix, args);
}

static vardnsmonom_t 
bigintobj_vardnsexpdegspspol_monomat (bigintobj_vardnsexpdegspspol_t self, bigintobj_vardnsexpdegspspol_ixt ix, bigintobj_vardnsexpdegspspol_args args)
{
  assert (bigintobj_vardnsexpdegspspol_ix_ismatch (ix) && ix->head == self);
  return bigintobj_vardnsexpdegspsterm_monom (ix->ix);
}

static bigintobj_t 
bigintobj_vardnsexpdegspspol_scalfirst (bigintobj_vardnsexpdegspspol_t self, bigintobj_vardnsexpdegspspol_args args)
{
  assert (bigintobj_vardnsexpdegspspol_isempty (self) == NO);
  return bigintobj_vardnsexpdegspsterm_scal (self->nlink, args);
}

static vardnsmonom_t 
bigintobj_vardnsexpdegspspol_monomfirst (bigintobj_vardnsexpdegspspol_t self, bigintobj_vardnsexpdegspspol_args args)
{
  assert (bigintobj_vardnsexpdegspspol_isempty (self) == NO);
  return bigintobj_vardnsexpdegspsterm_monom (self->nlink);
}

static void 
bigintobj_vardnsexpdegspspol_remove (bigintobj_vardnsexpdegspspol_t self, bigintobj_vardnsexpdegspspol_args args)
{
  assert (bigintobj_vardnsexpdegspspol_check (self, args) && bigintobj_vardnsexpdegspspol_isempty (self) == NO);
  bigintobj_vardnsexpdegspsterm_delete (self->nlink, args);
  assert (bigintobj_vardnsexpdegspspol_check (self, args));
}

static void 
bigintobj_vardnsexpdegspspol_insert (bigintobj_vardnsexpdegspspol_t self, vardnsmonom_t m, bigintobj_t s, bigintobj_vardnsexpdegspspol_args args)
{
  assert (bigintobj_vardnsexpdegspspol_check (self, args));
  bigintobj_vardnsexpdegspslist_insert (self->nlink, self, m, s, args);
  assert (bigintobj_vardnsexpdegspspol_check (self, args));
}

static int 
bigintobj_vardnsexpdegspspol_iszero (bigintobj_vardnsexpdegspspol_t self, bigintobj_vardnsexpdegspspol_args args)
{
  return bigintobj_vardnsexpdegspspol_isempty (self);
}

static int 
bigintobj_vardnsexpdegspspol_isop (bigintobj_vardnsexpdegspspol_t a, bigintobj_vardnsexpdegspspol_t b, bigintobj_vardnsexpdegspspol_args args)
{
  assert (a != b);
  return bigintobj_vardnsexpdegspslist_isop (a->nlink, a, b->nlink, b, args);
}

static void 
bigintobj_vardnsexpdegspspol_ooneg (bigintobj_vardnsexpdegspspol_t c, bigintobj_vardnsexpdegspspol_t a, bigintobj_vardnsexpdegspspol_args args)
{
  bigintobj_vardnsexpdegspspol_init (c, args);
  bigintobj_vardnsexpdegspslist_ooneg (c, a->nlink, a, c, args);
  assert (bigintobj_vardnsexpdegspspol_check (c, args));
}

static void 
bigintobj_vardnsexpdegspspol_inneg (bigintobj_vardnsexpdegspspol_t a, bigintobj_vardnsexpdegspspol_args args)
{
  bigintobj_vardnsexpdegspslist_inneg (a->nlink, a, args);
  assert (bigintobj_vardnsexpdegspspol_check (a, args));
}

static void 
bigintobj_vardnsexpdegspspol_oodbl (bigintobj_vardnsexpdegspspol_t c, bigintobj_vardnsexpdegspspol_t a, int v, bigintobj_vardnsexpdegspspol_args args)
{
  bigintobj_vardnsexpdegspspol_init (c, args);
  bigintobj_vardnsexpdegspslist_oodbl (c, a->nlink, a, v, c, args);
  assert (bigintobj_vardnsexpdegspspol_check (c, args));
}

static void 
bigintobj_vardnsexpdegspspol_indbl (bigintobj_vardnsexpdegspspol_t a, int v, bigintobj_vardnsexpdegspspol_args args)
{
  bigintobj_vardnsexpdegspslist_indbl (a->nlink, a, v, args);
  assert (bigintobj_vardnsexpdegspspol_check (a, args));
}

static void 
bigintobj_vardnsexpdegspspol_ooadd (bigintobj_vardnsexpdegspspol_t c, bigintobj_vardnsexpdegspspol_t a, int v, bigintobj_vardnsexpdegspspol_t b, int w, bigintobj_vardnsexpdegspspol_args args)
{
  assert (a != b);
  bigintobj_vardnsexpdegspspol_init (c, args);
  bigintobj_vardnsexpdegspslist_ooadd (c, a->nlink, a, v, b->nlink, b, w, c, args);
  assert (bigintobj_vardnsexpdegspspol_check (c, args));
}

static void 
bigintobj_vardnsexpdegspspol_inadd (bigintobj_vardnsexpdegspspol_t a, int v, bigintobj_vardnsexpdegspspol_t b, int w, bigintobj_vardnsexpdegspspol_args args)
{
  assert (a != b);
  bigintobj_vardnsexpdegspslist_inadd (a->nlink, a, v, b->nlink, b, w, args);
  assert (bigintobj_vardnsexpdegspspol_check (a, args));
}

static void 
bigintobj_vardnsexpdegspspol_oomulsc (bigintobj_vardnsexpdegspspol_t c, bigintobj_vardnsexpdegspspol_t a, bigintobj_t s, bigintobj_vardnsexpdegspspol_args args)
{
  bigintobj_vardnsexpdegspspol_init (c, args);
  bigintobj_vardnsexpdegspslist_oomulsc (c, a->nlink, a, s, +1, c, args);
  assert (bigintobj_vardnsexpdegspspol_check (c, args));
}

static void 
bigintobj_vardnsexpdegspspol_inmulsc (bigintobj_vardnsexpdegspspol_t a, bigintobj_t s, bigintobj_vardnsexpdegspspol_args args)
{
  bigintobj_vardnsexpdegspslist_inmulsc (a->nlink, a, s, +1, args);
  assert (bigintobj_vardnsexpdegspspol_check (a, args));
}

static void 
bigintobj_vardnsexpdegspspol_ooaddmulsc (bigintobj_vardnsexpdegspspol_t c, bigintobj_vardnsexpdegspspol_t a, int v, bigintobj_vardnsexpdegspspol_t b, bigintobj_t t, int w, bigintobj_vardnsexpdegspspol_args args)
{
  bigintobj_vardnsexpdegspspol_init (c, args);
  bigintobj_vardnsexpdegspslist_ooaddmulsc (c, a->nlink, a, v, b->nlink, b, t, w, c, args);
  assert (bigintobj_vardnsexpdegspspol_check (c, args));
}

static void 
bigintobj_vardnsexpdegspspol_inaddmulsc (bigintobj_vardnsexpdegspspol_t a, int v, bigintobj_vardnsexpdegspspol_t b, bigintobj_t t, int w, bigintobj_vardnsexpdegspspol_args args)
{
  bigintobj_vardnsexpdegspslist_inaddmulsc (a->nlink, a, v, b->nlink, b, t, w, args);
  assert (bigintobj_vardnsexpdegspspol_check (a, args));
}

static void 
bigintobj_vardnsexpdegspspol_oomulscadd (bigintobj_vardnsexpdegspspol_t c, bigintobj_vardnsexpdegspspol_t a, bigintobj_t s, int v, bigintobj_vardnsexpdegspspol_t b, int w, bigintobj_vardnsexpdegspspol_args args)
{
  bigintobj_vardnsexpdegspspol_init (c, args);
  bigintobj_vardnsexpdegspslist_oomulscadd (c, a->nlink, a, s, v, b->nlink, b, w, c, args);
  assert (bigintobj_vardnsexpdegspspol_check (c, args));
}

static void 
bigintobj_vardnsexpdegspspol_inmulscadd (bigintobj_vardnsexpdegspspol_t a, bigintobj_t s, int v, bigintobj_vardnsexpdegspspol_t b, int w, bigintobj_vardnsexpdegspspol_args args)
{
  bigintobj_vardnsexpdegspslist_inmulscadd (a->nlink, a, s, v, b->nlink, b, w, args);
  assert (bigintobj_vardnsexpdegspspol_check (a, args));
}

static void 
bigintobj_vardnsexpdegspspol_oomulscaddmulsc (bigintobj_vardnsexpdegspspol_t c, bigintobj_vardnsexpdegspspol_t a, bigintobj_t s, int v, bigintobj_vardnsexpdegspspol_t b, bigintobj_t t, int w, bigintobj_vardnsexpdegspspol_args args)
{
  bigintobj_vardnsexpdegspspol_init (c, args);
  bigintobj_vardnsexpdegspslist_oomulscaddmulsc (c, a->nlink, a, s, v, b->nlink, b, t, w, c, args);
  assert (bigintobj_vardnsexpdegspspol_check (c, args));
}

static void 
bigintobj_vardnsexpdegspspol_inmulscaddmulsc (bigintobj_vardnsexpdegspspol_t a, bigintobj_t s, int v, bigintobj_vardnsexpdegspspol_t b, bigintobj_t t, int w, bigintobj_vardnsexpdegspspol_args args)
{
  bigintobj_vardnsexpdegspslist_inmulscaddmulsc (a->nlink, a, s, v, b->nlink, b, t, w, args);
  assert (bigintobj_vardnsexpdegspspol_check (a, args));
}

static BOOL 
bigintobj_vardnsexpdegspspol_oodivsc (bigintobj_vardnsexpdegspspol_t c, bigintobj_vardnsexpdegspspol_t a, bigintobj_t s, bigintobj_vardnsexpdegspspol_args args)
{
  BOOL failed;
  bigintobj_vardnsexpdegspspol_init (c, args);
  failed = bigintobj_vardnsexpdegspslist_oodivsc (c, a->nlink, a, s, c, args);
  assert (bigintobj_vardnsexpdegspspol_check (c, args));
  if (failed)
    bigintobj_vardnsexpdegspspol_clear (c, args);
  return failed;
}

static void 
bigintobj_vardnsexpdegspspol_indivsc (bigintobj_vardnsexpdegspspol_t a, bigintobj_t s, bigintobj_vardnsexpdegspspol_args args)
{
  bigintobj_vardnsexpdegspslist_indivsc (a->nlink, a, s, args);
  assert (bigintobj_vardnsexpdegspspol_check (a, args));
}

static void 
bigintobj_vardnsexpdegspspol_oomulmonomsc (bigintobj_vardnsexpdegspspol_t c, bigintobj_vardnsexpdegspspol_t b, vardnsmonom_t m, bigintobj_t t, int w, bigintobj_vardnsexpdegspspol_args args)
{
  bigintobj_vardnsexpdegspspol_init (c, args);
  bigintobj_vardnsexpdegspslist_oomulmonomsc (c, b->nlink, b, m, t, w, c, args);
  assert (bigintobj_vardnsexpdegspspol_check (c, args));
}

static void 
bigintobj_vardnsexpdegspspol_inmulmonomsc (bigintobj_vardnsexpdegspspol_t b, vardnsmonom_t m, bigintobj_t t, int w, bigintobj_vardnsexpdegspspol_args args)
{
  bigintobj_vardnsexpdegspslist_inmulmonomsc (b->nlink, b, m, t, w, args);
  assert (bigintobj_vardnsexpdegspspol_check (b, args));
}

static void 
bigintobj_vardnsexpdegspspol_ooaddmulmonomsc (bigintobj_vardnsexpdegspspol_t c, bigintobj_vardnsexpdegspspol_t a, int v, bigintobj_vardnsexpdegspspol_t b, vardnsmonom_t m, bigintobj_t t, int w, bigintobj_vardnsexpdegspspol_args args)
{
  bigintobj_vardnsexpdegspspol_init (c, args);
  bigintobj_vardnsexpdegspslist_ooaddmulmonomsc (c, a->nlink, a, v, b->nlink, b, m, t, w, c, args);
  assert (bigintobj_vardnsexpdegspspol_check (c, args));
}

static void 
bigintobj_vardnsexpdegspspol_inaddmulmonomsc (bigintobj_vardnsexpdegspspol_t a, int v, bigintobj_vardnsexpdegspspol_t b, vardnsmonom_t m, bigintobj_t t, int w, bigintobj_vardnsexpdegspspol_args args)
{
  bigintobj_vardnsexpdegspslist_inaddmulmonomsc (a->nlink, a, v, b->nlink, b, m, t, w, args);
  assert (bigintobj_vardnsexpdegspspol_check (a, args));
}

static void 
bigintobj_vardnsexpdegspspol_oomulscaddmulmonomsc (bigintobj_vardnsexpdegspspol_t c, bigintobj_vardnsexpdegspspol_t a, bigintobj_t s, int v, bigintobj_vardnsexpdegspspol_t b, vardnsmonom_t m, bigintobj_t t, int w, bigintobj_vardnsexpdegspspol_args args)
{
  bigintobj_vardnsexpdegspspol_init (c, args);
  bigintobj_vardnsexpdegspslist_oomulscaddmulmonomsc (c, a->nlink, a, s, v, b->nlink, b, m, t, w, c, args);
  assert (bigintobj_vardnsexpdegspspol_check (c, args));
}

static void 
bigintobj_vardnsexpdegspspol_inmulscaddmulmonomsc (bigintobj_vardnsexpdegspspol_t a, bigintobj_t s, int v, bigintobj_vardnsexpdegspspol_t b, vardnsmonom_t m, bigintobj_t t, int w, bigintobj_vardnsexpdegspspol_args args)
{
  bigintobj_vardnsexpdegspslist_inmulscaddmulmonomsc (a->nlink, a, s, v, b->nlink, b, m, t, w, args);
  assert (bigintobj_vardnsexpdegspspol_check (a, args));
}

static BOOL 
bigintobj_vardnsexpdegspspol_oodivmonomsc (bigintobj_vardnsexpdegspspol_t c, bigintobj_vardnsexpdegspspol_t b, vardnsmonom_t m, bigintobj_t t, bigintobj_vardnsexpdegspspol_args args)
{
  BOOL failed;
  bigintobj_vardnsexpdegspspol_init (c, args);
  failed = bigintobj_vardnsexpdegspslist_oodivmonomsc (c, b->nlink, b, m, t, c, args);
  assert (bigintobj_vardnsexpdegspspol_check (c, args));
  if (failed)
    bigintobj_vardnsexpdegspspol_clear (c, args);
  return failed;
}

static void 
bigintobj_vardnsexpdegspspol_indivmonomsc (bigintobj_vardnsexpdegspspol_t b, vardnsmonom_t m, bigintobj_t t, bigintobj_vardnsexpdegspspol_args args)
{
  bigintobj_vardnsexpdegspslist_indivmonomsc (b->nlink, b, m, t, args);
  assert (bigintobj_vardnsexpdegspspol_check (b, args));
}

static void 
bigintobj_vardnsexpdegspspol_args_fileOut (id aFiler, bigintobj_vardnsexpdegspspol_args * args)
{
  bigintobj_vardnsexpdegspsterm_args_fileOut (aFiler, args);
}
static void 
bigintobj_vardnsexpdegspspol_args_fileIn (id aFiler, bigintobj_vardnsexpdegspspol_args * args)
{
  bigintobj_vardnsexpdegspsterm_args_fileIn (aFiler, args);
}

static void 
bigintobj_vardnsexpdegspspol_fileOut (id aFiler, bigintobj_vardnsexpdegspspol_t self, bigintobj_vardnsexpdegspspol_args args)
{
  assert (bigintobj_vardnsexpdegspspol_check (self, args));
  bigintobj_vardnsexpdegspslist_fileOut (aFiler, self->nlink, self, args);
}

static void 
bigintobj_vardnsexpdegspspol_fileIn (id aFiler, bigintobj_vardnsexpdegspspol_t self, bigintobj_vardnsexpdegspspol_args args)
{
  bigintobj_vardnsexpdegspspol_init (self, args);
  bigintobj_vardnsexpdegspslist_fileIn (aFiler, self, self, args);
  assert (bigintobj_vardnsexpdegspspol_check (self, args));
}

static bigintobj_vardnsexpdegspspol_args 
bigintobj_vardnsexpdegspspol_getargs (id self)
{
  bigintobj_vardnsexpdegspspol_args res;
  id monomialZero = [self monomialZero];
  res.sargs = bigintobj_getargs ([monomialZero scalar]);
  res.margs = vardnsmonom_getargs ([monomialZero terms]);
  return res;
}
@implementation bigintobj_vardnsexpdegsps_polynomial : vardnsexpdegsps_polynomial

- (bigintobj_vardnsexpdegspspol_t)bigintobj_vardnsexpdegspspol_value
{
  return &value;
}

- dobigintobj_vardnsexpdegspspol_value:(bigintobj_vardnsexpdegspspol_t)aValue
{
  bigintobj_vardnsexpdegspspol_copy (&value, aValue, bigintobj_vardnsexpdegspspol_getargs (self));
  assert ([self check]);
  return self;
}

- bigintobj_vardnsexpdegspspol_value:(bigintobj_vardnsexpdegspspol_t)aValue
{
  return [[self clone] dobigintobj_vardnsexpdegspspol_value:aValue];
}

- (bigintobj_vardnsexpdegspspol_t)bigintobj_vardnsexpdegspspol_reference
{
  return &value;
}

- dobigintobj_vardnsexpdegspspol_reference:(bigintobj_vardnsexpdegspspol_c *)aReference
{
  bigintobj_vardnsexpdegspspol_move (&value, aReference, bigintobj_vardnsexpdegspspol_getargs (self));
  assert ([self check]);
  return self;
}

- bigintobj_vardnsexpdegspspol_reference:(bigintobj_vardnsexpdegspspol_c *)aReference
{
  return [[self clone] dobigintobj_vardnsexpdegspspol_reference:aReference];
}

- copy
{
  bigintobj_vardnsexpdegspspol_c c;
  assert ([self check]);
  bigintobj_vardnsexpdegspspol_copy (&c, &value, bigintobj_vardnsexpdegspspol_getargs (self));
  return bigintobj_vardnsexpdegspspol_c2id (self, &c);
}

- deepCopy
{
  bigintobj_vardnsexpdegspspol_c c;
  assert ([self check]);
  bigintobj_vardnsexpdegspspol_deepcopy (&c, &value, bigintobj_vardnsexpdegspspol_getargs (self));
  return bigintobj_vardnsexpdegspspol_c2id (self, &c);
}

- (BOOL) isEmpty
{
  return bigintobj_vardnsexpdegspspol_isempty (&value);
}

- (BOOL) isOne
{
  return bigintobj_vardnsexpdegspspol_isone (&value, bigintobj_vardnsexpdegspspol_getargs (self));
}

- (BOOL) isMinusOne
{
  return bigintobj_vardnsexpdegspspol_isminusone (&value, bigintobj_vardnsexpdegspspol_getargs (self));
}

- (unsigned) hash
{
  return bigintobj_vardnsexpdegspspol_hash (bigintobj_vardnsexpdegspspol_id2t (self), bigintobj_vardnsexpdegspspol_getargs (self));
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
      return bigintobj_vardnsexpdegspspol_iseq (bigintobj_vardnsexpdegspspol_id2t (self), bigintobj_vardnsexpdegspspol_id2t (b), bigintobj_vardnsexpdegspspol_getargs (self));
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
      return !bigintobj_vardnsexpdegspspol_iseq (bigintobj_vardnsexpdegspspol_id2t (self), bigintobj_vardnsexpdegspspol_id2t (b), bigintobj_vardnsexpdegspspol_getargs (self));
    }
}

- (BOOL) isZero
{
  assert ([self check]);
  return bigintobj_vardnsexpdegspspol_iszero (bigintobj_vardnsexpdegspspol_id2t (self), bigintobj_vardnsexpdegspspol_getargs (self));
}

- (BOOL) notZero
{
  assert ([self check]);
  return !bigintobj_vardnsexpdegspspol_iszero (bigintobj_vardnsexpdegspspol_id2t (self), bigintobj_vardnsexpdegspspol_getargs (self));
}

- (BOOL) isOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return bigintobj_vardnsexpdegspspol_isop (bigintobj_vardnsexpdegspspol_id2t (self), bigintobj_vardnsexpdegspspol_id2t (b), bigintobj_vardnsexpdegspspol_getargs (self));
}

- (BOOL) notOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return !bigintobj_vardnsexpdegspspol_isop (bigintobj_vardnsexpdegspspol_id2t (self), bigintobj_vardnsexpdegspspol_id2t (b), bigintobj_vardnsexpdegspspol_getargs (self));
}

- negate
{
  bigintobj_vardnsexpdegspspol_c c;
  assert ([self check]);
  bigintobj_vardnsexpdegspspol_ooneg (&c, bigintobj_vardnsexpdegspspol_id2t (self), bigintobj_vardnsexpdegspspol_getargs (self));
  return bigintobj_vardnsexpdegspspol_c2id (self, &c);
}

- _double:(int)v
{
  bigintobj_vardnsexpdegspspol_c c;
  assert ([self check]);
  bigintobj_vardnsexpdegspspol_oodbl (&c, bigintobj_vardnsexpdegspspol_id2t (self), v, bigintobj_vardnsexpdegspspol_getargs (self));
  return bigintobj_vardnsexpdegspspol_c2id (self, &c);
}

- double
{
  bigintobj_vardnsexpdegspspol_c c;
  assert ([self check]);
  bigintobj_vardnsexpdegspspol_oodbl (&c, bigintobj_vardnsexpdegspspol_id2t (self), +1, bigintobj_vardnsexpdegspspol_getargs (self));
  return bigintobj_vardnsexpdegspspol_c2id (self, &c);
}

- _add:(int)v:b:(int)w
{
  bigintobj_vardnsexpdegspspol_c c;
  assert ([self sameClass:b] && v * v == 1 && w * w == 1 && self != b);
  bigintobj_vardnsexpdegspspol_ooadd (&c, bigintobj_vardnsexpdegspspol_id2t (self), v, bigintobj_vardnsexpdegspspol_id2t (b), w, bigintobj_vardnsexpdegspspol_getargs (self));
  return bigintobj_vardnsexpdegspspol_c2id (self, &c);
}

- add:b
{
  bigintobj_vardnsexpdegspspol_c c;
  assert ([self checkSameClass:b] && self != b);
  bigintobj_vardnsexpdegspspol_ooadd (&c, bigintobj_vardnsexpdegspspol_id2t (self), +1, bigintobj_vardnsexpdegspspol_id2t (b), +1, bigintobj_vardnsexpdegspspol_getargs (self));
  return bigintobj_vardnsexpdegspspol_c2id (self, &c);
}

- subtract:b
{
  bigintobj_vardnsexpdegspspol_c c;
  assert ([self checkSameClass:b] && self != b);
  bigintobj_vardnsexpdegspspol_ooadd (&c, bigintobj_vardnsexpdegspspol_id2t (self), +1, bigintobj_vardnsexpdegspspol_id2t (b), -1, bigintobj_vardnsexpdegspspol_getargs (self));
  return bigintobj_vardnsexpdegspspol_c2id (self, &c);
}

- (int) leadingDegree
{
  return bigintobj_vardnsexpdegspspol_deg (&value, bigintobj_vardnsexpdegspspol_getargs (self));
}

- (int) lastDegree
{
  return bigintobj_vardnsexpdegspspol_ord (&value, bigintobj_vardnsexpdegspspol_getargs (self));
}

- (int) maxDegree
{
  return bigintobj_vardnsexpdegspspol_maxdeg (&value, bigintobj_vardnsexpdegspspol_getargs (self));
}

- (int) minDegree
{
  return bigintobj_vardnsexpdegspspol_mindeg (&value, bigintobj_vardnsexpdegspspol_getargs (self));
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

  bigintobj_vardnsexpdegspspol_check (&value, bigintobj_vardnsexpdegspspol_getargs (self));
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

  bigintobj_vardnsexpdegspspol_init (&value, bigintobj_vardnsexpdegspspol_getargs (self));
  assert ([self check]);
  return self;
}

+ scalarZero:aScalar symbols:aCltn
{
  return [[super new] _setUpScalarZero:aScalar symbols:aCltn];
}

- release
{
  bigintobj_vardnsexpdegspspol_clear (&value, bigintobj_vardnsexpdegspspol_getargs (self));
  return [super release];
}

- empty
{
  bigintobj_vardnsexpdegspspol_c c;
  assert ([self check]);
  bigintobj_vardnsexpdegspspol_init (&c, bigintobj_vardnsexpdegspspol_getargs (self));
  return bigintobj_vardnsexpdegspspol_c2id (self, &c);
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
  return bigintobj_vardnsexpdegspspol_count (&value);
}

- eachMonomial
{
  id aSequence = [bigintobj_vardnsexpdegspspol_sequence content:self];
  return [CASequence over:aSequence];
}

- elt_bigintobj_vardnsexpdegspspol_ix:(bigintobj_vardnsexpdegspspol_ixt)ix
{
  if (bigintobj_vardnsexpdegspspol_ix_ismatch (ix))
    {
      id s, m;
      bigintobj_t sc;
      vardnsmonom_t mc;
      sc = bigintobj_vardnsexpdegspspol_scalat (&value, ix, bigintobj_vardnsexpdegspspol_getargs (self));
      mc = bigintobj_vardnsexpdegspspol_monomat (&value, ix, bigintobj_vardnsexpdegspspol_getargs (self));
      s = bigintobj_t2id ([monomialZero scalar], sc);
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
      bigintobj_t sc;
      vardnsmonom_t mc;
      assert ([self check]);

      sc = bigintobj_vardnsexpdegspspol_scalfirst (&value, bigintobj_vardnsexpdegspspol_getargs (self));
      mc = bigintobj_vardnsexpdegspspol_monomfirst (&value, bigintobj_vardnsexpdegspspol_getargs (self));
      s = bigintobj_t2id ([monomialZero scalar], sc);
      m = vardnsmonom_t2id ([monomialZero terms], mc);
      lt = [monomialZero scalar:s terms:m];

      bigintobj_vardnsexpdegspspol_remove (&value, bigintobj_vardnsexpdegspspol_getargs (self));
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
      bigintobj_c c;
      bigintobj_t r;
      vardnsmonom_t m;
      assert ([aMonomial check]);
      assert ([self check]);
      r = bigintobj_id2ref ([aMonomial scalar], &c);
      m = vardnsmonom_id2t ([aMonomial terms]);
      bigintobj_vardnsexpdegspspol_insert (&value, m, r, bigintobj_vardnsexpdegspspol_getargs (self));
      assert ([aMonomial check]);
      [self invalidate];
      assert ([self check]);
      return self;
    }
}

- multiplyScalar:s
{
  bigintobj_vardnsexpdegspspol_c c;
  bigintobj_c sc;
  bigintobj_vardnsexpdegspspol_oomulsc (&c, bigintobj_vardnsexpdegspspol_id2t (self), bigintobj_id2ref (s, &sc), bigintobj_vardnsexpdegspspol_getargs (self));
  return bigintobj_vardnsexpdegspspol_c2id (self, &c);
}

- divideScalar:s
{
  bigintobj_vardnsexpdegspspol_c c;
  bigintobj_c sc;
  BOOL failed = bigintobj_vardnsexpdegspspol_oodivsc (&c, bigintobj_vardnsexpdegspspol_id2t (self), bigintobj_id2ref (s, &sc), bigintobj_vardnsexpdegspspol_getargs (self));
  return (failed) ? nil : bigintobj_vardnsexpdegspspol_c2id (self, &c);
}

- _add:(int)v:B multiplyScalar:b:(int)w
{
  bigintobj_vardnsexpdegspspol_c c;
  bigintobj_c bc;
  assert ([self sameClass:B] && [scalarZero sameClass:b] && v * v == 1 && w * w == 1);
  bigintobj_vardnsexpdegspspol_ooaddmulsc (&c, bigintobj_vardnsexpdegspspol_id2t (self), v, bigintobj_vardnsexpdegspspol_id2t (B), bigintobj_id2ref (b, &bc), w, bigintobj_vardnsexpdegspspol_getargs (self));
  return bigintobj_vardnsexpdegspspol_c2id (self, &c);
}

- _multiplyScalar:a:(int)v add:B:(int)w
{
  bigintobj_vardnsexpdegspspol_c c;
  bigintobj_c ac;
  assert ([scalarZero sameClass:a] && [self sameClass:B] && v * v == 1 && w * w == 1);
  bigintobj_vardnsexpdegspspol_oomulscadd (&c, bigintobj_vardnsexpdegspspol_id2t (self), bigintobj_id2ref (a, &ac), v, bigintobj_vardnsexpdegspspol_id2t (B), w, bigintobj_vardnsexpdegspspol_getargs (self));
  return bigintobj_vardnsexpdegspspol_c2id (self, &c);
}

- _multiplyScalar:a:(int)v add:B multiplyScalar:b:(int)w
{
  bigintobj_vardnsexpdegspspol_c c;
  bigintobj_c ac, bc;
  assert ([scalarZero sameClass:a] && [self sameClass:B] && [scalarZero sameClass:b] && v * v == 1 && w * w == 1);
  bigintobj_vardnsexpdegspspol_oomulscaddmulsc (&c, bigintobj_vardnsexpdegspspol_id2t (self), bigintobj_id2ref (a, &ac), v, bigintobj_vardnsexpdegspspol_id2t (B), bigintobj_id2ref (b, &bc), w, bigintobj_vardnsexpdegspspol_getargs (self));
  return bigintobj_vardnsexpdegspspol_c2id (self, &c);
}

- multiplyMonomial:aMonomial
{
  bigintobj_vardnsexpdegspspol_c c;
  bigintobj_t s;
  bigintobj_c sc;
  vardnsmonom_t m;

  m = vardnsmonom_id2t ([aMonomial terms]);
  s = bigintobj_id2ref ([aMonomial scalar], &sc);
  bigintobj_vardnsexpdegspspol_oomulmonomsc (&c, bigintobj_vardnsexpdegspspol_id2t (self), m, s, +1, bigintobj_vardnsexpdegspspol_getargs (self));
  return bigintobj_vardnsexpdegspspol_c2id (self, &c);
}

- _multiplyMonomial:aMonomial:(int)v
{
  bigintobj_vardnsexpdegspspol_c c;
  bigintobj_t s;
  bigintobj_c sc;
  vardnsmonom_t m;

  m = vardnsmonom_id2t ([aMonomial terms]);
  s = bigintobj_id2ref ([aMonomial scalar], &sc);
  bigintobj_vardnsexpdegspspol_oomulmonomsc (&c, bigintobj_vardnsexpdegspspol_id2t (self), m, s, v, bigintobj_vardnsexpdegspspol_getargs (self));
  return bigintobj_vardnsexpdegspspol_c2id (self, &c);
}

- divideMonomial:aMonomial
{
  BOOL failed;
  bigintobj_vardnsexpdegspspol_c c;
  bigintobj_t s;
  bigintobj_c sc;
  vardnsmonom_t m;

  m = vardnsmonom_id2t ([aMonomial terms]);
  s = bigintobj_id2ref ([aMonomial scalar], &sc);
  failed = bigintobj_vardnsexpdegspspol_oodivmonomsc (&c, bigintobj_vardnsexpdegspspol_id2t (self), m, s, bigintobj_vardnsexpdegspspol_getargs (self));
  return (failed) ? nil : bigintobj_vardnsexpdegspspol_c2id (self, &c);
}

- _add:(int)v:B multiplyMonomial:b:(int)w
{
  bigintobj_vardnsexpdegspspol_c c;
  bigintobj_c bc;
  bigintobj_t bs;
  vardnsmonom_t bm;

  bm = vardnsmonom_id2t ([b terms]);
  bs = bigintobj_id2ref ([b scalar], &bc);
  bigintobj_vardnsexpdegspspol_ooaddmulmonomsc (&c, bigintobj_vardnsexpdegspspol_id2c (self), v, bigintobj_vardnsexpdegspspol_id2t (B), bm, bs, w, bigintobj_vardnsexpdegspspol_getargs (self));
  return bigintobj_vardnsexpdegspspol_c2id (self, &c);
}

- _multiplyScalar:a:(int)v add:B multiplyMonomial:b:(int)w
{
  bigintobj_vardnsexpdegspspol_c c;
  bigintobj_c ac, bc;
  bigintobj_t as, bs;
  vardnsmonom_t bm;

  as = bigintobj_id2ref (a, &ac);
  bm = vardnsmonom_id2t ([b terms]);
  bs = bigintobj_id2ref ([b scalar], &bc);
  bigintobj_vardnsexpdegspspol_oomulscaddmulmonomsc (&c, bigintobj_vardnsexpdegspspol_id2c (self), as, v, bigintobj_vardnsexpdegspspol_id2t (B), bm, bs, w, bigintobj_vardnsexpdegspspol_getargs (self));
  return bigintobj_vardnsexpdegspspol_c2id (self, &c);
}


- fileOutOn:aFiler
{
  bigintobj_vardnsexpdegspspol_args args;
  assert ([self check]);
  [super fileOutOn:aFiler];
  args = bigintobj_vardnsexpdegspspol_getargs (self);
  bigintobj_vardnsexpdegspspol_args_fileOut (aFiler, &args);
  bigintobj_vardnsexpdegspspol_fileOut (aFiler, &value, args);
  return self;
}

- fileInFrom:aFiler
{
  bigintobj_vardnsexpdegspspol_args args;
  [super fileInFrom:aFiler];
  bigintobj_vardnsexpdegspspol_args_fileIn (aFiler, &args);
  bigintobj_vardnsexpdegspspol_fileIn (aFiler, &value, args);
  return self;
}

@end
 
