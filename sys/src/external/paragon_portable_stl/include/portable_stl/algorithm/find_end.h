// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="find_end.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_FIND_END_H
#define PSTL_FIND_END_H

#include "comp.h"
#include "../iterator/bidirectional_iterator_tag.h"
#include "../iterator/forward_iterator_tag.h"
#include "../iterator/iterator_traits.h"
#include "../iterator/random_access_iterator_tag.h"
#include "../metaprogramming/reference_modifications/add_lvalue_reference.h"

namespace portable_stl {
namespace algorithm_helper {
  /**
   * @brief find_end implementation for forward iterators.
   *
   * @tparam t_binary_predicate
   * @tparam t_forward_iterator1_type
   * @tparam t_forward_iterator2_type
   * @param iter_first1
   * @param iter_last1
   * @param iter_first2
   * @param iter_last2
   * @param pred
   * @return t_forward_iterator1_type
   */
  template<class t_binary_predicate, class t_forward_iterator1_type, class t_forward_iterator2_type>
  t_forward_iterator1_type find_end_impl(t_forward_iterator1_type iter_first1,
                                         t_forward_iterator1_type iter_last1,
                                         t_forward_iterator2_type iter_first2,
                                         t_forward_iterator2_type iter_last2,
                                         t_binary_predicate       pred,
                                         ::portable_stl::forward_iterator_tag,
                                         ::portable_stl::forward_iterator_tag) {
    // modeled after search algorithm
    t_forward_iterator1_type ret{iter_last1}; // iter_last1 is the "default" answer
    if (iter_first2 == iter_last2) {
      return ret;
    }
    while (true) {
      while (true) {
        if (iter_first1 == iter_last1) { // if source exhausted return last correct answer
          return ret;
        } //    (or iter_last1 if never found)
        if (pred(*iter_first1, *iter_first2)) {
          break;
        }
        ++iter_first1;
      }
      // *iter_first1 matches *iter_first2, now match elements after here
      t_forward_iterator1_type m1{iter_first1};
      t_forward_iterator2_type m2{iter_first2};
      while (true) {
        if (++m2 == iter_last2) { // Pattern exhaused, record answer and search for another one
          ret = iter_first1;
          ++iter_first1;
          break;
        }
        if (++m1 == iter_last1) { // Source exhausted, return last answer
          return ret;
        }
        if (!pred(*m1, *m2)) // mismatch, restart with a new __first
        {
          ++iter_first1;
          break;
        } // else there is a match, check next elements
      }
    }
  }

  /**
   * @brief find_end implementation for bidirectiona iterators.
   *
   * @tparam t_binary_predicate
   * @tparam t_bidirectiona_iterator1_type
   * @tparam t_bidirectiona_iterator2_type
   * @param iter_first1
   * @param iter_last1
   * @param iter_first2
   * @param iter_last2
   * @param pred
   * @return t_bidirectiona_iterator1_type
   */
  template<class t_binary_predicate, class t_bidirectiona_iterator1_type, class t_bidirectiona_iterator2_type>
  t_bidirectiona_iterator1_type find_end_impl(t_bidirectiona_iterator1_type iter_first1,
                                              t_bidirectiona_iterator1_type iter_last1,
                                              t_bidirectiona_iterator2_type iter_first2,
                                              t_bidirectiona_iterator2_type iter_last2,
                                              t_binary_predicate            pred,
                                              ::portable_stl::bidirectional_iterator_tag,
                                              ::portable_stl::bidirectional_iterator_tag) {
    // modeled after search algorithm (in reverse)
    if (iter_first2 == iter_last2) {
      return iter_last1;
    } // Everything matches an empty sequence
    t_bidirectiona_iterator1_type l1{iter_last1};
    t_bidirectiona_iterator2_type l2{iter_last2};
    --l2;
    while (true) {
      // Find last element in sequence 1 that matchs *(iter_last2-1), with a mininum of loop checks
      while (true) {
        if (iter_first1 == l1) { // return iter_last1 if no element matches *iter_first2
          return iter_last1;
        }
        if (pred(*--l1, *l2)) {
          break;
        }
      }
      // *l1 matches *l2, now match elements before here
      t_bidirectiona_iterator1_type m1{l1};
      t_bidirectiona_iterator2_type m2{l2};
      while (true) {
        if (m2 == iter_first2) { // If pattern exhausted, m1 is the answer (works for 1 element pattern)
          return m1;
        }
        if (m1 == iter_first1) { // Otherwise if source exhaused, pattern not found
          return iter_last1;
        }
        if (!pred(*--m1, *--m2)) // if there is a mismatch, restart with a new l1
        {
          break;
        } // else there is a match, check next elements
      }
    }
  }

  /**
   * @brief find_end implementation for random access iterators.
   *
   * @tparam t_binary_predicate
   * @tparam t_random_access_iterator1_type
   * @tparam t_random_access_iterator2_type
   * @param iter_first1
   * @param iter_last1
   * @param iter_first2
   * @param iter_last2
   * @param pred
   * @return t_random_access_iterator1_type
   */
  template<class t_binary_predicate, class t_random_access_iterator1_type, class t_random_access_iterator2_type>
  t_random_access_iterator1_type find_end_impl(t_random_access_iterator1_type iter_first1,
                                               t_random_access_iterator1_type iter_last1,
                                               t_random_access_iterator2_type iter_first2,
                                               t_random_access_iterator2_type iter_last2,
                                               t_binary_predicate             pred,
                                               ::portable_stl::random_access_iterator_tag,
                                               ::portable_stl::random_access_iterator_tag) {
    // Take advantage of knowing source and pattern lengths.  Stop short when source is smaller than pattern
    typename iterator_traits<t_random_access_iterator2_type>::difference_type len2{iter_last2 - iter_first2};
    if (len2 == 0) {
      return iter_last1;
    }
    typename iterator_traits<t_random_access_iterator1_type>::difference_type len1{iter_last1 - iter_first1};
    if (len1 < len2) {
      return iter_last1;
    }
    t_random_access_iterator1_type const s{iter_first1 + (len2 - 1)}; // End of pattern match can't go before here
    t_random_access_iterator1_type       l1{iter_last1};
    t_random_access_iterator2_type       l2{iter_last2};
    --l2;
    while (true) {
      while (true) {
        if (s == l1) {
          return iter_last1;
        }
        if (pred(*--l1, *l2)) {
          break;
        }
      }
      t_random_access_iterator1_type m1{l1};
      t_random_access_iterator2_type m2{l2};
      while (true) {
        if (m2 == iter_first2) {
          return m1;
        }
        // no need to check range on m1 because s guarantees we have enough source
        if (!pred(*--m1, *--m2)) {
          break;
        }
      }
    }
  }
} // namespace algorithm_helper

/**
 * @brief Finds the last sequence of elements in a certain range.
 *
 * @tparam t_forward_iterator1_type Must meet the requirements of LegacyForwardIterator.
 * @tparam t_forward_iterator2_type Must meet the requirements of LegacyForwardIterator.
 * @tparam t_binary_predicate Unary predicate type (must meet the requirements of Predicate).
 * @param iter_first1 The range of elements to examine.
 * @param iter_last1 The range of elements to examine.
 * @param iter_first2 The range of elements to search for.
 * @param iter_last2 The range of elements to search for.
 * @param pred Unary predicate.
 * @return Iterator to the beginning of last occurrence of the sequence [iter_first2, iter_last2) in range [iter_first1,
 * iter_last1).
 */
template<class t_forward_iterator1_type, class t_forward_iterator2_type, class t_binary_predicate>
inline t_forward_iterator1_type find_end(t_forward_iterator1_type iter_first1,
                                         t_forward_iterator1_type iter_last1,
                                         t_forward_iterator2_type iter_first2,
                                         t_forward_iterator2_type iter_last2,
                                         t_binary_predicate       pred) {
  return algorithm_helper::find_end_impl<::portable_stl::add_lvalue_reference_t<t_binary_predicate>>(
    iter_first1,
    iter_last1,
    iter_first2,
    iter_last2,
    pred,
    typename ::portable_stl::iterator_traits<t_forward_iterator1_type>::iterator_category(),
    typename ::portable_stl::iterator_traits<t_forward_iterator2_type>::iterator_category());
}

/**
 * @brief Finds the last sequence of elements in a certain range.
 *
 * @tparam t_forward_iterator1_type Must meet the requirements of LegacyForwardIterator.
 * @tparam t_forward_iterator2_type Must meet the requirements of LegacyForwardIterator.
 * @param iter_first1 The range of elements to examine.
 * @param iter_last1 The range of elements to examine.
 * @param iter_first2 The range of elements to search for.
 * @param iter_last2 The range of elements to search for.
 * @return Iterator to the beginning of last occurrence of the sequence [iter_first2, iter_last2) in range [iter_first1,
 * iter_last1).
 */
template<class t_forward_iterator1_type, class t_forward_iterator2_type>
inline t_forward_iterator1_type find_end(t_forward_iterator1_type iter_first1,
                                         t_forward_iterator1_type iter_last1,
                                         t_forward_iterator2_type iter_first2,
                                         t_forward_iterator2_type iter_last2) {
  return find_end(
    iter_first1, iter_last1, iter_first2, iter_last2, ::portable_stl::algorithm_helper::equal_to_inter{});
}
} // namespace portable_stl

#endif /* PSTL_FIND_END_H */
