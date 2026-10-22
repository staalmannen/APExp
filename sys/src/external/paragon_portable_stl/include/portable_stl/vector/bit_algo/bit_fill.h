// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="bit_fill.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BIT_FILL_H
#define PSTL_BIT_FILL_H

#include "../../algorithm/fill_n.h"
#include "../../algorithm/min.h"
#include "../../memory/to_address.h"
#include "../fwd_decl_bit.h"
#include "bit_common.h"

namespace portable_stl {
namespace bit_algo {
  template<bool t_fill_value, class t_container_type>
  void fill_n(bit_iterator<t_container_type, false> first, typename t_container_type::size_type num) {
    using t_iterator     = bit_iterator<t_container_type, false>;
    using t_storage_type = typename t_iterator::t_storage_type;

    unsigned int const bits_per_word = t_iterator::m_bits_per_word;

    // do first partial word
    if (first.m_ctz != 0) {
      unsigned int   clz_f{bits_per_word - first.m_ctz};
      unsigned int   dn = ::portable_stl::min(clz_f, static_cast<unsigned int>(num));
      t_storage_type m
        = clo<t_storage_type>(bits_per_word - first.m_ctz, bits_per_word) & (~t_storage_type(0) >> (clz_f - dn));
      if (t_fill_value) {
        *first.m_seg |= m;
      } else {
        *first.m_seg &= ~m;
      }
      num -= dn;
      ++first.m_seg;
    }

    // do middle whole words
    t_storage_type numw = num / bits_per_word;
    ::portable_stl::fill_n(
      ::portable_stl::to_address(first.m_seg), numw, t_fill_value ? static_cast<t_storage_type>(-1) : 0);
    num -= numw * bits_per_word;

    // do last partial word
    if (num > 0) {
      first.m_seg += numw;
      t_storage_type m = ~t_storage_type(0) >> (bits_per_word - num);
      if (t_fill_value) {
        *first.m_seg |= m;
      } else {
        *first.m_seg &= ~m;
      }
    }
  }
} // namespace bit_algo

template<class t_container_type>
inline void fill_n_bit(
  bit_iterator<t_container_type, false> first, typename t_container_type::size_type num, bool value) {
  if (num > 0) {
    if (value) {
      bit_algo::fill_n<true>(first, num);
    } else {
      bit_algo::fill_n<false>(first, num);
    }
  }
}

template<class t_container_type>
inline void fill_bit(
  bit_iterator<t_container_type, false> first, bit_iterator<t_container_type, false> last, bool value) {
  fill_n_bit(first, static_cast<typename t_container_type::size_type>(last - first), value);
}
} // namespace portable_stl

#endif // PSTL_BIT_FILL_H
