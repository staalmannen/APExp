/*
 * dwarftype.c — DWARF type-information emitter for the Plan9 C compilers.
 *
 * Called from pgen.c (compiled with -DWITH_DWARFP) after each function's
 * code and register-optimization pass are complete.  Intended to use
 * libdwarfp to produce DW_TAG_subprogram DIEs with parameter and local
 * variable children carrying full type information.
 *
 * This file is compiled with Plan9 native headers (-I$ARCSRC for gc.h)
 * AND the libdwarfp headers (-I$DWSRC/src/lib/libdwarfp).
 *
 * Status: stub — dwarf_emit_func does nothing yet.
 * TODO: initialise a per-translation-unit Dwarf_P_Debug handle, walk
 *       the Auto chain of textp, emit DW_TAG_formal_parameter and
 *       DW_TAG_variable DIEs with DW_AT_type cross-references built
 *       from the compiler's Type* tree.
 */
#include "gc.h"

void
dwarf_emit_func(Sym *func, Prog *textp)
{
	USED(func);
	USED(textp);
}
