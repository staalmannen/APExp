#include <time.h>
#include "_npe.h"

time_t
mktime(struct tm *tm)
{
	Tm t;

	t.sec = tm->tm_sec;
	t.min = tm->tm_min;
	t.hour = tm->tm_hour;
	t.mday = tm->tm_mday;
	t.mon = tm->tm_mon;
	t.year = tm->tm_year;
	t.wday = tm->tm_wday;
	t.yday = tm->tm_yday;
	t.tzoff = 0;
	t.tz = tzload(tm->tm_zone);
	/* ... = tm.tm_isdst; */ /* FIXME */

	return tmnorm(&t) / Nsec;
}
