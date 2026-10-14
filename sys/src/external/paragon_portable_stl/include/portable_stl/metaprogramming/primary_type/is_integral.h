// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_integral.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_INTEGRAL_H
#define PSTL_IS_INTEGRAL_H

#include "../cv_modifications/remove_cv.h"
#include "../logical_operator/disjunction.h"
#include "../type_relations/is_same.h"

#if defined(__cpp_char8_t)
#  include "has_char8_t/is_same_char8_t.h"
#else
#  include "default/is_same_char8_t.h"
#endif

namespace portable_stl {
/**
 * @brief t_type is an integral type.
 * @tparam t_type type for check.
 */
template<class t_type>
using is_integral = ::portable_stl::disjunction<
  ::portable_stl::is_same<::portable_stl::remove_cv_t<t_type>, bool>,
  ::portable_stl::is_same<::portable_stl::remove_cv_t<t_type>, char>,
  ::portable_stl::is_same<::portable_stl::remove_cv_t<t_type>, wchar_t>,
  ::portable_stl::metaprogramming_helper::is_same_char8_t<::portable_stl::remove_cv_t<t_type>>,
  ::portable_stl::is_same<::portable_stl::remove_cv_t<t_type>, char16_t>,
  ::portable_stl::is_same<::portable_stl::remove_cv_t<t_type>, char32_t>,
  ::portable_stl::is_same<::portable_stl::remove_cv_t<t_type>, signed char>,
  ::portable_stl::is_same<::portable_stl::remove_cv_t<t_type>, unsigned char>,
  ::portable_stl::is_same<::portable_stl::remove_cv_t<t_type>, signed short int>,
  ::portable_stl::is_same<::portable_stl::remove_cv_t<t_type>, unsigned short int>,
  ::portable_stl::is_same<::portable_stl::remove_cv_t<t_type>, signed int>,
  ::portable_stl::is_same<::portable_stl::remove_cv_t<t_type>, unsigned int>,
  ::portable_stl::is_same<::portable_stl::remove_cv_t<t_type>, signed long int>,
  ::portable_stl::is_same<::portable_stl::remove_cv_t<t_type>, unsigned long int>,
  ::portable_stl::is_same<::portable_stl::remove_cv_t<t_type>, signed long long int>,
  ::portable_stl::is_same<::portable_stl::remove_cv_t<t_type>, unsigned long long int>>;

} // namespace portable_stl

#endif // PSTL_IS_INTEGRAL_H
