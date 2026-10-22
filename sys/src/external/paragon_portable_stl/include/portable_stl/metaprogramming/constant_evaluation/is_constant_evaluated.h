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

#if defined(_MSC_VER)
    #include "no_realization/is_constant_evaluated_impl.h"
#else // clang and gcc
    #include "buildin_realization/is_constant_evaluated_impl.h"
#endif
 namespace portable_stl {
constexpr bool is_constant_evaluated() noexcept { // Internal function for any standard mode
  return constant_evaluation_helper::is_constant_evaluated_impl();
}
} // namespace portable_stl

#endif // PSTL_IS_CONSTANT_EVALUATED_H
