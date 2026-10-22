// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="unexpect_t.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_UNEXPECT_T_H
#define PSTL_UNEXPECT_T_H

namespace portable_stl {
/**
 * @brief unexpected in-place contructor.
 *
 */
class unexpect_t final {
public:
  /**
   * @brief Default constructor.
   */
  explicit unexpect_t() noexcept = default;
};

} // namespace portable_stl

#endif // PSTL_UNEXPECT_T_H
