// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="map_modify.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <cmath>
#include <portable_stl/map/map.h>
#include <portable_stl/ranges/begin.h>
#include <portable_stl/ranges/end.h>
#include <portable_stl/string/string.h>

#include "../common/counter.h"
#include "../common/default_only.h"
#include "../common/emplaceable.h"
#include "../common/move_only.h"
#include "../common/test_allocator.h"
#include "../common/test_compare.h"
#include "../iterator_helper.h"

using t_map_value_type = ::portable_stl::tuple<std::int32_t const, double>;

using t_allocator2 = test_allocator_helper::test_allocator<t_map_value_type>;

using t_compare = test_common_helper::test_less<std::int32_t>;

using t_map = ::portable_stl::map<std::int32_t, double>;

// [erase]

// size_type erase(const Key& key);
TEST(map, erase_key) {
  static_cast<void>(test_info_);

  t_map_value_type arr[] = {
    t_map_value_type(1, 1.5),
    t_map_value_type(2, 2.5),
    t_map_value_type(3, 3.5),
    t_map_value_type(4, 4.5),
    t_map_value_type(5, 5.5),
    t_map_value_type(6, 6.5),
    t_map_value_type(7, 7.5),
    t_map_value_type(8, 8.5),
  };

  ::portable_stl::map<std::int32_t, double> mp(arr, arr + sizeof(arr) / sizeof(arr[0]));

  ASSERT_EQ(8, mp.size());

  auto removed_cnt = mp.erase(9);
  ASSERT_EQ(0, removed_cnt);
  ASSERT_EQ(8, mp.size());

  ASSERT_EQ(1, ::portable_stl::get<0>(*mp.begin()));
  ASSERT_EQ(1.5, ::portable_stl::get<1>(*mp.begin()));
  ASSERT_EQ(2, ::portable_stl::get<0>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(2.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(3, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(3.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(4, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(4.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(5, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 4)));
  ASSERT_EQ(5.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 4)));
  ASSERT_EQ(6, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 5)));
  ASSERT_EQ(6.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 5)));
  ASSERT_EQ(7, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 6)));
  ASSERT_EQ(7.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 6)));
  ASSERT_EQ(8, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 7)));
  ASSERT_EQ(8.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 7)));

  removed_cnt = mp.erase(4);
  ASSERT_EQ(1, removed_cnt);
  ASSERT_EQ(7, mp.size());

  ASSERT_EQ(1, ::portable_stl::get<0>(*mp.begin()));
  ASSERT_EQ(1.5, ::portable_stl::get<1>(*mp.begin()));
  ASSERT_EQ(2, ::portable_stl::get<0>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(2.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(3, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(3.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(5, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(5.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(6, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 4)));
  ASSERT_EQ(6.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 4)));
  ASSERT_EQ(7, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 5)));
  ASSERT_EQ(7.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 5)));
  ASSERT_EQ(8, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 6)));
  ASSERT_EQ(8.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 6)));

  removed_cnt = mp.erase(1);
  ASSERT_EQ(1, removed_cnt);
  ASSERT_EQ(6, mp.size());

  ASSERT_EQ(2, ::portable_stl::get<0>(*mp.begin()));
  ASSERT_EQ(2.5, ::portable_stl::get<1>(*mp.begin()));
  ASSERT_EQ(3, ::portable_stl::get<0>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(3.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(5, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(5.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(6, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(6.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(7, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 4)));
  ASSERT_EQ(7.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 4)));
  ASSERT_EQ(8, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 5)));
  ASSERT_EQ(8.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 5)));

  removed_cnt = mp.erase(8);
  ASSERT_EQ(1, removed_cnt);
  ASSERT_EQ(5, mp.size());

  ASSERT_EQ(2, ::portable_stl::get<0>(*mp.begin()));
  ASSERT_EQ(2.5, ::portable_stl::get<1>(*mp.begin()));
  ASSERT_EQ(3, ::portable_stl::get<0>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(3.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(5, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(5.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(6, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(6.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(7, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 4)));
  ASSERT_EQ(7.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 4)));

  removed_cnt = mp.erase(3);
  ASSERT_EQ(1, removed_cnt);
  ASSERT_EQ(4, mp.size());

  ASSERT_EQ(2, ::portable_stl::get<0>(*mp.begin()));
  ASSERT_EQ(2.5, ::portable_stl::get<1>(*mp.begin()));
  ASSERT_EQ(5, ::portable_stl::get<0>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(5.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(6, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(6.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(7, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(7.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 3)));

  removed_cnt = mp.erase(6);
  ASSERT_EQ(1, removed_cnt);
  ASSERT_EQ(3, mp.size());

  ASSERT_EQ(2, ::portable_stl::get<0>(*mp.begin()));
  ASSERT_EQ(2.5, ::portable_stl::get<1>(*mp.begin()));
  ASSERT_EQ(5, ::portable_stl::get<0>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(5.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(7, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(7.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)));

  removed_cnt = mp.erase(7);
  ASSERT_EQ(1, removed_cnt);
  ASSERT_EQ(2, mp.size());

  ASSERT_EQ(2, ::portable_stl::get<0>(*mp.begin()));
  ASSERT_EQ(2.5, ::portable_stl::get<1>(*mp.begin()));
  ASSERT_EQ(5, ::portable_stl::get<0>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(5.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin())));

  removed_cnt = mp.erase(2);
  ASSERT_EQ(1, removed_cnt);
  ASSERT_EQ(1, mp.size());

  ASSERT_EQ(5, ::portable_stl::get<0>(*mp.begin()));
  ASSERT_EQ(5.5, ::portable_stl::get<1>(*mp.begin()));

  removed_cnt = mp.erase(5);
  ASSERT_EQ(1, removed_cnt);
  ASSERT_EQ(0, mp.size());
}

// iterator erase(const_iterator position);
TEST(map, erase_position) {
  static_cast<void>(test_info_);

  t_map_value_type arr[] = {
    t_map_value_type(1, 1.5),
    t_map_value_type(2, 2.5),
    t_map_value_type(3, 3.5),
    t_map_value_type(4, 4.5),
    t_map_value_type(5, 5.5),
    t_map_value_type(6, 6.5),
    t_map_value_type(7, 7.5),
    t_map_value_type(8, 8.5),
  };

  ::portable_stl::map<std::int32_t, double> mp(arr, arr + sizeof(arr) / sizeof(arr[0]));

  ASSERT_EQ(8, mp.size());

  auto iter = mp.erase(::portable_stl::next(mp.cbegin(), 3));
  ASSERT_EQ(iter, ::portable_stl::next(mp.begin(), 3));
  ASSERT_EQ(7, mp.size());

  ASSERT_EQ(1, ::portable_stl::get<0>(*mp.begin()));
  ASSERT_EQ(1.5, ::portable_stl::get<1>(*mp.begin()));
  ASSERT_EQ(2, ::portable_stl::get<0>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(2.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(3, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(3.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(5, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(5.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(6, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 4)));
  ASSERT_EQ(6.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 4)));
  ASSERT_EQ(7, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 5)));
  ASSERT_EQ(7.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 5)));
  ASSERT_EQ(8, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 6)));
  ASSERT_EQ(8.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 6)));

  iter = mp.erase(::portable_stl::next(mp.cbegin(), 0));
  ASSERT_EQ(iter, mp.begin());
  ASSERT_EQ(6, mp.size());

  ASSERT_EQ(2, ::portable_stl::get<0>(*mp.begin()));
  ASSERT_EQ(2.5, ::portable_stl::get<1>(*mp.begin()));
  ASSERT_EQ(3, ::portable_stl::get<0>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(3.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(5, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(5.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(6, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(6.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(7, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 4)));
  ASSERT_EQ(7.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 4)));
  ASSERT_EQ(8, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 5)));
  ASSERT_EQ(8.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 5)));

  iter = mp.erase(::portable_stl::next(mp.cbegin(), 5));
  ASSERT_EQ(iter, mp.end());
  ASSERT_EQ(5, mp.size());

  ASSERT_EQ(2, ::portable_stl::get<0>(*mp.begin()));
  ASSERT_EQ(2.5, ::portable_stl::get<1>(*mp.begin()));
  ASSERT_EQ(3, ::portable_stl::get<0>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(3.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(5, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(5.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(6, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(6.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(7, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 4)));
  ASSERT_EQ(7.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 4)));

  iter = mp.erase(::portable_stl::next(mp.begin(), 1));
  ASSERT_EQ(iter, ::portable_stl::next(mp.begin()));
  ASSERT_EQ(4, mp.size());

  ASSERT_EQ(2, ::portable_stl::get<0>(*mp.begin()));
  ASSERT_EQ(2.5, ::portable_stl::get<1>(*mp.begin()));
  ASSERT_EQ(5, ::portable_stl::get<0>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(5.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(6, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(6.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(7, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(7.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 3)));

  iter = mp.erase(::portable_stl::next(mp.begin(), 2));
  ASSERT_EQ(iter, ::portable_stl::next(mp.begin(), 2));
  ASSERT_EQ(3, mp.size());

  ASSERT_EQ(2, ::portable_stl::get<0>(*mp.begin()));
  ASSERT_EQ(2.5, ::portable_stl::get<1>(*mp.begin()));
  ASSERT_EQ(5, ::portable_stl::get<0>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(5.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(7, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(7.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)));

  iter = mp.erase(::portable_stl::next(mp.cbegin(), 2));
  ASSERT_EQ(iter, ::portable_stl::next(mp.begin(), 2));
  ASSERT_EQ(2, mp.size());

  ASSERT_EQ(2, ::portable_stl::get<0>(*mp.begin()));
  ASSERT_EQ(2.5, ::portable_stl::get<1>(*mp.begin()));
  ASSERT_EQ(5, ::portable_stl::get<0>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(5.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin())));

  iter = mp.erase(::portable_stl::next(mp.cbegin(), 0));
  ASSERT_EQ(iter, ::portable_stl::next(mp.begin(), 0));
  ASSERT_EQ(1, mp.size());

  ASSERT_EQ(5, ::portable_stl::get<0>(*mp.begin()));
  ASSERT_EQ(5.5, ::portable_stl::get<1>(*mp.begin()));

  iter = mp.erase(mp.cbegin());
  ASSERT_EQ(iter, mp.cbegin());
  ASSERT_EQ(iter, mp.end());
  ASSERT_EQ(0, mp.size());
}

// iterator erase(const_iterator first, const_iterator last);
TEST(map, erase_iter_iter) {
  static_cast<void>(test_info_);

  t_map_value_type arr[] = {
    t_map_value_type(1, 1.5),
    t_map_value_type(2, 2.5),
    t_map_value_type(3, 3.5),
    t_map_value_type(4, 4.5),
    t_map_value_type(5, 5.5),
    t_map_value_type(6, 6.5),
    t_map_value_type(7, 7.5),
    t_map_value_type(8, 8.5),
  };

  ::portable_stl::map<std::int32_t, double> mp(arr, arr + sizeof(arr) / sizeof(arr[0]));

  ASSERT_EQ(8, mp.size());

  auto iter = mp.erase(mp.begin(), mp.begin());
  ASSERT_EQ(iter, mp.begin());
  ASSERT_EQ(8, mp.size());

  ASSERT_EQ(1, ::portable_stl::get<0>(*mp.begin()));
  ASSERT_EQ(1.5, ::portable_stl::get<1>(*mp.begin()));
  ASSERT_EQ(2, ::portable_stl::get<0>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(2.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(3, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(3.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(4, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(4.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(5, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 4)));
  ASSERT_EQ(5.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 4)));
  ASSERT_EQ(6, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 5)));
  ASSERT_EQ(6.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 5)));
  ASSERT_EQ(7, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 6)));
  ASSERT_EQ(7.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 6)));
  ASSERT_EQ(8, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 7)));
  ASSERT_EQ(8.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 7)));

  iter = mp.erase(mp.cbegin(), ::portable_stl::next(mp.cbegin(), 2));
  ASSERT_EQ(iter, mp.begin());
  ASSERT_EQ(6, mp.size());

  ASSERT_EQ(3, ::portable_stl::get<0>(*mp.begin()));
  ASSERT_EQ(3.5, ::portable_stl::get<1>(*mp.begin()));
  ASSERT_EQ(4, ::portable_stl::get<0>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(4.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(5, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(5.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(6, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(6.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(7, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 4)));
  ASSERT_EQ(7.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 4)));
  ASSERT_EQ(8, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 5)));
  ASSERT_EQ(8.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 5)));

  iter = mp.erase(::portable_stl::next(mp.cbegin(), 2), ::portable_stl::next(mp.cbegin(), 6));
  ASSERT_EQ(iter, ::portable_stl::next(mp.begin(), 2));
  ASSERT_EQ(2, mp.size());

  ASSERT_EQ(3, ::portable_stl::get<0>(*mp.begin()));
  ASSERT_EQ(3.5, ::portable_stl::get<1>(*mp.begin()));
  ASSERT_EQ(4, ::portable_stl::get<0>(*::portable_stl::next(mp.begin())));
  ASSERT_EQ(4.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin())));

  iter = mp.erase(mp.cbegin(), mp.cend());
  ASSERT_EQ(iter, mp.begin());
  ASSERT_EQ(iter, mp.end());
  ASSERT_EQ(0, mp.size());
}

namespace test_map_helper {
template<class t_map, class t_key_type_iter>
void test_extract_key(t_map &mp, t_key_type_iter first, t_key_type_iter last) {
  std::size_t sz{mp.size()};
  ASSERT_EQ(sz, static_cast<std::size_t>(::portable_stl::distance(first, last)));

  for (t_key_type_iter copy_iter{first}; copy_iter != last; ++copy_iter) {
    typename t_map::node_type t = mp.extract(*copy_iter);
    ASSERT_FALSE(t.empty());
    --sz;
    ASSERT_EQ(t.key(), *copy_iter);
    t.key() = *first; // We should be able to mutate key.
    ASSERT_EQ(t.key(), *first);
    ASSERT_EQ(t.get_allocator(), mp.get_allocator());
    ASSERT_EQ(sz, mp.size());
  }

  ASSERT_EQ(0, mp.size());

  for (t_key_type_iter copy_iter = first; copy_iter != last; ++copy_iter) {
    typename t_map::node_type t = mp.extract(*copy_iter);
    ASSERT_TRUE(t.empty());
  }
}

template<class t_map> void test_extract_iter(t_map &mp) {
  auto sz = mp.size();

  auto some_key = ::portable_stl::get<0>(*mp.cbegin());

  for (auto iter = mp.cbegin(); iter != mp.cend();) {
    auto                      key_value = ::portable_stl::get<0>(*iter);
    typename t_map::node_type t         = mp.extract(iter++);
    --sz;

    ASSERT_EQ(t.key(), key_value);
    t.key() = some_key;
    ASSERT_EQ(t.key(), some_key);
    ASSERT_EQ(t.get_allocator(), mp.get_allocator());
    ASSERT_EQ(sz, mp.size());
  }

  ASSERT_EQ(mp.size(), 0);
}

} // namespace test_map_helper

// node_type extract(key_type const&);
TEST(map, extract_key) {
  static_cast<void>(test_info_);

  // using t_map_value_type2 = ::portable_stl::tuple<std::int32_t const, std::int32_t>;

  {
    ::portable_stl::map<std::int32_t, std::int32_t> mp({
      {1, 1},
      {2, 2},
      {3, 3},
      {4, 4},
      {5, 5},
      {6, 6}
    });

    std::int32_t keys[] = {1, 2, 3, 4, 5, 6};
    test_map_helper::test_extract_key(mp, ::portable_stl::ranges::begin(keys), ::portable_stl::ranges::end(keys));
  }

  {
    ::portable_stl::map<test_common_helper::Counter<std::int32_t>, test_common_helper::Counter<std::int32_t>> mp({
      {1, 1},
      {2, 2},
      {3, 3},
      {4, 4},
      {5, 5},
      {6, 6}
    });
    {
      test_common_helper::Counter<std::int32_t> keys[] = {1, 2, 3, 4, 5, 6};
      ASSERT_EQ(12 + 6, test_common_helper::Counter_base::gConstructed);

      test_map_helper::test_extract_key(mp, std::begin(keys), std::end(keys));
    }
    assert(test_common_helper::Counter_base::gConstructed == 0);
  }
}

// node_type extract(const_iterator);
TEST(map, extract_iter) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::map<std::int32_t, std::int32_t> mp({
      {1, 1},
      {2, 2},
      {3, 3},
      {4, 4},
      {5, 5},
      {6, 6}
    });
    test_map_helper::test_extract_iter(mp);
  }

  {
    ::portable_stl::map<test_common_helper::Counter<std::int32_t>, test_common_helper::Counter<std::int32_t>> mp({
      {1, 1},
      {2, 2},
      {3, 3},
      {4, 4},
      {5, 5},
      {6, 6}
    });

    ASSERT_EQ(test_common_helper::Counter_base::gConstructed, 12);

    test_map_helper::test_extract_iter(mp);

    ASSERT_EQ(test_common_helper::Counter_base::gConstructed, 0);
  }
}

namespace test_map_helper {
class t_move_only {
  t_move_only(t_move_only const &);
  t_move_only &operator=(t_move_only const &);

  std::int32_t m_int;
  double       m_double;

public:
  t_move_only() : m_int(0), m_double(0) {
  }
  t_move_only(std::int32_t i, double d) : m_int(i), m_double(d) {
  }
  t_move_only(t_move_only &&x) : m_int(x.m_int), m_double(x.m_double) {
    x.m_int    = -1;
    x.m_double = -1;
  }
  t_move_only &operator=(t_move_only &&x) {
    m_int      = x.m_int;
    x.m_int    = -1;
    m_double   = x.m_double;
    x.m_double = -1;
    return *this;
  }

  bool operator==(t_move_only const &x) const {
    return (m_int == x.m_int) && (std::fabs(m_double - x.m_double) < std::numeric_limits<double>::epsilon());
  }
  bool operator<(t_move_only const &x) const {
    return (m_int < x.m_int) || ((m_int == x.m_int) && (m_double < x.m_double));
  }

  int get() const {
    return m_int;
  }
  bool moved() const {
    return m_int == -1;
  }
};
} // namespace test_map_helper

/**
 * @brief Alias.
 */
using t_move_only = test_map_helper::t_move_only;

// template <class M> pair<iterator, bool> insert_or_assign(const key_type& k, M&& obj);
TEST(map, insert_or_assign_lvalue_key) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::map<std::int32_t, t_move_only> mp;

    for (std::int32_t i{0}; i < 20; i += 2) {
      mp.emplace(i, t_move_only(i, static_cast<double>(i)));
    }
    ASSERT_EQ(mp.size(), 10);

    for (std::int32_t i = 0; i < 20; i += 2) {
      t_move_only mv(i + 1, i + 1);
      auto        result = mp.insert_or_assign(i, std::move(mv));
      ASSERT_TRUE(result);
      auto iter_bool = result.value();

      ASSERT_EQ(mp.size(), 10);
      ASSERT_FALSE(::portable_stl::get<1>(iter_bool));                                    // was not inserted
      ASSERT_TRUE(mv.moved());                                                            // was moved from
      ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::get<0>(iter_bool)), i);           // key
      ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::get<0>(iter_bool)).get(), i + 1); // value
    }
    {
      t_move_only mv1(5, 5.0);
      auto        result = mp.insert_or_assign(-1, std::move(mv1));
      ASSERT_TRUE(result);
      auto iter_bool = result.value();

      ASSERT_EQ(mp.size(), 11);
      ASSERT_TRUE(::portable_stl::get<1>(iter_bool));                                 // was inserted
      ASSERT_TRUE(mv1.moved());                                                       // was moved from
      ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::get<0>(iter_bool)), -1);      // key
      ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::get<0>(iter_bool)).get(), 5); // value
    }
    {
      t_move_only mv2(9, 9.0);
      auto        result = mp.insert_or_assign(3, std::move(mv2));
      ASSERT_TRUE(result);
      auto iter_bool = result.value();

      ASSERT_EQ(mp.size(), 12);
      ASSERT_TRUE(::portable_stl::get<1>(iter_bool));                                 // was inserted
      ASSERT_TRUE(mv2.moved());                                                       // was moved from
      ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::get<0>(iter_bool)), 3);       // key
      ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::get<0>(iter_bool)).get(), 9); // value
    }
    {
      t_move_only mv3(-1, 5.0);
      auto        result = mp.insert_or_assign(117, std::move(mv3));
      ASSERT_TRUE(result);
      auto iter_bool = result.value();

      ASSERT_EQ(mp.size(), 13);
      ASSERT_TRUE(::portable_stl::get<1>(iter_bool));                                  // was inserted
      ASSERT_TRUE(mv3.moved());                                                        // was moved from
      ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::get<0>(iter_bool)), 117);      // key
      ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::get<0>(iter_bool)).get(), -1); // value
    }
  }

  std::int32_t key_val = 1;
  {
    ::portable_stl::map<std::int32_t, t_move_only> mp;
    auto                                           result = mp.insert_or_assign(key_val, t_move_only(1, 2));
    ASSERT_TRUE(result);

    auto iter_bool = result.value();
    ASSERT_TRUE(::portable_stl::get<1>(iter_bool));
    ASSERT_EQ(1, mp.size());
  }

  // bad allocation
  {
    using t_map_value_type2 = ::portable_stl::tuple<std::int32_t const, t_move_only>;

    using t_allocator3 = test_allocator_helper::test_allocator<t_map_value_type2>;

    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    t_allocator3 alloc(&stat);

    ::portable_stl::map<std::int32_t, t_move_only, ::portable_stl::less<std::int32_t>, t_allocator3> mp(alloc);

    auto result = mp.insert_or_assign(key_val, t_move_only(1, 2));

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }
}

// template <class M> pair<iterator, bool> insert_or_assign(key_type&& k, M&& obj);
TEST(map, insert_or_assign_rvalue_key) {
  static_cast<void>(test_info_);

  ::portable_stl::map<t_move_only, t_move_only> mp;

  for (std::int32_t i{0}; i < 20; i += 2) {
    mp.emplace(t_move_only(i, static_cast<double>(i)), t_move_only(i + 1, static_cast<double>(i + 1)));
  }
  ASSERT_EQ(mp.size(), 10);

  {
    t_move_only mvkey1(2, 2.0);
    t_move_only mv1(4, 4.0);
    auto        result = mp.insert_or_assign(std::move(mvkey1), std::move(mv1));
    ASSERT_TRUE(result);
    auto iter_bool = result.value();

    ASSERT_EQ(mp.size(), 10);
    ASSERT_FALSE(::portable_stl::get<1>(iter_bool));                                // was not inserted
    ASSERT_FALSE(mvkey1.moved());                                                   // was not moved from
    ASSERT_TRUE(mv1.moved());                                                       // was moved from
    ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::get<0>(iter_bool)), mvkey1);  // key
    ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::get<0>(iter_bool)).get(), 4); // value
  }

  {
    t_move_only mvkey2(3, 3.0);
    t_move_only mv2(5, 5.0);
    auto        result = mp.try_emplace(std::move(mvkey2), std::move(mv2));
    ASSERT_TRUE(result);
    auto iter_bool = result.value();

    ASSERT_EQ(mp.size(), 11);
    ASSERT_TRUE(::portable_stl::get<1>(iter_bool));                                 // was inserted
    ASSERT_TRUE(mv2.moved());                                                       // was moved from
    ASSERT_TRUE(mvkey2.moved());                                                    // was moved from
    ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::get<0>(iter_bool)).get(), 3); // key
    ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::get<0>(iter_bool)).get(), 5); // value
  }
}

// template <class M> iterator insert_or_assign(const_iterator hint, const key_type& k, M&& obj);
TEST(map, insert_or_assign_pos_lvalue_key) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::map<std::int32_t, t_move_only> mp;

    for (std::int32_t i{0}; i < 20; i += 2) {
      mp.emplace(i, t_move_only(i, static_cast<double>(i)));
    }
    ASSERT_EQ(mp.size(), 10);
    auto it = mp.find(2);

    {
      t_move_only        mv1(3, 3.0);
      std::int32_t const key_val{2};
      auto               result = mp.insert_or_assign(it, key_val, std::move(mv1));
      ASSERT_TRUE(result);
      auto iter = result.value();

      ASSERT_EQ(mp.size(), 10);
      ASSERT_TRUE(mv1.moved());                          // was moved from
      ASSERT_EQ(::portable_stl::get<0>(*iter), 2);       // key
      ASSERT_EQ(::portable_stl::get<1>(*iter).get(), 3); // value
    }
    {
      t_move_only        mv2(5, 5.0);
      std::int32_t const key_val{3};
      auto               result = mp.insert_or_assign(it, key_val, std::move(mv2));
      ASSERT_TRUE(result);
      auto iter = result.value();

      ASSERT_EQ(mp.size(), 11);
      ASSERT_TRUE(mv2.moved());                          // was moved from
      ASSERT_EQ(::portable_stl::get<0>(*iter), 3);       // key
      ASSERT_EQ(::portable_stl::get<1>(*iter).get(), 5); // value
    }
    // wrong hint: begin()
    {
      t_move_only mv3(7, 7.0);
      auto        result = mp.insert_or_assign(mp.begin(), 4, std::move(mv3));
      ASSERT_TRUE(result);
      auto iter = result.value();

      ASSERT_EQ(mp.size(), 11);
      ASSERT_TRUE(mv3.moved());                          // was moved from
      ASSERT_EQ(::portable_stl::get<0>(*iter), 4);       // key
      ASSERT_EQ(::portable_stl::get<1>(*iter).get(), 7); // value
    }
    {
      t_move_only mv4(9, 9.0);
      auto        result = mp.insert_or_assign(mp.begin(), 5, std::move(mv4));
      ASSERT_TRUE(result);
      auto iter = result.value();

      ASSERT_EQ(mp.size(), 12);
      ASSERT_TRUE(mv4.moved());                          // was moved from
      ASSERT_EQ(::portable_stl::get<0>(*iter), 5);       // key
      ASSERT_EQ(::portable_stl::get<1>(*iter).get(), 9); // value
    }
    // wrong hint: end()
    {
      t_move_only mv5(11, 11.0);
      auto        result = mp.insert_or_assign(mp.end(), 6, std::move(mv5));
      ASSERT_TRUE(result);
      auto iter = result.value();

      ASSERT_EQ(mp.size(), 12);
      ASSERT_TRUE(mv5.moved());                           // was moved from
      ASSERT_EQ(::portable_stl::get<0>(*iter), 6);        // key
      ASSERT_EQ(::portable_stl::get<1>(*iter).get(), 11); // value
    }
    {
      t_move_only mv6(13, 13.0);
      auto        result = mp.insert_or_assign(mp.end(), 7, std::move(mv6));
      ASSERT_TRUE(result);
      auto iter = result.value();

      ASSERT_EQ(mp.size(), 13);
      ASSERT_TRUE(mv6.moved());                           // was moved from
      ASSERT_EQ(::portable_stl::get<0>(*iter), 7);        // key
      ASSERT_EQ(::portable_stl::get<1>(*iter).get(), 13); // value
    }
    // wrong hint: third element
    {
      t_move_only mv7(15, 15.0);
      auto        result = mp.insert_or_assign(::portable_stl::next(mp.begin(), 2), 8, std::move(mv7));
      ASSERT_TRUE(result);
      auto iter = result.value();

      ASSERT_EQ(mp.size(), 13);
      ASSERT_TRUE(mv7.moved());                           // was moved from
      ASSERT_EQ(::portable_stl::get<0>(*iter), 8);        // key
      ASSERT_EQ(::portable_stl::get<1>(*iter).get(), 15); // value
    }
    {
      t_move_only mv8(17, 17.0);
      auto        result = mp.insert_or_assign(::portable_stl::next(mp.begin(), 2), 9, std::move(mv8));
      ASSERT_TRUE(result);
      auto iter = result.value();

      ASSERT_EQ(mp.size(), 14);
      ASSERT_TRUE(mv8.moved());                           // was moved from
      ASSERT_EQ(::portable_stl::get<0>(*iter), 9);        // key
      ASSERT_EQ(::portable_stl::get<1>(*iter).get(), 17); // value
    }
  }

  // bad allocation

  {
    std::int32_t key_val = 1;

    using t_map_value_type2 = ::portable_stl::tuple<std::int32_t const, t_move_only>;

    using t_allocator3 = test_allocator_helper::test_allocator<t_map_value_type2>;

    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    t_allocator3 alloc(&stat);

    ::portable_stl::map<std::int32_t, t_move_only, ::portable_stl::less<std::int32_t>, t_allocator3> mp(alloc);

    auto result = mp.insert_or_assign(mp.begin(), key_val, t_move_only(1, 2));

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }
}

// template <class M> iterator insert_or_assign(const_iterator hint, key_type&& k, M&& obj);
TEST(map, insert_or_assign_pos_rvalue_key) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::map<t_move_only, t_move_only> mp;

    for (std::int32_t i{0}; i < 20; i += 2) {
      mp.emplace(t_move_only(i, static_cast<double>(i)), t_move_only(i + 1, static_cast<double>(i + 1)));
    }
    ASSERT_EQ(mp.size(), 10);

    auto it = ::portable_stl::next(mp.cbegin());

    {
      t_move_only mvkey1(2, 2.0);
      t_move_only mv1(4, 4.0);
      auto        result = mp.insert_or_assign(it, std::move(mvkey1), std::move(mv1));
      ASSERT_TRUE(result);
      auto iter = result.value();

      ASSERT_EQ(mp.size(), 10);
      ASSERT_TRUE(mv1.moved());                          // was moved from
      ASSERT_FALSE(mvkey1.moved());                      // was not moved from
      ASSERT_EQ(::portable_stl::get<0>(*iter), mvkey1);  // key
      ASSERT_EQ(::portable_stl::get<1>(*iter).get(), 4); // value
    }
    {
      t_move_only mvkey2(3, 3.0);
      t_move_only mv2(5, 5.0);
      auto        result = mp.insert_or_assign(it, std::move(mvkey2), std::move(mv2));
      ASSERT_TRUE(result);
      auto iter = result.value();

      ASSERT_EQ(mp.size(), 11);
      ASSERT_TRUE(mv2.moved());                          // was moved from
      ASSERT_TRUE(mvkey2.moved());                       // was moved from
      ASSERT_EQ(::portable_stl::get<0>(*iter).get(), 3); // key
      ASSERT_EQ(::portable_stl::get<1>(*iter).get(), 5); // value
    }
    // wrong hint: begin()
    {
      t_move_only mvkey3(6, 6.0);
      t_move_only mv3(8, 8.0);
      auto        result = mp.insert_or_assign(mp.begin(), std::move(mvkey3), std::move(mv3));
      ASSERT_TRUE(result);
      auto iter = result.value();

      ASSERT_EQ(mp.size(), 11);
      ASSERT_TRUE(mv3.moved());                          // was moved from
      ASSERT_FALSE(mvkey3.moved());                      // was not moved from
      ASSERT_EQ(::portable_stl::get<0>(*iter), mvkey3);  // key
      ASSERT_EQ(::portable_stl::get<1>(*iter).get(), 8); // value
    }
    {
      t_move_only mvkey4(7, 7.0);
      t_move_only mv4(9, 9.0);
      auto        result = mp.insert_or_assign(mp.begin(), std::move(mvkey4), std::move(mv4));
      ASSERT_TRUE(result);
      auto iter = result.value();

      ASSERT_EQ(mp.size(), 12);
      ASSERT_TRUE(mv4.moved());                          // was moved from
      ASSERT_TRUE(mvkey4.moved());                       // was moved from
      ASSERT_EQ(::portable_stl::get<0>(*iter).get(), 7); // key
      ASSERT_EQ(::portable_stl::get<1>(*iter).get(), 9); // value
    }
    // wrong hint: end()
    {
      t_move_only mvkey5(8, 8.0);
      t_move_only mv5(10, 10.0);
      auto        result = mp.insert_or_assign(mp.end(), std::move(mvkey5), std::move(mv5));
      ASSERT_TRUE(result);
      auto iter = result.value();

      ASSERT_EQ(mp.size(), 12);
      ASSERT_TRUE(mv5.moved());                           // was moved from
      ASSERT_FALSE(mvkey5.moved());                       // was not moved from
      ASSERT_EQ(::portable_stl::get<0>(*iter), mvkey5);   // key
      ASSERT_EQ(::portable_stl::get<1>(*iter).get(), 10); // value
    }
    {
      t_move_only mvkey6(9, 9.0);
      t_move_only mv6(11, 11.0);
      auto        result = mp.insert_or_assign(mp.end(), std::move(mvkey6), std::move(mv6));
      ASSERT_TRUE(result);
      auto iter = result.value();

      ASSERT_EQ(mp.size(), 13);
      ASSERT_TRUE(mv6.moved());                           // was moved from
      ASSERT_TRUE(mvkey6.moved());                        // was moved from
      ASSERT_EQ(::portable_stl::get<0>(*iter).get(), 9);  // key
      ASSERT_EQ(::portable_stl::get<1>(*iter).get(), 11); // value
    }
    // wrong hint: third element
    {
      t_move_only mvkey7(10, 10.0);
      t_move_only mv7(12, 12.0);
      auto        result = mp.insert_or_assign(::portable_stl::next(mp.begin(), 2), std::move(mvkey7), std::move(mv7));
      ASSERT_TRUE(result);
      auto iter = result.value();

      ASSERT_EQ(mp.size(), 13);
      ASSERT_TRUE(mv7.moved());                           // was moved from
      ASSERT_FALSE(mvkey7.moved());                       // was not moved from
      ASSERT_EQ(::portable_stl::get<0>(*iter), mvkey7);   // key
      ASSERT_EQ(::portable_stl::get<1>(*iter).get(), 12); // value
    }
    {
      t_move_only mvkey8(11, 11.0);
      t_move_only mv8(13, 13.0);
      auto        result = mp.insert_or_assign(::portable_stl::next(mp.begin(), 2), std::move(mvkey8), std::move(mv8));
      ASSERT_TRUE(result);
      auto iter = result.value();

      ASSERT_EQ(mp.size(), 14);
      ASSERT_TRUE(mv8.moved());                           // was moved from
      ASSERT_TRUE(mvkey8.moved());                        // was moved from
      ASSERT_EQ(::portable_stl::get<0>(*iter).get(), 11); // key
      ASSERT_EQ(::portable_stl::get<1>(*iter).get(), 13); // value
    }
  }

  // bad allocation
  {
    using t_map_value_type2 = ::portable_stl::tuple<std::int32_t const, t_move_only>;

    using t_allocator3 = test_allocator_helper::test_allocator<t_map_value_type2>;

    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    t_allocator3 alloc(&stat);

    ::portable_stl::map<std::int32_t, t_move_only, ::portable_stl::less<std::int32_t>, t_allocator3> mp(alloc);

    auto result = mp.insert_or_assign(mp.begin(), 1, t_move_only(1, 2));

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }
}

namespace test_map_helper {
template<class t_map> bool map_equal(t_map const &map, t_map other) {
  return map == other;
}

class throw_comparator final {
  bool &m_should_throw;

public:
  throw_comparator(bool &should_throw) : m_should_throw(should_throw) {
  }

  template<class t_type> bool operator()(t_type const &lhs, t_type const &rhs) const {
    if (m_should_throw) {
      throw 0;
    }
    return lhs < rhs;
  }
};

class comparator final {
public:
  comparator() = default;

  bool operator()(test_common_helper::Counter<std::int32_t> const &lhs,
                  test_common_helper::Counter<std::int32_t> const &rhs) const {
    return lhs < rhs;
  }
};
} // namespace test_map_helper

// template <class C2> void merge(map<key_type, value_type, C2, allocator_type>& source);
TEST(map, merge_lvalue_map) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::map<std::int32_t, std::int32_t> src({
      {1, 0},
      {3, 0},
      {5, 0}
    });

    ::portable_stl::map<std::int32_t, std::int32_t> dst({
      {2, 0},
      {4, 0},
      {5, 0}
    });

    dst.merge(src);

    ASSERT_TRUE(test_map_helper::map_equal(src,
                                           ::portable_stl::map<std::int32_t, std::int32_t>({
                                             {5, 0}
    })));

    ASSERT_TRUE(test_map_helper::map_equal(dst,
                                           ::portable_stl::map<std::int32_t, std::int32_t>({
                                             {1, 0},
                                             {2, 0},
                                             {3, 0},
                                             {4, 0},
                                             {5, 0}
    })));
  }

  {
    ::portable_stl::map<std::int32_t, std::int32_t> src({
      {1, 0},
      {3, 0},
      {5, 0}
    });

    ::portable_stl::map<std::int32_t, std::int32_t> dst({
      {2, 0},
      {4, 0},
      {5, 0}
    });

    dst.merge(std::move(src));

    ASSERT_TRUE(test_map_helper::map_equal(src,
                                           ::portable_stl::map<std::int32_t, std::int32_t>({
                                             {5, 0}
    })));

    ASSERT_TRUE(test_map_helper::map_equal(dst,
                                           ::portable_stl::map<std::int32_t, std::int32_t>({
                                             {1, 0},
                                             {2, 0},
                                             {3, 0},
                                             {4, 0},
                                             {5, 0}
    })));
  }

  // throw by comparator
  {
    bool do_throw = false;

    /**
     * @brief Map alias.
     */
    using t_map2
      = ::portable_stl::map<test_common_helper::Counter<std::int32_t>, std::int32_t, test_map_helper::throw_comparator>;

    t_map2 src(
      {
        {1, 0},
        {3, 0},
        {5, 0}
    },
      test_map_helper::throw_comparator(do_throw));

    t_map2 dst(
      {
        {2, 0},
        {4, 0},
        {5, 0}
    },
      test_map_helper::throw_comparator(do_throw));

    ASSERT_EQ(test_common_helper::Counter_base::gConstructed, 6);

    do_throw = true;
    try {
      dst.merge(src);
      ASSERT_TRUE(false);
    } catch (int &) {
    }

    do_throw = false;
    ASSERT_TRUE(test_map_helper::map_equal(src,
                                           t_map2(
                                             {
                                               {1, 0},
                                               {3, 0},
                                               {5, 0}
    },
                                             test_map_helper::throw_comparator(do_throw))));
    ASSERT_TRUE(test_map_helper::map_equal(dst,
                                           t_map2(
                                             {
                                               {2, 0},
                                               {4, 0},
                                               {5, 0}
    },
                                             test_map_helper::throw_comparator(do_throw))));
  }
}

// pair<iterator, bool> try_emplace(const key_type& k, Args&&... args);
TEST(map, try_emplace) {
  static_cast<void>(test_info_);

  using t_map2 = ::portable_stl::map<std::int32_t, ::test_map_helper::t_move_only>;

  t_map2 mp;

  for (std::int32_t i{0}; i < 20; i += 2) {
    mp.emplace(i, t_move_only(i, static_cast<double>(i)));
  }

  ASSERT_EQ(10, mp.size());

  t_move_only mv1(3, 3.0);
  for (std::int32_t i{0}; i < 20; i += 2) {
    auto result = mp.try_emplace(i, std::move(mv1));
    ASSERT_TRUE(result);

    auto iter_bool = result.value();
    ASSERT_EQ(10, mp.size());
    ASSERT_FALSE(::portable_stl::get<1>(iter_bool));                          // was not inserted
    ASSERT_FALSE(mv1.moved());                                                // was not moved from
    ASSERT_EQ(i, ::portable_stl::get<0>(*::portable_stl::get<0>(iter_bool))); // key
  }

  {
    auto result = mp.try_emplace(-1, std::move(mv1));
    ASSERT_TRUE(result);

    auto iter_bool = result.value();
    ASSERT_EQ(11, mp.size());
    ASSERT_TRUE(::portable_stl::get<1>(iter_bool));                                 // was inserted
    ASSERT_TRUE(mv1.moved());                                                       // was moved from
    ASSERT_EQ(-1, ::portable_stl::get<0>(*::portable_stl::get<0>(iter_bool)));      // key
    ASSERT_EQ(3, ::portable_stl::get<1>(*::portable_stl::get<0>(iter_bool)).get()); // value
  }
  {
    t_move_only mv2(5, 3.0);
    auto        result = mp.try_emplace(5, std::move(mv2));
    ASSERT_TRUE(result);

    auto iter_bool = result.value();
    ASSERT_EQ(12, mp.size());
    ASSERT_TRUE(::portable_stl::get<1>(iter_bool));                                 // was inserted
    ASSERT_TRUE(mv2.moved());                                                       // was moved from
    ASSERT_EQ(5, ::portable_stl::get<0>(*::portable_stl::get<0>(iter_bool)));       // key
    ASSERT_EQ(5, ::portable_stl::get<1>(*::portable_stl::get<0>(iter_bool)).get()); // value
  }
  {
    t_move_only mv3(-1, 3.0);
    auto        result = mp.try_emplace(117, std::move(mv3));
    ASSERT_TRUE(result);

    auto iter_bool = result.value();
    ASSERT_EQ(mp.size(), 13);
    ASSERT_TRUE(::portable_stl::get<1>(iter_bool));                                  // was inserted
    ASSERT_TRUE(mv3.moved());                                                        // was moved from
    ASSERT_EQ(117, ::portable_stl::get<0>(*::portable_stl::get<0>(iter_bool)));      // key
    ASSERT_EQ(-1, ::portable_stl::get<1>(*::portable_stl::get<0>(iter_bool)).get()); // value
  }
}

// pair<iterator, bool> try_emplace(key_type&& k, Args&&... args);
TEST(map, try_emplace1) {
  static_cast<void>(test_info_);

  using t_map2 = ::portable_stl::map<::test_map_helper::t_move_only, ::test_map_helper::t_move_only>;

  t_map2 mp;

  for (std::int32_t i{0}; i < 20; i += 2) {
    mp.emplace(t_move_only(i, static_cast<double>(i)), t_move_only(i + 1, static_cast<double>(i + 1)));
  }

  ASSERT_EQ(10, mp.size());

  {
    ::test_map_helper::t_move_only mvkey1(2, 2.0);
    ::test_map_helper::t_move_only mv1(4, 4.0);
    auto                           result = mp.try_emplace(std::move(mvkey1), std::move(mv1));
    ASSERT_TRUE(result);

    auto iter_bool = result.value();
    ASSERT_EQ(mp.size(), 10);
    ASSERT_FALSE(::portable_stl::get<1>(iter_bool));                               // was not inserted
    ASSERT_FALSE(mv1.moved());                                                     // was not moved from
    ASSERT_FALSE(mvkey1.moved());                                                  // was not moved from
    ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::get<0>(iter_bool)), mvkey1); // key

    ::test_map_helper::t_move_only mvkey2(3, 3.0);
    result = mp.try_emplace(std::move(mvkey2), std::move(mv1));
    ASSERT_TRUE(result);

    iter_bool = result.value();
    ASSERT_EQ(mp.size(), 11);
    ASSERT_TRUE(::portable_stl::get<1>(iter_bool));                                 // was inserted
    ASSERT_TRUE(mv1.moved());                                                       // was moved from
    ASSERT_TRUE(mvkey2.moved());                                                    // was moved from
    ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::get<0>(iter_bool)).get(), 3); // key
    ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::get<0>(iter_bool)).get(), 4); // value
  }
}

// iterator try_emplace(const_iterator hint, const key_type& k, Args&&... args);
TEST(map, try_emplace2) {
  static_cast<void>(test_info_);

  using t_map2 = ::portable_stl::map<std::int32_t, ::test_map_helper::t_move_only>;

  t_map2 mp;

  for (int i = 0; i < 20; i += 2) {
    mp.try_emplace(i, t_move_only(i, (double)i));
  }
  ASSERT_EQ(mp.size(), 10);

  t_map2::const_iterator it = mp.find(2);

  t_move_only mv1(3, 3.0);
  for (int i = 0; i < 20; i += 2) {
    auto result = mp.try_emplace(it, i, std::move(mv1));
    ASSERT_TRUE(result);

    auto iter = result.value();
    ASSERT_EQ(mp.size(), 10);
    ASSERT_FALSE(mv1.moved());                         // was not moved from
    ASSERT_EQ(::portable_stl::get<0>(*iter), i);       // key
    ASSERT_EQ(::portable_stl::get<1>(*iter).get(), i); // value
  }

  auto result = mp.try_emplace(it, 3, std::move(mv1));
  ASSERT_TRUE(result);

  auto iter = result.value();
  ASSERT_EQ(mp.size(), 11);
  ASSERT_TRUE(mv1.moved());                          // was moved from
  ASSERT_EQ(::portable_stl::get<0>(*iter), 3);       // key
  ASSERT_EQ(::portable_stl::get<1>(*iter).get(), 3); // value
}

// iterator try_emplace(const_iterator hint, key_type&& k, Args&&... args);
TEST(map, try_emplace3) {
  static_cast<void>(test_info_);

  using t_map2 = ::portable_stl::map<::test_map_helper::t_move_only, ::test_map_helper::t_move_only>;

  t_map2 mp;

  for (std::int32_t i{0}; i < 20; i += 2) {
    mp.emplace(t_move_only(i, static_cast<double>(i)), t_move_only(i + 1, static_cast<double>(i + 1)));
  }

  ASSERT_EQ(10, mp.size());

  t_map2::const_iterator it = ::portable_stl::next(mp.cbegin());

  {
    t_move_only mvkey1(2, 2.0);
    t_move_only mv1(4, 4.0);
    auto        result = mp.try_emplace(it, std::move(mvkey1), std::move(mv1));
    ASSERT_TRUE(result);

    auto iter = result.value();
    ASSERT_EQ(mp.size(), 10);
    ASSERT_FALSE(mv1.moved());                        // was not moved from
    ASSERT_FALSE(mvkey1.moved());                     // was not moved from
    ASSERT_EQ(::portable_stl::get<0>(*iter), mvkey1); // key

    t_move_only mvkey2(3, 3.0);
    result = mp.try_emplace(it, std::move(mvkey2), std::move(mv1));
    ASSERT_TRUE(result);

    iter = result.value();
    ASSERT_EQ(mp.size(), 11);
    ASSERT_TRUE(mv1.moved());                          // was moved from
    ASSERT_TRUE(mvkey2.moved());                       // was moved from
    ASSERT_EQ(::portable_stl::get<0>(*iter).get(), 3); // key
    ASSERT_EQ(::portable_stl::get<1>(*iter).get(), 4); // value
  }
}
