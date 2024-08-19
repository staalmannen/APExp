
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
 * $Id: methdef.m,v 1.1.1.1 2000/06/07 21:09:25 stes Exp $
 */

#include "config.h"
#include <stdlib.h>
#include <assert.h>
#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include <stdio.h> /* FILE */
#include "Object.h" /* Stepstone Object.h assumes #import */
#endif
#include <set.h>
#include <ocstring.h>
#include "symbol.h"
#include "selector.h"
#include "node.h"
#include "def.h"
#include "methdef.h"
#include "stmt.h"
#include "compstmt.h"
#include "method.h"
#include "classdef.h"
#include "trlunit.h"
#include "options.h"
#include "type.h"
#include "expr.h"
#include "msgxpr.h"
#include "stkframe.h"

@implementation MethodDef 

- (unsigned)hash
{
  return [method typehash];
}

- (BOOL)isEqual:that /* in typeEqual: sense */
{
  if (self == that) {
    return YES;
  } else {
    id b = [that method];
    return [method typeEqual:b];
  }
}

- (BOOL)factory
{
  return factory;
}

- restype
{
  id r = [method restype];

  return (r) ? r : t_id;
}

- (BOOL)ismethdef
{
  return YES;
}

- factory:(BOOL)flag
{
  factory = flag;
  return self;
}

- (char*)selname
{
  assert(selname != NULL);
  return selname;
}

- (char*)impname
{
  assert(impname != NULL);
  return impname;
}

- method
{
  return method;
}

- selector
{
  return [method selector];
}

- method:aDecl
{
  method = aDecl;
  return self;
}

- compound
{
  return body;
}

- body:aBody
{
  body = aBody;
  return self;
}

- classdef:aClass
{
  classdef = aClass;
  return self;
}

- prototype
{
  if (!curclassdef) {
    fatal("method prototype outside interface");
  } else {
    id m, s = [self selector];

    if (o_warntypeconflict && (m = [trlunit lookupmethod:s])) {
      /* hashes and equality of methods in terms of *type* equality */
      if ([m typeEqual:method]) {
	assert([m typehash] == [method typehash]);
      } else {
	int no = [m lineno];
	char *fn = [[m filename] str];

	warn("selector '%s' previously declared at %s:%d", [s str], fn, no);
      }
    } else {
      [trlunit def:s asmethod:method];
      if (factory) {
	[curclassdef addclssel:s];
      } else {
	[curclassdef addnstsel:s];
      }
    }
  }
  return self;
}

- synth
{
  unit = trlunit;

  if (!curclassdef) {
    fatal("method definition outside implementation");
  } else {
    id t;
    id x;
    char *fmt;

    [self classdef:curclassdef];
    curdef = self;
    curcompound = nil;
    x = [s_self copy];
    [x lineno:[method lineno]];
    [x filename:[method filename]];
    [self defparm:x astype:[classdef selftype]];	/* it's not t_id */
    x = [s_cmd copy];
    [x lineno:[method lineno]];
    [x filename:[method filename]];
    [self defparm:x astype:t_sel];
    [method synth];
    [curclassdef forceimpl];
    selname = [[method selector] str];
    fmt = (factory) ? "c_%s_%s" : "i_%s_%s";
    t = [[Symbol sprintf:fmt, [curclassdef classname], selname] toscores];
    impname = [t strCopy];
    if (factory) {
      [curclassdef addclsdisp:self];
    } else {
      [curclassdef addnstdisp:self];
    }
    [trlunit usingselfassign:NO];
    [body synth];
    curdef = nil;
  }
  return self;
}

- gen
{
  id f, c;

  [classdef gen];		/* in case not yet emitted (must be done before blocks) */
  [super gen];			/* code for class references and blocks in this impl */
  if ((f = [method filename]))
    gl([method lineno], [f str]);
  gs("static");
  [method genrestype];
  gs(impname);
  gc('(');
  c = classdef;
  assert(classdef);
  gf("struct %s *self,SEL _cmd", (o_otb) ? [c otbtypename] : [c privtypename]);
  [method genparmlist];
  gc(')');
  [body gen];
  return self;
}

- st80
{
  int no;
  char *fn, *sl;

  [classdef st80];		/* in case not yet emitted */
  gf("!%s methodsFor:'POC Generated' stamp: 'POC'!", [classdef classname]);
  gc('\n');
  [method st80];
  gc('\n');
  no = [method lineno];
  fn = [[method filename] str];
  sl = [[method selector] str];
  gf("\t\"Generated from '%c%s' at %s:%d\"", (factory) ? '+' : '-', sl, fn, no);
  gc('\n');
  [body st80];
  gs("! !\n");
  gc('\n');
  return self;
}

- fcall:x
{
  id r;
  trlunit = unit;
  if (breakpt) [breakpt go];
  [[Stackframe push] def:self];
  r = [body fcall:x];
  [Stackframe pop];
  return r;
}

- printBtOn:(IOD)d
{
  int no = [method lineno];
  char *fn = [[method filename] str];
  char *cn = [classdef classname];
  char *sn = [[self selector] str];
  fprintf(d,(factory)?"+":"-");
  fprintf(d,"[%s %s] at %s:%d\n",cn,sn,fn,no);
  return self; 
}

- setbreak:bkpt
{
  breakpt = bkpt;
  return self;
}

@end
 
