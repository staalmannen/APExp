// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_element.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <complex>
#include <string>

#include "portable_stl/array/array.h"
#include "portable_stl/utility/tuple/tuple.h"
#include "tuple_test_helper.h"

namespace test_tuple_helper {
/**
 * @brief Helper to test tuple_element
 *
 * @tparam t_type
 * @tparam t_idx
 * @tparam t_expected_type
 */
template<class t_type, ::portable_stl::size_t t_idx, class t_expected_type> static void test_element() {
  // clang-format off
  EXPECT_TRUE((std::is_same<typename ::portable_stl::tuple_element<t_idx, t_type>::type, t_expected_type>{}));
  EXPECT_TRUE((std::is_same<typename ::portable_stl::tuple_element<t_idx, const t_type>::type, const t_expected_type>{}));
  EXPECT_TRUE((std::is_same<typename ::portable_stl::tuple_element<t_idx, volatile t_type>::type, volatile t_expected_type>{}));
  EXPECT_TRUE((std::is_same<typename ::portable_stl::tuple_element<t_idx, const volatile t_type>::type, const volatile t_expected_type>{}));
  EXPECT_TRUE((std::is_same<typename ::portable_stl::tuple_element_t<t_idx, t_type>, t_expected_type>{}));
  EXPECT_TRUE((std::is_same<typename ::portable_stl::tuple_element_t<t_idx, const t_type>, const t_expected_type>{}));
  EXPECT_TRUE((std::is_same<typename ::portable_stl::tuple_element_t<t_idx, volatile t_type>, volatile t_expected_type>{}));
  EXPECT_TRUE((std::is_same<typename ::portable_stl::tuple_element_t<t_idx, const volatile t_type>, const volatile t_expected_type>{}));
  // clang-format on
}
} // namespace test_tuple_helper

TEST(tuple, element) {
  static_cast<void>(test_info_);

  test_tuple_helper::test_element<::portable_stl::tuple<std::int32_t>, 0, std::int32_t>();
  test_tuple_helper::test_element<::portable_stl::tuple<double, std::int32_t>, 0, double>();
  test_tuple_helper::test_element<::portable_stl::tuple<double, std::int32_t>, 1, std::int32_t>();
  test_tuple_helper::test_element<::portable_stl::tuple<std::int32_t *, double, std::int32_t>, 0, std::int32_t *>();
  test_tuple_helper::test_element<::portable_stl::tuple<std::int32_t *, double, std::int32_t>, 1, double>();
  test_tuple_helper::test_element<::portable_stl::tuple<std::int32_t *, double, std::int32_t>, 2, std::int32_t>();
}

TEST(tuple, element_array) {
  static_cast<void>(test_info_);
  test_tuple_helper::test_element<::portable_stl::array<std::int32_t, 5>, 0, std::int32_t>();
  test_tuple_helper::test_element<::portable_stl::array<std::int32_t, 5>, 1, std::int32_t>();
  test_tuple_helper::test_element<::portable_stl::array<std::int8_t const *, 4>, 3, std::int8_t const *>();
  test_tuple_helper::test_element<::portable_stl::array<std::int32_t volatile, 4>, 3, std::int32_t volatile>();
  test_tuple_helper::test_element<::portable_stl::array<std::int8_t *, 3>, 1, std::int8_t *>();
  test_tuple_helper::test_element<::portable_stl::array<std::int8_t *, 3>, 2, std::int8_t *>();
}

namespace test_tuple_helper {

/**
 * @brief Test class.
 */
class Empty_test_element final {};

/**
 * @brief complex test class.
 */
class Element_test_class final {
public:
  /**
   * @brief
   */
  ::portable_stl::tuple<std::int32_t, Empty_test_element> m_internal_tuple;
  /**
   * @brief
   */
  std::int32_t                                            m_k;
  /**
   * @brief
   */
  Empty_test_element                                      m_e;
  /**
   * @brief Construct a new Element_test_class object
   */
  Element_test_class()
      : m_internal_tuple{1, Empty_test_element{}}
      , m_k(::portable_stl::get<0>(m_internal_tuple))
      , m_e(::portable_stl::get<1>(m_internal_tuple)) {
  }
};

/**
 * @brief
 * @return ::portable_stl::tuple<std::int32_t, std::int32_t>
 */
static ::portable_stl::tuple<std::int32_t, std::int32_t> getP() {
  return ::portable_stl::tuple<std::int32_t, std::int32_t>{0, 1};
}

} // namespace test_tuple_helper

TEST(tuple, get_non_const) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::tuple<std::int32_t> tpl{1};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));

    ::portable_stl::get<0>(tpl) = 0;
    EXPECT_EQ(0, ::portable_stl::get<0>(tpl));
  }
  {
    ::portable_stl::tuple<std::string, std::int32_t> tpl{"one", 1};

    EXPECT_EQ("one", ::portable_stl::get<0>(tpl));
    EXPECT_EQ(1, ::portable_stl::get<1>(tpl));

    ::portable_stl::get<0>(tpl) = "zero";
    ::portable_stl::get<1>(tpl) = 0;
    EXPECT_EQ("zero", ::portable_stl::get<0>(tpl));
    EXPECT_EQ(0, ::portable_stl::get<1>(tpl));
  }
  {
    double                                                     dbl_value{1.5};
    ::portable_stl::tuple<double &, std::string, std::int32_t> tpl{dbl_value, "zero", 0};

    EXPECT_EQ(1.5, ::portable_stl::get<0>(tpl));
    EXPECT_EQ("zero", ::portable_stl::get<1>(tpl));
    EXPECT_EQ(0, ::portable_stl::get<2>(tpl));

    ::portable_stl::get<0>(tpl) = 2.5;
    ::portable_stl::get<1>(tpl) = "one";
    ::portable_stl::get<2>(tpl) = 1;

    EXPECT_EQ(2.5, dbl_value);
    EXPECT_EQ(2.5, ::portable_stl::get<0>(tpl));
    EXPECT_EQ("one", ::portable_stl::get<1>(tpl));
    EXPECT_EQ(1, ::portable_stl::get<2>(tpl));
  }
  // get on an rvalue tuple
  {
    EXPECT_EQ(0, ::portable_stl::get<0>(::portable_stl::make_tuple(0.0, 1, 2.0, 3L)));
    EXPECT_EQ(1, ::portable_stl::get<1>(::portable_stl::make_tuple(0.0, 1, 2.0, 3L)));
    EXPECT_EQ(::test_tuple_helper::val_2,
              ::portable_stl::get<::test_tuple_helper::val_2>(::portable_stl::make_tuple(0.0, 1, 2.0, 3L)));
    EXPECT_EQ(::test_tuple_helper::val_3,
              ::portable_stl::get<::test_tuple_helper::val_3>(::portable_stl::make_tuple(0.0, 1, 2.0, 3L)));

    EXPECT_EQ(1, test_tuple_helper::Element_test_class().m_k);
    EXPECT_EQ(1, ::portable_stl::get<1>(test_tuple_helper::getP()));
  }
}

TEST(tuple, get_const) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::tuple<std::int32_t> const tpl{1};

    EXPECT_EQ(1, ::portable_stl::get<0>(tpl));
  }
  {
    ::portable_stl::tuple<std::string, std::int32_t> const tpl{"one", 1};

    EXPECT_EQ("one", ::portable_stl::get<0>(tpl));
    EXPECT_EQ(1, ::portable_stl::get<1>(tpl));
  }
  {
    double                                                           dbl_value{1.5};
    ::portable_stl::tuple<double &, std::string, std::int32_t> const tpl{dbl_value, "zero", 0};

    EXPECT_EQ(1.5, ::portable_stl::get<0>(tpl));
    EXPECT_EQ("zero", ::portable_stl::get<1>(tpl));
    EXPECT_EQ(0, ::portable_stl::get<::test_tuple_helper::val_2>(tpl));

    ::portable_stl::get<0>(tpl) = 2.5;

    EXPECT_EQ(2.5, dbl_value);                   // first tuple type is ref, so ignore tuple constness !!!
    EXPECT_EQ(2.5, ::portable_stl::get<0>(tpl)); // first tuple type is ref, so ignore tuple constness !!!
    EXPECT_EQ("zero", ::portable_stl::get<1>(tpl));
    EXPECT_EQ(0, ::portable_stl::get<::test_tuple_helper::val_2>(tpl));
  }
  {
    test_tuple_helper::test_element<::portable_stl::tuple<std::int32_t> const, 0, std::int32_t const>();
    test_tuple_helper::test_element<::portable_stl::tuple<double, std::int32_t> const, 0, double const>();
    test_tuple_helper::test_element<::portable_stl::tuple<double, std::int32_t> const, 1, std::int32_t const>();
    test_tuple_helper::
      test_element<::portable_stl::tuple<std::int32_t *, double, std::int32_t> const, 0, std::int32_t *const>();
    test_tuple_helper::
      test_element<::portable_stl::tuple<std::int32_t *, double, std::int32_t> const, 1, double const>();
    test_tuple_helper::test_element<::portable_stl::tuple<std::int32_t *, double, std::int32_t> const,
                                    ::test_tuple_helper::val_2,
                                    std::int32_t const>();
  }
}

TEST(tuple, get_rv) {
  static_cast<void>(test_info_);

  ::portable_stl::tuple<std::unique_ptr<std::int32_t>> tpl{std::make_unique<std::int32_t>(1)};
  std::unique_ptr<std::int32_t>                        ptr{::portable_stl::get<0>(std::move(tpl))};
  EXPECT_EQ(1, *ptr);
}

TEST(tuple, get_const_rv) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::tuple<std::int32_t> const tpl{1};
    EXPECT_TRUE((std::is_same<std::int32_t const &&, decltype(::portable_stl::get<0>(std::move(tpl)))>{}));
    EXPECT_TRUE(noexcept(::portable_stl::get<0>(std::move(tpl))));

    std::int32_t const &&value_rv{::portable_stl::get<0>(std::move(tpl))};
    EXPECT_EQ(1, value_rv);
  }
  {
    ::portable_stl::tuple<std::string, std::int32_t> const tpl{"one", 1};
    EXPECT_TRUE((std::is_same<std::string const &&, decltype(::portable_stl::get<0>(std::move(tpl)))>{}));
    EXPECT_TRUE(noexcept(::portable_stl::get<0>(std::move(tpl))));
    EXPECT_TRUE((std::is_same<std::int32_t const &&, decltype(::portable_stl::get<1>(std::move(tpl)))>{}));
    EXPECT_TRUE(noexcept(::portable_stl::get<1>(std::move(tpl))));

    std::string const  &&string_rv{::portable_stl::get<0>(std::move(tpl))};
    std::int32_t const &&value_rv{::portable_stl::get<1>(std::move(tpl))};
    EXPECT_EQ("one", string_rv);
    EXPECT_EQ(1, value_rv);
  }
  {
    std::int32_t       value1{0};
    std::int32_t const value2{1};

    ::portable_stl::tuple<std::int32_t &, std::int32_t const &> const tpl{value1, value2};
    EXPECT_TRUE((std::is_same<std::int32_t &, decltype(::portable_stl::get<0>(std::move(tpl)))>{}));
    EXPECT_TRUE(noexcept(::portable_stl::get<0>(std::move(tpl))));
    EXPECT_TRUE((std::is_same<std::int32_t const &, decltype(::portable_stl::get<1>(std::move(tpl)))>{}));
    EXPECT_TRUE(noexcept(::portable_stl::get<1>(std::move(tpl))));
  }
  {
    std::int32_t       value1{0};
    std::int32_t const value2{1};

    ::portable_stl::tuple<std::int32_t &&, std::int32_t const &&> const tpl{std::move(value1), std::move(value2)};
    EXPECT_TRUE((std::is_same<std::int32_t &&, decltype(::portable_stl::get<0>(std::move(tpl)))>{}));
    EXPECT_TRUE(noexcept(::portable_stl::get<0>(std::move(tpl))));
    EXPECT_TRUE((std::is_same<std::int32_t const &&, decltype(::portable_stl::get<1>(std::move(tpl)))>{}));
    EXPECT_TRUE(noexcept(::portable_stl::get<1>(std::move(tpl))));
  }
}

TEST(tuple, get_by_type) {
  static_cast<void>(test_info_);
  /**
   * @brief Complex type.
   */
  using complex_type = std::complex<double>;
  {
    auto tpl = ::portable_stl::tuple<std::int32_t, std::string, complex_type>{
      1, "Hi", {0, 1}
    };
    EXPECT_EQ(1, ::portable_stl::get<std::int32_t>(tpl));
    EXPECT_EQ("Hi", ::portable_stl::get<std::string>(tpl));
    EXPECT_EQ(0, ::portable_stl::get<complex_type>(tpl).real());
    EXPECT_EQ(1, ::portable_stl::get<complex_type>(tpl).imag());
  }
  {
    auto tpl = ::portable_stl::tuple<std::int32_t, std::string, std::int32_t, complex_type>{
      1, "Hi", 0, {0.0, 1.0}
    };
    // EXPECT _ EQ (1 , ::portable_stl :: get < std :: int32_t > ( tpl ) ) ; will fail
    EXPECT_EQ("Hi", ::portable_stl::get<std::string>(tpl));
    EXPECT_TRUE((complex_type{0, 1} == ::portable_stl::get<complex_type>(tpl)));
  }
  {
    auto tpl = ::portable_stl::tuple<std::int32_t, double, std::int32_t const, double>{0, 1.0, 1, 2.0};
    EXPECT_EQ(0, ::portable_stl::get<std::int32_t>(tpl));
    EXPECT_EQ(1, ::portable_stl::get<std::int32_t const>(tpl));
  }
  {
    ::portable_stl::tuple<std::int32_t, double, std::int32_t const, double> const tpl{0, 1.0, 1, 2.0};
    std::int32_t const &cref1{::portable_stl::get<std::int32_t>(tpl)};
    std::int32_t const &cref2{::portable_stl::get<std::int32_t const>(tpl)};
    EXPECT_EQ(0, cref1);
    EXPECT_EQ(1, cref2);
  }
  {
    /**
     * @brief Smart pointer to int type.
     */
    using t_uptr = std::unique_ptr<std::int32_t>;
    ::portable_stl::tuple<t_uptr> tpl{std::make_unique<std::int32_t>(1)};
    t_uptr                        ptr{::portable_stl::get<t_uptr>(std::move(tpl))}; // get rvalue
    EXPECT_EQ(1, *ptr);
    EXPECT_EQ(nullptr, ::portable_stl::get<t_uptr>(tpl));
  }
  {
    /**
     * @brief Smart pointer to int type.
     */
    using t_uptr = std::unique_ptr<std::int32_t>;
    ::portable_stl::tuple<t_uptr> tpl{std::make_unique<std::int32_t>(1)};
    t_uptr const                &&ptr{::portable_stl::get<t_uptr>(std::move(tpl))}; // get const rvalue
    EXPECT_EQ(1, *ptr);
    EXPECT_NE(nullptr, ::portable_stl::get<t_uptr>(tpl));
  }
  {
    std::int32_t                                                      value1{0};
    std::int32_t                                                      value2{1};
    ::portable_stl::tuple<std::int32_t &, std::int32_t const &> const tpl{value1, value2};

    EXPECT_TRUE((std::is_same<std::int32_t &, decltype(::portable_stl::get<std::int32_t &>(std::move(tpl)))>{}));
    EXPECT_TRUE((noexcept(::portable_stl::get<std::int32_t &>(std::move(tpl)))));

    EXPECT_TRUE(
      (std::is_same<std::int32_t const &, decltype(::portable_stl::get<std::int32_t const &>(std::move(tpl)))>{}));
    EXPECT_TRUE((noexcept(::portable_stl::get<std::int32_t const &>(std::move(tpl)))));
  }
  {
    std::int32_t                                                        value1{0};
    std::int32_t                                                        value2{1};
    ::portable_stl::tuple<std::int32_t &&, std::int32_t const &&> const tpl{std::move(value1), std::move(value2)};

    EXPECT_TRUE((std::is_same<std::int32_t &&, decltype(::portable_stl::get<std::int32_t &&>(std::move(tpl)))>{}));
    EXPECT_TRUE((noexcept(::portable_stl::get<std::int32_t &&>(std::move(tpl)))));

    EXPECT_TRUE(
      (std::is_same<std::int32_t const &&, decltype(::portable_stl::get<std::int32_t const &&>(std::move(tpl)))>{}));
    EXPECT_TRUE((noexcept(::portable_stl::get<std::int32_t const &&>(std::move(tpl)))));
  }
}
