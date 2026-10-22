// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="bit_copy_backward.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BIT_COPY_BACKWARD_H
#define PSTL_BIT_COPY_BACKWARD_H

#include "../../algorithm/copy_n.h"
#include "../../algorithm/min.h"
#include "../../memory/to_address.h"
#include "../fwd_decl_bit.h"
#include "bit_common.h"

namespace portable_stl {
namespace bit_algo {

  template<class t_container_type, bool is_const>
  bit_iterator<t_container_type, false> copy_backward_aligned(bit_iterator<t_container_type, is_const> first,
                                                              bit_iterator<t_container_type, is_const> last,
                                                              bit_iterator<t_container_type, false>    result) {
    using t_iterator      = bit_iterator<t_container_type, is_const>;
    using t_storage_type  = typename t_iterator::t_storage_type;

    unsigned int const bits_per_word = t_iterator::m_bits_per_word;
    auto               num           = static_cast<unsigned int>(last - first); // was difference_type
    if (num > 0U) {
      // do first word
      if (last.m_ctz != 0) {
        unsigned int dn{::portable_stl::min(last.m_ctz, num)};
        num -= dn;
        unsigned int   clz{bits_per_word - last.m_ctz};
        t_storage_type m
          = clo<t_storage_type>(bits_per_word - (last.m_ctz - dn), bits_per_word) & (~t_storage_type(0) >> clz);
        t_storage_type b = *last.m_seg & m;
        *result.m_seg &= ~m;
        *result.m_seg |= b;
        result.m_ctz = static_cast<unsigned int>(((-dn & (bits_per_word - 1U)) + result.m_ctz) % bits_per_word);
        // last.m_ctz = 0
      }
      // last.m_ctz == 0 || num == 0
      // result.m_ctz == 0 || num == 0
      // do middle words
      auto numw = num / bits_per_word;
      result.m_seg -= numw;
      last.m_seg -= numw;
      ::portable_stl::copy_n(::portable_stl::to_address(last.m_seg), numw, ::portable_stl::to_address(result.m_seg));
      num -= numw * bits_per_word;
      // do last word
      if (num > 0) {
        t_storage_type m = ~t_storage_type(0) << (bits_per_word - num);
        t_storage_type b = *--last.m_seg & m;
        *--result.m_seg &= ~m;
        *result.m_seg |= b;
        result.m_ctz = static_cast<unsigned int>(-num & (bits_per_word - 1U));
      }
    }
    return result;
  }

  template<class t_container_type, bool is_const>
  bit_iterator<t_container_type, false> copy_backward_unaligned(bit_iterator<t_container_type, is_const> first,
                                                                bit_iterator<t_container_type, is_const> last,
                                                                bit_iterator<t_container_type, false>    result) {
    using t_iterator     = bit_iterator<t_container_type, is_const>;
    using t_storage_type = typename t_iterator::t_storage_type;

    unsigned int const bits_per_word = t_iterator::m_bits_per_word;
    auto               num           = static_cast<unsigned int>(last - first); // was difference_type
    if (num > 0U) {
      // do first word
      if (last.m_ctz != 0) {
        unsigned int dn{::portable_stl::min(last.m_ctz, num)};
        num -= dn;
        unsigned int   clz_l{bits_per_word - last.m_ctz};
        t_storage_type m
          = clo<t_storage_type>(bits_per_word - (last.m_ctz - dn), bits_per_word) & (~t_storage_type(0) >> clz_l);
        t_storage_type b = *last.m_seg & m;
        unsigned int   clz_r{bits_per_word - result.m_ctz};
        unsigned int   ddn{::portable_stl::min(dn, result.m_ctz)};
        if (ddn > 0U) {
          m = clo<t_storage_type>(bits_per_word - (result.m_ctz - ddn), bits_per_word) & (~t_storage_type(0) >> clz_r);
          *result.m_seg &= ~m;
          if (result.m_ctz > last.m_ctz) {
            *result.m_seg |= b << (result.m_ctz - last.m_ctz);
          } else {
            *result.m_seg |= b >> (last.m_ctz - result.m_ctz);
          }
          result.m_ctz = static_cast<unsigned int>(((-ddn & (bits_per_word - 1U)) + result.m_ctz) % bits_per_word);
          dn -= ddn;
        }
        if (dn > 0U) {
          // result.m_ctz == 0
          --result.m_seg;
          result.m_ctz = static_cast<unsigned int>(-dn & (bits_per_word - 1U));
          m            = clo<t_storage_type>(bits_per_word - result.m_ctz, bits_per_word);
          *result.m_seg &= ~m;
          last.m_ctz -= dn + ddn;
          *result.m_seg |= b << (result.m_ctz - last.m_ctz);
        }
        // last.m_ctz = 0
      }
      // last.m_ctz == 0 || num == 0
      // result.m_ctz != 0 || num == 0
      // do middle words
      unsigned int   clz_r{bits_per_word - result.m_ctz};
      t_storage_type m = ~t_storage_type(0) >> clz_r;
      for (; num >= bits_per_word; num -= bits_per_word) {
        t_storage_type b = *--last.m_seg;
        *result.m_seg &= ~m;
        *result.m_seg |= b >> clz_r;
        *--result.m_seg &= m;
        *result.m_seg |= b << result.m_ctz;
      }
      // do last word
      if (num > 0U) {
        m                 = clo<t_storage_type>(num, bits_per_word);
        t_storage_type b  = *--last.m_seg & m;
        clz_r             = bits_per_word - result.m_ctz;
        t_storage_type dn = ::portable_stl::min(num, result.m_ctz);
        m                 = (~t_storage_type(0) << (result.m_ctz - dn)) & (~t_storage_type(0) >> clz_r);
        *result.m_seg &= ~m;
        *result.m_seg |= b >> (bits_per_word - result.m_ctz);
        result.m_ctz = static_cast<unsigned int>(((-dn & (bits_per_word - 1U)) + result.m_ctz) % bits_per_word);
        num -= dn;
        if (num > 0) {
          // result.m_ctz == 0
          --result.m_seg;
          result.m_ctz = static_cast<unsigned int>(-num & (bits_per_word - 1U));
          m            = clo<t_storage_type>(bits_per_word - result.m_ctz, bits_per_word);
          *result.m_seg &= ~m;
          *result.m_seg |= b << (result.m_ctz - (bits_per_word - num - dn));
        }
      }
    }
    return result;
  }
} // namespace bit_algo

template<class t_container_type, bool is_const>
inline bit_iterator<t_container_type, false> copy_backward(bit_iterator<t_container_type, is_const> first,
                                                           bit_iterator<t_container_type, is_const> last,
                                                           bit_iterator<t_container_type, false>    result) {
  if (last.m_ctz == result.m_ctz) {
    return bit_algo::copy_backward_aligned(first, last, result);
  }
  return bit_algo::copy_backward_unaligned(first, last, result);
}
} // namespace portable_stl

#endif // PSTL_BIT_COPY_BACKWARD_H
