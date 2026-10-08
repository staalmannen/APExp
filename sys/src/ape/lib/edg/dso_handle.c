/*
 * dso_handle.c -- `__dso_handle', for programs cpfe translates.
 *
 * APExp's, not EDG's; see the header of `cxa_atexit.c' beside it for
 * why this directory has two hand-written files among 50 generated
 * ones, and for the ABI the pair implements.
 *
 * **cpfe DOES NOT REFERENCE THIS**, which is worth stating because
 * the name appears in `src/lower_init.c' and looks like a use.  It is
 * a STRING LITERAL there -- cpfe EMITS references to `__dso_handle'
 * in the C it generates, as every C++ front end does for a static
 * object with a destructor.  So this symbol is for the programs cpfe
 * translates, and it reaches no link until one of them asks.
 *
 * IT IS ITS OWN FILE BECAUSE THE HOST ALREADY HAS ONE.  glibc's
 * `crtbeginS.o' defines `__dso_handle', so linking it from the same
 * object as `__cxa_atexit' makes the host cross-check fail to link
 * at all:
 *
 *	multiple definition of `__dso_handle';
 *	crtbeginS.o: first defined here
 *
 * *That is the measurement rather than an inconvenience*: the symbol
 * belongs to the C runtime startup and the finalization functions
 * belong to the C++ runtime, and the host says so by already owning
 * exactly one of the two.  Split, `cxaatexit-test.c' links the other
 * file on either machine and uses whichever handle is present.
 *
 * Plan 9 has no dlopen, so there is one DSO and this is its handle.
 * Self-referential because that is what a crt does on a static
 * target: the ADDRESS is the whole content, and taking its own
 * guarantees it is unique and non-null without pretending the value
 * means anything.
 */

void *__dso_handle = &__dso_handle;
