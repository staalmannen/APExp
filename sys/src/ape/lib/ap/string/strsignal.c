#include <signal.h>
#include <string.h>
#include <stdio.h>

/* strsignal - return description string for signal number */
char *strsignal(int signum)
{
	static const char strings[] =
		"Unknown signal\0"              /*  0 - fallback */
		"Hangup\0"                      /*  1 - SIGHUP   */
		"Interrupt\0"                   /*  2 - SIGINT   */
		"Quit\0"                        /*  3 - SIGQUIT  */
		"Illegal instruction\0"         /*  4 - SIGILL   */
		"Aborted\0"                     /*  5 - SIGABRT  */
		"Arithmetic exception\0"        /*  6 - SIGFPE   */
		"Killed\0"                      /*  7 - SIGKILL  */
		"Segmentation fault\0"          /*  8 - SIGSEGV  */
		"Broken pipe\0"                 /*  9 - SIGPIPE  */
		"Alarm clock\0"                 /* 10 - SIGALRM  */
		"Terminated\0"                  /* 11 - SIGTERM  */
		"User defined signal 1\0"       /* 12 - SIGUSR1  */
		"User defined signal 2\0"       /* 13 - SIGUSR2  */
		"Bus error\0"                   /* 14 - SIGBUS   */
		"Child process status\0"        /* 15 - SIGCHLD  */
		"Continued\0"                   /* 16 - SIGCONT  */
		"Stopped (signal)\0"            /* 17 - SIGSTOP  */
		"Stopped\0"                     /* 18 - SIGTSTP  */
		"Stopped (tty input)\0"         /* 19 - SIGTTIN  */
		"Stopped (tty output)\0"        /* 20 - SIGTTOU  */
		"Window changed\0"              /* 21 - SIGWINCH */
		"Virtual timer expired\0"       /* 22 - SIGVTALRM */
		"Profiling timer expired\0"     /* 23 - SIGPROF */
		"";

	static char buf[32];
	const char *s = strings;
	int i;

	if (signum < 0 || signum >= NSIG)
		signum = 0;

	/* Find the right string in the table */
	for (i = 0; i < signum; i++) {
		while (*s) s++;
		s++;
	}

	return (char *)s;
}


