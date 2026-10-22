// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="char_traits_win_wchar_t.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CHAR_TRAITS_WIN_WCHAR_T_H
#define PSTL_CHAR_TRAITS_WIN_WCHAR_T_H

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
}

inline void char_traits_wchar_t_access3() {
  {
    t_char_type s2[]{L'\0', L'\0', L'\0'};
    EXPECT_EQ(s2, test_char_traits::assign(s2, 3, L'я'));

    EXPECT_EQ(L'я', s2[0]);
    EXPECT_EQ(L'я', s2[1]);
    EXPECT_EQ(L'я', s2[2]);
  }

  EXPECT_EQ(nullptr, test_char_traits::assign(nullptr, 0, t_char_type(5)));
}

inline void char_traits_wchar_t_compare() {
  EXPECT_EQ(test_char_traits::compare(L"", L"", 0), 0);
  EXPECT_EQ(test_char_traits::compare(nullptr, nullptr, 0), 0);

  EXPECT_EQ(test_char_traits::compare(L"1", L"1", 1), 0);
  EXPECT_LT(test_char_traits::compare(L"1", L"2", 1), 0);
  EXPECT_GT(test_char_traits::compare(L"2", L"1", 1), 0);

  // compare only first code unit (,1). Ther are same x\f09d
  EXPECT_EQ(test_char_traits::compare(L"𝄞", L"𝄞", 1), 0); // x\f09d x\849e and x\f09d x\84a2 ==
  EXPECT_EQ(test_char_traits::compare(L"𝄞", L"𝄢", 1), 0); // x\f09d x\849e and x\f09d x\84a2 ==
  EXPECT_EQ(test_char_traits::compare(L"𝄢", L"𝄞", 1), 0); // x\f09d x\84a2 and x\f09d x\849e ==

  // compare only first code unit (,1). Ther are x\f09d and x\f09f
  EXPECT_EQ(test_char_traits::compare(L"𝄞", L"𝄞", 1), 0);  // x\f09d x\849e and x\f09d x\849e
  EXPECT_LT(test_char_traits::compare(L"𝄞", L"😅", 1), 0); // x\f09d x\849e and x\f09f x\9885
  EXPECT_GT(test_char_traits::compare(L"😅", L"𝄞", 1), 0); // x\f09f x\9885 and x\f09d x\849e

  // compare both code units (,2)
  EXPECT_EQ(test_char_traits::compare(L"𝄞", L"𝄞", 2), 0); // x\f09d x\849e and x\f09d x\849e
  EXPECT_LT(test_char_traits::compare(L"𝄞", L"𝄢", 2), 0); // x\f09d x\849e and x\f09d x\84a2
  EXPECT_GT(test_char_traits::compare(L"𝄢", L"𝄞", 2), 0); // x\f09d x\84a2 and x\f09d x\849e

  EXPECT_EQ(test_char_traits::compare(L"𝄞", L"𝄞", 2), 0); // x\f09d x\849e and x\f09d x\849e
  EXPECT_LT(test_char_traits::compare(L"𝄞", L"😅", 2), 0); // x\f09d x\849e and x\f09f x\9885
  EXPECT_GT(test_char_traits::compare(L"😅", L"𝄞", 2), 0); // x\f09f x\9885 and x\f09d x\849e

  EXPECT_EQ(test_char_traits::compare(L"12", L"12", 2), 0);
  EXPECT_LT(test_char_traits::compare(L"12", L"13", 2), 0);
  EXPECT_LT(test_char_traits::compare(L"12", L"22", 2), 0);
  EXPECT_GT(test_char_traits::compare(L"13", L"12", 2), 0);
  EXPECT_GT(test_char_traits::compare(L"22", L"12", 2), 0);

  EXPECT_EQ(test_char_traits::compare(L"byz¥ðбяࠀ℉𐀀𑊰𝄞😅", L"byz¥ðбяࠀ℉𐀀𑊰𝄞😅", 18), 0);
  EXPECT_LT(test_char_traits::compare(L"123", L"223", 3), 0);
  EXPECT_LT(test_char_traits::compare(L"123", L"133", 3), 0);
  EXPECT_LT(test_char_traits::compare(L"123", L"124", 3), 0);
  EXPECT_GT(test_char_traits::compare(L"223", L"123", 3), 0);
  EXPECT_GT(test_char_traits::compare(L"133", L"123", 3), 0);
  EXPECT_GT(test_char_traits::compare(L"124", L"123", 3), 0);

  {
    t_char_type a[]{static_cast<t_char_type>(-1), 0};
    t_char_type b[]{1, 0};
    // EXPECT_GT(test_char_traits::compare(a, b, 1), 0); // TODO
  }
}

inline void char_traits_wchar_t_copy() {
  t_char_type s1[]{L'б', L'ц', L'я'};
  t_char_type s2[]{L'\0', L'\0', L'\0'};

  EXPECT_EQ(s2, test_char_traits::copy(s2, s1, 3));

  EXPECT_EQ(L'б', s2[0]);
  EXPECT_EQ(L'ц', s2[1]);
  EXPECT_EQ(L'я', s2[2]);

  EXPECT_EQ(nullptr, test_char_traits::copy(nullptr, s1, 0));
  EXPECT_EQ(s1, test_char_traits::copy(s1, nullptr, 0));
}

inline void char_traits_wchar_t_eof() {
  EXPECT_EQ(-1, test_char_traits::eof());
}

inline void char_traits_wchar_t_not_eof() {
  EXPECT_EQ(test_char_traits::not_eof(L'a'), L'a');
  EXPECT_EQ(test_char_traits::not_eof(L'я'), L'я');
  EXPECT_EQ(test_char_traits::not_eof(0), 0);
  EXPECT_NE(test_char_traits::not_eof(test_char_traits::eof()), test_char_traits::eof());
}

inline void char_traits_wchar_t_eq() {
  EXPECT_TRUE(test_char_traits::eq(L'a', L'a'));
  EXPECT_TRUE(test_char_traits::eq(L'я', L'я'));

  EXPECT_FALSE(test_char_traits::eq(L'a', L'z'));
  EXPECT_FALSE(test_char_traits::eq(L'a', L'я'));

  EXPECT_FALSE(test_char_traits::eq(L'я', L'z'));
  EXPECT_FALSE(test_char_traits::eq(L'я', L'б'));
}

inline void char_traits_wchar_t_lt() {
  {
    EXPECT_EQ(test_char_traits::lt(L'\0', L'a'), (L'\0' < L'a'));
    EXPECT_EQ(test_char_traits::lt(L'\0', L'я'), (L'\0' < L'я'));
    EXPECT_EQ(test_char_traits::lt(L'a', L'\0'), (L'a' < L'\0'));
    EXPECT_EQ(test_char_traits::lt(L'я', L'\0'), (L'я' < L'\0'));
  }
  {
    EXPECT_EQ(test_char_traits::lt(L'z', L'a'), (L'z' < L'a'));
    EXPECT_EQ(test_char_traits::lt(L'a', L'z'), (L'a' < L'z'));

    EXPECT_EQ(test_char_traits::lt(L'a', L'a'), (L'a' < L'a'));
    EXPECT_EQ(test_char_traits::lt(L'a', L'я'), (L'a' < L'я'));
  }
  {
    EXPECT_EQ(test_char_traits::lt(L'я', L'б'), (L'я' < L'б'));
    EXPECT_EQ(test_char_traits::lt(L'б', L'я'), (L'б' < L'я'));
  }
}

inline void char_traits_wchar_t_eq_int_type() {
  EXPECT_TRUE(test_char_traits::eq_int_type(L'a', L'a'));
  EXPECT_FALSE(test_char_traits::eq_int_type(L'a', L'A'));
  EXPECT_TRUE(test_char_traits::eq_int_type(L'б', L'б'));
  EXPECT_FALSE(test_char_traits::eq_int_type(L'б', L'я'));

  EXPECT_FALSE(test_char_traits::eq_int_type(test_char_traits::eof(), 'я'));
  EXPECT_TRUE(test_char_traits::eq_int_type(test_char_traits::eof(), test_char_traits::eof()));
}

inline void char_traits_wchar_t_find() {
  t_char_type const s1[]{L'€', L'Њ', L'ᰃ'};
  EXPECT_EQ(test_char_traits::find(s1, 3, L'€'), s1);
  EXPECT_EQ(test_char_traits::find(s1, 3, L'Њ'), s1 + 1);
  EXPECT_EQ(test_char_traits::find(s1, 3, L'ᰃ'), s1 + 2);

  EXPECT_EQ(test_char_traits::find(s1, 3, L'ᄅ'), nullptr);
  EXPECT_EQ(test_char_traits::find(s1, 3, L'a'), nullptr);

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

  EXPECT_EQ(test_char_traits::length(L"𝄞"), 2);
  EXPECT_EQ(test_char_traits::length(L"𝄞𝄞"), 4);
  EXPECT_EQ(test_char_traits::length(L"𝄞𝄞𝄞"), 6);
  EXPECT_EQ(test_char_traits::length(L"𝄞𝄞𝄞𝄞"), 8);

  EXPECT_EQ(test_char_traits::length(L"aя"), 2);
  EXPECT_EQ(test_char_traits::length(L"a℉"), 2);
  EXPECT_EQ(test_char_traits::length(L"a𝄞"), 3);
  EXPECT_EQ(test_char_traits::length(L"я℉"), 2);
  EXPECT_EQ(test_char_traits::length(L"я𝄞"), 3);
  EXPECT_EQ(test_char_traits::length(L"℉𝄞"), 3);

  EXPECT_EQ(test_char_traits::length(L"byz¥ðбяࠀ℉𐀀𑊰𝄞😅"), 17);
}

inline void char_traits_wchar_t_move() {
  t_char_type s1[]{L'€', L'Њ', L'ᰃ'};
  {
    EXPECT_EQ(test_char_traits::move(&s1[0], &s1[1], 2), &s1[0]);
    EXPECT_EQ(s1[0], L'Њ');
    EXPECT_EQ(s1[1], L'ᰃ');
    EXPECT_EQ(s1[2], L'ᰃ');

    s1[2] = t_char_type(0);
    EXPECT_EQ(test_char_traits::move(&s1[1], &s1[0], 2), &s1[1]);
    EXPECT_EQ(s1[0], L'Њ');
    EXPECT_EQ(s1[1], L'Њ');
    EXPECT_EQ(s1[2], L'ᰃ');
  }
  {
    EXPECT_EQ(test_char_traits::move(nullptr, &s1[0], 0), nullptr);
    EXPECT_EQ(test_char_traits::move(&s1[0], nullptr, 0), &s1[0]);
  }
}

inline void char_traits_wchar_t_to_char_type() {
  EXPECT_EQ(test_char_traits::to_char_type(97), L'a');
  EXPECT_EQ(test_char_traits::to_char_type(122), L'z');
  EXPECT_EQ(test_char_traits::to_char_type(240), L'ð');
  EXPECT_EQ(test_char_traits::to_char_type(1073), L'б');
  EXPECT_EQ(test_char_traits::to_char_type(0), L'\0');
}

inline void char_traits_wchar_t_to_int_type() {
  EXPECT_EQ(test_char_traits::to_int_type(L'a'), 97);
  EXPECT_EQ(test_char_traits::to_int_type(L'z'), 122);
  EXPECT_EQ(test_char_traits::to_int_type(L'ð'), 240);
  EXPECT_EQ(test_char_traits::to_int_type(L'б'), 1073);
  EXPECT_EQ(test_char_traits::to_int_type(L'\0'), 0);
}
} // namespace test_string

#endif // PSTL_CHAR_TRAITS_WIN_WCHAR_T_H
