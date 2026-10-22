// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_type_property_queries_helper.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_METAPROGRAMMING_TYPE_PROPERTY_QUERIES_HELPER_H
#define PSTL_METAPROGRAMMING_TYPE_PROPERTY_QUERIES_HELPER_H

#include <cstddef>

namespace metaprogramming_type_property_queries_helper {
/**
 * @brief Empty class.
 */
struct Empty {};

/**
 * @brief Test char alias.
 */
using user_char8_t = char;

/**
 * @brief User value 2
 */
constexpr size_t const USER_VALUE_2{2U};
/**
 * @brief User value 3
 */
constexpr size_t const USER_VALUE_3{3U};
/**
 * @brief User value 9
 */
constexpr size_t const USER_VALUE_9{9U};

/**
 * @brief 1 word alignment size.
 */
constexpr size_t const ALIGN_8{1U};
/**
 * @brief 2 word alignment size.
 */
constexpr size_t const ALIGN_16{2U};
/**
 * @brief 4 word alignment size.
 */
constexpr size_t const ALIGN_32{4U};
/**
 * @brief 8 word alignment size.
 */
constexpr size_t const ALIGN_64{8U};
} // namespace metaprogramming_type_property_queries_helper

#endif // PSTL_METAPROGRAMMING_TYPE_PROPERTY_QUERIES_HELPER_H
