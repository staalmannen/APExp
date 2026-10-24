// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="get_allocator_const_pointer.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_GET_ALLOCATOR_CONST_POINTER_H
#define PSTL_GET_ALLOCATOR_CONST_POINTER_H

#include "../metaprogramming/cv_modifications/add_const.h"
#include "../metaprogramming/helper/integral_constant.h"
#include "../metaprogramming/reference_modifications/remove_reference.h"
#include "../metaprogramming/type_properties/has_const_pointer.h"
#include "pointer_traits.h"

namespace portable_stl {
/**
 * @brief Get const_pointer type for the allocator type.
 *
 * @tparam t_type the type for the const_pointer.
 * @tparam t_allocator the allocator type for get const_pointer.
 * @tparam t_clean_allocator the allocator type without references.
 */
template<class t_type,
         class t_pointer,
         class t_allocator,
         class t_clean_allocator = ::portable_stl::remove_reference_t<t_allocator>,
         class                   = ::portable_stl::has_const_pointer<t_clean_allocator>>
class get_allocator_const_pointer final {
public:
  /**
   * @brief Result type.
   */
  using type = typename t_clean_allocator::const_pointer;
};

/**
 * @brief Get const_pointer type for the allocator type.
 *
 * @tparam t_type the type for the const_pointer.
 * @tparam t_allocator the allocator type for get const_pointer.
 * @tparam t_clean_allocator the allocator type without references.
 */
template<class t_type, class t_pointer, class t_allocator, class t_clean_allocator>
class get_allocator_const_pointer<t_type, t_pointer, t_allocator, t_clean_allocator, ::portable_stl::false_type> final {
  /**
   * @brief Additional layer of indirection for msvc.
   */
  using t_pointer_traits = ::portable_stl::pointer_traits<t_pointer>;
public:
  /**
   * @brief Result type.
   */
  using type = typename t_pointer_traits::template rebind<::portable_stl::add_const_t<t_type>>;
};

} // namespace portable_stl

#endif // PSTL_GET_ALLOCATOR_CONST_POINTER_H
