/*
 * cppelif-probe.c -- does kencc's cpp actually SKIP the arms it should?
 *
 *	pcc -c cppelif-probe.c
 *
 * ***A PROBE, NOT A TEST.*** Nobody has promised an answer; report what
 * it prints. The result is whether it COMPILES, like `regpair-min'.
 *
 * WHERE THE QUESTION CAME FROM.  `objtype=386 mk install' in
 * `cmd/dist' answered
 *
 *	unix.c:851[stdin:4351] syntax error, last name: volatile
 *	warning: unix.c:841 param declared and not used: ax
 *	warning: unix.c:841 param declared and not used: dst
 *
 * and line 851 is `asm volatile("cpuid"' inside
 *
 *	#ifdef APEXP_PROBE_NEVER_A
 *		... extended asm ...
 *	#elif defined(APEXP_PROBE_NEVER_B)
 *		asm volatile("cpuid" ...	<- line 851
 *	#else
 *		dst[0] = dst[1] = dst[2] = dst[3] = 0;
 *	#endif
 *
 * **kencc defines NEITHER `__i386__' NOR `__x86_64__'** -- it
 * predefines `__STDC__', `_POSIX_SOURCE' and two `__APEXP_*' markers
 * and nothing else -- so the `#else' arm should have been taken and
 * line 851 should never have reached the compiler. *It did.*
 *
 * AND THE WARNINGS DISAGREE WITH EITHER STORY.  `dst' and `ax' are
 * both reported unused at `:841', the opening brace of `__cpuid'. The
 * `#else' arm USES `dst'. So the body the compiler saw was neither the
 * x86 arm (which would not be a syntax error if it were understood)
 * nor the portable one (which uses `dst'). *Two observations that no
 * single arm explains, which is why this is a probe and not a bug
 * report.*
 *
 * THREE CANDIDATES, and this file separates them:
 *
 *   1. cpp mishandles `#elif' after `#ifdef' (as opposed to after
 *      `#if'), and leaks the untaken arm's text.  Case 1 and case 2
 *      below differ in exactly that and nothing else.
 *   2. cpp skips correctly but something about `asm' or the string
 *      continuation inside the skipped arm confuses its lexer -- a
 *      skipped block still has to be TOKENISED well enough to find
 *      `#endif'.  Case 3 puts an unterminated-looking construct in a
 *      skipped arm; case 4 puts `asm volatile' there.
 *   3. Nothing is wrong with cpp and the go diagnostic has another
 *      cause entirely -- in which case every case here compiles and
 *      the question moves back to `unix.c'.
 *
 * **IT COMPILES** -> candidate 3; cpp is fine and `unix.c' needs
 * looking at again with `pcc -E'.
 * **A CASE FAILS** -> that case names the construct, and it is a cpp
 * bug affecting every `#ifdef'/`#elif' chain in the tree, which is far
 * bigger than go.
 *
 * Each case is numbered in its diagnostic by being on its own line, so
 * read the LINE and match it to the comment above it.
 */

/*
 * ***THE MACROS ARE INVENTED, AND THE FIRST DRAFT'S WERE NOT.***
 *
 * This probe first used `__i386__' and `__x86_64__', the real names
 * from `unix.c' -- and gcc rejected it, because **gcc on x86-64
 * defines `__x86_64__'**, so the arm meant to be SKIPPED was taken and
 * the deliberate garbage in it was compiled.  *The probe's behaviour
 * depended on the host it ran on*, which is the one thing an
 * instrument must not do, and checking it against gcc first is what
 * said so -- the rule this tree already carries, paying out on the
 * probe rather than on the tree.
 *
 * `APEXP_PROBE_NEVER_A' and `_B' are defined by nothing, anywhere, so
 * every arm below is skipped on every compiler and the question is
 * purely whether cpp SKIPS correctly.  **gcc compiles this file, which is
 * the control** -- with ONE warning, `missing terminating ' character',
 * from case 3's skipped arm, which is precisely what case 3 is about:
 * gcc notices the unterminated quote while tokenising a block it then
 * correctly discards.  *That warning is the expected output, not a
 * fault.*  A hard ERROR under `pcc' is then kencc's and not the
 * probe's.
 */

int ok1, ok2, ok3, ok4;

/* CASE 1: `#ifdef' then `#elif'.  This is unix.c's exact shape. */
void
case1(int *dst, int ax)
{
#ifdef APEXP_PROBE_NEVER_A
	dst[0] = ax;
#elif defined(APEXP_PROBE_NEVER_B)
	this is not C at all ((( ;
#else
	dst[0] = ax;
#endif
	ok1 = 1;
}

/* CASE 2: `#if defined(...)' then `#elif'.  Differs from case 1 in the
 * FIRST directive only, which is the whole point. */
void
case2(int *dst, int ax)
{
#if defined(APEXP_PROBE_NEVER_A)
	dst[0] = ax;
#elif defined(APEXP_PROBE_NEVER_B)
	this is not C at all ((( ;
#else
	dst[0] = ax;
#endif
	ok2 = 1;
}

/* CASE 3: a skipped arm holding an apostrophe and an unbalanced quote.
 * A skipped block still has to be tokenised far enough to find the
 * `#endif', and that is where a lexer gets it wrong if it does. */
void
case3(int *dst, int ax)
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

/* CASE 4: the actual construct -- `asm volatile' with GCC extended
 * operands -- sitting in a skipped arm.  If only this one fails, the
 * trouble is `asm' and not `#elif'. */
void
case4(int *dst, int ax)
{
#ifdef APEXP_PROBE_NEVER_A
	dst[0] = ax;
#elif defined(APEXP_PROBE_NEVER_B)
	asm volatile("cpuid"
		: "=a" (dst[0]), "=b" (dst[1]), "=c" (dst[2]), "=d" (dst[3])
		: "0" (ax));
#else
	dst[0] = ax;
#endif
	ok4 = 1;
}
