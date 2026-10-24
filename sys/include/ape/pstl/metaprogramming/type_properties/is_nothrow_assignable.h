// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_nothrow_assignable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_NOTHROW_ASSIGNABLE_H
#define PSTL_IS_NOTHROW_ASSIGNABLE_H


#if defined(__has_builtin) // gcc and clang has
#  if (__has_builtin(__is_nothrow_assignable)) // clang and NEW gcc
#    include "default/is_nothrow_assignable_impl.h"
#  else // old gcc
#    include "is_nothrow_assignable/is_nothrow_assignable_impl.h"
#  endif
#else // msvc hasn't
#  include "default/is_nothrow_assignable_impl.h"
#endif

namespace portable_stl{
  template<class t_type, class t_other>
  using is_nothrow_assignable = type_properties_helper::is_nothrow_assignable_impl<t_type, t_other>;
} // namespace portable_stl



#endif /* PSTL_IS_NOTHROW_ASSIGNABLE_H */
