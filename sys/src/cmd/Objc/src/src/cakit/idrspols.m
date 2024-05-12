#include "cakit.h"

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
@implementation bigintobj_vardnsrecdegspspol_sequence : sequencec

- _setUpContent:anObject
{
  content = anObject;
  bigintobj_vardnsrecdegspspol_ix_init (&ix, content);
  return self;
}

+ content:anObject
{
  return [[super new] _setUpContent:anObject];
}

- release
{
  bigintobj_vardnsrecdegspspol_ix_clear (&ix);
  if (currentMember)
    currentMember = nil;
  return [super release];
}

- (unsigned) size
{
  return bigintobj_vardnsrecdegspspol_ix_count (&ix);
}

- (BOOL) isEmpty
{
  return bigintobj_vardnsrecdegspspol_ix_isempty (&ix);
}

- toFirst
{
  bigintobj_vardnsrecdegspspol_ix_tofirst (&ix);
  return self;
}

- toLast
{
  bigintobj_vardnsrecdegspspol_ix_tolast (&ix);
  return self;
}

- toElementAt:(int)i
{
  bigintobj_vardnsrecdegspspol_ix_to (&ix, i);
  return self;
}

- currentMember
{
  if (currentMember)
    currentMember = nil;
  return currentMember = [content elt_bigintobj_vardnsrecdegspspol_ix:&ix];
}

- next
{
  bigintobj_vardnsrecdegspspol_ix_next (&ix);
  return [self currentMember];
}

- previous
{
  bigintobj_vardnsrecdegspspol_ix_prev (&ix);
  return [self currentMember];
}

@end
 
