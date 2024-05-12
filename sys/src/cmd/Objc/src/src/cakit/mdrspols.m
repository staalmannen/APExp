#include "cakit.h"

static void 
modp_vardnsrecdegspspol_ix_init (modp_vardnsrecdegspspol_ixt ix, id self)
{
  modp_vardnsrecdegspspol_t v = [self modp_vardnsrecdegspspol_value];
  ix->head = v;
  ix->ix = v;
}

static void 
modp_vardnsrecdegspspol_ix_clear (modp_vardnsrecdegspspol_ixt ix)
{
  /* nothing to clear */
}

static int 
modp_vardnsrecdegspspol_ix_count_aux_aux (modp_vardnsrecdegspsterm_t A, modp_vardnsrecdegspsterm_t AT)
{
  int c = 0;
  for (; A != AT; A = A->nlink)
    c++;
  return c;
}

static int 
modp_vardnsrecdegspspol_ix_count_aux (modp_vardnsrecdegspspol_t self)
{
  return modp_vardnsrecdegspspol_ix_count_aux_aux (self->nlink, self);
}

static int 
modp_vardnsrecdegspspol_ix_count (modp_vardnsrecdegspspol_ixt ix)
{
  /* merde ! can't include entire modp_vardnsrecdegspslist for modp_vardnsrecdegspslist_count */
  return modp_vardnsrecdegspspol_ix_count_aux (ix->head);
}

static int 
modp_vardnsrecdegspspol_ix_isempty_aux (modp_vardnsrecdegspspol_t self)
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
modp_vardnsrecdegspspol_ix_isempty (modp_vardnsrecdegspspol_ixt ix)
{
  /* can't include entire modp_vardnsrecdegspspol for modp_vardnsrecdegspspol_isempty */
  return modp_vardnsrecdegspspol_ix_isempty_aux (ix->head);
}

static int 
modp_vardnsrecdegspspol_ix_ismatch (modp_vardnsrecdegspspol_ixt ix)
{
  return (ix->ix != NULL && ix->ix != ix->head);
}

static void 
modp_vardnsrecdegspspol_ix_tofirst (modp_vardnsrecdegspspol_ixt ix)
{
  ix->ix = ix->head;
}

static void 
modp_vardnsrecdegspspol_ix_tolast (modp_vardnsrecdegspspol_ixt ix)
{
  ix->ix = NULL;
}

static void 
modp_vardnsrecdegspspol_ix_to (modp_vardnsrecdegspspol_ixt ix, int i)
{
  fprintf (stderr, "at: notImplemented\n");
}

static void 
modp_vardnsrecdegspspol_ix_next (modp_vardnsrecdegspspol_ixt ix)
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
modp_vardnsrecdegspspol_ix_prev (modp_vardnsrecdegspspol_ixt ix)
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
@implementation modp_vardnsrecdegspspol_sequence : sequencec

- _setUpContent:anObject
{
  content = anObject;
  modp_vardnsrecdegspspol_ix_init (&ix, content);
  return self;
}

+ content:anObject
{
  return [[super new] _setUpContent:anObject];
}

- release
{
  modp_vardnsrecdegspspol_ix_clear (&ix);
  if (currentMember)
    currentMember = nil;
  return [super release];
}

- (unsigned) size
{
  return modp_vardnsrecdegspspol_ix_count (&ix);
}

- (BOOL) isEmpty
{
  return modp_vardnsrecdegspspol_ix_isempty (&ix);
}

- toFirst
{
  modp_vardnsrecdegspspol_ix_tofirst (&ix);
  return self;
}

- toLast
{
  modp_vardnsrecdegspspol_ix_tolast (&ix);
  return self;
}

- toElementAt:(int)i
{
  modp_vardnsrecdegspspol_ix_to (&ix, i);
  return self;
}

- currentMember
{
  if (currentMember)
    currentMember = nil;
  return currentMember = [content elt_modp_vardnsrecdegspspol_ix:&ix];
}

- next
{
  modp_vardnsrecdegspspol_ix_next (&ix);
  return [self currentMember];
}

- previous
{
  modp_vardnsrecdegspspol_ix_prev (&ix);
  return [self currentMember];
}

@end
 
