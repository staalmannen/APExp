/*
 * asmok-probe.c -- the `__asm__' spellings that must STILL compile.
 *
 *	pcc -c asmok-probe.c	# MUST SUCCEED, silently
 *
 * ***THE CONTROL FOR `asmout-probe.c', AND THE HALF THAT STOPS THE
 * CURE BEING WORSE.***  That file asserts a diagnostic; this one
 * asserts its NARROWNESS.  A compiler that refused every `__asm__'
 * would satisfy `asmout-probe' and fail to build php, which has 50
 * vendored files spelling `__asm__ __volatile__("")'.
 *
 * The rule under test: an asm is refused only when it has an OUTPUT
 * operand -- at depth 1, after the FIRST `:', a constraint string
 * beginning `=' or `+'.  Everything below is outside that.
 *
 * Case 1   a barrier with no operand list at all.  This is php's
 *          `zend_gdb.c:59' shape, and the one that cost a round when
 *          `cc/lex.c' did not know the `__volatile__' qualifier.
 * Case 2   a symbol-rename specifier -- a declaration, no colon.
 * Case 3   INPUTS ONLY.  `:: "r"(x)' has an empty output section, so
 *          nothing is written and there is nothing to lose.  *This is
 *          the case a naive "does it contain a colon" rule gets
 *          wrong*, which is why the test is on the constraint's first
 *          character and not on the colon.
 * Case 4   clobbers only, `::: "memory"' -- two empty sections.
 * Case 5   an input whose constraint contains an `=' that is not
 *          leading, to catch a rule that searched the string rather
 *          than reading its first character.
 *
 * *Nothing here is executed.* Skipping a barrier loses a fence, which
 * is a real deviation and is recorded in 0.6's inventory rather than
 * fixed; what this file asserts is only that it still COMPILES.
 *
 * ***WARNINGS ARE EXPECTED HERE AND ARE NOT FAILURES.***  Cases 3 and
 * 5 pass `x' to an asm that is then swallowed, so kencc reports
 * `set and not used: x' and `param declared and not used: x' -- four
 * lines, and they are the deviation itself showing through rather
 * than a fault in the test. **Read the EXIT STATUS, not the output**:
 * the pass condition is that `pcc -c' succeeds and prints no line
 * containing `output operand'.
 */

/* 1: a bare barrier, both spellings of the qualifier */
void
barrier(void)
{
	__asm__ __volatile__("");
	__asm__ volatile("");
	__asm__("");
}

/* 2: symbol rename on a declaration */
extern int ap_errno __asm__("errno");

/* 3: inputs only -- empty output section */
void
inputs(int x)
{
	__asm__ volatile("nop" :: "r"(x));
}

/* 4: clobbers only -- two empty sections */
void
clobber(void)
{
	__asm__ volatile("" ::: "memory");
}

/* 5: a non-leading `=' in an input constraint */
void
notleading(int x)
{
	__asm__ volatile("nop" :: "r="(x));
}

int
main(void)
{
	/* the file exists to be COMPILED; running it proves nothing */
	return 0;
}
