/*
 * edgtuoff-probe.c -- does the offset EDG FOLDED INTO the generated C
 * match the offset the compiler that BUILDS that C computes?
 *
 * Where this came from.  cpfe, built under pcc from the committed
 * corpus, linked and then faulted on every run that got past the
 * target flags:
 *
 *	cpfe 82846: suicide: sys: trap: fault read addr=0x68 pc=0x7e2d88
 *
 * `acid' + `lstk()' on the Broken process named the line:
 *
 *	f_add_orphaned_file_scope_il_entry(...)+0x11a   src/il.c:4936
 *	edg::void_type()+0x4c
 *	edg::make_global_operator_new_or_delete_symbol(...)+0x351
 *	predeclare_entities()+0x1ff
 *	edg::fe_translation_unit_init()+0x189
 *	edg::process_translation_unit(...)+0x1b8
 *	cfe_main(argc=..d, argv=..)+0x77
 *
 * and `il.c:26113' is
 *
 *	orphan_array = tup->orphaned_file_scope_il_entries;
 *	last_entry_ptr = &orphan_array[entry_kind].last_entry;
 *
 * with `entry_kind' 6 from the frame.  `an_orphaned_il_entry_list' is
 * 16 bytes (1616/101 from the registration below), so 6*16 + 8 is
 * **104 = 0x68 exactly** -- the faulting address is that subscript of
 * a NULL array.  *An address that the arithmetic reproduces to the
 * digit is a measurement, not a resemblance.*
 *
 * WHY THAT MEMBER IS NULL, AND WHY IT IS A LAYOUT QUESTION.
 * `src/trans_unit.h' is upstream's own:
 *
 *	#define register_trans_unit_variable_with_field(var, field) \
 *	  (f_register_trans_unit_variable((a_void_ptr)&var, sizeof(var), \
 *	     offsetof(a_translation_unit, field)))
 *
 * -- and cpfe FOLDS that `offsetof' to an integer literal when it
 * translates.  The whole 133-file corpus holds exactly TWO non-zero
 * ones (359 registrations pass 0):
 *
 *	il.c:51481         orphaned_file_scope_il_entries   400
 *	host_envir.c:...   module_id_ptr                    416
 *
 * So the C carries a BAKED-IN STRUCT OFFSET.  If the compiler building
 * it lays `a_translation_unit' out differently, the registration files
 * the pointer under the wrong member, the real member stays null, and
 * the first read of it faults at a small address -- which is the stack
 * above.  Nothing diagnoses it: every type is right, every symbol
 * resolves, and the only evidence is a fault a long way downstream.
 *
 * *The NOTE for this port says "EDG bakes in NO struct sizes", measured
 * by grepping for cfront's `sizeof X == N' markers and finding zero.
 * That was true and it was the wrong question: a folded `offsetof' has
 * no marker, is indistinguishable from any other integer literal, and
 * is exactly the same hazard.*
 *
 * WHAT THIS PROBE IS.  A REDUCTION, not an extraction: every pointer
 * member becomes `void *' and every scalar keeps its written type, so
 * the file is twenty lines instead of 5798 and needs no part of EDG.
 * **The gcc control is what licenses the reduction** -- the host must
 * print 424 and 440, which are the numbers `gdb' reads out of the DWARF
 * of a real `gcc -g -c mem_manage.c'.  A reduction that reproduces the
 * known answer is layout-faithful; one that does not is measuring a
 * different struct, which is how a probe passes its control and still
 * answers the wrong question.
 *
 *	gcc -w -o edgtuoff-probe edgtuoff-probe.c && ./edgtuoff-probe
 *	  -> 424 / 440, "host layout reproduced", 2 mismatches, exit 2
 *
 *	pcc -o edgtuoff-probe edgtuoff-probe.c && ./edgtuoff-probe
 *	  -> whatever kencc says.  THIS is the measurement.
 *
 * It is built with PLAIN pcc on purpose.  `pcc' passes `-J' itself on
 * every compile now, which is the rule the whole APE world is built
 * under, so a probe that asked for anything else would measure a
 * compiler nothing else uses.  `pcc -9' is available if the old rule
 * ever needs asking about.
 *
 * THE PREDICTION, written down before the run.  Two members differ
 * between the two targets:
 *
 *   - `unsigned long' is 8 on the host and **4 under kencc**, and
 *     `an_il_header' holds FIVE of them, so it is 208 there and 184
 *     here -- 24 less, which is exactly 424-400.  *So the fold already
 *     used kencc's `long', and the corpus is right about that half.*
 *
 *   - `a_scope_pointers_block' ends `unsigned int x : 1; char
 *     __dummy[7];' -- EDG's own explicit tail padding, sized so the
 *     bit field's unit and the array together make 160.  **kencc
 *     allocates a bit field in a whole `tfield' unit** and does not
 *     pack a following `char' into it (recorded, and `-J' does not
 *     change it), so the array starts at 156, the struct is 168, and
 *     every member after it moves up 8.
 *
 * So the prediction is **408 and 424 under pcc, against the baked 400
 * and 416**, a uniform 8-byte shift, and the probe reports MISMATCH.
 * *That would mean the registration writes the orphan array over
 * `exported_template_file' and the member it was meant for stays null*
 * -- the fault, exactly.
 *
 * REFUTATION, and it is the useful outcome either way.  If pcc prints
 * 400 and 416 the layouts AGREE, the folded constants are right, this
 * whole reading is wrong, and the null member has another cause --
 * which sends the next round to `trans_unit.c' and the registration
 * machinery rather than to the compiler.  A probe whose two outcomes
 * point at two different files is worth more than one that can only
 * confirm.
 *
 * And if it does print 408: *the fix is a re-translation, not a patch
 * here.* Nothing in this tree should edit a folded constant by hand --
 * the next regeneration would silently put it back.
 */

typedef _Bool a_byte_boolean;		/* il.c:8030, literally _Bool */
typedef unsigned short a_targ_alignment;	/* il.c:8210 */
typedef unsigned int u32;		/* uint32_t */
typedef int s32;			/* int32_t  */

/* src/il.c:14788 -- 19 pointers, then EDG's own explicit tail padding */
struct a_scope_pointers_block {
	void *symbols, *synth_namespace_projection_symbols, *last_symbol;
	void *last_constant, *last_type, *last_variable, *last_routine;
	void *last_asm_entry, *last_dynamic_init, *last_namespace;
	void *last_using_declaration, *last_using_directive, *last_pragma;
	void *last_template, *last_ms_attribute, *unnamed_namespace_sym;
	void *inline_namespaces, *lookup_table, *module_lookup_table_map;
	unsigned int add_symbols_to_inactive_list: 1;
	char __dummy[7];
};

/* src/il.c:13958 -- the five `unsigned long' are the long-width half */
struct an_il_header {
	void *primary_source_file;
	void *primary_scope;
	void *file_scope_statements;
	void *main_routine;
	void *compiler_version;
	void *time_of_compilation;
	a_byte_boolean plain_chars_are_signed;
	void *region_scope_entry;
	void *function_def_table;
	void *scope_orphaned_list_headers;
	enum a_source_language { __sl_dummy } source_language;
	u32 std_version;
	void *cli_metadata_files;
	a_byte_boolean pcc_compatibility_mode;
	a_byte_boolean enum_type_is_integral;
	a_targ_alignment default_max_member_alignment;
	a_byte_boolean microsoft_mode;
	a_byte_boolean cppcli_enabled;
	a_byte_boolean cppcx_enabled;
	unsigned long microsoft_version;
	a_byte_boolean default_upc_strict_access;
	a_byte_boolean gcc_mode;
	a_byte_boolean gpp_mode;
	a_byte_boolean clang_mode;
	unsigned long gnu_version;
	unsigned long clang_version;
	a_byte_boolean short_enums;
	a_byte_boolean default_nocommon;
	a_byte_boolean gnu_c89_inlining;
	a_byte_boolean near_and_far_are_enabled;
	a_byte_boolean far_data_pointers;
	a_byte_boolean far_code_pointers;
	a_byte_boolean UCN_identifiers_used;
	a_byte_boolean vla_used;
	a_byte_boolean any_templates_seen;
	a_byte_boolean prototype_instantiations_in_il;
	a_byte_boolean il_has_all_prototype_instantiations;
	a_byte_boolean il_has_C_semantics;
	void *instantiation_dir_name;
	unsigned long number_of_external_nonclass_template_entities;
	void *nontag_types_used_in_exception_or_rtti;
	void *seq_number_lookup_entries;
	unsigned long num_seq_number_lookup_entries;
	s32 target_configuration_index;
	void *imported_modules;
};

/* src/il.c:17732 -- only as far as the two registered members */
struct a_translation_unit {
	void *next;
	void *primary_scope;
	void *variables_block;
	struct a_scope_pointers_block file_scope_pointers_block;
	void *source_file;
	struct an_il_header il_header;
	void *last_scope_orphaned_list_header;
	void *based_type_fixup_list;
	void *exported_template_file;
	void *orphaned_file_scope_il_entries;		/* baked 400 */
	a_byte_boolean specified_on_command_line;
	a_byte_boolean additional_instantiation_wrapup_required;
	char **module_id_ptr;				/* baked 416 */
};

/*
 * SECTION 2 -- WHICH published bit-field rule is kencc's?
 *
 * Section 1 says only THAT the two disagree.  This asks the question
 * that decides what to do about it, and it is answerable by pcc alone.
 *
 * `a_scope_pointers_block' ends `unsigned x:1; char __dummy[7];' --
 * EDG's own explicit tail padding, and EDG emits one after EVERY
 * bit-field group in the corpus (33 of 33 in `src/il.c', no
 * exceptions), so whatever rule governs this governs all of them.
 * EDG lets the `char' share the unused tail of the bit field's
 * container, which is what gcc does; kencc closes the container
 * first.  **That second behaviour is MSVC's**, and EDG has a target
 * variable for it -- `TARG_MICROSOFT_BIT_FIELD_ALLOCATION', which
 * `kencc_targ.h' sets nowhere and which one of the eight shipped
 * configurations already uses.  *It is a `TARG_' macro rather than a
 * command-line flag*, so a pre-include can set it and a regeneration
 * would then emit padding kencc agrees with.
 *
 * So the whole plan turns on one identification, and it is recalled
 * rather than measured -- which is why it is asked here instead of
 * assumed. **Do not write the expected emission into this probe**: a
 * section that assumes what cpfe WOULD emit measures nothing, since
 * only a rebuilt cpfe can say. Ask kencc what it does, and compare
 * with the two published rules:
 *
 *   gcc / EDG today : c at 1, sizeof 4   (the container is shared)
 *   MSVC            : c at 4, sizeof 8   (the container is closed)
 *
 * If pcc answers 4 and 8, kencc's rule IS the MSVC one, the knob is
 * the right knob, and a one-line `kencc_targ.h' plus a regeneration
 * fixes the class rather than the two constants.  **If it answers
 * anything else the knob is NOT the fix** -- it would trade one
 * mismatch for a different one -- and the remaining option is to
 * change kencc's own allocation under `-J', which is the
 * non-conformance this tree already records and deliberately left.
 *
 * The gcc control is the first column: the host must print 1 and 4,
 * or this section is measuring something other than the rule.
 */
struct bf1 { unsigned x: 1; char c; };
struct bf2 { unsigned a: 3; unsigned b: 5; char c; };

extern int printf(const char *, ...);

#define OFF(f) ((unsigned long)(unsigned long long) \
	&((struct a_translation_unit *)0)->f)
#define BOFF(t, f) ((unsigned long)(unsigned long long) &((struct t *)0)->f)

int
main(void)
{
	unsigned long a, b, sp, ih;
	int bad = 0;

	sp = (unsigned long)sizeof(struct a_scope_pointers_block);
	ih = (unsigned long)sizeof(struct an_il_header);
	a = OFF(orphaned_file_scope_il_entries);
	b = OFF(module_id_ptr);

	printf("sizeof(long)                   = %lu\n",
	    (unsigned long)sizeof(long));
	printf("sizeof(a_scope_pointers_block) = %lu   (host 160)\n", sp);
	printf("sizeof(an_il_header)           = %lu   (host 208)\n", ih);

	/* the control: on the host these two must be the DWARF numbers,
	   or the reduction is not of this struct and nothing below it
	   means anything */
	if (sizeof(long) == 8)
		printf("CONTROL: host layout %s\n",
		    (a == 424 && b == 440) ? "reproduced (424/440) -- "
		    "reduction is faithful"
		    : "*** NOT reproduced -- THIS PROBE IS VOID ***");

	printf("orphaned_file_scope_il_entries: compiler %lu  baked 400  %s\n",
	    a, a == 400 ? "AGREE" : "*** MISMATCH ***");
	printf("module_id_ptr:                  compiler %lu  baked 416  %s\n",
	    b, b == 416 ? "AGREE" : "*** MISMATCH ***");

	if (a != 400)
		bad++;
	if (b != 416)
		bad++;
	printf("%d mismatch(es)\n", bad);

	printf("\n-- section 2: which published bit-field rule is this? --\n");
	printf("struct{unsigned x:1; char c;}        c at %lu, sizeof %lu\n",
	    BOFF(bf1, c), (unsigned long)sizeof(struct bf1));
	printf("struct{unsigned a:3,b:5; char c;}    c at %lu, sizeof %lu\n",
	    BOFF(bf2, c), (unsigned long)sizeof(struct bf2));
	printf("   gcc/EDG-today says 1,4 and 1,4    (container shared)\n");
	printf("   MSVC says           4,8 and 4,8   (container closed)\n");
	printf("   -> this compiler follows: %s\n",
	    (BOFF(bf1, c) == 4 && BOFF(bf2, c) == 4) ? "MSVC -- "
	    "TARG_MICROSOFT_BIT_FIELD_ALLOCATION is the knob"
	    : (BOFF(bf1, c) == 1 && BOFF(bf2, c) == 1) ? "gcc/EDG -- "
	    "then section 1 cannot have mismatched; re-read it"
	    : "NEITHER -- the knob is not the fix, see the header");

	return bad;
}
