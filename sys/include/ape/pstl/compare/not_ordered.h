// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="not_ordered.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_NOT_ORDERED_H
#define PSTL_NOT_ORDERED_H

#include "compare_t.h"

namespace portable_stl {
namespace compare_helper {
  /**
   * @brief Class for save not ordered and not compared values.
   */
  enum class not_ordered : ::portable_stl::compare_helper::compare_t {
    /**
     * @brief Objects can't compared.
     *
     */
    unordered = -127
  };
} // namespace compare_helper

} // namespace portable_stl

#endif // PSTL_NOT_ORDERED_H
