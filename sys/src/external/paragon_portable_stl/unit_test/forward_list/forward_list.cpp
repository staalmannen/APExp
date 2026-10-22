// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="forward_list.cpp"
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
#include "portable_stl/forward_list/forward_list.h"

// [assign]

TEST(forward_list, assign_count_value) {
  static_cast<void>(test_info_);

  // reuse some nodes
  {
    ::portable_stl::forward_list<std::int32_t> lst{1, 2};

    auto result = lst.assign(4, 3);
    ASSERT_TRUE(result);

    ASSERT_EQ(4, ::portable_stl::distance(lst.begin(), lst.end()));
    auto iter = lst.begin();
    ASSERT_EQ(3, *iter++);
    ASSERT_EQ(3, *iter++);
    ASSERT_EQ(3, *iter++);
    ASSERT_EQ(3, *iter++);
  }

  // remove ending nodes
  {
    ::portable_stl::forward_list<std::int32_t> lst{1, 2, 3, 4, 5, 6};

    auto result = lst.assign(4, 3);
    ASSERT_TRUE(result);

    ASSERT_EQ(4, ::portable_stl::distance(lst.begin(), lst.end()));
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
    test_allocator_helper::test_allocator_statistics        stat;
    t_allocator                                             alloc(4, &stat);
    ::portable_stl::forward_list<std::int32_t, t_allocator> lst(alloc);
    auto                                                    lst_ref = lst;

    stat.m_throw_after = 3;
    auto result        = lst.assign(4, 3);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    /* Strong exception guarantee*/
    ASSERT_EQ(lst_ref, lst);
  }
}

TEST(forward_list, assign_iter_iter) {
  static_cast<void>(test_info_);

  std::int32_t                 arr[] = {1, 2, 3, 4};
  ::portable_stl::size_t const arr_size{sizeof(arr) / sizeof(arr[0])};

  {
    ::portable_stl::forward_list<std::int32_t> lst;

    auto result = lst.assign(test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
                             test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size));
    ASSERT_TRUE(result);

    ASSERT_EQ(4, ::portable_stl::distance(lst.begin(), lst.end()));
    auto iter = lst.begin();
    ASSERT_EQ(1, *iter++);
    ASSERT_EQ(2, *iter++);
    ASSERT_EQ(3, *iter++);
    ASSERT_EQ(4, *iter++);
  }

  // remove ending nodes
  {
    ::portable_stl::forward_list<std::int32_t> lst{1, 2, 3, 4, 5, 6};

    auto result = lst.assign(test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
                             test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size));
    ASSERT_TRUE(result);

    ASSERT_EQ(4, ::portable_stl::distance(lst.begin(), lst.end()));
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
    test_allocator_helper::test_allocator_statistics        stat;
    t_allocator                                             alloc(4, &stat);
    ::portable_stl::forward_list<std::int32_t, t_allocator> lst(alloc);
    auto                                                    lst_ref = lst;

    stat.m_throw_after = 3;
    auto result        = lst.assign(test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
                             test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size));
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    /* Strong exception guarantee*/
    ASSERT_EQ(lst_ref, lst);
  }
}

TEST(forward_list, assign_init_forward_list) {
  static_cast<void>(test_info_);

  ::portable_stl::forward_list<std::int32_t> lst{5, 6, 7};

  auto result = lst.assign({1, 2, 3, 4});
  ASSERT_TRUE(result);

  ASSERT_EQ(4, ::portable_stl::distance(lst.begin(), lst.end()));
  auto iter = lst.begin();
  ASSERT_EQ(1, *iter++);
  ASSERT_EQ(2, *iter++);
  ASSERT_EQ(3, *iter++);
  ASSERT_EQ(4, *iter++);
}

// [operator=]

// forward_list& operator=(const forward_list& c);
TEST(forward_list, assign_op_copy) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  ::portable_stl::forward_list<std::int32_t, t_allocator> lst(3, 2, t_allocator(5));
  ::portable_stl::forward_list<std::int32_t, t_allocator> lst2(lst, t_allocator(3));
  lst2 = lst;
  ASSERT_EQ(lst2, lst);
  ASSERT_EQ(lst2.get_allocator(), t_allocator(3));
}

// forward_list& operator=(forward_list&& c);
TEST(forward_list, assign_op_move) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias.
   */
  using t_move_only = test_common_helper::MoveOnly;
  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<t_move_only>;

  /**
   * @brief Moving iterator alias.
   */
  using t_move_iter = ::portable_stl::move_iterator<t_move_only *>;

  /**
   * @brief List alias.
   */
  using t_flist = ::portable_stl::forward_list<t_move_only, t_allocator>;

  // reuse nodes + add lacking, same allocator
  {
    t_move_only arr0[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    t_move_only arr1[] = {10, 11, 12, 13};

    t_flist lst0(t_move_iter(std::begin(arr0)),
                 t_move_iter(std::end(arr0)),
                 t_allocator(10));
    t_flist lst1(t_move_iter(std::begin(arr1)),
                 t_move_iter(std::end(arr1)),
                 t_allocator(10));

    lst1 = std::move(lst0);

    std::int32_t n{0};
    for (t_flist::const_iterator iter{lst1.begin()}, iter_end = lst1.end(); iter != iter_end; ++iter, (void)++n) {
      ASSERT_EQ(n, *iter);
    }

    ASSERT_EQ(10, n);
    ASSERT_TRUE(lst0.empty());
    ASSERT_EQ(t_allocator(10), lst1.get_allocator());
  }

  // reuse nodes + add lacking, different allocators
  {
    t_move_only arr0[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    t_move_only arr1[] = {10, 11, 12, 13};

    t_flist lst0(t_move_iter(std::begin(arr0)),
                 t_move_iter(std::end(arr0)),
                 t_allocator(10));
    t_flist lst1(t_move_iter(std::begin(arr1)),
                 t_move_iter(std::end(arr1)),
                 t_allocator(11));

    lst1 = std::move(lst0);

    std::int32_t n{0};
    for (t_flist::const_iterator iter{lst1.begin()}, iter_end = lst1.end(); iter != iter_end; ++iter, (void)++n) {
      ASSERT_EQ(n, *iter);
    }

    ASSERT_EQ(10, n);
    ASSERT_FALSE(lst0.empty());
    ASSERT_EQ(t_allocator(11), lst1.get_allocator());
  }

  // reuse nodes, same allocator
  {
    t_move_only arr0[] = {10, 11, 12, 13};
    t_move_only arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    t_flist lst0(t_move_iter(std::begin(arr0)),
                 t_move_iter(std::end(arr0)),
                 t_allocator(10));
    t_flist lst1(t_move_iter(std::begin(arr1)),
                 t_move_iter(std::end(arr1)),
                 t_allocator(10));

    lst1 = std::move(lst0);

    std::int32_t n{0};
    for (t_flist::const_iterator iter{lst1.begin()}, iter_end = lst1.end(); iter != iter_end; ++iter, (void)++n) {
      ASSERT_EQ(10 + n, *iter);
    }

    ASSERT_EQ(4, n);
    ASSERT_TRUE(lst0.empty());
    ASSERT_EQ(t_allocator(10), lst1.get_allocator());
  }

  // reuse nodes, different allocators
  {
    t_move_only arr0[] = {10, 11, 12, 13};
    t_move_only arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    t_flist lst0(t_move_iter(std::begin(arr0)),
                 t_move_iter(std::end(arr0)),
                 t_allocator(10));
    t_flist lst1(t_move_iter(std::begin(arr1)),
                 t_move_iter(std::end(arr1)),
                 t_allocator(11));

    lst1 = std::move(lst0);

    std::int32_t n{0};
    for (t_flist::const_iterator iter{lst1.begin()}, iter_end = lst1.end(); iter != iter_end; ++iter, (void)++n) {
      ASSERT_EQ(10 + n, *iter);
    }

    ASSERT_EQ(4, n);
    ASSERT_FALSE(lst0.empty());
    ASSERT_EQ(t_allocator(11), lst1.get_allocator());
  }
}

// forward_list& operator=(initializer_forward_list<value_type> il);
TEST(forward_list, assign_op_init_forward_list) {
  static_cast<void>(test_info_);

  ::portable_stl::forward_list<std::int32_t> lst;
  lst = {3, 4, 5, 6};

  ASSERT_EQ(4, ::portable_stl::distance(lst.begin(), lst.end()));
  auto iter = lst.begin();
  ASSERT_EQ(3, *iter++);
  ASSERT_EQ(4, *iter++);
  ASSERT_EQ(5, *iter++);
  ASSERT_EQ(6, *iter++);
}

// allocator_type get_allocator() const
TEST(forward_list, get_allocator) {
  static_cast<void>(test_info_);

  ::portable_stl::allocator<std::int32_t>  alloc;
  ::portable_stl::forward_list<std::int32_t> const lst(alloc);
  ASSERT_EQ(alloc, lst.get_allocator());
}

// [compare]

TEST(forward_list, comparison) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::forward_list<std::int32_t> const l1, l2;
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, true, false));
  }
  {
    ::portable_stl::forward_list<std::int32_t> const l1(1, 1), l2(1, 1);
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, true, false));
  }
  {
    std::int32_t                             items[3] = {1, 2, 3};
    ::portable_stl::forward_list<std::int32_t> const l1(items, items + 3);
    ::portable_stl::forward_list<std::int32_t> const l2(items, items + 3);
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, true, false));
  }
  {
    ::portable_stl::forward_list<std::int32_t> const l1(1, 1), l2;
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, false, false));
  }
  {
    ::portable_stl::forward_list<std::int32_t> const l1(1, 1), l2(1, 2);
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, false, true));
  }
  {
    std::int32_t                             items1[2] = {1, 2};
    std::int32_t                             items2[2] = {1, 3};
    ::portable_stl::forward_list<std::int32_t> const l1(items1, items1 + 2);
    ::portable_stl::forward_list<std::int32_t> const l2(items2, items2 + 2);
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, false, true));
  }
  {
    std::int32_t                             items1[2] = {2, 2};
    std::int32_t                             items2[2] = {1, 3};
    ::portable_stl::forward_list<std::int32_t> const l1(items1, items1 + 2);
    ::portable_stl::forward_list<std::int32_t> const l2(items2, items2 + 2);
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, false, false));
  }

  using t_less_and_eq_comp = test_common_helper::LessAndEqComp;
  {
    ::portable_stl::forward_list<t_less_and_eq_comp> const l1, l2;
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, true, false));
  }
  {
    ::portable_stl::forward_list<t_less_and_eq_comp> const l1(1, t_less_and_eq_comp(1));
    ::portable_stl::forward_list<t_less_and_eq_comp> const l2(1, t_less_and_eq_comp(1));
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, true, false));
  }
  {
    t_less_and_eq_comp items[3] = {t_less_and_eq_comp(1), t_less_and_eq_comp(2), t_less_and_eq_comp(3)};
    ::portable_stl::forward_list<t_less_and_eq_comp> const l1(items, items + 3);
    ::portable_stl::forward_list<t_less_and_eq_comp> const l2(items, items + 3);
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, true, false));
  }
  {
    ::portable_stl::forward_list<t_less_and_eq_comp> const l1(1, t_less_and_eq_comp(1));
    ::portable_stl::forward_list<t_less_and_eq_comp> const l2;
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, false, false));
  }
  {
    ::portable_stl::forward_list<t_less_and_eq_comp> const l1(1, t_less_and_eq_comp(1));
    ::portable_stl::forward_list<t_less_and_eq_comp> const l2(1, t_less_and_eq_comp(2));
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, false, true));
  }
  {
    t_less_and_eq_comp                             items1[2] = {t_less_and_eq_comp(1), t_less_and_eq_comp(2)};
    t_less_and_eq_comp                             items2[2] = {t_less_and_eq_comp(1), t_less_and_eq_comp(3)};
    ::portable_stl::forward_list<t_less_and_eq_comp> const l1(items1, items1 + 2);
    ::portable_stl::forward_list<t_less_and_eq_comp> const l2(items2, items2 + 2);
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, false, true));
  }
  {
    t_less_and_eq_comp                             items1[2] = {t_less_and_eq_comp(2), t_less_and_eq_comp(2)};
    t_less_and_eq_comp                             items2[2] = {t_less_and_eq_comp(1), t_less_and_eq_comp(3)};
    ::portable_stl::forward_list<t_less_and_eq_comp> const l1(items1, items1 + 2);
    ::portable_stl::forward_list<t_less_and_eq_comp> const l2(items2, items2 + 2);
    ASSERT_TRUE(test_common_helper::testComparisons(l1, l2, false, false));
  }
}
