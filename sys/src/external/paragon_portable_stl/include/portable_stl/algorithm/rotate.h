// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="rotate.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ROTATE_H
#define PSTL_ROTATE_H

#include "../iterator/prev.h"
#include "../iterator/random_access_iterator_tag.h"
#include "../metaprogramming/other_transformations/enable_if.h"
#include "../metaprogramming/type_properties/is_trivially_move_assignable.h"
#include "../utility/tuple/tuple.h"
#include "../utility/tuple/tuple_get.h"
#include "copy_move_common.h"
#include "iterator_operations.h"
#include "move_algo.h"
#include "move_backward.h"
#include "swap_ranges.h"

namespace portable_stl {
namespace algorithm_helper {
  template<class t_alg_policy, class t_forward_iterator>
  t_forward_iterator rotate_left(t_forward_iterator first, t_forward_iterator last) {
    using value_type = typename iterator_traits<t_forward_iterator>::value_type;
    using iter_ops   = ::portable_stl::iterator_operations<t_alg_policy>;

    value_type         tmp = iter_ops::iter_move(first);
    t_forward_iterator lm1
      = ::portable_stl::get<1>(::portable_stl::move_impl<t_alg_policy>(iter_ops::next(first), last, first));
    *lm1 = ::portable_stl::move(tmp);
    return lm1;
  }

  template<class t_alg_policy, class t_bidirectional_iterator>
  t_bidirectional_iterator rotate_right(t_bidirectional_iterator first, t_bidirectional_iterator last) {
    using value_type = typename iterator_traits<t_bidirectional_iterator>::value_type;
    using iter_ops   = ::portable_stl::iterator_operations<t_alg_policy>;

    t_bidirectional_iterator lm1 = iter_ops::prev(last);
    value_type               tmp = iter_ops::iter_move(lm1);
    t_bidirectional_iterator fp1 = ::portable_stl::get<1>(
      algorithm_helper::move_backward_impl<t_alg_policy>(first, lm1, ::portable_stl::move(last)));
    *first = ::portable_stl::move(tmp);
    return fp1;
  }

  template<class t_alg_policy, class t_forward_iterator>
  t_forward_iterator rotate_forward(t_forward_iterator first, t_forward_iterator middle, t_forward_iterator last) {
    t_forward_iterator iter = middle;
    while (true) {
      ::portable_stl::iterator_operations<t_alg_policy>::iter_swap(first, iter);
      ++first;
      if (++iter == last) {
        break;
      }
      if (first == middle) {
        middle = iter;
      }
    }
    t_forward_iterator ret = first;
    if (first != middle) {
      iter = middle;
      while (true) {
        ::portable_stl::iterator_operations<t_alg_policy>::iter_swap(first, iter);
        ++first;
        if (++iter == last) {
          if (first == middle) {
            break;
          }
          iter = middle;
        } else if (first == middle) {
          middle = iter;
        }
      }
    }
    return ret;
  }

  /**
   * @brief Greatest common divisor.
   *
   * @tparam t_integral
   * @param x_value
   * @param y_value
   * @return t_integral
   */
  template<typename t_integral> inline t_integral algo_gcd(t_integral x_value, t_integral y_value) {
    do {
      t_integral tmp = x_value % y_value;
      x_value        = y_value;
      y_value        = tmp;
    } while (y_value);
    return x_value;
  }

  template<class t_alg_policy, typename t_random_access_iterator>
  t_random_access_iterator rotate_gcd(
    t_random_access_iterator first, t_random_access_iterator middle, t_random_access_iterator last) {
    using difference_type = typename iterator_traits<t_random_access_iterator>::difference_type;
    using value_type      = typename iterator_traits<t_random_access_iterator>::value_type;
    using iter_ops        = ::portable_stl::iterator_operations<t_alg_policy>;

    difference_type const m1{middle - first};
    difference_type const m2{iter_ops::distance(middle, last)};
    if (m1 == m2) {
      ::portable_stl::algorithm_helper::swap_ranges_impl<t_alg_policy>(first, middle, middle, last);
      return middle;
    }

    difference_type const gcd{algo_gcd(m1, m2)};
    for (t_random_access_iterator ptr{first + gcd}; ptr != first;) {
      value_type               tmp{iter_ops::iter_move(--ptr)};
      t_random_access_iterator ptr1{ptr};
      t_random_access_iterator ptr2{ptr1 + m1};
      do {
        *ptr1 = iter_ops::iter_move(ptr2);
        ptr1  = ptr2;
        difference_type const diff{iter_ops::distance(ptr2, last)};
        if (m1 < diff) {
          ptr2 += m1;
        } else {
          ptr2 = first + (m1 - diff);
        }
      } while (ptr2 != ptr);
      *ptr1 = ::portable_stl::move(tmp);
    }
    return first + m2;
  }

  template<class t_alg_policy, class t_forward_iterator>
  inline t_forward_iterator rotate_impl0(t_forward_iterator first,
                                         t_forward_iterator middle,
                                         t_forward_iterator last,
                                         ::portable_stl::forward_iterator_tag) {
    using value_type = typename iterator_traits<t_forward_iterator>::value_type;

    if (::portable_stl::is_trivially_move_assignable<value_type>{}()) {
      if (::portable_stl::iterator_operations<t_alg_policy>::next(first) == middle) {
        return rotate_left<t_alg_policy>(first, last);
      }
    }
    return rotate_forward<t_alg_policy>(first, middle, last);
  }

  template<class t_alg_policy, class t_bidirectional_iterator>
  inline t_bidirectional_iterator rotate_impl0(t_bidirectional_iterator first,
                                               t_bidirectional_iterator middle,
                                               t_bidirectional_iterator last,
                                               ::portable_stl::bidirectional_iterator_tag) {
    using value_type = typename iterator_traits<t_bidirectional_iterator>::value_type;

    if (::portable_stl::is_trivially_move_assignable<value_type>{}()) {
      if (::portable_stl::iterator_operations<t_alg_policy>::next(first) == middle) {
        return rotate_left<t_alg_policy>(first, last);
      }
      if (::portable_stl::iterator_operations<t_alg_policy>::next(middle) == last) {
        return rotate_right<t_alg_policy>(first, last);
      }
    }
    return rotate_forward<t_alg_policy>(first, middle, last);
  }

  template<class t_alg_policy, class t_random_access_iterator>
  inline t_random_access_iterator rotate_impl0(t_random_access_iterator first,
                                               t_random_access_iterator middle,
                                               t_random_access_iterator last,
                                               ::portable_stl::random_access_iterator_tag) {
    using value_type = typename iterator_traits<t_random_access_iterator>::value_type;

    if (::portable_stl::is_trivially_move_assignable<value_type>{}()) {
      if (::portable_stl::iterator_operations<t_alg_policy>::next(first) == middle) {
        return rotate_left<t_alg_policy>(first, last);
      }
      if (::portable_stl::iterator_operations<t_alg_policy>::next(middle) == last) {
        return rotate_right<t_alg_policy>(first, last);
      }
      return rotate_gcd<t_alg_policy>(first, middle, last);
    }
    return rotate_forward<t_alg_policy>(first, middle, last);
  }

  template<class t_alg_policy, class t_iterator, class t_sentinel>
  ::portable_stl::tuple<t_iterator, t_iterator> rotate_impl(t_iterator first, t_iterator middle, t_sentinel last) {
    using t_ret_type = ::portable_stl::tuple<t_iterator, t_iterator>;

    /**
     * @brief Additional layer of indirection for msvc.
     */
    using iter_ops = ::portable_stl::iterator_operations<t_alg_policy>;

    t_iterator last_iter = iter_ops::next(middle, last);

    if (first == middle) {
      return t_ret_type(last_iter, last_iter);
    }
    if (middle == last) {
      return t_ret_type(::portable_stl::move(first), ::portable_stl::move(last_iter));
    }

    using t_iter_category = typename iter_ops::template iterator_category<t_iterator>;

    auto result = rotate_impl0<t_alg_policy>(
      ::portable_stl::move(first), ::portable_stl::move(middle), last_iter, t_iter_category());

    return t_ret_type(::portable_stl::move(result), ::portable_stl::move(last_iter));
  }
} // namespace algorithm_helper

/**
 * @brief Rotates the order of elements in a range.
 *
 * @tparam t_forward_iterator Must meet the requirements of LegacyForwardIterator.
 * @param first The beginning of the original range.
 * @param middle The element that should appear at the beginning of the rotated range.
 * @param last The end of the original range.
 * @return The iterator to the element originally referenced by *first, i.e. the ::distance(middle, last)-th next
 * iterator of first.
 */
template<class t_forward_iterator>
inline t_forward_iterator rotate(t_forward_iterator first, t_forward_iterator middle, t_forward_iterator last) {
  return ::portable_stl::get<0>(algorithm_helper::rotate_impl<::portable_stl::classic_alg_policy>(
    ::portable_stl::move(first), ::portable_stl::move(middle), ::portable_stl::move(last)));
}

} // namespace portable_stl

#endif // PSTL_ROTATE_H
