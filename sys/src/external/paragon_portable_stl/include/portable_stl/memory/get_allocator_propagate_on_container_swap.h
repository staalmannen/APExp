// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="get_allocator_propagate_on_container_swap.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_GET_ALLOCATOR_PROPAGATE_ON_CONTAINER_SWAP_H
#define PSTL_GET_ALLOCATOR_PROPAGATE_ON_CONTAINER_SWAP_H

#include "../metaprogramming/helper/integral_constant.h"
#include "../metaprogramming/reference_modifications/remove_reference.h"
#include "../metaprogramming/type_properties/has_propagate_on_container_swap.h"

namespace portable_stl {
/**
 * @brief Get propagate_on_container_swap type for the allocator type.
 *
 * @tparam t_type the type for the propagate_on_container_swap.
 * @tparam t_allocator the allocator type for get propagate_on_container_swap.
 * @tparam t_clean_allocator the allocator type without references.
 */
template<class t_allocator,
         class t_clean_allocator = ::portable_stl::remove_reference_t<t_allocator>,
         class                   = ::portable_stl::has_propagate_on_container_swap<t_clean_allocator>>
class get_allocator_propagate_on_container_swap final {
public:
  /**
   * @brief Result type.
   */
  using type = typename t_clean_allocator::propagate_on_container_swap;
};

/**
 * @brief Get propagate_on_container_swap type for the allocator type.
 *
 * @tparam t_type the type for the propagate_on_container_swap.
 * @tparam t_allocator the allocator type for get propagate_on_container_swap.
 * @tparam t_clean_allocator the allocator type without references.
 */
template<class t_allocator, class t_clean_allocator>
class get_allocator_propagate_on_container_swap<t_allocator, t_clean_allocator, ::portable_stl::false_type> final {
public:
  /**
   * @brief Result type.
   */
  using type = ::portable_stl::false_type;
};

} // namespace portable_stl

#endif // PSTL_GET_ALLOCATOR_PROPAGATE_ON_CONTAINER_SWAP_H
