#include "../include/lib.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * strptime - parse a date/time string into struct tm
 *
 * Implements the POSIX strptime interface. Supports the most commonly
 * used format specifiers. Returns pointer to first unparsed character,
 * or NULL on failure.
 */

static const char *daynames[] = {
	"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday",
	"Sun","Mon","Tue","Wed","Thu","Fri","Sat",
	NULL
};
static const char *monnames[] = {
	"January","February","March","April","May","June",
	"July","August","September","October","November","December",
	"Jan","Feb","Mar","Apr","May","Jun",
	"Jul","Aug","Sep","Oct","Nov","Dec",
	NULL
};

static int
matchname(const char *s, const char **names, int *val, int nfull)
{
	int i;
	for(i = 0; names[i] != NULL; i++){
		int len = strlen(names[i]);
		if(strncasecmp(s, names[i], len) == 0){
			*val = i % nfull;
			return len;
		}
	}
	return 0;
}

static int
getnum(const char *s, int *val, int min, int max)
{
	int n = 0, digits = 0;
	while(*s >= '0' && *s <= '9'){
		n = n * 10 + (*s - '0');
		s++;
		digits++;
	}
	if(digits == 0 || n < min || n > max)
		return 0;
	*val = n;
	return digits;
}

char *
strptime(const char *buf, const char *fmt, struct tm *tm)
{
	const char *s = buf;
	int n, val;

	while(*fmt){
		if(*fmt != '%'){
			/* literal character */
			if(isspace((unsigned char)*fmt)){
				while(isspace((unsigned char)*s)) s++;
			} else {
				if(*s != *fmt) return NULL;
				s++;
			}
			fmt++;
			continue;
		}
		fmt++; /* skip % */

		switch(*fmt++){
		case 'Y': /* 4-digit year */
			n = getnum(s, &val, 1, 9999);
			if(!n) return NULL;
			tm->tm_year = val - 1900;
			s += n;
			break;
		case 'y': /* 2-digit year */
			n = getnum(s, &val, 0, 99);
			if(!n) return NULL;
			tm->tm_year = val >= 69 ? val : val + 100;
			s += n;
			break;
		case 'm': /* month 01-12 */
			n = getnum(s, &val, 1, 12);
			if(!n) return NULL;
			tm->tm_mon = val - 1;
			s += n;
			break;
		case 'd': /* day 01-31 */
		case 'e':
			while(isspace((unsigned char)*s)) s++;
			n = getnum(s, &val, 1, 31);
			if(!n) return NULL;
			tm->tm_mday = val;
			s += n;
			break;
		case 'H': /* hour 00-23 */
			n = getnum(s, &val, 0, 23);
			if(!n) return NULL;
			tm->tm_hour = val;
			s += n;
			break;
		case 'I': /* hour 01-12 */
			n = getnum(s, &val, 1, 12);
			if(!n) return NULL;
			tm->tm_hour = val;
			s += n;
			break;
		case 'M': /* minute 00-59 */
			n = getnum(s, &val, 0, 59);
			if(!n) return NULL;
			tm->tm_min = val;
			s += n;
			break;
		case 'S': /* second 00-60 (leap) */
			n = getnum(s, &val, 0, 60);
			if(!n) return NULL;
			tm->tm_sec = val;
			s += n;
			break;
		case 'j': /* day of year 001-366 */
			n = getnum(s, &val, 1, 366);
			if(!n) return NULL;
			tm->tm_yday = val - 1;
			s += n;
			break;
		case 'w': /* weekday 0-6, 0=Sunday */
			n = getnum(s, &val, 0, 6);
			if(!n) return NULL;
			tm->tm_wday = val;
			s += n;
			break;
		case 'A': /* full weekday name */
		case 'a': /* abbreviated weekday name */
			n = matchname(s, daynames, &val, 7);
			if(!n) return NULL;
			tm->tm_wday = val;
			s += n;
			break;
		case 'B': /* full month name */
		case 'b': /* abbreviated month name */
		case 'h':
			n = matchname(s, monnames, &val, 12);
			if(!n) return NULL;
			tm->tm_mon = val;
			s += n;
			break;
		case 'p': /* AM/PM */
		case 'P':
			if(strncasecmp(s, "am", 2) == 0){
				if(tm->tm_hour == 12) tm->tm_hour = 0;
				s += 2;
			} else if(strncasecmp(s, "pm", 2) == 0){
				if(tm->tm_hour != 12) tm->tm_hour += 12;
				s += 2;
			} else return NULL;
			break;
		case 'n': /* newline */
		case 't': /* tab */
			while(isspace((unsigned char)*s)) s++;
			break;
		case 'D': /* %m/%d/%y */
			s = strptime(s, "%m/%d/%y", tm);
			if(!s) return NULL;
			break;
		case 'F': /* %Y-%m-%d */
			s = strptime(s, "%Y-%m-%d", tm);
			if(!s) return NULL;
			break;
		case 'T': /* %H:%M:%S */
			s = strptime(s, "%H:%M:%S", tm);
			if(!s) return NULL;
			break;
		case 'R': /* %H:%M */
			s = strptime(s, "%H:%M", tm);
			if(!s) return NULL;
			break;
		case 'r': /* %I:%M:%S %p */
			s = strptime(s, "%I:%M:%S %p", tm);
			if(!s) return NULL;
			break;
		case '%': /* literal % */
			if(*s != '%') return NULL;
			s++;
			break;
		default:
			/* unknown specifier — skip */
			break;
		}
	}
	return (char *)s;
}
