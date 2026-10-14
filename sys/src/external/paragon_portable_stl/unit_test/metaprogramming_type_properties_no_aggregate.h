// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_type_properties_no_aggregate.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_METAPROGRAMMING_TYPE_PROPERTIES_NO_AGGREGATE_H
#define PSTL_METAPROGRAMMING_TYPE_PROPERTIES_NO_AGGREGATE_H

#include <gtest/gtest.h>

namespace test_metaprogramming_type_properties {
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_aggregate() {
  ASSERT_TRUE((true));
}
} // namespace test_metaprogramming_type_properties

#endif // PSTL_METAPROGRAMMING_TYPE_PROPERTIES_NO_AGGREGATE_H
