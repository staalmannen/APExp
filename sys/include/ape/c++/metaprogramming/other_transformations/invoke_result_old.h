// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="invoke_result_old.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INVOKE_RESULT_OLD_H
#define PSTL_INVOKE_RESULT_OLD_H

#include "../../utility/general/declval.h"
#include "../../utility/general/forward.h"
#include "../../utility/general/functional/reference_wrapper.h"
#include "../helper/integral_constant.h"
#include "../logical_operator/negation.h"
#include "../type_relations/is_base_of.h"
#include "decay.h"
#include "enable_if_bool_constant.h"
#include "../type_properties/is_reference_wrapper.h"

namespace std {

namespace other_transformations_helper {
  /**
   * @brief Main invoke result implementation class.
   * @tparam T
   */
  template<class T> class invoke_impl final {
  public:
    /**
     * @brief
     * @tparam F
     * @tparam Args
     * @param f
     * @param args
     * @return
     */
    template<class F, class... Args>
    static auto call(F &&f, Args &&...args)
      -> decltype(::std::forward<F>(f)(::std::forward<Args>(args)...));
  };

  /**
   * @brief Main invoke result implementation class.
   * @tparam B The base type.
   * @tparam MT The member type.
   */
  template<class B, class MT> class invoke_impl<MT B::*> final {
  public:
    /**
     * @brief
     * @tparam T
     * @tparam Td
     * @tparam
     * @param t
     * @return
     */
    template<class T,
             class Td = ::std::decay_t<T>,
             class    = ::std::enable_if_bool_constant<::std::is_base_of<B, Td>>>
    static auto get(T &&t) -> T &&;

    /**
     * @brief
     * @tparam T
     * @tparam Td
     * @param t
     * @return
     */
    template<class T,
             class Td = ::std::decay_t<T>,
             class    = ::std::enable_if_bool_constant<is_reference_wrapper<T>>>
    static auto get(T &&t) -> decltype(t.get());

    /**
     * @brief
     * @tparam T
     * @tparam Td
     * @param t
     * @return
     */
    template<
      class T,
      class Td = ::std::decay_t<T>,
      class    = ::std::enable_if_bool_constant<::std::negation<::std::is_base_of<B, Td>>>,
      class    = ::std::enable_if_bool_constant<
        ::std::negation<::std::is_reference_wrapper<T>>>>
    static auto get(T &&t) -> decltype(*::std::forward<T>(t));

    /**
     * @brief
     * @tparam T
     * @tparam Args
     * @tparam MT1
     * @param pmf
     * @param t
     * @param args
     * @return
     */
    template<class T,
             class... Args,
             class MT1,
             class = ::std::enable_if_bool_constant<::std::is_function<MT1>>>
    static auto call(MT1 B::*pmf, T &&t, Args &&...args)
      -> decltype((invoke_impl::get(::std::forward<T>(t)).*pmf)(::std::forward<Args>(args)...));

    /**
     * @brief
     * @tparam T
     * @param pmd
     * @param t
     * @return
     */
    template<class T>
    static auto call(MT B::*pmd, T &&t) -> decltype(invoke_impl::get(::std::forward<T>(t)).*pmd);
  };

  /**
   * @brief Invoke The exposition-only operation.
   * @tparam F Callable type.
   * @tparam ArgTypes Arguments types.
   * @tparam Fd
   * @param f The callable object.
   * @param args Arguments of calling.
   * @return
   */
  template<class F, class... ArgTypes, class Fd = ::std::decay_t<F>>
  auto INVOKE(F &&f, ArgTypes &&...args)
    -> decltype(invoke_impl<Fd>::call(::std::forward<F>(f), ::std::forward<ArgTypes>(args)...));

} // namespace other_transformations_helper

namespace other_transformations_helper {
  /**
   * @brief Invoke result initial checking.
   * F can not be called with the arguments ArgTypes...
   */
  template<typename AlwaysVoid, class, class...> class invoke_result final {};

  /**
   * @brief Invoke result initial checking.
   * F can be called with the arguments ArgTypes...
   * @tparam F Callable type.
   * @tparam ...ArgTypes Arguments types.
   */
  template<class F, class... ArgTypes>
  class invoke_result<decltype(void(INVOKE(::std::declval<F>(), ::std::declval<ArgTypes>()...))),
                      F,
                      ArgTypes...>
    final {
  public:
    /**
     * @brief The return type of the Callable type F if invoked with the arguments ArgTypes....
     *
     */
    using type = decltype(INVOKE(::std::declval<F>(), ::std::declval<ArgTypes>()...));
  };

} // namespace other_transformations_helper

/**
 * @brief Deduces the result type of invoking a callable object with a set of arguments.
 *
 * @tparam F Callable type.
 * @tparam ArgTypes Arguments types.
 */
template<class F, class... ArgTypes>
using invoke_result = other_transformations_helper::invoke_result<void, F, ArgTypes...>;

/**
 * @brief Deduces the result type of invoking a callable object with a set of arguments.
 *
 * @tparam F Callable type.
 * @tparam ArgTypes Arguments types.
 */
template<class F, class... ArgTypes>
using invoke_result_t = typename other_transformations_helper::invoke_result<void, F, ArgTypes...>::type;
} // namespace std

#endif // PSTL_INVOKE_RESULT_OLD_H
