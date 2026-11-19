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

struct eh_entry {
	struct eh_entry *next;
	unsigned char kind;
};

extern struct eh_entry *__curr_eh_stack_entry;

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

	printf("  chain at %s: head = %p\n", when, (void *)__curr_eh_stack_entry);
	n = 0;
	for(e = __curr_eh_stack_entry; e != 0 && n < 64; e = e->next, n++)
		printf("    [%2d] %p kind %u %s\n", n, (void *)e,
			(unsigned)e->kind, kindname(e->kind));
	printf("  chain at %s: %d entr%s\n", when, n, n == 1 ? "y" : "ies");
}

#else

void
eh_dump(char *when)
{
	printf("  chain at %s: not available on the reference arm\n", when);
}

#endif
