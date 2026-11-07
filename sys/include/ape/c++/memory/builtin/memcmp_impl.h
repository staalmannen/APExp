// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="memcmp_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MEMCMP_IMPL_H
#define PSTL_MEMCMP_IMPL_H

#include "../../common/size_t.h"
#include "../../common/int32_t.h"

namespace std {
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
inline ::std::int32_t memcmp_impl(void const *lhs, void const *rhs, ::std::size_t count) noexcept {
  return __builtin_memcmp(lhs, rhs, count);
}
} // namespace std

#endif // PSTL_MEMCMP_IMPL_H
