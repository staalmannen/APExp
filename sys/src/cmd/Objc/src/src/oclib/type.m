
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
 * $Id: type.m,v 1.3 2011/06/15 19:06:42 stes Exp $
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
#include <ocstring.h>
#include <ordcltn.h>
#include "node.h"
#include "type.h"
#include "symbol.h"
#include "decl.h"
#include "arydecl.h"
#include "pointer.h"
#include "stardecl.h"
#include "options.h"
#include "structsp.h"
#include "enumsp.h"
#include "var.h"
#include "scalar.h"

id t_unknown;
id t_void;
id t_char;
id t_bool;
id t_int;
id t_uns;
id t_long;
id t_double;
id t_str;
id t_sel;
id t_id;

@implementation Type

+ commontypes
{
  if (!t_unknown) {
    t_unknown = [Type new];
    t_void = [[Type new] addspec:s_void];
    t_char = [[Type new] addspec:s_char];
    t_bool = [[Type new] addspec:s_bool];
    t_int = [[Type new] addspec:s_int];
    t_uns = [[Type new] addspec:s_uns];
    t_long = [[Type new] addspec:s_long];
    t_double = [[Type new] addspec:s_double];
    t_str = [[Type new] addspec:s_str];
    t_sel = [[Type new] addspec:s_sel];
    t_id = [[Type new] addspec:s_id];
  }
  return self;
}

- specs
{
  return specs;
}

- decl
{
  return decl;
}

- abstrspecs:aList
{
  if (aList) {
    specs = aList;
  } else {
    specs = [OrdCltn new];
    [specs add:s_int];		/* C default */
  }
  return self;
}

- checkspec:s
{
  if ([s isKindOf:(id) [Symbol class]])
    return self;
  if ([s isKindOf:(id) [StructSpec class]])
    return self;
  if ([s isKindOf:(id) [EnumSpec class]])
    return self;
  fprintf(stderr, "%s\n", [s name]);
  return nil;
}

- (int)lineno
{
  if (specs) {
    int i,n = [specs size];
    for(i=0;i<n;i++) {
      int no = [[specs at:i] lineno];if (no) return no;
    }
  }
  return 0;
}

- filename
{
  if (specs) {
    int i,n = [specs size];
    for(i=0;i<n;i++) {
      id no = [[specs at:i] filename];if (no) return no;
    }
  }
  return nil;
}

- specs:aList
{
  if (aList) {
    int i, n;
    id typespecs = [OrdCltn new];

    for (i = 0, n = [aList size]; i < n; i++) {
      id s = [aList at:i];

      assert([self checkspec:s]);
      /* filter out storageclass instances */
      if (![s isstorageclass] && ![s isgnuattrib])
	[typespecs add:s];
    }
    return [self abstrspecs:typespecs];
  } else {
    return [self addspec:s_int];	/* C default */
  }
}

- addspec:aSpec
{
  if (!specs)
    specs = [OrdCltn new];
  if (aSpec) {
    assert([self checkspec:aSpec]);
    assert(![aSpec isstorageclass]);
    [specs add:aSpec];
  }
  return self;
}

- abstrdecl:aDecl
{
  decl = aDecl;
  return self;
}

- decl:aDecl
{
  return [self abstrdecl:(aDecl) ? [aDecl abstrdecl] : nil];
}

- (BOOL)haslistinit
{
  return haslistinit;
}

- (BOOL)isstatic
{
  return isstatic;
}

- (BOOL)isextern
{
  return isextern;
}

- (BOOL)definesocu
{
  return !isstatic;
}

- isstatic:(BOOL)flag
{
  isstatic = flag;
  return self;
}

- isextern:(BOOL)flag
{
  isextern = flag;
  return self;
}

- haslistinit:(BOOL)flag
{
  haslistinit = flag;
  return self;
}

- max:aType
{
  if (self == t_unknown || aType == t_unknown)
    return t_unknown;
  return self;
}

- (unsigned)hash
{
  unsigned h = 0;

  if (specs) {
    int i, n;

    h = (n = [specs size]);
    for (i = 0; i < n; i++)
      h = (h << 1) ^ ([[specs at:i] hash]);
  }
  if (decl)
    h ^= [decl hash];
  return h;
}

- (BOOL)isEqual:x
{
  if (self == x) {
    return YES;
  } else {
    id y, z;

    y = [x specs];
    if (specs && y && ![specs isEqual:y])
      return NO;
    if ((!specs || !y) && specs != y)
      return NO;
    z = [x decl];
    if (decl && z && ![decl isEqual:z])
      return NO;
    if ((!decl || !z) && decl != z)
      return NO;
    return YES;
  }
}

- (BOOL)isvoid
{
  if (self == t_void)
    return YES;
  return decl == nil && [specs size] == 1 && [[specs at:0] isvoid];
}

- (BOOL)isid
{
  if (self == t_id)
    return YES;
  return decl == nil && [specs size] == 1 && [[specs at:0] isid];
}

- (BOOL)isrefcounted
{
  int n;
  if (self == t_id) {
    return YES;
  }
  if (decl == nil && (n = [specs size]) > 0) {
    int i;
    for(i=0;i<n;i++) {
      if ([[specs at:i] isvolatile]) return NO;
    }
    return [[specs at:n-1] isrefcounted];
  }
  return NO;
}

- (BOOL)isscalartype
{
  /* same as canforward, except for structs */
  if ([decl ispointer]) {
    return YES;
  } else {
    if (decl == nil || [decl isscalartype]) {
      int i, n;

      /* anything that is defined as something that is scalar */
      for (i = 0, n = [specs size]; i < n; i++) {
	id sp = [specs at:i];

	if ([sp isstorageclass])
	  continue;
	if (![sp isscalartype])
	  return NO;
      }
      return YES;
    } else {
      return NO;
    }
  }
}

- (BOOL)canforward
{
  if ([decl ispointer]) {
    return YES;
  } else {
    if (decl == nil || [decl canforward]) {
      int i, n;

      /* anything that is defined as something that can be forwarded */
      for (i = 0, n = [specs size]; i < n; i++) {
	id sp = [specs at:i];

	if ([sp isstorageclass])
	  continue;
	if (![sp canforward])
	  return NO;
      }
      return YES;
    } else {
      return NO;
    }
  }
}

- (BOOL)isselptr
{
  if ([decl ispointer]) {
    return YES;
  } else {
    if (decl == nil) {
      int i, n;

      /* anything that is defined as a pointer */
      for (i = 0, n = [specs size]; i < n; i++) {
	id sp = [specs at:i];

	if ([sp isstorageclass])
	  continue;
	if (![sp isselptr])
	  return NO;
      }
      return YES;
    } else {
      return NO;
    }
  }
}

- synth
{
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

- genabstrtype
{
  return [self gendef:nil];
}

- gendef:sym
{
  o_nolinetags++;
  if (specs)
    [specs elementsPerform:@selector(gen)];
  if (decl) {
    [decl gendef:sym];
  } else {
    if (sym)
      [sym gen];
  }
  o_nolinetags--;
  return self;
}

- dot:sym
{
  if (decl)
    return nil;
  if ([specs size] != 1)
    return nil;
  return [[specs at:0] dot:sym];
}

- star
{
  if (decl == nil && [specs size] == 1)
    return [[specs at:0] star];
  if (decl == nil && [specs size] != 1)
    return nil;
  return [[self copy] abstrdecl:[decl star]];
}

- ampersand
{
  id s, p;

  p = [Pointer new];
  s = [[[StarDecl new] pointer:p] decl:decl];
  return [[self copy] abstrdecl:s];
}

- funcall
{
  if (decl == nil && [specs size] == 1)
    return [[specs at:0] funcall];
  if (decl == nil && [specs size] != 1)
    return nil;
  return [[self copy] abstrdecl:[decl funcall]];
}

- zero
{
  if ([self isEqual:t_id]) return nil;
  if ([self isEqual:t_str]) return [[Scalar new] u_str:NULL];
  if ([decl isKindOf:(id)[ArrayDecl class]] && [specs size] == 1) {
    id s;
    int n = [[decl expr] asInt];
    s = [Symbol new:n];
    return [[Scalar new] u_str:[s strCopy]];
  }
  if (decl == nil && [specs size] == 1) {
    return [[specs at:0] zero];
  }
  return nil;
}

- peekAt:(char*)ptr
{
  if (decl == nil && [specs size] == 1) {
    return [[specs at:0] peekAt:ptr];
  } else {
    [self notImplemented:_cmd];
    return 0;
  }
}

- poke:v at:(char*)ptr
{
  if (decl == nil && [specs size] == 1) {
    return [[specs at:0] poke:v at:ptr];
  } else {
    [self notImplemented:_cmd];
    return 0;
  }
}

- (int)bytesize
{
  if (decl == nil && [specs size] == 1) {
    return [[specs at:0] bytesize];
  } else {
    [self notImplemented:_cmd];
    return 0;
  }
}

@end
 
