// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_tie.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TUPLE_TIE_H
#define PSTL_TUPLE_TIE_H

#include "fwd_decl_tuple.h"

namespace portable_stl {
/**
 * @brief Creates a tuple of lvalue references to its arguments or instances of ::ignore.
 *
 * @tparam t_types
 * @param args zero or more lvalue arguments to construct the tuple from.
 * @return A ::tuple object containing lvalue references.
 */
template<class... t_types> constexpr ::portable_stl::tuple<t_types &...> tie(t_types &...args) noexcept {
  using t_tuple = ::portable_stl::tuple<t_types &...>;
  return t_tuple(args...);
}
} // namespace portable_stl

#endif /* PSTL_TUPLE_TIE_H */
