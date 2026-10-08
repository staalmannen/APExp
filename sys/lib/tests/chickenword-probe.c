/*
 * chickenword-probe.c -- what width did CHICKEN's tagged word get?
 *
 * FROM: `chicken compiler-test.scm' answering
 *	chicken 13344: suicide: sys: trap: fault read addr=0xfffffffffffefa6
 * and costing nothing to diagnose once asked the right way round.
 *
 * THE BUG IT EXISTS FOR.  `chicken.h:81' sets C_SIXTY_FOUR from
 * __LP64__/_LP64/__MINGW64__/_WIN64.  kencc on amd64 is LLP64 and
 * defines NONE of them -- it predefines only __STDC__, _POSIX_SOURCE
 * and the two __APEXP_* markers -- so C_SIXTY_FOUR was never set.
 * `C_LLP', which both chicken mkfiles already passed, is read for the
 * word size only INSIDE `#ifdef C_SIXTY_FOUR' (chicken.h:515), so it
 * was inert and the `#else' arm gave **C_word = int**: 32 bits, on a
 * machine whose pointers are 64, in the type CHICKEN stores pointers
 * in.
 *
 * THIS IS A PROBE AND NOT A RULE for the first three lines -- it
 * reports the configuration rather than judging the platform -- but
 * the last two checks ARE assertions, because `sizeof(C_word) ==
 * sizeof(void *)' is not a matter of taste on any target CHICKEN
 * supports: a tagged word that cannot hold a pointer cannot work.
 *
 * BUILD IT WITH THE LIBRARY'S OWN FLAGS.  Built any other way it
 * measures a different chicken.h, which is the rule `tarblock-probe'
 * records and paid for:
 *
 *   cd sys/lib/tests
 *   pcc -o chickenword-probe \
 *       -I../../src/external/chicken -DHAVE_CHICKEN_CONFIG_H \
 *       -DHAVE_ALLOCA_H -DC_SIXTY_FOUR -DC_LLP \
 *       chickenword-probe.c
 *   ./chickenword-probe
 *
 * THE CONTROL IS TO DROP -DC_SIXTY_FOUR and run it again: that is the
 * configuration the port shipped with, and it must FAIL.  A run that
 * passes with the flag says nothing on its own -- it looks identical
 * whether the flag works or the header never had the problem.
 *
 * Correct on gcc too, where __LP64__ supplies C_SIXTY_FOUR by itself,
 * so OMIT -DC_SIXTY_FOUR there or it is a redefinition warning.  That
 * asymmetry is the finding in miniature: the host needs no flag
 * precisely because its model is the one chicken.h:81 knows about.
 *
 * AND THE HOST RUNS BOTH SIDES, so this needed no VM round at all.
 * `-U__LP64__ -U_LP64' takes the markers away and reproduces kencc's
 * configuration exactly:
 *
 *   gcc -o cwp -I../../src/external/chicken -DHAVE_CHICKEN_CONFIG_H \
 *       -DHAVE_ALLOCA_H -DC_LLP chickenword-probe.c          # fixed
 *   gcc -o cwp -I../../src/external/chicken -DHAVE_CHICKEN_CONFIG_H \
 *       -DHAVE_ALLOCA_H -DC_LLP -U__LP64__ -U_LP64 \
 *       chickenword-probe.c                                  # shipped
 *
 * Measured:
 *   fixed    C_SIXTY_FOUR defined, C_word 8, 0 failures
 *   shipped  C_SIXTY_FOUR NOT defined, C_word 4, pointer 8,
 *            1 failure, exit 1
 *
 * *That pair is the whole diagnosis*, and one of the two is the build
 * that crashed.
 */

/*
 * chicken.h FIRST, and that is load-bearing rather than tidy:
 * `chicken.h:52' sets _DEFAULT_SOURCE and the other feature macros,
 * which must precede any libc header.  With <stdio.h> above it this
 * file does not compile at all -- `C_header' stops being a type and
 * gcc reports eight errors inside chicken.h, none of which mentions
 * the include order.  *The message names the victim*, as this tree's
 * `lock.h' shadow and its runaway mkfile comment both did.
 */
#include <chicken.h>
#include <stdio.h>

int
main(void)
{
	int fail = 0;

	printf("chickenword-probe\n");

	/* Section 0: the MARKER.  Which arms of chicken.h were live?
	 * Without this a wrong width and a stale object look the same,
	 * which is the `__APEXP_CONFORMALIGN__' lesson for a header. */
#ifdef C_SIXTY_FOUR
	printf("  C_SIXTY_FOUR  defined\n");
#else
	printf("  C_SIXTY_FOUR  NOT defined   <- chicken.h:81 did not fire\n");
#endif
#ifdef C_LLP
	printf("  C_LLP         defined\n");
#else
	printf("  C_LLP         NOT defined\n");
#endif
	printf("  model         %s\n",
	    (sizeof(void *) == 8 && sizeof(long) == 4) ? "LLP64" :
	    (sizeof(void *) == 8 && sizeof(long) == 8) ? "LP64"  :
	    (sizeof(void *) == 4)                      ? "32-bit" : "?");

	/* Section 1: the widths, as a PROBE. */
	printf("  sizeof(void *)  %d\n", (int)sizeof(void *));
	printf("  sizeof(long)    %d\n", (int)sizeof(long));
	printf("  sizeof(C_word)  %d\n", (int)sizeof(C_word));
	printf("  sizeof(C_hword) %d\n", (int)sizeof(C_hword));
	printf("  C_WORD_SIZE     %d\n", (int)C_WORD_SIZE);

	/* Section 2: the ASSERTION that carries the whole file.
	 * CHICKEN stores pointers in C_word; if it is narrower than a
	 * pointer every object reference is truncated, which is the
	 * garbage address the crash reported. */
	if(sizeof(C_word) != sizeof(void *)) {
		printf("FAIL C_word is %d bytes, a pointer is %d\n",
		    (int)sizeof(C_word), (int)sizeof(void *));
		fail++;
	} else
		printf("PASS C_word holds a pointer\n");

	/* Section 3: C_WORD_SIZE must agree with the type it describes.
	 * They are set in two different `#ifdef C_SIXTY_FOUR' blocks
	 * (chicken.h:348 and :514), so they can disagree -- and a macro
	 * that disagrees with its own type is how a shift or a mask goes
	 * wrong silently rather than loudly. */
	if((int)C_WORD_SIZE != (int)(sizeof(C_word) * 8)) {
		printf("FAIL C_WORD_SIZE %d against sizeof(C_word)*8 %d\n",
		    (int)C_WORD_SIZE, (int)(sizeof(C_word) * 8));
		fail++;
	} else
		printf("PASS C_WORD_SIZE agrees with C_word\n");

	printf("%d failures\n", fail);
	return fail;
}
