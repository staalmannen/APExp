// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="float_round_style.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_FLOAT_ROUND_STYLE_H
#define PSTL_FLOAT_ROUND_STYLE_H

namespace portable_stl {

enum class float_round_style : decltype(-1) {
  round_indeterminate       = -1,
  round_toward_zero         = 0,
  round_to_nearest          = 1,
  round_toward_infinity     = 2,
  round_toward_neg_infinity = 3
};

} // namespace portable_stl

#endif // PSTL_FLOAT_ROUND_STYLE_H
