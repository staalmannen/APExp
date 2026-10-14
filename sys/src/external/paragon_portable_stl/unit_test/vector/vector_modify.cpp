// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="vector_modify.cpp"
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
#include "../iterator_helper.h"
#include "portable_stl/vector/vector.h"
#include "vector_test_helper.h"

TEST(vector, emplace_back_ok) {
  static_cast<void>(test_info_);

  // OK
  {
    ::portable_stl::vector<std::int32_t> vec;

    for (::portable_stl::size_t i{0U}; i < 10U; ++i) {
      auto result = vec.emplace_back(static_cast<std::int32_t>(i));
      ASSERT_TRUE(result);
      EXPECT_EQ(result.value(), vec[i]);
    }

    ASSERT_EQ(10U, vec.size());
    for (::portable_stl::size_t i{0U}; i < vec.size(); ++i) {
      EXPECT_EQ(static_cast<std::int32_t>(i), vec[i]);
    }
  }
}

TEST(vector, emplace_back_bad_conctruction) {
  static_cast<void>(test_info_);

  // construction error during adding new element to split_buffer
  {
    test_vector_helper::ThrowSometime::setThrowOnConstruction(4); // only 2 successful construction

    {
      ::portable_stl::vector<test_vector_helper::ThrowSometime> vec;
      try {
        for (::portable_stl::size_t i{0U}; i < 3U; ++i) {
          auto result = vec.emplace_back(static_cast<std::int32_t>(i));
          ASSERT_TRUE(result);
          EXPECT_EQ(result.value().get().getData(), vec[i].getData());
        }
        ASSERT_TRUE(false);
      } catch (::portable_stl::logic_error<> &e) {
        static_cast<void>(e);
      }

      // roll back during creation
      EXPECT_EQ(3, test_vector_helper::ThrowSometime::m_construct_count);
      EXPECT_EQ(1, test_vector_helper::ThrowSometime::m_destruct_count);
    }
    EXPECT_EQ(3, test_vector_helper::ThrowSometime::m_destruct_count);
  }

  // construction error during swap vector and split_buffer
  {
    {
      test_vector_helper::ThrowSometime::setThrowOnConstruction(6); // only 5 successful construction

      ::portable_stl::vector<test_vector_helper::ThrowSometime> vec;
      try {
        for (::portable_stl::size_t i{0U}; i < 3U; ++i) {
          auto result = vec.emplace_back(static_cast<std::int32_t>(i));
          ASSERT_TRUE(result);
          EXPECT_EQ(result.value().get().getData(), vec[i].getData());
        }
        ASSERT_TRUE(false);
      } catch (::portable_stl::logic_error<> &e) {
        static_cast<void>(e);
      }

      // roll back during creation
      // 1
      // 2 3
      // 4 5 *6
      EXPECT_EQ(5, test_vector_helper::ThrowSometime::m_construct_count);
      EXPECT_EQ(3, test_vector_helper::ThrowSometime::m_destruct_count);
    }
    EXPECT_EQ(5, test_vector_helper::ThrowSometime::m_destruct_count);
  }

  // construction fails at existed memory
  {
    {
      test_vector_helper::ThrowSometime::setThrowOnConstruction(100);
      ::portable_stl::vector<test_vector_helper::ThrowSometime> vec(4);
      vec.resize(2);
      test_vector_helper::ThrowSometime::setThrowOnConstruction(2); // only 1 successful construction

      try {
        vec.emplace_back(3);
        auto result = vec.emplace_back(3);
        ASSERT_TRUE(false);
      } catch (::portable_stl::logic_error<> &e) {
        static_cast<void>(e);
      }

      // roll back during creation
      ASSERT_EQ(2 + 1, vec.size());
      EXPECT_EQ(1, test_vector_helper::ThrowSometime::m_construct_count);
      EXPECT_EQ(0, test_vector_helper::ThrowSometime::m_destruct_count);
    }
    EXPECT_EQ(2 + 1, test_vector_helper::ThrowSometime::m_destruct_count); // 2 in vec + 1 emplaced
  }
}

TEST(vector, emplace_back_bad_allocation) {
  static_cast<void>(test_info_);

  /**
   * @brief Allocator with limitations.
   */
  using TestAlloc = test_allocator_helper::test_allocator<std::int32_t>;

  // Allocation split_buffer failed
  {
    test_allocator_helper::test_allocator_statistics stat;
    TestAlloc                                        alloc(&stat);
    ::portable_stl::vector<std::int32_t, TestAlloc>  vec{
       {1, 2, 3},
       alloc
    };
    ::portable_stl::vector<std::int32_t, TestAlloc> vec0{vec};
    stat.m_throw_after = 2; // 2 allocation happened already

    auto result = vec.emplace_back(1);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // check roll-back invariant
    EXPECT_EQ(3, vec.size());
    // EXPECT_EQ(vec0, vec);
  }
}

TEST(vector, assign_count_value) {
  static_cast<void>(test_info_);

  /**
   * @brief Size type alias.
   */
  using t_size = typename ::portable_stl::vector<std::int32_t>::size_type;
  // initial empty
  {
    ::portable_stl::vector<std::int32_t> vec;
    t_size                               num{6};
    auto                                 result = vec.assign(num, 3);

    ASSERT_TRUE(result);
    ASSERT_EQ(num, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(3, vec[i]);
    }
  }

  // count = 0
  {
    ::portable_stl::vector<std::int32_t> vec{1, 2, 3, 4};
    t_size                               num{0};
    auto                                 result = vec.assign(num, 3);

    ASSERT_TRUE(result);
    ASSERT_TRUE(vec.empty());
    ASSERT_EQ(4, vec.capacity());
  }

  // reuse all memory
  {
    ::portable_stl::vector<std::int32_t> vec(6, 0);
    t_size                               old_cap{vec.capacity()};

    t_size num{6};
    auto   result = vec.assign(num, 3);

    ASSERT_TRUE(result);
    ASSERT_EQ(num, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(3, vec[i]);
    }
    EXPECT_EQ(old_cap, vec.capacity());
  }

  // reuse less memory
  {
    ::portable_stl::vector<std::int32_t> vec(50, 0);
    t_size                               old_cap{vec.capacity()};

    t_size num{6};
    auto   result = vec.assign(num, 3);

    ASSERT_TRUE(result);
    ASSERT_EQ(num, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(3, vec[i]);
    }
    EXPECT_EQ(old_cap, vec.capacity());
  }

  // reuse size() < memory < capacity()
  {
    ::portable_stl::vector<std::int32_t> vec(50, 0);
    vec.resize(3);
    t_size old_cap{vec.capacity()};

    t_size num{10};
    auto   result = vec.assign(num, 3);

    ASSERT_TRUE(result);
    ASSERT_EQ(num, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(3, vec[i]);
    }
    EXPECT_EQ(old_cap, vec.capacity());
  }

  // full reallocation
  {
    ::portable_stl::vector<std::int32_t> vec(5, 0);

    t_size num{10};
    auto   result = vec.assign(num, 3);

    ASSERT_TRUE(result);
    ASSERT_EQ(num, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(3, vec[i]);
    }
    EXPECT_EQ(num, vec.capacity());
  }

  // bad allocation
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 100;
    ::portable_stl::vector<std::int32_t, TestAllocator> vec(5, 0);
    TestAllocator::m_counter_ok_allocation = 0;

    t_size num{10};
    auto   result = vec.assign(num, 3);

    ASSERT_FALSE(result);
    EXPECT_TRUE(vec.size() <= vec.capacity());
  }

  // bad construction (ThrowSometime)
  {
    test_vector_helper::ThrowSometime::setThrowOnConstruction(100);
    test_vector_helper::ThrowSometime                         value{3};
    ::portable_stl::size_t                                    initial_size{10U};
    ::portable_stl::vector<test_vector_helper::ThrowSometime> vec(initial_size, value);
    test_vector_helper::ThrowSometime::setThrowOnConstruction(3); // only 2 successful construction

    try {
      static_cast<void>(vec.assign(30, value));
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &e) {
      static_cast<void>(e);
    }

    // check invariant
    EXPECT_EQ(2, test_vector_helper::ThrowSometime::m_construct_count);
    // only old elements have been destroyed
    EXPECT_EQ(initial_size, test_vector_helper::ThrowSometime::m_destruct_count);
  }
}

TEST(vector, assign_inputiter_inputiter) {
  static_cast<void>(test_info_);

  /**
   * @brief Size type alias.
   */
  using t_size = typename ::portable_stl::vector<std::int32_t>::size_type;

  /**
   * @brief Test input iterator.
   */
  using t_input_iter = test_iterator_helper::tst_input_iterator<std::int32_t const *>;

  std::int32_t  a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 1, 0};
  std::int32_t *an  = a + sizeof(a) / sizeof(a[0]);
  t_size        num_ref{18};

  // initial empty
  {
    ::portable_stl::vector<std::int32_t> vec;
    auto                                 result = vec.assign(t_input_iter(a), t_input_iter(an));

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(a[i], vec[i]);
    }
  }

  // count = 0
  {
    ::portable_stl::vector<std::int32_t> vec{1, 2, 3, 4};
    auto                                 result = vec.assign(t_input_iter(a), t_input_iter(a));

    ASSERT_TRUE(result);
    ASSERT_TRUE(vec.empty());
    ASSERT_EQ(4, vec.capacity());
  }

  // reuse all memory
  {
    ::portable_stl::vector<std::int32_t> vec(num_ref, 0);
    t_size                               old_cap{vec.capacity()};
    auto                                 old_begin = vec.begin();

    auto result = vec.assign(t_input_iter(a), t_input_iter(an));

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(a[i], vec[i]);
    }
    EXPECT_EQ(old_cap, vec.capacity());
    EXPECT_EQ(old_begin, vec.begin());
  }

  // reuse less memory
  {
    ::portable_stl::vector<std::int32_t> vec(num_ref * 3, 0);
    t_size                               old_cap{vec.capacity()};
    auto                                 old_begin = vec.begin();

    auto result = vec.assign(t_input_iter(a), t_input_iter(an));

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(a[i], vec[i]);
    }
    EXPECT_EQ(old_cap, vec.capacity());
    EXPECT_EQ(old_begin, vec.begin());
  }

  // reuse size() < memory < capacity()
  {
    ::portable_stl::vector<std::int32_t> vec(num_ref * 3, 0);
    vec.resize(num_ref / 2);
    t_size old_cap{vec.capacity()};
    auto   old_begin = vec.begin();

    auto result = vec.assign(t_input_iter(a), t_input_iter(an));

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(a[i], vec[i]);
    }
    EXPECT_EQ(old_cap, vec.capacity());
    EXPECT_EQ(old_begin, vec.begin());
  }

  // full reallocation
  {
    ::portable_stl::vector<std::int32_t> vec(5, 0);
    auto                                 old_begin = vec.begin();

    auto result = vec.assign(t_input_iter(a), t_input_iter(an));

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(a[i], vec[i]);
    }
    EXPECT_GE(vec.capacity(), num_ref);
    EXPECT_NE(old_begin, vec.begin());
  }

  // bad allocation
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 100;
    ::portable_stl::vector<std::int32_t, TestAllocator> vec(5, 0);
    TestAllocator::m_counter_ok_allocation = 0;

    auto result = vec.assign(t_input_iter(a), t_input_iter(an));

    ASSERT_FALSE(result);
    EXPECT_TRUE(vec.size() <= vec.capacity());
  }

  // bad construction (ThrowSometime)
  {
    test_vector_helper::ThrowSometime::setThrowOnConstruction(100);
    test_vector_helper::ThrowSometime                         value{3};
    ::portable_stl::size_t                                    initial_size{10U};
    ::portable_stl::vector<test_vector_helper::ThrowSometime> vec(initial_size, value);
    test_vector_helper::ThrowSometime::setThrowOnConstruction(3); // only 2 successful construction

    try {
      static_cast<void>(vec.assign(t_input_iter(a), t_input_iter(an)));
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &e) {
      static_cast<void>(e);
    }

    // check invariant
    EXPECT_EQ(2, test_vector_helper::ThrowSometime::m_construct_count);
    // only old elements have been destroyed
    EXPECT_EQ(initial_size, test_vector_helper::ThrowSometime::m_destruct_count);
  }
}

TEST(vector, assign_forwarditer_forwarditer) {
  static_cast<void>(test_info_);

  /**
   * @brief Size type alias.
   */
  using t_size = typename ::portable_stl::vector<std::int32_t>::size_type;

  /**
   * @brief Test input iterator.
   */
  using t_forward_iter = test_iterator_helper::tst_forward_iterator<std::int32_t const *>;

  std::int32_t  a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 1, 0};
  std::int32_t *an  = a + sizeof(a) / sizeof(a[0]);
  t_size        num_ref{18};

  // initial empty
  {
    ::portable_stl::vector<std::int32_t> vec;
    auto                                 result = vec.assign(t_forward_iter(a), t_forward_iter(an));

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(a[i], vec[i]);
    }
  }

  // count = 0
  {
    ::portable_stl::vector<std::int32_t> vec{1, 2, 3, 4};
    auto                                 result = vec.assign(t_forward_iter(a), t_forward_iter(a));

    ASSERT_TRUE(result);
    ASSERT_TRUE(vec.empty());
    ASSERT_EQ(4, vec.capacity());
  }

  // reuse all memory
  {
    ::portable_stl::vector<std::int32_t> vec(num_ref, 0);
    t_size                               old_cap{vec.capacity()};
    auto                                 old_begin = vec.begin();

    auto result = vec.assign(t_forward_iter(a), t_forward_iter(an));

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(a[i], vec[i]);
    }
    EXPECT_EQ(old_cap, vec.capacity());
    EXPECT_EQ(old_begin, vec.begin());
  }

  // reuse less memory
  {
    ::portable_stl::vector<std::int32_t> vec(num_ref * 3, 0);
    t_size                               old_cap{vec.capacity()};
    auto                                 old_begin = vec.begin();

    auto result = vec.assign(t_forward_iter(a), t_forward_iter(an));

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(a[i], vec[i]);
    }
    EXPECT_EQ(old_cap, vec.capacity());
    EXPECT_EQ(old_begin, vec.begin());
  }

  // reuse size() < memory < capacity()
  {
    ::portable_stl::vector<std::int32_t> vec(num_ref * 2, 3);
    vec.resize(num_ref / 2);
    t_size old_cap{vec.capacity()};
    auto   old_begin = vec.begin();

    auto result = vec.assign(t_forward_iter(a), t_forward_iter(an));

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(a[i], vec[i]);
    }
    EXPECT_EQ(old_cap, vec.capacity());
    EXPECT_EQ(old_begin, vec.begin());
  }

  // full reallocation
  {
    ::portable_stl::vector<std::int32_t> vec(5, 0);
    auto                                 old_begin = vec.begin();

    auto result = vec.assign(t_forward_iter(a), t_forward_iter(an));

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(a[i], vec[i]);
    }
    EXPECT_GE(vec.capacity(), num_ref);
    EXPECT_NE(old_begin, vec.begin());
  }

  // bad allocation
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 100;
    ::portable_stl::vector<std::int32_t, TestAllocator> vec(5, 0);
    TestAllocator::m_counter_ok_allocation = 0;

    auto result = vec.assign(t_forward_iter(a), t_forward_iter(an));

    ASSERT_FALSE(result);
    EXPECT_TRUE(vec.size() <= vec.capacity());
  }

  // bad construction (ThrowSometime)
  {
    /**
     * @brief Test input iterator.
     */
    using t_forward_iter2 = test_iterator_helper::tst_forward_iterator<test_vector_helper::ThrowSometime const *>;

    test_vector_helper::ThrowSometime::setThrowOnConstruction(100);
    test_vector_helper::ThrowSometime                         value{3};
    ::portable_stl::size_t                                    initial_size{2U};
    ::portable_stl::vector<test_vector_helper::ThrowSometime> vec(initial_size, value);

    test_vector_helper::ThrowSometime  a2[10] = {value, value, value, value, value, value, value, value, value, value};
    test_vector_helper::ThrowSometime *a2n    = a2 + sizeof(a2) / sizeof(a2[0]);
    test_vector_helper::ThrowSometime::setThrowOnConstruction(3); // only 2 successful construction

    try {
      static_cast<void>(vec.assign(t_forward_iter2(a2), t_forward_iter2(a2n)));
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &e) {
      static_cast<void>(e);
    }

    // check invariant
    EXPECT_EQ(2, test_vector_helper::ThrowSometime::m_construct_count);
    // 2 old elements + 2 successful constructed have been destroyed
    EXPECT_EQ(initial_size + 2, test_vector_helper::ThrowSometime::m_destruct_count);
  }
}

TEST(vector, assign_initializer_list) {
  static_cast<void>(test_info_);

  /**
   * @brief Size type alias.
   */
  using t_size = typename ::portable_stl::vector<std::int32_t>::size_type;

  t_size num_ref{10};

  // initial empty
  {
    ::portable_stl::vector<std::int32_t> vec;
    auto                                 result = vec.assign({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(i, vec[i]);
    }
  }

  // count = 0
  {
    ::portable_stl::vector<std::int32_t> vec{1, 2, 3, 4};
    auto                                 result = vec.assign({});

    ASSERT_TRUE(result);
    ASSERT_TRUE(vec.empty());
    ASSERT_EQ(4, vec.capacity());
  }

  // reuse all memory
  {
    ::portable_stl::vector<std::int32_t> vec(num_ref, 0);
    t_size                               old_cap{vec.capacity()};
    auto                                 old_begin = vec.begin();

    auto result = vec.assign({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(i, vec[i]);
    }
    EXPECT_EQ(old_cap, vec.capacity());
    EXPECT_EQ(old_begin, vec.begin());
  }

  // reuse less memory
  {
    ::portable_stl::vector<std::int32_t> vec(num_ref * 3, 0);
    t_size                               old_cap{vec.capacity()};
    auto                                 old_begin = vec.begin();

    auto result = vec.assign({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(i, vec[i]);
    }
    EXPECT_EQ(old_cap, vec.capacity());
    EXPECT_EQ(old_begin, vec.begin());
  }

  // reuse size() < memory < capacity()
  {
    ::portable_stl::vector<std::int32_t> vec(num_ref * 3, 0);
    vec.resize(num_ref / 2);
    t_size old_cap{vec.capacity()};
    auto   old_begin = vec.begin();

    auto result = vec.assign({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(i, vec[i]);
    }
    EXPECT_EQ(old_cap, vec.capacity());
    EXPECT_EQ(old_begin, vec.begin());
  }

  // full reallocation
  {
    ::portable_stl::vector<std::int32_t> vec(5, 0);
    auto                                 old_begin = vec.begin();

    auto result = vec.assign({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});

    ASSERT_TRUE(result);
    ASSERT_EQ(num_ref, vec.size());
    for (decltype(vec)::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(i, vec[i]);
    }
    EXPECT_GE(vec.capacity(), num_ref);
    EXPECT_NE(old_begin, vec.begin());
  }

  // bad allocation
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 100;
    ::portable_stl::vector<std::int32_t, TestAllocator> vec(5, 0);
    TestAllocator::m_counter_ok_allocation = 0;

    auto result = vec.assign({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});

    ASSERT_FALSE(result);
    EXPECT_TRUE(vec.size() <= vec.capacity());
  }

  // bad construction (ThrowSometime)
  {
    test_vector_helper::ThrowSometime::setThrowOnConstruction(100);
    test_vector_helper::ThrowSometime                         value{3};
    ::portable_stl::size_t                                    initial_size{3U};
    ::portable_stl::vector<test_vector_helper::ThrowSometime> vec(initial_size, value);
    test_vector_helper::ThrowSometime::setThrowOnConstruction(10 + 3); // only 2 successful construction in assign

    try {
      static_cast<void>(vec.assign({value, value, value, value, value, value, value, value, value, value}));
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &e) {
      static_cast<void>(e);
    }

    // check invariant
    EXPECT_EQ(10 + 2, test_vector_helper::ThrowSometime::m_construct_count);
    // only old elements have been destroyed
    EXPECT_EQ(initial_size + 10 + 2, test_vector_helper::ThrowSometime::m_destruct_count);
  }
}

TEST(vector, operator_assign_copy) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Allocator.
     */
    using TestAlloc = test_allocator_helper::test_allocator<std::int32_t>;

    ::portable_stl::vector<std::int32_t, TestAlloc> vec0(3, 2, TestAlloc(5));
    ::portable_stl::vector<std::int32_t, TestAlloc> vec(vec0, TestAlloc(3));

    vec = vec0;

    EXPECT_EQ(vec, vec0);
    EXPECT_EQ(vec.get_allocator(), TestAlloc(3));
  }

  // Test with Allocator::propagate_on_container_copy_assignment == false_type
  {
    /**
     * @brief Allocator.
     */
    using TestAlloc = test_allocator_helper::NonPOCCAAllocator<std::int32_t>;
    bool copy_assigned_into{false};

    ::portable_stl::vector<std::int32_t, TestAlloc> vec0(3, 2, TestAlloc(5, nullptr));
    ::portable_stl::vector<std::int32_t, TestAlloc> vec(vec0, TestAlloc(3, &copy_assigned_into));
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
    using TestAlloc = test_allocator_helper::POCCAAllocator<std::int32_t>;
    bool copy_assigned_into{false};

    ::portable_stl::vector<std::int32_t, TestAlloc> vec0(3, 2, TestAlloc(5, nullptr));
    ::portable_stl::vector<std::int32_t, TestAlloc> vec(vec0, TestAlloc(5, &copy_assigned_into));
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
    using TestAlloc = test_allocator_helper::POCCAAllocator<std::int32_t>;
    bool copy_assigned_into{false};

    ::portable_stl::vector<std::int32_t, TestAlloc> vec0(3, 2, TestAlloc(5, nullptr));
    ::portable_stl::vector<std::int32_t, TestAlloc> vec(vec0, TestAlloc(3, &copy_assigned_into));
    EXPECT_FALSE(copy_assigned_into);

    vec = vec0;

    EXPECT_TRUE(copy_assigned_into);
    EXPECT_EQ(vec, vec0);
    EXPECT_EQ(vec.get_allocator(), TestAlloc(5, nullptr));
  }
}

TEST(vector, operator_assign_move) {
  static_cast<void>(test_info_);
  /**
   * @brief Allocator.
   */
  using TestAlloc = test_allocator_helper::test_allocator<test_common_helper::MoveOnly>;

  {
    ::portable_stl::vector<test_common_helper::MoveOnly, TestAlloc> vec0(TestAlloc(5));
    ::portable_stl::vector<test_common_helper::MoveOnly, TestAlloc> vec(TestAlloc(5));
    for (int i = 1; i <= 3; ++i) {
      static_cast<void>(vec0.push_back(i));
      static_cast<void>(vec.push_back(i));
    }
    ::portable_stl::vector<test_common_helper::MoveOnly, TestAlloc> vec2(TestAlloc(5));
    vec2 = std::move(vec0);

    EXPECT_EQ(vec2, vec);
    EXPECT_TRUE(vec0.empty());
    EXPECT_EQ(vec2.get_allocator(), vec.get_allocator());
  }

  {
    ::portable_stl::vector<test_common_helper::MoveOnly, TestAlloc> vec0(TestAlloc(5));
    ::portable_stl::vector<test_common_helper::MoveOnly, TestAlloc> vec(TestAlloc(5));
    for (int i = 1; i <= 3; ++i) {
      static_cast<void>(vec0.push_back(i));
      static_cast<void>(vec.push_back(i));
    }

    ::portable_stl::vector<test_common_helper::MoveOnly, TestAlloc> vec2(TestAlloc(6));
    vec2 = std::move(vec0);

    EXPECT_EQ(vec2, vec);
    EXPECT_FALSE(vec0.empty());
    EXPECT_EQ(vec2.get_allocator(), TestAlloc(6));
  }
}

TEST(vector, push_back_lvalue) {
  static_cast<void>(test_info_);

  /**
   * @brief Vector size type.
   */
  using t_size = ::portable_stl::vector<std::int32_t>::size_type;

  std::int32_t const value0{0};
  std::int32_t const value1{1};
  std::int32_t const value2{2};
  std::int32_t const value3{3};
  std::int32_t const value4{4};
  {
    ::portable_stl::vector<std::int32_t> vec;

    static_cast<void>(vec.push_back(value0));
    EXPECT_EQ(vec.size(), 1);
    for (t_size j{0}; j < vec.size(); ++j) {
      EXPECT_EQ(vec[j], j);
    }

    static_cast<void>(vec.push_back(value1));
    EXPECT_EQ(vec.size(), 2);
    for (t_size j{0}; j < vec.size(); ++j) {
      EXPECT_EQ(vec[j], j);
    }

    static_cast<void>(vec.push_back(value2));
    EXPECT_EQ(vec.size(), 3);
    for (t_size j{0}; j < vec.size(); ++j) {
      EXPECT_EQ(vec[j], j);
    }

    static_cast<void>(vec.push_back(value3));
    EXPECT_EQ(vec.size(), 4);
    for (t_size j{0}; j < vec.size(); ++j) {
      EXPECT_EQ(vec[j], j);
    }

    static_cast<void>(vec.push_back(value4));
    EXPECT_EQ(vec.size(), 5);
    for (t_size j{0}; j < vec.size(); ++j) {
      EXPECT_EQ(vec[j], j);
    }
  }
}

TEST(vector, push_back_rvalue) {
  static_cast<void>(test_info_);

  /**
   * @brief Type alias.
   */
  using t_type = test_common_helper::MoveOnly;

  /**
   * @brief Vector size type.
   */
  using t_size = ::portable_stl::vector<t_type>::size_type;

  {
    ::portable_stl::vector<test_common_helper::MoveOnly> vec;

    static_cast<void>(vec.push_back(t_type(0)));
    EXPECT_EQ(vec.size(), 1);
    for (t_size j{0}; j < vec.size(); ++j) {
      EXPECT_EQ(vec[j], t_size(j));
    }

    static_cast<void>(vec.push_back(t_type(1)));
    EXPECT_EQ(vec.size(), 2);
    for (t_size j{0}; j < vec.size(); ++j) {
      EXPECT_EQ(vec[j], t_size(j));
    }

    static_cast<void>(vec.push_back(t_type(2)));
    EXPECT_EQ(vec.size(), 3);
    for (t_size j{0}; j < vec.size(); ++j) {
      EXPECT_EQ(vec[j], t_size(j));
    }

    static_cast<void>(vec.push_back(t_type(3)));
    EXPECT_EQ(vec.size(), 4);
    for (t_size j{0}; j < vec.size(); ++j) {
      EXPECT_EQ(vec[j], t_size(j));
    }

    static_cast<void>(vec.push_back(t_type(4)));
    EXPECT_EQ(vec.size(), 5);
    for (t_size j{0}; j < vec.size(); ++j) {
      EXPECT_EQ(vec[j], t_size(j));
    }
  }
}

TEST(vector, push_back_lvalue_bad) {
  static_cast<void>(test_info_);

  /**
   * @brief Test type.
   */
  using t_type = ::test_vector_helper::ThrowSometime;

  // Bad construction in already available memory.
  {
    t_type::setThrowOnConstruction(100);
    ::portable_stl::vector<t_type> vec(10, t_type(3));
    t_type                         value(4);
    vec.resize(2);

    t_type::setThrowOnConstruction(1);
    try {
      static_cast<void>(vec.push_back(value));
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check vector invariant
    ASSERT_EQ(2, vec.size());
    EXPECT_EQ(3, vec.back().getData());
  }

  // Bad construction in newly allocated memoty
  {
    t_type::setThrowOnConstruction(100);
    ::portable_stl::vector<t_type> vec(10, t_type(3));
    t_type                         value(4);

    t_type::setThrowOnConstruction(1);
    try {
      static_cast<void>(vec.push_back(value));
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check vector invariant
    ASSERT_EQ(10, vec.size());
    EXPECT_EQ(3, vec.back().getData());
  }

  // Bad construction on swap temp buffer and vector data
  {
    t_type::setThrowOnConstruction(100);
    ::portable_stl::vector<t_type> vec(10, t_type(3));
    t_type                         value(4);

    t_type::setThrowOnConstruction(2);
    try {
      static_cast<void>(vec.push_back(value));
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check vector invariant
    ASSERT_EQ(10, vec.size());
    EXPECT_EQ(3, vec.back().getData());
  }

  // Bad allocation of the temp buffer
  {
    /**
     * @brief Test allocator with limitation.
     */
    using TestAlloc                    = ::test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<std::int32_t, TestAlloc> vec(10, 3);
    std::int32_t const                              value{4};

    TestAlloc::m_counter_ok_allocation = 0;
    auto result                        = vec.push_back(value);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // Check vector invariant
    ASSERT_EQ(10, vec.size());
    EXPECT_EQ(3, vec.back());
  }

  // max_size reaching
  {
    /**
     * @brief Allocator with limitations.
     */
    using TestAlloc = ::test_allocator_helper::TestSimpleAllocator<std::int32_t>;

    TestAlloc::m_counter_ok_allocation = 100;
    TestAlloc::m_max_size              = 5;
    ::portable_stl::vector<std::int32_t, TestAlloc>                  vec(5);
    ::portable_stl::vector<std::int32_t, TestAlloc>::size_type const sz{vec.size()};
    std::int32_t const                                               value{1};

    auto result = vec.push_back(value);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    // Check invariant: strong guarantee
    EXPECT_EQ(sz, vec.size());
    for (::portable_stl::vector<std::int32_t, TestAlloc>::size_type i{0}; i < sz; ++i) {
      EXPECT_EQ(0, vec[i]);
    }

    TestAlloc::m_max_size = 10000;
  }
}

TEST(vector, push_back_rvalue_bad) {
  static_cast<void>(test_info_);

  /**
   * @brief Test type.
   */
  using t_type = ::test_vector_helper::ThrowSometime;

  // Bad construction in already available memory.
  {
    t_type::setThrowOnConstruction(100);
    ::portable_stl::vector<t_type> vec(10, t_type(3));
    vec.resize(2);

    t_type::setThrowOnConstruction(2);
    try {
      static_cast<void>(vec.push_back(t_type(4)));
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check vector invariant
    ASSERT_EQ(2, vec.size());
    EXPECT_EQ(3, vec.back().getData());
  }

  // Bad construction in newly allocated memoty
  {
    t_type::setThrowOnConstruction(100);
    ::portable_stl::vector<t_type> vec(10, t_type(3));

    t_type::setThrowOnConstruction(2);
    try {
      static_cast<void>(vec.push_back(t_type(4)));
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check vector invariant
    ASSERT_EQ(10, vec.size());
    EXPECT_EQ(3, vec.back().getData());
  }

  // Bad construction on swap temp buffer and vector data
  {
    t_type::setThrowOnConstruction(100);
    ::portable_stl::vector<t_type> vec(10, t_type(3));

    t_type::setThrowOnConstruction(3);
    try {
      static_cast<void>(vec.push_back(t_type(4)));
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check vector invariant
    ASSERT_EQ(10, vec.size());
    EXPECT_EQ(3, vec.back().getData());
  }

  // Bad allocation of the temp buffer
  {
    /**
     * @brief Test allocator with limitation.
     */
    using TestAlloc                    = ::test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<std::int32_t, TestAlloc> vec(10, 3);

    TestAlloc::m_counter_ok_allocation = 0;
    auto result                        = vec.push_back(4);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // Check vector invariant
    ASSERT_EQ(10, vec.size());
    EXPECT_EQ(3, vec.back());
  }

  // max_size reaching
  {
    /**
     * @brief Allocator with limitations.
     */
    using TestAlloc = ::test_allocator_helper::TestSimpleAllocator<std::int32_t>;

    TestAlloc::m_counter_ok_allocation = 100;
    TestAlloc::m_max_size              = 5;
    ::portable_stl::vector<std::int32_t, TestAlloc>                  vec(5);
    ::portable_stl::vector<std::int32_t, TestAlloc>::size_type const sz{vec.size()};

    auto result = vec.push_back(4);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    // Check invariant: strong guarantee
    EXPECT_EQ(sz, vec.size());
    for (::portable_stl::vector<std::int32_t, TestAlloc>::size_type i{0}; i < sz; ++i) {
      EXPECT_EQ(0, vec[i]);
    }

    TestAlloc::m_max_size = 10000;
  }
}

TEST(vector, pop_back) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::vector<std::int32_t> vec;

    vec.push_back(1);
    EXPECT_EQ(1, vec.size());

    vec.pop_back();
    EXPECT_EQ(0, vec.size());
  }
  // LWG 526
  {
    std::int32_t                         arr[] = {0, 1, 2, 3, 4};
    ::portable_stl::size_t               sz{5U};
    ::portable_stl::vector<std::int32_t> vec(arr, arr + sz);

    while (vec.size() < vec.capacity()) {
      vec.push_back(static_cast<std::int32_t>(sz++));
    }

    vec.push_back(vec.front());
    EXPECT_EQ(0, vec.back());
    for (::portable_stl::size_t i{0U}; i < sz; ++i) {
      EXPECT_EQ(i, vec[i]);
    }
  }
}

TEST(vector, erase_position) {
  static_cast<void>(test_info_);

  {
    std::int32_t                         a1[] = {1, 2, 3, 4, 5};
    ::portable_stl::vector<std::int32_t> vec(a1, a1 + 5);
    vec.erase(vec.begin());
    EXPECT_EQ(vec, ::portable_stl::vector<std::int32_t>(a1 + 1, a1 + 5));
  }
  {
    std::int32_t                         a1[] = {1, 2, 3, 4, 5};
    std::int32_t                         e1[] = {1, 3, 4, 5};
    ::portable_stl::vector<std::int32_t> vec(a1, a1 + 5);
    vec.erase(vec.begin() + 1);
    EXPECT_EQ(vec, ::portable_stl::vector<std::int32_t>(e1, e1 + 4));
  }
  {
    std::int32_t                                         a1[] = {1, 2, 3};
    ::portable_stl::vector<std::int32_t>                 vec(a1, a1 + 3);
    ::portable_stl::vector<std::int32_t>::const_iterator i{vec.begin()};
    ++i;

    ::portable_stl::vector<std::int32_t>::iterator j{vec.erase(i)};
    EXPECT_EQ(2U, vec.size());
    EXPECT_EQ(2, ::portable_stl::distance(vec.begin(), vec.end()));
    EXPECT_EQ(3, *j);
    EXPECT_EQ(1, *vec.begin());
    EXPECT_EQ(3, *::portable_stl::next(vec.begin()));

    j = vec.erase(j);
    EXPECT_EQ(j, vec.end());
    EXPECT_EQ(1U, vec.size());
    EXPECT_EQ(1, ::portable_stl::distance(vec.begin(), vec.end()));
    EXPECT_EQ(1, *vec.begin());

    j = vec.erase(vec.begin());
    EXPECT_EQ(j, vec.end());
    EXPECT_EQ(0U, vec.size());
    EXPECT_EQ(0, ::portable_stl::distance(vec.begin(), vec.end()));
  }

  // Make sure vector::erase works with move-only types when non-trivial
  {
    ::portable_stl::vector<test_common_helper::MoveOnly> vec;
    vec.emplace_back(1);
    vec.emplace_back(2);
    vec.emplace_back(3);
    vec.erase(vec.begin());
    EXPECT_EQ(2, vec.size());
    EXPECT_EQ(vec[0], test_common_helper::MoveOnly(2));
    EXPECT_EQ(vec[1], test_common_helper::MoveOnly(3));
  }

  // When trivial
  {
    ::portable_stl::vector<test_vector_helper::TrivialMoveOnly> vec;
    vec.emplace_back(1);
    vec.emplace_back(2);
    vec.emplace_back(3);
    vec.erase(vec.begin());
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], test_vector_helper::TrivialMoveOnly(2));
    EXPECT_EQ(vec[1], test_vector_helper::TrivialMoveOnly(3));
  }

  // Bad copy/move assignment during moving elements after erased position.
  {
    using t_type            = test_vector_helper::ThrowCopyMove;
    t_type::m_throw_on_move = false;
    t_type::m_throw_on_copy = false;
    ::portable_stl::vector<t_type> vec{t_type(1), t_type(2), t_type(3)};

    t_type::m_throw_on_move = true;
    try {
      static_cast<void>(vec.erase(::portable_stl::next(vec.begin())));
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check vector invariant: basic guarantee
    ASSERT_GE(vec.size(), 1);
    EXPECT_EQ(1, vec[0].getData());
  }
}

TEST(vector, erase_iter_iter) {
  static_cast<void>(test_info_);

  std::int32_t a1[] = {1, 2, 3};
  {
    ::portable_stl::vector<std::int32_t> vec(a1, a1 + 3);

    ::portable_stl::vector<std::int32_t>::iterator i = vec.erase(vec.cbegin(), vec.cbegin());

    EXPECT_EQ(3, vec.size());
    EXPECT_EQ(3, ::portable_stl::distance(vec.cbegin(), vec.cend()));
    EXPECT_EQ(i, vec.begin());
  }
  {
    ::portable_stl::vector<std::int32_t> vec(a1, a1 + 3);

    ::portable_stl::vector<std::int32_t>::iterator i = vec.erase(vec.cbegin(), ::portable_stl::next(vec.cbegin()));

    EXPECT_EQ(2, vec.size());
    EXPECT_EQ(2, ::portable_stl::distance(vec.cbegin(), vec.cend()));
    EXPECT_EQ(i, vec.begin());
    EXPECT_EQ(vec, ::portable_stl::vector<std::int32_t>(a1 + 1, a1 + 3));
  }
  {
    ::portable_stl::vector<std::int32_t> vec(a1, a1 + 3);

    ::portable_stl::vector<std::int32_t>::iterator i = vec.erase(vec.cbegin(), ::portable_stl::next(vec.cbegin(), 2));

    EXPECT_EQ(1, vec.size());
    EXPECT_EQ(1, ::portable_stl::distance(vec.cbegin(), vec.cend()));
    EXPECT_EQ(i, vec.begin());
    EXPECT_EQ(vec, ::portable_stl::vector<std::int32_t>(a1 + 2, a1 + 3));
  }
  {
    ::portable_stl::vector<std::int32_t> vec(a1, a1 + 3);

    ::portable_stl::vector<std::int32_t>::iterator i = vec.erase(vec.cbegin(), ::portable_stl::next(vec.cbegin(), 3));

    EXPECT_EQ(0, vec.size());
    EXPECT_EQ(0, ::portable_stl::distance(vec.cbegin(), vec.cend()));
    EXPECT_EQ(i, vec.begin());
  }
  {
    std::vector<::portable_stl::vector<std::int32_t>> outer(2, ::portable_stl::vector<std::int32_t>(1));

    outer.erase(outer.begin(), outer.begin());

    EXPECT_EQ(2, outer.size());
    EXPECT_EQ(1, outer[0].size());
    EXPECT_EQ(1, outer[1].size());
  }
  // Make sure vector::erase works with move-only types
  {
    // When non-trivial
    {
      ::portable_stl::vector<test_common_helper::MoveOnly> vec;
      vec.emplace_back(1);
      vec.emplace_back(2);
      vec.emplace_back(3);

      vec.erase(vec.begin(), vec.begin() + 2);

      EXPECT_EQ(1, vec.size());
      EXPECT_EQ(vec[0], test_common_helper::MoveOnly(3));
    }
    // When trivial
    {
      ::portable_stl::vector<test_vector_helper::TrivialMoveOnly> vec;
      vec.emplace_back(1);
      vec.emplace_back(2);
      vec.emplace_back(3);

      vec.erase(vec.begin(), vec.begin() + 2);

      EXPECT_EQ(1, vec.size());
      EXPECT_EQ(vec[0], test_vector_helper::TrivialMoveOnly(3));
    }
  }

  // Bad copy/move assignment during moving elements after erased position.
  {
    using t_type            = test_vector_helper::ThrowCopyMove;
    t_type::m_throw_on_move = false;
    t_type::m_throw_on_copy = false;
    ::portable_stl::vector<t_type> vec{t_type(1), t_type(2), t_type(3), t_type(4), t_type(5)};

    t_type::m_throw_on_move = true;
    try {
      static_cast<void>(vec.erase(vec.begin() + 1, vec.end() - 2));
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check vector invariant: basic guarantee
    ASSERT_GE(vec.size(), 1);
    EXPECT_EQ(1, vec[0].getData());
  }
}
