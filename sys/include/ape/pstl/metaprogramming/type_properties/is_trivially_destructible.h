// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_trivially_destructible.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_TRIVIALLY_DESTRUCTIBLE_H
#define PSTL_IS_TRIVIALLY_DESTRUCTIBLE_H

#if defined(__has_builtin)
#  if (!(__has_builtin(__is_trivially_destructible)))
#    include "trivial_destructor/check_is_trivially_destructible.h"
#  else
#    include "default/check_is_trivially_destructible.h"
#  endif
#else
#  include "default/check_is_trivially_destructible.h"
#endif

namespace portable_stl {

/**
 * @brief Check t_type is a Trivially-destructible . ( Can destroy by free like functions. )
 * @tparam t_type type for check.
 */
template<class t_type>
using is_trivially_destructible = ::portable_stl::type_properties_helpers::check_is_trivially_destructible<t_type>;
} // namespace portable_stl

#endif // PSTL_IS_TRIVIALLY_DESTRUCTIBLE_H
