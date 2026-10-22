// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="basic_string_view_find.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "basic_string_view_helper.h"
#include "portable_stl/string/basic_string_view.h"
#include "portable_stl/string/string_view.h"

/*
        hex       dec       utf-8 code units    utf-16 code units
  a   U+0061        97                   61               0061
  z   U+007A       122                   7a               0074
  ¥   U+00A5       164                ca a5               00a5
  ð   U+00F0       240                c3 b0               00f0
  б   U+0431      1073                d0 b1               0431
  я   U+044F      1103                d1 8f               044f
  ࠀ  U+0800      2048             e0 a0 80               0800
  ℉  U+2108      8457             e2 84 88               2109
  𐀀  U+10000     65536          f0 90 80 80         d800 dc00
  𑊰 U+112B0     70320           f0 91 8a b0         d801 dd00
  𝄞  U+1D11E    119070          f0 9d 84 9e         d834 dd1e
  😅 U+1F605    128517          f0 9f 98 85	        d83d de05

  abyz
  abyz¥ð
  abyz¥ðбя
  abyz¥ðбяࠀ℉
  abyz¥ðбяࠀ℉𐀀𑊰
  abyz¥ðбяࠀ℉𐀀𑊰𝄞😅

  𑊰a¥ࠀ𐀀¥яbyz😅℉б𝄞 // shuffled
  a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя

*/

TEST(string_view, find_char_start_position) {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;
  test_basic_string_view_helper::check_find(t_sv(""), "a"[0], 0, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv(""), "a"[0], 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "я"[0], 0, 32);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "я"[0], 16, 32);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "я"[0], 32, 32);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "я"[0], 33, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "б"[0], 0, 21);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "б"[0], 22, 55);
  test_basic_string_view_helper::check_find(
    t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "б"[0], 100, t_sv::npos);
  test_basic_string_view_helper::check_find(
    t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "𝄞"[0], 0, 1); // found f0 in 😅 !
}

TEST(string_view, find_char) /* from start */ {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;
  test_basic_string_view_helper::check_find(t_sv(""), "b"[0], t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "b"[0], 5);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "b"[0], 5);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "b"[0], 5);
}

TEST(string_view, find_string_view_start_position) {
  static_cast<void>(test_info_);

  // clang-format off
  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;
  test_basic_string_view_helper::check_find(t_sv(""), t_sv(""), 0, 0);
  test_basic_string_view_helper::check_find(t_sv(""), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv(""), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv(""), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv(""), t_sv(""), 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv(""), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv(""), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv(""), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 1, 1);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 34, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 34, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 34, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 34, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 35, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 35, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 35, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 35, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 1, 1);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 1, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 4, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 34, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 34, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 34, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 34, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 35, 35);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 35, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 35, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 35, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 1, 1);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 1, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 1, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 35, 35);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 35, 68);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 35, 68);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 35, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 69, 69);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 69, 102);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 69, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 69, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 103, 103);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 103, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 103, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 103, t_sv::npos);
  // clang-format on
}

TEST(string_view, find_string_view) /* from start */ {
  static_cast<void>(test_info_);

  // clang-format off
  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;
  test_basic_string_view_helper::check_find(t_sv(""), t_sv(""), 0);
  test_basic_string_view_helper::check_find(t_sv(""), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv::npos);
  // clang-format on
}

TEST(string_view, find_pointer_start_position) {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;
  // clang-format off
  test_basic_string_view_helper::check_find(t_sv(""), "", 0, 0);
  test_basic_string_view_helper::check_find(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv(""), "", 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, t_sv::npos);

  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 1, 1);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 34, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 35, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, t_sv::npos);

  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 1, 1);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 34, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 35, 35);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, t_sv::npos);
  
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 1, 1);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 35, 35);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, 68);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, 68);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 68, 68);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 68, 68);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 68, 68);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 68, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 69, 69);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 69, 102);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 69, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 69, t_sv::npos);
  // clang-format on
}

TEST(string_view, find_pointer) /* from start */ {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;
  // clang-format off
  test_basic_string_view_helper::check_find(t_sv(""), "", 0);
  test_basic_string_view_helper::check_find(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", t_sv::npos);

  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", t_sv::npos);

  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", t_sv::npos);

  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0);
  // clang-format on
}

TEST(string_view, find_pointer_start_position_size) {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;
  test_basic_string_view_helper::check_find(t_sv(""), "", 0, 0, 0);

  test_basic_string_view_helper::check_find(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 0, 0);
  test_basic_string_view_helper::check_find(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 34, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 35, t_sv::npos);

  test_basic_string_view_helper::check_find(t_sv(""), "", 1, 0, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 0, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 34, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 35, t_sv::npos);

  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 0, 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 1, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 34, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 35, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 1, 0, 1);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 0, 1);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 34, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 35, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 34, 0, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 0, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 34, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 35, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 35, 0, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, 0, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, 1, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, 34, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, 35, t_sv::npos);

  // clang-format off
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 0, 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 1, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 34, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 35, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 0, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 1, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 34, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 68, 0);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 69, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 1, 0, 1);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 0, 1);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 1, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 34, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 0, 1);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 1, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 34, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 35, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 69, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 34, 0, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 0, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 1, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 34, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 0, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 1, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 34, 34);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 35, t_sv::npos);
  test_basic_string_view_helper::check_find(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 69, t_sv::npos);
  // clang-format on
}

TEST(string_view, rfind_char_end_position) {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;
  test_basic_string_view_helper::check_rfind(t_sv(""), "a"[0], 0, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv(""), "a"[0], 1, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 2, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 33, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 34, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 33, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 34, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 68, 34);
    // clang-format off
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 33, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 34, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 67, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 68, 68);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 101, 68);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 102, 102);
  // clang-format on
}

TEST(string_view, rfind_char) /* from end */{
  static_cast<void>(test_info_);

  // clang-format off
  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;
  test_basic_string_view_helper::check_rfind(t_sv(""), "a"[0], 0, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a"[0], 102);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "😅"[0], 128); // found x\f0 in 𐀀
  // clang-format on
}

TEST(string_view, rfind_string_view_end_position) {
  static_cast<void>(test_info_);

  // clang-format off
  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;
  test_basic_string_view_helper::check_rfind(t_sv(""), t_sv(""), 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv(""), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv(""), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv(""), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv(""), t_sv(""), 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv(""), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 1, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv(""), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 1, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv(""), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 1, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 1, 1);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 1, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 1, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 34, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 34, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 34, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 34, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 35, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 35, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 35, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 35, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 1, 1);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 4, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 34, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 34, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 34, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 34, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 35, 35);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 35, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 35, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 35, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 69, 68);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 69, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 69, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 69, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 1, 1);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 35, 35);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 35, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 35, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 35, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 69, 69);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 69, 68);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 69, 68);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 69, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 103, 103);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 103, 102);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 103, 68);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 103, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 137, 136);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 137, 102);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 137, 68);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 137, 0);
  // clang-format on
}

TEST(string_view, rfind_string_view) /* from end */ {
  static_cast<void>(test_info_);

  // clang-format off
  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;
  test_basic_string_view_helper::check_rfind(t_sv(""), t_sv(""), 0);
  test_basic_string_view_helper::check_rfind(t_sv(""), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv(""), 68);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), t_sv::npos);
  // clang-format on
}

TEST(string_view, rfind_pointer_start_position_size) {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;
  test_basic_string_view_helper::check_rfind(t_sv(""), "", 0, 0, 0);

  test_basic_string_view_helper::check_rfind(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 1, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 34, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 35, t_sv::npos);

  test_basic_string_view_helper::check_rfind(t_sv(""), "", 1, 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 1, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 34, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 35, t_sv::npos);

  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 0, 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 34, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 35, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 1, 0, 1);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 0, 1);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 34, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 35, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 34, 0, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 0, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 34, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 35, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 35, 0, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, 0, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, 34, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, 35, t_sv::npos);

  // // clang-format off
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 0, 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 34, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 35, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 34, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 68, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 69, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 1, 0, 1);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 0, 1);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 34, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 0, 1);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 34, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 35, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 68, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 69, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 34, 0, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 0, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 1, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 34, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 0, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 1, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 34, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 35, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 68, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 69, t_sv::npos);
  // // clang-format on
}

TEST(string_view, rfind_pointer_start_position) {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;
  // clang-format off
  test_basic_string_view_helper::check_rfind(t_sv(""), "", 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv(""), "", 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, t_sv::npos);

  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 1, 1);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 34, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 35, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, t_sv::npos);

  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 1, 1);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 34, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34, t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 35, 35);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, t_sv::npos);
  
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 1, 1);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 1, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 35, 35);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 35, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 68, 68);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 68, 68);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 68, 68);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 68, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 69, 69);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 69, 68);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 69, 68);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 69, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 102, 102);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 102, 102);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 102, 68);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 102, 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 103, 103);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 103, 102);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 103, 68);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 103, 0);
  // clang-format on
}

TEST(string_view, rfind_pointer) /* from end */ {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;
  // clang-format off
  test_basic_string_view_helper::check_rfind(t_sv(""), "", 0);
  test_basic_string_view_helper::check_rfind(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", t_sv::npos);

  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", t_sv::npos);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", t_sv::npos);

  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 68);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 34);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", t_sv::npos);

  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "", 136);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 102);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 68);
  test_basic_string_view_helper::check_rfind(t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðяa😅b𝄞¥𑊰℉yzбࠀ𐀀ðя", 0);
  // clang-format on
}
