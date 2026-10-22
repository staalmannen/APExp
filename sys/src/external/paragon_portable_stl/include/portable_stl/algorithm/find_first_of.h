// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="find_first_of.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_FIND_FIRST_OF_H
#define PSTL_FIND_FIRST_OF_H

#include "comp.h"

namespace portable_stl {
namespace algorithm_helper {
  /**
   * @brief find_first_of implementation.
   *
   * @tparam t_forward_iterator1_type
   * @tparam t_forward_iterator2_type
   * @tparam t_binary_predicate
   * @param iter_first1
   * @param iter_last1
   * @param iter_first2
   * @param iter_last2
   * @param pred
   * @return t_forward_iterator1_type
   */
  template<class t_forward_iterator1_type, class t_forward_iterator2_type, class t_binary_predicate>
  t_forward_iterator1_type find_first_of_impl(t_forward_iterator1_type iter_first1,
                                              t_forward_iterator1_type iter_last1,
                                              t_forward_iterator2_type iter_first2,
                                              t_forward_iterator2_type iter_last2,
                                              t_binary_predicate       pred) {
    for (; iter_first1 != iter_last1; ++iter_first1) {
      for (t_forward_iterator2_type j = iter_first2; j != iter_last2; ++j) {
        if (pred(*iter_first1, *j)) {
          return iter_first1;
        }
      }
    }
    return iter_last1;
  }
} // namespace algorithm_helper

/**
 * @brief Searches for any one of a set of elements.
 *
 * @tparam t_forward_iterator1_type Must meet the requirements of LegacyForwardIterator.
 * @tparam t_forward_iterator2_type Must meet the requirements of LegacyForwardIterator.
 * @tparam t_binary_predicate Binary predicate type (must meet the requirements of Predicate).
 * @param iter_first1 The range of elements to examine.
 * @param iter_last1 The range of elements to examine.
 * @param iter_first2 The range of elements to search for.
 * @param iter_last2 The range of elements to search for.
 * @param pred Binary predicate.
 * @return Iterator to the first element in the range [iter_first1, iter_last1) that is equal to an element from the
 * range [iter_first2, iter_last2).
 */
template<class t_forward_iterator1_type, class t_forward_iterator2_type, class t_binary_predicate>
inline t_forward_iterator1_type find_first_of(t_forward_iterator1_type iter_first1,
                                              t_forward_iterator1_type iter_last1,
                                              t_forward_iterator2_type iter_first2,
                                              t_forward_iterator2_type iter_last2,
                                              t_binary_predicate       pred) {
  return algorithm_helper::find_first_of_impl(iter_first1, iter_last1, iter_first2, iter_last2, pred);
}

/**
 * @brief Searches the range [iter_first1, iter_last1) for any of the elements in the range [iter_first2, iter_last2).
 *
 * @tparam t_forward_iterator1_type Must meet the requirements of LegacyForwardIterator.
 * @tparam t_forward_iterator2_type Must meet the requirements of LegacyForwardIterator.
 * @param iter_first1 The range of elements to examine.
 * @param iter_last1 The range of elements to examine.
 * @param iter_first2 The range of elements to search for.
 * @param iter_last2 The range of elements to search for.
 * @return Iterator to the first element in the range [iter_first1, iter_last1) that is equal to an element from the
 * range [iter_first2, iter_last2).
 */
template<class t_forward_iterator1_type, class t_forward_iterator2_type>
inline t_forward_iterator1_type find_first_of(t_forward_iterator1_type iter_first1,
                                              t_forward_iterator1_type iter_last1,
                                              t_forward_iterator2_type iter_first2,
                                              t_forward_iterator2_type iter_last2) {
  return algorithm_helper::find_first_of_impl(
    iter_first1, iter_last1, iter_first2, iter_last2, ::portable_stl::algorithm_helper::equal_to_inter{});
}
} // namespace portable_stl

#endif /* PSTL_FIND_FIRST_OF_H */
