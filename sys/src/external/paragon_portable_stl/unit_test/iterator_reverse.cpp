// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="iterator_reverse.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "iterator_helper.h"
#include "metaprogramming_type_relations_helper.h"
#include "portable_stl/array/array.h"
#include "portable_stl/iterator/reverse_iterator.h"
#include "portable_stl/metaprogramming/type_properties/is_nothrow_constructible.h"
#include "portable_stl/metaprogramming/type_properties/is_nothrow_default_constructible.h"

namespace test_r_iterator_helper {
constexpr std::int32_t elemets_size{4};
constexpr std::int32_t el_0{0};
constexpr std::int32_t el_1{1};
constexpr std::int32_t el_2{2};
constexpr std::int32_t el_3{3};

/**
 * @brief Test class.
 */
class TestClass final {
public:
  /**
   * @brief Test member.
   */
  std::int32_t value_{0};
};
} // namespace test_r_iterator_helper

TEST(reverse_iterator, construction) {
  static_cast<void>(test_info_);
  /**
   * @brief Test iterator type.
   */
  using arr_iter_type = ::portable_stl::array<std::int32_t, test_r_iterator_helper::el_3>::iterator;

  ::portable_stl::array<std::int32_t, test_r_iterator_helper::el_3> test_array{
    {test_r_iterator_helper::el_0, test_r_iterator_helper::el_1, test_r_iterator_helper::el_2}
  };

  // ctor from iterator
  auto iter = ::portable_stl::reverse_iterator<arr_iter_type>(test_array.end());
  ++iter;

  // default constructor (arr_iter_type is_constructible)
  ::portable_stl::reverse_iterator<arr_iter_type> iter2;

  // copy constructor same underlying type
  auto const iter3 = iter;

  // copy assignment operator
  iter2 = iter3;
  static_cast<void>(iter2);

  ++iter;
}

TEST(reverse_iterator, exception_construction) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test reverse iterator type with throwing exception on construct from ClassCanThrow<>.
     */
    using rev_iter_type = ::portable_stl::reverse_iterator<test_iterator_exception_helper::ClassCanThrow<true>>;

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
    using rev_iter_type = ::portable_stl::reverse_iterator<test_iterator_exception_helper::ClassCanThrow<false>>;

    EXPECT_TRUE(noexcept(rev_iter_type(test_iterator_exception_helper::ClassCanThrow<false>())));
  }
}

TEST(reverse_iterator, exception_iter_move) {
  static_cast<void>(test_info_);
  // {
  //   /**
  //    * @brief Test reverse iterator type with throwing exception on construct from ClassCanThrow<>.
  //    */
  //   using rev_iter_type = ::portable_stl::reverse_iterator<test_iterator_exception_helper::ClassCanThrow<true>>;
  //   rev_iter_type rev_iter1{};
  //   try {
  //     auto rev_iter_moved = ::portable_stl::ranges::iter_move(rev_iter1);
  //     EXPECT_FALSE(true);
  //   } catch (std::runtime_error &) {
  //   }

  //   EXPECT_FALSE(noexcept(::portable_stl::ranges::iter_move(rev_iter1)));
  // }
  // {
  //   /**
  //    * @brief Test reverse iterator type with no throwing exception on construct from ClassCanThrow<>.
  //    */
  //   using rev_iter_type = ::portable_stl::reverse_iterator<test_iterator_exception_helper::ClassCanThrow<false>>;
  //   rev_iter_type rev_iter1{};
  //   auto          rev_iter_moved = ::portable_stl::ranges::iter_move(rev_iter1);

  //   EXPECT_TRUE(noexcept(::portable_stl::ranges::iter_move(rev_iter1)));
  // }
}

TEST(reverse_iterator, exception_iter_swap) {
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
  //   rev_iter_type rev_iter1{};
  //   rev_iter_type rev_iter2{};
  //   // no exception on iter_swap: iter copy - no throwing, iter_swap(ClassCanThrow,ClassCanThrow) - no throwing
  //   ::portable_stl::ranges::iter_swap2(rev_iter1, rev_iter2);

  //   // ClassCanThrow copy ctor mark as noexcept, BUT iter_swap(ClassCanThrow<false>,ClassCanThrow<false>) - as
  //   // noexcept(false)
  //   EXPECT_FALSE(noexcept(::portable_stl::ranges::iter_swap2(rev_iter1, rev_iter2)));
  //   EXPECT_TRUE(noexcept(base_iter_type(base_iter_type())));
  //   EXPECT_FALSE(noexcept(iter_swap(base_iter_type(), base_iter_type())));
  // }
}

// template<class It, class U> void test(U u) {
//   ::portable_stl::reverse_iterator<U> const r2(u);
//   ::portable_stl::reverse_iterator<It>      r1 = r2;
//   assert(base(r1.base()).base() == base(u));
// }

TEST(reverse_iterator, construction_from_another) {
  static_cast<void>(test_info_);

  /**
   * @brief Base class
   *
   */
  using Base    = metaprogramming_type_relations_helper::Base1;
  /**
   * @brief Derived class
   *
   */
  using Derived = metaprogramming_type_relations_helper::Derived1;

  Derived derived_object{};

  ::portable_stl::reverse_iterator<Derived *> const rev_iter_1{&derived_object};
  ::portable_stl::reverse_iterator<Base *>          rev_iter_2{rev_iter_1};

  // /**
  //  * @brief Test base type.
  //  */
  // using Base    = metaprogramming_type_relations_helper::Base1;
  // /**
  //  * @brief Test derived type.
  //  */
  // using Derived = metaprogramming_type_relations_helper::Derived1;

  // ::portable_stl::array<Base, test_r_iterator_helper::elemets_size> test_array{};

  // /**
  //  * @brief Test iterator2 type.
  //  */
  // using arr_iter_type2 = typename ::portable_stl::array<Derived, test_r_iterator_helper::elemets_size>::iterator;

  // auto const iter_base = ::portable_stl::make_reverse_iterator(test_array.end());
  // // ++iter_derived;

  // // copy constructor from another underlying type
  // ::portable_stl::reverse_iterator<arr_iter_type2> const iter_derived{iter_base};
  // static_cast<void>(iter_derived);

  // // copy assignment operator from another underlying type
  // ::portable_stl::reverse_iterator<arr_iter_type2> iter_derived2;
  // iter_derived2 = iter_base;
}

TEST(reverse_iterator, accessor) {
  static_cast<void>(test_info_);
  // Array container
  {
    ::portable_stl::array<test_r_iterator_helper::TestClass, test_r_iterator_helper::el_2> test_array;
    test_array[0U].value_ = 0;
    test_array[1U].value_ = 1;

    /**
     * @brief Test iterator type.
     */
    using arr_iter_type = typename decltype(test_array)::iterator;

    auto iter = ::portable_stl::reverse_iterator<arr_iter_type>(test_array.end());
    EXPECT_EQ(1, (*iter).value_);
    EXPECT_EQ(1, iter->value_);

    EXPECT_EQ(test_array.end(), iter.base());
  }

  // Array c-style
  {
    std::int32_t test_array[test_r_iterator_helper::elemets_size]{
      0, 1, test_r_iterator_helper::el_2, test_r_iterator_helper::el_3};

    /**
     * @brief Test iterator type.
     */
    using arr_iter_type = std::int32_t *;

    auto iter = ::portable_stl::reverse_iterator<arr_iter_type>(&test_array[test_r_iterator_helper::elemets_size]);
    EXPECT_EQ(test_r_iterator_helper::el_3, *iter);

    EXPECT_EQ(&test_array[test_r_iterator_helper::elemets_size], iter.base());
  }
}

/**
 * @brief For a reverse iterator r constructed from an iterator i, the relationship &*r == &*(i - 1)
 */
TEST(reverse_iterator, modifier) {
  static_cast<void>(test_info_);
  ::portable_stl::array<std::int32_t, test_r_iterator_helper::elemets_size> test_array{
    {test_r_iterator_helper::el_0,
     test_r_iterator_helper::el_1,
     test_r_iterator_helper::el_2,
     test_r_iterator_helper::el_3}
  };
  /**
   * @brief Test iterator type.
   */
  using arr_iter_type = typename decltype(test_array)::iterator;

  {
    auto const iter_base = ::portable_stl::reverse_iterator<arr_iter_type>(test_array.end());
    {
      auto iter = iter_base;
      EXPECT_EQ(test_r_iterator_helper::el_2, *(++iter));
    }
    {
      auto iter = iter_base;
      EXPECT_EQ(test_r_iterator_helper::el_3, *(iter++));
      EXPECT_EQ(test_r_iterator_helper::el_2, *(iter));
    }
  }
  {
    auto const iter_base = ::portable_stl::reverse_iterator<arr_iter_type>(std::next(test_array.begin()));
    {
      auto iter = iter_base;
      EXPECT_EQ(test_r_iterator_helper::el_1, *(--iter));
    }
    {
      auto iter = iter_base;
      EXPECT_EQ(test_r_iterator_helper::el_0, *(iter--));
      EXPECT_EQ(test_r_iterator_helper::el_1, *(iter));
    }
  }
  {
    auto const iter_base = ::portable_stl::reverse_iterator<arr_iter_type>(test_array.end());
    {
      auto iter = iter_base;
      EXPECT_EQ(test_r_iterator_helper::el_0, *(iter + test_r_iterator_helper::el_3));

      iter
        += static_cast<::portable_stl::iterator_traits<arr_iter_type>::difference_type>(test_r_iterator_helper::el_3);
      EXPECT_EQ(test_r_iterator_helper::el_0, *(iter));
    }
  }
  {
    auto const iter_base = ::portable_stl::reverse_iterator<arr_iter_type>(test_array.end());
    EXPECT_EQ(test_r_iterator_helper::el_0, *(test_r_iterator_helper::el_3 + iter_base));
  }
  {
    auto const iter_base = ::portable_stl::reverse_iterator<arr_iter_type>(std::next(test_array.begin()));
    {
      auto iter = iter_base;
      EXPECT_EQ(test_r_iterator_helper::el_3, *(iter - test_r_iterator_helper::el_3));

      iter
        -= static_cast<::portable_stl::iterator_traits<arr_iter_type>::difference_type>(test_r_iterator_helper::el_3);
      EXPECT_EQ(test_r_iterator_helper::el_3, *(iter));
    }
  }
  {
    auto iter = ::portable_stl::reverse_iterator<arr_iter_type>(test_array.end());
    EXPECT_EQ(test_r_iterator_helper::el_3, iter[0]);
    EXPECT_EQ(test_r_iterator_helper::el_2, iter[1]);
    EXPECT_EQ(test_r_iterator_helper::el_1, iter[test_r_iterator_helper::el_2]);
    EXPECT_EQ(test_r_iterator_helper::el_0, iter[test_r_iterator_helper::el_3]);
  }
  {
    auto iter = ::portable_stl::reverse_iterator<arr_iter_type>(test_array.end());
    iter[1]   = 0;
    EXPECT_EQ(0, iter[1]);
  }
}

TEST(reverse_iterator, comparison) {
  static_cast<void>(test_info_);

  ::portable_stl::array<std::int32_t, test_r_iterator_helper::elemets_size> test_array{
    {test_r_iterator_helper::el_0,
     test_r_iterator_helper::el_1,
     test_r_iterator_helper::el_2,
     test_r_iterator_helper::el_3}
  };
  /**
   * @brief Test iterator type.
   */
  using arr_iter_type = typename decltype(test_array)::iterator;

  {
    auto iter_rbegin = ::portable_stl::reverse_iterator<arr_iter_type>(test_array.end());
    auto iter_rend   = ::portable_stl::reverse_iterator<arr_iter_type>(std::next(test_array.begin()));
    EXPECT_TRUE(iter_rend == (iter_rbegin + test_r_iterator_helper::el_3));
  }

  {
    auto iter_rbegin = ::portable_stl::reverse_iterator<arr_iter_type>(test_array.end());
    auto iter_rend   = ::portable_stl::reverse_iterator<arr_iter_type>(std::next(test_array.begin()));
    EXPECT_TRUE(iter_rbegin != iter_rend);
  }

  {
    auto iter_rbegin = ::portable_stl::reverse_iterator<arr_iter_type>(test_array.end());
    auto iter_rend   = ::portable_stl::reverse_iterator<arr_iter_type>(std::next(test_array.begin()));
    EXPECT_TRUE(iter_rbegin > iter_rend);
    EXPECT_TRUE(iter_rbegin >= iter_rend);
    EXPECT_TRUE(iter_rend < iter_rbegin);
    EXPECT_TRUE(iter_rend <= iter_rbegin);
  }

  {
    ::portable_stl::array<std::int32_t, test_r_iterator_helper::el_3> test_array2{
      {test_r_iterator_helper::el_0, test_r_iterator_helper::el_1, test_r_iterator_helper::el_2}
    };
    /**
     * @brief Test iterator type.
     */
    using arr_iter_type2 = typename decltype(test_array2)::iterator;

    auto iter_rend1 = ::portable_stl::reverse_iterator<arr_iter_type>(std::next(test_array.begin()));
    auto iter_rend2 = ::portable_stl::reverse_iterator<arr_iter_type2>(std::next(test_array2.begin()));

    EXPECT_FALSE(iter_rend1 == iter_rend2);
  }
}

TEST(reverse_iterator, make_reverse_iterator) {
  static_cast<void>(test_info_);
  ::portable_stl::array<std::int32_t, test_r_iterator_helper::el_3> test_array{
    {test_r_iterator_helper::el_0, test_r_iterator_helper::el_1, test_r_iterator_helper::el_2}
  };
  /**
   * @brief Test iterator type.
   */
  using arr_iter_type = typename decltype(test_array)::iterator;

  auto iter = ::portable_stl::make_reverse_iterator<arr_iter_type>(test_array.end());
  EXPECT_EQ(test_r_iterator_helper::el_2, *iter);
}

TEST(reverse_iterator, distance) {
  static_cast<void>(test_info_);
  ::portable_stl::array<std::int32_t, test_r_iterator_helper::el_3> test_array{
    {test_r_iterator_helper::el_0, test_r_iterator_helper::el_1, test_r_iterator_helper::el_2}
  };
  /**
   * @brief Test iterator type.
   */
  using arr_iter_type = typename decltype(test_array)::iterator;

  auto iter1 = ::portable_stl::make_reverse_iterator<arr_iter_type>(test_array.end());
  auto iter2 = ::portable_stl::make_reverse_iterator<arr_iter_type>(test_array.begin());
  EXPECT_EQ(test_r_iterator_helper::el_3, iter2 - iter1);
}
