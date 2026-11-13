// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="compiler_builtins.h"
// *
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// *
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_COMPILER_BUILTINS_H
#define PSTL_COMPILER_BUILTINS_H

/*
 * WHICH COMPILER EXTENSIONS ARE AVAILABLE -- an APExp addition, and
 * the reason it exists is that this library had no way to say "neither
 * of the above".
 *
 * Four headers chose an implementation with `#if defined(_MSC_VER)'
 * ... `#else /` *` clang and gcc *` /', a two-way split that answers
 * CLANG-AND-GCC for every compiler that is not Microsoft's.  EDG's
 * `cpfe', which is what `rc/bin/ape/eccp' runs, is a third thing: it
 * defines neither `_MSC_VER' nor `__GNUC__', so it took the gcc arm
 * and reached `__integer_pack', `__builtin_is_constant_evaluated' and
 * `__LONG_LONG_MAX__', none of which it has outside g++ emulation
 * mode.  Eleven of the fifty public headers failed on that one shape.
 *
 * **The split was by COMPILER IDENTITY where the question is
 * CAPABILITY**, which is the whole of the bug: a library called
 * Portable STL cannot enumerate the compilers it will meet, and it
 * does not have to -- `__has_builtin' and a version test answer the
 * question directly, and a compiler that answers neither gets the
 * portable path rather than a guess.
 *
 * `PSTL_NO_COMPILER_BUILTINS' forces every answer to NO.  It is what
 * `sys/lib/tests/hostkencc/cxxlib-host.sh --portable' defines, and it
 * is the only way to compile the arms cpfe takes with a compiler that
 * has the builtins -- *a host run that takes the gcc arm has not
 * tested the code the VM runs.*
 */

#if defined(PSTL_NO_COMPILER_BUILTINS)
#  define PSTL_HAS_BUILTIN(x)              0
#  define PSTL_HAS_INTEGER_PACK             0
#  define PSTL_HAS_MAKE_INTEGER_SEQ         0
#  define PSTL_HAS_GNU_LIMIT_MACROS         0
#else

#  if defined(__has_builtin)
#    define PSTL_HAS_BUILTIN(x) __has_builtin(x)
#  else
#    define PSTL_HAS_BUILTIN(x) 0
#  endif

/* clang's and MSVC's pack builtin.  Not a function, so `__has_builtin'
   is the only way to ask clang, and MSVC is asked by name. */
#  if PSTL_HAS_BUILTIN(__make_integer_seq) || defined(_MSC_VER)
#    define PSTL_HAS_MAKE_INTEGER_SEQ 1
#  else
#    define PSTL_HAS_MAKE_INTEGER_SEQ 0
#  endif

/* gcc's, from 8.  clang does not have it, and `__GNUC__' alone is not
   the test because clang defines it too. */
#  if defined(__GNUC__) && !defined(__clang__) && (__GNUC__ >= 8)
#    define PSTL_HAS_INTEGER_PACK 1
#  else
#    define PSTL_HAS_INTEGER_PACK 0
#  endif

/* `__LONG_LONG_MAX__', `__SCHAR_MAX__' and the rest, which
   `limits_clang_gcc/' reads directly.  `<limits.h>' is the portable
   way to the same numbers and is what `limits_msvc/' uses. */
#  if defined(__LONG_LONG_MAX__) && defined(__SCHAR_MAX__)
#    define PSTL_HAS_GNU_LIMIT_MACROS 1
#  else
#    define PSTL_HAS_GNU_LIMIT_MACROS 0
#  endif

#endif /* PSTL_NO_COMPILER_BUILTINS */

#endif // PSTL_COMPILER_BUILTINS_H
