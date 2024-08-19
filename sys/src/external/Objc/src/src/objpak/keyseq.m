
/*
 * Portable Object Compiler (c) 1997,98.  All Rights Reserved.
 * $Id: keyseq.m,v 1.2 2020/04/16 19:16:07 stes Exp $
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
#include "keyseq.h"
#include "assoc.h"

@implementation KeySequence
/*****************************************************************************
 *
 * Creation
 *
 ****************************************************************************/


- setUpCarrier:aCarrier
{
  carrier = aCarrier;
  return self;
}

+ over:aCarrier
{
  id newObj = [super new];
  [newObj setUpCarrier:aCarrier];
  return newObj;
}

- copy
{
  return [isa over:[carrier copy]];
}

- free
{
  carrier = [carrier free];
  return [super free];
}

/*****************************************************************************
 *
 * Interrogation
 *
 ****************************************************************************/


- (unsigned) size
{
  return [carrier size];
}

/*****************************************************************************
 *
 * Accessing
 *
 ****************************************************************************/


- next
{
  return [[carrier next] key];
}

- peek
{
  return [[carrier peek] key];
}

- previous
{
  return [[carrier previous] key];
}

- first
{
  return [[carrier first] key];
}

- last
{
  return [[carrier last] key];
}

@end
 
