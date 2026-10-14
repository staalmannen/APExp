// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_any_of.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_ANY_OF_H
#define PSTL_IS_ANY_OF_H

#include "../logical_operator/disjunction.h"
#include "is_same.h"

namespace portable_stl {
namespace type_relations_helper {
  /**
   * @brief is_any_of wrapper;
   *
   * @tparam t_checked_type
   * @tparam ...t_types
   */
  template<class t_checked_type, class... t_types> class is_any_of_wrapper final {
  public:
    using type = ::portable_stl::disjunction<::portable_stl::is_same<t_checked_type, t_types>...>;
  };
} // namespace type_relations_helper

/**
 * @brief Checks if t_types contains t_checked_type.
 * (Non-standerd class)
 * @tparam t_checked_type Checked type.
 * @tparam ...t_types All types to check in.
 */
template<class t_checked_type, class... t_types>
using is_any_of = typename type_relations_helper::is_any_of_wrapper<t_checked_type, t_types...>::type;
} // namespace portable_stl

#endif /* PSTL_IS_ANY_OF_H */
