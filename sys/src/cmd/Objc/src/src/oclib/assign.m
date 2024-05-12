
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
 * $Id: assign.m,v 1.4 2001/01/25 19:54:41 stes Exp $
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
#include "node.h"
#include "expr.h"
#include "binxpr.h"
#include "identxpr.h"
#include "assign.h"
#include "type.h"
#include "def.h"
#include "classdef.h"
#include "options.h"
#include "trlunit.h"

@implementation Assignment

- (int)lineno
{
  return [lhs lineno];
}

- filename
{
  return [lhs filename];
}

- typesynth
{
  type = [lhs type];
  return self;
}

- synth
{
  [super synth];
  if (curdef && [curdef ismethdef] && [lhs isidentexpr] && strcmp([lhs str], "self") == 0) {
    [trlunit usingselfassign:YES];
    if (!o_selfassign) {
      id sym = [lhs identifier];

      fatalat(sym, "assignment to 'self' not allowed with -noSelfAssign");
    } else {
      classdef = curclassdef;
      isselfassign++;
      /* we cannot cast the lhs to 'id' (that is not ANSI C) */
      [lhs lhsself:YES];	/* no 'id' cast at the lhs */
    }
  }
  if (o_refcnt) {
    if (isselfassign || [[lhs type] isrefcounted])
      isidassign++;
  }
  return self;
}

- gen
{
  if (isidassign) {
    gl([lhs lineno], [[lhs filename] str]);
    if (!isselfassign) {
      gs("idassign(&");
      [lhs gen]; 
      gc(',');
      [rhs gen];
      gc(')');
    } else {
      gs("idassign((id*)(&");
      [lhs gen];
      gs("),");
      [rhs gen];
      gc(')');
    }
    return self;
  }
  if (isselfassign) {
    [lhs gen];
    gs(op);
    /* cast rhs to type of 'self' */
    if (!o_otb) {
      gf("(struct %s*)", [classdef privtypename]);
    } else {
      gf("(struct %s*)", [classdef otbtypename]);
    }
    gc('(');
    [rhs gen];
    gc(')');
    return self;
  }
  return [super gen];
}

- go
{
  return [lhs assignvar:[rhs go]];
}

- st80
{
  [lhs st80];
#ifdef ST80
  gc('_');
#else
  gs(":=");
#endif
  [rhs st80];
  return self;
}

@end
 
