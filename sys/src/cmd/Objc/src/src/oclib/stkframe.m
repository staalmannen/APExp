
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
 * $Id: stkframe.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
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
#include <dictnary.h>
#include "node.h"
#include "type.h"
#include "stkframe.h"
#include "stmt.h"
#include "compstmt.h"
#include "def.h"
#include "var.h"
#include "scalar.h"
#include "symbol.h"

id topframe;

@implementation Stackframe

- next:x
{
  next = x;
  return self;
}

- previous:x
{
  previous = x;
  return self;
}

- next
{
  return next;
}

- previous
{
  return previous;
}

+ push
{
  id frame = [super new];
  if (topframe) {
    [topframe next:frame];
    [frame previous:topframe];
  }
  topframe = frame;
  return frame;
}
  
+ pop
{
  if (topframe) topframe = [topframe previous];
  return nil;
}

- compound:x
{
  compound = x;
  return self;
}

- def
{
  return def;
}

- def:m
{
  compound = nil;
  def = m;
  return self;
}

- compound
{
  return compound;
}

- lookupself
{
  return [self lookupval:s_self];
}

- lookuplocal:sym
{
  return [compound lookuplocal:sym];
}

- lookupval:sym
{
  if ([vals includesKey:sym]) {
    return [vals atKey:sym]; /* may be nil */
  }
  if ([compound lookuplocal:sym]) {
    [self error:"Variable '%s' was not initialized",[sym str]];
    return self;
  } else { 
    id e = [self enclosing];
    if (e) {
      return [e lookupval:sym];
    } else {
      [self error:"Can't find variable '%s'",[sym str]];
      return nil;
    }
  }
}

- defval:sym as:scalar
{
  if (!vals) {
    vals = [Dictionary new];
  }
  [vals atKey:sym put:scalar];
  return self;
}

- enclosing
{
  id f = [self previous]; 
  if (f) {
    if (compound) {
#ifndef NDEBUG
      id t = [compound enclosing];
      assert(t == [f compound]);
#endif
      return f;
    } else {
      return nil;
    }
  } else {
    return nil;
  }
}

- quitframe:(BOOL)x
{
  quitframe=x;breakframe=x;return self;
}

- (BOOL)quitframe
{
  return quitframe;
}

- breakframe:(BOOL)x
{
  breakframe=x;return self;
}

- (BOOL)breakframe
{
  return breakframe;
}

- contframe:(BOOL)x
{
  contframe=x;return self;
}

- (BOOL)contframe
{
  return contframe;
}

- exitframe
{
  id frm;
  for(frm=self;frm;frm=[frm previous]) {
    [frm quitframe:YES];
  }
  return self;
}

- returnval
{
  return returnval;
}

- returnval:x
{
  returnval=x;return self;
}

- printBtOn:(IOD)d
{
  id frm;
  int c = 0;
  
  for(frm=self;frm;frm=[frm previous]) {
    if ([frm compound] == nil) {
      fprintf(d,"#%d  ",c++);[[frm def] printBtOn:d];
    }
  }

  return self;
}
  
@end
 
