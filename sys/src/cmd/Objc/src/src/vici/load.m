
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
 * $Id: load.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
 */

#include "config.h"
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include <stdio.h> /* FILE */
#include "Object.h" /* Stepstone Object.h assumes #import */
#endif

#if HAVE_DLFCN_H
#include <dlfcn.h>
#endif
#if HAVE_SHLLOAD_H
#include <dl.h>
#include <errno.h>
#endif

#include <ocstring.h>
#include <set.h>
#include <ordcltn.h>
#include <sequence.h>
#include <dictnary.h>

#include "cmd.h"
#include "load.h"
#include "loaded.h"

#include <node.h>

@implementation Load

+ stdmods
{
  /* -stdmods must be done for every translation unit */
  id ld = [[Loaded new] stdmods];
  assert(loadedcltn != nil);
  [loadedcltn add:ld];
  return self;
}

- what:x
{
  what = x;
  return self;
}

- what
{
  return what;
}

- dodlopen
{
#if HAVE_DLFCN_H
  void *handle;
  handle = dlopen([what str],1);
  if (!handle) {
   fprintf(stderr,"vici> can't dlopen() %s\n (%s)\n",[what str],dlerror());
  }
#endif
#if HAVE_SHLLOAD_H
  shlt_t handle;
  handle = shl_load([what str],BIND_IMMEDIATE | BIND_VERBOSE,0L);
  if (!handle) {
    fprintf(stderr,"vici> can't shl_load() %s\n (%s)\n",[what str],strerror(errno));
  }
#endif
  return self;
}

- go
{
  id ld;
  if (what == nil) return self;
  if (strstr([what str],".so")) return [self dodlopen];
  if (!(ld = [loaded atKey:what])) {
    ld = [[Loaded new] filename:what];
  }
  [ld load];
  [loaded atKey:what put:ld];
  [loadedcltn addIfAbsent:ld];
  return self;
}

@end

