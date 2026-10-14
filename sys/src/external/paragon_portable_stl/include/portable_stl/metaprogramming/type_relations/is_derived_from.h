// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_derived_from.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_DERIVED_FROM_H
#define PSTL_IS_DERIVED_FROM_H
#include "../cv_modifications/add_cv.h"
#include "../logical_operator/conjunction.h"
#include "../pointer_modifications/add_pointer.h"
#include "is_base_of.h"
#include "is_convertible.h"

namespace portable_stl {
/**
 * @brief Check if t_base is a class type that is either t_derived or a public and unambiguous base of t_derived,
 * ignoring cv-qualifiers.
 *
 * @tparam t_derived the derived class.
 * @tparam t_base the base class.
 */
template<class t_derived, class t_base>
using is_derived_from = ::portable_stl::conjunction<
  ::portable_stl::is_base_of<t_base, t_derived>,
  ::portable_stl::is_convertible<::portable_stl::add_pointer_t<::portable_stl::add_cv_t<t_derived>>,
                                 ::portable_stl::add_pointer_t<::portable_stl::add_cv_t<t_base>>>>;
} // namespace portable_stl

#endif // PSTL_IS_DERIVED_FROM_H
