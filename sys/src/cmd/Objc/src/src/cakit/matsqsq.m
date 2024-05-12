
/*
 * Computer Algebra Kit (c) 1993,00 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: matsqsq.m,v 1.6 2000/10/12 14:40:26 stes Exp $
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

#include "cakit.h"

@implementation CAMatrixSequenceSequences
- _setUpContent:aMatrix
{
  content = aMatrix;
  numRows = [content numRows];
  return self;
}

+ content:aMatrix
{
  return [[super new] _setUpContent:aMatrix];
}


- (unsigned) size
{
  return numRows;
}

- (BOOL) isEmpty
{
  return numRows == 0;
}

- toFirst
{
  index = -1;
  return self;
}

- toLast
{
  index = numRows;
  return self;
}

- toElementAt:(int)i
{
  index = i - 1;
  return self;
}

- currentMember
{
  if (0 <= index && index < numRows)
    currentMember = [[content rowAt:index] eachScalar];
  return currentMember;
}

- next
{
  index = (index <= numRows) ? index + 1 : numRows;
  return [self currentMember];
}

- previous
{
  index = (index >= 0) ? index - 1 : -1;
  return [self currentMember];
}

@end
 
