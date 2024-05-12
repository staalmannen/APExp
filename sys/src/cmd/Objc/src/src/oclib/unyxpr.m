
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
 * $Id: unyxpr.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
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
#include "type.h"
#include "var.h"
#include "scalar.h"

@implementation UnaryExpr

- op:(STR)anop
{
  op = anop;
  return self;
}

- expr:aRcvr
{
  expr = aRcvr;
  return self;
}

- (int)lineno
{
  return [expr lineno];
}

- filename
{
  return [expr filename];
}

- typesynth
{
  type = [expr type];
  return self;
}

- synth
{
  [expr synth];
  return self;
}

- gen
{
  gc(' ');			/* a+ +b -> a+(+b) not a++  b */
  gs(op);
  [expr gen];
  return self;
}

- (BOOL)isconstexpr
{
  return [expr isconstexpr];
}

- st80
{
  gc('(');
  gs(op);
  [expr st80];
  gc(')');
  return self;
}

- go
{
  id a,r;
  int s = 0;
  a = [expr go];
  if ([a isKindOf:(id)[Scalar class]]) {
    s = [a u_int];
  } else {
    s = (a)?1:0;
  }
  r = [Scalar new];
  if (strcmp(op,"-") == 0) s = -s;
  else if (strcmp(op,"+") == 0) s = +s;
  else if (strcmp(op,"!") == 0) s = !s;
  else [self notImplemented:_cmd];
  return [r u_int:s];
}

@end
 
