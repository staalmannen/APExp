
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
 * $Id: enumtor.m,v 1.1.1.1 2000/06/07 21:09:25 stes Exp $
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
#include "node.h"
#include "enumtor.h"
#include "trlunit.h"

@implementation Enumerator

- (BOOL)isenumtor
{
  return YES;
}

- name:n
{
  name = n;
  return self;
}

- value:v
{
  value = v;
  return self;
}

- (STR)str
{
  return [name str];
}

- (unsigned) hash
{
  return [name hash];
}

- (BOOL)isEqual:x
{
  return strcmp([name str], [x str]) == 0;	/* works for String subcls. */
}

- synth
{
  [trlunit defenumtor:self];
  return self;
}

- gen
{
  [name gen];
  if (value) {
    gc('=');
    [value gen];
  }
  return self;
}
@end
 
