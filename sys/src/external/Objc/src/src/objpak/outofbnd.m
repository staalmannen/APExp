
/*
 * Portable Object Compiler (c) 2003,2023.  All Rights Reserved.
 * $Id: outofbnd.m,v 1.5 2023/03/12 16:10:57 stes Exp $
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

#include "Exceptn.h"

#include "config.h"
#include "outofbnd.h"
#include "ocstring.h"

@implementation OutOfBounds
- (unsigned) size
{
  return size;
}

- at:(unsigned)n
{
  offset = n;
  return self;
}

+ new:(unsigned)n
{
  return [[super new] new:n];
}

- new:(unsigned)n
{
  size = n;
  return self;
}

- signal
{
  if (!messageText)
    {
      messageText = [String sprintf:"offset %u, size %u", offset, size];
    }
  return [super signal];
}

@end
 
