/*
 * boolptr-test.c -- a POINTER converted to `bool', at each of the four
 * sites that CONVERT rather than cast.
 *
 *	pcc -o boolptr-test boolptr-test.c && ./boolptr-test
 *
 * Correct on gcc too, and checked there first.
 *
 * WHERE IT CAME FROM.  php's `Zend/zend_lazy_objects.c:117' is
 *
 *	static bool zend_lazy_object_has_stale_info(const zend_object *obj)
 *	{
 *		return zend_hash_index_find_ptr(..., obj->handle);
 *	}
 *
 * -- a `void *' returned from a `bool' function, which C99 6.5.16.1
 * allows outright -- and kencc answered `incompatible types: "UCHAR"
 * and "IND VOID" for op "RETURN"'.  **kencc has no TBOOL etype**: bool
 * is unsigned char (`cc/lex.c', `typebool' in `cc/cc.h'), so
 * `tasign[TUCHAR]' is `BNUMBER', which excludes BIND.
 *
 * ***AND THE CONVERSION WAS ALREADY THERE, BEHIND THE CHECK THAT
 * REFUSED THE OPERAND.***  `cc/com.c' calls `boolnorm' -- `!!x', a
 * COMPARISON and not a truncation -- at OAS, OASI, ORETURN and in
 * `tcoma', and all four run `stcompat(..., tasign)' first.  So the fix
 * is one clause in `cc/sub.c's `stcompat' and the four sites then do
 * what they already meant to.  *The CAST form `(bool)p' worked all
 * along*, because `tcast[TUCHAR]' carries BIND.
 *
 * WHY THE VALUES MATTER AND NOT JUST THE COMPILE.  The plausible wrong
 * fix is to let the pointer through as a NUMBER, which keeps the low
 * byte: every pointer whose low byte is zero -- and on a 2MB-aligned
 * mapping that is most of them -- would convert to `false'.  **Sections
 * 1 and 2 exist to separate a compile from a correct conversion**, and
 * use a pointer whose low byte, low two bytes and low four bytes are
 * all zero.  *That is the shape of the perl `cBOOL' bug `boolnorm' was
 * written for, arriving by a different route.*
 *
 * Exit status is the failure count.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int fails;

static void
eq(const char *what, int got, int want)
{
	if(got == want)
		printf("  PASS %-46s %d\n", what, got);
	else {
		printf("  FAIL %-46s got %d want %d\n", what, got, want);
		fails++;
	}
}

/* The four sites.  `q' is opaque to the optimiser on purpose. */
static void *(*opaque)(void);

static bool
by_return(void)
{
	return opaque();
}

static bool
by_init(void)
{
	bool b = opaque();
	return b;
}

static bool
by_assign(void)
{
	bool b;

	b = opaque();
	return b;
}

static bool arg_seen;

static void
sink(bool b)
{
	arg_seen = b;
}

static void
by_argument(void)
{
	sink(opaque());
}

static bool
by_cast(void)
{
	return (bool)opaque();
}

/* ---- the three things `opaque' can answer ------------------- */

static char big[1];

static void *nullp(void) { return 0; }
static void *realp(void) { return big; }

/*
 * A pointer value whose low FOUR bytes are zero.  Not dereferenced --
 * only converted -- so any non-null bit pattern will do, and this one
 * is the pattern a byte-wise or int-wise truncation gets wrong.
 */
static void *alignedp(void) { return (void *)(unsigned long long)0x0000555500000000ULL; }

static int
section(const char *name, void *(*f)(void), int want)
{
	char nm[80];

	opaque = f;
	sprintf(nm, "%s: return", name);  eq(nm, by_return(), want);
	sprintf(nm, "%s: init", name);    eq(nm, by_init(), want);
	sprintf(nm, "%s: assign", name);  eq(nm, by_assign(), want);
	sprintf(nm, "%s: cast", name);    eq(nm, by_cast(), want);
	arg_seen = !want;
	by_argument();
	sprintf(nm, "%s: argument", name); eq(nm, arg_seen, want);
	return 0;
}

int
main(void)
{
	setvbuf(stdout, (char *)0, _IOLBF, 0);
	printf("boolptr-test: a pointer converted to bool\n\n");

	printf("Section 0: a null pointer is false\n");
	section("null", nullp, 0);

	printf("\nSection 1: an ordinary pointer is true\n");
	section("object", realp, 1);

	printf("\nSection 2: a pointer whose low four bytes are ZERO\n");
	/*
	 * ***THIS IS THE SECTION A TRUNCATING CONVERSION FAILS.***  The
	 * value is 0x0000555500000000: non-null, and zero in every byte
	 * a `char', `short' or `int' conversion would keep.
	 */
	section("aligned", alignedp, 1);

	printf("\nboolptr-test: %d failures\n", fails);
	return fails;
}
