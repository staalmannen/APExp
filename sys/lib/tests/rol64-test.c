/*
 * rol64-test.c -- a 64-bit function result truncated to 32 bits.
 *
 * Found in LibreSSL's Keccak, which is why TLS 1.3 could not talk to
 * any server offering X25519MLKEM768: ML-KEM is the only thing in a
 * handshake that hashes with SHA-3, SHA-3 was wrong, and the fault is
 * one call in the theta step of crypto/sha/sha3.c:
 *
 *	t0 = bc[(i + 4) % 5] ^ crypto_rol_u64(bc[(i + 1) % 5], 1);
 *
 * crypto_rol_u64 returns uint64_t. Its result arrives here with bits
 * 32..63 cleared. The identical function called two lines further down,
 *
 *	st[j] = crypto_rol_u64(t0, sha3_keccakf_rotc[i]);
 *
 * is correct, so it was never the function: it was the call site.
 *
 * FIXED in 6c/cgen.c. cgen spills AX, CX or DX where the instruction it
 * is about to emit can only use that register -- a divide or modulo
 * needs AX and DX, a variable shift needs CX -- and the save was
 *
 *	regsalloc(&nod2, n);	-- slot sized from n, the divide
 *	gmove(&nod, &nod2);	-- so a 32-bit save
 *
 * regsalloc takes its size from the node it is given, and n is the
 * divide. A 32-bit operation therefore spilled four bytes of a register
 * that might hold eight. What is live in AX at that point belongs to an
 * earlier part of the expression and has nothing to do with the type of
 * the operation being generated. OFUNC has complex == FNX, so cgen's
 * OXOR case evaluates the call first and it lands in AX; the 32-bit
 * "% 5" beside it then saved AX four bytes wide.
 *
 * Now a regression test. The cases below found the trigger by changing
 * one thing at a time, and the pattern was:
 *
 *	% in the call's argument		passed
 *	% in the other operand of the ^		FAILED
 *	% in the other operand, but no call	passed
 *	% hoisted into a variable first		passed
 *	/ or * instead of %			passed
 *
 * so the trigger is <expression containing / or %> op <64-bit function
 * call>, with the division in the *other* operand: an argument is
 * evaluated before the call, so nothing 64-bit is live across it yet.
 * All of that is kept because it is what makes a future regression
 * legible rather than just red.
 *
 * Nothing here is Keccak-specific and nothing here is unusual C. A
 * 64-bit function result feeding an XOR is ordinary enough that this is
 * unlikely to be the only casualty; it is simply the first one with a
 * test vector sharp enough to catch it.
 *
 * Build and run:  pcc -o rol64-test rol64-test.c
 * Prints "PASS" per case; exit status is the number of failures.
 */

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#define V	0x0000300000200200ULL	/* the value theta rotated */
#define WANT	0x0000600000400400ULL	/* V rotated left by 1 */
#define OTHER	0x0000100000208004ULL	/* bc[4], the other XOR operand */

static int failures;

static void
check(const char *what, uint64_t got, uint64_t want)
{
	if (got == want) {
		printf("PASS  %s\n", what);
		return;
	}
	printf("FAIL  %s\n", what);
	printf("      got  0x%016llx\n", (unsigned long long)got);
	printf("      want 0x%016llx\n", (unsigned long long)want);
	if ((got & 0xffffffffULL) == (want & 0xffffffffULL)
	    && (got >> 32) == 0)
		printf("      (low 32 bits right, high 32 lost)\n");
	failures++;
}

/* The three linkages, all the same body as crypto_rol_u64. */
static inline uint64_t
rol_inline(uint64_t v, size_t s)
{
	return (v << s) | (v >> (64 - s));
}

static uint64_t
rol_static(uint64_t v, size_t s)
{
	return (v << s) | (v >> (64 - s));
}

uint64_t
rol_extern(uint64_t v, size_t s)
{
	return (v << s) | (v >> (64 - s));
}

/* A 64-bit result that owes nothing to shifting, to separate "the
   rotate is wrong" from "a 64-bit return value is wrong". */
static uint64_t
ret_const(void)
{
	return WANT;
}

/* Keep values out of the compiler's reach so nothing is folded. */
static volatile uint64_t vv = V;
static volatile uint64_t vother = OTHER;
static volatile size_t vone = 1;
static volatile int vi = 0;

int
main(void)
{
	uint64_t v, other, r;
	uint64_t bc[5];
	size_t s;
	int i;

	v = vv;
	other = vother;
	s = vone;
	i = vi;

	printf("--- the result assigned straight to a variable\n");
	r = rol_inline(v, 1);
	check("r = rol_inline(v, 1)", r, WANT);
	r = rol_inline(v, s);
	check("r = rol_inline(v, s)", r, WANT);

	printf("\n--- the result as an operand of ^, which is theta's shape\n");
	r = other ^ rol_inline(v, 1);
	check("r = other ^ rol_inline(v, 1)", r, OTHER ^ WANT);
	r = other ^ rol_inline(v, s);
	check("r = other ^ rol_inline(v, s)", r, OTHER ^ WANT);

	printf("\n--- the same, without the inline keyword\n");
	r = other ^ rol_static(v, 1);
	check("r = other ^ rol_static(v, 1)", r, OTHER ^ WANT);
	r = other ^ rol_extern(v, 1);
	check("r = other ^ rol_extern(v, 1)", r, OTHER ^ WANT);

	printf("\n--- a 64-bit result that involves no shifting at all\n");
	r = other ^ ret_const();
	check("r = other ^ ret_const()", r, OTHER ^ WANT);
	r = ret_const();
	check("r = ret_const()", r, WANT);

	printf("\n--- the rotation written out, with no call\n");
	r = other ^ ((v << 1) | (v >> 63));
	check("r = other ^ ((v << 1) | (v >> 63))", r, OTHER ^ WANT);
	r = (v << 1) | (v >> 63);
	check("r = (v << 1) | (v >> 63)", r, WANT);

	printf("\n--- narrowing: which part of the array operand matters?\n"
	       "--- (on amd64 %% and / need AX and DX, which is also where a\n"
	       "--- call returns its result -- so these separate a plain\n"
	       "--- array index from one that needs a division)\n");
	{
		int k = vi + 1;		/* 1, but opaque */
		int m = vi + 4;		/* 4, but opaque */

		bc[0] = v;
		bc[1] = v;
		bc[2] = v;
		bc[3] = other;
		bc[4] = other;

		/* Plain indices, no division anywhere. */
		r = bc[m] ^ rol_inline(bc[k], 1);
		check("bc[m] ^ rol(bc[k], 1)            -- no division",
		    r, OTHER ^ WANT);

		/* Division only in the call's argument. */
		r = other ^ rol_inline(bc[(i + 1) % 5], 1);
		check("other ^ rol(bc[(i+1)%5], 1)      -- % in the argument",
		    r, OTHER ^ WANT);

		/* Division only in the other operand of the ^. */
		r = bc[(i + 4) % 5] ^ rol_inline(bc[k], 1);
		check("bc[(i+4)%5] ^ rol(bc[k], 1)      -- % in the left operand",
		    r, OTHER ^ WANT);

		/* Division in both, which is what theta has. */
		r = bc[(i + 4) % 5] ^ rol_inline(bc[(i + 1) % 5], 1);
		check("bc[(i+4)%5] ^ rol(bc[(i+1)%5], 1) -- % in both",
		    r, OTHER ^ WANT);

		/* / rather than %, to see whether it is division as such. */
		r = bc[m] ^ rol_inline(bc[(i + 5) / 5], 1);
		check("bc[m] ^ rol(bc[(i+5)/5], 1)      -- / in the argument",
		    r, OTHER ^ WANT);

		/* A multiply instead: same shape, but no fixed registers. */
		r = bc[m] ^ rol_inline(bc[(i + 1) * 1], 1);
		check("bc[m] ^ rol(bc[(i+1)*1], 1)      -- * in the argument",
		    r, OTHER ^ WANT);

		/* Division outside the call, result in a plain variable, to
		   show the division itself computes the right index. */
		{
			int idx = (i + 1) % 5;

			r = bc[m] ^ rol_inline(bc[idx], 1);
			check("bc[m] ^ rol(bc[idx], 1)          -- % hoisted out",
			    r, OTHER ^ WANT);
		}

		/* And with no call at all, to confirm the call is needed. */
		r = bc[(i + 4) % 5] ^ ((bc[(i + 1) % 5] << 1)
		    | (bc[(i + 1) % 5] >> 63));
		check("bc[(i+4)%5] ^ (shift written out) -- % but no call",
		    r, OTHER ^ WANT);
	}

	printf("\n--- array operands with computed indices, as in theta\n");
	bc[0] = v;
	bc[1] = v;
	bc[2] = v;
	bc[3] = other;
	bc[4] = other;
	r = bc[(i + 4) % 5] ^ rol_inline(bc[(i + 1) % 5], 1);
	check("r = bc[(i+4)%5] ^ rol_inline(bc[(i+1)%5], 1)", r,
	    OTHER ^ WANT);

	printf("\n--- theta itself, in full\n");
	{
		uint64_t st[25], t0;
		int j;

		for (j = 0; j < 25; j++)
			st[j] = 0;
		st[0] = v;
		st[4] = other;

		for (i = 0; i < 5; i++)
			bc[i] = st[i] ^ st[i + 5] ^ st[i + 10] ^ st[i + 15]
			    ^ st[i + 20];
		i = 0;
		t0 = bc[(i + 4) % 5] ^ rol_inline(bc[(i + 1) % 5], 1);
		/* bc[4] is st[4] = OTHER; bc[1] is st[1] = 0, so this one
		   only checks that the shape compiles to the right thing
		   when the rotated operand is zero. */
		check("theta t0 with a zero rotate operand", t0, OTHER);

		st[1] = v;
		for (i = 0; i < 5; i++)
			bc[i] = st[i] ^ st[i + 5] ^ st[i + 10] ^ st[i + 15]
			    ^ st[i + 20];
		i = 0;
		t0 = bc[(i + 4) % 5] ^ rol_inline(bc[(i + 1) % 5], 1);
		check("theta t0, exactly as sha3.c writes it", t0,
		    OTHER ^ WANT);
	}

	if (failures)
		printf("\n%d failure(s). Compare which cases failed: the one\n"
		       "thing they have in common is the trigger.\n", failures);
	else
		printf("\nall ok\n");
	return failures;
}
