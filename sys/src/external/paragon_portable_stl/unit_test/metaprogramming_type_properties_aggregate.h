// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_type_properties_aggregate.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_METAPROGRAMMING_TYPE_PROPERTIES_AGGREGATE_H
#define PSTL_METAPROGRAMMING_TYPE_PROPERTIES_AGGREGATE_H

#include <gtest/gtest.h>

#include "portable_stl/metaprogramming/type_properties/is_aggregate.h"

namespace test_metaprogramming_type_properties {
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_properties_is_aggregate() {
  {
    ::portable_stl::is_aggregate<
      metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>
      checker{};
    ASSERT_FALSE((checker()));
  }
  ASSERT_FALSE((::portable_stl::is_aggregate<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::virtual_class>{}()));
  ASSERT_FALSE((::portable_stl::is_aggregate<
                metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::trivial_class>{}()));
  ASSERT_FALSE(
    (::portable_stl::is_aggregate<metaprogramming_type_properties_helper::metaprogramming_type_properties_helper>{}()));

  ASSERT_TRUE((::portable_stl::is_aggregate<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::aggregate_class>{}()));
}
} // namespace test_metaprogramming_type_properties

#endif // PSTL_METAPROGRAMMING_TYPE_PROPERTIES_AGGREGATE_H
