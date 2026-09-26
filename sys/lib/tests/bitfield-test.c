/*
 * bitfield-test.c -- bit fields whose base type is not int.
 *
 * C99 6.7.2.1p4 lets an implementation offer bit fields of types other
 * than int/unsigned int/_Bool, and kencc's bit field support (the
 * kencc patch from @jamoson) accepts them. This checks that a field
 * declared in a *short* unit is allocated and accessed correctly --
 * particularly a field that lives above bit 7, i.e. in the second byte
 * of its unit, which is where a storage unit chosen by base type
 * rather than by the declaration differs from one chosen by width.
 *
 * The layout under test is perl's, from op.h:
 *
 *	#define BASEOP				\
 *	    OP*		op_next;		\
 *	    OP*		op_sibparent;		\
 *	    OP*		(*op_ppaddr)(pTHX);	\
 *	    PADOFFSET	op_targ;		\
 *	    PERL_BITFIELD16 op_type:9;		\
 *	    PERL_BITFIELD16 op_opt:1;		\
 *	    PERL_BITFIELD16 op_slabbed:1;	\
 *	    PERL_BITFIELD16 op_savefree:1;	\
 *	    PERL_BITFIELD16 op_static:1;	\
 *	    PERL_BITFIELD16 op_folded:1;	\
 *	    PERL_BITFIELD16 op_moresib:1;	\
 *	    PERL_BITFIELD16 op_spare:1;		\
 *	    U8		op_flags;		\
 *	    U8		op_private;
 *
 * with PERL_BITFIELD16 = U16, because perl's config.h for this tree
 * defines HAS_NON_INT_BITFIELDS. Nine bits of opcode number followed by
 * seven single-bit flags: exactly 16, so the whole thing is one U16 and
 * every flag but op_opt sits at bit 8 or above.
 *
 * Why it matters here: op_moresib is bit 14, and it is the *only* thing
 * that says whether an op has a next sibling --
 *
 *	#define OpSIBLING(o) (0 + (o)->op_moresib ? (o)->op_sibparent : NULL)
 *
 * Perl_op_linklist walks a node's children with that macro to build the
 * op_next chain the interpreter follows. If op_moresib reads back as 0
 * when it was set, every list collapses to its first element, and a
 * program compiles perfectly and then executes almost nothing: no
 * output, no diagnostics, exit status 0. Case 4 is that macro.
 *
 * Build and run:  pcc -o bitfield-test bitfield-test.c
 * Prints "PASS" per case; exit status is the number of failures.
 */

#include <stdio.h>
#include <string.h>
/* Section 10 needs `bool'. kencc has it as a real type now, and this
   header is what a portable program includes for it; on gcc it is the
   same type, which is the point of checking there first. */
#include <stdbool.h>

typedef unsigned short U16;
typedef unsigned char U8;

static int failures;

static void
check(const char *what, int ok, const char *detail)
{
	if (ok)
		printf("PASS  %s\n", what);
	else {
		printf("FAIL  %s%s%s\n", what, detail ? ": " : "",
		       detail ? detail : "");
		failures++;
	}
}

/* perl's flag word, standing alone so the offsets are easy to reason
   about. The pointers before it in BASEOP only add alignment. */
struct opflags {
	U16 op_type:9;
	U16 op_opt:1;
	U16 op_slabbed:1;
	U16 op_savefree:1;
	U16 op_static:1;
	U16 op_folded:1;
	U16 op_moresib:1;
	U16 op_spare:1;
	U8 op_flags;
	U8 op_private;
	/* stands in for op_sibparent, which in perl precedes the flags;
	   here it only has to be a pointer beside them */
	int *op_sibparent_test;
};

/* The same widths in an int unit, which is the case kencc has always
   had to handle. If this passes and the U16 one does not, the base type
   is what matters rather than the widths. */
struct intflags {
	unsigned f_type:9;
	unsigned f_opt:1;
	unsigned f_slabbed:1;
	unsigned f_savefree:1;
	unsigned f_static:1;
	unsigned f_folded:1;
	unsigned f_moresib:1;
	unsigned f_spare:1;
};

/* A char unit, the other non-int base type: two fields that cannot
   share a byte if the unit really is a char. */
struct charflags {
	U8 c_lo:4;
	U8 c_hi:4;
};

int
main(void)
{
	struct opflags o;
	struct intflags i;
	struct charflags c;
	int n, bad;
	char detail[128];

	printf("sizeof(struct opflags) = %d\n", (int)sizeof(struct opflags));
	printf("sizeof(struct intflags) = %d\n", (int)sizeof(struct intflags));
	printf("sizeof(struct charflags) = %d\n", (int)sizeof(struct charflags));

	/*
	 * 1. Every field holds its own value at the same time. This is
	 *    the whole layout in use at once, which is how perl uses it.
	 */
	memset(&o, 0, sizeof o);
	o.op_type = 401;		/* a plausible opcode number */
	o.op_opt = 1;
	o.op_slabbed = 1;
	o.op_savefree = 0;
	o.op_static = 1;
	o.op_folded = 0;
	o.op_moresib = 1;
	o.op_spare = 0;
	o.op_flags = 0x5a;
	o.op_private = 0xa5;

	sprintf(detail, "type=%d opt=%d slabbed=%d savefree=%d static=%d"
	    " folded=%d moresib=%d spare=%d flags=%02x private=%02x",
	    (int)o.op_type, (int)o.op_opt, (int)o.op_slabbed,
	    (int)o.op_savefree, (int)o.op_static, (int)o.op_folded,
	    (int)o.op_moresib, (int)o.op_spare,
	    (unsigned)o.op_flags, (unsigned)o.op_private);
	check("all U16 fields hold their values together",
	    o.op_type == 401 && o.op_opt == 1 && o.op_slabbed == 1 &&
	    o.op_savefree == 0 && o.op_static == 1 && o.op_folded == 0 &&
	    o.op_moresib == 1 && o.op_spare == 0 &&
	    o.op_flags == 0x5a && o.op_private == 0xa5, detail);

	/*
	 * 2. op_moresib on its own. Nothing else is set, so if it reads
	 *    back 0 the field is not where the write went; if some other
	 *    field reads back 1 the two overlap.
	 */
	memset(&o, 0, sizeof o);
	o.op_moresib = 1;
	sprintf(detail, "moresib=%d type=%d opt=%d slabbed=%d savefree=%d"
	    " static=%d folded=%d spare=%d",
	    (int)o.op_moresib, (int)o.op_type, (int)o.op_opt,
	    (int)o.op_slabbed, (int)o.op_savefree, (int)o.op_static,
	    (int)o.op_folded, (int)o.op_spare);
	check("op_moresib alone", o.op_moresib == 1 && o.op_type == 0 &&
	    o.op_opt == 0 && o.op_slabbed == 0 && o.op_savefree == 0 &&
	    o.op_static == 0 && o.op_folded == 0 && o.op_spare == 0, detail);

	/*
	 * 3. Writing the 9-bit field must not disturb the flags above
	 *    it, for any value it can hold. op_type is written on every
	 *    op perl builds, by OpTYPE_set, often after the flags.
	 */
	bad = -1;
	for (n = 0; n < 512; n++) {
		memset(&o, 0, sizeof o);
		o.op_moresib = 1;
		o.op_slabbed = 1;
		o.op_type = n;
		if (o.op_type != n || o.op_moresib != 1 || o.op_slabbed != 1) {
			bad = n;
			break;
		}
	}
	if (bad < 0)
		detail[0] = 0;
	else
		sprintf(detail, "op_type=%d gave type=%d moresib=%d"
		    " slabbed=%d", bad, (int)o.op_type, (int)o.op_moresib,
		    (int)o.op_slabbed);
	check("all 512 op_type values leave the flags alone", bad < 0,
	    bad < 0 ? NULL : detail);

	/* ... and the reverse: setting a flag must not disturb op_type. */
	memset(&o, 0, sizeof o);
	o.op_type = 511;
	o.op_moresib = 1;
	o.op_spare = 1;
	o.op_folded = 1;
	sprintf(detail, "type=%d", (int)o.op_type);
	check("flags leave op_type alone", o.op_type == 511, detail);

	/*
	 * 4. perl's OpSIBLING, which is what the interpreter's whole
	 *    execution order is built from.
	 */
	{
		int sib = 7, *sibparent = &sib, *got;

		memset(&o, 0, sizeof o);
		o.op_type = 178;
		o.op_moresib = 1;
		got = (0 + o.op_moresib) ? sibparent : NULL;
		check("OpSIBLING with op_moresib set", got == sibparent,
		    "returned NULL, so every op list has one element");

		o.op_moresib = 0;
		got = (0 + o.op_moresib) ? sibparent : NULL;
		check("OpSIBLING with op_moresib clear", got == NULL, NULL);
	}

	/*
	 * 5. The int-unit version of the same widths, as a control.
	 */
	memset(&i, 0, sizeof i);
	i.f_type = 401;
	i.f_moresib = 1;
	i.f_spare = 1;
	sprintf(detail, "type=%d moresib=%d spare=%d", (int)i.f_type,
	    (int)i.f_moresib, (int)i.f_spare);
	check("int-unit fields of the same widths",
	    i.f_type == 401 && i.f_moresib == 1 && i.f_spare == 1, detail);

	/*
	 * 6. char-unit fields, the other non-int base type.
	 */
	memset(&c, 0, sizeof c);
	c.c_lo = 0xd;
	c.c_hi = 0x3;
	sprintf(detail, "lo=%d hi=%d", (int)c.c_lo, (int)c.c_hi);
	check("char-unit fields", c.c_lo == 0xd && c.c_hi == 0x3, detail);

	/*
	 * 7. A field read straight after a write through a pointer, which
	 *    is how perl always touches these -- op_moresib is set by
	 *    op_sibling_splice on an OP * and read by OpSIBLING on
	 *    another. A compiler that keeps the unit in a register across
	 *    the two would pass everything above and still fail here.
	 */
	{
		struct opflags a, *p = &a;

		memset(&a, 0, sizeof a);
		p->op_type = 33;
		p->op_moresib = 1;
		p->op_folded = 1;
		sprintf(detail, "type=%d moresib=%d folded=%d",
		    (int)p->op_type, (int)p->op_moresib, (int)p->op_folded);
		check("through a pointer", p->op_type == 33 &&
		    p->op_moresib == 1 && p->op_folded == 1, detail);
	}

	/*
	 * 8. The value of an assignment to a bit field.
	 *
	 * C99 6.5.16p3: the value of an assignment expression is the
	 * value of the left operand after the assignment, converted to
	 * its type. For a bit field that is the stored value, so
	 * (o->op_moresib = 1) is 1.
	 *
	 * perl's op.h carries a note saying kencc gets this wrong --
	 * "bitfield-assign expression value is unreliable (always 0)" --
	 * and works around it in OpMAYBESIB_set. These cases say whether
	 * that is still true and how far it goes, because the macro as
	 * originally written is
	 *
	 *	((o)->op_sibparent = ((o)->op_moresib = cBOOL(sib))
	 *	                     ? (sib) : (parent))
	 *
	 * which reads the assignment's value to choose a branch. A zero
	 * there sets the sibling pointer to the parent while the flag
	 * says there is a sibling, or leaves the flag clear -- either
	 * way every op list in the program loses all but its first
	 * element.
	 */
	{
		int v;

		memset(&o, 0, sizeof o);
		v = (o.op_moresib = 1);
		sprintf(detail, "(bf = 1) gave %d, field holds %d", v,
		    (int)o.op_moresib);
		check("value of a 1-bit assignment", v == 1, detail);

		memset(&o, 0, sizeof o);
		v = (o.op_type = 401);
		sprintf(detail, "(bf = 401) gave %d, field holds %d", v,
		    (int)o.op_type);
		check("value of a 9-bit assignment", v == 401, detail);

		/* The store must happen even when the value is used. */
		sprintf(detail, "field holds %d after its value was read",
		    (int)o.op_type);
		check("a read value does not lose the store",
		    o.op_type == 401, detail);
	}

	/*
	 * 9. OpMAYBESIB_set as perl writes it upstream, which is where
	 *    the whole op tree's sibling links come from.
	 */
	{
		int sib = 7, parent = 9;
		int *sibp = &sib, *parentp = &parent, *got;
		struct opflags a;

		memset(&a, 0, sizeof a);
		a.op_sibparent_test = (a.op_moresib = (sibp != NULL))
		    ? sibp : parentp;
		got = (0 + a.op_moresib) ? a.op_sibparent_test : NULL;
		sprintf(detail, "moresib=%d, sibparent %s", (int)a.op_moresib,
		    a.op_sibparent_test == sibp ? "= sib" :
		    a.op_sibparent_test == parentp ? "= parent (wrong)" :
		    "= neither");
		check("OpMAYBESIB_set with a sibling", got == sibp, detail);

		memset(&a, 0, sizeof a);
		a.op_sibparent_test = (a.op_moresib = (NULL != NULL))
		    ? sibp : parentp;
		got = (0 + a.op_moresib) ? a.op_sibparent_test : NULL;
		sprintf(detail, "moresib=%d, sibparent %s", (int)a.op_moresib,
		    a.op_sibparent_test == parentp ? "= parent" : "= other");
		check("OpMAYBESIB_set without a sibling",
		    got == NULL && a.op_sibparent_test == parentp, detail);
	}

	/*
	 * 10. A `bool' BIT FIELD, and CLEARING one that is already set.
	 *
	 * WHERE THIS CAME FROM. Under vts, readline's bracketed-paste
	 * sequence `ESC [ ? 2 0 0 4 h' reached the terminal whole -- the
	 * server logged all eight bytes -- and the screen showed the last
	 * five, `2004h', as text. The cursor column confirmed it
	 * arithmetically: 53 (a debug line) + 5 + 2 for the prompt = 60,
	 * exactly what the session's ctl file reported.
	 *
	 * libvterm's parser holds its escape flag as
	 *
	 *	bool in_esc : 1;		(vterm_internal.h:205)
	 *
	 * and the sequence is consumed by setting it on ESC and CLEARING
	 * it when the following byte is hoisted into a C1 control. A
	 * one-bit field that accepts a 1 and ignores a 0 -- a store that
	 * ORs in the new value without first masking the old one out --
	 * would leave the parser believing it is still inside an escape,
	 * which is the shape of what the screen showed.
	 *
	 * THAT IS A HYPOTHESIS, and this section is how it is settled
	 * rather than argued: kencc's bit fields came from a patch that
	 * predates `bool' being a real type here, so a `bool' bit field
	 * may take a path `unsigned' does not.
	 *
	 * The `unsigned u : 1' beside it is what makes the answer
	 * ATTRIBUTABLE. If bool fails and unsigned passes, the base type
	 * is the discriminator; if both fail, it is clearing in general;
	 * if both pass, the reading above is wrong and libvterm's parser
	 * must be looked at directly. *A check whose negative result has
	 * two explanations is not a check.*
	 */
	{
		struct flags {
			enum { P_NORMAL, P_CSI_LEADER, P_CSI_ARGS } state;
			bool b : 1;
			unsigned u : 1;
			int after;
		} f;

		memset(&f, 0, sizeof f);
		f.state = P_CSI_LEADER;
		f.after = 12345;

		f.b = true;
		sprintf(detail, "b=%d after setting true", (int)f.b);
		check("bool bit field holds true", f.b != 0, detail);

		f.b = false;
		sprintf(detail, "b=%d after setting false over true",
		    (int)f.b);
		check("bool bit field CLEARS to false", f.b == 0, detail);

		/*
		 * WARNING: UNDER APE THESE TWO ARE THE SAME TEST.
		 *
		 * The intent was to ask both spellings, because libvterm
		 * clears the same flag with `= false' in one place and
		 * `= 0' in another. But APE's <stdbool.h> is literally
		 *
		 *	#define false 0
		 *
		 * so `f.b = false' preprocesses to `f.b = 0' and the two
		 * checks are one check written twice. **A duplicate dressed
		 * as two cases**, and it cannot distinguish a broken
		 * `false' from a working one.
		 *
		 * It CANNOT be fixed here. Native Plan 9 has no
		 * <stdbool.h>, so libvterm's `false' is kencc's own C23
		 * keyword, and no APE program can reach that spelling --
		 * the header is on the include path whether or not this
		 * file asks for it. The question therefore belongs to a
		 * NATIVE probe, and it is asked by
		 * sys/src/cmd2/vts/test/vtlayout-probe.c section 2b.
		 *
		 * Kept anyway: as a pair it is redundant, but it still
		 * checks that clearing works at all, and the comment is
		 * worth more than the line.
		 */
		f.b = true;
		f.b = 0;
		sprintf(detail, "b=%d after setting 0 over true", (int)f.b);
		check("bool bit field clears when assigned 0", f.b == 0,
		    detail);

		f.u = 1;
		sprintf(detail, "u=%u after setting 1", f.u);
		check("unsigned:1 bit field holds 1", f.u != 0, detail);

		f.u = 0;
		sprintf(detail, "u=%u after setting 0 over 1", f.u);
		check("unsigned:1 bit field CLEARS to 0", f.u == 0, detail);

		/* And the neighbours, because a store that writes a whole
		   word to set one bit takes its neighbours with it. */
		sprintf(detail, "state=%d after=%d", (int)f.state, f.after);
		check("bit field stores leave their neighbours alone",
		    f.state == P_CSI_LEADER && f.after == 12345, detail);

		/*
		 * AND THE OTHER DIRECTION, WHICH THIS TEST MISSED THE FIRST
		 * TIME AND WHICH IS THE ONE THAT MATTERS.
		 *
		 * The checks above all write the BIT FIELD and then read
		 * the neighbours. They say nothing about writing a
		 * NEIGHBOUR and reading the bit field -- and an overlap is
		 * symmetric, so testing one direction and calling the pair
		 * covered is exactly the "check whose negative result has
		 * two explanations" trap, one level up.
		 *
		 * WHAT ASKED FOR IT. libvterm's parser holds
		 *
		 *	enum { NORMAL, CSI_LEADER, ... } state;
		 *	bool in_esc : 1;
		 *
		 * and mis-parses every CSI sequence longer than three
		 * bytes, consuming ESC, `[' and exactly one more and then
		 * printing the rest -- measured for seven different
		 * sequences by sys/src/cmd2/vts/test/vtparse-probe.c. Every
		 * one of those seven is explained, exactly, if a store to
		 * `state' sets the `in_esc' bit: the byte after `[' then
		 * finds in_esc true, takes the escape path instead of the
		 * CSI path, resets the state to NORMAL and the rest is
		 * text.
		 *
		 * So: set the bit, write the neighbour, read the bit back.
		 */
		f.b = 0;
		f.u = 0;
		f.state = P_CSI_LEADER;		/* == 1, one bit set */
		sprintf(detail, "after state=%d: b=%d u=%u",
		    (int)f.state, (int)f.b, f.u);
		check("writing the enum neighbour leaves a false bool bit "
		    "field false", f.b == 0, detail);
		check("writing the enum neighbour leaves a 0 unsigned bit "
		    "field 0", f.u == 0, detail);

		f.b = 1;
		f.u = 1;
		f.state = P_NORMAL;		/* == 0 */
		sprintf(detail, "after state=%d: b=%d u=%u",
		    (int)f.state, (int)f.b, f.u);
		check("writing the enum neighbour leaves a true bool bit "
		    "field true", f.b != 0, detail);
		check("writing the enum neighbour leaves a 1 unsigned bit "
		    "field 1", f.u != 0, detail);

		/*
		 * And the layout itself, printed rather than asserted --
		 * if the two do overlap, the sizes say so and a reader
		 * should not have to infer it from four FAILs.
		 */
		printf("      (sizeof struct flags = %d; an enum is %d, "
		    "an int %d)\n",
		    (int)sizeof f, (int)sizeof f.state, (int)sizeof(int));
	}

	if (failures == 0)
		printf("\nall bit field cases passed\n");
	else
		printf("\n%d bit field case%s failed\n", failures,
		    failures == 1 ? "" : "s");
	return failures;
}
