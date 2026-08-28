/*
 * sha3_kat.c -- SHA-3 and SHAKE known-answer tests.
 *
 * ML-KEM keygen fails here, which is where the TLS 1.3 handshake
 * failure bottoms out (see the mkfile beside this). Keygen is the
 * earliest of the three operations and encap and decap build on it, so
 * this is the root and not a consequence.
 *
 * ML-KEM keygen is two layers:
 *
 *   Keccak    SHA3-512 expands the seed, SHAKE-128 generates the
 *             matrix A, SHAKE-256 samples the noise
 *   ---------------------------------------------------------------
 *   lattice   NTT, pointwise multiply, Barrett/Montgomery reduction,
 *             and the byte encoding of the result
 *
 * This test decides which. If SHA-3 is wrong, everything above it is
 * garbage in and there is no point reading the polynomial arithmetic;
 * if SHA-3 is right, the fault is in crypto/mlkem itself.
 *
 * Keccak is the better suspect on the evidence. It is used by ML-KEM
 * and by essentially nothing else in a TLS handshake -- TLS 1.3 hashes
 * with SHA-256 and SHA-384 -- which fits a failure that appears only
 * when X25519MLKEM768 is negotiated. crypto/sha/sha3.c is also the only
 * file in all of crypto that calls le64toh and htole64, the two names
 * that were undefined at the first link and are now supplied by APE's
 * <endian.h> through -DHAVE_ENDIAN_H. On amd64 both are no-op casts and
 * <_apetypes.h> does set __BYTE_ORDER to __LITTLE_ENDIAN, so that
 * should be right -- but "should be right" is what this file is for.
 *
 * SHAKE is reached through crypto/sha/sha3_internal.h; only
 * EVP_sha3_256 is public, and SHAKE is not exposed at all.
 *
 * Vectors are the NIST ones for the empty string and "abc", plus a
 * 200-byte input, which matters: the SHA3-256 rate is 136 bytes and
 * SHA3-512's is 72, so 200 bytes is the shortest input that drives the
 * absorb loop through more than one permutation for every variant here.
 * A one-block-only test would miss anything wrong with the sponge's
 * block handling and catch only a broken permutation.
 *
 * All of them were checked against an independent implementation before
 * being written down.
 *
 * Build and run:  mk test  (from this directory)
 * Prints "PASS" per case; exit status is the number of failures.
 */

#include <stdio.h>
#include <string.h>

#include "sha3_internal.h"

static int failures;

static void
hexdump(const char *label, const unsigned char *p, size_t n)
{
	size_t i;

	printf("      %s ", label);
	for (i = 0; i < n; i++)
		printf("%02x", p[i]);
	printf("\n");
}

static void
check(const char *what, const unsigned char *got, const unsigned char *want,
    size_t n)
{
	if (memcmp(got, want, n) == 0) {
		printf("PASS  %s\n", what);
		return;
	}
	printf("FAIL  %s\n", what);
	hexdump("got ", got, n);
	hexdump("want", want, n);
	failures++;
}

/* mdlen is in bytes: 32 for SHA3-256, 64 for SHA3-512. */
static void
sha3(int mdlen, const void *in, size_t inlen, unsigned char *out)
{
	sha3_ctx ctx;

	sha3_init(&ctx, mdlen);
	sha3_update(&ctx, in, inlen);
	sha3_final(out, &ctx);
}

/*
 * SHAKE, the extendable-output form: absorb, switch the sponge to
 * squeezing with shake_xof(), then take as many bytes as wanted.
 * shake128_init passes 16 and shake256_init 32 -- that is the capacity
 * argument, not an output length, which is why the output size is
 * chosen at squeeze time.
 */
static void
shake(int rate_arg, const void *in, size_t inlen, unsigned char *out,
    size_t outlen)
{
	sha3_ctx ctx;

	sha3_init(&ctx, rate_arg);
	shake_update(&ctx, in, inlen);
	shake_xof(&ctx);
	shake_out(&ctx, out, outlen);
}

int
main(void)
{
	static const unsigned char sha3_256_empty[32] = {
		0xa7,0xff,0xc6,0xf8,0xbf,0x1e,0xd7,0x66,
		0x51,0xc1,0x47,0x56,0xa0,0x61,0xd6,0x62,
		0xf5,0x80,0xff,0x4d,0xe4,0x3b,0x49,0xfa,
		0x82,0xd8,0x0a,0x4b,0x80,0xf8,0x43,0x4a,
	};
	static const unsigned char sha3_256_abc[32] = {
		0x3a,0x98,0x5d,0xa7,0x4f,0xe2,0x25,0xb2,
		0x04,0x5c,0x17,0x2d,0x6b,0xd3,0x90,0xbd,
		0x85,0x5f,0x08,0x6e,0x3e,0x9d,0x52,0x5b,
		0x46,0xbf,0xe2,0x45,0x11,0x43,0x15,0x32,
	};
	static const unsigned char sha3_512_abc[64] = {
		0xb7,0x51,0x85,0x0b,0x1a,0x57,0x16,0x8a,
		0x56,0x93,0xcd,0x92,0x4b,0x6b,0x09,0x6e,
		0x08,0xf6,0x21,0x82,0x74,0x44,0xf7,0x0d,
		0x88,0x4f,0x5d,0x02,0x40,0xd2,0x71,0x2e,
		0x10,0xe1,0x16,0xe9,0x19,0x2a,0xf3,0xc9,
		0x1a,0x7e,0xc5,0x76,0x47,0xe3,0x93,0x40,
		0x57,0x34,0x0b,0x4c,0xf4,0x08,0xd5,0xa5,
		0x65,0x92,0xf8,0x27,0x4e,0xec,0x53,0xf0,
	};
	static const unsigned char shake128_empty[32] = {
		0x7f,0x9c,0x2b,0xa4,0xe8,0x8f,0x82,0x7d,
		0x61,0x60,0x45,0x50,0x76,0x05,0x85,0x3e,
		0xd7,0x3b,0x80,0x93,0xf6,0xef,0xbc,0x88,
		0xeb,0x1a,0x6e,0xac,0xfa,0x66,0xef,0x26,
	};
	static const unsigned char shake256_empty[32] = {
		0x46,0xb9,0xdd,0x2b,0x0b,0xa8,0x8d,0x13,
		0x23,0x3b,0x3f,0xeb,0x74,0x3e,0xeb,0x24,
		0x3f,0xcd,0x52,0xea,0x62,0xb8,0x1b,0x82,
		0xb5,0x0c,0x27,0x64,0x6e,0xd5,0x76,0x2f,
	};
	/* 64 bytes out, so the squeeze runs past a single block. */
	static const unsigned char shake128_abc[64] = {
		0x58,0x81,0x09,0x2d,0xd8,0x18,0xbf,0x5c,
		0xf8,0xa3,0xdd,0xb7,0x93,0xfb,0xcb,0xa7,
		0x40,0x97,0xd5,0xc5,0x26,0xa6,0xd3,0x5f,
		0x97,0xb8,0x33,0x51,0x94,0x0f,0x2c,0xc8,
		0x44,0xc5,0x0a,0xf3,0x2a,0xcd,0x3f,0x2c,
		0xdd,0x06,0x65,0x68,0x70,0x6f,0x50,0x9b,
		0xc1,0xbd,0xde,0x58,0x29,0x5d,0xae,0x3f,
		0x89,0x1a,0x9a,0x0f,0xca,0x57,0x83,0x78,
	};
	/* 200 bytes in: more than one absorb block for every variant. */
	static const unsigned char sha3_256_200[32] = {
		0x5f,0x72,0x8f,0x63,0xbf,0x5e,0xe4,0x8c,
		0x77,0xf4,0x53,0xc0,0x49,0x03,0x98,0xfa,
		0x64,0x5b,0x8d,0x4c,0x4e,0x56,0xbe,0x9a,
		0x41,0xcf,0xec,0x34,0x4d,0x6c,0xa8,0x99,
	};
	static const unsigned char shake256_200[64] = {
		0x4e,0xe1,0xca,0x03,0x27,0x2b,0x05,0xd3,
		0xbf,0xb1,0xe1,0xc7,0x9a,0x96,0x7f,0x82,
		0x3b,0x9f,0xc5,0xe4,0xbb,0x39,0x87,0xb1,
		0xba,0x9e,0x9c,0xb5,0xaf,0xb0,0x7a,0x5e,
		0xe3,0xa0,0x7f,0xbd,0x45,0x7a,0x94,0x36,
		0x49,0x64,0xa8,0x41,0xe7,0xf4,0x66,0xe5,
		0xa0,0x22,0xe2,0x1a,0xb7,0xf6,0x73,0xc1,
		0x8b,0xa9,0x8c,0xdb,0x1d,0x5a,0xec,0xfa,
	};
	unsigned char out[64], big[200];
	int i;

	for (i = 0; i < 200; i++)
		big[i] = (unsigned char)i;

	sha3(32, "", 0, out);
	check("SHA3-256 of the empty string", out, sha3_256_empty, 32);

	sha3(32, "abc", 3, out);
	check("SHA3-256 of \"abc\"", out, sha3_256_abc, 32);

	sha3(64, "abc", 3, out);
	check("SHA3-512 of \"abc\"", out, sha3_512_abc, 64);

	sha3(32, big, sizeof(big), out);
	check("SHA3-256 of 200 bytes (multi-block absorb)", out,
	    sha3_256_200, 32);

	shake(16, "", 0, out, 32);
	check("SHAKE-128 of the empty string, 32 out", out,
	    shake128_empty, 32);

	shake(32, "", 0, out, 32);
	check("SHAKE-256 of the empty string, 32 out", out,
	    shake256_empty, 32);

	shake(16, "abc", 3, out, 64);
	check("SHAKE-128 of \"abc\", 64 out (multi-block squeeze)", out,
	    shake128_abc, 64);

	shake(32, big, sizeof(big), out, 64);
	check("SHAKE-256 of 200 bytes, 64 out", out, shake256_200, 64);

	if (failures)
		printf("\n%d failure(s) -- Keccak is the bug, and there is no\n"
		       "point reading crypto/mlkem's polynomial arithmetic\n"
		       "until this passes.\n", failures);
	else
		printf("\nall ok -- Keccak is sound, so the ML-KEM keygen\n"
		       "failure is in crypto/mlkem itself.\n");
	return failures;
}
