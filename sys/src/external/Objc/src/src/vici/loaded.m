
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
 * $Id: loaded.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
 */

#include "config.h"
#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <time.h>
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
#include <trlunit.h>
#include <options.h>
#include <def.h>
#include <util.h>
#include <symbol.h>
#include <type.h>

#include <expr.h>
#include <msgxpr.h>
#include "msgwrap.h"

#include "cmd.h"
#include "loaded.h"
#include "funwrap.h"
#include "globwrap.h"

id loaded;
id loadedcltn;
static id cppcmd;

@implementation Loaded

+ initialize
{
  loaded = [Dictionary new];
  loadedcltn = [OrdCltn new];
  cppcmd = [String str:CPPCMD];
  loadedmodules = self;
  return self;
}

+ make
{
  int i,n;
  for(i=0,n=[loadedcltn size];i<n;i++) [[loadedcltn at:i] silentload:YES];
  return self;
}

- trlunit
{
  return unit;
}

- filename
{
  return filename;
}

- filename:x
{ 
  filename = x;
  return self;
}
  
- (time_t)savetime
{
  return savetime;
}

- savetime:(time_t)t
{
  savetime = t;
  return self;
}

void setfirstlinetag(void)
{
  /* initialize linetag mechanism */

  inlineno = 1;
  if (o_srcfilename) {
    infilename = [String str:o_srcfilename];
  } else {
    if (o_infile) {
      infilename = [String str:o_infile];
    } else {
      infilename = [String str:"-=stdin=-"];
    }
  }

  assert(trlunit != nil);
  [trlunit setmodversion:"@NAME@"];
  [trlunit setmodname:[infilename str]];

  if (o_vms) {
    definebuiltinfun("__VA_START_BUILTIN");
    definebuiltinfun("__IS_X_FLOAT_BUILTIN");
    definebuiltintype("__int64");
  }

  if (o_gnu) {
    definebuiltinfun("__builtin_saveregs");
    definebuiltinfun("__builtin_classify_type");
    definebuiltinfun("__builtin_isfloat");
    definebuiltinfun("__builtin_classof");
    definebuiltinfun("__alignof__");
    definebuiltinfun("__builtin_alignof");
    definebuiltinfun("__builtin_next_arg");
    definebuiltinfun("__builtin_alloca");
    definebuiltinfun("__builtin_memcpy");
    definebuiltinfun("__builtin_memset");
    definebuiltinfun("__builtin_fabs");
    definebuiltinfun("__builtin_fabsl");
    definebuiltinfun("__builtin_fabsf");
    definebuiltinfun("__builtin_constant_p");
    definebuiltinvar("__PRETTY_FUNCTION__");
    definebuiltinvar("_VA_FP_SAVE_AREA");
  }
}

- stdmods
{
  trlunit = (unit = [TranslationUnit new]);
  assert(t_id != nil);
  if (!msgwraps) [Mesgwrap defmsgwrapsfor:stdmsgwraps];
  [Funwrap defwrapsfor:stdiofunwraps];
  [Funwrap defwrapsfor:stdlibfunwraps];
  [Funwrap defwrapsfor:ctypefunwraps];
  [Funwrap defwrapsfor:stringfunwraps];
  [Globwrap defglobwrapsfor:stdioglobwraps];
  trlunit = nil;
  return self;
}

- compile
{
  id buf;
  FILE *f;
  assert(cppcmd != nil && filename != nil);
  buf = [[[cppcmd copy] concatSTR:" "] concat:filename];
  if ((f = popen([buf str],"r"))) {
    extern int cmdmode;
    extern int yyparse();
    extern void yyrestart(FILE *);
    cmdmode = 0;
    o_srcfilename = [filename str];
    trlunit = (unit = [TranslationUnit new]);
    setfirstlinetag();
    o_outputcode = 0;
    yyrestart(f);
    yyparse();
    trlunit = nil;
    pclose(f);
  } else {
    fprintf(vistdout,"vici: problem running %s %s\n",[cppcmd str],[filename str]);
  }
  return self;
}
  
- silentload:(BOOL)silent
{
  if (filename) {
  struct stat st;
  if (stat([filename str],&st) == -1) {
    fprintf(vistdout,"vici: can't stat %s (%s)\n",[filename str],strerror(errno));
    return self;
  }
  if (savetime == st.st_ctime) {
     if (!silent) {
     fprintf(vistdout,"Nothing to be done for %s (file is up to date)\n",[filename str]);
     }
  } else {
     savetime = st.st_ctime;
     fprintf(vistdout,"Loading %s ... \n",[filename str]);
     [self compile];
     [unit go];
  }
  }
  return self;
}

- load
{
  return [self silentload:NO];
}

+ reset
{
  int i,n;
  for(i=0,n=[loadedcltn size];i<n;i++) {
    id t,b;
    b = [loadedcltn at:i];
    t = [b trlunit];
    [t reset];
  }
  return self;
}

+ resolve:sym
{
  id x,a;
  int i,n;
  for(i=0,x=nil,n=[loadedcltn size];i<n;i++) {
    id y,t,b;
    b = [loadedcltn at:i];
    t = [b trlunit];
    y = [t lookupdef:sym];
    if (y != nil) {
      if (x) {
	id f = [a filename];
	id g = [b filename];
        fprintf(vistdout,"vici: multiple definitions for %s\n",[sym str]);
        if (f) fprintf(vistdout,"vici: using definition from %s\n",[f str]);
        if (g) fprintf(vistdout,"vici: ignoring definition from %s\n",[g str]);
      } else {
	a = b;
        x = y;
      }
    }
  }
  if (!x) {
    [self error:"Can't resolve '%s' (no such function)\n",[sym str]];
  }
  return x;
}

+ resolvestr:(char*)funname
{
  id sym = [Symbol str:funname];
  return [self resolve:sym];
}

@end

