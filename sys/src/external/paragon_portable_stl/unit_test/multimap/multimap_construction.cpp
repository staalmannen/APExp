// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="multimap_construction.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <algorithm>
#include <portable_stl/map/multimap.h>

#include "../common/counter.h"
#include "../common/move_only.h"
#include "../common/test_allocator.h"
#include "../common/test_compare.h"
#include "portable_stl/iterator/move_iterator.h"

TEST(multimap, constructor_default) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::multimap<std::int32_t, double> mp;
    ASSERT_TRUE(mp.empty());
    ASSERT_EQ(mp.begin(), mp.end());
  }
  {
    ::portable_stl::multimap<std::int32_t, double> mp = {};
    ASSERT_TRUE(mp.empty());
    ASSERT_EQ(mp.begin(), mp.end());
  }
}

namespace test_multimap_helper {

template<class t_type> class some_comp final {
public:
  using value_type = t_type;
  some_comp();
  bool operator()(t_type const &, t_type const &) const {
    return false;
  }
};
} // namespace test_multimap_helper

TEST(multimap, constructor_default_noexcept) {
  static_cast<void>(test_info_);

  {
    using t_container = ::portable_stl::multimap<test_common_helper::MoveOnly, test_common_helper::MoveOnly>;
    ASSERT_TRUE(std::is_nothrow_default_constructible<t_container>{});
  }
  {
    using t_map_value_type = ::portable_stl::tuple<test_common_helper::MoveOnly const, test_common_helper::MoveOnly>;

    using t_container = ::portable_stl::multimap<test_common_helper::MoveOnly,
                                                 test_common_helper::MoveOnly,
                                                 std::less<::test_common_helper::MoveOnly>,
                                                 ::portable_stl::allocator<t_map_value_type>>;
    ASSERT_TRUE(std::is_nothrow_default_constructible<t_container>{});
  }
  {
    using t_container = ::portable_stl::multimap<test_common_helper::MoveOnly,
                                                 test_common_helper::MoveOnly,
                                                 test_multimap_helper::some_comp<test_common_helper::MoveOnly>>;

    ASSERT_FALSE(std::is_nothrow_default_constructible<t_container>{});
  }
}

namespace test_multimap_helper {

class map_rec {
public:
  ::portable_stl::multimap<std::int32_t, map_rec>                 m;
  ::portable_stl::multimap<std::int32_t, map_rec>::iterator       i;
  ::portable_stl::multimap<std::int32_t, map_rec>::const_iterator ci;

  // These reverse_iterator specializations require map_rec to be complete
  // ::portable_stl::multimap<std::int32_t, map_rec>::reverse_iterator       ri;
  // ::portable_stl::multimap<std::int32_t, map_rec>::const_reverse_iterator cri;
};
} // namespace test_multimap_helper

using t_map_value_type = ::portable_stl::tuple<std::int32_t const, double>;

using t_allocator = test_allocator_helper::TestSimpleAllocator<t_map_value_type>;

using t_allocator2 = test_allocator_helper::test_allocator<t_map_value_type>;

using t_tree_allocator = test_allocator_helper::TestSimpleAllocator<
  portable_stl::tree_node<portable_stl::value_type_impl<std::int32_t, double>, void *>>;

using t_tree_allocator_const_key = test_allocator_helper::TestSimpleAllocator<
  portable_stl::tree_node<portable_stl::value_type_impl<std::int32_t const, double>, void *>>;

using t_compare = test_common_helper::test_less<std::int32_t>;

namespace test_multimap_helper {
static t_map_value_type arr[] = {t_map_value_type(1, 1),
                                 t_map_value_type(1, 1.5),
                                 t_map_value_type(1, 2),
                                 t_map_value_type(2, 1),
                                 t_map_value_type(2, 1.5),
                                 t_map_value_type(2, 2),
                                 t_map_value_type(3, 1),
                                 t_map_value_type(3, 1.5),
                                 t_map_value_type(3, 2)};

static size_t const arr_size = sizeof(arr) / sizeof(arr[0]);

static t_map_value_type *const arr_end = &arr[arr_size];
} // namespace test_multimap_helper

TEST(multimap, constructor_compare) {
  static_cast<void>(test_info_);

  ::portable_stl::multimap<std::int32_t, double, t_compare> const mp(t_compare(3));

  ASSERT_TRUE(mp.empty());
  ASSERT_EQ(mp.begin(), mp.end());
  ASSERT_EQ(mp.key_comp(), t_compare(3));
}

TEST(multimap, constructor_allocator) {
  static_cast<void>(test_info_);

  ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator> const mp(t_allocator(4));

  ASSERT_TRUE(mp.empty());
  ASSERT_EQ(mp.begin(), mp.end());
  ASSERT_EQ(mp.get_allocator(), t_allocator(4));
}

TEST(multimap, constructor_compare_allocator) {
  static_cast<void>(test_info_);

  ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator> const mp(t_compare(3), t_allocator(4));

  ASSERT_TRUE(mp.empty());
  ASSERT_EQ(mp.begin(), mp.end());
  ASSERT_EQ(mp.key_comp(), t_compare(3));
  ASSERT_EQ(mp.get_allocator(), t_allocator(4));
}

TEST(multimap, constructor_iter_iter) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::multimap<std::int32_t, double> mp(test_multimap_helper::arr, test_multimap_helper::arr_end);

    ASSERT_EQ(9, mp.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp.begin(), mp.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp.begin(), 8));
  }

  // bad alloc
  {
    t_tree_allocator_const_key::m_counter_ok_allocation = 0;

    try {
      ::portable_stl::multimap<std::int32_t const, double, ::portable_stl::less<std::int32_t>, t_allocator> mp(
        test_multimap_helper::arr, test_multimap_helper::arr_end);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }

    t_tree_allocator_const_key::m_counter_ok_allocation = 10000;
  }
}

TEST(multimap, make_multimap_iter_iter) {
  static_cast<void>(test_info_);

  {
    auto result = ::portable_stl::multimap<std::int32_t, double>::make_multimap(test_multimap_helper::arr,
                                                                                test_multimap_helper::arr_end);
    ASSERT_TRUE(result);

    auto mp = result.value();
    ASSERT_EQ(9, mp.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp.begin(), mp.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp.begin(), 8));
  }

  // bad alloc
  {
    t_tree_allocator_const_key::m_counter_ok_allocation = 0;

    auto result
      = ::portable_stl::multimap<std::int32_t const, double, ::portable_stl::less<std::int32_t>, t_allocator>::
        make_multimap(test_multimap_helper::arr, test_multimap_helper::arr_end);

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    t_tree_allocator_const_key::m_counter_ok_allocation = 10000;
  }
}

TEST(multimap, constructor_iter_iter_comp) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::multimap<std::int32_t, double, t_compare> mp(
      test_multimap_helper::arr, test_multimap_helper::arr_end, t_compare(3));

    ASSERT_EQ(t_compare(3), mp.key_comp());

    ASSERT_EQ(9, mp.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp.begin(), mp.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp.begin(), 8));
  }

  // bad alloc
  {
    t_tree_allocator_const_key::m_counter_ok_allocation = 0;

    try {
      ::portable_stl::multimap<std::int32_t const, double, t_compare, t_allocator> mp(
        test_multimap_helper::arr, test_multimap_helper::arr_end, t_compare(3));
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }

    t_tree_allocator_const_key::m_counter_ok_allocation = 10000;
  }
}

TEST(multimap, make_multimap_iter_iter_comp) {
  static_cast<void>(test_info_);

  {
    auto result = ::portable_stl::multimap<std::int32_t, double, t_compare>::make_multimap(
      test_multimap_helper::arr, test_multimap_helper::arr_end, t_compare(3));
    ASSERT_TRUE(result);

    auto mp = result.value();
    ASSERT_EQ(t_compare(3), mp.key_comp());

    ASSERT_EQ(9, mp.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp.begin(), mp.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp.begin(), 8));
  }

  // bad alloc
  {
    t_tree_allocator_const_key::m_counter_ok_allocation = 0;

    auto result = ::portable_stl::multimap<std::int32_t const, double, t_compare, t_allocator>::make_multimap(
      test_multimap_helper::arr, test_multimap_helper::arr_end, t_compare(3));

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    t_tree_allocator_const_key::m_counter_ok_allocation = 10000;
  }
}

TEST(multimap, constructor_iter_iter_allocator) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator> mp(
      test_multimap_helper::arr, test_multimap_helper::arr_end, t_allocator(4));

    ASSERT_EQ(t_allocator(4), mp.get_allocator());

    ASSERT_EQ(9, mp.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp.begin(), mp.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp.begin(), 8));
  }

  // bad alloc
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 1;
    t_allocator2 alloc(&stat);

    try {
      ::portable_stl::multimap<std::int32_t const, double, t_compare, t_allocator2> mp(
        test_multimap_helper::arr, test_multimap_helper::arr_end, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

TEST(multimap, make_multimap_iter_iter_allocator) {
  static_cast<void>(test_info_);

  {
    auto result = ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator>::make_multimap(
      test_multimap_helper::arr, test_multimap_helper::arr_end, t_allocator(4));
    ASSERT_TRUE(result);

    auto mp = result.value();
    ASSERT_EQ(t_allocator(4), mp.get_allocator());

    ASSERT_EQ(9, mp.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp.begin(), mp.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp.begin(), 8));
  }

  // bad alloc
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 1;
    t_allocator2 alloc(&stat);

    auto result = ::portable_stl::multimap<std::int32_t const, double, t_compare, t_allocator2>::make_multimap(
      test_multimap_helper::arr, test_multimap_helper::arr_end, alloc);

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }
}

TEST(multimap, constructor_iter_iter_comp_alloc) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator> mp(
      test_multimap_helper::arr, test_multimap_helper::arr_end, t_compare(3), t_allocator(4));

    ASSERT_EQ(t_compare(3), mp.key_comp());
    ASSERT_EQ(t_allocator(4), mp.get_allocator());

    ASSERT_EQ(9, mp.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp.begin(), mp.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp.begin(), 8));
  }

  // bad alloc
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 1;
    t_allocator2 alloc(&stat);

    try {
      ::portable_stl::multimap<std::int32_t const, double, t_compare, t_allocator2> mp(
        test_multimap_helper::arr, test_multimap_helper::arr_end, t_compare(3), alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

TEST(multimap, make_multimap_iter_iter_comp_alloc) {
  static_cast<void>(test_info_);

  {
    auto result = ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator>::make_multimap(
      test_multimap_helper::arr, test_multimap_helper::arr_end, t_compare(3), t_allocator(4));
    ASSERT_TRUE(result);

    auto mp = result.value();

    ASSERT_EQ(t_compare(3), mp.key_comp());
    ASSERT_EQ(t_allocator(4), mp.get_allocator());

    ASSERT_EQ(9, mp.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp.begin(), mp.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp.begin(), 8));
  }

  // bad alloc
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 1;
    t_allocator2 alloc(&stat);

    auto result = ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator2>::make_multimap(
      test_multimap_helper::arr, test_multimap_helper::arr_end, t_compare(3), alloc);

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }
}

TEST(multimap, constructor_copy) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator> mp0(
      test_multimap_helper::arr, test_multimap_helper::arr_end, t_compare(3), t_allocator(4));

    ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator> mp = mp0;

    ASSERT_EQ(t_compare(3), mp.key_comp());
    ASSERT_EQ(t_allocator(4), mp.get_allocator());

    ASSERT_EQ(9, mp.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp.begin(), mp.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp.begin(), 8));

    ASSERT_EQ(t_compare(3), mp0.key_comp());
    ASSERT_EQ(t_allocator(4), mp0.get_allocator());

    ASSERT_EQ(9, mp0.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp0.begin(), mp0.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp0.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp0.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp0.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp0.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp0.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp0.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp0.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp0.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp0.begin(), 8));
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 11;
    t_allocator2 alloc(&stat);

    ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator2> mp0(
      test_multimap_helper::arr, test_multimap_helper::arr_end, t_compare(3), alloc);

    try {
      ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator2> mp = mp0;
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

TEST(multimap, constructor_copy_alloc) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator> mp0(
      test_multimap_helper::arr, test_multimap_helper::arr_end, t_compare(3), t_allocator(4));

    ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator> mp(mp0, t_allocator(5));

    ASSERT_EQ(t_allocator(5), mp.get_allocator());
    ASSERT_EQ(t_compare(3), mp.key_comp());

    ASSERT_EQ(9, mp.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp.begin(), mp.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp.begin(), 8));

    ASSERT_EQ(t_compare(3), mp0.key_comp());
    ASSERT_EQ(t_allocator(4), mp0.get_allocator());

    ASSERT_EQ(9, mp0.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp0.begin(), mp0.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp0.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp0.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp0.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp0.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp0.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp0.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp0.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp0.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp0.begin(), 8));
  }

  // bad allocation
  {
    ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator2> mp0(
      test_multimap_helper::arr, test_multimap_helper::arr_end, t_compare(3), t_allocator2(4));

    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 8;
    t_allocator2 alloc(&stat);
    try {
      ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator2> mp(mp0, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

TEST(multimap, constructor_move) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator2> mp0(
      test_multimap_helper::arr, test_multimap_helper::arr_end, t_compare(3), t_allocator2(4));

    ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator2> mp = std::move(mp0);

    ASSERT_EQ(t_compare(3), mp.key_comp());
    ASSERT_EQ(t_allocator2(4), mp.get_allocator());

    ASSERT_EQ(9, mp.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp.begin(), mp.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp.begin(), 8));

    ASSERT_EQ(t_compare(3), mp0.key_comp());
    ASSERT_EQ(t_allocator2(test_allocator_helper::test_alloc_base::moved_value), mp0.get_allocator());

    ASSERT_EQ(0, mp0.size());
    ASSERT_EQ(0, ::portable_stl::distance(mp0.begin(), mp0.end()));
  }

  // no re allocation - no error
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 9 + 1;
    t_allocator2 alloc(&stat);

    ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator2> mp0(
      test_multimap_helper::arr, test_multimap_helper::arr_end, t_compare(3), alloc);

    ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator2> mp = std::move(mp0);
  }
}

TEST(multimap, constructor_move_alloc) {
  static_cast<void>(test_info_);

  {
    /**
     * @brief Move only alias.
     */
    using t_move_only = test_common_helper::MoveOnly;

    /**
     * @brief Alias.
     */
    using t_map_value_type2 = ::portable_stl::tuple<t_move_only, t_move_only>;

    /**
     * @brief Alias.
     */
    using t_map_value_type2_const = ::portable_stl::tuple<t_move_only const, t_move_only>;

    /**
     * @brief Alias.
     */
    using t_allocator3 = ::test_allocator_helper::test_allocator<t_map_value_type2_const>;

    /**
     * @brief Alias.
     */
    using t_compate2 = test_common_helper::test_less<t_move_only>;

    /**
     * @brief Map alias.
     */
    using t_map = ::portable_stl::multimap<t_move_only, t_move_only, t_compate2, t_allocator3>;

    /**
     * @brief Alias.
     */
    using t_iter = ::portable_stl::move_iterator<t_map_value_type2 *>;

    {
      t_map_value_type2 arr1[] = {t_map_value_type2(1, 1),
                                  t_map_value_type2(1, 2),
                                  t_map_value_type2(1, 3),
                                  t_map_value_type2(2, 1),
                                  t_map_value_type2(2, 2),
                                  t_map_value_type2(2, 3),
                                  t_map_value_type2(3, 1),
                                  t_map_value_type2(3, 2),
                                  t_map_value_type2(3, 3)};
      t_map mp1(t_iter(arr1), t_iter(arr1 + sizeof(arr1) / sizeof(arr1[0])), t_compate2(5), t_allocator3(7));

      t_map_value_type2 arr2[] = {t_map_value_type2(1, 1),
                                  t_map_value_type2(1, 2),
                                  t_map_value_type2(1, 3),
                                  t_map_value_type2(2, 1),
                                  t_map_value_type2(2, 2),
                                  t_map_value_type2(2, 3),
                                  t_map_value_type2(3, 1),
                                  t_map_value_type2(3, 2),
                                  t_map_value_type2(3, 3)};
      t_map mp2(t_iter(arr2), t_iter(arr2 + sizeof(arr2) / sizeof(arr2[0])), t_compate2(5), t_allocator3(7));
      t_map mp3(std::move(mp1), t_allocator3(7));

      ASSERT_EQ(mp3, mp2);
      ASSERT_EQ(mp3.get_allocator(), t_allocator3(7));
      ASSERT_EQ(mp3.key_comp(), t_compate2(5));
      ASSERT_TRUE(mp1.empty());
    }

    // another allocator
    {
      t_map_value_type2 arr1[] = {t_map_value_type2(1, 1),
                                  t_map_value_type2(1, 2),
                                  t_map_value_type2(1, 3),
                                  t_map_value_type2(2, 1),
                                  t_map_value_type2(2, 2),
                                  t_map_value_type2(2, 3),
                                  t_map_value_type2(3, 1),
                                  t_map_value_type2(3, 2),
                                  t_map_value_type2(3, 3)};
      t_map mp1(t_iter(arr1), t_iter(arr1 + sizeof(arr1) / sizeof(arr1[0])), t_compate2(5), t_allocator3(7));

      t_map_value_type2 arr2[] = {t_map_value_type2(1, 1),
                                  t_map_value_type2(1, 2),
                                  t_map_value_type2(1, 3),
                                  t_map_value_type2(2, 1),
                                  t_map_value_type2(2, 2),
                                  t_map_value_type2(2, 3),
                                  t_map_value_type2(3, 1),
                                  t_map_value_type2(3, 2),
                                  t_map_value_type2(3, 3)};
      t_map mp2(t_iter(arr2), t_iter(arr2 + sizeof(arr2) / sizeof(arr2[0])), t_compate2(5), t_allocator3(7));
      t_map mp3(std::move(mp1), t_allocator3(6)); // t_allocator3(6) != t_allocator3(7)

      ASSERT_EQ(mp3, mp2);
      ASSERT_EQ(mp3.get_allocator(), t_allocator3(6));
      ASSERT_EQ(mp3.key_comp(), t_compate2(5));
      ASSERT_TRUE(mp1.empty());
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
    using t_map_value_type2 = ::portable_stl::tuple<std::int32_t, t_value>;

    /**
     * @brief Alias.
     */
    using t_map_value_type2_const = ::portable_stl::tuple<std::int32_t const, t_value>;

    /**
     * @brief Alias.
     */
    using t_allocator3 = ::test_allocator_helper::test_allocator<t_map_value_type2_const>;

    /**
     * @brief Alias.
     */
    using t_compate2 = test_common_helper::test_less<std::int32_t>;

    /**
     * @brief Map alias.
     */
    using t_map = ::portable_stl::multimap<std::int32_t, t_value, t_compate2, t_allocator3>;

    /**
     * @brief Alias.
     */
    using t_iter = t_map_value_type2 *;

    test_common_helper::Counter_base::gConstructed = 0;

    {
      t_map_value_type2 arr1[] = {t_map_value_type2(1, 1),
                                  t_map_value_type2(1, 2),
                                  t_map_value_type2(1, 3),
                                  t_map_value_type2(2, 1),
                                  t_map_value_type2(2, 2),
                                  t_map_value_type2(2, 3),
                                  t_map_value_type2(3, 1),
                                  t_map_value_type2(3, 2),
                                  t_map_value_type2(3, 3)};
      std::size_t const num    = sizeof(arr1) / sizeof(arr1[0]);
      ASSERT_EQ(num, test_common_helper::Counter_base::gConstructed);

      t_map mp1(t_iter(arr1), t_iter(arr1 + num), t_compate2(), t_allocator3());
      ASSERT_EQ(num + 9, test_common_helper::Counter_base::gConstructed);

      t_map mp2(mp1);
      ASSERT_EQ(num + 18, test_common_helper::Counter_base::gConstructed);
      ASSERT_EQ(mp2, mp1);

      t_map mp3(std::move(mp1), t_allocator3());
      ASSERT_EQ(mp3, mp2);
      ASSERT_TRUE(mp1.empty());
      ASSERT_GE(test_common_helper::Counter_base::gConstructed, (std::int32_t)(num + 18));
      ASSERT_LE(test_common_helper::Counter_base::gConstructed, (std::int32_t)(num + 18 + mp1.size()));

      {
        t_map mp4(std::move(mp2), t_allocator3(5));
        ASSERT_GE(test_common_helper::Counter_base::gConstructed, (std::int32_t)(num + 18));
        ASSERT_LE(test_common_helper::Counter_base::gConstructed, (std::int32_t)(num + 18 + mp1.size() + mp2.size()));
        ASSERT_EQ(mp4, mp3);
        ASSERT_TRUE(mp2.empty());
      }
      ASSERT_GE(test_common_helper::Counter_base::gConstructed, (std::int32_t)(num + 9));
      ASSERT_LE(test_common_helper::Counter_base::gConstructed, (std::int32_t)(num + 9 + mp1.size() + mp2.size()));
    }
    ASSERT_EQ(0, test_common_helper::Counter_base::gConstructed);
  }

  // no re allocation - no error
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 9;
    t_allocator2 alloc(&stat);

    ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator2> mp0(
      test_multimap_helper::arr, test_multimap_helper::arr_end, t_compare(3), alloc);

    ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator2> mp = std::move(mp0);
  }
}

TEST(multimap, constructor_move_noexcept) {
  static_cast<void>(test_info_);

  /**
   * @brief Move only alias.
   */
  using t_move_only = test_common_helper::MoveOnly;

  {
    using t_container = ::portable_stl::multimap<t_move_only, t_move_only>;
    ASSERT_TRUE(std::is_nothrow_move_constructible<t_container>{});
  }
  {
    using t_map_value_type2 = ::portable_stl::tuple<t_move_only const, t_move_only>;

    using t_container = ::portable_stl::
      multimap<t_move_only, t_move_only, std::less<t_move_only>, ::portable_stl::allocator<t_map_value_type2>>;
    ASSERT_TRUE(std::is_nothrow_move_constructible<t_container>{});
  }

  // todo(plotitsyn)
  // {
  //   using t_container = ::portable_stl::multimap<t_move_only, t_move_only,
  // test_multimap_helper::some_comp<t_move_only>>;

  //   ASSERT_FALSE(std::is_nothrow_move_constructible<t_container>{});
  // }
}

TEST(multimap, constructor_init_list) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::multimap<std::int32_t, double> mp({
      {1,   1},
      {1, 1.5},
      {1,   2},
      {2,   1},
      {2, 1.5},
      {2,   2},
      {3,   1},
      {3, 1.5},
      {3,   2}
    });

    ASSERT_EQ(9, mp.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp.begin(), mp.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp.begin(), 8));
  }

  // bad alloc
  {
    t_tree_allocator::m_counter_ok_allocation = 0;

    try {
      ::portable_stl::multimap<std::int32_t, double, ::portable_stl::less<std::int32_t>, t_allocator> mp({
        {1,   1},
        {1, 1.5},
        {1,   2},
        {2,   1},
        {2, 1.5},
        {2,   2},
        {3,   1},
        {3, 1.5},
        {3,   2}
      });
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }

    t_tree_allocator::m_counter_ok_allocation = 10000;
  }
}

TEST(multimap, constructor_init_list_comp) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::multimap<std::int32_t, double, t_compare> mp(
      {
        {1,   1},
        {1, 1.5},
        {1,   2},
        {2,   1},
        {2, 1.5},
        {2,   2},
        {3,   1},
        {3, 1.5},
        {3,   2}
    },
      t_compare(3));

    ASSERT_EQ(t_compare(3), mp.key_comp());

    ASSERT_EQ(9, mp.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp.begin(), mp.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp.begin(), 8));
  }

  // bad alloc
  {
    t_tree_allocator::m_counter_ok_allocation = 0;

    try {
      ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator> mp(
        {
          {1,   1},
          {1, 1.5},
          {1,   2},
          {2,   1},
          {2, 1.5},
          {2,   2},
          {3,   1},
          {3, 1.5},
          {3,   2}
      },
        t_compare(3));
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }

    t_tree_allocator::m_counter_ok_allocation = 10000;
  }
}

TEST(multimap, constructor_init_list_alloc) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator> mp(
      {
        {1,   1},
        {1, 1.5},
        {1,   2},
        {2,   1},
        {2, 1.5},
        {2,   2},
        {3,   1},
        {3, 1.5},
        {3,   2}
    },
      t_allocator(4));
    ASSERT_EQ(t_allocator(4), mp.get_allocator());

    ASSERT_EQ(9, mp.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp.begin(), mp.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp.begin(), 8));
  }

  // bad alloc
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 1;
    t_allocator2 alloc(&stat);

    try {
      ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator2> mp(
        {
          {1,   1},
          {1, 1.5},
          {1,   2},
          {2,   1},
          {2, 1.5},
          {2,   2},
          {3,   1},
          {3, 1.5},
          {3,   2}
      },
        alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

TEST(multimap, constructor_init_list_comp_alloc) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator> mp(
      {
        {1,   1},
        {1, 1.5},
        {1,   2},
        {2,   1},
        {2, 1.5},
        {2,   2},
        {3,   1},
        {3, 1.5},
        {3,   2}
    },
      t_compare(3),
      t_allocator(4));

    ASSERT_EQ(t_compare(3), mp.key_comp());
    ASSERT_EQ(t_allocator(4), mp.get_allocator());

    ASSERT_EQ(9, mp.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp.begin(), mp.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp.begin(), 8));
  }

  // bad alloc
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 1;
    t_allocator2 alloc(&stat);

    try {
      ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator2> mp(
        {
          {1,   1},
          {1, 1.5},
          {1,   2},
          {2,   1},
          {2, 1.5},
          {2,   2},
          {3,   1},
          {3, 1.5},
          {3,   2}
      },
        t_compare(3),
        alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

namespace test_multimap_helper {
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
  std::vector<int> temp1, temp2;

  std::printf("Allocations = %zu, deallocations = %zu\n", ca_allocs.size(), ca_deallocs.size());
  if (ca_allocs.size() != ca_deallocs.size()) {
    return false;
  }

  temp1 = ca_allocs;
  std::sort(temp1.begin(), temp1.end());
  temp2.clear();
  std::unique_copy(temp1.begin(), temp1.end(), std::back_inserter<std::vector<int>>(temp2));
  std::printf("There were %zu different allocators\n", temp2.size());

  for (std::vector<int>::const_iterator it = temp2.begin(); it != temp2.end(); ++it) {
    std::ptrdiff_t const allocs   = std::count(ca_allocs.begin(), ca_allocs.end(), *it);
    std::ptrdiff_t const deallocs = std::count(ca_deallocs.begin(), ca_deallocs.end(), *it);
    std::printf("%d: %td vs %td\n", *it, allocs, deallocs);
    if (allocs != deallocs) {
      return false;
    }
  }

  temp1 = ca_allocs;
  std::sort(temp1.begin(), temp1.end());
  temp2.clear();
  std::unique_copy(temp1.begin(), temp1.end(), std::back_inserter<std::vector<int>>(temp2));
  std::printf("There were %zu different (de)allocators\n", temp2.size());

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
} // namespace test_multimap_helper

TEST(multimap, copy_assign) {
  static_cast<void>(test_info_);

  {
    t_map_value_type ar[] = {t_map_value_type(1, 1),
                             t_map_value_type(1, 1.5),
                             t_map_value_type(1, 2),
                             t_map_value_type(2, 1),
                             t_map_value_type(2, 1.5),
                             t_map_value_type(2, 2),
                             t_map_value_type(3, 1),
                             t_map_value_type(3, 1.5),
                             t_map_value_type(3, 2)};

    ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator2> mp0(
      ar, ar + sizeof(ar) / sizeof(ar[0]), t_compare(5), t_allocator2(2));
    ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocator2> mp(
      ar, ar + sizeof(ar) / sizeof(ar[0]) / 2, t_compare(3), t_allocator2(7));

    mp = mp0;

    // mp
    ASSERT_EQ(t_allocator2(7), mp.get_allocator());
    ASSERT_EQ(t_compare(5), mp.key_comp());

    ASSERT_EQ(9, mp.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp.begin(), mp.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp.begin(), 8));

    // mp0
    ASSERT_EQ(t_allocator2(2), mp0.get_allocator());
    ASSERT_EQ(t_compare(5), mp0.key_comp());

    ASSERT_EQ(9, mp0.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp0.begin(), mp0.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp0.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp0.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp0.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp0.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp0.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp0.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp0.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp0.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp0.begin(), 8));
  }

  {
    t_map_value_type ar[] = {t_map_value_type(1, 1), t_map_value_type(2, 1), t_map_value_type(3, 1)};

    ::portable_stl::multimap<int, double> mp(ar, ar + sizeof(ar) / sizeof(ar[0]));

    ::portable_stl::multimap<int, double> *ptr = &mp;

    mp = *ptr;

    ASSERT_EQ(3, mp.size());
    ASSERT_TRUE(::portable_stl::equal(mp.begin(), mp.end(), ar));
  }

  ASSERT_TRUE(test_multimap_helper::balanced_allocs());
  {
    t_map_value_type ar[] = {t_map_value_type(1, 1),
                             t_map_value_type(1, 1.5),
                             t_map_value_type(1, 2),
                             t_map_value_type(2, 1),
                             t_map_value_type(2, 1.5),
                             t_map_value_type(2, 2),
                             t_map_value_type(3, 1),
                             t_map_value_type(3, 1.5),
                             t_map_value_type(3, 2)};

    using t_allocatorT = test_multimap_helper::counting_allocatorT<t_map_value_type>;

    ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocatorT> mp0(
      ar, ar + sizeof(ar) / sizeof(ar[0]), t_compare(5), t_allocatorT(1));

    ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocatorT> mp(
      ar, ar + sizeof(ar) / sizeof(ar[0]) / 2, t_compare(3), t_allocatorT(2));

    mp = mp0;
    ASSERT_EQ(mp.key_comp(), t_compare(5));

    ASSERT_EQ(9, mp.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp.begin(), mp.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp.begin(), 8));

    ASSERT_EQ(mp0.key_comp(), t_compare(5));

    ASSERT_EQ(9, mp0.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp0.begin(), mp0.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp0.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp0.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp0.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp0.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp0.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp0.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp0.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp0.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp0.begin(), 8));
  }

  ASSERT_TRUE(test_multimap_helper::balanced_allocs());
  {
    t_map_value_type ar[] = {t_map_value_type(1, 1),
                             t_map_value_type(1, 1.5),
                             t_map_value_type(1, 2),
                             t_map_value_type(2, 1),
                             t_map_value_type(2, 1.5),
                             t_map_value_type(2, 2),
                             t_map_value_type(3, 1),
                             t_map_value_type(3, 1.5),
                             t_map_value_type(3, 2)};

    using t_allocatorF = test_multimap_helper::counting_allocatorF<t_map_value_type>;

    ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocatorF> mp0(
      ar, ar + sizeof(ar) / sizeof(ar[0]), t_compare(5), t_allocatorF(100));

    ::portable_stl::multimap<std::int32_t, double, t_compare, t_allocatorF> mp(
      ar, ar + sizeof(ar) / sizeof(ar[0]) / 2, t_compare(3), t_allocatorF(200));

    mp = mp0;
    ASSERT_EQ(mp.key_comp(), t_compare(5));

    ASSERT_EQ(9, mp.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp.begin(), mp.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp.begin(), 8));

    ASSERT_EQ(mp0.key_comp(), t_compare(5));

    ASSERT_EQ(9, mp0.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp0.begin(), mp0.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp0.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp0.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp0.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp0.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp0.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp0.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp0.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp0.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp0.begin(), 8));
  }
  ASSERT_TRUE(test_multimap_helper::balanced_allocs());
}

TEST(multimap, move_assign) {
  static_cast<void>(test_info_);

  /**
   * @brief Move only alias.
   */
  using t_move_only = test_common_helper::MoveOnly;

  using t_map_value_type2       = ::portable_stl::tuple<t_move_only, t_move_only>;
  using t_map_value_type2_const = ::portable_stl::tuple<t_move_only const, t_move_only>;
  using t_compare2              = test_common_helper::test_less<t_move_only>;
  using t_allocator3            = test_allocator_helper::test_allocator<t_map_value_type2_const>;
  using t_move_iter             = ::portable_stl::move_iterator<t_map_value_type2 *>;
  using t_map_move_only         = ::portable_stl::multimap<t_move_only, t_move_only, t_compare2, t_allocator3>;

  t_map_value_type2 ar[] = {t_map_value_type2(1, 1),
                            t_map_value_type2(1, 2),
                            t_map_value_type2(1, 3),
                            t_map_value_type2(2, 1),
                            t_map_value_type2(2, 2),
                            t_map_value_type2(2, 3),
                            t_map_value_type2(3, 1),
                            t_map_value_type2(3, 2),
                            t_map_value_type2(3, 3)};

  t_map_value_type2 ar2[] = {t_map_value_type2(1, 1),
                             t_map_value_type2(1, 2),
                             t_map_value_type2(1, 3),
                             t_map_value_type2(2, 1),
                             t_map_value_type2(2, 2),
                             t_map_value_type2(2, 3),
                             t_map_value_type2(3, 1),
                             t_map_value_type2(3, 2),
                             t_map_value_type2(3, 3)};

  // same t_allocator3(7)
  {
    t_map_move_only mp1(t_move_iter(ar), t_move_iter(ar + sizeof(ar) / sizeof(ar[0])), t_compare2(5), t_allocator3(7));

    t_map_move_only mp2(
      t_move_iter(ar2), t_move_iter(ar2 + sizeof(ar2) / sizeof(ar2[0])), t_compare2(5), t_allocator3(7));

    t_map_move_only mp3(t_compare2(3), t_allocator3(7));

    mp3 = std::move(mp1);

    ASSERT_EQ(mp3, mp2);
    ASSERT_EQ(mp3.get_allocator(), t_allocator3(7));
    ASSERT_EQ(mp3.key_comp(), t_compare2(5));
    ASSERT_TRUE(mp1.empty());
  }

  // diff allocators
  {
    t_map_move_only mp1(t_move_iter(ar), t_move_iter(ar + sizeof(ar) / sizeof(ar[0])), t_compare2(5), t_allocator3(7));

    t_map_move_only mp2(
      t_move_iter(ar2), t_move_iter(ar2 + sizeof(ar2) / sizeof(ar2[0])), t_compare2(5), t_allocator3(7));

    t_map_move_only mp3(t_compare2(3), t_allocator3(5));

    mp3 = std::move(mp1);

    ASSERT_EQ(mp3, mp2);
    ASSERT_EQ(mp3.get_allocator(), t_allocator3(5));
    ASSERT_EQ(mp3.key_comp(), t_compare2(5));
    ASSERT_TRUE(mp1.empty());
  }
}

TEST(multimap, assign_initializer_list) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::multimap<std::int32_t, double> mp = {
      {20, 1.1}
    };

    mp = {
      {1,   1},
      {1, 1.5},
      {1,   2},
      {2,   1},
      {2, 1.5},
      {2,   2},
      {3,   1},
      {3, 1.5},
      {3,   2}
    };

    ASSERT_EQ(9, mp.size());
    ASSERT_EQ(9, ::portable_stl::distance(mp.begin(), mp.end()));
    EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp.begin(), 0));
    EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp.begin(), 1));
    EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp.begin(), 2));

    EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp.begin(), 3));
    EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp.begin(), 4));
    EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp.begin(), 5));

    EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp.begin(), 6));
    EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp.begin(), 7));
    EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp.begin(), 8));
  }

  {
    test_allocator_helper::test_allocator_statistics alloc_stats;

    using t_allocator3 = test_allocator_helper::test_allocator<::portable_stl::tuple<std::int32_t const, double>>;
    using t_map
      = ::portable_stl::multimap<std::int32_t, double, ::portable_stl::less<std::int32_t>, t_allocator3>;
    {
      ASSERT_EQ(0, alloc_stats.m_alloc_count);
      t_map mp(
        {
          {20, 1}
      },
        ::portable_stl::less<std::int32_t>(),
        t_allocator3(&alloc_stats));

      ASSERT_EQ(1, alloc_stats.m_alloc_count);

      mp = {
        {1,   1},
        {1, 1.5},
        {1,   2},
        {2,   1},
        {2, 1.5},
        {2,   2},
        {3,   1},
        {3, 1.5},
        {3,   2}
      };

      ASSERT_EQ(9, alloc_stats.m_alloc_count);

      ASSERT_EQ(9, mp.size());
      ASSERT_EQ(9, ::portable_stl::distance(mp.begin(), mp.end()));
      EXPECT_EQ(t_map_value_type(1, 1), *::portable_stl::next(mp.begin(), 0));
      EXPECT_EQ(t_map_value_type(1, 1.5), *::portable_stl::next(mp.begin(), 1));
      EXPECT_EQ(t_map_value_type(1, 2), *::portable_stl::next(mp.begin(), 2));

      EXPECT_EQ(t_map_value_type(2, 1), *::portable_stl::next(mp.begin(), 3));
      EXPECT_EQ(t_map_value_type(2, 1.5), *::portable_stl::next(mp.begin(), 4));
      EXPECT_EQ(t_map_value_type(2, 2), *::portable_stl::next(mp.begin(), 5));

      EXPECT_EQ(t_map_value_type(3, 1), *::portable_stl::next(mp.begin(), 6));
      EXPECT_EQ(t_map_value_type(3, 1.5), *::portable_stl::next(mp.begin(), 7));
      EXPECT_EQ(t_map_value_type(3, 2), *::portable_stl::next(mp.begin(), 8));
    }
    ASSERT_EQ(0, alloc_stats.m_alloc_count);
  }
}
