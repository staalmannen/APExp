// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="integer_pack.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INTEGER_PACK_H
#define PSTL_INTEGER_PACK_H

#include "integer_sequence.h"

namespace portable_stl {

/**
 * @brief Alias template make_integer_sequence
 *
 * @tparam t_type Elements type.
 * @tparam t_num Number of elements.
 */
template<typename t_type, t_type t_num>
using make_integer_sequence = integer_sequence<t_type, __integer_pack(t_num)...>;

} // namespace portable_stl

#endif /* PSTL_INTEGER_PACK_H */
