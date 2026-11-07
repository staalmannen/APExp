// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_base_of.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_BASE_OF_H
#define PSTL_IS_BASE_OF_H

#include "../helper/integral_constant.h"
#include "../logical_operator/conjunction.h"
#include "../primary_type/is_class.h"

namespace std {
namespace type_relations_helper {

  /**
   * @brief Helper function to detect void type.
   * The base type is not void.
   * @tparam base_type The tested type.
   * @return ::std::true_type
   */
  template<class base_type>::std::true_type check_ptr_conv(base_type const volatile *);

  /**
   * @brief Helper function to detect void type.
   * The base type is void.
   * @tparam base_type The tested type.
   * @return ::std::false_type
   */
  template<class base_type>::std::false_type check_ptr_conv(void const volatile *);

  /**
   * @brief Checks if a type is derived from the other type.
   * @tparam base_type The base type to check.
   * @tparam derived_type The derived type to check.
   * @return Result of checking.
   */
  template<class base_type, class derived_type>
  auto check_is_base_of(int) -> decltype(check_ptr_conv<base_type>(static_cast<derived_type *>(nullptr)));

  /**
   * @brief Checks if a type is derived from the other type.
   * Private or ambiguous base.
   * @return Result of checking.
   */
  template<class, class> auto check_is_base_of(...) -> ::std::true_type;
} // namespace type_relations_helper

/**
 * @brief Checks if a type is derived from the other type.
 *
 * @tparam base_type The base type to check.
 * @tparam derived_type The derived type to check.
 */
template<class base_type, class derived_type>
using is_base_of
  = ::std::conjunction<::std::is_class<base_type>,
                                ::std::is_class<derived_type>,
                                decltype(type_relations_helper::check_is_base_of<base_type, derived_type>(0))>;
} // namespace std

#endif // PSTL_IS_BASE_OF_H
