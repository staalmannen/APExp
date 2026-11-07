// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="swap_array.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_SWAP_ARRAY_H
#define PSTL_SWAP_ARRAY_H

#include "../../common/size_t.h"
#include "../../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../../metaprogramming/reference_modifications/add_lvalue_reference.h"
#include "../../metaprogramming/type_properties/is_nothrow_swappable.h"
#include "../../metaprogramming/type_properties/is_swappable_with.h"
#include "swap.h"

namespace std {
/**
 * @brief Swap left and right arrays.
 * Strange constraint in the template matches the declaration in the file is_swappable_with.h
 * @param left one array for swap.
 * @param right other array for swap.
 * @return void
 */
template<
  class t_type,
  ::std::size_t t_size,
  ::std::enable_if_bool_constant_t<typename ::std::is_swappable_with_helpers::is_swappable_with_class<
                                              ::std::add_lvalue_reference_t<t_type>,
                                              ::std::add_lvalue_reference_t<t_type>>::type,
                                            int>>
inline void swap(t_type (&left)[t_size],
                 t_type (&right)[t_size]) /*noexcept(::std::is_nothrow_swappable<t_type>{}())*/ {
  using ::std::swap;
  for (::std::size_t position{0U}; position < t_size; ++position) {
    swap(left[position], right[position]);
  }
}
} // namespace std

#endif /* PSTL_SWAP_ARRAY_H */
