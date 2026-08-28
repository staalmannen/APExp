/*
 * tls13-kat-test.c -- known-answer tests for everything a TLS 1.3
 * handshake needs before it can read its first encrypted record.
 *
 * Written for this failure:
 *
 *   $ curl -sSI --max-time 10 https://curl.se/
 *   curl: (35) TLS connect error: error:06FFF064:digital envelope
 *     routines:CRYPTO_internal:bad decrypt
 *
 *   $ openssl s_client -connect curl.se:443 </dev/null
 *   CONNECTED(00000006)
 *   9973:error:06FFF064:...:bad decrypt:.../evp/e_chacha20poly1305.c:223:
 *   no peer certificate available
 *   New, TLSv1/SSLv3, Cipher is TLS_CHACHA20_POLY1305_SHA256
 *
 * The named line is
 *
 *   if (timingsafe_memcmp(mac, in + plaintext_len, c20_ctx->tag_len) != 0)
 *
 * in aead_chacha20_poly1305_open() -- the Poly1305 tag on the server's
 * first encrypted record did not match. "no peer certificate available"
 * says how early: in TLS 1.3 the certificate arrives inside that record,
 * so nothing was ever seen, and the "Verify return code: 0 (ok)" printed
 * below it is vacuous rather than reassuring. The CA bundle is not
 * implicated and has not in fact been exercised yet.
 *
 * A tag mismatch does NOT mean the AEAD is at fault. Everything that
 * feeds it is equally suspect, and a wrong key produces exactly the same
 * symptom as a wrong cipher:
 *
 *   SHA-256   -> HMAC-SHA256 -> HKDF -> traffic keys -> ChaCha20
 *                                                    -> Poly1305
 *
 * So each stage is checked here against published vectors, in that
 * order. The first FAIL is the one to chase; later ones are consequences
 * of it. If everything here passes, the primitives are sound and the
 * fault is above them -- the TLS 1.3 key schedule in ssl/tls13_key_share
 * and friends, or the record-layer nonce construction, neither of which
 * has a published vector to test against here.
 *
 * Round-tripping is deliberately not the test. Sealing and opening with
 * the same broken implementation agrees with itself; only a known answer
 * catches an implementation that is self-consistently wrong, which is
 * the only kind that gets this far into a handshake.
 *
 * Vectors: FIPS 180-2 (SHA-256), RFC 4231 (HMAC), RFC 5869 (HKDF),
 * RFC 8439 sections 2.4.2, 2.5.2 and 2.8.2 (ChaCha20, Poly1305, AEAD).
 *
 * The AEAD interface is declared in <openssl/evp.h> here. There is no
 * <openssl/aead.h> -- that is BoringSSL's split, and LibreSSL keeps the
 * whole EVP_AEAD API in evp.h. EVP_AEAD_CTX is opaque, so the contexts
 * below are allocated rather than declared on the stack.
 *
 * Build and run, under apexp-sh:
 *   pcc -o tls13-kat-test tls13-kat-test.c
 * Prints "PASS" per case; exit status is the number of failures.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <openssl/hkdf.h>
#include <openssl/chacha.h>
#include <openssl/poly1305.h>
#include <openssl/evp.h>

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
	if (got != NULL && memcmp(got, want, n) == 0) {
		printf("PASS  %s\n", what);
		return;
	}
	printf("FAIL  %s\n", what);
	if (got != NULL) {
		hexdump("got ", got, n);
		hexdump("want", want, n);
	} else
		printf("      the call itself failed\n");
	failures++;
}

static void
checkbool(const char *what, int ok, const char *detail)
{
	if (ok)
		printf("PASS  %s\n", what);
	else {
		printf("FAIL  %s%s%s\n", what, detail ? ": " : "",
		       detail ? detail : "");
		failures++;
	}
}

/* ---- 1. SHA-256. FIPS 180-2, the one-block "abc" vector. ---- */
static void
test_sha256(void)
{
	static const unsigned char want[32] = {
		0xba,0x78,0x16,0xbf,0x8f,0x01,0xcf,0xea,
		0x41,0x41,0x40,0xde,0x5d,0xae,0x22,0x23,
		0xb0,0x03,0x61,0xa3,0x96,0x17,0x7a,0x9c,
		0xb4,0x10,0xff,0x61,0xf2,0x00,0x15,0xad,
	};
	unsigned char md[32];
	SHA256_CTX c;

	SHA256_Init(&c);
	SHA256_Update(&c, "abc", 3);
	SHA256_Final(md, &c);
	check("SHA-256 of \"abc\"", md, want, 32);

	/* And in three pieces, so the buffering path is used too. */
	SHA256_Init(&c);
	SHA256_Update(&c, "a", 1);
	SHA256_Update(&c, "b", 1);
	SHA256_Update(&c, "c", 1);
	SHA256_Final(md, &c);
	check("SHA-256 of \"abc\", one byte at a time", md, want, 32);
}

/* ---- 2. HMAC-SHA256. RFC 4231 test case 1. ---- */
static void
test_hmac(void)
{
	static const unsigned char key[20] = {
		0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,
		0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,
	};
	static const unsigned char want[32] = {
		0xb0,0x34,0x4c,0x61,0xd8,0xdb,0x38,0x53,
		0x5c,0xa8,0xaf,0xce,0xaf,0x0b,0xf1,0x2b,
		0x88,0x1d,0xc2,0x00,0xc9,0x83,0x3d,0xa7,
		0x26,0xe9,0x37,0x6c,0x2e,0x32,0xcf,0xf7,
	};
	unsigned char out[32];
	unsigned int outlen = 0;

	if (HMAC(EVP_sha256(), key, sizeof(key),
	    (const unsigned char *)"Hi There", 8, out, &outlen) == NULL
	    || outlen != 32) {
		check("HMAC-SHA256, RFC 4231 case 1", NULL, want, 32);
		return;
	}
	check("HMAC-SHA256, RFC 4231 case 1", out, want, 32);
}

/* ---- 3. HKDF-SHA256. RFC 5869 test case 1. ---- */
static void
test_hkdf(void)
{
	static const unsigned char ikm[22] = {
		0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,
		0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,
	};
	static const unsigned char salt[13] = {
		0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
		0x08,0x09,0x0a,0x0b,0x0c,
	};
	static const unsigned char info[10] = {
		0xf0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,0xf7,0xf8,0xf9,
	};
	static const unsigned char want[42] = {
		0x3c,0xb2,0x5f,0x25,0xfa,0xac,0xd5,0x7a,0x90,0x43,
		0x4f,0x64,0xd0,0x36,0x2f,0x2a,0x2d,0x2d,0x0a,0x90,
		0xcf,0x1a,0x5a,0x4c,0x5d,0xb0,0x2d,0x56,0xec,0xc4,
		0xc5,0xbf,0x34,0x00,0x72,0x08,0xd5,0xb8,0x87,0x18,
		0x58,0x65,
	};
	unsigned char out[42];

	if (!HKDF(out, sizeof(out), EVP_sha256(), ikm, sizeof(ikm),
	    salt, sizeof(salt), info, sizeof(info))) {
		check("HKDF-SHA256, RFC 5869 case 1", NULL, want, 42);
		return;
	}
	check("HKDF-SHA256, RFC 5869 case 1", out, want, 42);
}

/*
 * ---- 4. ChaCha20. RFC 8439 section 2.4.2. ----
 *
 * The RFC splits the 128-bit block position into a 32-bit counter and a
 * 96-bit nonce. LibreSSL's CRYPTO_chacha_20 keeps the original ChaCha
 * split -- a 64-bit counter and a 64-bit iv -- so the same block is
 * addressed by putting the RFC's first four nonce bytes, read little
 * endian, in the top half of the counter and passing the remaining
 * eight as the iv. That is exactly what e_chacha20poly1305.c does:
 *
 *   ctr = (uint64_t)((uint32_t)(nonce[0]) | ... << 24) << 32;
 *   iv = nonce + CHACHA20_CONSTANT_LEN;
 *
 * so if this case fails while the AEAD case below passes, suspect this
 * translation and not the cipher.
 */
static void
test_chacha20(void)
{
	static const unsigned char key[32] = {
		0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
		0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
		0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,
		0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,
	};
	/* nonce 00:00:00:00 00:00:00:4a 00:00:00:00, block counter 1.
	   Note this is NOT section 2.3.2's nonce, which has 09 in the
	   fourth byte -- 2.3.2 and 2.4.2 differ there, and using 2.3.2's
	   here gives a completely different keystream. */
	static const unsigned char iv[8] = {
		0x00,0x00,0x00,0x4a,0x00,0x00,0x00,0x00,
	};
	static const char pt[] =
	    "Ladies and Gentlemen of the class of '99: If I could offer you "
	    "only one tip for the future, sunscreen would be it.";
	static const unsigned char want[114] = {
		0x6e,0x2e,0x35,0x9a,0x25,0x68,0xf9,0x80,0x41,0xba,
		0x07,0x28,0xdd,0x0d,0x69,0x81,0xe9,0x7e,0x7a,0xec,
		0x1d,0x43,0x60,0xc2,0x0a,0x27,0xaf,0xcc,0xfd,0x9f,
		0xae,0x0b,0xf9,0x1b,0x65,0xc5,0x52,0x47,0x33,0xab,
		0x8f,0x59,0x3d,0xab,0xcd,0x62,0xb3,0x57,0x16,0x39,
		0xd6,0x24,0xe6,0x51,0x52,0xab,0x8f,0x53,0x0c,0x35,
		0x9f,0x08,0x61,0xd8,0x07,0xca,0x0d,0xbf,0x50,0x0d,
		0x6a,0x61,0x56,0xa3,0x8e,0x08,0x8a,0x22,0xb6,0x5e,
		0x52,0xbc,0x51,0x4d,0x16,0xcc,0xf8,0x06,0x81,0x8c,
		0xe9,0x1a,0xb7,0x79,0x37,0x36,0x5a,0xf9,0x0b,0xbf,
		0x74,0xa3,0x5b,0xe6,0xb4,0x0b,0x8e,0xed,0xf2,0x78,
		0x5e,0x42,0x87,0x4d,
	};
	unsigned char out[114];
	uint64_t ctr;

	/* nonce[0..3] is all zero here, so the top half of the counter is
	   zero and only the block counter, 1, remains. */
	ctr = 1;

	CRYPTO_chacha_20(out, (const unsigned char *)pt, 114, key, iv, ctr);
	check("ChaCha20 keystream, RFC 8439 2.4.2", out, want, 114);
}

/* ---- 5. Poly1305. RFC 8439 section 2.5.2. ---- */
static void
test_poly1305(void)
{
	static const unsigned char key[32] = {
		0x85,0xd6,0xbe,0x78,0x57,0x55,0x6d,0x33,
		0x7f,0x44,0x52,0xfe,0x42,0xd5,0x06,0xa8,
		0x01,0x03,0x80,0x8a,0xfb,0x0d,0xb2,0xfd,
		0x4a,0xbf,0xf6,0xaf,0x41,0x49,0xf5,0x1b,
	};
	static const char msg[] = "Cryptographic Forum Research Group";
	static const unsigned char want[16] = {
		0xa8,0x06,0x1d,0xc1,0x30,0x51,0x36,0xc6,
		0xc2,0x2b,0x8b,0xaf,0x0c,0x01,0x27,0xa9,
	};
	unsigned char mac[16];
	poly1305_context ctx;
	size_t i;

	CRYPTO_poly1305_init(&ctx, key);
	CRYPTO_poly1305_update(&ctx, (const unsigned char *)msg, 34);
	CRYPTO_poly1305_finish(&ctx, mac);
	check("Poly1305 tag, RFC 8439 2.5.2", mac, want, 16);

	/* Again a byte at a time: the leftover buffer in poly1305-donna is
	   a separate path from the whole-block loop, and 34 bytes is two
	   blocks plus two, so both are used either way. */
	CRYPTO_poly1305_init(&ctx, key);
	for (i = 0; i < 34; i++)
		CRYPTO_poly1305_update(&ctx, (const unsigned char *)msg + i, 1);
	CRYPTO_poly1305_finish(&ctx, mac);
	check("Poly1305 tag, one byte at a time", mac, want, 16);
}

/* ---- 6. AEAD_CHACHA20_POLY1305. RFC 8439 section 2.8.2. ----
        This is the operation that failed, in both directions. */
static void
test_aead(void)
{
	static const unsigned char key[32] = {
		0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,
		0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,
		0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,
		0x98,0x99,0x9a,0x9b,0x9c,0x9d,0x9e,0x9f,
	};
	static const unsigned char nonce[12] = {
		0x07,0x00,0x00,0x00,
		0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,
	};
	static const unsigned char ad[12] = {
		0x50,0x51,0x52,0x53,0xc0,0xc1,0xc2,0xc3,
		0xc4,0xc5,0xc6,0xc7,
	};
	static const char pt[] =
	    "Ladies and Gentlemen of the class of '99: If I could offer you "
	    "only one tip for the future, sunscreen would be it.";
	static const unsigned char want[130] = {
		/* ciphertext, 114 bytes */
		0xd3,0x1a,0x8d,0x34,0x64,0x8e,0x60,0xdb,0x7b,0x86,
		0xaf,0xbc,0x53,0xef,0x7e,0xc2,0xa4,0xad,0xed,0x51,
		0x29,0x6e,0x08,0xfe,0xa9,0xe2,0xb5,0xa7,0x36,0xee,
		0x62,0xd6,0x3d,0xbe,0xa4,0x5e,0x8c,0xa9,0x67,0x12,
		0x82,0xfa,0xfb,0x69,0xda,0x92,0x72,0x8b,0x1a,0x71,
		0xde,0x0a,0x9e,0x06,0x0b,0x29,0x05,0xd6,0xa5,0xb6,
		0x7e,0xcd,0x3b,0x36,0x92,0xdd,0xbd,0x7f,0x2d,0x77,
		0x8b,0x8c,0x98,0x03,0xae,0xe3,0x28,0x09,0x1b,0x58,
		0xfa,0xb3,0x24,0xe4,0xfa,0xd6,0x75,0x94,0x55,0x85,
		0x80,0x8b,0x48,0x31,0xd7,0xbc,0x3f,0xf4,0xde,0xf0,
		0x8e,0x4b,0x7a,0x9d,0xe5,0x76,0xd2,0x65,0x86,0xce,
		0xc6,0x4b,0x61,0x16,
		/* tag, 16 bytes */
		0x1a,0xe1,0x0b,0x59,0x4f,0x09,0xe2,0x6a,
		0x7e,0x90,0x2e,0xcb,0xd0,0x60,0x06,0x91,
	};
	EVP_AEAD_CTX *ctx;
	unsigned char out[160], back[160];
	size_t outlen = 0, backlen = 0;
	char detail[128];

	if ((ctx = EVP_AEAD_CTX_new()) == NULL) {
		checkbool("EVP_AEAD_CTX_new", 0, NULL);
		return;
	}
	if (!EVP_AEAD_CTX_init(ctx, EVP_aead_chacha20_poly1305(),
	    key, sizeof(key), 16, NULL)) {
		checkbool("EVP_AEAD_CTX_init(chacha20-poly1305)", 0, NULL);
		EVP_AEAD_CTX_free(ctx);
		return;
	}
	checkbool("EVP_AEAD_CTX_init(chacha20-poly1305)", 1, NULL);

	if (!EVP_AEAD_CTX_seal(ctx, out, &outlen, sizeof(out),
	    nonce, sizeof(nonce), (const unsigned char *)pt, 114,
	    ad, sizeof(ad))) {
		checkbool("AEAD seal", 0, "the call failed");
	} else {
		sprintf(detail, "sealed %d bytes, want 130", (int)outlen);
		checkbool("AEAD seal length", outlen == 130, detail);
		if (outlen == 130) {
			check("AEAD ciphertext, RFC 8439 2.8.2", out, want, 114);
			check("AEAD tag, RFC 8439 2.8.2",
			      out + 114, want + 114, 16);
		}
	}

	/* Open the RFC's own ciphertext, not ours: this is the direction
	   that failed, and opening what we just sealed would pass even if
	   both halves were wrong in the same way. */
	if (!EVP_AEAD_CTX_open(ctx, back, &backlen, sizeof(back),
	    nonce, sizeof(nonce), want, 130, ad, sizeof(ad))) {
		checkbool("AEAD open of the RFC's ciphertext", 0,
		    "bad decrypt -- this is the handshake failure, reproduced");
	} else {
		sprintf(detail, "opened %d bytes, want 114", (int)backlen);
		checkbool("AEAD open length", backlen == 114, detail);
		if (backlen == 114)
			check("AEAD plaintext", back,
			      (const unsigned char *)pt, 114);
	}

	EVP_AEAD_CTX_free(ctx);
}

/* ---- 7. AES-128-GCM, for contrast. ----
        TLS 1.3's other cipher. If this passes and chacha20-poly1305
        fails, "curl --ciphers" onto an AES suite is a usable stopgap;
        if both fail, look further down, at SHA-256 and HKDF above. */
static void
test_aesgcm(void)
{
	/* NIST GCM test case 2: 16 zero bytes of plaintext, zero key/IV. */
	static const unsigned char key[16] = { 0 };
	static const unsigned char nonce[12] = { 0 };
	static const unsigned char pt[16] = { 0 };
	static const unsigned char want[32] = {
		0x03,0x88,0xda,0xce,0x60,0xb6,0xa3,0x92,
		0xf3,0x28,0xc2,0xb9,0x71,0xb2,0xfe,0x78,
		0xab,0x6e,0x47,0xd4,0x2c,0xec,0x13,0xbd,
		0xf5,0x3a,0x67,0xb2,0x12,0x57,0xbd,0xdf,
	};
	EVP_AEAD_CTX *ctx;
	unsigned char out[64];
	size_t outlen = 0;

	if ((ctx = EVP_AEAD_CTX_new()) == NULL) {
		checkbool("EVP_AEAD_CTX_new", 0, NULL);
		return;
	}
	if (!EVP_AEAD_CTX_init(ctx, EVP_aead_aes_128_gcm(),
	    key, sizeof(key), 16, NULL)) {
		checkbool("EVP_AEAD_CTX_init(aes-128-gcm)", 0, NULL);
		EVP_AEAD_CTX_free(ctx);
		return;
	}
	if (!EVP_AEAD_CTX_seal(ctx, out, &outlen, sizeof(out),
	    nonce, sizeof(nonce), pt, sizeof(pt), NULL, 0)) {
		checkbool("AES-128-GCM seal", 0, "the call failed");
	} else if (outlen != 32) {
		checkbool("AES-128-GCM seal length", 0, NULL);
	} else
		check("AES-128-GCM, NIST case 2", out, want, 32);

	EVP_AEAD_CTX_free(ctx);
}

int
main(void)
{
	printf("--- hash and key derivation (a wrong key here fails the\n"
	       "--- AEAD below with exactly the handshake's symptom)\n");
	test_sha256();
	test_hmac();
	test_hkdf();

	printf("\n--- the primitives of TLS_CHACHA20_POLY1305_SHA256\n");
	test_chacha20();
	test_poly1305();

	printf("\n--- the AEAD itself: e_chacha20poly1305.c:223 is the open\n");
	test_aead();

	printf("\n--- the other TLS 1.3 cipher, for contrast\n");
	test_aesgcm();

	if (failures) {
		printf("\n%d failure(s). The FIRST one is the bug; the rest\n"
		       "follow from it. If none of these fail, the primitives\n"
		       "are sound and the fault is in the TLS 1.3 key schedule\n"
		       "or the record-layer nonce, above everything tested here.\n",
		       failures);
	} else
		printf("\nall ok\n");
	return failures;
}
