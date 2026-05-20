/*
 * dwarftype.h — DWARF type-info emission hook for the Plan9 C compilers.
 *
 * Declared here; included via -I.. from pgen.c when -DWITH_DWARFP is set.
 * gc.h (and thus Sym, Prog) must be included before this header.
 */
#ifdef WITH_DWARFP
void dwarf_emit_func(Sym *func, Prog *textp);
#endif
