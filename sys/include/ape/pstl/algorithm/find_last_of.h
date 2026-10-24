// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="find_last_of.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_FIND_LAST_OF_H
#define PSTL_FIND_LAST_OF_H

namespace portable_stl {
/**
 * @brief Searches for any one of a set of elements from the end.
 *
 * @tparam t_forward_iterator1_type Must meet the requirements of LegacyForwardIterator.
 * @tparam t_forward_iterator2_type Must meet the requirements of LegacyForwardIterator.
 * @tparam t_binary_predicate Unary predicate type (must meet the requirements of Predicate).
 * @param iter_first1 The range of elements to examine.
 * @param iter_last1 The range of elements to examine.
 * @param iter_first2 The range of elements to search for.
 * @param iter_last2 The range of elements to search for.
 * @param pred Unary predicate.
 * @return Iterator to the last element in the range [iter_first1, iter_last1) that is equal to an element from the
 * range [iter_first2, iter_last2).
 */
template<class t_forward_iterator1_type, class t_forward_iterator2_type, class t_binary_predicate>
t_forward_iterator1_type find_last_of(t_forward_iterator1_type iter_first1,
                                      t_forward_iterator1_type iter_last1,
                                      t_forward_iterator2_type iter_first2,
                                      t_forward_iterator2_type iter_last2,
                                      t_binary_predicate       pred) {
  for (; iter_first1 != iter_last1; --iter_last1) {
    for (t_forward_iterator2_type j = iter_first2; j != iter_last2; ++j) {
      if (pred(*iter_last1, *j)) {
        return iter_last1;
      }
    }
  }
  return iter_first1 - 1;
}
} // namespace portable_stl

#endif /* PSTL_FIND_LAST_OF_H */
