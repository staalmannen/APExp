
/*
 * Portable Object Compiler (c) 1997,98.  All Rights Reserved.
 * $Id: bag.m,v 1.4 2020/04/16 19:16:07 stes Exp $
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
#include "bag.h"
#include "bagseq.h"
#include "ordcltn.h"
#include "set.h"
#include "sequence.h"
#include "ocstring.h"
#include "ascfiler.h"
#if OBJC_BLOCKS
#include "Block.h"
#endif

@implementation Bag

/*****************************************************************************
 *
 * Creation
 *
 ****************************************************************************/

static void 
ptrzero (id * p, int *m, int c)
{
  while (c--)
    {
      *p++ = nil;
      *m++ = 0;
    }
}

static void 
init (objbag_t self, int n, int c)
{
  assert (0 <= n && n <= c);
  self->count = n;		/* count != size, count = num diff. Objects */
  self->capacity = c;
  self->ptr = (id *) OC_Calloc (c * sizeof (id));
  self->cnts = (int *) OC_MallocAtomic (c * sizeof (int));
  memset (self->cnts, 0, sizeof (int) * c);
}

static void 
initzero (objbag_t self, int c)
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
  initzero ([newObj objbagvalue], n);
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
ptrcopy (id * p, int *mp, id * q, int *mq, int c)
{
  while (c--)
    {
      *p++ = *q++;
      *mp++ = *mq++;
    }
}

static void 
copy (objbag_t dst, objbag_t src)
{
  init (dst, src->count, src->capacity);
  ptrcopy (dst->ptr, dst->cnts, src->ptr, src->cnts, src->capacity);
}

- copy
{
  id aCopy = [super copy];
  copy ([aCopy objbagvalue], (&value));
  return aCopy;
}

static void 
ptrdeepcopy (id * p, int *mp, id * q, int *mq, int c)
{
  while (c--)
    {
      id obj = *q++;
      *p++ = (obj) ? [obj deepCopy] : nil;
      *mp++ = *mq++;
    }
}

static void 
deepcopy (objbag_t dst, objbag_t src)
{
  init (dst, src->count, src->capacity);
  ptrdeepcopy (dst->ptr, dst->cnts, src->ptr, src->cnts, src->capacity);
}

- deepCopy
{
  /* not all Object implementations have |deepCopy| */
  /* so we send |copy| to super instead             */

  id aCopy = [super copy];
  deepcopy ([aCopy objbagvalue], (&value));
  return aCopy;
}

static void 
empty (objbag_t self)
{
  self->count = 0;
  ptrzero (self->ptr, self->cnts, self->capacity);
}

- emptyYourself
{
  empty ((&value));
  return self;
}

static void 
ptraddself (int *m, int c)
{
  while (c--)
    {
      (*m) *= 2;
      m++;
    }
}

static void 
addself (objbag_t self)
{
  ptraddself (self->cnts, self->capacity);
}

- addYourself
{
  /* very efficient for Bags, since it just operates on multiplicities */
  addself ((&value));
  return self;
}

static void 
ptrclear (id * p, int *m, int c)
{
  while (c--)
    {
      id obj = *p;
      *p++ = (obj) ? [obj free] : nil;
      *m++ = 0;
    }
}

static void 
freecontents (objbag_t self)
{
  self->count = 0;
  ptrclear (self->ptr, self->cnts, self->capacity);
}

- freeContents
{
  freecontents ((&value));
  return self;
}

static void 
clear (objbag_t self)
{
  self->count = 0;
  self->capacity = 0;
  OC_Free (self->ptr);
  self->ptr = NULL;
  OC_Free (self->cnts);
  self->cnts = NULL;
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

- (objbag_t) objbagvalue
{
  return (&value);
}

static int 
ptrsize (id * p, int *m, int c)
{
  int n = 0;
  while (c--)
    {
      n += (*m++);
    }
  return n;
}

static int 
size (objbag_t self)
{
  return ptrsize (self->ptr, self->cnts, self->capacity);
}

- (unsigned) size
{
  return (unsigned) size ((&value));
}

- (BOOL) isEmpty
{
  return value.count == 0;
}

- eachElement
{
  id aCarrier = [BagSequence over:self];
  return [Sequence over:aCarrier];
}

/*****************************************************************************
 *
 * Comparing
 *
 ****************************************************************************/

- (unsigned) hash
{
  return [super hash];		/* would it pay to improve this? */
}

- (BOOL) isEqual:bag
{
  id anElement, aSequence;
  if (self == bag)
    return YES;
  if (![bag isKindOf:(id) [Bag class]])
    return NO;
  if ([bag size] != [self size])
    return NO;
  aSequence = [self eachElement];
  while ((anElement = [aSequence next]))
    {
      if ([bag contains:anElement])
	{
#ifndef OBJC_REFCNT
	  [aSequence free];
#endif
	  return NO;
	}
    }
#ifndef OBJC_REFCNT
  [aSequence free];
#endif
  return YES;
}

/*****************************************************************************
 *
 * Adding
 *
 ****************************************************************************/

static unsigned 
ptrfind (id * p, id obj, int n)
{
  id *begin, *now, *end;

  begin = p;
  now = p + (([obj hash]) % n);
  end = p + n;

  for (; n--; now++)
    {
      if (now >= end)
	now = begin;
      if (*now == nil || [*now isEqual:obj])
	return (unsigned) (now - begin);
    }

  fprintf (stderr, "find: table full shouldn't happen");
  return 0;
}

static id *
find (objbag_t self, id obj, int **m)
{
  unsigned of = ptrfind (self->ptr, obj, self->capacity);
  *m = self->cnts + of;
  return self->ptr + of;
}

- add:anObject
{
  [self addNTest:anObject];
  return self;
}

static BOOL 
needsexpand (objbag_t self)
{
  return 2 * self->count > self->capacity;
}

/* don't use "new" as variable name (for C++) */
static void 
ptrrehash (id * newp, int *nm, int newc, id * old, int *om, int oldc)
{
  while (oldc--)
    {
      id obj = *old++;
      int cnt = *om++;
      id *newend = newp + newc;
      if (obj)
	{
	  id *pos = newp + ([obj hash] % ((unsigned) newc));
	  while (*pos)
	    {
	      pos++;
	      if (pos == newend)
		pos = newp;
	    }
	  *pos = obj;
	  nm [pos - newp] = cnt;
	}
    }
}

static void 
rehash (objbag_t self)
{
  int c;
  int *nm, *om;
  id *newp, *old;

  c = self->capacity;
  old = self->ptr;
  newp = (id *) OC_Calloc (c * sizeof (id));
  om = self->cnts;
  nm = (int *) OC_MallocAtomic (c * sizeof (int));
  memset (nm, 0, sizeof (int) * c);

  ptrrehash (newp, nm, c, old, om, c);

  OC_Free (old);
  OC_Free (om);
  self->ptr = newp;
  self->cnts = nm;
}

static void 
expand (objbag_t self)
{
  int *nm, *om;
  id *newp, *old;
  int newc, oldc;

  oldc = self->capacity;
  old = self->ptr;
  om = self->cnts;
  newc = 1 + 2 * oldc;
  newp = (id *) OC_Calloc (newc * sizeof (id));
  nm = (int *) OC_MallocAtomic (newc * sizeof (int));
  memset (nm, 0, sizeof (int) * newc);

  ptrrehash (newp, nm, newc, old, om, oldc);

  OC_Free (old);
  OC_Free (om);
  self->ptr = newp;
  self->cnts = nm;
  self->capacity = newc;
}

static id 
add (objbag_t self, id obj)
{
  id *p;
  int *m;

  if (needsexpand (self))
    expand (self);

  if (*(p = find (self, obj, &m)))
    {
      (*m)++;
      return nil;		/* filter: returns object instead */
    }
  else
    {
      self->count++;
      *m = 1;
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
filter (objbag_t self, id obj)
{
  id *p;
  int *m;

  if (needsexpand (self))
    expand (self);

  if (*(p = find (self, obj, &m)))
    {
      (*m)++;
      return *p;		/* -filter: returns object */
    }
  else
    {
      self->count++;
      *m = 1;
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
replace (objbag_t self, id obj)
{
  id *p;
  int *m;

  if (needsexpand (self))
    expand (self);

  if (*(p = find (self, obj, &m)))
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
delete (objbag_t self, id obj)
{
  id *p;
  int *m;

  if (*(p = find (self, obj, &m)))
    {
      id tmp = *p;
      if (((*m)--) == 0)
	{
	  *p = nil;
	  self->count--;
	}
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
  int *m;
  return (anObject) ? *find ((&value), anObject, &m) : nil;
}

- (BOOL) contains:anObject
{
  return (BOOL) ([self find:anObject] ? YES : NO);
}

- (BOOL) includes:anObject
{
  return (BOOL) ([self find:anObject] ? YES : NO);
}

- (unsigned) occurrencesOf:anObject
{
  int *m;
  find ((&value), anObject, &m);
  return *m;
}

/*****************************************************************************
 *
 * Printing
 *
 ****************************************************************************/

- printOn:(IOD)aFile
{
#ifndef OBJC_REFCNT
  [[[self eachElement] printOn:aFile] free];
  return self;
#else
  [[self eachElement] printOn:aFile];
  return self;
#endif
}

/*****************************************************************************
 *
 * Archiving
 *
 ****************************************************************************/

#ifdef __PORTABLE_OBJC__
static void 
ptrfileout (id aFiler, id * a, int *m, int n)
{
  while (n--)
    {
      id obj = *a++;
      int cnt = *m++;
      if (cnt)
	{
	  [aFiler fileOut:&obj type:'@'];
	  [aFiler fileOut:&cnt type:'i'];
	}
    }
}

static void 
ptrfilein (id aFiler, id * a, int *m, int n)
{
  /* The idea here is that the Bag is not usable until a "rehash"
     * is performed, in the awakeFrom: method.
     * The hash-value of the objects themselves cannot, by the way, be
     * computed before the |awakeFrom:| message is being sent.
   */

  while (n--)
    {
      [aFiler fileIn:a++ type:'@'];
      [aFiler fileIn:m++ type:'i'];
    }
}

static void 
fileout (id aFiler, objbag_t self)
{
  int n = self->count;
  [aFiler fileOut:&n type:'i'];
  ptrfileout (aFiler, self->ptr, self->cnts, self->capacity);
}

static void 
filein (id aFiler, objbag_t self)
{
  int n;
  [aFiler fileIn:&n type:'i'];
  init (self, n, n);
  ptrfilein (aFiler, self->ptr, self->cnts, n);
}

- fileOutOn:aFiler
{
  [super fileOutOn:aFiler];
  fileout (aFiler, (&value));
  return self;
}

- fileInFrom:aFiler
{
  [super fileInFrom:aFiler];
  filein (aFiler, (&value));
  return self;
}

- awakeFrom:aFiler
{
  /* double size of capacity and rehash */
  expand ((&value));
  return self;
}
#endif /* __PORTABLE_OBJC__ */

@end
 
