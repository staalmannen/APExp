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

	printf("sizeof(struct opflags) = %d (2 bit field bytes + 2 U8"
	       " is 4)\n", (int)sizeof(struct opflags));
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

	if (failures == 0)
		printf("\nall bit field cases passed\n");
	else
		printf("\n%d bit field case%s failed\n", failures,
		    failures == 1 ? "" : "s");
	return failures;
}
