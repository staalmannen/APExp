/*
 * switchcase-test.c -- a 64-bit case TYPE is not a 64-bit case VALUE.
 *
 * FROM: rebuilding CHICKEN, where `pcc' answered
 *
 *   runtime.c:12525 duplicate cases in switch 0        (x4)
 *
 * on `decode_literal2''s first switch -- **naming a case the program
 * does not contain**, four times, after the `L'-suffix fix had
 * already cleared the second switch in the same function.
 *
 * TWO BUGS IN `cc/pswt.c', and only the second was audible.
 *
 * (1) THE SILENT ONE.  `pgen.c:342' sets a case's `isv' from
 *     `typev[type]' -- the TYPE alone -- and `doswit' then dropped
 *     every `isv' case in a switch whose expression is 32 bits, under
 *     the comment "can never match".  That sentence is about a VALUE
 *     too wide to appear; it was being applied to a small number that
 *     merely has a wide type.  `chicken.h' writes every immediate as
 *     `((C_word)(C_SPECIAL_BITS | 0x10))' and `C_word' is 64 bits
 *     here, so four of that switch's labels are 0x0e, 0x1e, 0x3e and
 *     0x4e wearing `int64_t' -- **discarded, and the switch would
 *     have fallen to `default' for all four at run time.**
 *
 * (2) THE LOUD ONE, and it is what made (1) visible at all.  `nc' was
 *     the number of non-default cases, counted BEFORE that loop
 *     dropped any, and `alloc()' is a hunk bump allocator that does
 *     not zero.  So `qsort' and the duplicate scan ran over `nc'
 *     entries of which the last few had never been written, and
 *     reported those against each other.  **Five dropped labels gave
 *     exactly four duplicate reports, all of value 0**, which is the
 *     arithmetic in the message.
 *
 * SECTION 2 IS THE ONE THAT MATTERS and it is why this file exists
 * rather than a note.  A compiler with (2) fixed and (1) left alone
 * COMPILES CLEANLY and selects the wrong arm -- so the error going
 * away is not evidence, and only asking which arm ran can tell the
 * two apart.  Section 1 is the loud half; if the compiler still has
 * (2) this file does not build, which is its own answer.
 *
 *   cd sys/lib/tests && pcc -o switchcase-test switchcase-test.c
 *   ./switchcase-test
 *
 * CHECKED ON gcc FIRST -- 0 failures -- AND WHAT THAT IS WORTH IS
 * NARROW.  On the host `long' is 64 bits, so `(long long)14' and
 * `14' have the same width and neither bug can arise; the gcc run
 * says the test is written correctly and nothing more.  Section 0
 * prints `sizeof(long)' so the two runs tell themselves apart.
 */

#include <stdio.h>

/* chicken.h's own shape: a small immediate behind a 64-bit cast. */
#define SPECIAL_BITS  0x0000000e
#define EOL           ((long long)(SPECIAL_BITS | 0x00000000))
#define UNDEF         ((long long)(SPECIAL_BITS | 0x00000010))
#define EOF_OBJ       ((long long)(SPECIAL_BITS | 0x00000030))
#define BROKEN        ((long long)(SPECIAL_BITS | 0x00000040))

static int
which(int c)
{
	/*
	 * The switch EXPRESSION is a plain int -- that is the whole
	 * condition for both bugs -- while six of the eight labels
	 * carry a 64-bit type.
	 */
	switch(c) {
	case 6:                 return 1;        /* plain int label */
	case 0x0a:              return 2;        /* plain int label */
	case EOL:               return 3;        /* 64-bit type, 0x0e */
	case UNDEF:             return 4;        /* 64-bit type, 0x1e */
	case EOF_OBJ:           return 5;        /* 64-bit type, 0x3e */
	case BROKEN:            return 6;        /* 64-bit type, 0x4e */
	case 1:                 return 7;        /* plain int label */
	/* chicken's own, a shift of two 64-bit constants back down */
	case (int)((((0x0200000000000000LL | 0x4000000000000000LL)
	             | 0x8000000000000000ULL) >> (24 + 32)) & 0xff):
		                return 8;        /* 0xc2 */
	default:                return 0;
	}
}

int
main(void)
{
	int fail = 0;
	int i, got, want;

	/* name, input, expected arm */
	static const struct { const char *nm; int in; int want; } t[] = {
		{ "2a int label 6",        6,     1 },
		{ "2b int label 0x0a",     0x0a,  2 },
		{ "2c wide label 0x0e",    0x0e,  3 },
		{ "2d wide label 0x1e",    0x1e,  4 },
		{ "2e wide label 0x3e",    0x3e,  5 },
		{ "2f wide label 0x4e",    0x4e,  6 },
		{ "2g int label 1",        1,     7 },
		{ "2h wide label 0xc2",    0xc2,  8 },
		{ "2i default",            0x55,  0 },
	};

	printf("switchcase-test\n");

	/* Section 0: which machine is this?  A PROBE. */
	printf("  sizeof(int)       %d\n", (int)sizeof(int));
	printf("  sizeof(long)      %d\n", (int)sizeof(long));
	printf("  sizeof(long long) %d\n", (int)sizeof(long long));

	/* Section 1: the loud half.  Reaching this line at all means
	 * the file compiled, i.e. no case the program does not
	 * contain was reported as a duplicate. */
	printf("PASS 1a compiled without a spurious duplicate case\n");

	/* Section 2: the SILENT half -- does each arm actually run? */
	for(i = 0; i < (int)(sizeof t / sizeof t[0]); i++) {
		got = which(t[i].in);
		want = t[i].want;
		if(got != want) {
			printf("FAIL %s: 0x%x chose arm %d, want %d\n",
			    t[i].nm, t[i].in, got, want);
			fail++;
		} else
			printf("PASS %s -> arm %d\n", t[i].nm, got);
	}

	/* Section 3: a label too WIDE for the switch expression, which
	 * is the case the old code thought it was handling.  C
	 * 6.8.4.2p5 says the label "is converted to the promoted type
	 * of the controlling expression", so it is TRUNCATED rather
	 * than discarded: 0x100000001LL becomes 1 and is reached by
	 * 1, not by 0x100000001.
	 *
	 * MY FIRST VERSION OF THIS SECTION ASSERTED THE OPPOSITE --
	 * that such a label can never be selected -- and gcc refused
	 * to compile it, because `case 0x100000000LL:' truncates onto
	 * the `case 0:' above it and is a genuine duplicate. *The
	 * host run is what turned a recollection into the rule*, and
	 * it is the second time in this round that checking against
	 * gcc first changed what the fix should be. */
	{
		int n;
		int r[3], k;

		for(k = 0; k < 3; k++) {
			n = (k == 0) ? 0 : (k == 1) ? 1 : 7;
			switch(n) {
			case 0:              r[k] = 100; break;
			case 0x100000001LL:  r[k] = 200; break;
			default:             r[k] = 300; break;
			}
		}
		if(r[0] != 100 || r[1] != 200 || r[2] != 300) {
			printf("FAIL 3a wide label: 0->%d 1->%d 7->%d,"
			    " want 100 200 300\n", r[0], r[1], r[2]);
			fail++;
		} else
			printf("PASS 3a wide label truncates to 1 and is"
			    " selected by 1\n");
	}

	printf("%d failures\n", fail);
	return fail;
}
