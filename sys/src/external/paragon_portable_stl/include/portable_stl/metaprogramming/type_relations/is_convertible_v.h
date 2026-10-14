// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_convertible_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_CONVERTIBLE_V_H
#define PSTL_IS_CONVERTIBLE_V_H

#include "is_convertible.h"
namespace portable_stl {
/**
 * @brief The t_type_from can be converted to the t_type_to.
 *
 * @tparam t_type_from
 * @tparam t_type_to
 */
template<class t_type> constexpr inline bool is_convertible_v = ::portable_stl::is_convertible<t_type>{}();
} // namespace portable_stl

#endif // PSTL_IS_CONVERTIBLE_V_H
