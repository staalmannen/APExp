
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
 * $Id: arydecl.m,v 1.1.1.1 2000/06/07 21:09:25 stes Exp $
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
#include "decl.h"
#include "arydecl.h"

@implementation ArrayDecl

- decl
{
  return decl;
}

- expr
{
  return expr;
}

- decl:aRcvr
{
  decl = aRcvr;
  return self;
}

- star
{
  if (decl) {
    return [[self copy] decl:[decl star]];
  } else {
    return nil;
  }
}

- abstrdecl
{
  if (decl) {
    id x = [decl abstrdecl];

    return [[self copy] decl:x];
  } else {
    return self;
  }
}

- (unsigned)hash
{
  unsigned h = 0;

  if (decl)
    h ^= [decl hash];
  if (expr)
    h ^= [expr hash];
  return h;
}

- (BOOL)isEqual:x
{
  id a, b;

  if (self == x)
    return YES;
  a = [x decl];
  if (decl && a && ![decl isEqual:a])
    return NO;
  if ((!decl || !a) && (decl != a))
    return NO;
  b = [x expr];
  if (expr && b && ![expr isEqual:b])
    return NO;
  if ((!expr || !b) && (expr != b))
    return NO;
  return YES;
}

- identifier
{
  return (decl) ? [decl identifier] : nil;
}

- (BOOL)isfunproto
{
  return (decl) ? [decl isfunproto] : NO;
}

- expr:aRcvr
{
  expr = aRcvr;
  return self;
}

- gendef:sym
{
  if (decl) {
    [decl gendef:sym];
  } else {
    if (sym)
      [sym gen];
  }
  gc('[');
  if (expr)
    [expr gen];
  gc(']');
  return self;
}

- gen
{
  if (decl)
    [decl gen];
  gc('[');
  if (expr)
    [expr gen];
  gc(']');
  return self;
}

- st80
{
  if (decl)
    [decl st80];
  return self;
}

@end
 
