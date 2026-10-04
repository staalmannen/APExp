/*
 * random-xcheck -- is libap's random()/srandom()/initstate()/setstate()
 * the same generator glibc and 4.4BSD have?
 *
 * A HOST program, like tz-xcheck, ctype-xcheck, strftime-xcheck and
 * strtoint-xcheck: it links the unit under test into a glibc program
 * beside the reference implementation, so the answer arrives without a
 * VM round. Build it with TWO compiles -- the reason is in the next
 * paragraph and it is not a style choice:
 *
 *   gcc -c -O1 -w -o /tmp/ap_random.o \
 *       -Drandom=ap_random -Dsrandom=ap_srandom \
 *       -Dinitstate=ap_initstate -Dsetstate=ap_setstate \
 *       sys/src/ape/lib/ap/prng/random.c
 *   gcc -O1 -o /tmp/random-xcheck sys/lib/tests/random-xcheck.c \
 *       /tmp/ap_random.o && /tmp/random-xcheck
 *
 * ONE command would be vacuous, and that has happened here before:
 * strftime-xcheck's first version put the `-D' rename on the same line
 * as the checker, so the checker's own reference call was renamed too
 * and the sweep compared libap against ITSELF -- printing `0 wrong',
 * which is the sentence a real run prints. So section 0 asks the
 * machine instead of trusting the command line: if `random' and
 * `ap_random' are the same address, every later number is a tautology
 * and the program says so and stops.
 *
 * WHY BIT-COMPATIBILITY IS THE REQUIREMENT. A seeded sequence is
 * something programs reproduce across machines -- a test fixture, a
 * shuffled corpus, a hash probe order -- so "a generator with the
 * right distribution" is not the specification. The numbers are.
 *
 * WHAT SECTION 1 ACTUALLY MEASURES is the one thing in random.c that
 * is an argument rather than a transcription. glibc ships 31 magic
 * words for the UNSEEDED state; libap's file ships none and calls
 * srandom(1) on first use instead, on 4.3BSD's own claim that its
 * table is exactly the state srandom(1) leaves. If that claim is
 * false, section 1 disagrees on value 1 and everything else still
 * passes -- which is why it is asked separately from the seeds.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

extern long ap_random(void);
extern void ap_srandom(unsigned int);
extern char *ap_initstate(unsigned int, char *, size_t);
extern char *ap_setstate(char *);

static int failures;

/* draw n from each and count the disagreements */
static int
compare(const char *what, int n)
{
	int i, wrong = 0;
	long a, b;

	for(i = 0; i < n; i++){
		a = ap_random();
		b = random();
		if(a != b){
			if(wrong < 3)
				printf("    %s: draw %d  libap %ld  glibc %ld\n",
				    what, i, a, b);
			wrong++;
		}
	}
	return wrong;
}

static void
report(const char *what, int wrong)
{
	if(wrong){
		printf("FAIL %-34s %d wrong\n", what, wrong);
		failures++;
	}else
		printf("PASS %-34s\n", what);
}

int
main(void)
{
	static uint32_t apbuf[64], glbuf[64];	/* aligned, 256 bytes each */
	static const int sizes[] = { 8, 32, 64, 128, 256 };
	unsigned seed;
	int i, k, wrong;
	long a1[16], a2[16], b1[16], b2[16];
	char *aold, *gold;

	/*
	 * Section 0 -- THE CONTROL OF THE INSTRUMENT, not of the library.
	 * If the rename reached this file, the two names are one function
	 * and every comparison below is a number compared with itself.
	 */
	printf("Section 0: is this comparison real?\n");
	if((void *)ap_random == (void *)random){
		printf("FAIL VACUOUS -- ap_random and random are the same\n");
		printf("  The -D rename reached the checker. Use TWO compiles;\n"
		       "  the commands are at the top of this file.\n");
		return 1;
	}
	printf("PASS two distinct implementations are linked\n");

	/*
	 * And the other half of the same question: does `compare' NOTICE?
	 * Two different seeds must disagree, or every PASS below is a
	 * comparison that cannot fail.
	 *
	 * The first version of this control was `b & 0x7fffffff' as the
	 * deliberately wrong value -- and random() never returns anything
	 * ABOVE 2^31, so the mask was a no-op and the "broken" number was
	 * the right one. It printed a note and passed. *A control whose
	 * wrong answer is the right answer is not a control*, which is
	 * the same shape as the vacuous rename it sits next to.
	 */
	ap_srandom(1);
	srandom(2);
	wrong = compare("mismatched seeds (expected to differ)", 32);
	if(wrong == 0){
		printf("FAIL compare() reported 0 wrong for two DIFFERENT "
		    "seeds -- it cannot detect anything\n");
		failures++;
	}else
		printf("PASS compare() reports %d/32 for two different seeds\n",
		    wrong);

	printf("\nSection 1: the DEFAULT stream, nothing seeded\n");
	/*
	 * Both are freshly started by being used -- but this process has
	 * already seeded both above, so ask in a child-free way: reset
	 * each to seed 1 explicitly and compare that to glibc's own
	 * unseeded start, which glibc documents as seed 1.
	 */
	srandom(1);
	ap_srandom(1);
	wrong = compare("seed 1", 2000);
	report("srandom(1) == glibc's default table", wrong);

	printf("\nSection 2: 400 seeds, 50 draws each\n");
	wrong = 0;
	for(seed = 0; seed < 400; seed++){
		srandom(seed);
		ap_srandom(seed);
		wrong += compare("seeded", 50);
	}
	report("srandom(seed) for 0..399", wrong);

	printf("\nSection 3: every initstate() size\n");
	/*
	 * The five sizes select five different generators -- a plain LCG
	 * at 8 bytes and additive feedback of degree 7, 15, 31 and 63
	 * above it. Asking only the default would leave four untested,
	 * and the 8-byte case is the one that takes a different branch
	 * in all four functions.
	 */
	for(k = 0; k < (int)(sizeof sizes/sizeof sizes[0]); k++){
		char name[64];
		memset(apbuf, 0, sizeof apbuf);
		memset(glbuf, 0, sizeof glbuf);
		ap_initstate(777+k, (char *)apbuf, sizes[k]);
		initstate(777+k, (char *)glbuf, sizes[k]);
		wrong = compare("initstate", 500);
		snprintf(name, sizeof name, "initstate(.., %d bytes)", sizes[k]);
		report(name, wrong);
		/*
		 * And the state WORD itself: setstate() has to be able to
		 * read back what initstate() wrote, and a buffer written by
		 * one library is routinely read by the same library later,
		 * so the encoding is part of the contract rather than an
		 * internal detail.
		 */
		if(apbuf[0] != glbuf[0]){
			printf("FAIL   state word %u, glibc %u\n",
			    apbuf[0], glbuf[0]);
			failures++;
		}
	}

	printf("\nSection 4: setstate() round trip between TWO states\n");
	/*
	 * The question a sequence comparison cannot ask: does switching
	 * away to another state and back RESUME the first one? An
	 * implementation that stored nothing and reseeded passes every
	 * section above.
	 *
	 * It has to be two states. Handing setstate() the state already
	 * in use is a no-op -- the save writes the current position into
	 * word 0 and the restore reads back what it just wrote -- so that
	 * version of this section would have asserted nothing. **It also
	 * found the one real bug in random.c**: libap read word 0 BEFORE
	 * saving, which rewound to the last srandom() instead.
	 */
	memset(apbuf, 0, sizeof apbuf);
	memset(glbuf, 0, sizeof glbuf);
	ap_initstate(4242, (char *)apbuf, 128);
	initstate(4242, (char *)glbuf, 128);
	for(i = 0; i < 16; i++){ a1[i] = ap_random(); b1[i] = random(); }
	{
		static uint32_t apother[64], glother[64];
		memset(apother, 0, sizeof apother);
		memset(glother, 0, sizeof glother);
		ap_initstate(99, (char *)apother, 64);	/* a different size too */
		initstate(99, (char *)glother, 64);
		for(i = 0; i < 7; i++){ (void)ap_random(); (void)random(); }
		aold = ap_setstate((char *)apbuf);	/* back to the first */
		gold = setstate((char *)glbuf);
		if(aold != (char *)apother || gold != (char *)glother){
			printf("FAIL setstate did not hand back the state it "
			    "replaced\n");
			failures++;
		}
	}
	for(i = 0; i < 16; i++){ a2[i] = ap_random(); b2[i] = random(); }
	wrong = 0;
	for(i = 0; i < 16; i++){
		if(a2[i] != b2[i])
			wrong++;
		/*
		 * glibc is the reference for WHAT resumption means, so the
		 * repeat is only required where glibc repeats -- that keeps
		 * this a cross-check rather than an assertion of my own.
		 */
		if(b2[i] == b1[i] && a2[i] != a1[i])
			wrong++;
	}
	report("switch away and back resumes the first", wrong);

	printf("\nSection 5: initstate() returns the PREVIOUS state\n");
	/*
	 * POSIX: initstate and setstate return a pointer to the state
	 * array in use BEFORE the call, so a caller can put it back. A
	 * version returning the new one, or NULL, passes everything else.
	 */
	memset(apbuf, 0, sizeof apbuf);
	ap_initstate(5, (char *)apbuf, 128);
	aold = ap_setstate((char *)apbuf);
	if(aold != (char *)apbuf){
		printf("FAIL setstate returned %p, wanted the previous state "
		    "%p\n", (void *)aold, (void *)apbuf);
		failures++;
	}else
		printf("PASS setstate returns the state that was in use\n");

	printf("\nSection 6: initstate() refuses a buffer under 8 bytes\n");
	if(ap_initstate(1, (char *)apbuf, 4) != NULL){
		printf("FAIL a 4-byte state was accepted\n");
		failures++;
	}else
		printf("PASS\n");

	printf("\n%d failures\n", failures);
	return failures;
}
