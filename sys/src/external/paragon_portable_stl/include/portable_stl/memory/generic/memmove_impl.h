// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="memmove_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MEMMOVE_IMPL_H
#define PSTL_MEMMOVE_IMPL_H

#include "../../common/ptrdiff_t.h"
#include "../../common/size_t.h"
#include "../../common/uchar_t.h"

namespace portable_stl {
/**
 * @brief Copies count characters from the object pointed to by source to the object pointed to by destination.
 * Both objects are reinterpreted as arrays of unsigned char.
 * The objects may overlap: copying takes place as if the characters
 * were copied to a temporary character array and then the characters were copied from the array to destination.
 *
 * @param destination Pointer to the memory location to copy to.
 * @param source Pointer to the memory location to copy from.
 * @param count Number of bytes to copy.
 * @return The destination pointer.
 */
inline void *memmove_impl(void *destination, void const *source, ::portable_stl::size_t count) noexcept {
  auto *d        = static_cast<::portable_stl::uchar_t *>(destination);
  auto *s        = static_cast<::portable_stl::uchar_t const *>(source);
  auto  signed_n = static_cast<::portable_stl::ptrdiff_t>(count);
  if (d < s) {
    for (::portable_stl::ptrdiff_t i{0}; i < signed_n; ++i) {
      d[i] = s[i];
    }
  } else {
    if ((d > s) && (signed_n > 0)) {
      for (::portable_stl::ptrdiff_t i{signed_n - 1}; i >= 0; --i) {
        d[i] = s[i];
      }
    }
  }
  return destination;
}
} // namespace portable_stl

#endif /* PSTL_MEMMOVE_IMPL_H */
