
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
 * $Id: gasmstmt.m,v 1.1.1.1 2000/06/07 21:09:25 stes Exp $
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
#include "node.h"
#include "stmt.h"
#include "gasmstmt.h"

@implementation GnuAsmStmt

- keyw:k
{
  keyw = k;
  return self;
}

- typequal:k
{
  typequal = k;
  return self;
}

- expr:e
{
  expr = e;
  return self;
}

- asmop1:op
{
  asmop1 = op;
  return self;
}

- asmop2:op
{
  asmop2 = op;
  return self;
}

- clobbers:c
{
  clobbers = c;
  return self;
}

- synth
{
  [expr synth];
  if (asmop1)
    [asmop1 elementsPerform:_cmd];
  if (asmop2)
    [asmop2 elementsPerform:_cmd];
  return self;
}

- gen
{
  [keyw gen];
  if (typequal)
    [typequal gen];
  gc('(');
  if (expr)
    [expr gen];
  if (asmop1 || asmop2 || clobbers) {
    gc(':');
  }
  if (asmop1) {
    gcommalist(asmop1);
  }
  if (asmop2 || clobbers) {
    gc(':');
  }
  if (asmop2) {
    gcommalist(asmop2);
  }
  if (clobbers) {
    gc(':');
  }
  if (clobbers) {
    int i, n;
    int comma = 0;

    for (i = 0, n = [clobbers size]; i < n; i++) {
      if (comma)
	gc(',');
      else
	comma++;
      [[clobbers at:i] elementsPerform:_cmd];
    }
  }
  gc(')');
  gc(';');
  return self;
}

- st80
{
  [expr st80];
  gs(".\n");
  return self;
}

@end
 
