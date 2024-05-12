
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
 * $Id: structsp.m,v 1.4 2001/01/25 20:22:26 stes Exp $
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
#include <dictnary.h>
#include "node.h"
#include "structsp.h"
#include "decl.h"
#include "symbol.h"
#include "type.h"
#include "trlunit.h"
#include "options.h"

id curstruct;

@implementation StructSpec 

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

- defs:akeyw
{
  defs = akeyw;
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

- (unsigned) hash
{
  return [name hash];
}

- (STR) str
{
  return [name str];
}

- (BOOL)isEqual:x
{
  if (!name)
    return self == x;
  /* so that comparison to Symbol works */
  return (self == x) ? YES : strcmp([name str], [x str]) == 0;
}

- synth
{
  id outerstruct = curstruct;
  curstruct = self;
  if (defs) {
    [defs elementsPerform:_cmd];
    if (name)
      [trlunit defstruct:self];	/* no point in registering unnamed */
  }
  curstruct = outerstruct;
  return self;
}

- gen
{
  [keyw gen];
  if (name)
    [name gen];			/* it may be unnamed */
  if (defs) {
    if (lbrace)
      [lbrace gen];
    else
      gc('{');
    [defs elementsPerform:_cmd];
    if (rbrace)
      [rbrace gen];
    else
      gc('}');
  }
  return self;
}

- (BOOL)isscalartype
{
  return NO;
}

- (BOOL)isvolatile
{
  return NO;
}

- (BOOL)isrefcounted
{
  return NO;
}

- (BOOL)canforward
{
  /* YES unless compiler would not support struct assignment ! */
  return o_structassign;
}

- (BOOL)isselptr
{
  return NO;
}

- lookupcomp:c
{
  return (compdic) ? [compdic atKey : c]:nil;
}

- defcomp:sym astype:t
{
  if (!compdic) {
    compdic = [Dictionary new];
    compnames = [OrdCltn new];
    comptypes = [OrdCltn new];
  }
  [compdic atKey:sym put:t];
  [compnames add:sym];
  [comptypes add:t];
  return self;
}

- dot:sym
{
  if (compdic) {
    return [compdic atKey:sym];
  } else {
    if (name) {
      id s = [trlunit lookupstruct:self];

      if (!s) {
	warnat(sym, "incomplete definition of struct '%s'", [name str]);
	return nil;
      } else {
	return [s dot:sym];
      }
    } else {
      return nil;
    }
  }
}

@end
 
