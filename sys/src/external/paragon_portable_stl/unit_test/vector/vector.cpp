// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="vector.cpp"
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
#include "portable_stl/memory/addressof.h"
#include "portable_stl/vector/vector.h"
#include "vector_test_helper.h"

// [element access]

namespace test_vector_helper {
template<class t_vector> t_vector make(::portable_stl::size_t size, typename t_vector::value_type start) {
  /**
   * @brief Alias.
   */
  using t_value = typename t_vector::value_type;

  t_vector vec;
  for (::portable_stl::size_t i{0U}; i < size; ++i) {
    vec.push_back(start + static_cast<t_value>(i));
  }
  return vec;
}

template<class t_vector> void test_get_basic(t_vector &vec, typename t_vector::value_type start_value) {
  /**
   * @brief Alias.
   */
  using t_value = typename t_vector::value_type;

  ::portable_stl::size_t const num = vec.size();

  for (::portable_stl::size_t i{0U}; i < num; ++i) {
    EXPECT_EQ(start_value + static_cast<t_value>(i), vec[i]);
  }

  for (::portable_stl::size_t i{0U}; i < num; ++i) {
    EXPECT_EQ(start_value + static_cast<t_value>(i), vec.at(i).value());
  }

  auto result = vec.at(num);
  ASSERT_FALSE(result);
  EXPECT_EQ(::portable_stl::portable_stl_error::out_of_range, result.error());

  EXPECT_EQ(start_value, vec.front());
  EXPECT_EQ(start_value + static_cast<t_value>(num - 1U), vec.back());
}

template<class t_vector> void test_get() {
  typename t_vector::value_type const start_value = 35;
  t_vector           vec{make<t_vector>(10U, start_value)};
  t_vector const    &const_vec{vec};
  test_get_basic(vec, start_value);
  test_get_basic(const_vec, start_value);
}

template<class t_vector> void test_set() {
  /**
   * @brief Alias.
   */
  using t_value = typename t_vector::value_type;

  t_value const                start_value{35};
  ::portable_stl::size_t const num{10};
  t_vector                     vec{make<t_vector>(num, start_value)};

  for (::portable_stl::size_t i{0U}; i < num; ++i) {
    EXPECT_EQ(start_value + static_cast<t_value>(i), vec[i]);
    vec[i] = start_value + static_cast<t_value>(i + 1);
    EXPECT_EQ(start_value + static_cast<t_value>(i + 1), vec[i]);
  }

  for (::portable_stl::size_t i{0U}; i < num; ++i) {
    EXPECT_EQ(start_value + static_cast<t_value>(i + 1), vec.at(i).value());
    vec.at(i).value().get() = start_value + static_cast<t_value>(i + 2);
    EXPECT_EQ(start_value + static_cast<t_value>(i + 2), vec.at(i).value());
  }

  EXPECT_EQ(start_value + 2, vec.front());
  vec.front() = start_value + 3;
  EXPECT_EQ(start_value + 3, vec.front());

  EXPECT_EQ(start_value + static_cast<t_value>(num + 1), vec.back());
  vec.back() = start_value + static_cast<t_value>(num + 2);
  EXPECT_EQ(start_value + static_cast<t_value>(num + 2), vec.back());
}
} // namespace test_vector_helper

TEST(vector, element_access) {
  static_cast<void>(test_info_);

  /**
   * @brief Test vector alias.
   */
  using t_vector = ::portable_stl::vector<std::int32_t>;

  test_vector_helper::test_get<t_vector>();
  test_vector_helper::test_set<t_vector>();

  t_vector        vec;
  t_vector const &const_vec = vec;
  EXPECT_TRUE((std::is_same<typename t_vector::reference, decltype(vec[0])>{}));
  EXPECT_TRUE((std::is_same<typename t_vector::const_reference, decltype(const_vec[0])>{}));

  EXPECT_TRUE((std::is_same<typename t_vector::reference, decltype(vec.at(0).value().get())>{}));
  EXPECT_TRUE((std::is_same<typename t_vector::const_reference, decltype(const_vec.at(0).value().get())>{}));

  EXPECT_TRUE((std::is_same<typename t_vector::reference, decltype(vec.front())>{}));
  EXPECT_TRUE((std::is_same<typename t_vector::const_reference, decltype(const_vec.front())>{}));

  EXPECT_TRUE((std::is_same<typename t_vector::reference, decltype(vec.back())>{}));
  EXPECT_TRUE((std::is_same<typename t_vector::const_reference, decltype(const_vec.back())>{}));
}

namespace test_vector_helper {
class Nasty final {
  std::int32_t m_data;

public:
  Nasty() noexcept : m_data(0) {
  }
  Nasty(std::int32_t value) noexcept : m_data(value) {
  }
  ~Nasty() {
    m_data = 0;
  }

  Nasty *operator&() const {
    assert(false);
    return nullptr;
  }
};
} // namespace test_vector_helper

TEST(vector, data) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::vector<std::int32_t> vec;
    EXPECT_EQ(0, vec.data());
  }
  {
    ::portable_stl::vector<std::int32_t> vec(100);
    EXPECT_EQ(::portable_stl::addressof(vec.front()), vec.data());
  }
  {
    ::portable_stl::vector<test_vector_helper::Nasty> vec(100);
    assert(vec.data() == ::portable_stl::addressof(vec.front()));
  }
}

TEST(vector, data_const) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::vector<std::int32_t> const vec;
    EXPECT_EQ(0, vec.data());
  }
  {
    ::portable_stl::vector<std::int32_t> const vec(100);
    EXPECT_EQ(::portable_stl::addressof(vec.front()), vec.data());
  }
  {
    ::portable_stl::vector<test_vector_helper::Nasty> const vec(100);
    assert(vec.data() == ::portable_stl::addressof(vec.front()));
  }
}

// [capacity]

TEST(vector, resize) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::vector<std::int32_t> vec(100);
    EXPECT_TRUE(vec.resize(50));

    EXPECT_EQ(50, vec.size());
    EXPECT_EQ(100, vec.capacity());

    EXPECT_TRUE(vec.resize(200));

    EXPECT_EQ(200, vec.size());
    EXPECT_GE(vec.capacity(), 200);
  }

  {
    ::portable_stl::vector<test_common_helper::MoveOnly> vec(100);
    EXPECT_TRUE(vec.resize(50));

    EXPECT_EQ(50, vec.size());
    EXPECT_EQ(100, vec.capacity());

    EXPECT_TRUE(vec.resize(200));

    EXPECT_EQ(200, vec.size());
    EXPECT_GE(vec.capacity(), 200);
  }

  {
    ::portable_stl::vector<test_common_helper::MoveOnly> vec(70);
    vec.reserve(200);

    EXPECT_TRUE(vec.resize(150));

    EXPECT_EQ(150, vec.size());
    EXPECT_EQ(200, vec.capacity());
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
    t_vector vec(50);
    auto     original_size = vec.size();

    TestAlloc::m_counter_ok_allocation = 0;
    auto result                        = vec.resize(100);

    ASSERT_FALSE(result);

    // Check invariant: strong guarantee
    EXPECT_EQ(original_size, vec.size());
  }

  // bad construction
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
    t_vector vec{50, t_type(3)};
    auto     original_size = vec.size();

    t_type::setThrowOnConstruction(1);
    try {
      auto result = vec.resize(70);
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check invariant: strong guarantee
    EXPECT_EQ(original_size, vec.size());
  }

  // max_size reaching
  {
    /**
     * @brief Allocator with limitations.
     */
    using TestAlloc = ::test_allocator_helper::TestSimpleAllocator<std::int32_t>;

    TestAlloc::m_counter_ok_allocation = 100;
    TestAlloc::m_max_size              = 6;
    ::portable_stl::vector<std::int32_t, TestAlloc>                  vec(5);
    ::portable_stl::vector<std::int32_t, TestAlloc>::size_type const sz{vec.size()};

    auto result = vec.resize(7);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    // Check invariant: strong guarantee
    EXPECT_EQ(sz, vec.size());

    TestAlloc::m_max_size = 10000;
  }
}

TEST(vector, resize_value) {
  static_cast<void>(test_info_);

  /**
   * @brief Size type.
   */
  using size_type1 = ::portable_stl::vector<std::int32_t>::size_type;
  {
    ::portable_stl::vector<std::int32_t> vec(100);
    EXPECT_TRUE(vec.resize(50, 1));

    EXPECT_EQ(50, vec.size());
    EXPECT_EQ(100, vec.capacity());
    for (size_type1 i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(std::int32_t(), vec[i]);
    }

    EXPECT_TRUE(vec.resize(200, 1));

    EXPECT_EQ(200, vec.size());
    EXPECT_GE(vec.capacity(), 200);

    size_type1 i{0};
    for (; i < 50; ++i) {
      EXPECT_EQ(std::int32_t(), vec[i]);
    }
    for (; i < vec.size(); ++i) {
      EXPECT_EQ(1, vec[i]);
    }
  }

  {
    ::portable_stl::vector<std::int32_t> vec(70);
    vec.reserve(200);

    EXPECT_TRUE(vec.resize(150, 1));

    EXPECT_EQ(150, vec.size());
    EXPECT_EQ(200, vec.capacity());
    size_type1 i{0};
    for (; i < 70; ++i) {
      EXPECT_EQ(std::int32_t(), vec[i]);
    }
    for (; i < vec.size(); ++i) {
      EXPECT_EQ(1, vec[i]);
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
    t_vector vec(50);
    auto     original_size = vec.size();

    TestAlloc::m_counter_ok_allocation = 0;
    auto result                        = vec.resize(100, 1);

    ASSERT_FALSE(result);

    // Check invariant: strong guarantee
    EXPECT_EQ(original_size, vec.size());
  }

  // bad construction
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
    t_type   value(7);
    t_vector vec{50, t_type(3)};
    auto     original_size = vec.size();

    t_type::setThrowOnConstruction(1);
    try {
      auto result = vec.resize(70, value);
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // Check invariant: strong guarantee
    EXPECT_EQ(original_size, vec.size());
  }

  // max_size reaching
  {
    /**
     * @brief Allocator with limitations.
     */
    using TestAlloc = ::test_allocator_helper::TestSimpleAllocator<std::int32_t>;

    TestAlloc::m_counter_ok_allocation = 100;
    TestAlloc::m_max_size              = 6;
    ::portable_stl::vector<std::int32_t, TestAlloc>                  vec(5);
    ::portable_stl::vector<std::int32_t, TestAlloc>::size_type const sz{vec.size()};

    auto result = vec.resize(7, 1);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    // Check invariant: strong guarantee
    EXPECT_EQ(sz, vec.size());

    TestAlloc::m_max_size = 10000;
  }
}

TEST(vector, empty) {
  static_cast<void>(test_info_);

  ::portable_stl::vector<std::int32_t> vec;
  ASSERT_TRUE(vec.empty());

  vec.push_back(::portable_stl::vector<std::int32_t>::value_type(1));
  ASSERT_FALSE(vec.empty());

  vec.clear();
  ASSERT_TRUE(vec.empty());
}

TEST(vector, capacity) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::vector<std::int32_t> vec;
    EXPECT_TRUE(noexcept(vec.capacity()));
    ASSERT_EQ(0, vec.capacity());
  }
  {
    ::portable_stl::vector<std::int32_t> vec(100);
    ASSERT_EQ(100, vec.capacity());

    vec.push_back(0);
    ASSERT_GE(vec.capacity(), 101);
  }
  {
    /**
     * @brief Allocator with limitations.
     */
    using TestAlloc                    = ::test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAlloc::m_counter_ok_allocation = 100;
    TestAlloc::m_max_size              = 10;
    ::portable_stl::vector<std::int32_t, TestAlloc> vec(4);
    vec.reserve(6);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);

    EXPECT_EQ(TestAlloc::m_max_size, vec.capacity()); // not 6*2=12
    EXPECT_EQ(7, vec.size());

    TestAlloc::m_max_size = 10000;
  }
}

TEST(vector, reserve) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::vector<std::int32_t> vec;
    ASSERT_TRUE(vec.reserve(10));
    EXPECT_GE(vec.capacity(), 10);
  }
  {
    ::portable_stl::vector<std::int32_t> vec(100);
    EXPECT_EQ(100, vec.capacity());

    ASSERT_TRUE(vec.reserve(50));
    EXPECT_EQ(100, vec.size());
    EXPECT_EQ(100, vec.capacity());

    ASSERT_TRUE(vec.reserve(150));
    EXPECT_EQ(100, vec.size());
    EXPECT_EQ(150, vec.capacity());
  }

  // Bad allocation
  {
    /**
     * @brief Type with lmitations.
     */
    using TestAlloc = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    /**
     * @brief Test vector type.
     */
    using t_vector  = ::portable_stl::vector<std::int32_t, TestAlloc>;

    t_vector vec{};

    TestAlloc::m_counter_ok_allocation = 0;
    auto result                        = vec.reserve(10);

    ASSERT_FALSE(result);
    ASSERT_EQ(0, vec.capacity());
    ASSERT_EQ(0, vec.size());
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }

  // Max size
  {
    using TestAlloc = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    /**
     * @brief Test vector type.
     */
    using t_vector  = ::portable_stl::vector<std::int32_t, TestAlloc>;

    t_vector vec{};

    auto result = vec.reserve(vec.max_size() + 1);

    ASSERT_FALSE(result);
    ASSERT_EQ(0, vec.capacity());
    ASSERT_EQ(0, vec.size());
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());
  }
}

TEST(vector, size) {
  static_cast<void>(test_info_);

  ::portable_stl::vector<std::int32_t> vec;

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

TEST(vector, shrink_to_fit) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::vector<std::int32_t> vec(100);
    vec.push_back(1);
    EXPECT_GT(vec.capacity(), 101);
    ASSERT_EQ(101, vec.size());

    vec.shrink_to_fit();

    ASSERT_EQ(101, vec.capacity());
    ASSERT_EQ(101, vec.size());
  }

  // Bad allocation
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
    t_vector vec(5);
    vec.resize(1);

    TestAlloc::m_counter_ok_allocation = 0;
    auto result                        = vec.shrink_to_fit();

    ASSERT_FALSE(result);

    // Check invariant: strong guarantee
    ASSERT_EQ(5, vec.capacity());
    ASSERT_EQ(1, vec.size());
  }
}

TEST(vector, swap) {
  static_cast<void>(test_info_);

  {
    std::int32_t                         a1[] = {1, 3, 7, 9, 10};
    std::int32_t                         a2[] = {0, 2, 4, 5, 6, 8, 11};
    ::portable_stl::vector<std::int32_t> vec1(a1, a1 + sizeof(a1) / sizeof(a1[0]));
    ::portable_stl::vector<std::int32_t> vec2(a2, a2 + sizeof(a2) / sizeof(a2[0]));

    swap(vec1, vec2);

    ASSERT_EQ(::portable_stl::vector<std::int32_t>(a2, a2 + sizeof(a2) / sizeof(a2[0])), vec1);
    ASSERT_EQ(::portable_stl::vector<std::int32_t>(a1, a1 + sizeof(a1) / sizeof(a1[0])), vec2);
  }
  {
    std::int32_t                         a1[] = {1, 3, 7, 9, 10};
    std::int32_t                         a2[] = {0, 2, 4, 5, 6, 8, 11};
    ::portable_stl::vector<std::int32_t> vec1(a1, a1);
    ::portable_stl::vector<std::int32_t> vec2(a2, a2 + sizeof(a2) / sizeof(a2[0]));

    swap(vec1, vec2);

    ASSERT_EQ(::portable_stl::vector<std::int32_t>(a2, a2 + sizeof(a2) / sizeof(a2[0])), vec1);
    ASSERT_TRUE(vec2.empty());
    ASSERT_EQ(0, ::portable_stl::distance(vec2.begin(), vec2.end()));
  }
  {
    std::int32_t                         a1[] = {1, 3, 7, 9, 10};
    std::int32_t                         a2[] = {0, 2, 4, 5, 6, 8, 11};
    ::portable_stl::vector<std::int32_t> vec1(a1, a1 + sizeof(a1) / sizeof(a1[0]));
    ::portable_stl::vector<std::int32_t> vec2(a2, a2);

    swap(vec1, vec2);

    ASSERT_TRUE(vec1.empty());
    ASSERT_EQ(0, ::portable_stl::distance(vec1.begin(), vec1.end()));
    ASSERT_EQ(::portable_stl::vector<std::int32_t>(a1, a1 + sizeof(a1) / sizeof(a1[0])), vec2);
  }
  {
    std::int32_t                         a1[] = {1, 3, 7, 9, 10};
    std::int32_t                         a2[] = {0, 2, 4, 5, 6, 8, 11};
    ::portable_stl::vector<std::int32_t> vec1(a1, a1);
    ::portable_stl::vector<std::int32_t> vec2(a2, a2);

    swap(vec1, vec2);

    ASSERT_TRUE(vec1.empty());
    ASSERT_EQ(0, ::portable_stl::distance(vec1.begin(), vec1.end()));
    ASSERT_TRUE(vec2.empty());
    ASSERT_EQ(0, ::portable_stl::distance(vec2.begin(), vec2.end()));
  }
  {
    std::int32_t a1[]                  = {1, 3, 7, 9, 10};
    std::int32_t a2[]                  = {0, 2, 4, 5, 6, 8, 11};
    /**
     * @brief Type with lmitations.
     */
    using TestAlloc                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAlloc::m_counter_ok_allocation = 100;

    ::portable_stl::vector<std::int32_t, TestAlloc> vec1(a1, a1 + sizeof(a1) / sizeof(a1[0]), TestAlloc(1));
    ::portable_stl::vector<std::int32_t, TestAlloc> vec2(a2, a2 + sizeof(a2) / sizeof(a2[0]), TestAlloc(2));

    TestAlloc::m_counter_ok_allocation = 0;
    swap(vec1, vec2);

    TestAlloc::m_counter_ok_allocation = 100;

    ASSERT_EQ((::portable_stl::vector<std::int32_t, TestAlloc>(a2, a2 + sizeof(a2) / sizeof(a2[0]))), vec1);
    ASSERT_EQ(1, vec1.get_allocator().getValue());
    ASSERT_EQ((::portable_stl::vector<std::int32_t, TestAlloc>(a1, a1 + sizeof(a1) / sizeof(a1[0]))), vec2);
    ASSERT_EQ(2, vec2.get_allocator().getValue());
  }
}

// [compare]

TEST(vector, compare) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::vector<std::int32_t> const c1, c2;
    ASSERT_TRUE(test_common_helper::testComparisons(c1, c2, true, false));
  }
  {
    ::portable_stl::vector<std::int32_t> const c1(1, 1), c2(1, 2);
    ASSERT_TRUE(test_common_helper::testComparisons(c1, c2, false, true));
  }
  {
    ::portable_stl::vector<std::int32_t> const c1, c2(1, 2);
    ASSERT_TRUE(test_common_helper::testComparisons(c1, c2, false, true));
  }
  {
    std::int32_t                               items1[3] = {1, 2, 1};
    std::int32_t                               items2[3] = {1, 2, 2};
    ::portable_stl::vector<std::int32_t> const c1(items1, items1 + 3);
    ::portable_stl::vector<std::int32_t> const c2(items2, items2 + 3);
    ASSERT_TRUE(test_common_helper::testComparisons(c1, c2, false, true));
  }
  {
    std::int32_t                               items1[3] = {3, 2, 3};
    std::int32_t                               items2[3] = {3, 1, 3};
    ::portable_stl::vector<std::int32_t> const c1(items1, items1 + 3);
    ::portable_stl::vector<std::int32_t> const c2(items2, items2 + 3);

    ASSERT_TRUE(test_common_helper::testComparisons(c1, c2, false, false));
  }
  {
    std::int32_t                               items1[2] = {1, 2};
    std::int32_t                               items2[3] = {1, 2, 0};
    ::portable_stl::vector<std::int32_t> const c1(items1, items1 + 2);
    ::portable_stl::vector<std::int32_t> const c2(items2, items2 + 3);
    ASSERT_TRUE(test_common_helper::testComparisons(c1, c2, false, true));
  }
  {
    int                                        items1[3] = {1, 2, 0};
    ::portable_stl::vector<std::int32_t> const c1(items1, items1 + 3);
    ::portable_stl::vector<std::int32_t> const c2(1, 3);
    ASSERT_TRUE(test_common_helper::testComparisons(c1, c2, false, true));
  }
  {
    ::portable_stl::vector<test_vector_helper::LessAndEqComp> const c1, c2;
    ASSERT_TRUE(test_common_helper::testComparisons(c1, c2, true, false));
  }
  {
    ::portable_stl::vector<test_vector_helper::LessAndEqComp> const c1(1, test_vector_helper::LessAndEqComp(1));
    ::portable_stl::vector<test_vector_helper::LessAndEqComp> const c2(1, test_vector_helper::LessAndEqComp(1));
    ASSERT_TRUE(test_common_helper::testComparisons(c1, c2, true, false));
  }
  {
    ::portable_stl::vector<test_vector_helper::LessAndEqComp> const c1(1, test_vector_helper::LessAndEqComp(1));
    ::portable_stl::vector<test_vector_helper::LessAndEqComp> const c2(1, test_vector_helper::LessAndEqComp(2));
    ASSERT_TRUE(test_common_helper::testComparisons(c1, c2, false, true));
  }
  {
    ::portable_stl::vector<test_vector_helper::LessAndEqComp> const c1;
    ::portable_stl::vector<test_vector_helper::LessAndEqComp> const c2(1, test_vector_helper::LessAndEqComp(2));
    ASSERT_TRUE(test_common_helper::testComparisons(c1, c2, false, true));
  }
  {
    test_vector_helper::LessAndEqComp items1[3] = {
      test_vector_helper::LessAndEqComp(1), test_vector_helper::LessAndEqComp(2), test_vector_helper::LessAndEqComp(2)};
    test_vector_helper::LessAndEqComp items2[3] = {
      test_vector_helper::LessAndEqComp(1), test_vector_helper::LessAndEqComp(2), test_vector_helper::LessAndEqComp(1)};
    ::portable_stl::vector<test_vector_helper::LessAndEqComp> const c1(items1, items1 + 3);
    ::portable_stl::vector<test_vector_helper::LessAndEqComp> const c2(items2, items2 + 3);
    ASSERT_TRUE(test_common_helper::testComparisons(c1, c2, false, false));
  }
  {
    test_vector_helper::LessAndEqComp items1[3] = {
      test_vector_helper::LessAndEqComp(3), test_vector_helper::LessAndEqComp(3), test_vector_helper::LessAndEqComp(3)};
    test_vector_helper::LessAndEqComp items2[3] = {
      test_vector_helper::LessAndEqComp(3), test_vector_helper::LessAndEqComp(2), test_vector_helper::LessAndEqComp(3)};
    ::portable_stl::vector<test_vector_helper::LessAndEqComp> const c1(items1, items1 + 3);
    ::portable_stl::vector<test_vector_helper::LessAndEqComp> const c2(items2, items2 + 3);
    ASSERT_TRUE(test_common_helper::testComparisons(c1, c2, false, false));
  }
  {
    test_vector_helper::LessAndEqComp items1[2]
      = {test_vector_helper::LessAndEqComp(1), test_vector_helper::LessAndEqComp(2)};
    test_vector_helper::LessAndEqComp items2[3] = {
      test_vector_helper::LessAndEqComp(1), test_vector_helper::LessAndEqComp(2), test_vector_helper::LessAndEqComp(0)};
    ::portable_stl::vector<test_vector_helper::LessAndEqComp> const c1(items1, items1 + 2);
    ::portable_stl::vector<test_vector_helper::LessAndEqComp> const c2(items2, items2 + 3);
    ASSERT_TRUE(test_common_helper::testComparisons(c1, c2, false, true));
  }
  {
    test_vector_helper::LessAndEqComp items1[3] = {
      test_vector_helper::LessAndEqComp(1), test_vector_helper::LessAndEqComp(2), test_vector_helper::LessAndEqComp(0)};
    ::portable_stl::vector<test_vector_helper::LessAndEqComp> const c1(items1, items1 + 3);
    ::portable_stl::vector<test_vector_helper::LessAndEqComp> const c2(1, test_vector_helper::LessAndEqComp(3));
    ASSERT_TRUE(test_common_helper::testComparisons(c1, c2, false, true));
  }
  {
    ASSERT_TRUE((::portable_stl::vector<std::int32_t>() == ::portable_stl::vector<std::int32_t>()));
    ASSERT_TRUE(!(::portable_stl::vector<std::int32_t>() != ::portable_stl::vector<std::int32_t>()));
    ASSERT_TRUE(!(::portable_stl::vector<std::int32_t>() < ::portable_stl::vector<std::int32_t>()));
    ASSERT_TRUE((::portable_stl::vector<std::int32_t>() <= ::portable_stl::vector<std::int32_t>()));
    ASSERT_TRUE(!(::portable_stl::vector<std::int32_t>() > ::portable_stl::vector<std::int32_t>()));
    ASSERT_TRUE((::portable_stl::vector<std::int32_t>() >= ::portable_stl::vector<std::int32_t>()));
  }
}
