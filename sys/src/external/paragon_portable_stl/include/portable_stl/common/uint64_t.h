// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="uint64_t.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_UINT64_T_H
#define PSTL_UINT64_T_H
#include "long_size.h"

namespace portable_stl {
/**
 * @brief Type for unsigned integer width of exactly 64 bits.
 */
using uint64_t = typename common_helper::long_size<>::uint64_t;
} // namespace portable_stl

#endif /* PSTL_INT64_T_H */
