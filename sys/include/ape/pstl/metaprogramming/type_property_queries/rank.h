// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="rank.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_RANK_H
#define PSTL_RANK_H

#include "../../common/size_t.h"
#include "../helper/integral_constant.h"
namespace portable_stl {

namespace type_property_queries_helpers {
  /**
   * @brief Number of dimensions of the array.
   * t_type is not an array.
   * @tparam t_type Type for property query.
   */
  template<class t_type> class rank final {
  public:
    /**
     * @brief Result getter.
     * true.
     */
    constexpr static ::portable_stl::size_t const value{0U};
  };

  /**
   * @brief Number of dimensions of the array.
   * t_type is not an array with unknown bound.
   * @tparam t_type Type for property query.
   */
  template<class t_type> class rank<t_type[]> final {
  public:
    /**
     * @brief Result getter.
     * 1 + number of dimensions in underlaying t_type.
     */
    constexpr static ::portable_stl::size_t const value{1U + rank<t_type>::value};
  };

  /**
   * @brief Number of dimensions of the array.
   * t_type is not an array with known bound.
   * @tparam t_type Type for property query.
   */
  template<class t_type, ::portable_stl::size_t N> class rank<t_type[N]> final {
  public:
    /**
     * @brief Result getter.
     * 1 + number of dimensions in underlaying t_type.
     */
    constexpr static ::portable_stl::size_t const value{1U + rank<t_type>::value};
  };
} // namespace type_property_queries_helpers
/**
 * @brief If t_type is an array type, provides the member constant value equal to the number of dimensions of the array.
 * For any other type, value is ​0​.
 *
 * @tparam t_type Type for property query.
 */
template<class t_type>
using rank = ::portable_stl::integral_constant<::portable_stl::size_t,
                                               ::portable_stl::type_property_queries_helpers::rank<t_type>::value>;
} // namespace portable_stl

#endif // PSTL_RANK_H
