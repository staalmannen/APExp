// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="max.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MAX_H
#define PSTL_MAX_H

#include "../functional/less.h"

namespace portable_stl {

/**
 * @brief Compare two arguments with compare and return greater of arguments.
 * @tparam t_type the type of arguments.
 * @tparam t_compare the type of compare function.
 * @param left a one arguments.
 * @param right a other argument.
 * @param compare the comparison function object which returns true if left is less than right.
 * @return left if is greater than right.
 */
template<class t_type, class t_compare>
constexpr inline static t_type const &max(t_type const &left, t_type const &right, t_compare compare) noexcept(
  noexcept(compare(left, right))) {
  return (compare(left, right) ? right : left);
}

/**
 * @brief Compare two arguments return greater of arguments.
 * @tparam t_type the type of arguments.
 * @param left a one arguments.
 * @param right a other argument.
 * @return left if is greater than right.
 */
template<class t_type>
constexpr inline static t_type const &max(t_type const &left, t_type const &right) noexcept(
  noexcept(max(left, right, ::portable_stl::less<t_type>{}))) {
  return max(left, right, ::portable_stl::less<t_type>{});
}

} // namespace portable_stl

#endif // PSTL_MAX_H
