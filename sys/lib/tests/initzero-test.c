/*
 * initzero-test -- does a compound literal ZERO the members its
 * initialiser list leaves out?
 *
 *	cd sys/lib/tests && pcc -o initzero-test initzero-test.c && ./initzero-test
 *	host:  gcc -O0 -o initzero-test initzero-test.c && ./initzero-test
 *
 * WHERE IT CAME FROM: muon's FIRST run on 9front, which crashed before it
 * had parsed an argument.
 *
 *	muon 21799: suicide: sys: trap: fault write addr=0x7ffffff000 pc=0x4d1c7c
 *	acid: lstk()
 *	memset(c=0x0, n=0x29afb0)+0x1f       .../lib/ap/string/memset.c:10
 *	tstr_clear(sb=0x7fffffdee00)+0x32    muon/src/lang/string.c:882
 *	path_basename(wk=0x0, buf=0x7fffffdee00, ...)  muon/src/platform/path.c:356
 *	main+0x86                            muon/src/main.c:1447
 *
 * `tstr_clear' is two statements: `memset(sb->buf, 0, sb->len)' and
 * `sb->len = 0'.  **The faulting write is a memset of 0x29afb0 =
 * 2,731,952 bytes over a 1024-byte buffer on main's stack**, which is a
 * `len' that is garbage.  `buf' was right -- the memset reached a real
 * address and walked off the top of the stack rather than faulting at
 * once -- so exactly ONE member of that struct is wrong.
 *
 * AND THAT MEMBER IS THE ONE C REQUIRES TO BE ZEROED.  `tstr_init' ends:
 *
 *	*sb = (struct tstr){
 *		.flags = flags,
 *		.buf = initial_buffer,
 *		.cap = initial_buffer_cap,
 *	};
 *
 * `struct tstr' is `{ char *buf; uint32_t len, cap; enum tstr_flags flags;
 * obj s; }'.  **`.len' and `.s' are OMITTED**, and C99 6.7.8p21 (and
 * 6.5.2.5p1 for the literal) says an omitted member is initialised as an
 * object with static storage duration would be -- zero.  If kencc writes
 * only the three named members into the destination and leaves the rest
 * alone, `len' keeps whatever was in that storage.  *That is the whole
 * symptom with nothing left over.*
 *
 * WHY THE TWO EXISTING TESTS COULD NOT HAVE CAUGHT IT.
 * `compound-literal-test.c' asks whether a literal can be taken by
 * address, passed, subscripted and written through -- every one of its
 * checks names a member it also initialises.  `designated-init-test.c'
 * asks which member a DESIGNATOR lands on when names collide or nest --
 * it is about placement, not about the gaps.  **Neither asks what happens
 * to a member that is not mentioned**, and neither assigns a literal
 * THROUGH A POINTER, which is muon's form.  *Correctness and completeness
 * are different properties*, which is the lesson the 47-of-97 cfront probe
 * already cost this tree.
 *
 * THE STORAGE IS DIRTIED FIRST, AND WITHOUT THAT THIS FILE IS WORTHLESS.
 * A compiler that writes only the named members passes every check here if
 * the destination happened to be zero already -- a fresh stack frame or
 * fresh BSS usually is.  So every case writes 0xAA over the destination
 * before the literal, and section 0 CHECKS THAT THE DIRTYING WORKED by
 * reading one byte back.  *A check that cannot fail is not a check*, and
 * a test whose poison never arrived is exactly that.
 *
 * Section 7 is muon's own reduction: its struct, its init, its clear, and
 * the assertion that `len' is 0 before the memset length is taken from it.
 * It is the one section whose failure names a program rather than a rule.
 *
 * MEASURED ON THE VM: **6 failures under `pcc', 0 under gcc**, so muon's
 * crash is kencc's and the fix is in the compiler.  `sizeof(struct tstr)'
 * printed 24 rather than the host's 32, which is the 32-bit `long'
 * invariant and not a finding.
 *
 * AND THE PATTERN IS THE DIAGNOSIS, not the count.  `.len' was garbage
 * and `.s' was zero through a POINTER (1a/1b), and the other way round
 * into a LOCAL (2a/2b) -- the same two gaps of the same struct, in one
 * program, differing only in what the frame last held.  Section 6b, an
 * array literal with three holes, passed outright.  *A compiler that
 * simply never zeroed would have failed all of them uniformly; this is
 * what an UNINITIALISED SLOT looks like*, and `compoundlit()' in
 * `cc/dcl.c' allocates exactly that -- a hidden auto, `adecl(CAUTO,...)',
 * written only where the initialiser list says.
 *
 * **SECTION 5 IS THE CONTROL AND IT PASSED FOR A REAL REASON.** A
 * DECLARATION goes through `cc.y's `adlist', which is `doinit(); contig()'
 * -- and `contig()' is precisely "zero every byte the list did not
 * cover".  `compoundlit()' was the one caller of `doinit()' that never
 * had the second half.  So section 5 passing beside 1a/3a/4a/6a/7 failing
 * is not noise: *it is the asymmetry between the two productions, which
 * is the whole bug*, and it is why no ordinary C in this tree ever
 * tripped over it.
 *
 * 0 failures on gcc.  Exit status is the failure count.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int failures;

static void
check(const char *what, int ok, const char *detail)
{
	printf("%s: %s", ok ? "PASS" : "FAIL", what);
	if(detail != NULL && detail[0] != '\0')
		printf("  (%s)", detail);
	printf("\n");
	if(!ok)
		failures++;
}

/*
 * Poison.  `volatile' on the pointer is what stops a compiler proving the
 * writes dead and dropping them -- which would silently remove the only
 * thing that makes this file able to fail.
 */
static void
dirty(void *p, size_t n)
{
	volatile unsigned char *q = (volatile unsigned char *)p;
	size_t i;

	for(i = 0; i < n; i++)
		q[i] = 0xAA;
}

/* muon's struct, verbatim in shape */
typedef unsigned int u32;
struct tstr {
	char *buf;
	u32 len, cap;
	int flags;
	unsigned long s;
};

struct mixed {
	int a;
	char b;
	long c;
	void *d;
};

struct inner { int x, y; };
struct outer { int head; struct inner in; int tail; };

/* not static: muon's is a separate translation unit, and a compiler may
 * treat a whole-struct assignment differently when it can see the caller */
void
tstr_init_model(struct tstr *sb, char *buf, u32 cap, int flags)
{
	*sb = (struct tstr){
		.flags = flags,
		.buf = buf,
		.cap = cap,
	};
}

int
main(void)
{
	char room[1024];

	/* ---- 0: the instrument.  Did the poison arrive? */
	{
		struct tstr t;
		unsigned char first;

		dirty(&t, sizeof t);
		memcpy(&first, &t, 1);
		check("0 the destination really is dirty before each case",
			first == 0xAA, "a zero destination would make every "
			"check below pass for the wrong reason");
		printf("     sizeof(struct tstr) = %d\n", (int)sizeof t);
	}

	/* ---- 1: muon's exact shape -- a literal assigned THROUGH A POINTER,
	 * with .len and .s omitted.  This is the one that crashed. */
	{
		struct tstr *p = malloc(sizeof *p);

		if(p == NULL)
			return 125;
		dirty(p, sizeof *p);
		tstr_init_model(p, room, (u32)sizeof room, 0);
		check("1a omitted .len is zero (literal through a pointer)",
			p->len == 0, NULL);
		check("1b omitted .s is zero", p->s == 0, NULL);
		check("1c the named members are still right",
			p->buf == room && p->cap == (u32)sizeof room
			&& p->flags == 0, NULL);
		free(p);
	}

	/* ---- 2: the same literal assigned to a LOCAL rather than through a
	 * pointer.  Two different code paths in a compiler; 1 passing and 2
	 * failing, or the reverse, would say which. */
	{
		struct tstr t;

		dirty(&t, sizeof t);
		t = (struct tstr){ .flags = 3, .buf = room, .cap = 7 };
		check("2a omitted .len is zero (literal into a local)",
			t.len == 0, NULL);
		check("2b omitted .s is zero", t.s == 0, NULL);
	}

	/* ---- 3: a POSITIONAL partial literal.  No designators at all, so a
	 * compiler that gets designators right and gaps wrong is separated
	 * from one that gets both wrong. */
	{
		struct mixed m;

		dirty(&m, sizeof m);
		m = (struct mixed){ 5 };
		check("3a positional literal: trailing members zeroed",
			m.b == 0 && m.c == 0 && m.d == NULL, NULL);
		check("3b and the one given member is right", m.a == 5, NULL);
	}

	/* ---- 4: a designator that SKIPS a member in the middle, so the gap
	 * is not merely a tail the compiler could clear with one memset of
	 * the end. */
	{
		struct mixed m;

		dirty(&m, sizeof m);
		m = (struct mixed){ .a = 1, .d = room };
		check("4a a gap in the MIDDLE is zeroed",
			m.b == 0 && m.c == 0, NULL);
		check("4b the members around it are right",
			m.a == 1 && m.d == (void *)room, NULL);
	}

	/* ---- 5: a DECLARATION with an initialiser rather than an
	 * assignment.  Different grammar, possibly different code.  The frame
	 * is dirtied by a call that returns before the declaration, which is
	 * how muon's garbage got there. */
	{
		struct mixed junk;

		dirty(&junk, sizeof junk);
		{
			struct mixed m = { .c = 9 };

			check("5 declaration initialiser zeroes the gaps",
				m.a == 0 && m.b == 0 && m.d == NULL
				&& m.c == 9, NULL);
		}
	}

	/* ---- 6: nested, and an array literal with a hole. */
	{
		struct outer o;
		int *a;

		dirty(&o, sizeof o);
		o = (struct outer){ .tail = 4 };
		check("6a an omitted nested STRUCT member is zeroed",
			o.in.x == 0 && o.in.y == 0 && o.head == 0
			&& o.tail == 4, NULL);

		a = (int[5]){ [3] = 7 };
		check("6b an array literal zeroes the elements it skips",
			a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 7
			&& a[4] == 0, NULL);
	}

	/* ---- 7: muon's reduction, end to end.  `tstr_clear' takes its
	 * memset LENGTH from the member section 1 asks about, so this is the
	 * fault itself rather than the rule behind it. */
	{
		struct tstr t;
		unsigned long n;

		dirty(&t, sizeof t);
		tstr_init_model(&t, room, (u32)sizeof room, 0);
		n = (unsigned long)t.len;
		if(n <= sizeof room)
			memset(t.buf, 0, (size_t)n);
		check("7 tstr_clear's memset length is 0, not stack garbage",
			n == 0, n == 0 ? NULL :
			"muon faulted writing this many bytes over a 1024-byte "
			"buffer");
		if(n != 0)
			printf("     the length it would have used: %lu\n", n);
	}

	printf("\n%d failures\n", failures);
	if(failures != 0) {
		printf("NOTE: an omitted member of a compound literal must be\n");
		printf("      zeroed (C99 6.7.8p21).  If these fail under pcc\n");
		printf("      and pass under gcc, muon's crash is kencc's and\n");
		printf("      the fix is in the compiler, not in muon.\n");
	}
	return failures;
}
