// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="disable_sized_range.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_DISABLE_SIZED_RANGE_H
#define PSTL_DISABLE_SIZED_RANGE_H

#include "../../metaprogramming/helper/integral_constant.h"
#include "../../metaprogramming/other_transformations/conditional.h"
#include "../size.h"

namespace portable_stl {
namespace ranges {
  /**
   * @brief disable_sized_range exists to allow use of range types that provide a size function (either as a member or
   * as a non-member) but do not in fact model sized_range. Users may specialize disable_sized_range for cv-unqualified
   * program-defined types. Such specializations shall be usable in constant expressions and have type const bool.
   * @tparam range_type Range type.
   */
  template<class range_type> constexpr bool disable_sized_range = false;

  namespace ranges_helper {
    /**
     * @brief Bool constant wrapper over disable_sized_range.
     * @tparam range_type Tested range type.
     */
    template<class range_type>
    using disable_sized_range_bool_constant
      = conditional_t<disable_sized_range<range_type>, ::portable_stl::true_type, ::portable_stl::false_type>;
  } // namespace ranges_helper

} // namespace ranges
} // namespace portable_stl

#endif /* PSTL_DISABLE_SIZED_RANGE_H */
