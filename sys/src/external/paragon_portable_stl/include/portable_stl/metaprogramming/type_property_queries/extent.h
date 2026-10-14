// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="extent.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_EXTENT_H
#define PSTL_EXTENT_H

#include "../../common/size_t.h"
#include "../helper/integral_constant.h"
namespace portable_stl {

namespace type_property_queries_helpers {

  /**
   * @brief Number of elements along the Nth dimension.
   * Non array type.
   * @tparam t_type Type for property query.
   * @tparam N Nth dimension of the type.
   */
  template<class t_type, ::portable_stl::size_t N = 0> class extent final {
  public:
    /**
     * @brief Number of elements.
     */
    constexpr static ::portable_stl::size_t const value{0U};
  };

  /**
   * @brief Number of elements along the Nth dimension.
   * Array of unknown bound.
   * @tparam t_type Type for property query.
   */
  template<class t_type> class extent<t_type[], 0> final {
  public:
    /**
     * @brief Number of elements.
     */
    constexpr static ::portable_stl::size_t const value{0U};
  };

  /**
   * @brief Number of elements along the Nth dimension.
   * Array of unknown bound.
   * @tparam t_type Type for property query.
   * @tparam N Nth dimension of the type.
   */
  template<class t_type, ::portable_stl::size_t N> class extent<t_type[], N> final {
  public:
    /**
     * @brief Number of elements.
     */
    constexpr static ::portable_stl::size_t const value{extent<t_type, N - 1>::value};
  };

  /**
   * @brief Number of elements along the Nth dimension.
   * Array of I elements.
   * @tparam t_type Type for property query.
   * @tparam I Number of elements.
   */
  template<class t_type, ::portable_stl::size_t I> class extent<t_type[I], 0> final {
  public:
    /**
     * @brief Number of elements.
     */
    constexpr static ::portable_stl::size_t const value{I};
  };

  /**
   * @brief Number of elements along the Nth dimension.
   * Array of I elements.
   * @tparam t_type Type for property query.
   * @tparam I Number of elements.
   * @tparam N Nth dimension of the type.
   */
  template<class t_type, ::portable_stl::size_t I, ::portable_stl::size_t N> class extent<t_type[I], N> final {
  public:
    /**
     * @brief Number of elements.
     */
    constexpr static ::portable_stl::size_t const value{extent<t_type, N - 1>::value};
  };

} // namespace type_property_queries_helpers
/**
 * @brief If t_type is an array type, provides value equal to the number of elements along the Nth dimension of the
 * array, if N is in [​0​, rank<T>::value). For any other type, or if t_type is an array of unknown bound along its
 * first dimension and N is ​0​, value is ​0​.
 *
 * @tparam t_type type for property query.
 */
template<class t_type, ::portable_stl::size_t N = 0U>
using extent
  = ::portable_stl::integral_constant<::portable_stl::size_t,
                                      ::portable_stl::type_property_queries_helpers::extent<t_type, N>::value>;

} // namespace portable_stl

#endif // PSTL_EXTENT_H
