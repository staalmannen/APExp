// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="copy_n.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_COPY_N_H
#define PSTL_COPY_N_H

#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/type_traits/has_input_iterator_category.h"
#include "../metaprogramming/type_traits/has_random_access_iterator_category.h"
#include "../utility/convert_to_integral.h"
#include "copy.h"

namespace portable_stl {

  template<class t_input_iterator,
           class t_size,
           class t_output_iterator,
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<
               ::portable_stl::has_input_iterator_category<t_input_iterator>,
               ::portable_stl::negation<::portable_stl::has_random_access_iterator_category<t_input_iterator>>>,
             void *>
           = nullptr>
  inline t_output_iterator copy_n(t_input_iterator first, t_size orig_num, t_output_iterator result) {
  using t_integral_size = decltype(portable_stl::convert_to_integral(orig_num));
  t_integral_size num   = orig_num;
  if (num > 0) {
    *result = *first;
    ++result;
    for (--num; num > 0; --num) {
      ++first;
      *result = *first;
      ++result;
    }
  }
  return result;
}

template<class t_input_iterator,
         class t_size,
         class t_output_iterator,
         ::portable_stl::
           enable_if_bool_constant_t<::portable_stl::has_random_access_iterator_category<t_input_iterator>, void *>
         = nullptr>
inline t_output_iterator copy_n(t_input_iterator first, t_size orig_num, t_output_iterator result) {
  using difference_type = typename iterator_traits<t_input_iterator>::difference_type ;
  using t_integral_size = decltype(portable_stl::convert_to_integral(orig_num));
  t_integral_size num   = orig_num;
  return ::portable_stl::copy(first, first + static_cast<difference_type>(num), result);
}
} // namespace portable_stl

#endif // PSTL_COPY_N_H
