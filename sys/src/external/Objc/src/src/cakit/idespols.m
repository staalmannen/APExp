#include "cakit.h"

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
@implementation bigintobj_vardnsexpdegspspol_sequence : sequencec

- _setUpContent:anObject
{
  content = anObject;
  bigintobj_vardnsexpdegspspol_ix_init (&ix, content);
  return self;
}

+ content:anObject
{
  return [[super new] _setUpContent:anObject];
}

- release
{
  bigintobj_vardnsexpdegspspol_ix_clear (&ix);
  if (currentMember)
    currentMember = nil;
  return [super release];
}

- (unsigned) size
{
  return bigintobj_vardnsexpdegspspol_ix_count (&ix);
}

- (BOOL) isEmpty
{
  return bigintobj_vardnsexpdegspspol_ix_isempty (&ix);
}

- toFirst
{
  bigintobj_vardnsexpdegspspol_ix_tofirst (&ix);
  return self;
}

- toLast
{
  bigintobj_vardnsexpdegspspol_ix_tolast (&ix);
  return self;
}

- toElementAt:(int)i
{
  bigintobj_vardnsexpdegspspol_ix_to (&ix, i);
  return self;
}

- currentMember
{
  if (currentMember)
    currentMember = nil;
  return currentMember = [content elt_bigintobj_vardnsexpdegspspol_ix:&ix];
}

- next
{
  bigintobj_vardnsexpdegspspol_ix_next (&ix);
  return [self currentMember];
}

- previous
{
  bigintobj_vardnsexpdegspspol_ix_prev (&ix);
  return [self currentMember];
}

@end
 
