/*	$OpenBSD: tty_subs.c,v 1.17 2016/08/26 04:22:13 guenther Exp $	*/
/*	$NetBSD: tty_subs.c,v 1.5 1995/03/21 09:07:52 cgd Exp $	*/

/*-
 * Copyright (c) 2012, 2014, 2016
 *	mirabilos <m@mirbsd.org>
 * Copyright (c) 1992 Keith Muller.
 * Copyright (c) 1992, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Keith Muller of the University of California, San Diego.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if HAVE_STRINGS_H
#include <strings.h>
#endif
#include <unistd.h>

#include "pax.h"
#include "extern.h"

__RCSID("$MirOS: src/bin/pax/tty_subs.c,v 1.13 2018/12/12 18:08:48 tg Exp $");

/*
 * routines that deal with I/O to and from the user
 */

/* device for interactive I/O */
static const char devtty[] = "/dev/tty";
/* file descriptor for accessing it */
static int ttyfd;

/*
 * tty_init()
 *	try to open the controlling terminal (if any) for this process. if the
 *	open fails, future ops that require user input will get an EOF
 */

int
tty_init(void)
{
	if ((ttyfd = binopen2(BO_CLEXEC, devtty, O_RDWR)) == -1 && iflag) {
		syswarn(1, errno, "Fatal error, cannot open %s", devtty);
		return (-1);
	}

	return (0);
}

/*
 * tty_prnt()
 *	print a message using the specified format to the controlling tty
 *	if there is no controlling terminal, just return.
 */

void
tty_prnt(const char *fmt, ...)
{
	va_list ap;
	char *cp;
	int len;

	va_start(ap, fmt);
	if (ttyfd != -1) {
		len = vasprintf(&cp, fmt, ap);
		if (len != -1) {
			dwrite(ttyfd, cp, len);
			free(cp);
		}
	}
	va_end(ap);
}

/*
 * tty_rd()
 *	read a string from the controlling terminal if it is open
 * Return:
 *	pointer caller must free if data was read, NULL otherwise
 */

char *
tty_rd(void)
{
	return (ttyfd == -1 ? NULL : fdgetline(ttyfd));
}

/*
 * paxwarn()
 *	write a warning message to stderr. if "set" the exit value of pax
 *	will be non-zero.
 */

void
paxwarn(int set, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	if (set)
		exit_val = 1;
	/*
	 * when vflag we better ship out an extra \n to get this message on a
	 * line by itself
	 */
	if (vfpart) {
		(void)fflush(listf);
		(void)fputc('\n', stderr);
		vfpart = 0;
	}
	(void)fprintf(stderr, "%s: ", argv0);
	(void)vfprintf(stderr, fmt, ap);
	va_end(ap);
	(void)fputc('\n', stderr);
}

/*
 * syswarn()
 *	write a warning message to stderr. if "set" the exit value of pax
 *	will be non-zero.
 */

void
syswarn(int set, int errnum, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	if (set)
		exit_val = 1;
	/*
	 * when vflag we better ship out an extra \n to get this message on a
	 * line by itself
	 */
	if (vfpart) {
		(void)fflush(listf);
		(void)fputc('\n', stderr);
		vfpart = 0;
	}
	(void)fprintf(stderr, "%s: ", argv0);
	(void)vfprintf(stderr, fmt, ap);
	va_end(ap);

	/*
	 * format and print the errno
	 */
	if (errnum > 0)
		(void)fprintf(stderr, ": %s", strerror(errnum));
	(void)fputc('\n', stderr);
}

/*
 * fdgetline()
 *	read a line from a file descriptor, similar to fgetln(3).
 *	caller must free(3) the result string.
 */

char fdgetline_err;

char *
fdgetline(int fd)
{
	size_t n = 0;
	char *rv = NULL;
	size_t z = 32;
	ssize_t rdr;
	char *np;
	int term;

	term = zeroflag ? '\0' : '\n';	/* path termination character */

	goto fdgetline_alloc;

	do {
		if (n == z) {
			z <<= 1;
			if (z < n) {
				/* overflow */
				break;
			}
 fdgetline_alloc:
			if ((np = realloc(rv, z)) == NULL) {
				/* allocation error */
				break;
			}
			rv = np;
		}

		rdr = read(fd, rv + n, 1);
		if (rdr == 0 && n == 0) {
			/* EOF reached, but nothing ever read */
			free(rv);
			rv = NULL;
			goto fdgetline_eod;
		}
		if (rdr == 0 || (rdr == 1 && rv[n] == term)) {
			/* EOF or EOL */
			rv[n++] = 0;
			if ((np = realloc(rv, n)) != NULL)
				rv = np;
 fdgetline_eod:
			fdgetline_err = 0;
			return (rv);
		}
		++n;
	} while (rdr == 1);

	/* fall through do-while if rdr > 1 (read too much) or < 0 (error) */
	/* get here via break on memory allocation errors */

	free(rv);
	fdgetline_err = 1;
	return (NULL);
}
