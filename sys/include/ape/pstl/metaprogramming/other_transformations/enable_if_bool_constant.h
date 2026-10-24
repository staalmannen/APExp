// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="enable_if_bool_constant.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ENABLE_IF_BOOL_CONSTANT_H
#define PSTL_ENABLE_IF_BOOL_CONSTANT_H
#include "../helper/integral_constant.h"

namespace portable_stl {

/**
 * @brief If t_condition is true_type, the member typedef type denotes t_type otherwise, there shall be no member type.
 *
 * @tparam t_condition bool_constant conditional type.
 * @tparam t_type result type.
 */
template<class t_condition, class t_type = void> class enable_if_bool_constant final {};

/**
 * @brief If t_condition is true_type, the member typedef type denotes t_type otherwise, there shall be no member type.
 *
 * @tparam t_type result type.
 */
template<class t_type> class enable_if_bool_constant<::portable_stl::true_type, t_type> final {
public:
  /**
   * @brief Result type.
   *
   */
  using type = t_type;
};

/**
 * @brief If t_condition is true_type, the member typedef type denotes t_type otherwise, there shall be no member type.
 *
 * @tparam t_condition bool_constant conditional type.
 * @tparam t_type result type.
 */
template<class t_condition, class t_type = void>
using enable_if_bool_constant_t = typename enable_if_bool_constant<t_condition, t_type>::type;

} // namespace portable_stl

#endif // PSTL_ENABLE_IF_BOOL_CONSTANT_H
