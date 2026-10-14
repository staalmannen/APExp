// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_pointer_modifications.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "portable_stl/metaprogramming/pointer_modifications/add_pointer.h"
#include "portable_stl/metaprogramming/pointer_modifications/remove_pointer.h"

namespace metaprogramming_array_modifications_helpers {
/**
 * @brief Empty class.
 *
 */
struct Empty {};
}; // namespace metaprogramming_array_modifications_helpers

TEST(metaprogramming_array_modifications, remove_pointer) {
  static_cast<void>(test_info_);
  { ASSERT_TRUE((std::is_same<std::uint32_t, ::portable_stl::remove_pointer<std::uint32_t *>::type>{})); }

  ASSERT_TRUE((std::is_same<void, ::portable_stl::remove_pointer_t<void>>{}));
  ASSERT_TRUE((std::is_same<std::uint32_t, ::portable_stl::remove_pointer_t<uint32_t>>{}));
  ASSERT_TRUE((std::is_same<std::uint32_t const, ::portable_stl::remove_pointer_t<uint32_t const *>>{}));
  ASSERT_TRUE((std::is_same<std::uint32_t volatile, ::portable_stl::remove_pointer_t<uint32_t volatile *>>{}));
  // clang-format off
  ASSERT_TRUE(
    (std::is_same<std::uint32_t volatile const, ::portable_stl::remove_pointer_t<uint32_t volatile const *>>{}));
  // clang-format on
  ASSERT_TRUE((std::is_same<std::uint32_t[5], ::portable_stl::remove_pointer_t<uint32_t[5]>>{}));
  ASSERT_TRUE((std::is_same<std::uint32_t[], ::portable_stl::remove_pointer_t<uint32_t[]>>{}));
  ASSERT_TRUE((std::is_same<std::uint32_t &, ::portable_stl::remove_pointer_t<uint32_t &>>{}));
  ASSERT_TRUE((std::is_same<std::uint32_t *, ::portable_stl::remove_pointer_t<uint32_t **>>{}));
  ASSERT_TRUE((std::is_same<metaprogramming_array_modifications_helpers::Empty,
                            ::portable_stl::remove_pointer_t<metaprogramming_array_modifications_helpers::Empty *>>{}));
}

TEST(metaprogramming_array_modifications, add_pointer) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type     = ::portable_stl::add_pointer<std::uint32_t>;
    /**
     * @brief Test type.
     */
    using result_type_t = typename test_type::type;
    ASSERT_TRUE((std::is_same<std::uint32_t *, result_type_t>()));
  }

  ASSERT_TRUE((std::is_same<void *, ::portable_stl::add_pointer_t<void>>{}));
  ASSERT_TRUE((std::is_same<std::uint32_t const *, ::portable_stl::add_pointer_t<uint32_t const>>{}));
  ASSERT_TRUE((std::is_same<std::uint32_t volatile *, ::portable_stl::add_pointer_t<uint32_t volatile>>{}));
  ASSERT_TRUE((std::is_same<std::uint32_t const volatile *, ::portable_stl::add_pointer_t<uint32_t const volatile>>{}));

  ASSERT_TRUE((std::is_same<std::uint32_t(*)[5], ::portable_stl::add_pointer_t<uint32_t[5]>>{}));
  ASSERT_TRUE((std::is_same<std::uint32_t *, ::portable_stl::add_pointer_t<uint32_t &>>{}));
  ASSERT_TRUE((std::is_same<std::uint32_t **, ::portable_stl::add_pointer_t<uint32_t *>>{}));
  ASSERT_TRUE((std::is_same<metaprogramming_array_modifications_helpers::Empty *,
                            ::portable_stl::add_pointer_t<metaprogramming_array_modifications_helpers::Empty>>{}));
}
