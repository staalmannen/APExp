// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="bit_move_backward.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BIT_MOVE_BACKWARD_H
#define PSTL_BIT_MOVE_BACKWARD_H

#include "bit_copy_backward.h"

namespace std {
  template<class t_container_type, bool is_const>
  inline bit_iterator<t_container_type, false> move_backward(bit_iterator<t_container_type, is_const> first,
                                                             bit_iterator<t_container_type, is_const> last,
                                                             bit_iterator<t_container_type, false>    result) {
    return std::copy_backward(first, last, result);
  }
} // namespace std

#endif // PSTL_BIT_MOVE_BACKWARD_H
