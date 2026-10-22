// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_rvalue_referenceable_v.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_RVALUE_REFERENCEABLE_V_H
#define PSTL_IS_RVALUE_REFERENCEABLE_V_H

#include "is_rvalue_referenceable.h"

namespace portable_stl {
/**
 * @brief Check the t_type is rvalue referenceable type.
 * @tparam t_type for check.
 */
template<class t_type>
constexpr inline bool is_rvalue_referenceable_v = ::portable_stl::is_rvalue_referenceable<t_type>{}();

} // namespace portable_stl

#endif // PSTL_IS_RVALUE_REFERENCEABLE_V_H
