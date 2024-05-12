#include "cakit.h"

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

@implementation vardns_sequence : sequencec

- _setUpContent:anObject
{
  content = anObject;
  vardns_ix_init (&ix, content);
  return self;
}

+ content:anObject
{
  return [[super new] _setUpContent:anObject];
}

- release
{
  vardns_ix_clear (&ix);
  if (currentMember)
    currentMember = nil;
  return [super release];
}

- (unsigned) size
{
  return vardns_ix_count (&ix);
}

- (BOOL) isEmpty
{
  return vardns_ix_isempty (&ix);
}

- toFirst
{
  vardns_ix_tofirst (&ix);
  return self;
}

- toLast
{
  vardns_ix_tolast (&ix);
  return self;
}

- toElementAt:(int)i
{
  vardns_ix_to (&ix, i);
  return self;
}

- currentMember
{
  if (currentMember)
    currentMember = nil;
  return currentMember = [content elt_vardns_ix:&ix];
}

- next
{
  vardns_ix_next (&ix);
  return [self currentMember];
}

- previous
{
  vardns_ix_prev (&ix);
  return [self currentMember];
}

@end
 
