/*
 * truefalse-test -- C23 `true' and `false' as kencc's own keywords.
 *
 * ***** THIS ONE IS NATIVE, NOT APE. *****
 *
 *	6c truefalse-test.c && 6l -o truefalse-test truefalse-test.6
 *	./truefalse-test
 *
 * AND IT CANNOT BE AN APE TEST, which is the whole reason it exists
 * as a separate file rather than a section of bool-test.c. APE's
 * <stdbool.h> says
 *
 *	#define true  1
 *	#define false 0
 *
 * so in any program built with `pcc' the preprocessor answers before
 * the compiler ever sees the words, and the keywords go untested. A
 * NATIVE build has no <stdbool.h> at all -- `true' and `false' are
 * kencc's own C23 keywords (sys/src/cmd/cc/lex.c, itab) -- so this is
 * the only dialect in which the question can be asked.
 *
 * *A test under sys/lib/tests measures the APE dialect. A bug in the
 * native dialect needs a native test.*
 *
 * ------------------------------------------------------------------
 * THE BUG IT CAME FROM, which was silent and was not small.
 *
 * `itab' in lex.c is
 *
 *	struct { char *name; ushort lexical; ushort type; } itab[]
 *
 * and its third column is a TYPE index, applied by lexinit() as
 * `s->type = types[...]'. `true' and `false' were written into it as
 *
 *	"true",		LCONST,		1,
 *	"false",	LCONST,		0,
 *
 * as though that column were a value. It is not. So `true' set
 * s->type = types[1] and `false' set nothing, and NEITHER set
 * yylval.vval -- which is exactly what the grammar reads for LCONST
 * (cc.y: `$$->vconst = $1'). yylex had already done `yylval.sym = s',
 * and sym and vval are the same union member, so both keywords
 * arrived carrying a pointer reinterpreted as an integer.
 *
 * WHAT IT BROKE. libvterm's VT parser clears its escape flag with
 * `vt->parser.in_esc = false;' in one place and `= 0' in another. The
 * second worked; the first did not. So the parser never left escape
 * state after `ESC [', every CSI sequence consumed exactly three
 * bytes and printed the rest, and a terminal under vts displayed
 * `2004h' instead of enabling bracketed paste.
 *
 * It took two refuted hypotheses to get here -- a bit-field overlap
 * and a bit-field clear bug -- both of which passed their tests
 * because those tests were APE, where `false' is a macro. The
 * measurement that named it was vtlayout-probe.c, asking `= 0' and
 * `= false' side by side on the real struct in the native dialect.
 *
 * NOT bit-field-specific and NOT libvterm-specific: every
 * `x = false', `return true;' and `flag == false' in every native C23
 * program had the same junk in it.
 */

#include <u.h>
#include <libc.h>

static int failures;

static void
check(char *what, int ok, char *detail)
{
	if(ok)
		print("PASS  %s\n", what);
	else {
		print("FAIL  %s%s%s\n", what, detail ? ": " : "",
			detail ? detail : "");
		failures++;
	}
}

/* The shape libvterm has: an enum, then a one-bit bool beside it. */
struct parserish {
	enum { PNORMAL, PCSI_LEADER, PCSI_ARGS } state;
	bool in_esc : 1;
	int intermedlen;
};

void
main(int, char**)
{
	char detail[128];
	bool b;
	int i;
	struct parserish p;

	print("truefalse-test (NATIVE: `true'/`false' are kencc keywords)\n\n");

	/*
	 * 1. The values themselves. If these are wrong nothing below
	 *    means anything, so they come first.
	 */
	i = true;
	sprint(detail, "(int)true = %d", i);
	check("true is 1", i == 1, detail);

	i = false;
	sprint(detail, "(int)false = %d", i);
	check("false is 0", i == 0, detail);

	/* 2. Into a plain bool, both directions. */
	b = false;
	b = true;
	sprint(detail, "b = %d", (int)b);
	check("bool = true sets it", b != 0, detail);

	b = true;
	b = false;
	sprint(detail, "b = %d", (int)b);
	check("bool = false CLEARS it", b == 0, detail);

	/*
	 * 3. THE EXACT SEQUENCE FROM THE BUG: set with the keyword, then
	 *    clear with the keyword, in a one-bit field, with nothing
	 *    numeric lexed in between. That last part matters -- the
	 *    junk `false' carried was whatever the union last held, so a
	 *    constant between the two statements could hide it.
	 */
	memset(&p, 0, sizeof p);
	p.state = PCSI_LEADER;
	p.in_esc = true;
	p.in_esc = false;
	sprint(detail, "in_esc = %d, state = %d", (int)p.in_esc,
		(int)p.state);
	check("bool:1 = false clears, straight after = true", p.in_esc == 0,
		detail);

	/* 4. And with `= 0', which always worked -- the CONTROL that
	 *    tells a broken keyword from a broken bit field. */
	memset(&p, 0, sizeof p);
	p.in_esc = 1;
	p.in_esc = 0;
	sprint(detail, "in_esc = %d", (int)p.in_esc);
	check("bool:1 = 0 clears (control)", p.in_esc == 0, detail);

	/* 5. In a comparison and a return, the other two ways real code
	 *    spells it. */
	b = false;
	check("false compares equal to a cleared bool", b == false, nil);
	b = true;
	check("true compares equal to a set bool", b == true, nil);

	/*
	 * 6. Two keywords in one expression, which is where a stale
	 *    union value is most likely to look right by accident.
	 */
	i = (int)true + (int)false;
	sprint(detail, "true + false = %d", i);
	check("true + false is 1", i == 1, detail);

	print("\n%d failure%s\n", failures, failures == 1 ? "" : "s");
	exits(failures ? "fail" : nil);
}
