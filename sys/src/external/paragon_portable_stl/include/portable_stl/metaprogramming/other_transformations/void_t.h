// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="void_t.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_VOID_T_H
#define PSTL_VOID_T_H

namespace portable_stl {
/**
 * @brief Wrap any types as void.
 */
template<class...> using void_t = void;
} // namespace portable_stl

#endif // PSTL_VOID_T_H
