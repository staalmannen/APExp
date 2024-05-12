
/*
 * Copyright (c) 1998 David Stes.
 *
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
 *
 * $Id: def.m,v 1.1.1.1 2000/06/07 21:09:25 stes Exp $
 */

#include "config.h"
#include <stdlib.h>
#include <assert.h>
#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include <stdio.h> /* FILE */
#include "Object.h" /* Stepstone Object.h assumes #import */
#endif
#include <ordcltn.h>
#include <set.h>
#include <dictnary.h>
#include "node.h"
#include "def.h"
#include "expr.h"
#include "blockxpr.h"
#include "classdef.h"

id curdef;

@implementation Def

- restype
{
  return [self subclassResponsibility:_cmd];
}

- compound
{
  return [self notImplemented:_cmd];
}

- parmnames
{
  return parmnames;
}

- defheapvar:x type:t
{
  if (!heapvars)
    heapvars = [Set new];
  [heapvars add:x];
  [[self compound] defheapvar:x type:t];
  return self;
}

- (BOOL)isfundef
{
  return NO;
}

- (BOOL)ismethdef
{
  return NO;
}

- synth
{
  return [self subclassResponsibility];
}

- defparm:sym astype:aType
{
  if (!parmdic) {
    parmdic = [Dictionary new];
    parmnames = [OrdCltn new];
  }
  [parmdic atKey:sym put:aType];
  [parmnames add:sym];
  return self;
}

- lookupparm:sym
{
  return (parmdic) ? [parmdic atKey : sym]:nil;
}

- addclassreference:x
{
  if (!classreferences)
    classreferences = [OrdCltn new];
  [classreferences add:x];
  return self;
}

- addblockreference:x
{
  if (!blockreferences)
    blockreferences = [OrdCltn new];
  [blockreferences add:x];
  return self;
}

- addheapvarblock:x
{
  if (!heapvarblocks)
    heapvarblocks = [Set new];	/* order doesn't matter */
  [heapvarblocks add:x];
  return self;
}

- gen
{
  gc('\n');
  if (classreferences) {
    [classreferences elementsPerform:@selector(genintf)];
  }
  if (heapvarblocks) {
    [heapvarblocks elementsPerform:@selector(genheapvartype)];
  }
  if (blockreferences) {
    int n = [blockreferences size];	/* work from end (deepest blk) to begin */

    while (n--)
      [[blockreferences at:n] genblockfun];
  }
  return self;
}

- reset
{
  return self;
}

@end
 
