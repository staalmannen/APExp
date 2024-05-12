
/*
 * Portable Object Compiler (c) 1997,98,99,2003.  All Rights Reserved.
 * $Id: ordcltn.m,v 1.7 2020/04/16 19:16:08 stes Exp $
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
#include <string.h>
#include <stdlib.h>
#include "ordcltn.h"
#include "cltnseq.h"
#include "set.h"
#include "sequence.h"
#include "ascfiler.h"
#include "ocstring.h"
#if OBJC_BLOCKS
#include "Block.h"
#endif
#include "notfound.h"
#include "outofbnd.h"

#define DEFAULT_CAPACITY (16)

typedef struct
  {
    @defs (OrdCltn)
  }
TFOrdCltn;

@implementation OrdCltn

/*****************************************************************************
 *
 * Creation
 *
 ****************************************************************************/

static void 
ptrinit (id * p, id q, int c)
{
  while (c--)
    *p++ = q;
}

static void 
init (objcol_t self, int n, int c)
{
  assert (0 <= n && n <= c);
  self->count = n;
  self->capacity = c;
  self->ptr = (id *) OC_Calloc (c * sizeof (id));
}

+ new
{
  int n = DEFAULT_CAPACITY;
  id newObject = [super new];
#if OTBCRT
  /* this is always ok, not just for -otb */
  init ([newObject objcolvalue], 0, n);
#else
  /* faster, but not correct in the -otb case */
  init (&(((TFOrdCltn *) newObject)->value), 0, n);
#endif
  return newObject;
}

+ new:(unsigned)n
{
  id newObject = [super new];
  init ([newObject objcolvalue], 0, n);
  return newObject;
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

static void 
ptrcopy (id * p, id * q, int c)
{
  while (c--)
    {
      *p++ = *q++;
    }
}

static void 
copy (objcol_t dst, objcol_t src)
{
  init (dst, src->count, src->count);
  ptrcopy (dst->ptr, src->ptr, src->count);
}

- copy
{
  id aCopy = [super copy];
  copy ([aCopy objcolvalue], (&value));
  return aCopy;
}

static void 
ptrdeepcopy (id * p, id * q, int c)
{
  while (c--)
    {
      id obj = *q++;
      *p++ = (obj) ? [obj deepCopy] : nil;
    }
}

static void 
deepcopy (objcol_t dst, objcol_t src)
{
  init (dst, src->count, src->count);
  ptrdeepcopy (dst->ptr, src->ptr, src->count);
}

- deepCopy
{
  /* not all Object implementations have |deepCopy| */
  /* so we send |copy| to super instead             */

  id aCopy = [super copy];
  deepcopy ([aCopy objcolvalue], (&value));
  return aCopy;
}

static void 
empty (objcol_t self)
{
  ptrinit (self->ptr, nil, self->count);	/* not same as memset ! */
  self->count = 0;
}

- emptyYourself
{
  empty ((&value));
  return self;
}

static void 
ptrclear (id * p, int c)
{
  while (c--)
    {
      id obj = *p;
      *p++ = (obj) ? [obj free] : nil;
    }
}

static void 
freecontents (objcol_t self)
{
  ptrclear (self->ptr, self->count);
  self->count = 0;
}

- freeContents
{
  freecontents ((&value));
  return self;
}

static void 
ptrclearall (id * p, int c)
{
  while (c--)
    {
      id obj = *p;
      *p++ = (obj) ? [obj freeAll] : nil;
    }
}

static void 
freeall (objcol_t self)
{
  ptrclearall (self->ptr, self->count);
  self->count = 0;
}

- freeAll
{
  freeall ((&value));
  return self;
}

static void 
clear (objcol_t self)
{
  self->count = 0;
  self->capacity = 0;
  OC_Free (self->ptr);
  self->ptr = NULL;
}

- free
{
  clear ((&value));
  return [super free];
}

- release
{
#ifdef OBJC_REFCNT
  empty ((&value));
  clear ((&value));
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

- (objcol_t) objcolvalue
{
  return &value;
}

- (unsigned) size
{
  return (unsigned) ((&value)->count);
}

- (BOOL) isEmpty
{
  return (&value)->count == 0;
}

- (unsigned) lastOffset
{
  return (&value)->count - 1;
}

- eachElement
{
  id aCarrier = [CollectionSequence over:self];
  return [Sequence over:aCarrier];
}

static id 
ptrfirst (id * p, int n)
{
  return (n) ? p [0] : nil;
}

static id 
first (objcol_t self)
{
  return ptrfirst (self->ptr, self->count);
}

- firstElement
{
  return first ((&value));
}

static id 
ptrlast (id * p, int n)
{
  return (n) ? p [n - 1] : nil;
}

static id 
last (objcol_t self)
{
  return ptrlast (self->ptr, self->count);
}

- lastElement
{
  return last ((&value));
}

/*****************************************************************************
 *
 * Comparing
 *
 ****************************************************************************/

static unsigned 
ptrhash (id * p, int n)
{
  unsigned code = n;
  while (n--)
    {
      code ^= [*p++ hash];
    }
  return code;
}

static unsigned 
hashcontents (objcol_t a)
{
  return ptrhash (a->ptr, a->count);
}

- (unsigned) hash
{
  return hashcontents (&value);
}

static BOOL 
ptreq (id * p, id * q, int n)
{
  while (n--)
    {
      if (![*p++ isEqual:*q++])
	{
	  return NO;
	}
    }
  return YES;
}

static BOOL 
eq (objcol_t a, objcol_t b)
{
  if (a->count == b->count)
    {
      return ptreq (a->ptr, b->ptr, a->count);
    }
  else
    {
      return NO;
    }
}

- (BOOL) isEqual:aCltn
{
  return (self == aCltn) ? YES : eq ((&value), [aCltn objcolvalue]);
}

/*****************************************************************************
 *
 * Adding
 *
 ****************************************************************************/

static BOOL 
needsexpand (objcol_t self)
{
  assert (self->count <= self->capacity);
  return self->count == self->capacity;
}

static void 
expand (objcol_t self)
{
  self->capacity = 1 + 2 * self->capacity;
  self->ptr = (id *) OC_Realloc (self->ptr, sizeof (id) * self->capacity);
  memset (self->ptr + self->count, 0, sizeof (id) * (self->capacity - self->count));
}

static int 
ptraddlast (id * p, id obj, int n)
{
  p [n] = obj;
  return n + 1;
}

static void 
addlast (objcol_t self, id obj)
{
  if (needsexpand (self))
    {
      expand (self);
    }
  self->count = ptraddlast (self->ptr, obj, self->count);
}

- add:anObject
{
  if (anObject)
    {
      addlast ((&value), anObject);
      return self;
    }
  else
    {
      return self;
    }
}

- addYourself
{
  int i, n = [self size];
  for (i = 0; i < n; i++)
    [self add:[self at:i]];
  return self;
}

static int 
ptraddfirst (id * p, id obj, int n)
{
  int m = n;
  p += n;
  while (m--)
    {
      id *q = p - 1;
      *p = *q;
      p = q;
    }
  *p = obj;
  return n + 1;
}

static void 
addfirst (objcol_t self, id obj)
{
  if (needsexpand (self))
    {
      expand (self);
    }
  self->count = ptraddfirst (self->ptr, obj, self->count);
}

- addFirst:newObject
{
  if (newObject)
    {
      addfirst ((&value), newObject);
      return self;
    }
  else
    {
      return self;
    }
}

- addLast:newObject
{
  return [self add:newObject];
}

- addIfAbsent:anObject
{
  if ([self find:anObject] == nil)
    {
      [self add:anObject];
    }
  return self;
}

- addIfAbsentMatching:anObject
{
  if ([self findMatching:anObject] == nil)
    {
      [self add:anObject];
    }
  return self;
}

/*****************************************************************************
 *
 * Insertion
 *
 ****************************************************************************/

static int 
ptrinsert (id * p, id obj, int i, int n)
{
  if (i == n)
    {
      return ptraddlast (p, obj, n);
    }
  else
    {
      return i + ptraddfirst (p + i, obj, n - i);
    }
}

static void 
insert (objcol_t self, id obj, int i)
{
  if (needsexpand (self))
    {
      expand (self);
    }

  self->count = ptrinsert (self->ptr, obj, i, self->count);
}

- at:(unsigned )anOffset insert:anObject
{
  if (anObject)
    {
      if (anOffset > [self size])
	{
	  [[[OutOfBounds new:[self size]] at:anOffset] signal];
	}
      else
	{
	  insert ((&value), anObject, (int) anOffset);
	}
      return self;
    }
  else
    {
      return self;
    }
}

- couldntfind
{
  return [NotFound signal];
}

- insert:newObject after:oldObject
{
  if (newObject)
    {
      unsigned offset = [self offsetOf:oldObject];
      if (offset == (unsigned) -1)
	{
	  return [self couldntfind];
	}
      else
	{
	  return [self at:offset + 1 insert:newObject];
	}
    }
  else
    {
      return self;
    }
}

- insert:newObject before:oldObject
{
  if (newObject)
    {
      unsigned offset = [self offsetOf:oldObject];
      if (offset == (unsigned) -1)
	{
	  return [self couldntfind];
	}
      else
	{
	  return [self at:offset - 1 insert:newObject];
	}
    }
  else
    {
      return self;
    }
}

/*****************************************************************************
 *
 * Relative Accessing
 *
 ****************************************************************************/

- after:anObject
{
  unsigned offset = [self offsetOf:anObject];
  if (offset == (unsigned) -1)
    {
      return [self couldntfind];
    }
  else
    {
      return (offset == [self lastOffset]) ? nil : [self at:offset + 1];
    }
}

- before:anObject
{
  unsigned offset = [self offsetOf:anObject];
  if (offset == (unsigned) -1)
    {
      return [self couldntfind];
    }
  else
    {
      return (offset == 0) ? nil : [self at:offset - 1];
    }
}

static id 
at (objcol_t self, int i)
{
  assert (0 <= i && i < self->count);
  return (self->ptr) [i];
}

- at:(unsigned )anOffset
{
  if (anOffset >= [self size])
    {
      [[[OutOfBounds new:[self size]] at:anOffset] signal];
      return nil;
    }
  else
    {
      return at ((&value), anOffset);
    }
}

static id 
atput (objcol_t self, int i, id obj)
{
  id tmp;
  assert (0 <= i && i < self->count);
  tmp = (self->ptr) [i];
  (self->ptr) [i] = obj;
  return tmp;
}

- at:(unsigned )anOffset put:anObject
{
  if (anOffset >= [self size])
    {
      [[[OutOfBounds new:[self size]] at:anOffset] signal];
      return nil;
    }
  else
    {
      return atput ((&value), anOffset, anObject);
    }
}

/*****************************************************************************
 *
 * Removing
 *
 ****************************************************************************/

static id 
ptrremovefirst (id * p, int n)
{
  id obj = *p;
  n--;
  while (n--)
    {
      id *q = p + 1;
      *p = *q;
      p = q;
    }
  *p = nil;
  return obj;
}

static id 
removefirst (objcol_t self)
{
  if (self->count)
    {
      id obj = ptrremovefirst (self->ptr, self->count);
      self->count--;
      return obj;
    }
  else
    {
      return nil;
    }
}

- removeFirst
{
  return removefirst ((&value));
}

static id 
ptrremove (id * p)
{
  id obj = *p;
  *p = nil;
  return obj;
}

static id 
removelast (objcol_t self)
{
  if (self->count)
    {
      id obj = ptrremove (self->ptr + self->count - 1);
      self->count--;
      return obj;
    }
  else
    {
      return nil;
    }
}

- removeLast
{
  return removelast ((&value));
}

static id 
ptrremoveat (id * p, int i, int n)
{
  if (i == n - 1)
    {
      return ptrremove (p + n - 1);
    }
  else
    {
      return ptrremovefirst (p + i, n - i);
    }
}

static id 
removeat (objcol_t self, int i)
{
  if (self->count)
    {
      id obj = ptrremoveat (self->ptr, i, self->count);
      self->count--;
      return obj;
    }
  else
    {
      return nil;
    }
}

- removeAt:(unsigned )anOffset
{
  if (anOffset >= [self size])
    {
      [[[OutOfBounds new:[self size]] at:anOffset] signal];
      return nil;
    }
  else
    {
      return removeat ((&value), anOffset);
    }
}

- removeAtIndex:(unsigned )anOffset
{
  return [self removeAt:anOffset];
}

- remove:oldObject
{
  unsigned offset = [self offsetOf:oldObject];
  if (offset == (unsigned) -1)
    {
      return nil;
    }
  else
    {
      return [self removeAt:offset];
    }
}

#if OBJC_BLOCKS
- remove:oldObject ifAbsent:exceptionBlock
{
  id anObject = [self remove:oldObject];
  return (anObject) ? anObject : [exceptionBlock value];
}
#endif /* OBJC_BLOCKS */

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
  int i, n;
  for (i = 0, n = [self size]; i < n; i++)
    {
      [[self at:i] perform:aSelector];
    }
  return self;
}

- elementsPerform:(SEL)aSelector with:anObject
{
  int i, n;
  for (i = 0, n = [self size]; i < n; i++)
    {
      [[self at:i] perform:aSelector with:anObject];
    }
  return self;
}

- elementsPerform:(SEL)aSelector with:anObject with:otherObject
{
  int i, n;
  for (i = 0, n = [self size]; i < n; i++)
    {
      [[self at:i] perform:aSelector with:anObject with:otherObject];
    }
  return self;
}

- elementsPerform:(SEL)aSelector with:anObject with:otherObject with:thirdObj
{
  int i, n;
  for (i = 0, n = [self size]; i < n; i++)
    {
      [[self at:i] perform:aSelector with:anObject with:otherObject with:thirdObj];
    }
  return self;
}
/*****************************************************************************
 *
 * Do Blocks  (also provide a -reverseDo: here)
 *
 ****************************************************************************/

#if OBJC_BLOCKS
- do:aBlock
{
  int i = 0;
  int n = [self size];
  for (i = 0; i < n; i++)
    {
      [aBlock value:[self at:i]];
    }
  return self;
}

- do:aBlock until:(BOOL*)flag
{
  int i = 0;
  int n = [self size];
  for (i = 0; i < n; i++)
    {
      [aBlock value:[self at:i]];
      if (*flag)
	break;
    }
  return self;
}

- reverseDo:aBlock
{
  unsigned n = [self size];
  while (n--)
    {
      [aBlock value:[self at:n]];
    }
  return self;
}
#endif /* OBJC_BLOCKS */

/*****************************************************************************
 *
 * Locating
 *
 ****************************************************************************/

static id 
ptrfind (id * p, id obj, int n)
{
  int i;
  for (i = 0; i < n; i++)
    {
      if (p [i] == obj)
	{
	  return p [i];
	}
    }
  return nil;
}

static id 
find (objcol_t self, id obj)
{
  return ptrfind (self->ptr, obj, self->count);
}

- find:anObject
{
  return find ((&value), anObject);
}

static id 
ptrfindmatch (id * p, id obj, int n)
{
  int i;
  for (i = 0; i < n; i++)
    {
      if (p [i] == obj || [p [i] isEqual:obj])
	{
	  return p [i];
	}
    }
  return nil;
}

static id 
findmatch (objcol_t self, id obj)
{
  return ptrfindmatch (self->ptr, obj, self->count);
}

- findMatching:anObject
{
  return findmatch ((&value), anObject);
}

- (BOOL) includes:anObject
{
  return [self findMatching:anObject] != nil;
}

static id 
ptrfindstr (id * p, STR s, int n)
{
  int i;
  for (i = 0; i < n; i++)
    {
      if ([p [i] isEqualSTR:s])
	{
	  return p [i];
	}
    }
  return nil;
}

static id 
findstr (objcol_t self, STR s)
{
  return ptrfindstr (self->ptr, s, self->count);
}

- findSTR:(STR )aString
{
  return findstr ((&value), aString);
}

- (BOOL) contains:anObject
{
  return [self find:anObject] != nil;
}

static int 
ptroffset (id * p, id obj, int n)
{
  int i;
  for (i = 0; i < n; i++)
    {
      if (*p++ == obj)
	{
	  return i;
	}
    }
  return -1;
}

static int 
offset (objcol_t self, id obj)
{
  return ptroffset (self->ptr, obj, self->count);
}

- (unsigned) offsetOf:anObject
{
  return (unsigned) offset ((&value), anObject);
}

/*****************************************************************************
 *
 * Printing
 *
 ****************************************************************************/

- printOn:(IOD)aFile
{
  int i, n = [self size];
  for (i = 0; i < n; i++)
    {
      id s = [self at:i];
      [s printOn:aFile];
      fprintf (aFile, "\n");
    }
  return self;
}

/*****************************************************************************
 *
 * Archiving
 *
 ****************************************************************************/

#ifdef __PORTABLE_OBJC__
static void 
ptrfileout (id aFiler, id * a, int n)
{
  while (n--)
    {
      [aFiler fileOut:a++ type:'@'];
    }
}

static void 
ptrfilein (id aFiler, id * a, int n)
{
  while (n--)
    {
      [aFiler fileIn:a++ type:'@'];
    }
}

static void 
fileout (id aFiler, objcol_t self)
{
  [aFiler fileOut:&self->count type:'i'];
  [aFiler fileOut:&self->capacity type:'i'];
  ptrfileout (aFiler, self->ptr, self->count);
}

static void 
filein (id aFiler, objcol_t self)
{
  int n, c;
  [aFiler fileIn:&n type:'i'];
  [aFiler fileIn:&c type:'i'];
  init (self, n, c);
  ptrfilein (aFiler, self->ptr, n);
}

- fileOutOn:aFiler
{
  [super fileOutOn:aFiler];
  fileout (aFiler, &value);
  return self;
}

- fileInFrom:aFiler
{
  [super fileInFrom:aFiler];
  filein (aFiler, &value);
  return self;
}

#endif /* __PORTABLE_OBJC__ */

@end
 
