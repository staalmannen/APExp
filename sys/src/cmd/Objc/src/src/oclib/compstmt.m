
/*
 * Copyright (c) 1998,99 David Stes.
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
 * $Id: compstmt.m,v 1.3 2003/09/29 16:52:05 stes Exp $
 */

#include "config.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include <stdio.h> /* FILE */
#include "Object.h" /* Stepstone Object.h assumes #import */
#endif
#include <ocstring.h>
#include <ordcltn.h>
#include <set.h>
#include <dictnary.h>
#include "node.h"
#include "decl.h"
#include "symbol.h"
#include "expr.h"
#include "identxpr.h"
#include "stmt.h"
#include "compstmt.h"
#include "def.h"
#include "datadef.h"
#include "classdef.h"
#include "trlunit.h"
#include "type.h"
#include "util.h"
#include "options.h"
#include "stkframe.h"
#include "casestmt.h"

id curcompound;
id curloopcompound;

@implementation CompoundStmt

- (BOOL)isbracedgroup
{
  return bracedgroup;
}

- setbracedgroup:(BOOL)flag
{
  bracedgroup = flag;
  return self;
}

- setreturnflag
{
  if (checkreturnflag) {
    return self;
  } else {
    if (enclosing) {
      checkreturnflag++;
      [enclosing setreturnflag];
    } else {
      needreturnflag++;
    }
  }
  return self;
}

- usereturnflag
{
  if (enclosing) {
    checkreturnflag++;
    [enclosing setreturnflag];
  } else {
    needreturnflag++;
  }
  return self;
}

- (BOOL)iscompstmt
{
  return YES;
}

- (int)lineno
{
  if (lbrace) return [lbrace lineno];
  return 0;
}

- filename
{
  if (lbrace) return [lbrace filename];
  return nil;
}

- lbrace:lb
{
  lbrace = lb;
  return self;
}

- rbrace:rb
{
  rbrace = rb;
  return self;
}

- datadefs:defs
{
  datadefs = defs;
  return self;
}

- stmts:stmtlist
{
  stmts = stmtlist;
  return self;
}

- subblock:sub
{
  subblock = sub;
  return self;
}

- nextreturnlabel
{
  if (returnlabel) {
    return returnlabel;
  } else {
    if (enclosing) {
      if (decrefs || heapvars) {
	return [self returnlabel];
      } else {
        return [enclosing nextreturnlabel];
      }
    } else {
      /* always need a toplevel returnlabel */
      return [self returnlabel];
    }
  }
}

- returnlabel
{
  assert(o_refcnt);

  if (!returnlabel) {
    if (bracedgroup) {
      fatal("-refcnt doesn't work inside GNU ({...}) braced groups");
    } else {
      returnlabel = [trlunit returnlabel];
    }
  }

  return returnlabel;
}

- lookupparm:sym
{
  return nil;			/* no parms for compound (unlike BlockExpr) */
}

- synth
{
  int i, n;

  enclosing = curcompound;
  curcompound = self;
  if (!enclosing) {
    restype = [curdef restype];
    parmnames = [curdef parmnames];
    if (o_refcnt) {
      for (i = 0, n = [parmnames size]; i < n; i++) {
	id x = [parmnames at:i];

	if ([[curdef lookupparm:x] isid]) {
	  [self addincref:x];
	  [self adddecref:x];
	}
      }
    }
  }
  if (datadefs)
    [datadefs elementsPerform:_cmd];
  if (stmts)
    [stmts elementsPerform:_cmd];
  if (heapvars)
    [self removeheapvarsfromdatadefs];
  if (o_refcnt)
    for (i = 0, n = [locals size]; i < n; i++) {
      id x = [locals at:i];

      if ([[self lookuplocal:x] isid] && ![self isheapvar:x]) {
	[self adddecref:x];	/* works since all locals are nil'ed */
      }
    }
  curcompound = enclosing;
  return self;
}

- gen
{
  if (lbrace)
    [lbrace gen];
  else
    gc('{');
  if (heapvars || tmpvars || icaches || (o_refcnt && enclosing == nil))
    gc('\n');
  if (needreturnflag) gs("int _returnflag = 0;\n");
  if (o_refcnt && enclosing == nil && ![restype isvoid]) {
    [restype gendef:s_returnval];
    if ([restype isscalartype]) {
      /* this initializer isn't really needed, but suppresses -Wall warning */
      gs("=(");
      [restype genabstrtype];
      gs(")0");
    }
    gs(";\n");
  }
  if (heapvars)
    [self genheapvarptr];
  if (tmpvars)
    gvarlist(tmpvars, "id", (o_refcnt) ? "=(id)0" : "");
  if (icaches)
    gvarlist(icaches, "static struct objcrt_inlineCache", "");
  if (datadefs)
    [datadefs elementsPerform:_cmd];
  if (increfs)
    [self genincrefs];
  if (initializers)
    [initializers elementsPerform:_cmd];
  if (stmts)
    [stmts elementsPerform:_cmd];
  if (subblock)
    [subblock gen];
  if (returnlabel) {
    gc('\n');
    gs([returnlabel str]);
    gs(":\n");
  }
  if (heapvars) {
    [self freeheapvarptr];
  }
  if (o_refcnt) {
    if (decrefs)
      [self gendecrefs];
    if (checkreturnflag) {
      gf("if (_returnflag) goto %s;\n", [[enclosing nextreturnlabel] str]);
    }
    if (enclosing == nil) {
      if ([restype isvoid]) {
	gs("return;\n");
      } else {
	gs("return _returnval;");
      }
    }
  }
  if (rbrace)
    [rbrace gen];
  else
    gc('}');
  return self;
}

#include "shared.m"

- addheapvarblock:c
{
  if (c == self) {
    return self;
  } else {
    if (enclosing)
      [enclosing addheapvarblock:c];
    return self;
  }
}

- st80
{
  gc('|');
  if (datadefs)
    [datadefs elementsPerform:_cmd];
  gc('|');
  gc('\n');
  if (datadefs)
    [datadefs elementsPerform:@selector(st80inits)];
  [stmts elementsPerform:_cmd];
  return self;
}

@end
 
