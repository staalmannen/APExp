#include <stdio.h>
#include <signal.h>
#include <limits.h>
#include <libv.h>
#include "lib.h"

char *
getpass(char *prompt)
{
	int c;
	char *p;
	FILE *fi;
	static char pbuf[PASS_MAX];
	void (*sig)(int);
	int wasraw;

	if ((fi = fopen("/dev/cons", "r")) == NULL)
		fi = stdin;
	else
		setbuf(fi, NULL);
	sig = signal(SIGINT, SIG_IGN);
	/*
	 * Save and restore rather than "off then on": the console may
	 * already be raw because the caller's own line editor put it
	 * there, and unconditionally cooking it on the way out would
	 * leave that caller reading whole lines from then on.  _tty_raw
	 * returns the previous state for exactly this.
	 */
	wasraw = _tty_raw(1);
	fprintf(stderr, "%s", prompt);
	fflush(stderr);

	for (p = pbuf; (c = getc(fi)) != '\n' && c != EOF; )
		if (c == ('u' & 037))
			p = pbuf;
		else if (c == '\b') {
			if (p > pbuf)
				p--;
		} else if (p < &pbuf[sizeof(pbuf)-1])
			*p++ = c;
	*p = '\0';

	fprintf(stderr, "\n");
	fflush(stderr);
	if(wasraw >= 0)
		_tty_raw(wasraw);
	signal(SIGINT, sig);
	if (fi != stdin)
		fclose(fi);
	return(pbuf);
}
