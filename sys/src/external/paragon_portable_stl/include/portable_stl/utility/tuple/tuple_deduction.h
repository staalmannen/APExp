// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_deduction.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TUPLE_DEDUCTION_H
#define PSTL_TUPLE_DEDUCTION_H

#include "tuple.h"
namespace portable_stl {

template<class... t_types> tuple(t_types...) -> tuple<t_types...>;

template<class t_allocator, class... t_types>
tuple(::portable_stl::allocator_arg_t, t_allocator, t_types...) -> tuple<t_types...>;

template<class t_allocator, class... t_types>
tuple(::portable_stl::allocator_arg_t, t_allocator, tuple<t_types...>) -> tuple<t_types...>;

} // namespace portable_stl

#endif /* PSTL_TUPLE_DEDUCTION_H */
