/*
 * vtparse-probe -- does libvterm consume `ESC [ ? 2004 h', or print it?
 *
 * THIS IS A PROBE. It feeds a fixed byte string to libvterm and prints
 * what landed on the screen; the only thing it asserts is the one
 * binary answer, at the end.
 *
 * NATIVE, not APE -- libvterm is built by 6c against Plan 9's own libc
 * (see ../mkfile), so this is too. From this directory:
 *
 *	6c -I../../../../../sys/include vtparse-probe.c
 *	6l -o vtparse-probe vtparse-probe.6
 *	./vtparse-probe
 *
 * THOSE FLAGS ARE COPIED FROM ../mkfile AND THE COPYING IS THE POINT.
 * vts builds with
 *
 *	CFLAGS= -I$APEXPROOT/sys/include
 *
 * which REPLACES the CFLAGS mkone inherited from /$objtype/mkfile
 * rather than adding to them -- so vts compiles with **no `-T`**, and
 * its objects carry no type signatures. libvterm, whose mkfile says
 * `CFLAGS=$CFLAGS -I.', keeps 9front's `-FTVw' and does carry them.
 * kencc's linker only objects when BOTH sides have a signature for
 * the same symbol, which is why vts links and why a probe built with
 * `-FTVw' does not:
 *
 *	sb_pushline_from_row: incompatible type signatures
 *	bce1af83(vtparse-probe.6) and be0d91f(libvterm.a(vterm_obtain_screen))
 *	for vterm_screen_get_cell
 *
 * *Put a test binary in the directory whose flags it shares* is
 * already a rule here; this is the same rule for a directory whose
 * mkfile overrides the flags rather than extending them. **Build a
 * probe the way the thing it probes is built, and read the mkfile to
 * find out how -- do not assume the tree-wide CFLAGS apply.**
 *
 * And the include path is `sys/include', not `sys/src/lib/libvterm',
 * because libvterm keeps TWO tracked copies of its public headers and
 * vts compiles against the installed one. They are identical today --
 * diffed -- but its mkfile warns that nothing keeps them so.
 *
 * ------------------------------------------------------------------
 * WHY IT EXISTS, and what it SPLITS.
 *
 * Under vts, readline's bracketed-paste sequence reached the terminal
 * whole -- the server logged `tty write 8 [<1b>[?2004h]' -- and five
 * of those eight bytes appeared on the screen as the text `2004h'.
 * The cursor column confirmed it arithmetically rather than by eye:
 * the session's ctl reported `cursor=1,60', and 53 (the debug line
 * above it) + 5 + 2 for the prompt is exactly 60.
 *
 * Two places can do that and they need completely different fixes:
 *
 *   (a) LIBVTERM mis-parses it. Then this probe reproduces it with no
 *       vts, no 9P and no terminal in the picture, and the per-prefix
 *       table below names the byte at which the text appears.
 *   (b) LIBVTERM IS FINE and vts feeds the engine something other than
 *       what its own log printed -- engine_feed, the tty write arm, or
 *       a second writer interleaving into one parser, which this tree
 *       has suspected once already. Then this comes back clean and the
 *       next round is in vts, not upstream.
 *
 * IT ANSWERED (a), AND THE ANSWER WAS NOT IN LIBVTERM'S SOURCE.
 * Every CSI consumed exactly three bytes and printed the rest -- seven
 * sequences, no slack -- because kencc's C23 `false' carried a stale
 * pointer rather than 0, so parser.c's `vt->parser.in_esc = false' in
 * the ESC-to-C1 hoist never cleared the flag while the `= 0' beside it
 * did. sys/src/cmd/cc/lex.c, three lines; libvterm untouched.
 *
 * **WHICH MAKES A CLEAN RUN OF THIS PROBE AMBIGUOUS FROM NOW ON.** It
 * clears the libvterm in front of it, built by the compiler in front
 * of it. A stale libvterm.a, or a vts still linked against one, reads
 * identically to a fixed tree from here -- so a clean table beside a
 * dirty SCREEN is a build question before it is a vts question.
 *
 * A probe that reuses the code under suspicion cannot clear it, so
 * this one calls libvterm directly and never goes near celldiff.
 *
 * ------------------------------------------------------------------
 * PUBLIC API ONLY, AND THAT IS NOT A STYLE CHOICE.
 *
 * The first version of this file included <vterm_internal.h> to print
 * `parser.state' after each byte. It compiled and then would not link:
 *
 *	sb_pushline_from_row: incompatible type signatures
 *	bce1af83(vtparse-probe.6) and be0d91f(libvterm.a(vterm_obtain_screen))
 *	for vterm_screen_get_cell
 *
 * which is the FAMILY of an invariant this tree already had written
 * down: **kencc's type signatures follow POINTERS into the struct they
 * point at**, and 9front's `-FTVw' turns them on for every native
 * build, so completing an opaque type in one file makes that file
 * disagree with every other about every function that can reach it.
 * *Fifteen link errors in libvterm were this one thing.*
 *
 * BUT NOT EXACTLY, AND THE DIFFERENCE IS RECORDED RATHER THAN GUESSED.
 * `vterm.h' already carries `#pragma incomplete' for VTerm,
 * VTermState and VTermScreen, and the note says the pragma is read by
 * signat() and that completing the struct afterwards does NOT clear
 * it. On that reading this link should have worked. It did not. So
 * either the pragma's protection is narrower than the note claims, or
 * the type that actually diverged is something else the internal
 * header drags in. **Unresolved, and left unresolved** -- it is not
 * what this probe is for, and the probe does not need the internal
 * header at all once the question is asked behaviourally.
 *
 * So the state trace is gone and the question is asked BEHAVIOURALLY
 * instead: feed the first n bytes to a fresh terminal, for n = 1..8,
 * and count what is on screen. The n at which characters first appear
 * is the byte the parser stopped consuming at -- the same information,
 * through the public API, and immune to the trap.
 *
 * ------------------------------------------------------------------
 * ALREADY RULED OUT, so nobody re-runs it.
 *
 * The first hypothesis was kencc: libvterm holds its escape flag as
 * `bool in_esc : 1', the sequence is consumed by CLEARING that flag,
 * and a one-bit field that takes a 1 and ignores a 0 would leave the
 * parser inside an escape -- this exact shape. **REFUTED**:
 * sys/lib/tests/bitfield-test.c section 10 passes on 9front, and the
 * types match (APE's <stdbool.h> does not redefine `bool' -- it is
 * kencc's own keyword -- and `pcc' IS `6c' with APE flags).
 */

#include <u.h>
#include <libc.h>
#include <vterm.h>

/* Exactly what the server logged, and nothing else. */
static char seq[] = { 0x1b, '[', '?', '2', '0', '0', '4', 'h' };

enum { Rows = 24, Cols = 80 };

/*
 * How many characters are on row 0, and what they are. Blank cells
 * read back as a space or as nothing depending on how the row was
 * touched, so both count as empty.
 */
static int
row0(VTermScreen *vs, char *out, int nout)
{
	VTermPos pos;
	VTermScreenCell cell;
	int col, n, o;

	n = 0;
	o = 0;
	for(col = 0; col < Cols; col++){
		pos.row = 0;
		pos.col = col;
		if(!vterm_screen_get_cell(vs, pos, &cell))
			break;
		if(cell.chars[0] == 0 || cell.chars[0] == ' ')
			continue;
		n++;
		if(o < nout - 8)
			o += snprint(out+o, nout-o, "%C", (Rune)cell.chars[0]);
	}
	out[o] = 0;
	return n;
}

/* Feed the first n bytes to a FRESH terminal and report row 0. */
static int
feedprefix(int n, char *out, int nout)
{
	VTerm *vt;
	VTermScreen *vs;
	int got;

	vt = vterm_new(Rows, Cols);
	vterm_set_utf8(vt, 1);
	vs = vterm_obtain_screen(vt);
	vterm_screen_reset(vs, 1);
	vterm_input_write(vt, seq, n);
	got = row0(vs, out, nout);
	vterm_free(vt);
	return got;
}

/*
 * A TABLE OF SEQUENCES, because the prefix scan localised the byte and
 * then the source said that byte cannot print.
 *
 * After `?' the parser must be in CSI_LEADER (parser.c's `case 0x9b'
 * does `leaderlen = 0; ENTER_STATE(CSI_LEADER)'), and a digit there
 * falls through to CSI_ARGS and is accumulated. It is not accumulated.
 * So an assumption is wrong, and these ask which one -- each to a
 * fresh terminal, each expecting to leave the screen EMPTY.
 *
 * `hi' is the POSITIVE CONTROL and is not decoration: without it, a
 * row0() that always answered 0 would make every other line read as a
 * pass. *A check that cannot fail is not a check.*
 */
static struct {
	char *what;
	char *seq;		/* NUL-terminated: strlen, never a hand count */
	int wantprinted;	/* how many characters SHOULD reach the screen */
} table[] = {
	{ "plain text (POSITIVE CONTROL -- must print)",	"hi",		2 },
	{ "ESC M     (RI, a bare escape)",		"\033M",	0 },
	{ "ESC [ H   (CSI, no leader, no args)",	"\033[H",	0 },
	{ "ESC [ 2 J (CSI, one argument)",		"\033[2J",	0 },
	{ "ESC [ 1 m (CSI, SGR)",			"\033[1m",	0 },
	{ "ESC [ 2004 h  (CSI, args, NO leader)",	"\033[2004h",	0 },
	{ "ESC [ ? h (CSI, leader, no args)",		"\033[?h",	0 },
	{ "ESC [ ? 1 h  (CSI, leader + one digit)",	"\033[?1h",	0 },
	{ "ESC [ ? 2004 h  (the one that fails)",	"\033[?2004h",	0 },
};

static int
feedbytes(char *p, int n, char *out, int nout)
{
	VTerm *vt;
	VTermScreen *vs;
	int got;

	vt = vterm_new(Rows, Cols);
	vterm_set_utf8(vt, 1);
	vs = vterm_obtain_screen(vt);
	vterm_screen_reset(vs, 1);
	vterm_input_write(vt, p, n);
	got = row0(vs, out, nout);
	vterm_free(vt);
	return got;
}

void
main(int, char**)
{
	char buf[256];
	int i, got, first, bad;

	print("vtparse-probe: ESC [ ? 2 0 0 4 h, fed as prefixes of 1..8 bytes\n");
	print("  (each to a FRESH terminal, so nothing carries over)\n\n");

	first = 0;
	for(i = 1; i <= (int)sizeof seq; i++){
		got = feedprefix(i, buf, sizeof buf);
		print("  first %d byte%s -> %d char%s on row 0  \"%s\"\n",
			i, i == 1 ? " " : "s", got, got == 1 ? " " : "s", buf);
		if(got > 0 && first == 0)
			first = i;
	}

	/* And the whole thing followed by the prompt bash sends next,
	 * because `$ ' is what the text landed beside on the real screen. */
	{
		VTerm *vt;
		VTermScreen *vs;

		vt = vterm_new(Rows, Cols);
		vterm_set_utf8(vt, 1);
		vs = vterm_obtain_screen(vt);
		vterm_screen_reset(vs, 1);
		vterm_input_write(vt, seq, sizeof seq);
		vterm_input_write(vt, "$ ", 2);
		got = row0(vs, buf, sizeof buf);
		print("\n  the eight bytes then \"$ \" -> %d char%s  \"%s\"\n",
			got, got == 1 ? "" : "s", buf);
		vterm_free(vt);
	}

	/*
	 * The table. Run it whatever the prefix scan said: if the
	 * sequence turns out to be consumed after all, these still say
	 * whether CSI works at all, and that is worth knowing either way.
	 */
	print("\n  ---- other sequences, each to a fresh terminal ----\n");
	bad = 0;
	for(i = 0; i < (int)(sizeof table / sizeof table[0]); i++){
		got = feedbytes(table[i].seq, strlen(table[i].seq),
			buf, sizeof buf);
		print("  %-44s -> %d printed \"%s\"%s\n",
			table[i].what, got, buf,
			got == table[i].wantprinted ? "" : "   <<< UNEXPECTED");
		if(got != table[i].wantprinted)
			bad++;
	}
	print("  (%d of %d unexpected)\n", bad,
		(int)(sizeof table / sizeof table[0]));
	print("\n  HOW TO READ THE TABLE:\n");
	print("    the control prints and NOTHING else does -> the parser\n");
	print("        is fine and the failing sequence is not what we think.\n");
	print("    `ESC [ H' prints too -> CSI never starts; the fault is\n");
	print("        the ESC-to-C1 hoist or the 0x9b dispatch, not the\n");
	print("        leader or the arguments.\n");
	print("    `ESC [ H' is clean but `ESC [ 2 J' prints -> ARGUMENTS.\n");
	print("    only the leader forms print -> the `?' path.\n");
	print("    the CONTROL prints 0 -> row0() is broken and every other\n");
	print("        line above is meaningless. Fix that first.\n");

	print("\n");
	if(first == 0){
		print("CONSUMED: libvterm swallowed the whole sequence.\n");
		print("  This clears the libvterm YOU JUST BUILT. It does not\n");
		print("  say libvterm was always innocent, and the history here\n");
		print("  is exactly that trap: this probe once printed `2004h'\n");
		print("  and the cause was kencc's C23 `false' evaluating to a\n");
		print("  stale pointer, so `in_esc = false' never cleared. The\n");
		print("  fix was in sys/src/cmd/cc/lex.c and libvterm's source\n");
		print("  did not change a character.\n");
		print("  So if the SCREEN still shows the text while this says\n");
		print("  CONSUMED, ask FIRST whether vts was relinked against\n");
		print("  this libvterm.a -- `mk clean' in cmd2, not just mk.\n");
		print("  Only once the two disagree on the SAME build is the\n");
		print("  answer in what vts feeds the engine: engine_feed, the\n");
		print("  tty write arm, or a second writer interleaving into\n");
		print("  one parser.\n");
		exits(nil);
	}
	print("PRINTED: libvterm emitted part of the sequence as text.\n");
	print("  It first appears at byte %d (0x%02x '%c'), so everything\n",
		first, (uchar)seq[first-1],
		(seq[first-1] >= 32 && seq[first-1] < 127) ? seq[first-1] : '.');
	print("  before it was consumed and the parser stopped there.\n");
	print("  Expected: byte 2 ([) reaches CSI_LEADER, byte 3 (?) stays,\n");
	print("  bytes 4..8 are arguments and the final. Read parser.c's\n");
	print("  case for whichever state byte %d should have been in.\n", first);
	exits("printed");
}
