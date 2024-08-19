
/*
 * Portable Object Compiler (c) 1998.  All Rights Reserved.
 * $Id: intarray.m,v 1.4 2020/04/16 19:16:07 stes Exp $
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
#include "intarray.h"
#include "outofbnd.h"
#include "ascfiler.h"
#include "ocstring.h"		/* OCMalloc */

#define DEFAULT_CAPACITY (16)

@implementation IntArray

/*****************************************************************************
 *
 * Creation
 *
 ****************************************************************************/


static void 
fill (int *p, int v, int n)
{
  while (n--)
    {
      *p++ = v;
    }
}

static void 
init (intary_t self, int v, int c)
{
  int *p = (int *) OC_MallocAtomic (c * sizeof (int));
  self->capacity = c;
  self->ptr = p;
  fill (p, v, c);
}

+ new
{
  id newObj = [super new];
  init ([newObj intaryvalue], 0, DEFAULT_CAPACITY);
  return newObj;
}

+ new:(unsigned)n
{
  id newObj = [super new];
  init ([newObj intaryvalue], 0, n);
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
      int anObject = OC_VA_ARG (vp, int);
      [newObject intAt:i put:anObject];
    }
  OC_VA_END (vp);
#endif

  return newObject;
}

static void 
intncpy (int *p, int *q, int n)
{
  while (n--)
    {
      *p++ = *q++;
    }
}

static void 
copy (intary_t dst, intary_t src)
{
  int n = src->capacity;

  dst->capacity = n + 1;
  dst->ptr = (int *) OC_MallocAtomic (dst->capacity * sizeof (int));

  intncpy (dst->ptr, src->ptr, n);
}

- copy
{
  id aCopy = [super copy];
  copy ([aCopy intaryvalue], (&value));
  return aCopy;
}

- deepCopy
{
  return [self copy];
}

static void 
clear (intary_t self)
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

- (intary_t) intaryvalue
{
  return (&value);
}

- (unsigned) size
{
  return (&value)->capacity;
}

static int 
intat (intary_t self, int i)
{
  if (0 <= i && i < self->capacity)
    {
      return (self->ptr) [i];
    }
  else
    {
      [OutOfBounds signal];
      return 0;
    }
}

- (int) intAt:(unsigned)anOffset
{
  return intat ((&value), anOffset);
}

static int 
intputint (int *self, int c)
{
  int r = *self;
  *self = c;
  return r;
}

static int 
putintat (intary_t self, int i, int c)
{
  if (0 <= i && i < self->capacity)
    {
      return intputint (self->ptr + i, c);
    }
  else
    {
      [OutOfBounds signal];
      return 0;
    }
}

- (int) intAt:(unsigned)anOffset put:(int)anInt
{
  return putintat ((&value), anOffset, anInt);
}

/*****************************************************************************
 *
 * Resizing
 *
 ****************************************************************************/

static void 
resize (intary_t self, unsigned c)
{
  int min, n;
  int *newp = (int *) OC_Realloc (self->ptr, c * sizeof (int));
  n = self->capacity;
  min = (n < c) ? n : c;
  fill (newp + min, 0, c - min);
  self->ptr = newp;
  self->capacity = c;
}

- (unsigned) capacity
{
  return (&value)->capacity;
}

- capacity:(unsigned)nSlots
{
  resize ((&value), nSlots);
  return self;
}

static void 
removezeroes (int *to, int *limit)
{
  int *from;

  while ((to < limit) && (*to != 0))
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
      *to++ = 0;
    }
}

static void 
packcontents (intary_t self)
{
  removezeroes (self->ptr, self->ptr + self->capacity);
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
    fprintf (aFile, "%i", [self intAt:0]);
  for (i = 1; i < n; i++)
    fprintf (aFile, ",%i", [self intAt:i]);
  return self;
}

/*****************************************************************************
 *
 * Archiving
 *
 ****************************************************************************/

#ifdef __PORTABLE_OBJC__
static void 
intfileout (id aFiler, int *p, int n)
{
  while (n--)
    {
      [aFiler fileOut:p++ type:'i'];
    }
}

static void 
intfilein (id aFiler, int *p, int n)
{
  while (n--)
    {
      [aFiler fileIn:p++ type:'i'];
    }
}

static void 
fileout (id aFiler, intary_t self)
{
  [aFiler fileOut:&self->capacity type:'i'];
  intfileout (aFiler, self->ptr, self->capacity);
}

static void 
filein (id aFiler, intary_t self)
{
  [aFiler fileIn:&self->capacity type:'i'];
  self->ptr = (int *) OC_MallocAtomic (self->capacity * sizeof (int));
  intfilein (aFiler, self->ptr, self->capacity);
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
 
