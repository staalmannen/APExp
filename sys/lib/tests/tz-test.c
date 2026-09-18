/*
 * tz-test.c -- does $TZ reach localtime(), and does a change to it get
 * noticed?
 *
 * WHERE THIS CAME FROM. Sixteen failures in Tcl's clock.test, all of
 * them `-timezone :localtime` -- the mode where Tcl stops using its own
 * tzdata and asks the C library -- with names that say the whole thing:
 *
 *	clock-38.3sc {ensure cache of base is correct for :localtime
 *	               if TZ-env changing / scan}
 *
 * libap had TWO timezone implementations that could not see each other,
 * and neither had heard of $TZ: tzset() parsed getenv("timezone"), Plan
 * 9's own spelling, into tzname/timezone/daylight, while localtime_r()
 * separately read /env/timezone with open() into a private static, once
 * per process, and never looked again. So setting TZ did nothing, and
 * calling tzset() did nothing to localtime(). See lib/ap/time/tzone.c.
 *
 * EVERY EXPECTED VALUE BELOW WAS MEASURED ON glibc, not derived. The
 * awkward cases are the point:
 *
 *	EST5		is five hours WEST -- a TZ offset's sign is the
 *			opposite of what tm_gmtoff uses
 *	GMT-11:30	is EAST, and has minutes
 *	+04:20		is NOT a valid TZ string (a name needs three
 *			alphabetic characters or <brackets>), so it is UTC
 *			with an EMPTY %Z -- glibc prints nothing there
 *	US/East-Indiana	needs zoneinfo, which this system has not: also UTC
 *	<+0420>-4:20	IS valid, and means +0420
 *
 * The last two are a pair on purpose: they differ only in whether the
 * name is bracketed, and a parser that accepted the first would be
 * inventing a zone.
 *
 * SECTION 4 IS THE ONE THE TESTS ARE NAMED AFTER: set TZ, ask, set it
 * again, ask again. A cached answer passes every other section in this
 * file and fails that one.
 *
 * SECTION 5 IS JULY, AND NOTHING IN clock.test WOULD HAVE CAUGHT IT.
 * Every test that found this bug uses a January date, so an
 * implementation that parsed the DST rules and dropped them would have
 * turned the suite green while being silently wrong for half of every
 * year. That is the most common shape of bug in this tree, so it gets
 * its own section rather than being trusted.
 *
 * Correct on glibc, which is where every expectation in it came from.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static int failures;

static void
ok(const char *what, int good)
{
	printf("  %s %s\n", good ? "PASS" : "FAIL", what);
	if(!good)
		failures++;
}

/*
 * Format an instant in the zone TZ names, and compare the whole string.
 * Comparing the formatted result rather than tm_gmtoff alone is
 * deliberate: it exercises %Z and %z, which is where the other half of
 * this bug lived.
 */
static void
check(const char *tzv, time_t t, const char *want)
{
	struct tm tm;
	char got[128], what[256];

	setenv("TZ", tzv, 1);
	tzset();
	if(localtime_r(&t, &tm) == 0){
		sprintf(what, "TZ=%s at %ld: localtime_r failed", tzv, (long)t);
		ok(what, 0);
		return;
	}
	strftime(got, sizeof got, "%Y-%m-%dT%H:%M:%S [%Z] %z", &tm);
	sprintf(what, "TZ=%-46s -> %s", tzv, got);
	if(strcmp(got, want) != 0){
		printf("  FAIL %s\n", what);
		printf("  note wanted                                            %s\n",
			want);
		failures++;
		return;
	}
	printf("  PASS %s\n", what);
}

#define EPOCH	((time_t)0)		/* 1970-01-01T00:00:00Z, a Thursday */
#define T20H	((time_t)72000)		/* clock.test's own base: 20:00Z */
#define JULY	((time_t)15638400)	/* 1970-07-01T00:00:00Z */

int
main(void)
{
	struct tm tm;
	time_t t;
	long o1, o2;

	printf("--- 1. an offset west, and one east with minutes ---\n");
	check("UTC0", EPOCH,	"1970-01-01T00:00:00 [UTC] +0000");
	check("EST5", EPOCH,	"1969-12-31T19:00:00 [EST] -0500");
	check("EST5", T20H,	"1970-01-01T15:00:00 [EST] -0500");
	check("GMT-11:30", EPOCH, "1970-01-01T11:30:00 [GMT] +1130");
	check("GMT-07:30", T20H, "1970-01-02T03:30:00 [GMT] +0730");
	check("GMT-03:30", EPOCH, "1970-01-01T03:30:00 [GMT] +0330");
	check("GMT", T20H,	"1970-01-01T20:00:00 [GMT] +0000");

	printf("--- 2. what is NOT a TZ string falls back to UTC ---\n");
	/*
	 * Empty %Z, not "UTC": a caller can tell "no zone" from a zone
	 * that really is UTC, and glibc prints nothing here.
	 */
	check("+04:20", EPOCH,	"1970-01-01T00:00:00 [] +0000");
	check("+03:20", T20H,	"1970-01-01T20:00:00 [] +0000");
	check("US/East-Indiana", EPOCH, "1970-01-01T00:00:00 [] +0000");

	printf("--- 3. ...but the bracketed form of the same thing IS ---\n");
	check("<+0420>-4:20", EPOCH, "1970-01-01T04:20:00 [+0420] +0420");

	printf("--- 4. a CHANGE to TZ is noticed (the tests' own name) ---\n");
	t = EPOCH;
	setenv("TZ", "EST5", 1);
	tzset();
	localtime_r(&t, &tm);
	o1 = tm.tm_gmtoff;
	setenv("TZ", "GMT-11:30", 1);
	tzset();
	localtime_r(&t, &tm);
	o2 = tm.tm_gmtoff;
	printf("  note first %+ld seconds, then %+ld\n", o1, o2);
	ok("the second TZ gives a different offset from the first",
		o1 == -5*3600L && o2 == 11*3600L+30*60L);
	/*
	 * AND THE DISTINCTION POSIX DRAWS BETWEEN THE TWO, which this
	 * test got wrong first time and glibc corrected: localtime()
	 * behaves as if it called tzset(), and localtime_r() "need not".
	 * glibc takes that literally, so with TZ changed and no tzset():
	 *
	 *	localtime_r  -> the OLD zone
	 *	localtime    -> the new one
	 *
	 * The first assertion here was that localtime_r picks the change
	 * up. It does not, on glibc, and writing the test before the
	 * implementation is what caught it -- libap had been about to
	 * refresh on every call and quietly differ from every Linux this
	 * code is developed against.
	 */
	setenv("TZ", "EST5", 1);		/* changed; no tzset() */
	localtime_r(&t, &tm);
	ok("localtime_r does NOT re-read TZ on its own", o2 == tm.tm_gmtoff);
	ok("...but localtime() does", localtime(&t)->tm_gmtoff == -5*3600L);

	printf("--- 5. July, which no test in clock.test would catch ---\n");
	/*
	 * CET with the European rules. January is CET +0100 and July is
	 * CEST +0200; an implementation that parsed the rules and ignored
	 * them gives +0100 both times and passes every section above.
	 */
	check("CET-01:00CEST-02:00,M3.5.0/02:00,M10.5.0/03:00", EPOCH,
		"1970-01-01T01:00:00 [CET] +0100");
	check("CET-01:00CEST-02:00,M3.5.0/02:00,M10.5.0/03:00", JULY,
		"1970-07-01T02:00:00 [CEST] +0200");
	/* tm_isdst has to say so as well, not just the offset */
	setenv("TZ", "CET-01:00CEST-02:00,M3.5.0/02:00,M10.5.0/03:00", 1);
	t = JULY;
	localtime_r(&t, &tm);
	ok("tm_isdst is set in July", tm.tm_isdst == 1);
	t = EPOCH;
	localtime_r(&t, &tm);
	ok("tm_isdst is clear in January", tm.tm_isdst == 0);

	printf("--- 6. the four globals tzset() publishes ---\n");
	setenv("TZ", "EST5EDT,M3.2.0/2,M11.1.0/2", 1);
	tzset();
	printf("  note tzname {%s, %s} timezone %ld daylight %d\n",
		tzname[0], tzname[1], timezone, daylight);
	/*
	 * `timezone' is seconds WEST, the opposite sign from tm_gmtoff in
	 * the same header. POSIX chose that, and it is worth a check
	 * precisely because it reads like a bug.
	 */
	ok("timezone is +18000, seconds WEST of Greenwich", timezone == 18000);
	ok("tzname[0] is EST", strcmp(tzname[0], "EST") == 0);
	ok("tzname[1] is EDT", strcmp(tzname[1], "EDT") == 0);
	ok("daylight is set", daylight != 0);

	printf("%d failure(s)\n", failures);
	return failures;
}
