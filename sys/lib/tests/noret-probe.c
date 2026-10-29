/*
 * noret-probe.c -- does kencc record NORET when `_Noreturn' arrives
 * through a MACRO expansion?
 *
 *	pcc -c noret-probe.c
 *
 * ***A PROBE, AND ITS RESULT IS WHETHER IT COMPILES***, like
 * `regpair-min' and `cppskip-probe'.  Nobody has promised an answer;
 * report what it prints.  Nothing is run and nothing is installed.
 *
 * WHERE THE QUESTION CAME FROM.  CLISP declares every nonreturning
 * function through one macro (`lispbibl.d:1008'):
 *
 *	#define nonreturning_function(storclass,funname,arguments) \
 *	  storclass _Noreturn void funname arguments
 *
 * and `unix.d:155' is `nonreturning_function(extern_C, exit, (int
 * status));', where `extern_C' is `extern'.  That should expand to
 * exactly what APE's `<stdlib.h>:71' says --
 * `extern __ape_Noreturn void exit(int);', and `__ape_Noreturn' is
 * `_Noreturn'.  **kencc disagreed anyway**:
 *
 *	unix.d:155 external redeclaration of: exit
 *	  EXTERN FUNC(INT) VOID
 *	  EXTERN FUNC(INT) NORET VOID  /sys/include/ape/stdlib.h:71
 *
 * -- no NORET on CLISP's side.  **Everything checkable from the build
 * host says the arm was taken**: `gcc -E -D_PLAN9_SOURCE' over that
 * macro chain yields the `_Noreturn' body; `lex.c:1688' has
 * `"_Noreturn", LNORET'; `cc.y:1562' makes `LNORET' a `gname', the
 * same class as `const' and `volatile'; and the sibling edit in the
 * SAME file, adding `_PLAN9_SOURCE' to `alloca's do-not-redeclare
 * list, demonstrably took effect -- `<alloca.h>' defines no `alloca'
 * macro, so nothing else could have silenced that error.
 *
 * *So `_PLAN9_SOURCE' is visible and the arm is reached, and the
 * declaration still came out without NORET.*  This file is the one
 * run that can separate the remaining possibilities, because there is
 * no kencc on the build host and every statement above about kencc's
 * behaviour is a reading of its source rather than a measurement.
 *
 * ***WHAT A FAILURE MEANS DEPENDS ON WHICH CASE FAILS***, which is
 * why they are numbered and each is alone in what it asserts:
 *
 *   1  `_Noreturn' written out directly, matching <stdlib.h>.
 *      If THIS fails, kencc does not record NORET for the spelling
 *      its own header uses, and the fault is nowhere near CLISP.
 *   2  the same declaration reached through a one-level macro.
 *      If 1 passes and 2 fails, **macro expansion loses the garb
 *      bit**, which is a kencc bug affecting any header that wraps a
 *      noreturn declaration -- far bigger than this port.
 *   3  CLISP's exact two-level shape: a macro whose STORAGE CLASS is
 *      itself a macro (`extern_C').  If 2 passes and 3 fails, the
 *      trouble is the nested expansion rather than expansion as such.
 *   4  the parameter NAMED, since <stdlib.h> writes `(int)' and CLISP
 *      writes `(int status)'.  A long shot, and cheap to exclude.
 *
 * **A clean compile refutes the whole family** and sends the question
 * back to CLISP's own configuration -- in which case the next thing
 * to ask is whether `lispbibl.c' in `build-$objtype' is the one the
 * compile actually read, since this tree's oldest rule is that a
 * measurement of a build that does not contain the change measures
 * nothing.
 *
 * `<stdlib.h>' is included FIRST on purpose: every case below is a
 * re-declaration of a function it has already declared, so kencc has
 * something to disagree with.  Without it the file compiles no matter
 * what and the probe cannot fail -- a check that cannot fail is not a
 * check.
 *
 * **gcc is NOT a control here.** gcc accepts all four without a word,
 * because it does not carry a noreturn bit in the type the way
 * kencc's `-FTVw' signatures do; it says the cases are valid C, not
 * that they agree.  The comparison that matters is kencc against
 * kencc.
 */

#include <stdlib.h>	/* extern __ape_Noreturn void exit(int); */

/* CASE 1: the spelling <stdlib.h> itself uses, written out. */
extern _Noreturn void exit (int);

/* CASE 2: one level of macro. */
#define noret_fn(storclass, funname, arguments) \
	storclass _Noreturn void funname arguments
noret_fn(extern, exit, (int));

/* CASE 3: CLISP's shape -- the storage class is itself a macro. */
#define extern_C extern
noret_fn(extern_C, exit, (int));

/* CASE 4: a named parameter, as unix.d writes it. */
noret_fn(extern_C, exit, (int status));

/* So the file has a definition and the link stage is reachable if
   anyone wants to take it further. */
int noret_probe_ok = 1;
