#include "cakit.h"

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
@implementation obj_vardnsrecdegspspol_sequence : sequencec

- _setUpContent:anObject
{
  content = anObject;
  obj_vardnsrecdegspspol_ix_init (&ix, content);
  return self;
}

+ content:anObject
{
  return [[super new] _setUpContent:anObject];
}

- release
{
  obj_vardnsrecdegspspol_ix_clear (&ix);
  if (currentMember)
    currentMember = nil;
  return [super release];
}

- (unsigned) size
{
  return obj_vardnsrecdegspspol_ix_count (&ix);
}

- (BOOL) isEmpty
{
  return obj_vardnsrecdegspspol_ix_isempty (&ix);
}

- toFirst
{
  obj_vardnsrecdegspspol_ix_tofirst (&ix);
  return self;
}

- toLast
{
  obj_vardnsrecdegspspol_ix_tolast (&ix);
  return self;
}

- toElementAt:(int)i
{
  obj_vardnsrecdegspspol_ix_to (&ix, i);
  return self;
}

- currentMember
{
  if (currentMember)
    currentMember = nil;
  return currentMember = [content elt_obj_vardnsrecdegspspol_ix:&ix];
}

- next
{
  obj_vardnsrecdegspspol_ix_next (&ix);
  return [self currentMember];
}

- previous
{
  obj_vardnsrecdegspspol_ix_prev (&ix);
  return [self currentMember];
}

@end
 
