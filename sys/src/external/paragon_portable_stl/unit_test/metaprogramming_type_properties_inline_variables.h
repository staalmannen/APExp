// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_type_properties_inline_variables.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_METAPROGRAMMING_TYPE_PROPERTIES_INLINE_VARIABLES_H
#define PSTL_METAPROGRAMMING_TYPE_PROPERTIES_INLINE_VARIABLES_H

#include <gtest/gtest.h>

#include "metaprogramming_type_properties_helper.h"
#include "portable_stl/metaprogramming/type_properties/has_unique_object_representations_v.h"
#include "portable_stl/metaprogramming/type_properties/has_virtual_destructor_v.h"
#include "portable_stl/metaprogramming/type_properties/is_abstract_v.h"
#include "portable_stl/metaprogramming/type_properties/is_aggregate_v.h"
#include "portable_stl/metaprogramming/type_properties/is_assignable_v.h"
#include "portable_stl/metaprogramming/type_properties/is_bounded_array_v.h"
#include "portable_stl/metaprogramming/type_properties/is_const_v.h"
#include "portable_stl/metaprogramming/type_properties/is_constructible_v.h"
#include "portable_stl/metaprogramming/type_properties/is_copy_assignable_v.h"
#include "portable_stl/metaprogramming/type_properties/is_copy_constructible_v.h"
#include "portable_stl/metaprogramming/type_properties/is_default_constructible_v.h"
#include "portable_stl/metaprogramming/type_properties/is_destructible_v.h"
#include "portable_stl/metaprogramming/type_properties/is_empty_v.h"
#include "portable_stl/metaprogramming/type_properties/is_final_v.h"
#include "portable_stl/metaprogramming/type_properties/is_implicit_lifetime_v.h"
#include "portable_stl/metaprogramming/type_properties/is_lvalue_referenceable_v.h"
#include "portable_stl/metaprogramming/type_properties/is_move_assignable_v.h"
#include "portable_stl/metaprogramming/type_properties/is_move_constructible_v.h"
#include "portable_stl/metaprogramming/type_properties/is_nothrow_assignable_v.h"
#include "portable_stl/metaprogramming/type_properties/is_nothrow_constructible_v.h"
#include "portable_stl/metaprogramming/type_properties/is_nothrow_copy_assignable_v.h"
#include "portable_stl/metaprogramming/type_properties/is_nothrow_copy_constructible_v.h"
#include "portable_stl/metaprogramming/type_properties/is_nothrow_default_constructible_v.h"
#include "portable_stl/metaprogramming/type_properties/is_nothrow_destructible_v.h"
#include "portable_stl/metaprogramming/type_properties/is_nothrow_move_assignable_v.h"
#include "portable_stl/metaprogramming/type_properties/is_nothrow_move_constructible_v.h"
#include "portable_stl/metaprogramming/type_properties/is_nothrow_swappable_v.h"
#include "portable_stl/metaprogramming/type_properties/is_nothrow_swappable_with_v.h"
#include "portable_stl/metaprogramming/type_properties/is_polymorphic_v.h"
#include "portable_stl/metaprogramming/type_properties/is_rvalue_referenceable_v.h"
#include "portable_stl/metaprogramming/type_properties/is_scoped_enum_v.h"
#include "portable_stl/metaprogramming/type_properties/is_signed_v.h"
#include "portable_stl/metaprogramming/type_properties/is_standard_layout_v.h"
#include "portable_stl/metaprogramming/type_properties/is_swappable_v.h"
#include "portable_stl/metaprogramming/type_properties/is_trivial_v.h"
#include "portable_stl/metaprogramming/type_properties/is_trivially_assignable_v.h"
#include "portable_stl/metaprogramming/type_properties/is_trivially_constructible_v.h"
#include "portable_stl/metaprogramming/type_properties/is_trivially_copy_assignable_v.h"
#include "portable_stl/metaprogramming/type_properties/is_trivially_copy_constructible_v.h"
#include "portable_stl/metaprogramming/type_properties/is_trivially_copyable_v.h"
#include "portable_stl/metaprogramming/type_properties/is_trivially_default_constructible_v.h"
#include "portable_stl/metaprogramming/type_properties/is_trivially_destructible_v.h"
#include "portable_stl/metaprogramming/type_properties/is_trivially_move_assignable_v.h"
#include "portable_stl/metaprogramming/type_properties/is_trivially_move_constructible_v.h"
#include "portable_stl/metaprogramming/type_properties/is_unbounded_array_v.h"
#include "portable_stl/metaprogramming/type_properties/is_unsigned_v.h"
#include "portable_stl/metaprogramming/type_properties/is_volatile_v.h"
#include "portable_stl/metaprogramming/type_properties/reference_constructs_from_temporary_v.h"
#include "portable_stl/metaprogramming/type_properties/reference_converts_from_temporary_v.h"

namespace test_metaprogramming_type_properties {
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_lvalue_referenceable_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_lvalue_referenceable_v<void>));
  ASSERT_TRUE((::portable_stl::is_lvalue_referenceable_v<std::uint32_t>));
  ASSERT_TRUE((::portable_stl::is_lvalue_referenceable_v<void *>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_rvalue_referenceable_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_rvalue_referenceable_v<void>));
  ASSERT_TRUE((::portable_stl::is_rvalue_referenceable_v<std::uint32_t>));
  ASSERT_TRUE((::portable_stl::is_rvalue_referenceable_v<void *>));
}

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_const_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_const_v<std::int32_t const volatile>));
  ASSERT_FALSE((::portable_stl::is_const_v<std::int32_t const *>));
  ASSERT_FALSE((::portable_stl::is_const_v<std::int32_t const &>));
  ASSERT_FALSE((::portable_stl::is_const_v<std::int32_t[3]>));
  ASSERT_TRUE((::portable_stl::is_const_v<std::int32_t const[3]>));
}

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_volatile_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_volatile_v<std::int32_t const volatile>));
  ASSERT_FALSE((::portable_stl::is_volatile_v<std::int32_t volatile *>));
  ASSERT_FALSE((::portable_stl::is_volatile_v<std::int32_t volatile &>));
  ASSERT_FALSE((::portable_stl::is_volatile_v<std::int32_t[3]>));
  ASSERT_TRUE((::portable_stl::is_volatile_v<std::int32_t volatile[3]>));
}

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_trivial_inline_variables() {
  ASSERT_FALSE(
    (::portable_stl::is_trivial_v<metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>));
  ASSERT_TRUE((::portable_stl::is_trivial_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_trivially_copyable_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_trivially_copyable_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>));
  ASSERT_TRUE((::portable_stl::is_trivially_copyable_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
  ASSERT_FALSE((::portable_stl::is_trivially_copyable_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_standard_layout_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_standard_layout_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
  ASSERT_FALSE((::portable_stl::is_standard_layout_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>));
  ASSERT_TRUE((::portable_stl::is_standard_layout_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_empty_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_empty_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
  ASSERT_FALSE((::portable_stl::is_empty_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>));
  ASSERT_FALSE(
    (::portable_stl::is_empty_v<metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_polymorphic_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_polymorphic_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
  ASSERT_TRUE((::portable_stl::is_polymorphic_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>));
  ASSERT_TRUE((::portable_stl::is_polymorphic_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::pure_virtual_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_abstract_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_abstract_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
  ASSERT_FALSE((::portable_stl::is_abstract_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>));
  ASSERT_TRUE((::portable_stl::is_abstract_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::pure_virtual_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_final_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_final_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>));
  ASSERT_TRUE((::portable_stl::is_final_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_aggregate_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_aggregate_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>));
  ASSERT_FALSE((::portable_stl::is_aggregate_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
  ASSERT_FALSE(
    (::portable_stl::is_aggregate_v<metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>));

  ASSERT_TRUE((::portable_stl::is_aggregate_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_signed_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_signed_v<bool>));
  ASSERT_FALSE((::portable_stl::is_signed_v<std::uint32_t>));

  ASSERT_TRUE((::portable_stl::is_signed_v<std::int32_t>));
  ASSERT_TRUE((::portable_stl::is_signed_v<float>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_unsigned_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_unsigned_v<bool>));
  ASSERT_TRUE((::portable_stl::is_unsigned_v<std::uint32_t>));

  ASSERT_FALSE((::portable_stl::is_unsigned_v<std::int32_t>));
  ASSERT_FALSE((::portable_stl::is_unsigned_v<float>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_bounded_array_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_bounded_array_v<std::int32_t>));
  ASSERT_FALSE((::portable_stl::is_bounded_array_v<std::int32_t[]>));
  ASSERT_TRUE((::portable_stl::is_bounded_array_v<std::int32_t[1]>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_unbounded_array_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_unbounded_array_v<std::int32_t>));
  ASSERT_FALSE((::portable_stl::is_unbounded_array_v<std::int32_t[1]>));
  ASSERT_TRUE((::portable_stl::is_unbounded_array_v<std::int32_t[]>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_scoped_enum_inline_variables() {
  ASSERT_FALSE(
    (::portable_stl::is_scoped_enum_v<metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>));
  ASSERT_FALSE((::portable_stl::is_scoped_enum_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::unscopped_enum>));
  ASSERT_TRUE((::portable_stl::is_scoped_enum_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::scopped_enum>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_constructible_inline_variables() {
  ASSERT_FALSE(
    (::portable_stl::is_constructible_v<metaprogramming_type_properties_helper::metaprogramming_type_properties_helper,
                                        std::int32_t>));
  ASSERT_TRUE((::portable_stl::is_constructible_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class,
               std::int32_t>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_default_constructible_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_default_constructible_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>));
  ASSERT_TRUE((::portable_stl::is_default_constructible_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_copy_constructible_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_copy_constructible_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>));
  ASSERT_TRUE((::portable_stl::is_copy_constructible_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_move_constructible_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_move_constructible_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>));
  ASSERT_TRUE((::portable_stl::is_move_constructible_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_assignable_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_assignable_v<std::int32_t, std::int32_t>));
  ASSERT_TRUE((::portable_stl::is_assignable_v<std::int32_t &, std::int32_t>));
  ASSERT_FALSE((::portable_stl::is_assignable_v<float, float>));
  ASSERT_TRUE((::portable_stl::is_assignable_v<float &, float>));
  ASSERT_TRUE((::portable_stl::is_assignable_v<std::string, float>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_copy_assignable_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_copy_assignable_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>));
  ASSERT_TRUE((::portable_stl::is_copy_assignable_v<std::int32_t>));
  ASSERT_TRUE((::portable_stl::is_copy_assignable_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_move_assignable_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_move_assignable_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>));
  ASSERT_TRUE((::portable_stl::is_move_assignable_v<std::int32_t>));
  ASSERT_TRUE((::portable_stl::is_move_assignable_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_swappable_with_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_swappable_with_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper &,
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class &>));
  ASSERT_FALSE((::portable_stl::is_swappable_with_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper &,
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class &>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_swappable_inline_variables() {
  ASSERT_TRUE(
    (::portable_stl::is_swappable_v<metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>));
  ASSERT_FALSE((::portable_stl::is_swappable_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class>));

  EXPECT_TRUE((::portable_stl::is_swappable_v<std::int32_t>));
  EXPECT_TRUE((::portable_stl::is_swappable_v<double>));
  EXPECT_TRUE((::portable_stl::is_swappable_v<std::int32_t[4]>));
  EXPECT_TRUE((::portable_stl::is_swappable_v<std::int32_t[2][3][4][5]>));
  EXPECT_TRUE((::portable_stl::is_swappable_v<void (*)(std::int32_t, double)>));

  // EXPECT_FALSE((::portable_stl::is_swappable_v<void>));
  EXPECT_FALSE((::portable_stl::is_swappable_v<double[]>));
  EXPECT_FALSE((::portable_stl::is_swappable_v<std::int32_t[][4]>));
  EXPECT_FALSE((::portable_stl::is_swappable_v<void(std::int32_t, double)>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_destructible_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_destructible_v<std::int32_t &>));
  ASSERT_FALSE((::portable_stl::is_destructible_v<std::int32_t(std::int32_t)>));
  ASSERT_FALSE((::portable_stl::is_destructible_v<void>));
  ASSERT_FALSE((::portable_stl::is_destructible_v<std::int32_t[]>));
  ASSERT_TRUE((::portable_stl::is_destructible_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class>));
  ASSERT_TRUE((::portable_stl::is_destructible_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class[1]>));
  ASSERT_TRUE((::portable_stl::is_destructible_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class[1][1]>));
  ASSERT_FALSE((::portable_stl::is_destructible_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::not_destructor_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_trivially_constructible_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_trivially_constructible_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>));

  ASSERT_TRUE((::portable_stl::is_trivially_constructible_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
  ASSERT_FALSE((::portable_stl::is_trivially_constructible_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class,
                std::int32_t>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_trivially_default_constructible_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_trivially_default_constructible_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>));

  ASSERT_TRUE((::portable_stl::is_trivially_default_constructible_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_trivially_copy_constructible_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_trivially_copy_constructible_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>));

  ASSERT_TRUE((::portable_stl::is_trivially_copy_constructible_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_trivially_move_constructible_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_trivially_move_constructible_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>));

  ASSERT_TRUE((::portable_stl::is_trivially_move_constructible_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_trivially_assignable_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_trivially_assignable_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper &,
                std::int32_t>));

  ASSERT_TRUE((::portable_stl::is_trivially_assignable_v<std::int32_t &, std::int32_t>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_trivially_copy_assignable_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_trivially_copy_assignable_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>));

  ASSERT_TRUE((::portable_stl::is_trivially_copy_assignable_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_trivially_move_assignable_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_trivially_move_assignable_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>));

  ASSERT_TRUE((::portable_stl::is_trivially_move_assignable_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_trivially_destructible_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_trivially_destructible_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>));

  ASSERT_TRUE((::portable_stl::is_trivially_destructible_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_nothrow_constructible_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_nothrow_constructible_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>));
  ASSERT_FALSE((::portable_stl::is_nothrow_constructible_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class,
                bool &,
                bool>));
  ASSERT_TRUE((::portable_stl::is_nothrow_constructible_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_nothrow_default_constructible_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_nothrow_default_constructible_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>));
  ASSERT_TRUE((::portable_stl::is_nothrow_default_constructible_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_nothrow_copy_constructible_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_nothrow_copy_constructible_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>));
  ASSERT_TRUE((::portable_stl::is_nothrow_copy_constructible_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_nothrow_move_constructible_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_nothrow_move_constructible_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>));
  ASSERT_TRUE((::portable_stl::is_nothrow_move_constructible_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_nothrow_assignable_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_nothrow_assignable_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class &,
                std::int32_t>));
  ASSERT_TRUE((::portable_stl::is_nothrow_assignable_v<std::int32_t &, std::int32_t>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_nothrow_copy_assignable_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_nothrow_copy_assignable_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>));
  ASSERT_TRUE((::portable_stl::is_nothrow_copy_assignable_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_nothrow_move_assignable_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_nothrow_move_assignable_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>));
  ASSERT_TRUE((::portable_stl::is_nothrow_move_assignable_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_nothrow_swappable_with_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_nothrow_swappable_with_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class &,
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper &>));
  ASSERT_FALSE((::portable_stl::is_nothrow_swappable_with_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class &,
                std::int32_t &>));
  ASSERT_TRUE((::portable_stl::is_nothrow_swappable_with_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper &,
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class &>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_nothrow_swappable_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_nothrow_swappable_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class>));
  ASSERT_FALSE((::portable_stl::is_nothrow_swappable_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>));
  ASSERT_TRUE((::portable_stl::is_nothrow_swappable_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_nothrow_destructible_inline_variables() {
  ASSERT_FALSE((::portable_stl::is_nothrow_destructible_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::throw_class>));
  ASSERT_TRUE((::portable_stl::is_nothrow_destructible_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_implicit_lifetime_inline_variables() {
  ASSERT_TRUE(true);
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_has_virtual_destructor_inline_variables() {
  ASSERT_FALSE((::portable_stl::has_virtual_destructor_v<void>));
  ASSERT_FALSE((::portable_stl::has_virtual_destructor_v<std::int32_t>));
  ASSERT_FALSE((::portable_stl::has_virtual_destructor_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>));
  ASSERT_TRUE((::portable_stl::has_virtual_destructor_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>));
  ASSERT_TRUE((::portable_stl::has_virtual_destructor_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::pure_virtual_class>));
  ASSERT_TRUE(
    (::portable_stl::has_virtual_destructor_v<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::inheritor_virtual_class>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_has_unique_object_representations_inline_variables() {
  ASSERT_FALSE((::portable_stl::has_unique_object_representations_v<float>));
  ASSERT_TRUE((::portable_stl::has_unique_object_representations_v<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::unpadded>));
  ASSERT_FALSE((::portable_stl::has_unique_object_representations_v<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::likely_padded>));
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_reference_constructs_from_temporary_inline_variables() {
  ASSERT_TRUE(true);
}
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_reference_converts_from_temporary_inline_variables() {
  ASSERT_TRUE(true);
}
} // namespace test_metaprogramming_type_properties

#endif // PSTL_METAPROGRAMMING_TYPE_PROPERTIES_INLINE_VARIABLES_H
