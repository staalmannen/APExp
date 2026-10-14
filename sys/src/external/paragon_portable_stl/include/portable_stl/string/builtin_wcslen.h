// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="builtin_wcslen.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BUILTIN_WCSLEN_H
#define PSTL_BUILTIN_WCSLEN_H

#if defined(__has_builtin)
#  if (!(__has_builtin(__builtin_wcslen)))
#    include "generic/builtin_wcslen_impl.h"
#  else
#    include "builtin/builtin_wcslen_impl.h"
#  endif
#else
#  include "generic/builtin_wcslen_impl.h"
#endif

namespace portable_stl {
namespace string_helper {
  inline ::portable_stl::size_t builtin_wcslen(wchar_t const *ptr) noexcept {
    return string_helper::builtin_wcslen_impl(ptr);
  }
} // namespace string_helper
} // namespace portable_stl

#endif // PSTL_BUILTIN_WCSLEN_H
