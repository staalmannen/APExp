// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="map.cpp"
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
#include <portable_stl/common/char_t.h>

#include "../common/test_comparisons.h"

TEST(map, clear) {
  static_cast<void>(test_info_);

  /**
   * @brief Map alias.
   */
  using t_map = ::portable_stl::map<std::int32_t, double>;

  t_map mp;
  auto  result = mp.insert({
    {3, 3.5},
    {2, 2.5},
    {1, 1.5},
    {4, 4.5},
    {6, 6.5},
    {5, 5.5},
  });

  ASSERT_EQ(6, mp.size());

  ASSERT_NO_THROW(mp.clear());
  mp.clear();

  ASSERT_EQ(0, mp.size());
}

TEST(map, key_comp) {
  static_cast<void>(test_info_);

  /**
   * @brief Map alias.
   */
  using t_map = ::portable_stl::map<std::int32_t, std::string>;

  t_map mp;
  auto  pair1 = mp.insert(t_map::value_type(1, "abc")).value();
  auto  pair2 = mp.insert(t_map::value_type(2, "abc")).value();

  t_map const &cmp = mp;

  ASSERT_TRUE(cmp.key_comp()(::portable_stl::get<0>(*::portable_stl::get<0>(pair1)),
                             ::portable_stl::get<0>(*::portable_stl::get<0>(pair2))));
  // vice versa
  ASSERT_FALSE(cmp.key_comp()(::portable_stl::get<0>(*::portable_stl::get<0>(pair2)),
                              ::portable_stl::get<0>(*::portable_stl::get<0>(pair1))));
}

TEST(map, value_comp) {
  static_cast<void>(test_info_);

  /**
   * @brief Map alias.
   */
  using t_map = ::portable_stl::map<std::int32_t, std::string>;

  t_map mp;
  auto  pair1 = mp.insert(t_map::value_type(1, "abc")).value();
  auto  pair2 = mp.insert(t_map::value_type(2, "abc")).value();

  t_map const &cmp = mp;

  ASSERT_TRUE(cmp.value_comp()(*::portable_stl::get<0>(pair1), *::portable_stl::get<0>(pair2)));

  // vice versa
  ASSERT_FALSE(cmp.value_comp()(*::portable_stl::get<0>(pair2), *::portable_stl::get<0>(pair1)));
}

TEST(map, comparisons) {
  static_cast<void>(test_info_);

  /**
   * @brief Map value alias.
   */
  using t_map_value_type = ::portable_stl::tuple<std::int32_t, ::portable_stl::string>;

  /**
   * @brief Map alias.
   */
  using t_map = ::portable_stl::map<std::int32_t, ::portable_stl::string>;

  {
    t_map mp1;
    t_map mp2;

    mp1.insert(t_map_value_type(1, "abc"));
    mp2.insert(t_map_value_type(2, "abc"));

    t_map const &cmp1 = mp1;
    t_map const &cmp2 = mp2;

    EXPECT_TRUE(test_common_helper::testComparisons(cmp1, cmp2, false, true));
  }
  {
    t_map mp1;
    t_map mp2;

    mp1.insert(t_map_value_type(1, "abc"));
    mp2.insert(t_map_value_type(1, "abc"));

    t_map const &cmp1 = mp1;
    t_map const &cmp2 = mp2;

    EXPECT_TRUE(test_common_helper::testComparisons(cmp1, cmp2, true, false));
  }
  {
    t_map mp1;
    t_map mp2;

    mp1.insert(t_map_value_type(1, "ab"));
    mp2.insert(t_map_value_type(1, "abc"));

    t_map const &cmp1 = mp1;
    t_map const &cmp2 = mp2;

    EXPECT_TRUE(test_common_helper::testComparisons(cmp1, cmp2, false, true));
  }
  {
    t_map mp1;
    t_map mp2;

    mp1.insert(t_map_value_type(1, "abc"));
    mp2.insert(t_map_value_type(1, "bcd"));

    t_map const &cmp1 = mp1;
    t_map const &cmp2 = mp2;

    EXPECT_TRUE(test_common_helper::testComparisons(cmp1, cmp2, false, true));
  }
  {
    t_map mp1;
    t_map mp2;

    mp1.insert(t_map_value_type(1, "abc"));
    mp2.insert(t_map_value_type(1, "abc"));
    mp2.insert(t_map_value_type(2, "abc"));

    t_map const &cmp1 = mp1;
    t_map const &cmp2 = mp2;

    EXPECT_TRUE(test_common_helper::testComparisons(cmp1, cmp2, false, true));
  }
}

namespace test_map_helper {
class Key final {
public:
  template<typename t_type> Key(t_type const &) {
  }

  bool operator<(Key const &) const {
    return false;
  }
};
} // namespace test_map_helper

TEST(map, value_compare) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::map<test_map_helper::Key, std::int32_t> m_empty;
    ::portable_stl::map<test_map_helper::Key, std::int32_t> m_contains;
    m_contains[test_map_helper::Key(0)] = 42;

    auto it = m_empty.find(test_map_helper::Key(0));
    ASSERT_EQ(m_empty.end(), it);

    it = m_contains.find(test_map_helper::Key(0));
    ASSERT_NE(m_contains.end(), it);
  }
  {
    ::portable_stl::map<test_map_helper::Key, std::int32_t> map;

    {
      auto result = map.insert(::portable_stl::make_tuple(test_map_helper::Key(0), 42));
      ASSERT_TRUE(result);

      auto iter_bool = result.value();
      ASSERT_TRUE(::portable_stl::get<1>(iter_bool));
      ASSERT_EQ(42, ::portable_stl::get<1>(*::portable_stl::get<0>(iter_bool)));
    }

    {
      auto result = map.insert(::portable_stl::make_tuple(test_map_helper::Key(0), 43));
      ASSERT_TRUE(result);

      auto iter_bool = result.value();
      ASSERT_FALSE(::portable_stl::get<1>(iter_bool));
      ASSERT_EQ(42, map[test_map_helper::Key(0)]);
    }
  }
}

TEST(map, member_swap) {
  static_cast<void>(test_info_);

  /**
   * @brief Map alias.
   */
  using t_map = ::portable_stl::map<std::int32_t, ::portable_stl::char_t>;

  /**
   * @brief Map value alias.
   */
  using t_map_value_type = ::portable_stl::tuple<std::int32_t const, ::portable_stl::char_t>;

  {
    {
      t_map mp1;
      t_map mp2;

      t_map mp1_save = mp1;
      t_map mp2_save = mp2;

      mp1.swap(mp2);
      ASSERT_EQ(mp1, mp2_save);
      ASSERT_EQ(mp2, mp1_save);
    }
    {
      t_map_value_type ar2[] = {t_map_value_type(5, '5'),
                                t_map_value_type(6, '6'),
                                t_map_value_type(7, '7'),
                                t_map_value_type(8, '8'),
                                t_map_value_type(9, '9'),
                                t_map_value_type(10, '0'),
                                t_map_value_type(11, '1'),
                                t_map_value_type(12, '2')};
      t_map            mp1;
      t_map            mp2(ar2, ar2 + sizeof(ar2) / sizeof(ar2[0]));
      t_map            mp1_save = mp1;
      t_map            mp2_save = mp2;

      mp1.swap(mp2);

      ASSERT_EQ(mp1, mp2_save);
      ASSERT_EQ(mp2, mp1_save);
    }
    {
      t_map_value_type ar1[]
        = {t_map_value_type(1, '1'), t_map_value_type(2, '2'), t_map_value_type(3, '3'), t_map_value_type(4, '4')};
      t_map mp1(ar1, ar1 + sizeof(ar1) / sizeof(ar1[0]));
      t_map mp2;
      t_map mp1_save = mp1;
      t_map mp2_save = mp2;

      mp1.swap(mp2);

      ASSERT_EQ(mp1, mp2_save);
      ASSERT_EQ(mp2, mp1_save);
    }
    {
      t_map_value_type ar1[]
        = {t_map_value_type(1, '1'), t_map_value_type(2, '2'), t_map_value_type(3, '3'), t_map_value_type(4, '4')};
      t_map_value_type ar2[] = {t_map_value_type(5, '5'),
                                t_map_value_type(6, '6'),
                                t_map_value_type(7, '7'),
                                t_map_value_type(8, '8'),
                                t_map_value_type(9, '9'),
                                t_map_value_type(10, '0'),
                                t_map_value_type(11, '1'),
                                t_map_value_type(12, '2')};
      t_map            mp1(ar1, ar1 + sizeof(ar1) / sizeof(ar1[0]));
      t_map            mp2(ar2, ar2 + sizeof(ar2) / sizeof(ar2[0]));
      t_map            mp1_save = mp1;
      t_map            mp2_save = mp2;

      mp1.swap(mp2);

      ASSERT_EQ(mp1, mp2_save);
      ASSERT_EQ(mp2, mp1_save);
    }
  }
}

TEST(map, swap) {
  static_cast<void>(test_info_);

  /**
   * @brief Map alias.
   */
  using t_map = ::portable_stl::map<std::int32_t, ::portable_stl::char_t>;

  /**
   * @brief Map value alias.
   */
  using t_map_value_type = ::portable_stl::tuple<std::int32_t const, ::portable_stl::char_t>;

  {
    t_map mp1;
    t_map mp2;
    t_map mp1_save = mp1;
    t_map mp2_save = mp2;
    swap(mp1, mp2);
    ASSERT_EQ(mp1, mp2_save);
    ASSERT_EQ(mp2, mp1_save);
  }
  {
    t_map_value_type ar2[] = {t_map_value_type(5, '5'),
                              t_map_value_type(6, '6'),
                              t_map_value_type(7, '7'),
                              t_map_value_type(8, '8'),
                              t_map_value_type(9, '9'),
                              t_map_value_type(10, '0'),
                              t_map_value_type(11, '1'),
                              t_map_value_type(12, '2')};
    t_map            mp1;
    t_map            mp2(ar2, ar2 + sizeof(ar2) / sizeof(ar2[0]));
    t_map            mp1_save = mp1;
    t_map            mp2_save = mp2;

    swap(mp1, mp2);

    ASSERT_EQ(mp1, mp2_save);
    ASSERT_EQ(mp2, mp1_save);
  }
  {
    t_map_value_type ar1[]
      = {t_map_value_type(1, '1'), t_map_value_type(2,'2'), t_map_value_type(3, '3'), t_map_value_type(4, '4')};
    t_map mp1(ar1, ar1 + sizeof(ar1) / sizeof(ar1[0]));
    t_map mp2;
    t_map mp1_save = mp1;
    t_map mp2_save = mp2;

    swap(mp1, mp2);

    ASSERT_EQ(mp1, mp2_save);
    ASSERT_EQ(mp2, mp1_save);
  }
  {
    t_map_value_type ar1[]
      = {t_map_value_type(1, '1'), t_map_value_type(2, '2'), t_map_value_type(3, '3'), t_map_value_type(4, '4')};
    t_map_value_type ar2[] = {t_map_value_type(5, '5'),
                              t_map_value_type(6, '6'),
                              t_map_value_type(7, '7'),
                              t_map_value_type(8, '8'),
                              t_map_value_type(9, '9'),
                              t_map_value_type(10, '0'),
                              t_map_value_type(11, '1'),
                              t_map_value_type(12, '2')};
    t_map            mp1(ar1, ar1 + sizeof(ar1) / sizeof(ar1[0]));
    t_map            mp2(ar2, ar2 + sizeof(ar2) / sizeof(ar2[0]));
    t_map            mp1_save = mp1;
    t_map            mp2_save = mp2;

    swap(mp1, mp2);

    ASSERT_EQ(mp1, mp2_save);
    ASSERT_EQ(mp2, mp1_save);
  }
}
