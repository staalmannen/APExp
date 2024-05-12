
/*
 * Portable Object Compiler - PostLink Program
 * $Id: postlink.m,v 1.1.1.1 2000/06/07 21:09:25 stes Exp $
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

/*
 * Input  : link map.
 * Output : C source file listing of all classes in application,
 * to be linked again into the program (after first link).
 *
 * NOTE:
 *      This only applies to compiling with the -postlink option.
 *      By default, on UNIX K&R C compilers, postlink is not used, 
 *      and objcrt uses "auto-initialization code", which
 *      determines at run-time what classes are linked into the program.
 * 
 * The idea of postlink is to "look", after a first link, in the binary
 * image of the program and to make a list of the classes that are linked
 * into the program (for initialization).
 *
 * postlink takes as input the output of "nm" for the (first link of) the
 * program, and searches for "BIND" entries.  It generates a table of these
 * BIND entries, that can then be used for objcrt initialization.
 * 
 * The output of "postlink" is then compiled and is then linked into the
 * program (this means a second link).
 * 
 * Note that "nm" output can differ among machines, and that there's often
 * flags to "nm" that can simplify the task of this program.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>		/* strtok */
#include "objpak.h"

id inFile;
id outFile;
id linkFormat;
id prefix;			/* not be confused with the BINDPREFIX */
id appendFiles;

#define BINDPREFIX "_OBJCBIND"
#define MAXLINE 4096

/*
 * WATCOM
 * ------
 *
 * the format of the WATCOM wlink map file is as follows:
 *
 *  000408123   _OBJCBIND_String_
 *
 * it appends an underscore (the first underscore is "ours").
 * but does NOT append (I believe) when compiling with stack
 * (or register,don't remember) calling conventions!
 *
 * in addition, for DLL's we might have something like:
 *
 *  000408123   _OBJCBIND_String_       objpak.dl()
 *
 */

static int 
watcomGrepLine(id set, char *buf)
{
  int c = strlen(BINDPREFIX);
  char *p, *delims = " .|\t";	/* fixed tab for metrowerks */

  while (*buf != 0) {
    if (strncmp(buf, BINDPREFIX, c) == 0) {
      id entry = [String chars:buf count:strlen(buf) - 1];

      p = strtok([entry str], delims);
      if (p) {
	/* remove last underscore - if any */
	c = strlen(p);
	if (p[c - 1] == '_')
	  p[c - 1] = 0;
	[set add:entry];
      }
      break;
    }
    buf++;
  }

  return 0;
}

/*
 * UNIX
 * ----
 *
 * Sometimes '_' is prepended to the function name.
 * On HPUX, field are (by default) sometimes limited by '|'
 * 
 * AIX   : 00009078 T _OBJCBIND_myObject
 * IRIX  : [2] | 0| |Global | |Bss | _OBJCBIND_myObject
 * NeXT  : 00009078 T __OBJCBIND_myObject
 * HP-UX : _OBJCBIND_myObject|4|undef|common|$SHORTBSS$
 *
 */

static int 
unixGrepLine(id set, char *buf)
{
  char *p;
  char *delims = " .|\t";	/* fixed tab for metrowerks */
  int c = strlen(BINDPREFIX);

  while (*buf != 0) {
    if (strncmp(buf, BINDPREFIX, c) == 0) {
      /* copy rest of line into buffer */
      id entry = [String chars:buf count:strlen(buf) - 1];

      p = strtok([entry str], delims);
      if (p)
	[set add:entry];
      break;
    }
    buf++;
  }

  return 0;
}

/*
 * Metrowerks
 * 0x00000000 0x000028  PR  SD  globl       ._OBJCBIND_hello   hello.c.o
 *
 * Seems to be covered by unix case.
 */

static int 
grepLine(id set, char *buf)
{
  if (linkFormat == nil)
    return unixGrepLine(set, buf);
  if ([linkFormat isEqualSTR:"unix"])
    return unixGrepLine(set, buf);
  if ([linkFormat isEqualSTR:"mpw"])
    return unixGrepLine(set, buf);
  if ([linkFormat isEqualSTR:"watcom"])
    return watcomGrepLine(set, buf);
  if ([linkFormat isEqualSTR:"metrowerks"]) {
    return unixGrepLine(set, buf);
  }
  if ([linkFormat isEqualSTR:"ibmvac"])
    return unixGrepLine(set, buf);
  fprintf(stderr, "postlink: unknown format %s\n", [linkFormat str]);
  return 0;
}

static BOOL 
grepMap(id set, FILE * file)
{
  char buf[BUFSIZ];

  while (fgets(buf, sizeof(buf), file) != NULL)
    grepLine(set, buf);
  return ferror(file) == NO;
}

/*
 * dumpFile
 */

static void 
dumpFile(id set, FILE * f)
{
  id elt, seq;

  fprintf(f, "\n");
  fprintf(f, "/* dummy def for compilers that require struct def */\n");
  fprintf(f, "struct modDescriptor { int dummy; };\n");
  fprintf(f, "\n");

  seq = [set eachElement];
  while ((elt = [seq next])) {
    fprintf(f, "extern struct modDescriptor *%s();\n", [elt str]);
  }

  fprintf(f, "\n");
  fprintf(f, "/* this must match objcrt.m datatype */\n");
  fprintf(f, "static struct modEntry {\n");
  fprintf(f, "\tstruct modDescriptor *(*modLink)();\n");
  fprintf(f, "\tstruct modDescriptor *modInfo;\n");
  fprintf(f, "} _msgControl[] = {\n");

  seq = [set eachElement];
  while ((elt = [seq next])) {
    fprintf(f, "\t{%s,0},\n", [elt str]);
  }

  fprintf(f, "\t{0,0}\n");
  fprintf(f, "};\n");
  fprintf(f, "\n");

  /* the possibility to append files is used to generate
   * DLL initialization code here, and in that case we
   * do not output a _objcModules definition (file can do
   * that anyway)
   */

  if (appendFiles == nil) {

    /* normal case when invoked without -a */

    fprintf(f, "/* non-NULL _objcModules disables auto-init */\n");
    if (prefix) {
      STR s = [prefix str];

      fprintf(f, "struct modEntry *%s_objcModules = _msgControl;\n", s);
    } else {
      fprintf(f, "struct modEntry *_objcModules = _msgControl;\n");
    }
  } else {
    FILE *aFile;

    seq = [appendFiles eachElement];
    while ((elt = [seq next])) {
      if ((aFile = fopen([elt str], "r"))) {
	char aBuf[MAXLINE + 1];

	while (fgets(aBuf, MAXLINE, aFile))
	  fputs(aBuf, f);
	fclose(aFile);
      } else {
	fprintf(stderr, "can't open %s\n", [elt str]);
      }
    }
  }

  fprintf(f, "\n");
}

/*
 * Options
 */

static BOOL 
isOption(id s)
{
  return [s size] && [s charAt:0] == '-';
}

static void 
unknownOption(id option)
{
  fprintf(stderr, "postlink: Illegal option %s\n", [option str]);
  exit(1);
}

static int 
setLinkFormat(id option, int i, char *argv[])
{
  id arg = [String str:argv[++i]];

  if (isOption(arg))
    unknownOption(arg);
  linkFormat = arg;
  return i;
}

static int 
setPrefix(id option, int i, char *argv[])
{
  id arg = [String str:argv[++i]];

  if (isOption(arg))
    unknownOption(arg);
  prefix = arg;
  return i;
}

static int 
appendFile(id option, int i, char *argv[])
{
  id arg = [String str:argv[++i]];

  if (isOption(arg))
    unknownOption(arg);
  if (!appendFiles)
    appendFiles = [OrdCltn new];
  [appendFiles add:arg];
  return i;
}

static int 
setOutFile(id option, int i, char *argv[])
{
  id arg = [String str:argv[++i]];

  if (isOption(arg))
    unknownOption(arg);
  outFile = arg;
  return i;
}

static void 
setOptions(int argc, char *argv[])
{
  int i;
  int fileCount = 0;		/* optional inFile and outFile */
  BOOL checkOption = YES;	/* YES if filename can't begin with a dash */

  for (i = 1; i < argc; i++) {
    id s = [String str:argv[i]];

    if ([s isEqualSTR:"-linkFormat"]) {
      i = setLinkFormat(s, i, argv);
    } else if ([s isEqualSTR:"-f"]) {
      i = setLinkFormat(s, i, argv);
    } else if ([s isEqualSTR:"-format"]) {
      i = setLinkFormat(s, i, argv);
    } else if ([s isEqualSTR:"-p"]) {
      i = setPrefix(s, i, argv);
    } else if ([s isEqualSTR:"-prefix"]) {
      i = setPrefix(s, i, argv);
    } else if ([s isEqualSTR:"-a"]) {
      i = appendFile(s, i, argv);
    } else if ([s isEqualSTR:"-append"]) {
      i = appendFile(s, i, argv);
    } else if ([s isEqualSTR:"-o"]) {
      i = setOutFile(s, i, argv);
    } else if ([s isEqualSTR:"-"]) {
      checkOption = NO;
    } else if (checkOption && isOption(s)) {
      unknownOption(s);
    } else if (fileCount == 0) {
      inFile = s;
      fileCount++;
    } else if (fileCount == 1) {
      outFile = s;
      fileCount++;
    } else {
      unknownOption(s);
    }
  }
}

int 
main(int argc, char *argv[])
{
  FILE *inIOD = NULL;
  FILE *outIOD = NULL;
  id functions = [Set new];

  setOptions(argc, argv);

  if (inFile) {
    inIOD = fopen([inFile str], "r");
    if (!inIOD)
      fprintf(stderr, "postlink: can't open %s", [inFile str]);
  }
  if (outFile) {
    outIOD = fopen([outFile str], "w");
    if (!outIOD)
      fprintf(stderr, "postlink: can't open %s", [outFile str]);
  }
  grepMap(functions, (inIOD) ? inIOD : stdin);
  dumpFile(functions, (outIOD) ? outIOD : stdout);

  if (inIOD) {
    fclose(inIOD);
  }
  if (outIOD) {
    fclose(outIOD);
  }
  return 0;
}


