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

namespace portable_stl {
namespace string_helper {
  inline ::portable_stl::char_t const *builtin_char_memchr(
    ::portable_stl::char_t const *ptr, ::portable_stl::char_t const ch, ::portable_stl::size_t count) noexcept {
    return string_helper::builtin_char_memchr_impl(ptr, ch, count);
  }
} // namespace string_helper
} // namespace portable_stl

#endif // PSTL_BUILTIN_CHAR_MEMCHR_H
