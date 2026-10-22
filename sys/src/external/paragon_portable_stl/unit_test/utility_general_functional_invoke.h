// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="utility_general_functional_invoke.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_UTILITY_GENERAL_FUNCTIONAL_INVOKE_H
#define PSTL_UTILITY_GENERAL_FUNCTIONAL_INVOKE_H

#include <gtest/gtest.h>

#include "portable_stl/utility/general/functional/invoke.h"

namespace test_utility_general_functional {

namespace utility_general_functional_helper {
  /**
   * @brief Test class.
   */
  class CallableClass {
  public:
    /**
     * @brief Simple operator() implemantation.
     *
     * @param value
     * @return 10 * value.
     */
    int operator()(int value) {
      return 10 * value;
    }
    /**
     * @brief Simple function.
     *
     * @param value
     * @return 10 * value.
     */
    int func(int value) {
      return 10 * value;
    }

    /**
     * @brief Member data.
     */
    int m_value{11};
  };

  /**
   * @brief Simple function.
   *
   * @param value
   * @return 10 * value.
   */
  int int_function(double value) {
    return 10 * value;
  }
} // namespace utility_general_functional_helper

/**
 * @brief Additional test for inline variable
 *
 */
inline void utility_general_functional_invoke() {
  // function
  EXPECT_EQ(10, ::portable_stl::invoke(utility_general_functional_helper::int_function, 1));

  // member function
  utility_general_functional_helper::CallableClass Obj1{};
  EXPECT_EQ(10, ::portable_stl::invoke(&utility_general_functional_helper::CallableClass::func, Obj1, 1));

  // data member
  EXPECT_EQ(11, ::portable_stl::invoke(&utility_general_functional_helper::CallableClass::m_value, Obj1));

  // functional object
  EXPECT_EQ(10, ::portable_stl::invoke(utility_general_functional_helper::CallableClass(), 1));
  EXPECT_EQ(10, ::portable_stl::invoke(Obj1, 1));

  // functional object
  // clang-format off
  EXPECT_EQ(10, ::portable_stl::invoke([](auto value){return 10 * value;}, 1));
  // clang-format on
}
} // namespace test_utility_general_functional

#endif // PSTL_UTILITY_GENERAL_FUNCTIONAL_INVOKE_H
