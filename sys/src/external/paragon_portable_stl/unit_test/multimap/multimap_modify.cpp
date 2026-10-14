// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="multimap_modify.cpp"
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
#include <portable_stl/map/multimap.h>
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

using t_map = ::portable_stl::multimap<std::int32_t, double>;

// [erase]

// size_type erase(const Key& key);
TEST(multimap, erase_key) {
  static_cast<void>(test_info_);

  t_map_value_type arr[] = {t_map_value_type(1, 1),
                            t_map_value_type(1, 1.5),
                            t_map_value_type(1, 2),
                            t_map_value_type(2, 1),
                            t_map_value_type(2, 1.5),
                            t_map_value_type(2, 2),
                            t_map_value_type(3, 1),
                            t_map_value_type(3, 1.5),
                            t_map_value_type(3, 2)};

  ::portable_stl::multimap<std::int32_t, double> mp(arr, arr + sizeof(arr) / sizeof(arr[0]));

  ASSERT_EQ(9, mp.size());

  auto removed_cnt = mp.erase(2);
  ASSERT_EQ(3, removed_cnt);

  ASSERT_EQ(6, mp.size());

  ASSERT_EQ(1, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 0)));
  ASSERT_EQ(1, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 0)));
  ASSERT_EQ(1, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 1)));
  ASSERT_EQ(1.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 1)));
  ASSERT_EQ(1, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(2, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(3, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(1, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(3, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 4)));
  ASSERT_EQ(1.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 4)));
  ASSERT_EQ(3, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 5)));
  ASSERT_EQ(2, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 5)));

  removed_cnt = mp.erase(2);
  ASSERT_EQ(0, removed_cnt);
  ASSERT_EQ(6, mp.size());

  ASSERT_EQ(1, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 0)));
  ASSERT_EQ(1, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 0)));
  ASSERT_EQ(1, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 1)));
  ASSERT_EQ(1.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 1)));
  ASSERT_EQ(1, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(2, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(3, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(1, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 3)));
  ASSERT_EQ(3, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 4)));
  ASSERT_EQ(1.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 4)));
  ASSERT_EQ(3, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 5)));
  ASSERT_EQ(2, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 5)));

  removed_cnt = mp.erase(3);
  ASSERT_EQ(3, removed_cnt);
  ASSERT_EQ(3, mp.size());

  ASSERT_EQ(1, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 0)));
  ASSERT_EQ(1, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 0)));
  ASSERT_EQ(1, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 1)));
  ASSERT_EQ(1.5, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 1)));
  ASSERT_EQ(1, ::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)));
  ASSERT_EQ(2, ::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)));

  removed_cnt = mp.erase(1);
  ASSERT_EQ(3, removed_cnt);
  ASSERT_EQ(0, mp.size());
}

// iterator erase(const_iterator position);
TEST(multimap, erase_position) {
  static_cast<void>(test_info_);

  t_map_value_type arr[] = {t_map_value_type(1, 1),
                            t_map_value_type(1, 1.5),
                            t_map_value_type(1, 2),
                            t_map_value_type(2, 1),
                            t_map_value_type(2, 1.5),
                            t_map_value_type(2, 2),
                            t_map_value_type(3, 1),
                            t_map_value_type(3, 1.5),
                            t_map_value_type(3, 2)};

  ::portable_stl::multimap<std::int32_t, double> mp(arr, arr + sizeof(arr) / sizeof(arr[0]));

  ASSERT_EQ(9, mp.size());

  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 0)), 1);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 0)), 1);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 1)), 1);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 1)), 1.5);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)), 1);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)), 2);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 3)), 2);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 3)), 1);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 4)), 2);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 4)), 1.5);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 5)), 2);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 5)), 2);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 6)), 3);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 6)), 1);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 7)), 3);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 7)), 1.5);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 8)), 3);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 8)), 2);

  auto iter = mp.erase(::portable_stl::next(mp.cbegin(), 3));
  ASSERT_EQ(iter, ::portable_stl::next(mp.begin(), 3));
  ASSERT_EQ(8, mp.size());

  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 0)), 1);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 0)), 1);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 1)), 1);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 1)), 1.5);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)), 1);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)), 2);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 3)), 2);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 3)), 1.5);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 4)), 2);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 4)), 2);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 5)), 3);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 5)), 1);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 6)), 3);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 6)), 1.5);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 7)), 3);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 7)), 2);

  iter = mp.erase(::portable_stl::next(mp.cbegin(), 0));
  ASSERT_EQ(iter, mp.begin());
  ASSERT_EQ(7, mp.size());

  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 0)), 1);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 0)), 1.5);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 1)), 1);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 1)), 2);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)), 2);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)), 1.5);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 3)), 2);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 3)), 2);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 4)), 3);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 4)), 1);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 5)), 3);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 5)), 1.5);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 6)), 3);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 6)), 2);

  iter = mp.erase(::portable_stl::next(mp.cbegin(), 5));
  ASSERT_EQ(iter, ::portable_stl::prev(mp.end()));
  ASSERT_EQ(6, mp.size());

  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 0)), 1);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 0)), 1.5);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 1)), 1);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 1)), 2);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)), 2);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)), 1.5);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 3)), 2);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 3)), 2);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 4)), 3);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 4)), 1);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 5)), 3);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 5)), 2);

  iter = mp.erase(::portable_stl::next(mp.begin(), 1));
  ASSERT_EQ(iter, ::portable_stl::next(mp.begin()));
  ASSERT_EQ(5, mp.size());

  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 0)), 1);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 0)), 1.5);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 1)), 2);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 1)), 1.5);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)), 2);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)), 2);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 3)), 3);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 3)), 1);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 4)), 3);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 4)), 2);

  iter = mp.erase(::portable_stl::next(mp.begin(), 2));
  ASSERT_EQ(iter, ::portable_stl::next(mp.begin(), 2));
  ASSERT_EQ(4, mp.size());

  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 0)), 1);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 0)), 1.5);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 1)), 2);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 1)), 1.5);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)), 3);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)), 1);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 3)), 3);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 3)), 2);

  iter = mp.erase(::portable_stl::next(mp.cbegin(), 2));
  ASSERT_EQ(iter, ::portable_stl::next(mp.begin(), 2));
  ASSERT_EQ(3, mp.size());

  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 0)), 1);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 0)), 1.5);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 1)), 2);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 1)), 1.5);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)), 3);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)), 2);

  iter = mp.erase(::portable_stl::next(mp.cbegin(), 0));
  ASSERT_EQ(iter, ::portable_stl::next(mp.begin(), 0));
  ASSERT_EQ(2, mp.size());

  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 0)), 2);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 0)), 1.5);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 1)), 3);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 1)), 2);

  iter = mp.erase(::portable_stl::next(mp.cbegin(), 1));
  ASSERT_EQ(iter, ::portable_stl::next(mp.begin(), 1));
  ASSERT_EQ(1, mp.size());

  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 0)), 2);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 0)), 1.5);

  iter = mp.erase(mp.cbegin());
  ASSERT_EQ(iter, mp.cbegin());
  ASSERT_EQ(iter, mp.end());
  ASSERT_EQ(0, mp.size());
}

// iterator erase(const_iterator first, const_iterator last);
TEST(multimap, erase_iter_iter) {
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

  ::portable_stl::multimap<std::int32_t, double> mp(arr, arr + sizeof(arr) / sizeof(arr[0]));

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

// [extract]

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
TEST(multimap, extract_key) {
  static_cast<void>(test_info_);

  // using t_map_value_type2 = ::portable_stl::tuple<std::int32_t const, std::int32_t>;

  {
    ::portable_stl::multimap<std::int32_t, std::int32_t> mp({
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
    ::portable_stl::multimap<test_common_helper::Counter<std::int32_t>, test_common_helper::Counter<std::int32_t>> mp({
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
    ASSERT_EQ(0, test_common_helper::Counter_base::gConstructed);
  }
}

// node_type extract(const_iterator);
TEST(multimap, extract_iter) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::multimap<std::int32_t, std::int32_t> mp({
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
    ::portable_stl::multimap<test_common_helper::Counter<std::int32_t>, test_common_helper::Counter<std::int32_t>> mp({
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

namespace test_multimap_helper {
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
} // namespace test_multimap_helper

// template <class C2>
//   void merge(map<key_type, value_type, C2, allocator_type>& source);
// template <class C2>
//   void merge(map<key_type, value_type, C2, allocator_type>&& source);
// template <class C2>
//   void merge(multimap<key_type, value_type, C2, allocator_type>& source);
// template <class C2>
//   void merge(multimap<key_type, value_type, C2, allocator_type>&& source);
TEST(multimap, merge) {
  static_cast<void>(test_info_);

  // merge lvalue
  {
    ::portable_stl::multimap<std::int32_t, std::int32_t> src{
      {1, 0},
      {3, 0},
      {5, 0}
    };
    ::portable_stl::multimap<std::int32_t, std::int32_t> dst{
      {2, 0},
      {4, 0},
      {5, 0}
    };
    dst.merge(src);
    ASSERT_TRUE(test_multimap_helper::map_equal(src, {}));
    ASSERT_TRUE(test_multimap_helper::map_equal(dst,
                                                {
                                                  {1, 0},
                                                  {2, 0},
                                                  {3, 0},
                                                  {4, 0},
                                                  {5, 0},
                                                  {5, 0}
    }));
  }

  // marge exception on compare
  {
    bool do_throw{false};
    using t_mmap = ::portable_stl::
      multimap<test_common_helper::Counter<std::int32_t>, std::int32_t, test_multimap_helper::throw_comparator>;
    t_mmap src(
      {
        {1, 0},
        {3, 0},
        {5, 0}
    },
      test_multimap_helper::throw_comparator(do_throw));

    t_mmap dst(
      {
        {2, 0},
        {4, 0},
        {5, 0}
    },
      test_multimap_helper::throw_comparator(do_throw));

    ASSERT_EQ(6, test_common_helper::Counter_base::gConstructed);

    do_throw = true;
    try {
      dst.merge(src);
    } catch (std::int32_t &) {
      do_throw = false;
    }

    ASSERT_FALSE(do_throw);
    ASSERT_TRUE(test_multimap_helper::map_equal(src,
                                                t_mmap(
                                                  {
                                                    {1, 0},
                                                    {3, 0},
                                                    {5, 0}
    },
                                                  test_multimap_helper::throw_comparator(do_throw))));
    ASSERT_TRUE(test_multimap_helper::map_equal(dst,
                                                t_mmap(
                                                  {
                                                    {2, 0},
                                                    {4, 0},
                                                    {5, 0}
    },
                                                  test_multimap_helper::throw_comparator(do_throw))));
  }
  ASSERT_EQ(0, test_common_helper::Counter_base::gConstructed);

  struct comparator final {
  public:
    comparator() = default;

    bool operator()(::test_common_helper::Counter<std::int32_t> const &lhs,
                    ::test_common_helper::Counter<std::int32_t> const &rhs) const {
      return lhs < rhs;
    }
  };

  // multimap lvalue merge multimap and map
  {
    using first_map_type = ::portable_stl::multimap<::test_common_helper::Counter<std::int32_t>,
                                                    std::int32_t,
                                                    std::less<::test_common_helper::Counter<std::int32_t>>>;
    using second_map_type
      = ::portable_stl::multimap<::test_common_helper::Counter<std::int32_t>, std::int32_t, comparator>;
    using third_map_type = ::portable_stl::map<::test_common_helper::Counter<std::int32_t>, std::int32_t, comparator>;

    {
      first_map_type first{
        {1, 0},
        {2, 0},
        {3, 0}
      };
      second_map_type second{
        {2, 0},
        {3, 0},
        {4, 0}
      };
      third_map_type third{
        {1, 0},
        {3, 0}
      };

      ASSERT_EQ(8, test_common_helper::Counter_base::gConstructed);

      first.merge(second);
      first.merge(third);

      ASSERT_TRUE(test_multimap_helper::map_equal(first,
                                                  {
                                                    {1, 0},
                                                    {1, 0},
                                                    {2, 0},
                                                    {2, 0},
                                                    {3, 0},
                                                    {3, 0},
                                                    {3, 0},
                                                    {4, 0}
      }));
      ASSERT_TRUE(test_multimap_helper::map_equal(second, {}));
      ASSERT_TRUE(test_multimap_helper::map_equal(third, {}));

      ASSERT_EQ(8, test_common_helper::Counter_base::gConstructed);
    }
    ASSERT_EQ(0, test_common_helper::Counter_base::gConstructed);

  // merge rvalue merge multimap and map
    {
      first_map_type first{
        {1, 0},
        {2, 0},
        {3, 0}
      };

      second_map_type second{
        {2, 0},
        {3, 0},
        {4, 0}
      };

      third_map_type third{
        {1, 0},
        {3, 0}
      };

      ASSERT_EQ(8, test_common_helper::Counter_base::gConstructed);

      first.merge(std::move(second));
      first.merge(std::move(third));

      ASSERT_TRUE(test_multimap_helper::map_equal(first,
                                                  {
                                                    {1, 0},
                                                    {1, 0},
                                                    {2, 0},
                                                    {2, 0},
                                                    {3, 0},
                                                    {3, 0},
                                                    {3, 0},
                                                    {4, 0}
      }));
      ASSERT_TRUE(test_multimap_helper::map_equal(second, {}));
      ASSERT_TRUE(test_multimap_helper::map_equal(third, {}));

      ASSERT_EQ(8, test_common_helper::Counter_base::gConstructed);
    }
    ASSERT_EQ(0, test_common_helper::Counter_base::gConstructed);
  }
  ASSERT_EQ(0, test_common_helper::Counter_base::gConstructed);

  {
    ::portable_stl::multimap<std::int32_t, std::int32_t> first;
    {
      ::portable_stl::multimap<std::int32_t, std::int32_t> second;
      first.merge(second);
      first.merge(std::move(second));
    }
    {
      ::portable_stl::multimap<std::int32_t, std::int32_t> second;
      first.merge(second);
      first.merge(std::move(second));
    }
  }
}
