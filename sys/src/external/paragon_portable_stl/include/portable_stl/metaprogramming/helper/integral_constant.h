// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="integral_constant.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INTEGRAL_CONSTANT_H
#define PSTL_INTEGRAL_CONSTANT_H

namespace portable_stl {

/**
 * @brief The metaprogramming constant value class.
 *
 * @tparam t_type The type of value.
 * @tparam t_value The current constant value.
 */
template<class t_type, t_type t_value> class integral_constant final {
public:
  /**
   * @brief The type of value.
   *
   */
  using value_type = t_type;
  /**
   * @brief The metaprogramming constant value class.
   *
   */
  using type       = integral_constant<t_type, t_value>;
  /**
   * @brief Value getter.
   *
   * @return The current constant value.
   */
  constexpr value_type operator()() const noexcept;
};

/**
 * @brief Value getter.
 *
 * @tparam t_type The type of value.
 * @tparam t_value The current constant value.
 *
 * @return The current constant value.
 */
template<class t_type, t_type t_value>
constexpr auto integral_constant<t_type, t_value>::operator()() const noexcept -> value_type {
  return t_value;
}

/**
 * @brief The metaprogramming boolean constant value class.
 *
 * @tparam t_value The current constant value.
 */
template<bool t_value> using bool_constant = integral_constant<bool, t_value>;

/**
 * @brief The metaprogramming true boolean constant value class.
 *
 */
using true_type = bool_constant<true>;

/**
 * @brief The metaprogramming false boolean constant value class.
 *
 */
using false_type = bool_constant<false>;

} // namespace portable_stl

#endif // PSTL_INTEGRAL_CONSTANT_H
