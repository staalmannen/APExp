// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="weak_result_type.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_WEAK_RESULT_TYPE_H
#define PSTL_WEAK_RESULT_TYPE_H

#include "../../../functional/binary_function.h"
#include "../../../functional/unary_function.h"
#include "../../../metaprogramming/type_relations/is_same.h"
// #include "invoke_impl.h"

namespace portable_stl {

namespace functional_helper {
  template<class t_type> class has_result_type_impl final {
  private:
    template<class t_test_type> static ::portable_stl::false_type test(...);
    template<class t_test_type> static ::portable_stl::true_type  test(typename t_test_type::result_type  * = 0);

  public:
    using type = decltype(test<t_type>(0));
  };

  template<class t_type> using has_result_type = typename has_result_type_impl<t_type>::type;

  template<class t_type> struct derives_from_unary_function {
  private:
    struct __two {
      char __lx;
      char __lxx;
    };

    static __two test(...);

    template<class t_arg, class t_return_type>
    static ::portable_stl::unary_function_depr<t_arg, t_return_type> test(
      ::portable_stl::unary_function_depr<t_arg, t_return_type> const volatile *);

  public:
    static bool const value = !::portable_stl::is_same<decltype(test((t_type *)0)), __two>::value;
    using type              = decltype(test((t_type *)0));
  };

  template<class t_type> struct derives_from_binary_function {
  private:
    struct __two {
      char __lx;
      char __lxx;
    };

    static __two test(...);

    template<class t_arg1, class t_arg2, class t_return_type>
    static ::portable_stl::binary_function_depr<t_arg1, t_arg2, t_return_type> test(
      ::portable_stl::binary_function_depr<t_arg1, t_arg2, t_return_type> const volatile *);

  public:
    static bool const value = !::portable_stl::is_same<decltype(test((t_type *)0)), __two>::value;
    using type              = decltype(test((t_type *)0));
  };

  template<class t_type, bool = derives_from_unary_function<t_type>::value>
  struct maybe_derive_from_unary_function // bool is true
      : public derives_from_unary_function<t_type>::type {};

  template<class t_type> struct maybe_derive_from_unary_function<t_type, false> {};

  template<class t_type, bool = derives_from_binary_function<t_type>::value>
  struct maybe_derive_from_binary_function // bool is true
      : public derives_from_binary_function<t_type>::type {};

  template<class t_type> struct maybe_derive_from_binary_function<t_type, false> {};

  template<class> struct weak_result_type;

  template<class t_type, class = functional_helper::has_result_type<t_type>>
  struct weak_result_type_imp // bool is true
      : public maybe_derive_from_unary_function<t_type>
      , public maybe_derive_from_binary_function<t_type> {
#if 0 //_LIBCPP_STD_VER <= 17 || defined(_LIBCPP_ENABLE_CXX20_REMOVED_BINDER_TYPEDEFS)
  using result_type _LIBCPP_NODEBUG _LIBCPP_DEPRECATED_IN_CXX17 = typename t_type::result_type;
#endif
  };

  template<class t_type>
  struct weak_result_type_imp<t_type, ::portable_stl::false_type>
      : public maybe_derive_from_unary_function<t_type>
      , public maybe_derive_from_binary_function<t_type> {};
} // namespace functional_helper

template<class t_type> struct weak_result_type : public functional_helper::weak_result_type_imp<t_type> {};

// 0 argument case

template<class t_return_type> struct weak_result_type<t_return_type()> {
#if 0 //_LIBCPP_STD_VER <= 17 || defined(_LIBCPP_ENABLE_CXX20_REMOVED_BINDER_TYPEDEFS)
    using result_type _LIBCPP_NODEBUG _LIBCPP_DEPRECATED_IN_CXX17 = t_return_type;
#endif
};

template<class t_return_type> struct weak_result_type<t_return_type (&)()> {
#if 0 //_LIBCPP_STD_VER <= 17 || defined(_LIBCPP_ENABLE_CXX20_REMOVED_BINDER_TYPEDEFS)
    using result_type _LIBCPP_NODEBUG _LIBCPP_DEPRECATED_IN_CXX17 = t_return_type;
#endif
};

template<class t_return_type> struct weak_result_type<t_return_type (*)()> {
#if 0 //_LIBCPP_STD_VER <= 17 || defined(_LIBCPP_ENABLE_CXX20_REMOVED_BINDER_TYPEDEFS)
    using result_type _LIBCPP_NODEBUG _LIBCPP_DEPRECATED_IN_CXX17 = t_return_type;
#endif
};

// 1 argument case

template<class t_return_type, class t_arg1>
struct weak_result_type<t_return_type(t_arg1)> : public unary_function_depr<t_arg1, t_return_type> {};

template<class t_return_type, class t_arg1>
struct weak_result_type<t_return_type (&)(t_arg1)> : public unary_function_depr<t_arg1, t_return_type> {};

template<class t_return_type, class t_arg1>
struct weak_result_type<t_return_type (*)(t_arg1)> : public unary_function_depr<t_arg1, t_return_type> {};

template<class t_return_type, class t_class_type>
struct weak_result_type<t_return_type (t_class_type::*)()>
    : public unary_function_depr<t_class_type *, t_return_type> {};

template<class t_return_type, class t_class_type>
struct weak_result_type<t_return_type (t_class_type::*)() const>
    : public unary_function_depr<t_class_type const *, t_return_type> {};

template<class t_return_type, class t_class_type>
struct weak_result_type<t_return_type (t_class_type::*)() volatile>
    : public unary_function_depr<t_class_type volatile *, t_return_type> {};

template<class t_return_type, class t_class_type>
struct weak_result_type<t_return_type (t_class_type::*)() const volatile>
    : public unary_function_depr<t_class_type const volatile *, t_return_type> {};

// 2 argument case

template<class t_return_type, class t_arg1, class t_arg2>
struct weak_result_type<t_return_type(t_arg1, t_arg2)> : public binary_function_depr<t_arg1, t_arg2, t_return_type> {};

template<class t_return_type, class t_arg1, class t_arg2>
struct weak_result_type<t_return_type (*)(t_arg1, t_arg2)>
    : public binary_function_depr<t_arg1, t_arg2, t_return_type> {};

template<class t_return_type, class t_arg1, class t_arg2>
struct weak_result_type<t_return_type (&)(t_arg1, t_arg2)>
    : public binary_function_depr<t_arg1, t_arg2, t_return_type> {};

template<class t_return_type, class t_class_type, class t_arg1>
struct weak_result_type<t_return_type (t_class_type::*)(t_arg1)>
    : public binary_function_depr<t_class_type *, t_arg1, t_return_type> {};

template<class t_return_type, class t_class_type, class t_arg1>
struct weak_result_type<t_return_type (t_class_type::*)(t_arg1) const>
    : public binary_function_depr<t_class_type const *, t_arg1, t_return_type> {};

template<class t_return_type, class t_class_type, class t_arg1>
struct weak_result_type<t_return_type (t_class_type::*)(t_arg1) volatile>
    : public binary_function_depr<t_class_type volatile *, t_arg1, t_return_type> {};

template<class t_return_type, class t_class_type, class t_arg1>
struct weak_result_type<t_return_type (t_class_type::*)(t_arg1) const volatile>
    : public binary_function_depr<t_class_type const volatile *, t_arg1, t_return_type> {};

// 3 or more arguments

template<class t_return_type, class t_arg1, class t_arg2, class t_arg3, class... t_args_other>
struct weak_result_type<t_return_type(t_arg1, t_arg2, t_arg3, t_args_other...)> {
#if 0 //_LIBCPP_STD_VER <= 17 || defined(_LIBCPP_ENABLE_CXX20_REMOVED_BINDER_TYPEDEFS)
    using result_type _LIBCPP_NODEBUG _LIBCPP_DEPRECATED_IN_CXX17 = t_return_type;
#endif
};

template<class t_return_type, class t_arg1, class t_arg2, class t_arg3, class... t_args_other>
struct weak_result_type<t_return_type (&)(t_arg1, t_arg2, t_arg3, t_args_other...)> {
#if 0 //_LIBCPP_STD_VER <= 17 || defined(_LIBCPP_ENABLE_CXX20_REMOVED_BINDER_TYPEDEFS)
    using result_type _LIBCPP_NODEBUG _LIBCPP_DEPRECATED_IN_CXX17 = t_return_type;
#endif
};

template<class t_return_type, class t_arg1, class t_arg2, class t_arg3, class... t_args_other>
struct weak_result_type<t_return_type (*)(t_arg1, t_arg2, t_arg3, t_args_other...)> {
#if 0 //_LIBCPP_STD_VER <= 17 || defined(_LIBCPP_ENABLE_CXX20_REMOVED_BINDER_TYPEDEFS)
    using result_type _LIBCPP_NODEBUG _LIBCPP_DEPRECATED_IN_CXX17 = t_return_type;
#endif
};

template<class t_return_type, class t_class_type, class t_arg1, class t_arg2, class... t_args_other>
struct weak_result_type<t_return_type (t_class_type::*)(t_arg1, t_arg2, t_args_other...)> {
#if 0 //_LIBCPP_STD_VER <= 17 || defined(_LIBCPP_ENABLE_CXX20_REMOVED_BINDER_TYPEDEFS)
    using result_type _LIBCPP_NODEBUG _LIBCPP_DEPRECATED_IN_CXX17 = t_return_type;
#endif
};

template<class t_return_type, class t_class_type, class t_arg1, class t_arg2, class... t_args_other>
struct weak_result_type<t_return_type (t_class_type::*)(t_arg1, t_arg2, t_args_other...) const> {
#if 0 //_LIBCPP_STD_VER <= 17 || defined(_LIBCPP_ENABLE_CXX20_REMOVED_BINDER_TYPEDEFS)
    using result_type _LIBCPP_NODEBUG _LIBCPP_DEPRECATED_IN_CXX17 = t_return_type;
#endif
};

template<class t_return_type, class t_class_type, class t_arg1, class t_arg2, class... t_args_other>
struct weak_result_type<t_return_type (t_class_type::*)(t_arg1, t_arg2, t_args_other...) volatile> {
#if 0 //_LIBCPP_STD_VER <= 17 || defined(_LIBCPP_ENABLE_CXX20_REMOVED_BINDER_TYPEDEFS)
    using result_type _LIBCPP_NODEBUG _LIBCPP_DEPRECATED_IN_CXX17 = t_return_type;
#endif
};

template<class t_return_type, class t_class_type, class t_arg1, class t_arg2, class... t_args_other>
struct weak_result_type<t_return_type (t_class_type::*)(t_arg1, t_arg2, t_args_other...) const volatile> {
#if 0 //_LIBCPP_STD_VER <= 17 || defined(_LIBCPP_ENABLE_CXX20_REMOVED_BINDER_TYPEDEFS)
    using result_type _LIBCPP_NODEBUG _LIBCPP_DEPRECATED_IN_CXX17 = t_return_type;
#endif
};

// template<class t_type, class... t_args> struct __invoke_return {
//   using type = decltype(::portable_stl::functional_helper::invoke_impl(::portable_stl::declval<t_type>(),
//                                                                     ::portable_stl::declval<t_args>()...));
// };

} // namespace portable_stl

#endif // PSTL_WEAK_RESULT_TYPE_H
