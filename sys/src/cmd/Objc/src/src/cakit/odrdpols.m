#include "cakit.h"

static void 
obj_vardnsrecdegdnspol_ix_init (obj_vardnsrecdegdnspol_ixt ix, id self)
{
  obj_vardnsrecdegdnspol_t v = [self obj_vardnsrecdegdnspol_value];
  ix->i = -1;
  ix->n = v->n;
}

static void 
obj_vardnsrecdegdnspol_ix_clear (obj_vardnsrecdegdnspol_ixt ix)
{
  /* nothing to clear */
}

static int 
obj_vardnsrecdegdnspol_ix_count (obj_vardnsrecdegdnspol_ixt ix)
{
  return ix->n;			/* total number, zero or nonzero */
}

static int 
obj_vardnsrecdegdnspol_ix_isempty (obj_vardnsrecdegdnspol_ixt ix)
{
  return ix->n == 0;
}

static int 
obj_vardnsrecdegdnspol_ix_ismatch (obj_vardnsrecdegdnspol_ixt ix)
{
  assert (-1 <= ix->i && ix->i <= ix->n);
  return (ix->i != -1 && ix->i != ix->n);
}

static void 
obj_vardnsrecdegdnspol_ix_tofirst (obj_vardnsrecdegdnspol_ixt ix)
{
  ix->i = -1;			/* next = first */
}

static void 
obj_vardnsrecdegdnspol_ix_tolast (obj_vardnsrecdegdnspol_ixt ix)
{
  ix->i = ix->n;		/* prev = last */
}

static void 
obj_vardnsrecdegdnspol_ix_to (obj_vardnsrecdegdnspol_ixt ix, int i)
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
obj_vardnsrecdegdnspol_ix_next (obj_vardnsrecdegdnspol_ixt ix)
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
obj_vardnsrecdegdnspol_ix_prev (obj_vardnsrecdegdnspol_ixt ix)
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
@implementation obj_vardnsrecdegdnspol_sequence : sequencec

- _setUpContent:anObject
{
  content = anObject;
  obj_vardnsrecdegdnspol_ix_init (&ix, content);
  return self;
}

+ content:anObject
{
  return [[super new] _setUpContent:anObject];
}

- release
{
  obj_vardnsrecdegdnspol_ix_clear (&ix);
  if (currentMember)
    currentMember = nil;
  return [super release];
}

- (unsigned) size
{
  return obj_vardnsrecdegdnspol_ix_count (&ix);
}

- (BOOL) isEmpty
{
  return obj_vardnsrecdegdnspol_ix_isempty (&ix);
}

- toFirst
{
  obj_vardnsrecdegdnspol_ix_tofirst (&ix);
  return self;
}

- toLast
{
  obj_vardnsrecdegdnspol_ix_tolast (&ix);
  return self;
}

- toElementAt:(int)i
{
  obj_vardnsrecdegdnspol_ix_to (&ix, i);
  return self;
}

- currentMember
{
  if (currentMember)
    currentMember = nil;
  return currentMember = [content elt_obj_vardnsrecdegdnspol_ix:&ix];
}

- next
{
  obj_vardnsrecdegdnspol_ix_next (&ix);
  return [self currentMember];
}

- previous
{
  obj_vardnsrecdegdnspol_ix_prev (&ix);
  return [self currentMember];
}

@end
 
