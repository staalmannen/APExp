// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="niter_base.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_NITER_BASE_H
#define PSTL_NITER_BASE_H

#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/type_properties/is_nothrow_copy_constructible.h"
#include "move_iterator.h"
#include "reverse_iterator.h"
#include "wrap_iter.h"

/**
 * @brief Helper functions from gcc.
 * Used in vector.
 */

namespace portable_stl {

/**
 * @brief Fallback implementation of the function niter_base, used to remove the wrap_iter wrapper.
 * @tparam t_iterator
 * @param iter
 * @return
 */
template<typename t_iterator>
constexpr inline t_iterator niter_base(t_iterator iter) noexcept(
  ::portable_stl::is_nothrow_copy_constructible<t_iterator>{}()) {
  return iter;
}

template<typename t_iterator>
constexpr inline t_iterator niter_base(::portable_stl::wrap_iter<t_iterator> it) noexcept(
  ::portable_stl::is_nothrow_copy_constructible<t_iterator>{}()) {
  return it.base();
}

template<typename t_iterator>
constexpr auto niter_base(::portable_stl::reverse_iterator<t_iterator> it)
  -> decltype(::portable_stl::make_reverse_iterator(niter_base(it.base()))) {
  return make_reverse_iterator(niter_base(it.base()));
}

template<typename t_iterator>
constexpr auto niter_base(
  ::portable_stl::move_iterator<t_iterator> it) -> decltype(::portable_stl::make_move_iterator(niter_base(it.base()))) {
  return make_move_iterator(niter_base(it.base()));
}
} // namespace portable_stl

#endif // PSTL_NITER_BASE_H
