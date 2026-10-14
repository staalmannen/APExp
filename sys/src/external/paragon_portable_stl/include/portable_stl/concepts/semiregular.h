// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="semiregular.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_SEMIREGULAR_H
#define PSTL_SEMIREGULAR_H

#include "../metaprogramming/logical_operator/conjunction.h"
#include "copyable.h"
#include "default_initializable.h"

namespace portable_stl {

/**
 * @brief The semiregular 'concept' specifies that a type is both copyable and default constructible. It is satisfied by
 * types that behave similarly to built-in types like int, except that they need not support comparison with ==.
 *
 * @tparam t_type Tested type.
 */
template<class t_type>
using semiregular
  = ::portable_stl::conjunction<::portable_stl::copyable<t_type>, ::portable_stl::default_initializable<t_type>>;

} // namespace portable_stl

#endif /* PSTL_SEMIREGULAR_H */
