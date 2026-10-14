// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="convert_to_integral.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CONVERT_TO_INTEGRAL_H
#define PSTL_CONVERT_TO_INTEGRAL_H

#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/underlying_type.h"
#include "../metaprogramming/primary_type/is_enum.h"
#include "../metaprogramming/primary_type/is_floating_point.h"

namespace portable_stl {

constexpr inline int convert_to_integral(int value) {
  return value;
}

constexpr inline unsigned convert_to_integral(unsigned value) {
  return value;
}

constexpr inline long convert_to_integral(long value) {
  return value;
}

constexpr inline unsigned long convert_to_integral(unsigned long value) {
  return value;
}

constexpr inline long long convert_to_integral(long long value) {
  return value;
}

constexpr inline unsigned long long convert_to_integral(unsigned long long value) {
  return value;
}

template<typename t_float,
         ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_floating_point<t_float>, void *> = nullptr>
constexpr inline long long convert_to_integral(t_float value) {
  return value;
}

// #ifndef _LIBCPP_HAS_NO_INT128
// constexpr inline __int128_t convert_to_integral(__int128_t value) {
//   return value;
// }

// constexpr inline __uint128_t convert_to_integral(__uint128_t value) {
//   return value;
// }
// #endif

template<class t_type, class = ::portable_stl::is_enum<t_type>> class __sfinae_underlying_type final {
  using type            = ::portable_stl::underlying_type_t<t_type>;
  using t_promoted_type = decltype((static_cast<type>(1)) + 0);
};

template<class t_type> class __sfinae_underlying_type<t_type, ::portable_stl::false_type> final {};

template<class t_type>
constexpr inline typename __sfinae_underlying_type<t_type>::t_promoted_type convert_to_integral(t_type value) {
  return value;
}

} // namespace portable_stl

#endif // PSTL_CONVERT_TO_INTEGRAL_H
