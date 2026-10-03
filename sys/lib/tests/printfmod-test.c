/*
 * printfmod-test -- does printf honour the C99 LENGTH MODIFIERS?
 *
 *	pcc -o printfmod-test printfmod-test.c && ./printfmod-test
 *
 * On the host, where there is no libap to mark:
 *
 *	gcc -Wall -o /tmp/printfmod-test printfmod-test.c \
 *	    -xc <(echo 'int _printfmark(void){return 1;}')
 *	/tmp/printfmod-test
 *
 * (0 failures on glibc.)
 *
 * ------------------------------------------------------------------
 * THE BUG, AND WHY NOBODY SAW A WRONG NUMBER.
 *
 * `vfprintf.c' had a table of length modifiers with `h', `l', `L' and
 * `z' in it, and **no `t' (ptrdiff_t), no `j' (intmax_t), and no
 * second-`h' rule for `hh' (char).** An unrecognised conversion falls
 * through to the arm that prints the character and moves on **without
 * consuming an argument**, so
 *
 *	printf("%td", n)
 *
 * did not print a wrong number. It printed the literal text `td', and
 * left `n' in the va_list -- so **every conversion after it in the same
 * format string took the wrong argument.** A `%s' after a `%td' reads a
 * string from an integer.
 *
 * Found through bash's test suite, in the one place where the damage
 * was arithmetically decodable. GNU diffutils prints every line number
 * through `#define pI "t"' and
 *
 *	fprintf(outfile, "%"pI"d%c%"pI"d", trans_a, sepchar, trans_b)
 *
 * so EVERY position line of EVERY diff on this system was garbage:
 * `1,2d0' came out as `td\x01tddtd' -- `td' per number, and the `%c'
 * taking `trans_a' (1) rather than the comma, hence chr(1). Three
 * separate hunks in that log decode to their own first line numbers,
 * which is what identified the mechanism rather than merely the fault.
 *
 * ~370 literal uses of these three modifiers sit in coreutils, gnulib,
 * diffutils, patch, bison, tar, flex, pcre2, grep and sed. **`z' was
 * the one that worked**, which is why size_t printing never misled
 * anyone; and **the PRI* macros dodge it**, because APE's <inttypes.h>
 * spells PRIdMAX as "lld" rather than "jd".
 *
 * ------------------------------------------------------------------
 * SECTIONS 1-3 ARE THE BUG. SECTION 4 IS THE CONTROL AND IS THE POINT:
 * it checks that the conversion CONSUMED ITS ARGUMENT, by putting a
 * second conversion after it and asking what that one printed. An
 * implementation that printed the number correctly but ate no argument
 * -- or ate two -- passes 1-3 and fails 4. That is the half that did
 * the real damage, and asking only "is the number right" would have
 * measured the harmless half.
 *
 * Section 6 is the second control: `%z' must not REGRESS. It was the
 * one modifier that already worked, so a fix that rebuilt the table
 * wrongly would show up here and nowhere else.
 */

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>

extern int _printfmark(void);

static int failures;

static void
eq(const char *got, const char *want, const char *what)
{
	int ok = strcmp(got, want) == 0;
	printf("%s: %-46s got \"%s\"", ok ? "PASS" : "FAIL", what, got);
	if(!ok)
		printf("  want \"%s\"", want);
	printf("\n");
	if(!ok)
		failures++;
}

int
main(void)
{
	char b[256];
	ptrdiff_t t = 12345;
	intmax_t j = -9876543210LL;
	uintmax_t u = 18000000000ULL;
	size_t z = 4242;

	printf("printfmod-test\n");
	printf("_printfmark = %d  (1 = t/j/hh; 2 = %%F, %%g.0, 0-flag)\n",
		_printfmark());
	if(_printfmark() < 2){
		printf("FAIL: libap predates the %%F fix -- sections 7-9 "
			"below measure the OLD library\n");
		failures++;
	}
	printf("\n");

	/* 1. t -- ptrdiff_t. This is diffutils' pI. */
	printf("1. %%td / %%ti / %%tx  (ptrdiff_t)\n");
	sprintf(b, "%td", t);		eq(b, "12345", "%td");
	sprintf(b, "%ti", t);		eq(b, "12345", "%ti");
	sprintf(b, "%tx", t);		eq(b, "3039", "%tx");
	sprintf(b, "%td", (ptrdiff_t)-7);	eq(b, "-7", "%td negative");
	printf("\n");

	/* 2. j -- intmax_t. Must be 64-bit: kencc's long is 32. */
	printf("2. %%jd / %%ju  (intmax_t, must be 64-bit)\n");
	sprintf(b, "%jd", j);		eq(b, "-9876543210", "%jd");
	sprintf(b, "%ju", u);		eq(b, "18000000000", "%ju");
	printf("\n");

	/* 3. hh -- char. Truncation is the whole content of this one. */
	printf("3. %%hhd / %%hhu / %%hhx  (char; TRUNCATION is the test)\n");
	sprintf(b, "%hhu", 300);	eq(b, "44", "%hhu of 300 truncates");
	sprintf(b, "%hhd", -1);		eq(b, "-1", "%hhd of -1");
	sprintf(b, "%hhd", 200);	eq(b, "-56", "%hhd of 200 is signed");
	sprintf(b, "%hhx", 0x1234);	eq(b, "34", "%hhx of 0x1234");
	printf("\n");

	/*
	 * 4. THE CONTROL THAT MATTERS: did the conversion consume its
	 *    argument? The old code printed `td' and ate nothing, so the
	 *    NEXT conversion got the previous one's argument. Here the
	 *    second conversion is what carries the result.
	 */
	printf("4. ARGUMENT CONSUMPTION -- the second conversion tells\n");
	sprintf(b, "%td,%d", t, 77);	eq(b, "12345,77", "%td then %d");
	sprintf(b, "%jd,%d", (intmax_t)5, 77);	eq(b, "5,77", "%jd then %d");
	sprintf(b, "%hhd,%d", 5, 77);	eq(b, "5,77", "%hhd then %d");
	sprintf(b, "%td,%s", t, "end");	eq(b, "12345,end", "%td then %s");
	printf("\n");

	/*
	 * 5. diffutils' own format, verbatim. This is the line that was
	 *    coming out as `td\x01tddtd' in every diff on this system.
	 */
	printf("5. diffutils' position line, verbatim\n");
	sprintf(b, "%td%c%td", (ptrdiff_t)1, ',', (ptrdiff_t)2);
	eq(b, "1,2", "\"%td%c%td\", 1, ',', 2");
	sprintf(b, "%td%c%tdd%td", (ptrdiff_t)1, ',', (ptrdiff_t)2,
		(ptrdiff_t)0);
	eq(b, "1,2d0", "a whole `1,2d0' hunk header");
	printf("\n");

	/* 6. THE REGRESSION CONTROL: z already worked. */
	printf("6. %%zu must NOT regress -- it was the one that worked\n");
	sprintf(b, "%zu", z);		eq(b, "4242", "%zu");
	sprintf(b, "%zu,%d", z, 77);	eq(b, "4242,77", "%zu then %d");
	sprintf(b, "%lld", 9876543210LL);	eq(b, "9876543210", "%lld");
	sprintf(b, "%hd", (int)-5);	eq(b, "-5", "%hd");
	printf("\n");

	/*
	 * 7. %F. It was ABSENT from the dispatch table, which is the
	 *    `%td' bug again: the letter prints and no argument is
	 *    consumed. bash's printf.tests lines 320/325 are exactly
	 *    `printf "%F\n" 0' and `printf "%F\n" 4', and this tree
	 *    answered `F'. The second line of each pair is the
	 *    consumption control, for the same reason as section 4.
	 */
	printf("7. %%F  (it did not exist; `F' was printed and nothing eaten)\n");
	sprintf(b, "%F", 0.0);		eq(b, "0.000000", "%F of 0");
	sprintf(b, "%.2F", 0.0);	eq(b, "0.00", "%.2F of 0");
	sprintf(b, "%F", 4.0);		eq(b, "4.000000", "%F of 4");
	sprintf(b, "%.2F", 4.0);	eq(b, "4.00", "%.2F of 4");
	sprintf(b, "%F,%d", 1.5, 77);	eq(b, "1.500000,77", "%F then %d");
	printf("\n");

	/*
	 * 8. The two flag rules, both from bash's printf4.sub. Each is
	 *    a case where a PRESENT conversion formatted wrongly, so
	 *    unlike section 7 the damage stops at one value.
	 */
	printf("8. %%g with precision 0, and the 0 flag with a precision\n");
	sprintf(b, "%+010.0g", 123.0);	eq(b, "+00001e+02", "%+010.0g (0 means 1)");
	sprintf(b, "%.0g", 123.0);	eq(b, "1e+02", "%.0g");
	sprintf(b, "%+010.0d", 123);	eq(b, "      +123", "%+010.0d (0 ignored)");
	sprintf(b, "%+010.0x", 123);	eq(b, "        7b", "%+010.0x (0 ignored)");
	sprintf(b, "%010d", 123);	eq(b, "0000000123", "%010d still zero-pads");
	sprintf(b, "%+010.0f", 123.0);	eq(b, "+000000123", "%+010.0f DOES zero-pad");
	printf("\n");

	/*
	 * 9. PROBE, asserting nothing. bash's `printf "%08X" 2604292517'
	 *    wants `9B3A59A5' and this tree printed `FFFFFFFF9B3A59A5'
	 *    -- a 32-bit value SIGN-EXTENDED to 64 bits. bash reaches
	 *    printf with `%08lX' and an `unsigned long' (32-bit under
	 *    kencc) whenever the value fits, which this one does
	 *    (printf.def's x/X arm compares `p != pp' first).
	 *
	 *    Which side is wrong is NOT settled, so this measures
	 *    rather than asserts: it prints the same number through
	 *    four widths. If `%lX' alone is wrong, it is libap's
	 *    va_arg; if `%X' is wrong too, it is the caller's promotion.
	 *    A negative `int' is printed beside them because that is
	 *    the only thing that could produce those eight F's.
	 */
	printf("9. PROBE (no assertion): %%X and the width of its argument\n");
	{
		unsigned long ul = 2604292517UL;
		unsigned int ui = 2604292517U;

		printf("   sizeof(long)=%d  sizeof(void*)=%d\n",
			(int)sizeof(long), (int)sizeof(void *));
		sprintf(b, "%08X", ui);	 printf("   %%08X  of unsigned int  -> %s\n", b);
		sprintf(b, "%08lX", ul); printf("   %%08lX of unsigned long -> %s\n", b);
		sprintf(b, "%08llX", (unsigned long long)ul);
		                         printf("   %%08llX of ull          -> %s\n", b);
		sprintf(b, "%08X", -1);	 printf("   %%08X  of (int)-1       -> %s\n", b);
		printf("   all four should end 9B3A59A5 except the last "
			"(FFFFFFFF)\n");
	}
	printf("\n");

	printf("%d failures\n", failures);
	return failures;
}
