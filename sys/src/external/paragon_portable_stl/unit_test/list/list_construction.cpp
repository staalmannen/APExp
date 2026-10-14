// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="list_construction.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "../common/default_only.h"
#include "../common/move_only.h"
#include "../common/test_allocator.h"
#include "../iterator_helper.h"
#include "portable_stl/list/list.h"

// (1-2) explicit list(const Alloc& = Alloc());
TEST(list, constructor_default) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::list<std::int32_t> lst;
    ASSERT_EQ(0U, lst.size());
    ASSERT_EQ(0U, ::portable_stl::distance(lst.begin(), lst.end()));
  }
  {
    ::portable_stl::list<std::int32_t> lst = {};
    ASSERT_EQ(0U, lst.size());
    ASSERT_EQ(0U, ::portable_stl::distance(lst.begin(), lst.end()));
  }
  {
    ::portable_stl::list<std::int32_t> lst((::portable_stl::allocator<std::int32_t>()));
    ASSERT_EQ(0U, lst.size());
    ASSERT_EQ(0U, ::portable_stl::distance(lst.begin(), lst.end()));
  }
  {
    ::portable_stl::list<test_common_helper::DefaultOnly> lst;
    ASSERT_EQ(0U, lst.size());
    ASSERT_EQ(0U, ::portable_stl::distance(lst.begin(), lst.end()));
  }
  {
    ::portable_stl::list<test_common_helper::DefaultOnly> lst(
      (::portable_stl::allocator<test_common_helper::DefaultOnly>()));
    ASSERT_EQ(0U, lst.size());
    ASSERT_EQ(0U, ::portable_stl::distance(lst.begin(), lst.end()));
  }
}

namespace test_list_helper {
template<class t_type> class AllocMayThrow final {
public:
  /**
   * @brief Value type.
   */
  using value_type = t_type;

  AllocMayThrow(AllocMayThrow const &);
  void allocate(::portable_stl::size_t);
};
} // namespace test_list_helper

TEST(list, constructor_default_noexcept) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias.
   */
  using t_move_only = test_common_helper::MoveOnly;
  {
    /**
     * @brief Alias.
     */
    using t_list = ::portable_stl::list<t_move_only>;
    static_assert(std::is_nothrow_default_constructible<t_list>{}, "");
  }
  {
    /**
     * @brief Alias.
     */
    using t_list = ::portable_stl::list<t_move_only, test_allocator_helper::test_allocator<t_move_only>>;
    static_assert(std::is_nothrow_default_constructible<t_list>{}, "");
  }

  // Allocator may throw.
  {
    /**
     * @brief Alias.
     */
    using t_list = ::portable_stl::list<t_move_only, test_list_helper::AllocMayThrow<t_move_only>>;
    static_assert(!std::is_nothrow_default_constructible<t_list>{}, "");
  }
}

// (3) list(size_type n, const T& value, const Allocator& = Allocator());
TEST(list, constructor_count_value) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::list<std::int32_t> lst(3, 2);
    ASSERT_EQ(3, lst.size());
    ASSERT_EQ(3, ::portable_stl::distance(lst.begin(), lst.end()));
    auto iter = lst.begin();
    ASSERT_EQ(2, *iter);
    ++iter;
    ASSERT_EQ(2, *iter);
    ++iter;
    ASSERT_EQ(2, *iter);
  }

  // bad allocation
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::TestSimpleAllocator<std::int32_t>;

    /**
     * @brief Node allocator alias.
     */
    using t_node_allocator = test_allocator_helper::TestSimpleAllocator<portable_stl::list_node<std::int32_t, void *>>;
    t_node_allocator::m_counter_ok_allocation = 3;
    try {
      ::portable_stl::list<std::int32_t, t_allocator> lst(5, 2);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }

    t_node_allocator::m_counter_ok_allocation = 10000;
  }
}

TEST(list, make_count_value) {
  static_cast<void>(test_info_);

  {
    auto result = ::portable_stl::list<std::int32_t>::make_list(3, 2);
    ASSERT_TRUE(result);
    auto lst = result.value();

    ASSERT_EQ(3, lst.size());
    ASSERT_EQ(3, ::portable_stl::distance(lst.begin(), lst.end()));
    auto iter = lst.begin();
    ASSERT_EQ(2, *iter);
    ++iter;
    ASSERT_EQ(2, *iter);
    ++iter;
    ASSERT_EQ(2, *iter);
  }

  // bad allocation
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::TestSimpleAllocator<std::int32_t>;

    /**
     * @brief Node allocator alias.
     */
    using t_node_allocator = test_allocator_helper::TestSimpleAllocator<portable_stl::list_node<std::int32_t, void *>>;
    t_node_allocator::m_counter_ok_allocation = 3;

    auto result = ::portable_stl::list<std::int32_t, t_allocator>::make_list(5, 2);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    t_node_allocator::m_counter_ok_allocation = 10000;
  }
}

// (3) list(size_type n, const T& value, const Allocator&);
TEST(list, constructor_count_value_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  {
    t_allocator alloc(7);

    ::portable_stl::list<std::int32_t, t_allocator> lst(3, 4, alloc);
    ASSERT_EQ(3, lst.size());
    ASSERT_EQ(3, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(t_allocator{7}, lst.get_allocator());
    auto iter = lst.begin();
    ASSERT_EQ(4, *iter);
    ++iter;
    ASSERT_EQ(4, *iter);
    ++iter;
    ASSERT_EQ(4, *iter);
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 3;
    t_allocator alloc{&stat};
    try {
      ::portable_stl::list<std::int32_t, t_allocator> lst(5, 2, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

TEST(list, make_count_value_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  {
    t_allocator alloc(7);

    auto result = ::portable_stl::list<std::int32_t, t_allocator>::make_list(3, 4, alloc);
    ASSERT_TRUE(result);
    auto lst = result.value();

    ASSERT_EQ(3, lst.size());
    ASSERT_EQ(3, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(t_allocator{7}, lst.get_allocator());
    auto iter = lst.begin();
    ASSERT_EQ(4, *iter);
    ++iter;
    ASSERT_EQ(4, *iter);
    ++iter;
    ASSERT_EQ(4, *iter);
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 3;
    t_allocator alloc{&stat};

    auto result = ::portable_stl::list<std::int32_t, t_allocator>::make_list(5, 2, alloc);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }
}

// (4a) explicit list(size_type num);
TEST(list, constructor_count) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::list<std::int32_t> lst(3);
    ASSERT_EQ(3, lst.size());
    ASSERT_EQ(3, ::portable_stl::distance(lst.begin(), lst.end()));
    auto iter = lst.begin();
    ASSERT_EQ(0, *iter);
    ++iter;
    ASSERT_EQ(0, *iter);
    ++iter;
    ASSERT_EQ(0, *iter);
  }

  // bad allocation
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::TestSimpleAllocator<std::int32_t>;

    /**
     * @brief Node allocator alias.
     */
    using t_node_allocator = test_allocator_helper::TestSimpleAllocator<portable_stl::list_node<std::int32_t, void *>>;
    t_node_allocator::m_counter_ok_allocation = 3;
    try {
      ::portable_stl::list<std::int32_t, t_allocator> lst(5);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }

    t_node_allocator::m_counter_ok_allocation = 10000;
  }
}

TEST(list, make_count) {
  static_cast<void>(test_info_);

  {
    auto result = ::portable_stl::list<std::int32_t>::make_list(3);
    ASSERT_TRUE(result);
    auto lst = result.value();

    ASSERT_EQ(3, lst.size());
    ASSERT_EQ(3, ::portable_stl::distance(lst.begin(), lst.end()));
    auto iter = lst.begin();
    ASSERT_EQ(0, *iter);
    ++iter;
    ASSERT_EQ(0, *iter);
    ++iter;
    ASSERT_EQ(0, *iter);
  }

  // bad allocation
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::TestSimpleAllocator<std::int32_t>;

    /**
     * @brief Node allocator alias.
     */
    using t_node_allocator = test_allocator_helper::TestSimpleAllocator<portable_stl::list_node<std::int32_t, void *>>;
    t_node_allocator::m_counter_ok_allocation = 3;

    auto result = ::portable_stl::list<std::int32_t, t_allocator>::make_list(5);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    t_node_allocator::m_counter_ok_allocation = 10000;
  }
}

// (4b) list(size_type num, allocator_type const &alloc);
TEST(list, constructor_count_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  {
    t_allocator alloc(7);

    ::portable_stl::list<std::int32_t, t_allocator> lst(3, alloc);
    ASSERT_EQ(3, lst.size());
    ASSERT_EQ(3, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(t_allocator{7}, lst.get_allocator());
    auto iter = lst.begin();
    ASSERT_EQ(0, *iter);
    ++iter;
    ASSERT_EQ(0, *iter);
    ++iter;
    ASSERT_EQ(0, *iter);
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 3;
    t_allocator alloc{&stat};
    try {
      ::portable_stl::list<std::int32_t, t_allocator> lst(5, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

TEST(list, make_count_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  {
    t_allocator alloc(7);

    auto result = ::portable_stl::list<std::int32_t, t_allocator>::make_list(3, alloc);
    ASSERT_TRUE(result);
    auto lst = result.value();

    ASSERT_EQ(3, lst.size());
    ASSERT_EQ(3, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(t_allocator{7}, lst.get_allocator());
    auto iter = lst.begin();
    ASSERT_EQ(0, *iter);
    ++iter;
    ASSERT_EQ(0, *iter);
    ++iter;
    ASSERT_EQ(0, *iter);
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 3;
    t_allocator alloc{&stat};

    auto result = ::portable_stl::list<std::int32_t, t_allocator>::make_list(5, alloc);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }
}

// (5a) template<class t_input_iterator> list(t_input_iterator first, t_input_iterator last)
TEST(list, constructor_iter_iter) {
  static_cast<void>(test_info_);

  std::int32_t                 arr[] = {0, 1, 2, 3, 4};
  ::portable_stl::size_t const arr_size{sizeof(arr) / sizeof(arr[0])};

  {
    ::portable_stl::list<std::int32_t> lst(test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
                                           test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size));

    ASSERT_EQ(arr_size, lst.size());
    ASSERT_EQ(arr_size, ::portable_stl::distance(lst.begin(), lst.end()));

    auto iter     = lst.cbegin();
    auto iter_end = lst.cend();
    for (std::int32_t i{0}; iter != iter_end; ++iter, ++i) {
      ASSERT_EQ(i, *iter);
    }
  }

  // bad allocation
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::TestSimpleAllocator<std::int32_t>;

    /**
     * @brief Node allocator alias.
     */
    using t_node_allocator = test_allocator_helper::TestSimpleAllocator<portable_stl::list_node<std::int32_t, void *>>;
    t_node_allocator::m_counter_ok_allocation = 3;
    try {
      ::portable_stl::list<std::int32_t, t_allocator> lst(
        test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
        test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size));
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }

    t_node_allocator::m_counter_ok_allocation = 10000;
  }
}

TEST(list, make_iter_iter) {
  static_cast<void>(test_info_);

  std::int32_t                 arr[] = {0, 1, 2, 3, 4};
  ::portable_stl::size_t const arr_size{sizeof(arr) / sizeof(arr[0])};

  {
    auto result = ::portable_stl::list<std::int32_t>::make_list(
      test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
      test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size));
    ASSERT_TRUE(result);
    auto lst = result.value();

    ASSERT_EQ(arr_size, lst.size());
    ASSERT_EQ(arr_size, ::portable_stl::distance(lst.begin(), lst.end()));

    auto iter     = lst.cbegin();
    auto iter_end = lst.cend();
    for (std::int32_t i{0}; iter != iter_end; ++iter, ++i) {
      ASSERT_EQ(i, *iter);
    }
  }

  // bad allocation
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::TestSimpleAllocator<std::int32_t>;

    /**
     * @brief Node allocator alias.
     */
    using t_node_allocator = test_allocator_helper::TestSimpleAllocator<portable_stl::list_node<std::int32_t, void *>>;
    t_node_allocator::m_counter_ok_allocation = 3;

    auto result = ::portable_stl::list<std::int32_t, t_allocator>::make_list(
      test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
      test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size));
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    t_node_allocator::m_counter_ok_allocation = 10000;
  }
}

// (5b) template<class t_input_iterator> list(t_input_iterator first, t_input_iterator last, const Allocator&)
TEST(list, constructor_iter_iter_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  std::int32_t                 arr[] = {0, 1, 2, 3, 4};
  ::portable_stl::size_t const arr_size{sizeof(arr) / sizeof(arr[0])};

  {
    t_allocator                                     alloc(7);
    ::portable_stl::list<std::int32_t, t_allocator> lst(
      test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
      test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size),
      alloc);

    ASSERT_EQ(arr_size, lst.size());
    ASSERT_EQ(arr_size, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(t_allocator{7}, lst.get_allocator());

    auto iter     = lst.cbegin();
    auto iter_end = lst.cend();
    for (std::int32_t i{0}; iter != iter_end; ++iter, ++i) {
      ASSERT_EQ(i, *iter);
    }
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 3;
    t_allocator alloc{&stat};
    try {
      ::portable_stl::list<std::int32_t, t_allocator> lst(
        test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
        test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size),
        alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

TEST(list, make_iter_iter_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  std::int32_t                 arr[] = {0, 1, 2, 3, 4};
  ::portable_stl::size_t const arr_size{sizeof(arr) / sizeof(arr[0])};

  {
    t_allocator alloc(7);
    auto        result = ::portable_stl::list<std::int32_t, t_allocator>::make_list(
      test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
      test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size),
      alloc);
    ASSERT_TRUE(result);
    auto lst = result.value();

    ASSERT_EQ(arr_size, lst.size());
    ASSERT_EQ(arr_size, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(t_allocator{7}, lst.get_allocator());

    auto iter     = lst.cbegin();
    auto iter_end = lst.cend();
    for (std::int32_t i{0}; iter != iter_end; ++iter, ++i) {
      ASSERT_EQ(i, *iter);
    }
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 3;
    t_allocator alloc{&stat};

    auto result = ::portable_stl::list<std::int32_t, t_allocator>::make_list(
      test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
      test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size),
      alloc);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }
}

// (6) list(list const &other);
TEST(list, constructor_copy) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::list<std::int32_t> lst0(3, 2);

    ::portable_stl::list<std::int32_t> lst1 = lst0;
    ASSERT_EQ(lst0, lst1);
  }

  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

    ::portable_stl::list<std::int32_t, t_allocator> lst0(3, 2, t_allocator(5));

    ::portable_stl::list<std::int32_t, t_allocator> lst1 = lst0;
    ASSERT_EQ(lst0, lst1);
    ASSERT_EQ(lst0.get_allocator(), lst1.get_allocator());
  }

  // bad allocation
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::TestSimpleAllocator<std::int32_t>;

    /**
     * @brief Node allocator alias.
     */
    using t_node_allocator = test_allocator_helper::TestSimpleAllocator<portable_stl::list_node<std::int32_t, void *>>;

    ::portable_stl::list<std::int32_t, t_allocator> lst0(5, 2, t_allocator(5));

    t_node_allocator::m_counter_ok_allocation = 3;
    try {
      ::portable_stl::list<std::int32_t, t_allocator> lst1 = lst0;
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }

    t_node_allocator::m_counter_ok_allocation = 10000;
  }
}

TEST(list, make_copy) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::list<std::int32_t> lst0(3, 2);

    auto result = ::portable_stl::list<std::int32_t>::make_list(lst0);
    ASSERT_TRUE(result);
    auto lst1 = result.value();

    ASSERT_EQ(lst0, lst1);
  }

  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

    ::portable_stl::list<std::int32_t, t_allocator> lst0(3, 2, t_allocator(5));

    auto result = ::portable_stl::list<std::int32_t, t_allocator>::make_list(lst0);
    ASSERT_TRUE(result);
    auto lst1 = result.value();

    ASSERT_EQ(lst0, lst1);
    ASSERT_EQ(lst0.get_allocator(), lst1.get_allocator());
  }

  // bad allocation
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::TestSimpleAllocator<std::int32_t>;

    /**
     * @brief Node allocator alias.
     */
    using t_node_allocator = test_allocator_helper::TestSimpleAllocator<portable_stl::list_node<std::int32_t, void *>>;

    ::portable_stl::list<std::int32_t, t_allocator> lst0(5, 2, t_allocator(5));

    t_node_allocator::m_counter_ok_allocation = 3;
    auto result                               = ::portable_stl::list<std::int32_t, t_allocator>::make_list(lst0);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    t_node_allocator::m_counter_ok_allocation = 10000;
  }
}

// (7) list(list const &other, allocator_type const &alloc);
TEST(list, constructor_copy_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  {
    ::portable_stl::list<std::int32_t, t_allocator> lst0(3, 2, t_allocator(5));

    ::portable_stl::list<std::int32_t, t_allocator> lst1(lst0, t_allocator(3));
    ASSERT_EQ(lst0, lst1);
    ASSERT_EQ(t_allocator(3), lst1.get_allocator());
  }

  // bad allocation
  {
    ::portable_stl::list<std::int32_t, t_allocator> lst0(5, 2, t_allocator(5));

    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 3;
    t_allocator alloc{&stat};
    try {
      ::portable_stl::list<std::int32_t, t_allocator> lst1(lst0, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

TEST(list, make_copy_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  {
    ::portable_stl::list<std::int32_t, t_allocator> lst0(3, 2, t_allocator(5));

    auto result = ::portable_stl::list<std::int32_t, t_allocator>::make_list(lst0, t_allocator(3));
    ASSERT_TRUE(result);
    auto lst1 = result.value();

    ASSERT_EQ(lst0, lst1);
    ASSERT_EQ(t_allocator(3), lst1.get_allocator());
  }

  // bad allocation
  {
    ::portable_stl::list<std::int32_t, t_allocator> lst0(5, 2, t_allocator(5));

    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 3;
    t_allocator alloc{&stat};

    auto result = ::portable_stl::list<std::int32_t, t_allocator>::make_list(lst0, alloc);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }
}

// (8) list(list &&other);
TEST(list, constructor_move) {
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

    ::portable_stl::list<t_move_only, t_allocator>::iterator iter = lst.begin();

    ::portable_stl::list<t_move_only, t_allocator> lst2 = std::move(lst);
    ASSERT_EQ(lst0, lst2);
    ASSERT_TRUE(lst.empty());
    ASSERT_EQ(lst2.get_allocator(), lst0.get_allocator());
    ASSERT_EQ(iter, lst2.begin()); // Iterators remain valid
  }
}

// (9) list(list &&other, allocator_type const &alloc);
TEST(list, constructor_move_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias.
   */
  using t_move_only = test_common_helper::MoveOnly;

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<t_move_only>;

  // same allocator
  {
    ::portable_stl::list<t_move_only, t_allocator> lst(t_allocator(5));
    ::portable_stl::list<t_move_only, t_allocator> lst0(t_allocator(5));
    for (std::int32_t i{1}; i <= 3; ++i) {
      lst.push_back(i);
      lst0.push_back(i);
    }

    ::portable_stl::list<t_move_only, t_allocator> lst2(std::move(lst), t_allocator(5));
    ASSERT_EQ(lst0, lst2);
    ASSERT_TRUE(lst.empty());
    ASSERT_EQ(t_allocator(5), lst2.get_allocator());
  }

  // not the same allocator
  {
    ::portable_stl::list<t_move_only, t_allocator> lst(t_allocator(5));
    ::portable_stl::list<t_move_only, t_allocator> lst0(t_allocator(5));
    for (std::int32_t i{1}; i <= 3; ++i) {
      lst.push_back(i);
      lst0.push_back(i);
    }

    ::portable_stl::list<t_move_only, t_allocator> lst2(std::move(lst), t_allocator(6));
    ASSERT_EQ(lst0, lst2);
    ASSERT_FALSE(lst.empty());
    ASSERT_EQ(t_allocator(6), lst2.get_allocator());
  }

  // bad allocation durin internal assing
  {
    ::portable_stl::list<t_move_only, t_allocator> lst(t_allocator(5));
    ::portable_stl::list<t_move_only, t_allocator> lst0(t_allocator(5));
    for (std::int32_t i{1}; i <= 5; ++i) {
      lst.push_back(i);
      lst0.push_back(i);
    }

    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 3;
    t_allocator alloc(6, &stat);
    try {
      ::portable_stl::list<t_move_only, t_allocator> lst2(std::move(lst), alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

TEST(list, make_move_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias.
   */
  using t_move_only = test_common_helper::MoveOnly;

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<t_move_only>;

  // same allocator
  {
    ::portable_stl::list<t_move_only, t_allocator> lst(t_allocator(5));
    ::portable_stl::list<t_move_only, t_allocator> lst0(t_allocator(5));
    for (std::int32_t i{1}; i <= 3; ++i) {
      lst.push_back(i);
      lst0.push_back(i);
    }

    auto result = ::portable_stl::list<t_move_only, t_allocator>::make_list(std::move(lst), t_allocator(5));
    ASSERT_TRUE(result);
    auto lst2 = std::move(result.value());

    ASSERT_EQ(lst0, lst2);
    ASSERT_TRUE(lst.empty());
    ASSERT_EQ(t_allocator(5), lst2.get_allocator());
  }

  // not the same allocator
  {
    ::portable_stl::list<t_move_only, t_allocator> lst(t_allocator(5));
    ::portable_stl::list<t_move_only, t_allocator> lst0(t_allocator(5));
    for (std::int32_t i{1}; i <= 3; ++i) {
      lst.push_back(i);
      lst0.push_back(i);
    }

    auto result = ::portable_stl::list<t_move_only, t_allocator>::make_list(std::move(lst), t_allocator(6));
    ASSERT_TRUE(result);
    auto lst2 = std::move(result.value());

    ASSERT_EQ(lst0, lst2);
    ASSERT_FALSE(lst.empty());
    ASSERT_EQ(t_allocator(6), lst2.get_allocator());
  }

  // bad allocation durin internal assing
  {
    ::portable_stl::list<t_move_only, t_allocator> lst(t_allocator(5));
    ::portable_stl::list<t_move_only, t_allocator> lst0(t_allocator(5));
    for (std::int32_t i{1}; i <= 5; ++i) {
      lst.push_back(i);
      lst0.push_back(i);
    }

    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 3;
    t_allocator alloc(6, &stat);

    auto result = ::portable_stl::list<t_move_only, t_allocator>::make_list(std::move(lst), alloc);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }
}

// (10a) list(std::initializer_list<value_type> init_list);
TEST(list, constructor_init_list) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::list<std::int32_t> lst = {0, 1, 2, 3, 4};

    ASSERT_EQ(5, lst.size());
    ASSERT_EQ(5, ::portable_stl::distance(lst.begin(), lst.end()));

    auto iter     = lst.cbegin();
    auto iter_end = lst.cend();
    for (std::int32_t i{0}; iter != iter_end; ++iter, ++i) {
      ASSERT_EQ(i, *iter);
    }
  }

  // bad allocation
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::TestSimpleAllocator<std::int32_t>;

    /**
     * @brief Node allocator alias.
     */
    using t_node_allocator = test_allocator_helper::TestSimpleAllocator<portable_stl::list_node<std::int32_t, void *>>;
    t_node_allocator::m_counter_ok_allocation = 3;
    try {
      ::portable_stl::list<std::int32_t, t_allocator> lst = {0, 1, 2, 3, 4};
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }

    t_node_allocator::m_counter_ok_allocation = 10000;
  }
}

TEST(list, make_init_list) {
  static_cast<void>(test_info_);

  {
    auto result = ::portable_stl::list<std::int32_t>::make_list({0, 1, 2, 3, 4});
    ASSERT_TRUE(result);
    auto lst = result.value();

    ASSERT_EQ(5, lst.size());
    ASSERT_EQ(5, ::portable_stl::distance(lst.begin(), lst.end()));

    auto iter     = lst.cbegin();
    auto iter_end = lst.cend();
    for (std::int32_t i{0}; iter != iter_end; ++iter, ++i) {
      ASSERT_EQ(i, *iter);
    }
  }

  // bad allocation
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::TestSimpleAllocator<std::int32_t>;

    /**
     * @brief Node allocator alias.
     */
    using t_node_allocator = test_allocator_helper::TestSimpleAllocator<portable_stl::list_node<std::int32_t, void *>>;
    t_node_allocator::m_counter_ok_allocation = 3;

    auto result = ::portable_stl::list<std::int32_t, t_allocator>::make_list({0, 1, 2, 3, 4});
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    t_node_allocator::m_counter_ok_allocation = 10000;
  }
}

// (10b) list(std::initializer_list<value_type> init_list, allocator_type const &alloc);
TEST(list, constructor_init_list_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  {
    t_allocator                                     alloc(7);
    ::portable_stl::list<std::int32_t, t_allocator> lst({0, 1, 2, 3, 4}, alloc);

    ASSERT_EQ(5, lst.size());
    ASSERT_EQ(5, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(t_allocator{7}, lst.get_allocator());

    auto iter     = lst.cbegin();
    auto iter_end = lst.cend();
    for (std::int32_t i{0}; iter != iter_end; ++iter, ++i) {
      ASSERT_EQ(i, *iter);
    }
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 3;
    t_allocator alloc{&stat};
    try {
      ::portable_stl::list<std::int32_t, t_allocator> lst({0, 1, 2, 3, 4}, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

TEST(list, make_init_list_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  {
    t_allocator alloc(7);
    auto        result = ::portable_stl::list<std::int32_t, t_allocator>::make_list({0, 1, 2, 3, 4}, alloc);
    ASSERT_TRUE(result);
    auto lst = result.value();

    ASSERT_EQ(5, lst.size());
    ASSERT_EQ(5, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(t_allocator{7}, lst.get_allocator());

    auto iter     = lst.cbegin();
    auto iter_end = lst.cend();
    for (std::int32_t i{0}; iter != iter_end; ++iter, ++i) {
      ASSERT_EQ(i, *iter);
    }
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 3;
    t_allocator alloc{&stat};

    auto result = ::portable_stl::list<std::int32_t, t_allocator>::make_list({0, 1, 2, 3, 4}, alloc);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }
}
