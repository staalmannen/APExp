// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="ctz.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CTZ_H
#define PSTL_CTZ_H

#if defined(_MSC_VER)
#  include "msvc/ctz_impl.h"
#else // clang and gcc
#  include "gcc_clang/ctz_impl.h"
#endif

namespace portable_stl {

/**
 * @brief Count trailing zeros, are used to count the amount of zeros at the end of the numbers binary representation.
 *
 * @param value
 * @return ::portable_stl::int32_t
 */
inline ::portable_stl::int32_t ctz(::portable_stl::uint32_t value) noexcept {
  return algorithm_helper::ctz_impl(value);
}
} // namespace portable_stl

#endif // PSTL_CTZ_H
