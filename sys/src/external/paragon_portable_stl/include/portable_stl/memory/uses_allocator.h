// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="uses_allocator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_USES_ALLOCATOR_H
#define PSTL_USES_ALLOCATOR_H

#include "../metaprogramming/helper/integral_constant.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../metaprogramming/type_relations/is_convertible.h"

namespace portable_stl {
namespace memory_helper {
  /**
   * @brief uses_allocator implementation.
   * Primary template.
   */
  template<class, class, class = void> class has_allocator_type {
  public:
    /**
     * @brief Result type.
     */
    using type = portable_stl::false_type;
  };

  /**
   * @brief uses_allocator implementation.
   *
   * @tparam t_type Checked type.
   * @tparam t_allocator_type Allocator type.
   */
  template<class t_type, class t_allocator_type>
  struct has_allocator_type<t_type, t_allocator_type, ::portable_stl::void_t<typename t_type::allocator_type>> {
  public:
    /**
     * @brief Result type.
     */
    using type = typename ::portable_stl::is_convertible<t_allocator_type, typename t_type::allocator_type>::type;
  };
} // namespace memory_helper

/**
 * @brief If t_type has a nested type allocator_type which is convertible from t_allocator_type, the member constant
 * value is true. Otherwise value is false.
 *
 * @tparam t_type Checked type.
 * @tparam t_allocator_type Allocator type.
 */
template<class t_type, class t_allocator_type>
using uses_allocator = typename memory_helper::has_allocator_type<t_type, t_allocator_type>::type;

} // namespace portable_stl

#endif /* PSTL_USES_ALLOCATOR_H */
