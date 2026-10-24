// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="iter_value_t.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ITER_VALUE_T_H
#define PSTL_ITER_VALUE_T_H

#include "../metaprogramming/other_transformations/conditional_bool_constant.h"
#include "../metaprogramming/other_transformations/remove_cvref.h"
#include "../metaprogramming/type_relations/is_base_of.h"
#include "indirectly_readable_traits.h"
#include "is_primary_template.h"
#include "iterator_traits.h"

namespace portable_stl {

/**
 * @brief Compute the associated value types of an iterator.
 *
 * @tparam t_iterator The iterator type.
 */
template<class t_iterator, class t_rm_cvref = ::portable_stl::remove_cvref_t<t_iterator>>
using iter_value_t = typename ::portable_stl::conditional_bool_constant_t<
  iterator_helper::is_primary_template<::portable_stl::iterator_traits<t_rm_cvref>>,
  ::portable_stl::indirectly_readable_traits<t_rm_cvref>,
  ::portable_stl::iterator_traits<t_rm_cvref>>::value_type;
} // namespace portable_stl

#endif /* PSTL_ITER_VALUE_T_H */
