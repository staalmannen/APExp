// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="min.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MIN_H
#define PSTL_MIN_H

#include "../functional/less.h"

namespace portable_stl {

/**
 * @brief Returns the smaller of the given values.
 * @tparam t_type the type of arguments.
 * @tparam t_compare the type of compare function.
 * @param left A one arguments.
 * @param right An other argument.
 * @param compare the comparison function object which returns true if left is less than right.
 * @return left if is greater than right.
 */
template<class t_type, class t_compare>
constexpr inline static t_type const &min(t_type const &left, t_type const &right, t_compare compare) noexcept(
  noexcept(compare(left, right))) {
  return compare(right, left) ? right : left;
}

/**
 * @brief Returns the smaller of the given values.
 * @tparam t_type the type of arguments.
 * @param left A one arguments.
 * @param right An other argument.
 * @return left if is greater than right.
 */
template<class t_type>
constexpr inline static t_type const &min(t_type const &left, t_type const &right) noexcept(
  noexcept(min(left, right, ::portable_stl::less<t_type>{}))) {
  return min(left, right, ::portable_stl::less<t_type>());
}
} // namespace portable_stl

#endif /* PSTL_MIN_H */
