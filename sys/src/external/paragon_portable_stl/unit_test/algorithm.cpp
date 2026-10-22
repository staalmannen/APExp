// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="algorithm.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "iterator_helper.h"
#include "portable_stl/algorithm/any_of.h"
#include "portable_stl/algorithm/find_end.h"
#include "portable_stl/algorithm/find_first_of.h"
#include "portable_stl/algorithm/find_if_not.h"
#include "portable_stl/algorithm/search.h"

namespace test_algorithm_helper {
/**
 * @brief Test unary predicate.
 */
class pred1 final {
public:
  /**
   * @brief The only operator.
   * @param value
   * @return true
   * @return false
   */
  constexpr bool operator()(std::int32_t const &value) const {
    return value % 2 == 0;
  }
};
} // namespace test_algorithm_helper

TEST(algorithm, any_of) {
  static_cast<void>(test_info_);

  /**
   * @brief Test input iterator type.
   */
  using t_iter = test_iterator_helper::tst_input_iterator<std::int32_t const *>;

  // all
  {
    std::int32_t const ia[] = {2, 4, 6, 8};
    unsigned const     sa{sizeof(ia) / sizeof(ia[0])};

    EXPECT_TRUE(::portable_stl::any_of(t_iter(ia), t_iter(ia + sa), test_algorithm_helper::pred1()));
  }

  // not all
  {
    std::int32_t const ia[] = {2, 4, 5, 8};
    unsigned const     sa{sizeof(ia) / sizeof(ia[0])};

    EXPECT_TRUE(::portable_stl::any_of(t_iter(ia), t_iter(ia + sa), test_algorithm_helper::pred1()));
  }

  // none
  {
    std::int32_t const ia2[] = {1, 3, 5, 7};
    unsigned const     sa2{sizeof(ia2) / sizeof(ia2[0])};

    EXPECT_FALSE(::portable_stl::any_of(t_iter(ia2), t_iter(ia2 + sa2), test_algorithm_helper::pred1()));
  }

  // first == last
  {
    std::int32_t const ia2[] = {1, 3, 5, 7};

    EXPECT_FALSE(::portable_stl::any_of(t_iter(ia2), t_iter(ia2), test_algorithm_helper::pred1()));
  }
}

namespace test_algorithm_helper {

/**
 * @brief Helper function to test find_end with different iterator types.
 * @tparam t_iter1_type
 * @tparam t_iter2_type
 */
template<class t_iter1_type, class t_iter2_type> void find_end_test() {
  std::int32_t const ia[]{0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 0, 1, 2, 3, 0, 1, 2, 0, 1, 0};
  unsigned const     sa{sizeof(ia) / sizeof(ia[0])};

  std::int32_t const b[]{0};
  EXPECT_EQ(::portable_stl::find_end(t_iter1_type(ia), t_iter1_type(&ia[sa]), t_iter2_type(b), t_iter2_type(&b[1])),
            t_iter1_type(&ia[sa - 1]));

  {
    std::int32_t c[]{0, 1};
    EXPECT_EQ(::portable_stl::find_end(t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(c), t_iter2_type(c + 2)),
              t_iter1_type(ia + 18));
  }
  {
    std::int32_t d[]{0, 1, 2};
    EXPECT_EQ(::portable_stl::find_end(t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(d), t_iter2_type(d + 3)),
              t_iter1_type(ia + 15));
  }
  {
    std::int32_t e[]{0, 1, 2, 3};
    EXPECT_EQ(::portable_stl::find_end(t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(e), t_iter2_type(e + 4)),
              t_iter1_type(ia + 11));
  }
  {
    std::int32_t f[]{0, 1, 2, 3, 4};
    EXPECT_EQ(::portable_stl::find_end(t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(f), t_iter2_type(f + 5)),
              t_iter1_type(ia + 6));
  }
  {
    std::int32_t g[]{0, 1, 2, 3, 4, 5};
    EXPECT_EQ(::portable_stl::find_end(t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(g), t_iter2_type(g + 6)),
              t_iter1_type(ia));
  }
  {
    std::int32_t h[]{0, 1, 2, 3, 4, 5, 6};
    EXPECT_EQ(::portable_stl::find_end(t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(h), t_iter2_type(h + 7)),
              t_iter1_type(ia + sa));
    EXPECT_EQ(::portable_stl::find_end(t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(b), t_iter2_type(b)),
              t_iter1_type(ia + sa));
    EXPECT_EQ(::portable_stl::find_end(t_iter1_type(ia), t_iter1_type(ia), t_iter2_type(b), t_iter2_type(b + 1)),
              t_iter1_type(ia));
  }
}
} // namespace test_algorithm_helper

TEST(algorithm, find_end) {
  static_cast<void>(test_info_);
  test_algorithm_helper::find_end_test<test_iterator_helper::tst_forward_iterator<std::int32_t const *>,
                                       test_iterator_helper::tst_forward_iterator<std::int32_t const *>>();

  test_algorithm_helper::find_end_test<test_iterator_helper::tst_forward_iterator<std::int32_t const *>,
                                       test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>>();

  test_algorithm_helper::find_end_test<test_iterator_helper::tst_forward_iterator<std::int32_t const *>,
                                       test_iterator_helper::tst_random_access_iterator<std::int32_t const *>>();

  test_algorithm_helper::find_end_test<test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>,
                                       test_iterator_helper::tst_forward_iterator<std::int32_t const *>>();

  test_algorithm_helper::find_end_test<test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>,
                                       test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>>();

  test_algorithm_helper::find_end_test<test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>,
                                       test_iterator_helper::tst_random_access_iterator<std::int32_t const *>>();

  test_algorithm_helper::find_end_test<test_iterator_helper::tst_random_access_iterator<std::int32_t const *>,
                                       test_iterator_helper::tst_forward_iterator<std::int32_t const *>>();

  test_algorithm_helper::find_end_test<test_iterator_helper::tst_random_access_iterator<std::int32_t const *>,
                                       test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>>();

  test_algorithm_helper::find_end_test<test_iterator_helper::tst_random_access_iterator<std::int32_t const *>,
                                       test_iterator_helper::tst_random_access_iterator<std::int32_t const *>>();
}

namespace test_algorithm_helper {

/**
 * @brief Test predicate.
 */
class count_equal final {
public:
  /**
   * @brief Statistic data.
   */
  static std::uint32_t        count;
  /**
   * @brief The only operator.
   * @tparam t_type
   * @param x
   * @param y
   * @return true
   * @return false
   */
  template<class t_type> bool operator()(t_type const &x, t_type const &y) {
    ++count;
    return x == y;
  }
};

std::uint32_t count_equal::count{0};

/**
 * @brief Helper function to test find_end with predicate and different iterator types.
 * @tparam t_iter1_type
 * @tparam t_iter2_type
 */
template<class t_iter1_type, class t_iter2_type> void find_end_pred_test() {
  std::int32_t   ia[] = {0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 0, 1, 2, 3, 0, 1, 2, 0, 1, 0};
  unsigned const sa{sizeof(ia) / sizeof(ia[0])};

  std::int32_t b[]{0};

  {
    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::find_end(
                t_iter1_type(ia), t_iter1_type(&ia[sa]), t_iter2_type(b), t_iter2_type(&b[1]), count_equal()),
              t_iter1_type(&ia[sa - 1]));
    ASSERT_LE(count_equal::count, 1 * (sa - 1 + 1));
  }
  {
    std::int32_t c[]{0, 1};
    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::find_end(
                t_iter1_type(ia), t_iter1_type(&ia[sa]), t_iter2_type(c), t_iter2_type(&c[2]), count_equal()),
              t_iter1_type(ia + 18));
    ASSERT_LE(count_equal::count, 2 * (sa - 2 + 1));
  }
  {
    std::int32_t d[]{0, 1, 2};
    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::find_end(
                t_iter1_type(ia), t_iter1_type(&ia[sa]), t_iter2_type(d), t_iter2_type(d + 3), count_equal()),
              t_iter1_type(ia + 15));
    ASSERT_LE(count_equal::count, 3 * (sa - 3 + 1));
  }
  {
    std::int32_t e[]{0, 1, 2, 3};
    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::find_end(
                t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(e), t_iter2_type(e + 4), count_equal()),
              t_iter1_type(ia + 11));
    ASSERT_LE(count_equal::count, 4 * (sa - 4 + 1));
  }
  {
    std::int32_t f[]{0, 1, 2, 3, 4};
    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::find_end(
                t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(f), t_iter2_type(f + 5), count_equal()),
              t_iter1_type(ia + 6));
    ASSERT_LE(count_equal::count, 5 * (sa - 5 + 1));
  }
  {
    std::int32_t g[]{0, 1, 2, 3, 4, 5};
    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::find_end(
                t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(g), t_iter2_type(g + 6), count_equal()),
              t_iter1_type(ia));
    ASSERT_LE(count_equal::count, 6 * (sa - 6 + 1));
  }

  {
    std::int32_t h[]{0, 1, 2, 3, 4, 5, 6};
    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::find_end(
                t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(h), t_iter2_type(h + 7), count_equal()),
              t_iter1_type(ia + sa));
    ASSERT_LE(count_equal::count, 7 * (sa - 7 + 1));
  }
  {
    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::find_end(
                t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(b), t_iter2_type(b), count_equal()),
              t_iter1_type(ia + sa));
    ASSERT_LE(count_equal::count, 0);
  }
  {
    count_equal::count = 0;
    EXPECT_EQ(
      ::portable_stl::find_end(t_iter1_type(ia), t_iter1_type(ia), t_iter2_type(b), t_iter2_type(b + 1), count_equal()),
      t_iter1_type(ia));
    ASSERT_LE(count_equal::count, 0);
  }
}
} // namespace test_algorithm_helper

TEST(algorithm, find_end_pred) {
  static_cast<void>(test_info_);

  test_algorithm_helper::find_end_pred_test<test_iterator_helper::tst_forward_iterator<std::int32_t const *>,
                                            test_iterator_helper::tst_forward_iterator<std::int32_t const *>>();

  test_algorithm_helper::find_end_pred_test<test_iterator_helper::tst_forward_iterator<std::int32_t const *>,
                                            test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>>();

  test_algorithm_helper::find_end_pred_test<test_iterator_helper::tst_forward_iterator<std::int32_t const *>,
                                            test_iterator_helper::tst_random_access_iterator<std::int32_t const *>>();

  test_algorithm_helper::find_end_pred_test<test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>,
                                            test_iterator_helper::tst_forward_iterator<std::int32_t const *>>();

  test_algorithm_helper::find_end_pred_test<test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>,
                                            test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>>();

  test_algorithm_helper::find_end_pred_test<test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>,
                                            test_iterator_helper::tst_random_access_iterator<std::int32_t const *>>();

  test_algorithm_helper::find_end_pred_test<test_iterator_helper::tst_random_access_iterator<std::int32_t const *>,
                                            test_iterator_helper::tst_forward_iterator<std::int32_t const *>>();

  test_algorithm_helper::find_end_pred_test<test_iterator_helper::tst_random_access_iterator<std::int32_t const *>,
                                            test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>>();

  test_algorithm_helper::find_end_pred_test<test_iterator_helper::tst_random_access_iterator<std::int32_t const *>,
                                            test_iterator_helper::tst_random_access_iterator<std::int32_t const *>>();
}

TEST(algorithm, find_first_of) {
  static_cast<void>(test_info_);

  std::int32_t   ia[]{0, 1, 2, 3, 0, 1, 2, 3};
  unsigned const sa{sizeof(ia) / sizeof(ia[0])};

  std::int32_t   ib[]{1, 3, 5, 7};
  unsigned const sb{sizeof(ib) / sizeof(ib[0])};

  EXPECT_EQ(::portable_stl::find_first_of(test_iterator_helper::tst_input_iterator<std::int32_t const *>(ia),
                                          test_iterator_helper::tst_input_iterator<std::int32_t const *>(&ia[sa]),
                                          test_iterator_helper::tst_forward_iterator<std::int32_t const *>(ib),
                                          test_iterator_helper::tst_forward_iterator<std::int32_t const *>(&ib[sb])),
            test_iterator_helper::tst_input_iterator<std::int32_t const *>(&ia[1]));

  std::int32_t ic[]{7};
  EXPECT_EQ(::portable_stl::find_first_of(test_iterator_helper::tst_input_iterator<std::int32_t const *>(ia),
                                          test_iterator_helper::tst_input_iterator<std::int32_t const *>(&ia[sa]),
                                          test_iterator_helper::tst_forward_iterator<std::int32_t const *>(ic),
                                          test_iterator_helper::tst_forward_iterator<std::int32_t const *>(&ic[1])),
            test_iterator_helper::tst_input_iterator<std::int32_t const *>(&ia[sa]));

  EXPECT_EQ(::portable_stl::find_first_of(test_iterator_helper::tst_input_iterator<std::int32_t const *>(ia),
                                          test_iterator_helper::tst_input_iterator<std::int32_t const *>(&ia[sa]),
                                          test_iterator_helper::tst_forward_iterator<std::int32_t const *>(ic),
                                          test_iterator_helper::tst_forward_iterator<std::int32_t const *>(ic)),
            test_iterator_helper::tst_input_iterator<std::int32_t const *>(&ia[sa]));

  EXPECT_EQ(::portable_stl::find_first_of(test_iterator_helper::tst_input_iterator<std::int32_t const *>(ia),
                                          test_iterator_helper::tst_input_iterator<std::int32_t const *>(ia),
                                          test_iterator_helper::tst_forward_iterator<std::int32_t const *>(ic),
                                          test_iterator_helper::tst_forward_iterator<std::int32_t const *>(&ic[1])),
            test_iterator_helper::tst_input_iterator<std::int32_t const *>(ia));
}

TEST(algorithm, find_first_of_pred) {
  static_cast<void>(test_info_);

  std::int32_t   ia[]{0, 1, 2, 3, 0, 1, 2, 3};
  unsigned const sa{sizeof(ia) / sizeof(ia[0])};

  std::int32_t   ib[]{1, 3, 5, 7};
  unsigned const sb{sizeof(ib) / sizeof(ib[0])};

  EXPECT_EQ(::portable_stl::find_first_of(test_iterator_helper::tst_input_iterator<std::int32_t const *>(ia),
                                          test_iterator_helper::tst_input_iterator<std::int32_t const *>(&ia[sa]),
                                          test_iterator_helper::tst_forward_iterator<std::int32_t const *>(ib),
                                          test_iterator_helper::tst_forward_iterator<std::int32_t const *>(&ib[sb]),
                                          std::equal_to<std::int32_t>()),
            test_iterator_helper::tst_input_iterator<std::int32_t const *>(&ia[1]));

  std::int32_t ic[]{7};
  EXPECT_EQ(::portable_stl::find_first_of(test_iterator_helper::tst_input_iterator<std::int32_t const *>(ia),
                                          test_iterator_helper::tst_input_iterator<std::int32_t const *>(&ia[sa]),
                                          test_iterator_helper::tst_forward_iterator<std::int32_t const *>(ic),
                                          test_iterator_helper::tst_forward_iterator<std::int32_t const *>(&ic[1]),
                                          std::equal_to<std::int32_t>()),
            test_iterator_helper::tst_input_iterator<std::int32_t const *>(&ia[sa]));

  EXPECT_EQ(::portable_stl::find_first_of(test_iterator_helper::tst_input_iterator<std::int32_t const *>(ia),
                                          test_iterator_helper::tst_input_iterator<std::int32_t const *>(&ia[sa]),
                                          test_iterator_helper::tst_forward_iterator<std::int32_t const *>(ic),
                                          test_iterator_helper::tst_forward_iterator<std::int32_t const *>(ic),
                                          std::equal_to<std::int32_t>()),
            test_iterator_helper::tst_input_iterator<std::int32_t const *>(&ia[sa]));

  EXPECT_EQ(::portable_stl::find_first_of(test_iterator_helper::tst_input_iterator<std::int32_t const *>(ia),
                                          test_iterator_helper::tst_input_iterator<std::int32_t const *>(ia),
                                          test_iterator_helper::tst_forward_iterator<std::int32_t const *>(ic),
                                          test_iterator_helper::tst_forward_iterator<std::int32_t const *>(&ic[1]),
                                          std::equal_to<std::int32_t>()),
            test_iterator_helper::tst_input_iterator<std::int32_t const *>(ia));
}

namespace test_algorithm_helper {

/**
 * @brief Test conditional predicate.
 */
class DifferentFrom final {
public:
  std::int32_t m_value;
  /**
   * @brief Ctor
   */
  constexpr explicit DifferentFrom(std::int32_t value) noexcept : m_value(value) {
  }
  /**
   * @brief The only unary operator
   *
   * @param other
   * @return true
   * @return false
   */
  constexpr bool operator()(std::int32_t other) const noexcept {
    return m_value != other;
  }
};

/**
 * @brief Helper function to test find_if_not with different iterator types.
 * @tparam t_iter_type
 */
template<class t_iter_type> void find_if_not_test() {
  std::int32_t range[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // We don't find what we're looking for in the range
  {
    {
      t_iter_type result{::portable_stl::find_if_not(t_iter_type(range), t_iter_type(range), DifferentFrom(0))};
      ASSERT_EQ(result, t_iter_type(range));
    }
    {
      t_iter_type result{
        ::portable_stl::find_if_not(t_iter_type(range), t_iter_type(std::end(range)), DifferentFrom(999))};
      ASSERT_EQ(result, t_iter_type(std::end(range)));
    }
  }

  // Tests with sub-ranges of various sizes
  for (std::int32_t size{1}; size != 10; ++size) {
    for (std::int32_t i{0}; i != size - 1; ++i) {
      t_iter_type result{::portable_stl::find_if_not(t_iter_type(range), t_iter_type(&range[size]), DifferentFrom(i))};
      ASSERT_EQ(result, t_iter_type(&range[i]));
    }
  }
}
} // namespace test_algorithm_helper

TEST(algorithm, find_if_not) {
  static_cast<void>(test_info_);

  test_algorithm_helper::find_if_not_test<test_iterator_helper::tst_input_iterator<std::int32_t *>>();
  test_algorithm_helper::find_if_not_test<test_iterator_helper::tst_forward_iterator<std::int32_t *>>();
  test_algorithm_helper::find_if_not_test<test_iterator_helper::tst_bidirectional_iterator<std::int32_t *>>();
  test_algorithm_helper::find_if_not_test<test_iterator_helper::tst_random_access_iterator<std::int32_t *>>();
}

namespace test_algorithm_helper {

/**
 * @brief Helper function to test search with different iterator types.
 * @tparam t_iter1_type
 * @tparam t_iter2_type
 */
template<class t_iter1_type, class t_iter2_type> void search_test() {
  {
    std::int32_t   ia[]{0, 1, 2, 3, 4, 5};
    unsigned const sa{sizeof(ia) / sizeof(ia[0])};

    EXPECT_EQ(::portable_stl::search(t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(ia), t_iter2_type(ia)),
              t_iter1_type(ia));
    EXPECT_EQ(::portable_stl::search(t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(ia), t_iter2_type(ia + 1)),
              t_iter1_type(ia));
    EXPECT_EQ(
      ::portable_stl::search(t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(ia + 1), t_iter2_type(ia + 2)),
      t_iter1_type(ia + 1));
    EXPECT_EQ(
      ::portable_stl::search(t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(ia + 2), t_iter2_type(ia + 2)),
      t_iter1_type(ia));
    EXPECT_EQ(
      ::portable_stl::search(t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(ia + 2), t_iter2_type(ia + 3)),
      t_iter1_type(ia + 2));
    EXPECT_EQ(
      ::portable_stl::search(t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(ia + 2), t_iter2_type(ia + 3)),
      t_iter1_type(ia + 2));
    EXPECT_EQ(::portable_stl::search(t_iter1_type(ia), t_iter1_type(ia), t_iter2_type(ia + 2), t_iter2_type(ia + 3)),
              t_iter1_type(ia));
    EXPECT_EQ(
      ::portable_stl::search(t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(ia + sa - 1), t_iter2_type(ia + sa)),
      t_iter1_type(ia + sa - 1));
    EXPECT_EQ(
      ::portable_stl::search(t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(ia + sa - 3), t_iter2_type(ia + sa)),
      t_iter1_type(ia + sa - 3));

    EXPECT_EQ(::portable_stl::search(t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(ia), t_iter2_type(ia + sa)),
              t_iter1_type(ia));
    EXPECT_EQ(
      ::portable_stl::search(t_iter1_type(ia), t_iter1_type(ia + sa - 1), t_iter2_type(ia), t_iter2_type(ia + sa)),
      t_iter1_type(ia + sa - 1));
    EXPECT_EQ(::portable_stl::search(t_iter1_type(ia), t_iter1_type(ia + 1), t_iter2_type(ia), t_iter2_type(ia + sa)),
              t_iter1_type(ia + 1));
  }

  std::int32_t   ib[]{0, 1, 2, 0, 1, 2, 3, 0, 1, 2, 3, 4};
  unsigned const sb{sizeof(ib) / sizeof(ib[0])};

  {
    std::int32_t ic[]{1};
    EXPECT_EQ(::portable_stl::search(t_iter1_type(ib), t_iter1_type(ib + sb), t_iter2_type(ic), t_iter2_type(ic + 1)),
              t_iter1_type(ib + 1));
  }
  {
    std::int32_t id[]{1, 2};
    EXPECT_EQ(::portable_stl::search(t_iter1_type(ib), t_iter1_type(ib + sb), t_iter2_type(id), t_iter2_type(id + 2)),
              t_iter1_type(ib + 1));
  }
  {
    std::int32_t ie[]{1, 2, 3};
    EXPECT_EQ(::portable_stl::search(t_iter1_type(ib), t_iter1_type(ib + sb), t_iter2_type(ie), t_iter2_type(ie + 3)),
              t_iter1_type(ib + 4));
  }
  {
    std::int32_t ig[]{1, 2, 3, 4};
    EXPECT_EQ(::portable_stl::search(t_iter1_type(ib), t_iter1_type(ib + sb), t_iter2_type(ig), t_iter2_type(ig + 4)),
              t_iter1_type(ib + 8));
  }
  {
    std::int32_t   ih[]{0, 1, 1, 1, 1, 2, 3, 0, 1, 2, 3, 4};
    unsigned const sh = sizeof(ih) / sizeof(ih[0]);
    std::int32_t   ii[]{1, 1, 2};
    EXPECT_EQ(::portable_stl::search(t_iter1_type(ih), t_iter1_type(ih + sh), t_iter2_type(ii), t_iter2_type(ii + 3)),
              t_iter1_type(ih + 3));
  }
  {
    std::int32_t   ij[]{0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0};
    unsigned const sj{sizeof(ij) / sizeof(ij[0])};
    std::int32_t   ik[]{0, 0, 0, 0, 1, 1, 1, 1, 0, 0};
    unsigned const sk{sizeof(ik) / sizeof(ik[0])};
    EXPECT_EQ(::portable_stl::search(t_iter1_type(ij), t_iter1_type(ij + sj), t_iter2_type(ik), t_iter2_type(ik + sk)),
              t_iter1_type(ij + 6));
  }
}

namespace search_adl {
  /**
   * @brief
   */
  class S final {
  public:
    /**
     * @brief Construct a new S object
     * @param value
     */
    S(std::int32_t value) : m_value(value) {
    }
    /**
     * @brief Data.
     */
    int m_value;
  };

  /**
   * @brief Equality operator to anable ADL in equal_to<>
   *
   * @param lhs
   * @param rhs
   * @return true
   * @return false
   */
  static bool operator==(S lhs, S rhs) {
    return lhs.m_value == rhs.m_value;
  }
  // template<class T, class U> void make_pair(T &&, U &&) = delete;
} // namespace search_adl

/**
 * @brief
 * @tparam t_iter_type
 */
template<class t_iter_type> void search_adl_test() {
  search_adl::S ua[]{1};
  EXPECT_EQ(::portable_stl::search(t_iter_type(ua), t_iter_type(ua), t_iter_type(ua), t_iter_type(ua)),
            t_iter_type(ua));
}
} // namespace test_algorithm_helper

TEST(algorithm, search) {
  static_cast<void>(test_info_);

  {
    test_algorithm_helper::search_test<test_iterator_helper::tst_forward_iterator<std::int32_t const *>,
                                       test_iterator_helper::tst_forward_iterator<std::int32_t const *>>();

    test_algorithm_helper::search_test<test_iterator_helper::tst_forward_iterator<std::int32_t const *>,
                                       test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>>();

    test_algorithm_helper::search_test<test_iterator_helper::tst_forward_iterator<std::int32_t const *>,
                                       test_iterator_helper::tst_random_access_iterator<std::int32_t const *>>();

    test_algorithm_helper::search_test<test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>,
                                       test_iterator_helper::tst_forward_iterator<std::int32_t const *>>();

    test_algorithm_helper::search_test<test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>,
                                       test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>>();

    test_algorithm_helper::search_test<test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>,
                                       test_iterator_helper::tst_random_access_iterator<std::int32_t const *>>();

    test_algorithm_helper::search_test<test_iterator_helper::tst_random_access_iterator<std::int32_t const *>,
                                       test_iterator_helper::tst_forward_iterator<std::int32_t const *>>();

    test_algorithm_helper::search_test<test_iterator_helper::tst_random_access_iterator<std::int32_t const *>,
                                       test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>>();

    test_algorithm_helper::search_test<test_iterator_helper::tst_random_access_iterator<std::int32_t const *>,
                                       test_iterator_helper::tst_random_access_iterator<std::int32_t const *>>();
  }
  {
    test_algorithm_helper::search_adl_test<
      test_iterator_helper::tst_forward_iterator<test_algorithm_helper::search_adl::S *>>();

    test_algorithm_helper::search_adl_test<
      test_iterator_helper::tst_random_access_iterator<test_algorithm_helper::search_adl::S *>>();
  }
}

namespace test_algorithm_helper {
/**
 * @brief Helper function to test search with predicate different iterator types.
 * @tparam t_iter1_type
 * @tparam t_iter2_type
 */
template<class t_iter1_type, class t_iter2_type> void search_test_pred() {
  {
    std::int32_t   ia[]{0, 1, 2, 3, 4, 5};
    unsigned const sa{sizeof(ia) / sizeof(ia[0])};
    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::search(
                t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(ia), t_iter2_type(ia), count_equal()),
              t_iter1_type(ia));
    EXPECT_LE(count_equal::count, 0);

    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::search(
                t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(ia), t_iter2_type(ia + 1), count_equal()),
              t_iter1_type(ia));
    EXPECT_LE(count_equal::count, sa);

    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::search(
                t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(ia + 1), t_iter2_type(ia + 2), count_equal()),
              t_iter1_type(ia + 1));
    EXPECT_LE(count_equal::count, sa);

    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::search(
                t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(ia + 2), t_iter2_type(ia + 2), count_equal()),
              t_iter1_type(ia));
    EXPECT_LE(count_equal::count, 0);

    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::search(
                t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(ia + 2), t_iter2_type(ia + 3), count_equal()),
              t_iter1_type(ia + 2));
    EXPECT_LE(count_equal::count, sa);

    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::search(
                t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(ia + 2), t_iter2_type(ia + 3), count_equal()),
              t_iter1_type(ia + 2));
    EXPECT_LE(count_equal::count, sa);

    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::search(
                t_iter1_type(ia), t_iter1_type(ia), t_iter2_type(ia + 2), t_iter2_type(ia + 3), count_equal()),
              t_iter1_type(ia));
    EXPECT_LE(count_equal::count, 0);

    count_equal::count = 0;
    EXPECT_EQ(
      ::portable_stl::search(
        t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(ia + sa - 1), t_iter2_type(ia + sa), count_equal()),
      t_iter1_type(ia + sa - 1));
    EXPECT_LE(count_equal::count, sa);

    count_equal::count = 0;
    EXPECT_EQ(
      ::portable_stl::search(
        t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(ia + sa - 3), t_iter2_type(ia + sa), count_equal()),
      t_iter1_type(ia + sa - 3));
    EXPECT_LE(count_equal::count, sa * 3);

    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::search(
                t_iter1_type(ia), t_iter1_type(ia + sa), t_iter2_type(ia), t_iter2_type(ia + sa), count_equal()),
              t_iter1_type(ia));
    EXPECT_LE(count_equal::count, sa * sa);

    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::search(
                t_iter1_type(ia), t_iter1_type(ia + sa - 1), t_iter2_type(ia), t_iter2_type(ia + sa), count_equal()),
              t_iter1_type(ia + sa - 1));
    EXPECT_LE(count_equal::count, (sa - 1) * sa);

    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::search(
                t_iter1_type(ia), t_iter1_type(ia + 1), t_iter2_type(ia), t_iter2_type(ia + sa), count_equal()),
              t_iter1_type(ia + 1));
    EXPECT_LE(count_equal::count, sa);
  }
  std::int32_t   ib[]{0, 1, 2, 0, 1, 2, 3, 0, 1, 2, 3, 4};
  unsigned const sb{sizeof(ib) / sizeof(ib[0])};

  {
    std::int32_t ic[]{1};
    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::search(
                t_iter1_type(ib), t_iter1_type(ib + sb), t_iter2_type(ic), t_iter2_type(ic + 1), count_equal()),
              t_iter1_type(ib + 1));
    EXPECT_LE(count_equal::count, sb);
  }
  {
    std::int32_t id[]{1, 2};
    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::search(
                t_iter1_type(ib), t_iter1_type(ib + sb), t_iter2_type(id), t_iter2_type(id + 2), count_equal()),
              t_iter1_type(ib + 1));
    EXPECT_LE(count_equal::count, sb * 2);
  }
  {
    std::int32_t ie[]{1, 2, 3};
    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::search(
                t_iter1_type(ib), t_iter1_type(ib + sb), t_iter2_type(ie), t_iter2_type(ie + 3), count_equal()),
              t_iter1_type(ib + 4));
    EXPECT_LE(count_equal::count, sb * 3);
  }
  {
    std::int32_t ig[]{1, 2, 3, 4};
    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::search(
                t_iter1_type(ib), t_iter1_type(ib + sb), t_iter2_type(ig), t_iter2_type(ig + 4), count_equal()),
              t_iter1_type(ib + 8));
    EXPECT_LE(count_equal::count, sb * 4);
  }
  {
    std::int32_t   ih[]{0, 1, 1, 1, 1, 2, 3, 0, 1, 2, 3, 4};
    unsigned const sh = sizeof(ih) / sizeof(ih[0]);
    std::int32_t   ii[]{1, 1, 2};
    count_equal::count = 0;
    EXPECT_EQ(::portable_stl::search(
                t_iter1_type(ih), t_iter1_type(ih + sh), t_iter2_type(ii), t_iter2_type(ii + 3), count_equal()),
              t_iter1_type(ih + 3));
    EXPECT_LE(count_equal::count, sh * 3);
  }
}
} // namespace test_algorithm_helper

TEST(algorithm, search_pred) {
  static_cast<void>(test_info_);

  test_algorithm_helper::search_test_pred<test_iterator_helper::tst_forward_iterator<std::int32_t const *>,
                                          test_iterator_helper::tst_forward_iterator<std::int32_t const *>>();

  test_algorithm_helper::search_test_pred<test_iterator_helper::tst_forward_iterator<std::int32_t const *>,
                                          test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>>();

  test_algorithm_helper::search_test_pred<test_iterator_helper::tst_forward_iterator<std::int32_t const *>,
                                          test_iterator_helper::tst_random_access_iterator<std::int32_t const *>>();

  test_algorithm_helper::search_test_pred<test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>,
                                          test_iterator_helper::tst_forward_iterator<std::int32_t const *>>();

  test_algorithm_helper::search_test_pred<test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>,
                                          test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>>();

  test_algorithm_helper::search_test_pred<test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>,
                                          test_iterator_helper::tst_random_access_iterator<std::int32_t const *>>();

  test_algorithm_helper::search_test_pred<test_iterator_helper::tst_random_access_iterator<std::int32_t const *>,
                                          test_iterator_helper::tst_forward_iterator<std::int32_t const *>>();

  test_algorithm_helper::search_test_pred<test_iterator_helper::tst_random_access_iterator<std::int32_t const *>,
                                          test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>>();

  test_algorithm_helper::search_test_pred<test_iterator_helper::tst_random_access_iterator<std::int32_t const *>,
                                          test_iterator_helper::tst_random_access_iterator<std::int32_t const *>>();
}
