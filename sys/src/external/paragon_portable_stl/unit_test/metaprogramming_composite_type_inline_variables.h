// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_composite_type_inline_variables.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_METAPROGRAMMING_COMPOSITE_TYPE_INLINE_VARIABLES_H
#define PSTL_METAPROGRAMMING_COMPOSITE_TYPE_INLINE_VARIABLES_H

#include <gtest/gtest.h>

#include "portable_stl/common/size_t.h"
#include "portable_stl/metaprogramming/composite_type/is_arithmetic_v.h"
#include "portable_stl/metaprogramming/composite_type/is_compound_v.h"
#include "portable_stl/metaprogramming/composite_type/is_fundamental_v.h"
#include "portable_stl/metaprogramming/composite_type/is_member_pointer_v.h"
#include "portable_stl/metaprogramming/composite_type/is_object_v.h"
#include "portable_stl/metaprogramming/composite_type/is_reference_v.h"
#include "portable_stl/metaprogramming/composite_type/is_scalar_v.h"

namespace test_metaprogramming_composite_type {
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_composite_type_is_reference_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_reference_v<std::int32_t>));
  ASSERT_TRUE((::portable_stl::is_reference_v<std::int32_t &>));
  ASSERT_TRUE((::portable_stl::is_reference_v<std::int32_t &&>));
}

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_composite_type_is_arithmetic_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_arithmetic_v<std::uint32_t>));
  ASSERT_TRUE((::portable_stl::is_arithmetic_v<float const>));
  ASSERT_TRUE((::portable_stl::is_arithmetic_v<std::size_t>));
  ASSERT_FALSE((::portable_stl::is_arithmetic_v<void>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_composite_type_is_fundamental_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_fundamental_v<std::uint32_t>));
  ASSERT_TRUE((::portable_stl::is_fundamental_v<void>));
  ASSERT_TRUE((::portable_stl::is_fundamental_v<float>));
  ASSERT_TRUE((::portable_stl::is_fundamental_v<float>));
  ASSERT_TRUE((::portable_stl::is_fundamental_v<std::nullptr_t>));
  ASSERT_FALSE((::portable_stl::is_fundamental_v<std::uint32_t *>));
  ASSERT_FALSE((::portable_stl::is_fundamental_v<std::uint32_t &>));
  ASSERT_FALSE((::portable_stl::is_fundamental_v<std::uint32_t &&>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_composite_type_is_object_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_object_v<void>));
  ASSERT_TRUE((::portable_stl::is_object_v<std::uint32_t>));
  ASSERT_FALSE((::portable_stl::is_object_v<std::uint32_t &>));
  ASSERT_TRUE((::portable_stl::is_object_v<std::uint32_t *>));
  ASSERT_FALSE((::portable_stl::is_object_v<std::uint32_t *&>));
  ASSERT_TRUE((::portable_stl::is_object_v<class cls>));
  ASSERT_FALSE((::portable_stl::is_object_v<class cls &>));
  ASSERT_TRUE((::portable_stl::is_object_v<class cls *>));
  ASSERT_FALSE((::portable_stl::is_object_v<std::int32_t()>));
  ASSERT_TRUE((::portable_stl::is_object_v<std::int32_t (*)()>));
  ASSERT_FALSE((::portable_stl::is_object_v<std::int32_t (&)()>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_composite_type_is_scalar_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_scalar_v<std::uint32_t>));
  ASSERT_TRUE((::portable_stl::is_scalar_v<std::uint32_t *>));
  ASSERT_TRUE((::portable_stl::is_scalar_v<void *>));
  ASSERT_TRUE((::portable_stl::is_scalar_v<std::nullptr_t>));
  ASSERT_FALSE((::portable_stl::is_scalar_v<void>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_composite_type_is_compound_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_compound_v<std::uint32_t>));
  ASSERT_TRUE((::portable_stl::is_compound_v<std::uint32_t *>));
  ASSERT_TRUE((::portable_stl::is_compound_v<std::uint32_t &>));
  ASSERT_TRUE((::portable_stl::is_compound_v<std::int32_t()>));
  ASSERT_TRUE((::portable_stl::is_compound_v<std::int32_t(*)>));
  ASSERT_TRUE((::portable_stl::is_compound_v<std::uint8_t[1]>));
}

namespace metaprogramming_composite_type_test_helper_inline {
  /**
   * @brief is_member_object test helper class
   *
   */
  class metaprogramming_composite_type_inline_variables final {
  public:
    /**
     * @brief value member.
     *
     */
    std::uint32_t          value{0U};
    /**
     * @brief function member.
     * @return 0
     */
    constexpr std::int32_t function() const noexcept {
      static_cast<void>(value);
      return 0;
    };
  };
} // namespace metaprogramming_composite_type_test_helper_inline

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_composite_type_is_member_pointer_inline_variables() {
  {
    constexpr metaprogramming_composite_type_test_helper_inline::metaprogramming_composite_type_inline_variables
      helper{};
    static_cast<void>(helper);
    ASSERT_EQ(0, helper.value);
    static_cast<void>(helper.function());
  }
  ASSERT_FALSE((::portable_stl::is_member_pointer_v<std::int32_t>));
  ASSERT_TRUE(
    (::portable_stl::is_member_pointer_v<decltype(&metaprogramming_composite_type_test_helper_inline::
                                                    metaprogramming_composite_type_inline_variables::value)>));
  ASSERT_TRUE(
    (::portable_stl::is_member_pointer_v<decltype(&metaprogramming_composite_type_test_helper_inline::
                                                    metaprogramming_composite_type_inline_variables::function)>));
}

} // namespace test_metaprogramming_composite_type

#endif // PSTL_METAPROGRAMMING_COMPOSITE_TYPE_INLINE_VARIABLES_H
