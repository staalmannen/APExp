// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="vector_constructor.cpp"
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
#include "portable_stl/vector/vector.h"
#include "vector_test_helper.h"

namespace test_vector_ctor_helper {
template<class t_vector> void ctor_default0() {
  t_vector vec;
  EXPECT_TRUE(vec.empty());
  EXPECT_EQ(typename t_vector::allocator_type(), vec.get_allocator());

  t_vector vec1 = {};
  EXPECT_TRUE(vec1.empty());
  EXPECT_EQ(typename t_vector::allocator_type(), vec1.get_allocator());
}

template<class t_vector> void ctor_default1(typename t_vector::allocator_type const &alloc) {
  EXPECT_TRUE(noexcept(t_vector{typename t_vector::allocator_type{}}));
  t_vector vec(alloc);
  EXPECT_TRUE(vec.empty());
  EXPECT_EQ(alloc, vec.get_allocator());
}
} // namespace test_vector_ctor_helper

/**
 * @brief Test allocator alias
 * @tparam t_type
 */
template<class t_type> using TestAlloc = test_allocator_helper::test_allocator<t_type>;

/**
 * @brief Explicit allocator alias
 * @tparam t_type
 */
template<class t_type> using ExplAlloc = test_allocator_helper::test_allocator<t_type>;

/**
 * @brief Test allocator alias
 */
using TestAllocSize = test_allocator_helper::TestSimpleAllocator<std::int32_t>;

TEST(vector, constructor_default) {
  static_cast<void>(test_info_);

  {
    test_vector_ctor_helper::ctor_default0<::portable_stl::vector<std::int32_t>>();
    test_vector_ctor_helper::ctor_default0<::portable_stl::vector<test_vector_helper::NotConstructible>>();
  }

  {
    test_vector_ctor_helper::ctor_default1<::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>>>(
      TestAlloc<std::int32_t>(1));
    test_vector_ctor_helper::ctor_default1<
      ::portable_stl::vector<test_vector_helper::NotConstructible, TestAlloc<test_vector_helper::NotConstructible>>>(
      TestAlloc<test_vector_helper::NotConstructible>(2));
  }

  {
    test_vector_ctor_helper::ctor_default1<::portable_stl::vector<std::int32_t, ExplAlloc<std::int32_t>>>(
      ExplAlloc<std::int32_t>(1));
    test_vector_ctor_helper::ctor_default1<
      ::portable_stl::vector<test_vector_helper::NotConstructible, ExplAlloc<test_vector_helper::NotConstructible>>>(
      ExplAlloc<test_vector_helper::NotConstructible>(2));
  }
}

TEST(vector, constructor_size) {
  static_cast<void>(test_info_);

  {
    test_vector_helper::ctor_size<::portable_stl::vector<std::int32_t>>(0);
    test_vector_helper::ctor_size<::portable_stl::vector<std::int32_t>>(50);
  }
  {
    test_common_helper::DefaultOnly::count = 0;
    test_vector_helper::ctor_size<::portable_stl::vector<test_common_helper::DefaultOnly>>(0);
    test_vector_helper::ctor_size<::portable_stl::vector<test_common_helper::DefaultOnly>>(500);
    EXPECT_EQ(0, test_common_helper::DefaultOnly::count);
  }

  // no bad allocation (zero size)
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 0;

    ::portable_stl::vector<std::int32_t, TestAllocator> vec(0);
    EXPECT_EQ(0, vec.size());
  }

  // bad allocation
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 0;

    try {
      ::portable_stl::vector<std::int32_t, TestAllocator> vec(2);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }

  // bad construction (ThrowSometime)
  {
    test_vector_helper::ThrowSometime::setThrowOnConstruction(3); // only 2 successful construction

    try {
      ::portable_stl::vector<test_vector_helper::ThrowSometime> vec(10);
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &e) {
      static_cast<void>(e);
    }

    // roll back during creation
    EXPECT_EQ(2, test_vector_helper::ThrowSometime::m_construct_count);
    EXPECT_EQ(2, test_vector_helper::ThrowSometime::m_destruct_count);
  }

  // reaching max_size
  {
    TestAllocSize::m_max_size = 10;
    try {
      ::portable_stl::vector<std::int32_t, TestAllocSize> vec(11);
      ASSERT_TRUE(false);
    } catch (::portable_stl::length_error<> &) {
    }
    TestAllocSize::m_max_size = 10000;
  }
}

TEST(vector, make_vector_size) {
  static_cast<void>(test_info_);

  {
    auto result = ::portable_stl::vector<std::int32_t>::make_vector(0);
    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_EQ(0, vec.size());
  }
  {
    auto result = ::portable_stl::vector<std::int32_t>::make_vector(3);
    ASSERT_TRUE(result);
    auto vec = result.value();
    ASSERT_EQ(3, vec.size());
    for (::portable_stl::size_t i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(0, vec[i]);
    }
  }

  // bad allocation (zero size)
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 0;

    auto result = ::portable_stl::vector<std::int32_t, TestAllocator>::make_vector(0);
    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_EQ(0, vec.size());
  }

  // bad allocation
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 0;

    auto result = ::portable_stl::vector<std::int32_t, TestAllocator>::make_vector(3);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }

  // bad construction - no error, exception only
  {
    test_vector_helper::ThrowSometime::setThrowOnConstruction(3); // only 2 successful construction

    try {
      auto result = ::portable_stl::vector<test_vector_helper::ThrowSometime>::make_vector(10);
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &e) {
      static_cast<void>(e);
    }

    // roll back during creation
    EXPECT_EQ(2, test_vector_helper::ThrowSometime::m_construct_count);
    EXPECT_EQ(2, test_vector_helper::ThrowSometime::m_destruct_count);
  }

  // reaching max_size
  {
    using TestAllocator = test_allocator_helper::TestSimpleAllocator<std::int32_t>; // max_size = 10000

    auto result = ::portable_stl::vector<std::int32_t, TestAllocator>::make_vector(20000);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());
  }
}

TEST(vector, constructor_size_alloc) {
  static_cast<void>(test_info_);

  {
    test_vector_helper::ctor_size<::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>>>(
      0, TestAlloc<std::int32_t>(1));
    test_vector_helper::ctor_size<::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>>>(
      50, TestAlloc<std::int32_t>(2));
  }
  {
    test_common_helper::DefaultOnly::count = 0;
    test_vector_helper::ctor_size<
      ::portable_stl::vector<test_common_helper::DefaultOnly, TestAlloc<test_common_helper::DefaultOnly>>>(
      0, TestAlloc<test_common_helper::DefaultOnly>(3));
    test_vector_helper::ctor_size<
      ::portable_stl::vector<test_common_helper::DefaultOnly, TestAlloc<test_common_helper::DefaultOnly>>>(
      50, TestAlloc<test_common_helper::DefaultOnly>(4));
    EXPECT_EQ(0, test_common_helper::DefaultOnly::count);
  }

  // no bad allocation (zero size)
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    TestAlloc<std::int32_t> alloc{&stat};

    ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>> vec(0, alloc);
    EXPECT_EQ(0, vec.size());
  }

  // bad allocation (zero size)
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    TestAlloc<std::int32_t> alloc{&stat};

    try {
      ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>> vec(3, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }
  }

  // bad construction (ThrowSometime)
  {
    TestAlloc<test_vector_helper::ThrowSometime> alloc{};
    test_vector_helper::ThrowSometime::setThrowOnConstruction(3); // only 2 successful construction

    try {
      ::portable_stl::vector<test_vector_helper::ThrowSometime, TestAlloc<test_vector_helper::ThrowSometime>> vec(
        10, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &e) {
      static_cast<void>(e);
    }

    // roll back during creation
    EXPECT_EQ(2, test_vector_helper::ThrowSometime::m_construct_count);
    EXPECT_EQ(2, test_vector_helper::ThrowSometime::m_destruct_count);
  }

  // reaching max_size
  {
    TestAllocSize alloc;

    TestAllocSize::m_max_size = 10;
    try {
      ::portable_stl::vector<std::int32_t, TestAllocSize> vec(11, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::length_error<> &) {
    }
    TestAllocSize::m_max_size = 10000;
  }
}

TEST(vector, make_vector_size_alloc) {
  static_cast<void>(test_info_);

  TestAlloc<std::int32_t> alloc{3};
  {
    auto result = ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>>::make_vector(0, alloc);
    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_EQ(0, vec.size());
    EXPECT_EQ(alloc, vec.get_allocator());
  }
  {
    auto result = ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>>::make_vector(3, alloc);
    ASSERT_TRUE(result);
    auto vec = result.value();
    ASSERT_EQ(3, vec.size());
    EXPECT_EQ(alloc, vec.get_allocator());
    for (::portable_stl::size_t i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(0, vec[i]);
    }
  }

  // bad allocation (zero size)
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    TestAlloc<std::int32_t> alloc1{&stat};

    auto result = ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>>::make_vector(0, alloc1);
    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_EQ(alloc1, vec.get_allocator());
    EXPECT_EQ(0, vec.size());
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    TestAlloc<std::int32_t> alloc1{&stat};

    auto result = ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>>::make_vector(3, alloc1);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }

  // bad construction - no error, exception only
  {
    test_vector_helper::ThrowSometime::setThrowOnConstruction(2); // only 2 successful construction
    TestAlloc<test_vector_helper::ThrowSometime> alloc2{2};

    try {
      auto result = ::portable_stl::vector<test_vector_helper::ThrowSometime,
                                           TestAlloc<test_vector_helper::ThrowSometime>>::make_vector(3, alloc2);
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }
  }

  // reaching max_size
  {
    using TestAllocator = test_allocator_helper::TestSimpleAllocator<std::int32_t>; // max_size = 10000
    TestAllocator alloc2;

    auto result = ::portable_stl::vector<std::int32_t, TestAllocator>::make_vector(20000, alloc2);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());
  }
}

namespace test_vector_ctor_helper {
template<class t_vector>
void ctor_size_value(typename t_vector::size_type num, typename t_vector::const_reference value) {
  {
    t_vector vec(num, value);
    ASSERT_EQ(num, vec.size());
    ASSERT_EQ(typename t_vector::allocator_type(), vec.get_allocator());
    for (typename t_vector::const_iterator i{vec.cbegin()}, e{vec.cend()}; i != e; ++i) {
      ASSERT_EQ(*i, value);
    }
  }
}
} // namespace test_vector_ctor_helper

TEST(vector, constructor_size_value) {
  static_cast<void>(test_info_);

  {
    test_vector_ctor_helper::ctor_size_value<::portable_stl::vector<std::int32_t>>(0, 3);
    test_vector_ctor_helper::ctor_size_value<::portable_stl::vector<std::int32_t>>(3, 3);
    test_vector_ctor_helper::ctor_size_value<::portable_stl::vector<std::int32_t>>(50, 3);
  }

  // no bad allocation (zero size)
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 0;

    ::portable_stl::vector<std::int32_t, TestAllocator> vec(0, 3);
    EXPECT_EQ(0, vec.size());
  }

  // bad allocation
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 0;

    try {
      ::portable_stl::vector<std::int32_t, TestAllocator> vec(2, 3);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }

  // bad construction (ThrowSometime)
  {
    test_vector_helper::ThrowSometime::setThrowOnConstruction(100);
    test_vector_helper::ThrowSometime value{3};
    test_vector_helper::ThrowSometime::setThrowOnConstruction(3); // only 2 successful construction

    try {
      ::portable_stl::vector<test_vector_helper::ThrowSometime> vec(10, value);
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // roll back during creation
    EXPECT_EQ(2, test_vector_helper::ThrowSometime::m_construct_count);
    EXPECT_EQ(2, test_vector_helper::ThrowSometime::m_destruct_count);
  }

  // reaching max_size
  {
    TestAllocSize::m_max_size = 10;
    try {
      ::portable_stl::vector<std::int32_t, TestAllocSize> vec(11, 1);
      ASSERT_TRUE(false);
    } catch (::portable_stl::length_error<> &) {
    }
    TestAllocSize::m_max_size = 10000;
  }
}

TEST(vector, make_vector_size_value) {
  static_cast<void>(test_info_);
  {
    auto result = ::portable_stl::vector<std::int32_t>::make_vector(0, 3);
    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_EQ(0, vec.size());
  }
  {
    auto result = ::portable_stl::vector<std::int32_t>::make_vector(3, 3);
    ASSERT_TRUE(result);
    auto vec = result.value();
    ASSERT_EQ(3, vec.size());
    for (::portable_stl::size_t i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(3, vec[i]);
    }
  }
  // bad allocation (zero size)
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 0;

    auto result = ::portable_stl::vector<std::int32_t, TestAllocator>::make_vector(0, 3);
    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_EQ(0, vec.size());
  }
  // bad allocation
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 0;

    auto result = ::portable_stl::vector<std::int32_t, TestAllocator>::make_vector(3, 3);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }

  // bad construction - no error, exception only
  {
    test_vector_helper::ThrowSometime::setThrowOnConstruction(100);
    test_vector_helper::ThrowSometime value(3);
    test_vector_helper::ThrowSometime::setThrowOnConstruction(3);

    try {
      auto result = ::portable_stl::vector<test_vector_helper::ThrowSometime>::make_vector(10, value);
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &e) {
      static_cast<void>(e);
    }

    // roll back during creation
    EXPECT_EQ(2, test_vector_helper::ThrowSometime::m_construct_count);
    EXPECT_EQ(2, test_vector_helper::ThrowSometime::m_destruct_count);
  }

  // too much
  {
    using TestAllocator = test_allocator_helper::TestSimpleAllocator<std::int32_t>; // max_size = 10000
    auto result         = ::portable_stl::vector<std::int32_t, TestAllocator>::make_vector(20000, 3);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());
  }
}

namespace test_vector_ctor_helper {
template<class t_vector>
void ctor_size_value_alloc(typename t_vector::size_type             num,
                           typename t_vector::const_reference       value,
                           typename t_vector::allocator_type const &alloc) {
  {
    t_vector vec(num, value, alloc);
    ASSERT_EQ(num, vec.size());
    ASSERT_EQ(alloc, vec.get_allocator());
    for (typename t_vector::const_iterator i{vec.cbegin()}, e{vec.cend()}; i != e; ++i) {
      ASSERT_EQ(*i, value);
    }
  }
}
} // namespace test_vector_ctor_helper

TEST(vector, constructor_size_value_alloc) {
  static_cast<void>(test_info_);

  {
    test_vector_ctor_helper::ctor_size_value_alloc<::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>>>(
      0, 3, TestAlloc<std::int32_t>(1));
    test_vector_ctor_helper::ctor_size_value_alloc<::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>>>(
      50, 3, TestAlloc<std::int32_t>(2));
  }

  // no bad allocation (zero size)
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    TestAlloc<std::int32_t> alloc{&stat};

    ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>> vec(0, 3, alloc);
    EXPECT_EQ(0, vec.size());
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    TestAlloc<std::int32_t> alloc{&stat};

    try {
      ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>> vec(3, 3, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }
  }

  // bad construction (ThrowSometime)
  {
    TestAlloc<test_vector_helper::ThrowSometime> alloc{};
    test_vector_helper::ThrowSometime::setThrowOnConstruction(100);
    test_vector_helper::ThrowSometime value(3);
    test_vector_helper::ThrowSometime::setThrowOnConstruction(3);

    try {
      ::portable_stl::vector<test_vector_helper::ThrowSometime, TestAlloc<test_vector_helper::ThrowSometime>> vec(
        10, value, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &e) {
      static_cast<void>(e);
    }

    // roll back during creation
    EXPECT_EQ(2, test_vector_helper::ThrowSometime::m_construct_count);
    EXPECT_EQ(2, test_vector_helper::ThrowSometime::m_destruct_count);
  }

  // reaching max_size
  {
    TestAllocSize alloc;
    TestAllocSize::m_max_size = 10;

    try {
      ::portable_stl::vector<std::int32_t, TestAllocSize> vec(11, 1, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::length_error<> &) {
    }
    TestAllocSize::m_max_size = 10000;
  }
}

TEST(vector, make_vector_size_value_alloc) {
  static_cast<void>(test_info_);

  TestAlloc<std::int32_t> alloc{3};
  {
    auto result = ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>>::make_vector(0, 3, alloc);
    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_EQ(0, vec.size());
    EXPECT_EQ(alloc, vec.get_allocator());
  }
  {
    auto result = ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>>::make_vector(3, 3, alloc);
    ASSERT_TRUE(result);
    auto vec = result.value();
    ASSERT_EQ(3, vec.size());
    EXPECT_EQ(alloc, vec.get_allocator());
    for (::portable_stl::size_t i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(3, vec[i]);
    }
  }

  // bad allocation (zero size)
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    TestAlloc<std::int32_t> alloc1{&stat};

    auto result = ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>>::make_vector(0, 3, alloc1);
    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_EQ(alloc1, vec.get_allocator());
    EXPECT_EQ(0, vec.size());
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    TestAlloc<std::int32_t> alloc1{&stat};

    auto result = ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>>::make_vector(10, 3, alloc1);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }

  test_vector_helper::ThrowSometime::setThrowOnConstruction(100);
  test_vector_helper::ThrowSometime value{3};

  // bad construction - no error, exception only
  {
    TestAlloc<test_vector_helper::ThrowSometime> alloc2{2};
    test_vector_helper::ThrowSometime::setThrowOnConstruction(3); // only 2 successful construction

    try {
      auto result
        = ::portable_stl::vector<test_vector_helper::ThrowSometime,
                                 TestAlloc<test_vector_helper::ThrowSometime>>::make_vector(10, value, alloc2);
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &e) {
      static_cast<void>(e);
    }
  }
  // too much
  {
    using TestAllocator = test_allocator_helper::TestSimpleAllocator<std::int32_t>; // max_size = 10000
    TestAllocator alloc2;

    auto result = ::portable_stl::vector<std::int32_t, TestAllocator>::make_vector(20000, 3, alloc2);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());
  }
}

TEST(vector, constructor_iter_iter) {
  static_cast<void>(test_info_);

  {
    std::int32_t  a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 1, 0};
    std::int32_t *an  = a + sizeof(a) / sizeof(a[0]);

    test_vector_helper::ctor_iter_iter<::portable_stl::vector<std::int32_t>>(
      test_iterator_helper::tst_input_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_input_iterator<std::int32_t const *>(an));

    test_vector_helper::ctor_iter_iter<::portable_stl::vector<std::int32_t>>(
      test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_forward_iterator<std::int32_t const *>(an));

    test_vector_helper::ctor_iter_iter<::portable_stl::vector<std::int32_t>>(
      test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>(an));

    test_vector_helper::ctor_iter_iter<::portable_stl::vector<std::int32_t>>(
      test_iterator_helper::tst_random_access_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_random_access_iterator<std::int32_t const *>(an));

    test_vector_helper::ctor_iter_iter<::portable_stl::vector<std::int32_t>>(a, an);
  }

  // Regression test for https://github.com/llvm/llvm-project/issues/46841
  {
    ::portable_stl::vector<std::int32_t> v1({}, test_iterator_helper::tst_forward_iterator<std::int32_t const *>{});
    ::portable_stl::vector<std::int32_t> vec(test_iterator_helper::tst_forward_iterator<std::int32_t const *>{}, {});
  }

  // Make sure initialization is performed with each element value, not with a memory blob.
  {
    std::int16_t                         array[3] = {0, 1, 2};
    ::portable_stl::vector<std::int64_t> vec(array, array + 3);
    EXPECT_EQ(0, vec[0]);
    EXPECT_EQ(1, vec[1]);
    EXPECT_EQ(2, vec[2]);
  }

  // Though the types are different, initialization can be done with `memcpy`.
  {
    std::uint16_t                         array[1] = {65535};
    ::portable_stl::vector<std::uint32_t> v(array, array + 1);
    EXPECT_EQ(1, v.size());
    EXPECT_EQ(65535, v[0]);
  }

  // no bad allocation (zero size) tst_forward_iterator
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 0;

    std::int32_t  a[] = {0};
    std::int32_t *an  = a;

    ::portable_stl::vector<std::int32_t, TestAllocator> vec{
      test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_forward_iterator<std::int32_t const *>(an)};
    EXPECT_EQ(0, vec.size());
  }

  // bad allocation tst_forward_iterator
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 0;

    std::int32_t  a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 1, 0};
    std::int32_t *an  = a + sizeof(a) / sizeof(a[0]);

    try {
      ::portable_stl::vector<std::int32_t, TestAllocator> vec{
        test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a),
        test_iterator_helper::tst_forward_iterator<std::int32_t const *>(an)};
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }
  }

  // ok construction tst_forward_iterator USE memcpy
  {
    /**
     * @brief Test type with trivial ctors.
     */
    using T             = std::int32_t;
    /**
     * @brief Test allocator with no limits.
     */
    using TestAllocator = test_allocator_helper::TestSimpleAllocator<T>;
    TestAllocator::resetStat();

    T  a[] = {0, 1, 2, 3, 4, 5};
    T *an  = a + sizeof(a) / sizeof(a[0]);

    ::portable_stl::vector<T, TestAllocator> vec{a, an};

    // memcpy used to construct vector<T>.
    EXPECT_EQ(0, TestAllocator::m_construct_count);
    EXPECT_EQ(0, TestAllocator::m_destroy_count);
  }

  // ok construction tst_forward_iterator USE construct/destroy
  {
    /**
     * @brief Test type with trivial ctors.
     */
    using T             = test_vector_helper::ThrowSometime;
    /**
     * @brief Test allocator with no limits.
     */
    using TestAllocator = test_allocator_helper::TestSimpleAllocator<test_vector_helper::ThrowSometime>;
    TestAllocator::resetStat();
    T::setThrowOnConstruction(100);

    std::int32_t  a[] = {0, 1, 2, 3, 4};
    std::int32_t *an  = a + sizeof(a) / sizeof(a[0]);

    ::portable_stl::vector<test_vector_helper::ThrowSometime, TestAllocator> vec{
      test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_forward_iterator<std::int32_t const *>(an)};

    // allocator.construct used to construct vector<T>.
    EXPECT_EQ(5, TestAllocator::m_construct_count);
    EXPECT_EQ(0, TestAllocator::m_destroy_count);
  }

  // bad construction tst_forward_iterator USE construct/destroy
  {
    /**
     * @brief Test type with trivial ctors.
     */
    using T             = test_vector_helper::ThrowSometime;
    /**
     * @brief Test allocator with no limits.
     */
    using TestAllocator = test_allocator_helper::TestSimpleAllocator<test_vector_helper::ThrowSometime>;
    TestAllocator::resetStat();
    T::setThrowOnConstruction(4);

    std::int32_t  a[] = {0, 1, 2, 3, 4};
    std::int32_t *an  = a + sizeof(a) / sizeof(a[0]);

    try {
      ::portable_stl::vector<test_vector_helper::ThrowSometime, TestAllocator> vec{
        test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a),
        test_iterator_helper::tst_forward_iterator<std::int32_t const *>(an)};
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // allocator.construct/destroy used to construct vector<T>.
    EXPECT_EQ(3, TestAllocator::m_construct_count);
    EXPECT_EQ(3, TestAllocator::m_destroy_count);
  }

  // no bad allocation tst_input_iterator
  {
    /**
     * @brief Test type with trivial ctors.
     */
    using T             = test_vector_helper::ThrowSometime;
    /**
     * @brief Test allocator with no limits.
     */
    using TestAllocator = test_allocator_helper::TestSimpleAllocator<test_vector_helper::ThrowSometime>;
    TestAllocator::resetStat();
    T::setThrowOnConstruction(100);

    std::int32_t  a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    std::int32_t *an  = a + sizeof(a) / sizeof(a[0]);

    ::portable_stl::vector<test_vector_helper::ThrowSometime, TestAllocator> vec{
      test_iterator_helper::tst_input_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_input_iterator<std::int32_t const *>(an)};

    ASSERT_EQ(9, vec.size());
  }

  // no bad allocation (zero size) tst_input_iterator
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 0;

    std::int32_t  a[] = {0};
    std::int32_t *an  = a;

    ::portable_stl::vector<std::int32_t, TestAllocator> vec{
      test_iterator_helper::tst_input_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_input_iterator<std::int32_t const *>(an)};
    EXPECT_EQ(0, vec.size());
  }

  // bad allocation tst_input_iterator
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 4;

    std::int32_t  a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 1, 0};
    std::int32_t *an  = a + sizeof(a) / sizeof(a[0]);

    try {
      ::portable_stl::vector<std::int32_t, TestAllocator> vec{
        test_iterator_helper::tst_input_iterator<std::int32_t const *>(a),
        test_iterator_helper::tst_input_iterator<std::int32_t const *>(an)};
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }

  // bad construction tst_input_iterator USE construct/destroy
  {
    /**
     * @brief Test type with trivial ctors.
     */
    using T             = test_vector_helper::ThrowSometime;
    /**
     * @brief Test allocator with no limits.
     */
    using TestAllocator = test_allocator_helper::TestSimpleAllocator<test_vector_helper::ThrowSometime>;
    TestAllocator::resetStat();
    T::setThrowOnConstruction(6);

    std::int32_t  a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    std::int32_t *an  = a + sizeof(a) / sizeof(a[0]);

    try {
      ::portable_stl::vector<test_vector_helper::ThrowSometime, TestAllocator> vec{
        test_iterator_helper::tst_input_iterator<std::int32_t const *>(a),
        test_iterator_helper::tst_input_iterator<std::int32_t const *>(an)};
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &) {
    }

    // allocator.construct/destroy used to construct vector<T>.
    EXPECT_EQ(5, TestAllocator::m_construct_count);
    EXPECT_EQ(5, TestAllocator::m_destroy_count);
  }
}

TEST(vector, make_vector_iter_iter) {
  static_cast<void>(test_info_);

  std::int32_t  a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 1, 0};
  std::int32_t *an  = a + sizeof(a) / sizeof(a[0]);

  // OK input_iterator, size 0
  {
    auto result = ::portable_stl::vector<std::int32_t>::make_vector(
      test_iterator_helper::tst_input_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_input_iterator<std::int32_t const *>(a));

    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_TRUE(vec.empty());
  }

  // OK input_iterator, size >0
  {
    auto result = ::portable_stl::vector<std::int32_t>::make_vector(
      test_iterator_helper::tst_input_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_input_iterator<std::int32_t const *>(an));

    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_EQ(18, vec.size());
  }

  // OK forward_iterator, size 0
  {
    auto result = ::portable_stl::vector<std::int32_t>::make_vector(
      test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a));

    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_TRUE(vec.empty());
  }

  // OK forward_iterator, size >0
  {
    auto result = ::portable_stl::vector<std::int32_t>::make_vector(
      test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_forward_iterator<std::int32_t const *>(an));

    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_EQ(18, vec.size());
  }

  // bad allocation input_iterator
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 4;

    auto result = ::portable_stl::vector<std::int32_t, TestAllocator>::make_vector(
      test_iterator_helper::tst_input_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_input_iterator<std::int32_t const *>(an));

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }

  // bad allocation forward_iterator
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 0;

    auto result = ::portable_stl::vector<std::int32_t, TestAllocator>::make_vector(
      test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_forward_iterator<std::int32_t const *>(an));

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }

  // bad construction input_iterator USE construct/destroy
  {
    /**
     * @brief Test type with trivial ctors.
     */
    using T             = test_vector_helper::ThrowSometime;
    /**
     * @brief Test allocator with no limits.
     */
    using TestAllocator = test_allocator_helper::TestSimpleAllocator<test_vector_helper::ThrowSometime>;
    TestAllocator::resetStat();
    T::setThrowOnConstruction(6);

    try {
      auto result = ::portable_stl::vector<test_vector_helper::ThrowSometime, TestAllocator>::make_vector(
        test_iterator_helper::tst_input_iterator<std::int32_t const *>(a),
        test_iterator_helper::tst_input_iterator<std::int32_t const *>(an));
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &e) {
      static_cast<void>(e);
    }

    // allocator.construct/destroy used to construct vector<T>.
    EXPECT_EQ(5, TestAllocator::m_construct_count);
    EXPECT_EQ(5, TestAllocator::m_destroy_count);
  }

  // bad construction forward_iterator USE construct/destroy
  {
    /**
     * @brief Test type with trivial ctors.
     */
    using T             = test_vector_helper::ThrowSometime;
    /**
     * @brief Test allocator with no limits.
     */
    using TestAllocator = test_allocator_helper::TestSimpleAllocator<test_vector_helper::ThrowSometime>;
    TestAllocator::resetStat();
    T::setThrowOnConstruction(6);

    try {
      auto result = ::portable_stl::vector<test_vector_helper::ThrowSometime, TestAllocator>::make_vector(
        test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a),
        test_iterator_helper::tst_forward_iterator<std::int32_t const *>(an));
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &e) {
      static_cast<void>(e);
    }

    // allocator.construct/destroy used to construct vector<T>.
    EXPECT_EQ(5, TestAllocator::m_construct_count);
    EXPECT_EQ(5, TestAllocator::m_destroy_count);
  }

  // max_size tst_forward_iterator
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 100;
    TestAllocator::m_max_size              = 10;

    auto result = ::portable_stl::vector<std::int32_t, TestAllocator>::make_vector(
      test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_forward_iterator<std::int32_t const *>(an));

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    TestAllocator::m_max_size = 10000;
  }
}

TEST(vector, constructor_iter_iter_alloc) {
  static_cast<void>(test_info_);

  {
    std::int32_t            a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 1, 0};
    std::int32_t           *an  = a + sizeof(a) / sizeof(a[0]);
    TestAlloc<std::int32_t> alloc;

    test_vector_helper::ctor_iter_iter_alloc<::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>>>(
      test_iterator_helper::tst_input_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_input_iterator<std::int32_t const *>(an),
      alloc);

    test_vector_helper::ctor_iter_iter_alloc<::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>>>(
      test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_forward_iterator<std::int32_t const *>(an),
      alloc);

    test_vector_helper::ctor_iter_iter_alloc<::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>>>(
      test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_bidirectional_iterator<std::int32_t const *>(an),
      alloc);

    test_vector_helper::ctor_iter_iter_alloc<::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>>>(
      test_iterator_helper::tst_random_access_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_random_access_iterator<std::int32_t const *>(an),
      alloc);

    test_vector_helper::ctor_iter_iter_alloc<::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>>>(
      a, an, alloc);
  }

  // bad allocation tst_input_iterator
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 4;
    TestAllocator alloc;

    std::int32_t  a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 1, 0};
    std::int32_t *an  = a + sizeof(a) / sizeof(a[0]);

    try {
      ::portable_stl::vector<std::int32_t, TestAllocator> vec{
        test_iterator_helper::tst_input_iterator<std::int32_t const *>(a),
        test_iterator_helper::tst_input_iterator<std::int32_t const *>(an),
        alloc};
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }

  // max_size tst_forward_iterator
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 100;
    TestAllocator::m_max_size              = 10;
    TestAllocator alloc;

    std::int32_t  a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 1, 0};
    std::int32_t *an  = a + sizeof(a) / sizeof(a[0]);

    try {
      ::portable_stl::vector<std::int32_t, TestAllocator> vec{
        test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a),
        test_iterator_helper::tst_forward_iterator<std::int32_t const *>(an),
        alloc};
      ASSERT_TRUE(false);
    } catch (::portable_stl::length_error<> &) {
    }
    TestAllocator::m_max_size = 10000;
  }
}

TEST(vector, make_vector_iter_iter_alloc) {
  static_cast<void>(test_info_);

  std::int32_t            a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 1, 0};
  std::int32_t           *an  = a + sizeof(a) / sizeof(a[0]);
  TestAlloc<std::int32_t> alloc;

  // OK input_iterator, size 0
  {
    auto result = ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>>::make_vector(
      test_iterator_helper::tst_input_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_input_iterator<std::int32_t const *>(a),
      alloc);

    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_TRUE(vec.empty());
  }

  // OK input_iterator, size >0
  {
    auto result = ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>>::make_vector(
      test_iterator_helper::tst_input_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_input_iterator<std::int32_t const *>(an),
      alloc);

    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_EQ(18, vec.size());
  }

  // OK forward_iterator, size 0
  {
    auto result = ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>>::make_vector(
      test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a),
      alloc);

    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_TRUE(vec.empty());
  }

  // OK forward_iterator, size >0
  {
    auto result = ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>>::make_vector(
      test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_forward_iterator<std::int32_t const *>(an),
      alloc);

    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_EQ(18, vec.size());
  }

  // max_size tst_forward_iterator
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 100;
    TestAllocator::m_max_size              = 10;
    TestAllocator alloc2;

    auto result = ::portable_stl::vector<std::int32_t, TestAllocator>::make_vector(
      test_iterator_helper::tst_forward_iterator<std::int32_t const *>(a),
      test_iterator_helper::tst_forward_iterator<std::int32_t const *>(an),
      alloc2);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    TestAllocator::m_max_size = 10000;
  }
}

TEST(vector, constructor_initializer_list) {
  static_cast<void>(test_info_);

  // ok
  {
    ::portable_stl::vector<std::int32_t> vec{0, 1, 2, 3, 4, 5};
    ASSERT_EQ(6, vec.size());
    for (::portable_stl::size_t i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(i, vec[i]);
    }
  }

  // bad allocation
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 0;

    try {
      ::portable_stl::vector<std::int32_t, TestAllocator> vec{0, 1, 2, 3, 4, 5};
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }
  }

  // bad construction (ThrowSometime)
  {
    test_vector_helper::ThrowSometime::setThrowOnConstruction(100);
    test_vector_helper::ThrowSometime value0{0};
    test_vector_helper::ThrowSometime value1{1};
    test_vector_helper::ThrowSometime value2{2};
    test_vector_helper::ThrowSometime value3{3};
    test_vector_helper::ThrowSometime::setThrowOnConstruction(
      4 + 3); // only 2 successful construction (4 on initializer list construction)

    try {
      ::portable_stl::vector<test_vector_helper::ThrowSometime> vec{value0, value1, value2, value3};
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &e) {
      static_cast<void>(e);
    }

    // roll back during creation
    EXPECT_EQ(4 + 2, test_vector_helper::ThrowSometime::m_construct_count);
    EXPECT_EQ(4 + 2, test_vector_helper::ThrowSometime::m_destruct_count);
  }

  // max_size
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 100;
    TestAllocator::m_max_size              = 10;

    try {
      ::portable_stl::vector<std::int32_t, TestAllocator> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 8, 7, 6, 5, 4, 3, 2, 1};
      ASSERT_TRUE(false);
    } catch (::portable_stl::length_error<> &) {
    }

    TestAllocator::m_max_size = 10000;
  }
}

TEST(vector, constructor_initializer_list_alloc) {
  static_cast<void>(test_info_);

  // ok
  {
    TestAlloc<std::int32_t>                                       alloc;
    ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>> vec({0, 1, 2, 3, 4, 5}, alloc);
    ASSERT_EQ(6, vec.size());
    for (::portable_stl::size_t i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(i, vec[i]);
    }
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    TestAlloc<std::int32_t> alloc1{&stat};

    try {
      ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>> vec({0, 1, 2, 3, 4, 5}, alloc1);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &e) {
      static_cast<void>(e);
    }
  }

  // bad construction (ThrowSometime)
  {
    test_vector_helper::ThrowSometime::setThrowOnConstruction(100);
    test_vector_helper::ThrowSometime value0{0};
    test_vector_helper::ThrowSometime value1{1};
    test_vector_helper::ThrowSometime value2{2};
    test_vector_helper::ThrowSometime value3{3};
    test_vector_helper::ThrowSometime::setThrowOnConstruction(
      4 + 3); // only 2 successful construction (4 on initializer list construction)

    TestAlloc<test_vector_helper::ThrowSometime> alloc;

    try {
      ::portable_stl::vector<test_vector_helper::ThrowSometime, TestAlloc<test_vector_helper::ThrowSometime>> vec(
        {value0, value1, value2, value3}, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::logic_error<> &e) {
      static_cast<void>(e);
    }

    // roll back during creation
    EXPECT_EQ(4 + 2, test_vector_helper::ThrowSometime::m_construct_count);
    EXPECT_EQ(4 + 2, test_vector_helper::ThrowSometime::m_destruct_count);
  }

  // max_size
  {
    using TestAllocator                    = test_allocator_helper::TestSimpleAllocator<std::int32_t>;
    TestAllocator::m_counter_ok_allocation = 100;
    TestAllocator::m_max_size              = 10;
    TestAllocator alloc;

    try {
      ::portable_stl::vector<std::int32_t, TestAllocator> vec({1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 8, 7, 6, 5, 4, 3, 2, 1},
                                                              alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::length_error<> &) {
    }

    TestAllocator::m_max_size = 10000;
  }
}

TEST(vector, get_allocator) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::allocator<std::int32_t> alloc;
    ::portable_stl::vector<std::int32_t>    vec(alloc);

    EXPECT_EQ(alloc, vec.get_allocator());
  }
  {
    using TestAllocator = test_allocator_helper::TestSimpleAllocator<std::int32_t>;

    TestAllocator                                       alloc(3);
    ::portable_stl::vector<std::int32_t, TestAllocator> vec(alloc);

    EXPECT_EQ(alloc, vec.get_allocator());
  }
}

TEST(vector, constructor_copy) {
  static_cast<void>(test_info_);
  {
    std::int32_t  a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 1, 0};
    std::int32_t *an  = a + sizeof(a) / sizeof(a[0]);
    test_vector_helper::test_constructor_copy(::portable_stl::vector<std::int32_t>(a, an));
  }
  {
    ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>> vec0(3, 2, TestAlloc<std::int32_t>(5));
    ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>> vec = vec0;
    EXPECT_EQ(vec0, vec);
    EXPECT_EQ(vec.get_allocator(), vec0.get_allocator());
  }

  // Test copy ctor with empty source
  {
    ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>> vec0(TestAlloc<std::int32_t>(5));
    ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>> vec = vec0;
    EXPECT_EQ(vec0, vec);
    EXPECT_EQ(vec.get_allocator(), vec0.get_allocator());
    EXPECT_TRUE(vec.empty());
  }
}

TEST(vector, constructor_copy_alloc) {
  static_cast<void>(test_info_);
  {
    std::int32_t  a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 1, 0};
    std::int32_t *an  = a + sizeof(a) / sizeof(a[0]);
    test_vector_helper::test_constructor_copy_alloc(::portable_stl::vector<std::int32_t>(a, an),
                                                    ::portable_stl::allocator<std::int32_t>());
  }
  {
    ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>> vec0(3, 2, TestAlloc<std::int32_t>(5));
    ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>> vec(vec0, TestAlloc<std::int32_t>(3));
    EXPECT_EQ(vec0, vec);
    EXPECT_EQ(vec.get_allocator(), TestAlloc<std::int32_t>(3));
  }

  // Test copy ctor with empty source
  {
    ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>> vec0(TestAlloc<std::int32_t>(5));
    ::portable_stl::vector<std::int32_t, TestAlloc<std::int32_t>> vec(vec0, TestAlloc<std::int32_t>(3));
    EXPECT_TRUE(vec.empty());
    EXPECT_EQ(vec0, vec);
    EXPECT_EQ(vec.get_allocator(), TestAlloc<std::int32_t>(3));
  }
}

TEST(vector, constructor_move) {
  static_cast<void>(test_info_);

  // invoke operator== ( MoveOnly &, MoveOnly & )
  {
    test_common_helper::MoveOnly a(2);
    test_common_helper::MoveOnly ref(1);
    test_common_helper::MoveOnly b(1);
    a = std::move(b);
    ASSERT_TRUE(ref == a);
  }

  test_allocator_helper::test_allocator_statistics stat{};
  {
    ::portable_stl::vector<test_common_helper::MoveOnly, TestAlloc<test_common_helper::MoveOnly>> vec(
      TestAlloc<test_common_helper::MoveOnly>(5, &stat));
    ::portable_stl::vector<test_common_helper::MoveOnly, TestAlloc<test_common_helper::MoveOnly>> vec0(
      TestAlloc<test_common_helper::MoveOnly>(5, &stat));

    for (std::int32_t i = 1; i <= 3; ++i) {
      vec.push_back(i);
      vec0.push_back(i);
    }

    ::portable_stl::vector<test_common_helper::MoveOnly, TestAlloc<test_common_helper::MoveOnly>> vec2 = std::move(vec);
    EXPECT_EQ(vec0, vec2);
    EXPECT_TRUE(vec.empty());
    EXPECT_EQ(vec2.get_allocator(), vec0.get_allocator());
  }
  {
    std::int32_t                         a1[] = {1, 3, 7, 9, 10};
    ::portable_stl::vector<std::int32_t> vec0(a1, a1 + sizeof(a1) / sizeof(a1[0]));

    ::portable_stl::vector<std::int32_t>::const_iterator i    = vec0.begin();
    ::portable_stl::vector<std::int32_t>                 vec2 = std::move(vec0);
    ::portable_stl::vector<std::int32_t>::iterator       j    = vec2.erase(i);
    EXPECT_EQ(3, *j);
  }
}

TEST(vector, constructor_move_alloc) {
  static_cast<void>(test_info_);

  // different allocators - move via assign
  {
    ::portable_stl::vector<test_common_helper::MoveOnly, TestAlloc<test_common_helper::MoveOnly>> vec0(
      TestAlloc<test_common_helper::MoveOnly>(5));
    ::portable_stl::vector<test_common_helper::MoveOnly, TestAlloc<test_common_helper::MoveOnly>> vec(
      TestAlloc<test_common_helper::MoveOnly>(5));

    for (std::int32_t i = 1; i <= 3; ++i) {
      vec0.push_back(i);
      vec.push_back(i);
    }

    ::portable_stl::vector<test_common_helper::MoveOnly, TestAlloc<test_common_helper::MoveOnly>> vec2(
      std::move(vec0), TestAlloc<test_common_helper::MoveOnly>(6));
    EXPECT_EQ(vec, vec2);
    EXPECT_FALSE(vec0.empty());
    EXPECT_EQ(vec2.get_allocator(), TestAlloc<test_common_helper::MoveOnly>(6));
  }

  // same allocator - 'pure' move
  {
    ::portable_stl::vector<test_common_helper::MoveOnly, TestAlloc<test_common_helper::MoveOnly>> vec0(
      TestAlloc<test_common_helper::MoveOnly>(5));
    ::portable_stl::vector<test_common_helper::MoveOnly, TestAlloc<test_common_helper::MoveOnly>> vec(
      TestAlloc<test_common_helper::MoveOnly>(5));
    for (int i = 1; i <= 3; ++i) {
      vec0.push_back(i);
      vec.push_back(i);
    }
    ::portable_stl::vector<test_common_helper::MoveOnly, TestAlloc<test_common_helper::MoveOnly>> vec2(
      std::move(vec0), TestAlloc<test_common_helper::MoveOnly>(5));

    EXPECT_EQ(vec2, vec);
    EXPECT_TRUE(vec0.empty());
    EXPECT_EQ(vec2.get_allocator(), TestAlloc<test_common_helper::MoveOnly>(5));
  }
}
