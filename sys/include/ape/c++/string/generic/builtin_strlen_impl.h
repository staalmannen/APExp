// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="builtin_strlen_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BUILTIN_STRLEN_IMPL_H
#define PSTL_BUILTIN_STRLEN_IMPL_H

#include "../../common/char_t.h"
#include "../../common/size_t.h"

namespace std {
namespace string_helper {
  inline ::std::size_t builtin_strlen_impl(::std::char_t const *ptr) noexcept {
    // find length of null-terminated sequence
    ::std::size_t len{0U};
    for (; ptr[len] != '\0'; ++len) {
      ;
    }
    return len;
  }
} // namespace string_helper
} // namespace std

#endif // PSTL_BUILTIN_STRLEN_IMPL_H
