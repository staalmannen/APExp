#include <time.h>
#include <string.h>
#include <locale.h>

static char *awday[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
static char *wday[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
			"Friday", "Saturday"};
#define ISLEAP(y)	(((y)%4 == 0 && (y)%100 != 0) || (y)%400 == 0)

static char *amon[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
			    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
static char *mon[12] = {"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"};
static char *ampm[2] = {"AM", "PM"};

/*
 * MOST OF POSIX's CONVERSIONS WERE MISSING, and the `default:' arm
 * below writes the conversion character out as a literal -- so every
 * one of them printed its own letter and said nothing. The same shape
 * as `vfprintf''s missing `%td': *an unrecognised conversion that
 * prints the letter is silent in exactly the way a wrong number is
 * not.*
 *
 * Measured, in bash's `printf3.sub' (the `%(...)T' conversion feeds
 * its argument straight to strftime):
 *
 *	printf "current time: %(%F %r)T\n"   ->  current time: F r
 *	printf "%(%e-%b-%Y %T)T\n"           ->  e-May-2010 T
 *	printf -v v2 "%(%s)T" -1             ->  current time mismatch
 *
 * Absent: C D e F G g h n r R s t T u V, and `%%' worked only by
 * falling through `default:'. All of them are in POSIX.1 and C99
 * 7.23.3.5; they are added here, and `%%' is explicit so that the
 * default arm means "unknown" rather than "the escape".
 *
 * `%c' and `%x' were also WRONG rather than missing. POSIX fixes both
 * in the C locale -- `%c' is "%a %b %e %H:%M:%S %Y" and `%x' is
 * "%m/%d/%y" -- and this file had "%a %b %d %H:%M:%S %Y" and
 * "%a %b %d, %Y". bash's `printf "%(%x %X)T"' expects `05/30/10
 * 15:09:15' and got `Sun May 30, 2010 15:09:15', which is how the
 * second one was found; `%c' differed only by `%d' for `%e' and is
 * corrected with it.
 */

static int jan1(int);
static int isoweek(const struct tm *, int *);
static char *strval(char *, char *, char **, int, int);
static char *dval(char *, char *, int, int);
static char *spval(char *, char *, int, int);
static char *llval(char *, char *, long long);

size_t
strftime(char *s, size_t maxsize, const char *format, const struct tm *t)
{
	char *sp, *se, *fp, *cp;
	int i;

	sp = s;
	se = s+maxsize;
	for(fp=(char *)format; *fp && sp<se; fp++){
		if(*fp != '%')
			*sp++ = *fp;
		else switch(*++fp){
			case 'a':
				sp = strval(sp, se, awday, t->tm_wday, 7);
				break;
			case 'A':
				sp = strval(sp, se, wday, t->tm_wday, 7);
				break;
			case 'b':
				sp = strval(sp, se, amon, t->tm_mon, 12);
				break;
			case 'B':
				sp = strval(sp, se, mon, t->tm_mon, 12);
				break;
			case 'c':
				sp += strftime(sp, se-sp, "%a %b %e %H:%M:%S %Y", t);
				break;
			case 'C':
				sp = dval(sp, se, (t->tm_year+1900)/100, 2);
				break;
			case 'd':
				sp = dval(sp, se, t->tm_mday, 2);
				break;
			case 'D':
				sp += strftime(sp, se-sp, "%m/%d/%y", t);
				break;
			case 'e':
				sp = spval(sp, se, t->tm_mday, 2);
				break;
			case 'F':
				sp += strftime(sp, se-sp, "%Y-%m-%d", t);
				break;
			case 'g':
				isoweek(t, &i);
				sp = dval(sp, se, i%100, 2);
				break;
			case 'G':
				isoweek(t, &i);
				sp = dval(sp, se, i, 4);
				break;
			case 'h':
				sp = strval(sp, se, amon, t->tm_mon, 12);
				break;
			case 'n':
				if(sp < se) *sp++ = '\n';
				break;
			case 'r':
				sp += strftime(sp, se-sp, "%I:%M:%S %p", t);
				break;
			case 'R':
				sp += strftime(sp, se-sp, "%H:%M", t);
				break;
			case 's':
				/*
				 * Seconds since the Epoch. `mktime' is given
				 * a COPY: it normalises its argument, and a
				 * conversion must not rewrite the caller's
				 * struct tm. coreutils' `date +%s' reaches
				 * gnulib's strftime, which does the same
				 * thing through `mktime_z' -- so the two
				 * agree, which is what bash's `printf3.sub'
				 * compares.
				 */
				{
					struct tm cp;

					cp = *t;
					sp = llval(sp, se, (long long)mktime(&cp));
				}
				break;
			case 't':
				if(sp < se) *sp++ = '\t';
				break;
			case 'T':
				sp += strftime(sp, se-sp, "%H:%M:%S", t);
				break;
			case 'u':
				/* ISO weekday, Monday 1 .. Sunday 7 */
				i = t->tm_wday;
				sp = dval(sp, se, i == 0 ? 7 : i, 1);
				break;
			case 'V':
				sp = dval(sp, se, isoweek(t, &i), 2);
				break;
			case '%':
				if(sp < se) *sp++ = '%';
				break;
			case 'H':
				sp = dval(sp, se, t->tm_hour, 2);
				break;
			case 'I':
				i = t->tm_hour;
				if(i == 0)
					i = 12;
				else if(i > 12)
					i -= 12;
				sp = dval(sp, se, i, 2);
				break;
			case 'j':
				sp = dval(sp, se, t->tm_yday+1, 3);
				break;
			case 'm':
				sp = dval(sp, se, t->tm_mon+1, 2);
				break;
			case 'M':
				sp = dval(sp, se, t->tm_min, 2);
				break;
			case 'p':
				i = (t->tm_hour < 12)? 0 : 1;
				sp = strval(sp, se, ampm, i, 2);
				break;
			case 'S':
				sp = dval(sp, se, t->tm_sec, 2);
				break;
			case 'U':
				i = 7-jan1(t->tm_year);
				if(i == 7)
					i = 0;
				/* Now i is yday number of first sunday in year */
				if(t->tm_yday < i)
					i = 0;
				else
					i = (t->tm_yday-i)/7 + 1;
				sp = dval(sp, se, i, 2);
				break;
			case 'w':
				sp = dval(sp, se, t->tm_wday, 1);
				break;
			case 'W':
				i = 8-jan1(t->tm_year);
				if(i >= 7)
					i -= 7;
				/* Now i is yday number of first monday in year */
				if(t->tm_yday < i)
					i = 0;
				else
					i = (t->tm_yday-i)/7 + 1;
				sp = dval(sp, se, i, 2);
				break;
			case 'x':
				sp += strftime(sp, se-sp, "%m/%d/%y", t);
				break;
			case 'X':
				sp += strftime(sp, se-sp, "%H:%M:%S", t);
				break;
			case 'y':
				sp = dval(sp, se, t->tm_year%100, 2);
				break;
			case 'Y':
				sp = dval(sp, se, t->tm_year+1900, 4);
				break;
			case 'Z':
				/*
				 * This was `strval(sp, se, tz, t->tm_isdst, 2)'
				 * against a static {"EST", "EDT"}, under the
				 * comment "hack for now: assume eastern time
				 * zone" -- every zone in the world printed as
				 * one of two names. struct tm carries tm_zone
				 * here; nothing had ever filled it in, which is
				 * why the hack looked necessary. It does now
				 * (see time/tzone.c), so read it.
				 *
				 * An empty name is not an error and must print
				 * as nothing: that is what a zone we could not
				 * identify looks like, and glibc prints nothing
				 * for it too.
				 */
				if(t->tm_zone != 0)
					for(cp = (char *)t->tm_zone; *cp && sp < se; cp++)
						*sp++ = *cp;
				break;
			case 'z':
				/*
				 * Did not exist at all, so `%z' fell through to
				 * `default:' and printed a literal `z'.
				 * +hhmm/-hhmm, EAST of Greenwich positive --
				 * the opposite sign from the `timezone' global
				 * four lines from it in <time.h>.
				 */
				{
					long off;
					int neg;

					off = t->tm_gmtoff;
					neg = off < 0;
					if(neg)
						off = -off;
					if(sp < se)
						*sp++ = neg ? '-' : '+';
					sp = dval(sp, se, (int)(off/3600), 2);
					sp = dval(sp, se, (int)(off/60%60), 2);
				}
				break;
			case 0:
				fp--; /* stop loop after next fp incr */
				break;
			default:
				*sp++ = *fp;
			}
	}
	if(*fp)
		sp = s; /* format string didn't end: no room for conversion */
	if(sp<se)
		*sp = 0;
	return sp-s;
}

size_t
strftime_l(char *s, size_t maxsize, const char *format, const struct tm *t, locale_t locale)
{
	return strftime(s, maxsize, format, t);
}

static char *
strval(char *start, char *end, char **array, int index, int alen)
{
	int n;

	if(index<0 || index>=alen){
		*start = '?';
		return start+1;
	}
	n = strlen(array[index]);
	if(n > end-start)
		n = end-start;
	memcpy(start, array[index], n);
	return start+n;
}

static char *
dval(char *start, char *end, int val, int width)
{
	char *p;

	if(val<0 || end-start<width){
		*start = '?';
		return start+1;
	}
	p = start+width-1;
	while(p>=start){
		*p-- = val%10 + '0';
		val /= 10;
	}
	if(val>0)
		*start = '*';
	return start+width;
}

/*
 * Like dval, but padded with SPACES rather than zeros: `%e'.
 */
static char *
spval(char *start, char *end, int val, int width)
{
	char *p;

	if(val<0 || end-start<width){
		*start = '?';
		return start+1;
	}
	p = start+width-1;
	while(p>=start){
		*p-- = val%10 + '0';
		val /= 10;
		if(val == 0)
			break;
	}
	while(p>=start)
		*p-- = ' ';
	return start+width;
}

/*
 * `%s' is the one conversion with no fixed width, and the one that
 * can be negative (an instant before 1970), so it cannot go through
 * dval. It writes nothing at all if the buffer is too small, which is
 * what the caller's `sp<se' loop expects.
 */
static char *
llval(char *start, char *end, long long val)
{
	char buf[24];
	int n;
	int neg;
	unsigned long long u;

	neg = val < 0;
	u = neg ? -(unsigned long long)val : (unsigned long long)val;
	n = 0;
	do{
		buf[n++] = u%10 + '0';
		u /= 10;
	}while(u);
	if(neg)
		buf[n++] = '-';
	if(n > end-start)
		return start;
	while(n > 0)
		*start++ = buf[--n];
	return start;
}

/*
 * ISO 8601 week number, and the week-based year through *year.
 *
 * The rule is one sentence: a week runs Monday to Sunday and belongs
 * to the year that holds its THURSDAY. So the week number is the
 * Thursday's day-of-year divided by seven, rounded up -- and a date in
 * the first days of January can belong to week 52 or 53 of the
 * previous year, while the last days of December can belong to week 1
 * of the next. Both edges are handled below; they are the only reason
 * this is more than one line, and they are what a sweep against glibc
 * is for (see `strftime-test.c').
 */
static int
isoweek(const struct tm *t, int *year)
{
	int wday, yday, yr, week, ylen, plen;

	yr = t->tm_year + 1900;
	yday = t->tm_yday;			/* 0-based */
	wday = (t->tm_wday + 6) % 7;		/* Monday 0 .. Sunday 6 */

	/* day-of-year of this week's Thursday, 0-based; may be <0 or >=ylen */
	week = (yday - wday + 3);

	ylen = ISLEAP(yr) ? 366 : 365;
	plen = ISLEAP(yr-1) ? 366 : 365;

	if(week < 0){				/* Thursday is last year's */
		yr--;
		week += plen;
	} else if(week >= ylen){		/* Thursday is next year's */
		yr++;
		week -= ylen;
	}
	if(year)
		*year = yr;
	return week/7 + 1;
}

/*
 *	return day of the week
 *	of jan 1 of given year
 */
static int
jan1(int yr)
{
	int y, d;

/*
 *	normal gregorian calendar
 *	one extra day per four years
 */

	y = yr+1900;
	d = 4+y+(y+3)/4;

/*
 *	julian calendar
 *	regular gregorian
 *	less three days per 400
 */

	if(y > 1800) {
		d -= (y-1701)/100;
		d += (y-1601)/400;
	}

/*
 *	great calendar changeover instant
 */

	if(y > 1752)
		d += 3;

	return(d%7);
}
