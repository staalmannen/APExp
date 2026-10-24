// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="rebind_alloc.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_REBIND_ALLOC_H
#define PSTL_REBIND_ALLOC_H

namespace portable_stl {

/**
 * @brief
 *
 * @tparam t_traits
 * @tparam t_type
 */
template<class t_traits, class t_type> using rebind_alloc = typename t_traits::template rebind_alloc<t_type>;
} // namespace portable_stl

#endif // PSTL_REBIND_ALLOC_H
