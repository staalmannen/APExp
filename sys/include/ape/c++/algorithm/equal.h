// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="equal.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_EQUAL_H
#define PSTL_EQUAL_H

#include "../concepts/is_equality_comparable.h"
#include "../functional/equal_to.h"
#include "../functional/identity.h"
#include "../iterator/distance.h"
#include "../iterator/input_iterator_tag.h"
#include "../iterator/random_access_iterator_tag.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/type_properties/is_volatile.h"
#include "../metaprogramming/type_traits/operation_traits.h"
#include "../utility/general/functional/invoke.h"
#include "comp.h"
#include "constexpr_memcmp_equal.h"
#include "copy_move_common.h"
#include "unwrap_iter.h"

namespace std {
namespace algorithm_helper {

  template<class t_input_iterator1, class t_input_iterator2, class t_binary_predicate>
  inline bool equal_iter_impl(
    t_input_iterator1 first1, t_input_iterator1 last1, t_input_iterator2 first2, t_binary_predicate &pred) {
    for (; first1 != last1; ++first1, (void)++first2) {
      if (!pred(*first1, *first2)) {
        return false;
      }
    }
    return true;
  }

  template<
    class t_type,
    class t_other_type,
    class t_binary_predicate,
    ::std::enable_if_bool_constant_t<
      ::std::conjunction<
        typename ::std::desugars_to<::std::equal_tag, t_binary_predicate, t_type, t_other_type>::type,
        ::std::negation<::std::is_volatile<t_type>>,
        ::std::negation<::std::is_volatile<t_other_type>>,
        ::std::is_trivially_equality_comparable<t_type, t_other_type>>,
      void *>
    = nullptr>
  inline bool equal_iter_impl(t_type *first1, t_type *last1, t_other_type *first2, t_binary_predicate &) {
    return ::std::constexpr_memcmp_equal(first1, first2, ::std::element_count(last1 - first1));
  }

  template<class t_binary_predicate, class t_input_iterator1, class t_input_iterator2>
  inline bool equal_impl(t_input_iterator1  first1,
                         t_input_iterator1  last1,
                         t_input_iterator2  first2,
                         t_input_iterator2  last2,
                         t_binary_predicate pred,
                         ::std::input_iterator_tag,
                         ::std::input_iterator_tag) {
    for (; first1 != last1 && first2 != last2; ++first1, (void)++first2) {
      if (!pred(*first1, *first2)) {
        return false;
      }
    }
    return first1 == last1 && first2 == last2;
  }

  template<class t_iterator1,
           class t_sentinel1,
           class t_iterator2,
           class t_sentinel2,
           class t_pred,
           class t_projection1,
           class t_projection2>
  inline bool equal_impl0(t_iterator1    first1,
                          t_sentinel1    last1,
                          t_iterator2    first2,
                          t_sentinel2    last2,
                          t_pred        &comp,
                          t_projection1 &proj1,
                          t_projection2 &proj2) {
    while (first1 != last1 && first2 != last2) {
      if (
        !::std::invoke(comp, ::std::invoke(proj1, *first1), ::std::invoke(proj2, *first2))) {
        return false;
      }
      ++first1;
      ++first2;
    }
    return first1 == last1 && first2 == last2;
  }

  template<class t_type,
           class t_other_type,
           class t_pred,
           class t_projection1,
           class t_projection2,
           ::std::enable_if_bool_constant_t<
             ::std::conjunction<
               typename ::std::desugars_to<::std::equal_tag, t_pred, t_type, t_other_type>::type,
               typename ::std::is_identity<t_projection1>::type,
               typename ::std::is_identity<t_projection2>::type,
               ::std::negation<::std::is_volatile<t_type>>,
               ::std::negation<::std::is_volatile<t_other_type>>,
               ::std::is_trivially_equality_comparable<t_type, t_other_type>>,
             void *>
           = nullptr>
  inline bool equal_impl0(
    t_type *first1, t_type *last1, t_other_type *first2, t_other_type *, t_pred &, t_projection1 &, t_projection2 &) {
    return ::std::constexpr_memcmp_equal(first1, first2, ::std::element_count(last1 - first1));
  }

  template<class t_binary_predicate, class t_random_access_iterator1, class t_random_access_iterator2>
  inline bool equal_impl(t_random_access_iterator1 first1,
                         t_random_access_iterator1 last1,
                         t_random_access_iterator2 first2,
                         t_random_access_iterator2 last2,
                         t_binary_predicate        pred,
                         ::std::random_access_iterator_tag,
                         ::std::random_access_iterator_tag) {
    if (::std::distance(first1, last1) != ::std::distance(first2, last2)) {
      return false;
    }
    ::std::identity proj; // default bypass projection
    return equal_impl0(::std::unwrap_iter(first1),
                       ::std::unwrap_iter(last1),
                       ::std::unwrap_iter(first2),
                       ::std::unwrap_iter(last2),
                       pred,
                       proj,
                       proj);
  }
} // namespace algorithm_helper

template<class t_input_iterator1, class t_input_iterator2, class t_binary_predicate>
inline bool equal(
  t_input_iterator1 first1, t_input_iterator1 last1, t_input_iterator2 first2, t_binary_predicate pred) {
  return algorithm_helper::equal_iter_impl(
    ::std::unwrap_iter(first1), ::std::unwrap_iter(last1), ::std::unwrap_iter(first2), pred);
}

template<class t_input_iterator1, class t_input_iterator2>
inline bool equal(t_input_iterator1 first1, t_input_iterator1 last1, t_input_iterator2 first2) {
  return equal(first1, last1, first2, ::std::algorithm_helper::equal_to_inter{});
}

template<class t_input_iterator1, class t_input_iterator2, class t_binary_predicate>
inline bool equal(t_input_iterator1  first1,
                  t_input_iterator1  last1,
                  t_input_iterator2  first2,
                  t_input_iterator2  last2,
                  t_binary_predicate pred) {
  return algorithm_helper::equal_impl<t_binary_predicate &>(
    first1,
    last1,
    first2,
    last2,
    pred,
    typename ::std::iterator_traits<t_input_iterator1>::iterator_category(),
    typename ::std::iterator_traits<t_input_iterator2>::iterator_category());
}

template<class t_input_iterator1, class t_input_iterator2>
inline bool equal(
  t_input_iterator1 first1, t_input_iterator1 last1, t_input_iterator2 first2, t_input_iterator2 last2) {
  return algorithm_helper::equal_impl(first1,
                                      last1,
                                      first2,
                                      last2,
                                      ::std::algorithm_helper::equal_to_inter{},
                                      typename ::std::iterator_traits<t_input_iterator1>::iterator_category(),
                                      typename ::std::iterator_traits<t_input_iterator2>::iterator_category());
}

} // namespace std

#endif // PSTL_EQUAL_H
