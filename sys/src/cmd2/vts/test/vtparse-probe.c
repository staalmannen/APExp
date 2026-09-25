/*
 * vtparse-probe -- does libvterm consume `ESC [ ? 2004 h', or print it?
 *
 * THIS IS A PROBE. It asserts almost nothing; it feeds a fixed byte
 * string to libvterm and prints what landed on the screen and what the
 * parser's state was after every byte.
 *
 * NATIVE, not APE -- libvterm is built by 6c against Plan 9's own libc
 * (see ../mkfile), so this is too:
 *
 *	6c -FTVw -I.. -I../../../lib/libvterm vtparse-probe.c
 *	6l -o vtparse-probe vtparse-probe.6
 *	./vtparse-probe
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
 *   (a) LIBVTERM mis-parses the sequence. Then this probe reproduces
 *       it with no vts, no 9P and no terminal in the picture at all,
 *       and the state trace names the byte where it goes wrong.
 *   (b) LIBVTERM IS FINE and vts feeds it something other than what
 *       the log printed -- engine_feed, the tty write arm, or a
 *       second writer interleaving into one parser (which this tree
 *       has already suspected once). Then this probe comes back
 *       clean and the next round is in vts, not upstream.
 *
 * A probe that reuses the code under suspicion cannot clear it, so
 * this one calls libvterm directly and formats the screen itself.
 *
 * ------------------------------------------------------------------
 * WHAT WAS ALREADY RULED OUT, so nobody re-runs it.
 *
 * The first hypothesis was kencc: libvterm holds its escape flag as
 * `bool in_esc : 1' (vterm_internal.h), the sequence is consumed by
 * CLEARING that flag, and a one-bit field that takes a 1 and ignores a
 * 0 would leave the parser inside an escape -- which is this exact
 * shape. **REFUTED**: sys/lib/tests/bitfield-test.c section 10 sets a
 * bool bit field, clears it with `false', clears it with `0', does the
 * same for an `unsigned : 1' beside it and checks the neighbours --
 * all pass on 9front. And the types match: APE's <stdbool.h> does not
 * redefine `bool' (it is kencc's own keyword, an unsigned char) and
 * `pcc' IS `6c' with APE flags, so the test measured the same type and
 * the same compiler libvterm is built with.
 */

#include <u.h>
#include <libc.h>
#include <vterm.h>
#include "vterm_internal.h"	/* for parser.state and parser.in_esc */

static char *
statename(int s)
{
	switch(s){
	case NORMAL:		return "NORMAL";
	case CSI_LEADER:	return "CSI_LEADER";
	case CSI_ARGS:		return "CSI_ARGS";
	case CSI_INTERMED:	return "CSI_INTERMED";
	case OSC_COMMAND:	return "OSC_COMMAND";
	case DCS_COMMAND:	return "DCS_COMMAND";
	case OSC:		return "OSC";
	case DCS:		return "DCS";
	case APC:		return "APC";
	case PM:		return "PM";
	case SOS:		return "SOS";
	}
	return "?";
}

static void
showrow(VTermScreen *vs, int row, int cols)
{
	VTermPos pos;
	VTermScreenCell cell;
	int col, last;

	/* Find the last non-blank so the line is readable. */
	last = -1;
	for(col = 0; col < cols; col++){
		pos.row = row;
		pos.col = col;
		if(vterm_screen_get_cell(vs, pos, &cell) && cell.chars[0] != 0
		    && cell.chars[0] != ' ')
			last = col;
	}
	print("  row %d: \"", row);
	for(col = 0; col <= last; col++){
		pos.row = row;
		pos.col = col;
		if(!vterm_screen_get_cell(vs, pos, &cell) || cell.chars[0] == 0)
			print(" ");
		else
			print("%C", (Rune)cell.chars[0]);
	}
	print("\"  (last non-blank column %d)\n", last);
}

void
main(int, char**)
{
	VTerm *vt;
	VTermScreen *vs;
	/* Exactly what the server logged, and nothing else. */
	static char seq[] = { 0x1b, '[', '?', '2', '0', '0', '4', 'h' };
	int i, rows = 24, cols = 80;

	vt = vterm_new(rows, cols);
	vterm_set_utf8(vt, 1);
	vs = vterm_obtain_screen(vt);
	vterm_screen_reset(vs, 1);

	print("vtparse-probe: feeding ESC [ ? 2 0 0 4 h, one byte at a time\n");
	print("  (state BEFORE any byte: %s, in_esc=%d)\n",
		statename(vt->parser.state), (int)vt->parser.in_esc);

	for(i = 0; i < (int)sizeof seq; i++){
		vterm_input_write(vt, &seq[i], 1);
		print("  byte %d = 0x%02x %c -> state %s, in_esc=%d\n",
			i, (uchar)seq[i],
			(seq[i] >= 32 && seq[i] < 127) ? seq[i] : '.',
			statename(vt->parser.state),
			(int)vt->parser.in_esc);
	}

	/*
	 * Then the prompt bash sends next, because the SCREEN is what the
	 * question is really about and `$ ' is what it landed beside.
	 */
	vterm_input_write(vt, "$ ", 2);

	print("\nscreen after the sequence and `$ ':\n");
	showrow(vs, 0, cols);

	print("\nHOW TO READ IT:\n");
	print("  row 0 == \"$ \" and last non-blank column 0  ->  libvterm\n");
	print("      CONSUMED the sequence. The fault is in vts: what it\n");
	print("      feeds the engine is not what its own log printed.\n");
	print("  row 0 contains \"2004h\"  ->  libvterm PRINTED it, with no\n");
	print("      vts anywhere. The per-byte trace above names where:\n");
	print("      byte 1 ([) should reach CSI_LEADER, byte 2 (?) should\n");
	print("      stay there, and bytes 3..6 should be CSI_ARGS.\n");

	/*
	 * ONE assertion, because the whole question is binary and a reader
	 * should not have to count columns. Everything above is the
	 * evidence; this is the verdict.
	 */
	{
		VTermPos pos;
		VTermScreenCell cell;
		int printed = 0;

		pos.row = 0;
		pos.col = 0;
		if(vterm_screen_get_cell(vs, pos, &cell) && cell.chars[0] == '2')
			printed = 1;
		print("\n%s\n", printed ?
			"PRINTED: libvterm emitted the sequence as text." :
			"CONSUMED: libvterm swallowed the sequence.");
		exits(printed ? "printed" : nil);
	}
}
