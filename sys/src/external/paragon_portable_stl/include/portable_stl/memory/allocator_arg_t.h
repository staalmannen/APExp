// ***************************************************************************
// * Copyright (c) 2024 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="allocator_arg_t.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ALLOCATOR_ARG_T_H
#define PSTL_ALLOCATOR_ARG_T_H
namespace portable_stl {
/**
 * @brief allocator argument tag.
 */
class allocator_arg_t final {
public:
  /**
   * @brief Construct allocator argument tag.
   */
  explicit allocator_arg_t() = default;
};
} // namespace portable_stl

#endif // PSTL_ALLOCATOR_ARG_T_H
