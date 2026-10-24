// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="move_backward.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MOVE_BACKWARD_H
#define PSTL_MOVE_BACKWARD_H

#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/type_properties/is_copy_constructible.h"
#include "../utility/tuple/tuple.h"
#include "../utility/tuple/tuple_get.h"
#include "copy_move_common.h"
#include "iterator_operations.h"

namespace portable_stl {

namespace algorithm_helper {
  template<class t_alg_policy, class t_bidirectional_iterator1, class t_sentinel, class t_bidirectional_iterator2>
  ::portable_stl::tuple<t_bidirectional_iterator1, t_bidirectional_iterator2> move_backward_impl(
    t_bidirectional_iterator1 first, t_sentinel last, t_bidirectional_iterator2 result);

  template<class t_alg_policy> class move_backward_loop {
  public:
    template<class t_input_itereator, class t_sentinel, class t_output_itereator>
    ::portable_stl::tuple<t_input_itereator, t_output_itereator> operator()(
      t_input_itereator first, t_sentinel last, t_output_itereator result) const {
      auto last_iter          = ::portable_stl::iterator_operations<t_alg_policy>::next(first, last);
      auto original_last_iter = last_iter;

      while (first != last_iter) {
        *--result = ::portable_stl::iterator_operations<t_alg_policy>::iter_move(--last_iter);
      }

      return ::portable_stl::make_tuple(::portable_stl::move(original_last_iter), ::portable_stl::move(result));
    }

    // == RELATED TO SEGMENTED ITERATORS

    //   template<class t_input_itereator, class t_output_itereator,
    //   __enable_if_t<__is_segmented_iterator<t_input_itereator>::value, int> = 0>
    //   ::portable_stl::tuple<t_input_itereator, t_output_itereator> operator()(t_input_itereator first,
    //   t_input_itereator last, t_output_itereator result) const
    //   {
    //     using t_traits = __segmented_iterator_traits<t_input_itereator>;
    //     auto __sfirst = t_traits::__segment(first);
    //     auto __slast  = t_traits::__segment(last);
    //     if (__sfirst == __slast) {
    //       auto __iters
    //         = std::__move_backward<t_alg_policy>(t_traits::__local(first), t_traits::__local(last),
    //         ::portable_stl::move(result));
    //       return ::portable_stl::make_tuple(last, __iters.second);
    //     }

    //     result
    //       = std::__move_backward<t_alg_policy>(t_traits::__begin(__slast), t_traits::__local(last),
    //       ::portable_stl::move(result))
    //           .second;
    //     --__slast;
    //     while (__sfirst != __slast) {
    //       result
    //         = std::__move_backward<t_alg_policy>(t_traits::__begin(__slast), t_traits::__end(__slast),
    //         ::portable_stl::move(result))
    //             .second;
    //       --__slast;
    //     }
    //     result
    //       = std::__move_backward<t_alg_policy>(t_traits::__local(first), t_traits::__end(__slast),
    //       ::portable_stl::move(result))
    //           .second;
    //     return ::portable_stl::make_tuple(last, ::portable_stl::move(result));
    //   }

    //   template<class t_input_itereator,
    //            class t_output_itereator,
    //            __enable_if_t<__has_random_access_iterator_category<t_input_itereator>::value
    //                            && !__is_segmented_iterator<t_input_itereator>::value &&
    //                            __is_segmented_iterator<t_output_itereator>::value,
    //                          int>
    //            = 0>
    //   ::portable_stl::tuple<t_input_itereator, t_output_itereator> operator()(t_input_itereator first,
    //   t_input_itereator last, t_output_itereator result) const {
    //     using t_traits = __segmented_iterator_traits<t_output_itereator>;
    //     using _DiffT  = typename common_type<__iter_diff_t<t_input_itereator>,
    //     __iter_diff_t<t_output_itereator>>::type;

    //     // When the range contains no elements, result might not be a valid iterator
    //     if (first == last) {
    //       return ::portable_stl::make_tuple(first, result);
    //     }

    //     auto __orig_last = last;

    //     auto __local_last       = t_traits::__local(result);
    //     auto __segment_iterator = t_traits::__segment(result);
    //     while (true) {
    //       auto __local_first = t_traits::__begin(__segment_iterator);
    //       auto __size        = std::min<_DiffT>(__local_last - __local_first, last - first);
    //       auto __iter        = std::__move_backward<t_alg_policy>(last - __size, last, __local_last).second;
    //       last -= __size;

    //       if (first == last) {
    //         return ::portable_stl::make_tuple(::portable_stl::move(__orig_last),
    //         t_traits::__compose(__segment_iterator, ::portable_stl::move(__iter)));
    //       }

    //       __local_last = t_traits::__end(--__segment_iterator);
    //     }
    //   }
  };

  class move_backward_trivial {
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
      return ::portable_stl::copy_backward_trivial_impl(first, last, result);
    }
  };

  template<class t_alg_policy, class t_bidirectional_iterator1, class t_sentinel, class t_bidirectional_iterator2>
  ::portable_stl::tuple<t_bidirectional_iterator1, t_bidirectional_iterator2> move_backward_impl(
    t_bidirectional_iterator1 first, t_sentinel last, t_bidirectional_iterator2 result) {
    static_assert(::portable_stl::is_copy_constructible<t_bidirectional_iterator1>{}()
                    && ::portable_stl::is_copy_constructible<t_bidirectional_iterator1>{}(),
                  "Iterators must be copy constructible.");

    return ::portable_stl::dispatch_copy_or_move<t_alg_policy, move_backward_loop<t_alg_policy>, move_backward_trivial>(
      ::portable_stl::move(first), ::portable_stl::move(last), ::portable_stl::move(result));
  }
} // namespace algorithm_helper

template<class t_bidirectional_iterator1, class t_bidirectional_iterator2>
inline t_bidirectional_iterator2 move_backward(
  t_bidirectional_iterator1 first, t_bidirectional_iterator1 last, t_bidirectional_iterator2 result) {
  return ::portable_stl::get<1>(algorithm_helper::move_backward_impl<::portable_stl::classic_alg_policy>(
    ::portable_stl::move(first), ::portable_stl::move(last), ::portable_stl::move(result)));
}
} // namespace portable_stl

#endif // PSTL_MOVE_BACKWARD_H
