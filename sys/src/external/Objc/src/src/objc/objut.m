
/* 
 * Copyright (c) 1998-2023 David Stes
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

#include "config.h"

#include <string.h>		/* strtok */
#include <stdlib.h>		/* getenv */
#include <assert.h>
#include <objpak.h>
#include "node.h"
#include "trlunit.h"
#include "options.h"
#include "util.h"
#include "symbol.h"

/* objut (Object Unit Test) is a test program to check newly built libs */

int okblock = 1;
static int numclasses = 0;

static void
p(int tabs,id c)
{
    numclasses++;
    while (tabs--) printf("\t");printf("%s\n",[c name]);
}

static void
phierarchy(id c)
{
    int tabs = 0;
    id b = { :e | p(tabs++,e);[[e subclasses] do:b];tabs--;};
    [b value:c];
}

static int
psuccess(int ok)
{
  int exitcode = (ok)?0:1;
  printf("\n");
  printf("Object Unit Test: %s\n",(ok)?"success":"failure");
  exit(exitcode);
  return exitcode;
}

/*
 * idea here is to link an executable which like objc1
 * is processing TranlationUnit classes
 *
 * however here for testing purposes we just print some info
 * that can then be used as a basic regression test to see that the
 * produced executable (which uses a new runtime) is not simply core dumping
 *
 * if this program would crash (or core dump), then it makes no sense
 * to do a 'make install' obviously
 *
 */

int main(int argc, char *argv[])
{
  id trlunit = [TranslationUnit new];

  phierarchy(Object);

  printf("\n");
  printf("Object Unit Test: number of classes is %i\n",numclasses);

  return psuccess(numclasses == 105);
}

