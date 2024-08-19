#include "cakit.h"

static void 
bigintobjvec_ix_init (bigintobjvec_ixt ix, id self)
{
  bigintobjvec_t v = [self bigintobjvec_value];
  ix->n = v->n;
}

static void 
bigintobjvec_ix_copy (bigintobjvec_ixt c, bigintobjvec_ixt a)
{
  c->i = a->i;
  c->n = a->n;
}

static void 
bigintobjvec_ix_clear (bigintobjvec_ixt ix)
{
  /* nothing to clear */
}

static int 
bigintobjvec_ix_count (bigintobjvec_ixt ix)
{
  return ix->n;
}

static int 
bigintobjvec_ix_isempty (bigintobjvec_ixt ix)
{
  return ix->n == 0;
}

static int 
bigintobjvec_ix_ismatch (bigintobjvec_ixt ix)
{
  assert (-1 <= ix->i && ix->i <= ix->n);
  return 0 <= ix->i && ix->i < ix->n;
}

static void 
bigintobjvec_ix_tofirst (bigintobjvec_ixt ix)
{
  ix->i = -1;			/* next -> first */
}

static void 
bigintobjvec_ix_tolast (bigintobjvec_ixt ix)
{
  ix->i = ix->n;		/* prev -> last */
}

static void 
bigintobjvec_ix_to (bigintobjvec_ixt ix, int i)
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
bigintobjvec_ix_next (bigintobjvec_ixt ix)
{
  ix->i = (ix->i < ix->n) ? ix->i + 1 : ix->n;
}

static void 
bigintobjvec_ix_prev (bigintobjvec_ixt ix)
{
  ix->i = (0 <= ix->i) ? ix->i - 1 : -1;
}
@implementation bigintobjvec_sequence : sequencec

- _setUpContent:anObject
{
  content = anObject;
  bigintobjvec_ix_init (&ix, content);
  return self;
}

+ content:anObject
{
  return [[super new] _setUpContent:anObject];
}

- release
{
  bigintobjvec_ix_clear (&ix);
  if (currentMember)
    currentMember = nil;
  return [super release];
}

- (unsigned) size
{
  return bigintobjvec_ix_count (&ix);
}

- (BOOL) isEmpty
{
  return bigintobjvec_ix_isempty (&ix);
}

- toFirst
{
  bigintobjvec_ix_tofirst (&ix);
  return self;
}

- toLast
{
  bigintobjvec_ix_tolast (&ix);
  return self;
}

- toElementAt:(int)i
{
  bigintobjvec_ix_to (&ix, i);
  return self;
}

- currentMember
{
  if (currentMember)
    currentMember = nil;
  return currentMember = [content elt_bigintobjvec_ix:&ix];
}

- next
{
  bigintobjvec_ix_next (&ix);
  return [self currentMember];
}

- previous
{
  bigintobjvec_ix_prev (&ix);
  return [self currentMember];
}

@end
 
