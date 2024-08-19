#include "cakit.h"

static void 
modpvec_ix_init (modpvec_ixt ix, id self)
{
  modpvec_t v = [self modpvec_value];
  ix->n = v->n;
}

static void 
modpvec_ix_copy (modpvec_ixt c, modpvec_ixt a)
{
  c->i = a->i;
  c->n = a->n;
}

static void 
modpvec_ix_clear (modpvec_ixt ix)
{
  /* nothing to clear */
}

static int 
modpvec_ix_count (modpvec_ixt ix)
{
  return ix->n;
}

static int 
modpvec_ix_isempty (modpvec_ixt ix)
{
  return ix->n == 0;
}

static int 
modpvec_ix_ismatch (modpvec_ixt ix)
{
  assert (-1 <= ix->i && ix->i <= ix->n);
  return 0 <= ix->i && ix->i < ix->n;
}

static void 
modpvec_ix_tofirst (modpvec_ixt ix)
{
  ix->i = -1;			/* next -> first */
}

static void 
modpvec_ix_tolast (modpvec_ixt ix)
{
  ix->i = ix->n;		/* prev -> last */
}

static void 
modpvec_ix_to (modpvec_ixt ix, int i)
{
  /* the actual position is n-i-1; conversion done in elting routine... */
  if (i < 0)
    ix->i = -1;
  else if (i > ix->n)
    ix->i = ix->n;
  else
    ix->i = i - 1;		/* next -> at i */
}

static void 
modpvec_ix_next (modpvec_ixt ix)
{
  ix->i = (ix->i < ix->n) ? ix->i + 1 : ix->n;
}

static void 
modpvec_ix_prev (modpvec_ixt ix)
{
  ix->i = (0 <= ix->i) ? ix->i - 1 : -1;
}
@implementation modpvec_sequence : sequencec

- _setUpContent:anObject
{
  content = anObject;
  modpvec_ix_init (&ix, content);
  return self;
}

+ content:anObject
{
  return [[super new] _setUpContent:anObject];
}

- release
{
  modpvec_ix_clear (&ix);
  if (currentMember)
    currentMember = nil;
  return [super release];
}

- (unsigned) size
{
  return modpvec_ix_count (&ix);
}

- (BOOL) isEmpty
{
  return modpvec_ix_isempty (&ix);
}

- toFirst
{
  modpvec_ix_tofirst (&ix);
  return self;
}

- toLast
{
  modpvec_ix_tolast (&ix);
  return self;
}

- toElementAt:(int)i
{
  modpvec_ix_to (&ix, i);
  return self;
}

- currentMember
{
  if (currentMember)
    currentMember = nil;
  return currentMember = [content elt_modpvec_ix:&ix];
}

- next
{
  modpvec_ix_next (&ix);
  return [self currentMember];
}

- previous
{
  modpvec_ix_prev (&ix);
  return [self currentMember];
}

@end
 
