// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="list.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "../common/move_only.h"
#include "../common/test_allocator.h"
#include "../common/test_comparisons.h"
#include "../iterator_helper.h"
#include "portable_stl/list/list.h"

// [assign]

TEST(list, assign_count_value) {
  static_cast<void>(test_info_);

  // reuse some nodes
  {
    ::portable_stl::list<std::int32_t> lst{1, 2};

    auto result = lst.assign(4, 3);
    ASSERT_TRUE(result);

    ASSERT_EQ(4, lst.size());
    auto iter = lst.begin();
    ASSERT_EQ(3, *iter++);
    ASSERT_EQ(3, *iter++);
    ASSERT_EQ(3, *iter++);
    ASSERT_EQ(3, *iter++);
  }

  // remove ending nodes
  {
    ::portable_stl::list<std::int32_t> lst{1, 2, 3, 4, 5, 6};

    auto result = lst.assign(4, 3);
    ASSERT_TRUE(result);

    ASSERT_EQ(4, lst.size());
    auto iter = lst.begin();
    ASSERT_EQ(3, *iter++);
    ASSERT_EQ(3, *iter++);
    ASSERT_EQ(3, *iter++);
    ASSERT_EQ(3, *iter++);
  }

  // bad allocation (node creation)
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;
    test_allocator_helper::test_allocator_statistics stat;
    t_allocator                                      alloc(4, &stat);
    ::portable_stl::list<std::int32_t, t_allocator>  lst(alloc);
    auto                                             lst_ref = lst;

    stat.m_throw_after = 3;
    auto result        = lst.assign(4, 3);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    /* Strong exception guarantee*/
    ASSERT_EQ(lst_ref, lst);
  }
}

TEST(list, assign_iter_iter) {
  static_cast<void>(test_info_);

  std::int32_t                 arr[] = {1, 2, 3, 4};
  ::portable_stl::size_t const arr_size{sizeof(arr) / sizeof(arr[0])};

  {
    ::portable_stl::list<std::int32_t> lst;

    auto result = lst.assign(test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
                             test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size));
    ASSERT_TRUE(result);

    ASSERT_EQ(4, lst.size());
    auto iter = lst.begin();
    ASSERT_EQ(1, *iter++);
    ASSERT_EQ(2, *iter++);
    ASSERT_EQ(3, *iter++);
    ASSERT_EQ(4, *iter++);
  }

  // remove ending nodes
  {
    ::portable_stl::list<std::int32_t> lst{1, 2, 3, 4, 5, 6};

    auto result = lst.assign(test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
                             test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size));
    ASSERT_TRUE(result);

    ASSERT_EQ(4, lst.size());
    auto iter = lst.begin();
    ASSERT_EQ(1, *iter++);
    ASSERT_EQ(2, *iter++);
    ASSERT_EQ(3, *iter++);
    ASSERT_EQ(4, *iter++);
  }

  // bad allocation (node creation)
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;
    test_allocator_helper::test_allocator_statistics stat;
    t_allocator                                      alloc(4, &stat);
    ::portable_stl::list<std::int32_t, t_allocator>  lst(alloc);
    auto                                             lst_ref = lst;

    stat.m_throw_after = 3;
    auto result        = lst.assign(test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
                             test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size));
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    /* Strong exception guarantee*/
    ASSERT_EQ(lst_ref, lst);
  }
}

TEST(list, assign_init_list) {
  static_cast<void>(test_info_);

  ::portable_stl::list<std::int32_t> lst{5, 6, 7};

  auto result = lst.assign({1, 2, 3, 4});
  ASSERT_TRUE(result);

  ASSERT_EQ(4, lst.size());
  auto iter = lst.begin();
  ASSERT_EQ(1, *iter++);
  ASSERT_EQ(2, *iter++);
  ASSERT_EQ(3, *iter++);
  ASSERT_EQ(4, *iter++);
}

// [operator=]

// list& operator=(const list& c);
TEST(list, assign_op_copy) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  ::portable_stl::list<std::int32_t, t_allocator> lst(3, 2, t_allocator(5));
  ::portable_stl::list<std::int32_t, t_allocator> lst2(lst, t_allocator(3));
  lst2 = lst;
  ASSERT_EQ(lst2, lst);
  ASSERT_EQ(lst2.get_allocator(), t_allocator(3));
}

// list& operator=(list&& c);
TEST(list, assign_op_move) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias.
   */
  using t_move_only = test_common_helper::MoveOnly;
  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<t_move_only>;

  {
    ::portable_stl::list<t_move_only, t_allocator> lst(t_allocator(5));
    ::portable_stl::list<t_move_only, t_allocator> lst0(t_allocator(5));
    for (std::int32_t i{1}; i <= 3; ++i) {
      lst.push_back(i);
      lst0.push_back(i);
    }

    ::portable_stl::list<t_move_only, t_allocator>           lst2(t_allocator(5));
    ::portable_stl::list<t_move_only, t_allocator>::iterator iter = lst.begin();
    lst2                                                          = std::move(lst);
    ASSERT_EQ(lst2, lst0);
    ASSERT_TRUE(lst.empty());
    ASSERT_EQ(lst2.get_allocator(), lst0.get_allocator());
    ASSERT_EQ(iter, lst2.begin()); // Iterators remain valid
  }
  {
    ::portable_stl::list<t_move_only, t_allocator> lst(t_allocator(5));
    ::portable_stl::list<t_move_only, t_allocator> lst0(t_allocator(5));
    for (std::int32_t i{1}; i <= 3; ++i) {
      lst.push_back(i);
      lst0.push_back(i);
    }
    ::portable_stl::list<t_move_only, t_allocator> lst2(t_allocator(6));
    lst2 = std::move(lst);
    ASSERT_EQ(lst2, lst0);
    ASSERT_FALSE(lst.empty());
    ASSERT_EQ(lst2.get_allocator(), t_allocator(6));
  }
}

// list& operator=(initializer_list<value_type> il);
TEST(list, assign_op_init_list) {
  static_cast<void>(test_info_);

  ::portable_stl::list<std::int32_t> lst;
  lst = {3, 4, 5, 6};
  ASSERT_EQ(4, lst.size());
  auto iter = lst.begin();
  ASSERT_EQ(3, *iter++);
  ASSERT_EQ(4, *iter++);
  ASSERT_EQ(5, *iter++);
  ASSERT_EQ(6, *iter++);
}

// allocator_type get_allocator() const
TEST(list, get_allocator) {
  static_cast<void>(test_info_);

  ::portable_stl::allocator<std::int32_t>  alloc;
  ::portable_stl::list<std::int32_t> const lst(alloc);
  ASSERT_EQ(alloc, lst.get_allocator());
}

// [compare]

TEST(list, comparison) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::list<std::int32_t> const l1, l2;
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, true, false));
  }
  {
    ::portable_stl::list<std::int32_t> const l1(1, 1), l2(1, 1);
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, true, false));
  }
  {
    std::int32_t                             items[3] = {1, 2, 3};
    ::portable_stl::list<std::int32_t> const l1(items, items + 3);
    ::portable_stl::list<std::int32_t> const l2(items, items + 3);
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, true, false));
  }
  {
    ::portable_stl::list<std::int32_t> const l1(1, 1), l2;
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, false, false));
  }
  {
    ::portable_stl::list<std::int32_t> const l1(1, 1), l2(1, 2);
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, false, true));
  }
  {
    std::int32_t                             items1[2] = {1, 2};
    std::int32_t                             items2[2] = {1, 3};
    ::portable_stl::list<std::int32_t> const l1(items1, items1 + 2);
    ::portable_stl::list<std::int32_t> const l2(items2, items2 + 2);
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, false, true));
  }
  {
    std::int32_t                             items1[2] = {2, 2};
    std::int32_t                             items2[2] = {1, 3};
    ::portable_stl::list<std::int32_t> const l1(items1, items1 + 2);
    ::portable_stl::list<std::int32_t> const l2(items2, items2 + 2);
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, false, false));
  }

  using t_less_and_eq_comp = test_common_helper::LessAndEqComp;
  {
    ::portable_stl::list<t_less_and_eq_comp> const l1, l2;
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, true, false));
  }
  {
    ::portable_stl::list<t_less_and_eq_comp> const l1(1, t_less_and_eq_comp(1));
    ::portable_stl::list<t_less_and_eq_comp> const l2(1, t_less_and_eq_comp(1));
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, true, false));
  }
  {
    t_less_and_eq_comp items[3] = {t_less_and_eq_comp(1), t_less_and_eq_comp(2), t_less_and_eq_comp(3)};
    ::portable_stl::list<t_less_and_eq_comp> const l1(items, items + 3);
    ::portable_stl::list<t_less_and_eq_comp> const l2(items, items + 3);
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, true, false));
  }
  {
    ::portable_stl::list<t_less_and_eq_comp> const l1(1, t_less_and_eq_comp(1));
    ::portable_stl::list<t_less_and_eq_comp> const l2;
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, false, false));
  }
  {
    ::portable_stl::list<t_less_and_eq_comp> const l1(1, t_less_and_eq_comp(1));
    ::portable_stl::list<t_less_and_eq_comp> const l2(1, t_less_and_eq_comp(2));
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, false, true));
  }
  {
    t_less_and_eq_comp                             items1[2] = {t_less_and_eq_comp(1), t_less_and_eq_comp(2)};
    t_less_and_eq_comp                             items2[2] = {t_less_and_eq_comp(1), t_less_and_eq_comp(3)};
    ::portable_stl::list<t_less_and_eq_comp> const l1(items1, items1 + 2);
    ::portable_stl::list<t_less_and_eq_comp> const l2(items2, items2 + 2);
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, false, true));
  }
  {
    t_less_and_eq_comp                             items1[2] = {t_less_and_eq_comp(2), t_less_and_eq_comp(2)};
    t_less_and_eq_comp                             items2[2] = {t_less_and_eq_comp(1), t_less_and_eq_comp(3)};
    ::portable_stl::list<t_less_and_eq_comp> const l1(items1, items1 + 2);
    ::portable_stl::list<t_less_and_eq_comp> const l2(items2, items2 + 2);
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, false, false));
  }
}
