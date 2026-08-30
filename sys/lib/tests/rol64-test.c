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
 * is correct, so it is not the function: it is something about this
 * call site. Modelling the permutation with only the theta call's
 * result masked to 32 bits reproduces all 25 lanes of the observed
 * wrong state after 24 rounds -- a 1600-bit match, so the diagnosis is
 * not in doubt. What is not yet known is which property of the call
 * site triggers it.
 *
 * That is what this file is for. Each case changes one thing:
 *
 *	how the result is used	assigned, or an operand of ^
 *	the shift		a literal constant, or a variable
 *	the function		static inline, static, or extern
 *	the arguments		a scalar, or an array element with a
 *				computed index
 *
 * The pattern of PASS and FAIL across them names the trigger. Every
 * case computes the same rotation of the same value -- the one theta
 * actually got wrong, 0x0000300000200200 rotated left by 1 -- so any
 * FAIL is the compiler and nothing else.
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
