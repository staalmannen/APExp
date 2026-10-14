// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="basic_string_compare.cpp"
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

// [compare operators]

TEST(basic_string, op_eq_pointer_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_TRUE("" == TString{""});
  EXPECT_TRUE("abc" == TString{"abc"});
  EXPECT_TRUE("123456789012345679081324657890" == TString{"123456789012345679081324657890"});

  EXPECT_FALSE("" == TString{"abc"});
  EXPECT_FALSE("" == TString{"123456789012345679081324657890"});

  EXPECT_FALSE("abc" == TString{""});
}

TEST(basic_string, op_eq_string_pointer) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_TRUE(TString{""} == "");
  EXPECT_TRUE(TString{"abc"} == "abc");
  EXPECT_TRUE(TString{"123456789012345679081324657890"} == "123456789012345679081324657890");

  EXPECT_FALSE(TString{"abc"} == "");
  EXPECT_FALSE(TString{"123456789012345679081324657890"} == "");

  EXPECT_FALSE(TString{""} == "abc");
}

TEST(basic_string, op_eq_string_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_TRUE(TString{""} == TString{""});
  EXPECT_TRUE(TString{"abc"} == TString{"abc"});
  EXPECT_TRUE(TString{"123456789012345679081324657890"} == TString{"123456789012345679081324657890"});

  EXPECT_FALSE(TString{"abc"} == TString{""});
  EXPECT_FALSE(TString{"abc"} == TString{"abcabc"});
  EXPECT_FALSE(TString{"123456789012345679081324657890"} == TString{""});
  EXPECT_FALSE(TString{""} == TString{"123456789012345679081324657890"});

  EXPECT_FALSE(TString{""} == TString{"abc"});
}

TEST(basic_string, op_eq_string_view_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_TRUE(TStringView{""} == TString{""});
  EXPECT_TRUE(TStringView{"abc"} == TString{"abc"});
  EXPECT_TRUE(TStringView{"123456789012345679081324657890"} == TString{"123456789012345679081324657890"});

  EXPECT_FALSE(TStringView{""} == TString{"abc"});
  EXPECT_FALSE(TStringView{""} == TString{"123456789012345679081324657890"});

  EXPECT_FALSE(TStringView{"abc"} == TString{""});
}

TEST(basic_string, op_eq_string_string_view) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_TRUE(TString{""} == TStringView{""});
  EXPECT_TRUE(TString{"abc"} == TStringView{"abc"});
  EXPECT_TRUE(TString{"123456789012345679081324657890"} == TStringView{"123456789012345679081324657890"});

  EXPECT_FALSE(TString{"abc"} == TStringView{""});
  EXPECT_FALSE(TString{"123456789012345679081324657890"} == TStringView{""});

  EXPECT_FALSE(TString{""} == TStringView{"abc"});
}

TEST(basic_string, op_ne_pointer_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_FALSE("" != TString{""});
  EXPECT_FALSE("abc" != TString{"abc"});
  EXPECT_FALSE("123456789012345679081324657890" != TString{"123456789012345679081324657890"});

  EXPECT_TRUE("" != TString{"abc"});
  EXPECT_TRUE("" != TString{"123456789012345679081324657890"});

  EXPECT_TRUE("abc" != TString{""});
}

TEST(basic_string, op_ne_string_pointer) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_FALSE(TString{""} != "");
  EXPECT_FALSE(TString{"abc"} != "abc");
  EXPECT_FALSE(TString{"123456789012345679081324657890"} != "123456789012345679081324657890");

  EXPECT_TRUE(TString{"abc"} != "");
  EXPECT_TRUE(TString{"123456789012345679081324657890"} != "");

  EXPECT_TRUE(TString{""} != "abc");
}

TEST(basic_string, op_ne_string_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_FALSE(TString{""} != TString{""});
  EXPECT_FALSE(TString{"abc"} != TString{"abc"});
  EXPECT_FALSE(TString{"123456789012345679081324657890"} != TString{"123456789012345679081324657890"});

  EXPECT_TRUE(TString{"abc"} != TString{""});
  EXPECT_TRUE(TString{"abc"} != TString{"abcabc"});
  EXPECT_TRUE(TString{"123456789012345679081324657890"} != TString{""});
  EXPECT_TRUE(TString{""} != TString{"123456789012345679081324657890"});

  EXPECT_TRUE(TString{""} != TString{"abc"});
}

TEST(basic_string, op_ne_string_view_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_FALSE(TStringView{""} != TString{""});
  EXPECT_FALSE(TStringView{"abc"} != TString{"abc"});
  EXPECT_FALSE(TStringView{"123456789012345679081324657890"} != TString{"123456789012345679081324657890"});

  EXPECT_TRUE(TStringView{""} != TString{"abc"});
  EXPECT_TRUE(TStringView{""} != TString{"123456789012345679081324657890"});

  EXPECT_TRUE(TStringView{"abc"} != TString{""});
}

TEST(basic_string, op_ne_string_string_view) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_FALSE(TString{""} != TStringView{""});
  EXPECT_FALSE(TString{"abc"} != TStringView{"abc"});
  EXPECT_FALSE(TString{"123456789012345679081324657890"} != TStringView{"123456789012345679081324657890"});

  EXPECT_TRUE(TString{"abc"} != TStringView{""});
  EXPECT_TRUE(TString{"123456789012345679081324657890"} != TStringView{""});

  EXPECT_TRUE(TString{""} != TStringView{"abc"});
}

TEST(basic_string, op_gt_pointer_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_FALSE("" > TString{""});
  EXPECT_FALSE("" > TString{"abc"});
  EXPECT_FALSE("" > TString{"123456789012345679081324657890"});

  EXPECT_TRUE("abc" > TString{""});
  EXPECT_FALSE("abc" > TString{"abc"});
  EXPECT_FALSE("123" > TString{"123456789012345679081324657890"});

  EXPECT_TRUE("123456789012345679081324657890" > TString{""});
  EXPECT_TRUE("123456789012345679081324657890" > TString{"123"});
  EXPECT_FALSE("123456789012345679081324657890" > TString{"123456789012345679081324657890"});
}

TEST(basic_string, op_gt_string_pointer) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_FALSE(TString{""} > "");
  EXPECT_FALSE(TString{""} > "abc");
  EXPECT_FALSE(TString{""} > "123456789012345679081324657890");

  EXPECT_TRUE(TString{"abc"} > "");
  EXPECT_FALSE(TString{"abc"} > "abc");
  EXPECT_FALSE(TString{"123"} > "123456789012345679081324657890");

  EXPECT_TRUE(TString{"123456789012345679081324657890"} > "");
  EXPECT_TRUE(TString{"123456789012345679081324657890"} > "123");
  EXPECT_FALSE(TString{"123456789012345679081324657890"} > "123456789012345679081324657890");
}

TEST(basic_string, op_gt_string_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_FALSE(TString{""} > TString{""});
  EXPECT_FALSE(TString{""} > TString{"abc"});
  EXPECT_FALSE(TString{""} > TString{"123456789012345679081324657890"});

  EXPECT_TRUE(TString{"abc"} > TString{""});
  EXPECT_FALSE(TString{"abc"} > TString{"abc"});
  EXPECT_FALSE(TString{"123"} > TString{"123456789012345679081324657890"});

  EXPECT_TRUE(TString{"123456789012345679081324657890"} > TString{""});
  EXPECT_TRUE(TString{"123456789012345679081324657890"} > TString{"123"});
  EXPECT_FALSE(TString{"123456789012345679081324657890"} > TString{"123456789012345679081324657890"});
}

TEST(basic_string, op_gt_string_view_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_FALSE(TStringView{""} > TString{""});
  EXPECT_FALSE(TStringView{""} > TString{"abc"});
  EXPECT_FALSE(TStringView{""} > TString{"123456789012345679081324657890"});

  EXPECT_TRUE(TStringView{"abc"} > TString{""});
  EXPECT_FALSE(TStringView{"abc"} > TString{"abc"});

  EXPECT_FALSE(TStringView{"123456789012345679081324657890"} > TString{"123456789012345679081324657890"});
}

TEST(basic_string, op_gt_string_string_view) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_FALSE(TString{""} > TStringView{""});
  EXPECT_FALSE(TString{""} > TStringView{"abc"});
  EXPECT_FALSE(TString{""} > TStringView{"123456789012345679081324657890"});

  EXPECT_TRUE(TString{"abc"} > TStringView{""});
  EXPECT_FALSE(TString{"abc"} > TStringView{"abc"});
  EXPECT_FALSE(TString{"123"} > TStringView{"123456789012345679081324657890"});

  EXPECT_TRUE(TString{"123456789012345679081324657890"} > TStringView{""});
  EXPECT_TRUE(TString{"123456789012345679081324657890"} > TStringView{"123"});
  EXPECT_FALSE(TString{"123456789012345679081324657890"} > TStringView{"123456789012345679081324657890"});
}

TEST(basic_string, op_ge_pointer_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_TRUE("" >= TString{""});
  EXPECT_FALSE("" >= TString{"abc"});
  EXPECT_FALSE("" >= TString{"123456789012345679081324657890"});

  EXPECT_TRUE("abc" >= TString{""});
  EXPECT_TRUE("abc" >= TString{"abc"});
  EXPECT_FALSE("123" >= TString{"123456789012345679081324657890"});

  EXPECT_TRUE("123456789012345679081324657890" >= TString{""});
  EXPECT_TRUE("123456789012345679081324657890" >= TString{"123"});
  EXPECT_TRUE("123456789012345679081324657890" >= TString{"123456789012345679081324657890"});
}

TEST(basic_string, op_ge_string_pointer) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_TRUE(TString{""} >= "");
  EXPECT_FALSE(TString{""} >= "abc");
  EXPECT_FALSE(TString{""} >= "123456789012345679081324657890");

  EXPECT_TRUE(TString{"abc"} >= "");
  EXPECT_TRUE(TString{"abc"} >= "abc");
  EXPECT_FALSE(TString{"123"} >= "123456789012345679081324657890");

  EXPECT_TRUE(TString{"123456789012345679081324657890"} >= "");
  EXPECT_TRUE(TString{"123456789012345679081324657890"} >= "123");
  EXPECT_TRUE(TString{"123456789012345679081324657890"} >= "123456789012345679081324657890");
}

TEST(basic_string, op_ge_string_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_TRUE(TString{""} >= TString{""});
  EXPECT_FALSE(TString{""} >= TString{"abc"});
  EXPECT_FALSE(TString{""} >= TString{"123456789012345679081324657890"});

  EXPECT_TRUE(TString{"abc"} >= TString{""});
  EXPECT_TRUE(TString{"abc"} >= TString{"abc"});
  EXPECT_FALSE(TString{"123"} >= TString{"123456789012345679081324657890"});

  EXPECT_TRUE(TString{"123456789012345679081324657890"} >= TString{""});
  EXPECT_TRUE(TString{"123456789012345679081324657890"} >= TString{"123"});
  EXPECT_TRUE(TString{"123456789012345679081324657890"} >= TString{"123456789012345679081324657890"});
}

TEST(basic_string, op_ge_string_view_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_TRUE(TStringView{""} >= TString{""});
  EXPECT_FALSE(TStringView{""} >= TString{"abc"});
  EXPECT_FALSE(TStringView{""} >= TString{"123456789012345679081324657890"});

  EXPECT_TRUE(TStringView{"abc"} >= TString{""});
  EXPECT_TRUE(TStringView{"abc"} >= TString{"abc"});
  EXPECT_FALSE(TStringView{"123"} >= TString{"123456789012345679081324657890"});

  EXPECT_TRUE(TStringView{"123456789012345679081324657890"} >= TString{""});
  EXPECT_TRUE(TStringView{"123456789012345679081324657890"} >= TString{"123"});
  EXPECT_TRUE(TStringView{"123456789012345679081324657890"} >= TString{"123456789012345679081324657890"});
}

TEST(basic_string, op_ge_string_string_view) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_TRUE(TString{""} >= TStringView{""});
  EXPECT_FALSE(TString{""} >= TStringView{"abc"});
  EXPECT_FALSE(TString{""} >= TStringView{"123456789012345679081324657890"});

  EXPECT_TRUE(TString{"abc"} >= TStringView{""});
  EXPECT_TRUE(TString{"abc"} >= TStringView{"abc"});
  EXPECT_FALSE(TString{"123"} >= TStringView{"123456789012345679081324657890"});

  EXPECT_TRUE(TString{"123456789012345679081324657890"} >= TStringView{""});
  EXPECT_TRUE(TString{"123456789012345679081324657890"} >= TStringView{"123"});
  EXPECT_TRUE(TString{"123456789012345679081324657890"} >= TStringView{"123456789012345679081324657890"});
}

TEST(basic_string, op_lt_pointer_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_FALSE("" < TString{""});
  EXPECT_TRUE("" < TString{"abc"});
  EXPECT_TRUE("" < TString{"123456789012345679081324657890"});

  EXPECT_FALSE("abc" < TString{""});
  EXPECT_FALSE("abc" < TString{"abc"});
  EXPECT_TRUE("123" < TString{"123456789012345679081324657890"});

  EXPECT_FALSE("123456789012345679081324657890" < TString{""});
  EXPECT_FALSE("123456789012345679081324657890" < TString{"123"});
  EXPECT_FALSE("123456789012345679081324657890" < TString{"123456789012345679081324657890"});
}

TEST(basic_string, op_lt_string_pointer) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_FALSE(TString{""} < "");
  EXPECT_TRUE(TString{""} < "abc");
  EXPECT_TRUE(TString{""} < "123456789012345679081324657890");

  EXPECT_FALSE(TString{"abc"} < "");
  EXPECT_FALSE(TString{"abc"} < "abc");
  EXPECT_TRUE(TString{"123"} < "123456789012345679081324657890");

  EXPECT_FALSE(TString{"123456789012345679081324657890"} < "");
  EXPECT_FALSE(TString{"123456789012345679081324657890"} < "123");
  EXPECT_FALSE(TString{"123456789012345679081324657890"} < "123456789012345679081324657890");
}

TEST(basic_string, op_lt_string_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_FALSE(TString{""} < TString{""});
  EXPECT_TRUE(TString{""} < TString{"abc"});
  EXPECT_TRUE(TString{""} < TString{"123456789012345679081324657890"});

  EXPECT_FALSE(TString{"abc"} < TString{""});
  EXPECT_FALSE(TString{"abc"} < TString{"abc"});
  EXPECT_TRUE(TString{"123"} < TString{"123456789012345679081324657890"});

  EXPECT_FALSE(TString{"123456789012345679081324657890"} < TString{""});
  EXPECT_FALSE(TString{"123456789012345679081324657890"} < TString{"123"});
  EXPECT_FALSE(TString{"123456789012345679081324657890"} < TString{"123456789012345679081324657890"});
}

TEST(basic_string, op_lt_string_view_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_FALSE(TStringView{""} < TString{""});
  EXPECT_TRUE(TStringView{""} < TString{"abc"});
  EXPECT_TRUE(TStringView{""} < TString{"123456789012345679081324657890"});

  EXPECT_FALSE(TStringView{"abc"} < TString{""});
  EXPECT_FALSE(TStringView{"abc"} < TString{"abc"});
  EXPECT_TRUE(TStringView{"123"} < TString{"123456789012345679081324657890"});

  EXPECT_FALSE(TStringView{"123456789012345679081324657890"} < TString{""});
  EXPECT_FALSE(TStringView{"123456789012345679081324657890"} < TString{"123"});
  EXPECT_FALSE(TStringView{"123456789012345679081324657890"} < TString{"123456789012345679081324657890"});
}

TEST(basic_string, op_lt_string_string_view) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_FALSE(TString{""} < TStringView{""});
  EXPECT_TRUE(TString{""} < TStringView{"abc"});
  EXPECT_TRUE(TString{""} < TStringView{"123456789012345679081324657890"});

  EXPECT_FALSE(TString{"abc"} < TStringView{""});
  EXPECT_FALSE(TString{"abc"} < TStringView{"abc"});
  EXPECT_TRUE(TString{"123"} < TStringView{"123456789012345679081324657890"});

  EXPECT_FALSE(TString{"123456789012345679081324657890"} < TStringView{""});
  EXPECT_FALSE(TString{"123456789012345679081324657890"} < TStringView{"123"});
  EXPECT_FALSE(TString{"123456789012345679081324657890"} < TStringView{"123456789012345679081324657890"});
}

TEST(basic_string, op_le_pointer_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_TRUE("" <= TString{""});
  EXPECT_TRUE("" <= TString{"abc"});
  EXPECT_TRUE("" <= TString{"123456789012345679081324657890"});

  EXPECT_FALSE("abc" <= TString{""});
  EXPECT_TRUE("abc" <= TString{"abc"});
  EXPECT_TRUE("123" <= TString{"123456789012345679081324657890"});

  EXPECT_FALSE("123456789012345679081324657890" <= TString{""});
  EXPECT_FALSE("123456789012345679081324657890" <= TString{"123"});
  EXPECT_TRUE("123456789012345679081324657890" <= TString{"123456789012345679081324657890"});
}

TEST(basic_string, op_le_string_pointer) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_TRUE(TString{""} <= "");
  EXPECT_TRUE(TString{""} <= "abc");
  EXPECT_TRUE(TString{""} <= "123456789012345679081324657890");

  EXPECT_FALSE(TString{"abc"} <= "");
  EXPECT_TRUE(TString{"abc"} <= "abc");
  EXPECT_TRUE(TString{"123"} <= "123456789012345679081324657890");

  EXPECT_FALSE(TString{"123456789012345679081324657890"} <= "");
  EXPECT_FALSE(TString{"123456789012345679081324657890"} <= "123");
  EXPECT_TRUE(TString{"123456789012345679081324657890"} <= "123456789012345679081324657890");
}

TEST(basic_string, op_le_string_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_TRUE(TString{""} <= TString{""});
  EXPECT_TRUE(TString{""} <= TString{"abc"});
  EXPECT_TRUE(TString{""} <= TString{"123456789012345679081324657890"});

  EXPECT_FALSE(TString{"abc"} <= TString{""});
  EXPECT_TRUE(TString{"abc"} <= TString{"abc"});
  EXPECT_TRUE(TString{"123"} <= TString{"123456789012345679081324657890"});

  EXPECT_FALSE(TString{"123456789012345679081324657890"} <= TString{""});
  EXPECT_FALSE(TString{"123456789012345679081324657890"} <= TString{"123"});
  EXPECT_TRUE(TString{"123456789012345679081324657890"} <= TString{"123456789012345679081324657890"});
}

TEST(basic_string, op_le_string_view_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_TRUE(TStringView{""} <= TString{""});
  EXPECT_TRUE(TStringView{""} <= TString{"abc"});
  EXPECT_TRUE(TStringView{""} <= TString{"123456789012345679081324657890"});

  EXPECT_FALSE(TStringView{"abc"} <= TString{""});
  EXPECT_TRUE(TStringView{"abc"} <= TString{"abc"});
  EXPECT_TRUE(TStringView{"123"} <= TString{"123456789012345679081324657890"});

  EXPECT_FALSE(TStringView{"123456789012345679081324657890"} <= TString{""});
  EXPECT_FALSE(TStringView{"123456789012345679081324657890"} <= TString{"123"});
  EXPECT_TRUE(TStringView{"123456789012345679081324657890"} <= TString{"123456789012345679081324657890"});
}

TEST(basic_string, op_le_string_string_view) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_TRUE(TString{""} <= TStringView{""});
  EXPECT_TRUE(TString{""} <= TStringView{"abc"});
  EXPECT_TRUE(TString{""} <= TStringView{"123456789012345679081324657890"});

  EXPECT_FALSE(TString{"abc"} <= TStringView{""});
  EXPECT_TRUE(TString{"abc"} <= TStringView{"abc"});
  EXPECT_TRUE(TString{"123"} <= TStringView{"123456789012345679081324657890"});

  EXPECT_FALSE(TString{"123456789012345679081324657890"} <= TStringView{""});
  EXPECT_FALSE(TString{"123456789012345679081324657890"} <= TStringView{"123"});
  EXPECT_TRUE(TString{"123456789012345679081324657890"} <= TStringView{"123456789012345679081324657890"});
}
