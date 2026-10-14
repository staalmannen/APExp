// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="new.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_NEW_H
#define PSTL_NEW_H

#include "../common/size_t.h"

/**
 * @brief Placement new operator.
 *
 * @param
 * @param pointer input pointer.
 * @return pointer
 */
inline void *operator new(::portable_stl::size_t, void *pointer) noexcept {
  return pointer;
}

/**
 * @brief Placement new operator for array.
 *
 * @param
 * @param pointer input pointer.
 * @return pointer
 */
inline void *operator new[](::portable_stl::size_t, void *pointer) noexcept {
  return pointer;
}

#endif // PSTL_NEW_H
