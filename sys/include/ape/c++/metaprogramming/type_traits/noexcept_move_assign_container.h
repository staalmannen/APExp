// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="noexcept_move_assign_container.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_NOEXCEPT_MOVE_ASSIGN_CONTAINER_H
#define PSTL_NOEXCEPT_MOVE_ASSIGN_CONTAINER_H

#include "../../memory/allocator_traits.h"
#include "../logical_operator/disjunction.h"

namespace std {

template<typename t_allocator>
using noexcept_move_assign_container
  = ::std::disjunction<typename ::std::allocator_traits<t_allocator>::propagate_on_container_move_assignment,
                                typename ::std::allocator_traits<t_allocator>::is_always_equal>;

} // namespace std

#endif // PSTL_NOEXCEPT_MOVE_ASSIGN_CONTAINER_H
