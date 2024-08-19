
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
 * $Id: fundef.m,v 1.2 2000/09/08 15:07:57 stes Exp $
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
#include "node.h"
#include "def.h"
#include "symbol.h"
#include "fundef.h"
#include "stmt.h"
#include "compstmt.h"
#include "trlunit.h"
#include "decl.h"
#include "type.h"
#include "options.h"
#include "stkframe.h"

@implementation FunctionDef

- compound
{
  return [body compound];
}

- (BOOL)isfundef
{
  return YES;
}

- (BOOL)isextern
{ 
  return isextern;
}

- (BOOL)isstatic
{ 
  return isstatic;
}

- datadefspecs:s
{
  datadefspecs = s;
  return self;
}

- decl:d
{
  decl = d;
  return self;
}

- body:b
{
  body = b;
  return self;
}

- synthattrs
{
  int i, n;
  
  unit = trlunit;

  for (i = 0, n = [datadefspecs size]; i < n; i++) {
    id s = [datadefspecs at:i];

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

- (BOOL)definesocu
{
  return !isstatic && !isinline;
}

- restype
{
  id x, v = [decl identifier];

  x = [trlunit lookupglobal:v];	/* as defined in declarefun() */
  assert([x isKindOf:(id) [Type class]]);
  return [x funcall];
}

- synth
{
  id v;

  curdef = self;
  curcompound = nil;
  /* definition of type is already done in declarefun() */
  /* we send a -synth again to 'decl' for getting name&type of ANSI parms */
  [decl synth];
  [self synthattrs];
  v = [decl identifier];
  [trlunit def:v as:self];
  if (istypedef)
    fatal("illegal storage class for %s", [v str]);
  if (!o_postlink && [self definesocu])
    [trlunit definesentry:v];
  [body synth];
  curdef = nil;
  return self;
}

- genmain
{
  if (o_initcall) {
    char *fmt;

    gc('\n');
    if (!o_shareddata) {
      gs("extern struct useDescriptor *OCU_main;\n");
      gs("extern struct modEntry *_objcModules;\n");
      if (o_cplus) {
	fmt = "extern \"C\" int %s(void *mods,void *desc);\n";
      } else {
	fmt = "extern int %s(void *mods,void *desc);\n";
      }
    } else {
      if (o_cplus) {
	fmt = "extern \"C\" int %s(int debug,int traceInit);\n";
      } else {
	fmt = "extern int %s(int debug,int traceInit);\n";
      }
    }
    gf(fmt, o_initcall);
  } else {
    fatal("no initialization call defined (use -init)");
  }

  if (o_filer) {
    gs((o_cplus) ? "extern \"C\"" : "extern");
    gs(" void *_OBJCBIND_ascfiler(void);\n");
    gs((o_cplus) ? "extern \"C\"" : "extern");
    gs(" void *_OBJCBIND_ocstring(void);\n");
    if (!o_postlink)
      [trlunit usesentry:[Symbol str:"AsciiFiler"]];
    if (!o_postlink)
      [trlunit usesentry:[Symbol str:"String"]];
  }
  if (datadefspecs)
    [datadefspecs elementsPerform:@selector(gen)];
  [decl gen];
  gs("{\n");

  if (o_filer) {
    gs("_OBJCBIND_ascfiler();\n");
    gs("_OBJCBIND_ocstring();\n");
  }
  if (!o_cache) {
    gs("noCacheFlag=1;\n");
  }
  if (!o_nilrcvr) {
    gs("noNilRcvr=1;\n");
  }
  if (!o_shareddata) {
    gf("%s(_objcModules,OCU_main);\n", o_initcall);
  } else {
    gf("%s(0,0);\n", o_initcall);
  }

  if (!o_postlink)
    [trlunit usesentry:[Symbol str:o_initcall]];

  if (datadefspecs == nil || ![[datadefspecs at:0] isvoid])
    gs("return");
  gs([s_objcmain str]);
  gc('(');
  o_nolinetags++;
  if (parmnames)
    gcommalist(parmnames);
  o_nolinetags--;
  gs(");\n");

  gs("}\n");
  return self;
}

- gen
{
  char *s;
  BOOL ismain;

  assert(decl != nil && body != nil);
  s = [[decl identifier] str];
  ismain = !strcmp(s, o_mainfun);
  [super gen]; /* code for class references and blocks in this impl */
  if (datadefspecs)
    [datadefspecs elementsPerform:@selector(gen)];
  if (ismain) {
    o_nolinetags++;
    [decl gendef:s_objcmain];
    o_nolinetags--;
    [trlunit definesentry:s_main];	/* also in postlink case */
  } else {
    [decl gen];
  }
  [body gen];
  if (ismain)
    [self genmain];
  return self;
}

- go
{
  return [self shouldNotImplement:_cmd];
}

- fcall:x
{
  id r;
  trlunit = unit;
  [[Stackframe push] def:self];
  if (breakpt) [breakpt go];
  r = [body fcall:x]; /* dispatch to funbody */
  [Stackframe pop];
  return r;
}

- printBtOn:(IOD)d
{
  id n;
  int lo;
  char *fn;
  n = [decl identifier];
  fn = [[n filename] str];
  lo = [n lineno];
  fprintf(d,"%s () at %s:%d\n",[n str],fn,lo);
  return self;
}

- setbreak:bkpt
{
  breakpt = bkpt;
  return self;
}

- defval:v
{
  return [self error:"Attempt to assign a value to function"];
}

- value
{
  return self;
}

@end
 
