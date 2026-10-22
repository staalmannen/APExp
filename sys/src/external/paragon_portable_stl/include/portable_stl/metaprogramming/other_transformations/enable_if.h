// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="enable_if.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ENABLE_IF_H
#define PSTL_ENABLE_IF_H

namespace portable_stl {

/**
 * @brief If t_condition is true, the member typedef type denotes t_type; otherwise, there shall be no member type.
 *
 * @tparam t_condition
 * @tparam t_type
 */
template<bool t_condition, class t_type = void> class enable_if final {};

/**
 * @brief If t_condition is true, the member typedef type denotes t_type; otherwise, there shall be no member type.
 *
 * @tparam t_type
 */
template<class t_type> class enable_if<true, t_type> final {
public:
  /**
   * @brief The result type.
   */
  using type = t_type;
};

/**
 * @brief If t_condition is true, the member typedef type denotes t_type; otherwise, there shall be no member type.
 *
 * @tparam t_condition
 * @tparam t_type
 */
template<bool t_condition, class t_type = void> using enable_if_t = typename enable_if<t_condition, t_type>::type;

} // namespace portable_stl

#endif // PSTL_ENABLE_IF_H
