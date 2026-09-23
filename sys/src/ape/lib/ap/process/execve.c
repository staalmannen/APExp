#include "lib.h"
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include "sys9.h"

extern char **environ;

/*
 * Which libap is actually linked in.
 *
 * `pcc -o x x.c' links against the INSTALLED library, so a test built
 * from a fresh pull can be running days-old library code and say
 * nothing about it -- a measurement of a build that does not contain
 * the change measures nothing. execfail-test declares this extern for
 * itself, so an old libap fails to LINK rather than passing quietly.
 * The same idiom as _sock_listenmark(); bump it whenever this file
 * changes in a way a test has to be able to see.
 *
 *	1  the preflight open, and the FD_CLOEXEC closes moved last
 */
int
_execmark(void)
{
	return 1;
}

int
execve(const char *name, const char *argv[], const char *envp[])
{
	int n, f, i;
	char **e, *ss, *se;
	Fdinfo *fi;
	unsigned long flags;
	char buf[1024];

	/*
	 * PREFLIGHT, BEFORE ANYTHING IS DESTROYED.
	 *
	 * POSIX: "If the exec function returns to the calling process
	 * image, an error has occurred; ... the process image is
	 * unchanged."  Everything below this point changes it -- the
	 * environment group is cleared, /env/_fdinfo and /env/_sighdlr are
	 * rewritten, and every FD_CLOEXEC descriptor is closed -- and none
	 * of it can be undone once _EXEC has declined to happen.
	 *
	 * Tcl's exec-10.20.1 is what this costs in practice.  Its child
	 * forks, execs a program that does not exist, and reports the
	 * failure down an error pipe that the parent reads; the pipe is
	 * close-on-exec, which is precisely how the parent tells success
	 * from failure.  By the time execvp returned, that pipe had been
	 * closed underneath it, so the write got EBADF and Tcl panicked
	 * with "unable to write to errPipeOut" instead of saying which
	 * program was missing.
	 *
	 * Plan 9's exec opens the file with OEXEC itself (namec(..., Aopen,
	 * OEXEC, 0)), so opening it that way here asks the same question of
	 * the same namespace and answers it without touching anything: a
	 * missing file, a directory, a file without execute permission and
	 * an unreachable path all fail here, with the errno the caller
	 * wanted, and the process carries on exactly as it was.
	 *
	 * This is not a guarantee, and saying so rather than implying it:
	 * an exec can still fail after a successful open -- a bad binary
	 * format, or the file changing underneath -- and that case is as
	 * destructive as the whole function used to be.  What it does is
	 * make the overwhelmingly common failure, "no such file", free.
	 *
	 * _execpath does the same thing with access(X_OK) for each PATH
	 * candidate, but only when it searches: a name containing '/' is
	 * used as given, with no search and no check, and
	 * `~non_existent_user/foo/bar' is such a name.  Checking here
	 * covers both routes and every direct caller of execve besides.
	 */
	n = _OPEN(name, OEXEC);
	if(n < 0){
		_syserrno();
		return -1;
	}
	_CLOSE(n);

	/*
	 * RFCENVG IS ALREADY THE CLEAR. The `C' in RFCENVG, RFCNAMEG and
	 * RFCFDG means a new EMPTY group, not a copy -- RFENVG is the one
	 * that copies. So by the line below this process has no
	 * environment at all, and the creates further down are the whole
	 * of the child's environment: exactly envp, which is what POSIX
	 * says execve delivers.
	 *
	 * SAYING SO BECAUSE THIS WAS READ BACKWARDS ONCE. A loop removing
	 * every /env entry was added here, on the reasoning that RFCENVG
	 * copied the parent's group and so leaked any name envp did not
	 * mention. sys/lib/tests/execve-env-test.c asked the machine
	 * instead -- rfork(RFCENVG), create two names, list /env -- and
	 * got two names back, none of them the parent's. The loop was
	 * removing an empty directory on every exec. It is gone.
	 */
	_RFORK(RFCENVG);

	/*
	 * To pass _fdinfo[] across exec, put lines like
	 *   fd flags oflags
	 * in $_fdinfo (for open fd's)
	 */

	f = _CREATE("/env/_fdinfo", OWRITE|OCEXEC, 0666);
	ss = buf;
	for(i = 0; i<OPEN_MAX; i++){
		if(i == f)
			continue;
		fi = &_fdinfo[i];
		flags = fi->flags;
		/*
		 * FD_CLOEXEC descriptors are LEFT ALONE HERE and closed in
		 * the loop at the end, immediately before _EXEC.  They used
		 * to be closed on this pass, which is the earliest possible
		 * moment and the one with the most left to go wrong after
		 * it; the closing has to happen before the exec and cannot
		 * be undone, so the only thing available is to do it as late
		 * as possible.  They are simply omitted from /env/_fdinfo,
		 * which is what makes them close-on-exec for the child.
		 */
		if(flags&FD_CLOEXEC){
			continue;
		}else if(flags&FD_ISOPEN){
			if(f < 0)
				continue;
			ss = _ultoa(ss, i);
			*ss++ = ' ';
			ss = _ultoa(ss, flags);
			*ss++ = ' ';
			ss = _ultoa(ss, fi->oflags);
			*ss++ = '\n';
			n = ss-buf;
			if(n > sizeof(buf)-50){
				if(_WRITE(f, buf, n) != n)
					break;
				ss = buf;
			}
		}
	}
	if(f >= 0){
		if(ss > buf)
			_WRITE(f, buf, ss-buf);
		_CLOSE(f);
	}

	/*
	 * To pass _sighdlr[] across exec, set $_sighdlr
	 * to list of blank separated fd's that have
	 * SIG_IGN (the rest will be SIG_DFL).
	 * We write the variable, even if no signals
	 * are ignored, in case the current value of the
	 * variable ignored some.
	 */
	f = _CREATE("/env/_sighdlr", OWRITE|OCEXEC, 0666);
	if(f >= 0){
		ss = buf;
		for(i = 0; i <=MAXSIG; i++) {
			if(_sighdlr[i] == SIG_IGN) {
				ss = _ultoa(ss, i);
				*ss++ = ' ';
				n = ss-buf;
				if(n > sizeof(buf)-20){
					if(_WRITE(f, buf, n) != n)
						break;
					ss = buf;
				}
			}
		}
		if(ss > buf)
			_WRITE(f, buf, ss-buf);
		_CLOSE(f);
	}
	if(envp){
		for(e = (char**)envp; (ss = *e); e++) {
			if(strncmp(ss, "#()fn ", 6)==0){
				if((se = strchr(ss+6, '{'))==0)
					continue;
				while(se[-1]==' ') se--;
				n = se-(ss+6);
				if(n <= 0 || n >= sizeof(buf)-8)
					continue;	/* name too long */
				memcpy(buf, "/env/fn#", 8);
				memcpy(buf+8, ss+6, n);
				buf[8+n] = '\0';
				f = _CREATE(buf, OWRITE|OCEXEC, 0666);
				if(f < 0)
					continue;
				ss += 3;	/* past #() */
				_WRITE(f, ss, strlen(ss));
				_CLOSE(f);
			} else {
				if((se = strchr(ss, '='))==0)
					continue;
				n = se-ss;
				if(n <= 0 || n >= sizeof(buf)-5)
					continue;	/* name too long */
				memcpy(buf, "/env/", 5);
				memcpy(buf+5, ss, n);
				buf[5+n] = '\0';
				f = _CREATE(buf, OWRITE|OCEXEC, 0666);
				if(f < 0)
					continue;
				ss = ++se;	/* past = */
				se += strlen(se);
				while((n = (se - ss)) > 0){
					if(n > sizeof(buf))
						n = sizeof(buf);
					/* decode nulls (see _envsetup()) */
					for(i=0; i<n; i++)
						if((buf[i] = ss[i]) == 1)
							buf[i] = 0;
					if(_WRITE(f, buf, n) != n)
						break;
					ss += n;
				}
				_CLOSE(f);
			}
		}
	}
	/*
	 * LAST, and as close to _EXEC as it can be got.  Plan 9 has no
	 * close-on-exec for a descriptor that was not opened with OCEXEC,
	 * and fcntl(F_SETFD) cannot add it after the fact, so FD_CLOEXEC
	 * is implemented by closing them by hand.  Nothing between here
	 * and _EXEC can fail, so a caller that gets control back has lost
	 * its close-on-exec descriptors only in the case where _EXEC
	 * itself refused a file this function has already opened.
	 */
	for(i = 0; i < OPEN_MAX; i++){
		fi = &_fdinfo[i];
		if(fi->flags&FD_CLOEXEC){
			_CLOSE(i);
			fi->flags = 0;
			fi->oflags = 0;
		}
	}

	n = _EXEC(name, argv);
	_syserrno();
	return n;
}
