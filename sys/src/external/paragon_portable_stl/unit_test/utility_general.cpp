// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="utility_general.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <portable_stl/utility/general/declval.h>
#include <portable_stl/utility/general/forward.h>
#include <portable_stl/utility/general/make_exception_guard.h>
#include <portable_stl/utility/general/move.h>
#include <portable_stl/utility/general/swap.h>
#include <portable_stl/utility/general/swap_array.h>

#include "utility_general_helper.h"

TEST(utility_general, declval) {
  static_cast<void>(test_info_);
  ASSERT_TRUE((std::is_same<void, decltype(::portable_stl::declval<void>())>{}));
  ASSERT_TRUE((std::is_same<std::int32_t &&, decltype(::portable_stl::declval<std::int32_t>())>{}));
}

TEST(utility_general, swap) {
  static_cast<void>(test_info_);
  std::int32_t value_a{0};
  std::int32_t value_b{1};
  ASSERT_EQ(0, value_a);
  ASSERT_EQ(1, value_b);
  ::portable_stl::swap(value_a, value_b);
  ASSERT_EQ(1, value_a);
  ASSERT_EQ(0, value_b);
}

TEST(utility_general, swap_exception) {
  static_cast<void>(test_info_);
  {
    std::int32_t left_value;
    std::int32_t right_value;
    ::portable_stl::swap(left_value, right_value);
    EXPECT_TRUE(noexcept(::portable_stl::swap(left_value, right_value)));
  }
  {
    test_utility_general_helper::throw_on_move_assignment left_value;
    test_utility_general_helper::throw_on_move_assignment right_value;
    ::portable_stl::swap(left_value, right_value);
    EXPECT_FALSE(noexcept(::portable_stl::swap(left_value, right_value)));
  }
  {
    test_utility_general_helper::throw_on_move_construction left_value;
    test_utility_general_helper::throw_on_move_construction right_value;
    ::portable_stl::swap(left_value, right_value);
    EXPECT_FALSE(noexcept(::portable_stl::swap(left_value, right_value)));
  }
}

TEST(utility_general, swap_array) {
  static_cast<void>(test_info_);
}

TEST(utility_general, DISABLED_swap_array_exception) {
  static_cast<void>(test_info_);
  {
    std::int32_t left_value[1];
    std::int32_t right_value[1];
    ::portable_stl::swap(left_value, right_value);
    EXPECT_TRUE(noexcept(::portable_stl::swap(left_value, right_value)));
  }
  {
    test_utility_general_helper::throw_on_move_assignment left_value[1];
    test_utility_general_helper::throw_on_move_assignment right_value[1];
    ::portable_stl::swap(left_value, right_value);
    EXPECT_FALSE(noexcept(::portable_stl::swap(left_value, right_value)));
  }
  {
    test_utility_general_helper::throw_on_move_construction left_value[1];
    test_utility_general_helper::throw_on_move_construction right_value[1];
    ::portable_stl::swap(left_value, right_value);
    EXPECT_FALSE(noexcept(::portable_stl::swap(left_value, right_value)));
  }
}

TEST(utility_general, exchange) {
  static_cast<void>(test_info_);
}
TEST(utility_general, forward) {
  static_cast<void>(test_info_);

  {
    std::int32_t value{0};
    auto const   check(::portable_stl::forward<std::int32_t>(value));
    value = 1;
    ASSERT_EQ(0, check);
    ASSERT_EQ(1, value);
  }
  {
    constexpr auto check(::portable_stl::forward<std::int32_t>(0));
    ASSERT_EQ(0, check);
  }
  // ASSERT_TRUE((std::is_same<std::int32_t &&, decltype(::portable_stl::forward<std::int32_t>(0))>{}));
  {
    std::int32_t value{0};
    ASSERT_TRUE((std::is_same<std::int32_t &&, decltype(::portable_stl::forward<std::int32_t>(value))>{}));
    ASSERT_EQ(0, value);
  }
}

TEST(utility_general, forward_like) {
  static_cast<void>(test_info_);
}
TEST(utility_general, move) {
  static_cast<void>(test_info_);
  ASSERT_TRUE((std::is_same<std::int32_t &&, decltype(::portable_stl::move(0))>{}));
}

TEST(utility_general, make_exception_guard) {
  static_cast<void>(test_info_);
  {
    bool callback_called{false};
    {
      auto const guard = ::portable_stl::make_exception_guard([&callback_called]() -> void {
        callback_called = true;
      });
      static_cast<void>(guard);
    }
    ASSERT_TRUE(callback_called);
  }
  {
    bool callback_called{false};
    {
      auto guard = ::portable_stl::make_exception_guard([&callback_called]() -> void {
        callback_called = true;
      });
      guard.commit();
    }
    ASSERT_FALSE(callback_called);
  }
}
