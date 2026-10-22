// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="get_allocator_pointer.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_GET_ALLOCATOR_POINTER_H
#define PSTL_GET_ALLOCATOR_POINTER_H

#include "../metaprogramming/pointer_modifications/add_pointer.h"
#include "../metaprogramming/reference_modifications/remove_reference.h"
#include "../metaprogramming/type_properties/has_pointer.h"

namespace portable_stl {
/**
 * @brief Get pointer type for the allocator type.
 *
 * @tparam t_type the type for the pointer.
 * @tparam t_allocator the allocator type for get pointer.
 * @tparam t_clean_allocator the allocator type without references.
 */
template<class t_type,
         class t_allocator,
         class t_clean_allocator = ::portable_stl::remove_reference_t<t_allocator>,
         class                   = ::portable_stl::has_pointer<t_clean_allocator>>
class get_allocator_pointer final {
public:
  /**
   * @brief Result type.
   */
  using type = typename t_clean_allocator::pointer;
};

/**
 * @brief Get pointer type for the allocator type.
 *
 * @tparam t_type the type for the pointer.
 * @tparam t_allocator the allocator type for get pointer.
 * @tparam t_clean_allocator the allocator type without references.
 */
template<class t_type, class t_allocator, class t_clean_allocator>
class get_allocator_pointer<t_type, t_allocator, t_clean_allocator, ::portable_stl::false_type> final {
public:
  /**
   * @brief Result type.
   */
  using type = ::portable_stl::add_pointer_t<t_type>;
};

} // namespace portable_stl

#endif // PSTL_GET_ALLOCATOR_POINTER_H
