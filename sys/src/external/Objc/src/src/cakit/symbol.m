
/*
 * Computer Algebra Kit (c) 1993,00 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: symbol.m,v 1.7 2000/10/12 14:40:26 stes Exp $
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

@implementation Symbol

static BOOL 
CheckValue (STR buf, int len)
{
  if (len && isalpha (buf [0]))
    {
      int i;
      for (i = 1; i < len; i++)
	if (isalnum (buf [i]) == 0)
	  return NO;
      return YES;
    }
  else
    {
      return NO;
    }
}

+ str:(STR)aString
{
  int len = strlen (aString);
  if (CheckValue (aString, len))
    {
      return [self chars:aString count:len];
    }
  else
    {
      return nil;
    }
}

- _setUpChars:(char *)aBuffer count:(int)numChars
{
  value = (char *) OC_Malloc (sizeof (char) * (numChars + 1));
  strncpy (value, aBuffer, numChars);
  value [numChars] = 0;
  return self;
}

- chars:(STR)aBuffer count:(int)numChars
{
  return [self notImplemented:_cmd];
}

+ chars:(STR)aBuffer count:(int)numChars
{
  return [[super new] _setUpChars:aBuffer count:numChars];
}

- set_str:(STR)x
{
  value = x;
  return self;
}

- copy
{
  STR copy = OC_Malloc (sizeof (char) * (strlen (value) + 1));
  strcpy (copy, value);
  return [[super copy] set_str:copy];
}

- deepCopy
{
  return [self copy];
}

- release
{
  OC_Free (value);
  return [super release];
}


- (STR) str
{
  return value;
}

- str:(STR)aString
{
  return [isa str:aString];
}

- (unsigned) hash
{
  unsigned len = strlen (value);
  assert (len);
  return (len & 255) + (((unsigned) value [0]) << 8) + (((unsigned) value [len - 1]) << 16);
}

- (BOOL) isEqual:b
{
  return (self == b) ? YES : 0 == strcmp (value, [b str]);
}

- (int) compare:b
{
  return (self == b) ? 0 : strcmp (value, [b str]);
}

- (BOOL) isLetter
{
  return strlen (value) == 1;
}


- printOn:(IOD)aFile
{
  fprintf (aFile, "%s", value);
  return self;
}


- fileOutOn:aFiler
{
  [super fileOutOn:aFiler];
  [aFiler fileOut:&value type:'*'];
  return self;
}

- fileInFrom:aFiler
{
  [super fileInFrom:aFiler];
  [aFiler fileIn:&value type:'*'];
  return self;
}

@end
 
