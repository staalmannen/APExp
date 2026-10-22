// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="bit_equal.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BIT_EQUAL_H
#define PSTL_BIT_EQUAL_H

#include "../../algorithm/min.h"
#include "../fwd_decl_bit.h"

namespace portable_stl {

namespace bit_algo {
  template<class t_container_type, bool is_const1, bool is_const2>
  bool equal_unaligned(bit_iterator<t_container_type, is_const1> first1,
                       bit_iterator<t_container_type, is_const1> last1,
                       bit_iterator<t_container_type, is_const2> first2) {
    using t_iterator     = bit_iterator<t_container_type, is_const1>;
    using t_storage_type = typename t_iterator::t_storage_type;

    unsigned int const bits_per_word = t_iterator::m_bits_per_word;
    auto               num           = static_cast<unsigned int>(last1 - first1); // was difference_type
    if (num > 0U) {
      // do first word
      if (first1.m_ctz != 0) {
        unsigned int clz_f{bits_per_word - first1.m_ctz};
        unsigned int dn = {::portable_stl::min(clz_f, num)};
        num -= dn;
        t_storage_type m     = (~t_storage_type(0) << first1.m_ctz) & (~t_storage_type(0) >> (clz_f - dn));
        t_storage_type b     = *first1.m_seg & m;
        unsigned int   clz_r = bits_per_word - first2.m_ctz;
        auto           ddn   = ::portable_stl::min<t_storage_type>(dn, clz_r);
        m                    = (~t_storage_type(0) << first2.m_ctz) & (~t_storage_type(0) >> (clz_r - ddn));
        if (first2.m_ctz > first1.m_ctz) {
          if ((*first2.m_seg & m) != (b << (first2.m_ctz - first1.m_ctz))) {
            return false;
          }
        } else {
          if ((*first2.m_seg & m) != (b >> (first1.m_ctz - first2.m_ctz))) {
            return false;
          }
        }
        first2.m_seg += (ddn + first2.m_ctz) / bits_per_word;
        first2.m_ctz = (ddn + first2.m_ctz) % bits_per_word;
        dn -= ddn;
        if (dn > 0) {
          m = ~t_storage_type(0) >> (bits_per_word - dn);
          if ((*first2.m_seg & m) != (b >> (first1.m_ctz + ddn))) {
            return false;
          }
          first2.m_ctz = dn;
        }
        ++first1.m_seg;
        // first1.m_ctz = 0;
      }
      // first1.m_ctz == 0;

      // do middle words
      unsigned int   clz_r{bits_per_word - first2.m_ctz};
      t_storage_type m = ~t_storage_type(0) << first2.m_ctz;
      for (; num >= bits_per_word; num -= bits_per_word, ++first1.m_seg) {
        t_storage_type b = *first1.m_seg;
        if ((*first2.m_seg & m) != (b << first2.m_ctz)) {
          return false;
        }
        ++first2.m_seg;
        if ((*first2.m_seg & ~m) != (b >> clz_r)) {
          return false;
        }
      }

      // do last word
      if (num > 0) {
        m                = ~t_storage_type(0) >> (bits_per_word - num);
        t_storage_type b = *first1.m_seg & m;
        t_storage_type dn{::portable_stl::min(num, clz_r)};
        m = (~t_storage_type(0) << first2.m_ctz) & (~t_storage_type(0) >> (clz_r - dn));
        if ((*first2.m_seg & m) != (b << first2.m_ctz)) {
          return false;
        }
        first2.m_seg += (dn + first2.m_ctz) / bits_per_word;
        first2.m_ctz = (dn + first2.m_ctz) % bits_per_word;
        num -= dn;
        if (num > 0) {
          m = ~t_storage_type(0) >> (bits_per_word - num);
          if ((*first2.m_seg & m) != (b >> dn)) {
            return false;
          }
        }
      }
    }
    return true;
  }

  template<class t_container_type, bool is_const1, bool is_const2>
  bool equal_aligned(bit_iterator<t_container_type, is_const1> first1,
                     bit_iterator<t_container_type, is_const1> last1,
                     bit_iterator<t_container_type, is_const2> first2) {
    using t_iterator     = bit_iterator<t_container_type, is_const1>;
    using t_storage_type = typename t_iterator::t_storage_type;

    unsigned int const bits_per_word = t_iterator::m_bits_per_word;
    auto               num           = static_cast<unsigned int>(last1 - first1);
    if (num > 0U) {
      // do first word
      if (first1.m_ctz != 0) {
        unsigned int clz = bits_per_word - first1.m_ctz;
        unsigned int dn{::portable_stl::min(clz, num)};
        num -= dn;
        t_storage_type m = (~t_storage_type(0) << first1.m_ctz) & (~t_storage_type(0) >> (clz - dn));
        if ((*first2.m_seg & m) != (*first1.m_seg & m)) {
          return false;
        }
        ++first2.m_seg;
        ++first1.m_seg;
        // first1.m_ctz = 0;
        // first2.m_ctz = 0;
      }
      // first1.m_ctz == 0;
      // first2.m_ctz == 0;
      // do middle words
      for (; num >= bits_per_word; num -= bits_per_word, ++first1.m_seg, ++first2.m_seg) {
        if (*first2.m_seg != *first1.m_seg) {
          return false;
        }
      }
      // do last word
      if (num > 0) {
        t_storage_type m = ~t_storage_type(0) >> (bits_per_word - num);
        if ((*first2.m_seg & m) != (*first1.m_seg & m)) {
          return false;
        }
      }
    }
    return true;
  }

} // namespace bit_algo

template<class t_container_type, bool is_const1, bool is_const2>
inline bool equal(bit_iterator<t_container_type, is_const1> first1,
                  bit_iterator<t_container_type, is_const1> last1,
                  bit_iterator<t_container_type, is_const2> first2) {
  if (first1.m_ctz == first2.m_ctz) {
    return bit_algo::equal_aligned(first1, last1, first2);
  }
  return bit_algo::equal_unaligned(first1, last1, first2);
}
} // namespace portable_stl

#endif // PSTL_BIT_EQUAL_H
