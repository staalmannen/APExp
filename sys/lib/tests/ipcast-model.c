/*
 * ipcast-model.c -- what does intparam.c's pointer-cast test answer
 * when `ulong' is NARROWER than a pointer?
 *
 *	gcc -w -o ipcast-model ipcast-model.c && ./ipcast-model
 *
 * ***A MODEL, NOT A TEST.***  It runs on the BUILD HOST and transcribes
 * `sys/src/external/clisp/src/intparam.c's `test_pointer_casts' macro
 * (intparam.c:439-469) with kencc's widths forced: `ulong' 32 bits,
 * pointers 64.  *The host cannot be asked directly* -- glibc's `ulong'
 * is 64-bit, so a host run of the real `intparam.c' reproduces nothing
 * about this -- and the real one cannot run here, which is the
 * condition this tree keeps a model for.
 *
 * WHERE THE QUESTION CAME FROM.  The first native run of clisp's
 * replacement `configure:V:' compiled and ran both probes and mk did
 * not stop, but it printed EIGHT of
 *
 *	intparam.c:470 conversion of pointer to shorter integer
 *	intparam.c:471 conversion of pointer to shorter integer
 *
 * and lines 470 and 471 are the two `test_pointer_casts' calls.  That
 * macro round-trips a pointer through `ulong' and emits
 * `#error "Casts from %s to %s modify part 0x%8lX of pointer!!"' into
 * `intparam.h' if any bit differs.  **A poisoned `intparam.h' would
 * fail the build much later, naming a generated file and not this
 * mechanism**, so the question was whether the truncation makes the
 * test report a difference.
 *
 * ***THE ANSWER IS NO, AND THE REASON IS THAT THE TEST IS VACUOUS.***
 * `sample' is a `ulong', so it only ever holds 32 bits; both pointers
 * are built from it and both sides of the XOR truncate back to 32, so
 * `differences1' and `differences2' are 0 and the macro prints its
 * "OK (does nothing)" comment.  The output is CORRECT and the warning
 * is benign -- *but the high half of a pointer is never exercised*, so
 * on an LLP64 target this is a check that cannot fail.  It would not
 * notice a cast that really did lose the top 32 bits.
 *
 * **That is a note about upstream's instrument, not a bug in clisp or
 * in kencc**, and it is written down here because the next LLP64 probe
 * in the next package will have the same shape: a measurement whose
 * accumulator is narrower than the thing measured reads as a clean
 * pass.  `pointer_bitsize' is computed separately
 * (`char_bitsize * sizeof(char*)', intparam.c:432) and is 64, which is
 * the value clisp actually keys on and it is right.
 *
 * Expected output: both lines `no #error emitted', pointer_bitsize 64.
 * If either line ever says `#error WOULD BE EMITTED', the generated
 * `intparam.h' is poisoned and that is the thing to read.
 */

#include <stdio.h>
#include <stdint.h>

typedef uint32_t ulong32;          /* kencc's `ulong' on every target */
typedef void function(void);

static ulong32
rnd(void)
{
	static ulong32 s = 12345;
	s = s * 1103515245u + 12345u;
	return s;
}

/* intparam.c:439, with the casts routed through uintptr_t so that the
   host compiles what kencc would do rather than refusing it. */
#define test_pointer_casts(type1, type2, typestr1, typestr2)            \
  if (sizeof(type1) != sizeof(type2)) {                                 \
    printf("#error \"Pointer types %s and %s have different sizes!!\"\n", \
           typestr1, typestr2);                                         \
  } else {                                                              \
    int i;                                                              \
    ulong32 differences1 = 0, differences2 = 0;                         \
    for (i = 0; i < 100; i++) {                                         \
      ulong32 sample;                                                   \
      type1 sample1;                                                    \
      type2 sample2;                                                    \
      sample = rnd();                                                   \
      sample1 = (type1)(uintptr_t)sample;                               \
      sample2 = (type2)(uintptr_t)sample;                               \
      differences1 |= ((ulong32)(uintptr_t)sample1                      \
                       ^ (ulong32)(uintptr_t)(type1)(sample2));         \
      differences2 |= ((ulong32)(uintptr_t)sample2                      \
                       ^ (ulong32)(uintptr_t)(type2)(sample1));         \
    }                                                                   \
    printf("  %-22s differences1=0x%08X differences2=0x%08X  %s\n",     \
           typestr1, differences1, differences2,                        \
           (differences1 == 0 && differences2 == 0)                     \
             ? "no #error emitted" : "#error WOULD BE EMITTED");        \
  }

int
main(void)
{
	printf("ipcast-model: pointer %zu bits, ulong %d bits (kencc's widths)\n",
	       sizeof(char *) * 8, 32);
	test_pointer_casts(char *, long *, "char * / long *", "long *");
	test_pointer_casts(char *, function *, "char * / function *", "function *");
	printf("  pointer_bitsize would be %ld (intparam.c:432, the value\n",
	       (long)(8 * sizeof(char *)));
	printf("  clisp keys on -- computed separately and not affected)\n");
	printf("\nthe test cannot fail on LLP64: `sample' is a ulong, so the\n");
	printf("high 32 bits of a pointer are never exercised.\n");
	return 0;
}
