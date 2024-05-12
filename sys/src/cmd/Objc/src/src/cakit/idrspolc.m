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
 * $Id: idrspolc.m,v 1.6 2000/10/12 14:40:25 stes Exp $
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
bigintobj_vardnsrecdegspsterm_monom_cval (bigintobj_vardnsrecdegspsterm_t self)
{
  return &self->data;
}

static unimonom_t 
bigintobj_vardnsrecdegspsterm_monom (bigintobj_vardnsrecdegspsterm_t self)
{
#if unimonom_pervalue
  return self->data;
#else
  return bigintobj_vardnsrecdegspsterm_monom_cval (self);
#endif
}

/* stes - mar31,1997
 * change for DEC alpha to exclude varsized scalars
 */

static bigintobj_c *
bigintobj_vardnsrecdegspsterm_scal_cval (bigintobj_vardnsrecdegspsterm_t self, bigintobj_vardnsrecdegspsterm_args args)
{
  return &self->scal;
}

static bigintobj_t 
bigintobj_vardnsrecdegspsterm_scal (bigintobj_vardnsrecdegspsterm_t self, bigintobj_vardnsrecdegspsterm_args args)
{
#if bigintobj_pervalue
  return self->scal;
#else
  return bigintobj_vardnsrecdegspsterm_scal_cval (self, args);
#endif
}

static int 
bigintobj_vardnsrecdegspsterm_check (bigintobj_vardnsrecdegspsterm_t self, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (bigintobj_check (bigintobj_vardnsrecdegspsterm_scal (self, args), args.sargs));
  assert (!bigintobj_iszero (bigintobj_vardnsrecdegspsterm_scal (self, args), args.sargs));
  assert (unimonom_check (bigintobj_vardnsrecdegspsterm_monom (self), args.margs));
  return 1;
}

static int 
bigintobj_vardnsrecdegspsterm_bsize (bigintobj_vardnsrecdegspsterm_args args)
{
  /* this is sizeof(unimonom_c) too much but why bother ? */
  return sizeof (struct bigintobj_vardnsrecdegspsterm) + unimonom_bsize (args.margs);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_alloc (bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_t p;
  int n = bigintobj_vardnsrecdegspsterm_bsize (args);
  p = (bigintobj_vardnsrecdegspsterm_t) OC_Malloc (n);
#if OBJC_REFCNT
  memset (p, 0, n);
#endif
  return p;
}

static void 
bigintobj_vardnsrecdegspsterm_clear (bigintobj_vardnsrecdegspsterm_t self, bigintobj_vardnsrecdegspsterm_args args)
{
  unimonom_clear (bigintobj_vardnsrecdegspsterm_monom_cval (self), args.margs);
  bigintobj_clear (bigintobj_vardnsrecdegspsterm_scal_cval (self, args), args.sargs);
}

static void 
bigintobj_vardnsrecdegspsterm_free (bigintobj_vardnsrecdegspsterm_t self, bigintobj_vardnsrecdegspsterm_args args)
{
  /* invalidating links not always helps : buggy code might work because
   * links were cleared...        self->nlink = NULL;self->plink = NULL;
   */
  OC_Free (self);
}

static int 
bigintobj_vardnsrecdegspsterm_cmp (bigintobj_vardnsrecdegspsterm_t a, bigintobj_vardnsrecdegspsterm_t b, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (bigintobj_vardnsrecdegspsterm_check (a, args) && bigintobj_vardnsrecdegspsterm_check (b, args));
  return unimonom_cmp (bigintobj_vardnsrecdegspsterm_monom (a), bigintobj_vardnsrecdegspsterm_monom (b), args.margs);
}

static int 
bigintobj_vardnsrecdegspsterm_cmpmonom (bigintobj_vardnsrecdegspsterm_t a, unimonom_t b, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (bigintobj_vardnsrecdegspsterm_check (a, args) && unimonom_check (b, args.margs));
  return unimonom_cmp (bigintobj_vardnsrecdegspsterm_monom (a), b, args.margs);
}

static int 
bigintobj_vardnsrecdegspsterm_cmpmul (bigintobj_vardnsrecdegspsterm_t a, bigintobj_vardnsrecdegspsterm_t b, unimonom_t m, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (bigintobj_vardnsrecdegspsterm_check (a, args) && bigintobj_vardnsrecdegspsterm_check (b, args));
  assert (unimonom_check (m, args.margs));
  return unimonom_cmpmul (bigintobj_vardnsrecdegspsterm_monom (a), bigintobj_vardnsrecdegspsterm_monom (b), m, args.margs);
}

static int 
bigintobj_vardnsrecdegspsterm_deg (bigintobj_vardnsrecdegspsterm_t a, bigintobj_vardnsrecdegspsterm_args args)
{
  return unimonom_deg (bigintobj_vardnsrecdegspsterm_monom (a), args.margs);
}

static int 
bigintobj_vardnsrecdegspsterm_iszero (bigintobj_vardnsrecdegspsterm_t self, bigintobj_vardnsrecdegspsterm_args args)
{
  return bigintobj_iszero (bigintobj_vardnsrecdegspsterm_scal (self, args), args.sargs);
}

static int 
bigintobj_vardnsrecdegspsterm_isone (bigintobj_vardnsrecdegspsterm_t self, bigintobj_vardnsrecdegspsterm_args args)
{
  return bigintobj_isone (bigintobj_vardnsrecdegspsterm_scal (self, args), args.sargs) && unimonom_isone (bigintobj_vardnsrecdegspsterm_monom (self), args.margs);
}

static int 
bigintobj_vardnsrecdegspsterm_isminusone (bigintobj_vardnsrecdegspsterm_t self, bigintobj_vardnsrecdegspsterm_args args)
{
  return bigintobj_isminusone (bigintobj_vardnsrecdegspsterm_scal (self, args), args.sargs) && unimonom_isone (bigintobj_vardnsrecdegspsterm_monom (self), args.margs);
}

static int 
bigintobj_vardnsrecdegspsterm_iseq (bigintobj_vardnsrecdegspsterm_t a, bigintobj_vardnsrecdegspsterm_t b, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (bigintobj_vardnsrecdegspsterm_check (a, args) && bigintobj_vardnsrecdegspsterm_check (b, args));
  return unimonom_iseq (bigintobj_vardnsrecdegspsterm_monom (a), bigintobj_vardnsrecdegspsterm_monom (b), args.margs) && bigintobj_iseq (bigintobj_vardnsrecdegspsterm_scal (a, args), bigintobj_vardnsrecdegspsterm_scal (b, args), args.sargs);
}

static int 
bigintobj_vardnsrecdegspsterm_isop (bigintobj_vardnsrecdegspsterm_t a, bigintobj_vardnsrecdegspsterm_t b, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (bigintobj_vardnsrecdegspsterm_check (a, args) && bigintobj_vardnsrecdegspsterm_check (b, args));
  return unimonom_iseq (bigintobj_vardnsrecdegspsterm_monom (a), bigintobj_vardnsrecdegspsterm_monom (b), args.margs) && bigintobj_isop (bigintobj_vardnsrecdegspsterm_scal (a, args), bigintobj_vardnsrecdegspsterm_scal (b, args), args.sargs);
}

static void 
bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A)
{
  C->nlink = A;
  A->plink = C;
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A)
{
  bigintobj_vardnsrecdegspsterm_glue (C, A);
  return A;
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_delete (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_t C = A->nlink;
  bigintobj_vardnsrecdegspsterm_glue (A->plink, C);
  bigintobj_vardnsrecdegspsterm_clear (A, args);
  bigintobj_vardnsrecdegspsterm_free (A, args);
  return C;
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_condcns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t new, bigintobj_vardnsrecdegspsterm_args args)
{
  if (bigintobj_vardnsrecdegspsterm_iszero (new, args))
    {
      bigintobj_vardnsrecdegspsterm_clear (new, args);
      bigintobj_vardnsrecdegspsterm_free (new, args);
      return C;
    }
  else
    {
      assert (bigintobj_vardnsrecdegspsterm_check (new, args));
      return bigintobj_vardnsrecdegspsterm_cns (C, new);
    }
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_conddelete (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_args args)
{
  if (bigintobj_vardnsrecdegspsterm_iszero (A, args))
    {
      return bigintobj_vardnsrecdegspsterm_delete (A, args);
    }
  else
    {
      return A->nlink;
    }
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_copymonomsc_cns (bigintobj_vardnsrecdegspsterm_t C, unimonom_t m, bigintobj_t s, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_t new = bigintobj_vardnsrecdegspsterm_alloc (args);

  bigintobj_copy (bigintobj_vardnsrecdegspsterm_scal_cval (new, args), s, args.sargs);
  unimonom_copy (bigintobj_vardnsrecdegspsterm_monom_cval (new), m, args.margs);

  assert (bigintobj_vardnsrecdegspsterm_check (new, args));
  return bigintobj_vardnsrecdegspsterm_cns (C, new);
}

static void 
bigintobj_vardnsrecdegspsterm_copymonomsc (bigintobj_vardnsrecdegspsterm_t C, unimonom_t m, bigintobj_t s, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspsterm_copymonomsc_cns (C, m, s, args), CT);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_deepcopymonomsc_cns (bigintobj_vardnsrecdegspsterm_t C, unimonom_t m, bigintobj_t s, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_t new = bigintobj_vardnsrecdegspsterm_alloc (args);

  bigintobj_deepcopy (bigintobj_vardnsrecdegspsterm_scal_cval (new, args), s, args.sargs);
  unimonom_copy (bigintobj_vardnsrecdegspsterm_monom_cval (new), m, args.margs);

  assert (bigintobj_vardnsrecdegspsterm_check (new, args));
  return bigintobj_vardnsrecdegspsterm_cns (C, new);
}

static void 
bigintobj_vardnsrecdegspsterm_deepcopymonomsc (bigintobj_vardnsrecdegspsterm_t C, unimonom_t m, bigintobj_t s, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspsterm_deepcopymonomsc_cns (C, m, s, args), CT);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_copy_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_args args)
{
  return bigintobj_vardnsrecdegspsterm_copymonomsc_cns (C, bigintobj_vardnsrecdegspsterm_monom (A), bigintobj_vardnsrecdegspsterm_scal (A, args), args);
}

static void 
bigintobj_vardnsrecdegspsterm_copy (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspsterm_copy_cns (C, A, args), CT);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_deepcopy_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_args args)
{
  return bigintobj_vardnsrecdegspsterm_deepcopymonomsc_cns (C, bigintobj_vardnsrecdegspsterm_monom (A), bigintobj_vardnsrecdegspsterm_scal (A, args), args);
}

static void 
bigintobj_vardnsrecdegspsterm_deepcopy (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspsterm_deepcopy_cns (C, A, args), CT);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_ooneg_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_t new = bigintobj_vardnsrecdegspsterm_alloc (args);
  assert (bigintobj_vardnsrecdegspsterm_iszero (A, args) == NO);

  bigintobj_ooneg (bigintobj_vardnsrecdegspsterm_scal_cval (new, args), bigintobj_vardnsrecdegspsterm_scal (A, args), args.sargs);
  unimonom_copy (bigintobj_vardnsrecdegspsterm_monom_cval (new), bigintobj_vardnsrecdegspsterm_monom (A), args.margs);

  return bigintobj_vardnsrecdegspsterm_cns (C, new);
}

static void 
bigintobj_vardnsrecdegspsterm_ooneg (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspsterm_ooneg_cns (C, A, args), CT);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_inneg (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (bigintobj_vardnsrecdegspsterm_iszero (A, args) == NO);
  bigintobj_inneg (bigintobj_vardnsrecdegspsterm_scal_cval (A, args), args.sargs);
  assert (bigintobj_vardnsrecdegspsterm_iszero (A, args) == NO);
  return A->nlink;
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_oonegv_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, int v, bigintobj_vardnsrecdegspsterm_args args)
{
  return (v == -1) ? bigintobj_vardnsrecdegspsterm_ooneg_cns (C, A, args) : bigintobj_vardnsrecdegspsterm_copy_cns (C, A, args);
}

static void 
bigintobj_vardnsrecdegspsterm_oonegv (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, int v, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspsterm_oonegv_cns (C, A, v, args), CT);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_innegv (bigintobj_vardnsrecdegspsterm_t A, int v, bigintobj_vardnsrecdegspsterm_args args)
{
  return (v == -1) ? bigintobj_vardnsrecdegspsterm_inneg (A, args) : A->nlink;
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_oodbl_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, int v, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_t new = bigintobj_vardnsrecdegspsterm_alloc (args);
  assert (bigintobj_vardnsrecdegspsterm_iszero (A, args) == NO);

  bigintobj_oodbl (bigintobj_vardnsrecdegspsterm_scal_cval (new, args), bigintobj_vardnsrecdegspsterm_scal (A, args), v, args.sargs);
  unimonom_copy (bigintobj_vardnsrecdegspsterm_monom_cval (new), bigintobj_vardnsrecdegspsterm_monom (A), args.margs);

  return bigintobj_vardnsrecdegspsterm_condcns (C, new, args);
}

static void 
bigintobj_vardnsrecdegspsterm_oodbl (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, int v, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspsterm_oodbl_cns (C, A, v, args), CT);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_indbl (bigintobj_vardnsrecdegspsterm_t A, int v, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (bigintobj_vardnsrecdegspsterm_iszero (A, args) == NO);
  bigintobj_indbl (bigintobj_vardnsrecdegspsterm_scal_cval (A, args), v, args.sargs);
  return bigintobj_vardnsrecdegspsterm_conddelete (A, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_ooaddsc_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, int v, bigintobj_t B, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_t new = bigintobj_vardnsrecdegspsterm_alloc (args);
  bigintobj_ooadd (bigintobj_vardnsrecdegspsterm_scal_cval (new, args), bigintobj_vardnsrecdegspsterm_scal (A, args), v, B, w, args.sargs);
  unimonom_copy (bigintobj_vardnsrecdegspsterm_monom_cval (new), bigintobj_vardnsrecdegspsterm_monom (A), args.margs);
  return bigintobj_vardnsrecdegspsterm_condcns (C, new, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_inaddsc (bigintobj_vardnsrecdegspsterm_t A, int v, bigintobj_t B, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_inadd (bigintobj_vardnsrecdegspsterm_scal_cval (A, args), v, B, w, args.sargs);
  return bigintobj_vardnsrecdegspsterm_conddelete (A, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_ooadd_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, int v, bigintobj_vardnsrecdegspsterm_t B, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (0 == bigintobj_vardnsrecdegspsterm_cmp (A, B, args));
  assert (bigintobj_vardnsrecdegspsterm_iszero (A, args) == NO && bigintobj_vardnsrecdegspsterm_iszero (B, args) == NO);
  return bigintobj_vardnsrecdegspsterm_ooaddsc_cns (C, A, v, bigintobj_vardnsrecdegspsterm_scal (B, args), w, args);
}

static void 
bigintobj_vardnsrecdegspsterm_ooadd (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, int v, bigintobj_vardnsrecdegspsterm_t B, int w, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspsterm_ooadd_cns (C, A, v, B, w, args), CT);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_inadd (bigintobj_vardnsrecdegspsterm_t A, int v, bigintobj_vardnsrecdegspsterm_t B, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (0 == bigintobj_vardnsrecdegspsterm_cmp (A, B, args));
  assert (bigintobj_vardnsrecdegspsterm_iszero (A, args) == NO && bigintobj_vardnsrecdegspsterm_iszero (B, args) == NO);
  return bigintobj_vardnsrecdegspsterm_inaddsc (A, v, bigintobj_vardnsrecdegspsterm_scal (B, args), w, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_oomulsc_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_t new = bigintobj_vardnsrecdegspsterm_alloc (args);

  bigintobj_oomulv (bigintobj_vardnsrecdegspsterm_scal_cval (new, args), bigintobj_vardnsrecdegspsterm_scal (A, args), s, v, args.sargs);
  unimonom_copy (bigintobj_vardnsrecdegspsterm_monom_cval (new), bigintobj_vardnsrecdegspsterm_monom (A), args.margs);

  return bigintobj_vardnsrecdegspsterm_condcns (C, new, args);
}

static void 
bigintobj_vardnsrecdegspsterm_oomulsc (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspsterm_oomulsc_cns (C, A, s, v, args), CT);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_inmulsc (bigintobj_vardnsrecdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_inmulv (bigintobj_vardnsrecdegspsterm_scal_cval (A, args), s, v, args.sargs);
  return bigintobj_vardnsrecdegspsterm_conddelete (A, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_oomulmonomsc_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, unimonom_t m, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_t new = bigintobj_vardnsrecdegspsterm_alloc (args);

  bigintobj_oomulv (bigintobj_vardnsrecdegspsterm_scal_cval (new, args), bigintobj_vardnsrecdegspsterm_scal (A, args), s, v, args.sargs);
  unimonom_oomul (bigintobj_vardnsrecdegspsterm_monom_cval (new), bigintobj_vardnsrecdegspsterm_monom (A), m, args.margs);

  return bigintobj_vardnsrecdegspsterm_condcns (C, new, args);
}

static void 
bigintobj_vardnsrecdegspsterm_oomulmonomsc (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, unimonom_t m, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspsterm_oomulmonomsc_cns (C, A, m, s, v, args), CT);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_inmulmonomsc (bigintobj_vardnsrecdegspsterm_t A, unimonom_t m, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_inmulv (bigintobj_vardnsrecdegspsterm_scal_cval (A, args), s, v, args.sargs);
  unimonom_inmul (bigintobj_vardnsrecdegspsterm_monom_cval (A), m, args.margs);

  return bigintobj_vardnsrecdegspsterm_conddelete (A, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_ooaddscmulsc_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, int v, bigintobj_t B, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_t new = bigintobj_vardnsrecdegspsterm_alloc (args);

  bigintobj_ooaddmul (bigintobj_vardnsrecdegspsterm_scal_cval (new, args), bigintobj_vardnsrecdegspsterm_scal (A, args), v, B, t, w, args.sargs);
  unimonom_copy (bigintobj_vardnsrecdegspsterm_monom_cval (new), bigintobj_vardnsrecdegspsterm_monom (A), args.margs);

  return bigintobj_vardnsrecdegspsterm_condcns (C, new, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_inaddscmulsc (bigintobj_vardnsrecdegspsterm_t A, int v, bigintobj_t B, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_inaddmul (bigintobj_vardnsrecdegspsterm_scal_cval (A, args), v, B, t, w, args.sargs);
  return bigintobj_vardnsrecdegspsterm_conddelete (A, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_ooaddmulsc_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (0 == (bigintobj_vardnsrecdegspsterm_cmp (A, B, args)));
  return bigintobj_vardnsrecdegspsterm_ooaddscmulsc_cns (C, A, v, bigintobj_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_ooaddmulmonomsc_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, int v, bigintobj_vardnsrecdegspsterm_t B, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (0 == (bigintobj_vardnsrecdegspsterm_cmpmul (A, B, m, args)));
  return bigintobj_vardnsrecdegspsterm_ooaddscmulsc_cns (C, A, v, bigintobj_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static void 
bigintobj_vardnsrecdegspsterm_ooaddmulsc (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspsterm_ooaddmulsc_cns (C, A, v, B, t, w, args), CT);
}

static void 
bigintobj_vardnsrecdegspsterm_ooaddmulmonomsc (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, int v, bigintobj_vardnsrecdegspsterm_t B, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspsterm_ooaddmulmonomsc_cns (C, A, v, B, m, t, w, args), CT);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_inaddmulsc (bigintobj_vardnsrecdegspsterm_t A, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (0 == (bigintobj_vardnsrecdegspsterm_cmp (A, B, args)));
  return bigintobj_vardnsrecdegspsterm_inaddscmulsc (A, v, bigintobj_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_inaddmulmonomsc (bigintobj_vardnsrecdegspsterm_t A, int v, bigintobj_vardnsrecdegspsterm_t B, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (0 == (bigintobj_vardnsrecdegspsterm_cmpmul (A, B, m, args)));
  return bigintobj_vardnsrecdegspsterm_inaddscmulsc (A, v, bigintobj_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_oomulscaddsc_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_t s, int v, bigintobj_t B, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_t new = bigintobj_vardnsrecdegspsterm_alloc (args);

  bigintobj_oomuladd (bigintobj_vardnsrecdegspsterm_scal_cval (new, args), bigintobj_vardnsrecdegspsterm_scal (A, args), s, v, B, w, args.sargs);
  unimonom_copy (bigintobj_vardnsrecdegspsterm_monom_cval (new), bigintobj_vardnsrecdegspsterm_monom (A), args.margs);

  return bigintobj_vardnsrecdegspsterm_condcns (C, new, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_inmulscaddsc (bigintobj_vardnsrecdegspsterm_t A, bigintobj_t s, int v, bigintobj_t B, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_inmuladd (bigintobj_vardnsrecdegspsterm_scal_cval (A, args), s, v, B, w, args.sargs);
  return bigintobj_vardnsrecdegspsterm_conddelete (A, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_oomulscadd_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_t B, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (0 == (bigintobj_vardnsrecdegspsterm_cmp (A, B, args)));
  return bigintobj_vardnsrecdegspsterm_oomulscaddsc_cns (C, A, s, v, bigintobj_vardnsrecdegspsterm_scal (B, args), w, args);
}

static void 
bigintobj_vardnsrecdegspsterm_oomulscadd (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_t B, int w, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspsterm_oomulscadd_cns (C, A, s, v, B, w, args), CT);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_inmulscadd (bigintobj_vardnsrecdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_t B, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (0 == (bigintobj_vardnsrecdegspsterm_cmp (A, B, args)));
  return bigintobj_vardnsrecdegspsterm_inmulscaddsc (A, s, v, bigintobj_vardnsrecdegspsterm_scal (B, args), w, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_oomulscaddscmulsc_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_t s, int v, bigintobj_t B, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_t new = bigintobj_vardnsrecdegspsterm_alloc (args);
  bigintobj_oomuladdmul (bigintobj_vardnsrecdegspsterm_scal_cval (new, args), bigintobj_vardnsrecdegspsterm_scal (A, args), s, v, B, t, w, args.sargs);
  unimonom_copy (bigintobj_vardnsrecdegspsterm_monom_cval (new), bigintobj_vardnsrecdegspsterm_monom (A), args.margs);

  return bigintobj_vardnsrecdegspsterm_condcns (C, new, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_inmulscaddscmulsc (bigintobj_vardnsrecdegspsterm_t A, bigintobj_t s, int v, bigintobj_t B, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_inmuladdmul (bigintobj_vardnsrecdegspsterm_scal_cval (A, args), s, v, B, t, w, args.sargs);
  return bigintobj_vardnsrecdegspsterm_conddelete (A, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_oomulscaddmulsc_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (0 == (bigintobj_vardnsrecdegspsterm_cmp (A, B, args)));
  return bigintobj_vardnsrecdegspsterm_oomulscaddscmulsc_cns (C, A, s, v, bigintobj_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_oomulscaddmulmonomsc_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_t B, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (0 == (bigintobj_vardnsrecdegspsterm_cmpmul (A, B, m, args)));
  return bigintobj_vardnsrecdegspsterm_oomulscaddscmulsc_cns (C, A, s, v, bigintobj_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static void 
bigintobj_vardnsrecdegspsterm_oomulscaddmulsc (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspsterm_oomulscaddmulsc_cns (C, A, s, v, B, t, w, args), CT);
}

static void 
bigintobj_vardnsrecdegspsterm_oomulscaddmulmonomsc (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_t B, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspsterm_oomulscaddmulmonomsc_cns (C, A, s, v, B, m, t, w, args), CT);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_inmulscaddmulsc (bigintobj_vardnsrecdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (0 == (bigintobj_vardnsrecdegspsterm_cmp (A, B, args)));
  return bigintobj_vardnsrecdegspsterm_inmulscaddscmulsc (A, s, v, bigintobj_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_inmulscaddmulmonomsc (bigintobj_vardnsrecdegspsterm_t A, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_t B, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (0 == (bigintobj_vardnsrecdegspsterm_cmpmul (A, B, m, args)));
  return bigintobj_vardnsrecdegspsterm_inmulscaddscmulsc (A, s, v, bigintobj_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_oodivsc_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_t s, bigintobj_vardnsrecdegspsterm_args args)
{
  BOOL failed;
  bigintobj_vardnsrecdegspsterm_t new = bigintobj_vardnsrecdegspsterm_alloc (args);

  failed = bigintobj_oodiv (bigintobj_vardnsrecdegspsterm_scal_cval (new, args), bigintobj_vardnsrecdegspsterm_scal (A, args), s, args.sargs);
  if (failed)
    {
      bigintobj_vardnsrecdegspsterm_free (new, args);
      return NULL;
    }

  unimonom_copy (bigintobj_vardnsrecdegspsterm_monom_cval (new), bigintobj_vardnsrecdegspsterm_monom (A), args.margs);

  return bigintobj_vardnsrecdegspsterm_condcns (C, new, args);
}

#if 0				/* unused ! why did I write this ? */
static BOOL 
bigintobj_vardnsrecdegspsterm_oodivsc (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_t s, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  if ((C = bigintobj_vardnsrecdegspsterm_oodivsc_cns (C, A, s, args)))
    {
      bigintobj_vardnsrecdegspsterm_glue (C, CT);
      return SUCCESS;
    }
  else
    {
      return FAILURE;
    }
}
#endif

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_indivsc (bigintobj_vardnsrecdegspsterm_t A, bigintobj_t s, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_indiv (bigintobj_vardnsrecdegspsterm_scal_cval (A, args), s, args.sargs);
  return bigintobj_vardnsrecdegspsterm_conddelete (A, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_oodivmonomsc_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, unimonom_t m, bigintobj_t s, bigintobj_vardnsrecdegspsterm_args args)
{
  BOOL sfailed, mfailed;
  bigintobj_vardnsrecdegspsterm_t new = bigintobj_vardnsrecdegspsterm_alloc (args);

  sfailed = bigintobj_oodiv (bigintobj_vardnsrecdegspsterm_scal_cval (new, args), bigintobj_vardnsrecdegspsterm_scal (A, args), s, args.sargs);
  mfailed = unimonom_oodiv (bigintobj_vardnsrecdegspsterm_monom_cval (new), bigintobj_vardnsrecdegspsterm_monom (A), m, args.margs);

  if (sfailed || mfailed)
    {
      /* both failures are possible in the multivariate case */
      bigintobj_vardnsrecdegspsterm_free (new, args);
      return NULL;
    }

  return bigintobj_vardnsrecdegspsterm_condcns (C, new, args);
}

#if 0				/* unused ! why did I write this ? */
static BOOL 
bigintobj_vardnsrecdegspsterm_oodivmonomsc (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, unimonom_t m, bigintobj_t s, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  if ((C = bigintobj_vardnsrecdegspsterm_oodivmonomsc_cns (C, A, m, s, args)))
    {
      bigintobj_vardnsrecdegspsterm_glue (C, CT);
      return SUCCESS;
    }
  else
    {
      return FAILURE;
    }
}
#endif

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_indivmonomsc (bigintobj_vardnsrecdegspsterm_t A, unimonom_t m, bigintobj_t s, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_indiv (bigintobj_vardnsrecdegspsterm_scal_cval (A, args), s, args.sargs);
  unimonom_indiv (bigintobj_vardnsrecdegspsterm_monom_cval (A), m, args.margs);

  return bigintobj_vardnsrecdegspsterm_conddelete (A, args);
}

static void 
bigintobj_vardnsrecdegspsterm_args_fileOut (id aFiler, bigintobj_vardnsrecdegspsterm_args * args)
{
  bigintobj_args_fileOut (aFiler, &args->sargs);
  unimonom_args_fileOut (aFiler, &args->margs);
}
static void 
bigintobj_vardnsrecdegspsterm_args_fileIn (id aFiler, bigintobj_vardnsrecdegspsterm_args * args)
{
  bigintobj_args_fileIn (aFiler, &args->sargs);
  unimonom_args_fileIn (aFiler, &args->margs);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_fileOut (id aFiler, bigintobj_vardnsrecdegspsterm_t self, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (bigintobj_vardnsrecdegspsterm_check (self, args));

  bigintobj_fileOut (aFiler, bigintobj_vardnsrecdegspsterm_scal_cval (self, args), args.sargs);
  unimonom_fileOut (aFiler, bigintobj_vardnsrecdegspsterm_monom_cval (self), args.margs);

  return self->nlink;
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspsterm_fileIn_cns (id aFiler, bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_t self = bigintobj_vardnsrecdegspsterm_alloc (args);

  bigintobj_fileIn (aFiler, bigintobj_vardnsrecdegspsterm_scal_cval (self, args), args.sargs);
  unimonom_fileIn (aFiler, bigintobj_vardnsrecdegspsterm_monom_cval (self), args.margs);

  return bigintobj_vardnsrecdegspsterm_cns (C, self);
}

static int 
bigintobj_vardnsrecdegspslist_check (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_t prev;

  for (prev = NULL; A != AT; prev = A, A = A->nlink)
    {
      if (bigintobj_vardnsrecdegspsterm_check (A, args) == 0)
	return 0;
      if (prev && bigintobj_vardnsrecdegspsterm_cmp (prev, A, args) <= 0)
	return 0;
    }

  return 1;
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspslist_copy_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    {
      C = bigintobj_vardnsrecdegspsterm_copy_cns (C, A, args);
      A = A->nlink;
    }
  return C;
}

static void 
bigintobj_vardnsrecdegspslist_copy (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspslist_copy_cns (C, A, AT, args), CT);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspslist_deepcopy_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    {
      C = bigintobj_vardnsrecdegspsterm_deepcopy_cns (C, A, args);
      A = A->nlink;
    }
  return C;
}

static void 
bigintobj_vardnsrecdegspslist_deepcopy (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspslist_deepcopy_cns (C, A, AT, args), CT);
}

static void 
bigintobj_vardnsrecdegspslist_clear (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    {
      bigintobj_vardnsrecdegspsterm_clear (A, args);
      A = A->nlink;
    }
}

static void 
bigintobj_vardnsrecdegspslist_free (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_t t;
  for (; A != AT; A = t)
    {
      t = A->nlink;
      bigintobj_vardnsrecdegspsterm_free (A, args);
    }
}

static int 
bigintobj_vardnsrecdegspslist_count (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT)
{
  int c = 0;
  for (; A != AT; A = A->nlink)
    c++;
  return c;
}

static unsigned 
bigintobj_vardnsrecdegspslist_hash (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_vardnsrecdegspsterm_args args)
{
  return bigintobj_vardnsrecdegspslist_count (A, AT);
}

static int 
bigintobj_vardnsrecdegspslist_iseq (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_vardnsrecdegspsterm_t B, bigintobj_vardnsrecdegspsterm_t BT, bigintobj_vardnsrecdegspsterm_args args)
{
  for (; A != AT && B != BT; A = A->nlink, B = B->nlink)
    {
      if (!bigintobj_vardnsrecdegspsterm_iseq (A, B, args))
	return 0;
    }
  return (A == AT && B == BT);
}

static int 
bigintobj_vardnsrecdegspslist_isop (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_vardnsrecdegspsterm_t B, bigintobj_vardnsrecdegspsterm_t BT, bigintobj_vardnsrecdegspsterm_args args)
{
  for (; A != AT && B != BT; A = A->nlink, B = B->nlink)
    {
      if (!bigintobj_vardnsrecdegspsterm_isop (A, B, args))
	return 0;
    }
  return (A == AT && B == BT);
}

static int 
bigintobj_vardnsrecdegspslist_deg (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_vardnsrecdegspsterm_args args)
{
  return (A == AT) ? -1 : bigintobj_vardnsrecdegspsterm_deg (A, args);
}

static int 
bigintobj_vardnsrecdegspslist_maxdeg (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_vardnsrecdegspsterm_args args)
{
  int max = (A == AT) ? -1 : bigintobj_vardnsrecdegspsterm_deg (A, args);
  for (A = A->nlink; A != AT; A = A->nlink)
    {
      int d = bigintobj_vardnsrecdegspsterm_deg (A, args);
      if (max < d)
	max = d;
    }
  return max;
}

static int 
bigintobj_vardnsrecdegspslist_ord (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_vardnsrecdegspsterm_args args)
{
  return (A == AT) ? -1 : bigintobj_vardnsrecdegspsterm_deg (AT->plink, args);
}

static int 
bigintobj_vardnsrecdegspslist_mindeg (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_vardnsrecdegspsterm_args args)
{
  int min = (A == AT) ? -1 : bigintobj_vardnsrecdegspsterm_deg (A, args);
  for (A = A->nlink; A != AT; A = A->nlink)
    {
      int d = bigintobj_vardnsrecdegspsterm_deg (A, args);
      if (min > d)
	min = d;
    }
  return min;
}

static void 
bigintobj_vardnsrecdegspslist_insert (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, unimonom_t m, bigintobj_t s, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (bigintobj_iszero (s, args.sargs) == NO);

  /* adding to zero */
  if (A == AT)
    {
      bigintobj_vardnsrecdegspsterm_copymonomsc (A, m, s, A, args);
      return;
    }

  /* tail append */
  if (bigintobj_vardnsrecdegspsterm_cmpmonom (AT->plink, m, args) > 0)
    {
      bigintobj_vardnsrecdegspsterm_copymonomsc (AT->plink, m, s, AT, args);
      return;
    }

  /* insertion */
  while (A != AT)
    {
      int cmp = bigintobj_vardnsrecdegspsterm_cmpmonom (A, m, args);
      if (cmp == 0)
	{
	  bigintobj_vardnsrecdegspsterm_inaddsc (A, +1, s, +1, args);
	  return;
	}
      if (cmp < 0)
	{
	  bigintobj_vardnsrecdegspsterm_copymonomsc (A->plink, m, s, A, args);
	  return;
	}
      A = A->nlink;
    }

  fprintf (stderr, "Shouldn't happen\n");
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspslist_ooneg_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    {
      C = bigintobj_vardnsrecdegspsterm_ooneg_cns (C, A, args);
      A = A->nlink;
    }
  return C;
}

static void 
bigintobj_vardnsrecdegspslist_ooneg (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspslist_ooneg_cns (C, A, AT, args), CT);
}

static void 
bigintobj_vardnsrecdegspslist_inneg (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    A = bigintobj_vardnsrecdegspsterm_inneg (A, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspslist_oonegv_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, int v, bigintobj_vardnsrecdegspsterm_args args)
{
  if (v == -1)
    {
      return bigintobj_vardnsrecdegspslist_ooneg_cns (C, A, AT, args);
    }
  else
    {
      return bigintobj_vardnsrecdegspslist_copy_cns (C, A, AT, args);
    }
}

static void 
bigintobj_vardnsrecdegspslist_oonegv (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, int v, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspslist_oonegv_cns (C, A, AT, v, args), CT);
}

static void 
bigintobj_vardnsrecdegspslist_innegv (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, int v, bigintobj_vardnsrecdegspsterm_args args)
{
  if (v == -1)
    bigintobj_vardnsrecdegspslist_inneg (A, AT, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspslist_oodbl_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, int v, bigintobj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    {
      C = bigintobj_vardnsrecdegspsterm_oodbl_cns (C, A, v, args);
      A = A->nlink;
    }
  return C;
}

static void 
bigintobj_vardnsrecdegspslist_oodbl (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, int v, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspslist_oodbl_cns (C, A, AT, v, args), CT);
}

static void 
bigintobj_vardnsrecdegspslist_indbl (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, int v, bigintobj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    A = bigintobj_vardnsrecdegspsterm_indbl (A, v, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspslist_ooadd_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_vardnsrecdegspsterm_t BT, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = bigintobj_vardnsrecdegspsterm_ooadd_cns (C, A, v, B, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = bigintobj_vardnsrecdegspsterm_oonegv_cns (C, B, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = bigintobj_vardnsrecdegspsterm_oonegv_cns (C, A, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return bigintobj_vardnsrecdegspslist_oonegv_cns (C, A, AT, v, args);
  if (B != BT)
    return bigintobj_vardnsrecdegspslist_oonegv_cns (C, B, BT, w, args);
  return C;
}

static void 
bigintobj_vardnsrecdegspslist_ooadd (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_vardnsrecdegspsterm_t BT, int w, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspslist_ooadd_cns (C, A, AT, v, B, BT, w, args), CT);
}

static void 
bigintobj_vardnsrecdegspslist_inadd (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_vardnsrecdegspsterm_t BT, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = bigintobj_vardnsrecdegspsterm_inadd (A, v, B, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  bigintobj_vardnsrecdegspsterm_oonegv (A->plink, B, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = bigintobj_vardnsrecdegspsterm_innegv (A, v, args);
	}
    }

  if (A != AT)
    bigintobj_vardnsrecdegspslist_innegv (A, AT, v, args);
  if (B != BT)
    bigintobj_vardnsrecdegspslist_oonegv (A->plink, B, BT, w, A, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspslist_oomulsc_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    {
      C = bigintobj_vardnsrecdegspsterm_oomulsc_cns (C, A, s, v, args);
      A = A->nlink;
    }
  return C;
}

static void 
bigintobj_vardnsrecdegspslist_oomulsc (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspslist_oomulsc_cns (C, A, AT, s, v, args), CT);
}

static void 
bigintobj_vardnsrecdegspslist_inmulsc (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    A = bigintobj_vardnsrecdegspsterm_inmulsc (A, s, v, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspslist_oomulmonomsc_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, unimonom_t m, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    {
      C = bigintobj_vardnsrecdegspsterm_oomulmonomsc_cns (C, A, m, s, v, args);
      A = A->nlink;
    }
  return C;
}

static void 
bigintobj_vardnsrecdegspslist_oomulmonomsc (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, unimonom_t m, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspslist_oomulmonomsc_cns (C, A, AT, m, s, v, args), CT);
}

static void 
bigintobj_vardnsrecdegspslist_inmulmonomsc (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, unimonom_t m, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    A = bigintobj_vardnsrecdegspsterm_inmulmonomsc (A, m, s, v, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspslist_ooaddmulsc_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_vardnsrecdegspsterm_t BT, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = bigintobj_vardnsrecdegspsterm_ooaddmulsc_cns (C, A, v, B, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = bigintobj_vardnsrecdegspsterm_oomulsc_cns (C, B, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = bigintobj_vardnsrecdegspsterm_oonegv_cns (C, A, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return bigintobj_vardnsrecdegspslist_oonegv_cns (C, A, AT, v, args);
  if (B != BT)
    return bigintobj_vardnsrecdegspslist_oomulsc_cns (C, B, BT, t, w, args);
  return C;
}

static void 
bigintobj_vardnsrecdegspslist_ooaddmulsc (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_vardnsrecdegspsterm_t BT, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspslist_ooaddmulsc_cns (C, A, AT, v, B, BT, t, w, args), CT);
}

static void 
bigintobj_vardnsrecdegspslist_inaddmulsc (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_vardnsrecdegspsterm_t BT, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = bigintobj_vardnsrecdegspsterm_inaddmulsc (A, v, B, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  bigintobj_vardnsrecdegspsterm_oomulsc (A->plink, B, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = bigintobj_vardnsrecdegspsterm_innegv (A, v, args);
	}
    }

  if (A != AT)
    bigintobj_vardnsrecdegspslist_innegv (A, AT, v, args);
  if (B != BT)
    bigintobj_vardnsrecdegspslist_oomulsc (A->plink, B, BT, t, w, A, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspslist_ooaddmulmonomsc_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_vardnsrecdegspsterm_t BT, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsrecdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  C = bigintobj_vardnsrecdegspsterm_ooaddmulmonomsc_cns (C, A, v, B, m, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = bigintobj_vardnsrecdegspsterm_oomulmonomsc_cns (C, B, m, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = bigintobj_vardnsrecdegspsterm_oonegv_cns (C, A, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return bigintobj_vardnsrecdegspslist_oonegv_cns (C, A, AT, v, args);
  if (B != BT)
    return bigintobj_vardnsrecdegspslist_oomulmonomsc_cns (C, B, BT, m, t, w, args);
  return C;
}

static void 
bigintobj_vardnsrecdegspslist_ooaddmulmonomsc (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_vardnsrecdegspsterm_t BT, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspslist_ooaddmulmonomsc_cns (C, A, AT, v, B, BT, m, t, w, args), CT);
}

static void 
bigintobj_vardnsrecdegspslist_inaddmulmonomsc (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_vardnsrecdegspsterm_t BT, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsrecdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  A = bigintobj_vardnsrecdegspsterm_inaddmulmonomsc (A, v, B, m, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  bigintobj_vardnsrecdegspsterm_oomulmonomsc (A->plink, B, m, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = bigintobj_vardnsrecdegspsterm_innegv (A, v, args);
	}
    }

  if (A != AT)
    bigintobj_vardnsrecdegspslist_innegv (A, AT, v, args);
  if (B != BT)
    bigintobj_vardnsrecdegspslist_oomulmonomsc (A->plink, B, BT, m, t, w, A, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspslist_oomulscadd_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_vardnsrecdegspsterm_t BT, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = bigintobj_vardnsrecdegspsterm_oomulscadd_cns (C, A, s, v, B, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = bigintobj_vardnsrecdegspsterm_oonegv_cns (C, B, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = bigintobj_vardnsrecdegspsterm_oomulsc_cns (C, A, s, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return bigintobj_vardnsrecdegspslist_oomulsc_cns (C, A, AT, s, v, args);
  if (B != BT)
    return bigintobj_vardnsrecdegspslist_oonegv_cns (C, B, BT, w, args);
  return C;
}

static void 
bigintobj_vardnsrecdegspslist_oomulscadd (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_vardnsrecdegspsterm_t BT, int w, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspslist_oomulscadd_cns (C, A, AT, s, v, B, BT, w, args), CT);
}

static void 
bigintobj_vardnsrecdegspslist_inmulscadd (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_vardnsrecdegspsterm_t BT, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = bigintobj_vardnsrecdegspsterm_inmulscadd (A, s, v, B, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  bigintobj_vardnsrecdegspsterm_oonegv (A->plink, B, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = bigintobj_vardnsrecdegspsterm_inmulsc (A, s, v, args);
	}
    }

  if (A != AT)
    bigintobj_vardnsrecdegspslist_inmulsc (A, AT, s, v, args);
  if (B != BT)
    bigintobj_vardnsrecdegspslist_oonegv (A->plink, B, BT, w, A, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspslist_oomulscaddmulsc_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_vardnsrecdegspsterm_t BT, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = bigintobj_vardnsrecdegspsterm_oomulscaddmulsc_cns (C, A, s, v, B, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = bigintobj_vardnsrecdegspsterm_oomulsc_cns (C, B, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = bigintobj_vardnsrecdegspsterm_oomulsc_cns (C, A, s, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return bigintobj_vardnsrecdegspslist_oomulsc_cns (C, A, AT, s, v, args);
  if (B != BT)
    return bigintobj_vardnsrecdegspslist_oomulsc_cns (C, B, BT, t, w, args);
  return C;
}

static void 
bigintobj_vardnsrecdegspslist_oomulscaddmulsc (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_vardnsrecdegspsterm_t BT, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspslist_oomulscaddmulsc_cns (C, A, AT, s, v, B, BT, t, w, args), CT);
}

static void 
bigintobj_vardnsrecdegspslist_inmulscaddmulsc (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_vardnsrecdegspsterm_t BT, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = bigintobj_vardnsrecdegspsterm_inmulscaddmulsc (A, s, v, B, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  bigintobj_vardnsrecdegspsterm_oomulsc (A->plink, B, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = bigintobj_vardnsrecdegspsterm_inmulsc (A, s, v, args);
	}
    }

  if (A != AT)
    bigintobj_vardnsrecdegspslist_inmulsc (A, AT, s, v, args);
  if (B != BT)
    bigintobj_vardnsrecdegspslist_oomulsc (A->plink, B, BT, t, w, A, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspslist_oomulscaddmulmonomsc_cns (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_vardnsrecdegspsterm_t BT, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsrecdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  C = bigintobj_vardnsrecdegspsterm_oomulscaddmulmonomsc_cns (C, A, s, v, B, m, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = bigintobj_vardnsrecdegspsterm_oomulmonomsc_cns (C, B, m, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = bigintobj_vardnsrecdegspsterm_oomulsc_cns (C, A, s, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return bigintobj_vardnsrecdegspslist_oomulsc_cns (C, A, AT, s, v, args);
  if (B != BT)
    return bigintobj_vardnsrecdegspslist_oomulmonomsc_cns (C, B, BT, m, t, w, args);
  return C;
}

static void 
bigintobj_vardnsrecdegspslist_oomulscaddmulmonomsc (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_vardnsrecdegspsterm_t BT, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspslist_oomulscaddmulmonomsc_cns (C, A, AT, s, v, B, BT, m, t, w, args), CT);
}

static void 
bigintobj_vardnsrecdegspslist_inmulscaddmulmonomsc (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_t s, int v, bigintobj_vardnsrecdegspsterm_t B, bigintobj_vardnsrecdegspsterm_t BT, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = bigintobj_vardnsrecdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  A = bigintobj_vardnsrecdegspsterm_inmulscaddmulmonomsc (A, s, v, B, m, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  bigintobj_vardnsrecdegspsterm_oomulmonomsc (A->plink, B, m, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = bigintobj_vardnsrecdegspsterm_inmulsc (A, s, v, args);
	}
    }

  if (A != AT)
    bigintobj_vardnsrecdegspslist_inmulsc (A, AT, s, v, args);
  if (B != BT)
    bigintobj_vardnsrecdegspslist_oomulmonomsc (A->plink, B, BT, m, t, w, A, args);
}

static BOOL 
bigintobj_vardnsrecdegspslist_oodivsc (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_t s, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  BOOL failed = NO;

  while (A != AT)
    {
      bigintobj_vardnsrecdegspsterm_t nextC = bigintobj_vardnsrecdegspsterm_oodivsc_cns (C, A, s, args);
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
  bigintobj_vardnsrecdegspsterm_glue (C, CT);
  return failed;
}

static void 
bigintobj_vardnsrecdegspslist_indivsc (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_t s, bigintobj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    A = bigintobj_vardnsrecdegspsterm_indivsc (A, s, args);
}

static BOOL 
bigintobj_vardnsrecdegspslist_oodivmonomsc (bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, unimonom_t m, bigintobj_t s, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  BOOL failed = NO;

  while (A != AT)
    {
      bigintobj_vardnsrecdegspsterm_t nextC = bigintobj_vardnsrecdegspsterm_oodivmonomsc_cns (C, A, m, s, args);
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
  bigintobj_vardnsrecdegspsterm_glue (C, CT);
  return failed;
}

static void 
bigintobj_vardnsrecdegspslist_indivmonomsc (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, unimonom_t m, bigintobj_t s, bigintobj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    A = bigintobj_vardnsrecdegspsterm_indivmonomsc (A, m, s, args);
}

static void 
bigintobj_vardnsrecdegspslist_fileOut (id aFiler, bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT, bigintobj_vardnsrecdegspsterm_args args)
{
  int n;
  n = bigintobj_vardnsrecdegspslist_count (A, AT);
  [aFiler fileOut:&n type:'i'];
  while (A != AT)
    A = bigintobj_vardnsrecdegspsterm_fileOut (aFiler, A, args);
}

static bigintobj_vardnsrecdegspsterm_t 
bigintobj_vardnsrecdegspslist_fileIn_cns (id aFiler, bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_args args)
{
  int n;
  [aFiler fileIn:&n type:'i'];
  while (n--)
    C = bigintobj_vardnsrecdegspsterm_fileIn_cns (aFiler, C, args);
  return C;
}

static void 
bigintobj_vardnsrecdegspslist_fileIn (id aFiler, bigintobj_vardnsrecdegspsterm_t C, bigintobj_vardnsrecdegspsterm_t CT, bigintobj_vardnsrecdegspsterm_args args)
{
  bigintobj_vardnsrecdegspsterm_glue (bigintobj_vardnsrecdegspslist_fileIn_cns (aFiler, C, args), CT);
}

static void 
bigintobj_vardnsrecdegspspol_ix_init (bigintobj_vardnsrecdegspspol_ixt ix, id self)
{
  bigintobj_vardnsrecdegspspol_t v = [self bigintobj_vardnsrecdegspspol_value];
  ix->head = v;
  ix->ix = v;
}

static void 
bigintobj_vardnsrecdegspspol_ix_clear (bigintobj_vardnsrecdegspspol_ixt ix)
{
  /* nothing to clear */
}

static int 
bigintobj_vardnsrecdegspspol_ix_count_aux_aux (bigintobj_vardnsrecdegspsterm_t A, bigintobj_vardnsrecdegspsterm_t AT)
{
  int c = 0;
  for (; A != AT; A = A->nlink)
    c++;
  return c;
}

static int 
bigintobj_vardnsrecdegspspol_ix_count_aux (bigintobj_vardnsrecdegspspol_t self)
{
  return bigintobj_vardnsrecdegspspol_ix_count_aux_aux (self->nlink, self);
}

static int 
bigintobj_vardnsrecdegspspol_ix_count (bigintobj_vardnsrecdegspspol_ixt ix)
{
  /* merde ! can't include entire bigintobj_vardnsrecdegspslist for bigintobj_vardnsrecdegspslist_count */
  return bigintobj_vardnsrecdegspspol_ix_count_aux (ix->head);
}

static int 
bigintobj_vardnsrecdegspspol_ix_isempty_aux (bigintobj_vardnsrecdegspspol_t self)
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
bigintobj_vardnsrecdegspspol_ix_isempty (bigintobj_vardnsrecdegspspol_ixt ix)
{
  /* can't include entire bigintobj_vardnsrecdegspspol for bigintobj_vardnsrecdegspspol_isempty */
  return bigintobj_vardnsrecdegspspol_ix_isempty_aux (ix->head);
}

static int 
bigintobj_vardnsrecdegspspol_ix_ismatch (bigintobj_vardnsrecdegspspol_ixt ix)
{
  return (ix->ix != NULL && ix->ix != ix->head);
}

static void 
bigintobj_vardnsrecdegspspol_ix_tofirst (bigintobj_vardnsrecdegspspol_ixt ix)
{
  ix->ix = ix->head;
}

static void 
bigintobj_vardnsrecdegspspol_ix_tolast (bigintobj_vardnsrecdegspspol_ixt ix)
{
  ix->ix = NULL;
}

static void 
bigintobj_vardnsrecdegspspol_ix_to (bigintobj_vardnsrecdegspspol_ixt ix, int i)
{
  fprintf (stderr, "at: notImplemented\n");
}

static void 
bigintobj_vardnsrecdegspspol_ix_next (bigintobj_vardnsrecdegspspol_ixt ix)
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
bigintobj_vardnsrecdegspspol_ix_prev (bigintobj_vardnsrecdegspspol_ixt ix)
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
bigintobj_vardnsrecdegspspol_check (bigintobj_vardnsrecdegspspol_t self, bigintobj_vardnsrecdegspspol_args args)
{
  assert (self->data == 0xcafebabe);
  return bigintobj_vardnsrecdegspslist_check (self->nlink, self, args);
}

static bigintobj_vardnsrecdegspspol_t 
bigintobj_vardnsrecdegspspol_id2t (id object)
{
  return [object bigintobj_vardnsrecdegspspol_value];
}

static bigintobj_vardnsrecdegspspol_c *
bigintobj_vardnsrecdegspspol_id2c (id object)
{
  return [object bigintobj_vardnsrecdegspspol_reference];
}

static id 
bigintobj_vardnsrecdegspspol_t2id (id proto, bigintobj_vardnsrecdegspspol_t f)
{
  return [proto bigintobj_vardnsrecdegspspol_value:f];
}

static id 
bigintobj_vardnsrecdegspspol_c2id (id proto, bigintobj_vardnsrecdegspspol_c * r)
{
  return [proto bigintobj_vardnsrecdegspspol_reference:r];
}

static int 
bigintobj_vardnsrecdegspspol_isempty (bigintobj_vardnsrecdegspspol_t self)
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
bigintobj_vardnsrecdegspspol_init (bigintobj_vardnsrecdegspspol_t self, bigintobj_vardnsrecdegspspol_args args)
{
  self->data = 0xcafebabe;
  self->nlink = self;
  self->plink = self;
  assert (bigintobj_vardnsrecdegspspol_check (self, args));
}

static void 
bigintobj_vardnsrecdegspspol_copy (bigintobj_vardnsrecdegspspol_t c, bigintobj_vardnsrecdegspspol_t a, bigintobj_vardnsrecdegspspol_args args)
{
  assert (bigintobj_vardnsrecdegspspol_check (a, args));
  bigintobj_vardnsrecdegspspol_init (c, args);
  bigintobj_vardnsrecdegspslist_copy (c, a->nlink, a, c, args);
}

static void 
bigintobj_vardnsrecdegspspol_deepcopy (bigintobj_vardnsrecdegspspol_t c, bigintobj_vardnsrecdegspspol_t a, bigintobj_vardnsrecdegspspol_args args)
{
  assert (bigintobj_vardnsrecdegspspol_check (a, args));
  bigintobj_vardnsrecdegspspol_init (c, args);
  bigintobj_vardnsrecdegspslist_deepcopy (c, a->nlink, a, c, args);
}

static void 
bigintobj_vardnsrecdegspspol_move (bigintobj_vardnsrecdegspspol_t c, bigintobj_vardnsrecdegspspol_t a, bigintobj_vardnsrecdegspspol_args args)
{
  if (bigintobj_vardnsrecdegspspol_isempty (a))
    {
      bigintobj_vardnsrecdegspspol_init (c, args);
    }
  else
    {
      bigintobj_vardnsrecdegspspol_init (c, args);
      bigintobj_vardnsrecdegspsterm_glue (c, a->nlink);
      bigintobj_vardnsrecdegspsterm_glue (a->plink, c);
    }

  a->data = 0;
  assert (bigintobj_vardnsrecdegspspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegspspol_clear (bigintobj_vardnsrecdegspspol_t self, bigintobj_vardnsrecdegspspol_args args)
{
  bigintobj_vardnsrecdegspslist_clear (self->nlink, self, args);
  self->data = 0;
  bigintobj_vardnsrecdegspslist_free (self->nlink, self, args);
}

static int 
bigintobj_vardnsrecdegspspol_count (bigintobj_vardnsrecdegspspol_t self)
{
  return bigintobj_vardnsrecdegspslist_count (self->nlink, self);
}

static unsigned 
bigintobj_vardnsrecdegspspol_hash (bigintobj_vardnsrecdegspspol_t a, bigintobj_vardnsrecdegspspol_args args)
{
  return bigintobj_vardnsrecdegspslist_hash (a->nlink, a, args);
}

static int 
bigintobj_vardnsrecdegspspol_iseq (bigintobj_vardnsrecdegspspol_t a, bigintobj_vardnsrecdegspspol_t b, bigintobj_vardnsrecdegspspol_args args)
{
  return (a == b) ? YES : bigintobj_vardnsrecdegspslist_iseq (a->nlink, a, b->nlink, b, args);
}

static int 
bigintobj_vardnsrecdegspspol_isone (bigintobj_vardnsrecdegspspol_t a, bigintobj_vardnsrecdegspspol_args args)
{
  /* if the leading term is one, then it is one */
  return (bigintobj_vardnsrecdegspspol_isempty (a)) ? 0 : bigintobj_vardnsrecdegspsterm_isone (a->nlink, args);
}

static int 
bigintobj_vardnsrecdegspspol_isminusone (bigintobj_vardnsrecdegspspol_t a, bigintobj_vardnsrecdegspspol_args args)
{
  /* if the leading term is minus one, then it is minus one */
  return (bigintobj_vardnsrecdegspspol_isempty (a)) ? 0 : bigintobj_vardnsrecdegspsterm_isminusone (a->nlink, args);
}

static int 
bigintobj_vardnsrecdegspspol_deg (bigintobj_vardnsrecdegspspol_t self, bigintobj_vardnsrecdegspspol_args args)
{
  return bigintobj_vardnsrecdegspslist_deg (self->nlink, self, args);
}

static int 
bigintobj_vardnsrecdegspspol_ord (bigintobj_vardnsrecdegspspol_t self, bigintobj_vardnsrecdegspspol_args args)
{
  return bigintobj_vardnsrecdegspslist_ord (self->nlink, self, args);
}

static int 
bigintobj_vardnsrecdegspspol_maxdeg (bigintobj_vardnsrecdegspspol_t self, bigintobj_vardnsrecdegspspol_args args)
{
  return bigintobj_vardnsrecdegspslist_maxdeg (self->nlink, self, args);
}

static int 
bigintobj_vardnsrecdegspspol_mindeg (bigintobj_vardnsrecdegspspol_t self, bigintobj_vardnsrecdegspspol_args args)
{
  return bigintobj_vardnsrecdegspslist_mindeg (self->nlink, self, args);
}

static bigintobj_t 
bigintobj_vardnsrecdegspspol_scalat (bigintobj_vardnsrecdegspspol_t self, bigintobj_vardnsrecdegspspol_ixt ix, bigintobj_vardnsrecdegspspol_args args)
{
  assert (bigintobj_vardnsrecdegspspol_ix_ismatch (ix) && ix->head == self);
  return bigintobj_vardnsrecdegspsterm_scal (ix->ix, args);
}

static unimonom_t 
bigintobj_vardnsrecdegspspol_monomat (bigintobj_vardnsrecdegspspol_t self, bigintobj_vardnsrecdegspspol_ixt ix, bigintobj_vardnsrecdegspspol_args args)
{
  assert (bigintobj_vardnsrecdegspspol_ix_ismatch (ix) && ix->head == self);
  return bigintobj_vardnsrecdegspsterm_monom (ix->ix);
}

static bigintobj_t 
bigintobj_vardnsrecdegspspol_scalfirst (bigintobj_vardnsrecdegspspol_t self, bigintobj_vardnsrecdegspspol_args args)
{
  assert (bigintobj_vardnsrecdegspspol_isempty (self) == NO);
  return bigintobj_vardnsrecdegspsterm_scal (self->nlink, args);
}

static unimonom_t 
bigintobj_vardnsrecdegspspol_monomfirst (bigintobj_vardnsrecdegspspol_t self, bigintobj_vardnsrecdegspspol_args args)
{
  assert (bigintobj_vardnsrecdegspspol_isempty (self) == NO);
  return bigintobj_vardnsrecdegspsterm_monom (self->nlink);
}

static void 
bigintobj_vardnsrecdegspspol_remove (bigintobj_vardnsrecdegspspol_t self, bigintobj_vardnsrecdegspspol_args args)
{
  assert (bigintobj_vardnsrecdegspspol_check (self, args) && bigintobj_vardnsrecdegspspol_isempty (self) == NO);
  bigintobj_vardnsrecdegspsterm_delete (self->nlink, args);
  assert (bigintobj_vardnsrecdegspspol_check (self, args));
}

static void 
bigintobj_vardnsrecdegspspol_insert (bigintobj_vardnsrecdegspspol_t self, unimonom_t m, bigintobj_t s, bigintobj_vardnsrecdegspspol_args args)
{
  assert (bigintobj_vardnsrecdegspspol_check (self, args));
  bigintobj_vardnsrecdegspslist_insert (self->nlink, self, m, s, args);
  assert (bigintobj_vardnsrecdegspspol_check (self, args));
}

static int 
bigintobj_vardnsrecdegspspol_iszero (bigintobj_vardnsrecdegspspol_t self, bigintobj_vardnsrecdegspspol_args args)
{
  return bigintobj_vardnsrecdegspspol_isempty (self);
}

static int 
bigintobj_vardnsrecdegspspol_isop (bigintobj_vardnsrecdegspspol_t a, bigintobj_vardnsrecdegspspol_t b, bigintobj_vardnsrecdegspspol_args args)
{
  assert (a != b);
  return bigintobj_vardnsrecdegspslist_isop (a->nlink, a, b->nlink, b, args);
}

static void 
bigintobj_vardnsrecdegspspol_ooneg (bigintobj_vardnsrecdegspspol_t c, bigintobj_vardnsrecdegspspol_t a, bigintobj_vardnsrecdegspspol_args args)
{
  bigintobj_vardnsrecdegspspol_init (c, args);
  bigintobj_vardnsrecdegspslist_ooneg (c, a->nlink, a, c, args);
  assert (bigintobj_vardnsrecdegspspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegspspol_inneg (bigintobj_vardnsrecdegspspol_t a, bigintobj_vardnsrecdegspspol_args args)
{
  bigintobj_vardnsrecdegspslist_inneg (a->nlink, a, args);
  assert (bigintobj_vardnsrecdegspspol_check (a, args));
}

static void 
bigintobj_vardnsrecdegspspol_oodbl (bigintobj_vardnsrecdegspspol_t c, bigintobj_vardnsrecdegspspol_t a, int v, bigintobj_vardnsrecdegspspol_args args)
{
  bigintobj_vardnsrecdegspspol_init (c, args);
  bigintobj_vardnsrecdegspslist_oodbl (c, a->nlink, a, v, c, args);
  assert (bigintobj_vardnsrecdegspspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegspspol_indbl (bigintobj_vardnsrecdegspspol_t a, int v, bigintobj_vardnsrecdegspspol_args args)
{
  bigintobj_vardnsrecdegspslist_indbl (a->nlink, a, v, args);
  assert (bigintobj_vardnsrecdegspspol_check (a, args));
}

static void 
bigintobj_vardnsrecdegspspol_ooadd (bigintobj_vardnsrecdegspspol_t c, bigintobj_vardnsrecdegspspol_t a, int v, bigintobj_vardnsrecdegspspol_t b, int w, bigintobj_vardnsrecdegspspol_args args)
{
  assert (a != b);
  bigintobj_vardnsrecdegspspol_init (c, args);
  bigintobj_vardnsrecdegspslist_ooadd (c, a->nlink, a, v, b->nlink, b, w, c, args);
  assert (bigintobj_vardnsrecdegspspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegspspol_inadd (bigintobj_vardnsrecdegspspol_t a, int v, bigintobj_vardnsrecdegspspol_t b, int w, bigintobj_vardnsrecdegspspol_args args)
{
  assert (a != b);
  bigintobj_vardnsrecdegspslist_inadd (a->nlink, a, v, b->nlink, b, w, args);
  assert (bigintobj_vardnsrecdegspspol_check (a, args));
}

static void 
bigintobj_vardnsrecdegspspol_oomulsc (bigintobj_vardnsrecdegspspol_t c, bigintobj_vardnsrecdegspspol_t a, bigintobj_t s, bigintobj_vardnsrecdegspspol_args args)
{
  bigintobj_vardnsrecdegspspol_init (c, args);
  bigintobj_vardnsrecdegspslist_oomulsc (c, a->nlink, a, s, +1, c, args);
  assert (bigintobj_vardnsrecdegspspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegspspol_inmulsc (bigintobj_vardnsrecdegspspol_t a, bigintobj_t s, bigintobj_vardnsrecdegspspol_args args)
{
  bigintobj_vardnsrecdegspslist_inmulsc (a->nlink, a, s, +1, args);
  assert (bigintobj_vardnsrecdegspspol_check (a, args));
}

static void 
bigintobj_vardnsrecdegspspol_ooaddmulsc (bigintobj_vardnsrecdegspspol_t c, bigintobj_vardnsrecdegspspol_t a, int v, bigintobj_vardnsrecdegspspol_t b, bigintobj_t t, int w, bigintobj_vardnsrecdegspspol_args args)
{
  bigintobj_vardnsrecdegspspol_init (c, args);
  bigintobj_vardnsrecdegspslist_ooaddmulsc (c, a->nlink, a, v, b->nlink, b, t, w, c, args);
  assert (bigintobj_vardnsrecdegspspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegspspol_inaddmulsc (bigintobj_vardnsrecdegspspol_t a, int v, bigintobj_vardnsrecdegspspol_t b, bigintobj_t t, int w, bigintobj_vardnsrecdegspspol_args args)
{
  bigintobj_vardnsrecdegspslist_inaddmulsc (a->nlink, a, v, b->nlink, b, t, w, args);
  assert (bigintobj_vardnsrecdegspspol_check (a, args));
}

static void 
bigintobj_vardnsrecdegspspol_oomulscadd (bigintobj_vardnsrecdegspspol_t c, bigintobj_vardnsrecdegspspol_t a, bigintobj_t s, int v, bigintobj_vardnsrecdegspspol_t b, int w, bigintobj_vardnsrecdegspspol_args args)
{
  bigintobj_vardnsrecdegspspol_init (c, args);
  bigintobj_vardnsrecdegspslist_oomulscadd (c, a->nlink, a, s, v, b->nlink, b, w, c, args);
  assert (bigintobj_vardnsrecdegspspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegspspol_inmulscadd (bigintobj_vardnsrecdegspspol_t a, bigintobj_t s, int v, bigintobj_vardnsrecdegspspol_t b, int w, bigintobj_vardnsrecdegspspol_args args)
{
  bigintobj_vardnsrecdegspslist_inmulscadd (a->nlink, a, s, v, b->nlink, b, w, args);
  assert (bigintobj_vardnsrecdegspspol_check (a, args));
}

static void 
bigintobj_vardnsrecdegspspol_oomulscaddmulsc (bigintobj_vardnsrecdegspspol_t c, bigintobj_vardnsrecdegspspol_t a, bigintobj_t s, int v, bigintobj_vardnsrecdegspspol_t b, bigintobj_t t, int w, bigintobj_vardnsrecdegspspol_args args)
{
  bigintobj_vardnsrecdegspspol_init (c, args);
  bigintobj_vardnsrecdegspslist_oomulscaddmulsc (c, a->nlink, a, s, v, b->nlink, b, t, w, c, args);
  assert (bigintobj_vardnsrecdegspspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegspspol_inmulscaddmulsc (bigintobj_vardnsrecdegspspol_t a, bigintobj_t s, int v, bigintobj_vardnsrecdegspspol_t b, bigintobj_t t, int w, bigintobj_vardnsrecdegspspol_args args)
{
  bigintobj_vardnsrecdegspslist_inmulscaddmulsc (a->nlink, a, s, v, b->nlink, b, t, w, args);
  assert (bigintobj_vardnsrecdegspspol_check (a, args));
}

static BOOL 
bigintobj_vardnsrecdegspspol_oodivsc (bigintobj_vardnsrecdegspspol_t c, bigintobj_vardnsrecdegspspol_t a, bigintobj_t s, bigintobj_vardnsrecdegspspol_args args)
{
  BOOL failed;
  bigintobj_vardnsrecdegspspol_init (c, args);
  failed = bigintobj_vardnsrecdegspslist_oodivsc (c, a->nlink, a, s, c, args);
  assert (bigintobj_vardnsrecdegspspol_check (c, args));
  if (failed)
    bigintobj_vardnsrecdegspspol_clear (c, args);
  return failed;
}

static void 
bigintobj_vardnsrecdegspspol_indivsc (bigintobj_vardnsrecdegspspol_t a, bigintobj_t s, bigintobj_vardnsrecdegspspol_args args)
{
  bigintobj_vardnsrecdegspslist_indivsc (a->nlink, a, s, args);
  assert (bigintobj_vardnsrecdegspspol_check (a, args));
}

static void 
bigintobj_vardnsrecdegspspol_oomulmonomsc (bigintobj_vardnsrecdegspspol_t c, bigintobj_vardnsrecdegspspol_t b, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegspspol_args args)
{
  bigintobj_vardnsrecdegspspol_init (c, args);
  bigintobj_vardnsrecdegspslist_oomulmonomsc (c, b->nlink, b, m, t, w, c, args);
  assert (bigintobj_vardnsrecdegspspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegspspol_inmulmonomsc (bigintobj_vardnsrecdegspspol_t b, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegspspol_args args)
{
  bigintobj_vardnsrecdegspslist_inmulmonomsc (b->nlink, b, m, t, w, args);
  assert (bigintobj_vardnsrecdegspspol_check (b, args));
}

static void 
bigintobj_vardnsrecdegspspol_ooaddmulmonomsc (bigintobj_vardnsrecdegspspol_t c, bigintobj_vardnsrecdegspspol_t a, int v, bigintobj_vardnsrecdegspspol_t b, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegspspol_args args)
{
  bigintobj_vardnsrecdegspspol_init (c, args);
  bigintobj_vardnsrecdegspslist_ooaddmulmonomsc (c, a->nlink, a, v, b->nlink, b, m, t, w, c, args);
  assert (bigintobj_vardnsrecdegspspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegspspol_inaddmulmonomsc (bigintobj_vardnsrecdegspspol_t a, int v, bigintobj_vardnsrecdegspspol_t b, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegspspol_args args)
{
  bigintobj_vardnsrecdegspslist_inaddmulmonomsc (a->nlink, a, v, b->nlink, b, m, t, w, args);
  assert (bigintobj_vardnsrecdegspspol_check (a, args));
}

static void 
bigintobj_vardnsrecdegspspol_oomulscaddmulmonomsc (bigintobj_vardnsrecdegspspol_t c, bigintobj_vardnsrecdegspspol_t a, bigintobj_t s, int v, bigintobj_vardnsrecdegspspol_t b, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegspspol_args args)
{
  bigintobj_vardnsrecdegspspol_init (c, args);
  bigintobj_vardnsrecdegspslist_oomulscaddmulmonomsc (c, a->nlink, a, s, v, b->nlink, b, m, t, w, c, args);
  assert (bigintobj_vardnsrecdegspspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegspspol_inmulscaddmulmonomsc (bigintobj_vardnsrecdegspspol_t a, bigintobj_t s, int v, bigintobj_vardnsrecdegspspol_t b, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegspspol_args args)
{
  bigintobj_vardnsrecdegspslist_inmulscaddmulmonomsc (a->nlink, a, s, v, b->nlink, b, m, t, w, args);
  assert (bigintobj_vardnsrecdegspspol_check (a, args));
}

static BOOL 
bigintobj_vardnsrecdegspspol_oodivmonomsc (bigintobj_vardnsrecdegspspol_t c, bigintobj_vardnsrecdegspspol_t b, unimonom_t m, bigintobj_t t, bigintobj_vardnsrecdegspspol_args args)
{
  BOOL failed;
  bigintobj_vardnsrecdegspspol_init (c, args);
  failed = bigintobj_vardnsrecdegspslist_oodivmonomsc (c, b->nlink, b, m, t, c, args);
  assert (bigintobj_vardnsrecdegspspol_check (c, args));
  if (failed)
    bigintobj_vardnsrecdegspspol_clear (c, args);
  return failed;
}

static void 
bigintobj_vardnsrecdegspspol_indivmonomsc (bigintobj_vardnsrecdegspspol_t b, unimonom_t m, bigintobj_t t, bigintobj_vardnsrecdegspspol_args args)
{
  bigintobj_vardnsrecdegspslist_indivmonomsc (b->nlink, b, m, t, args);
  assert (bigintobj_vardnsrecdegspspol_check (b, args));
}

static void 
bigintobj_vardnsrecdegspspol_args_fileOut (id aFiler, bigintobj_vardnsrecdegspspol_args * args)
{
  bigintobj_vardnsrecdegspsterm_args_fileOut (aFiler, args);
}
static void 
bigintobj_vardnsrecdegspspol_args_fileIn (id aFiler, bigintobj_vardnsrecdegspspol_args * args)
{
  bigintobj_vardnsrecdegspsterm_args_fileIn (aFiler, args);
}

static void 
bigintobj_vardnsrecdegspspol_fileOut (id aFiler, bigintobj_vardnsrecdegspspol_t self, bigintobj_vardnsrecdegspspol_args args)
{
  assert (bigintobj_vardnsrecdegspspol_check (self, args));
  bigintobj_vardnsrecdegspslist_fileOut (aFiler, self->nlink, self, args);
}

static void 
bigintobj_vardnsrecdegspspol_fileIn (id aFiler, bigintobj_vardnsrecdegspspol_t self, bigintobj_vardnsrecdegspspol_args args)
{
  bigintobj_vardnsrecdegspspol_init (self, args);
  bigintobj_vardnsrecdegspslist_fileIn (aFiler, self, self, args);
  assert (bigintobj_vardnsrecdegspspol_check (self, args));
}

static bigintobj_vardnsrecdegspspol_args 
bigintobj_vardnsrecdegspspol_getargs (id self)
{
  bigintobj_vardnsrecdegspspol_args res;
  res.sargs = bigintobj_getargs ([[self termZero] coefficient]);
  res.margs = 0;		/* unused */
  return res;
}

static int 
bigintobj_vardnsrecdegspspol_expat (bigintobj_vardnsrecdegspspol_t self, bigintobj_vardnsrecdegspspol_ixt ix, bigintobj_vardnsrecdegspspol_args args)
{
  return bigintobj_vardnsrecdegspspol_monomat (self, ix, args);
}

static int 
bigintobj_vardnsrecdegspspol_expfirst (bigintobj_vardnsrecdegspspol_t self, bigintobj_vardnsrecdegspspol_args args)
{
  return bigintobj_vardnsrecdegspspol_monomfirst (self, args);
}
@implementation bigintobj_vardnsrecdegsps_polynomial : vardnsrecdegsps_polynomial

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
  bigintobj_vardnsrecdegspspol_init (&value, bigintobj_vardnsrecdegspspol_getargs (self));
  assert ([self check]);
  return self;
}

+ scalarZero:aScalar coefficientZero:aCoef symbols:aCltn
{
  return [[super new] _setUpScalarZero:aScalar coefficientZero:aCoef symbols:aCltn];
}

- empty
{
  bigintobj_vardnsrecdegspspol_c c;
  assert ([self check]);
  /* in vardns case, init takes a capacity */
  bigintobj_vardnsrecdegspspol_init (&c, bigintobj_vardnsrecdegspspol_getargs (self));
  return bigintobj_vardnsrecdegspspol_c2id (self, &c);
}

- (int) numTerms
{
  /* seems to take getargs in degdns case */
  assert ([self check]);
  return bigintobj_vardnsrecdegspspol_count (&value);
}

- (bigintobj_vardnsrecdegspspol_t)bigintobj_vardnsrecdegspspol_value
{
  return &value;
}

- dobigintobj_vardnsrecdegspspol_value:(bigintobj_vardnsrecdegspspol_t)aValue
{
  bigintobj_vardnsrecdegspspol_copy (&value, aValue, bigintobj_vardnsrecdegspspol_getargs (self));
  assert ([self check]);
  return self;
}

- bigintobj_vardnsrecdegspspol_value:(bigintobj_vardnsrecdegspspol_t)aValue
{
  return [[self clone] dobigintobj_vardnsrecdegspspol_value:aValue];
}

- (bigintobj_vardnsrecdegspspol_t)bigintobj_vardnsrecdegspspol_reference
{
  return &value;
}

- dobigintobj_vardnsrecdegspspol_reference:(bigintobj_vardnsrecdegspspol_c *)aReference
{
  bigintobj_vardnsrecdegspspol_move (&value, aReference, bigintobj_vardnsrecdegspspol_getargs (self));
  assert ([self check]);
  return self;
}

- bigintobj_vardnsrecdegspspol_reference:(bigintobj_vardnsrecdegspspol_c *)aReference
{
  return [[self clone] dobigintobj_vardnsrecdegspspol_reference:aReference];
}

- copy
{
  bigintobj_vardnsrecdegspspol_c c;
  assert ([self check]);
  bigintobj_vardnsrecdegspspol_copy (&c, &value, bigintobj_vardnsrecdegspspol_getargs (self));
  return bigintobj_vardnsrecdegspspol_c2id (self, &c);
}

- deepCopy
{
  bigintobj_vardnsrecdegspspol_c c;
  assert ([self check]);
  bigintobj_vardnsrecdegspspol_deepcopy (&c, &value, bigintobj_vardnsrecdegspspol_getargs (self));
  return bigintobj_vardnsrecdegspspol_c2id (self, &c);
}

- (BOOL) isEmpty
{
  return bigintobj_vardnsrecdegspspol_isempty (&value);
}

- (BOOL) isOne
{
  return bigintobj_vardnsrecdegspspol_isone (&value, bigintobj_vardnsrecdegspspol_getargs (self));
}

- (BOOL) isMinusOne
{
  return bigintobj_vardnsrecdegspspol_isminusone (&value, bigintobj_vardnsrecdegspspol_getargs (self));
}

- (unsigned) hash
{
  return bigintobj_vardnsrecdegspspol_hash (bigintobj_vardnsrecdegspspol_id2t (self), bigintobj_vardnsrecdegspspol_getargs (self));
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
      return bigintobj_vardnsrecdegspspol_iseq (bigintobj_vardnsrecdegspspol_id2t (self), bigintobj_vardnsrecdegspspol_id2t (b), bigintobj_vardnsrecdegspspol_getargs (self));
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
      return !bigintobj_vardnsrecdegspspol_iseq (bigintobj_vardnsrecdegspspol_id2t (self), bigintobj_vardnsrecdegspspol_id2t (b), bigintobj_vardnsrecdegspspol_getargs (self));
    }
}

- (BOOL) isZero
{
  assert ([self check]);
  return bigintobj_vardnsrecdegspspol_iszero (bigintobj_vardnsrecdegspspol_id2t (self), bigintobj_vardnsrecdegspspol_getargs (self));
}

- (BOOL) notZero
{
  assert ([self check]);
  return !bigintobj_vardnsrecdegspspol_iszero (bigintobj_vardnsrecdegspspol_id2t (self), bigintobj_vardnsrecdegspspol_getargs (self));
}

- (BOOL) isOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return bigintobj_vardnsrecdegspspol_isop (bigintobj_vardnsrecdegspspol_id2t (self), bigintobj_vardnsrecdegspspol_id2t (b), bigintobj_vardnsrecdegspspol_getargs (self));
}

- (BOOL) notOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return !bigintobj_vardnsrecdegspspol_isop (bigintobj_vardnsrecdegspspol_id2t (self), bigintobj_vardnsrecdegspspol_id2t (b), bigintobj_vardnsrecdegspspol_getargs (self));
}

- negate
{
  bigintobj_vardnsrecdegspspol_c c;
  assert ([self check]);
  bigintobj_vardnsrecdegspspol_ooneg (&c, bigintobj_vardnsrecdegspspol_id2t (self), bigintobj_vardnsrecdegspspol_getargs (self));
  return bigintobj_vardnsrecdegspspol_c2id (self, &c);
}

- _double:(int)v
{
  bigintobj_vardnsrecdegspspol_c c;
  assert ([self check]);
  bigintobj_vardnsrecdegspspol_oodbl (&c, bigintobj_vardnsrecdegspspol_id2t (self), v, bigintobj_vardnsrecdegspspol_getargs (self));
  return bigintobj_vardnsrecdegspspol_c2id (self, &c);
}

- double
{
  bigintobj_vardnsrecdegspspol_c c;
  assert ([self check]);
  bigintobj_vardnsrecdegspspol_oodbl (&c, bigintobj_vardnsrecdegspspol_id2t (self), +1, bigintobj_vardnsrecdegspspol_getargs (self));
  return bigintobj_vardnsrecdegspspol_c2id (self, &c);
}

- _add:(int)v:b:(int)w
{
  bigintobj_vardnsrecdegspspol_c c;
  assert ([self sameClass:b] && v * v == 1 && w * w == 1 && self != b);
  bigintobj_vardnsrecdegspspol_ooadd (&c, bigintobj_vardnsrecdegspspol_id2t (self), v, bigintobj_vardnsrecdegspspol_id2t (b), w, bigintobj_vardnsrecdegspspol_getargs (self));
  return bigintobj_vardnsrecdegspspol_c2id (self, &c);
}

- add:b
{
  bigintobj_vardnsrecdegspspol_c c;
  assert ([self checkSameClass:b] && self != b);
  bigintobj_vardnsrecdegspspol_ooadd (&c, bigintobj_vardnsrecdegspspol_id2t (self), +1, bigintobj_vardnsrecdegspspol_id2t (b), +1, bigintobj_vardnsrecdegspspol_getargs (self));
  return bigintobj_vardnsrecdegspspol_c2id (self, &c);
}

- subtract:b
{
  bigintobj_vardnsrecdegspspol_c c;
  assert ([self checkSameClass:b] && self != b);
  bigintobj_vardnsrecdegspspol_ooadd (&c, bigintobj_vardnsrecdegspspol_id2t (self), +1, bigintobj_vardnsrecdegspspol_id2t (b), -1, bigintobj_vardnsrecdegspspol_getargs (self));
  return bigintobj_vardnsrecdegspspol_c2id (self, &c);
}

- (int) leadingDegree
{
  return bigintobj_vardnsrecdegspspol_deg (&value, bigintobj_vardnsrecdegspspol_getargs (self));
}

- (int) lastDegree
{
  return bigintobj_vardnsrecdegspspol_ord (&value, bigintobj_vardnsrecdegspspol_getargs (self));
}

- (int) maxDegree
{
  return bigintobj_vardnsrecdegspspol_maxdeg (&value, bigintobj_vardnsrecdegspspol_getargs (self));
}

- (int) minDegree
{
  return bigintobj_vardnsrecdegspspol_mindeg (&value, bigintobj_vardnsrecdegspspol_getargs (self));
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

  bigintobj_vardnsrecdegspspol_check (&value, bigintobj_vardnsrecdegspspol_getargs (self));
  return self;
}

- release
{
  bigintobj_vardnsrecdegspspol_clear (&value, bigintobj_vardnsrecdegspspol_getargs (self));
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
  id aSequence = [bigintobj_vardnsrecdegspspol_sequence content:self];
  return [CASequence over:aSequence];
}

- elt_bigintobj_vardnsrecdegspspol_ix:(bigintobj_vardnsrecdegspspol_ixt)ix
{
  if (bigintobj_vardnsrecdegspspol_ix_ismatch (ix))
    {
      id c, s;
      int e;
      bigintobj_t t;
      t = bigintobj_vardnsrecdegspspol_scalat (&value, ix, bigintobj_vardnsrecdegspspol_getargs (self));
      e = bigintobj_vardnsrecdegspspol_expat (&value, ix, bigintobj_vardnsrecdegspspol_getargs (self));
      c = bigintobj_t2id ([termZero coefficient], t);
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
      bigintobj_t t;
      assert ([self check]);

      t = bigintobj_vardnsrecdegspspol_scalfirst (&value, bigintobj_vardnsrecdegspspol_getargs (self));
      e = bigintobj_vardnsrecdegspspol_expfirst (&value, bigintobj_vardnsrecdegspspol_getargs (self));
      c = bigintobj_t2id ([termZero coefficient], t);
      s = (e) ? [termZero symbol] : nil;
      lt = [termZero coefficient:c symbol:s exponent:e];

      bigintobj_vardnsrecdegspspol_remove (&value, bigintobj_vardnsrecdegspspol_getargs (self));
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
      bigintobj_c c;
      bigintobj_t r;
      int e;
      assert ([aTerm check]);
      assert ([self check]);
      r = bigintobj_id2ref ([aTerm coefficient], &c);
      e = [aTerm exponent];
      bigintobj_vardnsrecdegspspol_insert (&value, e, r, bigintobj_vardnsrecdegspspol_getargs (self));
      assert ([aTerm check]);
      [self invalidate];
      assert ([self check]);
      return self;
    }
}

- multiplyCoefficient:s
{
  bigintobj_vardnsrecdegspspol_c c;
  bigintobj_c sc;
  bigintobj_vardnsrecdegspspol_oomulsc (&c, bigintobj_vardnsrecdegspspol_id2t (self), bigintobj_id2ref (s, &sc), bigintobj_vardnsrecdegspspol_getargs (self));
  return bigintobj_vardnsrecdegspspol_c2id (self, &c);
}

- divideCoefficient:s
{
  bigintobj_vardnsrecdegspspol_c c;
  bigintobj_c sc;
  BOOL failed = bigintobj_vardnsrecdegspspol_oodivsc (&c, bigintobj_vardnsrecdegspspol_id2t (self), bigintobj_id2ref (s, &sc), bigintobj_vardnsrecdegspspol_getargs (self));
  return (failed) ? nil : bigintobj_vardnsrecdegspspol_c2id (self, &c);
}

- _add:(int)v:B multiplyCoefficient:b:(int)w
{
  bigintobj_vardnsrecdegspspol_c c;
  bigintobj_c bc;
  bigintobj_vardnsrecdegspspol_ooaddmulsc (&c, bigintobj_vardnsrecdegspspol_id2t (self), v, bigintobj_vardnsrecdegspspol_id2t (B), bigintobj_id2ref (b, &bc), w, bigintobj_vardnsrecdegspspol_getargs (self));
  return bigintobj_vardnsrecdegspspol_c2id (self, &c);
}

- _multiplyCoefficient:a:(int)v add:B:(int)w
{
  bigintobj_vardnsrecdegspspol_c c;
  bigintobj_c ac;
  bigintobj_vardnsrecdegspspol_oomulscadd (&c, bigintobj_vardnsrecdegspspol_id2t (self), bigintobj_id2ref (a, &ac), v, bigintobj_vardnsrecdegspspol_id2t (B), w, bigintobj_vardnsrecdegspspol_getargs (self));
  return bigintobj_vardnsrecdegspspol_c2id (self, &c);
}

- _multiplyCoefficient:a:(int)v add:B multiplyCoefficient:b:(int)w
{
  bigintobj_vardnsrecdegspspol_c c;
  bigintobj_c ac, bc;
  bigintobj_vardnsrecdegspspol_oomulscaddmulsc (&c, bigintobj_vardnsrecdegspspol_id2t (self), bigintobj_id2ref (a, &ac), v, bigintobj_vardnsrecdegspspol_id2t (B), bigintobj_id2ref (b, &bc), w, bigintobj_vardnsrecdegspspol_getargs (self));
  return bigintobj_vardnsrecdegspspol_c2id (self, &c);
}

- multiplyTerm:aTerm
{
  bigintobj_vardnsrecdegspspol_c c;
  bigintobj_t s;
  bigintobj_c sc;
  s = bigintobj_id2ref ([aTerm coefficient], &sc);
  bigintobj_vardnsrecdegspspol_oomulmonomsc (&c, bigintobj_vardnsrecdegspspol_id2t (self), [aTerm exponent], s, +1, bigintobj_vardnsrecdegspspol_getargs (self));
  return bigintobj_vardnsrecdegspspol_c2id (self, &c);
}

- _multiplyTerm:aTerm:(int)v
{
  bigintobj_vardnsrecdegspspol_c c;
  bigintobj_t s;
  bigintobj_c sc;
  s = bigintobj_id2ref ([aTerm coefficient], &sc);
  bigintobj_vardnsrecdegspspol_oomulmonomsc (&c, bigintobj_vardnsrecdegspspol_id2t (self), [aTerm exponent], s, v, bigintobj_vardnsrecdegspspol_getargs (self));
  return bigintobj_vardnsrecdegspspol_c2id (self, &c);
}

- divideTerm:aTerm
{
  int e;
  bigintobj_vardnsrecdegspspol_c c;
  BOOL failed;
  bigintobj_t s;
  bigintobj_c sc;

  e = [aTerm exponent];
  s = bigintobj_id2ref ([aTerm coefficient], &sc);
  failed = bigintobj_vardnsrecdegspspol_oodivmonomsc (&c, bigintobj_vardnsrecdegspspol_id2t (self), e, s, bigintobj_vardnsrecdegspspol_getargs (self));
  return (failed) ? nil : bigintobj_vardnsrecdegspspol_c2id (self, &c);
}

- _add:(int)v:B multiplyTerm:b:(int)w
{
  bigintobj_vardnsrecdegspspol_c c;
  bigintobj_c bc;
  bigintobj_t bs;
  bs = bigintobj_id2ref ([b coefficient], &bc);
  bigintobj_vardnsrecdegspspol_ooaddmulmonomsc (&c, bigintobj_vardnsrecdegspspol_id2c (self), v, bigintobj_vardnsrecdegspspol_id2t (B), [b exponent], bs, w, bigintobj_vardnsrecdegspspol_getargs (self));
  return bigintobj_vardnsrecdegspspol_c2id (self, &c);
}

- _multiplyCoefficient:a:(int)v add:B multiplyTerm:b:(int)w
{
  bigintobj_vardnsrecdegspspol_c c;
  bigintobj_c ac, bc;
  bigintobj_t as, bs;
  as = bigintobj_id2ref (a, &ac);
  bs = bigintobj_id2ref ([b coefficient], &bc);
  bigintobj_vardnsrecdegspspol_oomulscaddmulmonomsc (&c, bigintobj_vardnsrecdegspspol_id2c (self), as, v, bigintobj_vardnsrecdegspspol_id2t (B), [b exponent], bs, w, bigintobj_vardnsrecdegspspol_getargs (self));
  return bigintobj_vardnsrecdegspspol_c2id (self, &c);
}


- fileOutOn:aFiler
{
  bigintobj_vardnsrecdegspspol_args args;
  [super fileOutOn:aFiler];
  args = bigintobj_vardnsrecdegspspol_getargs (self);	/* can't do this in fileIn case */
  bigintobj_vardnsrecdegspspol_args_fileOut (aFiler, &args);
  bigintobj_vardnsrecdegspspol_fileOut (aFiler, &value, args);
  return self;
}

- fileInFrom:aFiler
{
  bigintobj_vardnsrecdegspspol_args args;
  [super fileInFrom:aFiler];
  bigintobj_vardnsrecdegspspol_args_fileIn (aFiler, &args);
  bigintobj_vardnsrecdegspspol_fileIn (aFiler, &value, args);
  return self;
}

@end
 
