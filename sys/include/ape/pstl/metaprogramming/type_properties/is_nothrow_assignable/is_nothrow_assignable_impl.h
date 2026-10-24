// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_nothrow_assignable_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_NOTHROW_ASSIGNABLE_IMPL_H
#define PSTL_IS_NOTHROW_ASSIGNABLE_IMPL_H

#include "../../cv_modifications/remove_cv.h"
#include "../../helper/integral_constant.h"
#include "../is_assignable.h"
namespace portable_stl {
namespace type_properties_helper {
  /**
   * @brief A wrapper over a build-in function to add indirectness. Necessary for msvc.
   *
   * @tparam t_type Processed type.
   * @tparam t_other Processed type.
   * @tparam t_type can assignable with t_other.
   */
  template<class t_type, class t_other, class t_is_assignable> class is_nothrow_assignable_impl0 final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::bool_constant<noexcept(::portable_stl::declval<::portable_stl::remove_cv_t<t_type>>()
                                                        = (::portable_stl::declval<t_other>()))>;
  };

  /**
   * @brief A wrapper over a build-in function to add indirectness. Necessary for msvc.
   *
   * @tparam t_type Processed type.
   * @tparam t_other Processed type.
   */
  template<class t_type, class t_other>
  class is_nothrow_assignable_impl0<t_type, t_other, ::portable_stl::false_type> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief Check t_type is an assignable with t_other without exceptions.
   * @tparam t_type type for check.
   * @tparam t_other type for assign.
   */
  template<class t_type, class t_other>
  using is_nothrow_assignable_impl =
    typename is_nothrow_assignable_impl0<t_type, t_other, ::portable_stl::is_assignable<t_type, t_other>>::type;
} // namespace type_properties_helper

} // namespace portable_stl

#endif /* PSTL_IS_NOTHROW_ASSIGNABLE_IMPL_H */
