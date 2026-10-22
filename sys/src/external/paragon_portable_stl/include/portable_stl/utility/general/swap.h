// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="swap.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_SWAP_H
#define PSTL_SWAP_H

#include "move.h"
#include "swap_def.h"

namespace portable_stl {
/**
 * @brief Swap left and right values.
 * @param left one value for swap.
 * @param right other value for swap.
 *
 * @return void
 */
template<
  class t_type,
  ::portable_stl::enable_if_bool_constant_t<::portable_stl::conjunction<::portable_stl::is_move_constructible<t_type>,
                                                                        ::portable_stl::is_move_assignable<t_type>>,
                                            int>>
inline void swap(t_type &left, t_type &right) noexcept(
  ::portable_stl::conjunction<::portable_stl::is_nothrow_move_constructible<t_type>,
                              ::portable_stl::is_nothrow_move_assignable<t_type>>{}()) {
  t_type tmp{::portable_stl::move(left)};
  left  = ::portable_stl::move(right);
  right = ::portable_stl::move(tmp);
}

} // namespace portable_stl

#endif /* PSTL_SWAP_H */
