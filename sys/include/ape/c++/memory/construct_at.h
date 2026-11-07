// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="construct_at.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CONSTRUCT_AT_H
#define PSTL_CONSTRUCT_AT_H

#include "../metaprogramming/type_properties/is_nothrow_constructible.h"
#include "../utility/general/forward.h"
#include "new_selector.h"
#include "voidify.h"

namespace std {
/**
 * @brief Construct the t_type object at the location memory.
 * was noexcept(::std::is_nothrow_constructible<t_type, t_args...>{}())
 * @tparam t_type the type of object.
 * @tparam t_args the types of arguments.
 * @param location the pointer to memory for construct object.
 * @param args arguments for contruction.
 * @return pointer to the constructed object.
 */
template<class t_type, class... t_args>
constexpr inline static t_type *construct_at(t_type *location, t_args &&...args) noexcept(
  noexcept(::new(::std::voidify(*location)) t_type(::std::forward<t_args>(args)...))) {
  return ::new (::std::voidify(*location)) t_type(::std::forward<t_args>(args)...);
}
} // namespace std

#endif // PSTL_CONSTRUCT_AT_H
