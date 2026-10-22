// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="disjunction.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_DISJUNCTION_H
#define PSTL_DISJUNCTION_H

#include "../helper/integral_constant.h"
#include "../other_transformations/conditional.h"
#include "bool_constant_get.h"

namespace portable_stl {
namespace logical_operator_helper {
  namespace processor {
    /**
     * @brief The class template disjunction forms the logical disjunction of its template t_bool_constant arguments.
     * Implementation for one or first false arguments.
     * @tparam t_bool_constant Porcessing argument.
     */
    template<class t_first, class... t_other> class disjunction final {
    public:
      /**
       * @brief Value getter.
       *
       * @return The current constant value.
       */
      using type = t_first;
    };

    /**
     * @brief @brief The class template disjunction forms the logical disjunction of its template t_bool_constant
     * arguments. Implementation for first false argument.
     * @tparam t_bool_constant Porcessing arguments.
     */
    template<class t_next, class... t_other> class disjunction<::portable_stl::false_type, t_next, t_other...> final {
    public:
      /**
       * @brief Value getter.
       *
       * @return The current constant value.
       */
      using type = typename disjunction<::portable_stl::bool_constant_get<t_next>, t_other...>::type;
    };
  } // namespace processor

  /**
   * @brief The class template disjunction forms the logical disjunction of its template t_bool_constant arguments.
   *
   * @tparam t_bool_constant Porcessing arguments.
   */
  template<class... t_bool_constant> class disjunction final {
  public:
    /**
     * @brief Value getter.
     * Implementation for zero arguments.
     * @return The current constant value.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief The class template disjunction forms the logical disjunction of its template t_bool_constant arguments.
   * Implementation non for zero arguments.
   * @tparam t_bool_constant Porcessing arguments.
   * @tparam t_bool_constants Porcessing arguments.
   */
  template<class t_bool_constant, class... t_bool_constants>
  class disjunction<t_bool_constant, t_bool_constants...> final {
  public:
    /**
     * @brief Value getter.
     *
     * @return the logical disjunction of its template t_bool_constant arguments.
     */
    using type =
      typename processor::disjunction<::portable_stl::bool_constant_get<t_bool_constant>, t_bool_constants...>::type;
  };
} // namespace logical_operator_helper

/**
 * @brief The class template disjunction forms the logical disjunction(||) of its template t_bool_constant arguments.
 *
 * @tparam t_bool_constant Porcessing arguments.
 */
template<class... t_bool_constant>
using disjunction = typename ::portable_stl::logical_operator_helper::disjunction<t_bool_constant...>::type;
} // namespace portable_stl

#endif // PSTL_DISJUNCTION_H
