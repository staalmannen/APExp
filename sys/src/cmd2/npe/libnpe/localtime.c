#include <time.h>

#undef localtime

static struct tm tm;

struct tm *
npe_localtime(time_t *timep)
{
	time_t ti;
	Tm *t;

	ti = timep ? *timep : time(nil);
	if((t = localtime(ti)) != nil){
		tm.tm_sec = t->sec;
		tm.tm_min = t->min;
		tm.tm_hour = t->hour;
		tm.tm_mday = t->mday;
		tm.tm_mon = t->mon;
		tm.tm_year = t->year;
		tm.tm_wday = t->wday;
		tm.tm_yday = t->yday;
		tm.tm_isdst = 0; /* FIXME */
		tm.tm_zone = "local";
	}

	return &tm;
}
