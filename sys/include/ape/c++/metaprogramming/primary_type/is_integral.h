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

namespace std {
/**
 * @brief t_type is an integral type.
 * @tparam t_type type for check.
 */
template<class t_type>
using is_integral = ::std::disjunction<
  ::std::is_same<::std::remove_cv_t<t_type>, bool>,
  ::std::is_same<::std::remove_cv_t<t_type>, char>,
  ::std::is_same<::std::remove_cv_t<t_type>, wchar_t>,
  ::std::metaprogramming_helper::is_same_char8_t<::std::remove_cv_t<t_type>>,
  ::std::is_same<::std::remove_cv_t<t_type>, char16_t>,
  ::std::is_same<::std::remove_cv_t<t_type>, char32_t>,
  ::std::is_same<::std::remove_cv_t<t_type>, signed char>,
  ::std::is_same<::std::remove_cv_t<t_type>, unsigned char>,
  ::std::is_same<::std::remove_cv_t<t_type>, signed short int>,
  ::std::is_same<::std::remove_cv_t<t_type>, unsigned short int>,
  ::std::is_same<::std::remove_cv_t<t_type>, signed int>,
  ::std::is_same<::std::remove_cv_t<t_type>, unsigned int>,
  ::std::is_same<::std::remove_cv_t<t_type>, signed long int>,
  ::std::is_same<::std::remove_cv_t<t_type>, unsigned long int>,
  ::std::is_same<::std::remove_cv_t<t_type>, signed long long int>,
  ::std::is_same<::std::remove_cv_t<t_type>, unsigned long long int>>;

} // namespace std

#endif // PSTL_IS_INTEGRAL_H
