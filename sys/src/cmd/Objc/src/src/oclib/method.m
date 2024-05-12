
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
 * $Id: method.m,v 1.2 2000/09/08 15:09:06 stes Exp $
 */

#include "config.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include <stdio.h> /* FILE */
#include "Object.h" /* Stepstone Object.h assumes #import */
#endif
#include <ocstring.h>
#include <ordcltn.h>
#include "node.h"
#include "decl.h"
#include "keywdecl.h"
#include "method.h"
#include "expr.h"
#include "keywxpr.h"
#include "type.h"
#include "selector.h"
#include "options.h"
#include "var.h"
#include "scalar.h"

/* must match definition of selptrfwd() in objcrt.m */
#define NUM_SELPTR_ARGS 3

@implementation Method

- usel
{
  return usel;
}

- ksel
{
  return ksel;
}

- canforward:(BOOL)f
{
  havecanforward = YES;
  canforward = f;
  return self;
}

- calccanforward
{
  havecanforward = YES;
  canforward = YES;

  if (varargs) {
    canforward = NO;
    return self;
  }
  if ([self needscast] == NO || [self isselptr]) {
    canforward = YES;
    return self;
  }
  /* as special exception, void (which cannot be forwarded as arg) */
  /* is allowed as return type (see -genfwdstub) */
  if (restype && !([restype canforward] || [restype isvoid])) {
    canforward = NO;
    return self;
  }
  if (ksel) {
    int i, n;

    for (i = 0, n = [ksel size]; i < n; i++) {
      if (![[ksel at:i] canforward]) {
	canforward = NO;
	return self;
      }
    }
  }
  return self;
}

- calcisselptr
{
  haveisselptr = YES;
  isselptr = YES;

  if ([self needscast] == NO) {
    if (ksel && [ksel size] > NUM_SELPTR_ARGS)
      isselptr = NO;
  } else {
    if (usel) {
      if (restype && ![restype isselptr])
	isselptr = NO;
    }
    if (ksel) {
      int i, n = [ksel size];

      if (n > NUM_SELPTR_ARGS) {
	isselptr = NO;
      } else {
	if (restype && ![restype isselptr]) {
	  isselptr = NO;
	  return self;
	}
	for (i = 0; i < n; i++) {
	  if (![[ksel at:i] isselptr]) {
	    isselptr = NO;
	    return self;
	  }
	}
      }
    }
  }
  return self;
}

- calchash
{
  havehash = YES;

  /* hash used for message FORWARDING based on return and argument types */
  /* may NOT be based on selector (e.g. +new and -copy have same hash)  */

  if (usel) {
    typehash = (restype) ? [restype hash] : [t_id hash];
  }
  if (ksel) {
    int i, n;

    typehash = (restype) ? [restype hash] : [t_id hash];
    for (i = 0, n = [ksel size]; i < n; i++) {
      typehash = (typehash << 1) ^ [[ksel at:i] typehash];
    }
  }
  return self;
}

- (unsigned)typehash
{
  if (!havehash)
    [self calchash];
  return typehash;
}

- (BOOL)typeEqual:that
{
  if (self == that) {
    return YES;
  } else {
    id y;
    id a = restype;
    id b = [that restype];

    if (!a)
      a = t_id;
    if (!b)
      b = t_id;
    if (![a isEqual:b])
      return NO;
    if (usel && (y = [that usel])) {
      return YES;
    }
    if (ksel && (y = [that ksel])) {
      int i, n = [ksel size];

      if (n != [y size])
	return NO;
      for (i = 0; i < n; i++) {
	if (![[ksel at:i] typeEqual:[y at:i]])
	  return NO;
      }
      return YES;
    }
    return NO;
  }
}

- calcneedscast
{
  haveneedscast++;

  if (o_inlinecache) {
    needscast = YES;
    return self;
  }
  if (restype != nil && ![restype isid]) {
    needscast = YES;
    return self;
  }
  if (ksel) {
    int i, n;

    for (i = 0, n = [ksel size]; i < n; i++) {
      if (![[ksel at:i] isid]) {
	needscast = YES;
	break;
      }
    }
  }
  return self;
}

- (BOOL)needscast
{
  if (!haveneedscast)
    [self calcneedscast];
  return needscast;
}

- (BOOL)isselptr
{
  if (!haveisselptr)
    [self calcisselptr];
  return isselptr;
}

- (BOOL)canforward
{
  if (!havecanforward)
    [self calccanforward];
  return canforward;
}

- restype
{
  return restype;
}

- restype:t
{
  restype = t;
  return self;
}

- (int)lineno
{
  if (lineno)
    return lineno;
  if (usel) {
    lineno = [usel lineno];
  } else {
    id fkeyw = [[ksel at:0] keyw];

    lineno = [fkeyw lineno];
  }
  return lineno;
}

- filename
{
  if (filename)
    return filename;
  if (usel) {
    filename = [usel filename];
  } else {
    id fkeyw = [[ksel at:0] keyw];

    filename = [fkeyw filename];
  }
  return filename;
}

- unarysel:aSel
{
  usel = aSel;
  return self;
}

- keywsel:aList
{
  ksel = aList;
  return self;
}

- selector
{
  if (selector) {
    return selector;
  } else {
    if (usel) {
      selector = [Selector str:[usel str]];
    } else {
      selector = [Selector new];
      [ksel elementsPerform:@selector(selcons:)with:selector];
    }
    return selector;
  }
}

- (BOOL)varargs
{
  return varargs;
}

- varargs:(BOOL)flag
{
  varargs = flag;
  return self;
}

- cvtcommalist
{
  /* convert last commaexpr to an exprlist */
  if (ksel)
    [[ksel lastElement] cvtcommalist];
  return self;
}

- warnforwithmethod
{
  char *s = [[self selector] str];
  if (!strcmp(s, "with:")) {
    /* suggestion Marc Boschma marcb@c3.telstra-mm.net.au */
    /* to check number of arguments for +with: method */
    if (ksel)
      [[ksel lastElement] warnforwithmethod];
  }
  return self;
}

- gencast
{
  if (restype) {
    [restype genabstrtype];
  } else {
    gs("id");
  }

  gs("(*)");			/* function pointer */

  gc('(');
  gs("id,SEL");
  if (ksel) {
    int i, n;

    for (i = 0, n = [ksel size]; i < n; i++) {
      gc(',');
      [[ksel at:i] genabstrtype];
    }
    if (varargs) {
      gs(",...");
    }
  }
  gc(')');
  return self;
}

- genrestype
{
  if (restype) {
    [restype gen];
  } else {
    gs("id");			/* Objective C default */
  }
  return self;
}

- genargstruct
{
  if (restype == nil || ![restype isvoid]) {
    [self genrestype];
    gs("_retval;\n");
  } else {
    gs("int _retval;\n");	/* assures non-empty struct */
  }
  if (ksel) {
    int i, n;

    for (i = 0, n = [ksel size]; i < n; i++) {
      [[ksel at:i] genparm];
      gs(";\n");
    }
  }
  return self;
}

- genparmlist
{
  if (ksel)
    [ksel elementsPerform:@selector(gencommaparm)];
  if (varargs) {
    gc(',');
    gs("...");
  }
  return self;
}

- genmsgargs
{
  if (ksel) {
    int i, n = [ksel size];

    for (i = 0; i < n; i++) {
      gc(',');
      [[ksel at:i] genarg];
    }
  }
  return self;
}

- gendispargs
{
  if (ksel) {
    int i, n = [ksel size];

    for (i = 0; i < n; i++) {
      gc(',');
      [[ksel at:i] gendisparg];
    }
  }
  return self;
}

- gendispargsintostruct
{
  if (ksel)
    [ksel elementsPerform:_cmd];
  return self;
}

- synth
{
  if (ksel)
    [ksel elementsPerform:_cmd];
  return self;
}

- gen
{
  return self;
}

- st80
{
  if (usel)
    [usel st80];
  if (ksel)
    [ksel elementsPerform:_cmd];
  return self;
}

@end
 
