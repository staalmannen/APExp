// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="contiguous_range.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CONTIGUOUS_RANGE_H
#define PSTL_CONTIGUOUS_RANGE_H

#include "../../iterator/concepts/contiguous_iterator.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../iterator_t.h"
#include "random_access_range.h"

namespace portable_stl {
namespace ranges {
  /**
   * @brief The contiguous_range 'concept' is a refinement of range for which ranges::begin returns a model of
   * contiguous_iterator.
   * @tparam range_type Given range type.
   */
  template<class range_type> using contiguous_range = template_range_concept<range_type, contiguous_iterator>;

} // namespace ranges
} // namespace portable_stl

#endif /* PSTL_CONTIGUOUS_RANGE_H */
