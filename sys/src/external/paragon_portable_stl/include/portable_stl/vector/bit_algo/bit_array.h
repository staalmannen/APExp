// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="bit_array.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BIT_ARRAY_H
#define PSTL_BIT_ARRAY_H

#include "../../common/size_t.h"
#include "../../memory/construct_at.h"
#include "../../metaprogramming/constant_evaluation/is_constant_evaluated.h"
namespace portable_stl {
namespace bit_algo {
  /**
   * @brief Helper for rotate.
   *
   * @tparam t_container_type
   */
  template<class t_container_type> struct bit_array {
    using difference_type   = typename t_container_type::difference_type;
    using t_storage_type    = typename t_container_type::t_storage_type;
    using t_storage_pointer = typename t_container_type::t_storage_pointer;
    using iterator          = typename t_container_type::iterator;

    static unsigned int const bits_per_word = t_container_type::m_bits_per_word;
    static unsigned int const num           = 4;

    difference_type m_size;
    t_storage_type  m_word[num];

    static difference_type capacity() {
      return static_cast<difference_type>(num * bits_per_word);
    }
    explicit bit_array(difference_type s) : m_size(s) {
      if (::portable_stl::is_constant_evaluated()) {
        for (::portable_stl::size_t i{0U}; i != bit_array<t_container_type>::num; ++i) {
          ::portable_stl::construct_at(m_word + i, 0U);
        }
      }
    }
    iterator begin() {
      return iterator(pointer_traits<t_storage_pointer>::pointer_to(m_word[0]), 0);
    }
    iterator end() {
      return iterator(
        pointer_traits<t_storage_pointer>::pointer_to(m_word[0]) + m_size / static_cast<difference_type>(bits_per_word),
        static_cast<unsigned int>(m_size) % bits_per_word);
    }
  };
} // namespace bit_algo
} // namespace portable_stl

#endif // PSTL_BIT_ARRAY_H
