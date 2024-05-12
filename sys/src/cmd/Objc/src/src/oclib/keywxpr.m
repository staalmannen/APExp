
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
 * $Id: keywxpr.m,v 1.1.1.1 2000/06/07 21:09:25 stes Exp $
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
#include "decl.h"
#include "keywdecl.h"
#include "expr.h"
#include "keywxpr.h"
#include "commaxpr.h"
#include "constxpr.h"
#include "selector.h"
#include "options.h"
#include "type.h"

@implementation KeywExpr

- keyw
{
  return keyw;
}

- keyw:sel
{
  keyw = sel;
  return self;
}

- arg:a
{
  expr = a;
  return self;
}

- (unsigned)typehash
{
  return [t_id hash];
}

- (BOOL)typeEqual:x
{
  return YES;
}

- selcons:sel
{
  if (keyw)
    [sel add:keyw];
  [sel addcol];
  return self;
}

- cvtcommalist
{
  id e;

  /* compensate here for the fact that the argument of a vararg method */
  /* has been parsed as a left associative CommaExpr: a,b,c -> (a,b),c */

  exprlist = [OrdCltn new];

  for (e = expr; [e isKindOf:(id) [CommaExpr class]]; e = [e lhs]) {
    [exprlist addFirst:[e rhs]];
  }
  expr = nil;
  [exprlist addFirst:e];
  if (o_debuginfo)
    fprintf(stderr, "message with %d varargs\n", [exprlist size]);
  return self;
}

- warnforwithmethod
{
  int n;

  assert(exprlist);
  if ((n = [exprlist size])) {
    id e = [exprlist at:0];

    if ([e isKindOf:(id) [ConstantExpr class]]) {
      int m = [e asInt];

      /* e.g. n == 3 for [OrdCltn with:2,a,b] */
      if (m != 0 && n != m + 1) {
	warn("argument count '%d' followed by %d arguments", m, n - 1);
      }
    }
  }
  return self;
}

- synth
{
  if (expr)
    [expr synth];
  if (exprlist)
    [exprlist elementsPerform:_cmd];
  return self;
}

- genarg
{
  if (expr)
    [expr gen];
  if (exprlist)
    gcommalist(exprlist);	/* varargs method */
  return self;
}

/* for messages where the method is not prototyped */

- (BOOL)isselptr
{
  return YES;			/* assume 'id' */
}

- (BOOL)canforward
{
  return YES;			/* assume 'id' */
}

- st80
{
  if (keyw)
    [keyw st80];
  gc(':');
  if (expr)
    [expr st80];
  if (exprlist)
    [exprlist elementsPerform:_cmd];
  return self;
}

- go
{
  if (exprlist) [self notImplemented:_cmd];
  return [expr go];
}

@end
 
