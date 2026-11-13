// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="numeric_limits.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_NUMERIC_LIMITS_H
#define PSTL_NUMERIC_LIMITS_H

#include "compiler_builtins.h"

/*
 * ***THE INFINITY AND NaN BUILTINS, WHICH SAT OUTSIDE BOTH LIMITS
 * DIRECTORIES AND SO OUTSIDE EVERY GUARD.***  Nine call sites in this
 * file -- `__builtin_huge_valf/_val', `__builtin_nanf/_nan' and
 * `__builtin_nansf/_nans' -- used directly, with no `__has_builtin'
 * and no portable sibling.  They are the reason `<forward_list>',
 * `<functional>', `<list>', `<map>', `<memory>', `<string>',
 * `<string_view>' and `<vector>' all stopped at `numeric_limits.h'
 * once the four SELECTORS were fixed: *the selectors were only ever
 * half the class, and the sweep that would have found the other half
 * did not exist yet.*  `sys/lib/tests/cxxbuiltin-sweep.py' is it.
 *
 * `<math.h>' is the portable answer and APExp's own is
 * `HUGE_VAL Inf(1)' / `NAN NaN()' -- FUNCTION CALLS, not literals, so
 * the portable arm cannot be evaluated at compile time.  `constexpr'
 * is kept all the same, for the reason spelled out in
 * `../memory/addressof.h': by [dcl.constexpr]/5 a `constexpr'
 * function no invocation of which can be constant is ill-formed NO
 * DIAGNOSTIC REQUIRED, and removing the keyword instead would make
 * every `constexpr' caller ill-formed in turn.
 *
 * **There is no portable SIGNALLING NaN**, so `signaling_NaN()'
 * returns the quiet one on this arm.  That is a conformance loss and
 * is recorded rather than hidden: nothing can distinguish them
 * without either a builtin or a bit pattern, and a bit pattern is not
 * available in a C++14 constant expression either.
 */
#if PSTL_HAS_BUILTIN(__builtin_huge_val) || PSTL_HAS_GNU_BUILTINS
#  define PSTL_HUGE_VALF()  __builtin_huge_valf()
#  define PSTL_HUGE_VAL()   __builtin_huge_val()
#  define PSTL_QUIET_NANF() __builtin_nanf("0")
#  define PSTL_QUIET_NAN()  __builtin_nan("0")
#  define PSTL_SIG_NANF()   __builtin_nansf("1")
#  define PSTL_SIG_NAN()    __builtin_nans("1")
#else
#  include <math.h>
#  define PSTL_HUGE_VALF()  HUGE_VALF
#  define PSTL_HUGE_VAL()   HUGE_VAL
#  define PSTL_QUIET_NANF() (static_cast<float>(NAN))
#  define PSTL_QUIET_NAN()  (static_cast<double>(NAN))
#  define PSTL_SIG_NANF()   (static_cast<float>(NAN))
#  define PSTL_SIG_NAN()    (static_cast<double>(NAN))
#endif

/*
 * `PSTL_FP_CONSTEXPR' IS `constexpr' ON THE BUILTIN ARM AND NOTHING ON
 * THE PORTABLE ONE, and the asymmetry is measured rather than
 * squeamish.  APExp's `<math.h>' spells `HUGE_VAL' as `Inf(1)' and
 * `NAN' as `NaN()' -- CALLS -- so a `constexpr' function returning one
 * can never be evaluated as a constant, which [dcl.constexpr]/5 makes
 * ill-formed NO DIAGNOSTIC REQUIRED.  g++ accepts it with
 * `-Winvalid-constexpr' and cpfe probably would too, but *probably*
 * is the word to avoid when the check costs a VM rebuild.
 *
 * **Dropping the keyword here cascades nowhere**: a grep for
 * `infinity()', `quiet_NaN()' and `signaling_NaN()' across the whole
 * library finds **0 callers outside this file**, so no `constexpr'
 * function is made ill-formed by the change.  *That is the whole
 * reason this file may do what `../memory/addressof.h' may not* --
 * there the three casts are equally non-constant, but `addressof' IS
 * called from `constexpr' code throughout `functional/' and the
 * iterators, so removing the keyword would break far more than it
 * fixed.  **Same rule, opposite answer, because the callers differ.**
 *
 * The cost is a real conformance loss and belongs in
 * `docs/notes/cxx-library.md': a user writing
 * `constexpr double d = numeric_limits<double>::infinity();' gets a
 * diagnostic on this platform and not on gcc.
 */
#if PSTL_HAS_BUILTIN(__builtin_huge_val) || PSTL_HAS_GNU_BUILTINS
#  define PSTL_FP_CONSTEXPR constexpr
#else
#  define PSTL_FP_CONSTEXPR
#endif

/*
 * BY CAPABILITY, NOT BY COMPILER NAME.  `limits_clang_gcc/' reads
 * gcc's own `__LONG_LONG_MAX__', `__SCHAR_MAX__' and `__UINT8_MAX__'
 * directly; `limits_msvc/' reads `<limits.h>' and `<float.h>', which
 * every hosted implementation has -- so the second is the PORTABLE
 * one and only its directory name says otherwise.  cpfe defines none
 * of the gcc macros and took the gcc arm, which is why
 * `<forward_list>' stopped in `climits_wrapper.h'.
 *
 * *The directory names are upstream's and are left alone*: renaming
 * them would make the next re-import a merge conflict in every file
 * rather than in this one.
 */
#if PSTL_HAS_GNU_LIMIT_MACROS
    #include "limits_clang_gcc/climits_wrapper.h"
    #include "limits_clang_gcc/float_wrapper.h"
#else
    #include "limits_msvc/climits_wrapper.h"
    #include "limits_msvc/float_wrapper.h"
#endif

#include "../common/int32_t.h"
#include "../metaprogramming/composite_type/is_arithmetic.h"
#include "../metaprogramming/cv_modifications/remove_cv.h"
#include "../metaprogramming/type_properties/is_signed.h"

namespace std {

constexpr unsigned int const char_bit_const{8};

// constants for different IEEE float denormalization styles
enum float_denorm_style {
  denorm_indeterminate = -1,
  denorm_absent        = 0,
  denorm_present       = 1
};

enum float_round_style { // constants for different IEEE rounding styles
  round_indeterminate       = -1,
  round_toward_zero         = 0,
  round_to_nearest          = 1,
  round_toward_infinity     = 2,
  round_toward_neg_infinity = 3
};

// base for all types, with common defaults
struct num_base {
  constexpr static float_denorm_style has_denorm      = denorm_absent;
  constexpr static bool               has_denorm_loss = false;

  constexpr static bool              has_infinity      = false;
  constexpr static bool              has_quiet_NaN     = false;
  constexpr static bool              has_signaling_NaN = false;
  constexpr static bool              is_bounded        = false;
  constexpr static bool              is_exact          = false;
  constexpr static bool              is_iec559         = false;
  constexpr static bool              is_integer        = false;
  constexpr static bool              is_modulo         = false;
  constexpr static bool              is_signed         = false;
  constexpr static bool              is_specialized    = false;
  constexpr static bool              tinyness_before   = false;
  constexpr static bool              traps             = false;
  constexpr static float_round_style round_style       = round_toward_zero;
  constexpr static int               digits            = 0;
  constexpr static int               digits10          = 0;
  constexpr static int               max_digits10      = 0;
  constexpr static int               max_exponent      = 0;
  constexpr static int               max_exponent10    = 0;
  constexpr static int               min_exponent      = 0;
  constexpr static int               min_exponent10    = 0;
  constexpr static int               radix             = 0;
};

// numeric limits for arbitrary type t_type (say little or nothing)
template<class t_type> class numeric_limits : public num_base {
public:
  constexpr static t_type(min)() noexcept {
    return t_type();
  }

  constexpr static t_type(max)() noexcept {
    return t_type();
  }

  constexpr static t_type lowest() noexcept {
    return t_type();
  }

  constexpr static t_type epsilon() noexcept {
    return t_type();
  }

  constexpr static t_type round_error() noexcept {
    return t_type();
  }

  constexpr static t_type denorm_min() noexcept {
    return t_type();
  }

  constexpr static t_type infinity() noexcept {
    return t_type();
  }

  constexpr static t_type quiet_NaN() noexcept {
    return t_type();
  }

  constexpr static t_type signaling_NaN() noexcept {
    return t_type();
  }
};

// numeric limits for const types
template<class t_type> class numeric_limits<t_type const> : public numeric_limits<t_type> {};

// numeric limits for volatile types
template<class t_type> class numeric_limits<t_type volatile> : public numeric_limits<t_type> {};

// numeric limits for const volatile types
template<class t_type> class numeric_limits<t_type const volatile> : public numeric_limits<t_type> {};

// base for integer types
struct num_int_base : num_base {
  constexpr static bool is_bounded     = true;
  constexpr static bool is_exact       = true;
  constexpr static bool is_integer     = true;
  constexpr static bool is_specialized = true;
  constexpr static int  radix          = 2;
};

// base for floating-point types
struct num_float_base : num_base {
  constexpr static float_denorm_style has_denorm = denorm_present;

  constexpr static bool              has_infinity      = true;
  constexpr static bool              has_quiet_NaN     = true;
  constexpr static bool              has_signaling_NaN = true;
  constexpr static bool              is_bounded        = true;
  constexpr static bool              is_iec559         = true;
  constexpr static bool              is_signed         = true;
  constexpr static bool              is_specialized    = true;
  constexpr static float_round_style round_style       = round_to_nearest;
  constexpr static int               radix             = numeric_limits_helper::float_radix_constant;
};

template<> class numeric_limits<bool> : public num_int_base {
public:
  constexpr static bool(min)() noexcept {
    return false;
  }

  constexpr static bool(max)() noexcept {
    return true;
  }

  constexpr static bool lowest() noexcept {
    return (min)();
  }

  constexpr static bool epsilon() noexcept {
    return 0;
  }

  constexpr static bool round_error() noexcept {
    return 0;
  }

  constexpr static bool denorm_min() noexcept {
    return 0;
  }

  constexpr static bool infinity() noexcept {
    return 0;
  }

  constexpr static bool quiet_NaN() noexcept {
    return 0;
  }

  constexpr static bool signaling_NaN() noexcept {
    return 0;
  }

  constexpr static int digits = 1;
};

template<> class numeric_limits<char> : public num_int_base {
public:
  constexpr static char(min)() noexcept {
    return numeric_limits_helper::char_min_constant;
  }

  constexpr static char(max)() noexcept {
    return numeric_limits_helper::char_max_constant;
  }

  constexpr static char lowest() noexcept {
    return (min)();
  }

  constexpr static char epsilon() noexcept {
    return 0;
  }

  constexpr static char round_error() noexcept {
    return 0;
  }

  constexpr static char denorm_min() noexcept {
    return 0;
  }

  constexpr static char infinity() noexcept {
    return 0;
  }

  constexpr static char quiet_NaN() noexcept {
    return 0;
  }

  constexpr static char signaling_NaN() noexcept {
    return 0;
  }

  constexpr static bool is_signed = 0 != numeric_limits_helper::char_min_constant;
  constexpr static bool is_modulo = 0 == numeric_limits_helper::char_min_constant;
  constexpr static int  digits    = 8 - (0 != numeric_limits_helper::char_min_constant);
  constexpr static int  digits10  = 2;
};

template<> class numeric_limits<signed char> : public num_int_base {
public:
  constexpr static signed char(min)() noexcept {
    return numeric_limits_helper::signed_char_min_constant;
  }

  constexpr static signed char(max)() noexcept {
    return numeric_limits_helper::signed_char_max_constant;
  }

  constexpr static signed char lowest() noexcept {
    return (min)();
  }

  constexpr static signed char epsilon() noexcept {
    return 0;
  }

  constexpr static signed char round_error() noexcept {
    return 0;
  }

  constexpr static signed char denorm_min() noexcept {
    return 0;
  }

  constexpr static signed char infinity() noexcept {
    return 0;
  }

  constexpr static signed char quiet_NaN() noexcept {
    return 0;
  }

  constexpr static signed char signaling_NaN() noexcept {
    return 0;
  }

  constexpr static bool is_signed = true;
  constexpr static int  digits    = char_bit_const - 1;
  constexpr static int  digits10  = (digits * 3) / 10;
};

template<> class numeric_limits<unsigned char> : public num_int_base {
public:
  constexpr static unsigned char(min)() noexcept {
    return 0;
  }

  constexpr static unsigned char(max)() noexcept {
    return numeric_limits_helper::unsigned_char_max_constant;
  }

  constexpr static unsigned char lowest() noexcept {
    return (min)();
  }

  constexpr static unsigned char epsilon() noexcept {
    return 0;
  }

  constexpr static unsigned char round_error() noexcept {
    return 0;
  }

  constexpr static unsigned char denorm_min() noexcept {
    return 0;
  }

  constexpr static unsigned char infinity() noexcept {
    return 0;
  }

  constexpr static unsigned char quiet_NaN() noexcept {
    return 0;
  }

  constexpr static unsigned char signaling_NaN() noexcept {
    return 0;
  }

  constexpr static bool is_modulo = true;
  constexpr static int  digits    = char_bit_const;
  constexpr static int  digits10  = (digits * 3) / 10;
};

#ifdef __cpp_char8_t
template<> class numeric_limits<char8_t> : public num_int_base {
public:
  constexpr static char8_t(min)() noexcept {
    return 0;
  }

  constexpr static char8_t(max)() noexcept {
    return numeric_limits_helper::unsigned_char_max_constant;
  }

  constexpr static char8_t lowest() noexcept {
    return 0;
  }

  constexpr static char8_t epsilon() noexcept {
    return 0;
  }

  constexpr static char8_t round_error() noexcept {
    return 0;
  }

  constexpr static char8_t denorm_min() noexcept {
    return 0;
  }

  constexpr static char8_t infinity() noexcept {
    return 0;
  }

  constexpr static char8_t quiet_NaN() noexcept {
    return 0;
  }

  constexpr static char8_t signaling_NaN() noexcept {
    return 0;
  }

  constexpr static bool is_modulo = true;
  constexpr static int  digits    = char_bit_const;
  constexpr static int  digits10  = (digits * 3) / 10;
};
#endif // defined(__cpp_char8_t)

template<> class numeric_limits<char16_t> : public num_int_base {
public:
  constexpr static char16_t(min)() noexcept {
    return 0;
  }

  constexpr static char16_t(max)() noexcept {
    return numeric_limits_helper::unsigned_short_max_constant;
  }

  constexpr static char16_t lowest() noexcept {
    return (min)();
  }

  constexpr static char16_t epsilon() noexcept {
    return 0;
  }

  constexpr static char16_t round_error() noexcept {
    return 0;
  }

  constexpr static char16_t denorm_min() noexcept {
    return 0;
  }

  constexpr static char16_t infinity() noexcept {
    return 0;
  }

  constexpr static char16_t quiet_NaN() noexcept {
    return 0;
  }

  constexpr static char16_t signaling_NaN() noexcept {
    return 0;
  }

  constexpr static bool is_modulo = true;
  constexpr static int  digits    = sizeof(char16_t) * char_bit_const;
  constexpr static int  digits10  = (digits * 3) / 10;
};

template<> class numeric_limits<char32_t> : public num_int_base {
public:
  constexpr static char32_t(min)() noexcept {
    return 0;
  }

  constexpr static char32_t(max)() noexcept {
    return numeric_limits_helper::unsigned_int_max_constant;
  }

  constexpr static char32_t lowest() noexcept {
    return (min)();
  }

  constexpr static char32_t epsilon() noexcept {
    return 0;
  }

  constexpr static char32_t round_error() noexcept {
    return 0;
  }

  constexpr static char32_t denorm_min() noexcept {
    return 0;
  }

  constexpr static char32_t infinity() noexcept {
    return 0;
  }

  constexpr static char32_t quiet_NaN() noexcept {
    return 0;
  }

  constexpr static char32_t signaling_NaN() noexcept {
    return 0;
  }

  constexpr static bool is_modulo = true;
  constexpr static int  digits    = sizeof(char32_t) * char_bit_const;
  constexpr static int  digits10  = (digits * 3) / 10;
};

template<> class numeric_limits<wchar_t> : public num_int_base {
public:
  constexpr static wchar_t(min)() noexcept {
    return 0;
  }

  constexpr static wchar_t(max)() noexcept {
    return numeric_limits_helper::wchat_max_constant;
  }

  constexpr static wchar_t lowest() noexcept {
    return (min)();
  }

  constexpr static wchar_t epsilon() noexcept {
    return 0;
  }

  constexpr static wchar_t round_error() noexcept {
    return 0;
  }

  constexpr static wchar_t denorm_min() noexcept {
    return 0;
  }

  constexpr static wchar_t infinity() noexcept {
    return 0;
  }

  constexpr static wchar_t quiet_NaN() noexcept {
    return 0;
  }

  constexpr static wchar_t signaling_NaN() noexcept {
    return 0;
  }

  constexpr static bool is_modulo = true;
  constexpr static int  digits    = sizeof(wchar_t) * char_bit_const - is_signed;
  constexpr static int  digits10  = (digits * 3) / 10;
};

template<> class numeric_limits<short> : public num_int_base {
public:
  constexpr static short(min)() noexcept {
    return -numeric_limits_helper::short_max_constant - 1;
  }

  constexpr static short(max)() noexcept {
    return numeric_limits_helper::short_max_constant;
  }

  constexpr static short lowest() noexcept {
    return (min)();
  }

  constexpr static short epsilon() noexcept {
    return 0;
  }

  constexpr static short round_error() noexcept {
    return 0;
  }

  constexpr static short denorm_min() noexcept {
    return 0;
  }

  constexpr static short infinity() noexcept {
    return 0;
  }

  constexpr static short quiet_NaN() noexcept {
    return 0;
  }

  constexpr static short signaling_NaN() noexcept {
    return 0;
  }

  constexpr static bool is_signed = true;
  constexpr static int  digits    = sizeof(short) * char_bit_const - is_signed;
  constexpr static int  digits10  = (digits * 3) / 10;
};

template<> class numeric_limits<int> : public num_int_base {
public:
  constexpr static int(min)() noexcept {
    return numeric_limits_helper::int_min_constant;
  }

  constexpr static int(max)() noexcept {
    return numeric_limits_helper::int_max_constant;
  }

  constexpr static int lowest() noexcept {
    return (min)();
  }

  constexpr static int epsilon() noexcept {
    return 0;
  }

  constexpr static int round_error() noexcept {
    return 0;
  }

  constexpr static int denorm_min() noexcept {
    return 0;
  }

  constexpr static int infinity() noexcept {
    return 0;
  }

  constexpr static int quiet_NaN() noexcept {
    return 0;
  }

  constexpr static int signaling_NaN() noexcept {
    return 0;
  }

  constexpr static bool is_signed = true;
  constexpr static int  digits    = sizeof(int) * char_bit_const - is_signed;
  constexpr static int  digits10  = (digits * 3) / 10;
};

template<> class numeric_limits<long> : public num_int_base {
public:
  constexpr static long(min)() noexcept {
    return numeric_limits_helper::long_min_constant;
  }

  constexpr static long(max)() noexcept {
    return numeric_limits_helper::long_max_constant;
  }

  constexpr static long lowest() noexcept {
    return (min)();
  }

  constexpr static long epsilon() noexcept {
    return 0;
  }

  constexpr static long round_error() noexcept {
    return 0;
  }

  constexpr static long denorm_min() noexcept {
    return 0;
  }

  constexpr static long infinity() noexcept {
    return 0;
  }

  constexpr static long quiet_NaN() noexcept {
    return 0;
  }

  constexpr static long signaling_NaN() noexcept {
    return 0;
  }

  // static_assert(sizeof(int) == sizeof(long), "LLP64 assumption"); windows only
  constexpr static bool is_signed = true;
  constexpr static int  digits    = sizeof(long) * char_bit_const - is_signed;
  constexpr static int  digits10  = (digits * 3) / 10;
};

template<> class numeric_limits<long long> : public num_int_base {
public:
  constexpr static long long(min)() noexcept {
    return numeric_limits_helper::llong_min_constant;
  }

  constexpr static long long(max)() noexcept {
    return numeric_limits_helper::llong_max_constant;
  }

  constexpr static long long lowest() noexcept {
    return (min)();
  }

  constexpr static long long epsilon() noexcept {
    return 0;
  }

  constexpr static long long round_error() noexcept {
    return 0;
  }

  constexpr static long long denorm_min() noexcept {
    return 0;
  }

  constexpr static long long infinity() noexcept {
    return 0;
  }

  constexpr static long long quiet_NaN() noexcept {
    return 0;
  }

  constexpr static long long signaling_NaN() noexcept {
    return 0;
  }

  constexpr static bool is_signed = true;
  constexpr static int  digits    = sizeof(long long) * char_bit_const - is_signed;
  constexpr static int  digits10  = (digits * 3) / 10;
};

template<> class numeric_limits<unsigned short> : public num_int_base {
public:
  constexpr static unsigned short(min)() noexcept {
    return 0;
  }

  constexpr static unsigned short(max)() noexcept {
    return numeric_limits_helper::unsigned_short_max_constant;
  }

  constexpr static unsigned short lowest() noexcept {
    return (min)();
  }

  constexpr static unsigned short epsilon() noexcept {
    return 0;
  }

  constexpr static unsigned short round_error() noexcept {
    return 0;
  }

  constexpr static unsigned short denorm_min() noexcept {
    return 0;
  }

  constexpr static unsigned short infinity() noexcept {
    return 0;
  }

  constexpr static unsigned short quiet_NaN() noexcept {
    return 0;
  }

  constexpr static unsigned short signaling_NaN() noexcept {
    return 0;
  }

  constexpr static bool is_modulo = true;
  constexpr static int  digits    = sizeof(unsigned short) * char_bit_const;
  constexpr static int  digits10  = (digits * 3) / 10;
};

template<> class numeric_limits<unsigned int> : public num_int_base {
public:
  constexpr static unsigned int(min)() noexcept {
    return 0;
  }

  constexpr static unsigned int(max)() noexcept {
    return numeric_limits_helper::unsigned_int_max_constant;
  }

  constexpr static unsigned int lowest() noexcept {
    return (min)();
  }

  constexpr static unsigned int epsilon() noexcept {
    return 0;
  }

  constexpr static unsigned int round_error() noexcept {
    return 0;
  }

  constexpr static unsigned int denorm_min() noexcept {
    return 0;
  }

  constexpr static unsigned int infinity() noexcept {
    return 0;
  }

  constexpr static unsigned int quiet_NaN() noexcept {
    return 0;
  }

  constexpr static unsigned int signaling_NaN() noexcept {
    return 0;
  }

  constexpr static bool is_modulo = true;
  constexpr static int  digits    = sizeof(unsigned int) * char_bit_const;
  constexpr static int  digits10  = (digits * 3) / 10;
};

template<> class numeric_limits<unsigned long> : public num_int_base {
public:
  constexpr static unsigned long(min)() noexcept {
    return 0;
  }

  constexpr static unsigned long(max)() noexcept {
    return numeric_limits_helper::unsigned_long_max_constant;
  }

  constexpr static unsigned long lowest() noexcept {
    return (min)();
  }

  constexpr static unsigned long epsilon() noexcept {
    return 0;
  }

  constexpr static unsigned long round_error() noexcept {
    return 0;
  }

  constexpr static unsigned long denorm_min() noexcept {
    return 0;
  }

  constexpr static unsigned long infinity() noexcept {
    return 0;
  }

  constexpr static unsigned long quiet_NaN() noexcept {
    return 0;
  }

  constexpr static unsigned long signaling_NaN() noexcept {
    return 0;
  }

  // static_assert(sizeof(unsigned int) == sizeof(unsigned long), "LLP64 assumption"); // windows only
  constexpr static bool is_modulo = true;
  constexpr static int  digits    = sizeof(unsigned long) * char_bit_const;
  constexpr static int  digits10  = (digits * 3) / 10;
};

template<> class numeric_limits<unsigned long long> : public num_int_base {
public:
  constexpr static unsigned long long(min)() noexcept {
    return 0;
  }

  constexpr static unsigned long long(max)() noexcept {
    return numeric_limits_helper::unsigned_llong_max_constant;
  }

  constexpr static unsigned long long lowest() noexcept {
    return (min)();
  }

  constexpr static unsigned long long epsilon() noexcept {
    return 0;
  }

  constexpr static unsigned long long round_error() noexcept {
    return 0;
  }

  constexpr static unsigned long long denorm_min() noexcept {
    return 0;
  }

  constexpr static unsigned long long infinity() noexcept {
    return 0;
  }

  constexpr static unsigned long long quiet_NaN() noexcept {
    return 0;
  }

  constexpr static unsigned long long signaling_NaN() noexcept {
    return 0;
  }

  constexpr static bool is_modulo = true;
  constexpr static int  digits    = sizeof(unsigned long long) * char_bit_const;
  constexpr static int  digits10  = (digits * 3) / 10;
};

template<> class numeric_limits<float> : public num_float_base {
public:
  constexpr static float(min)() noexcept {
    return numeric_limits_helper::float_true_min_constant;
  }

  constexpr static float(max)() noexcept {
    return numeric_limits_helper::float_true_max_constant;
  }

  constexpr static float lowest() noexcept {
    return -(max)();
  }

  constexpr static float epsilon() noexcept {
    return numeric_limits_helper::float_epsilon_constant;
  }

  constexpr static float round_error() noexcept {
    return 0.5F;
  }

  constexpr static float denorm_min() noexcept {
    return numeric_limits_helper::float_true_min_constant;
  }

  PSTL_FP_CONSTEXPR static float infinity() noexcept {
    return PSTL_HUGE_VALF();
  }

  PSTL_FP_CONSTEXPR static float quiet_NaN() noexcept {
    return PSTL_QUIET_NANF();
  }

  PSTL_FP_CONSTEXPR static float signaling_NaN() noexcept {
    return PSTL_SIG_NANF();
  }

  constexpr static int digits         = numeric_limits_helper::float_mant_digits_constant;
  constexpr static int digits10       = numeric_limits_helper::float_digits_constant;
  constexpr static int max_digits10   = 9;
  constexpr static int max_exponent   = numeric_limits_helper::float_max_exp_constant;
  constexpr static int max_exponent10 = numeric_limits_helper::float_max_10_exp_constant;
  constexpr static int min_exponent   = numeric_limits_helper::float_min_exp_constant;
  constexpr static int min_exponent10 = numeric_limits_helper::float_min_10_exp_constant;
};

template<> class numeric_limits<double> : public num_float_base {
public:
  constexpr static double(min)() noexcept {
    return numeric_limits_helper::double_true_min_constant;
  }

  constexpr static double(max)() noexcept {
    return numeric_limits_helper::double_true_max_constant;
  }

  constexpr static double lowest() noexcept {
    return -(max)();
  }

  constexpr static double epsilon() noexcept {
    return numeric_limits_helper::double_epsilon_constant;
  }

  constexpr static double round_error() noexcept {
    return 0.5;
  }

  constexpr static double denorm_min() noexcept {
    return numeric_limits_helper::double_true_min_constant;
  }

  PSTL_FP_CONSTEXPR static double infinity() noexcept {
    return PSTL_HUGE_VAL();
  }

  PSTL_FP_CONSTEXPR static double quiet_NaN() noexcept {
    return PSTL_QUIET_NAN();
  }

  PSTL_FP_CONSTEXPR static double signaling_NaN() noexcept {
    return PSTL_SIG_NAN();
  }

  constexpr static int digits         = numeric_limits_helper::double_mant_digits_constant;
  constexpr static int digits10       = numeric_limits_helper::double_digits_constant;
  constexpr static int max_digits10   = 17;
  constexpr static int max_exponent   = numeric_limits_helper::double_max_exp_constant;
  constexpr static int max_exponent10 = numeric_limits_helper::double_max_10_exp_constant;
  constexpr static int min_exponent   = numeric_limits_helper::double_min_exp_constant;
  constexpr static int min_exponent10 = numeric_limits_helper::double_min_10_exp_constant;
};

template<> class numeric_limits<long double> : public num_float_base {
public:
  constexpr static long double(min)() noexcept {
    return numeric_limits_helper::ldouble_true_min_constant;
  }

  constexpr static long double(max)() noexcept {
    return numeric_limits_helper::ldouble_true_max_constant;
  }

  constexpr static long double lowest() noexcept {
    return -(max)();
  }

  constexpr static long double epsilon() noexcept {
    return numeric_limits_helper::ldouble_epsilon_constant;
  }

  constexpr static long double round_error() noexcept {
    return 0.5L;
  }

  constexpr static long double denorm_min() noexcept {
    return numeric_limits_helper::ldouble_true_min_constant;
  }

  PSTL_FP_CONSTEXPR static long double infinity() noexcept {
    return static_cast<long double>(PSTL_HUGE_VAL());
  }

  PSTL_FP_CONSTEXPR static long double quiet_NaN() noexcept {
    return static_cast<long double>(PSTL_QUIET_NAN());
  }

  PSTL_FP_CONSTEXPR static long double signaling_NaN() noexcept {
    return static_cast<long double>(PSTL_SIG_NAN());
  }

  constexpr static int digits         = numeric_limits_helper::ldouble_mant_digits_constant;
  constexpr static int digits10       = numeric_limits_helper::ldouble_digits_constant;
  constexpr static int max_digits10   = 2 + numeric_limits_helper::ldouble_mant_digits_constant * 301L / 1000;
  constexpr static int max_exponent   = numeric_limits_helper::ldouble_max_exp_constant;
  constexpr static int max_exponent10 = numeric_limits_helper::ldouble_max_10_exp_constant;
  constexpr static int min_exponent   = numeric_limits_helper::ldouble_min_exp_constant;
  constexpr static int min_exponent10 = numeric_limits_helper::ldouble_min_10_exp_constant;
};
} // namespace std

#endif /* PSTL_NUMERIC_LIMITS_H */
