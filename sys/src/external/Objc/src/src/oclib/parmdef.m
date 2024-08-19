
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
 * $Id: parmdef.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
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
#include "parmdef.h"
#include "decl.h"
#include "symbol.h"
#include "type.h"
#include "def.h"

@implementation ParameterDef 

- specs  {
  return specs;
}

- specs:aSpec
{
  specs = aSpec;
  return self;
}

- decl:aDecl
{
  decl = aDecl;
  return self;
}

- gen
{
  if (specs)
    [specs elementsPerform:@selector(gen)];
  if (decl)
    [decl gen];
  return self;
}

- synth
{
  if (curdef) {
    id v = nil;

    if (decl)
      v = [decl identifier];
    if (!decl || !v) {
      if (specs && [specs size] == 1 && [[specs at:0] isvoid])
	return self;
      warn("missing parameter name in function definition");
    } else {
      id t = [Type new];

      [t specs:specs];
      [t decl:decl];		/* type makes an abstrdecl of it */
      [curdef defparm:v astype:t];
    }
  }
  return self;
}

@end
 
