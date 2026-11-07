// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="builtin_char_memchr.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BUILTIN_CHAR_MEMCHR_H
#define PSTL_BUILTIN_CHAR_MEMCHR_H

#if defined(__has_builtin)
#  if (!(__has_builtin(__builtin_char_memchr)))
#    include "generic/builtin_char_memchr_impl.h"
#  else
#    include "builtin/builtin_char_memchr_impl.h"
#  endif
#else
#  include "generic/builtin_char_memchr_impl.h"
#endif

namespace std {
namespace string_helper {
  inline ::std::char_t const *builtin_char_memchr(
    ::std::char_t const *ptr, ::std::char_t const ch, ::std::size_t count) noexcept {
    return string_helper::builtin_char_memchr_impl(ptr, ch, count);
  }
} // namespace string_helper
} // namespace std

#endif // PSTL_BUILTIN_CHAR_MEMCHR_H
