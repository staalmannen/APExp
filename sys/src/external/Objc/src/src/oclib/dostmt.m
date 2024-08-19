
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
 * $Id: dostmt.m,v 1.2 2003/09/29 16:52:05 stes Exp $
 */

#include "config.h"
#include <stdlib.h>
#include <assert.h>
#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include <stdio.h> /* FILE */
#include "Object.h" /* Stepstone Object.h assumes #import */
#endif
#include "node.h"
#include "stmt.h"
#include "dostmt.h"
#include "compstmt.h"
#include "options.h"
#include "util.h"
#include "stkframe.h"
#include "var.h"
#include "scalar.h"

@implementation DoStmt

- keyw:aKeyw
{
  keyw = aKeyw;
  return self;
}

- stmt:aStmt
{
  stmt = aStmt;
  if (o_refcnt && ![stmt iscompstmt]) {
    stmt = mkcompstmt(nil, nil, mklist(nil, stmt), nil, nil);
  }
  return self;
}

- wkeyw:wKeyw
{
  wkeyw = wKeyw;
  return self;
}

- expr:anExpr
{
  expr = anExpr;
  return self;
}

- synth
{
  [stmt synth];
  if (o_refcnt)
    curloopcompound = stmt;
  [expr synth];
  curloopcompound = nil;
  return self;
}

- gen
{
  [keyw gen];
  [stmt gen];
  [wkeyw gen];
  gc('(');
  [expr gen];
  gc(')');
  gc(';');
  return self;
}

- st80
{
  [stmt st80];
  gc('[');
  [expr st80];
  gs("]whileTrue:[\n");
  [stmt st80];
  gc(']');
  return self;
}

- go
{
  id e;
  do {
    [stmt go];
    if ([topframe breakframe]) break;
    [topframe contframe:NO];
  } while (e=[expr go],!ISSCALARZERO(e));  
  [topframe breakframe:NO];
  return self;
}

@end
 
