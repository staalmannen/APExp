// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_assignable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_ASSIGNABLE_H
#define PSTL_IS_ASSIGNABLE_H

#include "../../utility/general/declval.h"
#include "../helper/integral_constant.h"

namespace std {
namespace type_properties_helpers {

  /**
   * @brief Check t_type is an assignable with t_other.
   * @tparam t_type type for check.
   * @tparam t_other type for assign.
   */
  template<class t_type, class t_other> class is_assignable final {
    /**
     * @brief Detect assign operator.
     * assign operator exist.
     *
     * @tparam t_work_type type for  check.
     * @tparam t_work_args arguments.
     * @param first helper arguments
     * @param second helper arguments
     * @return true;
     */
    template<class t_work_type,
             class t_work_arg,
             class = decltype(::std::declval<t_work_type>() = ::std::declval<t_work_arg>())>
    inline static ::std::true_type assignable_check(::std::size_t first, bool second) noexcept;

    /**
     * @brief Detect constructor.
     * Constructor not exist.
     * @param first helper arguments
     * @param second helper arguments
     * @return false
     */
    template<class, class>
    inline static ::std::false_type assignable_check(::std::size_t first,
                                                              ::std::size_t second) noexcept;

  public:
    /**
     * @brief Result type.
     */
    using type = ::std::bool_constant<__is_assignable(t_type, t_other)>;
    // using type = decltype(assignable_check<t_type, t_other>(0U, true));
  };
} // namespace type_properties_helpers

/**
 * @brief Check t_type is an assignable with t_other.
 * @tparam t_type type for check.
 * @tparam t_other type for assign.
 */
template<class t_type, class t_other>
using is_assignable = typename ::std::type_properties_helpers::is_assignable<t_type, t_other>::type;
} // namespace std

#endif // PSTL_IS_ASSIGNABLE_H
