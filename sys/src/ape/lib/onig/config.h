/*
 * config.h for oniguruma under APExp -- HAND-ANSWERED.
 *
 * oniguruma is autoconf'd and this tree does not run configure, so this
 * is the fourth hand-answered capability file here after perl's, bash's
 * and clisp's-to-be.  **It is deliberately the SMALLEST one**: the
 * whole set oniguruma's sources actually read is ten names, found by
 * sweeping `src/*.c src/*.h' for `HAVE_*' and `SIZEOF_*' rather than
 * by copying a generated config.h from some other platform.  Anything
 * not listed here is not consulted; adding more would be inventing
 * answers to questions nobody asks.
 *
 * THE SEVEN HEADERS ARE ALL PRESENT and were checked one at a time
 * against `sys/include/ape', not assumed: alloca.h, inttypes.h,
 * stdint.h, sys/times.h, sys/time.h, sys/types.h, unistd.h.
 *
 * ***THE WORD SIZES ARE THE DANGEROUS PART AND SIZEOF_VOIDP IS NOT
 * HERE.***  This tree has six hand-maintained config.h files that say
 * amd64 on every target -- perl's `PTRSIZE 8', bash's `SIZEOF_CHAR_P
 * 8', gawk's `SIZEOF_VOID_P 8', xz's, curl's and libzip's
 * `SIZEOF_SIZE_T 8' -- and the 386 cross build is how that was found,
 * one package at a time.  *So this file does not get to answer it.*
 *
 * `SIZEOF_LONG' and `SIZEOF_LONG_LONG' ARE constant under kencc and
 * are answered here: `long' is 32 bits on every target including
 * amd64 (see the invariant in CLAUDE.md) and `long long' is 64.
 * `SIZEOF_VOIDP' is 8 on amd64, arm64 and power64 and 4 on the other
 * eight, so **../onig/mkfile computes it from `$objtype'** the way
 * `lib/chicken/mkfile' computes `$WORD64', from the same measured set
 * (`SZ_IND' is 8 in exactly `6c/gc.h', `7c/gc.h' and `9c/gc.h').
 *
 * And if that ever stops arriving, this file FAILS THE COMPILE rather
 * than guessing.  *A missing answer that is loud is worth more than a
 * present answer that is wrong*, which is the whole lesson of the six
 * files above.
 */
#ifndef APEXP_ONIG_CONFIG_H
#define APEXP_ONIG_CONFIG_H

#define HAVE_ALLOCA_H		1
#define HAVE_INTTYPES_H		1
#define HAVE_STDINT_H		1
#define HAVE_SYS_TIMES_H	1
#define HAVE_SYS_TIME_H		1
#define HAVE_SYS_TYPES_H	1
#define HAVE_UNISTD_H		1

/* kencc: 32-bit long on every target, 64-bit long long on every target. */
#define SIZEOF_LONG		4
#define SIZEOF_LONG_LONG	8

#ifndef SIZEOF_VOIDP
#error "SIZEOF_VOIDP must come from the mkfile (-DSIZEOF_VOIDP=4 or 8); see the comment above"
#endif

#endif /* APEXP_ONIG_CONFIG_H */
