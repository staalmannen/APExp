// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="char_traits_char32_t.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "portable_stl/string/char_traits.h"

using t_char_type      = char32_t;
using test_char_traits = ::portable_stl::char_traits<t_char_type>;

namespace test_string_helper {} // namespace test_string_helper

TEST(char_traits_char32_t, access2) {
  static_cast<void>(test_info_);

  {
    t_char_type chr{U'\0'};
    test_char_traits::assign(chr, U'a'); // U+0061
    EXPECT_EQ(U'a', chr);
  }
  {
    t_char_type chr{U'\0'};
    test_char_traits::assign(chr, U'я'); // U+044F
    EXPECT_EQ(U'я', chr);
  }
  {
    t_char_type chr{U'\0'};
    test_char_traits::assign(chr, U'𝄞'); // U+1D11E
    EXPECT_EQ(U'𝄞', chr);
  }
}

TEST(char_traits_char32_t, access3) {
  static_cast<void>(test_info_);
  {
    t_char_type s2[]{U'\0', U'\0', U'\0'};
    EXPECT_EQ(s2, test_char_traits::assign(s2, 3, U'𝄞'));

    EXPECT_EQ(U'𝄞', s2[0]);
    EXPECT_EQ(U'𝄞', s2[1]);
    EXPECT_EQ(U'𝄞', s2[2]);
  }

  EXPECT_EQ(nullptr, test_char_traits::assign(nullptr, 0, t_char_type(5)));
}

TEST(char_traits_char32_t, compare) {
  static_cast<void>(test_info_);

  EXPECT_EQ(test_char_traits::compare(U"", U"", 0), 0);
  EXPECT_EQ(test_char_traits::compare(nullptr, nullptr, 0), 0);

  EXPECT_EQ(test_char_traits::compare(U"𝄞", U"𝄞", 1), 0);
  EXPECT_LT(test_char_traits::compare(U"𝄞", U"𝄢", 1), 0);
  EXPECT_GT(test_char_traits::compare(U"𝄢", U"𝄞", 1), 0);

  EXPECT_EQ(test_char_traits::compare(U"𝄞𝄢", U"𝄞𝄢", 2), 0);
  EXPECT_LT(test_char_traits::compare(U"𝄞𝄢", U"𝄞𝄰", 2), 0);
  EXPECT_LT(test_char_traits::compare(U"𝄞𝄢", U"𝄢𝄢", 2), 0);
  EXPECT_GT(test_char_traits::compare(U"𝄞𝄰", U"𝄞𝄢", 2), 0);
  EXPECT_GT(test_char_traits::compare(U"𝄢𝄢", U"𝄞𝄢", 2), 0);

  EXPECT_EQ(test_char_traits::compare(U"byz¥ðбяࠀ℉𐀀𑊰𝄞😅", U"byz¥ðбяࠀ℉𐀀𑊰𝄞😅", 14), 0);
  EXPECT_LT(test_char_traits::compare(U"123", U"223", 3), 0);
  EXPECT_LT(test_char_traits::compare(U"123", U"133", 3), 0);
  EXPECT_LT(test_char_traits::compare(U"123", U"124", 3), 0);
  EXPECT_GT(test_char_traits::compare(U"223", U"123", 3), 0);
  EXPECT_GT(test_char_traits::compare(U"133", U"123", 3), 0);
  EXPECT_GT(test_char_traits::compare(U"124", U"123", 3), 0);

  {
    t_char_type a[]{static_cast<t_char_type>(-1), 0};
    t_char_type b[]{1, 0};
    EXPECT_GT(test_char_traits::compare(a, b, 1), 0);
  }
}

TEST(char_traits_char32_t, copy) {
  static_cast<void>(test_info_);

  t_char_type s1[]{U'€', U'➼', U'𐭻'};
  t_char_type s2[]{U'\0', U'\0', U'\0'};

  EXPECT_EQ(s2, test_char_traits::copy(s2, s1, 3));

  EXPECT_EQ(U'€', s2[0]);
  EXPECT_EQ(U'➼', s2[1]);
  EXPECT_EQ(U'𐭻', s2[2]);

  EXPECT_EQ(nullptr, test_char_traits::copy(nullptr, s1, 0));
  EXPECT_EQ(s1, test_char_traits::copy(s1, nullptr, 0));
}

TEST(char_traits_char32_t, eof) {
  static_cast<void>(test_info_);

  EXPECT_EQ(-1, test_char_traits::eof());
}

TEST(char_traits_char32_t, not_eof) {
  static_cast<void>(test_info_);

  EXPECT_EQ(test_char_traits::not_eof(U'𝄞'), U'𝄞');
  EXPECT_EQ(test_char_traits::not_eof(U'😅'), U'😅');
  EXPECT_EQ(test_char_traits::not_eof(0), 0);
  EXPECT_NE(test_char_traits::not_eof(test_char_traits::eof()), test_char_traits::eof());
}

TEST(char_traits_char32_t, eq) {
  static_cast<void>(test_info_);

  EXPECT_TRUE(test_char_traits::eq(U'a', U'a'));
  EXPECT_TRUE(test_char_traits::eq(U'я', U'я'));
  EXPECT_TRUE(test_char_traits::eq(U'℉', U'℉'));
  EXPECT_TRUE(test_char_traits::eq(U'𝄞', U'𝄞'));

  EXPECT_FALSE(test_char_traits::eq(U'a', U'z'));
  EXPECT_FALSE(test_char_traits::eq(U'a', U'я'));
  EXPECT_FALSE(test_char_traits::eq(U'a', U'℉'));
  EXPECT_FALSE(test_char_traits::eq(U'a', U'𝄞'));

  EXPECT_FALSE(test_char_traits::eq(U'я', U'z'));
  EXPECT_FALSE(test_char_traits::eq(U'я', U'б'));
  EXPECT_FALSE(test_char_traits::eq(U'я', U'℉'));
  EXPECT_FALSE(test_char_traits::eq(U'я', U'𝄞'));

  EXPECT_FALSE(test_char_traits::eq(U'℉', U'z'));
  EXPECT_FALSE(test_char_traits::eq(U'℉', U'б'));
  EXPECT_FALSE(test_char_traits::eq(U'℉', U'ࠀ'));
  EXPECT_FALSE(test_char_traits::eq(U'℉', U'𝄞'));

  EXPECT_FALSE(test_char_traits::eq(U'𝄞', U'z'));
  EXPECT_FALSE(test_char_traits::eq(U'𝄞', U'б'));
  EXPECT_FALSE(test_char_traits::eq(U'𝄞', U'℉'));
  EXPECT_FALSE(test_char_traits::eq(U'𝄞', U'😅'));
}

TEST(char_traits_char32_t, lt) {
  static_cast<void>(test_info_);

  {
    EXPECT_EQ(test_char_traits::lt(U'\0', U'a'), (U'\0' < U'a'));
    EXPECT_EQ(test_char_traits::lt(U'\0', U'я'), (U'\0' < U'я'));
    EXPECT_EQ(test_char_traits::lt(U'\0', U'℉'), (U'\0' < U'℉'));
    EXPECT_EQ(test_char_traits::lt(U'\0', U'𝄞'), (U'\0' < U'𝄞'));
    EXPECT_EQ(test_char_traits::lt(U'a', U'\0'), (U'a' < U'\0'));
    EXPECT_EQ(test_char_traits::lt(U'я', U'\0'), (U'я' < U'\0'));
    EXPECT_EQ(test_char_traits::lt(U'℉', U'\0'), (U'℉' < U'\0'));
    EXPECT_EQ(test_char_traits::lt(U'𝄞', U'\0'), (U'𝄞' < U'\0'));
  }
  {
    EXPECT_EQ(test_char_traits::lt(U'z', U'a'), (U'z' < U'a'));
    EXPECT_EQ(test_char_traits::lt(U'a', U'z'), (U'a' < U'z'));

    EXPECT_EQ(test_char_traits::lt(U'a', U'a'), (U'a' < U'a'));
    EXPECT_EQ(test_char_traits::lt(U'a', U'я'), (U'a' < U'я'));
    EXPECT_EQ(test_char_traits::lt(U'a', U'℉'), (U'a' < U'℉'));
    EXPECT_EQ(test_char_traits::lt(U'a', U'𝄞'), (U'a' < U'𝄞'));
  }
  {
    EXPECT_EQ(test_char_traits::lt(U'я', U'б'), (U'я' < U'б'));
    EXPECT_EQ(test_char_traits::lt(U'б', U'я'), (U'б' < U'я'));

    EXPECT_EQ(test_char_traits::lt(U'б', U'℉'), (U'б' < U'℉'));
    EXPECT_EQ(test_char_traits::lt(U'б', U'𝄞'), (U'б' < U'𝄞'));
  }
  {
    EXPECT_EQ(test_char_traits::lt(U'ࠀ', U'℉'), (U'ࠀ' < U'℉'));
    EXPECT_EQ(test_char_traits::lt(U'℉', U'ࠀ'), (U'℉' < U'ࠀ'));

    EXPECT_EQ(test_char_traits::lt(U'℉', U'℉'), (U'℉' < U'℉'));
    EXPECT_EQ(test_char_traits::lt(U'℉', U'𝄞'), (U'℉' < U'𝄞'));
  }
  {
    EXPECT_EQ(test_char_traits::lt(U'𝄞', U'😅'), (U'𝄞' < U'😅'));
    EXPECT_EQ(test_char_traits::lt(U'😅', U'𝄞'), (U'😅' < U'𝄞'));

    EXPECT_EQ(test_char_traits::lt(U'𝄞', U'𝄞'), (U'𝄞' < U'𝄞'));
  }
}

TEST(char_traits_char32_t, eq_int_type) {
  static_cast<void>(test_info_);

  EXPECT_TRUE(test_char_traits::eq_int_type(U'a', U'a'));
  EXPECT_FALSE(test_char_traits::eq_int_type(U'a', U'A'));

  EXPECT_FALSE(test_char_traits::eq_int_type(test_char_traits::eof(), 'A'));
  EXPECT_TRUE(test_char_traits::eq_int_type(test_char_traits::eof(), test_char_traits::eof()));
}

TEST(char_traits_char32_t, find) {
  static_cast<void>(test_info_);

  t_char_type const s1[]{U'€', U'▙', U'𐭤'};
  EXPECT_EQ(test_char_traits::find(s1, 3, U'€'), s1);
  EXPECT_EQ(test_char_traits::find(s1, 3, U'▙'), s1 + 1);
  EXPECT_EQ(test_char_traits::find(s1, 3, U'𐭤'), s1 + 2);

  EXPECT_EQ(test_char_traits::find(s1, 3, U'ᄅ'), nullptr);
  EXPECT_EQ(test_char_traits::find(s1, 3, U'𐭡'), nullptr);

  EXPECT_EQ(test_char_traits::find(nullptr, 0, t_char_type(0)), nullptr);
}

TEST(char_traits_char32_t, length) {
  static_cast<void>(test_info_);
  
  EXPECT_EQ(test_char_traits::length(U""), 0);
  EXPECT_EQ(test_char_traits::length(U"a"), 1);
  EXPECT_EQ(test_char_traits::length(U"aa"), 2);
  EXPECT_EQ(test_char_traits::length(U"aaa"), 3);
  EXPECT_EQ(test_char_traits::length(U"aaaa"), 4);

  EXPECT_EQ(test_char_traits::length(U"я"), 1);
  EXPECT_EQ(test_char_traits::length(U"яя"), 2);
  EXPECT_EQ(test_char_traits::length(U"яяя"), 3);
  EXPECT_EQ(test_char_traits::length(U"яяяя"), 4);

  EXPECT_EQ(test_char_traits::length(U"℉"), 1);
  EXPECT_EQ(test_char_traits::length(U"℉℉"), 2);
  EXPECT_EQ(test_char_traits::length(U"℉℉℉"), 3);
  EXPECT_EQ(test_char_traits::length(U"℉℉℉℉"), 4);

  EXPECT_EQ(test_char_traits::length(U"𝄞"), 1);
  EXPECT_EQ(test_char_traits::length(U"𝄞𝄞"), 2);
  EXPECT_EQ(test_char_traits::length(U"𝄞𝄞𝄞"), 3);
  EXPECT_EQ(test_char_traits::length(U"𝄞𝄞𝄞𝄞"), 4);

  EXPECT_EQ(test_char_traits::length(U"aя"), 2);
  EXPECT_EQ(test_char_traits::length(U"a℉"), 2);
  EXPECT_EQ(test_char_traits::length(U"a𝄞"), 2);
  EXPECT_EQ(test_char_traits::length(U"я℉"), 2);
  EXPECT_EQ(test_char_traits::length(U"я𝄞"), 2);
  EXPECT_EQ(test_char_traits::length(U"℉𝄞"), 2);

  EXPECT_EQ(test_char_traits::length(U"byz¥ðбяࠀ℉𐀀𑊰𝄞😅"), 13);
}

TEST(char_traits_char32_t, move) {
  static_cast<void>(test_info_);

  t_char_type s1[]{U'𝄰', U'𝄢', U'𝄞'};
  {
    EXPECT_EQ(test_char_traits::move(&s1[0], &s1[1], 2), &s1[0]);
    EXPECT_EQ(s1[0], U'𝄢');
    EXPECT_EQ(s1[1], U'𝄞');
    EXPECT_EQ(s1[2], U'𝄞');

    s1[2] = t_char_type(0);
    EXPECT_EQ(test_char_traits::move(&s1[1], &s1[0], 2), &s1[1]);
    EXPECT_EQ(s1[0], U'𝄢');
    EXPECT_EQ(s1[1], U'𝄢');
    EXPECT_EQ(s1[2], U'𝄞');
  }
  {
    EXPECT_EQ(test_char_traits::move(nullptr, &s1[0], 0), nullptr);
    EXPECT_EQ(test_char_traits::move(&s1[0], nullptr, 0), &s1[0]);
  }

  t_char_type s2[]{U'a', U'𝄢', U'℉'};
  {
    EXPECT_EQ(test_char_traits::move(&s2[0], &s2[1], 2), &s2[0]);
    EXPECT_EQ(s2[0], U'𝄢');
    EXPECT_EQ(s2[1], U'℉');
    EXPECT_EQ(s2[2], U'℉');

    s2[2] = t_char_type(0);
    EXPECT_EQ(test_char_traits::move(&s2[1], &s2[0], 2), &s2[1]);
    EXPECT_EQ(s2[0], U'𝄢');
    EXPECT_EQ(s2[1], U'𝄢');
    EXPECT_EQ(s2[2], U'℉');
  }
}

TEST(char_traits_char32_t, to_char_type) {
  static_cast<void>(test_info_);

  EXPECT_EQ(test_char_traits::to_char_type(97), U'a');
  EXPECT_EQ(test_char_traits::to_char_type(122), U'z');
  EXPECT_EQ(test_char_traits::to_char_type(240), U'ð');
  EXPECT_EQ(test_char_traits::to_char_type(1073), U'б');
  EXPECT_EQ(test_char_traits::to_char_type(8457), U'℉');
  EXPECT_EQ(test_char_traits::to_char_type(119070), U'𝄞');
  EXPECT_EQ(test_char_traits::to_char_type(0), U'\0');
}

TEST(char_traits_char32_t, to_int_type) {
  static_cast<void>(test_info_);

  EXPECT_EQ(test_char_traits::to_int_type(U'a'), 97);
  EXPECT_EQ(test_char_traits::to_int_type(U'z'), 122);
  EXPECT_EQ(test_char_traits::to_int_type(U'ð'), 240);
  EXPECT_EQ(test_char_traits::to_int_type(U'б'), 1073);
  EXPECT_EQ(test_char_traits::to_int_type(U'℉'), 8457);
  EXPECT_EQ(test_char_traits::to_int_type(U'𝄞'), 119070);
  EXPECT_EQ(test_char_traits::to_int_type(U'\0'), 0);
}
