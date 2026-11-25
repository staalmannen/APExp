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

typedef int eh_jmp_buf[20];

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

void
eh_dump(char *when)
{
	struct eh_entry *e;
	int n;

	printf("  chain at %s: head = %p, __eh_curr_region = %u\n",
		when, (void *)__curr_eh_stack_entry, (unsigned)__eh_curr_region);
	n = 0;
	for(e = __curr_eh_stack_entry; e != 0 && n < 64; e = e->next, n++){
		printf("    [%2d] %p kind %u %s\n", n, (void *)e,
			(unsigned)e->kind, kindname(e->kind));
		if(e->kind == 0 || e->kind == 5){
			struct eh_ets *ets;

			printf("         catch_entries %p  catch_info %p  region %u\n",
				e->variant.try_block.catch_entries,
				e->variant.try_block.catch_info,
				(unsigned)e->variant.try_block.region_number);
			/*
			 * One entry only.  The list's terminator is the
			 * matcher's business and transcribing a loop
			 * condition is how a reader walks off the end of a
			 * table it does not own; the FIRST entry is enough
			 * to say whether the pointer leads anywhere real.
			 */
			ets = (struct eh_ets *)e->variant.try_block.catch_entries;
			if(ets != 0)
				printf("         ets[0] type_info %p  flags 0x%x\n",
					ets->type_info, ets->flags);
		}
		if(e->kind == 1)
			printf("         regions %p  saved_region %u\n",
				e->variant.function.regions,
				(unsigned)e->variant.function.saved_region_number);
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
