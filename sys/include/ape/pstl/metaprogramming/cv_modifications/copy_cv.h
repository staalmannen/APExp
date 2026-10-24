// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="copy_cv.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_COPY_CV_H
#define PSTL_COPY_CV_H

#include "../other_transformations/conditional_bool_constant.h"
#include "../type_properties/is_const.h"
#include "../type_properties/is_volatile.h"
#include "add_const.h"
#include "add_volatile.h"

namespace portable_stl {

/**
 * @brief Copy cv modificators from ref_type type to t_type type.
 *`
 * @tparam t_type The type to copy to.
 * @tparam ref_type The reference type to copy from.
 */
template<class t_type, class ref_type> class copy_cv final {
private:
  /**
   * @brief Medium type with copied const modificator.
   */
  using c_type = ::portable_stl::conditional_bool_constant_t<::portable_stl::is_const<ref_type>, t_type const, t_type>;

public:
  /**
   * @brief Result type.
   */
  using type
    = ::portable_stl::conditional_bool_constant_t<::portable_stl::is_volatile<ref_type>, c_type volatile, c_type>;
};

/**
 * @brief Copy cv modificators from ref_type type to t_type type.
 *
 * @tparam t_type The type to copy to.
 * @tparam ref_type The reference type to copy from.
 */
template<class t_type, class ref_type> using copy_cv_t = typename copy_cv<t_type, ref_type>::type;
} // namespace portable_stl

#endif // PSTL_COPY_CV_H
