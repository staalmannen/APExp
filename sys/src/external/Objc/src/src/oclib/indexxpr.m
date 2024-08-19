
/*
 * Copyright (c) 1998,2000 David Stes.
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
 * $Id: indexxpr.m,v 1.1.1.1 2000/06/07 21:09:25 stes Exp $
 */

#include "config.h"
#include <stdlib.h>
#include <assert.h>
#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include <stdio.h> /* FILE */
#include "Object.h" /* Stepstone Object.h assumes #import */
#endif
#include "node.h"
#include "expr.h"
#include "indexxpr.h"
#include "type.h"
#include "var.h"
#include "aryvar.h"
#include "scalar.h"

@implementation IndexExpr

- lhs:e  {
  lhs = e;
  return self;
}
- rhs:e  {
  rhs = e;
  return self;
}

- (int)lineno
{
  return [lhs lineno];
}

- filename
{
  return [lhs filename];
}

- synth
{
  [lhs synth];
  [rhs synth];
  return self;
}

- typesynth
{
  type = [[lhs type] star];
  return self;
}

- gen
{
  [lhs gen];
  gc('[');
  [rhs gen];
  gc(']');
  return self;
}

- go
{
  id a = [lhs go];
  id b = [rhs go];

  if ([a isKindOf:(id)[ArrayVariable class]]) {
    int i = [b u_int];
    return [a at:i];
  } else {
    int i = [b u_int];
    if ([a type] == t_str) {
      STR s = [a u_str];
      return [[Scalar new] u_char:s[i]];
    }
    return [self notImplemented];
  }
}

- assignvar:v
{
  id a = [lhs go];
  id b = [rhs go];

  if ([a isKindOf:(id)[ArrayVariable class]]) {
    int i = [b u_int];
    [a at:i put:v];
    return v;
  } else {
    int i = [b u_int];
    if ([a type] == t_str) {
      STR s = [a u_str];
      s[i] = [v u_char];
      return v;
    }
    return [self notImplemented];
  }
}

@end
 
