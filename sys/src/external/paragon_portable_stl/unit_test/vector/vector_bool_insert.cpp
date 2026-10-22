// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="vector_bool_insert.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "../common/test_allocator.h"
#include "../iterator_helper.h"
#include "portable_stl/vector/vector_bool.h"
#include "vector_test_helper.h"

/**
 * @brief Test allocator alias
 */
using TestBoolSimpleAlloc = test_allocator_helper::TestSimpleAllocator<bool>;

/**
 * @brief Storage allocator for vecor<bool>
 */
using TestUIntSimpleAlloc = test_allocator_helper::TestSimpleAllocator<::portable_stl::vector<bool>::t_storage_type>;

TEST(vector_bool, insert_iter_value) {
  static_cast<void>(test_info_);

  ::portable_stl::size_t min_cap = 8 * sizeof(::portable_stl::vector<bool>::t_storage_type);

  /**
   * @brief Vector size alias.
   */
  using t_size = ::portable_stl::vector<bool>::size_type;

  // No reallocation expected
  {
    ::portable_stl::vector<bool>                        vec(min_cap - 1);
    t_size const                                        old_size{vec.size()};
    ::portable_stl::vector<bool>::difference_type const pos{5};

    auto result = vec.insert(vec.cbegin() + pos, true);
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(old_size + 1, vec.size());
    EXPECT_EQ(vec.begin() + pos, it);

    ::portable_stl::size_t j{0U};
    for (; j < static_cast<::portable_stl::size_t>(pos); ++j) {
      EXPECT_EQ(false, vec[j]);
    }
    EXPECT_EQ(true, vec[j]);
    for (++j; j < vec.size(); ++j) {
      EXPECT_EQ(false, vec[j]);
    }
  }

  // Reallocation expected
  {
    ::portable_stl::vector<bool>                        vec(min_cap);
    t_size const                                        old_size{vec.size()};
    ::portable_stl::vector<bool>::difference_type const pos{5};

    auto result = vec.insert(vec.cbegin() + pos, true);
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(old_size + 1, vec.size());
    EXPECT_EQ(vec.begin() + pos, it);

    ::portable_stl::size_t j{0U};
    for (; j < static_cast<::portable_stl::size_t>(pos); ++j) {
      EXPECT_EQ(false, vec[j]);
    }
    EXPECT_EQ(true, vec[j]);
    for (++j; j < vec.size(); ++j) {
      EXPECT_EQ(false, vec[j]);
    }
  }

  // Bad reallocation
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc>   vec(min_cap);
    t_size const                                        old_size{vec.size()};
    ::portable_stl::vector<bool>::difference_type const pos{5};

    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;
    auto result                                  = vec.insert(vec.cbegin() + pos, true);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // check invariant
    EXPECT_EQ(old_size, vec.size());
    for (::portable_stl::size_t j{0U}; j < vec.size(); ++j) {
      EXPECT_EQ(false, vec[j]);
    }

    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
  }

  // reaching max_size
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc>   vec(min_cap);
    t_size const                                        old_size{vec.size()};
    ::portable_stl::vector<bool>::difference_type const pos{5};

    TestUIntSimpleAlloc::m_max_size = 1;
    auto result                     = vec.insert(vec.cbegin() + pos, true);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    // check invariant
    EXPECT_EQ(old_size, vec.size());
    for (::portable_stl::size_t j{0U}; j < vec.size(); ++j) {
      EXPECT_EQ(false, vec[j]);
    }

    TestUIntSimpleAlloc::m_max_size = 10000;
  }
}

TEST(vector_bool, insert_iter_count_value) {
  static_cast<void>(test_info_);

  ::portable_stl::size_t min_cap = 8 * sizeof(::portable_stl::vector<bool>::t_storage_type);

  /**
   * @brief Vector size alias.
   */
  using t_size = ::portable_stl::vector<bool>::size_type;

  // No reallocation expected
  {
    t_size const                                        count{4};
    ::portable_stl::vector<bool>                        vec(min_cap - (count + 1));
    t_size const                                        old_size{vec.size()};
    ::portable_stl::vector<bool>::difference_type const pos{5};

    auto result = vec.insert(vec.cbegin() + pos, count, true);
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(old_size + count, vec.size());
    EXPECT_EQ(vec.begin() + pos, it);

    t_size j{0U};
    for (; j < static_cast<t_size>(pos); ++j) {
      EXPECT_EQ(false, vec[j]);
    }
    for (; j < (static_cast<t_size>(pos) + count); ++j) {
      EXPECT_EQ(true, vec[j]);
    }
    for (++j; j < vec.size(); ++j) {
      EXPECT_EQ(false, vec[j]);
    }
  }

  // Reallocation expected
  {
    t_size const                 count{10};
    ::portable_stl::vector<bool> vec(min_cap - 1);
    t_size const                 old_size{vec.size()};
    ::portable_stl::vector<bool>::difference_type const pos{5};

    auto result = vec.insert(vec.cbegin() + pos, count, true);
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(old_size + count, vec.size());
    EXPECT_EQ(vec.begin() + pos, it);

    ::portable_stl::size_t j{0U};
    for (; j < static_cast<t_size>(pos); ++j) {
      EXPECT_EQ(false, vec[j]);
    }
    for (; j < (static_cast<t_size>(pos) + count); ++j) {
      EXPECT_EQ(true, vec[j]);
    }
    for (++j; j < vec.size(); ++j) {
      EXPECT_EQ(false, vec[j]);
    }
  }

  // Bad reallocation
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    t_size const                                      count{10};
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(min_cap - 1);
    t_size const                                      old_size{vec.size()};
    ::portable_stl::size_t const                      pos{5};

    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;
    auto result                                  = vec.insert(vec.cbegin() + pos, count, true);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // check invariant
    EXPECT_EQ(old_size, vec.size());
    for (::portable_stl::size_t j{0U}; j < vec.size(); ++j) {
      EXPECT_EQ(false, vec[j]);
    }

    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
  }

  // reaching max_size
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    t_size const                                      count{10};
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(min_cap - 1);
    t_size const                                      old_size{vec.size()};
    ::portable_stl::size_t const                      pos{5};

    TestUIntSimpleAlloc::m_max_size = 1;
    auto result                     = vec.insert(vec.cbegin() + pos, count, true);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    // check invariant
    EXPECT_EQ(old_size, vec.size());
    for (::portable_stl::size_t j{0U}; j < vec.size(); ++j) {
      EXPECT_EQ(false, vec[j]);
    }

    TestUIntSimpleAlloc::m_max_size = 10000;
  }
}

TEST(vector_bool, insert_iter_iter_iter_input_iterators) {
  static_cast<void>(test_info_);

  ::portable_stl::size_t min_cap = 8 * sizeof(::portable_stl::vector<bool>::t_storage_type);

  /**
   * @brief Vector size alias.
   */
  using t_size = ::portable_stl::vector<bool>::size_type;

  bool         a[]   = {true, false, true, false, true};
  t_size const count = sizeof(a) / sizeof(a[0]);

  // No reallocation expected
  {
    ::portable_stl::vector<bool> vec(min_cap - (count + 1));
    t_size const                 old_size{vec.size()};
    ::portable_stl::size_t const pos{5};

    auto result = vec.insert(vec.cbegin() + pos,
                             test_iterator_helper::tst_input_iterator<bool const *>(a),
                             test_iterator_helper::tst_input_iterator<bool const *>(a + count));
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(old_size + count, vec.size());
    EXPECT_EQ(vec.begin() + pos, it);

    ::portable_stl::size_t j{0U};
    for (; j < pos; ++j) {
      EXPECT_EQ(false, vec[j]);
    }
    ::portable_stl::size_t k{0U};
    for (; j < (pos + count); ++j) {
      EXPECT_EQ(a[k++], vec[j]);
    }
    for (++j; j < vec.size(); ++j) {
      EXPECT_EQ(false, vec[j]);
    }
  }

  // Reallocation expected
  {
    ::portable_stl::vector<bool> vec(min_cap - 1);
    t_size const                 old_size{vec.size()};
    ::portable_stl::size_t const pos{5};

    auto result = vec.insert(vec.cbegin() + pos,
                             test_iterator_helper::tst_input_iterator<bool const *>(a),
                             test_iterator_helper::tst_input_iterator<bool const *>(a + count));
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(old_size + count, vec.size());
    EXPECT_EQ(vec.begin() + pos, it);

    ::portable_stl::size_t j{0U};
    for (; j < pos; ++j) {
      EXPECT_EQ(false, vec[j]);
    }
    ::portable_stl::size_t k{0U};
    for (; j < (pos + count); ++j) {
      EXPECT_EQ(a[k++], vec[j]);
    }
    for (++j; j < vec.size(); ++j) {
      EXPECT_EQ(false, vec[j]);
    }
  }

  // Bad allocation of the temp buffer for new elements
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(min_cap - (count - 1));
    t_size const                                      old_cap{vec.capacity()};
    ::portable_stl::size_t const                      pos{5};

    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;
    auto result                                  = vec.insert(vec.cbegin() + pos,
                             test_iterator_helper::tst_input_iterator<bool const *>(a),
                             test_iterator_helper::tst_input_iterator<bool const *>(a + count));
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // check invariant
    EXPECT_EQ(old_cap, vec.capacity());

    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
  }

  // Bad self reallocation
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(min_cap - (count - 1));
    t_size const                                      old_cap{vec.capacity()};
    ::portable_stl::size_t const                      pos{5};

    TestUIntSimpleAlloc::m_counter_ok_allocation = 1;
    auto result                                  = vec.insert(vec.cbegin() + pos,
                             test_iterator_helper::tst_input_iterator<bool const *>(a),
                             test_iterator_helper::tst_input_iterator<bool const *>(a + count));
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // check invariant
    EXPECT_EQ(old_cap, vec.capacity());

    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
  }
}

TEST(vector_bool, insert_iter_iter_iter_forward_iterators) {
  static_cast<void>(test_info_);

  ::portable_stl::size_t min_cap = 8 * sizeof(::portable_stl::vector<bool>::t_storage_type);

  /**
   * @brief Vector size alias.
   */
  using t_size = ::portable_stl::vector<bool>::size_type;

  bool         a[]   = {true, false, true, false, true};
  t_size const count = sizeof(a) / sizeof(a[0]);

  // No reallocation expected
  {
    ::portable_stl::vector<bool> vec(min_cap - (count + 1));
    t_size const                 old_size{vec.size()};
    ::portable_stl::size_t const pos{5};

    auto result = vec.insert(vec.cbegin() + pos,
                             test_iterator_helper::tst_forward_iterator<bool const *>(a),
                             test_iterator_helper::tst_forward_iterator<bool const *>(a + count));
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(old_size + count, vec.size());
    EXPECT_EQ(vec.begin() + pos, it);

    ::portable_stl::size_t j{0U};
    for (; j < pos; ++j) {
      EXPECT_EQ(false, vec[j]);
    }
    ::portable_stl::size_t k{0U};
    for (; j < (pos + count); ++j) {
      EXPECT_EQ(a[k++], vec[j]);
    }
    for (++j; j < vec.size(); ++j) {
      EXPECT_EQ(false, vec[j]);
    }
  }

  // Reallocation expected
  {
    ::portable_stl::vector<bool> vec(min_cap - 1);
    t_size const                 old_size{vec.size()};
    ::portable_stl::size_t const pos{5};

    auto result = vec.insert(vec.cbegin() + pos,
                             test_iterator_helper::tst_forward_iterator<bool const *>(a),
                             test_iterator_helper::tst_forward_iterator<bool const *>(a + count));
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(old_size + count, vec.size());
    EXPECT_EQ(vec.begin() + pos, it);

    ::portable_stl::size_t j{0U};
    for (; j < pos; ++j) {
      EXPECT_EQ(false, vec[j]);
    }
    ::portable_stl::size_t k{0U};
    for (; j < (pos + count); ++j) {
      EXPECT_EQ(a[k++], vec[j]);
    }
    for (++j; j < vec.size(); ++j) {
      EXPECT_EQ(false, vec[j]);
    }
  }

  // Bad allocation of the temp buffer for new elements
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(min_cap - (count - 1));
    t_size const                                      old_cap{vec.capacity()};
    ::portable_stl::size_t const                      pos{5};

    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;
    auto result                                  = vec.insert(vec.cbegin() + pos,
                             test_iterator_helper::tst_forward_iterator<bool const *>(a),
                             test_iterator_helper::tst_forward_iterator<bool const *>(a + count));
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // check invariant
    EXPECT_EQ(old_cap, vec.capacity());

    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
  }

  // reaching max_size
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(min_cap - (count - 1));
    t_size const                                      old_cap{vec.capacity()};
    ::portable_stl::size_t const                      pos{5};

    TestUIntSimpleAlloc::m_max_size = 1;
    auto result                     = vec.insert(vec.cbegin() + pos,
                             test_iterator_helper::tst_forward_iterator<bool const *>(a),
                             test_iterator_helper::tst_forward_iterator<bool const *>(a + count));
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    // check invariant
    EXPECT_EQ(old_cap, vec.capacity());

    TestUIntSimpleAlloc::m_max_size = 100;
  }
}

TEST(vector_bool, insert_iter_initializer_list) {
  static_cast<void>(test_info_);

  /**
   * @brief Vector size alias.
   */
  using t_size = ::portable_stl::vector<bool>::size_type;

  bool         a[] = {true, false, true, false, true};
  t_size const count{5};

  // No reallocation expected
  {
    ::portable_stl::vector<bool> vec(6);
    t_size const                 old_size{vec.size()};
    ::portable_stl::size_t const pos{5};

    auto result = vec.insert(vec.cbegin() + pos, {true, false, true, false, true});
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(old_size + count, vec.size());
    EXPECT_EQ(vec.begin() + pos, it);

    ::portable_stl::size_t j{0U};
    for (; j < pos; ++j) {
      EXPECT_EQ(false, vec[j]);
    }
    ::portable_stl::size_t k{0U};
    for (; j < (pos + count); ++j) {
      EXPECT_EQ(a[k++], vec[j]);
    }
    for (++j; j < vec.size(); ++j) {
      EXPECT_EQ(false, vec[j]);
    }
  }
}

TEST(vector_bool, emplace) {
  static_cast<void>(test_info_);

  ::portable_stl::vector<bool> vec(6);

  auto result = vec.emplace(vec.cbegin(), true);
  ASSERT_TRUE(result);

  EXPECT_EQ(true, vec.front());
  EXPECT_EQ(result.value(), vec.cbegin());
}
