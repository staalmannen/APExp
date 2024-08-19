
/*
 * Copyright (c) 1998,2000 David Stes.
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
 * $Id: dfltstmt.m,v 1.3 2003/09/29 16:52:05 stes Exp $
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
#include "dfltstmt.h"
#include "util.h"
#include "options.h"

@implementation DefaultStmt

- stmt:aStmt
{
  stmt = aStmt;
  if (o_refcnt && ![stmt iscompstmt]) {
    stmt = mkcompstmt(nil, nil, mklist(nil, stmt), nil, nil);
  }
  return self;
}

- keyw:aKeyw
{
  keyw = aKeyw;
  return self;
}

- synth
{
  [stmt synth];
  return self;
}

- gen
{
  [keyw gen];
  gc(':');
  [stmt gen];
  return self;
}

- (BOOL)iscaseOf:e
{
  return YES; /* anything matches */
}

- go
{
  return [stmt go];
}
  
@end
 
