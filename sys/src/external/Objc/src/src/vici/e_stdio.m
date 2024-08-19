
/* 
 * VICI Copyright (c) 1999 David Stes
 *
 * $Id: e_stdio.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
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
#include <def.h>
#include <var.h>
#include <scalar.h>
#include <type.h>
#include "funwrap.h"
#include "globwrap.h"

static id e_printf(id aList)
{
   id a,b,c;
   int n = [aList size];
   if (n > 0) a = [aList at:0];
   if (n > 1) b = [aList at:1];
   if (n > 2) c = [aList at:2];
   if (n == 1) {
      printf([a u_str]);return nil;
   }
   if (n == 2 && ![b isKindOf:(id)[Scalar class]]) {
      printf([a u_str],b);return nil;
   }
   if (n == 2 && [[b type] isEqual: t_int]) {
      printf([a u_str],[b u_int]);return nil;
   }
   if (n == 2 && [[b type] isEqual: t_str]) {
      printf([a u_str],[b u_str]);return nil;
   }
   if (n == 2 && [[b type] isEqual: t_bool]) {
      printf([a u_str],[b u_char]);return nil;
   }
   if (n == 2 && [[b type] isEqual: t_char]) {
      printf([a u_str],[b u_char]);return nil;
   }
   [aList error:"don't know how to print %s",[a u_str]];
}

static id e_fprintf(id aList)
{
   FILE *f;
   id a,b,c;
   int n = [aList size];
   f = [[aList at:0] u_fp];
   if (n > 1) a = [aList at:1];
   if (n > 2) b = [aList at:2];
   if (n > 3) c = [aList at:3];
   if (n == 2) { fprintf(f,[a u_str]);return nil; }
   if (n == 3 && [[b type] isEqual: t_int]) {
     fprintf(f,[a u_str],[b u_int]);return nil;
   }
   if (n == 3 && [[b type] isEqual: t_str]) {
     fprintf(f,[a u_str],[b u_str]);return nil;
   }
   if (n == 3 && [[b type] isEqual: t_bool]) {
     fprintf(f,[a u_str],[b u_char]);return nil;
   }
   if (n == 3 && [[b type] isEqual: t_char]) {
     fprintf(f,[a u_str],[b u_char]);return nil;
   }
   [aList error:"don't know how to print %s",[a u_str]];
}

static id e_getc(id aList)
{
   int c;
   FILE *f = [[aList at:0] u_fp];
   c = getc(f);
   return [[Scalar new] u_int:c];
}

static id e_ungetc(id aList)
{
   int c;
   FILE *f;
   c = [[aList at:0] u_int];
   f = [[aList at:1] u_fp];
   ungetc(c,f);
}

static id e_perror(id aList)
{
   char *c = [[aList at:0] u_str];
   perror(c);
}

static id e_freopen(id aList)
{
   int c;
   char *s,*m;
   FILE *f,*g;
   s = [[aList at:0] u_str];
   m = [[aList at:1] u_str];
   f = [[aList at:2] u_fp];
   g = freopen(s,m,f);
   return [[Scalar new] u_fp:g];
}

FUNWRAP stdiofunwraps[] = {
  {"printf",e_printf},
  {"fprintf",e_fprintf},
  {"getc",e_getc},
  {"ungetc",e_ungetc},
  {"_IO_getc",e_getc}, 
  {"perror",e_perror},
  {"freopen",e_freopen},
  {NULL,NULL},
};

static id g_stderr(void)
{
  return [[Scalar new] u_fp:stderr];
}

static void s_stderr(id v)
{
#if 0
  stderr = [v u_fp];
#else
  [v error:"can't set stderr"];
#endif
}

static id g_stdin(void)
{
  return [[Scalar new] u_fp:stdin];
}

static void s_stdin(id v)
{
#if 0
  stdin = [v u_fp];
#else
  [v error:"can't set stdin"];
#endif
}

static id g_stdout(void)
{
  return [[Scalar new] u_fp:stdout];
}

static void s_stdout(id v)
{
#if 0
  stdout = [v u_fp];
#else
  [v error:"can't set stdout"];
#endif
}

GLOBWRAP stdioglobwraps[] = {
  {"stderr",g_stderr,s_stderr},
  {"stdout",g_stdout,s_stdout},
  {"stdin",g_stdin,s_stdin},
  {NULL,NULL,NULL},
};


