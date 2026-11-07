// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="ctz_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CTZ_IMPL_H
#define PSTL_CTZ_IMPL_H
#include "../../common/int32_t.h"
#include "../../common/uint32_t.h"

namespace std {
namespace algorithm_helper {
  inline ::std::int32_t ctz_impl(::std::uint32_t value) noexcept {
    return __builtin_ctz(value);
  }
} // namespace algorithm_helper
} // namespace std

#endif // PSTL_CTZ_IMPL_H
