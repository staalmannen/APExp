// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="vector_bool_modify.cpp"
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
// #include "vector_test_helper.h"

/**
 * @brief Test allocator alias
 */
using TestBoolSimpleAlloc = test_allocator_helper::TestSimpleAllocator<bool>;

/**
 * @brief Storage allocator for vecor<bool>
 */
using TestUIntSimpleAlloc = test_allocator_helper::TestSimpleAllocator<::portable_stl::vector<bool>::t_storage_type>;

TEST(vector_bool, emplace_back_ok) {
  static_cast<void>(test_info_);

  ::portable_stl::vector<bool> vec;

  auto res1 = vec.emplace_back();
  EXPECT_TRUE(res1);
  ASSERT_EQ(1, vec.size());
  auto ref1 = res1.value();
  ASSERT_EQ(false, ref1);

  ref1 = true;
  ASSERT_EQ(true, vec.front());
  ref1 = false;

  auto res2 = vec.emplace_back(true);
  EXPECT_TRUE(res2);
  ASSERT_EQ(2, vec.size());
  auto ref2 = res2.value();
  ASSERT_EQ(false, vec.front());
  ASSERT_EQ(true, vec.back());

  ref2 = false;
  ASSERT_EQ(false, vec.back());
  ref2 = true;

  vec.emplace_back(true);
  ASSERT_EQ(3, vec.size());
  ASSERT_EQ(false, vec.front());
  ASSERT_EQ(true, vec[1]);
  ASSERT_EQ(true, vec.back());
}

TEST(vector_bool, emplace_back_bad_alloc) {
  static_cast<void>(test_info_);

  // equal push_back

  // bad allocation input_iterator
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;

    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(64, true);

    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;
    auto result                                  = vec.emplace_back(true);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }
}

TEST(vector_bool, assign_count_value) {
  static_cast<void>(test_info_);

  ::portable_stl::size_t min_cap = 8 * sizeof(::portable_stl::vector<bool>::t_storage_type);

  /**
   * @brief Size type alias.
   */
  using t_size = typename ::portable_stl::vector<bool>::size_type;
  // initial empty
  {
    ::portable_stl::vector<bool> vec;
    t_size                       num{6};
    auto                         result = vec.assign(num, true);

    ASSERT_TRUE(result);
    ASSERT_EQ(num, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(true, vec[i]);
    }
  }

  // count = 0
  {
    ::portable_stl::vector<bool> vec{true, false, true};
    t_size                       num{0};
    auto                         result = vec.assign(num, true);

    ASSERT_TRUE(result);
    ASSERT_TRUE(vec.empty());
    ASSERT_EQ(min_cap, vec.capacity());
  }

  // reuse all memory
  {
    ::portable_stl::vector<bool> vec(min_cap, false);
    t_size                       old_cap{vec.capacity()};

    t_size num{min_cap};
    auto   result = vec.assign(num, true);

    ASSERT_TRUE(result);
    ASSERT_EQ(num, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(true, vec[i]);
    }
    EXPECT_EQ(old_cap, vec.capacity());
  }

  // reuse less memory
  {
    ::portable_stl::vector<bool> vec(3 * min_cap, false);
    t_size                       old_cap{vec.capacity()};

    t_size num{2 * min_cap};
    auto   result = vec.assign(num, true);

    ASSERT_TRUE(result);
    ASSERT_EQ(num, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(true, vec[i]);
    }
    EXPECT_EQ(old_cap, vec.capacity());
  }

  // reuse size() < memory < capacity()
  {
    ::portable_stl::vector<bool> vec(3 * min_cap, false);
    vec.resize(min_cap);
    t_size old_cap{vec.capacity()};

    t_size num{2 * min_cap};
    auto   result = vec.assign(num, true);

    ASSERT_TRUE(result);
    ASSERT_EQ(num, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(true, vec[i]);
    }
    EXPECT_EQ(old_cap, vec.capacity());
  }

  // full reallocation
  {
    ::portable_stl::vector<bool> vec(16, false);

    t_size num{min_cap + 1};
    auto   result = vec.assign(num, true);

    ASSERT_TRUE(result);
    ASSERT_EQ(num, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(true, vec[i]);
    }
    EXPECT_EQ(2 * min_cap, vec.capacity());
  }

  // bad allocation
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(16, false);
    t_size                                            num{min_cap + 1};

    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;
    auto result                                  = vec.assign(num, true);

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }

  // reaching max_size
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(16, false);
    t_size                                            num{min_cap + 1};
    TestUIntSimpleAlloc::m_max_size = 1;
    auto result                     = vec.assign(num, true);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    TestUIntSimpleAlloc::m_max_size = 10000;
  }
}

TEST(vector_bool, assign_inputiter_inputiter) {
  static_cast<void>(test_info_);

  ::portable_stl::size_t min_cap = 8 * sizeof(::portable_stl::vector<bool>::t_storage_type);

  /**
   * @brief Size type alias.
   */
  using t_size = typename ::portable_stl::vector<bool>::size_type;

  /**
   * @brief Test input iterator.
   */
  using t_input_iter = test_iterator_helper::tst_input_iterator<bool const *>;

  bool   a[] = {true, false, true, false, true, false};
  bool  *an  = a + sizeof(a) / sizeof(a[0]);
  t_size num_ref{sizeof(a)};

  // initial empty
  {
    ::portable_stl::vector<bool> vec;
    auto                         result = vec.assign(t_input_iter(a), t_input_iter(an));

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(a[i], vec[i]);
    }
  }

  // count = 0
  {
    ::portable_stl::vector<bool> vec{false, true, false};
    auto                         result = vec.assign(t_input_iter(a), t_input_iter(a));

    ASSERT_TRUE(result);
    ASSERT_TRUE(vec.empty());
    ASSERT_EQ(min_cap, vec.capacity());
  }

  // reuse all memory
  {
    ::portable_stl::vector<bool> vec(num_ref, false);
    t_size                       old_cap{vec.capacity()};

    auto result = vec.assign(t_input_iter(a), t_input_iter(an));

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(a[i], vec[i]);
    }
    EXPECT_EQ(old_cap, vec.capacity());
  }

  // reuse less memory
  {
    ::portable_stl::vector<bool> vec(2 * min_cap, false);
    t_size                       old_cap{vec.capacity()};

    auto result = vec.assign(t_input_iter(a), t_input_iter(an));

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(a[i], vec[i]);
    }
    EXPECT_EQ(old_cap, vec.capacity());
  }

  bool   a2[] = {true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
                 true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
                 true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
                 true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
                 true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
                 true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
                 true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
                 true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false};
  bool  *a2n  = a2 + sizeof(a2) / sizeof(a2[0]);
  t_size num_ref2{sizeof(a2)};

  // reuse size() < memory < capacity()
  {
    ::portable_stl::vector<bool> vec(10 * min_cap, false);
    vec.resize(min_cap);
    t_size old_cap{vec.capacity()};

    auto result = vec.assign(t_input_iter(a2), t_input_iter(a2n));

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref2, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(a2[i], vec[i]);
    }
    EXPECT_EQ(old_cap, vec.capacity());
  }

  // full reallocation
  {
    ::portable_stl::vector<bool> vec(5, 0);

    auto result = vec.assign(t_input_iter(a2), t_input_iter(a2n));

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref2, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(a2[i], vec[i]);
    }
    EXPECT_GE(vec.capacity(), num_ref2);
  }

  // bad allocation
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(16, false);

    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;
    auto result                                  = vec.assign(t_input_iter(a2), t_input_iter(a2n));

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
    EXPECT_TRUE(vec.size() <= vec.capacity());
  }
}

TEST(vector_bool, assign_forwarditer_forwarditer) {
  static_cast<void>(test_info_);

  ::portable_stl::size_t min_cap = 8 * sizeof(::portable_stl::vector<bool>::t_storage_type);

  /**
   * @brief Size type alias.
   */
  using t_size = typename ::portable_stl::vector<bool>::size_type;

  /**
   * @brief Test input iterator.
   */
  using t_forward_iter = test_iterator_helper::tst_forward_iterator<bool const *>;

  bool   a[] = {true, false, true, false, true, false};
  bool  *an  = a + sizeof(a) / sizeof(a[0]);
  t_size num_ref{sizeof(a)};

  // initial empty
  {
    ::portable_stl::vector<bool> vec;
    auto                         result = vec.assign(t_forward_iter(a), t_forward_iter(an));

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(a[i], vec[i]);
    }
  }

  // count = 0
  {
    ::portable_stl::vector<bool> vec{false, true, false};
    auto                         result = vec.assign(t_forward_iter(a), t_forward_iter(a));

    ASSERT_TRUE(result);
    ASSERT_TRUE(vec.empty());
    ASSERT_EQ(min_cap, vec.capacity());
  }

  // reuse all memory
  {
    ::portable_stl::vector<bool> vec(num_ref, false);
    t_size                       old_cap{vec.capacity()};

    auto result = vec.assign(t_forward_iter(a), t_forward_iter(an));

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(a[i], vec[i]);
    }
    EXPECT_EQ(old_cap, vec.capacity());
  }

  // reuse less memory
  {
    ::portable_stl::vector<bool> vec(2 * min_cap, false);
    t_size                       old_cap{vec.capacity()};

    auto result = vec.assign(t_forward_iter(a), t_forward_iter(an));

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(a[i], vec[i]);
    }
    EXPECT_EQ(old_cap, vec.capacity());
  }

  bool   a2[] = {true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
                 true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
                 true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
                 true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
                 true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
                 true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
                 true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
                 true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false};
  bool  *a2n  = a2 + sizeof(a2) / sizeof(a2[0]);
  t_size num_ref2{sizeof(a2)};

  // reuse size() < memory < capacity()
  {
    ::portable_stl::vector<bool> vec(10 * min_cap, false);
    vec.resize(min_cap);
    t_size old_cap{vec.capacity()};

    auto result = vec.assign(t_forward_iter(a2), t_forward_iter(a2n));

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref2, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(a2[i], vec[i]);
    }
    EXPECT_EQ(old_cap, vec.capacity());
  }

  // full reallocation
  {
    ::portable_stl::vector<bool> vec(5, 0);

    auto result = vec.assign(t_forward_iter(a2), t_forward_iter(a2n));

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref2, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(a2[i], vec[i]);
    }
    EXPECT_GE(vec.capacity(), num_ref2);
  }

  // bad allocation
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(16, false);

    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;
    auto result                                  = vec.assign(t_forward_iter(a2), t_forward_iter(a2n));

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
    EXPECT_TRUE(vec.size() <= vec.capacity());
  }

  // bad allocation
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(16, false);

    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;
    auto result                                  = vec.assign(t_forward_iter(a2), t_forward_iter(a2n));

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
    EXPECT_TRUE(vec.size() <= vec.capacity());
  }

  // reaching max_size
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(16, false);

    TestUIntSimpleAlloc::m_max_size = 1;
    auto result                     = vec.assign(t_forward_iter(a2), t_forward_iter(a2n));

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    TestUIntSimpleAlloc::m_max_size = 10000;
  }
}

TEST(vector_bool, operator_assign_copy) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Allocator.
     */
    using TestAlloc = test_allocator_helper::test_allocator<bool>;

    ::portable_stl::vector<bool, TestAlloc> vec0(3, true, TestAlloc(5));
    ::portable_stl::vector<bool, TestAlloc> vec(vec0, TestAlloc(3));

    vec = vec0;

    EXPECT_EQ(vec, vec0);
    EXPECT_EQ(3, vec.get_allocator().get_data());
  }

  // Test with Allocator::propagate_on_container_copy_assignment == false_type
  {
    /**
     * @brief Allocator.
     */
    using TestAlloc = test_allocator_helper::NonPOCCAAllocator<bool>;
    bool copy_assigned_into{false};

    ::portable_stl::vector<bool, TestAlloc> vec0(3, true, TestAlloc(5, nullptr));
    ::portable_stl::vector<bool, TestAlloc> vec(vec0, TestAlloc(3, &copy_assigned_into));
    EXPECT_FALSE(copy_assigned_into);

    vec = vec0;

    EXPECT_FALSE(copy_assigned_into);
    EXPECT_EQ(vec, vec0);
    EXPECT_EQ(vec.get_allocator(), TestAlloc(3, nullptr));
  }

  // Test with Allocator::propagate_on_container_copy_assignment == true_type and equal allocators
  {
    /**
     * @brief Allocator.
     */
    using TestAlloc = test_allocator_helper::POCCAAllocator<bool>;
    bool copy_assigned_into{false};

    ::portable_stl::vector<bool, TestAlloc> vec0(3, true, TestAlloc(5, nullptr));
    ::portable_stl::vector<bool, TestAlloc> vec(vec0, TestAlloc(5, &copy_assigned_into));
    EXPECT_FALSE(copy_assigned_into);

    vec = vec0;

    EXPECT_TRUE(copy_assigned_into);
    EXPECT_EQ(vec, vec0);
    EXPECT_EQ(vec.get_allocator(), TestAlloc(5, nullptr));
  }

  // Test with Allocator::propagate_on_container_copy_assignment == true_type and unequal allocators
  {
    /**
     * @brief Allocator.
     */
    using TestAlloc = test_allocator_helper::POCCAAllocator<bool>;
    bool copy_assigned_into{false};

    ::portable_stl::vector<bool, TestAlloc> vec0(3, true, TestAlloc(5, nullptr));
    ::portable_stl::vector<bool, TestAlloc> vec(vec0, TestAlloc(3, &copy_assigned_into));
    EXPECT_FALSE(copy_assigned_into);

    vec = vec0;

    EXPECT_TRUE(copy_assigned_into);
    EXPECT_EQ(vec, vec0);
    EXPECT_EQ(vec.get_allocator(), TestAlloc(5, nullptr));
  }
}

TEST(vector_bool, operator_assign_move) {
  static_cast<void>(test_info_);
  /**
   * @brief Allocator.
   */
  using TestAlloc = test_allocator_helper::test_allocator<bool>;

  {
    ::portable_stl::vector<bool, TestAlloc> vec(TestAlloc(5));
    ::portable_stl::vector<bool, TestAlloc> vec0(TestAlloc(5));
    for (int i = 1; i <= 3; ++i) {
      vec.push_back(static_cast<bool>(i % 2));
      vec0.push_back(static_cast<bool>(i % 2));
    }

    ::portable_stl::vector<bool, TestAlloc> vec2(TestAlloc(5));
    vec2 = ::portable_stl::move(vec);
    EXPECT_EQ(vec2, vec0);
    EXPECT_TRUE(vec.empty());
    EXPECT_EQ(vec2.get_allocator(), vec0.get_allocator());
  }

  {
    ::portable_stl::vector<bool, TestAlloc> vec(TestAlloc(5));
    ::portable_stl::vector<bool, TestAlloc> vec0(TestAlloc(5));
    for (int i = 1; i <= 3; ++i) {
      vec.push_back(static_cast<bool>(i % 2));
      vec0.push_back(static_cast<bool>(i % 2));
    }

    ::portable_stl::vector<bool, TestAlloc> vec2(TestAlloc(6));
    vec2 = ::portable_stl::move(vec);
    EXPECT_EQ(vec2, vec0);
    EXPECT_FALSE(vec.empty());
    EXPECT_EQ(vec2.get_allocator(), TestAlloc(6));
  }
}

TEST(vector_bool, push_back) {
  static_cast<void>(test_info_);

  {
    bool                         a[] = {false, true, true, false, true, false, false};
    ::portable_stl::size_t const N   = sizeof(a) / sizeof(a[0]);
    ::portable_stl::vector<bool> vec;

    for (::portable_stl::size_t i{0}; i < N; ++i) {
      auto result = vec.push_back(a[i]);
      ASSERT_TRUE(result);
      ASSERT_EQ(i + 1, vec.size());
      for (::portable_stl::size_t j{0}; j < vec.size(); ++j) {
        ASSERT_EQ(a[j], vec[j]);
      }
    }
  }

  ::portable_stl::size_t min_cap = 8 * sizeof(::portable_stl::vector<bool>::t_storage_type);

  // Bad allocation on reservation
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(min_cap, false);
    auto                                              old_size = vec.size();

    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;
    auto result                                  = vec.push_back(true);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // Check vector invariant
    ASSERT_EQ(old_size, vec.size());
    EXPECT_EQ(false, vec.back());
  }

  // max_size reaching
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(min_cap, false);
    auto                                              old_size = vec.size();

    TestUIntSimpleAlloc::m_max_size = 1;
    auto result                     = vec.push_back(true);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    // Check invariant: strong guarantee
    EXPECT_EQ(old_size, vec.size());
    for (::portable_stl::size_t i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(false, vec[i]);
    }

    TestUIntSimpleAlloc::m_max_size = 10000;
  }
}

TEST(vector_bool, pop_back) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::vector<bool> vec;

    vec.push_back(1);
    EXPECT_EQ(1, vec.size());

    vec.pop_back();
    EXPECT_EQ(0, vec.size());
  }
}

TEST(vector_bool, erase_position) {
  static_cast<void>(test_info_);

  {
    bool                         a1[] = {true, false, true, false, true};
    ::portable_stl::vector<bool> vec(a1, a1 + 5);
    vec.erase(vec.begin());
    EXPECT_EQ(vec, ::portable_stl::vector<bool>(a1 + 1, a1 + 5));
  }
  {
    ::portable_stl::vector<bool> ref{true, true, false, true};
    ::portable_stl::vector<bool> vec{true, false, true, false, true};
    vec.erase(vec.begin() + 1);
    EXPECT_EQ(vec, ref);
  }
  {
    bool                                         a1[] = {true, false, true};
    ::portable_stl::vector<bool>                 vec(a1, a1 + 3);
    ::portable_stl::vector<bool>::const_iterator i{vec.begin()};
    ++i;

    ::portable_stl::vector<bool>::iterator j{vec.erase(i)};
    EXPECT_EQ(2, vec.size());
    EXPECT_EQ(2, ::portable_stl::distance(vec.begin(), vec.end()));
    EXPECT_EQ(true, *j);
    EXPECT_EQ(true, *vec.begin());
    EXPECT_EQ(true, *::portable_stl::next(vec.begin()));

    j = vec.erase(j);
    EXPECT_EQ(j, vec.end());
    EXPECT_EQ(1, vec.size());
    EXPECT_EQ(1, ::portable_stl::distance(vec.begin(), vec.end()));
    EXPECT_EQ(true, *vec.begin());

    j = vec.erase(vec.begin());
    EXPECT_EQ(j, vec.end());
    EXPECT_EQ(0, vec.size());
    EXPECT_EQ(0, ::portable_stl::distance(vec.begin(), vec.end()));
  }
}

TEST(vector_bool, erase_iter_iter) {
  static_cast<void>(test_info_);

  bool a1[] = {true, false, true};

  // erase zero
  {
    ::portable_stl::vector<bool> vec(a1, a1 + 3);

    ::portable_stl::vector<bool>::iterator i = vec.erase(vec.cbegin(), vec.cbegin());

    EXPECT_EQ(3, vec.size());
    EXPECT_EQ(3, ::portable_stl::distance(vec.cbegin(), vec.cend()));
    EXPECT_EQ(i, vec.begin());
  }

  // erase 1
  {
    ::portable_stl::vector<bool> vec(a1, a1 + 3);

    ::portable_stl::vector<bool>::iterator i = vec.erase(vec.cbegin(), ::portable_stl::next(vec.cbegin()));

    EXPECT_EQ(2, vec.size());
    EXPECT_EQ(2, ::portable_stl::distance(vec.cbegin(), vec.cend()));
    EXPECT_EQ(i, vec.begin());
    EXPECT_EQ(vec, ::portable_stl::vector<bool>(a1 + 1, a1 + 3));
  }
  {
    ::portable_stl::vector<bool> vec(a1, a1 + 3);

    ::portable_stl::vector<bool>::iterator i = vec.erase(vec.cbegin(), ::portable_stl::next(vec.cbegin(), 2));

    EXPECT_EQ(1, vec.size());
    EXPECT_EQ(1, ::portable_stl::distance(vec.cbegin(), vec.cend()));
    EXPECT_EQ(i, vec.begin());
    EXPECT_EQ(vec, ::portable_stl::vector<bool>(a1 + 2, a1 + 3));
  }

  // erase all
  {
    ::portable_stl::vector<bool> vec(a1, a1 + 3);

    ::portable_stl::vector<bool>::iterator i = vec.erase(vec.cbegin(), ::portable_stl::next(vec.cbegin(), 3));

    EXPECT_EQ(0, vec.size());
    EXPECT_EQ(0, ::portable_stl::distance(vec.cbegin(), vec.cend()));
    EXPECT_EQ(i, vec.begin());
  }
  {
    std::vector<::portable_stl::vector<bool>> outer(2, ::portable_stl::vector<bool>(1));

    outer.erase(outer.begin(), outer.begin());

    EXPECT_EQ(2, outer.size());
    EXPECT_EQ(1, outer[0].size());
    EXPECT_EQ(1, outer[1].size());
  }
}

TEST(vector_bool, flip) {
  static_cast<void>(test_info_);

  ::portable_stl::size_t min_cap = 8 * sizeof(::portable_stl::vector<bool>::t_storage_type);

  {
    ::portable_stl::vector<bool> vec(min_cap / 2, true);
    vec.insert(vec.cend(), min_cap / 2, false);
    ASSERT_EQ(min_cap, vec.size());

    vec.flip();

    ::portable_stl::size_t i{0};

    for (; i < min_cap / 2; ++i) {
      EXPECT_EQ(false, vec[i]);
    }
    for (; i < vec.size(); ++i) {
      EXPECT_EQ(true, vec[i]);
    }
  }

  {
    ::portable_stl::vector<bool> vec((min_cap / 2) + 3, true);
    vec.insert(vec.cend(), (min_cap / 2) + 3, false);
    ASSERT_EQ(min_cap + 6, vec.size());

    vec.flip();

    ::portable_stl::size_t i{0};

    for (; i < (min_cap / 2) + 3; ++i) {
      EXPECT_EQ(false, vec[i]);
    }
    for (; i < vec.size(); ++i) {
      EXPECT_EQ(true, vec[i]);
    }
  }
}
