// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="set_construction.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <algorithm>
#include <portable_stl/set/set.h>

#include "../common/counter.h"
#include "../common/move_only.h"
#include "../common/test_allocator.h"
#include "../common/test_compare.h"
#include "portable_stl/iterator/move_iterator.h"

TEST(set, constructor_default) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::set<std::int32_t> st;
    ASSERT_TRUE(st.empty());
    ASSERT_EQ(st.begin(), st.end());
  }
  {
    ::portable_stl::set<std::int32_t> st = {};
    ASSERT_TRUE(st.empty());
    ASSERT_EQ(st.begin(), st.end());
  }
}

namespace test_set_helper {

template<class t_type> class some_comp final {
public:
  using value_type = t_type;
  some_comp();
  bool operator()(t_type const &, t_type const &) const {
    return false;
  }
};
} // namespace test_set_helper

TEST(set, constructor_default_noexcept) {
  static_cast<void>(test_info_);

  {
    using t_container = ::portable_stl::set<test_common_helper::MoveOnly>;
    ASSERT_TRUE(std::is_nothrow_default_constructible<t_container>{});
  }
  {
    using t_container = ::portable_stl::set<test_common_helper::MoveOnly,
                                            std::less<::test_common_helper::MoveOnly>,
                                            ::portable_stl::allocator<test_common_helper::MoveOnly>>;
    ASSERT_TRUE(std::is_nothrow_default_constructible<t_container>{});
  }
  {
    using t_container
      = ::portable_stl::set<test_common_helper::MoveOnly, test_set_helper::some_comp<test_common_helper::MoveOnly>>;

    ASSERT_FALSE(std::is_nothrow_default_constructible<t_container>{});
  }
}

using t_compare = test_common_helper::test_less<std::int32_t>;

using t_allocator = test_allocator_helper::TestSimpleAllocator<std::int32_t>;

using t_allocator2 = test_allocator_helper::test_allocator<std::int32_t>;

using t_tree_allocator = test_allocator_helper::TestSimpleAllocator<portable_stl::tree_node<std::int32_t, void *>>;

namespace test_set_helper {
static std::int32_t arr[] = {1, 2, 3, 1, 2, 3, 1, 2, 3};

static size_t const arr_size = sizeof(arr) / sizeof(arr[0]);

static std::int32_t *const arr_end = &arr[arr_size];
} // namespace test_set_helper

TEST(set, constructor_compare) {
  static_cast<void>(test_info_);

  ::portable_stl::set<std::int32_t, t_compare> const st(t_compare(3));

  ASSERT_TRUE(st.empty());
  ASSERT_EQ(st.begin(), st.end());
  ASSERT_EQ(st.key_comp(), t_compare(3));
}

TEST(set, constructor_allocator) {
  static_cast<void>(test_info_);

  ::portable_stl::set<std::int32_t, t_compare, t_allocator> const st(t_allocator(4));

  ASSERT_TRUE(st.empty());
  ASSERT_EQ(st.begin(), st.end());
  ASSERT_EQ(st.get_allocator(), t_allocator(4));
}

TEST(set, constructor_compare_allocator) {
  static_cast<void>(test_info_);

  ::portable_stl::set<std::int32_t, t_compare, t_allocator> const st(t_compare(3), t_allocator(4));

  ASSERT_TRUE(st.empty());
  ASSERT_EQ(st.begin(), st.end());
  ASSERT_EQ(st.key_comp(), t_compare(3));
  ASSERT_EQ(st.get_allocator(), t_allocator(4));
}

TEST(set, constructor_iter_iter) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::set<std::int32_t> st(test_set_helper::arr, test_set_helper::arr_end);

    ASSERT_EQ(3, st.size());
    ASSERT_EQ(3, ::portable_stl::distance(st.begin(), st.end()));
    EXPECT_EQ(1, *st.begin());
    EXPECT_EQ(2, *::portable_stl::next(st.begin()));
    EXPECT_EQ(3, *::portable_stl::next(st.begin(), 2));
  }

  // bad alloc
  {
    t_tree_allocator::m_counter_ok_allocation = 0;

    try {
      ::portable_stl::set<std::int32_t, ::portable_stl::less<std::int32_t>, t_allocator> st(test_set_helper::arr,
                                                                                            test_set_helper::arr_end);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }

    t_tree_allocator::m_counter_ok_allocation = 10000;
  }
}

TEST(set, make_set_iter_iter) {
  static_cast<void>(test_info_);

  {
    auto result = ::portable_stl::set<std::int32_t>::make_set(test_set_helper::arr, test_set_helper::arr_end);
    ASSERT_TRUE(result);

    auto st = result.value();
    ASSERT_EQ(3, st.size());
    ASSERT_EQ(3, ::portable_stl::distance(st.begin(), st.end()));
    EXPECT_EQ(1, *st.begin());
    EXPECT_EQ(2, *::portable_stl::next(st.begin()));
    EXPECT_EQ(3, *::portable_stl::next(st.begin(), 2));
  }

  // bad alloc
  {
    t_tree_allocator::m_counter_ok_allocation = 0;

    auto result = ::portable_stl::set<std::int32_t, ::portable_stl::less<std::int32_t>, t_allocator>::make_set(
      test_set_helper::arr, test_set_helper::arr_end);

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    t_tree_allocator::m_counter_ok_allocation = 10000;
  }
}

TEST(set, constructor_iter_iter_comp) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::set<std::int32_t, t_compare> st(test_set_helper::arr, test_set_helper::arr_end, t_compare(3));

    ASSERT_EQ(3, st.size());
    ASSERT_EQ(t_compare(3), st.key_comp());
    ASSERT_EQ(3, ::portable_stl::distance(st.begin(), st.end()));
    EXPECT_EQ(1, *st.begin());
    EXPECT_EQ(2, *::portable_stl::next(st.begin()));
    EXPECT_EQ(3, *::portable_stl::next(st.begin(), 2));
  }

  // bad alloc
  {
    t_tree_allocator::m_counter_ok_allocation = 0;

    try {
      ::portable_stl::set<std::int32_t, t_compare, t_allocator> st(
        test_set_helper::arr, test_set_helper::arr_end, t_compare(3));
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }

    t_tree_allocator::m_counter_ok_allocation = 10000;
  }
}

TEST(set, make_set_iter_iter_comp) {
  static_cast<void>(test_info_);

  {
    auto result = ::portable_stl::set<std::int32_t, t_compare>::make_set(
      test_set_helper::arr, test_set_helper::arr_end, t_compare(3));
    ASSERT_TRUE(result);

    auto st = result.value();
    ASSERT_EQ(3, st.size());
    ASSERT_EQ(t_compare(3), st.key_comp());
    ASSERT_EQ(3, ::portable_stl::distance(st.begin(), st.end()));
    EXPECT_EQ(1, *st.begin());
    EXPECT_EQ(2, *::portable_stl::next(st.begin()));
    EXPECT_EQ(3, *::portable_stl::next(st.begin(), 2));
  }

  // bad alloc
  {
    t_tree_allocator::m_counter_ok_allocation = 0;

    auto result = ::portable_stl::set<std::int32_t, t_compare, t_allocator>::make_set(
      test_set_helper::arr, test_set_helper::arr_end, t_compare(3));

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    t_tree_allocator::m_counter_ok_allocation = 10000;
  }
}

TEST(set, constructor_iter_iter_allocator) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::set<std::int32_t, t_compare, t_allocator> st(
      test_set_helper::arr, test_set_helper::arr_end, t_allocator(4));

    ASSERT_EQ(t_allocator(4), st.get_allocator());
    ASSERT_EQ(3, st.size());
    ASSERT_EQ(3, ::portable_stl::distance(st.begin(), st.end()));
    EXPECT_EQ(1, *st.begin());
    EXPECT_EQ(2, *::portable_stl::next(st.begin()));
    EXPECT_EQ(3, *::portable_stl::next(st.begin(), 2));
  }

  // bad alloc
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 1;
    t_allocator2 alloc(&stat);

    try {
      ::portable_stl::set<std::int32_t, t_compare, t_allocator2> st(
        test_set_helper::arr, test_set_helper::arr_end, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

TEST(set, make_set_iter_iter_allocator) {
  static_cast<void>(test_info_);

  {
    auto result = ::portable_stl::set<std::int32_t, t_compare, t_allocator>::make_set(
      test_set_helper::arr, test_set_helper::arr_end, t_allocator(4));
    ASSERT_TRUE(result);

    auto st = result.value();
    ASSERT_EQ(t_allocator(4), st.get_allocator());
    ASSERT_EQ(3, st.size());
    ASSERT_EQ(3, ::portable_stl::distance(st.begin(), st.end()));
    EXPECT_EQ(1, *st.begin());
    EXPECT_EQ(2, *::portable_stl::next(st.begin()));
    EXPECT_EQ(3, *::portable_stl::next(st.begin(), 2));
  }

  // bad alloc
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 1;
    t_allocator2 alloc(&stat);

    auto result = ::portable_stl::set<std::int32_t, t_compare, t_allocator2>::make_set(
      test_set_helper::arr, test_set_helper::arr_end, alloc);

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }
}

TEST(set, constructor_iter_iter_comp_alloc) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::set<std::int32_t, t_compare, t_allocator> st(
      test_set_helper::arr, test_set_helper::arr_end, t_compare(3), t_allocator(4));

    ASSERT_EQ(3, st.size());
    ASSERT_EQ(t_compare(3), st.key_comp());
    ASSERT_EQ(t_allocator(4), st.get_allocator());
    ASSERT_EQ(3, ::portable_stl::distance(st.begin(), st.end()));
    EXPECT_EQ(1, *st.begin());
    EXPECT_EQ(2, *::portable_stl::next(st.begin()));
    EXPECT_EQ(3, *::portable_stl::next(st.begin(), 2));
  }

  // bad alloc
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 1;
    t_allocator2 alloc(&stat);

    try {
      ::portable_stl::set<std::int32_t, t_compare, t_allocator2> st(
        test_set_helper::arr, test_set_helper::arr_end, t_compare(3), alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

TEST(set, make_set_iter_iter_comp_alloc) {
  static_cast<void>(test_info_);

  {
    auto result = ::portable_stl::set<std::int32_t, t_compare, t_allocator>::make_set(
      test_set_helper::arr, test_set_helper::arr_end, t_compare(3), t_allocator(4));
    ASSERT_TRUE(result);

    auto st = result.value();

    ASSERT_EQ(3, st.size());
    ASSERT_EQ(t_compare(3), st.key_comp());
    ASSERT_EQ(t_allocator(4), st.get_allocator());
    ASSERT_EQ(3, ::portable_stl::distance(st.begin(), st.end()));
    EXPECT_EQ(1, *st.begin());
    EXPECT_EQ(2, *::portable_stl::next(st.begin()));
    EXPECT_EQ(3, *::portable_stl::next(st.begin(), 2));
  }

  // bad alloc
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 1;
    t_allocator2 alloc(&stat);

    auto result = ::portable_stl::set<std::int32_t, t_compare, t_allocator2>::make_set(
      test_set_helper::arr, test_set_helper::arr_end, t_compare(3), alloc);

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }
}

TEST(set, constructor_copy) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::set<std::int32_t, t_compare, t_allocator> st0(
      test_set_helper::arr, test_set_helper::arr_end, t_compare(3), t_allocator(4));

    ::portable_stl::set<std::int32_t, t_compare, t_allocator> st = st0;

    ASSERT_EQ(3, st.size());
    ASSERT_EQ(t_compare(3), st.key_comp());
    ASSERT_EQ(t_allocator(4), st.get_allocator());
    ASSERT_EQ(3, ::portable_stl::distance(st.begin(), st.end()));
    EXPECT_EQ(1, *st.begin());
    EXPECT_EQ(2, *::portable_stl::next(st.begin()));
    EXPECT_EQ(3, *::portable_stl::next(st.begin(), 2));

    ASSERT_EQ(3, st0.size());
    ASSERT_EQ(t_compare(3), st0.key_comp());
    ASSERT_EQ(t_allocator(4), st0.get_allocator());
    ASSERT_EQ(3, ::portable_stl::distance(st0.begin(), st0.end()));
    EXPECT_EQ(1, *st0.begin());
    EXPECT_EQ(2, *::portable_stl::next(st0.begin()));
    EXPECT_EQ(3, *::portable_stl::next(st0.begin(), 2));
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 4;
    t_allocator2 alloc(&stat);

    ::portable_stl::set<std::int32_t, t_compare, t_allocator2> st0(
      test_set_helper::arr, test_set_helper::arr_end, t_compare(3), alloc);

    try {
      ::portable_stl::set<std::int32_t, t_compare, t_allocator2> mp = st0;
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

TEST(set, constructor_copy_alloc) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::set<std::int32_t, t_compare, t_allocator> st0(
      test_set_helper::arr, test_set_helper::arr_end, t_compare(3), t_allocator(4));

    ::portable_stl::set<std::int32_t, t_compare, t_allocator> st(st0, t_allocator(5));

    ASSERT_EQ(3, st.size());
    ASSERT_EQ(t_allocator(5), st.get_allocator());

    ASSERT_EQ(t_compare(3), st.key_comp());
    ASSERT_EQ(3, ::portable_stl::distance(st.begin(), st.end()));
    EXPECT_EQ(1, *st.begin());
    EXPECT_EQ(2, *::portable_stl::next(st.begin()));
    EXPECT_EQ(3, *::portable_stl::next(st.begin(), 2));

    ASSERT_EQ(3, st0.size());
    ASSERT_EQ(t_compare(3), st0.key_comp());
    ASSERT_EQ(t_allocator(4), st0.get_allocator());
    ASSERT_EQ(3, ::portable_stl::distance(st0.begin(), st0.end()));
    EXPECT_EQ(1, *st0.begin());
    EXPECT_EQ(2, *::portable_stl::next(st0.begin()));
    EXPECT_EQ(3, *::portable_stl::next(st0.begin(), 2));
  }

  // bad allocation
  {
    ::portable_stl::set<std::int32_t, t_compare, t_allocator2> st0(
      test_set_helper::arr, test_set_helper::arr_end, t_compare(3), t_allocator2(4));

    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 1;
    t_allocator2 alloc(&stat);
    try {
      ::portable_stl::set<std::int32_t, t_compare, t_allocator2> st(st0, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

TEST(set, constructor_move) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::set<std::int32_t, t_compare, t_allocator2> st0(
      test_set_helper::arr, test_set_helper::arr_end, t_compare(3), t_allocator2(4));

    ::portable_stl::set<std::int32_t, t_compare, t_allocator2> st = std::move(st0);

    ASSERT_EQ(3, st.size());
    ASSERT_EQ(t_compare(3), st.key_comp());
    ASSERT_EQ(t_allocator2(4), st.get_allocator());
    ASSERT_EQ(3, ::portable_stl::distance(st.begin(), st.end()));
    EXPECT_EQ(1, *st.begin());
    EXPECT_EQ(2, *::portable_stl::next(st.begin()));
    EXPECT_EQ(3, *::portable_stl::next(st.begin(), 2));

    ASSERT_EQ(0, st0.size());
    ASSERT_EQ(0, ::portable_stl::distance(st0.begin(), st0.end()));
    ASSERT_EQ(t_compare(3), st0.key_comp());
    ASSERT_EQ(t_allocator2(test_allocator_helper::test_alloc_base::moved_value), st0.get_allocator());
  }

  // no reallocation - no error
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 3;
    t_allocator2 alloc(&stat);

    ::portable_stl::set<std::int32_t, t_compare, t_allocator2> st0(
      test_set_helper::arr, test_set_helper::arr_end, t_compare(3), alloc);

    ::portable_stl::set<std::int32_t, t_compare, t_allocator2> mp = std::move(st0);
  }
}

TEST(set, constructor_move_alloc) {
  static_cast<void>(test_info_);

  {
    /**
     * @brief Move only alias.
     */
    using t_move_only = test_common_helper::MoveOnly;

    /**
     * @brief Alias.
     */
    using t_allocator3 = ::test_allocator_helper::test_allocator<t_move_only>;

    /**
     * @brief Alias.
     */
    using t_compate2 = test_common_helper::test_less<t_move_only>;

    /**
     * @brief Map alias.
     */
    using t_set = ::portable_stl::set<t_move_only, t_compate2, t_allocator3>;

    /**
     * @brief Alias.
     */
    using t_iter = ::portable_stl::move_iterator<t_move_only *>;

    {
      t_move_only arr1[] = {t_move_only(1),
                            t_move_only(1),
                            t_move_only(1),
                            t_move_only(2),
                            t_move_only(2),
                            t_move_only(2),
                            t_move_only(3),
                            t_move_only(3),
                            t_move_only(3)};
      t_set       st1(t_iter(arr1), t_iter(arr1 + sizeof(arr1) / sizeof(arr1[0])), t_compate2(5), t_allocator3(7));

      t_move_only arr2[] = {t_move_only(1),
                            t_move_only(1),
                            t_move_only(1),
                            t_move_only(2),
                            t_move_only(2),
                            t_move_only(2),
                            t_move_only(3),
                            t_move_only(3),
                            t_move_only(3)};
      t_set       st2(t_iter(arr2), t_iter(arr2 + sizeof(arr2) / sizeof(arr2[0])), t_compate2(5), t_allocator3(7));
      t_set       st3(std::move(st1), t_allocator3(7));

      ASSERT_EQ(st3, st2);
      ASSERT_EQ(st3.get_allocator(), t_allocator3(7));
      ASSERT_EQ(st3.key_comp(), t_compate2(5));
      ASSERT_TRUE(st1.empty());
    }

    // another allocator
    {
      t_move_only arr1[] = {t_move_only(1),
                            t_move_only(1),
                            t_move_only(1),
                            t_move_only(2),
                            t_move_only(2),
                            t_move_only(2),
                            t_move_only(3),
                            t_move_only(3),
                            t_move_only(3)};
      t_set       st1(t_iter(arr1), t_iter(arr1 + sizeof(arr1) / sizeof(arr1[0])), t_compate2(5), t_allocator3(7));

      t_move_only arr2[] = {t_move_only(1),
                            t_move_only(1),
                            t_move_only(1),
                            t_move_only(2),
                            t_move_only(2),
                            t_move_only(2),
                            t_move_only(3),
                            t_move_only(3),
                            t_move_only(3)};
      t_set       st2(t_iter(arr2), t_iter(arr2 + sizeof(arr2) / sizeof(arr2[0])), t_compate2(5), t_allocator3(7));
      t_set       st3(std::move(st1), t_allocator3(6)); // t_allocator3(6) != t_allocator3(7)

      ASSERT_EQ(st3, st2);
      ASSERT_EQ(st3.get_allocator(), t_allocator3(6));
      ASSERT_EQ(st3.key_comp(), t_compate2(5));
      ASSERT_TRUE(st1.empty());
    }
  }

  {
    /**
     * @brief Value alias.
     */
    using t_value = ::test_common_helper::Counter<std::int32_t>;

    /**
     * @brief Alias.
     */
    using t_allocator3 = ::test_allocator_helper::test_allocator<t_value>;

    /**
     * @brief Alias.
     */
    using t_compate2 = test_common_helper::test_less<t_value>;

    /**
     * @brief Map alias.
     */
    using t_set = ::portable_stl::set<t_value, t_compate2, t_allocator3>;

    /**
     * @brief Alias.
     */
    using t_iter = t_value *;

    test_common_helper::Counter_base::gConstructed = 0;

    {
      t_value arr1[]
        = {t_value(1), t_value(1), t_value(1), t_value(2), t_value(2), t_value(2), t_value(3), t_value(3), t_value(3)};
      std::size_t const num = sizeof(arr1) / sizeof(arr1[0]);
      ASSERT_EQ(num, test_common_helper::Counter_base::gConstructed);

      t_set st1(t_iter(arr1), t_iter(arr1 + num), t_compate2(), t_allocator3());
      ASSERT_EQ(num + 3, test_common_helper::Counter_base::gConstructed);

      t_set st2(st1);
      ASSERT_EQ(num + 6, test_common_helper::Counter_base::gConstructed);
      ASSERT_EQ(st2, st1);

      t_set st3(std::move(st1), t_allocator3());
      ASSERT_EQ(st3, st2);
      ASSERT_TRUE(st1.empty());
      ASSERT_GE(test_common_helper::Counter_base::gConstructed, (std::int32_t)(num + 6));
      ASSERT_LE(test_common_helper::Counter_base::gConstructed, (std::int32_t)(num + 6 + st1.size()));

      {
        t_set mp4(std::move(st2), t_allocator3(5));
        ASSERT_GE(test_common_helper::Counter_base::gConstructed, (std::int32_t)(num + 6));
        ASSERT_LE(test_common_helper::Counter_base::gConstructed, (std::int32_t)(num + 6 + st1.size() + st2.size()));
        ASSERT_EQ(mp4, st3);
        ASSERT_TRUE(st2.empty());
      }
      ASSERT_GE(test_common_helper::Counter_base::gConstructed, (std::int32_t)(num + 3));
      ASSERT_LE(test_common_helper::Counter_base::gConstructed, (std::int32_t)(num + 3 + st1.size() + st2.size()));
    }
    ASSERT_EQ(0, test_common_helper::Counter_base::gConstructed);
  }

  // no re allocation - no error
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 3;
    t_allocator2 alloc(&stat);

    ::portable_stl::set<std::int32_t, t_compare, t_allocator2> st0(
      test_set_helper::arr, test_set_helper::arr_end, t_compare(3), alloc);

    ::portable_stl::set<std::int32_t, t_compare, t_allocator2> mp = std::move(st0);
  }
}

TEST(set, constructor_move_noexcept) {
  static_cast<void>(test_info_);

  /**
   * @brief Move only alias.
   */
  using t_move_only = test_common_helper::MoveOnly;

  {
    using t_container = ::portable_stl::set<t_move_only>;
    ASSERT_TRUE(std::is_nothrow_move_constructible<t_container>{});
  }
  {
    using t_container
      = ::portable_stl::set<t_move_only, std::less<t_move_only>, ::portable_stl::allocator<t_move_only>>;
    ASSERT_TRUE(std::is_nothrow_move_constructible<t_container>{});
  }

  // todo(plotitsyn)
  // {
  //   using t_container = ::portable_stl::set<t_move_only, t_move_only, test_set_halper::some_comp<t_move_only>>;

  //   ASSERT_FALSE(std::is_nothrow_move_constructible<t_container>{});
  // }
}

TEST(set, constructor_init_list) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::set<std::int32_t> st{1, 2, 3, 1, 2, 3, 1, 2, 3};

    ASSERT_EQ(3, st.size());
    ASSERT_EQ(3, ::portable_stl::distance(st.begin(), st.end()));
    EXPECT_EQ(1, *st.begin());
    EXPECT_EQ(2, *::portable_stl::next(st.begin()));
    EXPECT_EQ(3, *::portable_stl::next(st.begin(), 2));
  }

  // bad alloc
  {
    t_tree_allocator::m_counter_ok_allocation = 0;

    try {
      ::portable_stl::set<std::int32_t, ::portable_stl::less<std::int32_t>, t_allocator> st{1, 2, 3, 1, 2, 3, 1, 2, 3};
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }

    t_tree_allocator::m_counter_ok_allocation = 10000;
  }
}

TEST(set, constructor_init_list_comp) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::set<std::int32_t, t_compare> st({1, 2, 3, 1, 2, 3, 1, 2, 3}, t_compare(3));

    ASSERT_EQ(3, st.size());
    ASSERT_EQ(t_compare(3), st.key_comp());
    ASSERT_EQ(3, ::portable_stl::distance(st.begin(), st.end()));
    EXPECT_EQ(1, *st.begin());
    EXPECT_EQ(2, *::portable_stl::next(st.begin()));
    EXPECT_EQ(3, *::portable_stl::next(st.begin(), 2));
  }

  // bad alloc
  {
    t_tree_allocator::m_counter_ok_allocation = 0;

    try {
      ::portable_stl::set<std::int32_t, t_compare, t_allocator> st({1, 2, 3, 1, 2, 3, 1, 2, 3}, t_compare(3));
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }

    t_tree_allocator::m_counter_ok_allocation = 10000;
  }
}

TEST(set, constructor_init_list_alloc) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::set<std::int32_t, t_compare, t_allocator> st({1, 2, 3, 1, 2, 3, 1, 2, 3}, t_allocator(4));

    ASSERT_EQ(3, st.size());
    ASSERT_EQ(t_allocator(4), st.get_allocator());
    ASSERT_EQ(3, ::portable_stl::distance(st.begin(), st.end()));
    EXPECT_EQ(1, *st.begin());
    EXPECT_EQ(2, *::portable_stl::next(st.begin()));
    EXPECT_EQ(3, *::portable_stl::next(st.begin(), 2));
  }

  // bad alloc
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 1;
    t_allocator2 alloc(&stat);

    try {
      ::portable_stl::set<std::int32_t, t_compare, t_allocator2> st({1, 2, 3, 1, 2, 3, 1, 2, 3}, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

TEST(set, constructor_init_list_comp_alloc) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::set<std::int32_t, t_compare, t_allocator> st(
      {1, 2, 3, 1, 2, 3, 1, 2, 3}, t_compare(3), t_allocator(4));

    ASSERT_EQ(3, st.size());
    ASSERT_EQ(t_compare(3), st.key_comp());
    ASSERT_EQ(t_allocator(4), st.get_allocator());
    ASSERT_EQ(3, ::portable_stl::distance(st.begin(), st.end()));
    EXPECT_EQ(1, *st.begin());
    EXPECT_EQ(2, *::portable_stl::next(st.begin()));
    EXPECT_EQ(3, *::portable_stl::next(st.begin(), 2));
  }

  // bad alloc
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 1;
    t_allocator2 alloc(&stat);

    try {
      ::portable_stl::set<std::int32_t, t_compare, t_allocator2> st({1, 2, 3, 1, 2, 3, 1, 2, 3}, t_compare(3), alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

namespace test_set_helper {
static std::vector<std::int32_t> ca_allocs;
static std::vector<std::int32_t> ca_deallocs;

template<class t_type> class counting_allocatorT {
public:
  using value_type = t_type;
  std::int32_t m_foo{0};
  counting_allocatorT(std::int32_t value) noexcept : m_foo(value) {
  }

  using propagate_on_container_copy_assignment = ::portable_stl::true_type;

  template<class t_other_type> counting_allocatorT(counting_allocatorT<t_other_type> const &other) noexcept {
    m_foo = other.m_foo;
  }
  template<class t_other_type> bool operator==(counting_allocatorT<t_other_type> const &other) const noexcept {
    return m_foo == other.m_foo;
  }
  template<class t_other_type> bool operator!=(counting_allocatorT<t_other_type> const &other) const noexcept {
    return m_foo != other.m_foo;
  }

  t_type *allocate(::portable_stl::size_t num) const {
    ca_allocs.push_back(m_foo);
    void *const pv = ::malloc(num * sizeof(t_type));
    return static_cast<t_type *>(pv);
  }
  void deallocate(t_type *p, ::portable_stl::size_t) const noexcept {
    ca_deallocs.push_back(m_foo);
    free(p);
  }
};

template<class t_type> class counting_allocatorF {
public:
  using value_type = t_type;
  std::int32_t m_foo{0};
  counting_allocatorF(std::int32_t value) noexcept : m_foo(value) {
  }

  using propagate_on_container_copy_assignment = ::portable_stl::false_type;
  template<class t_other_type> counting_allocatorF(counting_allocatorF<t_other_type> const &other) noexcept {
    m_foo = other.m_foo;
  }
  template<class t_other_type> bool operator==(counting_allocatorF<t_other_type> const &other) const noexcept {
    return m_foo == other.m_foo;
  }
  template<class t_other_type> bool operator!=(counting_allocatorF<t_other_type> const &other) const noexcept {
    return m_foo != other.m_foo;
  }

  t_type *allocate(::portable_stl::size_t num) const {
    ca_allocs.push_back(m_foo);
    void *const pv = ::malloc(num * sizeof(t_type));
    return static_cast<t_type *>(pv);
  }
  void deallocate(t_type *p, ::portable_stl::size_t) const noexcept {
    ca_deallocs.push_back(m_foo);
    free(p);
  }
};

static bool balanced_allocs() {
  std::vector<int> test1, test2;

  std::printf("Allocations = %zu, deallocations = %zu\n", ca_allocs.size(), ca_deallocs.size());
  if (ca_allocs.size() != ca_deallocs.size()) {
    return false;
  }

  test1 = ca_allocs;
  std::sort(test1.begin(), test1.end());
  test2.clear();
  std::unique_copy(test1.begin(), test1.end(), std::back_inserter<std::vector<int>>(test2));
  std::printf("There were %zu different allocators\n", test2.size());

  for (std::vector<int>::const_iterator it = test2.begin(); it != test2.end(); ++it) {
    std::ptrdiff_t const allocs   = std::count(ca_allocs.begin(), ca_allocs.end(), *it);
    std::ptrdiff_t const deallocs = std::count(ca_deallocs.begin(), ca_deallocs.end(), *it);
    std::printf("%d: %td vs %td\n", *it, allocs, deallocs);
    if (allocs != deallocs) {
      return false;
    }
  }

  test1 = ca_allocs;
  std::sort(test1.begin(), test1.end());
  test2.clear();
  std::unique_copy(test1.begin(), test1.end(), std::back_inserter<std::vector<int>>(test2));
  std::printf("There were %zu different (de)allocators\n", test2.size());

  for (std::vector<int>::const_iterator it = ca_deallocs.begin(); it != ca_deallocs.end(); ++it) {
    std::ptrdiff_t const allocs   = std::count(ca_allocs.begin(), ca_allocs.end(), *it);
    std::ptrdiff_t const deallocs = std::count(ca_deallocs.begin(), ca_deallocs.end(), *it);
    std::printf("%d: %td vs %td\n", *it, allocs, deallocs);
    if (allocs != deallocs) {
      return false;
    }
  }

  return true;
}
} // namespace test_set_helper

TEST(set, copy_assign) {
  static_cast<void>(test_info_);

  {
    std::int32_t ar[] = {1, 2, 3, 1, 2, 3, 1, 2, 3};

    ::portable_stl::set<std::int32_t, t_compare, t_allocator2> st0(
      ar, ar + sizeof(ar) / sizeof(ar[0]), t_compare(5), t_allocator2(2));

    ::portable_stl::set<std::int32_t, t_compare, t_allocator2> st(
      ar, ar + sizeof(ar) / sizeof(ar[0]) / 2, t_compare(3), t_allocator2(7));

    st = st0;

    // mp
    ASSERT_EQ(t_allocator2(7), st.get_allocator());
    ASSERT_EQ(t_compare(5), st.key_comp());
    ASSERT_EQ(3, st.size());
    ASSERT_EQ(3, ::portable_stl::distance(st.begin(), st.end()));

    ASSERT_EQ(*st.begin(), 1);
    ASSERT_EQ(*::portable_stl::next(st.begin()), 2);
    ASSERT_EQ(*::portable_stl::next(st.begin(), 2), 3);

    // st0
    ASSERT_EQ(t_allocator2(2), st0.get_allocator());
    ASSERT_EQ(t_compare(5), st0.key_comp());
    ASSERT_EQ(3, st.size());
    ASSERT_EQ(3, ::portable_stl::distance(st.begin(), st.end()));

    ASSERT_EQ(*st.begin(), 1);
    ASSERT_EQ(*::portable_stl::next(st.begin()), 2);
    ASSERT_EQ(*::portable_stl::next(st.begin(), 2), 3);
  }
  {
    std::int32_t ar[] = {1, 2, 3};

    ::portable_stl::set<std::int32_t> st(ar, ar + sizeof(ar) / sizeof(ar[0]));

    ::portable_stl::set<std::int32_t> *ptr = &st;

    st = *ptr;

    ASSERT_EQ(3, st.size());
    ASSERT_TRUE(::portable_stl::equal(st.begin(), st.end(), ar));
  }

  ASSERT_TRUE(test_set_helper::balanced_allocs());
  {
    std::int32_t ar[] = {1, 2, 3, 1, 2, 3, 1, 2, 3};

    using t_allocatorT = test_set_helper::counting_allocatorT<std::int32_t>;

    ::portable_stl::set<std::int32_t, t_compare, t_allocatorT> st0(
      ar, ar + sizeof(ar) / sizeof(ar[0]), t_compare(5), t_allocatorT(1));

    ::portable_stl::set<std::int32_t, t_compare, t_allocatorT> st(
      ar, ar + sizeof(ar) / sizeof(ar[0]) / 2, t_compare(3), t_allocatorT(2));

    st = st0;
    ASSERT_EQ(st.key_comp(), t_compare(5));
    ASSERT_EQ(st.size(), 3);
    ASSERT_EQ(::portable_stl::distance(st.begin(), st.end()), 3);
    ASSERT_EQ(*st.begin(), 1);
    ASSERT_EQ(*::portable_stl::next(st.begin()), 2);
    ASSERT_EQ(*::portable_stl::next(st.begin(), 2), 3);

    ASSERT_EQ(st0.key_comp(), t_compare(5));
    ASSERT_EQ(st0.size(), 3);
    ASSERT_EQ(::portable_stl::distance(st0.begin(), st0.end()), 3);
    ASSERT_EQ(*st0.begin(), 1);
    ASSERT_EQ(*::portable_stl::next(st0.begin()), 2);
    ASSERT_EQ(*::portable_stl::next(st0.begin(), 2), 3);
  }

  ASSERT_TRUE(test_set_helper::balanced_allocs());
  {
    std::int32_t ar[] = {1, 2, 3, 1, 2, 3, 1, 2, 3};

    using t_allocatorF = test_set_helper::counting_allocatorF<std::int32_t>;

    ::portable_stl::set<std::int32_t, t_compare, t_allocatorF> st0(
      ar, ar + sizeof(ar) / sizeof(ar[0]), t_compare(5), t_allocatorF(100));

    ::portable_stl::set<std::int32_t, t_compare, t_allocatorF> st(
      ar, ar + sizeof(ar) / sizeof(ar[0]) / 2, t_compare(3), t_allocatorF(200));

    st = st0;
    ASSERT_EQ(st.key_comp(), t_compare(5));
    ASSERT_EQ(st.size(), 3);
    ASSERT_EQ(::portable_stl::distance(st.begin(), st.end()), 3);
    ASSERT_EQ(*st.begin(), 1);
    ASSERT_EQ(*::portable_stl::next(st.begin()), 2);
    ASSERT_EQ(*::portable_stl::next(st.begin(), 2), 3);

    ASSERT_EQ(st0.key_comp(), t_compare(5));
    ASSERT_EQ(st0.size(), 3);
    ASSERT_EQ(::portable_stl::distance(st0.begin(), st0.end()), 3);
    ASSERT_EQ(*st0.begin(), 1);
    ASSERT_EQ(*::portable_stl::next(st0.begin()), 2);
    ASSERT_EQ(*::portable_stl::next(st0.begin(), 2), 3);
  }
  ASSERT_TRUE(test_set_helper::balanced_allocs());
}

TEST(set, move_assign) {
  static_cast<void>(test_info_);

  /**
   * @brief Move only alias.
   */
  using t_move_only = test_common_helper::MoveOnly;

  using t_compare2      = test_common_helper::test_less<t_move_only>;
  using t_allocator3    = test_allocator_helper::test_allocator<t_move_only>;
  using t_move_iter     = ::portable_stl::move_iterator<t_move_only *>;
  using t_set_move_only = ::portable_stl::set<t_move_only, t_compare2, t_allocator3>;

  t_move_only ar[] = {t_move_only(1),
                      t_move_only(1),
                      t_move_only(1),
                      t_move_only(2),
                      t_move_only(2),
                      t_move_only(2),
                      t_move_only(3),
                      t_move_only(3),
                      t_move_only(3)};

  t_move_only ar2[] = {t_move_only(1),
                       t_move_only(1),
                       t_move_only(1),
                       t_move_only(2),
                       t_move_only(2),
                       t_move_only(2),
                       t_move_only(3),
                       t_move_only(3),
                       t_move_only(3)};

  // same t_allocator3(7)
  {
    t_set_move_only st1(t_move_iter(ar), t_move_iter(ar + sizeof(ar) / sizeof(ar[0])), t_compare2(5), t_allocator3(7));

    t_set_move_only st2(
      t_move_iter(ar2), t_move_iter(ar2 + sizeof(ar2) / sizeof(ar2[0])), t_compare2(5), t_allocator3(7));

    t_set_move_only st3(t_compare2(3), t_allocator3(7));

    st3 = std::move(st1);

    ASSERT_EQ(st3, st2);
    ASSERT_EQ(st3.get_allocator(), t_allocator3(7));
    ASSERT_EQ(st3.key_comp(), t_compare2(5));
    ASSERT_TRUE(st1.empty());
  }

  // diff allocators
  {
    t_set_move_only st1(t_move_iter(ar), t_move_iter(ar + sizeof(ar) / sizeof(ar[0])), t_compare2(5), t_allocator3(7));

    t_set_move_only st2(
      t_move_iter(ar2), t_move_iter(ar2 + sizeof(ar2) / sizeof(ar2[0])), t_compare2(5), t_allocator3(7));

    t_set_move_only st3(t_compare2(3), t_allocator3(5));

    st3 = std::move(st1);

    ASSERT_EQ(st3, st2);
    ASSERT_EQ(st3.get_allocator(), t_allocator3(5));
    ASSERT_EQ(st3.key_comp(), t_compare2(5));
    ASSERT_TRUE(st1.empty());
  }
}

TEST(set, assign_initializer_list) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::set<std::int32_t> st{20};

    st = {1, 2, 3, 1, 2, 3, 1, 2, 3};

    ASSERT_EQ(st.size(), 3);
    ASSERT_EQ(::portable_stl::distance(st.begin(), st.end()), 3);
    ASSERT_EQ(*st.begin(), 1);
    ASSERT_EQ(*::portable_stl::next(st.begin()), 2);
    ASSERT_EQ(*::portable_stl::next(st.begin(), 2), 3);
  }
  {
    test_allocator_helper::test_allocator_statistics alloc_stats;

    using t_set = ::portable_stl::set<std::int32_t, ::portable_stl::less<std::int32_t>, t_allocator2>;
    {
      ASSERT_EQ(0, alloc_stats.m_alloc_count);
      t_set st({1, 2, 3}, ::portable_stl::less<std::int32_t>(), t_allocator2(&alloc_stats));

      ASSERT_EQ(3, alloc_stats.m_alloc_count);

      st = {4, 4, 4, 4};

      ASSERT_EQ(1, alloc_stats.m_alloc_count);
      ASSERT_EQ(1, st.size());
      ASSERT_EQ(4, *st.begin());
    }
    ASSERT_EQ(0, alloc_stats.m_alloc_count);
  }
}
