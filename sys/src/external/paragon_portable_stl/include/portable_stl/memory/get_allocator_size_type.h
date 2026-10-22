// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="get_allocator_size_type.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_GET_ALLOCATOR_SIZE_TYPE_H
#define PSTL_GET_ALLOCATOR_SIZE_TYPE_H

#include "../metaprogramming/helper/integral_constant.h"
#include "../metaprogramming/reference_modifications/remove_reference.h"
#include "../metaprogramming/sign_modifications/make_unsigned.h"
#include "../metaprogramming/type_properties/has_size_type.h"
#include "pointer_traits.h"

namespace portable_stl {
/**
 * @brief Get size_type type for the allocator type.
 *
 * @tparam t_type the type for the size_type.
 * @tparam t_allocator the allocator type for get size_type.
 * @tparam t_clean_allocator the allocator type without references.
 */
template<class t_pointer,
         class t_allocator,
         class t_clean_allocator = ::portable_stl::remove_reference_t<t_allocator>,
         class                   = ::portable_stl::has_size_type<t_clean_allocator>>
class get_allocator_size_type final {
public:
  /**
   * @brief Result type.
   */
  using type = typename t_clean_allocator::size_type;
};

/**
 * @brief Get size_type type for the allocator type.
 *
 * @tparam t_type the type for the size_type.
 * @tparam t_allocator the allocator type for get size_type.
 * @tparam t_clean_allocator the allocator type without references.
 */
template<class t_pointer, class t_allocator, class t_clean_allocator>
class get_allocator_size_type<t_pointer, t_allocator, t_clean_allocator, ::portable_stl::false_type> final {
public:
  /**
   * @brief Result type.
   */
  using type = ::portable_stl::make_unsigned_t<typename ::portable_stl::pointer_traits<t_pointer>::difference_type>;
};

} // namespace portable_stl

#endif // PSTL_GET_ALLOCATOR_SIZE_TYPE_H
