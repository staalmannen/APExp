// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="reference_wrapper_deduction.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_REFERENCE_WRAPPER_DEDUCTION_H
#define PSTL_REFERENCE_WRAPPER_DEDUCTION_H

#include "reference_wrapper.h"

namespace portable_stl {

/**
 * @brief Deduction guides.
 *
 * @tparam t_type The given type.
 */
template<class t_type> reference_wrapper(t_type &) -> reference_wrapper<t_type>;

} // namespace portable_stl

#endif /* PSTL_REFERENCE_WRAPPER_DEDUCTION_H */
