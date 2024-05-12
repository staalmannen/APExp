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
 * $Id: idrdpolc.m,v 1.6 2000/10/12 14:40:25 stes Exp $
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

static int 
bigintobj_vardnsrecdegdnspolseq_check (bigintobj_vardnsrecdegdnspolseq_t self, int n, bigintobj_vardnsrecdegdnspol_args args)
{
  if (n)
    {
      bigintobj_t lcf = bigintobjseq_last (self, n, args.sargs);
      assert (!bigintobj_iszero (lcf, args.sargs));
    }

  return bigintobjseq_check (self, n, args.sargs);
}

static int 
bigintobj_vardnsrecdegdnspolseq_copy (bigintobj_vardnsrecdegdnspolseq_t c, bigintobj_vardnsrecdegdnspolseq_t a, int n, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobjseq_copy (c, a, n, args.sargs);
  return n;
}

static int 
bigintobj_vardnsrecdegdnspolseq_deepcopy (bigintobj_vardnsrecdegdnspolseq_t c, bigintobj_vardnsrecdegdnspolseq_t a, int n, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobjseq_deepcopy (c, a, n, args.sargs);
  return n;
}

static int 
bigintobj_vardnsrecdegdnspolseq_count (bigintobj_vardnsrecdegdnspolseq_t self, int n, bigintobj_vardnsrecdegdnspol_args args)
{
  int count = 0;
  while (n--)
    {
      if (!bigintobj_iszero (bigintobjseq_tval (self), args.sargs))
	count++;
      self += bigintobj_size (args.sargs);
    }
  return count;
}

static int 
bigintobj_vardnsrecdegdnspolseq_ord (bigintobj_vardnsrecdegdnspolseq_t self, int n, bigintobj_vardnsrecdegdnspol_args args)
{
  int ord = -1;
  while (n--)
    {
      if (bigintobj_iszero (bigintobjseq_tval (self), args.sargs))
	{
	  ord++;
	  self += bigintobj_size (args.sargs);
	}
      else
	{
	  break;
	}
    }
  return ord;
}

static int 
bigintobj_vardnsrecdegdnspolseq_iseq (bigintobj_vardnsrecdegdnspolseq_t a, int an, bigintobj_vardnsrecdegdnspolseq_t b, int bn, bigintobj_vardnsrecdegdnspol_args args)
{
  return (an == bn) ? bigintobjseq_iseq (a, b, an, args.sargs) : 0;
}

static int 
bigintobj_vardnsrecdegdnspolseq_isop (bigintobj_vardnsrecdegdnspolseq_t a, int an, bigintobj_vardnsrecdegdnspolseq_t b, int bn, bigintobj_vardnsrecdegdnspol_args args)
{
  return (an == bn) ? bigintobjseq_isop (a, b, an, args.sargs) : 0;
}

static int 
bigintobj_vardnsrecdegdnspolseq_hash (bigintobj_vardnsrecdegdnspolseq_t a, int an, bigintobj_vardnsrecdegdnspol_args args)
{
  return bigintobjseq_hash (a, an, args.sargs);
}

static int 
bigintobj_vardnsrecdegdnspolseq_isone (bigintobj_vardnsrecdegdnspolseq_t a, int an, bigintobj_vardnsrecdegdnspol_args args)
{
  return an == 1 && bigintobj_isone (bigintobjseq_tval (a), args.sargs);
}

static int 
bigintobj_vardnsrecdegdnspolseq_isminusone (bigintobj_vardnsrecdegdnspolseq_t a, int an, bigintobj_vardnsrecdegdnspol_args args)
{
  return an == 1 && bigintobj_isminusone (bigintobjseq_tval (a), args.sargs);
}

static int 
bigintobj_vardnsrecdegdnspolseq_removezeroes (bigintobj_vardnsrecdegdnspolseq_t a, int n, bigintobj_vardnsrecdegdnspol_args args)
{
  a += n * bigintobj_size (args.sargs);
  while (n--)
    {
      a -= bigintobj_size (args.sargs);
      if (bigintobj_iszero (bigintobjseq_tval (a), args.sargs))
	{
	  bigintobj_clear (bigintobjseq_cval (a), args.sargs);
	}
      else
	{
	  break;
	}
    }
  return n + 1;
}

static int 
bigintobj_vardnsrecdegdnspolseq_delete (bigintobj_vardnsrecdegdnspolseq_t self, int n, bigintobj_vardnsrecdegdnspol_args args)
{
  n = n - 1;
  assert (n >= 0);
  bigintobj_clear (bigintobjseq_cvalat (self, n, args.sargs), args.sargs);
  return bigintobj_vardnsrecdegdnspolseq_removezeroes (self, n, args);
}

static int 
bigintobj_vardnsrecdegdnspolseq_insert (bigintobj_vardnsrecdegdnspolseq_t self, int n, int e, bigintobj_t s, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (bigintobj_iszero (s, args.sargs) == 0);
  if (e < n)
    {
      bigintobj_inadd (bigintobjseq_cvalat (self, e, args.sargs), +1, s, +1, args.sargs);
      return bigintobj_vardnsrecdegdnspolseq_removezeroes (self, n, args);
    }
  else
    {
      bigintobjseq_oozero (self + n * bigintobj_size (args.sargs), e + 1 - n, args.sargs);
      bigintobj_inadd (bigintobjseq_cvalat (self, e, args.sargs), +1, s, +1, args.sargs);
      return e + 1;
    }
}

static int 
bigintobj_vardnsrecdegdnspolseq_ooneg (bigintobj_vardnsrecdegdnspolseq_t c, bigintobj_vardnsrecdegdnspolseq_t a, int n, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobjseq_ooneg (c, a, n, args.sargs);
  return n;
}

static int 
bigintobj_vardnsrecdegdnspolseq_inneg (bigintobj_vardnsrecdegdnspolseq_t a, int n, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobjseq_inneg (a, n, args.sargs);
  return n;
}

static int 
bigintobj_vardnsrecdegdnspolseq_oodbl (bigintobj_vardnsrecdegdnspolseq_t c, bigintobj_vardnsrecdegdnspolseq_t a, int n, int v, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobjseq_oodbl (c, a, v, n, args.sargs);
  return bigintobj_vardnsrecdegdnspolseq_removezeroes (c, n, args);
}

static int 
bigintobj_vardnsrecdegdnspolseq_indbl (bigintobj_vardnsrecdegdnspolseq_t a, int n, int v, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobjseq_indbl (a, v, n, args.sargs);
  return bigintobj_vardnsrecdegdnspolseq_removezeroes (a, n, args);
}

static int 
bigintobj_vardnsrecdegdnspolseq_ooadd (bigintobj_vardnsrecdegdnspolseq_t c, bigintobj_vardnsrecdegdnspolseq_t a, int an, int v, bigintobj_vardnsrecdegdnspolseq_t b, int bn, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      bigintobjseq_ooadd (c, a, v, b, w, an, args.sargs);
      return bigintobj_vardnsrecdegdnspolseq_removezeroes (c, an, args);
    }
  else
    {
      if (an < bn)
	{
	  bigintobjseq_ooadd (c, a, v, b, w, an, args.sargs);
	  c += an * bigintobj_size (args.sargs);
	  b += an * bigintobj_size (args.sargs);
	  bigintobjseq_oonegv (c, b, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  bigintobjseq_ooadd (c, a, v, b, w, bn, args.sargs);
	  c += bn * bigintobj_size (args.sargs);
	  a += bn * bigintobj_size (args.sargs);
	  bigintobjseq_oonegv (c, a, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static int 
bigintobj_vardnsrecdegdnspolseq_inadd (bigintobj_vardnsrecdegdnspolseq_t a, int an, int v, bigintobj_vardnsrecdegdnspolseq_t b, int bn, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      bigintobjseq_inadd (a, v, b, w, an, args.sargs);
      return bigintobj_vardnsrecdegdnspolseq_removezeroes (a, an, args);
    }
  else
    {
      if (an < bn)
	{
	  bigintobjseq_inadd (a, v, b, w, an, args.sargs);
	  a += an * bigintobj_size (args.sargs);
	  b += an * bigintobj_size (args.sargs);
	  bigintobjseq_oonegv (a, b, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  bigintobjseq_inadd (a, v, b, w, bn, args.sargs);
	  a += bn * bigintobj_size (args.sargs);
	  bigintobjseq_innegv (a, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static int 
bigintobj_vardnsrecdegdnspolseq_oomulsc (bigintobj_vardnsrecdegdnspolseq_t c, bigintobj_vardnsrecdegdnspolseq_t a, int n, bigintobj_t s, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobjseq_oomulsc (c, a, s, n, args.sargs);
  return bigintobj_vardnsrecdegdnspolseq_removezeroes (c, n, args);
}

static int 
bigintobj_vardnsrecdegdnspolseq_inmulsc (bigintobj_vardnsrecdegdnspolseq_t a, int n, bigintobj_t s, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobjseq_inmulsc (a, s, n, args.sargs);
  return bigintobj_vardnsrecdegdnspolseq_removezeroes (a, n, args);
}

static int 
bigintobj_vardnsrecdegdnspolseq_ooaddmulsc (bigintobj_vardnsrecdegdnspolseq_t c, bigintobj_vardnsrecdegdnspolseq_t a, int an, int v, bigintobj_vardnsrecdegdnspolseq_t b, int bn, bigintobj_t t, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      bigintobjseq_ooaddmulsc (c, a, v, b, t, w, an, args.sargs);
      return bigintobj_vardnsrecdegdnspolseq_removezeroes (c, an, args);
    }
  else
    {
      if (an < bn)
	{
	  bigintobjseq_ooaddmulsc (c, a, v, b, t, w, an, args.sargs);
	  c += an * bigintobj_size (args.sargs);
	  b += an * bigintobj_size (args.sargs);
	  bigintobjseq_oomulscv (c, b, t, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  bigintobjseq_ooaddmulsc (c, a, v, b, t, w, bn, args.sargs);
	  c += bn * bigintobj_size (args.sargs);
	  a += bn * bigintobj_size (args.sargs);
	  bigintobjseq_oonegv (c, a, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static int 
bigintobj_vardnsrecdegdnspolseq_inaddmulsc (bigintobj_vardnsrecdegdnspolseq_t a, int an, int v, bigintobj_vardnsrecdegdnspolseq_t b, int bn, bigintobj_t t, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      bigintobjseq_inaddmulsc (a, v, b, t, w, an, args.sargs);
      return bigintobj_vardnsrecdegdnspolseq_removezeroes (a, an, args);
    }
  else
    {
      if (an < bn)
	{
	  bigintobjseq_inaddmulsc (a, v, b, t, w, an, args.sargs);
	  a += an * bigintobj_size (args.sargs);
	  b += an * bigintobj_size (args.sargs);
	  bigintobjseq_oomulscv (a, b, t, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  bigintobjseq_inaddmulsc (a, v, b, t, w, bn, args.sargs);
	  a += bn * bigintobj_size (args.sargs);
	  bigintobjseq_innegv (a, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static int 
bigintobj_vardnsrecdegdnspolseq_oomulscadd (bigintobj_vardnsrecdegdnspolseq_t c, bigintobj_vardnsrecdegdnspolseq_t a, int an, bigintobj_t s, int v, bigintobj_vardnsrecdegdnspolseq_t b, int bn, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      bigintobjseq_oomulscadd (c, a, s, v, b, w, an, args.sargs);
      return bigintobj_vardnsrecdegdnspolseq_removezeroes (c, an, args);
    }
  else
    {
      if (an < bn)
	{
	  bigintobjseq_oomulscadd (c, a, s, v, b, w, an, args.sargs);
	  c += an * bigintobj_size (args.sargs);
	  b += an * bigintobj_size (args.sargs);
	  bigintobjseq_oonegv (c, b, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  bigintobjseq_oomulscadd (c, a, s, v, b, w, bn, args.sargs);
	  c += bn * bigintobj_size (args.sargs);
	  a += bn * bigintobj_size (args.sargs);
	  bigintobjseq_oomulscv (c, a, s, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static int 
bigintobj_vardnsrecdegdnspolseq_inmulscadd (bigintobj_vardnsrecdegdnspolseq_t a, int an, bigintobj_t s, int v, bigintobj_vardnsrecdegdnspolseq_t b, int bn, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      bigintobjseq_inmulscadd (a, s, v, b, w, an, args.sargs);
      return bigintobj_vardnsrecdegdnspolseq_removezeroes (a, an, args);
    }
  else
    {
      if (an < bn)
	{
	  bigintobjseq_inmulscadd (a, s, v, b, w, an, args.sargs);
	  a += an * bigintobj_size (args.sargs);
	  b += an * bigintobj_size (args.sargs);
	  bigintobjseq_oonegv (a, b, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  bigintobjseq_inmulscadd (a, s, v, b, w, bn, args.sargs);
	  a += bn * bigintobj_size (args.sargs);
	  bigintobjseq_inmulscv (a, s, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static int 
bigintobj_vardnsrecdegdnspolseq_oomulscaddmulsc (bigintobj_vardnsrecdegdnspolseq_t c, bigintobj_vardnsrecdegdnspolseq_t a, int an, bigintobj_t s, int v, bigintobj_vardnsrecdegdnspolseq_t b, int bn, bigintobj_t t, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      bigintobjseq_oomulscaddmulsc (c, a, s, v, b, t, w, an, args.sargs);
      return bigintobj_vardnsrecdegdnspolseq_removezeroes (c, an, args);
    }
  else
    {
      if (an < bn)
	{
	  bigintobjseq_oomulscaddmulsc (c, a, s, v, b, t, w, an, args.sargs);
	  c += an * bigintobj_size (args.sargs);
	  b += an * bigintobj_size (args.sargs);
	  bigintobjseq_oomulscv (c, b, t, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  bigintobjseq_oomulscaddmulsc (c, a, s, v, b, t, w, bn, args.sargs);
	  c += bn * bigintobj_size (args.sargs);
	  a += bn * bigintobj_size (args.sargs);
	  bigintobjseq_oomulscv (c, a, s, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static int 
bigintobj_vardnsrecdegdnspolseq_inmulscaddmulsc (bigintobj_vardnsrecdegdnspolseq_t a, int an, bigintobj_t s, int v, bigintobj_vardnsrecdegdnspolseq_t b, int bn, bigintobj_t t, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn)
    {
      bigintobjseq_inmulscaddmulsc (a, s, v, b, t, w, an, args.sargs);
      return bigintobj_vardnsrecdegdnspolseq_removezeroes (a, an, args);
    }
  else
    {
      if (an < bn)
	{
	  bigintobjseq_inmulscaddmulsc (a, s, v, b, t, w, an, args.sargs);
	  a += an * bigintobj_size (args.sargs);
	  b += an * bigintobj_size (args.sargs);
	  bigintobjseq_oomulscv (a, b, t, w, bn - an, args.sargs);
	  return bn;
	}
      else
	{
	  bigintobjseq_inmulscaddmulsc (a, s, v, b, t, w, bn, args.sargs);
	  a += bn * bigintobj_size (args.sargs);
	  bigintobjseq_inmulscv (a, s, v, an - bn, args.sargs);
	  return an;
	}
    }
}

static BOOL 
bigintobj_vardnsrecdegdnspolseq_oodivsc (bigintobj_vardnsrecdegdnspolseq_t c, bigintobj_vardnsrecdegdnspolseq_t a, int n, bigintobj_t s, bigintobj_vardnsrecdegdnspol_args args)
{
  return bigintobjseq_oodivsc (c, a, s, n, args.sargs);
}

static int 
bigintobj_vardnsrecdegdnspolseq_indivsc (bigintobj_vardnsrecdegdnspolseq_t a, int n, bigintobj_t s, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobjseq_indivsc (a, s, n, args.sargs);
  return n;
}

static int 
bigintobj_vardnsrecdegdnspolseq_oomulmonomsc (bigintobj_vardnsrecdegdnspolseq_t c, bigintobj_vardnsrecdegdnspolseq_t a, int n, int m, bigintobj_t s, int v, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobjseq_oozero (c, m, args.sargs);
  c += m * bigintobj_size (args.sargs);
  bigintobjseq_oomulscv (c, a, s, v, n, args.sargs);
  return n + m;
}

static BOOL 
bigintobj_vardnsrecdegdnspolseq_oodivmonomsc (bigintobj_vardnsrecdegdnspolseq_t c, bigintobj_vardnsrecdegdnspolseq_t a, int n, int m, bigintobj_t s, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (n >= m);
  a += m * bigintobj_size (args.sargs);
  return bigintobjseq_oodivsc (c, a, s, n - m, args.sargs);
}

static int 
bigintobj_vardnsrecdegdnspolseq_ooaddmulmonomsc (bigintobj_vardnsrecdegdnspolseq_t c, bigintobj_vardnsrecdegdnspolseq_t a, int an, int v, bigintobj_vardnsrecdegdnspolseq_t b, int bn, int m, bigintobj_t t, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn + m)
    {
      assert (an >= m);
      bigintobjseq_oonegv (c, a, v, m, args.sargs);
      c += m * bigintobj_size (args.sargs);
      a += m * bigintobj_size (args.sargs);
      assert (an >= bn);
      bigintobjseq_ooaddmulsc (c, a, v, b, t, w, bn, args.sargs);
      c -= m * bigintobj_size (args.sargs);
      return bigintobj_vardnsrecdegdnspolseq_removezeroes (c, an, args);
    }
  else
    {
      if (an < bn + m)
	{
	  if (an < m)
	    {
	      bigintobjseq_oonegv (c, a, v, an, args.sargs);
	      c += an * bigintobj_size (args.sargs);
	      a += an * bigintobj_size (args.sargs);
	      bigintobjseq_oozero (c, m - an, args.sargs);
	      c += (m - an) * bigintobj_size (args.sargs);
	      bigintobjseq_oomulscv (c, b, t, w, bn, args.sargs);
	    }
	  else
	    {
	      assert (an >= m);
	      bigintobjseq_oonegv (c, a, v, m, args.sargs);
	      c += m * bigintobj_size (args.sargs);
	      a += m * bigintobj_size (args.sargs);
	      assert (bn > an - m);
	      bigintobjseq_ooaddmulsc (c, a, v, b, t, w, an - m, args.sargs);
	      c += (an - m) * bigintobj_size (args.sargs);
	      b += (an - m) * bigintobj_size (args.sargs);
	      bigintobjseq_oomulscv (c, b, t, w, bn - (an - m), args.sargs);
	    }
	  return bn + m;
	}
      else
	{
	  assert (an >= m);
	  bigintobjseq_oonegv (c, a, v, m, args.sargs);
	  c += m * bigintobj_size (args.sargs);
	  a += m * bigintobj_size (args.sargs);
	  assert (an >= bn);
	  bigintobjseq_ooaddmulsc (c, a, v, b, t, w, bn, args.sargs);
	  c += bn * bigintobj_size (args.sargs);
	  a += bn * bigintobj_size (args.sargs);
	  assert (an > bn + m);
	  bigintobjseq_oonegv (c, a, v, an - bn - m, args.sargs);
	  return an;
	}
    }
}

static int 
bigintobj_vardnsrecdegdnspolseq_inaddmulmonomsc (bigintobj_vardnsrecdegdnspolseq_t a, int an, int v, bigintobj_vardnsrecdegdnspolseq_t b, int bn, int m, bigintobj_t t, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn + m)
    {
      assert (an >= m);
      bigintobjseq_innegv (a, v, m, args.sargs);
      a += m * bigintobj_size (args.sargs);
      assert (an >= bn);
      bigintobjseq_inaddmulsc (a, v, b, t, w, bn, args.sargs);
      a -= m * bigintobj_size (args.sargs);
      return bigintobj_vardnsrecdegdnspolseq_removezeroes (a, an, args);
    }
  else
    {
      if (an < bn + m)
	{
	  if (an < m)
	    {
	      bigintobjseq_innegv (a, v, an, args.sargs);
	      a += an * bigintobj_size (args.sargs);
	      bigintobjseq_oozero (a, m - an, args.sargs);
	      a += (m - an) * bigintobj_size (args.sargs);
	      bigintobjseq_oomulscv (a, b, t, w, bn, args.sargs);
	    }
	  else
	    {
	      assert (an >= m);
	      bigintobjseq_innegv (a, v, m, args.sargs);
	      a += m * bigintobj_size (args.sargs);
	      assert (bn > an - m);
	      bigintobjseq_inaddmulsc (a, v, b, t, w, an - m, args.sargs);
	      a += (an - m) * bigintobj_size (args.sargs);
	      bigintobjseq_oomulscv (a, b, t, w, bn - (an - m), args.sargs);
	    }
	  return bn + m;
	}
      else
	{
	  assert (an >= m);
	  bigintobjseq_innegv (a, v, m, args.sargs);
	  a += m * bigintobj_size (args.sargs);
	  assert (an >= bn);
	  bigintobjseq_inaddmulsc (a, v, b, t, w, bn, args.sargs);
	  a += bn * bigintobj_size (args.sargs);
	  assert (an > bn + m);
	  bigintobjseq_innegv (a, v, an - bn - m, args.sargs);
	  return an;
	}
    }
}

static int 
bigintobj_vardnsrecdegdnspolseq_oomulscaddmulmonomsc (bigintobj_vardnsrecdegdnspolseq_t c, bigintobj_vardnsrecdegdnspolseq_t a, int an, bigintobj_t s, int v, bigintobj_vardnsrecdegdnspolseq_t b, int bn, int m, bigintobj_t t, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn + m)
    {
      assert (an >= m);
      bigintobjseq_oomulscv (c, a, s, v, m, args.sargs);
      c += m * bigintobj_size (args.sargs);
      a += m * bigintobj_size (args.sargs);
      assert (an >= bn);
      bigintobjseq_oomulscaddmulsc (c, a, s, v, b, t, w, bn, args.sargs);
      c -= m * bigintobj_size (args.sargs);
      return bigintobj_vardnsrecdegdnspolseq_removezeroes (c, an, args);
    }
  else
    {
      if (an < bn + m)
	{
	  if (an < m)
	    {
	      bigintobjseq_oomulscv (c, a, s, v, an, args.sargs);
	      c += an * bigintobj_size (args.sargs);
	      a += an * bigintobj_size (args.sargs);
	      bigintobjseq_oozero (c, m - an, args.sargs);
	      c += (m - an) * bigintobj_size (args.sargs);
	      bigintobjseq_oomulscv (c, b, t, w, bn, args.sargs);
	    }
	  else
	    {
	      assert (an >= m);
	      bigintobjseq_oomulscv (c, a, s, v, m, args.sargs);
	      c += m * bigintobj_size (args.sargs);
	      a += m * bigintobj_size (args.sargs);
	      assert (bn > an - m);
	      bigintobjseq_oomulscaddmulsc (c, a, s, v, b, t, w, an - m, args.sargs);
	      c += (an - m) * bigintobj_size (args.sargs);
	      a += (an - m) * bigintobj_size (args.sargs);
	      b += (an - m) * bigintobj_size (args.sargs);
	      bigintobjseq_oomulscv (c, b, t, w, bn - (an - m), args.sargs);
	    }
	  return bn + m;
	}
      else
	{
	  assert (an >= m);
	  bigintobjseq_oomulscv (c, a, s, v, m, args.sargs);
	  c += m * bigintobj_size (args.sargs);
	  a += m * bigintobj_size (args.sargs);
	  assert (an >= bn);
	  bigintobjseq_oomulscaddmulsc (c, a, s, v, b, t, w, bn, args.sargs);
	  c += bn * bigintobj_size (args.sargs);
	  a += bn * bigintobj_size (args.sargs);
	  assert (an > bn + m);
	  bigintobjseq_oomulscv (c, a, s, v, an - bn - m, args.sargs);
	  return an;
	}
    }
}

static int 
bigintobj_vardnsrecdegdnspolseq_inmulscaddmulmonomsc (bigintobj_vardnsrecdegdnspolseq_t a, int an, bigintobj_t s, int v, bigintobj_vardnsrecdegdnspolseq_t b, int bn, int m, bigintobj_t t, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (v * v == 1 && w * w == 1);

  if (an == bn + m)
    {
      assert (an >= m);
      bigintobjseq_inmulscv (a, s, v, m, args.sargs);
      a += m * bigintobj_size (args.sargs);
      assert (an >= bn);
      bigintobjseq_inmulscaddmulsc (a, s, v, b, t, w, bn, args.sargs);
      a -= m * bigintobj_size (args.sargs);
      return bigintobj_vardnsrecdegdnspolseq_removezeroes (a, an, args);
    }
  else
    {
      if (an < bn + m)
	{
	  if (an < m)
	    {
	      bigintobjseq_inmulscv (a, s, v, an, args.sargs);
	      a += an * bigintobj_size (args.sargs);
	      bigintobjseq_oozero (a, m - an, args.sargs);
	      a += m * bigintobj_size (args.sargs);
	      bigintobjseq_oomulscv (a, b, t, w, bn, args.sargs);
	    }
	  else
	    {
	      assert (an >= m);
	      bigintobjseq_inmulscv (a, s, v, m, args.sargs);
	      a += m * bigintobj_size (args.sargs);
	      assert (bn > an - m);
	      bigintobjseq_inmulscaddmulsc (a, s, v, b, t, w, an - m, args.sargs);
	      a += (an - m) * bigintobj_size (args.sargs);
	      bigintobjseq_oomulscv (a, b, t, w, bn - (an - m), args.sargs);
	    }
	  return bn + m;
	}
      else
	{
	  assert (an >= m);
	  bigintobjseq_inmulscv (a, s, v, m, args.sargs);
	  a += m * bigintobj_size (args.sargs);
	  assert (an >= bn);
	  bigintobjseq_inmulscaddmulsc (a, s, v, b, t, w, bn, args.sargs);
	  a += bn * bigintobj_size (args.sargs);
	  assert (an > bn + m);
	  bigintobjseq_inmulscv (a, s, v, an - bn - m, args.sargs);
	  return an;
	}
    }
}

static void 
bigintobj_vardnsrecdegdnspol_ix_init (bigintobj_vardnsrecdegdnspol_ixt ix, id self)
{
  bigintobj_vardnsrecdegdnspol_t v = [self bigintobj_vardnsrecdegdnspol_value];
  ix->i = -1;
  ix->n = v->n;
}

static void 
bigintobj_vardnsrecdegdnspol_ix_clear (bigintobj_vardnsrecdegdnspol_ixt ix)
{
  /* nothing to clear */
}

static int 
bigintobj_vardnsrecdegdnspol_ix_count (bigintobj_vardnsrecdegdnspol_ixt ix)
{
  return ix->n;			/* total number, zero or nonzero */
}

static int 
bigintobj_vardnsrecdegdnspol_ix_isempty (bigintobj_vardnsrecdegdnspol_ixt ix)
{
  return ix->n == 0;
}

static int 
bigintobj_vardnsrecdegdnspol_ix_ismatch (bigintobj_vardnsrecdegdnspol_ixt ix)
{
  assert (-1 <= ix->i && ix->i <= ix->n);
  return (ix->i != -1 && ix->i != ix->n);
}

static void 
bigintobj_vardnsrecdegdnspol_ix_tofirst (bigintobj_vardnsrecdegdnspol_ixt ix)
{
  ix->i = -1;			/* next = first */
}

static void 
bigintobj_vardnsrecdegdnspol_ix_tolast (bigintobj_vardnsrecdegdnspol_ixt ix)
{
  ix->i = ix->n;		/* prev = last */
}

static void 
bigintobj_vardnsrecdegdnspol_ix_to (bigintobj_vardnsrecdegdnspol_ixt ix, int i)
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
bigintobj_vardnsrecdegdnspol_ix_next (bigintobj_vardnsrecdegdnspol_ixt ix)
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
bigintobj_vardnsrecdegdnspol_ix_prev (bigintobj_vardnsrecdegdnspol_ixt ix)
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
bigintobj_vardnsrecdegdnspol_check (bigintobj_vardnsrecdegdnspol_t self, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (self->n <= self->c);
  return bigintobj_vardnsrecdegdnspolseq_check (self->ptr, self->n, args);
}

static bigintobj_vardnsrecdegdnspol_args 
bigintobj_vardnsrecdegdnspol_getargs (id self)
{
  bigintobj_vardnsrecdegdnspol_args res;
  res.sargs = bigintobj_getargs ([[self termZero] coefficient]);
  return res;
}

static bigintobj_vardnsrecdegdnspol_t 
bigintobj_vardnsrecdegdnspol_id2t (id object)
{
  return [object bigintobj_vardnsrecdegdnspol_value];
}

static bigintobj_vardnsrecdegdnspol_c *
bigintobj_vardnsrecdegdnspol_id2c (id object)
{
  return [object bigintobj_vardnsrecdegdnspol_reference];
}

static id 
bigintobj_vardnsrecdegdnspol_t2id (id proto, bigintobj_vardnsrecdegdnspol_t f)
{
  return [proto bigintobj_vardnsrecdegdnspol_value:f];
}

static id 
bigintobj_vardnsrecdegdnspol_c2id (id proto, bigintobj_vardnsrecdegdnspol_c * r)
{
  return [proto bigintobj_vardnsrecdegdnspol_reference:r];
}

static int 
bigintobj_vardnsrecdegdnspol_isempty (bigintobj_vardnsrecdegdnspol_t self)
{
  return self->n == 0;
}

static void 
bigintobj_vardnsrecdegdnspol_init (bigintobj_vardnsrecdegdnspol_t self, int c, bigintobj_vardnsrecdegdnspol_args args)
{
  self->n = 0;
  self->c = c;
  self->ptr = bigintobjseq_alloc (c, args.sargs);
  assert (bigintobj_vardnsrecdegdnspol_check (self, args));
}

static void 
bigintobj_vardnsrecdegdnspol_copy (bigintobj_vardnsrecdegdnspol_t c, bigintobj_vardnsrecdegdnspol_t a, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (bigintobj_vardnsrecdegdnspol_check (a, args));
  bigintobj_vardnsrecdegdnspol_init (c, a->n, args);
  c->n = bigintobj_vardnsrecdegdnspolseq_copy (c->ptr, a->ptr, a->n, args);
  assert (bigintobj_vardnsrecdegdnspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegdnspol_deepcopy (bigintobj_vardnsrecdegdnspol_t c, bigintobj_vardnsrecdegdnspol_t a, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (bigintobj_vardnsrecdegdnspol_check (a, args));
  bigintobj_vardnsrecdegdnspol_init (c, a->n, args);
  c->n = bigintobj_vardnsrecdegdnspolseq_deepcopy (c->ptr, a->ptr, a->n, args);
  assert (bigintobj_vardnsrecdegdnspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegdnspol_move (bigintobj_vardnsrecdegdnspol_t c, bigintobj_vardnsrecdegdnspol_t a, bigintobj_vardnsrecdegdnspol_args args)
{
  c->ptr = a->ptr;
  c->n = a->n;
  c->c = a->c;
  a->ptr = NULL;
  assert (bigintobj_vardnsrecdegdnspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegdnspol_destroy (bigintobj_vardnsrecdegdnspol_t self, bigintobj_vardnsrecdegdnspol_args args)
{
  /* needed e.g. after a failed oodiv operation */
  self->ptr = bigintobjseq_free (self->ptr, args.sargs);
}

static void 
bigintobj_vardnsrecdegdnspol_clear (bigintobj_vardnsrecdegdnspol_t self, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobjseq_clear (self->ptr, self->n, args.sargs);
  bigintobj_vardnsrecdegdnspol_destroy (self, args);
}

static int 
bigintobj_vardnsrecdegdnspol_count (bigintobj_vardnsrecdegdnspol_t self, bigintobj_vardnsrecdegdnspol_args args)
{
  return bigintobj_vardnsrecdegdnspolseq_count (self->ptr, self->n, args);	/* num non-zero coefs */
}

static unsigned 
bigintobj_vardnsrecdegdnspol_hash (bigintobj_vardnsrecdegdnspol_t a, bigintobj_vardnsrecdegdnspol_args args)
{
  return bigintobj_vardnsrecdegdnspolseq_hash (a->ptr, a->n, args);
}

static int 
bigintobj_vardnsrecdegdnspol_iseq (bigintobj_vardnsrecdegdnspol_t a, bigintobj_vardnsrecdegdnspol_t b, bigintobj_vardnsrecdegdnspol_args args)
{
  return (a == b) ? YES : bigintobj_vardnsrecdegdnspolseq_iseq (a->ptr, a->n, b->ptr, b->n, args);
}

static int 
bigintobj_vardnsrecdegdnspol_isone (bigintobj_vardnsrecdegdnspol_t self, bigintobj_vardnsrecdegdnspol_args args)
{
  return bigintobj_vardnsrecdegdnspolseq_isone (self->ptr, self->n, args);
}

static int 
bigintobj_vardnsrecdegdnspol_isminusone (bigintobj_vardnsrecdegdnspol_t self, bigintobj_vardnsrecdegdnspol_args args)
{
  return bigintobj_vardnsrecdegdnspolseq_isminusone (self->ptr, self->n, args);
}

static int 
bigintobj_vardnsrecdegdnspol_deg (bigintobj_vardnsrecdegdnspol_t self, bigintobj_vardnsrecdegdnspol_args args)
{
  return self->n - 1;
}

static int 
bigintobj_vardnsrecdegdnspol_ord (bigintobj_vardnsrecdegdnspol_t self, bigintobj_vardnsrecdegdnspol_args args)
{
  return bigintobj_vardnsrecdegdnspolseq_ord (self->ptr, self->n, args);
}

static int 
bigintobj_vardnsrecdegdnspol_maxdeg (bigintobj_vardnsrecdegdnspol_t self, bigintobj_vardnsrecdegdnspol_args args)
{
  return self->n - 1;
}

static int 
bigintobj_vardnsrecdegdnspol_mindeg (bigintobj_vardnsrecdegdnspol_t self, bigintobj_vardnsrecdegdnspol_args args)
{
  return bigintobj_vardnsrecdegdnspolseq_ord (self->ptr, self->n, args);
}

static bigintobj_t 
bigintobj_vardnsrecdegdnspol_scalat (bigintobj_vardnsrecdegdnspol_t self, bigintobj_vardnsrecdegdnspol_ixt ix, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (bigintobj_vardnsrecdegdnspol_ix_ismatch (ix) && ix->n == self->n);
  return bigintobjseq_at (self->ptr, ix->n - ix->i - 1, args.sargs);
}

static int 
bigintobj_vardnsrecdegdnspol_expat (bigintobj_vardnsrecdegdnspol_t self, bigintobj_vardnsrecdegdnspol_ixt ix, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (bigintobj_vardnsrecdegdnspol_ix_ismatch (ix) && ix->n == self->n);
  return ix->n - ix->i - 1;
}

static bigintobj_t 
bigintobj_vardnsrecdegdnspol_scalfirst (bigintobj_vardnsrecdegdnspol_t self, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (bigintobj_vardnsrecdegdnspol_isempty (self) == NO);
  return bigintobjseq_last (self->ptr, self->n, args.sargs);
}

static int 
bigintobj_vardnsrecdegdnspol_expfirst (bigintobj_vardnsrecdegdnspol_t self, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (bigintobj_vardnsrecdegdnspol_isempty (self) == NO);
  return self->n - 1;
}

static void 
bigintobj_vardnsrecdegdnspol_expand (bigintobj_vardnsrecdegdnspol_t self, bigintobj_vardnsrecdegdnspol_args args)
{
  int oldc = self->c;
  self->c = self->n + self->c + 1;
  self->ptr = bigintobjseq_realloc (self->ptr, oldc, self->c, args.sargs);
  assert (self->n < self->c);
}

static void 
bigintobj_vardnsrecdegdnspol_remove (bigintobj_vardnsrecdegdnspol_t self, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (bigintobj_vardnsrecdegdnspol_check (self, args) && bigintobj_vardnsrecdegdnspol_isempty (self) == NO);
  self->n = bigintobj_vardnsrecdegdnspolseq_delete (self->ptr, self->n, args);
  assert (bigintobj_vardnsrecdegdnspol_check (self, args));
}

static void 
bigintobj_vardnsrecdegdnspol_insert (bigintobj_vardnsrecdegdnspol_t self, int e, bigintobj_t s, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (bigintobj_vardnsrecdegdnspol_check (self, args));
  while (self->c < e + 1)
    bigintobj_vardnsrecdegdnspol_expand (self, args);
  self->n = bigintobj_vardnsrecdegdnspolseq_insert (self->ptr, self->n, e, s, args);
  assert (bigintobj_vardnsrecdegdnspol_check (self, args));
}

static int 
bigintobj_vardnsrecdegdnspol_iszero (bigintobj_vardnsrecdegdnspol_t self, bigintobj_vardnsrecdegdnspol_args args)
{
  return bigintobj_vardnsrecdegdnspol_isempty (self);
}

static int 
bigintobj_vardnsrecdegdnspol_isop (bigintobj_vardnsrecdegdnspol_t a, bigintobj_vardnsrecdegdnspol_t b, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (a != b);
  return bigintobj_vardnsrecdegdnspolseq_isop (a->ptr, a->n, b->ptr, b->n, args);
}

static void 
bigintobj_vardnsrecdegdnspol_ooneg (bigintobj_vardnsrecdegdnspol_t c, bigintobj_vardnsrecdegdnspol_t a, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobj_vardnsrecdegdnspol_init (c, a->n, args);
  c->n = bigintobj_vardnsrecdegdnspolseq_ooneg (c->ptr, a->ptr, a->n, args);
  assert (bigintobj_vardnsrecdegdnspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegdnspol_inneg (bigintobj_vardnsrecdegdnspol_t a, bigintobj_vardnsrecdegdnspol_args args)
{
  a->n = bigintobj_vardnsrecdegdnspolseq_inneg (a->ptr, a->n, args);
  assert (bigintobj_vardnsrecdegdnspol_check (a, args));
}

static void 
bigintobj_vardnsrecdegdnspol_oodbl (bigintobj_vardnsrecdegdnspol_t c, bigintobj_vardnsrecdegdnspol_t a, int v, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobj_vardnsrecdegdnspol_init (c, a->n, args);
  c->n = bigintobj_vardnsrecdegdnspolseq_oodbl (c->ptr, a->ptr, a->n, v, args);
  assert (bigintobj_vardnsrecdegdnspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegdnspol_indbl (bigintobj_vardnsrecdegdnspol_t a, int v, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobj_vardnsrecdegdnspolseq_indbl (a->ptr, a->n, v, args);
  assert (bigintobj_vardnsrecdegdnspol_check (a, args));
}

static void 
bigintobj_vardnsrecdegdnspol_ooadd (bigintobj_vardnsrecdegdnspol_t c, bigintobj_vardnsrecdegdnspol_t a, int v, bigintobj_vardnsrecdegdnspol_t b, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (a != b);
  bigintobj_vardnsrecdegdnspol_init (c, MAX (a->n, b->n), args);
  c->n = bigintobj_vardnsrecdegdnspolseq_ooadd (c->ptr, a->ptr, a->n, v, b->ptr, b->n, w, args);
  assert (bigintobj_vardnsrecdegdnspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegdnspol_inadd (bigintobj_vardnsrecdegdnspol_t a, int v, bigintobj_vardnsrecdegdnspol_t b, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  assert (a != b);
  while (a->c < b->n)
    bigintobj_vardnsrecdegdnspol_expand (a, args);
  a->n = bigintobj_vardnsrecdegdnspolseq_inadd (a->ptr, a->n, v, b->ptr, b->n, w, args);
  assert (bigintobj_vardnsrecdegdnspol_check (a, args));
}

static void 
bigintobj_vardnsrecdegdnspol_oomulsc (bigintobj_vardnsrecdegdnspol_t c, bigintobj_vardnsrecdegdnspol_t a, bigintobj_t s, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobj_vardnsrecdegdnspol_init (c, a->n, args);
  c->n = bigintobj_vardnsrecdegdnspolseq_oomulsc (c->ptr, a->ptr, a->n, s, args);
  assert (bigintobj_vardnsrecdegdnspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegdnspol_inmulsc (bigintobj_vardnsrecdegdnspol_t a, bigintobj_t s, bigintobj_vardnsrecdegdnspol_args args)
{
  a->n = bigintobj_vardnsrecdegdnspolseq_inmulsc (a->ptr, a->n, s, args);
  assert (bigintobj_vardnsrecdegdnspol_check (a, args));
}

static void 
bigintobj_vardnsrecdegdnspol_ooaddmulsc (bigintobj_vardnsrecdegdnspol_t c, bigintobj_vardnsrecdegdnspol_t a, int v, bigintobj_vardnsrecdegdnspol_t b, bigintobj_t t, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobj_vardnsrecdegdnspol_init (c, MAX (a->n, b->n), args);
  c->n = bigintobj_vardnsrecdegdnspolseq_ooaddmulsc (c->ptr, a->ptr, a->n, v, b->ptr, b->n, t, w, args);
  assert (bigintobj_vardnsrecdegdnspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegdnspol_inaddmulsc (bigintobj_vardnsrecdegdnspol_t a, int v, bigintobj_vardnsrecdegdnspol_t b, bigintobj_t t, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  while (a->c < b->n)
    bigintobj_vardnsrecdegdnspol_expand (a, args);
  a->n = bigintobj_vardnsrecdegdnspolseq_inaddmulsc (a->ptr, a->n, v, b->ptr, b->n, t, w, args);
  assert (bigintobj_vardnsrecdegdnspol_check (a, args));
}

static void 
bigintobj_vardnsrecdegdnspol_oomulscadd (bigintobj_vardnsrecdegdnspol_t c, bigintobj_vardnsrecdegdnspol_t a, bigintobj_t s, int v, bigintobj_vardnsrecdegdnspol_t b, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobj_vardnsrecdegdnspol_init (c, MAX (a->n, b->n), args);
  c->n = bigintobj_vardnsrecdegdnspolseq_oomulscadd (c->ptr, a->ptr, a->n, s, v, b->ptr, b->n, w, args);
  assert (bigintobj_vardnsrecdegdnspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegdnspol_inmulscadd (bigintobj_vardnsrecdegdnspol_t a, bigintobj_t s, int v, bigintobj_vardnsrecdegdnspol_t b, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  while (a->c < b->n)
    bigintobj_vardnsrecdegdnspol_expand (a, args);
  a->n = bigintobj_vardnsrecdegdnspolseq_inmulscadd (a->ptr, a->n, s, v, b->ptr, b->n, w, args);
  assert (bigintobj_vardnsrecdegdnspol_check (a, args));
}

static void 
bigintobj_vardnsrecdegdnspol_oomulscaddmulsc (bigintobj_vardnsrecdegdnspol_t c, bigintobj_vardnsrecdegdnspol_t a, bigintobj_t s, int v, bigintobj_vardnsrecdegdnspol_t b, bigintobj_t t, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobj_vardnsrecdegdnspol_init (c, MAX (a->n, b->n), args);
  c->n = bigintobj_vardnsrecdegdnspolseq_oomulscaddmulsc (c->ptr, a->ptr, a->n, s, v, b->ptr, b->n, t, w, args);
  assert (bigintobj_vardnsrecdegdnspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegdnspol_inmulscaddmulsc (bigintobj_vardnsrecdegdnspol_t a, bigintobj_t s, int v, bigintobj_vardnsrecdegdnspol_t b, bigintobj_t t, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  while (a->c < b->n)
    bigintobj_vardnsrecdegdnspol_expand (a, args);
  a->n = bigintobj_vardnsrecdegdnspolseq_inmulscaddmulsc (a->ptr, a->n, s, v, b->ptr, b->n, t, w, args);
  assert (bigintobj_vardnsrecdegdnspol_check (a, args));
}

static BOOL 
bigintobj_vardnsrecdegdnspol_oodivsc (bigintobj_vardnsrecdegdnspol_t c, bigintobj_vardnsrecdegdnspol_t a, bigintobj_t s, bigintobj_vardnsrecdegdnspol_args args)
{
  BOOL failed;
  bigintobj_vardnsrecdegdnspol_init (c, a->n, args);
  failed = bigintobj_vardnsrecdegdnspolseq_oodivsc (c->ptr, a->ptr, a->n, s, args);
  if (failed)
    {
      /* the actual scalars are already freed */
      bigintobj_vardnsrecdegdnspol_destroy (c, args);
    }
  else
    {
      c->n = a->n;
      assert (bigintobj_vardnsrecdegdnspol_check (c, args));
    }
  return failed;
}

static void 
bigintobj_vardnsrecdegdnspol_indivsc (bigintobj_vardnsrecdegdnspol_t a, bigintobj_t s, bigintobj_vardnsrecdegdnspol_args args)
{
  a->n = bigintobj_vardnsrecdegdnspolseq_indivsc (a->ptr, a->n, s, args);
  assert (bigintobj_vardnsrecdegdnspol_check (a, args));
}

static void 
bigintobj_vardnsrecdegdnspol_oomulmonomsc (bigintobj_vardnsrecdegdnspol_t c, bigintobj_vardnsrecdegdnspol_t b, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobj_vardnsrecdegdnspol_init (c, b->n + m, args);
  c->n = bigintobj_vardnsrecdegdnspolseq_oomulmonomsc (c->ptr, b->ptr, b->n, m, t, w, args);
  assert (bigintobj_vardnsrecdegdnspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegdnspol_inmulmonomsc (bigintobj_vardnsrecdegdnspol_t b, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobj_vardnsrecdegdnspol_c tmp;
  bigintobj_vardnsrecdegdnspol_oomulmonomsc (&tmp, b, m, t, w, args);
  bigintobj_vardnsrecdegdnspol_clear (b, args);
  bigintobj_vardnsrecdegdnspol_move (b, &tmp, args);
}

static void 
bigintobj_vardnsrecdegdnspol_ooaddmulmonomsc (bigintobj_vardnsrecdegdnspol_t c, bigintobj_vardnsrecdegdnspol_t a, int v, bigintobj_vardnsrecdegdnspol_t b, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobj_vardnsrecdegdnspol_init (c, MAX (a->n, b->n + m), args);
  c->n = bigintobj_vardnsrecdegdnspolseq_ooaddmulmonomsc (c->ptr, a->ptr, a->n, v, b->ptr, b->n, m, t, w, args);
  assert (bigintobj_vardnsrecdegdnspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegdnspol_inaddmulmonomsc (bigintobj_vardnsrecdegdnspol_t a, int v, bigintobj_vardnsrecdegdnspol_t b, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  while (a->c < b->n + m)
    bigintobj_vardnsrecdegdnspol_expand (a, args);
  a->n = bigintobj_vardnsrecdegdnspolseq_inaddmulmonomsc (a->ptr, a->n, v, b->ptr, b->n, m, t, w, args);
  assert (bigintobj_vardnsrecdegdnspol_check (a, args));
}

static void 
bigintobj_vardnsrecdegdnspol_oomulscaddmulmonomsc (bigintobj_vardnsrecdegdnspol_t c, bigintobj_vardnsrecdegdnspol_t a, bigintobj_t s, int v, bigintobj_vardnsrecdegdnspol_t b, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobj_vardnsrecdegdnspol_init (c, MAX (a->n, b->n + m), args);
  c->n = bigintobj_vardnsrecdegdnspolseq_oomulscaddmulmonomsc (c->ptr, a->ptr, a->n, s, v, b->ptr, b->n, m, t, w, args);
  assert (bigintobj_vardnsrecdegdnspol_check (c, args));
}

static void 
bigintobj_vardnsrecdegdnspol_inmulscaddmulmonomsc (bigintobj_vardnsrecdegdnspol_t a, bigintobj_t s, int v, bigintobj_vardnsrecdegdnspol_t b, unimonom_t m, bigintobj_t t, int w, bigintobj_vardnsrecdegdnspol_args args)
{
  a->n = bigintobj_vardnsrecdegdnspolseq_inmulscaddmulmonomsc (a->ptr, a->n, s, v, b->ptr, b->n, m, t, w, args);
  assert (bigintobj_vardnsrecdegdnspol_check (a, args));
}

static BOOL 
bigintobj_vardnsrecdegdnspol_oodivmonomsc (bigintobj_vardnsrecdegdnspol_t c, bigintobj_vardnsrecdegdnspol_t b, unimonom_t m, bigintobj_t t, bigintobj_vardnsrecdegdnspol_args args)
{
  if (bigintobj_vardnsrecdegdnspol_ord (b, args) < m)
    {
      return FAILURE;
    }
  else
    {
      BOOL failed;
      bigintobj_vardnsrecdegdnspol_init (c, b->n - m, args);
      failed = bigintobj_vardnsrecdegdnspolseq_oodivmonomsc (c->ptr, b->ptr, b->n, m, t, args);
      if (failed)
	{
	  /* the actual scalars are already freed */
	  bigintobj_vardnsrecdegdnspol_destroy (c, args);
	}
      else
	{
	  c->n = b->n - m;
	  assert (bigintobj_vardnsrecdegdnspol_check (c, args));
	}
      return failed;
    }
}

static void 
bigintobj_vardnsrecdegdnspol_indivmonomsc (bigintobj_vardnsrecdegdnspol_t b, unimonom_t m, bigintobj_t t, bigintobj_vardnsrecdegdnspol_args args)
{
  bigintobj_vardnsrecdegdnspol_c tmp;
  BOOL failed = bigintobj_vardnsrecdegdnspol_oodivmonomsc (&tmp, b, m, t, args);
  if (failed)
    {
      fprintf (stderr, "Exact Division Failed");
      abort ();
    }
  bigintobj_vardnsrecdegdnspol_clear (b, args);
  bigintobj_vardnsrecdegdnspol_move (b, &tmp, args);
}

static void 
bigintobj_vardnsrecdegdnspol_args_fileOut (id aFiler, bigintobj_vardnsrecdegdnspol_args * args)
{
  bigintobjseq_args_fileOut (aFiler, &args->sargs);
}
static void 
bigintobj_vardnsrecdegdnspol_args_fileIn (id aFiler, bigintobj_vardnsrecdegdnspol_args * args)
{
  bigintobjseq_args_fileIn (aFiler, &args->sargs);
}

static void 
bigintobj_vardnsrecdegdnspol_fileOut (id aFiler, bigintobj_vardnsrecdegdnspol_t self, bigintobj_vardnsrecdegdnspol_args args)
{
  int n = self->n;
  [aFiler fileOut:&n type:'i'];
  assert (bigintobj_vardnsrecdegdnspol_check (self, args));
  bigintobjseq_fileOut (aFiler, self->ptr, n, args.sargs);
}

static void 
bigintobj_vardnsrecdegdnspol_fileIn (id aFiler, bigintobj_vardnsrecdegdnspol_t self, bigintobj_vardnsrecdegdnspol_args args)
{
  int n;
  [aFiler fileIn:&n type:'i'];
  bigintobj_vardnsrecdegdnspol_init (self, n, args);
  bigintobjseq_fileIn (aFiler, self->ptr, n, args.sargs);
  self->n = n;
  assert (self->n == n && bigintobj_vardnsrecdegdnspol_check (self, args));
}

@implementation bigintobj_vardnsrecdegdns_polynomial : vardnsrecdegdns_polynomial

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

  bigintobj_vardnsrecdegdnspol_init (&value, 2 /* capacity */ , bigintobj_vardnsrecdegdnspol_getargs (self));
  assert ([self check]);
  return self;
}

+ scalarZero:aScalar coefficientZero:aCoef symbols:aCltn
{
  return [[super new] _setUpScalarZero:aScalar coefficientZero:aCoef symbols:aCltn];
}

- empty
{
  bigintobj_vardnsrecdegdnspol_c c;
  assert ([self check]);
  bigintobj_vardnsrecdegdnspol_init (&c, 2 /* capacity */ , bigintobj_vardnsrecdegdnspol_getargs (self));
  return bigintobj_vardnsrecdegdnspol_c2id (self, &c);
}

- (int) numTerms
{
  /* doesn't take getargs in degsps case */
  assert ([self check]);
  return bigintobj_vardnsrecdegdnspol_count (&value, bigintobj_vardnsrecdegdnspol_getargs (self));
}

- (bigintobj_vardnsrecdegdnspol_t)bigintobj_vardnsrecdegdnspol_value
{
  return &value;
}

- dobigintobj_vardnsrecdegdnspol_value:(bigintobj_vardnsrecdegdnspol_t)aValue
{
  bigintobj_vardnsrecdegdnspol_copy (&value, aValue, bigintobj_vardnsrecdegdnspol_getargs (self));
  assert ([self check]);
  return self;
}

- bigintobj_vardnsrecdegdnspol_value:(bigintobj_vardnsrecdegdnspol_t)aValue
{
  return [[self clone] dobigintobj_vardnsrecdegdnspol_value:aValue];
}

- (bigintobj_vardnsrecdegdnspol_t)bigintobj_vardnsrecdegdnspol_reference
{
  return &value;
}

- dobigintobj_vardnsrecdegdnspol_reference:(bigintobj_vardnsrecdegdnspol_c *)aReference
{
  bigintobj_vardnsrecdegdnspol_move (&value, aReference, bigintobj_vardnsrecdegdnspol_getargs (self));
  assert ([self check]);
  return self;
}

- bigintobj_vardnsrecdegdnspol_reference:(bigintobj_vardnsrecdegdnspol_c *)aReference
{
  return [[self clone] dobigintobj_vardnsrecdegdnspol_reference:aReference];
}

- copy
{
  bigintobj_vardnsrecdegdnspol_c c;
  assert ([self check]);
  bigintobj_vardnsrecdegdnspol_copy (&c, &value, bigintobj_vardnsrecdegdnspol_getargs (self));
  return bigintobj_vardnsrecdegdnspol_c2id (self, &c);
}

- deepCopy
{
  bigintobj_vardnsrecdegdnspol_c c;
  assert ([self check]);
  bigintobj_vardnsrecdegdnspol_deepcopy (&c, &value, bigintobj_vardnsrecdegdnspol_getargs (self));
  return bigintobj_vardnsrecdegdnspol_c2id (self, &c);
}

- (BOOL) isEmpty
{
  return bigintobj_vardnsrecdegdnspol_isempty (&value);
}

- (BOOL) isOne
{
  return bigintobj_vardnsrecdegdnspol_isone (&value, bigintobj_vardnsrecdegdnspol_getargs (self));
}

- (BOOL) isMinusOne
{
  return bigintobj_vardnsrecdegdnspol_isminusone (&value, bigintobj_vardnsrecdegdnspol_getargs (self));
}

- (unsigned) hash
{
  return bigintobj_vardnsrecdegdnspol_hash (bigintobj_vardnsrecdegdnspol_id2t (self), bigintobj_vardnsrecdegdnspol_getargs (self));
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
      return bigintobj_vardnsrecdegdnspol_iseq (bigintobj_vardnsrecdegdnspol_id2t (self), bigintobj_vardnsrecdegdnspol_id2t (b), bigintobj_vardnsrecdegdnspol_getargs (self));
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
      return !bigintobj_vardnsrecdegdnspol_iseq (bigintobj_vardnsrecdegdnspol_id2t (self), bigintobj_vardnsrecdegdnspol_id2t (b), bigintobj_vardnsrecdegdnspol_getargs (self));
    }
}

- (BOOL) isZero
{
  assert ([self check]);
  return bigintobj_vardnsrecdegdnspol_iszero (bigintobj_vardnsrecdegdnspol_id2t (self), bigintobj_vardnsrecdegdnspol_getargs (self));
}

- (BOOL) notZero
{
  assert ([self check]);
  return !bigintobj_vardnsrecdegdnspol_iszero (bigintobj_vardnsrecdegdnspol_id2t (self), bigintobj_vardnsrecdegdnspol_getargs (self));
}

- (BOOL) isOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return bigintobj_vardnsrecdegdnspol_isop (bigintobj_vardnsrecdegdnspol_id2t (self), bigintobj_vardnsrecdegdnspol_id2t (b), bigintobj_vardnsrecdegdnspol_getargs (self));
}

- (BOOL) notOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return !bigintobj_vardnsrecdegdnspol_isop (bigintobj_vardnsrecdegdnspol_id2t (self), bigintobj_vardnsrecdegdnspol_id2t (b), bigintobj_vardnsrecdegdnspol_getargs (self));
}

- negate
{
  bigintobj_vardnsrecdegdnspol_c c;
  assert ([self check]);
  bigintobj_vardnsrecdegdnspol_ooneg (&c, bigintobj_vardnsrecdegdnspol_id2t (self), bigintobj_vardnsrecdegdnspol_getargs (self));
  return bigintobj_vardnsrecdegdnspol_c2id (self, &c);
}

- _double:(int)v
{
  bigintobj_vardnsrecdegdnspol_c c;
  assert ([self check]);
  bigintobj_vardnsrecdegdnspol_oodbl (&c, bigintobj_vardnsrecdegdnspol_id2t (self), v, bigintobj_vardnsrecdegdnspol_getargs (self));
  return bigintobj_vardnsrecdegdnspol_c2id (self, &c);
}

- double
{
  bigintobj_vardnsrecdegdnspol_c c;
  assert ([self check]);
  bigintobj_vardnsrecdegdnspol_oodbl (&c, bigintobj_vardnsrecdegdnspol_id2t (self), +1, bigintobj_vardnsrecdegdnspol_getargs (self));
  return bigintobj_vardnsrecdegdnspol_c2id (self, &c);
}

- _add:(int)v:b:(int)w
{
  bigintobj_vardnsrecdegdnspol_c c;
  assert ([self sameClass:b] && v * v == 1 && w * w == 1 && self != b);
  bigintobj_vardnsrecdegdnspol_ooadd (&c, bigintobj_vardnsrecdegdnspol_id2t (self), v, bigintobj_vardnsrecdegdnspol_id2t (b), w, bigintobj_vardnsrecdegdnspol_getargs (self));
  return bigintobj_vardnsrecdegdnspol_c2id (self, &c);
}

- add:b
{
  bigintobj_vardnsrecdegdnspol_c c;
  assert ([self checkSameClass:b] && self != b);
  bigintobj_vardnsrecdegdnspol_ooadd (&c, bigintobj_vardnsrecdegdnspol_id2t (self), +1, bigintobj_vardnsrecdegdnspol_id2t (b), +1, bigintobj_vardnsrecdegdnspol_getargs (self));
  return bigintobj_vardnsrecdegdnspol_c2id (self, &c);
}

- subtract:b
{
  bigintobj_vardnsrecdegdnspol_c c;
  assert ([self checkSameClass:b] && self != b);
  bigintobj_vardnsrecdegdnspol_ooadd (&c, bigintobj_vardnsrecdegdnspol_id2t (self), +1, bigintobj_vardnsrecdegdnspol_id2t (b), -1, bigintobj_vardnsrecdegdnspol_getargs (self));
  return bigintobj_vardnsrecdegdnspol_c2id (self, &c);
}

- (int) leadingDegree
{
  return bigintobj_vardnsrecdegdnspol_deg (&value, bigintobj_vardnsrecdegdnspol_getargs (self));
}

- (int) lastDegree
{
  return bigintobj_vardnsrecdegdnspol_ord (&value, bigintobj_vardnsrecdegdnspol_getargs (self));
}

- (int) maxDegree
{
  return bigintobj_vardnsrecdegdnspol_maxdeg (&value, bigintobj_vardnsrecdegdnspol_getargs (self));
}

- (int) minDegree
{
  return bigintobj_vardnsrecdegdnspol_mindeg (&value, bigintobj_vardnsrecdegdnspol_getargs (self));
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

  bigintobj_vardnsrecdegdnspol_check (&value, bigintobj_vardnsrecdegdnspol_getargs (self));
  return self;
}

- release
{
  bigintobj_vardnsrecdegdnspol_clear (&value, bigintobj_vardnsrecdegdnspol_getargs (self));
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
  id aSequence = [bigintobj_vardnsrecdegdnspol_sequence content:self];
  return [CASequence over:aSequence];
}

- elt_bigintobj_vardnsrecdegdnspol_ix:(bigintobj_vardnsrecdegdnspol_ixt)ix
{
  if (bigintobj_vardnsrecdegdnspol_ix_ismatch (ix))
    {
      id c, s;
      int e;
      bigintobj_t t;
      t = bigintobj_vardnsrecdegdnspol_scalat (&value, ix, bigintobj_vardnsrecdegdnspol_getargs (self));
      e = bigintobj_vardnsrecdegdnspol_expat (&value, ix, bigintobj_vardnsrecdegdnspol_getargs (self));
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

      t = bigintobj_vardnsrecdegdnspol_scalfirst (&value, bigintobj_vardnsrecdegdnspol_getargs (self));
      e = bigintobj_vardnsrecdegdnspol_expfirst (&value, bigintobj_vardnsrecdegdnspol_getargs (self));
      c = bigintobj_t2id ([termZero coefficient], t);
      s = (e) ? [termZero symbol] : nil;
      lt = [termZero coefficient:c symbol:s exponent:e];

      bigintobj_vardnsrecdegdnspol_remove (&value, bigintobj_vardnsrecdegdnspol_getargs (self));
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
      bigintobj_vardnsrecdegdnspol_insert (&value, e, r, bigintobj_vardnsrecdegdnspol_getargs (self));
      assert ([aTerm check]);
      [self invalidate];
      assert ([self check]);
      return self;
    }
}

- multiplyCoefficient:s
{
  bigintobj_vardnsrecdegdnspol_c c;
  bigintobj_c sc;
  bigintobj_vardnsrecdegdnspol_oomulsc (&c, bigintobj_vardnsrecdegdnspol_id2t (self), bigintobj_id2ref (s, &sc), bigintobj_vardnsrecdegdnspol_getargs (self));
  return bigintobj_vardnsrecdegdnspol_c2id (self, &c);
}

- divideCoefficient:s
{
  bigintobj_vardnsrecdegdnspol_c c;
  bigintobj_c sc;
  BOOL failed = bigintobj_vardnsrecdegdnspol_oodivsc (&c, bigintobj_vardnsrecdegdnspol_id2t (self), bigintobj_id2ref (s, &sc), bigintobj_vardnsrecdegdnspol_getargs (self));
  return (failed) ? nil : bigintobj_vardnsrecdegdnspol_c2id (self, &c);
}

- _add:(int)v:B multiplyCoefficient:b:(int)w
{
  bigintobj_vardnsrecdegdnspol_c c;
  bigintobj_c bc;
  bigintobj_vardnsrecdegdnspol_ooaddmulsc (&c, bigintobj_vardnsrecdegdnspol_id2t (self), v, bigintobj_vardnsrecdegdnspol_id2t (B), bigintobj_id2ref (b, &bc), w, bigintobj_vardnsrecdegdnspol_getargs (self));
  return bigintobj_vardnsrecdegdnspol_c2id (self, &c);
}

- _multiplyCoefficient:a:(int)v add:B:(int)w
{
  bigintobj_vardnsrecdegdnspol_c c;
  bigintobj_c ac;
  bigintobj_vardnsrecdegdnspol_oomulscadd (&c, bigintobj_vardnsrecdegdnspol_id2t (self), bigintobj_id2ref (a, &ac), v, bigintobj_vardnsrecdegdnspol_id2t (B), w, bigintobj_vardnsrecdegdnspol_getargs (self));
  return bigintobj_vardnsrecdegdnspol_c2id (self, &c);
}

- _multiplyCoefficient:a:(int)v add:B multiplyCoefficient:b:(int)w
{
  bigintobj_vardnsrecdegdnspol_c c;
  bigintobj_c ac, bc;
  bigintobj_vardnsrecdegdnspol_oomulscaddmulsc (&c, bigintobj_vardnsrecdegdnspol_id2t (self), bigintobj_id2ref (a, &ac), v, bigintobj_vardnsrecdegdnspol_id2t (B), bigintobj_id2ref (b, &bc), w, bigintobj_vardnsrecdegdnspol_getargs (self));
  return bigintobj_vardnsrecdegdnspol_c2id (self, &c);
}

- multiplyTerm:aTerm
{
  bigintobj_vardnsrecdegdnspol_c c;
  bigintobj_t s;
  bigintobj_c sc;
  s = bigintobj_id2ref ([aTerm coefficient], &sc);
  bigintobj_vardnsrecdegdnspol_oomulmonomsc (&c, bigintobj_vardnsrecdegdnspol_id2t (self), [aTerm exponent], s, +1, bigintobj_vardnsrecdegdnspol_getargs (self));
  return bigintobj_vardnsrecdegdnspol_c2id (self, &c);
}

- _multiplyTerm:aTerm:(int)v
{
  bigintobj_vardnsrecdegdnspol_c c;
  bigintobj_t s;
  bigintobj_c sc;
  s = bigintobj_id2ref ([aTerm coefficient], &sc);
  bigintobj_vardnsrecdegdnspol_oomulmonomsc (&c, bigintobj_vardnsrecdegdnspol_id2t (self), [aTerm exponent], s, v, bigintobj_vardnsrecdegdnspol_getargs (self));
  return bigintobj_vardnsrecdegdnspol_c2id (self, &c);
}

- divideTerm:aTerm
{
  int e;
  bigintobj_vardnsrecdegdnspol_c c;
  BOOL failed;
  bigintobj_t s;
  bigintobj_c sc;

  e = [aTerm exponent];
  s = bigintobj_id2ref ([aTerm coefficient], &sc);
  failed = bigintobj_vardnsrecdegdnspol_oodivmonomsc (&c, bigintobj_vardnsrecdegdnspol_id2t (self), e, s, bigintobj_vardnsrecdegdnspol_getargs (self));
  return (failed) ? nil : bigintobj_vardnsrecdegdnspol_c2id (self, &c);
}

- _add:(int)v:B multiplyTerm:b:(int)w
{
  bigintobj_vardnsrecdegdnspol_c c;
  bigintobj_c bc;
  bigintobj_t bs;
  bs = bigintobj_id2ref ([b coefficient], &bc);
  bigintobj_vardnsrecdegdnspol_ooaddmulmonomsc (&c, bigintobj_vardnsrecdegdnspol_id2c (self), v, bigintobj_vardnsrecdegdnspol_id2t (B), [b exponent], bs, w, bigintobj_vardnsrecdegdnspol_getargs (self));
  return bigintobj_vardnsrecdegdnspol_c2id (self, &c);
}

- _multiplyCoefficient:a:(int)v add:B multiplyTerm:b:(int)w
{
  bigintobj_vardnsrecdegdnspol_c c;
  bigintobj_c ac, bc;
  bigintobj_t as, bs;
  as = bigintobj_id2ref (a, &ac);
  bs = bigintobj_id2ref ([b coefficient], &bc);
  bigintobj_vardnsrecdegdnspol_oomulscaddmulmonomsc (&c, bigintobj_vardnsrecdegdnspol_id2c (self), as, v, bigintobj_vardnsrecdegdnspol_id2t (B), [b exponent], bs, w, bigintobj_vardnsrecdegdnspol_getargs (self));
  return bigintobj_vardnsrecdegdnspol_c2id (self, &c);
}


- fileOutOn:aFiler
{
  bigintobj_vardnsrecdegdnspol_args args;
  [super fileOutOn:aFiler];
  args = bigintobj_vardnsrecdegdnspol_getargs (self);	/* can't do this in fileIn case */
  bigintobj_vardnsrecdegdnspol_args_fileOut (aFiler, &args);
  bigintobj_vardnsrecdegdnspol_fileOut (aFiler, &value, args);
  return self;
}

- fileInFrom:aFiler
{
  bigintobj_vardnsrecdegdnspol_args args;
  [super fileInFrom:aFiler];
  bigintobj_vardnsrecdegdnspol_args_fileIn (aFiler, &args);
  bigintobj_vardnsrecdegdnspol_fileIn (aFiler, &value, args);
  return self;
}

@end
 
