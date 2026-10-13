/*
 * Moved out of memory management:
 * table of all fixed symbols
 * Bruno Haible 1990-2006
 * Sam Steingold 2002-2009
 */

#include "lispbibl.c"

#undef LISPSYM

/* Yet another macro-problem. Grr... */
#undef inline
/* WIN32.D does "#define read" and "#define write" */
#undef read
#undef write
/* LISPBIBL.D does "#define export" */
#undef export
/* Large File Support on some versions of Solaris does "#define open open64",
   "#define truncate truncate64", "#define ftruncate ftruncate64" */
#undef open
#undef truncate
#undef ftruncate

/* Table of all fixed symbols: */
modexp struct symbol_tab_ symbol_tab_data
  #if defined(HEAPCODES) && (alignment_long < varobject_alignment)
/* Force all symbols to be allocated with a 4/8-byte alignment. GC needs this. */
    #if defined(GNU)
      __attribute__ ((aligned (varobject_alignment)))
    #endif
    #if defined(__SUNPRO_C)
      #pragma align varobject_alignment (symbol_tab_data)
    #endif
  #endif
  #if defined(INIT_SYMBOL_TAB) && NIL_IS_CONSTANT
    = {
        #if varobjects_misaligned
        { 0 },
        #endif
        #define LISPSYM  LISPSYM_B
        #include "constsym.c"
        #undef LISPSYM
      }
  #endif
  ;

