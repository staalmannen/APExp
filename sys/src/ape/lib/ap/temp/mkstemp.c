/*
 * mkstemp/mkostemp -- create and open a unique temporary file.
 *
 * See mktemp.c for the bug these shared: the old mktemp could name
 * only 26 files per process, so the 27th temporary any program asked
 * for failed, and coreutils `sort' on a large file died with
 * `cannot create temporary file in '/tmp': empty file name'.
 *
 * THE LOOP HERE WAS PART OF IT. Twenty retries look like robustness,
 * but each called mktemp with the same template from the same pid,
 * and the old mktemp was a pure function of exactly those -- so the
 * twenty attempts produced the same twenty-six candidates and the
 * retry bought nothing at all. *A retry is only a retry if something
 * varies between the tries.*
 *
 * Now shaped like mkdtemp beside it: generate, try, repeat, with
 * __randname supplying the variation.
 */
#define _BSD_SOURCE
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

extern char *__randname(char *);

/*
 * Version marker, as _sock_listenmark/_execmark/_ttymark/_fdinfomark
 * are for their fixes. `pcc -o x x.c' relinks against the INSTALLED
 * libap, so a test built from a fresh pull can measure days-old
 * library code and say nothing; a test that calls this will not LINK
 * against a libap predating the fix.
 *
 *	1  mktemp/mkstemp use __randname rather than 26 names per pid
 */
int
_tempmark(void)
{
	return 1;
}

int
mkstemp(char *template)
{
	size_t l;
	int retries, fd;

	l = strlen(template);
	if(l < 6 || memcmp(template + l - 6, "XXXXXX", 6) != 0){
		errno = EINVAL;
		return -1;
	}

	/*
	 * O_EXCL is what makes this safe where bare mktemp is not: a
	 * name taken between generating it and opening it fails the
	 * open, and we go round again with a different one.
	 *
	 * Only EEXIST is worth retrying. A bad directory, a denied
	 * permission or no free descriptors will not improve, and
	 * retrying those a hundred times only delays the real
	 * message -- which is how the original failure presented,
	 * with the true cause twenty attempts behind the report.
	 */
	for(retries = 100; retries > 0; retries--){
		__randname(template + l - 6);
		if((fd = open(template, O_RDWR | O_CREAT | O_EXCL, 0600)) >= 0)
			return fd;
		if(errno != EEXIST)
			break;
	}

	/* POSIX leaves the template unspecified on failure; restoring
	 * it is what mkdtemp does, and it lets a caller retry or print
	 * the template without showing a half-formed name. */
	memcpy(template + l - 6, "XXXXXX", 6);
	return -1;
}

int
mkostemp(char *template, int flags)
{
	int fd;

	fd = mkstemp(template);
	if(fd < 0)
		return -1;
	/*
	 * O_CLOEXEC is the one flag POSIX allows here beyond the
	 * implied ones, and coreutils passes exactly that. Plan 9's
	 * open() has no such bit, so it is applied afterwards rather
	 * than silently dropped: a descriptor that survives an exec
	 * when the caller asked for the opposite is the "stub that
	 * answers the wrong thing" shape this tree keeps meeting.
	 */
	if(flags & O_CLOEXEC)
		fcntl(fd, F_SETFD, FD_CLOEXEC);
	return fd;
}
