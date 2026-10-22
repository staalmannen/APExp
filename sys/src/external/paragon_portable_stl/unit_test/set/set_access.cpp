// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="set_access.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <portable_stl/set/set.h>

#include "../common/move_only.h"
#include "../common/test_allocator.h"
#include "../common/test_compare.h"
#include "../common/test_comparisons.h"

TEST(set, empty) {
  static_cast<void>(test_info_);

  /**
   * @brief Map alias.
   */
  using t_set = ::portable_stl::set<std::int32_t>;

  t_set st;
  ASSERT_TRUE(st.empty());

  st.insert(1);
  ASSERT_FALSE(st.empty());

  st.clear();
  ASSERT_TRUE(st.empty());
}

TEST(set, size) {
  static_cast<void>(test_info_);

  /**
   * @brief Map alias.
   */
  using t_set = ::portable_stl::set<std::int32_t>;

  t_set st;
  EXPECT_EQ(0, st.size());

  st.insert(1);
  EXPECT_EQ(1, st.size());

  st.insert(2);
  EXPECT_EQ(2, st.size());

  st.insert(3);
  EXPECT_EQ(3, st.size());

  st.erase(st.begin());
  EXPECT_EQ(2, st.size());

  st.erase(st.begin());
  EXPECT_EQ(1, st.size());

  st.erase(st.begin());
  EXPECT_EQ(0, st.size());
}

TEST(set, iterators) {
  static_cast<void>(test_info_);

  std::int32_t arr[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

  {
    ::portable_stl::set<std::int32_t> st(arr, arr + (sizeof(arr) / sizeof(arr[0])));

    ASSERT_EQ(st.size(), ::portable_stl::distance(st.begin(), st.end()));
    ASSERT_EQ(st.size(), ::portable_stl::distance(st.rbegin(), st.rend()));

    ::portable_stl::set<std::int32_t>::iterator iter = st.begin();

    ::portable_stl::set<std::int32_t>::const_iterator const_begin_iter = iter;

    ASSERT_EQ(iter, const_begin_iter);

    for (std::int32_t j{1}; j <= static_cast<std::int32_t>(st.size()); ++j, ++iter) {
      ASSERT_EQ(j, *iter);
    }
    ASSERT_EQ(iter, st.end());

    for (std::int32_t j{static_cast<std::int32_t>(st.size())}; j >= 1; --j) {
      --iter;
      ASSERT_EQ(j, *iter);
    }
    ASSERT_EQ(iter, st.begin());
  }
  {
    ::portable_stl::set<std::int32_t> const st(arr, arr + (sizeof(arr) / sizeof(arr[0])));

    ASSERT_EQ(static_cast<std::size_t>(::portable_stl::distance(st.begin(), st.end())), st.size());
    ASSERT_EQ(static_cast<std::size_t>(::portable_stl::distance(st.cbegin(), st.cend())), st.size());
    ASSERT_EQ(static_cast<std::size_t>(::portable_stl::distance(st.rbegin(), st.rend())), st.size());
    ASSERT_EQ(static_cast<std::size_t>(::portable_stl::distance(st.crbegin(), st.crend())), st.size());

    ::portable_stl::set<std::int32_t>::const_iterator iter;

    iter = st.begin();
    for (std::int32_t j{1}; static_cast<std::size_t>(j) <= st.size(); ++j, ++iter) {
      ASSERT_EQ(j, *iter);
    }
    ASSERT_EQ(iter, st.end());

    for (auto j = static_cast<std::int32_t>(st.size()); j >= 1; --j) {
      --iter;
      ASSERT_EQ(j, *iter);
    }
    ASSERT_EQ(iter, st.begin());
  }

  // N3644 testing
  {
    using t_set = ::portable_stl::set<std::int32_t>;
    t_set::iterator       ii1{}, ii2{};
    t_set::iterator       ii4 = ii1;
    t_set::const_iterator cii{};
    ASSERT_EQ(ii1, ii2);
    ASSERT_EQ(ii1, ii4);

    ASSERT_FALSE(ii1 != ii2);

    ASSERT_EQ(ii1, cii);
    ASSERT_EQ(cii, ii1);
    ASSERT_FALSE(ii1 != cii);
    ASSERT_FALSE(cii != ii1);
  }
}

TEST(set, max_size) {
  static_cast<void>(test_info_);

  using t_allocator = test_allocator_helper::TestSimpleAllocator<std::int32_t>;

  /**
   * @brief Tree's allocator alias.
   */
  using t_tree_allocator = test_allocator_helper::TestSimpleAllocator<portable_stl::tree_node<std::int32_t, void *>>;

  {
    ::portable_stl::set<std::int32_t, ::portable_stl::less<std::int32_t>, t_allocator> st;

    t_tree_allocator::m_max_size = 10;
    ASSERT_EQ(10, st.max_size());

    t_tree_allocator::m_max_size = 10000;
  }

  {
    using t_set = ::portable_stl::set<std::int32_t>;

    auto const max_dist = static_cast<t_set::size_type>(::portable_stl::numeric_limits<t_set::difference_type>::max());

    t_set st;
    ASSERT_LE(st.max_size(), max_dist);
  }
}

TEST(set, comparisons) {
  static_cast<void>(test_info_);

  /**
   * @brief Set alias.
   */
  using t_set = ::portable_stl::set<std::int32_t>;

  {
    t_set st1;
    t_set st2;

    st1.insert(1);
    st2.insert(2);

    t_set const &cst1 = st1;
    t_set const &cst2 = st2;

    EXPECT_TRUE(test_common_helper::testComparisons(cst1, cst2, false, true));
  }
  {
    t_set st1;
    t_set st2;

    st1.insert(1);
    st2.insert(1);

    t_set const &cst1 = st1;
    t_set const &cst2 = st2;

    EXPECT_TRUE(test_common_helper::testComparisons(cst1, cst2, true, false));
  }
  {
    t_set st1;
    t_set st2;

    st1.insert(1);
    st2.insert(1);
    st2.insert(2);

    t_set const &cst1 = st1;
    t_set const &cst2 = st2;

    EXPECT_TRUE(test_common_helper::testComparisons(cst1, cst2, false, true));
  }
}

TEST(set, clear) {
  static_cast<void>(test_info_);

  /**
   * @brief Map alias.
   */
  using t_set = ::portable_stl::set<std::int32_t>;

  t_set st{1, 2, 3, 4, 5, 6};

  ASSERT_EQ(6, st.size());

  ASSERT_NO_THROW(st.clear());
  st.clear();

  ASSERT_EQ(0, st.size());
}

TEST(set, key_comp) {
  static_cast<void>(test_info_);

  /**
   * @brief Map alias.
   */
  using t_set = ::portable_stl::set<std::int32_t>;

  t_set st;
  auto  pair1 = st.insert(t_set::value_type(1)).value();
  auto  pair2 = st.insert(t_set::value_type(2)).value();

  t_set const &cst = st;

  ASSERT_TRUE(cst.key_comp()(*::portable_stl::get<0>(pair1), *::portable_stl::get<0>(pair2)));
  // vice versa
  ASSERT_FALSE(cst.key_comp()(*::portable_stl::get<0>(pair2), *::portable_stl::get<0>(pair1)));
}

TEST(set, value_comp) {
  static_cast<void>(test_info_);

  /**
   * @brief Map alias.
   */
  using t_set = ::portable_stl::set<std::int32_t>;

  t_set st;
  auto  pair1 = st.insert(t_set::value_type(1)).value();
  auto  pair2 = st.insert(t_set::value_type(2)).value();

  t_set const &cst = st;

  ASSERT_TRUE(cst.value_comp()(*::portable_stl::get<0>(pair1), *::portable_stl::get<0>(pair2)));
  // vice versa
  ASSERT_FALSE(cst.value_comp()(*::portable_stl::get<0>(pair2), *::portable_stl::get<0>(pair1)));
}

namespace test_set_helper {
class Key final {
public:
  template<typename t_type> Key(t_type const &) {
  }

  bool operator<(Key const &) const {
    return false;
  }
};
} // namespace test_set_helper

TEST(set, member_swap) {
  static_cast<void>(test_info_);

  /**
   * @brief Map alias.
   */
  using t_set = ::portable_stl::set<std::int32_t>;

  {
    t_set st1;
    t_set st2;

    t_set st1_save = st1;
    t_set st2_save = st2;

    st1.swap(st2);
    ASSERT_EQ(st1, st2_save);
    ASSERT_EQ(st2, st1_save);
  }
  {
    t_set st1;
    t_set st2{5, 6, 7, 8, 9, 10, 11, 12};
    t_set st1_save = st1;
    t_set st2_save = st2;

    st1.swap(st2);

    ASSERT_EQ(st1, st2_save);
    ASSERT_EQ(st2, st1_save);
  }
  {
    t_set st1{1, 2, 3, 4};
    t_set st2;
    t_set st1_save = st1;
    t_set st2_save = st2;

    st1.swap(st2);

    ASSERT_EQ(st1, st2_save);
    ASSERT_EQ(st2, st1_save);
  }
  {
    t_set st1{1, 2, 3, 4};
    t_set st2{5, 6, 7, 8, 9, 10, 11, 12};
    t_set st1_save = st1;
    t_set st2_save = st2;

    st1.swap(st2);

    ASSERT_EQ(st1, st2_save);
    ASSERT_EQ(st2, st1_save);
  }
}

TEST(set, swap) {
  static_cast<void>(test_info_);

  /**
   * @brief Map alias.
   */
  using t_set = ::portable_stl::set<std::int32_t>;

  {
    t_set st1;
    t_set st2;
    t_set st1_save = st1;
    t_set st2_save = st2;
    swap(st1, st2);
    ASSERT_EQ(st1, st2_save);
    ASSERT_EQ(st2, st1_save);
  }
  {
    t_set st1;
    t_set st2{5, 6, 7, 8, 9, 10, 11, 12};
    t_set st1_save = st1;
    t_set st2_save = st2;

    swap(st1, st2);

    ASSERT_EQ(st1, st2_save);
    ASSERT_EQ(st2, st1_save);
  }
  {
    t_set st1{5, 6, 7, 8, 9, 10, 11, 12};
    t_set st2;
    t_set st1_save = st1;
    t_set st2_save = st2;

    swap(st1, st2);

    ASSERT_EQ(st1, st2_save);
    ASSERT_EQ(st2, st1_save);
  }
  {
    t_set st1{1, 2, 3, 4};
    t_set st2{5, 6, 7, 8, 9, 10, 11, 12};
    t_set st1_save = st1;
    t_set st2_save = st2;

    swap(st1, st2);

    ASSERT_EQ(st1, st2_save);
    ASSERT_EQ(st2, st1_save);
  }
}
