// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="remove_cvref.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_REMOVE_CVREF_H
#define PSTL_REMOVE_CVREF_H

#include "../cv_modifications/remove_cv.h"
#include "../reference_modifications/remove_reference.h"

namespace portable_stl {
/**
 * @brief Remove constant volatile and references.
 *
 * @tparam t_type for modify.
 */
template<class t_type> using remove_cvref = ::portable_stl::remove_cv<::portable_stl::remove_reference_t<t_type>>;

/**
 * @brief Remove constant volatile and references.
 *
 * @tparam t_type for modify.
 */
template<class t_type> using remove_cvref_t = typename ::portable_stl::remove_cvref<t_type>::type;
} // namespace portable_stl

#endif /* PSTL_REMOVE_CVREF_H */
