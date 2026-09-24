/*
 * _apdbg.c -- one line of debug output, on demand, from inside libap.
 *
 * WHERE THIS CAME FROM. `$APEXP_LISTENDEBUG' was added to
 * network/_sock_listenpid.c after two rounds went on mechanisms argued
 * from the source, both wrong. It settled its question in one run, and
 * then a second question turned up two hundred lines away in
 * plan9/_buf.c, where the same instrument was wanted and was not there.
 * So it lives here, where anything in libap can reach it.
 *
 * WHY NOT stdio. This is called from `close()' and from `select()',
 * which every program links; printf would drag the whole of stdio in
 * behind them. write(2) and a hand-rolled number instead, and no
 * allocation, so it is also safe where stdio would not be.
 *
 * $APEXP_DEBUG or $APEXP_LISTENDEBUG turns it on. Both, because the
 * second name is the one already written down in the notes and in a
 * shell history, and breaking it mid-investigation would cost a round
 * for nothing.
 */

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#include "lib.h"

static int dbgon = -1;

static char *
putstr(char *p, char *e, const char *s)
{
	while(*s && p < e)
		*p++ = *s++;
	return p;
}

static char *
putnum(char *p, char *e, int v)
{
	char n[16];
	int i;

	i = 0;
	if(v < 0 && p < e){
		*p++ = '-';
		v = -v;
	}
	do {
		n[i++] = '0' + v%10;
		v /= 10;
	} while(v != 0 && i < (int)sizeof n);
	while(i > 0 && p < e)
		*p++ = n[--i];
	return p;
}

/*
 * Each label may be 0, in which case its number is left out. The
 * labels are spelled by the caller so that the OUTPUT says what the
 * numbers are -- a line reading `fd=4 pid=7898' can be read by someone
 * who has never seen this file, and one reading `a=4 b=7898' cannot.
 */
/*
 * Is it on? For callers on a hot path, so that a run with debugging
 * off costs one load and one branch rather than one call per line.
 * read() is the reason: three lines per read is three calls in the
 * inner loop of every program in the tree.
 */
int
_apdbgon(void)
{
	if(dbgon < 0)
		dbgon = getenv("APEXP_DEBUG") != 0
			|| getenv("APEXP_LISTENDEBUG") != 0;
	return dbgon;
}

void
_apdbg(const char *msg, const char *l1, int v1, const char *l2, int v2)
{
	char buf[160], *p, *e;

	if(_apdbgon() == 0)
		return;
	p = buf;
	e = buf + sizeof buf - 2;
	p = putstr(p, e, msg);
	if(l1 != 0){
		p = putstr(p, e, " ");
		p = putstr(p, e, l1);
		p = putstr(p, e, "=");
		p = putnum(p, e, v1);
	}
	if(l2 != 0){
		p = putstr(p, e, " ");
		p = putstr(p, e, l2);
		p = putstr(p, e, "=");
		p = putnum(p, e, v2);
	}
	/*
	 * CR AND THEN LF, and the CR is not decoration.
	 *
	 * This writes to fd 2, and since tcsetattr started working
	 * (plan9/tty.c) fd 2 is often a terminal in RAW mode -- where
	 * `\n' is a pure line feed and the cursor stays in the column it
	 * was in. Every line then starts one further right than the last,
	 * and the output marches diagonally off the screen. Measured
	 * under vts, where the debug lines were unreadable for exactly
	 * this reason and looked like a terminal-emulator bug.
	 *
	 * Harmless everywhere else: a cooked terminal drops the CR, and a
	 * log file gains one byte per line.
	 *
	 * *A debug line that cannot be read is not a debug line*, and the
	 * fix that made raw mode real is what made this reachable -- the
	 * same rule, a third time.
	 */
	*p++ = '\r';
	*p++ = '\n';
	write(2, buf, p - buf);
}
