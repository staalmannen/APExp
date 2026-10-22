// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="make_index_sequence.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MAKE_INDEX_SEQUENCE_H
#define PSTL_MAKE_INDEX_SEQUENCE_H

#include "../../common/size_t.h"

#if (defined(__clang__) || defined(_MSC_VER))
#  include "make_integer_seq.h"
#else
#  include "integer_pack.h"
#endif

namespace portable_stl {

template<::portable_stl::size_t t_size>
using make_index_sequence = make_integer_sequence<::portable_stl::size_t, t_size>;

template<class... t_types> using index_sequence_for = make_index_sequence<sizeof...(t_types)>;

} // namespace portable_stl

#endif /* PSTL_MAKE_INDEX_SEQUENCE_H */
