// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="char_traits_unix_wchar_t.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************

#ifndef PSTL_CHAR_TRAITS_UNIX_WCHAR_T_H
#define PSTL_CHAR_TRAITS_UNIX_WCHAR_T_H

#include <gtest/gtest.h>

#include "portable_stl/string/char_traits.h"

using t_char_type      = wchar_t;
using test_char_traits = ::portable_stl::char_traits<t_char_type>;

namespace test_string {
inline void char_traits_wchar_t_access2() {
  {
    t_char_type chr{L'\0'};
    test_char_traits::assign(chr, L'a'); // U+0061
    EXPECT_EQ(L'a', chr);
  }
  {
    t_char_type chr{L'\0'};
    test_char_traits::assign(chr, L'я'); // U+044F
    EXPECT_EQ(L'я', chr);
  }
  {
    t_char_type chr{L'\0'};
    test_char_traits::assign(chr, L'𝄞'); // U+1D11E
    EXPECT_EQ(L'𝄞', chr);
  }
}

inline void char_traits_wchar_t_access3() {
  {
    t_char_type s2[]{L'\0', L'\0', L'\0'};
    EXPECT_EQ(s2, test_char_traits::assign(s2, 3, L'𝄞'));

    EXPECT_EQ(L'𝄞', s2[0]);
    EXPECT_EQ(L'𝄞', s2[1]);
    EXPECT_EQ(L'𝄞', s2[2]);
  }

  EXPECT_EQ(nullptr, test_char_traits::assign(nullptr, 0, t_char_type(5)));
}

inline void char_traits_wchar_t_compare() {
  EXPECT_EQ(test_char_traits::compare(L"", L"", 0), 0);
  EXPECT_EQ(test_char_traits::compare(nullptr, nullptr, 0), 0);

  EXPECT_EQ(test_char_traits::compare(L"𝄞", L"𝄞", 1), 0);
  EXPECT_LT(test_char_traits::compare(L"𝄞", L"𝄢", 1), 0);
  EXPECT_GT(test_char_traits::compare(L"𝄢", L"𝄞", 1), 0);

  EXPECT_EQ(test_char_traits::compare(L"𝄞𝄢", L"𝄞𝄢", 2), 0);
  EXPECT_LT(test_char_traits::compare(L"𝄞𝄢", L"𝄞𝄰", 2), 0);
  EXPECT_LT(test_char_traits::compare(L"𝄞𝄢", L"𝄢𝄢", 2), 0);
  EXPECT_GT(test_char_traits::compare(L"𝄞𝄰", L"𝄞𝄢", 2), 0);
  EXPECT_GT(test_char_traits::compare(L"𝄢𝄢", L"𝄞𝄢", 2), 0);

  EXPECT_EQ(test_char_traits::compare(L"byz¥ðбяࠀ℉𐀀𑊰𝄞😅", L"byz¥ðбяࠀ℉𐀀𑊰𝄞😅", 14), 0);
  EXPECT_LT(test_char_traits::compare(L"123", L"223", 3), 0);
  EXPECT_LT(test_char_traits::compare(L"123", L"133", 3), 0);
  EXPECT_LT(test_char_traits::compare(L"123", L"124", 3), 0);
  EXPECT_GT(test_char_traits::compare(L"223", L"123", 3), 0);
  EXPECT_GT(test_char_traits::compare(L"133", L"123", 3), 0);
  EXPECT_GT(test_char_traits::compare(L"124", L"123", 3), 0);
}

inline void char_traits_wchar_t_copy() {
  t_char_type s1[]{L'€', L'➼', L'𐭻'};
  t_char_type s2[]{L'\0', L'\0', L'\0'};

  EXPECT_EQ(s2, test_char_traits::copy(s2, s1, 3));

  EXPECT_EQ(L'€', s2[0]);
  EXPECT_EQ(L'➼', s2[1]);
  EXPECT_EQ(L'𐭻', s2[2]);

  EXPECT_EQ(nullptr, test_char_traits::copy(nullptr, s1, 0));
  EXPECT_EQ(s1, test_char_traits::copy(s1, nullptr, 0));
}

inline void char_traits_wchar_t_eof() {
  EXPECT_EQ(-1, test_char_traits::eof());
}

inline void char_traits_wchar_t_not_eof() {
  EXPECT_EQ(test_char_traits::not_eof(L'𝄞'), L'𝄞');
  EXPECT_EQ(test_char_traits::not_eof(L'😅'), L'😅');
  EXPECT_EQ(test_char_traits::not_eof(0), 0);
  EXPECT_NE(test_char_traits::not_eof(test_char_traits::eof()), test_char_traits::eof());
}

inline void char_traits_wchar_t_eq() {
  EXPECT_TRUE(test_char_traits::eq(L'a', L'a'));
  EXPECT_TRUE(test_char_traits::eq(L'я', L'я'));
  EXPECT_TRUE(test_char_traits::eq(L'℉', L'℉'));
  EXPECT_TRUE(test_char_traits::eq(L'𝄞', L'𝄞'));

  EXPECT_FALSE(test_char_traits::eq(L'a', L'z'));
  EXPECT_FALSE(test_char_traits::eq(L'a', L'я'));
  EXPECT_FALSE(test_char_traits::eq(L'a', L'℉'));
  EXPECT_FALSE(test_char_traits::eq(L'a', L'𝄞'));

  EXPECT_FALSE(test_char_traits::eq(L'я', L'z'));
  EXPECT_FALSE(test_char_traits::eq(L'я', L'б'));
  EXPECT_FALSE(test_char_traits::eq(L'я', L'℉'));
  EXPECT_FALSE(test_char_traits::eq(L'я', L'𝄞'));

  EXPECT_FALSE(test_char_traits::eq(L'℉', L'z'));
  EXPECT_FALSE(test_char_traits::eq(L'℉', L'б'));
  EXPECT_FALSE(test_char_traits::eq(L'℉', L'ࠀ'));
  EXPECT_FALSE(test_char_traits::eq(L'℉', L'𝄞'));

  EXPECT_FALSE(test_char_traits::eq(L'𝄞', L'z'));
  EXPECT_FALSE(test_char_traits::eq(L'𝄞', L'б'));
  EXPECT_FALSE(test_char_traits::eq(L'𝄞', L'℉'));
  EXPECT_FALSE(test_char_traits::eq(L'𝄞', L'😅'));
}

inline void char_traits_wchar_t_lt() {
  {
    EXPECT_EQ(test_char_traits::lt(L'\0', L'a'), (L'\0' < L'a'));
    EXPECT_EQ(test_char_traits::lt(L'\0', L'я'), (L'\0' < L'я'));
    EXPECT_EQ(test_char_traits::lt(L'\0', L'℉'), (L'\0' < L'℉'));
    EXPECT_EQ(test_char_traits::lt(L'\0', L'𝄞'), (L'\0' < L'𝄞'));
    EXPECT_EQ(test_char_traits::lt(L'a', L'\0'), (L'a' < L'\0'));
    EXPECT_EQ(test_char_traits::lt(L'я', L'\0'), (L'я' < L'\0'));
    EXPECT_EQ(test_char_traits::lt(L'℉', L'\0'), (L'℉' < L'\0'));
    EXPECT_EQ(test_char_traits::lt(L'𝄞', L'\0'), (L'𝄞' < L'\0'));
  }
  {
    EXPECT_EQ(test_char_traits::lt(L'z', L'a'), (L'z' < L'a'));
    EXPECT_EQ(test_char_traits::lt(L'a', L'z'), (L'a' < L'z'));

    EXPECT_EQ(test_char_traits::lt(L'a', L'a'), (L'a' < L'a'));
    EXPECT_EQ(test_char_traits::lt(L'a', L'я'), (L'a' < L'я'));
    EXPECT_EQ(test_char_traits::lt(L'a', L'℉'), (L'a' < L'℉'));
    EXPECT_EQ(test_char_traits::lt(L'a', L'𝄞'), (L'a' < L'𝄞'));
  }
  {
    EXPECT_EQ(test_char_traits::lt(L'я', L'б'), (L'я' < L'б'));
    EXPECT_EQ(test_char_traits::lt(L'б', L'я'), (L'б' < L'я'));

    EXPECT_EQ(test_char_traits::lt(L'б', L'℉'), (L'б' < L'℉'));
    EXPECT_EQ(test_char_traits::lt(L'б', L'𝄞'), (L'б' < L'𝄞'));
  }
  {
    EXPECT_EQ(test_char_traits::lt(L'ࠀ', L'℉'), (L'ࠀ' < L'℉'));
    EXPECT_EQ(test_char_traits::lt(L'℉', L'ࠀ'), (L'℉' < L'ࠀ'));

    EXPECT_EQ(test_char_traits::lt(L'℉', L'℉'), (L'℉' < L'℉'));
    EXPECT_EQ(test_char_traits::lt(L'℉', L'𝄞'), (L'℉' < L'𝄞'));
  }
  {
    EXPECT_EQ(test_char_traits::lt(L'𝄞', L'😅'), (L'𝄞' < L'😅'));
    EXPECT_EQ(test_char_traits::lt(L'😅', L'𝄞'), (L'😅' < L'𝄞'));

    EXPECT_EQ(test_char_traits::lt(L'𝄞', L'𝄞'), (L'𝄞' < L'𝄞'));
  }
}

inline void char_traits_wchar_t_eq_int_type() {
  EXPECT_TRUE(test_char_traits::eq_int_type(L'a', L'a'));
  EXPECT_FALSE(test_char_traits::eq_int_type(L'a', L'A'));

  EXPECT_FALSE(test_char_traits::eq_int_type(test_char_traits::eof(), 'A'));
  EXPECT_TRUE(test_char_traits::eq_int_type(test_char_traits::eof(), test_char_traits::eof()));
}

inline void char_traits_wchar_t_find() {
  t_char_type const s1[]{L'€', L'▙', L'𐭤'};
  EXPECT_EQ(test_char_traits::find(s1, 3, L'€'), s1);
  EXPECT_EQ(test_char_traits::find(s1, 3, L'▙'), s1 + 1);
  EXPECT_EQ(test_char_traits::find(s1, 3, L'𐭤'), s1 + 2);

  EXPECT_EQ(test_char_traits::find(s1, 3, L'ᄅ'), nullptr);
  EXPECT_EQ(test_char_traits::find(s1, 3, L'𐭡'), nullptr);

  EXPECT_EQ(test_char_traits::find(nullptr, 0, t_char_type(0)), nullptr);
}

inline void char_traits_wchar_t_length() {
  EXPECT_EQ(test_char_traits::length(L""), 0);
  EXPECT_EQ(test_char_traits::length(L"a"), 1);
  EXPECT_EQ(test_char_traits::length(L"aa"), 2);
  EXPECT_EQ(test_char_traits::length(L"aaa"), 3);
  EXPECT_EQ(test_char_traits::length(L"aaaa"), 4);

  EXPECT_EQ(test_char_traits::length(L"я"), 1);
  EXPECT_EQ(test_char_traits::length(L"яя"), 2);
  EXPECT_EQ(test_char_traits::length(L"яяя"), 3);
  EXPECT_EQ(test_char_traits::length(L"яяяя"), 4);

  EXPECT_EQ(test_char_traits::length(L"℉"), 1);
  EXPECT_EQ(test_char_traits::length(L"℉℉"), 2);
  EXPECT_EQ(test_char_traits::length(L"℉℉℉"), 3);
  EXPECT_EQ(test_char_traits::length(L"℉℉℉℉"), 4);

  EXPECT_EQ(test_char_traits::length(L"𝄞"), 1);
  EXPECT_EQ(test_char_traits::length(L"𝄞𝄞"), 2);
  EXPECT_EQ(test_char_traits::length(L"𝄞𝄞𝄞"), 3);
  EXPECT_EQ(test_char_traits::length(L"𝄞𝄞𝄞𝄞"), 4);

  EXPECT_EQ(test_char_traits::length(L"aя"), 2);
  EXPECT_EQ(test_char_traits::length(L"a℉"), 2);
  EXPECT_EQ(test_char_traits::length(L"a𝄞"), 2);
  EXPECT_EQ(test_char_traits::length(L"я℉"), 2);
  EXPECT_EQ(test_char_traits::length(L"я𝄞"), 2);
  EXPECT_EQ(test_char_traits::length(L"℉𝄞"), 2);

  EXPECT_EQ(test_char_traits::length(L"byz¥ðбяࠀ℉𐀀𑊰𝄞😅"), 13);
}

inline void char_traits_wchar_t_move() {
  t_char_type s1[]{L'𝄰', L'𝄢', L'𝄞'};
  {
    EXPECT_EQ(test_char_traits::move(&s1[0], &s1[1], 2), &s1[0]);
    EXPECT_EQ(s1[0], L'𝄢');
    EXPECT_EQ(s1[1], L'𝄞');
    EXPECT_EQ(s1[2], L'𝄞');

    s1[2] = t_char_type(0);
    EXPECT_EQ(test_char_traits::move(&s1[1], &s1[0], 2), &s1[1]);
    EXPECT_EQ(s1[0], L'𝄢');
    EXPECT_EQ(s1[1], L'𝄢');
    EXPECT_EQ(s1[2], L'𝄞');
  }
  {
    EXPECT_EQ(test_char_traits::move(nullptr, &s1[0], 0), nullptr);
    EXPECT_EQ(test_char_traits::move(&s1[0], nullptr, 0), &s1[0]);
  }

  t_char_type s2[]{L'a', L'𝄢', L'℉'};
  {
    EXPECT_EQ(test_char_traits::move(&s2[0], &s2[1], 2), &s2[0]);
    EXPECT_EQ(s2[0], L'𝄢');
    EXPECT_EQ(s2[1], L'℉');
    EXPECT_EQ(s2[2], L'℉');

    s2[2] = t_char_type(0);
    EXPECT_EQ(test_char_traits::move(&s2[1], &s2[0], 2), &s2[1]);
    EXPECT_EQ(s2[0], L'𝄢');
    EXPECT_EQ(s2[1], L'𝄢');
    EXPECT_EQ(s2[2], L'℉');
  }
}

inline void char_traits_wchar_t_to_char_type() {
  EXPECT_EQ(test_char_traits::to_char_type(97), L'a');
  EXPECT_EQ(test_char_traits::to_char_type(122), L'z');
  EXPECT_EQ(test_char_traits::to_char_type(240), L'ð');
  EXPECT_EQ(test_char_traits::to_char_type(1073), L'б');
  EXPECT_EQ(test_char_traits::to_char_type(8457), L'℉');
  EXPECT_EQ(test_char_traits::to_char_type(119070), L'𝄞');
  EXPECT_EQ(test_char_traits::to_char_type(0), L'\0');
}

inline void char_traits_wchar_t_to_int_type() {
  EXPECT_EQ(test_char_traits::to_int_type(L'a'), 97);
  EXPECT_EQ(test_char_traits::to_int_type(L'z'), 122);
  EXPECT_EQ(test_char_traits::to_int_type(L'ð'), 240);
  EXPECT_EQ(test_char_traits::to_int_type(L'б'), 1073);
  EXPECT_EQ(test_char_traits::to_int_type(L'℉'), 8457);
  EXPECT_EQ(test_char_traits::to_int_type(L'𝄞'), 119070);
  EXPECT_EQ(test_char_traits::to_int_type(L'\0'), 0);
}
} // namespace test_string

#endif // PSTL_CHAR_TRAITS_UNIX_WCHAR_T_H
