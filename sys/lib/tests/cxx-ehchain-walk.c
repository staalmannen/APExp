/*
 * cxx-ehchain-walk.c -- the EH-stack walker for cxx-ehchain-probe.
 *
 * ***THIS IS A SEPARATE C FILE FOR ONE REASON AND IT IS NOT STYLE.***
 * The walk has to name `__curr_eh_stack_entry', and a C++ translation
 * unit that uses exceptions at all ALREADY HAS a declaration of that
 * name: cpfe emits its own `struct __C8 *__curr_eh_stack_entry;' into
 * the generated C, with a per-TU generated tag.  Declaring it again
 * in the `.cpp' is therefore a redeclaration with a different type,
 * and kencc says so:
 *
 *	external redeclaration of: __curr_eh_stack_entry
 *	    EXTERN IND STRUCT __C8  ...
 *	    EXTERN IND STRUCT eh_entry  ...
 *
 * The generated tag varies per translation unit, so there is no
 * spelling of the declaration that would agree -- the name simply
 * cannot be redeclared from a C++ TU that throws.  **A plain C file
 * is never handed to cpfe**, so nothing competes with the
 * declaration here, and `eccp' already passes `*.o'/`*.[1-9kqv]'
 * straight to the linker.
 *
 *	pcc -c cxx-ehchain-walk.c
 *
 * ---- WHAT IT READS ---------------------------------------------------
 *
 * Only `next' and `kind', at offsets 0 and 8; nothing is ever
 * allocated through this declaration, so a PREFIX is enough to walk
 * a list and getting the union wrong cannot matter.  The two sides
 * agree about where `kind' is: `an_eh_stack_entry' in `throw.c' and
 * `struct __C7' in a client TU are both `{ next; kind; variant; }'.
 *
 * The kind enumeration is `src/lower_eh.c:6650'.
 */

#include <stdio.h>

#ifndef REFERENCE

/*
 * ---- THE FULL ENTRY, TRANSCRIBED FROM `lib_src/throw.c' -------------
 *
 * The first version of this file declared `{ next; kind; }' alone and
 * walked the list, which was enough to show that the chain is PERFECT
 * -- `[0] TRY_BLOCK, [1] function' -- and that is what moved the
 * question inside the entry.
 *
 * **The marker's ABSENCE is what says the walk ran.**
 * `__exception_started' pushes the kind 3 throw marker
 * (`throw.c:1038') and `__exception_caught' pops it (`:1053'), and
 * the no-handler path at `:1494' is
 * `in_handler = 1; __exception_caught(); __call_terminate();' -- it
 * pops the marker BEFORE terminating.  So a chain with no marker in
 * it is the chain after a completed, failed search, and
 * `destination_ehsep' came back 0.
 *
 * `throw.c:1322' is then the only arm that could have set it:
 *
 *	if (kind == 0 || kind == 5)
 *	  if (try_block.catch_info == 0) {
 *	    if (try_block.catch_entries != 0)
 *	      result = check_exception_type_specifications(...);
 *	    else
 *	      result = 1;
 *	    if (result != 0) destination = ehsep;
 *	  }
 *
 * -- which gives exactly three ways to fail, and the two fields
 * below separate them:
 *
 *   catch_info != 0   the arm is SKIPPED ENTIRELY, and `catch (...)'
 *	cannot save it.  The field is garbage, and since it sits
 *	immediately after an 80-byte `jmp_buf' in the same struct,
 *	whatever wrote it is the bug.
 *   catch_entries == 0 and terminate reached: impossible by the code
 *	above, so the chain at throw time was not the chain printed.
 *   both sane                the TYPE MATCH failed, and `throw.c:892' is
 *	the whole rule -- `etsp->type_info == type_info ||
 *	name(etsp->type_info) == name(type_info)', **pointer
 *	identity on the object or on the NAME STRING, never
 *	`strcmp'**.  Two copies of one type's `type_info' then fail
 *	to match, which is a COMDAT question and puts `-C' back in
 *	the frame.
 *
 * ***THE `jmp_buf' IS CLEARED AND WAS CHECKED RATHER THAN ASSUMED***:
 * the corpus bakes `typedef int jmp_buf[20]' citing
 * `ape-sys/setjmp.h', and `sys/include/ape/setjmp.h:10' is that same
 * `int[20]' -- 80 bytes both sides, against the 64 amd64 writes.  *A
 * struct whose first member is a buffer the platform fills is the
 * `alloc_fe' shape exactly*, so it had to be asked; it just answers
 * no.
 *
 * Transcribed, not guessed: `a_region_number' is `unsigned short'
 * (`throw.c:101') and `an_ETS_flag_set' is `unsigned' (`:104').  The
 * `function' arm is carried although nothing reads it, because the
 * union's SIZE AND ALIGNMENT decide where `variant' begins and
 * leaving a member out is how a reader lands on the wrong offset.
 */

/*
 * ***THE BUFFER IS `int[39]' AND NOT `int[20]', AND THE FIRST RUN OF
 * THIS FILE GOT IT WRONG AND NEARLY SHIPPED A FINDING.***
 *
 * `throw.c' spells the member `jmp_buf setjmp_buffer', and the
 * corpus's own `typedef int jmp_buf[20]' cites `ape-sys/setjmp.h' --
 * so reading the type name was enough to be confident and enough to
 * be wrong.  **cpfe does not use the platform's `jmp_buf' for this
 * member**: `lower_eh.c:12564' builds the type from
 * `targ_jmp_buf_num_elements' and `targ_jmp_buf_element_int_kind',
 * and `src/target.c:7127' sets the win64 arm -- which is the arm
 * `eccp' selects -- to **39 elements of `ik_int'**, 156 bytes.
 *
 * With `int[20]' the walker printed
 * `catch_entries 0xFEFEFEFEFEFEFEFE' and that was the MIDDLE OF THE
 * BUFFER: APE's amd64 `setjmp' writes 64 bytes of it, so everything
 * past that is untouched stack, which on this machine reads
 * `0xfefefefe' (`lib/ap/plan9/callmain.c:14').  *A field that is
 * uninitialised because nothing should have written it, read as a
 * field that should have been written and was not.*  The raw hex
 * dump is what caught it, which is why that is the primary output
 * and these named fields are secondary.
 *
 * **Oversized is the SAFE direction and was checked**: EDG reserves
 * 156 bytes where APE's `setjmp' writes 64, so nothing overruns.
 * The reverse would have been a stack smash with no diagnostic, and
 * it is the question `kencc_targ.h' asks about `long [25]' --
 * which carries no `TARG_JMP_BUF_*' entry at all, so this is one of
 * the 18 `edgtarg-sweep.py' reports as absent.
 */
#define EH_JMP_BUF_ELEMS 39	/* src/target.c:7127, the win64 arm */
typedef int eh_jmp_buf[EH_JMP_BUF_ELEMS];

struct eh_try_block {
	eh_jmp_buf setjmp_buffer;
	void *catch_entries;
	void *catch_info;
	unsigned short region_number;
	char __dummy[6];
};

struct eh_function {
	void *regions;
	void *object_address_table;
	void *array_table;
	unsigned short saved_region_number;
	char __dummy[6];
};

union eh_variant {
	struct eh_try_block try_block;
	struct eh_function function;
	void *throw_specification;
	void *array_alloc_eh_info;
};

struct eh_entry {
	struct eh_entry *next;
	unsigned char kind;
	union eh_variant variant;
};

struct eh_ets {
	void *type_info;
	unsigned flags;
	unsigned *ptr_flags;
};

extern struct eh_entry *__curr_eh_stack_entry;
extern unsigned short __eh_curr_region;

static char *
kindname(unsigned char k)
{
	switch(k){
	case 0: return "old_try_block";
	case 1: return "function";
	case 2: return "throw_spec";
	case 3: return "throw_processing_marker";
	case 4: return "vec_new_or_delete";
	case 5: return "TRY_BLOCK";
	case 6: return "NOEXCEPT";
	}
	return "???";
}

/*
 * ***PLAUSIBILITY, NOT TRUST.***  The previous version followed
 * `catch_entries' unconditionally and died on `0xFEFEFEFEFEFEFEFE'
 * with every later section unreported.  The entry now reads sane
 * (`catch_entries 0x407550', `catch_info 0'), but a probe that is
 * safe only while the thing it measures is healthy is no use for the
 * run where it is not.  Plan 9 amd64 puts TEXT at 0x200000 and the
 * data above it, so anything below that, absurdly high, or
 * misaligned is refused and SAID SO -- a silent skip and a table of
 * zeroes would read alike.
 */
static int
plausible(void *p)
{
	unsigned long long a = (unsigned long long)p;

	return a >= 0x200000ULL && a < 0x40000000ULL && (a & 7) == 0;
}

/*
 * The exception-type-specification table, which is what
 * `check_exception_type_specifications' walks (`throw.c:854').
 *
 * **The terminator is a FLAG, not a null entry**: the loop ends
 * `done = etsp->flags & 32; etsp++;' in a `do/while', so the last
 * entry is MARKED rather than followed by a sentinel.  A reader that
 * stopped on a null `type_info' would run off the end of a table it
 * does not own.
 *
 * **Bit 16 with bits 1 and 128 clear is the ELLIPSIS** (`:888'), and
 * it short-circuits the type comparison entirely -- so a
 * `catch (...)' in the source MUST appear here as such an entry, and
 * if it does the match cannot fail.  That is the most useful thing
 * in this dump: the probe's own try block is `catch (Boom &)' then
 * `catch (...)', so the table should be two entries with the second
 * flagged 16 and 32.
 */
static void
ets_dump(void *p)
{
	struct eh_ets *ets;
	int i;

	if(p == 0){
		printf("         ets: catch_entries is null -- the match is then\n");
		printf("              unconditional, so terminate is impossible\n");
		return;
	}
	if(!plausible(p)){
		printf("         ets: %p is not a plausible data address -- NOT followed\n", p);
		return;
	}
	ets = (struct eh_ets *)p;
	for(i = 0; i < 16; i++){
		printf("         ets[%d] type_info %p  flags 0x%x  ptr_flags %p%s%s\n",
			i, ets[i].type_info, ets[i].flags, (void *)ets[i].ptr_flags,
			((ets[i].flags & 16) && (ets[i].flags & 129) == 0) ? "  <= ELLIPSIS" : "",
			(ets[i].flags & 32) ? "  <= LAST" : "");
		if(ets[i].flags & 32)
			return;
	}
	printf("         ets: no entry flagged LAST in 16 -- the table is malformed\n");
}

void
eh_dump(char *when)
{
	struct eh_entry *e;
	int n, w;

	printf("  chain at %s: head = %p, __eh_curr_region = %u\n",
		when, (void *)__curr_eh_stack_entry, (unsigned)__eh_curr_region);
	n = 0;
	for(e = __curr_eh_stack_entry; e != 0 && n < 64; e = e->next, n++){
		printf("    [%2d] %p kind %u %s\n", n, (void *)e,
			(unsigned)e->kind, kindname(e->kind));
		/*
		 * ***THE RAW DUMP IS THE PRIMARY READING AND THE NAMED
		 * FIELDS ARE SECONDARY, WHICH IS THE WRONG WAY ROUND FROM
		 * HOW THIS FILE STARTED.***  The first run printed
		 * `catch_entries 0xFEFEFEFEFEFEFEFE' -- and `0xfefefefe' is
		 * *stack garbage on this machine*, named as such in
		 * `lib/ap/plan9/callmain.c:14', so those words were never
		 * written.  **But "never written" and "written somewhere
		 * I am not looking" print the same thing**, and the layout
		 * here is TRANSCRIBED from `lib_src/throw.c' while the
		 * entry is built by the CLIENT's generated C.  They are not
		 * guaranteed to agree: `eh_util.c''s own try-block push
		 * writes a member called `rtinfo' that `throw.c''s struct
		 * does not have.  A hex dump needs no transcription to be
		 * right, so it goes first and a disagreement between the
		 * two halves is the finding.
		 */
		for(w = 0; w < (int)(sizeof(struct eh_entry) / 8) + 1; w++){
			if((w % 3) == 0)
				printf("         +%-3d", w * 8);
			/*
			 * `%016llx' and NOT `%016llux': the latter is Plan 9
			 * `fmt' syntax and this is APE's C stdio, where it
			 * parses as `%llu' followed by a literal `x' -- a
			 * decimal dump that looks deliberate.
			 */
			printf(" %016llx", ((unsigned long long *)e)[w]);
			if((w % 3) == 2)
				printf("\n");
		}
		printf("\n");

		if(e->kind == 0 || e->kind == 5){
			printf("         [by throw.c's layout] catch_entries %p  catch_info %p  region %u\n",
				e->variant.try_block.catch_entries,
				e->variant.try_block.catch_info,
				(unsigned)e->variant.try_block.region_number);
			ets_dump(e->variant.try_block.catch_entries);
		}
		if(e->kind == 1)
			printf("         [by throw.c's layout] regions %p  saved_region %u\n",
				e->variant.function.regions,
				(unsigned)e->variant.function.saved_region_number);
		/*
		 * `catch_entries' is NOT dereferenced.  The first run did,
		 * and the probe died on `0xFEFEFEFEFEFEFEFE' with every
		 * later section unreported -- this tree's own rule about a
		 * case that can kill the process hiding the ones after it,
		 * arriving inside an instrument written to survive a crash.
		 */
	}
	printf("  chain at %s: %d entr%s\n", when, n, n == 1 ? "y" : "ies");
}

#else

void
eh_dump(char *when)
{
	printf("  chain at %s: not available on the reference arm\n", when);
}

#endif
