// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="basic_string_capacity.cpp"
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

// [capacity]

// TEST(basic_string, size) {
//   static_cast<void>(test_info_);

//   EXPECT_EQ(0, TString().size());
//   EXPECT_EQ(6, test_string_helper::s1.size());
//   EXPECT_EQ(6, test_string_helper::cs1.size());
//   EXPECT_EQ(50, test_string_helper::s2.size());
//   EXPECT_EQ(50, test_string_helper::cs2.size());
// }

// TEST(basic_string, length) {
//   static_cast<void>(test_info_);

//   EXPECT_EQ(0, TString().length());
//   EXPECT_EQ(6, test_string_helper::s1.length());
//   EXPECT_EQ(6, test_string_helper::cs1.length());
//   EXPECT_EQ(50, test_string_helper::s2.length());
//   EXPECT_EQ(50, test_string_helper::cs2.length());

//   {
//     TString empty;

//     EXPECT_EQ(empty.size(), empty.length());
//     EXPECT_EQ(test_string_helper::s1.size(), test_string_helper::s1.length());
//     EXPECT_EQ(test_string_helper::cs1.size(), test_string_helper::cs1.length());
//     EXPECT_EQ(test_string_helper::s2.size(), test_string_helper::s2.length());
//     EXPECT_EQ(test_string_helper::cs2.size(), test_string_helper::cs2.length());
//   }
// }

// TEST(basic_string, empty) {
//   static_cast<void>(test_info_);

//   EXPECT_TRUE(TString().empty());

//   EXPECT_FALSE(test_string_helper::s1.empty());
//   EXPECT_FALSE(test_string_helper::cs1.empty());
//   EXPECT_FALSE(test_string_helper::s2.empty());
//   EXPECT_FALSE(test_string_helper::cs2.empty());
// }

// TEST(basic_string, capacity) {
//   static_cast<void>(test_info_);
//   TMManager::m_counter_ok_allocation = 100;

//   {
//     TString s;
//     EXPECT_LE(s.size(), s.capacity());
//     EXPECT_GT(s.capacity(), 1);
//   }
//   {
//     TString s{"a"};
//     EXPECT_LE(s.size(), s.capacity());
//   }
//   {
//     TString s{"1234567890"};
//     EXPECT_LE(s.size(), s.capacity());
//   }
//   {
//     TString s{"12345678901"};
//     EXPECT_LE(s.size(), s.capacity());
//   }
//   {
//     TString s{"1234567890123456789012"};
//     EXPECT_LE(s.size(), s.capacity());
//   }
//   {
//     TString s{"12345678901234567890123"};
//     EXPECT_LE(s.size(), s.capacity());
//   }
//   { EXPECT_LE(test_string_helper::s2.size(), test_string_helper::s2.capacity()); }
//   {
//     TString s1{"123"};
//     TString s2{"12346578"};
//     EXPECT_EQ(s1.capacity(), s2.capacity());
//   }

//   // do not shrink allocated memory
//   {
//     TString s{"1234567890123456789012345678901234567890"};
//     auto    cap1  = s.capacity();
//     auto    size1 = s.size();

//     s.replace(0, 10, "");
//     auto cap2  = s.capacity();
//     auto size2 = s.size();

//     EXPECT_NE(size1, size2);
//     EXPECT_EQ(cap1, cap2);
//   }
// }

// namespace test_string_erase_helper {
// void erase_index_count(
//   TString &str, typename TString::size_type index, typename TString::size_type count, TString const &expected) {
//   auto cap1 = str.capacity();

//   auto result = str.erase(index, count);

//   ASSERT_TRUE(result);
//   ASSERT_EQ(0, str.check_invariants()) << str.c_str();
//   EXPECT_LE(str.capacity(), cap1);
//   EXPECT_EQ(expected, str);
// }
// } // namespace test_string_erase_helper

// TEST(basic_string, erase_index_count) {
//   static_cast<void>(test_info_);
//   TMManager::m_counter_ok_allocation = 0;
//   {
//     TString s;
//     test_string_erase_helper::erase_index_count(s, 0, 100, TString(""));
//     EXPECT_EQ(0, s.size());
//     EXPECT_EQ(TString().capacity(), s.capacity());
//   }

//   {
//     TString s{"1234567890"};
//     test_string_erase_helper::erase_index_count(s, 0, 100, TString(""));
//     EXPECT_EQ(0, s.size());
//     EXPECT_EQ(TString().capacity(), s.capacity());
//   }
//   {
//     TString s{"1234567890"};
//     test_string_erase_helper::erase_index_count(s, 1, 100, TString("1"));
//     EXPECT_EQ(1, s.size());
//     EXPECT_EQ(TString().capacity(), s.capacity());
//   }
//   {
//     TString s{"1234567890"};
//     test_string_erase_helper::erase_index_count(s, 9, 100, TString("123456789"));
//     EXPECT_EQ(9, s.size());
//     EXPECT_EQ(TString().capacity(), s.capacity());
//   }
//   {
//     TString s{"1234567890"};
//     test_string_erase_helper::erase_index_count(s, 10, 100, TString("1234567890"));
//     EXPECT_EQ(10, s.size());
//     EXPECT_EQ(TString().capacity(), s.capacity());
//   }
//   {
//     TString s{"1234567890"};
//     test_string_erase_helper::erase_index_count(s, 5, 0, TString("1234567890"));
//     EXPECT_EQ(10, s.size());
//     EXPECT_EQ(TString().capacity(), s.capacity());
//   }
//   {
//     TString s{"1234567890"};
//     test_string_erase_helper::erase_index_count(s, 4, 4, TString("123490"));
//     EXPECT_EQ(6, s.size());
//     EXPECT_EQ(TString().capacity(), s.capacity());
//   }

//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString s{"1234567890123456789012"};
//     TMManager::m_counter_ok_allocation = 0;

//     test_string_erase_helper::erase_index_count(s, 0, 100, TString(""));
//     EXPECT_EQ(0, s.size());
//     EXPECT_EQ(TString().capacity(), s.capacity());
//   }
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString s{"1234567890123456789012"};
//     TMManager::m_counter_ok_allocation = 0;

//     test_string_erase_helper::erase_index_count(s, 1, 100, TString("1"));
//     EXPECT_EQ(1, s.size());
//     EXPECT_EQ(TString().capacity(), s.capacity());
//   }
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString       s{"1234567890123456789012"};
//     TString const ref{"123456789012345678901"};
//     TMManager::m_counter_ok_allocation = 0;

//     test_string_erase_helper::erase_index_count(s, 21, 100, ref);
//     EXPECT_EQ(21, s.size());
//   }
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString       s{"1234567890123456789012"};
//     TString const ref{"1234567890123456789012"};
//     TMManager::m_counter_ok_allocation = 0;

//     test_string_erase_helper::erase_index_count(s, 22, 100, ref);
//     EXPECT_EQ(22, s.size());
//   }
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString       s{"1234567890123456789012"};
//     TString const ref{"1234567890123456789012"};
//     TMManager::m_counter_ok_allocation = 0;

//     test_string_erase_helper::erase_index_count(s, 10, 0, ref);
//     EXPECT_EQ(22, s.size());
//   }
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString       s{"1234567890123456789012"};
//     TString const ref{"1234012"};
//     TMManager::m_counter_ok_allocation = 0;

//     test_string_erase_helper::erase_index_count(s, 4, 15, ref);
//     EXPECT_EQ(7, s.size());
//     EXPECT_EQ(TString().capacity(), s.capacity());
//   }

//   // cut on the edge SSO/no-SSO
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString s{"1234567890123456"};
//     TMManager::m_counter_ok_allocation = 0;

//     test_string_erase_helper::erase_index_count(s, 4, 10, TString("123456"));
//     EXPECT_EQ(6, s.size());
//     EXPECT_EQ(TString().capacity(), s.capacity());
//   }
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString s{"1234567890123456"};
//     TMManager::m_counter_ok_allocation = 0;

//     test_string_erase_helper::erase_index_count(s, 4, 6, TString("1234123456"));
//     EXPECT_EQ(10, s.size());
//     EXPECT_EQ(TString().capacity(), s.capacity());
//   }
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString       s{"1234aaaaa0123456"};
//     TString const ref{"12340123456"};
//     TMManager::m_counter_ok_allocation = 0;

//     test_string_erase_helper::erase_index_count(s, 4, 5, ref);
//     EXPECT_EQ(11, s.size());
//   }
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString       s{"12345aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa67890"};
//     TString const ref{"1234567890"};
//     TMManager::m_counter_ok_allocation = 0;

//     test_string_erase_helper::erase_index_count(s, 5, 30, ref);
//     EXPECT_EQ(10, s.size());
//     EXPECT_EQ(TString().capacity(), s.capacity());
//   }
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString       s{"123456aaaaaaaaaaaaaaaaaa7890123456789012"};
//     TString const ref{"1234567890123456789012"};
//     TMManager::m_counter_ok_allocation = 0;

//     test_string_erase_helper::erase_index_count(s, 6, 18, ref);
//     EXPECT_EQ(22, s.size());
//   }
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString       s{"123456aaaaaaaaaaaaaaaaaa78901234567890123"};
//     TString const ref{"12345678901234567890123"};
//     TMManager::m_counter_ok_allocation = 0;

//     test_string_erase_helper::erase_index_count(s, 6, 18, ref);
//     EXPECT_EQ(23, s.size());
//   }

//   // out of range
//   {
//     TMManager::m_counter_ok_allocation = 0;
//     TString s{"123465789"};

//     auto result = s.erase(10, 0);
//     ASSERT_FALSE(result);
//     EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());

//     ASSERT_EQ(0, s.check_invariants());
//     EXPECT_EQ(TString("123465789"), s);
//   }
// }

// TEST(basic_string, erase_iter) {
//   static_cast<void>(test_info_);
//   TMManager::m_counter_ok_allocation = 0;
//   {
//     TString s("1234_5678");

//     auto result = s.erase(s.cbegin() + 4);

//     ASSERT_TRUE(result);
//     ASSERT_EQ(0, s.check_invariants());
//     EXPECT_EQ(TString("12345678"), s);
//   }
//   {
//     TString s("_12345678");

//     auto result = s.erase(s.cbegin());

//     ASSERT_TRUE(result);
//     ASSERT_EQ(0, s.check_invariants());
//     EXPECT_EQ(TString("12345678"), s);
//   }
//   {
//     TString s("12345678_");

//     auto result = s.erase(s.cend() - 1);

//     ASSERT_TRUE(result);
//     ASSERT_EQ(0, s.check_invariants());
//     EXPECT_EQ(TString("12345678"), s);
//   }
// }

// TEST(basic_string, erase_iter_iter) {
//   static_cast<void>(test_info_);
//   TMManager::m_counter_ok_allocation = 0;
//   {
//     TString s("123456789");

//     auto result = s.erase(s.cbegin(), s.cend());

//     ASSERT_TRUE(result);
//     ASSERT_EQ(0, s.check_invariants());
//     EXPECT_EQ(TString(""), s);
//   }
//   {
//     TString s("123456789");

//     auto result = s.erase(s.cbegin(), s.cbegin());

//     ASSERT_TRUE(result);
//     ASSERT_EQ(0, s.check_invariants());
//     EXPECT_EQ(TString("123456789"), s);
//   }
//   {
//     TString s("1____2345");

//     auto result = s.erase(s.cbegin() + 1, s.cbegin() + 5);

//     ASSERT_TRUE(result);
//     ASSERT_EQ(0, s.check_invariants());
//     EXPECT_EQ(TString("12345"), s);
//   }
// }

// TEST(basic_string, clear) {
//   static_cast<void>(test_info_);
//   {
//     TString s("123456789");
//     TMManager::m_counter_ok_allocation = 0;

//     s.clear();

//     ASSERT_EQ(0, s.check_invariants());
//     EXPECT_EQ(TString(""), s);
//     EXPECT_EQ(TString().capacity(), s.capacity());
//   }
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString s("1234567890123456789012345678901234567890");
//     TMManager::m_counter_ok_allocation = 0;

//     s.clear();

//     ASSERT_EQ(0, s.check_invariants());
//     EXPECT_EQ(TString(""), s);
//     EXPECT_EQ(TString().capacity(), s.capacity());
//   }
// }

// TEST(basic_string, pop_back) {
//   static_cast<void>(test_info_);

//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString s{"123456789012345678901234567890"};
//     TString const ref{"12345678901234567890123456789"};

//     TMManager::m_counter_ok_allocation = 0;
//     EXPECT_TRUE(s.pop_back());

//     EXPECT_EQ(ref, s);
//   }
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString s{"12345678901234567890123"};
//     TString const ref{"1234567890123456789012"};

//     TMManager::m_counter_ok_allocation = 0;
//     EXPECT_TRUE(s.pop_back());

//     EXPECT_EQ(ref, s);
//   }
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString s{"12345678901"};
//     TString const ref{"1234567890"};

//     TMManager::m_counter_ok_allocation = 0;
//     EXPECT_TRUE(s.pop_back());

//     EXPECT_EQ(ref, s);
//   }
//   {
//     TString s{"a"};

//     TMManager::m_counter_ok_allocation = 0;
//     EXPECT_TRUE(s.pop_back());

//     EXPECT_EQ(TString(), s);
//   }
//   {
//     TString s{""};

//     TMManager::m_counter_ok_allocation = 0;
//     EXPECT_FALSE(s.pop_back());

//     EXPECT_EQ(TString(), s);
//   }
// }

// TEST(basic_string, reserve) {
//   static_cast<void>(test_info_);

//   {
//     TMManager::m_counter_ok_allocation = 0;
//     TString s;

//     EXPECT_TRUE(s.reserve(0));

//     ASSERT_EQ(0, s.check_invariants());
//     EXPECT_EQ(TString().capacity(), s.capacity());
//   }
//   {
//     TMManager::m_counter_ok_allocation = 0;
//     TString s;

//     EXPECT_TRUE(s.reserve(10));

//     ASSERT_EQ(0, s.check_invariants());
//     EXPECT_EQ(TString().capacity(), s.capacity());
//   }
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString s;

//     EXPECT_TRUE(s.reserve(100));

//     ASSERT_EQ(0, s.check_invariants());
//     EXPECT_EQ(100, s.capacity());
//   }
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString s{test_string_helper::s2};
//     TMManager::m_counter_ok_allocation = 0;

//     auto const size1 = s.size();
//     auto const cap1  = s.capacity();

//     EXPECT_TRUE(s.reserve(0));

//     ASSERT_EQ(0, s.check_invariants());
//     EXPECT_EQ(cap1, s.capacity());
//     EXPECT_EQ(size1, s.size());
//   }
//   // no new allocation
//   {
//     TMManager::m_counter_ok_allocation = 0;
//     TString s{"12345"};

//     EXPECT_TRUE(s.reserve(9));

//     ASSERT_EQ(0, s.check_invariants());
//     EXPECT_EQ(TString().capacity(), s.capacity());
//   }
//   // new allocation
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString s{"12345"};

//     EXPECT_TRUE(s.reserve(16));

//     ASSERT_EQ(0, s.check_invariants());
//     EXPECT_GE(s.capacity(), 16);
//   }
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString s{"1234567890123"};

//     EXPECT_TRUE(s.reserve(26));

//     ASSERT_EQ(0, s.check_invariants());
//     EXPECT_EQ(26, s.capacity());
//   }
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString s{test_string_helper::s2};

//     EXPECT_TRUE(s.reserve(100));

//     ASSERT_EQ(0, s.check_invariants());
//     EXPECT_EQ(100, s.capacity());
//   }
//   // bad allocation
//   {
//     TMManager::m_counter_ok_allocation = 0;
//     TString s{"12345"};

//     ASSERT_FALSE(s.reserve(26));

//     ASSERT_EQ(0, s.check_invariants());
//     EXPECT_EQ(TString().capacity(), s.capacity());
//   }
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString s{test_string_helper::s2};
//     TMManager::m_counter_ok_allocation = 0;

//     ASSERT_FALSE(s.reserve(100));

//     ASSERT_EQ(0, s.check_invariants());
//     EXPECT_EQ(51, s.capacity());
//   }
// }

TEST(basic_string, shrink_to_fit) {
  static_cast<void>(test_info_);

  TMManager::m_counter_ok_allocation = 0;
  {
    TString s;

    EXPECT_TRUE(s.shrink_to_fit());

    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(TString().capacity(), s.capacity());
  }
  {
    TString s{"1"};

    EXPECT_TRUE(s.shrink_to_fit());

    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(TString().capacity(), s.capacity());
  }
  {
    TString s{"1234567890"};

    EXPECT_TRUE(s.shrink_to_fit());

    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(TString().capacity(), s.capacity());
  }
  {
    TString s;
    TMManager::m_counter_ok_allocation = 100;
    s.reserve(50);
    TMManager::m_counter_ok_allocation = 0;
    ASSERT_EQ(0, s.check_invariants());
    ASSERT_EQ(50, s.capacity());

    EXPECT_TRUE(s.shrink_to_fit());

    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(TString().capacity(), s.capacity());
  }
  {
    TString s{"1234567890"};
    TMManager::m_counter_ok_allocation = 100;
    s.reserve(50);
    TMManager::m_counter_ok_allocation = 0;
    ASSERT_EQ(0, s.check_invariants());
    ASSERT_EQ(50, s.capacity());

    EXPECT_TRUE(s.shrink_to_fit());

    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(TString("1234567890"), s);
    EXPECT_EQ(TString().capacity(), s.capacity());
  }
  {
    TMManager::m_counter_ok_allocation = 100;
    TString       s{"123456789012345678901234567890"};
    TString const ref{s};
    s.reserve(50);
    ASSERT_EQ(0, s.check_invariants());
    ASSERT_EQ(50, s.capacity());

    EXPECT_TRUE(s.shrink_to_fit()); // reallocate memory

    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(ref, s);
  }

  // bad reallocation
  {
    TMManager::m_counter_ok_allocation = 100;
    TString       s{"123456789012345678901234567890"};
    TString const ref{s};
    s.reserve(50);
    ASSERT_EQ(0, s.check_invariants());
    ASSERT_EQ(50, s.capacity());

    TMManager::m_counter_ok_allocation = 0;
    EXPECT_FALSE(s.shrink_to_fit()); // reallocate memory

    ASSERT_EQ(0, s.check_invariants());
    EXPECT_EQ(ref, s);
    EXPECT_EQ(50, s.capacity());
  }
}

// namespace test_string_erase_helper {
// void resize_size(TString str, typename TString::size_type size, TString const &expected) {
//   ASSERT_EQ(0, str.check_invariants());

//   auto result = str.resize(size);

//   ASSERT_TRUE(result);
//   ASSERT_EQ(0, str.check_invariants()) << str.c_str();
//   EXPECT_EQ(size, str.size());
//   EXPECT_EQ(expected, str);
// }

// void resize_size_char(
//   TString str, typename TString::size_type size, typename TString::value_type ch, TString const &expected) {
//   ASSERT_EQ(0, str.check_invariants());

//   auto result = str.resize(size, ch);

//   ASSERT_TRUE(result);
//   ASSERT_EQ(0, str.check_invariants()) << str.c_str();
//   EXPECT_EQ(size, str.size());
//   EXPECT_EQ(expected, str);
// }
// } // namespace test_string_erase_helper

// TEST(basic_string, resize_size) {
//   static_cast<void>(test_info_);

//   TMManager::m_counter_ok_allocation = 0;
//   test_string_erase_helper::resize_size(TString(), 0, TString());
//   test_string_erase_helper::resize_size(TString(), 1, TString(1, '\0'));
//   test_string_erase_helper::resize_size(TString(), 10, TString(10, '\0'));

//   TMManager::m_counter_ok_allocation = 100;
//   test_string_erase_helper::resize_size(TString(), 22, TString(22, '\0'));
//   test_string_erase_helper::resize_size(TString(), 100, TString(100, '\0'));

//   TMManager::m_counter_ok_allocation = 0;
//   test_string_erase_helper::resize_size(TString("12345"), 0, TString());
//   test_string_erase_helper::resize_size(TString("12345"), 2, TString("12"));
//   test_string_erase_helper::resize_size(TString("12345"), 5, TString("12345"));

//   TMManager::m_counter_ok_allocation = 100;
//   test_string_erase_helper::resize_size(
//     TString("12345"), 25, TString("12345\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 25));

//   test_string_erase_helper::resize_size(test_string_helper::s2, 0, TString());
//   test_string_erase_helper::resize_size(test_string_helper::s2, 10, TString("1234567890"));
//   test_string_erase_helper::resize_size(test_string_helper::s2, 11, TString("12345678901"));
//   test_string_erase_helper::resize_size(test_string_helper::s2, 22, TString("1234567890123456789012"));
//   test_string_erase_helper::resize_size(test_string_helper::s2, 23, TString("12345678901234567890123"));
//   test_string_erase_helper::resize_size(test_string_helper::s2, 50, test_string_helper::s2);

//   // bad allocation
//   {
//     TMManager::m_counter_ok_allocation = 0;
//     TString s{};

//     EXPECT_FALSE(s.resize(25));
//   }
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString s{test_string_helper::s2};
//     TMManager::m_counter_ok_allocation = 0;

//     EXPECT_FALSE(s.resize(55));
//   }
//   // but...
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString s{test_string_helper::s2};
//     TMManager::m_counter_ok_allocation = 0;

//     EXPECT_TRUE(s.resize(25));
//     EXPECT_TRUE(s.resize(30));
//     EXPECT_TRUE(s.resize(50));
//   }
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString s{test_string_helper::s2};
//     TMManager::m_counter_ok_allocation = 0;

//     EXPECT_TRUE(s.resize(40));
//     EXPECT_TRUE(s.resize(30));
//     EXPECT_TRUE(s.resize(10));
//     EXPECT_FALSE(s.resize(25));
//   }
// }

// TEST(basic_string, resize_size_char) {
//   static_cast<void>(test_info_);

//   TMManager::m_counter_ok_allocation = 0;
//   test_string_erase_helper::resize_size_char(TString(), 0, 'a', TString());
//   test_string_erase_helper::resize_size_char(TString(), 1, 'a', TString(1, 'a'));
//   test_string_erase_helper::resize_size_char(TString(), 10, 'a', TString(10, 'a'));

//   TMManager::m_counter_ok_allocation = 100;
//   test_string_erase_helper::resize_size_char(TString(), 22, 'a', TString(22, 'a'));
//   test_string_erase_helper::resize_size_char(TString(), 100, 'a', TString(100, 'a'));

//   TMManager::m_counter_ok_allocation = 0;
//   test_string_erase_helper::resize_size_char(TString("12345"), 0, 'a', TString());
//   test_string_erase_helper::resize_size_char(TString("12345"), 2, 'a', TString("12"));
//   test_string_erase_helper::resize_size_char(TString("12345"), 5, 'a', TString("12345"));

//   TMManager::m_counter_ok_allocation = 100;
//   test_string_erase_helper::resize_size_char(TString("12345"), 25, 'a', TString("12345aaaaaaaaaaaaaaaaaaaa", 25));

//   test_string_erase_helper::resize_size_char(test_string_helper::s2, 0, 'a', TString());
//   test_string_erase_helper::resize_size_char(test_string_helper::s2, 10, 'a', TString("1234567890"));
//   test_string_erase_helper::resize_size_char(test_string_helper::s2, 11, 'a', TString("12345678901"));
//   test_string_erase_helper::resize_size_char(test_string_helper::s2, 22, 'a', TString("1234567890123456789012"));
//   test_string_erase_helper::resize_size_char(test_string_helper::s2, 23, 'a', TString("12345678901234567890123"));
//   test_string_erase_helper::resize_size_char(test_string_helper::s2, 50, 'a', test_string_helper::s2);

//   // bad allocation
//   {
//     TMManager::m_counter_ok_allocation = 0;
//     TString s{};

//     EXPECT_FALSE(s.resize(25, 'a'));
//   }
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString s{test_string_helper::s2};
//     TMManager::m_counter_ok_allocation = 0;

//     EXPECT_FALSE(s.resize(55, 'a'));
//   }
//   // but...
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString s{test_string_helper::s2};
//     TMManager::m_counter_ok_allocation = 0;

//     EXPECT_TRUE(s.resize(25, 'a'));
//     EXPECT_TRUE(s.resize(30, 'a'));
//     EXPECT_TRUE(s.resize(50, 'a'));
//   }
//   {
//     TMManager::m_counter_ok_allocation = 100;
//     TString s{test_string_helper::s2};
//     TMManager::m_counter_ok_allocation = 0;

//     EXPECT_TRUE(s.resize(40, 'a'));
//     EXPECT_TRUE(s.resize(30, 'a'));
//     EXPECT_TRUE(s.resize(10, 'a'));
//     EXPECT_FALSE(s.resize(25, 'a'));
//   }
// }
