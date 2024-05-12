
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
 * $Id: binxpr.m,v 1.1.1.1 2000/06/07 21:09:25 stes Exp $
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
#include "type.h"
#include "var.h"
#include "scalar.h"

@implementation BinaryExpr

- rhs:aRcvr
{
  rhs = aRcvr;
  return self;
}

- op:(STR)anop
{
  op = anop;
  return self;
}

- lhs:aRcvr
{
  lhs = aRcvr;
  return self;
}

- (BOOL)isconstexpr
{
  return [lhs isconstexpr] && [rhs isconstexpr];
}

- (int)lineno
{
  return [lhs lineno];
}

- filename
{
  return [lhs filename];
}

- typesynth
{
  type = [[lhs type] max:[rhs type]];
  return self;
}

- synth
{
  [lhs synth];
  [rhs synth];
  return self;
}

- gen
{
  [lhs gen];
  gs(op);
  [rhs gen];
  return self;
}

- st80
{
  [lhs st80];
  gs(op);
  [rhs st80];
  return self;
}

- go
{
  id a,b,r;
  int s = 0;
  a = [lhs go];
  b = [rhs go];
  r = [Scalar new];
  if (strcmp(op,"*") == 0) s = [a u_int] * [b u_int];
  else if (strcmp(op,"/") == 0) s = [a u_int] / [b u_int];
  else if (strcmp(op,"%") == 0) s = [a u_int] % [b u_int];
  else if (strcmp(op,"+") == 0) s = [a u_int] + [b u_int];
  else if (strcmp(op,"-") == 0) s = [a u_int] - [b u_int];
  else if (strcmp(op,"|") == 0) s = [a u_int] | [b u_int];
  else if (strcmp(op,"||") == 0) s = [a u_int] || [b u_int];
  else if (strcmp(op,"&") == 0) s = [a u_int] || [b u_int];
  else if (strcmp(op,"&&") == 0) s = [a u_int] || [b u_int];
  else if (strcmp(op,"^") == 0) s = [a u_int] ^ [b u_int];
  else [self notImplemented:_cmd];
  return [r u_int:s];
}

@end
 
