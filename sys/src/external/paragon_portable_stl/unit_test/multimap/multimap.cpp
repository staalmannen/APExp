// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="multimap.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <portable_stl/common/char_t.h>
#include <portable_stl/map/multimap.h>
#include <portable_stl/string/string.h>

#include "../common/test_comparisons.h"

TEST(multimap, clear) {
  static_cast<void>(test_info_);

  /**
   * @brief Map alias.
   */
  using t_multimap = ::portable_stl::multimap<std::int32_t, double>;

  t_multimap mp;
  auto       result = mp.insert({
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

TEST(multimap, key_comp) {
  static_cast<void>(test_info_);

  /**
   * @brief Map alias.
   */
  using t_multimap = ::portable_stl::multimap<std::int32_t, std::string>;

  t_multimap mp;
  auto       iter1 = mp.insert(t_multimap::value_type(1, "abc")).value();
  auto       iter2 = mp.insert(t_multimap::value_type(2, "abc")).value();

  t_multimap const &cmp = mp;

  ASSERT_TRUE(cmp.key_comp()(::portable_stl::get<0>(*iter1), ::portable_stl::get<0>(*iter2)));
  // vice versa
  ASSERT_FALSE(cmp.key_comp()(::portable_stl::get<0>(*iter2), ::portable_stl::get<0>(*iter1)));
}

TEST(multimap, value_comp) {
  static_cast<void>(test_info_);

  /**
   * @brief Map alias.
   */
  using t_multimap = ::portable_stl::multimap<std::int32_t, std::string>;

  t_multimap mp;
  auto       iter1 = mp.insert(t_multimap::value_type(1, "abc")).value();
  auto       iter2 = mp.insert(t_multimap::value_type(2, "abc")).value();

  t_multimap const &cmp = mp;

  ASSERT_TRUE(cmp.value_comp()(*iter1, *iter2));

  // vice versa
  ASSERT_FALSE(cmp.value_comp()(*iter2, *iter1));
}

TEST(multimap, comparisons) {
  static_cast<void>(test_info_);

  /**
   * @brief Map value alias.
   */
  using t_multimap_value_type = ::portable_stl::tuple<std::int32_t, ::portable_stl::string>;

  /**
   * @brief Map alias.
   */
  using t_multimap = ::portable_stl::multimap<std::int32_t, ::portable_stl::string>;

  {
    t_multimap mp1;
    t_multimap mp2;

    mp1.insert(t_multimap_value_type(1, "abc"));
    mp2.insert(t_multimap_value_type(2, "abc"));

    t_multimap const &cmp1 = mp1;
    t_multimap const &cmp2 = mp2;

    EXPECT_TRUE(test_common_helper::testComparisons(cmp1, cmp2, false, true));
  }
  {
    t_multimap mp1;
    t_multimap mp2;

    mp1.insert(t_multimap_value_type(1, "abc"));
    mp2.insert(t_multimap_value_type(1, "abc"));

    t_multimap const &cmp1 = mp1;
    t_multimap const &cmp2 = mp2;

    EXPECT_TRUE(test_common_helper::testComparisons(cmp1, cmp2, true, false));
  }
  {
    t_multimap mp1;
    t_multimap mp2;

    mp1.insert(t_multimap_value_type(1, "ab"));
    mp2.insert(t_multimap_value_type(1, "abc"));

    t_multimap const &cmp1 = mp1;
    t_multimap const &cmp2 = mp2;

    EXPECT_TRUE(test_common_helper::testComparisons(cmp1, cmp2, false, true));
  }
  {
    t_multimap mp1;
    t_multimap mp2;

    mp1.insert(t_multimap_value_type(1, "abc"));
    mp2.insert(t_multimap_value_type(1, "bcd"));

    t_multimap const &cmp1 = mp1;
    t_multimap const &cmp2 = mp2;

    EXPECT_TRUE(test_common_helper::testComparisons(cmp1, cmp2, false, true));
  }
  {
    t_multimap mp1;
    t_multimap mp2;

    mp1.insert(t_multimap_value_type(1, "abc"));
    mp2.insert(t_multimap_value_type(1, "abc"));
    mp2.insert(t_multimap_value_type(2, "abc"));

    t_multimap const &cmp1 = mp1;
    t_multimap const &cmp2 = mp2;

    EXPECT_TRUE(test_common_helper::testComparisons(cmp1, cmp2, false, true));
  }
}

namespace test_multimap_helper {
class Key final {
public:
  template<typename t_type> Key(t_type const &) {
  }

  bool operator<(Key const &) const {
    return false;
  }
};
} // namespace test_multimap_helper

TEST(multimap, member_swap) {
  static_cast<void>(test_info_);

  /**
   * @brief Map alias.
   */
  using t_multimap = ::portable_stl::multimap<std::int32_t, ::portable_stl::char_t>;

  /**
   * @brief Map value alias.
   */
  using t_multimap_value_type = ::portable_stl::tuple<std::int32_t const, ::portable_stl::char_t>;

  {
    {
      t_multimap mp1;
      t_multimap mp2;

      t_multimap mp1_save = mp1;
      t_multimap mp2_save = mp2;

      mp1.swap(mp2);
      ASSERT_EQ(mp1, mp2_save);
      ASSERT_EQ(mp2, mp1_save);
    }
    {
      t_multimap_value_type ar2[] = {t_multimap_value_type(5, '5'),
                                     t_multimap_value_type(6, '6'),
                                     t_multimap_value_type(7, '7'),
                                     t_multimap_value_type(8, '8'),
                                     t_multimap_value_type(9, '9'),
                                     t_multimap_value_type(10, '0'),
                                     t_multimap_value_type(11, '1'),
                                     t_multimap_value_type(12, '2')};
      t_multimap            mp1;
      t_multimap            mp2(ar2, ar2 + sizeof(ar2) / sizeof(ar2[0]));
      t_multimap            mp1_save = mp1;
      t_multimap            mp2_save = mp2;

      mp1.swap(mp2);

      ASSERT_EQ(mp1, mp2_save);
      ASSERT_EQ(mp2, mp1_save);
    }
    {
      t_multimap_value_type ar1[] = {t_multimap_value_type(1, '1'),
                                     t_multimap_value_type(2, '2'),
                                     t_multimap_value_type(3, '3'),
                                     t_multimap_value_type(4, '4')};
      t_multimap            mp1(ar1, ar1 + sizeof(ar1) / sizeof(ar1[0]));
      t_multimap            mp2;
      t_multimap            mp1_save = mp1;
      t_multimap            mp2_save = mp2;

      mp1.swap(mp2);

      ASSERT_EQ(mp1, mp2_save);
      ASSERT_EQ(mp2, mp1_save);
    }
    {
      t_multimap_value_type ar1[] = {t_multimap_value_type(1, '1'),
                                     t_multimap_value_type(2, '2'),
                                     t_multimap_value_type(3, '3'),
                                     t_multimap_value_type(4, '4')};
      t_multimap_value_type ar2[] = {t_multimap_value_type(5, '5'),
                                     t_multimap_value_type(6, '6'),
                                     t_multimap_value_type(7, '7'),
                                     t_multimap_value_type(8, '8'),
                                     t_multimap_value_type(9, '9'),
                                     t_multimap_value_type(10, '0'),
                                     t_multimap_value_type(11, '1'),
                                     t_multimap_value_type(12, '2')};
      t_multimap            mp1(ar1, ar1 + sizeof(ar1) / sizeof(ar1[0]));
      t_multimap            mp2(ar2, ar2 + sizeof(ar2) / sizeof(ar2[0]));
      t_multimap            mp1_save = mp1;
      t_multimap            mp2_save = mp2;

      mp1.swap(mp2);

      ASSERT_EQ(mp1, mp2_save);
      ASSERT_EQ(mp2, mp1_save);
    }
  }
}

TEST(multimap, swap) {
  static_cast<void>(test_info_);

  /**
   * @brief Map alias.
   */
  using t_multimap = ::portable_stl::multimap<std::int32_t, ::portable_stl::char_t>;

  /**
   * @brief Map value alias.
   */
  using t_multimap_value_type = ::portable_stl::tuple<std::int32_t const, ::portable_stl::char_t>;

  {
    t_multimap mp1;
    t_multimap mp2;
    t_multimap mp1_save = mp1;
    t_multimap mp2_save = mp2;
    swap(mp1, mp2);
    ASSERT_EQ(mp1, mp2_save);
    ASSERT_EQ(mp2, mp1_save);
  }
  {
    t_multimap_value_type ar2[] = {t_multimap_value_type(5, '5'),
                                   t_multimap_value_type(6, '6'),
                                   t_multimap_value_type(7, '7'),
                                   t_multimap_value_type(8, '8'),
                                   t_multimap_value_type(9, '9'),
                                   t_multimap_value_type(10, '0'),
                                   t_multimap_value_type(11, '1'),
                                   t_multimap_value_type(12, '2')};
    t_multimap            mp1;
    t_multimap            mp2(ar2, ar2 + sizeof(ar2) / sizeof(ar2[0]));
    t_multimap            mp1_save = mp1;
    t_multimap            mp2_save = mp2;

    swap(mp1, mp2);

    ASSERT_EQ(mp1, mp2_save);
    ASSERT_EQ(mp2, mp1_save);
  }
  {
    t_multimap_value_type ar1[] = {t_multimap_value_type(1, '1'),
                                   t_multimap_value_type(2, '2'),
                                   t_multimap_value_type(3, '3'),
                                   t_multimap_value_type(4, '4')};
    t_multimap            mp1(ar1, ar1 + sizeof(ar1) / sizeof(ar1[0]));
    t_multimap            mp2;
    t_multimap            mp1_save = mp1;
    t_multimap            mp2_save = mp2;

    swap(mp1, mp2);

    ASSERT_EQ(mp1, mp2_save);
    ASSERT_EQ(mp2, mp1_save);
  }
  {
    t_multimap_value_type ar1[] = {t_multimap_value_type(1, '1'),
                                   t_multimap_value_type(2, '2'),
                                   t_multimap_value_type(3, '3'),
                                   t_multimap_value_type(4, '4')};
    t_multimap_value_type ar2[] = {t_multimap_value_type(5, '5'),
                                   t_multimap_value_type(6, '6'),
                                   t_multimap_value_type(7, '7'),
                                   t_multimap_value_type(8, '8'),
                                   t_multimap_value_type(9, '9'),
                                   t_multimap_value_type(10, '0'),
                                   t_multimap_value_type(11, '1'),
                                   t_multimap_value_type(12, '2')};
    t_multimap            mp1(ar1, ar1 + sizeof(ar1) / sizeof(ar1[0]));
    t_multimap            mp2(ar2, ar2 + sizeof(ar2) / sizeof(ar2[0]));
    t_multimap            mp1_save = mp1;
    t_multimap            mp2_save = mp2;

    swap(mp1, mp2);

    ASSERT_EQ(mp1, mp2_save);
    ASSERT_EQ(mp2, mp1_save);
  }
}
