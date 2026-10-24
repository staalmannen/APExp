// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="bit_swap_ranges.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BIT_SWAP_RANGES_H
#define PSTL_BIT_SWAP_RANGES_H

#include "../../algorithm/min.h"
#include "../fwd_decl_bit.h"

namespace portable_stl {
namespace bit_algo {
  template<class t_container_type_left, class t_container_type_right>
  bit_iterator<t_container_type_right, false> swap_ranges_aligned(bit_iterator<t_container_type_left, false>  first,
                                                                  bit_iterator<t_container_type_left, false>  last,
                                                                  bit_iterator<t_container_type_right, false> result) {
    using t_iterator1     = bit_iterator<t_container_type_left, false>;
    using t_storage_type  = typename t_iterator1::t_storage_type;

    unsigned int const bits_per_word = t_iterator1::m_bits_per_word;
    auto               num           = static_cast<unsigned int>(last - first); // was difference_type
    if (num > 0U) {
      // do first word
      if (first.m_ctz != 0) {
        unsigned int clz{bits_per_word - first.m_ctz};
        unsigned int dn{::portable_stl::min(clz, num)};
        num -= dn;
        t_storage_type m  = (~t_storage_type(0) << first.m_ctz) & (~t_storage_type(0) >> (clz - dn));
        t_storage_type b1 = *first.m_seg & m;
        *first.m_seg &= ~m;
        t_storage_type b2 = *result.m_seg & m;
        *result.m_seg &= ~m;
        *result.m_seg |= b1;
        *first.m_seg |= b2;
        result.m_seg += (dn + result.m_ctz) / bits_per_word;
        result.m_ctz = (dn + result.m_ctz) % bits_per_word;
        ++first.m_seg;
        // first.m_ctz = 0;
      }
      // first.m_ctz == 0;
      // do middle words
      for (; num >= bits_per_word; num -= bits_per_word, ++first.m_seg, ++result.m_seg) {
        swap(*first.m_seg, *result.m_seg);
      }
      // do last word
      if (num > 0) {
        t_storage_type m  = ~t_storage_type(0) >> (bits_per_word - num);
        t_storage_type b1 = *first.m_seg & m;
        *first.m_seg &= ~m;
        t_storage_type b2 = *result.m_seg & m;
        *result.m_seg &= ~m;
        *result.m_seg |= b1;
        *first.m_seg |= b2;
        result.m_ctz = num;
      }
    }
    return result;
  }

  template<class t_container_type_left, class t_container_type_right>
  bit_iterator<t_container_type_right, false> swap_ranges_unaligned(
    bit_iterator<t_container_type_left, false>  first,
    bit_iterator<t_container_type_left, false>  last,
    bit_iterator<t_container_type_right, false> result) {
    using t_iterator1    = bit_iterator<t_container_type_left, false>;
    using t_storage_type = typename t_iterator1::t_storage_type;

    unsigned int const bits_per_word = t_iterator1::m_bits_per_word;
    auto               num           = static_cast<unsigned int>(last - first); // was difference_type
    if (num > 0U) {
      // do first word
      if (first.m_ctz != 0) {
        unsigned int clz_f{bits_per_word - first.m_ctz};
        unsigned int dn{::portable_stl::min(clz_f, num)};
        num -= dn;
        t_storage_type m  = (~t_storage_type(0) << first.m_ctz) & (~t_storage_type(0) >> (clz_f - dn));
        t_storage_type b1 = *first.m_seg & m;
        *first.m_seg &= ~m;
        unsigned int   clz_r{bits_per_word - result.m_ctz};
        t_storage_type ddn = ::portable_stl::min<t_storage_type>(dn, clz_r);
        m                  = (~t_storage_type(0) << result.m_ctz) & (~t_storage_type(0) >> (clz_r - ddn));
        t_storage_type b2  = *result.m_seg & m;
        *result.m_seg &= ~m;
        if (result.m_ctz > first.m_ctz) {
          unsigned int s{result.m_ctz - first.m_ctz};
          *result.m_seg |= b1 << s;
          *first.m_seg |= b2 >> s;
        } else {
          unsigned int s{first.m_ctz - result.m_ctz};
          *result.m_seg |= b1 >> s;
          *first.m_seg |= b2 << s;
        }
        result.m_seg += (ddn + result.m_ctz) / bits_per_word;
        result.m_ctz = (ddn + result.m_ctz) % bits_per_word;
        dn -= ddn;
        if (dn > 0) {
          m  = ~t_storage_type(0) >> (bits_per_word - dn);
          b2 = *result.m_seg & m;
          *result.m_seg &= ~m;
          auto s = static_cast<unsigned int>(first.m_ctz + ddn);
          *result.m_seg |= b1 >> s;
          *first.m_seg |= b2 << s;
          result.m_ctz = dn;
        }
        ++first.m_seg;
        // first.m_ctz = 0;
      }
      // first.m_ctz == 0;
      // do middle words
      t_storage_type m = ~t_storage_type(0) << result.m_ctz;
      unsigned int   clz_r{bits_per_word - result.m_ctz};
      for (; num >= bits_per_word; num -= bits_per_word, ++first.m_seg) {
        t_storage_type b1 = *first.m_seg;
        t_storage_type b2 = *result.m_seg & m;
        *result.m_seg &= ~m;
        *result.m_seg |= b1 << result.m_ctz;
        *first.m_seg = b2 >> result.m_ctz;
        ++result.m_seg;
        b2 = *result.m_seg & ~m;
        *result.m_seg &= m;
        *result.m_seg |= b1 >> clz_r;
        *first.m_seg |= b2 << clz_r;
      }
      // do last word
      if (num > 0) {
        m                 = ~t_storage_type(0) >> (bits_per_word - num);
        t_storage_type b1 = *first.m_seg & m;
        *first.m_seg &= ~m;
        t_storage_type dn = ::portable_stl::min(num, clz_r);
        m                 = (~t_storage_type(0) << result.m_ctz) & (~t_storage_type(0) >> (clz_r - dn));
        t_storage_type b2 = *result.m_seg & m;
        *result.m_seg &= ~m;
        *result.m_seg |= b1 << result.m_ctz;
        *first.m_seg |= b2 >> result.m_ctz;
        result.m_seg += (dn + result.m_ctz) / bits_per_word;
        result.m_ctz = (dn + result.m_ctz) % bits_per_word;
        num -= dn;
        if (num > 0) {
          m  = ~t_storage_type(0) >> (bits_per_word - num);
          b2 = *result.m_seg & m;
          *result.m_seg &= ~m;
          *result.m_seg |= b1 >> dn;
          *first.m_seg |= b2 << dn;
          result.m_ctz = num;
        }
      }
    }
    return result;
  }
} // namespace bit_algo

template<class t_container_type_left, class t_container_type_right>
inline bit_iterator<t_container_type_right, false> swap_ranges(bit_iterator<t_container_type_left, false>  first1,
                                                               bit_iterator<t_container_type_left, false>  last1,
                                                               bit_iterator<t_container_type_right, false> first2) {
  if (first1.m_ctz == first2.m_ctz) {
    return bit_algo::swap_ranges_aligned(first1, last1, first2);
  }
  return bit_algo::swap_ranges_unaligned(first1, last1, first2);
}
} // namespace portable_stl

#endif // PSTL_BIT_SWAP_RANGES_H
