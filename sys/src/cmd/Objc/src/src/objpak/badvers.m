
/*
 * Portable Object Compiler (c) 2003,2023.  All Rights Reserved.
 * $Id: badvers.m,v 1.4 2023/03/12 16:10:57 stes Exp $
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
#include "badvers.h"
#include "ocstring.h"

@implementation BadVersion
- (int) goodVersion
{
  return goodVersion;
}

- (int) badVersion
{
  return badVersion;
}

- goodVersion:(int)g badVersion:(int)b
{
  goodVersion = g;
  badVersion = b;
  return self;
}

- signal
{
  if (!messageText)
    {
      messageText = [String sprintf:"Expect version %i, got version %i", goodVersion, badVersion];
    }
  return [super signal];
}

@end
 
