
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
 * $Id: msgwrap.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
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
#include <set.h>
#include <node.h>
#include <def.h>
#include <symbol.h>
#include <trlunit.h>
#include <decl.h>
#include <keywdecl.h>
#include <var.h>
#include <scalar.h>
#include <expr.h>
#include <method.h>
#include <selector.h>
#include <msgxpr.h>
#include "msgwrap.h"
#include "revmap.h"

@implementation Mesgwrap

- wrap:(MSGWRAP*)w:e
{
  efun = w->efun ;
  trapfun = w->trapfun ;
  [self method:e];
  return self;
}

+ defmsgwrapsfor:(MSGWRAP*)w
{
  MSGWRAP *m;
  msgwraps = [Set new];
  while ((m = w++) && m->efun != NULL) {
    id *t;
    int i;
    id e = [Method new];
    [e restype:*m->rtyp];
    if (m->atyp[0]) {
      id kw = [OrdCltn new];
      for(i=0;i<MSGWRAPNARGS && m->atyp[i]!=NULL;i++) {
        id k = [KeywDecl new];
        [k cast:*m->atyp[i]];
        [kw add:k];
      }
      [e keywsel:kw];
    } else {
      [e unarysel:[Selector new]];
    }
    [msgwraps add:[[self new] wrap:m:e]];
  }
  return self;
}

- send:(IMP)i sel:(SEL)sel with:kw to:rcvr
{
  return (*efun)(i,rcvr,sel,kw);
}

- (IMP)methodFor:(SEL)s cls:c methdef:m
{
  id n = [Revmap new];
  [n cls:c];
  [n sel:[[Scalar new] u_str:s]];
  [n methdef:m];
  if (!revtab) revtab = [Set new];
  [revtab add:n];
  return trapfun;
}

@end
 
