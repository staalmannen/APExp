/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <string.h>
#include <stdlib.h>

#include <slibtool/slibtool.h>
#include "slibtool_visibility_impl.h"

slbt_hidden int slbt_txtline_to_string_vector(const char * txtline, char *** pargv)
{
	int             argc;
	char **         argv;
	const char *    ch;
	const char *    mark;

	if (!(ch = txtline))
		return 0;

	argc = 1;

	for (; *ch == ' '; )
		ch++;

	for (; *ch; ) {
		if (*ch++ == ' ') {
			argc++;

			for (; (*ch == ' '); )
				ch++;
		}
	}

	if (argc == 1)
		return 0;

	if (!(*pargv = calloc(++argc,sizeof(char *))))
		return -1;

	for (ch=txtline; (*ch == ' '); ch++)
		(void)0;

	argv = *pargv;
	mark = ch;

	for (; *ch; ) {
		if (*ch == ' ') {
			if (!(*argv++ = strndup(mark,ch-mark)))
				return -1;

			for (; (*ch == ' '); )
				ch++;

			mark = ch;
		} else {
			ch++;
		}
	}

	if (!(*argv++ = strndup(mark,ch-mark)))
		return -1;

	return 0;
}
