/*
 * cppaste-probe.c -- which token-paste shape does kencc's cpp get wrong?
 *
 *	pcc -c cppaste-probe.c
 *
 * ***A PROBE, AND ITS RESULT IS WHETHER IT COMPILES***, like
 * `regpair-min' and `cppskip-probe'. Each case is a LADDER STEP: they
 * are ordered from the plainest paste to CLISP's exact shape, so the
 * FIRST case that fails names the construct. Report what it prints.
 *
 * WHERE THE QUESTION CAME FROM. clisp's `flo_rest.d:338' answered
 *
 *	flo_rest.d:338 name not declared: TO_F_
 *
 * on `GEN_F_op2(x,y,...,1,0,return)', whose body contains
 * `CONCAT(TO_F_,r) (FF_op(arg1,arg2),FF_to_SF)'. With `r' = 1 that
 * must become `TO_F_1(...)'. **It became `TO_F_'** -- the right
 * operand of the paste vanished, leaving a call to an undeclared
 * `TO_F_'.
 *
 * `CONCAT' is the ordinary two-level idiom (`lispbibl.d:949,955'):
 * `CONCAT(x,y)' -> `CONCAT_(x,y)' -> `x##y'. **gcc expands all of it
 * correctly**, including the case where the same parameter is used
 * BOTH as a pasted token and as a value, which is what clisp does --
 * `GEN_F_op2' also contains `if (r>0 && ...)', and that produced no
 * diagnostic, so `r' substitutes fine as an ordinary parameter and
 * only the PASTE loses it.
 *
 * ***TWO MECHANISMS WERE READ OUT OF `cpp/macro.c' AND BOTH WERE
 * WRONG***, which is why this is a probe rather than a patch:
 *
 *   - *The argument begins with WHITESPACE*, since clisp writes the
 *     `1' on a continuation line. Refuted: whitespace is a FIELD
 *     (`tp->wslen'), not a token, and `normtokenrow' (tokens.c:251)
 *     explicitly clears it on the first token of every argument row.
 *   - *The argument begins with a NEWLINE token*, `NL' being its own
 *     type in `cpp.h:39'. Refuted: `gatherargs' (macro.c:331) deletes
 *     `NL' with `adjustrow(trp, -1)' and converts it to space before
 *     the row is ever normalised.
 *
 * *This tree's own tally for mechanisms guessed from code alone is
 * about one in eight*, and two readings in a row went the wrong way,
 * so the ladder below asks the machine instead.
 *
 * WHAT EACH ANSWER MEANS:
 *
 *   all compile          the paste is fine and `flo_rest.d' fails for
 *                        some other reason. **`pcc -E' is the next
 *                        step and it is supported** (`cmd/pcc.c:107'
 *                        sets Eflag and cflag), so from
 *                        `cmd/clisp/build-amd64', with that recipe's
 *                        own flags:
 *
 *	S=../../../../../sys/src/external/clisp/src
 *	pcc -E -D_PLAN9_SOURCE -D_POSIX_SOURCE -D_BSD_EXTENSION \
 *	    -DENABLE_UNICODE -D__x86_64__ -I. -I$S -I$S/gllib \
 *	    lisparit.c >/tmp/lisparit.i
 *	grep -n TO_F_ /tmp/lisparit.i | head
 *
 *                        and read what the paste actually became.
 *                        *That is the machine answering instead of
 *                        another reading of `macro.c'.*
 *   1 fails              `##' is broken outright; nothing in this tree
 *                        that uses CONCAT can be trusted.
 *   2 fails, 1 passes    the two-level idiom is the problem: pasting a
 *                        token that arrived as a macro PARAMETER.
 *   3 fails, 2 passes    the NUMBER is the problem -- pasting an
 *                        identifier to a numeric literal, which is
 *                        exactly what `TO_F_'+`1' is.
 *   4 fails, 3 passes    the call spanning a NEWLINE is the problem,
 *                        which is the one reading above that the
 *                        source seemed to refute.
 *   5 fails, 4 passes    using the parameter as a VALUE as well as a
 *                        pasted token is the problem.
 *
 * **gcc compiles this file clean, and that is the control**: every
 * case is valid C, so a failure here is kencc's and not the probe's.
 * Each case CALLS the function it builds, so a wrong paste is a hard
 * error (`name not declared') rather than a quietly unused macro.
 */

#define CONCAT_(xxx,yyy)  xxx##yyy
#define CONCAT(xxx,yyy)   CONCAT_(xxx,yyy)

int step_ab(void)  { return 1; }
int step_a1(void)  { return 1; }

/* CASE 1: the plainest paste -- two literal identifiers, one level. */
#define PASTE1 CONCAT_(step_,ab)
int case1(void) { return PASTE1(); }

/* CASE 2: through the two-level idiom, operands still literal. */
#define PASTE2 CONCAT(step_,ab)
int case2(void) { return PASTE2(); }

/* CASE 3: the right operand is a NUMBER, as `TO_F_'+`1' is. */
#define PASTE3 CONCAT(step_a,1)
int case3(void) { return PASTE3(); }

/* CASE 4: the number arrives as an OUTER macro's parameter, and the
   call spans a NEWLINE exactly as flo_rest.d:338 does. */
#define OUTER4(a,b,r)  CONCAT(step_a,r) ()
int case4(void)
{
	return OUTER4(1,2,
	              1);
}

/* CASE 5: CLISP's shape in full -- the same parameter used BOTH as a
   value and as a pasted token, with the call spanning a newline. */
#define OUTER5(a,b,r)  ((r)>0 ? CONCAT(step_a,r) () : 0)
int case5(void)
{
	return OUTER5(1,2,
	              1);
}

/*
 * ***CASES 1-5 ALL COMPILED, AND THAT REFUTED THE FAMILY RATHER THAN
 * ANSWERING IT.*** `pcc -c cppaste-probe.c' produced `cppaste-probe.6'
 * with no diagnostic, so kencc's `##' is fine for every shape above --
 * including the two-level idiom, a numeric right operand, the operand
 * arriving as an outer macro's parameter, a call spanning a newline,
 * and the parameter used as a value as well as a pasted token.
 *
 * **So the ladder did not go far enough, and reading `flo_rest.d'
 * again says which rung was missing.** In CLISP the paste is NOT in
 * the outer macro's body. `GEN_F_op2' is built from `floatcase'
 * (`flo_rest.d:7'), whose four statement arms are MACRO ARGUMENTS, and
 * the arms are nested: `floatcase(arg1, {... floatcase(arg2, {...
 * CONCAT(TO_F_,r) ...}) ...})'. So `r' is substituted into
 * `GEN_F_op2's body, then carried as part of an ARGUMENT to
 * `floatcase', then again as part of an argument to the inner
 * `floatcase', and only then does the paste run.
 *
 * *Cases 1-5 all have the paste directly in the body.* Cases 6 and 7
 * carry it through one and two levels of nested macro argument, which
 * is the only structural difference left between the probe and the
 * code that fails.
 */

/* CASE 6: the paste is inside a NESTED macro's argument, one level. */
#define ARM1(stmt)  do { stmt; } while(0)
#define OUTER6(r)   ARM1(v = CONCAT(step_a,r) ())
int case6(void)
{
	int v = 0;
	OUTER6(1);
	return v;
}

/* CASE 7: TWO levels of nested argument -- CLISP's actual shape. */
#define ARM2(a,b)   do { if (1) { a; } else { b; } } while(0)
#define OUTER7(r)   ARM2(ARM2(v = CONCAT(step_a,r) (), v = 0), v = 0)
int case7(void)
{
	int v = 0;
	OUTER7(1);
	return v;
}

int cppaste_probe_ok = 1;
