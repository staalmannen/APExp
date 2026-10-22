// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="piecewise_construct.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_PIECEWISE_CONSTRUCT_H
#define PSTL_PIECEWISE_CONSTRUCT_H

namespace portable_stl {

/**
 * @brief piecewise_construct_t is an empty class tag type used to disambiguate between different functions that take
 * two tuple arguments.
 *
 */
struct piecewise_construct_t {
  explicit piecewise_construct_t() = default;
};

} // namespace portable_stl

#endif // PSTL_PIECEWISE_CONSTRUCT_H
