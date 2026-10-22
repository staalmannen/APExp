// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="bit_common.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BIT_COMMON_H
#define PSTL_BIT_COMMON_H

#include "../../common/size_t.h"

namespace portable_stl {
namespace bit_algo {
  /**
   * @brief Generates mask of leading zeros.
   *
   * @tparam t_type
   * @param leading_ones count of leading zeros.
   * @param bits_per_word bits in t_type.
   * @return mask.
   */
  template<class t_type> t_type clo(::portable_stl::size_t leading_ones, ::portable_stl::size_t bits_per_word) {
    return ((leading_ones <= 0) || (bits_per_word <= leading_ones))
           ? static_cast<t_type>(~0)
           : static_cast<t_type>((static_cast<t_type>(1) << leading_ones) - 1) << (bits_per_word - leading_ones);
  }
} // namespace bit_algo
} // namespace portable_stl

#endif // PSTL_BIT_COMMON_H
