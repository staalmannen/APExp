
/*
 * Computer Algebra Kit (c) 1995,98,99 by David Stes.  All Rights Reserved.
 * $Id: dmonomc.m,v 1.6 2000/10/12 14:40:25 stes Exp $
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

#include "cakit.h"

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
static vardns_args 
vardns_getargs (id self)
{
  vardns_args res;
  res.nvars = [[self symbols] size];
  return res;
}

static vardns_t 
vardns_id2t (id object)
{
  return [object vardns_value];
}

static vardns_c *
vardns_id2c (id object)
{
  return [object vardns_reference];
}

static id 
vardns_t2id (id proto, vardns_t f)
{
  return [proto vardns_value:f];
}

static id 
vardns_c2id (id proto, vardns_c * r)
{
  return [proto vardns_reference:r];
}

static int 
vardns_check (vardns_t self, vardns_args args)
{
  assert (0 < args.nvars);
  return vardnsmonom_check (self, args);
}

static void 
vardns_init (vardns_c * self, vardns_args args)
{
  *self = vardnsmonom_alloc (args);
  vardnsmonom_init (*self, args);
}

static void 
vardns_copy (vardns_c * c, vardns_t a, vardns_args args)
{
  *c = vardnsmonom_alloc (args);
  vardnsmonom_copy (*c, a, args);
}

static void 
vardns_move (vardns_c * c, vardns_c * a, vardns_args args)
{
  *c = *a;
  *a = NULL;
}

static void 
vardns_copymonom (vardns_c * c, vardnsmonom_t a, vardns_args args)
{
  *c = vardnsmonom_alloc (args);
  vardnsmonom_copy (*c, a, args);
}

static void 
vardns_clear (vardns_c * self, vardns_args args)
{
  vardnsmonom_free (*self, args);
  *self = NULL;
}

static int 
vardns_deg (vardns_t self, vardns_args args)
{
  return vardnsmonom_deg (self, args);
}

static int 
vardns_hash (vardns_t self, vardns_args args)
{
  return vardnsmonom_hash (self, args);
}

static int 
vardns_numterms (vardns_t self, vardns_args args)
{
  return vardnsmonom_numterms (self, args);
}

static int 
vardns_iseq (vardns_t a, vardns_t b, vardns_args args)
{
  return vardnsmonom_iseq (a, b, args);
}

static int 
vardns_cmp (vardns_t a, vardns_t b, vardns_args args)
{
  return vardnsmonom_cmp (a, b, args);
}

static int 
vardns_findfirst (vardns_t self, vardns_args args)
{
  return -1;
}

static int 
vardns_expat (vardns_t self, int i, vardns_args args)
{
  assert (0 <= i && i < args.nvars);
  return self [i];
}

static void 
vardns_setexpat (vardns_t self, int i, int e, vardns_args args)
{
  assert (0 <= i && i < args.nvars);
  self [i] = e;
}


static void 
vardns_args_fileOut (id aFiler, vardns_args * args)
{
  vardnsmonom_args_fileOut (aFiler, args);
}

static void 
vardns_args_fileIn (id aFiler, vardns_args * args)
{
  vardnsmonom_args_fileIn (aFiler, args);
}

static void 
vardns_fileOut (id aFiler, vardns_c * self, vardns_args args)
{
  vardnsmonom_fileOut (aFiler, *self, args);
}

static void 
vardns_fileIn (id aFiler, vardns_c * self, vardns_args args)
{
  *self = vardnsmonom_alloc (args);
  vardnsmonom_fileIn (aFiler, *self, args);
}

static void 
vardns_ix_init (vardns_ixt ix, id self)
{
  ix->n = [[self symbols] size];
  ix->i = -1;
}

static void 
vardns_ix_clear (vardns_ixt ix)
{
  /* nothing to clear */
}

static int 
vardns_ix_count (vardns_ixt ix)
{
  return ix->n;			/* total number, not just nonzeroes */
}

static int 
vardns_ix_isempty (vardns_ixt ix)
{
  return ix->n == 0;
}

static int 
vardns_ix_ismatch (vardns_ixt ix)
{
  return (0 <= ix->i && ix->i < ix->n);
}

static void 
vardns_ix_tofirst (vardns_ixt ix)
{
  ix->i = -1;
}

static void 
vardns_ix_tolast (vardns_ixt ix)
{
  ix->i = ix->n;
}

static void 
vardns_ix_to (vardns_ixt ix, int i)
{
  ix->i = i - 1;
}

static void 
vardns_ix_next (vardns_ixt ix)
{
  if (ix->i == ix->n)
    {
      /* remain on position just after last term */
    }
  else
    {
      ix->i = ix->i + 1;
    }
}

static void 
vardns_ix_prev (vardns_ixt ix)
{
  if (ix->i == -1)
    {
      /* remain on position just before first term */
    }
  else
    {
      ix->i = ix->i - 1;
    }
}

@implementation vardns_monomial
- check
{
  [super check];
  assert (termOne != nil && symbols != nil);
  [termOne check];
  [symbols check];
  vardnsmonom_check (value, vardns_getargs (self));
  return self;
}

- _setUpScalarOne:aOne symbols:aCltn
{
  assert ([aOne isOne] && [aCltn size] > 0);
  termOne = [Term scalar:aOne symbol:nil exponent:0];
  symbols = aCltn;
  vardns_init (&value, vardns_getargs (self));
  assert ([self check]);
  return self;
}

+ scalarOne:aOne symbols:aCltn
{
  return [[super new] _setUpScalarOne:aOne symbols:aCltn];
}

- copy
{
  vardns_c c;
  assert ([self check]);
  vardns_copy (&c, value, vardns_getargs (self));
  return vardns_c2id (self, &c);
}

- deepCopy
{
  vardns_c c;
  assert ([self check]);
  vardns_copy (&c, value, vardns_getargs (self));
  return vardns_c2id (self, &c);
}

- release
{
  vardns_clear (&value, vardns_getargs (self));
  return [super release];
}

- empty
{
  vardns_c c;
  assert ([self check]);
  vardns_init (&c, vardns_getargs (self));
  return vardns_c2id (self, &c);
}

- (vardns_t) vardns_value
{
  return value;
}

- dovardns_value:(vardns_t)aValue
{
  vardns_copy (&value, aValue, vardns_getargs (self));
  assert ([self check]);
  return self;
}

- vardns_value:(vardns_t)aValue
{
  return [[self clone] dovardns_value:aValue];
}

- (vardns_c *) vardns_reference
{
  return &value;
}

- dovardns_reference:(vardns_c *)aReference
{
  vardns_move (&value, aReference, vardns_getargs (self));
  assert ([self check]);
  return self;
}

- vardns_reference:(vardns_c *)aReference
{
  return [[self clone] dovardns_reference:aReference];
}

- (vardnsmonom_t) vardnsmonom_value
{
  return value;
}

- dovardnsmonom_value:(vardnsmonom_t)aValue
{
  vardns_copymonom (&value, aValue, vardns_getargs (self));
  assert ([self check]);
  return self;
}

- vardnsmonom_value:(vardnsmonom_t)aValue
{
  return [[self clone] dovardnsmonom_value:aValue];
}

- (vardnsmonom_c *) vardnsmonom_reference
{
  return value;
}

- vardnsmonom_reference:(vardnsmonom_c *)aReference
{
  return [self error:""];
}

- termOne 
{
  return termOne;
}
- symbols 
{
  return symbols;
}
- (BOOL)isVariableSparse 
{
  return NO;
}
- (BOOL)isVariableDense  
{
  return YES;
}

- (BOOL) sameClass:b
{
  return [super sameClass:b] && [symbols isEqual:[b symbols]];
}

- (int) numTerms
{
  return vardns_numterms (value, vardns_getargs (self));
}

- (BOOL) isEmpty
{
  return [self numTerms] == 0;
}

- (BOOL) isOne
{
  return [self numTerms] == 0;
}

- (int) compare:b
{
  return vardns_cmp (value, [b vardns_value], vardns_getargs (self));
}

- (BOOL) isEqual:b
{
  return vardns_iseq (value, [b vardns_value], vardns_getargs (self));
}

- (unsigned) hash
{
  return vardns_hash (value, vardns_getargs (self));
}

- eachTerm
{
  id aSequence = [vardns_sequence content:self];
  return [CASequence over:aSequence];
}

- elt_vardns_ix:(vardns_ixt)ix
{
  if (vardns_ix_ismatch (ix))
    {
      id c, s;
      int e;
      c = [termOne coefficient];
      e = vardns_expat (value, ix->i, vardns_getargs (self));
      s = (e) ? [symbols at : ix->i]:nil;
      return [termOne coefficient:c symbol:s exponent:e];
    }
  else
    {
      return nil;
    }
}


- removeTerm
{
  int i = vardns_findfirst (value, vardns_getargs (self));

  if (i == -1)
    {
      return nil;
    }
  else
    {
      id lt, c, s;
      int e;
      assert ([self check] == self);
      c = [termOne coefficient];
      e = vardns_expat (value, i, vardns_getargs (self));
      assert (e > 0);
      s = (e) ? [symbols at : i]:nil;
      lt = [termOne coefficient:c symbol:s exponent:e];
      vardns_setexpat (value, i, 0, vardns_getargs (self));
      [self invalidate];
      return lt;
    }
}

- insertTerm:aTerm
{
  int i;

  assert ([self check] && [[aTerm coefficient] isOne]);
  if ([aTerm exponent] == 0)
    {
      return self;
    }

  i = [symbols offsetOf:[aTerm symbol]];

  if (i == -1)
    {
      return [self error:"-insertTerm: illegal symbol"];
    }
  else
    {
      int e = vardns_expat (value, i, vardns_getargs (self));
      e += [aTerm exponent];
      if (e < 0)
	{
	  return nil;
	}
      else
	{
	  vardns_setexpat (value, i, e, vardns_getargs (self));
	  assert ([self check]);
	  return [self invalidate];
	}
    }
}


- fileOutOn:aFiler
{
  vardns_args args;
  [super fileOutOn:aFiler];
  args = vardns_getargs (self);
  vardns_args_fileOut (aFiler, &args);
  vardns_fileOut (aFiler, &value, args);
  return self;
}

- fileInFrom:aFiler
{
  vardns_args args;
  [super fileInFrom:aFiler];
  vardns_args_fileIn (aFiler, &args);
  vardns_fileIn (aFiler, &value, args);
  return self;
}

@end
 
