
/*
 * Copyright (c) 1998-2023 David Stes.
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
 * $Id: symbol.m,v 1.5 2023/02/17 15:39:07 stes Exp $
 */

#include "config.h"
#include <stdlib.h>
#include <stdio.h> /* FILE */
#include <string.h>
#include <assert.h>
#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include "Object.h" /* Stepstone Object.h assumes #import */
#endif
#include <ocstring.h>
#include "symbol.h"
#include "node.h"
#include "options.h"
#include "trlunit.h"
#include "type.h"
#include "var.h"
#include "scalar.h"

BOOL
istypeword(id sym)
{
  return [trlunit istypeword:sym];
}

BOOL
isbuiltinfun(id sym)
{
  return [trlunit isbuiltinfun:sym];
}

void
definebuiltinfun(char *s)
{
  id x = [Symbol str:s];

  x = [Symbol str:strtok([x str], " \t\n\r/")]; /* / for comments */
  [trlunit defbuiltinfun:x];
}

int
pragmatoggle(char *s)
{
  id x = [Symbol str:s];

  /* there was a bug here on SCO (if comment followed value) */
  /* the SCO preproc. does'nt remove the comment on a pragma line */
  return atoi(strtok([x str], " \t\n\r/"));
}

void
definebuiltinvar(char *s)
{
  id x = [Symbol str:s];

  x = [Symbol str:strtok([x str], " \t\n\r/")];
  [trlunit defdata:x astype:t_int];
}

void
definebuiltintype(char *s)
{
  id x = [Symbol str:s];

  x = [Symbol str:strtok([x str], " \t\n\r/")];
  [trlunit defbuiltintype:x];
}

@implementation Symbol

id s_void;
id s_char;
id s_bool;
id s_int;
id s_uns;
id s_long;
id s_double;
id s_str;
id s_sel;
id s_id;
id s_nil;
id s_self;
id s_cmd;
id s_super;
id s_newblock;
id s_main;
id s_objcmain;
id s_aFiler;
id s_type;
id s_fileIn;
id s_fileOut;
id s_fileInIdsFrom;
id s_fileOutIdsFor;
id s_returnval;
id s_returnflag;
id s_increfs;
id s_decrefs;
id s_idincref;
id s_iddecref;

+ commonsymbols
{
  s_newblock = [Symbol str:"newBlock"];
  /* 
   * stes feb/2023 o_mainfun can differ from main
   * but o_mainfun is not necessarily set at this point in time 
   * the way s_main is used is not related to the strcmp() to o_mainfun
   * s_main is used for automatic runtime init OCU_main entry will be used
   * even if the o_mainfun has a different name than main
   * the runtime src/objcrt/objcrt.m hardcodes the name OCU_main 
   * and is doing a _objcModules = findmods (OCU_main) and
   * a return _objcInitNoShared (_objcModules, OCU_main)
   * so it refers to the name OCU_main regardless of o_mainfun name
   */
  s_main = [Symbol str:"main"]; /* objcrt refers to OCU_main */
  s_objcmain = [Symbol str:"objcmain"];
  s_void = [Symbol str:"void"];
  s_char = [Symbol str:"char"];
  s_bool = [Symbol str:"BOOL"];
  s_int = [Symbol str:"int"];
  s_uns = [Symbol str:"unsigned"];
  s_long = [Symbol str:"long"];
  s_double = [Symbol str:"double"];
  s_str = [Symbol str:"STR"];
  s_sel = [Symbol str:"SEL"];
  s_id = [Symbol str:"id"];
  s_nil = [Symbol str:"(id)0"];
  s_self = [Symbol str:"self"];
  s_cmd = [Symbol str:"_cmd"];
  s_super = [Symbol str:"super"];
  s_type = [Symbol str:"type"];
  s_aFiler = [Symbol str:"aFiler"];
  s_fileIn = [Symbol str:"fileIn"];
  s_fileOut = [Symbol str:"fileOut"];
  s_fileInIdsFrom = [Symbol str:"fileInIdsFrom"];
  s_fileOutIdsFor = [Symbol str:"fileOutIdsFor"];
  s_returnflag = [Symbol str:"_returnflag"];
  s_returnval = [Symbol str:"_returnval"];
  s_increfs = [Symbol str:"increfs"];
  s_decrefs = [Symbol str:"decrefs"];
  s_idincref = [Symbol str:"idincref"];
  s_iddecref = [Symbol str:"iddecref"];

  return self;
}

+ str:(char*)s lineno:(int)no filename:fn
{
  return [[super str:s] lineno:no filename:fn];
}

- type
{
  return type;
}

- filename
{
  return filename;
}

- (int)lineno
{
  return lineno;
}

- type:fn
{
  type = fn;
  return self;
}

- filename:fn
{
  filename = fn;
  return self;
}

- lineno:(int)no
{
  lineno = no;
  return self;
}

- lineno:(int)no filename:fn
{
  lineno = no;
  filename = fn;
  return self;
}

- synth
{
  return self;
}

- gen
{
  gl(lineno, [filename str]);
  gs([self str]);
  return self;
}

- (BOOL)canforward
{
  id d;

  /* all atomic types can be forwarded except void */
  if ([self isvoid])
    return NO;
  d = [trlunit lookuptype:self];
  return (d) ? [d canforward] : YES;
}

- (BOOL)isscalartype
{
  id d;

  if ([self isvoid])
    return NO;
  d = [trlunit lookuptype:self];
  return (d) ? [d isscalartype] : YES;
}

- dot:sym
{
  id d = [trlunit lookuptype:self];

  return (d) ? [d dot : sym]:nil;
}

- star
{
  id d = [trlunit lookuptype:self];

  return (d) ? [d star] : nil;
}

- funcall
{
  id d = [trlunit lookuptype:self];

  return (d) ? [d funcall] : nil;
}

- (BOOL)isselptr
{
  id d = [trlunit lookuptype:self];

  if ([self isid])
    return YES;
  return (d) ? [d isselptr] : NO;
}

- (BOOL)isid
{
  id d;
  if (self == s_id) return YES;
  if (strcmp([self str], "id") == 0) return YES;
  d = [trlunit lookuptype:self];
  return (d) ? [d isid] : NO;
}

- (BOOL)isvolatile
{
  return strcmp([self str],"volatile") == 0;
}

- (BOOL)isrefcounted
{
  id d;
  if (self == s_id) return YES;
  if (strcmp([self str], "id") == 0) return YES;
  d = [trlunit lookuptype:self];
  return (d) ? [d isrefcounted] : NO;
}

- (BOOL)isvoid
{
  id d;
  if (self == s_void) return YES;
  if (strcmp([self str], "void") == 0) return YES;
  d = [trlunit lookuptype:self];
  return (d) ? [d isvoid] : NO;
}

- (BOOL)isstorageclass
{
  return NO;			/* overridden by StorageClass */
}

- (BOOL)isgnuattrib
{
  return NO;
}

- (BOOL)isenumtor
{
  return NO;
}

- (BOOL)istypedef
{
  return strcmp([self str], "typedef") == 0;
}

- (BOOL)isstatic
{
  return strcmp([self str], "static") == 0;
}

- (BOOL)isextern
{
  /* this works for extern "C" as well */
  return (strcmp([self str], "extern") == 0) || (strstr([self str], "extern") != NULL);
}

- (BOOL)isinline
{
  char *token = [self str];

  return (strcmp(token, "inline") == 0) || (strcmp(token, "__inline") == 0) || (strcmp(token, "__inline__") == 0);
}

- toscores
{
  int c;
  char *s = [self str];

  while ((c = (*s))) {
    if (c == ':')
      *s = '_';
    s++;
  }
  return self;
}

- unescape
{
  char c;
  int n = 0;
  char * p = value.ptr; 
  char * q = value.ptr; 
  while ((c = *p++)) {
    if (c == '\"') continue;
    if (c == '\\') {
      c = *p++;
      switch (c) {
        case 'n' : c = '\n';break;
        case 'r' : c = '\r';break;
        default  : break;
      }
    } 
    *q++ = c;n++;
  }
  value.count = n;
  *q++ = '\0';
  return self;
}

- unescapeChar
{
  char c;
  int n = 0;
  char * p = value.ptr; 
  char * q = value.ptr; 
  while ((c = *p++)) {
    if (c == '\'') continue;
    if (c == '\\') {
      c = *p++;
      switch (c) {
        case 'n' : c = '\n';break;
        case 'r' : c = '\r';break;
        default  : break;
      }
    } 
    *q++ = c;n++;
  }
  value.count = n;
  *q++ = '\0';
  return self;
}

- st80
{
  gs([self str]);
  return self;
}

- notrlunit
{
  return [self error:"evaluation outside translation unit"];
}

- zero
{
  id d;
  if ([self isid]) return nil;
  if ([self isEqual:s_int]) return [[Scalar new] u_int:0];
  if ([self isEqual:s_char]) return [[Scalar new] u_char:0];
  if ([self isEqual:s_str]) return [[Scalar new] u_str:NULL];
  if (!trlunit) [self notrlunit];
  d = [trlunit lookuptype:self];
  return (d) ? [d zero] : nil;
}

- (int)bytesize
{
  id d;
  if ([self isid]) return sizeof(id);
  if ([self isEqual:s_int]) return sizeof(int);
  if ([self isEqual:s_char]) return sizeof(char);
  if ([self isEqual:s_str]) return sizeof(STR);
  if (!trlunit) [self notrlunit];
  d = [trlunit lookuptype:self];
  if (d) {
    return [d bytesize];
  } else {
    [self error:"dont know how to compute bytesize of %s",[self str]];
    return 0;
  }
}

- peekAt:(char*)ptr
{
  id s;
  id d;
  if ([self isid])  return *((id*)ptr); 
  s = [Scalar new];
  if ([self isEqual:s_int]) return [s u_int:*((int*)ptr)];
  if ([self isEqual:s_char]) return [s u_char: *((char*)ptr)];
  if ([self isEqual:s_str]) return [s u_str:*((char**)ptr)];
  if (!trlunit) [self notrlunit];
  d = [trlunit lookuptype:self];
  if (d) {
    return [d peekAt:ptr];
  } else {
    [self error:"dont know how to peek %s value from memory",[self str]];
    return 0;
  }
}

- poke:v at:(char*)ptr
{
  id d;
  if ([self isid]) { *((id*)ptr) = v; return v; }
  if ([self isEqual:s_int]) { *((int*)ptr) = [v u_int]; return v; }
  if ([self isEqual:s_char]) { *((char*)ptr) = [v u_char]; return v; }
  if ([self isEqual:s_str]) { *((char**)ptr) = [v u_str]; return v; }
  if (!trlunit) [self notrlunit];
  d = [trlunit lookuptype:self];
  if (d) {
    return [d poke:v at:ptr];
  } else {
    [self error:"dont know how to poke %s value into memory",[self str]];
    return 0;
  }
}

@end
 
