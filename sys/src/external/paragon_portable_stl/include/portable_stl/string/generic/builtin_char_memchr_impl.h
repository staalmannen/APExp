// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="builtin_char_memchr_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BUILTIN_CHAR_MEMCHR_IMPL_H
#define PSTL_BUILTIN_CHAR_MEMCHR_IMPL_H

#include "../../common/char_t.h"
#include "../../common/size_t.h"

namespace portable_stl {
namespace string_helper {
  inline ::portable_stl::char_t const *builtin_char_memchr_impl(
    ::portable_stl::char_t const *ptr, ::portable_stl::char_t const ch, ::portable_stl::size_t count) noexcept {
    for (; 0U < count; --count, ++ptr) {
      if (ch == *ptr) {
        return ptr;
      }
    }
    return nullptr;
  }
} // namespace string_helper
} // namespace portable_stl

#endif // PSTL_BUILTIN_CHAR_MEMCHR_IMPL_H
