// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="move_algo.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MOVE_ALGO_H
#define PSTL_MOVE_ALGO_H

#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/type_properties/is_copy_constructible.h"
#include "../utility/tuple/tuple.h"
#include "../utility/tuple/tuple_get.h"
#include "copy_move_common.h"
#include "iterator_operations.h"

namespace portable_stl {

// /**
//  * @brief Forward declaration
//  *
//  * @tparam t_alg_policy
//  * @tparam t_input_iterator
//  * @tparam t_sentinel
//  * @tparam t_output_iterator
//  * @param first
//  * @param last
//  * @param result
//  * @return ::portable_stl::tuple<t_input_iterator, t_output_iterator>
//  */
// template<class t_alg_policy, class t_input_iterator, class t_sentinel, class t_output_iterator>
// inline ::portable_stl::tuple<t_input_iterator, t_output_iterator> move_impl(
//   t_input_iterator first, t_sentinel last, t_output_iterator result);

template<class t_alg_policy> class move_loop {
public:
  template<class t_input_iter, class t_sentinel, class t_output_iter>
  tuple<t_input_iter, t_output_iter> operator()(t_input_iter first, t_sentinel last, t_output_iter result) const {
    while (first != last) {
      *result = ::portable_stl::iterator_operations<t_alg_policy>::template iter_move(first);
      ++first;
      ++result;
    }
    return ::portable_stl::make_tuple(::portable_stl::move(first), ::portable_stl::move(result));
  }

  // == RELATED TO SEGMENTED ITERATORS

  // template<class t_input_iter, class t_output_iter> struct _MoveSegment {
  //   using _Traits = __segmented_iterator_traits<t_input_iter>;

  //   t_output_iter &result_;

  //   constexpr explicit _MoveSegment(t_output_iter &result) : result_(result) {
  //   }

  //   constexpr void operator()(typename _Traits::__local_iterator __lfirst, typename _Traits::__local_iterator __llast) {
  //     result_ = std::__move<t_alg_policy>(__lfirst, __llast, ::portable_stl::move(result_)).second;
  //   }
  // };

  // template<class t_input_iter,
  //          class t_output_iter,
  //          __enable_if_t<__is_segmented_iterator<t_input_iter>::value, int> = 0>
  // constexpr tuple<t_input_iter, t_output_iter> operator()(
  //   t_input_iter first, t_input_iter last, t_output_iter result) const {
  //   std::__for_each_segment(first, last, _MoveSegment<t_input_iter, t_output_iter>(result));
  //   return std::make_tuple(last, ::portable_stl::move(result));
  // }

  // template<
  //   class t_input_iter,
  //   class t_output_iter,
  //   __enable_if_t<__has_random_access_iterator_category<t_input_iter>::value
  //                   && !__is_segmented_iterator<t_input_iter>::value && __is_segmented_iterator<t_output_iter>::value,
  //                 int>
  //   = 0>
  // constexpr tuple<t_input_iter, t_output_iter> operator()(
  //   t_input_iter first, t_input_iter last, t_output_iter result) const {
  //   using _Traits = __segmented_iterator_traits<t_output_iter>;
  //   using _DiffT  = typename common_type<__iter_diff_t<t_input_iter>, __iter_diff_t<t_output_iter>>::type;

  //   if (first == last) {
  //     return std::make_tuple(::portable_stl::move(first), ::portable_stl::move(result));
  //   }

  //   auto __local_first      = _Traits::__local(result);
  //   auto __segment_iterator = _Traits::__segment(result);
  //   while (true) {
  //     auto __local_last = _Traits::__end(__segment_iterator);
  //     auto __size       = ::portable_stl::min<_DiffT>(__local_last - __local_first, last - first);
  //     auto __iters      = std::__move<t_alg_policy>(first, first + __size, __local_first);
  //     first           = ::portable_stl::move(__iters.first);

  //     if (first == last) {
  //       return std::make_tuple(::portable_stl::move(first),
  //                              _Traits::__compose(__segment_iterator, ::portable_stl::move(__iters.second)));
  //     }

  //     __local_first = _Traits::__begin(++__segment_iterator);
  //   }
  // }
};

class move_trivial {
  public:
  // At this point, the iterators have been unwrapped so any `contiguous_iterator` has been unwrapped to a pointer.
  template<class t_input_type,
           class t_output_type,
           ::portable_stl::enable_if_bool_constant_t<
             typename ::portable_stl::can_lower_move_assignment_to_memmove<t_input_type, t_output_type>::type,
             void *>
           = nullptr>
  ::portable_stl::tuple<t_input_type *, t_output_type *> operator()(
    t_input_type *first, t_input_type *last, t_output_type *result) const {
    return ::portable_stl::copy_trivial_impl(first, last, result);
  }
};

template<class t_alg_policy, class t_input_iterator, class t_sentinel, class t_output_iterator>
inline ::portable_stl::tuple<t_input_iterator, t_output_iterator> move_impl(
  t_input_iterator first, t_sentinel last, t_output_iterator result) {
  return ::portable_stl::dispatch_copy_or_move<t_alg_policy, move_loop<t_alg_policy>, move_trivial>(
    ::portable_stl::move(first), ::portable_stl::move(last), ::portable_stl::move(result));
}

template<class t_input_iterator, class t_output_iterator>
inline t_output_iterator move(t_input_iterator first, t_input_iterator last, t_output_iterator result) {
  static_assert(::portable_stl::is_copy_constructible<t_input_iterator>{}(), "Iterators has to be copy constructible.");
  static_assert(::portable_stl::is_copy_constructible<t_output_iterator>{}(),
                "The output iterator has to be copy constructible.");

  return ::portable_stl::get<1>(move_impl<::portable_stl::classic_alg_policy>(
    ::portable_stl::move(first), ::portable_stl::move(last), ::portable_stl::move(result)));
}
} // namespace portable_stl

#endif // PSTL_MOVE_ALGO_H
