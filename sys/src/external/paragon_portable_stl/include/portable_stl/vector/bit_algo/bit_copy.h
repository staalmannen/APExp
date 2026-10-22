// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="bit_copy.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BIT_COPY_H
#define PSTL_BIT_COPY_H

#include "../../algorithm/copy_n.h"
#include "../../algorithm/min.h"
#include "../../memory/to_address.h"
#include "../fwd_decl_bit.h"
#include "bit_common.h"

namespace portable_stl {
namespace bit_algo {
  template<class t_container_type, bool is_const>
  bit_iterator<t_container_type, false> copy_aligned(bit_iterator<t_container_type, is_const> first,
                                                     bit_iterator<t_container_type, is_const> last,
                                                     bit_iterator<t_container_type, false>    result) {
    using t_iterator     = bit_iterator<t_container_type, is_const>;
    using t_storage_type = typename t_iterator::t_storage_type;

    unsigned int const bits_per_word = t_iterator::m_bits_per_word;
    auto               num           = static_cast<unsigned int>(last - first); // was difference_type
    if (num > 0U) {
      // do first word
      if (first.m_ctz != 0) {
        unsigned     clz{bits_per_word - first.m_ctz};
        unsigned int dn{::portable_stl::min(clz, num)};
        num -= dn;
        t_storage_type m
          = clo<t_storage_type>(bits_per_word - first.m_ctz, bits_per_word) & (~t_storage_type(0) >> (clz - dn));
        t_storage_type b = *first.m_seg & m;
        *result.m_seg &= ~m;
        *result.m_seg |= b;
        result.m_seg += (dn + result.m_ctz) / bits_per_word;
        result.m_ctz = (dn + result.m_ctz) % bits_per_word;
        ++first.m_seg;
        // first.m_ctz = 0;
      }
      // first.m_ctz == 0;
      // do middle words
      t_storage_type numw = num / bits_per_word;
      ::portable_stl::copy_n(::portable_stl::to_address(first.m_seg), numw, ::portable_stl::to_address(result.m_seg));
      num -= numw * bits_per_word;
      result.m_seg += numw;
      // do last word
      if (num > 0) {
        first.m_seg += numw;
        t_storage_type m = ~t_storage_type(0) >> (bits_per_word - num);
        t_storage_type b = *first.m_seg & m;
        *result.m_seg &= ~m;
        *result.m_seg |= b;
        result.m_ctz = num;
      }
    }
    return result;
  }

  template<class t_container_type, bool is_const>
  bit_iterator<t_container_type, false> copy_unaligned(bit_iterator<t_container_type, is_const> first,
                                                       bit_iterator<t_container_type, is_const> last,
                                                       bit_iterator<t_container_type, false>    result) {
    using t_iterator     = bit_iterator<t_container_type, is_const>;
    using t_storage_type = typename t_iterator::t_storage_type;

    unsigned int const bits_per_word = t_iterator::m_bits_per_word;
    auto               num           = static_cast<unsigned int>(last - first); // was difference_type
    if (num > 0U) {
      // do first word
      if (first.m_ctz != 0) {
        unsigned int clz_f{bits_per_word - first.m_ctz};
        unsigned int dn{::portable_stl::min(clz_f, num)};
        num -= dn;
        t_storage_type m
          = clo<t_storage_type>(bits_per_word - first.m_ctz, bits_per_word) & (~t_storage_type(0) >> (clz_f - dn));
        t_storage_type b = *first.m_seg & m;
        unsigned int   clz_r{bits_per_word - result.m_ctz};
        t_storage_type ddn = ::portable_stl::min<t_storage_type>(dn, clz_r);
        m = clo<t_storage_type>(bits_per_word - result.m_ctz, bits_per_word) & (~t_storage_type(0) >> (clz_r - ddn));
        *result.m_seg &= ~m;
        if (result.m_ctz > first.m_ctz) {
          *result.m_seg |= b << (result.m_ctz - first.m_ctz);
        } else {
          *result.m_seg |= b >> (first.m_ctz - result.m_ctz);
        }
        result.m_seg += (ddn + result.m_ctz) / bits_per_word;
        result.m_ctz = (ddn + result.m_ctz) % bits_per_word;
        dn -= ddn;
        if (dn > 0) {
          m = ~t_storage_type(0) >> (bits_per_word - dn);
          *result.m_seg &= ~m;
          *result.m_seg |= b >> (first.m_ctz + ddn);
          result.m_ctz = dn;
        }
        ++first.m_seg;
        // first.m_ctz = 0;
      }
      // first.m_ctz == 0;
      // do middle words
      unsigned int   clz_r{bits_per_word - result.m_ctz};
      t_storage_type m = clo<t_storage_type>(bits_per_word - result.m_ctz, bits_per_word);
      for (; num >= bits_per_word; num -= bits_per_word, ++first.m_seg) {
        t_storage_type b = *first.m_seg;
        *result.m_seg &= ~m;
        *result.m_seg |= b << result.m_ctz;
        ++result.m_seg;
        *result.m_seg &= m;
        *result.m_seg |= b >> clz_r;
      }
      // do last word
      if (num > 0) {
        m                = ~t_storage_type(0) >> (bits_per_word - num);
        t_storage_type b = *first.m_seg & m;
        t_storage_type dn{::portable_stl::min(num, clz_r)};
        m = clo<t_storage_type>(bits_per_word - result.m_ctz, bits_per_word) & (~t_storage_type(0) >> (clz_r - dn));
        *result.m_seg &= ~m;
        *result.m_seg |= b << result.m_ctz;
        result.m_seg += (dn + result.m_ctz) / bits_per_word;
        result.m_ctz = (dn + result.m_ctz) % bits_per_word;
        num -= dn;
        if (num > 0) {
          m = ~t_storage_type(0) >> (bits_per_word - num);
          *result.m_seg &= ~m;
          *result.m_seg |= b >> dn;
          result.m_ctz = num;
        }
      }
    }
    return result;
  }
} // namespace bit_algo

template<class t_container_type, bool is_const>
inline bit_iterator<t_container_type, false> copy_bit(bit_iterator<t_container_type, is_const> first,
                                                      bit_iterator<t_container_type, is_const> last,
                                                      bit_iterator<t_container_type, false>    result) {
  if (first.m_ctz == result.m_ctz) {
    return bit_algo::copy_aligned(first, last, result);
  }
  return bit_algo::copy_unaligned(first, last, result);
}
} // namespace portable_stl

#endif // PSTL_BIT_COPY_H
