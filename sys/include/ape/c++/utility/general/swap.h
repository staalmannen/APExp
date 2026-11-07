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

namespace std {
/**
 * @brief Swap left and right values.
 * @param left one value for swap.
 * @param right other value for swap.
 *
 * @return void
 */
template<
  class t_type,
  ::std::enable_if_bool_constant_t<::std::conjunction<::std::is_move_constructible<t_type>,
                                                                        ::std::is_move_assignable<t_type>>,
                                            int>>
inline void swap(t_type &left, t_type &right) noexcept(
  ::std::conjunction<::std::is_nothrow_move_constructible<t_type>,
                              ::std::is_nothrow_move_assignable<t_type>>{}()) {
  t_type tmp{::std::move(left)};
  left  = ::std::move(right);
  right = ::std::move(tmp);
}

} // namespace std

#endif /* PSTL_SWAP_H */
