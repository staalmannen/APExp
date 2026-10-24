// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="conditional_bool_constant.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************

#ifndef PSTL_CONDITIONAL_BOOL_CONSTANT_H
#define PSTL_CONDITIONAL_BOOL_CONSTANT_H

#include "../helper/integral_constant.h"

namespace portable_stl {
/**
 * @brief If t_conditional is true_type, the member typedef type denotes t_true. If t_conditional is false_type, the
 * member typedef type denotes t_false.
 * @tparam t_conditional Conditional type.
 * @tparam t_true The type on true_type t_conditional.
 * @tparam t_false The type on false_type t_conditional.
 */
template<class bool_type, class t_true, class t_false> class conditional_bool_constant final {
public:
  /**
   * @brief The result type.
   */
  using type = t_true;
};

/**
 * @brief If t_conditional is true_type, the member typedef type denotes t_true. If t_conditional is false_type, the
 * member typedef type denotes t_false.
 * @tparam t_conditional Conditional type.
 * @tparam t_true The type on true_type t_conditional.
 * @tparam t_false The type on false_type t_conditional.
 */
template<class t_true, class t_false> class conditional_bool_constant<false_type, t_true, t_false> final {
public:
  /**
   * @brief The result type.
   */
  using type = t_false;
};

/**
 * @brief If t_conditional is true_type, the member typedef type denotes t_true. If t_conditional is false_type, the
 * member typedef type denotes t_false.
 * @tparam t_conditional Conditional type.
 * @tparam t_true The type on true_type t_conditional.
 * @tparam t_false The type on false_type t_conditional.
 */
template<class bool_type, class t_true, class t_false>
using conditional_bool_constant_t = typename conditional_bool_constant<bool_type, t_true, t_false>::type;

} // namespace portable_stl

#endif // PSTL_CONDITIONAL_BOOL_CONSTANT_H
