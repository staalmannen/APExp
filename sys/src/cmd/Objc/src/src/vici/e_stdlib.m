
/* 
 * VICI Copyright (c) 1999 David Stes
 *
 * $Id: e_stdlib.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published 
 * by the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include <stdio.h> /* FILE */
#include "Object.h" /* Stepstone Object.h assumes #import */
#endif

#include <ordcltn.h>
#include <node.h>
#include <var.h>
#include <scalar.h>
#include <def.h>
#include <stkframe.h>
#include "cmd.h"
#include "funwrap.h"

static id e_atoi(id aList)
{
   int i = atoi([[aList at:0] u_str]);
   return [Scalar new];
}

static id e_exit(id aList)
{
   int c = [[aList at:0] u_int];
   fprintf(vistdout,"Program exited normally with exit code %d\n",c);
   [topframe exitframe];
}

FUNWRAP stdlibfunwraps[] = {
  {"atoi",&e_atoi},
  {"exit",&e_exit},
  {NULL,NULL},
};

