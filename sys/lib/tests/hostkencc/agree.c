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
 * **A diff here is a real result either way.** Identical output means
 * the harness's codegen can be believed for this target; any difference
 * names the construct to look at, and `docs/notes/kencc.md' has the two
 * known width hazards to check first (`cc.h:47' NVAR, and `sizeof(long)'
 * in the LINKERS' `pass.c', which is why `[1-9]l' is not built here).
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
