// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="bit_rotate.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BIT_ROTATE_H
#define PSTL_BIT_ROTATE_H

#include "bit_array.h"
#include "bit_copy.h"
#include "bit_copy_backward.h"
#include "bit_swap_ranges.h"

namespace portable_stl {
  template<class t_container_type>
  bit_iterator<t_container_type, false> rotate(bit_iterator<t_container_type, false> first,
                                               bit_iterator<t_container_type, false> middle,
                                               bit_iterator<t_container_type, false> last) {
    using t_iterator1     = bit_iterator<t_container_type, false>;
    using difference_type = typename t_iterator1::difference_type;

    difference_type diff1 = middle - first;
    difference_type diff2 = last - middle;
    t_iterator1     ret  = first + diff2;
    while (diff1 != 0 && diff2 != 0) {
      if (diff1 <= diff2) {
        if (diff1 <= bit_algo::bit_array<t_container_type>::capacity()) {
          bit_algo::bit_array<t_container_type> b(diff1);
          ::portable_stl::copy(first, middle, b.begin());
          ::portable_stl::copy(b.begin(), b.end(), ::portable_stl::copy(middle, last, first));
          break;
        } else {
          bit_iterator<t_container_type, false> mp = ::portable_stl::swap_ranges(first, middle, middle);
          first                                    = middle;
          middle                                   = mp;
          diff2 -= diff1;
        }
      } else {
        if (diff2 <= bit_algo::bit_array<t_container_type>::capacity()) {
          bit_algo::bit_array<t_container_type> b(diff2);
          ::portable_stl::copy(middle, last, b.begin());
          ::portable_stl::copy_backward(b.begin(), b.end(), ::portable_stl::copy_backward(first, middle, last));
          break;
        } else {
          bit_iterator<t_container_type, false> mp = first + diff2;
          ::portable_stl::swap_ranges(first, mp, middle);
          first = mp;
          diff1 -= diff2;
        }
      }
    }
    return ret;
  }

} // namespace portable_stl

#endif // PSTL_BIT_ROTATE_H
