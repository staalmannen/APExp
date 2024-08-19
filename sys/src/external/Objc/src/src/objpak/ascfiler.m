
/*
 * Portable Object Compiler (c) 1997,2000,03,04.  All Rights Reserved.
 * $Id: ascfiler.m,v 1.5 2020/04/16 19:16:07 stes Exp $
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

#ifdef __PORTABLE_OBJC__

#include "config.h"
#include "ascfiler.h"
#include "ordcltn.h"
#include "unknownt.h"
#include "badvers.h"
#include "typeinc.h"
#include "outofbnd.h"
#include <string.h>		/* strlen */
#include <assert.h>
#include <stdlib.h>

@implementation AsciiFiler
/*****************************************************************************
 *
 * Initialize
 *
 ****************************************************************************/

static BOOL 
asciiFileOut (FILE * f, id anObject)
{
  BOOL r;
  id aFiler = [AsciiFiler new];
  r = [aFiler store:anObject onFile:f];
#ifndef OBJC_REFCNT
  [aFiler free];
#endif
  return r;
}

static id 
asciiFileIn (FILE * f)
{
  id r;
  id aFiler = [AsciiFiler new];
  r = [aFiler readFromFile:f];
#ifndef OBJC_REFCNT
  [aFiler free];
#endif
  return r;
}

+ initialize
{
  setfilein (asciiFileIn);
  setfileout (asciiFileOut);
  return self;
}

/*****************************************************************************
 *
 * Creating, Copying and Freeing
 *
 ****************************************************************************/


+ new
{
  return [super new];
}

- free
{
  if (ownFile)
    {
      fclose (file);
    }
  return [super free];
}

/*****************************************************************************
 *
 * Storing and Reading Objects
 *
 ****************************************************************************/


- (BOOL) store:anObject on:(STR)aFileName
{
  BOOL r;

  if ((file = fopen (aFileName, "w")))
    {
      ownFile = YES;
      r = [self store:anObject onFile:file];
      if (ownFile)
	{
	  ownFile = NO;
	  fclose (file);
	}
    }
  else
    {
      r = NO;
    }

  return r;
}

- readFrom:(STR)aFileName
{
  id r;

  if ((file = fopen (aFileName, "r")))
    {
      ownFile = YES;
      r = [self readFromFile:file];
      if (ownFile)
	{
	  ownFile = NO;
	  fclose (file);
	}
    }
  else
    {
      r = nil;
    }

  return r;
}
/*****************************************************************************
 *
 * File Out Operation
 *
 ****************************************************************************/


/* Stepstone 4.x has release 3.1 or 4 for AsciiFiler */
/* make Portable Object Compiler starts at 111       */
#define	FILER_3_1		0
#define FILER_3_3		1
#define FILER_3_3_201	        2
#define FILER_4_0		3
#define POC_1_4_4		144
#define POC_1_8_8		188	/* changed OrdCltn */
#define POC_3_1_7		317	/* fixed patchPointer bug */
#define POC_3_2_5		325	/* some refcnt issues */

#define ASCIIFILER_VERSION POC_3_2_5

static BOOL 
isClass (id anObject)
{
  return anObject != nil && [anObject class] == anObject;
}

- (BOOL) store:anObject onFile:(FILE *)aFile
{
  int i, n;

  file = aFile;

  /* write Filer type and version */
  fprintf (file, "#%s i%d \n", [self name], ASCIIFILER_VERSION);

  /* first pass - build TOC */
  inSecondPass = NO;
  toc = [OrdCltn new];
  [self fileOutObject:anObject];

  /* second pass - write data to file */

  inSecondPass = YES;
  for (i = 0, n = [toc size]; i < n; i++)
    {
#ifdef STRICTSTEPSTONE
      fprintf (file, "0 ");	/* ixvars - unused for us */
#else
      fprintf (file, "%i ", i + 1);	/* record number, useful! */
#endif
      [[toc at:i] fileOutOn:self];
      fprintf (file, "\n");
    }

  /* clean up */
  inSecondPass = NO;
#ifndef OBJC_REFCNT
  toc = [toc free];
#else
  toc = nil;
#endif

  return YES;
}

static void 
outClass (FILE * file, void *value)
{
  id aClass = *((id *) value);
  fprintf (file, "#%s ", [aClass name]);
}

static void 
outObject (id self, FILE * file, id toc, void *value)
{
  id anObject = *((id *) value);

  /* this allows "isa" to be filed out as '@' */
  if (isClass (anObject))
    {
      [self fileOut2:value type:'#'];
      return;
    }

  if (anObject)
    {
      int offset = [toc offsetOf:anObject];
      if (offset == -1)
	{
	  [[[OutOfBounds new:[toc size]] at:-1] signal];
	}
      else
	{
	  fprintf (file, "@%i ", offset + 1);
	}
    }
  else
    {
      fprintf (file, "@0 ");
    }
}

static void 
outChar (FILE * file, void *value)
{
  char c = *((char *) value);
  fprintf (file, "c%c ", c);
}

static void 
outInt (FILE * file, void *value)
{
  int i = *((int *) value);
  fprintf (file, "i%i ", i);
}

static void 
outUShort (FILE * file, void *value)
{
  unsigned i = *((unsigned short *) value);
  fprintf (file, "S%u ", i);
}

static void 
outShort (FILE * file, void *value)
{
  int i = *((short *) value);
  fprintf (file, "s%i ", i);
}

static void
outfloat (FILE * file, void *value)
{
  float f = *((float *) value);
  fprintf (file, "f%f ", f);
}

static void
outdouble (FILE * file, void *value)
{
  double d = *((double *) value);
  fprintf (file, "d%f ", d);
}



#define DOLLARASCII 044

static void 
outSTR (FILE * file, void *value)
{
  STR s;
  int len;

  s = *((STR *) value);

  if (s)
    {
      len = strlen (s);
      fprintf (file, "*%i\"%s ", len, s);
    }
  else
    {
      fprintf (file, "%c0 ", DOLLARASCII);
    }
}

- fileOut2:(void *)value type:(char)typeDesc
{
  switch (typeDesc)
    {
      case '#':outClass (file, value);
      break;
    case '@':
      outObject (self, file, toc, value);
      break;
    case 'c':
      outChar (file, value);
      break;
    case 'i':
      outInt (file, value);
      break;
    case 's':
      outShort (file, value);
      break;
    case 'S':
      outUShort (file, value);
      break;
    case 'f':
      outfloat (file, value);
      break;
    case 'd':
      outdouble (file, value);
      break;
    case '*':
      outSTR (file, value);
      break;
    case DOLLARASCII:
      fprintf (file, "%c0 ", DOLLARASCII);
      break;
    default:
      {
	[[[UnknownType new] typeDesc:typeDesc] signal];
	break;
      }
    }

  return self;
}

- fileOutObject:anObject
{
  if (anObject != nil && !isClass (anObject) && [toc find:anObject] == nil)
    {
      [toc add:anObject];
      [anObject fileOutOn:self];
    }

  return self;
}

- fileOut:(void *)value type:(char)typeDesc
{
  if (inSecondPass)
    return [self fileOut2:value type:typeDesc];

  if (typeDesc == '@')
    {
      id anObject = *((id *) value);
      return [self fileOutObject:anObject];
    }

  return self;
}

/*****************************************************************************
 *
 * File In Operation
 *
 ****************************************************************************/


static int 
nextCode (FILE * file)
{
  int code;
  do
    {
      code = getc (file);
    }
  while (code == ' ' || code == '\t');
  return code;
}

#define DEBUGLEX 0

static int 
lex (id self, FILE * file, int expected, char *buffer)
{
  int code = nextCode (file);
  char *q = buffer;

  switch (code)
    {
      case 'c':
	case 'i':
	case 's':
	case 'S':
	case 'f':
	case 'd':
	case '@':
	case '#':
      {
	int c;
	while ((c = getc (file)) != ' ')
	  *q++ = c;
	*q = 0;
	break;
      }
    default:
      break;
    }

  if (code == DOLLARASCII)
    return code;		/* even when * requested */

  if (code == expected)
    {
#if DEBUGLEX
      if (code == '\n')
	{
	  fprintf (stderr, "lex: '\\n'\n");
	}
      else if (buffer)
	{
	  fprintf (stderr, "lex: '%c' '%s'\n", code, buffer);
	}
      else
	{
	  fprintf (stderr, "lex: '%c'\n", code);
	}
#endif
      return code;
    }
  else
    {
      [[[TypeInconsistency new] got:code wanted:expected] signal];
      return 0;
    }
}

static int 
a_to_i (char *s)
{
  return atoi (s);
}

static double 
a_to_f (char *s)
{
  return atof (s);
}

static int 
skipIX (FILE * file)
{
  int c;
  while (feof (file) == 0 && (c = getc (file)) != ' ')
    {
#if DEBUGLEX
      fprintf (stderr, "lex: '%c'\n", c);
#endif
    }
  return 0 == feof (file);
}

static STR 
lexSTR (id self, FILE * file)
{
  int expected = '*';
  int code = nextCode (file);

  if (code == DOLLARASCII)
    {
      skipIX (file);
      return NULL;
    }

  if (code != expected)
    {
      [[[TypeInconsistency new] got:code wanted:expected] signal];
      return NULL;
    }
  else
    {
      STR q;
      STR s;
      int c, len;
      char buffer [32];

      q = buffer;
      while ((c = getc (file)) != '\"')
	*q++ = c;
      *q = 0;
      len = a_to_i (buffer);
      s = OC_Malloc (len + 1);
      q = s;
      while (len--)
	*q++ = getc (file);
      *q++ = 0;

#if DEBUGLEX
      fprintf (stderr, "lex: '%c' '%s'\n", code, s);
#endif
      return s;
    }
}

static id 
lexClass (id self, FILE * file)
{
  char buffer [1024];
  lex (self, file, '#', buffer);
  return [self idOfSTR:buffer];
}

static int 
lexObjectOffset (id self, FILE * file)
{
  char buffer [32];
  lex (self, file, '@', buffer);
  return a_to_i (buffer);
}

static int 
lexChar (id self, FILE * file)
{
  char buffer [8];
  lex (self, file, 'c', buffer);
  return buffer [0];
}

static short int 
lexShort (id self, FILE * file)
{
  char buffer [32];
  lex (self, file, 's', buffer);
  return a_to_i (buffer);
}

static unsigned short int 
lexUShort (id self, FILE * file)
{
  char buffer [32];
  lex (self, file, 'S', buffer);
  return a_to_i (buffer);
}

static int 
lexInt (id self, FILE * file)
{
  char buffer [32];
  lex (self, file, 'i', buffer);
  return a_to_i (buffer);
}

static float 
lexfloat (id self, FILE * file)
{
  char buffer [32];
  lex (self, file, 'f', buffer);
  return a_to_f (buffer);
}

static float 
lexdouble (id self, FILE * file)
{
  char buffer [32];
  lex (self, file, 'd', buffer);
  return a_to_f (buffer);
}


static void 
skipNL (id self, FILE * file)
{
  lex (self, file, '\n', NULL);
}

- readFromFile:(FILE *)aFile
{
  id anObject;
  int i, n, version;

  file = aFile;

  /* see if this the right filer and version */
  if (isa != lexClass (self, file))
    {
      [BadVersion signal];
      return nil;
    }
  version = lexInt (self, file);
  if (version != ASCIIFILER_VERSION)
    {
      id e = [BadVersion new];
      [[e goodVersion:ASCIIFILER_VERSION badVersion:version] signal];
      return nil;
    }

  skipNL (self, file);

  toc = [OrdCltn new];
  patchSize = 0;
  patchCapacity = 64;
  patchPointers = (void **) OC_Malloc (sizeof (void *) * patchCapacity);

  /* a different strategy might be to first allocate all instances
   * then start sending "fileInFrom:" (so that we don't have to patch
   * pointers).  However, we then would have to deal with newlines in
   * strings and characters
   */

  while (feof (file) == 0 && skipIX (file))
    {
      id tmpObject;
      id aClass = lexClass (self, file);
      tmpObject = [aClass fileInFrom:self];
      [toc add:tmpObject];
      skipNL (self, file);
    }

  /* second pass, to patch "id" vars  */

  for (i = 0; i < patchSize; i++)
    {
      int offset;
      void *value = patchPointers [i];
      offset = *((int *) value);
      if (offset > [toc size])
	{
	  [[[OutOfBounds new:[toc size]] at:offset] signal];
	}
      else
	{
	  id realObject = (offset) ? [toc at : offset - 1]:nil;
	  // careful here, because *value, the offset,
	  // is not a valid object for idAssign()
	  // clear it first
	  *(void **) value = NULL;
	  *((id *) value) = realObject;
	}
    }

  /* send awake */

  for (i = 0, n = [toc size]; i < n; i++)
    [[toc at:i] awakeFrom:self];

  /* cleanup */

  anObject = [toc firstElement];
  OC_Free (patchPointers);
  patchPointers = NULL;
#ifndef OBJC_REFCNT
  toc = [toc free];
#else
  toc = nil;
#endif

  return anObject;
}

- fileIn:(void *)value type:(char)typeDesc
{
  switch (typeDesc)
    {
      case '#':
      {
	*((id *) value) = lexClass (self, file);
	break;
      }
    case '@':
      {
	int offset;
	offset = lexObjectOffset (self, file);
	if (offset <= [toc size])
	  {
	    *((id *) value) = (offset) ? [toc at : offset - 1]:nil;
	  }
	else
	  {
	    /* store offset instead of object */
	    *((int *) value) = offset;
	    if (patchSize + 1 == patchCapacity)
	      {
		patchCapacity = patchCapacity * 2 + 1;
		patchPointers = (void **) OC_Realloc (patchPointers, patchCapacity);
	      }
	    /* keep track of pointers to be patched */
	    patchPointers [patchSize] = value;
	    patchSize++;
	  }
	break;
      }
    case 'c':
      {
	*((char *) value) = lexChar (self, file);
	break;
      }
    case 'i':
      {
	*((int *) value) = lexInt (self, file);
	break;
      }
    case 's':
      {
	*((short *) value) = lexShort (self, file);
	break;
      }
    case 'S':
      {
	*((unsigned short *) value) = lexUShort (self, file);
	break;
      }
    case 'f':
      {
	*((float *) value) = lexfloat (self, file);
	break;
      }
    case 'd':
      {
	*((double *) value) = lexdouble (self, file);
	break;
      }
    case '*':
      {
	*((STR *) value) = lexSTR (self, file);
	break;
      }
    case DOLLARASCII:
      {
	*((void **) value) = NULL;
	skipIX (file);
	break;
      }
    default:
      {
	[[[UnknownType new] typeDesc:typeDesc] signal];
	break;
      }
    }

  return self;
}


@end

#endif /* __PORTABLE_OBJC__ */
 
