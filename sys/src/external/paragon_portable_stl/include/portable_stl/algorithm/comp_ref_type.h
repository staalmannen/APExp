// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="comp_ref_type.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_COMP_REF_TYPE_H
#define PSTL_COMP_REF_TYPE_H

namespace portable_stl {
namespace algorithm_helper {

  // Pass the comparator by lvalue reference.
  template<class t_comp> using comp_ref_type = t_comp &;
} // namespace algorithm_helper
} // namespace portable_stl

#endif // PSTL_COMP_REF_TYPE_H
