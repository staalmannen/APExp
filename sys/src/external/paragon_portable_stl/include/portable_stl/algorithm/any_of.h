// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="any_of.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ANY_OF_H
#define PSTL_ANY_OF_H

namespace portable_stl {

/**
 * @brief Checks if a predicate is true for any of the elements in a range.
 *
 * @tparam t_input_iterator_type Must meet the requirements of LegacyInputIterator.
 * @tparam t_predicate Unary predicate type (must meet the requirements of Predicate).
 * @param iter_first The first element of the range to examine.
 * @param iter_last The element after last of the range to examine.
 * @param pred Unary predicate.
 * @return true
 * @return false
 */
template<class t_input_iterator_type, class t_predicate>
inline bool any_of(t_input_iterator_type iter_first, t_input_iterator_type iter_last, t_predicate pred) {
  for (; iter_first != iter_last; ++iter_first) {
    if (pred(*iter_first)) {
      return true;
    }
  }
  return false;
}
} // namespace portable_stl

#endif /* PSTL_ANY_OF_H */
