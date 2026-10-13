/*
 * List of all packages available in C
 * Bruno Haible 1990-2004
 * Sam Steingold 1999-2003

 Macro LISPPACK declares a LISP package.
 LISPPACK(abbrev,packname)
 > abbrev: C package identified, used in constsym.d
 > packname: full Lisp name */

/* Expander for enumerating: */
#define LISPPACK_A(abbrev,packname)             \
    enum_##abbrev##_index,

/* Expander for constructing of the list O(all_packages): */
#define LISPPACK_B(abbrev,packname)                             \
    make_package(ascii_to_string(packname),NIL,false,false);

/* The including file should select which expander is actually used. */

LISPPACK(clos,"CLOS")
LISPPACK(ext,"EXT")
LISPPACK(custom,"CUSTOM")
#ifdef MULTITHREAD
LISPPACK(mt,"THREADS")
#endif
#ifdef SCREEN
LISPPACK(screen,"SCREEN")
#endif
#ifdef DYNAMIC_FFI
LISPPACK(ffi,"FFI")
#endif
#ifdef SOCKET_STREAMS
LISPPACK(socket,"SOCKET")
#endif
LISPPACK(i18n,"I18N")
LISPPACK(gray,"GRAY")
#ifdef GENERIC_STREAMS
LISPPACK(gstream,"GSTREAM")
#endif
