/*
 * strtoint-xcheck -- a HOST program, not a Plan 9 test.
 *
 * It compiles libap's own `strtoll.c' and `strtoull.c' into a glibc
 * program under different names and sweeps both against glibc's,
 * printing every disagreement in value, endptr and errno.
 *
 *	gcc -Wall -c -o /tmp/ap_strtoll.o \
 *	    -Dstrtoll=ap_strtoll -Dstrtoimax=ap_strtoimax \
 *	    ../../src/ape/lib/ap/string/strtoll.c
 *	gcc -Wall -c -o /tmp/ap_strtoull.o -Dstrtoull=ap_strtoull \
 *	    ../../src/ape/lib/ap/string/strtoull.c
 *	gcc -Wall -o /tmp/strtoint-xcheck strtoint-xcheck.c \
 *	    /tmp/ap_strtoll.o /tmp/ap_strtoull.o
 *	/tmp/strtoint-xcheck
 *
 * **THREE compiles, and the -D must NOT reach this file** -- the same
 * trap `strftime-xcheck' and `ctype-xcheck' carry: renaming the unit
 * under test in one command renames the checker's reference call too,
 * and the sweep then compares libap against ITSELF and prints a clean
 * number. Break one on purpose and confirm the instrument notices
 * before believing a zero.
 *
 * `strtol'/`strtoul' are NOT swept here and the reason is not an
 * oversight: kencc's `long' is 32-bit on amd64 and the host's is 64,
 * so the two disagree about the correct answer for every value above
 * 2^31 by definition. A cross-check needs both sides to agree on what
 * is being computed.
 *
 * ------------------------------------------------------------------
 * THE BUG IT CAME FROM.
 *
 * `strtoull.c' opened with
 *
 *	#define UVLONG_MAX	(1LL<<63)
 *
 * which is not the largest `unsigned long long'. The saturation
 * value on overflow was therefore 2^63, and -- because the literal is
 * SIGNED -- `m = UVLONG_MAX/base' was a signed division whose
 * negative quotient converted to an unsigned value just under
 * ULLONG_MAX, so the threshold was effectively disabled and overflow
 * detection fell back on a wrap test that misses a multi-wrap.
 * `strtoul.c' in the same directory uses `ULONG_MAX' and is right:
 * *the library held a correct version of the thing it got wrong*,
 * which is now the fourth time in this tree.
 *
 * **The control is the point of this file, twice over.** Restoring
 * the exact original line makes it report 28 wrong against 0 -- and
 * it also corrected the explanation above, which first said the
 * threshold was "halved" and predicted a band of false ERANGEs. The
 * failing cases are wrap misses instead. *An expression read rather
 * than evaluated is a guess.*
 *
 * The sweep then found TWO MORE that reading had not: `strtoll' of
 * LLONG_MIN answering ERANGE for a representable value (its
 * magnitude is one more than LLONG_MAX, and the loop used one limit
 * for both signs), and `strtoX("0x")' with no hex digit reporting no
 * conversion where C converts the `0' and leaves endptr on the `x'.
 *
 * It was all found while chasing something else entirely (bash
 * printing `FFFFFFFF9B3A59A5' for `printf "%08X" 2604292517'), and
 * **none of it is that bug** -- 2604292517 is far below any threshold
 * here and parsed correctly even before. Recorded so the two are not
 * confused: this sweep says nothing about the %08X question.
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <inttypes.h>

long long ap_strtoll(char *, char **, int);
unsigned long long ap_strtoull(char *, char **, int);

static long checked, wrong;

static void
ck_u(const char *s, int base)
{
	char *e1, *e2;
	unsigned long long v1, v2;
	int r1, r2;
	char buf[128];

	strcpy(buf, s);
	errno = 0; v1 = strtoull(buf, &e1, base); r1 = errno;
	errno = 0; v2 = ap_strtoull(buf, &e2, base); r2 = errno;
	checked++;
	if(v1 != v2 || (e1-buf) != (e2-buf) || (r1==ERANGE) != (r2==ERANGE)){
		wrong++;
		if(wrong <= 20)
			printf("  strtoull(\"%s\", %d): glibc %llu end+%d %s | "
				"libap %llu end+%d %s\n", s, base,
				v1, (int)(e1-buf), r1==ERANGE?"ERANGE":"ok",
				v2, (int)(e2-buf), r2==ERANGE?"ERANGE":"ok");
	}
}

static void
ck_s(const char *s, int base)
{
	char *e1, *e2;
	long long v1, v2;
	int r1, r2;
	char buf[128];

	strcpy(buf, s);
	errno = 0; v1 = strtoll(buf, &e1, base); r1 = errno;
	errno = 0; v2 = ap_strtoll(buf, &e2, base); r2 = errno;
	checked++;
	if(v1 != v2 || (e1-buf) != (e2-buf) || (r1==ERANGE) != (r2==ERANGE)){
		wrong++;
		if(wrong <= 20)
			printf("  strtoll(\"%s\", %d): glibc %lld end+%d %s | "
				"libap %lld end+%d %s\n", s, base,
				v1, (int)(e1-buf), r1==ERANGE?"ERANGE":"ok",
				v2, (int)(e2-buf), r2==ERANGE?"ERANGE":"ok");
	}
}

int
main(void)
{
	char buf[128];
	unsigned long long u;
	int i, base;

	printf("strtoint-xcheck: libap's strtoll/strtoull against glibc's\n\n");

	/*
	 * 1. The boundaries. These are where the bug lived, and a sweep
	 *    of random small numbers would never reach them.
	 */
	{
		static const char *edge[] = {
			"0", "1", "-1", "+1", "   42", "\t\n 7",
			"9223372036854775806",		/* LLONG_MAX-1 */
			"9223372036854775807",		/* LLONG_MAX */
			"9223372036854775808",		/* LLONG_MAX+1 */
			"-9223372036854775808",		/* LLONG_MIN */
			"-9223372036854775809",		/* LLONG_MIN-1 */
			"18446744073709551614",		/* ULLONG_MAX-1 */
			"18446744073709551615",		/* ULLONG_MAX */
			"18446744073709551616",		/* ULLONG_MAX+1 */
			"99999999999999999999999",
			"2604292517",			/* bash's %08X value */
			"0x9B3A59A5", "0XFFFFFFFFFFFFFFFF", "0x10000000000000000",
			"010", "0777777777777777777777", "01777777777777777777777",
			"", " ", "-", "+", "x", "0x", "0xzz",
			"12abc", "  -0x1Fg", "99999999999999999999x",
		};

		printf("1. boundaries and malformed input\n");
		for(i = 0; i < (int)(sizeof edge/sizeof edge[0]); i++){
			ck_u(edge[i], 0);
			ck_u(edge[i], 10);
			ck_u(edge[i], 16);
			ck_s(edge[i], 0);
			ck_s(edge[i], 10);
			ck_s(edge[i], 16);
		}
	}

	/*
	 * 2. A WALK ACROSS THE WHOLE RANGE rather than a random sample:
	 *    every power of two and its two neighbours, in three bases.
	 *    The old threshold was ULLONG_MAX/2, so a sweep bounded
	 *    below 2^63 could not have failed.
	 */
	printf("2. every power of two, +/- 1, in bases 10, 16 and 8\n");
	for(i = 0; i < 64; i++){
		u = 1ULL << i;
		static const int bases[] = { 10, 16, 8 };
		int b, d;
		for(b = 0; b < 3; b++){
			base = bases[b];
			for(d = -1; d <= 1; d++){
				const char *f = base==10 ? "%llu" :
					base==16 ? "%llx" : "%llo";
				sprintf(buf, f, u + d);
				ck_u(buf, base);
				ck_s(buf, base);
			}
		}
	}

	/* 3. decimal strings of every length, to walk the loop's guard */
	printf("3. decimal strings of 1 to 25 digits\n");
	for(i = 1; i <= 25; i++){
		int j;
		for(j = 0; j < i; j++)
			buf[j] = (j == 0) ? '9' : '0' + (j % 10);
		buf[i] = 0;
		ck_u(buf, 10);
		ck_s(buf, 10);
		memmove(buf+1, buf, i+1);
		buf[0] = '-';
		ck_s(buf, 10);
	}

	printf("\n%ld checked, %ld wrong\n", checked, wrong);
	return wrong != 0;
}
