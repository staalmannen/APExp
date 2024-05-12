
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
 * $Id: ifstmt.m,v 1.2 2003/09/29 16:52:05 stes Exp $
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
#include "ifstmt.h"
#include "compstmt.h"
#include "options.h"
#include "util.h"
#include "stkframe.h"
#include "var.h"
#include "scalar.h"

@implementation IfStmt

- keyw:aKeyw
{
  keyw = aKeyw;
  return self;
}

- expr:anExpr
{
  expr = anExpr;
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

- ekeyw:eKeyw
{
  ekeyw = eKeyw;
  return self;
}

- estmt:eStmt
{
  estmt = eStmt;
  if (o_refcnt && ![estmt iscompstmt]) {
    estmt = mkcompstmt(nil, nil, mklist(nil, estmt), nil, nil);
  }
  return self;
}

- synth
{
  [expr synth];
  [stmt synth];
  if (estmt)
    [estmt synth];
  return self;
}

- gen
{
  [keyw gen];
  gc('(');
  [expr gen];
  gc(')');
  [stmt gen];
  if (ekeyw)
    [ekeyw gen];
  if (estmt)
    [estmt gen];
  return self;
}

- st80
{
  gc('(');
  [expr st80];
  gc(')');
  gs("ifTrue:[");
  [stmt st80];
  gc(']');
  if (estmt) {
    gs("ifFalse:[");
    [estmt st80];
    gc(']');
  }
  gs(".\n");
  return self;
}

- go
{
  id e;
  if (e=[expr go],!ISSCALARZERO(e)) {
    [stmt go];
  } else {
    if (estmt) [estmt go];
  }
  return self;
}

@end
 
