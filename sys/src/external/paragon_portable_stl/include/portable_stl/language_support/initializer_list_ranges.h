// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="initializer_list_ranges.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INITIALIZER_LIST_RANGES_H
#define PSTL_INITIALIZER_LIST_RANGES_H

#include "initializer_list.h"

namespace portable_stl {

/**
 * @brief First element.
 *
 * @tparam t_type types of initialization objects.
 * @param il list initialization.
 * @return first element.
 */
template<class t_type>
constexpr inline static auto begin(::portable_stl::initializer_list<t_type> il) noexcept ->
  typename ::portable_stl::initializer_list<t_type>::const_iterator {
  return il.begin();
}

/**
 * @brief One past the last element.
 *
 * @tparam t_type types of initialization objects.
 * @param il list initialization.
 * @return one past the last element.
 */
template<class t_type>
constexpr inline static auto end(::portable_stl::initializer_list<t_type> il) noexcept ->
  typename ::portable_stl::initializer_list<t_type>::const_iterator {
  return il.end();
}

} // namespace portable_stl

#endif // PSTL_INITIALIZER_LIST_RANGES_H
