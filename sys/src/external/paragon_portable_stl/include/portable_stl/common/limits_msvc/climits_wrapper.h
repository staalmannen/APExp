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

namespace portable_stl {
namespace numeric_limits_helper {

  constexpr char const char_min_constant{CHAR_MIN};
  constexpr char const char_max_constant{CHAR_MAX};

  constexpr signed char const signed_char_min_constant{SCHAR_MIN};
  constexpr signed char const signed_char_max_constant{SCHAR_MAX};

  constexpr unsigned char const unsigned_char_max_constant{UCHAR_MAX};

  constexpr unsigned int const wchat_max_constant{WCHAR_MAX};

  constexpr unsigned short unsigned_short_max_constant{USHRT_MAX};

  constexpr short short_max_constant{SHRT_MAX};

  constexpr unsigned int unsigned_int_max_constant{UINT_MAX};

  constexpr int int_min_constant{INT_MIN};
  constexpr int int_max_constant{INT_MAX};

  constexpr long long_min_constant{LONG_MIN};
  constexpr long long_max_constant{LONG_MAX};

  constexpr unsigned long unsigned_long_max_constant{ULONG_MAX};

  constexpr long long llong_min_constant{LLONG_MIN};
  constexpr long long llong_max_constant{LLONG_MAX};

  constexpr unsigned long long unsigned_llong_max_constant{ULLONG_MAX};

} // namespace numeric_limits_helper
} // namespace portable_stl

#endif // PSTL_CLIMITS_WRAPPER_H
