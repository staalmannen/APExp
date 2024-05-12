
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
 * $Id: gatrdecl.m,v 1.2 2011/06/15 19:06:42 stes Exp $
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
#include "gatrdecl.h"

@implementation GnuAttribDecl

- keyw:k
{
  keyw = k;
  return self;
}

- attribs:aList
{
  attribs = aList;
  return self;
}

- synth
{
  [attribs elementsPerform:_cmd];
  return self;
}

- (BOOL)isgnuattrib
{
   return YES;
}

- gen
{
  [keyw gen];
  gs("((");
  gcommalist(attribs);
  gs("))");
  return self;
}

@end
 
