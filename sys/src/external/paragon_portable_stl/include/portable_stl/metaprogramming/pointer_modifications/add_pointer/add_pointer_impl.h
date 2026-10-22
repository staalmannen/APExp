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

#include "../../other_transformations/void_t.h"
#include "../../reference_modifications/remove_reference.h"

namespace portable_stl {
namespace pointer_modifications_helpers {
  /**
   * @brief Adds a pointer to the given type.
   * Pointer can not be added.
   * @tparam t_type The given type.
   */
  template<class t_type, class = void> class add_pointer_impl final {
  public:
    /**
     * @brief Pointer to t_type or to the type referenced by t_type.
     *
     */
    using type = t_type;
  };

  /**
   * @brief Adds a pointer to the given type.
   * Pointer can be added.
   * @tparam t_type The given type.
   */
  template<class t_type>
  class add_pointer_impl<t_type, ::portable_stl::void_t<::portable_stl::remove_reference_t<t_type> *>> final {
  public:
    /**
     * @brief Pointer to t_type or to the type referenced by t_type.
     *
     */
    using type = ::portable_stl::remove_reference_t<t_type> *;
  };

  /**
   * @brief Adds a pointer to the given type.
   *
   * @tparam t_type The given type.
   */
  template<class t_type> using add_pointer_t_impl = typename add_pointer_impl<t_type>::type;
} // namespace pointer_modifications_helpers
} // namespace portable_stl

#endif // PSTL_ADD_POINTER_IMPL_H
