// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_trivial.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_TRIVIAL_H
#define PSTL_IS_TRIVIAL_H

#include "../logical_operator/conjunction.h"
#include "is_trivially_copyable.h"
#include "is_trivially_default_constructible.h"

namespace std {
/**
 * @brief Check t_type is a Trivial. (Can default construct with trivial function and can copy with trivial function.)
 * @tparam t_type type for check.
 */
template<class t_type>
using is_trivial = ::std::conjunction<::std::is_trivially_default_constructible<t_type>,
                                               ::std::is_trivially_copyable<t_type>>;
} // namespace std

#endif // PSTL_IS_TRIVIAL_H
