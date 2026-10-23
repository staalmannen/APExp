/*
 * regpair-min.c -- the whole question, in one function.
 *
 * `regpair-probe.c' grew to fifteen cases and 450 lines while the
 * thing it is asking about is three lines long.  **Every hypothesis it
 * has killed was killed by a case that differed from case 1 in more
 * ways than one**, and the variable nobody has held constant is the
 * one the file itself imposes: ***case 1 is the FIRST FUNCTION in the
 * translation unit, and everything that passes comes after it.***
 *
 * So this file is case 1 and nothing else.
 *
 *	8c regpair-min.c
 *
 * **IT FAILS** -- then the construct is self-contained, this is a
 * ten-line reproduction, and it is what a bug report should carry.
 * Vary things *inside* this file from here; `regpair-probe.c' has done
 * what it can.
 *
 * **IT COMPILES** -- then the construct is innocent and the
 * SURROUNDING FILE is the variable, which no case added to the probe
 * could ever have shown, because every one of them was added to the
 * same file. The live candidate is position: per-function state in the
 * backend (`regsalloc`'s stack offsets, `maxargsafe`, the register
 * tables) is in its initial condition for the first function and in
 * some accumulated one for every later one. *That would also explain
 * why the probe's other fourteen cases are unanimous.*
 *
 * ***EITHER ANSWER IS WORTH MORE THAN A SIXTEENTH CASE***, which is
 * the lesson: when a reduction stops narrowing, stop adding to it and
 * ask whether the harness is part of the measurement.
 *
 * The structs are copied from `regpair-probe.c' character for
 * character, which is copied from `ar.c' -- the original is
 * `as->offset = ap->size' at `sys/src/cmd/ar.c:586', both members
 * `vlong', in a file this tree has never modified.
 *
 * NATIVE, like `regpair-probe.c' and `truefalse-test.c': the question
 * is about a backend, so it is asked of that backend. The result is
 * whether it COMPILES.
 */

#include <u.h>
#include <libc.h>

typedef struct Src Src;
typedef struct Dst Dst;

struct Src
{
	char	*name;
	int	type;
	int	len;
	vlong	size;
};

struct Dst
{
	char	*name;
	int	type;
	int	len;
	vlong	offset;
	Dst	*next;
};

/*
 * -DLEADER PUTS A TRIVIAL FUNCTION AHEAD OF case1, and that is the one
 * hypothesis this file does NOT settle by existing.
 *
 * `regpair-probe.c' could never test it, because case1 was the first
 * function there too and every case added to that file came after it.
 * It still is here.  So per-function backend state -- `regsalloc''s
 * stack offsets, `maxargsafe', the register tables, all in their
 * initial condition for the first function compiled and in some
 * accumulated one for every later one -- remains live, and two
 * compiles of ONE file settle it:
 *
 *	8c regpair-min.c            both name the same line
 *	8c -DLEADER regpair-min.c
 *
 * **Both fail** -> position is irrelevant and this is a true minimal
 * reproduction: two structs, one assignment.
 * **-DLEADER compiles** -> the construct is innocent and the fault is
 * POSITIONAL, which is a different bug in a different place and a much
 * bigger finding than a tenth case would have been.
 *
 * cpp keeps line numbering through an `#ifdef', so the assignment
 * below is on the same line in both builds and the two diagnostics are
 * directly comparable.
 */
#ifdef LEADER
void
leader(void)
{
}
#endif

void
case1(Dst *d, Src *s)
{
	d->offset = s->size;
}

void
main(void)
{
	Src s;
	Dst d;

	s.size = 0x1122334455667788LL;
	d.offset = 0;
	d.next = nil;
	case1(&d, &s);
	print("regpair-min: %lld\n", d.offset);
	exits(0);
}
