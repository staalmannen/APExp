// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="basic_string_insert.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************

#include <gtest/gtest.h>

#include <algorithm>

#include "basic_string_test_helper.h"
#include "portable_stl/string/basic_string.h"
#include "portable_stl/string/char_traits.h"
// [insert]

namespace test_string_insert_helper {
static void insert_index_char_count(TString                           &str,
                             std::size_t                        index,
                             std::size_t                        count,
                             t_char_type                        ch,
                             bool                               set_bad_alloc,
                             ::portable_stl::portable_stl_error err
                             = ::portable_stl::portable_stl_error::delete_error) {
  TMManager::m_counter_ok_allocation = (set_bad_alloc ? 0 : 100);

  ASSERT_EQ(0, str.check_invariants());
  auto size_before = str.size();

  auto result = str.insert(index, count, ch);
  ASSERT_EQ(0, str.check_invariants());

  if (result) {
    EXPECT_EQ(size_before + count, str.size());
  } else {
    EXPECT_EQ(result.error(), err);
    EXPECT_EQ(size_before, str.size());
  }
  TMManager::m_counter_ok_allocation = 100;
}

static void insert_index_string_view(TString                           &str,
                              std::size_t                        index,
                              TStringView                        sv,
                              bool                               set_bad_alloc,
                              ::portable_stl::portable_stl_error err
                              = ::portable_stl::portable_stl_error::delete_error) {
  TMManager::m_counter_ok_allocation = (set_bad_alloc ? 0 : 100);

  ASSERT_EQ(0, str.check_invariants());
  auto size_before = str.size();

  auto result = str.insert(index, sv);

  ASSERT_EQ(0, str.check_invariants());
  if (result) {
    EXPECT_EQ(size_before + sv.size(), str.size());
  } else {
    EXPECT_EQ(result.error(), err);
    EXPECT_EQ(size_before, str.size());
  }
  TMManager::m_counter_ok_allocation = 100;
}

static void insert_index_string(TString                           &str,
                         std::size_t                        index,
                         TString const                     &other,
                         bool                               set_bad_alloc,
                         ::portable_stl::portable_stl_error err = ::portable_stl::portable_stl_error::delete_error) {
  TMManager::m_counter_ok_allocation = (set_bad_alloc ? 0 : 100);

  ASSERT_EQ(0, str.check_invariants());
  auto size_before = str.size();

  auto result = str.insert(index, other);

  ASSERT_EQ(0, str.check_invariants());
  if (result) {
    EXPECT_EQ(size_before + other.size(), str.size());
  } else {
    EXPECT_EQ(result.error(), err);
    EXPECT_EQ(size_before, str.size());
  }
  TMManager::m_counter_ok_allocation = 100;
}

static void insert_index_cstring(TString                           &str,
                          std::size_t                        index,
                          typename TString::const_pointer    cstr,
                          bool                               set_bad_alloc,
                          ::portable_stl::portable_stl_error err = ::portable_stl::portable_stl_error::delete_error) {
  TMManager::m_counter_ok_allocation = (set_bad_alloc ? 0 : 100);

  ASSERT_EQ(0, str.check_invariants());
  auto size_before = str.size();

  auto result = str.insert(index, cstr);

  ASSERT_EQ(0, str.check_invariants());
  if (result) {
    EXPECT_EQ(size_before + TString::traits_type::length(cstr), str.size());
  } else {
    EXPECT_EQ(result.error(), err);
    EXPECT_EQ(size_before, str.size());
  }

  TMManager::m_counter_ok_allocation = 100;
}

static void insert_index_cstring_count(TString                           &str,
                                std::size_t                        index,
                                typename TString::const_pointer    cstr,
                                ::portable_stl::size_t             count,
                                bool                               set_bad_alloc,
                                ::portable_stl::portable_stl_error err
                                = ::portable_stl::portable_stl_error::delete_error) {
  TMManager::m_counter_ok_allocation = (set_bad_alloc ? 0 : 100);

  ASSERT_EQ(0, str.check_invariants());
  auto size_before = str.size();

  auto result = str.insert(index, cstr, count);

  ASSERT_EQ(0, str.check_invariants());
  if (result) {
    EXPECT_EQ(size_before + std::min(count, TString::traits_type::length(cstr)), str.size());
  } else {
    EXPECT_EQ(result.error(), err);
    EXPECT_EQ(size_before, str.size());
  }

  TMManager::m_counter_ok_allocation = 100;
}

static void insert_index_string_index_count(TString                           &str,
                                     std::size_t                        index,
                                     TString const                     &other,
                                     std::size_t                        other_index,
                                     std::size_t                        count,
                                     bool                               set_bad_alloc,
                                     ::portable_stl::portable_stl_error err
                                     = ::portable_stl::portable_stl_error::delete_error) {
  TMManager::m_counter_ok_allocation = (set_bad_alloc ? 0 : 100);

  ASSERT_EQ(0, str.check_invariants());
  auto size_before = str.size();

  auto result = str.insert(index, other, other_index, count);

  ASSERT_EQ(0, str.check_invariants());
  if (!result) {
    EXPECT_EQ(result.error(), err);
    EXPECT_EQ(size_before, str.size());
  }

  TMManager::m_counter_ok_allocation = 100;
}
} // namespace test_string_insert_helper

TEST(basic_string, insert_index_count_char) {
  static_cast<void>(test_info_);

  {
    TString s;
    test_string_insert_helper::insert_index_char_count(s, 0, 0, 'a', true); // true - bad_alloc on allocation
  }
  {
    TString s;
    test_string_insert_helper::insert_index_char_count(s, 0, 1, 'a', true);
  }
  {
    TString s;
    test_string_insert_helper::insert_index_char_count(s, 0, test_string_helper::chars_in_SSO, 'a', true);
  }

  // longest SSO
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    test_string_insert_helper::insert_index_char_count(s, 0, 0, 'a', true);
  }
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    test_string_insert_helper::insert_index_char_count(s, 1, 0, 'a', true);
  }
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    test_string_insert_helper::insert_index_char_count(s, test_string_helper::chars_in_SSO, 0, 'a', true);
  }

  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_char_count(s, 0, 2, 'b', true);
    EXPECT_TRUE('b' == s[0]);
    EXPECT_TRUE('b' == s[1]);
    EXPECT_TRUE('a' == s[test_string_helper::chars_in_SSO - 1]);
  }
  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_char_count(s, 5, 2, 'b', true);
    EXPECT_TRUE('a' == s[0]);
    EXPECT_TRUE('b' == s[5]);
    EXPECT_TRUE('b' == s[6]);
    EXPECT_TRUE('a' == s[test_string_helper::chars_in_SSO - 1]);
  }
  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_char_count(s, test_string_helper::chars_in_SSO - 2, 2, 'b', true);
    EXPECT_TRUE('a' == s[0]);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO - 2]);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO - 1]);
  }

  // NO SSO
  {
    TString s;
    test_string_insert_helper::insert_index_char_count(s, 0, test_string_helper::chars_in_SSO + 1, 'a', false);
  }
  {
    TString s;
    test_string_insert_helper::insert_index_char_count(s, 0, 50, 'a', false);
  }

  // SSO+1
  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_char_count(s, 0, 3, 'b', false);
    EXPECT_TRUE('b' == s[0]);
    EXPECT_TRUE('b' == s[1]);
    EXPECT_TRUE('b' == s[2]);
  }

  {
    TString s(30, 'a');
    test_string_insert_helper::insert_index_char_count(s, 0, 3, 'b', false);
  }

  // out_of_range
  {
    TString s;

    test_string_insert_helper::insert_index_char_count(
      s, 1, 0, 'a', false, ::portable_stl::portable_stl_error::out_of_range);
  }
  {
    TString s(test_string_helper::chars_in_SSO, 'a');

    test_string_insert_helper::insert_index_char_count(
      s, test_string_helper::chars_in_SSO + 1, 0, 'a', true, ::portable_stl::portable_stl_error::out_of_range);
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(30, 'a');

    test_string_insert_helper::insert_index_char_count(
      s, 31, 0, 'a', true, ::portable_stl::portable_stl_error::out_of_range);
  }

  // bad_alloc
  {
    TString s;

    test_string_insert_helper::insert_index_char_count(
      s, 0, test_string_helper::chars_in_SSO + 1, 'a', true, ::portable_stl::portable_stl_error::allocate_error);
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(test_string_helper::chars_in_SSO - 2, 'a');

    test_string_insert_helper::insert_index_char_count(
      s, 0, 3, 'b', true, ::portable_stl::portable_stl_error::allocate_error);
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(30, 'a');

    test_string_insert_helper::insert_index_char_count(
      s, 0, 3, 'b', true, ::portable_stl::portable_stl_error::allocate_error);
  }

  // no new allocation
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(30, 'a');
    test_string_insert_helper::insert_index_char_count(s, 0, 0, 'b', true);
  }
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    test_string_insert_helper::insert_index_char_count(s, 0, 0, 'b', true);
  }
}

TEST(basic_string, insert_index_string_view) {
  static_cast<void>(test_info_);
  TString s0{};
  {
    TString s;
    test_string_insert_helper::insert_index_string_view(s, 0, TStringView(s0), true); // true - bad_alloc on allocation
  }

  // longest SSO
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    test_string_insert_helper::insert_index_string_view(s, 0, TStringView(s0), true);
  }
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    test_string_insert_helper::insert_index_string_view(s, 10, TStringView(s0), true);
  }
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    test_string_insert_helper::insert_index_string_view(s, test_string_helper::chars_in_SSO, TStringView(s0), true);
  }

  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_string_view(s, 0, TStringView("bb"), true);
    EXPECT_TRUE('b' == s[0]);
    EXPECT_TRUE('b' == s[1]);
    EXPECT_TRUE('a' == s[test_string_helper::chars_in_SSO - 1]);
  }
  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_string_view(s, 5, TStringView("bb"), true);
    EXPECT_TRUE('a' == s[0]);
    EXPECT_TRUE('b' == s[5]);
    EXPECT_TRUE('b' == s[6]);
    EXPECT_TRUE('a' == s[test_string_helper::chars_in_SSO - 1]);
  }
  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_string_view(
      s, test_string_helper::chars_in_SSO - 2, TStringView("bb"), true);
    EXPECT_TRUE('a' == s[0]);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO - 2]);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO - 1]);
  }

  // NO SSO
  {
    TString s;
    test_string_insert_helper::insert_index_string_view(s, 0, TStringView("aaaaaaaaaaaaaaaaaaaaaaa"), false);
  }
  {
    TString s;
    test_string_insert_helper::insert_index_string_view(s, 0, TStringView(test_string_helper::test_string2), false);
  }

  // SSO+1
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    test_string_insert_helper::insert_index_string_view(s, 0, TStringView("bbb"), false);
    EXPECT_TRUE('b' == s[0]);
    EXPECT_TRUE('b' == s[1]);
    EXPECT_TRUE('b' == s[2]);
  }

  {
    TString s(30, 'a');
    test_string_insert_helper::insert_index_string_view(s, 0, TStringView("bbb"), false);
  }

  // out_of_range
  {
    TString s{};

    test_string_insert_helper::insert_index_string_view(
      s, 1, TStringView(""), false, ::portable_stl::portable_stl_error::out_of_range);
  }
  {
    TString s(test_string_helper::chars_in_SSO, 'a');

    test_string_insert_helper::insert_index_string_view(
      s, test_string_helper::chars_in_SSO + 1, TStringView(""), true, ::portable_stl::portable_stl_error::out_of_range);
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(30, 'a');

    test_string_insert_helper::insert_index_string_view(
      s, 31, TStringView(""), true, ::portable_stl::portable_stl_error::out_of_range);
  }

  // bad_alloc
  {
    TString s;

    test_string_insert_helper::insert_index_string_view(
      s, 0, TStringView("aaaaaaaaaaaaaaaaaaaaaaa"), true, ::portable_stl::portable_stl_error::allocate_error);
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(test_string_helper::chars_in_SSO - 2, 'a');

    test_string_insert_helper::insert_index_string_view(
      s, 0, TStringView("bbb"), true, ::portable_stl::portable_stl_error::allocate_error);
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(30, 'a');

    test_string_insert_helper::insert_index_string_view(
      s, 0, TStringView("bbb"), true, ::portable_stl::portable_stl_error::allocate_error);
  }

  // no new allocation
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(30, 'a');
    test_string_insert_helper::insert_index_string_view(s, 0, TStringView(""), true);
  }
}

TEST(basic_string, insert_index_cstring) {
  static_cast<void>(test_info_);

  {
    TString s;
    test_string_insert_helper::insert_index_cstring(s, 0, "", true); // true - bad_alloc on allocation
  }

  // longest SSO
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    test_string_insert_helper::insert_index_cstring(s, 0, "", true);
  }
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    test_string_insert_helper::insert_index_cstring(s, 10, "", true);
  }
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    test_string_insert_helper::insert_index_cstring(s, test_string_helper::chars_in_SSO, "", true);
  }

  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_cstring(s, 0, "bb", true);
    EXPECT_TRUE('b' == s[0]);
    EXPECT_TRUE('b' == s[1]);
    EXPECT_TRUE('a' == s[test_string_helper::chars_in_SSO - 1]);
  }
  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_cstring(s, 5, "bb", true);
    EXPECT_TRUE('a' == s[0]);
    EXPECT_TRUE('b' == s[5]);
    EXPECT_TRUE('b' == s[6]);
    EXPECT_TRUE('a' == s[test_string_helper::chars_in_SSO - 1]);
  }
  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_cstring(s, test_string_helper::chars_in_SSO - 2, "bb", true);
    EXPECT_TRUE('a' == s[0]);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO - 2]);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO - 1]);
  }

  // NO SSO
  {
    TString s;
    test_string_insert_helper::insert_index_cstring(s, 0, "aaaaaaaaaaaaaaaaaaaaaaa", false);
  }
  {
    TString s;
    test_string_insert_helper::insert_index_cstring(s, 0, test_string_helper::test_string2, false);
  }

  // SSO+1
  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_cstring(s, 0, "bbb", false);
    EXPECT_TRUE('b' == s[0]);
    EXPECT_TRUE('b' == s[1]);
    EXPECT_TRUE('b' == s[2]);
  }

  {
    TString s(30, 'a');
    test_string_insert_helper::insert_index_cstring(s, 0, "bbb", false);
  }

  // out_of_range
  {
    TString s{};

    test_string_insert_helper::insert_index_cstring(s, 1, "", false, ::portable_stl::portable_stl_error::out_of_range);
  }
  {
    TString s(test_string_helper::chars_in_SSO, 'a');

    test_string_insert_helper::insert_index_cstring(
      s, test_string_helper::chars_in_SSO + 1, "", true, ::portable_stl::portable_stl_error::out_of_range);
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(30, 'a');

    test_string_insert_helper::insert_index_cstring(s, 31, "", true, ::portable_stl::portable_stl_error::out_of_range);
  }

  // bad_alloc
  {
    TString s;

    test_string_insert_helper::insert_index_cstring(
      s, 0, "aaaaaaaaaaaaaaaaaaaaaaa", true, ::portable_stl::portable_stl_error::allocate_error);
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(test_string_helper::chars_in_SSO - 2, 'a');

    test_string_insert_helper::insert_index_cstring(
      s, 0, "bbb", true, ::portable_stl::portable_stl_error::allocate_error);
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(30, 'a');

    test_string_insert_helper::insert_index_cstring(
      s, 0, "bbb", true, ::portable_stl::portable_stl_error::allocate_error);
  }

  // no new allocation
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(30, 'a');
    test_string_insert_helper::insert_index_cstring(s, 0, "", true);
  }
}

TEST(basic_string, insert_index_cstring_count) {
  static_cast<void>(test_info_);

  {
    TString s;
    test_string_insert_helper::insert_index_cstring_count(s, 0, "", 0, true); // true - bad_alloc on allocation
  }

  // longest SSO
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    test_string_insert_helper::insert_index_cstring_count(s, 0, "", 0, true);
  }
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    test_string_insert_helper::insert_index_cstring_count(s, 5, "", 0, true);
  }
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    test_string_insert_helper::insert_index_cstring_count(s, test_string_helper::chars_in_SSO, "", 0, true);
  }

  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_cstring_count(s, 0, "bb", 2, true);
    EXPECT_TRUE('b' == s[0]);
    EXPECT_TRUE('b' == s[1]);
    EXPECT_TRUE('a' == s[test_string_helper::chars_in_SSO - 1]);
  }
  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_cstring_count(s, 5, "bb", 2, true);
    EXPECT_TRUE('a' == s[0]);
    EXPECT_TRUE('b' == s[5]);
    EXPECT_TRUE('b' == s[6]);
    EXPECT_TRUE('a' == s[test_string_helper::chars_in_SSO - 1]);
  }
  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_cstring_count(s, test_string_helper::chars_in_SSO - 2, "bb", 2, true);
    EXPECT_TRUE('a' == s[0]);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO - 2]);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO - 1]);
  }
  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_cstring_count(
      s, test_string_helper::chars_in_SSO - 2, "bbbbbbbbbb", 2, true);
    EXPECT_TRUE('a' == s[0]);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO - 2]);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO - 1]);
  }

  // NO SSO
  {
    TString s;
    test_string_insert_helper::insert_index_cstring_count(
      s, 0, "aaaaaaaaaaaaaaaaaaaaaaa", test_string_helper::chars_in_SSO + 1, false);
  }
  {
    TString s;
    test_string_insert_helper::insert_index_cstring_count(s, 0, test_string_helper::test_string2, 45, false);
  }

  // SSO+1
  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_cstring_count(s, 0, "bbb", 3, false);
    EXPECT_TRUE('b' == s[0]);
    EXPECT_TRUE('b' == s[1]);
    EXPECT_TRUE('b' == s[2]);
  }

  {
    TString s(30, 'a');
    test_string_insert_helper::insert_index_cstring_count(s, 0, "bbbbbb", 3, false);
  }

  // out_of_range
  {
    TString s{};

    test_string_insert_helper::insert_index_cstring_count(
      s, 1, "", 0, false, ::portable_stl::portable_stl_error::out_of_range);
  }
  {
    TString s(test_string_helper::chars_in_SSO, 'a');

    test_string_insert_helper::insert_index_cstring_count(
      s, test_string_helper::chars_in_SSO + 1, "", 0, true, ::portable_stl::portable_stl_error::out_of_range);
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(30, 'a');

    test_string_insert_helper::insert_index_cstring_count(
      s, 31, "", 0, true, ::portable_stl::portable_stl_error::out_of_range);
  }

  // bad_alloc
  {
    TString s;

    test_string_insert_helper::insert_index_cstring_count(s,
                                                          0,
                                                          "aaaaaaaaaaaaaaaaaaaaaaa",
                                                          test_string_helper::chars_in_SSO + 1,
                                                          true,
                                                          ::portable_stl::portable_stl_error::allocate_error);
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(test_string_helper::chars_in_SSO - 2, 'a');

    test_string_insert_helper::insert_index_cstring_count(
      s, 0, "bbbaaa", 3, true, ::portable_stl::portable_stl_error::allocate_error);
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(30, 'a');

    test_string_insert_helper::insert_index_cstring_count(
      s, 0, "bbb", 3, true, ::portable_stl::portable_stl_error::allocate_error);
  }

  // no new allocation
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(30, 'a');
    test_string_insert_helper::insert_index_cstring_count(s, 0, "", 0, true);
  }
}

TEST(basic_string, insert_index_string) {
  static_cast<void>(test_info_);

  {
    TString s;
    test_string_insert_helper::insert_index_string(s, 0, TString(""), true); // true - bad_alloc on allocation
  }

  // longest SSO
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    test_string_insert_helper::insert_index_string(s, 0, TString(""), true);
  }
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    test_string_insert_helper::insert_index_string(s, 10, TString(""), true);
  }
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    test_string_insert_helper::insert_index_string(s, test_string_helper::chars_in_SSO, TString(""), true);
  }

  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_string(s, 0, TString("bb"), true);
    EXPECT_TRUE('b' == s[0]);
    EXPECT_TRUE('b' == s[1]);
    EXPECT_TRUE('a' == s[test_string_helper::chars_in_SSO - 1]);
  }
  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_string(s, 5, TString("bb"), true);
    EXPECT_TRUE('a' == s[0]);
    EXPECT_TRUE('b' == s[5]);
    EXPECT_TRUE('b' == s[6]);
    EXPECT_TRUE('a' == s[test_string_helper::chars_in_SSO - 1]);
  }
  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_string(s, test_string_helper::chars_in_SSO - 2, TString("bb"), true);
    EXPECT_TRUE('a' == s[0]);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO - 2]);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO - 1]);
  }

  // NO SSO
  {
    TString s;
    test_string_insert_helper::insert_index_string(s, 0, TString("aaaaaaaaaaaaaaaaaaaaaaa"), false);
  }
  {
    TString s;
    test_string_insert_helper::insert_index_string(s, 0, test_string_helper::s2, false);
  }

  // SSO+1
  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_string(s, 0, TString("bbb"), false);
    EXPECT_TRUE('b' == s[0]);
    EXPECT_TRUE('b' == s[1]);
    EXPECT_TRUE('b' == s[2]);
  }

  {
    TString s(30, 'a');
    test_string_insert_helper::insert_index_string(s, 0, TString("bbb"), false);
  }

  // out_of_range
  {
    TString s{};

    test_string_insert_helper::insert_index_string(
      s, 1, TString(""), false, ::portable_stl::portable_stl_error::out_of_range);
  }
  {
    TString s(test_string_helper::chars_in_SSO, 'a');

    test_string_insert_helper::insert_index_string(
      s, test_string_helper::chars_in_SSO + 1, TString(""), true, ::portable_stl::portable_stl_error::out_of_range);
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(30, 'a');

    test_string_insert_helper::insert_index_string(
      s, 31, TString(""), true, ::portable_stl::portable_stl_error::out_of_range);
  }

  // bad_alloc
  {
    TString s;

    test_string_insert_helper::insert_index_string(
      s, 0, TString("aaaaaaaaaaaaaaaaaaaaaaa"), true, ::portable_stl::portable_stl_error::allocate_error);
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(test_string_helper::chars_in_SSO - 2, 'a');

    test_string_insert_helper::insert_index_string(
      s, 0, TString("bbb"), true, ::portable_stl::portable_stl_error::allocate_error);
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(30, 'a');

    test_string_insert_helper::insert_index_string(
      s, 0, TString("bbb"), true, ::portable_stl::portable_stl_error::allocate_error);
  }

  // no new allocation
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(30, 'a');
    test_string_insert_helper::insert_index_string(s, 0, TString(""), true);
  }
}

TEST(basic_string, insert_index_string_index_count) {
  static_cast<void>(test_info_);

  TString s0;
  {
    TString s;
    test_string_insert_helper::insert_index_string_index_count(
      s, 0, s0, 0, 0, true); // true - bad_alloc on allocation
  }

  // longest SSO
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    test_string_insert_helper::insert_index_string_index_count(s, 0, s0, 0, TString::npos, true);
  }
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    test_string_insert_helper::insert_index_string_index_count(s, 10, s0, 0, 10, true);
  }
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    test_string_insert_helper::insert_index_string_index_count(
      s, test_string_helper::chars_in_SSO, s0, 0, TString::npos, true);
  }

  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_string_index_count(s, 0, TString("bb"), 0, TString::npos, true);
    EXPECT_TRUE('b' == s[0]);
    EXPECT_TRUE('b' == s[1]);
    EXPECT_TRUE('a' == s[test_string_helper::chars_in_SSO - 1]);
  }
  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_string_index_count(s, 5, TString("bb"), 0, 2, true);
    EXPECT_TRUE('a' == s[0]);
    EXPECT_TRUE('b' == s[5]);
    EXPECT_TRUE('b' == s[6]);
    EXPECT_TRUE('a' == s[test_string_helper::chars_in_SSO - 1]);
  }
  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_string_index_count(
      s, test_string_helper::chars_in_SSO - 2, TString("aabb"), 2, TString::npos, true);
    EXPECT_TRUE('a' == s[0]);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO - 2]);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO - 1]);
  }

  // NO SSO
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s;
    test_string_insert_helper::insert_index_string_index_count(
      s, 0, TString("bbaaaaaaaaaaaaaaaaaaaaaaa"), 2, TString::npos, false);
  }
  {
    TString s;
    test_string_insert_helper::insert_index_string_index_count(s, 0, test_string_helper::s2, 5, 50, false);
  }

  // SSO+1
  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_insert_helper::insert_index_string_index_count(s, 0, TString("cbbb"), 1, 3, false);
    EXPECT_TRUE('b' == s[0]);
    EXPECT_TRUE('b' == s[1]);
    EXPECT_TRUE('b' == s[2]);
  }

  {
    TString s(30, 'a');
    test_string_insert_helper::insert_index_string_index_count(s, 0, TString("cccbbb"), 3, 50, false);
  }

  // insertion out_of_range
  {
    TString s{};

    test_string_insert_helper::insert_index_string_index_count(
      s, 1, TString(""), 0, 0, false, ::portable_stl::portable_stl_error::out_of_range);
  }
  {
    TString s(test_string_helper::chars_in_SSO, 'a');

    test_string_insert_helper::insert_index_string_index_count(
      s, test_string_helper::chars_in_SSO + 1, TString(""), 0, 0, true, ::portable_stl::portable_stl_error::out_of_range);
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(30, 'a');

    test_string_insert_helper::insert_index_string_index_count(
      s, 31, TString(""), 0, 0, true, ::portable_stl::portable_stl_error::out_of_range);
  }

  // substr out_of_range
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(30, 'a');

    test_string_insert_helper::insert_index_string_index_count(
      s, 31, TString("aaabbb"), 10, 1, true, ::portable_stl::portable_stl_error::out_of_range);
  }

  // bad_alloc
  {
    TString s;

    test_string_insert_helper::insert_index_string_index_count(
      s, 0, TString("aaaaaaaaaaaaaaaaaaaaaaa"), 0, 50, true, ::portable_stl::portable_stl_error::allocate_error);
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(test_string_helper::chars_in_SSO - 2, 'a');

    test_string_insert_helper::insert_index_string_index_count(
      s, 0, TString("bbb"), 0, 50, true, ::portable_stl::portable_stl_error::allocate_error);
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(30, 'a');

    test_string_insert_helper::insert_index_string_index_count(
      s, 0, TString("bbb"), 0, 50, true, ::portable_stl::portable_stl_error::allocate_error);
  }

  // no new allocation
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(30, 'a');
    test_string_insert_helper::insert_index_string_index_count(s, 0, TString(""), 0, 50, true);
  }
}

namespace test_string_insert_helper {
static void insert_pos_char(
  TString &str, typename TString::const_iterator pos, typename TString::value_type ch, TString expected) {
  bool                              sufficient_cap{str.size() < (str.capacity() - 1)};
  typename TString::difference_type index{pos - str.begin()};
  auto                              result = str.insert(pos, ch);
  ASSERT_TRUE(result);
  typename TString::iterator i{result.value()};

  ASSERT_EQ(0, str.check_invariants());

  ASSERT_TRUE(str == expected);
  ASSERT_EQ(index, i - str.begin());
  ASSERT_EQ(*i, ch);
  if (sufficient_cap) {
    ASSERT_EQ(i, pos);
  }
}
} // namespace test_string_insert_helper

TEST(basic_string, insert_pos_char) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  TString s{};
  test_string_insert_helper::insert_pos_char(s, s.begin(), '1', TString("1"));
  test_string_insert_helper::insert_pos_char(s, s.begin(), 'a', TString("a1"));
  test_string_insert_helper::insert_pos_char(s, s.end(), 'b', TString("a1b"));
  test_string_insert_helper::insert_pos_char(s, s.end() - 1, 'c', TString("a1cb"));
  test_string_insert_helper::insert_pos_char(s, s.end() - 2, 'd', TString("a1dcb"));
  test_string_insert_helper::insert_pos_char(s, s.end() - 3, '2', TString("a12dcb"));
  test_string_insert_helper::insert_pos_char(s, s.end() - 4, '3', TString("a132dcb"));
  test_string_insert_helper::insert_pos_char(s, s.end() - 5, '4', TString("a1432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin() + 1, '5', TString("a51432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin() + 2, '6', TString("a561432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin() + 3, '7', TString("a5671432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin() + 4, 'A', TString("a567A1432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin() + 5, 'B', TString("a567AB1432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin() + 6, 'C', TString("a567ABC1432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin(), 'x', TString("xa567ABC1432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin(), 'x', TString("xxa567ABC1432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin(), 'x', TString("xxxa567ABC1432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin(), 'x', TString("xxxxa567ABC1432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin(), 'x', TString("xxxxxa567ABC1432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin(), 'x', TString("xxxxxxa567ABC1432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin(), 'x', TString("xxxxxxxa567ABC1432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin(), 'x', TString("xxxxxxxxa567ABC1432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin(), 'x', TString("xxxxxxxxxa567ABC1432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin(), 'x', TString("xxxxxxxxxxa567ABC1432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin(), 'x', TString("xxxxxxxxxxxa567ABC1432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin(), 'x', TString("xxxxxxxxxxxxa567ABC1432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin(), 'x', TString("xxxxxxxxxxxxxa567ABC1432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin(), 'x', TString("xxxxxxxxxxxxxxa567ABC1432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin(), 'x', TString("xxxxxxxxxxxxxxxa567ABC1432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin(), 'x', TString("xxxxxxxxxxxxxxxxa567ABC1432dcb"));
  test_string_insert_helper::insert_pos_char(s, s.begin() + 1, 'x', TString("xxxxxxxxxxxxxxxxxa567ABC1432dcb"));
}

TEST(basic_string, insert_pos_count_char) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 0;

  TString s{};
  auto    result = s.insert(s.begin(), test_string_helper::chars_in_SSO, 'a');

  ASSERT_TRUE(result);
  ASSERT_EQ(0, s.check_invariants());
  EXPECT_EQ(test_string_helper::chars_in_SSO, s.size());
  EXPECT_EQ(s.begin(), result.value());
  EXPECT_EQ(test_string_helper::test_string_of_a_SSO, s);
}

TEST(basic_string, insert_pos_iter_iter) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  TString s{"1234567890"};

  auto result = s.insert(s.begin() + 4,
                         &test_string_helper::test_string_of_a_SSO[0],
                         &test_string_helper::test_string_of_a_SSO[test_string_helper::chars_in_SSO]);

  ASSERT_TRUE(result);
  ASSERT_EQ(0, s.check_invariants());
  EXPECT_EQ(10 + test_string_helper::chars_in_SSO, s.size());

  EXPECT_TRUE(s.starts_with("1234"));
  EXPECT_TRUE(s.contains(test_string_helper::test_string_of_a_SSO));
  EXPECT_TRUE(s.ends_with("567890"));
}

TEST(basic_string, insert_pos_initializer_list) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  TString s{"12345678901234657890"};

  auto result = s.insert(s.begin() + 4, {'a', 'b', 'c', 'd', 'e'});

  ASSERT_TRUE(result);
  ASSERT_EQ(0, s.check_invariants());
  EXPECT_EQ(5 + 20, s.size());

  EXPECT_TRUE(s.starts_with("1234"));
  EXPECT_TRUE(s.contains("abcde"));
  EXPECT_TRUE(s.ends_with("5678901234657890"));
}

TEST(basic_string, insert_index_string_view_index_count) {
  static_cast<void>(test_info_);
  {
    TMManager::m_counter_ok_allocation = 100;

    TString s{"12345678901234657890"};
    TString s0{"aaabbbcccdddeee"};

    auto result = s.insert(4, TStringView(s0), 3, 9);

    ASSERT_TRUE(result);
    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(9 + 20, s.size());

    EXPECT_TRUE(s.starts_with("1234"));
    EXPECT_TRUE(s.contains("bbbcccddd"));
    EXPECT_TRUE(s.ends_with("5678901234657890"));
  }
  // out of range
  {
    TMManager::m_counter_ok_allocation = 100;

    TString       s{"12345678901234657890"};
    TString const ref{s};
    auto const    size1 = s.size();
    TString       s0{"aaabbbcccdddeee"};

    auto result = s.insert(4, TStringView(s0), 50, 9);

    ASSERT_FALSE(result);
    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(size1, s.size());
    EXPECT_EQ(ref, s);
  }
}

TEST(basic_string, push_back) {
  static_cast<void>(test_info_);

  {
    TMManager::m_counter_ok_allocation = 0;
    TString s{};
    for (::portable_stl::size_t i{0U}; i < 10; ++i) {
      EXPECT_TRUE(s.push_back('a'));
      ASSERT_EQ(0, s.check_invariants());
      EXPECT_EQ(i + 1, s.size());
      EXPECT_EQ(TString("").capacity(), s.capacity());
      EXPECT_EQ(TString(i + 1, 'a'), s);
    }
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s{};
    for (::portable_stl::size_t i{0U}; i < 30; ++i) {
      EXPECT_TRUE(s.push_back('a'));
      ASSERT_EQ(0, s.check_invariants());
      EXPECT_EQ(i + 1, s.size());
      EXPECT_EQ(TString(i + 1, 'a'), s);
    }
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString       s{"1234567890123456789012"};
    TString const ref{s};

    TMManager::m_counter_ok_allocation = 0;
    EXPECT_FALSE(s.push_back('a'));

    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(ref, s);
  }
}
