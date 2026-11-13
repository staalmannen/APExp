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

#include "../common/compiler_builtins.h"

/*
 * BY CAPABILITY, NOT BY COMPILER NAME.  Unlike the other three
 * selectors this one has NOT been observed to fail -- cpfe accepts
 * `__builtin_ctz' -- so the change is to the test and not to the
 * outcome, and it is made because a selector that asks the wrong
 * question is a bug whether or not it has fired yet.  **There is no
 * third arm here**: `msvc/' uses `_BitScanForward', which is an
 * intrinsic too, so a compiler with neither still has nowhere to go.
 * That is recorded rather than fixed, because nothing in this tree
 * is such a compiler.
 */
#if PSTL_HAS_BUILTIN(__builtin_ctz) || defined(__GNUC__)
#  include "gcc_clang/ctz_impl.h"
#else
#  include "msvc/ctz_impl.h"
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
