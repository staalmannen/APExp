// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_member_pointer.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_MEMBER_POINTER_H
#define PSTL_IS_MEMBER_POINTER_H

#include "../cv_modifications/remove_cv.h"
#include "../helper/integral_constant.h"

namespace portable_stl {
namespace composite_type_helper {
  /**
   * @brief t_type is a pointer-to-member type.
   * @tparam t_type the type for check.
   */
  template<class t_type> class is_member_pointer final {
  public:
    /**
     * @brief Result getter.
     *
     * @return false.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief t_type is a pointer-to-member type.
   * @tparam t_type the type for check.
   * @tparam t_object_type the type of object for the member check.
   */
  template<class t_type, class t_object_type> class is_member_pointer<t_type t_object_type::*> final {
  public:
    /**
     * @brief Result getter.
     *
     * @return true.
     */
    using type = ::portable_stl::true_type;
  };
} // namespace composite_type_helper

/**
 * @brief t_type is a pointer-to-member type.
 * @tparam t_type the type for check.
 */
template<class t_type>
using is_member_pointer = typename composite_type_helper::is_member_pointer<::portable_stl::remove_cv_t<t_type>>::type;

} // namespace portable_stl

#endif // PSTL_IS_MEMBER_POINTER_H
