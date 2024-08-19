
/*
 * Copyright (c) 1998,2020 David Stes.
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
 * $Id: blockxpr.m,v 1.2 2020/04/16 19:16:12 stes Exp $
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
#include "symbol.h"
#include "node.h"
#include "decl.h"
#include "keywdecl.h"
#include "expr.h"
#include "identxpr.h"
#include "blockxpr.h"
#include "stmt.h"
#include "compstmt.h"
#include "type.h"
#include "options.h"
#include "def.h"
#include "classdef.h"
#include "datadef.h"
#include "trlunit.h"
#include "util.h"
#include "stkframe.h"
#include "casestmt.h"

@implementation BlockExpr

- usereturnflag
{
  return self;
}

- blockcount:(int)x
{
  blockcount = x;
  return self;
}

+ new
{
  [trlunit usingblocks:YES];
  return [[super new] blockcount:[trlunit blockcount]];
}

- (BOOL)isblockexpr
{
  return YES;
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

- defparm:sym astype:t
{
  if (!parmnames) {
    parmnames = [OrdCltn new];
  }
  [parmnames add:sym];
  assert([t isid]);
  return self;
}

- parms:aList
{
#if 1
  int i, n;

  parms = [OrdCltn new];
  for (i = 0, n = [aList size]; i < n; i++) {
    [parms add:[[KeywDecl new] arg:[aList at:i]]];
  }
  parmnames = aList;
#else
  parms = aList;
#endif
  return self;
}

- datadefs:aList
{
  datadefs = aList;
  return self;
}

- stmts:aList
{
  stmts = aList;
  return self;
}

- expr:anExpr
{
  expr = anExpr;
  return self;
}

- lookupparm:sym
{
  if (parmnames && [parmnames findMatching:sym])
    return t_id;
  return nil;
}

- nextreturnlabel
{
  return [self returnlabel];
}

- returnlabel
{
  assert(o_refcnt);
  returnlabel = [trlunit returnlabel];
  return returnlabel;
}

- (int)lineno
{
  return [lbrace lineno];
}

- filename
{
  return [lbrace filename];
}

- synth
{
  if (!o_blocks) {
    fatalat(lbrace, "blocks not allowed with -noBlocks");
    return self;
  }
  if (curdef) {
    [curdef addblockreference:self];
  } else {
    fatalat(lbrace, "block expression outside method or function definition");
  }
  enclosing = curcompound;
  curcompound = self;		/* BlockExpr responds to messages of CompoundStmt */
#if 0
  enclosingdef = curdef;
  curdef = self;		/* BlockExpr responds to messages of MethodDef (anon.meth.) */
  if (parms)
    [parms elementsPerform:_cmd];
  curdef = enclosingdef;
#endif
  if (datadefs)
    [datadefs elementsPerform:_cmd];
  if (stmts)
    [stmts elementsPerform:_cmd];
  if (expr)
    [expr synth];
  numparms = (parms) ? [parms size] : 0;
  blkconsname = [[String sprintf:"newblk%i", blockcount] strCopy];
  blkdtorname = [[String sprintf:"clearblk%i", blockcount] strCopy];
  blkfunname = [[String sprintf:"blkfun%i", blockcount] strCopy];
  blkdataname = [[String sprintf:"blkdata%i", blockcount] strCopy];
  blktypename = [[String sprintf:"struct blktype%i", blockcount] strCopy];
  restype = (expr) ? [expr type] : t_id;
  if (heapvars)
    [self removeheapvarsfromdatadefs];
  curcompound = enclosing;

  if (o_refcnt) {
    int i, n;

    refvar = [trlunit gettmpvar];
    [curcompound addtmpvar:refvar];
    [curcompound adddecref:refvar];
    for (i = 0, n = [parmnames size]; i < n; i++) {
      id x = [parmnames at:i];

      if ([[self lookupparm:x] isid] /* always true */ ) {
	[self addincref:x];
	[self adddecref:x];
      }
    }
    for (i = 0, n = [locals size]; i < n; i++) {
      id x = [locals at:i];

      if ([[self lookuplocal:x] isid] && ![self isheapvar:x]) {
	[self adddecref:x];	/* works since all locals are nil'ed */
      }
    }
  }
  return self;
}

- typesynth
{
  type = t_id;
  return self;
}

- genblocktype
{
  if (numheapvarblocks) {
    int i;

    gf("%s {\n", blktypename);
    for (i = 0; i < numheapvarblocks; i++) {
      id c = [heapvarblocks at:i];
      char *hvt = [c heapvartypename];
      char *hvp = [c heapvarptrname];

      gf("%s *%s;\n", hvt, hvp);
    }
    gs("};\n");
  }
  return self;
}

- packblockdata
{
  int i;

  for (i = 0; i < numheapvarblocks; i++) {
    id c = [heapvarblocks at:i];
    char *hvp = [c heapvarptrname];

    gf("%s->%s=%s;\n", blkdataname, hvp, hvp);
    gf("%s->heaprefcnt++;\n", hvp);
  }
  return self;
}

- unpackblockdata
{
  int i;

  for (i = 0; i < numheapvarblocks; i++) {
    id c = [heapvarblocks at:i];
    char *hvt = [c heapvartypename];
    char *hvp = [c heapvarptrname];

    gf("%s *%s=%s->%s;\n", hvt, hvp, blkdataname, hvp);
  }
  return self;
}

- genconstructor
{
  assert(blkconsname);
  gf("static id %s(", blkconsname);
  if (!numheapvarblocks) {
    gs("void");
  } else {
    int i;
    int comma = 0;

    for (i = 0; i < numheapvarblocks; i++) {
      id c = [heapvarblocks at:i];
      char *hvt = [c heapvartypename];
      char *hvp = [c heapvarptrname];

      if (comma)
	gc(',');
      else
	comma++;
      gf("%s *%s", hvt, hvp);
    }
  }
  gs(")\n");
  gs("{\n");
  if (numheapvarblocks) {
    /* this can be a Malloc but the heapvarptr's themselves must be Calloced */
    gf("%s *%s=OC_Malloc(sizeof(%s));\n", blktypename, blkdataname, blktypename);
  }
  if (numheapvarblocks)
    [self packblockdata];
  gf("return newBlock(%i,(IMP)%s,", numparms, blkfunname);
  if (!o_postlink) {
    [trlunit usesentry:s_newblock];
  }
  if (numheapvarblocks) {
    gf("%s,(IMP)%s);\n", blkdataname, blkdtorname);
  } else {
    gs("(void*)0,(IMP)0);\n");
  }
  gs("}\n");
  return self;
}

- gendestructor
{
  int i;
  assert(blkdtorname != NULL && numheapvarblocks > 0);
  gc('\n');
  gf("static void %s(%s *%s)\n",blkdtorname,blktypename,blkdataname);
  gs("{\n");
  [self unpackblockdata];
  for(i=0;i<numheapvarblocks;i++) {
      [[heapvarblocks at:i] freeheapvarptr];
  }
  gf("OC_Free(%s);\n",blkdataname);
  gs("}\n");
  return self;
}

- genblockfun
{
  [self genblocktype];
  gs("static");
  [restype gendef:nil];
  gs(blkfunname);
  gs("(id thisBlock,");
  if (numheapvarblocks) {
    gf("%s *%s", blktypename, blkdataname);
  } else {
    gf("void *%s", blkdataname);
  }
  if (parms)
    [parms elementsPerform:@selector(gencommaparm)];
  gs(")\n{\n");
  if (o_refcnt) {
    gs("int _returnflag = 0;\n");
    if (![restype isvoid]) {
      [restype gendef:s_returnval];
      if ([restype isscalartype]) { /* suppress -Wall warning */
	gs("=(");
	[restype genabstrtype];
	gs(")0");
      }
      gs(";\n");
    }
  }
  if (heapvars)
    [self genheapvarptr];
  if (numheapvarblocks)
    [self unpackblockdata];
  if (tmpvars)
    gvarlist(tmpvars, "id", (o_refcnt) ? "=(id)0" : "");
  if (icaches)
    gvarlist(icaches, "static struct objcrt_inlineCache", "");
  if (datadefs)
    [datadefs elementsPerform:@selector(gen)];
  if (increfs)
    [self genincrefs];
  if (initializers)
    [initializers elementsPerform:@selector(gen)];
  if (stmts)
    [stmts elementsPerform:@selector(gen)];
  if (returnlabel) {
    gc('\n');
    gs([returnlabel str]);
    gs(":\n");
  }
  if (o_refcnt) {
    gs("_returnflag++;\n");
    if (expr && ![restype isvoid]) {
      gs("_returnval=");
      [expr gen];
      gs(";\n");
      if ([restype isid])
	gs("idincref(_returnval);");
    }
    if (decrefs)
      [self gendecrefs];
  }
  if (heapvars) {
    [self freeheapvarptr];
  }
  if (expr) {
    if (o_refcnt) {
      if ([restype isvoid]) {
	gs("return;\n");
      } else {
	gs("return _returnval;");
      }
    } else {
      gs("return ");
      [expr gen];
      gs(";\n");
    }
  } else {
    if (o_refcnt) {
      gs("return idincref(thisBlock);\n");
    } else {
      gs("return thisBlock;\n");
    }
  }
  gs("}\n");

  if (numheapvarblocks) [self gendestructor];
  [self genconstructor];

  return self;
}

- addheapvarblock:c
{
  if (c == self) {
    return self;
  } else {
    if (!heapvarblocks)
      heapvarblocks = [OrdCltn new];
    [heapvarblocks addIfAbsent:c];
    numheapvarblocks = [heapvarblocks size];
    if (enclosing)
      [enclosing addheapvarblock:c];
    return self;
  }
}

- gen
{
  int i;
  int comma = 0;

  gl([self lineno],[[self filename] str]);
  if (refvar) {
    gc('(');
    gs([refvar str]);
    gc('=');
  }
  gf("%s(", blkconsname);
  for (i = 0; i < numheapvarblocks; i++) {
    if (comma)
      gc(',');
    else
      comma++;
    gs([[heapvarblocks at:i] heapvarptrname]);
  }
  gc(')');
  if (refvar) gc(')');
  return self;
}

#include "shared.m"

- st80
{
  gc('[');
  if (parms) {
    [parms elementsPerform:_cmd];
    gc('|');
  }
  gc('\n');
  gc('|');
  if (datadefs)
    [datadefs elementsPerform:_cmd];
  gc('|');
  gc('\n');
  if (datadefs)
    [datadefs elementsPerform:@selector(st80inits)];
  if (stmts)
    [stmts elementsPerform:_cmd];
  if (expr)
    [expr st80];
  gc(']');
  return self;
}

@end
 
