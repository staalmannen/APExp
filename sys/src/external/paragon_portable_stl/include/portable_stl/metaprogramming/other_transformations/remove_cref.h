// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="remove_cref.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_REMOVE_CREF_H
#define PSTL_REMOVE_CREF_H

#include "../cv_modifications/remove_const.h"
#include "../reference_modifications/remove_reference.h"

namespace portable_stl {
/**
 * @brief Remove constant and references.
 *
 * @tparam t_type for modify.
 */
template<class t_type> using remove_cref = ::portable_stl::remove_const<::portable_stl::remove_reference_t<t_type>>;

/**
 * @brief Remove constant and references.
 *
 * @tparam t_type for modify.
 */
template<class t_type> using remove_cref_t = typename ::portable_stl::remove_cvref<t_type>::type;
} // namespace portable_stl

#endif // PSTL_REMOVE_CREF_H
