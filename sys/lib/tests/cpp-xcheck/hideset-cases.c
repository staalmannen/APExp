/*
 * hideset-cases.c -- the cases that distinguish kencc's cpp from gcc's
 * on macro re-expansion. Run by `cpp-xcheck.sh', which preprocesses this
 * file with BOTH and diffs; every line below must come out the same.
 *
 * ***CASE R2 IS THE ONE THAT MATTERS AND IT MUST BE RUN UNDER A
 * TIMEOUT***, because the failure mode is not a wrong answer, it is a
 * preprocessor that never returns. The first version of the hideset
 * intersection fix made `a(2)' loop for ever, and R2 is what caught it
 * -- see the comment on the distribution loop in `cc/../cpp/macro.c'.
 * The script passes `timeout', for that reason and only that reason.
 *
 * WHERE THE CASES CAME FROM. clisp's `flo_rest.d:338' answered
 * `name not declared: TO_F_': `CONCAT(TO_F_,r)' inside `GEN_LF_op2_0'
 * was emitted unexpanded, twelve times in `lisparit.c'. The cause is
 * that `GEN_LF_op2_0' is itself reached through
 * `CONCAT(GEN_LF_op2_,s)', so its NAME is a token manufactured by
 * `##', carrying the hideset of the paste that built it -- and
 * `expand()' handed that hideset to every name in the pasted macro's
 * body, hiding `CONCAT' permanently.
 *
 * `V1'/`V2' below are that shape reduced to five lines. `V1' is the
 * control: the same paste reached WITHOUT going through a pasted macro
 * name, which always worked and is why seven earlier cases in
 * `cppaste-probe.c' all passed.
 *
 * The `R' cases are the protection that must survive the fix: direct
 * self-reference, mutual recursion through a call, an object-like
 * self-reference, object-like mutual recursion, and the same two
 * reached through a paste. **None of them may expand and none may
 * loop.** C99 6.10.3.4p2 is what they are checking, and gcc's answer
 * is the reference.
 */

#define CONCAT_(a,b)  a##b
#define CONCAT(a,b)   CONCAT_(a,b)

#define TO_1(x)       ((x)+1)
#define INNER_0(x)    CONCAT(TO_,1)(x)
#define OUTER(s,v)    CONCAT(INNER_,s)(v)

/* V1: the paste reached directly -- the control, which always worked. */
V1 CONCAT(TO_,1)(7)

/* V2: the paste reached through a macro whose NAME was pasted. */
V2 OUTER(0,7)

/* --- the protection --- */

#define self(x)    self(x)
#define a(x)       b(x)
#define b(x)       a(x)
#define obj        obj
#define oa         ob
#define ob         oa
#define loop       CONCAT(lo,op)
#define pself(x)   CONCAT(pse,lf)(x)

R1 self(1)
R2 a(2)
R3 obj
R4 oa
R5 loop
R6 pself(6)

/*
 * R7 is about the OTHER half of the fix: the hideset is distributed to
 * RP as well as NAME now, because the intersection reads the closing
 * parenthesis. An argument that is a complete call of the same macro
 * puts an inner `)' carrying that macro's paint inside the outer call's
 * argument list, so if the paint leaked to the outer `)' the outer
 * expansion would lose itself.
 *
 * ***THE FIRST R7 WAS ILL-FORMED AND GCC SAID SO***: it was
 * `f(1 paren(2)' with the closing `)' arriving from `paren's expansion,
 * which does not close an argument list -- gatherargs reads raw tokens
 * and a macro-produced `)' is not a terminator for anyone. gcc answered
 * `unterminated argument list invoking macro "id2"' and swallowed the
 * rest of the file. *A case the reference implementation rejects cannot
 * discriminate anything*, which is this tree's rule about checking a new
 * test against gcc first, for the preprocessor.
 */
#define twice(x)   ((x)+(x))
R7 twice(twice(3))

/*
 * R8 is C99 6.10.3.5 EXAMPLE 3 verbatim -- the standard's own torture
 * case for this machinery, and the reason it is here rather than
 * invented: it exercises `#', `##', rescanning and argument
 * pre-expansion together, and its expected output is written down in the
 * standard. The one line whose result the standard leaves UNSPECIFIED is
 * deliberately left out; `cpp-xcheck.sh' diffs against gcc, and a case
 * where two conforming implementations may differ would report a fault
 * that is not one.
 */
#define x       3
#define f(a)    f(x * (a))
#undef  x
#define x       2
#define g       f
#define z       z[0]
#define h       g(~
#define m(a)    a(w)
#define w       0,1
#define t(a)    a
#define p()     int
#define q(x)    x
#define r(x,y)  x ## y
#define str(x)  # x

R8 f(y+1) + f(f(z)) % t(t(g)(0) + t)(1);
R9 g(x+(3,4)-w) | h 5) & m
       (f)^m(m);
R10 p() i[q()] = { q(1), r(2,3), r(4,), r(,5), r(,) };
R11 char c[2][6] = { str(hello), str() };
