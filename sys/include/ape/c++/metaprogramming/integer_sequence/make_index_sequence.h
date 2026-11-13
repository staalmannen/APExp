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

#include "../../common/compiler_builtins.h"

/*
 * BY CAPABILITY, NOT BY COMPILER NAME.  This was
 * `#if (defined(__clang__) || defined(_MSC_VER))' ... `#else' --
 * i.e. "gcc" for everything that is not clang or Microsoft -- so
 * cpfe, which is neither, reached gcc's `__integer_pack' and did not
 * have it.  The third arm is plain C++14 and is new; see
 * `common/compiler_builtins.h' for the whole shape.
 */
#if PSTL_HAS_MAKE_INTEGER_SEQ
#  include "make_integer_seq.h"
#elif PSTL_HAS_INTEGER_PACK
#  include "integer_pack.h"
#else
#  include "make_integer_seq_generic.h"
#endif

namespace std {

template<::std::size_t t_size>
using make_index_sequence = make_integer_sequence<::std::size_t, t_size>;

template<class... t_types> using index_sequence_for = make_index_sequence<sizeof...(t_types)>;

} // namespace std

#endif /* PSTL_MAKE_INDEX_SEQUENCE_H */
