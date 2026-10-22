// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="char_traits_char16_t.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "portable_stl/common/char_t.h"
#include "portable_stl/string/char_traits.h"

using t_char_type      = char16_t;
using test_char_traits = ::portable_stl::char_traits<t_char_type>;

namespace test_string_helper {} // namespace test_string_helper

TEST(char_traits_char16_t, access2) {
  static_cast<void>(test_info_);

  {
    t_char_type chr{u'1'};
    test_char_traits::assign(chr, u'a');
    EXPECT_EQ(u'a', chr);
  }
  {
    t_char_type chr{u'1'};
    test_char_traits::assign(chr, u'я'); // U+044F
    EXPECT_EQ(u'я', chr);
  }
}

TEST(char_traits_char16_t, access3) {
  static_cast<void>(test_info_);
  {
    t_char_type s2[]{u'\0', u'\0', u'\0'};
    EXPECT_EQ(s2, test_char_traits::assign(s2, 3, u'я'));

    EXPECT_EQ(u'я', s2[0]);
    EXPECT_EQ(u'я', s2[1]);
    EXPECT_EQ(u'я', s2[2]);
  }

  EXPECT_EQ(nullptr, test_char_traits::assign(nullptr, 0, u'я'));
}

TEST(char_traits_char16_t, compare) {
  static_cast<void>(test_info_);

  EXPECT_EQ(test_char_traits::compare(u"", u"", 0), 0);
  EXPECT_EQ(test_char_traits::compare(nullptr, nullptr, 0), 0);

  EXPECT_EQ(test_char_traits::compare(u"1", u"1", 1), 0);
  EXPECT_LT(test_char_traits::compare(u"1", u"2", 1), 0);
  EXPECT_GT(test_char_traits::compare(u"2", u"1", 1), 0);

  // compare only first code unit (,1). Ther are same x\f09d
  EXPECT_EQ(test_char_traits::compare(u"𝄞", u"𝄞", 1), 0); // x\f09d x\849e and x\f09d x\84a2 ==
  EXPECT_EQ(test_char_traits::compare(u"𝄞", u"𝄢", 1), 0); // x\f09d x\849e and x\f09d x\84a2 ==
  EXPECT_EQ(test_char_traits::compare(u"𝄢", u"𝄞", 1), 0); // x\f09d x\84a2 and x\f09d x\849e ==

  // compare only first code unit (,1). Ther are x\f09d and x\f09f
  EXPECT_EQ(test_char_traits::compare(u"𝄞", u"𝄞", 1), 0);  // x\f09d x\849e and x\f09d x\849e
  EXPECT_LT(test_char_traits::compare(u"𝄞", u"😅", 1), 0); // x\f09d x\849e and x\f09f x\9885
  EXPECT_GT(test_char_traits::compare(u"😅", u"𝄞", 1), 0); // x\f09f x\9885 and x\f09d x\849e

  // compare both code units (,2)
  EXPECT_EQ(test_char_traits::compare(u"𝄞", u"𝄞", 2), 0); // x\f09d x\849e and x\f09d x\849e
  EXPECT_LT(test_char_traits::compare(u"𝄞", u"𝄢", 2), 0); // x\f09d x\849e and x\f09d x\84a2
  EXPECT_GT(test_char_traits::compare(u"𝄢", u"𝄞", 2), 0); // x\f09d x\84a2 and x\f09d x\849e

  EXPECT_EQ(test_char_traits::compare(u"𝄞", u"𝄞", 2), 0); // x\f09d x\849e and x\f09d x\849e
  EXPECT_LT(test_char_traits::compare(u"𝄞", u"😅", 2), 0); // x\f09d x\849e and x\f09f x\9885
  EXPECT_GT(test_char_traits::compare(u"😅", u"𝄞", 2), 0); // x\f09f x\9885 and x\f09d x\849e

  EXPECT_EQ(test_char_traits::compare(u"12", u"12", 2), 0);
  EXPECT_LT(test_char_traits::compare(u"12", u"13", 2), 0);
  EXPECT_LT(test_char_traits::compare(u"12", u"22", 2), 0);
  EXPECT_GT(test_char_traits::compare(u"13", u"12", 2), 0);
  EXPECT_GT(test_char_traits::compare(u"22", u"12", 2), 0);

  EXPECT_EQ(test_char_traits::compare(u"byz¥ðбяࠀ℉𐀀𑊰𝄞😅", u"byz¥ðбяࠀ℉𐀀𑊰𝄞😅", 18), 0);
  EXPECT_LT(test_char_traits::compare(u"123", u"223", 3), 0);
  EXPECT_LT(test_char_traits::compare(u"123", u"133", 3), 0);
  EXPECT_LT(test_char_traits::compare(u"123", u"124", 3), 0);
  EXPECT_GT(test_char_traits::compare(u"223", u"123", 3), 0);
  EXPECT_GT(test_char_traits::compare(u"133", u"123", 3), 0);
  EXPECT_GT(test_char_traits::compare(u"124", u"123", 3), 0);

  {
    t_char_type a[]{static_cast<t_char_type>(-1), 0};
    t_char_type b[]{1, 0};
    EXPECT_GT(test_char_traits::compare(a, b, 1), 0);
  }
}

TEST(char_traits_char16_t, copy) {
  static_cast<void>(test_info_);

  t_char_type s1[]{u'€', u'Њ', u'$'};
  t_char_type s2[]{u'\0',u'\0',u'\0'};

  EXPECT_EQ(s2, test_char_traits::copy(s2, s1, 3));

  EXPECT_EQ(u'€', s2[0]);
  EXPECT_EQ(u'Њ', s2[1]);
  EXPECT_EQ(u'$', s2[2]);

  EXPECT_EQ(nullptr, test_char_traits::copy(nullptr, s1, 0));
  EXPECT_EQ(s1, test_char_traits::copy(s1, nullptr, 0));
}

TEST(char_traits_char16_t, eof) {
  static_cast<void>(test_info_);

  EXPECT_EQ(-1, test_char_traits::eof());
}

TEST(char_traits_char16_t, not_eof) {
  static_cast<void>(test_info_);

  EXPECT_EQ(test_char_traits::not_eof(u'a'), u'a');
  EXPECT_EQ(test_char_traits::not_eof(u'A'), u'A');
  EXPECT_EQ(test_char_traits::not_eof(0), 0);
  EXPECT_NE(test_char_traits::not_eof(test_char_traits::eof()), test_char_traits::eof());
}

TEST(char_traits_char16_t, eq) {
  static_cast<void>(test_info_);

  EXPECT_TRUE(test_char_traits::eq(u'a', u'a'));
  EXPECT_TRUE(test_char_traits::eq(u'я', u'я'));

  EXPECT_FALSE(test_char_traits::eq(u'a', u'z'));
  EXPECT_FALSE(test_char_traits::eq(u'a', u'я'));

  EXPECT_FALSE(test_char_traits::eq(u'я', u'z'));
  EXPECT_FALSE(test_char_traits::eq(u'я', u'б'));
}

TEST(char_traits_char16_t, lt) {
  static_cast<void>(test_info_);

{
    EXPECT_EQ(test_char_traits::lt(u'\0', u'a'), (u'\0' < u'a'));
    EXPECT_EQ(test_char_traits::lt(u'\0', u'я'), (u'\0' < u'я'));
    EXPECT_EQ(test_char_traits::lt(u'a', u'\0'), (u'a' < u'\0'));
    EXPECT_EQ(test_char_traits::lt(u'я', u'\0'), (u'я' < u'\0'));
  }
  {
    EXPECT_EQ(test_char_traits::lt(u'z', u'a'), (u'z' < u'a'));
    EXPECT_EQ(test_char_traits::lt(u'a', u'z'), (u'a' < u'z'));

    EXPECT_EQ(test_char_traits::lt(u'a', u'a'), (u'a' < u'a'));
    EXPECT_EQ(test_char_traits::lt(u'a', u'я'), (u'a' < u'я'));
  }
  {
    EXPECT_EQ(test_char_traits::lt(u'я', u'б'), (u'я' < u'б'));
    EXPECT_EQ(test_char_traits::lt(u'б', u'я'), (u'б' < u'я'));
  }
}

TEST(char_traits_char16_t, eq_int_type) {
  static_cast<void>(test_info_);

  EXPECT_TRUE(test_char_traits::eq_int_type(u'a', u'a'));
  EXPECT_FALSE(test_char_traits::eq_int_type(u'a', u'A'));

  EXPECT_FALSE(test_char_traits::eq_int_type(test_char_traits::eof(), 'A'));
  EXPECT_TRUE(test_char_traits::eq_int_type(test_char_traits::eof(), test_char_traits::eof()));
}

TEST(char_traits_char16_t, find) {
  static_cast<void>(test_info_);

  t_char_type const s1[]{u'€', u'Њ', u'ᰃ'};
  EXPECT_EQ(test_char_traits::find(s1, 3, u'€'), s1);
  EXPECT_EQ(test_char_traits::find(s1, 3, u'Њ'), s1 + 1);
  EXPECT_EQ(test_char_traits::find(s1, 3, u'ᰃ'), s1 + 2);

  EXPECT_EQ(test_char_traits::find(s1, 3, u'ᄅ'), nullptr);
  EXPECT_EQ(test_char_traits::find(s1, 3, u'a'), nullptr);

  EXPECT_EQ(test_char_traits::find(nullptr, 0, t_char_type(0)), nullptr);
}

TEST(char_traits_char16_t, length) {
  static_cast<void>(test_info_);

  EXPECT_EQ(test_char_traits::length(u""), 0);
  EXPECT_EQ(test_char_traits::length(u"a"), 1);
  EXPECT_EQ(test_char_traits::length(u"aa"), 2);
  EXPECT_EQ(test_char_traits::length(u"aaa"), 3);
  EXPECT_EQ(test_char_traits::length(u"aaaa"), 4);

  EXPECT_EQ(test_char_traits::length(u"я"), 1);
  EXPECT_EQ(test_char_traits::length(u"яя"), 2);
  EXPECT_EQ(test_char_traits::length(u"яяя"), 3);
  EXPECT_EQ(test_char_traits::length(u"яяяя"), 4);

  EXPECT_EQ(test_char_traits::length(u"℉"), 1);
  EXPECT_EQ(test_char_traits::length(u"℉℉"), 2);
  EXPECT_EQ(test_char_traits::length(u"℉℉℉"), 3);
  EXPECT_EQ(test_char_traits::length(u"℉℉℉℉"), 4);

  EXPECT_EQ(test_char_traits::length(u"𝄞"), 2);
  EXPECT_EQ(test_char_traits::length(u"𝄞𝄞"), 4);
  EXPECT_EQ(test_char_traits::length(u"𝄞𝄞𝄞"), 6);
  EXPECT_EQ(test_char_traits::length(u"𝄞𝄞𝄞𝄞"), 8);

  EXPECT_EQ(test_char_traits::length(u"aя"), 2);
  EXPECT_EQ(test_char_traits::length(u"a℉"), 2);
  EXPECT_EQ(test_char_traits::length(u"a𝄞"), 3);
  EXPECT_EQ(test_char_traits::length(u"я℉"), 2);
  EXPECT_EQ(test_char_traits::length(u"я𝄞"), 3);
  EXPECT_EQ(test_char_traits::length(u"℉𝄞"), 3);

  EXPECT_EQ(test_char_traits::length(u"byz¥ðбяࠀ℉𐀀𑊰𝄞😅"), 17);
}

TEST(char_traits_char16_t, move) {
  static_cast<void>(test_info_);

  t_char_type s1[]{u'€', u'Њ', u'ᰃ'};
  {
    EXPECT_EQ(test_char_traits::move(&s1[0], &s1[1], 2), &s1[0]);
    EXPECT_EQ(s1[0], u'Њ');
    EXPECT_EQ(s1[1], u'ᰃ');
    EXPECT_EQ(s1[2], u'ᰃ');

    s1[2] = t_char_type(0);
    EXPECT_EQ(test_char_traits::move(&s1[1], &s1[0], 2), &s1[1]);
    EXPECT_EQ(s1[0], u'Њ');
    EXPECT_EQ(s1[1], u'Њ');
    EXPECT_EQ(s1[2], u'ᰃ');
  }
  {
    EXPECT_EQ(test_char_traits::move(nullptr, &s1[0], 0), nullptr);
    EXPECT_EQ(test_char_traits::move(&s1[0], nullptr, 0), &s1[0]);
  }
}

TEST(char_traits_char16_t, to_char_type) {
  static_cast<void>(test_info_);

  EXPECT_EQ(test_char_traits::to_char_type(97), u'a');
  EXPECT_EQ(test_char_traits::to_char_type(122), u'z');
  EXPECT_EQ(test_char_traits::to_char_type(240), u'ð');
  EXPECT_EQ(test_char_traits::to_char_type(1073), u'б');
  EXPECT_EQ(test_char_traits::to_char_type(0), u'\0');
}

TEST(char_traits_char16_t, to_int_type) {
  static_cast<void>(test_info_);

  EXPECT_EQ(test_char_traits::to_int_type(u'a'), 97);
  EXPECT_EQ(test_char_traits::to_int_type(u'z'), 122);
  EXPECT_EQ(test_char_traits::to_int_type(u'ð'), 240);
  EXPECT_EQ(test_char_traits::to_int_type(u'б'), 1073);
  EXPECT_EQ(test_char_traits::to_int_type(u'\0'), 0);
}
