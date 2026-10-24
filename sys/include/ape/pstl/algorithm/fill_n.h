// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="fill_n.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_FILL_N_H
#define PSTL_FILL_N_H
namespace portable_stl {
/**
 * @brief  Assigns the given value to the first count elements in the range beginning at first if count > 0. Does
 * nothing otherwise.
 *
 * @tparam t_output_iterator the type of the elements to modify.
 * @tparam t_size the type of number of elements to modify.
 * @tparam t_type the type of the value to be assigned.
 * @param first the beginning of the range of elements to modify.
 * @param count number of elements to modify.
 * @param value the value to be assigned.
 * @return Iterator one past the last element assigned if count > 0, first otherwise.
 */
template<class t_output_iterator, class t_size, class t_type>
inline static t_output_iterator fill_n(t_output_iterator first, t_size count, t_type const &value) noexcept(
  noexcept((*first) = value)) {
  for (t_size pos{0U}; pos < count; static_cast<void>(++pos)) {
    *(first++) = value;
  }
  return first;
}
} // namespace portable_stl

#endif // PSTL_FILL_N_H
