
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
 * $Id: listxpr.m,v 1.1.1.1 2000/06/07 21:09:25 stes Exp $
 */

#include "config.h"
#include <stdlib.h>
#include <assert.h>
#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include <stdio.h> /* FILE */
#include "Object.h" /* Stepstone Object.h assumes #import */
#endif
#include <ordcltn.h>
#include "node.h"
#include "expr.h"
#include "listxpr.h"

@implementation ListExpr

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

- exprs:aRcvr
{
  exprs = aRcvr;
  return self;
}

- synth
{
  [exprs elementsPerform:_cmd];
  return self;
}

- (BOOL)isconstexpr
{
  int i, n;

  for (i = 0, n = [exprs size]; i < n; i++) {
    if (![[exprs at:i] isconstexpr])
      return NO;
  }
  return YES;
}

- gen
{
  if (lbrace)
    [lbrace gen];
  else
    gc('{');
  gcommalist(exprs);
  if (rbrace)
    [rbrace gen];
  else
    gc('}');
  return self;
}

@end
 
