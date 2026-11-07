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

#include "../../common/int32_t.h"
#include "../../common/size_t.h"
#include "../../common/uchar_t.h"

namespace std {
/**
 * @brief Copies the value static_cast<unsigned char>(ch) into each of the first count characters of the object pointed
 * to by dest.
 *
 * @param destination the destination pointer.
 * @param ch fill byte.
 * @param count the byte count.
 * @return the destination pointer.
 */
inline void *memset_impl(
  void *const destination, ::std::int32_t ch, ::std::size_t const count) noexcept {
  for (::std::size_t position{0U}; position < count; ++position) {
    static_cast<::std::uchar_t *>(destination)[position] = static_cast<::std::uchar_t>(ch);
  }
  return destination;
}
} // namespace std

#endif // PSTL_MEMSET_IMPL_H
