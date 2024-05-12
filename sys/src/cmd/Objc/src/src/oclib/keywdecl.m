
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
 * $Id: keywdecl.m,v 1.1.1.1 2000/06/07 21:09:25 stes Exp $
 */

#include "config.h"
#include <stdlib.h>
#include <assert.h>
#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include <stdio.h> /* FILE */
#include "Object.h" /* Stepstone Object.h assumes #import */
#endif
#include <ocstring.h>
#include "node.h"
#include "decl.h"
#include "keywdecl.h"
#include "selector.h"
#include "type.h"
#include "def.h"

@implementation KeywDecl

- identifier
{
  return arg;
}

- keyw
{
  return keyw;
}

- keyw:sel
{
  keyw = sel;
  return self;
}

- cast
{
  return cast;
}

- cast:c
{
  cast = c;
  return self;
}

- (unsigned)typehash
{
  return (cast) ? [cast hash] : [t_id hash];
}

- (BOOL)typeEqual:x
{
  id a = cast;
  id b = [x cast];

  if (!a)
    a = t_id;
  if (!b)
    b = t_id;
  return [a isEqual:b];
}

- hide:x rename:y
{
  if ([arg isEqual:x])
    hide = y;
  return self;
}

- arg:a
{
  arg = a;
  return self;
}

- selcons:sel
{
  if (keyw)
    [sel add:keyw];
  [sel addcol];
  return self;
}

- genparm
{
  id x = (hide) ? hide : arg;

  if (cast) {
    [cast gendef:x];
  } else {
    [t_id gendef:x];		/* Objective C default */
  }
  return self;
}

- gencommaparm
{
  gc(',');
  return [self genparm];
}

- (BOOL)canforward
{
  return (cast) ? [cast canforward] : YES;
}

- (BOOL)isid
{
  return (cast) ? [cast isid] : YES;
}

- (BOOL)isselptr
{
  return (cast) ? [cast isselptr] : YES;
}

- gendef:sym
{
  if (cast) {
    [cast gendef:sym];
  } else {
    gs("id");			/* Objective C default */
    if (sym)
      gs([sym str]);
  }
  return self;
}

- gendisparg
{
  gs("args->");
  [arg gen];
  return self;
}

- gendispargsintostruct
{
  gs("args.");
  [arg gen];
  gc('=');
  [arg gen];
  gc(';');
  gc('\n');
  return self;
}

- gen
{
  return self;
}

- synth
{
  assert(curdef);
  assert(arg);
  [curdef defparm:arg astype:(cast) ? cast : t_id];
  return self;
}

- st80
{
  if (keyw)
    [keyw st80];
  gc(':');
  [arg st80];
  return self;
}

@end
 
