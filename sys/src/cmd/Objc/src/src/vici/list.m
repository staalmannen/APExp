
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
 * $Id: list.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
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
#include <symbol.h>

#include "cmd.h"
#include "list.h"
#include "loaded.h"

id listfile;
int listlineno;

@implementation List

- what:x
{
  what = x;
  return self;
}

- what
{
  return what;
}

- listcurrent
{
  if (listfile) {
    int a,b;
    char buf[4096];
    char *s = [listfile str];
    a = listlineno - 5;
    a = (a<1)?1:a;
    b = a + 10;
    assert(strlen(s) < 4000);
    sprintf(buf,"sed -n %d,%dp %s",a,b,s); 
    system(buf);
    listlineno+=10;
  }
  return self;
}

- go
{
  id ld;

  if (what == nil) return [self listcurrent];

  assert([what isKindOf:(id)[Symbol class]]);
  ld = [loaded atKey:what];
  if (ld) { listlineno=1;listfile=what;return [self listcurrent]; }
  
  fprintf(stderr,"vici: don't know how to list %s\n",[what str]);
  return self;
}

@end

