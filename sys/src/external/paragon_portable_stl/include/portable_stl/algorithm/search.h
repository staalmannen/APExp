// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="search.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_SEARCH_H
#define PSTL_SEARCH_H

#include "comp.h"
#include "../iterator/forward_iterator_tag.h"
#include "../iterator/iterator_traits.h"
#include "../iterator/random_access_iterator_tag.h"
#include "../utility/tuple/tuple.h"
#include "../utility/tuple/tuple_get.h"
#include "../utility/tuple/tuple_make.h"

namespace portable_stl {
namespace algorithm_helper {
  /**
   * @brief Search implementation for forward iterators.
   *
   * @tparam t_binary_predicate Unary predicate type (must meet the requirements of Predicate).
   * @tparam t_forward_iterator1_type
   * @tparam t_forward_iterator2_type
   * @param iter_first1 The range of elements to examine.
   * @param iter_last1 The range of elements to examine.
   * @param iter_first2 The range of elements to search for.
   * @param iter_last2 The range of elements to search for.
   * @param pred Must meet the requirements of BinaryPredicate.
   * @return ::portable_stl::tuple<t_forward_iterator1_type, t_forward_iterator1_type>
   */
  template<class t_binary_predicate, class t_forward_iterator1_type, class t_forward_iterator2_type>
  ::portable_stl::tuple<t_forward_iterator1_type, t_forward_iterator1_type> search_impl(
    t_forward_iterator1_type iter_first1,
    t_forward_iterator1_type iter_last1,
    t_forward_iterator2_type iter_first2,
    t_forward_iterator2_type iter_last2,
    t_binary_predicate       pred,
    ::portable_stl::forward_iterator_tag,
    ::portable_stl::forward_iterator_tag) {
    if (iter_first2 == iter_last2) {
      return ::portable_stl::make_tuple(iter_first1, iter_first1);
    } // Everything matches an empty sequence

    while (true) {
      // Find first element in sequence 1 that matchs *iter_first2, with a mininum of loop checks
      while (true) {
        if (iter_first1 == iter_last1) { // return iter_last1 if no element matches *iter_first2
          return ::portable_stl::make_tuple(iter_last1, iter_last1);
        }
        if (pred(*iter_first1, *iter_first2)) {
          break;
        }
        ++iter_first1;
      }

      // *iter_first1 matches *iter_first2, now match elements after here
      t_forward_iterator1_type m1{iter_first1};
      t_forward_iterator2_type m2{iter_first2};
      while (true) {
        if (++m2 == iter_last2) { // If pattern exhausted, iter_first1 is the answer (works for 1 element pattern)
          return ::portable_stl::make_tuple(iter_first1, m1);
        }
        if (++m1 == iter_last1) { // Otherwise if source exhaused, pattern not found
          return ::portable_stl::make_tuple(iter_last1, iter_last1);
        }
        if (!pred(*m1, *m2)) // if there is a mismatch, restart with a new iter_first1
        {
          ++iter_first1;
          break;
        } // else there is a match, check next elements
      }
    }
  }

  /**
   * @brief Search implementation for random access iterators.
   *
   * @tparam t_binary_predicate Unary predicate type (must meet the requirements of Predicate).
   * @tparam t_random_access_iterator1_type
   * @tparam t_random_access_iterator2_type
   * @param iter_first1 The range of elements to examine.
   * @param iter_last1 The range of elements to examine.
   * @param iter_first2 The range of elements to search for.
   * @param iter_last2 The range of elements to search for.
   * @param pred Must meet the requirements of BinaryPredicate.
   * @return ::portable_stl::tuple<t_random_access_iterator1_type, t_random_access_iterator1_type>
   */
  template<class t_binary_predicate, class t_random_access_iterator1_type, class t_random_access_iterator2_type>
  ::portable_stl::tuple<t_random_access_iterator1_type, t_random_access_iterator1_type> search_impl(
    t_random_access_iterator1_type iter_first1,
    t_random_access_iterator1_type iter_last1,
    t_random_access_iterator2_type iter_first2,
    t_random_access_iterator2_type iter_last2,
    t_binary_predicate             pred,
    random_access_iterator_tag,
    random_access_iterator_tag) {
    /**
     * @brief Difference type.
     */
    using t_diff1_type = typename ::portable_stl::iterator_traits<t_random_access_iterator1_type>::difference_type;
    /**
     * @brief Difference type.
     */
    using t_diff2_type = typename ::portable_stl::iterator_traits<t_random_access_iterator2_type>::difference_type;

    // Take advantage of knowing source and pattern lengths.  Stop short when source is smaller than pattern
    t_diff2_type const len2{iter_last2 - iter_first2};
    if (len2 == 0) {
      return ::portable_stl::make_tuple(iter_first1, iter_first1);
    }

    t_diff1_type const len1{iter_last1 - iter_first1};
    if (len1 < len2) {
      return ::portable_stl::make_tuple(iter_last1, iter_last1);
    }
    t_random_access_iterator1_type const start_pos{iter_last1
                                                   - (len2 - 1)}; // Start of pattern match can't go beyond here

    while (true) {
      while (true) {
        if (iter_first1 == start_pos) {
          return ::portable_stl::make_tuple(iter_last1, iter_last1);
        }
        if (pred(*iter_first1, *iter_first2)) {
          break;
        }
        ++iter_first1;
      }

      t_random_access_iterator1_type m1{iter_first1};
      t_random_access_iterator2_type m2{iter_first2};
      while (true) {
        if (++m2 == iter_last2) {
          return ::portable_stl::make_tuple(iter_first1, iter_first1 + len2);
        }
        ++m1; // no need to check range on m1 because start_pos guarantees we have enough source
        if (!pred(*m1, *m2)) {
          ++iter_first1;
          break;
        }
      }
    }
  }

} // namespace algorithm_helper

/**
 * @brief Searches for a range of elements.
 *
 * @tparam t_forward_iterator1_type Must meet the requirements of LegacyForwardIterator.
 * @tparam t_forward_iterator2_type Must meet the requirements of LegacyForwardIterator.
 * @tparam t_binary_predicate Unary predicate type (must meet the requirements of Predicate).
 * @param iter_first1 The range of elements to examine.
 * @param iter_last1 The range of elements to examine.
 * @param iter_first2 The range of elements to search for.
 * @param iter_last2 The range of elements to search for.
 * @param pred Must meet the requirements of BinaryPredicate.
 * @return Iterator to the beginning of first occurrence of the sequence [iter_first2, iter_last2) in the range
 * [iter_first1, iter_last1). If no such occurrence is found, last is returned.
 */
template<class t_forward_iterator1_type, class t_forward_iterator2_type, class t_binary_predicate>
inline t_forward_iterator1_type search(t_forward_iterator1_type iter_first1,
                                       t_forward_iterator1_type iter_last1,
                                       t_forward_iterator2_type iter_first2,
                                       t_forward_iterator2_type iter_last2,
                                       t_binary_predicate       pred) {
  return ::portable_stl::get<0>(algorithm_helper::search_impl<typename add_lvalue_reference<t_binary_predicate>::type>(
    iter_first1,
    iter_last1,
    iter_first2,
    iter_last2,
    pred,
    typename iterator_traits<t_forward_iterator1_type>::iterator_category(),
    typename iterator_traits<t_forward_iterator2_type>::iterator_category()));
}

/**
 * @brief Searches for a range of elements.
 *
 * @tparam t_forward_iterator1_type Must meet the requirements of LegacyForwardIterator.
 * @tparam t_forward_iterator2_type Must meet the requirements of LegacyForwardIterator.
 * @param iter_first1 The range of elements to examine.
 * @param iter_last1 The range of elements to examine.
 * @param iter_first2 The range of elements to search for.
 * @param iter_last2 The range of elements to search for.
 * @return Iterator to the beginning of first occurrence of the sequence [iter_first2, iter_last2) in the range
 * [iter_first1, iter_last1). If no such occurrence is found, last is returned.
 */
template<class t_forward_iterator1_type, class t_forward_iterator2_type>
inline t_forward_iterator1_type search(t_forward_iterator1_type iter_first1,
                                       t_forward_iterator1_type iter_last1,
                                       t_forward_iterator2_type iter_first2,
                                       t_forward_iterator2_type iter_last2) {
  return search(
    iter_first1, iter_last1, iter_first2, iter_last2, ::portable_stl::algorithm_helper::equal_to_inter{});
}
} // namespace portable_stl

#endif /* PSTL_SEARCH_H */
