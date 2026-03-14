#include <signal.h>
#include <string.h>
#include "locale_impl.h"

/*
 * APE signal numbers differ substantially from Linux/musl.
 * APE signal.h defines (from signal.h):
 *
 *   SIGHUP   1    SIGINT   2    SIGQUIT  3    SIGILL   4
 *   SIGABRT  5    SIGFPE   6    SIGKILL  7    SIGSEGV  8
 *   SIGPIPE  9    SIGALRM  10   SIGTERM  11   SIGUSR1  12
 *   SIGUSR2  13   SIGBUS   14   SIGCHLD  15   SIGCONT  16
 *   SIGSTOP  17   SIGTSTP  18   SIGTTIN  19   SIGTTOU  20
 *   SIGWINCH 21   SIGVTALRM 22  SIGPROF  23
 *   NSIG     24
 *
 * Signals present in musl but absent in APE (no Plan9 equivalent):
 *   SIGTRAP, SIGURG, SIGXCPU, SIGXFSZ, SIGPWR, SIGSYS,
 *   SIGPOLL/SIGIO, SIGSTKFLT/SIGEMT, all realtime signals.
 *
 * The strings table is indexed 0..NSIG-1 where index 0 is "Unknown signal".
 * Entry N corresponds to signal number N.
 */

/* No sigmap needed: we use APE signal numbers directly as indices.
 * The table below is laid out to match APE's numbering exactly. */

static const char strings[] =
	"Unknown signal\0"      /*  0 - fallback */
	"Hangup\0"              /*  1 - SIGHUP   */
	"Interrupt\0"           /*  2 - SIGINT   */
	"Quit\0"                /*  3 - SIGQUIT  */
	"Illegal instruction\0" /*  4 - SIGILL   */
	"Aborted\0"             /*  5 - SIGABRT  */
	"Arithmetic exception\0"/*  6 - SIGFPE   */
	"Killed\0"              /*  7 - SIGKILL  */
	"Segmentation fault\0"  /*  8 - SIGSEGV  */
	"Broken pipe\0"         /*  9 - SIGPIPE  */
	"Alarm clock\0"         /* 10 - SIGALRM  */
	"Terminated\0"          /* 11 - SIGTERM  */
	"User defined signal 1\0"/* 12 - SIGUSR1 */
	"User defined signal 2\0"/* 13 - SIGUSR2 */
	"Bus error\0"           /* 14 - SIGBUS   */
	"Child process status\0"/* 15 - SIGCHLD  */
	"Continued\0"           /* 16 - SIGCONT  */
	"Stopped (signal)\0"    /* 17 - SIGSTOP  */
	"Stopped\0"             /* 18 - SIGTSTP  */
	"Stopped (tty input)\0" /* 19 - SIGTTIN  */
	"Stopped (tty output)\0"/* 20 - SIGTTOU  */
	"Window changed\0"      /* 21 - SIGWINCH */
	"Virtual timer expired\0"/* 22 - SIGVTALRM */
	"Profiling timer expired\0" /* 23 - SIGPROF */
	"";

char *strsignal(int signum)
{
	const char *s = strings;

	if (signum < 0 || signum >= NSIG)
		signum = 0;

	for (; signum--; s++)
		for (; *s; s++);

	return (char *)LCTRANS_CUR(s);
}
