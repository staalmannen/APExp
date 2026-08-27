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
 * Deliberately NOT here, because they must stay errors: "char **" for
 * "unsigned char **", which is the case where the difference can be
 * observed, and any pointer of a different width.
 *
 * Build and run:  pcc -o charptr-test charptr-test.c
 * Prints "PASS" per case; exit status is the number of failures.
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

static int failures;

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

	if (failures)
		printf("\n%d failure(s)\n", failures);
	else
		printf("\nall ok\n");
	return failures;
}
