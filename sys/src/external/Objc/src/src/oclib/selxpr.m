
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
 * $Id: selxpr.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
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
#include "expr.h"
#include "selxpr.h"
#include "type.h"
#include "trlunit.h"
#include "options.h"
#include "var.h"
#include "scalar.h"

@implementation SelectorExpr

- selector:aRcvr
{
  selector = aRcvr;
  return self;
}

- (int)lineno
{
  return [selector lineno];
}

- filename
{
  return [selector filename];
}

- typesynth
{
  type = t_sel;
  return self;
}

- synth
{
  id method = [trlunit lookupmethod:selector];

  if (!method && o_warnundefined) {
    warn("argument types for '%s' default to 'id'", [selector str]);
  }
  return self;
}

- gen
{
  [selector gen];
  return self;
}

- go
{
#ifdef __PORTABLE_OBJC__
  return [[Scalar new] u_str:selUid([selector str])];
#else
  return nil;
#endif
}

@end
 
