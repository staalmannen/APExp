// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="assignable_from.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ASSIGNABLE_FROM_H
#define PSTL_ASSIGNABLE_FROM_H

#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/primary_type/is_lvalue_reference.h"
#include "../metaprogramming/primary_type/is_void.h"
#include "../metaprogramming/reference_modifications/remove_reference.h"
#include "../metaprogramming/type_relations/is_same.h"
#include "../utility/general/declval.h"
#include "../utility/general/forward.h"
#include "common_reference_with.h"

namespace std {

namespace concepts_helper {
  /**
   * @brief Helper.
   * Primary template.
   */
  template<class, class, class = void> class com_ref_check final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::std::false_type;
  };

  /**
   * @brief Helper.
   *
   * @tparam T1 Type to test.
   * @tparam T2 Type to test.
   */
  template<class T1, class T2>
  class com_ref_check<
    T1,
    T2,
    ::std::void_t<::std::remove_reference_t<T1> &, ::std::remove_reference_t<T2> &>>
    final {
  public:
    /**
     * @brief Result type.
     * todo(plotitsyn): msvc: const applied to function type has no meaning (warning c4180)
     */
    using type = ::std::common_reference_with<::std::remove_reference_t<T1> const &,
                                                       ::std::remove_reference_t<T2> const &>;
  };

  /**
   * @brief The 'concept' assignable_from<t_type, u_type> implementation.
   *
   * @tparam t_type Type to test.
   * @tparam u_type Type to test.
   */
  template<class t_type, class u_type> class assignable_from_impl final {
    /**
     * @brief Helper function to check semantic.
     *
     * @tparam T1 Type to test.
     * @tparam T2 Type to test.
     * @param arg1 Dummy arg.
     * @return
     */
    template<class T1, class T2, class = decltype(::std::declval<T1>() = ::std::declval<T2>())>
    constexpr static auto check(::std::size_t arg1)
      -> decltype(::std::is_same<T1,
                                          decltype(::std::declval<T1 &>() = ::std::declval<T2>())>{});

    /**
     * @brief Helper function to check semantic.
     * @return
     */
    template<class, class> constexpr static ::std::false_type check(...);

  public:
    /**
     * @brief Result type.
     */
    using type = ::std::conjunction<::std::is_lvalue_reference<t_type>,
                                             typename com_ref_check<t_type, u_type>::type,
                                             decltype(check<t_type, u_type>(0U))>;
  };
} // namespace concepts_helper

/**
 * @brief The 'concept' assignable_from<t_type, u_type> specifies that an expression of the type and value category
 * specified by u_type can be assigned to an lvalue expression whose type is specified by t_type.
 *
 * @tparam t_type Type to test.
 * @tparam u_type Type to test.
 */
template<class t_type, class u_type>
using assignable_from = typename ::std::concepts_helper::assignable_from_impl<t_type, u_type>::type;
} // namespace std

#endif /* PSTL_ASSIGNABLE_FROM_H */
