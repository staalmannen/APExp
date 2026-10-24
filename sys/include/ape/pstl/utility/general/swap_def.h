// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="swap_def.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************

#ifndef PSTL_SWAP_DEF_H
#define PSTL_SWAP_DEF_H

#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../../metaprogramming/type_properties/is_move_assignable.h"
#include "../../metaprogramming/type_properties/is_move_constructible.h"
#include "../../metaprogramming/type_properties/is_nothrow_move_assignable.h"
#include "../../metaprogramming/type_properties/is_nothrow_move_constructible.h"

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
                                            int>
  = 0>
inline void swap(t_type &left, t_type &right) noexcept(
  ::portable_stl::conjunction<::portable_stl::is_nothrow_move_constructible<t_type>,
                              ::portable_stl::is_nothrow_move_assignable<t_type>>{}());

} // namespace portable_stl

#endif /* PSTL_SWAP_DEF_H */
