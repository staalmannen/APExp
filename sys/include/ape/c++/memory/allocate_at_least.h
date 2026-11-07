// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="allocate_at_least.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ALLOCATE_AT_LEAST_H
#define PSTL_ALLOCATE_AT_LEAST_H

#include "allocation_result.h"
#include "allocator_traits.h"

namespace std {

template<class t_allocator>

constexpr ::std::allocation_result<typename ::std::allocator_traits<t_allocator>::pointer,
                                            typename ::std::allocator_traits<t_allocator>::size_type>
  allocate_at_least(t_allocator &alloc, size_t num) {
  return {alloc.allocate(num), num};
}

} // namespace std

#endif // PSTL_ALLOCATE_AT_LEAST_H
