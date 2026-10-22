// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "portable_stl/array/array.h"
#include "portable_stl/utility/tuple/tuple.h"
#include "tuple_test_helper.h"

TEST(tuple, tuple_restrictions) {
  static_cast<void>(test_info_);

  EXPECT_TRUE(
    (::portable_stl::tuple_helper::tuple_constructible<::portable_stl::tuple<std::int32_t, std::int32_t, std::int32_t>,
                                                       std::int32_t const &,
                                                       std::int32_t const &,
                                                       std::int32_t const &>{}()));
  EXPECT_TRUE(
    (::portable_stl::tuple_helper::tuple_perfect_val<::portable_stl::tuple<std::int32_t, std::int32_t, std::int32_t>,
                                                     std::int32_t const &,
                                                     std::int32_t const &,
                                                     std::int32_t const &>{}()));
}

TEST(tuple, equal) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<>;
    T1 const tpl1;
    T2 const tpl2;
    EXPECT_EQ(tpl1, tpl2);
    EXPECT_FALSE(tpl1 != tpl2);
    EXPECT_FALSE(tpl2 != tpl1);
  }

  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int32_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int64_t>;

    T1 const tpl1{1};
    T2 const tpl2{2};

    EXPECT_FALSE(tpl1 == tpl2);
    EXPECT_NE(tpl1, tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int32_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int64_t>;

    T1 const tpl1{1};
    T2 const tpl2{1};
    
    EXPECT_EQ(tpl1, tpl2);
    EXPECT_FALSE(tpl1 != tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int32_t, std::int64_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int64_t, std::int32_t>;

    T1 const tpl1{1, 2};
    T2 const tpl2{1, 2};
    EXPECT_EQ(tpl1, tpl2);
    EXPECT_FALSE(tpl1 != tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int32_t, std::int64_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int64_t, std::int32_t>;

    T1 const tpl1{1, 2};
    T2 const tpl2{1, 3};
    EXPECT_FALSE(tpl1 == tpl2);
    EXPECT_NE(tpl1, tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int32_t, std::int64_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int64_t, std::int32_t>;

    T1 const tpl1{1, 3};
    T2 const tpl2{2, 3};
    EXPECT_FALSE(tpl1 == tpl2);
    EXPECT_NE(tpl1, tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int32_t, std::int64_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int64_t, std::int32_t>;

    T1 const tpl1{1, 3};
    T2 const tpl2{2, 4};
    EXPECT_FALSE(tpl1 == tpl2);
    EXPECT_NE(tpl1, tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t, std::int64_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int32_t, std::int64_t, std::int32_t>;

    T1 const tpl1{1, 2, 3};
    T2 const tpl2{1, 2, 3};
    EXPECT_EQ(tpl1, tpl2);
    EXPECT_FALSE(tpl1 != tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t, std::int64_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int32_t, std::int64_t, std::int32_t>;

    T1 const tpl1{1, 3, 4};
    T2 const tpl2{2, 3, 4};
    EXPECT_FALSE(tpl1 == tpl2);
    EXPECT_NE(tpl1, tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t, std::int64_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int32_t, std::int64_t, std::int32_t>;

    T1 const tpl1{1, 2, 3};
    T2 const tpl2{1, 3, 3};
    EXPECT_FALSE(tpl1 == tpl2);
    EXPECT_NE(tpl1, tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t, std::int64_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int32_t, std::int64_t, std::int32_t>;

    T1 const tpl1{1, 2, 3};
    T2 const tpl2{1, 2, 4};
    EXPECT_FALSE(tpl1 == tpl2);
    EXPECT_NE(tpl1, tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t, std::int64_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int32_t, std::int64_t, std::int32_t>;

    T1 const tpl1{1, 2, 3};
    T2 const tpl2{1, 3, 2};
    EXPECT_FALSE(tpl1 == tpl2);
    EXPECT_NE(tpl1, tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t, std::int64_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int32_t, std::int64_t, std::int32_t>;

    T1 const tpl1{1, 3, 4};
    T2 const tpl2{2, 3, 3};
    EXPECT_FALSE(tpl1 == tpl2);
    EXPECT_NE(tpl1, tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t, std::int64_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int32_t, std::int64_t, std::int32_t>;

    T1 const tpl1{1, 3, 4};
    T2 const tpl2{2, 4, 4};
    EXPECT_FALSE(tpl1 == tpl2);
    EXPECT_NE(tpl1, tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t, std::int64_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int32_t, std::int64_t, std::int32_t>;

    T1 const tpl1{1, 3, 4};
    T2 const tpl2{2, 4, 3};
    EXPECT_FALSE(tpl1 == tpl2);
    EXPECT_NE(tpl1, tpl2);
  }
}

TEST(tuple, compare) {
  static_cast<void>(test_info_);

  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<>;

    T1 const tpl1;
    T2 const tpl2;
    EXPECT_FALSE(tpl1 < tpl2);
    EXPECT_LE(tpl1, tpl2);
    EXPECT_FALSE(tpl1 > tpl2);
    EXPECT_GE(tpl1, tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int32_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int64_t>;

    T1 const tpl1{1};
    T2 const tpl2{1};
    EXPECT_FALSE(tpl1 < tpl2);
    EXPECT_LE(tpl1, tpl2);
    EXPECT_FALSE(tpl1 > tpl2);
    EXPECT_GE(tpl1, tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int32_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int64_t>;

    T1 const tpl1{2};
    T2 const tpl2{1};
    EXPECT_FALSE(tpl1 < tpl2);
    EXPECT_FALSE(tpl1 <= tpl2);
    EXPECT_GT(tpl1, tpl2);
    EXPECT_GE(tpl1, tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int32_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int64_t>;

    T1 const tpl1{1};
    T2 const tpl2{2};
    EXPECT_LT(tpl1, tpl2);
    EXPECT_LE(tpl1, tpl2);
    EXPECT_FALSE(tpl1 > tpl2);
    EXPECT_FALSE(tpl1 >= tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int32_t, std::int64_t>;

    T1 const tpl1{1, 2};
    T2 const tpl2{1, 2};
    EXPECT_FALSE(tpl1 < tpl2);
    EXPECT_LE(tpl1, tpl2);
    EXPECT_FALSE(tpl1 > tpl2);
    EXPECT_GE(tpl1, tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int32_t, std::int64_t>;

    T1 const tpl1{1, 2};
    T2 const tpl2{0, 2};
    EXPECT_FALSE(tpl1 < tpl2);
    EXPECT_FALSE(tpl1 <= tpl2);
    EXPECT_GT(tpl1, tpl2);
    EXPECT_GE(tpl1, tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int32_t, std::int64_t>;

    T1 const tpl1{1, 3};
    T2 const tpl2{2, 3};
    EXPECT_LT(tpl1, tpl2);
    EXPECT_LE(tpl1, tpl2);
    EXPECT_FALSE(tpl1 > tpl2);
    EXPECT_FALSE(tpl1 >= tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int32_t, std::int64_t>;

    T1 const tpl1{1, 2};
    T2 const tpl2{1, 1};
    EXPECT_FALSE(tpl1 < tpl2);
    EXPECT_FALSE(tpl1 <= tpl2);
    EXPECT_GT(tpl1, tpl2);
    EXPECT_GE(tpl1, tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int32_t, std::int64_t>;

    T1 const tpl1{1, 2};
    T2 const tpl2{1, 3};
    EXPECT_LT(tpl1, tpl2);
    EXPECT_LE(tpl1, tpl2);
    EXPECT_FALSE(tpl1 > tpl2);
    EXPECT_FALSE(tpl1 >= tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t, std::int64_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int32_t, std::int64_t, std::int32_t>;

    T1 const tpl1{1, 2, 3};
    T2 const tpl2{1, 2, 3};
    EXPECT_FALSE(tpl1 < tpl2);
    EXPECT_LE(tpl1, tpl2);
    EXPECT_FALSE(tpl1 > tpl2);
    EXPECT_GE(tpl1, tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t, std::int64_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int32_t, std::int64_t, std::int32_t>;

    T1 const tpl1{1, 2, 3};
    T2 const tpl2{0, 2, 3};
    EXPECT_FALSE(tpl1 < tpl2);
    EXPECT_FALSE(tpl1 <= tpl2);
    EXPECT_GT(tpl1, tpl2);
    EXPECT_GE(tpl1, tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t, std::int64_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int32_t, std::int64_t, std::int32_t>;

    T1 const tpl1{0, 2, 3};
    T2 const tpl2{1, 2, 3};
    EXPECT_LT(tpl1, tpl2);
    EXPECT_LE(tpl1, tpl2);
    EXPECT_FALSE(tpl1 > tpl2);
    EXPECT_FALSE(tpl1 >= tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t, std::int64_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int32_t, std::int64_t, std::int32_t>;

    T1 const tpl1{1, 2, 3};
    T2 const tpl2{1, 1, 3};
    EXPECT_FALSE(tpl1 < tpl2);
    EXPECT_FALSE(tpl1 <= tpl2);
    EXPECT_GT(tpl1, tpl2);
    EXPECT_GE(tpl1, tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t, std::int64_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int32_t, std::int64_t, std::int32_t>;

    T1 const tpl1{1, 2, 3};
    T2 const tpl2{1, 3, 3};
    EXPECT_LT(tpl1, tpl2);
    EXPECT_LE(tpl1, tpl2);
    EXPECT_FALSE(tpl1 > tpl2);
    EXPECT_FALSE(tpl1 >= tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t, std::int64_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int32_t, std::int64_t, std::int32_t>;

    T1 const tpl1{1, 2, 3};
    T2 const tpl2{1, 2, 2};
    EXPECT_FALSE(tpl1 < tpl2);
    EXPECT_FALSE(tpl1 <= tpl2);
    EXPECT_GT(tpl1, tpl2);
    EXPECT_GE(tpl1, tpl2);
  }
  {
    /**
     * @brief Test tuple type.
     */
    using T1 = ::portable_stl::tuple<std::int64_t, std::int32_t, std::int64_t>;
    /**
     * @brief Test tuple type.
     */
    using T2 = ::portable_stl::tuple<std::int32_t, std::int64_t, std::int32_t>;

    T1 const tpl1{1, 2, 3};
    T2 const tpl2{1, 2, 4};
    EXPECT_LT(tpl1, tpl2);
    EXPECT_LE(tpl1, tpl2);
    EXPECT_FALSE(tpl1 > tpl2);
    EXPECT_FALSE(tpl1 >= tpl2);
  }
}

TEST(tuple, size) {
  static_cast<void>(test_info_);

  EXPECT_EQ(0, (::portable_stl::tuple_size<::portable_stl::tuple<>>{}()));
  EXPECT_EQ(1, (::portable_stl::tuple_size<::portable_stl::tuple<std::int32_t>>{}()));
  EXPECT_EQ(::test_tuple_helper::val_2,
            (::portable_stl::tuple_size<::portable_stl::tuple<std::int32_t, std::int8_t>>{}()));
  EXPECT_EQ(::test_tuple_helper::val_3,
            (::portable_stl::tuple_size<::portable_stl::tuple<std::int32_t, std::int8_t, double>>{}()));
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::tuple_size<::portable_stl::tuple<>>;
    EXPECT_EQ(0, test_type{}());
  }
  {
    /**
     * @brief Test type.
     */
    using test_type = typename ::portable_stl::tuple_helper::tuple_size_wrapper<::portable_stl::tuple<>>::value;
    EXPECT_EQ(0, test_type{}());
  }
  {
    /**
     * @brief Test type.
     */
    using test_type = typename ::portable_stl::tuple_helper::tuple_size_wrapper<::portable_stl::tuple<> const>::value;
    EXPECT_EQ(0, test_type{}());
  }
  {
    /**
     * @brief Test type.
     */
    using test_type =
      typename ::portable_stl::tuple_helper::tuple_size_wrapper<::portable_stl::array<std::int32_t, 1>>::value;
    EXPECT_EQ(1, test_type{}());
  }
}

TEST(tuple, size_array) {
  static_cast<void>(test_info_);

  EXPECT_EQ(1, (::portable_stl::tuple_size<::portable_stl::array<std::int32_t, 1>>{}()));
  EXPECT_EQ(::test_tuple_helper::val_2,
            (::portable_stl::tuple_size<::portable_stl::array<std::int16_t, ::test_tuple_helper::val_2>>{}()));
  EXPECT_EQ(::test_tuple_helper::val_3,
            (::portable_stl::tuple_size<::portable_stl::array<std::int8_t, ::test_tuple_helper::val_3>>{}()));
  EXPECT_EQ(::test_tuple_helper::val_4,
            (::portable_stl::tuple_size<::portable_stl::array<double, ::test_tuple_helper::val_4>>{}()));
}

TEST(tuple, clang_case_1) {
  static_cast<void>(test_info_);
  { static_cast<void>(::portable_stl::tuple<std::int32_t &>(::portable_stl::tuple<std::int32_t &&>(1))); }
}

namespace test_tuple_helper {
class HasConstSwap final {};

static void swap(HasConstSwap const &lhv, HasConstSwap const &rhv) noexcept {
  static_cast<void>(lhv);
  static_cast<void>(rhv);
}
} // namespace test_tuple_helper

TEST(tuple, swap) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::tuple<>       tpl0;
    ::portable_stl::tuple<> const tpl1;
    tpl0.swap(tpl1);
    static_cast<void>(tpl0);
  }
  {
    ::portable_stl::tuple<> const tpl0;
    ::portable_stl::tuple<> const tpl1;
    tpl0.swap(tpl1);
    static_cast<void>(tpl0);
  }
  {
    ::portable_stl::tuple<test_tuple_helper::HasConstSwap> const tpl0;
    ::portable_stl::tuple<test_tuple_helper::HasConstSwap> const tpl1;
    tpl0.swap(tpl1);
    static_cast<void>(tpl0);
  }
  {
    ::portable_stl::tuple<test_tuple_helper::MoveOnly> tpl0{test_tuple_helper::MoveOnly(0)};
    ::portable_stl::tuple<test_tuple_helper::MoveOnly> tpl1{test_tuple_helper::MoveOnly(1)};

    tpl0.swap(tpl1);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl0));
    EXPECT_EQ(0, ::portable_stl::get<0>(tpl1));
  }
  {
    ::portable_stl::tuple<test_tuple_helper::MoveOnly, test_tuple_helper::MoveOnly> tpl0{
      test_tuple_helper::MoveOnly(0), test_tuple_helper::MoveOnly(1)};
    ::portable_stl::tuple<test_tuple_helper::MoveOnly, test_tuple_helper::MoveOnly> tpl1{
      test_tuple_helper::MoveOnly(1), test_tuple_helper::MoveOnly(0)};

    tpl0.swap(tpl1);

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl0));
    EXPECT_EQ(0, ::portable_stl::get<0>(tpl1));
    EXPECT_EQ(0, ::portable_stl::get<1>(tpl0));
    EXPECT_EQ(1, ::portable_stl::get<1>(tpl1));
  }
  {
    ::portable_stl::tuple<test_tuple_helper::MoveOnly, test_tuple_helper::MoveOnly, test_tuple_helper::MoveOnly> tpl0{
      test_tuple_helper::MoveOnly(0), test_tuple_helper::MoveOnly(1), test_tuple_helper::MoveOnly(0)};
    ::portable_stl::tuple<test_tuple_helper::MoveOnly, test_tuple_helper::MoveOnly, test_tuple_helper::MoveOnly> tpl1{
      test_tuple_helper::MoveOnly(1), test_tuple_helper::MoveOnly(0), test_tuple_helper::MoveOnly(1)};

    tpl0.swap(tpl1);

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl0));
    EXPECT_EQ(0, ::portable_stl::get<0>(tpl1));
    EXPECT_EQ(0, ::portable_stl::get<1>(tpl0));
    EXPECT_EQ(1, ::portable_stl::get<1>(tpl1));
    EXPECT_EQ(1, ::portable_stl::get<2>(tpl0));
    EXPECT_EQ(0, ::portable_stl::get<2>(tpl1));
  }
}

TEST(tuple, helper_types) {
  static_cast<void>(test_info_);
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::tuple_helper::tuple_like<std::int32_t>;
    EXPECT_FALSE(test_type{}());
  }
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::tuple_helper::tuple_like<::portable_stl::array<std::int32_t, 2>>;
    EXPECT_TRUE(test_type{}());
  }
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::tuple_helper::tuple_like<::portable_stl::tuple<std::int32_t, bool>>;
    EXPECT_TRUE(test_type{}());
  }

  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::tuple_helper::make_tuple_unref_wrap_t<std::int32_t>;
    EXPECT_TRUE((std::is_same<test_type, std::int32_t>{}));
  }
  {
    /**
     * @brief Test type.
     */
    using test_type
      = ::portable_stl::tuple_helper::make_tuple_unref_wrap_t<::portable_stl::reference_wrapper<std::int32_t>>;
    EXPECT_TRUE((std::is_same<test_type, std::int32_t &>{}));
  }
}
