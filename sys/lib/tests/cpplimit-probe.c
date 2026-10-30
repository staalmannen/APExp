/*
 * cpplimit-probe.c -- why does kencc's cpp leave some `CONCAT(...)'
 * calls unexpanded?  THREE SERIES, and the first two are negative.
 *
 *	pcc -E cpplimit-probe.c >/tmp/cpplimit.i
 *	grep -c 'CONCAT(' /tmp/cpplimit.i        # how many went unexpanded
 *	grep -n 'CONCAT(' /tmp/cpplimit.i        # and which case each is in
 *
 * ***NOT A COMPILE TEST.*** It is `-E', and the result is which cases
 * still contain the text `CONCAT(' afterwards.
 *
 * WHERE IT CAME FROM.  clisp's `lisparit.c' preprocesses with twelve
 * `CONCAT(TO_F_,1)' left unexpanded, so `6c' reported `name not
 * declared: TO_F_' for a name inside an unexpanded macro call.  *The
 * paste itself is fine*: `cppaste-probe' puts the construct through
 * seven nestings and kencc expands all of them.
 *
 * ***THE "SIX LONGEST LINES" CORRELATION THAT STARTED THIS FILE WAS AN
 * ARTIFACT, AND SERIES A AND B ARE BOTH NEGATIVE BECAUSE OF IT.***
 * The six failing lines ARE the six longest in `lisparit.i', and that
 * looked like a size limit.  But **only six lines in the whole file
 * contain `TO_F_' at all**, and they are those six: the comparison was
 * against lines that never had the construct.  *A name absent from a
 * list is not a measurement until you have checked the name could have
 * been present*, and it could not.  Those lines are long BECAUSE they
 * are the `GEN_F_op2' expansions, which is also the only place
 * `CONCAT(TO_F_,...)' occurs.
 *
 * Series A and B were built on that artifact and refute it anyway:
 *   A  one-character padding, to 16405 TOKENS -- all ten expand, so it
 *      is not a token count.
 *   B  43-character identifier padding, to 135221 CHARACTERS, 5.6x
 *      clisp's failing length -- all nine expand, so it is not a line
 *      length either.
 * Both are kept because a refuted axis is worth not re-testing.
 *
 * ***SERIES C IS THE REAL SHAPE, AND IT CAME FROM COUNTING.***
 * `lisparit.c' uses `CONCAT' 76 times and **70 expand correctly** --
 * so this is site-specific, not a blanket failure.  (Zero occurrences
 * of `TO_F_0/1/2' in the output is what SUCCESS looks like: `TO_F_1
 * (e,t)' is `t(e)', so the name vanishes.)  In `flo_rest.d' the six
 * sites of `CONCAT(LFlen,s)' at lines 162, 200, 238, 252, 264 and 276
 * are each followed immediately by a `CONCAT(TO_F_,r)' at 164, 202,
 * 240, 254, 266 and 278 -- **six pairs, and exactly six failing
 * lines** -- while every `CONCAT(TO_F_,r)' with no `CONCAT(LFlen,s)'
 * before it in the same arm (141, 152, 177, 190, 215, 226, 303, 310)
 * expands.
 *
 * So the rule to test is: **a SECOND `CONCAT' in the same expansion
 * does not expand.** Every probe written before this one had exactly
 * one, which is why they all passed.
 *
 *   c_one      fails -> something far more basic is wrong; stop here.
 *   c_two      fails -> the second CONCAT in one expansion is the bug,
 *                       and `CONCAT' is being left in the hideset of
 *                       the tokens that follow the first one.
 *   c_twonest  fails alone -> it needs the nesting as well.
 *   all pass   -> the count is not it either, and what is left is the
 *                 interaction with `GEN_F_op2's own parameters.
 *
 * **gcc expands all three and compiles the file, which is the
 * control.**  All sizes quoted above are measured with `gcc -E`.
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

/* ---- series C: how MANY CONCATs in one expansion ----------------- */
#define LFlen0(a)  (a)
#define LFlen1(a)  (a)
#define TO_F_0(e,t) e
#define TO_F_1(e,t) t(e)
int neg(int v) { return -v; }

/* c_one: ONE CONCAT -- the shape every earlier probe had. */
#define ONE(r)       q = CONCAT(TO_F_,r) (q, neg);
int c_one(void) { int q=1; ONE(1) return q; }

/* c_two: TWO CONCATs in one expansion, clisp's LF arm exactly. */
#define TWO(r,s)     q = CONCAT(LFlen,s)(q); q = CONCAT(TO_F_,r) (q, neg);
int c_two(void) { int q=1; TWO(1,0) return q; }

/* c_twonest: the same two inside a macro ARGUMENT, as floatcase does. */
#define ARM(a)       do { a } while(0)
#define TWONEST(r,s) ARM( q = CONCAT(LFlen,s)(q); q = CONCAT(TO_F_,r) (q, neg); )
int c_twonest(void) { int q=1; TWONEST(1,0); return q; }

int cpplimit_probe_ok = 1;
