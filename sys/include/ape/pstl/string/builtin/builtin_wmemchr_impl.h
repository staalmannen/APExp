// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="builtin_wmemchr_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BUILTIN_WMEMCHR_IMPL_H
#define PSTL_BUILTIN_WMEMCHR_IMPL_H

#include "../../common/size_t.h"

namespace portable_stl {
namespace string_helper {
  inline wchar_t const *builtin_wmemchr_impl(
    wchar_t const *ptr, wchar_t const ch, ::portable_stl::size_t count) noexcept {
    return __builtin_wmemchr(ptr, ch, count);
  }
} // namespace string_helper
} // namespace portable_stl

#endif // PSTL_BUILTIN_WMEMCHR_IMPL_H
