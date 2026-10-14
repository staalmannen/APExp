// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="map_access.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <portable_stl/map/map.h>

#include "../common/move_only.h"
#include "../common/test_allocator.h"
#include "../common/test_compare.h"

using t_map_value_type = ::portable_stl::tuple<std::int32_t const, double>;

namespace test_map_helper {
static t_map_value_type arr[] = {t_map_value_type(1, 1.5),
                                 t_map_value_type(2, 2.5),
                                 t_map_value_type(3, 3.5),
                                 t_map_value_type(4, 4.5),
                                 t_map_value_type(5, 5.5),
                                 t_map_value_type(7, 7.5),
                                 t_map_value_type(8, 8.5)};

static size_t const arr_size = sizeof(arr) / sizeof(arr[0]);

static t_map_value_type *const arr_end = &arr[arr_size];
} // namespace test_map_helper

TEST(map, at) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::map<std::int32_t, double> mp(test_map_helper::arr, test_map_helper::arr_end);

    ASSERT_EQ(mp.size(), 7);
    ASSERT_EQ(mp.at(1), 1.5);

    mp.at(1) = -1.5;

    ASSERT_EQ(mp.at(1), -1.5);
    ASSERT_EQ(mp.at(2), 2.5);
    ASSERT_EQ(mp.at(3), 3.5);
    ASSERT_EQ(mp.at(4), 4.5);
    ASSERT_EQ(mp.at(5), 5.5);

    // out of range
    {
      try {
        static_cast<void>(mp.at(6));
        ASSERT_TRUE(false);
      } catch (::portable_stl::out_of_range<> &) {
      }
    }
    ASSERT_EQ(mp.at(7), 7.5);
    ASSERT_EQ(mp.at(8), 8.5);
    ASSERT_EQ(mp.size(), 7);
  }

  // const
  {
    ::portable_stl::map<std::int32_t, double> const mp(test_map_helper::arr, test_map_helper::arr_end);

    ASSERT_EQ(mp.size(), 7);
    ASSERT_EQ(mp.at(1), 1.5);
    ASSERT_EQ(mp.at(2), 2.5);
    ASSERT_EQ(mp.at(3), 3.5);
    ASSERT_EQ(mp.at(4), 4.5);
    ASSERT_EQ(mp.at(5), 5.5);

    // out of range
    {
      try {
        static_cast<void>(mp.at(6));
        ASSERT_TRUE(false);
      } catch (::portable_stl::out_of_range<> &) {
      }
    }
    ASSERT_EQ(mp.at(7), 7.5);
    ASSERT_EQ(mp.at(8), 8.5);
    ASSERT_EQ(mp.size(), 7);
  }
}

TEST(map, empty) {
  static_cast<void>(test_info_);

  /**
   * @brief Map alias.
   */
  using t_map = ::portable_stl::map<std::int32_t, double>;

  t_map mp;
  ASSERT_TRUE(mp.empty());

  mp.insert(t_map::value_type(1, 1.5));
  ASSERT_FALSE(mp.empty());

  mp.clear();
  ASSERT_TRUE(mp.empty());
}

TEST(map, size) {
  static_cast<void>(test_info_);

  /**
   * @brief Map alias.
   */
  using t_map = ::portable_stl::map<std::int32_t, double>;

  t_map mp;
  EXPECT_EQ(0, mp.size());

  mp.insert(t_map::value_type(2, 1.5));
  EXPECT_EQ(1, mp.size());

  mp.insert(t_map::value_type(1, 1.5));
  EXPECT_EQ(2, mp.size());

  mp.insert(t_map::value_type(3, 1.5));
  EXPECT_EQ(3, mp.size());

  mp.erase(mp.begin());
  EXPECT_EQ(2, mp.size());

  mp.erase(mp.begin());
  EXPECT_EQ(1, mp.size());

  mp.erase(mp.begin());
  EXPECT_EQ(0, mp.size());
}

TEST(map, iterators) {
  static_cast<void>(test_info_);

  t_map_value_type arr[]
    = {t_map_value_type(1, 1),   t_map_value_type(1, 1.5), t_map_value_type(1, 2),   t_map_value_type(2, 1),
       t_map_value_type(2, 1.5), t_map_value_type(2, 2),   t_map_value_type(3, 1),   t_map_value_type(3, 1.5),
       t_map_value_type(3, 2),   t_map_value_type(4, 1),   t_map_value_type(4, 1.5), t_map_value_type(4, 2),
       t_map_value_type(5, 1),   t_map_value_type(5, 1.5), t_map_value_type(5, 2),   t_map_value_type(6, 1),
       t_map_value_type(6, 1.5), t_map_value_type(6, 2),   t_map_value_type(7, 1),   t_map_value_type(7, 1.5),
       t_map_value_type(7, 2),   t_map_value_type(8, 1),   t_map_value_type(8, 1.5), t_map_value_type(8, 2)};

  {
    ::portable_stl::map<std::int32_t, double> mp(arr, arr + (sizeof(arr) / sizeof(arr[0])));

    ASSERT_EQ(mp.size(), ::portable_stl::distance(mp.begin(), mp.end()));
    ASSERT_EQ(mp.size(), ::portable_stl::distance(mp.rbegin(), mp.rend()));

    ::portable_stl::map<std::int32_t, double>::iterator iter = mp.begin();

    ::portable_stl::map<std::int32_t, double>::const_iterator const_begin_iter = iter;

    ASSERT_EQ(iter, const_begin_iter);

    for (std::int32_t j{1}; j <= static_cast<std::int32_t>(mp.size()); ++j, ++iter) {
      ASSERT_EQ(::portable_stl::get<0>(*iter), j);
      ASSERT_EQ(::portable_stl::get<1>(*iter), 1);

      ::portable_stl::get<1>(*iter) = 2.5;
      ASSERT_EQ(::portable_stl::get<1>(*iter), 2.5);
    }
    ASSERT_EQ(iter, mp.end());

    for (std::int32_t j{static_cast<std::int32_t>(mp.size())}; j >= 1; --j) {
      --iter;
      ASSERT_EQ(::portable_stl::get<0>(*iter), j);
      ASSERT_EQ(::portable_stl::get<1>(*iter), 2.5);

      ::portable_stl::get<1>(*iter) = 1;
      ASSERT_EQ(::portable_stl::get<1>(*iter), 1);
    }
    ASSERT_EQ(iter, mp.begin());
  }
  {
    ::portable_stl::map<std::int32_t, double> const mp(arr, arr + (sizeof(arr) / sizeof(arr[0])));

    ASSERT_EQ(static_cast<std::size_t>(::portable_stl::distance(mp.begin(), mp.end())), mp.size());
    ASSERT_EQ(static_cast<std::size_t>(::portable_stl::distance(mp.cbegin(), mp.cend())), mp.size());
    ASSERT_EQ(static_cast<std::size_t>(::portable_stl::distance(mp.rbegin(), mp.rend())), mp.size());
    ASSERT_EQ(static_cast<std::size_t>(::portable_stl::distance(mp.crbegin(), mp.crend())), mp.size());

    ::portable_stl::map<std::int32_t, double>::const_iterator iter;

    iter = mp.begin();
    for (std::int32_t j{1}; static_cast<std::size_t>(j) <= mp.size(); ++j, ++iter) {
      ASSERT_EQ(::portable_stl::get<0>(*iter), j);
      ASSERT_EQ(::portable_stl::get<1>(*iter), 1);
    }
    ASSERT_EQ(iter, mp.end());

    for (auto j = static_cast<std::int32_t>(mp.size()); j >= 1; --j) {
      --iter;
      ASSERT_EQ(::portable_stl::get<0>(*iter), j);
      ASSERT_EQ(::portable_stl::get<1>(*iter), 1);
    }
    ASSERT_EQ(iter, mp.begin());
  }

  // N3644 testing
  {
    using t_map = ::portable_stl::map<std::int32_t, double>;
    t_map::iterator       ii1{}, ii2{};
    t_map::iterator       ii4 = ii1;
    t_map::const_iterator cii{};
    ASSERT_EQ(ii1, ii2);
    ASSERT_EQ(ii1, ii4);

    ASSERT_FALSE(ii1 != ii2);

    ASSERT_EQ(ii1, cii);
    ASSERT_EQ(cii, ii1);
    ASSERT_FALSE(ii1 != cii);
    ASSERT_FALSE(cii != ii1);
  }
}

TEST(map, max_size) {
  static_cast<void>(test_info_);

  using t_allocator = test_allocator_helper::TestSimpleAllocator<t_map_value_type>;

  /**
   * @brief Tree's allocator alias.
   */
  using t_tree_allocator_const_key = test_allocator_helper::TestSimpleAllocator<
    portable_stl::tree_node<portable_stl::value_type_impl<std::int32_t const, double>, void *>>;

  {
    ::portable_stl::map<std::int32_t const, double, ::portable_stl::less<std::int32_t>, t_allocator> mp;

    t_tree_allocator_const_key::m_max_size = 10;
    ASSERT_EQ(10, mp.max_size());

    t_tree_allocator_const_key::m_max_size = 10000;
  }

  {
    using t_map = ::portable_stl::map<std::int32_t, std::int32_t>;

    auto const max_dist = static_cast<t_map::size_type>(::portable_stl::numeric_limits<t_map::difference_type>::max());

    t_map mp;
    ASSERT_LE(mp.max_size(), max_dist);
  }
}

// mapped_type& operator[](const key_type& k);
TEST(map, index_operator_lvalue_key) {
  static_cast<void>(test_info_);

  t_map_value_type arr[] = {t_map_value_type(1, 1.5),
                            t_map_value_type(2, 2.5),
                            t_map_value_type(3, 3.5),
                            t_map_value_type(4, 4.5),
                            t_map_value_type(5, 5.5),
                            t_map_value_type(7, 7.5),
                            t_map_value_type(8, 8.5)};

  {
    ::portable_stl::map<std::int32_t, double> mp(arr, arr + (sizeof(arr) / sizeof(arr[0])));
    ASSERT_EQ(7, mp.size());

    // hit
    std::int32_t const val1{1};
    ASSERT_EQ(1.5, mp[val1]);
    ASSERT_EQ(7, mp.size());

    mp[1] = -1.5;
    ASSERT_EQ(-1.5, mp[val1]);
    ASSERT_EQ(7, mp.size());

    // miss and add
    std::int32_t const val6{6};
    ASSERT_EQ(0, mp[val6]);
    ASSERT_EQ(8, mp.size());

    mp[6] = 6.5;
    ASSERT_EQ(6.5, mp[val6]);
    ASSERT_EQ(8, mp.size());
  }

  // tuple key
  {
    ::portable_stl::map<::portable_stl::tuple<std::int32_t, std::int32_t>, double> mp;
    mp[::portable_stl::make_tuple(2, 3)] = 7;

    ASSERT_EQ(1, mp.size());
  }
}

// mapped_type& operator[](key_type&& k);
TEST(map, index_operator_rvalue_key) {
  static_cast<void>(test_info_);

  /**
   * @brief Move only alias.
   */
  using t_move_only = test_common_helper::MoveOnly;

  ::portable_stl::map<t_move_only, double> mp;
  ASSERT_EQ(0, mp.size());

  // miss and add
  ASSERT_EQ(0.0, mp[1]);
  ASSERT_EQ(1, mp.size());

  mp[1] = -1.5;
  ASSERT_EQ(-1.5, mp[1]);
  ASSERT_EQ(1, mp.size());

  // miss and add
  ASSERT_EQ(0.0, mp[6]);
  ASSERT_EQ(2, mp.size());

  mp[6] = 6.5;
  ASSERT_EQ(6.5, mp[6]);
  ASSERT_EQ(2, mp.size());
}
