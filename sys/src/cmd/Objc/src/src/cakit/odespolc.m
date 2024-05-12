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
 * $Id: odespolc.m,v 1.6 2000/10/12 14:40:26 stes Exp $
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
obj_vardnsexpdegspsterm_monom_cval (obj_vardnsexpdegspsterm_t self)
{
  return &self->data;
}

static vardnsmonom_t 
obj_vardnsexpdegspsterm_monom (obj_vardnsexpdegspsterm_t self)
{
#if vardnsmonom_pervalue
  return self->data;
#else
  return obj_vardnsexpdegspsterm_monom_cval (self);
#endif
}

/* stes - mar31,1997
 * change for DEC alpha to exclude varsized scalars
 */

static obj_c *
obj_vardnsexpdegspsterm_scal_cval (obj_vardnsexpdegspsterm_t self, obj_vardnsexpdegspsterm_args args)
{
  return &self->scal;
}

static obj_t 
obj_vardnsexpdegspsterm_scal (obj_vardnsexpdegspsterm_t self, obj_vardnsexpdegspsterm_args args)
{
#if obj_pervalue
  return self->scal;
#else
  return obj_vardnsexpdegspsterm_scal_cval (self, args);
#endif
}

static int 
obj_vardnsexpdegspsterm_check (obj_vardnsexpdegspsterm_t self, obj_vardnsexpdegspsterm_args args)
{
  assert (obj_check (obj_vardnsexpdegspsterm_scal (self, args), args.sargs));
  assert (!obj_iszero (obj_vardnsexpdegspsterm_scal (self, args), args.sargs));
  assert (vardnsmonom_check (obj_vardnsexpdegspsterm_monom (self), args.margs));
  return 1;
}

static int 
obj_vardnsexpdegspsterm_bsize (obj_vardnsexpdegspsterm_args args)
{
  /* this is sizeof(vardnsmonom_c) too much but why bother ? */
  return sizeof (struct obj_vardnsexpdegspsterm) + vardnsmonom_bsize (args.margs);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_alloc (obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_t p;
  int n = obj_vardnsexpdegspsterm_bsize (args);
  p = (obj_vardnsexpdegspsterm_t) OC_Malloc (n);
#if OBJC_REFCNT
  memset (p, 0, n);
#endif
  return p;
}

static void 
obj_vardnsexpdegspsterm_clear (obj_vardnsexpdegspsterm_t self, obj_vardnsexpdegspsterm_args args)
{
  vardnsmonom_clear (obj_vardnsexpdegspsterm_monom_cval (self), args.margs);
  obj_clear (obj_vardnsexpdegspsterm_scal_cval (self, args), args.sargs);
}

static void 
obj_vardnsexpdegspsterm_free (obj_vardnsexpdegspsterm_t self, obj_vardnsexpdegspsterm_args args)
{
  /* invalidating links not always helps : buggy code might work because
   * links were cleared...        self->nlink = NULL;self->plink = NULL;
   */
  OC_Free (self);
}

static int 
obj_vardnsexpdegspsterm_cmp (obj_vardnsexpdegspsterm_t a, obj_vardnsexpdegspsterm_t b, obj_vardnsexpdegspsterm_args args)
{
  assert (obj_vardnsexpdegspsterm_check (a, args) && obj_vardnsexpdegspsterm_check (b, args));
  return vardnsmonom_cmp (obj_vardnsexpdegspsterm_monom (a), obj_vardnsexpdegspsterm_monom (b), args.margs);
}

static int 
obj_vardnsexpdegspsterm_cmpmonom (obj_vardnsexpdegspsterm_t a, vardnsmonom_t b, obj_vardnsexpdegspsterm_args args)
{
  assert (obj_vardnsexpdegspsterm_check (a, args) && vardnsmonom_check (b, args.margs));
  return vardnsmonom_cmp (obj_vardnsexpdegspsterm_monom (a), b, args.margs);
}

static int 
obj_vardnsexpdegspsterm_cmpmul (obj_vardnsexpdegspsterm_t a, obj_vardnsexpdegspsterm_t b, vardnsmonom_t m, obj_vardnsexpdegspsterm_args args)
{
  assert (obj_vardnsexpdegspsterm_check (a, args) && obj_vardnsexpdegspsterm_check (b, args));
  assert (vardnsmonom_check (m, args.margs));
  return vardnsmonom_cmpmul (obj_vardnsexpdegspsterm_monom (a), obj_vardnsexpdegspsterm_monom (b), m, args.margs);
}

static int 
obj_vardnsexpdegspsterm_deg (obj_vardnsexpdegspsterm_t a, obj_vardnsexpdegspsterm_args args)
{
  return vardnsmonom_deg (obj_vardnsexpdegspsterm_monom (a), args.margs);
}

static int 
obj_vardnsexpdegspsterm_iszero (obj_vardnsexpdegspsterm_t self, obj_vardnsexpdegspsterm_args args)
{
  return obj_iszero (obj_vardnsexpdegspsterm_scal (self, args), args.sargs);
}

static int 
obj_vardnsexpdegspsterm_isone (obj_vardnsexpdegspsterm_t self, obj_vardnsexpdegspsterm_args args)
{
  return obj_isone (obj_vardnsexpdegspsterm_scal (self, args), args.sargs) && vardnsmonom_isone (obj_vardnsexpdegspsterm_monom (self), args.margs);
}

static int 
obj_vardnsexpdegspsterm_isminusone (obj_vardnsexpdegspsterm_t self, obj_vardnsexpdegspsterm_args args)
{
  return obj_isminusone (obj_vardnsexpdegspsterm_scal (self, args), args.sargs) && vardnsmonom_isone (obj_vardnsexpdegspsterm_monom (self), args.margs);
}

static int 
obj_vardnsexpdegspsterm_iseq (obj_vardnsexpdegspsterm_t a, obj_vardnsexpdegspsterm_t b, obj_vardnsexpdegspsterm_args args)
{
  assert (obj_vardnsexpdegspsterm_check (a, args) && obj_vardnsexpdegspsterm_check (b, args));
  return vardnsmonom_iseq (obj_vardnsexpdegspsterm_monom (a), obj_vardnsexpdegspsterm_monom (b), args.margs) && obj_iseq (obj_vardnsexpdegspsterm_scal (a, args), obj_vardnsexpdegspsterm_scal (b, args), args.sargs);
}

static int 
obj_vardnsexpdegspsterm_isop (obj_vardnsexpdegspsterm_t a, obj_vardnsexpdegspsterm_t b, obj_vardnsexpdegspsterm_args args)
{
  assert (obj_vardnsexpdegspsterm_check (a, args) && obj_vardnsexpdegspsterm_check (b, args));
  return vardnsmonom_iseq (obj_vardnsexpdegspsterm_monom (a), obj_vardnsexpdegspsterm_monom (b), args.margs) && obj_isop (obj_vardnsexpdegspsterm_scal (a, args), obj_vardnsexpdegspsterm_scal (b, args), args.sargs);
}

static void 
obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A)
{
  C->nlink = A;
  A->plink = C;
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A)
{
  obj_vardnsexpdegspsterm_glue (C, A);
  return A;
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_delete (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_t C = A->nlink;
  obj_vardnsexpdegspsterm_glue (A->plink, C);
  obj_vardnsexpdegspsterm_clear (A, args);
  obj_vardnsexpdegspsterm_free (A, args);
  return C;
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_condcns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t new, obj_vardnsexpdegspsterm_args args)
{
  if (obj_vardnsexpdegspsterm_iszero (new, args))
    {
      obj_vardnsexpdegspsterm_clear (new, args);
      obj_vardnsexpdegspsterm_free (new, args);
      return C;
    }
  else
    {
      assert (obj_vardnsexpdegspsterm_check (new, args));
      return obj_vardnsexpdegspsterm_cns (C, new);
    }
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_conddelete (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_args args)
{
  if (obj_vardnsexpdegspsterm_iszero (A, args))
    {
      return obj_vardnsexpdegspsterm_delete (A, args);
    }
  else
    {
      return A->nlink;
    }
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_copymonomsc_cns (obj_vardnsexpdegspsterm_t C, vardnsmonom_t m, obj_t s, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_t new = obj_vardnsexpdegspsterm_alloc (args);

  obj_copy (obj_vardnsexpdegspsterm_scal_cval (new, args), s, args.sargs);
  vardnsmonom_copy (obj_vardnsexpdegspsterm_monom_cval (new), m, args.margs);

  assert (obj_vardnsexpdegspsterm_check (new, args));
  return obj_vardnsexpdegspsterm_cns (C, new);
}

static void 
obj_vardnsexpdegspsterm_copymonomsc (obj_vardnsexpdegspsterm_t C, vardnsmonom_t m, obj_t s, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspsterm_copymonomsc_cns (C, m, s, args), CT);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_deepcopymonomsc_cns (obj_vardnsexpdegspsterm_t C, vardnsmonom_t m, obj_t s, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_t new = obj_vardnsexpdegspsterm_alloc (args);

  obj_deepcopy (obj_vardnsexpdegspsterm_scal_cval (new, args), s, args.sargs);
  vardnsmonom_copy (obj_vardnsexpdegspsterm_monom_cval (new), m, args.margs);

  assert (obj_vardnsexpdegspsterm_check (new, args));
  return obj_vardnsexpdegspsterm_cns (C, new);
}

static void 
obj_vardnsexpdegspsterm_deepcopymonomsc (obj_vardnsexpdegspsterm_t C, vardnsmonom_t m, obj_t s, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspsterm_deepcopymonomsc_cns (C, m, s, args), CT);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_copy_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_args args)
{
  return obj_vardnsexpdegspsterm_copymonomsc_cns (C, obj_vardnsexpdegspsterm_monom (A), obj_vardnsexpdegspsterm_scal (A, args), args);
}

static void 
obj_vardnsexpdegspsterm_copy (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspsterm_copy_cns (C, A, args), CT);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_deepcopy_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_args args)
{
  return obj_vardnsexpdegspsterm_deepcopymonomsc_cns (C, obj_vardnsexpdegspsterm_monom (A), obj_vardnsexpdegspsterm_scal (A, args), args);
}

static void 
obj_vardnsexpdegspsterm_deepcopy (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspsterm_deepcopy_cns (C, A, args), CT);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_ooneg_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_t new = obj_vardnsexpdegspsterm_alloc (args);
  assert (obj_vardnsexpdegspsterm_iszero (A, args) == NO);

  obj_ooneg (obj_vardnsexpdegspsterm_scal_cval (new, args), obj_vardnsexpdegspsterm_scal (A, args), args.sargs);
  vardnsmonom_copy (obj_vardnsexpdegspsterm_monom_cval (new), obj_vardnsexpdegspsterm_monom (A), args.margs);

  return obj_vardnsexpdegspsterm_cns (C, new);
}

static void 
obj_vardnsexpdegspsterm_ooneg (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspsterm_ooneg_cns (C, A, args), CT);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_inneg (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_args args)
{
  assert (obj_vardnsexpdegspsterm_iszero (A, args) == NO);
  obj_inneg (obj_vardnsexpdegspsterm_scal_cval (A, args), args.sargs);
  assert (obj_vardnsexpdegspsterm_iszero (A, args) == NO);
  return A->nlink;
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_oonegv_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, int v, obj_vardnsexpdegspsterm_args args)
{
  return (v == -1) ? obj_vardnsexpdegspsterm_ooneg_cns (C, A, args) : obj_vardnsexpdegspsterm_copy_cns (C, A, args);
}

static void 
obj_vardnsexpdegspsterm_oonegv (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, int v, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspsterm_oonegv_cns (C, A, v, args), CT);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_innegv (obj_vardnsexpdegspsterm_t A, int v, obj_vardnsexpdegspsterm_args args)
{
  return (v == -1) ? obj_vardnsexpdegspsterm_inneg (A, args) : A->nlink;
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_oodbl_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, int v, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_t new = obj_vardnsexpdegspsterm_alloc (args);
  assert (obj_vardnsexpdegspsterm_iszero (A, args) == NO);

  obj_oodbl (obj_vardnsexpdegspsterm_scal_cval (new, args), obj_vardnsexpdegspsterm_scal (A, args), v, args.sargs);
  vardnsmonom_copy (obj_vardnsexpdegspsterm_monom_cval (new), obj_vardnsexpdegspsterm_monom (A), args.margs);

  return obj_vardnsexpdegspsterm_condcns (C, new, args);
}

static void 
obj_vardnsexpdegspsterm_oodbl (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, int v, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspsterm_oodbl_cns (C, A, v, args), CT);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_indbl (obj_vardnsexpdegspsterm_t A, int v, obj_vardnsexpdegspsterm_args args)
{
  assert (obj_vardnsexpdegspsterm_iszero (A, args) == NO);
  obj_indbl (obj_vardnsexpdegspsterm_scal_cval (A, args), v, args.sargs);
  return obj_vardnsexpdegspsterm_conddelete (A, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_ooaddsc_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, int v, obj_t B, int w, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_t new = obj_vardnsexpdegspsterm_alloc (args);
  obj_ooadd (obj_vardnsexpdegspsterm_scal_cval (new, args), obj_vardnsexpdegspsterm_scal (A, args), v, B, w, args.sargs);
  vardnsmonom_copy (obj_vardnsexpdegspsterm_monom_cval (new), obj_vardnsexpdegspsterm_monom (A), args.margs);
  return obj_vardnsexpdegspsterm_condcns (C, new, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_inaddsc (obj_vardnsexpdegspsterm_t A, int v, obj_t B, int w, obj_vardnsexpdegspsterm_args args)
{
  obj_inadd (obj_vardnsexpdegspsterm_scal_cval (A, args), v, B, w, args.sargs);
  return obj_vardnsexpdegspsterm_conddelete (A, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_ooadd_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, int v, obj_vardnsexpdegspsterm_t B, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (0 == obj_vardnsexpdegspsterm_cmp (A, B, args));
  assert (obj_vardnsexpdegspsterm_iszero (A, args) == NO && obj_vardnsexpdegspsterm_iszero (B, args) == NO);
  return obj_vardnsexpdegspsterm_ooaddsc_cns (C, A, v, obj_vardnsexpdegspsterm_scal (B, args), w, args);
}

static void 
obj_vardnsexpdegspsterm_ooadd (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, int v, obj_vardnsexpdegspsterm_t B, int w, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspsterm_ooadd_cns (C, A, v, B, w, args), CT);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_inadd (obj_vardnsexpdegspsterm_t A, int v, obj_vardnsexpdegspsterm_t B, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (0 == obj_vardnsexpdegspsterm_cmp (A, B, args));
  assert (obj_vardnsexpdegspsterm_iszero (A, args) == NO && obj_vardnsexpdegspsterm_iszero (B, args) == NO);
  return obj_vardnsexpdegspsterm_inaddsc (A, v, obj_vardnsexpdegspsterm_scal (B, args), w, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_oomulsc_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_t s, int v, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_t new = obj_vardnsexpdegspsterm_alloc (args);

  obj_oomulv (obj_vardnsexpdegspsterm_scal_cval (new, args), obj_vardnsexpdegspsterm_scal (A, args), s, v, args.sargs);
  vardnsmonom_copy (obj_vardnsexpdegspsterm_monom_cval (new), obj_vardnsexpdegspsterm_monom (A), args.margs);

  return obj_vardnsexpdegspsterm_condcns (C, new, args);
}

static void 
obj_vardnsexpdegspsterm_oomulsc (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_t s, int v, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspsterm_oomulsc_cns (C, A, s, v, args), CT);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_inmulsc (obj_vardnsexpdegspsterm_t A, obj_t s, int v, obj_vardnsexpdegspsterm_args args)
{
  obj_inmulv (obj_vardnsexpdegspsterm_scal_cval (A, args), s, v, args.sargs);
  return obj_vardnsexpdegspsterm_conddelete (A, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_oomulmonomsc_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, vardnsmonom_t m, obj_t s, int v, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_t new = obj_vardnsexpdegspsterm_alloc (args);

  obj_oomulv (obj_vardnsexpdegspsterm_scal_cval (new, args), obj_vardnsexpdegspsterm_scal (A, args), s, v, args.sargs);
  vardnsmonom_oomul (obj_vardnsexpdegspsterm_monom_cval (new), obj_vardnsexpdegspsterm_monom (A), m, args.margs);

  return obj_vardnsexpdegspsterm_condcns (C, new, args);
}

static void 
obj_vardnsexpdegspsterm_oomulmonomsc (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, vardnsmonom_t m, obj_t s, int v, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspsterm_oomulmonomsc_cns (C, A, m, s, v, args), CT);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_inmulmonomsc (obj_vardnsexpdegspsterm_t A, vardnsmonom_t m, obj_t s, int v, obj_vardnsexpdegspsterm_args args)
{
  obj_inmulv (obj_vardnsexpdegspsterm_scal_cval (A, args), s, v, args.sargs);
  vardnsmonom_inmul (obj_vardnsexpdegspsterm_monom_cval (A), m, args.margs);

  return obj_vardnsexpdegspsterm_conddelete (A, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_ooaddscmulsc_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, int v, obj_t B, obj_t t, int w, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_t new = obj_vardnsexpdegspsterm_alloc (args);

  obj_ooaddmul (obj_vardnsexpdegspsterm_scal_cval (new, args), obj_vardnsexpdegspsterm_scal (A, args), v, B, t, w, args.sargs);
  vardnsmonom_copy (obj_vardnsexpdegspsterm_monom_cval (new), obj_vardnsexpdegspsterm_monom (A), args.margs);

  return obj_vardnsexpdegspsterm_condcns (C, new, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_inaddscmulsc (obj_vardnsexpdegspsterm_t A, int v, obj_t B, obj_t t, int w, obj_vardnsexpdegspsterm_args args)
{
  obj_inaddmul (obj_vardnsexpdegspsterm_scal_cval (A, args), v, B, t, w, args.sargs);
  return obj_vardnsexpdegspsterm_conddelete (A, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_ooaddmulsc_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, int v, obj_vardnsexpdegspsterm_t B, obj_t t, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (0 == (obj_vardnsexpdegspsterm_cmp (A, B, args)));
  return obj_vardnsexpdegspsterm_ooaddscmulsc_cns (C, A, v, obj_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_ooaddmulmonomsc_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, int v, obj_vardnsexpdegspsterm_t B, vardnsmonom_t m, obj_t t, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (0 == (obj_vardnsexpdegspsterm_cmpmul (A, B, m, args)));
  return obj_vardnsexpdegspsterm_ooaddscmulsc_cns (C, A, v, obj_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static void 
obj_vardnsexpdegspsterm_ooaddmulsc (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, int v, obj_vardnsexpdegspsterm_t B, obj_t t, int w, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspsterm_ooaddmulsc_cns (C, A, v, B, t, w, args), CT);
}

static void 
obj_vardnsexpdegspsterm_ooaddmulmonomsc (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, int v, obj_vardnsexpdegspsterm_t B, vardnsmonom_t m, obj_t t, int w, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspsterm_ooaddmulmonomsc_cns (C, A, v, B, m, t, w, args), CT);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_inaddmulsc (obj_vardnsexpdegspsterm_t A, int v, obj_vardnsexpdegspsterm_t B, obj_t t, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (0 == (obj_vardnsexpdegspsterm_cmp (A, B, args)));
  return obj_vardnsexpdegspsterm_inaddscmulsc (A, v, obj_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_inaddmulmonomsc (obj_vardnsexpdegspsterm_t A, int v, obj_vardnsexpdegspsterm_t B, vardnsmonom_t m, obj_t t, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (0 == (obj_vardnsexpdegspsterm_cmpmul (A, B, m, args)));
  return obj_vardnsexpdegspsterm_inaddscmulsc (A, v, obj_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_oomulscaddsc_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_t s, int v, obj_t B, int w, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_t new = obj_vardnsexpdegspsterm_alloc (args);

  obj_oomuladd (obj_vardnsexpdegspsterm_scal_cval (new, args), obj_vardnsexpdegspsterm_scal (A, args), s, v, B, w, args.sargs);
  vardnsmonom_copy (obj_vardnsexpdegspsterm_monom_cval (new), obj_vardnsexpdegspsterm_monom (A), args.margs);

  return obj_vardnsexpdegspsterm_condcns (C, new, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_inmulscaddsc (obj_vardnsexpdegspsterm_t A, obj_t s, int v, obj_t B, int w, obj_vardnsexpdegspsterm_args args)
{
  obj_inmuladd (obj_vardnsexpdegspsterm_scal_cval (A, args), s, v, B, w, args.sargs);
  return obj_vardnsexpdegspsterm_conddelete (A, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_oomulscadd_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_t s, int v, obj_vardnsexpdegspsterm_t B, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (0 == (obj_vardnsexpdegspsterm_cmp (A, B, args)));
  return obj_vardnsexpdegspsterm_oomulscaddsc_cns (C, A, s, v, obj_vardnsexpdegspsterm_scal (B, args), w, args);
}

static void 
obj_vardnsexpdegspsterm_oomulscadd (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_t s, int v, obj_vardnsexpdegspsterm_t B, int w, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspsterm_oomulscadd_cns (C, A, s, v, B, w, args), CT);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_inmulscadd (obj_vardnsexpdegspsterm_t A, obj_t s, int v, obj_vardnsexpdegspsterm_t B, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (0 == (obj_vardnsexpdegspsterm_cmp (A, B, args)));
  return obj_vardnsexpdegspsterm_inmulscaddsc (A, s, v, obj_vardnsexpdegspsterm_scal (B, args), w, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_oomulscaddscmulsc_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_t s, int v, obj_t B, obj_t t, int w, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_t new = obj_vardnsexpdegspsterm_alloc (args);
  obj_oomuladdmul (obj_vardnsexpdegspsterm_scal_cval (new, args), obj_vardnsexpdegspsterm_scal (A, args), s, v, B, t, w, args.sargs);
  vardnsmonom_copy (obj_vardnsexpdegspsterm_monom_cval (new), obj_vardnsexpdegspsterm_monom (A), args.margs);

  return obj_vardnsexpdegspsterm_condcns (C, new, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_inmulscaddscmulsc (obj_vardnsexpdegspsterm_t A, obj_t s, int v, obj_t B, obj_t t, int w, obj_vardnsexpdegspsterm_args args)
{
  obj_inmuladdmul (obj_vardnsexpdegspsterm_scal_cval (A, args), s, v, B, t, w, args.sargs);
  return obj_vardnsexpdegspsterm_conddelete (A, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_oomulscaddmulsc_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_t s, int v, obj_vardnsexpdegspsterm_t B, obj_t t, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (0 == (obj_vardnsexpdegspsterm_cmp (A, B, args)));
  return obj_vardnsexpdegspsterm_oomulscaddscmulsc_cns (C, A, s, v, obj_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_oomulscaddmulmonomsc_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_t s, int v, obj_vardnsexpdegspsterm_t B, vardnsmonom_t m, obj_t t, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (0 == (obj_vardnsexpdegspsterm_cmpmul (A, B, m, args)));
  return obj_vardnsexpdegspsterm_oomulscaddscmulsc_cns (C, A, s, v, obj_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static void 
obj_vardnsexpdegspsterm_oomulscaddmulsc (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_t s, int v, obj_vardnsexpdegspsterm_t B, obj_t t, int w, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspsterm_oomulscaddmulsc_cns (C, A, s, v, B, t, w, args), CT);
}

static void 
obj_vardnsexpdegspsterm_oomulscaddmulmonomsc (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_t s, int v, obj_vardnsexpdegspsterm_t B, vardnsmonom_t m, obj_t t, int w, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspsterm_oomulscaddmulmonomsc_cns (C, A, s, v, B, m, t, w, args), CT);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_inmulscaddmulsc (obj_vardnsexpdegspsterm_t A, obj_t s, int v, obj_vardnsexpdegspsterm_t B, obj_t t, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (0 == (obj_vardnsexpdegspsterm_cmp (A, B, args)));
  return obj_vardnsexpdegspsterm_inmulscaddscmulsc (A, s, v, obj_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_inmulscaddmulmonomsc (obj_vardnsexpdegspsterm_t A, obj_t s, int v, obj_vardnsexpdegspsterm_t B, vardnsmonom_t m, obj_t t, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (0 == (obj_vardnsexpdegspsterm_cmpmul (A, B, m, args)));
  return obj_vardnsexpdegspsterm_inmulscaddscmulsc (A, s, v, obj_vardnsexpdegspsterm_scal (B, args), t, w, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_oodivsc_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_t s, obj_vardnsexpdegspsterm_args args)
{
  BOOL failed;
  obj_vardnsexpdegspsterm_t new = obj_vardnsexpdegspsterm_alloc (args);

  failed = obj_oodiv (obj_vardnsexpdegspsterm_scal_cval (new, args), obj_vardnsexpdegspsterm_scal (A, args), s, args.sargs);
  if (failed)
    {
      obj_vardnsexpdegspsterm_free (new, args);
      return NULL;
    }

  vardnsmonom_copy (obj_vardnsexpdegspsterm_monom_cval (new), obj_vardnsexpdegspsterm_monom (A), args.margs);

  return obj_vardnsexpdegspsterm_condcns (C, new, args);
}

#if 0				/* unused ! why did I write this ? */
static BOOL 
obj_vardnsexpdegspsterm_oodivsc (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_t s, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  if ((C = obj_vardnsexpdegspsterm_oodivsc_cns (C, A, s, args)))
    {
      obj_vardnsexpdegspsterm_glue (C, CT);
      return SUCCESS;
    }
  else
    {
      return FAILURE;
    }
}
#endif

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_indivsc (obj_vardnsexpdegspsterm_t A, obj_t s, obj_vardnsexpdegspsterm_args args)
{
  obj_indiv (obj_vardnsexpdegspsterm_scal_cval (A, args), s, args.sargs);
  return obj_vardnsexpdegspsterm_conddelete (A, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_oodivmonomsc_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, vardnsmonom_t m, obj_t s, obj_vardnsexpdegspsterm_args args)
{
  BOOL sfailed, mfailed;
  obj_vardnsexpdegspsterm_t new = obj_vardnsexpdegspsterm_alloc (args);

  sfailed = obj_oodiv (obj_vardnsexpdegspsterm_scal_cval (new, args), obj_vardnsexpdegspsterm_scal (A, args), s, args.sargs);
  mfailed = vardnsmonom_oodiv (obj_vardnsexpdegspsterm_monom_cval (new), obj_vardnsexpdegspsterm_monom (A), m, args.margs);

  if (sfailed || mfailed)
    {
      /* both failures are possible in the multivariate case */
      obj_vardnsexpdegspsterm_free (new, args);
      return NULL;
    }

  return obj_vardnsexpdegspsterm_condcns (C, new, args);
}

#if 0				/* unused ! why did I write this ? */
static BOOL 
obj_vardnsexpdegspsterm_oodivmonomsc (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, vardnsmonom_t m, obj_t s, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  if ((C = obj_vardnsexpdegspsterm_oodivmonomsc_cns (C, A, m, s, args)))
    {
      obj_vardnsexpdegspsterm_glue (C, CT);
      return SUCCESS;
    }
  else
    {
      return FAILURE;
    }
}
#endif

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_indivmonomsc (obj_vardnsexpdegspsterm_t A, vardnsmonom_t m, obj_t s, obj_vardnsexpdegspsterm_args args)
{
  obj_indiv (obj_vardnsexpdegspsterm_scal_cval (A, args), s, args.sargs);
  vardnsmonom_indiv (obj_vardnsexpdegspsterm_monom_cval (A), m, args.margs);

  return obj_vardnsexpdegspsterm_conddelete (A, args);
}

static void 
obj_vardnsexpdegspsterm_args_fileOut (id aFiler, obj_vardnsexpdegspsterm_args * args)
{
  obj_args_fileOut (aFiler, &args->sargs);
  vardnsmonom_args_fileOut (aFiler, &args->margs);
}
static void 
obj_vardnsexpdegspsterm_args_fileIn (id aFiler, obj_vardnsexpdegspsterm_args * args)
{
  obj_args_fileIn (aFiler, &args->sargs);
  vardnsmonom_args_fileIn (aFiler, &args->margs);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_fileOut (id aFiler, obj_vardnsexpdegspsterm_t self, obj_vardnsexpdegspsterm_args args)
{
  assert (obj_vardnsexpdegspsterm_check (self, args));

  obj_fileOut (aFiler, obj_vardnsexpdegspsterm_scal_cval (self, args), args.sargs);
  vardnsmonom_fileOut (aFiler, obj_vardnsexpdegspsterm_monom_cval (self), args.margs);

  return self->nlink;
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspsterm_fileIn_cns (id aFiler, obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_t self = obj_vardnsexpdegspsterm_alloc (args);

  obj_fileIn (aFiler, obj_vardnsexpdegspsterm_scal_cval (self, args), args.sargs);
  vardnsmonom_fileIn (aFiler, obj_vardnsexpdegspsterm_monom_cval (self), args.margs);

  return obj_vardnsexpdegspsterm_cns (C, self);
}

static int 
obj_vardnsexpdegspslist_check (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_t prev;

  for (prev = NULL; A != AT; prev = A, A = A->nlink)
    {
      if (obj_vardnsexpdegspsterm_check (A, args) == 0)
	return 0;
      if (prev && obj_vardnsexpdegspsterm_cmp (prev, A, args) <= 0)
	return 0;
    }

  return 1;
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspslist_copy_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    {
      C = obj_vardnsexpdegspsterm_copy_cns (C, A, args);
      A = A->nlink;
    }
  return C;
}

static void 
obj_vardnsexpdegspslist_copy (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspslist_copy_cns (C, A, AT, args), CT);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspslist_deepcopy_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    {
      C = obj_vardnsexpdegspsterm_deepcopy_cns (C, A, args);
      A = A->nlink;
    }
  return C;
}

static void 
obj_vardnsexpdegspslist_deepcopy (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspslist_deepcopy_cns (C, A, AT, args), CT);
}

static void 
obj_vardnsexpdegspslist_clear (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    {
      obj_vardnsexpdegspsterm_clear (A, args);
      A = A->nlink;
    }
}

static void 
obj_vardnsexpdegspslist_free (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_t t;
  for (; A != AT; A = t)
    {
      t = A->nlink;
      obj_vardnsexpdegspsterm_free (A, args);
    }
}

static int 
obj_vardnsexpdegspslist_count (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT)
{
  int c = 0;
  for (; A != AT; A = A->nlink)
    c++;
  return c;
}

static unsigned 
obj_vardnsexpdegspslist_hash (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_vardnsexpdegspsterm_args args)
{
  return obj_vardnsexpdegspslist_count (A, AT);
}

static int 
obj_vardnsexpdegspslist_iseq (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_vardnsexpdegspsterm_t B, obj_vardnsexpdegspsterm_t BT, obj_vardnsexpdegspsterm_args args)
{
  for (; A != AT && B != BT; A = A->nlink, B = B->nlink)
    {
      if (!obj_vardnsexpdegspsterm_iseq (A, B, args))
	return 0;
    }
  return (A == AT && B == BT);
}

static int 
obj_vardnsexpdegspslist_isop (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_vardnsexpdegspsterm_t B, obj_vardnsexpdegspsterm_t BT, obj_vardnsexpdegspsterm_args args)
{
  for (; A != AT && B != BT; A = A->nlink, B = B->nlink)
    {
      if (!obj_vardnsexpdegspsterm_isop (A, B, args))
	return 0;
    }
  return (A == AT && B == BT);
}

static int 
obj_vardnsexpdegspslist_deg (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_vardnsexpdegspsterm_args args)
{
  return (A == AT) ? -1 : obj_vardnsexpdegspsterm_deg (A, args);
}

static int 
obj_vardnsexpdegspslist_maxdeg (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_vardnsexpdegspsterm_args args)
{
  int max = (A == AT) ? -1 : obj_vardnsexpdegspsterm_deg (A, args);
  for (A = A->nlink; A != AT; A = A->nlink)
    {
      int d = obj_vardnsexpdegspsterm_deg (A, args);
      if (max < d)
	max = d;
    }
  return max;
}

static int 
obj_vardnsexpdegspslist_ord (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_vardnsexpdegspsterm_args args)
{
  return (A == AT) ? -1 : obj_vardnsexpdegspsterm_deg (AT->plink, args);
}

static int 
obj_vardnsexpdegspslist_mindeg (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_vardnsexpdegspsterm_args args)
{
  int min = (A == AT) ? -1 : obj_vardnsexpdegspsterm_deg (A, args);
  for (A = A->nlink; A != AT; A = A->nlink)
    {
      int d = obj_vardnsexpdegspsterm_deg (A, args);
      if (min > d)
	min = d;
    }
  return min;
}

static void 
obj_vardnsexpdegspslist_insert (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, vardnsmonom_t m, obj_t s, obj_vardnsexpdegspsterm_args args)
{
  assert (obj_iszero (s, args.sargs) == NO);

  /* adding to zero */
  if (A == AT)
    {
      obj_vardnsexpdegspsterm_copymonomsc (A, m, s, A, args);
      return;
    }

  /* tail append */
  if (obj_vardnsexpdegspsterm_cmpmonom (AT->plink, m, args) > 0)
    {
      obj_vardnsexpdegspsterm_copymonomsc (AT->plink, m, s, AT, args);
      return;
    }

  /* insertion */
  while (A != AT)
    {
      int cmp = obj_vardnsexpdegspsterm_cmpmonom (A, m, args);
      if (cmp == 0)
	{
	  obj_vardnsexpdegspsterm_inaddsc (A, +1, s, +1, args);
	  return;
	}
      if (cmp < 0)
	{
	  obj_vardnsexpdegspsterm_copymonomsc (A->plink, m, s, A, args);
	  return;
	}
      A = A->nlink;
    }

  fprintf (stderr, "Shouldn't happen\n");
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspslist_ooneg_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    {
      C = obj_vardnsexpdegspsterm_ooneg_cns (C, A, args);
      A = A->nlink;
    }
  return C;
}

static void 
obj_vardnsexpdegspslist_ooneg (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspslist_ooneg_cns (C, A, AT, args), CT);
}

static void 
obj_vardnsexpdegspslist_inneg (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    A = obj_vardnsexpdegspsterm_inneg (A, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspslist_oonegv_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, int v, obj_vardnsexpdegspsterm_args args)
{
  if (v == -1)
    {
      return obj_vardnsexpdegspslist_ooneg_cns (C, A, AT, args);
    }
  else
    {
      return obj_vardnsexpdegspslist_copy_cns (C, A, AT, args);
    }
}

static void 
obj_vardnsexpdegspslist_oonegv (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, int v, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspslist_oonegv_cns (C, A, AT, v, args), CT);
}

static void 
obj_vardnsexpdegspslist_innegv (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, int v, obj_vardnsexpdegspsterm_args args)
{
  if (v == -1)
    obj_vardnsexpdegspslist_inneg (A, AT, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspslist_oodbl_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, int v, obj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    {
      C = obj_vardnsexpdegspsterm_oodbl_cns (C, A, v, args);
      A = A->nlink;
    }
  return C;
}

static void 
obj_vardnsexpdegspslist_oodbl (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, int v, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspslist_oodbl_cns (C, A, AT, v, args), CT);
}

static void 
obj_vardnsexpdegspslist_indbl (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, int v, obj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    A = obj_vardnsexpdegspsterm_indbl (A, v, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspslist_ooadd_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, int v, obj_vardnsexpdegspsterm_t B, obj_vardnsexpdegspsterm_t BT, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = obj_vardnsexpdegspsterm_ooadd_cns (C, A, v, B, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = obj_vardnsexpdegspsterm_oonegv_cns (C, B, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = obj_vardnsexpdegspsterm_oonegv_cns (C, A, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return obj_vardnsexpdegspslist_oonegv_cns (C, A, AT, v, args);
  if (B != BT)
    return obj_vardnsexpdegspslist_oonegv_cns (C, B, BT, w, args);
  return C;
}

static void 
obj_vardnsexpdegspslist_ooadd (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, int v, obj_vardnsexpdegspsterm_t B, obj_vardnsexpdegspsterm_t BT, int w, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspslist_ooadd_cns (C, A, AT, v, B, BT, w, args), CT);
}

static void 
obj_vardnsexpdegspslist_inadd (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, int v, obj_vardnsexpdegspsterm_t B, obj_vardnsexpdegspsterm_t BT, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = obj_vardnsexpdegspsterm_inadd (A, v, B, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  obj_vardnsexpdegspsterm_oonegv (A->plink, B, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = obj_vardnsexpdegspsterm_innegv (A, v, args);
	}
    }

  if (A != AT)
    obj_vardnsexpdegspslist_innegv (A, AT, v, args);
  if (B != BT)
    obj_vardnsexpdegspslist_oonegv (A->plink, B, BT, w, A, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspslist_oomulsc_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_t s, int v, obj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    {
      C = obj_vardnsexpdegspsterm_oomulsc_cns (C, A, s, v, args);
      A = A->nlink;
    }
  return C;
}

static void 
obj_vardnsexpdegspslist_oomulsc (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_t s, int v, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspslist_oomulsc_cns (C, A, AT, s, v, args), CT);
}

static void 
obj_vardnsexpdegspslist_inmulsc (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_t s, int v, obj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    A = obj_vardnsexpdegspsterm_inmulsc (A, s, v, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspslist_oomulmonomsc_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, vardnsmonom_t m, obj_t s, int v, obj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    {
      C = obj_vardnsexpdegspsterm_oomulmonomsc_cns (C, A, m, s, v, args);
      A = A->nlink;
    }
  return C;
}

static void 
obj_vardnsexpdegspslist_oomulmonomsc (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, vardnsmonom_t m, obj_t s, int v, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspslist_oomulmonomsc_cns (C, A, AT, m, s, v, args), CT);
}

static void 
obj_vardnsexpdegspslist_inmulmonomsc (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, vardnsmonom_t m, obj_t s, int v, obj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    A = obj_vardnsexpdegspsterm_inmulmonomsc (A, m, s, v, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspslist_ooaddmulsc_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, int v, obj_vardnsexpdegspsterm_t B, obj_vardnsexpdegspsterm_t BT, obj_t t, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = obj_vardnsexpdegspsterm_ooaddmulsc_cns (C, A, v, B, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = obj_vardnsexpdegspsterm_oomulsc_cns (C, B, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = obj_vardnsexpdegspsterm_oonegv_cns (C, A, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return obj_vardnsexpdegspslist_oonegv_cns (C, A, AT, v, args);
  if (B != BT)
    return obj_vardnsexpdegspslist_oomulsc_cns (C, B, BT, t, w, args);
  return C;
}

static void 
obj_vardnsexpdegspslist_ooaddmulsc (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, int v, obj_vardnsexpdegspsterm_t B, obj_vardnsexpdegspsterm_t BT, obj_t t, int w, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspslist_ooaddmulsc_cns (C, A, AT, v, B, BT, t, w, args), CT);
}

static void 
obj_vardnsexpdegspslist_inaddmulsc (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, int v, obj_vardnsexpdegspsterm_t B, obj_vardnsexpdegspsterm_t BT, obj_t t, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = obj_vardnsexpdegspsterm_inaddmulsc (A, v, B, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  obj_vardnsexpdegspsterm_oomulsc (A->plink, B, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = obj_vardnsexpdegspsterm_innegv (A, v, args);
	}
    }

  if (A != AT)
    obj_vardnsexpdegspslist_innegv (A, AT, v, args);
  if (B != BT)
    obj_vardnsexpdegspslist_oomulsc (A->plink, B, BT, t, w, A, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspslist_ooaddmulmonomsc_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, int v, obj_vardnsexpdegspsterm_t B, obj_vardnsexpdegspsterm_t BT, vardnsmonom_t m, obj_t t, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsexpdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  C = obj_vardnsexpdegspsterm_ooaddmulmonomsc_cns (C, A, v, B, m, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = obj_vardnsexpdegspsterm_oomulmonomsc_cns (C, B, m, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = obj_vardnsexpdegspsterm_oonegv_cns (C, A, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return obj_vardnsexpdegspslist_oonegv_cns (C, A, AT, v, args);
  if (B != BT)
    return obj_vardnsexpdegspslist_oomulmonomsc_cns (C, B, BT, m, t, w, args);
  return C;
}

static void 
obj_vardnsexpdegspslist_ooaddmulmonomsc (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, int v, obj_vardnsexpdegspsterm_t B, obj_vardnsexpdegspsterm_t BT, vardnsmonom_t m, obj_t t, int w, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspslist_ooaddmulmonomsc_cns (C, A, AT, v, B, BT, m, t, w, args), CT);
}

static void 
obj_vardnsexpdegspslist_inaddmulmonomsc (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, int v, obj_vardnsexpdegspsterm_t B, obj_vardnsexpdegspsterm_t BT, vardnsmonom_t m, obj_t t, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsexpdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  A = obj_vardnsexpdegspsterm_inaddmulmonomsc (A, v, B, m, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  obj_vardnsexpdegspsterm_oomulmonomsc (A->plink, B, m, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = obj_vardnsexpdegspsterm_innegv (A, v, args);
	}
    }

  if (A != AT)
    obj_vardnsexpdegspslist_innegv (A, AT, v, args);
  if (B != BT)
    obj_vardnsexpdegspslist_oomulmonomsc (A->plink, B, BT, m, t, w, A, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspslist_oomulscadd_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_t s, int v, obj_vardnsexpdegspsterm_t B, obj_vardnsexpdegspsterm_t BT, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = obj_vardnsexpdegspsterm_oomulscadd_cns (C, A, s, v, B, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = obj_vardnsexpdegspsterm_oonegv_cns (C, B, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = obj_vardnsexpdegspsterm_oomulsc_cns (C, A, s, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return obj_vardnsexpdegspslist_oomulsc_cns (C, A, AT, s, v, args);
  if (B != BT)
    return obj_vardnsexpdegspslist_oonegv_cns (C, B, BT, w, args);
  return C;
}

static void 
obj_vardnsexpdegspslist_oomulscadd (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_t s, int v, obj_vardnsexpdegspsterm_t B, obj_vardnsexpdegspsterm_t BT, int w, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspslist_oomulscadd_cns (C, A, AT, s, v, B, BT, w, args), CT);
}

static void 
obj_vardnsexpdegspslist_inmulscadd (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_t s, int v, obj_vardnsexpdegspsterm_t B, obj_vardnsexpdegspsterm_t BT, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = obj_vardnsexpdegspsterm_inmulscadd (A, s, v, B, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  obj_vardnsexpdegspsterm_oonegv (A->plink, B, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = obj_vardnsexpdegspsterm_inmulsc (A, s, v, args);
	}
    }

  if (A != AT)
    obj_vardnsexpdegspslist_inmulsc (A, AT, s, v, args);
  if (B != BT)
    obj_vardnsexpdegspslist_oonegv (A->plink, B, BT, w, A, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspslist_oomulscaddmulsc_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_t s, int v, obj_vardnsexpdegspsterm_t B, obj_vardnsexpdegspsterm_t BT, obj_t t, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  C = obj_vardnsexpdegspsterm_oomulscaddmulsc_cns (C, A, s, v, B, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = obj_vardnsexpdegspsterm_oomulsc_cns (C, B, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = obj_vardnsexpdegspsterm_oomulsc_cns (C, A, s, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return obj_vardnsexpdegspslist_oomulsc_cns (C, A, AT, s, v, args);
  if (B != BT)
    return obj_vardnsexpdegspslist_oomulsc_cns (C, B, BT, t, w, args);
  return C;
}

static void 
obj_vardnsexpdegspslist_oomulscaddmulsc (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_t s, int v, obj_vardnsexpdegspsterm_t B, obj_vardnsexpdegspsterm_t BT, obj_t t, int w, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspslist_oomulscaddmulsc_cns (C, A, AT, s, v, B, BT, t, w, args), CT);
}

static void 
obj_vardnsexpdegspslist_inmulscaddmulsc (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_t s, int v, obj_vardnsexpdegspsterm_t B, obj_vardnsexpdegspsterm_t BT, obj_t t, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsexpdegspsterm_cmp (A, B, args);
      if (cmp == 0)
	{
	  A = obj_vardnsexpdegspsterm_inmulscaddmulsc (A, s, v, B, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  obj_vardnsexpdegspsterm_oomulsc (A->plink, B, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = obj_vardnsexpdegspsterm_inmulsc (A, s, v, args);
	}
    }

  if (A != AT)
    obj_vardnsexpdegspslist_inmulsc (A, AT, s, v, args);
  if (B != BT)
    obj_vardnsexpdegspslist_oomulsc (A->plink, B, BT, t, w, A, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspslist_oomulscaddmulmonomsc_cns (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_t s, int v, obj_vardnsexpdegspsterm_t B, obj_vardnsexpdegspsterm_t BT, vardnsmonom_t m, obj_t t, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsexpdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  C = obj_vardnsexpdegspsterm_oomulscaddmulmonomsc_cns (C, A, s, v, B, m, t, w, args);
	  A = A->nlink;
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  C = obj_vardnsexpdegspsterm_oomulmonomsc_cns (C, B, m, t, w, args);
	  B = B->nlink;
	}
      else
	{
	  C = obj_vardnsexpdegspsterm_oomulsc_cns (C, A, s, v, args);
	  A = A->nlink;
	}
    }

  if (A != AT)
    return obj_vardnsexpdegspslist_oomulsc_cns (C, A, AT, s, v, args);
  if (B != BT)
    return obj_vardnsexpdegspslist_oomulmonomsc_cns (C, B, BT, m, t, w, args);
  return C;
}

static void 
obj_vardnsexpdegspslist_oomulscaddmulmonomsc (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_t s, int v, obj_vardnsexpdegspsterm_t B, obj_vardnsexpdegspsterm_t BT, vardnsmonom_t m, obj_t t, int w, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspslist_oomulscaddmulmonomsc_cns (C, A, AT, s, v, B, BT, m, t, w, args), CT);
}

static void 
obj_vardnsexpdegspslist_inmulscaddmulmonomsc (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_t s, int v, obj_vardnsexpdegspsterm_t B, obj_vardnsexpdegspsterm_t BT, vardnsmonom_t m, obj_t t, int w, obj_vardnsexpdegspsterm_args args)
{
  assert (A != B);

  while (A != AT && B != BT)
    {
      int cmp = obj_vardnsexpdegspsterm_cmpmul (A, B, m, args);
      if (cmp == 0)
	{
	  A = obj_vardnsexpdegspsterm_inmulscaddmulmonomsc (A, s, v, B, m, t, w, args);
	  B = B->nlink;
	  continue;
	}
      if (cmp < 0)
	{
	  obj_vardnsexpdegspsterm_oomulmonomsc (A->plink, B, m, t, w, A, args);
	  B = B->nlink;
	}
      else
	{
	  A = obj_vardnsexpdegspsterm_inmulsc (A, s, v, args);
	}
    }

  if (A != AT)
    obj_vardnsexpdegspslist_inmulsc (A, AT, s, v, args);
  if (B != BT)
    obj_vardnsexpdegspslist_oomulmonomsc (A->plink, B, BT, m, t, w, A, args);
}

static BOOL 
obj_vardnsexpdegspslist_oodivsc (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_t s, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  BOOL failed = NO;

  while (A != AT)
    {
      obj_vardnsexpdegspsterm_t nextC = obj_vardnsexpdegspsterm_oodivsc_cns (C, A, s, args);
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
  obj_vardnsexpdegspsterm_glue (C, CT);
  return failed;
}

static void 
obj_vardnsexpdegspslist_indivsc (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_t s, obj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    A = obj_vardnsexpdegspsterm_indivsc (A, s, args);
}

static BOOL 
obj_vardnsexpdegspslist_oodivmonomsc (obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, vardnsmonom_t m, obj_t s, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  BOOL failed = NO;

  while (A != AT)
    {
      obj_vardnsexpdegspsterm_t nextC = obj_vardnsexpdegspsterm_oodivmonomsc_cns (C, A, m, s, args);
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
  obj_vardnsexpdegspsterm_glue (C, CT);
  return failed;
}

static void 
obj_vardnsexpdegspslist_indivmonomsc (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, vardnsmonom_t m, obj_t s, obj_vardnsexpdegspsterm_args args)
{
  while (A != AT)
    A = obj_vardnsexpdegspsterm_indivmonomsc (A, m, s, args);
}

static void 
obj_vardnsexpdegspslist_fileOut (id aFiler, obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT, obj_vardnsexpdegspsterm_args args)
{
  int n;
  n = obj_vardnsexpdegspslist_count (A, AT);
  [aFiler fileOut:&n type:'i'];
  while (A != AT)
    A = obj_vardnsexpdegspsterm_fileOut (aFiler, A, args);
}

static obj_vardnsexpdegspsterm_t 
obj_vardnsexpdegspslist_fileIn_cns (id aFiler, obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_args args)
{
  int n;
  [aFiler fileIn:&n type:'i'];
  while (n--)
    C = obj_vardnsexpdegspsterm_fileIn_cns (aFiler, C, args);
  return C;
}

static void 
obj_vardnsexpdegspslist_fileIn (id aFiler, obj_vardnsexpdegspsterm_t C, obj_vardnsexpdegspsterm_t CT, obj_vardnsexpdegspsterm_args args)
{
  obj_vardnsexpdegspsterm_glue (obj_vardnsexpdegspslist_fileIn_cns (aFiler, C, args), CT);
}

static void 
obj_vardnsexpdegspspol_ix_init (obj_vardnsexpdegspspol_ixt ix, id self)
{
  obj_vardnsexpdegspspol_t v = [self obj_vardnsexpdegspspol_value];
  ix->head = v;
  ix->ix = v;
}

static void 
obj_vardnsexpdegspspol_ix_clear (obj_vardnsexpdegspspol_ixt ix)
{
  /* nothing to clear */
}

static int 
obj_vardnsexpdegspspol_ix_count_aux_aux (obj_vardnsexpdegspsterm_t A, obj_vardnsexpdegspsterm_t AT)
{
  int c = 0;
  for (; A != AT; A = A->nlink)
    c++;
  return c;
}

static int 
obj_vardnsexpdegspspol_ix_count_aux (obj_vardnsexpdegspspol_t self)
{
  return obj_vardnsexpdegspspol_ix_count_aux_aux (self->nlink, self);
}

static int 
obj_vardnsexpdegspspol_ix_count (obj_vardnsexpdegspspol_ixt ix)
{
  /* merde ! can't include entire obj_vardnsexpdegspslist for obj_vardnsexpdegspslist_count */
  return obj_vardnsexpdegspspol_ix_count_aux (ix->head);
}

static int 
obj_vardnsexpdegspspol_ix_isempty_aux (obj_vardnsexpdegspspol_t self)
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
obj_vardnsexpdegspspol_ix_isempty (obj_vardnsexpdegspspol_ixt ix)
{
  /* can't include entire obj_vardnsexpdegspspol for obj_vardnsexpdegspspol_isempty */
  return obj_vardnsexpdegspspol_ix_isempty_aux (ix->head);
}

static int 
obj_vardnsexpdegspspol_ix_ismatch (obj_vardnsexpdegspspol_ixt ix)
{
  return (ix->ix != NULL && ix->ix != ix->head);
}

static void 
obj_vardnsexpdegspspol_ix_tofirst (obj_vardnsexpdegspspol_ixt ix)
{
  ix->ix = ix->head;
}

static void 
obj_vardnsexpdegspspol_ix_tolast (obj_vardnsexpdegspspol_ixt ix)
{
  ix->ix = NULL;
}

static void 
obj_vardnsexpdegspspol_ix_to (obj_vardnsexpdegspspol_ixt ix, int i)
{
  fprintf (stderr, "at: notImplemented\n");
}

static void 
obj_vardnsexpdegspspol_ix_next (obj_vardnsexpdegspspol_ixt ix)
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
obj_vardnsexpdegspspol_ix_prev (obj_vardnsexpdegspspol_ixt ix)
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
obj_vardnsexpdegspspol_check (obj_vardnsexpdegspspol_t self, obj_vardnsexpdegspspol_args args)
{
  assert (self->data == 0xcafebabe);
  return obj_vardnsexpdegspslist_check (self->nlink, self, args);
}

static obj_vardnsexpdegspspol_t 
obj_vardnsexpdegspspol_id2t (id object)
{
  return [object obj_vardnsexpdegspspol_value];
}

static obj_vardnsexpdegspspol_c *
obj_vardnsexpdegspspol_id2c (id object)
{
  return [object obj_vardnsexpdegspspol_reference];
}

static id 
obj_vardnsexpdegspspol_t2id (id proto, obj_vardnsexpdegspspol_t f)
{
  return [proto obj_vardnsexpdegspspol_value:f];
}

static id 
obj_vardnsexpdegspspol_c2id (id proto, obj_vardnsexpdegspspol_c * r)
{
  return [proto obj_vardnsexpdegspspol_reference:r];
}

static int 
obj_vardnsexpdegspspol_isempty (obj_vardnsexpdegspspol_t self)
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
obj_vardnsexpdegspspol_init (obj_vardnsexpdegspspol_t self, obj_vardnsexpdegspspol_args args)
{
  self->data = 0xcafebabe;
  self->nlink = self;
  self->plink = self;
  assert (obj_vardnsexpdegspspol_check (self, args));
}

static void 
obj_vardnsexpdegspspol_copy (obj_vardnsexpdegspspol_t c, obj_vardnsexpdegspspol_t a, obj_vardnsexpdegspspol_args args)
{
  assert (obj_vardnsexpdegspspol_check (a, args));
  obj_vardnsexpdegspspol_init (c, args);
  obj_vardnsexpdegspslist_copy (c, a->nlink, a, c, args);
}

static void 
obj_vardnsexpdegspspol_deepcopy (obj_vardnsexpdegspspol_t c, obj_vardnsexpdegspspol_t a, obj_vardnsexpdegspspol_args args)
{
  assert (obj_vardnsexpdegspspol_check (a, args));
  obj_vardnsexpdegspspol_init (c, args);
  obj_vardnsexpdegspslist_deepcopy (c, a->nlink, a, c, args);
}

static void 
obj_vardnsexpdegspspol_move (obj_vardnsexpdegspspol_t c, obj_vardnsexpdegspspol_t a, obj_vardnsexpdegspspol_args args)
{
  if (obj_vardnsexpdegspspol_isempty (a))
    {
      obj_vardnsexpdegspspol_init (c, args);
    }
  else
    {
      obj_vardnsexpdegspspol_init (c, args);
      obj_vardnsexpdegspsterm_glue (c, a->nlink);
      obj_vardnsexpdegspsterm_glue (a->plink, c);
    }

  a->data = 0;
  assert (obj_vardnsexpdegspspol_check (c, args));
}

static void 
obj_vardnsexpdegspspol_clear (obj_vardnsexpdegspspol_t self, obj_vardnsexpdegspspol_args args)
{
  obj_vardnsexpdegspslist_clear (self->nlink, self, args);
  self->data = 0;
  obj_vardnsexpdegspslist_free (self->nlink, self, args);
}

static int 
obj_vardnsexpdegspspol_count (obj_vardnsexpdegspspol_t self)
{
  return obj_vardnsexpdegspslist_count (self->nlink, self);
}

static unsigned 
obj_vardnsexpdegspspol_hash (obj_vardnsexpdegspspol_t a, obj_vardnsexpdegspspol_args args)
{
  return obj_vardnsexpdegspslist_hash (a->nlink, a, args);
}

static int 
obj_vardnsexpdegspspol_iseq (obj_vardnsexpdegspspol_t a, obj_vardnsexpdegspspol_t b, obj_vardnsexpdegspspol_args args)
{
  return (a == b) ? YES : obj_vardnsexpdegspslist_iseq (a->nlink, a, b->nlink, b, args);
}

static int 
obj_vardnsexpdegspspol_isone (obj_vardnsexpdegspspol_t a, obj_vardnsexpdegspspol_args args)
{
  /* if the leading term is one, then it is one */
  return (obj_vardnsexpdegspspol_isempty (a)) ? 0 : obj_vardnsexpdegspsterm_isone (a->nlink, args);
}

static int 
obj_vardnsexpdegspspol_isminusone (obj_vardnsexpdegspspol_t a, obj_vardnsexpdegspspol_args args)
{
  /* if the leading term is minus one, then it is minus one */
  return (obj_vardnsexpdegspspol_isempty (a)) ? 0 : obj_vardnsexpdegspsterm_isminusone (a->nlink, args);
}

static int 
obj_vardnsexpdegspspol_deg (obj_vardnsexpdegspspol_t self, obj_vardnsexpdegspspol_args args)
{
  return obj_vardnsexpdegspslist_deg (self->nlink, self, args);
}

static int 
obj_vardnsexpdegspspol_ord (obj_vardnsexpdegspspol_t self, obj_vardnsexpdegspspol_args args)
{
  return obj_vardnsexpdegspslist_ord (self->nlink, self, args);
}

static int 
obj_vardnsexpdegspspol_maxdeg (obj_vardnsexpdegspspol_t self, obj_vardnsexpdegspspol_args args)
{
  return obj_vardnsexpdegspslist_maxdeg (self->nlink, self, args);
}

static int 
obj_vardnsexpdegspspol_mindeg (obj_vardnsexpdegspspol_t self, obj_vardnsexpdegspspol_args args)
{
  return obj_vardnsexpdegspslist_mindeg (self->nlink, self, args);
}

static obj_t 
obj_vardnsexpdegspspol_scalat (obj_vardnsexpdegspspol_t self, obj_vardnsexpdegspspol_ixt ix, obj_vardnsexpdegspspol_args args)
{
  assert (obj_vardnsexpdegspspol_ix_ismatch (ix) && ix->head == self);
  return obj_vardnsexpdegspsterm_scal (ix->ix, args);
}

static vardnsmonom_t 
obj_vardnsexpdegspspol_monomat (obj_vardnsexpdegspspol_t self, obj_vardnsexpdegspspol_ixt ix, obj_vardnsexpdegspspol_args args)
{
  assert (obj_vardnsexpdegspspol_ix_ismatch (ix) && ix->head == self);
  return obj_vardnsexpdegspsterm_monom (ix->ix);
}

static obj_t 
obj_vardnsexpdegspspol_scalfirst (obj_vardnsexpdegspspol_t self, obj_vardnsexpdegspspol_args args)
{
  assert (obj_vardnsexpdegspspol_isempty (self) == NO);
  return obj_vardnsexpdegspsterm_scal (self->nlink, args);
}

static vardnsmonom_t 
obj_vardnsexpdegspspol_monomfirst (obj_vardnsexpdegspspol_t self, obj_vardnsexpdegspspol_args args)
{
  assert (obj_vardnsexpdegspspol_isempty (self) == NO);
  return obj_vardnsexpdegspsterm_monom (self->nlink);
}

static void 
obj_vardnsexpdegspspol_remove (obj_vardnsexpdegspspol_t self, obj_vardnsexpdegspspol_args args)
{
  assert (obj_vardnsexpdegspspol_check (self, args) && obj_vardnsexpdegspspol_isempty (self) == NO);
  obj_vardnsexpdegspsterm_delete (self->nlink, args);
  assert (obj_vardnsexpdegspspol_check (self, args));
}

static void 
obj_vardnsexpdegspspol_insert (obj_vardnsexpdegspspol_t self, vardnsmonom_t m, obj_t s, obj_vardnsexpdegspspol_args args)
{
  assert (obj_vardnsexpdegspspol_check (self, args));
  obj_vardnsexpdegspslist_insert (self->nlink, self, m, s, args);
  assert (obj_vardnsexpdegspspol_check (self, args));
}

static int 
obj_vardnsexpdegspspol_iszero (obj_vardnsexpdegspspol_t self, obj_vardnsexpdegspspol_args args)
{
  return obj_vardnsexpdegspspol_isempty (self);
}

static int 
obj_vardnsexpdegspspol_isop (obj_vardnsexpdegspspol_t a, obj_vardnsexpdegspspol_t b, obj_vardnsexpdegspspol_args args)
{
  assert (a != b);
  return obj_vardnsexpdegspslist_isop (a->nlink, a, b->nlink, b, args);
}

static void 
obj_vardnsexpdegspspol_ooneg (obj_vardnsexpdegspspol_t c, obj_vardnsexpdegspspol_t a, obj_vardnsexpdegspspol_args args)
{
  obj_vardnsexpdegspspol_init (c, args);
  obj_vardnsexpdegspslist_ooneg (c, a->nlink, a, c, args);
  assert (obj_vardnsexpdegspspol_check (c, args));
}

static void 
obj_vardnsexpdegspspol_inneg (obj_vardnsexpdegspspol_t a, obj_vardnsexpdegspspol_args args)
{
  obj_vardnsexpdegspslist_inneg (a->nlink, a, args);
  assert (obj_vardnsexpdegspspol_check (a, args));
}

static void 
obj_vardnsexpdegspspol_oodbl (obj_vardnsexpdegspspol_t c, obj_vardnsexpdegspspol_t a, int v, obj_vardnsexpdegspspol_args args)
{
  obj_vardnsexpdegspspol_init (c, args);
  obj_vardnsexpdegspslist_oodbl (c, a->nlink, a, v, c, args);
  assert (obj_vardnsexpdegspspol_check (c, args));
}

static void 
obj_vardnsexpdegspspol_indbl (obj_vardnsexpdegspspol_t a, int v, obj_vardnsexpdegspspol_args args)
{
  obj_vardnsexpdegspslist_indbl (a->nlink, a, v, args);
  assert (obj_vardnsexpdegspspol_check (a, args));
}

static void 
obj_vardnsexpdegspspol_ooadd (obj_vardnsexpdegspspol_t c, obj_vardnsexpdegspspol_t a, int v, obj_vardnsexpdegspspol_t b, int w, obj_vardnsexpdegspspol_args args)
{
  assert (a != b);
  obj_vardnsexpdegspspol_init (c, args);
  obj_vardnsexpdegspslist_ooadd (c, a->nlink, a, v, b->nlink, b, w, c, args);
  assert (obj_vardnsexpdegspspol_check (c, args));
}

static void 
obj_vardnsexpdegspspol_inadd (obj_vardnsexpdegspspol_t a, int v, obj_vardnsexpdegspspol_t b, int w, obj_vardnsexpdegspspol_args args)
{
  assert (a != b);
  obj_vardnsexpdegspslist_inadd (a->nlink, a, v, b->nlink, b, w, args);
  assert (obj_vardnsexpdegspspol_check (a, args));
}

static void 
obj_vardnsexpdegspspol_oomulsc (obj_vardnsexpdegspspol_t c, obj_vardnsexpdegspspol_t a, obj_t s, obj_vardnsexpdegspspol_args args)
{
  obj_vardnsexpdegspspol_init (c, args);
  obj_vardnsexpdegspslist_oomulsc (c, a->nlink, a, s, +1, c, args);
  assert (obj_vardnsexpdegspspol_check (c, args));
}

static void 
obj_vardnsexpdegspspol_inmulsc (obj_vardnsexpdegspspol_t a, obj_t s, obj_vardnsexpdegspspol_args args)
{
  obj_vardnsexpdegspslist_inmulsc (a->nlink, a, s, +1, args);
  assert (obj_vardnsexpdegspspol_check (a, args));
}

static void 
obj_vardnsexpdegspspol_ooaddmulsc (obj_vardnsexpdegspspol_t c, obj_vardnsexpdegspspol_t a, int v, obj_vardnsexpdegspspol_t b, obj_t t, int w, obj_vardnsexpdegspspol_args args)
{
  obj_vardnsexpdegspspol_init (c, args);
  obj_vardnsexpdegspslist_ooaddmulsc (c, a->nlink, a, v, b->nlink, b, t, w, c, args);
  assert (obj_vardnsexpdegspspol_check (c, args));
}

static void 
obj_vardnsexpdegspspol_inaddmulsc (obj_vardnsexpdegspspol_t a, int v, obj_vardnsexpdegspspol_t b, obj_t t, int w, obj_vardnsexpdegspspol_args args)
{
  obj_vardnsexpdegspslist_inaddmulsc (a->nlink, a, v, b->nlink, b, t, w, args);
  assert (obj_vardnsexpdegspspol_check (a, args));
}

static void 
obj_vardnsexpdegspspol_oomulscadd (obj_vardnsexpdegspspol_t c, obj_vardnsexpdegspspol_t a, obj_t s, int v, obj_vardnsexpdegspspol_t b, int w, obj_vardnsexpdegspspol_args args)
{
  obj_vardnsexpdegspspol_init (c, args);
  obj_vardnsexpdegspslist_oomulscadd (c, a->nlink, a, s, v, b->nlink, b, w, c, args);
  assert (obj_vardnsexpdegspspol_check (c, args));
}

static void 
obj_vardnsexpdegspspol_inmulscadd (obj_vardnsexpdegspspol_t a, obj_t s, int v, obj_vardnsexpdegspspol_t b, int w, obj_vardnsexpdegspspol_args args)
{
  obj_vardnsexpdegspslist_inmulscadd (a->nlink, a, s, v, b->nlink, b, w, args);
  assert (obj_vardnsexpdegspspol_check (a, args));
}

static void 
obj_vardnsexpdegspspol_oomulscaddmulsc (obj_vardnsexpdegspspol_t c, obj_vardnsexpdegspspol_t a, obj_t s, int v, obj_vardnsexpdegspspol_t b, obj_t t, int w, obj_vardnsexpdegspspol_args args)
{
  obj_vardnsexpdegspspol_init (c, args);
  obj_vardnsexpdegspslist_oomulscaddmulsc (c, a->nlink, a, s, v, b->nlink, b, t, w, c, args);
  assert (obj_vardnsexpdegspspol_check (c, args));
}

static void 
obj_vardnsexpdegspspol_inmulscaddmulsc (obj_vardnsexpdegspspol_t a, obj_t s, int v, obj_vardnsexpdegspspol_t b, obj_t t, int w, obj_vardnsexpdegspspol_args args)
{
  obj_vardnsexpdegspslist_inmulscaddmulsc (a->nlink, a, s, v, b->nlink, b, t, w, args);
  assert (obj_vardnsexpdegspspol_check (a, args));
}

static BOOL 
obj_vardnsexpdegspspol_oodivsc (obj_vardnsexpdegspspol_t c, obj_vardnsexpdegspspol_t a, obj_t s, obj_vardnsexpdegspspol_args args)
{
  BOOL failed;
  obj_vardnsexpdegspspol_init (c, args);
  failed = obj_vardnsexpdegspslist_oodivsc (c, a->nlink, a, s, c, args);
  assert (obj_vardnsexpdegspspol_check (c, args));
  if (failed)
    obj_vardnsexpdegspspol_clear (c, args);
  return failed;
}

static void 
obj_vardnsexpdegspspol_indivsc (obj_vardnsexpdegspspol_t a, obj_t s, obj_vardnsexpdegspspol_args args)
{
  obj_vardnsexpdegspslist_indivsc (a->nlink, a, s, args);
  assert (obj_vardnsexpdegspspol_check (a, args));
}

static void 
obj_vardnsexpdegspspol_oomulmonomsc (obj_vardnsexpdegspspol_t c, obj_vardnsexpdegspspol_t b, vardnsmonom_t m, obj_t t, int w, obj_vardnsexpdegspspol_args args)
{
  obj_vardnsexpdegspspol_init (c, args);
  obj_vardnsexpdegspslist_oomulmonomsc (c, b->nlink, b, m, t, w, c, args);
  assert (obj_vardnsexpdegspspol_check (c, args));
}

static void 
obj_vardnsexpdegspspol_inmulmonomsc (obj_vardnsexpdegspspol_t b, vardnsmonom_t m, obj_t t, int w, obj_vardnsexpdegspspol_args args)
{
  obj_vardnsexpdegspslist_inmulmonomsc (b->nlink, b, m, t, w, args);
  assert (obj_vardnsexpdegspspol_check (b, args));
}

static void 
obj_vardnsexpdegspspol_ooaddmulmonomsc (obj_vardnsexpdegspspol_t c, obj_vardnsexpdegspspol_t a, int v, obj_vardnsexpdegspspol_t b, vardnsmonom_t m, obj_t t, int w, obj_vardnsexpdegspspol_args args)
{
  obj_vardnsexpdegspspol_init (c, args);
  obj_vardnsexpdegspslist_ooaddmulmonomsc (c, a->nlink, a, v, b->nlink, b, m, t, w, c, args);
  assert (obj_vardnsexpdegspspol_check (c, args));
}

static void 
obj_vardnsexpdegspspol_inaddmulmonomsc (obj_vardnsexpdegspspol_t a, int v, obj_vardnsexpdegspspol_t b, vardnsmonom_t m, obj_t t, int w, obj_vardnsexpdegspspol_args args)
{
  obj_vardnsexpdegspslist_inaddmulmonomsc (a->nlink, a, v, b->nlink, b, m, t, w, args);
  assert (obj_vardnsexpdegspspol_check (a, args));
}

static void 
obj_vardnsexpdegspspol_oomulscaddmulmonomsc (obj_vardnsexpdegspspol_t c, obj_vardnsexpdegspspol_t a, obj_t s, int v, obj_vardnsexpdegspspol_t b, vardnsmonom_t m, obj_t t, int w, obj_vardnsexpdegspspol_args args)
{
  obj_vardnsexpdegspspol_init (c, args);
  obj_vardnsexpdegspslist_oomulscaddmulmonomsc (c, a->nlink, a, s, v, b->nlink, b, m, t, w, c, args);
  assert (obj_vardnsexpdegspspol_check (c, args));
}

static void 
obj_vardnsexpdegspspol_inmulscaddmulmonomsc (obj_vardnsexpdegspspol_t a, obj_t s, int v, obj_vardnsexpdegspspol_t b, vardnsmonom_t m, obj_t t, int w, obj_vardnsexpdegspspol_args args)
{
  obj_vardnsexpdegspslist_inmulscaddmulmonomsc (a->nlink, a, s, v, b->nlink, b, m, t, w, args);
  assert (obj_vardnsexpdegspspol_check (a, args));
}

static BOOL 
obj_vardnsexpdegspspol_oodivmonomsc (obj_vardnsexpdegspspol_t c, obj_vardnsexpdegspspol_t b, vardnsmonom_t m, obj_t t, obj_vardnsexpdegspspol_args args)
{
  BOOL failed;
  obj_vardnsexpdegspspol_init (c, args);
  failed = obj_vardnsexpdegspslist_oodivmonomsc (c, b->nlink, b, m, t, c, args);
  assert (obj_vardnsexpdegspspol_check (c, args));
  if (failed)
    obj_vardnsexpdegspspol_clear (c, args);
  return failed;
}

static void 
obj_vardnsexpdegspspol_indivmonomsc (obj_vardnsexpdegspspol_t b, vardnsmonom_t m, obj_t t, obj_vardnsexpdegspspol_args args)
{
  obj_vardnsexpdegspslist_indivmonomsc (b->nlink, b, m, t, args);
  assert (obj_vardnsexpdegspspol_check (b, args));
}

static void 
obj_vardnsexpdegspspol_args_fileOut (id aFiler, obj_vardnsexpdegspspol_args * args)
{
  obj_vardnsexpdegspsterm_args_fileOut (aFiler, args);
}
static void 
obj_vardnsexpdegspspol_args_fileIn (id aFiler, obj_vardnsexpdegspspol_args * args)
{
  obj_vardnsexpdegspsterm_args_fileIn (aFiler, args);
}

static void 
obj_vardnsexpdegspspol_fileOut (id aFiler, obj_vardnsexpdegspspol_t self, obj_vardnsexpdegspspol_args args)
{
  assert (obj_vardnsexpdegspspol_check (self, args));
  obj_vardnsexpdegspslist_fileOut (aFiler, self->nlink, self, args);
}

static void 
obj_vardnsexpdegspspol_fileIn (id aFiler, obj_vardnsexpdegspspol_t self, obj_vardnsexpdegspspol_args args)
{
  obj_vardnsexpdegspspol_init (self, args);
  obj_vardnsexpdegspslist_fileIn (aFiler, self, self, args);
  assert (obj_vardnsexpdegspspol_check (self, args));
}

static obj_vardnsexpdegspspol_args 
obj_vardnsexpdegspspol_getargs (id self)
{
  obj_vardnsexpdegspspol_args res;
  id monomialZero = [self monomialZero];
  res.sargs = obj_getargs ([monomialZero scalar]);
  res.margs = vardnsmonom_getargs ([monomialZero terms]);
  return res;
}
@implementation obj_vardnsexpdegsps_polynomial : vardnsexpdegsps_polynomial

- (obj_vardnsexpdegspspol_t)obj_vardnsexpdegspspol_value
{
  return &value;
}

- doobj_vardnsexpdegspspol_value:(obj_vardnsexpdegspspol_t)aValue
{
  obj_vardnsexpdegspspol_copy (&value, aValue, obj_vardnsexpdegspspol_getargs (self));
  assert ([self check]);
  return self;
}

- obj_vardnsexpdegspspol_value:(obj_vardnsexpdegspspol_t)aValue
{
  return [[self clone] doobj_vardnsexpdegspspol_value:aValue];
}

- (obj_vardnsexpdegspspol_t)obj_vardnsexpdegspspol_reference
{
  return &value;
}

- doobj_vardnsexpdegspspol_reference:(obj_vardnsexpdegspspol_c *)aReference
{
  obj_vardnsexpdegspspol_move (&value, aReference, obj_vardnsexpdegspspol_getargs (self));
  assert ([self check]);
  return self;
}

- obj_vardnsexpdegspspol_reference:(obj_vardnsexpdegspspol_c *)aReference
{
  return [[self clone] doobj_vardnsexpdegspspol_reference:aReference];
}

- copy
{
  obj_vardnsexpdegspspol_c c;
  assert ([self check]);
  obj_vardnsexpdegspspol_copy (&c, &value, obj_vardnsexpdegspspol_getargs (self));
  return obj_vardnsexpdegspspol_c2id (self, &c);
}

- deepCopy
{
  obj_vardnsexpdegspspol_c c;
  assert ([self check]);
  obj_vardnsexpdegspspol_deepcopy (&c, &value, obj_vardnsexpdegspspol_getargs (self));
  return obj_vardnsexpdegspspol_c2id (self, &c);
}

- (BOOL) isEmpty
{
  return obj_vardnsexpdegspspol_isempty (&value);
}

- (BOOL) isOne
{
  return obj_vardnsexpdegspspol_isone (&value, obj_vardnsexpdegspspol_getargs (self));
}

- (BOOL) isMinusOne
{
  return obj_vardnsexpdegspspol_isminusone (&value, obj_vardnsexpdegspspol_getargs (self));
}

- (unsigned) hash
{
  return obj_vardnsexpdegspspol_hash (obj_vardnsexpdegspspol_id2t (self), obj_vardnsexpdegspspol_getargs (self));
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
      return obj_vardnsexpdegspspol_iseq (obj_vardnsexpdegspspol_id2t (self), obj_vardnsexpdegspspol_id2t (b), obj_vardnsexpdegspspol_getargs (self));
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
      return !obj_vardnsexpdegspspol_iseq (obj_vardnsexpdegspspol_id2t (self), obj_vardnsexpdegspspol_id2t (b), obj_vardnsexpdegspspol_getargs (self));
    }
}

- (BOOL) isZero
{
  assert ([self check]);
  return obj_vardnsexpdegspspol_iszero (obj_vardnsexpdegspspol_id2t (self), obj_vardnsexpdegspspol_getargs (self));
}

- (BOOL) notZero
{
  assert ([self check]);
  return !obj_vardnsexpdegspspol_iszero (obj_vardnsexpdegspspol_id2t (self), obj_vardnsexpdegspspol_getargs (self));
}

- (BOOL) isOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return obj_vardnsexpdegspspol_isop (obj_vardnsexpdegspspol_id2t (self), obj_vardnsexpdegspspol_id2t (b), obj_vardnsexpdegspspol_getargs (self));
}

- (BOOL) notOpposite:b
{
  assert ([self checkSameClass:b] && self != b);
  return !obj_vardnsexpdegspspol_isop (obj_vardnsexpdegspspol_id2t (self), obj_vardnsexpdegspspol_id2t (b), obj_vardnsexpdegspspol_getargs (self));
}

- negate
{
  obj_vardnsexpdegspspol_c c;
  assert ([self check]);
  obj_vardnsexpdegspspol_ooneg (&c, obj_vardnsexpdegspspol_id2t (self), obj_vardnsexpdegspspol_getargs (self));
  return obj_vardnsexpdegspspol_c2id (self, &c);
}

- _double:(int)v
{
  obj_vardnsexpdegspspol_c c;
  assert ([self check]);
  obj_vardnsexpdegspspol_oodbl (&c, obj_vardnsexpdegspspol_id2t (self), v, obj_vardnsexpdegspspol_getargs (self));
  return obj_vardnsexpdegspspol_c2id (self, &c);
}

- double
{
  obj_vardnsexpdegspspol_c c;
  assert ([self check]);
  obj_vardnsexpdegspspol_oodbl (&c, obj_vardnsexpdegspspol_id2t (self), +1, obj_vardnsexpdegspspol_getargs (self));
  return obj_vardnsexpdegspspol_c2id (self, &c);
}

- _add:(int)v:b:(int)w
{
  obj_vardnsexpdegspspol_c c;
  assert ([self sameClass:b] && v * v == 1 && w * w == 1 && self != b);
  obj_vardnsexpdegspspol_ooadd (&c, obj_vardnsexpdegspspol_id2t (self), v, obj_vardnsexpdegspspol_id2t (b), w, obj_vardnsexpdegspspol_getargs (self));
  return obj_vardnsexpdegspspol_c2id (self, &c);
}

- add:b
{
  obj_vardnsexpdegspspol_c c;
  assert ([self checkSameClass:b] && self != b);
  obj_vardnsexpdegspspol_ooadd (&c, obj_vardnsexpdegspspol_id2t (self), +1, obj_vardnsexpdegspspol_id2t (b), +1, obj_vardnsexpdegspspol_getargs (self));
  return obj_vardnsexpdegspspol_c2id (self, &c);
}

- subtract:b
{
  obj_vardnsexpdegspspol_c c;
  assert ([self checkSameClass:b] && self != b);
  obj_vardnsexpdegspspol_ooadd (&c, obj_vardnsexpdegspspol_id2t (self), +1, obj_vardnsexpdegspspol_id2t (b), -1, obj_vardnsexpdegspspol_getargs (self));
  return obj_vardnsexpdegspspol_c2id (self, &c);
}

- (int) leadingDegree
{
  return obj_vardnsexpdegspspol_deg (&value, obj_vardnsexpdegspspol_getargs (self));
}

- (int) lastDegree
{
  return obj_vardnsexpdegspspol_ord (&value, obj_vardnsexpdegspspol_getargs (self));
}

- (int) maxDegree
{
  return obj_vardnsexpdegspspol_maxdeg (&value, obj_vardnsexpdegspspol_getargs (self));
}

- (int) minDegree
{
  return obj_vardnsexpdegspspol_mindeg (&value, obj_vardnsexpdegspspol_getargs (self));
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

  obj_vardnsexpdegspspol_check (&value, obj_vardnsexpdegspspol_getargs (self));
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

  obj_vardnsexpdegspspol_init (&value, obj_vardnsexpdegspspol_getargs (self));
  assert ([self check]);
  return self;
}

+ scalarZero:aScalar symbols:aCltn
{
  return [[super new] _setUpScalarZero:aScalar symbols:aCltn];
}

- release
{
  obj_vardnsexpdegspspol_clear (&value, obj_vardnsexpdegspspol_getargs (self));
  return [super release];
}

- empty
{
  obj_vardnsexpdegspspol_c c;
  assert ([self check]);
  obj_vardnsexpdegspspol_init (&c, obj_vardnsexpdegspspol_getargs (self));
  return obj_vardnsexpdegspspol_c2id (self, &c);
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
  return obj_vardnsexpdegspspol_count (&value);
}

- eachMonomial
{
  id aSequence = [obj_vardnsexpdegspspol_sequence content:self];
  return [CASequence over:aSequence];
}

- elt_obj_vardnsexpdegspspol_ix:(obj_vardnsexpdegspspol_ixt)ix
{
  if (obj_vardnsexpdegspspol_ix_ismatch (ix))
    {
      id s, m;
      obj_t sc;
      vardnsmonom_t mc;
      sc = obj_vardnsexpdegspspol_scalat (&value, ix, obj_vardnsexpdegspspol_getargs (self));
      mc = obj_vardnsexpdegspspol_monomat (&value, ix, obj_vardnsexpdegspspol_getargs (self));
      s = obj_t2id ([monomialZero scalar], sc);
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
      obj_t sc;
      vardnsmonom_t mc;
      assert ([self check]);

      sc = obj_vardnsexpdegspspol_scalfirst (&value, obj_vardnsexpdegspspol_getargs (self));
      mc = obj_vardnsexpdegspspol_monomfirst (&value, obj_vardnsexpdegspspol_getargs (self));
      s = obj_t2id ([monomialZero scalar], sc);
      m = vardnsmonom_t2id ([monomialZero terms], mc);
      lt = [monomialZero scalar:s terms:m];

      obj_vardnsexpdegspspol_remove (&value, obj_vardnsexpdegspspol_getargs (self));
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
      obj_c c;
      obj_t r;
      vardnsmonom_t m;
      assert ([aMonomial check]);
      assert ([self check]);
      r = obj_id2ref ([aMonomial scalar], &c);
      m = vardnsmonom_id2t ([aMonomial terms]);
      obj_vardnsexpdegspspol_insert (&value, m, r, obj_vardnsexpdegspspol_getargs (self));
      assert ([aMonomial check]);
      [self invalidate];
      assert ([self check]);
      return self;
    }
}

- multiplyScalar:s
{
  obj_vardnsexpdegspspol_c c;
  obj_c sc;
  obj_vardnsexpdegspspol_oomulsc (&c, obj_vardnsexpdegspspol_id2t (self), obj_id2ref (s, &sc), obj_vardnsexpdegspspol_getargs (self));
  return obj_vardnsexpdegspspol_c2id (self, &c);
}

- divideScalar:s
{
  obj_vardnsexpdegspspol_c c;
  obj_c sc;
  BOOL failed = obj_vardnsexpdegspspol_oodivsc (&c, obj_vardnsexpdegspspol_id2t (self), obj_id2ref (s, &sc), obj_vardnsexpdegspspol_getargs (self));
  return (failed) ? nil : obj_vardnsexpdegspspol_c2id (self, &c);
}

- _add:(int)v:B multiplyScalar:b:(int)w
{
  obj_vardnsexpdegspspol_c c;
  obj_c bc;
  assert ([self sameClass:B] && [scalarZero sameClass:b] && v * v == 1 && w * w == 1);
  obj_vardnsexpdegspspol_ooaddmulsc (&c, obj_vardnsexpdegspspol_id2t (self), v, obj_vardnsexpdegspspol_id2t (B), obj_id2ref (b, &bc), w, obj_vardnsexpdegspspol_getargs (self));
  return obj_vardnsexpdegspspol_c2id (self, &c);
}

- _multiplyScalar:a:(int)v add:B:(int)w
{
  obj_vardnsexpdegspspol_c c;
  obj_c ac;
  assert ([scalarZero sameClass:a] && [self sameClass:B] && v * v == 1 && w * w == 1);
  obj_vardnsexpdegspspol_oomulscadd (&c, obj_vardnsexpdegspspol_id2t (self), obj_id2ref (a, &ac), v, obj_vardnsexpdegspspol_id2t (B), w, obj_vardnsexpdegspspol_getargs (self));
  return obj_vardnsexpdegspspol_c2id (self, &c);
}

- _multiplyScalar:a:(int)v add:B multiplyScalar:b:(int)w
{
  obj_vardnsexpdegspspol_c c;
  obj_c ac, bc;
  assert ([scalarZero sameClass:a] && [self sameClass:B] && [scalarZero sameClass:b] && v * v == 1 && w * w == 1);
  obj_vardnsexpdegspspol_oomulscaddmulsc (&c, obj_vardnsexpdegspspol_id2t (self), obj_id2ref (a, &ac), v, obj_vardnsexpdegspspol_id2t (B), obj_id2ref (b, &bc), w, obj_vardnsexpdegspspol_getargs (self));
  return obj_vardnsexpdegspspol_c2id (self, &c);
}

- multiplyMonomial:aMonomial
{
  obj_vardnsexpdegspspol_c c;
  obj_t s;
  obj_c sc;
  vardnsmonom_t m;

  m = vardnsmonom_id2t ([aMonomial terms]);
  s = obj_id2ref ([aMonomial scalar], &sc);
  obj_vardnsexpdegspspol_oomulmonomsc (&c, obj_vardnsexpdegspspol_id2t (self), m, s, +1, obj_vardnsexpdegspspol_getargs (self));
  return obj_vardnsexpdegspspol_c2id (self, &c);
}

- _multiplyMonomial:aMonomial:(int)v
{
  obj_vardnsexpdegspspol_c c;
  obj_t s;
  obj_c sc;
  vardnsmonom_t m;

  m = vardnsmonom_id2t ([aMonomial terms]);
  s = obj_id2ref ([aMonomial scalar], &sc);
  obj_vardnsexpdegspspol_oomulmonomsc (&c, obj_vardnsexpdegspspol_id2t (self), m, s, v, obj_vardnsexpdegspspol_getargs (self));
  return obj_vardnsexpdegspspol_c2id (self, &c);
}

- divideMonomial:aMonomial
{
  BOOL failed;
  obj_vardnsexpdegspspol_c c;
  obj_t s;
  obj_c sc;
  vardnsmonom_t m;

  m = vardnsmonom_id2t ([aMonomial terms]);
  s = obj_id2ref ([aMonomial scalar], &sc);
  failed = obj_vardnsexpdegspspol_oodivmonomsc (&c, obj_vardnsexpdegspspol_id2t (self), m, s, obj_vardnsexpdegspspol_getargs (self));
  return (failed) ? nil : obj_vardnsexpdegspspol_c2id (self, &c);
}

- _add:(int)v:B multiplyMonomial:b:(int)w
{
  obj_vardnsexpdegspspol_c c;
  obj_c bc;
  obj_t bs;
  vardnsmonom_t bm;

  bm = vardnsmonom_id2t ([b terms]);
  bs = obj_id2ref ([b scalar], &bc);
  obj_vardnsexpdegspspol_ooaddmulmonomsc (&c, obj_vardnsexpdegspspol_id2c (self), v, obj_vardnsexpdegspspol_id2t (B), bm, bs, w, obj_vardnsexpdegspspol_getargs (self));
  return obj_vardnsexpdegspspol_c2id (self, &c);
}

- _multiplyScalar:a:(int)v add:B multiplyMonomial:b:(int)w
{
  obj_vardnsexpdegspspol_c c;
  obj_c ac, bc;
  obj_t as, bs;
  vardnsmonom_t bm;

  as = obj_id2ref (a, &ac);
  bm = vardnsmonom_id2t ([b terms]);
  bs = obj_id2ref ([b scalar], &bc);
  obj_vardnsexpdegspspol_oomulscaddmulmonomsc (&c, obj_vardnsexpdegspspol_id2c (self), as, v, obj_vardnsexpdegspspol_id2t (B), bm, bs, w, obj_vardnsexpdegspspol_getargs (self));
  return obj_vardnsexpdegspspol_c2id (self, &c);
}


- fileOutOn:aFiler
{
  obj_vardnsexpdegspspol_args args;
  assert ([self check]);
  [super fileOutOn:aFiler];
  args = obj_vardnsexpdegspspol_getargs (self);
  obj_vardnsexpdegspspol_args_fileOut (aFiler, &args);
  obj_vardnsexpdegspspol_fileOut (aFiler, &value, args);
  return self;
}

- fileInFrom:aFiler
{
  obj_vardnsexpdegspspol_args args;
  [super fileInFrom:aFiler];
  obj_vardnsexpdegspspol_args_fileIn (aFiler, &args);
  obj_vardnsexpdegspspol_fileIn (aFiler, &value, args);
  return self;
}

@end
 
