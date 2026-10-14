// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="ranges_concepts.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "iterator_helper.h"
#include "portable_stl/iterator/concepts/input_or_output_iterator.h"
#include "portable_stl/metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "portable_stl/ranges/concepts/bidirectional_range.h"
#include "portable_stl/ranges/concepts/common_range.h"
#include "portable_stl/ranges/concepts/contiguous_range.h"
#include "portable_stl/ranges/concepts/forward_range.h"
#include "portable_stl/ranges/concepts/input_range.h"
#include "portable_stl/ranges/concepts/random_access_range.h"
#include "portable_stl/ranges/concepts/range.h"
#include "ranges_helper.h"

namespace ranges_concepts_tests_helper {

/**
 * @brief Unsuitable type of iterator to use in range.
 */
class incompatible_iterators final {
public:
  /**
   * @brief
   * @return std::int32_t*
   */
  std::int32_t *begin();
  /**
   * @brief
   * @return std::int64_t*
   */
  std::int64_t *end();
};

/**
 * @brief Unsuitable type of iterator to use in range.
 */
class int_begin_int_end final {
public:
  /**
   * @brief
   * @return std::int32_t
   */
  std::int32_t begin();
  /**
   * @brief
   * @return std::int32_t
   */
  std::int32_t end();
};

/**
 * @brief Unsuitable type of iterator to use in range.
 */
class iterator_begin_int_end final {
public:
  /**
   * @brief
   * @return std::int32_t*
   */
  std::int32_t *begin();
  /**
   * @brief
   * @return std::int32_t
   */
  std::int32_t  end();
};

/**
 * @brief Unsuitable type of iterator to use in range.
 */
class int_begin_iterator_end final {
public:
  /**
   * @brief
   * @return std::int32_t
   */
  std::int32_t  begin();
  /**
   * @brief
   * @return std::int32_t*
   */
  std::int32_t *end();
};

/**
 * @brief Test range type.
 * @tparam iter_t
 * @tparam type_t
 */
template<template<class...> class iter_t,
         class type_t = std::int32_t,
         class = ::portable_stl::enable_if_bool_constant_t<::portable_stl::input_or_output_iterator<iter_t<type_t *>>>>
class test_range final {
public:
  /**
   * @brief
   * @return iter_t<type_t *>
   */
  iter_t<type_t *> begin() {
    return {};
  }
  /**
   * @brief
   * @return iter_t<type_t const *>
   */
  iter_t<type_t const *> begin() const;
  /**
   * @brief
   * @return iter_t<type_t *>
   */
  iter_t<type_t *>       end() {
    return {};
  }
  /**
   * @brief
   * @return iter_t<type_t const *>
   */
  iter_t<type_t const *> end() const;
};
} // namespace ranges_concepts_tests_helper

TEST(ranges_concepts, range) {
  static_cast<void>(test_info_);
  EXPECT_FALSE((::portable_stl::ranges::range<ranges_concepts_tests_helper::incompatible_iterators>{}()));
  EXPECT_FALSE((::portable_stl::ranges::range<ranges_concepts_tests_helper::int_begin_int_end>{}()));
  EXPECT_FALSE((::portable_stl::ranges::range<ranges_concepts_tests_helper::iterator_begin_int_end>{}()));
  EXPECT_FALSE((::portable_stl::ranges::range<ranges_concepts_tests_helper::int_begin_iterator_end>{}()));

  /**
   * @brief Test range with tst_input_iterator iterator
   */
  using test_range_type = ranges_concepts_tests_helper::test_range<test_iterator_helper::tst_input_iterator>;
  EXPECT_TRUE((::portable_stl::ranges::range<test_range_type>{}()));

  EXPECT_TRUE((::portable_stl::ranges::range<std::int32_t(&)[1]>{}()));
  EXPECT_TRUE((::portable_stl::ranges::range<std::int32_t const(&)[1]>{}()));
  EXPECT_TRUE((::portable_stl::ranges::range<std::int32_t[1]>{}()));
}

TEST(ranges_concepts, input_range) {
  static_cast<void>(test_info_);

  /**
   * @brief Test range with tst_input_iterator iterator
   */
  using test_range_type = ranges_concepts_tests_helper::test_range<test_iterator_helper::tst_input_iterator>;
  EXPECT_TRUE((::portable_stl::ranges::input_range<test_range_type>{}()));

  EXPECT_TRUE((::portable_stl::ranges::input_range<std::int32_t(&)[1]>{}()));
  EXPECT_TRUE((::portable_stl::ranges::input_range<std::int32_t const(&)[1]>{}()));
  EXPECT_TRUE((::portable_stl::ranges::input_range<std::int32_t[1]>{}()));
}

TEST(ranges_concepts, forward_range) {
  static_cast<void>(test_info_);

  /**
   * @brief Test range with tst_input_iterator iterator
   */
  using test_input_range_type = ranges_concepts_tests_helper::test_range<test_iterator_helper::tst_input_iterator>;
  EXPECT_FALSE((::portable_stl::ranges::forward_range<test_input_range_type>{}()));

  /**
   * @brief Test range with tst_bidirectional_iterator iterator
   */
  using test_bidirectional_range_type
    = ranges_concepts_tests_helper::test_range<test_iterator_helper::tst_bidirectional_iterator>;
  EXPECT_TRUE((::portable_stl::ranges::forward_range<test_bidirectional_range_type>{}()));

  EXPECT_TRUE((::portable_stl::ranges::forward_range<std::int32_t(&)[1]>{}()));
  EXPECT_TRUE((::portable_stl::ranges::forward_range<std::int32_t const(&)[1]>{}()));
  EXPECT_TRUE((::portable_stl::ranges::forward_range<std::int32_t[1]>{}()));
}

TEST(ranges_concepts, bidirectional_range) {
  static_cast<void>(test_info_);

  /**
   * @brief Test range with tst_input_iterator iterator
   */
  using test_input_range_type = ranges_concepts_tests_helper::test_range<test_iterator_helper::tst_input_iterator>;
  EXPECT_FALSE((::portable_stl::ranges::bidirectional_range<test_input_range_type>{}()));

  /**
   * @brief Test range with tst_bidirectional_iterator iterator
   */
  using test_bidirectional_range_type
    = ranges_concepts_tests_helper::test_range<test_iterator_helper::tst_bidirectional_iterator>;
  EXPECT_TRUE((::portable_stl::ranges::bidirectional_range<test_bidirectional_range_type>{}()));

  EXPECT_TRUE((::portable_stl::ranges::bidirectional_range<std::int32_t(&)[1]>{}()));
  EXPECT_TRUE((::portable_stl::ranges::bidirectional_range<std::int32_t const(&)[1]>{}()));
  EXPECT_TRUE((::portable_stl::ranges::bidirectional_range<std::int32_t[1]>{}()));
}

TEST(ranges_concepts, random_access_range) {
  static_cast<void>(test_info_);

  /**
   * @brief Test range with tst_input_iterator iterator
   */
  using test_input_range_type = ranges_concepts_tests_helper::test_range<test_iterator_helper::tst_input_iterator>;
  EXPECT_FALSE((::portable_stl::ranges::random_access_range<test_input_range_type>{}()));

  /**
   * @brief Test range with tst_bidirectional_iterator iterator
   */
  using test_bidirectional_range_type
    = ranges_concepts_tests_helper::test_range<test_iterator_helper::tst_bidirectional_iterator>;
  EXPECT_FALSE((::portable_stl::ranges::random_access_range<test_bidirectional_range_type>{}()));

  /**
   * @brief Test range with tst_random_access_iterator iterator
   */
  using test_random_access_range_type
    = ranges_concepts_tests_helper::test_range<test_iterator_helper::tst_random_access_iterator>;
  EXPECT_TRUE((::portable_stl::ranges::random_access_range<test_random_access_range_type>{}()));

  EXPECT_TRUE((::portable_stl::ranges::random_access_range<std::int32_t(&)[1]>{}()));
  EXPECT_TRUE((::portable_stl::ranges::random_access_range<std::int32_t const(&)[1]>{}()));
  EXPECT_TRUE((::portable_stl::ranges::random_access_range<std::int32_t[1]>{}()));
}

TEST(ranges_concepts, contiguous_range) {
  static_cast<void>(test_info_);

  /**
   * @brief Test range with tst_input_iterator iterator
   */
  using test_input_range_type = ranges_concepts_tests_helper::test_range<test_iterator_helper::tst_input_iterator>;
  EXPECT_FALSE((::portable_stl::ranges::contiguous_range<test_input_range_type>{}()));

  /**
   * @brief Test range with tst_bidirectional_iterator iterator
   */
  using test_bidirectional_range_type
    = ranges_concepts_tests_helper::test_range<test_iterator_helper::tst_bidirectional_iterator>;
  EXPECT_FALSE((::portable_stl::ranges::contiguous_range<test_bidirectional_range_type>{}()));

  /**
   * @brief Test range with tst_random_access_iterator iterator
   */
  using test_random_access_range_type
    = ranges_concepts_tests_helper::test_range<test_iterator_helper::tst_random_access_iterator>;
  EXPECT_FALSE((::portable_stl::ranges::contiguous_range<test_random_access_range_type>{}()));

  EXPECT_TRUE((::portable_stl::ranges::contiguous_range<std::int32_t(&)[1]>{}()));
  EXPECT_TRUE((::portable_stl::ranges::contiguous_range<std::int32_t const(&)[1]>{}()));
  EXPECT_TRUE((::portable_stl::ranges::contiguous_range<std::int32_t[1]>{}()));
}

TEST(ranges_concepts, common_range) {
  static_cast<void>(test_info_);

  EXPECT_FALSE((::portable_stl::ranges::common_range<ranges_concepts_tests_helper::incompatible_iterators>{}()));

  EXPECT_TRUE((::portable_stl::ranges::common_range<std::int32_t(&)[1]>{}()));
  EXPECT_TRUE((::portable_stl::ranges::common_range<std::int32_t const(&)[1]>{}()));
  EXPECT_TRUE((::portable_stl::ranges::common_range<std::int32_t[1]>{}()));
}
