
/*
 * Portable Object Compiler (c) 1997,98,2003.  All Rights Reserved.
 * $Id: sortcltn.m,v 1.6 2020/04/16 19:16:08 stes Exp $
 */

/*
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Library General Public License as published 
 * by the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "config.h"
#include <assert.h>
#include <stdlib.h>
#include "sortcltn.h"
#include "treeseq.h"
#include "set.h"
#include "ordcltn.h"
#include "ascfiler.h"
#include "sequence.h"
#include "ocstring.h"
#if OBJC_BLOCKS
#include "Block.h"
#endif

#ifndef NDEBUG
#define CHECK_BALANCE
#endif

@implementation SortCltn

/*****************************************************************************
 *
 * Creation
 *
 ****************************************************************************/

static objbbt_t 
alloc ()
{
  return (objbbt_t) OC_Malloc (sizeof (struct objbbt));
}

static objbbt_t 
init (objbbt_t self, id key)
{
  self->ulink = NULL;
  self->llink = NULL;
  self->rlink = NULL;
  self->key = key;
  self->balance = 0;
  return self;
}

static objbbt_t 
create (id key)
{
  return init (alloc (), key);
}

static int 
signum (objbbt_t ulink, objbbt_t self)
{
  assert (ulink->llink == self || ulink->rlink == self);
  return (ulink->llink == self) ? -1 : +1;
}

static objbbt_t 
slink (objbbt_t self, int sign)
{
  assert (sign == +1 || sign == -1);
  return (sign > 0) ? self->rlink : self->llink;
}

static void 
setllink (objbbt_t self, objbbt_t node)
{
  self->llink = node;
  if (node)
    node->ulink = self;
}

static void 
setrlink (objbbt_t self, objbbt_t node)
{
  self->rlink = node;
  if (node)
    node->ulink = self;
}

static void 
setslink (objbbt_t self, objbbt_t node, int sign)
{
  if (sign > 0)
    setrlink (self, node);
  else
    setllink (self, node);
}

static void 
freeobjects (objbbt_t self)
{
  if (self->llink)
    freeobjects (self->llink);
  if (self->rlink)
    freeobjects (self->rlink);
  self->key = [self->key free];
}

static objbbt_t 
destroy (objbbt_t self)
{
  if (self->llink)
    self->llink = destroy (self->llink);
  if (self->rlink)
    self->rlink = destroy (self->rlink);
  self->key = nil;
  OC_Free (self);
  return NULL;
}

+ new
{
  return [self newCmpSel:@selector (compare:)];
}

+ new:(unsigned)n
{
  return [self new];
}

+ newDictCompare
{
  return [self newCmpSel:@selector (dictCompare:)];
}

- setupcmpblock:sortBlock
{
  cmpBlk = sortBlock;
  init (&value, (id) 0xdeadbeaf);
  return self;
}

#ifndef __PORTABLE_OBJC__
- shouldNotImplement
{
  return nil;
}
#endif

+ sortBy:sortBlock
{
#if OBJC_BLOCKS
  id newObj = [super new];
  [newObj setupcmpblock:sortBlock];
  return newObj;
#else
  return [self shouldNotImplement];
#endif
}

+ sortBlock:sortBlock
{
  return [self sortBy:sortBlock];
}

- setupcmpsel:(SEL)aSel
{
  cmpSel = aSel;
  init (&value, (id) 0);
  return self;
}

+ newCmpSel:(SEL)aSel
{
  id newObj = [super new];
  [newObj setupcmpsel:aSel];
  return newObj;
}

/*****************************************************************************
 *
 * Creating with contents.
 *
 ****************************************************************************/

+ with:(int)nArgs,...
{
  id newObject;

  /* use OC macros for porting to SunOS4 */
  OC_VA_LIST vp;

  newObject = [self new];

  /* #if 0 this piece of code if problems with stdarg
   * typically this means the driver is not configured with
   * the right -builtintype
   * or builtinfunction flags (because the macros might expand to these)
   * 
   * alternative solution: check the .P output (-retain) and 
   * do a setenv OBJCOPT -builtinfunction __builtin_foo
   * (and please let me know)
   */

#ifdef NSTDARG
  [self notImplemented];
#else
  OC_VA_START (vp, nArgs);
  while (nArgs-- > 0)
    {
      id anObject = OC_VA_ARG (vp, id);
      [newObject add:anObject];
    }
  OC_VA_END (vp);
#endif

  return newObject;
}

+ with:firstObject with:nextObject
{
  return [[[self new] add:firstObject] add:nextObject];
}

+ add:firstObject
{
  return [[self new] add:firstObject];
}

- copy
{
  return [[isa new] addAll:self];
}

- deepCopy
{
  id aSeq, elt;
  id aCopy = [isa new];

  aSeq = [self eachElement];
  while ((elt = [aSeq next]))
    [aCopy add:[elt deepCopy]];
#ifndef OBJC_REFCNT
  aSeq = [aSeq free];
#endif

  return aCopy;
}

- emptyYourself
{
  if (value.llink)
    value.llink = destroy (value.llink);
  return self;
}

- freeContents
{
  if (value.llink)
    {
      freeobjects (value.llink);
      value.llink = destroy (value.llink);
    }
  return self;
}

- free
{
  if (value.llink)
    value.llink = destroy (value.llink);
  return [super free];
}

- release
{
#ifdef OBJC_REFCNT
  [self emptyYourself];
  return [super release];
#else
  return [self notImplemented:_cmd];
#endif
}

/*****************************************************************************
 *
 * Interrogation
 *
 ****************************************************************************/

- (objbbt_t) objbbtTop
{
  return value.llink;
}

- (SEL) comparisonSelector
{
  return cmpSel;
}

static int 
size (objbbt_t self)
{
  int n = 1;
  if (self->llink)
    n += size (self->llink);
  if (self->rlink)
    n += size (self->rlink);
  return n;
}

- (unsigned) size
{
  return (value.llink) ? size (value.llink) : 0;
}

- (BOOL) isEmpty
{
  return value.llink == NULL;
}

- eachElement
{
  id aCarrier = [TreeSequence over:self];
  return [Sequence over:aCarrier];
}

/*****************************************************************************
 *
 * Comparing
 *
 ****************************************************************************/

- (unsigned) hash
{
  [self notImplemented:_cmd];
  return 0;
}

- (BOOL) isEqual:aSort
{
  [self notImplemented:_cmd];
  return NO;
}

/*****************************************************************************
 *
 * Adding
 *
 ****************************************************************************/

static int 
cmp (objbbt_t self, id key, SEL cmpSel, id cmpBlk, objbbt_t * offset)
{
  int c = 0;
  objbbt_t link;
  id bkey = self->key;

  if (cmpBlk)
    {
#if OBJC_BLOCKS
      if (key == bkey)
	{
	  c = 0;
	}
      else
	{
	  c = [cmpBlk intvalue:key value:bkey];
	}
#endif
    }
  else
    {
      if (key == bkey)
	{
	  c = 0;
	}
      else
	{
	  c = ((int (*)(id, SEL, id)) [key methodFor:cmpSel]) (key, cmpSel, bkey);
	}
    }

  if (c == 0)
    {
      *offset = self;
      return c;
    }
  link = (c < 0) ? self->llink : self->rlink;

  return (link) ? cmp (link, key, cmpSel, cmpBlk, offset) : (*offset = self, c);
}

static int 
cmpne (objbbt_t self, id key, SEL cmpSel, id cmpBlk, objbbt_t * offset)
{
  int c = 0;
  objbbt_t link;
  id bkey = self->key;

  if (cmpBlk)
    {
#if OBJC_BLOCKS
      if (key == bkey)
	{
	  c = 0;
	}
      else
	{
	  c = [cmpBlk intvalue:key value:bkey];
	}
#endif
    }
  else
    {
      if (key == bkey)
	{
	  c = 0;
	}
      else
	{
	  c = ((int (*)(id, SEL, id)) [key methodFor:cmpSel]) (key, cmpSel, bkey);
	}
    }

  if (c == 0)
    {
      c = +1;
    }
  link = (c < 0) ? self->llink : self->rlink;

  return (link) ? cmpne (link, key, cmpSel, cmpBlk, offset) : (*offset = self, c);
}

static int 
height (objbbt_t self)
{
  if (self)
    {
      int a, b;
      a = height (self->llink);
      b = height (self->rlink);
      assert (self->balance == (b - a));
      return 1 + ((a > b) ? a : b);
    }
  else
    {
      return 0;
    }
}

static objbbt_t 
bnode (objbbt_t top, objbbt_t newp)
{
  while (newp != top && newp->balance == 0)
    newp = newp->ulink;
  assert (newp->balance != 0 || newp == top);
  return newp;
}

static int 
adjust (objbbt_t b, objbbt_t newp)
{
  int sign = 0;
  objbbt_t ulink;

  while (1)
    {
      ulink = newp->ulink;
      sign = signum (ulink, newp);
      if (ulink == b)
	break;
      assert (ulink->balance == 0);
      ulink->balance = sign;
      newp = ulink;
    }

  return sign;
}

/*
 *                A                       B
 *               / \                     / \
 *              a   B       --->        A   \
 *             /   / \                 / \   c
 *                b   c               a   b   \
 *               /     \             /     \   \
 *                      \
 */

static void 
sglrot (objbbt_t A, objbbt_t B, int sign)
{
  objbbt_t U = A->ulink;
  setslink (A, slink (B, -sign), sign);
  setslink (B, A, -sign);
  A->balance = 0;
  B->balance = 0;
  setslink (U, B, signum (U, A));
}

/*                                            
 *                A                            X      
 *               / \                        /     \
 *              a   B       --->           A       B   
 *             /   / \                    / \     / \ 
 *                X   d                  a   b   c   d
 *               / \   \                /     \ /     \  
 *              b   c                                
 *             /     \
 */

static void 
dblrot (objbbt_t A, objbbt_t B, int sign)
{
  objbbt_t U = A->ulink;
  objbbt_t X = slink (B, -sign);

  setslink (B, slink (X, sign), -sign);
  setslink (X, B, +sign);
  setslink (A, slink (X, -sign), sign);
  setslink (X, A, -sign);

  if (X->balance == +sign)
    {
      A->balance = -sign;
      B->balance = 0;
    }
  if (X->balance == 0)
    {
      A->balance = 0;
      B->balance = 0;
    }
  if (X->balance == -sign)
    {
      A->balance = 0;
      B->balance = +sign;
    }

  X->balance = 0;
  setslink (U, X, signum (U, A));
}

static void 
rot (objbbt_t A, int sign)
{
  objbbt_t B = slink (A, sign);
  assert (sign == A->balance && sign != 0 && B->balance != 0);
  /* SGI cc doesn't like return of a 'void' function */
  if (sign == +B->balance)
    {
      sglrot (A, B, sign);
      return;
    }
  if (sign == -B->balance)
    {
      dblrot (A, B, sign);
      return;
    }
}

static void 
rebalance (objbbt_t top, objbbt_t newp)
{
  int sign;
  objbbt_t b;

  b = bnode (top, newp);
  sign = adjust (b, newp);

  if (b->balance == 0)
    {
      b->balance = sign;
      return;
    }
  if (b->balance == -sign)
    {
      b->balance = 0;
      return;
    }
  if (b->balance == +sign)
    {
      rot (b, sign);
      return;
    }
}

static void 
addfirst (objbbt_t self, id key)
{
  setllink (self, create (key));
}

static void 
addat (objbbt_t top, id key, int c, objbbt_t offset)
{
  objbbt_t newp = create (key);

  assert (c < 0 || c > 0);
  if (c < 0)
    setllink (offset, newp);
  if (c > 0)
    setrlink (offset, newp);

  rebalance (top, newp);

#ifdef CHECK_BALANCE
  assert (height (top) > 0);
#endif
}

static void 
add (objbbt_t top, id key, SEL selCmp, id cmpBlk)
{
  objbbt_t offset = NULL;
  int c = cmpne (top, key, selCmp, cmpBlk, &offset);
  addat (top, key, c, offset);
}

- add:anObject
{
  if (anObject)
    {
      if (value.llink)
	{
	  add (value.llink, anObject, cmpSel, cmpBlk);
	  return self;
	}
      else
	{
	  addfirst (&value, anObject);
	  return self;
	}
    }
  else
    {
      return nil;
    }
}

static id 
addnfind (objbbt_t top, id key, SEL selCmp, id cmpBlk)
{
  objbbt_t offset = NULL;
  int c = cmpne (top, key, selCmp, cmpBlk, &offset);
  if (c == 0)
    {
      return offset->key;
    }
  else
    {
      addat (top, key, c, offset);
      return key;
    }
}

- addNTest:anObject
{
  if (anObject)
    {
      if (value.llink)
	{
	  id res = addnfind (value.llink, anObject, cmpSel, cmpBlk);
	  return (res == anObject) ? anObject : nil;
	}
      else
	{
	  addfirst (&value, anObject);
	  return anObject;
	}
    }
  else
    {
      return nil;
    }
}

- filter:anObject
{
  if (anObject)
    {
      if (value.llink)
	{
	  id res = addnfind (value.llink, anObject, cmpSel, cmpBlk);
#ifndef OBJC_REFCNT
	  return (res == anObject) ? anObject : ([anObject free], res);
#else
	  return (res == anObject) ? anObject : res;
#endif
	}
      else
	{
	  addfirst (&value, anObject);
	  return anObject;
	}
    }
  else
    {
      return nil;
    }
}

static id 
replace (objbbt_t top, id key, SEL selCmp, id cmpBlk)
{
  objbbt_t offset = NULL;
  int c = cmpne (top, key, selCmp, cmpBlk, &offset);
  if (c == 0)
    {
      id tmp = offset->key;
      offset->key = key;
      return tmp;
    }
  else
    {
      addat (top, key, c, offset);
      return nil;
    }
}

- replace:anObject
{
  if (anObject)
    {
      if (value.llink)
	{
	  return replace (value.llink, anObject, cmpSel, cmpBlk);
	}
      else
	{
	  addfirst (&value, anObject);
	  return nil;
	}
    }
  else
    {
      return nil;
    }
}

/*****************************************************************************
 *
 * Removing
 *
 ****************************************************************************/

- remove:oldObject
{
  if (oldObject)
    {
      return [self notImplemented:_cmd];
    }
  else
    {
      return nil;
    }
}

/*****************************************************************************
 *
 * Testing Contents
 *
 ****************************************************************************/

- (BOOL) includesAllOf:aCltn
{
  if (self == aCltn)
    {
      return YES;
    }
  else
    {
      BOOL res = YES;
      id e, seq = [aCltn eachElement];
      while ((e = [seq next]))
	{
	  if (![self includes:e])
	    {
	      res = NO;
	      goto done;
	    }
	}
    done:
#ifndef OBJC_REFCNT
      [seq free];
#endif
      return res;
    }
}

- (BOOL) includesAnyOf:aCltn
{
  if (self == aCltn)
    {
      return YES;
    }
  else
    {
      BOOL res = NO;
      id e, seq = [aCltn eachElement];
      while ((e = [seq next]))
	{
	  if ([self includes:e])
	    {
	      res = YES;
	      goto done;
	    }
	}
    done:
#ifndef OBJC_REFCNT
      [seq free];
#endif
      return res;
    }
}

/*****************************************************************************
 *
 * Adding and Removing Contents
 *
 ****************************************************************************/

- addAll:aCltn
{
  if (self == aCltn)
    {
      [self addYourself];
    }
  else
    {
      id e, seq;

      seq = [aCltn eachElement];
      while ((e = [seq next]))
	{
	  [self add:e];
	}
#ifndef OBJC_REFCNT
      seq = [seq free];
#endif
    }

  return self;
}

- addContentsOf:aCltn
{
  return [self addAll:aCltn];
}

- addContentsTo:aCltn
{
  return [aCltn addAll:self];
}

- removeAll:aCltn
{
  if (self == aCltn)
    {
      [self emptyYourself];
    }
  else
    {
      id e, seq;

      seq = [aCltn eachElement];
      while ((e = [seq next]))
	{
	  [self remove:e];
	}
#ifndef OBJC_REFCNT
      seq = [seq free];
#endif
    }

  return self;
}

- removeContentsFrom:aCltn
{
  return [aCltn removeAll:self];
}

- removeContentsOf:aCltn
{
  return [self removeAll:aCltn];
}

/*****************************************************************************
 *
 * Combining
 *
 ****************************************************************************/

- intersection:bag
{
  if (self == bag)
    {
      return [self copy];
    }
  else
    {
      id anElement, elements;
      id intersection = [isa new];

      elements = [self eachElement];
      while ((anElement = [elements next]))
	{
	  if ([bag find:anElement])
	    [intersection add:anElement];
	}
#ifndef OBJC_REFCNT
      elements = [elements free];
#endif

      return intersection;
    }
}

- union:bag
{
  if (self == bag)
    {
      return [self copy];
    }
  else
    {
      return [[self copy] addAll:bag];
    }
}

- difference:bag
{
  if (self == bag)
    {
      return [isa new];
    }
  else
    {
      return [[self copy] removeAll:bag];
    }
}

/*****************************************************************************
 *
 * Converting to different type of collection.
 *
 ****************************************************************************/

- asSet
{
  /* Stepstone isKindOf takes a id but class returns SHR */
  if ([self isKindOf:(id) [Set class]])
    {
      return self;
    }
  else
    {
      return [[Set new] addAll:self];
    }
}

- asOrdCltn
{
  /* Stepstone isKindOf takes a id but class returns SHR */
  if ([self isKindOf:(id) [OrdCltn class]])
    {
      return self;
    }
  else
    {
      return [[OrdCltn new] addAll:self];
    }
}

/*****************************************************************************
 *
 * Block methods
 *
 ****************************************************************************/

#if OBJC_BLOCKS
- detect:aBlock
{
  id e, seq;

  seq = [self eachElement];

  while ((e = [seq next]))
    {
      if (([aBlock value:e]))
	{
#ifndef OBJC_REFCNT
	  seq = [seq free];
#endif
	  return e;
	}
    }

#ifndef OBJC_REFCNT
  seq = [seq free];
#endif
  return nil;
}

- detect:aBlock ifNone:noneBlock
{
  id e, seq;

  seq = [self eachElement];

  while ((e = [seq next]))
    {
      if (([aBlock value:e]))
	{
#ifndef OBJC_REFCNT
	  seq = [seq free];
#endif
	  return e;
	}
    }

#ifndef OBJC_REFCNT
  seq = [seq free];
#endif
  return [noneBlock value];
}

- select:testBlock
{
  id e, seq;
  id newObject = [isa new];

  seq = [self eachElement];

  while ((e = [seq next]))
    {
      if (([testBlock value:e]))
	{
	  [newObject add:e];
	}
    }

#ifndef OBJC_REFCNT
  seq = [seq free];
#endif
  return newObject;
}

- reject:testBlock
{
  id e, seq;
  id newObject = [isa new];

  seq = [self eachElement];

  while ((e = [seq next]))
    {
      if (!([testBlock value:e]))
	{
	  [newObject add:e];
	}
    }

#ifndef OBJC_REFCNT
  seq = [seq free];
#endif
  return newObject;
}

- collect:transformBlock
{
  id e, seq;
  id newObject = [isa new];

  seq = [self eachElement];

  while ((e = [seq next]))
    {
      id anImage = [transformBlock value:e];
      if (anImage)
	{
	  [newObject add:anImage];
	}
    }

#ifndef OBJC_REFCNT
  seq = [seq free];
#endif
  return newObject;
}

- (unsigned) count:aBlock
{
  id e, seq;
  unsigned c = 0;

  seq = [self eachElement];
  while ((e = [seq next]))
    {
      if ([aBlock value:e])
	{
	  c++;
	}
    }
#ifndef OBJC_REFCNT
  seq = [seq free];
#endif

  return c;
}

#endif /* OBJC_BLOCKS */

/*****************************************************************************
 *
 * Making elements perform actions.
 *
 ****************************************************************************/

- elementsPerform:(SEL)aSelector
{
  id e, seq;

  seq = [self eachElement];
  while ((e = [seq next]))
    {
      [e perform:aSelector];
    }
#ifndef OBJC_REFCNT
  seq = [seq free];
#endif

  return self;
}

- elementsPerform:(SEL)aSelector with:anObject
{
  id e, seq;

  seq = [self eachElement];
  while ((e = [seq next]))
    {
      [e perform:aSelector with:anObject];
    }
#ifndef OBJC_REFCNT
  seq = [seq free];
#endif

  return self;
}

- elementsPerform:(SEL)aSelector with:anObject with:otherObject
{
  id e, seq;

  seq = [self eachElement];
  while ((e = [seq next]))
    {
      [e perform:aSelector with:anObject with:otherObject];
    }
#ifndef OBJC_REFCNT
  seq = [seq free];
#endif

  return self;
}

- elementsPerform:(SEL)aSelector with:anObject with:otherObject with:thirdObj
{
  id e, seq;

  seq = [self eachElement];
  while ((e = [seq next]))
    {
      [e perform:aSelector with:anObject with:otherObject with:thirdObj];
    }
#ifndef OBJC_REFCNT
  seq = [seq free];
#endif

  return self;
}
/*****************************************************************************
 *
 * Do Blocks
 *
 ****************************************************************************/

#if OBJC_BLOCKS
- do:aBlock
{
  id e, seq;

  seq = [self eachElement];

  while ((e = [seq next]))
    {
      [aBlock value:e];
    }

#ifndef OBJC_REFCNT
  seq = [seq free];
#endif
  return self;
}
- do:aBlock until:(BOOL*)flag
{
  id e, seq;

  seq = [self eachElement];

  while ((e = [seq next]))
    {
      [aBlock value:e];
      if (*flag)
	break;
    }

#ifndef OBJC_REFCNT
  seq = [seq free];
#endif
  return self;
}
#endif /* OBJC_BLOCKS */

/*****************************************************************************
 *
 * Locating
 *
 ****************************************************************************/

static id 
find (objbbt_t self, id key, SEL cmpSel, id cmpBlk)
{
  int c;
  objbbt_t offset = NULL;

  if ((c = cmp (self, key, cmpSel, cmpBlk, &offset)))
    {
      return nil;
    }
  else
    {
      assert ([key isEqual:offset->key]);
      return offset->key;
    }
}

- find:anObject
{
  if (anObject)
    {
      return (value.llink) ? find (value.llink, anObject, cmpSel, cmpBlk) : nil;
    }
  else
    {
      return nil;
    }
}

- (BOOL) contains:anObject
{
  return (BOOL) ([self find:anObject] ? YES : NO);
}

/*****************************************************************************
 *
 * Printing
 *
 ****************************************************************************/

- printOn:(IOD)aFile
{
  id s = [self eachElement];
  [s printOn:aFile];
#ifndef OBJC_REFCNT
  [s free];
#endif
  return self;
}

/*****************************************************************************
 *
 * Archiving
 *
 ****************************************************************************/

- fileOutOn:aFiler
{
  return [self notImplemented:_cmd];
}

- fileInFrom:aFiler
{
  return [self notImplemented:_cmd];
}

@end
 
