
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
 * $Id: deref.m,v 1.2 2014/03/04 09:03:32 stes Exp $
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
#include "unyxpr.h"
#include "deref.h"
#include "type.h"
#include "var.h"
#include "scalar.h"
#include "aryvar.h"

@implementation Dereference

+ new
{
  return [[super new] op:"*"];
}

- typesynth
{
  type = [[expr type] star];
  return self;
}

- go
{
  id x = [expr go];

  if ([x isKindOf:(id)[ArrayVariable class]]) {
    return [x at:0];
  } else {
    if ([x type] == t_str) {
      STR s = [x u_str];
      return [[Scalar new] u_char:*s];
    }
    return [self notImplemented];
  }
}

- assignvar:v
{
  id x = [expr go];

  if ([x isKindOf:(id)[ArrayVariable class]]) {
    [x at:0 put:v];
    return v;
  } else {
    if ([x type] == t_str) {
      STR s = [x u_str];
      *s = [v u_char];
      return v;
    }
    return [self notImplemented];
  }
}

@end
 
