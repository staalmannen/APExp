// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="remove_extent.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_REMOVE_EXTENT_H
#define PSTL_REMOVE_EXTENT_H
#include "../../common/size_t.h"

namespace portable_stl {
/**
 * @brief If t_type is an array of some type X, provides the member typedef type equal to X, otherwise type is t_type.
 * Note that if t_type is a multidimensional array, only the first dimension is removed.
 * t_type is not an array.
 * @tparam t_type type for transformation.
 */
template<class t_type> class remove_extent final {
public:
  /**
   * @brief Result.
   *
   */
  using type = t_type;
};

/**
 * @brief If t_type is an array of some type X, provides the member typedef type equal to X, otherwise type is t_type.
 * Note that if t_type is a multidimensional array, only the first dimension is removed.
 * t_type is an array with known bound.
 * @tparam t_type type for transformation.
 */
template<class t_type, ::portable_stl::size_t t_size> class remove_extent<t_type[t_size]> final {
public:
  /**
   * @brief Result.
   *
   */
  using type = t_type;
};

/**
 * @brief If t_type is an array of some type X, provides the member typedef type equal to X, otherwise type is t_type.
 * Note that if t_type is a multidimensional array, only the first dimension is removed.
 * t_type is an array with unknown bound.
 * @tparam t_type type for transformation.
 */
template<class t_type> class remove_extent<t_type[]> final {
public:
  /**
   * @brief Result.
   *
   */
  using type = t_type;
};

/**
 * @brief If t_type is "multidimensional array of type_underlying", the resulting member typedef type denotes
 * type_underlying, otherwise t_type.
 * For multidimensional arrays, only the first array dimension is removed.
 * @tparam t_type type for check.
 */
template<class t_type> using remove_extent_t = typename remove_extent<t_type>::type;

} // namespace portable_stl
#endif // PSTL_REMOVE_EXTENT_H
