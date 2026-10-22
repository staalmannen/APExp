// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_logical_operator_inline_variables.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_METAPROGRAMMING_LOGICAL_OPERATOR_INLINE_VARIABLES_H
#define PSTL_METAPROGRAMMING_LOGICAL_OPERATOR_INLINE_VARIABLES_H

#include <gtest/gtest.h>

#include "portable_stl/metaprogramming/logical_operator/conjunction_v.h"
#include "portable_stl/metaprogramming/logical_operator/disjunction_v.h"
#include "portable_stl/metaprogramming/logical_operator/negation_v.h"

namespace test_metaprogramming_logical_operator {
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_logical_operator_conjunction_variables() {
  /**
   * @brief Not full defined class
   *
   */
  class undefined;

  ASSERT_FALSE((::portable_stl::conjunction_v<std::false_type, std::true_type, std::true_type, undefined>));
  ASSERT_FALSE((::portable_stl::conjunction_v<std::true_type, std::false_type, std::true_type, undefined>));
  ASSERT_FALSE((::portable_stl::conjunction_v<std::true_type, std::true_type, std::false_type, undefined>));
  ASSERT_TRUE((::portable_stl::conjunction_v<>));
  ASSERT_TRUE((::portable_stl::conjunction_v<std::true_type>));
  ASSERT_TRUE((::portable_stl::conjunction_v<std::true_type, std::true_type>));
  ASSERT_TRUE((::portable_stl::conjunction_v<std::true_type, std::true_type, std::true_type>));
}

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_logical_operator_disjunction_variables() {
  /**
   * @brief Not full defined class
   *
   */
  class undefined;

  ASSERT_FALSE((::portable_stl::disjunction_v<std::false_type, std::false_type, std::false_type>));
  ASSERT_TRUE((::portable_stl::disjunction_v<std::false_type, std::true_type, std::false_type>));
  ASSERT_TRUE((::portable_stl::disjunction_v<std::false_type, std::false_type, std::true_type>));
  ASSERT_TRUE((::portable_stl::disjunction_v<std::true_type, undefined>));
  ASSERT_TRUE((::portable_stl::disjunction_v<std::true_type>));
  ASSERT_FALSE((::portable_stl::disjunction_v<std::false_type>));
  ASSERT_FALSE((::portable_stl::disjunction_v<>));
}

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_logical_operator_negation_variables() {
  ASSERT_TRUE((::portable_stl::negation_v<std::false_type>));
  ASSERT_FALSE((::portable_stl::negation_v<std::true_type>));
}

} // namespace test_metaprogramming_logical_operator

#endif // PSTL_METAPROGRAMMING_LOGICAL_OPERATOR_INLINE_VARIABLES_H
