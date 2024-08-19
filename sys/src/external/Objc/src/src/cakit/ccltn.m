
/*
 * Computer Algebra Kit (c) 1994,00 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: ccltn.m,v 1.6 2000/10/12 14:40:25 stes Exp $
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

#include "cakit.h"

static int 
mmbs_check (mmbs_t a, int n)
{
  assert (a && 0 <= n);
  while (n--)
    assert (*a++);
  return 1;
}

static mmbs_t 
mmbs_alloc (int n)
{
  int m;
  mmbs_t p;
  assert (0 <= n);
  m = sizeof (id) * n;
#if OBJC_REFCNT
  p = (mmbs_t) OC_Calloc (m);
#else
  p = (mmbs_t) OC_Malloc (m);
#endif
  return p;
}

static void 
mmbs_copy (mmbs_t c, mmbs_t a, int n)
{
  assert (0 <= n);
  while (n--)
    *c++ = *a++;
}

static void 
mmbs_deepcopy (mmbs_t c, mmbs_t a, int n)
{
  assert (0 <= n);
  while (n--)
    *c++ = [*a++ deepCopy];
}

static void 
mmbs_free (mmbs_t a, int n)
{
  assert (0 <= n);
  a += n;
  while (n--)
    {
      *--a = nil;
    }
  OC_Free (a);			/* points to start of array now ! */
}

static BOOL 
mmbs_eq (mmbs_t a, mmbs_t b, int n)
{
  assert (a != b && 0 <= n);
  while (n--)
    {
      if (*a != *b && [*a notEqual:*b])
	return NO;
      else
	{
	  a++;
	  b++;
	}
    }
  return YES;
}

static unsigned 
mmbs_hash (mmbs_t a, int n)
{
  assert (a && 0 <= n);
  return (n) ? (([a [n - 1] hash] < 8) + (n & 255)) : 0;
}

static mmbs_t 
mmbs_realloc (mmbs_t a, int oldc, int n)
{
  int m;
  mmbs_t p;
  m = n * sizeof (id);
  p = (mmbs_t) OC_Realloc (a, m);
#if OBJC_REFCNT
  assert (oldc <= n);
  memset (p + oldc, 0, (n - oldc) * sizeof (id));
#endif
  return p;
}

static int 
mmbs_insertlast (mmbs_t a, id obj, int n)
{
  a [n++] = obj;
  return n;
}

static int 
mmbs_insertfirst (mmbs_t a, id obj, int n)
{
  int j = n;
  a += n;
  while (j--)
    {
      mmbs_t t = a - 1;
      *a = *t;
      a = t;
    }
  *a = obj;
  return n + 1;
}

static int 
mmbs_insertat (mmbs_t a, id obj, int i, int n)
{
  if (i == n)
    {
      return mmbs_insertlast (a, obj, n);
    }
  else
    {
      return i + mmbs_insertfirst (a + i, obj, n - i);
    }
}

static id 
mmbs_removelast (mmbs_t a, int n)
{
  id obj;
  assert (n);
  obj = a [n - 1];
  a [n - 1] = nil;
  return obj;
}

static id 
mmbs_removefirst (mmbs_t a, int n)
{
  id obj;
  assert (n);
  obj = *a;
  --n;
  while (n--)
    {
      mmbs_t t = a + 1;
      *a = *t;
      a = t;
    }
  *a = nil;
  return obj;
}

static id 
mmbs_removeat (mmbs_t a, int i, int n)
{
  return mmbs_removefirst (a + i, n - i);
}

static id 
mmbs_replace (mmbs_t a, int i, id obj, int n)
{
  if (obj && 0 <= i && i < n)
    {
      id old = a [i];
      a [i] = obj;
      return old;
    }
  else
    {
      return nil;
    }
}

static void 
mmbs_swap (mmbs_t a, int i, int j, int n)
{
  assert (a && 0 <= i && i < n && 0 <= j && j < n);
  if (i != j)
    {
      id t = a [i];
      a [i] = a [j];
      a [j] = t;
    }
}

static id 
mmbs_at (mmbs_t a, int i, int n)
{
  assert (0 <= i && i < n);
  return a [i];
}

static id 
mmbs_last (mmbs_t a, int n)
{
  return (n) ? a [n - 1] : nil;
}

static int 
mmbs_find (mmbs_t a, id obj, int n)
{
  a += n;
  while (n--)
    {
      a--;
      if (*a == obj || [*a isEqual:obj])
	return n;
    }
  return -1;
}

#define STRIDE_FACTOR 3

static void 
mmbs_sort (mmbs_t self, int count)
{
  id a, b;
  BOOL found;
  int c, d, stride;

  stride = 1;
  while (stride <= count)
    stride = stride * STRIDE_FACTOR + 1;

  while (stride > (STRIDE_FACTOR - 1))
    {
      stride = stride / STRIDE_FACTOR;
      for (c = stride; c < count; c++)
	{
	  found = NO;
	  d = c - stride;
	  assert (0 <= d + stride < count);
	  a = self [d + stride];
	  while ((d >= 0) && !found)
	    {
	      if ([b = self [d] isLess:a])
		{
		  self [d + stride] = b;
		  d -= stride;
		}
	      else
		{
		  found = YES;
		}
	    }
	  self [d + stride] = a;
	}
    }
}

static BOOL 
mmbs_sorted (mmbs_t self, int count)
{
  id next = nil;
  while (count--)
    {
      id current = self [count];
      if (next && [current isLess:next])
	return NO;
      next = current;
    }
  return YES;
}

static void 
mmbs_reverse (mmbs_t self, int count)
{
  int i;
  for (i = 0; i < count / 2; i++)
    {
      id t = self [i];
      self [i] = self [count - i - 1];
      self [count - i - 1] = t;
    }
}

static void 
mmbs_fileout (id aFiler, mmbs_t a, int n)
{
  while (n--)
    {
      assert ([*a check]);
      [aFiler fileOut:a type:'@'];
      a++;
    }
}

static void 
mmbs_filein (id aFiler, mmbs_t a, int n)
{
  while (n--)
    {
      [aFiler fileIn:a type:'@'];
      a++;
    }
}

static int 
cltn_check (cltn_t a)
{
  assert (a && 0 <= a->count && a->count <= a->capacity);
  assert (mmbs_check (a->members, a->count));
  return 1;
}

static void 
cltn_initcapacity (cltn_t c, int n)
{
  assert (n >= 0);
  c->count = 0;
  c->capacity = n;
  c->members = mmbs_alloc (n);
}

static void 
cltn_initcount (cltn_t c, int n)
{
  assert (n >= 0);
  c->count = n;
  c->capacity = n;
  c->members = mmbs_alloc (n);
}

static void 
cltn_copy (cltn_t c, cltn_t a)
{
  cltn_check (a);
  cltn_initcount (c, a->count);
  mmbs_copy (c->members, a->members, a->count);
}

static void 
cltn_deepcopy (cltn_t c, cltn_t a)
{
  cltn_check (a);
  cltn_initcount (c, a->count);
  mmbs_deepcopy (c->members, a->members, a->count);
}

static void 
cltn_release (cltn_t c)
{
  cltn_check (c);
  mmbs_free (c->members, c->count);
}

static BOOL 
cltn_eq (cltn_t a, cltn_t b)
{
  assert (a != b);
  cltn_check (a);
  cltn_check (b);
  if (a->count != b->count)
    {
      return NO;
    }
  else
    {
      return mmbs_eq (a->members, b->members, a->count);
    }
}

static unsigned 
cltn_hash (cltn_t a)
{
  cltn_check (a);
  return mmbs_hash (a->members, a->count);
}

static int 
cltn_nummembers (cltn_t a)
{
  return a->count;
}

static void 
cltn_expand (cltn_t c)
{
  int oldc = c->capacity;
  assert (c->count == c->capacity);
  c->capacity += 1 + c->count;
  c->members = mmbs_realloc (c->members, oldc, c->capacity);
  assert (c->count < c->capacity);
}

static void 
cltn_insert (cltn_t c, id obj)
{
  assert (obj);
  cltn_check (c);
  if (c->count == c->capacity)
    cltn_expand (c);
  c->count = mmbs_insertlast (c->members, obj, c->count);
}

static void 
cltn_insertat (cltn_t c, id obj, int i)
{
  assert (obj && 0 <= i && i < c->count);
  cltn_check (c);
  if (c->count == c->capacity)
    cltn_expand (c);
  c->count = mmbs_insertat (c->members, obj, i, c->count);
}

static id 
cltn_remove (cltn_t c)
{
  if (c->count)
    {
      id obj = mmbs_removelast (c->members, c->count);
      c->count--;
      return obj;
    }
  else
    {
      return nil;
    }
}

static id 
cltn_removeat (cltn_t c, int i)
{
  id obj;
  assert (0 <= i && i < c->count);
  obj = mmbs_removeat (c->members, i, c->count);
  c->count--;
  return obj;
}

static id 
cltn_replace (cltn_t c, int i, id obj)
{
  return mmbs_replace (c->members, i, obj, c->count);
}

static void 
cltn_swap (cltn_t c, int i, int j)
{
  mmbs_swap (c->members, i, j, c->count);
}

static id 
cltn_at (cltn_t c, int i)
{
  cltn_check (c);
  return mmbs_at (c->members, i, c->count);
}

static id 
cltn_last (cltn_t c)
{
  cltn_check (c);
  return mmbs_last (c->members, c->count);
}

static int 
cltn_find (cltn_t c, id obj)
{
  cltn_check (c);
  return mmbs_find (c->members, obj, c->count);
}

static void 
cltn_sort (cltn_t self)
{
  mmbs_sort (self->members, self->count);
}

static void 
cltn_reverse (cltn_t self)
{
  mmbs_reverse (self->members, self->count);
}

static BOOL 
cltn_sorted (cltn_t self)
{
  return mmbs_sorted (self->members, self->count);
}

static void 
cltn_fileout (id aFiler, cltn_t c)
{
  int n = c->count;
  [aFiler fileOut:&n type:'i'];
  mmbs_fileout (aFiler, c->members, n);
}

static void 
cltn_filein (id aFiler, cltn_t c)
{
  int n;
  [aFiler fileIn:&n type:'i'];
  cltn_initcount (c, n);
  mmbs_filein (aFiler, c->members, n);
}

@implementation CACollection
- check
{
  int n = [self size];
  while (n--)
    [[self at:n] check];
  return [super check];
}


- _setUpCapacity:(int)aCapacity
{
  cltn_initcapacity (&value, aCapacity);
  return self;
}

+ new
{
  return [[super new] _setUpCapacity:16];
}

- new:(unsigned)aCapacity
{
  return [self notImplemented:_cmd];
}

+ new:(unsigned)aCapacity
{
  return [[super new] _setUpCapacity:aCapacity];
}

- capacity:(int)aCapacity
{
  return [isa new:aCapacity];
}

- empty
{
  return [isa new];
}
- copy
{
  id copy = [super copy];
  cltn_copy ([copy cltn_value], &value);
  return copy;
}

- deepCopy
{
  id copy = [super copy];
  cltn_deepcopy ([copy cltn_value], &value);
  return copy;
}

- release
{
  cltn_release (&value);
  return [super release];
}


- (cltn_t) cltn_value
{
  return &value;
}

- (BOOL) isEqual:aCollection
{
  return (self == aCollection) ? YES : cltn_eq (&value, [aCollection cltn_value]);
}

- (unsigned) hash
{
  return cltn_hash (&value);
}

- (BOOL) isEmpty
{
  return [self size] == 0;
}

- (BOOL) notEmpty
{
  return [self size] != 0;
}

- (unsigned) size
{
  return cltn_nummembers (&value);
}

- add:anObject
{
  if (anObject)
    {
      cltn_insert (&value, anObject);
      return [self invalidate];
    }
  else
    {
      return nil;
    }
}
- addIfAbsent:anObject
{
  if (anObject)
    {
      int i = [self offsetOf:anObject];
      if (i == -1)
	{
	  return [self add:anObject];
	}
      else
	{
	  return self;
	}
    }
  else
    {
      return nil;
    }
}
- at:(unsigned)i insert:anObject
{
  if (anObject)
    {
      int n = [self size];
      if (i > n)
	[self error:"-at:insert: index out of bounds"];
      if (i == n)
	{
	  cltn_insert (&value, anObject);
	}
      else
	{
	  cltn_insertat (&value, anObject, i);
	}
      return [self invalidate];
    }
  else
    {
      return nil;
    }
}

- removeLast
{
  return cltn_remove (&value);
}
- removeAt:(unsigned)i
{
  return cltn_removeat (&value, i);
}
- remove:anObject
{
  int i = [self offsetOf:anObject];
  return (i == -1) ? nil : [self removeAt:i];
}


- at:(unsigned)i put:anObject
{
  id member;

  /* Matrix makes abuse of this method...
   * the return value can be a pointer to a void object !
   * these reduction methods should be rewritten and not to do that...
   * so don't check self before replacing, and don't check return value
   */

  assert (anObject == nil || [anObject check]);
  member = cltn_replace (&value, i, anObject);
  assert ([self check]);
  return member;
}

- swapElementsAt:(int)i:(int)j
{
  assert ([self check]);
  cltn_swap (&value, i, j);
  assert ([self check]);
  return self;
}

- eachElement
{
  return [CASequence over:[CACollectionSequence content:self]];
}

- eachElementReversed
{
  return [CASequence over:[CACollectionSequenceReversed content:self]];
}

- at:(unsigned)i
{
  return cltn_at (&value, i);
}
- (float) floatValueAt:(int)i
{
  return [[self at:i] floatValue];
}
- (int) intValueAt:(int)i
{
  return [[self at:i] intValue];
}
- lastElement
{
  return cltn_last (&value);
}
- (unsigned) offsetOf:anObject
{
  if (anObject)
    {
      return cltn_find (&value, anObject);
    }
  else
    {
      return -1;
    }
}

- (BOOL) isSorted
{
  return cltn_sorted (&value);
}

- (BOOL) notSorted
{
  return [self isSorted] == NO;
}

- sort
{
  cltn_sort (&value);
  return self;
}

- reverse
{
  cltn_reverse (&value);
  return self;
}


- merge:aCltn
{
  id new;
  int i, m;
  int j, n;

  if ([self notSorted] || [aCltn notSorted])
    [self error:"Not Sorted"];

  i = 0;
  j = 0;
  m = [self size];
  n = [aCltn size];
  new = [self capacity:m + n];

  while (i < m && j < n)
    {
      id a = [self at:i];
      id b = [aCltn at:j];
      if ([a isLess:b])
	{
	  [new add:b];
	  j++;
	}
      else
	{
	  [new add:a];
	  i++;
	}
    }

  while (i < m)
    {
      [new add:[self at:i]];
      i++;
    }
  while (j < n)
    {
      [new add:[aCltn at:j]];
      j++;
    }

  return new;
}

- union:aCltn
{
  int i, n;
  id new = [self empty];
  for (i = 0, n = [self size]; i < n; i++)
    {
      [new addIfAbsent:[self at:i]];
    }
  for (i = 0, n = [aCltn size]; i < n; i++)
    {
      [new addIfAbsent:[aCltn at:i]];
    }
  return new;
}


- printOn:(IOD)aFile
{
  int i, n;

  if ((n = [self size]))
    {
      fprintf (aFile, "{");
      [[self at:0] printOn:aFile];
      for (i = 1; i < n; i++)
	{
	  fprintf (aFile, ",");
	  [[self at:i] printOn:aFile];
	}
      fprintf (aFile, "}");
    }
  else
    {
      fprintf (aFile, "{}");
    }

  return self;
}


- fileOutOn:aFiler
{
  [super fileOutOn:aFiler];
  cltn_fileout (aFiler, &value);
  return self;
}

- fileInFrom:aFiler
{
  [super fileInFrom:aFiler];
  cltn_filein (aFiler, &value);
  return self;
}

@end
 
