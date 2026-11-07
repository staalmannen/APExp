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

namespace std {
namespace string_helper {
  inline ::std::char_t const *builtin_char_memchr_impl(
    ::std::char_t const *ptr, ::std::char_t const ch, ::std::size_t count) noexcept {
    return __builtin_char_memchr(ptr, ch, count);
  }
} // namespace string_helper
} // namespace std

#endif // PSTL_BUILTIN_CHAR_MEMCHR_IMPL_H
