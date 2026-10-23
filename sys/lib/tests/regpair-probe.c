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

	print("regpair-probe: it COMPILED, which is the whole result\n");
	exits(0);
}
