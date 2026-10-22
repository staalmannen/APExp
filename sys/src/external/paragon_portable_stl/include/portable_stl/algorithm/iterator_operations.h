// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="iterator_operations.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ITERATOR_OPERATIONS_H
#define PSTL_ITERATOR_OPERATIONS_H

#include "../iterator/advance.h"
#include "../iterator/distance.h"
#include "../iterator/iter_swap.h"
#include "algo_iter_swap.h"
#include "../iterator/iterator_traits.h"
#include "../iterator/next.h"
#include "../iterator/prev.h"
#include "../metaprogramming/composite_type/is_reference.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/remove_cvref.h"
#include "../metaprogramming/type_relations/is_same.h"
#include "../utility/general/declval.h"
#include "../utility/general/forward.h"
#include "../utility/general/move.h"

namespace portable_stl {

template<class t_alg_policy> class iterator_operations;

struct classic_alg_policy {};

template<> class iterator_operations<classic_alg_policy> final {
public:
  template<class t_iter> using value_type        = typename iterator_traits<t_iter>::value_type;
  template<class t_iter> using iterator_category = typename iterator_traits<t_iter>::iterator_category;
  template<class t_iter> using difference_type   = typename iterator_traits<t_iter>::difference_type;

  // advance
  template<class t_iter, class _Distance> constexpr static void advance(t_iter &iter, _Distance count) {
    ::portable_stl::advance(iter, count);
  }

  // distance
  template<class t_iter>
  constexpr static typename iterator_traits<t_iter>::difference_type distance(t_iter first, t_iter last) {
    return ::portable_stl::distance(first, last);
  }

  template<class t_iter> using t_deref_type = decltype(*::portable_stl::declval<t_iter &>());
  template<class t_iter> using t_move_type  = decltype(::portable_stl::move(*::portable_stl::declval<t_iter &>()));

  template<class t_iter> constexpr static void validate_iter_reference() {
    static_assert(
      ::portable_stl::is_same<
        t_deref_type<t_iter>,
        typename ::portable_stl::iterator_traits<::portable_stl::remove_cvref_t<t_iter>>::reference>{}(),
      "It looks like your iterator's `iterator_traits<It>::reference` does not match the return type of "
      "dereferencing the iterator, i.e., calling `*it`. This is undefined behavior according to [input.iterators] "
      "and can lead to dangling reference issues at runtime, so we are flagging this.");
  }

  // iter_move
  template<class t_iter,
           class t_deref = t_deref_type<t_iter>, // additional indirection for msvc
           ::portable_stl::enable_if_bool_constant_t<::portable_stl::is_reference<t_deref>, void *> = nullptr>
  static t_move_type<t_iter> iter_move(t_iter &&iter) {
    // If the result of dereferencing `t_iter` is a reference type, deduce the result of calling `::portable_stl::move`
    // on it. Note that the C++03 mode doesn't support `decltype(auto)` as the return type.
    validate_iter_reference<t_iter>();

    return ::portable_stl::move(*::portable_stl::forward<t_iter>(iter));
  }

  template<
    class t_iter,
    class t_deref = t_deref_type<t_iter>, // additional indirection for msvc
    ::portable_stl::enable_if_bool_constant_t<::portable_stl::negation<::portable_stl::is_reference<t_deref>>, void *>
    = nullptr>
  static t_deref_type<t_iter> iter_move(t_iter &&iter) {
    // If the result of dereferencing `t_iter` is a value type, deduce the return value of this function to also be a
    // value -- otherwise, after `operator*` returns a temporary, this function would return a dangling reference to
    // that temporary. Note that the C++03 mode doesn't support `auto` as the return type.
    validate_iter_reference<t_iter>();

    return *::portable_stl::forward<t_iter>(iter);
  }

  // iter_swap
  template<class t_iter1, class t_iter2> constexpr static void iter_swap(t_iter1 &&left, t_iter2 &&right) {
    ::portable_stl::algo_iter_swap(::portable_stl::forward<t_iter1>(left), ::portable_stl::forward<t_iter2>(right));
  }

  // next
  template<class t_iterator> constexpr static t_iterator next(t_iterator, t_iterator last) {
    return last;
  }

  template<class t_iter>
  constexpr static ::portable_stl::remove_cvref_t<t_iter> next(
    t_iter &&iter, typename iterator_traits<::portable_stl::remove_cvref_t<t_iter>>::difference_type num = 1) {
    return ::portable_stl::next(::portable_stl::forward<t_iter>(iter), num);
  }

  // prev
  template<class t_iter>
  constexpr static ::portable_stl::remove_cvref_t<t_iter> prev(
    t_iter &&iter, typename iterator_traits<::portable_stl::remove_cvref_t<t_iter>>::difference_type num = 1) {
    return ::portable_stl::prev(::portable_stl::forward<t_iter>(iter), num);
  }

  template<class t_iter> constexpr static void advance_to(t_iter &first, t_iter last) {
    first = last;
  }
};
} // namespace portable_stl

#endif // PSTL_ITERATOR_OPERATIONS_H
