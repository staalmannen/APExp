// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="wmemcmp_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_WMEMCMP_IMPL_H
#define PSTL_WMEMCMP_IMPL_H

#include "../../common/int32_t.h"
#include "../../common/size_t.h"

namespace portable_stl {
/**
 * @brief Compares the first count wide characters of the wide character arrays pointed to by lhs and rhs. The
 * comparison is done lexicographically. The sign of the result is the sign of the difference between the values of the
 * first pair of wide characters that differ in the arrays being compared. If count is zero, the function does nothing.
 *
 * @param lhs Pointers to the wide character arrays to compare.
 * @param rhs Pointers to the wide character arrays to compare.
 * @param count Number of wide characters to examine.
 * @return Negative value if the value of the first differing wide character in lhs is less than the value of the
 * corresponding wide character in rhs: lhs precedes rhs in lexicographical order. ​0​ if all count wide characters
 * of lhs and rhs are equal. Positive value if the value of the first differing wide character in lhs is greater than
 * the value of the corresponding wide character in rhs: rhs precedes lhs in lexicographical order.
 */
inline ::portable_stl::int32_t wmemcmp_impl(
  wchar_t const *lhs, wchar_t const *rhs, ::portable_stl::size_t count) noexcept {
  return __builtin_wmemcmp(lhs, rhs, count);
}
} // namespace portable_stl

#endif // PSTL_WMEMCMP_IMPL_H
