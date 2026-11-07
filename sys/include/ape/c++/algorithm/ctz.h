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

namespace std {

/**
 * @brief Count trailing zeros, are used to count the amount of zeros at the end of the numbers binary representation.
 *
 * @param value
 * @return ::std::int32_t
 */
inline ::std::int32_t ctz(::std::uint32_t value) noexcept {
  return algorithm_helper::ctz_impl(value);
}
} // namespace std

#endif // PSTL_CTZ_H
