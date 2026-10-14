/*
 * Moved out of memory management:
 * table of all SUBRs
 * Bruno Haible 1990-2006
 * Sam Steingold 2002-2009
 */

#include "lispbibl.c"

#undef LISPFUN

/* table of all SUBRs */
modexp struct subr_tab_ subr_tab_data
  #if defined(HEAPCODES) && (alignment_long < varobject_alignment)
/* Force all Subrs to be allocated with a 4/8-byte alignment. GC needs this. */
    #if defined(GNU)
      __attribute__ ((aligned (varobject_alignment)))
    #endif
    #if defined(__SUNPRO_C)
      #pragma align varobject_alignment (subr_tab_data)
    #endif
  #endif
  #if defined(INIT_SUBR_TAB)
    = {
        #if varobjects_misaligned
        { 0 },
        #endif
        #if NIL_IS_CONSTANT
          #define LISPFUN  LISPFUN_G
        #else
          #define LISPFUN  LISPFUN_F
        #endif
        #include "subr.c"
        #undef LISPFUN
      }
  #endif
  ;
global uintC subr_tab_data_size = (sizeof(subr_tab_data)-varobjects_misaligned)/sizeof(subr_t);

