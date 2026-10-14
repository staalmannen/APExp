// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="advance.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ADVANCE_H
#define PSTL_ADVANCE_H

#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/type_relations/is_derived_from.h"
#include "iterator_traits.h"
#include "random_access_iterator_tag.h"

namespace portable_stl {
namespace iterator_helper {
  /**
   * @brief Increments given iterator iter by n_value elements.
   * Implementation for input iterator.
   * @tparam iterator_t Iterator type.
   * @param iter 	Iterator to be advanced.
   * @param n_value Number of elements iter should be advanced.
   */
  template<class iterator_t>
  inline void advance_impl(iterator_t                                           &iter,
                           typename iterator_traits<iterator_t>::difference_type n_value,
                           ::portable_stl::input_iterator_tag) {
    while (n_value > 0) {
      --n_value;
      ++iter;
    }
  }

  /**
   * @brief Increments given iterator iter by n_value elements.
   * Implementation for bidirectional iterator.
   * @tparam iterator_t Iterator type.
   * @param iter 	Iterator to be advanced.
   * @param n_value Number of elements iter should be advanced.
   */
  template<class iterator_t>
  inline void advance_impl(iterator_t                                           &iter,
                           typename iterator_traits<iterator_t>::difference_type n_value,
                           ::portable_stl::bidirectional_iterator_tag) {
    if (n_value >= 0) {
      while (n_value > 0) {
        --n_value;
        ++iter;
      }
    } else {
      while (n_value < 0) {
        ++n_value;
        --iter;
      }
    }
  }

  /**
   * @brief Increments given iterator iter by n_value elements.
   * Implementation for iterator with random access.
   * @tparam iterator_t Iterator type.
   * @param iter 	Iterator to be advanced.
   * @param n_value Number of elements iter should be advanced.
   */
  template<class iterator_t>
  inline void advance_impl(iterator_t                                           &iter,
                           typename iterator_traits<iterator_t>::difference_type n_value,
                           ::portable_stl::random_access_iterator_tag) {
    iter += n_value;
  }
} // namespace iterator_helper

/**
 * @brief Increments given iterator iter by n_value elements.
 *
 * @tparam iterator_t Iterator type.
 * @param iter 	Iterator to be advanced.
 * @param n_value Number of elements iter should be advanced.
 */
template<class iterator_t>
inline void advance(iterator_t &iter, typename iterator_traits<iterator_t>::difference_type n_value) {
  iterator_helper::advance_impl(
    iter, n_value, typename ::portable_stl::iterator_traits<iterator_t>::iterator_category());
}
} // namespace portable_stl

#endif /* PSTL_ADVANCE_H */
