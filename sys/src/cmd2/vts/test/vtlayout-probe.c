/*
 * vtlayout-probe -- do libvterm's `state' and `in_esc' share storage?
 *
 * THIS IS A PROBE ON THE REAL STRUCT. Not a model of it: the previous
 * two rounds both reasoned from a struct I retyped into
 * sys/lib/tests/bitfield-test.c, and both were wrong. This one
 * includes libvterm's own `vterm_internal.h' and pokes the actual
 * declaration with the actual compiler.
 *
 *	6c -I../../../lib/libvterm vtlayout-probe.c
 *	6l -o vtlayout-probe vtlayout-probe.6
 *	./vtlayout-probe
 *
 * IT LINKS, AND THAT IS NOT LUCK. Including `vterm_internal.h'
 * completes libvterm's opaque types, which is what made
 * `vtparse-probe' fail to link -- but only because that one CALLS
 * libvterm. This one calls nothing from the library, so there is no
 * second object to disagree with and libc is the whole link.
 *
 * ------------------------------------------------------------------
 * THE QUESTION, AND WHY IT IS WORTH A FILE.
 *
 * `vtparse-probe' measured that every CSI sequence loses the parser
 * state after exactly one byte: ESC, `[' and one more are consumed
 * and the rest is printed, for seven different sequences. The only
 * mechanism that fit was
 *
 *	enum { NORMAL, CSI_LEADER, ... } state;
 *	bool in_esc : 1;
 *
 * overlapping, so that ENTER_STATE(CSI_LEADER) -- a store of 1 --
 * lights `in_esc' and the next byte takes the escape path.
 *
 * **That was tested in bitfield-test section 10 and REFUTED**: a
 * retyped copy of the same shape passes both directions on 9front.
 * But the copy is not the original. libvterm's `parser' is a NESTED
 * anonymous struct inside VTerm, preceded by another nested struct of
 * bit fields (`mode'), and kencc has a documented rule about nested
 * struct members (6c/swt.c's `align()', case Ael1). So the retyped
 * version could pass while the real one does not.
 *
 * *A model of a struct is not the struct* -- the same lesson as
 * "replicate the code in the tree, line by line, not the code you
 * remember", which is already in CLAUDE.md and which I have now paid
 * for twice in one investigation.
 */

#include <u.h>
#include <libc.h>
#include <vterm.h>
#include <vterm_internal.h>

static VTerm vt;	/* static, so it starts zeroed */

static void
hexdump(char *what, void *p, int n)
{
	uchar *b = p;
	int i;

	print("    %-28s", what);
	for(i = 0; i < n; i++)
		print(" %02x", b[i]);
	print("\n");
}

void
main(int, char**)
{
	int bad = 0;

	print("vtlayout-probe: libvterm's own parser struct, this compiler\n\n");
	print("  sizeof(VTerm)          = %d\n", (int)sizeof(VTerm));
	print("  sizeof(vt.parser)      = %d\n", (int)sizeof vt.parser);
	print("  sizeof(vt.parser.state)= %d\n", (int)sizeof vt.parser.state);
	print("  sizeof(vt.mode)        = %d\n", (int)sizeof vt.mode);
	print("  NORMAL=%d CSI_LEADER=%d CSI_ARGS=%d\n\n",
		(int)NORMAL, (int)CSI_LEADER, (int)CSI_ARGS);

	/*
	 * 1. Write the enum, read the bit field. This is the direction
	 *    the parser actually takes -- ENTER_STATE(CSI_LEADER) is a
	 *    store of 1 into `state', and the very next byte reads
	 *    `in_esc'.
	 */
	memset(&vt.parser, 0, sizeof vt.parser);
	vt.parser.state = CSI_LEADER;
	hexdump("after state=CSI_LEADER:", &vt.parser, 16);
	print("    -> state=%d in_esc=%d intermedlen=%d\n",
		(int)vt.parser.state, (int)vt.parser.in_esc,
		vt.parser.intermedlen);
	if(vt.parser.in_esc != 0){
		print("    *** in_esc became TRUE when nothing set it.\n");
		print("    *** That is the whole bug: the byte after `[' then\n");
		print("    *** takes the escape path, resets state to NORMAL,\n");
		print("    *** and everything after it is printed as text.\n");
		bad++;
	}
	if(vt.parser.intermedlen != 0){
		print("    *** intermedlen was disturbed too.\n");
		bad++;
	}

	/* 2. And the other direction, for completeness. */
	memset(&vt.parser, 0, sizeof vt.parser);
	vt.parser.in_esc = 1;
	hexdump("after in_esc=1:", &vt.parser, 16);
	print("    -> state=%d in_esc=%d intermedlen=%d\n",
		(int)vt.parser.state, (int)vt.parser.in_esc,
		vt.parser.intermedlen);
	if(vt.parser.state != NORMAL){
		print("    *** state was disturbed by writing in_esc.\n");
		bad++;
	}

	/*
	 * 3. Does the state survive a write to the member AFTER the bit
	 *    field? The parser sets intermedlen on the CSI_ARGS ->
	 *    CSI_INTERMED fallthrough, and if that store reaches `state'
	 *    the symptom is identical.
	 */
	memset(&vt.parser, 0, sizeof vt.parser);
	vt.parser.state = CSI_ARGS;
	vt.parser.intermedlen = 0;
	print("    after state=CSI_ARGS then intermedlen=0: state=%d in_esc=%d\n",
		(int)vt.parser.state, (int)vt.parser.in_esc);
	if(vt.parser.state != CSI_ARGS){
		print("    *** state did not survive the neighbouring store.\n");
		bad++;
	}

	/*
	 * 4. THE POSITIVE CONTROL. If every read above answered 0 for
	 *    reasons of its own, sections 1-3 would all look clean. So
	 *    check that the fields can hold what they are given at all.
	 *    *A check that cannot fail is not a check.*
	 */
	memset(&vt.parser, 0, sizeof vt.parser);
	vt.parser.state = CSI_INTERMED;
	vt.parser.in_esc = 1;
	vt.parser.intermedlen = 7;
	print("\n    CONTROL, all three set: state=%d (want %d) in_esc=%d "
		"(want 1) intermedlen=%d (want 7)\n",
		(int)vt.parser.state, (int)CSI_INTERMED,
		(int)vt.parser.in_esc, vt.parser.intermedlen);
	if(vt.parser.state != CSI_INTERMED || vt.parser.in_esc == 0
	    || vt.parser.intermedlen != 7){
		print("    *** THE CONTROL FAILED -- the three fields cannot\n");
		print("    *** even hold distinct values, so everything above\n");
		print("    *** is meaningless and this is the finding.\n");
		bad++;
	}

	print("\n%d problem%s\n", bad, bad == 1 ? "" : "s");
	if(bad == 0){
		print("The layout is innocent. So the state IS being kept and\n");
		print("lost some other way -- next suspect is how the bytes\n");
		print("reach the loop at all: read vterm_input_write and check\n");
		print("whether it hands the parser one byte per call.\n");
	}
	exits(bad ? "bad" : nil);
}
