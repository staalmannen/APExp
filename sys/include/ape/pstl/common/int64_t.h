// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="int64_t.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INT64_T_H
#define PSTL_INT64_T_H

#include "long_size.h"

namespace portable_stl {
/**
 * @brief Type for signed integer width of exactly 64 bits.
 */
using int64_t = typename common_helper::long_size<>::int64_t;
} // namespace portable_stl

#endif /* PSTL_INT64_T_H */
