// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_array.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_ARRAY_H
#define PSTL_IS_ARRAY_H

#include "../../common/size_t.h"
#include "../cv_modifications/remove_cv.h"
#include "../helper/integral_constant.h"

namespace portable_stl {
namespace primary_type_helper {
  /**
   * @brief t_type is an array type of known or unknown extent.
   * Class template ::portable_stl::array is not an array type.
   * Non array type implementation.
   *
   * @tparam t_type the type for check.
   */
  template<class t_type> class is_array final {
  public:
    /**
     * @brief Result getter.
     * @return false
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief t_type is an array type of known or unknown extent.
   * Class template ::portable_stl::array is not an array type.
   * The unknown size array implementation.
   *
   * @tparam t_type the type for check.
   */
  template<class t_type> class is_array<t_type[]> final {
  public:
    /**
     * @brief Result getter.
     * @return true
     */
    using type = ::portable_stl::true_type;
  };

  /**
   * @brief t_type is an array type of known or unknown extent.
   * Class template ::portable_stl::array is not an array type.
   * The known size array implementation.
   *
   * @tparam t_type the type for check.
   */
  template<class t_type, ::portable_stl::size_t t_size> class is_array<t_type[t_size]> final {
  public:
    /**
     * @brief Result getter.
     * @return true
     */
    using type = ::portable_stl::true_type;
  };
} // namespace primary_type_helper

/**
 * @brief t_type is an array type of known or unknown extent.
 * Class template ::portable_stl::array is not an array type.
 *
 * @tparam t_type the type for check.
 */
template<class t_type>
using is_array = typename primary_type_helper::is_array<::portable_stl::remove_cv_t<t_type>>::type;
} // namespace portable_stl

#endif // PSTL_IS_ARRAY_H
