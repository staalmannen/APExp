// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="forward_list_construction.cpp"
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
#include "portable_stl/forward_list/forward_list.h"

// (1-2) explicit forward_list(const Alloc& = Alloc());
TEST(forward_list, constructor_default) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::forward_list<std::int32_t> lst;
    ASSERT_EQ(0U, ::portable_stl::distance(lst.begin(), lst.end()));
  }
  {
    ::portable_stl::forward_list<std::int32_t> lst = {};
    ASSERT_EQ(0U, ::portable_stl::distance(lst.begin(), lst.end()));
  }
  {
    ::portable_stl::forward_list<std::int32_t> lst((::portable_stl::allocator<std::int32_t>()));
    ASSERT_EQ(0U, ::portable_stl::distance(lst.begin(), lst.end()));
  }
  {
    ::portable_stl::forward_list<test_common_helper::DefaultOnly> lst;
    ASSERT_EQ(0U, ::portable_stl::distance(lst.begin(), lst.end()));
  }
  {
    ::portable_stl::forward_list<test_common_helper::DefaultOnly> lst(
      (::portable_stl::allocator<test_common_helper::DefaultOnly>()));
    ASSERT_EQ(0U, ::portable_stl::distance(lst.begin(), lst.end()));
  }
}

namespace test_forward_list_helper {
template<class t_type> class AllocMayThrow final {
public:
  /**
   * @brief Value type.
   */
  using value_type = t_type;

  AllocMayThrow(AllocMayThrow const &);
  void allocate(::portable_stl::size_t);
};
} // namespace test_forward_list_helper

TEST(forward_list, constructor_default_noexcept) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias.
   */
  using t_move_only = test_common_helper::MoveOnly;
  {
    /**
     * @brief Alias.
     */
    using t_forward_list = ::portable_stl::forward_list<t_move_only>;
    static_assert(std::is_nothrow_default_constructible<t_forward_list>{}, "");
  }
  {
    /**
     * @brief Alias.
     */
    using t_forward_list
      = ::portable_stl::forward_list<t_move_only, test_allocator_helper::test_allocator<t_move_only>>;
    static_assert(std::is_nothrow_default_constructible<t_forward_list>{}, "");
  }

  // Allocator may throw.
  {
    /**
     * @brief Alias.
     */
    using t_forward_list
      = ::portable_stl::forward_list<t_move_only, test_forward_list_helper::AllocMayThrow<t_move_only>>;
    static_assert(!std::is_nothrow_default_constructible<t_forward_list>{}, "");
  }
}

// (3a) forward_list(size_type n, const T& value, const Allocator& = Allocator());
TEST(forward_list, constructor_count_value) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::forward_list<std::int32_t> lst(3, 2);
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
    using t_node_allocator
      = test_allocator_helper::TestSimpleAllocator<portable_stl::forward_list_node<std::int32_t, void *>>;
    t_node_allocator::m_counter_ok_allocation = 3;
    try {
      ::portable_stl::forward_list<std::int32_t, t_allocator> lst(5, 2);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }

    t_node_allocator::m_counter_ok_allocation = 10000;
  }
}

TEST(forward_list, make_count_value) {
  static_cast<void>(test_info_);

  {
    auto result = ::portable_stl::forward_list<std::int32_t>::make_forward_list(3, 2);
    ASSERT_TRUE(result);
    auto lst = result.value();

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
    using t_node_allocator
      = test_allocator_helper::TestSimpleAllocator<portable_stl::forward_list_node<std::int32_t, void *>>;
    t_node_allocator::m_counter_ok_allocation = 3;

    auto result = ::portable_stl::forward_list<std::int32_t, t_allocator>::make_forward_list(5, 2);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    t_node_allocator::m_counter_ok_allocation = 10000;
  }
}

// (3b) forward_list(size_type n, const T& value, const Allocator&);
TEST(forward_list, constructor_count_value_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  {
    t_allocator alloc(7);

    ::portable_stl::forward_list<std::int32_t, t_allocator> lst(3, 4, alloc);
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
      ::portable_stl::forward_list<std::int32_t, t_allocator> lst(5, 2, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

TEST(forward_list, make_count_value_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  {
    t_allocator alloc(7);

    auto result = ::portable_stl::forward_list<std::int32_t, t_allocator>::make_forward_list(3, 4, alloc);
    ASSERT_TRUE(result);
    auto lst = result.value();

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

    auto result = ::portable_stl::forward_list<std::int32_t, t_allocator>::make_forward_list(5, 2, alloc);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }
}

// (4a) explicit forward_list(size_type num);
TEST(forward_list, constructor_count) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::forward_list<std::int32_t> lst(3);
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
    using t_node_allocator
      = test_allocator_helper::TestSimpleAllocator<portable_stl::forward_list_node<std::int32_t, void *>>;
    t_node_allocator::m_counter_ok_allocation = 3;
    try {
      ::portable_stl::forward_list<std::int32_t, t_allocator> lst(5);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }

    t_node_allocator::m_counter_ok_allocation = 10000;
  }
}

TEST(forward_list, make_count) {
  static_cast<void>(test_info_);

  {
    auto result = ::portable_stl::forward_list<std::int32_t>::make_forward_list(3);
    ASSERT_TRUE(result);
    auto lst = result.value();

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
    using t_node_allocator
      = test_allocator_helper::TestSimpleAllocator<portable_stl::forward_list_node<std::int32_t, void *>>;
    t_node_allocator::m_counter_ok_allocation = 3;

    auto result = ::portable_stl::forward_list<std::int32_t, t_allocator>::make_forward_list(5);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    t_node_allocator::m_counter_ok_allocation = 10000;
  }
}

// (4b) forward_list(size_type num, allocator_type const &alloc);
TEST(forward_list, constructor_count_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  {
    t_allocator alloc(7);

    ::portable_stl::forward_list<std::int32_t, t_allocator> lst(3, alloc);

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
      ::portable_stl::forward_list<std::int32_t, t_allocator> lst(5, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

TEST(forward_list, make_count_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  {
    t_allocator alloc(7);

    auto result = ::portable_stl::forward_list<std::int32_t, t_allocator>::make_forward_list(3, alloc);
    ASSERT_TRUE(result);
    auto lst = result.value();

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

    auto result = ::portable_stl::forward_list<std::int32_t, t_allocator>::make_forward_list(5, alloc);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }
}

// (5a) template<class t_input_iterator> forward_list(t_input_iterator first, t_input_iterator last)
TEST(forward_list, constructor_iter_iter) {
  static_cast<void>(test_info_);

  std::int32_t                 arr[] = {0, 1, 2, 3, 4};
  ::portable_stl::size_t const arr_size{sizeof(arr) / sizeof(arr[0])};

  {
    ::portable_stl::forward_list<std::int32_t> lst(
      test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
      test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size));

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
    using t_node_allocator
      = test_allocator_helper::TestSimpleAllocator<portable_stl::forward_list_node<std::int32_t, void *>>;
    t_node_allocator::m_counter_ok_allocation = 3;
    try {
      ::portable_stl::forward_list<std::int32_t, t_allocator> lst(
        test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
        test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size));
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }

    t_node_allocator::m_counter_ok_allocation = 10000;
  }
}

TEST(forward_list, make_iter_iter) {
  static_cast<void>(test_info_);

  std::int32_t                 arr[] = {0, 1, 2, 3, 4};
  ::portable_stl::size_t const arr_size{sizeof(arr) / sizeof(arr[0])};

  {
    auto result = ::portable_stl::forward_list<std::int32_t>::make_forward_list(
      test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
      test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size));
    ASSERT_TRUE(result);
    auto lst = result.value();

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
    using t_node_allocator
      = test_allocator_helper::TestSimpleAllocator<portable_stl::forward_list_node<std::int32_t, void *>>;
    t_node_allocator::m_counter_ok_allocation = 3;

    auto result = ::portable_stl::forward_list<std::int32_t, t_allocator>::make_forward_list(
      test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
      test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size));
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    t_node_allocator::m_counter_ok_allocation = 10000;
  }
}

// (5b) template<class t_input_iterator> forward_list(t_input_iterator first, t_input_iterator last, const Allocator&)
TEST(forward_list, constructor_iter_iter_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  std::int32_t                 arr[] = {0, 1, 2, 3, 4};
  ::portable_stl::size_t const arr_size{sizeof(arr) / sizeof(arr[0])};

  {
    t_allocator                                             alloc(7);
    ::portable_stl::forward_list<std::int32_t, t_allocator> lst(
      test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
      test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size),
      alloc);

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
      ::portable_stl::forward_list<std::int32_t, t_allocator> lst(
        test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
        test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size),
        alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

TEST(forward_list, make_iter_iter_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  std::int32_t                 arr[] = {0, 1, 2, 3, 4};
  ::portable_stl::size_t const arr_size{sizeof(arr) / sizeof(arr[0])};

  {
    t_allocator alloc(7);
    auto        result = ::portable_stl::forward_list<std::int32_t, t_allocator>::make_forward_list(
      test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
      test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size),
      alloc);
    ASSERT_TRUE(result);
    auto lst = result.value();

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

    auto result = ::portable_stl::forward_list<std::int32_t, t_allocator>::make_forward_list(
      test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
      test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size),
      alloc);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }
}

// (6) forward_list(forward_list const &other);
TEST(forward_list, constructor_copy) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::forward_list<std::int32_t> lst0(3, 2);

    ::portable_stl::forward_list<std::int32_t> lst1 = lst0;
    ASSERT_EQ(lst0, lst1);
  }

  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

    ::portable_stl::forward_list<std::int32_t, t_allocator> lst0(3, 2, t_allocator(5));

    ::portable_stl::forward_list<std::int32_t, t_allocator> lst1 = lst0;
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
    using t_node_allocator
      = test_allocator_helper::TestSimpleAllocator<portable_stl::forward_list_node<std::int32_t, void *>>;

    ::portable_stl::forward_list<std::int32_t, t_allocator> lst0(5, 2, t_allocator(5));

    t_node_allocator::m_counter_ok_allocation = 3;
    try {
      ::portable_stl::forward_list<std::int32_t, t_allocator> lst1 = lst0;
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }

    t_node_allocator::m_counter_ok_allocation = 10000;
  }
}

TEST(forward_list, make_copy) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::forward_list<std::int32_t> lst0(3, 2);

    auto result = ::portable_stl::forward_list<std::int32_t>::make_forward_list(lst0);
    ASSERT_TRUE(result);
    auto lst1 = result.value();

    ASSERT_EQ(lst0, lst1);
  }

  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

    ::portable_stl::forward_list<std::int32_t, t_allocator> lst0(3, 2, t_allocator(5));

    auto result = ::portable_stl::forward_list<std::int32_t, t_allocator>::make_forward_list(lst0);
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
    using t_node_allocator
      = test_allocator_helper::TestSimpleAllocator<portable_stl::forward_list_node<std::int32_t, void *>>;

    ::portable_stl::forward_list<std::int32_t, t_allocator> lst0(5, 2, t_allocator(5));

    t_node_allocator::m_counter_ok_allocation = 3;
    auto result = ::portable_stl::forward_list<std::int32_t, t_allocator>::make_forward_list(lst0);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    t_node_allocator::m_counter_ok_allocation = 10000;
  }
}

// (7) forward_list(forward_list const &other, allocator_type const &alloc);
TEST(forward_list, constructor_copy_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  {
    ::portable_stl::forward_list<std::int32_t, t_allocator> lst0(3, 2, t_allocator(5));

    ::portable_stl::forward_list<std::int32_t, t_allocator> lst1(lst0, t_allocator(3));
    ASSERT_EQ(lst0, lst1);
    ASSERT_EQ(t_allocator(3), lst1.get_allocator());
  }

  // bad allocation
  {
    ::portable_stl::forward_list<std::int32_t, t_allocator> lst0(5, 2, t_allocator(5));

    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 3;
    t_allocator alloc{&stat};
    try {
      ::portable_stl::forward_list<std::int32_t, t_allocator> lst1(lst0, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

TEST(forward_list, make_copy_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  {
    ::portable_stl::forward_list<std::int32_t, t_allocator> lst0(3, 2, t_allocator(5));

    auto result = ::portable_stl::forward_list<std::int32_t, t_allocator>::make_forward_list(lst0, t_allocator(3));
    ASSERT_TRUE(result);
    auto lst1 = result.value();

    ASSERT_EQ(lst0, lst1);
    ASSERT_EQ(t_allocator(3), lst1.get_allocator());
  }

  // bad allocation
  {
    ::portable_stl::forward_list<std::int32_t, t_allocator> lst0(5, 2, t_allocator(5));

    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 3;
    t_allocator alloc{&stat};

    auto result = ::portable_stl::forward_list<std::int32_t, t_allocator>::make_forward_list(lst0, alloc);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }
}

// (8) forward_list(forward_list &&other);
TEST(forward_list, constructor_move) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias.
   */
  using t_move_only = test_common_helper::MoveOnly;

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<t_move_only>;

  t_move_only arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  using t_move_iter = ::portable_stl::move_iterator<t_move_only *>;

  ::portable_stl::forward_list<t_move_only, t_allocator> lst0(
    t_move_iter(std::begin(arr)), t_move_iter(std::end(arr)), t_allocator(10));

  ::portable_stl::forward_list<t_move_only, t_allocator> lst = std::move(lst0);

  std::int32_t n{0};
  for (::portable_stl::forward_list<t_move_only, t_allocator>::const_iterator iter{lst.begin()}, iter_end = lst.end();
       iter != iter_end;
       ++iter, (void)++n) {
    ASSERT_EQ(n, *iter);
  }

  ASSERT_EQ(n, std::end(arr) - std::begin(arr));
  ASSERT_TRUE(lst0.empty());
  ASSERT_EQ(t_allocator(10), lst.get_allocator());
}

// (9) forward_list(forward_list &&other, allocator_type const &alloc);
TEST(forward_list, constructor_move_allocator) {
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

  // same allocator
  {
    t_move_only arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    ::portable_stl::forward_list<t_move_only, t_allocator> lst0(
      t_move_iter(std::begin(arr)), t_move_iter(std::end(arr)), t_allocator(10));

    ::portable_stl::forward_list<t_move_only, t_allocator> lst(std::move(lst0), t_allocator(10));

    std::int32_t n{0};
    for (::portable_stl::forward_list<t_move_only, t_allocator>::const_iterator iter{lst.begin()}, iter_end = lst.end();
         iter != iter_end;
         ++iter, (void)++n) {
      ASSERT_EQ(n, *iter);
    }

    ASSERT_EQ(n, std::end(arr) - std::begin(arr));
    ASSERT_TRUE(lst0.empty());
    ASSERT_EQ(t_allocator(10), lst.get_allocator());
  }

  // not the same allocator - no pure movement
  {
    t_move_only arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    ::portable_stl::forward_list<t_move_only, t_allocator> lst0(
      t_move_iter(std::begin(arr)), t_move_iter(std::end(arr)), t_allocator(10));

    ::portable_stl::forward_list<t_move_only, t_allocator> lst(std::move(lst0), t_allocator(9));

    std::int32_t n{0};
    for (::portable_stl::forward_list<t_move_only, t_allocator>::const_iterator iter{lst.begin()}, iter_end = lst.end();
         iter != iter_end;
         ++iter, (void)++n) {
      ASSERT_EQ(n, *iter);
    }

    ASSERT_EQ(n, std::end(arr) - std::begin(arr));
    ASSERT_FALSE(lst0.empty()); // no move
    ASSERT_EQ(t_allocator(9), lst.get_allocator());
  }

  // bad allocation durin internal assing
  {}
}

// (10a) forward_list(std::initializer_forward_list<value_type> init_forward_list);
TEST(forward_list, constructor_init_forward_list) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::forward_list<std::int32_t> lst = {0, 1, 2, 3, 4};

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
    using t_node_allocator = test_allocator_helper::TestSimpleAllocator<portable_stl::forward_list_node<std::int32_t,
    void *>>; t_node_allocator::m_counter_ok_allocation = 3; try {
      ::portable_stl::forward_list<std::int32_t, t_allocator> lst = {0, 1, 2, 3, 4};
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }

    t_node_allocator::m_counter_ok_allocation = 10000;
  }
}

TEST(forward_list, make_init_forward_list) {
  static_cast<void>(test_info_);

  {
    auto result = ::portable_stl::forward_list<std::int32_t>::make_forward_list({0, 1, 2, 3, 4});
    ASSERT_TRUE(result);
    auto lst = result.value();

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
    using t_node_allocator = test_allocator_helper::TestSimpleAllocator<portable_stl::forward_list_node<std::int32_t,
    void *>>; t_node_allocator::m_counter_ok_allocation = 3;

    auto result = ::portable_stl::forward_list<std::int32_t, t_allocator>::make_forward_list({0, 1, 2, 3, 4});
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    t_node_allocator::m_counter_ok_allocation = 10000;
  }
}

// (10b) forward_list(std::initializer_forward_list<value_type> init_forward_list, allocator_type const &alloc);
TEST(forward_list, constructor_init_forward_list_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  {
    t_allocator                                     alloc(7);
    ::portable_stl::forward_list<std::int32_t, t_allocator> lst({0, 1, 2, 3, 4}, alloc);

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
      ::portable_stl::forward_list<std::int32_t, t_allocator> lst({0, 1, 2, 3, 4}, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }
}

TEST(forward_list, make_init_forward_list_allocator) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator alias.
   */
  using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  {
    t_allocator alloc(7);
    auto        result = ::portable_stl::forward_list<std::int32_t, t_allocator>::make_forward_list({0, 1, 2, 3, 4},
    alloc); ASSERT_TRUE(result); auto lst = result.value();

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

    auto result = ::portable_stl::forward_list<std::int32_t, t_allocator>::make_forward_list({0, 1, 2, 3, 4}, alloc);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }
}
