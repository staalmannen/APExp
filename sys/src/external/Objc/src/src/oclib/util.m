
/*
 * Copyright (c) 1998,1999,2011 David Stes.
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
 * $Id: util.m,v 1.4 2011/06/13 21:54:16 stes Exp $
 */

#include "config.h"
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include <stdio.h> /* FILE */
#include "Object.h" /* Stepstone Object.h assumes #import */
#endif
#include "node.h"
#include <ordcltn.h>
#include <ocstring.h>
#include "symbol.h"
#include "cppdirec.h"
#include "util.h"
#include "options.h"
#include "stmt.h"
#include "ifstmt.h"
#include "whilstmt.h"
#include "switstmt.h"
#include "lblstmt.h"
#include "casestmt.h"
#include "dfltstmt.h"
#include "exprstmt.h"
#include "rtrnstmt.h"
#include "compstmt.h"
#include "contstmt.h"
#include "gotostmt.h"
#include "dostmt.h"
#include "forstmt.h"
#include "expr.h"
#include "listxpr.h"
#include "identxpr.h"
#include "constxpr.h"
#include "condxpr.h"
#include "castxpr.h"
#include "unyxpr.h"
#include "deref.h"
#include "addrof.h"
#include "sizeof.h"
#include "type.h"
#include "typeof.h"
#include "binxpr.h"
#include "msgxpr.h"
#include "blockxpr.h"
#include "selxpr.h"
#include "precxpr.h"
#include "dotxpr.h"
#include "arrowxpr.h"
#include "indexxpr.h"
#include "pfixxpr.h"
#include "commaxpr.h"
#include "relxpr.h"
#include "keywxpr.h"
#include "assign.h"
#include "funcall.h"
#include "btincall.h"
#include "funbody.h"
#include "method.h"
#include "selector.h"
#include "decl.h"
#include "pointer.h"
#include "arydecl.h"
#include "fundecl.h"
#include "namedecl.h"
#include "precdecl.h"
#include "stardecl.h"
#include "bflddecl.h"
#include "initdecl.h"
#include "keywdecl.h"
#include "pfixdecl.h"
#include "compdef.h"
#include "structsp.h"
#include "enumsp.h"
#include "enumtor.h"
#include "def.h"
#include "methdef.h"
#include "fundef.h"
#include "datadef.h"
#include "parmdef.h"
#include "parmlist.h"
#include "classdef.h"
#include "trlunit.h"
#include "gasmop.h"
#include "gasmstmt.h"
#include "gattrib.h"
#include "gatrdecl.h"

void 
procextdef(id def)
{
  [def synth];
  if (o_outputcode)
    [def gen];
  if (o_st80)
    [def st80];
}

void 
finclassdef(void)
{
  if (curclassdef) {
    if ([curclassdef numidivars]) {
      if (o_filer) {
	[curclassdef synthfilermethods];
      }
      if (o_refcnt) {
	[curclassdef synthrefcntmethods];
      }
    }
    if (o_warnmissingmethods && [curclassdef isimpl]) {
      [curclassdef warnimplnotfound];
    }
    curclassdef = nil;
  } else {
    fatal("illegal end of class definition.");
  }
}

FILE *
openfile(STR name, STR modfs)
{
  FILE *f;

  if ((f = fopen(name, modfs)) == NULL) {
    fprintf(stderr, "objc1: Unable to open %s\n", name);
    exit(1);
  }
  return f;
}

FILE *
reopenfile(STR name, STR modfs, FILE * of)
{
  FILE *f;

  if ((f = freopen(name, modfs, of)) == NULL) {
    fprintf(stderr, "objc1: Unable to open %s\n", name);
    exit(1);
  }
  return f;
}

static char *
setinlineno(char *s)
{
  char *p = s;
  int c, n = 0;

  while ((c = *p++) && '0' <= c && c <= '9') {
    n = n * 10 + (c - '0');
  }

  inlineno = n;
  return p - 1;
}

static BOOL 
setinfilename(char *s)
{
  char *p = s;
  int c, n = 0;

  while ((c = *p++) && c != '"')
    n++;

  /* implies no \" in filenames (yet) */
  if (c == '"') {
    infilename = [String chars:s count:n];
    return YES;
  } else {
    return NO;
  }
}

static BOOL 
isline(char *s)
{
  int c;
  char *p = s;

  /* match hash */
  c = *p++;
  if (c == '#') {
    c = *p++;
  } else {
    return NO;
  }

  /* optional whitespace */
  while (c && (c == ' ' || c == '\t'))
    c = *p++;

  /* accept both "# no name" and "# line no name" */
  if (c == 'l') {
    char *key = "ine";		/* l already consumed */

    if (strncmp(p, key, strlen(key)) == 0) {
      p += strlen(key);
      c = *p++;
    } else {
      return NO;
    }
  }
  /* optional whitespace */
  while (c && (c == ' ' || c == '\t'))
    c = *p++;

  /* get the line number */
  if (c && '0' <= c && c <= '9') {
    p = setinlineno(p - 1);
    c = *p++;
  } else {
    return NO;
  }

  /* optional whitespace */
  while (c && (c == ' ' || c == '\t'))
    c = *p++;

  /* get the filename */
  if (c && c == '"') {
    return setinfilename(p);
    /* ignore everything else on the line after the fn */
  } else {
    /* # lineno style (HP-UX emits #line without filename) */
    /* ignore everything else on the line after the fn */
    return YES;
  }
}

/* some pragma's for dealing with types such as __long_long or __int64 */
/* those are also supported by the Stepstone compiler */

static BOOL 
ispragma(char *s)
{
  char *t;
  id x = [String str:s];
  char *sep = " #/\t\n\r";

  t = strtok([x str],sep);
  if (strcmp(t,"pragma") != 0) return NO;
  if ((t = strtok(NULL,sep)) == NULL) return NO;

  if (strcmp(t,"OCbuiltInFctn") == 0) {
    definebuiltinfun(strtok(NULL,sep));
    return YES; /* do not emit */
  }
  if (strcmp(t,"OCbuiltInVar") == 0) {
    definebuiltinvar(strtok(NULL,sep));
    return YES; /* do not emit */
  }
  if (strcmp(t,"OCbuiltInType") == 0) {
    definebuiltintype(strtok(NULL,sep));
    return YES; /* do not emit */
  }
  if (strcmp(t,"OCRefCnt") == 0) {
    o_refcnt = pragmatoggle(strtok(NULL,sep));
    return YES; /* do not emit */
  }
  if (strcmp(t,"OCInlineCache") == 0) {
    o_inlinecache = pragmatoggle(strtok(NULL,sep));
    return YES; /* do not emit */
  }
  if (strcmp(t,"token") == 0) {
    if ((t = strtok(NULL,sep)) == NULL) return NO;

    /* tcc (tendra C compiler) stupid pragma (required for tcc compile) */
    if (strcmp(t,"TYPE") == 0) {
      definebuiltintype(strtok(NULL,sep));
      return NO; /* reemit */
    }

    /* tcc (tendra C compiler) stupid pragma (required for tcc compile) */
    if (strcmp(t,"VARIETY") == 0) {
       if ((t = strtok(NULL,sep)) == NULL) return NO;
       
       if (strcmp(t,"signed") == 0 || strcmp(t,"unsigned") == 0) {
          if ((t = strtok(NULL,sep)) == NULL) return NO;
       }

       definebuiltintype(t);
       return NO; /* reemit */
    }

    /* tcc (tendra C compiler) stupid pragma (required for tcc compile) */
    if (strcmp(t,"PROC") == 0) {
      /* #pragma token PROC (blahblah) foo # */
      while (1) {
	char *s;
	if ((s = strtok(NULL," \t\n\r")) == NULL) return NO;
	if (strcmp(s,"#") == 0) break;
	t = s;
      }
      definebuiltinfun(t);
      return NO; /* reemit */
    }
    
    /* other token pragma's as well (FUNC, EXP) don't seem to be needed */
    return NO;
  }
  return NO;
}

id 
mkcppdirect(char *s)
{
  id r;
  int n;
  char *t;

  if (isline(s))
    return nil;
  if (ispragma(s))
    return nil;

  /* (POC specific) #printLine #include blah emits #include blah */
  t = "#printLine ";
  n = strlen(t);
  if (strncmp(s, t, n) == 0)
    s += n;
  t = "#pragma printLine ";
  n = strlen(t);
  if (strncmp(s, t, n) == 0)
    s += n;
  /* SunOS cc turns space into tab after pragma */
  t = "#pragma\tprintLine ";
  n = strlen(t);
  if (strncmp(s, t, n) == 0)
    s += n;

  r = [CppDirective str:s lineno:inlineno filename:infilename];
  return r;
}

id 
mkexprstmt(id expr)
{
  id r = [ExprStmt new];
  [r expr:expr];
  return r;
}

id 
mkexprstmtx(id expr)
{
  id r = [ExprStmt new];
  [r expr:expr];
  [r forcenewline:YES];
  return r;
}

id 
mklabeledstmt(id label, id stmt)
{
  id r = [LabeledStmt new];

  [r label:label];
  [r stmt:stmt];
  return r;
}

id 
mkcasestmt(id keyw, id expr, id stmt)
{
  id r = [CaseStmt new];

  [r keyw:keyw];
  [r expr:expr];
  [r stmt:stmt];
  return r;
}

id 
mkdefaultstmt(id keyw, id stmt)
{
  id r = [DefaultStmt new];

  [r keyw:keyw];
  [r stmt:stmt];
  return r;
}

id 
mkifstmt(id keyw, id expr, id stmt)
{
  id r = [IfStmt new];

  [r keyw:keyw];
  [r expr:expr];
  [r stmt:stmt];
  return r;
}

id 
mkifelsestmt(id keyw, id expr, id stmt, id ekeyw, id estmt)
{
  id r = [IfStmt new];

  [r keyw:keyw];
  [r expr:expr];
  [r stmt:stmt];
  [r ekeyw:ekeyw];
  [r estmt:estmt];
  return r;
}

id 
mkswitchstmt(id keyw, id expr, id stmt)
{
  id r = [SwitchStmt new];

  [r keyw:keyw];
  [r expr:expr];
  [r stmt:stmt];
  return r;
}

id 
mkwhilestmt(id keyw, id expr, id stmt)
{
  id r = [WhileStmt new];

  [r keyw:keyw];
  [r expr:expr];
  [r stmt:stmt];
  return r;
}

id 
mkdostmt(id keyw, id stmt, id wkeyw, id expr)
{
  id r = [DoStmt new];

  [r keyw:keyw];
  [r stmt:stmt];
  [r wkeyw:wkeyw];
  [r expr:expr];
  return r;
}

id 
mkforstmt(id keyw, id a, id b, id c, id stmt)
{
  id r = [ForStmt new];

  [r keyw:keyw];
  [r begin:a cond:b step:c];
  [r stmt:stmt];
  return r;
}

id 
mkgotostmt(id keyw, id label)
{
  id r = [GotoStmt new];

  [r keyw:keyw];
  [r label:label];
  return r;
}

id 
mkcontinuestmt(id keyw)
{
  id r = [ContinueStmt new];

  [r keyw:keyw];
  return r;
}

id 
mkbreakstmt(id keyw)
{
  return mkcontinuestmt(keyw);
}

id 
mkreturnstmt(id keyw, id expr)
{
  id r = [ReturnStmt new];

  [r keyw:keyw];
  [r expr:expr];
  return r;
}

id 
mkreturnx(id x)
{
  return [[ReturnStmt new] expr:x];
}

id 
mkcastexpr(id a, id b)
{
  id r = [CastExpr new];

  [r cast:a];
  [r expr:b];
  return r;
}

id 
mkcondexpr(id a, id b, id c)
{
  id r = [CondExpr new];

  [r expr:a];
  [r lhs:b];
  [r rhs:c];
  return r;
}

id 
mkunaryexpr(STR op, id a)
{
  id r = [UnaryExpr new];

  [r op:op];
  [r expr:a];
  return r;
}

id 
mkdereference(id a)
{
  id r = [Dereference new];

  [r expr:a];
  return r;
}

id 
mksizeof(id a)
{
  id r = [SizeOf new];

  [r expr:a];
  return r;
}

id 
mktypeof(id kw,id a)
{
  id r = [TypeOf new];

  [r keyw:kw];
  [r expr:a];
  return r;
}

id 
mkaddressof(id a)
{
  id r = [AddressOf new];

  [r expr:a];
  return r;
}

id 
mkbinexpr(id a, STR op, id b)
{
  id r = [BinaryExpr new];

  [r lhs:a];
  [r rhs:b];
  [r op:op];
  return r;
}

id 
mkcommaexpr(id a, id b)
{
  id r = [CommaExpr new];

  [r lhs:a];
  [r rhs:b];
  return r;
}

id 
mkassignexpr(id a, STR op, id b)
{
  id r = [Assignment new];

  [r lhs:a];
  [r rhs:b];
  [r op:op];
  return r;
}

id 
mkrelexpr(id a, STR op, id b)
{
  id r = [RelationExpr new];

  [r lhs:a];
  [r rhs:b];
  [r op:op];
  return r;
}

id 
mkbuiltincall(id funname, id args)
{
  id r = [BuiltinCall new];

  [r funname:funname];		/* stuff like alignof() or sizeof() etc */
  [r funargs:args];
  return r;
}

id 
mkfuncall(id funname, id args)
{
  id r = [FunctionCall new];

  [r funname:funname];
  [r funargs:args];
  return r;
}

id 
mkfunbody(id datadefs, id compound)
{
  id r = [FunctionBody new];

  [r datadefs:datadefs];
  [r compound:compound];
  return r;
}

void 
declarefun(id specs, id decl)
{
  id d = [DataDef new];

  if (specs)
    [d specs:specs];
  [d add:decl];
  [d synth];
}

void 
declaremeth(BOOL factory, id decl)
{
  id r = [MethodDef new];

  [r factory:factory];
  [r method:decl];
  [r prototype];
}

id 
mkfundef(id specs, id decl, id body)
{
  id r = [FunctionDef new];

  [r datadefspecs:specs];
  [r decl:decl];
  [r body:body];
  return r;
}

id 
mkmethdef(BOOL factory, id decl, id body)
{
  id r = [MethodDef new];

  [r factory:factory];
  [r method:decl];
  [r body:body];
  return r;
}

id 
mkmesgexpr(id receiver, id args)
{
  id r = [MesgExpr new];

  [r receiver:receiver];
  [r msg:args];
  return r;
}

id 
mkdecl(id ident)
{
  id r = [NameDecl new];

  [r identifier:ident];
  return r;
}

id 
mkprecdecl(id typequals, id decl)
{
  id r = [PrecDecl new];

  if (typequals)
    [r typequals:typequals];
  if (decl)
    [r decl:decl];
  return r;
}

id 
mkarraydecl(id lhs, id ix)
{
  id r = [ArrayDecl new];

  [r decl:lhs];
  [r expr:ix];
  return r;
}

id 
mkfundecl(id lhs, id args)
{
  id r = [FunctionDecl new];

  [r decl:lhs];
  [r args:args];
  return r;
}

id 
mkprefixdecl(id lhs, id rhs)
{
  id r = [PostfixDecl new];

  [r prefix:lhs];
  [r decl:rhs];
  return r;
}

id 
mkpostfixdecl(id lhs, id rhs)
{
  id r = [PostfixDecl new];

  [r decl:lhs];
  [r postfix:rhs];
  return r;
}

id 
mkpointer(id specs, id pointer)
{
  id r = [Pointer new];

  if (specs)
    [r specs:specs];
  if (pointer)
    [r pointer:pointer];
  return r;
}

id 
mkbitfielddecl(id decl, id expr)
{
  id r = [BitfieldDecl new];

  [r decl:decl];
  [r expr:expr];
  return r;
}

id 
mkstardecl(id pointer, id decl)
{
  id r = [StarDecl new];

  [r pointer:pointer];
  [r decl:decl];
  return r;
}

id 
mkasmop(id aList, id expr)
{
  id r = [GnuAsmOp new];

  [r stringchain:aList];
  [r expr:expr];
  return r;
}

id 
mkasmstmt(id keyw, id typequal, id expr, id asmop1, id asmop2, id clobbers)
{
  id r = [GnuAsmStmt new];

  [r keyw:keyw];
  [r typequal:typequal];
  [r expr:expr];
  [r asmop1:asmop1];
  [r asmop2:asmop2];
  [r clobbers:clobbers];
  return r;
}

id 
mkcompstmt(id lbrace, id datadefs, id stmtlist, id subblock, id rbrace)
{
  id r = [CompoundStmt new];

  [r lbrace:lbrace];
  [r datadefs:datadefs];
  [r stmts:stmtlist];
  [r subblock:subblock];
  [r rbrace:rbrace];
  return r;
}

id 
mklist(id c, id s)
{
  if (c == nil)
    c = [OrdCltn new];
  assert(s != nil);
  [c add:s];
  return c;
}

id 
mklist2(id c, id s,id t)
{
  if (c == nil)
    c = [OrdCltn new];
  assert(s != nil);
  [c add:s];
  [c add:t];
  return c;
}

id 
atdefsadd(id c, id cls)
{
  id scls = [cls superclassdef];

  if (scls)
    atdefsadd(c, scls);
  [c addAll:[cls ivars]];
  return c;
}

id 
atdefsaddall(id c, id n)
{
  id cls;

  if (c == nil)
    c = [OrdCltn new];
  assert(n != nil);
  if ((cls = [trlunit lookupclass:n])) {
    atdefsadd(c, cls);
  } else {
    fatal("cannot find @defs of '%s'", [n str]);
  }
  return c;
}

id 
mkblockexpr(id lb, id parms, id datadefs, id stmts, id expr, id rb)
{
  id r = [BlockExpr new];

  [r lbrace:lb];
  [r parms:parms];
  [r datadefs:datadefs];
  [r stmts:stmts];
  [r expr:expr];
  [r rbrace:rb];
  return r;
}

id 
mkclassdef(id keyw, id name, id sname, id ivars, id cvars)
{
  id r;
  BOOL intfkeyw = (keyw != nil && strstr([keyw str], "interface") != NULL);
  BOOL implkeyw = (keyw != nil && strstr([keyw str], "implementation") != NULL);


  if ((r = [trlunit lookupclass:name])) {
    if (intfkeyw) {
      fatal("multiple interfaces for class %s.", [r classname]);
    } else {
      if (sname)
	[r checksupername:sname];
      if (ivars)
	[r checkivars:ivars];
      if (cvars)
	[r checkcvars:cvars];
    }
  } else {
    r = [ClassDef new];
    [r classname:name];
    [r supername:sname];
    [r ivars:ivars];
    [r cvars:cvars];
  }

  if (implkeyw)
    [r forceimpl];

  if (curclassdef) {
    warn("definition of %s not properly ended.", [curclassdef classname]);
    curclassdef = r;
  } else {
    curclassdef = r;
  }

  return r;
}

BOOL 
lhsisid(id specs, id decl)
{
  return [specs size] == 1 && [[specs at:0] isid] && [decl isKindOf:(id) [NameDecl class]];
}

void 
datadefokblock(id datadef, id specs, id decl)
{
  /* id aBlock = { :x | ... }; okblock = 1 */
  /* id *exprs = { [Object new], [Object new] }; okblock = 0 */

  if (specs) {
    okblock = lhsisid(specs, decl);
  } else {
    okblock = lhsisid([datadef specs], decl);
  }
}

id 
mkdatadef(id datadef, id specs, id decl, id initializer)
{
  if (datadef == nil)
    datadef = [DataDef new];
  if (specs)
    [datadef specs:specs];
  if (initializer) {
    decl = [[[InitDecl new] decl:decl] initializer:initializer];
  }
  [datadef add:decl];
  return datadef;
}

id 
mkencodeexpr(id name)
{
  return nil;
}

id 
mkenumspec(id keyw, id name, id lb, id list, id rb)
{
  id r = [EnumSpec new];

  [r keyw:keyw];
  [r name:name];
  [r lbrace:lb];
  if (list)
    [r enumtors:list];
  [r rbrace:rb];
  return r;
}

id 
mkenumerator(id name, id value)
{
  id r = [Enumerator new];

  [r name:name];
  if (value) [r value:value];
  return r;
}

id 
mkgnuattrib(id anyword, id exprlist)
{
  id r = [GnuAttrib new];

  [r anyword:anyword];
  [r exprlist:exprlist];
  return r;
}

id 
mkgnuattribdecl(id keyw, id list)
{
  id r = [GnuAttribDecl new];

  [r keyw:keyw];
  [r attribs:list];
  return r;
}

id 
mklistexpr(id lb, id x, id rb)
{
  id r = [ListExpr new];

  [r lbrace:lb];
  [r exprs:x];
  [r rbrace:rb];
  return r;
}

id 
mktypename(id specs, id decl)
{
  id r = [Type new];

  [r specs:specs];
  [r decl:decl];
  return r;
}

id 
mkcomponentdef(id cdef, id specs, id decl)
{
  if (cdef == nil)
    cdef = [ComponentDef new];
  if (specs)
    [cdef specs:specs];
  [cdef add:decl];
  return cdef;
}

id 
mkstructspec(id keyw, id name, id lb, id defs, id rb)
{
  id r = [StructSpec new];

  [r keyw:keyw];
  [r name:name];
  [r lbrace:lb];
  if (defs)
    [r defs:defs];
  [r rbrace:rb];
  return r;
}

id 
mkkeywarg(id sel, id arg)
{
  id r = [KeywExpr new];

  [r keyw:sel];
  [r arg:arg];
  return r;
}

id 
mkkeywdecl(id sel, id cast, id arg)
{
  id r = [KeywDecl new];

  [r keyw:sel];
  [r cast:cast];
  [r arg:arg];
  return r;
}

id 
mkmethproto(id cast, id usel, id ksel, BOOL varargs)
{
  id r = [Method new];

  [r restype:cast];
  [r unarysel:usel];
  [r keywsel:ksel];
  [r varargs:varargs];
  return r;
}

id 
mkidentexpr(id name)
{
  id r = [IdentifierExpr new];

  [r identifier:name];
  return r;
}

id 
mkconstexpr(id name, id schain)
{
  id r = [ConstantExpr new];

  if (name)
    [r identifier:name];
  if (schain)
    [r stringchain:schain];
  return r;
}

id 
mkprecexpr(id expr)
{
  id r = [PrecExpr new];

  [r expr:expr];
  return r;
}

id 
mkbracedgroup(id expr)
{
  [expr setbracedgroup:YES];
  return mkprecexpr(expr);
}

id 
mkarrowexpr(id array, id ix)
{
  id r = [ArrowExpr new];

  [r lhs:array];
  [r rhs:ix];
  return r;
}

id 
mkdotexpr(id array, id ix)
{
  id r = [DotExpr new];

  [r lhs:array];
  [r rhs:ix];
  return r;
}

id 
mkindexexpr(id array, id ix)
{
  id r = [IndexExpr new];

  [r lhs:array];
  [r rhs:ix];
  return r;
}

id 
mkpostfixexpr(id expr, id pf)
{
  id r = [PostfixExpr new];

  [r expr:expr];
  [r op:[pf strCopy]];
  return r;
}

id 
mkparmdef(id parmdef, id specs, id decl)
{
  id r = [ParameterDef new];

  if (specs)
    [r specs:specs];
  [r decl:decl];
  return r;
}

id 
mkparmdeflist(id idents, id parmdefs, BOOL varargs)
{
  id r = [ParameterList new];

  if (idents)
    [r idents:idents];
  if (parmdefs)
    [r parmdefs:parmdefs];
  [r varargs:varargs];
  return r;
}

id 
mkselarg(id sel, id usel, int ncols)
{
  if (sel == nil) {
    assert(ncols == 0 && usel != nil);
    sel = [Selector str:[usel strCopy]];
  } else {
    if (usel)
      [sel add:usel];
    while (ncols--)
      [sel addcol];
  }
  return sel;
}

id 
mkselectorexpr(id expr)
{
  id r = [SelectorExpr new];

  [r selector:expr];
  return r;
}

id 
mkfilesupermsg(id sel, id arg)
{
  id ksel, m;

  m = [MesgExpr new];
  [m receiver:e_super];
  ksel = [OrdCltn add:mkkeywarg(sel, arg)];
  [m msg:mkmethproto(nil, nil, ksel, NO)];
  return mkexprstmtx(m);
}

id 
mkfilemsg(id sel, id name)
{
  id ksel, m;

  m = [MesgExpr new];
  [m receiver:e_aFiler];
  ksel = [OrdCltn add:mkkeywarg(sel, mkaddressof(mkidentexpr(name)))];
  [ksel add:mkkeywarg(s_type, e_ft_id)];
  [m msg:mkmethproto(nil, nil, ksel, NO)];
  return mkexprstmtx(m);
}

id 
mkfileinoutmeth(id ssel, id fsel, id ivarnames, id ivartypes)
{
  id d, b, r;

  r = [MethodDef new];
  if ((d = [Method new])) {
    id ksel = [OrdCltn add:mkkeywdecl(ssel, nil, s_aFiler)];

    [d keywsel:ksel];
    [d canforward:NO];
    [r method:d];
  }
  [r prototype];
  if ((b = [CompoundStmt new])) {
    int i, n;
    id s = [OrdCltn new];

    [s add:mkfilesupermsg(ssel, e_aFiler)];
    for (i = 0, n = [ivartypes size]; i < n; i++) {
      if ([[ivartypes at:i] isrefcounted]) {
	[s add:mkfilemsg(fsel, [ivarnames at:i])];
      }
    }
    [s add:mkreturnx([e_self copy])];
    [b stmts:s];
    [r body:b];
  }
  return r;
}

id 
mkfileinmeth(id classdef, id ivarnames, id ivartypes)
{
  return mkfileinoutmeth(s_fileInIdsFrom, s_fileIn, ivarnames, ivartypes);
}

id 
mkfileoutmeth(id classdef, id ivarnames, id ivartypes)
{
  return mkfileinoutmeth(s_fileOutIdsFor, s_fileOut, ivarnames, ivartypes);
}

id 
mkrefsupermsg(id sel)
{
  id usel, m;

  m = [MesgExpr new];
  [m receiver:e_super];
  usel = sel;
  [m msg:mkmethproto(nil, usel, nil, NO)];
  return mkexprstmtx(m);
}

id 
mkrefmeth(id classdef, id ivarnames, id ivartypes, id ssel, id sfun)
{
  id d, b, r;
  id usel = [Selector str:[ssel strCopy]];

  r = [MethodDef new];
  if ((d = [Method new])) {
    [d unarysel:usel];
    [d canforward:NO];
    [r method:d];
  }
  [r prototype];
  if ((b = [CompoundStmt new])) {
    int i, n;
    id s = [OrdCltn new];
    id f = mkidentexpr(sfun);

    [s add:mkrefsupermsg(usel)];
    for (i = 0, n = [ivartypes size]; i < n; i++) {
      if ([[ivartypes at:i] isid]) {
	id e = mkidentexpr([ivarnames at:i]);

	[s add:mkexprstmtx(mkassignexpr(e, "=", mkfuncall(f, mklist(nil, e))))];
      }
    }
    [s add:mkreturnx([e_nil copy])];	/* nil so that self refcnt unchanged */
    [b stmts:s];
    [r body:b];
  }
  return r;
}

id 
mkincrefsmeth(id classdef, id ivarnames, id ivartypes)
{
  return mkrefmeth(classdef, ivarnames, ivartypes, s_increfs, s_idincref);
}

id 
mkdecrefsmeth(id classdef, id ivarnames, id ivartypes)
{
  return mkrefmeth(classdef, ivarnames, ivartypes, s_decrefs, s_iddecref);
}
 
