#include <time.h>

size_t
strftime(char *s, size_t max, const char *format, const struct tm *tm)
{
	char *s₀, *e, *f, c;
	int i;
	Tm t;

	memset(&t, 0, sizeof(t));
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
	/* ... = tm->tm_isdst; */ /* FIXME */

	*s = 0;
	s₀ = s;
	e = s+max;
	for(i = 0; format[i]; i++){
		if((c = format[i]) == '%'){
			c = format[i+1];
			f = nil;
			switch(c){
			case 'Y': f = "YYYY"; break;
			case 'm': f = "MM"; break;
			case 'd': f = "DD"; break;
			case 'H': f = "hh"; break;
			case 'M': f = "mm"; break;
			case 'S': f = "ss"; break;
			/* FIXME - more formatting */
			case '%': break;
			default: s = seprint(s, e, "%%"); break;
			}
			i++;
			if(f != nil){
				s = seprint(s, e, "%τ", tmfmt(&t, f));
				continue;
			}
		}
		s = seprint(s, e, "%c", c);
	}

	return s-s₀;
}
