// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="list_modifiers.cpp"
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
#include "portable_stl/iterator/move_iterator.h"
#include "portable_stl/list/list.h"

namespace test_list_helper {
// Flag that makes the copy constructor for CMyClass throw an exception
static bool gCopyConstructorShouldThrow = false;

class CMyClass final {
public:
  CMyClass();
  CMyClass(CMyClass const &iOther);
  ~CMyClass();

private:
  std::int32_t        fMagicValue;
  static std::int32_t kStartedConstructionMagicValue;
  static std::int32_t kFinishedConstructionMagicValue;
};

// Value for fMagicValue when the constructor has started running, but not yet finished
std::int32_t CMyClass::kStartedConstructionMagicValue  = 0;
// Value for fMagicValue when the constructor has finished running
std::int32_t CMyClass::kFinishedConstructionMagicValue = 12345;

CMyClass::CMyClass() : fMagicValue(kStartedConstructionMagicValue) {
  // Signal that the constructor has finished running
  fMagicValue = kFinishedConstructionMagicValue;
}

CMyClass::CMyClass(CMyClass const & /*iOther*/) : fMagicValue(kStartedConstructionMagicValue) {
  // If requested, throw an exception _before_ setting fMagicValue to kFinishedConstructionMagicValue
  if (gCopyConstructorShouldThrow) {
    throw 1;
  }
  // Signal that the constructor has finished running
  fMagicValue = kFinishedConstructionMagicValue;
}

CMyClass::~CMyClass() {
  // Only instances for which the constructor has finished running should be destructed
  assert(fMagicValue == kFinishedConstructionMagicValue);
}
} // namespace test_list_helper

// void clear() noexcept;
TEST(list, clear) {
  static_cast<void>(test_info_);

  ::portable_stl::list<std::int32_t> lst{1, 2, 3};
  ASSERT_FALSE(lst.empty());

  lst.clear();
  ASSERT_TRUE(lst.empty());

  ASSERT_NO_THROW(lst.clear());
}

// [push_back/front]

// void push_back(const value_type& x);
TEST(list, push_back_lvalue) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::list<std::int32_t> lst;
    for (std::int32_t i{0}; i < 5; ++i) {
      ASSERT_TRUE(lst.push_back(i));
    }

    ASSERT_EQ((::portable_stl::list<std::int32_t>{0, 1, 2, 3, 4}), lst);
  }

  // bad construction
  {
    test_list_helper::CMyClass                       instance;
    ::portable_stl::list<test_list_helper::CMyClass> lst;

    lst.push_back(instance);

    test_list_helper::gCopyConstructorShouldThrow = true;
    try {
      lst.push_back(instance);
      ASSERT_TRUE(false);
    } catch (std::int32_t &) {
    }

    test_list_helper::gCopyConstructorShouldThrow = false;
  }

  // bad allocation
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 5 + 2;
    t_allocator                                     alloc(&stat);
    std::int32_t                                    arr[] = {0, 1, 2, 3, 4};
    ::portable_stl::list<std::int32_t, t_allocator> lst(arr, arr + (sizeof(arr) / sizeof(arr[0])), alloc);

    std::int32_t value{5};
    ASSERT_TRUE(lst.push_back(value));

    value = 6;
    ASSERT_TRUE(lst.push_back(value));

    value       = 7;
    auto result = lst.push_back(value);

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    /* Strong exception guarantee*/
    ASSERT_EQ(7, lst.size());
    ASSERT_EQ(6, lst.back());
  }
}

// void push_back(value_type&& x);
TEST(list, push_back_rvalue) {
  static_cast<void>(test_info_);

  /**
   * @brief Move only alias.
   */
  using t_move_only = test_common_helper::MoveOnly;

  {
    ::portable_stl::list<t_move_only> lst;
    lst.push_back(t_move_only(1));
    ASSERT_EQ(1, lst.size());
    ASSERT_EQ(t_move_only(1), lst.front());

    lst.push_back(t_move_only(2));
    ASSERT_EQ(2, lst.size());
    ASSERT_EQ(t_move_only(1), lst.front());
    ASSERT_EQ(t_move_only(2), lst.back());
  }

  // bad allocation
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<t_move_only>;
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 5 + 2;
    t_allocator alloc(&stat);
    t_move_only arr[] = {t_move_only(0), t_move_only(1), t_move_only(2), t_move_only(3), t_move_only(4)};
    ::portable_stl::list<t_move_only, t_allocator> lst(
      ::portable_stl::move_iterator<t_move_only *>(arr),
      ::portable_stl::move_iterator<t_move_only *>(arr + (sizeof(arr) / sizeof(arr[0]))),
      alloc);

    ASSERT_TRUE(lst.push_back(t_move_only(5)));

    ASSERT_TRUE(lst.push_back(t_move_only(6)));

    auto result = lst.push_back(t_move_only(7));

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    /* Strong exception guarantee*/
    ASSERT_EQ(7, lst.size());
    ASSERT_EQ(t_move_only(6), lst.back());
  }
}

// void push_front(const value_type& x);
TEST(list, push_front_lvalue) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::list<std::int32_t> lst;
    for (std::int32_t i{0}; i < 5; ++i) {
      ASSERT_TRUE(lst.push_front(i));
    }

    ASSERT_EQ((::portable_stl::list<std::int32_t>{4, 3, 2, 1, 0}), lst);
  }

  // bad construction
  {
    test_list_helper::CMyClass                       instance;
    ::portable_stl::list<test_list_helper::CMyClass> lst;

    lst.push_front(instance);

    test_list_helper::gCopyConstructorShouldThrow = true;
    try {
      lst.push_front(instance);
      ASSERT_TRUE(false);
    } catch (std::int32_t &) {
    }

    test_list_helper::gCopyConstructorShouldThrow = false;
  }

  // bad allocation
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 5 + 2;
    t_allocator                                     alloc(&stat);
    ::portable_stl::list<std::int32_t, t_allocator> lst({4, 3, 2, 1, 0}, alloc);

    std::int32_t value{5};
    ASSERT_TRUE(lst.push_front(value));

    value = 6;
    ASSERT_TRUE(lst.push_front(value));

    value       = 7;
    auto result = lst.push_front(value);

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    /* Strong exception guarantee*/
    ASSERT_EQ(7, lst.size());
    ASSERT_EQ(6, lst.front());
  }
}

// void push_front(value_type&& x);
TEST(list, push_front_rvalue) {
  static_cast<void>(test_info_);

  /**
   * @brief Move only alias.
   */
  using t_move_only = test_common_helper::MoveOnly;

  {
    ::portable_stl::list<t_move_only> lst;
    lst.push_front(t_move_only(1));
    ASSERT_EQ(1, lst.size());
    ASSERT_EQ(t_move_only(1), lst.front());

    lst.push_front(t_move_only(2));
    ASSERT_EQ(2, lst.size());
    ASSERT_EQ(t_move_only(2), lst.front());
    ASSERT_EQ(t_move_only(1), lst.back());
  }

  // bad allocation
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<t_move_only>;
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 5 + 2;
    t_allocator alloc(&stat);
    t_move_only arr[] = {t_move_only(0), t_move_only(1), t_move_only(2), t_move_only(3), t_move_only(4)};
    ::portable_stl::list<t_move_only, t_allocator> lst(
      ::portable_stl::move_iterator<t_move_only *>(arr),
      ::portable_stl::move_iterator<t_move_only *>(arr + (sizeof(arr) / sizeof(arr[0]))),
      alloc);

    ASSERT_TRUE(lst.push_front(t_move_only(5)));

    ASSERT_TRUE(lst.push_front(t_move_only(6)));

    auto result = lst.push_front(t_move_only(7));

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    /* Strong exception guarantee*/
    ASSERT_EQ(7, lst.size());
    ASSERT_EQ(t_move_only(6), lst.front());
  }
}

// [insert]

// iterator insert(const_iterator position, const value_type& x);
TEST(list, insert_pos_value) {
  static_cast<void>(test_info_);

  {
    std::int32_t                       arr1[] = {1, 2, 3};
    std::int32_t                       arr2[] = {1, 4, 2, 3};
    ::portable_stl::list<std::int32_t> lst1(arr1, arr1 + (sizeof(arr1) / sizeof(arr1[0])));
    ::portable_stl::list<std::int32_t> lst_ref(arr2, arr2 + (sizeof(arr2) / sizeof(arr2[0])));

    std::int32_t value{4};
    auto         result = lst1.insert(::portable_stl::next(lst1.cbegin()), value);
    ASSERT_TRUE(result);
    auto iter = result.value();

    ASSERT_EQ(::portable_stl::next(lst1.cbegin()), iter);
    ASSERT_EQ(lst_ref, lst1);
  }

  // bad allocation (node creation)
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;
    test_allocator_helper::test_allocator_statistics stat;
    t_allocator                                      alloc(4, &stat);
    ::portable_stl::list<std::int32_t, t_allocator>  lst({1, 2, 3, 4}, alloc);
    auto                                             lst_ref = lst;

    stat.m_throw_after = 0;
    std::int32_t value{4};
    auto         result = lst.insert(::portable_stl::next(lst.cbegin()), value);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    /* Strong exception guarantee*/
    ASSERT_EQ(lst_ref, lst);
  }
}

// iterator insert(const_iterator position, value_type&& x);
TEST(list, insert_pos_rvalue) {
  static_cast<void>(test_info_);

  /**
   * @brief Move only alias.
   */
  using t_move_only = test_common_helper::MoveOnly;

  {
    ::portable_stl::list<t_move_only> lst;

    lst.insert(lst.cend(), t_move_only(1));
    ASSERT_EQ(1, lst.size());
    ASSERT_EQ(lst.front(), t_move_only(1));

    lst.insert(lst.cbegin(), t_move_only(2));
    ASSERT_EQ(2, lst.size());
    ASSERT_EQ(lst.front(), t_move_only(2));
    ASSERT_EQ(lst.back(), t_move_only(1));
  }

  // bad allocation
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<t_move_only>;
    test_allocator_helper::test_allocator_statistics stat;
    t_allocator                                      alloc(4, &stat);

    ::portable_stl::list<t_move_only, t_allocator> lst(alloc);

    auto result = lst.insert(lst.cend(), t_move_only(1));
    ASSERT_TRUE(result);
    ASSERT_EQ(1, lst.size());
    ASSERT_EQ(lst.front(), t_move_only(1));

    stat.m_throw_after = 0;
    result             = lst.insert(lst.cbegin(), t_move_only(2));
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    /* Strong exception guarantee*/
    ASSERT_EQ(1, lst.size());
    ASSERT_EQ(lst.front(), t_move_only(1));
    ASSERT_EQ(lst.back(), t_move_only(1));
  }
}

// iterator insert(const_iterator position, size_type n, const value_type& x);
TEST(list, insert_pos_count_value) {
  static_cast<void>(test_info_);

  {
    std::int32_t                       arr1[] = {1, 2, 3};
    std::int32_t                       arr2[] = {1, 4, 4, 4, 4, 4, 2, 3};
    ::portable_stl::list<std::int32_t> lst1(arr1, arr1 + (sizeof(arr1) / sizeof(arr1[0])));
    ::portable_stl::list<std::int32_t> lst_ref(arr2, arr2 + (sizeof(arr2) / sizeof(arr2[0])));

    auto result = lst1.insert(::portable_stl::next(lst1.cbegin()), 5, 4);
    ASSERT_TRUE(result);
    auto iter = result.value();

    ASSERT_EQ(::portable_stl::next(lst1.cbegin()), iter);
    ASSERT_EQ(lst_ref, lst1);
  }

  // bad allocation (node creation)
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;
    test_allocator_helper::test_allocator_statistics stat;
    t_allocator                                      alloc(4, &stat);
    ::portable_stl::list<std::int32_t, t_allocator>  lst({1, 2, 3, 4}, alloc);
    auto                                             lst_ref = lst;

    stat.m_throw_after = 3;
    auto result        = lst.insert(::portable_stl::next(lst.cbegin()), 4, 3);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    /* Strong exception guarantee*/
    ASSERT_EQ(lst_ref, lst);
  }
}

// template<t_input_iterator> iterator insert(const_iterator position, t_input_iterator first, t_input_iterator last);
TEST(list, insert_pos_iter_iter) {
  static_cast<void>(test_info_);

  std::int32_t                 arr[] = {1, 2, 3};
  ::portable_stl::size_t const arr_size{sizeof(arr) / sizeof(arr[0])};

  {
    ::portable_stl::list<std::int32_t> lst;
    auto                               result = lst.insert(lst.begin(),
                             test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
                             test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size));
    ASSERT_TRUE(result);
    auto iter = result.value();

    ASSERT_EQ(lst.begin(), iter);
    ASSERT_EQ(arr_size, lst.size());
    ASSERT_EQ(arr_size, ::portable_stl::distance(lst.begin(), lst.end()));

    auto iter_end = lst.cend();
    for (std::int32_t i{1}; iter != iter_end; ++iter, ++i) {
      ASSERT_EQ(i, *iter);
    }
    --iter;

    std::int32_t                 arr2[] = {4, 5, 6};
    ::portable_stl::size_t const arr2_size{sizeof(arr2) / sizeof(arr2[0])};

    result = lst.insert(iter,
                        test_iterator_helper::tst_input_iterator<std::int32_t *>(arr2),
                        test_iterator_helper::tst_input_iterator<std::int32_t *>(arr2 + arr2_size));
    ASSERT_TRUE(result);
    iter = result.value();

    ASSERT_EQ(4, *iter);
    ASSERT_EQ(arr_size + arr2_size, lst.size());
    ASSERT_EQ(arr_size + arr2_size, ::portable_stl::distance(lst.begin(), lst.end()));

    std::int32_t arr_ref[] = {1, 2, 4, 5, 6, 3};

    iter     = lst.begin();
    iter_end = lst.cend();
    for (std::size_t i{0U}; iter != iter_end; ++iter, ++i) {
      ASSERT_EQ(arr_ref[i], *iter);
    }
  }

  // bad allocation
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

    test_allocator_helper::test_allocator_statistics stat;
    t_allocator                                      alloc{&stat};

    ::portable_stl::list<std::int32_t, t_allocator> lst({1, 2, 3, 4, 5}, alloc);
    auto                                            lst_ref = lst;

    stat.m_throw_after = 2;
    auto result        = lst.insert(lst.begin(),
                             test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
                             test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size));
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    /* Strong exception guarantee*/
    ASSERT_EQ(lst_ref, lst);
  }
}

// iterator insert(const_iterator p, initializer_list<value_type> il);
TEST(list, insert_pos_init_list) {
  static_cast<void>(test_info_);

  ::portable_stl::list<std::int32_t> lst{1, 2, 3, 4, 5};

  auto result = lst.insert(::portable_stl::next(lst.begin(), 3), {6, 7, 8, 9, 0});
  ASSERT_TRUE(result);
  auto iter = result.value();

  ASSERT_EQ(::portable_stl::next(lst.begin(), 3), iter);
  ASSERT_EQ(10, lst.size());
  ASSERT_EQ(10, ::portable_stl::distance(lst.begin(), lst.end()));

  std::int32_t arr_ref[] = {1, 2, 3, 6, 7, 8, 9, 0, 4, 5};

  iter          = lst.begin();
  auto iter_end = lst.cend();
  for (std::size_t i{0U}; iter != iter_end; ++iter, ++i) {
    ASSERT_EQ(arr_ref[i], *iter);
  }
}

// [emplace]

namespace test_list_helper {
class type_for_emplace final {
  std::int32_t m_int;
  double       m_double;

public:
  type_for_emplace(std::int32_t i, double d) noexcept : m_int(i), m_double(d) {
  }

  type_for_emplace(type_for_emplace const &)            = delete;
  type_for_emplace &operator=(type_for_emplace const &) = delete;

  std::int32_t geti() const noexcept {
    return m_int;
  }
  double getd() const noexcept {
    return m_double;
  }
};
} // namespace test_list_helper

// template<class... t_args> iterator emplace(const_iterator pos, t_args &&...args);
TEST(list, emplace) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias.
   */
  using t_type = test_list_helper::type_for_emplace;

  {
    ::portable_stl::list<t_type> lst;

    auto result = lst.emplace(lst.begin(), 2, 3.5);
    ASSERT_TRUE(result);

    ASSERT_EQ(1, lst.size());
    ASSERT_EQ(2, lst.front().geti());
    ASSERT_EQ(3.5, lst.front().getd());

    result = lst.emplace(lst.cend(), 3, 4.5);
    ASSERT_TRUE(result);

    ASSERT_EQ(2, lst.front().geti());
    ASSERT_EQ(3.5, lst.front().getd());
    ASSERT_EQ(2, lst.size());
    ASSERT_EQ(3, lst.back().geti());
    ASSERT_EQ(4.5, lst.back().getd());
  }

  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<t_type>;

    test_allocator_helper::test_allocator_statistics stat;
    t_allocator                                      alloc{&stat};

    ::portable_stl::list<t_type, t_allocator> lst(alloc);
    lst.emplace(lst.begin(), 3, 3.5);
    lst.emplace(lst.begin(), 2, 2.5);
    lst.emplace(lst.begin(), 1, 1.5);

    stat.m_throw_after = 0;
    auto result        = lst.emplace(lst.begin(), 9, 9.5);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    /* Strong exception guarantee*/
    ASSERT_EQ(3, lst.size());
  }
}

// template<class... t_args> iterator emplace_back(t_args &&...args);
TEST(list, emplace_back) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias.
   */
  using t_type = test_list_helper::type_for_emplace;

  ::portable_stl::list<t_type> lst;

  auto result = lst.emplace_back(2, 3.5);
  ASSERT_TRUE(result);
  auto insert_ref = result.value();

  ASSERT_EQ(&lst.back(), &insert_ref.get());
  ASSERT_EQ(1, lst.size());
  ASSERT_EQ(2, lst.front().geti());
  ASSERT_EQ(3.5, lst.front().getd());

  result = lst.emplace_back(3, 4.5);
  ASSERT_TRUE(result);
  insert_ref = result.value();

  ASSERT_EQ(&lst.back(), &insert_ref.get());
  ASSERT_EQ(2, lst.front().geti());
  ASSERT_EQ(3.5, lst.front().getd());
  ASSERT_EQ(2, lst.size());
  ASSERT_EQ(3, lst.back().geti());
  ASSERT_EQ(4.5, lst.back().getd());
}

// template<class... t_args> iterator emplace_front(t_args &&...args);
TEST(list, emplace_front) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias.
   */
  using t_type = test_list_helper::type_for_emplace;

  ::portable_stl::list<t_type> lst;

  auto result = lst.emplace_front(2, 3.5);
  ASSERT_TRUE(result);
  auto insert_ref = result.value();

  ASSERT_EQ(&lst.front(), &insert_ref.get());
  ASSERT_EQ(1, lst.size());
  ASSERT_EQ(2, lst.front().geti());
  ASSERT_EQ(3.5, lst.front().getd());

  result = lst.emplace_front(3, 4.5);
  ASSERT_TRUE(result);
  insert_ref = result.value();

  ASSERT_EQ(&lst.front(), &insert_ref.get());
  ASSERT_EQ(2, lst.size());
  ASSERT_EQ(3, lst.front().geti());
  ASSERT_EQ(4.5, lst.front().getd());
  ASSERT_EQ(2, lst.back().geti());
  ASSERT_EQ(3.5, lst.back().getd());
}

// [erase]

// iterator erase(const_iterator position);
TEST(list, erase_pos) {
  static_cast<void>(test_info_);

  ::portable_stl::list<int> lst{1, 2, 3};

  auto j = lst.erase(::portable_stl::next(lst.begin()));
  ASSERT_EQ(2U, lst.size());
  ASSERT_EQ(2, ::portable_stl::distance(lst.begin(), lst.end()));
  ASSERT_EQ(3, *j);
  ASSERT_EQ(1, *lst.begin());
  ASSERT_EQ(3, *::portable_stl::next(lst.begin()));

  j = lst.erase(j);
  ASSERT_EQ(lst.end(), j);
  ASSERT_EQ(1U, lst.size());
  ASSERT_EQ(1, ::portable_stl::distance(lst.begin(), lst.end()));
  ASSERT_EQ(1, *lst.begin());

  j = lst.erase(lst.begin());
  ASSERT_EQ(lst.end(), j);
  ASSERT_EQ(0U, lst.size());
  ASSERT_EQ(0, ::portable_stl::distance(lst.begin(), lst.end()));
}

// iterator erase(const_iterator first, const_iterator last);
TEST(list, erase_iter_iter) {
  static_cast<void>(test_info_);

  ::portable_stl::list<std::int32_t> lst0{1, 2, 3};
  {
    auto lst = lst0;

    auto iter = lst.erase(lst.cbegin(), lst.cbegin());
    ASSERT_EQ(3U, lst.size());
    ASSERT_EQ(3, ::portable_stl::distance(lst.cbegin(), lst.cend()));
    ASSERT_EQ(lst.begin(), iter);
  }
  {
    auto lst = lst0;

    auto iter = lst.erase(lst.cbegin(), ::portable_stl::next(lst.cbegin()));
    ASSERT_EQ(2U, lst.size());
    ASSERT_EQ(2, ::portable_stl::distance(lst.cbegin(), lst.cend()));
    ASSERT_EQ(iter, lst.begin());
    ASSERT_EQ((::portable_stl::list<std::int32_t>{2, 3}), lst);
  }
  {
    auto lst = lst0;

    auto iter = lst.erase(lst.cbegin(), ::portable_stl::next(lst.cbegin(), 2));
    ASSERT_EQ(1U, lst.size());
    ASSERT_EQ(1, ::portable_stl::distance(lst.cbegin(), lst.cend()));
    ASSERT_EQ(lst.begin(), iter);
    ASSERT_EQ(::portable_stl::list<std::int32_t>{3}, lst);
  }
  {
    auto lst = lst0;

    auto iter = lst.erase(lst.cbegin(), ::portable_stl::next(lst.cbegin(), 3));
    ASSERT_EQ(0U, lst.size());
    ASSERT_EQ(0, ::portable_stl::distance(lst.cbegin(), lst.cend()));
    ASSERT_EQ(lst.begin(), iter);
  }
}

// [pop_back_front]

// void pop_back();
TEST(list, pop_back) {
  static_cast<void>(test_info_);

  ::portable_stl::list<std::int32_t> lst{1, 2, 3};

  lst.pop_back();
  ASSERT_EQ((::portable_stl::list<std::int32_t>{1, 2}), lst);
  lst.pop_back();
  ASSERT_EQ((::portable_stl::list<std::int32_t>{1}), lst);
  lst.pop_back();
  ASSERT_TRUE(lst.empty());
}

// void pop_front();
TEST(list, pop_front) {
  static_cast<void>(test_info_);

  ::portable_stl::list<std::int32_t> lst{1, 2, 3};

  lst.pop_front();
  ASSERT_EQ((::portable_stl::list<std::int32_t>{2, 3}), lst);
  lst.pop_front();
  ASSERT_EQ((::portable_stl::list<std::int32_t>{3}), lst);
  lst.pop_front();
  ASSERT_TRUE(lst.empty());
}

// [resize]

// void resize(size_type new_size);
TEST(list, resize_count) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::list<std::int32_t> lst(5, 2);
    lst.resize(2);
    ASSERT_EQ(2, lst.size());
    ASSERT_EQ(2, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(::portable_stl::list<std::int32_t>(2, 2), lst);
  }
  {
    ::portable_stl::list<std::int32_t> lst(5, 2);
    lst.resize(10);
    ASSERT_EQ(10, lst.size());
    ASSERT_EQ(10, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(2, lst.front());
    ASSERT_EQ(0, lst.back());
  }

  /**
   * @brief Alias.
   */
  using t_default = test_common_helper::DefaultOnly;
  {
    ::portable_stl::list<t_default> lst(10);
    lst.resize(5);
    ASSERT_EQ(5, lst.size());
    ASSERT_EQ(5, ::portable_stl::distance(lst.begin(), lst.end()));
  }
  {
    ::portable_stl::list<t_default> lst(10);
    lst.resize(20);
    ASSERT_EQ(20, lst.size());
    ASSERT_EQ(20, ::portable_stl::distance(lst.begin(), lst.end()));
  }

  // bad allocation 1
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

    test_allocator_helper::test_allocator_statistics stat;
    t_allocator                                      alloc{&stat};

    ::portable_stl::list<std::int32_t, t_allocator> lst({1, 2, 3, 4, 5}, alloc);
    auto                                            lst_ref = lst;

    stat.m_time_to_throw = 0;
    stat.m_throw_after   = 4;
    auto result          = lst.resize(10);
    ASSERT_FALSE(result);

    /* Strong exception guarantee*/
    ASSERT_EQ(lst_ref, lst);
  }

  // bad allocation 2
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

    test_allocator_helper::test_allocator_statistics stat;
    t_allocator                                      alloc{&stat};

    ::portable_stl::list<std::int32_t, t_allocator> lst({1, 2, 3, 4, 5}, alloc);
    auto                                            lst_ref = lst;

    stat.m_throw_after = 0;
    auto result        = lst.resize(10);
    ASSERT_FALSE(result);

    /* Strong exception guarantee*/
    ASSERT_EQ(lst_ref, lst);
  }
}

// void resize(size_type new_size, const value_type& x);
TEST(list, resize_count_value) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::list<std::int32_t> lst(5, 2);
    lst.resize(2, 5);
    ASSERT_EQ(2, lst.size());
    ASSERT_EQ(2, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(::portable_stl::list<std::int32_t>(2, 2), lst);
  }
  {
    ::portable_stl::list<std::int32_t> lst(5, 2);
    lst.resize(10, 5);
    ASSERT_EQ(10, lst.size());
    ASSERT_EQ(10, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ((::portable_stl::list<std::int32_t>{2, 2, 2, 2, 2, 5, 5, 5, 5, 5}), lst);
  }

  // bad allocation 1
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

    test_allocator_helper::test_allocator_statistics stat;
    t_allocator                                      alloc{&stat};

    ::portable_stl::list<std::int32_t, t_allocator> lst({1, 2, 3, 4, 5}, alloc);
    auto                                            lst_ref = lst;

    stat.m_time_to_throw = 0;
    stat.m_throw_after   = 4;
    auto result          = lst.resize(10, 5);
    ASSERT_FALSE(result);

    /* Strong exception guarantee*/
    ASSERT_EQ(lst_ref, lst);
  }

  // bad allocation 2
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

    test_allocator_helper::test_allocator_statistics stat;
    t_allocator                                      alloc{&stat};

    ::portable_stl::list<std::int32_t, t_allocator> lst({1, 2, 3, 4, 5}, alloc);
    auto                                            lst_ref = lst;

    stat.m_throw_after = 0;
    auto result        = lst.resize(10, 5);
    ASSERT_FALSE(result);

    /* Strong exception guarantee*/
    ASSERT_EQ(lst_ref, lst);
  }
}

// [swap]

// template <class T, class Alloc> void swap(list<T,Alloc>& x, list<T,Alloc>& y);
TEST(list, swap) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::list<std::int32_t> lst_ref1{1, 3, 7, 9, 10};
    ::portable_stl::list<std::int32_t> lst_ref2{0, 2, 4, 6, 8, 11};

    auto lst1 = lst_ref1;
    auto lst2 = lst_ref2;

    auto iter1 = lst1.begin();
    auto iter2 = lst2.cbegin();

    swap(lst1, lst2);

    ASSERT_EQ(lst_ref1, lst2);
    ASSERT_EQ(lst_ref2, lst1);
    ASSERT_EQ(lst2.begin(), iter1); // Iterators remain valid
    ASSERT_EQ(lst1.begin(), iter2); // Iterators remain valid
  }
  {
    ::portable_stl::list<std::int32_t> lst1;
    ::portable_stl::list<std::int32_t> lst_ref2{0, 2, 4, 6, 8, 11};
    auto                               lst2 = lst_ref2;

    swap(lst1, lst2);
    ASSERT_EQ(lst_ref2, lst1);
    ASSERT_TRUE(lst2.empty());
    ASSERT_EQ(0, ::portable_stl::distance(lst2.begin(), lst2.end()));
  }
  {
    ::portable_stl::list<std::int32_t> lst_ref1{0, 2, 4, 6, 8, 11};
    auto                               lst1 = lst_ref1;
    ::portable_stl::list<std::int32_t> lst2;

    swap(lst1, lst2);
    ASSERT_TRUE(lst1.empty());
    ASSERT_EQ(0, ::portable_stl::distance(lst1.begin(), lst1.end()));
    ASSERT_EQ(lst_ref1, lst2);
  }
  {
    ::portable_stl::list<std::int32_t> lst1;
    ::portable_stl::list<std::int32_t> lst2;
    swap(lst1, lst2);
    ASSERT_TRUE(lst1.empty());
    ASSERT_EQ(0, ::portable_stl::distance(lst1.begin(), lst1.end()));
    ASSERT_TRUE(lst2.empty());
    ASSERT_EQ(0, ::portable_stl::distance(lst2.begin(), lst2.end()));
  }
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

    auto lst1 = ::portable_stl::list<std::int32_t, t_allocator>({1, 3, 7, 9, 10}, t_allocator{1});
    auto lst2 = ::portable_stl::list<std::int32_t, t_allocator>({0, 2, 4, 6, 8, 11}, t_allocator{1});

    swap(lst1, lst2);

    ASSERT_EQ((::portable_stl::list<std::int32_t, t_allocator>({0, 2, 4, 6, 8, 11})), lst1);
    ASSERT_EQ(lst1.get_allocator(), t_allocator(1));
    ASSERT_EQ((::portable_stl::list<std::int32_t, t_allocator>({1, 3, 7, 9, 10})), lst2);
    ASSERT_EQ(lst2.get_allocator(), t_allocator(1));
  }
}
