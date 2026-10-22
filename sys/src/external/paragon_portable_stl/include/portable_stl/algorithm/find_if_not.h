// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="find_if_not.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_FIND_IF_NOT_H
#define PSTL_FIND_IF_NOT_H

namespace portable_stl {
/**
 * @brief Searches for an element for which predicate pred returns false.
 *
 * @tparam t_input_iterator_type Must meet the requirements of LegacyInputIterator.
 * @tparam t_predicate Unary predicate type (must meet the requirements of Predicate).
 * @param iter_first The range of elements to examine.
 * @param iter_last The range of elements to examine.
 * @param pred Unary predicate.
 * @return The first iterator it in the range [iter_first, iter_last) satisfying the pred(*it) is false condition or
 * last if there is no such iterator.
 */
template<class t_input_iterator_type, class t_predicate>
inline t_input_iterator_type find_if_not(
  t_input_iterator_type iter_first, t_input_iterator_type iter_last, t_predicate pred) {
  for (; iter_first != iter_last; ++iter_first) {
    if (!pred(*iter_first)) {
      break;
    }
  }
  return iter_first;
}
} // namespace portable_stl

#endif /* PSTL_FIND_IF_NOT_H */
