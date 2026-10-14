// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="input_range.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INPUT_RANGE_H
#define PSTL_INPUT_RANGE_H

#include "../../iterator/concepts/input_iterator.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../iterator_t.h"
#include "range.h"
#include "template_range_concept.h"

namespace portable_stl {
namespace ranges {
  /**
   * @brief The input_range 'concept' is a refinement of range for which ranges::begin returns a model of
   * input_iterator.
   * @tparam range_type Given range type.
   */
  template<class range_type> using input_range = template_range_concept<range_type, input_iterator>;

} // namespace ranges
} // namespace portable_stl

#endif /* PSTL_INPUT_RANGE_H */
