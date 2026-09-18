/*
 * The one place that knows what time zone this process is in.
 *
 * Before this existed there were two, which is the whole bug: tzset()
 * parsed $timezone into tzname/timezone/daylight, localtime_r() read
 * /env/timezone into a private struct of its own, neither had ever
 * heard of $TZ, and nothing set tm_gmtoff or tm_zone. See tzone.c.
 */

/* re-read $TZ (or /env/timezone) now: for the callers POSIX says must */
extern void _tzrefresh(void);

/* seconds EAST of UTC at that instant; names the zone and says if it is DST */
extern long _tzoffset(time_t, const char **, int *);

/* the zone as tzset() reports it: standard and DST offsets and names */
extern void _tzstate(long *stoff, long *dloff, const char **stname,
	const char **dlname, int *hasdst);
