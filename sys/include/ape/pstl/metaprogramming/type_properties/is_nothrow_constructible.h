// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_nothrow_constructible.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_NOTHROW_CONSTRUCTIBLE_H
#define PSTL_IS_NOTHROW_CONSTRUCTIBLE_H

#if defined(__has_builtin) // gcc and clang has
#  if (__has_builtin(__is_nothrow_constructible)) // clang and NEW gcc
#    include "default/is_nothrow_constructible_impl.h"
#  else // old gcc
#    include "is_nothrow_constructible/is_nothrow_constructible_impl.h"
#  endif
#else // msvc has too
#  include "default/is_nothrow_constructible_impl.h"
#endif

namespace portable_stl{
  template<class t_type, class... t_args>
  using is_nothrow_constructible = type_properties_helper::is_nothrow_constructible_impl<t_type, t_args...>;
} // namespace portable_stl
#endif /* PSTL_IS_NOTHROW_CONSTRUCTIBLE_H */
