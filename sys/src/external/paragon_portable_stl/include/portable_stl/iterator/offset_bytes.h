// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="offset_bytes.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_OFFSET_BYTES_H
#define PSTL_OFFSET_BYTES_H

#include "../common/size_t.h"
#include "../metaprogramming/cv_modifications/remove_const.h"

namespace portable_stl {

/**
 * @brief Add offset to pointer.
 *
 * @tparam t_type the type of pointer value
 * @param pointer the pointer to object.
 * @param offset the offset for pointer increase.
 * @return pointer + offset[in bytes].
 */
template<class t_type> constexpr inline t_type *offset_bytes(t_type *pointer, ::portable_stl::size_t offset) noexcept {
  return static_cast<t_type *>(static_cast<void *>(&(
    static_cast<char *>(static_cast<void *>(const_cast<::portable_stl::remove_const_t<t_type> *>(pointer)))[offset])));
}

} // namespace portable_stl

#endif // PSTL_OFFSET_BYTES_H
