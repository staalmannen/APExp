
/*
 * Copyright (c) 1999 David Stes.
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
 * $Id: globwrap.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
 */

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
#include <node.h>
#include <def.h>
#include <symbol.h>
#include <trlunit.h>
#include "globwrap.h"

@implementation Globwrap

- wrap:(GLOBWRAP*)fw
{
  globname = [Symbol str:fw->globname];
  getfun = fw->getfun;
  setfun = fw->setfun;
  return self;
}

- define
{
  if (!trlunit) [self error:"wrap must be defined in trlunit"];
  [trlunit def:globname as:self];
  return self;
}

+ defglobwrapsfor:(GLOBWRAP*)funwraps
{
  GLOBWRAP *e;
  while ((e = funwraps++) && e->globname != NULL && e->getfun != NULL) {
    [[[Globwrap new] wrap:e] define];
  }
  return self;
}

- (BOOL)isextern
{
  return NO;
}

- (BOOL)isstatic
{
  return NO;
}

- value
{
  return (*getfun)();
}

- defval:v
{
  (*setfun)(v);
  return v;
}

@end
 
