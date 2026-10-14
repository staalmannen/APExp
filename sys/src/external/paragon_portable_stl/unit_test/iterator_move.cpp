// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="iterator_move.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "common/move_only.h"
#include "iterator_helper.h"
#include "metaprogramming_type_relations_helper.h"
#include "portable_stl/array/array.h"
#include "portable_stl/iterator/move_iterator.h"
#include "portable_stl/iterator/wrap_iter.h"
#include "portable_stl/ranges/begin.h"

namespace test_m_iterator_helper {
constexpr std::int32_t elemets_size{4};
constexpr std::int32_t el_0{0};
constexpr std::int32_t el_1{1};
constexpr std::int32_t el_2{2};
constexpr std::int32_t el_3{3};
} // namespace test_m_iterator_helper

TEST(move_iterator, construction) {
  static_cast<void>(test_info_);
  ::portable_stl::array<std::int32_t, test_m_iterator_helper::el_3> test_array{
    {test_m_iterator_helper::el_0, test_m_iterator_helper::el_1, test_m_iterator_helper::el_2}
  };
  /**
   * @brief Test iterator type.
   */
  using arr_iter_type = decltype(test_array)::iterator;

  EXPECT_TRUE((::portable_stl::is_constructible<arr_iter_type>{}()));

  // ctor from iterator
  auto iter = ::portable_stl::move_iterator<arr_iter_type>(test_array.begin());
  ++iter;

  // default constructor (arr_iter_type is_constructible)
  ::portable_stl::move_iterator<arr_iter_type> iter2;

  // copy constructor same underlying type
  auto const iter3 = iter;

  // copy assignment operator
  iter2 = iter3;
  static_cast<void>(iter2);
}

TEST(move_iterator, construction_from_another) {
  static_cast<void>(test_info_);

  /**
   * @brief Test base type.
   */
  using Base    = metaprogramming_type_relations_helper::Base1;
  /**
   * @brief Test derived type.
   */
  using Derived = metaprogramming_type_relations_helper::Derived1;

  ::portable_stl::array<Derived, test_m_iterator_helper::elemets_size> test_array{};

  // /**
  //  * @brief Test iterator1 type.
  //  */
  // using arr_iter_type1 = typename ::portable_stl::array<Derived, test_m_iterator_helper::elemets_size>::iterator;
  /**
   * @brief Test iterator2 type.
   */
  using arr_iter_type2 = typename ::portable_stl::array<Base, test_m_iterator_helper::elemets_size>::iterator;

  auto const iter_derived = ::portable_stl::make_move_iterator(test_array.begin());

  // copy constructor from another underlying type
  ::portable_stl::move_iterator<arr_iter_type2> const iter_base{iter_derived};
  static_cast<void>(iter_base);

  // copy assignment operator from another underlying type
  ::portable_stl::move_iterator<arr_iter_type2> iter_base2;
  iter_base2 = iter_derived;
}

TEST(move_iterator, exception_construction) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test reverse iterator type with throwing exception on construct from ClassCanThrow<>.
     */
    using rev_iter_type = ::portable_stl::move_iterator<test_iterator_exception_helper::ClassCanThrow<true>>;

    try {
      test_iterator_exception_helper::ClassCanThrow<true> some_iter{};
      rev_iter_type                                       try_construct_from_iterator{some_iter};
      static_cast<void>(try_construct_from_iterator);
      EXPECT_FALSE(true);
    } catch (std::runtime_error &) {
    }

    EXPECT_FALSE(noexcept(rev_iter_type(test_iterator_exception_helper::ClassCanThrow<true>())));
  }
  {
    /**
     * @brief Test reverse iterator type with not throwing exception on construct from ClassCanThrow<>.
     */
    using rev_iter_type = ::portable_stl::move_iterator<test_iterator_exception_helper::ClassCanThrow<false>>;

    EXPECT_TRUE(noexcept(rev_iter_type(test_iterator_exception_helper::ClassCanThrow<false>())));
  }
}

TEST(move_iterator, exception_iter_move) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test reverse iterator type with throwing exception on construct from ClassCanThrow<>.
     */
    using rev_iter_type = ::portable_stl::move_iterator<test_iterator_exception_helper::ClassCanThrow<true>>;
    rev_iter_type move_iter{};
    EXPECT_FALSE(noexcept(::portable_stl::ranges::iter_move(move_iter)));
  }
  {
    /**
     * @brief Test reverse iterator type with no throwing exception on construct from ClassCanThrow<>.
     */
    using rev_iter_type = ::portable_stl::move_iterator<test_iterator_exception_helper::ClassCanThrow<false>>;
    rev_iter_type move_iter{};
    auto          rev_iter_moved = ::portable_stl::ranges::iter_move(move_iter);
    static_cast<void>(rev_iter_moved);

    EXPECT_TRUE(noexcept(::portable_stl::ranges::iter_move(move_iter)));
  }
}

TEST(move_iterator, exception_iter_swap) {
  static_cast<void>(test_info_);

  /**
   * @brief Base iter type.
   */
  using base_iter_type = test_iterator_exception_helper::ClassCanThrow<false>;
  /**
   * @brief Test reverse iterator type with POTENTIAL throwing exception on iter_swap(ClassCanThrow<false>,
   * ClassCanThrow<false>).
   */
  // using rev_iter_type  = ::portable_stl::reverse_iterator<base_iter_type>;

  {
    ASSERT_TRUE((::portable_stl::indirectly_readable<base_iter_type>{}()));
    ASSERT_TRUE((::portable_stl::indirectly_swappable<base_iter_type, base_iter_type>{}()));
    ASSERT_TRUE((::portable_stl::ranges::iter_swap_impl::is_adl_iter_swap<base_iter_type, base_iter_type>{}()));
    // ASSERT_TRUE((::portable_stl::ranges::iter_swap_impl::is_adl_iter_swap<rev_iter_type, rev_iter_type>{}()));
  }
  // {
  //   rev_iter_type move_iter{};
  //   rev_iter_type rev_iter2{};
  //   // no exception on iter_swap: iter copy - no throwing, iter_swap(ClassCanThrow,ClassCanThrow) - no throwing
  //   ::portable_stl::ranges::iter_swap2(move_iter, rev_iter2);

  //   // ClassCanThrow copy ctor mark as noexcept, BUT iter_swap(ClassCanThrow<false>,ClassCanThrow<false>) - as
  //   // noexcept(false)
  //   EXPECT_FALSE(noexcept(::portable_stl::ranges::iter_swap2(move_iter, rev_iter2)));
  //   EXPECT_TRUE(noexcept(base_iter_type(base_iter_type())));
  //   EXPECT_FALSE(noexcept(iter_swap(base_iter_type(), base_iter_type())));
  // }
}

TEST(move_iterator, modifier) {
  static_cast<void>(test_info_);
  ::portable_stl::array<std::int32_t, test_m_iterator_helper::elemets_size> test_array{
    {test_m_iterator_helper::el_0,
     test_m_iterator_helper::el_1,
     test_m_iterator_helper::el_2,
     test_m_iterator_helper::el_3}
  };
  /**
   * @brief Test iterator type.
   */
  using arr_iter_type = typename decltype(test_array)::iterator;

  EXPECT_TRUE((::portable_stl::forward_iterator<arr_iter_type>{}()));

  {
    auto iter = ::portable_stl::make_move_iterator(test_array.begin());
    ++iter;
    EXPECT_EQ(test_m_iterator_helper::el_1, *iter.base());
  }
  {
    auto iter = ::portable_stl::make_move_iterator(test_array.end());
    --iter;
    EXPECT_EQ(test_m_iterator_helper::el_3, *iter.base());
  }
  {
    auto iter = ::portable_stl::make_move_iterator(test_array.begin());
    iter++;
    EXPECT_EQ(test_m_iterator_helper::el_1, *iter);
  }

  // non forward_iterator<> post-increment
  {
    std::int32_t arr[test_m_iterator_helper::el_2]{0, 1};
    /**
     * @brief Test iter type.
     */
    using iter_type = test_iterator_helper::tst_input_iterator<std::int32_t *>;
    auto iter       = ::portable_stl::move_iterator<iter_type>{&arr[0]};
    iter++;
    static_cast<void>(iter);
  }
  {
    auto iter = ::portable_stl::make_move_iterator(test_array.end());
    iter--;
    EXPECT_EQ(test_m_iterator_helper::el_3, *iter);
  }
  {
    auto const iter  = ::portable_stl::make_move_iterator(test_array.begin());
    auto       iter2 = iter + test_m_iterator_helper::el_2;
    EXPECT_EQ(test_m_iterator_helper::el_2, *iter2);
  }
  {
    auto iter = ::portable_stl::make_move_iterator(test_array.begin());
    iter += test_m_iterator_helper::el_2;
    EXPECT_EQ(test_m_iterator_helper::el_2, *iter);
  }
  {
    auto const iter  = ::portable_stl::make_move_iterator(test_array.end());
    auto       iter2 = iter - test_m_iterator_helper::el_2;
    EXPECT_EQ(test_m_iterator_helper::el_2, *iter2);
  }
  {
    auto iter = ::portable_stl::make_move_iterator(test_array.end());
    iter -= test_m_iterator_helper::el_2;
    EXPECT_EQ(test_m_iterator_helper::el_2, *iter);
  }
}

TEST(move_iterator, comparison) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::array<std::int32_t, test_m_iterator_helper::elemets_size> test_array{
      {test_m_iterator_helper::el_0,
       test_m_iterator_helper::el_1,
       test_m_iterator_helper::el_2,
       test_m_iterator_helper::el_3}
    };

    auto iter1 = ::portable_stl::make_move_iterator(test_array.begin());
    auto iter2 = ::portable_stl::make_move_iterator(test_array.end());
    EXPECT_TRUE(iter1 < iter2);
    EXPECT_TRUE(iter1 <= iter2);
    EXPECT_TRUE(iter1 <= iter1);
    EXPECT_TRUE(iter1 != iter2);
    EXPECT_TRUE(iter2 > iter1);
    EXPECT_TRUE(iter2 >= iter1);
    EXPECT_TRUE(iter2 >= iter2);
    EXPECT_TRUE(iter1 == iter1);
    EXPECT_TRUE(iter1 != iter2);
  }

  // move_iterator<move_only*>
  {
    /**
     * @brief Alias.
     */
    using move_only = test_common_helper::MoveOnly;

    move_only m1(0);
    move_only m2(1);

    ::portable_stl::move_iterator<move_only *> iter1(&m1);

    ::portable_stl::move_iterator<move_only *> iter2(&m2);
    ASSERT_FALSE(iter1 == iter2);
    ASSERT_TRUE(iter1 != iter2);

    ::portable_stl::move_iterator<move_only *> iter3(&m1);
    ASSERT_TRUE(iter1 == iter3);
    ASSERT_FALSE(iter1 != iter3);
  }

  // move_iterator<wrap_iter<move_only*>>
  {
    /**
     * @brief Alias.
     */
    using move_only = test_common_helper::MoveOnly;

    move_only raw1(0);
    move_only raw2(1);

    /**
     * @brief Alias.
     */
    using wrap_iter_type = ::portable_stl::wrap_iter<move_only *>;

    wrap_iter_type wrap1(&raw1);
    wrap_iter_type wrap2(&raw2);

    ::portable_stl::move_iterator<wrap_iter_type> iter1(wrap1);

    ::portable_stl::move_iterator<wrap_iter_type> iter2(wrap2);
    ASSERT_FALSE(iter1 == iter2);
    ASSERT_TRUE(iter1 != iter2);

    ::portable_stl::move_iterator<wrap_iter_type> iter3(wrap1);
    ASSERT_TRUE(iter1 == iter3);
    ASSERT_FALSE(iter1 != iter3);
  }
}

TEST(move_iterator, accessor) {
  static_cast<void>(test_info_);
  ::portable_stl::array<std::int32_t, test_m_iterator_helper::elemets_size> test_array{
    {test_m_iterator_helper::el_0,
     test_m_iterator_helper::el_1,
     test_m_iterator_helper::el_2,
     test_m_iterator_helper::el_3}
  };

  // operator* & operator[]
  {
    auto iter = ::portable_stl::make_move_iterator(test_array.begin());

    EXPECT_TRUE(test_iterator_helper::Eater::test_fn(*iter));
    EXPECT_TRUE(test_iterator_helper::Eater::test_fn(iter[test_m_iterator_helper::el_2]));
  }

  // base() &&
  {
    auto iter = ::portable_stl::make_move_iterator(test_array.end());
    --iter;
    EXPECT_EQ(test_m_iterator_helper::el_3, *(iter--).base());
  }
}

TEST(move_iterator, other) {
  static_cast<void>(test_info_);
  ::portable_stl::array<std::int32_t, test_m_iterator_helper::elemets_size> test_array{
    {test_m_iterator_helper::el_0,
     test_m_iterator_helper::el_1,
     test_m_iterator_helper::el_2,
     test_m_iterator_helper::el_3}
  };

  {
    auto const iter  = ::portable_stl::make_move_iterator(test_array.begin());
    auto       iter2 = test_m_iterator_helper::el_2 + iter;
    EXPECT_EQ(test_m_iterator_helper::el_2, *iter2);
  }
  {
    auto iter1 = ::portable_stl::make_move_iterator(test_array.begin());
    auto iter2 = ::portable_stl::make_move_iterator(test_array.end());
    EXPECT_EQ(test_m_iterator_helper::elemets_size, iter2 - iter1);
  }
}
