/*
 * leawide-test.c -- a wide constant must not become an x86-64 address
 * DISPLACEMENT.
 *
 *	pcc -o leawide-test leawide-test.c && ./leawide-test
 *	gcc -O2 -o /tmp/l leawide-test.c && /tmp/l
 *
 * ***THE THIRD MEMBER OF A FAMILY, AND THE ONE THAT TOOK LONGEST TO
 * SEE.*** x86-64 has `MOV r64, imm64' and has NO 64-bit form of:
 * a `CMP' immediate, or an address displacement.  Each time, kencc
 * emitted the wide value anyway and `6l' wrote the low half with
 * `put4' and no diagnostic.
 *
 *	MOVQ $sym+off(SB)             -- `Node.xoffset' was `long'
 *	CMPQ r,$sym+off(SB)           -- `hardconst'/`oclass'
 *	LEAQ off(base)(index*scale)   -- THIS ONE
 *
 * `6c/cgen.c:346' turns `(x << k) + C' into `genmuladd', an
 * `LEAQ C(base)(index*2^k)'.  Its test already refused a SMALL C,
 * because `ADDQ' is better for one; it never refused a WIDE C.  So
 *
 *	((u64)3 << 48) + ((n<<1)+1)
 *	  LEAQ 844424930131969(NONE)(BP*2),AX
 *
 * -- correct arithmetic, (3<<48)+1, and not an instruction.
 *
 * WHERE IT CAME FROM. clisp's `make_small_read_label(n)' is
 * `((oint)system_type << 48) + ((n<<1)+1)', that shape exactly.  The
 * displacement truncated to 1, so every `#n#' reader label came out as
 * oint 3 with its TYPE TAG GONE.  It then printed as
 * `#<ADDRESS #x000000000003>' -- `machine_type' is 0 -- rather than
 * `#<READ-LABEL 1>', `subst_circ' walked past it as `case_machine'
 * substituting nothing and reporting success, and `SET-DIFFERENCE'
 * got a literal label where a hash table belonged:
 * `GETHASH: argument #<ADDRESS #x000000000003> is not a hash table'.
 *
 * ***THE PRINTER WAS THE DISCRIMINATOR AND IT WAS NOT READ FOR FOUR
 * ROUNDS.*** `#x3' matches `make_small_read_label(1)' -- `(1<<1)+1' --
 * so the object was identified from arithmetic alone and four
 * instruments were built on it, hunting a substitution that was never
 * at fault.  One look at `pr_readlabel' (`io.d:8551') says a label
 * prints `#<READ-LABEL n>'; `#<ADDRESS ...>' is `pr_machine'.  *The
 * first instinct was right and the mechanism was not.*
 *
 * SECTIONS 4 AND 5 ARE CONTROLS AND PASS EITHER WAY: a small constant
 * fits the displacement, and an unshifted variable never reaches the
 * `genmuladd' path at all.  A test built only from those reports a
 * clean run against a broken compiler.
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long u64;

static int failed = 0;

/* volatile so that gcc -O2 cannot fold the whole thing to a constant */
static volatile u64 one = 1;

static void
ck(const char *what, u64 got, u64 want)
{
	if (got == want) {
		printf("PASS %s: 0x%llx\n", what, (unsigned long long)got);
	} else {
		printf("FAIL %s: got 0x%llx want 0x%llx\n", what,
		       (unsigned long long)got, (unsigned long long)want);
		failed++;
	}
}

/* 1. clisp's make_small_read_label(): wide constant + (n<<1) + 1 */
static u64
readlabel(u64 n)
{
	return ((u64)3 << 48) + ((n << 1) + 1);
}

/* 2. the same without the +1 */
static u64
shift1(u64 n)
{
	return ((u64)3 << 48) + (n << 1);
}

/* 3. the other two scales an LEA can encode */
static u64
shift2(u64 n)
{
	return ((u64)3 << 48) + (n << 2);
}

static u64
shift3(u64 n)
{
	return ((u64)3 << 48) + (n << 3);
}

/* 4. control: a constant that FITS the displacement */
static u64
narrow(u64 n)
{
	return (u64)0x40000000 + (n << 1);
}

/* 5. control: no shift, so no indexed address is formed */
static u64
noshift(u64 n)
{
	return ((u64)3 << 48) + n;
}

int
main(void)
{
	u64 n;

	setvbuf(stdout, (char*)0, _IOLBF, 0);
	printf("leawide-test: starting\n");

	n = one;	/* 1, opaquely */

	ck("1 read label (3<<48)+(n<<1)+1", readlabel(n),
	   ((u64)3 << 48) + 3);
	ck("2 (3<<48)+(n<<1)", shift1(n), ((u64)3 << 48) + 2);
	ck("3a (3<<48)+(n<<2)", shift2(n), ((u64)3 << 48) + 4);
	ck("3b (3<<48)+(n<<3)", shift3(n), ((u64)3 << 48) + 8);

	/* the two controls, which pass against a broken compiler too */
	ck("4 narrow constant + (n<<1)", narrow(n), (u64)0x40000000 + 2);
	ck("5 wide constant, no shift", noshift(n), ((u64)3 << 48) + 1);

	printf("leawide-test: %d failure%s\n", failed,
	       failed == 1 ? "" : "s");
	return failed;
}
