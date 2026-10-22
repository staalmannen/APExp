// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="basic_string_view.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "../iterator_helper.h"
#include "basic_string_view_helper.h"
#include "portable_stl/array/array.h"
#include "portable_stl/ranges/empty.h"
#include "portable_stl/ranges/size.h"
#include "portable_stl/string/basic_string_view.h"
#include "portable_stl/string/string_view.h"

/**
 * @brief Char type alias.
 */
using t_char = char;

namespace test_string_helper {
constexpr static t_char const test_string[]    = "a😅b𝄞¥𑊰℉yzбࠀ𐀀ðя";
constexpr static size_t const test_string_size = sizeof(test_string) - 1UL;
// constexpr static size_t const test_string_size_in_bytes_with_eos    = sizeof(test_string);
// constexpr static size_t const test_string_size_in_bytes_without_eos = test_string_size;

constexpr static t_char const test_string_ascii[] = "abcd";
} // namespace test_string_helper

// [constructor]

TEST(basic_string_view, ctor) {
  static_cast<void>(test_info_);
  {
    // note: MSVC compilation error
    // EXPECT_TRUE(noexcept(::portable_stl::string_view()));

    constexpr ::portable_stl::string_view sv;
    static_assert(0 == sv.size(), "");
    static_assert(sv.empty(), "");
    static_cast<void>(sv);
  }
  {
    ::portable_stl::string_view const sv;
    EXPECT_EQ(0, sv.size());
    EXPECT_TRUE(sv.empty());
    static_cast<void>(sv);
  }
}

TEST(basic_string_view, from_nullptr) {
  static_cast<void>(test_info_);

  EXPECT_FALSE((std::is_convertible<decltype(nullptr), ::portable_stl::string_view>{}));
  EXPECT_FALSE((std::is_constructible<::portable_stl::string_view, decltype(nullptr)>{}));
  EXPECT_FALSE((std::is_assignable<::portable_stl::string_view, decltype(nullptr)>{}));
}

namespace test_string_helper {
/**
 * @brief Helper to get length of literal string
 * @tparam t_char_type
 * @param str
 * @return size_t
 */
template<typename t_char_type> size_t StrLen(t_char_type const *str) {
  std::size_t retVal{0};
  while (*str != 0) {
    ++retVal;
    ++str;
  }
  return retVal;
}
} // namespace test_string_helper

TEST(basic_string_view, ctor_from_literal) {
  static_cast<void>(test_info_);

  ::portable_stl::string_view sv(test_string_helper::test_string);

  EXPECT_EQ(test_string_helper::test_string_size, sv.size());
  EXPECT_EQ(test_string_helper::test_string, sv.data());
}

TEST(basic_string_view, ctor_utf8_from_string_literal) {
  static_cast<void>(test_info_);

  // basic_string_view<unsigned char> from string literal of signed char
  {
    ::portable_stl::u8string_view u8sv("regular_char_string_litergal");
    EXPECT_EQ(28U, u8sv.size());
  }
  {
    ::portable_stl::u8string_view u8sv = "regular_char_string_litergal";
    EXPECT_EQ(28U, u8sv.size());
  }
}

TEST(basic_string_view, ctor_ptr_and_len) {
  static_cast<void>(test_info_);

  EXPECT_TRUE(
    noexcept(::portable_stl::string_view(test_string_helper::test_string, test_string_helper::test_string_size)));

  ::portable_stl::string_view sv(test_string_helper::test_string, test_string_helper::test_string_size);
  EXPECT_EQ(test_string_helper::test_string_size, sv.size());
  EXPECT_EQ(test_string_helper::test_string, sv.data());
}

namespace test_string_helper {

/**
 * @brief Helper to test ctor from iterator and sentinel.
 *
 * @tparam t_iter
 * @tparam t_sent
 * @tparam t_char
 * @param val
 */
template<class t_iter, class t_sent> void test_construction(::portable_stl::string_view const &val) {
  auto sv = ::portable_stl::string_view(t_iter(val.data()), t_sent(t_iter(val.data() + val.size())));

  EXPECT_EQ(sv.data(), val.data());
  EXPECT_EQ(sv.size(), val.size());
}

static void test_with_char(::portable_stl::string_view val) {
  test_construction<t_char *, t_char *>(val);
  test_construction<t_char *, t_char const *>(val);
  test_construction<t_char const *, t_char *>(val);
  // test_construction<t_char const *, sized_sentinel<t_char const *>>(val);
  // test_construction<contiguous_iterator<t_char const *>, contiguous_iterator<t_char const *>>(val);
  // test_construction<contiguous_iterator<t_char const *>, sized_sentinel<contiguous_iterator<t_char const *>>>(val);
}
} // namespace test_string_helper

TEST(basic_string_view, ctor_ptr_and_sent) {
  static_cast<void>(test_info_);
  test_string_helper::test_with_char(::test_string_helper::test_string);

  {
    constexpr ::portable_stl::string_view const sv{
      &::test_string_helper::test_string[0],
      &::test_string_helper::test_string[::test_string_helper::test_string_size]};
    static_assert(::test_string_helper::test_string_size == sv.size(), "");
  }
  {
    EXPECT_TRUE((std::is_constructible<::portable_stl::string_view, t_char const *, t_char *>{}));
    EXPECT_TRUE((std::is_constructible<::portable_stl::string_view, t_char *, t_char const *>{}));
    // not a sentinel
    EXPECT_FALSE((std::is_constructible<::portable_stl::string_view, t_char *, void *>{}));
    // wrong char type
    EXPECT_FALSE((std::is_constructible<::portable_stl::string_view, signed char *, signed char *>{}));
    // not contiguous
    EXPECT_FALSE((std::is_constructible<::portable_stl::string_view,
                                        test_iterator_helper::tst_random_access_iterator<t_char *>,
                                        test_iterator_helper::tst_random_access_iterator<t_char *>>{}));
  }
}

// TEST(basic_string_view, implicit_deduction_guide) {
//   static_cast<void>(test_info_);

//   {
//     ::portable_stl::string_view const sin("abc");
//     ::portable_stl::basic_string_view s(sin);

//     EXPECT_TRUE((std::is_same<decltype(s), ::portable_stl::string_view>{}));
//     EXPECT_EQ("abc", s);
//   }
//   {
//     using wchar_string_view = ::portable_stl::basic_string_view<wchar_t>;
//      wchar_string_view const sin{L"abc"};
//     ::portable_stl::basic_string_view s(sin);

//     EXPECT_TRUE((std::is_same<decltype(s), wchar_string_view>{}));
//     EXPECT_EQ(L"abc", s);
//   }
//   {
//     using wchar_string_view = ::portable_stl::basic_string_view<wchar_t>;
//      wchar_string_view const sin{L"abc"};
//     ::portable_stl::basic_string_view s(sin);

//     EXPECT_TRUE((std::is_same<decltype(s), wchar_string_view>{}));
//     EXPECT_EQ(L"abc", s);
//   }
// }

TEST(basic_string_view, assign) {
  static_cast<void>(test_info_);

  ::portable_stl::string_view sv0{::test_string_helper::test_string};
  ::portable_stl::string_view sv;
  sv = sv0;
  EXPECT_EQ(sv, sv0);
  static_cast<void>(sv);
}

// [access]

namespace test_string_helper {
/**
 * @brief Check index operator
 *
 * @param str
 * @param len
 */
static void string_view_index(t_char const *str, ::portable_stl::size_t len) {
  ::portable_stl::string_view sv(str, len);
  EXPECT_TRUE((std::is_same<decltype(sv[0]), typename ::portable_stl::string_view::const_reference>{}));
  EXPECT_TRUE(noexcept(sv[0]));
  EXPECT_EQ(len, sv.length());

  for (::portable_stl::size_t i{0}; i < len; ++i) {
    EXPECT_EQ(str[i], sv[i]);
    EXPECT_EQ(&str[i], &sv[i]);
  }
}
} // namespace test_string_helper

TEST(basic_string_view, index) {
  static_cast<void>(test_info_);

  test_string_helper::string_view_index("", 0);
  test_string_helper::string_view_index("a", 1);
  test_string_helper::string_view_index(test_string_helper::test_string, test_string_helper::test_string_size);

  // constexpr
  {
    constexpr ::portable_stl::string_view sv(test_string_helper::test_string, test_string_helper::test_string_size);
    static_assert(sv.length() == test_string_helper::test_string_size, "");
    static_assert(sv[0] == test_string_helper::test_string[0], "");
    static_assert(sv[1] == test_string_helper::test_string[1], "");
    static_assert(sv[test_string_helper::test_string_size - 1]
                    == test_string_helper::test_string[test_string_helper::test_string_size - 1],
                  "");
    static_assert(sv[test_string_helper::test_string_size - 2]
                    == test_string_helper::test_string[test_string_helper::test_string_size - 2],
                  "");
  }
}

namespace test_string_helper {
/**
 * @brief Check at
 * @param str
 * @param len
 */
static void string_view_at(t_char const *str, ::portable_stl::size_t len) {
  ::portable_stl::string_view sv(str, len);
  EXPECT_EQ(len, sv.length());

  for (::portable_stl::size_t i{0}; i < len; ++i) {
    auto result = sv.at(i);
    ASSERT_FALSE(result.has_error());

    EXPECT_EQ(str[i], result.value().get());
    EXPECT_EQ(&str[i], &result.value().get());
  }
  // out of range
  {
    auto result_out = sv.at(len);
    ASSERT_TRUE(result_out.has_error());
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result_out.error());
  }
}
} // namespace test_string_helper

TEST(basic_string_view, at) {
  static_cast<void>(test_info_);

  test_string_helper::string_view_at(test_string_helper::test_string, test_string_helper::test_string_size);
}

namespace test_string_helper {
/**
 * @brief Check data
 * @tparam t_char_type
 * @param str
 * @param len
 */
template<class t_char_type> void string_view_data(t_char_type const *str, ::portable_stl::size_t len) {
  ::portable_stl::basic_string_view<t_char_type> sv{str, len};
  EXPECT_EQ(len, sv.length());
  EXPECT_EQ(str, sv.data());
}
} // namespace test_string_helper

TEST(basic_string_view, front) {
  static_cast<void>(test_info_);

  constexpr ::portable_stl::string_view sv(test_string_helper::test_string, test_string_helper::test_string_size);
  EXPECT_TRUE((std::is_same<decltype(sv.front()), typename ::portable_stl::string_view::const_reference>{}));
  EXPECT_TRUE(noexcept(sv.front()));
  EXPECT_EQ(test_string_helper::test_string_size, sv.length());
  EXPECT_EQ(test_string_helper::test_string[0], sv.front());
  EXPECT_EQ(&test_string_helper::test_string[0], &sv.front());
}

TEST(basic_string_view, back) {
  static_cast<void>(test_info_);

  constexpr ::portable_stl::string_view sv(test_string_helper::test_string, test_string_helper::test_string_size);
  EXPECT_TRUE((std::is_same<decltype(sv.back()), typename ::portable_stl::string_view::const_reference>{}));
  EXPECT_TRUE(noexcept(sv.back()));
  EXPECT_EQ(test_string_helper::test_string_size, sv.length());
  EXPECT_EQ(test_string_helper::test_string[test_string_helper::test_string_size - 1], sv.back());
  EXPECT_EQ(&test_string_helper::test_string[test_string_helper::test_string_size - 1], &sv.back());
}

TEST(basic_string_view, data) {
  static_cast<void>(test_info_);

  constexpr ::portable_stl::string_view sv(test_string_helper::test_string, test_string_helper::test_string_size);
  EXPECT_EQ(test_string_helper::test_string_size, sv.length());
  EXPECT_EQ(test_string_helper::test_string, sv.data());
}

// [capacity]

namespace test_string_helper {
/**
 * @brief Helper to test capacity
 *
 * @param str
 * @param len
 */
static void string_view_capacity(t_char const *str, ::portable_stl::size_t len) {
  ::portable_stl::string_view sv{str};

  EXPECT_EQ(len, sv.size());
  EXPECT_EQ(str, sv.data());
  EXPECT_EQ((len == 0), sv.empty());
  EXPECT_EQ(sv.length(), sv.size());
  EXPECT_GT(sv.max_size(), sv.size());

  EXPECT_EQ(::portable_stl::ranges::size(sv), sv.size());
  EXPECT_EQ(::portable_stl::ranges::empty(sv), sv.empty());
}
} // namespace test_string_helper

TEST(basic_string_view, capacity) {
  static_cast<void>(test_info_);

  // empty
  {
    constexpr ::portable_stl::string_view sv;
    static_assert(sv.size() == 0, "");
    static_assert(sv.empty(), "");
    static_assert(sv.size() == sv.length(), "");
    static_assert(sv.max_size() > sv.size(), "");

    // noexcept
    EXPECT_TRUE(noexcept(sv.size()));
    EXPECT_TRUE(noexcept(sv.empty()));
    EXPECT_TRUE(noexcept(sv.max_size()));
    EXPECT_TRUE(noexcept(sv.length()));
  }

  test_string_helper::string_view_capacity("", 0);
  test_string_helper::string_view_capacity("a", 1);
  test_string_helper::string_view_capacity(test_string_helper::test_string, test_string_helper::test_string_size);
  test_string_helper::string_view_capacity("abcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcda"
                                           "bcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcd",
                                           140);
}

// [iterators]

TEST(basic_string_view, concept_conformance) {
  static_cast<void>(test_info_);

  /**
   * @brief Test type.
   */
  using t_iterator               = ::portable_stl::string_view::iterator;
  /**
   * @brief Test type.
   */
  using t_const_iterator         = ::portable_stl::string_view::const_iterator;
  /**
   * @brief Test type.
   */
  using t_reverse_iterator       = ::portable_stl::string_view::reverse_iterator;
  /**
   * @brief Test type.
   */
  using t_const_reverse_iterator = ::portable_stl::string_view::const_reverse_iterator;

  EXPECT_TRUE((::portable_stl::contiguous_iterator<t_iterator>{}()));

  EXPECT_FALSE((::portable_stl::indirectly_writable<t_iterator, t_char>{}()));
  EXPECT_TRUE((::portable_stl::sentinel_for<t_iterator, t_iterator>{}()));
  EXPECT_TRUE((::portable_stl::sentinel_for<t_iterator, t_const_iterator>{}()));
  EXPECT_FALSE((::portable_stl::sentinel_for<t_iterator, t_reverse_iterator>{}()));
  EXPECT_FALSE((::portable_stl::sentinel_for<t_iterator, t_const_reverse_iterator>{}()));
  EXPECT_TRUE((::portable_stl::sized_sentinel_for<t_iterator, t_iterator>{}()));
  EXPECT_TRUE((::portable_stl::sized_sentinel_for<t_iterator, t_const_iterator>{}()));
  EXPECT_FALSE((::portable_stl::sized_sentinel_for<t_iterator, t_reverse_iterator>{}()));
  EXPECT_FALSE((::portable_stl::sized_sentinel_for<t_iterator, t_const_reverse_iterator>{}()));
  EXPECT_TRUE((::portable_stl::indirectly_movable<t_iterator, t_char *>{}()));
  EXPECT_TRUE((::portable_stl::indirectly_movable_storable<t_iterator, t_char *>{}()));
  EXPECT_FALSE((::portable_stl::indirectly_swappable<t_iterator, t_iterator>{}()));

  EXPECT_TRUE((::portable_stl::contiguous_iterator<t_const_iterator>{}()));
  EXPECT_FALSE((::portable_stl::indirectly_writable<t_const_iterator, t_char>{}()));
  EXPECT_TRUE((::portable_stl::sentinel_for<t_const_iterator, t_iterator>{}()));
  EXPECT_TRUE((::portable_stl::sentinel_for<t_const_iterator, t_const_iterator>{}()));
  EXPECT_FALSE((::portable_stl::sentinel_for<t_const_iterator, t_reverse_iterator>{}()));
  EXPECT_FALSE((::portable_stl::sentinel_for<t_const_iterator, t_const_reverse_iterator>{}()));
  EXPECT_TRUE((::portable_stl::sized_sentinel_for<t_const_iterator, t_iterator>{}()));
  EXPECT_TRUE((::portable_stl::sized_sentinel_for<t_const_iterator, t_const_iterator>{}()));
  EXPECT_FALSE((::portable_stl::sized_sentinel_for<t_const_iterator, t_reverse_iterator>{}()));
  EXPECT_FALSE((::portable_stl::sized_sentinel_for<t_const_iterator, t_const_reverse_iterator>{}()));
  EXPECT_FALSE((::portable_stl::indirectly_swappable<t_const_iterator, t_const_iterator>{}()));
}

namespace test_string_helper {
/**
 * @brief Check begin().
 * @tparam t_type
 */
template<class t_string_view> void string_view_begin(t_string_view sv) {
  t_string_view const                   &csv{sv};
  typename t_string_view::iterator       bgn{sv.begin()};
  typename t_string_view::const_iterator cbgn1{csv.begin()};
  typename t_string_view::const_iterator cbgn2{sv.cbegin()};

  if (!sv.empty()) {
    EXPECT_EQ(*bgn, sv[0]);
    EXPECT_EQ(&*bgn, &sv[0]);
    EXPECT_EQ(*cbgn1, sv[0]);
    EXPECT_EQ(&*cbgn1, &sv[0]);
    EXPECT_EQ(*cbgn2, sv[0]);
    EXPECT_EQ(&*cbgn2, &sv[0]);
  }
  EXPECT_EQ(bgn, cbgn1);
  EXPECT_EQ(bgn, cbgn2);
  EXPECT_EQ(cbgn1, cbgn2);
}

/**
 * @brief Check rbegin().
 * @tparam t_type
 */
template<class t_string_view> void string_view_rbegin(t_string_view sv) {
  t_string_view const                           &csv{sv};
  typename t_string_view::reverse_iterator       bgn{sv.rbegin()};
  typename t_string_view::const_reverse_iterator cbgn1{csv.rbegin()};
  typename t_string_view::const_reverse_iterator cbgn2{sv.crbegin()};

  if (!sv.empty()) {
    ::portable_stl::size_t const last{sv.size() - 1};
    EXPECT_EQ(*bgn, sv[last]);
    EXPECT_EQ(&*bgn, &sv[last]);
    EXPECT_EQ(*cbgn1, sv[last]);
    EXPECT_EQ(&*cbgn1, &sv[last]);
    EXPECT_EQ(*cbgn2, sv[last]);
    EXPECT_EQ(&*cbgn2, &sv[last]);
  }
  EXPECT_EQ(bgn, cbgn1);
  EXPECT_EQ(bgn, cbgn2);
  EXPECT_EQ(cbgn1, cbgn2);
}

/**
 * @brief Check end().
 * @tparam t_type
 */
template<class t_string_view> void string_view_end(t_string_view sv) {
  t_string_view const                   &csv{sv};
  typename t_string_view::iterator       ed{sv.end()};
  typename t_string_view::const_iterator ced1{csv.end()};
  typename t_string_view::const_iterator ced2{sv.cend()};

  if (sv.empty()) {
    EXPECT_EQ(ed, sv.begin());
    EXPECT_EQ(ced1, csv.begin());
    EXPECT_EQ(ced2, sv.begin());
  } else {
    EXPECT_NE(ed, sv.begin());
    EXPECT_NE(ced1, csv.begin());
    EXPECT_NE(ced2, sv.begin());
  }

  EXPECT_EQ(sv.size(), static_cast<::portable_stl::size_t>(ed - sv.begin()));
  EXPECT_EQ(csv.size(), static_cast<::portable_stl::size_t>(ced1 - csv.begin()));
  EXPECT_EQ(sv.size(), static_cast<::portable_stl::size_t>(ced2 - sv.begin()));

  EXPECT_EQ(ed, ced1);
  EXPECT_EQ(ed, ced2);
  EXPECT_EQ(ced1, ced2);
}

/**
 * @brief Check rend().
 * @tparam t_type
 */
template<class t_string_view> void string_view_rend(t_string_view sv) {
  t_string_view const                           &csv{sv};
  typename t_string_view::reverse_iterator       ed{sv.rend()};
  typename t_string_view::const_reverse_iterator ced1{csv.rend()};
  typename t_string_view::const_reverse_iterator ced2{sv.crend()};

  if (sv.empty()) {
    EXPECT_EQ(ed, sv.rbegin());
    EXPECT_EQ(ced1, csv.rbegin());
    EXPECT_EQ(ced2, sv.rbegin());
  } else {
    EXPECT_NE(ed, sv.rbegin());
    EXPECT_NE(ced1, csv.rbegin());
    EXPECT_NE(ced2, sv.rbegin());
  }

  EXPECT_EQ(sv.size(), static_cast<::portable_stl::size_t>(ed - sv.rbegin()));
  EXPECT_EQ(csv.size(), static_cast<::portable_stl::size_t>(ced1 - csv.rbegin()));
  EXPECT_EQ(sv.size(), static_cast<::portable_stl::size_t>(ced2 - sv.rbegin()));

  EXPECT_EQ(ed, ced1);
  EXPECT_EQ(ed, ced2);
  EXPECT_EQ(ced1, ced2);
}

} // namespace test_string_helper

TEST(basic_string_view, begin) {
  static_cast<void>(test_info_);

  test_string_helper::string_view_begin(portable_stl::string_view(""));
  test_string_helper::string_view_begin(portable_stl::string_view(test_string_helper::test_string));

  // constexpr
  {
    constexpr portable_stl::string_view sv{test_string_helper::test_string, test_string_helper::test_string_size};
    static_assert(*sv.begin() == test_string_helper::test_string[0], "");
    static_assert(*sv.cbegin() == test_string_helper::test_string[0], "");
  }
}

TEST(basic_string_view, rbegin) {
  static_cast<void>(test_info_);

  test_string_helper::string_view_rbegin(portable_stl::string_view(""));
  test_string_helper::string_view_rbegin(portable_stl::string_view(test_string_helper::test_string));
}

TEST(basic_string_view, end) {
  static_cast<void>(test_info_);

  test_string_helper::string_view_end(portable_stl::string_view(""));
  test_string_helper::string_view_end(portable_stl::string_view(test_string_helper::test_string));

  // constexpr
  {
    constexpr portable_stl::string_view sv{test_string_helper::test_string, test_string_helper::test_string_size};
    static_assert(sv.begin() != sv.end(), "");
    static_assert(sv.cbegin() != sv.cend(), "");
  }
}

TEST(basic_string_view, rend) {
  static_cast<void>(test_info_);

  test_string_helper::string_view_rend(portable_stl::string_view(""));
  test_string_helper::string_view_rend(portable_stl::string_view(test_string_helper::test_string));
}

TEST(basic_string_view, iterators_remove_prefix) {
  test_basic_string_view_helper::check_remove_prefix<portable_stl::string_view>(test_string_helper::test_string,
                                                                                test_string_helper::test_string_size);
  test_basic_string_view_helper::check_remove_prefix<portable_stl::string_view>("a", 1);
  test_basic_string_view_helper::check_remove_prefix<portable_stl::string_view>("", 0);
}

TEST(basic_string_view, iterators_remove_suffix) {
  test_basic_string_view_helper::check_remove_suffix<portable_stl::string_view>(test_string_helper::test_string,
                                                                                test_string_helper::test_string_size);
  test_basic_string_view_helper::check_remove_suffix<portable_stl::string_view>("a", 1);
  test_basic_string_view_helper::check_remove_suffix<portable_stl::string_view>("", 0);
}

TEST(basic_string_view, iterators_swap) {
  test_basic_string_view_helper::check_swap<portable_stl::string_view>(test_string_helper::test_string,
                                                                       test_string_helper::test_string_size);
  test_basic_string_view_helper::check_swap<portable_stl::string_view>("a", 1);
  test_basic_string_view_helper::check_swap<portable_stl::string_view>("", 0);
}

namespace test_string_helper {
static void test_copy(::portable_stl::string_view const              &sv,
                      typename ::portable_stl::string_view::size_type num_to_copy,
                      typename ::portable_stl::string_view::size_type start_pos,
                      typename ::portable_stl::string_view::size_type num_expected,
                      bool                                            error_expected = false) {
  ::portable_stl::array<::portable_stl::string_view::value_type, 100> buff{0};
  memset(buff.begin(), static_cast<::portable_stl::string_view::value_type>(-1), 100);

  auto result = sv.copy(buff.begin(), num_to_copy, start_pos);
  ASSERT_EQ(error_expected, result.has_error());
  if (!result.has_error()) {
    ASSERT_EQ(num_expected, result.value());
    for (::portable_stl::size_t i{0}; i < result.value(); ++i) {
      ASSERT_EQ(sv[start_pos + i], buff[i]);
    }
    ASSERT_EQ(static_cast<::portable_stl::string_view::value_type>(-1), buff.at(num_expected));
  }

  // std::string_view sv_std{sv.data()};
  // auto             result = sv_std.copy(buff.begin(), num_to_copy, start_pos);
  // ASSERT_EQ(num_expected, result);
  // for (::portable_stl::size_t i{0}; i < result; ++i) {
  //   ASSERT_EQ(sv[start_pos + i], buff[i]);
  // }
  // ASSERT_EQ(static_cast<::portable_stl::string_view::value_type>(-1), buff.at(num_expected));
}

static void test_substr_safe(::portable_stl::string_view const              &sv,
                             typename ::portable_stl::string_view::size_type start_pos,
                             typename ::portable_stl::string_view::size_type num_to_copy,
                             ::portable_stl::string_view const              &sv_expected,
                             bool                                            error_expected = false) {
  auto result = sv.substr_safe(start_pos, num_to_copy);
  ASSERT_EQ(error_expected, result.has_error());
  if (!result.has_error()) {
    ASSERT_EQ(sv_expected, result.value());
  }
}
} // namespace test_string_helper

TEST(basic_string_view, copy) {
  static_cast<void>(test_info_);

  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 1, 4, 0); // num start expected
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 2, 3, 1);
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 3, 2, 2);
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 4, 1, 3);
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 5, 0, 4);

  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 2, 4, 0);
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 3, 3, 1);
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 4, 2, 2);
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 5, 1, 3);
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 6, 0, 4);

  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 1, 0, 1);
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 2, 0, 2);
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 3, 0, 3);
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 4, 0, 4);
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 5, 0, 4);

  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 1, 1, 1);
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 2, 1, 2);
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 3, 1, 3);
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 4, 1, 3);
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 5, 1, 3);

  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 0, 0, 0);
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 0, 1, 0);
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 0, 3, 0);
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 0, 4, 0);        // !(4 > sv.size)
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 0, 50, 0, true); // 50 > sv.size

  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 1, 0, 1);
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 1, 1, 1);
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 1, 3, 1);
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 1, 4, 0);        // !(4 > sv.size)
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 1, 50, 0, true); // 50 > sv.size

  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 1, ::portable_stl::string_view::npos, 0, true);
  test_string_helper::test_copy(::portable_stl::string_view("abcd"), 0, ::portable_stl::string_view::npos, 0, true);
}

TEST(basic_string_view, substr_safe) {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias;
   */
  using t_sv = ::portable_stl::string_view;

  test_string_helper::test_substr_safe(t_sv("abcd"), 0, 0, t_sv("")); // start_pos num
  test_string_helper::test_substr_safe(t_sv("abcd"), 1, 0, t_sv(""));
  test_string_helper::test_substr_safe(t_sv("abcd"), 2, 0, t_sv(""));
  test_string_helper::test_substr_safe(t_sv("abcd"), 3, 0, t_sv(""));
  test_string_helper::test_substr_safe(t_sv("abcd"), 4, 0, t_sv(""));
  test_string_helper::test_substr_safe(t_sv("abcd"), 5, 0, t_sv(""), true); // 5 > sv.size

  test_string_helper::test_substr_safe(t_sv("abcd"), 0, 1, t_sv("a"));
  test_string_helper::test_substr_safe(t_sv("abcd"), 1, 1, t_sv("b"));
  test_string_helper::test_substr_safe(t_sv("abcd"), 2, 1, t_sv("c"));
  test_string_helper::test_substr_safe(t_sv("abcd"), 3, 1, t_sv("d"));
  test_string_helper::test_substr_safe(t_sv("abcd"), 4, 1, t_sv(""));

  test_string_helper::test_substr_safe(t_sv("abcd"), 0, 2, t_sv("ab"));
  test_string_helper::test_substr_safe(t_sv("abcd"), 1, 2, t_sv("bc"));
  test_string_helper::test_substr_safe(t_sv("abcd"), 2, 2, t_sv("cd"));
  test_string_helper::test_substr_safe(t_sv("abcd"), 3, 2, t_sv("d"));
  test_string_helper::test_substr_safe(t_sv("abcd"), 4, 2, t_sv(""));

  test_string_helper::test_substr_safe(t_sv("abcd"), 0, 3, t_sv("abc"));
  test_string_helper::test_substr_safe(t_sv("abcd"), 1, 3, t_sv("bcd"));
  test_string_helper::test_substr_safe(t_sv("abcd"), 2, 3, t_sv("cd"));
  test_string_helper::test_substr_safe(t_sv("abcd"), 3, 3, t_sv("d"));
  test_string_helper::test_substr_safe(t_sv("abcd"), 4, 3, t_sv(""));

  test_string_helper::test_substr_safe(t_sv("abcd"), 0, 4, t_sv("abcd"));
  test_string_helper::test_substr_safe(t_sv("abcd"), 1, 4, t_sv("bcd"));
  test_string_helper::test_substr_safe(t_sv("abcd"), 2, 4, t_sv("cd"));
  test_string_helper::test_substr_safe(t_sv("abcd"), 3, 4, t_sv("d"));
  test_string_helper::test_substr_safe(t_sv("abcd"), 4, 4, t_sv(""));

  test_string_helper::test_substr_safe(t_sv("abcd"), 0, 5, t_sv("abcd"));
  test_string_helper::test_substr_safe(t_sv("abcd"), 1, 5, t_sv("bcd"));
  test_string_helper::test_substr_safe(t_sv("abcd"), 2, 5, t_sv("cd"));
  test_string_helper::test_substr_safe(t_sv("abcd"), 3, 5, t_sv("d"));
  test_string_helper::test_substr_safe(t_sv("abcd"), 4, 5, t_sv(""));

  test_string_helper::test_substr_safe(t_sv("abcd"), ::portable_stl::string_view::npos, 0, t_sv(""), true);
  test_string_helper::test_substr_safe(t_sv("abcd"), ::portable_stl::string_view::npos, 1, t_sv(""), true);
  test_string_helper::test_substr_safe(t_sv("abcd"), 0, ::portable_stl::string_view::npos, t_sv("abcd"));
  test_string_helper::test_substr_safe(t_sv("abcd"), 1, ::portable_stl::string_view::npos, t_sv("bcd"));
}

// [string.view.ops]

TEST(basic_string_view, starts_with_chr) {
  static_cast<void>(test_info_);

  {
    constexpr ::portable_stl::string_view sv{test_string_helper::test_string, test_string_helper::test_string_size};
    constexpr ::portable_stl::string_view sv_empty{};
    static_assert(sv.starts_with(test_string_helper::test_string[0]), "");
    static_assert(!sv.starts_with('g'), "");

    static_assert(!sv_empty.starts_with(test_string_helper::test_string[0]), "");
    static_assert(!sv_empty.starts_with(static_cast<typename ::portable_stl::string_view::value_type>(0)), "");
  }
}

TEST(basic_string_view, starts_with_view) {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias;
   */
  using t_sv = ::portable_stl::string_view;

  {
    ::portable_stl::string_view sv{"abcd", 4};

    EXPECT_TRUE(sv.starts_with(t_sv("")));
    EXPECT_TRUE(sv.starts_with(t_sv("a")));
    EXPECT_TRUE(sv.starts_with(t_sv("ab")));
    EXPECT_TRUE(sv.starts_with(t_sv("abc")));
    EXPECT_TRUE(sv.starts_with(t_sv("abcd")));
    EXPECT_FALSE(sv.starts_with(t_sv("abcde")));
  }
  {
    ::portable_stl::string_view sv_empty{};

    EXPECT_TRUE(sv_empty.starts_with(t_sv("")));
    EXPECT_FALSE(sv_empty.starts_with(t_sv("a")));
  }
}

TEST(basic_string_view, starts_with_pointer) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::string_view sv{"abcd", 4};

    EXPECT_TRUE(sv.starts_with(""));
    EXPECT_TRUE(sv.starts_with("a"));
    EXPECT_TRUE(sv.starts_with("ab"));
    EXPECT_TRUE(sv.starts_with("abc"));
    EXPECT_TRUE(sv.starts_with("abcd"));
    EXPECT_FALSE(sv.starts_with("abcde"));
  }
  {
    ::portable_stl::string_view sv_empty{};

    EXPECT_TRUE(sv_empty.starts_with(""));
    EXPECT_FALSE(sv_empty.starts_with("a"));
  }
}

TEST(basic_string_view, ends_with_chr) {
  static_cast<void>(test_info_);

  {
    constexpr ::portable_stl::string_view sv{test_string_helper::test_string_ascii, 4};
    constexpr ::portable_stl::string_view sv_empty{};
    static_assert(sv.ends_with(test_string_helper::test_string_ascii[3]), "");
    static_assert(!sv.ends_with(' '), "");
    static_assert(!sv.ends_with(static_cast<typename ::portable_stl::string_view::value_type>(0)), "");

    static_assert(!sv_empty.ends_with(test_string_helper::test_string_ascii[0]), "");
    static_assert(!sv_empty.ends_with(static_cast<typename ::portable_stl::string_view::value_type>(0)), "");
  }
}

TEST(basic_string_view, ends_with_view) {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias;
   */
  using t_sv = ::portable_stl::string_view;

  {
    ::portable_stl::string_view sv{"abcd", 4};

    EXPECT_TRUE(sv.ends_with(t_sv("")));
    EXPECT_TRUE(sv.ends_with(t_sv("d")));
    EXPECT_TRUE(sv.ends_with(t_sv("cd")));
    EXPECT_TRUE(sv.ends_with(t_sv("bcd")));
    EXPECT_TRUE(sv.ends_with(t_sv("abcd")));
    EXPECT_FALSE(sv.ends_with(t_sv("_abcd")));
  }
  {
    ::portable_stl::string_view sv_empty{};

    EXPECT_TRUE(sv_empty.ends_with(t_sv("")));
    EXPECT_FALSE(sv_empty.ends_with(t_sv("a")));
  }
}

TEST(basic_string_view, ends_with_pointer) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::string_view sv{"abcd", 4};

    EXPECT_TRUE(sv.ends_with(""));
    EXPECT_TRUE(sv.ends_with("d"));
    EXPECT_TRUE(sv.ends_with("cd"));
    EXPECT_TRUE(sv.ends_with("bcd"));
    EXPECT_TRUE(sv.ends_with("abcd"));
    EXPECT_FALSE(sv.ends_with("_abcd"));
  }
  {
    ::portable_stl::string_view sv_empty{};

    EXPECT_TRUE(sv_empty.ends_with(""));
    EXPECT_FALSE(sv_empty.ends_with("a"));
  }
}

TEST(basic_string_view, contains_chr) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::string_view sv{"abcd", 4};

    EXPECT_FALSE(sv.contains(static_cast<typename ::portable_stl::string_view::value_type>(0)));
    EXPECT_TRUE(sv.contains(sv.data()[0]));
    EXPECT_TRUE(sv.contains('d'));
    EXPECT_FALSE(sv.contains('z'));
  }
  {
    ::portable_stl::string_view sv_empty{};

    EXPECT_FALSE(sv_empty.contains('a'));
    EXPECT_FALSE(sv_empty.contains(static_cast<typename ::portable_stl::string_view::value_type>(0)));
  }
}

TEST(basic_string_view, contains_view) {
  static_cast<void>(test_info_);

  /**
   * @brief ::portable_stl::string_view alias;
   */
  using t_sv = ::portable_stl::string_view;

  {
    ::portable_stl::string_view sv{"abcd", 4};

    EXPECT_TRUE(sv.contains(t_sv("")));
    EXPECT_TRUE(sv.contains(t_sv("d")));
    EXPECT_TRUE(sv.contains(t_sv("cd")));
    EXPECT_TRUE(sv.contains(t_sv("bcd")));
    EXPECT_TRUE(sv.contains(t_sv("abcd")));
    EXPECT_TRUE(sv.contains(t_sv("b")));
    EXPECT_TRUE(sv.contains(t_sv("bc")));
    EXPECT_TRUE(sv.contains(t_sv("d")));
    EXPECT_FALSE(sv.contains(t_sv("abdc")));
  }
  {
    ::portable_stl::string_view sv_empty{};

    EXPECT_TRUE(sv_empty.contains(t_sv("")));
    EXPECT_FALSE(sv_empty.contains(t_sv("a")));
  }
}

TEST(basic_string_view, contains_pointer) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::string_view sv{"abcd", 4};

    EXPECT_TRUE(sv.contains(""));
    EXPECT_TRUE(sv.contains("d"));
    EXPECT_TRUE(sv.contains("cd"));
    EXPECT_TRUE(sv.contains("bcd"));
    EXPECT_TRUE(sv.contains("abcd"));
    EXPECT_TRUE(sv.contains("b"));
    EXPECT_TRUE(sv.contains("bc"));
    EXPECT_TRUE(sv.contains("d"));
    EXPECT_FALSE(sv.contains("abdc"));
  }
  {
    ::portable_stl::string_view sv_empty{};

    EXPECT_TRUE(sv_empty.contains(""));
    EXPECT_FALSE(sv_empty.contains("a"));
  }
}
