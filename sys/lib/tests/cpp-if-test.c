/*
 * cpp-if-test.c -- what can the preprocessor evaluate in #if?
 *
 * Written for one failure in particular. GNU tar's src/misc.c has
 *
 *   #if ! (INTMAX_MAX <= UINTMAX_MAX / 2)
 *   # error "sysinttostr: uintmax_t cannot represent all intmax_t values"
 *   #endif
 *
 * and the error fires here, although the assertion is true on this
 * platform: both types are 64 bit and UINTMAX_MAX / 2 is exactly
 * INTMAX_MAX. The neighbouring test in src/list.c, which is the same
 * comparison with the operands the other way round, passes.
 *
 * C99 6.10.1 requires #if arithmetic to be done in intmax_t/uintmax_t,
 * with the usual conversions -- so an unsigned operand makes the whole
 * expression unsigned. Each probe below isolates one step of that, so
 * whichever #error appears first names the primitive that is wrong.
 *
 * Build:  pcc -c cpp-if-test.c
 * Silence is a pass. Any diagnostic is the answer.
 */

#include <stdint.h>
#include <stdio.h>

/* --- 1. are the macros even here? ------------------------------- */

#ifndef INTMAX_MAX
# error "1a: INTMAX_MAX is not defined -- <stdint.h> did not arrive"
#endif
#ifndef UINTMAX_MAX
# error "1b: UINTMAX_MAX is not defined -- <stdint.h> did not arrive"
#endif

/* An undefined name is 0 in #if, so 1a and 1b passing does not prove
   the values are right. These do. */
#if INTMAX_MAX == 0
# error "1c: INTMAX_MAX evaluates to 0 -- it is not expanding"
#endif
#if UINTMAX_MAX == 0
# error "1d: UINTMAX_MAX evaluates to 0 -- it is not expanding"
#endif

/* --- 2. is a big unsigned constant read as unsigned? ------------- */

/* If the U suffix is ignored, this is -1 and compares less than zero. */
#if UINTMAX_MAX < 0
# error "2a: UINTMAX_MAX is negative -- the U suffix is being dropped"
#endif
#if 0xffffffffffffffffULL < 0
# error "2b: a literal 0xffffffffffffffffULL is negative in #if"
#endif
#if 18446744073709551615ULL < 0
# error "2c: the same value in decimal is negative in #if"
#endif

/* --- 3. is division unsigned when an operand is? ----------------- */

/* Signed, this is -1/2 == 0. Unsigned, it is INTMAX_MAX. */
#if UINTMAX_MAX / 2 == 0
# error "3a: UINTMAX_MAX / 2 is 0 -- division is signed"
#endif
#if ! (UINTMAX_MAX / 2 == INTMAX_MAX)
# error "3b: UINTMAX_MAX / 2 is neither 0 nor INTMAX_MAX"
#endif

/* --- 4. the two orderings, which is where tar differs ------------ */

#if ! (UINTMAX_MAX / 2 <= INTMAX_MAX)
# error "4a: list.c ordering fails (unsigned <= signed)"
#endif
#if ! (INTMAX_MAX <= UINTMAX_MAX / 2)
# error "4b: misc.c ordering fails (signed <= unsigned) -- THIS IS THE ONE"
#endif

/* Same two comparisons without the division, to tell a division fault
   from a comparison fault. */
#if ! (INTMAX_MAX <= UINTMAX_MAX)
# error "4c: signed <= unsigned fails even without a division"
#endif
#if ! (UINTMAX_MAX >= INTMAX_MAX)
# error "4d: unsigned >= signed fails even without a division"
#endif

/* --- 5. the rest of tar's assertions ----------------------------- */

#if ! (INTMAX_MAX <= UINTMAX_MAX && - (INTMAX_MIN + 1) <= UINTMAX_MAX)
# error "5a: list.c:744 fails"
#endif
#if ! (UINTMAX_MAX / 2 <= INTMAX_MAX)
# error "5b: list.c:748 fails"
#endif

/* --- 6. the same facts at compile time -------------------------- */

/* If these hold but a #if above did not, the defect is in cpp's #if
   evaluator alone, not in the values <stdint.h> gives. */
static int check[(INTMAX_MAX <= UINTMAX_MAX / 2) ? 1 : -1];

int
main(void)
{
	printf("INTMAX_MAX      = %lld\n", (long long)INTMAX_MAX);
	printf("UINTMAX_MAX     = %llu\n", (unsigned long long)UINTMAX_MAX);
	printf("UINTMAX_MAX / 2 = %llu\n", (unsigned long long)UINTMAX_MAX / 2);
	printf("INTMAX_MIN      = %lld\n", (long long)INTMAX_MIN);
	(void)check;
	return 0;
}
