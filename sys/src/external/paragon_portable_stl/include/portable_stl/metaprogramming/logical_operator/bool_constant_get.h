// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="bool_constant_get.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BOOL_CONSTANT_GET_H
#define PSTL_BOOL_CONSTANT_GET_H

#include "../helper/integral_constant.h"

namespace portable_stl {
namespace logical_operator_helper {
  /**
   * @brief Getter for the value from t_bool_constant ( portable_stl / stl ).
   * Version for realisation with operator()().
   *
   * @tparam t_bool_constant the source bool constant type.
   */
  template<class t_bool_constant> class bool_constant_get final {
  public:
    /**
     * @brief Result getter.
     * @return the value of t_bool_constant.
     */
    using type = ::portable_stl::bool_constant<static_cast<bool>(t_bool_constant{})>;
  };

  /**
   * @brief Getter for the value from t_bool_constant ( portable_stl / stl ).
   * Version for realisation with operator()().
   *
   * @tparam t_bool_constant the source bool constant type.
   */
  template<> class bool_constant_get<::portable_stl::true_type> final {
  public:
    /**
     * @brief Result getter.
     * @return the value of t_bool_constant.
     */
    using type = ::portable_stl::true_type;
  };

  /**
   * @brief Getter for the value from t_bool_constant ( portable_stl / stl ).
   * Version for realisation with operator()().
   *
   * @tparam t_bool_constant the source bool constant type.
   */
  template<> class bool_constant_get<::portable_stl::false_type> final {
  public:
    /**
     * @brief Result getter.
     * @return the value of t_bool_constant.
     */
    using type = ::portable_stl::false_type;
  };
} // namespace logical_operator_helper
/**
 * @brief Getter for the value from t_bool_constant ( portable_stl / stl ).
 * Version for realisation with operator()().
 *
 * @tparam t_bool_constant the source bool constant type.
 */
template<class t_bool_constant>
using bool_constant_get = typename ::portable_stl::logical_operator_helper::bool_constant_get<t_bool_constant>::type;
} // namespace portable_stl

#endif // PSTL_BOOL_CONSTANT_GET_H
