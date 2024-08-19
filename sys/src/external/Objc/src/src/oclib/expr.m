
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
 * $Id: expr.m,v 1.1.1.1 2000/06/07 21:09:25 stes Exp $
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
#include "node.h"
#include "expr.h"
#include "type.h"
#include "identxpr.h"
#include "constxpr.h"
#include "castxpr.h"
#include "symbol.h"

id e_nil;
id e_self;
id e_cmd;
id e_super;
id e_aFiler;
id e_ft_id;

@implementation Expr

+ commonexprs
{
  e_self = [[IdentifierExpr new] identifier:s_self];
  e_cmd = [[IdentifierExpr new] identifier:s_cmd];
  e_super = [[IdentifierExpr new] identifier:s_super];
  e_aFiler = [[IdentifierExpr new] identifier:s_aFiler];
  e_ft_id = [[ConstantExpr new] identifier:[Symbol str:"'@'"]];
  e_nil = [[ConstantExpr new] identifier:[Symbol str:"0"]];
  assert(t_id);
  e_nil = [[[CastExpr new] expr:e_nil] cast:t_id];
  return self;
}

- (int)lineno
{
  [self subclassResponsibility];
  return 0;
}

- filename
{
  [self subclassResponsibility];
  return nil;
}

- type
{
  if (type) {
    return type;
  } else {
    [self typesynth];
    assert(type != nil);
    return type;
  }
}

- type:t
{
  type = t;
  return self;
}

- typesynth
{
  return [self subclassResponsibility:_cmd];
}

- gen
{
  return [self subclassResponsibility:_cmd];
}

- identifier
{
  return [self subclassResponsibility:_cmd];
}

- (BOOL)isidentexpr
{
  return NO;
}

- (BOOL)isconstexpr
{
  return NO;
}

@end
 
