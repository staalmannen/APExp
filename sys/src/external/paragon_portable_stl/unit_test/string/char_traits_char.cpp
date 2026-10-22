// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="char_traits_char.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "portable_stl/string/char_traits.h"

using t_char_type      = char;
using test_char_traits = ::portable_stl::char_traits<t_char_type>;

namespace test_string_helper {} // namespace test_string_helper

TEST(char_traits_char, access2) {
  static_cast<void>(test_info_);

  {
    t_char_type chr{'\0'};
    test_char_traits::assign(chr, 'a');
    EXPECT_EQ('a', chr);
  }
}

TEST(char_traits_char, access3) {
  static_cast<void>(test_info_);
  {
    t_char_type s2[]{'\0', '\0', '\0'};
    EXPECT_EQ(s2, test_char_traits::assign(s2, 3, 'a'));

    EXPECT_EQ('a', s2[0]);
    EXPECT_EQ('a', s2[1]);
    EXPECT_EQ('a', s2[2]);
  }

  EXPECT_EQ(nullptr, test_char_traits::assign(nullptr, 0, 'a'));
}

TEST(char_traits_char, compare) {
  static_cast<void>(test_info_);

  EXPECT_EQ(test_char_traits::compare("", "", 0), 0);
  EXPECT_EQ(test_char_traits::compare(nullptr, nullptr, 0), 0);

  EXPECT_EQ(test_char_traits::compare("a", "a", 1), 0);
  EXPECT_LT(test_char_traits::compare("a", "b", 1), 0);
  EXPECT_GT(test_char_traits::compare("b", "a", 1), 0);

  // compare only first code unit (,1). Ther are same x\d0
  EXPECT_EQ(test_char_traits::compare("б", "б", 1), 0); // x\d0 x\b1 and x\d0 x\b1 ==
  EXPECT_EQ(test_char_traits::compare("б", "в", 1), 0); // x\d0 x\b1 and x\d0 x\b2 ==
  EXPECT_EQ(test_char_traits::compare("в", "б", 1), 0); // x\d0 x\b2 and x\d0 x\b1 ==

  // compare only first code unit (,1). Ther are x\d0 and x\d1
  EXPECT_EQ(test_char_traits::compare("б", "б", 1), 0); // x\d0 x\b1 and x\d0 x\b1
  EXPECT_LT(test_char_traits::compare("б", "я", 1), 0); // x\d0 x\b1 and x\d1 x\8f
  EXPECT_GT(test_char_traits::compare("я", "б", 1), 0); // x\d1 x\8f and x\d0 x\b1

  // compare both code units (,2)
  EXPECT_EQ(test_char_traits::compare("б", "б", 2), 0); // x\d0 x\b1 and x\d0 x\b1
  EXPECT_LT(test_char_traits::compare("б", "в", 2), 0); // x\d0 x\b1 and x\d0 x\b2
  EXPECT_GT(test_char_traits::compare("в", "б", 2), 0); // x\d0 x\b2 and x\d0 x\b1

  EXPECT_EQ(test_char_traits::compare("б", "б", 2), 0); // x\d0 x\b1 and x\d0 x\b1
  EXPECT_LT(test_char_traits::compare("б", "я", 2), 0); // x\d0 x\b1 and x\d1 x\8f
  EXPECT_GT(test_char_traits::compare("я", "б", 2), 0); // x\d1 x\8f and x\d0 x\b1

  EXPECT_EQ(test_char_traits::compare("ab", "ab", 2), 0);
  EXPECT_LT(test_char_traits::compare("ab", "ac", 2), 0);
  EXPECT_LT(test_char_traits::compare("ab", "bb", 2), 0);
  EXPECT_GT(test_char_traits::compare("ac", "ab", 2), 0);
  EXPECT_GT(test_char_traits::compare("bb", "ab", 2), 0);

  EXPECT_EQ(test_char_traits::compare("byz¥ðбяࠀ℉𐀀𑊰𝄞😅", "byz¥ðбяࠀ℉𐀀𑊰𝄞😅", 34), 0);
  EXPECT_LT(test_char_traits::compare("abc", "bbc", 3), 0);
  EXPECT_LT(test_char_traits::compare("abc", "acc", 3), 0);
  EXPECT_LT(test_char_traits::compare("abc", "abd", 3), 0);
  EXPECT_GT(test_char_traits::compare("bbc", "abc", 3), 0);
  EXPECT_GT(test_char_traits::compare("acc", "abc", 3), 0);
  EXPECT_GT(test_char_traits::compare("abd", "abc", 3), 0);

  {
    t_char_type a[]{static_cast<t_char_type>(-1), 0};
    t_char_type b[]{1, 0};
    EXPECT_GT(test_char_traits::compare(a, b, 1), 0);
  }
}

TEST(char_traits_char, copy) {
  static_cast<void>(test_info_);

  t_char_type s1[]{'a', 'b', 'c'};
  t_char_type s2[]{'\0', '\0', '\0'};

  EXPECT_EQ(s2, test_char_traits::copy(s2, s1, 3));

  EXPECT_EQ('a', s2[0]);
  EXPECT_EQ('b', s2[1]);
  EXPECT_EQ('c', s2[2]);

  EXPECT_EQ(nullptr, test_char_traits::copy(nullptr, s1, 0));
  EXPECT_EQ(s1, test_char_traits::copy(s1, nullptr, 0));
}

TEST(char_traits_char, eof) {
  static_cast<void>(test_info_);

  EXPECT_EQ(-1, test_char_traits::eof());
}

TEST(char_traits_char, not_eof) {
  static_cast<void>(test_info_);

  EXPECT_EQ(test_char_traits::not_eof('a'), 'a');
  EXPECT_EQ(test_char_traits::not_eof('A'), 'A');
  EXPECT_EQ(test_char_traits::not_eof(0), 0);
  EXPECT_NE(test_char_traits::not_eof(test_char_traits::eof()), test_char_traits::eof());
}

TEST(char_traits_char, eq) {
  static_cast<void>(test_info_);

  EXPECT_TRUE(test_char_traits::eq('a', 'a'));
  EXPECT_FALSE(test_char_traits::eq('a', 'A'));
}

TEST(char_traits_char, lt) {
  static_cast<void>(test_info_);

  EXPECT_EQ(test_char_traits::lt('\0', 'A'), ('\0' < 'A'));
  EXPECT_EQ(test_char_traits::lt('A', '\0'), ('A' < '\0'));

  EXPECT_EQ(test_char_traits::lt('a', 'a'), ('a' < 'a'));
  EXPECT_EQ(test_char_traits::lt('A', 'a'), ('A' < 'a'));
  EXPECT_EQ(test_char_traits::lt('a', 'A'), ('a' < 'A'));

  EXPECT_EQ(test_char_traits::lt('a', 'z'), ('a' < 'z'));
  EXPECT_EQ(test_char_traits::lt('A', 'Z'), ('A' < 'Z'));

  EXPECT_EQ(test_char_traits::lt(' ', 'A'), (' ' < 'A'));
  EXPECT_EQ(test_char_traits::lt('A', '~'), ('A' < '~'));
}

TEST(char_traits_char, eq_int_type) {
  static_cast<void>(test_info_);

  EXPECT_TRUE(test_char_traits::eq_int_type('a', 'a'));
  EXPECT_FALSE(test_char_traits::eq_int_type('a', 'A'));

  EXPECT_FALSE(test_char_traits::eq_int_type(test_char_traits::eof(), 'A'));
  EXPECT_TRUE(test_char_traits::eq_int_type(test_char_traits::eof(), test_char_traits::eof()));
}

TEST(char_traits_char, find) {
  static_cast<void>(test_info_);

  {
    t_char_type const s1[]{'1', '2', '3'};
    EXPECT_EQ(test_char_traits::find(s1, 3, '1'), &s1[0]);
    EXPECT_EQ(test_char_traits::find(s1, 3, '2'), &s1[1]);
    EXPECT_EQ(test_char_traits::find(s1, 3, '3'), &s1[2]);
  }
  {
    t_char_type const s1[]{'1', '2', '3'};
    EXPECT_EQ(test_char_traits::find(s1, 2, '1'), &s1[0]);
    EXPECT_EQ(test_char_traits::find(s1, 2, '2'), &s1[1]);
    EXPECT_EQ(test_char_traits::find(s1, 2, '3'), nullptr);
  }
  {
    t_char_type const s1[]{'1', '2', '3'};
    EXPECT_EQ(test_char_traits::find(s1, 1, '1'), &s1[0]);
    EXPECT_EQ(test_char_traits::find(s1, 1, '2'), nullptr);
    EXPECT_EQ(test_char_traits::find(s1, 1, '3'), nullptr);
  }
  {
    t_char_type const s1[]{'1', '2', '3', '1', '2', '3'};
    EXPECT_EQ(test_char_traits::find(s1, 6, '1'), &s1[0]);
    EXPECT_EQ(test_char_traits::find(s1, 6, '2'), &s1[1]);
    EXPECT_EQ(test_char_traits::find(s1, 6, '3'), &s1[2]);
  }
  {
    t_char_type const s1[]{'1', '2', '3'};
    EXPECT_EQ(test_char_traits::find(s1, 3, 'z'), nullptr);
    EXPECT_EQ(test_char_traits::find(s1, 3, '\0'), nullptr);
  }

  EXPECT_EQ(test_char_traits::find(nullptr, 0, '\0'), nullptr);
}

TEST(char_traits_char, length) {
  static_cast<void>(test_info_);

  EXPECT_EQ(test_char_traits::length(""), 0);
  EXPECT_EQ(test_char_traits::length("a"), 1);
  EXPECT_EQ(test_char_traits::length("aa"), 2);
  EXPECT_EQ(test_char_traits::length("aaa"), 3);
  EXPECT_EQ(test_char_traits::length("aaaa"), 4);

  EXPECT_EQ(test_char_traits::length("я"), 2);
  EXPECT_EQ(test_char_traits::length("яя"), 4);
  EXPECT_EQ(test_char_traits::length("яяя"), 6);
  EXPECT_EQ(test_char_traits::length("яяяя"), 8);

  EXPECT_EQ(test_char_traits::length("℉"), 3);
  EXPECT_EQ(test_char_traits::length("℉℉"), 6);
  EXPECT_EQ(test_char_traits::length("℉℉℉"), 9);
  EXPECT_EQ(test_char_traits::length("℉℉℉℉"), 12);

  EXPECT_EQ(test_char_traits::length("𝄞"), 4);
  EXPECT_EQ(test_char_traits::length("𝄞𝄞"), 8);
  EXPECT_EQ(test_char_traits::length("𝄞𝄞𝄞"), 12);
  EXPECT_EQ(test_char_traits::length("𝄞𝄞𝄞𝄞"), 16);

  EXPECT_EQ(test_char_traits::length("aя"), 3);
  EXPECT_EQ(test_char_traits::length("a℉"), 4);
  EXPECT_EQ(test_char_traits::length("a𝄞"), 5);
  EXPECT_EQ(test_char_traits::length("я℉"), 5);
  EXPECT_EQ(test_char_traits::length("я𝄞"), 6);
  EXPECT_EQ(test_char_traits::length("℉𝄞"), 7);

  EXPECT_EQ(test_char_traits::length("byz¥ðбяࠀ℉𐀀𑊰𝄞😅"), 33);
}

TEST(char_traits_char, move) {
  static_cast<void>(test_info_);

  t_char_type s1[]{'a', 'b', 'c'};
  {
    EXPECT_EQ(test_char_traits::move(&s1[0], &s1[1], 2), &s1[0]);
    EXPECT_EQ(s1[0], 'b');
    EXPECT_EQ(s1[1], 'c');
    EXPECT_EQ(s1[2], 'c');

    s1[2] = '\0';
    EXPECT_EQ(test_char_traits::move(&s1[1], &s1[0], 2), &s1[1]);
    EXPECT_EQ(s1[0], 'b');
    EXPECT_EQ(s1[1], 'b');
    EXPECT_EQ(s1[2], 'c');
  }
  {
    EXPECT_EQ(test_char_traits::move(nullptr, &s1[0], 0), nullptr);
    EXPECT_EQ(test_char_traits::move(&s1[0], nullptr, 0), &s1[0]);
  }
}

TEST(char_traits_char, to_char_type) {
  static_cast<void>(test_info_);

  EXPECT_EQ(test_char_traits::to_char_type(97), 'a');
  EXPECT_EQ(test_char_traits::to_char_type(122), 'z');
  EXPECT_EQ(test_char_traits::to_char_type(0), '\0');
}

TEST(char_traits_char, to_int_type) {
  static_cast<void>(test_info_);

  EXPECT_EQ(test_char_traits::to_int_type('a'), 97);
  EXPECT_EQ(test_char_traits::to_int_type('z'), 122);
  EXPECT_EQ(test_char_traits::to_int_type('\0'), 0);
}
