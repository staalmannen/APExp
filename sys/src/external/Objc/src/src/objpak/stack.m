
/*
 * Portable Object Compiler (c) 1998.  All Rights Reserved.
 * $Id: stack.m,v 1.2 2020/04/16 19:16:08 stes Exp $
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
#include "stack.h"
#include "set.h"
#include "ordcltn.h"
#include "ascfiler.h"
#if OBJC_BLOCKS
#include "Block.h"
#endif

#define DEFAULT_CAPACITY (16)

@implementation Stack

/*****************************************************************************
 *
 * Creation
 *
 ****************************************************************************/

+ new
{
  return [self new:DEFAULT_CAPACITY];
}

- contents:anObject
{
  contents = anObject;
  return self;
}

- contents
{
  return contents;
}

+ new:(unsigned)n
{
  return [[super new] contents:[OrdCltn new:n]];
}

- copy
{
  id aCopy = [super copy];
  contents = [contents copy];
  return aCopy;
}

- deepCopy
{
  /* not all Object implementations have |deepCopy| */
  /* so we send |copy| to super instead             */

  id aCopy = [super copy];
  contents = [contents deepCopy];
  return aCopy;
}

- emptyYourself
{
  [contents emptyYourself];
  return self;
}

- freeContents
{
  [contents freeContents];
  return self;
}

- free
{
  contents = [contents free];
  return [super free];
}

/*****************************************************************************
 *
 * Interrogation
 *
 ****************************************************************************/

- (unsigned) size
{
  return [contents size];
}

- (unsigned) depth
{
  return [contents size];
}

- (BOOL) isEmpty
{
  return [contents isEmpty];
}

- eachElement
{
  return [contents eachElement];
}

- topElement
{
  return [contents lastElement];
}

/*****************************************************************************
 *
 * Adding
 *
 ****************************************************************************/

- push:anObject
{
  [contents add:anObject];
  return self;
}

- add:anObject
{
  [contents add:anObject];
  return self;
}

- pop
{
  return [contents removeLast];
}

- swap
{
  unsigned n = [contents size];

  if (n >= 2)
    {
      id anObject = [contents at:n - 1];
      [contents at:n - 1 put:[contents at:n - 2]];
      [contents at:n - 2 put:anObject];
      return self;
    }
  else
    {
      return [self notImplemented:_cmd];
    }
}

- at:(unsigned )anOffset
{
  unsigned n = [contents size];
  if (anOffset >= n)
    {
      return [self notImplemented:_cmd];
    }
  else
    {
      return [contents at:n - 1 - anOffset];
    }
}

- removeAt:(unsigned )anOffset
{
  unsigned n = [contents size];
  if (anOffset >= n)
    {
      return [self notImplemented:_cmd];
    }
  else
    {
      return [contents removeAt:n - 1 - anOffset];
    }
}

/*****************************************************************************
 *
 * Printing
 *
 ****************************************************************************/

- printOn:(IOD)aFile
{
  [[[self eachElement] printOn:aFile] free];
  return self;
}

@end
 
