// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="language_support.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "portable_stl/language_support/initializer_list.h"
#include "portable_stl/language_support/initializer_list_ranges.h"
#include "portable_stl/language_support/make_initializer_list.h"

TEST(language_support, initializer_list) {
  static_cast<void>(test_info_);
  auto const test_list = {1, 1, 1, 1, 1};

  auto il(::portable_stl::make_initializer_list(test_list));

  constexpr decltype(il)::size_type size_of_list{5U};

  ASSERT_EQ(size_of_list, il.size());

  for (decltype(il)::reference item : il) {
    ASSERT_EQ(1, item);
  }
  for (decltype(il)::const_reference item : il) {
    ASSERT_EQ(1, item);
  }
  {
    decltype(il)::const_iterator const begin_range{::portable_stl::begin(il)};
    decltype(il)::const_iterator const begin_list{il.begin()};
    ASSERT_EQ(begin_range, begin_list);
    ASSERT_EQ(begin_list, begin_range);
  }
  {
    decltype(il)::iterator const end_range{::portable_stl::end(il)};
    decltype(il)::iterator const end_list{il.end()};
    ASSERT_EQ(end_range, end_list);
    ASSERT_EQ(end_list, end_range);
  }
  {
    decltype(il)::const_iterator const begin_range{::portable_stl::begin(il)};
    decltype(il)::iterator const       end_range{::portable_stl::end(il)};
    EXPECT_EQ(end_range - begin_range, il.size());
  }
}

namespace language_support_test_helper {
/**
 * @brief Helper class for check initializing by initializer_list
 *
 */
class check_il final {
  /**
   * @brief Helper value.
   *
   */
  std::int32_t m_value;

public:
  /**
   * @brief Constructor for create  by initializer_list.
   * @param il list for initialize.
   */
  constexpr check_il(::portable_stl::initializer_list<std::int32_t> const &il) noexcept : m_value(*il.begin()) {
  }

  /**
   * @brief Helper func.
   * @return value.
   */
  constexpr std::int32_t get() const noexcept {
    return m_value;
  }
};

} // namespace language_support_test_helper

TEST(language_support, initializer_list_class) {
  static_cast<void>(test_info_);

  language_support_test_helper::check_il const checker{
    {1, 0}
  };

  ASSERT_EQ(1, checker.get());
}
