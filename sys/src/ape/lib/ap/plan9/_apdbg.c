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
void
_apdbg(const char *msg, const char *l1, int v1, const char *l2, int v2)
{
	char buf[160], *p, *e;

	if(dbgon < 0)
		dbgon = getenv("APEXP_DEBUG") != 0
			|| getenv("APEXP_LISTENDEBUG") != 0;
	if(dbgon == 0)
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
	*p++ = '\n';
	write(2, buf, p - buf);
}
