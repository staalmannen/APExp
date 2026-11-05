// +build !plan9
// +build !windows

/*
Plan 9 from User Space src/lib9/await.c
http://code.swtch.com/plan9port/src/tip/src/lib9/await.c

Copyright 2001-2007 Russ Cox.  All Rights Reserved.
Portions Copyright 2009 The Go Authors.  All Rights Reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#define NOPLAN9DEFINES
#include <u.h>
#include <libc.h>

#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>

#ifndef WCOREDUMP	/* not on Mac OS X Tiger */
#define WCOREDUMP(status) 0
#endif

static struct {
	int sig;
	char *str;
} tab[] = {
	SIGHUP,		"hangup",
	SIGINT,		"interrupt",
	SIGQUIT,		"quit",
	SIGILL,		"sys: illegal instruction",
	SIGTRAP,		"sys: breakpoint",
	SIGABRT,		"sys: abort",
#ifdef SIGEMT
	SIGEMT,		"sys: emulate instruction executed",
#endif
	SIGFPE,		"sys: fp: trap",
	SIGKILL,		"sys: kill",
	SIGBUS,		"sys: bus error",
	SIGSEGV,		"sys: segmentation violation",
	SIGALRM,		"alarm",
	SIGTERM,		"kill",
	SIGURG,		"sys: urgent condition on socket",
	SIGSTOP,		"sys: stop",
	SIGTSTP,		"sys: tstp",
	SIGCONT,		"sys: cont",
	SIGCHLD,		"sys: child",
	SIGTTIN,		"sys: ttin",
	SIGTTOU,		"sys: ttou",
#ifdef SIGIO	/* not on Mac OS X Tiger */
	SIGIO,		"sys: i/o possible on fd",
#endif
	SIGXCPU,		"sys: cpu time limit exceeded",
	SIGXFSZ,		"sys: file size limit exceeded",
	SIGVTALRM,	"sys: virtual time alarm",
	SIGPROF,		"sys: profiling timer alarm",
#ifdef SIGWINCH	/* not on Mac OS X Tiger */
	SIGWINCH,	"sys: window size change",
#endif
#ifdef SIGINFO
	SIGINFO,		"sys: status request",
#endif
	SIGUSR1,		"sys: usr1",
	SIGUSR2,		"sys: usr2",
	SIGPIPE,		"sys: write on closed pipe",
};

char*
_p9sigstr(int sig, char *tmp)
{
	int i;

	for(i=0; i<nelem(tab); i++)
		if(tab[i].sig == sig)
			return tab[i].str;
	if(tmp == nil)
		return nil;
	sprint(tmp, "sys: signal %d", sig);
	return tmp;
}

int
_p9strsig(char *s)
{
	int i;

	for(i=0; i<nelem(tab); i++)
		if(strcmp(s, tab[i].str) == 0)
			return tab[i].sig;
	return 0;
}

static Waitmsg*
_wait(int pid4, int opt)
{
	int pid, status, cd;
	struct rusage ru;
	char tmp[64];
	ulong u, s;
	Waitmsg *w;

	w = malloc(sizeof *w + 200);
	if(w == nil)
		return nil;
	/*
	 * APExp: the message buffer is part of this allocation and was
	 * NOT cleared -- `memset(w, 0, sizeof *w)' stops at the struct.
	 * A child that exits 0 has nothing written to `w->msg', so
	 * `msg[0]' was whatever malloc last left there, and a caller
	 * that reads it as "did the child fail?" fails at random.
	 *
	 * `cc/lex.c:349' is such a caller --
	 *	if(nerrors == 0 && mywait(&status) > 0 && status != 0)
	 *		nerrors++;
	 * with `compat-unix.c's mywait setting status from `msg[0]' --
	 * so a host-built kencc removed its own output file and exited
	 * 1 with NO DIAGNOSTIC, for some inputs and not others.  It
	 * took php's `KeccakP-1600-opt64.c' and a full strace to see
	 * that the child had exited 0 and been waited for correctly.
	 * This file is `+build !plan9', so nothing on the VM reads it.
	 */
	memset(w, 0, sizeof *w + 200);
	w->msg = (char*)&w[1];

	for(;;){
		/* On Linux, pid==-1 means anyone; on SunOS, it's pid==0. */
		if(pid4 == -1)
			pid = wait3(&status, opt, &ru);
		else
			pid = wait4(pid4, &status, opt, &ru);
		if(pid <= 0) {
			free(w);
			return nil;
		}
		u = (ulong)(ru.ru_utime.tv_sec*1000+((ru.ru_utime.tv_usec+500)/1000));
		s = (ulong)(ru.ru_stime.tv_sec*1000+((ru.ru_stime.tv_usec+500)/1000));
		w->pid = pid;
		w->time[0] = u;
		w->time[1] = s;
		w->time[2] = u+s;
		if(WIFEXITED(status)){
			if(status)
				sprint(w->msg, "%d", status);
			return w;
		}
		if(WIFSIGNALED(status)){
			cd = WCOREDUMP(status);
			sprint(w->msg, "signal: %s", _p9sigstr(WTERMSIG(status), tmp));
			if(cd)
				strcat(w->msg, " (core dumped)");
			return w;
		}
	}
}

Waitmsg*
p9wait(void)
{
	return _wait(-1, 0);
}

Waitmsg*
p9waitfor(int pid)
{
	return _wait(pid, 0);
}

Waitmsg*
p9waitnohang(void)
{
	return _wait(-1, WNOHANG);
}

int
p9waitpid(void)
{
	int status;
	return wait(&status);
}
