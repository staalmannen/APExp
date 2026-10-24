// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="indirectly_writable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INDIRECTLY_WRITABLE_H
#define PSTL_INDIRECTLY_WRITABLE_H

#include "../../metaprogramming/helper/integral_constant.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../../metaprogramming/other_transformations/void_t.h"
#include "../../utility/general/declval.h"
#include "../../utility/general/forward.h"
#include "../iter_reference_t.h"

namespace portable_stl {
namespace iterator_helper {
  /**
   * @brief The 'concept' indirectly_writable implementation.
   *
   * @tparam out_type Given type.
   * @tparam t_type Given type.
   */
  template<class out_type, class t_type> class indirectly_writable_impl final {
    /**
     * @brief Test function 1.
     * @tparam Out Given type.
     * @tparam T Given type.
     * @param out_value
     * @param t_value
     * @return ::portable_stl::true_type
     */
    template<class Out, class T>
    static auto test1(Out &&out_value, T &&t_value)
      -> decltype(*out_value = ::portable_stl::forward<T>(t_value), ::portable_stl::true_type{});

    /**
     * @brief Test function 1.
     * @tparam I1
     * @tparam I2
     * @return ::portable_stl::false_type
     */
    template<class I1, class I2> static auto test1(...) -> ::portable_stl::false_type;

    /**
     * @brief Test function 2.
     * @tparam Out Given type.
     * @tparam T Given type.
     * @param out_value
     * @param t_value
     * @return ::portable_stl::true_type
     */
    template<class Out, class T>
    static auto test2(Out &&out_value, T &&t_value)
      -> decltype(*::portable_stl::forward<Out>(out_value) = ::portable_stl::forward<T>(t_value),
                  ::portable_stl::true_type{});

    /**
     * @brief Test function 2.
     * @tparam I1
     * @tparam I2
     * @return ::portable_stl::false_type
     */
    template<class I1, class I2> static auto test2(...) -> ::portable_stl::false_type;

    /**
     * @brief Test function 3.
     * @tparam Out Given type.
     * @tparam T Given type.
     * @param out_value
     * @param t_value
     * @return ::portable_stl::true_type
     */
    template<class Out, class T>
    static auto test3(Out &&out_value, T &&t_value)
      -> decltype(const_cast<::portable_stl::iter_reference_t<Out> const &&>(*out_value)
                  = ::portable_stl::forward<T>(t_value),
                  ::portable_stl::true_type{});

    /**
     * @brief Test function 3.
     * @tparam I1
     * @tparam I2
     * @return ::portable_stl::false_type
     */
    template<class I1, class I2> static auto test3(...) -> ::portable_stl::false_type;

    /**
     * @brief Test function 4.
     * @tparam Out Given type.
     * @tparam T Given type.
     * @param out_value
     * @param t_value
     * @return ::portable_stl::true_type
     */
    template<class Out, class T>
    static auto test4(Out &&out_value, T &&t_value)
      -> decltype(const_cast<::portable_stl::iter_reference_t<Out> const &&>(*::portable_stl::forward<Out>(out_value))
                  = ::portable_stl::forward<T>(t_value),
                  ::portable_stl::true_type{});

    /**
     * @brief Test function 4.
     * @tparam I1
     * @tparam I2
     * @return ::portable_stl::false_type
     */
    template<class I1, class I2> static auto test4(...) -> ::portable_stl::false_type;

  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::conjunction<
      decltype(test1<out_type, t_type>(::portable_stl::declval<out_type>(), ::portable_stl::declval<t_type>())),
      decltype(test2<out_type, t_type>(::portable_stl::declval<out_type>(), ::portable_stl::declval<t_type>())),
      decltype(test3<out_type, t_type>(::portable_stl::declval<out_type>(), ::portable_stl::declval<t_type>())),
      decltype(test4<out_type, t_type>(::portable_stl::declval<out_type>(), ::portable_stl::declval<t_type>()))>;
  };
} // namespace iterator_helper

/**
 * @brief The 'concept' indirectly_writable<Out, T> specifies the requirements for writing a value whose type and value
 * category are encoded by T into an iterator Out's referenced object.
 *
 * @tparam out_type Given type.
 * @tparam t_type Given type.
 */
template<class out_type, class t_type>
using indirectly_writable = typename ::portable_stl::iterator_helper::indirectly_writable_impl<out_type, t_type>::type;

} // namespace portable_stl

#endif /* PSTL_INDIRECTLY_WRITABLE_H */
