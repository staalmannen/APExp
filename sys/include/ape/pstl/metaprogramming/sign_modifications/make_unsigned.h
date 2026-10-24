// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="make_unsigned.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MAKE_UNSIGNED_H
#define PSTL_MAKE_UNSIGNED_H

/**
 * @brief clang-15...18 somehow broke __make_unsigned, so use our implementation
 */
#if defined(__has_builtin)
#  if (1 || !(__has_builtin(__make_unsigned)))
#    include "make_unsigned/make_unsigned_impl.h"
#  else
#    include "default/make_unsigned_impl.h"
#  endif
#else
#  include "make_unsigned/make_unsigned_impl.h"
#endif

namespace portable_stl {
/**
 * @brief Makes the given integral type unsigned.
 *
 * @tparam t_type Type for conversion.
 */
template<class t_type> class make_unsigned final {
public:
  /**
   * @brief The result type.X
   */
  using type = sign_modifications_helpers::make_unsigned_t_impl<t_type>;
};

/**
 * @brief Makes the given integral type unsigned.
 *
 * @tparam t_type Type for conversion.
 */
template<class t_type> using make_unsigned_t = typename make_unsigned<t_type>::type;

namespace sign_modifications_helpers {
  template<class t_type> constexpr make_unsigned_t<t_type> to_unsigned_like(t_type value) noexcept {
    return static_cast<make_unsigned_t<t_type>>(value);
  }
} // namespace sign_modifications_helpers

} // namespace portable_stl
#endif /* PSTL_MAKE_UNSIGNED_H */
