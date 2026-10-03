/*
 * regcoll-xcheck -- a HOST program, not a Plan 9 test.
 *
 * It compiles libap's own `regcomp.c'/`regexec.c'/`tre-mem.c' into a
 * glibc program under different names and sweeps both regex engines
 * over collating symbols `[.X.]' and equivalence classes `[=X=]',
 * printing every disagreement.
 *
 * TWO COMPILES, and the reason is the one `ctype-xcheck' and
 * `strftime-xcheck' already carry: **one -I cannot serve both sides.**
 * libap's regex wants APE's `regex.h' for its own `regex_t' and REG_*
 * values, and the checker wants glibc's for the reference engine --
 * and the two disagree about both the struct layout AND the numbers,
 * so a single translation unit cannot hold them. The shim half is
 * compiled with APE's header and talks to the checker through plain
 * `int' and `const char *'.
 *
 *	R=../../src/ape/lib/ap/regex
 *	mkdir -p /tmp/apinc
 *	sed -e '/features.h/d' \
 *	    -e 's|^#include <alltypes.h>|#include <stddef.h>|' \
 *	    ../../include/ape/regex.h > /tmp/apinc/regex.h
 *	for f in regcomp regexec tre-mem; do \
 *	  gcc -c -w -O1 -o /tmp/$f.o -I/tmp/apinc -I$R/../include \
 *	    -Drestrict=__restrict -Dregcomp=ap_regcomp \
 *	    -Dregexec=ap_regexec -Dregfree=ap_regfree $R/$f.c ; done
 *	gcc -c -w -O1 -o /tmp/shim.o -DAP_SHIM -I/tmp/apinc regcoll-xcheck.c
 *	gcc -Wall -o /tmp/regcoll-xcheck regcoll-xcheck.c \
 *	    /tmp/shim.o /tmp/regcomp.o /tmp/regexec.o /tmp/tre-mem.o
 *	/tmp/regcoll-xcheck
 *
 * `regerror.c' is deliberately NOT compiled in: it pulls `musl.h' and
 * so Plan 9's `u.h'. The shim maps APE's error code to a NAME instead,
 * which is what the comparison needs anyway -- **APE's REG_* numbers
 * are its own**, exactly as its errno numbers are, so the two tables
 * can be lined up by name and by nothing else. That is the
 * `strerror-xcheck' lesson in a second place.
 *
 * ------------------------------------------------------------------
 * THE BUG IT CAME FROM.
 *
 * `parse_bracket_terms' answered REG_ECOLLATE for every `[.' and `[='
 * unconditionally -- musl's own line, under the comment "collating
 * symbols and equivalence classes are not supported". Honest for a
 * general locale, needlessly strict for the only locale this engine
 * has: there is no collation table anywhere in TRE, so the C locale is
 * what every comparison already implements, and in the C locale each
 * equivalence class is a SINGLETON. `[[=d=]]' is `[d]'.
 *
 * bash's `cond-regexp2.sub' lines 54-59 is what measured it:
 * `invalid regular expression `[[=d=]]..': Unknown collating element',
 * nine differing lines in `run-cond'.
 *
 * ------------------------------------------------------------------
 * WHAT A CLEAN RUN DOES AND DOES NOT SAY.
 *
 * Section 3 is a CONTROL of the instrument rather than of the library:
 * ordinary brackets with no collation in them, swept the same way. If
 * those disagree, the two engines differ about something unrelated and
 * every other number here is noise. They agree, so the collation
 * sections mean what they say.
 *
 * And the sweep was run against the OLD code before being believed:
 * with the blanket REG_ECOLLATE restored it reports **1652 wrong of
 * 1906** where the fix reports 0, and **section 3 stays at 0 in both
 * runs** -- which is the half that matters, since a control that moved
 * when the collation code changed would not be a control at all.
 * *A check that cannot fail is not a check.*
 *
 * The sweep also CORRECTED THE FIX TWICE, which is why it exists
 * rather than a handful of hand-picked cases:
 *   - `[[=d=]-z]' was accepted and glibc answers REG_ERANGE. An
 *     equivalence class names a SET, so it has no position in the
 *     order and cannot bound a range; a collating symbol names one
 *     element and can. The first version did not distinguish them.
 *   - `[[.d]]' answered ECOLLATE where glibc says EBRACK. An
 *     unterminated `[.' is an unclosed bracket expression; only a
 *     terminated one naming something unsupported is ECOLLATE.
 * Both were agreed with glibc everywhere else, so reading alone would
 * have shipped them.
 */

#include <stdio.h>
#include <string.h>

#ifdef AP_SHIM

/* ---- compiled with APE's regex.h ---- */
#include <regex.h>

int ap_regcomp(regex_t *, const char *, int);
int ap_regexec(const regex_t *, const char *, size_t, regmatch_t *, int);
void ap_regfree(regex_t *);

/*
 * Map APE's code to a canonical name. Compared by NAME because APE's
 * REG_* numbers are its own -- REG_ECOLLATE is 3 here and 11 on glibc.
 */
static const char *
apname(int e)
{
	switch (e) {
	case 0:                return "OK";
	case REG_BADPAT:       return "BADPAT";
	case REG_ECOLLATE:     return "ECOLLATE";
	case REG_ECTYPE:       return "ECTYPE";
	case REG_EESCAPE:      return "EESCAPE";
	case REG_ESUBREG:      return "ESUBREG";
	case REG_EBRACK:       return "EBRACK";
	case REG_EPAREN:       return "EPAREN";
	case REG_EBRACE:       return "EBRACE";
	case REG_BADBR:        return "BADBR";
	case REG_ERANGE:       return "ERANGE";
	case REG_ESPACE:       return "ESPACE";
	case REG_BADRPT:       return "BADRPT";
	}
	return "OTHER";
}

/*
 * Compile `pat', and if it compiles try it against `text'.
 * Returns the error name; *matched is 1/0 and meaningless on error.
 */
const char *
ap_try(const char *pat, int ext, const char *text, int *matched)
{
	regex_t re;
	int e;

	*matched = -1;
	e = ap_regcomp(&re, pat, ext ? REG_EXTENDED : 0);
	if (e)
		return apname(e);
	*matched = ap_regexec(&re, text, 0, 0, 0) == 0;
	ap_regfree(&re);
	return "OK";
}

#else

/* ---- compiled with glibc's headers ---- */
#include <regex.h>

extern const char *ap_try(const char *pat, int ext, const char *text, int *matched);

static long checked, wrong;

static const char *
glname(int e)
{
	switch (e) {
	case 0:                return "OK";
	case REG_BADPAT:       return "BADPAT";
	case REG_ECOLLATE:     return "ECOLLATE";
	case REG_ECTYPE:       return "ECTYPE";
	case REG_EESCAPE:      return "EESCAPE";
	case REG_ESUBREG:      return "ESUBREG";
	case REG_EBRACK:       return "EBRACK";
	case REG_EPAREN:       return "EPAREN";
	case REG_EBRACE:       return "EBRACE";
	case REG_BADBR:        return "BADBR";
	case REG_ERANGE:       return "ERANGE";
	case REG_ESPACE:       return "ESPACE";
	case REG_BADRPT:       return "BADRPT";
	}
	return "OTHER";
}

static const char *
gl_try(const char *pat, int ext, const char *text, int *matched)
{
	regex_t re;
	int e;

	*matched = -1;
	e = regcomp(&re, pat, ext ? REG_EXTENDED : 0);
	if (e)
		return glname(e);
	*matched = regexec(&re, text, 0, 0, 0) == 0;
	regfree(&re);
	return "OK";
}

static void
ck(const char *pat, const char *text)
{
	const char *a, *g;
	int am, gm, ext;

	for (ext = 0; ext <= 1; ext++) {
		a = ap_try(pat, ext, text, &am);
		g = gl_try(pat, ext, text, &gm);
		checked++;
		/*
		 * Both must agree on whether it compiled, on WHICH error
		 * if not, and on whether it matched if so.
		 */
		if (strcmp(a, g) != 0 || (strcmp(a, "OK") == 0 && am != gm)) {
			wrong++;
			if (wrong <= 25)
				printf("  %-18s %-8s text=%-8s  libap %s/%d  glibc %s/%d\n",
					pat, ext ? "ERE" : "BRE", text, a, am, g, gm);
		}
	}
}

int
main(void)
{
	char pat[64], one[2];
	int c;

	printf("regcoll-xcheck: libap's regcomp against glibc's,"
		" collating symbols and equivalence classes\n\n");

	/*
	 * 1. EVERY printable ASCII character as a one-character collating
	 *    symbol and equivalence class, against itself and against a
	 *    character it must not match. A sweep rather than a handful,
	 *    because the parser handles `]', `-', `.', `=' and `[' through
	 *    the same code as `d' and each is a chance to go wrong.
	 */
	printf("1. [[.X.]] and [[=X=]] for every printable ASCII X\n");
	for (c = 0x20; c < 0x7f; c++) {
		one[0] = c; one[1] = 0;
		sprintf(pat, "[[.%c.]]", c);
		ck(pat, one);
		ck(pat, "Q");
		sprintf(pat, "[[=%c=]]", c);
		ck(pat, one);
		ck(pat, "Q");
		/* and negated, which takes the other arm of the parser */
		sprintf(pat, "[^[.%c.]]", c);
		ck(pat, one);
		ck(pat, "Q");
	}

	/*
	 * 2. In company: beside a literal, beside a class, as a RANGE
	 *    endpoint on each side, and more than one in a bracket. The
	 *    range cases are the reason the parse is a helper rather than
	 *    inline -- they are a second call site.
	 */
	printf("2. in company, and as range endpoints\n");
	{
		static const char *pats[] = {
			"[[=d=]]", "[[.d.]]", "[a[=d=]z]", "[[=d=][=q=]]",
			"[[:alpha:][=d=]]",
			/*
			 * Both sides of a range, for BOTH constructs. An
			 * equivalence class must be refused and a collating
			 * symbol accepted, so asking only one of the four
			 * would leave the rule half measured -- the same
			 * reason `$@' was asked beside `$*' elsewhere.
			 */
			"[[=d=]-z]", "[a-[=z=]]", "[[.d.]-z]", "[a-[.z.]]",
			"[[.a.]-[.f.]]", "[[=a=]-[=f=]]",
			"x[[=d=]]y", "[[=d=]]..",
			"[^[=d=]]", "[^a[.d.]z]", "[[.-.]]", "[[.].]]",
			"[[.^.]]", "[[.[.]]", "[[.\\.]]",
		};
		static const char *txt[] = { "d", "a", "z", "q", "-", "]",
			"^", "[", "\\", "xdy", "d..", "Q" };
		int i, j;
		for (i = 0; i < (int)(sizeof pats/sizeof pats[0]); i++)
			for (j = 0; j < (int)(sizeof txt/sizeof txt[0]); j++)
				ck(pats[i], txt[j]);
	}

	/*
	 * 3. CONTROL OF THE INSTRUMENT. Ordinary brackets, no collation.
	 *    If these disagree the two engines differ about something
	 *    else and sections 1, 2 and 4 are unreadable. They must be 0.
	 */
	printf("3. control: ordinary brackets, no collation involved\n");
	{
		static const char *pats[] = {
			"[d]", "[^d]", "[a-z]", "[^a-z]", "[[:alpha:]]",
			"[]d]", "[-d]", "[d-]", "[a-]", "[[:digit:]a-f]",
			"x[abc]y", "[abc]*", "^[a-z]$",
		};
		static const char *txt[] = { "d", "a", "z", "q", "-", "]",
			"xay", "abc", "" };
		int i, j;
		for (i = 0; i < (int)(sizeof pats/sizeof pats[0]); i++)
			for (j = 0; j < (int)(sizeof txt/sizeof txt[0]); j++)
				ck(pats[i], txt[j]);
	}

	/*
	 * 4. MALFORMED, and the ones that must STAY errors. A fix that
	 *    accepted everything would pass 1 to 3 and fail only here --
	 *    multi-character elements genuinely do not exist in this
	 *    locale and must keep answering ECOLLATE.
	 */
	printf("4. malformed, and multi-character elements that must stay errors\n");
	{
		static const char *pats[] = {
			"[[.ch.]]", "[[=ch=]]", "[[..]]", "[[==]]",
			"[[.d]]", "[[=d]]", "[[.d.", "[[=d=", "[[.",
			"[[=", "[[.d=]]", "[[=d.]]", "[[.abc.]-z]",
		};
		int i;
		for (i = 0; i < (int)(sizeof pats/sizeof pats[0]); i++) {
			ck(pats[i], "d");
			ck(pats[i], "ch");
		}
	}

	printf("\n%ld checked, %ld wrong\n", checked, wrong);
	return wrong != 0;
}

#endif
