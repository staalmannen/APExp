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

namespace portable_stl {
namespace algorithm_helper {
  inline ::portable_stl::int32_t ctz_impl(::portable_stl::uint32_t value) noexcept {
    return __lzcnt(value);
  }
} // namespace algorithm_helper
} // namespace portable_stl

#endif // PSTL_CTZ_IMPL_H
