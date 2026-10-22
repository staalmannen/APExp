// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_type_property_queries.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "metaprogramming_type_property_queries_helper.h"
#include "portable_stl/metaprogramming/type_property_queries/alignment_of.h"
#include "portable_stl/metaprogramming/type_property_queries/extent.h"
#include "portable_stl/metaprogramming/type_property_queries/rank.h"

#if defined(__cpp_inline_variables)
#  include "metaprogramming_type_property_queries_inline_variables.h"
#else
#  include "metaprogramming_type_property_queries.h"
#endif

TEST(metaprogramming_type_property_queries, alignment_of) {
  static_cast<void>(test_info_);
  {
    constexpr ::portable_stl::alignment_of<std::uint32_t> checker{};
    EXPECT_EQ(metaprogramming_type_property_queries_helper::ALIGN_32, checker());
    static_cast<void>(checker);
  }

  EXPECT_EQ(metaprogramming_type_property_queries_helper::ALIGN_8,
            ::portable_stl::alignment_of<metaprogramming_type_property_queries_helper::user_char8_t>{}());
  EXPECT_EQ(metaprogramming_type_property_queries_helper::ALIGN_8, ::portable_stl::alignment_of<std::uint8_t>{}());
  EXPECT_EQ(metaprogramming_type_property_queries_helper::ALIGN_16, ::portable_stl::alignment_of<std::uint16_t>{}());
  EXPECT_EQ(metaprogramming_type_property_queries_helper::ALIGN_32, ::portable_stl::alignment_of<std::uint32_t>{}());
  EXPECT_GE(metaprogramming_type_property_queries_helper::ALIGN_64, ::portable_stl::alignment_of<std::uint64_t>{}());
  EXPECT_EQ(metaprogramming_type_property_queries_helper::ALIGN_8,
            ::portable_stl::alignment_of<metaprogramming_type_property_queries_helper::Empty>{}());
  EXPECT_EQ(metaprogramming_type_property_queries_helper::ALIGN_8,
            ::portable_stl::alignment_of<metaprogramming_type_property_queries_helper::user_char8_t &>{}());
  EXPECT_EQ(metaprogramming_type_property_queries_helper::ALIGN_8, ::portable_stl::alignment_of<std::uint8_t &>{}());
  EXPECT_EQ(metaprogramming_type_property_queries_helper::ALIGN_16, ::portable_stl::alignment_of<std::uint16_t &>{}());
  EXPECT_EQ(metaprogramming_type_property_queries_helper::ALIGN_32, ::portable_stl::alignment_of<std::uint32_t &>{}());
  EXPECT_GE(metaprogramming_type_property_queries_helper::ALIGN_64, ::portable_stl::alignment_of<std::uint64_t &>{}());
  EXPECT_EQ(metaprogramming_type_property_queries_helper::ALIGN_8,
            ::portable_stl::alignment_of<metaprogramming_type_property_queries_helper::Empty &>{}());

  test_metaprogramming_type_property_queries::metaprogramming_type_propery_queries_alignment_of_inline_variables();
}

TEST(metaprogramming_type_property_queries, rank) {
  static_cast<void>(test_info_);
  {
    constexpr ::portable_stl::rank<std::int64_t> checker{};
    EXPECT_EQ(0U, checker());
    static_cast<void>(checker);
  }

  EXPECT_EQ(0U, ::portable_stl::rank<std::int32_t>{}());
  EXPECT_EQ(1U, ::portable_stl::rank<std::int32_t[]>{}());
  EXPECT_EQ(1U, ::portable_stl::rank<std::int32_t[9]>{}());
  EXPECT_EQ(metaprogramming_type_property_queries_helper::USER_VALUE_2,
            ::portable_stl::rank<std::int32_t[1][metaprogramming_type_property_queries_helper::USER_VALUE_2]>{}());
  EXPECT_EQ(metaprogramming_type_property_queries_helper::USER_VALUE_2,
            ::portable_stl::rank<std::int32_t[][metaprogramming_type_property_queries_helper::USER_VALUE_2]>{}());
  EXPECT_EQ(metaprogramming_type_property_queries_helper::USER_VALUE_3,
            ::portable_stl::rank<std::int32_t[metaprogramming_type_property_queries_helper::USER_VALUE_2]
                                             [metaprogramming_type_property_queries_helper::USER_VALUE_3]
                                             [metaprogramming_type_property_queries_helper::USER_VALUE_9]>{}());
  EXPECT_EQ(metaprogramming_type_property_queries_helper::USER_VALUE_3,
            ::portable_stl::rank<std::int32_t[][metaprogramming_type_property_queries_helper::USER_VALUE_3]
                                             [metaprogramming_type_property_queries_helper::USER_VALUE_9]>{}());

  test_metaprogramming_type_property_queries::metaprogramming_type_propery_queries_rank_inline_variables();
}

TEST(metaprogramming_type_property_queries, extent) {
  static_cast<void>(test_info_);
  {
    constexpr ::portable_stl::extent<std::int32_t> checker{};
    EXPECT_EQ(0U, checker());
    static_cast<void>(checker);
  }

  EXPECT_EQ(0U, ::portable_stl::extent<std::int32_t>{}());
  EXPECT_EQ(0U, ::portable_stl::extent<std::int32_t[]>{}());

  EXPECT_EQ(metaprogramming_type_property_queries_helper::USER_VALUE_9,
            ::portable_stl::extent<std::int32_t[metaprogramming_type_property_queries_helper::USER_VALUE_9]>{}());
  EXPECT_EQ(metaprogramming_type_property_queries_helper::USER_VALUE_9,
            (::portable_stl::extent<std::int32_t[metaprogramming_type_property_queries_helper::USER_VALUE_9], 0>{}()));
  EXPECT_EQ(0U,
            (::portable_stl::extent<std::int32_t[metaprogramming_type_property_queries_helper::USER_VALUE_9], 1>{}()));

  EXPECT_EQ(metaprogramming_type_property_queries_helper::USER_VALUE_3,
            (::portable_stl::extent<std::int32_t[metaprogramming_type_property_queries_helper::USER_VALUE_3]
                                                [metaprogramming_type_property_queries_helper::USER_VALUE_9]>{}()));
  EXPECT_EQ(metaprogramming_type_property_queries_helper::USER_VALUE_3,
            (::portable_stl::extent<std::int32_t[metaprogramming_type_property_queries_helper::USER_VALUE_3]
                                                [metaprogramming_type_property_queries_helper::USER_VALUE_9],
                                    0>{}()));
  EXPECT_EQ(metaprogramming_type_property_queries_helper::USER_VALUE_9,
            (::portable_stl::extent<std::int32_t[metaprogramming_type_property_queries_helper::USER_VALUE_3]
                                                [metaprogramming_type_property_queries_helper::USER_VALUE_9],
                                    1>{}()));
  EXPECT_EQ(0U,
            (::portable_stl::extent<std::int32_t[metaprogramming_type_property_queries_helper::USER_VALUE_3]
                                                [metaprogramming_type_property_queries_helper::USER_VALUE_9],
                                    metaprogramming_type_property_queries_helper::USER_VALUE_2>{}()));

  EXPECT_EQ(0U, ::portable_stl::extent<std::int32_t[][metaprogramming_type_property_queries_helper::USER_VALUE_2]>{}());
  EXPECT_EQ(
    0U, (::portable_stl::extent<std::int32_t[][metaprogramming_type_property_queries_helper::USER_VALUE_2], 0>{}()));

  test_metaprogramming_type_property_queries::metaprogramming_type_propery_queries_extent_inline_variables();
}
