
/*
 * Computer Algebra Kit (c) 1993,00 by Comp.Alg.Objects.  All Rights Reserved.
 * $Id: ccltnsq.m,v 1.6 2000/10/12 14:40:25 stes Exp $
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

@implementation CACollectionSequence
- _setUpContent:aCollection
{
  content = aCollection;
  size = [content size];
  return self;
}

+ content:aCollection
{
  return [[super new] _setUpContent:aCollection];
}

- copy
{
  assert (-1 <= index && index <= size);
  return [super copy];
}

- (unsigned) size
{
  return size;
}

- (BOOL) isEmpty
{
  return size == 0;
}

- toFirst
{
  index = -1;
  return self;
}

- toLast
{
  index = size;
  return self;
}

- toElementAt:(int)i
{
  index = i - 1;
  return self;
}

- next
{
  index = (index > size) ? size : index + 1;
  return (0 <= index && index < size) ? [content at : index]:nil;
}

- previous
{
  index = (index < 0) ? -1 : index - 1;
  return (0 <= index && index < size) ? [content at : index]:nil;
}

@end
 
