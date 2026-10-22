/*
 * bitinit-test.c -- does a STATIC initialiser of a struct with bit
 * fields write only the bytes that struct's bit fields occupy?
 *
 * WHERE THIS CAME FROM.  The first full rebuild after `sualign()'
 * learned to share a bit-field container's HEAD stopped in GNU make,
 * with eighty-odd copies of
 *
 *   (14077) DATA  function_table_init<8>+16(SB)/4,$16777216
 *   _convM2D: multiple initialization
 *
 * and `too many errors'.  Every number in that reads out exactly:
 * `struct function_table_entry' (`gmake/src/function.c:31') is a union
 * of two function pointers, a `const char *name', then `len',
 * `minimum_args' and `maximum_args' as three `unsigned char', then
 * `expand_args:1, alloc_fn:1, adds_command:1'.  The ordinary members
 * end at byte 19, so the group's `tfield' CONTAINER is the aligned
 * unit at **16** and `expand_args' sits at shift **24**, which is
 * 0x01000000 = 16777216; the stride between records is 24, the
 * struct's size.
 *
 * **THE CONTAINER IS NOT THE GROUP**, and `init1' was emitting one
 * four-byte DATA at the container.  Bytes 16, 17 and 18 belong to the
 * three `unsigned char', which have their own one-byte DATA records --
 * so the same four bytes really were written twice and `6l' was right.
 * The fix is in `cc/dcl.c's `gbitagg()': emit the group's OWN bytes,
 * one at a time.  (One byte at a time rather than one narrower record
 * because `6l/asm.c's `datblk' accepts widths 1, 2, 4 and 8 and
 * `diag's anything else -- and a group can span three bytes.)
 *
 * **THE TAIL-SHARING RULE HAD THE SAME DEFECT AND NOTHING FIRED IT**,
 * which is section 2 below: `struct{unsigned a:1; char c;}' puts `c'
 * inside the same container, so a four-byte DATA at 0 clobbers it.
 * That rule shipped three commits before this one.  *A bug needing two
 * features at once to become reachable is still one bug.*
 *
 * HOW THIS TEST WORKS, and why it is not a layout test.  Every section
 * statically initialises a struct and then reads back **every member**,
 * ordinary ones included.  That is the whole instrument:
 *   - if the compiler writes the container rather than the group, the
 *     LINK fails with `multiple initialization' and there is no binary
 *     to run -- which is the loudest possible answer;
 *   - if it writes too NARROW a span, or shifts the value wrongly, a
 *     bit field reads back wrong;
 *   - if it writes over a neighbour that had no DATA of its own (a
 *     zero-valued `char', say), that neighbour reads back wrong.
 * Nothing here asserts an offset or a size: `structalign-test.c' owns
 * that question and this one would duplicate it badly.
 *
 * SECTION 0 IS THE CONTROL and is not decoration: a struct with NO bit
 * fields at all, statically initialised and read back.  If the static
 * initialiser path is broken in general -- which a change inside
 * `init1' can certainly do -- section 0 fails too, and the run says
 * "the init path" rather than "the bit-field span".  A file in which
 * every section involves the thing under test cannot make that
 * distinction.
 *
 * Build:
 *   gcc -o bitinit-test bitinit-test.c && ./bitinit-test   # host, 0
 *   pcc -o bitinit-test bitinit-test.c && ./bitinit-test   # 9front
 *
 * Exit status is the failure count.  Plain `pcc': the conforming
 * layout is the rule the whole APE world is built under.
 */

#include <stdio.h>

static int fails;

static void
eq(const char *what, long got, long want)
{
	if (got == want)
		printf("PASS %-38s %ld\n", what, got);
	else {
		printf("FAIL %-38s %ld   want %ld\n", what, got, want);
		fails++;
	}
}

/* ---- section 0: the CONTROL -- no bit fields anywhere ---------- */
struct plain {
	void		*p;
	const char	*name;
	unsigned char	a, b, c;
};
static struct plain plain0 = { 0, "plain", 11, 22, 33 };

/* ---- section 1: GNU make's struct function_table_entry --------- */
/* function.c:31, with the two function pointers reduced to void *:
 * what matters is a union of pointer size, then a pointer, then the
 * three unsigned char, then the three one-bit fields. */
struct ftab {
	union {
		void	*func_ptr;
		void	*alloc_func_ptr;
	} fptr;
	const char	*name;
	unsigned char	len;
	unsigned char	minimum_args;
	unsigned char	maximum_args;
	unsigned int	expand_args : 1;
	unsigned int	alloc_fn : 1;
	unsigned int	adds_command : 1;
};
/* An ARRAY, because the real failure was one record per entry and a
 * wrong stride would put the second entry's DATA on top of the
 * first's. */
static struct ftab ftab0[] = {
	{ { 0 }, "abspath",  7, 1, 1, 1, 0, 0 },
	{ { 0 }, "realpath", 8, 1, 1, 1, 0, 0 },
	{ { 0 }, "shell",    5, 1, 1, 1, 1, 1 },
	{ { 0 }, "eval",     4, 1, 1, 1, 0, 0 },
};

/* ---- section 2: the TAIL-sharing shape, latent since that rule - */
struct tailshare {
	unsigned int	a : 1;
	unsigned int	b : 1;
	char		c;
	char		d;
};
static struct tailshare tail0 = { 1, 1, 'z', 'q' };

/* ---- section 3: TWO groups that share one container ------------ */
/* Both groups round DOWN to the container at offset 0, so a
 * group-boundary test written on the container OFFSET merges them --
 * and then `c's byte is emitted from the bit-field value. */
struct twogroup {
	unsigned int	a : 1;
	char		c;
	unsigned int	b : 1;
	char		d;
};
static struct twogroup two0 = { 1, 'c', 1, 'd' };

/* ---- section 4: a group spanning THREE bytes ------------------- */
/* 17 bits starting at byte 1 covers bytes 1, 2 and 3 -- a width the
 * linker has no DATA record for, which is why the emission is one
 * byte at a time rather than one narrower record. */
struct span3 {
	char		c;
	unsigned int	a : 17;
	char		d;
};
static struct span3 span0 = { 'c', 0x1ABCD, 'd' };

/* ---- section 5: ZERO-valued bit fields beside live neighbours -- */
/* A zero constant needs no DATA at all (BSS is zero), so the group's
 * emitted span shrinks to the non-zero fields.  The neighbours must
 * still be intact, and the zero fields must still read back zero. */
struct withzero {
	unsigned char	before;
	unsigned int	z1 : 4;
	unsigned int	nz : 4;
	unsigned int	z2 : 4;
	unsigned char	after;
};
static struct withzero zero0 = { 0x5a, 0, 9, 0, 0xa5 };

int
main(void)
{
	printf("bitinit-test: static initialisers of structs with bit\n");
	printf("fields -- every member is read back, ordinary ones too.\n");
	printf("A compiler that writes the CONTAINER rather than the\n");
	printf("GROUP does not link at all: `multiple initialization'.\n\n");

	printf("Section 0: CONTROL -- no bit fields in this struct\n");
	eq("plain.a", plain0.a, 11);
	eq("plain.b", plain0.b, 22);
	eq("plain.c", plain0.c, 33);
	eq("plain.name[0]", plain0.name[0], 'p');

	printf("\nSection 1: GNU make's function_table_entry\n");
	eq("ftab[0].len", ftab0[0].len, 7);
	eq("ftab[0].minimum_args", ftab0[0].minimum_args, 1);
	eq("ftab[0].maximum_args", ftab0[0].maximum_args, 1);
	eq("ftab[0].expand_args", ftab0[0].expand_args, 1);
	eq("ftab[0].alloc_fn", ftab0[0].alloc_fn, 0);
	eq("ftab[0].adds_command", ftab0[0].adds_command, 0);
	eq("ftab[0].name[0]", ftab0[0].name[0], 'a');
	eq("ftab[1].len", ftab0[1].len, 8);
	eq("ftab[1].expand_args", ftab0[1].expand_args, 1);
	eq("ftab[2].len", ftab0[2].len, 5);
	eq("ftab[2].expand_args", ftab0[2].expand_args, 1);
	eq("ftab[2].alloc_fn", ftab0[2].alloc_fn, 1);
	eq("ftab[2].adds_command", ftab0[2].adds_command, 1);
	eq("ftab[3].len", ftab0[3].len, 4);
	eq("ftab[3].alloc_fn", ftab0[3].alloc_fn, 0);
	eq("ftab[3].name[0]", ftab0[3].name[0], 'e');

	printf("\nSection 2: the tail-sharing shape\n");
	eq("tail.a", tail0.a, 1);
	eq("tail.b", tail0.b, 1);
	eq("tail.c", tail0.c, 'z');
	eq("tail.d", tail0.d, 'q');

	printf("\nSection 3: two groups sharing one container\n");
	eq("two.a", two0.a, 1);
	eq("two.c", two0.c, 'c');
	eq("two.b", two0.b, 1);
	eq("two.d", two0.d, 'd');

	printf("\nSection 4: a group spanning three bytes\n");
	eq("span.c", span0.c, 'c');
	eq("span.a", span0.a, 0x1ABCD);
	eq("span.d", span0.d, 'd');

	printf("\nSection 5: zero-valued bit fields beside live bytes\n");
	eq("withzero.before", zero0.before, 0x5a);
	eq("withzero.z1", zero0.z1, 0);
	eq("withzero.nz", zero0.nz, 9);
	eq("withzero.z2", zero0.z2, 0);
	eq("withzero.after", zero0.after, 0xa5);

	printf("\n%d failures\n", fails);
	return fails;
}
