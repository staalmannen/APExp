// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="in_place_t.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IN_PLACE_T_H
#define PSTL_IN_PLACE_T_H

namespace portable_stl {
/**
 * @brief in-place construction
 *
 */
class in_place_t final {
public:
  /**
   * @brief Default constructor.
   */
  explicit in_place_t() noexcept = default;
};

// constexpr inline in_place_t in_place{};

} // namespace portable_stl

#endif // PSTL_IN_PLACE_T_H
