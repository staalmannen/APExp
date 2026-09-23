/*
 * strtof-xcheck.c -- libap's strtof beside glibc's, on the build host.
 *
 * NOT A PLAN 9 TEST, like strtod-xcheck.c and dtoa-xcheck.c.
 *
 *	gcc -std=c99 -O2 -I../../src/ape/lib/ap/include \
 *		-o strtof-xcheck strtof-xcheck.c -lm && ./strtof-xcheck
 *
 * WHAT IS BEING ASKED. `strtof' here is `(float)strtod(...)', and the
 * question is whether rounding twice -- decimal to 53 bits, then 53 to
 * 24 -- gives the same answer as rounding once to 24. It does not, in
 * general: when the correctly rounded double lands exactly on a
 * midpoint between two floats, the second rounding no longer knows
 * which side the decimal was on and falls back on round-half-to-even.
 *
 * SECTION 5 IS THE POINT OF THE FILE. Random decimals will not find
 * that; the inputs have to be built. For a float f, the midpoint M
 * between f and the next float up is exactly representable as a
 * double, and its decimal expansion is finite -- so "M", "M minus a
 * hair" and "M plus a hair" can all be written exactly, and each has a
 * correct float answer that round-half-to-even on M may or may not
 * agree with. Sections 1 to 4 say whether ordinary use is affected;
 * section 5 says whether the construction that is supposed to break it
 * actually does.
 *
 * The reference is glibc's strtof, which is correctly rounded.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <stdint.h>

#define strtod	ap_strtod
#define strtof	ap_strtof
#define IEEE_8087	1
#include "../../src/ape/lib/ap/stdio/_fconv.c"
#include "../../src/ape/lib/ap/string/strtod.c"
#include "../../src/ape/lib/ap/string/strtof.c"
#undef strtod
#undef strtof

static int failures;

static uint32_t
fbits(float f)
{
	uint32_t u;

	memcpy(&u, &f, sizeof u);
	return u;
}

struct sect {
	const char *name;
	long n;
	long bad;
	char worst[128];
	int haveworst;
};

static void
check(struct sect *s, const char *str)
{
	float got, want;

	got = ap_strtof(str, 0);
	want = strtof(str, 0);
	s->n++;
	if(fbits(got) == fbits(want))
		return;
	s->bad++;
	if(!s->haveworst){
		snprintf(s->worst, sizeof s->worst, "%s: ours %08lx glibc %08lx",
			str, (unsigned long)fbits(got), (unsigned long)fbits(want));
		s->haveworst = 1;
	}
}

static void
report(struct sect *s)
{
	printf("  %-44s %7ld checked, %5ld wrong   %s\n", s->name, s->n,
		s->bad, s->bad ? "FAIL" : "PASS");
	if(s->bad){
		failures++;
		printf("      first: %s\n", s->worst);
	}
}

int
main(void)
{
	struct sect s1 = {"1. round-trip of random floats (%.9g)"};
	struct sect s2 = {"2. long random decimals (17 digits)"};
	struct sect s3 = {"3. the powers of ten, 1e-50..1e40"};
	struct sect s4 = {"4. the edges of the float range"};
	struct sect s5 = {"5. CONSTRUCTED float midpoints"};
	char buf[512];
	uint32_t u;
	float f;
	long j;
	int i;

	setvbuf(stdout, 0, _IOLBF, 0);
	printf("strtof-xcheck: libap's strtof against glibc's\n");

	printf("--- 1. a float printed with %%.9g must come back ---\n");
	srand(4242);
	for(j = 0; j < 200000; j++){
		u = ((uint32_t)rand() << 20) ^ ((uint32_t)rand() << 10)
			^ (uint32_t)rand();
		memcpy(&f, &u, sizeof f);
		if(!isfinite(f))
			continue;
		snprintf(buf, sizeof buf, "%.9g", f);
		check(&s1, buf);
	}
	report(&s1);

	printf("--- 2. seventeen-digit decimals, where double rounding bites ---\n");
	for(j = 0; j < 200000; j++){
		int e = (rand() % 90) - 50;

		snprintf(buf, sizeof buf, "%c%d%08d%08de%d",
			(rand() & 1) ? '-' : '+', 1 + rand() % 9,
			rand() % 100000000, rand() % 100000000, e);
		check(&s2, buf);
	}
	report(&s2);

	printf("--- 3. the powers of ten ---\n");
	for(i = -50; i <= 40; i++){
		snprintf(buf, sizeof buf, "1e%d", i);
		check(&s3, buf);
	}
	report(&s3);

	printf("--- 4. the edges ---\n");
	{
		static const char *edge[] = {
			"3.4028234663852886e+38",	/* FLT_MAX */
			"3.4028235677973366e+38",	/* just over */
			"3.402823466385289e+38",
			"1.1754943508222875e-38",	/* FLT_MIN */
			"1.1754942106924411e-38",	/* largest subnormal */
			"1.4012984643248171e-45",	/* smallest subnormal */
			"7.006492321624085e-46",	/* half of it: ties to even */
			"7.006492321624087e-46",	/* a hair more: rounds up */
			"1e-46", "1e-60", "1e39", "1e40",
			0
		};

		for(i = 0; edge[i]; i++)
			check(&s4, edge[i]);
	}
	report(&s4);

	printf("--- 5. decimals built to sit on a float midpoint ---\n");
	/*
	 * M is the midpoint between f and the next float up. It has 25
	 * significand bits, so it is exact as a double and its decimal
	 * expansion is finite: %.60e writes it exactly. Then M itself
	 * (a tie, to be broken to even), and M with a 1 appended far to
	 * the right (just above, must round up).
	 */
	srand(99);
	for(j = 0; j < 20000; j++){
		double m;
		char *p;

		u = ((uint32_t)rand() << 20) ^ ((uint32_t)rand() << 10)
			^ (uint32_t)rand();
		u &= 0x7fffffff;
		memcpy(&f, &u, sizeof f);
		if(!isnormal(f))
			continue;
		m = ((double)f + (double)nextafterf(f, INFINITY)) / 2;
		snprintf(buf, sizeof buf, "%.60e", m);
		check(&s5, buf);		/* exactly the midpoint */

		/* a hair above: insert a 1 into the last digit position */
		p = strchr(buf, 'e');
		if(p != 0 && p - buf < (int)sizeof buf - 2){
			char tail[32];

			snprintf(tail, sizeof tail, "%s", p);
			p[0] = '1';
			snprintf(p + 1, sizeof buf - (p + 1 - buf), "%s", tail);
			check(&s5, buf);
		}
	}
	report(&s5);

	printf("%d section(s) failing\n", failures);
	return failures;
}
