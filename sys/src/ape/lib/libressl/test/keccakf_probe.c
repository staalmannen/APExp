/*
 * keccakf_probe.c -- find the miscompiled step of Keccak-f[1600].
 *
 * Where this stands. sha3_kat.c showed every 64-bit primitive Keccak is
 * built from to be correct -- crypto_rol_u64 at the amounts it uses,
 * both shifts by a size_t, the byte/word union -- and every SHA-3 and
 * SHAKE vector to be wrong. The first version of this file then showed
 * the permutation itself wrong on the standard all-zero-state vector,
 * so the sponge is not involved either.
 *
 * The full 25-lane result did not identify the step. Keccak diffuses
 * completely in a few rounds, so every candidate fault -- a byte-swapped
 * state, round constants truncated to 32 bits or sign-extended from
 * them, a dropped or extra round, theta without its rotate, chi with the
 * wrong operator, every wrong index in theta's and chi's (i+n)%5 -- all
 * produce output with no more lanes in common with the observed result
 * than chance gives. After 24 rounds a wrong permutation looks random
 * whatever is wrong with it.
 *
 * So stop diffusing. From an all-zero state the early rounds are almost
 * empty:
 *
 *   round 1   theta, rho and chi all act on zeros and do nothing;
 *             only iota fires, leaving lane 0 = 1 and the rest zero
 *   round 2   works on that single bit, so the state stays sparse
 *             enough to read: after theta it is columns of 1s and 2s
 *
 * A single wrong rotate, index or operator is unmissable there.
 *
 * probe_keccakf below is sha3_keccakf copied out of sha3.c, character
 * for character, with two parameters added: how many rounds to run, and
 * where to stop inside the last one. It uses sha3.c's own rndc, rotc and
 * piln tables -- this file #includes sha3.c, so they are in scope --
 * which means the copy differs from the original in nothing but the two
 * loop bounds. Check 2 confirms it reproduces the fault before any
 * conclusion is drawn from it; if the copy came out right while the
 * original came out wrong, that is a finding in itself and the bisect
 * below would be meaningless.
 *
 * Only the first failing check is reported, to keep this to a screen.
 *
 * Build and run:  mk test  (from this directory)
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "sha3.c"

static int failures;
static int reported;

static void
show(const char *label, const uint64_t *st, int nlanes)
{
	int i;

	for (i = 0; i + 5 <= nlanes; i += 5)
		printf("  %s%s 0x%016llx 0x%016llx 0x%016llx 0x%016llx 0x%016llx\n",
		    label, i == 0 ? "" : "    ",
		    (unsigned long long)st[i], (unsigned long long)st[i + 1],
		    (unsigned long long)st[i + 2], (unsigned long long)st[i + 3],
		    (unsigned long long)st[i + 4]);
}

/* Reports the first failure only; later ones follow from it. */
static int
check(const char *what, const uint64_t *got, const uint64_t *want, int nlanes)
{
	int i, bad = -1;

	for (i = 0; i < nlanes; i++)
		if (got[i] != want[i]) {
			bad = i;
			break;
		}
	if (bad < 0) {
		printf("PASS  %s\n", what);
		return 1;
	}
	printf("FAIL  %s (first difference at lane %d)\n", what, bad);
	failures++;
	if (!reported) {
		show("got ", got, nlanes);
		show("want", want, nlanes);
		reported = 1;
	}
	return 0;
}

/* Where to stop inside the final round. */
#define STOP_THETA	1
#define STOP_RHO	2
#define STOP_CHI	3
#define STOP_NONE	4

/*
 * sha3_keccakf, verbatim, plus "rounds" and "stop". The le64toh and
 * htole64 passes are kept so that the copy is the same code; on amd64
 * they are no-op casts.
 */
static void
probe_keccakf(uint64_t st[25], int rounds, int stop)
{
	uint64_t t0, t1, bc[5];
	int i, j, r;

	for (i = 0; i < 25; i++)
		st[i] = le64toh(st[i]);

	for (r = 0; r < rounds; r++) {
		int last = (r == rounds - 1);

		/* Theta */
		for (i = 0; i < 5; i++)
			bc[i] = st[i] ^ st[i + 5] ^ st[i + 10] ^ st[i + 15] ^ st[i + 20];

		for (i = 0; i < 5; i++) {
			t0 = bc[(i + 4) % 5] ^ crypto_rol_u64(bc[(i + 1) % 5], 1);
			for (j = 0; j < 25; j += 5)
				st[j + i] ^= t0;
		}
		if (last && stop == STOP_THETA)
			break;

		/* Rho Pi */
		t0 = st[1];
		for (i = 0; i < 24; i++) {
			j = sha3_keccakf_piln[i];
			t1 = st[j];
			st[j] = crypto_rol_u64(t0, sha3_keccakf_rotc[i]);
			t0 = t1;
		}
		if (last && stop == STOP_RHO)
			break;

		/* Chi */
		for (j = 0; j < 25; j += 5) {
			for (i = 0; i < 5; i++)
				bc[i] = st[j + i];
			for (i = 0; i < 5; i++)
				st[j + i] ^= (~bc[(i + 1) % 5]) & bc[(i + 2) % 5];
		}
		if (last && stop == STOP_CHI)
			break;

		/* Iota */
		st[0] ^= sha3_keccakf_rndc[r];
	}

	for (i = 0; i < 25; i++)
		st[i] = htole64(st[i]);
}

int
main(void)
{
	static const uint64_t once[25] = {
		0xf1258f7940e1dde7ULL, 0x84d5ccf933c0478aULL,
		0xd598261ea65aa9eeULL, 0xbd1547306f80494dULL,
		0x8b284e056253d057ULL,
		0xff97a42d7f8e6fd4ULL, 0x90fee5a0a44647c4ULL,
		0x8c5bda0cd6192e76ULL, 0xad30a6f71b19059cULL,
		0x30935ab7d08ffc64ULL,
		0xeb5aa93f2317d635ULL, 0xa9a6e6260d712103ULL,
		0x81a57c16dbcf555fULL, 0x43b831cd0347c826ULL,
		0x01f22f1a11a5569fULL,
		0x05e5635a21d9ae61ULL, 0x64befef28cc970f2ULL,
		0x613670957bc46611ULL, 0xb87c5a554fd00ecbULL,
		0x8c3ee88a1ccf32c8ULL,
		0x940c7922ae3a2614ULL, 0x1841f924a2c509e4ULL,
		0x16f53526e70465c2ULL, 0x75f644e97f30a13bULL,
		0xeaf1ff7b5ceca249ULL,
	};
	/* One round of an all-zero state: only iota does anything. */
	static const uint64_t r1[25] = {
		1, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,  0, 0, 0, 0, 0,
	};
	/* Round 2, step by step. Sparse enough to read by eye. */
	static const uint64_t r2_theta[25] = {
		0x0000000000000001ULL, 0x0000000000000001ULL, 0, 0,
		0x0000000000000002ULL,
		0, 0x0000000000000001ULL, 0, 0, 0x0000000000000002ULL,
		0, 0x0000000000000001ULL, 0, 0, 0x0000000000000002ULL,
		0, 0x0000000000000001ULL, 0, 0, 0x0000000000000002ULL,
		0, 0x0000000000000001ULL, 0, 0, 0x0000000000000002ULL,
	};
	static const uint64_t r2_rho[25] = {
		0x0000000000000001ULL, 0x0000100000000000ULL, 0, 0,
		0x0000000000008000ULL,
		0, 0x0000000000200000ULL, 0, 0x0000200000000000ULL, 0,
		0x0000000000000002ULL, 0, 0, 0x0000000000000200ULL, 0,
		0x0000000010000000ULL, 0, 0x0000000000000400ULL, 0, 0,
		0, 0, 0x0000010000000000ULL, 0, 0x0000000000000004ULL,
	};
	static const uint64_t r2_chi[25] = {
		0x0000000000000001ULL, 0x0000100000000000ULL,
		0x0000000000008000ULL, 0x0000000000000001ULL,
		0x0000100000008000ULL,
		0, 0x0000200000200000ULL, 0, 0x0000200000000000ULL,
		0x0000000000200000ULL,
		0x0000000000000002ULL, 0x0000000000000200ULL, 0,
		0x0000000000000202ULL, 0,
		0x0000000010000400ULL, 0, 0x0000000000000400ULL,
		0x0000000010000000ULL, 0,
		0x0000010000000000ULL, 0, 0x0000010000000004ULL, 0,
		0x0000000000000004ULL,
	};
	/* Round 2 complete: chi above, then iota XORs 0x8082 into lane 0. */
	static const uint64_t r2[25] = {
		0x0000000000008083ULL, 0x0000100000000000ULL,
		0x0000000000008000ULL, 0x0000000000000001ULL,
		0x0000100000008000ULL,
		0, 0x0000200000200000ULL, 0, 0x0000200000000000ULL,
		0x0000000000200000ULL,
		0x0000000000000002ULL, 0x0000000000000200ULL, 0,
		0x0000000000000202ULL, 0,
		0x0000000010000400ULL, 0, 0x0000000000000400ULL,
		0x0000000010000000ULL, 0,
		0x0000010000000000ULL, 0, 0x0000010000000004ULL, 0,
		0x0000000000000004ULL,
	};
	uint64_t st[25], real[25];

	printf("--- 1. the real sha3_keccakf, all-zero state, 24 rounds\n");
	memset(real, 0, sizeof(real));
	sha3_keccakf(real);
	check("real permutation of the all-zero state", real, once, 25);

	printf("\n--- 2. does the copy below reproduce it? (if not, nothing\n"
	       "---    after this means anything)\n");
	memset(st, 0, sizeof(st));
	probe_keccakf(st, 24, STOP_NONE);
	if (memcmp(st, real, sizeof(st)) == 0)
		printf("PASS  the copy agrees with the real one\n");
	else {
		printf("FAIL  the copy does NOT agree with the real one --\n"
		       "      the fault depends on something outside the\n"
		       "      function body, and the bisect below is void\n");
		show("copy", st, 25);
		show("real", real, 25);
		failures++;
		return failures;
	}

	printf("\n--- 3. bisect by round, from the all-zero state\n");
	memset(st, 0, sizeof(st));
	probe_keccakf(st, 1, STOP_NONE);
	check("round 1 (only iota acts: lane 0 becomes 1)", st, r1, 25);

	printf("\n--- 4. bisect by step, inside round 2\n");
	memset(st, 0, sizeof(st));
	probe_keccakf(st, 2, STOP_THETA);
	check("through theta of round 2", st, r2_theta, 25);

	memset(st, 0, sizeof(st));
	probe_keccakf(st, 2, STOP_RHO);
	check("through rho and pi of round 2", st, r2_rho, 25);

	memset(st, 0, sizeof(st));
	probe_keccakf(st, 2, STOP_CHI);
	check("through chi of round 2", st, r2_chi, 25);

	memset(st, 0, sizeof(st));
	probe_keccakf(st, 2, STOP_NONE);
	check("round 2 complete, including iota", st, r2, 25);

	if (failures)
		printf("\n%d failure(s). The first FAIL in section 3 or 4 is\n"
		       "the miscompiled step; everything after it follows.\n",
		       failures);
	else
		printf("\nall ok -- which cannot happen while check 1 fails,\n"
		       "so if you see this, the fault is round-dependent and\n"
		       "the bisect needs to go further than round 2.\n");
	return failures;
}
