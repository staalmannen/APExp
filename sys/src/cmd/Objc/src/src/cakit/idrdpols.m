#include "cakit.h"

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
@implementation bigintobj_vardnsrecdegdnspol_sequence : sequencec

- _setUpContent:anObject
{
  content = anObject;
  bigintobj_vardnsrecdegdnspol_ix_init (&ix, content);
  return self;
}

+ content:anObject
{
  return [[super new] _setUpContent:anObject];
}

- release
{
  bigintobj_vardnsrecdegdnspol_ix_clear (&ix);
  if (currentMember)
    currentMember = nil;
  return [super release];
}

- (unsigned) size
{
  return bigintobj_vardnsrecdegdnspol_ix_count (&ix);
}

- (BOOL) isEmpty
{
  return bigintobj_vardnsrecdegdnspol_ix_isempty (&ix);
}

- toFirst
{
  bigintobj_vardnsrecdegdnspol_ix_tofirst (&ix);
  return self;
}

- toLast
{
  bigintobj_vardnsrecdegdnspol_ix_tolast (&ix);
  return self;
}

- toElementAt:(int)i
{
  bigintobj_vardnsrecdegdnspol_ix_to (&ix, i);
  return self;
}

- currentMember
{
  if (currentMember)
    currentMember = nil;
  return currentMember = [content elt_bigintobj_vardnsrecdegdnspol_ix:&ix];
}

- next
{
  bigintobj_vardnsrecdegdnspol_ix_next (&ix);
  return [self currentMember];
}

- previous
{
  bigintobj_vardnsrecdegdnspol_ix_prev (&ix);
  return [self currentMember];
}

@end
 
