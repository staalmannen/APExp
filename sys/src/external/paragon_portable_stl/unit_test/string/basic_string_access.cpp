// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="basic_string_access.cpp"
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

// [access]

TEST(basic_string, c_str) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    TString                             s;
    typename TString::value_type const *cstr = s.c_str();
    EXPECT_TRUE(TTraitsType::eq(typename TString::value_type(), cstr[0]));
  }
  {
    TString                             s("");
    typename TString::value_type const *cstr = s.c_str();
    EXPECT_TRUE(TTraitsType::eq(typename TString::value_type(), cstr[0]));
  }
  {
    TString                             s("1234567890");
    typename TString::value_type const *cstr = s.c_str();
    EXPECT_EQ(0, TTraitsType::compare(cstr, &s[0], s.size()));
    EXPECT_TRUE(TTraitsType::eq(typename TString::value_type(), cstr[s.size()]));
  }
  {
    TString                             s("12345678901");
    typename TString::value_type const *cstr = s.c_str();
    EXPECT_EQ(0, TTraitsType::compare(cstr, &s[0], s.size()));
    EXPECT_TRUE(TTraitsType::eq(typename TString::value_type(), cstr[s.size()]));
  }
  {
    TString                             s("123456789012");
    typename TString::value_type const *cstr = s.c_str();
    EXPECT_EQ(0, TTraitsType::compare(cstr, &s[0], s.size()));
    EXPECT_TRUE(TTraitsType::eq(typename TString::value_type(), cstr[s.size()]));
  }
  {
    TString                             s("1234567890123456789012");
    typename TString::value_type const *cstr = s.c_str();
    EXPECT_EQ(0, TTraitsType::compare(cstr, &s[0], s.size()));
    EXPECT_TRUE(TTraitsType::eq(typename TString::value_type(), cstr[s.size()]));
  }
  {
    TString                             s("12345678901234567890123");
    typename TString::value_type const *cstr = s.c_str();
    EXPECT_EQ(0, TTraitsType::compare(cstr, &s[0], s.size()));
    EXPECT_TRUE(TTraitsType::eq(typename TString::value_type(), cstr[s.size()]));
  }
  {
    TString                             s("123456789012345678901234");
    typename TString::value_type const *cstr = s.c_str();
    EXPECT_EQ(0, TTraitsType::compare(cstr, &s[0], s.size()));
    EXPECT_TRUE(TTraitsType::eq(typename TString::value_type(), cstr[s.size()]));
  }
}

TEST(basic_string, data) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    TString                             s;
    typename TString::value_type const *cstr = s.data();
    EXPECT_TRUE(TTraitsType::eq(typename TString::value_type(), cstr[0]));
  }
  {
    TString                             s("");
    typename TString::value_type const *cstr = s.data();
    EXPECT_TRUE(TTraitsType::eq(typename TString::value_type(), cstr[0]));
  }
  {
    TString                             s("1234567890");
    typename TString::value_type const *cstr = s.data();
    EXPECT_EQ(0, TTraitsType::compare(cstr, &s[0], s.size()));
    EXPECT_TRUE(TTraitsType::eq(typename TString::value_type(), cstr[s.size()]));
  }
  {
    TString                             s("12345678901");
    typename TString::value_type const *cstr = s.data();
    EXPECT_EQ(0, TTraitsType::compare(cstr, &s[0], s.size()));
    EXPECT_TRUE(TTraitsType::eq(typename TString::value_type(), cstr[s.size()]));
  }
  {
    TString                             s("123456789012");
    typename TString::value_type const *cstr = s.data();
    EXPECT_EQ(0, TTraitsType::compare(cstr, &s[0], s.size()));
    EXPECT_TRUE(TTraitsType::eq(typename TString::value_type(), cstr[s.size()]));
  }
  {
    TString                             s("1234567890123456789012");
    typename TString::value_type const *cstr = s.data();
    EXPECT_EQ(0, TTraitsType::compare(cstr, &s[0], s.size()));
    EXPECT_TRUE(TTraitsType::eq(typename TString::value_type(), cstr[s.size()]));
  }
  {
    TString                             s("12345678901234567890123");
    typename TString::value_type const *cstr = s.data();
    EXPECT_EQ(0, TTraitsType::compare(cstr, &s[0], s.size()));
    EXPECT_TRUE(TTraitsType::eq(typename TString::value_type(), cstr[s.size()]));
  }
  {
    TString                             s("123456789012345678901234");
    typename TString::value_type const *cstr = s.data();
    EXPECT_EQ(0, TTraitsType::compare(cstr, &s[0], s.size()));
    EXPECT_TRUE(TTraitsType::eq(typename TString::value_type(), cstr[s.size()]));
  }
}

TEST(basic_string, at) {
  static_cast<void>(test_info_);

  {
    EXPECT_EQ(test_string_helper::test_string1[0], test_string_helper::s1.at(0));
    EXPECT_EQ(test_string_helper::test_string1[5], test_string_helper::s1.at(5));

    EXPECT_EQ(test_string_helper::test_string2[0], test_string_helper::s2.at(0));
    EXPECT_EQ(test_string_helper::test_string2[49], test_string_helper::s2.at(49));

    EXPECT_TRUE((std::is_same<typename TString::reference, decltype(test_string_helper::s1.at(0))>{}));
  }
  {
    EXPECT_EQ(test_string_helper::test_string1[0], test_string_helper::cs1.at(0));
    EXPECT_EQ(test_string_helper::test_string1[5], test_string_helper::cs1.at(5));

    EXPECT_EQ(test_string_helper::test_string2[0], test_string_helper::cs2.at(0));
    EXPECT_EQ(test_string_helper::test_string2[49], test_string_helper::cs2.at(49));

    EXPECT_TRUE((std::is_same<typename TString::const_reference, decltype(test_string_helper::cs1.at(0))>{}));
  }
  {
    try {
      test_string_helper::s1.at(10);
      EXPECT_TRUE(false);
    } catch (::portable_stl::out_of_range<> &) {
    }
    try {
      test_string_helper::s2.at(60);
      EXPECT_TRUE(false);
    } catch (::portable_stl::out_of_range<> &) {
    }
  }
  {
    try {
      test_string_helper::cs1.at(10);
      EXPECT_TRUE(false);
    } catch (::portable_stl::out_of_range<> &) {
    }
    try {
      test_string_helper::cs2.at(60);
      EXPECT_TRUE(false);
    } catch (::portable_stl::out_of_range<> &) {
    }
  }
}

TEST(basic_string, index) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  EXPECT_TRUE((std::is_same<typename TString::reference, decltype(test_string_helper::s1[1])>{}));
  EXPECT_TRUE((std::is_same<typename TString::const_reference, decltype(test_string_helper::cs1[2])>{}));

  for (::portable_stl::size_t i{0}; i < test_string_helper::s1.size(); ++i) {
    EXPECT_EQ(test_string_helper::test_string1[i], test_string_helper::s1[i]);
    EXPECT_EQ(test_string_helper::test_string1[i], test_string_helper::cs1[i]);
  }
  for (::portable_stl::size_t i{0}; i < test_string_helper::s2.size(); ++i) {
    EXPECT_EQ(test_string_helper::test_string2[i], test_string_helper::s2[i]);
    EXPECT_EQ(test_string_helper::test_string2[i], test_string_helper::cs2[i]);
  }

  EXPECT_EQ('\0', test_string_helper::s1[test_string_helper::s1.size()]);
  EXPECT_EQ('\0', test_string_helper::cs1[test_string_helper::cs1.size()]);
  EXPECT_EQ('\0', test_string_helper::s2[test_string_helper::s2.size()]);
  EXPECT_EQ('\0', test_string_helper::cs2[test_string_helper::cs2.size()]);

  {
    TString s("123456789132456798123"); // SSO
    EXPECT_EQ('\0', s[s.size()]);
  }
  {
    TString s("1234567891324567981234"); // SSO
    EXPECT_EQ('\0', s[s.size()]);
  }
  {
    TString s("12345678913245679812345"); // no SSO
    EXPECT_EQ('\0', s[s.size()]);
  }
}

TEST(basic_string, front) {
  static_cast<void>(test_info_);

  EXPECT_EQ(test_string_helper::test_string1[0], test_string_helper::s1.front());
  EXPECT_EQ(test_string_helper::test_string1[0], test_string_helper::cs1.front());
  EXPECT_EQ(test_string_helper::test_string2[0], test_string_helper::s2.front());
  EXPECT_EQ(test_string_helper::test_string2[0], test_string_helper::cs2.front());

  EXPECT_TRUE((std::is_same<typename TString::reference, decltype(test_string_helper::s2.front())>{}));
  EXPECT_TRUE((std::is_same<typename TString::const_reference, decltype(test_string_helper::cs2.front())>{}));

  EXPECT_TRUE(noexcept(test_string_helper::s1.front()));
  EXPECT_TRUE(noexcept(test_string_helper::cs1.front()));

  auto sz = static_cast<typename decltype(test_string_helper::s1)::difference_type>(test_string_helper::s1.size());
  EXPECT_EQ(0, *(test_string_helper::s1.begin() + sz));
}

TEST(basic_string, back) {
  static_cast<void>(test_info_);

  ASSERT_EQ(6, test_string_helper::s1.size());
  ASSERT_EQ(6, test_string_helper::cs1.size());
  ASSERT_EQ(50, test_string_helper::s2.size());
  ASSERT_EQ(50, test_string_helper::cs2.size());

  EXPECT_EQ(test_string_helper::test_string1[test_string_helper::s1.size() - 1], test_string_helper::s1.back());
  EXPECT_EQ(test_string_helper::test_string1[test_string_helper::cs1.size() - 1], test_string_helper::cs1.back());
  EXPECT_EQ(test_string_helper::test_string2[test_string_helper::s2.size() - 1], test_string_helper::s2.back());
  EXPECT_EQ(test_string_helper::test_string2[test_string_helper::cs2.size() - 1], test_string_helper::cs2.back());

  EXPECT_TRUE((std::is_same<typename TString::reference, decltype(test_string_helper::s2.back())>{}));
  EXPECT_TRUE((std::is_same<typename TString::const_reference, decltype(test_string_helper::cs2.back())>{}));

  EXPECT_TRUE(noexcept(test_string_helper::s1.back()));
  EXPECT_TRUE(noexcept(test_string_helper::cs1.back()));
}

// [iterators]

TEST(basic_string, begin) {
  static_cast<void>(test_info_);

  auto b1  = test_string_helper::s1.begin();
  auto cb1 = test_string_helper::s1.begin();
  auto b2  = test_string_helper::s2.begin();
  auto cb2 = test_string_helper::s2.begin();

  EXPECT_EQ(test_string_helper::test_string1[0], *b1);
  EXPECT_EQ(test_string_helper::test_string1[0], *cb1);
  EXPECT_EQ(test_string_helper::test_string2[0], *b2);
  EXPECT_EQ(test_string_helper::test_string2[0], *cb2);

  EXPECT_EQ(b1, cb1);
  EXPECT_EQ(b2, cb2);

  EXPECT_TRUE((std::is_same<typename TString::iterator, decltype(test_string_helper::s1.begin())>{}));
  EXPECT_TRUE((std::is_same<typename TString::const_iterator, decltype(test_string_helper::cs1.begin())>{}));
}

TEST(basic_string, cbegin) {
  static_cast<void>(test_info_);

  auto b1  = test_string_helper::s1.cbegin();
  auto cb1 = test_string_helper::s1.cbegin();
  auto b2  = test_string_helper::s2.cbegin();
  auto cb2 = test_string_helper::s2.cbegin();

  EXPECT_EQ(test_string_helper::test_string1[0], *b1);
  EXPECT_EQ(test_string_helper::test_string1[0], *cb1);
  EXPECT_EQ(test_string_helper::test_string2[0], *b2);
  EXPECT_EQ(test_string_helper::test_string2[0], *cb2);

  EXPECT_EQ(b1, cb1);
  EXPECT_EQ(b2, cb2);

  EXPECT_TRUE((std::is_same<typename TString::const_iterator, decltype(test_string_helper::s1.cbegin())>{}));
  EXPECT_TRUE((std::is_same<typename TString::const_iterator, decltype(test_string_helper::cs1.cbegin())>{}));
}

TEST(basic_string, end) {
  static_cast<void>(test_info_);

  auto e1  = test_string_helper::s1.end();
  auto ce1 = test_string_helper::s1.end();
  auto e2  = test_string_helper::s2.end();
  auto ce2 = test_string_helper::s2.end();

  EXPECT_EQ(test_string_helper::s1.size(), static_cast<std::size_t>(e1 - test_string_helper::s1.begin()));
  EXPECT_EQ(test_string_helper::s1.size(), static_cast<std::size_t>(ce1 - test_string_helper::s1.begin()));
  EXPECT_EQ(test_string_helper::s2.size(), static_cast<std::size_t>(e2 - test_string_helper::s2.begin()));
  EXPECT_EQ(test_string_helper::s2.size(), static_cast<std::size_t>(ce2 - test_string_helper::s2.begin()));

  EXPECT_EQ(e1, ce1);
  EXPECT_EQ(e2, ce2);

  EXPECT_TRUE((std::is_same<typename TString::iterator, decltype(test_string_helper::s1.end())>{}));
  EXPECT_TRUE((std::is_same<typename TString::const_iterator, decltype(test_string_helper::cs1.end())>{}));
}

TEST(basic_string, cend) {
  static_cast<void>(test_info_);

  auto e1  = test_string_helper::s1.cend();
  auto ce1 = test_string_helper::s1.cend();
  auto e2  = test_string_helper::s2.cend();
  auto ce2 = test_string_helper::s2.cend();

  EXPECT_EQ(test_string_helper::s1.size(), static_cast<std::size_t>(e1 - test_string_helper::s1.begin()));
  EXPECT_EQ(test_string_helper::s1.size(), static_cast<std::size_t>(ce1 - test_string_helper::s1.begin()));
  EXPECT_EQ(test_string_helper::s2.size(), static_cast<std::size_t>(e2 - test_string_helper::s2.begin()));
  EXPECT_EQ(test_string_helper::s2.size(), static_cast<std::size_t>(ce2 - test_string_helper::s2.begin()));

  EXPECT_EQ(e1, ce1);
  EXPECT_EQ(e2, ce2);

  EXPECT_TRUE((std::is_same<typename TString::const_iterator, decltype(test_string_helper::s1.cend())>{}));
  EXPECT_TRUE((std::is_same<typename TString::const_iterator, decltype(test_string_helper::cs1.cend())>{}));
}

TEST(basic_string, rbegin) {
  static_cast<void>(test_info_);

  auto rb1  = test_string_helper::s1.rbegin();
  auto crb1 = test_string_helper::s1.rbegin();
  auto rb2  = test_string_helper::s2.rbegin();
  auto crb2 = test_string_helper::s2.rbegin();

  EXPECT_EQ(test_string_helper::s1.back(), *rb1);
  EXPECT_EQ(test_string_helper::s1.back(), *crb1);
  EXPECT_EQ(test_string_helper::s2.back(), *rb2);
  EXPECT_EQ(test_string_helper::s2.back(), *crb2);

  EXPECT_EQ(rb1, crb1);
  EXPECT_EQ(rb2, crb2);

  EXPECT_TRUE((std::is_same<typename TString::reverse_iterator, decltype(test_string_helper::s1.rbegin())>{}));
  EXPECT_TRUE((std::is_same<typename TString::const_reverse_iterator, decltype(test_string_helper::cs1.rbegin())>{}));
}

TEST(basic_string, crbegin) {
  static_cast<void>(test_info_);

  auto rb1  = test_string_helper::s1.crbegin();
  auto crb1 = test_string_helper::s1.crbegin();
  auto rb2  = test_string_helper::s2.crbegin();
  auto crb2 = test_string_helper::s2.crbegin();

  EXPECT_EQ(test_string_helper::s1.back(), *rb1);
  EXPECT_EQ(test_string_helper::s1.back(), *crb1);
  EXPECT_EQ(test_string_helper::s2.back(), *rb2);
  EXPECT_EQ(test_string_helper::s2.back(), *crb2);

  EXPECT_EQ(rb1, crb1);
  EXPECT_EQ(rb2, crb2);

  EXPECT_TRUE((std::is_same<typename TString::const_reverse_iterator, decltype(test_string_helper::s1.crbegin())>{}));
  EXPECT_TRUE((std::is_same<typename TString::const_reverse_iterator, decltype(test_string_helper::cs1.crbegin())>{}));
}

TEST(basic_string, rend) {
  static_cast<void>(test_info_);

  auto re1  = test_string_helper::s1.rend();
  auto cre1 = test_string_helper::s1.rend();
  auto re2  = test_string_helper::s2.rend();
  auto cre2 = test_string_helper::s2.rend();

  EXPECT_EQ(test_string_helper::s1.size(), static_cast<std::size_t>(re1 - test_string_helper::s1.rbegin()));
  EXPECT_EQ(test_string_helper::s1.size(), static_cast<std::size_t>(cre1 - test_string_helper::s1.rbegin()));
  EXPECT_EQ(test_string_helper::s2.size(), static_cast<std::size_t>(re2 - test_string_helper::s2.rbegin()));
  EXPECT_EQ(test_string_helper::s2.size(), static_cast<std::size_t>(cre2 - test_string_helper::s2.rbegin()));

  EXPECT_EQ(re1, cre1);
  EXPECT_EQ(re2, cre2);

  EXPECT_TRUE((std::is_same<typename TString::reverse_iterator, decltype(test_string_helper::s1.rend())>{}));
  EXPECT_TRUE((std::is_same<typename TString::const_reverse_iterator, decltype(test_string_helper::cs1.rend())>{}));
}

TEST(basic_string, crend) {
  static_cast<void>(test_info_);

  auto re1  = test_string_helper::s1.crend();
  auto cre1 = test_string_helper::s1.crend();
  auto re2  = test_string_helper::s2.crend();
  auto cre2 = test_string_helper::s2.crend();

  EXPECT_EQ(test_string_helper::s1.size(), static_cast<std::size_t>(re1 - test_string_helper::s1.rbegin()));
  EXPECT_EQ(test_string_helper::s1.size(), static_cast<std::size_t>(cre1 - test_string_helper::s1.rbegin()));
  EXPECT_EQ(test_string_helper::s2.size(), static_cast<std::size_t>(re2 - test_string_helper::s2.rbegin()));
  EXPECT_EQ(test_string_helper::s2.size(), static_cast<std::size_t>(cre2 - test_string_helper::s2.rbegin()));

  EXPECT_EQ(re1, cre1);
  EXPECT_EQ(re2, cre2);

  EXPECT_TRUE((std::is_same<typename TString::const_reverse_iterator, decltype(test_string_helper::s1.crend())>{}));
  EXPECT_TRUE((std::is_same<typename TString::const_reverse_iterator, decltype(test_string_helper::cs1.crend())>{}));

  {
    TString       empty;
    TString const const_empty;

    EXPECT_EQ(empty.rend(), empty.rbegin());
    EXPECT_EQ(empty.crend(), empty.crbegin());
    EXPECT_EQ(const_empty.rend(), const_empty.rbegin());
    EXPECT_EQ(const_empty.crend(), const_empty.crbegin());
  }
}
