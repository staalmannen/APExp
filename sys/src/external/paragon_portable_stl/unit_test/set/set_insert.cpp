// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="set_insert.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <portable_stl/set/set.h>
#include <portable_stl/string/string.h>

#include "../common/default_only.h"
#include "../common/emplaceable.h"
#include "../common/move_only.h"
#include "../common/test_allocator.h"
#include "../common/test_compare.h"
#include "../iterator_helper.h"

using t_allocator2 = test_allocator_helper::test_allocator<std::int32_t>;

using t_compare = test_common_helper::test_less<std::int32_t>;

using t_set = ::portable_stl::set<std::int32_t>;

// pair<iterator, bool> insert(const value_type& v);
TEST(set, insert_value_type) {
  static_cast<void>(test_info_);

  {
    t_set st;

    // == 1
    std::int32_t const value1{2};
    auto               result = st.insert(value1);
    ASSERT_TRUE(result);

    auto iter_bool_result = result.value();
    ASSERT_TRUE(::portable_stl::get<1>(iter_bool_result));
    auto insert_iter = ::portable_stl::get<0>(iter_bool_result);

    ASSERT_EQ(st.begin(), insert_iter);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ(2, *insert_iter);

    // == 2
    std::int32_t const value2{1};
    result = st.insert(value2);
    ASSERT_TRUE(result);

    iter_bool_result = result.value();
    ASSERT_TRUE(::portable_stl::get<1>(iter_bool_result));
    insert_iter = ::portable_stl::get<0>(iter_bool_result);

    ASSERT_EQ(st.begin(), insert_iter);
    ASSERT_EQ(2, st.size());
    ASSERT_EQ(1, *insert_iter);

    // == 3
    std::int32_t const value3{3};
    result = st.insert(value3);
    ASSERT_TRUE(result);

    iter_bool_result = result.value();
    ASSERT_TRUE(::portable_stl::get<1>(iter_bool_result));
    insert_iter = ::portable_stl::get<0>(iter_bool_result);

    ASSERT_EQ(::portable_stl::prev(st.end()), insert_iter);
    ASSERT_EQ(3, st.size());
    ASSERT_EQ(3, *insert_iter);
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 3;
    t_allocator2 alloc(&stat);

    ::portable_stl::set<std::int32_t, t_compare, t_allocator2> st({1, 2, 3}, alloc);

    std::int32_t const value{4};
    auto               result = st.insert(value);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // Strong guarantee
    ASSERT_EQ(3, st.size());
  }
}

// expected<tuple<iterator, bool>, portable_stl_error> insert(value_type &&value)
TEST(set, insert_rvalue_type) {
  static_cast<void>(test_info_);

  /**
   * @brief Move only alias.
   */
  using t_move_only = test_common_helper::MoveOnly;

  ::portable_stl::set<t_move_only> st;

  // == 1
  auto result = st.insert(t_move_only(2));
  ASSERT_TRUE(result);

  auto iter_bool_result = result.value();
  ASSERT_TRUE(::portable_stl::get<1>(iter_bool_result));
  auto insert_iter = ::portable_stl::get<0>(iter_bool_result);

  ASSERT_EQ(st.begin(), insert_iter);
  ASSERT_EQ(1, st.size());
  ASSERT_EQ(2, *insert_iter);

  // == 2
  result = st.insert(t_move_only(1));
  ASSERT_TRUE(result);

  iter_bool_result = result.value();
  ASSERT_TRUE(::portable_stl::get<1>(iter_bool_result));
  insert_iter = ::portable_stl::get<0>(iter_bool_result);

  ASSERT_EQ(st.begin(), insert_iter);
  ASSERT_EQ(2, st.size());
  ASSERT_EQ(1, *insert_iter);

  // == 3
  result = st.insert(t_move_only(3));
  ASSERT_TRUE(result);

  iter_bool_result = result.value();
  ASSERT_TRUE(::portable_stl::get<1>(iter_bool_result));
  insert_iter = ::portable_stl::get<0>(iter_bool_result);

  ASSERT_EQ(::portable_stl::prev(st.end()), insert_iter);
  ASSERT_EQ(3, st.size());
  ASSERT_EQ(3, *insert_iter);

  // == 4
  result = st.insert(t_move_only(3));
  ASSERT_TRUE(result);

  iter_bool_result = result.value();
  ASSERT_FALSE(::portable_stl::get<1>(iter_bool_result));
  insert_iter = ::portable_stl::get<0>(iter_bool_result);

  ASSERT_EQ(::portable_stl::prev(st.end()), insert_iter);
  ASSERT_EQ(3, st.size());
  ASSERT_EQ(3, *insert_iter);
}

// expected<iterator, portable_stl_error> insert(const_iterator position, const value_type& v)
TEST(set, insert_pos_value_type) {
  static_cast<void>(test_info_);

  {
    t_set st;

    // == 1
    std::int32_t const value1{2};
    auto               result = st.insert(st.end(), value1);
    ASSERT_TRUE(result);

    auto iter_result = result.value();

    ASSERT_EQ(st.begin(), iter_result);
    ASSERT_EQ(1, st.size());
    ASSERT_EQ(2, *iter_result);

    // == 2
    std::int32_t const value2{1};
    result = st.insert(st.end(), value2);
    ASSERT_TRUE(result);

    iter_result = result.value();

    ASSERT_EQ(st.begin(), iter_result);
    ASSERT_EQ(2, st.size());
    ASSERT_EQ(1, *iter_result);

    // == 3
    std::int32_t const value3{3};
    result = st.insert(st.end(), value3);
    ASSERT_TRUE(result);

    iter_result = result.value();

    ASSERT_EQ(::portable_stl::prev(st.end()), iter_result);
    ASSERT_EQ(3, st.size());
    ASSERT_EQ(3, *iter_result);

    // == 4
    std::int32_t const value4{3};
    result = st.insert(st.end(), value4);
    ASSERT_TRUE(result);

    iter_result = result.value();

    ASSERT_EQ(::portable_stl::prev(st.end()), iter_result);
    ASSERT_EQ(3, st.size());
    ASSERT_EQ(3, *iter_result);
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 3;
    t_allocator2 alloc(&stat);

    ::portable_stl::set<std::int32_t, t_compare, t_allocator2> st({1, 2, 3}, alloc);

    std::int32_t const value{4};
    auto               result = st.insert(st.end(), value);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // Strong guarantee
    ASSERT_EQ(3, st.size());
  }
}

// expected<iterator, portable_stl_error> insert(const_iterator pos, value_type &&value)
TEST(set, insert_pos_rvalue_type) {
  static_cast<void>(test_info_);

  /**
   * @brief Move only alias.
   */
  using t_move_only = test_common_helper::MoveOnly;

  ::portable_stl::set<t_move_only> st;

  // == 1
  auto result = st.insert(st.end(), t_move_only(2));
  ASSERT_TRUE(result);

  auto iter_result = result.value();

  ASSERT_EQ(st.begin(), iter_result);
  ASSERT_EQ(1, st.size());
  ASSERT_EQ(2, *iter_result);

  // == 2
  result = st.insert(st.end(), t_move_only(1));
  ASSERT_TRUE(result);

  iter_result = result.value();

  ASSERT_EQ(st.begin(), iter_result);
  ASSERT_EQ(2, st.size());
  ASSERT_EQ(1, *iter_result);

  // == 3
  result = st.insert(st.end(), t_move_only(3));
  ASSERT_TRUE(result);

  iter_result = result.value();

  ASSERT_EQ(::portable_stl::prev(st.end()), iter_result);
  ASSERT_EQ(3, st.size());
  ASSERT_EQ(3, *iter_result);

  // == 4
  result = st.insert(st.end(), t_move_only(3));
  ASSERT_TRUE(result);

  iter_result = result.value();

  ASSERT_EQ(::portable_stl::prev(st.end()), iter_result);
  ASSERT_EQ(3, st.size());
  ASSERT_EQ(3, *iter_result);
}

// expected<void, portable_stl_error> insert(t_input_iterator first, t_input_iterator last);
TEST(set, insert_iter_iter) {
  static_cast<void>(test_info_);

  std::int32_t ar[] = {1, 2, 3, 1, 2, 3, 1, 2, 3};

  {
    t_set st;
    auto  result = st.insert(test_iterator_helper::tst_input_iterator<std::int32_t *>(ar),
                            test_iterator_helper::tst_input_iterator<std::int32_t *>(ar + sizeof(ar) / sizeof(ar[0])));

    ASSERT_TRUE(result);

    ASSERT_EQ(3, st.size());
    ASSERT_EQ(*::portable_stl::next(st.begin(), 0), 1);
    ASSERT_EQ(*::portable_stl::next(st.begin(), 1), 2);
    ASSERT_EQ(*::portable_stl::next(st.begin(), 2), 3);
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 4;
    t_allocator2                                               alloc(&stat);
    ::portable_stl::set<std::int32_t, t_compare, t_allocator2> st({8, 9}, alloc);

    auto result = st.insert(test_iterator_helper::tst_input_iterator<std::int32_t *>(ar),
                            test_iterator_helper::tst_input_iterator<std::int32_t *>(ar + sizeof(ar) / sizeof(ar[0])));

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    EXPECT_EQ(4, st.size()); // only two successful insertion
  }
}

// expected<void, portable_stl_error> insert(initializer_list<value_type> init_list);
TEST(set, insert_initializer_list) {
  static_cast<void>(test_info_);

  t_set st;
  auto  result = st.insert({1, 2, 3, 1, 2, 3, 1, 2, 3});

  ASSERT_TRUE(result);

  ASSERT_EQ(3, st.size());
  ASSERT_EQ(*::portable_stl::next(st.begin(), 0), 1);
  ASSERT_EQ(*::portable_stl::next(st.begin(), 1), 2);
  ASSERT_EQ(*::portable_stl::next(st.begin(), 2), 3);
}

namespace test_set_helper {

template<class t_set> typename t_set::node_type node_factory(typename t_set::key_type const &key) {
  static t_set st;
  auto         result = st.insert(key);
  auto         iter   = result.value();

  assert(::portable_stl::get<1>(iter));
  return st.extract(::portable_stl::get<0>(iter));
}
} // namespace test_set_helper

// insert_return_type insert(node_type&&);
TEST(set, insert_node_type) {
  static_cast<void>(test_info_);

  t_set st;

  auto *nf = &test_set_helper::node_factory<t_set>;

  for (std::int32_t i{0}; i != 10; ++i) {
    typename t_set::node_type node = nf(i);
    ASSERT_FALSE(node.empty());

    auto irt = st.insert(std::move(node));

    ASSERT_TRUE(node.empty());
    ASSERT_TRUE(irt.inserted);
    ASSERT_TRUE(irt.node.empty());
    ASSERT_EQ(i, *irt.position);
  }

  ASSERT_EQ(st.size(), 10);

  { // Insert empty node.
    typename t_set::node_type def;
    auto                      irt = st.insert(std::move(def));
    ASSERT_TRUE(def.empty());
    ASSERT_FALSE(irt.inserted);
    ASSERT_TRUE(irt.node.empty());
    ASSERT_EQ(irt.position, st.end());
  }

  { // Insert duplicate node.
    typename t_set::node_type dupl = nf(0);
    auto                      irt  = st.insert(std::move(dupl));
    ASSERT_TRUE(dupl.empty());
    ASSERT_FALSE(irt.inserted);
    ASSERT_FALSE(irt.node.empty());
    ASSERT_EQ(irt.position, st.find(0));
    ASSERT_EQ(0, irt.node.value());
  }

  ASSERT_EQ(st.size(), 10);

  for (std::int32_t i{0}; i != 10; ++i) {
    ASSERT_EQ(1, st.count(i));
  }
}

// insert_return_type insert(node_type&&);
TEST(set, insert_pos_node_type) {
  static_cast<void>(test_info_);

  t_set st;

  auto *nf = &test_set_helper::node_factory<t_set>;

  for (std::int32_t i{0}; i != 10; ++i) {
    typename t_set::node_type node = nf(i);
    ASSERT_FALSE(node.empty());
    std::size_t prev = st.size();

    auto iter = st.insert(st.end(), std::move(node));

    ASSERT_TRUE(node.empty());
    ASSERT_EQ(prev + 1, st.size());
    ASSERT_EQ(i, *iter);
  }

  ASSERT_EQ(st.size(), 10);

  for (std::int32_t i{0}; i != 10; ++i) {
    ASSERT_EQ(1, st.count(i));
  }
}

// expected<tuple<iterator, bool>, portable_stl_error> emplace(Args&&... args);
TEST(set, emplace) {
  static_cast<void>(test_info_);

  /**
   * @brief Type alias.
   */
  using t_default_only  = test_common_helper::DefaultOnly;
  t_default_only::count = 0;

  // DefaultOnly
  {
    ::portable_stl::set<t_default_only> st;
    ASSERT_EQ(0, t_default_only::count);

    // == 1
    auto result = st.emplace();
    ASSERT_TRUE(result);

    auto emplace_iter_bool = result.value();
    ASSERT_TRUE(::portable_stl::get<1>(emplace_iter_bool));

    ASSERT_EQ(st.begin(), ::portable_stl::get<0>(emplace_iter_bool));
    ASSERT_EQ(1, st.size());

    ASSERT_EQ(t_default_only(), *st.begin());
    ASSERT_EQ(1, t_default_only::count);

    // == 2 (same default)
    result = st.emplace();
    ASSERT_TRUE(result);

    emplace_iter_bool = result.value();
    ASSERT_FALSE(::portable_stl::get<1>(emplace_iter_bool));

    ASSERT_EQ(st.begin(), ::portable_stl::get<0>(emplace_iter_bool));
    ASSERT_EQ(1, st.size());

    ASSERT_EQ(t_default_only(), *st.begin());
    ASSERT_EQ(1, t_default_only::count);
  }
  ASSERT_EQ(0, t_default_only::count);

  // bad allocation
  {
    using t_allocator = test_allocator_helper::test_allocator<t_default_only>;
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    t_allocator                                                                                     alloc(&stat);
    ::portable_stl::set<t_default_only, test_common_helper::test_less<t_default_only>, t_allocator> st(alloc);

    auto result = st.emplace();

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }

  // Emplaceable
  {
    ::portable_stl::set<test_common_helper::Emplaceable> st;

    // == 1
    auto result = st.emplace();
    ASSERT_TRUE(result);

    auto emplace_iter_bool = result.value();
    ASSERT_TRUE(::portable_stl::get<1>(emplace_iter_bool));
    ASSERT_EQ(st.begin(), ::portable_stl::get<0>(emplace_iter_bool));
    ASSERT_EQ(1, st.size());
    ASSERT_EQ(test_common_helper::Emplaceable(), *st.begin());

    // == 2
    result = st.emplace(2, 3.5);
    ASSERT_TRUE(result);

    emplace_iter_bool = result.value();
    ASSERT_TRUE(::portable_stl::get<1>(emplace_iter_bool));
    ASSERT_EQ(::portable_stl::next(st.begin()), ::portable_stl::get<0>(emplace_iter_bool));
    ASSERT_EQ(2, st.size());
    ASSERT_EQ(test_common_helper::Emplaceable(2, 3.5), *::portable_stl::get<0>(emplace_iter_bool));

    // == 3
    result = st.emplace(2, 3.5);
    ASSERT_TRUE(result);

    emplace_iter_bool = result.value();
    ASSERT_FALSE(::portable_stl::get<1>(emplace_iter_bool));
    ASSERT_EQ(::portable_stl::next(st.begin()), ::portable_stl::get<0>(emplace_iter_bool));
    ASSERT_EQ(2, st.size());
    ASSERT_EQ(test_common_helper::Emplaceable(2, 3.5), *::portable_stl::get<0>(emplace_iter_bool));
  }

  // int
  {
    ::portable_stl::set<std::int32_t> st;

    auto result = st.emplace(2);
    ASSERT_TRUE(result);

    auto emplace_iter_bool = result.value();
    ASSERT_TRUE(::portable_stl::get<1>(emplace_iter_bool));
    ASSERT_EQ(st.begin(), ::portable_stl::get<0>(emplace_iter_bool));
    ASSERT_EQ(1, st.size());
    ASSERT_EQ(2, *::portable_stl::get<0>(emplace_iter_bool));
  }
}

// iterator emplace_hint(const_iterator hint_pos, t_args &&...args)
TEST(set, emplace_hint) {
  static_cast<void>(test_info_);

  /**
   * @brief Type alias.
   */
  using t_default_only  = test_common_helper::DefaultOnly;
  t_default_only::count = 0;

  // DefaultOnly
  {
    ::portable_stl::set<t_default_only> st;
    ASSERT_EQ(0, t_default_only::count);

    // == 1
    auto result = st.emplace_hint(st.cend());
    ASSERT_TRUE(result);

    auto iter = result.value();

    ASSERT_EQ(st.begin(), iter);
    ASSERT_EQ(1, st.size());

    ASSERT_EQ(t_default_only(), *st.begin());
    ASSERT_EQ(1, t_default_only::count);

    // == 2 (same default)
    result = st.emplace_hint(st.cbegin());
    ASSERT_TRUE(result);

    iter = result.value();

    ASSERT_EQ(st.begin(), iter);
    ASSERT_EQ(1, st.size());

    ASSERT_EQ(t_default_only(), *st.begin());
    ASSERT_EQ(1, t_default_only::count);
  }
  ASSERT_EQ(0, t_default_only::count);

  // bad allocation
  {
    using t_allocator = test_allocator_helper::test_allocator<t_default_only>;
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    t_allocator                                                                                     alloc(&stat);
    ::portable_stl::set<t_default_only, test_common_helper::test_less<t_default_only>, t_allocator> st(alloc);

    auto result = st.emplace_hint(st.cbegin());

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }

//   // Emplaceable
//   {
//     ::portable_stl::set<test_common_helper::Emplaceable> st;

//     // == 1
//     auto result = st.emplace_hint(st.cend());
//     ASSERT_TRUE(result);

//     auto iter = result.value();
//     ASSERT_EQ(st.begin(), iter);
//     ASSERT_EQ(1, st.size());
//     ASSERT_EQ(test_common_helper::Emplaceable(), *st.begin());

//     // == 2
//     result = st.emplace_hint(st.cend(), 2, 3.5);
//     ASSERT_TRUE(result);

//     iter = result.value();
//     ASSERT_EQ(::portable_stl::next(st.begin()), iter);
//     ASSERT_EQ(2, st.size());
//     ASSERT_EQ(test_common_helper::Emplaceable(2, 3.5), *iter);

//     // == 3
//     result = st.emplace_hint(st.cbegin(), 3.5);
//     ASSERT_TRUE(result);

//     iter = result.value();
//     ASSERT_EQ(::portable_stl::next(st.begin()), iter);
//     ASSERT_EQ(2, st.size());
//     ASSERT_EQ(test_common_helper::Emplaceable(2, 3.5), *iter);
//   }

//   // int
//   {
//     ::portable_stl::set<std::int32_t> st;

//     auto result = st.emplace_hint(st.cend(), 2);
//     ASSERT_TRUE(result);

//     auto iter = result.value();
//     ASSERT_EQ(st.begin(), iter);
//     ASSERT_EQ(1, st.size());
//     ASSERT_EQ(2, *iter);
//   }
}
