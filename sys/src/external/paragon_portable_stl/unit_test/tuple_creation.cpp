// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_creation.cpp"
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
#include "portable_stl/utility/tuple/tuple_cat.h"
#include "tuple_test_helper.h"

#if defined(__cpp_deduction_guides)
#  include "tuple_deduction_guide.h"
#else
#  include "tuple_no_deduction_guide.h"
#endif

TEST(tuple, make_tuple) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::tuple<std::int32_t, std::int32_t, double> tpl{::portable_stl::make_tuple(0, 1, 1.0)};
    std::int32_t                                              i1{::portable_stl::get<1>(tpl)};
    double                                                    d1{::portable_stl::get<2>(tpl)};

    EXPECT_EQ(1, i1);
    EXPECT_EQ(1.0, d1);
  }
  {
    std::int32_t                                                  i_value{0};
    double                                                        j_value{0.0};
    ::portable_stl::tuple<std::int32_t, std::int32_t &, double &> tpl{
      ::portable_stl::make_tuple(1, portable_stl::ref(i_value), ::portable_stl::ref(j_value))};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
    EXPECT_EQ(0, ::portable_stl::get<1>(tpl));
    EXPECT_EQ(0.0, ::portable_stl::get<2>(tpl));

    i_value = 1;
    j_value = 1.0;
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
    EXPECT_EQ(1, ::portable_stl::get<1>(tpl));
    EXPECT_EQ(1.0, ::portable_stl::get<2>(tpl));

    ::portable_stl::get<1>(tpl) = 0;
    ::portable_stl::get<2>(tpl) = 0.0;
    EXPECT_EQ(0, i_value);
    EXPECT_EQ(0.0, j_value);
  }
}

TEST(tuple, tie) {
  static_cast<void>(test_info_);

  {
    std::int32_t i_value{1};
    double       f_value{1.1};

    /**
     * @brief Excpected type.
     */
    using ExpectT = ::portable_stl::tuple<std::int32_t &, decltype(::portable_stl::ignore) &, double &>;
    auto res      = ::portable_stl::tie(i_value, ::portable_stl::ignore, f_value);

    EXPECT_TRUE((std::is_same<ExpectT, decltype(res)>{}));

    EXPECT_EQ(&i_value, &::portable_stl::get<0>(res));
    EXPECT_EQ(&::portable_stl::ignore, &::portable_stl::get<1>(res));
    EXPECT_EQ(&f_value, &::portable_stl::get<2>(res));

    res = ::portable_stl::make_tuple(1, nullptr, 1.0);
    EXPECT_EQ(1, i_value);
    EXPECT_EQ(1, f_value);
  }
  {
    std::int32_t i_value{0};
    std::string  s_value;
    ::portable_stl::tie(i_value, ::portable_stl::ignore, s_value) = ::portable_stl::make_tuple(1, 0.0, "C++");
    EXPECT_EQ(1, i_value);
    EXPECT_EQ("C++", s_value);
  }
}

namespace test_tuple_helper {
/**
 * @brief No params
 * @tparam t_tuple
 */
template<class t_tuple> static void forward_as_tuple_test0(t_tuple const &) {
  EXPECT_EQ(0, ::portable_stl::tuple_size<t_tuple>{}());
}

/**
 * @brief One rvalue param
 * @tparam t_tuple
 * @param tpl Forward tuple.
 */
template<class t_tuple> static void forward_as_tuple_testpl1a(t_tuple const &tpl) {
  EXPECT_EQ(1, ::portable_stl::tuple_size<t_tuple>{}());
  EXPECT_TRUE((std::is_same<std::int32_t &&, typename ::portable_stl::tuple_element<0, t_tuple>::type>{}));
  EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
}

/**
 * @brief One lvalue param
 * @tparam t_tuple
 * @param tpl Forward tuple.
 */
template<class t_tuple> static void forward_as_tuple_testpl1b(t_tuple const &tpl) {
  EXPECT_EQ(1, ::portable_stl::tuple_size<t_tuple>{}());
  EXPECT_TRUE((std::is_same<std::int32_t &, typename ::portable_stl::tuple_element<0, t_tuple>::type>{}));
  EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
}

/**
 * @brief Two params.
 * @tparam t_tuple
 * @param tpl Forward tuple.
 */
template<class t_tuple> static void forward_as_tuple_testpl2(t_tuple const &tpl) {
  EXPECT_EQ(::test_tuple_helper::val_2, ::portable_stl::tuple_size<t_tuple>{}());
  EXPECT_TRUE((std::is_same<double &, typename ::portable_stl::tuple_element<0, t_tuple>::type>{}));
  EXPECT_TRUE((std::is_same<std::int8_t &, typename ::portable_stl::tuple_element<1, t_tuple>::type>{}));
  EXPECT_EQ(1.0, ::portable_stl::get<0>(tpl));
  EXPECT_EQ('a', ::portable_stl::get<1>(tpl));
}
} // namespace test_tuple_helper

TEST(tuple, forward_as_tuple) {
  static_cast<void>(test_info_);

  test_tuple_helper::forward_as_tuple_test0(::portable_stl::forward_as_tuple());
  test_tuple_helper::forward_as_tuple_testpl1a(::portable_stl::forward_as_tuple(1));
  {
    std::int32_t lvalue{1};
    test_tuple_helper::forward_as_tuple_testpl1b(::portable_stl::forward_as_tuple(lvalue));
  }
  {
    double      lvalue_double{1.0};
    std::int8_t lvalue_char = 'a';
    test_tuple_helper::forward_as_tuple_testpl2(::portable_stl::forward_as_tuple(lvalue_double, lvalue_char));
  }
}

namespace test_tuple_helper {
namespace NS {
  /**
   * @brief
   */
  class Namespaced final {
  public:
    /**
     * @brief Data.
     */
    std::int32_t m_value;
  };
  /**
   * @brief
   * @tparam Ts
   */
  template<typename... Ts> void forward_as_tuple(Ts...) = delete;
} // namespace NS
} // namespace test_tuple_helper

TEST(tuple, tuple_cat) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::tuple<> const tpl{::portable_stl::tuple_cat()};
    static_cast<void>(tpl);
  }
  {
    ::portable_stl::tuple<> const tpl1;
    ::portable_stl::tuple<> const tpl2{::portable_stl::tuple_cat(tpl1)};
    static_cast<void>(tpl1);
    static_cast<void>(tpl2);
  }
  {
    ::portable_stl::tuple<> const tpl{::portable_stl::tuple_cat(::portable_stl::tuple<>())};
    static_cast<void>(tpl);
  }
  {
    ::portable_stl::tuple<> const tpl{::portable_stl::tuple_cat(::portable_stl::array<std::int32_t, 0>())};
    static_cast<void>(tpl);
  }
  {
    ::portable_stl::tuple<std::int32_t> tpl1{1};
    ::portable_stl::tuple<std::int32_t> tpl{::portable_stl::tuple_cat(tpl1)};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
  }
  {
    ::portable_stl::tuple<std::int32_t, test_tuple_helper::MoveOnly> tpl{
      ::portable_stl::tuple_cat(::portable_stl::tuple<std::int32_t, test_tuple_helper::MoveOnly>(0, 1))};

    EXPECT_EQ(0, ::portable_stl::get<0>(tpl));
    EXPECT_EQ(1, ::portable_stl::get<1>(tpl));
  }
  {
    ::portable_stl::tuple<std::int32_t, std::int32_t, std::int32_t> tpl{
      ::portable_stl::tuple_cat(::portable_stl::array<std::int32_t, 3>())};

    EXPECT_EQ(0, ::portable_stl::get<0>(tpl));
    EXPECT_EQ(0, ::portable_stl::get<1>(tpl));
    EXPECT_EQ(0, ::portable_stl::get<2>(tpl));
  }
  {
    ::portable_stl::tuple<> const tpl1;
    ::portable_stl::tuple<> const tpl2;

    ::portable_stl::tuple<> const tpl3{::portable_stl::tuple_cat(tpl1, tpl2)};
    static_cast<void>(tpl1);
    static_cast<void>(tpl2);
    static_cast<void>(tpl3);
  }
  {
    ::portable_stl::tuple<>             tpl1;
    ::portable_stl::tuple<std::int32_t> tpl2{1};

    ::portable_stl::tuple<std::int32_t> tpl3{::portable_stl::tuple_cat(tpl1, tpl2)};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl3));
  }
  {
    ::portable_stl::tuple<>             tpl1;
    ::portable_stl::tuple<std::int32_t> tpl2{1};

    ::portable_stl::tuple<std::int32_t> tpl3{::portable_stl::tuple_cat(tpl2, tpl1)};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl3));
  }
  {
    ::portable_stl::tuple<std::int32_t *> tpl1;
    ::portable_stl::tuple<std::int32_t>   tpl2{1};

    ::portable_stl::tuple<std::int32_t *, std::int32_t> tpl3{::portable_stl::tuple_cat(tpl1, tpl2)};

    EXPECT_EQ(nullptr, ::portable_stl::get<0>(tpl3));
    EXPECT_EQ(1, ::portable_stl::get<1>(tpl3));
  }
  {
    ::portable_stl::tuple<std::int32_t *> tpl1;
    ::portable_stl::tuple<std::int32_t>   tpl2{1};

    ::portable_stl::tuple<std::int32_t, std::int32_t *> tpl3{::portable_stl::tuple_cat(tpl2, tpl1)};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl3));
    EXPECT_EQ(nullptr, ::portable_stl::get<1>(tpl3));
  }
  {
    ::portable_stl::tuple<std::int32_t *>       tpl1;
    ::portable_stl::tuple<std::int32_t, double> tpl2{1, 1.1};

    ::portable_stl::tuple<std::int32_t *, std::int32_t, double> tpl3{::portable_stl::tuple_cat(tpl1, tpl2)};

    EXPECT_EQ(nullptr, ::portable_stl::get<0>(tpl3));
    EXPECT_EQ(1, ::portable_stl::get<1>(tpl3));
    EXPECT_EQ(1.1, ::portable_stl::get<2>(tpl3));
  }
  {
    ::portable_stl::tuple<std::int32_t *>       tpl1;
    ::portable_stl::tuple<std::int32_t, double> tpl2{1, 1.1};

    ::portable_stl::tuple<std::int32_t, double, std::int32_t *> tpl3{::portable_stl::tuple_cat(tpl2, tpl1)};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl3));
    EXPECT_EQ(1.1, ::portable_stl::get<1>(tpl3));
    EXPECT_EQ(nullptr, ::portable_stl::get<2>(tpl3));
  }
  {
    ::portable_stl::tuple<std::int32_t *, test_tuple_helper::MoveOnly> tpl1{nullptr, 1};
    ::portable_stl::tuple<std::int32_t, double>                        tpl2{0, 1.1};

    ::portable_stl::tuple<std::int32_t *, test_tuple_helper::MoveOnly, std::int32_t, double> tpl3{
      ::portable_stl::tuple_cat(std::move(tpl1), tpl2)};

    EXPECT_EQ(nullptr, ::portable_stl::get<0>(tpl3));
    EXPECT_EQ(1, ::portable_stl::get<1>(tpl3));
    EXPECT_EQ(0, ::portable_stl::get<2>(tpl3));
    EXPECT_EQ(1.1, ::portable_stl::get<3>(tpl3));
  }
  {
    ::portable_stl::tuple<std::int32_t *, test_tuple_helper::MoveOnly> tpl1{nullptr, 1};
    ::portable_stl::tuple<std::int32_t, double>                        tpl2{0, 1.1};

    ::portable_stl::tuple<std::int32_t, double, std::int32_t *, test_tuple_helper::MoveOnly> tpl3{
      ::portable_stl::tuple_cat(tpl2, std::move(tpl1))};

    EXPECT_EQ(0, ::portable_stl::get<0>(tpl3));
    EXPECT_EQ(1.1, ::portable_stl::get<1>(tpl3));
    EXPECT_EQ(nullptr, ::portable_stl::get<2>(tpl3));
    EXPECT_EQ(1, ::portable_stl::get<3>(tpl3));
  }
  {
    ::portable_stl::tuple<test_tuple_helper::MoveOnly, test_tuple_helper::MoveOnly> tpl1{1, 0};
    ::portable_stl::tuple<std::int32_t *, test_tuple_helper::MoveOnly>              tpl2{nullptr, 1};

    ::portable_stl::
      tuple<test_tuple_helper::MoveOnly, test_tuple_helper::MoveOnly, std::int32_t *, test_tuple_helper::MoveOnly>
        tpl3{::portable_stl::tuple_cat(std::move(tpl1), std::move(tpl2))};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl3));
    EXPECT_EQ(0, ::portable_stl::get<1>(tpl3));
    EXPECT_EQ(nullptr, ::portable_stl::get<2>(tpl3));
    EXPECT_EQ(1, ::portable_stl::get<3>(tpl3));
  }

  {
    ::portable_stl::tuple<test_tuple_helper::MoveOnly, test_tuple_helper::MoveOnly> tpl1{1, 0};
    ::portable_stl::tuple<std::int32_t *, test_tuple_helper::MoveOnly>              tpl2{nullptr, 1};

    ::portable_stl::
      tuple<test_tuple_helper::MoveOnly, test_tuple_helper::MoveOnly, std::int32_t *, test_tuple_helper::MoveOnly>
        tpl3{::portable_stl::tuple_cat(::portable_stl::tuple<>(), std::move(tpl1), std::move(tpl2))};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl3));
    EXPECT_EQ(0, ::portable_stl::get<1>(tpl3));
    EXPECT_EQ(nullptr, ::portable_stl::get<2>(tpl3));
    EXPECT_EQ(1, ::portable_stl::get<3>(tpl3));
  }
  {
    ::portable_stl::tuple<test_tuple_helper::MoveOnly, test_tuple_helper::MoveOnly> tpl1{1, 0};
    ::portable_stl::tuple<std::int32_t *, test_tuple_helper::MoveOnly>              tpl2{nullptr, 1};

    ::portable_stl::
      tuple<test_tuple_helper::MoveOnly, test_tuple_helper::MoveOnly, std::int32_t *, test_tuple_helper::MoveOnly>
        tpl3{::portable_stl::tuple_cat(std::move(tpl1), ::portable_stl::tuple<>(), std::move(tpl2))};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl3));
    EXPECT_EQ(0, ::portable_stl::get<1>(tpl3));
    EXPECT_EQ(nullptr, ::portable_stl::get<2>(tpl3));
    EXPECT_EQ(1, ::portable_stl::get<3>(tpl3));
  }
  {
    ::portable_stl::tuple<test_tuple_helper::MoveOnly, test_tuple_helper::MoveOnly> tpl1{1, 0};
    ::portable_stl::tuple<std::int32_t *, test_tuple_helper::MoveOnly>              tpl2{nullptr, 1};

    ::portable_stl::
      tuple<test_tuple_helper::MoveOnly, test_tuple_helper::MoveOnly, std::int32_t *, test_tuple_helper::MoveOnly>
        tpl3{::portable_stl::tuple_cat(std::move(tpl1), std::move(tpl2), ::portable_stl::tuple<>())};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl3));
    EXPECT_EQ(0, ::portable_stl::get<1>(tpl3));
    EXPECT_EQ(nullptr, ::portable_stl::get<2>(tpl3));
    EXPECT_EQ(1, ::portable_stl::get<3>(tpl3));
  }
  {
    ::portable_stl::tuple<test_tuple_helper::MoveOnly, test_tuple_helper::MoveOnly> tpl1{1, 0};
    ::portable_stl::tuple<std::int32_t *, test_tuple_helper::MoveOnly>              tpl2{nullptr, 1};

    ::portable_stl::tuple<test_tuple_helper::MoveOnly,
                          test_tuple_helper::MoveOnly,
                          std::int32_t *,
                          test_tuple_helper::MoveOnly,
                          std::int32_t>
      tpl3{::portable_stl::tuple_cat(std::move(tpl1), std::move(tpl2), ::portable_stl::tuple<std::int32_t>(1))};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl3));
    EXPECT_EQ(0, ::portable_stl::get<1>(tpl3));
    EXPECT_EQ(nullptr, ::portable_stl::get<2>(tpl3));
    EXPECT_EQ(1, ::portable_stl::get<3>(tpl3));
    EXPECT_EQ(1, ::portable_stl::get<3>(tpl3));
  }

  // See bug #19616.
  {
    auto tpl1 = ::portable_stl::tuple_cat(::portable_stl::make_tuple(::portable_stl::make_tuple(1)),
                                          ::portable_stl::make_tuple());
    EXPECT_EQ(::portable_stl::make_tuple(::portable_stl::make_tuple(1)), tpl1);

    auto tpl2 = ::portable_stl::tuple_cat(::portable_stl::make_tuple(::portable_stl::make_tuple(1)),
                                          ::portable_stl::make_tuple(::portable_stl::make_tuple(0)));
    EXPECT_EQ(::portable_stl::make_tuple(::portable_stl::make_tuple(1), ::portable_stl::make_tuple(0)), tpl2);
  }
  {
    std::int32_t x{1};

    ::portable_stl::tuple<std::int32_t, std::int32_t const, std::int32_t &, std::int32_t const &, std::int32_t &&> tpl{
      0, 1, x, x, std::move(x)};

    auto const &ct = tpl;

    ::portable_stl::tuple<std::int32_t, std::int32_t const, std::int32_t &, std::int32_t const &> tpl2{0, 1, x, x};

    auto const &ctpl2 = tpl2;

    auto result = ::portable_stl::tuple_cat(std::move(tpl), std::move(ct), tpl2, ctpl2);

    EXPECT_TRUE((std::is_same<decltype(result),
                              ::portable_stl::tuple<std::int32_t,
                                                    std::int32_t const,
                                                    std::int32_t &,
                                                    std::int32_t const &,
                                                    std::int32_t &&,
                                                    std::int32_t,
                                                    std::int32_t const,
                                                    std::int32_t &,
                                                    std::int32_t const &,
                                                    std::int32_t &&,
                                                    std::int32_t,
                                                    std::int32_t const,
                                                    std::int32_t &,
                                                    std::int32_t const &,
                                                    std::int32_t,
                                                    std::int32_t const,
                                                    std::int32_t &,
                                                    std::int32_t const &>>{}));
    static_cast<void>(result);
  }
  {
    ::portable_stl::tuple<test_tuple_helper::NS::Namespaced> tpl1{test_tuple_helper::NS::Namespaced{1}};
    ::portable_stl::tuple<test_tuple_helper::NS::Namespaced> tpl{::portable_stl::tuple_cat(tpl1)};

    ::portable_stl::tuple<test_tuple_helper::NS::Namespaced, test_tuple_helper::NS::Namespaced> tpl2{
      ::portable_stl::tuple_cat(tpl1, tpl1)};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl).m_value);
    EXPECT_EQ(1, ::portable_stl::get<0>(tpl2).m_value);
  }
}

TEST(tuple, deduction_guides_cpp17) {
  static_cast<void>(test_info_);

  test_tuple::tuple_deduction_guide();
}
