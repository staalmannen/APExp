/*
 * A format specifier with no argument left must produce nothing.
 *
 * GNU m4's format() builtin is one line, src/format.c:378:
 *
 *	str = xasprintf(fstart, width, prec, ARG_STR(argc, argv));
 *
 * with
 *
 *	#define ARG_STR(argc, argv) \
 *		((argc == 0) ? "" : \
 *		 (--argc, argv++, TOKEN_DATA_TEXT(argv[-1])))
 *
 * and fstart always carrying an explicit width and precision, so a
 * plain %s is emitted as "%*.*s" with width 0 and precision -1.  Run
 * out of arguments and ARG_STR must answer the empty string.
 *
 * Under APExp it answered the *previous* argument again.  bison's
 * skeleton relies on the standard behaviour -- data/skeletons/c.m4:557
 * formats "%s = %s%s%s" with three arguments, the last of which is the
 * separating comma or nothing:
 *
 *	YYEOF = 0,,		     (wrong -- two commas)
 *	YYEOF = 0,		     (right)
 *
 * so every token in every generated parser came out with a doubled
 * comma.  The Portable Object Compiler was the first thing to notice,
 * because it parses the y.tab.c bison writes:
 *
 *	y.tab.c:138: fatal: syntax error ","
 *
 * kencc and the C compilers that came before it accept ", ," in an
 * enumerator list about as often as they reject it, so this is exactly
 * the kind of corruption that shows up somewhere else entirely.
 *
 * Two halves, and the test separates them:
 *   - printf's "%*.*s" with a zero width and a negative precision,
 *     which C99 7.19.6.1p5 says are the same as not giving either;
 *   - the ARG_STR idiom itself: a comma expression inside the second
 *     arm of a conditional, evaluated as an argument to a variadic
 *     function, whose side effects on the enclosing argc/argv must
 *     happen exactly once per call and must not happen at all when the
 *     first arm is taken.
 *
 * Correct on gcc, which is where the expected values below come from.
 */

#include <stdio.h>
#include <string.h>

static int failures;

static void
check(const char *what, const char *got, const char *want)
{
	if(strcmp(got, want) == 0){
		printf("PASS %s: \"%s\"\n", what, got);
	}else{
		printf("FAIL %s: got \"%s\", want \"%s\"\n", what, got, want);
		failures++;
	}
}

static void
checkn(const char *what, int got, int want)
{
	if(got == want){
		printf("PASS %s: %d\n", what, got);
	}else{
		printf("FAIL %s: got %d, want %d\n", what, got, want);
		failures++;
	}
}

/* m4's macro, with TOKEN_DATA_TEXT collapsed to the array element. */
#define ARG_STR(argc, argv) \
	((argc == 0) ? "" : \
	 (--argc, argv++, argv[-1]))

/*
 * Fetch n arguments the way expand_format's loop does, joining them
 * with '|' so an argument taken twice, or skipped, is visible.  argc
 * and argv are the function's own parameters, which is what the macro
 * assumes.
 */
static void
fetch(char *out, size_t outlen, int argc, char **argv, int n)
{
	int i;

	out[0] = '\0';
	for(i = 0; i < n; i++){
		if(i > 0)
			strncat(out, "|", outlen - strlen(out) - 1);
		strncat(out, ARG_STR(argc, argv), outlen - strlen(out) - 1);
	}
}

/* The same, through a variadic call, which is m4's actual shape. */
static void
fetchf(char *out, size_t outlen, int argc, char **argv, int n)
{
	char one[64];
	int i;

	out[0] = '\0';
	for(i = 0; i < n; i++){
		if(i > 0)
			strncat(out, "|", outlen - strlen(out) - 1);
		snprintf(one, sizeof one, "%*.*s", 0, -1,
			ARG_STR(argc, argv));
		strncat(out, one, outlen - strlen(out) - 1);
	}
}

int
main(void)
{
	char buf[256];
	char *args[3];

	/* 1. printf: zero width and negative precision are "not given". */
	snprintf(buf, sizeof buf, "%*.*s", 0, -1, ",");
	check("%*.*s of \",\"", buf, ",");

	snprintf(buf, sizeof buf, "%*.*s", 0, -1, "");
	check("%*.*s of \"\"", buf, "");

	snprintf(buf, sizeof buf, "%*.*s", 0, -1, "abc");
	check("%*.*s of \"abc\"", buf, "abc");

	snprintf(buf, sizeof buf, "[%*.*s]", 5, -1, "abc");
	check("%*.*s width 5", buf, "[  abc]");

	snprintf(buf, sizeof buf, "[%-*.*s]", 5, -1, "abc");
	check("%-*.*s width 5", buf, "[abc  ]");

	snprintf(buf, sizeof buf, "%*.*d", 0, -1, 42);
	check("%*.*d of 42", buf, "42");

	/* 2. ARG_STR: each argument once, then nothing. */
	args[0] = "YYEOF";
	args[1] = "0";
	args[2] = ",";

	fetch(buf, sizeof buf, 3, args, 3);
	check("ARG_STR, 3 of 3", buf, "YYEOF|0|,");

	fetch(buf, sizeof buf, 3, args, 4);
	check("ARG_STR, 4 of 3", buf, "YYEOF|0|,|");

	fetch(buf, sizeof buf, 3, args, 6);
	check("ARG_STR, 6 of 3", buf, "YYEOF|0|,|||");

	fetch(buf, sizeof buf, 0, args, 2);
	check("ARG_STR, 2 of 0", buf, "|");

	/* 3. The same through a variadic call. */
	fetchf(buf, sizeof buf, 3, args, 4);
	check("ARG_STR via printf, 4 of 3", buf, "YYEOF|0|,|");

	/* 4. What bison's c.m4:557 actually asks for. */
	fetchf(buf, sizeof buf, 3, args, 3);
	check("bison c.m4 token, not last", buf, "YYEOF|0|,");

	args[2] = "";
	fetchf(buf, sizeof buf, 3, args, 3);
	check("bison c.m4 token, last", buf, "YYEOF|0|");

	/*
	 * 5. snprintf's return is the length it would have written,
	 * not the length it did (C99 7.19.6.5p3).  The two-pass idiom
	 * -- measure, allocate, format again -- is built on it, and
	 * gets a silent truncation instead of a second pass when the
	 * count comes back clamped.
	 *
	 * gcc warns about the deliberate truncations here
	 * (-Wformat-truncation); that is it agreeing with the test.
	 */
	{
		int n;

		strcpy(buf, "untouched");
		n = snprintf(buf, 4, "%s", "abcdefg");
		checkn("snprintf return, truncated", n, 7);
		check("snprintf buffer, truncated", buf, "abc");

		n = snprintf(NULL, 0, "%s", "abcdefg");
		checkn("snprintf return, sizing pass", n, 7);

		strcpy(buf, "untouched");
		n = snprintf(buf, 1, "x");
		checkn("snprintf return, room for NUL only", n, 1);
		check("snprintf buffer, room for NUL only", buf, "");

		strcpy(buf, "untouched");
		n = snprintf(buf, sizeof buf, "%s", "");
		checkn("snprintf return, empty", n, 0);
		check("snprintf buffer, empty", buf, "");
	}

	printf("%d failure(s)\n", failures);
	return failures;
}
