// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="iterator_concepts.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>
// #include "portable_stl/array/array.h"
#include "concepts_helper.h"
#include "iterator_helper.h"
#include "portable_stl/iterator/concepts/bidirectional_iterator.h"
#include "portable_stl/iterator/concepts/contiguous_iterator.h"
#include "portable_stl/iterator/concepts/cpp17_bidirectional_iterator.h"
#include "portable_stl/iterator/concepts/cpp17_forward_iterator.h"
#include "portable_stl/iterator/concepts/cpp17_input_iterator.h"
#include "portable_stl/iterator/concepts/cpp17_iterator.h"
#include "portable_stl/iterator/concepts/cpp17_random_access_iterator.h"
#include "portable_stl/iterator/concepts/forward_iterator.h"
#include "portable_stl/iterator/concepts/indirectly_readable.h"
#include "portable_stl/iterator/concepts/indirectly_swappable.h"
#include "portable_stl/iterator/concepts/indirectly_writable.h"
#include "portable_stl/iterator/concepts/input_iterator.h"
#include "portable_stl/iterator/concepts/iter_concept.h"
#include "portable_stl/iterator/concepts/random_access_iterator.h"
#include "portable_stl/iterator/concepts/sized_sentinel_for.h"
#include "portable_stl/iterator/concepts/weakly_incrementable.h"

TEST(iterator_concepts, indirectly_readable) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::indirectly_readable<std::int32_t *>;
    EXPECT_TRUE((test_type{}()));
  }

  // EXPECT_FALSE((::portable_stl::indirectly_readable<void>{}()));
  // EXPECT_FALSE((::portable_stl::indirectly_readable<void *>{}()));
  EXPECT_FALSE((::portable_stl::indirectly_readable<std::int32_t>{}()));

  EXPECT_TRUE((::portable_stl::indirectly_readable<std::int32_t *>{}()));
  EXPECT_TRUE((::portable_stl::indirectly_readable<std::int32_t const *>{}()));
  EXPECT_TRUE((::portable_stl::indirectly_readable<std::int32_t *&>{}()));
  EXPECT_TRUE((::portable_stl::indirectly_readable<std::int32_t const *&>{}()));

  EXPECT_TRUE((::portable_stl::indirectly_readable<test_iterator_helper::value_type_indirection>{}()));
  EXPECT_TRUE((::portable_stl::indirectly_readable<test_iterator_helper::element_type_indirection>{}()));
  EXPECT_TRUE((::portable_stl::indirectly_readable<test_iterator_helper::proxy_indirection>{}()));
  EXPECT_TRUE((::portable_stl::indirectly_readable<test_iterator_helper::read_only_indirection>{}()));

  EXPECT_FALSE((::portable_stl::indirectly_readable<test_iterator_helper::missing_dereference2>{}()));
  EXPECT_FALSE((::portable_stl::indirectly_readable<test_iterator_helper::iter_move_mismatch>{}()));
  EXPECT_FALSE((::portable_stl::indirectly_readable<test_iterator_helper::indirection_and_iter_move_mismatch>{}()));
  EXPECT_FALSE((::portable_stl::indirectly_readable<test_iterator_helper::missing_iter_value_t>{}()));
}

TEST(iterator_concepts, indirectly_writable) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::indirectly_writable<std::int32_t, std::int32_t>;
    EXPECT_FALSE((test_type{}()));
  }

  EXPECT_TRUE((::portable_stl::indirectly_writable<test_iterator_helper::value_type_indirection, std::int32_t>{}()));
  EXPECT_TRUE(
    (::portable_stl::indirectly_writable<test_iterator_helper::value_type_indirection const, std::int32_t>{}()));

  EXPECT_TRUE((::portable_stl::indirectly_writable<test_iterator_helper::value_type_indirection, double>{}()));
  EXPECT_TRUE((::portable_stl::indirectly_writable<test_iterator_helper::value_type_indirection const, double>{}()));

  EXPECT_FALSE((::portable_stl::indirectly_writable<test_iterator_helper::value_type_indirection, double *>{}()));
  EXPECT_FALSE((::portable_stl::indirectly_writable<test_iterator_helper::value_type_indirection const, double *>{}()));

  EXPECT_FALSE((::portable_stl::indirectly_writable<test_iterator_helper::read_only_indirection, std::int32_t>{}()));
  EXPECT_FALSE(
    (::portable_stl::indirectly_writable<test_iterator_helper::read_only_indirection const, std::int32_t>{}()));

  EXPECT_FALSE((::portable_stl::indirectly_writable<test_iterator_helper::proxy_indirection, std::int32_t>{}()));
  EXPECT_FALSE((::portable_stl::indirectly_writable<test_iterator_helper::proxy_indirection const, std::int32_t>{}()));

  EXPECT_FALSE((::portable_stl::indirectly_writable<test_iterator_helper::missing_dereference2,
                                                    test_iterator_helper::missing_dereference2::value_type>{}()));
  EXPECT_FALSE((::portable_stl::indirectly_writable<test_iterator_helper::missing_dereference2 const,
                                                    test_iterator_helper::missing_dereference2::value_type>{}()));

  EXPECT_FALSE((::portable_stl::indirectly_writable<void *, std::int32_t>{}()));
  EXPECT_FALSE((::portable_stl::indirectly_writable<void *const, std::int32_t>{}()));

  EXPECT_FALSE((::portable_stl::indirectly_writable<void const *, std::int32_t>{}()));
  EXPECT_FALSE((::portable_stl::indirectly_writable<void const *const, std::int32_t>{}()));

  EXPECT_FALSE((::portable_stl::indirectly_writable<void volatile *, std::int32_t>{}()));
  EXPECT_FALSE((::portable_stl::indirectly_writable<void volatile *const, std::int32_t>{}()));

  EXPECT_FALSE((::portable_stl::indirectly_writable<void const volatile *, std::int32_t>{}()));
  EXPECT_FALSE((::portable_stl::indirectly_writable<void const volatile *const, std::int32_t>{}()));

  EXPECT_TRUE((::portable_stl::indirectly_writable<void **, std::int32_t *>{}()));
  EXPECT_TRUE((::portable_stl::indirectly_writable<void **const, std::int32_t *>{}()));

  EXPECT_FALSE((::portable_stl::indirectly_writable<void **, std::int32_t>{}()));
  EXPECT_FALSE((::portable_stl::indirectly_writable<void **const, std::int32_t>{}()));

  EXPECT_TRUE((::portable_stl::indirectly_writable<std::int32_t *, std::int32_t>{}()));
  EXPECT_FALSE((::portable_stl::indirectly_writable<std::int32_t const *, std::int32_t>{}()));

  EXPECT_TRUE((::portable_stl::indirectly_writable<std::int32_t volatile *, std::int32_t>{}()));
  EXPECT_FALSE((::portable_stl::indirectly_writable<std::int32_t const volatile *, std::int32_t>{}()));

  EXPECT_TRUE((::portable_stl::indirectly_writable<std::int32_t *, double>{}()));

  EXPECT_TRUE((::portable_stl::indirectly_writable<std::int32_t **, std::int32_t *>{}()));
  EXPECT_FALSE((::portable_stl::indirectly_writable<std::int32_t **, std::int32_t>{}()));
}

TEST(iterator_concepts, indirectly_swappable) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::indirectly_swappable<test_iterator_helper::PointerTo<std::int32_t>>;
    EXPECT_TRUE((test_type{}()));
  }

  {
    /**
     * @brief Test iter to const.
     */
    using t_iter = std::int32_t const *;
    using t_iter_ref = ::portable_stl::iter_reference_t<t_iter>;

    EXPECT_FALSE((::portable_stl::swappable_with<t_iter_ref, t_iter_ref>{}()));
    EXPECT_FALSE((::portable_stl::ranges::iter_swap_impl::is_readable_swappable<t_iter, t_iter>{}()));
    EXPECT_FALSE((::portable_stl::indirectly_swappable<t_iter, t_iter>{}()));
  }

  EXPECT_TRUE((::portable_stl::indirectly_swappable<test_iterator_helper::PointerTo<std::int32_t>,
                                                    test_iterator_helper::PointerTo<std::int32_t>>{}()));

  /**
   * @brief Tested class.
   */
  using ClassAWithIterSwapSelf  = test_iterator_helper::ClassAWithIterSwapSelf;
  /**
   * @brief Tested class.
   */
  using ClassBWithIterSwapA     = test_iterator_helper::ClassBWithIterSwapA;
  /**
   * @brief Tested class.
   */
  using ClassCWithSemiIterSwapA = test_iterator_helper::ClassCWithSemiIterSwapA;

  EXPECT_TRUE((::portable_stl::ranges::iter_swap_impl::is_adl_iter_swap<
               test_iterator_helper::PointerTo<ClassAWithIterSwapSelf>,
               test_iterator_helper::PointerTo<ClassAWithIterSwapSelf>>{}()));

  EXPECT_TRUE((::portable_stl::ranges::iter_swap_impl::is_adl_iter_swap<
               test_iterator_helper::PointerTo<ClassAWithIterSwapSelf>,
               test_iterator_helper::PointerTo<ClassBWithIterSwapA>>{}()));
  // and
  EXPECT_TRUE((::portable_stl::ranges::iter_swap_impl::is_adl_iter_swap<
               test_iterator_helper::PointerTo<ClassBWithIterSwapA>,
               test_iterator_helper::PointerTo<ClassAWithIterSwapSelf>>{}()));

  EXPECT_TRUE((::portable_stl::ranges::iter_swap_impl::is_adl_iter_swap<
               test_iterator_helper::PointerTo<ClassAWithIterSwapSelf>,
               test_iterator_helper::PointerTo<ClassCWithSemiIterSwapA>>{}()));
  // but
  EXPECT_FALSE((::portable_stl::ranges::iter_swap_impl::is_adl_iter_swap<
                test_iterator_helper::PointerTo<ClassCWithSemiIterSwapA>,
                test_iterator_helper::PointerTo<ClassAWithIterSwapSelf>>{}()));

  EXPECT_TRUE((::portable_stl::indirectly_swappable<test_iterator_helper::PointerTo<ClassAWithIterSwapSelf>>{}()));

  EXPECT_TRUE((::portable_stl::indirectly_swappable<test_iterator_helper::PointerTo<ClassAWithIterSwapSelf>,
                                                    test_iterator_helper::PointerTo<ClassBWithIterSwapA>>{}()));

  // iter_swap (PointerTo < C > const &, PointerTo < A > const &) = delete, so
  EXPECT_FALSE((::portable_stl::indirectly_swappable<test_iterator_helper::PointerTo<ClassAWithIterSwapSelf>,
                                                     test_iterator_helper::PointerTo<ClassCWithSemiIterSwapA>>{}()));

  // using test_type_result = decltype(::portable_stl::ranges::iter_swap(
  //   ::portable_stl::declval<test_iterator_helper::PointerTo<ClassAWithIterSwapSelf>>(),
  //   ::portable_stl::declval<test_iterator_helper::PointerTo<ClassBWithIterSwapA>>()));
}

TEST(iterator_concepts, weakly_incrementable_fundamental) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::weakly_incrementable<std::int32_t>;
    test_type checker{};
    EXPECT_TRUE((checker()));
  }
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::concepts_helper::signed_integer_like<std::int32_t>;
    EXPECT_TRUE((test_type{}()));
  }

  EXPECT_TRUE((::portable_stl::weakly_incrementable<std::int32_t>{}()));
  EXPECT_TRUE((::portable_stl::weakly_incrementable<std::int32_t *>{}()));
  EXPECT_TRUE((::portable_stl::weakly_incrementable<std::int32_t const *>{}()));
  EXPECT_TRUE((::portable_stl::weakly_incrementable<std::int32_t **>{}()));

  EXPECT_FALSE((::portable_stl::weakly_incrementable<bool>{}()));
  EXPECT_FALSE((::portable_stl::weakly_incrementable<std::int32_t[]>{}()));
  EXPECT_FALSE((::portable_stl::weakly_incrementable<std::int32_t[10]>{}()));
  EXPECT_FALSE((::portable_stl::weakly_incrementable<double>{}()));
  EXPECT_FALSE((::portable_stl::weakly_incrementable<std::int32_t &>{}()));
  EXPECT_FALSE((::portable_stl::weakly_incrementable<std::int32_t()>{}()));
  EXPECT_FALSE((::portable_stl::weakly_incrementable<std::int32_t (*)()>{}()));
  EXPECT_FALSE((::portable_stl::weakly_incrementable<std::int32_t (&)()>{}()));
}

TEST(iterator_concepts, weakly_incrementable_user_types) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type        = ::portable_stl::concepts_helper::weakly_incrementable_check_movable<std::int32_t>;
    /**
     * @brief Test result type.
     */
    using test_type_result = typename test_type::type;
    EXPECT_TRUE((test_type_result{}()));
  }
  {
    /**
     * @brief Test type.
     */
    using test_type
      = ::portable_stl::concepts_helper::weakly_incrementable_check_movable<::test_concepts_helpers::not_movable>;
    /**
     * @brief Test result type.
     */
    using test_type_result = typename test_type::type;
    EXPECT_FALSE((test_type_result{}()));
  }

  EXPECT_TRUE((::portable_stl::weakly_incrementable<::test_concepts_helpers::postfix_increment_returns_void>{}()));
  EXPECT_TRUE((::portable_stl::weakly_incrementable<::test_concepts_helpers::postfix_increment_returns_copy>{}()));
  EXPECT_TRUE((::portable_stl::weakly_incrementable<::test_concepts_helpers::has_integral_minus>{}()));
  EXPECT_TRUE(
    (::portable_stl::weakly_incrementable<::test_concepts_helpers::has_distinct_difference_type_and_minus>{}()));
  EXPECT_TRUE((::portable_stl::weakly_incrementable<::test_concepts_helpers::not_default_initializable>{}()));
  EXPECT_TRUE((::portable_stl::weakly_incrementable<::test_concepts_helpers::incrementable_with_difference_type>{}()));
  EXPECT_TRUE(
    (::portable_stl::weakly_incrementable<::test_concepts_helpers::incrementable_without_difference_type>{}()));
  EXPECT_TRUE((::portable_stl::weakly_incrementable<::test_concepts_helpers::difference_type_and_void_minus>{}()));
  EXPECT_TRUE((::portable_stl::weakly_incrementable<::test_concepts_helpers::noncopyable_with_difference_type>{}()));
  EXPECT_TRUE((::portable_stl::weakly_incrementable<::test_concepts_helpers::noncopyable_without_difference_type>{}()));
  EXPECT_TRUE(
    (::portable_stl::weakly_incrementable<::test_concepts_helpers::noncopyable_with_difference_type_and_minus>{}()));

  EXPECT_FALSE((::portable_stl::weakly_incrementable<::test_concepts_helpers::missing_difference_type>{}()));
  EXPECT_FALSE((::portable_stl::weakly_incrementable<::test_concepts_helpers::floating_difference_type>{}()));
  EXPECT_FALSE((::portable_stl::weakly_incrementable<::test_concepts_helpers::non_const_minus>{}()));
  EXPECT_FALSE((::portable_stl::weakly_incrementable<::test_concepts_helpers::non_integral_minus>{}()));
  EXPECT_FALSE((::portable_stl::weakly_incrementable<::test_concepts_helpers::bad_difference_type_good_minus>{}()));
  EXPECT_FALSE((::portable_stl::weakly_incrementable<::test_concepts_helpers::not_movable>{}()));
  EXPECT_FALSE((::portable_stl::weakly_incrementable<::test_concepts_helpers::preinc_not_declared>{}()));
  EXPECT_FALSE((::portable_stl::weakly_incrementable<::test_concepts_helpers::postinc_not_declared>{}()));
}

TEST(iterator_concepts, incrementable) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type        = std::int32_t *;
    /**
     * @brief Test result type.
     */
    using test_type_result = ::portable_stl::incrementable<test_type>;
    EXPECT_TRUE((test_type_result{}()));
  }

  EXPECT_TRUE((::portable_stl::incrementable<std::int32_t>{}()));
  EXPECT_TRUE((::portable_stl::incrementable<std::int32_t *>{}()));
  EXPECT_TRUE((::portable_stl::incrementable<std::int32_t **>{}()));

  EXPECT_FALSE((::portable_stl::incrementable<::test_concepts_helpers::postfix_increment_returns_void>{}()));
  EXPECT_FALSE((::portable_stl::incrementable<::test_concepts_helpers::postfix_increment_returns_copy>{}()));
  EXPECT_FALSE((::portable_stl::incrementable<::test_concepts_helpers::has_integral_minus>{}()));
  EXPECT_FALSE((::portable_stl::incrementable<::test_concepts_helpers::has_distinct_difference_type_and_minus>{}()));
  EXPECT_FALSE((::portable_stl::incrementable<::test_concepts_helpers::not_default_initializable>{}()));
  EXPECT_FALSE((::portable_stl::incrementable<::test_concepts_helpers::noncopyable_with_difference_type>{}()));
  EXPECT_FALSE((::portable_stl::incrementable<::test_concepts_helpers::noncopyable_without_difference_type>{}()));
  EXPECT_FALSE(
    (::portable_stl::incrementable<::test_concepts_helpers::noncopyable_with_difference_type_and_minus>{}()));
  EXPECT_FALSE((::portable_stl::incrementable<::test_concepts_helpers::missing_difference_type>{}()));
  EXPECT_FALSE((::portable_stl::incrementable<::test_concepts_helpers::floating_difference_type>{}()));
  EXPECT_FALSE((::portable_stl::incrementable<::test_concepts_helpers::non_const_minus>{}()));
  EXPECT_FALSE((::portable_stl::incrementable<::test_concepts_helpers::non_integral_minus>{}()));
  EXPECT_FALSE((::portable_stl::incrementable<::test_concepts_helpers::bad_difference_type_good_minus>{}()));
  EXPECT_FALSE((::portable_stl::incrementable<::test_concepts_helpers::not_movable>{}()));
  EXPECT_FALSE((::portable_stl::incrementable<::test_concepts_helpers::preinc_not_declared>{}()));
  EXPECT_FALSE((::portable_stl::incrementable<::test_concepts_helpers::postinc_not_declared>{}()));
}

// gcc tests
TEST(iterator_concepts, input_or_output_iterator) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type        = std::int32_t *;
    /**
     * @brief Test result type.
     */
    using test_type_result = ::portable_stl::input_or_output_iterator<test_type>;
    EXPECT_TRUE((test_type_result{}()));
  }

  // EXPECT_FALSE((::portable_stl::input_or_output_iterator<void *>{}()));
  EXPECT_FALSE((::portable_stl::input_or_output_iterator<void>{}()));
  EXPECT_FALSE((::portable_stl::input_or_output_iterator<std::int32_t>{}()));
  EXPECT_TRUE((::portable_stl::input_or_output_iterator<std::int32_t *>{}()));
  EXPECT_TRUE((::portable_stl::input_or_output_iterator<std::int32_t const *>{}()));

  EXPECT_TRUE((::portable_stl::input_or_output_iterator<test_iterator_helper::tst_input_iterator<std::int32_t *>>{}()));
  EXPECT_TRUE(
    (::portable_stl::input_or_output_iterator<test_iterator_helper::tst_bidirectional_iterator<std::int32_t *>>{}()));
  EXPECT_TRUE(
    (::portable_stl::input_or_output_iterator<test_iterator_helper::tst_random_access_iterator<std::int32_t *>>{}()));

  EXPECT_FALSE((::portable_stl::input_or_output_iterator<test_iterator_helper::missing_dereference>{}()));
  EXPECT_FALSE((::portable_stl::input_or_output_iterator<test_iterator_helper::void_dereference>{}()));
  EXPECT_FALSE((::portable_stl::input_or_output_iterator<test_iterator_helper::not_weakly_incrementable>{}()));

  EXPECT_TRUE((::portable_stl::input_or_output_iterator<test_iterator_helper::tst_input_iterator<std::int32_t *>>{}()));
  EXPECT_TRUE(
    (::portable_stl::input_or_output_iterator<test_iterator_helper::tst_bidirectional_iterator<std::int32_t *>>{}()));
  EXPECT_TRUE(
    (::portable_stl::input_or_output_iterator<test_iterator_helper::tst_random_access_iterator<std::int32_t *>>{}()));
}

TEST(iterator_concepts, input_iterator) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type        = std::int32_t *;
    /**
     * @brief Test result type.
     */
    using test_type_result = ::portable_stl::input_iterator<test_type>;
    EXPECT_TRUE((test_type_result{}()));
  }

  EXPECT_TRUE((::portable_stl::input_iterator<std::int32_t *>{}()));
  EXPECT_TRUE((::portable_stl::input_iterator<std::int32_t const *>{}()));
  EXPECT_TRUE((::portable_stl::input_iterator<std::int32_t volatile *>{}()));
  EXPECT_TRUE((::portable_stl::input_iterator<std::int32_t const volatile *>{}()));

  EXPECT_TRUE((::portable_stl::input_iterator<test_iterator_helper::tst_input_iterator<std::int32_t *>>{}()));
  EXPECT_TRUE((::portable_stl::input_iterator<test_iterator_helper::tst_bidirectional_iterator<std::int32_t *>>{}()));
  EXPECT_TRUE((::portable_stl::input_iterator<test_iterator_helper::tst_random_access_iterator<std::int32_t *>>{}()));
}

TEST(iterator_concepts, forward_iterator) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type        = std::int32_t *;
    /**
     * @brief Test result type.
     */
    using test_type_result = ::portable_stl::forward_iterator<test_type>;
    EXPECT_TRUE((test_type_result{}()));
  }

  EXPECT_TRUE((::portable_stl::forward_iterator<std::int32_t *>{}()));
  EXPECT_TRUE((::portable_stl::forward_iterator<std::int32_t const *>{}()));
  EXPECT_TRUE((::portable_stl::forward_iterator<std::int32_t volatile *>{}()));
  EXPECT_TRUE((::portable_stl::forward_iterator<std::int32_t const volatile *>{}()));

  EXPECT_FALSE((::portable_stl::forward_iterator<test_iterator_helper::tst_input_iterator<std::int32_t *>>{}()));
  EXPECT_TRUE((::portable_stl::forward_iterator<test_iterator_helper::tst_bidirectional_iterator<std::int32_t *>>{}()));
  EXPECT_TRUE((::portable_stl::forward_iterator<test_iterator_helper::tst_random_access_iterator<std::int32_t *>>{}()));
}

TEST(iterator_concepts, bidirectional_iterator) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type        = std::int32_t *;
    /**
     * @brief Test result type.
     */
    using test_type_result = ::portable_stl::bidirectional_iterator<test_type>;
    EXPECT_TRUE((test_type_result{}()));
  }

  {
    /**
     * @brief Test iterator type.
     */
    using iterator_type = std::int32_t *;
    EXPECT_TRUE((typename ::portable_stl::iterator_helper::has_minus_ops<iterator_type>::type{}()));

    ASSERT_TRUE((std::is_same<::portable_stl::contiguous_iterator_tag,
                              ::portable_stl::iterator_helper::iter_concept<iterator_type>>{}));
  }

  EXPECT_TRUE((::portable_stl::bidirectional_iterator<std::int32_t *>{}()));
  EXPECT_TRUE((::portable_stl::bidirectional_iterator<std::int32_t const *>{}()));
  EXPECT_TRUE((::portable_stl::bidirectional_iterator<std::int32_t volatile *>{}()));
  EXPECT_TRUE((::portable_stl::bidirectional_iterator<std::int32_t const volatile *>{}()));

  EXPECT_FALSE((::portable_stl::bidirectional_iterator<test_iterator_helper::tst_input_iterator<std::int32_t *>>{}()));
  EXPECT_TRUE(
    (::portable_stl::bidirectional_iterator<test_iterator_helper::tst_bidirectional_iterator<std::int32_t *>>{}()));
  EXPECT_TRUE(
    (::portable_stl::bidirectional_iterator<test_iterator_helper::tst_random_access_iterator<std::int32_t *>>{}()));
}

TEST(iterator_concepts, random_access_iterator) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type        = std::int32_t *;
    /**
     * @brief Test result type.
     */
    using test_type_result = ::portable_stl::random_access_iterator<test_type>;
    EXPECT_TRUE((test_type_result{}()));
  }

  {
    /**
     * @brief Test iterator type.
     */
    using iterator_type = test_iterator_helper::tst_random_access_iterator<std::int32_t *>;

    EXPECT_TRUE((::portable_stl::bidirectional_iterator<iterator_type>{}()));
    EXPECT_TRUE((::portable_stl::totally_ordered<iterator_type>{}()));
    EXPECT_TRUE((::portable_stl::sized_sentinel_for<iterator_type, iterator_type>{}()));
    ASSERT_TRUE((std::is_same<::portable_stl::random_access_iterator_tag,
                              ::portable_stl::iterator_helper::iter_concept<iterator_type>>{}));
    EXPECT_TRUE(
      (::portable_stl::is_detected<::portable_stl::iterator_helper::has_iter_difference_type_pred, iterator_type>{}()));
    EXPECT_TRUE((typename ::portable_stl::iterator_helper::has_random_ops<iterator_type>::type{}()));
  }

  EXPECT_TRUE((::portable_stl::random_access_iterator<std::int32_t *>{}()));
  EXPECT_TRUE((::portable_stl::random_access_iterator<std::int32_t const *>{}()));
  EXPECT_TRUE((::portable_stl::random_access_iterator<std::int32_t volatile *>{}()));
  EXPECT_TRUE((::portable_stl::random_access_iterator<std::int32_t const volatile *>{}()));

  EXPECT_FALSE((::portable_stl::random_access_iterator<test_iterator_helper::tst_input_iterator<std::int32_t *>>{}()));
  EXPECT_FALSE(
    (::portable_stl::random_access_iterator<test_iterator_helper::tst_bidirectional_iterator<std::int32_t *>>{}()));
  EXPECT_TRUE(
    (::portable_stl::random_access_iterator<test_iterator_helper::tst_random_access_iterator<std::int32_t *>>{}()));
}

TEST(iterator_concepts, contiguous_iterator) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type        = std::int32_t *;
    /**
     * @brief Test result type.
     */
    using test_type_result = ::portable_stl::contiguous_iterator<test_type>;
    EXPECT_TRUE((test_type_result{}()));
  }

  {
    /**
     * @brief Test iterator type.
     */
    using iterator_type = std::int32_t *;
    EXPECT_TRUE((::portable_stl::random_access_iterator<iterator_type>{}()));

    /**
     * @brief Iterator concept type.
     */
    using iter_concept_t = ::portable_stl::iterator_helper::iter_concept<iterator_type>;
    EXPECT_TRUE((::portable_stl::derived_from<iter_concept_t, ::portable_stl::contiguous_iterator_tag>{}()));

    EXPECT_TRUE((::portable_stl::is_lvalue_reference<::portable_stl::iter_reference_t<iterator_type>>{}()));

    EXPECT_TRUE((std::is_same<::portable_stl::iter_value_t<iterator_type>,
                              ::portable_stl::remove_cvref_t<::portable_stl::iter_reference_t<iterator_type>>>{}));

    EXPECT_TRUE((std::is_same<decltype(::portable_stl::to_address(::portable_stl::declval<iterator_type const &>())),
                              ::portable_stl::add_pointer_t<::portable_stl::iter_reference_t<iterator_type>>>{}()));
  }

  EXPECT_TRUE((::portable_stl::contiguous_iterator<std::int32_t *>{}()));
  EXPECT_TRUE((::portable_stl::contiguous_iterator<std::int32_t const *>{}()));
  EXPECT_TRUE((::portable_stl::contiguous_iterator<void **>{}()));

  EXPECT_FALSE((::portable_stl::contiguous_iterator<std::int32_t *const>{}()));
  EXPECT_FALSE((::portable_stl::contiguous_iterator<std::int32_t const *const>{}()));
  EXPECT_FALSE((::portable_stl::contiguous_iterator<void **const>{}()));

  EXPECT_FALSE((::portable_stl::contiguous_iterator<void *>{}()));
  EXPECT_FALSE((::portable_stl::contiguous_iterator<void const *>{}()));
  EXPECT_FALSE((::portable_stl::contiguous_iterator<void volatile *>{}()));
}

TEST(iterator_concepts, sized_sentinel_for) {
  static_cast<void>(test_info_);
  {
    EXPECT_TRUE((typename ::portable_stl::iterator_helper::subtracted<std::int32_t *, std::int32_t *>::type{}()));
    EXPECT_FALSE((typename ::portable_stl::iterator_helper::subtracted<std::int32_t, std::int32_t *>::type{}()));
  }

  EXPECT_TRUE((::portable_stl::sized_sentinel_for<std::int32_t *, std::int32_t *>{}()));

  EXPECT_FALSE((::portable_stl::sized_sentinel_for<std::int32_t, std::int32_t *>{}()));
  EXPECT_FALSE((::portable_stl::sized_sentinel_for<void, std::int32_t *>{}()));
  EXPECT_FALSE((::portable_stl::sized_sentinel_for<void, void>{}()));
  EXPECT_FALSE((::portable_stl::sized_sentinel_for<void *, void *>{}()));
}

TEST(iterator_concepts, cpp17_iterator) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type        = std::int32_t *;
    /**
     * @brief Test result type.
     */
    using test_type_result = ::portable_stl::cpp17_iterator<test_type>;
    EXPECT_TRUE((test_type_result{}()));
  }

  EXPECT_TRUE((::portable_stl::cpp17_iterator<std::int32_t *>{}()));
  EXPECT_TRUE((::portable_stl::cpp17_iterator<std::int32_t const *>{}()));
  EXPECT_TRUE((::portable_stl::cpp17_iterator<std::int32_t volatile *>{}()));
  EXPECT_TRUE((::portable_stl::cpp17_iterator<std::int32_t const volatile *>{}()));

  EXPECT_TRUE((::portable_stl::cpp17_iterator<test_iterator_helper::tst_input_iterator<std::int32_t *>>{}()));
  EXPECT_TRUE((::portable_stl::cpp17_iterator<test_iterator_helper::tst_bidirectional_iterator<std::int32_t *>>{}()));
  EXPECT_TRUE((::portable_stl::cpp17_iterator<test_iterator_helper::tst_random_access_iterator<std::int32_t *>>{}()));
}

TEST(iterator_concepts, cpp17_input_iterator) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type        = std::int32_t *;
    /**
     * @brief Test result type.
     */
    using test_type_result = ::portable_stl::cpp17_input_iterator<test_type>;
    EXPECT_TRUE((test_type_result{}()));
  }
  // details checks
  // {
  //   using t_iterator = std::int32_t *;
  //   using a0         = ::portable_stl::cpp17_iterator<t_iterator>;
  //   EXPECT_TRUE((a0{}()));
  //   using a1 = ::portable_stl::equality_comparable<t_iterator>;
  //   EXPECT_TRUE((a1{}()));
  //   using a2 = typename ::portable_stl::incrementable_traits<t_iterator>::difference_type;
  //   using a3 = typename ::portable_stl::indirectly_readable_traits<t_iterator>::value_type;
  //   using a4 = ::portable_stl::iter_reference_t<t_iterator> &&;
  //   using a5 = typename ::portable_stl::indirectly_readable_traits<t_iterator>::value_type &;
  //   EXPECT_TRUE((std::is_same<void, ::portable_stl::void_t<::portable_stl::common_reference_t<a4, a5>>>{}));
  //   EXPECT_TRUE((std::is_same<void, ::portable_stl::void_t<decltype(*::portable_stl::declval<t_iterator
  //   &>()++)>>{})); using a6 = decltype(*::portable_stl::declval<t_iterator &>()++) &&;
  //   EXPECT_TRUE((std::is_same<void, ::portable_stl::void_t<::portable_stl::common_reference_t<a6, a5>>>{}));
  //   using a7
  //     = ::portable_stl::signed_integral<typename ::portable_stl::incrementable_traits<t_iterator>::difference_type>;
  //   EXPECT_TRUE((a7{}()));
  //   using a8 = typename ::portable_stl::iterator_helper::cpp17_input_iterator_req1<t_iterator>::type;
  //   EXPECT_TRUE((a8{}()));
  //   using a9 = typename ::portable_stl::iterator_helper::cpp17_input_iterator_req2<t_iterator>::type;
  //   EXPECT_TRUE((a9{}()));
  //   using a10 = typename ::portable_stl::iterator_helper::cpp17_input_iterator_req3<t_iterator>::type;
  //   EXPECT_TRUE((a10{}()));
  // }

  EXPECT_TRUE((::portable_stl::cpp17_input_iterator<std::int32_t *>{}()));
  EXPECT_TRUE((::portable_stl::cpp17_input_iterator<std::int32_t const *>{}()));
  EXPECT_TRUE((::portable_stl::cpp17_input_iterator<std::int32_t volatile *>{}()));
  EXPECT_TRUE((::portable_stl::cpp17_input_iterator<std::int32_t const volatile *>{}()));

  EXPECT_TRUE((::portable_stl::cpp17_input_iterator<test_iterator_helper::tst_input_iterator<std::int32_t *>>{}()));
  EXPECT_TRUE(
    (::portable_stl::cpp17_input_iterator<test_iterator_helper::tst_bidirectional_iterator<std::int32_t *>>{}()));
  EXPECT_TRUE(
    (::portable_stl::cpp17_input_iterator<test_iterator_helper::tst_random_access_iterator<std::int32_t *>>{}()));

  EXPECT_FALSE((::portable_stl::cpp17_input_iterator<void>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_input_iterator<void *>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_input_iterator<std::int32_t *const>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_input_iterator<std::int32_t>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_input_iterator<std::int32_t[]>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_input_iterator<std::int32_t[1]>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_input_iterator<std::int32_t()>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_input_iterator<std::int32_t (*)()>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_input_iterator<std::int32_t (&)()>{}()));
}

TEST(iterator_concepts, cpp17_forward_iterator) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type        = std::int32_t *;
    /**
     * @brief Test result type.
     */
    using test_type_result = ::portable_stl::cpp17_forward_iterator<test_type>;
    EXPECT_TRUE((test_type_result{}()));
  }
  // details checks
  // {
  //   using t_iterator = std::int32_t const*;
  //   using a1         = ::portable_stl::iter_reference_t<t_iterator>;
  //   using a2         = typename ::portable_stl::indirectly_readable_traits<t_iterator>::value_type;
  //   using a3         = ::portable_stl::cpp17_input_iterator<t_iterator>;
  //   using a4         = ::portable_stl::constructible_from<t_iterator>;
  //   using a5         = ::portable_stl::is_reference<::portable_stl::iter_reference_t<t_iterator>>;
  //   using a6 = ::portable_stl::remove_cvref_t<::portable_stl::iter_reference_t<t_iterator>>;
  //   using a7 = typename ::portable_stl::indirectly_readable_traits<t_iterator>::value_type;
  //   using a8 = ::portable_stl::same_as<a6, a7>;
  //   using a9  = decltype(::portable_stl::declval<t_iterator &>()++);
  //   using a10 = ::portable_stl::convertible_to<a9, t_iterator const &>;
  //   using a11 = decltype(*::portable_stl::declval<t_iterator &>()++);
  //   using a12 = ::portable_stl::iter_reference_t<t_iterator>;
  //   using a13 = ::portable_stl::same_as<a11, a12>;
  // }

  EXPECT_TRUE((::portable_stl::cpp17_forward_iterator<std::int32_t *>{}()));
  EXPECT_TRUE((::portable_stl::cpp17_forward_iterator<std::int32_t const *>{}()));
  EXPECT_TRUE((::portable_stl::cpp17_forward_iterator<std::int32_t volatile *>{}()));
  EXPECT_TRUE((::portable_stl::cpp17_forward_iterator<std::int32_t const volatile *>{}()));

  EXPECT_TRUE((::portable_stl::cpp17_forward_iterator<test_iterator_helper::tst_input_iterator<std::int32_t *>>{}()));
  EXPECT_TRUE(
    (::portable_stl::cpp17_forward_iterator<test_iterator_helper::tst_bidirectional_iterator<std::int32_t *>>{}()));
  EXPECT_TRUE(
    (::portable_stl::cpp17_forward_iterator<test_iterator_helper::tst_random_access_iterator<std::int32_t *>>{}()));

  EXPECT_FALSE((::portable_stl::cpp17_forward_iterator<void>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_forward_iterator<void *>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_forward_iterator<std::int32_t *const>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_forward_iterator<std::int32_t>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_forward_iterator<std::int32_t[]>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_forward_iterator<std::int32_t[1]>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_forward_iterator<std::int32_t()>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_forward_iterator<std::int32_t (*)()>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_forward_iterator<std::int32_t (&)()>{}()));
}

TEST(iterator_concepts, cpp17_bidirectional_iterator) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type        = std::int32_t *;
    /**
     * @brief Test result type.
     */
    using test_type_result = ::portable_stl::cpp17_bidirectional_iterator<test_type>;
    EXPECT_TRUE((test_type_result{}()));
  }
  // details checks
  // {
  //   using t_iterator = std::int32_t const *;
  //   using a1         = ::portable_stl::iter_reference_t<t_iterator>;
  //   using a2         = typename ::portable_stl::indirectly_readable_traits<t_iterator>::value_type;
  //   using a3         = ::portable_stl::cpp17_input_iterator<t_iterator>;
  //   EXPECT_TRUE((a3{}()));
  //   using a4 = ::portable_stl::constructible_from<t_iterator>;
  //   EXPECT_TRUE((a4{}()));
  //   using a5 = ::portable_stl::is_reference<::portable_stl::iter_reference_t<t_iterator>>;
  //   EXPECT_TRUE((a5{}()));
  //   using a6 = ::portable_stl::remove_cvref_t<::portable_stl::iter_reference_t<t_iterator>>;
  //   using a7 = typename ::portable_stl::indirectly_readable_traits<t_iterator>::value_type;
  //   using a8 = ::portable_stl::same_as<a6, a7>;
  //   EXPECT_TRUE((a8{}()));
  //   using a9  = decltype(::portable_stl::declval<t_iterator &>()++);
  //   using a10 = ::portable_stl::convertible_to<a9, t_iterator const &>;
  //   EXPECT_TRUE((a10{}()));
  //   using a11 = decltype(*::portable_stl::declval<t_iterator &>()++);
  //   using a12 = ::portable_stl::iter_reference_t<t_iterator>;
  //   using a13 = ::portable_stl::same_as<a11, a12>;
  //   EXPECT_TRUE((a13{}()));
  // }

  EXPECT_TRUE((::portable_stl::cpp17_bidirectional_iterator<std::int32_t *>{}()));
  EXPECT_TRUE((::portable_stl::cpp17_bidirectional_iterator<std::int32_t const *>{}()));
  EXPECT_TRUE((::portable_stl::cpp17_bidirectional_iterator<std::int32_t volatile *>{}()));
  EXPECT_TRUE((::portable_stl::cpp17_bidirectional_iterator<std::int32_t const volatile *>{}()));

  EXPECT_FALSE(
    (::portable_stl::cpp17_bidirectional_iterator<test_iterator_helper::tst_input_iterator<std::int32_t *>>{}()));
  EXPECT_TRUE((::portable_stl::cpp17_bidirectional_iterator<
               test_iterator_helper::tst_bidirectional_iterator<std::int32_t *>>{}()));
  EXPECT_TRUE((::portable_stl::cpp17_bidirectional_iterator<
               test_iterator_helper::tst_random_access_iterator<std::int32_t *>>{}()));

  EXPECT_FALSE((::portable_stl::cpp17_bidirectional_iterator<void>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_bidirectional_iterator<void *>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_bidirectional_iterator<std::int32_t *const>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_bidirectional_iterator<std::int32_t>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_bidirectional_iterator<std::int32_t[]>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_bidirectional_iterator<std::int32_t[1]>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_bidirectional_iterator<std::int32_t()>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_bidirectional_iterator<std::int32_t (*)()>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_bidirectional_iterator<std::int32_t (&)()>{}()));
}

TEST(iterator_concepts, cpp17_random_access_iterator) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type        = std::int32_t *;
    /**
     * @brief Test result type.
     */
    using test_type_result = ::portable_stl::cpp17_random_access_iterator<test_type>;
    EXPECT_TRUE((test_type_result{}()));
  }

  EXPECT_TRUE((::portable_stl::cpp17_random_access_iterator<std::int32_t *>{}()));
  EXPECT_TRUE((::portable_stl::cpp17_random_access_iterator<std::int32_t const *>{}()));
  EXPECT_TRUE((::portable_stl::cpp17_random_access_iterator<std::int32_t volatile *>{}()));
  EXPECT_TRUE((::portable_stl::cpp17_random_access_iterator<std::int32_t const volatile *>{}()));

  EXPECT_FALSE(
    (::portable_stl::cpp17_random_access_iterator<test_iterator_helper::tst_input_iterator<std::int32_t *>>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_random_access_iterator<
                test_iterator_helper::tst_bidirectional_iterator<std::int32_t *>>{}()));
  EXPECT_TRUE((::portable_stl::cpp17_random_access_iterator<
               test_iterator_helper::tst_random_access_iterator<std::int32_t *>>{}()));

  EXPECT_FALSE((::portable_stl::cpp17_random_access_iterator<void>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_random_access_iterator<void *>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_random_access_iterator<std::int32_t *const>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_random_access_iterator<std::int32_t>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_random_access_iterator<std::int32_t[]>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_random_access_iterator<std::int32_t[1]>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_random_access_iterator<std::int32_t()>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_random_access_iterator<std::int32_t (*)()>{}()));
  EXPECT_FALSE((::portable_stl::cpp17_random_access_iterator<std::int32_t (&)()>{}()));
}

TEST(iterator_concepts, iter_concept) {
  static_cast<void>(test_info_);
  // [iterator.concepts.general] 1.

  // no ::iterator_concept, so CONCEPT gets from ::iterator_category
  {
    /**
     * @brief Test iterator type.
     */
    using test_iter_type = test_iterator_helper::tst_input_iterator<std::int32_t *>;
    EXPECT_TRUE((std::is_same<::portable_stl::input_iterator_tag,
                              ::portable_stl::iterator_helper::iter_concept<test_iter_type>>{}));
  }
  // no ::iterator_concept, so CONCEPT gets from ::iterator_category
  {
    /**
     * @brief Test iterator type.
     */
    using test_iter_type = test_iterator_helper::tst_bidirectional_iterator<std::int32_t *>;
    EXPECT_TRUE((std::is_same<::portable_stl::bidirectional_iterator_tag,
                              ::portable_stl::iterator_helper::iter_concept<test_iter_type>>{}));
  }
  // no ::iterator_concept, and no ::iterator_category,
  // but iterator_trits< T * > :: iterator_concept = contiguous_iterator_tag
  {
    /**
     * @brief Test iterator type.
     */
    using test_iter_type = std::int32_t *;
    EXPECT_TRUE((std::is_same<::portable_stl::contiguous_iterator_tag,
                              ::portable_stl::iterator_helper::iter_concept<test_iter_type>>{}));
  }
}
