// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="vector_bool.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "portable_stl/vector/vector_bool.h"
#include "../common/test_allocator.h"
#include "../common/test_comparisons.h"
#include "vector_test_helper.h"
/**
 * @brief Test allocator alias
 */
using TestBoolSimpleAlloc = test_allocator_helper::TestSimpleAllocator<bool>;

/**
 * @brief Storage allocator for vecor<bool>
 */
using TestUIntSimpleAlloc = test_allocator_helper::TestSimpleAllocator<::portable_stl::vector<bool>::t_storage_type>;

TEST(vector_bool, element_access) {
  static_cast<void>(test_info_);

  /**
   * @brief Vector alias.
   */
  using t_vector = ::portable_stl::vector<bool>;

  {
    t_vector vec{true, false, false};
    vec.push_back(true);

    EXPECT_EQ(true, vec[3]);
    EXPECT_EQ(true, vec.back());
    EXPECT_EQ(true, vec.front());
    EXPECT_EQ(true, vec.at(3).value());

    auto result = vec.at(vec.size());
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }

  {
    t_vector const vec{true, false, false, true};

    EXPECT_EQ(true, vec[3]);
    EXPECT_EQ(true, vec.back());
    EXPECT_EQ(true, vec.front());
    EXPECT_EQ(true, vec.at(3).value());

    auto result = vec.at(vec.size());
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());
  }

  {
    t_vector        vec;
    t_vector const &const_vec = vec;
    EXPECT_TRUE((std::is_same<typename t_vector::reference, decltype(vec[0])>{}));
    EXPECT_TRUE((std::is_same<typename t_vector::const_reference, decltype(const_vec[0])>{}));

    EXPECT_TRUE((std::is_same<typename t_vector::reference, ::std::remove_reference_t<decltype(vec.at(0).value())>>{}));
    EXPECT_TRUE((std::is_same<typename t_vector::const_reference,
                              ::std::remove_reference_t<decltype(const_vec.at(0).value())>>{}));

    EXPECT_TRUE((std::is_same<typename t_vector::reference, decltype(vec.front())>{}));
    EXPECT_TRUE((std::is_same<typename t_vector::const_reference, decltype(const_vec.front())>{}));

    EXPECT_TRUE((std::is_same<typename t_vector::reference, decltype(vec.back())>{}));
    EXPECT_TRUE((std::is_same<typename t_vector::const_reference, decltype(const_vec.back())>{}));
  }
}

// [capacity]

TEST(vector_bool, resize) {
  static_cast<void>(test_info_);

  /**
   * @brief Vector size alias.
   */
  using t_size = ::portable_stl::vector<bool>::size_type;

  ::portable_stl::size_t min_cap = 8 * sizeof(::portable_stl::vector<bool>::t_storage_type);

  {
    ::portable_stl::vector<bool> vec(100);
    EXPECT_TRUE(vec.resize(50));

    EXPECT_EQ(50, vec.size());
    EXPECT_GE(vec.capacity(), 100);

    EXPECT_TRUE(vec.resize(200));

    EXPECT_EQ(200, vec.size());
    EXPECT_GE(vec.capacity(), 200);
  }

  {
    ::portable_stl::vector<bool> vec(3);

    auto result = vec.resize(10, true);
    ASSERT_TRUE(result);
    EXPECT_EQ(10, vec.size());

    size_t i{0};
    for (; i < 3; ++i) {
      EXPECT_EQ(false, vec[i]);
    }
    for (; i < vec.size(); ++i) {
      EXPECT_EQ(true, vec[i]);
    }
  }

  // Bad allocation of the temp buffer for new elements
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(min_cap - 1);
    t_size const                                      old_cap{vec.capacity()};
    t_size const                                      old_size{vec.size()};

    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;
    auto result                                  = vec.resize(2 * min_cap + 1);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    // check invariant
    EXPECT_EQ(old_cap, vec.capacity());
    EXPECT_EQ(old_size, vec.size());

    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
  }

  // max_size reaching
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(min_cap - 1);
    t_size const                                      old_cap{vec.capacity()};
    t_size const                                      old_size{vec.size()};

    TestUIntSimpleAlloc::m_max_size = 1;
    auto result                     = vec.resize(2 * min_cap + 1);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    // Check invariant: strong guarantee
    EXPECT_EQ(old_cap, vec.capacity());
    EXPECT_EQ(old_size, vec.size());

    TestUIntSimpleAlloc::m_max_size = 10000;
  }

  // reserve max_size
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(4 * min_cap);
    t_size const                                      old_size{vec.size()};
    t_size const                                      limit_cap{5 * min_cap};

    TestUIntSimpleAlloc::m_max_size = limit_cap / min_cap;
    auto result                     = vec.push_back(true);
    TestUIntSimpleAlloc::m_max_size = 10000;

    ASSERT_TRUE(result);

    EXPECT_EQ(limit_cap, vec.capacity());
    EXPECT_EQ(old_size + 1, vec.size());
  }
}

TEST(vector_bool, capacity) {
  static_cast<void>(test_info_);

  ::portable_stl::size_t min_cap = 8 * sizeof(::portable_stl::vector<bool>::t_storage_type);

  {
    ::portable_stl::vector<bool> vec;
    EXPECT_TRUE(noexcept(vec.capacity()));
    ASSERT_EQ(0, vec.capacity());
  }
  {
    ::portable_stl::vector<bool> vec(3 * min_cap);
    ASSERT_EQ(3 * min_cap, vec.capacity());

    vec.push_back(true);
    ASSERT_GE(vec.capacity(), 3 * min_cap);
  }
}

TEST(vector_bool, reserve) {
  static_cast<void>(test_info_);

  ::portable_stl::size_t min_cap = 8 * sizeof(::portable_stl::vector<bool>::t_storage_type);

  {
    ::portable_stl::vector<bool> vec;
    ASSERT_TRUE(vec.reserve(10));
    EXPECT_GE(vec.capacity(), min_cap);
  }
  {
    ::portable_stl::vector<bool> vec(2 * min_cap);
    EXPECT_EQ(2 * min_cap, vec.capacity());

    ASSERT_TRUE(vec.reserve(min_cap));
    EXPECT_EQ(2 * min_cap, vec.size());
    EXPECT_EQ(2 * min_cap, vec.capacity());

    ASSERT_TRUE(vec.reserve(3 * min_cap));
    EXPECT_EQ(2 * min_cap, vec.size());
    EXPECT_EQ(3 * min_cap, vec.capacity());
  }

  // Bad allocation
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(min_cap);

    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;
    auto result                                  = vec.reserve(2 * min_cap);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    ASSERT_EQ(min_cap, vec.capacity());
    ASSERT_EQ(min_cap, vec.size());
  }

  // Max size
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec;

    TestUIntSimpleAlloc::m_max_size = 1;
    auto result                     = vec.reserve(vec.max_size() + 1);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());
    ASSERT_EQ(0, vec.capacity());
    ASSERT_EQ(0, vec.size());

    TestUIntSimpleAlloc::m_max_size = 10000;
  }
}

TEST(vector_bool, size) {
  static_cast<void>(test_info_);

  ::portable_stl::vector<bool> vec;

  EXPECT_TRUE(noexcept(vec.size()));
  ASSERT_EQ(0, vec.size());

  vec.push_back(0);
  ASSERT_EQ(1, vec.size());

  vec.push_back(0);
  ASSERT_EQ(2, vec.size());

  vec.push_back(0);
  ASSERT_EQ(3, vec.size());

  vec.erase(vec.begin());
  ASSERT_EQ(2, vec.size());

  vec.erase(vec.begin());
  ASSERT_EQ(1, vec.size());

  vec.erase(vec.begin());
  ASSERT_EQ(0, vec.size());
}

TEST(vector_bool, shrink_to_fit) {
  static_cast<void>(test_info_);

  ::portable_stl::size_t min_cap = 8 * sizeof(::portable_stl::vector<bool>::t_storage_type);

  {
    ::portable_stl::vector<bool> vec(2 * min_cap + 1);
    vec.pop_back();
    vec.pop_back();

    EXPECT_EQ(vec.capacity(), 3 * min_cap);
    ASSERT_EQ(2 * min_cap - 1, vec.size());

    EXPECT_TRUE(vec.shrink_to_fit());

    EXPECT_GT(vec.capacity(), 2 * min_cap);
    ASSERT_EQ(2 * min_cap - 1, vec.size());
  }
}

TEST(vector_bool, swap) {
  static_cast<void>(test_info_);

  {
    bool                         a1[] = {true, false, true, false};
    bool                         a2[] = {false, true, false, true};
    ::portable_stl::vector<bool> vec1(a1, a1 + sizeof(a1) / sizeof(a1[0]));
    ::portable_stl::vector<bool> vec2(a2, a2 + sizeof(a2) / sizeof(a2[0]));

    swap(vec1, vec2);

    ASSERT_EQ(::portable_stl::vector<bool>(a2, a2 + sizeof(a2) / sizeof(a2[0])), vec1);
    ASSERT_EQ(::portable_stl::vector<bool>(a1, a1 + sizeof(a1) / sizeof(a1[0])), vec2);
  }
  {
    bool                         a1[] = {true};
    bool                         a2[] = {false, true, false, true, false, true, false, true, false, true};
    ::portable_stl::vector<bool> vec1(a1, a1);
    ::portable_stl::vector<bool> vec2(a2, a2 + sizeof(a2) / sizeof(a2[0]));

    swap(vec1, vec2);

    ASSERT_EQ(::portable_stl::vector<bool>(a2, a2 + sizeof(a2) / sizeof(a2[0])), vec1);
    ASSERT_TRUE(vec2.empty());
    ASSERT_EQ(0, ::portable_stl::distance(vec2.begin(), vec2.end()));
  }
  {
    bool                         a1[] = {false, true, false, true, false, true, false, true, false, true};
    bool                         a2[] = {true};
    ::portable_stl::vector<bool> vec1(a1, a1 + sizeof(a1) / sizeof(a1[0]));
    ::portable_stl::vector<bool> vec2(a2, a2);

    swap(vec1, vec2);

    ASSERT_TRUE(vec1.empty());
    ASSERT_EQ(0, ::portable_stl::distance(vec1.begin(), vec1.end()));
    ASSERT_EQ(::portable_stl::vector<bool>(a1, a1 + sizeof(a1) / sizeof(a1[0])), vec2);
  }
  {
    bool                         a1[] = {true};
    bool                         a2[] = {false};
    ::portable_stl::vector<bool> vec1(a1, a1);
    ::portable_stl::vector<bool> vec2(a2, a2);

    swap(vec1, vec2);

    ASSERT_TRUE(vec1.empty());
    ASSERT_EQ(0, ::portable_stl::distance(vec1.begin(), vec1.end()));
    ASSERT_TRUE(vec2.empty());
    ASSERT_EQ(0, ::portable_stl::distance(vec2.begin(), vec2.end()));
  }
}

// [compare]

TEST(vector_bool, compare) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::vector<bool> const vec1;
    ::portable_stl::vector<bool> const vec2;
    ASSERT_TRUE(test_common_helper::testComparisons(vec1, vec2, true, false));
  }
  {
    ::portable_stl::vector<bool> const vec1(true);
    ::portable_stl::vector<bool> const vec2(true);
    ASSERT_TRUE(test_common_helper::testComparisons(vec1, vec2, true, false));
  }
  {
    ::portable_stl::vector<bool> const vec1(false);
    ::portable_stl::vector<bool> const vec2(true);
    ASSERT_TRUE(test_common_helper::testComparisons(vec1, vec2, false, true));
  }
  {
    ::portable_stl::vector<bool> const vec1;
    ::portable_stl::vector<bool> const vec2(true);
    ASSERT_TRUE(test_common_helper::testComparisons(vec1, vec2, false, true));
  }
  {
    ::portable_stl::vector<bool> const vec1{false, true, false};
    ::portable_stl::vector<bool> const vec2{false, true, true};
    ASSERT_TRUE(test_common_helper::testComparisons(vec1, vec2, false, true));
  }
  {
    ::portable_stl::vector<bool> const vec1{false, false, false};
    ::portable_stl::vector<bool> const vec2{false, true, false};
    ASSERT_TRUE(test_common_helper::testComparisons(vec1, vec2, false, true));
  }
  {
    ::portable_stl::vector<bool> const vec1{false, true};
    ::portable_stl::vector<bool> const vec2{false, true, false};
    ASSERT_TRUE(test_common_helper::testComparisons(vec1, vec2, false, true));
  }
  {
    ::portable_stl::vector<bool> const vec1{false, true, false};
    ::portable_stl::vector<bool> const vec2{true};
    ASSERT_TRUE(test_common_helper::testComparisons(vec1, vec2, false, true));
  }
  {
    ASSERT_TRUE((::portable_stl::vector<bool>() == ::portable_stl::vector<bool>()));
    ASSERT_FALSE((::portable_stl::vector<bool>() != ::portable_stl::vector<bool>()));
    ASSERT_FALSE((::portable_stl::vector<bool>() < ::portable_stl::vector<bool>()));
    ASSERT_TRUE((::portable_stl::vector<bool>() <= ::portable_stl::vector<bool>()));
    ASSERT_FALSE((::portable_stl::vector<bool>() > ::portable_stl::vector<bool>()));
    ASSERT_TRUE((::portable_stl::vector<bool>() >= ::portable_stl::vector<bool>()));
  }
}
