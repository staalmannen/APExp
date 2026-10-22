// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="memcmp.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MEMCMP_H
#define PSTL_MEMCMP_H

#if defined(__has_builtin)
#  if (!(__has_builtin(__builtin_memcmp)))
#    include "generic/memcmp_impl.h"
#  else
#    include "builtin/memcmp_impl.h"
#  endif
#else
#  include "generic/memcmp_impl.h"
#endif

namespace portable_stl {
/**
 * @brief Reinterprets the objects pointed to by lhs and rhs as arrays of unsigned char and compares the first count
 * bytes of these arrays. The comparison is done lexicographically. The sign of the result is the sign of the difference
 * between the values of the first pair of bytes (both interpreted as unsigned char) that differ in the objects being
 * compared.
 *
 * @param lhs Pointer to the memory buffers to compare.
 * @param rhs Pointer to the memory buffers to compare.
 * @param count number of bytes to examine
 * @return Negative value if the first differing byte (reinterpreted as unsigned char) in lhs is less than the
 * corresponding byte in rhs; 0​ if all count bytes of lhs and rhs are equal.; Positive value if the first differing
 * byte in lhs is greater than the corresponding byte in rhs.
 */
inline ::portable_stl::int32_t memcmp(void const *lhs, void const *rhs, ::portable_stl::size_t count) noexcept {
  return ::portable_stl::memcmp_impl(lhs, rhs, count);
}
} // namespace portable_stl

#endif // PSTL_MEMCMP_H
