// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="constant_iterator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CONSTANT_ITERATOR_H
#define PSTL_CONSTANT_ITERATOR_H

#include "../concepts/same_as.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "concepts/input_iterator.h"
#include "iter_const_reference_t.h"
#include "iter_reference_t.h"

namespace std {
namespace iterator_helper {
  /**
   * @brief The exposition-only 'concept' constant-iterator<t_type> is satisfied when the result of the indirection
   * operation of the input iterator is its const reference type which implies read-only.
   * @tparam t_type Given type.
   */
  template<class t_type>
  using is_constant_iterator = ::std::conjunction<
    ::std::input_iterator<t_type>,
    ::std::same_as<::std::iter_const_reference_t<t_type>, ::std::iter_reference_t<t_type>>>;
} // namespace iterator_helper
} // namespace std

#endif /* PSTL_CONSTANT_ITERATOR_H */
