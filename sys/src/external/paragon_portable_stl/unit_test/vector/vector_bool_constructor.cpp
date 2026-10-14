// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="vector_bool_constructor.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "../iterator_helper.h"
#include "portable_stl/vector/vector_bool.h"
#include "../common/test_allocator.h"
#include "vector_test_helper.h"

namespace test_vector_bool_ctor_helper {} // namespace test_vector_bool_ctor_helper

/**
 * @brief Test allocator alias
 * @tparam t_type
 */
using TestBoolAlloc = test_allocator_helper::test_allocator<bool>;

/**
 * @brief Storage allocator for vecor<bool>
 */
using TestUIntAlloc = test_allocator_helper::test_allocator<::portable_stl::vector<bool>::t_storage_type>;

/**
 * @brief Test allocator alias
 */
using TestBoolSimpleAlloc = test_allocator_helper::TestSimpleAllocator<bool>;

/**
 * @brief Storage allocator for vecor<bool>
 */
using TestUIntSimpleAlloc = test_allocator_helper::TestSimpleAllocator<::portable_stl::vector<bool>::t_storage_type>;

TEST(vector_bool, constructor_default) {
  static_cast<void>(test_info_);

  {
    /**
     * @brief Vector alias.
     */
    using t_vector = ::portable_stl::vector<bool>;

    t_vector vec;
    EXPECT_TRUE(vec.empty());
    EXPECT_EQ(typename t_vector::allocator_type(), vec.get_allocator());

    t_vector vec1 = {};
    EXPECT_TRUE(vec1.empty());
    EXPECT_EQ(typename t_vector::allocator_type(), vec1.get_allocator());
  }
  {
    /**
     * @brief Vector alias.
     */
    using t_vector = ::portable_stl::vector<bool, TestBoolAlloc>;

    TestBoolAlloc alloc(1);

    EXPECT_TRUE(noexcept(t_vector{typename t_vector::allocator_type{}}));
    t_vector vec(alloc);
    EXPECT_TRUE(vec.empty());
    EXPECT_EQ(alloc, vec.get_allocator());
  }
}

TEST(vector_bool, constructor_size) {
  static_cast<void>(test_info_);

  {
    test_vector_helper::ctor_size<::portable_stl::vector<bool>>(0);
    test_vector_helper::ctor_size<::portable_stl::vector<bool>>(50);
  }

  // no bad allocation (zero size)
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;

    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(0);
    EXPECT_EQ(0, vec.size());
  }

  // bad allocation
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;

    try {
      ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(2);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }

  // reaching max_size
  {
    TestUIntSimpleAlloc::m_max_size              = 5;
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    try {
      ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(11 * 32);
      ASSERT_TRUE(false);
    } catch (::portable_stl::length_error<> &) {
    }
    TestUIntSimpleAlloc::m_max_size = 10000;
  }
}

TEST(vector_bool, make_vector_size) {
  static_cast<void>(test_info_);

  {
    auto result = ::portable_stl::vector<bool>::make_vector(0);
    ASSERT_TRUE(result);

    auto vec = result.value();
    EXPECT_EQ(0, vec.size());
  }
  {
    auto result = ::portable_stl::vector<bool>::make_vector(3);
    ASSERT_TRUE(result);

    auto vec = result.value();
    ASSERT_EQ(3, vec.size());
    for (::portable_stl::size_t i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(false, vec[i]);
    }
  }

  // bad allocation (zero size) - no error
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;

    auto result = ::portable_stl::vector<bool, TestBoolSimpleAlloc>::make_vector(0);
    ASSERT_TRUE(result);

    auto vec = result.value();
    EXPECT_EQ(0, vec.size());
  }

  // bad allocation
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;

    auto result = ::portable_stl::vector<bool, TestBoolSimpleAlloc>::make_vector(3);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }

  // reaching max_size
  {
    TestUIntSimpleAlloc::m_max_size                = 5;
    TestUIntSimpleAlloc::m_counter_ok_construction = 100;

    auto result = ::portable_stl::vector<bool, TestBoolSimpleAlloc>::make_vector(11 * 32);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    TestUIntSimpleAlloc::m_max_size = 10000;
  }
}

TEST(vector_bool, constructor_size_alloc) {
  static_cast<void>(test_info_);

  {
    test_vector_helper::ctor_size<::portable_stl::vector<bool, TestBoolAlloc>>(0, TestBoolAlloc(1));
    test_vector_helper::ctor_size<::portable_stl::vector<bool, TestBoolAlloc>>(50, TestBoolAlloc(2));
  }

  // no bad allocation (zero size)
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    TestUIntAlloc alloc{&stat};

    ::portable_stl::vector<bool, TestBoolAlloc> vec(0, alloc);
    EXPECT_EQ(0, vec.size());
  }

  // bad allocation (zero size)
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    TestUIntAlloc alloc{&stat};

    try {
      ::portable_stl::vector<bool, TestBoolAlloc> vec(3, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }

  // reaching max_size
  {
    TestBoolSimpleAlloc                               alloc;

    TestUIntSimpleAlloc::m_max_size              = 5;
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    try {
      ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(11 * 32, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::length_error<> &) {
    }

    TestBoolSimpleAlloc::m_max_size = 10000;
  }
}

TEST(vector_bool, make_vector_size_alloc) {
  static_cast<void>(test_info_);

  TestUIntAlloc alloc{3};
  {
    auto result = ::portable_stl::vector<bool, TestBoolAlloc>::make_vector(0, alloc);
    ASSERT_TRUE(result);

    auto vec = result.value();
    EXPECT_EQ(0, vec.size());
    EXPECT_EQ(3, vec.get_allocator().get_data());
  }
  {
    auto result = ::portable_stl::vector<bool, TestBoolAlloc>::make_vector(3, alloc);
    ASSERT_TRUE(result);

    auto vec = result.value();
    ASSERT_EQ(3, vec.size());
    EXPECT_EQ(3, vec.get_allocator().get_data());
    for (::portable_stl::size_t i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(false, vec[i]);
    }
  }

  // bad allocation (zero size) - no error
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    TestUIntAlloc alloc1{3, &stat};

    auto result = ::portable_stl::vector<bool, TestBoolAlloc>::make_vector(0, alloc1);
    ASSERT_TRUE(result);

    auto vec = result.value();
    EXPECT_EQ(3, vec.get_allocator().get_data());
    EXPECT_EQ(0, vec.size());
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    TestUIntAlloc alloc1{&stat};

    auto result = ::portable_stl::vector<bool, TestBoolAlloc>::make_vector(3, alloc1);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }

  // too much
  {
    TestUIntSimpleAlloc alloc2;

    TestUIntSimpleAlloc::m_max_size              = 5;
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    auto result = ::portable_stl::vector<bool, TestBoolSimpleAlloc>::make_vector(11 * 32, alloc2);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    TestUIntSimpleAlloc::m_max_size = 10000;
  }
}

TEST(vector_bool, constructor_size_value) {
  static_cast<void>(test_info_);

  {
    /**
     * @brief Vector alias.
     */
    using t_vector = ::portable_stl::vector<bool>;

    typename t_vector::size_type orig_size{50};

    t_vector vec(orig_size, true);

    EXPECT_EQ(vec.size(), orig_size);
    for (typename t_vector::const_iterator i{vec.cbegin()}, e{vec.cend()}; i != e; ++i) {
      EXPECT_EQ(true, *i);
    }
  }

  // no bad allocation (zero size)
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;

    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(0, true);
    EXPECT_EQ(0, vec.size());
  }

  // bad allocation
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;

    try {
      ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(2, true);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }

  // reaching max_size
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    TestUIntSimpleAlloc::m_max_size              = 5;
    try {
      ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(11 * 32, true);
      ASSERT_TRUE(false);
    } catch (::portable_stl::length_error<> &) {
    }

    TestUIntSimpleAlloc::m_max_size = 10000;
  }
}

TEST(vector_bool, make_vector_size_value) {
  static_cast<void>(test_info_);

  {
    auto result = ::portable_stl::vector<bool>::make_vector(0, true);
    ASSERT_TRUE(result);

    auto vec = result.value();
    EXPECT_EQ(0, vec.size());
  }
  {
    auto result = ::portable_stl::vector<bool>::make_vector(3, true);
    ASSERT_TRUE(result);

    auto vec = result.value();
    ASSERT_EQ(3, vec.size());
    for (::portable_stl::size_t i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(true, vec[i]);
    }
  }

  // bad allocation (zero size) - no error
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;

    auto result = ::portable_stl::vector<bool, TestBoolSimpleAlloc>::make_vector(0, true);
    ASSERT_TRUE(result);

    auto vec = result.value();
    EXPECT_EQ(0, vec.size());
  }

  // bad allocation
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;

    auto result = ::portable_stl::vector<bool, TestBoolSimpleAlloc>::make_vector(3, true);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }

  // reaching max_size
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    TestUIntSimpleAlloc::m_max_size              = 5;

    auto result = ::portable_stl::vector<bool, TestBoolSimpleAlloc>::make_vector(11 * 32, true);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    TestUIntSimpleAlloc::m_max_size = 10000;
  }
}

TEST(vector_bool, constructor_size_value_alloc) {
  static_cast<void>(test_info_);

  {
    /**
     * @brief Vector alias.
     */
    using t_vector = ::portable_stl::vector<bool, TestBoolAlloc>;
    TestUIntAlloc                alloc(3);
    typename t_vector::size_type orig_size{50};

    t_vector vec(orig_size, true, alloc);
    ASSERT_EQ(orig_size, vec.size());
    ASSERT_EQ(3, vec.get_allocator().get_data());
    for (typename t_vector::const_iterator i{vec.cbegin()}, e{vec.cend()}; i != e; ++i) {
      ASSERT_EQ(*i, true);
    }
  }

  // no bad allocation (zero size)
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    TestUIntAlloc alloc{3, &stat};

    ::portable_stl::vector<bool, TestBoolAlloc> vec(0, true, alloc);
    ASSERT_EQ(3, vec.get_allocator().get_data());
    EXPECT_EQ(0, vec.size());
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    TestUIntAlloc alloc{&stat};

    try {
      ::portable_stl::vector<bool, TestBoolAlloc> vec(3, true, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }

  // reaching max_size
  {
    TestUIntSimpleAlloc alloc;

    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    TestUIntSimpleAlloc::m_max_size              = 5;
    try {
      ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(11 * 32, true, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::length_error<> &) {
    }

    TestBoolSimpleAlloc::m_max_size = 10000;
  }
}

TEST(vector_bool, make_vector_size_value_alloc) {
  static_cast<void>(test_info_);

  TestUIntAlloc alloc{3};
  {
    auto result = ::portable_stl::vector<bool, TestBoolAlloc>::make_vector(0, true, alloc);
    ASSERT_TRUE(result);

    auto vec = result.value();
    EXPECT_EQ(0, vec.size());
    EXPECT_EQ(3, vec.get_allocator().get_data());
  }
  {
    auto result = ::portable_stl::vector<bool, TestBoolAlloc>::make_vector(3, true, alloc);
    ASSERT_TRUE(result);

    auto vec = result.value();
    ASSERT_EQ(3, vec.size());
    EXPECT_EQ(3, vec.get_allocator().get_data());
    for (::portable_stl::size_t i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(true, vec[i]);
    }
  }

  // bad allocation (zero size) - no error
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    TestUIntAlloc alloc1{3, &stat};

    auto result = ::portable_stl::vector<bool, TestBoolAlloc>::make_vector(0, true, alloc1);
    ASSERT_TRUE(result);

    auto vec = result.value();
    EXPECT_EQ(3, vec.get_allocator().get_data());
    EXPECT_EQ(0, vec.size());
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    TestUIntAlloc alloc1{&stat};

    auto result = ::portable_stl::vector<bool, TestBoolAlloc>::make_vector(10, true, alloc1);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }

  // reaching max_size
  {
    TestUIntSimpleAlloc alloc2;

    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    TestUIntSimpleAlloc::m_max_size              = 5;

    auto result = ::portable_stl::vector<bool, TestBoolSimpleAlloc>::make_vector(11 * 32, true, alloc2);
    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    TestUIntSimpleAlloc::m_max_size = 10000;
  }
}

TEST(vector_bool, constructor_iter_iter) {
  static_cast<void>(test_info_);

  bool  a[] = {true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false};
  bool *an  = a + sizeof(a) / sizeof(a[0]);

  {
    test_vector_helper::ctor_iter_iter<::portable_stl::vector<bool>>(
      test_iterator_helper::tst_input_iterator<bool const *>(a),
      test_iterator_helper::tst_input_iterator<bool const *>(an));

    test_vector_helper::ctor_iter_iter<::portable_stl::vector<bool>>(
      test_iterator_helper::tst_forward_iterator<bool const *>(a),
      test_iterator_helper::tst_forward_iterator<bool const *>(an));

    test_vector_helper::ctor_iter_iter<::portable_stl::vector<bool>>(
      test_iterator_helper::tst_bidirectional_iterator<bool const *>(a),
      test_iterator_helper::tst_bidirectional_iterator<bool const *>(an));

    test_vector_helper::ctor_iter_iter<::portable_stl::vector<bool>>(
      test_iterator_helper::tst_random_access_iterator<bool const *>(a),
      test_iterator_helper::tst_random_access_iterator<bool const *>(an));

    test_vector_helper::ctor_iter_iter<::portable_stl::vector<bool>>(a, an);
  }

  // no bad allocation (zero size) tst_forward_iterator
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;

    bool  a2[] = {0};
    bool *a2n  = a2;

    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec{
      test_iterator_helper::tst_forward_iterator<bool const *>(a2),
      test_iterator_helper::tst_forward_iterator<bool const *>(a2n)};
    EXPECT_EQ(0, vec.size());
  }

  // bad allocation tst_forward_iterator
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;

    try {
      ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec{
        test_iterator_helper::tst_forward_iterator<bool const *>(a),
        test_iterator_helper::tst_forward_iterator<bool const *>(an)};
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }

  // reaching max_size tst_forward_iterator
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    TestUIntSimpleAlloc::m_max_size              = 1;

    try {
      ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec{
        test_iterator_helper::tst_forward_iterator<bool const *>(a),
        test_iterator_helper::tst_forward_iterator<bool const *>(an)};
      ASSERT_TRUE(false);
    } catch (::portable_stl::length_error<> &) {
    }

    TestUIntSimpleAlloc::m_max_size = 10000;
  }

  // no bad allocation (zero size) tst_input_iterator
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;

    bool  a2[] = {0};
    bool *a2n  = a2;

    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec{test_iterator_helper::tst_input_iterator<bool const *>(a2),
                                                          test_iterator_helper::tst_input_iterator<bool const *>(a2n)};
    EXPECT_EQ(0, vec.size());
  }

  // bad allocation tst_input_iterator
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;

    try {
      ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec{test_iterator_helper::tst_input_iterator<bool const *>(a),
                                                            test_iterator_helper::tst_input_iterator<bool const *>(an)};
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }

  // reaching max_size tst_input_iterator
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    TestUIntSimpleAlloc::m_max_size              = 1;

    try {
      ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec{test_iterator_helper::tst_input_iterator<bool const *>(a),
                                                            test_iterator_helper::tst_input_iterator<bool const *>(an)};
      ASSERT_TRUE(false);
    } catch (::portable_stl::length_error<> &) {
    }

    TestUIntSimpleAlloc::m_max_size = 10000;
  }
}

TEST(vector_bool, make_vector_iter_iter) {
  static_cast<void>(test_info_);

  bool  a[] = {true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false};
  bool *an  = a + sizeof(a) / sizeof(a[0]);

  // OK input_iterator, size 0
  {
    auto result = ::portable_stl::vector<bool>::make_vector(test_iterator_helper::tst_input_iterator<bool const *>(a),
                                                            test_iterator_helper::tst_input_iterator<bool const *>(a));

    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_TRUE(vec.empty());
  }

  // OK input_iterator, size >0
  {
    auto result = ::portable_stl::vector<bool>::make_vector(test_iterator_helper::tst_input_iterator<bool const *>(a),
                                                            test_iterator_helper::tst_input_iterator<bool const *>(an));

    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_EQ(sizeof(a) / sizeof(a[0]), vec.size());
  }

  // OK forward_iterator, size 0
  {
    auto result
      = ::portable_stl::vector<bool>::make_vector(test_iterator_helper::tst_forward_iterator<bool const *>(a),
                                                  test_iterator_helper::tst_forward_iterator<bool const *>(a));

    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_TRUE(vec.empty());
  }

  // OK forward_iterator, size >0
  {
    auto result
      = ::portable_stl::vector<bool>::make_vector(test_iterator_helper::tst_forward_iterator<bool const *>(a),
                                                  test_iterator_helper::tst_forward_iterator<bool const *>(an));

    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_EQ(sizeof(a) / sizeof(a[0]), vec.size());
  }

  // bad allocation input_iterator
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 1;

    auto result = ::portable_stl::vector<bool, TestBoolSimpleAlloc>::make_vector(
      test_iterator_helper::tst_input_iterator<bool const *>(a),
      test_iterator_helper::tst_input_iterator<bool const *>(an));

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }

  // bad allocation forward_iterator
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;

    auto result = ::portable_stl::vector<bool, TestBoolSimpleAlloc>::make_vector(
      test_iterator_helper::tst_forward_iterator<bool const *>(a),
      test_iterator_helper::tst_forward_iterator<bool const *>(an));

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }

  // reaching max_size forward_iterator
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    TestUIntSimpleAlloc::m_max_size              = 1;

    auto result = ::portable_stl::vector<bool, TestBoolSimpleAlloc>::make_vector(
      test_iterator_helper::tst_forward_iterator<bool const *>(a),
      test_iterator_helper::tst_forward_iterator<bool const *>(an));

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    TestUIntSimpleAlloc::m_max_size = 10000;
  }

  // reaching max_size input_iterator
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    TestUIntSimpleAlloc::m_max_size              = 1;

    auto result = ::portable_stl::vector<bool, TestBoolSimpleAlloc>::make_vector(
      test_iterator_helper::tst_input_iterator<bool const *>(a),
      test_iterator_helper::tst_input_iterator<bool const *>(an));

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    TestUIntSimpleAlloc::m_max_size = 10000;
  }
}

TEST(vector_bool, constructor_iter_iter_alloc) {
  static_cast<void>(test_info_);

  bool  a[] = {true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false};
  bool *an  = a + sizeof(a) / sizeof(a[0]);

  {
    TestUIntAlloc alloc{3};

    test_vector_helper::ctor_iter_iter_alloc<::portable_stl::vector<bool, TestBoolAlloc>>(
      test_iterator_helper::tst_input_iterator<bool const *>(a),
      test_iterator_helper::tst_input_iterator<bool const *>(an),
      alloc);

    test_vector_helper::ctor_iter_iter_alloc<::portable_stl::vector<bool, TestBoolAlloc>>(
      test_iterator_helper::tst_forward_iterator<bool const *>(a),
      test_iterator_helper::tst_forward_iterator<bool const *>(an),
      alloc);

    test_vector_helper::ctor_iter_iter_alloc<::portable_stl::vector<bool, TestBoolAlloc>>(
      test_iterator_helper::tst_bidirectional_iterator<bool const *>(a),
      test_iterator_helper::tst_bidirectional_iterator<bool const *>(an),
      alloc);

    test_vector_helper::ctor_iter_iter_alloc<::portable_stl::vector<bool, TestBoolAlloc>>(
      test_iterator_helper::tst_random_access_iterator<bool const *>(a),
      test_iterator_helper::tst_random_access_iterator<bool const *>(an),
      alloc);

    test_vector_helper::ctor_iter_iter_alloc<::portable_stl::vector<bool, TestBoolAlloc>>(a, an, alloc);
  }

  // bad allocation tst_input_iterator
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 1;
    TestUIntSimpleAlloc alloc;

    try {
      ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec{test_iterator_helper::tst_input_iterator<bool const *>(a),
                                                            test_iterator_helper::tst_input_iterator<bool const *>(an),
                                                            alloc};
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }

  // bad allocation tst_forward_iterator
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;
    TestUIntSimpleAlloc alloc;

    try {
      ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec{
        test_iterator_helper::tst_forward_iterator<bool const *>(a),
        test_iterator_helper::tst_forward_iterator<bool const *>(an),
        alloc};
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }

  // max_size tst_input_iterator
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    TestUIntSimpleAlloc::m_max_size              = 1;
    TestUIntSimpleAlloc alloc;

    try {
      ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec{test_iterator_helper::tst_input_iterator<bool const *>(a),
                                                            test_iterator_helper::tst_input_iterator<bool const *>(an),
                                                            alloc};
      ASSERT_TRUE(false);
    } catch (::portable_stl::length_error<> &) {
    }

    TestUIntSimpleAlloc::m_max_size = 10000;
  }

  // max_size tst_forward_iterator
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    TestUIntSimpleAlloc::m_max_size              = 1;
    TestUIntSimpleAlloc alloc;

    try {
      ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec{
        test_iterator_helper::tst_forward_iterator<bool const *>(a),
        test_iterator_helper::tst_forward_iterator<bool const *>(an),
        alloc};
      ASSERT_TRUE(false);
    } catch (::portable_stl::length_error<> &) {
    }

    TestUIntSimpleAlloc::m_max_size = 10000;
  }
}

TEST(vector_bool, make_vector_iter_iter_alloc) {
  static_cast<void>(test_info_);

  bool  a[] = {true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
               true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false};
  bool *an  = a + sizeof(a) / sizeof(a[0]);
  TestUIntAlloc alloc{3};

  // OK input_iterator, size 0
  {
    auto result = ::portable_stl::vector<bool, TestBoolAlloc>::make_vector(
      test_iterator_helper::tst_input_iterator<bool const *>(a),
      test_iterator_helper::tst_input_iterator<bool const *>(a),
      alloc);

    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_TRUE(vec.empty());
    EXPECT_EQ(3, vec.get_allocator().get_data());
  }

  // OK input_iterator, size >0
  {
    auto result = ::portable_stl::vector<bool, TestBoolAlloc>::make_vector(
      test_iterator_helper::tst_input_iterator<bool const *>(a),
      test_iterator_helper::tst_input_iterator<bool const *>(an),
      alloc);

    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_EQ(sizeof(a) / sizeof(a[0]), vec.size());
    EXPECT_EQ(3, vec.get_allocator().get_data());
  }

  // OK forward_iterator, size 0
  {
    auto result = ::portable_stl::vector<bool, TestBoolAlloc>::make_vector(
      test_iterator_helper::tst_forward_iterator<bool const *>(a),
      test_iterator_helper::tst_forward_iterator<bool const *>(a),
      alloc);

    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_TRUE(vec.empty());
    EXPECT_EQ(3, vec.get_allocator().get_data());
  }

  // OK forward_iterator, size >0
  {
    auto result = ::portable_stl::vector<bool, TestBoolAlloc>::make_vector(
      test_iterator_helper::tst_forward_iterator<bool const *>(a),
      test_iterator_helper::tst_forward_iterator<bool const *>(an),
      alloc);

    ASSERT_TRUE(result);
    auto vec = result.value();
    EXPECT_EQ(sizeof(a) / sizeof(a[0]), vec.size());
    EXPECT_EQ(3, vec.get_allocator().get_data());
  }

  // reaching max_size forward_iterator
  {
    TestUIntSimpleAlloc alloc2;

    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    TestUIntSimpleAlloc::m_max_size              = 1;

    auto result = ::portable_stl::vector<bool, TestBoolSimpleAlloc>::make_vector(
      test_iterator_helper::tst_forward_iterator<bool const *>(a),
      test_iterator_helper::tst_forward_iterator<bool const *>(an),
      alloc2);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    TestUIntSimpleAlloc::m_max_size = 10000;
  }

  // reaching max_size input_iterator
  {
    TestUIntSimpleAlloc alloc2;

    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    TestUIntSimpleAlloc::m_max_size              = 1;

    auto result = ::portable_stl::vector<bool, TestBoolSimpleAlloc>::make_vector(
      test_iterator_helper::tst_input_iterator<bool const *>(a),
      test_iterator_helper::tst_input_iterator<bool const *>(an),
      alloc2);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    TestUIntSimpleAlloc::m_max_size = 10000;
  }
}

TEST(vector_bool, constructor_initializer_list) {
  static_cast<void>(test_info_);

  // ok
  {
    ::portable_stl::vector<bool> vec{true, false, true, false, true, false};
    ASSERT_EQ(6, vec.size());
    for (::portable_stl::size_t i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(static_cast<bool>((i + 1) % 2), vec[i]);
    }
  }

  // bad allocation
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;

    try {
      ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec{true, false, true, false, true, false};
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }

  // max_size
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    TestUIntSimpleAlloc::m_max_size              = 1;

    try {
      ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec{
        true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
        true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
        true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
        true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
        true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
        true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
        true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
        true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false};
      ASSERT_TRUE(false);
    } catch (::portable_stl::length_error<> &) {
    }

    TestUIntSimpleAlloc::m_max_size = 10000;
  }
}

TEST(vector_bool, make_vector_initializer_list) {
  static_cast<void>(test_info_);

  // ok
  {
    auto result = ::portable_stl::vector<bool>::make_vector({true, false, true, false, true, false});
    ASSERT_TRUE(result);

    auto vec = result.value();
    ASSERT_EQ(6, vec.size());
    for (::portable_stl::size_t i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(static_cast<bool>((i + 1) % 2), vec[i]);
    }
  }

  // bad allocation
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;

    auto result
      = ::portable_stl::vector<bool, TestBoolSimpleAlloc>::make_vector({true, false, true, false, true, false});

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }

  // max_size
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    TestUIntSimpleAlloc::m_max_size              = 1;

    auto result = ::portable_stl::vector<bool, TestBoolSimpleAlloc>::make_vector(
      {true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
       true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
       true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
       true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
       true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
       true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
       true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
       true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false});

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    TestUIntSimpleAlloc::m_max_size = 10000;
  }
}

TEST(vector_bool, constructor_initializer_list_alloc) {
  static_cast<void>(test_info_);

  // ok
  {
    TestUIntAlloc alloc(3);

    ::portable_stl::vector<bool, TestBoolAlloc> vec({true, false, true, false, true, false}, alloc);
    ASSERT_EQ(6, vec.size());
    ASSERT_EQ(3, vec.get_allocator().get_data());
    for (::portable_stl::size_t i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(static_cast<bool>((i + 1) % 2), vec[i]);
    }
  }

  // bad allocation
  {
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 0;
    TestUIntAlloc alloc1{&stat};

    try {
      ::portable_stl::vector<bool, TestBoolAlloc> vec({true, false, true, false, true, false}, alloc1);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
  }

  // max_size
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    TestUIntSimpleAlloc::m_max_size              = 1;
    TestUIntSimpleAlloc alloc2;

    try {
      ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(
        {true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
         true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
         true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
         true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
         true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
         true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
         true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
         true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false},
        alloc2);
      ASSERT_TRUE(false);
    } catch (::portable_stl::length_error<> &) {
    }

    TestUIntSimpleAlloc::m_max_size = 10000;
  }
}

TEST(vector_bool, make_vector_initializer_list_alloc) {
  static_cast<void>(test_info_);

  // ok
  {
    TestUIntAlloc alloc(3);

    auto result
      = ::portable_stl::vector<bool, TestBoolAlloc>::make_vector({true, false, true, false, true, false}, alloc);
    ASSERT_TRUE(result);

    auto vec = result.value();
    ASSERT_EQ(6, vec.size());
    ASSERT_EQ(3, vec.get_allocator().get_data());
    for (::portable_stl::size_t i{0}; i < vec.size(); ++i) {
      EXPECT_EQ(static_cast<bool>((i + 1) % 2), vec[i]);
    }
  }

  TestUIntSimpleAlloc alloc2;

  // bad allocation
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;

    auto result
      = ::portable_stl::vector<bool, TestBoolSimpleAlloc>::make_vector({true, false, true, false, true, false}, alloc2);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }

  // max_size
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    TestUIntSimpleAlloc::m_max_size              = 1;

    auto result = ::portable_stl::vector<bool, TestBoolSimpleAlloc>::make_vector(
      {true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
       true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
       true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
       true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
       true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
       true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
       true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
       true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false},
      alloc2);

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());

    TestUIntSimpleAlloc::m_max_size = 10000;
  }
}

TEST(vector_bool, constructor_copy) {
  static_cast<void>(test_info_);
  {
    bool a[] = {true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false};
    bool *an = a + sizeof(a) / sizeof(a[0]);
    test_vector_helper::test_constructor_copy(::portable_stl::vector<bool>(a, an));
  }
  {
    ::portable_stl::vector<bool, TestBoolAlloc> vec0(3, 2, TestBoolAlloc(5));
    ::portable_stl::vector<bool, TestBoolAlloc> vec = vec0;
    EXPECT_EQ(vec0, vec);
    EXPECT_EQ(vec.get_allocator(), vec0.get_allocator());
  }

  // Test copy ctor with empty source
  {
    ::portable_stl::vector<bool, TestBoolAlloc> vec0(TestBoolAlloc(5));
    ::portable_stl::vector<bool, TestBoolAlloc> vec = vec0;
    EXPECT_EQ(vec0, vec);
    EXPECT_EQ(vec.get_allocator(), vec0.get_allocator());
    EXPECT_TRUE(vec.empty());
  }

  // bad allocation
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec0{true, false, true, false, true, false};

    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;
    try {
      ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec = vec0;
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }

    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
  }
}

TEST(vector_bool, make_vector_lvalue_vector) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::vector<bool> vec0{true, false, true, false, true, false};
    auto                         result = ::portable_stl::vector<bool>::make_vector(vec0);
    ASSERT_TRUE(result);

    auto vec = result.value();
    EXPECT_EQ(vec0, vec);
    EXPECT_EQ(vec.get_allocator(), vec0.get_allocator());
  }

  // bad allocation
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec0{true, false, true, false, true, false};

    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;
    auto result                                  = ::portable_stl::vector<bool, TestBoolSimpleAlloc>::make_vector(vec0);
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }

  // max_size
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec0{
      true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
      true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
      true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
      true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
      true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
      true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
      true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
      true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false};

    TestUIntSimpleAlloc::m_max_size = 1;
    auto result                     = ::portable_stl::vector<bool, TestBoolSimpleAlloc>::make_vector(vec0);
    TestUIntSimpleAlloc::m_max_size = 10000;

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());
  }
}

TEST(vector_bool, constructor_copy_alloc) {
  static_cast<void>(test_info_);
  {
    bool a[] = {true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false};
    bool *an = a + sizeof(a) / sizeof(a[0]);
    test_vector_helper::test_constructor_copy_alloc(::portable_stl::vector<bool>(a, an),
                                                    ::portable_stl::allocator<bool>());
  }
  {
    ::portable_stl::vector<bool, TestBoolAlloc> vec0(3, false, TestBoolAlloc(5));
    ::portable_stl::vector<bool, TestBoolAlloc> vec(vec0, TestBoolAlloc(3));
    EXPECT_EQ(vec0, vec);
    EXPECT_EQ(vec.get_allocator(), TestBoolAlloc(3));
  }

  // Test copy ctor with empty source
  {
    ::portable_stl::vector<bool, TestBoolAlloc> vec0(TestBoolAlloc(5));
    ::portable_stl::vector<bool, TestBoolAlloc> vec(vec0, TestBoolAlloc(3));
    EXPECT_TRUE(vec.empty());
    EXPECT_EQ(vec0, vec);
    EXPECT_EQ(vec.get_allocator(), TestBoolAlloc(3));
  }

  // bad allocation
  {
    TestUIntSimpleAlloc alloc;
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec0{true, false, true, false, true, false};

    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;
    try {
      ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(vec0, alloc);
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }

    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
  }
}

TEST(vector_bool, make_vector_lvalue_vector_alloc) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::vector<bool, TestBoolAlloc> vec0({true, false, true, false, true, false}, TestBoolAlloc(5));
    auto result = ::portable_stl::vector<bool, TestBoolAlloc>::make_vector(vec0, TestBoolAlloc(3));
    ASSERT_TRUE(result);

    auto vec = result.value();
    EXPECT_EQ(vec0, vec);
    EXPECT_EQ(TestBoolAlloc(3), vec.get_allocator());
  }

  TestUIntSimpleAlloc alloc2;

  // bad allocation
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec0({true, false, true, false, true, false},
                                                           TestUIntSimpleAlloc{});

    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;
    auto result = ::portable_stl::vector<bool, TestBoolSimpleAlloc>::make_vector(vec0, alloc2);
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());
  }

  // max_size
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec0(
      {true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
       true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
       true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
       true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
       true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
       true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
       true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false,
       true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false},
      TestUIntSimpleAlloc{});

    TestUIntSimpleAlloc::m_max_size = 1;
    auto result                     = ::portable_stl::vector<bool, TestBoolSimpleAlloc>::make_vector(vec0, alloc2);
    TestUIntSimpleAlloc::m_max_size = 10000;

    ASSERT_FALSE(result);
    EXPECT_EQ(::portable_stl::portable_stl_error::length_error, result.error());
  }
}

TEST(vector_bool, constructor_move_alloc) {
  static_cast<void>(test_info_);

  TestBoolAlloc alloc(5);

  // same alloc - pure move
  {
    ::portable_stl::vector<bool, TestBoolAlloc> vec0(3, false, alloc);
    ::portable_stl::vector<bool, TestBoolAlloc> vec_ref(vec0);

    ::portable_stl::vector<bool, TestBoolAlloc> vec(std::move(vec0), alloc);

    EXPECT_EQ(vec_ref, vec);
    EXPECT_EQ(vec_ref.get_allocator(), vec.get_allocator());
    EXPECT_EQ(0, vec0.size());
  }

  // diff alloc, zero size - do nothing inside constructor
  {
    ::portable_stl::vector<bool, TestBoolAlloc> vec0(TestBoolAlloc(3));

    ::portable_stl::vector<bool, TestBoolAlloc> vec(std::move(vec0), alloc);

    EXPECT_TRUE(vec.empty());
    EXPECT_EQ(vec.get_allocator().get_data(), alloc.get_data());
  }

  // diff alloc, non zero
  {
    ::portable_stl::vector<bool, TestBoolAlloc> vec0(3, true, TestBoolAlloc(3));
    ::portable_stl::vector<bool, TestBoolAlloc> vec_ref(vec0);

    ::portable_stl::vector<bool, TestBoolAlloc> vec(std::move(vec0), alloc);

    EXPECT_EQ(vec_ref, vec);
    EXPECT_NE(vec_ref.get_allocator(), vec.get_allocator());
    EXPECT_NE(0, vec0.size());
  }

  // diff alloc, bad alloc
  {
    TestUIntSimpleAlloc::m_counter_ok_allocation = 100;
    ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec0(3, true, TestUIntSimpleAlloc(3));

    TestUIntSimpleAlloc::m_counter_ok_allocation = 0;
    try {
      ::portable_stl::vector<bool, TestBoolSimpleAlloc> vec(std::move(vec0), TestBoolSimpleAlloc(5));
      ASSERT_TRUE(false);
    } catch (::portable_stl::bad_alloc<> &) {
    }
    TestUIntSimpleAlloc::m_counter_ok_allocation = 1000;
  }
}
