// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="underlying_type.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_UNDERLYING_TYPE_H
#define PSTL_UNDERLYING_TYPE_H

#include "../cv_modifications/remove_cv.h"
#include "../primary_type/is_enum.h"

namespace portable_stl {
/**
 * @brief If t_type is an enumeration type, the member typedef type denotes the underlying type of t_type otherwise,
 * there is no member type.
 * @tparam t_type type for check.
 */
template<class t_type, class = ::portable_stl::is_enum<remove_cv_t<t_type>>> class underlying_type final {};

/**
 * @brief If t_type is an enumeration type, the member typedef type denotes the underlying type of t_type otherwise,
 * there is a member type.
 * @tparam t_type type for check.
 */
template<class t_type> class underlying_type<t_type, ::portable_stl::true_type> final {
public:
  /**
   * @brief Result type;
   *
   */
  using type = __underlying_type(t_type);
};

/**
 * @brief If t_type is an enumeration type, the member typedef type denotes the underlying type of t_type otherwise,
 * there is no member type.
 * @tparam t_type type for check.
 */
template<class t_type> using underlying_type_t = typename ::portable_stl::underlying_type<t_type>::type;
} // namespace portable_stl

#endif // PSTL_UNDERLYING_TYPE_H
