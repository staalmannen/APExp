
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
 * $Id: msgxpr.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
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
#include <set.h>
#include "node.h"
#include "expr.h"
#include "msgxpr.h"
#include "identxpr.h"
#include "stmt.h"
#include "compstmt.h"
#include "selector.h"
#include "symbol.h"
#include "method.h"
#include "def.h"
#include "methdef.h"
#include "classdef.h"
#include "type.h"
#include "trlunit.h"
#include "options.h"
#include "var.h"
#include "scalar.h"

id msgwraps; /* VICI */

@implementation MesgExpr

/* equality for message *forwarding*  (equivalence of argument types) */

- (BOOL)canforward
{
#if 0
  return (method == nil && [msg canforward]) || [method canforward];
#else
  return method != nil && [method canforward];
#endif
}

- (unsigned)hash
{
  id a;

  if ((a = [self method])) {
    return [a typehash];
  } else {
    return [msg hash];
  }
}

- (BOOL)isEqual:that /* in typeEqual: sense */
{
  if (self == that) {
    return YES;
  } else {
    id a = [self method];
    id b = [that method];

    if (!a)
      a = [self msg];
    if (!b)
      b = [that msg];
    return [a typeEqual:b];
  }
}

- receiver:aRcvr
{
  rcvr = aRcvr;
  return self;
}

- msg:m
{
  msg = m;
  assert([msg isKindOf:(id) [Method class]]);
  return self;
}

- tmpvar
{
  if (tmpvar)
    return tmpvar;
  /* tmp var that will hold the receiver (evaluated only once) */
  return tmpvar = [trlunit gettmpvar];
}

- icache
{
  if (icache)
    return icache;
  return icache = [String sprintf:"objcIC%i", [trlunit icachecount]];
}

- msg
{
  return msg;
}

- method:m
{
  if (methodfound) [self notImplemented:_cmd];
  methodfound++;
  method = m;
  return self;
}

- method
{
  if (methodfound) {
    return method;
  } else {
    methodfound++;
    method = [trlunit lookupmethod:[self selector]];
    if (!method && o_warnundefined) {
      warnat(msg, "argument types for '%s' default to 'id'", [sel str]);
    } else {
      if ([method varargs])
	[msg cvtcommalist];
    }
    return method;
  }
}

- indispatchfun:(BOOL)f
{
  indispatchfun = f;
  return self;
}

- (BOOL)varargs
{
  return [[self method] varargs];
}

- selector
{
  if (sel)
    return sel;
  sel = [msg selector];
  return sel;
}

- typesynth
{
  if ([self method])
    type = [method restype];
  if (!type)
    type = t_id;		/* Objective C default */
  return self;
}

- synth
{
  /* find prototype */
  method = [self method];
  if ([self varargs])
    [msg warnforwithmethod];

  if (curcompound) {
    BOOL inm = (curdef && [curdef ismethdef]);

    /* in a function 'super' is ordinary */
    if (inm && [rcvr isidentexpr]) {
      supermsg = !strcmp([rcvr str], "super");
      infactory = [curdef factory];
      classdef = curclassdef;
      if (supermsg)
	rcvr = nil;
    }
    [curcompound addtmpvar:[self tmpvar]];
    if (o_inlinecache)
      [curcompound addicache:[self icache]];
  } else {
    fatalat(msg, "message expression outside compound statement");
  }

  if (rcvr)
    [rcvr synth];
  [msg synth];

  if (o_refcnt && [[self type] isid]) {
    refvar = [trlunit gettmpvar];
    [curcompound addtmpvar:refvar];
    [curcompound adddecref:refvar];
  }
  return self;
}

- assignrcvr
{
  id t = [self tmpvar];

  gf("%s=", [t str]);
  [rcvr gen];
  return self;
}

- assignsuper
{
  id t = [self tmpvar];

  gf("%s=", [t str]);
  assert(classdef != nil);
  return (infactory) ? [classdef genmetasuper] : [classdef gensuper];
}

- genimpcall:(BOOL)tosuper
{
  char *messenger;

  if (!o_fwd) {
    messenger = (tosuper) ? "_impSuper" : "_imp";
    gf("%s(%s,", messenger, [tmpvar str]);
    if (indispatchfun) {
      gs("_cmd");
    } else {
      [[self selector] gen];
    }
    gc(')');
  } else {
    messenger = (tosuper) ? "fwdimpSuper" : "fwdimp";
    gf("%s(%s,", messenger, [tmpvar str]);
    if (indispatchfun) {
      gs("_cmd");
    } else {
      [[self selector] gen];
    }
    gc(',');
    if ([self canforward]) {
      if ([method isselptr]) {
	gs("selptrfwd");	/* Objective-C default (all args 'id') */
      } else {
	gf("fwdTransTbl[%i]", [trlunit fwdoffset:self]);
      }
    } else {
      gs((o_cplus) ? "(id(*)(...))0" : "(id(*)())0");
      if (o_warnfwd) {
	char *fmt;

	if (method) {
	  fmt = "forwarding of '%s' messages not supported";
	} else {
	  fmt = "cannot forward '%s'. no such method found.";
	}
	warnat(msg, fmt, [sel str]);
      }
    }
    gc(')');
  }

  return self;
}

- geninlinecall:(BOOL)tosuper
{
  char *fmt;
  char *tvar = [tmpvar str];
  char *cache = [icache str];

  gf("(%s)?(", tvar);
  gc('(');
  if (!o_otb) {
    fmt = (tosuper) ? "%s" : "%s->isa";
  } else {
    fmt = (tosuper) ? "%s" : "%s->ptr->isa";
  }
  gf(fmt, tvar);
  gf("==%s.cls)?%s.imp:", cache, cache);
  gc('(');
  gf("%s.cls=", cache);
  gf(fmt, tvar);
  gf(",%s.imp=", cache);
  [self genimpcall:tosuper];
  gc(')');
  gs("):_nilHandler");
  return self;
}

/* call messenger, cast return value, and dereference */

- gencall:(BOOL)tosuper
{
  gs("(*");
  if (method && [method needscast]) {
    gc('(');
    [method gencast];
    gc(')');
  }
  if (o_inlinecache && !indispatchfun) {
    gc('(');
    [self geninlinecall:tosuper];
    gc(')');
  } else {
    [self genimpcall:tosuper];
  }
  gc(')');
  return self;
}

- genmsgargs:(BOOL)tosuper
{
  if (tosuper) {
    gs("(id)");
    [e_self sgen];		/* 'self' can be output as scope->self in block */
  } else {
    gs([tmpvar str]);
  }

  gc(',');
  if (indispatchfun) {
    gs("_cmd");
  } else {
    [[self selector] gen];
  }

  if (indispatchfun) {
    [method gendispargs];
  } else {
    [msg genmsgargs];		/* begins with comma */
  }

  return self;
}

- genmsg:(BOOL)insuper
{
  [self gencall:insuper];
  gc('(');
  [self genmsgargs:insuper];
  gc(')');
  return self;
}

- genmsg
{
  gc('(');
  [self assignrcvr];
  gc(',');
  [self genmsg:NO];
  gc(')');
  return self;
}

- gensupermsg
{
  gc('(');
  [self assignsuper];
  gc(',');
  [self genmsg:YES];
  gc(')');
  return self;
}

- (int)lineno
{
  return [msg lineno];
}

- filename
{
  return [msg filename];
}

- gen
{
  gl([msg lineno], [[msg filename] str]);
  if (refvar) {
    gc('(');
    gs([refvar str]);
    gc('=');
  }
  (supermsg) ? [self gensupermsg] : [self genmsg];
  if (refvar) gc(')');
  return self;
}

- (char*)fwdname
{
  assert(sel);
  if (fwdname)
    return fwdname;
  fwdname = [[[Symbol sprintf:"%s_fwd", [sel str]] toscores] strCopy];
  return fwdname;
}

- (char*)dispname
{
  assert(sel);
  if (dispname)
    return dispname;
  dispname = [[[Symbol sprintf:"%s_disp", [sel str]] toscores] strCopy];
  return dispname;
}

- (char*)argstructname
{
  assert(sel);
  if (argstructname)
    return argstructname;
  argstructname = [[[Symbol sprintf:"%s_args", [sel str]] toscores] strCopy];
  return argstructname;
}

- genargstruct
{
  assert(method);
  gf("struct %s {\n", [self argstructname]);
  [method genargstruct];
  gs("};\n");
  return self;
}

- xgendispfun
{
  id rt;

  assert(method);
  gf("static void %s(id self,SEL _cmd", [self dispname]);
  gf(",struct %s *args)\n", [self argstructname]);
  gs("{\n");
  if ((rt = [method restype]) == nil || ![rt isvoid]) {
    gs("args->_retval = ");
  }
  [self genmsg:NO];
  gs(";\n");
  gs("}\n");
  return self;
}

- gendispfun
{
  assert(method);
  rcvr = e_self;
  tmpvar = e_self;
  indispatchfun++;
  return [self xgendispfun];
}

- gendispargsintostruct
{
  [method gendispargsintostruct];
  return self;
}

- genfwdstub
{
  id rt;

  assert(method);
  gs("static ");
  [method genrestype];
  gf(" %s(id self,SEL _cmd", [self fwdname]);
  [method genparmlist];
  gs(")\n");
  gs("{\n");
  gf("struct %s args;\n", [self argstructname]);
  [self gendispargsintostruct];
  gf("fwdmsg(self,_cmd,&args,(ARGIMP)%s);\n", [self dispname]);
  if ((rt = [method restype]) == nil || ![rt isvoid]) {
    gs("return args._retval;\n");
  }
  gs("}\n");
  return self;
}

- st80
{
  gc('(');
  [rcvr st80];
  [msg st80];
  gc(')');
  return self;
}

- send:(IMP)i sel:(SEL)sel with:kw to:rcvr
{
  return [self subclassResponsibility:_cmd];
}

- go
{
  id r;
  if ((r = [rcvr go])) {
    SEL s; 
    char *sn;
    sn = [[self selector] str];
    if ((s = [self findSel:sn])) {
      IMP i = [r methodFor:s];
      if (!msgwrap) msgwrap = [msgwraps find:self];
      if (!msgwrap) [self error:"'%s' can't send this type of message",sn];
      return [msgwrap send:i sel:s with:[msg ksel] to:r];
    } else {
      return [self error:"selector %s not loaded",sn];
    }
  } else {
    return nil; /* msg to nil */
  }
}

@end
 
