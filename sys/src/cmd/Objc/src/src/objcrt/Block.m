
/*
 * Portable Object Compiler (c) 1997,2020.  All Rights Reserved.
 * $Id: Block.m,v 1.10 2020/05/10 11:48:44 stes Exp $
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

#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include "Object.h"		/* Stepstone Object.h assumes #import */
#endif

#ifndef EXPORT
#define EXPORT			/* empty */
#endif

#include "Block.h"
#include "Exceptn.h"
#include <setjmp.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

@implementation Block

/*****************************************************************************
 *
 * Creating Blocks
 *
 ****************************************************************************/

/*
 * Compiler emits calls to newBlock() for creation of Blocks.
 */

id EXPORT newBlock (int n, IMP f, void *d, IMP c)
{
  return [Block blkc:n blkfn:f blkv:(void **) d blkdtor:c];
}

/*
 * Since objc-3.3.19 we do not print a message backtrace
 * code which was #ifdef'ed out anyway
 * Following function just prints the "msg" argument on stderr.
 */

static id 
err_fun (id thisBlock, void **data, id msg, id rcv)
{
  if (rcv)
    fprintf (stderr, "%s: ", [rcv name]);
  if (msg)
    [msg printOn:stderr];
  else
    fprintf (stderr, "(null message)");
  if (rcv != nil || msg != nil)
    fprintf (stderr, "\n");
  abort ();
#ifdef OBJCRT_RETURN_AFTER_ABORT
  return nil;
#endif
}

- blkc:(int)n blkfn:(IMP)f blkv:(void**)d blkdtor:(IMP)c
{
  nVars = n;
  fn = f;
  data = d;
  dtor = c;
  return self;
}

+ new
{
  return [self shouldNotImplement];
}

- copy
{
  return [self shouldNotImplement];
}

- deepCopy
{
  return [self shouldNotImplement];
}

+ blkc:(int)n blkfn:(IMP)f blkv:(void**)d blkdtor:(IMP)c
{
  return [[super new] blkc:n blkfn:f blkv:d blkdtor:c];
}

- free
{
  if (data)
    (*((void (*)(void **)) dtor)) (data);
  return [super free];
}

- release
{
  if (data)
    (*((void (*)(void **)) dtor)) (data);
  return [super release];
}

/*****************************************************************************
 *
 * Exception Handling
 *
 ****************************************************************************/

static id errorHandler;
static id defaultHandler;

+ errorHandler
{
  if (!defaultHandler)
    {
      defaultHandler = newBlock (2, (IMP) err_fun, NULL, NULL);
    }
  if (errorHandler)
    {
      return errorHandler;
    }
  else
    {
      return defaultHandler;
    }
}

+ errorHandler:aHandler
{
  id ret = defaultHandler;
  defaultHandler = [aHandler errorGoodHandler];
  return ret;
}

+ halt:message value:receiver
{
  id handler = [self errorHandler];
  if (errorHandler)
    {
      errorHandler = [errorHandler pop];	// sets errorHandler to "nextBlock"

    }
  return [handler value:message value:receiver];
}

- ifError:aHandler
{
  id returnValue;
  if (errorHandler)
    {
      errorHandler = [errorHandler push:[aHandler errorGoodHandler]];
    }
  else
    {
      errorHandler = [aHandler errorGoodHandler];
    }
  returnValue = [self value];
  errorHandler = [errorHandler pop];
  return returnValue;
}

- value:anObject ifError:aHandler
{
  id returnValue;
  if (errorHandler)
    {
      errorHandler = [errorHandler push:[aHandler errorGoodHandler]];
    }
  else
    {
      errorHandler = [aHandler errorGoodHandler];
    }
  returnValue = [self value:anObject];
  [aHandler pop];
  return returnValue;
}

- push:aBlock
{
  nextBlock = aBlock;
  return self;
}

- pop
{
  return nextBlock;
}

- on:aClassOfExceptions do:aHandler
{
  id returnValue;
  [aClassOfExceptions install:aHandler];
  returnValue = [self value];
  return returnValue;
}

- value:anObject on:aClassOfExceptions do:aHandler
{
  id returnValue;
  [aClassOfExceptions install:aHandler];
  returnValue = [self value:anObject];
  return returnValue;
}


/*****************************************************************************
 *
 * Evaluating Blocks
 *
 ****************************************************************************/

- errorNumArgs
{
  return [self error:"Block has wrong number of arguments."];
}

- errorGoodHandler
{
  return (nVars == 2) ? self : [self errorNumArgs];
}

- value
{
  return (nVars == 0) ? (id) (*fn) (self, data) : [self errorNumArgs];
}

- (int) intvalue
{
  if (nVars != 0)
    [self errorNumArgs];
  return (*((int (*)(id, void *)) fn)) (self, data);
}

#if 0
static int atExitCount = 0;
static id atExitBlocks [32];

static void 
valueAtExit (void)
{
  if (atExitCount)
    [atExitBlocks [--atExitCount] value];
}
#endif

- atExit
{
#if 1
  /* no atexit() on Sunos4.1.2 it seems? */
  return [self notImplemented];
#else
  if (nVars == 0)
    {
      atExitBlocks [atExitCount++] = self;
      atexit (valueAtExit);
      return self;
    }
  else
    {
      return [self errorNumArgs];
    }
#endif
}

- value:anObject
{
  return (nVars == 1) ? (id) (*fn) (self, data, anObject) : [self errorNumArgs];
}

- (int) intvalue:anObject
{
  if (nVars != 1)
    [self errorNumArgs];
  return (*((int (*)(id, void *, id)) fn)) (self, data, anObject);
}

- value:firstObject value:secondObject
{
  if (nVars == 2)
    {
      return (id) (*fn) (self, data, firstObject, secondObject);
    }
  else
    {
      return [self errorNumArgs];
    }
}

- (int) intvalue:firstObject value:secondObject
{
  if (nVars != 2)
    [self errorNumArgs];
  return (*((int (*)(id, void *, id, id)) fn)) (self, data, firstObject, secondObject);
}


/*****************************************************************************
 *
 * Control Flow 
 *
 ****************************************************************************/

- repeatTimes:(int)n
{
  int i;
  for (i = 0; i < n; i++)
    [self value];
  return self;
}

- shouldNotImplement
{
  /* this is just here to avoid a warning on GNU */
  /* when we use their Object, doesn't have this method */
  [self error:"Message is not approriate for this class."];
  return self;
}

- printOn:(IOD)anIod
{
  /* this is just here to avoid a warning on GNU */
  /* when we use their Object, doesn't have this method */
  return [self shouldNotImplement];
}

@end

#endif /* __PORTABLE_OBJC__ */
 
