// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="voidify.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_VOIDIFY_H
#define PSTL_VOIDIFY_H

#include "../metaprogramming/cv_modifications/copy_cv.h"
#include "../metaprogramming/pointer_modifications/add_pointer.h"
#include "addressof.h"
namespace portable_stl {
/**
 * @brief Get void pointer from object reference.
 *
 * @tparam t_type the type of object.
 * @param source the source object.
 * @return void pointer to the object memory location with cv modifiers.
 */
template<typename t_type>
constexpr static auto voidify(t_type &source) noexcept
  -> ::portable_stl::add_pointer_t<::portable_stl::copy_cv_t<void, t_type>> {
  return static_cast<::portable_stl::add_pointer_t<::portable_stl::copy_cv_t<void, t_type>>>(
    ::portable_stl::addressof(source));
}

} // namespace portable_stl

#endif // PSTL_VOIDIFY_H
