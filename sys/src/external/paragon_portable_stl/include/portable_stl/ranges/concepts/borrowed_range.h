// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="borrowed_range.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BORROWED_RANGE_H
#define PSTL_BORROWED_RANGE_H

#include "../../metaprogramming/logical_operator/conjunction.h"
#include "maybe_borrowed_range.h"
#include "range.h"

namespace portable_stl {
namespace ranges {
  /**
   * @brief The 'concept' borrowed_range defines the requirements of a range such that a function can take it by value
   * and return iterators obtained from it without danger of dangling.
   *
   * @tparam t_type Given type.
   */
  template<class t_type>
  using borrowed_range
    = ::portable_stl::conjunction<::portable_stl::range<t_type>, ::portable_stl::maybe_borrowed_range<t_type>>;

} // namespace ranges
} // namespace portable_stl

#endif /* PSTL_BORROWED_RANGE_H */
