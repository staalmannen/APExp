#include "cakit.h"

static void 
objvec_ix_init (objvec_ixt ix, id self)
{
  objvec_t v = [self objvec_value];
  ix->n = v->n;
}

static void 
objvec_ix_copy (objvec_ixt c, objvec_ixt a)
{
  c->i = a->i;
  c->n = a->n;
}

static void 
objvec_ix_clear (objvec_ixt ix)
{
  /* nothing to clear */
}

static int 
objvec_ix_count (objvec_ixt ix)
{
  return ix->n;
}

static int 
objvec_ix_isempty (objvec_ixt ix)
{
  return ix->n == 0;
}

static int 
objvec_ix_ismatch (objvec_ixt ix)
{
  assert (-1 <= ix->i && ix->i <= ix->n);
  return 0 <= ix->i && ix->i < ix->n;
}

static void 
objvec_ix_tofirst (objvec_ixt ix)
{
  ix->i = -1;			/* next -> first */
}

static void 
objvec_ix_tolast (objvec_ixt ix)
{
  ix->i = ix->n;		/* prev -> last */
}

static void 
objvec_ix_to (objvec_ixt ix, int i)
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
objvec_ix_next (objvec_ixt ix)
{
  ix->i = (ix->i < ix->n) ? ix->i + 1 : ix->n;
}

static void 
objvec_ix_prev (objvec_ixt ix)
{
  ix->i = (0 <= ix->i) ? ix->i - 1 : -1;
}
@implementation objvec_sequence : sequencec

- _setUpContent:anObject
{
  content = anObject;
  objvec_ix_init (&ix, content);
  return self;
}

+ content:anObject
{
  return [[super new] _setUpContent:anObject];
}

- release
{
  objvec_ix_clear (&ix);
  if (currentMember)
    currentMember = nil;
  return [super release];
}

- (unsigned) size
{
  return objvec_ix_count (&ix);
}

- (BOOL) isEmpty
{
  return objvec_ix_isempty (&ix);
}

- toFirst
{
  objvec_ix_tofirst (&ix);
  return self;
}

- toLast
{
  objvec_ix_tolast (&ix);
  return self;
}

- toElementAt:(int)i
{
  objvec_ix_to (&ix, i);
  return self;
}

- currentMember
{
  if (currentMember)
    currentMember = nil;
  return currentMember = [content elt_objvec_ix:&ix];
}

- next
{
  objvec_ix_next (&ix);
  return [self currentMember];
}

- previous
{
  objvec_ix_prev (&ix);
  return [self currentMember];
}

@end
 
