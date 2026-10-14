// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="char_traits_wchar_t.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#if defined(_MSC_VER)
#  include "wchar_t/char_traits_win_wchar_t.h"
#else // clang and gcc
#  include "wchar_t/char_traits_unix_wchar_t.h"
#endif

TEST(char_traits_wchar_t, access2) {
  static_cast<void>(test_info_);

  test_string::char_traits_wchar_t_access2();
}

TEST(char_traits_wchar_t, access3) {
  static_cast<void>(test_info_);

  test_string::char_traits_wchar_t_access3();
}

TEST(char_traits_wchar_t, compare) {
  static_cast<void>(test_info_);

  test_string::char_traits_wchar_t_compare();
}

TEST(char_traits_wchar_t, copy) {
  static_cast<void>(test_info_);

  test_string::char_traits_wchar_t_copy();
}

TEST(char_traits_wchar_t, eof) {
  static_cast<void>(test_info_);

  test_string::char_traits_wchar_t_eof();
}

TEST(char_traits_wchar_t, not_eof) {
  static_cast<void>(test_info_);

  test_string::char_traits_wchar_t_not_eof();
}

TEST(char_traits_wchar_t, eq) {
  static_cast<void>(test_info_);

  test_string::char_traits_wchar_t_eq();
}

TEST(char_traits_wchar_t, eq_int_type) {
  static_cast<void>(test_info_);

  test_string::char_traits_wchar_t_eq_int_type();
}

TEST(char_traits_wchar_t, find) {
  static_cast<void>(test_info_);

  test_string::char_traits_wchar_t_find();
}

TEST(char_traits_wchar_t, length) {
  static_cast<void>(test_info_);

  test_string::char_traits_wchar_t_length();
}

TEST(char_traits_wchar_t, lt) {
  static_cast<void>(test_info_);

  test_string::char_traits_wchar_t_lt();
}

TEST(char_traits_wchar_t, move) {
  static_cast<void>(test_info_);

  test_string::char_traits_wchar_t_move();
}

TEST(char_traits_wchar_t, to_char_type) {
  static_cast<void>(test_info_);

  test_string::char_traits_wchar_t_to_char_type();
}

TEST(char_traits_wchar_t, to_int_type) {
  static_cast<void>(test_info_);

  test_string::char_traits_wchar_t_to_int_type();
}
