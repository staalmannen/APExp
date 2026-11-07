// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_bounded_array.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_BOUNDED_ARRAY_H
#define PSTL_IS_BOUNDED_ARRAY_H

#include "../../common/size_t.h"
#include "../composite_type/is_arithmetic.h"

namespace std {
namespace type_properties_helpers {
  /**
   * @brief t_type is an array type of known bound.
   * Not equal implemetation.
   */
  template<class> class is_bounded_array final {
  public:
    /**
     * @brief Result getter.
     *
     * @return false.
     */
    using type = ::std::false_type;
  };

  /**
   * @brief t_type is an array type of known bound.
   * Equal implemetation.
   * @tparam t_type type for check.
   * @tparam t_size size of array.
   */
  template<class t_type, ::std::size_t t_size> class is_bounded_array<t_type[t_size]> final {
  public:
    /**
     * @brief Result getter.
     *
     * @return false.
     */
    using type = ::std::true_type;
  };
} // namespace type_properties_helpers

/**
 * @brief t_type is an array type of known bound.
 * @tparam t_type type for check.
 */
template<class t_type> using is_bounded_array = typename type_properties_helpers::is_bounded_array<t_type>::type;
} // namespace std

#endif // PSTL_IS_BOUNDED_ARRAY_H
