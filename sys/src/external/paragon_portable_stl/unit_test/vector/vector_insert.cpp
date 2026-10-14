// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="vector_insert.cpp"
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

TEST(vector, insert_iter_lvalue) {
  static_cast<void>(test_info_);

  // Middle, , reallocation expected
  {
    ::portable_stl::vector<std::int32_t> vec(100);
    std::int32_t const                   lvalue{1};

    auto result = vec.insert(vec.cbegin() + 10, lvalue);
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(101, vec.size());
    EXPECT_EQ(vec.begin() + 10, it);

    ::portable_stl::size_t j{0U};
    for (; j < 10; ++j) {
      EXPECT_EQ(0, vec[j]);
    }
    EXPECT_EQ(1, vec[j]);
    for (++j; j < 101; ++j) {
      EXPECT_EQ(0, vec[j]);
    }
  }

  // At the end, no reallocation expected
  {
    std::size_t const                    num{100};
    ::portable_stl::vector<std::int32_t> vec(num);
    vec.push_back(0);
    vec.pop_back();
    std::int32_t const lvalue{1};

    auto result = vec.insert(vec.cbegin() + num, lvalue);
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(num + 1, vec.size());
    EXPECT_EQ(vec.begin() + num, it);
    for (::portable_stl::size_t i{0U}; i < num; ++i) {
      EXPECT_EQ(0, vec[i]);
    }
    EXPECT_EQ(lvalue, vec[num]);
  }

  // Middle, reallocation expected
  {
    ::portable_stl::vector<std::int32_t> vec(100);
    while (vec.size() < vec.capacity()) {
      vec.push_back(0); // size = capacity
    }
    std::size_t const  sz{vec.size()};
    std::int32_t const lvalue = 1;

    auto result = vec.insert(vec.cbegin() + 10, lvalue);
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(sz + 1, vec.size());
    EXPECT_EQ(vec.begin() + 10, it);
    ::portable_stl::size_t j{0U};
    for (; j < 10; ++j) {
      EXPECT_EQ(0, vec[j]);
    }
    EXPECT_EQ(1, vec[j]);
    for (++j; j < vec.size(); ++j) {
      EXPECT_EQ(0, vec[j]);
    }
  }

  // Middle, no reallocation expected
  {
    ::portable_stl::vector<std::int32_t> vec(100);
    while (vec.size() < vec.capacity()) {
      vec.push_back(0);
    }

    vec.pop_back();
    vec.pop_back(); // force no reallocation
    std::size_t const  sz{vec.size()};
    std::int32_t const lvalue{1};

    auto result = vec.insert(vec.cbegin() + 10, lvalue);
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(sz + 1, vec.size());
    EXPECT_EQ(vec.begin() + 10, it);

    ::portable_stl::size_t j{0U};
    for (; j < 10; ++j) {
      EXPECT_EQ(0, vec[j]);
    }
    EXPECT_EQ(1, vec[j]);
    for (++j; j < vec.size(); ++j) {
      EXPECT_EQ(0, vec[j]);
    }
  }

  // Middle, no reallocation expected, value - is a reference to vector's element after position of insertion
  {
    ::portable_stl::vector<std::int32_t> vec(100);
    while (vec.size() < vec.capacity()) {
      vec.push_back(0);
    }

    vec.pop_back();
    vec.pop_back(); // force no reallocation

    std::size_t const ref_index{20};
    vec[ref_index] = 3;
    std::size_t const sz{vec.size()};

    auto result = vec.insert(vec.cbegin() + 10, vec[ref_index]);
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(sz + 1, vec.size());
    EXPECT_EQ(vec.begin() + 10, it);

    ::portable_stl::size_t j{0U};
    for (; j < 10; ++j) {
      EXPECT_EQ(0, vec[j]);
    }
    EXPECT_EQ(3, vec[j]);
    for (++j; j <= ref_index; ++j) {
      EXPECT_EQ(0, vec[j]) << j;
    }
    EXPECT_EQ(3, vec[ref_index + 1]);
    for (++j; j < vec.size(); ++j) {
      EXPECT_EQ(0, vec[j]) << j;
    }
  }

  // Bad allocation of the temp buffer
  {
    /**
     * @brief Allocator with limitations.
     */
    using TestAlloc = ::test_allocator_helper::TestSimpleAllocator<std::int32_t>;

    TestAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<std::int32_t, TestAlloc>                  vec(10);
    ::portable_stl::vector<std::int32_t, TestAlloc>::size_type const sz{vec.size()};
    std::int32_t const                                               value{1};

    TestAlloc::m_counter_ok_allocation = 0;
    auto result                        = vec.insert(vec.cbegin() + 5, value);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // Check invariant: strong guarantee
    EXPECT_EQ(sz, vec.size());
    for (::portable_stl::vector<std::int32_t, TestAlloc>::size_type i{0U}; i < sz; ++i) {
      EXPECT_EQ(0, vec[i]);
    }
  }

  // Bad copy/move assignment during moving elements
  {
    using t_type            = test_vector_helper::ThrowCopyMove;
    t_type::m_throw_on_move = false;
    t_type::m_throw_on_copy = false;
    ::portable_stl::vector<t_type> vec{t_type(1), t_type(2), t_type(3), t_type(4), t_type(5)};
    vec.push_back(6);
    vec.pop_back();
    ::portable_stl::vector<t_type>::size_type const sz{vec.size()};

    t_type::m_throw_on_move = true;
    try {
      static_cast<void>(vec.insert(vec.begin() + 2, vec[3]));
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check vector invariant: strong guarantee
    ASSERT_GE(sz, vec.size());
    for (::portable_stl::vector<t_type>::size_type i{0U}; i < vec.size(); ++i) {
      EXPECT_EQ(i + 1, vec[i].getData());
    }
  }

  // Bad construction at the end
  {
    using t_type            = test_vector_helper::ThrowCopyMove;
    t_type::m_throw_on_move = false;
    t_type::m_throw_on_copy = false;
    ::portable_stl::vector<t_type> vec{t_type(1), t_type(2), t_type(3), t_type(4), t_type(5)};
    vec.push_back(6);
    vec.pop_back();
    t_type                                          value{3};
    ::portable_stl::vector<t_type>::size_type const sz{vec.size()};

    t_type::m_throw_on_copy = true;
    try {
      static_cast<void>(vec.insert(vec.end(), value));
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check vector invariant: strong guarantee
    ASSERT_GE(sz, vec.size());
    for (::portable_stl::vector<t_type>::size_type i{0U}; i < vec.size(); ++i) {
      EXPECT_EQ(i + 1, vec[i].getData());
    }
  }

  // Bad construction at newly allocated temp buffer.
  {
    using t_type            = test_vector_helper::ThrowCopyMove;
    t_type::m_throw_on_move = false;
    t_type::m_throw_on_copy = false;
    ::portable_stl::vector<t_type>                  vec{t_type(1), t_type(2), t_type(3), t_type(4), t_type(5)};
    t_type                                          value{3};
    ::portable_stl::vector<t_type>::size_type const sz{vec.size()};

    t_type::m_throw_on_copy = true;
    try {
      static_cast<void>(vec.insert(vec.end(), value));
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check vector invariant: strong guarantee
    ASSERT_GE(sz, vec.size());
    for (::portable_stl::vector<t_type>::size_type i{0U}; i < vec.size(); ++i) {
      EXPECT_EQ(i + 1, vec[i].getData());
    }
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

    auto result = vec.insert(vec.cbegin(), value);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    // Check invariant: strong guarantee
    EXPECT_EQ(sz, vec.size());
    for (::portable_stl::vector<std::int32_t, TestAlloc>::size_type i{0U}; i < sz; ++i) {
      EXPECT_EQ(0, vec[i]);
    }

    TestAlloc::m_max_size = 10000;
  }
}

TEST(vector, insert_iter_rvalue) {
  static_cast<void>(test_info_);

  /**
   * @brief Move only type alias.
   */
  using t_move_type = test_common_helper::MoveOnly;

  // Middle, , reallocation expected
  {
    ::portable_stl::vector<t_move_type> vec(100);

    auto result = vec.insert(vec.cbegin() + 10, t_move_type(3));
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(101, vec.size());
    EXPECT_EQ(vec.begin() + 10, it);

    ::portable_stl::size_t j{0U};
    for (; j < 10; ++j) {
      EXPECT_EQ(t_move_type(), vec[j]);
    }
    EXPECT_EQ(t_move_type(3), vec[j]);
    for (++j; j < 101; ++j) {
      EXPECT_EQ(t_move_type(), vec[j]);
    }
  }

  // At the end, no reallocation expected
  {
    std::size_t const                   num{100};
    ::portable_stl::vector<t_move_type> vec(num);
    vec.push_back(0);
    vec.pop_back();

    auto result = vec.insert(vec.cbegin() + num, t_move_type(7));
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(num + 1, vec.size());
    EXPECT_EQ(vec.begin() + num, it);
    for (::portable_stl::size_t j{0U}; j < num; ++j) {
      EXPECT_EQ(t_move_type(), vec[j]);
    }
    EXPECT_EQ(t_move_type(7), vec[num]);
  }

  // Middle, reallocation expected
  {
    ::portable_stl::vector<t_move_type> vec(100);
    while (vec.size() < vec.capacity()) {
      vec.push_back(0); // size = capacity
    }
    std::size_t const sz{vec.size()};

    auto result = vec.insert(vec.cbegin() + 10, t_move_type(7));
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(sz + 1, vec.size());
    EXPECT_EQ(vec.begin() + 10, it);

    ::portable_stl::size_t j{0U};
    for (; j < 10; ++j) {
      EXPECT_EQ(t_move_type(), vec[j]);
    }
    EXPECT_EQ(t_move_type(7), vec[j]);
    for (++j; j < vec.size(); ++j) {
      EXPECT_EQ(t_move_type(), vec[j]);
    }
  }

  // Middle, no reallocation expected
  {
    ::portable_stl::vector<t_move_type> vec(100);
    while (vec.size() < vec.capacity()) {
      vec.push_back(0);
    }

    vec.pop_back();
    vec.pop_back(); // force no reallocation
    std::size_t const sz{vec.size()};

    auto result = vec.insert(vec.cbegin() + 10, t_move_type(7));
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(sz + 1, vec.size());
    EXPECT_EQ(vec.begin() + 10, it);

    ::portable_stl::size_t j{0U};
    for (; j < 10; ++j) {
      EXPECT_EQ(t_move_type(), vec[j]);
    }
    EXPECT_EQ(t_move_type(7), vec[j]);
    for (++j; j < vec.size(); ++j) {
      EXPECT_EQ(t_move_type(), vec[j]);
    }
  }

  // Bad allocation of the temp buffer
  {
    /**
     * @brief Allocator with limitations.
     */
    using TestAlloc = ::test_allocator_helper::TestSimpleAllocator<t_move_type>;

    TestAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<t_move_type, TestAlloc>                  vec(10);
    ::portable_stl::vector<t_move_type, TestAlloc>::size_type const sz{vec.size()};

    TestAlloc::m_counter_ok_allocation = 0;
    auto result                        = vec.insert(vec.cbegin() + 5, t_move_type(7));

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // Check invariant: strong guarantee
    EXPECT_EQ(sz, vec.size());
    for (::portable_stl::vector<t_move_type, TestAlloc>::size_type j{0}; j < sz; ++j) {
      EXPECT_EQ(t_move_type(), vec[j]);
    }
  }

  // Bad copy/move assignment during moving elements
  {
    using t_type            = test_vector_helper::ThrowCopyMove;
    t_type::m_throw_on_move = false;
    t_type::m_throw_on_copy = false;
    ::portable_stl::vector<t_type> vec{t_type(1), t_type(2), t_type(3), t_type(4), t_type(5)};
    vec.push_back(6);
    vec.pop_back();
    ::portable_stl::vector<t_type>::size_type const sz{vec.size()};

    t_type::m_throw_on_move = true;
    try {
      static_cast<void>(vec.insert(vec.begin() + 2, t_type(7)));
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check vector invariant: strong guarantee
    ASSERT_GE(sz, vec.size());
    for (::portable_stl::vector<t_type>::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(i + 1, vec[i].getData());
    }
  }

  // Bad construction at the end
  {
    using t_type            = test_vector_helper::ThrowCopyMove;
    t_type::m_throw_on_move = false;
    t_type::m_throw_on_copy = false;
    ::portable_stl::vector<t_type> vec{t_type(1), t_type(2), t_type(3), t_type(4), t_type(5)};
    vec.push_back(6);
    vec.pop_back();
    ::portable_stl::vector<t_type>::size_type const sz{vec.size()};

    t_type::m_throw_on_move = true;
    try {
      static_cast<void>(vec.insert(vec.end(), t_type(3)));
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check vector invariant: strong guarantee
    ASSERT_GE(sz, vec.size());
    for (::portable_stl::vector<t_type>::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(i + 1, vec[i].getData());
    }
  }

  // Bad construction at newly allocated temp buffer.
  {
    using t_type            = test_vector_helper::ThrowCopyMove;
    t_type::m_throw_on_move = false;
    t_type::m_throw_on_copy = false;
    ::portable_stl::vector<t_type>                  vec{t_type(1), t_type(2), t_type(3), t_type(4), t_type(5)};
    ::portable_stl::vector<t_type>::size_type const sz{vec.size()};

    t_type::m_throw_on_move = true;
    try {
      static_cast<void>(vec.insert(vec.end(), t_type(3)));
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check vector invariant: strong guarantee
    ASSERT_GE(sz, vec.size());
    for (::portable_stl::vector<t_type>::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(i + 1, vec[i].getData());
    }
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

    auto result = vec.insert(vec.cbegin(), 1);

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

TEST(vector, insert_iter_num_value) {
  static_cast<void>(test_info_);

  // Reallocation expected
  {
    ::portable_stl::vector<std::int32_t> vec(100);
    while (vec.size() < vec.capacity()) {
      vec.push_back(0);
    }
    auto sz = vec.size();

    auto result = vec.insert(vec.cbegin() + 10, 5, 1);
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(sz + 5, vec.size());
    EXPECT_EQ(vec.begin() + 10, it);

    decltype(sz) j{0};
    for (; j < 10; ++j) {
      EXPECT_EQ(0, vec[j]);
    }
    for (; j < 15; ++j) {
      EXPECT_EQ(1, vec[j]);
    }
    for (++j; j < vec.size(); ++j) {
      EXPECT_EQ(0, vec[j]);
    }
  }

  // No reallocation expected
  {
    ::portable_stl::vector<std::int32_t> vec(100);
    for (int i{0}; i < 6; ++i) {
      vec.push_back(0);
    }
    for (int i{0}; i < 6; ++i) {
      vec.pop_back();
    }
    auto sz = vec.size();

    auto result = vec.insert(vec.cbegin() + 10, 5, 1);
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(sz + 5, vec.size());
    EXPECT_EQ(vec.begin() + 10, it);

    decltype(sz) j{0};
    for (; j < 10; ++j) {
      EXPECT_EQ(0, vec[j]);
    }
    for (; j < 15; ++j) {
      EXPECT_EQ(1, vec[j]);
    }
    for (++j; j < vec.size(); ++j) {
      EXPECT_EQ(0, vec[j]);
    }
  }

  // No reallocation expected, position < end() < (position + num)
  {
    ::portable_stl::vector<std::int32_t> vec(100);
    for (int i{0}; i < 20; ++i) {
      vec.push_back(0);
    }
    for (int i{0}; i < 20; ++i) {
      vec.pop_back();
    }
    auto sz = vec.size();

    auto result = vec.insert(vec.cbegin() + 95, 10, 1);
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(sz + 10, vec.size());
    EXPECT_EQ(vec.begin() + 95, it);

    decltype(sz) j{0};
    for (; j < 95; ++j) {
      EXPECT_EQ(0, vec[j]);
    }
    for (; j < 95 + 10; ++j) {
      EXPECT_EQ(1, vec[j]);
    }
    for (++j; j < vec.size(); ++j) {
      EXPECT_EQ(0, vec[j]);
    }
  }

  // insert value from the same vector
  {
    ::portable_stl::vector<std::int32_t> vec(100);
    for (int i{0}; i < 6; ++i) {
      vec.push_back(0);
    }
    for (int i{0}; i < 6; ++i) {
      vec.pop_back();
    }
    auto sz = vec.size();
    vec[30] = 3;

    auto result = vec.insert(vec.cbegin() + 10, 5, vec[30]);
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(sz + 5, vec.size());
    EXPECT_EQ(vec.begin() + 10, it);

    decltype(sz) j{0};
    for (; j < 10; ++j) {
      EXPECT_EQ(0, vec[j]);
    }
    for (; j < 15; ++j) {
      EXPECT_EQ(3, vec[j]);
    }
    for (; j < (30 + 5); ++j) {
      EXPECT_EQ(0, vec[j]);
    }
    EXPECT_EQ(3, vec[j]);
    for (++j; j < vec.size(); ++j) {
      EXPECT_EQ(0, vec[j]);
    }
  }

  // Bad allocation of the temp buffer
  {
    /**
     * @brief Allocator with limitations.
     */
    using TestAlloc = ::test_allocator_helper::TestSimpleAllocator<std::int32_t>;

    TestAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<std::int32_t, TestAlloc>                  vec(10);
    ::portable_stl::vector<std::int32_t, TestAlloc>::size_type const sz{vec.size()};
    std::int32_t const                                               value{1};

    TestAlloc::m_counter_ok_allocation = 0;
    auto result                        = vec.insert(vec.cbegin() + 5, 5, value);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // Check invariant: strong guarantee
    EXPECT_EQ(sz, vec.size());
    for (::portable_stl::vector<std::int32_t, TestAlloc>::size_type i{0}; i < sz; ++i) {
      EXPECT_EQ(0, vec[i]);
    }
  }

  // Bad copy/move assignment during moving elements
  {
    using t_type            = test_vector_helper::ThrowCopyMove;
    t_type::m_throw_on_move = false;
    t_type::m_throw_on_copy = false;
    ::portable_stl::vector<t_type> vec{t_type(1), t_type(2), t_type(3), t_type(4), t_type(5)};
    for (int i{0}; i < 10; ++i) {
      vec.push_back(0);
    }
    for (int i{0}; i < 10; ++i) {
      vec.pop_back();
    }
    ::portable_stl::vector<t_type>::size_type const sz{vec.size()};

    t_type::m_throw_on_move = true;
    try {
      static_cast<void>(vec.insert(vec.begin() + 2, 5, vec[3]));
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check vector invariant: basic guarantee
    // ASSERT_GE(sz, vec.size());
    for (::portable_stl::vector<t_type>::size_type i{0}; i < sz; ++i) {
      EXPECT_EQ(i + 1, vec[i].getData());
    }
  }

  // Bad copy assignment during construction after end()
  {
    using t_type            = test_vector_helper::ThrowCopyMove;
    t_type::m_throw_on_move = false;
    t_type::m_throw_on_copy = false;
    ::portable_stl::vector<t_type> vec{t_type(1), t_type(2), t_type(3), t_type(4), t_type(5)};
    for (int i{0}; i < 10; ++i) {
      vec.push_back(0);
    }
    for (int i{0}; i < 10; ++i) {
      vec.pop_back();
    }
    ::portable_stl::vector<t_type>::size_type const sz{vec.size()};

    t_type::m_throw_on_copy = true;
    try {
      static_cast<void>(vec.insert(vec.begin() + 2, 5, vec[3]));
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check vector invariant: strong guarantee
    ASSERT_GE(sz, vec.size());
    for (::portable_stl::vector<t_type>::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(i + 1, vec[i].getData());
    }
  }

  // Bad copy assignment during filling range [pos, pos+num)
  {
    using t_type            = test_vector_helper::ThrowCopyMove;
    t_type::m_throw_on_move = false;
    t_type::m_throw_on_copy = false;
    ::portable_stl::vector<t_type> vec{t_type(1), t_type(2), t_type(3), t_type(4), t_type(5)};
    for (int i{0}; i < 10; ++i) {
      vec.push_back(0);
    }
    for (int i{0}; i < 10; ++i) {
      vec.pop_back();
    }
    t_type value{3};

    t_type::m_throw_on_copy = true;
    try {
      static_cast<void>(vec.insert(vec.begin(), 3, value));
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check vector invariant: basic guarantee
    ASSERT_GE(vec.capacity(), vec.size());
  }

  // Bad construction at newly allocated temp buffer.
  {
    using t_type            = test_vector_helper::ThrowCopyMove;
    t_type::m_throw_on_move = false;
    t_type::m_throw_on_copy = false;
    ::portable_stl::vector<t_type>                  vec{t_type(1), t_type(2), t_type(3), t_type(4), t_type(5)};
    t_type                                          value{3};
    ::portable_stl::vector<t_type>::size_type const sz{vec.size()};

    t_type::m_throw_on_copy = true;
    try {
      static_cast<void>(vec.insert(vec.end(), value));
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check vector invariant: strong guarantee
    ASSERT_GE(sz, vec.size());
    for (::portable_stl::vector<t_type>::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(i + 1, vec[i].getData());
    }
  }

  // max_size reaching
  {
    /**
     * @brief Allocator with limitations.
     */
    using TestAlloc = ::test_allocator_helper::TestSimpleAllocator<std::int32_t>;

    TestAlloc::m_counter_ok_allocation = 100;
    TestAlloc::m_max_size              = 9;
    ::portable_stl::vector<std::int32_t, TestAlloc>                  vec(5);
    ::portable_stl::vector<std::int32_t, TestAlloc>::size_type const sz{vec.size()};

    auto result = vec.insert(vec.cbegin(), 5, 1);

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

TEST(vector, insert_iter_iter_iter_input_iterators) {
  static_cast<void>(test_info_);

  // Reallocation expected
  {
    /**
     * @brief Vector alias.
     */
    using t_vector = ::portable_stl::vector<std::int32_t>;
    t_vector vec(100);
    while (vec.size() < vec.capacity()) {
      vec.push_back(0); // force reallocation
    }
    std::int32_t                 a[]    = {1, 2, 3, 4, 5};
    ::portable_stl::size_t const N      = sizeof(a) / sizeof(a[0]);
    auto                         result = vec.insert(vec.cbegin() + 10,
                             test_iterator_helper::tst_input_iterator<std::int32_t const *>(a),
                             test_iterator_helper::tst_input_iterator<std::int32_t const *>(a + N));
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(100U + N, vec.size());
    EXPECT_EQ(vec.begin() + 10, it);

    ::portable_stl::size_t j{0U};
    for (; j < 10U; ++j) {
      EXPECT_EQ(0, vec[j]);
    }
    for (::portable_stl::size_t k{0U}; k < N; ++j, ++k) {
      EXPECT_EQ(vec[j], a[k]);
    }
    for (; j < 105U; ++j) {
      EXPECT_EQ(0, vec[j]);
    }
  }

  // No reallocation expected
  {
    /**
     * @brief Vector alias.
     */
    using t_vector = ::portable_stl::vector<std::int32_t>;
    t_vector vec(100);
    vec.reserve(120);
    std::int32_t                 a[]    = {1, 2, 3, 4, 5};
    ::portable_stl::size_t const N      = sizeof(a) / sizeof(a[0]);
    auto                         result = vec.insert(vec.cbegin() + 10,
                             test_iterator_helper::tst_input_iterator<std::int32_t const *>(a),
                             test_iterator_helper::tst_input_iterator<std::int32_t const *>(a + N));
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(100U + N, vec.size());
    EXPECT_EQ(vec.begin() + 10, it);

    ::portable_stl::size_t j{0U};
    for (; j < 10U; ++j) {
      EXPECT_EQ(0, vec[j]);
    }
    for (::portable_stl::size_t k{0U}; k < N; ++j, ++k) {
      EXPECT_EQ(vec[j], a[k]);
    }
    for (; j < 105U; ++j) {
      EXPECT_EQ(0, vec[j]);
    }
  }

  // Bad construction at available memory (end..end_cap)
  {
    /**
     * @brief Type with lmitations.
     */
    using t_type   = test_vector_helper::ThrowSometime;
    /**
     * @brief Test vector type.
     */
    using t_vector = ::portable_stl::vector<t_type>;

    t_type::setThrowOnConstruction(100);
    t_vector vec{t_type(1), t_type(2), t_type(3), t_type(4), t_type(5)};
    vec.reserve(10);
    auto origin_size = vec.size();

    std::int32_t       a[] = {11, 12, 13, 14, 15};
    std::int32_t const N   = sizeof(a) / sizeof(a[0]);

    t_type::setThrowOnConstruction(3);
    try {
      static_cast<void>(vec.insert(vec.cbegin() + 3,
                                   test_iterator_helper::tst_input_iterator<std::int32_t const *>(a),
                                   test_iterator_helper::tst_input_iterator<std::int32_t const *>(a + N)));
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check vector invariant: strong guarantee
    ASSERT_EQ(origin_size, vec.size());
    for (::portable_stl::vector<t_type>::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(i + 1, vec[i].getData());
    }
    EXPECT_EQ(t_type::m_construct_count, t_type::m_destruct_count);
  }

  // Bad construction at temporary buffer
  {
    /**
     * @brief Type with lmitations.
     */
    using t_type   = test_vector_helper::ThrowSometime;
    /**
     * @brief Test vector type.
     */
    using t_vector = ::portable_stl::vector<t_type>;

    t_type::setThrowOnConstruction(100);
    t_vector vec{t_type(1), t_type(2), t_type(3), t_type(4), t_type(5)};
    vec.reserve(6); // only one alaliable space for insertion.
    auto origin_size = vec.size();

    std::int32_t       a[] = {11, 12, 13, 14, 15};
    std::int32_t const N   = sizeof(a) / sizeof(a[0]);

    t_type::setThrowOnConstruction(3);
    try {
      static_cast<void>(vec.insert(vec.cbegin() + 3,
                                   test_iterator_helper::tst_input_iterator<std::int32_t const *>(a),
                                   test_iterator_helper::tst_input_iterator<std::int32_t const *>(a + N)));
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check vector invariant: strong guarantee
    ASSERT_EQ(origin_size, vec.size());
    for (::portable_stl::vector<t_type>::size_type i{0U}; i < vec.size(); ++i) {
      EXPECT_EQ(i + 1, vec[i].getData());
    }
    EXPECT_EQ(t_type::m_construct_count, t_type::m_destruct_count);
  }

  // Bad allocation of a temporary buffer
  {
    /**
     * @brief Type with lmitations.
     */
    using TestAlloc                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    /**
     * @brief Test vector type.
     */
    using t_vector                     = ::portable_stl::vector<std::int32_t, TestAlloc>;
    TestAlloc::m_counter_ok_allocation = 100;

    t_vector vec{1, 2, 3, 4, 5};
    vec.reserve(6); // only one alaliable space for insertion.
    auto origin_size = vec.size();

    std::int32_t                 a[] = {11, 12, 13, 14, 15};
    ::portable_stl::size_t const N   = sizeof(a) / sizeof(a[0]);

    TestAlloc::m_counter_ok_allocation = 0;
    auto result                        = vec.insert(vec.cbegin() + 3,
                             test_iterator_helper::tst_input_iterator<std::int32_t const *>(a),
                             test_iterator_helper::tst_input_iterator<std::int32_t const *>(a + N));

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // Check vector invariant: strong guarantee
    ASSERT_EQ(origin_size, vec.size());
    for (t_vector::size_type i{0U}; i < vec.size(); ++i) {
      EXPECT_EQ(i + 1, vec[i]);
    }
  }

  // Bad allocation at reserve
  {
    /**
     * @brief Type with lmitations.
     */
    using TestAlloc                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    /**
     * @brief Test vector type.
     */
    using t_vector                     = ::portable_stl::vector<std::int32_t, TestAlloc>;
    TestAlloc::m_counter_ok_allocation = 100;

    t_vector vec{1, 2, 3, 4, 5};
    vec.reserve(6); // only one alaliable space for insertion.
    auto origin_size = vec.size();

    std::int32_t                 a[] = {11, 12, 13, 14, 15};
    ::portable_stl::size_t const N   = sizeof(a) / sizeof(a[0]);

    TestAlloc::m_counter_ok_allocation = 1;
    auto result                        = vec.insert(vec.cbegin() + 3,
                             test_iterator_helper::tst_input_iterator<std::int32_t const *>(a),
                             test_iterator_helper::tst_input_iterator<std::int32_t const *>(a + N));

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // Check vector invariant: strong guarantee
    ASSERT_EQ(origin_size, vec.size());
    for (t_vector::size_type i{0U}; i < vec.size(); ++i) {
      EXPECT_EQ(i + 1, vec[i]);
    }
  }
}

TEST(vector, insert_iter_iter_iter_forward_iterators) {
  static_cast<void>(test_info_);

  // Reallocation expected
  {
    /**
     * @brief Vector alias.
     */
    using t_vector = ::portable_stl::vector<std::int32_t>;
    t_vector vec(100U);
    while (vec.size() < vec.capacity()) {
      vec.push_back(0); // force reallocation
    }
    std::int32_t                 a[]    = {1, 2, 3, 4, 5};
    ::portable_stl::size_t const N      = sizeof(a) / sizeof(a[0]);
    auto                         result = vec.insert(vec.cbegin() + 10,
                             test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a),
                             test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a + N));
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(100U + N, vec.size());
    EXPECT_EQ(vec.begin() + 10, it);

    ::portable_stl::size_t j{0U};
    for (; j < 10U; ++j) {
      EXPECT_EQ(0, vec[j]);
    }
    for (::portable_stl::size_t k{0U}; k < N; ++j, ++k) {
      EXPECT_EQ(vec[j], a[k]);
    }
    for (; j < 105U; ++j) {
      EXPECT_EQ(0, vec[j]);
    }
  }

  // No reallocation expected
  {
    /**
     * @brief Vector alias.
     */
    using t_vector = ::portable_stl::vector<std::int32_t>;
    t_vector vec(100);
    vec.reserve(120);
    std::int32_t                 a[]    = {1, 2, 3, 4, 5};
    ::portable_stl::size_t const N      = sizeof(a) / sizeof(a[0]);
    auto                         result = vec.insert(vec.cbegin() + 10,
                             test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a),
                             test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a + N));
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(100U + N, vec.size());
    EXPECT_EQ(vec.begin() + 10, it);

    ::portable_stl::size_t j{0U};
    for (; j < 10U; ++j) {
      EXPECT_EQ(0, vec[j]);
    }
    for (::portable_stl::size_t k{0U}; k < N; ++j, ++k) {
      EXPECT_EQ(vec[j], a[k]);
    }
    for (; j < 105U; ++j) {
      EXPECT_EQ(0, vec[j]);
    }
  }

  // Bad construction at available memory (end..end_cap)
  {
    /**
     * @brief Type with lmitations.
     */
    using t_type   = test_vector_helper::ThrowSometime;
    /**
     * @brief Test vector type.
     */
    using t_vector = ::portable_stl::vector<t_type>;

    t_type::setThrowOnConstruction(100);
    t_vector vec{t_type(1), t_type(2), t_type(3), t_type(4), t_type(5)};
    vec.reserve(10);
    auto origin_size = vec.size();

    t_type             a[] = {t_type(6), t_type(7), t_type(8), t_type(9)};
    std::int32_t const N   = sizeof(a) / sizeof(a[0]);

    t_type::setThrowOnConstruction(2);
    try {
      static_cast<void>(vec.insert(vec.cbegin() + 3,
                                   test_iterator_helper::tst_forward_iterator<t_type const *>(a),
                                   test_iterator_helper::tst_forward_iterator<t_type const *>(a + N)));
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check vector invariant: basic guarantee
    ASSERT_EQ(origin_size, vec.size());
    for (::portable_stl::vector<t_type>::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(i + 1, vec[i].getData());
    }
    EXPECT_EQ(t_type::m_construct_count, t_type::m_destruct_count);
  }

  // Bad construction at temporary buffer
  {
    /**
     * @brief Type with lmitations.
     */
    using t_type   = test_vector_helper::ThrowSometime;
    /**
     * @brief Test vector type.
     */
    using t_vector = ::portable_stl::vector<t_type>;

    t_type::setThrowOnConstruction(100);
    t_vector vec{t_type(1), t_type(2), t_type(3), t_type(4), t_type(5)};
    vec.reserve(6); // only one alaliable space for insertion.
    auto origin_size = vec.size();

    t_type             a[] = {t_type(11), t_type(12), t_type(13), t_type(14), t_type(15)};
    std::int32_t const N   = sizeof(a) / sizeof(a[0]);

    t_type::setThrowOnConstruction(3);
    try {
      static_cast<void>(vec.insert(vec.cbegin() + 3,
                                   test_iterator_helper::tst_forward_iterator<t_type const *>(a),
                                   test_iterator_helper::tst_forward_iterator<t_type const *>(a + N)));
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check vector invariant: strong guarantee
    ASSERT_EQ(origin_size, vec.size());
    for (::portable_stl::vector<t_type>::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(i + 1, vec[i].getData());
    }
    EXPECT_EQ(t_type::m_construct_count, t_type::m_destruct_count);
  }

  // Bad allocation of a temporary buffer
  {
    /**
     * @brief Type with lmitations.
     */
    using TestAlloc                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    /**
     * @brief Test vector type.
     */
    using t_vector                     = ::portable_stl::vector<std::int32_t, TestAlloc>;
    TestAlloc::m_counter_ok_allocation = 100;

    t_vector vec{1, 2, 3, 4, 5};
    vec.reserve(6); // only one alaliable space for insertion.
    auto origin_size = vec.size();

    std::int32_t       a[] = {11, 12, 13, 14, 15};
    std::int32_t const N   = sizeof(a) / sizeof(a[0]);

    TestAlloc::m_counter_ok_allocation = 0;
    auto result                        = vec.insert(vec.cbegin() + 3,
                             test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a),
                             test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a + N));

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // Check vector invariant: strong guarantee
    ASSERT_EQ(origin_size, vec.size());
    for (t_vector::size_type i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(i + 1, vec[i]);
    }
  }

  // max_size reaching
  {
    /**
     * @brief Allocator with limitations.
     */
    using TestAlloc = ::test_allocator_helper::TestSimpleAllocator<std::int32_t>;

    TestAlloc::m_counter_ok_allocation = 100;
    TestAlloc::m_max_size              = 9;
    ::portable_stl::vector<std::int32_t, TestAlloc>                  vec(5);
    ::portable_stl::vector<std::int32_t, TestAlloc>::size_type const sz{vec.size()};

    std::int32_t       a[]    = {11, 12, 13, 14, 15};
    std::int32_t const N      = sizeof(a) / sizeof(a[0]);
    auto               result = vec.insert(vec.cbegin() + 3,
                             test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a),
                             test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a + N));

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

TEST(vector, insert_initializer_list) {
  static_cast<void>(test_info_);

  {
    /**
     * @brief Vector alias.
     */
    using t_vector = ::portable_stl::vector<std::int32_t>;
    t_vector vec(100);
    while (vec.size() < vec.capacity()) {
      vec.push_back(0); // force reallocation
    }
    std::int32_t const N{5};

    auto result = vec.insert(vec.cbegin() + 10, {1, 2, 3, 4, 5});
    ASSERT_TRUE(result);

    auto it = result.value();
    EXPECT_EQ(100 + N, vec.size());
    EXPECT_EQ(vec.begin() + 10, it);

    decltype(vec.size()) j{0};
    for (; j < 10; ++j) {
      EXPECT_EQ(0, vec[j]);
    }
    for (std::size_t k = 0; k < N; ++j, ++k) {
      EXPECT_EQ(vec[j], k + 1);
    }
    for (; j < vec.size(); ++j) {
      EXPECT_EQ(0, vec[j]);
    }
  }
}

namespace test_vector_helper {
class A {
  std::int32_t m_int;
  double       m_double;

public:
  A(std::int32_t i, double d) noexcept : m_int(i), m_double(d) {
  }

  A(A const &) = delete;

  A(A &&a) noexcept : m_int(a.m_int), m_double(a.m_double) {
    a.m_int    = 0;
    a.m_double = 0;
  }

  A &operator=(A const &) = delete;

  A &operator=(A &&a) noexcept {
    m_int      = a.m_int;
    m_double   = a.m_double;
    a.m_int    = 0;
    a.m_double = 0;
    return *this;
  }

  std::int32_t get_int() const noexcept {
    return m_int;
  }
  double get_double() const noexcept {
    return m_double;
  }
};
} // namespace test_vector_helper

TEST(vector, emplace) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::vector<test_vector_helper::A> vec;

    auto result = vec.emplace(vec.cbegin(), 2, 3.5);
    ASSERT_TRUE(result);
    auto it = result.value();
    EXPECT_EQ(vec.begin(), it);
    EXPECT_EQ(1, vec.size());

    EXPECT_EQ(2, vec.front().get_int());
    EXPECT_EQ(3.5, vec.front().get_double());

    result = vec.emplace(vec.cend(), 3, 4.5);
    it     = result.value();
    EXPECT_EQ(vec.end() - 1, it);
    EXPECT_EQ(2, vec.size());

    EXPECT_EQ(2, vec.front().get_int());
    EXPECT_EQ(3.5, vec.front().get_double());

    EXPECT_EQ(3, vec.back().get_int());
    EXPECT_EQ(4.5, vec.back().get_double());

    result = vec.emplace(vec.cbegin() + 1, 4, 6.5);
    it     = result.value();
    EXPECT_EQ(vec.begin() + 1, it);
    EXPECT_EQ(3, vec.size());

    EXPECT_EQ(2, vec.front().get_int());
    EXPECT_EQ(3.5, vec.front().get_double());

    EXPECT_EQ(4, vec[1].get_int());
    EXPECT_EQ(6.5, vec[1].get_double());

    EXPECT_EQ(3, vec.back().get_int());
    EXPECT_EQ(4.5, vec.back().get_double());

    vec.reserve(4);
    result = vec.emplace(vec.cbegin() + 1, 5, 7.5);
    it     = result.value();
    EXPECT_EQ(vec.begin() + 1, it);
    EXPECT_EQ(4, vec.size());

    EXPECT_EQ(2, vec.front().get_int());
    EXPECT_EQ(3.5, vec.front().get_double());

    EXPECT_EQ(5, vec[1].get_int());
    EXPECT_EQ(7.5, vec[1].get_double());

    EXPECT_EQ(4, vec[2].get_int());
    EXPECT_EQ(6.5, vec[2].get_double());

    EXPECT_EQ(3, vec.back().get_int());
    EXPECT_EQ(4.5, vec.back().get_double());
  }

  // bad construction at the end
  {
    /**
     * @brief Type with lmitations.
     */
    using t_type   = test_vector_helper::ThrowSometime;
    /**
     * @brief Test vector type.
     */
    using t_vector = ::portable_stl::vector<t_type>;

    t_type::setThrowOnConstruction(100);
    t_vector vec{3, t_type(3)};
    vec.reserve(5);
    auto original_size = vec.size();

    t_type::setThrowOnConstruction(1);
    try {
      static_cast<void>(vec.emplace(vec.end(), 7));
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check invariant: strong guarantee
    EXPECT_EQ(original_size, vec.size());
    for (decltype(original_size) i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(3, vec[i].getData());
    }
  }

  // bad construction of the temp value
  {
    /**
     * @brief Type with lmitations.
     */
    using t_type   = test_vector_helper::ThrowSometime;
    /**
     * @brief Test vector type.
     */
    using t_vector = ::portable_stl::vector<t_type>;

    t_type::setThrowOnConstruction(100);
    t_vector vec{3, t_type(3)};
    vec.reserve(5);
    auto original_size = vec.size();

    t_type::setThrowOnConstruction(1);
    try {
      auto result = vec.emplace(vec.begin() + 1, 7);
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check invariant: strong guarantee
    EXPECT_EQ(original_size, vec.size());
    for (decltype(original_size) i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(3, vec[i].getData());
    }
  }

  // bad construction in the temp buffer
  {
    /**
     * @brief Type with lmitations.
     */
    using t_type   = test_vector_helper::ThrowSometime;
    /**
     * @brief Test vector type.
     */
    using t_vector = ::portable_stl::vector<t_type>;

    t_type::setThrowOnConstruction(100);
    t_vector vec{3, t_type(3)};
    auto     original_size = vec.size();

    t_type::setThrowOnConstruction(1);
    try {
      auto result = vec.emplace(vec.begin() + 1, 7);
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check invariant: strong guarantee
    EXPECT_EQ(original_size, vec.size());
    for (decltype(original_size) i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(3, vec[i].getData());
    }
  }

  // bad temp buffer allocation
  {
    /**
     * @brief Type with lmitations.
     */
    using TestAlloc = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    /**
     * @brief Test vector type.
     */
    using t_vector  = ::portable_stl::vector<std::int32_t, TestAlloc>;

    TestAlloc::m_counter_ok_allocation = 100;
    t_vector vec{3, 3};
    auto     original_size = vec.size();

    TestAlloc::m_counter_ok_allocation = 0;
    auto result                        = vec.emplace(vec.begin() + 1, 7);

    ASSERT_FALSE(result);

    // Check invariant: strong guarantee
    EXPECT_EQ(original_size, vec.size());
    for (decltype(original_size) i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(3, vec[i]);
    }
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

    auto result = vec.emplace(vec.begin() + 1, 7);

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
