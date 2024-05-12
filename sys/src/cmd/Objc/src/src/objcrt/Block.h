
/*
 * Portable Object Compiler (c) 1997,2020.  All Rights Reserved.
 * $Id: Block.h,v 1.8 2020/05/10 11:48:44 stes Exp $
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

#ifndef __BLOCK_H__
#define __BLOCK_H__

#ifdef __PORTABLE_OBJC__

#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include "Object.h"		/* Stepstone Object.h assumes #import */
#endif

#ifndef EXPORT
#define EXPORT			/* empty */
#endif

#include "config.h"		/* because Object.h can be from another runtime */
#include "objcrt.h"
#include <stdio.h>		/* because Object.h can be from another runtime */

/* allows"manual" construction of Blocks, ie. without compiler support */
extern id EXPORT newBlock (int n, IMP fn, void *data, IMP dtor);

@interface Block : Object
{
  IMP fn;			/* it's not _really_ an IMP, it's just a func pointer */
  IMP dtor;			/* idem */
  int nVars;
  void **data;
  id nextBlock;
}

- blkc:(int)n blkfn:(IMP)f blkv:(void**)d blkdtor:(IMP)c;
+ new;
- copy;
- deepCopy;
+ blkc:(int)n blkfn:(IMP)f blkv:(void**)d blkdtor:(IMP)c;
- free;
- release;

+ errorHandler;
+ errorHandler:aHandler;
+ halt:message value:receiver;
- ifError:aHandler;
- value:anObject ifError:aHandler;
- push:aBlock;
- pop;
- on:aClassOfExceptions do:aHandler;
- value:anObject on:aClassOfExceptions do:aHandler;

- errorNumArgs;
- errorGoodHandler;
- value;
- (int) intvalue;
- atExit;
- value:anObject;
- (int) intvalue:anObject;
- value:firstObject value:secondObject;
- (int) intvalue:firstObject value:secondObject;

- repeatTimes:(int)n;
- shouldNotImplement;
- printOn:(IOD)anIod;
@end

#endif /* __PORTABLE_OBJC__ */

#endif /* __BLOCK_H__ */
 
