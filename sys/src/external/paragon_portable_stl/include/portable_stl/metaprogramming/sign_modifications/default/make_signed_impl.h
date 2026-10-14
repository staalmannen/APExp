// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="make_signed_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MAKE_SIGNED_IMPL_H
#define PSTL_MAKE_SIGNED_IMPL_H

namespace portable_stl {
namespace sign_modifications_helpers {
  /**
   * @brief Makes the given integral type signed.
   *
   * @tparam t_type Type for conversion.
   */
  template<class t_type> using make_signed_t_impl = __make_signed(t_type);
} // namespace sign_modifications_helpers
} // namespace portable_stl
#endif // PSTL_MAKE_SIGNED_IMPL_H
