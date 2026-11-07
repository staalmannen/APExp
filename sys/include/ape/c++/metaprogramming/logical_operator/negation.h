// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="negation.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_NEGATION_H
#define PSTL_NEGATION_H

#include "../helper/integral_constant.h"
#include "bool_constant_get.h"

namespace std {
namespace logical_operator_helper {
  /**
   * @brief The class template negation forms the logical negation of its template t_bool_constant arguments.
   *
   * @tparam t_bool_constant Porcessing arguments.
   */
  template<class t_bool_constant, class t_work_type = ::std::bool_constant_get<t_bool_constant>>
  class negation final {};

  /**
   * @brief The class template negation forms the logical negation of its template t_bool_constant arguments.
   *
   * @tparam t_bool_constant Porcessing arguments.
   */
  template<class t_bool_constant> class negation<t_bool_constant, ::std::true_type> final {
  public:
    /**
     * @brief Value getter.
     *
     * @return The current constant value.
     */
    using type = ::std::false_type;
  };

  /**
   * @brief The class template negation forms the logical negation of its template t_bool_constant arguments.
   *
   * @tparam t_bool_constant Porcessing arguments.
   */
  template<class t_bool_constant> class negation<t_bool_constant, ::std::false_type> final {
  public:
    /**
     * @brief Value getter.
     *
     * @return The current constant value.
     */
    using type = ::std::true_type;
  };
} // namespace logical_operator_helper

/**
 * @brief The class template negation forms the logical negation of its template t_bool_constant arguments.
 *
 * @tparam t_bool_constant Porcessing arguments.
 */
template<class t_bool_constant> using negation = typename logical_operator_helper::negation<t_bool_constant>::type;

} // namespace std

#endif // PSTL_NEGATION_H
