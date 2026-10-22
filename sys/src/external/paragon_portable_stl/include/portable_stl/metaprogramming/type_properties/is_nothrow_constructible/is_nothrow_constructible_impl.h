// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_nothrow_constructible_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_NOTHROW_CONSTRUCTIBLE_IMPL_H
#define PSTL_IS_NOTHROW_CONSTRUCTIBLE_IMPL_H

#include "../../helper/integral_constant.h"
#include "../is_constructible.h"

namespace portable_stl {
namespace type_properties_helper {
  /**
   * @brief Check t_type is a constructible with argumetns t_args without exceptions.
   * @tparam t_type type for check.
   * @tparam t_is_constructible t_type can costructible with t_args.
   * @tparam t_args arguments for constructor.
   */
  template<class t_type, class t_is_constructible, class... t_args> class is_nothrow_constructible_impl0 final {
  public:
    /**
     * @brief Result value.
     */
    using type = ::portable_stl::bool_constant<noexcept(t_type(::portable_stl::declval<t_args>()...))>;
  };

  /**
   * @brief Check t_type is a constructible with argumetns t_args without exceptions.
   * @tparam t_type type for check.
   * @tparam t_is_constructible t_type can costructible with t_args.
   * @tparam t_args arguments for constructor.
   */
  template<class t_type, class... t_args>
  class is_nothrow_constructible_impl0<t_type, ::portable_stl::false_type, t_args...> final {
  public:
    /**
     * @brief Result value.
     */
    using type = ::portable_stl::false_type;
  };

  template<class t_type, class... t_args>
  using is_nothrow_constructible_impl =
    typename is_nothrow_constructible_impl0<t_type, ::portable_stl::is_constructible<t_type, t_args...>, t_args...>::
      type;
} // namespace type_properties_helper
} // namespace portable_stl

#endif /* PSTL_IS_NOTHROW_CONSTRUCTIBLE_IMPL_H */
