// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_unbounded_array.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_UNBOUNDED_ARRAY_H
#define PSTL_IS_UNBOUNDED_ARRAY_H

#include "../../common/size_t.h"
#include "../composite_type/is_arithmetic.h"

namespace portable_stl {
namespace type_properties_helpers {
  /**
   * @brief t_type is an array type of unknown bound.
   * Not equal implemetation.
   */
  template<class> class is_unbounded_array final {
  public:
    /**
     * @brief Result getter.
     *
     * @return false.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief t_type is an array type of unknown bound.
   * Equal implemetation.
   * @tparam t_type type for check.
   */
  template<class t_type> class is_unbounded_array<t_type[]> final {
  public:
    /**
     * @brief Result getter.
     *
     * @return false.
     */
    using type = ::portable_stl::true_type;
  };
} // namespace type_properties_helpers

/**
 * @brief t_type is an array type of unknown bound.
 * @tparam t_type type for check.
 */
template<class t_type> using is_unbounded_array = typename type_properties_helpers::is_unbounded_array<t_type>::type;
} // namespace portable_stl

#endif // PSTL_IS_UNBOUNDED_ARRAY_H
