// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="maybe_borrowed_range.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MAYBE_BORROWED_RANGE_H
#define PSTL_MAYBE_BORROWED_RANGE_H

#include "../../metaprogramming/helper/integral_constant.h"
#include "../../metaprogramming/logical_operator/disjunction.h"
#include "../../metaprogramming/other_transformations/conditional.h"
#include "../../metaprogramming/other_transformations/remove_cvref.h"
#include "../../metaprogramming/primary_type/is_lvalue_reference.h"
// #include "range.h"

namespace std {
namespace ranges {
  /**
   * @brief The enable_borrowed_range variable template is used to indicate whether a range is a borrowed_range. The
   * primary template is defined as false.
   * @tparam range_type Range type.
   */
  template<class range_type> constexpr bool enable_borrowed_range = false;

  namespace ranges_helper {
    /**
     * @brief Bool constant wrapper over enable_borrowed_range.
     * @tparam range_type Tested range type.
     */
    template<class range_type>
    using enable_borrowed_range_bool_constant
      = conditional_t<enable_borrowed_range<range_type>, ::std::true_type, ::std::false_type>;

  } // namespace ranges_helper

  /**
   * @brief Part of the constraints of ranges::borrowed_range.
   * _Should_range_access in msvc
   * @tparam range_type Tested range type.
   */
  template<class range_type>
  using maybe_borrowed_range = ::std::disjunction<
    ::std::is_lvalue_reference<range_type>,
    ranges_helper::enable_borrowed_range_bool_constant<::std::remove_cvref<range_type>>>;

} // namespace ranges
} // namespace std

#endif /* PSTL_MAYBE_BORROWED_RANGE_H */
