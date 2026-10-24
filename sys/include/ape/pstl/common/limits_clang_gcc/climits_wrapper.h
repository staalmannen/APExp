// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="climits_wrapper.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CLIMITS_WRAPPER_H
#define PSTL_CLIMITS_WRAPPER_H

#ifndef LLONG_MIN
#  define LLONG_MIN (-__LONG_LONG_MAX__ - 1)
#endif
#ifndef LLONG_MAX
#  define LLONG_MAX __LONG_LONG_MAX__
#endif
#ifndef ULLONG_MAX
#  define ULLONG_MAX (__LONG_LONG_MAX__ * 2ULL + 1)
#endif

namespace portable_stl {
namespace numeric_limits_helper {
#ifdef __CHAR_UNSIGNED__ /* -funsigned-char */
                         // #  define CHAR_MIN 0
                         // #  define CHAR_MAX __UINT8_MAX__  /* ??? */
  constexpr char const char_min_constant{0};
  constexpr char const char_max_constant{__UINT8_MAX__};
#else
  constexpr char const char_min_constant{-__SCHAR_MAX__ - 1};
  constexpr char const char_max_constant{__SCHAR_MAX__};
#endif

  constexpr signed char const signed_char_min_constant{-__SCHAR_MAX__ - 1};
  constexpr signed char const signed_char_max_constant{__SCHAR_MAX__};

  constexpr unsigned char const unsigned_char_max_constant{__SCHAR_MAX__ * 2 + 1};

  constexpr unsigned int const wchat_max_constant{__WCHAR_MAX__};

  constexpr unsigned short unsigned_short_max_constant{__SHRT_MAX__ * 2 + 1};

  constexpr short short_max_constant{__SHRT_MAX__};

  constexpr unsigned int unsigned_int_max_constant{__INT_MAX__ * 2U + 1U};

  constexpr int int_min_constant{-__INT_MAX__ - 1};
  constexpr int int_max_constant{__INT_MAX__};

  constexpr long long_min_constant{-__LONG_MAX__ - 1L};
  constexpr long long_max_constant{__LONG_MAX__};

  constexpr unsigned long unsigned_long_max_constant{__LONG_MAX__ * 2UL + 1UL};

  constexpr long long llong_min_constant{-__LONG_LONG_MAX__ - 1LL};
  constexpr long long llong_max_constant{__LONG_LONG_MAX__};

  constexpr unsigned long long unsigned_llong_max_constant{__LONG_LONG_MAX__ * 2ULL + 1ULL};

} // namespace numeric_limits_helper
} // namespace portable_stl

#endif // PSTL_CLIMITS_WRAPPER_H
