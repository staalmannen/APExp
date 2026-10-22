// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_primary_type_char8_t.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_METAPROGRAMMING_PRIMARY_TYPE_CHAR8_T_H
#define PSTL_METAPROGRAMMING_PRIMARY_TYPE_CHAR8_T_H

#include <gtest/gtest.h>

#include "portable_stl/metaprogramming/primary_type/is_integral_v.h"
namespace test_metaprogramming_primary_type {
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_primary_type_is_integral_char8_t() {
  ASSERT_TRUE((::portable_stl::is_integral_v<char8_t>));
  ASSERT_TRUE((::portable_stl::is_integral_v<char8_t const>));
}
} // namespace test_metaprogramming_primary_type

#endif // PSTL_METAPROGRAMMING_PRIMARY_TYPE_CHAR8_T_H
