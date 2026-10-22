// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="lexicographical_compare.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_LEXICOGRAPHICAL_COMPARE_H
#define PSTL_LEXICOGRAPHICAL_COMPARE_H

#include "comp.h"
#include "comp_ref_type.h"

namespace portable_stl {
namespace algorithm_helper {
  template<class t_compare, class t_input_iterator1, class t_input_iterator2>
  bool lexicographical_compare_impl0(t_input_iterator1 first1,
                                     t_input_iterator1 last1,
                                     t_input_iterator2 first2,
                                     t_input_iterator2 last2,
                                     t_compare         comp) {
    for (; first2 != last2; ++first1, (void)++first2) {
      if (first1 == last1 || comp(*first1, *first2)) {
        return true;
      }
      if (comp(*first2, *first1)) {
        return false;
      }
    }
    return false;
  }

  template<class t_input_iterator1, class t_input_iterator2, class t_compare>
  inline bool lexicographical_compare_impl(t_input_iterator1 first1,
                                           t_input_iterator1 last1,
                                           t_input_iterator2 first2,
                                           t_input_iterator2 last2,
                                           t_compare         comp) {
    return lexicographical_compare_impl0<::portable_stl::algorithm_helper::comp_ref_type<t_compare>>(
      first1, last1, first2, last2, comp);
  }
} // namespace algorithm_helper

template<class t_input_iterator1, class t_input_iterator2>
inline bool lexicographical_compare(
  t_input_iterator1 first1, t_input_iterator1 last1, t_input_iterator2 first2, t_input_iterator2 last2) {
  return algorithm_helper::lexicographical_compare_impl(
    first1, last1, first2, last2, ::portable_stl::algorithm_helper::less<>());
}
} // namespace portable_stl

#endif // PSTL_LEXICOGRAPHICAL_COMPARE_H
