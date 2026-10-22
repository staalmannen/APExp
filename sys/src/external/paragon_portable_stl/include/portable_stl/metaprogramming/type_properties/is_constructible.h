// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_constructible.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_CONSTRUCTIBLE_H
#define PSTL_IS_CONSTRUCTIBLE_H

#include "../../utility/general/declval.h"
#include "../helper/integral_constant.h"
#include "../logical_operator/conjunction.h"
#include "../logical_operator/disjunction.h"
#include "is_destructible.h"

namespace portable_stl {
namespace type_properties_helpers {
  /**
   * @brief Check t_type is a constructible with argumetns t_args.
   * @tparam t_type type for check.
   * @tparam t_args arguments for constructor.
   */
  template<class t_type, class... t_args> class is_constructible_wrapper final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::bool_constant<__is_constructible(t_type, t_args...)>;
  };
} // namespace type_properties_helpers

/**
 * @brief Check t_type is a constructible with argumetns t_args.
 * @tparam t_type type for check.
 * @tparam t_args arguments for constructor.
 */
template<class t_type, class... t_args>
using is_constructible =
  typename ::portable_stl::type_properties_helpers::is_constructible_wrapper<t_type, t_args...>::type;
} // namespace portable_stl

#endif // PSTL_IS_CONSTRUCTIBLE_H
