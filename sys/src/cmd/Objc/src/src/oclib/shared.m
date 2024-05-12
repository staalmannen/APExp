
/*
 * Copyright (c) 1998,1999,2000 David Stes.
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
 * $Id: shared.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
 */

/* some methods to which both compound statement and block expr respond */

- enclosing
{
  return enclosing;
}

- addtmpvar:tvar
{
  if (!tmpvars)
    tmpvars = [OrdCltn new];
  [tmpvars add:tvar];
  return self;
}

- addicache:tvar
{
  if (!icaches)
    icaches = [OrdCltn new];
  [icaches add:tvar];
  return self;
}

- addincref:v
{
  if (!increfs)
    increfs = [OrdCltn new];
  [increfs add:v];
  return self;
}

- genincrefs
{
  int i, n = [increfs size];

  for (i = 0; i < n; i++) {
    if (lbrace) gl([lbrace lineno],[[lbrace filename] str]);
    gf("idincref(%s);\n", [[increfs at:i] str]);
  }
  gc('\n');
  return self;
}

- adddecref:v
{
  if (!decrefs)
    decrefs = [OrdCltn new];
  [decrefs add:v];
  /* get this to be added to both curcompound and stmt of for(;;) */
  if (curloopcompound && self != curloopcompound)
    [curloopcompound adddecref:v];
  return self;
}

- gendecrefs
{
  int i, n = [decrefs size];

  for (i = 0; i < n; i++) {
    char *s = [[decrefs at:i] str];

    if (rbrace) gl([rbrace lineno],[[rbrace filename] str]);
    gf("%s=iddecref(%s);\n", s, s);
  }
  gc('\n');
  return self;
}

- lookuplocal:sym
{
  return (localdic) ? [localdic atKey : sym]:nil;
}

- deflocal:sym astype:t
{
  if (!localdic) {
    localdic = [Dictionary new];
    locals = [OrdCltn new];
  }
  [localdic atKey:sym put:t];
  [locals add:sym];
  if (curdef && ([curdef ismethdef])) {
    assert(curclassdef);
    if ([curclassdef isivar:sym]) {
      warnat(sym, "definition of local '%s' hides instance variable", [sym str]);
    }
    if ([curclassdef iscvar:sym]) {
      warnat(sym, "definition of local '%s' hides class variable", [sym str]);
    }
  }
  return self;
}

- genheapvarptr
{
  char *p = heapvarptrname;
  char *t = heapvartypename;

  assert(heapnames);
  /* this must be a Calloc to set the refcnt to 0 and for 'id' vars */
  gf("%s *%s=(%s *)OC_Calloc(sizeof(%s));\n", t, p, t, t);
  return self;
}

- freeheapvarptr
{
  char *p = heapvarptrname;

  gf("if (%s->heaprefcnt-- == 0) {\n",p);
  if (o_refcnt) [self gendecrefsheapvars];
  gf("OC_Free(%s);\n",p);
  gs("}\n");

  return self;
}

- gendecrefsheapvars
{
  int i, n = [heapnames size];
  char *hvp = heapvarptrname;

  for (i = 0; i < n; i++) {
    id x = [heapnames at:i];
    id t = [heaptypes at:i];

    assert(t != nil);
    if ([t isid]) {
      char *s = [x str];
      gf("%s->%s=iddecref(%s->%s);\n", hvp,s,hvp, s);
    }
  }
  return self;
}

- genheapvartype
{
  int i, n = [heapnames size];

  if (!n)
    return self;
  gf("%s {\n", heapvartypename);
  gs("int heaprefcnt;\n");
  for (i = 0; i < n; i++) {
    id x = [heapnames at:i];
    id t = [heaptypes at:i];

    assert(t != nil);
    [t gendef:x];
    gs(";\n");
  }
  gs("};\n");
  return self;
}

- heapvars
{
  return nil;
}

- (BOOL)isheapvar:x
{
  return (heapvars) ? [heapvars contains : x]:NO;
}

- defheapvar:x type:t
{
  int i;

  if (!heapvars) {
    heapvars = [Set new];
    heapnames = [OrdCltn new];
    heaptypes = [OrdCltn new];
    i = [trlunit heapvarcount];
    heapvarptrname = [[String sprintf:"heapvars%i", i] strCopy];
    heapvartypename = [[String sprintf:"struct heaptype%i", i] strCopy];
  }
  if ([t isstatic]) {
    char *msg = "can't use static local variables (%s) from within block";

    fatalat(x, msg, [x str]);
  } else {
    if ([heapvars addNTest:x] != nil) {
      [heapnames add:x];
      [heaptypes add:t];
    }
  }
  return self;
}

- (char*)heapvarptrname
{
  assert(heapvarptrname);
  return heapvarptrname;
}

- (char*)heapvartypename
{
  assert(heapvartypename);
  return heapvartypename;
}

- removeheapvarsfromdatadefs
{
  int n;

  assert(heapvars);
  initializers = [OrdCltn new];

  if (parmnames) {
    n = [parmnames size];
    while (n--) {
      id p = [parmnames at:n];

      if ([heapvars contains:p]) {
	id x = [[mkidentexpr(p) lhsself:YES] synth];
	id y = mkidentexpr(p);	/* don't synth */

	[initializers add:mkexprstmt(mkassignexpr(x, "=", y))];
      }
    }
  }
  if (datadefs) {
    n = [datadefs size];
    while (n--) {
      id def = [datadefs at:n];

      [def removevars:heapvars initializers:initializers];
      if ([def decllist] == nil)
	[datadefs removeAt:n];
    }
  }
  if ([datadefs size] == 0)
    datadefs = nil;
  return self;
}

- fcall:x
{
  if ([x size] < [parmnames size]) {
    return [self error:"Arguments expected"];
  } else {
    int i,n;
    assert(topframe !=nil && [topframe compound] == nil);
    for(i=0,n=[parmnames size];i<n;i++) { 
      [topframe defval:[parmnames at:i] as:[x at:i]];
    }
    [self go];
    if ([topframe quitframe]) {
      return [topframe returnval];
    } else {
      return nil;
    }
  }
}

- switchOn:(BOOL)dosw:e
{
  int i,n;
  BOOL quit = NO;
  BOOL dobrk = NO;
  BOOL docont = NO;
  id frame = [[Stackframe push] compound:self];
  if (datadefs) [datadefs elementsPerform:@selector(go)];
  i = 0;
  n = [stmts size];
  if (dosw) for(;i<n;i++) {
    if ([[stmts at:i] iscaseOf:e]) break;
  } 
  for(;i<n;i++) {
     [[stmts at:i] go];
     if ((quit=[frame quitframe])) break;
     if ((docont=[frame contframe])) break;
     if ((dobrk=[frame breakframe])) break;
  }
  [Stackframe pop];
  if (quit) {
    [topframe quitframe:YES];
    [topframe returnval:[frame returnval]];
  }
  if (docont) [topframe contframe:YES];
  if (dobrk) [topframe breakframe:YES];
  return self;
}

- switchOn:e
{
  return [self switchOn:YES:e];
}

- go
{
  return [self switchOn:NO:nil];
}

