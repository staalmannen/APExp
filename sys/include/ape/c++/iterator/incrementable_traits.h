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

namespace std {

namespace iterator_helper {
  /**
   * @brief Helper class to check if type has public typename difference_type.
   */
  template<class t_type, class = void> class is_type_has_difference_type final {
  public:
    /**
     * @brief Result 'value' type.
     */
    using type = ::std::false_type;
  };

  /**
   * @brief Helper class to check if type has public typename difference_type.
   *
   * @tparam t_type Tested type.
   */
  template<class t_type>
  class is_type_has_difference_type<t_type, ::std::void_t<typename t_type::difference_type>> final {
  public:
    /**
     * @brief Result 'value' type.
     */
    using type = ::std::true_type;
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
  ::std::enable_if_bool_constant_t<
    ::std::conjunction<::std::is_object<t_type>, ::std::is_pointer<t_type>>>>
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
  ::std::enable_if_bool_constant_t<iterator_helper::is_type_has_difference_type_t<t_type>>>
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
                           ::std::enable_if_bool_constant_t<::std::conjunction<
                             ::std::negation<iterator_helper::is_type_has_difference_type_t<t_type>>,
                             ::std::is_integral<decltype(::std::declval<t_type const>()
                                                                  - ::std::declval<t_type const>())>>>>
  final {
public:
  /**
   * @brief Associated difference type.
   */
  using difference_type = ::std::make_signed_t<decltype(::std::declval<t_type const>()
                                                                 - ::std::declval<t_type const>())>;
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
template<class t_iterator, class t_rm_cvref = ::std::remove_cvref_t<t_iterator>>
using iter_difference_t = typename ::std::conditional_bool_constant_t<
  iterator_helper::is_primary_template<::std::iterator_traits<t_rm_cvref>>,
  incrementable_traits<t_rm_cvref>,
  ::std::iterator_traits<t_rm_cvref>>::difference_type;

} // namespace std
#endif /* PSTL_INCREMENTABLE_TRAITS_H */
