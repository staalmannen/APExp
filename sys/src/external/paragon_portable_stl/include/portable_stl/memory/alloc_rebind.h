// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="alloc_rebind.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef ALLOC_REBIND_H
#define ALLOC_REBIND_H

#include "allocator_traits.h"

namespace portable_stl {
template<typename t_allocator, typename t_type>
using alloc_rebind = typename ::portable_stl::allocator_traits<t_allocator>::template rebind<t_allocator, t_type>::type;
} // namespace portable_stl
#endif // ALLOC_REBIND_H
