// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="builtin_wcslen_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BUILTIN_WCSLEN_IMPL_H
#define PSTL_BUILTIN_WCSLEN_IMPL_H

#include "../../common/char_t.h"
#include "../../common/size_t.h"

namespace portable_stl {
namespace string_helper {
  inline ::portable_stl::size_t builtin_wcslen_impl(wchar_t const *ptr) noexcept {
    // find length of null-terminated sequence
    portable_stl::size_t len = 0;
    for (; *ptr != L'\0'; ++ptr) {
      ++len;
    }
    return len;
  }
} // namespace string_helper
} // namespace portable_stl

#endif // PSTL_BUILTIN_WCSLEN_IMPL_H
