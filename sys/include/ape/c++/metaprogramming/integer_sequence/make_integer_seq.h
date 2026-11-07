// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="make_integer_seq.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MAKE_INTEGER_SEQ_H
#define PSTL_MAKE_INTEGER_SEQ_H

#include "integer_sequence.h"

namespace std {

/**
 * @brief Alias template make_integer_sequence
 *
 * @tparam t_type Elements type.
 * @tparam t_num Number of elements.
 */
template<typename t_type, t_type t_num>
using make_integer_sequence = __make_integer_seq<integer_sequence, t_type, t_num>;

} // namespace std

#endif /* PSTL_MAKE_INTEGER_SEQ_H */
