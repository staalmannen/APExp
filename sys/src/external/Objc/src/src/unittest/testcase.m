
/*
 * Portable Object Compiler (c) 2025.  All Rights Reserved.
 * $Id: testcase.m,v 1.1 2025/03/15 14:50:40 stes Exp $
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
#include "testcase.h"
#if OBJC_BLOCKS
#include "Block.h"
#endif

@implementation TestCase 

- run
{
   return [self subclassResponsibility];
}

- assert:(BOOL)aBoolean
{
   assert(aBoolean);
   return self;
}

@end

