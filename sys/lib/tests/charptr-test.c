/*
 * charptr-test.c -- char * against unsigned char * across a prototype.
 *
 * "char *" and "unsigned char *" are distinct types, so passing one
 * where the other is declared is a constraint violation and C requires
 * a diagnostic. gcc and clang give a warning -- -Wpointer-sign, not in
 * -Werror by default -- and kencc used to give an error:
 *
 *   a_object.c:185 argument prototype mismatch "IND CHAR" for
 *     "IND CONST UCHAR": CBB_add_bytes
 *
 * from LibreSSL's
 *
 *   char s[22];
 *   n = snprintf(s, sizeof(s), fmt, arc);
 *   if (!CBB_add_bytes(cbb, s, n))
 *
 * against "int CBB_add_bytes(CBB *, const uint8_t *, size_t)". Portable
 * C is full of this and there is no spelling that avoids a cast at every
 * call, so cc/sub.c now warns rather than refusing -- see charptrsign()
 * there.
 *
 * The point of this file is that it has to COMPILE. Everything in it is
 * a constraint violation of exactly that shape; if the relaxation is
 * ever lost, this stops building rather than failing at run time. The
 * value checks confirm the obvious -- that a relaxation which changes
 * no representation changes no behaviour.
 *
 * -Wpointer-sign is not about char, though the name of this file is:
 * it is any integer type against its own opposite signedness. LibreSSL
 * hit the int case next --
 *
 *   e_sm4.c:241 argument prototype mismatch "IND INT" for "IND UINT":
 *     CRYPTO_ctr128_encrypt
 *
 * from passing "&ctx->num", an int *, to a "unsigned int *num"
 * parameter -- so short, int, long and long long are covered below too.
 *
 * Deliberately NOT here, because they must stay errors: "char **" for
 * "unsigned char **", which is the case where the difference can be
 * observed; any pointer of a different width; and "int *" for
 * "unsigned long *", which are the same width here but are not each
 * other's signed/unsigned spelling, so gcc calls them incompatible
 * pointer types rather than a signedness difference.
 *
 * Build and run:  pcc -o charptr-test charptr-test.c
 * Prints "PASS" per case; exit status is the number of failures.
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

static int failures;

/* Static initializers go through a different path in the compiler --
   dcl.c's init1, not stcompat -- and needed the same relaxation. This is
   apps/openssl/s_client.c's shape: an "unsigned int" whose address is
   stored in an "int *" member of a file-scope aggregate.

	s_client.c:540 initialization of incompatible pointers:
	  s_client_options / IND INT and IND UINT

   These have to be at file scope, and const-qualified members like the
   real thing, for the static path to be the one taken. */
static unsigned int cfg_off = 7;
static int cfg_af = 9;

struct sopt {
	const char *name;
	union {
		int *value;
		unsigned int *uvalue;
	} opt;
	const int flags;
};

static const struct sopt sopts[] = {
	{ .name = "off",  .opt.value = &cfg_off, .flags = 1 },
	{ .name = "af",   .opt.uvalue = &cfg_af, .flags = 2 },
	{ NULL },
};

/* And the plain, non-aggregate static case. */
static int *const p_to_unsigned = &cfg_off;
static unsigned int *const p_to_signed = &cfg_af;

static void
check(const char *what, int ok, const char *detail)
{
	if (ok)
		printf("PASS  %s\n", what);
	else {
		printf("FAIL  %s%s%s\n", what, detail ? ": " : "",
		       detail ? detail : "");
		failures++;
	}
}

/* The shape LibreSSL uses: a const unsigned char * parameter. */
static unsigned long
sum_u(const unsigned char *p, size_t n)
{
	unsigned long t = 0;
	size_t i;

	for (i = 0; i < n; i++)
		t += p[i];
	return t;
}

/* And the mirror: a plain char * parameter. */
static unsigned long
sum_c(const char *p, size_t n)
{
	unsigned long t = 0;
	size_t i;

	for (i = 0; i < n; i++)
		t += (unsigned char)p[i];
	return t;
}

static int
takes_uchar(unsigned char *p)
{
	p[0] = 'z';
	return p[0];
}

static int
takes_char(char *p)
{
	p[0] = 'y';
	return p[0];
}

/* The wider types, in the shape CRYPTO_ctr128_encrypt uses: a pointer
   the callee increments. One of each signedness for every width. */
static int		bump_i(int *p)			{ return ++*p; }
static unsigned int	bump_u(unsigned int *p)		{ return ++*p; }
static int		bump_sh(short *p)		{ return ++*p; }
static int		bump_ush(unsigned short *p)	{ return ++*p; }
static long		bump_l(long *p)			{ return ++*p; }
static unsigned long	bump_ul(unsigned long *p)	{ return ++*p; }
static long long	bump_ll(long long *p)		{ return ++*p; }
static unsigned long long bump_ull(unsigned long long *p)	{ return ++*p; }

int
main(void)
{
	char cbuf[8];
	unsigned char ubuf[8];
	char detail[128];
	unsigned long a, b;

	memcpy(cbuf, "abcdefg", 8);
	memcpy(ubuf, "abcdefg", 8);

	/* char * for const unsigned char *, which is a_object.c's case. */
	a = sum_u(cbuf, 7);
	b = sum_c(cbuf, 7);
	sprintf(detail, "%lu vs %lu", a, b);
	check("char * passed as const unsigned char *", a == b && a == 700, detail);

	/* unsigned char * for const char *, the other direction. */
	a = sum_c(ubuf, 7);
	sprintf(detail, "%lu", a);
	check("unsigned char * passed as const char *", a == 700, detail);

	/* Non-const, and written through: the pointee is one byte either
	   way, so the store lands in the same place. */
	check("char * passed as unsigned char *",
	      takes_uchar(cbuf) == 'z' && cbuf[0] == 'z', "store went astray");
	check("unsigned char * passed as char *",
	      takes_char(ubuf) == 'y' && ubuf[0] == 'y', "store went astray");

	/* Assignment and initialisation, not just argument passing --
	   stcompat is reached through tasign for these too. */
	{
		unsigned char *up = cbuf;
		char *cp = ubuf;

		check("unsigned char * = char *", (void *)up == (void *)cbuf, NULL);
		check("char * = unsigned char *", (void *)cp == (void *)ubuf, NULL);
	}

	/* uint8_t is what the LibreSSL prototypes actually say. It is
	   unsigned char here, but go through the typedef in case that
	   ever stops being true. */
	{
		const uint8_t *u8;

		/* takes_uchar above wrote into cbuf; start from a known
		   state rather than depending on the order of the cases. */
		memcpy(cbuf, "abcdefg", 8);
		u8 = cbuf;
		check("char * to const uint8_t *", sum_u(u8, 7) == 700, NULL);
	}

	/* Returning one for the other. */
	check("sizeof(char) == sizeof(unsigned char)",
	      sizeof(char) == 1 && sizeof(unsigned char) == 1, NULL);

	/* The wider integer types, which are the same rule. e_sm4.c's
	   case is the int one: an int * for an "unsigned int *num"
	   parameter, written to by the callee. */
	{
		int num = 3;
		unsigned int unum = 3;
		short sh = 7;
		unsigned short ush = 7;
		long lo = 11;
		unsigned long ulo = 11;
		long long ll = 13;
		unsigned long long ull = 13;

		check("int * passed as unsigned int *",
		      bump_u(&num) == 4 && num == 4, "store went astray");
		check("unsigned int * passed as int *",
		      bump_i(&unum) == 4 && unum == 4, "store went astray");
		check("short * passed as unsigned short *",
		      bump_ush(&sh) == 8 && sh == 8, "store went astray");
		check("unsigned short * passed as short *",
		      bump_sh(&ush) == 8 && ush == 8, "store went astray");
		check("long * passed as unsigned long *",
		      bump_ul(&lo) == 12 && lo == 12, "store went astray");
		check("unsigned long * passed as long *",
		      bump_l(&ulo) == 12 && ulo == 12, "store went astray");
		check("long long * passed as unsigned long long *",
		      bump_ull(&ll) == 14 && ll == 14, "store went astray");
		check("unsigned long long * passed as long long *",
		      bump_ll(&ull) == 14 && ull == 14, "store went astray");

		/* Assignment, and const on the target. */
		{
			const unsigned int *cu = &num;
			unsigned int *u = &num;

			check("unsigned int * = int *", (void *)u == (void *)&num,
			      NULL);
			check("const unsigned int * = int *",
			      (void *)cu == (void *)&num, NULL);
		}
	}

	/* Static initializers -- dcl.c's path rather than stcompat's. The
	   real test is that the file compiled at all; these confirm the
	   addresses landed where they should. */
	sprintf(detail, "opt.value=%p want %p, flags=%d want 1",
	        (void *)sopts[0].opt.value, (void *)&cfg_off, sopts[0].flags);
	check("int * member initialised from an unsigned int *",
	      (void *)sopts[0].opt.value == (void *)&cfg_off
	      && sopts[0].flags == 1, detail);
	sprintf(detail, "opt.uvalue=%p want %p, flags=%d want 2",
	        (void *)sopts[1].opt.uvalue, (void *)&cfg_af, sopts[1].flags);
	check("unsigned int * member initialised from an int *",
	      (void *)sopts[1].opt.uvalue == (void *)&cfg_af
	      && sopts[1].flags == 2, detail);
	check("static int * = &unsigned int",
	      (void *)p_to_unsigned == (void *)&cfg_off, NULL);
	check("static unsigned int * = &int",
	      (void *)p_to_signed == (void *)&cfg_af, NULL);

	if (failures)
		printf("\n%d failure(s)\n", failures);
	else
		printf("\nall ok\n");
	return failures;
}
