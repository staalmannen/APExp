
/*
 * Portable Object Compiler (c) 2025.  All Rights Reserved.
 * $Id: testcase.h,v 1.1 2025/03/15 14:50:40 stes Exp $
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

#ifndef __TESTCASE_H__
#define __TESTCASE_H__

#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include <stdio.h>		/* FILE */
#include "Object.h"		/* Stepstone Object.h assumes #import */
#endif

@interface TestCase : Object
{
}

- run;
- assert:(BOOL)aBoolean;

@end

#endif /* __TESTCASE_H__ */
 
