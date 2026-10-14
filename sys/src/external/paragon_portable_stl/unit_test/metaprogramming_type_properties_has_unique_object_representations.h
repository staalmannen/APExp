// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_type_properties_has_unique_object_representations.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************

#ifndef PSTL_METAPROGRAMMING_TYPE_PROPERTIES_HAS_UNIQUE_OBJECT_REPRESENTATIONS_H
#define PSTL_METAPROGRAMMING_TYPE_PROPERTIES_HAS_UNIQUE_OBJECT_REPRESENTATIONS_H

#include <gtest/gtest.h>

#include "portable_stl/metaprogramming/type_properties/has_unique_object_representations.h"

namespace test_metaprogramming_type_properties {

/**
 * @brief Additional test for
 *
 */
inline void metaprogramming_type_properties_has_unique_object_representations() {
  // examples from https://en.cppreference.com/w/cpp/types/has_unique_object_representations
  {
    ::portable_stl::has_unique_object_representations<std::int8_t> checker{};
    ASSERT_TRUE(checker());
  }

  // For IEC 559 floats, assertion passes because the value NaN has multiple object representations.
  ASSERT_FALSE(::portable_stl::has_unique_object_representations<float>{}());

  // Should succeed in any sane implementation because unpadded is typically not padded, and std::uint32_t cannot
  // contain padding bits.
  ASSERT_TRUE(::portable_stl::has_unique_object_representations<
              metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::unpadded>{}());

  // Fails in most implementations because padding bits are inserted between the data members c and st
  ASSERT_FALSE(::portable_stl::has_unique_object_representations<
               metaprogramming_type_properties_helper::metaprogramming_type_properties_helper::likely_padded>{}());

  // Notable architectural divergence:
  // ASSERT_TRUE ( ::  portable_stl  ::  has_unique_object_representations  < bool >  {}  ()  ); // x86
  // ASSERT_FALSE ( ::  portable_stl  ::  has_unique_object_representations  < bool >  {}  ()  ); // ARM
}
} // namespace test_metaprogramming_type_properties

#endif // PSTL_METAPROGRAMMING_TYPE_PROPERTIES_HAS_UNIQUE_OBJECT_REPRESENTATIONS_H
