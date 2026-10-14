// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="char_traits_char8_t.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#if defined(__cpp_char8_t)
#  include "char8_t/test_char_traits_char8_t.h"
#else
#  include "char8_t/test_char_traits_no_char8_t.h"
#endif

TEST(char_traits_char8_t, access2) {
  static_cast<void>(test_info_);

  test_string::char_traits_char8_t_access2();
}

TEST(char_traits_char8_t, access3) {
  static_cast<void>(test_info_);

  test_string::char_traits_char8_t_access3();
}

TEST(char_traits_char8_t, compare) {
  static_cast<void>(test_info_);

  test_string::char_traits_char8_t_compare();
}

TEST(char_traits_char8_t, copy) {
  static_cast<void>(test_info_);

  test_string::char_traits_char8_t_copy();
}

TEST(char_traits_char8_t, eof) {
  static_cast<void>(test_info_);

  test_string::char_traits_char8_t_eof();
}

TEST(char_traits_char8_t, not_eof) {
  static_cast<void>(test_info_);

  test_string::char_traits_char8_t_not_eof();
}

TEST(char_traits_char8_t, eq) {
  static_cast<void>(test_info_);

  test_string::char_traits_char8_t_eq();
}

TEST(char_traits_char8_t, eq_int_type) {
  static_cast<void>(test_info_);

  test_string::char_traits_char8_t_eq_int_type();
}

TEST(char_traits_char8_t, find) {
  static_cast<void>(test_info_);

  test_string::char_traits_char8_t_find();
}

TEST(char_traits_char8_t, length) {
  static_cast<void>(test_info_);

  test_string::char_traits_char8_t_length();
}

TEST(char_traits_char8_t, lt) {
  static_cast<void>(test_info_);

  test_string::char_traits_char8_t_lt();
}

TEST(char_traits_char8_t, move) {
  static_cast<void>(test_info_);

  test_string::char_traits_char8_t_move();
}

TEST(char_traits_char8_t, to_char_type) {
  static_cast<void>(test_info_);

  test_string::char_traits_char8_t_to_char_type();
}

TEST(char_traits_char8_t, to_int_type) {
  static_cast<void>(test_info_);

  test_string::char_traits_char8_t_to_int_type();
}
