// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="get_allocator_difference_type.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_GET_ALLOCATOR_DIFFERENCE_TYPE_H
#define PSTL_GET_ALLOCATOR_DIFFERENCE_TYPE_H

#include "../metaprogramming/helper/integral_constant.h"
#include "../metaprogramming/reference_modifications/remove_reference.h"
#include "../metaprogramming/type_properties/has_difference_type.h"
#include "pointer_traits.h"

namespace portable_stl {
/**
 * @brief Get difference_type type for the allocator type.
 *
 * @tparam t_type the type for the difference_type.
 * @tparam t_allocator the allocator type for get difference_type.
 * @tparam t_clean_allocator the allocator type without references.
 */
template<class t_pointer,
         class t_allocator,
         class t_clean_allocator = ::portable_stl::remove_reference_t<t_allocator>,
         class                   = ::portable_stl::has_difference_type<t_clean_allocator>>
class get_allocator_difference_type final {
public:
  /**
   * @brief Result type.
   */
  using type = typename t_clean_allocator::difference_type;
};

/**
 * @brief Get difference_type type for the allocator type.
 *
 * @tparam t_type the type for the difference_type.
 * @tparam t_allocator the allocator type for get difference_type.
 * @tparam t_clean_allocator the allocator type without references.
 */
template<class t_pointer, class t_allocator, class t_clean_allocator>
class get_allocator_difference_type<t_pointer, t_allocator, t_clean_allocator, ::portable_stl::false_type> final {
public:
  /**
   * @brief Result type.
   */
  using type = typename ::portable_stl::pointer_traits<t_pointer>::difference_type;
};

} // namespace portable_stl

#endif // PSTL_GET_ALLOCATOR_DIFFERENCE_TYPE_H
