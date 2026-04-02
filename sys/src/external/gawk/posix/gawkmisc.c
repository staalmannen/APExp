/* gawkmisc.c --- miscellaneous gawk routines that are OS specific.

   Copyright (C) 1986, 1988, 1989, 1991 - 1998, 2001 - 2004, 2011,
   2021, 2022, 2023, 2025, 2026
   the Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */

#ifdef __CYGWIN__
#ifdef __MSYS__
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <sys/cygwin.h>
#endif
#include <io.h>		/* for declaration of setmode(). */
#endif

#ifdef HAVE_SYS_PERSONALITY_H	// for linux
#include <sys/personality.h>
#endif

#ifdef HAVE_SPAWN_H
#include <spawn.h>	// for macos
#endif

#ifdef HAVE__NSGETEXECUTABLEPATH
#include <mach-o/dyld.h>
#endif

#ifdef HAVE_SYS_PROCCTL_H
#include <sys/procctl.h>
#endif

#ifdef HAVE_SYS_SYSCTL_H
#include <sys/sysctl.h>
#endif

const char quote = '\'';
const char *defpath = DEFPATH;
const char *deflibpath = DEFLIBPATH;
const char envsep = ':';

#ifndef INVALID_HANDLE
/* FIXME: is this value for INVALID_HANDLE correct? */
#define INVALID_HANDLE -1
#endif

/* gawk_name --- pull out the "gawk" part from how the OS called us */

const char *
gawk_name(const char *filespec)
{
	const char *p;

	/* "path/name" -> "name" */
	p = strrchr(filespec, '/');
	return (p == NULL ? (char *) filespec : p + 1);
}

/* os_arg_fixup --- fixup the command line */

void
os_arg_fixup(int *argcp, char ***argvp)
{
	/* no-op */
	return;
}

/* os_devopen --- open special per-OS devices */

int
os_devopen(const char *name, int flag)
{
	/* no-op */
	return INVALID_HANDLE;
}

/* optimal_bufsize --- determine optimal buffer size */

/*
 * Enhance this for debugging purposes, as follows:
 *
 * Always stat the file, stat buffer is used by higher-level code.
 *
 * if (AWKBUFSIZE == "exact")
 * 	return the file size
 * else if (AWKBUFSIZE == a number)
 * 	always return that number
 * else
 * 	if the size is < default_blocksize
 * 		return the size
 *	else
 *		return default_blocksize
 *	end if
 * endif
 *
 * Hair comes in an effort to only deal with AWKBUFSIZE
 * once, the first time this routine is called, instead of
 * every time.  Performance, dontyaknow.
 */

size_t
optimal_bufsize(int fd, struct stat *stb)
{
	char *val;
	static size_t env_val = 0;
	static bool first = true;
	static bool exact = false;

	/* force all members to zero in case OS doesn't use all of them. */
	memset(stb, '\0', sizeof(struct stat));

	/* always stat, in case stb is used by higher level code. */
	if (fstat(fd, stb) == -1)
		fatal("can't stat fd %d (%s)", fd, strerror(errno));

	if (first) {
		first = false;

		if ((val = getenv("AWKBUFSIZE")) != NULL) {
			if (strcmp(val, "exact") == 0)
				exact = true;
			else if (isdigit((unsigned char) *val)) {
				for (; *val && isdigit((unsigned char) *val); val++)
					env_val = (env_val * 10) + *val - '0';

				return env_val;
			}
		}
	} else if (! exact && env_val > 0)
		return env_val;
	/* else
	  	fall through */

	/*
	 * System V.n, n < 4, doesn't have the file system block size in the
	 * stat structure. So we have to make some sort of reasonable
	 * guess. We use stdio's BUFSIZ, since that is what it was
	 * meant for in the first place.
	 */
#ifdef HAVE_STRUCT_STAT_ST_BLKSIZE
#define DEFBLKSIZE	(stb->st_blksize > 0 ? stb->st_blksize : BUFSIZ)
#else
#define DEFBLKSIZE	BUFSIZ
#endif

	if (S_ISREG(stb->st_mode)		/* regular file */
	    && 0 < stb->st_size			/* non-zero size */
	    && (stb->st_size < DEFBLKSIZE	/* small file */
		|| exact))			/* or debugging */
		return stb->st_size;		/* use file size */

	return DEFBLKSIZE;
}

/* ispath --- return true if path has directory components */

int
ispath(const char *file)
{
	return (strchr(file, '/') != NULL);
}

/* isdirpunct --- return true if char is a directory separator */

int
isdirpunct(int c)
{
	return (c == '/');
}

/* os_close_on_exec --- set close on exec flag, print warning if fails */

void
os_close_on_exec(int fd, const char *name, const char *what, const char *dir)
{
	int curflags = 0;

	if (fd <= 2)	/* sanity */
		return;

	/*
	 * Per POSIX, use Read/Modify/Write - get the flags,
	 * add FD_CLOEXEC, set the flags back.
	 */

	if ((curflags = fcntl(fd, F_GETFD)) < 0) {
		warning(_("%s %s `%s': could not get fd flags: (fcntl F_GETFD: %s)"),
			what, dir, name, strerror(errno));
		return;
	}

#ifndef FD_CLOEXEC
#define FD_CLOEXEC	1
#endif

	curflags |= FD_CLOEXEC;

	if (fcntl(fd, F_SETFD, curflags) < 0)
		warning(_("%s %s `%s': could not set close-on-exec: (fcntl F_SETFD: %s)"),
			what, dir, name, strerror(errno));
}

/* os_isdir --- is this an fd on a directory? */

#if ! defined(S_ISDIR) && defined(S_IFDIR)
#define	S_ISDIR(m) (((m) & S_IFMT) == S_IFDIR)
#endif

int
os_isdir(int fd)
{
	struct stat sbuf;

	return (fstat(fd, &sbuf) == 0 && S_ISDIR(sbuf.st_mode));
}

/* os_isreadable --- fd can be read from */

int
os_isreadable(const awk_input_buf_t *iobuf, bool *isdir)
{
	*isdir = false;

	if (iobuf->fd == INVALID_HANDLE)
		return false;

	switch (iobuf->sbuf.st_mode & S_IFMT) {
	case S_IFREG:
	case S_IFCHR:	/* ttys, /dev/null, .. */
#ifdef S_IFSOCK
	case S_IFSOCK:
#endif
#ifdef S_IFIFO
	case S_IFIFO:
#endif
		return true;
	case S_IFDIR:
		*isdir = true;
		/* fall through */
	default:
		return false;
	}
}

/* os_is_setuid --- true if running setuid root */

int
os_is_setuid()
{
	long uid, euid;

	uid = getuid();
	euid = geteuid();

	return (euid == 0 && euid != uid);
}

/* os_setbinmode --- set binary mode on file */

int
os_setbinmode(int fd, int mode)
{
#ifdef __CYGWIN__
	setmode (fd, mode);
#endif
	return 0;
}

/* os_restore_mode --- restore the original mode of the console device */

void
os_restore_mode(int fd)
{
	/* no-op */
	return;
}

/* os_isatty --- return true if fd is a tty */

int
os_isatty(int fd)
{
	return isatty(fd);
}

/* files_are_same --- return true if files are identical */

int
files_are_same(char *path, SRCFILE *src)
{
	struct stat st;

	return (stat(path, & st) == 0
		&& st.st_dev == src->sbuf.st_dev
		&& st.st_ino == src->sbuf.st_ino);
}

void
init_sockets(void)
{
}

void
os_maybe_set_errno(void)
{
}

/* os_disable_aslr --- disable Address Space Layout Randomization */

void
os_disable_aslr(const char *persist_file, char **argv)
{
#if defined(HAVE_PERSONALITY) && defined(HAVE_ADDR_NO_RANDOMIZE)
	// This code is Linux specific, both the reliance on /proc/self/exe
	// and the personality system call.
	if (persist_file != NULL) {
		const char *cp = getenv("GAWK_PMA_REINCARNATION");

		if (cp == NULL) {
			static const char exe[] = "/proc/self/exe";

			(void) setenv("GAWK_PMA_REINCARNATION", "true", true);
			if (personality(PER_LINUX | ADDR_NO_RANDOMIZE) < 0) {
				fprintf(stderr, _("warning: personality: %s\n"),
							strerror(errno));
				fflush(stderr);
				// do the exec anyway...
			}
			execv(exe, argv);
		} else
			(void) unsetenv("GAWK_PMA_REINCARNATION");
	}
#endif

#if defined(HAVE__NSGETEXECUTABLEPATH) && defined(HAVE_POSIX_SPAWNP)
	// This code is for macos
	if (persist_file != NULL) {
		const char *cp = getenv("GAWK_PMA_REINCARNATION");

		if (cp == NULL) {
			char fullpath[BUFSIZ];
			int n;
			posix_spawnattr_t p_attr;
			int status;
			pid_t pid;
			extern char **environ;
			uint32_t size = BUFSIZ;

			memset(fullpath, 0, BUFSIZ);
			n = _NSGetExecutablePath(fullpath, &size);

			putenv("GAWK_PMA_REINCARNATION=true");

			posix_spawnattr_init(&p_attr);
			posix_spawnattr_setflags(&p_attr, 0x100);
			status = posix_spawnp(&pid, fullpath, NULL, &p_attr, argv, environ);
			if (status == 0) {
				if (waitpid(pid, &status,  WUNTRACED) != -1) {
					if (WIFEXITED(status))
						exit(WEXITSTATUS(status));	// use original exit code
				} else {
					fprintf(stderr, _("waitpid: got exit status %#o\n"), status);
					exit(EXIT_FATAL);
				}
			} else {
				fprintf(stderr, _("fatal: posix_spawnp: %s\n"), strerror(errno));
				exit(EXIT_FATAL);
			}
		} else
			(void) unsetenv("GAWK_PMA_REINCARNATION");
	}
#endif

#if HAVE_SYS_PROCCTL_H && HAVE_SYS_SYSCTL_H && HAVE_PROCCTL && HAVE_SYSCTL && \
	defined(PROC_ASLR_FORCE_DISABLE) && defined(PROC_ASLR_CTL)
	// This code is for FreeBSD.
	if (persist_file != NULL) {
		const char *cp = getenv("GAWK_PMA_REINCARNATION");

		if (cp == NULL) {
			// Retrieve the full path of this file
			int request[4];
			request[0] = CTL_KERN;
			request[1] = KERN_PROC;
			request[2] = KERN_PROC_PATHNAME;
			request[3] = -1; // Special PID -1 for the current process

			char exe[PATH_MAX];
			size_t len = sizeof(exe);
			if (sysctl(request, 4, exe, &len, NULL, 0) == -1) {
				fprintf(stderr, _("warning: sysctl: %s\n"),
							strerror(errno));
				fflush(stderr);
				return;
			}
			
			int action = PROC_ASLR_FORCE_DISABLE;
			// pid of 0 means getpid()
			if (procctl(P_PID, 0, PROC_ASLR_CTL, & action) < 0) {
				fprintf(stderr, _("warning: procctl: %s\n"),
							strerror(errno));
				fflush(stderr);
				// do the exec anyway...
			}
			(void) setenv("GAWK_PMA_REINCARNATION", "true", true);
			execv(exe, argv);
		} else
			(void) unsetenv("GAWK_PMA_REINCARNATION");
	}
#endif
}

// For MSYS, restore behavior of working in text mode.
#ifdef __MSYS__
void
cygwin_premain0(int argc, char **argv, struct per_process *myself)
{
	static struct __cygwin_perfile pf[] = {
		{ "", O_RDONLY | O_TEXT },
		/*{ "", O_WRONLY | O_BINARY },*/
		{ NULL, 0 }
	};
	cygwin_internal(CW_PERFILE, pf);
}

void
cygwin_premain2(int argc, char **argv, struct per_process *myself)
{
	setmode(fileno (stdin), O_TEXT);
}
#endif

#ifdef __CYGWIN__
size_t
wcitomb (char *s, int wc, mbstate_t *ps)
{
	/* If s is NULL, behave as if s pointed to an internal buffer and wc
	   was a null wide character (L'').  wcrtomb will do that for us*/
	if (wc <= 0xffff || !s)
		return wcrtomb (s, (wchar_t) wc, ps);

	wchar_t wc_arr[2];
	const wchar_t *wcp = wc_arr;

	wc -= 0x10000;
	wc_arr[0] = (wc >> 10) + 0xd800;
	wc_arr[1] = (wc & 0x3ff) + 0xdc00;
	return wcsnrtombs (s, &wcp, 2, SIZE_MAX, ps);
}
#endif
