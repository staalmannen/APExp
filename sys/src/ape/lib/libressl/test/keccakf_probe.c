/*
 * keccakf_probe.c -- the Keccak-f[1600] permutation on its own.
 *
 * sha3_kat.c narrowed the TLS 1.3 failure to SHA-3: every 64-bit
 * primitive Keccak is built from passes -- rotation at the amounts it
 * uses, both shifts, the byte/word union -- and every SHA-3 and SHAKE
 * vector fails. So the fault is in the permutation or the sponge around
 * it, and neither can be seen from a digest.
 *
 * A digest shows 256 bits of a wrong 1600-bit state, after padding and
 * truncation have mixed everything together. This calls the permutation
 * directly and prints all 25 lanes, which is the whole state and six
 * times the signal. sha3_keccakf is static, so this file #includes
 * sha3.c rather than linking against it -- which is also why it does
 * not link libressl.a: the archive has the same symbols.
 *
 * The vectors are the standard Keccak-f[1600] ones: the permutation
 * applied once and twice to an all-zero state. Nothing else is
 * involved -- no padding, no rate, no absorb loop -- so a failure here
 * is the permutation itself, and a pass means the permutation is right
 * and sha3_update/sha3_final/shake_out are where to look.
 *
 * The two extra inputs are not decoration. A zero state makes theta's
 * column parities zero for the first round, so the first round exercises
 * little; starting from a single set bit, and from a state with one bit
 * in every lane, drives different paths through rho's 24 distinct
 * rotate amounts and chi's non-linearity. If one input matches and
 * another does not, that difference says a great deal.
 *
 * Print the got lines even when they fail: the full wrong state is what
 * makes it possible to work out which step is wrong without another
 * round trip.
 *
 * Build and run:  mk test  (from this directory)
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "sha3.c"

static int failures;

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

static void
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
		return;
	}
	printf("FAIL  %s (first difference at lane %d)\n", what, bad);
	show("got ", got, nlanes);
	show("want", want, nlanes);
	failures++;
}

int
main(void)
{
	/* Keccak-f[1600] applied once to an all-zero state. */
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
	/* And twice: the first five lanes are enough to tell. */
	static const uint64_t twice[5] = {
		0x2d5c954df96ecb3cULL, 0x6a332cd07057b56dULL,
		0x093d8d1270d76b6cULL, 0x8a20d9b25569d094ULL,
		0x4f9c4f99e5e7f156ULL,
	};
	uint64_t st[25];
	int i;

	printf("--- Keccak-f[1600] on its own, no padding or sponge\n");

	memset(st, 0, sizeof(st));
	sha3_keccakf(st);
	check("permutation of the all-zero state", st, once, 25);

	sha3_keccakf(st);
	check("permutation applied twice", st, twice, 5);

	/*
	 * No reference value for these, so they cannot pass or fail --
	 * they are printed because the full wrong state from an input
	 * that exercises different rotate amounts is what identifies the
	 * faulty step without another round trip.
	 */
	if (failures) {
		printf("\n--- two more states, for diagnosis only; there is no\n"
		       "--- expected value here, the numbers themselves are the\n"
		       "--- point\n");

		memset(st, 0, sizeof(st));
		st[0] = 1;
		sha3_keccakf(st);
		show("lane0=1 ", st, 25);

		for (i = 0; i < 25; i++)
			st[i] = 0x0000000100000001ULL;
		sha3_keccakf(st);
		show("all lanes 0x100000001 ", st, 25);
	}

	if (failures)
		printf("\n%d failure(s) -- the permutation is wrong, so the\n"
		       "sponge above it is not the place to look.\n", failures);
	else
		printf("\nall ok -- the permutation is correct, so the fault is\n"
		       "in the sponge: sha3_update, sha3_final, shake_xof or\n"
		       "shake_out.\n");
	return failures;
}
