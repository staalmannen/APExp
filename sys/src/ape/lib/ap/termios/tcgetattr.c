#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "sys9.h"
#include "lib.h"
#include "dir.h"

#define	CESC	'\\'
#define	CINTR	0177	/* DEL */
#define	CQUIT	034	/* FS, cntl | */
#define	CERASE	010	/* BS */
#define	CKILL	025 /* cntl u */
#define	CEOF	04	/* cntl d */
#define	CSTART	021	/* cntl q */
#define	CSTOP	023	/* cntl s */
#define	CSWTCH	032	/* cntl z */
#define CEOL	000
#define	CNSWTCH	0

static int
isptty(int fd)
{
	Dir *d;
	int rv;

	if((d = _dirfstat(fd)) == nil)
		return 0;
	rv = (strncmp(d->name, "ptty", 4) == 0);
	free(d);
	return rv;
}

int
tcgetattr(int fd, struct termios *t)
{
	int n;
	char buf[60];

	if(!isptty(fd)) {
		if(isatty(fd)) {
			/*
			 * Most of this is a polite fiction -- Plan 9's
			 * console driver has no baud rate and no per-flag
			 * control -- but ICANON and ECHO are NOT, and they
			 * used to be. They were hardcoded on, so a program
			 * that set raw mode and read the state back was told
			 * its own change had not happened. A platform having
			 * only one switch is no reason for a value not to
			 * read back; _tty_israw() is that switch.
			 */
			t->c_iflag = ISTRIP|ICRNL|IXON|IXOFF;
			t->c_oflag = OPOST|TAB3|ONLCR;
			t->c_cflag = CS8 | CREAD | CLOCAL | (B9600 << 9);
			if(_tty_israw())
				t->c_lflag = ISIG;
			else
				t->c_lflag = ISIG|ICANON|ECHO|ECHOE|ECHOK;
			t->c_cc[VINTR] = CINTR;
			t->c_cc[VQUIT] = CQUIT;
			t->c_cc[VERASE] = CERASE;
			t->c_cc[VKILL] = CKILL;
			t->c_cc[VEOF] = CEOF;
			t->c_cc[VEOL] = CEOL;
			t->c_cc[VSTART] = CSTART;
			t->c_cc[VSTOP] = CSTOP;
			return 0;
		} else {
			errno = ENOTTY;
			return -1;
		}
	}
	if(_SEEK(fd, -2, 0) != -2) {
		_syserrno();
		return -1;
	}

	n = _READ(fd, buf, 57);
	if(n < 0) {
		_syserrno();
		return -1;
	}

	t->c_iflag = strtoul(buf+4, 0, 16);
	t->c_oflag = strtoul(buf+9, 0, 16);
	t->c_cflag = strtoul(buf+14, 0, 16);
	t->c_lflag = strtoul(buf+19, 0, 16);

	for(n = 0; n < NCCS; n++)
		t->c_cc[n] = strtoul(buf+24+(n*3), 0, 16);

	return 0;
}

/*
 * BUG: ignores optional_actions. TCSANOW, TCSADRAIN and TCSAFLUSH are
 * all treated as TCSANOW, which is harmless here because Plan 9's
 * console has no output queue to drain and no input queue to flush --
 * see tcdrain() and tcflush() below, which say the same thing.
 */

int
tcsetattr(int fd, int optional_actions, const struct termios *t)
{
	int n, i, want, was;
	char buf[100];

	(void)optional_actions;	/* see the BUG note above */

	if(!isptty(fd)) {
		if(!isatty(fd)) {
			errno = ENOTTY;
			return -1;
		}
		/*
		 * THIS USED TO `return 0' AND DO NOTHING, which is the
		 * worst answer available: the caller is told its request
		 * succeeded and the console carries on cooking. readline
		 * asks for ICANON and ECHO off, is told it got them, and
		 * then waits for keystrokes that the driver is holding
		 * back until Enter -- which is why tab completion has
		 * never worked under APE.
		 *
		 * Plan 9 gives one switch, not a flag set: /dev/consctl's
		 * "rawon" stops echo AND line assembly together. So the
		 * request is reduced to that one bit -- raw if EITHER
		 * ICANON or ECHO is being cleared. When only ECHO is
		 * wanted off (a password prompt asking for cooked input
		 * with no echo) raw is the closer of the two answers, as
		 * echoing a password is the worse failure.
		 *
		 * VMIN and VTIME have no equivalent and are ignored;
		 * raw mode delivers each byte as it arrives, which is
		 * VMIN=1 VTIME=0 and nothing else.
		 */
		want = !(t->c_lflag & ICANON) || !(t->c_lflag & ECHO);
		was = _tty_raw(want);
		if(was < 0) {
			/*
			 * Could not reach /dev/consctl. Report it rather
			 * than claiming success -- but note that _tty_raw
			 * does not touch consctl at all when the console is
			 * already in the requested state, so "nothing to do"
			 * still returns 0 here. A stub that answers
			 * "failure" and one that answers "nothing to do" are
			 * different, and so are the cases.
			 */
			_syserrno();
			return -1;
		}
		return 0;
	}
	n = sprintf(buf, "IOW %4.4x %4.4x %4.4x %4.4x ",
		t->c_iflag, t->c_oflag, t->c_cflag, t->c_lflag);

	for(i = 0; i < NCCS; i++)
		n += sprintf(buf+n, "%2.2x ", t->c_cc[i]);

	if(_SEEK(fd, -2, 0) != -2) {
		_syserrno();
		return -1;
	}

	n = _WRITE(fd, buf, n);
	if(n < 0) {
		_syserrno();
		return -1;
	}

	return 0;
}

int
tcsetpgrp(int fd, pid_t pgrpid)
{
	int n;
	char buf[30];

	if(!isptty(fd)) {
		if(!isatty(fd)) {
			errno = ENOTTY;
			return -1;
		} else
			return 0;
	}
	n = sprintf(buf, "IOW note %d", pgrpid);

	if(_SEEK(fd, -2, 0) != -2) {
		_syserrno();
		return -1;
	}

	n = _WRITE(fd, buf, n);
	if(n < 0) {
		_syserrno();
		return -1;
	}
	return 0;
}

pid_t
tcgetpgrp(int fd)
{
	int n;
	pid_t pgrp;
	char buf[100];

	if(!isptty(fd)) {
		errno = ENOTTY;
		return -1;
	}
	if(_SEEK(fd, -2, 0) != -2) {
		_syserrno();
		return -1;
	}
	n = _READ(fd, buf, sizeof(buf));
	if(n < 0) {
		_syserrno();
		return -1;
	}
	pgrp = atoi(buf+24+(NCCS*3));
	return pgrp;
}

int
tcdrain(int fd)
{
	if(!isatty(fd)){
		errno = ENOTTY;
		return -1;
	}
	/* Plan9: output is synchronous; nothing to drain */
	return 0;
}

int
tcflush(int fd, int queue_selector)
{
	(void)queue_selector;
	if(!isatty(fd)){
		errno = ENOTTY;
		return -1;
	}
	/* Plan9: no kernel queue to flush */
	return 0;
}

int
tcflow(int fd, int action)
{
	(void)action;
	if(!isatty(fd)){
		errno = ENOTTY;
		return -1;
	}
	/* Plan9: no flow-control registers to poke */
	return 0;
}

int
tcsendbreak(int fd, int duration)
{
	(void)duration;
	if(!isatty(fd)){
		errno = ENOTTY;
		return -1;
	}
	/* Plan9: no break signal on serial lines */
	return 0;
}

pid_t
tcgetsid(int fd)
{
	if(!isatty(fd)){
		errno = ENOTTY;
		return -1;
	}
	/* Plan9 has no session concept; return process group as session id */
	return getpid();
}
