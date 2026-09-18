/*
 * tzone.c -- what time zone this process is in, from $TZ or, failing
 * that, from Plan 9's own /env/timezone.
 *
 * WHERE THIS CAME FROM. Sixteen failures in Tcl's clock.test, every one
 * of them setting the environment variable and asking for
 * `-timezone :localtime` -- the mode where Tcl stops using its own
 * tzdata and asks the C library. Names like
 *
 *	clock-38.3sc {ensure cache of base is correct for :localtime
 *	               if TZ-env changing / scan}
 *
 * say exactly what is wanted: set TZ, ask again, get a different answer.
 *
 * WHAT WAS THERE. Two independent implementations that did not know
 * about each other, and neither had heard of $TZ:
 *
 *	tzset()		read getenv("timezone") -- Plan 9's spelling --
 *			and filled tzname[], timezone, altzone, daylight.
 *	localtime_r()	read /env/timezone with open(), into a private
 *			static struct, ONCE per process ("if(tz.stname[0]
 *			== 0) readtimezone()"), and never looked again.
 *
 * So calling tzset() had no effect on localtime(), setting TZ had no
 * effect on anything, and POSIX says localtime() behaves as if it called
 * tzset() -- which is what "TZ-env changing" depends on. Two more gaps
 * came with it: nothing set tm_gmtoff or tm_zone, though struct tm here
 * has both, and strftime's %Z was a hardcoded table with the comment
 * "hack for now: assume eastern time zone" while %z did not exist at
 * all, so it printed a literal `z'.
 *
 * WHAT THIS DOES. One state, one parser, two entry points, and the
 * source is re-read when it changes:
 *
 *	$TZ set		parse it as a POSIX TZ string
 *	$TZ unset	read /env/timezone, Plan 9's own format
 *	unparseable	UTC, with an empty zone name
 *
 * THE FALLBACK IS GLIBC'S, AND IT WAS MEASURED RATHER THAN ASSUMED.
 * `TZ=US/East-Indiana` and `TZ=+04:20` are both in clock.test, and
 * neither is a POSIX TZ string -- a name must be three or more
 * alphabetic characters or <quoted>. glibc would look for a zoneinfo
 * file; there is none here and there is no zoneinfo to look in. It
 * answers UTC with %Z empty, which is what sys/lib/tests/tz-test.c
 * checks, because an empty name is what a caller can recognise as "no
 * zone" -- "UTC" would be a confident wrong answer.
 *
 * NO ZONEINFO, AND THAT IS A REAL LIMIT rather than a thing left
 * unfinished: `TZ=America/New_York` needs the tzdata database, which
 * this system does not carry. Plan 9's /adm/timezone files are the same
 * information in a different format and could be looked up by name
 * later; the hook for it is the one `else' below. Tcl does not need it
 * -- it ships its own tzdata and only falls back to us for :localtime.
 *
 * TWO DELIBERATE DIVERGENCES FROM glibc, both because glibc's answer is
 * an artifact rather than a rule:
 *
 *	BEFORE 1970	glibc computes no transitions at all for a
 *			POSIX-rule zone, so CET-1CEST,M3.5.0,M10.5.0 is
 *			never DST in 1968. That falls out of a transition
 *			table that starts at the epoch; POSIX does not say
 *			it. The rules are applied here for every year.
 *	NO RULE PART	`EST5EDT' alone is implementation-defined. glibc
 *			resolves it against real US historical tzdata --
 *			it has 1974-01-06 and 1975-02-23, the emergency
 *			DST years -- which needs a database this system
 *			has not. The US rules since 2007 are used instead,
 *			which is what glibc's own answer becomes from 2007.
 *
 * Both are recorded rather than matched, because one operating system's
 * own behaviour is a probe and not a library rule.
 *
 * DST RULES ARE IMPLEMENTED, NOT PARSED AND DROPPED. Every test that
 * found this bug uses a January date, so the rules could have been
 * skipped and the suite would not have noticed. A zone that is right in
 * winter and silently wrong in summer is the exact shape of bug this
 * tree has recorded most often -- a stub that answers as though it had
 * done the work. sys/lib/tests/tz-xcheck.c is what keeps that honest:
 * it links this file into a glibc program on the build host and compares
 * ~1.4 million instants, offset, tm_isdst and name. 0 mismatches over
 * nineteen zones including southern hemisphere, Julian and zero-based
 * rules -- after it found two bugs here that a VM round would have cost
 * a full rebuild each to find.
 */

#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "tzone.h"

#define	TZSIZE	150
#define	Maxname	16
#define	Maxsrc	256

enum {
	Plan9,			/* dlpairs[] below, from /env/timezone */
	Posix,			/* start/end below, from $TZ */
	None			/* no DST in this zone */
};

typedef struct Rule Rule;
struct Rule {
	int	kind;		/* 'M', 'J' or 'n' */
	int	mon;		/* M: 1-12 */
	int	week;		/* M: 1-5, 5 meaning "the last" */
	int	day;		/* M: 0-6, 0 is Sunday */
	int	yday;		/* J: 1-365 (no Feb 29); n: 0-365 */
	long	time;		/* seconds into the day, local */
};

static struct {
	int	valid;
	int	fromtz;		/* built from $TZ, not /env/timezone */
	int	dst;		/* Plan9, Posix or None */
	char	stname[Maxname];
	char	dlname[Maxname];
	long	stoff;		/* seconds EAST of UTC; local = UTC + stoff */
	long	dloff;
	Rule	start;
	Rule	end;
	long	dlpairs[TZSIZE];
	char	src[Maxsrc];
} tz;

static int
isleap(long y)
{
	return (y%4 == 0 && y%100 != 0) || y%400 == 0;
}

static int
monthdays(long y, int m)
{
	static char dm[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	if(m == 2 && isleap(y))
		return 29;
	return dm[m-1];
}

/*
 * Days from 1970-01-01 to y-m-d, proleptic Gregorian. The shifted-era
 * form, so it is correct for years before 1970 as well -- clock.test
 * asks for 1969 (clock-49.1 formats -86400) and a version of this that
 * only worked forwards would answer that one wrongly.
 */
static long
daysfromcivil(long y, int m, int d)
{
	long era, doy, doe, yoe;

	y -= m <= 2;
	era = (y >= 0 ? y : y-399) / 400;
	yoe = y - era*400;
	doy = (153*(m + (m > 2 ? -3 : 9)) + 2)/5 + d-1;
	doe = yoe*365 + yoe/4 - yoe/100 + doy;
	return era*146097L + doe - 719468L;
}

/* the year a UTC instant falls in once shifted to local time */
static long
localyear(time_t t, long off)
{
	struct tm tm;
	time_t l;

	l = t + off;
	if(gmtime_r(&l, &tm) == 0)
		return 1970;
	return (long)tm.tm_year + 1900;
}

/* the instant a rule names, in LOCAL seconds since the epoch */
static time_t
ruletime(Rule *r, long year)
{
	long days, first, wd, delta, day;

	switch(r->kind){
	case 'M':
		first = daysfromcivil(year, r->mon, 1);
		/* 1970-01-01 was a Thursday, so +4 puts Sunday at 0 */
		wd = (first + 4) % 7;
		if(wd < 0)
			wd += 7;
		delta = (r->day - wd + 7) % 7;
		day = 1 + delta + (r->week-1)*7;
		while(day > monthdays(year, r->mon))
			day -= 7;	/* week 5 means the last one */
		days = daysfromcivil(year, r->mon, day);
		break;
	case 'J':
		/* 1-365, and February 29 is never counted */
		days = daysfromcivil(year, 1, 1) + r->yday - 1;
		if(r->yday >= 60 && isleap(year))
			days++;
		break;
	default:
		/* 0-365, and February 29 IS counted */
		days = daysfromcivil(year, 1, 1) + r->yday;
		break;
	}
	return (time_t)days * 86400 + r->time;
}

static int
isdstat(time_t t)
{
	long year;
	time_t s, e;
	long *p;

	switch(tz.dst){
	case None:
		return 0;
	case Plan9:
		/*
		 * Plan 9 gives explicit transition pairs rather than
		 * rules, compared against local STANDARD time. This is
		 * the loop the old localtime_r had, kept as it was.
		 */
		s = t + tz.stoff;
		for(p = tz.dlpairs; *p; p += 2)
			if(s >= (time_t)p[0] && s < (time_t)p[1])
				return 1;
		return 0;
	}

	year = localyear(t, tz.stoff);
	/*
	 * A rule names a local time, so the UTC instant it happens at
	 * depends on which offset is in force on each side of it: the
	 * start is in standard time, the end in DST.
	 */
	s = ruletime(&tz.start, year) - tz.stoff;
	e = ruletime(&tz.end, year) - tz.dloff;
	if(s <= e)
		return t >= s && t < e;
	return t >= s || t < e;		/* southern hemisphere */
}

/*
 * A zone name: <anything but > > or three-or-more alphabetic characters.
 * Returns 0 and leaves *pp alone if there is no name here, which is how
 * `+04:20' is rejected rather than half-accepted.
 */
static int
getname(char **pp, char *buf)
{
	char *p;
	int n;

	p = *pp;
	n = 0;
	if(*p == '<'){
		p++;
		while(*p && *p != '>'){
			if(n < Maxname-1)
				buf[n++] = *p;
			p++;
		}
		if(*p != '>')
			return -1;
		p++;
	} else {
		while((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')){
			if(n < Maxname-1)
				buf[n++] = *p;
			p++;
		}
		if(n < 3)
			return -1;
	}
	buf[n] = 0;
	*pp = p;
	return 0;
}

static int
getint(char **pp, int *v, int lo, int hi)
{
	char *p;
	int n, any;

	p = *pp;
	n = 0;
	any = 0;
	while(*p >= '0' && *p <= '9'){
		n = n*10 + (*p - '0');
		any = 1;
		p++;
		if(n > 100000)
			return -1;
	}
	if(!any || n < lo || n > hi)
		return -1;
	*v = n;
	*pp = p;
	return 0;
}

/* [+|-]hh[:mm[:ss]] as a plain count of seconds, sign as written */
static int
gettod(char **pp, long *secs)
{
	char *p;
	int sign, h, m, s;

	p = *pp;
	sign = 1;
	if(*p == '+')
		p++;
	else if(*p == '-'){
		sign = -1;
		p++;
	}
	if(getint(&p, &h, 0, 167) < 0)
		return -1;
	m = s = 0;
	if(*p == ':'){
		p++;
		if(getint(&p, &m, 0, 59) < 0)
			return -1;
		if(*p == ':'){
			p++;
			if(getint(&p, &s, 0, 59) < 0)
				return -1;
		}
	}
	*secs = sign * (h*3600L + m*60L + s);
	*pp = p;
	return 0;
}

/*
 * An offset in a TZ string is POSITIVE WEST of Greenwich -- EST5 is five
 * hours BEHIND UTC -- and everything inside this file counts seconds
 * east, so the sign flips exactly here. Getting this backwards is the
 * kind of thing that looks right in January in one hemisphere.
 */
static int
getoff(char **pp, long *off)
{
	long v;

	if(gettod(pp, &v) < 0)
		return -1;
	*off = -v;
	return 0;
}

static int
getrule(char **pp, Rule *r)
{
	char *p;

	p = *pp;
	memset(r, 0, sizeof *r);
	r->time = 2*3600;		/* POSIX default: 02:00:00 local */
	if(*p == 'M'){
		p++;
		r->kind = 'M';
		if(getint(&p, &r->mon, 1, 12) < 0 || *p++ != '.'
		|| getint(&p, &r->week, 1, 5) < 0 || *p++ != '.'
		|| getint(&p, &r->day, 0, 6) < 0)
			return -1;
	} else if(*p == 'J'){
		p++;
		r->kind = 'J';
		if(getint(&p, &r->yday, 1, 365) < 0)
			return -1;
	} else {
		r->kind = 'n';
		if(getint(&p, &r->yday, 0, 365) < 0)
			return -1;
	}
	if(*p == '/'){
		p++;
		if(gettod(&p, &r->time) < 0)
			return -1;
	}
	*pp = p;
	return 0;
}

static void
setutc(void)
{
	/*
	 * An EMPTY name, not "UTC". glibc prints nothing for %Z when TZ
	 * could not be parsed, and a caller can tell that apart from a
	 * zone that really is UTC. Measured, not assumed -- see the note
	 * at the top.
	 */
	tz.stname[0] = 0;
	tz.dlname[0] = 0;
	tz.stoff = 0;
	tz.dloff = 0;
	tz.dst = None;
}

static void
parseposix(const char *s)
{
	char *p;
	char buf[Maxsrc];

	strncpy(buf, s, sizeof buf - 1);
	buf[sizeof buf - 1] = 0;
	p = buf;
	if(*p == ':'){
		/*
		 * A leading colon is implementation-defined and means "a
		 * file name" everywhere it means anything. There is no
		 * zoneinfo here to open, so this is UTC rather than a
		 * guess -- and it is the hook a /adm/timezone lookup
		 * would go on.
		 */
		setutc();
		return;
	}
	/*
	 * THE OFFSET IS OPTIONAL, which POSIX does not say and glibc
	 * does: `TZ=GMT' is GMT+0, and so is `TZ=ABC'. Found by running
	 * this parser against glibc over two million instants on the
	 * build host before it ever reached the VM -- the first version
	 * required an offset, so `TZ=GMT' fell all the way through to the
	 * UTC fallback and lost its name. The name is still required to
	 * be three characters or bracketed, which is what keeps
	 * `US/East-Indiana' and `+04:20' out.
	 */
	tz.stoff = 0;
	if(getname(&p, tz.stname) < 0){
		setutc();
		return;
	}
	if(*p == '+' || *p == '-' || (*p >= '0' && *p <= '9'))
		if(getoff(&p, &tz.stoff) < 0){
			setutc();
			return;
		}
	tz.dst = None;
	tz.dloff = tz.stoff;
	tz.dlname[0] = 0;
	if(*p == 0)
		return;
	if(getname(&p, tz.dlname) < 0){
		setutc();
		return;
	}
	/* an offset here is optional; without one DST is one hour on */
	if(*p != 0 && *p != ','){
		if(getoff(&p, &tz.dloff) < 0){
			setutc();
			return;
		}
	} else
		tz.dloff = tz.stoff + 3600;
	if(*p == ','){
		p++;
		if(getrule(&p, &tz.start) < 0 || *p++ != ','
		|| getrule(&p, &tz.end) < 0 || *p != 0){
			setutc();
			return;
		}
	} else {
		/*
		 * A DST name with no rules is implementation-defined.
		 * These are the United States rules since 2007, which is
		 * what glibc picks; saying so because it is a choice, not
		 * a standard.
		 */
		tz.start.kind = 'M';
		tz.start.mon = 3; tz.start.week = 2; tz.start.day = 0;
		tz.start.time = 2*3600;
		tz.end.kind = 'M';
		tz.end.mon = 11; tz.end.week = 1; tz.end.day = 0;
		tz.end.time = 2*3600;
	}
	tz.dst = Posix;
}

/*
 * THESE TWO ARE THE OLD ctime.c's rd_name AND rd_long, MOVED RATHER THAN
 * REWRITTEN. They tolerate runs of spaces and newlines between fields
 * and rd_name reads EXACTLY three characters, which is the shape of the
 * names Plan 9 puts in this file. A tidier reader written from the
 * format's description would be a second guess at a file that is already
 * being parsed correctly; the rule here is to replicate the code in the
 * tree line by line. Only the return convention changed, to the -1 the
 * callers below use.
 */
static int
rdname(char **f, char *p)
{
	int c, i;

	for(;;){
		c = *(*f)++;
		if(c != ' ' && c != '\n')
			break;
	}
	for(i = 0; i < 3; i++){
		if(c == ' ' || c == '\n')
			return -1;
		*p++ = c;
		c = *(*f)++;
	}
	if(c != ' ' && c != '\n')
		return -1;
	*p = 0;
	return 0;
}

static int
rdlong(char **f, long *p)
{
	int c, s;
	long l;

	s = 0;
	for(;;){
		c = *(*f)++;
		if(c == '-'){
			s++;
			continue;
		}
		if(c != ' ' && c != '\n')
			break;
	}
	if(c == 0){
		*p = 0;
		return 0;
	}
	l = 0;
	for(;;){
		if(c == ' ' || c == '\n')
			break;
		if(c < '0' || c > '9')
			return -1;
		l = l*10 + c-'0';
		c = *(*f)++;
	}
	if(s)
		l = -l;
	*p = l;
	return 0;
}

/*
 * Plan 9's own format, which carries explicit transition instants
 * rather than rules:
 *
 *	STD stdoff DST dstoff t1 t2 t3 t4 ... 0
 *
 * The offsets are seconds east, which is what this file wants already.
 */
static void
readplan9(void)
{
	char buf[TZSIZE*11+30], *p;
	int i, fd, n;

	setutc();
	fd = open("/env/timezone", O_RDONLY);
	if(fd < 0)
		return;
	memset(buf, 0, sizeof buf);
	n = read(fd, buf, sizeof buf - 1);
	close(fd);
	if(n <= 0)
		return;
	p = buf;
	if(rdname(&p, tz.stname) < 0 || rdlong(&p, &tz.stoff) < 0){
		setutc();
		return;
	}
	if(rdname(&p, tz.dlname) < 0 || rdlong(&p, &tz.dloff) < 0){
		/* a zone with no DST half is not an error */
		tz.dlname[0] = 0;
		tz.dloff = tz.stoff;
		tz.dst = None;
		return;
	}
	for(i = 0; i < TZSIZE-1; i++){
		if(rdlong(&p, &tz.dlpairs[i]) < 0){
			tz.dlpairs[i] = 0;
			break;
		}
		if(tz.dlpairs[i] == 0)
			break;
	}
	tz.dlpairs[TZSIZE-1] = 0;
	tz.dst = tz.dlpairs[0] ? Plan9 : None;
}

/*
 * POSIX: localtime() and friends behave as if they called tzset(), so
 * the source is checked on every call and re-parsed when it changes.
 * That is the whole point of the tests this came from -- they set TZ and
 * ask again. Re-parsing a string is cheap; re-reading /env/timezone is a
 * system call, so that is done only when the SOURCE changes rather than
 * on every call, which is also what the old code did (it read once and
 * never again).
 */
static void
update(void)
{
	char *e;

	e = getenv("TZ");
	if(e != 0){
		if(tz.valid && tz.fromtz && strncmp(tz.src, e, Maxsrc-1) == 0)
			return;
		strncpy(tz.src, e, Maxsrc-1);
		tz.src[Maxsrc-1] = 0;
		tz.fromtz = 1;
		tz.dlpairs[0] = 0;
		parseposix(tz.src);
	} else {
		if(tz.valid && !tz.fromtz)
			return;
		tz.src[0] = 0;
		tz.fromtz = 0;
		readplan9();
	}
	tz.valid = 1;
}

/*
 * WHO RE-READS $TZ AND WHO DOES NOT, which is a real distinction and not
 * an oversight. POSIX says localtime() behaves as if it called tzset(),
 * and says localtime_r() "need not". glibc takes it at its word:
 *
 *	setenv("TZ","EST5",1); tzset();
 *	setenv("TZ","GMT-11:30",1);	/ * no tzset() * /
 *	localtime_r -> -18000		(the OLD zone)
 *	localtime   -> +41400		(the new one)
 *
 * -- measured, and sys/lib/tests/tz-test.c pins it. So _tzoffset() only
 * makes sure the state exists, and the callers that POSIX says must
 * refresh call _tzrefresh() first. Tcl needs nothing more: it watches $TZ
 * itself and calls tzset() when it changes (tclClock.c:4699), then uses
 * localtime_r.
 */
void
_tzrefresh(void)
{
	update();
}

static void
ensure(void)
{
	if(!tz.valid)
		update();
}

long
_tzoffset(time_t t, const char **name, int *isdst)
{
	int d;

	ensure();
	d = isdstat(t);
	if(isdst != 0)
		*isdst = d;
	if(name != 0)
		*name = d ? tz.dlname : tz.stname;
	return d ? tz.dloff : tz.stoff;
}

void
_tzstate(long *stoff, long *dloff, const char **stname, const char **dlname,
	int *hasdst)
{
	update();
	if(stoff != 0)
		*stoff = tz.stoff;
	if(dloff != 0)
		*dloff = tz.dloff;
	if(stname != 0)
		*stname = tz.stname;
	if(dlname != 0)
		*dlname = tz.dlname;
	if(hasdst != 0)
		*hasdst = tz.dst != None;
}
