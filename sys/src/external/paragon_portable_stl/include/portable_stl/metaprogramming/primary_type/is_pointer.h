// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_pointer.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_POINTER_H
#define PSTL_IS_POINTER_H

#include "../cv_modifications/remove_cv.h"
#include "../helper/integral_constant.h"

namespace portable_stl {
namespace primary_type_helper {
  /**
   * @brief t_type is a pointer type. Includes pointers to functions but not pointers to non-static members.
   * Non pointer implementation.
   *
   * @tparam t_type the value for check.
   */
  template<class t_type> class is_pointer final {
  public:
    /**
     * @brief Result getter.
     * @return false;
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief t_type is a pointer type. Includes pointers to functions but not pointers to non-static members.
   * Pointer implementation.
   *
   * @tparam t_type the value for check.
   */
  template<class t_type> class is_pointer<t_type *> final {
  public:
    /**
     * @brief Result getter.
     * @return true;
     */
    using type = ::portable_stl::true_type;
  };
} // namespace primary_type_helper
/**
 * @brief t_type is a pointer type. Includes pointers to functions but not pointers to non-static members.
 *
 * @tparam t_type the value for check.
 */
template<class t_type>
using is_pointer = typename primary_type_helper::is_pointer<::portable_stl::remove_cv_t<t_type>>::type;
} // namespace portable_stl

#endif // PSTL_IS_POINTER_H
