
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
 * $Id: relxpr.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
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
#include "binxpr.h"
#include "relxpr.h"
#include "type.h"
#include "var.h"
#include "scalar.h"

@implementation RelationExpr

- typesynth
{
  type = t_int;
  return self;
}

- go
{
  id a,b,r;
  int s = 0;
  int av,bv;
  a = [lhs go];
  b = [rhs go];
  r = [Scalar new];
  if ([a isKindOf:(id)[Scalar class]]) {
    av = [a u_int];
  } else {
    av = (a)?1:0;
  }
  if ([b isKindOf:(id)[Scalar class]]) {
    bv = [b u_int];
  } else {
    bv = (b)?1:0;
  }
  if (strcmp(op,"<")  == 0) s = av < bv;
  else if (strcmp(op,">")  == 0) s = av > bv;
  else if (strcmp(op,"==") == 0) s = av == bv;
  else if (strcmp(op,"!=") == 0) s = av != bv;
  else if (strcmp(op,">=") == 0) s = av >= bv;
  else if (strcmp(op,"<=") == 0) s = av <= bv;
  else [self notImplemented:_cmd];
  return [r u_int:s];
}

@end
 
