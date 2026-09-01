/*
 * locale-test.c -- setlocale reports the locale it actually set.
 *
 * Plan 9 has one locale, so APExp's setlocale changes no behaviour
 * whatever it is asked for. That is fine. What is not fine is lying
 * about the name: C99 7.11.1.1p8 says the return value is a string
 * associated with the specified locale for that category, and that
 * passing it back later restores that part of the locale. Callers test
 * it, because it is the only way to find out whether the request took.
 *
 * APExp's stub used to ignore the name and answer "C.UTF-8" to
 * everything. perl noticed:
 *
 *	locale.c: 3441: panic: Can't change locale for LC_NUMERIC (4)
 *	  from 'C.UTF-8' to 'C'
 *	Called via locale.c: 3622
 *	Called by locale.c: 3596
 *
 * Perl_set_numeric_standard pins LC_NUMERIC to "C" so that the radix
 * character is a dot regardless of LC_CTYPE -- so it is exactly the
 * case where one category's name must differ from the rest, and where
 * an answer of "everything is C.UTF-8" is visibly wrong. miniperl died
 * before running a line of perl.
 *
 * Every case below is required by C99 or POSIX of any conforming
 * setlocale, so this passes on a glibc host too; that is how it was
 * checked.
 *
 * Build and run:  pcc -o locale-test locale-test.c
 * Prints "PASS" per case; exit status is the number of failures.
 */

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static const char *
show(const char *s)
{
	return s ? s : "(null)";
}

/* setlocale may return a pointer into storage a later call overwrites,
   so anything kept across calls has to be copied. */
static char *
keep(const char *s)
{
	char *p;

	if (!s)
		return NULL;
	p = malloc(strlen(s) + 1);
	if (!p) {
		printf("FAIL  out of memory\n");
		exit(1);
	}
	strcpy(p, s);
	return p;
}

int
main(void)
{
	const char *r;
	char *start, *afterempty;
	char detail[512];

	/*
	 * 1. C99 7.11.1.1p4: at program startup the equivalent of
	 *    setlocale(LC_ALL, "C") has been executed.
	 */
	r = setlocale(LC_ALL, NULL);
	sprintf(detail, "got %s", show(r));
	check("startup locale is C", r && strcmp(r, "C") == 0, detail);
	start = keep(r);

	/*
	 * 2. A set returns the name that was set, not some other name
	 *    the implementation would rather have. This is the one perl
	 *    fell over.
	 */
	r = setlocale(LC_NUMERIC, "C");
	sprintf(detail, "got %s, wanted C", show(r));
	check("setlocale(LC_NUMERIC, \"C\") returns C",
	    r && strcmp(r, "C") == 0, detail);

	/*
	 * 3. A query returns what was set.
	 */
	r = setlocale(LC_NUMERIC, NULL);
	sprintf(detail, "got %s, wanted C", show(r));
	check("querying LC_NUMERIC returns C", r && strcmp(r, "C") == 0,
	    detail);

	/*
	 * 4. An unknown category fails rather than succeeding vaguely.
	 *    -1 is not a category on any implementation.
	 */
	r = setlocale(-1, "C");
	sprintf(detail, "got %s", show(r));
	check("an unknown category returns NULL", r == NULL, detail);

	/*
	 * 5. "" is the native locale. Whatever it turns out to be, the
	 *    category must then report that same name back -- this is
	 *    what a program does at startup and then checks.
	 */
	r = setlocale(LC_CTYPE, "");
	if (!r) {
		check("setlocale(LC_CTYPE, \"\") succeeds", 0,
		    "returned NULL; the native locale must exist");
		afterempty = NULL;
	} else {
		afterempty = keep(r);
		r = setlocale(LC_CTYPE, NULL);
		sprintf(detail, "set gave %s, query gave %s", afterempty,
		    show(r));
		check("LC_CTYPE query agrees with the \"\" that set it",
		    r && strcmp(r, afterempty) == 0, detail);
	}

	/*
	 * 6. Categories are independent: 5 must not have disturbed the
	 *    LC_NUMERIC that 2 set. perl relies on precisely this --
	 *    LC_CTYPE follows the environment while LC_NUMERIC stays C.
	 */
	r = setlocale(LC_NUMERIC, NULL);
	sprintf(detail, "got %s, wanted C", show(r));
	check("LC_NUMERIC still C after LC_CTYPE changed",
	    r && strcmp(r, "C") == 0, detail);

	/*
	 * 7. C99 7.11.1.1p8: the string a query returns can be given
	 *    back to setlocale to restore that state. With two
	 *    categories deliberately differing, this exercises whatever
	 *    composite form LC_ALL uses.
	 */
	{
		char *composite = keep(setlocale(LC_ALL, NULL));

		if (!composite)
			check("LC_ALL query with mixed categories", 0,
			    "returned NULL");
		else {
			r = setlocale(LC_ALL, "C");
			sprintf(detail, "got %s", show(r));
			check("setlocale(LC_ALL, \"C\") returns C",
			    r && strcmp(r, "C") == 0, detail);

			r = setlocale(LC_ALL, composite);
			sprintf(detail, "restoring %s gave %s", composite,
			    show(r));
			check("the LC_ALL query string can be set back",
			    r != NULL, detail);

			r = setlocale(LC_NUMERIC, NULL);
			sprintf(detail, "after restoring %s, LC_NUMERIC is"
			    " %s", composite, show(r));
			check("restoring brings LC_NUMERIC back to C",
			    r && strcmp(r, "C") == 0, detail);

			free(composite);
		}
	}

	/*
	 * 8. Back to where we started, which must also be settable.
	 */
	r = setlocale(LC_ALL, start);
	sprintf(detail, "setting %s gave %s", start, show(r));
	check("the startup locale can be restored", r != NULL, detail);

	free(start);
	free(afterempty);

	if (failures == 0)
		printf("\nall locale cases passed\n");
	else
		printf("\n%d locale case%s failed\n", failures,
		    failures == 1 ? "" : "s");
	return failures;
}
