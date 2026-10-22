// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_nothrow_convertible.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_NOTHROW_CONVERTIBLE_H
#define PSTL_IS_NOTHROW_CONVERTIBLE_H

#include "../../utility/general/declval.h"
#include "../helper/integral_constant.h"
#include "../other_transformations/void_t.h"
#include "../primary_type/is_void.h"
#include "is_convertible.h"

namespace portable_stl {

namespace type_relations_helper {
  /**
   * @brief
   *  _Fake_copy_init<T>(E) from msvc:
   * (1) has type T [decay_t<decltype((E))> if T is deduced],
   * (2) is well-formed if and only if E is implicitly convertible to T and T is destructible, and
   * (3) is non-throwing if and only if both conversion from decltype((E)) to T and destruction of T are non-throwing.
   *
   * @tparam t_type
   * @return t_type
   */
  template<class t_type> t_type Fake_copy_init(t_type) noexcept;

/**
 * @brief is_nothrow_convertible_impl implementation.
 * Primary template.
 * @tparam t_from_type
 * @tparam t_to_type
 */
  template<class t_from_type,
           class t_to_type,
           class = ::portable_stl::is_convertible<t_from_type, t_to_type>,
           class = ::portable_stl::is_void<t_to_type>>
  class is_nothrow_convertible_impl final {
  public:
    /**
     * @brief Result type.
     */
    using type
      = ::portable_stl::bool_constant<noexcept(Fake_copy_init<t_to_type>(::portable_stl::declval<t_from_type>()))>;
  };

/**
 * @brief is_nothrow_convertible_impl implementation.
 *
 * @tparam t_from_type
 * @tparam t_to_type
 */
  template<class t_from_type, class t_to_type>
  class is_nothrow_convertible_impl<t_from_type, t_to_type, ::portable_stl::true_type, ::portable_stl::true_type>
    final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::true_type;
  };

/**
 * @brief is_nothrow_convertible_impl implementation.
 *
 * @tparam t_from_type
 * @tparam t_to_type
 * @tparam t_dummy
 */
  template<class t_from_type, class t_to_type, class t_dummy>
  class is_nothrow_convertible_impl<t_from_type, t_to_type, ::portable_stl::false_type, t_dummy> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };
} // namespace type_relations_helper

/**
 * @brief The t_type_from can be converted to the t_type_to with no exceptions.
 *
 * @tparam t_type_from
 * @tparam t_type_to
 */
template<class t_from_type, class t_to_type>
using is_nothrow_convertible =
  typename type_relations_helper::is_nothrow_convertible_impl<t_from_type, t_to_type>::type;
} // namespace portable_stl

#endif // PSTL_IS_NOTHROW_CONVERTIBLE_H
