// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_constant_evaluated.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_CONSTANT_EVALUATED_H
#define PSTL_IS_CONSTANT_EVALUATED_H

#include "../../common/compiler_builtins.h"

/*
 * BY CAPABILITY, NOT BY COMPILER NAME -- this was
 * `#if defined(_MSC_VER)' against "clang and gcc", so cpfe took the
 * builtin arm and answered
 * `identifier "__builtin_is_constant_evaluated" is undefined'.
 *
 * `no_realization' returns FALSE unconditionally, which is the
 * conservative answer and not a wrong one: a caller that asks is
 * choosing between a constant-folding path and a runtime path, and
 * the runtime path is correct in both.  What is lost is an
 * optimisation, not a result.
 */
#if PSTL_HAS_BUILTIN(__builtin_is_constant_evaluated) \
 || (defined(__GNUC__) && !defined(__clang__) && (__GNUC__ >= 9))
    #include "buildin_realization/is_constant_evaluated_impl.h"
#else
    #include "no_realization/is_constant_evaluated_impl.h"
#endif
 namespace std {
constexpr bool is_constant_evaluated() noexcept { // Internal function for any standard mode
  return constant_evaluation_helper::is_constant_evaluated_impl();
}
} // namespace std

#endif // PSTL_IS_CONSTANT_EVALUATED_H
