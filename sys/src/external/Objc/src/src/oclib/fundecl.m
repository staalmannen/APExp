
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
 * $Id: fundecl.m,v 1.1.1.1 2000/06/07 21:09:25 stes Exp $
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
#include "decl.h"
#include "fundecl.h"
#include "parmlist.h"
#include "pointer.h"
#include "precdecl.h"
#include "options.h"

@implementation FunctionDecl

- abstrdecl
{
  id x = [decl abstrdecl];

  if (x) {
    return [[self copy] decl:x];
  } else {
    x = [[PrecDecl new] decl:[Pointer new]];
    return [[self copy] decl:x];
  }
}

- (BOOL)isfunproto
{
  return YES;
}

- decl:aRcvr
{
  decl = aRcvr;
  return self;
}

- args:aList
{
  args = aList;
  return self;
}

- identifier
{
  return [decl identifier];
}

- gendef:sym
{
  if (decl) {
    [decl gendef:sym];
  } else {
    if (sym)
      [sym gen];
  }
  gc('(');
  if (args)
    [args gen];
  gc(')');
  return self;
}

- gen
{
  if (decl)
    [decl gen];
  gc('(');
  if (args)
    [args gen];
  gc(')');
  return self;
}

- star
{
  return [[self copy] decl:[decl star]];
}

- funcall
{
  if (decl == nil || [decl star] == nil)
    return nil;			/* success */
  return [[self copy] decl:[decl funcall]];
}

- synth
{
  if (decl)
    [decl synth];
  if (args)
    [args synth];
  return self;
}

@end
 
