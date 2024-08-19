
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
 * $Id: namedecl.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
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
#include "symbol.h"
#include "node.h"
#include "decl.h"
#include "namedecl.h"

@implementation NameDecl

- abstrdecl
{
  return nil;
}

- identifier:aRcvr
{
  identifier = aRcvr;
  return self;
}

- (BOOL)isEqual:x
{
  BOOL ok = YES;
  id y = [x identifier];

  if (identifier && y && ![identifier isEqual:y])
    ok = NO;
  if (!identifier || !y)
    ok = (identifier == y);
  return ok;
}

- (BOOL)canforward
{
  return YES;
}

- (BOOL)isscalartype
{
  return YES;
}

- gen
{
  if (hide) {
    [hide gen];
  } else {
    [identifier gen];
  }
  return self;
}

- hide:x rename:y
{
  if ([identifier isEqual:x]) {
    [y lineno:[identifier lineno]];
    [y filename:[identifier filename]];
    hide = y;
  }
  return self;
}

- identifier
{
  return identifier;
}

- gendef:sym
{
  if (sym)
    [sym gen];
  return self;
}

- synth
{
  return self;
}

- st80
{
  [identifier st80];
  return self;
}

@end
 
