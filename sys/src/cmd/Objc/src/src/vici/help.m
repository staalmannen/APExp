
/*
 * Copyright (c) 1999 David Stes.
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
 *
 * $Id: help.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
 */

#include "config.h"
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>

#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include <stdio.h> /* FILE */
#include "Object.h" /* Stepstone Object.h assumes #import */
#endif
#include <ocstring.h>
#include <set.h>
#include <ordcltn.h>
#include <sequence.h>
#include <dictnary.h>

#include <node.h>
#include "cmd.h"
#include "help.h"

@implementation Help

- go
{
  printf("List of VICI commands:\n\n");
  printf("q -- quit\n");
  printf("r -- run a program\n");
  printf("br function -- put a breakpoint on function\n");
  printf("!cmd -- shell escape, run 'cmd'\n");
  printf("load file -- load Objective-C file\n");
  return self;
}

@end

