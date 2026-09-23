/*
 * dtoa-xcheck.c -- does _dtoa still name a double uniquely?
 *
 * NOT A PLAN 9 TEST, like strtod-xcheck.c and tz-xcheck.c: it links
 * the unit under test into a host program so the answer arrives in a
 * compile rather than a VM round.
 *
 *	gcc -std=c99 -O2 -I../../src/ape/lib/ap/include \
 *		-o dtoa-xcheck dtoa-xcheck.c -lm && ./dtoa-xcheck
 *
 * WHY IT EXISTS. `stdio/_dtoa.c' and `stdio/_fconv.c' are Gay's kit,
 * shared by printf's float conversion and (since strtod was rewritten
 * on it) by every number this system reads. Four bugs were fixed in
 * that shared code while chasing strtod, and three of them could have
 * broken printf instead; nothing in the tree would have noticed. This
 * is the check that would.
 *
 * It measures the property mode 0 promises: **the shortest string that
 * reads back as the same double**. So it is `_dtoa' and `strtod'
 * checked against each other, which is a real test of both -- a wrong
 * digit string that the matching parser happens to undo would still
 * have to survive being the SHORTEST such string.
 *
 * WHAT IT CAUGHT. `_d2b' left `i' unset under Pack_32 while its
 * denormal arm reads `x[i-1]'. With that bug: 52 of 99941 wrong, and
 * subnormals came out as the literal string "?" -- Gay's internal
 * "cannot happen" marker, printed by every program that formatted a
 * denormal. With it fixed: 3 wrong, all at 2^-1016 and below.
 *
 * Note the sign: _dtoa is handed fabs(d) here and reports the sign
 * separately, so the comparison must be against fabs(d) too. Comparing
 * against d reported 49809 failures, all of them this file's fault --
 * a reminder that a cross-check can fail for its own reasons.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define strtod	ap_strtod
#define IEEE_8087	1
#include "../../src/ape/lib/ap/stdio/_fconv.c"
#include "../../src/ape/lib/ap/stdio/_dtoa.c"
#include "../../src/ape/lib/ap/string/strtod.c"
#undef strtod

int
main(void)
{
	char out[64], *p, *rve;
	int decpt, sgn, bad = 0, n = 0, q = 0;
	uint64_t u;
	double d, ad, back;
	long j;

	setvbuf(stdout, 0, _IOLBF, 0);
	srand(999);
	for(j = 0; j < 100000; j++){
		u = ((uint64_t)rand() << 40) ^ ((uint64_t)rand() << 20)
			^ (uint64_t)rand();
		memcpy(&d, &u, sizeof d);
		if(!isfinite(d))
			continue;
		ad = fabs(d);
		p = _dtoa(ad, 0, 0, &decpt, &sgn, &rve);
		if(decpt == 9999)		/* infinity or NaN */
			continue;
		if(p[0] == '?')			/* Gay's "cannot happen" */
			q++;
		snprintf(out, sizeof out, "%.*se%d", (int)(rve - p), p,
			decpt - (int)(rve - p));
		back = ap_strtod(out, 0);
		n++;
		if(memcmp(&back, &ad, sizeof ad) != 0){
			if(bad < 5)
				printf("  %a -> %s -> %a\n", ad, out, back);
			bad++;
		}
	}
	printf("_dtoa round-trip: %d checked, %d wrong, %d unprintable\n",
		n, bad, q);
	return bad != 0;
}
