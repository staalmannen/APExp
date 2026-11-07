// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="swap_allocator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_SWAP_ALLOCATOR_H
#define PSTL_SWAP_ALLOCATOR_H

#include "../utility/general/swap.h"
#include "allocator_traits.h"
#include "../metaprogramming/helper/integral_constant.h"

namespace std {
namespace memory_helper {

  template<typename t_allocator> constexpr void swap_allocator_impl(t_allocator &alloc1, t_allocator &alloc2, ::std::true_type) noexcept {
    using ::std::swap;
    swap(alloc1, alloc2);
  }

  template<typename t_allocator> constexpr inline void swap_allocator_impl(t_allocator &, t_allocator &, ::std::false_type) noexcept {
  }
} // namespace memory_helper

template<typename t_allocator> constexpr inline void swap_allocator(t_allocator &alloc1, t_allocator &alloc2) noexcept {
  memory_helper::swap_allocator_impl(
    alloc1, alloc2, typename ::std::allocator_traits<t_allocator>::propagate_on_container_swap{});
}

} // namespace std
#endif // PSTL_SWAP_ALLOCATOR_H
