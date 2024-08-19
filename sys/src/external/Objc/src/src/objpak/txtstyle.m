
/*
 * Portable Object Compiler (c) 1997,98.  All Rights Reserved.
 * $Id: txtstyle.m,v 1.2 2020/04/16 19:16:09 stes Exp $
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
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include "txtstyle.h"

@implementation TextStyle

+ default
{
  return [self named:"Default"];
}

+ named:(STR)name
{
  return [super str:name];
}


- (STR) name
{
  return [self str];
}


- printOn:(IOD)aFile
{
  fprintf (aFile, "TextStyle %s", [self name]);
  return self;
}

@end
 
