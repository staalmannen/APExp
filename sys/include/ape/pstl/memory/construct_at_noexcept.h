// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="construct_at_noexcept.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CONSTRUCT_AT_NOEXCEPT_H
#define PSTL_CONSTRUCT_AT_NOEXCEPT_H

#include "../metaprogramming/type_properties/is_nothrow_constructible.h"
#include "../utility/general/forward.h"
#include "new_selector.h"
#include "voidify.h"

namespace portable_stl {
/**
 * @brief Construct the t_type object at the location memory.
 * Suppress all exceptions.
 * @tparam t_type the type of object.
 * @tparam t_args the types of arguments.
 * @param location the pointer to memory for construct object.
 * @param args arguments for contruction.
 * @return pointer to the constructed object.
 */
template<class t_type, class... t_args>
constexpr inline static t_type *construct_at_noexcept(t_type *location, t_args &&...args) noexcept {
    return ::portable_stl::exception_pack<::portable_stl::portable_stl_error,
                                          ::portable_stl::portable_stl_error::allocate_error>{}(
             [](t_type *location_val, t_args &&...args_val) -> t_type * {
               return ::new (::portable_stl::voidify(*location_val)) t_type(::portable_stl::forward<t_args>(args_val)...);
             },
             location, args...)
      .value_or(nullptr);
}
} // namespace portable_stl

#endif // PSTL_CONSTRUCT_AT_NOEXCEPT_H
