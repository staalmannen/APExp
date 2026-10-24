// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="iter_reference_t.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ITER_REFERENCE_T_H
#define PSTL_ITER_REFERENCE_T_H

#include "../concepts/dereferenceable.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"

namespace portable_stl {
namespace iterator_helper {
  /**
   * @brief Helper to check if type is dereferenceable.
   * @tparam t_type Teseted type.
   */
  template<class t_type, class = ::portable_stl::dereferenceable<t_type>> class iter_reference_t_impl final {
  public:
    /**
     * @brief Result type.
     */
    using type = decltype(*::portable_stl::declval<t_type &>());
  };

  /**
   * @brief Helper to check if type is dereferenceable.
   * @tparam t_type Teseted type.
   */
  template<class t_type> class iter_reference_t_impl<t_type, ::portable_stl::false_type> final {};
} // namespace iterator_helper

/**
 * @brief Computes the reference type of t_type.
 * The exposition-only 'concept' _dereferenceable_ is satisfied if and only if the expression *declval<T&>() is valid
 * and has a referenceable type (in particular, not void).
 * @tparam t_type The given type.
 */
template<class t_type> using iter_reference_t = typename iterator_helper::iter_reference_t_impl<t_type>::type;

} // namespace portable_stl

#endif /* PSTL_ITER_REFERENCE_T_H */
