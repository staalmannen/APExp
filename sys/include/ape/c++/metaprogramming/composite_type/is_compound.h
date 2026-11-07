// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_compound.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_COMPOUND_H
#define PSTL_IS_COMPOUND_H

#include "../logical_operator/negation.h"
#include "is_fundamental.h"

namespace std {
/**
 * @brief t_type is an compound type.
 * @tparam t_type the type for check.
 */
template<class t_type> using is_compound = ::std::negation<::std::is_fundamental<t_type>>;

} // namespace std

#endif // PSTL_IS_COMPOUND_H
