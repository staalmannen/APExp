/*
 * kencc_targ.h -- APExp target configuration for EDG's cpfe.
 *
 * NOT part of EDG.  Supplied with -include so that it is seen before
 * src/defines.h pulls in the generated cmake_defines.h, every entry of
 * which is #ifndef-guarded.  Nothing in the EDG tree is modified.
 *
 * Target: APExp/kencc on amd64 (6c/pcc).  This is LLP64 -- the same
 * integer model EDG already ships as its "win64" configuration, whose
 * values in cmake_defines.h are quoted beside each line below.
 */

#ifndef APEXP_KENCC_TARG_H
#define APEXP_KENCC_TARG_H

/*
 * Only for translation units that take defines.h's USE_CMAKE_DEFINES
 * branch -- that is cpfe, and cpfe is the only thing whose target
 * matters.  The helper programs in util/ are compiled WITHOUT that
 * define, so they take the legacy "#include defines_linux.h" path at
 * defines.h:518, where the TARG_* macros are UNCONDITIONAL and a
 * command-line definition only produces a redefinition warning that
 * the header then wins.  They are host programs here; leave them on
 * the host's own configuration.
 */
#if defined(USE_CMAKE_DEFINES)

/* ---- generated-code target -------------------------------------- *
 * The round-1 build inferred GCC_IS_GENERATED_CODE_TARGET from
 * __GNUC__ (targ_def.h:3505), i.e. from the compiler that built cpfe,
 * and that is the sole gate on both __attribute__((__weak__)) sites in
 * c_gen_be.c (8806, 11103).  kencc is "a compiler for which we have no
 * special handling", which is targ_def.h's own EDG_WIN32 #else arm.
 */
#define GCC_IS_GENERATED_CODE_TARGET   0
#define CLANG_IS_GENERATED_CODE_TARGET 0
#define SUN_IS_GENERATED_CODE_TARGET   0
#define MSVC_IS_GENERATED_CODE_TARGET  0
#define MICROSOFT_DIALECT_IS_GENERATED_CODE_TARGET 0
#define C_GEN_BE_GENERATES_ANSI_C      1

/* ---- no COMDAT ---------------------------------------------------- *
 * Clearing GCC_IS_GENERATED_CODE_TARGET above stops __weak__ being
 * EMITTED, but by itself that only turns a kencc-unsupported attribute
 * into a duplicate-definition link error: measured, two trivial TUs
 * sharing one header collide on 10 symbols.
 *
 * host_envir.h:862 names the real axis --
 * LINKER_CAN_DISCARD_DUPLICATE_DEFINITIONS, whose own comment is
 * "a simplified interpretation of this flag is: do we have COMDAT
 * sections?".  Plan 9's loaders do not.  It is forced TRUE by
 * IA64_ABI (host_envir.h:868), which the Linux configuration sets, so
 * IA64_ABI is what has to go: that selects EDG's Cfront-like ABI,
 * which is the no-COMDAT world this whole mechanism was built for.
 * With IA64_ABI off, extern inline entities are routed through the
 * template instantiation machinery instead of a COMDAT section
 * (targ_def.h:4641-4686) and vtables/typeinfo follow the same path.
 *
 * ATTEMPTED AND BACKED OUT -- see the note at the end of this block.
 * It is left here, disabled, because the wall it hits is the finding
 * and re-deriving it would cost another round.
 */
#if defined(APEXP_TRY_CFRONT_ABI)
#define IA64_ABI                                 0
#define LINKER_CAN_DISCARD_DUPLICATE_DEFINITIONS 0
#define INSTANTIATE_EXTERN_INLINE                1
#define INSTANTIATE_INLINE_VARIABLES             1

/*
 * targ_def.h:648 defaults this to GNU_EXTENSIONS_ALLOWED, and
 * targ_def.h:657 only permitted it to be off when IA64_ABI was off --
 * which it now is.  kencc has no weak references, so lazy
 * initialization must not be built on them.
 */
#define LAZY_INITIALIZATION_USES_WEAK_REFERENCES 0

/*
 * Two consistency checks fire on IA64_ABI going off, and each names
 * its own remedy; both are Cfront-ABI settings rather than choices:
 *   targ_def.h:357   TIE_DEFAULT_GNU_ABI_VERSION_TO_GNU_VERSION
 *                    requires that IA64_ABI be TRUE
 *   targ_def.h:4603  HANDLE_VIRTUAL_BASES_IN_COMPLETE_CTOR_DTORS must
 *                    be FALSE when IA64_ABI is FALSE
 */
#define TIE_DEFAULT_GNU_ABI_VERSION_TO_GNU_VERSION  0
#define HANDLE_VIRTUAL_BASES_IN_COMPLETE_CTOR_DTORS 0

/*
 * ...and then it stops, which is the thing to record.  With the two
 * above supplied, cpfe fails to COMPILE in src/target_map.h:
 *
 *   target_map.h:106 error: 'TARG_ALIGNOF_PTR_TO_VIRTUAL_BASE_CLASS_linux_i686'
 *                           was not declared in this scope
 *   target_map.h:302 error: 'TARG_RUNTIME_ELEM_COUNT_INT_KIND_linux_i686'
 *   target_map.h:338 error: 'TARG_SIZEOF_PTR_TO_VIRTUAL_BASE_CLASS_linux_i686'
 *
 * The Cfront ABI needs three target quantities the IA-64 ABI does not,
 * and this build is MULTI-TARGET: the platform cmakedef
 * (cmake/macro-conf/support/platform/linux-x86_64/base.cmakedef:14-38)
 * declares TARGET_CONFIGURATION_1..7, and target.c instantiates the
 * whole target map once per configuration, each needing a
 * <MACRO>_<config> spelling.  The generated cmake_defines.h carries
 * those suffixed variants only for the macros reachable under
 * IA64_ABI=1, which is what it was generated for.  Setting
 * EDG_CPP_RT_LIBS="" does NOT help: that list is separate from
 * TARGET_CONFIGURATION_n.
 *
 * Two of the three are mechanical (targ_def.h:2837,2842 derive them
 * from TARG_SIZEOF_POINTER / TARG_ALIGNOF_POINTER) but the suffixed
 * spellings still have to be written out by hand for all seven
 * secondary targets, and TARG_RUNTIME_ELEM_COUNT_INT_KIND has no
 * derived default at all -- that one would be invented.
 *
 * So the Cfront ABI is reachable by REGENERATING the macro
 * configuration for it, not by setting switches, and it is a large
 * semantic change (mangling, ctor/dtor model, vtable layout) that
 * wants its own round and its own validation.  Not done here.
 */
#endif /* defined(APEXP_TRY_CFRONT_ABI) */

/* ---- integer model: LLP64 (= EDG's win64) ----------------------- */
#define TARG_LITTLE_ENDIAN    1        /* amd64                       */
#define TARG_CHAR_BIT         8
#define TARG_HAS_SIGNED_CHARS 1        /* win64 1; APE's own
                                          limits_generic.h:44,52 make
                                          CHAR_MAX==SCHAR_MAX and
                                          CHAR_MIN==SCHAR_MIN         */
#define TARG_SIZEOF_SHORT     2
#define TARG_ALIGNOF_SHORT    2
#define TARG_SIZEOF_INT       4        /* win64 4 */
#define TARG_ALIGNOF_INT      4
#define TARG_SIZEOF_LONG      4        /* win64 4 -- NOT 8; kencc long
                                          is 32-bit on every target   */
#define TARG_ALIGNOF_LONG     4        /* win64 4 */
#define TARG_SIZEOF_LONG_LONG 8        /* win64 8 */
#define TARG_ALIGNOF_LONG_LONG 8       /* win64 8 */
#define TARG_SIZEOF_POINTER   8        /* win64 8 */
#define TARG_ALIGNOF_POINTER  8        /* win64 8 */

/* ---- floating point --------------------------------------------- *
 * kencc has no extended precision: cc/sub.c's simplet() maps
 * BDOUBLE|BLONG to types[TDOUBLE], so long double IS double.
 * EDG's win64 says 8 for the same reason (MSVC does the same).
 * targ_def.h:3954 requires DOUBLE == LONG_DOUBLE in that case.
 */
#define TARG_SIZEOF_FLOAT        4
#define TARG_ALIGNOF_FLOAT       4
#define TARG_SIZEOF_DOUBLE       8     /* win64 8 */
#define TARG_ALIGNOF_DOUBLE      8     /* win64 8 */
#define TARG_SIZEOF_LONG_DOUBLE  8     /* win64 8 */
#define TARG_ALIGNOF_LONG_DOUBLE 8     /* win64 8 */

/*
 * The SIZE alone is not enough: floating.h:216 cross-checks it against
 * the long double FORMAT, and cmake_defines.h:166 asserts the host's
 * 80-bit extended.  Saying 8 bytes while the format says 80 bits is
 * "long double type is mis-configured", which is the check doing its
 * job.  binary64 is the format that matches kencc's long-double-is-
 * double, and it is one of the three floating.h already names.
 */
#define FP_LONG_DOUBLE_IS_BINARY64       1
#define FP_LONG_DOUBLE_IS_80BIT_EXTENDED 0
#define FP_LONG_DOUBLE_IS_BINARY128      0

/* ---- derived library types -------------------------------------- *
 * Read from APE's own headers rather than inferred:
 *   amd64/include/ape/stddef_arch.h:4,10,14
 *     _ptrdiff_t = long long, size_t = unsigned long long,
 *     ssize_t = long long
 *   sys/include/ape/stddef.h:50   wchar_t = unsigned int
 * The first three are exactly win64's kinds; wchar_t is not
 * (win64 uses unsigned short), which is the one place APExp and
 * EDG's LLP64 configuration differ.
 */
#define TARG_SIZE_T_INT_KIND    ((an_integer_kind)ik_unsigned_long_long)
#define TARG_SSIZE_T_INT_KIND   ((an_integer_kind)ik_long_long)
#define TARG_PTRDIFF_T_INT_KIND ((an_integer_kind)ik_long_long)
#define TARG_WCHAR_T_INT_KIND   ((an_integer_kind)ik_unsigned_int)

#endif /* defined(USE_CMAKE_DEFINES) */
#endif /* APEXP_KENCC_TARG_H */
