// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_convertible.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_CONVERTIBLE_H
#define PSTL_IS_CONVERTIBLE_H

#include "../../utility/general/declval.h"
#include "../logical_operator/conjunction.h"
#include "../logical_operator/disjunction.h"
#include "../primary_type/is_void.h"

namespace portable_stl {
namespace type_relations_helper {
  /**
   * @brief Check the t_type_from can implicity convert to the t_type_to.
   *
   * @tparam t_type_from the source type.
   * @tparam t_type_to the target type.
   */
  template<class t_type_from, class t_type_to> class is_convertible final {
    /**
     * @brief Checker. Implementation for the t_type_from can implicity convert to the t_type_to.
     * @return true
     */
    template<class t_work_type_from,
             class t_work_type_to,
             class = decltype(::portable_stl::declval<void (&)(t_work_type_to)>()(
               ::portable_stl::declval<t_work_type_from>()))>
    inline static ::portable_stl::true_type check(::portable_stl::size_t, bool) noexcept;

    /**
     * @brief Checker. Implementation for the t_type_from can not implicity convert to the t_type_to.
     * @return false;
     */
    template<class t_work_type_from, class t_work_type_to>
    inline static ::portable_stl::false_type check(::portable_stl::size_t, ::portable_stl::size_t) noexcept;

  public:
    /**
     * @brief Result type.
     */
    using type = decltype(check<t_type_from, t_type_to>(0U, true));
  };
} // namespace type_relations_helper

/**
 * @brief The t_type_from can be converted to the t_type_to.
 *
 * @tparam t_type_from
 * @tparam t_type_to
 */
template<class t_type_from, class t_type_to>
using is_convertible = ::portable_stl::disjunction<
  ::portable_stl::conjunction<::portable_stl::is_void<t_type_from>, ::portable_stl::is_void<t_type_to>>,
  typename type_relations_helper::is_convertible<t_type_from, t_type_to>::type>;

} // namespace portable_stl

#endif // PSTL_IS_CONVERTIBLE_H
