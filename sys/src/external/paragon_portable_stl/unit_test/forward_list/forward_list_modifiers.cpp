// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="forward_list_modifiers.cpp"
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
#include "portable_stl/iterator/move_iterator.h"

namespace test_forward_list_helper {
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
} // namespace test_forward_list_helper

// void clear() noexcept;
TEST(forward_list, clear) {
  static_cast<void>(test_info_);

  ::portable_stl::forward_list<std::int32_t> lst{1, 2, 3};
  ASSERT_FALSE(lst.empty());

  lst.clear();
  ASSERT_TRUE(lst.empty());

  ASSERT_NO_THROW(lst.clear());
}

// [push_front]

// void push_front(const value_type& x);
TEST(forward_list, push_front_lvalue) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::forward_list<std::int32_t> lst;
    for (std::int32_t i{0}; i < 5; ++i) {
      ASSERT_TRUE(lst.push_front(i));
    }

    ASSERT_EQ((::portable_stl::forward_list<std::int32_t>{4, 3, 2, 1, 0}), lst);
  }

  // bad construction
  {
    test_forward_list_helper::CMyClass                               instance;
    ::portable_stl::forward_list<test_forward_list_helper::CMyClass> lst;

    lst.push_front(instance);

    test_forward_list_helper::gCopyConstructorShouldThrow = true;
    try {
      lst.push_front(instance);
      ASSERT_TRUE(false);
    } catch (std::int32_t &) {
    }

    test_forward_list_helper::gCopyConstructorShouldThrow = false;
  }

  // bad allocation
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;
    test_allocator_helper::test_allocator_statistics stat;
    stat.m_throw_after = 5 + 2;
    t_allocator                                             alloc(&stat);
    ::portable_stl::forward_list<std::int32_t, t_allocator> lst({4, 3, 2, 1, 0}, alloc);

    std::int32_t value{5};
    ASSERT_TRUE(lst.push_front(value));

    value = 6;
    ASSERT_TRUE(lst.push_front(value));

    value       = 7;
    auto result = lst.push_front(value);

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    /* Strong exception guarantee*/
    ASSERT_EQ(7U, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(6, lst.front());
  }
}

// void push_front(value_type&& x);
TEST(forward_list, push_front_rvalue) {
  static_cast<void>(test_info_);

  /**
   * @brief Move only alias.
   */
  using t_move_only = test_common_helper::MoveOnly;

  {
    ::portable_stl::forward_list<t_move_only> lst;
    lst.push_front(t_move_only(1));
    ASSERT_EQ(1U, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(t_move_only(1), lst.front());

    lst.push_front(t_move_only(2));
    ASSERT_EQ(2U, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(t_move_only(2), lst.front());
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
    ::portable_stl::forward_list<t_move_only, t_allocator> lst(
      ::portable_stl::move_iterator<t_move_only *>(arr),
      ::portable_stl::move_iterator<t_move_only *>(arr + (sizeof(arr) / sizeof(arr[0]))),
      alloc);

    ASSERT_TRUE(lst.push_front(t_move_only(5)));

    ASSERT_TRUE(lst.push_front(t_move_only(6)));

    auto result = lst.push_front(t_move_only(7));

    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    /* Strong exception guarantee*/
    ASSERT_EQ(7U, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(t_move_only(6), lst.front());
  }
}

// // [insert_after]

// iterator insert_after(const_iterator p, const value_type& v);
TEST(forward_list, insert_after_pos_value) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::forward_list<std::int32_t> lst;
    auto                                       result = lst.insert_after(lst.cbefore_begin(), 4);
    ASSERT_TRUE(result);
    auto iter = result.value();

    ASSERT_EQ(lst.cbegin(), iter);
    ASSERT_EQ(4, lst.front());
  }

  {
    std::int32_t                               arr1[] = {1, 2, 3};
    std::int32_t                               arr2[] = {1, 4, 2, 3};
    ::portable_stl::forward_list<std::int32_t> lst1(arr1, arr1 + (sizeof(arr1) / sizeof(arr1[0])));
    ::portable_stl::forward_list<std::int32_t> lst_ref(arr2, arr2 + (sizeof(arr2) / sizeof(arr2[0])));

    std::int32_t value{4};
    auto         result = lst1.insert_after(lst1.cbegin(), value);
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
    test_allocator_helper::test_allocator_statistics        stat;
    t_allocator                                             alloc(4, &stat);
    ::portable_stl::forward_list<std::int32_t, t_allocator> lst({1, 2, 3, 4}, alloc);
    auto                                                    lst_ref = lst;

    stat.m_throw_after = 0;
    std::int32_t value{4};
    auto         result = lst.insert_after(::portable_stl::next(lst.cbegin()), value);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    /* Strong exception guarantee*/
    ASSERT_EQ(lst_ref, lst);
  }
}

// iterator insert_after(const_iterator p, value_type&& v);
TEST(forward_list, insert_after_pos_rvalue) {
  static_cast<void>(test_info_);

  /**
   * @brief Move only alias.
   */
  using t_move_only = test_common_helper::MoveOnly;

  {
    ::portable_stl::forward_list<t_move_only> lst;

    auto iter = lst.insert_after(lst.cbefore_begin(), t_move_only(1)).value();
    ASSERT_EQ(1U, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(lst.cbegin(), iter);
    ASSERT_EQ(lst.front(), t_move_only(1));

    iter = lst.insert_after(lst.cbegin(), t_move_only(2)).value();
    ASSERT_EQ(2U, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(::portable_stl::next(lst.cbegin()), iter);
    ASSERT_EQ(lst.front(), t_move_only(1));
    ASSERT_EQ(*::portable_stl::next(lst.cbegin()), t_move_only(2));
  }

  // bad allocation
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<t_move_only>;
    test_allocator_helper::test_allocator_statistics stat;
    t_allocator                                      alloc(4, &stat);

    ::portable_stl::forward_list<t_move_only, t_allocator> lst(alloc);

    auto result = lst.insert_after(lst.cbefore_begin(), t_move_only(1));
    ASSERT_TRUE(result);
    ASSERT_EQ(1U, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(lst.front(), t_move_only(1));

    stat.m_throw_after = 0;
    result             = lst.insert_after(lst.cbegin(), t_move_only(2));
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    /* Strong exception guarantee*/
    ASSERT_EQ(1U, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(lst.front(), t_move_only(1));
  }
}

// iterator insert(const_iterator position, size_type n, const value_type& x);
TEST(forward_list, insert_pos_count_value) {
  static_cast<void>(test_info_);

  {
    std::int32_t                               arr1[] = {1, 2, 3};
    std::int32_t                               arr2[] = {1, 4, 4, 4, 4, 4, 2, 3};
    ::portable_stl::forward_list<std::int32_t> lst1(arr1, arr1 + (sizeof(arr1) / sizeof(arr1[0])));
    ::portable_stl::forward_list<std::int32_t> lst_ref(arr2, arr2 + (sizeof(arr2) / sizeof(arr2[0])));

    auto result = lst1.insert_after(lst1.cbegin(), 5, 4);
    ASSERT_TRUE(result);
    auto iter = result.value();

    ASSERT_EQ(::portable_stl::next(lst1.cbegin(), 5), iter);
    ASSERT_EQ(lst_ref, lst1);
  }

  // bad allocation (node creation)
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;
    test_allocator_helper::test_allocator_statistics        stat;
    t_allocator                                             alloc(4, &stat);
    ::portable_stl::forward_list<std::int32_t, t_allocator> lst({1, 2, 3, 4}, alloc);
    auto                                                    lst_ref = lst;

    stat.m_throw_after = 3;
    auto result        = lst.insert_after(lst.cbegin(), 4, 3);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    /* Strong exception guarantee*/
    ASSERT_EQ(lst_ref, lst);
  }
}

// template<t_input_iterator> iterator insert_after(const_iterator position, t_input_iterator first, t_input_iterator
// last);
TEST(forward_list, insert_pos_iter_iter) {
  static_cast<void>(test_info_);

  std::int32_t                 arr[] = {0, 1, 2};
  ::portable_stl::size_t const arr_size{sizeof(arr) / sizeof(arr[0])};

  // empty range
  {
    ::portable_stl::forward_list<std::int32_t> lst;
    auto                                       result = lst.insert_after(lst.cbefore_begin(),
                                   test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
                                   test_iterator_helper::tst_input_iterator<std::int32_t *>(arr));
    ASSERT_TRUE(result);
    auto iter = result.value();

    ASSERT_EQ(lst.before_begin(), iter);
    ASSERT_EQ(0, ::portable_stl::distance(lst.begin(), lst.end()));
  }

  {
    ::portable_stl::forward_list<std::int32_t> lst;
    auto                                       result = lst.insert_after(lst.cbefore_begin(),
                                   test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
                                   test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size));
    ASSERT_TRUE(result);
    auto iter = result.value();

    ASSERT_EQ(::portable_stl::next(lst.cbegin(), arr_size - 1), iter);
    ASSERT_EQ(arr_size, ::portable_stl::distance(lst.begin(), lst.end()));

    iter          = lst.begin();
    auto iter_end = lst.cend();
    for (std::int32_t i{0}; iter != iter_end; ++iter, ++i) {
      ASSERT_EQ(i, *iter);
    }

    std::int32_t                 arr2[] = {3, 4, 5};
    ::portable_stl::size_t const arr2_size{sizeof(arr2) / sizeof(arr2[0])};

    result = lst.insert_after(lst.begin(),
                              test_iterator_helper::tst_input_iterator<std::int32_t *>(arr2),
                              test_iterator_helper::tst_input_iterator<std::int32_t *>(arr2 + arr2_size));
    ASSERT_TRUE(result);
    iter = result.value();

    ASSERT_EQ(arr_size + arr2_size, ::portable_stl::distance(lst.begin(), lst.end()));

    std::int32_t arr_ref[] = {0, 3, 4, 5, 1, 2};

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

    ::portable_stl::forward_list<std::int32_t, t_allocator> lst({1, 2, 3, 4, 5}, alloc);
    auto                                                    lst_ref = lst;

    stat.m_throw_after = 2;
    auto result        = lst.insert_after(lst.cbefore_begin(),
                                   test_iterator_helper::tst_input_iterator<std::int32_t *>(arr),
                                   test_iterator_helper::tst_input_iterator<std::int32_t *>(arr + arr_size));
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    /* Strong exception guarantee*/
    ASSERT_EQ(lst_ref, lst);
  }
}

// iterator insert_after(const_iterator p, initializer_forward_list<value_type> il);
TEST(forward_list, insert_pos_init_forward_list) {
  static_cast<void>(test_info_);

  ::portable_stl::forward_list<std::int32_t> lst{1, 2, 3, 4, 5};

  auto result = lst.insert_after(::portable_stl::next(lst.begin(), 2), {6, 7, 8, 9, 0});
  ASSERT_TRUE(result);
  auto iter = result.value();

  ASSERT_EQ(::portable_stl::next(lst.begin(), 2 + 5), iter);
  ASSERT_EQ(10, ::portable_stl::distance(lst.begin(), lst.end()));

  std::int32_t arr_ref[] = {1, 2, 3, 6, 7, 8, 9, 0, 4, 5};

  iter          = lst.begin();
  auto iter_end = lst.cend();
  for (std::size_t i{0U}; iter != iter_end; ++iter, ++i) {
    ASSERT_EQ(arr_ref[i], *iter);
  }
}

// [emplace]

namespace test_forward_list_helper {
class type_for_emplace final {
  std::int32_t m_int;
  double       m_double;

public:
  type_for_emplace() : m_int(0), m_double(0) {
  }

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

static bool operator==(type_for_emplace const &lhv, type_for_emplace const &rhv) {
  return (lhv.geti() == rhv.geti()) && (lhv.getd() == rhv.getd());
}
} // namespace test_forward_list_helper

// template<class... t_args> iterator emplace_after(t_args &&...args);
TEST(forward_list, emplace_after) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias.
   */
  using t_type = test_forward_list_helper::type_for_emplace;

  {
    ::portable_stl::forward_list<t_type> lst;

    auto result = lst.emplace_after(lst.cbefore_begin());
    ASSERT_TRUE(result);
    auto iter = result.value();

    ASSERT_EQ(lst.begin(), iter);
    ASSERT_EQ(1U, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(t_type(), lst.front());
  }

  // {
  //   ::portable_stl::forward_list<t_type> lst;

  //   auto result = lst.emplace_after(lst.cbefore_begin(), 2, 3.5);
  //   ASSERT_TRUE(result);
  //   auto insert_ref = result.value();

  //   ASSERT_EQ(&lst.front(), &insert_ref.get());
  //   ASSERT_EQ(1U, ::portable_stl::distance(lst.begin(), lst.end()));
  //   ASSERT_EQ(2, lst.front().geti());
  //   ASSERT_EQ(3.5, lst.front().getd());

  //   result = lst.emplace_front(3, 4.5);
  //   ASSERT_TRUE(result);
  //   insert_ref = result.value();

  //   ASSERT_EQ(&lst.front(), &insert_ref.get());
  //   ASSERT_EQ(2U, ::portable_stl::distance(lst.begin(), lst.end()));
  //   ASSERT_EQ(3, lst.front().geti());
  //   ASSERT_EQ(4.5, lst.front().getd());
  // }

  // // bad allocation
  // {
  //   /**
  //    * @brief Allocator alias.
  //    */
  //   using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

  //   test_allocator_helper::test_allocator_statistics stat;
  //   t_allocator                                      alloc{&stat};

  //   ::portable_stl::forward_list<std::int32_t, t_allocator> lst({1, 2, 3}, alloc);
  //   auto                                                    lst_ref = lst;

  //   stat.m_throw_after = 0;
  //   auto result        = lst.emplace_front(0);
  //   ASSERT_FALSE(result);
  //   ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

  //   /* Strong exception guarantee*/
  //   ASSERT_EQ(lst_ref, lst);
  // }
}

// template<class... t_args> iterator emplace_front(t_args &&...args);
TEST(forward_list, emplace_front) {
  static_cast<void>(test_info_);

  /**
   * @brief Alias.
   */
  using t_type = test_forward_list_helper::type_for_emplace;

  {
    ::portable_stl::forward_list<t_type> lst;

    auto result = lst.emplace_front(2, 3.5);
    ASSERT_TRUE(result);
    auto insert_ref = result.value();

    ASSERT_EQ(&lst.front(), &insert_ref.get());
    ASSERT_EQ(1U, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(2, lst.front().geti());
    ASSERT_EQ(3.5, lst.front().getd());

    result = lst.emplace_front(3, 4.5);
    ASSERT_TRUE(result);
    insert_ref = result.value();

    ASSERT_EQ(&lst.front(), &insert_ref.get());
    ASSERT_EQ(2U, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(3, lst.front().geti());
    ASSERT_EQ(4.5, lst.front().getd());
  }

  // bad allocation
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

    test_allocator_helper::test_allocator_statistics stat;
    t_allocator                                      alloc{&stat};

    ::portable_stl::forward_list<std::int32_t, t_allocator> lst({1, 2, 3}, alloc);
    auto                                                    lst_ref = lst;

    stat.m_throw_after = 0;
    auto result        = lst.emplace_front(0);
    ASSERT_FALSE(result);
    ASSERT_EQ(::portable_stl::portable_stl_error::allocate_error, result.error());

    /* Strong exception guarantee*/
    ASSERT_EQ(lst_ref, lst);
  }
}

// [erase_after]

// iterator erase_after(const_iterator position);
TEST(forward_list, erase_pos) {
  static_cast<void>(test_info_);

  ::portable_stl::forward_list<int> lst{0, 1, 2, 3, 4};

  auto iter = lst.erase_after(::portable_stl::next(lst.cbefore_begin(), 4));
  ASSERT_EQ(lst.end(), iter);
  ASSERT_EQ(4, ::portable_stl::distance(lst.begin(), lst.end()));
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 0), 0);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 1), 1);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 2), 2);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 3), 3);

  iter = lst.erase_after(::portable_stl::next(lst.cbefore_begin(), 0));
  ASSERT_EQ(lst.begin(), iter);
  ASSERT_EQ(3, ::portable_stl::distance(lst.begin(), lst.end()));
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 0), 1);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 1), 2);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 2), 3);

  iter = lst.erase_after(::portable_stl::next(lst.cbefore_begin(), 1));
  ASSERT_EQ(::portable_stl::next(lst.begin()), iter);
  ASSERT_EQ(2, ::portable_stl::distance(lst.begin(), lst.end()));
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 0), 1);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 1), 3);

  iter = lst.erase_after(::portable_stl::next(lst.cbefore_begin(), 1));
  ASSERT_EQ(lst.end(), iter);
  ASSERT_EQ(1, ::portable_stl::distance(lst.begin(), lst.end()));
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 0), 1);

  iter = lst.erase_after(::portable_stl::next(lst.cbefore_begin(), 0));
  ASSERT_EQ(lst.end(), iter);
  ASSERT_EQ(lst.begin(), iter);
}

// iterator erase_after(const_iterator first, const_iterator last);
TEST(forward_list, erase_iter_iter) {
  static_cast<void>(test_info_);

  ::portable_stl::forward_list<std::int32_t> lst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  auto iter
    = lst.erase_after(::portable_stl::next(lst.cbefore_begin(), 4), ::portable_stl::next(lst.cbefore_begin(), 4));
  ASSERT_EQ(::portable_stl::next(lst.cbefore_begin(), 4), iter);
  ASSERT_EQ(10, ::portable_stl::distance(lst.begin(), lst.end()));
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 0), 0);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 1), 1);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 2), 2);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 3), 3);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 4), 4);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 5), 5);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 6), 6);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 7), 7);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 8), 8);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 9), 9);

  iter = lst.erase_after(::portable_stl::next(lst.cbefore_begin(), 2), ::portable_stl::next(lst.cbefore_begin(), 5));
  ASSERT_EQ(::portable_stl::next(lst.begin(), 2), iter);
  ASSERT_EQ(8, ::portable_stl::distance(lst.begin(), lst.end()));
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 0), 0);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 1), 1);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 2), 4);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 3), 5);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 4), 6);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 5), 7);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 6), 8);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 7), 9);

  iter = lst.erase_after(::portable_stl::next(lst.cbefore_begin(), 2), ::portable_stl::next(lst.cbefore_begin(), 3));
  ASSERT_EQ(::portable_stl::next(lst.begin(), 2), iter);
  ASSERT_EQ(8, ::portable_stl::distance(lst.begin(), lst.end()));
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 0), 0);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 1), 1);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 2), 4);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 3), 5);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 4), 6);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 5), 7);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 6), 8);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 7), 9);

  iter = lst.erase_after(::portable_stl::next(lst.cbefore_begin(), 5), ::portable_stl::next(lst.cbefore_begin(), 9));
  ASSERT_EQ(lst.end(), iter);
  ASSERT_EQ(5, ::portable_stl::distance(lst.begin(), lst.end()));
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 0), 0);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 1), 1);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 2), 4);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 3), 5);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 4), 6);

  iter = lst.erase_after(::portable_stl::next(lst.cbefore_begin(), 0), ::portable_stl::next(lst.cbefore_begin(), 2));
  ASSERT_EQ(lst.begin(), iter);
  ASSERT_EQ(4, ::portable_stl::distance(lst.begin(), lst.end()));
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 0), 1);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 1), 4);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 2), 5);
  ASSERT_EQ(*::portable_stl::next(lst.begin(), 3), 6);

  iter = lst.erase_after(::portable_stl::next(lst.cbefore_begin(), 0), ::portable_stl::next(lst.cbefore_begin(), 5));
  ASSERT_EQ(lst.begin(), iter);
  ASSERT_EQ(lst.end(), iter);
  ASSERT_EQ(0, ::portable_stl::distance(lst.begin(), lst.end()));
}

// [pop_front]

// void pop_front();
TEST(forward_list, pop_front) {
  static_cast<void>(test_info_);

  ::portable_stl::forward_list<std::int32_t> lst{1, 2, 3};

  lst.pop_front();
  ASSERT_EQ((::portable_stl::forward_list<std::int32_t>{2, 3}), lst);
  lst.pop_front();
  ASSERT_EQ((::portable_stl::forward_list<std::int32_t>{3}), lst);
  lst.pop_front();
  ASSERT_TRUE(lst.empty());
}

// [resize]

// void resize(size_type new_size);
TEST(forward_list, resize_count) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::forward_list<std::int32_t> lst(5, 2);
    lst.resize(2);
    ASSERT_EQ(2U, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(::portable_stl::forward_list<std::int32_t>(2, 2), lst);
  }
  {
    ::portable_stl::forward_list<std::int32_t> lst(5, 2);
    lst.resize(10);
    ASSERT_EQ(10U, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(2, lst.front());
  }

  /**
   * @brief Alias.
   */
  using t_default = test_common_helper::DefaultOnly;
  {
    ::portable_stl::forward_list<t_default> lst(10);
    lst.resize(5);
    ASSERT_EQ(5U, ::portable_stl::distance(lst.begin(), lst.end()));
  }
  {
    ::portable_stl::forward_list<t_default> lst(10);
    lst.resize(20);
    ASSERT_EQ(20U, ::portable_stl::distance(lst.begin(), lst.end()));
  }

  // bad allocation 1
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

    test_allocator_helper::test_allocator_statistics stat;
    t_allocator                                      alloc{&stat};

    ::portable_stl::forward_list<std::int32_t, t_allocator> lst({1, 2, 3, 4, 5}, alloc);
    auto                                                    lst_ref = lst;

    stat.m_time_to_throw = 0;
    stat.m_throw_after   = 4;
    auto result          = lst.resize(10);
    ASSERT_FALSE(result);

    /* Basic exception guarantee*/
    ASSERT_GE(::portable_stl::distance(lst.begin(), lst.end()),
              ::portable_stl::distance(lst_ref.begin(), lst_ref.end()));

    auto iter1 = lst.begin();
    auto iter2 = lst_ref.begin();
    for (std::size_t i{0U}; i < 5U; ++i, ++iter1, ++iter2) {
      ASSERT_EQ(*iter1, *iter2);
    }
  }

  // bad allocation 2
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

    test_allocator_helper::test_allocator_statistics stat;
    t_allocator                                      alloc{&stat};

    ::portable_stl::forward_list<std::int32_t, t_allocator> lst({1, 2, 3, 4, 5}, alloc);
    auto                                                    lst_ref = lst;

    stat.m_throw_after = 0;
    auto result        = lst.resize(10);
    ASSERT_FALSE(result);

    /* Basic exception guarantee*/
    ASSERT_GE(::portable_stl::distance(lst.begin(), lst.end()),
              ::portable_stl::distance(lst_ref.begin(), lst_ref.end()));

    auto iter1 = lst.begin();
    auto iter2 = lst_ref.begin();
    for (std::size_t i{0U}; i < 5U; ++i, ++iter1, ++iter2) {
      ASSERT_EQ(*iter1, *iter2);
    }
  }
}

// void resize(size_type new_size, const value_type& x);
TEST(forward_list, resize_count_value) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::forward_list<std::int32_t> lst(5, 2);
    lst.resize(2, 5);
    ASSERT_EQ(2U, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ(::portable_stl::forward_list<std::int32_t>(2, 2), lst);
  }
  {
    ::portable_stl::forward_list<std::int32_t> lst(5, 2);
    lst.resize(10, 5);
    ASSERT_EQ(10U, ::portable_stl::distance(lst.begin(), lst.end()));
    ASSERT_EQ((::portable_stl::forward_list<std::int32_t>{2, 2, 2, 2, 2, 5, 5, 5, 5, 5}), lst);
  }

  // bad allocation 1
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

    test_allocator_helper::test_allocator_statistics stat;
    t_allocator                                      alloc{&stat};

    ::portable_stl::forward_list<std::int32_t, t_allocator> lst({1, 2, 3, 4, 5}, alloc);
    auto                                            lst_ref = lst;

    stat.m_time_to_throw = 0;
    stat.m_throw_after   = 4;
    auto result          = lst.resize(10, 5);
    ASSERT_FALSE(result);

    /* Basic exception guarantee*/
    ASSERT_GE(::portable_stl::distance(lst.begin(), lst.end()),
              ::portable_stl::distance(lst_ref.begin(), lst_ref.end()));

    auto iter1 = lst.begin();
    auto iter2 = lst_ref.begin();
    for (std::size_t i{0U}; i < 5U; ++i, ++iter1, ++iter2) {
      ASSERT_EQ(*iter1, *iter2);
    }
  }

  // bad allocation 2
  {
    /**
     * @brief Allocator alias.
     */
    using t_allocator = test_allocator_helper::test_allocator<std::int32_t>;

    test_allocator_helper::test_allocator_statistics stat;
    t_allocator                                      alloc{&stat};

    ::portable_stl::forward_list<std::int32_t, t_allocator> lst({1, 2, 3, 4, 5}, alloc);
    auto                                            lst_ref = lst;

    stat.m_throw_after = 0;
    auto result        = lst.resize(10, 5);
    ASSERT_FALSE(result);

    /* Basic exception guarantee*/
    ASSERT_GE(::portable_stl::distance(lst.begin(), lst.end()),
              ::portable_stl::distance(lst_ref.begin(), lst_ref.end()));

    auto iter1 = lst.begin();
    auto iter2 = lst_ref.begin();
    for (std::size_t i{0U}; i < 5U; ++i, ++iter1, ++iter2) {
      ASSERT_EQ(*iter1, *iter2);
    }
  }
}

// [swap]

// template <class T, class Alloc> void swap(forward_list<T,Alloc>& x, forward_list<T,Alloc>& y);
TEST(forward_list, swap) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::forward_list<std::int32_t> lst_ref1{1, 3, 7, 9, 10};
    ::portable_stl::forward_list<std::int32_t> lst_ref2{0, 2, 4, 6, 8, 11};

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
    ::portable_stl::forward_list<std::int32_t> lst1;
    ::portable_stl::forward_list<std::int32_t> lst_ref2{0, 2, 4, 6, 8, 11};
    auto                               lst2 = lst_ref2;

    swap(lst1, lst2);
    ASSERT_EQ(lst_ref2, lst1);
    ASSERT_TRUE(lst2.empty());
    ASSERT_EQ(0, ::portable_stl::distance(lst2.begin(), lst2.end()));
  }
  {
    ::portable_stl::forward_list<std::int32_t> lst_ref1{0, 2, 4, 6, 8, 11};
    auto                               lst1 = lst_ref1;
    ::portable_stl::forward_list<std::int32_t> lst2;

    swap(lst1, lst2);
    ASSERT_TRUE(lst1.empty());
    ASSERT_EQ(0, ::portable_stl::distance(lst1.begin(), lst1.end()));
    ASSERT_EQ(lst_ref1, lst2);
  }
  {
    ::portable_stl::forward_list<std::int32_t> lst1;
    ::portable_stl::forward_list<std::int32_t> lst2;
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

    auto lst1 = ::portable_stl::forward_list<std::int32_t, t_allocator>({1, 3, 7, 9, 10}, t_allocator{1});
    auto lst2 = ::portable_stl::forward_list<std::int32_t, t_allocator>({0, 2, 4, 6, 8, 11}, t_allocator{1});

    swap(lst1, lst2);

    ASSERT_EQ((::portable_stl::forward_list<std::int32_t, t_allocator>({0, 2, 4, 6, 8, 11})), lst1);
    ASSERT_EQ(lst1.get_allocator(), t_allocator(1));
    ASSERT_EQ((::portable_stl::forward_list<std::int32_t, t_allocator>({1, 3, 7, 9, 10})), lst2);
    ASSERT_EQ(lst2.get_allocator(), t_allocator(1));
  }
}
