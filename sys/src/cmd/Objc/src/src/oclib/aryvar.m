
/*
 * Copyright (c) 1999,2000 David Stes.
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
 * $Id: aryvar.m,v 1.1.1.1 2000/06/07 21:09:25 stes Exp $
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
#include <ordcltn.h>
#include "node.h"
#include "var.h"
#include "aryvar.h"

@implementation ArrayVariable

- value:v
{
  value = v;
  return self;
}

- value
{
  return value;
}

- (unsigned)size
{
  return [value size];
}

+ new
{
  return [[super new] value: [OrdCltn new]];
}

+ new:(unsigned)x
{
  return [[super new] value: [OrdCltn new:x]];
}

- at:(unsigned)i
{
  return [value at:i];
}

- add:x
{
  [value add:x];
  return self;
}

- addAll:x
{
  [value addAll:x];
  return self;
}

- at:(unsigned)i put:v
{
  [value at:i put:v];
  return self;
}

@end

