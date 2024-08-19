
/*
 * Copyright (c) 1998,1999,2000 David Stes.
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
 * $Id: identxpr.m,v 1.1.1.1 2000/06/07 21:09:25 stes Exp $
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
#include "node.h"
#include "expr.h"
#include "identxpr.h"
#include "symbol.h"
#include "type.h"
#include "trlunit.h"
#include "options.h"
#include "stmt.h"
#include "compstmt.h"
#include "def.h"
#include "methdef.h"
#include "datadef.h"
#include "globdef.h"
#include "classdef.h"
#include "stkframe.h"
#include "var.h"
#include "scalar.h"

@implementation IdentifierExpr

+ resolve:sym
{
  return [self notImplemented:_cmd];
}

+ str:(STR)s
{
  return [[super new] identifier:[Symbol str:s]];
}

- (STR)str
{
  return [identifier str];
}

- (int)lineno
{
  return [identifier lineno];
}

- filename
{
  return [identifier filename];
}

- identifier
{
  return identifier;
}

- identifier:aNode
{
  identifier = aNode;
  return self;
}

- lhsself:(BOOL)x
{
  lhsself = x;			/* left hand side self doesn't need cast */
  return self;
}

- check:x type:t in:compound inblock:(BOOL)insideblock
{
  if ([compound isheapvar:x]) {
    heapvarblock = compound;	/* found a heapvar */
    [curdef addheapvarblock:compound];	/* found block with heapvars */
    [curcompound addheapvarblock:compound];	/* tell all blocks above us */
  } else {
    if (insideblock) {
      heapvarblock = compound;	/* found var to promote to heapvar */
      [compound defheapvar:x type:t];
      [curdef addheapvarblock:compound];	/* found block with heapvars */
      [curcompound addheapvarblock:compound];	/* tell all blocks above us */
    } else {
      maybeheapvarblock = compound;	/* may become a heapvar later */
    }
  }
  return self;
}

/* reference to ivar or cvar from within block promotes 'self' to heapvar */

- (BOOL)inblock
{
  id c;

  for (c = curcompound; c; c = [c enclosing]) {
    if ([c isblockexpr])
      return YES;
  }
  return NO;
}

- checkselfheapvar
{
  id c, t_self;

  c = [curdef compound];
  classdef = curclassdef;
  t_self = [classdef selftype];
  return [self check:s_self type:t_self in:c inblock:[self inblock]];
}

- typesynth
{
  if (!type)
    [self synth];
  return self;
}

- synth
{
  id c;
  BOOL usingblocks = (o_blocks && [trlunit usingblocks]);

  /* is it a local variable or argument of a block/fun/meth ? */

  if (1) {			/* fast test in case it isn't */
    int insideblock = 0;

    for (c = curcompound; c; c = [c enclosing]) {
      if ((type = [c lookuplocal:identifier])) {
	/* case of a local defined extern */
	if (!o_postlink && [type isextern]) {
	  [trlunit usesentry:identifier];
        } else { 
          isstkvar++;
        }
	if (usingblocks) {
	  [self check:identifier type:type in:c inblock:insideblock];
	}
	return self;
      }
      if (usingblocks) {
	BOOL isblock = [c isblockexpr];

	if (isblock && (type = [c lookupparm:identifier])) {
          isstkvar++;
	  [self check:identifier type:type in:c inblock:insideblock];
	  return self;
	}
	if (isblock)
	  insideblock++;
      }
    }

    if (curdef && (type = [curdef lookupparm:identifier])) {
      id c = [curdef compound];
      isstkvar++;
      [self check:identifier type:type in:c inblock:insideblock];
      isself = ([identifier isEqual:s_self] && [curdef ismethdef]);
      return self;
    }
  }
  /* is it an instance or class variable ? */

  if (curclassdef) {
    BOOL ism = (curdef != nil && [curdef ismethdef]);
    char *msg = "%s variable '%s' used outside method implementation";

    if ([curclassdef isivar:identifier]) {
      if (ism) {
	ivar++;
	classdef = curclassdef;
	infactory = [curdef factory];
	type = [curclassdef lookupivar:identifier];
	if (usingblocks)
	  [self checkselfheapvar];
	return self;
      } else {
	warnat(identifier, msg, "instance", [identifier str]);
      }
    }
    if ([curclassdef iscvar:identifier]) {
      if (ism) {
	cvar++;
	classdef = curclassdef;
	infactory = [curdef factory];
	type = [curclassdef lookupcvar:identifier];
	if (usingblocks)
	  [self checkselfheapvar];
	return self;
      } else {
	warnat(identifier, msg, "class", [identifier str]);
      }
    }
  }
  /* is it a global variable or function name ? */

  if ((type = [trlunit lookupglobal:identifier])) {
    isglobal++;
    if (!o_postlink && [type definesocu])
      [trlunit usesentry:identifier];
    return self;
  }
  /* is it the name of a class ? */

  if ((c = [trlunit lookupclass:identifier])) {
    type = t_id;
    if (curdef) {
      [curdef addclassreference:c];
    } else {
      char *msg = "classname '%s' used outside method or function implementation";

      warnat(identifier, msg, [identifier str]);
    }
    if (!o_postlink)
      [trlunit usesentry:identifier];
    isclassref++;
    classdef = c;
    return self;
  }
  if ([trlunit lookupenumtor:identifier]) {
    type = t_int;
    return self;
  }
  if (o_warnintvar) {
    warnat(identifier, "definition of '%s' defaults to 'int'", [identifier str]);
  }
  isglobal++;
  type = t_int;
  return self;
}

/* it wasn't when we last checked but may have become a heapvar */
/* for example : int x; x=0; b = {:a | x+=[a size]; } */

- checkagain
{
  id x = (ivar || cvar) ? s_self : identifier;

  if ([maybeheapvarblock isheapvar:x]) {
    heapvarblock = maybeheapvarblock;
    maybeheapvarblock = nil;
  } else {
    maybeheapvarblock = nil;
  }
  return self;
}

- gen
{
  if (maybeheapvarblock)
    [self checkagain];

  if (isself && !lhsself)
    gs("(id)");

  if (heapvarblock) {
    gs([heapvarblock heapvarptrname]);
    gs("->");
  }
  if (ivar) {
    gs("self->");
    if (o_otb)
      gs("ptr->");
  }
  if (cvar) {
    gf("((struct %s *)", [classdef shartypename]);	/* isa of Object.h is 'id' */
    if (infactory) {
      gs("self)->");
    } else {
      gs("self->isa)->");
    }
    if (o_otb)
      gs("ptr->");
  }
  if (isclassref) {
    [classdef genclassref];
  } else {
    [identifier gen];
  }
  return self;
}

- st80
{
  [identifier st80];
  return self;
}

- (BOOL)isidentexpr
{
  return YES;
}

- go
{
  id v;
  id c;

  /* is it a global variable or function name ? */

  if (isglobal) {
    return [[loadedmodules resolve:identifier] value];
  }

  /* is it a local variable or argument of a block/fun/meth ? */

  if (isstkvar) {
    return [topframe lookupval:identifier]; /* can be nil */
  } 

  /* is it a class name ? */

  if (isclassref) {
    id c;
    char *name = [classdef classname];
    assert(name != NULL);
    c = [self findClass:name];
    if (!c) [self error:"class '%s' not loaded",name];
    return c;
  }
  
  /* is it the name of an instance or class variable ? */

  if (ivar) {
    return [classdef getivarval:[topframe lookupself]:infactory:identifier]; 
  }
  if (cvar) return [self notImplemented:_cmd];

  return [self error:"cant find variable '%s'",[identifier str]];
}

- assignvar:v
{
  id c;

  /* is it a global variable or function name ? */

  if (isglobal) {
    id g = [loadedmodules resolve:identifier];
    [g defval:v];
    return v;
  }

  /* is it a local variable or argument of a block/fun/meth ? */
  for (c = topframe; c; c = [c enclosing]) {
    if ((type = [c lookuplocal:identifier])) {
      /* case of a local defined extern */
      if ([type isextern] || [type isstatic])
        [self notImplemented:_cmd];
      /* check type ? */
      [c defval:identifier as:v];
      return v;
    }
  }

  if (ivar) {
    return [classdef setivarval:[topframe lookupself]:infactory:identifier:v]; 
  }
  if (cvar) {
    return [self notImplemented:_cmd];
  }

  /* retval of assignment expression */
  return v;
}

@end
 
