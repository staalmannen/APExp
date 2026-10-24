// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="allocate_noexcept.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ALLOCATE_NOEXCEPT_H
#define PSTL_ALLOCATE_NOEXCEPT_H

#include "../common/size_t.h"
#include "../error/portable_stl_error.h"
#include "../utility/expected/exception_pack.h"
#include "allocator_traits.h"

namespace portable_stl {
template<class t_allocator>
typename t_allocator::value_type *allocate_noexcept(t_allocator &alloc, ::portable_stl::size_t const size_value) {
  using value_type = typename t_allocator::value_type;
  return ::portable_stl::exception_pack<::portable_stl::portable_stl_error,
                                        ::portable_stl::portable_stl_error::allocate_error>{}(
           [](t_allocator &a, ::portable_stl::size_t const size_val) -> value_type * {
             return {::portable_stl::allocator_traits<t_allocator>::allocate(a, size_val)};
           },
           alloc,
           size_value)
    .value_or(nullptr);
}

} // namespace portable_stl

#endif // PSTL_ALLOCATE_NOEXCEPT_H
