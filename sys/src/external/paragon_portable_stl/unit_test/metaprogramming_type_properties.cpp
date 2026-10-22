// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_type_properties.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "metaprogramming_type_properties_helper.h"
#include "portable_stl/metaprogramming/type_properties/has_virtual_destructor.h"
#include "portable_stl/metaprogramming/type_properties/is_abstract.h"
#include "portable_stl/metaprogramming/type_properties/is_assignable.h"
#include "portable_stl/metaprogramming/type_properties/is_bounded_array.h"
#include "portable_stl/metaprogramming/type_properties/is_const.h"
#include "portable_stl/metaprogramming/type_properties/is_constructible.h"
#include "portable_stl/metaprogramming/type_properties/is_copy_assignable.h"
#include "portable_stl/metaprogramming/type_properties/is_copy_constructible.h"
#include "portable_stl/metaprogramming/type_properties/is_default_constructible.h"
#include "portable_stl/metaprogramming/type_properties/is_destructible.h"
#include "portable_stl/metaprogramming/type_properties/is_empty.h"
#include "portable_stl/metaprogramming/type_properties/is_final.h"
#include "portable_stl/metaprogramming/type_properties/is_implicit_lifetime.h"
#include "portable_stl/metaprogramming/type_properties/is_lvalue_referenceable.h"
#include "portable_stl/metaprogramming/type_properties/is_move_assignable.h"
#include "portable_stl/metaprogramming/type_properties/is_move_constructible.h"
#include "portable_stl/metaprogramming/type_properties/is_nothrow_assignable.h"
#include "portable_stl/metaprogramming/type_properties/is_nothrow_constructible.h"
#include "portable_stl/metaprogramming/type_properties/is_nothrow_copy_assignable.h"
#include "portable_stl/metaprogramming/type_properties/is_nothrow_copy_constructible.h"
#include "portable_stl/metaprogramming/type_properties/is_nothrow_default_constructible.h"
#include "portable_stl/metaprogramming/type_properties/is_nothrow_destructible.h"
#include "portable_stl/metaprogramming/type_properties/is_nothrow_move_assignable.h"
#include "portable_stl/metaprogramming/type_properties/is_nothrow_move_constructible.h"
#include "portable_stl/metaprogramming/type_properties/is_nothrow_swappable.h"
#include "portable_stl/metaprogramming/type_properties/is_nothrow_swappable_with.h"
#include "portable_stl/metaprogramming/type_properties/is_polymorphic.h"
#include "portable_stl/metaprogramming/type_properties/is_rvalue_referenceable.h"
#include "portable_stl/metaprogramming/type_properties/is_scoped_enum.h"
#include "portable_stl/metaprogramming/type_properties/is_signed.h"
#include "portable_stl/metaprogramming/type_properties/is_standard_layout.h"
#include "portable_stl/metaprogramming/type_properties/is_swappable.h"
#include "portable_stl/metaprogramming/type_properties/is_swappable_with.h"
#include "portable_stl/metaprogramming/type_properties/is_trivial.h"
#include "portable_stl/metaprogramming/type_properties/is_trivially_assignable.h"
#include "portable_stl/metaprogramming/type_properties/is_trivially_constructible.h"
#include "portable_stl/metaprogramming/type_properties/is_trivially_copy_assignable.h"
#include "portable_stl/metaprogramming/type_properties/is_trivially_copy_constructible.h"
#include "portable_stl/metaprogramming/type_properties/is_trivially_copyable.h"
#include "portable_stl/metaprogramming/type_properties/is_trivially_default_constructible.h"
#include "portable_stl/metaprogramming/type_properties/is_trivially_destructible.h"
#include "portable_stl/metaprogramming/type_properties/is_trivially_move_assignable.h"
#include "portable_stl/metaprogramming/type_properties/is_trivially_move_constructible.h"
#include "portable_stl/metaprogramming/type_properties/is_unbounded_array.h"
#include "portable_stl/metaprogramming/type_properties/is_unsigned.h"
#include "portable_stl/metaprogramming/type_properties/is_volatile.h"
#include "portable_stl/metaprogramming/type_properties/reference_constructs_from_temporary.h"
#include "portable_stl/metaprogramming/type_properties/reference_converts_from_temporary.h"
#include "portable_stl/utility/general/swap_array.h"

#if defined(__cpp_inline_variables)
#  include "metaprogramming_type_properties_inline_variables.h"
#else
#  include "metaprogramming_type_properties.h"
#endif

#if defined(__cpp_aggregate_bases)
#  include "metaprogramming_type_properties_aggregate.h"
#else
#  include "metaprogramming_type_properties_no_aggregate.h"
#endif

// __has_builtin  (  __has_unique_object_representations) - does not work in VS 2015
// in VS 2015 is_aggregate and has_unique_object_representations are under the same '#if _HAS_CXX17'
#if defined(__cpp_aggregate_bases) // should be some property of C++17 standart
#  include "metaprogramming_type_properties_has_unique_object_representations.h"
#else
#  include "metaprogramming_type_properties_no_has_unique_object_representations.h"
#endif

TEST(metaprogramming_type_properties, is_lvalue_referenceable) {
  static_cast<void>(test_info_);
  ASSERT_FALSE((::portable_stl::is_lvalue_referenceable<void>{}()));
  ASSERT_TRUE((::portable_stl::is_lvalue_referenceable<std::uint32_t>{}()));
  ASSERT_TRUE((::portable_stl::is_lvalue_referenceable<void *>{}()));

  {
    constexpr ::portable_stl::is_lvalue_referenceable<void> checker{};
    ASSERT_FALSE((checker()));
    static_cast<void>(checker);
  }

  {
    constexpr ::portable_stl::is_lvalue_referenceable<void *> checker{};
    ASSERT_TRUE((checker()));
    static_cast<void>(checker);
  }
  test_metaprogramming_type_properties::metaprogramming_type_properties_is_lvalue_referenceable_inline_variables();
}

TEST(metaprogramming_type_properties, is_rvalue_referenceable) {
  static_cast<void>(test_info_);
  ASSERT_FALSE((::portable_stl::is_rvalue_referenceable<void>{}()));
  ASSERT_TRUE((::portable_stl::is_rvalue_referenceable<std::uint32_t>{}()));
  ASSERT_TRUE((::portable_stl::is_rvalue_referenceable<void *>{}()));

  {
    constexpr ::portable_stl::is_rvalue_referenceable<void> checker{};
    ASSERT_FALSE((checker()));
    static_cast<void>(checker);
  }

  {
    constexpr ::portable_stl::is_rvalue_referenceable<void *> checker{};
    ASSERT_TRUE((checker()));
    static_cast<void>(checker);
  }
  test_metaprogramming_type_properties::metaprogramming_type_properties_is_rvalue_referenceable_inline_variables();
}

TEST(metaprogramming_type_properties, is_const) {
  static_cast<void>(test_info_);
  {
    constexpr ::portable_stl::is_const<std::int32_t const[3]> checker{};
    ASSERT_TRUE((checker()));
    static_cast<void>(checker);
  }
  ASSERT_TRUE((::portable_stl::is_const<std::int32_t const volatile>{}()));
  ASSERT_FALSE((::portable_stl::is_const<std::int32_t const *>{}()));
  ASSERT_FALSE((::portable_stl::is_const<std::int32_t const &>{}()));
  ASSERT_FALSE((::portable_stl::is_const<std::int32_t[3]>{}()));
  ASSERT_TRUE((::portable_stl::is_const<std::int32_t const[3]>{}()));
  test_metaprogramming_type_properties::metaprogramming_type_properties_is_const_inline_variables();
}

TEST(metaprogramming_type_properties, is_volatile) {
  static_cast<void>(test_info_);
  {
    constexpr ::portable_stl::is_volatile<std::int32_t[3]> checker{};
    ASSERT_FALSE((checker()));
    static_cast<void>(checker);
  }
  {
    constexpr ::portable_stl::is_volatile<std::int32_t volatile[3]> checker{};
    ASSERT_TRUE((checker()));
    static_cast<void>(checker);
  }
  ASSERT_TRUE((::portable_stl::is_volatile<std::int32_t const volatile>{}()));
  ASSERT_FALSE((::portable_stl::is_volatile<std::int32_t volatile *>{}()));
  ASSERT_FALSE((::portable_stl::is_volatile<std::int32_t volatile &>{}()));
  ASSERT_FALSE((::portable_stl::is_volatile<std::int32_t[3]>{}()));
  ASSERT_TRUE((::portable_stl::is_volatile<std::int32_t volatile[3]>{}()));
  test_metaprogramming_type_properties::metaprogramming_type_properties_is_volatile_inline_variables();
}

TEST(metaprogramming_type_properties, is_trivial) {
  static_cast<void>(test_info_);
  {
    metaprogramming_type_properties_helper::metaprogramming_type_properties_helper helper{};
    ASSERT_NE(nullptr, helper.cls.function());
    ASSERT_EQ(0, helper.value);
  }
  {
    metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class helper{0};
    ASSERT_NE(nullptr, helper.function());
    static_cast<void>(helper);
  }
  {
    ::portable_stl::is_trivial<metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>
      checker{};
    ASSERT_FALSE((checker()));
  }
  ASSERT_FALSE(
    (::portable_stl::is_trivial<metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>{}()));
  ASSERT_TRUE((::portable_stl::is_trivial<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_trivial_inline_variables();
}

TEST(metaprogramming_type_properties, is_trivially_copyable) {
  static_cast<void>(test_info_);
  {
    metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class helper{};
    ASSERT_EQ(0, helper.function());
  }

  {
    ::portable_stl::is_trivially_copyable<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>
      checker{};
    ASSERT_TRUE((checker()));
  }
  ASSERT_TRUE((::portable_stl::is_trivially_copyable<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>{}()));
  ASSERT_TRUE((::portable_stl::is_trivially_copyable<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));
  ASSERT_FALSE((::portable_stl::is_trivially_copyable<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>{}()));
  test_metaprogramming_type_properties::metaprogramming_type_properties_is_trivially_copyable_inline_variables();
}

TEST(metaprogramming_type_properties, is_standard_layout) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_standard_layout<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>
      checker{};
    ASSERT_TRUE((checker()));
  }
  ASSERT_TRUE((::portable_stl::is_standard_layout<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));
  ASSERT_FALSE((::portable_stl::is_standard_layout<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>{}()));
  ASSERT_TRUE((::portable_stl::is_standard_layout<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>{}()));
  test_metaprogramming_type_properties::metaprogramming_type_properties_is_standard_layout_inline_variables();
}

TEST(metaprogramming_type_properties, is_empty) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_empty<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>
      checker{};
    ASSERT_TRUE((checker()));
  }
  ASSERT_TRUE((::portable_stl::is_empty<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));
  ASSERT_FALSE((::portable_stl::is_empty<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>{}()));
  ASSERT_FALSE(
    (::portable_stl::is_empty<metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>{}()));

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_empty_inline_variables();
}

TEST(metaprogramming_type_properties, is_polymorphic) {
  static_cast<void>(test_info_);
  {
    metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::inheritor_virtual_class helper{};
    ASSERT_EQ(0, helper.function());
  }
  {
    ::portable_stl::is_polymorphic<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>
      checker{};
    ASSERT_FALSE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_polymorphic<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));
  ASSERT_TRUE((::portable_stl::is_polymorphic<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>{}()));
  ASSERT_TRUE(
    (::portable_stl::is_polymorphic<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::pure_virtual_class>{}()));

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_polymorphic_inline_variables();
}

TEST(metaprogramming_type_properties, is_abstract) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_abstract<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>
      checker{};
    ASSERT_FALSE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_abstract<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));
  ASSERT_FALSE((::portable_stl::is_abstract<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>{}()));
  ASSERT_TRUE(
    (::portable_stl::is_abstract<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::pure_virtual_class>{}()));

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_abstract_inline_variables();
}

TEST(metaprogramming_type_properties, is_final) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_final<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>
      checker{};
    ASSERT_TRUE((checker()));
  }

  ASSERT_FALSE((::portable_stl::is_final<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>{}()));
  ASSERT_TRUE((::portable_stl::is_final<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_final_inline_variables();
}

TEST(metaprogramming_type_properties, is_aggregate) {
  static_cast<void>(test_info_);

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_aggregate();

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_aggregate_inline_variables();
}

TEST(metaprogramming_type_properties, is_signed) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::type_properties_helpers::is_signed<bool>::type checker{};
    ASSERT_FALSE((checker()));
  }

  {
    ::portable_stl::type_properties_helpers::is_signed<float>::type checker{};
    ASSERT_TRUE((checker()));
  }

  {
    ::portable_stl::is_signed<bool> checker{};
    ASSERT_FALSE((checker()));
  }

  {
    ::portable_stl::is_signed<float> checker{};
    ASSERT_TRUE((checker()));
  }

  ASSERT_FALSE((::portable_stl::is_signed<bool>{}()));
  ASSERT_FALSE((::portable_stl::is_signed<std::uint32_t>{}()));

  ASSERT_TRUE((::portable_stl::is_signed<float>{}()));
  ASSERT_TRUE((::portable_stl::is_signed<std::int32_t>{}()));

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_signed_inline_variables();
}

TEST(metaprogramming_type_properties, is_unsigned) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::type_properties_helpers::is_unsigned<bool>::type checker{};
    ASSERT_TRUE((checker()));
  }

  {
    ::portable_stl::type_properties_helpers::is_unsigned<float>::type checker{};
    ASSERT_FALSE((checker()));
  }
  {
    ::portable_stl::is_unsigned<float> checker{};
    ASSERT_FALSE((checker()));
  }
  {
    ::portable_stl::is_unsigned<bool> checker{};
    ASSERT_TRUE((checker()));
  }

  ASSERT_FALSE((::portable_stl::is_unsigned<float>{}()));
  ASSERT_FALSE((::portable_stl::is_unsigned<std::int32_t>{}()));

  ASSERT_TRUE((::portable_stl::is_unsigned<std::uint32_t>{}()));
  ASSERT_TRUE((::portable_stl::is_unsigned<bool>{}()));

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_unsigned_inline_variables();
}

TEST(metaprogramming_type_properties, is_bounded_array) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::type_properties_helpers::is_bounded_array<std::int32_t>::type checker{};
    ASSERT_FALSE((checker()));
  }
  {
    ::portable_stl::type_properties_helpers::is_bounded_array<std::int32_t[1]>::type checker{};
    ASSERT_TRUE((checker()));
  }
  {
    ::portable_stl::is_bounded_array<std::int32_t> checker{};
    ASSERT_FALSE((checker()));
  }
  {
    ::portable_stl::is_bounded_array<std::int32_t[1]> checker{};
    ASSERT_TRUE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_bounded_array<std::int32_t>{}()));
  ASSERT_FALSE((::portable_stl::is_bounded_array<std::int32_t[]>{}()));
  ASSERT_TRUE((::portable_stl::is_bounded_array<std::int32_t[1]>{}()));
  test_metaprogramming_type_properties::metaprogramming_type_properties_is_bounded_array_inline_variables();
}

TEST(metaprogramming_type_properties, is_unbounded_array) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::type_properties_helpers::is_unbounded_array<std::int32_t>::type checker{};
    ASSERT_FALSE((checker()));
  }
  {
    ::portable_stl::type_properties_helpers::is_unbounded_array<std::int32_t[]>::type checker{};
    ASSERT_TRUE((checker()));
  }
  {
    ::portable_stl::is_unbounded_array<std::int32_t> checker{};
    ASSERT_FALSE((checker()));
  }
  {
    ::portable_stl::is_unbounded_array<std::int32_t[]> checker{};
    ASSERT_TRUE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_unbounded_array<std::int32_t>{}()));
  ASSERT_FALSE((::portable_stl::is_unbounded_array<std::int32_t[1]>{}()));
  ASSERT_TRUE((::portable_stl::is_unbounded_array<std::int32_t[]>{}()));
  test_metaprogramming_type_properties::metaprogramming_type_properties_is_unbounded_array_inline_variables();
}

TEST(metaprogramming_type_properties, is_scoped_enum) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_scoped_enum<metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>
      checker{};
    ASSERT_FALSE((checker()));
  }
  {
    ::portable_stl::is_scoped_enum<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::scopped_enum>
      checker{};
    ASSERT_TRUE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_scoped_enum<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>{}()));
  ASSERT_FALSE((::portable_stl::is_scoped_enum<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::unscopped_enum>{}()));
  ASSERT_TRUE((::portable_stl::is_scoped_enum<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::scopped_enum>{}()));
  test_metaprogramming_type_properties::metaprogramming_type_properties_is_scoped_enum_inline_variables();
}

TEST(metaprogramming_type_properties, is_constructible) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_constructible<metaprogramming_type_properties_helper::metaprogramming_type_properties_helper,
                                     std::int32_t>
      checker{};
    ASSERT_FALSE((checker()));
  }
  ASSERT_FALSE(
    (::portable_stl::is_constructible<metaprogramming_type_properties_helper::metaprogramming_type_properties_helper,
                                      std::int32_t>{}()));
  ASSERT_TRUE((::portable_stl::is_constructible<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class,
               std::int32_t>{}()));
  test_metaprogramming_type_properties::metaprogramming_type_properties_is_constructible_inline_variables();
}

TEST(metaprogramming_type_properties, is_default_constructible) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_default_constructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>
      checker{};
    ASSERT_TRUE((checker()));
  }
  ASSERT_TRUE((::portable_stl::is_default_constructible<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>{}()));
  ASSERT_TRUE((::portable_stl::is_default_constructible<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));
  test_metaprogramming_type_properties::metaprogramming_type_properties_is_default_constructible_inline_variables();
}

TEST(metaprogramming_type_properties, is_copy_constructible) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_copy_constructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>
      checker{};
    ASSERT_TRUE((checker()));
  }
  ASSERT_TRUE((::portable_stl::is_copy_constructible<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>{}()));
  ASSERT_TRUE((::portable_stl::is_copy_constructible<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));
  test_metaprogramming_type_properties::metaprogramming_type_properties_is_copy_constructible_inline_variables();
}

TEST(metaprogramming_type_properties, is_move_constructible) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_move_constructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>
      checker{};
    ASSERT_TRUE((checker()));
  }
  ASSERT_TRUE((::portable_stl::is_move_constructible<std::uint32_t>{}()));
  ASSERT_TRUE((::portable_stl::is_move_constructible<std::int32_t>{}()));
  ASSERT_TRUE((::portable_stl::is_move_constructible<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>{}()));
  ASSERT_TRUE((::portable_stl::is_move_constructible<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));
  test_metaprogramming_type_properties::metaprogramming_type_properties_is_move_constructible_inline_variables();
}

TEST(metaprogramming_type_properties, is_assignable) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_assignable<std::int32_t, std::int32_t> checker{};
    ASSERT_FALSE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_assignable<std::int32_t, std::int32_t>{}()));
  ASSERT_TRUE((::portable_stl::is_assignable<std::int32_t &, std::int32_t>{}()));
  ASSERT_FALSE((::portable_stl::is_assignable<float, float>{}()));
  ASSERT_TRUE((::portable_stl::is_assignable<float &, float>{}()));
  ASSERT_TRUE((::portable_stl::is_assignable<std::string, float>{}()));

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_assignable_inline_variables();
}

TEST(metaprogramming_type_properties, is_copy_assignable) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_copy_assignable<metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>
      checker{};
    ASSERT_TRUE((checker()));
  }
  ASSERT_TRUE((::portable_stl::is_copy_assignable<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>{}()));
  ASSERT_TRUE((::portable_stl::is_copy_assignable<std::int32_t>{}()));
  ASSERT_TRUE((::portable_stl::is_copy_assignable<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));
  test_metaprogramming_type_properties::metaprogramming_type_properties_is_copy_assignable_inline_variables();
}

TEST(metaprogramming_type_properties, is_move_assignable) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_move_assignable<metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>
      checker{};
    ASSERT_TRUE((checker()));
  }
  ASSERT_TRUE((::portable_stl::is_move_assignable<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>{}()));
  ASSERT_TRUE((::portable_stl::is_move_assignable<std::int32_t>{}()));
  ASSERT_TRUE((::portable_stl::is_move_assignable<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));
  test_metaprogramming_type_properties::metaprogramming_type_properties_is_move_assignable_inline_variables();
}

TEST(metaprogramming_type_properties, is_swappable_with) {
  static_cast<void>(test_info_);
  {
    metaprogramming_type_properties_helper::metaprogramming_type_properties_helper                  a{};
    metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class b{};
    a.value   = 1;
    b.value_a = 0;
    swap(a, b);
    ASSERT_EQ(0, a.value);
    ASSERT_EQ(1, b.value_a);
    swap(b, a);
    ASSERT_EQ(1, a.value);
    ASSERT_EQ(0, b.value_a);
  }
  {
    /**
     * @brief Test type.
     */
    using test_type = ::portable_stl::is_swappable_with_helpers::is_swappable_with_impl<std::int32_t &, std::int32_t &>;
    /**
     * @brief Test result type.
     */
    using result_type = typename test_type::type;
    EXPECT_TRUE((result_type{}()));

    EXPECT_TRUE(
      (::portable_stl::is_swappable_with_helpers::is_swappable_with_impl_t<std::int32_t &, std::int32_t &>{}()));
  }
  {
    typename ::portable_stl::is_swappable_with_helpers::is_swappable_with_impl<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper &,
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class &>::type checker{};
    ASSERT_FALSE(checker());
  }
  {
    typename ::portable_stl::is_swappable_with_helpers::is_swappable_with_impl<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class &,
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper &>::type checker{};
    ASSERT_FALSE(checker());
  }
  {
    typename ::portable_stl::is_swappable_with_helpers::is_swappable_with_impl<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper &,
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class &>::type
      checker{};
    ASSERT_TRUE(checker());
  }
  {
    typename ::portable_stl::is_swappable_with_helpers::is_swappable_with_impl<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class &,
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper &>::type checker{};
    ASSERT_TRUE(checker());
  }
  {
    ::portable_stl::is_swappable_with<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper &,
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class &>
      checker{};
    ASSERT_TRUE((checker()));
  }
  {
    ::portable_stl::is_swappable_with<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper &,
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class &>
      checker{};
    ASSERT_FALSE((checker()));
  }
  ASSERT_TRUE((::portable_stl::is_swappable_with<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper &,
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class &>{}()));
  ASSERT_FALSE((::portable_stl::is_swappable_with<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper &,
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class &>{}()));

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_swappable_with_inline_variables();
}

TEST(metaprogramming_type_properties, is_swappable) {
  static_cast<void>(test_info_);
  {
    metaprogramming_type_properties_helper::metaprogramming_type_properties_helper a{};
    metaprogramming_type_properties_helper::metaprogramming_type_properties_helper b{};
    a.value = 1;
    b.value = 0;
    swap(a, b);
    ASSERT_EQ(0, a.value);
    ASSERT_EQ(1, b.value);
    swap(b, a);
    ASSERT_EQ(1, a.value);
    ASSERT_EQ(0, b.value);
  }
  {
    ::portable_stl::is_swappable<metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>
      checker{};
    ASSERT_TRUE((checker()));
  }
  {
    ::portable_stl::is_swappable<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class>
      checker{};
    ASSERT_FALSE((checker()));
  }
  ASSERT_TRUE(
    (::portable_stl::is_swappable<metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>{}()));
  ASSERT_FALSE((::portable_stl::is_swappable<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class>{}()));

  // :: portable_stl :: swap should be accessable from is_swappable_with implementation !!!
  {
    std::int32_t a[5] = {1, 2, 3, 4, 5};
    std::int32_t b[5] = {1, 2, 3, 4, 5};
    ::portable_stl::swap(a, b);
  }

  EXPECT_TRUE((::portable_stl::is_swappable<std::int32_t>{}()));
  EXPECT_TRUE((::portable_stl::is_swappable<double>{}()));

  EXPECT_TRUE((::portable_stl::is_swappable<std::int32_t[4]>{}()));
  EXPECT_TRUE((::portable_stl::is_swappable<std::int32_t[2][3][4][5]>{}()));

  EXPECT_TRUE((::portable_stl::is_swappable<void (*)(std::int32_t, double)>{}()));

  // If T is not a complete type, (possibly cv-qualified) void, or an array of unknown bound, the behavior is undefined.
  // EXPECT_FALSE((::portable_stl::is_swappable<void>{}()));
  EXPECT_FALSE((::portable_stl::is_swappable<double[]>{}()));
  EXPECT_FALSE((::portable_stl::is_swappable<std::int32_t[][4]>{}()));
  EXPECT_FALSE((::portable_stl::is_swappable<void(std::int32_t, double)>{}()));

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_swappable_inline_variables();
}

TEST(metaprogramming_type_properties, is_destructible) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_destructible<std::int32_t &> checker{};
    ASSERT_TRUE((checker()));
  }
  {
    ::portable_stl::is_destructible<std::int32_t(std::int32_t)> checker{};
    ASSERT_FALSE((checker()));
  }
  {
    ::portable_stl::is_destructible<void> checker{};
    ASSERT_FALSE((checker()));
  }
  {
    ::portable_stl::is_destructible<std::int32_t[]> checker{};
    ASSERT_FALSE((checker()));
  }
  {
    ::portable_stl::is_destructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class>
      checker{};
    ASSERT_TRUE((checker()));
  }
  {
    ::portable_stl::is_destructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::not_destructor_class>
      checker{};
    ASSERT_FALSE((checker()));
  }
  ASSERT_TRUE((::portable_stl::is_destructible<std::int32_t &>{}()));
  ASSERT_FALSE((::portable_stl::is_destructible<std::int32_t(std::int32_t)>{}()));
  ASSERT_FALSE((::portable_stl::is_destructible<void>{}()));
  ASSERT_FALSE((::portable_stl::is_destructible<std::int32_t[]>{}()));
  ASSERT_TRUE((::portable_stl::is_destructible<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class>{}()));
  ASSERT_TRUE(
    (::portable_stl::is_destructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class[1]>{}()));
  ASSERT_TRUE(
    (::portable_stl::is_destructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class[1][1]>{}()));
  ASSERT_FALSE(
    (::portable_stl::is_destructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::not_destructor_class>{}()));

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_destructible_inline_variables();
}

TEST(metaprogramming_type_properties, is_trivially_constructible) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_trivially_constructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>
      checker{};
    ASSERT_FALSE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_trivially_constructible<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>{}()));

  ASSERT_TRUE((::portable_stl::is_trivially_constructible<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));
  ASSERT_FALSE((::portable_stl::is_trivially_constructible<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class,
                std::int32_t>{}()));

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_trivially_constructible_inline_variables();
}

TEST(metaprogramming_type_properties, is_trivially_default_constructible) {
  static_cast<void>(test_info_);

  {
    ::portable_stl::is_trivially_default_constructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>
      checker{};
    ASSERT_FALSE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_trivially_default_constructible<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>{}()));

  ASSERT_TRUE((::portable_stl::is_trivially_default_constructible<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));

  test_metaprogramming_type_properties::
    metaprogramming_type_properties_is_trivially_default_constructible_inline_variables();
}

TEST(metaprogramming_type_properties, is_trivially_copy_constructible) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_trivially_copy_constructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>
      checker{};
    ASSERT_FALSE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_trivially_copy_constructible<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>{}()));

  ASSERT_TRUE((::portable_stl::is_trivially_copy_constructible<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));

  test_metaprogramming_type_properties::
    metaprogramming_type_properties_is_trivially_copy_constructible_inline_variables();
}

TEST(metaprogramming_type_properties, is_trivially_move_constructible) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_trivially_move_constructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>
      checker{};
    ASSERT_FALSE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_trivially_move_constructible<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>{}()));

  ASSERT_TRUE((::portable_stl::is_trivially_move_constructible<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));

  test_metaprogramming_type_properties::
    metaprogramming_type_properties_is_trivially_move_constructible_inline_variables();
}

TEST(metaprogramming_type_properties, is_trivially_assignable) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_trivially_assignable<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper &,
      std::uint32_t>
      checker{};
    ASSERT_FALSE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_trivially_assignable<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper &,
                std::int32_t>{}()));

  ASSERT_TRUE((::portable_stl::is_trivially_assignable<std::int32_t &, std::int32_t>{}()));

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_trivially_assignable_inline_variables();
}

TEST(metaprogramming_type_properties, is_trivially_copy_assignable) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_trivially_copy_assignable<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>
      checker{};
    ASSERT_FALSE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_trivially_copy_assignable<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>{}()));

  ASSERT_TRUE((::portable_stl::is_trivially_copy_assignable<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_trivially_copy_assignable_inline_variables();
}

TEST(metaprogramming_type_properties, is_trivially_move_assignable) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_trivially_move_assignable<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>
      checker{};
    ASSERT_FALSE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_trivially_move_assignable<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>{}()));

  ASSERT_TRUE((::portable_stl::is_trivially_move_assignable<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_trivially_move_assignable_inline_variables();
}

TEST(metaprogramming_type_properties, is_trivially_destructible) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::is_trivially_destructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>
      checker{};
    ASSERT_FALSE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_trivially_destructible<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>{}()));

  ASSERT_TRUE((::portable_stl::is_trivially_destructible<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));
  test_metaprogramming_type_properties::metaprogramming_type_properties_is_trivially_destructible_inline_variables();
}

TEST(metaprogramming_type_properties, is_nothrow_constructible) {
  static_cast<void>(test_info_);
  {
    try {
      bool check_throw_flag{false};
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class const helper{
        check_throw_flag, false};
      ASSERT_EQ(0U, helper.check());
    } catch (std::runtime_error &) {
    }
  }
  {
    ASSERT_TRUE((::portable_stl::is_constructible<
                 metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>{}()));
    ::portable_stl::is_nothrow_constructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>
      checker{};
    ASSERT_FALSE((checker()));
  }
  {
    ASSERT_TRUE((::portable_stl::is_constructible<
                 metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class,
                 bool &,
                 bool>{}()));

    ::portable_stl::is_nothrow_constructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class,
      bool &,
      bool>
      checker{};
    ASSERT_FALSE((checker()));
  }
  {
    ::portable_stl::is_nothrow_constructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>
      checker{};
    ASSERT_TRUE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_nothrow_constructible<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>{}()));
  ASSERT_FALSE((::portable_stl::is_nothrow_constructible<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class,
                bool &,
                bool>{}()));
  ASSERT_TRUE((::portable_stl::is_nothrow_constructible<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_nothrow_constructible_inline_variables();
}

TEST(metaprogramming_type_properties, is_nothrow_default_constructible) {
  static_cast<void>(test_info_);
  {
    try {
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class const helper{};
      ASSERT_EQ(0U, helper.check());
    } catch (std::runtime_error &) {
    }
  }
  {
    ASSERT_TRUE((::portable_stl::is_default_constructible<
                 metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>{}()));
    ::portable_stl::is_nothrow_default_constructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>
      checker{};
    ASSERT_FALSE((checker()));
  }
  {
    ::portable_stl::is_nothrow_default_constructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>
      checker{};
    ASSERT_TRUE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_nothrow_default_constructible<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>{}()));
  ASSERT_TRUE((::portable_stl::is_nothrow_default_constructible<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));

  test_metaprogramming_type_properties::
    metaprogramming_type_properties_is_nothrow_default_constructible_inline_variables();
}

TEST(metaprogramming_type_properties, is_nothrow_copy_constructible) {
  static_cast<void>(test_info_);
  {
    try {
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class const helper{};
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class const helper2{helper};
      ASSERT_EQ(0U, helper.check());
      ASSERT_EQ(0U, helper2.check());
    } catch (std::runtime_error &) {
    }
  }
  {
    ASSERT_TRUE((::portable_stl::is_copy_constructible<
                 metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>{}()));
    ::portable_stl::is_nothrow_copy_constructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>
      checker{};
    ASSERT_FALSE((checker()));
  }
  {
    ::portable_stl::is_nothrow_copy_constructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>
      checker{};
    ASSERT_TRUE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_nothrow_copy_constructible<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>{}()));
  ASSERT_TRUE((::portable_stl::is_nothrow_copy_constructible<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));

  test_metaprogramming_type_properties::
    metaprogramming_type_properties_is_nothrow_copy_constructible_inline_variables();
}

TEST(metaprogramming_type_properties, is_nothrow_move_constructible) {
  static_cast<void>(test_info_);
  {
    try {
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class helper{};
      ASSERT_EQ(0U, helper.check());
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class const helper2{
        std::move(helper)};
      ASSERT_EQ(0U, helper2.check());
    } catch (std::runtime_error &) {
    }
  }
  {
    ASSERT_TRUE((::portable_stl::is_move_constructible<
                 metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>{}()));
    ::portable_stl::is_nothrow_move_constructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>
      checker{};
    ASSERT_FALSE((checker()));
  }
  {
    ::portable_stl::is_nothrow_move_constructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>
      checker{};
    ASSERT_TRUE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_nothrow_move_constructible<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>{}()));
  ASSERT_TRUE((::portable_stl::is_nothrow_move_constructible<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));

  test_metaprogramming_type_properties::
    metaprogramming_type_properties_is_nothrow_move_constructible_inline_variables();
}

TEST(metaprogramming_type_properties, is_nothrow_assignable) {
  static_cast<void>(test_info_);
  {
    try {
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class helper{};
      ASSERT_EQ(0U, helper.check());
      helper = 0;
      ASSERT_EQ(0U, helper.check());
    } catch (std::runtime_error &) {
    }
  }
  {
    ASSERT_TRUE((::portable_stl::is_assignable<
                 metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class &,
                 std::int32_t>{}()));
    ::portable_stl::is_nothrow_assignable<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class &,
      std::int32_t>
      checker{};
    ASSERT_FALSE((checker()));
  }
  {
    ::portable_stl::is_nothrow_assignable<std::int32_t &, std::int32_t> checker{};
    ASSERT_TRUE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_nothrow_assignable<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class &,
                std::int32_t>{}()));
  ASSERT_TRUE((::portable_stl::is_nothrow_assignable<std::int32_t &, std::int32_t>{}()));

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_nothrow_assignable_inline_variables();
}

TEST(metaprogramming_type_properties, is_nothrow_copy_assignable) {
  static_cast<void>(test_info_);
  {
    try {
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class const helper{};
      ASSERT_EQ(0U, helper.check());
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class helper2{};
      ASSERT_EQ(0U, helper2.check());
      helper2 = helper;
      ASSERT_EQ(0U, helper2.check());
    } catch (std::runtime_error &) {
    }
  }
  {
    ASSERT_TRUE((::portable_stl::is_copy_assignable<
                 metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>{}()));
    ::portable_stl::is_nothrow_copy_assignable<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>
      checker{};
    ASSERT_FALSE((checker()));
  }
  {
    ::portable_stl::is_nothrow_copy_assignable<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>
      checker{};
    ASSERT_TRUE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_nothrow_copy_assignable<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>{}()));
  ASSERT_TRUE((::portable_stl::is_nothrow_copy_assignable<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_nothrow_copy_assignable_inline_variables();
}

TEST(metaprogramming_type_properties, is_nothrow_move_assignable) {
  static_cast<void>(test_info_);
  {
    try {
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class helper{};
      ASSERT_EQ(0U, helper.check());
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class helper2{};
      ASSERT_EQ(0U, helper2.check());
      helper2 = std::move(helper);
      ASSERT_EQ(0U, helper2.check());
    } catch (std::runtime_error &) {
    }
  }
  {
    ASSERT_TRUE((::portable_stl::is_move_assignable<
                 metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>{}()));
    ::portable_stl::is_nothrow_move_assignable<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>
      checker{};
    ASSERT_FALSE((checker()));
  }
  {
    ::portable_stl::is_nothrow_move_assignable<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>
      checker{};
    ASSERT_TRUE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_nothrow_move_assignable<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>{}()));
  ASSERT_TRUE((::portable_stl::is_nothrow_move_assignable<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_nothrow_move_assignable_inline_variables();
}

TEST(metaprogramming_type_properties, is_nothrow_swappable_with) {
  static_cast<void>(test_info_);
  {
    try {
      std::int32_t                                                                                value{0};
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class helper{};
      swap(value, helper);
      swap(helper, value);
      ASSERT_EQ(0U, helper.check());
    } catch (std::runtime_error &) {
    }
  }
  {
    ASSERT_FALSE((::portable_stl::is_swappable_with<
                  metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class &,
                  metaprogramming_type_properties_helper::metaprogramming_type_properties_helper &>{}()));
    ::portable_stl::is_nothrow_swappable_with<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class &,
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper &>
      checker{};
    ASSERT_FALSE((checker()));
  }
  {
    ASSERT_TRUE((::portable_stl::is_swappable_with<
                 metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class &,
                 std::int32_t &>{}()));
    ::portable_stl::is_nothrow_swappable_with<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class &,
      std::int32_t &>
      checker{};
    ASSERT_FALSE((checker()));
  }
  {
    ::portable_stl::is_nothrow_swappable_with<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper &,
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class &>
      checker{};
    ASSERT_TRUE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_nothrow_swappable_with<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class &,
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper &>{}()));
  ASSERT_FALSE((::portable_stl::is_nothrow_swappable_with<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class &,
                std::int32_t &>{}()));
  ASSERT_TRUE((::portable_stl::is_nothrow_swappable_with<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper &,
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class &>{}()));

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_nothrow_swappable_with_inline_variables();
}

TEST(metaprogramming_type_properties, is_nothrow_swappable) {
  static_cast<void>(test_info_);
  {
    try {
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class helper{};
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class helper2{};
      swap(helper, helper2);
      ASSERT_EQ(0U, helper.check());
      ASSERT_EQ(0U, helper2.check());
    } catch (std::runtime_error &) {
    }
  }

  {
    ASSERT_TRUE((::portable_stl::is_swappable<
                 metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>{}()));
    ::portable_stl::is_nothrow_swappable<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>
      checker{};
    ASSERT_FALSE((checker()));
  }
  {
    ::portable_stl::is_nothrow_swappable<metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>
      checker{};
    ASSERT_TRUE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_nothrow_swappable<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class>{}()));
  ASSERT_FALSE((::portable_stl::is_nothrow_swappable<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>{}()));
  ASSERT_TRUE((::portable_stl::is_nothrow_swappable<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>{}()));

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_nothrow_swappable_inline_variables();
}

TEST(metaprogramming_type_properties, is_nothrow_destructible) {
  static_cast<void>(test_info_);
  {
    try {
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class helper{};
      ASSERT_EQ(0U, helper.check());
    } catch (std::runtime_error &) {
    }
  }
  {
    ASSERT_TRUE((::portable_stl::is_destructible<
                 metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>{}()));
    ::portable_stl::is_nothrow_destructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>
      checker{};
    ASSERT_FALSE((checker()));
  }
  {
    ::portable_stl::is_nothrow_destructible<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>
      checker{};
    ASSERT_TRUE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_nothrow_destructible<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>{}()));
  ASSERT_TRUE((::portable_stl::is_nothrow_destructible<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>{}()));

  test_metaprogramming_type_properties::metaprogramming_type_properties_is_nothrow_destructible_inline_variables();
}

/*
  (since C++23) There is no realization in clang/gcc/msvc on 2023-11-30
*/
TEST(metaprogramming_type_properties, is_implicit_lifetime) {
  static_cast<void>(test_info_);
  test_metaprogramming_type_properties::metaprogramming_type_properties_is_implicit_lifetime_inline_variables();
}

TEST(metaprogramming_type_properties, has_virtual_destructor) {
  static_cast<void>(test_info_);
  {
    ::portable_stl::has_virtual_destructor<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>
      checker{};
    ASSERT_FALSE(checker());
  }

  ASSERT_FALSE(::portable_stl::has_virtual_destructor<void>{}());
  ASSERT_FALSE(::portable_stl::has_virtual_destructor<std::int32_t>{}());
  ASSERT_FALSE(::portable_stl::has_virtual_destructor<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}());
  ASSERT_TRUE(::portable_stl::has_virtual_destructor<
              metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>{}());
  ASSERT_TRUE(::portable_stl::has_virtual_destructor<
              metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::pure_virtual_class>{}());
  ASSERT_TRUE(
    ::portable_stl::has_virtual_destructor<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::inheritor_virtual_class>{}());

  test_metaprogramming_type_properties::metaprogramming_type_properties_has_virtual_destructor_inline_variables();
}

TEST(metaprogramming_type_properties, has_unique_object_representations) {
  static_cast<void>(test_info_);

  test_metaprogramming_type_properties::
    metaprogramming_type_properties_has_unique_object_representations_inline_variables();

  test_metaprogramming_type_properties::metaprogramming_type_properties_has_unique_object_representations();
}

/*
  (since C++23) There is no realization in clang/msvc on 2023-11-30
*/
TEST(metaprogramming_type_properties, reference_constructs_from_temporary) {
  static_cast<void>(test_info_);
  test_metaprogramming_type_properties::
    metaprogramming_type_properties_reference_constructs_from_temporary_inline_variables();
}

/*
  (since C++23) There is no realization in clang/gcc/msvc on 2023-11-30
*/
TEST(metaprogramming_type_properties, reference_converts_from_temporary) {
  static_cast<void>(test_info_);
  test_metaprogramming_type_properties::
    metaprogramming_type_properties_reference_converts_from_temporary_inline_variables();
}
