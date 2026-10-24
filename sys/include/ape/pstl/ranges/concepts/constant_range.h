// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="constant_range.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CONSTANT_RANGE_H
#define PSTL_CONSTANT_RANGE_H

#include "../../iterator/constant_iterator.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../iterator_t.h"
#include "input_range.h"

namespace portable_stl {
namespace ranges {
  /**
   * @brief The constant_range 'concept' is a refinement of range for which ranges::begin returns a constant iterator.
   *
   * @tparam t_type Given type.
   */
  template<class t_type>
  using constant_range = ::portable_stl::conjunction<
    ::portable_stl::ranges::input_range<t_type>,
    ::portable_stl::iterator_helper::is_constant_iterator<::portable_stl::ranges::iterator_t<t_type>>>;
} // namespace ranges
} // namespace portable_stl

#endif /* PSTL_CONSTANT_RANGE_H */
