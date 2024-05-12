
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
 * $Id: forstmt.m,v 1.2 2003/09/29 16:52:05 stes Exp $
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
#include "forstmt.h"
#include "options.h"
#include "compstmt.h"
#include "util.h"
#include "var.h"
#include "scalar.h"
#include "stkframe.h"

@implementation ForStmt

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

- begin:a cond:b step:c
{
  begin = a;
  cond = b;
  step = c;
  return self;
}

- synth
{
  [begin synth];
  if (o_refcnt)
    curloopcompound = stmt;
  [cond synth];			/* whatever is allocated here, free in loopcomp and curcomp */
  [step synth];
  curloopcompound = nil;
  [stmt synth];
  return self;
}

- gen
{
  [keyw gen];
  gc('(');
  [begin gen];
  gc(';');
  [cond gen];
  gc(';');
  [step gen];
  gc(')');
  [stmt gen];
  return self;
}

- st80
{
  [begin st80];
  gs(".\n");
  gc('[');
  [cond st80];
  gs("]whileTrue:[\n");
  [stmt st80];
  [step gen];
  gs(".\n");
  gc(']');
  return self;
}

- go
{
   id e;
   for([begin go];cond==nil||(e=[cond go],!ISSCALARZERO(e));[step go]) {
     [stmt go];
     if ([topframe breakframe]) break;
     [topframe contframe:NO];
   }
   [topframe breakframe:NO];
   return self;
}

@end
 
