// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="unwrap_iter.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_UNWRAP_ITER_H
#define PSTL_UNWRAP_ITER_H

#include "../iterator/concepts/contiguous_iterator.h"
#include "../memory/to_address.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/type_properties/is_copy_constructible.h"
#include "../utility/general/declval.h"
#include "../utility/general/move.h"

namespace portable_stl {

// TODO: Change the name of unwrap_iter_impl to something more appropriate
// The job of unwrap_iter is to remove iterator wrappers (like reverse_iterator or wrap_iter),
// to reduce the number of template instantiations and to enable pointer-based optimizations e.g. in ::copy.
//
// Some algorithms (e.g. ::copy, but not ::sort) need to convert an
// "unwrapped" result back into the original iterator type. Doing that is the job of rewrap_iter.

// Default case - we can't unwrap anything
template<class t_iter, class = ::portable_stl::contiguous_iterator<t_iter>> struct unwrap_iter_impl {
  constexpr static t_iter rewrap(t_iter, t_iter iter) {
    return iter;
  }
  constexpr static t_iter unwrap(t_iter iter) noexcept {
    return iter;
  }
};

// TODO(hardening): make sure that the following unwrapping doesn't unexpectedly turn hardened iterators into raw
// pointers.

// It's a contiguous iterator, so we can use a raw pointer instead
template<class t_iter> struct unwrap_iter_impl<t_iter, ::portable_stl::true_type> {
  /**
   * @brief Alias.
   */
  using t_to_address_type = decltype(::portable_stl::to_address(::portable_stl::declval<t_iter>()));

  constexpr static t_iter rewrap(t_iter orig_iter, t_to_address_type unwrapped_iter) {
    return orig_iter + (unwrapped_iter - ::portable_stl::to_address(orig_iter));
  }

  constexpr static t_to_address_type unwrap(t_iter iter) noexcept {
    return ::portable_stl::to_address(iter);
  }
};

template<class t_iter,
         class t_impl = unwrap_iter_impl<t_iter>,
         ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_copy_constructible<t_iter>, void *> = nullptr>
constexpr inline decltype(t_impl::unwrap(::portable_stl::declval<t_iter>())) unwrap_iter(t_iter iter) noexcept {
  return t_impl::unwrap(iter);
}

// Allow input_iterators to be passed to unwrap_iter (but not rewrap_iter)
// #if _LIBCPP_STD_VER >= 20
// template<class t_iter, enable_if_t<!is_copy_constructible<t_iter>::value, int> = 0>
// constexpr inline t_iter unwrap_iter(t_iter i) noexcept {
//   return i;
// }
// #endif

template<class t_orig_iter, class t_iter, class t_impl = unwrap_iter_impl<t_orig_iter>>
constexpr t_orig_iter rewrap_iter(t_orig_iter orig_iter, t_iter iter) noexcept {
  return t_impl::rewrap(::portable_stl::move(orig_iter), ::portable_stl::move(iter));
}
} // namespace portable_stl

#endif // PSTL_UNWRAP_ITER_H
