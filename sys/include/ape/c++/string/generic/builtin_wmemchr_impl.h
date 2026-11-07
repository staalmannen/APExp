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

namespace std {
namespace string_helper {
  inline wchar_t const *builtin_wmemchr_impl(
    wchar_t const *ptr, wchar_t const ch, ::std::size_t count) noexcept {
    for (; 0U < count; --count, ++ptr) {
      if (ch == *ptr) {
        return ptr;
      }
    }
    return nullptr;
  }
} // namespace string_helper
} // namespace std

#endif // PSTL_BUILTIN_WMEMCHR_IMPL_H