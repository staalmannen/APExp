// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="conjunction.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CONJUNCTION_H
#define PSTL_CONJUNCTION_H

#include "../helper/integral_constant.h"
#include "bool_constant_get.h"

namespace portable_stl {
namespace logical_operator_helper {
  namespace processor {
    /**
     * @brief The class template conjunction forms the logical conjunction of its template t_bool_constant arguments.
     * Implementation for one or first false arguments.
     * @tparam t_bool_constant Porcessing arguments.
     */
    template<class t_first, class... t_other> class conjunction final {
    public:
      /**
       * @brief Value getter.
       *
       * @return The current constant value.
       */
      using type = t_first;
    };

    /**
     * @brief The class template conjunction forms the logical conjunction of its template t_bool_constant arguments.
     * Implementation for first true argument.
     * @tparam t_bool_constant Porcessing arguments.
     */
    template<class t_next, class... t_other> class conjunction<::portable_stl::true_type, t_next, t_other...> final {
    public:
      /**
       * @brief Value getter.
       *
       * @return The current constant value.
       */
      using type = typename conjunction<::portable_stl::bool_constant_get<t_next>, t_other...>::type;
    };
  } // namespace processor

  /**
   * @brief The class template conjunction forms the logical conjunction of its template t_bool_constant arguments.
   * Implementation for zero arguments.
   * @tparam t_bool_constant Porcessing arguments.
   */
  template<class... t_bool_constant> class conjunction final {
  public:
    /**
     * @brief Value getter.
     *
     * @return The current constant value.
     */
    using type = ::portable_stl::true_type;
  };

  /**
   * @brief The class template conjunction forms the logical conjunction of its template t_bool_constant arguments.
   * Implementation non for zero arguments.
   * @tparam t_bool_constant Porcessing arguments.
   */
  template<class t_bool_constant, class... t_bool_constants>
  class conjunction<t_bool_constant, t_bool_constants...> final {
  public:
    /**
     * @brief Value getter.
     *
     * @return The current constant value.
     */
    using type =
      typename processor::conjunction<::portable_stl::bool_constant_get<t_bool_constant>, t_bool_constants...>::type;
  };
} // namespace logical_operator_helper

/**
 * @brief The class template conjunction forms the logical conjunction(&&) of its template t_bool_constant arguments.
 *
 * @tparam t_bool_constant Porcessing arguments.
 */
template<class... t_bool_constant>
using conjunction = typename ::portable_stl::logical_operator_helper::conjunction<t_bool_constant...>::type;

} // namespace portable_stl

#endif // PSTL_CONJUNCTION_H
