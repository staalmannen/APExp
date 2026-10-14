// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="incrementable_traits.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INCREMENTABLE_TRAITS_H
#define PSTL_INCREMENTABLE_TRAITS_H

#include "../metaprogramming/composite_type/is_object.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/logical_operator/negation.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/remove_cvref.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../metaprogramming/primary_type/is_integral.h"
#include "../metaprogramming/primary_type/is_pointer.h"
#include "../metaprogramming/sign_modifications/make_signed.h"
#include "../utility/general/declval.h"
#include "is_primary_template.h"
// #include "iterator_traits.h"

namespace portable_stl {

namespace iterator_helper {
  /**
   * @brief Helper class to check if type has public typename difference_type.
   */
  template<class t_type, class = void> class is_type_has_difference_type final {
  public:
    /**
     * @brief Result 'value' type.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief Helper class to check if type has public typename difference_type.
   *
   * @tparam t_type Tested type.
   */
  template<class t_type>
  class is_type_has_difference_type<t_type, ::portable_stl::void_t<typename t_type::difference_type>> final {
  public:
    /**
     * @brief Result 'value' type.
     */
    using type = ::portable_stl::true_type;
  };

  /**
   * @brief Helper class to check if type has public typename difference_type.
   *
   * @tparam t_type Tested type.
   */
  template<class t_type> using is_type_has_difference_type_t = typename is_type_has_difference_type<t_type>::type;
} // namespace iterator_helper

/**
 * @brief There is no difference_type.
 */
template<class t_type, class = void> class incrementable_traits final {};

/**
 * @brief t_type difference_type can be represented as ptrdiff_t.
 *
 * @tparam t_type The given type.
 */
template<class t_type>
class incrementable_traits<
  t_type *,
  ::portable_stl::enable_if_bool_constant_t<
    ::portable_stl::conjunction<::portable_stl::is_object<t_type>, ::portable_stl::is_pointer<t_type>>>>
  final {
public:
  /**
   * @brief Associated difference type.
   */
  using difference_type = ptrdiff_t;
};

/**
 * @brief t_type has difference_type already.
 *
 * @tparam t_type The given type.
 */
template<class t_type>
class incrementable_traits<
  t_type,
  ::portable_stl::enable_if_bool_constant_t<iterator_helper::is_type_has_difference_type_t<t_type>>>
  final {
public:
  /**
   * @brief Associated difference type.
   */
  using difference_type = typename t_type::difference_type;
};

/**
 * @brief There is no explicit difference_type but it can be deduced from t_type.
 *
 * @tparam t_type The given type.
 */
template<class t_type>
class incrementable_traits<t_type,
                           ::portable_stl::enable_if_bool_constant_t<::portable_stl::conjunction<
                             ::portable_stl::negation<iterator_helper::is_type_has_difference_type_t<t_type>>,
                             ::portable_stl::is_integral<decltype(::portable_stl::declval<t_type const>()
                                                                  - ::portable_stl::declval<t_type const>())>>>>
  final {
public:
  /**
   * @brief Associated difference type.
   */
  using difference_type = ::portable_stl::make_signed_t<decltype(::portable_stl::declval<t_type const>()
                                                                 - ::portable_stl::declval<t_type const>())>;
};

/**
 * @brief Forward declaration.
 */
template<class> class iterator_traits;

/**
 * @brief Compute the associated difference type of an iterator.
 *
 * @tparam t_iterator The iterator type.
 * @tparam t_rm_cvref The medium helper type.
 */
template<class t_iterator, class t_rm_cvref = ::portable_stl::remove_cvref_t<t_iterator>>
using iter_difference_t = typename ::portable_stl::conditional_bool_constant_t<
  iterator_helper::is_primary_template<::portable_stl::iterator_traits<t_rm_cvref>>,
  incrementable_traits<t_rm_cvref>,
  ::portable_stl::iterator_traits<t_rm_cvref>>::difference_type;

} // namespace portable_stl
#endif /* PSTL_INCREMENTABLE_TRAITS_H */
