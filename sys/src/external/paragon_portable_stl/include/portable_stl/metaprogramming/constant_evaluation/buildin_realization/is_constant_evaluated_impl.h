// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_constant_evaluated_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_CONSTANT_EVALUATED_IMPL_H
#define PSTL_IS_CONSTANT_EVALUATED_IMPL_H

namespace portable_stl {
  namespace constant_evaluation_helper{

constexpr bool is_constant_evaluated_impl() noexcept { // Internal function for any standard mode
  return __builtin_is_constant_evaluated();
}
  }
} // namespace portable_stl

#endif // PSTL_IS_CONSTANT_EVALUATED_IMPL_H

