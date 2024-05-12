#include "cakit.h"

static void 
modp_vardnsrecdegdnspol_ix_init (modp_vardnsrecdegdnspol_ixt ix, id self)
{
  modp_vardnsrecdegdnspol_t v = [self modp_vardnsrecdegdnspol_value];
  ix->i = -1;
  ix->n = v->n;
}

static void 
modp_vardnsrecdegdnspol_ix_clear (modp_vardnsrecdegdnspol_ixt ix)
{
  /* nothing to clear */
}

static int 
modp_vardnsrecdegdnspol_ix_count (modp_vardnsrecdegdnspol_ixt ix)
{
  return ix->n;			/* total number, zero or nonzero */
}

static int 
modp_vardnsrecdegdnspol_ix_isempty (modp_vardnsrecdegdnspol_ixt ix)
{
  return ix->n == 0;
}

static int 
modp_vardnsrecdegdnspol_ix_ismatch (modp_vardnsrecdegdnspol_ixt ix)
{
  assert (-1 <= ix->i && ix->i <= ix->n);
  return (ix->i != -1 && ix->i != ix->n);
}

static void 
modp_vardnsrecdegdnspol_ix_tofirst (modp_vardnsrecdegdnspol_ixt ix)
{
  ix->i = -1;			/* next = first */
}

static void 
modp_vardnsrecdegdnspol_ix_tolast (modp_vardnsrecdegdnspol_ixt ix)
{
  ix->i = ix->n;		/* prev = last */
}

static void 
modp_vardnsrecdegdnspol_ix_to (modp_vardnsrecdegdnspol_ixt ix, int i)
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
modp_vardnsrecdegdnspol_ix_next (modp_vardnsrecdegdnspol_ixt ix)
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
modp_vardnsrecdegdnspol_ix_prev (modp_vardnsrecdegdnspol_ixt ix)
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
@implementation modp_vardnsrecdegdnspol_sequence : sequencec

- _setUpContent:anObject
{
  content = anObject;
  modp_vardnsrecdegdnspol_ix_init (&ix, content);
  return self;
}

+ content:anObject
{
  return [[super new] _setUpContent:anObject];
}

- release
{
  modp_vardnsrecdegdnspol_ix_clear (&ix);
  if (currentMember)
    currentMember = nil;
  return [super release];
}

- (unsigned) size
{
  return modp_vardnsrecdegdnspol_ix_count (&ix);
}

- (BOOL) isEmpty
{
  return modp_vardnsrecdegdnspol_ix_isempty (&ix);
}

- toFirst
{
  modp_vardnsrecdegdnspol_ix_tofirst (&ix);
  return self;
}

- toLast
{
  modp_vardnsrecdegdnspol_ix_tolast (&ix);
  return self;
}

- toElementAt:(int)i
{
  modp_vardnsrecdegdnspol_ix_to (&ix, i);
  return self;
}

- currentMember
{
  if (currentMember)
    currentMember = nil;
  return currentMember = [content elt_modp_vardnsrecdegdnspol_ix:&ix];
}

- next
{
  modp_vardnsrecdegdnspol_ix_next (&ix);
  return [self currentMember];
}

- previous
{
  modp_vardnsrecdegdnspol_ix_prev (&ix);
  return [self currentMember];
}

@end
 
