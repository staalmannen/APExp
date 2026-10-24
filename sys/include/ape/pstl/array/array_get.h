// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="array_get.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ARRAY_GET_H
#define PSTL_ARRAY_GET_H

#include "../common/size_t.h"
// #include "../metaprogramming/cv_modifications/as_const.h"
#include "../utility/general/move.h"
#include "array.h"

namespace portable_stl {
/**
 * @brief Accesses an element of an array.
 *
 * @tparam t_idx Index.
 * @tparam t_type Value type.
 * @tparam t_size Array's size.
 * @param some_array Array whose contents to extract.
 * @return A reference to the t_idx-th element of some_array.
 */
template<portable_stl::size_t t_idx, class t_type, portable_stl::size_t t_size>
constexpr inline t_type &get(array<t_type, t_size> &some_array) noexcept {
  static_assert(t_idx < t_size, "Index out of bounds in ::get<> (::array)");
  return some_array.m_elements[t_idx];
}

/**
 * @brief Accesses an element of an array.
 *
 * @tparam t_idx Index.
 * @tparam t_type Value type.
 * @tparam t_size Array's size.
 * @param some_array Array whose contents to extract.
 * @return A reference to the t_idx-th element of some_array.
 */
template<portable_stl::size_t t_idx, class t_type, portable_stl::size_t t_size>
constexpr inline t_type const &get(array<t_type, t_size> const &some_array) noexcept {
  static_assert(t_idx < t_size, "Index out of bounds in ::get<> (const ::array)");
  return some_array.m_elements[t_idx];
}

/**
 * @brief Accesses an element of an array.
 *
 * @tparam t_idx Index.
 * @tparam t_type Value type.
 * @tparam t_size Array's size.
 * @param some_array Array whose contents to extract.
 * @return A reference to the t_idx-th element of some_array.
 */
template<portable_stl::size_t t_idx, class t_type, portable_stl::size_t t_size>
constexpr inline t_type &&get(array<t_type, t_size> &&some_array) noexcept {
  static_assert(t_idx < t_size, "Index out of bounds in ::get<> (::array &&)");
  return ::portable_stl::move(some_array.m_elements[t_idx]);
}

/**
 * @brief Accesses an element of an array.
 *
 * @tparam t_idx Index.
 * @tparam t_type Value type.
 * @tparam t_size Array's size.
 * @param some_array Array whose contents to extract.
 * @return A reference to the t_idx-th element of some_array.
 */
template<portable_stl::size_t t_idx, class t_type, portable_stl::size_t t_size>
constexpr inline t_type const &&get(array<t_type, t_size> const &&some_array) noexcept {
  static_assert(t_idx < t_size, "Index out of bounds in ::get<> (const ::array &&)");
  return ::portable_stl::move(some_array.m_elements[t_idx]);
}
} // namespace portable_stl

#endif /* PSTL_ARRAY_GET_H */
