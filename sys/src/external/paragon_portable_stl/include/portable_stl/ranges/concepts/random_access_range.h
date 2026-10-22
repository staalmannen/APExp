// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="random_access_range.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_RANDOM_ACCESS_RANGE_H
#define PSTL_RANDOM_ACCESS_RANGE_H

#include "../../iterator/concepts/random_access_iterator.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../iterator_t.h"
#include "range.h"
#include "template_range_concept.h"

namespace portable_stl {
namespace ranges {
  /**
   * @brief The random_access_range 'concept' is a refinement of range for which ranges::begin returns a model of
   * random_access_iterator.
   * @tparam range_type Given range type.
   */
  template<class range_type> using random_access_range = template_range_concept<range_type, random_access_iterator>;

} // namespace ranges
} // namespace portable_stl

#endif /* PSTL_RANDOM_ACCESS_RANGE_H */
