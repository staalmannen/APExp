/*
 * This routine converts time as follows.
 * The epoch is 0000 Jan 1 1970 GMT.
 * The argument time is in seconds since then.
 * The localtime(t) entry returns a pointer to an array
 * containing
 *
 *	seconds (0-59)
 *	minutes (0-59)
 *	hours (0-23)
 *	day of month (1-31)
 *	month (0-11)
 *	year-1970
 *	weekday (0-6, Sun is 0)
 *	day of the year
 *	daylight savings flag
 *
 * The routine gets the daylight savings time from the environment.
 *
 * asctime(tvec))
 * where tvec is produced by localtime
 * returns a ptr to a character string
 * that has the ascii time in the form
 *
 *	                            \\
 *	Thu Jan 01 00:00:00 1970n0
 *	01234567890123456789012345
 *	0	  1	    2
 *
 * ctime(t) just calls localtime, then asctime.
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "tzone.h"

static	char	dmsize[12] =
{
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

/*
 * The following table is used for 1974 and 1975 and
 * gives the day number of the first day after the Sunday of the
 * change.
 */

static	int	dysize(int);
static	void	ct_numb(char*, int);

char*
ctime(const time_t *t)
{
	return asctime(localtime(t));
}

struct tm*
gmtime_r(const time_t *timp, struct tm *result)
{
	int d0, d1;
	long hms, day;
	time_t tim;

	tim = *timp;
	/*
	 * break initial number into days
	 */
	hms = tim % 86400L;
	day = tim / 86400L;
	if(hms < 0) {
		hms += 86400L;
		day -= 1;
	}

	/*
	 * generate hours:minutes:seconds
	 */
	result->tm_sec = hms % 60;
	d1 = hms / 60;
	result->tm_min = d1 % 60;
	d1 /= 60;
	result->tm_hour = d1;

	/*
	 * day is the day number.
	 * generate day of the week.
	 * The addend is 4 mod 7 (1/1/1970 was Thursday)
	 */

	result->tm_wday = (day + 7340036L) % 7;

	/*
	 * year number
	 */
	if(day >= 0)
		for(d1 = 70; day >= dysize(d1); d1++)
			day -= dysize(d1);
	else
		for (d1 = 70; day < 0; d1--)
			day += dysize(d1-1);
	result->tm_year = d1;
	result->tm_yday = d0 = day;

	/*
	 * generate month
	 */

	if(dysize(d1) == 366)
		dmsize[1] = 29;
	for(d1 = 0; d0 >= dmsize[d1]; d1++)
		d0 -= dmsize[d1];
	dmsize[1] = 28;
	result->tm_mday = d0 + 1;
	result->tm_mon = d1;
	result->tm_isdst = 0;
	result->tm_gmtoff = 0;
	result->tm_zone = "GMT";
	return result;
}

struct tm*
gmtime(const time_t *timp)
{
	static struct tm xtime;

	return gmtime_r(timp, &xtime);
}

struct tm*
localtime_r(const time_t *timp, struct tm *result)
{
	struct tm *ct;
	time_t t;
	const char *name;
	long off;
	int isdst;

	/*
	 * All of the zone logic is in tzone.c now. This used to read
	 * /env/timezone into a static of its own, once per process, with
	 * no idea that $TZ or tzset() existed; see the note there.
	 *
	 * tm_gmtoff and tm_zone are set here because struct tm in this
	 * system HAS both and nothing ever filled them in, so strftime's
	 * %z and %Z had nothing to read and invented an answer.
	 */
	off = _tzoffset(*timp, &name, &isdst);
	t = *timp + off;
	ct = gmtime_r(&t, result);
	if(ct == 0)
		return 0;
	ct->tm_isdst = isdst;
	ct->tm_gmtoff = off;
	ct->tm_zone = name;
	return ct;
}

struct tm*
localtime(const time_t *timp)
{
	static struct tm xtime;

	/*
	 * POSIX: localtime() behaves as if it called tzset(), and
	 * localtime_r() need not -- so the refresh is HERE and not in the
	 * function below. glibc draws the same line; see time/tzone.c.
	 */
	_tzrefresh();
	return localtime_r(timp, &xtime);
}

char*
asctime_r(const struct tm *t, char *buf)
{
	char *ncp;

	strcpy(buf, "Thu Jan 01 00:00:00 1970\n");
	ncp = &"SunMonTueWedThuFriSat"[t->tm_wday*3];
	buf[0] = *ncp++;
	buf[1] = *ncp++;
	buf[2] = *ncp;
	ncp = &"JanFebMarAprMayJunJulAugSepOctNovDec"[t->tm_mon*3];
	buf[4] = *ncp++;
	buf[5] = *ncp++;
	buf[6] = *ncp;
	ct_numb(buf+8, t->tm_mday);
	ct_numb(buf+11, t->tm_hour+100);
	ct_numb(buf+14, t->tm_min+100);
	ct_numb(buf+17, t->tm_sec+100);
	if(t->tm_year >= 100) {
		buf[20] = '2';
		buf[21] = '0';
	}
	ct_numb(buf+22, t->tm_year+100);
	return buf;
}

char*
asctime(const struct tm *t)
{
	static char cbuf[30];

	return asctime_r(t, cbuf);
}

static
dysize(int y)
{
	if((y%4) == 0)
		return 366;
	return 365;
}

static
void
ct_numb(char *cp, int n)
{
	cp[0] = ' ';
	if(n >= 10)
		cp[0] = (n/10)%10 + '0';
	cp[1] = n%10 + '0';
}
