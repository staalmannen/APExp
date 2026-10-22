// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="common.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <array>

#include "portable_stl/common/nullptr_t.h"
#include "portable_stl/common/ptrdiff_t.h"
#include "portable_stl/common/size_t.h"

TEST(common, nullptr_t) {
  static_cast<void>(test_info_);

  ASSERT_TRUE((testing::StaticAssertTypeEq<::portable_stl::nullptr_t, decltype(nullptr)>()));
}

TEST(common, ptrdiff_t) {
  static_cast<void>(test_info_);

  std::array<std::uint32_t const, 2> test_buffer{0U, 0U};

  static_cast<void>(test_buffer);
  ASSERT_EQ(sizeof(::portable_stl::ptrdiff_t), sizeof(decltype(test_buffer.data() - test_buffer.data())));

  ASSERT_TRUE(
    (testing::StaticAssertTypeEq<::portable_stl::ptrdiff_t, decltype(test_buffer.data() - test_buffer.data())>()));
  ASSERT_TRUE((testing::StaticAssertTypeEq<::portable_stl::ptrdiff_t, std::ptrdiff_t>()));
}

TEST(common, size_t) {
  static_cast<void>(test_info_);
  ASSERT_EQ(sizeof(void *), sizeof(::portable_stl::size_t));

  ASSERT_TRUE((testing::StaticAssertTypeEq<::portable_stl::size_t, std::size_t>()));
}
