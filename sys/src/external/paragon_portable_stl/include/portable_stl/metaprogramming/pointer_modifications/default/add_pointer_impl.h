// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="add_pointer_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ADD_POINTER_IMPL_H
#define PSTL_ADD_POINTER_IMPL_H

namespace portable_stl {
namespace pointer_modifications_helpers {
  /**
   * @brief Adds a pointer to the given type.
   * Pointer can not be added.
   * @tparam t_type The given type.
   */
  template<class t_type> using add_pointer_t_impl = __add_pointer(t_type);
} // namespace pointer_modifications_helpers
} // namespace portable_stl

#endif // PSTL_ADD_POINTER_IMPL_H
