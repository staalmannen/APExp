// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="size_t.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_SIZE_T_H
#define PSTL_SIZE_T_H
namespace portable_stl {

/**
 * @brief The type is an implementation-defined unsigned integer type that is
 * large enough to contain the size in bytes of any object.
 *
 */
using size_t = decltype(sizeof(nullptr));

} // namespace portable_stl

#endif // PSTL_SIZE_T_H
