// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_primary_template.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_PRIMARY_TEMPLATE_H
#define PSTL_IS_PRIMARY_TEMPLATE_H

#include "../metaprogramming/other_transformations/conditional_bool_constant.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/is_detected.h"
#include "../metaprogramming/type_relations/is_same.h"

namespace portable_stl {
namespace iterator_helper {

  /**
   * @brief is_primary_template implementation pridicate.
   * @tparam t_type Tested type.
   */
  template<class t_type>
  using is_prim_template_pred
    = ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_same<t_type, typename t_type::primary_template_>>;

  /**
   * @brief  Helper class to check if given t_type is a primary template type.
   * @tparam t_type Tested type.
   */
  template<class t_type> using is_primary_template = ::portable_stl::is_detected<is_prim_template_pred, t_type>;
} // namespace iterator_helper
} // namespace portable_stl

#endif /* PSTL_IS_PRIMARY_TEMPLATE_H */
