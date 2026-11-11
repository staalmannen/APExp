/*
 * ppnum-cases.c -- `##' whose right operand is a pp-number.
 *
 *	sh cpp-xcheck.sh ppnum-cases.c
 *
 * C99 6.4.8 defines a preprocessing number as
 *	pp-number: digit | . digit | pp-number digit
 *		 | pp-number identifier-nondigit | pp-number e sign ...
 * and `identifier-nondigit' is a letter OR UNDERSCORE.  So `0_C' is ONE
 * token, and `IN##0_C' pastes `IN' onto the whole of it.
 *
 * ***kencc's `cpp/lex.c' ENDED THE NUMBER AT THE UNDERSCORE***, by two
 * later entries in the lexer FSM that overrode `_''s membership in
 * `C_ALPH'.  The paste then joined only `IN' and `0' and left `_C'
 * standing as a separate identifier, which reaches the compiler as
 *
 *	syntax error, last name: _C
 *
 * **P3 is the discriminator and must pass BOTH before and after**:
 * `_0_C' begins with `_', so it lexes as an identifier rather than a
 * number and was never affected.  *That is what pins the fault on
 * pp-number lexing rather than on `##' itself* -- without it, "paste is
 * broken" and "numbers are lexed wrongly" predict the same output.
 *
 * Found in libwebp 1.6.0, `src/dsp/lossless.c:630', whose
 * `COPY_PREDICTOR_ARRAY(IN, OUT)' pastes `IN##0_C' through `IN##13_C'.
 * It was the ONE file of 125 that would not compile.
 */

/* P1: single digit then underscore */
#define P1(IN) IN##0_C
int P1(foo);		/* foo0_C */

/* P2: two digits, so the paste is not simply "one character" */
#define P2(IN) IN##12_C
int P2(bar);		/* bar12_C */

/* P3: CONTROL -- leading underscore makes it an identifier, always worked */
#define P3(IN) IN##_0_C
int P3(baz);		/* baz_0_C */

/* P4: the real shape, a sentinel index reused twice as libwebp does */
#define P4(OUT, IN) \
  (OUT)[0] = IN##0_C; \
  (OUT)[13] = IN##13_C; \
  (OUT)[14] = IN##0_C;
int *out; int q0_C, q13_C;
void f(void) { P4(out, q) }
