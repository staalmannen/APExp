#include "../plan9/lib.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>

/*
 * timegm - convert struct tm (UTC) to time_t, inverse of gmtime()
 *
 * This is a BSD/GNU extension not in POSIX but widely expected.
 * We implement it portably by temporarily setting TZ=UTC,
 * calling mktime(), then restoring the original timezone.
 *
 * Since APE is single-threaded this is safe.
 */
time_t
timegm(struct tm *tm)
{
	time_t t;
	char *tz_save;
	char tz_buf[64];

	tz_save = getenv("TZ");
	if(tz_save != NULL){
		strncpy(tz_buf, tz_save, sizeof tz_buf - 1);
		tz_buf[sizeof tz_buf - 1] = '\0';
	} else {
		tz_buf[0] = '\0';
	}

	putenv("TZ=UTC");
	tzset();

	t = mktime(tm);

	if(tz_buf[0] != '\0'){
		/* restore original TZ */
		char restore[72];
		snprintf(restore, sizeof restore, "TZ=%s", tz_buf);
		putenv(restore);
	} else {
		/* TZ was not set; unset it */
		putenv("TZ=");
	}
	tzset();

	return t;
}
