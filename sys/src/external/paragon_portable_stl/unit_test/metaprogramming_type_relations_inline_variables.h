// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="metaprogramming_type_relations_inline_variables.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_METAPROGRAMMING_TYPE_RELATIONS_INLINE_VARIABLES_H
#define PSTL_METAPROGRAMMING_TYPE_RELATIONS_INLINE_VARIABLES_H

#include <gtest/gtest.h>

#include "metaprogramming_type_relations_helper.h"
#include "portable_stl/metaprogramming/type_relations/is_base_of_v.h"
#include "portable_stl/metaprogramming/type_relations/is_invocable_v.h"
#include "portable_stl/metaprogramming/type_relations/is_invocable_r_v.h"
#include "portable_stl/metaprogramming/type_relations/is_same_v.h"

namespace test_metaprogramming_type_relations {
/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_relations_is_same_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_same_v<std::uint32_t, std::uint32_t>));
  ASSERT_FALSE((::portable_stl::is_same_v<std::uint32_t const, std::uint32_t>));
  ASSERT_FALSE((::portable_stl::is_same_v<std::uint32_t volatile, std::uint32_t>));
  ASSERT_FALSE((::portable_stl::is_same_v<std::uint32_t const volatile, std::uint32_t>));
}

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_relations_is_base_of_inline_variables() {
  ASSERT_TRUE((::portable_stl::is_base_of_v<metaprogramming_type_relations_helper::Base1,
                                            metaprogramming_type_relations_helper::Derived1>));
  ASSERT_TRUE((::portable_stl::is_base_of_v<metaprogramming_type_relations_helper::Derived1,
                                            metaprogramming_type_relations_helper::Derived2>));
  ASSERT_TRUE((::portable_stl::is_base_of_v<metaprogramming_type_relations_helper::Base2,
                                            metaprogramming_type_relations_helper::Derived3>));

  ASSERT_FALSE((::portable_stl::is_base_of_v<metaprogramming_type_relations_helper::Base2,
                                             metaprogramming_type_relations_helper::Derived1>));
  ASSERT_FALSE((::portable_stl::is_base_of_v<metaprogramming_type_relations_helper::Base2,
                                             metaprogramming_type_relations_helper::Derived2>));

  ASSERT_FALSE((::portable_stl::is_base_of_v<metaprogramming_type_relations_helper::Base1,
                                             metaprogramming_type_relations_helper::Derived3>));

  ASSERT_FALSE((::portable_stl::is_base_of_v<std::uint32_t, std::uint32_t>));

  // private base
  ASSERT_TRUE((::portable_stl::is_base_of_v<metaprogramming_type_relations_helper::Base1,
                                            metaprogramming_type_relations_helper::Derived2>));
  // but
  ASSERT_FALSE((::std::is_convertible_v<metaprogramming_type_relations_helper::Derived2 *,
                                        metaprogramming_type_relations_helper::Base1 *>));
}

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_relations_is_invocable_inline_variables() {
  /**
   * @brief Alias.
   *
   */
  using Fn = void (*)();

  EXPECT_TRUE(::portable_stl::is_invocable_v<Fn>);
  EXPECT_FALSE(::portable_stl::is_invocable_v<Fn, std::int32_t>);
}

/**
 * @brief Additional test for inline variable
 *
 */
inline void metaprogramming_type_relations_is_invocable_r_inline_variables() {
  /**
   * @brief Alias.
   *
   */
  using Fn = void (*)();

  EXPECT_TRUE(::portable_stl::is_invocable_r_v<void, Fn>);
  EXPECT_FALSE(::portable_stl::is_invocable_r_v<std::int32_t, Fn>);
}
} // namespace test_metaprogramming_type_relations

#endif // PSTL_METAPROGRAMMING_TYPE_RELATIONS_INLINE_VARIABLES_H
