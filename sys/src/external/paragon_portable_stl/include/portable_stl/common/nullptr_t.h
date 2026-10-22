// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="nullptr_t.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_NULLPTR_T_H
#define PSTL_NULLPTR_T_H
namespace portable_stl {
/**
 * @brief The type is a synonym for the type of a nullptr expression.
 *
 */
using nullptr_t = decltype(nullptr);
} // namespace portable_stl

#endif // PSTL_NULLPTR_T_H
