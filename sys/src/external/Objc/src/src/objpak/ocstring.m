
/*
 * Portable Object Compiler (c) 1997,98,99,2003,09,14.  All Rights Reserved.
 * $Id: ocstring.m,v 1.6 2020/04/16 19:16:07 stes Exp $
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
#include <ctype.h>
#include <stdlib.h>
#include "ocstring.h"
#include "outofbnd.h"
#include "ascfiler.h"

#define DEFAULT_CAPACITY (16)
#define SPRINTF_BUFSIZE (2048)

typedef struct
  {
    @defs (String)
  }
TFString;

@implementation String

/*****************************************************************************
 *
 * Creation
 *
 ****************************************************************************/

static int 
str_len (char *s)
{
  int len = 0;
  while (*s++)
    len++;
  return len;
}

static void 
str_ncpy (char *dst, char *src, int n)
{
  int c = 0;
  while (n-- && (c = *src++))
    {
      *dst++ = c;
    }
  *dst++ = '\0';
}

static void 
str_cpy (char *dst, char *src)
{
  int c = 0;
  while ((c = *src++))
    {
      *dst++ = c;
    }
  *dst++ = '\0';
}

static void 
init (objstr_t self, char *s, int n, int c)
{
  assert (0 <= n && n + 1 <= c);

  self->count = n;
  self->capacity = c;
  self->ptr = (char *) OC_MallocAtomic (c);

  str_ncpy (self->ptr, s, n);
  self->ptr [n] = '\0';
}

+ new
{
  return [self new:DEFAULT_CAPACITY];
}

+ new:(unsigned)nChars
{
  id newObj = [super new];
  init ([newObj objstrvalue], "", 0, nChars);
  return newObj;
}

static void 
initstr (objstr_t self, char *s, int n)
{
  init (self, s, n, n + 1);
}

+ str:(STR)aString
{
  if (aString)
    {
      id newObj = [super new];
      int n = str_len (aString);
#if OTBCRT
      /* works always, also for -otb */
      initstr ([newObj objstrvalue], aString, n);
#else
      /* faster, but doesn't work for -otb */
      initstr (&(((TFString *) newObj)->value), aString, n);
#endif
      return newObj;
    }
  else
    {
      return [self new];
    }
}

+ chars:(STR)aString count:(int)n
{
  if (aString)
    {
      id newObj = [super new];
#if OTBCRT
      /* works always, also for -otb */
      initstr ([newObj objstrvalue], aString, n);
#else
      /* faster, but doesn't work for -otb */
      initstr (&(((TFString *) newObj)->value), aString, n);
#endif
      return newObj;
    }
  else
    {
      return [self new];
    }
}

+ vsprintf:(STR)format:(OC_VA_LIST*)ap
{
  char aBuffer [SPRINTF_BUFSIZE];

#if OBJCRT_USE_SNPRINTF
  if (vsnprintf (aBuffer, SPRINTF_BUFSIZE, format, *ap) >= SPRINTF_BUFSIZE)
    {
      [OutOfBounds signal];
      return nil;
    }
#else
  vsprintf (aBuffer, format, *ap);
#endif

  return [self str:aBuffer];
}

+ sprintf:(STR)format,...
{
  id newString;

  /* use OC macros for porting to SunOS4 */
  OC_VA_LIST ap;
  OC_VA_START (ap, format);
  newString = [self vsprintf:format:&ap];
  OC_VA_END (ap);
  return newString;
}

static void 
copy (objstr_t dst, objstr_t src)
{
  int n = src->count;

  assert (n == str_len (src->ptr) && 0 <= n && n < src->capacity);

  dst->count = n;
  dst->capacity = n + 1;
  dst->ptr = (char *) OC_MallocAtomic (n + 1);
  str_cpy (dst->ptr, src->ptr);
}

- copy
{
  id aCopy = [super copy];
  copy ([aCopy objstrvalue], (&value));
  return aCopy;
}

- deepCopy
{
  return [self copy];
}

static void 
clear (objstr_t self)
{
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
  clear ((&value));
  return [super release];
#else
  return [self notImplemented:_cmd];
#endif
}

/*****************************************************************************
 *
 * Comparison
 *
 ****************************************************************************/

static int 
str_cmp (char *s1, char *s2)
{
  int r;
  int c1, c2;

  while (1)
    {
      c1 = *s1++;
      c2 = *s2++;
      if (c1 == '\0')
	return (c2 == 0) ? 0 : -1;
      if (c2 == '\0')
	return 1;
      if ((r = c1 - c2))
	return r;
    }
}

static int 
cmpstr (objstr_t a, char *b)
{
  return str_cmp (a->ptr, b);
}

- (int) compare:aStr
{
  return (self == aStr) ? 0 : cmpstr ((&value), [aStr str]);
}

- (int) compareSTR:(STR)aString
{
  return cmpstr ((&value), aString);
}

static unsigned 
str_hash (char *s)
{
  unsigned hash = 0;

  while (1)
    {
      if (*s == '\0')
	break;
      else
	hash ^= *s++;
      if (*s == '\0')
	break;
      else
	hash ^= (*s++ << 8);
      if (*s == '\0')
	break;
      else
	hash ^= (*s++ << 16);
      if (*s == '\0')
	break;
      else
	hash ^= (*s++ << 24);
    }

  return hash;
}

static unsigned 
hash (objstr_t self)
{
  return str_hash (self->ptr);
}

- (unsigned) hash
{
  return hash ((&value));
}

static int 
str_dictcmp (char *s1, char *s2)
{
  int r;
  int c1, c2;

  while (1)
    {
      while ((c1 = *s1++) && !isalnum (c1))
	;
      while ((c2 = *s2++) && !isalnum (c2))
	;
      if (c1 == '\0')
	return (c2 == 0) ? 0 : -1;
      if (c2 == '\0')
	return 1;
      if (isupper (c1))
	c1 = tolower (c1);
      if (isupper (c2))
	c2 = tolower (c2);
      if ((r = c1 - c2))
	return r;
    }
}

static int 
dictcmp (objstr_t a, objstr_t b)
{
  return str_dictcmp (a->ptr, b->ptr);
}

- (int) dictCompare:aStr
{
  return dictcmp ((&value), [aStr objstrvalue]);
}

- (BOOL) isEqual:aStr
{
  return (self == aStr) ? YES : ([self compare:aStr] == 0);
}

- (BOOL) isEqualSTR:(STR)aString
{
  return [self compareSTR:aString] == 0;
}

/*****************************************************************************
 *
 * Interrogation
 *
 ****************************************************************************/

- (objstr_t) objstrvalue
{
  return &value;
}

- (unsigned) size
{
  return (&value)->count;
}

static char 
charat (objstr_t self, int i)
{
  if (0 <= i && i < self->count)
    {
      return (self->ptr) [i];
    }
  else
    {
      return 0;
    }
}

- (char) charAt:(unsigned)anOffset
{
  return charat ((&value), anOffset);
}

static char 
strputchar (char *self, char c)
{
  char r = *self;
  *self = c;
  return r;
}

static char 
putcharat (objstr_t self, int i, char c)
{
  if (0 <= i && i < self->count)
    {
      return strputchar (self->ptr + i, c);
    }
  else
    {
      return 0;
    }
}

- (char) charAt:(unsigned)anOffset put:(char)aChar
{
  return putcharat ((&value), anOffset, aChar);
}

/*****************************************************************************
 *
 * Concatenation
 *
 ****************************************************************************/

- (STR) strcat:(STR)aBuffer
{
  str_cpy (aBuffer + str_len (aBuffer), [self str]);
  return aBuffer;
}

static void 
expand (objstr_t self)
{
  assert (self->count + 1 <= self->capacity);
  self->capacity = 1 + self->capacity * 2;
  self->ptr = (char *) OC_Realloc (self->ptr, self->capacity);
}

static void 
concat (objstr_t self, char *s, int n)
{
  assert (n == str_len (s));
  while (self->count + n + 1 > self->capacity)
    expand (self);
  str_cpy (self->ptr + self->count, s);
  self->count += n;
}

/* patch from finnw, to dereference ptr after expand() */

static void 
concat_self (objstr_t self)
{
  while (2 * self->count + 1 > self->capacity)
    expand (self);
  str_ncpy (self->ptr + self->count, self->ptr, self->count);
  self->count *= 2;
}

- concat:aString
{
  if (aString == self)
    {
      concat_self (&value);
    }
  else
    {
      [self concatSTR:[aString str]];
    }
  return self;
}

- concatSTR:(STR)aString
{
  concat ((&value), aString, str_len (aString));
  return self;
}

- concatenateSTR:(STR)aString
{
  return [self concatSTR:aString];
}

static void 
atinsert (objstr_t self, int i, char *s, int n)
{
  int j;
  char *p;

  while (self->count + n + 1 > self->capacity)
    expand (self);
  j = self->count;
  p = self->ptr;
  while ((--j) >= i)
    {
      p [j + n] = p [j];
    }
  for (j = i; j < i + n; j++)
    {
      p [j] = *s++;
    }
  self->count += n;
  (self->ptr) [self->count] = '\0';
}

- at:(unsigned)anOffset insert:(char*)aString count:(int)n
{
  if (n)
    atinsert ((&value), anOffset, aString, n);
  return self;
}

- at:(unsigned)anOffset insert:aString
{
  id res, tmpString;
  /* patch from finnw to insert string in itself */
  tmpString = (aString == self) ? [aString copy] : aString;
  res = [self at:anOffset insert:[tmpString str] count:[tmpString size]];
  if (tmpString != aString)
    [tmpString free];
  return res;
}

static void 
deleteat (objstr_t self, int p, int n)
{
  int i, m;
  char *ptr;

  ptr = self->ptr;
  m = self->count;
  for (i = p + n; i < m; i++)
    {
      ptr [i - n] = ptr [i];
    }

  self->count -= n;
  (self->ptr) [self->count] = '\0';
}

- deleteFrom:(unsigned)p to:(unsigned)q
{
  if (q >= [self size] || p > q)
    {
      [OutOfBounds signal];
      return self;
    }
  else
    {
      deleteat ((&value), p, q - p + 1);
      return self;
    }
}

static void 
assign (objstr_t self, char *s, int n)
{
  assert (n <= str_len (s));
  while (n + 1 > self->capacity)
    expand (self);
  str_ncpy (self->ptr, s, n);
  (self->ptr) [n] = '\0';
  self->count = n;
}

- assignSTR:(STR)aString
{
  assign ((&value), aString, str_len (aString));
  return self;
}

- assignSTR:(STR)aString length:(unsigned)nChars
{
  assign ((&value), aString, nChars);
  return self;
}

/*****************************************************************************
 *
 * Format Conversions
 *
 ****************************************************************************/

- (double) asDouble
{
  return atof ([self str]);
}

- (int) asInt
{
  return atoi ([self str]);
}

- (long) asLong
{
  return atol ([self str]);
}

- asSTR:(STR)aBuffer maxSize:(int)aSize
{
  str_ncpy (aBuffer, [self str], aSize);
  return self;
}

- (STR) str
{
  return (&value)->ptr;
}

- (STR) strCopy
{
  struct objstr aCopy;
  copy (&aCopy, (&value));
  return aCopy.ptr;
}

/*****************************************************************************
 *
 * Conversions
 *
 ****************************************************************************/

static void 
strtolower (char *s)
{
  char c;
  while ((c = *s))
    {
      *s++ = tolower (c);
    }
}

static void 
objtolower (objstr_t self)
{
  strtolower (self->ptr);
}

- toLower
{
  objtolower ((&value));
  return self;
}

static void 
strtoupper (char *s)
{
  char c;
  while ((c = *s))
    {
      *s++ = toupper (c);
    }
}

static void 
objtoupper (objstr_t self)
{
  strtoupper (self->ptr);
}

- toUpper
{
  objtoupper ((&value));
  return self;
}

/*****************************************************************************
 *
 * Printing
 *
 ****************************************************************************/

- printOn:(IOD)aFile
{
  fprintf (aFile, "%s", [self str]);
  return self;
}

/*****************************************************************************
 *
 * Archiving
 *
 ****************************************************************************/

#ifdef __PORTABLE_OBJC__
static void 
fileout (id aFiler, objstr_t self)
{
  [aFiler fileOut:&self->count type:'i'];
  [aFiler fileOut:&self->capacity type:'i'];
  [aFiler fileOut:&self->ptr type:'*'];
}

static void 
filein (id aFiler, objstr_t self)
{
  int c;

  [aFiler fileIn:&self->count type:'i'];
  [aFiler fileIn:&c type:'i'];	/* unused */
  [aFiler fileIn:&self->ptr type:'*'];

  self->capacity = self->count + 1;
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

/* some defs needed when cross-compiling with a DIFFERENT compiler */
/* placed this here 'cause we will have a different objcrt.h and Object.h */

#if !defined(__PORTABLE_OBJC__)
#if !defined(OCLONGLONG)

void *
OC_Malloc (size_t n)
{
  return malloc (n);
}
void *
OC_Realloc (void *p, size_t n)
{
  return realloc (p, n);
}

#endif /* OCLONGLONG */

void *
OC_Calloc (size_t nBytes)
{
  char *p = (char *) OC_Malloc (nBytes);
  memset (p, 0, nBytes);
  return (void *) p;
}
void *
OC_MallocAtomic (size_t n)
{
  return malloc (n);
}
void *
OC_Free (void *p)
{
  free (p);
  return NULL;
}

#endif /* __PORTABLE_OBJC__ */
 
