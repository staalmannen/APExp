/*
 * The console's raw/cooked mode, and the one place that owns it.
 *
 * Plan 9 puts line editing and echo in the console driver, and
 * /dev/consctl is how a program turns them off: write "rawon" to stop
 * the driver cooking, "rawoff" to start again.  There is no per-flag
 * control -- it is one switch for echo AND line assembly together --
 * and the file is namespace-wide, so this is a property of /dev/cons
 * rather than of any particular descriptor.
 *
 * IT ALSO HAS TO BE HELD OPEN.  The console reverts to cooked mode
 * when the last descriptor on consctl closes, which is why ctlfd is a
 * static and not a local.
 *
 * WHY THIS FILE GREW A SECOND CALLER.  It used to serve getpass()
 * alone, through tty_echooff/tty_echoon.  termios now needs the same
 * switch -- tcsetattr had been answering "done" without doing anything
 * -- and two files each keeping their own consctl descriptor would
 * have fought: whichever closed last would drop the console back to
 * cooked under the other one.  So the state lives here once and both
 * go through it.  (The library already did this thing; copy the whole
 * idiom, not the call.)
 *
 * _tty_raw() IS ABSOLUTE AND RETURNS THE PREVIOUS STATE, which is what
 * makes save/restore possible for a caller like getpass that wants to
 * borrow the console and hand it back.  The old tty_echoon() turned
 * raw off unconditionally; with readline in the picture that would
 * have quietly cooked the console out from under it the first time a
 * program asked for a password.
 */

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <libv.h>
#include "lib.h"

static int ctlfd = -1;		/* held open while raw; -1 when cooked */
static int israw = 0;

/*
 * Which libap is linked in.  `pcc -o x x.c' links against the
 * INSTALLED library, so a test from a fresh pull can measure
 * days-old library code and say nothing about the change in hand.
 * rawmode-test declares this extern for itself, so an old libap fails
 * to LINK rather than passing quietly.  Same idiom as
 * _sock_listenmark() and _execmark(); bump it when this file changes
 * in a way a test must be able to see.
 *
 *	1  _tty_raw/_tty_israw, and termios driving them
 */
int
_ttymark(void)
{
	return 1;
}

/*
 * WHAT THIS DOES AND DOES NOT KNOW. It reports what THIS process has
 * set, not what the console is actually doing. /dev/consctl is
 * write-only -- Plan 9 offers no way to ask -- so a console left raw
 * by some other process reads as cooked here, and after an exec the
 * new program starts out believing the console is cooked whatever it
 * was.
 *
 * In practice that is the behaviour wanted rather than a gap to
 * paper over: a shell restores cooked mode before running a child, so
 * the child's belief is correct. Saying it plainly because the
 * alternative -- pretending to report the console -- is the failure
 * this whole file exists to undo.
 */
int
_tty_israw(void)
{
	return israw;
}

/*
 * Set the console to raw (on != 0) or cooked.  Returns the PREVIOUS
 * state, 0 or 1, or -1 if the mode could not be changed.
 *
 * Asking for the state it is already in is not a failure and does not
 * touch consctl: there is genuinely nothing to do.  That distinction
 * matters to the caller -- "I could not do it" and "it needed no
 * doing" are different answers, and tcsetattr reports them
 * differently.
 */
int
_tty_raw(int on)
{
	int was;

	was = israw;
	on = on != 0;
	if(on == israw)
		return was;

	if(on){
		if(ctlfd < 0){
			/*
			 * O_CLOEXEC matters here. Without it the descriptor
			 * survives exec, so a child started by a shell whose
			 * line editor had put the console in raw mode would
			 * inherit a raw console AND a consctl it knows
			 * nothing about. With it the child's copy closes at
			 * exec; the parent still holds its own, so the
			 * console stays raw for the shell, which is what
			 * both want.
			 */
			ctlfd = open("/dev/consctl", O_WRONLY|O_CLOEXEC);
			if(ctlfd < 0)
				return -1;
		}
		if(write(ctlfd, "rawon", 5) != 5){
			close(ctlfd);
			ctlfd = -1;
			return -1;
		}
		israw = 1;
		return was;
	}

	if(ctlfd >= 0){
		write(ctlfd, "rawoff", 6);
		/*
		 * Closing is what actually guarantees cooked mode -- the
		 * driver reverts when the last consctl descriptor goes --
		 * so the write is belt and braces and the close is the
		 * part that matters.
		 */
		close(ctlfd);
		ctlfd = -1;
	}
	israw = 0;
	return was;
}

/*
 * The old two-call interface, kept for getpass() and anything else
 * that includes <libv.h>.  tty_echooff returns 0 on success as before;
 * it used to return -1 when the console was ALREADY raw, which read as
 * a failure when nothing had gone wrong.
 *
 * The fd argument is ignored, as it always was: consctl is
 * namespace-wide.
 */
int
tty_echooff(int fd)
{
	(void)fd;
	return _tty_raw(1) < 0 ? -1 : 0;
}

int
tty_echoon(int fd)
{
	(void)fd;
	return _tty_raw(0) < 0 ? -1 : 0;
}
