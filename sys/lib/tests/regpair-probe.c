/*
 * regpair-probe.c -- which 64-bit construct makes 8c say
 * `bad in naddr: REGPAIR'?
 *
 * ***THE RESULT OF THIS PROBE IS WHETHER IT COMPILES, NOT WHAT IT
 * PRINTS.*** It is a compile-time question, so running the binary is
 * beside the point; if it links, it prints its own sums so that the
 * code cannot be dismissed as dead.
 *
 * WHERE IT CAME FROM.  `objtype=386 mk install' -- the first cross
 * build this tree has ever attempted -- stopped on the fourth command:
 *
 *	8c -FTVw ar.c
 *	ar.c:586 bad in naddr: REGPAIR
 *	ar.c:586 bad in naddr: REGPAIR
 *	mk: 8c -FTVw ar.c : exit status=8c 332996: error
 *
 * `ar.c:586' is `as->offset = ap->size;', and both members are
 * `vlong'.  **So it is a plain 64-bit member-to-member assignment**,
 * which is bread-and-butter C, in a file this tree has never modified:
 * `sys/src/cmd/ar.c' has one commit, the import.
 *
 * WHY AMD64 COULD NEVER HAVE SHOWN IT.  `OREGPAIR' is how 8c holds a
 * 64-bit value in two 32-bit registers, and `grep -rn REGPAIR' finds it
 * in `8c/' and in `cc/pswt.c' and NOWHERE ELSE.  The whole 64-bit code
 * generator, `8c/cgen64.c', is 8c's alone -- 6c does not need one,
 * because a vlong is a single amd64 register.  ***So the 386 backend's
 * 64-bit path is precisely the part of kencc that every build this tree
 * has ever done was unable to reach.***
 *
 * ***IT IS OURS, AND THAT IS MEASURED.***  Stock `8c' -- run from a
 * plain `term%' window where /bin is 9front's own -- compiles this very
 * `ar.c' and leaves an `ar.8' behind, and the whole of /sys/src cross
 * compiles to 386 on the host.  APExp's `8c' fails on the same file.
 * *The input is identical, so the difference is the compiler.*
 *
 * ***AND `git bisect' CANNOT REACH IT, WHICH IS WORTH SAYING BECAUSE
 * THE OPPOSITE WAS SAID FIRST.***  The thirteen commits under
 * `sys/src/cmd/cc/' are NOT the delta from stock: **this repository's
 * root commit already contains `isbool', `vlasizevar', `alignas_req',
 * `_Generic' and VLA**, so the import is APExp's compilers at an
 * advanced state and not 9front's.  Every kencc patch older than the
 * repository is invisible to the history and is just as likely to be
 * the cause.
 *
 * **SO THE INSTRUMENT IS A SOURCE DIFF AGAINST THE RUNNING SYSTEM
 * rather than the git log**, and it can only be taken on the VM:
 *
 *	diff -r /sys/src/cmd/cc $home/APExp/sys/src/cmd/cc
 *	diff -r /sys/src/cmd/8c $home/APExp/sys/src/cmd/8c
 *
 * **AND ONE BUILD SPLITS THE SEARCH IN HALF.**  APExp's `8c/' uses
 * names only APExp's `cc.h' defines -- `conformalign', `talign',
 * `dupokall' -- so stock-cc with APExp-8c will not compile; but the
 * other pairing will, because stock `8c/' asks for nothing new.  Build
 * `8c' from **APExp's `cc/' and STOCK `8c/'**, and compile `ar.c':
 *
 *   it FAILS  -> the fault is in the shared front end, `cc/'.
 *   it PASSES -> the fault is in `8c/' itself, which would be a
 *                surprise worth having, since the only changes this
 *                repository made there are -J's and -C's and both sit
 *                behind flags this compile does not pass.
 *
 * *One build, and whichever way it goes the search halves.*  **Run it
 * before reading anything below**: every section here is about WHICH
 * construct, and which construct does not matter until the half is
 * known.
 *
 * ***FIRST RUN, 2026-10-23, APExp's own compilers, ALL TEN BACKENDS.***
 * The split is by WORD SIZE and it is total:
 *
 *	6c amd64    COMPILES      7c arm64    COMPILES
 *	9c power64  COMPILES      kc sparc64  COMPILES
 *
 *	8c 386      116
 *	5c arm      122, 127
 *	qc power    127
 *	1c 68000    116 126 127 136 145 153 164  (and `too many errors')
 *	2c 68020    the same set
 *
 * **Every 64-bit backend compiles this file and every 32-bit backend
 * fails it**, which is what you would expect of a path only a register
 * PAIR can reach -- and it says the four that pass prove nothing about
 * the four that fail.
 *
 * ***A COMPILE-TIME RESULT CAN ONLY NAME A LINE, SO IT ROTS THE MOMENT
 * THE FILE IS EDITED ABOVE IT -- AND THIS FILE PROVED THAT ON ITSELF.***
 * Cases 7 to 11 were appended BELOW case6 precisely so the measured
 * line numbers would survive, and then writing this table pushed every
 * one of them down 48 lines anyway, because the table is in the
 * header.  *Appending to the code is not enough when the prose is at
 * the top.*  So the mapping is by CASE, which is stable, with both
 * line numbers given:
 *
 *	case  run of 2026-10-23  now  construct
 *	 1          116          181  d->offset = s->size  (ar.c:586)
 *	 2          122          187  a vlong PARAMETER arriving
 *	 2          126          191  b = a   (local to local)
 *	 2          127          192  RETURN of a vlong
 *	 3          136          201  d->offset = v  (32 -> 64)
 *	 4          145          210  return s->size
 *	 5          153          218  d->offset = d->offset + 1
 *	 6          164          229  a vlong as a vararg
 *
 * **Re-key the table, do not renumber the cases**, and when the next
 * run comes back, read it against the `now' column and then move that
 * column's name to the date of the run.
 *
 * ***AND THEY ARE NOT ONE BUG.*** 5c and qc fail on the RETURN of a
 * vlong, which 8c compiles; 8c fails on case 1, which 5c and qc
 * compile; 1c and 2c fail on everything, which reads as no vlong
 * support rather than as a defect in it.  *Three different faults at
 * least, so "the 32-bit backends are broken" is a summary and not a
 * diagnosis.*
 *
 * ***8c's RESULT IS THE SHARPEST THING HERE: CASE 1 AND NOTHING
 * ELSE.***  Not the parameter, not the return, not the widening, not
 * `d->offset = d->offset + 1', not the vararg.  So 8c's 64-bit support
 * is broadly working and ONE shape is not -- and the shape is the one
 * ar.c uses.  Cases 7 to 11 split it along its three seams: how many
 * indirections, whether the two structs are the same TYPE, and whether
 * the load and the store are in one expression.  **If case 8 compiles
 * where case 1 does not, the fault is holding two register pairs live
 * at once, which is the register allocator and not the front end.**
 *
 * **WHAT IS STILL MISSING IS STOCK 8c ON THIS FILE**, and it is one
 * command from a plain `term%' window.  The ar.c A/B says APExp's
 * compiler is at fault; this file says which construct; *only the two
 * together say that this construct is a regression rather than
 * something kencc never supported.*  If stock 8c also fails on 116,
 * then case 1 differs from ar.c:586 in some way that matters and the
 * reduction is not yet faithful.
 *
 * Build, and the build IS the test:
 *
 *	8c -FTVw regpair-probe.c && 8l -o regpair-probe regpair-probe.8
 *
 * **NATIVE, NOT `pcc'** -- the second native file here after
 * `truefalse-test.c', and for a related reason: the question is about a
 * backend, so it has to be asked of that backend directly.  To ask it
 * of 386 FROM an amd64 machine, that is `8c' either way: 8c is the 386
 * compiler and it runs on the host.
 *
 * Each case is in its own function so that a diagnostic names a line
 * and therefore a construct.  Expect a message per failing case rather
 * than one for the file.
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
 * CASE 1 is ar.c:586 itself, transcribed rather than described: two
 * POINTERS to different structs, one vlong member assigned from the
 * other.  If only this one fails, the fault is in the addressing of an
 * indirect 64-bit destination rather than in 64-bit assignment at all.
 */
void
case1(Dst *d, Src *s)
{
	d->offset = s->size;
}

/* CASE 2: the same assignment between LOCALS. If this fails too, the
 * fault is wider than ar.c's shape and nothing about structs matters. */
vlong
case2(vlong a)
{
	vlong b;

	b = a;
	return b;
}

/* CASE 3: a 32-bit value WIDENED into a 64-bit member. ar.c's two
 * members are both vlong, so this is not its case -- it is here to say
 * whether the conversion path is implicated or only the move. */
void
case3(Dst *d, long v)
{
	d->offset = v;
}

/* CASE 4: a 64-bit member READ, with no 64-bit destination. Separates
 * loading from storing: if 1 fails and this passes, the store side is
 * the one to look at. */
vlong
case4(Src *s)
{
	return s->size;
}

/* CASE 5: through one pointer only, which is the commonest shape in
 * the tree and the one most likely to be reached early in a build. */
void
case5(Dst *d)
{
	d->offset = d->offset + 1;
}

/*
 * CASE 6: a 64-bit member passed as an ARGUMENT. Argument setup is a
 * different path from assignment in every kencc backend, and a cross
 * build reaches it within a few files of starting.
 */
void
case6(Src *s)
{
	print("case6 %lld\n", s->size);
}

/*
 * CASES 7 TO 11 WERE ADDED AFTER THE FIRST RUN AND ARE DELIBERATELY
 * PLACED HERE, below case6 and above main, SO THAT THE LINE NUMBERS
 * ALREADY MEASURED STILL MEAN WHAT THEY MEANT.  A compile-time result
 * can only name a LINE, so a recorded result rots the moment the file
 * is edited above it; the table in the header is keyed on lines, and
 * appending is what keeps it honest.
 *
 * They exist because 8c failed on case 1 and on NOTHING ELSE -- not
 * the vlong parameter, not the vlong return, not the widening, not
 * `d->offset = d->offset + 1', not the vararg.  So its 64-bit support
 * is broadly working and one shape is not, and these five split that
 * shape along its three seams: how many indirections, whether the two
 * structs are the same TYPE, and whether the load and the store are in
 * one expression.
 */

vlong	gsrc;
vlong	gdst;

/* 7: TWO POINTERS, ONE TYPE. If case 1 fails and this passes, what
 * matters is that the structs DIFFER, which would point at the type
 * machinery rather than at addressing. */
void
case7(Dst *d, Dst *e)
{
	d->offset = e->offset;
}

/* 8: THE SAME WORK IN TWO STATEMENTS. If case 1 fails and this passes,
 * the fault is in holding two register pairs live at once -- the load
 * and the store are each fine alone. That is the register allocator,
 * not the front end. */
void
case8(Dst *d, Src *s)
{
	vlong t;

	t = s->size;
	d->offset = t;
}

/* 9: NO INDIRECTION AT ALL, two 64-bit statics. */
void
case9(void)
{
	gdst = gsrc;
}

/* 10: ONE indirection, on the READ side only. */
void
case10(Src *s)
{
	gdst = s->size;
}

/* 11: ONE indirection, on the WRITE side only -- and from a 64-bit
 * source rather than case 3's 32-bit one, so a failure here is about
 * the store and not about the conversion. */
void
case11(Dst *d)
{
	d->offset = gsrc;
}

/*
 * CASES 12 TO 14, APPENDED BELOW case11 AND ABOVE main for the same
 * reason as before: everything above stays where it was, and case 1 is
 * still on the line the run named.
 *
 * They exist because the FIRST prediction was refuted.  A said case 7
 * would fail -- two register pairs live at once -- and case 7 compiles.
 * B held: the discriminator is that the two structs are DIFFERENT
 * TYPES, since `d->offset = e->offset' through two `Dst *' is fine and
 * `d->offset = s->size' through a `Dst *' and a `Src *' is not.
 *
 * So what is it about Src that Dst is not?  Three things at once, and
 * these separate them:
 *
 *	Src has no self-pointer      Dst ends with `Dst *next'
 *	Src is 8 bytes shorter       (so a different t->width)
 *	Src's member is `size'       Dst's is `offset'
 */

typedef struct Twin Twin;
typedef struct Plain Plain;

/* Twin is Dst's layout EXACTLY, under another tag: self-referential,
 * same width, same member name. If case 12 fails, the mere difference
 * of TAG is enough and nothing about layout matters. */
struct Twin
{
	char	*name;
	int	type;
	int	len;
	vlong	offset;
	Twin	*next;
};

/* Plain is Src's layout with Dst's member NAME: not self-referential,
 * 8 bytes shorter, member called `offset'. Between 12 and 13 the name
 * is held constant, so a difference between them is layout. */
struct Plain
{
	char	*name;
	int	type;
	int	len;
	vlong	offset;
};

void
case12(Dst *d, Twin *w)
{
	d->offset = w->offset;
}

void
case13(Dst *d, Plain *p)
{
	d->offset = p->offset;
}

/* 14: case 1 BACKWARDS. If one direction fails and the other does not,
 * the fault is in the store or the load and not in the pair of types. */
void
case14(Dst *d, Src *s)
{
	s->size = d->offset;
}

/*
 * CASE 15, and it is ONE VARIABLE, which 12 to 14 were not.
 *
 * ***BOTH HYPOTHESES ARE NOW DEAD.*** A (two register pairs live at
 * once) died on case 7.  B (the two structs being different TYPES)
 * died on **case 14**: `s->size = d->offset' is the SAME pair of types
 * as case 1, merely reversed, and it compiles.
 *
 * And 12, 13 and 14 each varied THREE things from case 1 -- tag,
 * layout and member name -- which is the very fault named one
 * paragraph above them.  *Writing the rule down did not stop me
 * repeating it.*  What they do establish, between them and cases 4, 6,
 * 10 and 11, is how narrow this is:
 *
 *	d->offset = s->size      case 1   FAILS
 *	s->size   = d->offset    case 14  passes  (same two types!)
 *	gdst      = s->size      case 10  passes  (same source!)
 *	d->offset = gsrc         case 11  passes  (same dest!)
 *	d->offset = p->offset    case 13  passes  (Src's LAYOUT)
 *	return s->size           case 4   passes
 *
 * So `Src.size' loads fine, `Dst.offset' stores fine, and only the two
 * together fail -- while `Plain.offset', which has `Src''s layout,
 * stores into `Dst.offset' happily.
 *
 * `Plain' differs from `Src' in exactly three ways: the member is
 * called `offset' rather than `size', the tag is different, and it is
 * declared at the BOTTOM of this file rather than the top.  **Case 15
 * holds two of those and moves one**: `Named' is `Plain' with the
 * member renamed `size'.
 *
 *   it FAILS  -> the member NAME is the trigger.  Strange enough to
 *                be worth knowing, and it would point at `dotsearch'
 *                and the Sym rather than at anything about types.
 *   it PASSES -> the name is innocent, and what is left is `Src'
 *                itself: its tag, or its position at the top of the
 *                file.  Separating THOSE needs a struct declared early,
 *                which moves line 181, so it is deliberately not in
 *                this round.
 */

typedef struct Named Named;

struct Named
{
	char	*name;
	int	type;
	int	len;
	vlong	size;
};

void
case15(Dst *d, Named *q)
{
	d->offset = q->size;
}

void
main(void)
{
	Src s;
	Dst d;

	s.name = "src";
	s.type = 'T';
	s.len = 3;
	s.size = 0x1122334455667788LL;

	d.name = "dst";
	d.type = 'D';
	d.len = 3;
	d.offset = 0;
	d.next = nil;

	case1(&d, &s);
	print("case1 %lld\n", d.offset);
	print("case2 %lld\n", case2(s.size));
	case3(&d, 42L);
	print("case3 %lld\n", d.offset);
	print("case4 %lld\n", case4(&s));
	d.offset = 1;
	case5(&d);
	print("case5 %lld\n", d.offset);
	case6(&s);

	{
		Dst e;

		e = d;
		e.offset = 7;
		case7(&d, &e);
		print("case7 %lld\n", d.offset);
	}
	case8(&d, &s);
	print("case8 %lld\n", d.offset);
	gsrc = 0x7fffffff00000001LL;
	case9();
	print("case9 %lld\n", gdst);
	case10(&s);
	print("case10 %lld\n", gdst);
	case11(&d);
	print("case11 %lld\n", d.offset);
	{
		Twin w;
		Plain pl;

		w.offset = 11;
		pl.offset = 12;
		case12(&d, &w);
		print("case12 %lld\n", d.offset);
		case13(&d, &pl);
		print("case13 %lld\n", d.offset);
	}
	case14(&d, &s);
	print("case14 %lld\n", s.size);
	{
		Named q;

		q.size = 15;
		case15(&d, &q);
		print("case15 %lld\n", d.offset);
	}

	print("regpair-probe: it COMPILED, which is the whole result\n");
	exits(0);
}
