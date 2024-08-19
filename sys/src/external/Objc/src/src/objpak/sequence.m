
/*
 * Portable Object Compiler (c) 1997,98.  All Rights Reserved.
 * $Id: sequence.m,v 1.3 2020/04/16 19:16:08 stes Exp $
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
#include "sequence.h"
#if OBJC_BLOCKS
#include "Block.h"
#endif

@implementation Sequence
/*****************************************************************************
 *
 * Creation
 *
 ****************************************************************************/

- setUpCarrier:aCarrier
{
  carrier = aCarrier;
  return self;
}

+ over:aCarrier
{
  id newObj = [super new];
  [newObj setUpCarrier:aCarrier];
  return newObj;
}

- over:aCarrier
{
  return [self notImplemented:_cmd];
}

- copy
{
  return [isa over:[carrier copy]];
}

- free
{
  carrier = [carrier free];
  return [super free];
}

- release
{
#ifdef OBJC_REFCNT
  carrier = nil;
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

- (unsigned) size
{
  return [carrier size];
}

/*****************************************************************************
 *
 * Accessing
 *
 ****************************************************************************/

- next
{
  return [carrier next];
}

- peek
{
  return [carrier peek];
}

- previous
{
  return [carrier previous];
}

- first
{
  return [carrier first];
}

- last
{
  return [carrier last];
}

/*****************************************************************************
 *
 * Printing
 *
 ****************************************************************************/

- printOn:(IOD)aFile
{
  id aMember;
  while ((aMember = [self next]))
    {
      [aMember printOn:aFile];
      fprintf (aFile, "\n");
    }
  return self;
}

/*****************************************************************************
 *
 * Performing
 *
 ****************************************************************************/

#if OBJC_BLOCKS
- do:aBlock
{
  id aMember;
  while ((aMember = [self next]))
    [aBlock value:aMember];
  return self;
}
#endif /* OBJC_BLOCKS */


@end
 
