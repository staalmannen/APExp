// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_constructible_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_CONSTRUCTIBLE_V_H
#define PSTL_IS_CONSTRUCTIBLE_V_H

#include "is_constructible.h"
namespace portable_stl {
/**
 * @brief Check t_type is a constructible with argumetns t_args.
 * @tparam t_type type for check.
 * @tparam t_args arguments for constructor.
 */
template<class t_type, class... t_args>
constexpr inline bool is_constructible_v = ::portable_stl::is_constructible<t_type, t_args...>{}();
} // namespace portable_stl

#endif // PSTL_IS_CONSTRUCTIBLE_V_H
