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

namespace portable_stl {
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
    ::portable_stl::enable_if_bool_constant_t<
      ::portable_stl::conjunction<
        typename ::portable_stl::desugars_to<::portable_stl::equal_tag, t_binary_predicate, t_type, t_other_type>::type,
        ::portable_stl::negation<::portable_stl::is_volatile<t_type>>,
        ::portable_stl::negation<::portable_stl::is_volatile<t_other_type>>,
        ::portable_stl::is_trivially_equality_comparable<t_type, t_other_type>>,
      void *>
    = nullptr>
  inline bool equal_iter_impl(t_type *first1, t_type *last1, t_other_type *first2, t_binary_predicate &) {
    return ::portable_stl::constexpr_memcmp_equal(first1, first2, ::portable_stl::element_count(last1 - first1));
  }

  template<class t_binary_predicate, class t_input_iterator1, class t_input_iterator2>
  inline bool equal_impl(t_input_iterator1  first1,
                         t_input_iterator1  last1,
                         t_input_iterator2  first2,
                         t_input_iterator2  last2,
                         t_binary_predicate pred,
                         ::portable_stl::input_iterator_tag,
                         ::portable_stl::input_iterator_tag) {
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
        !::portable_stl::invoke(comp, ::portable_stl::invoke(proj1, *first1), ::portable_stl::invoke(proj2, *first2))) {
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
           ::portable_stl::enable_if_bool_constant_t<
             ::portable_stl::conjunction<
               typename ::portable_stl::desugars_to<::portable_stl::equal_tag, t_pred, t_type, t_other_type>::type,
               typename ::portable_stl::is_identity<t_projection1>::type,
               typename ::portable_stl::is_identity<t_projection2>::type,
               ::portable_stl::negation<::portable_stl::is_volatile<t_type>>,
               ::portable_stl::negation<::portable_stl::is_volatile<t_other_type>>,
               ::portable_stl::is_trivially_equality_comparable<t_type, t_other_type>>,
             void *>
           = nullptr>
  inline bool equal_impl0(
    t_type *first1, t_type *last1, t_other_type *first2, t_other_type *, t_pred &, t_projection1 &, t_projection2 &) {
    return ::portable_stl::constexpr_memcmp_equal(first1, first2, ::portable_stl::element_count(last1 - first1));
  }

  template<class t_binary_predicate, class t_random_access_iterator1, class t_random_access_iterator2>
  inline bool equal_impl(t_random_access_iterator1 first1,
                         t_random_access_iterator1 last1,
                         t_random_access_iterator2 first2,
                         t_random_access_iterator2 last2,
                         t_binary_predicate        pred,
                         ::portable_stl::random_access_iterator_tag,
                         ::portable_stl::random_access_iterator_tag) {
    if (::portable_stl::distance(first1, last1) != ::portable_stl::distance(first2, last2)) {
      return false;
    }
    ::portable_stl::identity proj; // default bypass projection
    return equal_impl0(::portable_stl::unwrap_iter(first1),
                       ::portable_stl::unwrap_iter(last1),
                       ::portable_stl::unwrap_iter(first2),
                       ::portable_stl::unwrap_iter(last2),
                       pred,
                       proj,
                       proj);
  }
} // namespace algorithm_helper

template<class t_input_iterator1, class t_input_iterator2, class t_binary_predicate>
inline bool equal(
  t_input_iterator1 first1, t_input_iterator1 last1, t_input_iterator2 first2, t_binary_predicate pred) {
  return algorithm_helper::equal_iter_impl(
    ::portable_stl::unwrap_iter(first1), ::portable_stl::unwrap_iter(last1), ::portable_stl::unwrap_iter(first2), pred);
}

template<class t_input_iterator1, class t_input_iterator2>
inline bool equal(t_input_iterator1 first1, t_input_iterator1 last1, t_input_iterator2 first2) {
  return equal(first1, last1, first2, ::portable_stl::algorithm_helper::equal_to_inter{});
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
    typename ::portable_stl::iterator_traits<t_input_iterator1>::iterator_category(),
    typename ::portable_stl::iterator_traits<t_input_iterator2>::iterator_category());
}

template<class t_input_iterator1, class t_input_iterator2>
inline bool equal(
  t_input_iterator1 first1, t_input_iterator1 last1, t_input_iterator2 first2, t_input_iterator2 last2) {
  return algorithm_helper::equal_impl(first1,
                                      last1,
                                      first2,
                                      last2,
                                      ::portable_stl::algorithm_helper::equal_to_inter{},
                                      typename ::portable_stl::iterator_traits<t_input_iterator1>::iterator_category(),
                                      typename ::portable_stl::iterator_traits<t_input_iterator2>::iterator_category());
}

} // namespace portable_stl

#endif // PSTL_EQUAL_H
