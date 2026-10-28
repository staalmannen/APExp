/*
 * cppskip-probe.c -- does kencc's cpp LEX a block it is skipping?
 *
 *	pcc -c cppskip-probe.c
 *
 * ***SPLIT OUT OF `cppelif-probe.c' BECAUSE IT KILLED IT.***  The first
 * run answered
 *
 *	cpp: cppelif-probe.c:126 Unterminated string or char const
 *	cc: 6c: cpp 414322: errors
 *
 * -- line 126 being this file's `don't "start a...' line, **inside an
 * arm that is not taken**.  So the answer to THIS question is already
 * known and it is yes: *kencc's cpp tokenises a block it is skipping,
 * and an unterminated quote in there is a hard error even though the
 * code is discarded.*  gcc only warns.
 *
 * ***AND THE ABORT IS WHY THIS FILE EXISTS SEPARATELY.***  cpp stopped
 * at that line, so `cc' never ran `6c' -- which means the OTHER cases
 * in `cppelif-probe.c' were not cleared by that run, only unreported.
 * A reader who saw "cases 1 and 2 got past" would have been reading an
 * abort as a pass.  **Every case that can kill the preprocessor
 * belongs in its own file**, which is the same rule this tree already
 * has about cases that can hang: *order and isolation are part of the
 * instrument, not tidiness.*
 *
 * WHAT IT COSTS IN PRACTICE: any `#if 0' or untaken arm anywhere in
 * the tree containing an apostrophe in prose -- `don't', `doesn't' --
 * or an unbalanced quote is a compile error under kencc and fine
 * everywhere else.  That is worth knowing before writing a comment
 * inside one.
 *
 * gcc is the control: it compiles this with one warning
 * (`missing terminating ' character') and no error.
 */

int ok3;

/* CASE 3: a skipped arm holding an apostrophe and an unbalanced quote.
 * A skipped block still has to be tokenised far enough to find the
 * `#endif', and that is where a lexer gets it wrong if it does. */
void
skipcase(int *dst, int ax)
{
#ifdef APEXP_PROBE_NEVER_A
	dst[0] = ax;
#elif defined(APEXP_PROBE_NEVER_B)
	don't "start a string that never ends
#else
	dst[0] = ax;
#endif
	ok3 = 1;
}
