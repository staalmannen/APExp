/*
 * readfile.c - Read an entire file into a string.
 *
 * Arnold Robbins
 * Tue Apr 23 17:43:30 IDT 2002
 * Revised per Peter Tillier
 * Mon Jun  9 17:05:11 IDT 2003
 * Revised for new dynamic function facilities
 * Mon Jun 14 14:53:07 IDT 2004
 */

/*
 * Copyright (C) 2002, 2003, 2004, 2011 the Free Software Foundation, Inc.
 * 
 * This file is part of GAWK, the GNU implementation of the
 * AWK Programming Language.
 * 
 * GAWK is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * GAWK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#include "awk.h"
#include <fcntl.h>

#ifndef O_BINARY
#define O_BINARY 0
#endif

int plugin_is_GPL_compatible;

/* do_readfile --- read a file into memory */

NODE *
do_readfile(int nargs)
{
	NODE *filename;
	int ret = -1;
	struct stat sbuf;
	char *text;
	int fd;

	if  (do_lint && get_curfunc_arg_count() > 1)
		lintwarn("readfile: called with too many arguments");

	filename = get_scalar_argument(0, FALSE);
	if (filename != NULL) {
		(void) force_string(filename);

		ret = stat(filename->stptr, & sbuf);
		if (ret < 0) {
			update_ERRNO();
			goto done;
		} else if ((sbuf.st_mode & S_IFMT) != S_IFREG) {
			errno = EINVAL;
			ret = -1;
			update_ERRNO();
			goto done;
		}

		if ((fd = open(filename->stptr, O_RDONLY|O_BINARY)) < 0) {
			ret = -1;
			update_ERRNO();
			goto done;
		}

		emalloc(text, char *, sbuf.st_size + 2, "do_readfile");
		memset(text, '\0', sbuf.st_size + 2);

		if ((ret = read(fd, text, sbuf.st_size)) != sbuf.st_size) {
			(void) close(fd);
			ret = -1;
			update_ERRNO();
			goto done;
		}

		close(fd);
		return make_string(text, sbuf.st_size);
	} else if (do_lint)
		lintwarn("filename: called with no arguments");


done:
	/* Set the return value */
	return make_number((AWKNUM) ret);
}


/* dlload --- load new builtins in this library */

NODE *
dlload(tree, dl)
NODE *tree;
void *dl;
{
	make_builtin("readfile", do_readfile, 1);

	return make_number((AWKNUM) 0);
}
