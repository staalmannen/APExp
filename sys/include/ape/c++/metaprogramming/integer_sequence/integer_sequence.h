// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="integer_sequence.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INTEGER_SEQUENCE_H
#define PSTL_INTEGER_SEQUENCE_H

namespace std {

template<class T, T... I> class integer_sequence final {
public:
  using value_type = T;
  constexpr static ::std::size_t size() noexcept {
    return sizeof...(I);
  }
};

template<::std::size_t... t_values>
using index_sequence = integer_sequence<::std::size_t, t_values...>;

} // namespace std

#endif /* PSTL_INTEGER_SEQUENCE_H */
