// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="get_allocator_const_void_pointer.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_GET_ALLOCATOR_CONST_VOID_POINTER_H
#define PSTL_GET_ALLOCATOR_CONST_VOID_POINTER_H

#include "../metaprogramming/helper/integral_constant.h"
#include "../metaprogramming/reference_modifications/remove_reference.h"
#include "../metaprogramming/type_properties/has_const_void_pointer.h"
#include "pointer_traits.h"

namespace portable_stl {
/**
 * @brief Get const_void_pointer type for the allocator type.
 *
 * @tparam t_type the type for the const_void_pointer.
 * @tparam t_allocator the allocator type for get const_void_pointer.
 * @tparam t_clean_allocator the allocator type without references.
 */
template<class t_pointer,
         class t_allocator,
         class t_clean_allocator = ::portable_stl::remove_reference_t<t_allocator>,
         class                   = ::portable_stl::has_const_void_pointer<t_clean_allocator>>
class get_allocator_const_void_pointer final {
public:
  /**
   * @brief Result type.
   */
  using type = typename t_clean_allocator::const_void_pointer;
};

/**
 * @brief Get const_void_pointer type for the allocator type.
 *
 * @tparam t_type the type for the const_void_pointer.
 * @tparam t_allocator the allocator type for get const_void_pointer.
 * @tparam t_clean_allocator the allocator type without references.
 */
template<class t_pointer, class t_allocator, class t_clean_allocator>
class get_allocator_const_void_pointer<t_pointer, t_allocator, t_clean_allocator, ::portable_stl::false_type> final {
  /**
   * @brief Additional layer of indirection for msvc.
   */
  using t_pointer_traits = ::portable_stl::pointer_traits<t_pointer>;
public:
  /**
   * @brief Result type.
   */
  using type = typename t_pointer_traits::template rebind<void const>;
};

} // namespace portable_stl

#endif // PSTL_GET_ALLOCATOR_CONST_VOID_POINTER_H
