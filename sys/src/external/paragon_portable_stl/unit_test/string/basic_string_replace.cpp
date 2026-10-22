// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="basic_string_replace.cpp"
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

namespace test_string_replace_helper {
static void replace_pos_count_string_view(
  TString str, std::size_t pos, std::size_t count, TStringView sv, TString expected, bool set_bad_alloc) {
  TMManager::m_counter_ok_allocation = 100;
  ASSERT_EQ(0, str.check_invariants());
  TString    s0{str}; // before replacement;
  TMManager::m_counter_ok_allocation = (set_bad_alloc ? 0 : 100);

  auto result = str.replace(pos, count, sv);

  EXPECT_EQ(0, str.check_invariants());
  if (result) {
    EXPECT_EQ(expected, str) << str.size();
  } else {
    EXPECT_EQ(s0, str) << str.size();
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }

  TMManager::m_counter_ok_allocation = 100;
}

} // namespace test_string_replace_helper

// [replace]

// (12)
TEST(basic_string, replace_pos_count_string_view) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  // clang-format off

  // no allocation
  {
    test_string_replace_helper::replace_pos_count_string_view(TString(""), 0, 0, TStringView(""), TString(""), true);
    test_string_replace_helper::replace_pos_count_string_view(TString(""), 0, 1, TStringView(""), TString(""), true);
    test_string_replace_helper::replace_pos_count_string_view(TString(""), 0, 10, TStringView(""), TString(""), true);
  }

  // inside SSO size (10 symbols + '\0')
  {
    TMManager::m_counter_ok_allocation = 100;

    test_string_replace_helper::replace_pos_count_string_view(TString(""), 0, 0, TStringView("1234567890"), TString("1234567890"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 0, 0, TStringView(""), TString("1234567890"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 0, 10, TStringView(""), TString(""), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 0, 20, TStringView(""), TString(""), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 1, 20, TStringView(""), TString("1"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 2, 20, TStringView(""), TString("12"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 9, 20, TStringView(""), TString("123456789"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 10, 20, TStringView(""), TString("1234567890"), true);
  }

  // inside SSO size (22 symbols + '\0')
  {
    TMManager::m_counter_ok_allocation = 100;

    test_string_replace_helper::replace_pos_count_string_view(TString(""), 0, 0, TStringView("1234567890123456789012"), TString("1234567890123456789012"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 0, 0, TStringView(""), TString("1234567890123456789012"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 0, 22, TStringView(""), TString(""), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 0, 50, TStringView(""), TString(""), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 1, 50, TStringView(""), TString("1"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 2, 50, TStringView(""), TString("12"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 9, 50, TStringView(""), TString("123456789"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 10, 50, TStringView(""), TString("1234567890"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 21, 50, TStringView(""), TString("123456789012345678901"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 22, 50, TStringView(""), TString("1234567890123456789012"), true);
  }

  // long->long no reallocation
  {
    TMManager::m_counter_ok_allocation = 100;
    test_string_replace_helper::replace_pos_count_string_view(TString("123456789012345678901234567890abcdefghijk"), 30, 50, TStringView(""), TString("123456789012345678901234567890"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("123456789012345678901234567890abcdefghijk"), 30, 50, TStringView(""), TString("123456789012345678901234567890"), false);
  }

  // long->SSO or long->long
  {
    TMManager::m_counter_ok_allocation = 100;
    test_string_replace_helper::replace_pos_count_string_view(TString("123456789012345678901234567890abcdefghijk"), 10, 50, TStringView(""), TString("1234567890"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("123456789012345678901234567890abcdefghijk"), 10, 50, TStringView(""), TString("1234567890"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("123456789012345678901234567890abcdefghijk"), 22, 50, TStringView(""), TString("1234567890123456789012"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("123456789012345678901234567890abcdefghijk"), 22, 50, TStringView(""), TString("1234567890123456789012"), false);
  }

  // SSO -> long
  {
    TMManager::m_counter_ok_allocation = 100;
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 0, 0, TStringView("abc"), TString("abc1234567890"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 0, 1, TStringView("abc"), TString("abc234567890"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 0, 2, TStringView("abc"), TString("abc34567890"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 0, 3, TStringView("abc"), TString("abc4567890"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 0, 0, TStringView("abc"), TString("abc1234567890"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 0, 1, TStringView("abc"), TString("abc234567890"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 0, 2, TStringView("abc"), TString("abc34567890"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 0, 3, TStringView("abc"), TString("abc4567890"), false);

    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 5, 0, TStringView("abc"), TString("12345abc67890"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 5, 1, TStringView("abc"), TString("12345abc7890"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 5, 2, TStringView("abc"), TString("12345abc890"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 5, 3, TStringView("abc"), TString("12345abc90"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 5, 0, TStringView("abc"), TString("12345abc67890"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 5, 1, TStringView("abc"), TString("12345abc7890"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 5, 2, TStringView("abc"), TString("12345abc890"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 5, 3, TStringView("abc"), TString("12345abc90"), false);

    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 8, 0, TStringView("abc"), TString("12345678abc90"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 8, 1, TStringView("abc"), TString("12345678abc0"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 8, 2, TStringView("abc"), TString("12345678abc"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 8, 3, TStringView("abc"), TString("12345678abc"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 8, 0, TStringView("abc"), TString("12345678abc90"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 8, 1, TStringView("abc"), TString("12345678abc0"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 8, 2, TStringView("abc"), TString("12345678abc"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890"), 8, 3, TStringView("abc"), TString("12345678abc"), false);

    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 0, 0, TStringView("abc"), TString("abc1234567890123456789012"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 0, 1, TStringView("abc"), TString("abc234567890123456789012"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 0, 2, TStringView("abc"), TString("abc34567890123456789012"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 0, 3, TStringView("abc"), TString("abc4567890123456789012"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 0, 0, TStringView("abc"), TString("abc1234567890123456789012"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 0, 1, TStringView("abc"), TString("abc234567890123456789012"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 0, 2, TStringView("abc"), TString("abc34567890123456789012"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 0, 3, TStringView("abc"), TString("abc4567890123456789012"), false);

    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 12, 0, TStringView("abc"), TString("123456789012abc3456789012"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 12, 1, TStringView("abc"), TString("123456789012abc456789012"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 12, 2, TStringView("abc"), TString("123456789012abc56789012"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 12, 3, TStringView("abc"), TString("123456789012abc6789012"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 12, 0, TStringView("abc"), TString("123456789012abc3456789012"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 12, 1, TStringView("abc"), TString("123456789012abc456789012"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 12, 2, TStringView("abc"), TString("123456789012abc56789012"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 12, 3, TStringView("abc"), TString("123456789012abc6789012"), false);

    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 20, 0, TStringView("abc"), TString("12345678901234567890abc12"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 20, 1, TStringView("abc"), TString("12345678901234567890abc2"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 20, 2, TStringView("abc"), TString("12345678901234567890abc"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 20, 3, TStringView("abc"), TString("12345678901234567890abc"), true);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 20, 0, TStringView("abc"), TString("12345678901234567890abc12"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 20, 1, TStringView("abc"), TString("12345678901234567890abc2"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 20, 2, TStringView("abc"), TString("12345678901234567890abc"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("1234567890123456789012"), 20, 3, TStringView("abc"), TString("12345678901234567890abc"), false);
  }
  // long
  {
    TMManager::m_counter_ok_allocation = 100;
    test_string_replace_helper::replace_pos_count_string_view(TString("123456789012345678901234567890"), 0, 1, TStringView("abc"), TString("abc23456789012345678901234567890"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("123456789012345678901234567890"), 5, 2, TStringView("abc"), TString("12345abc89012345678901234567890"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("123456789012345678901234567890"), 10, 3, TStringView("abc"), TString("1234567890abc45678901234567890"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("123456789012345678901234567890"), 28, 0, TStringView("abc"), TString("1234567890123456789012345678abc90"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("123456789012345678901234567890"), 28, 1, TStringView("abc"), TString("1234567890123456789012345678abc0"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("123456789012345678901234567890"), 28, 2, TStringView("abc"), TString("1234567890123456789012345678abc"), false);
    test_string_replace_helper::replace_pos_count_string_view(TString("123456789012345678901234567890"), 28, 3, TStringView("abc"), TString("1234567890123456789012345678abc"), false);
  }
  // clang-format on

  // out of range
  {
    TString s{"123465789"};

    auto result = s.replace(100, 1, TStringView("abc"));

    ASSERT_FALSE(result);
    EXPECT_EQ(0, s.check_invariants());
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
    EXPECT_EQ(TString{"123465789"}, s);
  }
}

// (1)
TEST(basic_string, replace_pos_count_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  TString s{"1234567890"};

  auto result = s.replace(3, 4, TString{"aaaaaaaaaaaaaaaaaaaa"});

  ASSERT_TRUE(result);
  ASSERT_EQ(0, s.check_invariants());
  EXPECT_EQ(TString{"123aaaaaaaaaaaaaaaaaaaa890"}, s);
}

// (2)
TEST(basic_string, replace_iter_iter_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  TString s{"1234567890"};

  auto result = s.replace(s.begin() + 3, s.begin() + 7, TString{"aaaaaaaaaaaaaaaaaaaa"});

  ASSERT_TRUE(result);
  ASSERT_EQ(0, s.check_invariants());
  EXPECT_EQ(TString{"123aaaaaaaaaaaaaaaaaaaa890"}, s);
}

// (3)
TEST(basic_string, replace_pos_count_string_pos2_count2) {
  static_cast<void>(test_info_);
  {
    TMManager::m_counter_ok_allocation = 100;

    TString s{"1234567890"};

    auto result = s.replace(3, 4, TString{"bbbbbbbbbbaaaaaaaaaaaaaaaaaaaa"}, 10, 100);

    ASSERT_TRUE(result);
    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(TString{"123aaaaaaaaaaaaaaaaaaaa890"}, s);
  }
  {
    TMManager::m_counter_ok_allocation = 100;

    TString s{"1234567890"};

    auto result = s.replace(3, 4, TString{"bbbbbbbbbbaaaaaaaaaaaaaaaaaaaa"}, 100, 10);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(TString{"1234567890"}, s);
  }
}

// (4)
TEST(basic_string, replace_pos_count_cstring_count2) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  TString s{"1234567890"};

  auto result = s.replace(3, 4, "aaaaaaaaaaaaaaaaaaaabbbbbbbbbb", 20);

  ASSERT_TRUE(result);
  ASSERT_EQ(0, s.check_invariants());
  EXPECT_EQ(TString{"123aaaaaaaaaaaaaaaaaaaa890"}, s);
}

// (5)
TEST(basic_string, replace_iter_iter_csting_count2) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  TString s{"1234567890"};

  auto result = s.replace(s.begin() + 3, s.begin() + 7, "aaaaaaaaaaaaaaaaaaaabbbbbbbbbb", 20);

  ASSERT_TRUE(result);
  ASSERT_EQ(0, s.check_invariants());
  EXPECT_EQ(TString{"123aaaaaaaaaaaaaaaaaaaa890"}, s);
}

// (6)
TEST(basic_string, replace_pos_count_cstring) {
  static_cast<void>(test_info_);
  {
    TMManager::m_counter_ok_allocation = 100;

    TString s{"1234567890"};

    auto result = s.replace(3, 4, "aaaaaaaaaaaaaaaaaaaa");

    ASSERT_TRUE(result);
    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(TString{"123aaaaaaaaaaaaaaaaaaaa890"}, s);
  }
  {
    TMManager::m_counter_ok_allocation = 100;

    TString s{"1234567890"};

    auto result = s.replace(3, 4, "aaaaaaaaaaaaaaaaaaaa\0bbbbbbbbbb", 20);

    ASSERT_TRUE(result);
    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(TString{"123aaaaaaaaaaaaaaaaaaaa890"}, s);
  }
}

// (7)
TEST(basic_string, replace_iter_iter_cstring) {
  static_cast<void>(test_info_);
  {
    TMManager::m_counter_ok_allocation = 100;

    TString s{"1234567890"};

    auto result = s.replace(s.begin() + 3, s.begin() + 7, "aaaaaaaaaaaaaaaaaaaa");

    ASSERT_TRUE(result);
    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(TString{"123aaaaaaaaaaaaaaaaaaaa890"}, s);
  }
  {
    TMManager::m_counter_ok_allocation = 100;

    TString s{"1234567890"};

    auto result = s.replace(s.begin() + 3, s.begin() + 7, "aaaaaaaaaaaaaaaaaaaa\0bbbbbbbbbb", 20);

    ASSERT_TRUE(result);
    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(TString{"123aaaaaaaaaaaaaaaaaaaa890"}, s);
  }
}

// (8)
TEST(basic_string, replace_pos_count_count2_char) {
  static_cast<void>(test_info_);
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s{"1234567890"};

    auto result = s.replace(3, 4, 20, 'a');

    ASSERT_TRUE(result);
    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(TString{"123aaaaaaaaaaaaaaaaaaaa890"}, s);
  }
  {
    TString s{"1234567890"};

    TMManager::m_counter_ok_allocation = 0;

    auto result = s.replace(3, 4, 20, 'a');

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(TString{"1234567890"}, s);
  }
  {
    TString s{"1234567890"};

    TMManager::m_counter_ok_allocation = 0;

    auto result = s.replace(20, 1, 20, 'a');

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(TString{"1234567890"}, s);
  }
}

// (9)
TEST(basic_string, replace_iter_iter_count2_char) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;
  TString s{"1234567890"};

  auto result = s.replace(s.begin() + 3, s.begin() + 7, 20, 'a');

  ASSERT_TRUE(result);
  ASSERT_EQ(0, s.check_invariants());
  EXPECT_EQ(TString{"123aaaaaaaaaaaaaaaaaaaa890"}, s);
}

// (10)
TEST(basic_string, replace_iter_iter_iter2_iter2) {
  static_cast<void>(test_info_);
  {
    TMManager::m_counter_ok_allocation = 100;
    t_char_type const s0[]{"aaaaaaaaaaaaaaaaaaaa"};
    TString           s{"1234567890"};

    auto result = s.replace(s.begin() + 3, s.begin() + 7, &s0[0], &s0[20]);

    ASSERT_TRUE(result);
    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(TString{"123aaaaaaaaaaaaaaaaaaaa890"}, s);
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    t_char_type const s0[]{"aaaaaaaaaaaaaaaaaaaabbbbbbbbbb"};
    TString           s{"1234567890"};

    auto result = s.replace(s.begin() + 3, s.begin() + 7, &s0[0], &s0[20]);

    ASSERT_TRUE(result);
    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(TString{"123aaaaaaaaaaaaaaaaaaaa890"}, s);
  }
}

// (11)
TEST(basic_string, replace_iter_iter_initializer_list) {
  static_cast<void>(test_info_);
  {
    TMManager::m_counter_ok_allocation = 100;
    TString           s{"1234567890"};

    auto result = s.replace(s.begin() + 3, s.begin() + 7, {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                                                           'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'});

    ASSERT_TRUE(result);
    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(TString{"123aaaaaaaaaaaaaaaaaaaa890"}, s);
  }
}

// (13)
TEST(basic_string, replace_iter_iter_string_view) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  TString s{"1234567890"};

  auto result = s.replace(s.begin() + 3, s.begin() + 7, TStringView("aaaaaaaaaaaaaaaaaaaa"));

  ASSERT_TRUE(result);
  ASSERT_EQ(0, s.check_invariants());
  EXPECT_EQ(TString{"123aaaaaaaaaaaaaaaaaaaa890"}, s);
}

// (14)
TEST(basic_string, replace_pos_count_string_view_pos2_count2) {
  static_cast<void>(test_info_);
  {
    TMManager::m_counter_ok_allocation = 100;

    TString s{"1234567890"};

    auto result = s.replace(3, 4, TStringView("bbbaaaaaaaaaaaaaaaaaaaabbb"), 3, 20);

    ASSERT_TRUE(result);
    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(TString{"123aaaaaaaaaaaaaaaaaaaa890"}, s);
  }
  {
    TMManager::m_counter_ok_allocation = 100;

    TString s{"1234567890"};

    auto result = s.replace(3, 4, TStringView("bbbaaaaaaaaaaaaaaaaaaaabbb"), 50, 10);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(TString{"1234567890"}, s);
  }
}
