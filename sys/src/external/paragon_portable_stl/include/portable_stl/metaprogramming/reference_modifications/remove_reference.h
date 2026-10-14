// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="remove_reference.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_REMOVE_REFERENCE_H
#define PSTL_REMOVE_REFERENCE_H

namespace portable_stl {
/**
 * @brief If t_type has type "reference to t_type_value" then the member typedef type denotes t_type_value; otherwise,
 * type denotes t_type.
 *
 * @tparam t_type for convert.
 */
template<class t_type> class remove_reference final {
public:
  /**
   * @brief Result type.
   */
  using type = t_type;
};

/**
 * @brief If t_type has type "reference to t_type_value" then the member typedef type denotes t_type_value; otherwise,
 * type denotes t_type.
 * lvalue reference implementation.
 *
 * @tparam t_type for convert.
 */
template<class t_type> class remove_reference<t_type &> final {
public:
  /**
   * @brief Result type.
   */
  using type = t_type;
};

/**
 * @brief If t_type has type "reference to t_type_value" then the member typedef type denotes t_type_value; otherwise,
 * type denotes t_type.
 * rvalue reference implementation.
 *
 * @tparam t_type for convert.
 */
template<class t_type> class remove_reference<t_type &&> final {
public:
  /**
   * @brief Result type.
   */
  using type = t_type;
};

/**
 * @brief If t_type has type "reference to t_type_value" then the member typedef type denotes t_type_value; otherwise,
 * type denotes t_type.
 *
 * @tparam t_type for convert.
 */
template<class t_type> using remove_reference_t = typename remove_reference<t_type>::type;
} // namespace portable_stl

#endif // PSTL_REMOVE_REFERENCE_H
