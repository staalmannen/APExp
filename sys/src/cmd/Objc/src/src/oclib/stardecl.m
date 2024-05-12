
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
 * $Id: stardecl.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
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
#include "stardecl.h"
#include "pointer.h"

@implementation StarDecl

- abstrdecl
{
  if (decl) {
    id x = [decl abstrdecl];

    if (x) {
      return [[[StarDecl new] decl:x] pointer:pointer];
    } else {
      return pointer;
    }
  } else {
    return pointer;
  }
}

- pointer:aPointer
{
  pointer = aPointer;
  return self;
}

- decl:aDecl
{
  decl = aDecl;
  return self;
}

- identifier
{
  return (decl) ? [decl identifier] : nil;
}

- (BOOL)isfunproto
{
  return (decl) ? [decl isfunproto] : NO;
}

- (BOOL)ispointer
{
  return YES;
}

- (BOOL)canforward
{
  return YES;
}

- (BOOL)isscalartype
{
  return YES;
}

- hide:x rename:y
{
  if (decl)
    [decl hide:x rename:y];
  return self;
}

- star
{
  if (decl) {
    return [[self copy] decl:[decl star]];
  } else {
    id p = [pointer star];

    return (p) ? [[self copy] pointer : p]:nil;
  }
}

- funcall
{
  if (decl) {
    id p = [decl funcall];

    if (p)
      return [[self copy] decl:p];
    if (pointer)
      return [[self copy] decl:nil];
    return nil;
  } else {
    return nil;
  }
}

- gen
{
  [pointer gen];
  if (decl)
    [decl gen];
  return self;
}

- gendef:sym
{
  if (decl) {
    [pointer gen];
    [decl gendef:sym];
  } else {
    [pointer gendef:sym];
  }
  return self;
}

- synth
{
  if (decl)
    [decl synth];
  return self;
}

- st80
{
  if (decl)
    [decl st80];
  return self;
}

@end
 
