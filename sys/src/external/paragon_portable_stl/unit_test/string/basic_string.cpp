// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="basic_string.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "basic_string_test_helper.h"
#include "portable_stl/common/ptrdiff_t.h"
#include "portable_stl/common/size_t.h"
#include "portable_stl/string/string.h"

// [constructors]

// (1)
TEST(basic_string, constr_default_stateless_allocator) {
  static_cast<void>(test_info_);

  TString s;
  EXPECT_TRUE(s.empty());
  EXPECT_EQ(0, s.check_invariants());
}

// (1)
TEST(basic_string, constr_default_state_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator with state.
   */
  using TestStringType
    = ::portable_stl::basic_string<t_char_type, ::portable_stl::char_traits<t_char_type>, StateAllocator<t_char_type>>;

  TestStringType s;
  EXPECT_TRUE(s.empty());
  EXPECT_EQ(0, s.check_invariants());
}

// (2)
TEST(basic_string, constr_allocator_stateless) {
  static_cast<void>(test_info_);

  TMManager alloc{};
  TString   s{alloc};
  EXPECT_TRUE(s.empty());
  EXPECT_EQ(0, s.check_invariants());
}

// (2)
TEST(basic_string, constr_state_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator with state.
   */
  using TestStringType
    = ::portable_stl::basic_string<t_char_type, ::portable_stl::char_traits<t_char_type>, StateAllocator<t_char_type>>;

  StateAllocator<t_char_type> alloc{1};
  TestStringType              s(alloc);
  // EXPECT_EQ(1, s.get_allocator().getData());
  EXPECT_TRUE(s.empty());
  EXPECT_EQ(0, s.check_invariants());
}

// (3)
TEST(basic_string, constr_char_count) {
  static_cast<void>(test_info_);

  TMManager::m_counter_ok_allocation = 0;
  {
    TString s(0, 'a');
    EXPECT_TRUE("" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(1, 'a');
    EXPECT_TRUE("a" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(test_string_helper::chars_in_SSO - 1, 'a');
    EXPECT_EQ(test_string_helper::chars_in_SSO - 1, s.size());
    EXPECT_TRUE('a' == s.front());
    EXPECT_TRUE('a' == s.back());
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    EXPECT_EQ(test_string_helper::chars_in_SSO, s.size());
    EXPECT_TRUE(test_string_helper::test_string_of_a_SSO == s);
    EXPECT_EQ(0, s.check_invariants());
  }

  // NO SSO
  TMManager::m_counter_ok_allocation = 100;
  {
    TString s(test_string_helper::chars_in_SSO, 'a');
    EXPECT_EQ(test_string_helper::chars_in_SSO, s.size());
    EXPECT_TRUE('a' == s.front());
    EXPECT_TRUE('a' == s.back());
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(test_string_helper::chars_in_SSO + 1, 'a');
    EXPECT_EQ(test_string_helper::chars_in_SSO + 1, s.size());
    EXPECT_TRUE('a' == s.front());
    EXPECT_TRUE('a' == s.back());
    EXPECT_EQ(0, s.check_invariants());
  }

  // bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;

    try {
      TString s(25, 'a');
      EXPECT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
      EXPECT_TRUE(true);
    }

    TMManager::m_counter_ok_allocation = 100;
  }
}

TEST(basic_string, make_char_count) {
  static_cast<void>(test_info_);
  TString s;
  TMManager::m_counter_ok_allocation = 0;
  {
    auto result = TString::make_string(0, 'a');

    ASSERT_TRUE(result);
    EXPECT_EQ(0, result.value().size());
    EXPECT_TRUE("" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(5, 'a');

    ASSERT_TRUE(result);
    EXPECT_EQ(5, result.value().size());
    EXPECT_TRUE("aaaaa" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(test_string_helper::chars_in_SSO, 'a');

    ASSERT_TRUE(result);
    EXPECT_EQ(test_string_helper::chars_in_SSO, result.value().size());
    EXPECT_TRUE(test_string_helper::test_string_of_a_SSO == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }

  // NO SSO
  TMManager::m_counter_ok_allocation = 100;
  {
    auto result = TString::make_string(test_string_helper::chars_in_SSO + 1, 'a');

    ASSERT_TRUE(result);
    EXPECT_EQ(test_string_helper::chars_in_SSO + 1, result.value().size());
    EXPECT_TRUE('a' == result.value().front());
    EXPECT_TRUE('a' == result.value().back());
    EXPECT_EQ(0, result.value().check_invariants());
  }

  // bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;
    auto result                        = TString::make_string(25, 'a');

    ASSERT_FALSE(result);
    ASSERT_EQ(result.error(), ::portable_stl::portable_stl_error::allocate_error);
    TMManager::m_counter_ok_allocation = 100;
  }
}

// (4-5)
TEST(basic_string, constr_string_pos) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 0;

  TString s0("");
  {
    TString s(s0, 0);
    ASSERT_EQ(0, s.size());
    EXPECT_TRUE("" == s);
    EXPECT_EQ(0, s.check_invariants());
  }

  TString s1("a");
  {
    TString s(s1, 0);
    ASSERT_EQ(01, s.size());
    EXPECT_TRUE("a" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(s1, 1);
    ASSERT_EQ(0, s.size());
    EXPECT_TRUE("" == s);
    EXPECT_EQ(0, s.check_invariants());
  }

  TString s2("abc");
  {
    TString s(s2, 0);
    ASSERT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(s2, 1);
    ASSERT_EQ(2, s.size());
    EXPECT_TRUE("bc" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(s2, 2);
    ASSERT_EQ(1, s.size());
    EXPECT_TRUE("c" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(s2, 3);
    ASSERT_EQ(0, s.size());
    EXPECT_TRUE("" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(TString("abc"), 0);
    ASSERT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(test_string_helper::s2, 50 - test_string_helper::chars_in_SSO);
    ASSERT_EQ(test_string_helper::chars_in_SSO, s.size());
    EXPECT_TRUE('0' == s.back());
    EXPECT_EQ(0, s.check_invariants());
  }

  // NO SSO
  TMManager::m_counter_ok_allocation = 100;
  {
    TString s(test_string_helper::s2, 27);
    ASSERT_EQ(23, s.size());
    EXPECT_TRUE("89012345678901234567890" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(test_string_helper::s2, 0);
    ASSERT_EQ(50, s.size());
    EXPECT_TRUE(test_string_helper::test_string2 == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(test_string_helper::s2, 20);
    ASSERT_EQ(30, s.size());
    EXPECT_TRUE("123456789012345678901234567890" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(TString("123456789012345678901234567890"), 0);
    ASSERT_EQ(30, s.size());
    EXPECT_TRUE("123456789012345678901234567890" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  // start position out of range
  {
    try {
      TString s(test_string_helper::s1, 10);
      EXPECT_TRUE(false);
    } catch (::portable_stl::out_of_range<> &e) {
      static_cast<void>(e);
    }
  }
  // start position out of range
  {
    try {
      TString s(test_string_helper::s2, 51);
      EXPECT_TRUE(false);
    } catch (::portable_stl::out_of_range<> &e) {
      static_cast<void>(e);
    }
  }
  // bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;

    try {
      TString s(test_string_helper::s2, 0);
      EXPECT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }

    TMManager::m_counter_ok_allocation = 100;
  }
  // start position out of range before bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;

    try {
      TString s(test_string_helper::s2, 51);
      EXPECT_TRUE(false);
    } catch (::portable_stl::out_of_range<> &e) {
      static_cast<void>(e);
    }

    TMManager::m_counter_ok_allocation = 100;
  }
}

TEST(basic_string, make_string_pos) {
  static_cast<void>(test_info_);

  TString s0("");
  {
    auto result = TString::make_string(s0, 0);

    ASSERT_TRUE(result);
    ASSERT_EQ(0, result.value().size());
    EXPECT_TRUE("" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }

  TString s1("a");
  {
    auto result = TString::make_string(s1, 0);

    ASSERT_TRUE(result);
    ASSERT_EQ(1, result.value().size());
    EXPECT_TRUE("a" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(s1, 1);

    ASSERT_TRUE(result);
    ASSERT_EQ(0, result.value().size());
    EXPECT_TRUE("" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }

  TString s2("abc");
  {
    auto result = TString::make_string(s2, 0);

    ASSERT_TRUE(result);
    ASSERT_EQ(3, result.value().size());
    EXPECT_TRUE("abc" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(s2, 1);

    ASSERT_TRUE(result);
    ASSERT_EQ(2, result.value().size());
    EXPECT_TRUE("bc" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(s2, 2);

    ASSERT_TRUE(result);
    ASSERT_EQ(1, result.value().size());
    EXPECT_TRUE("c" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(s2, 3);

    ASSERT_TRUE(result);
    ASSERT_EQ(0, result.value().size());
    EXPECT_TRUE("" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(test_string_helper::s2, 28);

    ASSERT_TRUE(result);
    ASSERT_EQ(22, result.value().size());
    EXPECT_TRUE("9012345678901234567890" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }

  // NO SSO
  TMManager::m_counter_ok_allocation = 100;
  {
    auto result = TString::make_string(test_string_helper::s2, 27);

    ASSERT_TRUE(result);
    ASSERT_EQ(23, result.value().size());
    EXPECT_TRUE("89012345678901234567890" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }

  // TString s2("12345678901234567890123456789012345678901234567890");
  {
    auto result = TString::make_string(test_string_helper::s2, 0);

    ASSERT_TRUE(result);
    ASSERT_EQ(50, result.value().size());
    EXPECT_TRUE(test_string_helper::test_string2 == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(test_string_helper::s2, 35);

    ASSERT_TRUE(result);
    ASSERT_EQ(15, result.value().size());
    EXPECT_TRUE("678901234567890" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }

  // start position out of range
  {
    auto result = TString::make_string(s2, 10);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }

  // start position out of range
  {
    TMManager::m_counter_ok_allocation = 100;

    auto result = TString::make_string(test_string_helper::s1, 10);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }

  // bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;

    auto result = TString::make_string(test_string_helper::s2, 0);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    TMManager::m_counter_ok_allocation = 100;
  }

  // start position out of range before bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;

    auto result = TString::make_string(test_string_helper::s2, 51);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());

    TMManager::m_counter_ok_allocation = 100;
  }
}

// (6-7)
TEST(basic_string, constr_string_pos_count) {
  static_cast<void>(test_info_);

  TString s0("");
  {
    TString s(s0, 0, 0);
    EXPECT_TRUE("" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(s0, 0, 10);
    EXPECT_TRUE("" == s);
    EXPECT_EQ(0, s.check_invariants());
  }

  TString s1("a");
  {
    TString s(s1, 0, 0);
    EXPECT_TRUE("" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(s1, 0, 1);
    EXPECT_TRUE("a" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(s1, 0, 10);
    EXPECT_TRUE("a" == s);
    EXPECT_EQ(0, s.check_invariants());
  }

  TString s2("abc");
  {
    TString s(s2, 0, 0);
    EXPECT_TRUE("" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(s2, 0, 10);
    EXPECT_TRUE("abc" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(s2, 1, 10);
    EXPECT_TRUE("bc" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(s2, 2, 10);
    EXPECT_TRUE("c" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(s2, 3, 10);
    EXPECT_TRUE("" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(TString("abc"), 1, 2);
    EXPECT_TRUE("bc" == s);
  }

  TString s3("1234567890123456789012345");
  {
    TString s(s3, 0, 25);
    EXPECT_TRUE("1234567890123456789012345" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(s3, 10, 25);
    EXPECT_TRUE("123456789012345" == s);
    EXPECT_EQ(0, s.check_invariants());
  }

  // start position out of range
  {
    try {
      TString s(s2, 10, 1);
      EXPECT_TRUE(false);
    } catch (::portable_stl::out_of_range<> &e) {
      static_cast<void>(e);
    }
  }
  // start position out of range
  {
    try {
      TString s(s3, 50, 1);
      EXPECT_TRUE(false);
    } catch (::portable_stl::out_of_range<> &e) {
      static_cast<void>(e);
    }
  }
  // bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;

    try {
      TString s(s3, 0, 25);
      EXPECT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }

    TMManager::m_counter_ok_allocation = 100;
  }
  // start position out of range before bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;

    try {
      TString s(s3, 50, 25);
      EXPECT_TRUE(false);
    } catch (::portable_stl::out_of_range<> &e) {
      static_cast<void>(e);
    }

    TMManager::m_counter_ok_allocation = 100;
  }
}

TEST(basic_string, make_string_pos_count) {
  static_cast<void>(test_info_);

  TString s0("");
  {
    auto result = TString::make_string(s0, 0, 0);

    ASSERT_TRUE(result);
    ASSERT_EQ(0, result.value().size());
    EXPECT_TRUE("" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(s0, 0, 10);

    ASSERT_TRUE(result);
    ASSERT_EQ(0, result.value().size());
    EXPECT_TRUE("" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }

  TString s1("a");
  {
    auto result = TString::make_string(s1, 0, 1);

    ASSERT_TRUE(result);
    ASSERT_EQ(1, result.value().size());
    EXPECT_TRUE("a" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(s1, 1, 1);

    ASSERT_TRUE(result);
    ASSERT_EQ(0, result.value().size());
    EXPECT_TRUE("" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(s1, 0, 0);

    ASSERT_TRUE(result);
    ASSERT_EQ(0, result.value().size());
    EXPECT_TRUE("" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }

  TString s2("abc");
  {
    auto result = TString::make_string(s2, 0, 3);

    ASSERT_TRUE(result);
    ASSERT_EQ(3, result.value().size());
    EXPECT_TRUE("abc" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(s2, 1, 3);

    ASSERT_TRUE(result);
    ASSERT_EQ(2, result.value().size());
    EXPECT_TRUE("bc" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(s2, 0, 2);

    ASSERT_TRUE(result);
    ASSERT_EQ(2, result.value().size());
    EXPECT_TRUE("ab" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(s2, 2, 1);

    ASSERT_TRUE(result);
    ASSERT_EQ(1, result.value().size());
    EXPECT_TRUE("c" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(s2, 3, 1);

    ASSERT_TRUE(result);
    ASSERT_EQ(0, result.value().size());
    EXPECT_TRUE("" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }

  TMManager::m_counter_ok_allocation = 100;
  TString s3("1234567890123456789012345");
  {
    auto result = TString::make_string(s3, 0);

    ASSERT_TRUE(result);
    ASSERT_EQ(25, result.value().size());
    EXPECT_TRUE("1234567890123456789012345" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(s3, 0, 24);

    ASSERT_TRUE(result);
    ASSERT_EQ(24, result.value().size());
    EXPECT_TRUE("123456789012345678901234" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(s3, 10);

    ASSERT_TRUE(result);
    ASSERT_EQ(15, result.value().size());
    EXPECT_TRUE("123456789012345" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }

  // start position out of range
  {
    auto result = TString::make_string(s2, 10, 0);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }

  // start position out of range
  {
    TMManager::m_counter_ok_allocation = 100;

    auto result = TString::make_string(s2, 50, 0);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }

  // bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;

    auto result = TString::make_string(s3, 0, 25);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    TMManager::m_counter_ok_allocation = 100;
  }

  // start position out of range before bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;

    auto result = TString::make_string(s2, 50, 25);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());

    TMManager::m_counter_ok_allocation = 100;
  }
}

// (8)
TEST(basic_string, constr_pointer_len) {
  static_cast<void>(test_info_);

  {
    TString s("", 0);

    EXPECT_EQ(0, s.size());
    EXPECT_TRUE("" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s("abc", 0);

    EXPECT_EQ(0, s.size());
    EXPECT_TRUE("" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s("abc", 1);

    EXPECT_EQ(1, s.size());
    EXPECT_TRUE("a" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s("abc", 3);

    EXPECT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s("123456789012345678901234567890", 25);

    EXPECT_EQ(25, s.size());
    EXPECT_TRUE("1234567890123456789012345" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  // bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;

    try {
      TString s("123456789012345678901234567890", 25);
      EXPECT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }

    TMManager::m_counter_ok_allocation = 100;
  }
}

TEST(basic_string, make_pointer_len) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    auto result = TString::make_string("", 0);

    ASSERT_TRUE(result);
    EXPECT_EQ(0, result.value().size());
    EXPECT_TRUE("" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string("a", 1);

    ASSERT_TRUE(result);
    EXPECT_EQ(1, result.value().size());
    EXPECT_TRUE("a" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string("abc", 2);

    ASSERT_TRUE(result);
    EXPECT_EQ(2, result.value().size());
    EXPECT_TRUE("ab" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string("abc", 3);

    ASSERT_TRUE(result);
    EXPECT_EQ(3, result.value().size());
    EXPECT_TRUE("abc" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string("123456789012345678901234567890", 25);

    ASSERT_TRUE(result);
    EXPECT_EQ(25, result.value().size());
    EXPECT_TRUE("1234567890123456789012345" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  // bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;

    auto result = TString::make_string("123456789012345678901234567890", 25);

    ASSERT_FALSE(result);
    ASSERT_EQ(result.error(), ::portable_stl::portable_stl_error::allocate_error);
    TMManager::m_counter_ok_allocation = 100;
  }
}

// (9)
TEST(basic_string, constr_pointer) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    TString s("");

    EXPECT_EQ(0, s.size());
    EXPECT_TRUE("" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s("a");

    EXPECT_EQ(1, s.size());
    EXPECT_TRUE("a" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s("abc");

    EXPECT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s("abc\0def");

    EXPECT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s("1234567890123456789012345");

    EXPECT_EQ(25, s.size());
    EXPECT_TRUE("1234567890123456789012345" == s);
    EXPECT_EQ(0, s.check_invariants());
  }

  // pointer to non-const char
  {
    t_char_type arr[8] = "abc\0def";
    t_char_type *cstr = arr;
    TString s(cstr);
    EXPECT_TRUE("abc" == s);
    EXPECT_EQ(0, s.check_invariants());
  }

  // bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;

    try {
      TString s("123456789012345678901234567890");
      EXPECT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }
  }
}

TEST(basic_string, make_pointer) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    auto result = TString::make_string("");

    ASSERT_TRUE(result);
    EXPECT_EQ(0, result.value().size());
    EXPECT_TRUE("" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string("a");

    ASSERT_TRUE(result);
    EXPECT_EQ(1, result.value().size());
    EXPECT_TRUE("a" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string("abc");

    ASSERT_TRUE(result);
    EXPECT_EQ(3, result.value().size());
    EXPECT_TRUE("abc" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string("abc\0def");

    ASSERT_TRUE(result);
    EXPECT_EQ(3, result.value().size());
    EXPECT_TRUE("abc" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string("1234567890123456789012345");

    ASSERT_TRUE(result);
    EXPECT_TRUE("1234567890123456789012345" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  // bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;
    auto result                        = TString::make_string("1234567890123456789012345");

    ASSERT_FALSE(result);
    ASSERT_EQ(result.error(), ::portable_stl::portable_stl_error::allocate_error);
  }
}

// (10)
TEST(basic_string, constr_two_iterators) {
  static_cast<void>(test_info_);

  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(&test_string_helper::test_string2[0], &test_string_helper::test_string2[3]);

    EXPECT_EQ(3, s.size());
    EXPECT_TRUE("123" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s(&test_string_helper::test_string2[0], &test_string_helper::test_string2[25]);

    EXPECT_EQ(25, s.size());
    EXPECT_TRUE("1234567890123456789012345" == s);
    EXPECT_EQ(0, s.check_invariants());
  }

  // bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;

    try {
      TString s(&test_string_helper::test_string2[0], &test_string_helper::test_string2[25]);
      EXPECT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }
  }
}

TEST(basic_string, make_two_iterators) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    auto result = TString::make_string(&test_string_helper::test_string2[0], &test_string_helper::test_string2[3]);

    ASSERT_TRUE(result);
    EXPECT_EQ(3, result.value().size());
    EXPECT_TRUE("123" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(&test_string_helper::test_string2[0], &test_string_helper::test_string2[25]);

    ASSERT_TRUE(result);
    EXPECT_EQ(25, result.value().size());
    EXPECT_TRUE("1234567890123456789012345" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }

  // bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;
    auto result = TString::make_string(&test_string_helper::test_string2[0], &test_string_helper::test_string2[25]);

    ASSERT_FALSE(result);
    ASSERT_EQ(result.error(), ::portable_stl::portable_stl_error::allocate_error);
  }
}

// (11)
TEST(basic_string, constr_copy) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    TString s0("");
    TString s(s0);

    EXPECT_EQ(0, s.size());
    EXPECT_TRUE(s0 == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s0("abc");
    TString s(s0);

    EXPECT_EQ(3, s.size());
    EXPECT_TRUE(s0 == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s0("1234567890123456789012345");
    TString s(s0);

    EXPECT_EQ(25, s.size());
    EXPECT_TRUE(s0 == s);
    EXPECT_EQ(0, s.check_invariants());
  }

  // bad alloc
  {
    TString s0("1234567890123456789012345");
    TMManager::m_counter_ok_allocation = 0;

    try {
      TString s(s0);
      EXPECT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }
  }
}

TEST(basic_string, make_copy) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    TString s0("");
    auto    result = TString::make_string(s0);

    ASSERT_TRUE(result);
    EXPECT_EQ(0, result.value().size());
    EXPECT_TRUE("" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    TString s0("abc");
    auto    result = TString::make_string(s0);

    ASSERT_TRUE(result);
    EXPECT_EQ(3, result.value().size());
    EXPECT_TRUE("abc" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    TString s0("1234567890123456789012345");
    auto    result = TString::make_string(s0);

    ASSERT_TRUE(result);
    EXPECT_EQ(25, result.value().size());
    EXPECT_TRUE("1234567890123456789012345" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }

  // bad alloc
  {
    TString s0("1234567890123456789012345");
    TMManager::m_counter_ok_allocation = 0;

    auto result = TString::make_string(s0);

    ASSERT_FALSE(result);
    ASSERT_EQ(result.error(), ::portable_stl::portable_stl_error::allocate_error);
  }
}

// (12)
TEST(basic_string, constr_copy_with_allocator) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  TMManager alloc;
  {
    TString s0("");
    TString s(s0, alloc);

    EXPECT_EQ(0, s.size());
    EXPECT_TRUE(s0 == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s0("abc");
    TString s(s0, alloc);

    EXPECT_EQ(3, s.size());
    EXPECT_TRUE(s0 == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s0("1234567890123456789012345");
    TString s(s0, alloc);

    EXPECT_EQ(25, s.size());
    EXPECT_TRUE(s0 == s);
    EXPECT_EQ(0, s.check_invariants());
  }

  // bad alloc
  {
    TMManager::m_counter_ok_allocation = 100;
    TString s0("1234567890123456789012345");
    TMManager::m_counter_ok_allocation = 0;

    try {
      TString s(s0, alloc);
      EXPECT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }
  }
}

TEST(basic_string, make_copy_with_allocator) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;
  TMManager alloc;
  {
    TString s0("");
    auto    result = TString::make_string(s0, alloc);

    ASSERT_TRUE(result);
    EXPECT_EQ(0, result.value().size());
    EXPECT_TRUE("" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    TString s0("abc");
    auto    result = TString::make_string(s0, alloc);

    ASSERT_TRUE(result);
    EXPECT_EQ(3, result.value().size());
    EXPECT_TRUE("abc" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    TString s0("1234567890123456789012345");
    auto    result = TString::make_string(s0, alloc);

    ASSERT_TRUE(result);
    EXPECT_EQ(25, result.value().size());
    EXPECT_TRUE("1234567890123456789012345" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }

  // bad alloc
  {
    TString s0("1234567890123456789012345");
    TMManager::m_counter_ok_allocation = 0;

    auto result = TString::make_string(s0);

    ASSERT_FALSE(result);
    ASSERT_EQ(result.error(), ::portable_stl::portable_stl_error::allocate_error);
  }
}

// (13)
TEST(basic_string, constr_move) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;
  TMManager alloc;
  {
    TString s(TString(""), alloc);

    EXPECT_EQ(0, s.size());
    EXPECT_TRUE("" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(TString("abc"), alloc);

    EXPECT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(TString("1234567890123456789012345"), alloc);

    EXPECT_EQ(25, s.size());
    EXPECT_TRUE("1234567890123456789012345" == s);
    EXPECT_EQ(0, s.check_invariants());
  }

  // no bad alloc - move has no exception !!
  {
    TString s0("1234567890123456789012345");
    TMManager::m_counter_ok_allocation = 0;

    try {
      TString s(std::move(s0), alloc);
      EXPECT_EQ(0, s.check_invariants());
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
      EXPECT_TRUE(false);
    }
  }
}

// (14)
TEST(basic_string, constr_move_with_allocator) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;
  {
    TString s(TString(""));

    EXPECT_EQ(0, s.size());
    EXPECT_TRUE("" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(TString("abc"));

    EXPECT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(TString("1234567890123456789012345"));

    EXPECT_EQ(25, s.size());
    EXPECT_TRUE("1234567890123456789012345" == s);
    EXPECT_EQ(0, s.check_invariants());
  }

  // no bad alloc - storage move has no exception !!
  {
    TString s0("1234567890123456789012345");
    TMManager::m_counter_ok_allocation = 0;

    try {
      TString s(std::move(s0));
      EXPECT_EQ(0, s.check_invariants());
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
      EXPECT_TRUE(false);
    }
  }
}

// (15)
TEST(basic_string, constr_initializer_list) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;
  {
    TString s{'a', 'b', 'c'};

    EXPECT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s{'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3',
              '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5'};

    EXPECT_EQ(25, s.size());
    EXPECT_TRUE("1234567890123456789012345" == s);
    EXPECT_EQ(0, s.check_invariants());
  }

  // bad_alloc
  {
    TMManager::m_counter_ok_allocation = 0;

    try {
      TString s{'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3',
                '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5'};
      EXPECT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }
  }
}

TEST(basic_string, make_initializer_list) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    auto result = TString::make_string({'a', 'b', 'c'});

    ASSERT_TRUE(result);
    EXPECT_EQ(3, result.value().size());
    EXPECT_TRUE("abc" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string({'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3',
                                        '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5'});

    ASSERT_TRUE(result);
    EXPECT_EQ(25, result.value().size());
    EXPECT_TRUE("1234567890123456789012345" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }

  // bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;
    auto result = TString::make_string({'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3',
                                        '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5'});

    ASSERT_FALSE(result);
    ASSERT_EQ(result.error(), ::portable_stl::portable_stl_error::allocate_error);
  }
}

// (16)
TEST(basic_string, constr_string_view) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    TString s(TString::view_type(""));

    EXPECT_EQ(0, s.size());
    EXPECT_TRUE("" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(TString::view_type("a"));

    EXPECT_EQ(1, s.size());
    EXPECT_TRUE("a" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(TString::view_type("abc"));

    EXPECT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(TString::view_type("1234567890123456789012345"));

    EXPECT_EQ(25, s.size());
    EXPECT_TRUE("1234567890123456789012345" == s);
    EXPECT_EQ(0, s.check_invariants());
  }

  // bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;

    try {
      TString s(TString::view_type("1234567890123456789012345"));
      EXPECT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }
  }
}

TEST(basic_string, make_string_view) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    auto result = TString::make_string(TString::view_type(""));

    ASSERT_TRUE(result);
    EXPECT_EQ(0, result.value().size());
    EXPECT_TRUE("" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(TString::view_type("a"));

    ASSERT_TRUE(result);
    EXPECT_EQ(1, result.value().size());
    EXPECT_TRUE("a" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(TString::view_type("abc"));

    ASSERT_TRUE(result);
    EXPECT_EQ(3, result.value().size());
    EXPECT_TRUE("abc" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(TString::view_type("1234567890123456789012345"));

    ASSERT_TRUE(result);
    EXPECT_EQ(25, result.value().size());
    EXPECT_TRUE("1234567890123456789012345" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }

  // bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;

    auto result = TString::make_string(TString::view_type("1234567890123456789012345"));

    ASSERT_FALSE(result);
    ASSERT_EQ(result.error(), ::portable_stl::portable_stl_error::allocate_error);
  }
}

// (17)
TEST(basic_string, constr_string_view_pos_count) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    TString s(TString::view_type(""), 0, 0);

    EXPECT_EQ(0, s.size());
    EXPECT_TRUE("" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(TString::view_type(""), 0, 10);

    EXPECT_EQ(0, s.size());
    EXPECT_TRUE("" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(TString::view_type("a"), 0, 0);

    EXPECT_EQ(0, s.size());
    EXPECT_TRUE("" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(TString::view_type("a"), 0, 1);

    EXPECT_EQ(1, s.size());
    EXPECT_TRUE("a" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(TString::view_type("a"), 0, 10);

    EXPECT_EQ(1, s.size());
    EXPECT_TRUE("a" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(TString::view_type("abc"), 0, 0);

    EXPECT_EQ(0, s.size());
    EXPECT_TRUE("" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(TString::view_type("abc"), 0, 10);

    EXPECT_EQ(3, s.size());
    EXPECT_TRUE("abc" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(TString::view_type("abc"), 1, 10);

    EXPECT_EQ(2, s.size());
    EXPECT_TRUE("bc" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(TString::view_type("abc"), 2, 10);

    EXPECT_EQ(1, s.size());
    EXPECT_TRUE("c" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(TString::view_type("abc"), 3, 10);

    EXPECT_EQ(0, s.size());
    EXPECT_TRUE("" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(TString::view_type("1234567890123456789012345"), 0, 25);

    EXPECT_EQ(25, s.size());
    EXPECT_TRUE("1234567890123456789012345" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    TString s(TString::view_type("1234567890123456789012345"), 10, 25);

    EXPECT_EQ(15, s.size());
    EXPECT_TRUE("123456789012345" == s);
    EXPECT_EQ(0, s.check_invariants());
  }

  // start position out of range
  {
    TMManager::m_counter_ok_allocation = 0;

    try {
      TString s(TString::view_type("abc"), 4, 0);
      EXPECT_TRUE(false);
    } catch (::portable_stl::out_of_range<> &e) {
      static_cast<void>(e);
    }
  }

  // start position out of range
  {
      TMManager::m_counter_ok_allocation = 100;
    try {
      TString s(TString::view_type("1234567890123456789012345"), 50, 1);
      EXPECT_TRUE(false);
    } catch (::portable_stl::out_of_range<> &e) {
      static_cast<void>(e);
    }
  }

  // bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;
    try {
      TString s(TString::view_type("123456789012345678901234567890"), 0, 25);
      EXPECT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }
  }

  // start position out of range before bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;
    try {
      TString s(TString::view_type("123456789012345678901234567890"), 50, 25);
      EXPECT_TRUE(false);
    } catch (::portable_stl::out_of_range<> &e) {
      static_cast<void>(e);
    }
  }
}

TEST(basic_string, make_string_view_pos_count) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    auto result = TString::make_string(TString::view_type(""), 0, 0);

    ASSERT_TRUE(result);
    EXPECT_TRUE("" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(TString::view_type(""), 0, 10);

    ASSERT_TRUE(result);
    EXPECT_TRUE("" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(TString::view_type("a"), 0, 0);

    ASSERT_TRUE(result);
    EXPECT_TRUE("" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(TString::view_type("a"), 0, 1);

    ASSERT_TRUE(result);
    EXPECT_TRUE("a" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(TString::view_type("a"), 0, 10);

    ASSERT_TRUE(result);
    EXPECT_TRUE("a" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(TString::view_type("abc"), 0, 0);

    ASSERT_TRUE(result);
    EXPECT_TRUE("" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(TString::view_type("abc"), 0, 10);

    ASSERT_TRUE(result);
    EXPECT_TRUE("abc" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(TString::view_type("abc"), 1, 10);

    ASSERT_TRUE(result);
    EXPECT_TRUE("bc" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(TString::view_type("abc"), 2, 10);

    ASSERT_TRUE(result);
    EXPECT_TRUE("c" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(TString::view_type("abc"), 3, 10);

    ASSERT_TRUE(result);
    EXPECT_TRUE("" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(TString::view_type("1234567890123456789012345"), 0, 25);

    ASSERT_TRUE(result);
    EXPECT_TRUE("1234567890123456789012345" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = TString::make_string(TString::view_type("1234567890123456789012345"), 10, 25);

    ASSERT_TRUE(result);
    EXPECT_TRUE("123456789012345" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  // start position out of range
  {
    auto result = TString::make_string(TString::view_type("abc"), 10, 0);

    ASSERT_FALSE(result);
    EXPECT_EQ(result.error(), ::portable_stl::portable_stl_error::out_of_range);
  }
  // start position out of range
  {
    auto result = TString::make_string(TString::view_type("1234567890123456789012345"), 50, 5);

    ASSERT_FALSE(result);
    EXPECT_EQ(result.error(), ::portable_stl::portable_stl_error::out_of_range);
  }
  // bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;

    auto result = TString::make_string(TString::view_type("1234567890123456789012345"), 0, 25);

    ASSERT_FALSE(result);

    EXPECT_EQ(result.error(), ::portable_stl::portable_stl_error::allocate_error);
  }
  // start position out of range before bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;

    auto result = TString::make_string(TString::view_type("1234567890123456789012345"), 50, 5);

    ASSERT_FALSE(result);

    EXPECT_EQ(result.error(), ::portable_stl::portable_stl_error::out_of_range);
  }
}

TEST(basic_string, substr) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  TString s0("123456789");
  {
    auto s = s0.substr(0);

    EXPECT_EQ(9, s.size());
    EXPECT_TRUE("123456789" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    auto s = s0.substr(1);

    EXPECT_EQ(8, s.size());
    EXPECT_TRUE("23456789" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    auto s = s0.substr(8);

    EXPECT_EQ(1, s.size());
    EXPECT_TRUE("9" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    auto s = s0.substr(9);

    EXPECT_EQ(0, s.size());
    EXPECT_TRUE("" == s);
    EXPECT_EQ(0, s.check_invariants());
  }

  TString long_s0("1234567890123456789012345");

  // allocation
  {
    auto s = long_s0.substr(0);

    EXPECT_EQ(25, s.size());
    EXPECT_TRUE("1234567890123456789012345" == s);
    EXPECT_EQ(0, s.check_invariants());
  }

  // start position out of range
  {
    try {
      auto s = s0.substr(10); // short string
      EXPECT_TRUE(false);
    } catch (::portable_stl::out_of_range<> &e) {
      static_cast<void>(e);
    }
  }

  // bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;

    try {
      auto s = long_s0.substr(0);
      EXPECT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }
  }

  // start position out of range before bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;

    try {
      auto s = long_s0.substr(26);
      EXPECT_TRUE(false);
    } catch (::portable_stl::out_of_range<> &e) {
      static_cast<void>(e);
    }
  }
}

TEST(basic_string, substr_rvalue) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;

  {
    auto s = TString("123456789").substr(0);

    EXPECT_EQ(9, s.size());
    EXPECT_TRUE("123456789" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    auto s = TString("123456789").substr(1);

    EXPECT_EQ(8, s.size());
    EXPECT_TRUE("23456789" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    auto s = TString("123456789").substr(8);

    EXPECT_EQ(1, s.size());
    EXPECT_TRUE("9" == s);
    EXPECT_EQ(0, s.check_invariants());
  }
  {
    auto s = TString("123456789").substr(9);

    EXPECT_EQ(0, s.size());
    EXPECT_TRUE("" == s);
    EXPECT_EQ(0, s.check_invariants());
  }

  // allocation
  {
    TString long_s0("1234567890123456789012345");
    TMManager::m_counter_ok_allocation = 100;

    auto s = std::move(long_s0).substr(0);

    EXPECT_EQ(25, s.size());
    EXPECT_TRUE("1234567890123456789012345" == s);
    EXPECT_EQ(0, s.check_invariants());
  }

  // start position out of range
  {
    try {
      auto s = TString("123456789").substr(10); // short string
      EXPECT_TRUE(false);
    } catch (::portable_stl::out_of_range<> &e) {
      static_cast<void>(e);
    }
  }

  // bad_alloc
  {
    TString long_s0("1234567890123456789012345");
    TMManager::m_counter_ok_allocation = 0;

    try {
      auto s = std::move(long_s0).substr(0);
      EXPECT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }
  }

  // start position out of range before bad alloc
  {
    TMManager::m_counter_ok_allocation = 100;
    TString long_s0("1234567890123456789012345");
    TMManager::m_counter_ok_allocation = 0;

    try {
      auto s = std::move(long_s0).substr(51);
      EXPECT_TRUE(false);
    } catch (::portable_stl::out_of_range<> &e) {
      static_cast<void>(e);
    }
  }
}

TEST(basic_string, substr_safe) {
  static_cast<void>(test_info_);
  TMManager::m_counter_ok_allocation = 100;
  TString s0("123456789");
  {
    auto result = s0.substr_safe(0);

    ASSERT_TRUE(result);
    EXPECT_TRUE("123456789" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = s0.substr_safe(1);

    ASSERT_TRUE(result);
    EXPECT_TRUE("23456789" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = s0.substr_safe(8);

    ASSERT_TRUE(result);
    EXPECT_TRUE("9" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  {
    auto result = s0.substr_safe(9);

    ASSERT_TRUE(result);
    EXPECT_TRUE("" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }

  TString long_s0("1234567890123456789012345");

  // allocation
  {
    auto result = long_s0.substr_safe(0);

    ASSERT_TRUE(result);
    EXPECT_TRUE("1234567890123456789012345" == result.value());
    EXPECT_EQ(0, result.value().check_invariants());
  }
  // start position out of range
  {
    auto result = s0.substr_safe(10); // short string

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  // bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;
    auto result                        = long_s0.substr_safe(0);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }
  // start position out of range before bad alloc
  {
    TMManager::m_counter_ok_allocation = 0;
    auto result                        = long_s0.substr_safe(26);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
}

TEST(basic_string, copy) {
  static_cast<void>(test_info_);

  {
    TMManager::m_counter_ok_allocation = 100;
    TString s{"aaa1234567890bbb"};
    auto    ptr = std::make_unique<t_char_type[]>(50);
    memset(ptr.get(), '_', 20);

    auto result = s.copy(ptr.get(), 10, 3);

    ASSERT_TRUE(result);
    EXPECT_EQ(10, result.value());
    EXPECT_EQ(TStringView(ptr.get(), 10), "1234567890");

    {
      result = s.copy(ptr.get(), 3, 50);

      ASSERT_FALSE(result);
      EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
    }
  }
}

namespace test_string_replace_helper {
static void test_swap(TString str1, TString str2) {
  TMManager::m_counter_ok_allocation = 100;
  ASSERT_EQ(0, str1.check_invariants());
  ASSERT_EQ(0, str2.check_invariants());

  TString s1{str1};
  TString s2{str2};

  swap(str1, str2);

  ASSERT_EQ(0, str1.check_invariants());
  ASSERT_EQ(0, str2.check_invariants());

  EXPECT_EQ(s1, str2);
  EXPECT_EQ(s2, str1);
}
} // namespace test_string_replace_helper

TEST(basic_string, swap) {
  static_cast<void>(test_info_);

  test_string_replace_helper::test_swap(TString(""), TString(""));
  test_string_replace_helper::test_swap(TString(""), TString("12345"));
  test_string_replace_helper::test_swap(TString(""), TString("1234567890"));
  test_string_replace_helper::test_swap(TString(""), TString("12345678901"));
  test_string_replace_helper::test_swap(TString(""), TString("1234567890123456789012"));
  test_string_replace_helper::test_swap(TString(""), TString("12345678901234567890123"));
  test_string_replace_helper::test_swap(TString(""), TString(test_string_helper::s2));

  test_string_replace_helper::test_swap(TString("a2345"), TString("b2345"));
  test_string_replace_helper::test_swap(TString("12345"), TString("1234567890"));
  test_string_replace_helper::test_swap(TString("12345"), TString("12345678901"));
  test_string_replace_helper::test_swap(TString("12345"), TString("1234567890123456789012"));
  test_string_replace_helper::test_swap(TString("12345"), TString("12345678901234567890123"));
  test_string_replace_helper::test_swap(TString("12345"), TString(test_string_helper::s2));

  test_string_replace_helper::test_swap(TString("a234567890"), TString("b234567890"));
  test_string_replace_helper::test_swap(TString("1234567890"), TString("12345678901"));
  test_string_replace_helper::test_swap(TString("1234567890"), TString("1234567890123456789012"));
  test_string_replace_helper::test_swap(TString("1234567890"), TString("12345678901234567890123"));
  test_string_replace_helper::test_swap(TString("1234567890"), TString(test_string_helper::s2));

  test_string_replace_helper::test_swap(TString("a2345678901"), TString("b2345678901"));
  test_string_replace_helper::test_swap(TString("12345678901"), TString("1234567890123456789012"));
  test_string_replace_helper::test_swap(TString("12345678901"), TString("12345678901234567890123"));
  test_string_replace_helper::test_swap(TString("12345678901"), TString(test_string_helper::s2));

  test_string_replace_helper::test_swap(TString("a234567890123456789012"), TString("b234567890123456789012"));
  test_string_replace_helper::test_swap(TString("1234567890123456789012"), TString("12345678901234567890123"));
  test_string_replace_helper::test_swap(TString("1234567890123456789012"), TString(test_string_helper::s2));

  test_string_replace_helper::test_swap(TString("a2345678901234567890123"), TString("b2345678901234567890123"));
  test_string_replace_helper::test_swap(TString("12345678901234567890123"), TString(test_string_helper::s2));

  test_string_replace_helper::test_swap(TString(test_string_helper::s2) + 'a', TString(test_string_helper::s2) + 'b');
}
