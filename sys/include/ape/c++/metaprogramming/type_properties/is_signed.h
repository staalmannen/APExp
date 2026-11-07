// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_signed.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_SIGNED_H
#define PSTL_IS_SIGNED_H

#include "../composite_type/is_arithmetic.h"
#include "../helper/integral_constant.h"
#include "../logical_operator/conjunction.h"

namespace std {
namespace type_properties_helpers {
  /**
   * @brief t_type is a signed type.
   * Not signed implementation.
   * @tparam t_type for check
   */
  template<class t_type, bool = (t_type(-1) < t_type(0))> class is_signed final {
  public:
    /**
     * @brief Result getter.
     *
     * @return false.
     */
    using type = ::std::false_type;
  };

  /**
   * @brief t_type is a signed type.
   * Signed implementation.
   * @tparam t_type for check
   */
  template<class t_type> class is_signed<t_type, true> final {
  public:
    /**
     * @brief Result getter.
     *
     * @return true.
     */
    using type = ::std::true_type;
  };
} // namespace type_properties_helpers

/**
 * @brief t_type is a signed type.
 * @tparam t_type type for check.
 */
template<class t_type>
using is_signed
  = ::std::conjunction<::std::is_arithmetic<t_type>,
                                typename ::std::type_properties_helpers::is_signed<t_type>::type>;
} // namespace std

#endif // PSTL_IS_SIGNED_H
