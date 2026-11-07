// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="view.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_VIEW_H
#define PSTL_VIEW_H

#include "../../concepts/movable.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "enable_view.h"
#include "range.h"

namespace std {
namespace ranges {

  template<class range_type>
  using view = ::std::conjunction<::std::range<range_type>,
                                           ::std::movable<range_type>,
                                           ::std::ranges::enable_view_bool_constant<range_type>>;

} // namespace ranges
} // namespace std

#endif /* PSTL_VIEW_H */
