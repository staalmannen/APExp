
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
 * $Id: whilstmt.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
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
#include "whilstmt.h"
#include "options.h"
#include "compstmt.h"
#include "var.h"
#include "scalar.h"
#include "stkframe.h"

@implementation WhileStmt

- synth
{
  if (o_refcnt)
    curloopcompound = stmt;
  [expr synth];
  curloopcompound = nil;
  [stmt synth];
  return self;
}

- st80
{
  gc('[');
  [expr st80];
  gc(']');
  gs("whileTrue:[");
  [stmt st80];
  gc(']');
  gs(".\n");
  return self;
}


- go
{
  id e;
  while (e=[expr go],!ISSCALARZERO(e)) {
    [stmt go];
    if ([topframe breakframe]) break;
    [topframe contframe:NO];
  }
  [topframe breakframe:NO];
  return self;
}

@end
 
