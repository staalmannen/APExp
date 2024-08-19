
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
 * $Id: compdef.m,v 1.2 2000/09/08 14:48:31 stes Exp $
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
#include <ordcltn.h>
#include <ocstring.h>
#include "node.h"
#include "symbol.h"
#include "compdef.h"
#include "structsp.h"
#include "decl.h"
#include "bflddecl.h"
#include "type.h"

@implementation ComponentDef

- specs  {
  return specs;
}

- specs:aSpec
{
  specs = aSpec;
  return self;
}

- decllist  {
  return decllist;
}

- add:aDecl
{
  if (!decllist)
    decllist = [OrdCltn new];
  [decllist add:aDecl];
  return self;
}

- gen
{
  if (specs)
    [specs elementsPerform:@selector(gen)];
  if (decllist)
    gcommalist(decllist);
  gc(';');
  return self;
}

- synth
{
  int i, n;

  assert(curstruct);
  for (i = 0, n = [decllist size]; i < n; i++) {
    id var = [[decllist at:i] identifier];

    if (var) {
      id t = [Type new];
      id d = [decllist at:i];

      if (specs) {
        [specs elementsPerform:_cmd];
	[t specs:specs];	/* type filters out storage class */
	[t decl:d];		/* type makes a -abstrdecl of it */
      } else {
	[t addspec:s_int];	/* C default */
	[t decl:d];
      }
      [curstruct defcomp:var astype:t];
    } else {
      if (![[decllist at:i] isKindOf:(id)[BitfieldDecl class]]) {
	char *what = "class definition";
	char *ms = "missing name in component of %s";

	if ([curstruct isKindOf:(id) [StructSpec class]])
	  what = "struct or union";
	if (specs)
	  warnat([specs at:0], ms, what);
	else
	  warn(ms, what);
      }
    }
  }
  return self;
}

@end
 
