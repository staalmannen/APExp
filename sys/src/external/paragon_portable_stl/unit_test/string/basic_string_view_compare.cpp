// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="basic_string_view_compare.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <string>

#include "basic_string_view_helper.h"
#include "portable_stl/string/basic_string_view.h"
#include "portable_stl/string/string_view.h"

TEST(basic_string_view, compare_string_view) {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;

  EXPECT_EQ(0, t_sv("").compare(t_sv("")));
  EXPECT_EQ(-1, t_sv("").compare(t_sv("abcde")));
  EXPECT_EQ(-1, t_sv("").compare(t_sv("abcdefghij")));
  EXPECT_EQ(-1, t_sv("").compare(t_sv("abcdefghijklmnopqrst")));

  EXPECT_EQ(+1, t_sv("abcde").compare(t_sv("")));
  EXPECT_EQ(0, t_sv("abcde").compare(t_sv("abcde")));
  EXPECT_EQ(-1, t_sv("abcde").compare(t_sv("abcdefghij")));
  EXPECT_EQ(-1, t_sv("abcde").compare(t_sv("abcdefghijklmnopqrst")));

  EXPECT_EQ(+1, t_sv("abcdefghij").compare(t_sv("")));
  EXPECT_EQ(+1, t_sv("abcdefghij").compare(t_sv("abcde")));
  EXPECT_EQ(0, t_sv("abcdefghij").compare(t_sv("abcdefghij")));
  EXPECT_EQ(-1, t_sv("abcdefghij").compare(t_sv("abcdefghijklmnopqrst")));

  EXPECT_EQ(+1, t_sv("abcdefghijklmnopqrst").compare(t_sv("")));
  EXPECT_EQ(+1, t_sv("abcdefghijklmnopqrst").compare(t_sv("abcde")));
  EXPECT_EQ(+1, t_sv("abcdefghijklmnopqrst").compare(t_sv("abcdefghij")));
  EXPECT_EQ(0, t_sv("abcdefghijklmnopqrst").compare(t_sv("abcdefghijklmnopqrst")));
}

TEST(basic_string_view, compare_pointer) {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;

  EXPECT_EQ(0, t_sv("").compare(""));
  EXPECT_EQ(-1, t_sv("").compare("abcde"));
  EXPECT_EQ(-1, t_sv("").compare("abcdefghij"));
  EXPECT_EQ(-1, t_sv("").compare("abcdefghijklmnopqrst"));

  EXPECT_EQ(+1, t_sv("abcde").compare(""));
  EXPECT_EQ(0, t_sv("abcde").compare("abcde"));
  EXPECT_EQ(-1, t_sv("abcde").compare("abcdefghij"));
  EXPECT_EQ(-1, t_sv("abcde").compare("abcdefghijklmnopqrst"));

  EXPECT_EQ(+1, t_sv("abcdefghij").compare(""));
  EXPECT_EQ(+1, t_sv("abcdefghij").compare("abcde"));
  EXPECT_EQ(0, t_sv("abcdefghij").compare("abcdefghij"));
  EXPECT_EQ(-1, t_sv("abcdefghij").compare("abcdefghijklmnopqrst"));

  EXPECT_EQ(+1, t_sv("abcdefghijklmnopqrst").compare(""));
  EXPECT_EQ(+1, t_sv("abcdefghijklmnopqrst").compare("abcde"));
  EXPECT_EQ(+1, t_sv("abcdefghijklmnopqrst").compare("abcdefghij"));
  EXPECT_EQ(0, t_sv("abcdefghijklmnopqrst").compare("abcdefghijklmnopqrst"));
}

namespace test_string_helper {

static std::int32_t normalize_cmp(std::int32_t value) {
  return (value < 0) ? -1 : (value > 0) ? 1 : 0;
}

static void test_compare_start_pos_size_string_view(::portable_stl::string_view const              &sv,
                                                    typename ::portable_stl::string_view::size_type start_pos,
                                                    typename ::portable_stl::string_view::size_type num,
                                                    ::portable_stl::string_view const              &sv_other,
                                                    int                                             result_expected,
                                                    bool error_expected = false) {
  auto result = sv.compare(start_pos, num, sv_other);
  ASSERT_EQ(error_expected, result.has_error());

  if (result.has_error()) {
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  } else {
    EXPECT_EQ(result_expected, normalize_cmp(result.value()));
  }
}

static void test_compare_start_pos_size_pointer(::portable_stl::string_view const                  &sv,
                                                typename ::portable_stl::string_view::size_type     start_pos,
                                                typename ::portable_stl::string_view::size_type     num,
                                                typename ::portable_stl::string_view::const_pointer str,
                                                int                                                 result_expected,
                                                bool error_expected = false) {
  auto result = sv.compare(start_pos, num, str);
  ASSERT_EQ(error_expected, result.has_error());

  if (result.has_error()) {
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  } else {
    EXPECT_EQ(result_expected, normalize_cmp(result.value()));
  }
}

static void test_compare_start_pos_size_pointer_size(::portable_stl::string_view const                  &sv,
                                                     typename ::portable_stl::string_view::size_type     start_pos,
                                                     typename ::portable_stl::string_view::size_type     num,
                                                     typename ::portable_stl::string_view::const_pointer str,
                                                     typename ::portable_stl::string_view::size_type     num2,
                                                     int  result_expected,
                                                     bool error_expected = false) {
  auto result = sv.compare(start_pos, num, str, num2);
  ASSERT_EQ(error_expected, result.has_error());

  if (result.has_error()) {
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  } else {
    EXPECT_EQ(result_expected, normalize_cmp(result.value()));
  }
}

static void test_compare_start_pos_size_string_view_start_pos_size(
  ::portable_stl::string_view const              &sv,
  typename ::portable_stl::string_view::size_type start_pos,
  typename ::portable_stl::string_view::size_type num,
  ::portable_stl::string_view const              &sv_other,
  typename ::portable_stl::string_view::size_type start_pos2,
  typename ::portable_stl::string_view::size_type num2,
  int                                             result_expected,
  bool                                            error_expected = false) {
  auto result = sv.compare(start_pos, num, sv_other, start_pos2, num2);
  ASSERT_EQ(error_expected, result.has_error());

  if (result.has_error()) {
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  } else {
    EXPECT_EQ(result_expected, normalize_cmp(result.value()));
  }
}
} // namespace test_string_helper

TEST(basic_string_view, compare_start_pos_size_string_view) {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;

  test_string_helper::test_compare_start_pos_size_string_view(t_sv(""), 0, 0, t_sv(""), 0);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv(""), 0, 0, t_sv("abcde"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv(""), 0, 0, t_sv("abcdefghij"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv(""), 0, 0, t_sv("abcdefghijklmnopqrst"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv(""), 0, 1, t_sv(""), 0);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv(""), 0, 1, t_sv("abcde"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv(""), 0, 1, t_sv("abcdefghij"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv(""), 0, 1, t_sv("abcdefghijklmnopqrst"), -1);

  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 0, 0, t_sv(""), 0);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 0, 0, t_sv("abcde"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 0, 0, t_sv("abcdefghij"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 0, 0, t_sv("abcdefghijklmnopqrst"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 0, 1, t_sv(""), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 0, 1, t_sv("abcde"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 0, 1, t_sv("abcdefghij"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 0, 1, t_sv("abcdefghijklmnopqrst"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 0, 5, t_sv(""), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 0, 5, t_sv("abcde"), 0);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 0, 5, t_sv("abcdefghij"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 0, 5, t_sv("abcdefghijklmnopqrst"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 0, 6, t_sv(""), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 0, 6, t_sv("abcde"), 0);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 0, 6, t_sv("abcdefghij"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 0, 6, t_sv("abcdefghijklmnopqrst"), -1);

  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 1, 0, t_sv(""), 0);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 1, 0, t_sv("abcde"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 1, 0, t_sv("abcdefghij"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 1, 0, t_sv("abcdefghijklmnopqrst"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 1, 1, t_sv(""), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 1, 1, t_sv("abcde"), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 1, 1, t_sv("abcdefghij"), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 1, 1, t_sv("abcdefghijklmnopqrst"), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 1, 2, t_sv(""), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 1, 2, t_sv("abcde"), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 1, 2, t_sv("abcdefghij"), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 1, 2, t_sv("abcdefghijklmnopqrst"), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 1, 5, t_sv(""), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 1, 5, t_sv("abcde"), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 1, 5, t_sv("abcdefghij"), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 1, 5, t_sv("abcdefghijklmnopqrst"), +1);

  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 2, 0, t_sv(""), 0);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 2, 0, t_sv("abcde"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 2, 0, t_sv("abcdefghij"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 2, 0, t_sv("abcdefghijklmnopqrst"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 2, 1, t_sv(""), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 2, 1, t_sv("abcde"), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 2, 1, t_sv("abcdefghij"), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 2, 1, t_sv("abcdefghijklmnopqrst"), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 2, 2, t_sv(""), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 2, 2, t_sv("abcde"), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 2, 2, t_sv("abcdefghij"), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 2, 2, t_sv("abcdefghijklmnopqrst"), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 2, 4, t_sv(""), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 2, 4, t_sv("abcde"), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 2, 4, t_sv("abcdefghij"), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 2, 4, t_sv("abcdefghijklmnopqrst"), +1);

  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 5, 0, t_sv(""), 0);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 5, 0, t_sv("abcde"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 5, 0, t_sv("abcdefghij"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 5, 0, t_sv("abcdefghijklmnopqrst"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 5, 1, t_sv(""), 0);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 5, 1, t_sv("abcde"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 5, 1, t_sv("abcdefghij"), -1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 5, 1, t_sv("abcdefghijklmnopqrst"), -1);

  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcdefghij"), 0, 10, t_sv(""), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcdefghij"), 0, 10, t_sv("abcde"), +1);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcdefghij"), 0, 10, t_sv("abcdefghij"), 0);
  test_string_helper::test_compare_start_pos_size_string_view(
    t_sv("abcdefghij"), 0, 10, t_sv("abcdefghijklmnopqrst"), -1);

  test_string_helper::test_compare_start_pos_size_string_view(t_sv(""), 1, 1, t_sv(""), 0, true); // substr
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 5, 0, t_sv(""), 0);
  test_string_helper::test_compare_start_pos_size_string_view(t_sv("abcde"), 6, 0, t_sv(""), 0, true); // substr
}

TEST(basic_string_view, compare_start_pos_size_pointer) {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;

  test_string_helper::test_compare_start_pos_size_pointer(t_sv(""), 0, 0, "", 0);
  test_string_helper::test_compare_start_pos_size_pointer(t_sv("abcde"), 0, 0, "", 0);
  test_string_helper::test_compare_start_pos_size_pointer(t_sv("abcde"), 0, 1, "", +1);
  test_string_helper::test_compare_start_pos_size_pointer(t_sv("abcde"), 0, 5, "", +1);
  test_string_helper::test_compare_start_pos_size_pointer(t_sv("abcde"), 0, 5, "abcdefghij", -1);
  test_string_helper::test_compare_start_pos_size_pointer(t_sv("abcde"), 0, 6, "abcdefghijklmnopqrst", -1);
  test_string_helper::test_compare_start_pos_size_pointer(t_sv("abcde"), 1, 0, "", 0);
  test_string_helper::test_compare_start_pos_size_pointer(t_sv("abcde"), 1, 0, "abcdefghijklmnopqrst", -1);
  test_string_helper::test_compare_start_pos_size_pointer(t_sv("abcde"), 2, 0, "", 0);
  test_string_helper::test_compare_start_pos_size_pointer(t_sv("abcde"), 2, 1, "abcdefghij", +1);
  test_string_helper::test_compare_start_pos_size_pointer(t_sv("abcde"), 2, 2, "abcdefghijklmnopqrst", +1);
  test_string_helper::test_compare_start_pos_size_pointer(t_sv("abcde"), 5, 1, "abcdefghijklmnopqrst", -1);

  test_string_helper::test_compare_start_pos_size_pointer(t_sv(""), 1, 1, "", 0, true); // substr
  test_string_helper::test_compare_start_pos_size_pointer(t_sv("abcde"), 5, 0, "", 0);
  test_string_helper::test_compare_start_pos_size_pointer(t_sv("abcde"), 6, 0, "", 0, true); // substr
}

TEST(basic_string_view, compare_start_pos_size_pointer_size) {
  static_cast<void>(test_info_);

  // no need to check all combinations again and again.
  // substr_res . compare(basic_string_view{str_ptr, num}

  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;

  test_string_helper::test_compare_start_pos_size_pointer_size(t_sv(""), 0, 0, "", 0, 0);
  test_string_helper::test_compare_start_pos_size_pointer_size(t_sv("abcde"), 0, 0, "", 0, 0);
  test_string_helper::test_compare_start_pos_size_pointer_size(t_sv("abcde"), 0, 1, "", 0, +1);
  test_string_helper::test_compare_start_pos_size_pointer_size(t_sv("abcde"), 0, 5, "", 0, +1);

  test_string_helper::test_compare_start_pos_size_pointer_size(t_sv("abcde"), 0, 5, "abcdefghij", 10, -1);
  test_string_helper::test_compare_start_pos_size_pointer_size(t_sv("abcde"), 0, 6, "abcdefghijklmnopqrst", 20, -1);
  test_string_helper::test_compare_start_pos_size_pointer_size(t_sv("abcde"), 1, 0, "", 0, 0);
  test_string_helper::test_compare_start_pos_size_pointer_size(t_sv("abcde"), 1, 0, "abcdefghijklmnopqrst", 20, -1);
  test_string_helper::test_compare_start_pos_size_pointer_size(t_sv("abcde"), 2, 0, "", 0, 0);
  test_string_helper::test_compare_start_pos_size_pointer_size(t_sv("abcde"), 2, 1, "abcdefghij", 10, +1);
  test_string_helper::test_compare_start_pos_size_pointer_size(t_sv("abcde"), 2, 2, "abcdefghijklmnopqrst", 20, +1);
  test_string_helper::test_compare_start_pos_size_pointer_size(t_sv("abcde"), 5, 1, "abcdefghijklmnopqrst", 20, -1);

  test_string_helper::test_compare_start_pos_size_pointer_size(t_sv(""), 1, 1, "", 0, 0, true); // substr
  test_string_helper::test_compare_start_pos_size_pointer_size(t_sv("abcde"), 5, 0, "", 0, 0);
  test_string_helper::test_compare_start_pos_size_pointer_size(t_sv("abcde"), 6, 0, "", 0, 0, true); // substr
}

TEST(basic_string_view, compare_start_pos_size_string_view_start_pos_size) {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias.
   */
  using t_sv = ::portable_stl::string_view;
  // clang-format off
  test_string_helper::test_compare_start_pos_size_string_view_start_pos_size(t_sv(""), 0, 0, t_sv(""), 0, 0, 0);

  test_string_helper::test_compare_start_pos_size_string_view_start_pos_size(t_sv("abcd"), 0, 0, t_sv("abcd"), 0, 0, 0);

  test_string_helper::test_compare_start_pos_size_string_view_start_pos_size(t_sv("abcd"), 0, 4, t_sv("abcd"), 0, 4, 0);
  test_string_helper::test_compare_start_pos_size_string_view_start_pos_size(t_sv("abqd"), 0, 4, t_sv("abcd"), 0, 4, +1);
  test_string_helper::test_compare_start_pos_size_string_view_start_pos_size(t_sv("abcd"), 0, 4, t_sv("abqd"), 0, 4, -1);

  test_string_helper::test_compare_start_pos_size_string_view_start_pos_size(t_sv("abcd"), 4, 4, t_sv("abcd"), 4, 4, 0);
  test_string_helper::test_compare_start_pos_size_string_view_start_pos_size(t_sv("abcd"), 4, 20, t_sv("abcd"), 4, 20, 0);
  test_string_helper::test_compare_start_pos_size_string_view_start_pos_size(t_sv("abcd"), 4, 4, t_sv("abcd"), 4, 20, 0);
  test_string_helper::test_compare_start_pos_size_string_view_start_pos_size(t_sv("abcd"), 4, 20, t_sv("abcd"), 4, 4, 0);

  test_string_helper::test_compare_start_pos_size_string_view_start_pos_size(t_sv("abcd"), 5, 0, t_sv("abcd"), 0, 4, 0, true);
  test_string_helper::test_compare_start_pos_size_string_view_start_pos_size(t_sv("abcd"), 5, 1, t_sv("abcd"), 0, 4, 0, true);

  test_string_helper::test_compare_start_pos_size_string_view_start_pos_size(t_sv("abcd"), 0, 4, t_sv("abcd"), 5, 0, 0, true);
  test_string_helper::test_compare_start_pos_size_string_view_start_pos_size(t_sv("abcd"), 0, 4, t_sv("abcd"), 5, 1, 0, true);
  // clang-format on
}

TEST(basic_string_view, compare_1) {
  static_cast<void>(test_info_);

  /**
   * @brief Char type alias.
   */
  using t_char_type   = char;
  /**
   * @brief Test string view type.
   */
  using t_string_view = ::portable_stl::basic_string_view<t_char_type>;

  t_string_view sw1{"abc"};
  t_string_view sw2{"abc"};

  {
    auto result = sw2.compare(0, sw2.size(), sw1);
    ASSERT_FALSE(result.has_error());
    EXPECT_EQ(0, result.value());
  }
  {
    auto result = sw2.compare(sw2.size() + 1, 1, sw1);
    ASSERT_TRUE(result.has_error());
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }

  {
    auto result = sw2.compare(0, sw2.size(), sw1, 0, sw1.size());
    ASSERT_FALSE(result.has_error());
    EXPECT_EQ(0, result.value());
  }
  {
    auto result = sw2.compare(sw2.size() + 1, 1, sw1, 0, sw1.size());
    ASSERT_TRUE(result.has_error());
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = sw2.compare(0, sw2.size(), sw1, sw1.size() + 1, 1);
    ASSERT_TRUE(result.has_error());
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
  {
    auto result = sw2.compare(sw2.size() + 1, 1, sw1, sw1.size() + 1, 1);
    ASSERT_TRUE(result.has_error());
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }

  {
    auto result = sw2.compare(0, sw2.size(), sw1.begin());
    ASSERT_FALSE(result.has_error());
    EXPECT_EQ(0, result.value());
  }
  {
    auto result = sw2.compare(sw2.size() + 1, 1, sw1.begin());
    ASSERT_TRUE(result.has_error());
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }

  {
    auto result = sw2.compare(0, sw2.size(), sw1.begin(), sw1.size());
    ASSERT_FALSE(result.has_error());
    EXPECT_EQ(0, result.value());
  }
  {
    auto result = sw2.compare(sw2.size() + 1, 1, sw1.begin(), sw1.size());
    ASSERT_TRUE(result.has_error());
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }
}
