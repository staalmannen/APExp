// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="ranges.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <list>

#include "iterator_helper.h"
#include "portable_stl/array/array.h"
#include "portable_stl/iterator/iter_move.h"
#include "portable_stl/ranges/begin.h"
#include "portable_stl/ranges/cbegin.h"
#include "portable_stl/ranges/cend.h"
#include "portable_stl/ranges/concepts/maybe_borrowed_range.h"
#include "portable_stl/ranges/crbegin.h"
#include "portable_stl/ranges/crend.h"
#include "portable_stl/ranges/data.h"
#include "portable_stl/ranges/empty.h"
#include "portable_stl/ranges/end.h"
#include "portable_stl/ranges/iterator_t.h"
#include "portable_stl/ranges/rbegin.h"
#include "portable_stl/ranges/rend.h"
#include "portable_stl/ranges/size.h"
#include "ranges_helper.h"
#include "test_debug_helper.h"

namespace test_ranges_helper {
constexpr std::int32_t el_2{2};
} // namespace test_ranges_helper

// TEST(ranges, begin) {
//   static_cast<void>(test_info_);

//   using RangeBeginT  = decltype(::portable_stl::ranges::begin);

//   EXPECT_TRUE ((std::is_invocable<RangeBeginT, std::int32_t(&)[10]>{}));
//   EXPECT_TRUE ((std::is_invocable<RangeBeginT, std::int32_t(&)[]>{}));
//   EXPECT_FALSE((std::is_invocable<RangeBeginT, std::int32_t(&&)[10]>{}));
//   EXPECT_FALSE((std::is_invocable<RangeBeginT, std::int32_t(&&)[]>{}));
// }

TEST(ranges, begin_c_array) {
  static_cast<void>(test_info_);

  std::int32_t array[1];
  auto         test_begin = ::portable_stl::ranges::begin(array);

  EXPECT_TRUE((std::is_same<decltype(test_begin), decltype(array + 0)>{}));
  EXPECT_EQ(test_begin, &array[0]);

  EXPECT_TRUE(noexcept(::portable_stl::ranges::begin(array)));

  constexpr std::int64_t array_constexpr[]{0, 1};
  EXPECT_EQ(::portable_stl::ranges::begin(array_constexpr), &array_constexpr[0]);
}

TEST(ranges, begin_array) {
  static_cast<void>(test_info_);

  ::portable_stl::array<std::int32_t, test_ranges_helper::el_2> array{
    {0, 1}
  };
  auto test_begin = ::portable_stl::ranges::begin(array);

  EXPECT_TRUE((std::is_same<decltype(test_begin), decltype(&array[1])>{}));
  EXPECT_EQ(test_begin, &array[0]);
  static_cast<void>(test_begin);

  EXPECT_TRUE(noexcept(::portable_stl::ranges::begin(array)));
}

TEST(ranges, begin_helpers) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::class_or_enum<test_ranges_helper::non_empty_class>;
    EXPECT_TRUE((test_type{}()));
    /**
     * @brief Test type.
     */
    using test_type2 = ::portable_stl::class_or_enum<std::int32_t>;
    EXPECT_FALSE((test_type2{}()));
  }
  {
    /**
     * @brief Tested class.
     */
    using value_type = std::int32_t[1];
    /**
     * @brief Result type.
     */
    using test_type1 = ::portable_stl::ranges::maybe_borrowed_range<value_type>;
    /**
     * @brief Result type.
     */
    using test_type2 = ::portable_stl::ranges::begin_impl_helper::member_begin<value_type>;
    /**
     * @brief Result type.
     */
    using test_type3 = ::portable_stl::ranges::begin_impl_helper::unqualified_begin<value_type>;
    EXPECT_FALSE((test_type1{}()));
    EXPECT_FALSE((test_type2{}()));
    EXPECT_FALSE((test_type3{}()));
  }
  {
    /**
     * @brief Tested class.
     */
    using value_type = test_ranges_helper::non_empty_class[];
    /**
     * @brief Result type.
     */
    using test_type1 = ::portable_stl::ranges::maybe_borrowed_range<value_type>;
    /**
     * @brief Result type.
     */
    using test_type2 = ::portable_stl::ranges::begin_impl_helper::member_begin<value_type>;
    /**
     * @brief Result type.
     */
    using test_type3 = ::portable_stl::ranges::begin_impl_helper::unqualified_begin<value_type>;
    EXPECT_FALSE((test_type1{}()));
    EXPECT_FALSE((test_type2{}()));
    EXPECT_FALSE((test_type3{}()));
  }
  {
    /**
     * @brief Tested class.
     */
    using value_type = ::portable_stl::array<std::int32_t, 2> &;
    /**
     * @brief Result type.
     */
    using test_type1 = ::portable_stl::ranges::maybe_borrowed_range<value_type>;
    /**
     * @brief Result type.
     */
    using test_type2 = ::portable_stl::ranges::begin_impl_helper::member_begin<value_type>;
    /**
     * @brief Result type.
     */
    using test_type3 = ::portable_stl::ranges::begin_impl_helper::unqualified_begin<value_type>;
    EXPECT_TRUE((test_type1{}()));
    EXPECT_TRUE((test_type2{}()));
    EXPECT_FALSE((test_type3{}()));
  }
  {
    /**
     * @brief Tested class.
     */
    using value_type = test_iterator_helper::container_with_insert &;
    /**
     * @brief Result type.
     */
    using test_type1 = ::portable_stl::ranges::maybe_borrowed_range<value_type>;
    /**
     * @brief Result type.
     */
    using test_type2 = ::portable_stl::ranges::begin_impl_helper::member_begin<value_type>;
    /**
     * @brief Result type.
     */
    using test_type3
      = ::portable_stl::input_or_output_iterator<decltype(::portable_stl::declval<value_type>().begin())>;
    /**
     * @brief Result type.
     */
    using test_type4 = ::portable_stl::ranges::begin_impl_helper::unqualified_begin<value_type>;
    EXPECT_TRUE((test_type1{}()));
    EXPECT_TRUE((test_type2{}()));
    EXPECT_TRUE((test_type3{}()));
    EXPECT_FALSE((test_type4{}()));
  }
}

TEST(ranges, begin) {
  static_cast<void>(test_info_);
  {
    std::int32_t item[1]{1};
    EXPECT_EQ(1, *::portable_stl::ranges::begin(item));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::begin(item)));
    static_cast<void>(item);
  }
  {
    // check test function itself
    {
      test_ranges_helper::has_begin_member_can_throw<false> item;
      ASSERT_EQ(1, *item.begin());
      ASSERT_TRUE(noexcept(item.begin()));
    }
    test_ranges_helper::has_begin_member_can_throw<false> item;
    EXPECT_EQ(1, *::portable_stl::ranges::begin(item));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::begin(item)));
  }
  {
    // check test function itself
    {
      test_ranges_helper::has_begin_member_can_throw<true> item;
      ASSERT_EQ(1, *item.begin());
      ASSERT_FALSE(noexcept(item.begin()));
    }
    test_ranges_helper::has_begin_member_can_throw<true> item;
    EXPECT_EQ(1, *::portable_stl::ranges::begin(item));
    EXPECT_FALSE(noexcept(::portable_stl::ranges::begin(item)));
  }
  {
    // check test function itself
    {
      test_ranges_helper::has_begin_func_can_throw<false> item;
      ASSERT_EQ(0, *begin(item));
      ASSERT_TRUE(noexcept(begin(item)));
    }
    test_ranges_helper::has_begin_func_can_throw<false> item;
    EXPECT_EQ(0, *::portable_stl::ranges::begin(item));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::begin(item)));
  }
  {
    // check test function itself
    {
      test_ranges_helper::has_begin_func_can_throw<true> item;
      ASSERT_EQ(0, *begin(item));
      ASSERT_FALSE(noexcept(begin(item)));
    }
    test_ranges_helper::has_begin_func_can_throw<true> item;
    EXPECT_EQ(0, *::portable_stl::ranges::begin(item));
    EXPECT_FALSE(noexcept(::portable_stl::ranges::begin(item)));
  }
}

TEST(ranges, rbegin) {
  static_cast<void>(test_info_);
  {
    std::int32_t item[test_ranges_helper::el_2]{1, 0};
    EXPECT_EQ(0, *::portable_stl::ranges::rbegin(item));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::rbegin(item)));
    static_cast<void>(item);
  }
  {
    /**
     * @brief Tested class.
     */
    using value_type = test_ranges_helper::has_rbegin_member_can_throw<false> &;
    /**
     * @brief Result type.
     */
    using test_type1 = ::portable_stl::ranges::maybe_borrowed_range<value_type>;
    /**
     * @brief Result type.
     */
    using test_type2 = ::portable_stl::ranges::rbegin_impl_helper::member_rbegin<value_type>;
    /**
     * @brief Result type.
     */
    using test_type3 = ::portable_stl::ranges::rbegin_impl_helper::unqualified_rbegin<value_type>;
    /**
     * @brief Result type.
     */
    using test_type4 = ::portable_stl::ranges::rbegin_impl_helper::is_reversable<value_type>;
    EXPECT_TRUE((test_type1{}()));
    EXPECT_TRUE((test_type2{}()));
    EXPECT_FALSE((test_type3{}()));
    EXPECT_FALSE((test_type4{}()));

    EXPECT_TRUE(
      (::portable_stl::input_or_output_iterator<decltype(::portable_stl::declval<value_type &>().rbegin())>{}()));
  }
  // .rbegin()
  {
    // check test function itself
    {
      test_ranges_helper::has_rbegin_member_can_throw<false> item;
      ASSERT_EQ(1, *item.rbegin());
      ASSERT_TRUE(noexcept(item.rbegin()));
    }
    test_ranges_helper::has_rbegin_member_can_throw<false> item;
    EXPECT_EQ(1, *::portable_stl::ranges::rbegin(item));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::rbegin(item)));
  }
  // .rbegin()
  {
    // check test function itself
    {
      test_ranges_helper::has_rbegin_member_can_throw<true> item;
      ASSERT_EQ(1, *item.rbegin());
      ASSERT_FALSE(noexcept(item.rbegin()));
    }
    test_ranges_helper::has_rbegin_member_can_throw<true> item;
    EXPECT_EQ(1, *::portable_stl::ranges::rbegin(item));
    EXPECT_FALSE(noexcept(::portable_stl::ranges::rbegin(item)));
  }
  // rbegin()
  {
    // check test function itself
    {
      test_ranges_helper::has_rbegin_func_can_throw<false> item;
      ASSERT_EQ(0, *rbegin(item));
      ASSERT_TRUE(noexcept(rbegin(item)));
    }
    test_ranges_helper::has_rbegin_func_can_throw<false> item;
    EXPECT_EQ(0, *::portable_stl::ranges::rbegin(item));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::rbegin(item)));
  }
  // rbegin()
  {
    // check test function itself
    {
      test_ranges_helper::has_rbegin_func_can_throw<true> item;
      ASSERT_EQ(0, *rbegin(item));
      ASSERT_FALSE(noexcept(rbegin(item)));
    }
    test_ranges_helper::has_rbegin_func_can_throw<true> item;
    EXPECT_EQ(0, *::portable_stl::ranges::rbegin(item));
    EXPECT_FALSE(noexcept(::portable_stl::ranges::rbegin(item)));
  }
  // begin()+end()+reverse
  {
    std::int32_t value[2]{0, 1};
    // check test function itself
    {
      test_ranges_helper::has_begin_end_member_can_throw<false, false> item{&value[0], &value[1]};
      ASSERT_EQ(0, *::portable_stl::ranges::begin(item));
      ASSERT_EQ(1, *::portable_stl::ranges::end(item));
      ASSERT_TRUE(noexcept(::portable_stl::ranges::begin(item)));
      ASSERT_TRUE(noexcept(::portable_stl::ranges::end(item)));
    }
    test_ranges_helper::has_begin_end_member_can_throw<false, false> item{&value[0], &value[1]};
    auto                                                             ptr = ::portable_stl::ranges::rbegin(item);
    EXPECT_EQ(0, *ptr);
    EXPECT_TRUE(noexcept(::portable_stl::ranges::rbegin(item)));
  }
  // begin()+end()+reverse
  {
    std::int32_t value[2]{0, 1};
    // check test function itself
    {
      test_ranges_helper::has_begin_end_member_can_throw<false, true> item{&value[0], &value[1]};
      ASSERT_EQ(0, *::portable_stl::ranges::begin(item));
      ASSERT_EQ(1, *::portable_stl::ranges::end(item));
      ASSERT_TRUE(noexcept(::portable_stl::ranges::begin(item)));
      ASSERT_FALSE(noexcept(::portable_stl::ranges::end(item)));
    }
    test_ranges_helper::has_begin_end_member_can_throw<false, true> item{&value[0], &value[1]};
    EXPECT_EQ(0, *::portable_stl::ranges::rbegin(item));
    ASSERT_FALSE(noexcept(::portable_stl::ranges::rbegin(item)));
  }
}

TEST(ranges, iterator_t) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Tested class.
     */
    using array_t            = std::int32_t[1];
    /**
     * @brief Result type.
     */
    using test_iter_get_type = ::portable_stl::ranges::iterator_t<array_t>;
    EXPECT_TRUE((std::is_same<test_iter_get_type, std::int32_t *>{}));
  }
  {
    /**
     * @brief Tested class.
     */
    using array_t            = test_ranges_helper::non_empty_class[];
    /**
     * @brief Result type.
     */
    using test_iter_get_type = ::portable_stl::ranges::iterator_t<array_t>;
    EXPECT_TRUE((std::is_same<test_iter_get_type, test_ranges_helper::non_empty_class *>{}));
  }
  {
    /**
     * @brief Tested class.
     */
    using container_t        = test_iterator_helper::container_with_insert;
    /**
     * @brief Result type.
     */
    using test_iter_get_type = ::portable_stl::ranges::iterator_t<container_t>;
    EXPECT_TRUE((std::is_same<test_iter_get_type, container_t::iterator>{}));
  }
}

TEST(ranges, iter_move_helpers) {
  static_cast<void>(test_info_);
  /**
   * @brief Test type.
   */
  using base_type = std::int32_t *;
  {
    /**
     * @brief Result type.
     */
    using check_type = typename ::portable_stl::ranges::iter_move_impl::adl_iter_move<base_type>::type;
    EXPECT_FALSE((check_type{}()));

    /**
     * @brief Result type.
     */
    using check_type2 = typename ::portable_stl::ranges::iter_move_impl::adl_iter_move<
      test_ranges_helper::has_adl_iter_move_can_throw<true>>::type;
    EXPECT_TRUE((check_type2{}()));
  }
  {
    /**
     * @brief Result type.
     */
    using check_type = typename ::portable_stl::ranges::iter_move_impl::move_deref<base_type>::type;
    EXPECT_TRUE((check_type{}()));
  }
  {
    /**
     * @brief Result type.
     */
    using check_type = typename ::portable_stl::ranges::iter_move_impl::just_deref<base_type>::type;
    EXPECT_FALSE((check_type{}()));
  }
}

TEST(ranges, iter_move) {
  static_cast<void>(test_info_);
  // class has custom iter_move.
  {
    // check test function itself
    {
      test_ranges_helper::has_adl_iter_move_can_throw<false> item;
      ASSERT_EQ(1, test_ranges_helper::iter_move(item));
      ASSERT_TRUE(noexcept(test_ranges_helper::iter_move(item)));
    }
    test_ranges_helper::has_adl_iter_move_can_throw<false> item;
    // check that the desired overload has been selected
    ASSERT_TRUE((std::is_same<std::int64_t, decltype(::portable_stl::ranges::iter_move(item))>{}));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::iter_move(item)));
    static_cast<void>(item);
  }
  {
    // check test function itselft
    {
      test_ranges_helper::has_adl_iter_move_can_throw<true> item;
      ASSERT_EQ(1, test_ranges_helper::iter_move(item));
      ASSERT_FALSE(noexcept(test_ranges_helper::iter_move(item)));
    }
    test_ranges_helper::has_adl_iter_move_can_throw<true> item;
    // check that the desired overload has been selected
    ASSERT_TRUE((std::is_same<std::int64_t, decltype(::portable_stl::ranges::iter_move(item))>{}));
    EXPECT_FALSE(noexcept(::portable_stl::ranges::iter_move(item)));
    static_cast<void>(item);
  }

  // class has dereferenceable lvalue.
  {
    // check test function itself
    {
      test_ranges_helper::lvalue_deref_can_throw<false> item;
      ASSERT_EQ(0, *item);
      ASSERT_TRUE(noexcept(*item));
    }
    test_ranges_helper::lvalue_deref_can_throw<false> item;
    // check that the desired overload has been selected
    ASSERT_TRUE((std::is_same<std::int32_t &&, decltype(::portable_stl::ranges::iter_move(item))>{}));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::iter_move(item)));
    static_cast<void>(item);
  }
  {
    // check test function itself
    {
      test_ranges_helper::lvalue_deref_can_throw<true> item;
      ASSERT_EQ(0, *item);
      ASSERT_FALSE(noexcept(*item));
    }
    test_ranges_helper::lvalue_deref_can_throw<true> item;
    // check that the desired overload has been selected
    ASSERT_TRUE((std::is_same<std::int32_t &&, decltype(::portable_stl::ranges::iter_move(item))>{}));
    EXPECT_FALSE(noexcept(::portable_stl::ranges::iter_move(item)));
    static_cast<void>(item);
  }

  // class just could be dereferencad.
  {
    // check test function itself
    {
      test_ranges_helper::rvalue_deref_can_throw<false> item;
      ASSERT_EQ(1, *item);
      ASSERT_TRUE(noexcept(*item));
    }
    test_ranges_helper::rvalue_deref_can_throw<false> item;
    // check that the desired overload has been selected
    ASSERT_TRUE((std::is_same<std::int16_t, decltype(::portable_stl::ranges::iter_move(item))>{}));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::iter_move(item)));
    static_cast<void>(item);
  }
  {
    // check test function itself
    {
      test_ranges_helper::rvalue_deref_can_throw<true> item;
      ASSERT_EQ(1, *item);
      ASSERT_FALSE(noexcept(*item));
    }
    test_ranges_helper::rvalue_deref_can_throw<true> item;
    // check that the desired overload has been selected
    ASSERT_TRUE((std::is_same<std::int16_t, decltype(::portable_stl::ranges::iter_move(item))>{}));
    EXPECT_FALSE(noexcept(::portable_stl::ranges::iter_move(item)));
    static_cast<void>(item);
  }
}

TEST(ranges, iter_swap) {
  static_cast<void>(test_info_);

  // std::int32_t *
  {
    std::int32_t value1{0};
    std::int32_t value2{1};
    auto         iter1 = &value1;
    auto         iter2 = &value2;

    ::portable_stl::ranges::iter_swap2(iter1, iter2);
    ASSERT_EQ(1, *iter1);
    ASSERT_EQ(0, *iter2);
  }

  // class has custom iter_swap.
  {
    std::int32_t                                           value1{0};
    std::int32_t                                           value2{1};
    test_ranges_helper::has_adl_iter_swap_can_throw<false> item1{value1};
    test_ranges_helper::has_adl_iter_swap_can_throw<false> item2{value2};

    ::portable_stl::ranges::iter_swap2(item1, item2);
    // check that the desired overload has been selected
    ASSERT_EQ(1, item1.test_getter());
    ASSERT_EQ(0, item2.test_getter());

    EXPECT_TRUE(noexcept(::portable_stl::ranges::iter_swap2(item1, item2)));
  }
  {
    std::int32_t                                          value1{0};
    std::int32_t                                          value2{1};
    test_ranges_helper::has_adl_iter_swap_can_throw<true> item1{value1};
    test_ranges_helper::has_adl_iter_swap_can_throw<true> item2{value2};

    ::portable_stl::ranges::iter_swap2(item1, item2);
    // check that the desired overload has been selected
    ASSERT_EQ(1, item1.test_getter());
    ASSERT_EQ(0, item2.test_getter());

    EXPECT_FALSE(noexcept(::portable_stl::ranges::iter_swap2(item1, item2)));
  }

  // class has dereferenceable lvalue for swap
  {
    // internal logic
    {
      /**
       * @brief Test type.
       */
      using test_type = test_ranges_helper::indirectly_deref_swappable_can_throw<false>;
      EXPECT_FALSE((::portable_stl::ranges::iter_swap_impl::is_adl_iter_swap<test_type, test_type>{}()));
      EXPECT_TRUE((::portable_stl::indirectly_readable<test_type>{}()));
      EXPECT_TRUE((::portable_stl::common_reference_with<test_type, test_type>{}()));
      EXPECT_TRUE(
        (::portable_stl::ranges::swap_impl::is_adl_swappable_with<test_ranges_helper::has_adl_swap const &,
                                                                  test_ranges_helper::has_adl_swap const &>{}()));
      EXPECT_TRUE((::portable_stl::swappable_with<::portable_stl::iter_reference_t<test_type>,
                                                  ::portable_stl::iter_reference_t<test_type>>{}()));
      EXPECT_TRUE((::portable_stl::ranges::iter_swap_impl::is_readable_swappable<test_type, test_type>{}()));
    }
    test_ranges_helper::indirectly_deref_swappable_can_throw<false> item1;
    test_ranges_helper::indirectly_deref_swappable_can_throw<false> item2;

    ::portable_stl::ranges::iter_swap2(item1, item2);

    EXPECT_TRUE(noexcept(::portable_stl::ranges::iter_swap2(item1, item2)));
  }
  {
    test_ranges_helper::indirectly_deref_swappable_can_throw<true> item1;
    test_ranges_helper::indirectly_deref_swappable_can_throw<true> item2;

    ::portable_stl::ranges::iter_swap2(item1, item2);

    EXPECT_FALSE(noexcept(::portable_stl::ranges::iter_swap2(item1, item2)));
  }
}

TEST(ranges, end_helpers) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Tested class.
     */
    using value_type = std::int32_t[1];
    /**
     * @brief Result type.
     */
    using test_type  = ::portable_stl::ranges::end_impl_helper::unqualified_end<value_type>;
    EXPECT_FALSE((test_type{}()));
  }
  {
    /**
     * @brief Tested class.
     */
    using value_type = test_ranges_helper::has_end_member_can_throw<false> &;
    /**
     * @brief Result type.
     */
    using test_type1 = ::portable_stl::ranges::maybe_borrowed_range<value_type>;
    /**
     * @brief Result type.
     */
    using test_type2 = ::portable_stl::ranges::end_impl_helper::member_end<value_type>;
    /**
     * @brief Result type.
     */
    using test_type3 = ::portable_stl::ranges::end_impl_helper::unqualified_end<value_type>;
    EXPECT_TRUE((test_type1{}()));
    EXPECT_TRUE((test_type2{}()));
    EXPECT_FALSE((test_type3{}()));
  }
  {
    /**
     * @brief Tested class.
     */
    using value_type = test_ranges_helper::has_end_func_can_throw<false> &;
    /**
     * @brief Result type.
     */
    using test_type1 = ::portable_stl::ranges::maybe_borrowed_range<value_type>;
    /**
     * @brief Result type.
     */
    using test_type2 = ::portable_stl::ranges::end_impl_helper::member_end<value_type>;
    /**
     * @brief Result type.
     */
    using test_type3 = typename ::portable_stl::ranges::end_impl_helper::is_sentinel_for<value_type>::type;
    /**
     * @brief Result type.
     */
    using test_type4 = typename ::portable_stl::ranges::end_impl_helper::has_adl_end_impl<value_type>::type;
    /**
     * @brief Result type.
     */
    using test_type5 = ::portable_stl::ranges::end_impl_helper::unqualified_end<value_type>;

    EXPECT_TRUE((test_type1{}()));
    EXPECT_FALSE((test_type2{}()));
    EXPECT_TRUE((test_type3{}()));
    EXPECT_TRUE((test_type4{}()));
    EXPECT_TRUE((test_type5{}()));
  }
}

TEST(ranges, end) {
  static_cast<void>(test_info_);
  {
    std::int32_t item[test_ranges_helper::el_2]{1, 0};
    EXPECT_TRUE(noexcept(::portable_stl::ranges::end(item)));
    static_cast<void>(item);
  }
  {
    // check test function itself
    {
      test_ranges_helper::has_end_member_can_throw<false> item;
      ASSERT_EQ(1, *item.end());
      ASSERT_EQ(1, *item.begin());
      ASSERT_TRUE(noexcept(item.end()));
    }
    test_ranges_helper::has_end_member_can_throw<false> item;
    EXPECT_EQ(1, *::portable_stl::ranges::end(item));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::end(item)));
  }
  {
    // check test function itself
    {
      test_ranges_helper::has_end_member_can_throw<true> item;
      ASSERT_EQ(1, *item.end());
      ASSERT_EQ(1, *item.begin());
      ASSERT_FALSE(noexcept(item.end()));
    }
    test_ranges_helper::has_end_member_can_throw<true> item;
    EXPECT_EQ(1, *::portable_stl::ranges::end(item));
    EXPECT_FALSE(noexcept(::portable_stl::ranges::end(item)));
  }
  {
    // check test function itself
    {
      test_ranges_helper::has_end_func_can_throw<false> item;
      ASSERT_EQ(0, *end(item));
      ASSERT_EQ(0, *item.begin());
      ASSERT_TRUE(noexcept(end(item)));
    }
    test_ranges_helper::has_end_func_can_throw<false> item;
    EXPECT_EQ(0, *::portable_stl::ranges::end(item));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::end(item)));
  }
  {
    // check test function itself
    {
      test_ranges_helper::has_end_func_can_throw<true> item;
      ASSERT_EQ(0, *end(item));
      ASSERT_FALSE(noexcept(end(item)));
    }
    test_ranges_helper::has_end_func_can_throw<true> item;
    EXPECT_EQ(0, *::portable_stl::ranges::end(item));
    EXPECT_FALSE(noexcept(::portable_stl::ranges::end(item)));
  }
}

TEST(ranges, rend) {
  static_cast<void>(test_info_);
  {
    std::int32_t item[test_ranges_helper::el_2]{1, 0};
    EXPECT_EQ(1, *(--::portable_stl::ranges::rend(item)));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::rend(item)));
    static_cast<void>(item);
  }
  {
    /**
     * @brief Tested class.
     */
    using value_type = test_ranges_helper::has_rend_member_can_throw<false> &;
    /**
     * @brief Result type.
     */
    using test_type1 = ::portable_stl::ranges::maybe_borrowed_range<value_type>;
    /**
     * @brief Result type.
     */
    using test_type2 = ::portable_stl::ranges::rend_impl_helper::member_rend<value_type>;
    /**
     * @brief Result type.
     */
    using test_type3 = ::portable_stl::ranges::rend_impl_helper::unqualified_rend<value_type>;
    /**
     * @brief Result type.
     */
    using test_type4 = ::portable_stl::ranges::rend_impl_helper::is_reversable<value_type>;
    EXPECT_TRUE((test_type1{}()));
    EXPECT_TRUE((test_type2{}()));
    EXPECT_FALSE((test_type3{}()));
    EXPECT_FALSE((test_type4{}()));
  }
  // .rend()
  {
    // check test function itself
    {
      test_ranges_helper::has_rend_member_can_throw<false> item;
      ASSERT_EQ(1, *item.rend());
      ASSERT_EQ(1, *item.rbegin());
      ASSERT_TRUE(noexcept(item.rend()));
    }
    test_ranges_helper::has_rend_member_can_throw<false> item;
    EXPECT_EQ(1, *::portable_stl::ranges::rend(item));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::rend(item)));
  }
  // .rend()
  {
    // check test function itself
    {
      test_ranges_helper::has_rend_member_can_throw<true> item;
      ASSERT_EQ(1, *item.rend());
      ASSERT_FALSE(noexcept(item.rend()));
    }
    test_ranges_helper::has_rend_member_can_throw<true> item;
    EXPECT_EQ(1, *::portable_stl::ranges::rend(item));
    EXPECT_FALSE(noexcept(::portable_stl::ranges::rend(item)));
  }
  // rend()
  {
    // check test function itself
    {
      test_ranges_helper::has_rend_func_can_throw<false> item;
      ASSERT_EQ(0, *rend(item));
      ASSERT_EQ(0, *item.rbegin());
      ASSERT_TRUE(noexcept(rend(item)));
      ASSERT_TRUE(noexcept(item.rbegin()));
    }
    test_ranges_helper::has_rend_func_can_throw<false> item;
    EXPECT_EQ(0, *::portable_stl::ranges::rend(item));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::rend(item)));
  }
  // rend()
  {
    // check test function itself
    {
      test_ranges_helper::has_rend_func_can_throw<true> item;
      ASSERT_EQ(0, *rend(item));
      ASSERT_FALSE(noexcept(rend(item)));
    }
    test_ranges_helper::has_rend_func_can_throw<true> item;
    EXPECT_EQ(0, *::portable_stl::ranges::rend(item));
    EXPECT_FALSE(noexcept(::portable_stl::ranges::rend(item)));
  }
  // begin()+end()+reverse
  {
    std::int32_t value[2]{0, 1};
    // check test function itself
    {
      test_ranges_helper::has_begin_end_member_can_throw<false, false> item{&value[0], &value[1]};
      ASSERT_EQ(0, *::portable_stl::ranges::begin(item));
      ASSERT_EQ(1, *::portable_stl::ranges::end(item));
      ASSERT_TRUE(noexcept(::portable_stl::ranges::begin(item)));
      ASSERT_TRUE(noexcept(::portable_stl::ranges::end(item)));
    }
    test_ranges_helper::has_begin_end_member_can_throw<false, false> item{&value[0], &value[1]};
    EXPECT_EQ(0, *(--::portable_stl::ranges::rend(item)));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::rend(item)));
  }
  // begin()+end()+reverse
  {
    std::int32_t value[2]{0, 1};
    // check test function itself
    {
      test_ranges_helper::has_begin_end_member_can_throw<true, false> item{&value[0], &value[1]};
      ASSERT_EQ(0, *::portable_stl::ranges::begin(item));
      ASSERT_EQ(1, *::portable_stl::ranges::end(item));
      ASSERT_FALSE(noexcept(::portable_stl::ranges::begin(item)));
      ASSERT_TRUE(noexcept(::portable_stl::ranges::end(item)));
    }
    test_ranges_helper::has_begin_end_member_can_throw<true, false> item{&value[0], &value[1]};
    EXPECT_EQ(0, *(--::portable_stl::ranges::rend(item)));
    ASSERT_FALSE(noexcept(::portable_stl::ranges::rend(item)));
  }
}

TEST(ranges, size_helpers) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Tested class.
     */
    using value_type = test_ranges_helper::has_size_member_can_throw<false>;
    /**
     * @brief Result type.
     */
    using test_type1 = ::portable_stl::ranges::size_impl_helper::is_size_enabled<value_type>;
    /**
     * @brief Result type.
     */
    using test_type2
      = ::portable_stl::ranges::size_impl_helper::integer_like<decltype(::portable_stl::declval<value_type>().size())>;
    /**
     * @brief Result type.
     */
    using test_type3 = ::portable_stl::ranges::size_impl_helper::member_size<value_type>;
    /**
     * @brief Result type.
     */
    using test_type4 = ::portable_stl::ranges::size_impl_helper::unqualified_size<value_type>;

    EXPECT_TRUE((test_type1{}()));
    EXPECT_TRUE((test_type2{}()));
    EXPECT_TRUE((test_type3{}()));
    EXPECT_FALSE((test_type4{}()));
  }
  {
    /**
     * @brief Tested class.
     */
    using value_type = test_ranges_helper::has_size_func_can_throw<false> &;
    /**
     * @brief Result type.
     */
    using test_type1 = ::portable_stl::ranges::size_impl_helper::is_size_enabled<value_type>;
    /**
     * @brief Result type.
     */
    using test_type2
      = ::portable_stl::ranges::size_impl_helper::integer_like<decltype(size(::portable_stl::declval<value_type>()))>;
    /**
     * @brief Result type.
     */
    using test_type3 = ::portable_stl::ranges::size_impl_helper::member_size<value_type>;
    /**
     * @brief Result type.
     */
    using test_type4 = ::portable_stl::ranges::size_impl_helper::unqualified_size<value_type>;

    EXPECT_TRUE((test_type1{}()));
    EXPECT_TRUE((test_type2{}()));
    EXPECT_FALSE((test_type3{}()));
    EXPECT_TRUE((test_type4{}()));
  }
}

TEST(ranges, size) {
  static_cast<void>(test_info_);
  // array
  {
    std::int32_t item[1]{1};
    EXPECT_EQ(1, ::portable_stl::ranges::size(item));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::size(item)));
  }
  {
    std::int32_t item[test_ranges_helper::el_2][1]{{1}, {1}};
    EXPECT_EQ(test_ranges_helper::el_2, ::portable_stl::ranges::size(item));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::size(item)));
  }
  // msvc has bug on c-style array move.
  // {
  //   std::int32_t item[1]{1};
  //   EXPECT_EQ(1, ::portable_stl::ranges::size(std::move(item)));
  //   EXPECT_TRUE(noexcept(::portable_stl::ranges::size(std::move(item))));
  // }

  // member .size()
  {
    // check test function itself
    {
      ASSERT_EQ(1, test_ranges_helper::has_size_member_can_throw<false>::size());
      ASSERT_TRUE(noexcept(test_ranges_helper::has_size_member_can_throw<false>::size()));
    }
    test_ranges_helper::has_size_member_can_throw<false> item;
    EXPECT_EQ(1, ::portable_stl::ranges::size(item));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::size(item)));
  }
  {
    // check test function itself
    {
      ASSERT_EQ(1, test_ranges_helper::has_size_member_can_throw<true>::size());
      ASSERT_FALSE(noexcept(test_ranges_helper::has_size_member_can_throw<true>::size()));
    }
    test_ranges_helper::has_size_member_can_throw<true> item;
    EXPECT_EQ(1, ::portable_stl::ranges::size(item));
    EXPECT_FALSE(noexcept(::portable_stl::ranges::size(item)));
  }

  // adl size()
  {
    // check test function itself
    {
      test_ranges_helper::has_size_func_can_throw<false> item;
      ASSERT_EQ(0, size(item));
      ASSERT_TRUE(noexcept(size(item)));
    }
    test_ranges_helper::has_size_func_can_throw<false> item;
    EXPECT_EQ(0, ::portable_stl::ranges::size(item));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::size(item)));
  }
  {
    // check test function itself
    {
      test_ranges_helper::has_size_func_can_throw<true> item;
      ASSERT_EQ(0, size(item));
      ASSERT_FALSE(noexcept(size(item)));
    }
    test_ranges_helper::has_size_func_can_throw<true> item;
    EXPECT_EQ(0, ::portable_stl::ranges::size(item));
    EXPECT_FALSE(noexcept(::portable_stl::ranges::size(item)));
  }

  // ranges::end - ranges::begin
  {
    std::int32_t value{1};
    // check test function itself
    {
      test_ranges_helper::has_begin_end_member_can_throw<false, false> item{&value};
      ASSERT_EQ(1, *item.begin());
      ASSERT_TRUE(noexcept(item.begin()));
      ASSERT_EQ(1, *item.end());
      ASSERT_TRUE(noexcept(item.end()));
    }
    test_ranges_helper::has_begin_end_member_can_throw<false, false> item{&value};
    EXPECT_EQ(0, ::portable_stl::ranges::size(item));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::size(item)));
  }
  {
    std::int32_t value{1};
    // check test function itself
    {
      test_ranges_helper::has_begin_end_member_can_throw<false, true> item{&value};
      ASSERT_EQ(1, *item.begin());
      ASSERT_TRUE(noexcept(item.begin()));
      ASSERT_EQ(1, *item.end());
      ASSERT_FALSE(noexcept(item.end()));
    }
    test_ranges_helper::has_begin_end_member_can_throw<false, true> item{&value};
    EXPECT_EQ(0, ::portable_stl::ranges::size(item));
    ASSERT_FALSE(noexcept(::portable_stl::ranges::size(item)));
  }
  {
    std::int32_t value{1};
    // check test function itself
    {
      test_ranges_helper::has_begin_end_member_can_throw<true, false> item{&value};
      ASSERT_EQ(1, *item.begin());
      ASSERT_FALSE(noexcept(item.begin()));
      ASSERT_EQ(1, *item.end());
      ASSERT_TRUE(noexcept(item.end()));
    }
    test_ranges_helper::has_begin_end_member_can_throw<true, false> item{&value};
    EXPECT_EQ(0, ::portable_stl::ranges::size(item));
    ASSERT_FALSE(noexcept(::portable_stl::ranges::size(item)));
  }
  {
    std::int32_t value{1};
    // check test function itself
    {
      test_ranges_helper::has_begin_end_member_can_throw<true, true> item{&value};
      ASSERT_EQ(1, *item.begin());
      ASSERT_FALSE(noexcept(item.begin()));
      ASSERT_EQ(1, *item.end());
      ASSERT_FALSE(noexcept(item.end()));
    }
    test_ranges_helper::has_begin_end_member_can_throw<true, true> item{&value};
    EXPECT_EQ(0, ::portable_stl::ranges::size(item));
    ASSERT_FALSE(noexcept(::portable_stl::ranges::size(item)));
  }
}

TEST(ranges, empty_helpers) {
  static_cast<void>(test_info_);
  {
    typename ::portable_stl::ranges::empty_impl_helper::has_size_impl<
      test_ranges_helper::has_size_member_can_throw<false>>::type checker{};
    EXPECT_TRUE(checker());
  }
  {
    /**
     * @brief Tested class.
     */
    using value_type = test_ranges_helper::has_empty_member_can_throw<false, false>;
    /**
     * @brief Result type.
     */
    using test_type1 = ::portable_stl::ranges::empty_impl_helper::member_empty<value_type>;
    /**
     * @brief Result type.
     */
    using test_type2 = ::portable_stl::ranges::empty_impl_helper::has_size<value_type>;

    EXPECT_TRUE((test_type1{}()));
    EXPECT_FALSE((test_type2{}()));
  }
}

TEST(ranges, empty) {
  static_cast<void>(test_info_);
  // c-style array
  {
    std::int32_t item[1]{1};
    EXPECT_FALSE(::portable_stl::ranges::empty(item));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::size(item)));
  }
  {
    std::int32_t item[2][1]{{1}, {1}};
    EXPECT_FALSE(::portable_stl::ranges::empty(item));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::size(item)));
  }

  // member .empty()
  {
    // check test function itself
    {
      ASSERT_FALSE((test_ranges_helper::has_empty_member_can_throw<false, false>::empty()));
      ASSERT_TRUE(noexcept(test_ranges_helper::has_empty_member_can_throw<false, false>::empty()));
    }
    test_ranges_helper::has_empty_member_can_throw<false, false> item;
    EXPECT_FALSE(::portable_stl::ranges::empty(item));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::empty(item)));
  }
  {
    // check test function itself
    {
      ASSERT_TRUE((test_ranges_helper::has_empty_member_can_throw<true, true>::empty()));
      ASSERT_FALSE(noexcept(test_ranges_helper::has_empty_member_can_throw<true, true>::empty()));
    }
    test_ranges_helper::has_empty_member_can_throw<true, true> item;
    EXPECT_TRUE(::portable_stl::ranges::empty(item));
    EXPECT_FALSE(noexcept(::portable_stl::ranges::empty(item)));
  }

  // 0 == ranges::size()
  {
    // check test function itself
    {
      test_ranges_helper::has_size_member_can_throw<false> item;
      ASSERT_EQ(1, ::portable_stl::ranges::size(item));
      ASSERT_TRUE(noexcept(::portable_stl::ranges::size(item)));
    }
    test_ranges_helper::has_size_member_can_throw<false> item;
    EXPECT_FALSE(::portable_stl::ranges::empty(item));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::empty(item)));
  }
  {
    // check test function itself
    {
      test_ranges_helper::has_size_func_can_throw<true> item;
      ASSERT_EQ(0, ::portable_stl::ranges::size(item));
      ASSERT_FALSE(noexcept(::portable_stl::ranges::size(item)));
    }
    test_ranges_helper::has_size_func_can_throw<true> item;
    EXPECT_TRUE(::portable_stl::ranges::empty(item));
    EXPECT_FALSE(noexcept(::portable_stl::ranges::empty(item)));
  }

  // ranges::begin() == ranges::end()
  // not so easy to make this test =(
}

TEST(ranges, data_helpers) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Tested class.
     */
    using value_type = std::int32_t(&)[1];
    /**
     * @brief Result type.
     */
    using test_type1 = ::portable_stl::ranges::data_impl_helper::member_data<value_type>;
    /**
     * @brief Result type.
     */
    using test_type2 = ::portable_stl::contiguous_iterator<decltype(::portable_stl::ranges::begin(
      ::portable_stl::declval<value_type>()))>;
    /**
     * @brief Result type.
     */
    using test_type3 = ::portable_stl::ranges::data_impl_helper::ranges_begin_invocable<value_type>;

    EXPECT_FALSE((test_type1{}()));
    EXPECT_TRUE((test_type2{}()));
    EXPECT_TRUE((test_type3{}()));
  }
}

TEST(ranges, data) {
  static_cast<void>(test_info_);

  // member .data()
  {
    // check test function itself
    {
      test_ranges_helper::has_data_member_can_throw<false> item;
      ASSERT_EQ(1, *item.data());
      ASSERT_TRUE(noexcept(item.data()));
    }
    test_ranges_helper::has_data_member_can_throw<false> item;
    EXPECT_EQ(1, *::portable_stl::ranges::data(item));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::data(item)));
  }
  {
    // check test function itself
    {
      test_ranges_helper::has_data_member_can_throw<true> item;
      ASSERT_EQ(1, *item.data());
      ASSERT_FALSE(noexcept(item.data()));
    }
    test_ranges_helper::has_data_member_can_throw<true> item;
    EXPECT_EQ(1, *::portable_stl::ranges::data(item));
    EXPECT_FALSE(noexcept(::portable_stl::ranges::data(item)));
  }

  // ranges::begin + adress_to
  {
    // check test function itself
    {
      ::portable_stl::array<std::int32_t, 1> item{{1}};
      ASSERT_EQ(1, *::portable_stl::ranges::begin(item));
      ASSERT_TRUE(*::portable_stl::ranges::begin(item));
    }
    ::portable_stl::array<std::int32_t, 1> item{{1}};
    EXPECT_EQ(1, *::portable_stl::ranges::data(item));
    EXPECT_TRUE(noexcept(::portable_stl::ranges::data(item)));
  }
}

TEST(ranges, cbegin_c_array) {
  static_cast<void>(test_info_);

  std::int32_t c_array[1]{0};
  EXPECT_TRUE((std::is_same<decltype(::portable_stl::ranges::cbegin(c_array)), std::int32_t const *>{}));
  EXPECT_TRUE(noexcept(::portable_stl::ranges::cbegin(c_array)));
  EXPECT_EQ(::portable_stl::ranges::cbegin(c_array), &c_array[0]);

  constexpr std::int64_t c_array_constexpr[]{1, 0};
  EXPECT_EQ(::portable_stl::ranges::cbegin(c_array_constexpr), &c_array_constexpr[0]);
}

TEST(ranges, cend_c_array) {
  static_cast<void>(test_info_);

  std::int32_t c_array[2]{0, 1};

  EXPECT_TRUE((std::is_same<decltype(::portable_stl::ranges::cend(c_array)), std::int32_t const *>{}));
  EXPECT_TRUE(noexcept(::portable_stl::ranges::cend(c_array)));
  EXPECT_EQ(::portable_stl::ranges::cend(c_array), &c_array[1] + 1);
}

TEST(ranges, crbegin_c_array) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief test c-array type
     */
    using test_type = std::int32_t[1];
    EXPECT_TRUE((::portable_stl::ranges::input_range<test_type>{}()));
    EXPECT_TRUE((::portable_stl::ranges::constant_range<test_type const>{}()));
    EXPECT_FALSE((::portable_stl::ranges::constant_range<test_type>{}()));

    /**
     * @brief const type of rbegin for given range type
     */
    using rbegin_on_const = decltype(::portable_stl::ranges::rbegin(
      ::portable_stl::ranges::ranges_helper::possibly_const_range(::portable_stl::declval<test_type &>())));
    EXPECT_TRUE((::portable_stl::input_or_output_iterator<rbegin_on_const>{}()));
    EXPECT_TRUE((::portable_stl::indirectly_readable<rbegin_on_const>{}()));
    EXPECT_TRUE((::portable_stl::input_iterator<rbegin_on_const>{}()));
  }
  {
    std::int32_t c_array[]{1, 0};

    EXPECT_TRUE(noexcept(::portable_stl::ranges::crbegin(c_array)));
    EXPECT_EQ((++::portable_stl::ranges::crbegin(c_array)).base(), &c_array[1]);

    constexpr std::int64_t c_array_constexpr[]{1, 0};
    EXPECT_EQ((++::portable_stl::ranges::crbegin(c_array_constexpr)).base(), &c_array_constexpr[1]);
  }
}

TEST(ranges, crend_c_array) {
  static_cast<void>(test_info_);
  {
    std::int32_t c_array[]{1, 0};

    EXPECT_TRUE(noexcept(::portable_stl::ranges::crend(c_array)));
    EXPECT_EQ(::portable_stl::ranges::crend(c_array).base(), &c_array[0]);

    constexpr std::int64_t c_array_constexpr[]{1, 0};
    EXPECT_EQ(::portable_stl::ranges::crend(c_array_constexpr).base(), &c_array_constexpr[0]);
  }
}
