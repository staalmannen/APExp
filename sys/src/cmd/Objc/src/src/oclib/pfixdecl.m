
/*
 * Copyright (c) 1998,2014 David Stes.
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
 * $Id: pfixdecl.m,v 1.2 2014/02/26 16:18:04 stes Exp $
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
#include "pfixdecl.h"

@implementation PostfixDecl

- abstrdecl
{
  return [[self copy] decl:[decl abstrdecl]];
}

- identifier
{
  return (decl) ? [decl identifier] : nil;
}

- (BOOL)isfunproto
{
  return (decl) ? [decl isfunproto] : NO;
}

- prefix:aRcvr
{
  prefix = aRcvr;
  return self;
}

- decl:aRcvr
{
  decl = aRcvr;
  return self;
}

- postfix:aDecl
{
  postfix = aDecl;
  return self;
}

- star
{
  return [[self copy] decl:[decl star]];
}

- synth
{
  if (prefix)
    [prefix synth];
  if (decl)
    [decl synth];
  if (postfix)
    [postfix synth];
  return self;
}

- gen
{
  if (prefix)
    [prefix gen];
  if (decl)
    [decl gen];
  if (postfix) {
    gc(' ');
    [postfix gen];
  }
  return self;
}

@end
 
