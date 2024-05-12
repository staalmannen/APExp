
/*
 * Copyright (c) 1998,1999,2000,2015 David Stes.
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
 * $Id: datadef.m,v 1.2 2015/10/24 13:32:07 stes Exp $
 */

#include "config.h"
#include <stdlib.h>
#include <assert.h>
#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include <stdio.h> /* FILE */
#include "Object.h" /* Stepstone Object.h assumes #import */
#endif
#include <ocstring.h>
#include <ordcltn.h>
#include "node.h"
#include "def.h"
#include "datadef.h"
#include "globdef.h"
#include "expr.h"
#include "decl.h"
#include "initdecl.h"
#include "symbol.h"
#include "stclass.h"
#include "trlunit.h"
#include "type.h"
#include "options.h"
#include "stmt.h"
#include "compstmt.h"
#include "util.h"
#include "stkframe.h"

@implementation DataDef 

- specs
{
  return specs;
}

- decllist
{
  return decllist;
}

- specs:aSpec
{
  specs = aSpec;
  return self;
}

- add:aDecl 
{
  if (!decllist) {
    decllist = [OrdCltn new];
  }
  [decllist add:aDecl];
  return self;
}

- synthattrs
{
  int i, n;

  for (i = 0, n = [specs size]; i < n; i++) {
    id s = [specs at:i];

    if ([s isstorageclass]) {
      if ([s istypedef])
	istypedef++;
      else if ([s isstatic])
	isstatic++;
      else if ([s isinline])
	isinline++;
      else if ([s isextern])
	isextern++;
    }
  }
  return self;
}

- (BOOL)isfundef
{
  return NO;
}

- (BOOL)iskandr
{
  return iskandr;
}

- iskandr:(BOOL)flag
{
  iskandr = flag;
  return self;
}

- (BOOL)istypedef
{
  return istypedef;
}

- (BOOL)isextern
{
  return isextern;
}

- (BOOL)isstatic
{
  return isstatic;
}

- (BOOL)isinline
{
  return isinline;
}

- (BOOL)definesocu
{
  /* Linux Debian headers contain 'inline' fun impls */
  return !isstatic && !isextern && !isinline;
}

- synth
{
  int i, n;
  id gdef = nil;

  unit = trlunit;

  if (specs)
    [specs elementsPerform:_cmd];
  [self synthattrs];

  for (i = 0, n = [decllist size]; i < n; i++) {
    id var = [[decllist at:i] identifier];

    if (var) {
      id t = [Type new];
      id d = [decllist at:i];

      if (specs) {
	[t specs:specs];	/* type filters out storage class */
	[t decl:d];		/* type makes a -abstrdecl of it */
      } else {
	[t addspec:s_int];	/* C default */
	[t decl:d];
      }
      [t isstatic:isstatic];
      [t isextern:isextern];
      if ([d islistinit])
	[t haslistinit:YES];
      if (istypedef) {
	if (curdef) {
	  warn("typedef not allowed inside function or method definition");
	} else {
	  [trlunit def:var astype:t];
	}
      } else {
	if (curdef) {
	  if (curcompound) {
	    [curcompound deflocal:var astype:t];
	  } else {
	    [curdef defparm:var astype:t];
	  }
	} else {
	  [trlunit defdata:var astype:t];
	  if (![d isfunproto] && !isextern) {
            gdef = [GlobDef new];
	    [trlunit def:var as:gdef];
          }
	  if (!o_postlink && [self definesocu] && ![d isfunproto]) {
	    [trlunit definesentry:var];
	  }
	}

	/* after defining the variable, process initializer if any */
	[d synthinits];

        if (gdef) {
          [gdef type:t];
          if ([d isinit]) [gdef initializer:[d initializer]];
        }

	/* for assignments to work in the refcnt case, locals must be nil'ed */
	if (o_refcnt && [t isid]) {
	  if ([d isinit]) {
	    if (![[d initializer] isconstexpr]) [d incref];
	  } else {
	    /* for extern and static, or K&R parms, don't add = (id)0 */
	    if (!isextern && !isstatic && !iskandr) {
	      d = [[[InitDecl new] decl:d] initnil];
	      [decllist at:i put:d];	/* make an init : id foo = nil */
	    }
	  }
	}
      }
    } else {
      fatal("missing name in data definition");
    }
  }

  return self;
}

- removevars:set initializers:cltn
{
  int n = [decllist size];

  while (n--) {
    id d, v;
    BOOL isheapvar;

    d = [decllist at:n];
    v = [d identifier];
    isheapvar = [set contains:v];
    if ([d isinit]) {
      if ([d islistinit]) {
	if (isheapvar || ![[d initializer] isconstexpr]) {
	  char *m = "list initializers not yet allowed in function with Blocks";

	  fatalat(v, m);
	}			/* if it is const and not for a heapvar, then doesnt need remove */
      } else {
	id x = [mkidentexpr(v) synth];
	/* Brian Martin: change add to addFirst */
	[cltn addFirst:mkexprstmt(mkassignexpr(x, "=", [d initializer]))];
	[decllist at:n put:[d decl]];	/* hence removing the initializer */
      }
    }
    if (isheapvar) {
      [decllist removeAt:n];	/* removing var alltogether */
    }
  }
  if (![decllist size])
    decllist = nil;
  return self;
}

- gen
{
  if (specs)
    [specs elementsPerform:@selector(gen)];
  if (decllist)
    gcommalist(decllist);
  gc(';');
  return self;
}

- st80
{
  if (decllist)
    [decllist elementsPerform:_cmd];
  return self;
}

- st80inits
{
  if (decllist)
    [decllist elementsPerform:_cmd];
  return self;
}

- go
{
  int i,n;

  for (i = 0, n = [decllist size]; i < n; i++) {
    id d,v;
    d = [decllist at:i];
    v = [d identifier];
    if ([d isinit]) {
      id e = [d initializer];
      [topframe defval:v as:[e go]];
    }
  }

  return self;
}

@end
 
