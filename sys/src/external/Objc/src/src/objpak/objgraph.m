
/*
 * Portable Object Compiler (c) 1998.  All Rights Reserved.
 * $Id: objgraph.m,v 1.2 2020/04/16 19:16:07 stes Exp $
 */

/*
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
 */

#include "config.h"
#include "objgraph.h"

@implementation ObjGraph

/*
 * (unused) class for compatibility with Stepstone runtime
 */

+ over:anId
{
  return [self notImplemented:_cmd];
}

- over:anId unique:(BOOL)flag
{
  return [self notImplemented:_cmd];
}

+ over:anId unique:(BOOL)flag
{
  return [self notImplemented:_cmd];
}

- (unsigned) size
{
  [self notImplemented:_cmd];
  return 0;
}

- error:(STR)fmt,...
{
  [self notImplemented:_cmd];
  return self;
}

- add:anObject
{
  [self notImplemented:_cmd];
  return self;
}

@end
 
