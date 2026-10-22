// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_forward_as.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TUPLE_FORWARD_AS_H
#define PSTL_TUPLE_FORWARD_AS_H

#include "fwd_decl_tuple.h"
#include "../../utility/general/forward.h"

namespace portable_stl {
/**
 * @brief Constructs a tuple of references to the arguments in args suitable for forwarding as an argument to a
 * function. The tuple has rvalue reference data members when rvalues are used as arguments, and otherwise has lvalue
 * reference data members.
 *
 * @tparam t_types
 * @param args zero or more arguments to construct the tuple from
 * @return A ::tuple object created as if by ::tuple<t_types&&...>(::forward<t_types>(args)...)
 */
template<class... t_types> constexpr tuple<t_types &&...> forward_as_tuple(t_types &&...args) noexcept {
  return ::portable_stl::tuple<t_types &&...>(::portable_stl::forward<t_types>(args)...);
}
} // namespace portable_stl

#endif /* PSTL_TUPLE_FORWARD_AS_H */
