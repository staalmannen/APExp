// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="integral.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INTEGRAL_H
#define PSTL_INTEGRAL_H

#include "../metaprogramming/primary_type/is_integral.h"

namespace std {
/**
 * @brief The 'concept' integral<t_type> is satisfied if and only if t_type is an integral type.
 *
 * @tparam t_type Tested type.
 */
template<class t_type> using integral = ::std::is_integral<t_type>;
} // namespace std

#endif /* PSTL_INTEGRAL_H */
