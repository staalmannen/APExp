
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
 * $Id: constxpr.m,v 1.1.1.1 2000/06/07 21:09:25 stes Exp $
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
#include <ocstring.h>
#include "node.h"
#include "symbol.h"
#include "expr.h"
#include "constxpr.h"
#include "type.h"
#include "var.h"
#include "scalar.h"

@implementation ConstantExpr

- (BOOL)isconstexpr
{
  return YES;
}

- identifier:aNode
{
  identifier = aNode;
  return self;
}

- stringchain:aList
{
  stringchain = aList;
  return self;
}

- identifier
{
  return identifier;
}

- stringchain
{
  return stringchain;
}

- (BOOL)isEqual:x
{
  assert(identifier);
  return [identifier isEqual:[x identifier]];
}

- (int)lineno
{
  if (identifier)
    return [identifier lineno];
  return [[stringchain at:0] lineno];
}

- filename
{
  if (identifier)
    return [identifier filename];
  return [[stringchain at:0] filename];
}

- (int)asInt
{
  return [identifier asInt];
}

- synth
{
  return self;
}

- typesynth
{
  if (identifier)
    type = [identifier type];
  if (stringchain)
    type = t_str;
  if (!type) type = t_unknown;
  return self;
}

- gen
{
  if (identifier)
    [identifier gen];
  if (stringchain)
    [stringchain elementsPerform:@selector(gen)];
  return self;
}

- concatstringchain
{
  int i,n;
  id s = [Symbol new];
  for(i=0,n=[stringchain size];i<n;i++) {
    id o = [stringchain at:i];
    [s concat:o];
  }
  return [s unescape];
}

- go
{
  id v = [Scalar new];
  if (!type) [self typesynth];
  if (identifier) {
     if ([type isEqual:t_char]) {
          id s = [Symbol str:[identifier str]];
          [s unescapeChar];
          [v u_char:*[s str]];
     }
     if ([type isEqual:t_int]) [v u_int:atoi([identifier str])];
     if ([type isEqual:t_double]) [v u_double:atof([identifier str])];
  }
  if (stringchain) {
     if (!strcontent) strcontent = [self concatstringchain];
     [v u_str:[strcontent strCopy]];
  }
  return v;
}

- st80
{
  if (identifier)
    [identifier st80];
  if (stringchain)
    [stringchain elementsPerform:_cmd];
  return self;
}

@end
 
