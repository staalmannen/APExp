// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="add_pointer.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ADD_POINTER_H
#define PSTL_ADD_POINTER_H

#if defined(__has_builtin)
#  if (!(__has_builtin(__add_pointer)))
#    include "add_pointer/add_pointer_impl.h"
#  else
#    include "default/add_pointer_impl.h"
#  endif
#else
#  include "add_pointer/add_pointer_impl.h"
#endif

namespace portable_stl {

/**
 * @brief Adds a pointer to the given type.
 *
 * @tparam t_type The given type.
 */
template<class t_type> class add_pointer final {
public:
  /**
   * @brief Pointer to t_type or to the type referenced by t_type.
   *
   */
  using type = pointer_modifications_helpers::add_pointer_t_impl<t_type>;
};

/**
 * @brief Adds a pointer to the given type.
 *
 * @tparam t_type The given type.
 */
template<class t_type> using add_pointer_t = pointer_modifications_helpers::add_pointer_t_impl<t_type>;
} // namespace portable_stl
#endif // PSTL_ADD_POINTER_H
