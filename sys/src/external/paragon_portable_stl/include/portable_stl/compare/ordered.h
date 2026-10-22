// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="ordered.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ORDERED_H
#define PSTL_ORDERED_H

#include "compare_t.h"

namespace portable_stl {

namespace compare_helper {
  /**
   * @brief Class for save current ordering value.
   */
  enum class ordered : ::portable_stl::compare_helper::compare_t {
    /**
     * @brief Ordering for equal objects.
     */
    equal      = 0,
    /**
     * @brief Ordering for equivalent objects.
     */
    equivalent = equal,
    /**
     * @brief Ordering for one object less than other.
     */
    less       = -1,
    /**
     * @brief Ordering for one object greater than other.
     */
    greater    = 1,
  };
} // namespace compare_helper

} // namespace portable_stl

#endif // PSTL_ORDERED_H
