
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
 * $Id: typeof.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
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
#include "typeof.h"
#include "expr.h"
#include "unyxpr.h"
#include "type.h"

@implementation TypeOf

- keyw:kw
{
  keyw = kw;
  return self;
}

- keyw
{
  return keyw;
}

- expr:e
{
  expr = e;
  return self;
}

- expr
{
  return expr;
}

- synth
{
  [expr synth];
  return self;
}

- gen
{
  [keyw gen];gc('(');[expr gen];gc(')');
  return self;
}

- (BOOL)isid
{
  return NO;
}

- (BOOL)isvoid
{
  return NO;
}

- (BOOL)isscalartype
{
  return NO;
}

- (BOOL)canforward
{
  return NO;
}

- (BOOL)isselptr
{
  return NO;
}

@end
 
