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

namespace std {
template<class t_allocator>
typename t_allocator::value_type *allocate_noexcept(t_allocator &alloc, ::std::size_t const size_value) {
  using value_type = typename t_allocator::value_type;
  return ::std::exception_pack<::std::std_error,
                                        ::std::std_error::allocate_error>{}(
           [](t_allocator &a, ::std::size_t const size_val) -> value_type * {
             return {::std::allocator_traits<t_allocator>::allocate(a, size_val)};
           },
           alloc,
           size_value)
    .value_or(nullptr);
}

} // namespace std

#endif // PSTL_ALLOCATE_NOEXCEPT_H
