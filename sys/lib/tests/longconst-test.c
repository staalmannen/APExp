/*
 * longconst-test.c -- does a single `L' cap a constant's width?
 *
 * FROM: rebuilding CHICKEN after `-DC_SIXTY_FOUR' was added, where
 * `pcc' answered, eight times over:
 *
 *   runtime.c:12525 duplicate cases in switch 0
 *   runtime.c:12578 duplicate cases in switch 0
 *
 * THE VALUE IN THAT MESSAGE IS THE EVIDENCE.  Not "duplicate cases"
 * on some number that happened to collide -- every label in both
 * switches had become **0**.  `chicken.h' spells its fourteen header
 * type tags `0x0n00000000000000L', one `L', correct on any LP64
 * system; kencc's `long' is 32 bits, `cc/lex.c' took the `L' as the
 * final word on the type, and `convvtox(vv, TLONG)' threw away every
 * significant bit of all fourteen.
 *
 * C99 6.4.4.1 says the opposite: a constant suffixed `l'/`L' has the
 * first of long, unsigned long, long long, unsigned long long IN
 * WHICH ITS VALUE CAN BE REPRESENTED.  **`L' is a floor on the type,
 * not a ceiling.**  The widening path in `lex.c' was guarded by
 * `(c1 & Numlong) == 0', so it ran only for constants with no suffix
 * at all; the guard is gone and the threshold is the same, since
 * `long' and `int' are both 32 bits here.
 *
 * THIS IS AN APE TEST AND NOT A NATIVE ONE, unlike `truefalse-test',
 * because the rule is the LEXER's and both dialects share it --
 * `pcc' is `6c' -- so there is no APE macro standing in the way the
 * way `<stdbool.h>' stands in front of `true'/`false'.
 *
 *   cd sys/lib/tests && pcc -o longconst-test longconst-test.c
 *   ./longconst-test
 *
 * CHECKED ON gcc FIRST, where it is 0 failures -- and saying what
 * that is worth matters more than the number.  On the host `long' is
 * 64 bits, so sections 1 and 2 are TRUE THERE FOR A DIFFERENT
 * REASON: nothing has to widen because nothing overflows.  **The gcc
 * run says the test is written correctly; only 9front can say the
 * compiler is fixed.**  Section 0 prints `sizeof(long)' so a reader
 * can tell the two runs apart without being told which machine
 * produced the output.
 *
 * AND SECTION 3 IS THE CONTROL that keeps the fix from being a
 * blunt "widen everything": `0x80000000L' must stay 32 bits, because
 * unsigned long CAN represent it and C99 picks the first type that
 * can.  A patch that widened on the first `L' passes 1 and 2 and
 * fails here.
 */

#include <stdio.h>

int
main(void)
{
	int fail = 0;

	printf("longconst-test\n");

	/* Section 0: which machine is this?  A PROBE. */
	printf("  sizeof(int)       %d\n", (int)sizeof(int));
	printf("  sizeof(long)      %d\n", (int)sizeof(long));
	printf("  sizeof(long long) %d\n", (int)sizeof(long long));
	printf("  sizeof(void *)    %d\n", (int)sizeof(void *));

	/* Section 1: the exact constants chicken.h uses.  A hex
	 * constant with one `L' that needs more than 32 bits. */
	if(0x0200000000000000L != 0x0200000000000000LL) {
		printf("FAIL 1a C_STRING_TYPE shape truncated\n");
		fail++;
	} else
		printf("PASS 1a 0x0200000000000000L survives\n");

	if(0x8000000000000000UL != 0x8000000000000000ULL) {
		printf("FAIL 1b sign-bit constant truncated\n");
		fail++;
	} else
		printf("PASS 1b 0x8000000000000000UL survives\n");

	/* The one the switch labels are actually built from: the type
	 * tag OR'd with the forwarding bit, shifted back down.  If any
	 * part of the expression truncated, this is not 0x82. */
	if((int)(((0x0200000000000000L | 0x4000000000000000L |
	           0x8000000000000000UL) >> (24 + 32)) & 0xff) != 0xc2) {
		printf("FAIL 1c decoded switch label is %d, want %d\n",
		    (int)(((0x0200000000000000L | 0x4000000000000000L |
		            0x8000000000000000UL) >> (24 + 32)) & 0xff), 0xc2);
		fail++;
	} else
		printf("PASS 1c switch label decodes to 0xc2\n");

	/* Section 2: a DECIMAL constant with one `L'.  C99 gives a
	 * decimal constant only the SIGNED candidates, so this one has
	 * nowhere to go but long long. */
	if(4000000000000L != 4000000000000LL) {
		printf("FAIL 2a decimal 4e12 with L truncated\n");
		fail++;
	} else
		printf("PASS 2a 4000000000000L survives\n");

	/* Section 3: THE CONTROL.  `L' is a floor, not an order to
	 * widen: unsigned long holds 0x80000000, so the type stops
	 * there and the value is positive either way. */
	if(sizeof(0x80000000L) != sizeof(long)) {
		printf("FAIL 3a 0x80000000L widened past long\n");
		fail++;
	} else
		printf("PASS 3a 0x80000000L stays long-sized\n");

	if(0x80000000L <= 0) {
		printf("FAIL 3b 0x80000000L is not positive\n");
		fail++;
	} else
		printf("PASS 3b 0x80000000L is positive\n");

	printf("%d failures\n", fail);
	return fail;
}
