// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="memset_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MEMSET_IMPL_H
#define PSTL_MEMSET_IMPL_H

#include "../../common/size_t.h"
#include "../../common/int32_t.h"
#include "../../common/uchar_t.h"

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
inline void *memset_impl(void *destination, ::portable_stl::int32_t ch, ::portable_stl::size_t count) noexcept {
  return __builtin_memset(destination, ch, count);
}
} // namespace portable_stl

#endif // PSTL_MEMSET_IMPL_H
