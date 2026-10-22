// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="set_lookup.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <portable_stl/set/set.h>

#include "../common/test_allocator.h"
#include "portable_stl/common/char_t.h"

using t_allocator2 = test_allocator_helper::test_allocator<std::int32_t>;

using t_set = ::portable_stl::set<std::int32_t>;

//       iterator find(const key_type& k);
// const_iterator find(const key_type& k) const;
TEST(set, find) {
  static_cast<void>(test_info_);

  {
    t_set st{5, 6, 7, 8, 9, 10, 11, 12};

    auto result = st.find(5);
    ASSERT_EQ(st.begin(), result);

    result = st.find(6);
    ASSERT_EQ(::portable_stl::next(st.begin(), 1), result);

    result = st.find(7);
    ASSERT_EQ(::portable_stl::next(st.begin(), 2), result);

    result = st.find(8);
    ASSERT_EQ(::portable_stl::next(st.begin(), 3), result);

    result = st.find(9);
    ASSERT_EQ(::portable_stl::next(st.begin(), 4), result);

    result = st.find(10);
    ASSERT_EQ(::portable_stl::next(st.begin(), 5), result);

    result = st.find(11);
    ASSERT_EQ(::portable_stl::next(st.begin(), 6), result);

    result = st.find(12);
    ASSERT_EQ(::portable_stl::next(st.begin(), 7), result);

    result = st.find(4);
    ASSERT_EQ(::portable_stl::next(st.begin(), 8), result);
  }

  // const
  {
    t_set const st{5, 6, 7, 8, 9, 10, 11, 12};

    auto result = st.find(5);
    ASSERT_EQ(st.begin(), result);
    ASSERT_TRUE((std::is_same<typename t_set::const_iterator, decltype(result)>{}));

    result = st.find(6);
    ASSERT_EQ(::portable_stl::next(st.begin(), 1), result);

    result = st.find(7);
    ASSERT_EQ(::portable_stl::next(st.begin(), 2), result);

    result = st.find(8);
    ASSERT_EQ(::portable_stl::next(st.begin(), 3), result);

    result = st.find(9);
    ASSERT_EQ(::portable_stl::next(st.begin(), 4), result);

    result = st.find(10);
    ASSERT_EQ(::portable_stl::next(st.begin(), 5), result);

    result = st.find(11);
    ASSERT_EQ(::portable_stl::next(st.begin(), 6), result);

    result = st.find(12);
    ASSERT_EQ(::portable_stl::next(st.begin(), 7), result);

    result = st.find(4);
    ASSERT_EQ(::portable_stl::next(st.begin(), 8), result);
  }
}

namespace test_set_helper {
struct FAT_key {
  std::int32_t m_int;
  std::int32_t m_data[1000]; // heavy part
};

struct Light_key {
  std::int32_t m_int;
};

// for use by comparator

static bool operator<(FAT_key const &fk, Light_key const &lk) {
  return fk.m_int < lk.m_int;
}
static bool operator<(Light_key const &lk, FAT_key const &fk) {
  return lk.m_int < fk.m_int;
}
static bool operator<(FAT_key const &fk1, FAT_key const &fk2) {
  return fk1.m_int < fk2.m_int;
}

} // namespace test_set_helper

//       iterator find(const key_type& k);
// const_iterator find(const key_type& k) const;
TEST(set, find_transparent) {
  static_cast<void>(test_info_);

  /**
   * @brief Map alias.
   */
  using t_setFAT = ::portable_stl::set<test_set_helper::FAT_key, ::portable_stl::less<>>;

  test_set_helper::FAT_key arr[] = {
    test_set_helper::FAT_key{ 5, {}},
    test_set_helper::FAT_key{ 6, {}},
    test_set_helper::FAT_key{ 7, {}},
    test_set_helper::FAT_key{ 8, {}},
    test_set_helper::FAT_key{ 9, {}},
    test_set_helper::FAT_key{10, {}},
    test_set_helper::FAT_key{11, {}},
    test_set_helper::FAT_key{12, {}}
  };

  {
    t_setFAT st(arr, arr + sizeof(arr) / sizeof(arr[0]));

    test_set_helper::Light_key const lkey{8};

    auto result = st.find(lkey);
    EXPECT_EQ(::portable_stl::next(st.begin(), 3), result);
  }

  // constant
  {
    t_setFAT const st(arr, arr + sizeof(arr) / sizeof(arr[0]));

    test_set_helper::Light_key const lkey{9};

    auto result = st.find(lkey);
    EXPECT_EQ(::portable_stl::next(st.begin(), 4), result);
  }
}

// size_type count(const key_type& k) const;
TEST(set, count) {
  static_cast<void>(test_info_);

  t_set st{5, 6, 7, 8, 9, 10, 11, 12};

  for (std::int32_t i{0}; i < 5; ++i) {
    auto result = st.count(i);
    ASSERT_EQ(0, result);
  }

  for (std::int32_t i{5}; i < 13; ++i) {
    auto result = st.count(i);
    ASSERT_EQ(1, result);
  }
}

namespace test_set_helper {
class compare_pair_trans final {
public:
  bool operator()(::portable_stl::tuple<std::int32_t, std::int32_t> const &lhs,
                  ::portable_stl::tuple<std::int32_t, std::int32_t> const &rhs) const {
    return lhs < rhs;
  }

  bool operator()(::portable_stl::tuple<std::int32_t, std::int32_t> const &lhs, std::int32_t rhs) const {
    return ::portable_stl::get<0>(lhs) < rhs;
  }

  bool operator()(std::int32_t lhs, ::portable_stl::tuple<std::int32_t, std::int32_t> const &rhs) const {
    return lhs < ::portable_stl::get<0>(rhs);
  }

  using is_transparent = void;
};
} // namespace test_set_helper

// size_type count(const key_type& k) const;
TEST(set, count_transparent) {
  static_cast<void>(test_info_);

  ::portable_stl::set<::portable_stl::tuple<std::int32_t, std::int32_t>, test_set_helper::compare_pair_trans> st({
    {2, 1},
    {1, 2}, // hit
    {1, 3}, // hit
    {1, 4}, // hit
    {2, 2},
  });

  ASSERT_EQ(3, st.count(1));
}

namespace test_set_helper {
template<class t_set, class t_value, class t_bad, class... t_vals> void test_set_contains(t_bad bad, t_vals... args) {
  t_set   st;
  t_value values[] = {args...};

  for (auto &val : values) {
    st.insert(val);
  }

  for (auto &val : values) {
    ASSERT_TRUE(st.contains(val));
  }

  ASSERT_FALSE(st.contains(bad));
}
} // namespace test_set_helper

// bool contains(const key_type& x) const;
TEST(set, contains) {
  static_cast<void>(test_info_);

  {
    test_set_helper::test_set_contains<::portable_stl::set<::portable_stl::char_t>, ::portable_stl::char_t>(
      'e', 'a', 'b', 'c', 'd');

    test_set_helper::test_set_contains<::portable_stl::set<std::int32_t>, std::int32_t>(14, 10, 11, 12, 13);
  }
}

// bool contains(const key_type& x) const;
TEST(set, contains_transparent) {
  static_cast<void>(test_info_);

  ::portable_stl::set<::portable_stl::tuple<std::int32_t, std::int32_t>, test_set_helper::compare_pair_trans> st({
    {2, 1},
    {1, 2}, // hit
    {1, 3}, // hit
    {1, 4}, // hit
    {2, 2}
  });

  ASSERT_TRUE(st.contains(1));
}

//       iterator lower_bound(const key_type& k);
// const_iterator lower_bound(const key_type& k) const;
TEST(set, lower_bound) {
  static_cast<void>(test_info_);

  {
    t_set st{5, 7, 9, 11, 13, 15, 17, 19};

    auto result = st.lower_bound(5);
    ASSERT_EQ(result, st.begin());

    result = st.lower_bound(7);
    ASSERT_EQ(result, ::portable_stl::next(st.begin()));

    result = st.lower_bound(9);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 2));

    result = st.lower_bound(11);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 3));

    result = st.lower_bound(13);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 4));

    result = st.lower_bound(15);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 5));

    result = st.lower_bound(17);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 6));

    result = st.lower_bound(19);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 7));

    result = st.lower_bound(4);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 0));

    result = st.lower_bound(6);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 1));

    result = st.lower_bound(8);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 2));

    result = st.lower_bound(10);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 3));

    result = st.lower_bound(12);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 4));

    result = st.lower_bound(14);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 5));

    result = st.lower_bound(16);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 6));

    result = st.lower_bound(18);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 7));

    result = st.lower_bound(20);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 8));
  }

  {
    t_set const st{5, 7, 9, 11, 13, 15, 17, 19};

    auto result = st.lower_bound(5);
    ASSERT_EQ(result, st.begin());

    result = st.lower_bound(7);
    ASSERT_EQ(result, ::portable_stl::next(st.begin()));

    result = st.lower_bound(9);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 2));

    result = st.lower_bound(11);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 3));

    result = st.lower_bound(13);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 4));

    result = st.lower_bound(15);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 5));

    result = st.lower_bound(17);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 6));

    result = st.lower_bound(19);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 7));

    result = st.lower_bound(4);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 0));

    result = st.lower_bound(6);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 1));

    result = st.lower_bound(8);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 2));

    result = st.lower_bound(10);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 3));

    result = st.lower_bound(12);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 4));

    result = st.lower_bound(14);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 5));

    result = st.lower_bound(16);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 6));

    result = st.lower_bound(18);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 7));

    result = st.lower_bound(20);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 8));
  }
}

//       iterator lower_bound(const key_type& k);
// const_iterator lower_bound(const key_type& k) const;
TEST(set, lower_bound_transparent) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::set<::portable_stl::tuple<std::int32_t, std::int32_t>, test_set_helper::compare_pair_trans> st({
      {2, 1},
      {1, 2}, // hit
      {1, 3}, // hit
      {1, 4}, // hit
      {2, 2}
    });

    ASSERT_EQ(::portable_stl::next(st.begin(), 0), st.lower_bound(1));
    ASSERT_EQ(st.end(), st.lower_bound(6));
  }

  // constant
  {
    ::portable_stl::set<::portable_stl::tuple<std::int32_t, std::int32_t>, test_set_helper::compare_pair_trans> const st({
      {2, 1},
      {1, 2}, // hit
      {1, 3}, // hit
      {1, 4}, // hit
      {2, 2}
    });

    ASSERT_EQ(::portable_stl::next(st.begin(), 0), st.lower_bound(1));
    ASSERT_EQ(st.end(), st.lower_bound(6));
  }
}

//       iterator upper_bound(const key_type& k);
// const_iterator upper_bound(const key_type& k) const;
TEST(set, upper_bound) {
  static_cast<void>(test_info_);

  {
    t_set st{5, 7, 9, 11, 13, 15, 17, 19};

    auto result = st.upper_bound(5);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 1));

    result = st.upper_bound(7);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 2));

    result = st.upper_bound(9);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 3));

    result = st.upper_bound(11);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 4));

    result = st.upper_bound(13);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 5));

    result = st.upper_bound(15);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 6));

    result = st.upper_bound(17);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 7));

    result = st.upper_bound(19);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 8));

    result = st.upper_bound(4);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 0));

    result = st.upper_bound(6);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 1));

    result = st.upper_bound(8);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 2));

    result = st.upper_bound(10);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 3));

    result = st.upper_bound(12);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 4));

    result = st.upper_bound(14);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 5));

    result = st.upper_bound(16);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 6));

    result = st.upper_bound(18);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 7));

    result = st.upper_bound(20);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 8));
  }

  // constant
  {
    t_set const st{5, 7, 9, 11, 13, 15, 17, 19};

    auto result = st.upper_bound(5);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 1));

    result = st.upper_bound(7);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 2));

    result = st.upper_bound(9);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 3));

    result = st.upper_bound(11);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 4));

    result = st.upper_bound(13);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 5));

    result = st.upper_bound(15);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 6));

    result = st.upper_bound(17);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 7));

    result = st.upper_bound(19);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 8));

    result = st.upper_bound(4);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 0));

    result = st.upper_bound(6);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 1));

    result = st.upper_bound(8);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 2));

    result = st.upper_bound(10);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 3));

    result = st.upper_bound(12);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 4));

    result = st.upper_bound(14);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 5));

    result = st.upper_bound(16);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 6));

    result = st.upper_bound(18);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 7));

    result = st.upper_bound(20);
    ASSERT_EQ(result, ::portable_stl::next(st.begin(), 8));
  }
}

//       iterator upper_bound(const key_type& k);
// const_iterator upper_bound(const key_type& k) const;
TEST(set, upper_bound_transparent) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::set<::portable_stl::tuple<std::int32_t, std::int32_t>, test_set_helper::compare_pair_trans>
    st({
      {2, 1},
      {1, 2}, // hit
      {1, 3}, // hit
      {1, 4}, // hit
      {2, 2}
    });

    ASSERT_EQ(::portable_stl::next(st.begin(), 3), st.upper_bound(1));
    ASSERT_EQ(st.end(), st.upper_bound(6));
  }

  // constant
  {
    ::portable_stl::set<::portable_stl::tuple<std::int32_t, std::int32_t>, test_set_helper::compare_pair_trans>
    const
      st({
        {2, 1},
        {1, 2}, // hit
        {1, 3}, // hit
        {1, 4}, // hit
        {2, 2}
    });

    ASSERT_EQ(::portable_stl::next(st.begin(), 3), st.upper_bound(1));
    ASSERT_EQ(st.end(), st.upper_bound(6));
  }
}

// pair<iterator,iterator>             equal_range(const key_type& k);
// pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
TEST(set, equal_range) {
  static_cast<void>(test_info_);

  {
    t_set st{5, 7, 9, 11, 13, 15, 17, 19};

    auto result = st.equal_range(5);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 0));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 1));

    result = st.equal_range(7);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 1));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 2));

    result = st.equal_range(9);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 2));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 3));

    result = st.equal_range(11);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 3));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 4));

    result = st.equal_range(13);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 4));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 5));

    result = st.equal_range(15);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 5));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 6));

    result = st.equal_range(17);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 6));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 7));

    result = st.equal_range(19);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 7));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 8));

    result = st.equal_range(4);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 0));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 0));

    result = st.equal_range(6);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 1));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 1));

    result = st.equal_range(8);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 2));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 2));

    result = st.equal_range(10);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 3));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 3));

    result = st.equal_range(12);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 4));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 4));

    result = st.equal_range(14);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 5));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 5));

    result = st.equal_range(16);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 6));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 6));

    result = st.equal_range(18);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 7));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 7));

    result = st.equal_range(20);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 8));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 8));
  }

  // constant
  {
    t_set const st{5, 7, 9, 11, 13, 15, 17, 19};

    auto result = st.equal_range(5);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 0));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 1));

    result = st.equal_range(7);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 1));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 2));

    result = st.equal_range(9);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 2));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 3));

    result = st.equal_range(11);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 3));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 4));

    result = st.equal_range(13);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 4));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 5));

    result = st.equal_range(15);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 5));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 6));

    result = st.equal_range(17);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 6));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 7));

    result = st.equal_range(19);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 7));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 8));

    result = st.equal_range(4);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 0));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 0));

    result = st.equal_range(6);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 1));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 1));

    result = st.equal_range(8);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 2));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 2));

    result = st.equal_range(10);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 3));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 3));

    result = st.equal_range(12);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 4));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 4));

    result = st.equal_range(14);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 5));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 5));

    result = st.equal_range(16);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 6));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 6));

    result = st.equal_range(18);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 7));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 7));

    result = st.equal_range(20);
    ASSERT_EQ(::portable_stl::get<0>(result), ::portable_stl::next(st.begin(), 8));
    ASSERT_EQ(::portable_stl::get<1>(result), ::portable_stl::next(st.begin(), 8));
  }
}

// template<typename K> pair<iterator,iterator>             equal_range(const K& x);
// template<typename K> pair<const_iterator,const_iterator> equal_range(const K& x) const;
TEST(set, equal_range_transparent) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::set<::portable_stl::tuple<std::int32_t, std::int32_t>, test_set_helper::compare_pair_trans>
    st({
      {2, 1},
      {1, 2}, // hit
      {1, 3}, // hit
      {1, 4}, // hit
      {2, 2}
    });

    auto        result = st.equal_range(1);
    std::size_t nels{0};

    for (auto it = ::portable_stl::get<0>(result); it != ::portable_stl::get<1>(result); it++) {
      ASSERT_EQ(1, ::portable_stl::get<0>(*it));
      ++nels;
    }

    ASSERT_EQ(3, nels);
  }

  {
    ::portable_stl::set<::portable_stl::tuple<std::int32_t, std::int32_t>, test_set_helper::compare_pair_trans>
    const
      st({
        {2, 1},
        {1, 2}, // hit
        {1, 3}, // hit
        {1, 4}, // hit
        {2, 2}
    });

    auto        result = st.equal_range(1);
    std::size_t nels{0};

    for (auto it = ::portable_stl::get<0>(result); it != ::portable_stl::get<1>(result); it++) {
      ASSERT_EQ(1, ::portable_stl::get<0>(*it));
      ++nels;
    }

    ASSERT_EQ(3, nels);
  }
}
