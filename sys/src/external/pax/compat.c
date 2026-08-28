/*-
 * Copyright © 2019, 2020
 *	mirabilos <m@mirbsd.org>
 * Copyright © 2018
 *	mirabilos <t.glaser@tarent.de>
 * The copyright notices and licences of the files in .linked/ inclu‐
 * ded below shall be considered being part of this copyright notice.
 * Also contains material part of “jupp” (Joe’s Own Editor), © 2018
 *	mirabilos <m@mirbsd.org>
 * Contains code from “mksh” (The MirBSD Korn Shell) © 2015
 *	mirabilos <m@mirbsd.org>
 *	KO Myung-Hun <komh@chollian.net>
 *
 * Provided that these terms and disclaimer and all copyright notices
 * are retained or reproduced in an accompanying document, permission
 * is granted to deal in this work without restriction, including un‐
 * limited rights to use, publicly perform, distribute, sell, modify,
 * merge, give away, or sublicence.
 *
 * This work is provided “AS IS” and WITHOUT WARRANTY of any kind, to
 * the utmost extent permitted by applicable law, neither express nor
 * implied; without malicious intent or gross negligence. In no event
 * may a licensor, author or contributor be held liable for indirect,
 * direct, other damage, loss, or other issues arising in any way out
 * of dealing in the work, even if advised of the possibility of such
 * damage or existence of a defect, except proven that it results out
 * of said person’s immediate fault when using the work as intended.
 */

#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>

#include "compat.h"
#define PAX_JUST_THE_WARNINGS
#include "extern.h"

__RCSID("$MirOS: src/bin/pax/compat.c,v 1.6 2020/09/04 21:09:00 tg Exp $");

int
binopen3(int features, const char *path, int flags, mode_t mode)
{
	int fd;

#ifdef O_BINARY
	flags |= O_BINARY;
#endif
#ifdef O_CLOEXEC
	if (features & BO_CLEXEC) {
		flags |= O_CLOEXEC;
		features &= ~BO_CLEXEC;
	}
#endif
#ifdef O_DIRECTORY
	if (features & BO_MAYBE_DIR)
		flags |= O_DIRECTORY;
#endif

	if ((fd = (features & BO__TWO) ? open(path, flags) :
	    open(path, flags, mode)) != -1) {
#ifdef __OS2__
		setmode(fd, O_BINARY);
#endif
		if ((features & BO_CLEXEC) &&
		    fcntl(fd, F_SETFD, FD_CLOEXEC) == -1)
			syswarn(0, errno,
			    "Failed to set the close-on-exec flag");
	}
	return (fd);
}

ssize_t
dwrite(int fd, const void *data, size_t size)
{
	const unsigned char *buf = data;
	ssize_t rv = 0, z;

	while (size) {
		if ((z = write(fd, buf, size)) < 0) {
			if (errno == EINTR)
				continue;
			return (rv ? /* fucked up since we got some */ -2 : -1);
		}
		rv += z;
		buf += z;
		size -= z;
	}
	return (rv);
}

#if !HAVE_DPRINTF
#include <stdarg.h>
#include <string.h>
static char *dprintf_donum(char *, unsigned long long);

/* replacement only as powerful as needed for this */
void
dprintf(int fd, const char *fmt, ...)
{
	/* %s %llu %lu %d */
	const char *ccp;
	char *cp, buf[24];
	unsigned long long uval;
	va_list ap;

	va_start(ap, fmt);
 loop:
	switch (*fmt) {
	case 0:
		goto out;
	case '%':
		break;
	default:
		ccp = fmt;
		do {
			++ccp;
		} while (*ccp && *ccp != '%');
		if (dwrite(fd, fmt, ccp - fmt) < 0)
			goto out;
		fmt = ccp;
		goto loop;
	}
	switch (*++fmt) {
	case 'd': {
		int ival;

		ival = va_arg(ap, int);
		cp = buf;
		if (ival < 0) {
			*cp++ = '-';
			uval = -(long long)ival;
		} else
			uval = ival;
		goto num;
	}
	case 'l':
		switch (*++fmt) {
		case 'l':
			if (*++fmt != 'u') {
 errfmt:
				/* could do something about this? */
				goto loop;
			}
			uval = va_arg(ap, unsigned long long);
			break;
		case 'u':
			uval = va_arg(ap, unsigned long);
			break;
		default:
			goto errfmt;
		}
		cp = buf;
 num:
		*dprintf_donum(cp, uval) = '\0';
		cp = buf;
		if (0)
			/* FALLTHROUGH */
	case 's':
		  cp = va_arg(ap, char *);
		if (dwrite(fd, cp, strlen(cp)) < 0)
			goto out;
		break;
	default:
		goto errfmt;
	}
	++fmt;
	goto loop;

 out:
	va_end(ap);
}

static char *
dprintf_donum(char *cp, unsigned long long val)
{
	unsigned long long subval = val / 10;

	if (subval)
		cp = dprintf_donum(cp, subval);
	*cp++ = '0' + (val % 10);
	return (cp);
}
#endif

#if !HAVE_STRLCPY || !HAVE_STRLCAT
#undef WIDEC
#define OUTSIDE_OF_LIBKERN
#if !HAVE_STRLCPY
#define L_strlcat
#endif
#if !HAVE_STRLCAT
#define L_strlcpy
#endif
#include ".linked/strlfun.inc"
#endif
