
/*
 * Portable Object Compiler (c) 1997,98.  All Rights Reserved.
 * $Id: dictnary.m,v 1.5 2020/04/16 19:16:07 stes Exp $
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
#include "dictnary.h"
#include "assoc.h"
#include "keyseq.h"
#include "valueseq.h"
#include "notfound.h"
#include "ocstring.h"
#include "sequence.h"
#include "set.h"

@implementation Dictionary

/*****************************************************************************
 *
 * Creation
 *
 ****************************************************************************/


static void 
setUp (id * associations)
{
  *associations = [Set new];
}

+ new
{
  id newObject = [super new];
  setUp ([newObject associationsRef]);
  return newObject;
}

- copyAssociations
{
  associations = [associations copy];
  return self;
}

- copy
{
  return [[super copy] copyAssociations];
}

- deepCopyAssociations
{
  associations = [associations deepCopy];
  return self;
}

- deepCopy
{
  /* not all Object implementations have |deepCopy| */
  /* so we send |copy| to super instead             */

  return [[super copy] deepCopyAssociations];
}

- emptyYourself
{
  [associations freeContents];
  return self;
}

- freeContents
{
  [associations freeContents];
  return self;
}

- freeAll
{
  [associations freeAll];
  return self;
}

- free
{
  associations = [associations free];
  return [super free];
}

- release
{
#ifdef OBJC_REFCNT
  associations = nil;
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


- associations
{
  return associations;
}

- (id *) associationsRef
{
  return &associations;
}

- (unsigned) size
{
  return [associations size];
}

- (BOOL) isEmpty
{
  return [associations isEmpty];
}

- (BOOL) includesKey:aKey
{
  return (BOOL) ([self associationAt:aKey] != nil);
}

/*****************************************************************************
 *
 * Comparing
 *
 ****************************************************************************/


- (unsigned) hash
{
  return [associations hash];
}

- (BOOL) isEqual:aDic
{
  if (self == aDic)
    return YES;
  return [associations isEqual:[aDic associations]];
}

/*****************************************************************************
 *
 * Indexed Access
 *
 ****************************************************************************/


- associationAt:aKey
{
  /* not obvious that this works : see Assoc -isEqual: impl */
  return [associations find:aKey];
}

- atKey:aKey
{
  id association = [self associationAt:aKey];
  return (association) ? [association value] : nil;
}

- atKey:aKey ifAbsent:exceptionBlock
{
  id association = [self associationAt:aKey];
  return (association) ? [association value] : [exceptionBlock value];
}

- atKeySTR:(STR)strKey
{
  return [self atKey:[String str:strKey]];
}

- atKey:aKey put:anObject
{
  return [[associations filter:[Association key:aKey]] value:anObject];
}

- atKeySTR:(STR)strKey put:anObject
{
  return [self atKey:[String str:strKey] put:anObject];
}

- eachKey
{
  id aCarrier = [KeySequence over:[associations eachElement]];
  return [Sequence over:aCarrier];
}
- eachValue
{
  id aCarrier = [ValueSequence over:[associations eachElement]];
  return [Sequence over:aCarrier];
}
/*****************************************************************************
 *
 * Adding and Removing Keys
 *
 ****************************************************************************/


- removeKey:key
{
  id assoc, v;
  if ((assoc = [[self associations] remove:key]))
    {
      v = [assoc value];
#ifndef OBJC_REFCNT
      assoc = [assoc free];
#endif
      return v;
    }
  else
    {
      [NotFound signal];
      return nil;
    }
}

- removeKey:key ifAbsent:aBlock
{
  id assoc, v;
  if ((assoc = [[self associations] remove:key]))
    {
      v = [assoc value];
#ifndef OBJC_REFCNT
      assoc = [assoc free];
#endif
      return v;
    }
  else
    {
      return [aBlock value];
    }
}

/*****************************************************************************
 *
 * Blocks
 *
 ****************************************************************************/


#if OBJC_BLOCKS
- keysDo:aBlock
{
  id aKey;
  id keys = [self eachKey];

  while ((aKey = [keys next]))
    [aBlock value:aKey];
#ifndef OBJC_REFCNT
  keys = [keys free];
#endif

  return self;
}
#endif /* OBJC_BLOCKS */

/*****************************************************************************
 *
 * Printing
 *
 ****************************************************************************/

- printOn:(IOD)aFile
{
  [associations printOn:aFile];
  return self;
}

@end
 
