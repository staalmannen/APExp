
/*
 * Copyright (c) 1998,1999 David Stes.
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
 * $Id: funcall.m,v 1.1.1.1 2000/06/07 21:09:25 stes Exp $
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
#include <idarray.h>
#include "node.h"
#include "expr.h"
#include "type.h"
#include "funcall.h"
#include "util.h"
#include "options.h"
#include "stmt.h"
#include "compstmt.h"
#include "trlunit.h"
#include "def.h"
#include "fundef.h"

@implementation FunctionCall

- funname:aRcvr
{
  funname = aRcvr;
  return self;
}

- funargs:args
{
  funargs = args;
  return self;
}

- (int)lineno
{
  return [funname lineno];
}

- filename
{
  return [funname filename];
}

- gen
{
  if (refvar) {
    gl([self lineno],[[self filename] str]);
    gc('(');
    gs([refvar str]);
    gc('=');
  }
  [funname gen];
  gc('(');
  if (funargs)
    gcommalist(funargs);
  gc(')');
  if (refvar) gc(')');
  return self;
}

- typesynth
{
  type = [funname type];
  type = [type funcall];
  if (!type) {
    warn("can't make function call to this type of object");
    type = t_int;
  }
  return self;
}

- synth
{
  [funname synth];
  if (funargs)
    [funargs elementsPerform:_cmd];
  if (o_refcnt && [[self type] isid]) {
    refvar = [trlunit gettmpvar];
    [curcompound addtmpvar:refvar];
    [curcompound adddecref:refvar];
  }
  return self;
}

- go
{
  id args;
  int i,n;
  id fdef = [funname go];
  if ([fdef isfundef]) {
    n = [funargs size];
    args = [IdArray new:n];
    for(i=0;i<n;i++) {
      [args at:i put:[[funargs at:i] go]];
    }
    return [fdef fcall:args]; 
  } else {
    return [self error:"Object is not a function name"];
  }
}

@end
 
