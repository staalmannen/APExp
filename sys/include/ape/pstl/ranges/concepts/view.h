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

namespace portable_stl {
namespace ranges {

  template<class range_type>
  using view = ::portable_stl::conjunction<::portable_stl::range<range_type>,
                                           ::portable_stl::movable<range_type>,
                                           ::portable_stl::ranges::enable_view_bool_constant<range_type>>;

} // namespace ranges
} // namespace portable_stl

#endif /* PSTL_VIEW_H */
