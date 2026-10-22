// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_sign_modifications.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <portable_stl/metaprogramming/sign_modifications/make_signed.h>
#include <portable_stl/metaprogramming/sign_modifications/make_unsigned.h>

namespace sign_modifications_helper {

/**
 * @brief Test char alias.
 */
using user_char8_t = char;

/**
 * @brief Helper enum for tests.
 */
enum struct Enum : std::uint32_t {
  zero,
  one
};

/**
 * @brief Helper enum for tests.
 */
enum struct BigEnum : std::uint64_t {
  bigzero = 0x0ULL,
  big     = 0xFFFFFFFFFFFFFFFFULL
};
} // namespace sign_modifications_helper
TEST(metaprogramming_sign_modifications, make_signed_numerical) {
  static_cast<void>(test_info_);

  {
    /**
     * @brief Helper type
     */
    using test_type      = ::portable_stl::make_signed<std::uint32_t>;
    /**
     * @brief Helper type
     */
    using checked_type_t = typename test_type::type;
    EXPECT_TRUE((std::is_same<std::int32_t, checked_type_t>{}()));
  }

  EXPECT_TRUE((std::is_same<std::int8_t, ::portable_stl::make_signed_t<sign_modifications_helper::user_char8_t>>{}()));
  EXPECT_TRUE((std::is_same<std::int8_t, ::portable_stl::make_signed_t<std::int8_t>>{}()));
  EXPECT_TRUE((std::is_same<std::int8_t, ::portable_stl::make_signed_t<std::uint8_t>>{}()));

  EXPECT_TRUE((std::is_same<std::int16_t, ::portable_stl::make_signed_t<std::int16_t>>{}()));
  EXPECT_TRUE((std::is_same<std::int16_t, ::portable_stl::make_signed_t<std::uint16_t>>{}()));

  EXPECT_TRUE((std::is_same<std::int32_t, ::portable_stl::make_signed_t<std::int32_t>>{}()));
  EXPECT_TRUE((std::is_same<std::int32_t, ::portable_stl::make_signed_t<std::uint32_t>>{}()));

  EXPECT_TRUE((std::is_same<std::int64_t, ::portable_stl::make_signed_t<std::int64_t>>{}()));
  EXPECT_TRUE((std::is_same<std::int64_t, ::portable_stl::make_signed_t<std::uint64_t>>{}()));
}

TEST(metaprogramming_sign_modifications, make_signed_enum) {
  static_cast<void>(test_info_);

  EXPECT_TRUE((std::is_same<std::int16_t, ::portable_stl::make_signed_t<char16_t>>{}()));
  EXPECT_TRUE((std::is_same<std::int16_t const, ::portable_stl::make_signed_t<char16_t const>>{}()));

  EXPECT_TRUE((std::is_same<std::int32_t, ::portable_stl::make_signed_t<char32_t>>{}()));
  EXPECT_TRUE((std::is_same<std::int32_t const, ::portable_stl::make_signed_t<char32_t const>>{}()));

  EXPECT_TRUE(
    (std::is_same<std::int32_t const, ::portable_stl::make_signed_t<sign_modifications_helper::Enum const>>{}()));
#ifndef __MACH__
  EXPECT_TRUE((std::is_same<std::int64_t, ::portable_stl::make_signed_t<sign_modifications_helper::BigEnum>>{}()));
#endif
}

TEST(metaprogramming_sign_modifications, make_signed_cv) {
  static_cast<void>(test_info_);

  EXPECT_TRUE((std::is_same<std::int32_t const, ::portable_stl::make_signed_t<std::int32_t const>>{}()));
  EXPECT_TRUE((std::is_same<std::int32_t volatile, ::portable_stl::make_signed_t<std::int32_t volatile>>{}()));
  EXPECT_TRUE(
    (std::is_same<std::int32_t const volatile, ::portable_stl::make_signed_t<std::int32_t const volatile>>{}()));
}

TEST(metaprogramming_sign_modifications, make_unsigned_numerical) {
  static_cast<void>(test_info_);

  {
    /**
     * @brief Helper type
     */
    using test_type = ::portable_stl::make_unsigned<std::int32_t>;

    /**
     * @brief Helper type
     */
    using checked_type_t = typename test_type::type;
    EXPECT_TRUE((std::is_same<std::uint32_t, checked_type_t>{}()));
  }

  EXPECT_TRUE(
    (std::is_same<std::uint8_t, ::portable_stl::make_unsigned_t<sign_modifications_helper::user_char8_t>>{}()));
  EXPECT_TRUE((std::is_same<std::uint8_t, ::portable_stl::make_unsigned_t<std::int8_t>>{}()));
  EXPECT_TRUE((std::is_same<std::uint8_t, ::portable_stl::make_unsigned_t<std::uint8_t>>{}()));

  EXPECT_TRUE((std::is_same<std::uint16_t, ::portable_stl::make_unsigned_t<std::int16_t>>{}()));
  EXPECT_TRUE((std::is_same<std::uint16_t, ::portable_stl::make_unsigned_t<std::uint16_t>>{}()));

  EXPECT_TRUE((std::is_same<std::uint32_t, ::portable_stl::make_unsigned_t<std::int32_t>>{}()));
  EXPECT_TRUE((std::is_same<std::uint32_t, ::portable_stl::make_unsigned_t<std::uint32_t>>{}()));

  EXPECT_TRUE((std::is_same<std::uint64_t, ::portable_stl::make_unsigned_t<std::int64_t>>{}()));
  EXPECT_TRUE((std::is_same<std::uint64_t, ::portable_stl::make_unsigned_t<std::uint64_t>>{}()));
}

TEST(metaprogramming_sign_modifications, make_unsigned_enum) {
  static_cast<void>(test_info_);

  EXPECT_TRUE((std::is_same<std::uint16_t, ::portable_stl::make_unsigned_t<char16_t>>{}()));
  EXPECT_TRUE((std::is_same<std::uint16_t const, ::portable_stl::make_unsigned_t<char16_t const>>{}()));

  EXPECT_TRUE((std::is_same<std::uint32_t, ::portable_stl::make_unsigned_t<char32_t>>{}()));
  EXPECT_TRUE((std::is_same<std::uint32_t const, ::portable_stl::make_unsigned_t<char32_t const>>{}()));
  EXPECT_TRUE(
    (std::is_same<std::uint32_t const, ::portable_stl::make_unsigned_t<sign_modifications_helper::Enum const>>{}()));
#ifndef __MACH__
  EXPECT_TRUE((std::is_same<std::uint64_t, ::portable_stl::make_unsigned_t<sign_modifications_helper::BigEnum>>{}()));
#endif
}

TEST(metaprogramming_sign_modifications, make_unsigned_cv) {
  static_cast<void>(test_info_);

  EXPECT_TRUE((std::is_same<std::uint32_t const, ::portable_stl::make_unsigned_t<std::int32_t const>>{}()));
  EXPECT_TRUE((std::is_same<std::uint32_t volatile, ::portable_stl::make_unsigned_t<std::int32_t volatile>>{}()));
  EXPECT_TRUE(
    (std::is_same<std::uint32_t const volatile, ::portable_stl::make_unsigned_t<std::int32_t const volatile>>{}()));
}
