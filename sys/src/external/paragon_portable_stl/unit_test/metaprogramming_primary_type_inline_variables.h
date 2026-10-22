// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_primary_type_inline_variables.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_METAPROGRAMMING_PRIMARY_TYPE_INLINE_VARIABLES_H
#define PSTL_METAPROGRAMMING_PRIMARY_TYPE_INLINE_VARIABLES_H

#include <gtest/gtest.h>

#include <list>

#include "portable_stl/metaprogramming/primary_type/is_array_v.h"
#include "portable_stl/metaprogramming/primary_type/is_class_v.h"
#include "portable_stl/metaprogramming/primary_type/is_enum_v.h"
#include "portable_stl/metaprogramming/primary_type/is_floating_point_v.h"
#include "portable_stl/metaprogramming/primary_type/is_function_v.h"
#include "portable_stl/metaprogramming/primary_type/is_integral_v.h"
#include "portable_stl/metaprogramming/primary_type/is_lvalue_reference_v.h"
#include "portable_stl/metaprogramming/primary_type/is_member_function_pointer_v.h"
#include "portable_stl/metaprogramming/primary_type/is_member_object_pointer_v.h"
#include "portable_stl/metaprogramming/primary_type/is_null_pointer_v.h"
#include "portable_stl/metaprogramming/primary_type/is_pointer_v.h"
#include "portable_stl/metaprogramming/primary_type/is_rvalue_reference_v.h"
#include "portable_stl/metaprogramming/primary_type/is_union_v.h"
#include "portable_stl/metaprogramming/primary_type/is_void_v.h"

namespace test_metaprogramming_primary_type {
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_primary_type_is_void_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_void_v<void>));
  ASSERT_TRUE((::portable_stl::is_void_v<void const>));
  ASSERT_FALSE((::portable_stl::is_void_v<std::uint32_t>));
}

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_primary_type_is_null_pointer_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_null_pointer_v<decltype(nullptr)>));
  ASSERT_TRUE((::portable_stl::is_null_pointer_v<::portable_stl::nullptr_t const>));
  ASSERT_FALSE((::portable_stl::is_null_pointer_v<std::uint32_t>));
  ASSERT_FALSE((::portable_stl::is_null_pointer_v<void>));
}

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_primary_type_is_integral_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_integral_v<bool>));
  ASSERT_TRUE((::portable_stl::is_integral_v<bool const>));
  ASSERT_TRUE((::portable_stl::is_integral_v<char>));
  ASSERT_TRUE((::portable_stl::is_integral_v<char const>));
  ASSERT_TRUE((::portable_stl::is_integral_v<wchar_t>));
  ASSERT_TRUE((::portable_stl::is_integral_v<wchar_t const>));
  ASSERT_TRUE((::portable_stl::is_integral_v<char16_t>));
  ASSERT_TRUE((::portable_stl::is_integral_v<char16_t const>));
  ASSERT_TRUE((::portable_stl::is_integral_v<char32_t>));
  ASSERT_TRUE((::portable_stl::is_integral_v<char32_t const>));
  ASSERT_TRUE((::portable_stl::is_integral_v<signed char>));
  ASSERT_TRUE((::portable_stl::is_integral_v<signed char const>));
  ASSERT_TRUE((::portable_stl::is_integral_v<unsigned char>));
  ASSERT_TRUE((::portable_stl::is_integral_v<unsigned char const>));
  ASSERT_TRUE((::portable_stl::is_integral_v<signed short int>));
  ASSERT_TRUE((::portable_stl::is_integral_v<signed short int const>));
  ASSERT_TRUE((::portable_stl::is_integral_v<unsigned short int>));
  ASSERT_TRUE((::portable_stl::is_integral_v<unsigned short int const>));
  ASSERT_TRUE((::portable_stl::is_integral_v<signed int>));
  ASSERT_TRUE((::portable_stl::is_integral_v<signed int const>));
  ASSERT_TRUE((::portable_stl::is_integral_v<unsigned int>));
  ASSERT_TRUE((::portable_stl::is_integral_v<unsigned int const>));
  ASSERT_TRUE((::portable_stl::is_integral_v<signed long int>));
  ASSERT_TRUE((::portable_stl::is_integral_v<signed long int const>));
  ASSERT_TRUE((::portable_stl::is_integral_v<unsigned long int>));
  ASSERT_TRUE((::portable_stl::is_integral_v<unsigned long int const>));
  ASSERT_TRUE((::portable_stl::is_integral_v<signed long long int>));
  ASSERT_TRUE((::portable_stl::is_integral_v<signed long long int const>));
  ASSERT_TRUE((::portable_stl::is_integral_v<unsigned long long int>));
  ASSERT_TRUE((::portable_stl::is_integral_v<unsigned long long int const>));
  ASSERT_FALSE((::portable_stl::is_integral_v<int *>));
  ASSERT_FALSE((::portable_stl::is_integral_v<std::vector<std::uint32_t>>));
  ASSERT_FALSE((::portable_stl::is_integral_v<void>));
  ASSERT_FALSE((::portable_stl::is_integral_v<float>));
  ASSERT_FALSE((::portable_stl::is_integral_v<float const>));
  ASSERT_FALSE((::portable_stl::is_integral_v<double>));
  ASSERT_FALSE((::portable_stl::is_integral_v<double const>));
  ASSERT_FALSE((::portable_stl::is_integral_v<long double>));
  ASSERT_FALSE((::portable_stl::is_integral_v<long double const>));
}

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_primary_type_is_floating_point_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_floating_point_v<float>));
  ASSERT_TRUE((::portable_stl::is_floating_point_v<float const>));
  ASSERT_TRUE((::portable_stl::is_floating_point_v<double>));
  ASSERT_TRUE((::portable_stl::is_floating_point_v<double const>));
  ASSERT_TRUE((::portable_stl::is_floating_point_v<long double>));
  ASSERT_TRUE((::portable_stl::is_floating_point_v<long double const>));
  ASSERT_FALSE((::portable_stl::is_floating_point_v<int>));
  ASSERT_FALSE((::portable_stl::is_floating_point_v<int *>));
  ASSERT_FALSE((::portable_stl::is_floating_point_v<std::list<std::uint32_t>>));
  ASSERT_FALSE((::portable_stl::is_floating_point_v<void>));
}

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_primary_type_is_array_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_array_v<std::uint32_t[]>));
  ASSERT_TRUE((::portable_stl::is_array_v<std::uint32_t const[]>));
  ASSERT_TRUE((::portable_stl::is_array_v<std::uint32_t[10]>));
  ASSERT_TRUE((::portable_stl::is_array_v<std::uint32_t const[10]>));
}

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_primary_type_is_pointer_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_pointer_v<void *>));
  ASSERT_TRUE((::portable_stl::is_pointer_v<void *const>));
  ASSERT_TRUE((::portable_stl::is_pointer_v<void const *>));
  ASSERT_TRUE((::portable_stl::is_pointer_v<void const *const>));
  ASSERT_TRUE(
    (::portable_stl::is_pointer_v<
      decltype(&test_metaprogramming_primary_type::metaprogramming_primary_type_is_pointer_inline_variables)>));
  ASSERT_FALSE((::portable_stl::is_pointer_v<std::uint32_t>));
  ASSERT_FALSE((::portable_stl::is_pointer_v<std::uint32_t const>));
}

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_primary_type_is_lvalue_reference_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_lvalue_reference_v<std::uint32_t &>));
  ASSERT_TRUE((::portable_stl::is_lvalue_reference_v<std::uint32_t const &>));
  ASSERT_FALSE((::portable_stl::is_lvalue_reference_v<std::uint32_t>));
  ASSERT_FALSE((::portable_stl::is_lvalue_reference_v<std::uint32_t &&>));
  ASSERT_FALSE((::portable_stl::is_lvalue_reference_v<std::uint32_t *>));
}

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_primary_type_is_rvalue_reference_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_rvalue_reference_v<std::uint32_t &&>));
  ASSERT_TRUE((::portable_stl::is_rvalue_reference_v<std::uint32_t const &&>));
  ASSERT_FALSE((::portable_stl::is_rvalue_reference_v<std::uint32_t>));
  ASSERT_FALSE((::portable_stl::is_rvalue_reference_v<std::uint32_t &>));
  ASSERT_FALSE((::portable_stl::is_rvalue_reference_v<std::uint32_t *>));
}

namespace metaprogramming_primary_type_inline_helper {
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
    std::int32_t           value{0};
    /**
     * @brief Function member.
     * @return 0
     */
    constexpr std::int32_t function() const noexcept {
      static_cast<void>(value);
      return 0;
    };
  };
} // namespace metaprogramming_primary_type_inline_helper

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_primary_type_is_member_object_pointer_inline_variables() {
  {
    constexpr metaprogramming_primary_type_inline_helper::is_member_object_helper helper{};
    static_cast<void>(helper.function());
  }
  ASSERT_FALSE((::portable_stl::is_member_object_pointer_v<std::uint32_t>));
  ASSERT_FALSE((::portable_stl::is_member_object_pointer_v<
                decltype(&metaprogramming_primary_type_inline_helper::is_member_object_helper::function)>));
  ASSERT_TRUE((::portable_stl::is_member_object_pointer_v<
               decltype(&metaprogramming_primary_type_inline_helper::is_member_object_helper::value)>));
}

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_primary_type_is_member_function_pointer_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_member_function_pointer_v<std::uint32_t>));
  ASSERT_TRUE((::portable_stl::is_member_function_pointer_v<
               decltype(&metaprogramming_primary_type_inline_helper::is_member_object_helper::function)>));
  ASSERT_FALSE((::portable_stl::is_member_function_pointer_v<
                decltype(&metaprogramming_primary_type_inline_helper::is_member_object_helper::value)>));
}

namespace metaprogramming_primary_type_inline_helper {
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
} // namespace metaprogramming_primary_type_inline_helper

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_primary_type_is_enum_inline_variables() {
  {
    metaprogramming_primary_type_inline_helper::checker_class::checker_inner_enum helper{
      metaprogramming_primary_type_inline_helper::checker_class::checker_inner_enum::CIE_FIRST};
    helper = metaprogramming_primary_type_inline_helper::checker_class::checker_inner_enum::CIE_SECOND;
    std::int32_t const value{static_cast<std::int32_t>(helper)};
    static_cast<void>(value);
    ASSERT_EQ(static_cast<std::int32_t>(
                metaprogramming_primary_type_inline_helper::checker_class::checker_inner_enum::CIE_SECOND),
              value);
  }
  {
    metaprogramming_primary_type_inline_helper::checker_enum helper{
      metaprogramming_primary_type_inline_helper::checker_enum::CE_FIRST};
    helper = metaprogramming_primary_type_inline_helper::checker_enum::CE_SECOND;
    std::int32_t const value{static_cast<std::int32_t>(helper)};
    static_cast<void>(value);
    ASSERT_EQ(static_cast<std::int32_t>(metaprogramming_primary_type_inline_helper::checker_enum::CE_SECOND), value);
  }
  {
    metaprogramming_primary_type_inline_helper::checker_class_enum helper{
      metaprogramming_primary_type_inline_helper::checker_class_enum::CCE_FIRST};
    helper = metaprogramming_primary_type_inline_helper::checker_class_enum::CCE_SECOND;
    std::int32_t const value{static_cast<std::int32_t>(helper)};
    static_cast<void>(value);
    ASSERT_EQ(static_cast<std::int32_t>(metaprogramming_primary_type_inline_helper::checker_class_enum::CCE_SECOND),
              value);
  }
  ASSERT_FALSE((::portable_stl::is_enum_v<metaprogramming_primary_type_inline_helper::checker_class>));
  ASSERT_TRUE(
    (::portable_stl::is_enum_v<metaprogramming_primary_type_inline_helper::checker_class::checker_inner_enum>));
  ASSERT_TRUE((::portable_stl::is_enum_v<metaprogramming_primary_type_inline_helper::checker_enum>));
  ASSERT_TRUE((::portable_stl::is_enum_v<metaprogramming_primary_type_inline_helper::checker_class_enum const>));
  ASSERT_FALSE((::portable_stl::is_enum_v<std::uint32_t>));
}

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_primary_type_is_union_inline_variables() {
  {
    metaprogramming_primary_type_inline_helper::checker_union helper{};
    helper.value = 0;
    static_cast<void>(helper);
    std::int32_t const value{static_cast<std::int32_t>(helper.value)};
    static_cast<void>(value);
    ASSERT_EQ(0, value);
  }
  ASSERT_FALSE((::portable_stl::is_union_v<metaprogramming_primary_type_inline_helper::checker_class>));
  ASSERT_FALSE((::portable_stl::is_union_v<metaprogramming_primary_type_inline_helper::checker_class_enum>));
  ASSERT_FALSE((::portable_stl::is_union_v<metaprogramming_primary_type_inline_helper::checker_enum>));
  ASSERT_TRUE((::portable_stl::is_union_v<metaprogramming_primary_type_inline_helper::checker_union>));
}

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_primary_type_is_class_inline_variables() {
  {
    metaprogramming_primary_type_inline_helper::checker_class helper{};
    helper.inner = metaprogramming_primary_type_inline_helper::checker_class::CIE_SECOND;
    std::int32_t const value{static_cast<std::int32_t>(helper.inner)};
    static_cast<void>(value);
    ASSERT_EQ(static_cast<std::int32_t>(metaprogramming_primary_type_inline_helper::checker_class::CIE_SECOND), value);
  }
  ASSERT_TRUE((::portable_stl::is_class_v<metaprogramming_primary_type_inline_helper::checker_class>));
  ASSERT_FALSE((::portable_stl::is_class_v<metaprogramming_primary_type_inline_helper::checker_class_enum>));
  ASSERT_FALSE((::portable_stl::is_class_v<metaprogramming_primary_type_inline_helper::checker_union>));
  ASSERT_TRUE((::portable_stl::is_class_v<class checker_class_not_implemented>));
}

namespace metaprogramming_primary_type_inline_helper {
  /**
   * @brief Helper function
   *
   * @return int
   */
  constexpr static std::int32_t inline_test_function() noexcept {
    return 0;
  };
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
}; // namespace metaprogramming_primary_type_inline_helper

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_primary_type_is_function_inline_variables() {
  static_cast<void>(metaprogramming_primary_type_inline_helper::inline_test_function());
  ASSERT_FALSE((::portable_stl::is_function_v<metaprogramming_primary_type_inline_helper::is_member_object_helper>));
  ASSERT_TRUE((::portable_stl::is_function_v<int(int)>));
  ASSERT_TRUE(
    (::portable_stl::is_function_v<decltype(metaprogramming_primary_type_inline_helper::inline_test_function)>));
  ASSERT_FALSE((::portable_stl::is_function_v<int>));

  /**
   * @brief Check detecting type is function.
   *
   */
  using T = metaprogramming_primary_type_inline_helper::member_getter<
    decltype(&metaprogramming_primary_type_inline_helper::is_member_object_helper::function)>::member_type; // T is
                                                                                                            // int()
                                                                                                            // const&
  ASSERT_TRUE((::portable_stl::is_function_v<T>));
}
} // namespace test_metaprogramming_primary_type

#endif // PSTL_METAPROGRAMMING_PRIMARY_TYPE_INLINE_VARIABLES_H
