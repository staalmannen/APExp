/*
 * cpplimit-probe.c -- at what SIZE does kencc's cpp stop expanding
 * macros on a line?  TWO SERIES, because the first one answered.
 *
 *	pcc -E cpplimit-probe.c >/tmp/cpplimit.i
 *	grep -c 'CONCAT(' /tmp/cpplimit.i        # how many went unexpanded
 *	grep -n 'CONCAT(' /tmp/cpplimit.i        # and which case each is in
 *
 * ***NOT A COMPILE TEST.*** It is `-E', and the result is which cases
 * still contain the text `CONCAT(' afterwards.  A case that expanded
 * correctly contains `step_a1' instead.
 *
 * WHERE IT CAME FROM.  clisp's `lisparit.c' preprocesses with TWELVE
 * `CONCAT(TO_F_,1)' left UNEXPANDED and zero correct `TO_F_0/1/2'
 * anywhere, so `6c' reported `name not declared: TO_F_' for a name
 * inside an unexpanded macro call.  *The paste was never the bug* --
 * `cppaste-probe' puts the same construct through seven nestings,
 * clisp's own two-level one included, and kencc expands all of them.
 * In the preprocessed output the six lines holding an unexpanded
 * `CONCAT' are the SIX LONGEST LINES IN THE FILE, 22869 to 24043
 * characters and about 11536 tokens; the seventh longest, 19344
 * characters and about 9637 tokens, is clean.
 *
 * ***SERIES A IS MEASURED AND IT REFUTES A TOKEN LIMIT.***  Cases
 * `lim1'..`lim10' pad with one-character tokens, so characters and
 * tokens rise together, and they reach 16405 tokens -- well past the
 * 11536 that fails in clisp.  `grep -c CONCAT(' answers **0**: all ten
 * expand.  So the limit is not a token count.
 *
 * **But series A tops out at 16438 CHARACTERS and clisp fails at
 * 22869**, so it never entered the failing range on that axis.  *A
 * probe that does not reach the condition cannot clear it*, and the
 * two axes were confounded because one-character tokens make
 * characters and tokens the same number.
 *
 * SERIES B SEPARATES THEM.  `big1'..`big9' pad with a 43-character
 * identifier, so characters rise about ten times faster than tokens:
 *
 *	big1   2933 chars    277 tokens
 *	big2   5813 chars    533 tokens
 *	big3  11573 chars   1045 tokens
 *	big4  23093 chars   2069 tokens   <- clisp's failing LENGTH,
 *	big5  34613 chars   3093 tokens      a sixth of its tokens
 *	big6  46133 chars   4117 tokens
 *	big7  69173 chars   6165 tokens
 *	big8  92213 chars   8213 tokens
 *	big9 138293 chars  12309 tokens
 *
 * **If `big4' fails, the limit is CHARACTERS**, somewhere near 22000,
 * and the constant to look at is one of `INS 32768' / `OBS 4096' /
 * `OUTS 16384' in `cpp.h' and `cpp.c'.
 * **If every `big' passes too, it is NEITHER length nor tokens**, and
 * what is left is structural: clisp's line is deeply nested macro
 * ARGUMENTS (`floatcase' inside `floatcase' inside `GEN_F_op2'),
 * which creates many distinct hidesets, while this padding is a flat
 * repetition that creates almost none.  `Token.hideset' is an
 * `unsigned short' fed from an unbounded `int' in `newhideset'.
 *
 * All counts above are MEASURED with `gcc -E', not estimated from the
 * macro arithmetic.  **gcc leaves 0 unexpanded and compiles the file,
 * which is the control.**
 */

#define CONCAT_(xxx,yyy)  xxx##yyy
#define CONCAT(xxx,yyy)   CONCAT_(xxx,yyy)
int step_a1(void) { return 1; }

/* ---- series A: one-character tokens; chars == tokens ------------- */
#define P0  x=1;x=1;
#define P1  P0 P0 P0 P0 P0 P0 P0 P0
#define P2  P1 P1 P1 P1 P1 P1 P1 P1
#define P3  P2 P2 P2 P2 P2 P2 P2 P2

/* lim1: 533 tokens, 565 chars -- MEASURED: expands correctly */
int lim1(void) { int x=0; P2 x = CONCAT(step_a,1) (); return x; }

/* lim2: 1045 tokens, 1077 chars -- MEASURED: expands correctly */
int lim2(void) { int x=0; P2 P2 x = CONCAT(step_a,1) (); return x; }

/* lim3: 2069 tokens, 2101 chars -- MEASURED: expands correctly */
int lim3(void) { int x=0; P2 P2 P2 P2 x = CONCAT(step_a,1) (); return x; }

/* lim4: 4117 tokens, 4149 chars -- MEASURED: expands correctly */
int lim4(void) { int x=0; P3 x = CONCAT(step_a,1) (); return x; }

/* lim5: 6165 tokens, 6197 chars -- MEASURED: expands correctly */
int lim5(void) { int x=0; P3 P2 P2 P2 P2 x = CONCAT(step_a,1) (); return x; }

/* lim6: 8213 tokens, 8245 chars -- MEASURED: expands correctly */
int lim6(void) { int x=0; P3 P3 x = CONCAT(step_a,1) (); return x; }

/* lim7: 9237 tokens, 9269 chars -- MEASURED: expands correctly */
int lim7(void) { int x=0; P3 P3 P2 P2 x = CONCAT(step_a,1) (); return x; }

/* lim8: 10261 tokens, 10293 chars -- MEASURED: expands correctly */
int lim8(void) { int x=0; P3 P3 P2 P2 P2 P2 x = CONCAT(step_a,1) (); return x; }

/* lim9: 12309 tokens, 12341 chars -- MEASURED: expands correctly */
int lim9(void) { int x=0; P3 P3 P3 x = CONCAT(step_a,1) (); return x; }

/* lim10: 16405 tokens, 16437 chars -- MEASURED: expands correctly */
int lim10(void) { int x=0; P3 P3 P3 P3 x = CONCAT(step_a,1) (); return x; }

/* ---- series B: a long identifier; chars rise ~10x faster --------- */
extern int a_rather_long_identifier_name_for_padding;
#define Q0  a_rather_long_identifier_name_for_padding=1;
#define Q1  Q0 Q0 Q0 Q0 Q0 Q0 Q0 Q0
#define Q2  Q1 Q1 Q1 Q1 Q1 Q1 Q1 Q1
#define Q3  Q2 Q2 Q2 Q2 Q2 Q2 Q2 Q2

/* big1: 2933 chars, 277 tokens */
int big1(void) { int x=0; Q2 x = CONCAT(step_a,1) (); return x; }

/* big2: 5813 chars, 533 tokens */
int big2(void) { int x=0; Q2 Q2 x = CONCAT(step_a,1) (); return x; }

/* big3: 11573 chars, 1045 tokens */
int big3(void) { int x=0; Q2 Q2 Q2 Q2 x = CONCAT(step_a,1) (); return x; }

/* big4: 23093 chars, 2069 tokens   <- clisp's failing LENGTH */
int big4(void) { int x=0; Q3 x = CONCAT(step_a,1) (); return x; }

/* big5: 34613 chars, 3093 tokens */
int big5(void) { int x=0; Q3 Q2 Q2 Q2 Q2 x = CONCAT(step_a,1) (); return x; }

/* big6: 46133 chars, 4117 tokens */
int big6(void) { int x=0; Q3 Q3 x = CONCAT(step_a,1) (); return x; }

/* big7: 69173 chars, 6165 tokens */
int big7(void) { int x=0; Q3 Q3 Q3 x = CONCAT(step_a,1) (); return x; }

/* big8: 92213 chars, 8213 tokens */
int big8(void) { int x=0; Q3 Q3 Q3 Q3 x = CONCAT(step_a,1) (); return x; }

/* big9: 138293 chars, 12309 tokens */
int big9(void) { int x=0; Q3 Q3 Q3 Q3 Q3 Q3 x = CONCAT(step_a,1) (); return x; }

int cpplimit_probe_ok = 1;
