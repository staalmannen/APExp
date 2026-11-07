// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_allocator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_ALLOCATOR_H
#define PSTL_IS_ALLOCATOR_H

#include "../../utility/general/declval.h"
#include "../helper/integral_constant.h"
#include "../other_transformations/void_t.h"

namespace std {
namespace primary_type_helper {

  /**
   * @brief is_allocator implementation.
   * @tparam t_type Tested type.
   */
  template<typename t_type, typename = void, typename = void> class is_allocator_impl final {
  public:
    /**
     * @brief Result type.
     */
    using type = std::false_type;
  };

  /**
   * @brief is_allocator implementation.
   * @tparam t_type Tested type.
   */
  template<typename t_type>
  class is_allocator_impl<t_type,
                          ::std::void_t<typename t_type::value_type>,
                          ::std::void_t<decltype(::std::declval<t_type &>().allocate(size_t(0)))>>
    final {
  public:
    /**
     * @brief Result type.
     */
    using type = std::true_type;
  };
} // namespace primary_type_helper

/**
 * @brief Check if type is allocator type.
 * @tparam t_type Tested type.
 */
template<typename t_type> using is_allocator = typename primary_type_helper::is_allocator_impl<t_type>::type;

} // namespace std

#endif // PSTL_IS_ALLOCATOR_H
