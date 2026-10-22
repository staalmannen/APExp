// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="test_char_traits_char8_t.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************

#ifndef PSTL_TEST_CHAR_TRAITS_CHAR8_T_H
#define PSTL_TEST_CHAR_TRAITS_CHAR8_T_H

#include <gtest/gtest.h>
#include "portable_stl/string/char_traits.h"

using t_char_type      = char8_t;
using test_char_traits = ::portable_stl::char_traits<t_char_type>;

namespace test_string {
// clang-format off
inline void char_traits_char8_t_access2() {
  t_char_type chr{u8'\0'};
  test_char_traits::assign(chr, u8'a');
  EXPECT_EQ(u8'a', chr);
}

inline void char_traits_char8_t_access3() {
  {
    t_char_type s2[3]{u8'\0', u8'\0', u8'\0'};
    EXPECT_EQ(s2, test_char_traits::assign(s2, 3, u8'f'));

    EXPECT_EQ(u8'f', s2[0]);
    EXPECT_EQ(u8'f', s2[1]);
    EXPECT_EQ(u8'f', s2[2]);
  }

  EXPECT_EQ(nullptr, test_char_traits::assign(nullptr, 0, u8'f'));
}

inline void char_traits_char8_t_compare() {
  EXPECT_EQ(test_char_traits::compare(u8"", u8"", 0), 0);
  EXPECT_EQ(test_char_traits::compare(nullptr, nullptr, 0), 0);

  EXPECT_EQ(test_char_traits::compare(u8"a", u8"a", 1), 0);
  EXPECT_LT(test_char_traits::compare(u8"a", u8"b", 1), 0);
  EXPECT_GT(test_char_traits::compare(u8"b", u8"a", 1), 0);

  // compare only first code unit (,1). Ther are same x\d0
  EXPECT_EQ(test_char_traits::compare(u8"б", u8"б", 1), 0); // x\d0 x\b1 and x\d0 x\b1 ==
  EXPECT_EQ(test_char_traits::compare(u8"б", u8"в", 1), 0); // x\d0 x\b1 and x\d0 x\b2 ==
  EXPECT_EQ(test_char_traits::compare(u8"в", u8"б", 1), 0); // x\d0 x\b2 and x\d0 x\b1 ==

  // compare only first code unit (,1). Ther are x\d0 and x\d1
  EXPECT_EQ(test_char_traits::compare(u8"б", u8"б", 1), 0); // x\d0 x\b1 and x\d0 x\b1
  EXPECT_LT(test_char_traits::compare(u8"б", u8"я", 1), 0); // x\d0 x\b1 and x\d1 x\8f
  EXPECT_GT(test_char_traits::compare(u8"я", u8"б", 1), 0); // x\d1 x\8f and x\d0 x\b1

  // compare both code units (,2)
  EXPECT_EQ(test_char_traits::compare(u8"б", u8"б", 2), 0); // x\d0 x\b1 and x\d0 x\b1
  EXPECT_LT(test_char_traits::compare(u8"б", u8"в", 2), 0); // x\d0 x\b1 and x\d0 x\b2
  EXPECT_GT(test_char_traits::compare(u8"в", u8"б", 2), 0); // x\d0 x\b2 and x\d0 x\b1

  EXPECT_EQ(test_char_traits::compare(u8"б", u8"б", 2), 0); // x\d0 x\b1 and x\d0 x\b1
  EXPECT_LT(test_char_traits::compare(u8"б", u8"я", 2), 0); // x\d0 x\b1 and x\d1 x\8f
  EXPECT_GT(test_char_traits::compare(u8"я", u8"б", 2), 0); // x\d1 x\8f and x\d0 x\b1

  EXPECT_EQ(test_char_traits::compare(u8"ab", u8"ab", 2), 0);
  EXPECT_LT(test_char_traits::compare(u8"ab", u8"ac", 2), 0);
  EXPECT_LT(test_char_traits::compare(u8"ab", u8"bb", 2), 0);
  EXPECT_GT(test_char_traits::compare(u8"ac", u8"ab", 2), 0);
  EXPECT_GT(test_char_traits::compare(u8"bb", u8"ab", 2), 0);

  EXPECT_EQ(test_char_traits::compare(u8"byz¥ðбяࠀ℉𐀀𑊰𝄞😅", u8"byz¥ðбяࠀ℉𐀀𑊰𝄞😅", 34), 0);
  EXPECT_LT(test_char_traits::compare(u8"abc", u8"bbc", 3), 0);
  EXPECT_LT(test_char_traits::compare(u8"abc", u8"acc", 3), 0);
  EXPECT_LT(test_char_traits::compare(u8"abc", u8"abd", 3), 0);
  EXPECT_GT(test_char_traits::compare(u8"bbc", u8"abc", 3), 0);
  EXPECT_GT(test_char_traits::compare(u8"acc", u8"abc", 3), 0);
  EXPECT_GT(test_char_traits::compare(u8"abd", u8"abc", 3), 0);

  {
    t_char_type a[]{static_cast<t_char_type>(-1), 0};
    t_char_type b[]{1, 0};
    // EXPECT_GT(test_char_traits::compare(a, b, 1), 0); // TODO
  }
}

inline void char_traits_char8_t_copy() {
  t_char_type s1[]{u8'a', u8'b', u8'c'};
  t_char_type s2[]{u8'\0', u8'\0', u8'\0'};

  EXPECT_EQ(s2, test_char_traits::copy(s2, s1, 3));

  EXPECT_EQ(u8'a', s2[0]);
  EXPECT_EQ(u8'b', s2[1]);
  EXPECT_EQ(u8'c', s2[2]);

  EXPECT_EQ(nullptr, test_char_traits::copy(nullptr, s1, 0));
  EXPECT_EQ(s1, test_char_traits::copy(s1, nullptr, 0));
}

inline void char_traits_char8_t_eof() {
  EXPECT_EQ(-1, test_char_traits::eof());
}

inline void char_traits_char8_t_not_eof() {
  EXPECT_EQ(test_char_traits::not_eof(u8'a'), u8'a');
  EXPECT_EQ(test_char_traits::not_eof(u8'A'), u8'A');
  EXPECT_EQ(test_char_traits::not_eof(0), 0);
  EXPECT_NE(test_char_traits::not_eof(test_char_traits::eof()), test_char_traits::eof());
}

inline void char_traits_char8_t_eq() {
  EXPECT_TRUE(test_char_traits::eq(u8'a', u8'a'));
  EXPECT_FALSE(test_char_traits::eq(u8'a', u8'A'));
}

inline void char_traits_char8_t_lt() {
  EXPECT_EQ(test_char_traits::lt(u8'\0', u8'A'), (u8'\0' < u8'A'));
  EXPECT_EQ(test_char_traits::lt(u8'A', u8'\0'), (u8'A' < u8'\0'));

  EXPECT_EQ(test_char_traits::lt(u8'a', u8'a'), (u8'a' < u8'a'));
  EXPECT_EQ(test_char_traits::lt(u8'A', u8'a'), (u8'A' < u8'a'));
  EXPECT_EQ(test_char_traits::lt(u8'a', u8'A'), (u8'a' < u8'A'));

  EXPECT_EQ(test_char_traits::lt(u8'a', u8'z'), (u8'a' < u8'z'));
  EXPECT_EQ(test_char_traits::lt(u8'A', u8'Z'), (u8'A' < u8'Z'));

  EXPECT_EQ(test_char_traits::lt(u8' ', u8'A'), (u8' ' < u8'A'));
  EXPECT_EQ(test_char_traits::lt(u8'A', u8'~'), (u8'A' < u8'~'));
}

inline void char_traits_char8_t_eq_int_type() {
  EXPECT_TRUE(test_char_traits::eq_int_type(u8'a', u8'a'));
  EXPECT_FALSE(test_char_traits::eq_int_type(u8'a', u8'A'));

  EXPECT_FALSE(test_char_traits::eq_int_type(test_char_traits::eof(), 'A'));
  EXPECT_TRUE(test_char_traits::eq_int_type(test_char_traits::eof(), test_char_traits::eof()));
}

inline void char_traits_char8_t_find() {
  t_char_type const s1[]{u8'a', u8'b', u8'c'};
  EXPECT_EQ(test_char_traits::find(s1, 3, u8'a'), s1);
  EXPECT_EQ(test_char_traits::find(s1, 3, u8'b'), s1 + 1);
  EXPECT_EQ(test_char_traits::find(s1, 3, u8'c'), s1 + 2);

  EXPECT_EQ(test_char_traits::find(s1, 3, u8'd'), nullptr);
  EXPECT_EQ(test_char_traits::find(s1, 3, u8'e'), nullptr);

  EXPECT_EQ(test_char_traits::find(nullptr, 0, t_char_type(0)), nullptr);
}

inline void char_traits_char8_t_length() {
  EXPECT_EQ(test_char_traits::length(u8""), 0);
  EXPECT_EQ(test_char_traits::length(u8"a"), 1);
  EXPECT_EQ(test_char_traits::length(u8"aa"), 2);
  EXPECT_EQ(test_char_traits::length(u8"aaa"), 3);
  EXPECT_EQ(test_char_traits::length(u8"aaaa"), 4);

  EXPECT_EQ(test_char_traits::length(u8"я"), 2);
  EXPECT_EQ(test_char_traits::length(u8"яя"), 4);
  EXPECT_EQ(test_char_traits::length(u8"яяя"), 6);
  EXPECT_EQ(test_char_traits::length(u8"яяяя"), 8);

  EXPECT_EQ(test_char_traits::length(u8"℉"), 3);
  EXPECT_EQ(test_char_traits::length(u8"℉℉"), 6);
  EXPECT_EQ(test_char_traits::length(u8"℉℉℉"), 9);
  EXPECT_EQ(test_char_traits::length(u8"℉℉℉℉"), 12);

  EXPECT_EQ(test_char_traits::length(u8"𝄞"), 4);
  EXPECT_EQ(test_char_traits::length(u8"𝄞𝄞"), 8);
  EXPECT_EQ(test_char_traits::length(u8"𝄞𝄞𝄞"), 12);
  EXPECT_EQ(test_char_traits::length(u8"𝄞𝄞𝄞𝄞"), 16);

  EXPECT_EQ(test_char_traits::length(u8"aя"), 3);
  EXPECT_EQ(test_char_traits::length(u8"a℉"), 4);
  EXPECT_EQ(test_char_traits::length(u8"a𝄞"), 5);
  EXPECT_EQ(test_char_traits::length(u8"я℉"), 5);
  EXPECT_EQ(test_char_traits::length(u8"я𝄞"), 6);
  EXPECT_EQ(test_char_traits::length(u8"℉𝄞"), 7);

  EXPECT_EQ(test_char_traits::length(u8"byz¥ðбяࠀ℉𐀀𑊰𝄞😅"), 33);
}

inline void char_traits_char8_t_move() {
  t_char_type s1[]{u8'a', u8'b', u8'c'};
  {
    EXPECT_EQ(test_char_traits::move(&s1[0], &s1[1], 2), &s1[0]);
    EXPECT_EQ(s1[0], u8'b');
    EXPECT_EQ(s1[1], u8'c');
    EXPECT_EQ(s1[2], u8'c');

    s1[2] = u8'\0';
    EXPECT_EQ(test_char_traits::move(&s1[1], &s1[0], 2), &s1[1]);
    EXPECT_EQ(s1[0], u8'b');
    EXPECT_EQ(s1[1], u8'b');
    EXPECT_EQ(s1[2], u8'c');
  }
  {
    EXPECT_EQ(test_char_traits::move(nullptr, &s1[0], 0), nullptr);
    EXPECT_EQ(test_char_traits::move(&s1[0], nullptr, 0), &s1[0]);
  }
}

inline void char_traits_char8_t_to_char_type() {
  EXPECT_EQ(test_char_traits::to_char_type(97), u8'a');
  EXPECT_EQ(test_char_traits::to_char_type(122), u8'z');
  EXPECT_EQ(test_char_traits::to_char_type(0), u8'\0');
}

inline void char_traits_char8_t_to_int_type() {
  EXPECT_EQ(test_char_traits::to_int_type(u8'a'), 97);
  EXPECT_EQ(test_char_traits::to_int_type(u8'z'), 122);
  EXPECT_EQ(test_char_traits::to_int_type(u8'\0'), 0);
}
// clang-format on
} // namespace test_string
#endif // PSTL_TEST_CHAR_TRAITS_CHAR8_T_H
