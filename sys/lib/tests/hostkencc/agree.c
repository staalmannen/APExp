/*
 * agree.c -- the one control this harness cannot run itself.
 *
 * Nothing in `hostkencc.sh' proves a host-built compiler agrees with a
 * VM-built one. Run this on both sides and diff:
 *
 *	( VM )    6c -S agree.c > /tmp/vm.s
 *	( host )  out/bin/6c -S agree.c > /tmp/host.s
 *	          diff /tmp/vm.s /tmp/host.s
 *
 * It uses NO headers, so it needs nothing staged on either side, and it
 * is chosen to touch the places where the host's 64-bit `long' could
 * leak into a decision the target should own: `long' arithmetic and
 * shifts, a `long'-to-`vlong' widening, struct layout and `sizeof',
 * a bit-field group, a switch with a wide label, and enough locals to
 * make the register allocator work (`Bits', `NVAR').
 *
 * ***THE CONTROL HAS BEEN RUN, AND IT PAID FOR ITSELF ON THE FIRST
 * DIFF.*** VM `6c -S' against host `out/bin/6c -S', 131 lines each:
 *
 *   - **`widecase' differed semantically and that was a REAL BUG.** The
 *     host emitted `CMPQ BP,$4294967296' -- an immediate x86-64 does
 *     not have -- where the VM materialises `MOVQ $4294967296,SI;
 *     CMPQ BP,SI'. The cause is `6c/cgen.c's `immconst()', whose whole
 *     test was `v = n->vconst; return n->vconst == (vlong)v;' with
 *     `long v': a round trip that answers "fits in 32 bits" only
 *     because kencc's `long' IS 32 bits. `int v' now, which is the
 *     same number on Plan 9 and says what was meant. **With it,
 *     `widecase' matches the VM instruction for instruction, PC
 *     offsets included.**
 *   - `s_size', `b_size', `widen', `ulongshift' and `manylocals' were
 *     identical from the start, as were every store in `bits'.
 *   - **What remains is the ORDER of commutative terms** in `larith'
 *     and in `bits's final sum -- identical instruction multisets,
 *     different accumulation order, same value. It comes from
 *     `cc/scon.c's `acom2', whose `qsort' comparators tie-break with
 *     `if(t2 > t1) return 1; return -1;' -- *the addresses of the
 *     array elements being sorted*, which qsort is permuting as it
 *     runs. So the permutation of equal terms is whatever the host's
 *     qsort does, and glibc's is not Plan 9's. **Measured**: an
 *     instrumented `acom2' shows `larith's seven terms going in as
 *     13,14,-60,59,3,88 and coming out reversed, with every compared
 *     pair a tie on `mult'.
 *
 * *Not fixed, deliberately.* Making the tie-break stable would change
 * generated code for every binary on Plan 9 and buys no correctness --
 * both orders compute the same value and C leaves the order
 * unspecified. It is recorded because it is the reason a host/VM diff
 * can never be byte-exact, and because compiler output that depends on
 * qsort's tie-breaking is a reproducibility hazard worth knowing about.
 *
 * ***AND A CONTROL THAT CANNOT SEPARATE THE HYPOTHESES IS NOT A
 * REFUTATION.*** The qsort mechanism was first declared refuted,
 * because relinking the host `6c' against a hand-written insertion
 * sort produced the SAME output as glibc's qsort. It proves nothing:
 * both algorithms reverse a run of ties under this comparator. The
 * instrumented `acom2' is what settled it.
 *
 * ***IT IS THE amd64 CONTROL, AND FIVE BACKENDS REJECT PARTS OF IT.***
 * That was not the plan and is worth more than the plan was. Compiled
 * by the host-built backends, `6c', `7c', `8c', `9c' and `qc' take it
 * and the other five do not:
 *
 *	1c, 2c   :68 switch expression must be integer      (vlong switch)
 *	5c       :62 bad vlong in gmove (REGISTER->REGPAIR)
 *	kc, vc   :43 unknown op in lcgen: MUL               ((vlong)v * 3)
 *
 * **kc and vc are the `lcgen' family that 0.6's inventory already
 * carries** -- recorded there on `regpair-probe' case 3 as
 * `unknown op in lcgen: CAST' -- so this says the same hole swallows
 * `MUL' as well as `CAST', and `5c' and the 68000 pair have their own.
 * *A control written for one target answered a question about nine
 * others*, which is the argument for this harness rather than an
 * objection to the file.
 *
 * So: the VM diff is specifically `6c -S', and the five failures above
 * are a finding and not an obstacle to it.
 *
 * **A diff here is a real result either way**, and re-running it after
 * any `cc/' or `6c/' change is the point of the file. Expect the two
 * `acom2' orderings above and nothing else; anything further names the
 * construct to look at, and `docs/notes/kencc.md' has the width hazards
 * to check first (`cc.h:47' NVAR, `6c/cgen.c' immconst, and
 * `sizeof(long)' in the LINKERS' `pass.c', which is why `[1-9]l' is not
 * built here).
 */

typedef long long vlong;
typedef unsigned long ulong;

struct S { char a; long b; char c[3]; };
struct B { unsigned x:3; unsigned y:5; unsigned z:24; };

long  s_size(void)	{ return sizeof(struct S); }
long  b_size(void)	{ return sizeof(struct B); }

long
larith(long a, long b)
{
	return (a << 3) + (b >> 2) - (a * b) + (a % 7) + (a & b) + (a ^ b);
}

vlong
widen(long v)
{
	return (vlong)v * 3;
}

long
ulongshift(ulong u)
{
	return (long)(u >> 17);
}

int
bits(struct B *p, int v)
{
	p->x = v;
	p->y = v >> 1;
	p->z = v >> 2;
	return p->x + p->y + p->z;
}

long
widecase(vlong v)
{
	switch(v) {
	case 1:			return 10;
	case 0x100000000LL:	return 20;
	case -1:		return 30;
	}
	return 0;
}

long
manylocals(long a)
{
	long b, c, d, e, f, g, h, i, j, k;

	b = a+1; c = b+2; d = c+3; e = d+4; f = e+5;
	g = f+6; h = g+7; i = h+8; j = i+9; k = j+10;
	return b+c+d+e+f+g+h+i+j+k;
}
