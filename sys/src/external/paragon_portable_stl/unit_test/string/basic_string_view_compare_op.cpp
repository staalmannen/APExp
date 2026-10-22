// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="basic_string_view_compare_op.cpp"
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
  ℉  U+2108      8459             e2 84 88               2109
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
TEST(basic_string_view, op_eq) {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;
  ASSERT_TRUE(test_basic_string_view_helper::check_equal(t_sv(""), ""));
  ASSERT_TRUE(test_basic_string_view_helper::check_equal(t_sv("abyz"), "abyz"));
  ASSERT_TRUE(test_basic_string_view_helper::check_equal(t_sv("abyz¥ðбя"), "abyz¥ðбя"));
  ASSERT_TRUE(test_basic_string_view_helper::check_equal(t_sv("abyz¥ðбяࠀ℉"), "abyz¥ðбяࠀ℉"));
  ASSERT_TRUE(test_basic_string_view_helper::check_equal(t_sv("abyz¥ðбяࠀ℉𐀀𑊰"), "abyz¥ðбяࠀ℉𐀀𑊰"));
  ASSERT_TRUE(test_basic_string_view_helper::check_equal(t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv(""), "abyz"));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv(""), "abyz¥ðбя"));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv(""), "abyz¥ðбяࠀ℉"));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv(""), "abyz¥ðбяࠀ℉𐀀𑊰"));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv(""), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("abyz"), "abyz¥ðбя"));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("abyz"), "abyz¥ðбяࠀ℉"));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("abyz"), "abyz¥ðбяࠀ℉𐀀𑊰"));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("abyz"), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("abyz¥ðбя"), "abyz¥ðбяࠀ℉"));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("abyz¥ðбя"), "abyz¥ðбяࠀ℉𐀀𑊰"));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("abyz¥ðбя"), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("abyz¥ðбяࠀ℉"), "abyz¥ðбяࠀ℉𐀀𑊰"));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("abyz¥ðбяࠀ℉"), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("abyz"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("¥ðбя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("ࠀ℉"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("𐀀𑊰"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("𝄞😅"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"));

  ASSERT_TRUE(test_basic_string_view_helper::check_equal(t_sv(""), t_sv("")));
  ASSERT_TRUE(test_basic_string_view_helper::check_equal(t_sv("abyz"), t_sv("abyz")));
  ASSERT_TRUE(test_basic_string_view_helper::check_equal(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбя")));
  ASSERT_TRUE(test_basic_string_view_helper::check_equal(t_sv("abyz¥ðбяࠀ℉"), t_sv("abyz¥ðбяࠀ℉")));
  ASSERT_TRUE(test_basic_string_view_helper::check_equal(t_sv("abyz¥ðбяࠀ℉𐀀𑊰"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰")));
  ASSERT_TRUE(test_basic_string_view_helper::check_equal(t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅")));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv(""), t_sv("abyz")));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv(""), t_sv("abyz¥ðбя")));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv(""), t_sv("abyz¥ðбяࠀ℉")));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv(""), t_sv("abyz¥ðбяࠀ℉𐀀𑊰")));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv(""), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅")));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("abyz"), t_sv("abyz¥ðбя")));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("abyz"), t_sv("abyz¥ðбяࠀ℉")));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("abyz"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰")));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("abyz"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅")));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбяࠀ℉")));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰")));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅")));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("abyz¥ðбяࠀ℉"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰")));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("abyz¥ðбяࠀ℉"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅")));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv(""), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя")));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("abyz"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя")));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("¥ðбя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя")));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("ࠀ℉"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя")));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("𐀀𑊰"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя")));
  ASSERT_FALSE(test_basic_string_view_helper::check_equal(t_sv("𝄞😅"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя")));
}

TEST(basic_string_view, op_ne) {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;
  ASSERT_FALSE(test_basic_string_view_helper::check_not_equal(t_sv(""), ""));
  ASSERT_FALSE(test_basic_string_view_helper::check_not_equal(t_sv("abyz"), "abyz"));
  ASSERT_FALSE(test_basic_string_view_helper::check_not_equal(t_sv("abyz¥ðбя"), "abyz¥ðбя"));
  ASSERT_FALSE(test_basic_string_view_helper::check_not_equal(t_sv("abyz¥ðбяࠀ℉"), "abyz¥ðбяࠀ℉"));
  ASSERT_FALSE(test_basic_string_view_helper::check_not_equal(t_sv("abyz¥ðбяࠀ℉𐀀𑊰"), "abyz¥ðбяࠀ℉𐀀𑊰"));
  ASSERT_FALSE(test_basic_string_view_helper::check_not_equal(t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv(""), "abyz"));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv(""), "abyz¥ðбя"));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv(""), "abyz¥ðбяࠀ℉"));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv(""), "abyz¥ðбяࠀ℉𐀀𑊰"));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv(""), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("abyz"), "abyz¥ðбя"));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("abyz"), "abyz¥ðбяࠀ℉"));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("abyz"), "abyz¥ðбяࠀ℉𐀀𑊰"));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("abyz"), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("abyz¥ðбя"), "abyz¥ðбяࠀ℉"));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("abyz¥ðбя"), "abyz¥ðбяࠀ℉𐀀𑊰"));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("abyz¥ðбя"), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("abyz¥ðбяࠀ℉"), "abyz¥ðбяࠀ℉𐀀𑊰"));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("abyz¥ðбяࠀ℉"), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv(""), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("abyz"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("¥ðбя"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("ࠀ℉"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("𐀀𑊰"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("𝄞😅"), "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя"));

  ASSERT_FALSE(test_basic_string_view_helper::check_not_equal(t_sv(""), t_sv("")));
  ASSERT_FALSE(test_basic_string_view_helper::check_not_equal(t_sv("abyz"), t_sv("abyz")));
  ASSERT_FALSE(test_basic_string_view_helper::check_not_equal(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбя")));
  ASSERT_FALSE(test_basic_string_view_helper::check_not_equal(t_sv("abyz¥ðбяࠀ℉"), t_sv("abyz¥ðбяࠀ℉")));
  ASSERT_FALSE(test_basic_string_view_helper::check_not_equal(t_sv("abyz¥ðбяࠀ℉𐀀𑊰"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰")));
  ASSERT_FALSE(test_basic_string_view_helper::check_not_equal(t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅")));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv(""), t_sv("abyz")));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv(""), t_sv("abyz¥ðбя")));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv(""), t_sv("abyz¥ðбяࠀ℉")));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv(""), t_sv("abyz¥ðбяࠀ℉𐀀𑊰")));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv(""), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅")));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("abyz"), t_sv("abyz¥ðбя")));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("abyz"), t_sv("abyz¥ðбяࠀ℉")));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("abyz"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰")));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("abyz"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅")));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбяࠀ℉")));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰")));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅")));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("abyz¥ðбяࠀ℉"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰")));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("abyz¥ðбяࠀ℉"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅")));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv(""), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя")));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("abyz"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя")));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("¥ðбя"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя")));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("ࠀ℉"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя")));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("𐀀𑊰"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя")));
  ASSERT_TRUE(test_basic_string_view_helper::check_not_equal(t_sv("𝄞😅"), t_sv("a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя")));
}

TEST(basic_string_view, op_ge) {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;
  test_basic_string_view_helper::check_ge(t_sv(""), "", true, true);
  test_basic_string_view_helper::check_ge(t_sv(""), "abyz", false, true);
  test_basic_string_view_helper::check_ge(t_sv(""), "abyz¥ðбя", false, true);
  test_basic_string_view_helper::check_ge(t_sv(""), "abyz¥ðбяࠀ℉", false, true);
  test_basic_string_view_helper::check_ge(t_sv(""), "abyz¥ðбяࠀ℉𐀀𑊰", false, true);
  test_basic_string_view_helper::check_ge(t_sv(""), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅", false, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz"), "abyz", true, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz"), "abyz¥ðбя", false, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz"), "abyz¥ðбяࠀ℉", false, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz"), "abyz¥ðбяࠀ℉𐀀𑊰", false, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz"), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅", false, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz¥ðбя"), "abyz¥ðбя", true, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz¥ðбя"), "abyz¥ðбяࠀ℉", false, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz¥ðбя"), "abyz¥ðбяࠀ℉𐀀𑊰", false, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz¥ðбя"), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅", false, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz¥ðбяࠀ℉"), "abyz¥ðбяࠀ℉", true, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz¥ðбяࠀ℉"), "abyz¥ðбяࠀ℉𐀀𑊰", false, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz¥ðбяࠀ℉"), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅", false, true);

  test_basic_string_view_helper::check_ge(t_sv(""), t_sv(""), true, true);
  test_basic_string_view_helper::check_ge(t_sv(""), t_sv("abyz"), false, true);
  test_basic_string_view_helper::check_ge(t_sv(""), t_sv("abyz¥ðбя"), false, true);
  test_basic_string_view_helper::check_ge(t_sv(""), t_sv("abyz¥ðбяࠀ℉"), false, true);
  test_basic_string_view_helper::check_ge(t_sv(""), t_sv("abyz¥ðбяࠀ℉𐀀𑊰"), false, true);
  test_basic_string_view_helper::check_ge(t_sv(""), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"), false, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz"), t_sv("abyz"), true, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz"), t_sv("abyz¥ðбя"), false, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz"), t_sv("abyz¥ðбяࠀ℉"), false, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰"), false, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"), false, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбя"), true, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбяࠀ℉"), false, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰"), false, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"), false, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz¥ðбяࠀ℉"), t_sv("abyz¥ðбяࠀ℉"), true, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz¥ðбяࠀ℉"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰"), false, true);
  test_basic_string_view_helper::check_ge(t_sv("abyz¥ðбяࠀ℉"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"), false, true);
}

TEST(basic_string_view, op_gt) {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;
  test_basic_string_view_helper::check_gt(t_sv(""), "", false, false);
  test_basic_string_view_helper::check_gt(t_sv(""), "abyz", false, true);
  test_basic_string_view_helper::check_gt(t_sv(""), "abyz¥ðбя", false, true);
  test_basic_string_view_helper::check_gt(t_sv(""), "abyz¥ðбяࠀ℉", false, true);
  test_basic_string_view_helper::check_gt(t_sv(""), "abyz¥ðбяࠀ℉𐀀𑊰", false, true);
  test_basic_string_view_helper::check_gt(t_sv(""), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅", false, true);
  test_basic_string_view_helper::check_gt(t_sv("abyz"), "abyz", false, false);
  test_basic_string_view_helper::check_gt(t_sv("abyz"), "abyz¥ðбя", false, true);
  test_basic_string_view_helper::check_gt(t_sv("abyz"), "abyz¥ðбяࠀ℉", false, true);
  test_basic_string_view_helper::check_gt(t_sv("abyz"), "abyz¥ðбяࠀ℉𐀀𑊰", false, true);
  test_basic_string_view_helper::check_gt(t_sv("abyz"), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅", false, true);
  test_basic_string_view_helper::check_gt(t_sv("abyz¥ðбя"), "abyz¥ðбя", false, false);
  test_basic_string_view_helper::check_gt(t_sv("abyz¥ðбя"), "abyz¥ðбяࠀ℉", false, true);
  test_basic_string_view_helper::check_gt(t_sv("abyz¥ðбя"), "abyz¥ðбяࠀ℉𐀀𑊰", false, true);
  test_basic_string_view_helper::check_gt(t_sv("abyz¥ðбя"), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅", false, true);
  test_basic_string_view_helper::check_gt(t_sv("abyz¥ðбяࠀ℉"), "abyz¥ðбяࠀ℉", false, false);
  test_basic_string_view_helper::check_gt(t_sv("abyz¥ðбяࠀ℉"), "abyz¥ðбяࠀ℉𐀀𑊰", false, true);
  test_basic_string_view_helper::check_gt(t_sv("abyz¥ðбяࠀ℉"), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅", false, true);

  test_basic_string_view_helper::check_gt(t_sv(""), t_sv(""), false, false);
  test_basic_string_view_helper::check_gt(t_sv(""), t_sv("abyz"), false, true);
  test_basic_string_view_helper::check_gt(t_sv(""), t_sv("abyz¥ðбя"), false, true);
  test_basic_string_view_helper::check_gt(t_sv(""), t_sv("abyz¥ðбяࠀ℉"), false, true);
  test_basic_string_view_helper::check_gt(t_sv(""), t_sv("abyz¥ðбяࠀ℉𐀀𑊰"), false, true);
  test_basic_string_view_helper::check_gt(t_sv(""), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"), false, true);
  test_basic_string_view_helper::check_gt(t_sv("abyz"), t_sv("abyz"), false, false);
  test_basic_string_view_helper::check_gt(t_sv("abyz"), t_sv("abyz¥ðбя"), false, true);
  test_basic_string_view_helper::check_gt(t_sv("abyz"), t_sv("abyz¥ðбяࠀ℉"), false, true);
  test_basic_string_view_helper::check_gt(t_sv("abyz"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰"), false, true);
  test_basic_string_view_helper::check_gt(t_sv("abyz"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"), false, true);
  test_basic_string_view_helper::check_gt(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбя"), false, false);
  test_basic_string_view_helper::check_gt(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбяࠀ℉"), false, true);
  test_basic_string_view_helper::check_gt(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰"), false, true);
  test_basic_string_view_helper::check_gt(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"), false, true);
  test_basic_string_view_helper::check_gt(t_sv("abyz¥ðбяࠀ℉"), t_sv("abyz¥ðбяࠀ℉"), false, false);
  test_basic_string_view_helper::check_gt(t_sv("abyz¥ðбяࠀ℉"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰"), false, true);
  test_basic_string_view_helper::check_gt(t_sv("abyz¥ðбяࠀ℉"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"), false, true);
}

TEST(basic_string_view, op_le) {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;
  test_basic_string_view_helper::check_le(t_sv(""), "", true, true);
  test_basic_string_view_helper::check_le(t_sv(""), "abyz", true, false);
  test_basic_string_view_helper::check_le(t_sv(""), "abyz¥ðбя", true, false);
  test_basic_string_view_helper::check_le(t_sv(""), "abyz¥ðбяࠀ℉", true, false);
  test_basic_string_view_helper::check_le(t_sv(""), "abyz¥ðбяࠀ℉𐀀𑊰", true, false);
  test_basic_string_view_helper::check_le(t_sv(""), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅", true, false);
  test_basic_string_view_helper::check_le(t_sv("abyz"), "abyz", true, true);
  test_basic_string_view_helper::check_le(t_sv("abyz"), "abyz¥ðбя", true, false);
  test_basic_string_view_helper::check_le(t_sv("abyz"), "abyz¥ðбяࠀ℉", true, false);
  test_basic_string_view_helper::check_le(t_sv("abyz"), "abyz¥ðбяࠀ℉𐀀𑊰", true, false);
  test_basic_string_view_helper::check_le(t_sv("abyz"), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅", true, false);
  test_basic_string_view_helper::check_le(t_sv("abyz¥ðбя"), "abyz¥ðбя", true, true);
  test_basic_string_view_helper::check_le(t_sv("abyz¥ðбя"), "abyz¥ðбяࠀ℉", true, false);
  test_basic_string_view_helper::check_le(t_sv("abyz¥ðбя"), "abyz¥ðбяࠀ℉𐀀𑊰", true, false);
  test_basic_string_view_helper::check_le(t_sv("abyz¥ðбя"), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅", true, false);
  test_basic_string_view_helper::check_le(t_sv("abyz¥ðбяࠀ℉"), "abyz¥ðбяࠀ℉", true, true);
  test_basic_string_view_helper::check_le(t_sv("abyz¥ðбяࠀ℉"), "abyz¥ðбяࠀ℉𐀀𑊰", true, false);
  test_basic_string_view_helper::check_le(t_sv("abyz¥ðбяࠀ℉"), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅", true, false);

  test_basic_string_view_helper::check_le(t_sv(""), t_sv(""), true, true);
  test_basic_string_view_helper::check_le(t_sv(""), t_sv("abyz"), true, false);
  test_basic_string_view_helper::check_le(t_sv(""), t_sv("abyz¥ðбя"), true, false);
  test_basic_string_view_helper::check_le(t_sv(""), t_sv("abyz¥ðбяࠀ℉"), true, false);
  test_basic_string_view_helper::check_le(t_sv(""), t_sv("abyz¥ðбяࠀ℉𐀀𑊰"), true, false);
  test_basic_string_view_helper::check_le(t_sv(""), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"), true, false);
  test_basic_string_view_helper::check_le(t_sv("abyz"), t_sv("abyz"), true, true);
  test_basic_string_view_helper::check_le(t_sv("abyz"), t_sv("abyz¥ðбя"), true, false);
  test_basic_string_view_helper::check_le(t_sv("abyz"), t_sv("abyz¥ðбяࠀ℉"), true, false);
  test_basic_string_view_helper::check_le(t_sv("abyz"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰"), true, false);
  test_basic_string_view_helper::check_le(t_sv("abyz"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"), true, false);
  test_basic_string_view_helper::check_le(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбя"), true, true);
  test_basic_string_view_helper::check_le(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбяࠀ℉"), true, false);
  test_basic_string_view_helper::check_le(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰"), true, false);
  test_basic_string_view_helper::check_le(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"), true, false);
  test_basic_string_view_helper::check_le(t_sv("abyz¥ðбяࠀ℉"), t_sv("abyz¥ðбяࠀ℉"), true, true);
  test_basic_string_view_helper::check_le(t_sv("abyz¥ðбяࠀ℉"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰"), true, false);
  test_basic_string_view_helper::check_le(t_sv("abyz¥ðбяࠀ℉"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"), true, false);
}

TEST(basic_string_view, op_lt) {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;
  test_basic_string_view_helper::check_lt(t_sv(""), "", false, false);
  test_basic_string_view_helper::check_lt(t_sv(""), "abyz", true, false);
  test_basic_string_view_helper::check_lt(t_sv(""), "abyz¥ðбя", true, false);
  test_basic_string_view_helper::check_lt(t_sv(""), "abyz¥ðбяࠀ℉", true, false);
  test_basic_string_view_helper::check_lt(t_sv(""), "abyz¥ðбяࠀ℉𐀀𑊰", true, false);
  test_basic_string_view_helper::check_lt(t_sv(""), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅", true, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz"), "abyz", false, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz"), "abyz¥ðбя", true, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz"), "abyz¥ðбяࠀ℉", true, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz"), "abyz¥ðбяࠀ℉𐀀𑊰", true, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz"), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅", true, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz¥ðбя"), "abyz¥ðбя", false, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz¥ðбя"), "abyz¥ðбяࠀ℉", true, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz¥ðбя"), "abyz¥ðбяࠀ℉𐀀𑊰", true, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz¥ðбя"), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅", true, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz¥ðбяࠀ℉"), "abyz¥ðбяࠀ℉", false, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz¥ðбяࠀ℉"), "abyz¥ðбяࠀ℉𐀀𑊰", true, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz¥ðбяࠀ℉"), "abyz¥ðбяࠀ℉𐀀𑊰𝄞😅", true, false);

  test_basic_string_view_helper::check_lt(t_sv(""), t_sv(""), false, false);
  test_basic_string_view_helper::check_lt(t_sv(""), t_sv("abyz"), true, false);
  test_basic_string_view_helper::check_lt(t_sv(""), t_sv("abyz¥ðбя"), true, false);
  test_basic_string_view_helper::check_lt(t_sv(""), t_sv("abyz¥ðбяࠀ℉"), true, false);
  test_basic_string_view_helper::check_lt(t_sv(""), t_sv("abyz¥ðбяࠀ℉𐀀𑊰"), true, false);
  test_basic_string_view_helper::check_lt(t_sv(""), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"), true, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz"), t_sv("abyz"), false, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz"), t_sv("abyz¥ðбя"), true, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz"), t_sv("abyz¥ðбяࠀ℉"), true, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰"), true, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"), true, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбя"), false, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбяࠀ℉"), true, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰"), true, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz¥ðбя"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"), true, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz¥ðбяࠀ℉"), t_sv("abyz¥ðбяࠀ℉"), false, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz¥ðбяࠀ℉"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰"), true, false);
  test_basic_string_view_helper::check_lt(t_sv("abyz¥ðбяࠀ℉"), t_sv("abyz¥ðбяࠀ℉𐀀𑊰𝄞😅"), true, false);
}
