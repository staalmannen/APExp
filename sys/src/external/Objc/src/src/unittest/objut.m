
/* 
 * Portable Object Compiler (c) 2025.  All Rights Reserved.
 * $Id: objut.m,v 1.8 2025/12/31 18:15:24 stes Exp $
 *
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
#include <stdlib.h>

#include "testcase.h"
#include "testste.h"
#include "classcnt.h"
#include "bagtest.h"
#include "seqtest.h"
#include "ordctest.h"
#include "factest.h"
#include "perfect.h"
#include "fddtest.h"
#include "mvartest.h"
#include "lgndtest.h"

/* objut (Object Unit Test) is a test program to check newly built libs */

int main(int argc, char *argv[])
{
  id testSuite = [TestSuite new];
#ifndef OBJC_REFCNT
  [testSuite addTest:[ClassCount new]];
#endif
  [testSuite addTest:[BagTest new]];
  [testSuite addTest:[OrdCltnTest new]];
  [testSuite addTest:[SequenceTest new]];
  [testSuite addTest:[FactorialTest new]];
  [testSuite addTest:[PerfectNumberTest new]];
  [testSuite addTest:[LegendreTest new]];
#ifndef OBJC_REFCNT
  [testSuite addTest:[FactorDistinctDegreeTest new]];
  [testSuite addTest:[MultivariateExpansionTest new]];
#endif
  [testSuite run];
  /* always success except when assert() fails */
  exit(0);
}

