
/*
 * Portable Object Compiler (c) 2025.  All Rights Reserved.
 * $Id: testste.m,v 1.2 2025/12/31 18:15:24 stes Exp $
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
#include <objpak.h>
#include "testste.h"
#include "testcase.h"
#if OBJC_BLOCKS
#include "Block.h"
#endif

@implementation TestSuite

- tests:c
{
  tests = c;
  return self;
}

+ new
{
  return [[super new] tests:[OrderedCollection new]];
}

- addTest:aTestCase
{
   [tests add:aTestCase];
   return self;
}

- run
{
   [tests elementsPerform:@selector(run)];
   return self;
}

@end

