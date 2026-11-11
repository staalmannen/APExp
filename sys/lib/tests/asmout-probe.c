/*
 * asmout-probe.c -- an `__asm__' with an OUTPUT operand must not compile.
 *
 *	pcc -c asmout-probe.c	# MUST FAIL, naming the output operand
 *
 * ***THE RESULT IS WHETHER IT COMPILES, AND THE EXPECTED RESULT IS
 * `no'.***  A clean compile here is the finding.
 *
 * WHERE IT CAME FROM.  kencc has no GNU extended asm, and `cc/lex.c'
 * swallows the whole `__asm__ ( ... )' construct so the grammar never
 * sees it.  For a barrier that is a missed fence; for an asm that
 * WRITES a C object it is a wrong answer, because the object is simply
 * never assigned.  `6c -S' on the body below used to emit
 *
 *	TEXT	bswap+0(SB),0,$16
 *	MOVL	swapped_bytes+-4(SP),AX
 *	RET	,
 *
 * -- a read of an uninitialised stack slot, returned as the result,
 * with no error and only a `used and not set' warning that reads like
 * dead-code noise in a build log.
 *
 * **It was reachable because APExp defines `__x86_64__' itself**
 * (`amd64/include/ape/_apetypes.h:59'), which is right for every
 * architecture question and is also how a vendored package selects its
 * x86 inline asm.  libwebp 1.6.0 is the package that found it: its
 * `BSwap32'/`BSwap64' (`src/utils/endian_inl_utils.h') and its CPUID
 * (`src/dsp/cpu.c') are all this shape, 14 occurrences across 7
 * translation units, every one silently wrong.
 *
 * ***`asmok-probe.c' IS THE OTHER HALF AND NEITHER IS READABLE
 * ALONE.***  A compiler that rejected EVERY `__asm__' would pass this
 * file and break the tree; a compiler that rejected none would pass
 * that one and be the bug. They are two files because this one is
 * REQUIRED to fail, so anything after the error in the same file would
 * be unreported rather than cleared -- the rule this tree already has
 * for `cppelif-probe'/`cppskip-probe'.
 */

unsigned int
bswap(unsigned int x)
{
	unsigned int swapped_bytes;

	/* "=r" is a plain output operand */
	__asm__ volatile("bswap %0" : "=r"(swapped_bytes) : "0"(x));
	return swapped_bytes;
}

int
readwrite(int x)
{
	int acc = x;

	/* "+r" is read-write, and is an output too */
	__asm__ volatile("incl %0" : "+r"(acc));
	return acc;
}

void
named(int *out)
{
	/* a [symbolic] name before the constraint must not hide it */
	__asm__ volatile("nop" : [res]"=r"(*out) : );
}
