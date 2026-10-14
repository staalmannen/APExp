// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="iter_rvalue_reference_t.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ITER_RVALUE_REFERENCE_T_H
#define PSTL_ITER_RVALUE_REFERENCE_T_H

#include "../concepts/dereferenceable.h"
#include "../metaprogramming/helper/integral_constant.h"
#include "iter_move.h"

namespace portable_stl {
namespace iterator_helper {
  /**
   * @brief iter_rvalue_reference implementation.
   * Primary template.
   */
  template<class, class = void> class iter_rvalue_reference_impl final {};

  /**
   * @brief iter_rvalue_reference implementation.
   * @tparam t_type Given type.
   */
  template<class t_type> class iter_rvalue_reference_impl<t_type, ::portable_stl::void_t<t_type &>> final {
  public:
    // static_assert(::portable_stl::is_lvalue_referenceable<decltype(::portable_stl::ranges::iter_move(
    //                 ::portable_stl::declval<t_type &>()))>{}(),
    //               "err");
    /**
     * @brief Result type.
     */
    using type = decltype(::portable_stl::ranges::iter_move(::portable_stl::declval<t_type &>()));
  };

} // namespace iterator_helper

/**
 * @brief Computes the rvalue reference type of t_type. The "see below" portion of the constraint on this alias template
 * is satisfied if and only if the expression ranges::iter_move(declval<t_type&>()) is valid and has a referenceable
 * type (in particular, not void).
 *
 * @tparam t_type Given type.
 */
template<class t_type>
using iter_rvalue_reference_t = typename ::portable_stl::iterator_helper::iter_rvalue_reference_impl<t_type>::type;
} // namespace portable_stl

#endif /* PSTL_ITER_RVALUE_REFERENCE_T_H */
