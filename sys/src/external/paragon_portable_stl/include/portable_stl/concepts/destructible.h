// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="destructible.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_DESTRUCTIBLE_H
#define PSTL_DESTRUCTIBLE_H

#include "../metaprogramming/type_properties/is_nothrow_destructible.h"

namespace portable_stl {
/**
 * @brief The 'concept' destructible specifies the concept of all types whose instances can safely be destroyed at the
 * end of their lifetime (including reference types).
 *
 * @tparam t_type Tested type.
 */
template<class t_type> using destructible = typename ::portable_stl::is_nothrow_destructible<t_type>::type;
} // namespace portable_stl

#endif /* PSTL_DESTRUCTIBLE_H */
