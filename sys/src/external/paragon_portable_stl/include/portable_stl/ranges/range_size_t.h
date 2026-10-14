// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="range_size_t.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_RANGE_SIZE_T_H
#define PSTL_RANGE_SIZE_T_H

#include "../utility/general/declval.h"
#include "size.h"

namespace portable_stl {
namespace ranges {
  /**
   * @brief Used to obtain the size type of the sized_range type range_type.
   * @tparam range_type Given range.
   */
  template<class range_type>
  using range_size_t = decltype(::portable_stl::ranges::size(::portable_stl::declval<range_type &>()));
} // namespace ranges
} // namespace portable_stl

#endif /* PSTL_RANGE_SIZE_T_H */
