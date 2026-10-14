// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="regular.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_REGULAR_H
#define PSTL_REGULAR_H

#include "../metaprogramming/logical_operator/conjunction.h"
#include "equality_comparable.h"
#include "semiregular.h"

namespace portable_stl {
/**
 * @brief The regular 'concept' specifies that a type is regular, that is, it is copyable, default constructible, and
 * equality comparable. It is satisfied by types that behave similarly to built-in types like int, and that are
 * comparable with ==.
 *
 * @tparam t_type Tested type.
 */
template<class t_type>
using regular
  = ::portable_stl::conjunction<::portable_stl::semiregular<t_type>, ::portable_stl::equality_comparable<t_type>>;
} // namespace portable_stl

#endif /* PSTL_REGULAR_H */
