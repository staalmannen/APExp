
/*
 * Portable Object Compiler (c) 1997,98,2003.  All Rights Reserved.
 * $Id: set.m,v 1.5 2020/04/16 19:16:08 stes Exp $
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
#include "set.h"
#include "setseq.h"
#include "ascfiler.h"
#include "ordcltn.h"
#include "ocstring.h"
#include "sequence.h"
#if OBJC_BLOCKS
#include "Block.h"
#endif

@implementation Set

/*****************************************************************************
 *
 * Creation
 *
 ****************************************************************************/

static void 
ptrzero (id * p, int c)
{
  while (c--)
    {
      *p++ = nil;		/* not same as memset in refcnt case */
    }
}

#ifndef NDEBUG
static int 
ptrcount (id * p, int c)
{
  int n = 0;
  while (c--)
    {
      if (*p++)
	{
	  n++;
	}
    }
  return n;
}
#endif

static void 
init (objset_t self, int n, int c)
{
  assert (0 <= n && n <= c);
  self->count = n;
  self->capacity = c;
  self->ptr = (id *) OC_Calloc (c * sizeof (id));
}

static void 
initzero (objset_t self, int c)
{
  init (self, 0, c);
}

+ new
{
  return [self new:16];
}

+ new:(unsigned)n
{
  id newObj = [super new];
  initzero ([newObj objsetvalue], n);
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

static void 
ptrcopy (id * p, id * q, int c)
{
  while (c--)
    {
      *p++ = *q++;
    }
}

static void 
copy (objset_t dst, objset_t src)
{
  init (dst, src->count, src->capacity);
  ptrcopy (dst->ptr, src->ptr, src->capacity);
}

- copy
{
  id aCopy = [super copy];
  copy ([aCopy objsetvalue], (&value));
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
deepcopy (objset_t dst, objset_t src)
{
  init (dst, src->count, src->capacity);
  ptrdeepcopy (dst->ptr, src->ptr, src->capacity);
}

- deepCopy
{
  /* not all Object implementations have |deepCopy| */
  /* so we send |copy| to super instead             */

  id aCopy = [super copy];
  deepcopy ([aCopy objsetvalue], (&value));
  return aCopy;
}

static void 
empty (objset_t self)
{
  self->count = 0;
  ptrzero (self->ptr, self->capacity);
}

- emptyYourself
{
  empty ((&value));
  return self;
}

- addYourself
{
  /* trivial for sets, since there are no duplicates */
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
freecontents (objset_t self)
{
  self->count = 0;
  ptrclear (self->ptr, self->capacity);
  assert (ptrcount (self->ptr, self->capacity) == 0);
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
freeall (objset_t self)
{
  self->count = 0;
  ptrclearall (self->ptr, self->capacity);
  assert (ptrcount (self->ptr, self->capacity) == 0);
}

- freeAll
{
  freeall ((&value));
  return self;
}

static void 
clear (objset_t self)
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

- (objset_t) objsetvalue
{
  return &value;
}

static int 
count (objset_t self)
{
  assert (ptrcount (self->ptr, self->capacity) == self->count);
  return self->count;
}

- (unsigned) size
{
  return (unsigned) count ((&value));
}

- (BOOL) isEmpty
{
  return count ((&value)) == 0;
}

- eachElement
{
  id aCarrier = [SetSequence over:self];
  return [Sequence over:aCarrier];
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
      id q = *p++;
      if (q)
	code ^= [q hash];
    }
  return code;
}

static unsigned 
hashcontents (objset_t a)
{
  return ptrhash (a->ptr, a->count);
}

- (unsigned) hash
{
  return hashcontents (&value);
}

- (BOOL) isEqual:set
{
  id e, seq;
  BOOL res = YES;
  if (self == set)
    {
      return YES;
    }
  if (![set isKindOf:(id) [Set class]])
    {
      return NO;
    }
  if ([set size] != [self size])
    {
      return NO;
    }
  seq = [self eachElement];
  while ((e = [seq next]))
    {
      if ([set contains:e])
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

/*****************************************************************************
 *
 * Adding
 *
 ****************************************************************************/

static id *
ptrfind (id * p, id obj, int n)
{
  id *begin, *now, *end;

  begin = p;
  now = p + (([obj hash]) % n);
  end = p + n;

  for (; n--; now++)
    {
      if (now >= end)
	{
	  now = begin;
	}
      if (*now == nil || [*now isEqual:obj])
	{
	  return now;
	}
    }

  fprintf (stderr, "find: table full shouldn't happen");
  return NULL;
}

static id *
find (objset_t self, id obj)
{
  assert (obj != nil);
  return ptrfind (self->ptr, obj, self->capacity);
}

- add:anObject
{
  [self addNTest:anObject];
  return self;
}

static BOOL 
needsexpand (objset_t self)
{
  return 2 * self->count > self->capacity;
}

/* don't use "new" as variable name (for C++) */
static void 
ptrrehash (id * newp, int newc, id * old, int oldc)
{
  while (oldc--)
    {
      id obj = *old++;
      id *newend = newp + newc;
      if (obj)
	{
	  id *pos = newp + ([obj hash] % ((unsigned) newc));
	  while (*pos)
	    {
	      pos++;
	      if (pos == newend)
		{
		  pos = newp;
		}
	    }
	  *pos = obj;
	}
    }
}

static void 
rehash (objset_t self)
{
  int c;
  id *newp, *old;

  c = self->capacity;
  old = self->ptr;
  newp = (id *) OC_Calloc (c * sizeof (id));

  assert (ptrcount (old, c) == self->count);
  ptrrehash (newp, c, old, c);
  assert (ptrcount (newp, c) == self->count);

  OC_Free (old);
  self->ptr = newp;
}

static void 
expand (objset_t self)
{
  id *newp, *old;
  int newc, oldc;

  oldc = self->capacity;
  old = self->ptr;
  newc = 1 + 2 * oldc;
  newp = (id *) OC_Calloc (newc * sizeof (id));

  assert (ptrcount (old, oldc) == self->count);
  ptrrehash (newp, newc, old, oldc);
  assert (ptrcount (newp, newc) == self->count);

  OC_Free (old);
  self->ptr = newp;
  self->capacity = newc;
}

static id 
add (objset_t self, id obj)
{
  id *p;

  if (needsexpand (self))
    {
      expand (self);
    }

  if (*(p = find (self, obj)))
    {
      return nil;
    }
  else
    {
      self->count++;
      return *p = obj;
    }
}

- addNTest:anObject
{
  if (anObject)
    {
      return add ((&value), anObject);
    }
  else
    {
      return nil;
    }
}

static id 
filter (objset_t self, id obj)
{
  id *p;

  if (needsexpand (self))
    {
      expand (self);
    }

  if (*(p = find (self, obj)))
    {
      return *p;
    }
  else
    {
      self->count++;
      *p = obj;
      return nil;
    }
}

- filter:anObject
{
  if (anObject)
    {
      id t = filter ((&value), anObject);
      if (t)
	{
#ifndef OBJC_REFCNT
	  [anObject free];
#endif
	  return t;
	}
      else
	{
	  return anObject;
	}
    }
  else
    {
      return nil;
    }
}

#if OBJC_BLOCKS
- add:anObject ifDuplicate:aBlock
{
  if (anObject)
    {
      id t = filter ((&value), anObject);
      if (t)
	{
	  [aBlock value];
	  return t;
	}
      else
	{
	  return anObject;
	}
    }
  else
    {
      return nil;
    }
}
#endif /* OBJC_BLOCKS */

static id 
replace (objset_t self, id obj)
{
  id *p;

  if (needsexpand (self))
    {
      expand (self);
    }

  if (*(p = find (self, obj)))
    {
      id tmp = *p;
      *p = obj;
      return tmp;
    }
  else
    {
      self->count++;
      *p = obj;
      return nil;
    }
}

- replace:anObject
{
  if (anObject)
    {
      return replace ((&value), anObject);
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

static id 
delete (objset_t self, id obj)
{
  id *p;

  if (*(p = find (self, obj)))
    {
      id tmp = *p;
      *p = nil;
      self->count--;
      rehash (self);
      return tmp;
    }
  else
    {
      return nil;
    }
}

- remove:oldObject
{
  if (oldObject)
    {
      return delete ((&value), oldObject);
    }
  else
    {
      return nil;
    }
}

- remove:oldObject ifAbsent:exceptionBlock
{
  if (oldObject)
    {
      return delete ((&value), oldObject);
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

- find:anObject
{
  return (anObject) ? *find ((&value), anObject) : nil;
}

- (BOOL) contains:anObject
{
  return (BOOL) ([self find:anObject] ? YES : NO);
}

- (BOOL) includes:anObject
{
  return [self contains:anObject];
}

- (unsigned) occurrencesOf:anObject
{
  return (unsigned) ([self find:anObject] ? 1 : 0);
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

#ifdef __PORTABLE_OBJC__
static void 
ptrfileout (id aFiler, id * a, int n)
{
  while (n--)
    {
      id obj = *a++;
      if (obj)
	{
	  [aFiler fileOut:&obj type:'@'];
	}
    }
}

static void 
ptrfilein (id aFiler, id * a, int n)
{
  /* The idea here is that the set is not usable until a "rehash"
   * is performed, in the awakeFrom: method.
   * The hash-value of the objects themselves cannot, by the way, be
   * computed before the |awakeFrom:| message is being sent.
   */

  while (n--)
    {
      [aFiler fileIn:a++ type:'@'];
    }
}

static void 
fileout (id aFiler, objset_t self)
{
  int n = self->count;
  [aFiler fileOut:&n type:'i'];
  ptrfileout (aFiler, self->ptr, self->capacity);
}

static void 
filein (id aFiler, objset_t self)
{
  int n;
  [aFiler fileIn:&n type:'i'];
  init (self, n, n);
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

- awakeFrom:aFiler
{
  /* double size of capacity and rehash */
  expand (&value);
  return self;
}
#endif /* __PORTABLE_OBJC__ */

@end
 
