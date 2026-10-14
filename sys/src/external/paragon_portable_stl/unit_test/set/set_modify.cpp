// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="set_modify.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

// #include <cmath>
#include <portable_stl/ranges/begin.h>
#include <portable_stl/ranges/end.h>
#include <portable_stl/set/set.h>
// #include <portable_stl/string/string.h>

#include "../common/counter.h"
// #include "../common/default_only.h"
// #include "../common/emplaceable.h"
// #include "../common/move_only.h"
#include "../common/test_allocator.h"
#include "../common/test_compare.h"
// #include "../iterator_helper.h"

using t_allocator2 = test_allocator_helper::test_allocator<std::int32_t>;

using t_compare = test_common_helper::test_less<std::int32_t>;

using t_set = ::portable_stl::set<std::int32_t>;

// [erase]

// size_type erase(const Key& key);
TEST(set, erase_key) {
  static_cast<void>(test_info_);

  ::portable_stl::set<std::int32_t> st{1, 2, 3, 4, 5, 6, 7, 8};

  ASSERT_EQ(8, st.size());

  auto removed_cnt = st.erase(9);
  ASSERT_EQ(0, removed_cnt);
  ASSERT_EQ(8, st.size());

  ASSERT_EQ(1, *::portable_stl::next(st.begin(), 0));
  ASSERT_EQ(2, *::portable_stl::next(st.begin(), 1));
  ASSERT_EQ(3, *::portable_stl::next(st.begin(), 2));
  ASSERT_EQ(4, *::portable_stl::next(st.begin(), 3));
  ASSERT_EQ(5, *::portable_stl::next(st.begin(), 4));
  ASSERT_EQ(6, *::portable_stl::next(st.begin(), 5));
  ASSERT_EQ(7, *::portable_stl::next(st.begin(), 6));
  ASSERT_EQ(8, *::portable_stl::next(st.begin(), 7));

  removed_cnt = st.erase(4);
  ASSERT_EQ(1, removed_cnt);
  ASSERT_EQ(7, st.size());

  ASSERT_EQ(1, *::portable_stl::next(st.begin(), 0));
  ASSERT_EQ(2, *::portable_stl::next(st.begin(), 1));
  ASSERT_EQ(3, *::portable_stl::next(st.begin(), 2));
  ASSERT_EQ(5, *::portable_stl::next(st.begin(), 3));
  ASSERT_EQ(6, *::portable_stl::next(st.begin(), 4));
  ASSERT_EQ(7, *::portable_stl::next(st.begin(), 5));
  ASSERT_EQ(8, *::portable_stl::next(st.begin(), 6));

  removed_cnt = st.erase(1);
  ASSERT_EQ(1, removed_cnt);
  ASSERT_EQ(6, st.size());

  ASSERT_EQ(2, *::portable_stl::next(st.begin(), 0));
  ASSERT_EQ(3, *::portable_stl::next(st.begin(), 1));
  ASSERT_EQ(5, *::portable_stl::next(st.begin(), 2));
  ASSERT_EQ(6, *::portable_stl::next(st.begin(), 3));
  ASSERT_EQ(7, *::portable_stl::next(st.begin(), 4));
  ASSERT_EQ(8, *::portable_stl::next(st.begin(), 5));

  removed_cnt = st.erase(8);
  ASSERT_EQ(1, removed_cnt);
  ASSERT_EQ(5, st.size());

  ASSERT_EQ(2, *::portable_stl::next(st.begin(), 0));
  ASSERT_EQ(3, *::portable_stl::next(st.begin(), 1));
  ASSERT_EQ(5, *::portable_stl::next(st.begin(), 2));
  ASSERT_EQ(6, *::portable_stl::next(st.begin(), 3));
  ASSERT_EQ(7, *::portable_stl::next(st.begin(), 4));

  removed_cnt = st.erase(3);
  ASSERT_EQ(1, removed_cnt);
  ASSERT_EQ(4, st.size());

  ASSERT_EQ(2, *::portable_stl::next(st.begin(), 0));
  ASSERT_EQ(5, *::portable_stl::next(st.begin(), 1));
  ASSERT_EQ(6, *::portable_stl::next(st.begin(), 2));
  ASSERT_EQ(7, *::portable_stl::next(st.begin(), 3));

  removed_cnt = st.erase(6);
  ASSERT_EQ(1, removed_cnt);
  ASSERT_EQ(3, st.size());

  ASSERT_EQ(2, *::portable_stl::next(st.begin(), 0));
  ASSERT_EQ(5, *::portable_stl::next(st.begin(), 1));
  ASSERT_EQ(7, *::portable_stl::next(st.begin(), 2));

  removed_cnt = st.erase(7);
  ASSERT_EQ(1, removed_cnt);
  ASSERT_EQ(2, st.size());

  ASSERT_EQ(2, *::portable_stl::next(st.begin(), 0));
  ASSERT_EQ(5, *::portable_stl::next(st.begin(), 1));

  removed_cnt = st.erase(2);
  ASSERT_EQ(1, removed_cnt);
  ASSERT_EQ(1, st.size());

  ASSERT_EQ(5, *::portable_stl::next(st.begin(), 0));

  removed_cnt = st.erase(5);
  ASSERT_EQ(1, removed_cnt);
  ASSERT_EQ(0, st.size());
}

// iterator erase(const_iterator position);
TEST(set, erase_position) {
  static_cast<void>(test_info_);

  ::portable_stl::set<std::int32_t> st{1, 2, 3, 4, 5, 6, 7, 8};

  ASSERT_EQ(8, st.size());

  auto iter = st.erase(::portable_stl::next(st.cbegin(), 3));
  ASSERT_EQ(iter, ::portable_stl::next(st.begin(), 3));
  ASSERT_EQ(7, st.size());

  ASSERT_EQ(1, *::portable_stl::next(st.begin(), 0));
  ASSERT_EQ(2, *::portable_stl::next(st.begin(), 1));
  ASSERT_EQ(3, *::portable_stl::next(st.begin(), 2));
  ASSERT_EQ(5, *::portable_stl::next(st.begin(), 3));
  ASSERT_EQ(6, *::portable_stl::next(st.begin(), 4));
  ASSERT_EQ(7, *::portable_stl::next(st.begin(), 5));
  ASSERT_EQ(8, *::portable_stl::next(st.begin(), 6));

  iter = st.erase(::portable_stl::next(st.cbegin(), 0));
  ASSERT_EQ(iter, st.begin());
  ASSERT_EQ(6, st.size());

  ASSERT_EQ(2, *::portable_stl::next(st.begin(), 0));
  ASSERT_EQ(3, *::portable_stl::next(st.begin(), 1));
  ASSERT_EQ(5, *::portable_stl::next(st.begin(), 2));
  ASSERT_EQ(6, *::portable_stl::next(st.begin(), 3));
  ASSERT_EQ(7, *::portable_stl::next(st.begin(), 4));
  ASSERT_EQ(8, *::portable_stl::next(st.begin(), 5));

  iter = st.erase(::portable_stl::next(st.cbegin(), 5));
  ASSERT_EQ(iter, st.end());
  ASSERT_EQ(5, st.size());

  ASSERT_EQ(2, *::portable_stl::next(st.begin(), 0));
  ASSERT_EQ(3, *::portable_stl::next(st.begin(), 1));
  ASSERT_EQ(5, *::portable_stl::next(st.begin(), 2));
  ASSERT_EQ(6, *::portable_stl::next(st.begin(), 3));
  ASSERT_EQ(7, *::portable_stl::next(st.begin(), 4));

  iter = st.erase(::portable_stl::next(st.begin(), 1));
  ASSERT_EQ(iter, ::portable_stl::next(st.begin()));
  ASSERT_EQ(4, st.size());

  ASSERT_EQ(2, *::portable_stl::next(st.begin(), 0));
  ASSERT_EQ(5, *::portable_stl::next(st.begin(), 1));
  ASSERT_EQ(6, *::portable_stl::next(st.begin(), 2));
  ASSERT_EQ(7, *::portable_stl::next(st.begin(), 3));

  iter = st.erase(::portable_stl::next(st.begin(), 2));
  ASSERT_EQ(iter, ::portable_stl::next(st.begin(), 2));
  ASSERT_EQ(3, st.size());

  ASSERT_EQ(2, *::portable_stl::next(st.begin(), 0));
  ASSERT_EQ(5, *::portable_stl::next(st.begin(), 1));
  ASSERT_EQ(7, *::portable_stl::next(st.begin(), 2));

  iter = st.erase(::portable_stl::next(st.cbegin(), 2));
  ASSERT_EQ(iter, ::portable_stl::next(st.begin(), 2));
  ASSERT_EQ(2, st.size());

  ASSERT_EQ(2, *::portable_stl::next(st.begin(), 0));
  ASSERT_EQ(5, *::portable_stl::next(st.begin(), 1));

  iter = st.erase(::portable_stl::next(st.cbegin(), 0));
  ASSERT_EQ(iter, ::portable_stl::next(st.begin(), 0));
  ASSERT_EQ(1, st.size());

  ASSERT_EQ(5, *::portable_stl::next(st.begin(), 0));

  iter = st.erase(st.cbegin());
  ASSERT_EQ(iter, st.cbegin());
  ASSERT_EQ(iter, st.end());
  ASSERT_EQ(0, st.size());
}

// iterator erase(const_iterator first, const_iterator last);
TEST(set, erase_iter_iter) {
  static_cast<void>(test_info_);

  ::portable_stl::set<std::int32_t> st{1, 2, 3, 4, 5, 6, 7, 8};

  ASSERT_EQ(8, st.size());

  auto iter = st.erase(st.begin(), st.begin());
  ASSERT_EQ(iter, st.begin());
  ASSERT_EQ(8, st.size());

  ASSERT_EQ(1, *::portable_stl::next(st.begin(), 0));
  ASSERT_EQ(2, *::portable_stl::next(st.begin(), 1));
  ASSERT_EQ(3, *::portable_stl::next(st.begin(), 2));
  ASSERT_EQ(4, *::portable_stl::next(st.begin(), 3));
  ASSERT_EQ(5, *::portable_stl::next(st.begin(), 4));
  ASSERT_EQ(6, *::portable_stl::next(st.begin(), 5));
  ASSERT_EQ(7, *::portable_stl::next(st.begin(), 6));
  ASSERT_EQ(8, *::portable_stl::next(st.begin(), 7));

  iter = st.erase(st.cbegin(), ::portable_stl::next(st.cbegin(), 2));
  ASSERT_EQ(iter, st.begin());
  ASSERT_EQ(6, st.size());

  ASSERT_EQ(3, *::portable_stl::next(st.begin(), 0));
  ASSERT_EQ(4, *::portable_stl::next(st.begin(), 1));
  ASSERT_EQ(5, *::portable_stl::next(st.begin(), 2));
  ASSERT_EQ(6, *::portable_stl::next(st.begin(), 3));
  ASSERT_EQ(7, *::portable_stl::next(st.begin(), 4));
  ASSERT_EQ(8, *::portable_stl::next(st.begin(), 5));

  iter = st.erase(::portable_stl::next(st.cbegin(), 2), ::portable_stl::next(st.cbegin(), 6));
  ASSERT_EQ(iter, ::portable_stl::next(st.begin(), 2));
  ASSERT_EQ(2, st.size());

  ASSERT_EQ(3, *::portable_stl::next(st.begin(), 0));
  ASSERT_EQ(4, *::portable_stl::next(st.begin(), 1));

  iter = st.erase(st.cbegin(), st.cend());
  ASSERT_EQ(iter, st.begin());
  ASSERT_EQ(iter, st.end());
  ASSERT_EQ(0, st.size());
}

namespace test_set_helper {
template<class t_set, class t_key_type_iter>
void test_extract_key(t_set &st, t_key_type_iter first, t_key_type_iter last) {
  std::size_t sz{st.size()};
  ASSERT_EQ(sz, static_cast<std::size_t>(::portable_stl::distance(first, last)));

  for (t_key_type_iter copy{first}; copy != last; ++copy) {
    typename t_set::node_type t = st.extract(*copy);
    ASSERT_FALSE(t.empty());
    --sz;
    ASSERT_EQ(t.value(), *copy);
    ASSERT_EQ(t.get_allocator(), st.get_allocator());
    ASSERT_EQ(sz, st.size());
  }

  ASSERT_EQ(0, st.size());

  for (t_key_type_iter copy = first; copy != last; ++copy) {
    typename t_set::node_type t = st.extract(*copy);
    ASSERT_TRUE(t.empty());
  }
}

template<class t_set> void test_extract_iter(t_set &st) {
  auto sz = st.size();

  for (auto iter = st.cbegin(); iter != st.cend();) {
    auto                      key_value = *iter;
    typename t_set::node_type t         = st.extract(iter++);
    --sz;

    ASSERT_EQ(t.value(), key_value);
    ASSERT_EQ(t.get_allocator(), st.get_allocator());
    ASSERT_EQ(sz, st.size());
  }

  ASSERT_EQ(st.size(), 0);
}

} // namespace test_set_helper

// node_type extract(key_type const&);
TEST(set, extract_key) {
  static_cast<void>(test_info_);

  // using t_set_value_type2 = ::portable_stl::tuple<std::int32_t const, std::int32_t>;

  {
    ::portable_stl::set<std::int32_t> st{1, 2, 3, 4, 5, 6};

    std::int32_t keys[] = {1, 2, 3, 4, 5, 6};
    test_set_helper::test_extract_key(st, ::portable_stl::ranges::begin(keys), ::portable_stl::ranges::end(keys));
  }

  {
    ::portable_stl::set<test_common_helper::Counter<std::int32_t>> st{1, 2, 3, 4, 5, 6};
    {
      test_common_helper::Counter<std::int32_t> keys[] = {1, 2, 3, 4, 5, 6};
      ASSERT_EQ(6 + 6, test_common_helper::Counter_base::gConstructed);

      test_set_helper::test_extract_key(st, std::begin(keys), std::end(keys));
    }
    assert(test_common_helper::Counter_base::gConstructed == 0);
  }
}

// node_type extract(const_iterator);
TEST(set, extract_iter) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::set<std::int32_t> st{1, 2, 3, 4, 5, 6};
    test_set_helper::test_extract_iter(st);
  }

  {
    ::portable_stl::set<test_common_helper::Counter<std::int32_t>> st{1, 2, 3, 4, 5, 6};

    ASSERT_EQ(test_common_helper::Counter_base::gConstructed, 6);

    test_set_helper::test_extract_iter(st);

    ASSERT_EQ(test_common_helper::Counter_base::gConstructed, 0);
  }
}

namespace test_set_helper {
template<class t_set> bool set_equal(t_set const &set, t_set other) {
  return set == other;
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
} // namespace test_set_helper

// template <class C2> void merge(set<key_type, C2, allocator_type>& source);
// template <class C2> void merge(set<key_type, C2, allocator_type>&& source);
TEST(set, merge) {
  static_cast<void>(test_info_);

  // lvalue
  {
    ::portable_stl::set<std::int32_t> src{1, 3, 5};
    ::portable_stl::set<std::int32_t> dst{2, 4, 5};

    dst.merge(src);

    ASSERT_TRUE(test_set_helper::set_equal(src, {5}));
    ASSERT_TRUE(test_set_helper::set_equal(dst, {1, 2, 3, 4, 5}));
  }

  // rvalue
  {
    ::portable_stl::set<std::int32_t> src{1, 3, 5};
    ::portable_stl::set<std::int32_t> dst{2, 4, 5};

    dst.merge(std::move(src));

    ASSERT_TRUE(test_set_helper::set_equal(src, {5}));
    ASSERT_TRUE(test_set_helper::set_equal(dst, {1, 2, 3, 4, 5}));
  }

  // throw by comparator
  {
    bool do_throw = false;

    /**
     * @brief Map alias.
     */
    using t_set2 = ::portable_stl::set<test_common_helper::Counter<std::int32_t>, test_set_helper::throw_comparator>;

    t_set2 src({1, 3, 5}, test_set_helper::throw_comparator(do_throw));
    t_set2 dst({2, 4, 5}, test_set_helper::throw_comparator(do_throw));

    ASSERT_EQ(test_common_helper::Counter_base::gConstructed, 6);

    do_throw = true;
    try {
      dst.merge(src);
      ASSERT_TRUE(false);
    } catch (int &) {
    }

    do_throw = false;
    ASSERT_TRUE(test_set_helper::set_equal(src, t_set2({1, 3, 5}, test_set_helper::throw_comparator(do_throw))));
    ASSERT_TRUE(test_set_helper::set_equal(dst, t_set2({2, 4, 5}, test_set_helper::throw_comparator(do_throw))));
  }
}
