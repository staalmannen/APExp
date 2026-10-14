// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="map_insert.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <portable_stl/map/map.h>
#include <portable_stl/string/string.h>

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

// pair<iterator, bool> insert(const value_type& v);
TEST(map, insert_value_type) {
  static_cast<void>(test_info_);

  /**
   * @brief Map value type alias.
   */
  using t_value_type = typename t_map::value_type;

  {
    t_map mp;

    // == 1
    t_value_type const value1(2, 2.5);
    auto               result = mp.insert(value1);
    ASSERT_TRUE(result);

    auto iter_bool_result = result.value();
    ASSERT_TRUE(::portable_stl::get<1>(iter_bool_result));
    auto insert_iter = ::portable_stl::get<0>(iter_bool_result);

    ASSERT_EQ(mp.begin(), insert_iter);
    ASSERT_EQ(1, mp.size());
    ASSERT_EQ(2, ::portable_stl::get<0>(*insert_iter));
    ASSERT_EQ(2.5, ::portable_stl::get<1>(*insert_iter));

    // == 2
    t_value_type const value2(1, 1.5);
    result = mp.insert(value2);
    ASSERT_TRUE(result);

    iter_bool_result = result.value();
    ASSERT_TRUE(::portable_stl::get<1>(iter_bool_result));
    insert_iter = ::portable_stl::get<0>(iter_bool_result);

    ASSERT_EQ(mp.begin(), insert_iter);
    ASSERT_EQ(2, mp.size());
    ASSERT_EQ(1, ::portable_stl::get<0>(*insert_iter));
    ASSERT_EQ(1.5, ::portable_stl::get<1>(*insert_iter));

    // == 3
    t_value_type const value3(3, 3.5);
    result = mp.insert(value3);
    ASSERT_TRUE(result);

    iter_bool_result = result.value();
    ASSERT_TRUE(::portable_stl::get<1>(iter_bool_result));
    insert_iter = ::portable_stl::get<0>(iter_bool_result);

    ASSERT_EQ(::portable_stl::prev(mp.end()), insert_iter);
    ASSERT_EQ(3, mp.size());
    ASSERT_EQ(3, ::portable_stl::get<0>(*insert_iter));
    ASSERT_EQ(3.5, ::portable_stl::get<1>(*insert_iter));
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 3;
    t_allocator2 alloc(&stat);

    ::portable_stl::map<std::int32_t, double, t_compare, t_allocator2> mp(
      {
        {1, 1.5},
        {2, 2.5},
        {3, 3.5}
    },
      alloc);

    t_value_type const value(4, 4.5);
    auto               result = mp.insert(value);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // Strong guarantee
    ASSERT_EQ(3, mp.size());
  }
}

namespace test_map_helper {
template<class t_map, class t_value_like_type> void map_insert_rv_test() {
  t_map mp;

  // == 1
  auto result = mp.insert(t_value_like_type(2, 5));
  ASSERT_TRUE(result);

  auto iter_bool_result = result.value();
  ASSERT_TRUE(::portable_stl::get<1>(iter_bool_result));
  auto insert_iter = ::portable_stl::get<0>(iter_bool_result);

  ASSERT_EQ(mp.begin(), insert_iter);
  ASSERT_EQ(1, mp.size());
  ASSERT_EQ(2, ::portable_stl::get<0>(*insert_iter));
  ASSERT_EQ(5, ::portable_stl::get<1>(*insert_iter));

  // == 2
  result = mp.insert(t_value_like_type(1, 3));
  ASSERT_TRUE(result);

  iter_bool_result = result.value();
  ASSERT_TRUE(::portable_stl::get<1>(iter_bool_result));
  insert_iter = ::portable_stl::get<0>(iter_bool_result);

  ASSERT_EQ(mp.begin(), insert_iter);
  ASSERT_EQ(2, mp.size());
  ASSERT_EQ(1, ::portable_stl::get<0>(*insert_iter));
  ASSERT_EQ(3, ::portable_stl::get<1>(*insert_iter));

  // == 3
  result = mp.insert(t_value_like_type(3, 4));
  ASSERT_TRUE(result);

  iter_bool_result = result.value();
  ASSERT_TRUE(::portable_stl::get<1>(iter_bool_result));
  insert_iter = ::portable_stl::get<0>(iter_bool_result);

  ASSERT_EQ(::portable_stl::prev(mp.end()), insert_iter);
  ASSERT_EQ(3, mp.size());
  ASSERT_EQ(3, ::portable_stl::get<0>(*insert_iter));
  ASSERT_EQ(4, ::portable_stl::get<1>(*insert_iter));

  // == 4 (same key)
  result = mp.insert(t_value_like_type(3, 7));
  ASSERT_TRUE(result);

  iter_bool_result = result.value();
  ASSERT_FALSE(::portable_stl::get<1>(iter_bool_result));
  insert_iter = ::portable_stl::get<0>(iter_bool_result);

  ASSERT_EQ(::portable_stl::prev(mp.end()), insert_iter);
  ASSERT_EQ(3, mp.size());
  ASSERT_EQ(3, ::portable_stl::get<0>(*insert_iter));
  ASSERT_EQ(4, ::portable_stl::get<1>(*insert_iter));
}
} // namespace test_map_helper

// expected<tuple<iterator, bool>, portable_stl_error> insert(value_type &&value)
// expected<tuple<iterator, bool>, portable_stl_error> insert(t_like_value &&value)
TEST(map, insert_rvalue_type) {
  static_cast<void>(test_info_);

  /**
   * @brief Move only alias.
   */
  using t_move_only = test_common_helper::MoveOnly;

  // value_type_like&&
  test_map_helper::map_insert_rv_test<::portable_stl::map<std::int32_t, t_move_only>,
                                      ::portable_stl::tuple<std::int32_t, t_move_only>>();

  // value_type&&
  test_map_helper::map_insert_rv_test<::portable_stl::map<std::int32_t, t_move_only>,
                                      ::portable_stl::tuple<std::int32_t const, t_move_only>>();

  // implicit value_type&&
  {
    ::portable_stl::map<std::int32_t, t_move_only> mp;

    // == 1
    auto result = mp.insert({2, t_move_only(2)});
    ASSERT_TRUE(result);

    auto iter_bool_result = result.value();
    ASSERT_TRUE(::portable_stl::get<1>(iter_bool_result));
    auto insert_iter = ::portable_stl::get<0>(iter_bool_result);

    ASSERT_EQ(mp.begin(), insert_iter);
    ASSERT_EQ(1, mp.size());
    ASSERT_EQ(2, ::portable_stl::get<0>(*insert_iter));
    ASSERT_EQ(2, ::portable_stl::get<1>(*insert_iter));

    // == 2
    result = mp.insert({1, t_move_only(1)});
    ASSERT_TRUE(result);

    iter_bool_result = result.value();
    ASSERT_TRUE(::portable_stl::get<1>(iter_bool_result));
    insert_iter = ::portable_stl::get<0>(iter_bool_result);

    ASSERT_EQ(mp.begin(), insert_iter);
    ASSERT_EQ(2, mp.size());
    ASSERT_EQ(1, ::portable_stl::get<0>(*insert_iter));
    ASSERT_EQ(1, ::portable_stl::get<1>(*insert_iter));

    // == 3
    result = mp.insert({3, t_move_only(3)});
    ASSERT_TRUE(result);

    iter_bool_result = result.value();
    ASSERT_TRUE(::portable_stl::get<1>(iter_bool_result));
    insert_iter = ::portable_stl::get<0>(iter_bool_result);

    ASSERT_EQ(::portable_stl::prev(mp.end()), insert_iter);
    ASSERT_EQ(3, mp.size());
    ASSERT_EQ(3, ::portable_stl::get<0>(*insert_iter));
    ASSERT_EQ(3, ::portable_stl::get<1>(*insert_iter));

    // == 4
    result = mp.insert({3, t_move_only(3)});
    ASSERT_TRUE(result);

    iter_bool_result = result.value();
    ASSERT_FALSE(::portable_stl::get<1>(iter_bool_result));
    insert_iter = ::portable_stl::get<0>(iter_bool_result);

    ASSERT_EQ(::portable_stl::prev(mp.end()), insert_iter);
    ASSERT_EQ(3, mp.size());
    ASSERT_EQ(3, ::portable_stl::get<0>(*insert_iter));
    ASSERT_EQ(3.5, ::portable_stl::get<1>(*insert_iter));
  }
}

// expected<iterator, portable_stl_error> insert(const_iterator position, const value_type& v)
TEST(map, insert_pos_value_type) {
  static_cast<void>(test_info_);

  /**
   * @brief Map value type alias.
   */
  using t_value_type = typename t_map::value_type;

  {
    t_map mp;

    // == 1
    t_value_type const value1(2, 2.5);
    auto               result = mp.insert(mp.end(), value1);
    ASSERT_TRUE(result);

    auto iter_result = result.value();

    ASSERT_EQ(mp.begin(), iter_result);
    ASSERT_EQ(1, mp.size());
    ASSERT_EQ(2, ::portable_stl::get<0>(*iter_result));
    ASSERT_EQ(2.5, ::portable_stl::get<1>(*iter_result));

    // == 2
    t_value_type const value2(1, 1.5);
    result = mp.insert(mp.end(), value2);
    ASSERT_TRUE(result);

    iter_result = result.value();

    ASSERT_EQ(mp.begin(), iter_result);
    ASSERT_EQ(2, mp.size());
    ASSERT_EQ(1, ::portable_stl::get<0>(*iter_result));
    ASSERT_EQ(1.5, ::portable_stl::get<1>(*iter_result));

    // == 3
    t_value_type const value3(3, 3.5);
    result = mp.insert(mp.end(), value3);
    ASSERT_TRUE(result);

    iter_result = result.value();

    ASSERT_EQ(::portable_stl::prev(mp.end()), iter_result);
    ASSERT_EQ(3, mp.size());
    ASSERT_EQ(3, ::portable_stl::get<0>(*iter_result));
    ASSERT_EQ(3.5, ::portable_stl::get<1>(*iter_result));

    // == 4
    t_value_type const value4(3, 3.5);
    result = mp.insert(mp.end(), value4);
    ASSERT_TRUE(result);

    iter_result = result.value();

    ASSERT_EQ(::portable_stl::prev(mp.end()), iter_result);
    ASSERT_EQ(3, mp.size());
    ASSERT_EQ(3, ::portable_stl::get<0>(*iter_result));
    ASSERT_EQ(3.5, ::portable_stl::get<1>(*iter_result));
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 3;
    t_allocator2 alloc(&stat);

    ::portable_stl::map<std::int32_t, double, t_compare, t_allocator2> mp(
      {
        {1, 1.5},
        {2, 2.5},
        {3, 3.5}
    },
      alloc);

    t_value_type const value(4, 4.5);
    auto               result = mp.insert(mp.end(), value);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // Strong guarantee
    ASSERT_EQ(3, mp.size());
  }
}

namespace test_map_helper {
template<class t_map, class t_value_like_type> void map_insert_pos_rv_test() {
  t_map mp;

  // == 1
  auto result = mp.insert(mp.end(), t_value_like_type(2, 2.5));
  ASSERT_TRUE(result);

  auto iter_result = result.value();

  ASSERT_EQ(mp.begin(), iter_result);
  ASSERT_EQ(1, mp.size());
  ASSERT_EQ(2, ::portable_stl::get<0>(*iter_result));
  ASSERT_EQ(2.5, ::portable_stl::get<1>(*iter_result));

  // == 2
  result = mp.insert(mp.end(), t_value_like_type(1, 1.5));
  ASSERT_TRUE(result);

  iter_result = result.value();

  ASSERT_EQ(mp.begin(), iter_result);
  ASSERT_EQ(2, mp.size());
  ASSERT_EQ(1, ::portable_stl::get<0>(*iter_result));
  ASSERT_EQ(1.5, ::portable_stl::get<1>(*iter_result));

  // == 3
  result = mp.insert(mp.end(), t_value_like_type(3, 3.5));
  ASSERT_TRUE(result);

  iter_result = result.value();

  ASSERT_EQ(::portable_stl::prev(mp.end()), iter_result);
  ASSERT_EQ(3, mp.size());
  ASSERT_EQ(3, ::portable_stl::get<0>(*iter_result));
  ASSERT_EQ(3.5, ::portable_stl::get<1>(*iter_result));

  // == 4
  result = mp.insert(mp.end(), t_value_like_type(3, 3.5));
  ASSERT_TRUE(result);

  iter_result = result.value();

  ASSERT_EQ(::portable_stl::prev(mp.end()), iter_result);
  ASSERT_EQ(3, mp.size());
  ASSERT_EQ(3, ::portable_stl::get<0>(*iter_result));
  ASSERT_EQ(3.5, ::portable_stl::get<1>(*iter_result));
}
} // namespace test_map_helper

// expected<iterator, portable_stl_error> insert(const_iterator pos, value_type &&value)
// expected<iterator, portable_stl_error> insert(const_iterator pos, t_like_value &&value)
TEST(map, insert_pos_rvalue_type) {
  static_cast<void>(test_info_);

  /**
   * @brief Move only alias.
   */
  using t_move_only = test_common_helper::MoveOnly;

  // value_type_like&&
  test_map_helper::map_insert_pos_rv_test<::portable_stl::map<std::int32_t, t_move_only>,
                                          ::portable_stl::tuple<std::int32_t, t_move_only>>();

  // value_type&&
  test_map_helper::map_insert_pos_rv_test<::portable_stl::map<std::int32_t, t_move_only>,
                                          ::portable_stl::tuple<std::int32_t const, t_move_only>>();

  // implicit value_type&&
  {
    ::portable_stl::map<std::int32_t, t_move_only> mp;

    // == 1
    auto result = mp.insert(mp.end(), {2, t_move_only(2)});
    ASSERT_TRUE(result);

    auto iter_result = result.value();

    ASSERT_EQ(mp.begin(), iter_result);
    ASSERT_EQ(1, mp.size());
    ASSERT_EQ(2, ::portable_stl::get<0>(*iter_result));
    ASSERT_EQ(2, ::portable_stl::get<1>(*iter_result));

    // == 2
    result = mp.insert(mp.end(), {1, t_move_only(1)});
    ASSERT_TRUE(result);

    iter_result = result.value();

    ASSERT_EQ(mp.begin(), iter_result);
    ASSERT_EQ(2, mp.size());
    ASSERT_EQ(1, ::portable_stl::get<0>(*iter_result));
    ASSERT_EQ(1.5, ::portable_stl::get<1>(*iter_result));

    // == 3
    result = mp.insert(mp.end(), {3, t_move_only(3)});
    ASSERT_TRUE(result);

    iter_result = result.value();

    ASSERT_EQ(::portable_stl::prev(mp.end()), iter_result);
    ASSERT_EQ(3, mp.size());
    ASSERT_EQ(3, ::portable_stl::get<0>(*iter_result));
    ASSERT_EQ(3, ::portable_stl::get<1>(*iter_result));

    // == 4
    result = mp.insert(mp.end(), {3, t_move_only(3)});
    ASSERT_TRUE(result);

    iter_result = result.value();

    ASSERT_EQ(::portable_stl::prev(mp.end()), iter_result);
    ASSERT_EQ(3, mp.size());
    ASSERT_EQ(3, ::portable_stl::get<0>(*iter_result));
    ASSERT_EQ(3, ::portable_stl::get<1>(*iter_result));
  }
}

// expected<void, portable_stl_error> insert(t_input_iterator first, t_input_iterator last);
TEST(map, insert_iter_iter) {
  static_cast<void>(test_info_);

  using t_value_type = ::portable_stl::tuple<std::int32_t, double>;

  t_value_type ar[] = {
    t_value_type(1, 1),
    t_value_type(1, 1.5),
    t_value_type(1, 2),
    t_value_type(2, 1),
    t_value_type(2, 1.5),
    t_value_type(2, 2),
    t_value_type(3, 1),
    t_value_type(3, 1.5),
    t_value_type(3, 2),
  };

  {
    t_map mp;
    auto  result = mp.insert(test_iterator_helper::tst_input_iterator<t_value_type *>(ar),
                            test_iterator_helper::tst_input_iterator<t_value_type *>(ar + sizeof(ar) / sizeof(ar[0])));

    ASSERT_TRUE(result);

    ASSERT_EQ(3, mp.size());
    ASSERT_EQ(::portable_stl::get<0>(*mp.begin()), 1);
    ASSERT_EQ(::portable_stl::get<1>(*mp.begin()), 1);
    ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin())), 2);
    ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin())), 1);
    ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)), 3);
    ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)), 1);
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 4;
    t_allocator2                                                       alloc(&stat);
    ::portable_stl::map<std::int32_t, double, t_compare, t_allocator2> mp(
      {
        {8, 8.5},
        {9, 9.5}
    },
      alloc);

    auto result = mp.insert(test_iterator_helper::tst_input_iterator<t_value_type *>(ar),
                            test_iterator_helper::tst_input_iterator<t_value_type *>(ar + sizeof(ar) / sizeof(ar[0])));

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    EXPECT_EQ(4, mp.size()); // only two successful insertion
  }
}

// expected<void, portable_stl_error> insert(initializer_list<value_type> init_list);
TEST(map, insert_initializer_list) {
  static_cast<void>(test_info_);

  t_map mp;
  auto  result = mp.insert({
    {3, 3.5},
    {2, 2.5},
    {1, 1.5},
  });

  ASSERT_TRUE(result);

  ASSERT_EQ(3, mp.size());
  ASSERT_EQ(::portable_stl::get<0>(*mp.begin()), 1);
  ASSERT_EQ(::portable_stl::get<1>(*mp.begin()), 1.5);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin())), 2);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin())), 2.5);
  ASSERT_EQ(::portable_stl::get<0>(*::portable_stl::next(mp.begin(), 2)), 3);
  ASSERT_EQ(::portable_stl::get<1>(*::portable_stl::next(mp.begin(), 2)), 3.5);
}

namespace test_map_helper {

template<class t_map>
typename t_map::node_type node_factory(typename t_map::key_type const &key, typename t_map::mapped_type const &mapped) {
  // tmp map
  t_map mp;

  // insert element (create node)
  auto insert_result = mp.insert({key, mapped});
  assert(insert_result);
  auto iter = insert_result.value();
  assert(::portable_stl::get<1>(iter));

  // get created node
  return mp.extract(::portable_stl::get<0>(iter));
}
} // namespace test_map_helper

// insert_return_type insert(node_type&&);
TEST(map, insert_node_type) {
  static_cast<void>(test_info_);

  /**
   * @brief Map alias.
   */
  using t_map2 = ::portable_stl::map<std::int32_t, std::int32_t>;

  t_map2 mp;

  auto *nf = &test_map_helper::node_factory<t_map2>;

  for (std::int32_t i{0}; i != 10; ++i) {
    typename t_map2::node_type node = nf(i, i + 1);
    ASSERT_FALSE(node.empty());

    typename t_map2::insert_return_type irt = mp.insert(std::move(node));

    ASSERT_TRUE(node.empty());
    ASSERT_TRUE(irt.inserted);
    ASSERT_TRUE(irt.node.empty());
    ASSERT_TRUE((::portable_stl::get<0>(*irt.position) == i) && (::portable_stl::get<1>(*irt.position) == (i + 1)));
  }

  ASSERT_EQ(mp.size(), 10);

  { // Insert empty node.
    typename t_map2::node_type def;
    auto                       irt = mp.insert(std::move(def));
    ASSERT_TRUE(def.empty());
    ASSERT_FALSE(irt.inserted);
    ASSERT_TRUE(irt.node.empty());
    ASSERT_EQ(irt.position, mp.end());
  }

  { // Insert duplicate node.
    typename t_map2::node_type dupl = nf(0, 42);
    auto                       irt  = mp.insert(std::move(dupl));
    ASSERT_TRUE(dupl.empty());
    ASSERT_FALSE(irt.inserted);
    ASSERT_FALSE(irt.node.empty());
    ASSERT_EQ(irt.position, mp.find(0));
    ASSERT_TRUE((irt.node.key() == 0) && (irt.node.mapped() == 42));
  }

  ASSERT_EQ(mp.size(), 10);

  for (std::int32_t i{0}; i != 10; ++i) {
    ASSERT_EQ(mp.count(i), 1);
    ASSERT_EQ(mp[i], i + 1);
  }
}

// insert_return_type insert(node_type&&);
TEST(map, insert_pos_node_type) {
  static_cast<void>(test_info_);

  /**
   * @brief Map alias.
   */
  using t_map2 = ::portable_stl::map<std::int32_t, std::int32_t>;

  t_map2 mp;

  auto *nf = &test_map_helper::node_factory<t_map2>;

  for (std::int32_t i{0}; i != 10; ++i) {
    typename t_map2::node_type node = nf(i, i + 1);
    ASSERT_FALSE(node.empty());
    std::size_t prev = mp.size();

    auto it = mp.insert(mp.end(), std::move(node));

    ASSERT_TRUE(node.empty());
    ASSERT_EQ(prev + 1, mp.size());
    ASSERT_EQ(::portable_stl::get<0>(*it), i);
    ASSERT_EQ(::portable_stl::get<1>(*it), i + 1);
  }

  ASSERT_EQ(mp.size(), 10);

  for (std::int32_t i{0}; i != 10; ++i) {
    ASSERT_EQ(mp.count(i), 1);
    ASSERT_EQ(mp[i], i + 1);
  }
}
// expected<tuple<iterator, bool>, portable_stl_error> emplace(Args&&... args);
TEST(map, emplace) {
  static_cast<void>(test_info_);

  /**
   * @brief Type alias.
   */
  using t_default_only  = test_common_helper::DefaultOnly;
  t_default_only::count = 0;

  {
    ::portable_stl::map<std::int32_t, t_default_only> mp;
    ASSERT_EQ(0, t_default_only::count);

    // == 1
    auto result = mp.emplace();
    ASSERT_TRUE(result);

    auto emplace_iter_bool = result.value();
    ASSERT_TRUE(::portable_stl::get<1>(emplace_iter_bool));

    ASSERT_EQ(mp.begin(), ::portable_stl::get<0>(emplace_iter_bool));
    ASSERT_EQ(1, mp.size());

    ASSERT_EQ(0, ::portable_stl::get<0>(*mp.begin()));
    ASSERT_EQ(t_default_only(), ::portable_stl::get<1>(*mp.begin()));

    ASSERT_EQ(1, t_default_only::count);

    // == 2
    result = mp.emplace(
      ::portable_stl::piecewise_construct_t{}, ::portable_stl::forward_as_tuple(1), ::portable_stl::forward_as_tuple());
    ASSERT_TRUE(result);

    emplace_iter_bool = result.value();
    ASSERT_TRUE(::portable_stl::get<1>(emplace_iter_bool));

    auto insert_iter = ::portable_stl::get<0>(emplace_iter_bool);
    ASSERT_EQ(::portable_stl::next(mp.begin()), insert_iter);
    ASSERT_EQ(2, mp.size());

    ASSERT_EQ(1, ::portable_stl::get<0>(*insert_iter));
    ASSERT_EQ(t_default_only(), ::portable_stl::get<1>(*insert_iter));

    ASSERT_EQ(2, t_default_only::count);

    // == 3 (unsuccess insertion)
    result = mp.emplace(
      ::portable_stl::piecewise_construct_t{}, ::portable_stl::forward_as_tuple(1), ::portable_stl::forward_as_tuple());
    ASSERT_TRUE(result);

    emplace_iter_bool = result.value();
    ASSERT_FALSE(::portable_stl::get<1>(emplace_iter_bool)); // false

    insert_iter = ::portable_stl::get<0>(emplace_iter_bool);
    ASSERT_EQ(::portable_stl::next(mp.begin()), insert_iter);
    ASSERT_EQ(2, mp.size());

    ASSERT_EQ(1, ::portable_stl::get<0>(*insert_iter));
    ASSERT_EQ(t_default_only(), ::portable_stl::get<1>(*insert_iter));

    ASSERT_EQ(2, t_default_only::count);
  }
  ASSERT_EQ(0, t_default_only::count);

  // bad allocation
  {
    using t_allocator
      = test_allocator_helper::test_allocator<::portable_stl::tuple<std::int32_t const, t_default_only>>;
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 2;
    t_allocator                                                               alloc(&stat);
    ::portable_stl::map<std::int32_t, t_default_only, t_compare, t_allocator> mp(alloc);
    mp.emplace(
      ::portable_stl::piecewise_construct_t{}, ::portable_stl::forward_as_tuple(5), ::portable_stl::forward_as_tuple());
    mp.emplace(
      ::portable_stl::piecewise_construct_t{}, ::portable_stl::forward_as_tuple(6), ::portable_stl::forward_as_tuple());
    auto ref_size = mp.size();

    auto result = mp.emplace(
      ::portable_stl::piecewise_construct_t{}, ::portable_stl::forward_as_tuple(1), ::portable_stl::forward_as_tuple());

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    EXPECT_EQ(ref_size, mp.size());
  }

  // class Two {
  //   std::int32_t m_int    = 0;
  //   double       m_double = 0.0;

  // public:
  //   Two() = default;
  //   Two(int int_value, double double_value) : m_int(int_value), m_double(double_value) {
  //   }
  // };

  {
    ::portable_stl::map<std::int32_t, test_common_helper::Emplaceable> mp;

    // == 1
    auto result = mp.emplace(
      ::portable_stl::piecewise_construct_t{}, ::portable_stl::forward_as_tuple(2), ::portable_stl::forward_as_tuple());
    ASSERT_TRUE(result);

    auto emplace_iter_bool = result.value();
    ASSERT_TRUE(::portable_stl::get<1>(emplace_iter_bool));

    auto insert_iter = ::portable_stl::get<0>(emplace_iter_bool);
    ASSERT_EQ(mp.begin(), insert_iter);
    ASSERT_EQ(1, mp.size());

    ASSERT_EQ(2, ::portable_stl::get<0>(*insert_iter));
    ASSERT_EQ(test_common_helper::Emplaceable(), ::portable_stl::get<1>(*insert_iter));

    // Two(1, 5.4);
    // int iiii = 5;
    // double dddd= 5.5;
    // ::portable_stl::tuple<int, Two> tpl1(::portable_stl::piecewise_construct_t{},
    // ::portable_stl::forward_as_tuple(1), ::portable_stl::forward_as_tuple(Two(1,2.5)));
    // ::portable_stl::tuple<int, Two> tpl2(::portable_stl::piecewise_construct_t{},
    // ::portable_stl::forward_as_tuple(1), ::portable_stl::forward_as_tuple(iiii, dddd));

    // std::pair<int, std::string> p{std::piecewise_construct, std::forward_as_tuple(1), std::forward_as_tuple(10,
    // 'a')};

    // ::portable_stl::tuple<std::int32_t, test_common_helper::Emplaceable> t_emp(
    //   ::portable_stl::piecewise_construct_t{},
    //   ::portable_stl::forward_as_tuple(2),
    //   ::portable_stl::forward_as_tuple(1, 2.5));

    // // == 2 (pair's piecewise constructor)
    // result = mp.emplace(
    //   ::portable_stl::piecewise_construct_t{}, ::portable_stl::forward_as_tuple(1),
    //   ::portable_stl::forward_as_tuple(2, 3.5));
    // ASSERT_TRUE(result);

    // emplace_iter_bool = result.value();
    // ASSERT_TRUE(::portable_stl::get<1>(emplace_iter_bool));

    // insert_iter = ::portable_stl::get<0>(emplace_iter_bool);
    // ASSERT_EQ(mp.begin(), insert_iter);
    // ASSERT_EQ(2, mp.size());

    // ASSERT_EQ(2, ::portable_stl::get<0>(*insert_iter));
    // ASSERT_EQ(test_common_helper::Emplaceable(2, 3.5), ::portable_stl::get<1>(*insert_iter));

    // // == 3
    // result = mp.emplace(
    //   ::portable_stl::piecewise_construct_t{}, ::portable_stl::forward_as_tuple(1),
    //   ::portable_stl::forward_as_tuple(2, 3.5));
    // ASSERT_TRUE(result);

    // emplace_iter_bool = result.value();
    // ASSERT_FALSE(::portable_stl::get<1>(emplace_iter_bool)); // false

    // ASSERT_EQ(2, mp.size());
    // insert_iter = ::portable_stl::get<0>(emplace_iter_bool);
    // ASSERT_EQ(mp.begin(), insert_iter);

    // ASSERT_EQ(1, ::portable_stl::get<0>(*insert_iter));
    // ASSERT_EQ(test_common_helper::Emplaceable(2, 3.5), ::portable_stl::get<1>(*insert_iter));
  }
}
