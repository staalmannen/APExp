
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
 * $Id: trlunit.m,v 1.6 2023/02/17 15:39:07 stes Exp $
 */

#include "config.h"
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include <stdio.h> /* FILE */
#include "Object.h" /* Stepstone Object.h assumes #import */
#endif
#include <ocstring.h>
#include "symbol.h"
#include <set.h>
#include <ordcltn.h>
#include <sequence.h>
#include <dictnary.h>
#include <sortcltn.h>
#include "node.h"
#include "expr.h"
#include "trlunit.h"
#include "type.h"
#include "options.h"
#include "datadef.h"
#include "classdef.h"
#include "msgxpr.h"

id trlunit;

@implementation TranslationUnit

+ new
{
  [Symbol commonsymbols];
  [Type commontypes];
  [Expr commonexprs];
  return trlunit = [super new];
}

- (int)msgcount
{
  return msgcount++;		/* count for tmp variables */
}

- gettmpvar
{
  return [String sprintf:"objcT%i", [trlunit msgcount]];
}

- (int)icachecount
{
  return icachecount++;		/* count for tmp variables */
}

- (int)blockcount
{
  return blockcount++;		/* count for tmp variables */
}

- (int)heapvarcount
{
  return heapvarcount++;	/* count for tmp variables */
}

- returnlabel
{
  return [String sprintf:"_cleanup%i", retlabelcount++];
}

- (BOOL)usingselfassign
{
  return usingselfassign;
}

- usingselfassign:(BOOL)x
{
  usingselfassign = x;
  return self;
}

- (BOOL)usingblocks
{
  return usingblocks;
}

- usingblocks:(BOOL)x
{
  usingblocks = x;
  return self;
}

- inlinecacheprologue
{
  /* inline cache data type emitted here, must match one from objcrt.m */
  if (o_cplus) {
    gs("struct objcrt_inlineCache {id cls;id (*imp)(...);};\n");
  } else {
    gs("struct objcrt_inlineCache {id cls;id (*imp)();};\n");
  }

  /* messages to nil with inlinecache */
  /* emit o_bind so that the definition matches the one in objcrt */
  if (o_cplus) {
    gextc();
    gf("id %s _nilHandler(...);\n", o_bind);
  } else {
    gf("id %s _nilHandler(id,char*);\n", o_bind);
  }

  return self;
}

- setmodversion:(char*)v
{
  modversion = v;
  return self;
}

static char *
mystrrchr(const char *s, int c)
{				/* sunos4.1.1 ? */
  char *t = (char *) s;

  while (*t) {
    t++;
  }

  while (t != s) {
    if (*t == c)
      return t;
    else
      t--;
  }

  return (*t == c) ? t : NULL;
}

- setmodname:(char *)filename
{
  id s;
  char *p;
  char *cp;

  p = mystrrchr(filename, o_pathsep[0]);
  s = [String str:(p) ? p + 1 : (char *) filename];
  p = [s strCopy];
  if ((cp = mystrrchr(p, '.')) != NULL)
    *cp = '\0';			/* strip extension */
  for (cp = p; *cp != '\0'; cp++) {
    if (!isalnum(*cp))
      *cp = '_';
  }

  /* module name */
  modname = p;

  /* name bind function */
  s = [String sprintf:"_OBJCBIND_%s", p];
  bindfunname = [s strCopy];

  /* name moddesc (because of bizar c++ problem, this used to be static) */
#ifndef MODDESCSTATIC
  s = [String sprintf:"%s_modDesc", p];
  moddescname = [s strCopy];
#else
  moddescname = "_modDesc";
#endif

  return self;
}

- (char *)moddescname
{
  assert(moddescname != NULL);
  return moddescname;
}

- checkbindprologue
{
  gs("\nextern char *objcrt_bindError(char *);\n");
  return self;
}

- prologue
{
  assert(modname != NULL);

  if (o_comments)
    gs("/* objc prologue */\n");

  if (o_otb) {
    gs("struct _PRIVATE {\n");
    gs("  struct OTB *isa;\n");
    gs("};\n");
    gs("struct OTB {\n");
    gs("  struct _PRIVATE *ptr;\n");
    g_otbvars();
    gs("};\n");
    gs("typedef struct OTB *id;\n");
  } else {
    if (!o_refcnt) {
      gs("struct _PRIVATE { struct _PRIVATE *isa; };\n");
    } else {
      gs("struct _PRIVATE { struct _PRIVATE *isa;unsigned int _refcnt; };\n");
    }
    gs("typedef struct _PRIVATE *id;\n");
  }

  [[ClassDef new] genshartype];

  if (!o_fwd) {
    if (o_cplus) {
      gextc();			/* in C++ IMP is defined as id *(...) */
      gf("id %s (* _imp(id,char*))(...);\n", o_bind);
      gextc();
      gf("id %s (* _impSuper(id,char*))(...);\n", o_bind);
    } else {
      gf("extern id %s (* _imp(id,char*))();\n", o_bind);
      gf("extern id %s (* _impSuper(id,char*))();\n", o_bind);
    }
  }
  if (o_inlinecache)
    [self inlinecacheprologue];

  gf("extern struct modDescriptor %s *%s(void);\n", o_bind, bindfunname);

  if (o_refbind) {
    /* workaround 'mwcc' dead code optimizer, force reference to bindfun */
    gf("static char **selTransTbl = (char **)%s;\n", bindfunname);
  } else {
    /* 'lcc' chokes on the above initializer, so also need this case */
    gs("static char **selTransTbl;\n");
  }

  if (o_fwd) {
    if (o_cplus) {
      gs("static id (**fwdTransTbl)(...);\n");
    } else {
      gs("static id (**fwdTransTbl)();\n");
    }
  }
  /* struct used in sharedType & defined by Stepstone objcc */
  if (o_cplus) {
    gs("struct _SLT {char *_cmd;id (*_imp)(...);};\n");
  } else {
    gs("struct _SLT {char *_cmd;id (*_imp)();};\n");
  }

  /* type for Objective C modules */
  gs("struct modDescriptor {\n");
  /* keep the following compat. with Stepstone objcc */
  gs("  char *modName;\n");
  gs("  char *modVersion;\n");
  gs("  long modStatus;\n");
  gs("  char *modMinSel;\n");
  gs("  char *modMaxSel;\n");
  gs("  id *modClsLst;\n");
  gs("  short modSelRef;\n");
  gs("  char **modSelTbl;\n");
  gs("  struct methodDescriptor *modMapTbl;\n");
  /* POC extensions if any */
  gs("};\n");

  gf("extern struct modDescriptor %s;\n", moddescname);
  if (o_checkbind)
    [self checkbindprologue];
  if (o_comments)
    gs("/* end of objc prologue */\n");
  return self;
}

- allclsimpls
{
  if (clsimpls)
    return clsimpls;
  if (clsimpl)
    return [[OrdCltn new] add:clsimpl];
  return nil;
}

- addclsimpl:c
{
  /* for Stepstone compatibility we have to support the oneperfile case */
  if (clsimpls) {
    assert(clsimpl == nil && [clsimpls size] >= 2);
    [clsimpls add:c];
  } else {
    if (clsimpl) {
      if (o_oneperfile) {
	fatal("only one implementation per file allowed");
      } else {
	clsimpls = [OrdCltn new];
	[clsimpls add:clsimpl];
	[clsimpls add:c];
	clsimpl = nil;
      }
    } else {
      clsimpl = c;
    }
  }
  return self;
}

- (int)seloffset:selname
{
  int n;
  id val;

  if (!selcltn) {
    selcltn = [OrdCltn new];
    seldic = [Dictionary new];
  }
  n = [selcltn size];
  if ((val = [seldic atKey:selname])) {
    return [val asInt];
  } else {
    [selcltn add:selname];
    [seldic atKey:selname put:[String sprintf:"%i", n]];
  }
  return n;
}

- (int)fwdoffset:msg
{
  int n;
  id val;

  if (!fwdcltn) {
    fwdcltn = [OrdCltn new];
    msgdic = [Dictionary new];
  }
  n = [fwdcltn size];
  /* try to find another selector with same argument types */
  /* see -hash and -isEqual: */
  /* it's okay if this fails, it will just generate more code */
  if ((val = [msgdic atKey:msg])) {
    if (o_debuginfo) {
      id x = [msg selector];
      id y = [[fwdcltn at:[val asInt]] selector];

      fprintf(stderr, "using '%s' dispatch fun for '%s'\n", [y str], [x str]);
    }
    return [val asInt];
  } else {
    [fwdcltn add:msg];
    [msgdic atKey:msg put:[String sprintf:"%i", n]];
  }
  return n;
}

- genmodclslst
{
  int i, n;

  assert(clsimpls && !o_oneperfile);
  gs("static id _modClsLst[] ={\n");
  for (i = 0, n = [clsimpls size]; i < n; i++) {
    STR s = [[clsimpls at:i] classname];

    /* &_Foo is the value of "id Foo := (id)&_Foo" */
    gf("(id)&_%s,\n", s);
  }
  /* must be NULL terminated */
  gs("(id)0};\n");
  return self;
}

- genseltranstbl
{
  int i, n = (selcltn) ? [selcltn size] : 0;

  gs("static char *_selTransTbl[] ={\n");
  for (i = 0; i < n; i++) {
    STR s = [[selcltn at:i] str];

    gf("\"%s\",\n", s);
  }
  /* always at least one entry (SGI cc chokes on empty decls) */
  gs("0\n};\n");
  return self;
}

- genfwdstubs
{
  int i, n;

  /* this can generate a lot of output
   * a good test in -fwdoffset: is important to reduce the size of gen. code
   */
  n = (fwdcltn) ? [fwdcltn size] : 0;
  for (i = 0; i < n; i++) {
    id msg = [fwdcltn at:i];

    [msg genargstruct];
    [msg gendispfun];
    [msg genfwdstub];
  }
  return self;
}

- genfwdtranstbl
{
  int i, n;

  n = (fwdcltn) ? [fwdcltn size] : 0;

  if (o_cplus) {
    gs("static id (*(_fwdTransTbl[]))(...) ={\n");
  } else {
    gs("static id (*(_fwdTransTbl[]))() ={\n");
  }

  for (i = 0; i < n; i++) {
    char *s = [[fwdcltn at:i] fwdname];

    if (o_cplus) {
      gf("(id(*)(...))%s,\n", s);
    } else {
      gf("(id(*)())%s,\n", s);
    }
  }

  /* always at least one entry (SGI cc chokes on empty decls)    */
  if (o_cplus) {
    gs("(id(*)(...))0\n};\n");
  } else {
    gs("(id(*)())0\n};\n");
  }

  return self;
}

/* the modClsLst field is either a pointer to a class (one per file case) */
/* or it is a pointer to a list with >= 2 class pointers (more than one) */
/* our runtime must be compatible with both cases */

#define MOD_MORETHANONE 0x4L	/* must match objcrt.m value !! */

- genmoddesc
{
  int selsize = (selcltn) ? [selcltn size] : 0;
  long modstatus = (clsimpls) ? MOD_MORETHANONE : 0;

#ifdef MODDESCSTATIC
  gs("static");
#endif
  gf("struct modDescriptor %s = {\n", moddescname);
  gf("  \"%s\",\n", modname);
  gf("  \"%s\",\n", modversion);
  gf("  %iL,\n", modstatus);
/* min/max are probably used by objcc at runtime for checking pointer range */
  gs("  0,\n");			/* modMinSel */
  gs("  0,\n");			/* modMaxSel */
  if (clsimpl) {
    /* this is the "one class per file" case */
    char *cname = [clsimpl classname];

    gf("  &%s,\n", cname);
  } else {
    if (clsimpls) {
      /* this is the more than one case */
      assert([clsimpls size] >= 2);
      gs("  _modClsLst,\n");	/* modClsLst */
    } else {
      gs("  0,\n");		/* NULL modClsLst */
    }
  }
  if (selsize) {
    gf("  %i,\n", selsize);	/* modSelRef */
    gs("  _selTransTbl,\n");	/* modSelTbl */
  } else {
    gs("  0,\n");		/* modSelRef */
    gs("  0,\n");		/* modSelTbl */
  }
  /* we don't support static references _mapTbl */
  /* this is just here for Stepstone compatibility */
  gs("  0\n};\n");		/* modMapTbl */
  return self;
}

- genglobfuncall
{
  id all = [self allclsimpls];

  if (all)
    [all elementsPerform:@selector(genglobfuncall)];
  return self;
}

- genbindfun
{
  /* for DLL's have to emit bind string */
  gf("struct modDescriptor %s*%s(void)\n{\n", o_bind, bindfunname);
  gs("  selTransTbl = _selTransTbl;\n");
  if (o_fwd) {
    gs("  fwdTransTbl = _fwdTransTbl;\n");
  }
  /* can't have global data shared across windows DLL's */
  if (!o_shareddata)
    [self genglobfuncall];
  gf("  return &%s;\n}\n", moddescname);
  return self;
}

- usesentry:name
{
  if (!usesentries)
    usesentries = [Set new];
#ifdef TRACEOCU
  if (o_debuginfo)
    fprintf(stderr, "OCU use %s\n", [name str]);
#endif
  [usesentries add:name];
  return self;
}

- definesentry:name
{
  if (!definesentries)
    definesentries = [Set new];
#ifdef TRACEOCU
  if (o_debuginfo)
    fprintf(stderr, "OCU defines %s\n", [name str]);
#endif
  [definesentries add:name];
  return self;
}

- (BOOL)definesmain
{
  return [definesentries contains:s_main];
}

- genusesentries
{
  id seq, entry;

  if (o_comments) {
    gs("/* Objective C Use (OCU) entries */\n");
  }
  seq = [usesentries eachElement];
  while ((entry = [seq next])) {
    char *s = [entry str];

    /* define an uninitialized global for the entry */
    /* goes into bss segment *if* no matching define entry */
    if (o_attrcommon)
      gs("__attribute__((__common__)) ");
    gf("struct useDescriptor *OCU_%s;\n", s);
  }
  return self;
}

- genusecontrol
{
  id seq, entry;

  gs("static struct useDescriptor **_useControl[] = {\n");

  seq = [usesentries eachElement];
  while ((entry = [seq next])) {
    char *s = [entry str];

    gf("  &OCU_%s,\n", s);
  }
  gs("0};\n");
  gs("static struct useDescriptor _useDesc = {\n");
  gs("  0,\n");			/* processed */
  gs("  0,\n");			/* next */
  gs("  _useControl,\n");	/* uses */
  gf("  %s", bindfunname);	/* bind */
  gs("\n};\n");

  return self;
}

- gendefinesentries
{
  id seq, entry;

  if (o_comments)
    gs("/* Objective C Use (OCU) defines */\n");

  seq = [definesentries eachElement];
  while ((entry = [seq next])) {
    char *s = [entry str];

    if (o_attrcommon)
      gs("__attribute__((__common__)) ");
    gf("struct useDescriptor *OCU_%s = &_useDesc;\n", s);
  }

  return self;
}

- genocu
{
  gs("struct useDescriptor {\n");
  gs("  int processed;\n");
  gs("  struct useDescriptor *next;\n");
  gs("  struct useDescriptor ***uses;\n");
  gs("  struct modDescriptor *(*bind)();\n");
  gs("};\n");

  [self genusesentries];
  [self genusecontrol];
  [self gendefinesentries];

  /* turn *on* auto-initialization code by defining the postlink
   * entry point (objcModules) as zero (non-zero -> postlink).
   */

  if ([self definesmain]) {
    gs("struct modEntry *_objcModules = 0;\n");
  }
  return self;
}

- postlinkmark
{
  /* the postLink version doesn't need the OCU entries
   * however, we want to 'mark' the .o file as being
   * compiled with -postlink, so that when linking
   * against a library that was compiled with -postlink
   * we could automatically detect this (and use postlink).
   */

  gf("int _OBJCPOSTLINK_%s = 1;\n", modname);
  if ([self definesmain]) {
    gs("struct useDescriptor *OCU_main = 0;\n");
  }
  return self;
}

- otbmark
{
  gf("int _OBJCOTB_%s = 1;\n", modname);
  return self;
}

- epilogue
{
  id e;

  o_nolinetags++;

  if (curclassdef) {
    [curclassdef warnpending];
  }
  if (o_comments) {
    gs("\n/* objc epilogue */\n");
  } else {
    gc('\n');
  }

  if ((e = [self allclsimpls])) {
    [e elementsPerform:@selector(genimpl)];
  }
  if (o_fwd) {
    [self genfwdstubs];
    [self genseltranstbl];
    [self genfwdtranstbl];
  } else {
    [self genseltranstbl];
  }

  if (clsimpls) {
    [self genmodclslst];
  }
  [self genmoddesc];
  [self genbindfun];

  if (o_postlink) {
    [self postlinkmark];
  } else {
    [self genocu];
  }

  if (o_otb) {
    [self otbmark];
  }
  gc('\n');
  gc('\n');
  o_nolinetags--;
  return self;
}

- (BOOL)istypeword:node
{
  if (builtintypes != nil && [builtintypes find:node] != nil)
    return YES;
  if (types != nil && [types includes:node])
    return YES;
  return NO;
}

- (BOOL)isbuiltinfun:node
{
  return builtinfuns != nil && [builtinfuns find:node] != nil;
}

- defbuiltinfun:node
{
  if (!builtinfuns)
    builtinfuns = [Set new];
  [builtinfuns add:node];
  return self;
}

- defbuiltintype:node
{
  if (!builtintypes)
    builtintypes = [Set new];
  [builtintypes add:node];
  return self;
}

- def:node astype:aType 
{
  if (!typedic) {
    typedic = [Dictionary new];
    types = [Set new];
  }
  if (o_debuginfo) {
    fprintf(stderr, "typedef %s as '", [node str]);
    gstderr();
    [aType gen];
    gnormal();
    fprintf(stderr, "'\n");
  }
  [types add:node];
  assert([aType isKindOf:(id) [Type class]]);
  [typedic atKey:node put:aType];
  return self;
}

- defenumtor:e
{
  if (!enumtors)
    enumtors = [Set new];
  [enumtors add:e];
  return self;
}

- lookupenumtor:sym
{
  return (enumtors) ? [enumtors find : sym]:nil;	/* works for Symbol class */
}

- defstruct:e
{
  if (!structdefs)
    structdefs = [Set new];
  [structdefs add:e];
  return self;
}

- lookupstruct:e
{
  return (structdefs) ? [structdefs find : e]:nil;
}

- lookuptype:sym
{
  return (typedic) ? [typedic atKey : sym]:nil;
}

- lookupglobal:sym
{
  return (globaldic) ? [globaldic atKey : sym]:nil;
}

- lookupdef:sym
{
  return (defdic) ? [defdic atKey:sym] : nil;
}

- def:sym as:d
{
  if (!defdic) {
    defdic = [Dictionary new];
  }
  [defdic atKey:sym put:d];
  return self;
}

- defdata:node astype:aType 
{
  if (!globaldic) {
    globaldic = [Dictionary new];
    globals = [Set new];
  }
  [globals add:node];
  assert([aType isKindOf:(id) [Type class]]);
  [globaldic atKey:node put:aType];
  return self;
}

- def:sym asclass:classdef
{
  if (!classdefs)
    classdefs = [Dictionary new];
  [classdefs atKey:sym put:classdef];
  return self;
}

- lookupclass:sym
{
  return [classdefs atKey:sym];
}

- lookupmethod:sel
{
  return [methods atKey:sel];
}

- def:sel asmethod:method
{
  if (!methods)
    methods = [Dictionary new];
  [methods atKey:sel put:method];
  return self;
}

- addgentype:s
{
  if (!gentypes)
    gentypes = [Set new];
  [gentypes add:s];
  return self;
}

- (BOOL)isgentype:s
{
  return [gentypes includes:s];
}

- go
{
  if (clsimpl) [clsimpl go];
  if (clsimpls) [clsimpls elementsPerform:_cmd];
  return self;
}

- reset
{
  id v,s;
  v=[defdic eachValue];
  while ((s=[v next])) [s reset];
  return self;
}

- inspectbutton
{
  printf("name=INSPECT\n");
  printf("button=2\n");
  printf("action=open Menu.$LININFO\n");
  return self;
}


- browseallclasses
{
  FILE *f;
  id sorted;
  id c,classes;
  sorted = [SortCltn new];
  classes = [classdefs eachValue];  
  while ((c = [classes next])) {
    [sorted add:c];
    [c browse];
  }
  f = freopen(browsepath("Menu.classes"),"w",stdout);
  if (!f) {
    fatal("cannot open Menu.classes for writing\n");
    return self;
  }
  printf("menu=Classes\n");
  classes = [sorted eachElement];
  while ((c = [classes next])) {
    printf("name='%s'\n",[c classname]);
    printf("action=open Menu.%s\n",[c classname]);
  }
  fclose(f);
  return self;
}

- findsubclasses:s
{
  id sorted;
  id c,classes;
  sorted = [SortCltn new];
  classes = [classdefs eachValue];  
  while ((c = [classes next])) {
    if ([c superclassdef] == s) [sorted add:c];
  }
  return sorted;
}

- browsesubclasses:c filename:(char*)filename title:(char*)title
{
  int i;
  FILE*f;
  id d,e,subclasses,classes;
  
  f = freopen(browsepath(filename),"w",stdout);
  if (!f) {
    fatal("cannot open %s for writing\n",filename);
    return self;
  }

  printf("menu=%s\n",title);

  classes = [c eachElement];
  subclasses = [OrdCltn new];
  while ((d = [classes next])) {
    [subclasses add:[self findsubclasses:d]];
  }

  i = 0;
  classes = [c eachElement];
  while ((d = [classes next])) {
    e = [subclasses at:i++];
    if ([e size]) {
      printf("name='%s...'\n",[d classname]);
      printf("lininfo='%s'\n",[d classname]);
      printf("action=open Menu.sub%s\n",[d classname]);
    } else {
      printf("name='%s'\n",[d classname]);
      printf("lininfo='%s'\n",[d classname]);
      printf("action=none\n");
    }
  }
  [self inspectbutton];
  fclose(f);

  i = 0;
  classes = [c eachElement];
  while ((d = [classes next])) {
    e = [subclasses at:i++];
    if ([e size]) {
      id fn = [String sprintf:"Menu.sub%s",[d classname]];
      [self browsesubclasses:e filename:[fn str] title:[d classname]];
    }
  }

  return self;
}

- browsemain
{
  FILE*f = freopen(browsepath("Menu.main"),"w",stdout);
  if (!f) {
    fatal("cannot open Menu.main for writing\n");
    return self;
  }

  printf("menu=Browser\n");
  printf("name=Classes\n");
  printf("action=open Menu.classes\n");
  printf("name=Class Hierarchy\n");
  printf("action=open Menu.root\n");
  printf("name=Unix shell\n");
  printf("action=unix-system\n");
  printf("name=Quit\n");
  printf("action=exit\n");
  fclose(f);
  return self;
}

- browse
{
  id rootclasses;
  assert(o_browsedir);
  [self browsemain];
  [self browseallclasses];
  rootclasses = [self findsubclasses:nil];
  [self browsesubclasses:rootclasses filename:"Menu.root" title:"Root"];
  return self;
}

@end
 
