// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_cv_modifications.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "portable_stl/metaprogramming/cv_modifications/add_const.h"
#include "portable_stl/metaprogramming/cv_modifications/add_cv.h"
#include "portable_stl/metaprogramming/cv_modifications/add_volatile.h"
#include "portable_stl/metaprogramming/cv_modifications/remove_const.h"
#include "portable_stl/metaprogramming/cv_modifications/remove_cv.h"
#include "portable_stl/metaprogramming/cv_modifications/remove_volatile.h"

TEST(metaprogramming_cv_modifications, add_const) {
  static_cast<void>(test_info_);

  ASSERT_TRUE((std::is_same<::portable_stl::add_const_t<std::uint32_t volatile>, std::uint32_t const volatile>{}));
  ASSERT_TRUE(
    (std::is_same<::portable_stl::add_const_t<std::uint32_t const volatile *>, std::uint32_t const volatile *const>{}));
  ASSERT_TRUE((std::is_same<::portable_stl::add_const_t<std::uint32_t const volatile *const>,
                            std::uint32_t const volatile *const>{}));
}

TEST(metaprogramming_cv_modifications, add_volatile) {
  static_cast<void>(test_info_);

  ASSERT_TRUE((std::is_same<::portable_stl::add_volatile_t<std::uint32_t volatile>, std::uint32_t volatile>{}));
  ASSERT_TRUE((std::is_same<::portable_stl::add_volatile_t<std::uint32_t const volatile *>,
                            std::uint32_t const volatile *volatile>{}));
  ASSERT_TRUE((std::is_same<::portable_stl::add_volatile_t<std::uint32_t const volatile *const>,
                            std::uint32_t const volatile *const volatile>{}));
}

TEST(metaprogramming_cv_modifications, add_cv) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Helper type.
     *
     */
    using test_type = ::portable_stl::add_cv_t<std::uint32_t>;
    constexpr test_type *check_type{nullptr};
    ASSERT_TRUE(nullptr == check_type);
  }

  {
    /**
     * @brief Helper type.
     *
     */
    using test_type = typename ::portable_stl::add_cv<std::uint32_t>::type;
    constexpr test_type *check_type{nullptr};
    ASSERT_TRUE(nullptr == check_type);
  }

  ASSERT_TRUE((std::is_same<::portable_stl::add_cv_t<std::uint32_t>, std::uint32_t const volatile>{}));
  ASSERT_TRUE((std::is_same<::portable_stl::add_cv_t<std::uint32_t const volatile *>,
                            std::uint32_t const volatile *const volatile>{}));
  ASSERT_TRUE((std::is_same<typename ::portable_stl::add_cv<std::uint32_t>::type, std::uint32_t const volatile>{}));
  ASSERT_TRUE((std::is_same<typename ::portable_stl::add_cv<std::uint32_t const volatile *>::type,
                            std::uint32_t const volatile *const volatile>{}));
}

TEST(metaprogramming_cv_modifications, remove_const) {
  static_cast<void>(test_info_);

  ASSERT_TRUE((std::is_same<::portable_stl::remove_const_t<std::uint32_t const volatile>, std::uint32_t volatile>{}));
  ASSERT_TRUE(
    (std::is_same<::portable_stl::remove_const_t<std::uint32_t const volatile *>, std::uint32_t const volatile *>{}));
}

TEST(metaprogramming_cv_modifications, remove_volatile) {
  static_cast<void>(test_info_);

  ASSERT_TRUE((std::is_same<::portable_stl::remove_volatile_t<std::uint32_t const volatile>, std::uint32_t const>{}));
  ASSERT_TRUE((
    std::is_same<::portable_stl::remove_volatile_t<std::uint32_t const volatile *>, std::uint32_t const volatile *>{}));
  static_cast<void>(
    std::is_same<::portable_stl::remove_volatile_t<std::uint32_t const volatile>, std::uint32_t const>{});

  static_cast<void>(
    std::is_same<::portable_stl::remove_volatile_t<std::uint32_t const volatile *>, std::uint32_t const volatile *>{});

  static_assert(
    std::is_same<::portable_stl::remove_volatile_t<std::uint32_t const volatile>, std::uint32_t const>::value,
    "remove_volatile_t invalid");
  static_assert(std::is_same<::portable_stl::remove_volatile_t<std::uint32_t const volatile *>,
                             std::uint32_t const volatile *>::value,
                "remove_volatile_t invalid");

  constexpr ::portable_stl::remove_volatile_t<std::uint32_t const volatile *> test_val{nullptr};
  static_cast<void>(test_val);
  ASSERT_TRUE(nullptr == test_val);
}

TEST(metaprogramming_cv_modifications, remove_cv) {
  static_cast<void>(test_info_);

  ASSERT_TRUE((std::is_same<::portable_stl::remove_cv_t<std::uint32_t const volatile>, std::uint32_t>{}));
  ASSERT_TRUE(
    (std::is_same<::portable_stl::remove_cv_t<std::uint32_t const volatile *>, std::uint32_t const volatile *>{}));
}
