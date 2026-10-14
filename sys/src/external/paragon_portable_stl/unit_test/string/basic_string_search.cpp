// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="basic_string_search.cpp"
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

// [find]

TEST(basic_string, find_char_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(5, test_string_helper::s1.find('f', 3));
  EXPECT_EQ(19, test_string_helper::s2.find('0', 18));

  EXPECT_EQ(5, test_string_helper::s1.find('f'));
  EXPECT_EQ(9, test_string_helper::s2.find('0'));
}

TEST(basic_string, find_pointer_pos_count) {
  static_cast<void>(test_info_);

  EXPECT_EQ(3, test_string_helper::s1.find("de", 2, 2));
  EXPECT_EQ(33, test_string_helper::s2.find("456789", 28, 4));
}

TEST(basic_string, find_pointer_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(3, test_string_helper::s1.find("de", 2));
  EXPECT_EQ(33, test_string_helper::s2.find("456789", 28));

  EXPECT_EQ(3, test_string_helper::s1.find(TString("de")));
  EXPECT_EQ(3, test_string_helper::s2.find(TString("456789")));
}

TEST(basic_string, find_string_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(3, test_string_helper::s1.find(TString("de"), 2));
  EXPECT_EQ(33, test_string_helper::s2.find(TString("456789"), 28));

  EXPECT_EQ(3, test_string_helper::s1.find(TString("de")));
  EXPECT_EQ(3, test_string_helper::s2.find(TString("456789")));
}

TEST(basic_string, find_strin_view_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(3, test_string_helper::s1.find(TStringView("de"), 2));
  EXPECT_EQ(33, test_string_helper::s2.find(TStringView("456789"), 28));

  EXPECT_EQ(3, test_string_helper::s1.find(TStringView("de")));
  EXPECT_EQ(3, test_string_helper::s2.find(TStringView("456789")));
}

// [rfind]

TEST(basic_string, rfind_char_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(1, test_string_helper::s1.rfind('b', 4));
  EXPECT_EQ(14, test_string_helper::s2.rfind('5', 18));

  EXPECT_EQ(1, test_string_helper::s1.rfind('b'));
  EXPECT_EQ(44, test_string_helper::s2.rfind('5'));
}

TEST(basic_string, rfind_pointer_pos_count) {
  static_cast<void>(test_info_);

  EXPECT_EQ(3, test_string_helper::s1.rfind("de", 6, 2));
  EXPECT_EQ(23, test_string_helper::s2.rfind("456789", 28, 4));
}

TEST(basic_string, rfind_pointer_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(3, test_string_helper::s1.rfind("de", 6));
  EXPECT_EQ(23, test_string_helper::s2.rfind("456789", 28));

  EXPECT_EQ(3, test_string_helper::s1.rfind(TString("de")));
  EXPECT_EQ(43, test_string_helper::s2.rfind(TString("456789")));
}

TEST(basic_string, rfind_string_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(3, test_string_helper::s1.rfind(TString("de"), 6));
  EXPECT_EQ(23, test_string_helper::s2.rfind(TString("456789"), 28));

  EXPECT_EQ(3, test_string_helper::s1.rfind(TString("de")));
  EXPECT_EQ(43, test_string_helper::s2.rfind(TString("456789")));
}

TEST(basic_string, rfind_strin_view_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(3, test_string_helper::s1.rfind(TStringView("de"), 6));
  EXPECT_EQ(23, test_string_helper::s2.rfind(TStringView("456789"), 28));

  EXPECT_EQ(3, test_string_helper::s1.rfind(TStringView("de")));
  EXPECT_EQ(43, test_string_helper::s2.rfind(TStringView("456789")));
}

// [find_first_of]

TEST(basic_string, find_first_of_char_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(5, test_string_helper::s1.find_first_of('f', 3));
  EXPECT_EQ(19, test_string_helper::s2.find_first_of('0', 18));

  EXPECT_EQ(5, test_string_helper::s1.find_first_of('f'));
  EXPECT_EQ(9, test_string_helper::s2.find_first_of('0'));
}

TEST(basic_string, find_first_of_pointer_pos_count) {
  static_cast<void>(test_info_);

  EXPECT_EQ(3, test_string_helper::s1.find_first_of("de", 2, 2));
  EXPECT_EQ(33, test_string_helper::s2.find_first_of("456789", 28, 4));
}

TEST(basic_string, find_first_of_pointer_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(3, test_string_helper::s1.find_first_of("de", 2));
  EXPECT_EQ(28, test_string_helper::s2.find_first_of("456789", 28));

  EXPECT_EQ(3, test_string_helper::s1.find_first_of(TString("de")));
  EXPECT_EQ(3, test_string_helper::s2.find_first_of(TString("456789")));
}

TEST(basic_string, find_first_of_string_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(3, test_string_helper::s1.find_first_of(TString("de"), 2));
  EXPECT_EQ(28, test_string_helper::s2.find_first_of(TString("456789"), 28));

  EXPECT_EQ(3, test_string_helper::s1.find_first_of(TString("de")));
  EXPECT_EQ(3, test_string_helper::s2.find_first_of(TString("456789")));
}

TEST(basic_string, find_first_of_strin_view_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(3, test_string_helper::s1.find_first_of(TStringView("de"), 2));
  EXPECT_EQ(28, test_string_helper::s2.find_first_of(TStringView("456789"), 28));

  EXPECT_EQ(3, test_string_helper::s1.find_first_of(TStringView("de")));
  EXPECT_EQ(3, test_string_helper::s2.find_first_of(TStringView("456789")));
}

// [find_first_not_of]

TEST(basic_string, find_first_not_of_char_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(3, test_string_helper::s1.find_first_not_of('f', 3));
  EXPECT_EQ(18, test_string_helper::s2.find_first_not_of('8', 17));

  EXPECT_EQ(0, test_string_helper::s1.find_first_not_of('f'));
  EXPECT_EQ(0, test_string_helper::s2.find_first_not_of('0'));
}

TEST(basic_string, find_first_not_of_pointer_pos_count) {
  static_cast<void>(test_info_);

  EXPECT_EQ(2, test_string_helper::s1.find_first_not_of("de", 2, 2));
  EXPECT_EQ(28, test_string_helper::s2.find_first_not_of("456789", 28, 4));
}

TEST(basic_string, find_first_not_of_pointer_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(2, test_string_helper::s1.find_first_not_of("de", 2));
  EXPECT_EQ(29, test_string_helper::s2.find_first_not_of("456789", 28));

  EXPECT_EQ(0, test_string_helper::s1.find_first_not_of(TString("de")));
  EXPECT_EQ(0, test_string_helper::s2.find_first_not_of(TString("456789")));
}

TEST(basic_string, find_first_not_of_string_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(2, test_string_helper::s1.find_first_not_of(TString("de"), 2));
  EXPECT_EQ(29, test_string_helper::s2.find_first_not_of(TString("456789"), 28));

  EXPECT_EQ(2, test_string_helper::s1.find_first_not_of(TString("ab")));
  EXPECT_EQ(1, test_string_helper::s2.find_first_not_of(TString("1456789")));
}

TEST(basic_string, find_first_not_of_strin_view_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(2, test_string_helper::s1.find_first_not_of(TStringView("de"), 2));
  EXPECT_EQ(29, test_string_helper::s2.find_first_not_of(TStringView("456789"), 28));

  EXPECT_EQ(2, test_string_helper::s1.find_first_not_of(TStringView("ab")));
  EXPECT_EQ(1, test_string_helper::s2.find_first_not_of(TStringView("1456789")));
}

// [find_last_of]

TEST(basic_string, find_last_of_char_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(1, test_string_helper::s1.find_last_of('b', 3));
  EXPECT_EQ(7, test_string_helper::s2.find_last_of('8', 16));

  EXPECT_EQ(5, test_string_helper::s1.find_last_of('f'));
  EXPECT_EQ(44, test_string_helper::s2.find_last_of('5'));
}

TEST(basic_string, find_last_of_pointer_pos_count) {
  static_cast<void>(test_info_);

  EXPECT_EQ(4, test_string_helper::s1.find_last_of("de", 6, 2));
  EXPECT_EQ(26, test_string_helper::s2.find_last_of("456789", 28, 4));
}

TEST(basic_string, find_last_of_pointer_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(4, test_string_helper::s1.find_last_of("de", 6));
  EXPECT_EQ(18, test_string_helper::s2.find_last_of("456789", 22));

  EXPECT_EQ(4, test_string_helper::s1.find_last_of(TString("de")));
  EXPECT_EQ(48, test_string_helper::s2.find_last_of(TString("456789")));
}

TEST(basic_string, find_last_of_string_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(4, test_string_helper::s1.find_last_of(TString("de"), 6));
  EXPECT_EQ(18, test_string_helper::s2.find_last_of(TString("456789"), 22));

  EXPECT_EQ(1, test_string_helper::s1.find_last_of(TString("ab")));
  EXPECT_EQ(48, test_string_helper::s2.find_last_of(TString("1456789")));
}

TEST(basic_string, find_last_of_strin_view_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(4, test_string_helper::s1.find_last_of(TStringView("de"), 6));
  EXPECT_EQ(18, test_string_helper::s2.find_last_of(TStringView("456789"), 22));

  EXPECT_EQ(1, test_string_helper::s1.find_last_of(TStringView("ab")));
  EXPECT_EQ(48, test_string_helper::s2.find_last_of(TStringView("1456789")));
}

// [find_last_not_of]

TEST(basic_string, find_last_not_of_char_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(3, test_string_helper::s1.find_last_not_of('b', 3));
  EXPECT_EQ(16, test_string_helper::s2.find_last_not_of('8', 16));

  EXPECT_EQ(4, test_string_helper::s1.find_last_not_of('f'));
  EXPECT_EQ(49, test_string_helper::s2.find_last_not_of('5'));
}

TEST(basic_string, find_last_not_of_pointer_pos_count) {
  static_cast<void>(test_info_);

  EXPECT_EQ(5, test_string_helper::s1.find_last_not_of("de", 6, 2));
  EXPECT_EQ(28, test_string_helper::s2.find_last_not_of("456789", 28, 4));
}

TEST(basic_string, find_last_not_of_pointer_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(5, test_string_helper::s1.find_last_not_of("de", 6));
  EXPECT_EQ(22, test_string_helper::s2.find_last_not_of("456789", 28));

  EXPECT_EQ(5, test_string_helper::s1.find_last_not_of(TString("de")));
  EXPECT_EQ(42, test_string_helper::s2.find_last_not_of(TString("4567890")));
}

TEST(basic_string, find_last_not_of_string_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(5, test_string_helper::s1.find_last_not_of(TString("de"), 6));
  EXPECT_EQ(22, test_string_helper::s2.find_last_not_of(TString("456789"), 28));

  EXPECT_EQ(4, test_string_helper::s1.find_last_not_of(TString("abf")));
  EXPECT_EQ(42, test_string_helper::s2.find_last_not_of(TString("14567890")));
}

TEST(basic_string, find_last_not_of_strin_view_pos) {
  static_cast<void>(test_info_);

  EXPECT_EQ(5, test_string_helper::s1.find_last_not_of(TStringView("de"), 6));
  EXPECT_EQ(22, test_string_helper::s2.find_last_not_of(TStringView("456789"), 28));

  EXPECT_EQ(4, test_string_helper::s1.find_last_not_of(TStringView("abf")));
  EXPECT_EQ(42, test_string_helper::s2.find_last_not_of(TStringView("14567890")));
}

// [starts_with]

TEST(basic_string, starts_with_char) {
  static_cast<void>(test_info_);

  EXPECT_TRUE(test_string_helper::s1.starts_with('a'));
  EXPECT_FALSE(test_string_helper::s1.starts_with('b'));

  EXPECT_TRUE(test_string_helper::s2.starts_with('1'));
  EXPECT_FALSE(test_string_helper::s2.starts_with('2'));
}

TEST(basic_string, starts_with_pointer) {
  static_cast<void>(test_info_);

  EXPECT_TRUE(test_string_helper::s1.starts_with("abc"));
  EXPECT_FALSE(test_string_helper::s1.starts_with("acd"));

  EXPECT_TRUE(test_string_helper::s2.starts_with("12345678901"));
  EXPECT_FALSE(test_string_helper::s2.starts_with("123456_78901"));
}

TEST(basic_string, starts_with_string_view) {
  static_cast<void>(test_info_);

  EXPECT_TRUE(test_string_helper::s1.starts_with(TStringView("abc")));
  EXPECT_FALSE(test_string_helper::s1.starts_with(TStringView("acd")));

  EXPECT_TRUE(test_string_helper::s2.starts_with(TStringView("12345678901")));
  EXPECT_FALSE(test_string_helper::s2.starts_with(TStringView("123456_78901")));
}

// [ends_with]

TEST(basic_string, ends_with_char) {
  static_cast<void>(test_info_);

  EXPECT_TRUE(test_string_helper::s1.ends_with('f'));
  EXPECT_FALSE(test_string_helper::s1.ends_with('g'));

  EXPECT_TRUE(test_string_helper::s2.ends_with('0'));
  EXPECT_FALSE(test_string_helper::s2.ends_with('9'));
}

TEST(basic_string, ends_with_pointer) {
  static_cast<void>(test_info_);

  EXPECT_TRUE(test_string_helper::s1.ends_with("def"));
  EXPECT_FALSE(test_string_helper::s1.ends_with("daf"));

  EXPECT_TRUE(test_string_helper::s2.ends_with("1234567890"));
  EXPECT_FALSE(test_string_helper::s2.ends_with("12345_67890"));
}

TEST(basic_string, ends_with_string_view) {
  static_cast<void>(test_info_);

  EXPECT_TRUE(test_string_helper::s1.ends_with(TStringView("def")));
  EXPECT_FALSE(test_string_helper::s1.ends_with(TStringView("daf")));

  EXPECT_TRUE(test_string_helper::s2.ends_with(TStringView("1234567890")));
  EXPECT_FALSE(test_string_helper::s2.ends_with(TStringView("12345_67890")));
}

// [contains]

TEST(basic_string, contains_char) {
  static_cast<void>(test_info_);

  EXPECT_TRUE(test_string_helper::s1.contains('c'));
  EXPECT_FALSE(test_string_helper::s1.contains('g'));

  EXPECT_TRUE(test_string_helper::s2.contains('5'));
  EXPECT_FALSE(test_string_helper::s2.contains('g'));
}

TEST(basic_string, contains_pointer) {
  static_cast<void>(test_info_);

  EXPECT_TRUE(test_string_helper::s1.contains("cde"));
  EXPECT_FALSE(test_string_helper::s1.contains("cge"));

  EXPECT_TRUE(test_string_helper::s2.contains("4567890123"));
  EXPECT_FALSE(test_string_helper::s2.contains("45678_90123"));
}

TEST(basic_string, contains_string_view) {
  static_cast<void>(test_info_);

  EXPECT_TRUE(test_string_helper::s1.contains(TStringView("cde")));
  EXPECT_FALSE(test_string_helper::s1.contains(TStringView("cge")));

  EXPECT_TRUE(test_string_helper::s2.contains(TStringView("4567890123")));
  EXPECT_FALSE(test_string_helper::s2.contains(TStringView("45678_90123")));
}

// [compare]

TEST(basic_string, compare_pointer) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_EQ(-1, test_string_helper::s1.compare("abddef"));
  EXPECT_EQ(0, test_string_helper::s1.compare("abcdef"));
  EXPECT_EQ(+1, test_string_helper::s1.compare("abbdef"));

  EXPECT_EQ(-1, test_string_helper::s2.compare("12345678901234567890123456789012345678901234567891"));
  EXPECT_EQ(0, test_string_helper::s2.compare("12345678901234567890123456789012345678901234567890"));
  EXPECT_EQ(+1, test_string_helper::s2.compare("12345678901234567890123456789012345678901234567880"));
}

TEST(basic_string, compare_string_view) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_EQ(-1, test_string_helper::s1.compare(TStringView("abddef")));
  EXPECT_EQ(0, test_string_helper::s1.compare(TStringView("abcdef")));
  EXPECT_EQ(+1, test_string_helper::s1.compare(TStringView("abbdef")));

  EXPECT_EQ(-1, test_string_helper::s2.compare(TStringView("12345678901234567890123456789012345678901234567891")));
  EXPECT_EQ(0, test_string_helper::s2.compare(TStringView("12345678901234567890123456789012345678901234567890")));
  EXPECT_EQ(+1, test_string_helper::s2.compare(TStringView("12345678901234567890123456789012345678901234567880")));
}

TEST(basic_string, compare_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_EQ(-1, test_string_helper::s1.compare(TString("abddef")));
  EXPECT_EQ(-1, test_string_helper::s1.compare(TString("abcdef\0\0\0", 9)));
  EXPECT_EQ(0, test_string_helper::s1.compare(TString("abcdef")));
  EXPECT_EQ(+1, test_string_helper::s1.compare(TString("abbdef")));

  EXPECT_EQ(-1, test_string_helper::s2.compare(TString("12345678901234567890123456789012345678901234567891")));
  EXPECT_EQ(0, test_string_helper::s2.compare(TString("12345678901234567890123456789012345678901234567890")));
  EXPECT_EQ(+1, test_string_helper::s2.compare(TString("12345678901234567890123456789012345678901234567880")));
}

TEST(basic_string, compare_pos_count_pointer) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    auto result = test_string_helper::s1.compare(0, 6, "abddef");
    ASSERT_TRUE(result);
    EXPECT_EQ(-1, result.value());
  }
  {
    auto result = test_string_helper::s1.compare(0, 6, "abcdef");
    ASSERT_TRUE(result);
    EXPECT_EQ(0, result.value());
  }
  {
    auto result = test_string_helper::s1.compare(0, 6, "abbdef");
    ASSERT_TRUE(result);
    EXPECT_EQ(+1, result.value());
  }
  {
    auto result = test_string_helper::s1.compare(7, 6, "abddef");
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = test_string_helper::s1.compare(7, 6, "abcdef");
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = test_string_helper::s1.compare(7, 6, "abbdef");
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }

  {
    auto result = test_string_helper::s2.compare(0, 50, "12345678901234567890123456789012345678901234567891");
    ASSERT_TRUE(result);
    EXPECT_EQ(-1, result.value());
  }
  {
    auto result = test_string_helper::s2.compare(0, 50, "12345678901234567890123456789012345678901234567890");
    ASSERT_TRUE(result);
    EXPECT_EQ(0, result.value());
  }
  {
    auto result = test_string_helper::s2.compare(0, 50, "12345678901234567890123456789012345678901234567880");
    ASSERT_TRUE(result);
    EXPECT_EQ(+1, result.value());
  }
  {
    auto result = test_string_helper::s2.compare(51, 50, "12345678901234567890123456789012345678901234567891");
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = test_string_helper::s2.compare(51, 50, "12345678901234567890123456789012345678901234567890");
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = test_string_helper::s2.compare(51, 50, "12345678901234567890123456789012345678901234567880");
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
}

TEST(basic_string, compare_pos_count_pointer_pos_count) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    auto result = test_string_helper::s1.compare(0, 6, "abddef", 6);
    ASSERT_TRUE(result);
    EXPECT_EQ(-1, result.value());
  }
  {
    auto result = test_string_helper::s1.compare(0, 6, "abcdef", 6);
    ASSERT_TRUE(result);
    EXPECT_EQ(0, result.value());
  }
  {
    auto result = test_string_helper::s1.compare(0, 6, "abbdef", 6);
    ASSERT_TRUE(result);
    EXPECT_EQ(+1, result.value());
  }
  {
    auto result = test_string_helper::s1.compare(7, 6, "abddef", 6);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = test_string_helper::s1.compare(7, 6, "abcdef", 6);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = test_string_helper::s1.compare(7, 6, "abbdef", 6);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = test_string_helper::s2.compare(0, 50, "12345678901234567890123456789012345678901234567891", 50);
    ASSERT_TRUE(result);
    EXPECT_EQ(-1, result.value());
  }
  {
    auto result = test_string_helper::s2.compare(0, 50, "12345678901234567890123456789012345678901234567890", 50);
    ASSERT_TRUE(result);
    EXPECT_EQ(0, result.value());
  }
  {
    auto result = test_string_helper::s2.compare(0, 50, "12345678901234567890123456789012345678901234567880", 50);
    ASSERT_TRUE(result);
    EXPECT_EQ(+1, result.value());
  }
  {
    auto result = test_string_helper::s2.compare(51, 50, "12345678901234567890123456789012345678901234567891", 50);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = test_string_helper::s2.compare(51, 50, "12345678901234567890123456789012345678901234567890", 50);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = test_string_helper::s2.compare(51, 50, "12345678901234567890123456789012345678901234567880", 50);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
}

TEST(basic_string, compare_pos_count_string_view) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    auto result = test_string_helper::s1.compare(0, 6, TStringView("abddef"));
    ASSERT_TRUE(result);
    EXPECT_EQ(-1, result.value());
  }
  {
    auto result = test_string_helper::s1.compare(0, 6, TStringView("abcdef"));
    ASSERT_TRUE(result);
    EXPECT_EQ(0, result.value());
  }
  {
    auto result = test_string_helper::s1.compare(0, 6, TStringView("abbdef"));
    ASSERT_TRUE(result);
    EXPECT_EQ(+1, result.value());
  }
  {
    auto result = test_string_helper::s1.compare(7, 6, TStringView("abddef"));
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = test_string_helper::s1.compare(7, 6, TStringView("abcdef"));
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = test_string_helper::s1.compare(7, 6, TStringView("abbdef"));
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }

  {
    auto result
      = test_string_helper::s2.compare(0, 50, TStringView("12345678901234567890123456789012345678901234567891"));
    ASSERT_TRUE(result);
    EXPECT_EQ(-1, result.value());
  }
  {
    auto result
      = test_string_helper::s2.compare(0, 50, TStringView("12345678901234567890123456789012345678901234567890"));
    ASSERT_TRUE(result);
    EXPECT_EQ(0, result.value());
  }
  {
    auto result
      = test_string_helper::s2.compare(0, 50, TStringView("12345678901234567890123456789012345678901234567880"));
    ASSERT_TRUE(result);
    EXPECT_EQ(+1, result.value());
  }
  {
    auto result
      = test_string_helper::s2.compare(51, 50, TStringView("12345678901234567890123456789012345678901234567891"));
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result
      = test_string_helper::s2.compare(51, 50, TStringView("12345678901234567890123456789012345678901234567890"));
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result
      = test_string_helper::s2.compare(51, 50, TStringView("12345678901234567890123456789012345678901234567880"));
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
}

TEST(basic_string, compare_pos_count_string_view_pos_count) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    auto result = test_string_helper::s1.compare(0, 6, TStringView("abddef"), 0, 6);
    ASSERT_TRUE(result);
    EXPECT_EQ(-1, result.value());
  }
  {
    auto result = test_string_helper::s1.compare(0, 6, TStringView("abcdef"), 0, 6);
    ASSERT_TRUE(result);
    EXPECT_EQ(0, result.value());
  }
  {
    auto result = test_string_helper::s1.compare(0, 6, TStringView("abbdef"), 0, 6);
    ASSERT_TRUE(result);
    EXPECT_EQ(+1, result.value());
  }
  {
    auto result = test_string_helper::s1.compare(7, 6, TStringView("abddef"), 0, 6);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = test_string_helper::s1.compare(7, 6, TStringView("abcdef"), 0, 6);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = test_string_helper::s1.compare(7, 6, TStringView("abbdef"), 0, 6);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result
      = test_string_helper::s2.compare(0, 50, TStringView("12345678901234567890123456789012345678901234567891"), 0, 50);
    ASSERT_TRUE(result);
    EXPECT_EQ(-1, result.value());
  }
  {
    auto result
      = test_string_helper::s2.compare(0, 50, TStringView("12345678901234567890123456789012345678901234567890"), 0, 50);
    ASSERT_TRUE(result);
    EXPECT_EQ(0, result.value());
  }
  {
    auto result
      = test_string_helper::s2.compare(0, 50, TStringView("12345678901234567890123456789012345678901234567880"), 0, 50);
    ASSERT_TRUE(result);
    EXPECT_EQ(+1, result.value());
  }
  {
    auto result = test_string_helper::s2.compare(
      51, 50, TStringView("12345678901234567890123456789012345678901234567891"), 51, 50);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = test_string_helper::s2.compare(
      51, 50, TStringView("12345678901234567890123456789012345678901234567890"), 51, 50);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = test_string_helper::s2.compare(
      51, 50, TStringView("12345678901234567890123456789012345678901234567880"), 51, 50);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
}

TEST(basic_string, compare_pos_count_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    auto result = test_string_helper::s1.compare(0, 6, TString("abddef"));
    ASSERT_TRUE(result);
    EXPECT_EQ(-1, result.value());
  }
  {
    auto result = test_string_helper::s1.compare(0, 6, TString("abcdef"));
    ASSERT_TRUE(result);
    EXPECT_EQ(0, result.value());
  }
  {
    auto result = test_string_helper::s1.compare(0, 6, TString("abbdef"));
    ASSERT_TRUE(result);
    EXPECT_EQ(+1, result.value());
  }
  {
    auto result = test_string_helper::s1.compare(7, 6, TString("abddef"));
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = test_string_helper::s1.compare(7, 6, TString("abcdef"));
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = test_string_helper::s1.compare(7, 6, TString("abbdef"));
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }

  {
    auto result = test_string_helper::s2.compare(0, 50, TString("12345678901234567890123456789012345678901234567891"));
    ASSERT_TRUE(result);
    EXPECT_EQ(-1, result.value());
  }
  {
    auto result = test_string_helper::s2.compare(0, 50, TString("12345678901234567890123456789012345678901234567890"));
    ASSERT_TRUE(result);
    EXPECT_EQ(0, result.value());
  }
  {
    auto result = test_string_helper::s2.compare(0, 50, TString("12345678901234567890123456789012345678901234567880"));
    ASSERT_TRUE(result);
    EXPECT_EQ(+1, result.value());
  }
  {
    auto result = test_string_helper::s2.compare(51, 50, TString("12345678901234567890123456789012345678901234567891"));
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = test_string_helper::s2.compare(51, 50, TString("12345678901234567890123456789012345678901234567890"));
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = test_string_helper::s2.compare(51, 50, TString("12345678901234567890123456789012345678901234567880"));
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
}

TEST(basic_string, compare_pos_count_string_pos_count) {
  static_cast<void>(test_info_);

  {
    auto result = test_string_helper::s1.compare(0, 6, TString("abddef"), 0, 6);
    ASSERT_TRUE(result);
    EXPECT_EQ(-1, result.value());
  }
  {
    auto result = test_string_helper::s1.compare(0, 6, TString("abcdef"), 0, 6);
    ASSERT_TRUE(result);
    EXPECT_EQ(0, result.value());
  }
  {
    auto result = test_string_helper::s1.compare(0, 6, TString("abbdef"), 0, 6);
    ASSERT_TRUE(result);
    EXPECT_EQ(+1, result.value());
  }
  {
    auto result = test_string_helper::s1.compare(7, 6, TString("abddef"), 0, 6);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = test_string_helper::s1.compare(7, 6, TString("abcdef"), 0, 6);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = test_string_helper::s1.compare(7, 6, TString("abbdef"), 0, 6);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result
      = test_string_helper::s2.compare(0, 50, TString("12345678901234567890123456789012345678901234567891"), 0, 50);
    ASSERT_TRUE(result);
    EXPECT_EQ(-1, result.value());
  }
  {
    auto result
      = test_string_helper::s2.compare(0, 50, TString("12345678901234567890123456789012345678901234567890"), 0, 50);
    ASSERT_TRUE(result);
    EXPECT_EQ(0, result.value());
  }
  {
    auto result
      = test_string_helper::s2.compare(0, 50, TString("12345678901234567890123456789012345678901234567880"), 0, 50);
    ASSERT_TRUE(result);
    EXPECT_EQ(+1, result.value());
  }
  {
    auto result
      = test_string_helper::s2.compare(51, 50, TString("12345678901234567890123456789012345678901234567891"), 51, 50);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result
      = test_string_helper::s2.compare(51, 50, TString("12345678901234567890123456789012345678901234567890"), 51, 50);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result
      = test_string_helper::s2.compare(51, 50, TString("12345678901234567890123456789012345678901234567880"), 51, 50);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
}
