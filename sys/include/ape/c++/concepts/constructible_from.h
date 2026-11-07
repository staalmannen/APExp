// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="constructible_from.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CONSTRUCTIBLE_FROM_H
#define PSTL_CONSTRUCTIBLE_FROM_H

#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/type_properties/is_constructible.h"
#include "destructible.h"

namespace std {
/**
 * @brief The constructible_from 'concept' specifies that a variable of type t_type can be initialized with the given
 * set of argument types arg_types... .
 *
 * @tparam t_type Tested type.
 * @tparam arg_types Given arg types.
 */
template<class t_type, class... arg_types>
using constructible_from = ::std::conjunction<::std::destructible<t_type>,
                                                       ::std::is_constructible<t_type, arg_types...>>;
} // namespace std

#endif /* PSTL_CONSTRUCTIBLE_FROM_H */
