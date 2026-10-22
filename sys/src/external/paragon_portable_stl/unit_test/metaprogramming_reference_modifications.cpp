// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_reference_modifications.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "portable_stl/metaprogramming/reference_modifications/add_lvalue_reference.h"
#include "portable_stl/metaprogramming/reference_modifications/add_rvalue_reference.h"
#include "portable_stl/metaprogramming/reference_modifications/remove_reference.h"

TEST(metaprogramming_reference_modifications, add_lvalue_reference) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Helper type
     *
     */
    using test_type = ::portable_stl::add_lvalue_reference_t<void>;
    constexpr test_type const *test_ptr{nullptr};
    ASSERT_EQ(nullptr, test_ptr);
  }
  ASSERT_TRUE((std::is_same<void, typename ::portable_stl::add_lvalue_reference<void>::type>{}));
  ASSERT_TRUE((std::is_same<void *&, typename ::portable_stl::add_lvalue_reference<void *>::type>{}));
  ASSERT_TRUE((std::is_same<void, ::portable_stl::add_lvalue_reference_t<void>>{}));
  ASSERT_TRUE((std::is_same<void *&, ::portable_stl::add_lvalue_reference_t<void *>>{}));
}

TEST(metaprogramming_reference_modifications, add_rvalue_reference) {
  static_cast<void>(test_info_);

  {
    /**
     * @brief Helper type.
     *
     */
    using test_type = typename ::portable_stl::add_rvalue_reference<void>::type;
    constexpr test_type const *test_ptr{nullptr};
    ASSERT_TRUE((std::is_same<void const *const, decltype(test_ptr)>{}));
    ASSERT_EQ(nullptr, test_ptr);
  }

  ASSERT_TRUE((std::is_same<void, typename ::portable_stl::add_rvalue_reference<void>::type>{}));
  ASSERT_TRUE((std::is_same<void *&&, typename ::portable_stl::add_rvalue_reference<void *>::type>{}));
  ASSERT_TRUE((std::is_same<void, ::portable_stl::add_rvalue_reference_t<void>>{}));
  ASSERT_TRUE((std::is_same<void *&&, ::portable_stl::add_rvalue_reference_t<void *>>{}));
}

TEST(metaprogramming_reference_modifications, remove_reference) {
  static_cast<void>(test_info_);

  {
    /**
     * @brief Helper type.
     *
     */
    using test_type = typename ::portable_stl::remove_reference<std::int32_t>::type;
    ASSERT_TRUE((std::is_same<std::int32_t, test_type>{}));
  }
  {
    /**
     * @brief Helper type.
     *
     */
    using test_type = typename ::portable_stl::remove_reference<std::int32_t &>::type;
    ASSERT_TRUE((std::is_same<std::int32_t, test_type>{}));
  }
  {
    /**
     * @brief Helper type.
     *
     */
    using test_type = typename ::portable_stl::remove_reference<std::int32_t &&>::type;
    ASSERT_TRUE((std::is_same<std::int32_t, test_type>{}));
  }

  ASSERT_TRUE((std::is_same<int32_t, typename ::portable_stl::remove_reference<std::int32_t &&>::type>{}));
  ASSERT_TRUE((std::is_same<int32_t, typename ::portable_stl::remove_reference<std::int32_t &>::type>{}));
  ASSERT_TRUE((std::is_same<int32_t, typename ::portable_stl::remove_reference<std::int32_t>::type>{}));
  ASSERT_TRUE((std::is_same<int32_t, ::portable_stl::remove_reference_t<std::int32_t &&>>{}));
  ASSERT_TRUE((std::is_same<int32_t, ::portable_stl::remove_reference_t<std::int32_t &>>{}));
  ASSERT_TRUE((std::is_same<int32_t, ::portable_stl::remove_reference_t<std::int32_t>>{}));
}
