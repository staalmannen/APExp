
/*
 * Copyright (c) 1999 David Stes.
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
 * $Id: revmap.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
 */

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include <stdio.h> /* FILE */
#include "Object.h" /* Stepstone Object.h assumes #import */
#endif
#include <ocstring.h>
#include <ordcltn.h>
#include <idarray.h>
#include <node.h>
#include <def.h>
#include <methdef.h>
#include <symbol.h>
#include <trlunit.h>
#include <var.h>
#include <scalar.h>
#include "revmap.h"

id revtab;

@implementation Revmap

- cls
{
  return cls;
}

- cls:x
{
  cls = x;return self;
}
 
- sel
{
  return sel;
}

- sel:x
{
  sel = x;return self;
}

- methdef
{
  return methdef;
}

- methdef:x
{
  methdef = x;return self;
}

- (unsigned)hash
{
  unsigned h = 0;
  h  = ((unsigned)([sel u_str] - (STR)0));
  h ^= ((unsigned)(cls - nil));
  return h;
}

- (BOOL)isEqual:x
{
  /* uniqued string used as selector */
  return (cls == [x cls]) && ([sel u_str] == [[x sel] u_str]);
}

- sentTo:r:(SEL)s
{
  id x = [IdArray with:2,r,sel];
  return [methdef fcall:x];
}

- sentTo:r:(SEL)s:a
{
  id x = [IdArray with:3,r,sel,a];
  return [methdef fcall:x];
}

- sentTo:r:(SEL)s:a:b
{
  id x = [IdArray with:4,r,sel,a,b];
  return [methdef fcall:x];
}

- sentTo:r:(SEL)s:a:b:c
{
  id x = [IdArray with:5,r,sel,a,b,c];
  return [methdef fcall:x];
}

- sentTo:r:(SEL)s:a:b:c:d
{
  id x = [IdArray with:6,r,sel,a,b,c,d];
  return [methdef fcall:x];
}

@end
 
id revmap(id receiver,SEL selector)
{
   id e;
   static id c;
   static id s;
   if (!c) c = [Revmap new];
   if (!s) s = [Scalar new];
   [c cls:receiver->isa];
   [s u_str:selector];
   [c sel:s];
   if ((e=[revtab find:c])) {
     return e;
   } else {
     [revtab error:"revmap not found for '%s'",selector];
   }
}

