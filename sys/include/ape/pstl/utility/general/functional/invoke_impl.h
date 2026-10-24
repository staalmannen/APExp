// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="invoke_impl.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INVOKE_IMPL_H
#define PSTL_INVOKE_IMPL_H

#include "../../../common/size_t.h"
#include "../../../metaprogramming/cv_modifications/remove_cv.h"
#include "../../../metaprogramming/helper/integral_constant.h"
#include "../../../metaprogramming/helper/nat.h"
#include "../../../metaprogramming/logical_operator/conjunction.h"
#include "../../../metaprogramming/logical_operator/disjunction.h"
#include "../../../metaprogramming/logical_operator/negation.h"
#include "../../../metaprogramming/other_transformations/decay.h"
#include "../../../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../../../metaprogramming/primary_type/is_member_function_pointer.h"
#include "../../../metaprogramming/primary_type/is_member_object_pointer.h"
#include "../../../metaprogramming/primary_type/is_void.h"
#include "../../../metaprogramming/type_properties/is_reference_wrapper.h"
#include "../../../metaprogramming/type_relations/is_base_of.h"
#include "../../../metaprogramming/type_traits/is_core_convertible.h"
#include "../../../utility/general/declval.h"

namespace portable_stl {
namespace functional_helper {
  struct construct_from_any {
    construct_from_any(...);
  };

  /**
   * @brief Helper to get class by member function pointer t_decayed_func.
   * Primary template.
   *
   * @tparam t_decayed_func
   */
  template<class t_decayed_func> class member_pointer_class_type final {};

  /**
   * @brief Helper to get class by member function pointer t_decayed_func.
   *
   * @tparam t_ret_type Return type.
   * @tparam t_class_type Result class type.
   */
  template<class t_ret_type, class t_class_type> class member_pointer_class_type<t_ret_type t_class_type::*> final {
  public:
    using type = t_class_type;
  };

  template<class t_func,
           class t_arg0,
           class t_decay_func = ::portable_stl::decay_t<t_func>,
           class t_decay_arg0 = ::portable_stl::decay_t<t_arg0>,
           class t_class      = typename member_pointer_class_type<t_decay_func>::type> // class of member_function
  using enable_if_bullet1 = ::portable_stl::enable_if_bool_constant_t<
    ::portable_stl::conjunction<::portable_stl::is_member_function_pointer<t_decay_func>,
                                ::portable_stl::disjunction<::portable_stl::is_same<t_class, t_decay_arg0>,
                                                            ::portable_stl::is_base_of<t_class, t_decay_arg0>>>>;

  template<class t_func,
           class t_arg0,
           class t_decay_func = ::portable_stl::decay_t<t_func>,
           class t_decay_arg0 = ::portable_stl::decay_t<t_arg0>>
  using enable_if_bullet2 = ::portable_stl::enable_if_bool_constant_t<
    ::portable_stl::conjunction<::portable_stl::is_member_function_pointer<t_decay_func>,
                                ::portable_stl::is_reference_wrapper<t_decay_arg0>>>;

  template<class t_func,
           class t_arg0,
           class t_decay_func = ::portable_stl::decay_t<t_func>,
           class t_decay_arg0 = ::portable_stl::decay_t<t_arg0>,
           class t_class      = typename member_pointer_class_type<t_decay_func>::type>
  using enable_if_bullet3 = ::portable_stl::enable_if_bool_constant_t<::portable_stl::conjunction<
    ::portable_stl::is_member_function_pointer<t_decay_func>,
    ::portable_stl::negation<::portable_stl::disjunction<::portable_stl::is_same<t_class, t_decay_arg0>,
                                                         ::portable_stl::is_base_of<t_class, t_decay_arg0>>>,
    ::portable_stl::negation<::portable_stl::is_reference_wrapper<t_decay_arg0>>>>;

  template<class t_func,
           class t_arg0,
           class t_decay_func = ::portable_stl::decay_t<t_func>,
           class t_decay_arg0 = ::portable_stl::decay_t<t_arg0>,
           class t_class      = typename member_pointer_class_type<t_decay_func>::type>
  using enable_if_bullet4 = ::portable_stl::enable_if_bool_constant_t<
    ::portable_stl::conjunction<::portable_stl::is_member_object_pointer<t_decay_func>,
                                ::portable_stl::disjunction<::portable_stl::is_same<t_class, t_decay_arg0>,
                                                            ::portable_stl::is_base_of<t_class, t_decay_arg0>>>>;

  template<class t_func,
           class t_arg0,
           class t_decay_func = ::portable_stl::decay_t<t_func>,
           class t_decay_arg0 = ::portable_stl::decay_t<t_arg0>>
  using enable_if_bullet5 = ::portable_stl::enable_if_bool_constant_t<
    ::portable_stl::conjunction<::portable_stl::is_member_object_pointer<t_decay_func>,
                                ::portable_stl::is_reference_wrapper<t_decay_arg0>>>;

  template<class t_func,
           class t_arg0,
           class t_decay_func = ::portable_stl::decay_t<t_func>,
           class t_decay_arg0 = ::portable_stl::decay_t<t_arg0>,
           class t_class      = typename member_pointer_class_type<t_decay_func>::type>
  using enable_if_bullet6 = ::portable_stl::enable_if_bool_constant_t<::portable_stl::conjunction<
    ::portable_stl::is_member_object_pointer<t_decay_func>,
    ::portable_stl::negation<::portable_stl::disjunction<::portable_stl::is_same<t_class, t_decay_arg0>,
                                                         ::portable_stl::is_base_of<t_class, t_decay_arg0>>>,
    ::portable_stl::negation<::portable_stl::is_reference_wrapper<t_decay_arg0>>>>;

  // fall back - none of the bullets

  template<class... t_args>::portable_stl::nat_class invoke_impl(construct_from_any, t_args &&...args);

  // bullets 1, 2 and 3

  template<class t_func, class t_arg0, class... t_args, class = enable_if_bullet1<t_func, t_arg0>>
  inline decltype((::portable_stl::declval<t_arg0>().*::portable_stl::declval<t_func>())(
    ::portable_stl::declval<t_args>()...))
    invoke_impl(t_func &&fn, t_arg0 &&arg0, t_args &&...args) noexcept(
      noexcept((static_cast<t_arg0 &&>(arg0).*fn)(static_cast<t_args &&>(args)...))) {
    return (static_cast<t_arg0 &&>(arg0).*fn)(static_cast<t_args &&>(args)...);
  }

  template<class t_func, class t_arg0, class... t_args, class = enable_if_bullet2<t_func, t_arg0>>
  inline decltype((::portable_stl::declval<t_arg0>().get().*::portable_stl::declval<t_func>())(
    ::portable_stl::declval<t_args>()...))
    invoke_impl(t_func &&fn, t_arg0 &&arg0, t_args &&...args) noexcept(
      noexcept((arg0.get().*fn)(static_cast<t_args &&>(args)...))) {
    return (arg0.get().*fn)(static_cast<t_args &&>(args)...);
  }

  template<class t_func, class t_arg0, class... t_args, class = enable_if_bullet3<t_func, t_arg0>>
  inline decltype(((*::portable_stl::declval<t_arg0>()).*::portable_stl::declval<t_func>())(
    ::portable_stl::declval<t_args>()...))
    invoke_impl(t_func &&fn, t_arg0 &&arg0, t_args &&...args) noexcept(
      noexcept(((*static_cast<t_arg0 &&>(arg0)).*fn)(static_cast<t_args &&>(args)...))) {
    return ((*static_cast<t_arg0 &&>(arg0)).*fn)(static_cast<t_args &&>(args)...);
  }

  // bullets 4, 5 and 6

  template<class t_func, class t_arg0, class = enable_if_bullet4<t_func, t_arg0>>
  inline decltype(::portable_stl::declval<t_arg0>().*::portable_stl::declval<t_func>()) invoke_impl(
    t_func &&fn, t_arg0 &&arg0) noexcept(noexcept(static_cast<t_arg0 &&>(arg0).*fn)) {
    return static_cast<t_arg0 &&>(arg0).*fn;
  }

  template<class t_func, class t_arg0, class = enable_if_bullet5<t_func, t_arg0>>
  inline decltype(::portable_stl::declval<t_arg0>().get().*::portable_stl::declval<t_func>()) invoke_impl(
    t_func &&fn, t_arg0 &&arg0) noexcept(noexcept(arg0.get().*fn)) {
    return arg0.get().*fn;
  }

  template<class t_func, class t_arg0, class = enable_if_bullet6<t_func, t_arg0>>
  inline decltype((*::portable_stl::declval<t_arg0>()).*::portable_stl::declval<t_func>()) invoke_impl(
    t_func &&fn, t_arg0 &&arg0) noexcept(noexcept((*static_cast<t_arg0 &&>(arg0)).*fn)) {
    return (*static_cast<t_arg0 &&>(arg0)).*fn;
  }

  // bullet 7

  template<class t_func, class... t_args>
  inline decltype(::portable_stl::declval<t_func>()(::portable_stl::declval<t_args>()...)) invoke_impl(
    t_func &&fn, t_args &&...args) noexcept(noexcept(static_cast<t_func &&>(fn)(static_cast<t_args &&>(args)...))) {
    return static_cast<t_func &&>(fn)(static_cast<t_args &&>(args)...);
  }

  /**
   * @brief is_invokable implementation.
   *
   * @tparam t_return_type Return type.
   * @tparam t_func_type Tested callable type.
   * @tparam t_args Argument types.
   */
  template<class t_return_type, class t_func_type, class... t_args> class invokable_r {
    /**
     * @brief Test if func could be called with args...
     *
     * @tparam func Tested callable type.
     * @tparam args Argument types.
     * @return decltype(invoke_impl(::portable_stl::declval<func>(), ::portable_stl::declval<args>()...))
     */
    template<class func, class... args>
    static auto test(::portable_stl::size_t) -> decltype(invoke_impl(::portable_stl::declval<func>(),
                                                                     ::portable_stl::declval<args>()...));

    /**
     * @brief func could not be called with args...
     *
     * @tparam func Tested callable type.
     * @tparam args Argument types.
     * @return ::portable_stl::nat_class
     */
    template<class func, class... args> static ::portable_stl::nat_class test(...);

  public:
    // FIXME: Check that t_return_type, t_func_type, and t_args... are all complete types, cv void,
    // or incomplete array types as required by the standard.

    /**
     * @brief Result of invoking func with args...
     *
     */
    using call_result_type = decltype(test<t_func_type, t_args...>(0));

    /**
     * @brief Checks if result of invoking matchs t_return_type.
     *
     */
    using type = ::portable_stl::conditional_bool_constant_t<
      ::portable_stl::negation<::portable_stl::is_same<call_result_type, ::portable_stl::nat_class>>,
      ::portable_stl::conditional_bool_constant_t<::portable_stl::is_void<t_return_type>,
                                                  ::portable_stl::true_type,
                                                  ::portable_stl::is_core_convertible<call_result_type, t_return_type>>,
      ::portable_stl::false_type>;
  };

  /**
   * @brief is_invokable implementation.
   *
   * @tparam t_func_type Callable type.
   * @tparam ...t_args Argument types to invoke with.
   */
  template<class t_func_type, class... t_args> using invokable = invokable_r<void, t_func_type, t_args...>;

  template<class is_invokable, class is_cv_void, class t_return_type, class t_func_type, class... t_args>
  class nothrow_invokable_r_impl final {
  public:
    using type = ::portable_stl::false_type;
  };

  template<class t_return_type, class t_func_type, class... t_args>
  class nothrow_invokable_r_impl<::portable_stl::true_type,
                                 ::portable_stl::false_type,
                                 t_return_type,
                                 t_func_type,
                                 t_args...>
    final {
    using t_this = nothrow_invokable_r_impl;

    template<class test_type> static void test_noexcept(test_type) noexcept;

    static bool const value = noexcept(t_this::test_noexcept<t_return_type>(
      invoke_impl(::portable_stl::declval<t_func_type>(), ::portable_stl::declval<t_args>()...)));

  public:
    using type = ::portable_stl::bool_constant<value>;
  };

  template<class t_return_type, class t_func_type, class... t_args>
  class nothrow_invokable_r_impl<::portable_stl::true_type,
                                 ::portable_stl::true_type,
                                 t_return_type,
                                 t_func_type,
                                 t_args...>
    final {
    static bool const value
      = noexcept(invoke_impl(::portable_stl::declval<t_func_type>(), ::portable_stl::declval<t_args>()...));

  public:
    using type = ::portable_stl::bool_constant<value>;
  };

} // namespace functional_helper

/**
 * @brief If t_func_type is invocable, return type of call.
 *
 * @tparam t_func_type
 * @tparam ...t_args
 */
template<class t_func_type, class... t_args>
using invoke_of = ::portable_stl::enable_if_bool_constant<
  typename functional_helper::invokable<t_func_type, t_args...>::type,
  typename functional_helper::invokable_r<void, t_func_type, t_args...>::call_result_type>;

} // namespace portable_stl

#endif // PSTL_INVOKE_IMPL_H
