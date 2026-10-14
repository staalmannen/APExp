// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_nothrow_destructible.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_NOTHROW_DESTRUCTIBLE_H
#define PSTL_IS_NOTHROW_DESTRUCTIBLE_H

#include "../../common/size_t.h"
#include "../../utility/general/declval.h"
#include "../helper/integral_constant.h"
#include "is_destructible.h"

namespace portable_stl {
namespace type_properties_helpers {
  namespace is_nothrow {
    /**
     * @brief t_type can be destroyed without exceptions.
     * Not can be destroyed implementation.
     * @tparam t_type type for check.
     */
    template<class, class t_type> class is_nothrow_destructible final {
    public:
      /**
       * @brief Result type
       */
      using type = ::portable_stl::false_type;
    };

    /**
     * @brief t_type can be destroyed without exceptions.
     * Can be destroyed implementation.
     * @tparam t_type type for check.
     */
    template<class t_type> class is_nothrow_destructible<::portable_stl::true_type, t_type> final {
    public:
      /**
       * @brief Result type
       */
      using type = ::portable_stl::bool_constant<noexcept(::portable_stl::declval<t_type>().~t_type())>;
    };
  } // namespace is_nothrow

  /**
   * @brief t_type can be destroyed without exceptions.
   * Implementation for object.
   * @tparam t_type type for check.
   */
  template<class t_type> class is_nothrow_destructible final {
  public:
    /**
     * @brief Result type
     */
    using type = typename ::portable_stl::type_properties_helpers::is_nothrow::
      is_nothrow_destructible<::portable_stl::is_destructible<t_type>, t_type>::type;
  };

  /**
   * @brief t_type can be destroyed without exceptions.
   * Implementation for bounded array.
   * @tparam t_type type for check.
   */
  template<class t_type, ::portable_stl::size_t t_size> class is_nothrow_destructible<t_type[t_size]> final {
  public:
    /**
     * @brief Result type
     */
    using type = typename ::portable_stl::type_properties_helpers::is_nothrow_destructible<t_type>::type;
  };

  /**
   * @brief t_type can be destroyed without exceptions.
   * Implementation for lvalue reference.
   * @tparam t_type type for check.
   */
  template<class t_type> class is_nothrow_destructible<t_type &> final {
  public:
    /**
     * @brief Result type
     */
    using type = ::portable_stl::true_type;
  };

  /**
   * @brief t_type can be destroyed without exceptions.
   * Implementation for rvalue reference.
   * @tparam t_type type for check.
   */
  template<class t_type> class is_nothrow_destructible<t_type &&> final {
  public:
    /**
     * @brief Result type
     */
    using type = ::portable_stl::true_type;
  };

} // namespace type_properties_helpers

/**
 * @brief t_type can be destroyed without exceptions.
 *
 * @tparam t_type type for check.
 */
template<class t_type>
using is_nothrow_destructible = typename ::portable_stl::type_properties_helpers::is_nothrow_destructible<t_type>::type;

} // namespace portable_stl
#endif /* PSTL_IS_NOTHROW_DESTRUCTIBLE_H */
