// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="memset.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MEMSET_H
#define PSTL_MEMSET_H

#if defined(__has_builtin)
#  if (!(__has_builtin(__builtin_memset)))
#    include "generic/memset_impl.h"
#  else
#    include "builtin/memset_impl.h"
#  endif
#else
#  include "generic/memset_impl.h"
#endif

namespace portable_stl {
/**
 * @brief Copies the value static_cast<unsigned char>(ch) into each of the first count characters of the object pointed
 * to by dest.
 *
 * @param destination the destination pointer.
 * @param ch fill byte.
 * @param count the byte count.
 * @return the destination pointer.
 */
inline void *memset(void *destination, ::portable_stl::int32_t ch, ::portable_stl::size_t count) noexcept {
  return ::portable_stl::memset_impl(destination, ch, count);
}
} // namespace portable_stl

#endif // PSTL_MEMSET_H
