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

namespace portable_stl {
namespace string_helper {
  inline ::portable_stl::size_t builtin_strlen_impl(char_t const *ptr) noexcept {
    return __builtin_strlen(ptr);
  }
} // namespace string_helper
} // namespace portable_stl

#endif // PSTL_BUILTIN_STRLEN_IMPL_H
