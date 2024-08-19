
/*
 * Portable Object Compiler (c) 1998,2003.  All Rights Reserved.
 * $Id: idarray.m,v 1.4 2020/04/16 19:16:07 stes Exp $
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
#include "idarray.h"
#include "outofbnd.h"
#include "ocstring.h"
#include "ascfiler.h"

#define DEFAULT_CAPACITY (16)

@implementation IdArray

/*****************************************************************************
 *
 * Creation
 *
 ****************************************************************************/


#if 0
static void 
idfill (id * p, id v, int c)
{
  while (c--)
    {
      *p++ = v;
    }
}
#endif

static void 
init (idary_t self, id v, int c)
{
  id *p = (id *) OC_Calloc (c * sizeof (id));
  self->capacity = c;
  self->ptr = p;
}

+ new
{
  id newObj = [super new];
  init ([newObj idaryvalue], nil, DEFAULT_CAPACITY);
  return newObj;
}

+ new:(unsigned)n
{
  id newObj = [super new];
  init ([newObj idaryvalue], nil, n);
  return newObj;
}

+ with:(int)nArgs,...
{
  /* use OC macros for porting to SunOS4 */
  unsigned i;
  OC_VA_LIST vp;
  id newObject = [self new:nArgs];

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
  for (i = 0; i < nArgs; i++)
    {
      id anObject = OC_VA_ARG (vp, id);
      [newObject at:i put:anObject];
    }
  OC_VA_END (vp);
#endif

  return newObject;
}

static void 
idncpy (id * p, id * q, int n)
{
  while (n--)
    {
      *p++ = *q++;
    }
}

static void 
copy (idary_t dst, idary_t src)
{
  int n = src->capacity;
  dst->capacity = n;
  dst->ptr = (id *) OC_Malloc (n * sizeof (id));
  idncpy (dst->ptr, src->ptr, n);
}

- copy
{
  id aCopy = [super copy];
  copy ([aCopy idaryvalue], (&value));
  return aCopy;
}

static void 
idndeepcpy (id * p, id * q, int n)
{
  while (n--)
    {
      *p++ = [*q++ deepCopy];
    }
}

static void 
deepcopy (idary_t dst, idary_t src)
{
  int n = src->capacity;
  dst->capacity = n;
  dst->ptr = (id *) OC_Malloc (n * sizeof (id));
  idndeepcpy (dst->ptr, src->ptr, n);
}

- deepCopy
{
  id aCopy = [super copy];
  deepcopy ([aCopy idaryvalue], (&value));
  return aCopy;
}

static void 
clear (idary_t self)
{
  OC_Free (self->ptr);
  self->ptr = NULL;
}

- free
{
  clear ((&value));
  return [super free];
}

/*****************************************************************************
 *
 * Interrogation
 *
 ****************************************************************************/

- (idary_t) idaryvalue
{
  return (&value);
}

static unsigned 
getsize (idary_t self)
{
  unsigned s = 0;
  int i = self->capacity;
  while (i--)
    if ((self->ptr) [i])
      s++;
  return s;
}

- (unsigned) size
{
  return getsize ((&value));
}

static id 
at (idary_t self, int i)
{
  if (0 <= i && i < self->capacity)
    {
      return (self->ptr) [i];
    }
  else
    {
      [OutOfBounds signal];
      return nil;
    }
}

- at:(unsigned)anOffset
{
  return at ((&value), anOffset);
}

static id 
idputid (id * self, id c)
{
  id r = *self;
  *self = c;
  return r;
}

static id 
putat (idary_t self, int i, id c)
{
  if (0 <= i && i < self->capacity)
    {
      return idputid (self->ptr + i, c);
    }
  else
    {
      [OutOfBounds signal];
      return nil;
    }
}

- at:(unsigned)anOffset put:anObject
{
  return putat ((&value), anOffset, anObject);
}

/*****************************************************************************
 *
 * Resizing
 *
 ****************************************************************************/

- (unsigned) capacity
{
  return ((&value)->capacity);
}

static void 
resize (idary_t self, unsigned c)
{
  int min, n;
  id *newp = (id *) OC_Realloc (self->ptr, c * sizeof (id));
  n = self->capacity;
  min = (n < c) ? n : c;
  memset (newp + min, 0, sizeof (id) * (c - min));
  self->ptr = newp;
  self->capacity = c;
}

- capacity:(unsigned)nSlots
{
  resize ((&value), nSlots);
  return self;
}

static void 
removenils (id * to, id * limit)
{
  id *from;

  while ((to < limit) && (*to != nil))
    {
      to++;
    }
  for (from = to + 1; from < limit; from++)
    {
      if (*from)
	*to++ = *from;
    }
  while (to < limit)
    {
      *to++ = nil;
    }
}

static void 
packcontents (idary_t self)
{
  removenils (self->ptr, self->ptr + self->capacity);
}

- packContents
{
  packcontents ((&value));
  return self;
}

/*****************************************************************************
 *
 * Printing
 *
 ****************************************************************************/

- printOn:(IOD)aFile
{
  unsigned i, n = [self size];

  if (n)
    {
      id o = [self at:0];
      if (o)
	[o printOn:aFile];
      else
	fprintf (aFile, "nil");
    }

  for (i = 0; i < n; i++)
    {
      id o = [self at:i];
      fprintf (aFile, ",");
      if (o)
	[o printOn:aFile];
      else
	fprintf (aFile, "nil");
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
idfileout (id aFiler, id * p, int n)
{
  while (n--)
    {
      [aFiler fileOut:p++ type:'@'];
    }
}

static void 
idfilein (id aFiler, id * p, int n)
{
  while (n--)
    {
      [aFiler fileIn:p++ type:'@'];
    }
}

static void 
fileout (id aFiler, idary_t self)
{
  [aFiler fileOut:&self->capacity type:'i'];
  idfileout (aFiler, self->ptr, self->capacity);
}

static void 
filein (id aFiler, idary_t self)
{
  [aFiler fileIn:&self->capacity type:'i'];
  self->ptr = (id *) OC_Malloc (self->capacity * sizeof (id));
  idfilein (aFiler, self->ptr, self->capacity);
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

#endif /* __PORTABLE_OBJC__ */

@end
 
