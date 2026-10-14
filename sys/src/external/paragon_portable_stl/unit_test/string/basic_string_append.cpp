// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="basic_string_append.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "basic_string_test_helper.h"
#include "portable_stl/common/char8_t.h"
#include "portable_stl/string/basic_string.h"
#include "portable_stl/string/char_traits.h"

// [append]

namespace test_string_append_helper {
static void append_count_char(TString                           &str,
                              std::size_t                        count,
                              t_char_type                        ch,
                              bool                               set_bad_alloc,
                              ::portable_stl::portable_stl_error err
                              = ::portable_stl::portable_stl_error::delete_error) {
  TMManager::m_counter_ok_allocation = 100;
  TString const ref{str};
  EXPECT_EQ(0, str.check_invariants());
  auto size_before                   = str.size();
  TMManager::m_counter_ok_allocation = (set_bad_alloc ? 0 : 100);

  auto result = str.append(count, ch);

  EXPECT_EQ(0, str.check_invariants());
  if (result) {
    EXPECT_EQ(size_before + count, str.size());
  } else {
    EXPECT_EQ(err, result.error());
    EXPECT_EQ(ref, str);
  }
  TMManager::m_counter_ok_allocation = 100;
}

static void append_string_view(TString                           &str,
                               TStringView const                 &sv,
                               bool                               set_bad_alloc,
                               ::portable_stl::portable_stl_error err
                               = ::portable_stl::portable_stl_error::delete_error) {
  TMManager::m_counter_ok_allocation = 100;
  TString const ref{str};
  EXPECT_EQ(0, str.check_invariants());
  auto size_before                   = str.size();
  TMManager::m_counter_ok_allocation = (set_bad_alloc ? 0 : 100);

  auto result = str.append(sv);

  EXPECT_EQ(0, str.check_invariants());
  if (result) {
    EXPECT_EQ(size_before + sv.size(), str.size());
  } else {
    EXPECT_EQ(err, result.error());
    EXPECT_EQ(ref, str);
  }
  TMManager::m_counter_ok_allocation = 100;
}
} // namespace test_string_append_helper

TEST(basic_string, append_count_char) {
  static_cast<void>(test_info_);

  {
    TString s;
    test_string_append_helper::append_count_char(s, 0, 'a', true); // true - bad_alloc on allocation
  }
  {
    TString s;
    test_string_append_helper::append_count_char(s, test_string_helper::chars_in_SSO, 'a', true);
  }

  // longest SSO
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    test_string_append_helper::append_count_char(s, 0, 'a', true);
  }

  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_append_helper::append_count_char(s, 2, 'b', true);
    EXPECT_TRUE('a' == s[0]);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO - 2]);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO - 1]);
  }

  // NO SSO
  {
    TString s;
    test_string_append_helper::append_count_char(s, test_string_helper::chars_in_SSO + 1, 'a', false);
  }
  {
    TString s;
    test_string_append_helper::append_count_char(s, 50, 'a', false);
  }

  // SSO+1
  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_append_helper::append_count_char(s, 3, 'b', false);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO - 2]);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO - 1]);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO]);
  }

  {
    TString s(30, 'a');
    test_string_append_helper::append_count_char(s, 3, 'b', false);
  }

  // bad_alloc
  {
    TString s{test_string_helper::s1};

    test_string_append_helper::append_count_char(
      s, test_string_helper::chars_in_SSO + 1, 'a', true, ::portable_stl::portable_stl_error::allocate_error);
  }
}

TEST(basic_string, append_string_view) {
  static_cast<void>(test_info_);

  {
    TString s;
    test_string_append_helper::append_string_view(s, TStringView(""), true); // true - bad_alloc on allocation
  }
  {
    TString s;
    test_string_append_helper::append_string_view(s, TStringView(test_string_helper::test_string_of_a_SSO), true);
  }

  // longest SSO
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    test_string_append_helper::append_string_view(s, TStringView(""), true);
  }

  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_append_helper::append_string_view(s, TStringView("bb"), true);
    EXPECT_TRUE('a' == s[0]);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO - 2]);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO - 1]);
  }

  // NO SSO
  {
    TString s;
    test_string_append_helper::append_string_view(s, TStringView(test_string_helper::test_string2), false);
  }

  // SSO+1
  {
    TString s(test_string_helper::chars_in_SSO - 2, 'a');
    test_string_append_helper::append_string_view(s, TStringView("bbb"), false);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO - 2]);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO - 1]);
    EXPECT_TRUE('b' == s[test_string_helper::chars_in_SSO]);
  }

  {
    TString s(30, 'a');
    test_string_append_helper::append_string_view(s, TStringView("bbb"), false);
  }

  // bad_alloc
  {
    TString s{test_string_helper::s1};

    test_string_append_helper::append_string_view(
      s, test_string_helper::s2, true, ::portable_stl::portable_stl_error::allocate_error);
  }
}

TEST(basic_string, append_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  TString s{test_string_helper::test_string_of_a_SSO};
  s.append(TString("endendend"));

  EXPECT_EQ(0, s.check_invariants());
  EXPECT_TRUE(s.ends_with("endendend"));
  EXPECT_TRUE(s.starts_with(test_string_helper::test_string_of_a_SSO));
}

TEST(basic_string, append_string_index_count) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    TString s{test_string_helper::test_string_of_a_SSO};
    s.append(TString("___endendend"), 3);

    EXPECT_EQ(0, s.check_invariants());
    EXPECT_TRUE(s.ends_with("endendend"));
    EXPECT_TRUE(s.starts_with(test_string_helper::test_string_of_a_SSO));
  }

  // bad indexing
  {
    TString s{test_string_helper::test_string_of_a_SSO};

    auto result = s.append(TString("___endendend"), 50, 1);
    EXPECT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());

    // check strong exception safety guarantee.
    EXPECT_TRUE(test_string_helper::test_string_of_a_SSO == s);
    EXPECT_EQ(0, s.check_invariants());
  }
}

TEST(basic_string, append_cstring_count) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  TString s{test_string_helper::test_string_of_a_SSO};
  s.append("endendend___", 9);

  EXPECT_EQ(0, s.check_invariants());
  EXPECT_TRUE(s.ends_with("endendend"));
  EXPECT_TRUE(s.starts_with(test_string_helper::test_string_of_a_SSO));
}

TEST(basic_string, append_cstring) {
  static_cast<void>(test_info_);
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s{test_string_helper::test_string_of_a_SSO};
    s.append("endendend");

    EXPECT_EQ(0, s.check_invariants());
    EXPECT_TRUE(s.ends_with("endendend"));
    EXPECT_TRUE(s.starts_with(test_string_helper::test_string_of_a_SSO));
  }

  {
    TMManager::m_counter_ok_allocation = 0;
    TString s{test_string_helper::test_string_of_a_SSO};
    s.append("");

    EXPECT_EQ(0, s.check_invariants());
    EXPECT_TRUE(test_string_helper::test_string_of_a_SSO == s);
  }
}

TEST(basic_string, utf8_append_cstring) {
  static_cast<void>(test_info_);

  using t_u8string = ::portable_stl::basic_string<::portable_stl::pstl_char8_t,
                                                  ::portable_stl::char_traits<::portable_stl::pstl_char8_t>,
                                                  ::portable_stl::allocator<::portable_stl::pstl_char8_t>>;
  {
    t_u8string s{"1234567890123456789012345678901234567890"};
    s.append("endendend");

    EXPECT_EQ(0, s.check_invariants());
    EXPECT_TRUE(s.ends_with("endendend"));
    EXPECT_TRUE(s.starts_with("1234567890123456789012345678901234567890"));
  }

  {
    t_u8string s{"1234567890123456789012345678901234567890"};
    s.append("");

    EXPECT_EQ(0, s.check_invariants());
    EXPECT_TRUE(s.starts_with("1234567890123456789012345678901234567890"));
  }
}

TEST(basic_string, append_iter_iter) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;
  TString s{test_string_helper::test_string_of_a_SSO};

  s.append(&test_string_helper::test_string_of_a_SSO[0],
           &test_string_helper::test_string_of_a_SSO[test_string_helper::chars_in_SSO]);

  EXPECT_EQ(0, s.check_invariants());
  EXPECT_EQ(2 * test_string_helper::chars_in_SSO, s.size());
  EXPECT_TRUE(s.ends_with(test_string_helper::test_string_of_a_SSO));
  EXPECT_TRUE(s.starts_with(test_string_helper::test_string_of_a_SSO));
}

TEST(basic_string, append_initializer_list) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;
  TString s{test_string_helper::test_string_of_a_SSO};

  s.append({'a', 'b', 'c', 'd', 'e'});

  EXPECT_EQ(0, s.check_invariants());
  EXPECT_TRUE(s.ends_with("abcde"));
  EXPECT_TRUE(s.starts_with(test_string_helper::test_string_of_a_SSO));
}

TEST(basic_string, append_string_view_index_count) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    TString s{test_string_helper::test_string_of_a_SSO};
    s.append(TStringView("___endendend"), 3);

    EXPECT_EQ(0, s.check_invariants());
    EXPECT_TRUE(s.ends_with("endendend"));
    EXPECT_TRUE(s.starts_with(test_string_helper::test_string_of_a_SSO));
  }

  // bad indexing
  {
    TString s{test_string_helper::test_string_of_a_SSO};

    auto result = s.append(TStringView("___endendend"), 50, 1);
    EXPECT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());

    // check strong exception safety guarantee.
    EXPECT_TRUE(test_string_helper::test_string_of_a_SSO == s);
    EXPECT_EQ(0, s.check_invariants());
  }
}

// [operator+=]

TEST(basic_string, operator_plus_eq_string) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    TString s{test_string_helper::test_string_of_a_SSO};
    s += TString("endendend");

    EXPECT_EQ(0, s.check_invariants());
    EXPECT_TRUE(s.ends_with("endendend"));
    EXPECT_TRUE(s.starts_with(test_string_helper::test_string_of_a_SSO));
  }
}

TEST(basic_string, operator_plus_eq_char) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    TString s{test_string_helper::test_string_of_a_SSO};
    s += 'q';

    EXPECT_EQ(0, s.check_invariants());
    EXPECT_TRUE(s.ends_with("q"));
    EXPECT_TRUE(s.starts_with(test_string_helper::test_string_of_a_SSO));
  }
}

TEST(basic_string, operator_plus_eq_cstring) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    TString s{test_string_helper::test_string_of_a_SSO};
    s += "endendend\0___";

    EXPECT_EQ(0, s.check_invariants());
    EXPECT_TRUE(s.ends_with("endendend"));
    EXPECT_TRUE(s.starts_with(test_string_helper::test_string_of_a_SSO));
  }
}

TEST(basic_string, operator_plus_eq_initializer_list) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    TString s{test_string_helper::test_string_of_a_SSO};
    s += {'a', 'b', 'c', 'd', 'e'};

    EXPECT_EQ(0, s.check_invariants());
    EXPECT_TRUE(s.ends_with("abcde"));
    EXPECT_TRUE(s.starts_with(test_string_helper::test_string_of_a_SSO));
  }
}

TEST(basic_string, operator_plus_eq_string_view) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    TString s{test_string_helper::test_string_of_a_SSO};
    s += TStringView("endendend\0___");

    EXPECT_EQ(0, s.check_invariants());
    EXPECT_TRUE(s.ends_with("endendend"));
    EXPECT_TRUE(s.starts_with(test_string_helper::test_string_of_a_SSO));
  }
}
