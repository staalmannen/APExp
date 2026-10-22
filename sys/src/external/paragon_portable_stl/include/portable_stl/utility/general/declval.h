// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="declval.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_DECLVAL_H
#define PSTL_DECLVAL_H

#include "../../metaprogramming/reference_modifications/add_rvalue_reference.h"

namespace portable_stl {

/**
 * @brief Converts any type t_type to a reference type, making it possible to use member functions in the operand of the
 * decltype specifier without the need to go through constructors.
 *
 * @tparam t_type The type for convert.
 * @return reference to the t_type.
 */
template<class t_type>::portable_stl::add_rvalue_reference_t<t_type> declval() noexcept;

} // namespace portable_stl

#endif /* PSTL_DECLVAL_H */
