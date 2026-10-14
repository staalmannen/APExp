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

#if defined(_MSC_VER)
    #include "limits_msvc/climits_wrapper.h"
    #include "limits_msvc/float_wrapper.h"
#else // clang and gcc
    #include "limits_clang_gcc/climits_wrapper.h"
    #include "limits_clang_gcc/float_wrapper.h"
#endif

#include "../common/int32_t.h"
#include "../metaprogramming/composite_type/is_arithmetic.h"
#include "../metaprogramming/cv_modifications/remove_cv.h"
#include "../metaprogramming/type_properties/is_signed.h"

namespace portable_stl {

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

  constexpr static float infinity() noexcept {
    return __builtin_huge_valf();
  }

  constexpr static float quiet_NaN() noexcept {
    return __builtin_nanf("0");
  }

  constexpr static float signaling_NaN() noexcept {
    return __builtin_nansf("1");
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

  constexpr static double infinity() noexcept {
    return __builtin_huge_val();
  }

  constexpr static double quiet_NaN() noexcept {
    return __builtin_nan("0");
  }

  constexpr static double signaling_NaN() noexcept {
    return __builtin_nans("1");
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

  constexpr static long double infinity() noexcept {
    return static_cast<long double>(__builtin_huge_val());
  }

  constexpr static long double quiet_NaN() noexcept {
    return static_cast<long double>(__builtin_nan("0"));
  }

  constexpr static long double signaling_NaN() noexcept {
    return static_cast<long double>(__builtin_nans("1"));
  }

  constexpr static int digits         = numeric_limits_helper::ldouble_mant_digits_constant;
  constexpr static int digits10       = numeric_limits_helper::ldouble_digits_constant;
  constexpr static int max_digits10   = 2 + numeric_limits_helper::ldouble_mant_digits_constant * 301L / 1000;
  constexpr static int max_exponent   = numeric_limits_helper::ldouble_max_exp_constant;
  constexpr static int max_exponent10 = numeric_limits_helper::ldouble_max_10_exp_constant;
  constexpr static int min_exponent   = numeric_limits_helper::ldouble_min_exp_constant;
  constexpr static int min_exponent10 = numeric_limits_helper::ldouble_min_10_exp_constant;
};
} // namespace portable_stl

#endif /* PSTL_NUMERIC_LIMITS_H */
