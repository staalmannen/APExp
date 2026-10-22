// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_type_property_queries_inline_variables.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_METAPROGRAMMING_TYPE_PROPERTY_QUERIES_INLINE_VARIABLES_H
#define PSTL_METAPROGRAMMING_TYPE_PROPERTY_QUERIES_INLINE_VARIABLES_H

#include <gtest/gtest.h>

#include <portable_stl/metaprogramming/type_property_queries/alignment_of_v.h>
#include <portable_stl/metaprogramming/type_property_queries/extent_v.h>
#include <portable_stl/metaprogramming/type_property_queries/rank_v.h>

#include "metaprogramming_type_property_queries_helper.h"

namespace test_metaprogramming_type_property_queries {

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_propery_queries_alignment_of_inline_variables() {
  EXPECT_EQ(metaprogramming_type_property_queries_helper::ALIGN_8,
            (::portable_stl::alignment_of_v<metaprogramming_type_property_queries_helper::user_char8_t>));
  EXPECT_EQ(metaprogramming_type_property_queries_helper::ALIGN_8, (::portable_stl::alignment_of_v<std::uint8_t>));
  EXPECT_EQ(metaprogramming_type_property_queries_helper::ALIGN_16, (::portable_stl::alignment_of_v<std::uint16_t>));
  EXPECT_EQ(metaprogramming_type_property_queries_helper::ALIGN_32, (::portable_stl::alignment_of_v<std::uint32_t>));
  EXPECT_GE(metaprogramming_type_property_queries_helper::ALIGN_64, (::portable_stl::alignment_of_v<std::uint64_t>));
  EXPECT_EQ(metaprogramming_type_property_queries_helper::ALIGN_8,
            (::portable_stl::alignment_of_v<metaprogramming_type_property_queries_helper::Empty>));
  EXPECT_EQ(metaprogramming_type_property_queries_helper::ALIGN_8,
            (::portable_stl::alignment_of_v<metaprogramming_type_property_queries_helper::user_char8_t &>));
  EXPECT_EQ(metaprogramming_type_property_queries_helper::ALIGN_8, (::portable_stl::alignment_of_v<std::uint8_t &>));
  EXPECT_EQ(metaprogramming_type_property_queries_helper::ALIGN_16, (::portable_stl::alignment_of_v<std::uint16_t &>));
  EXPECT_EQ(metaprogramming_type_property_queries_helper::ALIGN_32, (::portable_stl::alignment_of_v<std::uint32_t &>));
  EXPECT_GE(metaprogramming_type_property_queries_helper::ALIGN_64, (::portable_stl::alignment_of_v<std::uint64_t &>));
  EXPECT_EQ(metaprogramming_type_property_queries_helper::ALIGN_8,
            (::portable_stl::alignment_of_v<metaprogramming_type_property_queries_helper::Empty &>));
}

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_propery_queries_rank_inline_variables() {
  EXPECT_EQ(0U, (::portable_stl::rank_v<std::int32_t>));
  EXPECT_EQ(1U, (::portable_stl::rank_v<std::int32_t[]>));
  EXPECT_EQ(1U, (::portable_stl::rank_v<std::int32_t[metaprogramming_type_property_queries_helper::USER_VALUE_9]>));
  EXPECT_EQ(metaprogramming_type_property_queries_helper::USER_VALUE_2,
            (::portable_stl::rank_v<std::int32_t[1][metaprogramming_type_property_queries_helper::USER_VALUE_2]>));
  EXPECT_EQ(metaprogramming_type_property_queries_helper::USER_VALUE_2, (::portable_stl::rank_v<std::int32_t[][1]>));
  EXPECT_EQ(metaprogramming_type_property_queries_helper::USER_VALUE_3,
            (::portable_stl::rank_v<std::int32_t[1][metaprogramming_type_property_queries_helper::USER_VALUE_2]
                                                [metaprogramming_type_property_queries_helper::USER_VALUE_3]>));
  EXPECT_EQ(metaprogramming_type_property_queries_helper::USER_VALUE_3,
            (::portable_stl::rank_v<std::int32_t[][1][metaprogramming_type_property_queries_helper::USER_VALUE_2]>));
}

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_propery_queries_extent_inline_variables() {
  EXPECT_EQ(0U, (::portable_stl::extent_v<std::int32_t>));
  EXPECT_EQ(0U, (::portable_stl::extent_v<std::int32_t[]>));
  EXPECT_EQ(metaprogramming_type_property_queries_helper::USER_VALUE_9,
            (::portable_stl::extent_v<std::int32_t[metaprogramming_type_property_queries_helper::USER_VALUE_9]>));
  EXPECT_EQ(metaprogramming_type_property_queries_helper::USER_VALUE_9,
            (::portable_stl::extent_v<std::int32_t[metaprogramming_type_property_queries_helper::USER_VALUE_9], 0>));
  EXPECT_EQ(0U,
            (::portable_stl::extent_v<std::int32_t[metaprogramming_type_property_queries_helper::USER_VALUE_9], 1>));

  EXPECT_EQ(metaprogramming_type_property_queries_helper::USER_VALUE_9,
            (::portable_stl::extent_v<std::int32_t[metaprogramming_type_property_queries_helper::USER_VALUE_9][1]>));
  EXPECT_EQ(metaprogramming_type_property_queries_helper::USER_VALUE_9,
            (::portable_stl::extent_v<std::int32_t[metaprogramming_type_property_queries_helper::USER_VALUE_9][1], 0>));
  EXPECT_EQ(metaprogramming_type_property_queries_helper::USER_VALUE_9,
            (::portable_stl::extent_v<std::int32_t[1][metaprogramming_type_property_queries_helper::USER_VALUE_9], 1>));
  EXPECT_EQ(0U,
            (::portable_stl::extent_v<std::int32_t[1][metaprogramming_type_property_queries_helper::USER_VALUE_9],
                                      metaprogramming_type_property_queries_helper::USER_VALUE_2>));
  EXPECT_EQ(0U, (::portable_stl::extent_v<std::int32_t[][metaprogramming_type_property_queries_helper::USER_VALUE_2]>));
  EXPECT_EQ(0U,
            (::portable_stl::extent_v<std::int32_t[][metaprogramming_type_property_queries_helper::USER_VALUE_2], 0>));
}
} // namespace test_metaprogramming_type_property_queries

#endif // PSTL_METAPROGRAMMING_TYPE_PROPERTY_QUERIES_INLINE_VARIABLES_H
