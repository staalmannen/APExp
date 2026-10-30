/*
 * cpplimit-probe.c -- at what SIZE does kencc's cpp stop expanding
 * macros on a line?
 *
 *	pcc -E cpplimit-probe.c >/tmp/cpplimit.i
 *	grep -c 'CONCAT(' /tmp/cpplimit.i        # how many went unexpanded
 *	grep -n 'CONCAT(' /tmp/cpplimit.i        # and which case each is in
 *
 * ***NOT A COMPILE TEST.*** It is `-E', and the result is which cases
 * still contain the text `CONCAT(' afterwards. A case that expanded
 * correctly contains `step_a1' instead. **Every case is identical
 * except for how many tokens precede the paste**, so the first one
 * that fails is the threshold.
 *
 * WHERE IT CAME FROM. clisp's `lisparit.c' preprocesses with TWELVE
 * occurrences of `CONCAT(TO_F_,1)' left UNEXPANDED, and zero correct
 * `TO_F_0/1/2' anywhere -- so `6c' reported `name not declared: TO_F_'
 * for the `TO_F_` inside an unexpanded macro call. *The paste was
 * never the bug*: `cppaste-probe' puts the same construct through
 * seven nestings, including clisp's own two-level one, and kencc
 * expands all of them.
 *
 * ***THE FAILURES CORRELATE EXACTLY WITH LINE LENGTH.*** In the
 * preprocessed output the six lines holding an unexpanded `CONCAT' are
 * the SIX LONGEST LINES IN THE FILE -- 22869 to 24043 characters,
 * about 11536 tokens -- and the seventh longest, 19344 characters and
 * about 9637 tokens, is clean. Nothing else distinguishes them:
 * `r' substitutes correctly even on the failing lines, which print
 * `if (1 >0 && ...' from the same macro body.
 *
 * So the question is a NUMBER, and this file bisects it. Each case
 * below is one logical line: a padding macro expanding to a known
 * number of tokens, then the same `CONCAT(step_a,1) ()' paste. If the
 * threshold is a token count, the first failing case names it to
 * within the step. **The counts below are MEASURED with `gcc -E'**,
 * not estimated from the macro arithmetic -- cases 7, 8 and 9 are
 * 9237, 10261 and 12309 tokens, which brackets the 9637-passes /
 * 11536-fails boundary seen in `lisparit.i'. *A probe that mislabels
 * its own cases misreports the threshold.*
 *
 * **gcc expands every case, which is the control** -- run
 * `gcc -E -P cpplimit-probe.c | grep -c "CONCAT("' and expect 0.
 */

#define CONCAT_(xxx,yyy)  xxx##yyy
#define CONCAT(xxx,yyy)   CONCAT_(xxx,yyy)
int step_a1(void) { return 1; }

/* P0 is 10 tokens; each level multiplies by 8. */
#define P0  x=1;x=1;
#define P1  P0 P0 P0 P0 P0 P0 P0 P0
#define P2  P1 P1 P1 P1 P1 P1 P1 P1
#define P3  P2 P2 P2 P2 P2 P2 P2 P2

/* case 1: 533 tokens on the line, measured with gcc -E */
int lim1(void) { int x=0; P2 x = CONCAT(step_a,1) (); return x; }

/* case 2: 1045 tokens on the line, measured with gcc -E */
int lim2(void) { int x=0; P2 P2 x = CONCAT(step_a,1) (); return x; }

/* case 3: 2069 tokens on the line, measured with gcc -E */
int lim3(void) { int x=0; P2 P2 P2 P2 x = CONCAT(step_a,1) (); return x; }

/* case 4: 4117 tokens on the line, measured with gcc -E */
int lim4(void) { int x=0; P3 x = CONCAT(step_a,1) (); return x; }

/* case 5: 6165 tokens on the line, measured with gcc -E */
int lim5(void) { int x=0; P3 P2 P2 P2 P2 x = CONCAT(step_a,1) (); return x; }

/* case 6: 8213 tokens on the line, measured with gcc -E */
int lim6(void) { int x=0; P3 P3 x = CONCAT(step_a,1) (); return x; }

/* case 7: 9237 tokens on the line, measured with gcc -E */
int lim7(void) { int x=0; P3 P3 P2 P2 x = CONCAT(step_a,1) (); return x; }

/* case 8: 10261 tokens on the line, measured with gcc -E */
int lim8(void) { int x=0; P3 P3 P2 P2 P2 P2 x = CONCAT(step_a,1) (); return x; }

/* case 9: 12309 tokens on the line, measured with gcc -E */
int lim9(void) { int x=0; P3 P3 P3 x = CONCAT(step_a,1) (); return x; }

/* case 10: 16405 tokens on the line, measured with gcc -E */
int lim10(void) { int x=0; P3 P3 P3 P3 x = CONCAT(step_a,1) (); return x; }

int cpplimit_probe_ok = 1;
