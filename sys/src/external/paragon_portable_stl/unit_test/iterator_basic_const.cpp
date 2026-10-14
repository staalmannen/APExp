// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="iterator_basic_const.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "iterator_helper.h"
#include "portable_stl/iterator/basic_const_iterator.h"
#include "test_debug_helper.h"

TEST(basic_const_iterator, construction) {
  static_cast<void>(test_info_);
  /**
   * @brief Test iterator type.
   */
  using test_iterator_type = ::std::int32_t *;
  std::int32_t value{1};

  // default ctor
  {
    ::portable_stl::basic_const_iterator<test_iterator_type> citer{&value};
    static_cast<void>(citer);
  }
  // make_const_iterator
  {
    test_iterator_type iter{&value};
    auto               citer = ::portable_stl::make_const_iterator(iter);
    static_cast<void>(iter);
    static_cast<void>(citer);
  }
  // make_const_sentinel
  {
    test_iterator_type iter{&value};
    auto               citer = ::portable_stl::make_const_sentinel(iter);
    static_cast<void>(iter);
    static_cast<void>(citer);
  }
}

TEST(basic_const_iterator, iterator_concepts) {
  static_cast<void>(test_info_);

  /**
   * @brief Test iterator type.
   */
  using test_base_iter_type = ::test_iterator_helper::tst_bidirectional_iterator<int *>;
  /**
   * @brief Test adapter.
   */
  using const_iter_type     = ::portable_stl::basic_const_iterator<test_base_iter_type>;
  // {
  //   /**
  //    * @brief
  //    */
  //   using is_cpp17_iterator               = ::portable_stl::cpp17_iterator<const_iter_type>;
  //   /**
  //    * @brief
  //    */
  //   using is_cpp17_input_iterator         = ::portable_stl::cpp17_input_iterator<const_iter_type>;
  //   /**
  //    * @brief
  //    */
  //   using is_cpp17_forward_iterator       = ::portable_stl::cpp17_forward_iterator<const_iter_type>;
  //   /**
  //    * @brief
  //    */
  //   using is_cpp17_bidirectional_iterator = ::portable_stl::cpp17_bidirectional_iterator<const_iter_type>;
  //   /**
  //    * @brief
  //    */
  //   using is_cpp17_random_access_iterator = ::portable_stl::cpp17_random_access_iterator<const_iter_type>;
  // }
  EXPECT_TRUE((::portable_stl::input_iterator<test_base_iter_type>{}()));
  EXPECT_FALSE((typename ::portable_stl::iterator_helper::specifies_members<const_iter_type>::type{}()));
}

TEST(basic_const_iterator, nested_types) {
  static_cast<void>(test_info_);

  /**
   * @brief Test iterator type.
   */
  using test_base_iter_type = std::int32_t *;
  /**
   * @brief Test adapter.
   */
  using const_iter_type     = ::portable_stl::basic_const_iterator<test_base_iter_type>;

  EXPECT_TRUE(
    (std::is_same<typename const_iter_type::value_type, ::portable_stl::iter_value_t<test_base_iter_type>>{}));
  EXPECT_TRUE((
    std::is_same<typename const_iter_type::difference_type, ::portable_stl::iter_difference_t<test_base_iter_type>>{}));
  EXPECT_TRUE((std::is_same<typename const_iter_type::iterator_category,
                            typename ::portable_stl::iterator_traits<test_base_iter_type>::iterator_category>{}));
}

TEST(basic_const_iterator, default_initializable) {
  static_cast<void>(test_info_);

  /**
   * @brief Test iterator type.
   */
  using test_base_iter_type = std::int32_t *;
  /**
   * @brief Test adapter.
   */
  using const_iter_type     = ::portable_stl::basic_const_iterator<test_base_iter_type>;

  EXPECT_TRUE((::portable_stl::default_initializable<test_base_iter_type>{}()));
  EXPECT_TRUE((::portable_stl::default_initializable<const_iter_type>{}()));

  test_base_iter_type base_iter{};
  auto                test_fn = [](test_base_iter_type iter_r_value) {
    auto citer = const_iter_type{iter_r_value};
    static_cast<void>(citer);
  };
  test_fn(base_iter);
}

TEST(basic_const_iterator, base) {
  static_cast<void>(test_info_);

  /**
   * @brief Test iterator type.
   */
  using test_base_iter_type = std::int32_t *;
  /**
   * @brief Test adapter.
   */
  using const_iter_type     = ::portable_stl::basic_const_iterator<test_base_iter_type>;

  std::int32_t        int_value{1};
  test_base_iter_type base_iter{&int_value};
  const_iter_type     citer{base_iter};

  decltype(auto) base = citer.base();
  EXPECT_TRUE((std::is_same<test_base_iter_type const &, decltype(base)>{}));

  decltype(auto) move_base = std::move(citer).base();
  EXPECT_TRUE((std::is_same<test_base_iter_type, decltype(move_base)>{}));
}

TEST(basic_const_iterator, iter_move) {
  static_cast<void>(test_info_);

  /**
   * @brief Test iterator type.
   */
  using test_base_iter_type = std::int32_t *;
  /**
   * @brief Test adapter.
   */
  using const_iter_type     = ::portable_stl::basic_const_iterator<test_base_iter_type>;

  std::int32_t        int_value{1};
  test_base_iter_type base_iter{&int_value};
  const_iter_type     citer{base_iter};

  /**
   * @brief expected type
   */
  using Expected = ::portable_stl::common_reference_t<::portable_stl::iter_value_t<test_base_iter_type> const &&,
                                                      ::portable_stl::iter_rvalue_reference_t<test_base_iter_type>>;
  decltype(auto) iter_move = ::portable_stl::ranges::iter_move(citer);
  EXPECT_TRUE((std::is_same<Expected, decltype(iter_move)>{}));
  EXPECT_TRUE(noexcept(::portable_stl::ranges::iter_move(citer))
              == noexcept(static_cast<Expected>(::portable_stl::ranges::iter_move(citer.base()))));
}

/**
 * @brief
 */
class basic_const_iterator_operators : public ::testing::Test {
protected:
  /**
   * @brief Test iterator type.
   */
  using test_base_iter_type = std::int32_t *;
  /**
   * @brief Test adapter.
   */
  using const_iter_type     = ::portable_stl::basic_const_iterator<test_base_iter_type>;

  /**
   * @brief Test data
   */
  std::int32_t some_ints[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  /**
   * @brief Test base iterator
   */
  test_base_iter_type iter{&some_ints[4]};

  /**
   * @brief Test const iterator
   */
  const_iter_type citer{iter};

  /**
   * @brief Set the Up object
   */
  void SetUp() override {
    ::testing::Test::SetUp();
  }

  /**
   * @brief
   */
  void TearDown() override {
    ::testing::Test::TearDown();
  }
};

TEST_F(basic_const_iterator_operators, deref) {
  static_cast<void>(test_info_);

  auto val = *citer;

  EXPECT_EQ(val, *iter);
  EXPECT_TRUE(noexcept(*citer)
              == noexcept(static_cast<::portable_stl::iter_const_reference_t<test_base_iter_type>>(*iter)));
}

TEST_F(basic_const_iterator_operators, operator_arrow) {
  static_cast<void>(test_info_);

  auto ptr = citer.operator->();

  EXPECT_EQ(ptr, ::portable_stl::addressof(*iter));
  EXPECT_TRUE(noexcept(::portable_stl::to_address(iter)) == noexcept(citer.operator->()));
}

TEST_F(basic_const_iterator_operators, increment_pre) {
  static_cast<void>(test_info_);

  auto citer2 = ++citer;
  ++iter;

  EXPECT_EQ(citer2, iter);
  EXPECT_EQ(*citer2, *iter);
  EXPECT_TRUE(noexcept(++citer) == noexcept(++iter));
}

TEST_F(basic_const_iterator_operators, increment_post) {
  static_cast<void>(test_info_);

  auto citer2 = citer++;

  EXPECT_TRUE(citer2 == iter);
  EXPECT_TRUE(*citer2 == *iter);
  EXPECT_TRUE(noexcept(citer++) == noexcept(iter++));
}

TEST_F(basic_const_iterator_operators, decrement_pre) {
  static_cast<void>(test_info_);

  auto citer2 = --citer;
  --iter;

  EXPECT_TRUE(citer2 == iter);
  EXPECT_TRUE(*citer2 == *iter);
  EXPECT_TRUE(noexcept(--citer) == noexcept(--iter));
}

TEST_F(basic_const_iterator_operators, decrement_post) {
  static_cast<void>(test_info_);

  auto citer2 = citer--;

  EXPECT_TRUE(citer2 == iter);
  EXPECT_TRUE(*citer2 == *iter);
  EXPECT_TRUE(noexcept(citer--) == noexcept(iter--));

  iter--;
  EXPECT_TRUE(citer == iter);
  EXPECT_TRUE(*citer == *iter);
}

TEST_F(basic_const_iterator_operators, increment_assignment) {
  static_cast<void>(test_info_);

  auto citer2 = (citer += 2);
  iter += 2;

  EXPECT_TRUE(citer2 == iter);
  EXPECT_TRUE(*citer2 == *iter);
  EXPECT_TRUE(noexcept(citer += 2) == noexcept(iter += 2));
}

TEST_F(basic_const_iterator_operators, decrement_assignment) {
  static_cast<void>(test_info_);

  auto citer2 = (citer -= 2);
  iter -= 2;

  EXPECT_TRUE(citer2 == iter);
  EXPECT_TRUE(*citer2 == *iter);
  EXPECT_TRUE(noexcept(citer -= 2) == noexcept(iter -= 2));
}

TEST_F(basic_const_iterator_operators, operator_at) {
  static_cast<void>(test_info_);

  auto val = citer[0];

  EXPECT_EQ(iter[0], val);
  EXPECT_TRUE(noexcept(citer[0])
              == noexcept(static_cast<::portable_stl::iter_const_reference_t<test_base_iter_type>>(iter[0])));
}

TEST_F(basic_const_iterator_operators, equality) {
  // Validate basic_const_iterator::operator==()
  static_cast<void>(test_info_);

  auto citer2 = citer;
  static_cast<void>(citer2);

  EXPECT_TRUE((::portable_stl::sentinel_for<test_base_iter_type, test_base_iter_type>{}()));

  // EXPECT_TRUE(citer == citer2);
  // EXPECT_TRUE(citer == iter);
  // EXPECT_TRUE(iter == citer);

  // EXPECT_TRUE(noexcept(citer == citer2) == noexcept(iter == iter));
  // EXPECT_TRUE(noexcept(citer == iter) == noexcept(iter == iter));
  // EXPECT_TRUE(noexcept(iter == citer) == noexcept(iter == iter));
}

TEST_F(basic_const_iterator_operators, compares_with_const_iter) {
  // Validate operator{<, >, <=, >=}(const basic_const_iterator&, const basic_const_iterator&)
  static_cast<void>(test_info_);

  auto citer2 = (citer + 1);
  // EXPECT_TRUE(citer != citer2);
  EXPECT_TRUE(citer < citer2);
  EXPECT_TRUE(citer2 > citer);
  EXPECT_TRUE(citer <= citer2);
  EXPECT_TRUE(citer2 >= citer);

  // EXPECT_TRUE(noexcept(citer != citer2) == noexcept(citer.base() != citer2.base()));
  EXPECT_TRUE(noexcept(citer < citer2) == noexcept(citer.base() < citer2.base()));
  EXPECT_TRUE(noexcept(citer2 > citer) == noexcept(citer2.base() > citer.base()));
  EXPECT_TRUE(noexcept(citer <= citer2) == noexcept(citer.base() <= citer2.base()));
  EXPECT_TRUE(noexcept(citer2 >= citer) == noexcept(citer2.base() >= citer.base()));
}

TEST_F(basic_const_iterator_operators, compares_with_not_const_iter1) {
  // Validate operator{<, >, <=, >=}(const basic_const_iterator&, const "not same as basic_const_iterator"&)
  static_cast<void>(test_info_);

  iter += 1;
  EXPECT_TRUE(citer < iter);
  EXPECT_FALSE(citer > iter);
  EXPECT_TRUE(citer <= iter);
  EXPECT_FALSE(citer >= iter);

  EXPECT_TRUE(noexcept(citer < iter) == noexcept(citer.base() < iter));
  EXPECT_TRUE(noexcept(!(citer > iter)) == noexcept(!(citer.base() > iter)));
  EXPECT_TRUE(noexcept(citer <= iter) == noexcept(citer.base() <= iter));
  EXPECT_TRUE(noexcept(!(citer >= iter)) == noexcept(!(citer.base() >= iter)));
}

TEST_F(basic_const_iterator_operators, compares_with_not_const_iter2) {
  // Validate operator{<, >, <=, >=}(const "not a const iterator"&, const basic_const_iterator&)
  static_cast<void>(test_info_);

  iter += 1;
  EXPECT_FALSE(iter < citer);
  EXPECT_TRUE(iter > citer);
  EXPECT_FALSE(iter <= citer);
  EXPECT_TRUE(iter >= citer);

  EXPECT_TRUE(noexcept(iter < citer) == noexcept(iter < citer.base()));
  EXPECT_TRUE(noexcept(!(iter > citer)) == noexcept(!(iter > citer.base())));
  EXPECT_TRUE(noexcept(iter <= citer) == noexcept(iter <= citer.base()));
  EXPECT_TRUE(noexcept(!(iter >= citer)) == noexcept(!(iter >= citer.base())));

  EXPECT_TRUE(citer != iter);
  // EXPECT_TRUE(iter != citer);

  EXPECT_TRUE(noexcept(citer != iter) == noexcept(iter != iter));
  // EXPECT_TRUE(noexcept(iter != citer) == noexcept(iter == iter));
}

TEST_F(basic_const_iterator_operators, operator_plus) {
  static_cast<void>(test_info_);

  auto citer2 = citer + 1;
  auto citer3 = 1 + citer;
  auto citer4 = 1 + 1 + citer;
  iter += 1;

  static_cast<void>(citer3);
  static_cast<void>(citer4);
  // EXPECT_TRUE(citer2 == citer3);
  // EXPECT_TRUE(citer2 != citer4);
  EXPECT_TRUE(*citer2 == *iter);

  EXPECT_TRUE(noexcept(citer + 1) == noexcept(iter + 1));
  EXPECT_TRUE(noexcept(1 + citer) == noexcept(1 + iter));
}

TEST_F(basic_const_iterator_operators, operator_minus) {
  static_cast<void>(test_info_);

  auto citer2 = citer - 1;
  iter -= 1;

  EXPECT_TRUE(*citer2 == *iter);

  EXPECT_TRUE(noexcept(citer - 1) == noexcept(iter - 1));
}

TEST_F(basic_const_iterator_operators, operator_difference) {
  // Validate operator-(const basic_const_iterator&, sized_sentinel)
  static_cast<void>(test_info_);
  iter += 1;

  EXPECT_EQ(-1, citer - iter);
  EXPECT_EQ(1, iter - citer);
  // EXPECT_EQ(0, citer - citer);

  EXPECT_TRUE(noexcept(iter - citer) == noexcept(iter - iter));
  EXPECT_TRUE(noexcept(citer - iter) == noexcept(iter - iter));
  // EXPECT_TRUE(noexcept(citer - citer) == noexcept(iter - iter));
}

namespace test_basic_const_iterator_helper {
/**
 * @brief
 * @tparam t_iter
 */
template<class t_iter> void test_case1() {
  /**
   * @brief Const iterator adapter
   */
  using t_citer = ::portable_stl::basic_const_iterator<t_iter>;

  EXPECT_TRUE((std::is_same<::portable_stl::const_iterator<t_iter>, t_citer>{}));
  EXPECT_TRUE((std::is_same<::portable_stl::const_sentinel<t_iter>, t_citer>{}));
  EXPECT_TRUE(
    (std::is_same<::portable_stl::iter_const_reference_t<t_iter>, ::portable_stl::iter_reference_t<t_citer>>{}));

  EXPECT_EQ(::portable_stl::input_iterator<t_iter>{}(), ::portable_stl::input_iterator<t_citer>{}());
  EXPECT_EQ(::portable_stl::forward_iterator<t_iter>{}(), ::portable_stl::forward_iterator<t_citer>{}());
  EXPECT_EQ(::portable_stl::bidirectional_iterator<t_iter>{}(), ::portable_stl::bidirectional_iterator<t_citer>{}());
  EXPECT_EQ(::portable_stl::random_access_iterator<t_iter>{}(), ::portable_stl::random_access_iterator<t_citer>{}());
}
} // namespace test_basic_const_iterator_helper

TEST(const_iterator, iterator) {
  static_cast<void>(test_info_);
  // static_cast<void>(test_case1<std::int32_t *>());

  // static_cast<void>(test_basic_const_iterator_helper::test_case1<test_iterator_helper::tst_input_iterator<std::int32_t
  // *>>());
  // static_cast<void>(test_basic_const_iterator_helper::test_case1<test_iterator_helper::tst_bidirectional_iterator<std::int32_t
  // *>>());
  // static_cast<void>(test_basic_const_iterator_helper::test_case1<test_iterator_helper::tst_random_access_iterator<std::int32_t
  // *>>());
}

// TEST(const_iterator, concepts) {
//   static_cast<void>(test_info_);
//   using t_iter  = test_iterator_helper::tst_input_iterator<std::int32_t *>;
//   // using t_iter  = std::int32_t *;
//   using t_citer = ::portable_stl::basic_const_iterator<t_iter>;

//   EXPECT_TRUE((::portable_stl::input_or_output_iterator<t_iter>{}()));
//   EXPECT_TRUE((::portable_stl::input_or_output_iterator<t_citer>{}()));

//   EXPECT_TRUE((::portable_stl::indirectly_readable<t_iter>{}()));
//   EXPECT_TRUE((::portable_stl::indirectly_readable<t_citer>{}()));

//   EXPECT_TRUE((::portable_stl::cpp17_iterator<t_iter>{}()));
//   EXPECT_TRUE((::portable_stl::cpp17_iterator<t_citer>{}()));

//   EXPECT_TRUE((::portable_stl::cpp17_input_iterator<t_iter>{}()));
//   EXPECT_TRUE((::portable_stl::cpp17_input_iterator<t_citer>{}()));

//   EXPECT_TRUE((::portable_stl::equality_comparable<t_iter>{}()));
//   EXPECT_TRUE((::portable_stl::equality_comparable<t_citer>{}()));

//   EXPECT_TRUE((::portable_stl::weakly_equality_comparable_with<t_iter, t_iter>{}()));
//   EXPECT_TRUE((::portable_stl::weakly_equality_comparable_with<t_citer, t_citer>{}()));

//   EXPECT_TRUE((::portable_stl::semiregular<t_citer>{}()));
//   EXPECT_TRUE((::portable_stl::weakly_equality_comparable_with<t_citer, t_iter>{}()));
//   EXPECT_TRUE((::portable_stl::sentinel_for<t_citer, t_iter>{}()));
//   EXPECT_TRUE((::portable_stl::sentinel_for<t_iter, t_citer>{}()));

//   t_citer citer{};
//   t_iter  iter{};

//   // citer == citer;
//   // citer != citer;
//   citer == iter; // true =  sentinel_for<t_sentinel=t_iter, t_iter=t_iter>
//   // iter == citer; // false = sentinel_for<t_sentinel=t_iter, t_iter=t_iter>
//   //  citer1 != citer2;

//   using diff1 = typename ::portable_stl::incrementable_traits<t_iter>::difference_type;
//   using diff2 = typename ::portable_stl::incrementable_traits<t_citer>::difference_type;

//   using value_type1 = typename ::portable_stl::indirectly_readable_traits<t_iter>::value_type;
//   using value_type2 = typename ::portable_stl::indirectly_readable_traits<t_citer>::value_type;

//   using iter_ref1 = ::portable_stl::iter_reference_t<t_iter>;
//   using iter_ref2 = ::portable_stl::iter_reference_t<t_citer>;

//   using com_ref1 = ::portable_stl::common_reference_t<iter_ref1 &&, value_type1 &>;
//   using com_ref2 = ::portable_stl::common_reference_t<iter_ref2 &&, value_type2 &>;

//   using ch1 = decltype(*::portable_stl::declval<t_iter &>()++);
//   using ch2 = decltype(*::portable_stl::declval<t_citer &>()++);

//   using iter_caterogy1 = typename t_iter::iterator_category;
//   // using iter_caterogy2 = typename t_citer::iterator_category;

//   using iter_traits1 = ::portable_stl::iterator_traits<t_iter>;
//   using iter_traits2 = ::portable_stl::iterator_traits<t_citer>;

//   using iter_tr_caterogy1 = typename iter_traits1::iterator_category;
//   using iter_tr_caterogy2 = typename iter_traits2::iterator_category;

//   using iter_tr_ref1 = typename iter_traits1::reference;
//   using iter_tr_ref2 = typename iter_traits2::reference;

//   using concept1 = ::portable_stl::iterator_helper::iter_concept<t_iter>;
//   using concept2 = ::portable_stl::iterator_helper::iter_concept<t_citer>;

//   // static_cast<void>(test_case1<test_iterator_helper::tst_input_iterator<std::int32_t *>>());
//   // static_cast<void>(test_case1<test_iterator_helper::tst_bidirectional_iterator<std::int32_t *>>());
//   // static_cast<void>(test_case1<test_iterator_helper::tst_random_access_iterator<std::int32_t *>>());
// }

TEST(const_iterator, range) {
  static_cast<void>(test_info_);

  {
    /**
     * @brief Test iterator type.
     */
    using t_iter = std::int32_t *;

    using t_citer = ::portable_stl::basic_const_iterator<t_iter>;
    EXPECT_TRUE((std::is_same<::portable_stl::const_iterator<t_iter>, t_citer>{}));
    EXPECT_TRUE((std::is_same<::portable_stl::const_sentinel<t_iter>, t_citer>{}));
    EXPECT_TRUE(
      (std::is_same<::portable_stl::iter_const_reference_t<t_iter>, ::portable_stl::iter_reference_t<t_citer>>{}));
  }
}
