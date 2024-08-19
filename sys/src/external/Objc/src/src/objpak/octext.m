
/*
 * Portable Object Compiler (c) 1997,98,99,2003.  All Rights Reserved.
 * $Id: octext.m,v 1.4 2020/04/16 19:16:08 stes Exp $
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
#include "octext.h"
#include "ocstring.h"
#include "outofbnd.h"
#include "runarray.h"
#include "txtattr.h"
#include "paragrph.h"

#define SPRINTF_BUFSIZE (2048)

@implementation Text

- check
{
  [runs check];
  assert ([string size] == [runs size]);
  return self;
}

+ new
{
  return [self fromString:[String new]];
}

+ new:(unsigned)nChars
{
  return [self fromString:[String new:nChars]];
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

+ str:(STR)aString
{
  return [self fromString:[String str:aString]];;
}

+ sprintf:(STR)format,...
{
  id newtext;

  /* use OC macros for porting to SunOS4 */
  OC_VA_LIST ap;
  OC_VA_START (ap, format);
  newtext = [self vsprintf:format:&ap];
  OC_VA_END (ap);
  return newtext;
}

+ fromString:aString
{
  return [[super new] string:aString runs:[RunArray new]];
}

+ string:aString attribute:attrib
{
  return [[self fromString:aString] addAttribute:attrib];
}

- string:aString runs:anArray
{
  string = aString;
  runs = anArray;
  return self;
}

- copy
{
  return [[isa new] string:[string copy] runs:[runs copy]];
}

- free
{
  string = [string free];
  runs = [runs free];
  return [super free];
}


- (unsigned) hash
{
  return [string hash];
}

- (BOOL) isEqual:aStr
{
  [runs setsize:[string size]];
  if (self == aStr)
    {
      return YES;
    }
  else
    {
      return [string isEqual:[aStr string]] && [runs isEqual:[aStr runs]];
    }
}


- string
{
  return string;
}

- runs
{
  [runs setsize:[string size]];
  return runs;
}

- (STR) str
{
  return [string str];
}

- (unsigned) size
{
  return [string size];
}

- (char) charAt:(unsigned)anOffset
{
  return [string charAt:anOffset];
}

- (char) charAt:(unsigned)anOffset put:(char)aChar
{
  return [string charAt:anOffset put:aChar];
}

- at:(unsigned)anOffset insert:aString
{
  return [self at:anOffset insert:[aString str] count:[aString size]];
}

- at:(unsigned)anOffset insert:(char*)aString count:(int)size
{
  [string at:anOffset insert:aString count:size];
  [runs at:anOffset insert:aString count:size];
  return self;
}

- deleteFrom:(unsigned)p to:(unsigned)q
{
  [string deleteFrom:p to:q];
  [runs deleteFrom:p to:q];
  return self;
}

- concat:b
{
  [string concat:[b string]];
  [runs concat:[b runs]];
  return self;
}

- concatSTR:(STR)b
{
  [string concatSTR:b];
  [runs setsize:[string size]];
  return self;
}


- allBold
{
  [self addAttribute:[TextAttribute bold]];
  return self;
}

- makeBoldFrom:(unsigned)p to:(unsigned)q
{
  [self addAttribute:[TextAttribute bold] from:p to:q];
  return self;
}

- addAttribute:attribute
{
  unsigned n = [string size];
  [runs addAttribute:attribute from:0 size:n];
  return self;
}

- addAttribute:attribute from:(unsigned)p to:(unsigned)q
{
  unsigned n = [string size];
  if (p > q || q >= n)
    {
      [OutOfBounds signal];
      return self;
    }
  [runs addAttribute:attribute from:p size:q - p + 1];
  assert ([self check]);
  return self;
}

- attributesAt:(unsigned)i
{
  [runs setsize:[string size]];
  return [runs at:i];
}

- (unsigned) runLengthFor:(unsigned)i
{
  [runs setsize:[string size]];
  return [runs runLengthAt:i];
}

- (unsigned) fontNumberAt:(unsigned)i
{
  [runs setsize:[string size]];
  return [runs fontNumberAt:i];
}

- fontAt:(unsigned)i withStyle:textStyle
{
  [runs setsize:[string size]];
  return [runs fontAt:i withStyle:textStyle];
}


- asString
{
  return string;
}

- asText
{
  return self;
}

- asParagraph
{
  return [Paragraph withText:self];
}


- printOn:(IOD)aFile
{
  fprintf (aFile, "Text for ");
  [string printOn:aFile];
  return self;
}

@end
 
