
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
 * $Id: parmlist.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
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
#include "parmlist.h"
#include "util.h"

@implementation ParameterList

- idents:aList
{
  idents = aList;
  return self;
}

- parmdefs:aList
{
  parmdefs = aList;
  return self;
}

- varargs:(BOOL)flag
{
  varargs = flag;
  return self;
}

- gen
{
  if (idents) {
    assert(parmdefs == nil);
    gcommalist(idents);
    if (varargs)
      gc(',');
  }
  if (parmdefs) {
    assert(idents == nil);
    gcommalist(parmdefs);
    if (varargs)
      gc(',');
  }
  if (varargs)
    gs("...");
  return self;
}

- synth
{
  if (parmdefs)
    [parmdefs elementsPerform:_cmd];
  return self;
}

@end
 
