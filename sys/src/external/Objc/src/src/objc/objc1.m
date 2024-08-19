
/* 
 * Copyright (c) 1998-2024 David Stes
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

#include <string.h>		/* strtok */
#include <stdlib.h>		/* getenv */
#include <assert.h>
#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include <stdio.h> /* FILE */
#include "Object.h" /* Stepstone Object.h assumes #import */
#endif
#include <ocstring.h>
#include <ordcltn.h>
#include <sequence.h>
#include "config.h"
#include "node.h"
#include "trlunit.h"
#include "options.h"
#include "util.h"
#include "symbol.h"

void printversion(void)
{
  printf("%s\n",OBJCVERSION);
  exit(0);
}

void printcopyright(void)
{
  printf("Portable Object Compiler %s (c) 1997-2024.\n",OBJCVERSION);
  printf("Distributed under the terms of the GNU LGPL.\n");
}

void unknownoption(char* arg)
{
  STR msg = "%s: unknown option %s\n";
  STR name = (o_cplus) ? "objcpls1" : "objc1";
  fprintf(stderr, msg, name, arg);
  exit(1);
}

void badarg(id option,id arg)
{
  STR msg = "%s: illegal argument %s for %s\n";
  STR name = (o_cplus) ? "objcpls1" : "objc1";
  fprintf(stderr, msg, name, [arg str], [option str]);
  exit(1);
}

BOOL isoption(char* s)
{
  return s != NULL && s[0] == '-';
}

id optionstok(id aCltn, char *s)
{
  char *p;
  char *delims = " \t\n\r";
  id buffer = [String str:s];

  p = strtok([buffer str], delims);

  while (p != NULL) {
    [aCltn add:[String str:p]];
    p = strtok(NULL, delims);
  }

  return aCltn;
}

id optsfromfile(id aCltn, FILE * f)
{
  char buf[BUFSIZ + 1];

  while (!feof(f)) {
    if (fgets(buf, BUFSIZ, f)) {
      /* this works 'cause strtok also deletes \n */
      optionstok(aCltn, buf);
    }
  }

  return aCltn;
}

/* this is mostly for MS-DOS cmd line length limitations */

id optsnamed(id aCltn, STR s)
{
  STR t;
  FILE *f;

  /* maybe there's such an environment variable */
  if ((t = getenv(s)))
    return optionstok(aCltn, t);

  /* maybe there's such a file */
  if ((f = fopen(s, "r"))) {
    aCltn = optsfromfile(aCltn, f);
    fclose(f);
    return aCltn;
  }
  /* nope */
  return nil;
}

id cmdlineopts(int argc, char *argv[])
{
  int i;
  id aCltn = [OrdCltn new];

  for (i = 1; i < argc; i++) {
    [aCltn add:[String str:argv[i]]];
  }

  return aCltn;
}

/*
 * Filename for first line tag output (source filename)
 * (which we want to be file.m instead of file.P)
 */

int setfilename(id option, id args)
{
  id arg = [args next];
  char *t = [arg str];

  if (isoption(t)) badarg(option, arg);
  o_srcfilename = t;

  return 0;
}

int setinitcall(id option, id args)
{
  id arg = [args next];
  char *t = [arg str];

  if (isoption(t)) badarg(option, arg);
  o_initcall = t;

  return 0;
}

int setbrowsedir(id option, id args)
{
  id arg = [args next];
  char *t = [arg str];

  if (isoption(t)) badarg(option, arg);
  o_browsedir = t;

  return 0;
}

int setmainfun(id option, id args)
{
  id arg = [args next];
  if (isoption([arg str])) badarg(option, arg);
  o_mainfun = [arg str];
  return 0;
}

int setbind(id option, id args)
{
  id arg = [args next];
  if (isoption([arg str])) badarg(option, arg);
  o_bind = [arg str];
  return 0;
}

/*
 * Make line max settable (works only for identifiers now).
 */

int setlinemax(id option, id args)
{
  id arg = [args next];
  if (isoption([arg str])) badarg(option, arg);
  o_linemax = [arg asInt];
  return 0;
}

/*
 * @ filename is understood to take options from "filename"
 * Maybe we should also allow @filename (without space)
 */

void setoptions(id aCltn);

int setoptsfromfile(id option, id args)
{
  id arg = [args next];

  if (isoption([arg str])) badarg(option, arg);
  setoptions(optsnamed([OrdCltn new], [arg str]));
  return 0;
}

/*
 * Builtin functions (a la __builtin_isfloat).
 */

int addbuiltintype(id option, id args)
{
  id arg = [args next];
  if (isoption([arg str])) badarg(option, arg);
  definebuiltintype([arg str]);
  return 0;
}

int addbuiltinfun(id option, id args)
{
  id arg = [args next];
  if (isoption([arg str])) badarg(option, arg);
  definebuiltinfun([arg str]);
  return 0;
}

void setoptions(id aCltn)
{
  id args, s;
  int filecount = 0;		/* optional inFile and outFile */
  BOOL checkoption = YES;	/* YES if filename can't begin with a dash */

  args = [aCltn eachElement];

  while ((s = [args next])) {
    char *t = [s str];
    if (!strcmp(t,"-quiet")) {
      ++o_quiet;
    } else if (!strcmp(t,"-z")) {
      ++o_outputcode; 
    } else if (!strcmp(t,"@")) {
      setoptsfromfile(s, args);
    } else if (!strcmp(t,"-u")) {
      o_buffered=0;
    } else if (!strcmp(t,"-version")) {
      o_version++;
    } else if (!strcmp(t,"-otb")) {
      o_otb++;
      o_shareddata = 0;
    } else if (!strcmp(t,"-gnu")) {
      o_gnu++;
    } else if (!strcmp(t,"-darwin")) {
      o_darwin++;
    } else if (!strcmp(t,"-vms")) {
      o_vms++;
    } else if (!strcmp(t,"-hpux")) {
      o_hpux++;
    } else if (!strcmp(t,"-sunstudio")) {
      o_sunstudio++;
    } else if (!strcmp(t,"-m64")) {
      o_m64++;
    } else if (!strcmp(t,"-refcnt")) {
      o_refcnt++;
      o_selfassign = 0; /* because receiver of a message is not counted */
    } else if (!strcmp(t,"-noasm")) {
      o_enableasm = 0;
    } else if (!strcmp(t,"-nolonglong")) {
      o_llkeyw = 0;
    } else if (!strcmp(t,"-msdos")) {
#if 0
 /* there are still some problems with this code on LCC */
 /* temporarily disable it (with the goal to enable this later again) */
      o_duptypedefs++;
#endif
      o_msdos++;
    } else if (!strcmp(t,"-watcom")) {
      o_watcom++;
    } else if (!strcmp(t,"-comments")) {
      o_comments++;
    } else if (!strcmp(t,"-duptypedefs")) {
      o_duptypedefs++;
    } else if (!strcmp(t,"-ibmvac")) {
      o_ibmvac++;
    } else if (!strcmp(t,"-noSelTbl")) {
      o_seltranslation = 0;
    } else if (!strcmp(t,"-noCategories")) {
      o_categories = 0;
    } else if (!strcmp(t,"-noBlocks")) {
      o_blocks = 0;
    } else if (!strcmp(t,"-st80")) {
      o_st80++;
      o_nolinetags++;
      o_outputcode = 0; /* no C code */
    } else if (!strcmp(t,"-fwd")) {
      o_fwd++;
    } else if (!strcmp(t,"-noSelPtr")) {
      o_selptr = 0;
    } else if (!strcmp(t,"-noFwd")) {
      o_fwd = 0;
    } else if (!strcmp(t,"-noCache")) {
      o_cache = 0;
    } else if (!strcmp(t,"-noFiler")) {
      o_filer = 0;
    } else if (!strcmp(t,"-noSelfAssign")) {
      o_selfassign = 0;
    } else if (!strcmp(t,"-noNilRcvr")) {
      o_nilrcvr = 0;
    } else if (!strcmp(t,"-objc")) {
      o_gencode = 0;
    } else if (!strcmp(t,"-cplus")) {
      o_cplus++;
    } else if (!strcmp(t,"-inlinecache")) {
      o_inlinecache++;
    } else if (!strcmp(t,"-refBind")) {
      o_refbind++;
    } else if (!strcmp(t,"-export")) {
      setbind(s, args);
    } else if (!strcmp(t,"-dllexport")) {
      o_bind = "__declspec(dllexport)";
    } else if (!strcmp(t,"-traditional")) {		/* ignore */
    } else if (!strcmp(t,"-filename")) {
      setfilename(s, args);
    } else if (!strcmp(t,"-longlinetag")) {		/* compatib. */
    } else if (!strcmp(t,"-shortTags")) {
      o_tagformat = "# %d \"%s\"\n";
    } else if (!strcmp(t,"-init")) {
      setinitcall(s, args);
    } else if (!strcmp(t,"-browse")) {
      setbrowsedir(s, args);
      o_nolinetags++;
      o_outputcode = 0; /* no C code */
    } else if (!strcmp(t,"-noShared")) {
      o_shareddata = 0;
    } else if (!strcmp(t,"-main")) {
      setmainfun(s, args);
    } else if (!strcmp(t,"-linemax")) {
      setlinemax(s, args);
    } else if (!strcmp(t,"-builtinfunction")) {
      addbuiltinfun(s, args);
    } else if (!strcmp(t,"-builtintype")) {
      addbuiltintype(s, args);
    } else if (!strcmp(t,"-nolinetags")) {
      o_nolinetags++;
    } else if (!strcmp(t,"-oneperfile")) {
      o_oneperfile++;
    } else if (!strcmp(t,"-w")) {
      o_warnings = 0;
    } else if (!strcmp(t,"-wClassUsedAsType")) {
      o_warnclasstype = 0;
    } else if (!strcmp(t,"-wMissing")) {
      o_warnmissingmethods = 0;
    } else if (!strcmp(t,"-wTypeConflict")) {
      o_warntypeconflict = 0;
    } else if (!strcmp(t,"-wLocalInstance")) {
      o_warnlocalnst = 0;
    } else if (!strcmp(t,"-wUndefinedMethod")) {
      o_warnundefined = 0;
    } else if (!strcmp(t,"-wInterfaceNotFound")) {
      o_warnnotfound = 0;
    } else if (!strcmp(t,"-WLex")) {
      o_warnlex++;
    } else if (!strcmp(t,"-WFwd")) {
      o_warnfwd++;
    } else if (!strcmp(t,"-postlink")) {
      o_postlink++;
    } else if (!strcmp(t,"-attrcommon")) {
      o_attrcommon++;
    } else if (!strcmp(t,"-checkbindfunction")) {
      o_checkbind++;
    } else if (!strcmp(t,"-debugInfo")) {
      o_debuginfo++;
    } else if (!strcmp(t,"-ppi")) {
      o_ppi++;
    } else if (!strcmp(t,"-")) {
      checkoption = 0;
    } else if (checkoption && isoption(t)) {
      unknownoption(t);
    } else if (filecount == 0) {
      o_infile = t;
      filecount++;
    } else if (filecount == 1) {
      o_outfile = t;
      filecount++;
    } else {
      unknownoption(t);
    }
  }
}

/*
 * Opening and closing input file.  We're not dealing with wrapping around
 * files (include)  (because we're processing cpp output)
 */

void openinfile(void)
{
  if (o_infile) {
    yyin = openfile(o_infile, "r");
  } else {
    /* stdin */
  }
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

  if (!o_nolinetags) {
    gl(inlineno,[infilename str]);
  }

  assert(trlunit != nil);
  [trlunit setmodversion:OBJC1VERSION];
  [trlunit setmodname:[infilename str]];

  if (o_vms) {
    definebuiltinfun("__VA_START_BUILTIN");
    definebuiltinfun("__IS_X_FLOAT_BUILTIN");
    definebuiltintype("__int64");
  }

  if (o_hpux) {
    definebuiltinfun("__va_start__");
    definebuiltinfun("__va_arg__");
    definebuiltintype("__va_list__");
    definebuiltintype("__fpreg");
    definebuiltintype("__float80");
  }

  if (o_darwin) {
  /* Apple darwin headers have stuff like __attribute__((availability(macosx,introduced=10.12.1)))__attribute__((availability(ios,introduced=10.1))) */
  /* this causes some warnings about undefined tokens like ios */
    definebuiltinvar("message"); 
    definebuiltinvar("ios"); 
    definebuiltinvar("tvos"); 
    definebuiltinvar("watchos"); 
    definebuiltinvar("swift"); 
    definebuiltinvar("macos"); 
    definebuiltinvar("macosx"); 
    definebuiltinvar("introduced"); 
    definebuiltinvar("unavailable"); 
  }

  if (o_gnu) {
    definebuiltintype("__float128"); /* openindiana hipster gcc 9.2 -m32 */
    definebuiltinfun("__builtin_bswap16");
    definebuiltinfun("__builtin_saveregs");
    definebuiltinfun("__builtin_classify_type");
    definebuiltinfun("__builtin_isfloat");
    definebuiltinfun("__builtin_classof");
    definebuiltinfun("__alignof");
    definebuiltinfun("_Alignof");
    definebuiltinfun("__alignof__");
    definebuiltinfun("__ALIGNOF__"); /* Intel icc 6.0 header */
    definebuiltinfun("__builtin_alignof");
    definebuiltinfun("__builtin_next_arg");
/*  definebuiltinfun("__builtin_alloca"); Sun Solaris 11.1 regular function */
    definebuiltinfun("__builtin_memcpy");
    definebuiltinfun("__builtin_memset");
    definebuiltinfun("__builtin_fabs");
    definebuiltinfun("__builtin_fabsl");
    definebuiltinfun("__builtin_fabsf");
    definebuiltinfun("__builtin_constant_p");
    definebuiltinvar("__func__"); /* C99 standard */
    definebuiltinvar("__FUNCTION__"); /* old GCC */
    definebuiltinvar("__PRETTY_FUNCTION__");
    definebuiltinvar("_VA_FP_SAVE_AREA");
    definebuiltintype("__builtin_va_list"); /* IA-64 */
    definebuiltinfun("__builtin_stdarg_start");
    definebuiltinfun("__builtin_va_end");
    definebuiltinfun("__builtin_va_arg");
    /* Solaris 11.3 defines va_start as function when -m64 */
    if (!(o_sunstudio && o_m64)) definebuiltinfun("__builtin_va_start");
    definebuiltinfun("__builtin_expect");
    definebuiltinfun("__builtin_strchr");
    definebuiltinfun("__builtin_strcmp");
    definebuiltinfun("__builtin_strncmp");
    definebuiltinfun("__builtin_offsetof"); /* Slackware 14.2 gcc 5.3 */
    definebuiltinfun("__builtin_strncpy"); /* CentOS 6.5 gcc 4.4.7 */

    /* gcc 4.5 for ubuntu 11.04 port */
    definebuiltinfun("__builtin_strlen");
    definebuiltinfun("__builtin_object_size");
    definebuiltinfun("__builtin_va_arg_pack");
    definebuiltinfun("__builtin___sprintf_chk");
    definebuiltinfun("__builtin___vsprintf_chk");
    definebuiltinfun("__builtin___snprintf_chk");
    definebuiltinfun("__builtin___vsnprintf_chk");
    definebuiltinfun("__builtin___strcpy_chk");
    definebuiltinfun("__builtin___strncpy_chk");
    definebuiltinfun("__builtin___strcat_chk");
    definebuiltinfun("__builtin___strncat_chk");
    definebuiltinfun("__builtin___memmove_chk");
    definebuiltinfun("__builtin___memset_chk");
    definebuiltinfun("__builtin___memcpy_chk");

    /* Slackware 14.1 port gcc 4.8.2  */
    definebuiltinfun("__builtin_bswap32");
    definebuiltinfun("__builtin_bswap64");

    /* Apple i686-apple-darwin10.8.0 */
    /* /usr/include/secure/_string.h:103 */
    definebuiltinfun("__builtin___stpcpy_chk");

    /* the following are not really gnu, they're SUN headers */
    /* Solaris 11.3 defines va_arg_incr as function when -m64 */
    definebuiltinvar("__builtin_va_alist");
    if (!(o_sunstudio && o_m64)) definebuiltinfun("__builtin_va_arg_incr");
  }
}

void closeinfile(void)
{
  if (o_infile) {
    fclose(yyin);
  } else {
    /* stdin */
  }
}

void openoutfile(void)
{
  if (o_outfile) {
    gfile = openfile(o_outfile,"w");
  } else {
    gfile = stdout; /* direct output to this stream */
  }

  /* for debugging output (-u unbuf option) */
  if (!o_buffered) setbuf(gfile,NULL);
}

void closeoutfile(void)
{
  if (o_outfile) fclose(gfile);
}

int main(int argc, char *argv[])
{
  /* define early since setoptions() modifies this object */
  trlunit = [TranslationUnit new];

  defoptions();
  setoptions(cmdlineopts(argc, argv));

  if (o_version) printversion();
  if (!o_quiet) printcopyright();

  openinfile();
  openoutfile(); /* redirect stdout */

  setfirstlinetag();

  if (o_outputcode) [trlunit prologue];
  if (yyparse()) exit(1);
  if (o_outputcode) [trlunit epilogue];

  closeinfile();
  closeoutfile();

  if (o_browsedir) [trlunit browse];

  exit(exitstatus);
  return 0;
}

