// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="iterator.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <iterator>
#include <vector>

#include "iterator_helper.h"
#include "portable_stl/array/array.h"
#include "portable_stl/common/ptrdiff_t.h"
#include "portable_stl/common/size_t.h"
#include "portable_stl/iterator/advance.h"
#include "portable_stl/iterator/concepts/input_or_output_iterator.h"
#include "portable_stl/iterator/distance.h"
#include "portable_stl/iterator/incrementable_traits.h"
#include "portable_stl/iterator/indirectly_readable_traits.h"
#include "portable_stl/iterator/iter_reference_t.h"
#include "portable_stl/iterator/iter_rvalue_reference_t.h"
#include "portable_stl/iterator/iter_value_t.h"
#include "portable_stl/iterator/iterator_traits.h"
#include "portable_stl/iterator/next.h"
#include "portable_stl/iterator/prev.h"
#include "portable_stl/iterator/range_access.h"
#include "portable_stl/language_support/initializer_list.h"
#include "test_debug_helper.h"

namespace test_iterator_helper {
constexpr std::int32_t elemets_size{5};
constexpr std::int32_t el_0{0};
constexpr std::int32_t el_1{1};
constexpr std::int32_t el_2{2};
constexpr std::int32_t el_3{3};
constexpr std::int32_t el_4{4};
constexpr std::int32_t el_m3{-3};
} // namespace test_iterator_helper

TEST(iterator, is_type_has_member_value_type_t) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test iterator type.
     */
    using test_iterator_type = std::uint32_t *;
    EXPECT_FALSE((::portable_stl::iterator_helper::is_type_has_member_value_type_t<test_iterator_type>{}()));
  }
  {
    /**
     * @brief Test iterator type.
     */
    using test_iterator_type = test_iterator_helper::tst_bidirectional_iterator<std::int32_t *>;
    EXPECT_TRUE((::portable_stl::iterator_helper::is_type_has_member_value_type_t<test_iterator_type>{}()));
  }
}

TEST(iterator, is_type_has_element_type_t) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test iterator type.
     */
    using test_iterator_type = std::uint32_t *;
    EXPECT_FALSE((::portable_stl::iterator_helper::is_type_has_element_type_t<test_iterator_type>{}()));
  }
  {
    /**
     * @brief Test iterator type.
     */
    using test_iterator_type = test_iterator_helper::tst_bidirectional_iterator<std::int32_t *>;
    EXPECT_FALSE((::portable_stl::iterator_helper::is_type_has_element_type_t<test_iterator_type>{}()));
  }
}

TEST(iterator, is_type_has_difference_type_t) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test iterator type.
     */
    using test_iterator_type = std::uint32_t *;
    EXPECT_FALSE((::portable_stl::iterator_helper::is_type_has_difference_type_t<test_iterator_type>{}()));
  }
  {
    /**
     * @brief Test iterator type.
     */
    using test_iterator_type = test_iterator_helper::tst_bidirectional_iterator<std::int32_t *>;
    EXPECT_TRUE((::portable_stl::iterator_helper::is_type_has_difference_type_t<test_iterator_type>{}()));
  }
}

TEST(iterator, iter_value_t) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test iterator type.
     */
    using test_iterator_type = std::int32_t *;
    /**
     * @brief Test value type for given iterator type.
     */
    using test_type          = ::portable_stl::iter_value_t<test_iterator_type>;
    EXPECT_TRUE((std::is_same<std::int32_t, test_type>{}));
  }
  {
    /**
     * @brief Test iterator type.
     */
    using test_iterator_type = std::int32_t *const;
    /**
     * @brief Test value type for given iterator type.
     */
    using test_type          = ::portable_stl::iter_value_t<test_iterator_type>;
    EXPECT_TRUE((std::is_same<std::int32_t, test_type>{}));
  }
  {
    /**
     * @brief Test iterator type.
     */
    using test_iterator_type = test_iterator_helper::tst_bidirectional_iterator<std::int32_t *>;
    /**
     * @brief Test value type for given iterator type.
     */
    using test_type          = ::portable_stl::iter_value_t<test_iterator_type>;
    EXPECT_TRUE((std::is_same<std::int32_t, test_type>{}));
  }
  {
    /**
     * @brief Test iterator type.
     */
    using test_iterator_type = test_iterator_helper::tst_bidirectional_iterator<std::int32_t *> const;
    /**
     * @brief Test value type for given iterator type.
     */
    using test_type          = ::portable_stl::iter_value_t<test_iterator_type>;
    EXPECT_TRUE((std::is_same<std::int32_t, test_type>{}));
  }
}

TEST(iterator, iter_rvalue_reference_t) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test iterator type.
     */
    using test_iterator_type = std::int32_t *;

    EXPECT_TRUE((::portable_stl::dereferenceable<test_iterator_type>{}()));
    EXPECT_TRUE((::portable_stl::dereferenceable<test_iterator_type>{}()));
    /**
     * @brief Test value type for given iterator type.
     */
    using test_type = ::portable_stl::iter_rvalue_reference_t<test_iterator_type>;
    EXPECT_TRUE((std::is_same<std::int32_t &&, test_type>{}));
  }

  // class with friend float& iter_move (founded by adl)
  EXPECT_TRUE(
    (std::is_same<float &, ::portable_stl::iter_rvalue_reference_t<test_iterator_helper::iter_move_mismatch>>{}));
}

TEST(iterator, incrementable_traits) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test iterator type.
     */
    using test_iterator_type = std::uint32_t *;
    /**
     * @brief Test difference type for given iterator type.
     */
    using test_type          = ::portable_stl::iter_difference_t<test_iterator_type>;
    EXPECT_TRUE((std::is_same<std::ptrdiff_t, test_type>{}));
  }
  {
    /**
     * @brief Test iterator type.
     */
    using test_iterator_type = test_iterator_helper::tst_bidirectional_iterator<std::int32_t *>;
    /**
     * @brief Test difference type for given iterator type.
     */
    using test_type          = ::portable_stl::iter_difference_t<test_iterator_type>;
    EXPECT_TRUE((std::is_same<std::ptrdiff_t, test_type>{}));
  }
}

TEST(iterator, iter_reference_t) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test iterator type.
     */
    using test_iterator_type = ::std::uint32_t *;

    /**
     * @brief Test reference type for given iterator type.
     */
    using test_type = ::portable_stl::iter_reference_t<test_iterator_type>;
    EXPECT_TRUE((std::is_same<std::uint32_t &, test_type>{}));
  }
  {
    /**
     * @brief Test iterator type.
     */
    using test_iterator_type = test_iterator_helper::tst_bidirectional_iterator<std::int32_t *>;

    /**
     * @brief Test reference type for given iterator type.
     */
    using test_type = ::portable_stl::iter_reference_t<test_iterator_type>;
    EXPECT_TRUE((std::is_same<std::int32_t &, test_type>{}));
  }
}

TEST(iterator, advance_random_iterator) {
  static_cast<void>(test_info_);
  /**
   * @brief Pointer iterator type.
   */
  using test_iter_type = ::std::int32_t *;

  std::int32_t test_array[test_iterator_helper::elemets_size]{test_iterator_helper::el_0,
                                                              test_iterator_helper::el_1,
                                                              test_iterator_helper::el_2,
                                                              test_iterator_helper::el_3,
                                                              test_iterator_helper::el_4};

  test_iter_type iter{&test_array[0]};
  EXPECT_EQ(test_iterator_helper::el_0, *iter);
  ::portable_stl::advance(iter, 1);
  EXPECT_EQ(test_iterator_helper::el_1, *iter);
  ::portable_stl::advance(iter, test_iterator_helper::el_2);
  EXPECT_EQ(test_iterator_helper::el_3, *iter);

  ::portable_stl::advance(iter, test_iterator_helper::el_m3);
  EXPECT_EQ(test_iterator_helper::el_0, *iter);
}

TEST(iterator, advance_biderectional_iterator) {
  static_cast<void>(test_info_);
  std::int32_t test_array[test_iterator_helper::elemets_size]{test_iterator_helper::el_0,
                                                              test_iterator_helper::el_1,
                                                              test_iterator_helper::el_2,
                                                              test_iterator_helper::el_3,
                                                              test_iterator_helper::el_4};

  auto iter = test_iterator_helper::tst_bidirectional_iterator<std::int32_t *>(&test_array[0]);

  EXPECT_EQ(test_iterator_helper::el_0, *iter);
  ::portable_stl::advance(iter, 1);
  EXPECT_EQ(test_iterator_helper::el_1, *iter);
  ::portable_stl::advance(iter, test_iterator_helper::el_2);
  EXPECT_EQ(test_iterator_helper::el_3, *iter);

  ::portable_stl::advance(iter, test_iterator_helper::el_m3);
  EXPECT_EQ(test_iterator_helper::el_0, *iter);
}

TEST(iterator, advance_input_iterator) {
  static_cast<void>(test_info_);
  std::int32_t test_array[test_iterator_helper::elemets_size]{test_iterator_helper::el_0,
                                                              test_iterator_helper::el_1,
                                                              test_iterator_helper::el_2,
                                                              test_iterator_helper::el_3,
                                                              test_iterator_helper::el_4};

  auto iter = test_iterator_helper::tst_input_iterator<std::int32_t *>(&test_array[0]);
  EXPECT_EQ(test_iterator_helper::el_0, *iter);
  ::portable_stl::advance(iter, 1);
  EXPECT_EQ(test_iterator_helper::el_1, *iter);
  ::portable_stl::advance(iter, test_iterator_helper::el_2);
  EXPECT_EQ(test_iterator_helper::el_3, *iter);
}

TEST(iterator, distance_random_iterator) {
  static_cast<void>(test_info_);
  /**
   * @brief Pointer iterator type.
   */
  using test_iter_type = ::std::int32_t *;

  std::int32_t test_array[test_iterator_helper::elemets_size]{test_iterator_helper::el_0,
                                                              test_iterator_helper::el_1,
                                                              test_iterator_helper::el_2,
                                                              test_iterator_helper::el_3,
                                                              test_iterator_helper::el_4};

  test_iter_type const first{&test_array[0]};
  test_iter_type const last{&test_array[test_iterator_helper::el_3]};
  EXPECT_EQ(test_iterator_helper::el_3, ::portable_stl::distance(first, last));
  EXPECT_EQ(test_iterator_helper::el_m3, ::portable_stl::distance(last, first));
  EXPECT_EQ(0, ::portable_stl::distance(first, first));
}

TEST(iterator, distance_input_iterator) {
  static_cast<void>(test_info_);
  std::int32_t test_array[test_iterator_helper::elemets_size]{test_iterator_helper::el_0,
                                                              test_iterator_helper::el_1,
                                                              test_iterator_helper::el_2,
                                                              test_iterator_helper::el_3,
                                                              test_iterator_helper::el_4};

  auto first = test_iterator_helper::tst_input_iterator<std::int32_t *>(&test_array[0]);
  auto last  = test_iterator_helper::tst_input_iterator<std::int32_t *>(&test_array[test_iterator_helper::el_3]);
  EXPECT_EQ(test_iterator_helper::el_3, ::portable_stl::distance(first, last));
  EXPECT_EQ(0, ::portable_stl::distance(first, first));
}

TEST(iterator, next) {
  static_cast<void>(test_info_);
  /**
   * @brief Pointer iterator type.
   */
  using test_iter_type = ::std::int32_t *;

  // {
  //   /**
  //    * @brief Test
  //    */
  //   using test_type = ::portable_stl::iterator_helper::is_input_iterator<test_iter_type>;
  //   ASSERT_TRUE(test_type{}());
  // }

  std::int32_t test_array[test_iterator_helper::elemets_size]{test_iterator_helper::el_0,
                                                              test_iterator_helper::el_1,
                                                              test_iterator_helper::el_2,
                                                              test_iterator_helper::el_3,
                                                              test_iterator_helper::el_4};

  test_iter_type const iter{&test_array[0]};
  EXPECT_EQ(test_iterator_helper::el_0, *iter);
  EXPECT_EQ(test_iterator_helper::el_0, *::portable_stl::next(iter, 0));

  EXPECT_EQ(test_iterator_helper::el_1, *::portable_stl::next(iter));
  EXPECT_EQ(test_iterator_helper::el_2, *::portable_stl::next(iter, test_iterator_helper::el_2));
  EXPECT_EQ(test_iterator_helper::el_3, *::portable_stl::next(iter, test_iterator_helper::el_3));

  EXPECT_EQ(test_iterator_helper::el_0, *iter);
}

TEST(iterator, prev) {
  static_cast<void>(test_info_);
  std::int32_t test_array[test_iterator_helper::elemets_size]{test_iterator_helper::el_0,
                                                              test_iterator_helper::el_1,
                                                              test_iterator_helper::el_2,
                                                              test_iterator_helper::el_3,
                                                              test_iterator_helper::el_4};

  { // must be bidirectional iterator at least for prev>0
    auto iter
      = test_iterator_helper::tst_bidirectional_iterator<std::int32_t *>(&test_array[test_iterator_helper::el_3]);

    EXPECT_EQ(test_iterator_helper::el_3, *iter);
    EXPECT_EQ(test_iterator_helper::el_3, *::portable_stl::prev(iter, 0));

    EXPECT_EQ(test_iterator_helper::el_2, *::portable_stl::prev(iter, 1));
    EXPECT_EQ(test_iterator_helper::el_1, *::portable_stl::prev(iter, test_iterator_helper::el_2));
    EXPECT_EQ(test_iterator_helper::el_0, *::portable_stl::prev(iter, test_iterator_helper::el_3));

    EXPECT_EQ(test_iterator_helper::el_3, *iter);
  }

  // int32_t *
  {
    auto iter = &test_array[test_iterator_helper::el_3];

    EXPECT_EQ(test_iterator_helper::el_3, *iter);
    EXPECT_EQ(test_iterator_helper::el_3, *::portable_stl::prev(iter, 0));

    EXPECT_EQ(test_iterator_helper::el_2, *::portable_stl::prev(iter, 1));
    EXPECT_EQ(test_iterator_helper::el_1, *::portable_stl::prev(iter, test_iterator_helper::el_2));
    EXPECT_EQ(test_iterator_helper::el_0, *::portable_stl::prev(iter, test_iterator_helper::el_3));

    EXPECT_EQ(test_iterator_helper::el_3, *iter);
  }
}

TEST(iterator, begin) {
  static_cast<void>(test_info_);
  // Container
  {
    std::vector<std::int32_t> test_vector{test_iterator_helper::el_0,
                                          test_iterator_helper::el_1,
                                          test_iterator_helper::el_2,
                                          test_iterator_helper::el_3,
                                          test_iterator_helper::el_4};
    auto                      begin_result = ::portable_stl::begin(test_vector);
    EXPECT_EQ(test_iterator_helper::el_0, *begin_result);
  }
  // Container const
  {
    std::vector<std::int32_t> const test_vector{test_iterator_helper::el_0,
                                                test_iterator_helper::el_1,
                                                test_iterator_helper::el_2,
                                                test_iterator_helper::el_3,
                                                test_iterator_helper::el_4};

    auto begin_result = ::portable_stl::begin(test_vector);
    EXPECT_EQ(test_iterator_helper::el_0, *begin_result);
  }
  // Array
  {
    std::int32_t test_array[test_iterator_helper::elemets_size]{test_iterator_helper::el_0,
                                                                test_iterator_helper::el_1,
                                                                test_iterator_helper::el_2,
                                                                test_iterator_helper::el_3,
                                                                test_iterator_helper::el_4};

    auto begin_result = ::portable_stl::begin(test_array);
    EXPECT_EQ(test_iterator_helper::el_0, *begin_result);
  }
  // std Container cbegin
  {
    std::vector<std::int32_t> test_vector{test_iterator_helper::el_0,
                                          test_iterator_helper::el_1,
                                          test_iterator_helper::el_2,
                                          test_iterator_helper::el_3,
                                          test_iterator_helper::el_4};

    auto begin_result = ::portable_stl::cbegin(test_vector);
    EXPECT_EQ(test_iterator_helper::el_0, *begin_result);

    EXPECT_TRUE((std::is_same<decltype(test_vector.cbegin()), decltype(begin_result)>{}));
  }
  // portable_stl Array cbegin
  {
    ::portable_stl::array<std::int32_t, test_iterator_helper::elemets_size> test_array{
      {test_iterator_helper::el_0,
       test_iterator_helper::el_1,
       test_iterator_helper::el_2,
       test_iterator_helper::el_3,
       test_iterator_helper::el_4}
    };

    auto begin_result = ::portable_stl::cbegin(test_array);
    EXPECT_EQ(test_iterator_helper::el_0, *begin_result);

    EXPECT_TRUE((std::is_same<decltype(test_array.cbegin()), decltype(begin_result)>{}));
  }
}

TEST(iterator, end) {
  static_cast<void>(test_info_);
  // Container
  {
    std::vector<std::int32_t> test_vector{test_iterator_helper::el_0,
                                          test_iterator_helper::el_1,
                                          test_iterator_helper::el_2,
                                          test_iterator_helper::el_3,
                                          test_iterator_helper::el_4};
    auto                      end_result = ::portable_stl::end(test_vector);
    EXPECT_EQ(test_iterator_helper::el_4, *std::prev(end_result));
  }
  // Container const
  {
    std::vector<std::int32_t> const test_vector{test_iterator_helper::el_0,
                                                test_iterator_helper::el_1,
                                                test_iterator_helper::el_2,
                                                test_iterator_helper::el_3,
                                                test_iterator_helper::el_4};

    auto end_result = ::portable_stl::end(test_vector);
    EXPECT_EQ(test_iterator_helper::el_4, *std::prev(end_result));
  }
  // Array
  {
    std::int32_t test_array[test_iterator_helper::elemets_size]{test_iterator_helper::el_0,
                                                                test_iterator_helper::el_1,
                                                                test_iterator_helper::el_2,
                                                                test_iterator_helper::el_3,
                                                                test_iterator_helper::el_4};

    auto end_result = ::portable_stl::end(test_array);
    EXPECT_EQ(test_iterator_helper::el_4, *::portable_stl::prev(end_result));
  }
  // std Container cend
  {
    std::vector<std::int32_t> test_vector{test_iterator_helper::el_0,
                                          test_iterator_helper::el_1,
                                          test_iterator_helper::el_2,
                                          test_iterator_helper::el_3,
                                          test_iterator_helper::el_4};

    auto end_result = ::portable_stl::cend(test_vector);
    EXPECT_EQ(test_iterator_helper::el_4, *std::prev(end_result));

    EXPECT_TRUE((std::is_same<decltype(test_vector.cend()), decltype(end_result)>{}));
  }
  // portable_stl Array cend
  {
    ::portable_stl::array<std::int32_t, test_iterator_helper::elemets_size> test_array{
      {test_iterator_helper::el_0,
       test_iterator_helper::el_1,
       test_iterator_helper::el_2,
       test_iterator_helper::el_3,
       test_iterator_helper::el_4}
    };

    auto end_result = ::portable_stl::cend(test_array);
    EXPECT_EQ(test_iterator_helper::el_4, *::portable_stl::prev(end_result));

    EXPECT_TRUE((std::is_same<decltype(test_array.cend()), decltype(end_result)>{}));
  }
}

TEST(iterator, rbegin) {
  static_cast<void>(test_info_);
  // Container
  {
    ::portable_stl::array<std::int32_t, test_iterator_helper::elemets_size> test_array{
      {test_iterator_helper::el_0,
       test_iterator_helper::el_1,
       test_iterator_helper::el_2,
       test_iterator_helper::el_3,
       test_iterator_helper::el_4}
    };
    auto rbegin_result = ::portable_stl::rbegin(test_array);
    EXPECT_EQ(test_iterator_helper::el_4, *rbegin_result);

    EXPECT_TRUE((std::is_same<decltype(rbegin_result), decltype(test_array.rbegin())>{}));
  }

  // Container const
  {
    constexpr ::portable_stl::array<std::int32_t, test_iterator_helper::elemets_size> test_array{
      {test_iterator_helper::el_0,
       test_iterator_helper::el_1,
       test_iterator_helper::el_2,
       test_iterator_helper::el_3,
       test_iterator_helper::el_4}
    };
    auto rbegin_result = ::portable_stl::rbegin(test_array);
    EXPECT_EQ(test_iterator_helper::el_4, *rbegin_result);

    EXPECT_TRUE((std::is_same<decltype(rbegin_result), decltype(test_array.rbegin())>{}));
  }

  // Array
  {
    std::int32_t test_array[test_iterator_helper::elemets_size]{test_iterator_helper::el_0,
                                                                test_iterator_helper::el_1,
                                                                test_iterator_helper::el_2,
                                                                test_iterator_helper::el_3,
                                                                test_iterator_helper::el_4};

    auto rbegin_result = ::portable_stl::rbegin(test_array);
    EXPECT_EQ(test_iterator_helper::el_4, *rbegin_result);

    EXPECT_TRUE((std::is_same<decltype(rbegin_result), ::portable_stl::reverse_iterator<std::int32_t *>>{}));
  }

  // Array crbegin
  {
    std::int32_t test_array[test_iterator_helper::elemets_size]{test_iterator_helper::el_0,
                                                                test_iterator_helper::el_1,
                                                                test_iterator_helper::el_2,
                                                                test_iterator_helper::el_3,
                                                                test_iterator_helper::el_4};

    auto rbegin_result = ::portable_stl::crbegin(test_array);
    EXPECT_EQ(test_iterator_helper::el_4, *rbegin_result);

    EXPECT_TRUE((std::is_same<decltype(rbegin_result), ::portable_stl::reverse_iterator<std::int32_t const *>>{}));
  }

  // Initializer list
  {
    auto const test_env = [](::portable_stl::initializer_list<std::int32_t> const &init_list) -> void {
      auto rbegin_result = ::portable_stl::rbegin(init_list);
      EXPECT_EQ(test_iterator_helper::el_4, *rbegin_result);

      EXPECT_TRUE((std::is_same<decltype(rbegin_result), ::portable_stl::reverse_iterator<std::int32_t const *>>{}));
    };
    test_env({test_iterator_helper::el_0,
              test_iterator_helper::el_1,
              test_iterator_helper::el_2,
              test_iterator_helper::el_3,
              test_iterator_helper::el_4});
  }
}

TEST(iterator, rend) {
  static_cast<void>(test_info_);
  // Container
  {
    ::portable_stl::array<std::int32_t, test_iterator_helper::elemets_size> test_array{
      {test_iterator_helper::el_0,
       test_iterator_helper::el_1,
       test_iterator_helper::el_2,
       test_iterator_helper::el_3,
       test_iterator_helper::el_4}
    };
    auto rend_result = ::portable_stl::rend(test_array);
    EXPECT_EQ(test_iterator_helper::el_0, *(rend_result - 1));

    EXPECT_TRUE((std::is_same<decltype(rend_result), decltype(test_array.rend())>{}));
  }

  // Container const
  {
    constexpr ::portable_stl::array<std::int32_t, test_iterator_helper::elemets_size> test_array{
      {test_iterator_helper::el_0,
       test_iterator_helper::el_1,
       test_iterator_helper::el_2,
       test_iterator_helper::el_3,
       test_iterator_helper::el_4}
    };
    auto rend_result = ::portable_stl::rend(test_array);
    EXPECT_EQ(test_iterator_helper::el_0, *(rend_result - 1));

    EXPECT_TRUE((std::is_same<decltype(rend_result), decltype(test_array.rend())>{}));
  }

  // Array
  {
    std::int32_t test_array[test_iterator_helper::elemets_size]{test_iterator_helper::el_0,
                                                                test_iterator_helper::el_1,
                                                                test_iterator_helper::el_2,
                                                                test_iterator_helper::el_3,
                                                                test_iterator_helper::el_4};

    auto rend_result = ::portable_stl::rend(test_array);
    EXPECT_EQ(test_iterator_helper::el_0, *(rend_result - 1));

    EXPECT_TRUE((std::is_same<decltype(rend_result), ::portable_stl::reverse_iterator<std::int32_t *>>{}));
  }

  // Array crend
  {
    std::int32_t test_array[test_iterator_helper::elemets_size]{test_iterator_helper::el_0,
                                                                test_iterator_helper::el_1,
                                                                test_iterator_helper::el_2,
                                                                test_iterator_helper::el_3,
                                                                test_iterator_helper::el_4};

    auto rend_result = ::portable_stl::crend(test_array);
    EXPECT_EQ(test_iterator_helper::el_0, *(rend_result - 1));

    EXPECT_TRUE((std::is_same<decltype(rend_result), ::portable_stl::reverse_iterator<std::int32_t const *>>{}));
  }

  // Initializer list
  {
    auto const test_env = [](::portable_stl::initializer_list<std::int32_t> const &init_list) -> void {
      auto rend_result = ::portable_stl::rend(init_list);
      EXPECT_EQ(test_iterator_helper::el_0, *--rend_result);

      EXPECT_TRUE((std::is_same<decltype(rend_result), ::portable_stl::reverse_iterator<std::int32_t const *>>{}));
    };
    test_env({test_iterator_helper::el_0,
              test_iterator_helper::el_1,
              test_iterator_helper::el_2,
              test_iterator_helper::el_3,
              test_iterator_helper::el_4});
  }
}

TEST(iterator, size) {
  static_cast<void>(test_info_);
  // Container
  {
    constexpr ::portable_stl::array<std::int32_t, test_iterator_helper::elemets_size> test_array{
      {test_iterator_helper::el_0,
       test_iterator_helper::el_1,
       test_iterator_helper::el_2,
       test_iterator_helper::el_3,
       test_iterator_helper::el_4}
    };
    auto size_result = ::portable_stl::size(test_array);
    EXPECT_EQ(test_iterator_helper::elemets_size, size_result);

    EXPECT_TRUE((std::is_same<decltype(size_result), ::portable_stl::size_t>{}));
  }

  // Array
  {
    std::int32_t test_array[test_iterator_helper::elemets_size]{test_iterator_helper::el_0,
                                                                test_iterator_helper::el_1,
                                                                test_iterator_helper::el_2,
                                                                test_iterator_helper::el_3,
                                                                test_iterator_helper::el_4};

    auto size_result = ::portable_stl::size(test_array);
    EXPECT_EQ(test_iterator_helper::elemets_size, size_result);

    EXPECT_TRUE((std::is_same<decltype(size_result), ::portable_stl::size_t>{}));
  }
}

TEST(iterator, ssize) {
  static_cast<void>(test_info_);
  // Container
  {
    constexpr ::portable_stl::array<std::int32_t, test_iterator_helper::elemets_size> test_array{
      {test_iterator_helper::el_0,
       test_iterator_helper::el_1,
       test_iterator_helper::el_2,
       test_iterator_helper::el_3,
       test_iterator_helper::el_4}
    };
    auto size_result = ::portable_stl::ssize(test_array);
    EXPECT_EQ(static_cast<::portable_stl::ptrdiff_t>(test_iterator_helper::elemets_size), size_result);

    EXPECT_TRUE((std::is_same<decltype(size_result), ::portable_stl::ptrdiff_t>{}));
  }

  // Array
  {
    std::int32_t test_array[test_iterator_helper::elemets_size]{test_iterator_helper::el_0,
                                                                test_iterator_helper::el_1,
                                                                test_iterator_helper::el_2,
                                                                test_iterator_helper::el_3,
                                                                test_iterator_helper::el_4};

    auto size_result = ::portable_stl::ssize(test_array);
    EXPECT_EQ(static_cast<::portable_stl::ptrdiff_t>(test_iterator_helper::elemets_size), size_result);

    EXPECT_TRUE((std::is_same<decltype(size_result), ::portable_stl::ptrdiff_t>{}));
  }
}

TEST(iterator, empty) {
  static_cast<void>(test_info_);
  // Container
  {
    ::portable_stl::array<std::int32_t, test_iterator_helper::elemets_size> test_array{
      {test_iterator_helper::el_0,
       test_iterator_helper::el_1,
       test_iterator_helper::el_2,
       test_iterator_helper::el_3,
       test_iterator_helper::el_4}
    };
    EXPECT_FALSE(::portable_stl::empty(test_array));
  }

  // Container empty
  {
    std::vector<std::int32_t> test_vector;
    EXPECT_TRUE(::portable_stl::empty(test_vector));

    std::vector<std::int32_t> const test_vector_c;
    EXPECT_TRUE(::portable_stl::empty(test_vector_c));
  }

  // Array
  {
    std::int32_t test_array[test_iterator_helper::elemets_size]{test_iterator_helper::el_0,
                                                                test_iterator_helper::el_1,
                                                                test_iterator_helper::el_2,
                                                                test_iterator_helper::el_3,
                                                                test_iterator_helper::el_4};
    EXPECT_FALSE(::portable_stl::empty(test_array));
  }

  // Initializer list
  {
    auto const test_env = [](::portable_stl::initializer_list<std::int32_t> const &init_list) -> void {
      EXPECT_FALSE(::portable_stl::empty(init_list));
    };
    test_env({test_iterator_helper::el_0,
              test_iterator_helper::el_1,
              test_iterator_helper::el_2,
              test_iterator_helper::el_3,
              test_iterator_helper::el_4});
  }

  // Initializer list empty
  {
    auto const test_env = [](::portable_stl::initializer_list<std::int32_t> const &init_list) -> void {
      EXPECT_TRUE(::portable_stl::empty(init_list));
    };
    test_env({});
  }
}

TEST(iterator, data) {
  static_cast<void>(test_info_);
  // Container
  {
    ::portable_stl::array<std::int32_t, test_iterator_helper::elemets_size> test_array{
      {test_iterator_helper::el_0,
       test_iterator_helper::el_1,
       test_iterator_helper::el_2,
       test_iterator_helper::el_3,
       test_iterator_helper::el_4}
    };
    EXPECT_EQ(test_array.begin(), ::portable_stl::data(test_array));
  }

  // Container const
  {
    constexpr ::portable_stl::array<std::int32_t, test_iterator_helper::elemets_size> test_array{
      {test_iterator_helper::el_0,
       test_iterator_helper::el_1,
       test_iterator_helper::el_2,
       test_iterator_helper::el_3,
       test_iterator_helper::el_4}
    };
    EXPECT_EQ(test_array.begin(), ::portable_stl::data(test_array));
  }

  // Array
  {
    std::int32_t test_array[test_iterator_helper::elemets_size]{test_iterator_helper::el_0,
                                                                test_iterator_helper::el_1,
                                                                test_iterator_helper::el_2,
                                                                test_iterator_helper::el_3,
                                                                test_iterator_helper::el_4};
    EXPECT_EQ(test_array, ::portable_stl::data(test_array));
  }

  // Initializer list
  {
    auto const test_env = [](::portable_stl::initializer_list<std::int32_t> const &init_list) -> void {
      EXPECT_EQ(init_list.begin(), ::portable_stl::data(init_list));
    };
    test_env({test_iterator_helper::el_0,
              test_iterator_helper::el_1,
              test_iterator_helper::el_2,
              test_iterator_helper::el_3,
              test_iterator_helper::el_4});
  }
}

// gcc tests
TEST(iterator, range_access_array) {
  static_cast<void>(test_info_);
  std::int32_t arr[1];
  EXPECT_EQ(::portable_stl::cbegin(arr), arr);
  EXPECT_EQ(::portable_stl::cend(arr), arr + 1);
  EXPECT_EQ(::portable_stl::rbegin(arr), ::portable_stl::reverse_iterator<std::int32_t *>(&arr[1]));
  EXPECT_EQ(::portable_stl::rend(arr), ::portable_stl::reverse_iterator<std::int32_t *>(arr));
  EXPECT_EQ(::portable_stl::crbegin(arr), ::portable_stl::reverse_iterator<std::int32_t *>(&arr[1]));
  EXPECT_EQ(::portable_stl::crend(arr), ::portable_stl::reverse_iterator<std::int32_t *>(arr));
  EXPECT_EQ(::portable_stl::data(arr), arr);
}

// gcc tests
TEST(iterator, range_access_initializer_list) {
  static_cast<void>(test_info_);

  auto const test_env = [](::portable_stl::initializer_list<std::int32_t> const &init_list) {
    EXPECT_EQ(::portable_stl::cbegin(init_list), init_list.begin());
    EXPECT_EQ(::portable_stl::cend(init_list), init_list.end());
    EXPECT_EQ(::portable_stl::rbegin(init_list),
              ::portable_stl::reverse_iterator<std::int32_t const *>(init_list.end()));
    EXPECT_EQ(::portable_stl::rend(init_list),
              ::portable_stl::reverse_iterator<std::int32_t const *>(init_list.begin()));
    EXPECT_EQ(::portable_stl::crbegin(init_list),
              ::portable_stl::reverse_iterator<std::int32_t const *>(init_list.end()));
    EXPECT_EQ(::portable_stl::crend(init_list),
              ::portable_stl::reverse_iterator<std::int32_t const *>(init_list.begin()));
    EXPECT_EQ(::portable_stl::data(init_list), init_list.begin());
  };

  test_env({1, 0, 1, 0});
}

// gcc tests
TEST(iterator, range_access_vector) {
  static_cast<void>(test_info_);
  std::vector<std::int32_t> vec{1};
  EXPECT_EQ(::portable_stl::cbegin(vec), vec.cbegin());
  EXPECT_EQ(::portable_stl::cend(vec), vec.cend());
  EXPECT_EQ(::portable_stl::rbegin(vec), vec.rbegin());
  EXPECT_EQ(::portable_stl::rend(vec), vec.rend());
  EXPECT_EQ(::portable_stl::crbegin(vec), vec.crbegin());
  EXPECT_EQ(::portable_stl::crend(vec), vec.crend());
  EXPECT_EQ(::portable_stl::data(vec), vec.data());
}
