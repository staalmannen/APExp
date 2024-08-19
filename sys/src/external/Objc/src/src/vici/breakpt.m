
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
 * $Id: breakpt.m,v 1.1.1.1 2000/06/07 21:09:26 stes Exp $
 */

#include "config.h"
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>

#ifndef __OBJECT_INCLUDED__
#define __OBJECT_INCLUDED__
#include <stdio.h> /* FILE */
#include "Object.h" /* Stepstone Object.h assumes #import */
#include "Block.h" 
#endif
#include <ocstring.h>
#include <set.h>
#include <ordcltn.h>
#include <sequence.h>
#include <dictnary.h>

#include <node.h>
#include <options.h>
#include <def.h>
#include <fundef.h>

#include "cmd.h"
#include "breakpt.h"

#if USE_READLINE
#include <readline.h>
#endif

BOOL readcmdsflag;

void docmdf(FILE *f)
{
  extern int cmdmode;
  extern int yyparse();
  extern void yyrestart(FILE *);
  static id zprompt;
  infilename = (zprompt)?zprompt:(zprompt=[String str:"vici"]);
  vicicmds = [OrdCltn new];
  cmdmode = 1;
  yyrestart(f);
  yyparse();
  fclose(f);
  [vicicmds elementsPerform:@selector(go)];
}

void docmd(char *s)
{
  if (strlen(s) == 0) {
    /* repeat last command */
  } else {
    FILE *f = tmpfile();
    fprintf(f,"%s\n",s);
    fflush(f);
    rewind(f);
    docmdf(f);
  }
}

id vicibkpts;

@implementation Breakpoint

+ new
{
  id pt;
  static int cnt = 0;
  if (!vicibkpts) vicibkpts = [OrdCltn new];
  pt = [[[super new] setnum:cnt++] enabled:YES];
  [vicibkpts add:pt];
  return pt;
}

- (int)num
{
  return num;
}

- setnum:(int)x
{
  num=x;return self;
}

- (BOOL)enabled
{
  return enabled;
}

- enabled:(BOOL)x
{
  enabled = x;
  return self;
}

- (int)ignorecount
{
  return ignorecount;
}

- setignorecount:(int)x
{
  ignorecount = x;
  return self;
}

- prompt
{
  return prompt;
}

- prompt:x
{
  prompt = x;
  return self;
}

- readcmds
{
  readcmdsflag=YES;
  while (readcmdsflag) {
      if ([self readline]==nil) {
        fprintf(vistdout,"\n");
        exit(exitstatus);
      }
  }

  return self;
}

- readline
{
     char *b;
     if (prompt) fprintf(vistdout,"breakpoint:%s\n",[prompt str]);

#if USE_READLINE
     rl_instream = vistdin;
     rl_outstream = vistdout;
     b = readline(PRMPT);
#else
     b = malloc(8192+1);
     fprintf(vistdout,PRMPT);fgets(b,8192,vistdin);
#endif
     if (b) {
        docmd(b); free(b);
        return self;
     } else {
        return nil; 
     }
}

- go
{
  [self readcmds];
  return self;
}

@end

