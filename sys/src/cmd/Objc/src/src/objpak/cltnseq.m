
/*
 * Portable Object Compiler (c) 1997,98.  All Rights Reserved.
 * $Id: cltnseq.m,v 1.3 2020/04/16 19:16:07 stes Exp $
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
#include "cltnseq.h"
#include "ordcltn.h"

@implementation CollectionSequence

- collection:aCol
{
  collection = aCol;
  offset = 0;
  return self;
}

+ over:aCol
{
  id newObj = [super new];
  [newObj collection:aCol];
  return newObj;
}

- copy
{
  return [super copy];
}

- free
{
  return [super free];
}

- release
{
#ifdef OBJC_REFCNT
  collection = nil;
  return [super release];
#else
  return [self notImplemented:_cmd];
#endif
}

- (unsigned) size
{
  return [collection size];
}

- next
{
  return (offset < [collection size]) ? [collection at : offset++]:nil;
}

- peek
{
  return (offset < [collection size]) ? [collection at : offset]:nil;
}

- previous
{
  assert (offset <= [collection size]);
  return (0 < offset) ? [collection at : offset - 1]:nil;
}

- first
{
  return [collection firstElement];
}

- last
{
  return [collection lastElement];
}

@end
 
