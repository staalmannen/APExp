
/*
 * Portable Object Compiler (c) 1998,2003.  All Rights Reserved.
 * $Id: idarray.h,v 1.3 2009/10/23 19:36:43 stes Exp $
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

#ifndef __IDARRAY_H__
#define __IDARRAY_H__

#include "array.h"

typedef struct idary
  {
    int capacity;
    id *ptr;
  }
 *idary_t;

@interface IdArray : Array
{
  struct idary value;
}

+ new;
+ new:(unsigned)n;
+ with:(int)nArgs,...;
- copy;
- deepCopy;
- free;

- (unsigned) size;
- at:(unsigned)anOffset;
- at:(unsigned)anOffset put:anObject;

- (unsigned) capacity;
- capacity:(unsigned)nSlots;
- packContents;

- printOn:(IOD)aFile;

#ifdef __PORTABLE_OBJC__
- fileOutOn:aFiler;
- fileInFrom:aFiler;
#endif /* __PORTABLE_OBJC__ */

@end

#endif /* __IDARRAY_H__ */
 
