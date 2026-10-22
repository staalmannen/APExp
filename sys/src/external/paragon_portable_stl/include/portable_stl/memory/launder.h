// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="launder.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_LAUNDER_H
#define PSTL_LAUNDER_H

#include "../metaprogramming/primary_type/is_function.h"
#include "../metaprogramming/primary_type/is_void.h"

#if defined(__has_builtin)
#  if (!(__has_builtin(__cpp_lib_launder)))
#    include "generic/launder_impl.h"
#  else
#    include "builtin/launder_impl.h"
#  endif
#else
#  include "generic/launder_impl.h"
#endif

namespace portable_stl {

/**
 * @brief Devirtualization fence with respect to p. Returns a pointer to the same memory that ptr points to, but where
 * the referent object is assumed to have a distinct lifetime and dynamic type.
 *
 * @tparam t_type
 * @param ptr
 * @return t_type*
 */
template<class t_type> constexpr t_type *launder(t_type *ptr) noexcept {
    static_assert(!::portable_stl::is_function<t_type>{}() && !::portable_stl::is_void<t_type>{}(),
        "N4950 [ptr.launder]/1: Mandates: !is_function_v<t_type> && !is_void_v<t_type> is true.");
  return ::portable_stl::memory_helper::launder_impl(ptr);
}
} // namespace portable_stl

#endif // PSTL_LAUNDER_H
