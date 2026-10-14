// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_swappable_with.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_SWAPPABLE_WITH_H
#define PSTL_IS_SWAPPABLE_WITH_H

// clang-format off
#include "../../utility/general/swap_def.h"
// clang-format on

#include "../../utility/general/declval.h"
#include "../../utility/general/forward.h"
#include "../helper/integral_constant.h"
#include "../logical_operator/conjunction.h"
#include "../other_transformations/enable_if_bool_constant.h"
#include "../other_transformations/void_t.h"
#include "../reference_modifications/add_lvalue_reference.h"
#include "../type_properties/is_move_assignable.h"
#include "../type_properties/is_move_constructible.h"
#include "../type_properties/is_nothrow_move_assignable.h"
#include "../type_properties/is_nothrow_move_constructible.h"
#include "../type_properties/is_nothrow_swappable.h"

namespace portable_stl {

namespace is_swappable_with_helpers {
  /**
   * @brief Forward declaration of helper internal class.
   *
   * @tparam t_type Tested type.
   */
  template<class t_type, class u_type> class is_swappable_with_class;
} // namespace is_swappable_with_helpers

/**
 * @brief Declaration used by is_swappable_with_impl.
 *
 * @tparam t_type Tested type.
 * @tparam t_size
 * @param left one array for swap.
 * @param right other array for swap.
 */
template<
  class t_type,
  ::portable_stl::size_t t_size,
  ::portable_stl::enable_if_bool_constant_t<typename ::portable_stl::is_swappable_with_helpers::is_swappable_with_class<
                                              ::portable_stl::add_lvalue_reference_t<t_type>,
                                              ::portable_stl::add_lvalue_reference_t<t_type>>::type,
                                            int>
  = 0>
inline void swap(t_type (&left)[t_size],
                 t_type (&right)[t_size]) /*noexcept(::portable_stl::is_nothrow_swappable<t_type>{}())*/;

namespace is_swappable_with_helpers {
  /**
   * @brief Check the expressions swap(declval<t_type>(), declval<t_other_type>())
   * and swap(declval<t_other_type>(), declval<t_type>()) is valid.
   * Valid version.
   * @tparam t_type one type for check.
   * @tparam t_other_type other type for check.
   */
  template<class t_type, class t_other_type> class is_swappable_with_impl final {
    /**
     * @brief Test function.
     *
     * @tparam T1
     * @tparam T2
     * @param t_value
     * @param u_value
     * @return ::portable_stl::true_type
     */
    template<class T1, class T2>
    static auto test(T1 &&t_value, T2 &&u_value)
      -> decltype(swap(::portable_stl::forward<T1>(t_value), ::portable_stl::forward<T2>(u_value)),
                  ::portable_stl::true_type{});

    /**
     * @brief Test function.
     *
     * @tparam T1
     * @tparam T2
     * @return ::portable_stl::false_type
     */
    template<class T1, class T2> static auto test(...) -> ::portable_stl::false_type;

  public:
    /**
     * @brief Result type.
     */
    using type = decltype(test<t_type, t_other_type>(::portable_stl::declval<t_type>(),
                                                     ::portable_stl::declval<t_other_type>()));
  };

  /**
   * @brief Check the expressions swap(declval<t_type>(), declval<t_other_type>())
   * and swap(declval<t_other_type>(), declval<t_type>()) is valid.
   * Valid version.
   * @tparam t_type one type for check.
   * @tparam t_other_type other type for check.
   */
  template<class t_type, class t_other_type>
  using is_swappable_with_impl_t = typename is_swappable_with_impl<t_type, t_other_type>::type;
} // namespace is_swappable_with_helpers

/**
 * @brief Check the expressions swap(declval<t_type>(), declval<t_other_type>())
 * and swap(declval<t_other_type>(), declval<t_type>()) is valid.
 *
 * @tparam t_type one type for check.
 * @tparam t_other_type other type for check.
 */
template<class t_type, class t_other_type>
using is_swappable_with
  = ::portable_stl::conjunction<is_swappable_with_helpers::is_swappable_with_impl_t<t_type, t_other_type>,
                                is_swappable_with_helpers::is_swappable_with_impl_t<t_other_type, t_type>>;

namespace is_swappable_with_helpers {
  /**
   * @brief Can not use forward declaration of the template alias 'is_swappable', so add
   * helper class is_swappable_internal_impl.
   *
   * @tparam t_type Tested type.
   */
  template<class t_type, class u_type> class is_swappable_with_class final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::is_swappable_with<t_type, u_type>;
  };
} // namespace is_swappable_with_helpers
} // namespace portable_stl

#endif /* PSTL_IS_SWAPPABLE_WITH_H */
