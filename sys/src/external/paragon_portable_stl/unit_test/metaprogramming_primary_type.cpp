// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_primary_type.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include <list>

#include "portable_stl/metaprogramming/primary_type/is_array.h"
#include "portable_stl/metaprogramming/primary_type/is_class.h"
#include "portable_stl/metaprogramming/primary_type/is_enum.h"
#include "portable_stl/metaprogramming/primary_type/is_floating_point.h"
#include "portable_stl/metaprogramming/primary_type/is_function.h"
#include "portable_stl/metaprogramming/primary_type/is_integral.h"
#include "portable_stl/metaprogramming/primary_type/is_lvalue_reference.h"
#include "portable_stl/metaprogramming/primary_type/is_member_function_pointer.h"
#include "portable_stl/metaprogramming/primary_type/is_member_object_pointer.h"
#include "portable_stl/metaprogramming/primary_type/is_null_pointer.h"
#include "portable_stl/metaprogramming/primary_type/is_pointer.h"
#include "portable_stl/metaprogramming/primary_type/is_rvalue_reference.h"
#include "portable_stl/metaprogramming/primary_type/is_union.h"
#include "portable_stl/metaprogramming/primary_type/is_void.h"

#if defined(__cpp_inline_variables)
#  include "metaprogramming_primary_type_inline_variables.h"
#else
#  include "metaprogramming_primary_type.h"
#endif

#if defined(__cpp_char8_t)
#  include "metaprogramming_primary_type_char8_t.h"
#else
#  include "metaprogramming_primary_type_no_char8_t.h"
#endif

TEST(metaprogramming_primary_type, is_void) {
  static_cast<void>(test_info_);
  ASSERT_TRUE((::portable_stl::is_void<void>{}()));
  ASSERT_TRUE((::portable_stl::is_void<void const>{}()));
  ASSERT_FALSE((::portable_stl::is_void<std::uint32_t>{}()));
  test_metaprogramming_primary_type::metaprogramming_primary_type_is_void_inline_variables();
}

TEST(metaprogramming_primary_type, is_null_pointer) {
  static_cast<void>(test_info_);
  ASSERT_TRUE((::portable_stl::is_null_pointer<decltype(nullptr)>{}()));
  ASSERT_TRUE((::portable_stl::is_null_pointer<::portable_stl::nullptr_t const>{}()));
  ASSERT_FALSE((::portable_stl::is_null_pointer<std::uint32_t>{}()));
  ASSERT_FALSE((::portable_stl::is_null_pointer<void>{}()));

  ::portable_stl::is_null_pointer<void> null_checker{};
  ASSERT_FALSE(null_checker());

  test_metaprogramming_primary_type::metaprogramming_primary_type_is_null_pointer_inline_variables();
}

TEST(metaprogramming_primary_type, is_integral) {
  static_cast<void>(test_info_);
  {
    constexpr ::portable_stl::is_integral<bool> checker_type{};
    ASSERT_TRUE((checker_type()));
    static_cast<void>(checker_type);
  }
  ASSERT_TRUE((::portable_stl::is_integral<bool>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<bool const>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<char>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<char const>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<wchar_t>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<wchar_t const>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<char16_t>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<char16_t const>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<char32_t>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<char32_t const>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<signed char>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<signed char const>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<unsigned char>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<unsigned char const>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<signed short int>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<signed short int const>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<unsigned short int>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<unsigned short int const>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<signed int>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<signed int const>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<unsigned int>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<unsigned int const>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<signed long int>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<signed long int const>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<unsigned long int>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<unsigned long int const>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<signed long long int>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<signed long long int const>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<unsigned long long int>{}()));
  ASSERT_TRUE((::portable_stl::is_integral<unsigned long long int const>{}()));
  ASSERT_FALSE((::portable_stl::is_integral<int *>{}()));
  ASSERT_FALSE((::portable_stl::is_integral<std::list<std::uint32_t>>{}()));
  ASSERT_FALSE((::portable_stl::is_integral<void>{}()));
  ASSERT_FALSE((::portable_stl::is_integral<float>{}()));
  ASSERT_FALSE((::portable_stl::is_integral<float const>{}()));
  ASSERT_FALSE((::portable_stl::is_integral<double>{}()));
  ASSERT_FALSE((::portable_stl::is_integral<double const>{}()));
  ASSERT_FALSE((::portable_stl::is_integral<long double>{}()));
  ASSERT_FALSE((::portable_stl::is_integral<long double const>{}()));

  test_metaprogramming_primary_type::metaprogramming_primary_type_is_integral_inline_variables();
  test_metaprogramming_primary_type::metaprogramming_primary_type_is_integral_char8_t();
}

TEST(metaprogramming_primary_type, is_floating_point) {
  static_cast<void>(test_info_);
  {
    constexpr ::portable_stl::is_floating_point<float> checker_type{};
    ASSERT_TRUE((checker_type()));
    static_cast<void>(checker_type);
  }
  ASSERT_TRUE((::portable_stl::is_floating_point<float>{}()));
  ASSERT_TRUE((::portable_stl::is_floating_point<float const>{}()));
  ASSERT_TRUE((::portable_stl::is_floating_point<double>{}()));
  ASSERT_TRUE((::portable_stl::is_floating_point<double const>{}()));
  ASSERT_TRUE((::portable_stl::is_floating_point<long double>{}()));
  ASSERT_TRUE((::portable_stl::is_floating_point<long double const>{}()));
  ASSERT_FALSE((::portable_stl::is_floating_point<int>{}()));
  ASSERT_FALSE((::portable_stl::is_floating_point<int *>{}()));
  ASSERT_FALSE((::portable_stl::is_floating_point<std::list<std::uint32_t>>{}()));
  ASSERT_FALSE((::portable_stl::is_floating_point<void>{}()));
  test_metaprogramming_primary_type::metaprogramming_primary_type_is_floating_point_inline_variables();
}

TEST(metaprogramming_primary_type, is_array) {
  static_cast<void>(test_info_);
  {
    constexpr ::portable_stl::is_array<std::uint32_t> checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }
  {
    constexpr ::portable_stl::is_array<std::uint32_t[]> checker_type{};
    ASSERT_TRUE((checker_type()));
    static_cast<void>(checker_type);
  }
  {
    constexpr ::portable_stl::is_array<std::uint32_t[1]> checker_type{};
    ASSERT_TRUE((checker_type()));
    static_cast<void>(checker_type);
  }
  ASSERT_TRUE((::portable_stl::is_array<std::uint32_t[]>{}()));
  ASSERT_TRUE((::portable_stl::is_array<std::uint32_t const[]>{}()));
  {
    /**
     * @brief Test type for check array
     *
     */
    using test_type = std::uint32_t const[];
    ASSERT_TRUE((::portable_stl::is_array<test_type const>{}()));
  }
  ASSERT_TRUE((::portable_stl::is_array<std::uint32_t[10]>{}()));
  ASSERT_TRUE((::portable_stl::is_array<std::uint32_t const[10]>{}()));
  {
    /**
     * @brief Test type for check array
     *
     */
    using test_type = std::uint32_t const[10];
    ASSERT_TRUE((::portable_stl::is_array<test_type const>{}()));
  }
  ASSERT_FALSE((::portable_stl::is_array<std::uint32_t>{}()));
  ASSERT_FALSE((::portable_stl::is_array<std::uint32_t const>{}()));
  test_metaprogramming_primary_type::metaprogramming_primary_type_is_array_inline_variables();
}

TEST(metaprogramming_primary_type, is_pointer) {
  static_cast<void>(test_info_);
  {
    constexpr ::portable_stl::is_pointer<std::uint32_t> checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }
  {
    constexpr ::portable_stl::is_pointer<void *> checker_type{};
    ASSERT_TRUE((checker_type()));
    static_cast<void>(checker_type);
  }
  ASSERT_TRUE((::portable_stl::is_pointer<void *>{}()));
  ASSERT_TRUE((::portable_stl::is_pointer<void *const>{}()));
  ASSERT_TRUE((::portable_stl::is_pointer<void const *>{}()));
  ASSERT_TRUE((::portable_stl::is_pointer<void const *const>{}()));
  ASSERT_TRUE(
    (::portable_stl::is_pointer<
      decltype(&test_metaprogramming_primary_type::metaprogramming_primary_type_is_pointer_inline_variables)>{}()));
  ASSERT_FALSE((::portable_stl::is_pointer<std::uint32_t>{}()));
  ASSERT_FALSE((::portable_stl::is_pointer<std::uint32_t const>{}()));
  test_metaprogramming_primary_type::metaprogramming_primary_type_is_pointer_inline_variables();
}

TEST(metaprogramming_primary_type, is_lvalue_reference) {
  static_cast<void>(test_info_);
  {
    constexpr ::portable_stl::is_lvalue_reference<std::uint32_t &&> checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }
  {
    constexpr ::portable_stl::is_lvalue_reference<std::uint32_t &> checker_type{};
    ASSERT_TRUE((checker_type()));
    static_cast<void>(checker_type);
  }

  ASSERT_TRUE((::portable_stl::is_lvalue_reference<std::uint32_t &>{}()));
  ASSERT_TRUE((::portable_stl::is_lvalue_reference<std::uint32_t const &>{}()));
  ASSERT_FALSE((::portable_stl::is_lvalue_reference<std::uint32_t>{}()));
  ASSERT_FALSE((::portable_stl::is_lvalue_reference<std::uint32_t &&>{}()));
  ASSERT_FALSE((::portable_stl::is_lvalue_reference<std::uint32_t *>{}()));
  test_metaprogramming_primary_type::metaprogramming_primary_type_is_lvalue_reference_inline_variables();
}

TEST(metaprogramming_primary_type, is_rvalue_reference) {
  static_cast<void>(test_info_);
  {
    constexpr ::portable_stl::is_rvalue_reference<std::uint32_t &> checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }
  {
    constexpr ::portable_stl::is_rvalue_reference<std::uint32_t &&> checker_type{};
    ASSERT_TRUE((checker_type()));
    static_cast<void>(checker_type);
  }
  ASSERT_TRUE((::portable_stl::is_rvalue_reference<std::uint32_t &&>{}()));
  ASSERT_TRUE((::portable_stl::is_rvalue_reference<std::uint32_t const &&>{}()));
  ASSERT_FALSE((::portable_stl::is_rvalue_reference<std::uint32_t>{}()));
  ASSERT_FALSE((::portable_stl::is_rvalue_reference<std::uint32_t &>{}()));
  ASSERT_FALSE((::portable_stl::is_rvalue_reference<std::uint32_t *>{}()));
  test_metaprogramming_primary_type::metaprogramming_primary_type_is_rvalue_reference_inline_variables();
}

namespace metaprogramming_primary_type_helper {
/**
 * @brief Test helper class.
 *
 */
class is_member_object_helper final {
public:
  /**
   * @brief Variable member.
   *
   */
  std::int32_t value{0};
  /**
   * @brief Function member.
   * @return 0
   */
  std::int32_t function() const noexcept {
    static_cast<void>(value);
    return 0;
  }
};
} // namespace metaprogramming_primary_type_helper

TEST(metaprogramming_primary_type, is_member_object_pointer) {
  static_cast<void>(test_info_);
  {
    constexpr metaprogramming_primary_type_helper::is_member_object_helper helper{};
    static_cast<void>(helper.function());
  }
  {
    constexpr ::portable_stl::is_member_object_pointer<std::uint32_t> checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }
  {
    constexpr ::portable_stl::is_member_object_pointer<
      decltype(&metaprogramming_primary_type_helper::is_member_object_helper::function)>
      checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }
  {
    constexpr ::portable_stl::is_member_object_pointer<
      decltype(&metaprogramming_primary_type_helper::is_member_object_helper::value)>
      checker_type{};
    ASSERT_TRUE((checker_type()));
    static_cast<void>(checker_type);
  }
  ASSERT_FALSE((::portable_stl::is_member_object_pointer<std::uint32_t>{}()));
  ASSERT_FALSE((::portable_stl::is_member_object_pointer<
                decltype(&metaprogramming_primary_type_helper::is_member_object_helper::function)>{}()));
  ASSERT_TRUE((::portable_stl::is_member_object_pointer<
               decltype(&metaprogramming_primary_type_helper::is_member_object_helper::value)>{}()));

  test_metaprogramming_primary_type::metaprogramming_primary_type_is_member_object_pointer_inline_variables();
}

TEST(metaprogramming_primary_type, is_member_function_pointer) {
  static_cast<void>(test_info_);

  {
    constexpr ::portable_stl::is_member_function_pointer<std::uint32_t> checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }
  {
    constexpr ::portable_stl::is_member_function_pointer<
      decltype(&metaprogramming_primary_type_helper::is_member_object_helper::function)>
      checker_type{};
    ASSERT_TRUE((checker_type()));
    static_cast<void>(checker_type);
  }
  {
    constexpr ::portable_stl::is_member_function_pointer<
      decltype(&metaprogramming_primary_type_helper::is_member_object_helper::value)>
      checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }

  ASSERT_FALSE((::portable_stl::is_member_function_pointer<std::uint32_t>{}()));

  ASSERT_FALSE((::portable_stl::is_member_function_pointer<
                decltype(&metaprogramming_primary_type_helper::is_member_object_helper::value)>{}()));

  ASSERT_TRUE((::portable_stl::is_member_function_pointer<
               decltype(&metaprogramming_primary_type_helper::is_member_object_helper::function)>{}()));

  test_metaprogramming_primary_type::metaprogramming_primary_type_is_member_function_pointer_inline_variables();
}
namespace metaprogramming_primary_type_helper {
/**
 * @brief Class for checking.
 *
 */
class checker_class final {
public:
  /**
   * @brief Enum in class for checking.
   *
   */
  enum checker_inner_enum : std::uint32_t {
    /**
     * @brief Fist enum value.
     *
     */
    CIE_FIRST,
    /**
     * @brief Second enum value.
     *
     */
    CIE_SECOND
  } inner{checker_inner_enum::CIE_FIRST};
};

/**
 * @brief Old enum for checking.
 *
 */
enum checker_enum : std::uint32_t {
  /**
   * @brief Fist enum value.
   *
   */
  CE_FIRST,
  /**
   * @brief Second enum value.
   *
   */
  CE_SECOND
};

/**
 * @brief Class enum for checking
 *
 */
enum class checker_class_enum : std::uint32_t {
  /**
   * @brief Fist enum value.
   *
   */
  CCE_FIRST,
  /**
   * @brief Second enum value.
   *
   */
  CCE_SECOND
};
/**
 * @brief Union for checking.
 *
 */
union checker_union {
  /**
   * @brief First element in union.
   *
   */
  std::int32_t             value;
  /**
   * @brief Second element in union.
   *
   */
  std::list<std::int32_t> *list;
};
} // namespace metaprogramming_primary_type_helper

TEST(metaprogramming_primary_type, is_enum) {
  static_cast<void>(test_info_);
  {
    metaprogramming_primary_type_helper::checker_class::checker_inner_enum helper{
      metaprogramming_primary_type_helper::checker_class::checker_inner_enum::CIE_FIRST};
    helper = metaprogramming_primary_type_helper::checker_class::checker_inner_enum::CIE_SECOND;
    std::int32_t const value{static_cast<std::int32_t>(helper)};
    static_cast<void>(value);
    ASSERT_EQ(
      static_cast<std::int32_t>(metaprogramming_primary_type_helper::checker_class::checker_inner_enum::CIE_SECOND),
      value);
  }
  {
    metaprogramming_primary_type_helper::checker_enum helper{
      metaprogramming_primary_type_helper::checker_enum::CE_FIRST};
    helper = metaprogramming_primary_type_helper::checker_enum::CE_SECOND;
    std::int32_t const value{static_cast<std::int32_t>(helper)};
    static_cast<void>(value);
    ASSERT_EQ(static_cast<std::int32_t>(metaprogramming_primary_type_helper::checker_enum::CE_SECOND), value);
  }
  {
    metaprogramming_primary_type_helper::checker_class_enum helper{
      metaprogramming_primary_type_helper::checker_class_enum::CCE_FIRST};
    helper = metaprogramming_primary_type_helper::checker_class_enum::CCE_SECOND;
    std::int32_t const value{static_cast<std::int32_t>(helper)};
    static_cast<void>(value);
    ASSERT_EQ(static_cast<std::int32_t>(metaprogramming_primary_type_helper::checker_class_enum::CCE_SECOND), value);
  }
  {
    constexpr ::portable_stl::is_enum<metaprogramming_primary_type_helper::checker_class> checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }
  {
    constexpr ::portable_stl::is_enum<metaprogramming_primary_type_helper::checker_class::checker_inner_enum>
      checker_type{};
    ASSERT_TRUE((checker_type()));
    static_cast<void>(checker_type);
  }
  {
    constexpr ::portable_stl::is_enum<metaprogramming_primary_type_helper::checker_enum> checker_type{};
    ASSERT_TRUE((checker_type()));
    static_cast<void>(checker_type);
  }
  {
    constexpr ::portable_stl::is_enum<metaprogramming_primary_type_helper::checker_class_enum const> checker_type{};
    ASSERT_TRUE((checker_type()));
    static_cast<void>(checker_type);
  }
  {
    constexpr ::portable_stl::is_enum<std::uint32_t> checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }
  test_metaprogramming_primary_type::metaprogramming_primary_type_is_enum_inline_variables();
}
TEST(metaprogramming_primary_type, is_union) {
  static_cast<void>(test_info_);
  {
    metaprogramming_primary_type_helper::checker_union helper{};
    helper.value = 0;
    static_cast<void>(helper);
    std::int32_t const value{helper.value};
    static_cast<void>(value);
    ASSERT_EQ(0, value);
  }
  {
    constexpr ::portable_stl::is_union<metaprogramming_primary_type_helper::checker_class> checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }
  {
    constexpr ::portable_stl::is_union<metaprogramming_primary_type_helper::checker_class_enum> checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }
  {
    constexpr ::portable_stl::is_union<metaprogramming_primary_type_helper::checker_enum> checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }
  {
    constexpr ::portable_stl::is_union<metaprogramming_primary_type_helper::checker_union> checker_type{};
    ASSERT_TRUE((checker_type()));
    static_cast<void>(checker_type);
  }
  test_metaprogramming_primary_type::metaprogramming_primary_type_is_union_inline_variables();
}
TEST(metaprogramming_primary_type, is_class) {
  static_cast<void>(test_info_);
  {
    metaprogramming_primary_type_helper::checker_class helper{};
    helper.inner = metaprogramming_primary_type_helper::checker_class::CIE_SECOND;
    std::int32_t const value{static_cast<std::int32_t>(helper.inner)};
    static_cast<void>(value);
    ASSERT_EQ(static_cast<std::int32_t>(metaprogramming_primary_type_helper::checker_class::CIE_SECOND), value);
  }
  {
    constexpr ::portable_stl::is_class<metaprogramming_primary_type_helper::checker_class> checker_type{};
    ASSERT_TRUE((checker_type()));
    static_cast<void>(checker_type);
  }
  {
    constexpr ::portable_stl::is_class<metaprogramming_primary_type_helper::checker_class_enum> checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }
  {
    constexpr ::portable_stl::is_class<metaprogramming_primary_type_helper::checker_union> checker_type{};
    ASSERT_FALSE((checker_type()));
    static_cast<void>(checker_type);
  }
  {
    constexpr ::portable_stl::is_class<class checker_class_not_implemented> checker_type{};
    ASSERT_TRUE((checker_type()));
    static_cast<void>(checker_type);
  }
  test_metaprogramming_primary_type::metaprogramming_primary_type_is_class_inline_variables();
}

namespace metaprogramming_primary_type_helper {
namespace {
  /**
   * @brief Helper function
   *
   * @return int
   */
  constexpr static std::int32_t default_test_function() noexcept {
    return 0;
  };
} // namespace
/**
 * @brief Helper class for get member type.
 *
 * @tparam T of object
 */
template<class T> class member_getter                  final {};
/**
 * @brief Helper class for get member type.
 *
 * @tparam T of object.
 * @tparam U type of member.
 */
template<class T, class U> class member_getter<U T::*> final {
public:
  /**
   * @brief Detecter for member type.
   */
  using member_type = U;
};
}; // namespace metaprogramming_primary_type_helper
TEST(metaprogramming_primary_type, is_function) {
  static_cast<void>(test_info_);
  static_cast<void>(metaprogramming_primary_type_helper::default_test_function());
  ASSERT_FALSE((::portable_stl::is_function<metaprogramming_primary_type_helper::is_member_object_helper>{}()));
  ASSERT_TRUE((::portable_stl::is_function<int(int)>{}()));
  ASSERT_TRUE((::portable_stl::is_function<decltype(metaprogramming_primary_type_helper::default_test_function)>{}()));
  ASSERT_FALSE((::portable_stl::is_function<int>{}()));

  /**
   * @brief Check detecting type is function.
   *
   */
  using T = metaprogramming_primary_type_helper::member_getter<
    decltype(&metaprogramming_primary_type_helper::is_member_object_helper::function)>::member_type; // T is int()
                                                                                                     // const&
  ASSERT_TRUE((::portable_stl::is_function<T>{}()));

  test_metaprogramming_primary_type::metaprogramming_primary_type_is_function_inline_variables();
}
