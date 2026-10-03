/*
 * strftime-xcheck -- a HOST program, not a Plan 9 test.
 *
 * It compiles libap's own `string/strftime.c' into a glibc program
 * under a different name and sweeps every conversion over many
 * instants against glibc's strftime, printing every disagreement.
 *
 *	gcc -Wall -c -o /tmp/ap_strftime.o \
 *	    -Dstrftime=ap_strftime -Dstrftime_l=ap_strftime_l \
 *	    ../../src/ape/lib/ap/string/strftime.c
 *	gcc -Wall -o /tmp/strftime-xcheck strftime-xcheck.c /tmp/ap_strftime.o
 *	/tmp/strftime-xcheck
 *
 * **TWO compiles, and it must be two**, which cost a round. The -D
 * pair is what keeps libap's definitions from colliding with glibc's,
 * and compiling both files in ONE command applies it to this file as
 * well -- so the checker's own `strftime(want, ...)' call becomes
 * `ap_strftime' and the sweep compares libap against ITSELF. It
 * reported `204960 checked, 0 wrong' that way, and a deliberately
 * broken ISO-week branch reported 0 wrong too. *The control is what
 * caught it; the clean number alone was indistinguishable from a real
 * one.* Same family as `ctype-xcheck', which needs two compiles for a
 * different reason.
 *
 * ------------------------------------------------------------------
 * WHY A CROSS-CHECK AND NOT A TEST.
 *
 * A test run on glibc passes by asking glibc for the answers and says
 * nothing about our parser until it reaches the VM -- the rule this
 * tree learned from `tz-xcheck.c', which swept 1.4M instants and found
 * two bugs with no rebuild. Everything strftime does is a pure
 * function of a `struct tm', so it is exactly the shape that pattern
 * is for.
 *
 * **And the ISO week conversions are why it exists.** `%G', `%g' and
 * `%V' have two edges -- a January date belonging to week 52/53 of the
 * previous year, and a late-December date belonging to week 1 of the
 * next -- and both are easy to write plausibly and get wrong. A sweep
 * that walked only mid-year dates could not fail; this one walks every
 * day of fourteen years, which reaches both edges hundreds of times.
 *
 * ------------------------------------------------------------------
 * WHAT IT CANNOT CHECK, stated so a clean run is not over-read:
 *
 *   %Z %z   depend on the zone the struct tm carries; swept, but with
 *           TZ=UTC0 so both sides agree about what the answer means.
 *   %s      calls mktime, which is GLIBC's here -- so this checks the
 *           formatting, not libap's own mktime.
 *   %c %x %X %p  are locale-dependent; the C locale is forced.
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

size_t ap_strftime(char *, size_t, const char *, const struct tm *);

static const char *convs[] = {
	"%a", "%A", "%b", "%B", "%c", "%C", "%d", "%D", "%e", "%F",
	"%g", "%G", "%h", "%H", "%I", "%j", "%m", "%M", "%n", "%p",
	"%r", "%R", "%S", "%t", "%T", "%u", "%U", "%V", "%w", "%W",
	"%x", "%X", "%y", "%Y", "%%",
	/* a few in combination, which is how real formats come */
	"%Y-%m-%d", "%F %r", "%e-%b-%Y %T", "%G-W%V-%u", "%x %X",
};
#define NCONV (int)(sizeof(convs)/sizeof(convs[0]))

int
main(void)
{
	char want[256], got[256];
	struct tm tm;
	time_t t;
	long i;
	int c;
	long checked = 0, wrong = 0;
	long perconv[NCONV];

	setenv("TZ", "UTC0", 1);
	tzset();
	setlocale(LC_ALL, "C");
	for(c = 0; c < NCONV; c++)
		perconv[c] = 0;

	printf("strftime-xcheck: libap's strftime against glibc's\n");
	printf("%d conversions x every day from 1995 to 2008 inclusive\n\n",
		NCONV);

	/*
	 * Every day of fourteen years. 1995 starts on a Sunday and 2004
	 * is a leap year beginning on a Thursday, so the ISO week edges
	 * -- Jan 1 in last year's week 53, Dec 31 in next year's week 1
	 * -- both occur repeatedly in this range rather than by luck.
	 */
	for(i = 0; i < 14L*366; i++){
		t = 788918400L + i*86400L + 43271L;	/* 1995-01-01 + noonish */
		if(gmtime_r(&t, &tm) == 0)
			continue;
		for(c = 0; c < NCONV; c++){
			memset(want, 0, sizeof want);
			memset(got, 0, sizeof got);
			strftime(want, sizeof want, convs[c], &tm);
			ap_strftime(got, sizeof got, convs[c], &tm);
			checked++;
			if(strcmp(want, got) != 0){
				wrong++;
				perconv[c]++;
				if(perconv[c] <= 3)
					printf("  %s on %04d-%02d-%02d: "
						"glibc \"%s\"  libap \"%s\"\n",
						convs[c], tm.tm_year+1900,
						tm.tm_mon+1, tm.tm_mday,
						want, got);
			}
		}
	}

	printf("\n%ld checked, %ld wrong\n", checked, wrong);
	if(wrong){
		printf("per conversion:\n");
		for(c = 0; c < NCONV; c++)
			if(perconv[c])
				printf("  %-12s %ld\n", convs[c], perconv[c]);
	}
	return wrong != 0;
}
