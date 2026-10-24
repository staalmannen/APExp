// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="memcpy.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MEMCPY_H
#define PSTL_MEMCPY_H

#if defined(__has_builtin)
#  if (!(__has_builtin(__builtin_memcpy)))
#    include "generic/memcpy_impl.h"
#  else
#    include "builtin/memcpy_impl.h"
#  endif
#else
#  include "generic/memcpy_impl.h"
#endif

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
inline void *memcpy(void *const destination, void const *const source, ::portable_stl::size_t const count) noexcept {
  return ::portable_stl::memcpy_impl(destination, source, count);
}
} // namespace portable_stl

#endif // PSTL_MEMCPY_H
