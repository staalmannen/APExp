/*
 * edgscope-probe.c -- where does a member land AFTER a bit-field group
 * that FOLLOWS an ordinary member?
 *
 * WHERE THIS CAME FROM.  With the `offsetof' fix in (the sualign()
 * bit-field sharing change), cpfe under `--target win64' stopped
 * faulting at `fault read addr=0x68 pc=0x7e2d88' in
 * predeclare_entities -- before the source was read at all -- and
 * started faulting at `fault read addr=0x10 pc=0x861d21', in IL
 * pruning at the END of a function body.  So cpfe now parses the whole
 * translation unit and builds IL for it; what is left is further in.
 *
 * `lstk()' on the Broken process named the frame.  The recursion is
 * sound for seven frames, every pointer a real heap address --
 *
 *   prune_needed_flag_il_walk(entry_ptr=0x1c7efa8, entry_kind=0xb)
 *     -> walk_tree_and_set_needed(0x1c7efa8, 0xb)
 *     -> mark_as_needed(0x1c82ec0, 0xb)
 *     -> set_routine_definition_needed(rout=0x1c82ec0)
 *     -> mark_as_needed(0x1d7eb80, 0x19)
 *     -> mark_as_needed_basic(0x1d7eb80, 0x19)
 *     -> walk_tree_and_set_needed(0x1d7eb80, 0x19)
 *
 * -- and that last frame then calls ITSELF with (entry_ptr=0x8,
 * entry_kind=0x45).
 *
 * THE KINDS DECODE, AND THEY HAD TO BE DECODED FROM THE GENERATED
 * ENUM RATHER THAN FROM EDG'S HEADER.  `an_il_entry_kind' has
 * `#if'-guarded enumerators (MICROSOFT_EXTENSIONS_ALLOWED and more),
 * so its numbering depends on the macro configuration -- read
 * `src/il_def.h' and you get a different answer from the corpus that
 * actually runs.  Against `src/il.c''s own config-resolved enum:
 * 0x0b is `iek_routine', 0x19 is `iek_scope', and **0x45 is
 * `iek_ms_attribute'**.
 *
 * SO THE CALL IS NOT GARBAGE AND THE KIND IS EXACTLY RIGHT.
 * `walk_entry.h:3032', inside `case iek_scope:', is literally
 *
 *   walk_list(eptr->ms_attributes, an_ms_attribute_ptr,
 *             iek_ms_attribute);
 *
 * -- so the walker was reading `a_scope''s LAST member and the kind it
 * passed is the constant from that line.  What is wrong is the VALUE:
 * `eptr->ms_attributes' answered **8**.
 *
 * AND `a_scope' IS THE SHAPE THE SECOND, STILL-OPEN KENCC RULE
 * BREAKS.  Its prefix, from the generated C (`il.c:13799'), is three
 * pointers, an `int32_t', an `unsigned char', and THEN seven
 * `unsigned int :1' -- a bit-field group FOLLOWING ordinary members.
 * `structalign-test' section 9 reported that case as a PROBE and said
 * of it: *"a bit field following an ordinary member opens a fresh
 * container here.  Nothing has measured what it costs."*  This is
 * what it costs.
 *
 * ------------------------------------------------------------------
 * THE RULE IS FIXED NOW, so **a clean run of this is the regression
 * test and a dirty one is a BUILD question first.**  `cc/dcl.c's
 * `sualign()' shares the container's head as well as its tail under
 * `conformalign', so this must come back 0; if it does not, ask
 * whether `cd sys/src/cmd && mk install' preceded the rebuild before
 * asking anything about the rule.  *An instrument that bakes in the
 * conclusion for a branch keeps asserting it after the branch stops
 * being the live one* -- `vtparse-probe' already paid for that
 * sentence, so this one says it in advance.
 *
 * AND WHAT A CLEAN RUN DOES **NOT** SAY, which is the half to keep.
 * A consistent-but-different layout costs nothing on its own: pcc
 * lays `a_scope' out and pcc reads it back.  It bites only where a
 * constant is BAKED, and the whole 2.9M-line corpus holds exactly two
 * folded `offsetof' sites -- `trans_unit.h's pair, which the TAIL
 * rule already put back to 400/416, and `exprutil.h:577's
 * `offsetof(an_operand, variant)', folded as `expr.c:64388's
 * `memcpy(..., 152ULL)'.  **That second one never moved**: the member
 * after `an_operand's 23 bit fields is `a_name_reference', whose
 * alignment is 8, so `round(w, 8)' is 24 under every rule and
 * `variant' is 152 under every rule.  Computed, three ways, in
 * `sys/lib/tests/sualign-model.py's `an_operand' row.
 *
 * *So this probe measures a real non-conformance and is NOT known to
 * be cpfe's `fault read addr=0x10'.*  It was recorded as the cause
 * for one round on the strength of the 152, and the arithmetic
 * refutes that.
 *
 * WHAT THIS ASKS.  Section 1 is EDG's real prefix with one pointer
 * after it, so `offsetof(after)' isolates the rule with no union and
 * no 2.9M-line corpus in the way.  Section 2 is the same shape with
 * the `unsigned char' removed, so the bit field is FIRST -- the case
 * `edgtuoff-probe' already measured as agreeing once the container is
 * shared, and therefore the CONTROL: it must answer the same under
 * both compilers, or the disagreement in section 1 is not about this
 * rule at all.
 *
 * Section 3 is the two shapes `structalign-test' reports as a probe,
 * repeated here so one run carries its own reference.
 *
 * THE REFERENCE IS gcc, and legitimately so rather than by habit:
 * EDG, gcc and clang agree on this layout, the generated C was
 * written against it, and kencc under `-J' exists to join them.  The
 * host numbers are printed beside every answer.
 *
 * Build:
 *   gcc -o edgscope-probe edgscope-probe.c && ./edgscope-probe   # host
 *   pcc -o edgscope-probe edgscope-probe.c && ./edgscope-probe   # 9front
 *
 * Exit status is the number of disagreements with the host reference.
 * PLAIN `pcc', no flags: that is the rule the whole APE world and the
 * whole EDG corpus are built under.
 */

#include <stdio.h>
#include <stddef.h>

/* ---- section 1: a_scope's real prefix (il.c:13799) ---------------- */
struct scope_prefix {
	void		*next;
	void		*prev;
	void		*parent;
	int		number;			/* a_scope_number = int32_t */
	unsigned char	kind;			/* ordinary member ... */
	unsigned int	function_body_processing_finished : 1;	/* ... then */
	unsigned int	do_not_free_memory_region : 1;
	unsigned int	scope_orphaned_list_header_generated : 1;
	unsigned int	is_constexpr_routine : 1;
	unsigned int	is_stmt_expr_block : 1;
	unsigned int	is_placeholder_scope : 1;
	unsigned int	needed_walk_done : 1;
	void		*after;			/* `variant' in the real one */
};

/* ---- section 2: the control -- bit field FIRST in its run -------- */
struct scope_nochar {
	void		*next;
	void		*prev;
	void		*parent;
	int		number;
	unsigned int	b0 : 1;
	unsigned int	b1 : 1;
	unsigned int	b2 : 1;
	unsigned int	b3 : 1;
	unsigned int	b4 : 1;
	unsigned int	b5 : 1;
	unsigned int	b6 : 1;
	void		*after;
};

/* ---- section 3: structalign-test's two probe shapes -------------- */
struct bf_after_member {
	char		c;
	unsigned int	x : 1;
	char		d;
};

struct bf_alternating {
	unsigned int	x : 1;
	char		c;
	unsigned int	y : 1;
	char		d;
};

static int fails;

static void
eq(const char *what, long got, long want)
{
	if (got == want)
		printf("PASS %-34s %ld\n", what, got);
	else {
		printf("FAIL %-34s %ld   host says %ld\n", what, got, want);
		fails++;
	}
}

int
main(void)
{
	printf("edgscope-probe: a_scope's bit-field group follows an\n");
	printf("ordinary member, and its LAST member is what cpfe read\n");
	printf("as 8.  Host reference in the right-hand column.\n\n");

	printf("-- 1: EDG's real a_scope prefix ------------------------\n");
	eq("offsetof(scope_prefix, number)",
	    (long)offsetof(struct scope_prefix, number), 24);
	eq("offsetof(scope_prefix, kind)",
	    (long)offsetof(struct scope_prefix, kind), 28);
	eq("offsetof(scope_prefix, after)",
	    (long)offsetof(struct scope_prefix, after), 32);
	eq("sizeof(scope_prefix)",
	    (long)sizeof(struct scope_prefix), 40);

	printf("\n-- 2: CONTROL, bit field first in its run --------------\n");
	printf("   (edgtuoff-probe already measured this agreeing; if it\n");
	printf("    disagrees, section 1 is not about the following rule)\n");
	eq("offsetof(scope_nochar, after)",
	    (long)offsetof(struct scope_nochar, after), 32);
	eq("sizeof(scope_nochar)",
	    (long)sizeof(struct scope_nochar), 40);

	printf("\n-- 3: structalign-test's probe shapes ------------------\n");
	eq("offsetof(bf_after_member, d)",
	    (long)offsetof(struct bf_after_member, d), 2);
	eq("sizeof(bf_after_member)",
	    (long)sizeof(struct bf_after_member), 4);
	eq("offsetof(bf_alternating, d)",
	    (long)offsetof(struct bf_alternating, d), 3);
	eq("sizeof(bf_alternating)",
	    (long)sizeof(struct bf_alternating), 4);

	printf("\n%d disagreement(s) with the host\n", fails);
	if (fails == 0)
		printf("-> a_scope lays out the same here as where the corpus\n"
		       "   was generated.  That is the `follow' rule working;\n"
		       "   it does NOT say anything about the 0x10 fault, for\n"
		       "   the reason in the header (no baked constant depends\n"
		       "   on it).\n");
	else
		printf("-> every member of a_scope after the bit-field group\n"
		       "   is at a different offset from the one EDG, gcc and\n"
		       "   the generated C all assume.  Check that\n"
		       "   `cd sys/src/cmd && mk install' ran before blaming\n"
		       "   the rule: section 2 clean and section 1 dirty is\n"
		       "   what a stale compiler looks like too.\n");
	return fails;
}
