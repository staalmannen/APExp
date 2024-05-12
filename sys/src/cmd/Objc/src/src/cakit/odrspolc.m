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
 * $Id: odrspolc.m,v 1.6 2000/10/12 14:40:26 stes Exp $
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
obj_vardnsrecdegspsterm_monom_cval (obj_vardnsrecdegspsterm_t self)
{
  return &self->data;
}

static unimonom_t 
obj_vardnsrecdegspsterm_monom (obj_vardnsrecdegspsterm_t self)
{
#if unimonom_pervalue
  return self->data;
#else
  return obj_vardnsrecdegspsterm_monom_cval (self);
#endif
}

/* stes - mar31,1997
 * change for DEC alpha to exclude varsized scalars
 */

static obj_c *
obj_vardnsrecdegspsterm_scal_cval (obj_vardnsrecdegspsterm_t self, obj_vardnsrecdegspsterm_args args)
{
  return &self->scal;
}

static obj_t 
obj_vardnsrecdegspsterm_scal (obj_vardnsrecdegspsterm_t self, obj_vardnsrecdegspsterm_args args)
{
#if obj_pervalue
  return self->scal;
#else
  return obj_vardnsrecdegspsterm_scal_cval (self, args);
#endif
}

static int 
obj_vardnsrecdegspsterm_check (obj_vardnsrecdegspsterm_t self, obj_vardnsrecdegspsterm_args args)
{
  assert (obj_check (obj_vardnsrecdegspsterm_scal (self, args), args.sargs));
  assert (!obj_iszero (obj_vardnsrecdegspsterm_scal (self, args), args.sargs));
  assert (unimonom_check (obj_vardnsrecdegspsterm_monom (self), args.margs));
  return 1;
}

static int 
obj_vardnsrecdegspsterm_bsize (obj_vardnsrecdegspsterm_args args)
{
  /* this is sizeof(unimonom_c) too much but why bother ? */
  return sizeof (struct obj_vardnsrecdegspsterm) + unimonom_bsize (args.margs);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_alloc (obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_t p;
  int n = obj_vardnsrecdegspsterm_bsize (args);
  p = (obj_vardnsrecdegspsterm_t) OC_Malloc (n);
#if OBJC_REFCNT
  memset (p, 0, n);
#endif
  return p;
}

static void 
obj_vardnsrecdegspsterm_clear (obj_vardnsrecdegspsterm_t self, obj_vardnsrecdegspsterm_args args)
{
  unimonom_clear (obj_vardnsrecdegspsterm_monom_cval (self), args.margs);
  obj_clear (obj_vardnsrecdegspsterm_scal_cval (self, args), args.sargs);
}

static void 
obj_vardnsrecdegspsterm_free (obj_vardnsrecdegspsterm_t self, obj_vardnsrecdegspsterm_args args)
{
  /* invalidating links not always helps : buggy code might work because
   * links were cleared...        self->nlink = NULL;self->plink = NULL;
   */
  OC_Free (self);
}

static int 
obj_vardnsrecdegspsterm_cmp (obj_vardnsrecdegspsterm_t a, obj_vardnsrecdegspsterm_t b, obj_vardnsrecdegspsterm_args args)
{
  assert (obj_vardnsrecdegspsterm_check (a, args) && obj_vardnsrecdegspsterm_check (b, args));
  return unimonom_cmp (obj_vardnsrecdegspsterm_monom (a), obj_vardnsrecdegspsterm_monom (b), args.margs);
}

static int 
obj_vardnsrecdegspsterm_cmpmonom (obj_vardnsrecdegspsterm_t a, unimonom_t b, obj_vardnsrecdegspsterm_args args)
{
  assert (obj_vardnsrecdegspsterm_check (a, args) && unimonom_check (b, args.margs));
  return unimonom_cmp (obj_vardnsrecdegspsterm_monom (a), b, args.margs);
}

static int 
obj_vardnsrecdegspsterm_cmpmul (obj_vardnsrecdegspsterm_t a, obj_vardnsrecdegspsterm_t b, unimonom_t m, obj_vardnsrecdegspsterm_args args)
{
  assert (obj_vardnsrecdegspsterm_check (a, args) && obj_vardnsrecdegspsterm_check (b, args));
  assert (unimonom_check (m, args.margs));
  return unimonom_cmpmul (obj_vardnsrecdegspsterm_monom (a), obj_vardnsrecdegspsterm_monom (b), m, args.margs);
}

static int 
obj_vardnsrecdegspsterm_deg (obj_vardnsrecdegspsterm_t a, obj_vardnsrecdegspsterm_args args)
{
  return unimonom_deg (obj_vardnsrecdegspsterm_monom (a), args.margs);
}

static int 
obj_vardnsrecdegspsterm_iszero (obj_vardnsrecdegspsterm_t self, obj_vardnsrecdegspsterm_args args)
{
  return obj_iszero (obj_vardnsrecdegspsterm_scal (self, args), args.sargs);
}

static int 
obj_vardnsrecdegspsterm_isone (obj_vardnsrecdegspsterm_t self, obj_vardnsrecdegspsterm_args args)
{
  return obj_isone (obj_vardnsrecdegspsterm_scal (self, args), args.sargs) && unimonom_isone (obj_vardnsrecdegspsterm_monom (self), args.margs);
}

static int 
obj_vardnsrecdegspsterm_isminusone (obj_vardnsrecdegspsterm_t self, obj_vardnsrecdegspsterm_args args)
{
  return obj_isminusone (obj_vardnsrecdegspsterm_scal (self, args), args.sargs) && unimonom_isone (obj_vardnsrecdegspsterm_monom (self), args.margs);
}

static int 
obj_vardnsrecdegspsterm_iseq (obj_vardnsrecdegspsterm_t a, obj_vardnsrecdegspsterm_t b, obj_vardnsrecdegspsterm_args args)
{
  assert (obj_vardnsrecdegspsterm_check (a, args) && obj_vardnsrecdegspsterm_check (b, args));
  return unimonom_iseq (obj_vardnsrecdegspsterm_monom (a), obj_vardnsrecdegspsterm_monom (b), args.margs) && obj_iseq (obj_vardnsrecdegspsterm_scal (a, args), obj_vardnsrecdegspsterm_scal (b, args), args.sargs);
}

static int 
obj_vardnsrecdegspsterm_isop (obj_vardnsrecdegspsterm_t a, obj_vardnsrecdegspsterm_t b, obj_vardnsrecdegspsterm_args args)
{
  assert (obj_vardnsrecdegspsterm_check (a, args) && obj_vardnsrecdegspsterm_check (b, args));
  return unimonom_iseq (obj_vardnsrecdegspsterm_monom (a), obj_vardnsrecdegspsterm_monom (b), args.margs) && obj_isop (obj_vardnsrecdegspsterm_scal (a, args), obj_vardnsrecdegspsterm_scal (b, args), args.sargs);
}

static void 
obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A)
{
  C->nlink = A;
  A->plink = C;
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A)
{
  obj_vardnsrecdegspsterm_glue (C, A);
  return A;
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_delete (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_t C = A->nlink;
  obj_vardnsrecdegspsterm_glue (A->plink, C);
  obj_vardnsrecdegspsterm_clear (A, args);
  obj_vardnsrecdegspsterm_free (A, args);
  return C;
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_condcns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t new, obj_vardnsrecdegspsterm_args args)
{
  if (obj_vardnsrecdegspsterm_iszero (new, args))
    {
      obj_vardnsrecdegspsterm_clear (new, args);
      obj_vardnsrecdegspsterm_free (new, args);
      return C;
    }
  else
    {
      assert (obj_vardnsrecdegspsterm_check (new, args));
      return obj_vardnsrecdegspsterm_cns (C, new);
    }
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_conddelete (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_args args)
{
  if (obj_vardnsrecdegspsterm_iszero (A, args))
    {
      return obj_vardnsrecdegspsterm_delete (A, args);
    }
  else
    {
      return A->nlink;
    }
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_copymonomsc_cns (obj_vardnsrecdegspsterm_t C, unimonom_t m, obj_t s, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_t new = obj_vardnsrecdegspsterm_alloc (args);

  obj_copy (obj_vardnsrecdegspsterm_scal_cval (new, args), s, args.sargs);
  unimonom_copy (obj_vardnsrecdegspsterm_monom_cval (new), m, args.margs);

  assert (obj_vardnsrecdegspsterm_check (new, args));
  return obj_vardnsrecdegspsterm_cns (C, new);
}

static void 
obj_vardnsrecdegspsterm_copymonomsc (obj_vardnsrecdegspsterm_t C, unimonom_t m, obj_t s, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspsterm_copymonomsc_cns (C, m, s, args), CT);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_deepcopymonomsc_cns (obj_vardnsrecdegspsterm_t C, unimonom_t m, obj_t s, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_t new = obj_vardnsrecdegspsterm_alloc (args);

  obj_deepcopy (obj_vardnsrecdegspsterm_scal_cval (new, args), s, args.sargs);
  unimonom_copy (obj_vardnsrecdegspsterm_monom_cval (new), m, args.margs);

  assert (obj_vardnsrecdegspsterm_check (new, args));
  return obj_vardnsrecdegspsterm_cns (C, new);
}

static void 
obj_vardnsrecdegspsterm_deepcopymonomsc (obj_vardnsrecdegspsterm_t C, unimonom_t m, obj_t s, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspsterm_deepcopymonomsc_cns (C, m, s, args), CT);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_copy_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_args args)
{
  return obj_vardnsrecdegspsterm_copymonomsc_cns (C, obj_vardnsrecdegspsterm_monom (A), obj_vardnsrecdegspsterm_scal (A, args), args);
}

static void 
obj_vardnsrecdegspsterm_copy (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspsterm_copy_cns (C, A, args), CT);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_deepcopy_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_args args)
{
  return obj_vardnsrecdegspsterm_deepcopymonomsc_cns (C, obj_vardnsrecdegspsterm_monom (A), obj_vardnsrecdegspsterm_scal (A, args), args);
}

static void 
obj_vardnsrecdegspsterm_deepcopy (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspsterm_deepcopy_cns (C, A, args), CT);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_ooneg_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_t new = obj_vardnsrecdegspsterm_alloc (args);
  assert (obj_vardnsrecdegspsterm_iszero (A, args) == NO);

  obj_ooneg (obj_vardnsrecdegspsterm_scal_cval (new, args), obj_vardnsrecdegspsterm_scal (A, args), args.sargs);
  unimonom_copy (obj_vardnsrecdegspsterm_monom_cval (new), obj_vardnsrecdegspsterm_monom (A), args.margs);

  return obj_vardnsrecdegspsterm_cns (C, new);
}

static void 
obj_vardnsrecdegspsterm_ooneg (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspsterm_ooneg_cns (C, A, args), CT);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_inneg (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_args args)
{
  assert (obj_vardnsrecdegspsterm_iszero (A, args) == NO);
  obj_inneg (obj_vardnsrecdegspsterm_scal_cval (A, args), args.sargs);
  assert (obj_vardnsrecdegspsterm_iszero (A, args) == NO);
  return A->nlink;
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_oonegv_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, int v, obj_vardnsrecdegspsterm_args args)
{
  return (v == -1) ? obj_vardnsrecdegspsterm_ooneg_cns (C, A, args) : obj_vardnsrecdegspsterm_copy_cns (C, A, args);
}

static void 
obj_vardnsrecdegspsterm_oonegv (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, int v, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspsterm_oonegv_cns (C, A, v, args), CT);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_innegv (obj_vardnsrecdegspsterm_t A, int v, obj_vardnsrecdegspsterm_args args)
{
  return (v == -1) ? obj_vardnsrecdegspsterm_inneg (A, args) : A->nlink;
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_oodbl_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, int v, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_t new = obj_vardnsrecdegspsterm_alloc (args);
  assert (obj_vardnsrecdegspsterm_iszero (A, args) == NO);

  obj_oodbl (obj_vardnsrecdegspsterm_scal_cval (new, args), obj_vardnsrecdegspsterm_scal (A, args), v, args.sargs);
  unimonom_copy (obj_vardnsrecdegspsterm_monom_cval (new), obj_vardnsrecdegspsterm_monom (A), args.margs);

  return obj_vardnsrecdegspsterm_condcns (C, new, args);
}

static void 
obj_vardnsrecdegspsterm_oodbl (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, int v, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspsterm_oodbl_cns (C, A, v, args), CT);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_indbl (obj_vardnsrecdegspsterm_t A, int v, obj_vardnsrecdegspsterm_args args)
{
  assert (obj_vardnsrecdegspsterm_iszero (A, args) == NO);
  obj_indbl (obj_vardnsrecdegspsterm_scal_cval (A, args), v, args.sargs);
  return obj_vardnsrecdegspsterm_conddelete (A, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_ooaddsc_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, int v, obj_t B, int w, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_t new = obj_vardnsrecdegspsterm_alloc (args);
  obj_ooadd (obj_vardnsrecdegspsterm_scal_cval (new, args), obj_vardnsrecdegspsterm_scal (A, args), v, B, w, args.sargs);
  unimonom_copy (obj_vardnsrecdegspsterm_monom_cval (new), obj_vardnsrecdegspsterm_monom (A), args.margs);
  return obj_vardnsrecdegspsterm_condcns (C, new, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_inaddsc (obj_vardnsrecdegspsterm_t A, int v, obj_t B, int w, obj_vardnsrecdegspsterm_args args)
{
  obj_inadd (obj_vardnsrecdegspsterm_scal_cval (A, args), v, B, w, args.sargs);
  return obj_vardnsrecdegspsterm_conddelete (A, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_ooadd_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, int v, obj_vardnsrecdegspsterm_t B, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (0 == obj_vardnsrecdegspsterm_cmp (A, B, args));
  assert (obj_vardnsrecdegspsterm_iszero (A, args) == NO && obj_vardnsrecdegspsterm_iszero (B, args) == NO);
  return obj_vardnsrecdegspsterm_ooaddsc_cns (C, A, v, obj_vardnsrecdegspsterm_scal (B, args), w, args);
}

static void 
obj_vardnsrecdegspsterm_ooadd (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, int v, obj_vardnsrecdegspsterm_t B, int w, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspsterm_ooadd_cns (C, A, v, B, w, args), CT);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_inadd (obj_vardnsrecdegspsterm_t A, int v, obj_vardnsrecdegspsterm_t B, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (0 == obj_vardnsrecdegspsterm_cmp (A, B, args));
  assert (obj_vardnsrecdegspsterm_iszero (A, args) == NO && obj_vardnsrecdegspsterm_iszero (B, args) == NO);
  return obj_vardnsrecdegspsterm_inaddsc (A, v, obj_vardnsrecdegspsterm_scal (B, args), w, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_oomulsc_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_t s, int v, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_t new = obj_vardnsrecdegspsterm_alloc (args);

  obj_oomulv (obj_vardnsrecdegspsterm_scal_cval (new, args), obj_vardnsrecdegspsterm_scal (A, args), s, v, args.sargs);
  unimonom_copy (obj_vardnsrecdegspsterm_monom_cval (new), obj_vardnsrecdegspsterm_monom (A), args.margs);

  return obj_vardnsrecdegspsterm_condcns (C, new, args);
}

static void 
obj_vardnsrecdegspsterm_oomulsc (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_t s, int v, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspsterm_oomulsc_cns (C, A, s, v, args), CT);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_inmulsc (obj_vardnsrecdegspsterm_t A, obj_t s, int v, obj_vardnsrecdegspsterm_args args)
{
  obj_inmulv (obj_vardnsrecdegspsterm_scal_cval (A, args), s, v, args.sargs);
  return obj_vardnsrecdegspsterm_conddelete (A, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_oomulmonomsc_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, unimonom_t m, obj_t s, int v, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_t new = obj_vardnsrecdegspsterm_alloc (args);

  obj_oomulv (obj_vardnsrecdegspsterm_scal_cval (new, args), obj_vardnsrecdegspsterm_scal (A, args), s, v, args.sargs);
  unimonom_oomul (obj_vardnsrecdegspsterm_monom_cval (new), obj_vardnsrecdegspsterm_monom (A), m, args.margs);

  return obj_vardnsrecdegspsterm_condcns (C, new, args);
}

static void 
obj_vardnsrecdegspsterm_oomulmonomsc (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, unimonom_t m, obj_t s, int v, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspsterm_oomulmonomsc_cns (C, A, m, s, v, args), CT);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_inmulmonomsc (obj_vardnsrecdegspsterm_t A, unimonom_t m, obj_t s, int v, obj_vardnsrecdegspsterm_args args)
{
  obj_inmulv (obj_vardnsrecdegspsterm_scal_cval (A, args), s, v, args.sargs);
  unimonom_inmul (obj_vardnsrecdegspsterm_monom_cval (A), m, args.margs);

  return obj_vardnsrecdegspsterm_conddelete (A, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_ooaddscmulsc_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, int v, obj_t B, obj_t t, int w, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_t new = obj_vardnsrecdegspsterm_alloc (args);

  obj_ooaddmul (obj_vardnsrecdegspsterm_scal_cval (new, args), obj_vardnsrecdegspsterm_scal (A, args), v, B, t, w, args.sargs);
  unimonom_copy (obj_vardnsrecdegspsterm_monom_cval (new), obj_vardnsrecdegspsterm_monom (A), args.margs);

  return obj_vardnsrecdegspsterm_condcns (C, new, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_inaddscmulsc (obj_vardnsrecdegspsterm_t A, int v, obj_t B, obj_t t, int w, obj_vardnsrecdegspsterm_args args)
{
  obj_inaddmul (obj_vardnsrecdegspsterm_scal_cval (A, args), v, B, t, w, args.sargs);
  return obj_vardnsrecdegspsterm_conddelete (A, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_ooaddmulsc_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, int v, obj_vardnsrecdegspsterm_t B, obj_t t, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (0 == (obj_vardnsrecdegspsterm_cmp (A, B, args)));
  return obj_vardnsrecdegspsterm_ooaddscmulsc_cns (C, A, v, obj_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_ooaddmulmonomsc_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, int v, obj_vardnsrecdegspsterm_t B, unimonom_t m, obj_t t, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (0 == (obj_vardnsrecdegspsterm_cmpmul (A, B, m, args)));
  return obj_vardnsrecdegspsterm_ooaddscmulsc_cns (C, A, v, obj_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static void 
obj_vardnsrecdegspsterm_ooaddmulsc (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, int v, obj_vardnsrecdegspsterm_t B, obj_t t, int w, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspsterm_ooaddmulsc_cns (C, A, v, B, t, w, args), CT);
}

static void 
obj_vardnsrecdegspsterm_ooaddmulmonomsc (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, int v, obj_vardnsrecdegspsterm_t B, unimonom_t m, obj_t t, int w, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspsterm_ooaddmulmonomsc_cns (C, A, v, B, m, t, w, args), CT);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_inaddmulsc (obj_vardnsrecdegspsterm_t A, int v, obj_vardnsrecdegspsterm_t B, obj_t t, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (0 == (obj_vardnsrecdegspsterm_cmp (A, B, args)));
  return obj_vardnsrecdegspsterm_inaddscmulsc (A, v, obj_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_inaddmulmonomsc (obj_vardnsrecdegspsterm_t A, int v, obj_vardnsrecdegspsterm_t B, unimonom_t m, obj_t t, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (0 == (obj_vardnsrecdegspsterm_cmpmul (A, B, m, args)));
  return obj_vardnsrecdegspsterm_inaddscmulsc (A, v, obj_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_oomulscaddsc_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_t s, int v, obj_t B, int w, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_t new = obj_vardnsrecdegspsterm_alloc (args);

  obj_oomuladd (obj_vardnsrecdegspsterm_scal_cval (new, args), obj_vardnsrecdegspsterm_scal (A, args), s, v, B, w, args.sargs);
  unimonom_copy (obj_vardnsrecdegspsterm_monom_cval (new), obj_vardnsrecdegspsterm_monom (A), args.margs);

  return obj_vardnsrecdegspsterm_condcns (C, new, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_inmulscaddsc (obj_vardnsrecdegspsterm_t A, obj_t s, int v, obj_t B, int w, obj_vardnsrecdegspsterm_args args)
{
  obj_inmuladd (obj_vardnsrecdegspsterm_scal_cval (A, args), s, v, B, w, args.sargs);
  return obj_vardnsrecdegspsterm_conddelete (A, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_oomulscadd_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_t s, int v, obj_vardnsrecdegspsterm_t B, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (0 == (obj_vardnsrecdegspsterm_cmp (A, B, args)));
  return obj_vardnsrecdegspsterm_oomulscaddsc_cns (C, A, s, v, obj_vardnsrecdegspsterm_scal (B, args), w, args);
}

static void 
obj_vardnsrecdegspsterm_oomulscadd (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_t s, int v, obj_vardnsrecdegspsterm_t B, int w, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspsterm_oomulscadd_cns (C, A, s, v, B, w, args), CT);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_inmulscadd (obj_vardnsrecdegspsterm_t A, obj_t s, int v, obj_vardnsrecdegspsterm_t B, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (0 == (obj_vardnsrecdegspsterm_cmp (A, B, args)));
  return obj_vardnsrecdegspsterm_inmulscaddsc (A, s, v, obj_vardnsrecdegspsterm_scal (B, args), w, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_oomulscaddscmulsc_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_t s, int v, obj_t B, obj_t t, int w, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_t new = obj_vardnsrecdegspsterm_alloc (args);
  obj_oomuladdmul (obj_vardnsrecdegspsterm_scal_cval (new, args), obj_vardnsrecdegspsterm_scal (A, args), s, v, B, t, w, args.sargs);
  unimonom_copy (obj_vardnsrecdegspsterm_monom_cval (new), obj_vardnsrecdegspsterm_monom (A), args.margs);

  return obj_vardnsrecdegspsterm_condcns (C, new, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_inmulscaddscmulsc (obj_vardnsrecdegspsterm_t A, obj_t s, int v, obj_t B, obj_t t, int w, obj_vardnsrecdegspsterm_args args)
{
  obj_inmuladdmul (obj_vardnsrecdegspsterm_scal_cval (A, args), s, v, B, t, w, args.sargs);
  return obj_vardnsrecdegspsterm_conddelete (A, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_oomulscaddmulsc_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_t s, int v, obj_vardnsrecdegspsterm_t B, obj_t t, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (0 == (obj_vardnsrecdegspsterm_cmp (A, B, args)));
  return obj_vardnsrecdegspsterm_oomulscaddscmulsc_cns (C, A, s, v, obj_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_oomulscaddmulmonomsc_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_t s, int v, obj_vardnsrecdegspsterm_t B, unimonom_t m, obj_t t, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (0 == (obj_vardnsrecdegspsterm_cmpmul (A, B, m, args)));
  return obj_vardnsrecdegspsterm_oomulscaddscmulsc_cns (C, A, s, v, obj_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static void 
obj_vardnsrecdegspsterm_oomulscaddmulsc (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_t s, int v, obj_vardnsrecdegspsterm_t B, obj_t t, int w, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspsterm_oomulscaddmulsc_cns (C, A, s, v, B, t, w, args), CT);
}

static void 
obj_vardnsrecdegspsterm_oomulscaddmulmonomsc (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_t s, int v, obj_vardnsrecdegspsterm_t B, unimonom_t m, obj_t t, int w, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspsterm_oomulscaddmulmonomsc_cns (C, A, s, v, B, m, t, w, args), CT);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_inmulscaddmulsc (obj_vardnsrecdegspsterm_t A, obj_t s, int v, obj_vardnsrecdegspsterm_t B, obj_t t, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (0 == (obj_vardnsrecdegspsterm_cmp (A, B, args)));
  return obj_vardnsrecdegspsterm_inmulscaddscmulsc (A, s, v, obj_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_inmulscaddmulmonomsc (obj_vardnsrecdegspsterm_t A, obj_t s, int v, obj_vardnsrecdegspsterm_t B, unimonom_t m, obj_t t, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (0 == (obj_vardnsrecdegspsterm_cmpmul (A, B, m, args)));
  return obj_vardnsrecdegspsterm_inmulscaddscmulsc (A, s, v, obj_vardnsrecdegspsterm_scal (B, args), t, w, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_oodivsc_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_t s, obj_vardnsrecdegspsterm_args args)
{
  BOOL failed;
  obj_vardnsrecdegspsterm_t new = obj_vardnsrecdegspsterm_alloc (args);

  failed = obj_oodiv (obj_vardnsrecdegspsterm_scal_cval (new, args), obj_vardnsrecdegspsterm_scal (A, args), s, args.sargs);
  if (failed)
    {
      obj_vardnsrecdegspsterm_free (new, args);
      return NULL;
    }

  unimonom_copy (obj_vardnsrecdegspsterm_monom_cval (new), obj_vardnsrecdegspsterm_monom (A), args.margs);

  return obj_vardnsrecdegspsterm_condcns (C, new, args);
}

#if 0				/* unused ! why did I write this ? */
static BOOL 
obj_vardnsrecdegspsterm_oodivsc (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_t s, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  if ((C = obj_vardnsrecdegspsterm_oodivsc_cns (C, A, s, args)))
    {
      obj_vardnsrecdegspsterm_glue (C, CT);
      return SUCCESS;
    }
  else
    {
      return FAILURE;
    }
}
#endif

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_indivsc (obj_vardnsrecdegspsterm_t A, obj_t s, obj_vardnsrecdegspsterm_args args)
{
  obj_indiv (obj_vardnsrecdegspsterm_scal_cval (A, args), s, args.sargs);
  return obj_vardnsrecdegspsterm_conddelete (A, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_oodivmonomsc_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, unimonom_t m, obj_t s, obj_vardnsrecdegspsterm_args args)
{
  BOOL sfailed, mfailed;
  obj_vardnsrecdegspsterm_t new = obj_vardnsrecdegspsterm_alloc (args);

  sfailed = obj_oodiv (obj_vardnsrecdegspsterm_scal_cval (new, args), obj_vardnsrecdegspsterm_scal (A, args), s, args.sargs);
  mfailed = unimonom_oodiv (obj_vardnsrecdegspsterm_monom_cval (new), obj_vardnsrecdegspsterm_monom (A), m, args.margs);

  if (sfailed || mfailed)
    {
      /* both failures are possible in the multivariate case */
      obj_vardnsrecdegspsterm_free (new, args);
      return NULL;
    }

  return obj_vardnsrecdegspsterm_condcns (C, new, args);
}

#if 0				/* unused ! why did I write this ? */
static BOOL 
obj_vardnsrecdegspsterm_oodivmonomsc (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, unimonom_t m, obj_t s, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  if ((C = obj_vardnsrecdegspsterm_oodivmonomsc_cns (C, A, m, s, args)))
    {
      obj_vardnsrecdegspsterm_glue (C, CT);
      return SUCCESS;
    }
  else
    {
      return FAILURE;
    }
}
#endif

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_indivmonomsc (obj_vardnsrecdegspsterm_t A, unimonom_t m, obj_t s, obj_vardnsrecdegspsterm_args args)
{
  obj_indiv (obj_vardnsrecdegspsterm_scal_cval (A, args), s, args.sargs);
  unimonom_indiv (obj_vardnsrecdegspsterm_monom_cval (A), m, args.margs);

  return obj_vardnsrecdegspsterm_conddelete (A, args);
}

static void 
obj_vardnsrecdegspsterm_args_fileOut (id aFiler, obj_vardnsrecdegspsterm_args * args)
{
  obj_args_fileOut (aFiler, &args->sargs);
  unimonom_args_fileOut (aFiler, &args->margs);
}
static void 
obj_vardnsrecdegspsterm_args_fileIn (id aFiler, obj_vardnsrecdegspsterm_args * args)
{
  obj_args_fileIn (aFiler, &args->sargs);
  unimonom_args_fileIn (aFiler, &args->margs);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_fileOut (id aFiler, obj_vardnsrecdegspsterm_t self, obj_vardnsrecdegspsterm_args args)
{
  assert (obj_vardnsrecdegspsterm_check (self, args));

  obj_fileOut (aFiler, obj_vardnsrecdegspsterm_scal_cval (self, args), args.sargs);
  unimonom_fileOut (aFiler, obj_vardnsrecdegspsterm_monom_cval (self), args.margs);

  return self->nlink;
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspsterm_fileIn_cns (id aFiler, obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_t self = obj_vardnsrecdegspsterm_alloc (args);

  obj_fileIn (aFiler, obj_vardnsrecdegspsterm_scal_cval (self, args), args.sargs);
  unimonom_fileIn (aFiler, obj_vardnsrecdegspsterm_monom_cval (self), args.margs);

  return obj_vardnsrecdegspsterm_cns (C, self);
}

static int 
obj_vardnsrecdegspslist_check (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_t prev;

  for (prev = NULL; A != AT; prev = A, A = A->nlink)
    {
      if (obj_vardnsrecdegspsterm_check (A, args) == 0)
	return 0;
      if (prev && obj_vardnsrecdegspsterm_cmp (prev, A, args) <= 0)
	return 0;
    }

  return 1;
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspslist_copy_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    {
      C = obj_vardnsrecdegspsterm_copy_cns (C, A, args);
      A = A->nlink;
    }
  return C;
}

static void 
obj_vardnsrecdegspslist_copy (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspslist_copy_cns (C, A, AT, args), CT);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspslist_deepcopy_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    {
      C = obj_vardnsrecdegspsterm_deepcopy_cns (C, A, args);
      A = A->nlink;
    }
  return C;
}

static void 
obj_vardnsrecdegspslist_deepcopy (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspslist_deepcopy_cns (C, A, AT, args), CT);
}

static void 
obj_vardnsrecdegspslist_clear (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    {
      obj_vardnsrecdegspsterm_clear (A, args);
      A = A->nlink;
    }
}

static void 
obj_vardnsrecdegspslist_free (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_t t;
  for (; A != AT; A = t)
    {
      t = A->nlink;
      obj_vardnsrecdegspsterm_free (A, args);
    }
}

static int 
obj_vardnsrecdegspslist_count (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT)
{
  int c = 0;
  for (; A != AT; A = A->nlink)
    c++;
  return c;
}

static unsigned 
obj_vardnsrecdegspslist_hash (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_vardnsrecdegspsterm_args args)
{
  return obj_vardnsrecdegspslist_count (A, AT);
}

static int 
obj_vardnsrecdegspslist_iseq (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_vardnsrecdegspsterm_t B, obj_vardnsrecdegspsterm_t BT, obj_vardnsrecdegspsterm_args args)
{
  for (; A != AT && B != BT; A = A->nlink, B = B->nlink)
    {
      if (!obj_vardnsrecdegspsterm_iseq (A, B, args))
	return 0;
    }
  return (A == AT && B == BT);
}

static int 
obj_vardnsrecdegspslist_isop (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_vardnsrecdegspsterm_t B, obj_vardnsrecdegspsterm_t BT, obj_vardnsrecdegspsterm_args args)
{
  for (; A != AT && B != BT; A = A->nlink, B = B->nlink)
    {
      if (!obj_vardnsrecdegspsterm_isop (A, B, args))
	return 0;
    }
  return (A == AT && B == BT);
}

static int 
obj_vardnsrecdegspslist_deg (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_vardnsrecdegspsterm_args args)
{
  return (A == AT) ? -1 : obj_vardnsrecdegspsterm_deg (A, args);
}

static int 
obj_vardnsrecdegspslist_maxdeg (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_vardnsrecdegspsterm_args args)
{
  int max = (A == AT) ? -1 : obj_vardnsrecdegspsterm_deg (A, args);
  for (A = A->nlink; A != AT; A = A->nlink)
    {
      int d = obj_vardnsrecdegspsterm_deg (A, args);
      if (max < d)
	max = d;
    }
  return max;
}

static int 
obj_vardnsrecdegspslist_ord (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_vardnsrecdegspsterm_args args)
{
  return (A == AT) ? -1 : obj_vardnsrecdegspsterm_deg (AT->plink, args);
}

static int 
obj_vardnsrecdegspslist_mindeg (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_vardnsrecdegspsterm_args args)
{
  int min = (A == AT) ? -1 : obj_vardnsrecdegspsterm_deg (A, args);
  for (A = A->nlink; A != AT; A = A->nlink)
    {
      int d = obj_vardnsrecdegspsterm_deg (A, args);
      if (min > d)
	min = d;
    }
  return min;
}

static void 
obj_vardnsrecdegspslist_insert (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, unimonom_t m, obj_t s, obj_vardnsrecdegspsterm_args args)
{
  assert (obj_iszero (s, args.sargs) == NO);

  /* adding to zero */
  if (A == AT)
    {
      obj_vardnsrecdegspsterm_copymonomsc (A, m, s, A, args);
      return;
    }

  /* tail append */
  if (obj_vardnsrecdegspsterm_cmpmonom (AT->plink, m, args) > 0)
    {
      obj_vardnsrecdegspsterm_copymonomsc (AT->plink, m, s, AT, args);
      return;
    }

  /* insertion */
  while (A != AT)
    {
      int cmp = obj_vardnsrecdegspsterm_cmpmonom (A, m, args);
      if (cmp == 0)
	{
	  obj_vardnsrecdegspsterm_inaddsc (A, +1, s, +1, args);
	  return;
	}
      if (cmp < 0)
	{
	  obj_vardnsrecdegspsterm_copymonomsc (A->plink, m, s, A, args);
	  return;
	}
      A = A->nlink;
    }

  fprintf (stderr, "Shouldn't happen\n");
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspslist_ooneg_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    {
      C = obj_vardnsrecdegspsterm_ooneg_cns (C, A, args);
      A = A->nlink;
    }
  return C;
}

static void 
obj_vardnsrecdegspslist_ooneg (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspslist_ooneg_cns (C, A, AT, args), CT);
}

static void 
obj_vardnsrecdegspslist_inneg (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    A = obj_vardnsrecdegspsterm_inneg (A, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspslist_oonegv_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, int v, obj_vardnsrecdegspsterm_args args)
{
  if (v == -1)
    {
      return obj_vardnsrecdegspslist_ooneg_cns (C, A, AT, args);
    }
  else
    {
      return obj_vardnsrecdegspslist_copy_cns (C, A, AT, args);
    }
}

static void 
obj_vardnsrecdegspslist_oonegv (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, int v, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspslist_oonegv_cns (C, A, AT, v, args), CT);
}

static void 
obj_vardnsrecdegspslist_innegv (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, int v, obj_vardnsrecdegspsterm_args args)
{
  if (v == -1)
    obj_vardnsrecdegspslist_inneg (A, AT, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspslist_oodbl_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, int v, obj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    {
      C = obj_vardnsrecdegspsterm_oodbl_cns (C, A, v, args);
      A = A->nlink;
    }
  return C;
}

static void 
obj_vardnsrecdegspslist_oodbl (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, int v, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspslist_oodbl_cns (C, A, AT, v, args), CT);
}

static void 
obj_vardnsrecdegspslist_indbl (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, int v, obj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    A = obj_vardnsrecdegspsterm_indbl (A, v, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspslist_ooadd_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, int v, obj_vardnsrecdegspsterm_t B, obj_vardnsrecdegspsterm_t BT, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = obj_vardnsrecdegspsterm_ooadd_cns (C, A, v, B, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = obj_vardnsrecdegspsterm_oonegv_cns (C, B, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = obj_vardnsrecdegspsterm_oonegv_cns (C, A, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return obj_vardnsrecdegspslist_oonegv_cns (C, A, AT, v, args);
  if (B != BT)
    return obj_vardnsrecdegspslist_oonegv_cns (C, B, BT, w, args);
  return C;
}

static void 
obj_vardnsrecdegspslist_ooadd (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, int v, obj_vardnsrecdegspsterm_t B, obj_vardnsrecdegspsterm_t BT, int w, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspslist_ooadd_cns (C, A, AT, v, B, BT, w, args), CT);
}

static void 
obj_vardnsrecdegspslist_inadd (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, int v, obj_vardnsrecdegspsterm_t B, obj_vardnsrecdegspsterm_t BT, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = obj_vardnsrecdegspsterm_inadd (A, v, B, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  obj_vardnsrecdegspsterm_oonegv (A->plink, B, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = obj_vardnsrecdegspsterm_innegv (A, v, args);
	}
    }

  if (A != AT)
    obj_vardnsrecdegspslist_innegv (A, AT, v, args);
  if (B != BT)
    obj_vardnsrecdegspslist_oonegv (A->plink, B, BT, w, A, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspslist_oomulsc_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_t s, int v, obj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    {
      C = obj_vardnsrecdegspsterm_oomulsc_cns (C, A, s, v, args);
      A = A->nlink;
    }
  return C;
}

static void 
obj_vardnsrecdegspslist_oomulsc (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_t s, int v, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspslist_oomulsc_cns (C, A, AT, s, v, args), CT);
}

static void 
obj_vardnsrecdegspslist_inmulsc (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_t s, int v, obj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    A = obj_vardnsrecdegspsterm_inmulsc (A, s, v, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspslist_oomulmonomsc_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, unimonom_t m, obj_t s, int v, obj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    {
      C = obj_vardnsrecdegspsterm_oomulmonomsc_cns (C, A, m, s, v, args);
      A = A->nlink;
    }
  return C;
}

static void 
obj_vardnsrecdegspslist_oomulmonomsc (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, unimonom_t m, obj_t s, int v, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspslist_oomulmonomsc_cns (C, A, AT, m, s, v, args), CT);
}

static void 
obj_vardnsrecdegspslist_inmulmonomsc (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, unimonom_t m, obj_t s, int v, obj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    A = obj_vardnsrecdegspsterm_inmulmonomsc (A, m, s, v, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspslist_ooaddmulsc_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, int v, obj_vardnsrecdegspsterm_t B, obj_vardnsrecdegspsterm_t BT, obj_t t, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = obj_vardnsrecdegspsterm_ooaddmulsc_cns (C, A, v, B, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = obj_vardnsrecdegspsterm_oomulsc_cns (C, B, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = obj_vardnsrecdegspsterm_oonegv_cns (C, A, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return obj_vardnsrecdegspslist_oonegv_cns (C, A, AT, v, args);
  if (B != BT)
    return obj_vardnsrecdegspslist_oomulsc_cns (C, B, BT, t, w, args);
  return C;
}

static void 
obj_vardnsrecdegspslist_ooaddmulsc (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, int v, obj_vardnsrecdegspsterm_t B, obj_vardnsrecdegspsterm_t BT, obj_t t, int w, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspslist_ooaddmulsc_cns (C, A, AT, v, B, BT, t, w, args), CT);
}

static void 
obj_vardnsrecdegspslist_inaddmulsc (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, int v, obj_vardnsrecdegspsterm_t B, obj_vardnsrecdegspsterm_t BT, obj_t t, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = obj_vardnsrecdegspsterm_inaddmulsc (A, v, B, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  obj_vardnsrecdegspsterm_oomulsc (A->plink, B, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = obj_vardnsrecdegspsterm_innegv (A, v, args);
	}
    }

  if (A != AT)
    obj_vardnsrecdegspslist_innegv (A, AT, v, args);
  if (B != BT)
    obj_vardnsrecdegspslist_oomulsc (A->plink, B, BT, t, w, A, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspslist_ooaddmulmonomsc_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, int v, obj_vardnsrecdegspsterm_t B, obj_vardnsrecdegspsterm_t BT, unimonom_t m, obj_t t, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsrecdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  C = obj_vardnsrecdegspsterm_ooaddmulmonomsc_cns (C, A, v, B, m, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = obj_vardnsrecdegspsterm_oomulmonomsc_cns (C, B, m, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = obj_vardnsrecdegspsterm_oonegv_cns (C, A, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return obj_vardnsrecdegspslist_oonegv_cns (C, A, AT, v, args);
  if (B != BT)
    return obj_vardnsrecdegspslist_oomulmonomsc_cns (C, B, BT, m, t, w, args);
  return C;
}

static void 
obj_vardnsrecdegspslist_ooaddmulmonomsc (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, int v, obj_vardnsrecdegspsterm_t B, obj_vardnsrecdegspsterm_t BT, unimonom_t m, obj_t t, int w, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspslist_ooaddmulmonomsc_cns (C, A, AT, v, B, BT, m, t, w, args), CT);
}

static void 
obj_vardnsrecdegspslist_inaddmulmonomsc (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, int v, obj_vardnsrecdegspsterm_t B, obj_vardnsrecdegspsterm_t BT, unimonom_t m, obj_t t, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsrecdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  A = obj_vardnsrecdegspsterm_inaddmulmonomsc (A, v, B, m, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  obj_vardnsrecdegspsterm_oomulmonomsc (A->plink, B, m, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = obj_vardnsrecdegspsterm_innegv (A, v, args);
	}
    }

  if (A != AT)
    obj_vardnsrecdegspslist_innegv (A, AT, v, args);
  if (B != BT)
    obj_vardnsrecdegspslist_oomulmonomsc (A->plink, B, BT, m, t, w, A, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspslist_oomulscadd_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_t s, int v, obj_vardnsrecdegspsterm_t B, obj_vardnsrecdegspsterm_t BT, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = obj_vardnsrecdegspsterm_oomulscadd_cns (C, A, s, v, B, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = obj_vardnsrecdegspsterm_oonegv_cns (C, B, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = obj_vardnsrecdegspsterm_oomulsc_cns (C, A, s, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return obj_vardnsrecdegspslist_oomulsc_cns (C, A, AT, s, v, args);
  if (B != BT)
    return obj_vardnsrecdegspslist_oonegv_cns (C, B, BT, w, args);
  return C;
}

static void 
obj_vardnsrecdegspslist_oomulscadd (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_t s, int v, obj_vardnsrecdegspsterm_t B, obj_vardnsrecdegspsterm_t BT, int w, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspslist_oomulscadd_cns (C, A, AT, s, v, B, BT, w, args), CT);
}

static void 
obj_vardnsrecdegspslist_inmulscadd (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_t s, int v, obj_vardnsrecdegspsterm_t B, obj_vardnsrecdegspsterm_t BT, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = obj_vardnsrecdegspsterm_inmulscadd (A, s, v, B, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  obj_vardnsrecdegspsterm_oonegv (A->plink, B, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = obj_vardnsrecdegspsterm_inmulsc (A, s, v, args);
	}
    }

  if (A != AT)
    obj_vardnsrecdegspslist_inmulsc (A, AT, s, v, args);
  if (B != BT)
    obj_vardnsrecdegspslist_oonegv (A->plink, B, BT, w, A, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspslist_oomulscaddmulsc_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_t s, int v, obj_vardnsrecdegspsterm_t B, obj_vardnsrecdegspsterm_t BT, obj_t t, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = obj_vardnsrecdegspsterm_oomulscaddmulsc_cns (C, A, s, v, B, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = obj_vardnsrecdegspsterm_oomulsc_cns (C, B, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = obj_vardnsrecdegspsterm_oomulsc_cns (C, A, s, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return obj_vardnsrecdegspslist_oomulsc_cns (C, A, AT, s, v, args);
  if (B != BT)
    return obj_vardnsrecdegspslist_oomulsc_cns (C, B, BT, t, w, args);
  return C;
}

static void 
obj_vardnsrecdegspslist_oomulscaddmulsc (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_t s, int v, obj_vardnsrecdegspsterm_t B, obj_vardnsrecdegspsterm_t BT, obj_t t, int w, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspslist_oomulscaddmulsc_cns (C, A, AT, s, v, B, BT, t, w, args), CT);
}

static void 
obj_vardnsrecdegspslist_inmulscaddmulsc (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_t s, int v, obj_vardnsrecdegspsterm_t B, obj_vardnsrecdegspsterm_t BT, obj_t t, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsrecdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = obj_vardnsrecdegspsterm_inmulscaddmulsc (A, s, v, B, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  obj_vardnsrecdegspsterm_oomulsc (A->plink, B, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = obj_vardnsrecdegspsterm_inmulsc (A, s, v, args);
	}
    }

  if (A != AT)
    obj_vardnsrecdegspslist_inmulsc (A, AT, s, v, args);
  if (B != BT)
    obj_vardnsrecdegspslist_oomulsc (A->plink, B, BT, t, w, A, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspslist_oomulscaddmulmonomsc_cns (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_t s, int v, obj_vardnsrecdegspsterm_t B, obj_vardnsrecdegspsterm_t BT, unimonom_t m, obj_t t, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsrecdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  C = obj_vardnsrecdegspsterm_oomulscaddmulmonomsc_cns (C, A, s, v, B, m, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = obj_vardnsrecdegspsterm_oomulmonomsc_cns (C, B, m, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = obj_vardnsrecdegspsterm_oomulsc_cns (C, A, s, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return obj_vardnsrecdegspslist_oomulsc_cns (C, A, AT, s, v, args);
  if (B != BT)
    return obj_vardnsrecdegspslist_oomulmonomsc_cns (C, B, BT, m, t, w, args);
  return C;
}

static void 
obj_vardnsrecdegspslist_oomulscaddmulmonomsc (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_t s, int v, obj_vardnsrecdegspsterm_t B, obj_vardnsrecdegspsterm_t BT, unimonom_t m, obj_t t, int w, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspslist_oomulscaddmulmonomsc_cns (C, A, AT, s, v, B, BT, m, t, w, args), CT);
}

static void 
obj_vardnsrecdegspslist_inmulscaddmulmonomsc (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_t s, int v, obj_vardnsrecdegspsterm_t B, obj_vardnsrecdegspsterm_t BT, unimonom_t m, obj_t t, int w, obj_vardnsrecdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsrecdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  A = obj_vardnsrecdegspsterm_inmulscaddmulmonomsc (A, s, v, B, m, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  obj_vardnsrecdegspsterm_oomulmonomsc (A->plink, B, m, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = obj_vardnsrecdegspsterm_inmulsc (A, s, v, args);
	}
    }

  if (A != AT)
    obj_vardnsrecdegspslist_inmulsc (A, AT, s, v, args);
  if (B != BT)
    obj_vardnsrecdegspslist_oomulmonomsc (A->plink, B, BT, m, t, w, A, args);
}

static BOOL 
obj_vardnsrecdegspslist_oodivsc (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_t s, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  BOOL failed = NO;

  while (A != AT)
    {
      obj_vardnsrecdegspsterm_t nextC = obj_vardnsrecdegspsterm_oodivsc_cns (C, A, s, args);
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
  obj_vardnsrecdegspsterm_glue (C, CT);
  return failed;
}

static void 
obj_vardnsrecdegspslist_indivsc (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_t s, obj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    A = obj_vardnsrecdegspsterm_indivsc (A, s, args);
}

static BOOL 
obj_vardnsrecdegspslist_oodivmonomsc (obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, unimonom_t m, obj_t s, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  BOOL failed = NO;

  while (A != AT)
    {
      obj_vardnsrecdegspsterm_t nextC = obj_vardnsrecdegspsterm_oodivmonomsc_cns (C, A, m, s, args);
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
  obj_vardnsrecdegspsterm_glue (C, CT);
  return failed;
}

static void 
obj_vardnsrecdegspslist_indivmonomsc (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, unimonom_t m, obj_t s, obj_vardnsrecdegspsterm_args args)
{
  while (A != AT)
    A = obj_vardnsrecdegspsterm_indivmonomsc (A, m, s, args);
}

static void 
obj_vardnsrecdegspslist_fileOut (id aFiler, obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT, obj_vardnsrecdegspsterm_args args)
{
  int n;
  n = obj_vardnsrecdegspslist_count (A, AT);
  [aFiler fileOut:&n type:'i'];
  while (A != AT)
    A = obj_vardnsrecdegspsterm_fileOut (aFiler, A, args);
}

static obj_vardnsrecdegspsterm_t 
obj_vardnsrecdegspslist_fileIn_cns (id aFiler, obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_args args)
{
  int n;
  [aFiler fileIn:&n type:'i'];
  while (n--)
    C = obj_vardnsrecdegspsterm_fileIn_cns (aFiler, C, args);
  return C;
}

static void 
obj_vardnsrecdegspslist_fileIn (id aFiler, obj_vardnsrecdegspsterm_t C, obj_vardnsrecdegspsterm_t CT, obj_vardnsrecdegspsterm_args args)
{
  obj_vardnsrecdegspsterm_glue (obj_vardnsrecdegspslist_fileIn_cns (aFiler, C, args), CT);
}

static void 
obj_vardnsrecdegspspol_ix_init (obj_vardnsrecdegspspol_ixt ix, id self)
{
  obj_vardnsrecdegspspol_t v = [self obj_vardnsrecdegspspol_value];
  ix->head = v;
  ix->ix = v;
}

static void 
obj_vardnsrecdegspspol_ix_clear (obj_vardnsrecdegspspol_ixt ix)
{
  /* nothing to clear */
}

static int 
obj_vardnsrecdegspspol_ix_count_aux_aux (obj_vardnsrecdegspsterm_t A, obj_vardnsrecdegspsterm_t AT)
{
  int c = 0;
  for (; A != AT; A = A->nlink)
    c++;
  return c;
}

static int 
obj_vardnsrecdegspspol_ix_count_aux (obj_vardnsrecdegspspol_t self)
{
  return obj_vardnsrecdegspspol_ix_count_aux_aux (self->nlink, self);
}

static int 
obj_vardnsrecdegspspol_ix_count (obj_vardnsrecdegspspol_ixt ix)
{
  /* merde ! can't include entire obj_vardnsrecdegspslist for obj_vardnsrecdegspslist_count */
  return obj_vardnsrecdegspspol_ix_count_aux (ix->head);
}

static int 
obj_vardnsrecdegspspol_ix_isempty_aux (obj_vardnsrecdegspspol_t self)
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
obj_vardnsrecdegspspol_ix_isempty (obj_vardnsrecdegspspol_ixt ix)
{
  /* can't include entire obj_vardnsrecdegspspol for obj_vardnsrecdegspspol_isempty */
  return obj_vardnsrecdegspspol_ix_isempty_aux (ix->head);
}

static int 
obj_vardnsrecdegspspol_ix_ismatch (obj_vardnsrecdegspspol_ixt ix)
{
  return (ix->ix != NULL && ix->ix != ix->head);
}

static void 
obj_vardnsrecdegspspol_ix_tofirst (obj_vardnsrecdegspspol_ixt ix)
{
  ix->ix = ix->head;
}

static void 
obj_vardnsrecdegspspol_ix_tolast (obj_vardnsrecdegspspol_ixt ix)
{
  ix->ix = NULL;
}

static void 
obj_vardnsrecdegspspol_ix_to (obj_vardnsrecdegspspol_ixt ix, int i)
{
  fprintf (stderr, "at: notImplemented\n");
}

static void 
obj_vardnsrecdegspspol_ix_next (obj_vardnsrecdegspspol_ixt ix)
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
obj_vardnsrecdegspspol_ix_prev (obj_vardnsrecdegspspol_ixt ix)
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
obj_vardnsrecdegspspol_check (obj_vardnsrecdegspspol_t self, obj_vardnsrecdegspspol_args args)
{
  assert (self->data == 0xcafebabe);
  return obj_vardnsrecdegspslist_check (self->nlink, self, args);
}

static obj_vardnsrecdegspspol_t 
obj_vardnsrecdegspspol_id2t (id object)
{
  return [object obj_vardnsrecdegspspol_value];
}

static obj_vardnsrecdegspspol_c *
obj_vardnsrecdegspspol_id2c (id object)
{
  return [object obj_vardnsrecdegspspol_reference];
}

static id 
obj_vardnsrecdegspspol_t2id (id proto, obj_vardnsrecdegspspol_t f)
{
  return [proto obj_vardnsrecdegspspol_value:f];
}

static id 
obj_vardnsrecdegspspol_c2id (id proto, obj_vardnsrecdegspspol_c * r)
{
  return [proto obj_vardnsrecdegspspol_reference:r];
}

static int 
obj_vardnsrecdegspspol_isempty (obj_vardnsrecdegspspol_t self)
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
obj_vardnsrecdegspspol_init (obj_vardnsrecdegspspol_t self, obj_vardnsrecdegspspol_args args)
{
  self->data = 0xcafebabe;
  self->nlink = self;
  self->plink = self;
  assert (obj_vardnsrecdegspspol_check (self, args));
}

static void 
obj_vardnsrecdegspspol_copy (obj_vardnsrecdegspspol_t c, obj_vardnsrecdegspspol_t a, obj_vardnsrecdegspspol_args args)
{
  assert (obj_vardnsrecdegspspol_check (a, args));
  obj_vardnsrecdegspspol_init (c, args);
  obj_vardnsrecdegspslist_copy (c, a->nlink, a, c, args);
}

static void 
obj_vardnsrecdegspspol_deepcopy (obj_vardnsrecdegspspol_t c, obj_vardnsrecdegspspol_t a, obj_vardnsrecdegspspol_args args)
{
  assert (obj_vardnsrecdegspspol_check (a, args));
  obj_vardnsrecdegspspol_init (c, args);
  obj_vardnsrecdegspslist_deepcopy (c, a->nlink, a, c, args);
}

static void 
obj_vardnsrecdegspspol_move (obj_vardnsrecdegspspol_t c, obj_vardnsrecdegspspol_t a, obj_vardnsrecdegspspol_args args)
{
  if (obj_vardnsrecdegspspol_isempty (a))
    {
      obj_vardnsrecdegspspol_init (c, args);
    }
  else
    {
      obj_vardnsrecdegspspol_init (c, args);
      obj_vardnsrecdegspsterm_glue (c, a->nlink);
      obj_vardnsrecdegspsterm_glue (a->plink, c);
    }

  a->data = 0;
  assert (obj_vardnsrecdegspspol_check (c, args));
}

static void 
obj_vardnsrecdegspspol_clear (obj_vardnsrecdegspspol_t self, obj_vardnsrecdegspspol_args args)
{
  obj_vardnsrecdegspslist_clear (self->nlink, self, args);
  self->data = 0;
  obj_vardnsrecdegspslist_free (self->nlink, self, args);
}

static int 
obj_vardnsrecdegspspol_count (obj_vardnsrecdegspspol_t self)
{
  return obj_vardnsrecdegspslist_count (self->nlink, self);
}

static unsigned 
obj_vardnsrecdegspspol_hash (obj_vardnsrecdegspspol_t a, obj_vardnsrecdegspspol_args args)
{
  return obj_vardnsrecdegspslist_hash (a->nlink, a, args);
}

static int 
obj_vardnsrecdegspspol_iseq (obj_vardnsrecdegspspol_t a, obj_vardnsrecdegspspol_t b, obj_vardnsrecdegspspol_args args)
{
  return (a == b) ? YES : obj_vardnsrecdegspslist_iseq (a->nlink, a, b->nlink, b, args);
}

static int 
obj_vardnsrecdegspspol_isone (obj_vardnsrecdegspspol_t a, obj_vardnsrecdegspspol_args args)
{
  /* if the leading term is one, then it is one */
  return (obj_vardnsrecdegspspol_isempty (a)) ? 0 : obj_vardnsrecdegspsterm_isone (a->nlink, args);
}

static int 
obj_vardnsrecdegspspol_isminusone (obj_vardnsrecdegspspol_t a, obj_vardnsrecdegspspol_args args)
{
  /* if the leading term is minus one, then it is minus one */
  return (obj_vardnsrecdegspspol_isempty (a)) ? 0 : obj_vardnsrecdegspsterm_isminusone (a->nlink, args);
}

static int 
obj_vardnsrecdegspspol_deg (obj_vardnsrecdegspspol_t self, obj_vardnsrecdegspspol_args args)
{
  return obj_vardnsrecdegspslist_deg (self->nlink, self, args);
}

static int 
obj_vardnsrecdegspspol_ord (obj_vardnsrecdegspspol_t self, obj_vardnsrecdegspspol_args args)
{
  return obj_vardnsrecdegspslist_ord (self->nlink, self, args);
}

static int 
obj_vardnsrecdegspspol_maxdeg (obj_vardnsrecdegspspol_t self, obj_vardnsrecdegspspol_args args)
{
  return obj_vardnsrecdegspslist_maxdeg (self->nlink, self, args);
}

static int 
obj_vardnsrecdegspspol_mindeg (obj_vardnsrecdegspspol_t self, obj_vardnsrecdegspspol_args args)
{
  return obj_vardnsrecdegspslist_mindeg (self->nlink, self, args);
}

static obj_t 
obj_vardnsrecdegspspol_scalat (obj_vardnsrecdegspspol_t self, obj_vardnsrecdegspspol_ixt ix, obj_vardnsrecdegspspol_args args)
{
  assert (obj_vardnsrecdegspspol_ix_ismatch (ix) && ix->head == self);
  return obj_vardnsrecdegspsterm_scal (ix->ix, args);
}

static unimonom_t 
obj_vardnsrecdegspspol_monomat (obj_vardnsrecdegspspol_t self, obj_vardnsrecdegspspol_ixt ix, obj_vardnsrecdegspspol_args args)
{
  assert (obj_vardnsrecdegspspol_ix_ismatch (ix) && ix->head == self);
  return obj_vardnsrecdegspsterm_monom (ix->ix);
}

static obj_t 
obj_vardnsrecdegspspol_scalfirst (obj_vardnsrecdegspspol_t self, obj_vardnsrecdegspspol_args args)
{
  assert (obj_vardnsrecdegspspol_isempty (self) == NO);
  return obj_vardnsrecdegspsterm_scal (self->nlink, args);
}

static unimonom_t 
obj_vardnsrecdegspspol_monomfirst (obj_vardnsrecdegspspol_t self, obj_vardnsrecdegspspol_args args)
{
  assert (obj_vardnsrecdegspspol_isempty (self) == NO);
  return obj_vardnsrecdegspsterm_monom (self->nlink);
}

static void 
obj_vardnsrecdegspspol_remove (obj_vardnsrecdegspspol_t self, obj_vardnsrecdegspspol_args args)
{
  assert (obj_vardnsrecdegspspol_check (self, args) && obj_vardnsrecdegspspol_isempty (self) == NO);
  obj_vardnsrecdegspsterm_delete (self->nlink, args);
  assert (obj_vardnsrecdegspspol_check (self, args));
}

static void 
obj_vardnsrecdegspspol_insert (obj_vardnsrecdegspspol_t self, unimonom_t m, obj_t s, obj_vardnsrecdegspspol_args args)
{
  assert (obj_vardnsrecdegspspol_check (self, args));
  obj_vardnsrecdegspslist_insert (self->nlink, self, m, s, args);
  assert (obj_vardnsrecdegspspol_check (self, args));
}

static int 
obj_vardnsrecdegspspol_iszero (obj_vardnsrecdegspspol_t self, obj_vardnsrecdegspspol_args args)
{
  return obj_vardnsrecdegspspol_isempty (self);
}

static int 
obj_vardnsrecdegspspol_isop (obj_vardnsrecdegspspol_t a, obj_vardnsrecdegspspol_t b, obj_vardnsrecdegspspol_args args)
{
  assert (a != b);
  return obj_vardnsrecdegspslist_isop (a->nlink, a, b->nlink, b, args);
}

static void 
obj_vardnsrecdegspspol_ooneg (obj_vardnsrecdegspspol_t c, obj_vardnsrecdegspspol_t a, obj_vardnsrecdegspspol_args args)
{
  obj_vardnsrecdegspspol_init (c, args);
  obj_vardnsrecdegspslist_ooneg (c, a->nlink, a, c, args);
  assert (obj_vardnsrecdegspspol_check (c, args));
}

static void 
obj_vardnsrecdegspspol_inneg (obj_vardnsrecdegspspol_t a, obj_vardnsrecdegspspol_args args)
{
  obj_vardnsrecdegspslist_inneg (a->nlink, a, args);
  assert (obj_vardnsrecdegspspol_check (a, args));
}

static void 
obj_vardnsrecdegspspol_oodbl (obj_vardnsrecdegspspol_t c, obj_vardnsrecdegspspol_t a, int v, obj_vardnsrecdegspspol_args args)
{
  obj_vardnsrecdegspspol_init (c, args);
  obj_vardnsrecdegspslist_oodbl (c, a->nlink, a, v, c, args);
  assert (obj_vardnsrecdegspspol_check (c, args));
}

static void 
obj_vardnsrecdegspspol_indbl (obj_vardnsrecdegspspol_t a, int v, obj_vardnsrecdegspspol_args args)
{
  obj_vardnsrecdegspslist_indbl (a->nlink, a, v, args);
  assert (obj_vardnsrecdegspspol_check (a, args));
}

static void 
obj_vardnsrecdegspspol_ooadd (obj_vardnsrecdegspspol_t c, obj_vardnsrecdegspspol_t a, int v, obj_vardnsrecdegspspol_t b, int w, obj_vardnsrecdegspspol_args args)
{
  assert (a != b);
  obj_vardnsrecdegspspol_init (c, args);
  obj_vardnsrecdegspslist_ooadd (c, a->nlink, a, v, b->nlink, b, w, c, args);
  assert (obj_vardnsrecdegspspol_check (c, args));
}

static void 
obj_vardnsrecdegspspol_inadd (obj_vardnsrecdegspspol_t a, int v, obj_vardnsrecdegspspol_t b, int w, obj_vardnsrecdegspspol_args args)
{
  assert (a != b);
  obj_vardnsrecdegspslist_inadd (a->nlink, a, v, b->nlink, b, w, args);
  assert (obj_vardnsrecdegspspol_check (a, args));
}

static void 
obj_vardnsrecdegspspol_oomulsc (obj_vardnsrecdegspspol_t c, obj_vardnsrecdegspspol_t a, obj_t s, obj_vardnsrecdegspspol_args args)
{
  obj_vardnsrecdegspspol_init (c, args);
  obj_vardnsrecdegspslist_oomulsc (c, a->nlink, a, s, +1, c, args);
  assert (obj_vardnsrecdegspspol_check (c, args));
}

static void 
obj_vardnsrecdegspspol_inmulsc (obj_vardnsrecdegspspol_t a, obj_t s, obj_vardnsrecdegspspol_args args)
{
  obj_vardnsrecdegspslist_inmulsc (a->nlink, a, s, +1, args);
  assert (obj_vardnsrecdegspspol_check (a, args));
}

static void 
obj_vardnsrecdegspspol_ooaddmulsc (obj_vardnsrecdegspspol_t c, obj_vardnsrecdegspspol_t a, int v, obj_vardnsrecdegspspol_t b, obj_t t, int w, obj_vardnsrecdegspspol_args args)
{
  obj_vardnsrecdegspspol_init (c, args);
  obj_vardnsrecdegspslist_ooaddmulsc (c, a->nlink, a, v, b->nlink, b, t, w, c, args);
  assert (obj_vardnsrecdegspspol_check (c, args));
}

static void 
obj_vardnsrecdegspspol_inaddmulsc (obj_vardnsrecdegspspol_t a, int v, obj_vardnsrecdegspspol_t b, obj_t t, int w, obj_vardnsrecdegspspol_args args)
{
  obj_vardnsrecdegspslist_inaddmulsc (a->nlink, a, v, b->nlink, b, t, w, args);
  assert (obj_vardnsrecdegspspol_check (a, args));
}

static void 
obj_vardnsrecdegspspol_oomulscadd (obj_vardnsrecdegspspol_t c, obj_vardnsrecdegspspol_t a, obj_t s, int v, obj_vardnsrecdegspspol_t b, int w, obj_vardnsrecdegspspol_args args)
{
  obj_vardnsrecdegspspol_init (c, args);
  obj_vardnsrecdegspslist_oomulscadd (c, a->nlink, a, s, v, b->nlink, b, w, c, args);
  assert (obj_vardnsrecdegspspol_check (c, args));
}

static void 
obj_vardnsrecdegspspol_inmulscadd (obj_vardnsrecdegspspol_t a, obj_t s, int v, obj_vardnsrecdegspspol_t b, int w, obj_vardnsrecdegspspol_args args)
{
  obj_vardnsrecdegspslist_inmulscadd (a->nlink, a, s, v, b->nlink, b, w, args);
  assert (obj_vardnsrecdegspspol_check (a, args));
}

static void 
obj_vardnsrecdegspspol_oomulscaddmulsc (obj_vardnsrecdegspspol_t c, obj_vardnsrecdegspspol_t a, obj_t s, int v, obj_vardnsrecdegspspol_t b, obj_t t, int w, obj_vardnsrecdegspspol_args args)
{
  obj_vardnsrecdegspspol_init (c, args);
  obj_vardnsrecdegspslist_oomulscaddmulsc (c, a->nlink, a, s, v, b->nlink, b, t, w, c, args);
  assert (obj_vardnsrecdegspspol_check (c, args));
}

static void 
obj_vardnsrecdegspspol_inmulscaddmulsc (obj_vardnsrecdegspspol_t a, obj_t s, int v, obj_vardnsrecdegspspol_t b, obj_t t, int w, obj_vardnsrecdegspspol_args args)
{
  obj_vardnsrecdegspslist_inmulscaddmulsc (a->nlink, a, s, v, b->nlink, b, t, w, args);
  assert (obj_vardnsrecdegspspol_check (a, args));
}

static BOOL 
obj_vardnsrecdegspspol_oodivsc (obj_vardnsrecdegspspol_t c, obj_vardnsrecdegspspol_t a, obj_t s, obj_vardnsrecdegspspol_args args)
{
  BOOL failed;
  obj_vardnsrecdegspspol_init (c, args);
  failed = obj_vardnsrecdegspslist_oodivsc (c, a->nlink, a, s, c, args);
  assert (obj_vardnsrecdegspspol_check (c, args));
  if (failed)
    obj_vardnsrecdegspspol_clear (c, args);
  return failed;
}

static void 
obj_vardnsrecdegspspol_indivsc (obj_vardnsrecdegspspol_t a, obj_t s, obj_vardnsrecdegspspol_args args)
{
  obj_vardnsrecdegspslist_indivsc (a->nlink, a, s, args);
  assert (obj_vardnsrecdegspspol_check (a, args));
}

static void 
obj_vardnsrecdegspspol_oomulmonomsc (obj_vardnsrecdegspspol_t c, obj_vardnsrecdegspspol_t b, unimonom_t m, obj_t t, int w, obj_vardnsrecdegspspol_args args)
{
  obj_vardnsrecdegspspol_init (c, args);
  obj_vardnsrecdegspslist_oomulmonomsc (c, b->nlink, b, m, t, w, c, args);
  assert (obj_vardnsrecdegspspol_check (c, args));
}

static void 
obj_vardnsrecdegspspol_inmulmonomsc (obj_vardnsrecdegspspol_t b, unimonom_t m, obj_t t, int w, obj_vardnsrecdegspspol_args args)
{
  obj_vardnsrecdegspslist_inmulmonomsc (b->nlink, b, m, t, w, args);
  assert (obj_vardnsrecdegspspol_check (b, args));
}

static void 
obj_vardnsrecdegspspol_ooaddmulmonomsc (obj_vardnsrecdegspspol_t c, obj_vardnsrecdegspspol_t a, int v, obj_vardnsrecdegspspol_t b, unimonom_t m, obj_t t, int w, obj_vardnsrecdegspspol_args args)
{
  obj_vardnsrecdegspspol_init (c, args);
  obj_vardnsrecdegspslist_ooaddmulmonomsc (c, a->nlink, a, v, b->nlink, b, m, t, w, c, args);
  assert (obj_vardnsrecdegspspol_check (c, args));
}

static void 
obj_vardnsrecdegspspol_inaddmulmonomsc (obj_vardnsrecdegspspol_t a, int v, obj_vardnsrecdegspspol_t b, unimonom_t m, obj_t t, int w, obj_vardnsrecdegspspol_args args)
{
  obj_vardnsrecdegspslist_inaddmulmonomsc (a->nlink, a, v, b->nlink, b, m, t, w, args);
  assert (obj_vardnsrecdegspspol_check (a, args));
}

static void 
obj_vardnsrecdegspspol_oomulscaddmulmonomsc (obj_vardnsrecdegspspol_t c, obj_vardnsrecdegspspol_t a, obj_t s, int v, obj_vardnsrecdegspspol_t b, unimonom_t m, obj_t t, int w, obj_vardnsrecdegspspol_args args)
{
  obj_vardnsrecdegspspol_init (c, args);
  obj_vardnsrecdegspslist_oomulscaddmulmonomsc (c, a->nlink, a, s, v, b->nlink, b, m, t, w, c, args);
  assert (obj_vardnsrecdegspspol_check (c, args));
}

static void 
obj_vardnsrecdegspspol_inmulscaddmulmonomsc (obj_vardnsrecdegspspol_t a, obj_t s, int v, obj_vardnsrecdegspspol_t b, unimonom_t m, obj_t t, int w, obj_vardnsrecdegspspol_args args)
{
  obj_vardnsrecdegspslist_inmulscaddmulmonomsc (a->nlink, a, s, v, b->nlink, b, m, t, w, args);
  assert (obj_vardnsrecdegspspol_check (a, args));
}

static BOOL 
obj_vardnsrecdegspspol_oodivmonomsc (obj_vardnsrecdegspspol_t c, obj_vardnsrecdegspspol_t b, unimonom_t m, obj_t t, obj_vardnsrecdegspspol_args args)
{
  BOOL failed;
  obj_vardnsrecdegspspol_init (c, args);
  failed = obj_vardnsrecdegspslist_oodivmonomsc (c, b->nlink, b, m, t, c, args);
  assert (obj_vardnsrecdegspspol_check (c, args));
  if (failed)
    obj_vardnsrecdegspspol_clear (c, args);
  return failed;
}

static void 
obj_vardnsrecdegspspol_indivmonomsc (obj_vardnsrecdegspspol_t b, unimonom_t m, obj_t t, obj_vardnsrecdegspspol_args args)
{
  obj_vardnsrecdegspslist_indivmonomsc (b->nlink, b, m, t, args);
  assert (obj_vardnsrecdegspspol_check (b, args));
}

static void 
obj_vardnsrecdegspspol_args_fileOut (id aFiler, obj_vardnsrecdegspspol_args * args)
{
  obj_vardnsrecdegspsterm_args_fileOut (aFiler, args);
}
static void 
obj_vardnsrecdegspspol_args_fileIn (id aFiler, obj_vardnsrecdegspspol_args * args)
{
  obj_vardnsrecdegspsterm_args_fileIn (aFiler, args);
}

static void 
obj_vardnsrecdegspspol_fileOut (id aFiler, obj_vardnsrecdegspspol_t self, obj_vardnsrecdegspspol_args args)
{
  assert (obj_vardnsrecdegspspol_check (self, args));
  obj_vardnsrecdegspslist_fileOut (aFiler, self->nlink, self, args);
}

static void 
obj_vardnsrecdegspspol_fileIn (id aFiler, obj_vardnsrecdegspspol_t self, obj_vardnsrecdegspspol_args args)
{
  obj_vardnsrecdegspspol_init (self, args);
  obj_vardnsrecdegspslist_fileIn (aFiler, self, self, args);
  assert (obj_vardnsrecdegspspol_check (self, args));
}

static obj_vardnsrecdegspspol_args 
obj_vardnsrecdegspspol_getargs (id self)
{
  obj_vardnsrecdegspspol_args res;
  res.sargs = obj_getargs ([[self termZero] coefficient]);
  res.margs = 0;		/* unused */
  return res;
}

static int 
obj_vardnsrecdegspspol_expat (obj_vardnsrecdegspspol_t self, obj_vardnsrecdegspspol_ixt ix, obj_vardnsrecdegspspol_args args)
{
  return obj_vardnsrecdegspspol_monomat (self, ix, args);
}

static int 
obj_vardnsrecdegspspol_expfirst (obj_vardnsrecdegspspol_t self, obj_vardnsrecdegspspol_args args)
{
  return obj_vardnsrecdegspspol_monomfirst (self, args);
}
@implementation obj_vardnsrecdegsps_polynomial : vardnsrecdegsps_polynomial

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
  obj_vardnsrecdegspspol_init (&value, obj_vardnsrecdegspspol_getargs (self));
  assert ([self check]);
  return self;
}

+ scalarZero:aScalar coefficientZero:aCoef symbols:aCltn
{
  return [[super new] _setUpScalarZero:aScalar coefficientZero:aCoef symbols:aCltn];
}

- empty
{
  obj_vardnsrecdegspspol_c c;
  assert ([self check]);
  /* in vardns case, init takes a capacity */
  obj_vardnsrecdegspspol_init (&c, obj_vardnsrecdegspspol_getargs (self));
  return obj_vardnsrecdegspspol_c2id (self, &c);
}

- (int) numTerms
{
  /* seems to take getargs in degdns case */
  assert ([self check]);
  return obj_vardnsrecdegspspol_count (&value);
}

- (obj_vardnsrecdegspspol_t)obj_vardnsrecdegspspol_value
{
  return &value;
}

- doobj_vardnsrecdegspspol_value:(obj_vardnsrecdegspspol_t)aValue
{
  obj_vardnsrecdegspspol_copy (&value, aValue, obj_vardnsrecdegspspol_getargs (self));
  assert ([self check]);
  return self;
}

- obj_vardnsrecdegspspol_value:(obj_vardnsrecdegspspol_t)aValue
{
  return [[self clone] doobj_vardnsrecdegspspol_value:aValue];
}

- (obj_vardnsrecdegspspol_t)obj_vardnsrecdegspspol_reference
{
  return &value;
}

- doobj_vardnsrecdegspspol_reference:(obj_vardnsrecdegspspol_c *)aReference
{
  obj_vardnsrecdegspspol_move (&value, aReference, obj_vardnsrecdegspspol_getargs (self));
  assert ([self check]);
  return self;
}

- obj_vardnsrecdegspspol_reference:(obj_vardnsrecdegspspol_c *)aReference
{
  return [[self clone] doobj_vardnsrecdegspspol_reference:aReference];
}

- copy
{
  obj_vardnsrecdegspspol_c c;
  assert ([self check]);
  obj_vardnsrecdegspspol_copy (&c, &value, obj_vardnsrecdegspspol_getargs (self));
  return obj_vardnsrecdegspspol_c2id (self, &c);
}

- deepCopy
{
  obj_vardnsrecdegspspol_c c;
  assert ([self check]);
  obj_vardnsrecdegspspol_deepcopy (&c, &value, obj_vardnsrecdegspspol_getargs (self));
  return obj_vardnsrecdegspspol_c2id (self, &c);
}

- (BOOL) isEmpty
{
  return obj_vardnsrecdegspspol_isempty (&value);
}

- (BOOL) isOne
{
  return obj_vardnsrecdegspspol_isone (&value, obj_vardnsrecdegspspol_getargs (self));
}

- (BOOL) isMinusOne
{
  return obj_vardnsrecdegspspol_isminusone (&value, obj_vardnsrecdegspspol_getargs (self));
}

- (unsigned) hash
{
  return obj_vardnsrecdegspspol_hash (obj_vardnsrecdegspspol_id2t (self), obj_vardnsrecdegspspol_getargs (self));
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
      return obj_vardnsrecdegspspol_iseq (obj_vardnsrecdegspspol_id2t (self), obj_vardnsrecdegspspol_id2t (b), obj_vardnsrecdegspspol_getargs (self));
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
      return !obj_vardnsrecdegspspol_iseq (obj_vardnsrecdegspspol_id2t (self), obj_vardnsrecdegspspol_id2t (b), obj_vardnsrecdegspspol_getargs (self));
    }
}

- (BOOL) isZero
{
  assert ([self check]);
  return obj_vardnsrecdegspspol_iszero (obj_vardnsrecdegspspol_id2t (self), obj_vardnsrecdegspspol_getargs (self));
}

- (BOOL) notZero
{
  assert ([self check]);
  return !obj_vardnsrecdegspspol_iszero (obj_vardnsrecdegspspol_id2t (self), obj_vardnsrecdegspspol_getargs (self));
}

- (BOOL) isOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return obj_vardnsrecdegspspol_isop (obj_vardnsrecdegspspol_id2t (self), obj_vardnsrecdegspspol_id2t (b), obj_vardnsrecdegspspol_getargs (self));
}

- (BOOL) notOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return !obj_vardnsrecdegspspol_isop (obj_vardnsrecdegspspol_id2t (self), obj_vardnsrecdegspspol_id2t (b), obj_vardnsrecdegspspol_getargs (self));
}

- negate
{
  obj_vardnsrecdegspspol_c c;
  assert ([self check]);
  obj_vardnsrecdegspspol_ooneg (&c, obj_vardnsrecdegspspol_id2t (self), obj_vardnsrecdegspspol_getargs (self));
  return obj_vardnsrecdegspspol_c2id (self, &c);
}

- _double:(int)v
{
  obj_vardnsrecdegspspol_c c;
  assert ([self check]);
  obj_vardnsrecdegspspol_oodbl (&c, obj_vardnsrecdegspspol_id2t (self), v, obj_vardnsrecdegspspol_getargs (self));
  return obj_vardnsrecdegspspol_c2id (self, &c);
}

- double
{
  obj_vardnsrecdegspspol_c c;
  assert ([self check]);
  obj_vardnsrecdegspspol_oodbl (&c, obj_vardnsrecdegspspol_id2t (self), +1, obj_vardnsrecdegspspol_getargs (self));
  return obj_vardnsrecdegspspol_c2id (self, &c);
}

- _add:(int)v:b:(int)w
{
  obj_vardnsrecdegspspol_c c;
  assert ([self sameClass:b] && v * v == 1 && w * w == 1 && self != b);
  obj_vardnsrecdegspspol_ooadd (&c, obj_vardnsrecdegspspol_id2t (self), v, obj_vardnsrecdegspspol_id2t (b), w, obj_vardnsrecdegspspol_getargs (self));
  return obj_vardnsrecdegspspol_c2id (self, &c);
}

- add:b
{
  obj_vardnsrecdegspspol_c c;
  assert ([self checkSameClass:b] && self != b);
  obj_vardnsrecdegspspol_ooadd (&c, obj_vardnsrecdegspspol_id2t (self), +1, obj_vardnsrecdegspspol_id2t (b), +1, obj_vardnsrecdegspspol_getargs (self));
  return obj_vardnsrecdegspspol_c2id (self, &c);
}

- subtract:b
{
  obj_vardnsrecdegspspol_c c;
  assert ([self checkSameClass:b] && self != b);
  obj_vardnsrecdegspspol_ooadd (&c, obj_vardnsrecdegspspol_id2t (self), +1, obj_vardnsrecdegspspol_id2t (b), -1, obj_vardnsrecdegspspol_getargs (self));
  return obj_vardnsrecdegspspol_c2id (self, &c);
}

- (int) leadingDegree
{
  return obj_vardnsrecdegspspol_deg (&value, obj_vardnsrecdegspspol_getargs (self));
}

- (int) lastDegree
{
  return obj_vardnsrecdegspspol_ord (&value, obj_vardnsrecdegspspol_getargs (self));
}

- (int) maxDegree
{
  return obj_vardnsrecdegspspol_maxdeg (&value, obj_vardnsrecdegspspol_getargs (self));
}

- (int) minDegree
{
  return obj_vardnsrecdegspspol_mindeg (&value, obj_vardnsrecdegspspol_getargs (self));
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

  obj_vardnsrecdegspspol_check (&value, obj_vardnsrecdegspspol_getargs (self));
  return self;
}

- release
{
  obj_vardnsrecdegspspol_clear (&value, obj_vardnsrecdegspspol_getargs (self));
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
  id aSequence = [obj_vardnsrecdegspspol_sequence content:self];
  return [CASequence over:aSequence];
}

- elt_obj_vardnsrecdegspspol_ix:(obj_vardnsrecdegspspol_ixt)ix
{
  if (obj_vardnsrecdegspspol_ix_ismatch (ix))
    {
      id c, s;
      int e;
      obj_t t;
      t = obj_vardnsrecdegspspol_scalat (&value, ix, obj_vardnsrecdegspspol_getargs (self));
      e = obj_vardnsrecdegspspol_expat (&value, ix, obj_vardnsrecdegspspol_getargs (self));
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

      t = obj_vardnsrecdegspspol_scalfirst (&value, obj_vardnsrecdegspspol_getargs (self));
      e = obj_vardnsrecdegspspol_expfirst (&value, obj_vardnsrecdegspspol_getargs (self));
      c = obj_t2id ([termZero coefficient], t);
      s = (e) ? [termZero symbol] : nil;
      lt = [termZero coefficient:c symbol:s exponent:e];

      obj_vardnsrecdegspspol_remove (&value, obj_vardnsrecdegspspol_getargs (self));
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
      obj_vardnsrecdegspspol_insert (&value, e, r, obj_vardnsrecdegspspol_getargs (self));
      assert ([aTerm check]);
      [self invalidate];
      assert ([self check]);
      return self;
    }
}

- multiplyCoefficient:s
{
  obj_vardnsrecdegspspol_c c;
  obj_c sc;
  obj_vardnsrecdegspspol_oomulsc (&c, obj_vardnsrecdegspspol_id2t (self), obj_id2ref (s, &sc), obj_vardnsrecdegspspol_getargs (self));
  return obj_vardnsrecdegspspol_c2id (self, &c);
}

- divideCoefficient:s
{
  obj_vardnsrecdegspspol_c c;
  obj_c sc;
  BOOL failed = obj_vardnsrecdegspspol_oodivsc (&c, obj_vardnsrecdegspspol_id2t (self), obj_id2ref (s, &sc), obj_vardnsrecdegspspol_getargs (self));
  return (failed) ? nil : obj_vardnsrecdegspspol_c2id (self, &c);
}

- _add:(int)v:B multiplyCoefficient:b:(int)w
{
  obj_vardnsrecdegspspol_c c;
  obj_c bc;
  obj_vardnsrecdegspspol_ooaddmulsc (&c, obj_vardnsrecdegspspol_id2t (self), v, obj_vardnsrecdegspspol_id2t (B), obj_id2ref (b, &bc), w, obj_vardnsrecdegspspol_getargs (self));
  return obj_vardnsrecdegspspol_c2id (self, &c);
}

- _multiplyCoefficient:a:(int)v add:B:(int)w
{
  obj_vardnsrecdegspspol_c c;
  obj_c ac;
  obj_vardnsrecdegspspol_oomulscadd (&c, obj_vardnsrecdegspspol_id2t (self), obj_id2ref (a, &ac), v, obj_vardnsrecdegspspol_id2t (B), w, obj_vardnsrecdegspspol_getargs (self));
  return obj_vardnsrecdegspspol_c2id (self, &c);
}

- _multiplyCoefficient:a:(int)v add:B multiplyCoefficient:b:(int)w
{
  obj_vardnsrecdegspspol_c c;
  obj_c ac, bc;
  obj_vardnsrecdegspspol_oomulscaddmulsc (&c, obj_vardnsrecdegspspol_id2t (self), obj_id2ref (a, &ac), v, obj_vardnsrecdegspspol_id2t (B), obj_id2ref (b, &bc), w, obj_vardnsrecdegspspol_getargs (self));
  return obj_vardnsrecdegspspol_c2id (self, &c);
}

- multiplyTerm:aTerm
{
  obj_vardnsrecdegspspol_c c;
  obj_t s;
  obj_c sc;
  s = obj_id2ref ([aTerm coefficient], &sc);
  obj_vardnsrecdegspspol_oomulmonomsc (&c, obj_vardnsrecdegspspol_id2t (self), [aTerm exponent], s, +1, obj_vardnsrecdegspspol_getargs (self));
  return obj_vardnsrecdegspspol_c2id (self, &c);
}

- _multiplyTerm:aTerm:(int)v
{
  obj_vardnsrecdegspspol_c c;
  obj_t s;
  obj_c sc;
  s = obj_id2ref ([aTerm coefficient], &sc);
  obj_vardnsrecdegspspol_oomulmonomsc (&c, obj_vardnsrecdegspspol_id2t (self), [aTerm exponent], s, v, obj_vardnsrecdegspspol_getargs (self));
  return obj_vardnsrecdegspspol_c2id (self, &c);
}

- divideTerm:aTerm
{
  int e;
  obj_vardnsrecdegspspol_c c;
  BOOL failed;
  obj_t s;
  obj_c sc;

  e = [aTerm exponent];
  s = obj_id2ref ([aTerm coefficient], &sc);
  failed = obj_vardnsrecdegspspol_oodivmonomsc (&c, obj_vardnsrecdegspspol_id2t (self), e, s, obj_vardnsrecdegspspol_getargs (self));
  return (failed) ? nil : obj_vardnsrecdegspspol_c2id (self, &c);
}

- _add:(int)v:B multiplyTerm:b:(int)w
{
  obj_vardnsrecdegspspol_c c;
  obj_c bc;
  obj_t bs;
  bs = obj_id2ref ([b coefficient], &bc);
  obj_vardnsrecdegspspol_ooaddmulmonomsc (&c, obj_vardnsrecdegspspol_id2c (self), v, obj_vardnsrecdegspspol_id2t (B), [b exponent], bs, w, obj_vardnsrecdegspspol_getargs (self));
  return obj_vardnsrecdegspspol_c2id (self, &c);
}

- _multiplyCoefficient:a:(int)v add:B multiplyTerm:b:(int)w
{
  obj_vardnsrecdegspspol_c c;
  obj_c ac, bc;
  obj_t as, bs;
  as = obj_id2ref (a, &ac);
  bs = obj_id2ref ([b coefficient], &bc);
  obj_vardnsrecdegspspol_oomulscaddmulmonomsc (&c, obj_vardnsrecdegspspol_id2c (self), as, v, obj_vardnsrecdegspspol_id2t (B), [b exponent], bs, w, obj_vardnsrecdegspspol_getargs (self));
  return obj_vardnsrecdegspspol_c2id (self, &c);
}


- fileOutOn:aFiler
{
  obj_vardnsrecdegspspol_args args;
  [super fileOutOn:aFiler];
  args = obj_vardnsrecdegspspol_getargs (self);		/* can't do this in fileIn case */
  obj_vardnsrecdegspspol_args_fileOut (aFiler, &args);
  obj_vardnsrecdegspspol_fileOut (aFiler, &value, args);
  return self;
}

- fileInFrom:aFiler
{
  obj_vardnsrecdegspspol_args args;
  [super fileInFrom:aFiler];
  obj_vardnsrecdegspspol_args_fileIn (aFiler, &args);
  obj_vardnsrecdegspspol_fileIn (aFiler, &value, args);
  return self;
}

@end
 
