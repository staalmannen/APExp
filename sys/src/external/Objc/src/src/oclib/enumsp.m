
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
 * $Id: enumsp.m,v 1.4 2001/01/25 20:22:26 stes Exp $
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
#include "enumsp.h"
#include "enumtor.h"

@implementation EnumSpec 

- (int)lineno
{
  return [keyw lineno];
}

- filename
{
  return [keyw filename];
}

- keyw:akeyw
{
  keyw = akeyw;
  return self;
}

- name:akeyw
{
  name = akeyw;
  return self;
}

- lbrace:lb
{
  lbrace = lb;
  return self;
}

- rbrace:rb
{
  rbrace = rb;
  return self;
}

- enumtors:aList
{
  /* mind that not all elements are Enumtors (also cppdirects) */
  assert([aList isKindOf:(id) [OrdCltn class]]);
  enumtors = aList;
  return self;
}

- (BOOL)isscalartype
{
  return YES;
}

- (BOOL)isvolatile
{
  return NO;
}

- (BOOL)isrefcounted
{
  return NO;
}

- synth
{
  if (enumtors)
    [enumtors elementsPerform:_cmd];
  return self;
}

- gen
{
  [keyw gen];
  [name gen];
  if (enumtors) {
    int comma = 0;
    int i, n = [enumtors size];

    if (lbrace)
      [lbrace gen];
    else
      gc('{');
    if (n) {
      id e = [enumtors at:0];
      [e gen];
      comma = [e isenumtor];
    }
    for (i = 1; i < n; i++) {
      id e = [enumtors at:i];
      if (comma) gc(',');
      [e gen];
      comma = [e isenumtor];
    }
    if (rbrace)
      [rbrace gen];
    else
      gc('}');
  }
  return self;
}

- (BOOL)canforward
{
  return YES;
}

- (BOOL)isselptr
{
  return NO;
}

@end
 
