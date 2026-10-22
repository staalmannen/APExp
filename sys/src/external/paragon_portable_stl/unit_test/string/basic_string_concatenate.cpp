// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="basic_string_concatenate.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "basic_string_test_helper.h"
#include "portable_stl/string/basic_string.h"
#include "portable_stl/string/char_traits.h"

namespace test_string_insert_helper {
static void concat_string_string(TString const &str1, TString const &str2, TString const &expected) {
  ASSERT_EQ(0, str1.check_invariants());
  ASSERT_EQ(0, str2.check_invariants());

  auto const result = str1 + str2;

  ASSERT_EQ(0, result.check_invariants());
  EXPECT_EQ(expected, result);
}

static void concat_string_сstring(TString const &str, typename TString::const_pointer cstr, TString const &expected) {
  ASSERT_EQ(0, str.check_invariants());

  auto const result = str + cstr;

  ASSERT_EQ(0, result.check_invariants());
  EXPECT_EQ(expected, result);
}

static void concat_cstring_string(typename TString::const_pointer cstr, TString const &str, TString const &expected) {
  ASSERT_EQ(0, str.check_invariants());

  auto const result = cstr + str;

  ASSERT_EQ(0, result.check_invariants());
  EXPECT_EQ(expected, result);
}

static void concat_string_char(TString const &str, typename TString::value_type ch, TString const &expected) {
  ASSERT_EQ(0, str.check_invariants());

  auto const result = str + ch;

  ASSERT_EQ(0, result.check_invariants());
  EXPECT_EQ(expected, result);
}

static void concat_char_string(typename TString::value_type ch, TString const &str, TString const &expected) {
  ASSERT_EQ(0, str.check_invariants());

  auto const result = ch + str;

  ASSERT_EQ(0, result.check_invariants());
  EXPECT_EQ(expected, result);
}

static void concat_rstring_rstring(TString &&str1, TString &&str2, TString const &expected) {
  ASSERT_EQ(0, str1.check_invariants());
  ASSERT_EQ(0, str2.check_invariants());

  auto const result = std::move(str1) + std::move(str2);

  ASSERT_EQ(0, result.check_invariants());
  EXPECT_EQ(expected, result);
}

static void concat_rstring_string(TString &&str1, TString const &str2, TString const &expected) {
  ASSERT_EQ(0, str1.check_invariants());
  ASSERT_EQ(0, str2.check_invariants());

  auto const result = std::move(str1) + str2;

  ASSERT_EQ(0, result.check_invariants());
  EXPECT_EQ(expected, result);
}

static void concat_rstring_сstring(TString &&str, typename TString::const_pointer cstr, TString const &expected) {
  ASSERT_EQ(0, str.check_invariants());

  auto const result = std::move(str) + cstr;

  ASSERT_EQ(0, result.check_invariants());
  EXPECT_EQ(expected, result);
}

static void concat_rstring_char(TString &&str, typename TString::value_type ch, TString const &expected) {
  ASSERT_EQ(0, str.check_invariants());

  auto const result = std::move(str) + ch;

  ASSERT_EQ(0, result.check_invariants());
  EXPECT_EQ(expected, result);
}

static void concat_string_rstring(TString const &str1, TString &&str2, TString const &expected) {
  ASSERT_EQ(0, str1.check_invariants());
  ASSERT_EQ(0, str2.check_invariants());

  auto const result = str1 + std::move(str2);

  ASSERT_EQ(0, result.check_invariants());
  EXPECT_EQ(expected, result);
}

static void concat_cstring_rstring(typename TString::const_pointer cstr, TString &&str, TString const &expected) {
  ASSERT_EQ(0, str.check_invariants());

  auto const result = cstr + std::move(str);

  ASSERT_EQ(0, result.check_invariants());
  EXPECT_EQ(expected, result);
}

static void concat_char_rstring(typename TString::value_type ch, TString &&str, TString const &expected) {
  ASSERT_EQ(0, str.check_invariants());

  auto const result = ch + std::move(str);

  ASSERT_EQ(0, result.check_invariants());
  EXPECT_EQ(expected, result);
}
} // namespace test_string_insert_helper
// [operator+]

// (1)
TEST(basic_string, concat_string_string) {
  static_cast<void>(test_info_);
  // clang-format off
  TMManager::m_counter_ok_allocation = 100;
  test_string_insert_helper::concat_string_string(TString(""), TString(""), TString(""));

  test_string_insert_helper::concat_string_string(TString(""), TString("1234567890"), TString("1234567890"));
  test_string_insert_helper::concat_string_string(TString(""), TString("12345678901"), TString("12345678901"));
  test_string_insert_helper::concat_string_string(TString(""), TString("1234567890123456789012"), TString("1234567890123456789012"));
  test_string_insert_helper::concat_string_string(TString(""), TString("12345678901234567890123"), TString("12345678901234567890123"));

  test_string_insert_helper::concat_string_string(TString("1234567890"), TString(""), TString("1234567890"));
  test_string_insert_helper::concat_string_string(TString("12345678901"), TString(""), TString("12345678901"));
  test_string_insert_helper::concat_string_string(TString("1234567890123456789012"), TString(""), TString("1234567890123456789012"));
  test_string_insert_helper::concat_string_string(TString("12345678901234567890123"), TString(""), TString("12345678901234567890123"));

  test_string_insert_helper::concat_string_string(TString("12"), TString("34567890"), TString("1234567890"));
  test_string_insert_helper::concat_string_string(TString("12"), TString("345678901"), TString("12345678901"));
  test_string_insert_helper::concat_string_string(TString("12"), TString("34567890123456789012"), TString("1234567890123456789012"));
  test_string_insert_helper::concat_string_string(TString("12"), TString("345678901234567890123"), TString("12345678901234567890123"));

  test_string_insert_helper::concat_string_string(TString("1234567"), TString("890"), TString("1234567890"));
  test_string_insert_helper::concat_string_string(TString("1234567"), TString("8901"), TString("12345678901"));
  test_string_insert_helper::concat_string_string(TString("12345678901234"), TString("56789012"), TString("1234567890123456789012"));
  test_string_insert_helper::concat_string_string(TString("12345678901234"), TString("567890123"), TString("12345678901234567890123"));

  test_string_insert_helper::concat_string_string(TString("12345678901234567890123"), TString("12345678901234567890123"), TString("1234567890123456789012312345678901234567890123"));
  // clang-format on
}

// (2)
TEST(basic_string, concat_string_сstring) {
  static_cast<void>(test_info_);
  // clang-format off
  TMManager::m_counter_ok_allocation = 100;
  test_string_insert_helper::concat_string_сstring(TString(""), "", TString(""));

  test_string_insert_helper::concat_string_сstring(TString(""), "1234567890", TString("1234567890"));
  test_string_insert_helper::concat_string_сstring(TString(""), "12345678901", TString("12345678901"));
  test_string_insert_helper::concat_string_сstring(TString(""), "1234567890123456789012", TString("1234567890123456789012"));
  test_string_insert_helper::concat_string_сstring(TString(""), "12345678901234567890123", TString("12345678901234567890123"));

  test_string_insert_helper::concat_string_сstring(TString("1234567890"), "", TString("1234567890"));
  test_string_insert_helper::concat_string_сstring(TString("12345678901"), "", TString("12345678901"));
  test_string_insert_helper::concat_string_сstring(TString("1234567890123456789012"), "", TString("1234567890123456789012"));
  test_string_insert_helper::concat_string_сstring(TString("12345678901234567890123"), "", TString("12345678901234567890123"));

  test_string_insert_helper::concat_string_сstring(TString("12"), "34567890", TString("1234567890"));
  test_string_insert_helper::concat_string_сstring(TString("12"), "345678901", TString("12345678901"));
  test_string_insert_helper::concat_string_сstring(TString("12"), "34567890123456789012", TString("1234567890123456789012"));
  test_string_insert_helper::concat_string_сstring(TString("12"), "345678901234567890123", TString("12345678901234567890123"));

  test_string_insert_helper::concat_string_сstring(TString("1234567"), "890", TString("1234567890"));
  test_string_insert_helper::concat_string_сstring(TString("1234567"), "8901", TString("12345678901"));
  test_string_insert_helper::concat_string_сstring(TString("12345678901234"), "56789012", TString("1234567890123456789012"));
  test_string_insert_helper::concat_string_сstring(TString("12345678901234"), "567890123", TString("12345678901234567890123"));

  test_string_insert_helper::concat_string_сstring(TString("12345678901234567890123"), "12345678901234567890123", TString("1234567890123456789012312345678901234567890123"));
  // clang-format on
}

// (3)
TEST(basic_string, concat_string_char) {
  static_cast<void>(test_info_);
  // clang-format off
  TMManager::m_counter_ok_allocation = 100;
  test_string_insert_helper::concat_string_char(TString(""), 'a', TString("a"));
  test_string_insert_helper::concat_string_char(TString("1234567890"), 'a', TString("1234567890a"));
  test_string_insert_helper::concat_string_char(TString("12345678901"), 'a', TString("12345678901a"));
  test_string_insert_helper::concat_string_char(TString("1234567890123456789012"), 'a', TString("1234567890123456789012a"));
  test_string_insert_helper::concat_string_char(TString("12345678901234567890123"), 'a', TString("12345678901234567890123a"));
  // clang-format on
}

// (5)
TEST(basic_string, concat_cstring_string) {
  static_cast<void>(test_info_);
  // clang-format off
  TMManager::m_counter_ok_allocation = 100;
  test_string_insert_helper::concat_cstring_string("", TString(""), TString(""));

  test_string_insert_helper::concat_cstring_string("", TString("1234567890"), TString("1234567890"));
  test_string_insert_helper::concat_cstring_string("", TString("12345678901"), TString("12345678901"));
  test_string_insert_helper::concat_cstring_string("", TString("1234567890123456789012"), TString("1234567890123456789012"));
  test_string_insert_helper::concat_cstring_string("", TString("12345678901234567890123"), TString("12345678901234567890123"));

  test_string_insert_helper::concat_cstring_string("1234567890", TString(""), TString("1234567890"));
  test_string_insert_helper::concat_cstring_string("12345678901", TString(""), TString("12345678901"));
  test_string_insert_helper::concat_cstring_string("1234567890123456789012", TString(""), TString("1234567890123456789012"));
  test_string_insert_helper::concat_cstring_string("12345678901234567890123", TString(""), TString("12345678901234567890123"));

  test_string_insert_helper::concat_cstring_string("12", TString("34567890"), TString("1234567890"));
  test_string_insert_helper::concat_cstring_string("12", TString("345678901"), TString("12345678901"));
  test_string_insert_helper::concat_cstring_string("12", TString("34567890123456789012"), TString("1234567890123456789012"));
  test_string_insert_helper::concat_cstring_string("12", TString("345678901234567890123"), TString("12345678901234567890123"));

  test_string_insert_helper::concat_cstring_string("1234567", TString("890"), TString("1234567890"));
  test_string_insert_helper::concat_cstring_string("1234567", TString("8901"), TString("12345678901"));
  test_string_insert_helper::concat_cstring_string("12345678901234", TString("56789012"), TString("1234567890123456789012"));
  test_string_insert_helper::concat_cstring_string("12345678901234", TString("567890123"), TString("12345678901234567890123"));

  test_string_insert_helper::concat_cstring_string("12345678901234567890123", TString("12345678901234567890123"), TString("1234567890123456789012312345678901234567890123"));
  // clang-format on
}

// (6)
TEST(basic_string, concat_char_string) {
  static_cast<void>(test_info_);
  // clang-format off
  TMManager::m_counter_ok_allocation = 100;
  test_string_insert_helper::concat_char_string('a', TString(""),TString("a"));
  test_string_insert_helper::concat_char_string('a', TString("1234567890"), TString("a1234567890"));
  test_string_insert_helper::concat_char_string('a', TString("12345678901"), TString("a12345678901"));
  test_string_insert_helper::concat_char_string('a', TString("1234567890123456789012"), TString("a1234567890123456789012"));
  test_string_insert_helper::concat_char_string('a', TString("12345678901234567890123"), TString("a12345678901234567890123"));
  // clang-format on
}

// (8)
TEST(basic_string, concat_rstring_rstring) {
  static_cast<void>(test_info_);
  // clang-format off
  TMManager::m_counter_ok_allocation = 100;
  test_string_insert_helper::concat_rstring_rstring(TString(""), TString(""), TString(""));

  test_string_insert_helper::concat_rstring_rstring(TString(""), TString("1234567890"), TString("1234567890"));
  test_string_insert_helper::concat_rstring_rstring(TString(""), TString("12345678901"), TString("12345678901"));
  test_string_insert_helper::concat_rstring_rstring(TString(""), TString("1234567890123456789012"), TString("1234567890123456789012"));
  test_string_insert_helper::concat_rstring_rstring(TString(""), TString("12345678901234567890123"), TString("12345678901234567890123"));

  test_string_insert_helper::concat_rstring_rstring(TString("1234567890"), TString(""), TString("1234567890"));
  test_string_insert_helper::concat_rstring_rstring(TString("12345678901"), TString(""), TString("12345678901"));
  test_string_insert_helper::concat_rstring_rstring(TString("1234567890123456789012"), TString(""), TString("1234567890123456789012"));
  test_string_insert_helper::concat_rstring_rstring(TString("12345678901234567890123"), TString(""), TString("12345678901234567890123"));

  test_string_insert_helper::concat_rstring_rstring(TString("12"), TString("34567890"), TString("1234567890"));
  test_string_insert_helper::concat_rstring_rstring(TString("12"), TString("345678901"), TString("12345678901"));
  test_string_insert_helper::concat_rstring_rstring(TString("12"), TString("34567890123456789012"), TString("1234567890123456789012"));
  test_string_insert_helper::concat_rstring_rstring(TString("12"), TString("345678901234567890123"), TString("12345678901234567890123"));

  test_string_insert_helper::concat_rstring_rstring(TString("1234567"), TString("890"), TString("1234567890"));
  test_string_insert_helper::concat_rstring_rstring(TString("1234567"), TString("8901"), TString("12345678901"));
  test_string_insert_helper::concat_rstring_rstring(TString("12345678901234"), TString("56789012"), TString("1234567890123456789012"));
  test_string_insert_helper::concat_rstring_rstring(TString("12345678901234"), TString("567890123"), TString("12345678901234567890123"));

  test_string_insert_helper::concat_rstring_rstring(TString("12345678901234567890123"), TString("12345678901234567890123"), TString("1234567890123456789012312345678901234567890123"));
  // clang-format on
}

// (9)
TEST(basic_string, concat_rstring_string) {
  static_cast<void>(test_info_);
  // clang-format off
  TMManager::m_counter_ok_allocation = 100;
  test_string_insert_helper::concat_rstring_string(TString(""), TString(""), TString(""));

  test_string_insert_helper::concat_rstring_string(TString(""), TString("1234567890"), TString("1234567890"));
  test_string_insert_helper::concat_rstring_string(TString(""), TString("12345678901"), TString("12345678901"));
  test_string_insert_helper::concat_rstring_string(TString(""), TString("1234567890123456789012"), TString("1234567890123456789012"));
  test_string_insert_helper::concat_rstring_string(TString(""), TString("12345678901234567890123"), TString("12345678901234567890123"));

  test_string_insert_helper::concat_rstring_string(TString("1234567890"), TString(""), TString("1234567890"));
  test_string_insert_helper::concat_rstring_string(TString("12345678901"), TString(""), TString("12345678901"));
  test_string_insert_helper::concat_rstring_string(TString("1234567890123456789012"), TString(""), TString("1234567890123456789012"));
  test_string_insert_helper::concat_rstring_string(TString("12345678901234567890123"), TString(""), TString("12345678901234567890123"));

  test_string_insert_helper::concat_rstring_string(TString("12"), TString("34567890"), TString("1234567890"));
  test_string_insert_helper::concat_rstring_string(TString("12"), TString("345678901"), TString("12345678901"));
  test_string_insert_helper::concat_rstring_string(TString("12"), TString("34567890123456789012"), TString("1234567890123456789012"));
  test_string_insert_helper::concat_rstring_string(TString("12"), TString("345678901234567890123"), TString("12345678901234567890123"));

  test_string_insert_helper::concat_rstring_string(TString("1234567"), TString("890"), TString("1234567890"));
  test_string_insert_helper::concat_rstring_string(TString("1234567"), TString("8901"), TString("12345678901"));
  test_string_insert_helper::concat_rstring_string(TString("12345678901234"), TString("56789012"), TString("1234567890123456789012"));
  test_string_insert_helper::concat_rstring_string(TString("12345678901234"), TString("567890123"), TString("12345678901234567890123"));

  test_string_insert_helper::concat_rstring_string(TString("12345678901234567890123"), TString("12345678901234567890123"), TString("1234567890123456789012312345678901234567890123"));
  // clang-format on
}

// (10)
TEST(basic_string, concat_rstring_сstring) {
  static_cast<void>(test_info_);
  // clang-format off
  TMManager::m_counter_ok_allocation = 100;
  test_string_insert_helper::concat_rstring_сstring(TString(""), "", TString(""));

  test_string_insert_helper::concat_rstring_сstring(TString(""), "1234567890", TString("1234567890"));
  test_string_insert_helper::concat_rstring_сstring(TString(""), "12345678901", TString("12345678901"));
  test_string_insert_helper::concat_rstring_сstring(TString(""), "1234567890123456789012", TString("1234567890123456789012"));
  test_string_insert_helper::concat_rstring_сstring(TString(""), "12345678901234567890123", TString("12345678901234567890123"));

  test_string_insert_helper::concat_rstring_сstring(TString("1234567890"), "", TString("1234567890"));
  test_string_insert_helper::concat_rstring_сstring(TString("12345678901"), "", TString("12345678901"));
  test_string_insert_helper::concat_rstring_сstring(TString("1234567890123456789012"), "", TString("1234567890123456789012"));
  test_string_insert_helper::concat_rstring_сstring(TString("12345678901234567890123"), "", TString("12345678901234567890123"));

  test_string_insert_helper::concat_rstring_сstring(TString("12"), "34567890", TString("1234567890"));
  test_string_insert_helper::concat_rstring_сstring(TString("12"), "345678901", TString("12345678901"));
  test_string_insert_helper::concat_rstring_сstring(TString("12"), "34567890123456789012", TString("1234567890123456789012"));
  test_string_insert_helper::concat_rstring_сstring(TString("12"), "345678901234567890123", TString("12345678901234567890123"));

  test_string_insert_helper::concat_rstring_сstring(TString("1234567"), "890", TString("1234567890"));
  test_string_insert_helper::concat_rstring_сstring(TString("1234567"), "8901", TString("12345678901"));
  test_string_insert_helper::concat_rstring_сstring(TString("12345678901234"), "56789012", TString("1234567890123456789012"));
  test_string_insert_helper::concat_rstring_сstring(TString("12345678901234"), "567890123", TString("12345678901234567890123"));

  test_string_insert_helper::concat_rstring_сstring(TString("12345678901234567890123"), "12345678901234567890123", TString("1234567890123456789012312345678901234567890123"));
  // clang-format on
}

// (11)
TEST(basic_string, concat_rstring_char) {
  static_cast<void>(test_info_);
  // clang-format off
  TMManager::m_counter_ok_allocation = 100;
  test_string_insert_helper::concat_rstring_char(TString(""), 'a', TString("a"));
  test_string_insert_helper::concat_rstring_char(TString("1234567890"), 'a', TString("1234567890a"));
  test_string_insert_helper::concat_rstring_char(TString("12345678901"), 'a', TString("12345678901a"));
  test_string_insert_helper::concat_rstring_char(TString("1234567890123456789012"), 'a', TString("1234567890123456789012a"));
  test_string_insert_helper::concat_rstring_char(TString("12345678901234567890123"), 'a', TString("12345678901234567890123a"));
  // clang-format on
}

// (13)
TEST(basic_string, concat_string_rstring) {
  static_cast<void>(test_info_);
  // clang-format off
  TMManager::m_counter_ok_allocation = 100;
  test_string_insert_helper::concat_string_rstring(TString(""), TString(""), TString(""));

  test_string_insert_helper::concat_string_rstring(TString(""), TString("1234567890"), TString("1234567890"));
  test_string_insert_helper::concat_string_rstring(TString(""), TString("12345678901"), TString("12345678901"));
  test_string_insert_helper::concat_string_rstring(TString(""), TString("1234567890123456789012"), TString("1234567890123456789012"));
  test_string_insert_helper::concat_string_rstring(TString(""), TString("12345678901234567890123"), TString("12345678901234567890123"));

  test_string_insert_helper::concat_string_rstring(TString("1234567890"), TString(""), TString("1234567890"));
  test_string_insert_helper::concat_string_rstring(TString("12345678901"), TString(""), TString("12345678901"));
  test_string_insert_helper::concat_string_rstring(TString("1234567890123456789012"), TString(""), TString("1234567890123456789012"));
  test_string_insert_helper::concat_string_rstring(TString("12345678901234567890123"), TString(""), TString("12345678901234567890123"));

  test_string_insert_helper::concat_string_rstring(TString("12"), TString("34567890"), TString("1234567890"));
  test_string_insert_helper::concat_string_rstring(TString("12"), TString("345678901"), TString("12345678901"));
  test_string_insert_helper::concat_string_rstring(TString("12"), TString("34567890123456789012"), TString("1234567890123456789012"));
  test_string_insert_helper::concat_string_rstring(TString("12"), TString("345678901234567890123"), TString("12345678901234567890123"));

  test_string_insert_helper::concat_string_rstring(TString("1234567"), TString("890"), TString("1234567890"));
  test_string_insert_helper::concat_string_rstring(TString("1234567"), TString("8901"), TString("12345678901"));
  test_string_insert_helper::concat_string_rstring(TString("12345678901234"), TString("56789012"), TString("1234567890123456789012"));
  test_string_insert_helper::concat_string_rstring(TString("12345678901234"), TString("567890123"), TString("12345678901234567890123"));

  test_string_insert_helper::concat_string_rstring(TString("12345678901234567890123"), TString("12345678901234567890123"), TString("1234567890123456789012312345678901234567890123"));
  // clang-format on
}

// (14)
TEST(basic_string, concat_cstring_rstring) {
  static_cast<void>(test_info_);
  // clang-format off
  TMManager::m_counter_ok_allocation = 100;
  test_string_insert_helper::concat_cstring_rstring("", TString(""), TString(""));

  test_string_insert_helper::concat_cstring_rstring("", TString("1234567890"), TString("1234567890"));
  test_string_insert_helper::concat_cstring_rstring("", TString("12345678901"), TString("12345678901"));
  test_string_insert_helper::concat_cstring_rstring("", TString("1234567890123456789012"), TString("1234567890123456789012"));
  test_string_insert_helper::concat_cstring_rstring("", TString("12345678901234567890123"), TString("12345678901234567890123"));

  test_string_insert_helper::concat_cstring_rstring("1234567890", TString(""), TString("1234567890"));
  test_string_insert_helper::concat_cstring_rstring("12345678901", TString(""), TString("12345678901"));
  test_string_insert_helper::concat_cstring_rstring("1234567890123456789012", TString(""), TString("1234567890123456789012"));
  test_string_insert_helper::concat_cstring_rstring("12345678901234567890123", TString(""), TString("12345678901234567890123"));

  test_string_insert_helper::concat_cstring_rstring("12", TString("34567890"), TString("1234567890"));
  test_string_insert_helper::concat_cstring_rstring("12", TString("345678901"), TString("12345678901"));
  test_string_insert_helper::concat_cstring_rstring("12", TString("34567890123456789012"), TString("1234567890123456789012"));
  test_string_insert_helper::concat_cstring_rstring("12", TString("345678901234567890123"), TString("12345678901234567890123"));

  test_string_insert_helper::concat_cstring_rstring("1234567", TString("890"), TString("1234567890"));
  test_string_insert_helper::concat_cstring_rstring("1234567", TString("8901"), TString("12345678901"));
  test_string_insert_helper::concat_cstring_rstring("12345678901234", TString("56789012"), TString("1234567890123456789012"));
  test_string_insert_helper::concat_cstring_rstring("12345678901234", TString("567890123"), TString("12345678901234567890123"));

  test_string_insert_helper::concat_cstring_rstring("12345678901234567890123", TString("12345678901234567890123"), TString("1234567890123456789012312345678901234567890123"));
  // clang-format on
}

// (15)
TEST(basic_string, concat_char_rstring) {
  static_cast<void>(test_info_);
  // clang-format off
  TMManager::m_counter_ok_allocation = 100;
  test_string_insert_helper::concat_char_rstring('a', TString(""),TString("a"));
  test_string_insert_helper::concat_char_rstring('a', TString("1234567890"), TString("a1234567890"));
  test_string_insert_helper::concat_char_rstring('a', TString("12345678901"), TString("a12345678901"));
  test_string_insert_helper::concat_char_rstring('a', TString("1234567890123456789012"), TString("a1234567890123456789012"));
  test_string_insert_helper::concat_char_rstring('a', TString("12345678901234567890123"), TString("a12345678901234567890123"));
  // clang-format on
}

TEST(basic_string, concat_no_space) {
  static_cast<void>(test_info_);

  TMManager::m_counter_ok_allocation = 100;
  TString const s{test_string_helper::s2};
  TString s23{"12345678901234567890123"};
  TString const s_nm{"___________no matter___________"};
  TMManager::m_counter_ok_allocation = 0;

  try {
    test_string_insert_helper::concat_string_string(TString("a"), s, s_nm);
    EXPECT_TRUE(false);
  } catch (::portable_stl::bad_alloc<> &e) {
    static_cast<void>(e);
  }
  try {
    test_string_insert_helper::concat_string_сstring(TString("a"), "12345678901234567890123", s_nm);
    EXPECT_TRUE(false);
  } catch (::portable_stl::bad_alloc<> &e) {
    static_cast<void>(e);
  }
  try {
    test_string_insert_helper::concat_cstring_string("12345678901234567890123", TString("a"), s_nm);
    EXPECT_TRUE(false);
  } catch (::portable_stl::bad_alloc<> &e) {
    static_cast<void>(e);
  }
  try {
    test_string_insert_helper::concat_string_char(s, 'a', s_nm);
    EXPECT_TRUE(false);
  } catch (::portable_stl::bad_alloc<> &e) {
    static_cast<void>(e);
  }
  try {
    test_string_insert_helper::concat_char_string('a', s, s_nm);
    EXPECT_TRUE(false);
  } catch (::portable_stl::bad_alloc<> &e) {
    static_cast<void>(e);
  }
  try {
    test_string_insert_helper::concat_rstring_rstring(std::move(s23), TString("a"), s_nm);
    EXPECT_TRUE(false);
  } catch (::portable_stl::bad_alloc<> &e) {
    static_cast<void>(e);
  }
  try {
    test_string_insert_helper::concat_rstring_string(std::move(s23), s, s_nm);
    EXPECT_TRUE(false);
  } catch (::portable_stl::bad_alloc<> &e) {
    static_cast<void>(e);
  }
  try {
    test_string_insert_helper::concat_rstring_сstring(TString("a"), "12345678901234567890123", s_nm);
    EXPECT_TRUE(false);
  } catch (::portable_stl::bad_alloc<> &e) {
    static_cast<void>(e);
  }
  try {
    test_string_insert_helper::concat_rstring_char(std::move(s23), 'a', s_nm);
    EXPECT_TRUE(false);
  } catch (::portable_stl::bad_alloc<> &e) {
    static_cast<void>(e);
  }
  try {
    test_string_insert_helper::concat_string_rstring(s23, std::move(s23), s_nm);
    EXPECT_TRUE(false);
  } catch (::portable_stl::bad_alloc<> &e) {
    static_cast<void>(e);
  }
  try {
    test_string_insert_helper::concat_cstring_rstring("aa", std::move(s23), s_nm);
    EXPECT_TRUE(false);
  } catch (::portable_stl::bad_alloc<> &e) {
    static_cast<void>(e);
  }
  try {
    test_string_insert_helper::concat_char_rstring('a', std::move(s23), s_nm);
    EXPECT_TRUE(false);
  } catch (::portable_stl::bad_alloc<> &e) {
    static_cast<void>(e);
  }
}
