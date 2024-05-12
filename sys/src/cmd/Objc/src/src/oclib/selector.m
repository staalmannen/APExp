
/*
 * Copyright (c) 1998 David Stes.
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
 * $Id: selector.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
 */

#include "config.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include <stdio.h> /* FILE */
#include "Object.h" /* Stepstone Object.h assumes #import */
#endif
#include <ocstring.h>
#include "node.h"
#include "selector.h"
#include "trlunit.h"
#include "options.h"

@implementation Selector

- add:comp
{
  [self concatSTR:[comp str]];
  if (!filename) {
    lineno = [comp lineno];
    filename = [comp filename];
  }
  return self;
}

- (int)lineno
{
  return lineno;
}

- filename
{
  return filename;
}

- addcol
{
  [self concatSTR:":"];
  return self;
}

- gen
{
  if (!o_seltranslation) {
    gf("\"%s\"", [self str]);
  } else {
    int offset = [trlunit seloffset:self];

    if (o_checkbind) {
      gs("((selTransTbl)?");
    }
    gs("selTransTbl[");
    if (o_comments) {
      gf("/* %s */", [self str]);
    }
    gf("%i]", offset);
    if (o_checkbind) {
      gf(":objcrt_bindError(\"%s\"))", [trlunit moddescname]);
    }
  }

  return self;
}

- st80
{
  gs([self str]);
  return self;
}

@end
 
