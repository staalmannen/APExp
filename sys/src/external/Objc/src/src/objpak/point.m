
/*
 * Portable Object Compiler (c) 1997,98,99.  All Rights Reserved.
 * $Id: point.m,v 1.2 2020/04/16 19:16:08 stes Exp $
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
#include "point.h"
#include "ascfiler.h"

@implementation Point

/*****************************************************************************
 *
 * Creation
 *
 ****************************************************************************/


+ new
{
  return [self x:0 y:0];
}

+ x:(int)x y:(int)y
{
  return [[super new] x:x y:y];
}

/*****************************************************************************
 *
 * Instance Variables
 *
 ****************************************************************************/


- x:(int)x y:(int)y
{
  xLoc = x;
  yLoc = y;
  return self;
}

- x:(int)x
{
  xLoc = x;
  return self;
}

- y:(int)y
{
  yLoc = y;
  return self;
}

- (int) x
{
  return xLoc;
}

- (int) y
{
  return yLoc;
}

/*****************************************************************************
 *
 * Comparing
 *
 ****************************************************************************/


- (unsigned) hash
{
  return xLoc ^ yLoc;
}

- (BOOL) isEqual:aPoint
{
  /* Stepstone isKindOf: takes id but isa is SHR */
  return [aPoint isKindOf:(id) isa]
    && [aPoint x] == xLoc && [aPoint y] == yLoc;
}

- (BOOL) isBelow:aPoint
{
  return yLoc > [aPoint y];
}

- (BOOL) isAbove:aPoint
{
  return yLoc < [aPoint y];
}

- (BOOL) isLeft:aPoint
{
  return xLoc < [aPoint x];
}

- (BOOL) isRight:aPoint
{
  return xLoc > [aPoint x];
}

/*****************************************************************************
 *
 * Point Arithmetic
 *
 ****************************************************************************/


- moveBy:aPoint
{
  xLoc += [aPoint x];
  yLoc += [aPoint y];
  return self;
}

- moveBy:(int)x:(int)y
{
  xLoc += x;
  yLoc += y;
  return self;
}

- moveTo:aPoint
{
  xLoc = [aPoint x];
  yLoc = [aPoint y];
  return self;
}

- plus:aPoint
{
  return [isa x:xLoc + [aPoint x] y:yLoc + [aPoint y]];
}
- translateBy:aPoint
{
  return [isa x:xLoc + [aPoint x] y:yLoc + [aPoint y]];
}

/*****************************************************************************
 *
 * Printing
 *
 ****************************************************************************/

- printOn:(IOD)aFile
{
  printf ("(%i,%i)", xLoc, yLoc);
  return self;
}

#ifdef __PORTABLE_OBJC__
- fileOutOn:aFiler
{
  [super fileOutOn:aFiler];
  [aFiler fileOut:&xLoc type:'i'];
  [aFiler fileOut:&yLoc type:'i'];
  return self;
}

- fileInFrom:aFiler
{
  [super fileInFrom:aFiler];
  [aFiler fileIn:&xLoc type:'i'];
  [aFiler fileIn:&yLoc type:'i'];
  return self;
}
#endif /* __PORTABLE_OBJC__ */

@end
 
