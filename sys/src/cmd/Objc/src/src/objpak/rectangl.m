
/*
 * Portable Object Compiler (c) 1997,98,99.  All Rights Reserved.
 * $Id: rectangl.m,v 1.2 2020/04/16 19:16:08 stes Exp $
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
#include "rectangl.h"

@implementation Rectangle

/*****************************************************************************
 *
 * Creation
 *
 ****************************************************************************/


+ new
{
  return [self origin:[Point new] corner:[Point new]];
}

+ origin:p corner:q
{
  return [[super new] origin:p corner:q];
}

- origin:p extent:q
{
  return [self notImplemented:_cmd];	/* for Stepstone compilation */
}

+ origin:p extent:q
{
  return [[super new] origin:p extent:q];
}

+ origin:(int)x1:(int)y1 corner:(int)x2:(int)y2
{
  return [[[super new] origin:x1:y1] corner:x2:y2];
}

+ origin:(int)x:(int)y extent:(int)w:(int)h
{
  return [[[super new] origin:x:y] extent:w:h];
}

- copy
{
  return [[super copy] origin:[origin copy] corner:[corner copy]];
}

- deepCopy
{
  return [[super copy] origin:[origin deepCopy] corner:[corner deepCopy]];
}

- free
{
  corner = [corner free];
  origin = [origin free];
  return [super free];
}

/*****************************************************************************
 *
 * Motion
 *
 ****************************************************************************/


- origin:p
{
  origin = p;
  return self;
}

- corner:q
{
  corner = q;
  return self;
}

- origin:p corner:q
{
  [self origin:p];
  [self corner:q];
  return self;
}

- extent:(int)w:(int)h
{
  [self corner:[Point x:[origin x] + w y:[origin y] + h]];
  return self;
}

- extent:q
{
  [self extent:[q x]:[q y]];
  return self;
}

- origin:(int)x1:(int)y1
{
  return [self origin:[Point x:x1 y:y1]];
}

- corner:(int)x1:(int)y1
{
  return [self corner:[Point x:x1 y:y1]];
}

/*****************************************************************************
 *
 * Comparing
 *
 ****************************************************************************/


- (BOOL) contains:aPoint
{
  int xLoc = [aPoint x];
  int yLoc = [aPoint y];
  return ([origin x] <= xLoc && xLoc <= [corner x])
    && ([origin y] <= yLoc && yLoc <= [corner y]);
}

- (unsigned) hash
{
  return [origin hash] ^ [corner hash];
}

- (BOOL) isEqual:aRectangle
{
  /* Stepstone isKindOf: takes id but isa is SHR */
  return [aRectangle isKindOf:(id) isa] &&
    [origin isEqual:[aRectangle origin]] &&
    [corner isEqual:[aRectangle corner]];
}

/*****************************************************************************
 *
 * Interrogation
 *
 ****************************************************************************/


- (int) left
{
  return [origin x];
}

- (int) right
{
  return [corner x];
}

- (int) top
{
  return [origin y];
}

- (int) bottom
{
  return [corner y];
}

- (int) width
{
  return [corner x] - [origin x];
}

- (int) height
{
  return [corner y] - [origin y];
}

- origin
{
  return origin;
}

- topLeft
{
  return origin;
}

- topRight
{
  return [Point x:[corner x] y:[origin y]];
}

- topCenter
{
  return [Point x:[corner x] + [self width] / 2 y:[origin y]];
}

- corner
{
  return corner;
}

- bottomLeft
{
  return [Point x:[origin x] y:[corner y]];
}

- bottomCenter
{
  return [Point x:[corner x] + [self width] / 2 y:[corner y]];
}

- bottomRight
{
  return corner;
}

- center
{
  int x = [self left] + [self width] / 2;
  int y = [self top] + [self height] / 2;
  return [Point x:x y:y];
}

- leftCenter
{
  int y = [self top] + [self height] / 2;
  return [Point x:[origin x] y:y];
}

- rightCenter
{
  int y = [self top] + [self height] / 2;
  return [Point x:[corner x] y:y];
}

- extent
{
  return [Point x:[self width] y:[self height]];
}

- quickMerge:rect
{
  id tmp;
  int ax1, ay1, ax2, ay2;
  int bx1, by1, bx2, by2;
  int minx, miny, maxx, maxy;

  tmp = [self origin];
  ax1 = [tmp x];
  ay1 = [tmp y];
  tmp = [self corner];
  ax2 = [tmp x];
  ay2 = [tmp y];
  tmp = [rect origin];
  bx1 = [tmp x];
  by1 = [tmp y];
  tmp = [rect corner];
  bx2 = [tmp x];
  by2 = [tmp y];

  minx = (ax1 < bx1) ? ax1 : bx1;
  miny = (ay1 < by1) ? ay1 : by1;
  maxx = (ax2 > bx2) ? ax2 : bx2;
  maxy = (ay2 > by2) ? ay2 : by2;

  if (ax1 == minx && ay1 == miny && ax2 == maxx && ay2 == maxy)
    {
      return self;
    }
  else
    {
      return [Rectangle origin:minx:miny corner:maxx:maxy];
    }
}

/*****************************************************************************
 *
 * Arithmetic
 *
 ****************************************************************************/


- moveBy:aPoint
{
  [origin moveBy:aPoint];
  [corner moveBy:aPoint];
  return self;
}

- translateBy:p
{
  return [isa origin:[origin translateBy:p] corner:[corner translateBy:p]];
}

- align:p1 with:p2
{
  int x = [p2 x] - [p1 x];
  int y = [p2 y] - [p1 y];
  return [isa origin:[origin x] + x:[origin y] + y corner:[corner x] + x:[corner y] + y];
}

/*****************************************************************************
 *
 * Printing
 *
 ****************************************************************************/

- printOn:(IOD)aFile
{
  fprintf (aFile, "(");
  [origin printOn:aFile];
  fprintf (aFile, ",");
  [corner printOn:aFile];
  fprintf (aFile, ")");
  return self;
}

@end
 
