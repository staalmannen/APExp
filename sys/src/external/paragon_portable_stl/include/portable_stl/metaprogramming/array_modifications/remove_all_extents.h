// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="remove_all_extents.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_REMOVE_ALL_EXTENTS_H
#define PSTL_REMOVE_ALL_EXTENTS_H

#include "../../common/size_t.h"

namespace portable_stl {
/**
 * @brief If t_type is "multidimensional array of type_underlying", the resulting member typedef type denotes
 * type_underlying, otherwise t_type.
 *
 * @tparam t_type type for check.
 */
template<class t_type> class remove_all_extents final {
public:
  /**
   * @brief Result
   *
   */
  using type = t_type;
};

/**
 * @brief If t_type is "multidimensional array of type_underlying", the resulting member typedef type denotes
 * type_underlying, otherwise t_type.
 *
 * @tparam t_type type for check.
 */
template<class t_type, ::portable_stl::size_t t_size> class remove_all_extents<t_type[t_size]> final {
public:
  /**
   * @brief Result
   *
   */
  using type = typename remove_all_extents<t_type>::type;
};

/**
 * @brief If t_type is "multidimensional array of type_underlying", the resulting member typedef type denotes
 * type_underlying, otherwise t_type.
 *
 * @tparam t_type type for check.
 */
template<class t_type> class remove_all_extents<t_type[]> final {
public:
  /**
   * @brief Result
   *
   */
  using type = typename remove_all_extents<t_type>::type;
};

/**
 * @brief If t_type is "multidimensional array of type_underlying", the resulting member typedef type denotes
 * type_underlying, otherwise t_type.
 *
 * @tparam t_type type for check.
 */
template<class t_type> using remove_all_extents_t = typename remove_all_extents<t_type>::type;

} // namespace portable_stl

#endif // PSTL_REMOVE_ALL_EXTENTS_H
