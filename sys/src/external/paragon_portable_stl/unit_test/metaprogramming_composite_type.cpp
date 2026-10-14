// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_composite_type.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "portable_stl/metaprogramming/composite_type/is_arithmetic.h"
#include "portable_stl/metaprogramming/composite_type/is_compound.h"
#include "portable_stl/metaprogramming/composite_type/is_fundamental.h"
#include "portable_stl/metaprogramming/composite_type/is_member_pointer.h"
#include "portable_stl/metaprogramming/composite_type/is_object.h"
#include "portable_stl/metaprogramming/composite_type/is_reference.h"
#include "portable_stl/metaprogramming/composite_type/is_scalar.h"

#if defined(__cpp_inline_variables)
#  include "metaprogramming_composite_type_inline_variables.h"
#else
#  include "metaprogramming_composite_type.h"
#endif

TEST(metaprogramming_composite_type, is_reference) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_reference<std::int32_t> type_checker{};
    static_cast<void>(type_checker);
    ASSERT_FALSE((type_checker()));
  }
  {
    ::portable_stl::is_reference<std::int32_t &> type_checker{};
    static_cast<void>(type_checker);
    ASSERT_TRUE((type_checker()));
  }
  {
    ::portable_stl::is_reference<std::int32_t &&> type_checker{};
    static_cast<void>(type_checker);
    ASSERT_TRUE((type_checker()));
  }
  ASSERT_FALSE((::portable_stl::is_reference<std::int32_t>{}()));
  ASSERT_TRUE((::portable_stl::is_reference<std::int32_t &>{}()));
  ASSERT_TRUE((::portable_stl::is_reference<std::int32_t &&>{}()));
  test_metaprogramming_composite_type::metaprogramming_composite_type_is_reference_inline_variables();
}

TEST(metaprogramming_composite_type, is_arithmetic) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::is_arithmetic<std::uint32_t> checker{};
    ASSERT_TRUE((checker()));
  }

  ASSERT_TRUE((::portable_stl::is_arithmetic<std::uint32_t>{}()));
  ASSERT_TRUE((::portable_stl::is_arithmetic<float const>{}()));
  ASSERT_TRUE((::portable_stl::is_arithmetic<std::size_t>{}()));
  ASSERT_FALSE((::portable_stl::is_arithmetic<void>{}()));

  test_metaprogramming_composite_type::metaprogramming_composite_type_is_arithmetic_inline_variables();
}
TEST(metaprogramming_composite_type, is_fundamental) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_fundamental<std::uint32_t> checker{};
    ASSERT_TRUE((checker()));
  }

  ASSERT_TRUE((::portable_stl::is_fundamental<std::uint32_t>{}()));
  ASSERT_TRUE((::portable_stl::is_fundamental<void>{}()));
  ASSERT_TRUE((::portable_stl::is_fundamental<float>{}()));
  ASSERT_TRUE((::portable_stl::is_fundamental<float>{}()));
  ASSERT_TRUE((::portable_stl::is_fundamental<std::nullptr_t>{}()));
  ASSERT_FALSE((::portable_stl::is_fundamental<std::uint32_t *>{}()));
  ASSERT_FALSE((::portable_stl::is_fundamental<std::uint32_t &>{}()));
  ASSERT_FALSE((::portable_stl::is_fundamental<std::uint32_t &&>{}()));

  test_metaprogramming_composite_type::metaprogramming_composite_type_is_fundamental_inline_variables();
}
TEST(metaprogramming_composite_type, is_object) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_object<void> checker{};
    ASSERT_FALSE((checker()));
  }

  ASSERT_FALSE((::portable_stl::is_object<void>{}()));
  ASSERT_TRUE((::portable_stl::is_object<std::uint32_t>{}()));
  ASSERT_FALSE((::portable_stl::is_object<std::uint32_t &>{}()));
  ASSERT_TRUE((::portable_stl::is_object<std::uint32_t *>{}()));
  ASSERT_FALSE((::portable_stl::is_object<std::uint32_t *&>{}()));
  ASSERT_TRUE((::portable_stl::is_object<class cls>{}()));
  ASSERT_FALSE((::portable_stl::is_object<class cls &>{}()));
  ASSERT_TRUE((::portable_stl::is_object<class cls *>{}()));
  ASSERT_FALSE((::portable_stl::is_object<std::int32_t()>{}()));
  ASSERT_TRUE((::portable_stl::is_object<std::int32_t (*)()>{}()));
  ASSERT_FALSE((::portable_stl::is_object<std::int32_t (&)()>{}()));

  test_metaprogramming_composite_type::metaprogramming_composite_type_is_object_inline_variables();
}
TEST(metaprogramming_composite_type, is_scalar) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_scalar<std::uint32_t> checker{};
    ASSERT_TRUE((checker()));
  }
  ASSERT_TRUE((::portable_stl::is_scalar<std::uint32_t>{}()));
  ASSERT_TRUE((::portable_stl::is_scalar<std::uint32_t *>{}()));
  ASSERT_TRUE((::portable_stl::is_scalar<void *>{}()));
  ASSERT_TRUE((::portable_stl::is_scalar<std::nullptr_t>{}()));
  ASSERT_FALSE((::portable_stl::is_scalar<void>{}()));

  test_metaprogramming_composite_type::metaprogramming_composite_type_is_scalar_inline_variables();
}
TEST(metaprogramming_composite_type, is_compound) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_compound<std::uint32_t> checker{};
    ASSERT_FALSE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_compound<std::uint32_t>{}()));
  ASSERT_TRUE((::portable_stl::is_compound<std::uint32_t *>{}()));
  ASSERT_TRUE((::portable_stl::is_compound<std::uint32_t &>{}()));
  ASSERT_TRUE((::portable_stl::is_compound<std::int32_t()>{}()));
  ASSERT_TRUE((::portable_stl::is_compound<std::int32_t (*)()>{}()));
  ASSERT_TRUE((::portable_stl::is_compound<std::uint8_t[1]>{}()));

  test_metaprogramming_composite_type::metaprogramming_composite_type_is_compound_inline_variables();
}
namespace metaprogramming_composite_type_test_helper {
/**
 * @brief is_member_object test helper class
 *
 */
class is_member_object_helper final {
public:
  /**
   * @brief value member.
   *
   */
  std::int32_t           value{0};
  /**
   * @brief function member.
   * @return 0
   */
  constexpr std::int32_t function() const noexcept {
    return value;
  }
};
} // namespace metaprogramming_composite_type_test_helper

TEST(metaprogramming_composite_type, is_member_pointer) {
  static_cast<void>(test_info_);
  {
    metaprogramming_composite_type_test_helper::is_member_object_helper helper{};
    static_cast<void>(helper);
    ASSERT_EQ(0, helper.value);
    helper.value = 1;
    static_cast<void>(helper.function());
  }
  {
    ::portable_stl::is_member_pointer<std::int32_t> type_checker{};
    static_cast<void>(type_checker);
    ASSERT_FALSE((type_checker()));
  }
  {
    ::portable_stl::is_member_pointer<
      decltype(&metaprogramming_composite_type_test_helper::is_member_object_helper::value)>
      type_checker{};
    static_cast<void>(type_checker);
    ASSERT_TRUE((type_checker()));
  }
  {
    ::portable_stl::is_member_pointer<
      decltype(&metaprogramming_composite_type_test_helper::is_member_object_helper::function)>
      type_checker{};
    static_cast<void>(type_checker);
    ASSERT_TRUE((type_checker()));
  }
  ASSERT_FALSE((::portable_stl::is_member_pointer<std::int32_t>{}()));
  ASSERT_TRUE((::portable_stl::is_member_pointer<
               decltype(&metaprogramming_composite_type_test_helper::is_member_object_helper::value)>{}()));
  ASSERT_TRUE((::portable_stl::is_member_pointer<
               decltype(&metaprogramming_composite_type_test_helper::is_member_object_helper::function)>{}()));
  test_metaprogramming_composite_type::metaprogramming_composite_type_is_member_pointer_inline_variables();
}
