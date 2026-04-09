
/*
 * Portable Object Compiler (c) 2025.  All Rights Reserved.
 * $Id: ordctest.m,v 1.1 2025/03/15 14:50:40 stes Exp $
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
#include "ordctest.h"
#if OBJC_BLOCKS
#include "Block.h"
#endif
#include <objpak.h>

@implementation OrdCltnTest

- run
{
   id s,ordcltn,set;

   printf("Object Unit Test: OrdCltn and Set test\n");

   s = [String str:"hello world"];
   
   ordcltn = [OrdCltn new];
   [ordcltn add:s];
   [ordcltn add:s];

   set = [Set new];
   [set add:s];
   [set add:s];

   [self assert:(([s size] == 11)&&([ordcltn size] == 2)&&([set size] == 1))];
   return self;
}

@end

