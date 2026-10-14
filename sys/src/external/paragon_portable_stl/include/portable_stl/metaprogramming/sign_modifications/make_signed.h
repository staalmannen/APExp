// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="make_signed.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MAKE_SIGNED_H
#define PSTL_MAKE_SIGNED_H

/**
 * @brief clang-15...18 somehow broke __make_signed, so use our implementation
 */
#if defined(__has_builtin)
#  if (1 || !(__has_builtin(__make_signed)))
#    include "make_signed/make_signed_impl.h"
#  else
#    include "default/make_signed_impl.h"
#  endif
#else
#  include "make_signed/make_signed_impl.h"
#endif

namespace portable_stl {
/**
 * @brief Makes the given integral type signed.
 *
 * @tparam t_type Type for conversion.
 */
template<class t_type> class make_signed final {
public:
  /**
   * @brief The result type.X
   */
  using type = sign_modifications_helpers::make_signed_t_impl<t_type>;
};

/**
 * @brief Makes the given integral type signed.
 *
 * @tparam t_type Type for conversion.
 */
template<class t_type> using make_signed_t = sign_modifications_helpers::make_signed_t_impl<t_type>;
} // namespace portable_stl
#endif // PSTL_MAKE_SIGNED_H
