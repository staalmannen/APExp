// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_helper.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "portable_stl/metaprogramming/helper/integral_constant.h"

TEST(metaprogramming_helper, integral_constant) {
  static_cast<void>(test_info_);
  /**
   * @brief Test type
   *
   */
  using check_type = ::portable_stl::integral_constant<std::size_t, 0U>;

  ASSERT_TRUE((testing::StaticAssertTypeEq<check_type::value_type, std::size_t>()));
  ASSERT_TRUE((testing::StaticAssertTypeEq<check_type::type, check_type>()));

  ASSERT_EQ(0U, check_type{}());
}

TEST(metaprogramming_helper, bool_constant) {
  static_cast<void>(test_info_);
  /**
   * @brief Test type
   *
   */
  using check_bool_type = ::portable_stl::bool_constant<true>;

  ASSERT_TRUE((testing::StaticAssertTypeEq<check_bool_type::value_type, bool>()));
  ASSERT_TRUE((testing::StaticAssertTypeEq<check_bool_type::type, check_bool_type>()));

  ASSERT_TRUE(check_bool_type{}());
}

TEST(metaprogramming_helper, true_type) {
  static_cast<void>(test_info_);
  /**
   * @brief Test type
   *
   */
  using check_true_type = ::portable_stl::true_type;

  ASSERT_TRUE((testing::StaticAssertTypeEq<check_true_type::value_type, bool>()));
  ASSERT_TRUE((testing::StaticAssertTypeEq<check_true_type::type, check_true_type>()));

  ASSERT_TRUE(check_true_type{}());
}

TEST(metaprogramming_helper, false_type) {
  static_cast<void>(test_info_);
  /**
   * @brief Test type
   *
   */
  using check_false_type = ::portable_stl::false_type;

  ASSERT_TRUE((testing::StaticAssertTypeEq<check_false_type::value_type, bool>()));
  ASSERT_TRUE((testing::StaticAssertTypeEq<check_false_type::type, check_false_type>()));

  ASSERT_FALSE(check_false_type{}());
}
