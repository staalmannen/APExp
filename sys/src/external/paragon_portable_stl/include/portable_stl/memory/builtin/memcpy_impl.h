// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="memcpy_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MEMCPY_IMPL_H
#define PSTL_MEMCPY_IMPL_H

#include "../../common/size_t.h"

namespace portable_stl {
/**
 * @brief The memcpy() function copies count bytes from memory area source to memory area destination.
 * If destination and source overlap, behavior is undefined.
 *
 * @param destination the destination pointer.
 * @param source the source pointer.
 * @param count the byte count.
 * @return the destination pointer.
 */
inline void *memcpy_impl(void *destination, void const *source, ::portable_stl::size_t count) noexcept {
  return __builtin_memcpy(destination, source, count);
}
} // namespace portable_stl

#endif // PSTL_MEMCPY_IMPL_H
