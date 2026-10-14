// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="common_type.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_COMMON_TYPE_H
#define PSTL_COMMON_TYPE_H

#include "../../utility/general/declval.h"
#include "../helper/integral_constant.h"
#include "../logical_operator/conjunction.h"
#include "../reference_modifications/add_lvalue_reference.h"
#include "../reference_modifications/remove_reference.h"
#include "../type_relations/is_same.h"
#include "conditional_bool_constant.h"
#include "decay.h"
#include "void_t.h"

namespace portable_stl {

/**
 * @brief Determines the common type of a group of types.
 * No common type.
 */
template<class...> class common_type {};

namespace other_transformations_helper {

  /**
   * @brief Medium helper class-condition.
   * @tparam T1 The first type.
   * @tparam T2 The second type.
   */
  template<class T1, class T2>
  using conditional_result_t = decltype(false ? ::portable_stl::declval<::portable_stl::decay_t<T1>>()
                                              : ::portable_stl::declval<::portable_stl::decay_t<T2>>());

  /**
   * @brief Medium helper class.
   * No internal type.
   */
  template<class, class, class = void> class helper1 {};

  /**
   * @brief Medium helper class.
   * @tparam T1 The first type.
   * @tparam T2 The second type.
   */
  template<class T1, class T2> class helper1<T1, T2, ::portable_stl::void_t<conditional_result_t<T1, T2>>> {
  public:
    /**
     * @brief The result type.
     */
    using type = ::portable_stl::decay_t<conditional_result_t<T1, T2>>;
  };

  /**
   * @brief Medium helper class.
   * @tparam T1 The first type.
   * @tparam T2 The second type.
   */
  template<class T1, class T2, class = void> class helper2 : public helper1<const T1 &, const T2 &> {};

  /**
   * @brief Medium helper class.
   * @tparam T1 The first type.
   * @tparam T2 The second type.
   */
  template<class T1, class T2>
  class helper2<T1, T2, ::portable_stl::void_t<conditional_result_t<T1, T2>>> : public helper1<T1, T2> {};

  /**
   * @brief Medium helper class.
   * @tparam T1 The first type.
   * @tparam T2 The second type.
   */
  template<class T1, class T2>
  using helper3_cond_t = ::portable_stl::conjunction<::portable_stl::is_same<T1, ::portable_stl::decay_t<T1>>,
                                                     ::portable_stl::is_same<T2, ::portable_stl::decay_t<T2>>>;

  /**
   * @brief Implementation for two types.
   * @tparam T1 The first type.
   * @tparam T2 The second type.
   */
  template<class T1, class T2, class = helper3_cond_t<T1, T2>>
  class common_type_two_impl : public common_type_two_impl<::portable_stl::decay_t<T1>, ::portable_stl::decay_t<T2>> {};

  /**
   * @brief Implementation for two types.
   * @tparam T1 The first type.
   * @tparam T2 The second type.
   */
  template<class T1, class T2>
  class common_type_two_impl<T1, T2, ::portable_stl::true_type> : public helper2<T1, T2> {};

  /**
   * @brief Determines the common type of a group of types.
   * Implementation for multiple types.
   * @tparam AlwaysVoid The stub class for SFINAE.
   * @tparam T1 The first type.
   * @tparam T2 The second type.
   * @tparam ...R Rest types.
   */
  template<class AlwaysVoid, class T1, class T2, class... R> class common_type_multi_impl {};

  /**
   * @brief Determines the common type of a group of types.
   * Implementation for multiple types.
   * @tparam T1 The first type.
   * @tparam T2 The second type.
   * @tparam ...R Rest types.
   */
  template<class T1, class T2, class... R>
  class common_type_multi_impl<::portable_stl::void_t<typename common_type<T1, T2>::type>, T1, T2, R...>
      : public common_type<typename common_type<T1, T2>::type, R...> {};

} // namespace other_transformations_helper
/**
 * @brief Determines the common type of a group of types.
 * @tparam T The only given type.
 */
template<class T> class common_type<T> : public other_transformations_helper::common_type_two_impl<T, T> {};

/**
 * @brief Determines the common type of a group of types.
 * @tparam T1 The first type.
 * @tparam T2 The second type.
 */
template<class T1, class T2>
class common_type<T1, T2> : public other_transformations_helper::common_type_two_impl<T1, T2> {};

/**
 * @brief Determines the common type of a group of types.
 * @tparam T1 The first type.
 * @tparam T2 The second type.
 * @tparam ...R Rest types.
 */
template<class T1, class T2, class... R>
class common_type<T1, T2, R...> : public other_transformations_helper::common_type_multi_impl<void, T1, T2, R...> {};

/**
 * @brief Determines the common type of a group of types.
 */
template<class... T> using common_type_t = typename common_type<T...>::type;

} // namespace portable_stl

#endif // PSTL_COMMON_TYPE_H
