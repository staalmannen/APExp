
/*
 * Portable Object Compiler (c) 1997.  All Rights Reserved.
 * $Id: assoc.m,v 1.3 2020/04/16 19:16:07 stes Exp $
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
#include "assoc.h"

@implementation Assoc

/*****************************************************************************
 *
 * Creation
 *
 ****************************************************************************/

- key:aKey value:aValue
{
  key = aKey;
  value = aValue;
  return self;
}

+ key:aKey
{
  return [self key:aKey value:nil];
}

+ key:aKey value:aValue
{
  id newObj = [super new];
  [newObj key:aKey value:aValue];
  return newObj;
}

/*****************************************************************************
 *
 * Interrogation
 *
 ****************************************************************************/

- key
{
  return key;
}

- (STR) str
{
  return [key str];
}

- value
{
  return value;
}

- free
{
  /* Stepstone -free does NOT free key/value */
  return [super free];
}

- freeAll
{
  key = [key free];
  value = [value free];
  return [super free];
}

- release
{
#ifdef OBJC_REFCNT
  key = nil;
  value = nil;
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

- (unsigned) hash
{
  return [key hash];
}

- self
{
  /* trick to make associationAt: work without tmp object */
  return key;
}

- (BOOL) isEqual:anAssoc
{
  /* anAssoc can be either a Key or an Assoc */
  return (self == anAssoc) ? YES : [key isEqual:[anAssoc self]];
}

- (int) compare:anAssoc
{
  return [key compare:[anAssoc self]];
}

/*****************************************************************************
 *
 * Assignment
 *
 ****************************************************************************/

- value:aValue
{
  id tmp = value;
  value = aValue;
  return tmp;
}

/*****************************************************************************
 *
 * Printing
 *
 ****************************************************************************/

- printOn:(IOD)aFile
{
  [key printOn:aFile];
  fprintf (aFile, "\t");
  [value printOn:aFile];
  return self;
}

@end
 
